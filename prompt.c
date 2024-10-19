#include <stdio.h>
#include <stdlib.h>

// On OSX the editline library comes with Command Line Tools
// On Linux can be installed with sudo apt-get install libedit-dev
#include <editline/readline.h>

int main(int argc, char **argv) {
  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while (1) {
    char *input = readline("lispy> ");

    // Add input to history
    add_history(input);

    // echo back to user
    printf("No You're a %s\n", input);

    // free retrieved input
    free(input);
  }

  return 0;
}
