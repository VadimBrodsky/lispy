#include <stdio.h>
#include <stdlib.h>

// if we are compiling on Windows compile these functions
// _WIN32 defined for both 32-bit and 64-bit Windows applications.
// __APPLE__ defined on Apple platforms (including macOS, iOS, etc.)
// __linux__ defined on Linux systems, __unix__ or __posix__ are more broad
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// fake readline function
char *readline(char *prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char *cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

// fake add_history function
void add_history(char *unused) {}

// otherwise include the editline headers
#else
// On OSX the editline library comes with Command Line Tools
// On Linux can be installed with sudo apt-get install libedit-dev
#include <editline/readline.h>
#endif

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
