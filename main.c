#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear() {
    #ifdef _WIN32
        system("cls"); 
    #elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
}

int main() {

    char buffer[50];
    char method[3];
    char login[50], modality[50], gender[2];

    clear();

    while(1) {

        fflush(stdin);
        fgets(buffer, sizeof(buffer), stdin);

        sscanf(buffer, "%s", method);

        if (strcmp(method, "IC") == 0) {

            sscanf(buffer, "%s %s %s %s", method, login, modality, gender);
            printf("output: %s %s %s %s\n", method, login, modality, gender);

        } else if(strcmp(method, "BM") == 0) {

            sscanf(buffer, "%s %s", method, modality);
            printf("output: %s %s\n", method, modality);

        } else if(strcmp(method, "BS") == 0) {

            sscanf(buffer, "%s %s", method, gender);
            printf("output: %s %s\n", method, gender);

        } else if(strcmp(method, "BD") == 0) {

            sscanf(buffer, "%s %s %s", method, modality, gender);
            printf("output: %s %s %s\n", method, modality, gender);

        } else if(strcmp(method, "PR") == 0) {

            // 
            printf("output: %s\n", method);

        } else if(strcmp(method, "FM") == 0) {

            //
            printf("output: %s\n", method);

        } else {
            printf("error: invalid input\n");
        }

        memset(buffer,   0, sizeof(buffer));
        memset(method,   0, sizeof(method));
        memset(login,    0, sizeof(login));
        memset(modality, 0, sizeof(modality));
        memset(gender,   0, sizeof(gender));
    }

    return 0;
}