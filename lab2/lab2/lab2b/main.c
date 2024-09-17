#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N_REPS 50
#define DEFAULT_SLOWDOWN 10000  

int main(int argc, char * argv[]) {
    int i;
    int slow_down = DEFAULT_SLOWDOWN;
// Check if the correct number of command-line arguments is provided
    if (argc == 1) {
        fprintf(stderr, "Usage: %s string [delay]\n", argv[0]);
        return 1;
    }
    // If a delay argument is provided, use it; otherwise, use the default slowdown
    if (argc >= 3) {
        slow_down = atoi(argv[2]);
    }
    // Loop for a specified number of repetitions (N_REPS)
    for (i = 0; i < N_REPS; i++) {
        char * cp = argv[1];
        // Create a mutex by repeatedly attempting to create a directory named .mutex
        while(system("mkdir .mutex 2>/dev/null")!=0);
        // Loop through each character in the input string
        while (*cp) {
            // Print the character, flush the standard output, and introduce a delay
            printf("%c", *cp++);
            fflush(stdout);
            usleep(random() % slow_down);
        }
        system("rmdir .mutex 2>/dev/null");
        usleep(5000);
    }


    return EXIT_SUCCESS;
}