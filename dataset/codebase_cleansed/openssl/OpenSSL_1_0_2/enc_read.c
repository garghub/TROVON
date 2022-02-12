int DES_enc_read(int fd, void *buf, int len, DES_key_schedule *sched,
DES_cblock *iv)
{
#if defined(OPENSSL_NO_POSIX_IO)
return (0);
#else
int net_num = 0;
static unsigned char *net = NULL;
static unsigned char *unnet = NULL;
static int unnet_start = 0;
static int unnet_left = 0;
static unsigned char *tmpbuf = NULL;
int i;
long num = 0, rnum;
unsigned char *p;
if (tmpbuf == NULL) {
tmpbuf = OPENSSL_malloc(BSIZE);
if (tmpbuf == NULL)
return (-1);
}
if (net == NULL) {
net = OPENSSL_malloc(BSIZE);
if (net == NULL)
return (-1);
}
if (unnet == NULL) {
unnet = OPENSSL_malloc(BSIZE);
if (unnet == NULL)
return (-1);
}
if (unnet_left != 0) {
if (unnet_left < len) {
memcpy(buf, &(unnet[unnet_start]), unnet_left);
i = unnet_left;
unnet_start = unnet_left = 0;
} else {
memcpy(buf, &(unnet[unnet_start]), len);
unnet_start += len;
unnet_left -= len;
i = len;
}
return (i);
}
if (len > MAXWRITE)
len = MAXWRITE;
while (net_num < HDRSIZE) {
# ifndef OPENSSL_SYS_WIN32
i = read(fd, (void *)&(net[net_num]), HDRSIZE - net_num);
# else
i = _read(fd, (void *)&(net[net_num]), HDRSIZE - net_num);
# endif
# ifdef EINTR
if ((i == -1) && (errno == EINTR))
continue;
# endif
if (i <= 0)
return (0);
net_num += i;
}
p = net;
n2l(p, num);
if ((num > MAXWRITE) || (num < 0))
return (-1);
rnum = (num < 8) ? 8 : ((num + 7) / 8 * 8);
net_num = 0;
while (net_num < rnum) {
# ifndef OPENSSL_SYS_WIN32
i = read(fd, (void *)&(net[net_num]), rnum - net_num);
# else
i = _read(fd, (void *)&(net[net_num]), rnum - net_num);
# endif
# ifdef EINTR
if ((i == -1) && (errno == EINTR))
continue;
# endif
if (i <= 0)
return (0);
net_num += i;
}
if (len < num) {
if (DES_rw_mode & DES_PCBC_MODE)
DES_pcbc_encrypt(net, unnet, num, sched, iv, DES_DECRYPT);
else
DES_cbc_encrypt(net, unnet, num, sched, iv, DES_DECRYPT);
memcpy(buf, unnet, len);
unnet_start = len;
unnet_left = num - len;
num = len;
} else {
if (len < rnum) {
if (DES_rw_mode & DES_PCBC_MODE)
DES_pcbc_encrypt(net, tmpbuf, num, sched, iv, DES_DECRYPT);
else
DES_cbc_encrypt(net, tmpbuf, num, sched, iv, DES_DECRYPT);
memcpy(buf, tmpbuf, num);
} else {
if (DES_rw_mode & DES_PCBC_MODE)
DES_pcbc_encrypt(net, buf, num, sched, iv, DES_DECRYPT);
else
DES_cbc_encrypt(net, buf, num, sched, iv, DES_DECRYPT);
}
}
return num;
#endif
}
