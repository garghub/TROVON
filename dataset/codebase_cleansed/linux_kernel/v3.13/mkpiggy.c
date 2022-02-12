int main(int argc, char *argv[])
{
uint32_t olen;
long ilen;
unsigned long offs;
FILE *f = NULL;
int retval = 1;
if (argc < 2) {
fprintf(stderr, "Usage: %s compressed_file\n", argv[0]);
goto bail;
}
f = fopen(argv[1], "r");
if (!f) {
perror(argv[1]);
goto bail;
}
if (fseek(f, -4L, SEEK_END)) {
perror(argv[1]);
}
if (fread(&olen, sizeof(olen), 1, f) != 1) {
perror(argv[1]);
goto bail;
}
ilen = ftell(f);
olen = get_unaligned_le32(&olen);
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
retval = 0;
bail:
if (f)
fclose(f);
return retval;
}
