static uint32_t getle32(const void *p)
{
const uint8_t *cp = p;
return (uint32_t)cp[0] + ((uint32_t)cp[1] << 8) +
((uint32_t)cp[2] << 16) + ((uint32_t)cp[3] << 24);
}
int main(int argc, char *argv[])
{
uint32_t olen;
long ilen;
unsigned long offs;
FILE *f;
if (argc < 2) {
fprintf(stderr, "Usage: %s compressed_file\n", argv[0]);
return 1;
}
f = fopen(argv[1], "r");
if (!f) {
perror(argv[1]);
return 1;
}
if (fseek(f, -4L, SEEK_END)) {
perror(argv[1]);
}
if (fread(&olen, sizeof(olen), 1, f) != 1) {
perror(argv[1]);
return 1;
}
ilen = ftell(f);
olen = getle32(&olen);
fclose(f);
offs = (olen > ilen) ? olen - ilen : 0;
offs += olen >> 12;
offs += 64*1024 + 128;
offs = (offs+4095) & ~4095;
printf(".section \".rodata..compressed\",\"a\",@progbits\n");
printf(".globl z_input_len\n");
printf("z_input_len = %lu\n", ilen);
printf(".globl z_output_len\n");
printf("z_output_len = %lu\n", (unsigned long)olen);
printf(".globl z_extract_offset\n");
printf("z_extract_offset = 0x%lx\n", offs);
printf(".globl z_extract_offset_negative\n");
printf("z_extract_offset_negative = -0x%lx\n", offs);
printf(".globl input_data, input_data_end\n");
printf("input_data:\n");
printf(".incbin \"%s\"\n", argv[1]);
printf("input_data_end:\n");
return 0;
}
