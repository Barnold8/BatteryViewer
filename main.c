#include <stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 200

int getBatteryPercent(){

    char buffer[BUFFERSIZE];
    FILE* f;
    int percent = 0;

    system("cat ~/../../sys/class/power_supply/BAT0/capacity > powerCAP");
    f = fopen("powerCAP","r");
    
    if(f == NULL){
        return -1;
    }
 
    if(fgets(buffer,BUFFERSIZE,f) == NULL){
        return -1;
    }
    percent = atoi(buffer);

    fclose(f);
    return percent;
}

void printBattery(int percent){

    char *top =    "╔══════════════════════╗"; // 22 char long inner
    char *side =    "║";
    char *inner =    "█";
    char *bottom = "╚══════════════════════╝";
    char *outer_top = "╚╗";
    char *outer_bottom = "╔╝";
    int p = (int)( 22.0 * ((float)percent/100));

    printf("%s\n%s",top,side);

    for(int i = 0; i < p; i++){
        printf("%s",inner);
    }
    for(int i = 0; i < 22 - p; i++){
        printf("%c",32);
    }

    printf("%s\n%s",outer_top,side);
    
    for(int i = 0; i < p; i++){
        printf("%s",inner);
    }
    for(int i = 0; i < 22 - p; i++){
        printf("%c",32);
    }
    
    printf("%s\n%s\n",outer_bottom,bottom);
    printf("Battery Percent: %d\n",percent);

}

int main(){
    
    int percent = getBatteryPercent();


    printBattery(percent);

    return 0;
}
