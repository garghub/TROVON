int RAND_load_file(const char *file, long bytes)
{
MS_STATIC unsigned char buf[BUFSIZE];
#ifndef OPENSSL_NO_POSIX_IO
struct stat sb;
#endif
int i,ret=0,n;
FILE *in;
if (file == NULL) return(0);
#ifndef OPENSSL_NO_POSIX_IO
#ifdef PURIFY
memset(&sb, 0, sizeof(sb));
#endif
if (stat(file,&sb) < 0) return(0);
RAND_add(&sb,sizeof(sb),0.0);
#endif
if (bytes == 0) return(ret);
#ifdef OPENSSL_SYS_VMS
in=vms_fopen(file,"rb",VMS_OPEN_ATTRS);
#else
in=fopen(file,"rb");
#endif
if (in == NULL) goto err;
#if defined(S_IFBLK) && defined(S_IFCHR) && !defined(OPNESSL_NO_POSIX_IO)
if (sb.st_mode & (S_IFBLK | S_IFCHR)) {
bytes = (bytes == -1) ? 2048 : bytes;
setvbuf(in, NULL, _IONBF, 0);
}
#endif
for (;;)
{
if (bytes > 0)
n = (bytes < BUFSIZE)?(int)bytes:BUFSIZE;
else
n = BUFSIZE;
i=fread(buf,1,n,in);
if (i <= 0) break;
#ifdef PURIFY
RAND_add(buf,i,(double)i);
#else
RAND_add(buf,n,(double)i);
#endif
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
#ifndef OPENSSL_NO_POSIX_IO
struct stat sb;
i=stat(file,&sb);
if (i != -1) {
#if defined(S_ISBLK) && defined(S_ISCHR)
if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode)) {
return(1);
}
#endif
}
#endif
#if defined(O_CREAT) && !defined(OPENSSL_NO_POSIX_IO) && !defined(OPENSSL_SYS_VMS)
{
#ifndef O_BINARY
#define O_BINARY 0
#endif
int fd = open(file, O_WRONLY|O_CREAT|O_BINARY, 0600);
if (fd != -1)
out = fdopen(fd, "wb");
}
#endif
#ifdef OPENSSL_SYS_VMS
out = vms_fopen(file,"rb+",VMS_OPEN_ATTRS);
if (out == NULL)
out = vms_fopen(file,"wb",VMS_OPEN_ATTRS);
#else
if (out == NULL)
out = fopen(file,"wb");
#endif
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
fclose(out);
OPENSSL_cleanse(buf,BUFSIZE);
err:
return (rand_err ? -1 : ret);
}
const char *RAND_file_name(char *buf, size_t size)
{
char *s=NULL;
int ok = 0;
#ifdef __OpenBSD__
struct stat sb;
#endif
if (OPENSSL_issetugid() == 0)
s=getenv("RANDFILE");
if (s != NULL && *s && strlen(s) + 1 < size)
{
if (BUF_strlcpy(buf,s,size) >= size)
return NULL;
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
if (s && *s && strlen(s)+strlen(RFILE)+2 < size)
{
BUF_strlcpy(buf,s,size);
#ifndef OPENSSL_SYS_VMS
BUF_strlcat(buf,"/",size);
#endif
BUF_strlcat(buf,RFILE,size);
ok = 1;
}
else
buf[0] = '\0';
}
#ifdef __OpenBSD__
if (!ok)
if (BUF_strlcpy(buf,"/dev/arandom",size) >= size) {
return(NULL);
}
if (stat(buf,&sb) == -1)
if (BUF_strlcpy(buf,"/dev/arandom",size) >= size) {
return(NULL);
}
#endif
return(buf);
}
