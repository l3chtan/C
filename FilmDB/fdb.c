#include <dirent.h>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>


void read_dirs(char *p, void (*fcn) (char *)){

	DIR *dp;
	struct dirent *rid;
	char d_nam[NAME_MAX];

	if((dp = opendir(p)) == NULL){
		fprintf(stderr, "Cannot open directory %s\n", p);
		return;
	}
	while((rid = readdir(dp)) != NULL){
		if('.'!= rid->d_name[0]){
			sprintf(d_nam, "%s/%s", p, rid->d_name);
			(*fcn)(d_nam);	
			if(strstr(p, "Serien/")){
				break;
			}
		}
	}
		(void) closedir(dp);
		return;
}

void read_files(char *path){

	struct stat buff;

	if(stat(path, &buff) == -1){
		fprintf(stderr, "Cannot access %s\n", path);
		return;
	}

	if((buff.st_mode & S_IFMT) == S_IFDIR){
		read_dirs(path, read_files);	
	} else if((strstr(path, ".avi") || 
		strstr(path, ".mov") || 
		strstr(path, ".mkv") || 
		strstr(path, ".mpg") || 
		strstr(path, ".mpeg") ||
		strstr(path, ".wmv") || 
		strstr(path, ".mp4") ||
		strstr(path, ".swf") ||
		strstr(path, ".flv")) && !strstr(path, ".part")){
		printf("%s\n", path);
	}
	return;
}

int main(){

	FILE *fpath/*, *infout*/;
	int i = 0, a = 1;
	char **paths;

	fpath = fopen("path_to_files.dat", "r");

	if(fpath != NULL){
		fscanf(fpath, "%d", &a);
		if((paths = (char**)malloc(a*sizeof(char*))) == NULL){
			return 1;
		}
		for(i=0;i<a;i++){
			if((paths[i] = (char*)malloc(101)) == NULL){
				return 1;
			}
			fscanf(fpath,"%s",&paths[i][0]);
		}

		fclose(fpath);
	} else {
		if((paths = (char**)malloc(sizeof(char*))) == NULL){
			return 1;
		}
		if((paths[0] = (char*)malloc(101)) == NULL){
			return 1;
		}
		printf("Enter a path\n");
		scanf("%s", &paths[0][0]);
	}


	for(i=0;i<a;i++){
		read_files(paths[i]);
	}

	return 0;
}
