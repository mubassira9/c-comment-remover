#include <stdio.h>

void remove_comments(FILE *input, FILE *output) {
    int c, m;
    while ((c = fgetc(input)) != EOF) {
        if (c == '/') {
            m = fgetc(input);
            if (m == '/') {
                // Single line comment, skip till newline
                while ((c = fgetc(input)) != EOF && c != '\n');
                fputc('\n', output); // keep newline
            }
            else if (m == '*') {
                // Multi-line comment, skip till */
                int prev = 0;
                while ((c = fgetc(input)) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            }
            else {
                fputc(c, output);
                fputc(m, output);
            }
        }
        else {
            fputc(c, output);
        }
    }
}

int main() {
    printf("Enter your code:\n\n");

    remove_comments(stdin, stdout);

    return 0;
}
