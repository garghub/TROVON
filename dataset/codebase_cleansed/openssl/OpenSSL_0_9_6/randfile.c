int RAND_load_file(const char *file, long bytes)
{
MS_STATIC unsigned char buf[BUFSIZE];
struct stat sb;
int i,ret=0,n;
FILE *in;
if (file == NULL) return(0);
i=stat(file,&sb);
RAND_add(&sb,sizeof(sb),0);
if (i < 0) return(0);
if (bytes == 0) return(ret);
in=fopen(file,"rb");
if (in == NULL) goto err;
for (;;)
{
if (bytes > 0)
n = (bytes < BUFSIZE)?(int)bytes:BUFSIZE;
else
n = BUFSIZE;
i=fread(buf,1,n,in);
if (i <= 0) break;
RAND_add(buf,n,i);
ret+=i;
if (bytes > 0)
{
bytes-=n;
if (bytes == 0) break;
}
}
fclose(in);
memset(buf,0,BUFSIZE);
err:
return(ret);
}
int RAND_write_file(const char *file)
{
unsigned char buf[BUFSIZE];
int i,ret=0,rand_err=0;
FILE *out = NULL;
int n;
#if defined(O_CREAT) && !defined(WIN32)
int fd = open(file, O_CREAT, 0600);
if (fd != -1)
out = fdopen(fd, "wb");
#endif
if (out == NULL)
out = fopen(file,"wb");
if (out == NULL) goto err;
#ifndef NO_CHMOD
chmod(file,0600);
#endif
n=RAND_DATA;
for (;;)
{
i=(n > BUFSIZE)?BUFSIZE:n;
n-=BUFSIZE;
if (RAND_bytes(buf,i) <= 0)
rand_err=1;
i=fwrite(buf,1,i,out);
if (i <= 0)
{
ret=0;
break;
}
ret+=i;
if (n <= 0) break;
}
#ifdef VMS
{
char *tmpf;
tmpf = OPENSSL_malloc(strlen(file) + 4);
if (tmpf)
{
strcpy(tmpf, file);
strcat(tmpf, ";-1");
while(delete(tmpf) == 0)
;
rename(file,";1");
}
}
#endif
fclose(out);
memset(buf,0,BUFSIZE);
err:
return (rand_err ? -1 : ret);
}
const char *RAND_file_name(char *buf, int size)
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
