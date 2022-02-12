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
if (bytes <= 0) break;
}
}
fclose(in);
OPENSSL_cleanse(buf,BUFSIZE);
err:
return(ret);
}
int RAND_write_file(const char *file)
{
unsigned char buf[BUFSIZE];
int i,ret=0,rand_err=0;
FILE *out = NULL;
int n;
#if defined(O_CREAT) && !defined(OPENSSL_SYS_WIN32)
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
#ifdef OPENSSL_SYS_VMS
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
OPENSSL_cleanse(buf,BUFSIZE);
err:
return (rand_err ? -1 : ret);
}
const char *RAND_file_name(char *buf, size_t size)
{
char *s=NULL;
char *ret=NULL;
if (OPENSSL_issetugid() == 0)
s=getenv("RANDFILE");
if (s != NULL)
{
if(strlen(s) >= size)
return NULL;
strcpy(buf,s);
ret=buf;
}
else
{
if (OPENSSL_issetugid() == 0)
s=getenv("HOME");
#ifdef DEFAULT_HOME
if (s == NULL)
{
s = DEFAULT_HOME;
}
#endif
if (s != NULL && (strlen(s)+strlen(RFILE)+2 < size))
{
strcpy(buf,s);
#ifndef OPENSSL_SYS_VMS
strcat(buf,"/");
#endif
strcat(buf,RFILE);
ret=buf;
}
else
buf[0] = '\0';
}
return(ret);
}
