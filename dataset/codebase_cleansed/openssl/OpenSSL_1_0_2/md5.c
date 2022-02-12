int main(int argc, char **argv)
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
printf("MD5(%s)= ", argv[i]);
do_fp(IN);
fclose(IN);
}
}
exit(err);
}
void do_fp(FILE *f)
{
MD5_CTX c;
unsigned char md[MD5_DIGEST_LENGTH];
int fd;
int i;
static unsigned char buf[BUFSIZE];
fd = fileno(f);
MD5_Init(&c);
for (;;) {
i = read(fd, buf, BUFSIZE);
if (i <= 0)
break;
MD5_Update(&c, buf, (unsigned long)i);
}
MD5_Final(&(md[0]), &c);
pt(md);
}
void pt(unsigned char *md)
{
int i;
for (i = 0; i < MD5_DIGEST_LENGTH; i++)
printf("%02x", md[i]);
printf("\n");
}
