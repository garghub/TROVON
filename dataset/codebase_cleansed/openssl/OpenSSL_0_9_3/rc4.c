int main(int argc, char *argv[])
{
FILE *in=NULL,*out=NULL;
char *infile=NULL,*outfile=NULL,*keystr=NULL;
RC4_KEY key;
char buf[BUFSIZ];
int badops=0,i;
char **pp;
unsigned char md[MD5_DIGEST_LENGTH];
argc--;
argv++;
while (argc >= 1)
{
if (strcmp(*argv,"-in") == 0)
{
if (--argc < 1) goto bad;
infile= *(++argv);
}
else if (strcmp(*argv,"-out") == 0)
{
if (--argc < 1) goto bad;
outfile= *(++argv);
}
else if (strcmp(*argv,"-key") == 0)
{
if (--argc < 1) goto bad;
keystr= *(++argv);
}
else
{
fprintf(stderr,"unknown option %s\n",*argv);
badops=1;
break;
}
argc--;
argv++;
}
if (badops)
{
bad:
for (pp=usage; (*pp != NULL); pp++)
fprintf(stderr,*pp);
exit(1);
}
if (infile == NULL)
in=stdin;
else
{
in=fopen(infile,"r");
if (in == NULL)
{
perror("open");
exit(1);
}
}
if (outfile == NULL)
out=stdout;
else
{
out=fopen(outfile,"w");
if (out == NULL)
{
perror("open");
exit(1);
}
}
#ifdef MSDOS
{
#include <fcntl.h>
setmode(fileno(in),O_BINARY);
setmode(fileno(out),O_BINARY);
}
#endif
if (keystr == NULL)
{
i=EVP_read_pw_string(buf,BUFSIZ,"Enter RC4 password:",0);
if (i != 0)
{
memset(buf,0,BUFSIZ);
fprintf(stderr,"bad password read\n");
exit(1);
}
keystr=buf;
}
MD5((unsigned char *)keystr,(unsigned long)strlen(keystr),md);
memset(keystr,0,strlen(keystr));
RC4_set_key(&key,MD5_DIGEST_LENGTH,md);
for(;;)
{
i=fread(buf,1,BUFSIZ,in);
if (i == 0) break;
if (i < 0)
{
perror("read");
exit(1);
}
RC4(&key,(unsigned int)i,(unsigned char *)buf,
(unsigned char *)buf);
i=fwrite(buf,(unsigned int)i,1,out);
if (i != 1)
{
perror("write");
exit(1);
}
}
fclose(out);
fclose(in);
exit(0);
return(1);
}
