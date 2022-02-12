int RAND_load_file(const char *file, long bytes)
{
MS_STATIC unsigned char buf[BUFSIZE];
struct stat sb;
int i,ret=0,n;
FILE *in;
if (file == NULL) return(0);
i=stat(file,&sb);
RAND_seed(&sb,sizeof(sb));
ret+=sizeof(sb);
if (i < 0) return(0);
if (bytes <= 0) return(ret);
in=fopen(file,"rb");
if (in == NULL) goto err;
for (;;)
{
n=(bytes < BUFSIZE)?(int)bytes:BUFSIZE;
i=fread(buf,1,n,in);
if (i <= 0) break;
RAND_seed(buf,n);
ret+=i;
bytes-=n;
if (bytes <= 0) break;
}
fclose(in);
memset(buf,0,BUFSIZE);
err:
return(ret);
}
int RAND_write_file(const char *file)
{
unsigned char buf[BUFSIZE];
int i,ret=0;
FILE *out;
int n;
out=fopen(file,"rb+");
if (out == NULL && errno == ENOENT)
{
errno = 0;
out=fopen(file,"wb");
}
if (out == NULL) goto err;
chmod(file,0600);
n=RAND_DATA;
for (;;)
{
i=(n > BUFSIZE)?BUFSIZE:n;
n-=BUFSIZE;
RAND_bytes(buf,i);
i=fwrite(buf,1,i,out);
if (i <= 0)
{
ret=0;
break;
}
ret+=i;
if (n <= 0) break;
}
fclose(out);
memset(buf,0,BUFSIZE);
err:
return(ret);
}
char *RAND_file_name(char *buf, int size)
{
char *s;
char *ret=NULL;
s=getenv("RANDFILE");
if (s != NULL)
{
strncpy(buf,s,size-1);
buf[size-1]='\0';
ret=buf;
}
else
{
s=getenv("HOME");
if (s == NULL) return(RFILE);
if (((int)(strlen(s)+strlen(RFILE)+2)) > size)
return(RFILE);
strcpy(buf,s);
#ifndef VMS
strcat(buf,"/");
#endif
strcat(buf,RFILE);
ret=buf;
}
return(ret);
}
