int main(int argc, char **argv)
{
int i,err=0;
FILE *IN;
if (argc == 1)
{
do_fp(stdin);
}
else
{
for (i=1; i<argc; i++)
{
IN=fopen(argv[i],"r");
if (IN == NULL)
{
perror(argv[i]);
err++;
continue;
}
printf("MD4(%s)= ",argv[i]);
do_fp(IN);
fclose(IN);
}
}
exit(err);
}
void do_fp(FILE *f)
{
MD4_CTX c;
unsigned char md[MD4_DIGEST_LENGTH];
int fd;
int i;
static unsigned char buf[BUFSIZE];
fd=fileno(f);
MD4_Init(&c);
for (;;)
{
i=read(fd,buf,sizeof buf);
if (i <= 0) break;
MD4_Update(&c,buf,(unsigned long)i);
}
MD4_Final(&(md[0]),&c);
pt(md);
}
void pt(unsigned char *md)
{
int i;
for (i=0; i<MD4_DIGEST_LENGTH; i++)
printf("%02x",md[i]);
printf("\n");
}
