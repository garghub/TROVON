int des_enc_read(int fd, void *buf, int len, des_key_schedule sched,
des_cblock *iv)
{
int net_num=0;
static unsigned char *net=NULL;
static unsigned char *unnet=NULL;
static int unnet_start=0;
static int unnet_left=0;
static unsigned char *tmpbuf=NULL;
int i;
long num=0,rnum;
unsigned char *p;
if (tmpbuf == NULL)
{
tmpbuf=Malloc(BSIZE);
if (tmpbuf == NULL) return(-1);
}
if (net == NULL)
{
net=Malloc(BSIZE);
if (net == NULL) return(-1);
}
if (unnet == NULL)
{
unnet=Malloc(BSIZE);
if (unnet == NULL) return(-1);
}
if (unnet_left != 0)
{
if (unnet_left < len)
{
memcpy(buf,&(unnet[unnet_start]),
unnet_left);
i=unnet_left;
unnet_start=unnet_left=0;
}
else
{
memcpy(buf,&(unnet[unnet_start]),len);
unnet_start+=len;
unnet_left-=len;
i=len;
}
return(i);
}
if (len > MAXWRITE) len=MAXWRITE;
while (net_num < HDRSIZE)
{
i=read(fd,(void *)&(net[net_num]),HDRSIZE-net_num);
#ifdef EINTR
if ((i == -1) && (errno == EINTR)) continue;
#endif
if (i <= 0) return(0);
net_num+=i;
}
p=net;
n2l(p,num);
if ((num > MAXWRITE) || (num < 0))
return(-1);
rnum=(num < 8)?8:((num+7)/8*8);
net_num=0;
while (net_num < rnum)
{
i=read(fd,(void *)&(net[net_num]),rnum-net_num);
#ifdef EINTR
if ((i == -1) && (errno == EINTR)) continue;
#endif
if (i <= 0) return(0);
net_num+=i;
}
if (len < num)
{
if (des_rw_mode & DES_PCBC_MODE)
des_pcbc_encrypt(net,unnet,num,sched,iv,DES_DECRYPT);
else
des_cbc_encrypt(net,unnet,num,sched,iv,DES_DECRYPT);
memcpy(buf,unnet,len);
unnet_start=len;
unnet_left=num-len;
num=len;
}
else
{
if (len < rnum)
{
if (des_rw_mode & DES_PCBC_MODE)
des_pcbc_encrypt(net,tmpbuf,num,sched,iv,
DES_DECRYPT);
else
des_cbc_encrypt(net,tmpbuf,num,sched,iv,
DES_DECRYPT);
memcpy(buf,tmpbuf,num);
}
else
{
if (des_rw_mode & DES_PCBC_MODE)
des_pcbc_encrypt(net,buf,num,sched,iv,
DES_DECRYPT);
else
des_cbc_encrypt(net,buf,num,sched,iv,
DES_DECRYPT);
}
}
return num;
}
