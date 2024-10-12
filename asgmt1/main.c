#include <stdio.h>
int main()
{
    FILE *audioFile;
    FILE *upSampled;
    FILE *downSampled;
    char filename1[]="../audio.txt";
    audioFile = fopen(filename1, "r");
    char filename2[]="../upSampled_audio.txt";
    upSampled = fopen(filename2, "w");
    char filename3[]="../downSampled_audio.txt";
    downSampled = fopen(filename3, "w");
    char line[100];
    int numSamples=0;
    while (fgets(line, sizeof(line), audioFile) != NULL) {
        fprintf(upSampled, "%s0\n", line);
        if (numSamples % 2 == 0) {
            fprintf(downSampled, "%s", line);
        }
        numSamples++;
    }
    fclose(audioFile);
    fclose(upSampled);
    fclose(downSampled);

    return 0;
}
