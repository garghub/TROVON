static int
dtls1_copy_record(SSL *s, pitem *item)
{
DTLS1_RECORD_DATA *rdata;
rdata = (DTLS1_RECORD_DATA *)item->data;
if (s->s3->rbuf.buf != NULL)
OPENSSL_free(s->s3->rbuf.buf);
s->packet = rdata->packet;
s->packet_length = rdata->packet_length;
memcpy(&(s->s3->rbuf), &(rdata->rbuf), sizeof(SSL3_BUFFER));
memcpy(&(s->s3->rrec), &(rdata->rrec), sizeof(SSL3_RECORD));
return(1);
}
static int
dtls1_buffer_record(SSL *s, record_pqueue *queue, PQ_64BIT priority)
{
DTLS1_RECORD_DATA *rdata;
pitem *item;
rdata = OPENSSL_malloc(sizeof(DTLS1_RECORD_DATA));
item = pitem_new(priority, rdata);
if (rdata == NULL || item == NULL)
{
if (rdata != NULL) OPENSSL_free(rdata);
if (item != NULL) pitem_free(item);
SSLerr(SSL_F_DTLS1_BUFFER_RECORD, ERR_R_INTERNAL_ERROR);
return(0);
}
rdata->packet = s->packet;
rdata->packet_length = s->packet_length;
memcpy(&(rdata->rbuf), &(s->s3->rbuf), sizeof(SSL3_BUFFER));
memcpy(&(rdata->rrec), &(s->s3->rrec), sizeof(SSL3_RECORD));
item->data = rdata;
if (pqueue_insert(queue->q, item) == NULL)
{
OPENSSL_free(rdata);
pitem_free(item);
return(0);
}
s->packet = NULL;
s->packet_length = 0;
memset(&(s->s3->rbuf), 0, sizeof(SSL3_BUFFER));
memset(&(s->s3->rrec), 0, sizeof(SSL3_RECORD));
ssl3_setup_buffers(s);
return(1);
}
static int
dtls1_retrieve_buffered_record(SSL *s, record_pqueue *queue)
{
pitem *item;
item = pqueue_pop(queue->q);
if (item)
{
dtls1_copy_record(s, item);
OPENSSL_free(item->data);
pitem_free(item);
return(1);
}
return(0);
}
static int
dtls1_process_buffered_records(SSL *s)
{
pitem *item;
item = pqueue_peek(s->d1->unprocessed_rcds.q);
if (item)
{
DTLS1_RECORD_DATA *rdata;
rdata = (DTLS1_RECORD_DATA *)item->data;
if (s->d1->unprocessed_rcds.epoch != s->d1->r_epoch)
return(1);
while (pqueue_peek(s->d1->unprocessed_rcds.q))
{
dtls1_get_unprocessed_record(s);
if ( ! dtls1_process_record(s))
return(0);
dtls1_buffer_record(s, &(s->d1->processed_rcds),
s->s3->rrec.seq_num);
}
}
s->d1->processed_rcds.epoch = s->d1->r_epoch;
s->d1->unprocessed_rcds.epoch = s->d1->r_epoch + 1;
return(1);
}
static int
dtls1_process_record(SSL *s)
{
int i,al;
int clear=0;
int enc_err;
SSL_SESSION *sess;
SSL3_RECORD *rr;
unsigned int mac_size;
unsigned char md[EVP_MAX_MD_SIZE];
rr= &(s->s3->rrec);
sess = s->session;
rr->input= &(s->packet[DTLS1_RT_HEADER_LENGTH]);
if (rr->length > SSL3_RT_MAX_ENCRYPTED_LENGTH)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_ENCRYPTED_LENGTH_TOO_LONG);
goto f_err;
}
rr->data=rr->input;
enc_err = s->method->ssl3_enc->enc(s,0);
if (enc_err <= 0)
{
if (enc_err == 0)
goto err;
goto decryption_failed_or_bad_record_mac;
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
if (rr->length > SSL3_RT_MAX_COMPRESSED_LENGTH+mac_size)
{
#if 0
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_PRE_MAC_LENGTH_TOO_LONG);
goto f_err;
#else
goto decryption_failed_or_bad_record_mac;
#endif
}
if (rr->length < mac_size)
{
#if 0
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_LENGTH_TOO_SHORT);
goto f_err;
#else
goto decryption_failed_or_bad_record_mac;
#endif
}
rr->length-=mac_size;
i=s->method->ssl3_enc->mac(s,md,0);
if (memcmp(md,&(rr->data[rr->length]),mac_size) != 0)
{
goto decryption_failed_or_bad_record_mac;
}
}
if (s->expand != NULL)
{
if (rr->length > SSL3_RT_MAX_COMPRESSED_LENGTH)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_COMPRESSED_LENGTH_TOO_LONG);
goto f_err;
}
if (!ssl3_do_uncompress(s))
{
al=SSL_AD_DECOMPRESSION_FAILURE;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_BAD_DECOMPRESSION);
goto f_err;
}
}
if (rr->length > SSL3_RT_MAX_PLAIN_LENGTH)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_DATA_LENGTH_TOO_LONG);
goto f_err;
}
rr->off=0;
s->packet_length=0;
dtls1_record_bitmap_update(s, &(s->d1->bitmap));
return(1);
decryption_failed_or_bad_record_mac:
al=SSL_AD_BAD_RECORD_MAC;
SSLerr(SSL_F_DTLS1_PROCESS_RECORD,SSL_R_DECRYPTION_FAILED_OR_BAD_RECORD_MAC);
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
return(0);
}
int dtls1_get_record(SSL *s)
{
int ssl_major,ssl_minor,al;
int i,n;
SSL3_RECORD *rr;
SSL_SESSION *sess;
unsigned char *p;
short version;
DTLS1_BITMAP *bitmap;
unsigned int is_next_epoch;
rr= &(s->s3->rrec);
sess=s->session;
if ( ! dtls1_process_buffered_records(s))
return 0;
if (dtls1_get_processed_record(s))
return 1;
again:
if ( (s->rstate != SSL_ST_READ_BODY) ||
(s->packet_length < DTLS1_RT_HEADER_LENGTH))
{
n=ssl3_read_n(s, DTLS1_RT_HEADER_LENGTH, s->s3->rbuf.len, 0);
if (n <= 0) return(n);
OPENSSL_assert(s->packet_length == DTLS1_RT_HEADER_LENGTH);
s->rstate=SSL_ST_READ_BODY;
p=s->packet;
rr->type= *(p++);
ssl_major= *(p++);
ssl_minor= *(p++);
version=(ssl_major<<8)|ssl_minor;
n2s(p,rr->epoch);
memcpy(&(s->s3->read_sequence[2]), p, 6);
p+=6;
n2s(p,rr->length);
if (s->first_packet)
{
s->first_packet=0;
}
else
{
if (version != s->version)
{
SSLerr(SSL_F_DTLS1_GET_RECORD,SSL_R_WRONG_VERSION_NUMBER);
s->version=version;
al=SSL_AD_PROTOCOL_VERSION;
goto f_err;
}
}
if ((version & 0xff00) != (DTLS1_VERSION & 0xff00))
{
SSLerr(SSL_F_DTLS1_GET_RECORD,SSL_R_WRONG_VERSION_NUMBER);
goto err;
}
if (rr->length > SSL3_RT_MAX_ENCRYPTED_LENGTH)
{
al=SSL_AD_RECORD_OVERFLOW;
SSLerr(SSL_F_DTLS1_GET_RECORD,SSL_R_PACKET_LENGTH_TOO_LONG);
goto f_err;
}
}
if (rr->length > s->packet_length-DTLS1_RT_HEADER_LENGTH)
{
i=rr->length;
n=ssl3_read_n(s,i,i,1);
if (n <= 0) return(n);
if ( n != i)
{
s->packet_length = 0;
goto again;
}
}
s->rstate=SSL_ST_READ_HEADER;
bitmap = dtls1_get_bitmap(s, rr, &is_next_epoch);
if ( bitmap == NULL)
{
s->packet_length = 0;
goto again;
}
if ( ! dtls1_record_replay_check(s, bitmap, &(rr->seq_num)))
{
s->packet_length=0;
goto again;
}
if (rr->length == 0) goto again;
if (is_next_epoch)
{
dtls1_record_bitmap_update(s, bitmap);
dtls1_buffer_record(s, &(s->d1->unprocessed_rcds), rr->seq_num);
s->packet_length = 0;
goto again;
}
if ( ! dtls1_process_record(s))
return(0);
dtls1_clear_timeouts(s);
return(1);
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
return(0);
}
int dtls1_read_bytes(SSL *s, int type, unsigned char *buf, int len, int peek)
{
int al,i,j,ret;
unsigned int n;
SSL3_RECORD *rr;
void (*cb)(const SSL *ssl,int type2,int val)=NULL;
if (s->s3->rbuf.buf == NULL)
if (!ssl3_setup_buffers(s))
return(-1);
if ((type && (type != SSL3_RT_APPLICATION_DATA) &&
(type != SSL3_RT_HANDSHAKE) && type) ||
(peek && (type != SSL3_RT_APPLICATION_DATA)))
{
SSLerr(SSL_F_DTLS1_READ_BYTES, ERR_R_INTERNAL_ERROR);
return -1;
}
if ( (ret = have_handshake_fragment(s, type, buf, len, peek)))
return ret;
if (!s->in_handshake && SSL_in_init(s))
{
i=s->handshake_func(s);
if (i < 0) return(i);
if (i == 0)
{
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return(-1);
}
}
start:
s->rwstate=SSL_NOTHING;
rr = &(s->s3->rrec);
if ((rr->length == 0) || (s->rstate == SSL_ST_READ_BODY))
{
ret=dtls1_get_record(s);
if (ret <= 0)
{
ret = dtls1_read_failed(s, ret);
if (ret <= 0)
return(ret);
else
goto start;
}
}
if (s->s3->change_cipher_spec
&& (rr->type != SSL3_RT_HANDSHAKE))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_DATA_BETWEEN_CCS_AND_FINISHED);
goto err;
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
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_APP_DATA_IN_HANDSHAKE);
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
unsigned int k, dest_maxlen = 0;
unsigned char *dest = NULL;
unsigned int *dest_len = NULL;
if (rr->type == SSL3_RT_HANDSHAKE)
{
dest_maxlen = sizeof s->d1->handshake_fragment;
dest = s->d1->handshake_fragment;
dest_len = &s->d1->handshake_fragment_len;
}
else if (rr->type == SSL3_RT_ALERT)
{
dest_maxlen = sizeof(s->d1->alert_fragment);
dest = s->d1->alert_fragment;
dest_len = &s->d1->alert_fragment_len;
}
else
OPENSSL_assert(rr->type == SSL3_RT_CHANGE_CIPHER_SPEC);
if (dest_maxlen > 0)
{
if ( rr->length < dest_maxlen)
{
s->rstate=SSL_ST_READ_HEADER;
rr->length = 0;
goto start;
}
for ( k = 0; k < dest_maxlen; k++)
{
dest[k] = rr->data[rr->off++];
rr->length--;
}
*dest_len = dest_maxlen;
}
}
if ((!s->server) &&
(s->d1->handshake_fragment_len >= DTLS1_HM_HEADER_LENGTH) &&
(s->d1->handshake_fragment[0] == SSL3_MT_HELLO_REQUEST) &&
(s->session != NULL) && (s->session->cipher != NULL))
{
s->d1->handshake_fragment_len = 0;
if ((s->d1->handshake_fragment[1] != 0) ||
(s->d1->handshake_fragment[2] != 0) ||
(s->d1->handshake_fragment[3] != 0))
{
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_BAD_HELLO_REQUEST);
goto err;
}
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE,
s->d1->handshake_fragment, 4, s, s->msg_callback_arg);
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
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
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
if (s->d1->alert_fragment_len >= DTLS1_AL_HEADER_LENGTH)
{
int alert_level = s->d1->alert_fragment[0];
int alert_descr = s->d1->alert_fragment[1];
s->d1->alert_fragment_len = 0;
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_ALERT,
s->d1->alert_fragment, 2, s, s->msg_callback_arg);
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
#if 0
if (alert_descr == DTLS1_AD_MISSING_HANDSHAKE_MESSAGE)
{
unsigned short seq;
unsigned int frag_off;
unsigned char *p = &(s->d1->alert_fragment[2]);
n2s(p, seq);
n2l3(p, frag_off);
dtls1_retransmit_message(s, seq, frag_off, &found);
if ( ! found && SSL_in_init(s))
{
ssl3_send_alert(s,SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
}
}
#endif
}
else if (alert_level == 2)
{
char tmp[16];
s->rwstate=SSL_NOTHING;
s->s3->fatal_alert = alert_descr;
SSLerr(SSL_F_DTLS1_READ_BYTES, SSL_AD_REASON_OFFSET + alert_descr);
BIO_snprintf(tmp,sizeof tmp,"%d",alert_descr);
ERR_add_error_data(2,"SSL alert number ",tmp);
s->shutdown|=SSL_RECEIVED_SHUTDOWN;
SSL_CTX_remove_session(s->ctx,s->session);
return(0);
}
else
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_UNKNOWN_ALERT_TYPE);
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
struct ccs_header_st ccs_hdr;
dtls1_get_ccs_header(rr->data, &ccs_hdr);
if ( ccs_hdr.seq == s->d1->handshake_read_seq)
{
if ( (rr->length != DTLS1_CCS_HEADER_LENGTH) ||
(rr->off != 0) || (rr->data[0] != SSL3_MT_CCS))
{
i=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_BAD_CHANGE_CIPHER_SPEC);
goto err;
}
rr->length=0;
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_CHANGE_CIPHER_SPEC,
rr->data, 1, s, s->msg_callback_arg);
s->s3->change_cipher_spec=1;
if (!ssl3_do_change_cipher_spec(s))
goto err;
dtls1_reset_seq_numbers(s, SSL3_CC_READ);
s->d1->handshake_read_seq++;
goto start;
}
else
{
rr->length = 0;
goto start;
}
}
if ((s->d1->handshake_fragment_len >= DTLS1_HM_HEADER_LENGTH) &&
!s->in_handshake)
{
struct hm_header_st msg_hdr;
dtls1_get_message_header(rr->data, &msg_hdr);
if( rr->epoch != s->d1->r_epoch)
{
rr->length = 0;
goto start;
}
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
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
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
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_UNEXPECTED_RECORD);
goto f_err;
case SSL3_RT_CHANGE_CIPHER_SPEC:
case SSL3_RT_ALERT:
case SSL3_RT_HANDSHAKE:
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_DTLS1_READ_BYTES,ERR_R_INTERNAL_ERROR);
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
SSLerr(SSL_F_DTLS1_READ_BYTES,SSL_R_UNEXPECTED_RECORD);
goto f_err;
}
}
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
return(-1);
}
int
dtls1_write_app_data_bytes(SSL *s, int type, const void *buf_, int len)
{
unsigned int n,tot;
int i;
if (SSL_in_init(s) && !s->in_handshake)
{
i=s->handshake_func(s);
if (i < 0) return(i);
if (i == 0)
{
SSLerr(SSL_F_DTLS1_WRITE_APP_DATA_BYTES,SSL_R_SSL_HANDSHAKE_FAILURE);
return -1;
}
}
tot = s->s3->wnum;
n = len - tot;
while( n)
{
i = dtls1_write_bytes(s, type, buf_, len);
if (i <= 0) return i;
if ((i == (int)n) ||
(type == SSL3_RT_APPLICATION_DATA &&
(s->mode & SSL_MODE_ENABLE_PARTIAL_WRITE)))
{
s->s3->empty_fragment_done = 0;
return tot+i;
}
tot += i;
n-=i;
}
return tot;
}
static int
have_handshake_fragment(SSL *s, int type, unsigned char *buf,
int len, int peek)
{
if ((type == SSL3_RT_HANDSHAKE) && (s->d1->handshake_fragment_len > 0))
{
unsigned char *src = s->d1->handshake_fragment;
unsigned char *dst = buf;
unsigned int k,n;
n = 0;
while ((len > 0) && (s->d1->handshake_fragment_len > 0))
{
*dst++ = *src++;
len--; s->d1->handshake_fragment_len--;
n++;
}
for (k = 0; k < s->d1->handshake_fragment_len; k++)
s->d1->handshake_fragment[k] = *src++;
return n;
}
return 0;
}
int dtls1_write_bytes(SSL *s, int type, const void *buf_, int len)
{
const unsigned char *buf=buf_;
unsigned int tot,n,nw;
int i;
unsigned int mtu;
s->rwstate=SSL_NOTHING;
tot=s->s3->wnum;
n=(len-tot);
#if 0
mtu = BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_GET_MTU, 0, NULL);
mtu += DTLS1_HM_HEADER_LENGTH;
#endif
mtu = s->d1->mtu;
if (mtu > SSL3_RT_MAX_PLAIN_LENGTH)
mtu = SSL3_RT_MAX_PLAIN_LENGTH;
if (n > mtu)
nw=mtu;
else
nw=n;
i=do_dtls1_write(s, type, &(buf[tot]), nw, 0);
if (i <= 0)
{
s->s3->wnum=tot;
return i;
}
if ( (int)s->s3->wnum + i == len)
s->s3->wnum = 0;
else
s->s3->wnum += i;
return tot + i;
}
int do_dtls1_write(SSL *s, int type, const unsigned char *buf, unsigned int len, int create_empty_fragment)
{
unsigned char *p,*pseq;
int i,mac_size,clear=0;
int prefix_len = 0;
SSL3_RECORD *wr;
SSL3_BUFFER *wb;
SSL_SESSION *sess;
int bs;
if (s->s3->wbuf.left != 0)
{
OPENSSL_assert(0);
return(ssl3_write_pending(s,type,buf,len));
}
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
#if 0
if (!clear && !create_empty_fragment && !s->s3->empty_fragment_done
&& SSL_version(s) != DTLS1_VERSION)
{
if (s->s3->need_empty_fragments && type == SSL3_RT_APPLICATION_DATA)
{
prefix_len = s->method->do_ssl_write(s, type, buf, 0, 1);
if (prefix_len <= 0)
goto err;
if (s->s3->wbuf.len < (size_t)prefix_len + SSL3_RT_MAX_PACKET_SIZE)
{
SSLerr(SSL_F_DO_DTLS1_WRITE, ERR_R_INTERNAL_ERROR);
goto err;
}
}
s->s3->empty_fragment_done = 1;
}
#endif
p = wb->buf + prefix_len;
*(p++)=type&0xff;
wr->type=type;
*(p++)=(s->version>>8);
*(p++)=s->version&0xff;
pseq=p;
p+=10;
if ( s->enc_write_ctx &&
(EVP_CIPHER_mode( s->enc_write_ctx->cipher ) & EVP_CIPH_CBC_MODE))
bs = EVP_CIPHER_block_size(s->enc_write_ctx->cipher);
else
bs = 0;
wr->data=p + bs;
wr->length=(int)len;
wr->input=(unsigned char *)buf;
if (s->compress != NULL)
{
if (!ssl3_do_compress(s))
{
SSLerr(SSL_F_DO_DTLS1_WRITE,SSL_R_COMPRESSION_FAILURE);
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
s->method->ssl3_enc->mac(s,&(p[wr->length + bs]),1);
wr->length+=mac_size;
}
wr->input=p;
wr->data=p;
wr->length += bs;
s->method->ssl3_enc->enc(s,1);
s2n(s->d1->w_epoch, pseq);
memcpy(pseq, &(s->s3->write_sequence[2]), 6);
pseq+=6;
s2n(wr->length,pseq);
wr->type=type;
wr->length+=DTLS1_RT_HEADER_LENGTH;
#if 0
if ( type == SSL3_RT_HANDSHAKE || type == SSL3_RT_CHANGE_CIPHER_SPEC)
dtls1_buffer_record(s, wr->data, wr->length,
*((PQ_64BIT *)&(s->s3->write_sequence[0])));
#endif
ssl3_record_sequence_update(&(s->s3->write_sequence[0]));
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
static int dtls1_record_replay_check(SSL *s, DTLS1_BITMAP *bitmap,
PQ_64BIT *seq_num)
{
#if PQ_64BIT_IS_INTEGER
PQ_64BIT mask = 0x0000000000000001L;
#endif
PQ_64BIT rcd_num, tmp;
pq_64bit_init(&rcd_num);
pq_64bit_init(&tmp);
pq_64bit_bin2num(&rcd_num, s->s3->read_sequence, 8);
if (pq_64bit_gt(&rcd_num, &(bitmap->max_seq_num)) ||
pq_64bit_eq(&rcd_num, &(bitmap->max_seq_num)))
{
pq_64bit_assign(seq_num, &rcd_num);
pq_64bit_free(&rcd_num);
pq_64bit_free(&tmp);
return 1;
}
pq_64bit_sub(&tmp, &(bitmap->max_seq_num), &rcd_num);
if ( pq_64bit_get_word(&tmp) > bitmap->length)
{
pq_64bit_free(&rcd_num);
pq_64bit_free(&tmp);
return 0;
}
#if PQ_64BIT_IS_BIGNUM
{
int offset;
pq_64bit_sub(&tmp, &(bitmap->max_seq_num), &rcd_num);
pq_64bit_sub_word(&tmp, 1);
offset = pq_64bit_get_word(&tmp);
if ( pq_64bit_is_bit_set(&(bitmap->map), offset))
{
pq_64bit_free(&rcd_num);
pq_64bit_free(&tmp);
return 0;
}
}
#else
mask <<= (bitmap->max_seq_num - rcd_num - 1);
if (bitmap->map & mask)
return 0;
#endif
pq_64bit_assign(seq_num, &rcd_num);
pq_64bit_free(&rcd_num);
pq_64bit_free(&tmp);
return 1;
}
static void dtls1_record_bitmap_update(SSL *s, DTLS1_BITMAP *bitmap)
{
unsigned int shift;
PQ_64BIT rcd_num;
PQ_64BIT tmp;
PQ_64BIT_CTX *ctx;
pq_64bit_init(&rcd_num);
pq_64bit_init(&tmp);
pq_64bit_bin2num(&rcd_num, s->s3->read_sequence, 8);
if ( pq_64bit_gt(&rcd_num, &(bitmap->max_seq_num)) ||
pq_64bit_eq(&rcd_num, &(bitmap->max_seq_num)))
{
pq_64bit_sub(&tmp, &rcd_num, &(bitmap->max_seq_num));
pq_64bit_add_word(&tmp, 1);
shift = (unsigned int)pq_64bit_get_word(&tmp);
pq_64bit_lshift(&(tmp), &(bitmap->map), shift);
pq_64bit_assign(&(bitmap->map), &tmp);
pq_64bit_set_bit(&(bitmap->map), 0);
pq_64bit_add_word(&rcd_num, 1);
pq_64bit_assign(&(bitmap->max_seq_num), &rcd_num);
pq_64bit_assign_word(&tmp, 1);
pq_64bit_lshift(&tmp, &tmp, bitmap->length);
ctx = pq_64bit_ctx_new(&ctx);
pq_64bit_mod(&(bitmap->map), &(bitmap->map), &tmp, ctx);
pq_64bit_ctx_free(ctx);
}
else
{
pq_64bit_sub(&tmp, &(bitmap->max_seq_num), &rcd_num);
pq_64bit_sub_word(&tmp, 1);
shift = (unsigned int)pq_64bit_get_word(&tmp);
pq_64bit_set_bit(&(bitmap->map), shift);
}
pq_64bit_free(&rcd_num);
pq_64bit_free(&tmp);
}
int dtls1_dispatch_alert(SSL *s)
{
int i,j;
void (*cb)(const SSL *ssl,int type,int val)=NULL;
unsigned char buf[2 + 2 + 3];
unsigned char *ptr = &buf[0];
s->s3->alert_dispatch=0;
memset(buf, 0x00, sizeof(buf));
*ptr++ = s->s3->send_alert[0];
*ptr++ = s->s3->send_alert[1];
if (s->s3->send_alert[1] == DTLS1_AD_MISSING_HANDSHAKE_MESSAGE)
{
s2n(s->d1->handshake_read_seq, ptr);
#if 0
if ( s->d1->r_msg_hdr.frag_off == 0)
else
s2n(s->d1->r_msg_hdr.seq, ptr);
#endif
#if 0
fprintf(stderr, "s->d1->handshake_read_seq = %d, s->d1->r_msg_hdr.seq = %d\n",s->d1->handshake_read_seq,s->d1->r_msg_hdr.seq);
#endif
l2n3(s->d1->r_msg_hdr.frag_off, ptr);
}
i = do_dtls1_write(s, SSL3_RT_ALERT, &buf[0], sizeof(buf), 0);
if (i <= 0)
{
s->s3->alert_dispatch=1;
}
else
{
if ( s->s3->send_alert[0] == SSL3_AL_FATAL ||
s->s3->send_alert[1] == DTLS1_AD_MISSING_HANDSHAKE_MESSAGE)
(void)BIO_flush(s->wbio);
if (s->msg_callback)
s->msg_callback(1, s->version, SSL3_RT_ALERT, s->s3->send_alert,
2, s, s->msg_callback_arg);
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
static DTLS1_BITMAP *
dtls1_get_bitmap(SSL *s, SSL3_RECORD *rr, unsigned int *is_next_epoch)
{
*is_next_epoch = 0;
if (rr->epoch == s->d1->r_epoch)
return &s->d1->bitmap;
else if (rr->epoch == (unsigned long)(s->d1->r_epoch + 1) &&
(rr->type == SSL3_RT_HANDSHAKE ||
rr->type == SSL3_RT_ALERT))
{
*is_next_epoch = 1;
return &s->d1->next_bitmap;
}
return NULL;
}
void
dtls1_reset_seq_numbers(SSL *s, int rw)
{
unsigned char *seq;
unsigned int seq_bytes = sizeof(s->s3->read_sequence);
if ( rw & SSL3_CC_READ)
{
seq = s->s3->read_sequence;
s->d1->r_epoch++;
pq_64bit_assign(&(s->d1->bitmap.map), &(s->d1->next_bitmap.map));
s->d1->bitmap.length = s->d1->next_bitmap.length;
pq_64bit_assign(&(s->d1->bitmap.max_seq_num),
&(s->d1->next_bitmap.max_seq_num));
pq_64bit_free(&(s->d1->next_bitmap.map));
pq_64bit_free(&(s->d1->next_bitmap.max_seq_num));
memset(&(s->d1->next_bitmap), 0x00, sizeof(DTLS1_BITMAP));
pq_64bit_init(&(s->d1->next_bitmap.map));
pq_64bit_init(&(s->d1->next_bitmap.max_seq_num));
}
else
{
seq = s->s3->write_sequence;
s->d1->w_epoch++;
}
memset(seq, 0x00, seq_bytes);
}
static PQ_64BIT
bytes_to_long_long(unsigned char *bytes, PQ_64BIT *num)
{
PQ_64BIT _num;
_num = (((PQ_64BIT)bytes[0]) << 56) |
(((PQ_64BIT)bytes[1]) << 48) |
(((PQ_64BIT)bytes[2]) << 40) |
(((PQ_64BIT)bytes[3]) << 32) |
(((PQ_64BIT)bytes[4]) << 24) |
(((PQ_64BIT)bytes[5]) << 16) |
(((PQ_64BIT)bytes[6]) << 8) |
(((PQ_64BIT)bytes[7]) );
*num = _num ;
return _num;
}
static void
dtls1_clear_timeouts(SSL *s)
{
memset(&(s->d1->timeout), 0x00, sizeof(struct dtls1_timeout_st));
}
