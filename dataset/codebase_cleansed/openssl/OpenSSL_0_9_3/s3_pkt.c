static int ssl3_read_n(SSL *s, int n, int max, int extend)
{
int i,off,newb;
if (s->s3->rbuf.left >= (int)n)
{
if (extend)
s->packet_length+=n;
else
{
s->packet= &(s->s3->rbuf.buf[s->s3->rbuf.offset]);
s->packet_length=n;
}
s->s3->rbuf.left-=n;
s->s3->rbuf.offset+=n;
return(n);
}
if (!s->read_ahead) max=n;
if (max > SSL3_RT_MAX_PACKET_SIZE)
max=SSL3_RT_MAX_PACKET_SIZE;
off=0;
if ( (s->s3->rbuf.left != 0) ||
((s->packet_length != 0) && extend))
{
newb=s->s3->rbuf.left;
if (extend)
{
off=s->packet_length;
if (s->packet != s->s3->rbuf.buf)
memcpy(s->s3->rbuf.buf,s->packet,newb+off);
}
else if (s->s3->rbuf.offset != 0)
{
memcpy(s->s3->rbuf.buf,
&(s->s3->rbuf.buf[s->s3->rbuf.offset]),newb);
s->s3->rbuf.offset=0;
}
s->s3->rbuf.left=0;
}
else
newb=0;
s->packet=s->s3->rbuf.buf;
while (newb < n)
{
clear_sys_error();
if (s->rbio != NULL)
{
s->rwstate=SSL_READING;
i=BIO_read(s->rbio,
(char *)&(s->s3->rbuf.buf[off+newb]),
max-newb);
}
else
{
SSLerr(SSL_F_SSL3_READ_N,SSL_R_READ_BIO_NOT_SET);
i= -1;
}
if (i <= 0)
{
s->s3->rbuf.left+=newb;
return(i);
}
newb+=i;
}
if (newb > n)
{
s->s3->rbuf.offset=n+off;
s->s3->rbuf.left=newb-n;
}
else
{
s->s3->rbuf.offset=0;
s->s3->rbuf.left=0;
}
if (extend)
s->packet_length+=n;
else
s->packet_length+=n;
return(n);
}
static int ssl3_get_record(SSL *s)
{
int ssl_major,ssl_minor,al;
int n,i,ret= -1;
SSL3_BUFFER *rb;
SSL3_RECORD *rr;
SSL_SESSION *sess;
unsigned char *p;
unsigned char md[EVP_MAX_MD_SIZE];
short version;
unsigned int mac_size;
int clear=0,extra;
rr= &(s->s3->rrec);
rb= &(s->s3->rbuf);
sess=s->session;
if (s->options & SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER)
extra=SSL3_RT_MAX_EXTRA;
else
extra=0;
again:
if ( (s->rstate != SSL_ST_READ_BODY) ||
(s->packet_length < SSL3_RT_HEADER_LENGTH))
{
n=ssl3_read_n(s,SSL3_RT_HEADER_LENGTH,
SSL3_RT_MAX_PACKET_SIZE,0);
if (n <= 0) return(n);
s->rstate=SSL_ST_READ_BODY;
p=s->packet;
rr->type= *(p++);
ssl_major= *(p++);
ssl_minor= *(p++);
version=(ssl_major<<8)|ssl_minor;
n2s(p,rr->length);
if (s->first_packet)
{
s->first_packet=0;
}
else
{
if (version != s->version)
{
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_WRONG_VERSION_NUMBER);
s->version=version;
al=SSL_AD_PROTOCOL_VERSION;
goto f_err;
}
}
if ((version>>8) != SSL3_VERSION_MAJOR)
{
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_WRONG_VERSION_NUMBER);
goto err;
}
if (rr->length >
(unsigned int)SSL3_RT_MAX_ENCRYPTED_LENGTH+extra)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_PACKET_LENGTH_TOO_LONG);
goto f_err;
}
s->rstate=SSL_ST_READ_BODY;
}
if (s->rstate == SSL_ST_READ_BODY)
{
if (rr->length > (s->packet_length-SSL3_RT_HEADER_LENGTH))
{
i=rr->length;
n=ssl3_read_n(s,i,i,1);
if (n <= 0) return(n);
}
s->rstate=SSL_ST_READ_HEADER;
}
rr->input= &(s->packet[SSL3_RT_HEADER_LENGTH]);
s->rstate=SSL_ST_READ_HEADER;
if (rr->length > (unsigned int)SSL3_RT_MAX_ENCRYPTED_LENGTH+extra)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_ENCRYPTED_LENGTH_TOO_LONG);
goto f_err;
}
rr->data=rr->input;
if (!s->method->ssl3_enc->enc(s,0))
{
al=SSL_AD_DECRYPT_ERROR;
goto f_err;
}
#ifdef TLS_DEBUG
printf("dec %d\n",rr->length);
{ unsigned int z; for (z=0; z<rr->length; z++) printf("%02X%c",rr->data[z],((z+1)%16)?' ':'\n'); }
printf("\n");
#endif
if ( (sess == NULL) ||
(s->enc_read_ctx == NULL) ||
(s->read_hash == NULL))
clear=1;
if (!clear)
{
mac_size=EVP_MD_size(s->read_hash);
if (rr->length > SSL3_RT_MAX_COMPRESSED_LENGTH+extra+mac_size)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
}
if (rr->length < mac_size)
{
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_LENGTH_TOO_SHORT);
goto f_err;
}
rr->length-=mac_size;
i=s->method->ssl3_enc->mac(s,md,0);
if (memcmp(md,&(rr->data[rr->length]),mac_size) != 0)
{
al=SSL_AD_BAD_RECORD_MAC;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_BAD_MAC_DECODE);
ret= -1;
goto f_err;
}
}
if (s->expand != NULL)
{
if (rr->length >
(unsigned int)SSL3_RT_MAX_COMPRESSED_LENGTH+extra)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_COMPRESSED_LENGTH_TOO_LONG);
goto f_err;
}
if (!do_uncompress(s))
{
al=SSL_AD_DECOMPRESSION_FAILURE;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_BAD_DECOMPRESSION);
goto f_err;
}
}
if (rr->length > (unsigned int)SSL3_RT_MAX_PLAIN_LENGTH+extra)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_DATA_LENGTH_TOO_LONG);
goto f_err;
}
rr->off=0;
s->packet_length=0;
if (rr->length == 0) goto again;
return(1);
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
return(ret);
}
static int do_uncompress(SSL *ssl)
{
int i;
SSL3_RECORD *rr;
rr= &(ssl->s3->rrec);
i=COMP_expand_block(ssl->expand,rr->comp,
SSL3_RT_MAX_PLAIN_LENGTH,rr->data,(int)rr->length);
if (i < 0)
return(0);
else
rr->length=i;
rr->data=rr->comp;
return(1);
}
static int do_compress(SSL *ssl)
{
int i;
SSL3_RECORD *wr;
wr= &(ssl->s3->wrec);
i=COMP_compress_block(ssl->compress,wr->data,
SSL3_RT_MAX_COMPRESSED_LENGTH,
wr->input,(int)wr->length);
if (i < 0)
return(0);
else
wr->length=i;
wr->input=wr->data;
return(1);
}
int ssl3_write_bytes(SSL *s, int type, const void *_buf, int len)
{
const unsigned char *buf=_buf;
unsigned int tot,n,nw;
int i;
s->rwstate=SSL_NOTHING;
tot=s->s3->wnum;
s->s3->wnum=0;
if (SSL_in_init(s) && !s->in_handshake)
{
i=s->handshake_func(s);
if (i < 0) return(i);
if (i == 0)
{
SSLerr(SSL_F_SSL3_WRITE_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
}
n=(len-tot);
for (;;)
{
if (n > SSL3_RT_MAX_PLAIN_LENGTH)
nw=SSL3_RT_MAX_PLAIN_LENGTH;
else
nw=n;
i=do_ssl3_write(s,type,&(buf[tot]),nw);
if (i <= 0)
{
s->s3->wnum=tot;
return(i);
}
if (type == SSL3_RT_HANDSHAKE)
ssl3_finish_mac(s,&(buf[tot]),i);
if (i == (int)n) return(tot+i);
n-=i;
tot+=i;
}
}
static int do_ssl3_write(SSL *s, int type, const unsigned char *buf,
unsigned int len)
{
unsigned char *p,*plen;
int i,mac_size,clear=0;
SSL3_RECORD *wr;
SSL3_BUFFER *wb;
SSL_SESSION *sess;
if (s->s3->wbuf.left != 0)
return(ssl3_write_pending(s,type,buf,len));
if (s->s3->alert_dispatch)
{
i=ssl3_dispatch_alert(s);
if (i <= 0)
return(i);
}
if (len <= 0) return(len);
wr= &(s->s3->wrec);
wb= &(s->s3->wbuf);
sess=s->session;
if ( (sess == NULL) ||
(s->enc_write_ctx == NULL) ||
(s->write_hash == NULL))
clear=1;
if (clear)
mac_size=0;
else
mac_size=EVP_MD_size(s->write_hash);
p=wb->buf;
*(p++)=type&0xff;
wr->type=type;
*(p++)=(s->version>>8);
*(p++)=s->version&0xff;
plen=p;
p+=2;
wr->data=p;
wr->length=(int)len;
wr->input=(unsigned char *)buf;
if (s->compress != NULL)
{
if (!do_compress(s))
{
SSLerr(SSL_F_DO_SSL3_WRITE,SSL_R_COMPRESSION_FAILURE);
goto err;
}
}
else
{
memcpy(wr->data,wr->input,wr->length);
wr->input=wr->data;
}
if (mac_size != 0)
{
s->method->ssl3_enc->mac(s,&(p[wr->length]),1);
wr->length+=mac_size;
wr->input=p;
wr->data=p;
}
s->method->ssl3_enc->enc(s,1);
s2n(wr->length,plen);
wr->type=type;
wr->length+=SSL3_RT_HEADER_LENGTH;
wb->left=wr->length;
wb->offset=0;
s->s3->wpend_tot=len;
s->s3->wpend_buf=buf;
s->s3->wpend_type=type;
s->s3->wpend_ret=len;
return(ssl3_write_pending(s,type,buf,len));
err:
return(-1);
}
static int ssl3_write_pending(SSL *s, int type, const unsigned char *buf,
unsigned int len)
{
int i;
if ((s->s3->wpend_tot > (int)len) || (s->s3->wpend_buf != buf)
|| (s->s3->wpend_type != type))
{
SSLerr(SSL_F_SSL3_WRITE_PENDING,SSL_R_BAD_WRITE_RETRY);
return(-1);
}
for (;;)
{
clear_sys_error();
if (s->wbio != NULL)
{
s->rwstate=SSL_WRITING;
i=BIO_write(s->wbio,
(char *)&(s->s3->wbuf.buf[s->s3->wbuf.offset]),
(unsigned int)s->s3->wbuf.left);
}
else
{
SSLerr(SSL_F_SSL3_WRITE_PENDING,SSL_R_BIO_NOT_SET);
i= -1;
}
if (i == s->s3->wbuf.left)
{
s->s3->wbuf.left=0;
s->rwstate=SSL_NOTHING;
return(s->s3->wpend_ret);
}
else if (i <= 0)
return(i);
s->s3->wbuf.offset+=i;
s->s3->wbuf.left-=i;
}
}
int ssl3_read_bytes(SSL *s, int type, unsigned char *buf, int len)
{
int al,i,j,n,ret;
SSL3_RECORD *rr;
void (*cb)()=NULL;
BIO *bio;
if (s->s3->rbuf.buf == NULL)
if (!ssl3_setup_buffers(s))
return(-1);
if (!s->in_handshake && SSL_in_init(s))
{
i=s->handshake_func(s);
if (i < 0) return(i);
if (i == 0)
{
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
}
start:
s->rwstate=SSL_NOTHING;
rr= &(s->s3->rrec);
if ((rr->length == 0) || (s->rstate == SSL_ST_READ_BODY))
{
ret=ssl3_get_record(s);
if (ret <= 0) return(ret);
}
if (s->s3->change_cipher_spec && (rr->type != SSL3_RT_HANDSHAKE))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_DATA_BETWEEN_CCS_AND_FINISHED);
goto err;
}
if (s->shutdown & SSL_RECEIVED_SHUTDOWN)
{
rr->length=0;
s->rwstate=SSL_NOTHING;
return(0);
}
if ((rr->type == SSL3_RT_HANDSHAKE) && (rr->length == 4) &&
(rr->data[0] == SSL3_MT_CLIENT_REQUEST) &&
(s->session != NULL) && (s->session->cipher != NULL))
{
if ((rr->data[1] != 0) || (rr->data[2] != 0) ||
(rr->data[3] != 0))
{
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_BAD_CLIENT_REQUEST);
goto err;
}
if (SSL_is_init_finished(s) &&
!(s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS) &&
!s->s3->renegotiate)
{
ssl3_renegotiate(s);
if (ssl3_renegotiate_check(s))
{
n=s->handshake_func(s);
if (n < 0) return(n);
if (n == 0)
{
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
}
}
rr->length=0;
goto start;
}
if ((rr->type != type) || (s->shutdown & SSL_SENT_SHUTDOWN))
{
if (rr->type == SSL3_RT_ALERT)
{
if ((rr->length != 2) || (rr->off != 0))
{
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_BAD_ALERT_RECORD);
goto f_err;
}
i=rr->data[0];
n=rr->data[1];
rr->length=0;
if (s->info_callback != NULL)
cb=s->info_callback;
else if (s->ctx->info_callback != NULL)
cb=s->ctx->info_callback;
if (cb != NULL)
{
j=(i<<8)|n;
cb(s,SSL_CB_READ_ALERT,j);
}
if (i == 1)
{
s->s3->warn_alert=n;
if (n == SSL_AD_CLOSE_NOTIFY)
{
s->shutdown|=SSL_RECEIVED_SHUTDOWN;
return(0);
}
}
else if (i == 2)
{
char tmp[16];
s->rwstate=SSL_NOTHING;
s->s3->fatal_alert=n;
SSLerr(SSL_F_SSL3_READ_BYTES,
SSL_AD_REASON_OFFSET+n);
sprintf(tmp,"%d",n);
ERR_add_error_data(2,"SSL alert number ",tmp);
s->shutdown|=SSL_RECEIVED_SHUTDOWN;
SSL_CTX_remove_session(s->ctx,s->session);
return(0);
}
else
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_UNKNOWN_ALERT_TYPE);
goto f_err;
}
rr->length=0;
goto start;
}
if (s->shutdown & SSL_SENT_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
rr->length=0;
return(0);
}
if (rr->type == SSL3_RT_CHANGE_CIPHER_SPEC)
{
if ( (rr->length != 1) || (rr->off != 0) ||
(rr->data[0] != SSL3_MT_CCS))
{
i=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_BAD_CHANGE_CIPHER_SPEC);
goto err;
}
rr->length=0;
s->s3->change_cipher_spec=1;
if (!do_change_cipher_spec(s))
goto err;
else
goto start;
}
if ((rr->type == SSL3_RT_HANDSHAKE) &&
!s->in_handshake)
{
if (((s->state&SSL_ST_MASK) == SSL_ST_OK) &&
!(s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS))
{
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
s->new_session=1;
}
n=s->handshake_func(s);
if (n < 0) return(n);
if (n == 0)
{
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
s->rwstate=SSL_READING;
bio=SSL_get_rbio(s);
BIO_clear_retry_flags(bio);
BIO_set_retry_read(bio);
return(-1);
}
switch (rr->type)
{
default:
#ifndef NO_TLS
if (s->version == TLS1_VERSION)
{
goto start;
}
#endif
case SSL3_RT_CHANGE_CIPHER_SPEC:
case SSL3_RT_ALERT:
case SSL3_RT_HANDSHAKE:
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_UNEXPECTED_RECORD);
goto f_err;
case SSL3_RT_APPLICATION_DATA:
if (s->s3->in_read_app_data &&
(s->s3->total_renegotiations != 0) &&
((
(s->state & SSL_ST_CONNECT) &&
(s->state >= SSL3_ST_CW_CLNT_HELLO_A) &&
(s->state <= SSL3_ST_CR_SRVR_HELLO_A)
) || (
(s->state & SSL_ST_ACCEPT) &&
(s->state <= SSL3_ST_SW_HELLO_REQ_A) &&
(s->state >= SSL3_ST_SR_CLNT_HELLO_A)
)
))
{
s->s3->in_read_app_data=0;
return(-1);
}
else
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_UNEXPECTED_RECORD);
goto f_err;
}
}
}
if (SSL_in_init(s) && (type == SSL3_RT_APPLICATION_DATA) &&
(s->enc_read_ctx == NULL))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_APP_DATA_IN_HANDSHAKE);
goto f_err;
}
if (len <= 0) return(len);
if ((unsigned int)len > rr->length)
n=rr->length;
else
n=len;
memcpy(buf,&(rr->data[rr->off]),(unsigned int)n);
rr->length-=n;
rr->off+=n;
if (rr->length <= 0)
{
s->rstate=SSL_ST_READ_HEADER;
rr->off=0;
}
if (type == SSL3_RT_HANDSHAKE)
ssl3_finish_mac(s,buf,n);
return(n);
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
return(-1);
}
static int do_change_cipher_spec(SSL *s)
{
int i;
unsigned char *sender;
int slen;
if (s->state & SSL_ST_ACCEPT)
i=SSL3_CHANGE_CIPHER_SERVER_READ;
else
i=SSL3_CHANGE_CIPHER_CLIENT_READ;
if (s->s3->tmp.key_block == NULL)
{
s->session->cipher=s->s3->tmp.new_cipher;
if (!s->method->ssl3_enc->setup_key_block(s)) return(0);
}
if (!s->method->ssl3_enc->change_cipher_state(s,i))
return(0);
if (s->state & SSL_ST_CONNECT)
{
sender=s->method->ssl3_enc->server_finished;
slen=s->method->ssl3_enc->server_finished_len;
}
else
{
sender=s->method->ssl3_enc->client_finished;
slen=s->method->ssl3_enc->client_finished_len;
}
s->method->ssl3_enc->final_finish_mac(s,
&(s->s3->finish_dgst1),
&(s->s3->finish_dgst2),
sender,slen,&(s->s3->tmp.finish_md[0]));
return(1);
}
int ssl3_do_write(SSL *s, int type)
{
int ret;
ret=ssl3_write_bytes(s,type,&s->init_buf->data[s->init_off],
s->init_num);
if (ret == s->init_num)
return(1);
if (ret < 0) return(-1);
s->init_off+=ret;
s->init_num-=ret;
return(0);
}
void ssl3_send_alert(SSL *s, int level, int desc)
{
desc=s->method->ssl3_enc->alert_value(desc);
if (desc < 0) return;
if ((level == 2) && (s->session != NULL))
SSL_CTX_remove_session(s->ctx,s->session);
s->s3->alert_dispatch=1;
s->s3->send_alert[0]=level;
s->s3->send_alert[1]=desc;
if (s->s3->wbuf.left == 0)
ssl3_dispatch_alert(s);
}
int ssl3_dispatch_alert(SSL *s)
{
int i,j;
void (*cb)()=NULL;
s->s3->alert_dispatch=0;
i=do_ssl3_write(s,SSL3_RT_ALERT,&s->s3->send_alert[0],2);
if (i <= 0)
{
s->s3->alert_dispatch=1;
}
else
{
if (s->s3->send_alert[0] == SSL3_AL_FATAL)
BIO_flush(s->wbio);
if (s->info_callback != NULL)
cb=s->info_callback;
else if (s->ctx->info_callback != NULL)
cb=s->ctx->info_callback;
if (cb != NULL)
{
j=(s->s3->send_alert[0]<<8)|s->s3->send_alert[1];
cb(s,SSL_CB_WRITE_ALERT,j);
}
}
return(i);
}
