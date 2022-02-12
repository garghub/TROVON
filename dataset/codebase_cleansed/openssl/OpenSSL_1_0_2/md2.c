int main(int argc, char *argv[])
{
int i, err = 0;
FILE *IN;
if (argc == 1) {
do_fp(stdin);
} else {
for (i = 1; i < argc; i++) {
IN = fopen(argv[i], "r");
if (IN == NULL) {
perror(argv[i]);
err++;
continue;
}
printf("MD2(%s)= ", argv[i]);
do_fp(IN);
fclose(IN);
}
}
exit(err);
return (err);
}
void do_fp(FILE *f)
{
MD2_CTX c;
unsigned char md[MD2_DIGEST_LENGTH];
int fd, i;
static unsigned char buf[BUFSIZE];
fd = fileno(f);
MD2_Init(&c);
for (;;) {
i = read(fd, buf, BUFSIZE);
if (i <= 0)
break;
MD2_Update(&c, buf, (unsigned long)i);
}
MD2_Final(&(md[0]), &c);
pt(md);
}
void pt(unsigned char *md)
{
int i;
for (i = 0; i < MD2_DIGEST_LENGTH; i++)
printf("%02x", md[i]);
printf("\n");
}
