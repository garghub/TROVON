int ssl3_read_n(SSL *s, int n, int max, int extend)
{
int i,off,newb;
if (!extend)
{
if (s->s3->rbuf.left == 0)
s->s3->rbuf.offset = 0;
s->packet = s->s3->rbuf.buf + s->s3->rbuf.offset;
s->packet_length = 0;
}
if ( SSL_version(s) == DTLS1_VERSION &&
extend)
{
if ( s->s3->rbuf.left > 0 && n > s->s3->rbuf.left)
n = s->s3->rbuf.left;
}
if (s->s3->rbuf.left >= (int)n)
{
s->packet_length+=n;
s->s3->rbuf.left-=n;
s->s3->rbuf.offset+=n;
return(n);
}
if (!s->read_ahead)
max=n;
{
int max_max = s->s3->rbuf.len - s->packet_length;
if (max > max_max)
max = max_max;
}
if (n > max)
{
SSLerr(SSL_F_SSL3_READ_N,ERR_R_INTERNAL_ERROR);
return -1;
}
off = s->packet_length;
newb = s->s3->rbuf.left;
if (s->packet != s->s3->rbuf.buf)
{
memmove(s->s3->rbuf.buf, s->packet, off+newb);
s->packet = s->s3->rbuf.buf;
}
while (newb < n)
{
clear_sys_error();
if (s->rbio != NULL)
{
s->rwstate=SSL_READING;
i=BIO_read(s->rbio, &(s->s3->rbuf.buf[off+newb]), max-newb);
}
else
{
SSLerr(SSL_F_SSL3_READ_N,SSL_R_READ_BIO_NOT_SET);
i = -1;
}
if (i <= 0)
{
s->s3->rbuf.left = newb;
return(i);
}
newb+=i;
}
s->s3->rbuf.offset = off + n;
s->s3->rbuf.left = newb - n;
s->packet_length += n;
s->rwstate=SSL_NOTHING;
return(n);
}
static int ssl3_get_record(SSL *s)
{
int ssl_major,ssl_minor,al;
int enc_err,n,i,ret= -1;
SSL3_RECORD *rr;
SSL_SESSION *sess;
unsigned char *p;
unsigned char md[EVP_MAX_MD_SIZE];
short version;
unsigned int mac_size;
int clear=0;
size_t extra;
int decryption_failed_or_bad_record_mac = 0;
unsigned char *mac = NULL;
rr= &(s->s3->rrec);
sess=s->session;
if (s->options & SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER)
extra=SSL3_RT_MAX_EXTRA;
else
extra=0;
if (extra != s->s3->rbuf.len - SSL3_RT_MAX_PACKET_SIZE)
{
SSLerr(SSL_F_SSL3_GET_RECORD, ERR_R_INTERNAL_ERROR);
return -1;
}
again:
if ( (s->rstate != SSL_ST_READ_BODY) ||
(s->packet_length < SSL3_RT_HEADER_LENGTH))
{
n=ssl3_read_n(s, SSL3_RT_HEADER_LENGTH, s->s3->rbuf.len, 0);
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
if (rr->length > SSL3_RT_MAX_ENCRYPTED_LENGTH+extra)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_PACKET_LENGTH_TOO_LONG);
goto f_err;
}
}
if (rr->length > s->packet_length-SSL3_RT_HEADER_LENGTH)
{
i=rr->length;
n=ssl3_read_n(s,i,i,1);
if (n <= 0) return(n);
}
s->rstate=SSL_ST_READ_HEADER;
rr->input= &(s->packet[SSL3_RT_HEADER_LENGTH]);
if (rr->length > SSL3_RT_MAX_ENCRYPTED_LENGTH+extra)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_ENCRYPTED_LENGTH_TOO_LONG);
goto f_err;
}
rr->data=rr->input;
enc_err = s->method->ssl3_enc->enc(s,0);
if (enc_err <= 0)
{
if (enc_err == 0)
goto err;
decryption_failed_or_bad_record_mac = 1;
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
#if 0
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
#else
decryption_failed_or_bad_record_mac = 1;
#endif
}
if (rr->length >= mac_size)
{
rr->length -= mac_size;
mac = &rr->data[rr->length];
}
else
{
#if 0
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_LENGTH_TOO_SHORT);
goto f_err;
#else
decryption_failed_or_bad_record_mac = 1;
rr->length = 0;
#endif
}
i=s->method->ssl3_enc->mac(s,md,0);
if (mac == NULL || memcmp(md, mac, mac_size) != 0)
{
decryption_failed_or_bad_record_mac = 1;
}
}
if (decryption_failed_or_bad_record_mac)
{
al=SSL_AD_BAD_RECORD_MAC;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_DECRYPTION_FAILED_OR_BAD_RECORD_MAC);
goto f_err;
}
if (s->expand != NULL)
{
if (rr->length > SSL3_RT_MAX_COMPRESSED_LENGTH+extra)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_COMPRESSED_LENGTH_TOO_LONG);
goto f_err;
}
if (!ssl3_do_uncompress(s))
{
al=SSL_AD_DECOMPRESSION_FAILURE;
SSLerr(SSL_F_SSL3_GET_RECORD,SSL_R_BAD_DECOMPRESSION);
goto f_err;
}
}
if (rr->length > SSL3_RT_MAX_PLAIN_LENGTH+extra)
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
int ssl3_do_uncompress(SSL *ssl)
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
int ssl3_do_compress(SSL *ssl)
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
int ssl3_write_bytes(SSL *s, int type, const void *buf_, int len)
{
const unsigned char *buf=buf_;
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
return -1;
}
}
n=(len-tot);
for (;;)
{
if (n > SSL3_RT_MAX_PLAIN_LENGTH)
nw=SSL3_RT_MAX_PLAIN_LENGTH;
else
nw=n;
i=do_ssl3_write(s, type, &(buf[tot]), nw, 0);
if (i <= 0)
{
s->s3->wnum=tot;
return i;
}
if ((i == (int)n) ||
(type == SSL3_RT_APPLICATION_DATA &&
(s->mode & SSL_MODE_ENABLE_PARTIAL_WRITE)))
{
s->s3->empty_fragment_done = 0;
return tot+i;
}
n-=i;
tot+=i;
}
}
static int do_ssl3_write(SSL *s, int type, const unsigned char *buf,
unsigned int len, int create_empty_fragment)
{
unsigned char *p,*plen;
int i,mac_size,clear=0;
int prefix_len = 0;
SSL3_RECORD *wr;
SSL3_BUFFER *wb;
SSL_SESSION *sess;
if (s->s3->wbuf.left != 0)
return(ssl3_write_pending(s,type,buf,len));
if (s->s3->alert_dispatch)
{
i=s->method->ssl_dispatch_alert(s);
if (i <= 0)
return(i);
}
if (len == 0 && !create_empty_fragment)
return 0;
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
if (!clear && !create_empty_fragment && !s->s3->empty_fragment_done)
{
if (s->s3->need_empty_fragments && type == SSL3_RT_APPLICATION_DATA)
{
prefix_len = do_ssl3_write(s, type, buf, 0, 1);
if (prefix_len <= 0)
goto err;
if (s->s3->wbuf.len < (size_t)prefix_len + SSL3_RT_MAX_PACKET_SIZE)
{
SSLerr(SSL_F_DO_SSL3_WRITE, ERR_R_INTERNAL_ERROR);
goto err;
}
}
s->s3->empty_fragment_done = 1;
}
p = wb->buf + prefix_len;
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
if (!ssl3_do_compress(s))
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
if (create_empty_fragment)
{
return wr->length;
}
wb->left = prefix_len + wr->length;
wb->offset = 0;
s->s3->wpend_tot=len;
s->s3->wpend_buf=buf;
s->s3->wpend_type=type;
s->s3->wpend_ret=len;
return ssl3_write_pending(s,type,buf,len);
err:
return -1;
}
int ssl3_write_pending(SSL *s, int type, const unsigned char *buf,
unsigned int len)
{
int i;
if ((s->s3->wpend_tot > (int)len)
|| ((s->s3->wpend_buf != buf) &&
!(s->mode & SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER))
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
int ssl3_read_bytes(SSL *s, int type, unsigned char *buf, int len, int peek)
{
int al,i,j,ret;
unsigned int n;
SSL3_RECORD *rr;
void (*cb)(const SSL *ssl,int type2,int val)=NULL;
if (s->s3->rbuf.buf == NULL)
if (!ssl3_setup_buffers(s))
return(-1);
if ((type && (type != SSL3_RT_APPLICATION_DATA) && (type != SSL3_RT_HANDSHAKE) && type) ||
(peek && (type != SSL3_RT_APPLICATION_DATA)))
{
SSLerr(SSL_F_SSL3_READ_BYTES, ERR_R_INTERNAL_ERROR);
return -1;
}
if ((type == SSL3_RT_HANDSHAKE) && (s->s3->handshake_fragment_len > 0))
{
unsigned char *src = s->s3->handshake_fragment;
unsigned char *dst = buf;
unsigned int k;
n = 0;
while ((len > 0) && (s->s3->handshake_fragment_len > 0))
{
*dst++ = *src++;
len--; s->s3->handshake_fragment_len--;
n++;
}
for (k = 0; k < s->s3->handshake_fragment_len; k++)
s->s3->handshake_fragment[k] = *src++;
return n;
}
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
rr = &(s->s3->rrec);
if ((rr->length == 0) || (s->rstate == SSL_ST_READ_BODY))
{
ret=ssl3_get_record(s);
if (ret <= 0) return(ret);
}
if (s->s3->change_cipher_spec
&& (rr->type != SSL3_RT_HANDSHAKE))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_DATA_BETWEEN_CCS_AND_FINISHED);
goto f_err;
}
if (s->shutdown & SSL_RECEIVED_SHUTDOWN)
{
rr->length=0;
s->rwstate=SSL_NOTHING;
return(0);
}
if (type == rr->type)
{
if (SSL_in_init(s) && (type == SSL3_RT_APPLICATION_DATA) &&
(s->enc_read_ctx == NULL))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_APP_DATA_IN_HANDSHAKE);
goto f_err;
}
if (len <= 0) return(len);
if ((unsigned int)len > rr->length)
n = rr->length;
else
n = (unsigned int)len;
memcpy(buf,&(rr->data[rr->off]),n);
if (!peek)
{
rr->length-=n;
rr->off+=n;
if (rr->length == 0)
{
s->rstate=SSL_ST_READ_HEADER;
rr->off=0;
}
}
return(n);
}
{
unsigned int dest_maxlen = 0;
unsigned char *dest = NULL;
unsigned int *dest_len = NULL;
if (rr->type == SSL3_RT_HANDSHAKE)
{
dest_maxlen = sizeof s->s3->handshake_fragment;
dest = s->s3->handshake_fragment;
dest_len = &s->s3->handshake_fragment_len;
}
else if (rr->type == SSL3_RT_ALERT)
{
dest_maxlen = sizeof s->s3->alert_fragment;
dest = s->s3->alert_fragment;
dest_len = &s->s3->alert_fragment_len;
}
if (dest_maxlen > 0)
{
n = dest_maxlen - *dest_len;
if (rr->length < n)
n = rr->length;
while (n-- > 0)
{
dest[(*dest_len)++] = rr->data[rr->off++];
rr->length--;
}
if (*dest_len < dest_maxlen)
goto start;
}
}
if ((!s->server) &&
(s->s3->handshake_fragment_len >= 4) &&
(s->s3->handshake_fragment[0] == SSL3_MT_HELLO_REQUEST) &&
(s->session != NULL) && (s->session->cipher != NULL))
{
s->s3->handshake_fragment_len = 0;
if ((s->s3->handshake_fragment[1] != 0) ||
(s->s3->handshake_fragment[2] != 0) ||
(s->s3->handshake_fragment[3] != 0))
{
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_BAD_HELLO_REQUEST);
goto f_err;
}
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE, s->s3->handshake_fragment, 4, s, s->msg_callback_arg);
if (SSL_is_init_finished(s) &&
!(s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS) &&
!s->s3->renegotiate)
{
ssl3_renegotiate(s);
if (ssl3_renegotiate_check(s))
{
i=s->handshake_func(s);
if (i < 0) return(i);
if (i == 0)
{
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
if (!(s->mode & SSL_MODE_AUTO_RETRY))
{
if (s->s3->rbuf.left == 0)
{
BIO *bio;
s->rwstate=SSL_READING;
bio=SSL_get_rbio(s);
BIO_clear_retry_flags(bio);
BIO_set_retry_read(bio);
return(-1);
}
}
}
}
goto start;
}
if (s->s3->alert_fragment_len >= 2)
{
int alert_level = s->s3->alert_fragment[0];
int alert_descr = s->s3->alert_fragment[1];
s->s3->alert_fragment_len = 0;
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_ALERT, s->s3->alert_fragment, 2, s, s->msg_callback_arg);
if (s->info_callback != NULL)
cb=s->info_callback;
else if (s->ctx->info_callback != NULL)
cb=s->ctx->info_callback;
if (cb != NULL)
{
j = (alert_level << 8) | alert_descr;
cb(s, SSL_CB_READ_ALERT, j);
}
if (alert_level == 1)
{
s->s3->warn_alert = alert_descr;
if (alert_descr == SSL_AD_CLOSE_NOTIFY)
{
s->shutdown |= SSL_RECEIVED_SHUTDOWN;
return(0);
}
}
else if (alert_level == 2)
{
char tmp[16];
s->rwstate=SSL_NOTHING;
s->s3->fatal_alert = alert_descr;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_AD_REASON_OFFSET + alert_descr);
BIO_snprintf(tmp,sizeof tmp,"%d",alert_descr);
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
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_BAD_CHANGE_CIPHER_SPEC);
goto f_err;
}
if (s->s3->tmp.new_cipher == NULL)
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_CCS_RECEIVED_EARLY);
goto f_err;
}
rr->length=0;
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_CHANGE_CIPHER_SPEC, rr->data, 1, s, s->msg_callback_arg);
s->s3->change_cipher_spec=1;
if (!ssl3_do_change_cipher_spec(s))
goto err;
else
goto start;
}
if ((s->s3->handshake_fragment_len >= 4) && !s->in_handshake)
{
if (((s->state&SSL_ST_MASK) == SSL_ST_OK) &&
!(s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS))
{
#if 0
s->state=SSL_ST_BEFORE|(s->server)
?SSL_ST_ACCEPT
:SSL_ST_CONNECT;
#else
s->state = s->server ? SSL_ST_ACCEPT : SSL_ST_CONNECT;
#endif
s->new_session=1;
}
i=s->handshake_func(s);
if (i < 0) return(i);
if (i == 0)
{
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
if (!(s->mode & SSL_MODE_AUTO_RETRY))
{
if (s->s3->rbuf.left == 0)
{
BIO *bio;
s->rwstate=SSL_READING;
bio=SSL_get_rbio(s);
BIO_clear_retry_flags(bio);
BIO_set_retry_read(bio);
return(-1);
}
}
goto start;
}
switch (rr->type)
{
default:
#ifndef OPENSSL_NO_TLS
if (s->version == TLS1_VERSION)
{
rr->length = 0;
goto start;
}
#endif
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_UNEXPECTED_RECORD);
goto f_err;
case SSL3_RT_CHANGE_CIPHER_SPEC:
case SSL3_RT_ALERT:
case SSL3_RT_HANDSHAKE:
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,ERR_R_INTERNAL_ERROR);
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
s->s3->in_read_app_data=2;
return(-1);
}
else
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES,SSL_R_UNEXPECTED_RECORD);
goto f_err;
}
}
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
return(-1);
}
int ssl3_do_change_cipher_spec(SSL *s)
{
int i;
const char *sender;
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
sender=s->method->ssl3_enc->server_finished_label;
slen=s->method->ssl3_enc->server_finished_label_len;
}
else
{
sender=s->method->ssl3_enc->client_finished_label;
slen=s->method->ssl3_enc->client_finished_label_len;
}
s->s3->tmp.peer_finish_md_len = s->method->ssl3_enc->final_finish_mac(s,
&(s->s3->finish_dgst1),
&(s->s3->finish_dgst2),
sender,slen,s->s3->tmp.peer_finish_md);
return(1);
}
void ssl3_send_alert(SSL *s, int level, int desc)
{
desc=s->method->ssl3_enc->alert_value(desc);
if (s->version == SSL3_VERSION && desc == SSL_AD_PROTOCOL_VERSION)
desc = SSL_AD_HANDSHAKE_FAILURE;
if (desc < 0) return;
if ((level == 2) && (s->session != NULL))
SSL_CTX_remove_session(s->ctx,s->session);
s->s3->alert_dispatch=1;
s->s3->send_alert[0]=level;
s->s3->send_alert[1]=desc;
if (s->s3->wbuf.left == 0)
s->method->ssl_dispatch_alert(s);
}
int ssl3_dispatch_alert(SSL *s)
{
int i,j;
void (*cb)(const SSL *ssl,int type,int val)=NULL;
s->s3->alert_dispatch=0;
i = do_ssl3_write(s, SSL3_RT_ALERT, &s->s3->send_alert[0], 2, 0);
if (i <= 0)
{
s->s3->alert_dispatch=1;
}
else
{
if (s->s3->send_alert[0] == SSL3_AL_FATAL)
(void)BIO_flush(s->wbio);
if (s->msg_callback)
s->msg_callback(1, s->version, SSL3_RT_ALERT, s->s3->send_alert, 2, s, s->msg_callback_arg);
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
