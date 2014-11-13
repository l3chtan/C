#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

/* use strrchr(char *string, int c) to find last occurence of a character c in string string*/

struct meta_f{
	char patH[NAME_MAX];
	char name[NAME_MAX];
};

void read_files(char *path, char *prev_d, char *file);


int main(void){

	FILE *input/*, *infout*/;
	int i = 0, a = 1, cnt = 0;
	char **paths, buf[NAME_MAX];


	input = fopen("path_to_files.dat", "r");
		if((paths = (char**)malloc(a*sizeof(char*))) == NULL){
			return 1;
		}

	if(input != NULL){
		fscanf(input, "%d", &a);

		for(i=0;i<a;i++){
			if((paths[i] = (char*)malloc(NAME_MAX)) == NULL){
				return 1;
			}
			fscanf(input,"%s",&paths[i][0]);
		}

		fclose(input);
	} else {
		/*if((paths = (char**)malloc(sizeof(char*))) == NULL){
			return 1;
		}*/
		if((paths[0] = (char*)malloc(NAME_MAX)) == NULL){
			return 1;
		}

		printf("Enter an absolut path\n");
		scanf("%s", &paths[0][0]);
	}

	//Remove the temporary file, which stores the film names
	if(remove("Films.tmp") != 0){
		fprintf(stderr, "Cannot remove file!");
	}

	for(i=0;i<a;i++){
		read_files(paths[i], "", "");
	}

	input = fopen("Films.tmp", "r");

	while(fscanf(input, "%s", buf) != EOF){
		cnt++;		
	}
	fclose(input);


	return 0;
}


void read_files(char *path, char *prev_d, char *file){

	struct stat buff;
	char new_p[NAME_MAX];

	if(strcmp(file,"") != 0){
		sprintf(new_p, "%s/%s",path, file);
	} else {
		strcpy(new_p, path);
	}

	if(stat(new_p, &buff) == -1){
		fprintf(stderr, "Cannot access %s\n", path);
		return;
	}

	if((buff.st_mode & S_IFMT) == S_IFDIR){

		DIR *dp;
		struct dirent *rid;
		char d_nam[NAME_MAX];

		if((dp = opendir(new_p)) == NULL){
			fprintf(stderr, "Cannot open directory %s\n", new_p);
			return;
		}
		while((rid = readdir(dp)) != NULL){
			if('.'!= rid->d_name[0]){
				//sprintf(d_nam, "%s/%s", new_p, rid->d_name);
				read_files(new_p, file, rid->d_name);	
			}
		}
		(void) closedir(dp);

	} else if((strstr(new_p, ".avi") || 
				strstr(new_p, ".mkv") || 
				strstr(new_p, ".mp4") || 
				strstr(new_p, ".mpg") || 
				strstr(new_p, ".wmv") ||
				strstr(new_p, ".mov") || 
				strstr(new_p, ".mpeg") ||
				strstr(new_p, ".swf") ||
				strstr(new_p, ".flv")) && !(strstr(new_p, ".part") || strstr(new_p, "sample"))){
/*
		Remove path and only keep file name

		char *name;
	       	name =  strrchr(new_p, '/') + 1 ;
*/
		FILE *outp;
		outp = fopen("Films.tmp", "a");
		fprintf(outp,"%s\n", new_p);
		printf("%s\n", new_p);
		close(outp);
	}

	return;

}
