void des_cblock_print_file(const_des_cblock *cb, FILE *fp)
{
int i;
const unsigned int *p = (const unsigned int *)cb;
fprintf(fp, " 0x { ");
for (i = 0; i < 8; i++) {
fprintf(fp, "%x", p[i]);
if (i != 7) fprintf(fp, ", ");
}
fprintf(fp, " }");
}
