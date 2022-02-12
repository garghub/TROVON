int DES_enc_write(int fd, const void *_buf, int len,
DES_key_schedule *sched, DES_cblock *iv)
{
#ifdef _LIBC
extern unsigned long time();
extern int write();
#endif
const unsigned char *buf=_buf;
long rnum;
int i,j,k,outnum;
static unsigned char *outbuf=NULL;
unsigned char shortbuf[8];
unsigned char *p;
const unsigned char *cp;
static int start=1;
if (outbuf == NULL)
{
outbuf=OPENSSL_malloc(BSIZE+HDRSIZE);
if (outbuf == NULL) return(-1);
}
if (start)
{
start=0;
}
if (len > MAXWRITE)
{
j=0;
for (i=0; i<len; i+=k)
{
k=DES_enc_write(fd,&(buf[i]),
((len-i) > MAXWRITE)?MAXWRITE:(len-i),sched,iv);
if (k < 0)
return(k);
else
j+=k;
}
return(j);
}
p=outbuf;
l2n(len,p);
if (len < 8)
{
cp=shortbuf;
memcpy(shortbuf,buf,len);
RAND_pseudo_bytes(shortbuf+len, 8-len);
rnum=8;
}
else
{
cp=buf;
rnum=((len+7)/8*8);
}
if (DES_rw_mode & DES_PCBC_MODE)
DES_pcbc_encrypt(cp,&(outbuf[HDRSIZE]),(len<8)?8:len,sched,iv,
DES_ENCRYPT);
else
DES_cbc_encrypt(cp,&(outbuf[HDRSIZE]),(len<8)?8:len,sched,iv,
DES_ENCRYPT);
outnum=rnum+HDRSIZE;
for (j=0; j<outnum; j+=i)
{
i=write(fd,(void *)&(outbuf[j]),outnum-j);
if (i == -1)
{
#ifdef EINTR
if (errno == EINTR)
i=0;
else
#endif
return(-1);
}
}
return(len);
}
