#include <stdio.h>
#include <stdint.h>

#define SIZE_128 128

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("provide path to WAV file\nexiting...\n");
    return 1;
  }
  
  FILE* inputFile = fopen(argv[1], "r");
  if (!inputFile) {
    printf("could not open file \"%s\"\nexiting...\n", argv[1]);
    return 1;
  }

  fseek(inputFile, 0, SEEK_END);
  int sizeOfFile = ftell(inputFile);

  printf("input file size is %d\n", sizeOfFile);

  char buffer128[SIZE_128];

  fseek(inputFile, 0, SEEK_SET);
  // int currentPosition = ftell(inputFile);
  // printf("current position=%d\n", currentPosition);

  fgets(buffer128, 5, inputFile);
  printf("first 4 bytes=%s\n", buffer128);

  uint32_t readValue = 0;
  for (int i=0;i<4;++i) {
    uint8_t readCharacter = fgetc(inputFile);
    if (readCharacter != EOF) {
      printf("read %d char=%u\n", i, readCharacter);
    }
    readValue = readValue | (uint32_t)readCharacter << i*8; 
  }
  printf("read number=%u\n", readValue);

  for (int i=0; i<4; ++i) {
      printf ("value[%d] %u\n", i, (uint8_t) (((char *)&readValue)[i]));
  }

  return 0;
}