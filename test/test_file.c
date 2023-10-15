#include <stdio.h>
#include <stdlib.h>
#include "../src/file.h"

int main() {

    // write_data("login1", "bodybuilding", "m");
    // write_data("login2", "pilates", "f");

    client_data c;

    read_data(24, &c);

    printf("%s %s %s\n", c.login, c.modality, c.gender);

    return 0;
}