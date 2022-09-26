#include <stdio.h>
#include <stdlib.h>



struct Letter{
	char letter;
	int position[2048];
	int arr_loc;
};



int main(){

	FILE* fp;
	int c;
	int counter = 0; // for tracking position in the file
	struct Letter letters[127];


	if(!(fp = fopen("test","rt"))){
		printf("Error reading the file\n");
		exit(1);
	}

	for(int i = 0 ; i< 127; i++){

		letters[i].letter = i;
		letters[i].arr_loc = 0;

	}

	while((c = fgetc(fp))!= EOF){

		for(int i = 0;  i < 127; i++){
			if(letters[i].letter == c){
				letters[i].position[letters[i].arr_loc] = counter;
				letters[i].arr_loc++;
			}

		}
		counter++;
	}

	for(int  i  = 0; i < 127; i++){
		for(int y = 0; y  < letters[i].arr_loc;y++){
			printf("%d location\n",letters[i].position[y]);
		}
	}

	fclose(fp);


	fp = fopen("compressed","w");


	for(int i = 0; i < 127; i++){ // loop for writing compressed file
		if(letters[i].arr_loc <= 0){
		continue;}
		// letter
		fprintf(fp,"%c ",letters[i].letter);

		//positions
		for(int y = 0; y < letters[i].arr_loc; y++){
			if(y == letters[i].arr_loc -1){
				fprintf(fp,"%d",letters[i].position[y]);
			}else{
			fprintf(fp,"%d ",letters[i].position[y]);}
		}

		//array length (arr_loc)
		fprintf(fp,".%d",letters[i].arr_loc);
	}


	fclose(fp);



}





