int LLVMFuzzerInitialize(int *argc, char ***argv)
{
if (FuzzerInitialize)
return FuzzerInitialize(argc, argv);
return 0;
}
int LLVMFuzzerTestOneInput(const uint8_t *buf, size_t len) {
return FuzzerTestOneInput(buf, len);
}
int main(int argc, char** argv)
{
if (FuzzerInitialize)
FuzzerInitialize(&argc, &argv);
while (__AFL_LOOP(10000)) {
uint8_t *buf = malloc(BUF_SIZE);
size_t size = read(0, buf, BUF_SIZE);
FuzzerTestOneInput(buf, size);
free(buf);
}
return 0;
}
