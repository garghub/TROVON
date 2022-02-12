int ssl2_peek(SSL *s, char *buf, int len)
{
int ret;
ret=ssl2_read(s,buf,len);
if (ret > 0)
{
s->s2->ract_data_length+=ret;
s->s2->ract_data-=ret;
}
return(ret);
}
int ssl2_read(SSL *s, void *buf, int len)
{
int n;
unsigned char mac[MAX_MAC_SIZE];
unsigned char *p;
int i;
unsigned int mac_size=0;
ssl2_read_again:
if (SSL_in_init(s) && !s->in_handshake)
{
n=s->handshake_func(s);
if (n < 0) return(n);
if (n == 0)
{
SSLerr(SSL_F_SSL2_READ,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
}
clear_sys_error();
s->rwstate=SSL_NOTHING;
if (len <= 0) return(len);
if (s->s2->ract_data_length != 0)
{
if (len > s->s2->ract_data_length)
n=s->s2->ract_data_length;
else
n=len;
memcpy(buf,s->s2->ract_data,(unsigned int)n);
s->s2->ract_data_length-=n;
s->s2->ract_data+=n;
if (s->s2->ract_data_length == 0)
s->rstate=SSL_ST_READ_HEADER;
return(n);
}
if (s->rstate == SSL_ST_READ_HEADER)
{
if (s->first_packet)
{
n=read_n(s,5,SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+2,0);
if (n <= 0) return(n);
s->first_packet=0;
p=s->packet;
if (!((p[0] & 0x80) && (
(p[2] == SSL2_MT_CLIENT_HELLO) ||
(p[2] == SSL2_MT_SERVER_HELLO))))
{
SSLerr(SSL_F_SSL2_READ,SSL_R_NON_SSLV2_INITIAL_PACKET);
return(-1);
}
}
else
{
n=read_n(s,2,SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+2,0);
if (n <= 0) return(n);
}
s->rstate=SSL_ST_READ_BODY;
p=s->packet;
s->s2->escape=0;
s->s2->rlength=(((unsigned int)p[0])<<8)|((unsigned int)p[1]);
if ((p[0] & TWO_BYTE_BIT))
{
s->s2->three_byte_header=0;
s->s2->rlength&=TWO_BYTE_MASK;
}
else
{
s->s2->three_byte_header=1;
s->s2->rlength&=THREE_BYTE_MASK;
s->s2->escape=((p[0] & SEC_ESC_BIT))?1:0;
}
}
if (s->rstate == SSL_ST_READ_BODY)
{
n=s->s2->rlength+2+s->s2->three_byte_header;
if (n > (int)s->packet_length)
{
n-=s->packet_length;
i=read_n(s,(unsigned int)n,(unsigned int)n,1);
if (i <= 0) return(i);
}
p= &(s->packet[2]);
s->rstate=SSL_ST_READ_HEADER;
if (s->s2->three_byte_header)
s->s2->padding= *(p++);
else s->s2->padding=0;
if (s->s2->clear_text)
{
s->s2->mac_data=p;
s->s2->ract_data=p;
s->s2->pad_data=NULL;
}
else
{
mac_size=EVP_MD_size(s->read_hash);
s->s2->mac_data=p;
s->s2->ract_data= &p[mac_size];
s->s2->pad_data= &p[mac_size+
s->s2->rlength-s->s2->padding];
}
s->s2->ract_data_length=s->s2->rlength;
if ((!s->s2->clear_text) &&
(s->s2->rlength >= mac_size))
{
ssl2_enc(s,0);
s->s2->ract_data_length-=mac_size;
ssl2_mac(s,mac,0);
s->s2->ract_data_length-=s->s2->padding;
if ( (memcmp(mac,s->s2->mac_data,
(unsigned int)mac_size) != 0) ||
(s->s2->rlength%EVP_CIPHER_CTX_block_size(s->enc_read_ctx) != 0))
{
SSLerr(SSL_F_SSL2_READ,SSL_R_BAD_MAC_DECODE);
return(-1);
}
}
INC32(s->s2->read_sequence);
#if 1
goto ssl2_read_again;
#else
if (s->s2->ract_data_length == 0)
return(0);
return(ssl2_read(s,buf,len));
#endif
}
else
{
SSLerr(SSL_F_SSL2_READ,SSL_R_BAD_STATE);
return(-1);
}
}
static int read_n(SSL *s, unsigned int n, unsigned int max,
unsigned int extend)
{
int i,off,newb;
if (s->s2->rbuf_left >= (int)n)
{
if (extend)
s->packet_length+=n;
else
{
s->packet= &(s->s2->rbuf[s->s2->rbuf_offs]);
s->packet_length=n;
}
s->s2->rbuf_left-=n;
s->s2->rbuf_offs+=n;
return(n);
}
if (!s->read_ahead) max=n;
if (max > (unsigned int)(SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+2))
max=SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+2;
off=0;
if ((s->s2->rbuf_left != 0) || ((s->packet_length != 0) && extend))
{
newb=s->s2->rbuf_left;
if (extend)
{
off=s->packet_length;
if (s->packet != s->s2->rbuf)
memcpy(s->s2->rbuf,s->packet,
(unsigned int)newb+off);
}
else if (s->s2->rbuf_offs != 0)
{
memcpy(s->s2->rbuf,&(s->s2->rbuf[s->s2->rbuf_offs]),
(unsigned int)newb);
s->s2->rbuf_offs=0;
}
s->s2->rbuf_left=0;
}
else
newb=0;
s->packet=s->s2->rbuf;
while (newb < (int)n)
{
clear_sys_error();
if (s->rbio != NULL)
{
s->rwstate=SSL_READING;
i=BIO_read(s->rbio,(char *)&(s->s2->rbuf[off+newb]),
max-newb);
}
else
{
SSLerr(SSL_F_READ_N,SSL_R_READ_BIO_NOT_SET);
i= -1;
}
#ifdef PKT_DEBUG
if (s->debug & 0x01) sleep(1);
#endif
if (i <= 0)
{
s->s2->rbuf_left+=newb;
return(i);
}
newb+=i;
}
if (newb > (int)n)
{
s->s2->rbuf_offs=n+off;
s->s2->rbuf_left=newb-n;
}
else
{
s->s2->rbuf_offs=0;
s->s2->rbuf_left=0;
}
if (extend)
s->packet_length+=n;
else
s->packet_length=n;
s->rwstate=SSL_NOTHING;
return(n);
}
int ssl2_write(SSL *s, const void *_buf, int len)
{
const unsigned char *buf=_buf;
unsigned int n,tot;
int i;
if (SSL_in_init(s) && !s->in_handshake)
{
i=s->handshake_func(s);
if (i < 0) return(i);
if (i == 0)
{
SSLerr(SSL_F_SSL2_WRITE,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
}
if (s->error)
{
ssl2_write_error(s);
if (s->error)
return(-1);
}
clear_sys_error();
s->rwstate=SSL_NOTHING;
if (len <= 0) return(len);
tot=s->s2->wnum;
s->s2->wnum=0;
n=(len-tot);
for (;;)
{
i=do_ssl_write(s,&(buf[tot]),n);
if (i <= 0)
{
s->s2->wnum=tot;
return(i);
}
if ((i == (int)n) ||
(s->mode & SSL_MODE_ENABLE_PARTIAL_WRITE))
{
return(tot+i);
}
n-=i;
tot+=i;
}
}
static int write_pending(SSL *s, const unsigned char *buf, unsigned int len)
{
int i;
if ((s->s2->wpend_tot > (int)len) ||
((s->s2->wpend_buf != buf) &&
!(s->mode & SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER)))
{
SSLerr(SSL_F_WRITE_PENDING,SSL_R_BAD_WRITE_RETRY);
return(-1);
}
for (;;)
{
clear_sys_error();
if (s->wbio != NULL)
{
s->rwstate=SSL_WRITING;
i=BIO_write(s->wbio,
(char *)&(s->s2->write_ptr[s->s2->wpend_off]),
(unsigned int)s->s2->wpend_len);
}
else
{
SSLerr(SSL_F_WRITE_PENDING,SSL_R_WRITE_BIO_NOT_SET);
i= -1;
}
#ifdef PKT_DEBUG
if (s->debug & 0x01) sleep(1);
#endif
if (i == s->s2->wpend_len)
{
s->s2->wpend_len=0;
s->rwstate=SSL_NOTHING;
return(s->s2->wpend_ret);
}
else if (i <= 0)
return(i);
s->s2->wpend_off+=i;
s->s2->wpend_len-=i;
}
}
static int do_ssl_write(SSL *s, const unsigned char *buf, unsigned int len)
{
unsigned int j,k,olen,p,mac_size,bs;
register unsigned char *pp;
olen=len;
if (s->s2->wpend_len != 0) return(write_pending(s,buf,len));
if (s->s2->clear_text)
mac_size=0;
else
mac_size=EVP_MD_size(s->write_hash);
if (s->s2->clear_text)
{
if (len > SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER)
len=SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER;
p=0;
s->s2->three_byte_header=0;
}
else
{
bs=EVP_CIPHER_CTX_block_size(s->enc_read_ctx);
j=len+mac_size;
if ((j > SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER) &&
(!s->s2->escape))
{
if (j > SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER)
j=SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER;
k=j-(j%bs);
len=k-mac_size;
s->s2->three_byte_header=0;
p=0;
}
else if ((bs <= 1) && (!s->s2->escape))
{
s->s2->three_byte_header=0;
p=0;
}
else
{
p=(j%bs);
p=(p == 0)?0:(bs-p);
if (s->s2->escape)
s->s2->three_byte_header=1;
else
s->s2->three_byte_header=(p == 0)?0:1;
}
}
s->s2->wlength=len;
s->s2->padding=p;
s->s2->mac_data= &(s->s2->wbuf[3]);
s->s2->wact_data= &(s->s2->wbuf[3+mac_size]);
memcpy(s->s2->wact_data,buf,len);
#ifdef PURIFY
if (p)
memset(&(s->s2->wact_data[len]),0,p);
#endif
if (!s->s2->clear_text)
{
s->s2->wact_data_length=len+p;
ssl2_mac(s,s->s2->mac_data,1);
s->s2->wlength+=p+mac_size;
ssl2_enc(s,1);
}
s->s2->wpend_len=s->s2->wlength;
if (s->s2->three_byte_header)
{
pp=s->s2->mac_data;
pp-=3;
pp[0]=(s->s2->wlength>>8)&(THREE_BYTE_MASK>>8);
if (s->s2->escape) pp[0]|=SEC_ESC_BIT;
pp[1]=s->s2->wlength&0xff;
pp[2]=s->s2->padding;
s->s2->wpend_len+=3;
}
else
{
pp=s->s2->mac_data;
pp-=2;
pp[0]=((s->s2->wlength>>8)&(TWO_BYTE_MASK>>8))|TWO_BYTE_BIT;
pp[1]=s->s2->wlength&0xff;
s->s2->wpend_len+=2;
}
s->s2->write_ptr=pp;
INC32(s->s2->write_sequence);
s->s2->wpend_tot=olen;
s->s2->wpend_buf=buf;
s->s2->wpend_ret=len;
s->s2->wpend_off=0;
return(write_pending(s,buf,olen));
}
int ssl2_part_read(SSL *s, unsigned long f, int i)
{
unsigned char *p;
int j;
if ((s->init_num == 0) && (i >= 3))
{
p=(unsigned char *)s->init_buf->data;
if (p[0] == SSL2_MT_ERROR)
{
j=(p[1]<<8)|p[2];
SSLerr((int)f,ssl_mt_error(j));
}
}
if (i < 0)
{
return(i);
}
else
{
s->init_num+=i;
return(0);
}
}
int ssl2_do_write(SSL *s)
{
int ret;
ret=ssl2_write(s,&s->init_buf->data[s->init_off],s->init_num);
if (ret == s->init_num)
return(1);
if (ret < 0)
return(-1);
s->init_off+=ret;
s->init_num-=ret;
return(0);
}
static int ssl_mt_error(int n)
{
int ret;
switch (n)
{
case SSL2_PE_NO_CIPHER:
ret=SSL_R_PEER_ERROR_NO_CIPHER;
break;
case SSL2_PE_NO_CERTIFICATE:
ret=SSL_R_PEER_ERROR_NO_CERTIFICATE;
break;
case SSL2_PE_BAD_CERTIFICATE:
ret=SSL_R_PEER_ERROR_CERTIFICATE;
break;
case SSL2_PE_UNSUPPORTED_CERTIFICATE_TYPE:
ret=SSL_R_PEER_ERROR_UNSUPPORTED_CERTIFICATE_TYPE;
break;
default:
ret=SSL_R_UNKNOWN_REMOTE_ERROR_TYPE;
break;
}
return(ret);
}
