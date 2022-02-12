static hm_fragment *
dtls1_hm_fragment_new(unsigned long frag_len, int reassembly)
{
hm_fragment *frag = NULL;
unsigned char *buf = NULL;
unsigned char *bitmask = NULL;
frag = (hm_fragment *)OPENSSL_malloc(sizeof(hm_fragment));
if ( frag == NULL)
return NULL;
if (frag_len)
{
buf = (unsigned char *)OPENSSL_malloc(frag_len);
if ( buf == NULL)
{
OPENSSL_free(frag);
return NULL;
}
}
frag->fragment = buf;
if (reassembly)
{
bitmask = (unsigned char *)OPENSSL_malloc(RSMBLY_BITMASK_SIZE(frag_len));
if (bitmask == NULL)
{
if (buf != NULL) OPENSSL_free(buf);
OPENSSL_free(frag);
return NULL;
}
memset(bitmask, 0, RSMBLY_BITMASK_SIZE(frag_len));
}
frag->reassembly = bitmask;
return frag;
}
static void
dtls1_hm_fragment_free(hm_fragment *frag)
{
if (frag->fragment) OPENSSL_free(frag->fragment);
if (frag->reassembly) OPENSSL_free(frag->reassembly);
OPENSSL_free(frag);
}
int dtls1_do_write(SSL *s, int type)
{
int ret;
int curr_mtu;
unsigned int len, frag_off, mac_size, blocksize;
if (s->d1->mtu < dtls1_min_mtu() && !(SSL_get_options(s) & SSL_OP_NO_QUERY_MTU))
{
s->d1->mtu =
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
if (s->d1->mtu < dtls1_min_mtu())
{
s->d1->mtu = 0;
s->d1->mtu = dtls1_guess_mtu(s->d1->mtu);
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SET_MTU,
s->d1->mtu, NULL);
}
}
#if 0
mtu = s->d1->mtu;
fprintf(stderr, "using MTU = %d\n", mtu);
mtu -= (DTLS1_HM_HEADER_LENGTH + DTLS1_RT_HEADER_LENGTH);
curr_mtu = mtu - BIO_wpending(SSL_get_wbio(s));
if ( curr_mtu > 0)
mtu = curr_mtu;
else if ( ( ret = BIO_flush(SSL_get_wbio(s))) <= 0)
return ret;
if ( BIO_wpending(SSL_get_wbio(s)) + s->init_num >= mtu)
{
ret = BIO_flush(SSL_get_wbio(s));
if ( ret <= 0)
return ret;
mtu = s->d1->mtu - (DTLS1_HM_HEADER_LENGTH + DTLS1_RT_HEADER_LENGTH);
}
#endif
OPENSSL_assert(s->d1->mtu >= dtls1_min_mtu());
if ( s->init_off == 0 && type == SSL3_RT_HANDSHAKE)
OPENSSL_assert(s->init_num ==
(int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH);
if (s->write_hash)
mac_size = EVP_MD_CTX_size(s->write_hash);
else
mac_size = 0;
if (s->enc_write_ctx &&
(EVP_CIPHER_mode( s->enc_write_ctx->cipher) & EVP_CIPH_CBC_MODE))
blocksize = 2 * EVP_CIPHER_block_size(s->enc_write_ctx->cipher);
else
blocksize = 0;
frag_off = 0;
while( s->init_num)
{
curr_mtu = s->d1->mtu - BIO_wpending(SSL_get_wbio(s)) -
DTLS1_RT_HEADER_LENGTH - mac_size - blocksize;
if ( curr_mtu <= DTLS1_HM_HEADER_LENGTH)
{
ret = BIO_flush(SSL_get_wbio(s));
if ( ret <= 0)
return ret;
curr_mtu = s->d1->mtu - DTLS1_RT_HEADER_LENGTH -
mac_size - blocksize;
}
if ( s->init_num > curr_mtu)
len = curr_mtu;
else
len = s->init_num;
if ( type == SSL3_RT_HANDSHAKE)
{
if ( s->init_off != 0)
{
OPENSSL_assert(s->init_off > DTLS1_HM_HEADER_LENGTH);
s->init_off -= DTLS1_HM_HEADER_LENGTH;
s->init_num += DTLS1_HM_HEADER_LENGTH;
if ( len <= DTLS1_HM_HEADER_LENGTH)
len += DTLS1_HM_HEADER_LENGTH;
}
dtls1_fix_message_header(s, frag_off,
len - DTLS1_HM_HEADER_LENGTH);
dtls1_write_message_header(s, (unsigned char *)&s->init_buf->data[s->init_off]);
OPENSSL_assert(len >= DTLS1_HM_HEADER_LENGTH);
}
ret=dtls1_write_bytes(s,type,&s->init_buf->data[s->init_off],
len);
if (ret < 0)
{
if ( BIO_ctrl(SSL_get_wbio(s),
BIO_CTRL_DGRAM_MTU_EXCEEDED, 0, NULL) > 0 )
s->d1->mtu = BIO_ctrl(SSL_get_wbio(s),
BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
else
return(-1);
}
else
{
OPENSSL_assert(len == (unsigned int)ret);
if (type == SSL3_RT_HANDSHAKE && ! s->d1->retransmitting)
{
unsigned char *p = (unsigned char *)&s->init_buf->data[s->init_off];
const struct hm_header_st *msg_hdr = &s->d1->w_msg_hdr;
int xlen;
if (frag_off == 0 && s->version != DTLS1_BAD_VER)
{
*p++ = msg_hdr->type;
l2n3(msg_hdr->msg_len,p);
s2n (msg_hdr->seq,p);
l2n3(0,p);
l2n3(msg_hdr->msg_len,p);
p -= DTLS1_HM_HEADER_LENGTH;
xlen = ret;
}
else
{
p += DTLS1_HM_HEADER_LENGTH;
xlen = ret - DTLS1_HM_HEADER_LENGTH;
}
ssl3_finish_mac(s, p, xlen);
}
if (ret == s->init_num)
{
if (s->msg_callback)
s->msg_callback(1, s->version, type, s->init_buf->data,
(size_t)(s->init_off + s->init_num), s,
s->msg_callback_arg);
s->init_off = 0;
s->init_num = 0;
return(1);
}
s->init_off+=ret;
s->init_num-=ret;
frag_off += (ret -= DTLS1_HM_HEADER_LENGTH);
}
}
return(0);
}
long dtls1_get_message(SSL *s, int st1, int stn, int mt, long max, int *ok)
{
int i, al;
struct hm_header_st *msg_hdr;
unsigned char *p;
unsigned long msg_len;
if (s->s3->tmp.reuse_message)
{
s->s3->tmp.reuse_message=0;
if ((mt >= 0) && (s->s3->tmp.message_type != mt))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_DTLS1_GET_MESSAGE,SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
*ok=1;
s->init_msg = s->init_buf->data + DTLS1_HM_HEADER_LENGTH;
s->init_num = (int)s->s3->tmp.message_size;
return s->init_num;
}
msg_hdr = &s->d1->r_msg_hdr;
memset(msg_hdr, 0x00, sizeof(struct hm_header_st));
again:
i = dtls1_get_message_fragment(s, st1, stn, max, ok);
if ( i == DTLS1_HM_BAD_FRAGMENT ||
i == DTLS1_HM_FRAGMENT_RETRY)
goto again;
else if ( i <= 0 && !*ok)
return i;
p = (unsigned char *)s->init_buf->data;
msg_len = msg_hdr->msg_len;
*(p++) = msg_hdr->type;
l2n3(msg_len,p);
s2n (msg_hdr->seq,p);
l2n3(0,p);
l2n3(msg_len,p);
if (s->version != DTLS1_BAD_VER) {
p -= DTLS1_HM_HEADER_LENGTH;
msg_len += DTLS1_HM_HEADER_LENGTH;
}
ssl3_finish_mac(s, p, msg_len);
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE,
p, msg_len,
s, s->msg_callback_arg);
memset(msg_hdr, 0x00, sizeof(struct hm_header_st));
if (!s->d1->listen)
s->d1->handshake_read_seq++;
s->init_msg = s->init_buf->data + DTLS1_HM_HEADER_LENGTH;
return s->init_num;
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
*ok = 0;
return -1;
}
static int dtls1_preprocess_fragment(SSL *s,struct hm_header_st *msg_hdr,int max)
{
size_t frag_off,frag_len,msg_len;
msg_len = msg_hdr->msg_len;
frag_off = msg_hdr->frag_off;
frag_len = msg_hdr->frag_len;
if ( (frag_off+frag_len) > msg_len)
{
SSLerr(SSL_F_DTLS1_PREPROCESS_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
return SSL_AD_ILLEGAL_PARAMETER;
}
if ( (frag_off+frag_len) > (unsigned long)max)
{
SSLerr(SSL_F_DTLS1_PREPROCESS_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
return SSL_AD_ILLEGAL_PARAMETER;
}
if ( s->d1->r_msg_hdr.frag_off == 0)
{
if (!BUF_MEM_grow_clean(s->init_buf,msg_len+DTLS1_HM_HEADER_LENGTH))
{
SSLerr(SSL_F_DTLS1_PREPROCESS_FRAGMENT,ERR_R_BUF_LIB);
return SSL_AD_INTERNAL_ERROR;
}
s->s3->tmp.message_size = msg_len;
s->d1->r_msg_hdr.msg_len = msg_len;
s->s3->tmp.message_type = msg_hdr->type;
s->d1->r_msg_hdr.type = msg_hdr->type;
s->d1->r_msg_hdr.seq = msg_hdr->seq;
}
else if (msg_len != s->d1->r_msg_hdr.msg_len)
{
SSLerr(SSL_F_DTLS1_PREPROCESS_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
return SSL_AD_ILLEGAL_PARAMETER;
}
return 0;
}
static int
dtls1_retrieve_buffered_fragment(SSL *s, long max, int *ok)
{
pitem *item;
hm_fragment *frag;
int al;
*ok = 0;
item = pqueue_peek(s->d1->buffered_messages);
if ( item == NULL)
return 0;
frag = (hm_fragment *)item->data;
if (frag->reassembly != NULL)
return 0;
if ( s->d1->handshake_read_seq == frag->msg_header.seq)
{
unsigned long frag_len = frag->msg_header.frag_len;
pqueue_pop(s->d1->buffered_messages);
al=dtls1_preprocess_fragment(s,&frag->msg_header,max);
if (al==0)
{
unsigned char *p = (unsigned char *)s->init_buf->data+DTLS1_HM_HEADER_LENGTH;
memcpy(&p[frag->msg_header.frag_off],
frag->fragment,frag->msg_header.frag_len);
}
dtls1_hm_fragment_free(frag);
pitem_free(item);
if (al==0)
{
*ok = 1;
return frag_len;
}
ssl3_send_alert(s,SSL3_AL_FATAL,al);
s->init_num = 0;
*ok = 0;
return -1;
}
else
return 0;
}
static int
dtls1_reassemble_fragment(SSL *s, struct hm_header_st* msg_hdr, int *ok)
{
hm_fragment *frag = NULL;
pitem *item = NULL;
int i = -1, is_complete;
unsigned char seq64be[8];
unsigned long frag_len = msg_hdr->frag_len, max_len;
if ((msg_hdr->frag_off+frag_len) > msg_hdr->msg_len)
goto err;
if (DTLS1_HM_HEADER_LENGTH + SSL3_RT_MAX_ENCRYPTED_LENGTH < s->max_cert_list)
max_len = s->max_cert_list;
else
max_len = DTLS1_HM_HEADER_LENGTH + SSL3_RT_MAX_ENCRYPTED_LENGTH;
if ((msg_hdr->frag_off+frag_len) > max_len)
goto err;
memset(seq64be,0,sizeof(seq64be));
seq64be[6] = (unsigned char) (msg_hdr->seq>>8);
seq64be[7] = (unsigned char) msg_hdr->seq;
item = pqueue_find(s->d1->buffered_messages, seq64be);
if (item == NULL)
{
frag = dtls1_hm_fragment_new(msg_hdr->msg_len, 1);
if ( frag == NULL)
goto err;
memcpy(&(frag->msg_header), msg_hdr, sizeof(*msg_hdr));
frag->msg_header.frag_len = frag->msg_header.msg_len;
frag->msg_header.frag_off = 0;
}
else
frag = (hm_fragment*) item->data;
if (frag->reassembly == NULL)
{
unsigned char devnull [256];
while (frag_len)
{
i = s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,
devnull,
frag_len>sizeof(devnull)?sizeof(devnull):frag_len,0);
if (i<=0) goto err;
frag_len -= i;
}
return DTLS1_HM_FRAGMENT_RETRY;
}
i = s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,
frag->fragment + msg_hdr->frag_off,frag_len,0);
if (i<=0 || (unsigned long)i!=frag_len)
goto err;
RSMBLY_BITMASK_MARK(frag->reassembly, (long)msg_hdr->frag_off,
(long)(msg_hdr->frag_off + frag_len));
RSMBLY_BITMASK_IS_COMPLETE(frag->reassembly, (long)msg_hdr->msg_len,
is_complete);
if (is_complete)
{
OPENSSL_free(frag->reassembly);
frag->reassembly = NULL;
}
if (item == NULL)
{
memset(seq64be,0,sizeof(seq64be));
seq64be[6] = (unsigned char)(msg_hdr->seq>>8);
seq64be[7] = (unsigned char)(msg_hdr->seq);
item = pitem_new(seq64be, frag);
if (item == NULL)
{
goto err;
i = -1;
}
pqueue_insert(s->d1->buffered_messages, item);
}
return DTLS1_HM_FRAGMENT_RETRY;
err:
if (frag != NULL) dtls1_hm_fragment_free(frag);
if (item != NULL) OPENSSL_free(item);
*ok = 0;
return i;
}
static int
dtls1_process_out_of_seq_message(SSL *s, struct hm_header_st* msg_hdr, int *ok)
{
int i=-1;
hm_fragment *frag = NULL;
pitem *item = NULL;
unsigned char seq64be[8];
unsigned long frag_len = msg_hdr->frag_len;
if ((msg_hdr->frag_off+frag_len) > msg_hdr->msg_len)
goto err;
memset(seq64be,0,sizeof(seq64be));
seq64be[6] = (unsigned char) (msg_hdr->seq>>8);
seq64be[7] = (unsigned char) msg_hdr->seq;
item = pqueue_find(s->d1->buffered_messages, seq64be);
if (item != NULL && frag_len < msg_hdr->msg_len)
item = NULL;
if (msg_hdr->seq <= s->d1->handshake_read_seq ||
msg_hdr->seq > s->d1->handshake_read_seq + 10 || item != NULL ||
(s->d1->handshake_read_seq == 0 && msg_hdr->type == SSL3_MT_FINISHED))
{
unsigned char devnull [256];
while (frag_len)
{
i = s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,
devnull,
frag_len>sizeof(devnull)?sizeof(devnull):frag_len,0);
if (i<=0) goto err;
frag_len -= i;
}
}
else
{
if (frag_len && frag_len < msg_hdr->msg_len)
return dtls1_reassemble_fragment(s, msg_hdr, ok);
frag = dtls1_hm_fragment_new(frag_len, 0);
if ( frag == NULL)
goto err;
memcpy(&(frag->msg_header), msg_hdr, sizeof(*msg_hdr));
if (frag_len)
{
i = s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,
frag->fragment,frag_len,0);
if (i<=0 || (unsigned long)i!=frag_len)
goto err;
}
memset(seq64be,0,sizeof(seq64be));
seq64be[6] = (unsigned char)(msg_hdr->seq>>8);
seq64be[7] = (unsigned char)(msg_hdr->seq);
item = pitem_new(seq64be, frag);
if ( item == NULL)
goto err;
pqueue_insert(s->d1->buffered_messages, item);
}
return DTLS1_HM_FRAGMENT_RETRY;
err:
if ( frag != NULL) dtls1_hm_fragment_free(frag);
if ( item != NULL) OPENSSL_free(item);
*ok = 0;
return i;
}
static long
dtls1_get_message_fragment(SSL *s, int st1, int stn, long max, int *ok)
{
unsigned char wire[DTLS1_HM_HEADER_LENGTH];
unsigned long len, frag_off, frag_len;
int i,al;
struct hm_header_st msg_hdr;
if ((frag_len = dtls1_retrieve_buffered_fragment(s,max,ok)) || *ok)
{
if (*ok) s->init_num = frag_len;
return frag_len;
}
i=s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,wire,
DTLS1_HM_HEADER_LENGTH, 0);
if (i <= 0)
{
s->rwstate=SSL_READING;
*ok = 0;
return i;
}
if (i != DTLS1_HM_HEADER_LENGTH)
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
dtls1_get_message_header(wire, &msg_hdr);
if (msg_hdr.seq != s->d1->handshake_read_seq && !(s->d1->listen && msg_hdr.seq == 1))
return dtls1_process_out_of_seq_message(s, &msg_hdr, ok);
len = msg_hdr.msg_len;
frag_off = msg_hdr.frag_off;
frag_len = msg_hdr.frag_len;
if (frag_len && frag_len < len)
return dtls1_reassemble_fragment(s, &msg_hdr, ok);
if (!s->server && s->d1->r_msg_hdr.frag_off == 0 &&
wire[0] == SSL3_MT_HELLO_REQUEST)
{
if (wire[1] == 0 && wire[2] == 0 && wire[3] == 0)
{
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE,
wire, DTLS1_HM_HEADER_LENGTH, s,
s->msg_callback_arg);
s->init_num = 0;
return dtls1_get_message_fragment(s, st1, stn,
max, ok);
}
else
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
}
if ((al=dtls1_preprocess_fragment(s,&msg_hdr,max)))
goto f_err;
s->state=stn;
if ( frag_len > 0)
{
unsigned char *p=(unsigned char *)s->init_buf->data+DTLS1_HM_HEADER_LENGTH;
i=s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,
&p[frag_off],frag_len,0);
if (i <= 0)
{
s->rwstate=SSL_READING;
*ok = 0;
return i;
}
}
else
i = 0;
if (i != (int)frag_len)
{
al=SSL3_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL3_AD_ILLEGAL_PARAMETER);
goto f_err;
}
*ok = 1;
s->init_num = frag_len;
return frag_len;
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
s->init_num = 0;
*ok=0;
return(-1);
}
int dtls1_send_finished(SSL *s, int a, int b, const char *sender, int slen)
{
unsigned char *p,*d;
int i;
unsigned long l;
if (s->state == a)
{
d=(unsigned char *)s->init_buf->data;
p= &(d[DTLS1_HM_HEADER_LENGTH]);
i=s->method->ssl3_enc->final_finish_mac(s,
sender,slen,s->s3->tmp.finish_md);
s->s3->tmp.finish_md_len = i;
memcpy(p, s->s3->tmp.finish_md, i);
p+=i;
l=i;
if(s->type == SSL_ST_CONNECT)
{
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_client_finished,
s->s3->tmp.finish_md, i);
s->s3->previous_client_finished_len=i;
}
else
{
OPENSSL_assert(i <= EVP_MAX_MD_SIZE);
memcpy(s->s3->previous_server_finished,
s->s3->tmp.finish_md, i);
s->s3->previous_server_finished_len=i;
}
#ifdef OPENSSL_SYS_WIN16
l&=0xffff;
#endif
d = dtls1_set_message_header(s, d, SSL3_MT_FINISHED, l, 0, l);
s->init_num=(int)l+DTLS1_HM_HEADER_LENGTH;
s->init_off=0;
dtls1_buffer_message(s, 0);
s->state=b;
}
return(dtls1_do_write(s,SSL3_RT_HANDSHAKE));
}
int dtls1_send_change_cipher_spec(SSL *s, int a, int b)
{
unsigned char *p;
if (s->state == a)
{
p=(unsigned char *)s->init_buf->data;
*p++=SSL3_MT_CCS;
s->d1->handshake_write_seq = s->d1->next_handshake_write_seq;
s->init_num=DTLS1_CCS_HEADER_LENGTH;
if (s->version == DTLS1_BAD_VER) {
s->d1->next_handshake_write_seq++;
s2n(s->d1->handshake_write_seq,p);
s->init_num+=2;
}
s->init_off=0;
dtls1_set_message_header_int(s, SSL3_MT_CCS, 0,
s->d1->handshake_write_seq, 0, 0);
dtls1_buffer_message(s, 1);
s->state=b;
}
return(dtls1_do_write(s,SSL3_RT_CHANGE_CIPHER_SPEC));
}
static int dtls1_add_cert_to_buf(BUF_MEM *buf, unsigned long *l, X509 *x)
{
int n;
unsigned char *p;
n=i2d_X509(x,NULL);
if (!BUF_MEM_grow_clean(buf,(int)(n+(*l)+3)))
{
SSLerr(SSL_F_DTLS1_ADD_CERT_TO_BUF,ERR_R_BUF_LIB);
return 0;
}
p=(unsigned char *)&(buf->data[*l]);
l2n3(n,p);
i2d_X509(x,&p);
*l+=n+3;
return 1;
}
unsigned long dtls1_output_cert_chain(SSL *s, X509 *x)
{
unsigned char *p;
int i;
unsigned long l= 3 + DTLS1_HM_HEADER_LENGTH;
BUF_MEM *buf;
buf=s->init_buf;
if (!BUF_MEM_grow_clean(buf,10))
{
SSLerr(SSL_F_DTLS1_OUTPUT_CERT_CHAIN,ERR_R_BUF_LIB);
return(0);
}
if (x != NULL)
{
X509_STORE_CTX xs_ctx;
if (!X509_STORE_CTX_init(&xs_ctx,s->ctx->cert_store,x,NULL))
{
SSLerr(SSL_F_DTLS1_OUTPUT_CERT_CHAIN,ERR_R_X509_LIB);
return(0);
}
X509_verify_cert(&xs_ctx);
ERR_clear_error();
for (i=0; i < sk_X509_num(xs_ctx.chain); i++)
{
x = sk_X509_value(xs_ctx.chain, i);
if (!dtls1_add_cert_to_buf(buf, &l, x))
{
X509_STORE_CTX_cleanup(&xs_ctx);
return 0;
}
}
X509_STORE_CTX_cleanup(&xs_ctx);
}
for (i=0; i<sk_X509_num(s->ctx->extra_certs); i++)
{
x=sk_X509_value(s->ctx->extra_certs,i);
if (!dtls1_add_cert_to_buf(buf, &l, x))
return 0;
}
l-= (3 + DTLS1_HM_HEADER_LENGTH);
p=(unsigned char *)&(buf->data[DTLS1_HM_HEADER_LENGTH]);
l2n3(l,p);
l+=3;
p=(unsigned char *)&(buf->data[0]);
p = dtls1_set_message_header(s, p, SSL3_MT_CERTIFICATE, l, 0, l);
l+=DTLS1_HM_HEADER_LENGTH;
return(l);
}
int dtls1_read_failed(SSL *s, int code)
{
if ( code > 0)
{
fprintf( stderr, "invalid state reached %s:%d", __FILE__, __LINE__);
return 1;
}
if (!dtls1_is_timer_expired(s))
{
return code;
}
#ifndef OPENSSL_NO_HEARTBEATS
if (!SSL_in_init(s) && !s->tlsext_hb_pending)
#else
if (!SSL_in_init(s))
#endif
{
BIO_set_flags(SSL_get_rbio(s), BIO_FLAGS_READ);
return code;
}
#if 0
item = pqueue_peek(state->rcvd_records);
if ( item )
{
}
else
#endif
#if 0
if ( state->timeout.read_timeouts >= DTLS1_TMO_READ_COUNT)
ssl3_send_alert(s,SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
return dtls1_handle_timeout(s);
}
int
dtls1_get_queue_priority(unsigned short seq, int is_ccs)
{
return seq * 2 - is_ccs;
}
int
dtls1_retransmit_buffered_messages(SSL *s)
{
pqueue sent = s->d1->sent_messages;
piterator iter;
pitem *item;
hm_fragment *frag;
int found = 0;
iter = pqueue_iterator(sent);
for ( item = pqueue_next(&iter); item != NULL; item = pqueue_next(&iter))
{
frag = (hm_fragment *)item->data;
if ( dtls1_retransmit_message(s,
(unsigned short)dtls1_get_queue_priority(frag->msg_header.seq, frag->msg_header.is_ccs),
0, &found) <= 0 && found)
{
fprintf(stderr, "dtls1_retransmit_message() failed\n");
return -1;
}
}
return 1;
}
int
dtls1_buffer_message(SSL *s, int is_ccs)
{
pitem *item;
hm_fragment *frag;
unsigned char seq64be[8];
OPENSSL_assert(s->init_off == 0);
frag = dtls1_hm_fragment_new(s->init_num, 0);
memcpy(frag->fragment, s->init_buf->data, s->init_num);
if ( is_ccs)
{
OPENSSL_assert(s->d1->w_msg_hdr.msg_len +
((s->version==DTLS1_VERSION)?DTLS1_CCS_HEADER_LENGTH:3) == (unsigned int)s->init_num);
}
else
{
OPENSSL_assert(s->d1->w_msg_hdr.msg_len +
DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num);
}
frag->msg_header.msg_len = s->d1->w_msg_hdr.msg_len;
frag->msg_header.seq = s->d1->w_msg_hdr.seq;
frag->msg_header.type = s->d1->w_msg_hdr.type;
frag->msg_header.frag_off = 0;
frag->msg_header.frag_len = s->d1->w_msg_hdr.msg_len;
frag->msg_header.is_ccs = is_ccs;
frag->msg_header.saved_retransmit_state.enc_write_ctx = s->enc_write_ctx;
frag->msg_header.saved_retransmit_state.write_hash = s->write_hash;
frag->msg_header.saved_retransmit_state.compress = s->compress;
frag->msg_header.saved_retransmit_state.session = s->session;
frag->msg_header.saved_retransmit_state.epoch = s->d1->w_epoch;
memset(seq64be,0,sizeof(seq64be));
seq64be[6] = (unsigned char)(dtls1_get_queue_priority(frag->msg_header.seq,
frag->msg_header.is_ccs)>>8);
seq64be[7] = (unsigned char)(dtls1_get_queue_priority(frag->msg_header.seq,
frag->msg_header.is_ccs));
item = pitem_new(seq64be, frag);
if ( item == NULL)
{
dtls1_hm_fragment_free(frag);
return 0;
}
#if 0
fprintf( stderr, "buffered messge: \ttype = %xx\n", msg_buf->type);
fprintf( stderr, "\t\t\t\t\tlen = %d\n", msg_buf->len);
fprintf( stderr, "\t\t\t\t\tseq_num = %d\n", msg_buf->seq_num);
#endif
pqueue_insert(s->d1->sent_messages, item);
return 1;
}
int
dtls1_retransmit_message(SSL *s, unsigned short seq, unsigned long frag_off,
int *found)
{
int ret;
pitem *item;
hm_fragment *frag ;
unsigned long header_length;
unsigned char seq64be[8];
struct dtls1_retransmit_state saved_state;
unsigned char save_write_sequence[8];
memset(seq64be,0,sizeof(seq64be));
seq64be[6] = (unsigned char)(seq>>8);
seq64be[7] = (unsigned char)seq;
item = pqueue_find(s->d1->sent_messages, seq64be);
if ( item == NULL)
{
fprintf(stderr, "retransmit: message %d non-existant\n", seq);
*found = 0;
return 0;
}
*found = 1;
frag = (hm_fragment *)item->data;
if ( frag->msg_header.is_ccs)
header_length = DTLS1_CCS_HEADER_LENGTH;
else
header_length = DTLS1_HM_HEADER_LENGTH;
memcpy(s->init_buf->data, frag->fragment,
frag->msg_header.msg_len + header_length);
s->init_num = frag->msg_header.msg_len + header_length;
dtls1_set_message_header_int(s, frag->msg_header.type,
frag->msg_header.msg_len, frag->msg_header.seq, 0,
frag->msg_header.frag_len);
saved_state.enc_write_ctx = s->enc_write_ctx;
saved_state.write_hash = s->write_hash;
saved_state.compress = s->compress;
saved_state.session = s->session;
saved_state.epoch = s->d1->w_epoch;
saved_state.epoch = s->d1->w_epoch;
s->d1->retransmitting = 1;
s->enc_write_ctx = frag->msg_header.saved_retransmit_state.enc_write_ctx;
s->write_hash = frag->msg_header.saved_retransmit_state.write_hash;
s->compress = frag->msg_header.saved_retransmit_state.compress;
s->session = frag->msg_header.saved_retransmit_state.session;
s->d1->w_epoch = frag->msg_header.saved_retransmit_state.epoch;
if (frag->msg_header.saved_retransmit_state.epoch == saved_state.epoch - 1)
{
memcpy(save_write_sequence, s->s3->write_sequence, sizeof(s->s3->write_sequence));
memcpy(s->s3->write_sequence, s->d1->last_write_sequence, sizeof(s->s3->write_sequence));
}
ret = dtls1_do_write(s, frag->msg_header.is_ccs ?
SSL3_RT_CHANGE_CIPHER_SPEC : SSL3_RT_HANDSHAKE);
s->enc_write_ctx = saved_state.enc_write_ctx;
s->write_hash = saved_state.write_hash;
s->compress = saved_state.compress;
s->session = saved_state.session;
s->d1->w_epoch = saved_state.epoch;
if (frag->msg_header.saved_retransmit_state.epoch == saved_state.epoch - 1)
{
memcpy(s->d1->last_write_sequence, s->s3->write_sequence, sizeof(s->s3->write_sequence));
memcpy(s->s3->write_sequence, save_write_sequence, sizeof(s->s3->write_sequence));
}
s->d1->retransmitting = 0;
(void)BIO_flush(SSL_get_wbio(s));
return ret;
}
void
dtls1_clear_record_buffer(SSL *s)
{
pitem *item;
for(item = pqueue_pop(s->d1->sent_messages);
item != NULL; item = pqueue_pop(s->d1->sent_messages))
{
dtls1_hm_fragment_free((hm_fragment *)item->data);
pitem_free(item);
}
}
unsigned char *
dtls1_set_message_header(SSL *s, unsigned char *p, unsigned char mt,
unsigned long len, unsigned long frag_off, unsigned long frag_len)
{
if (frag_off == 0 && !s->d1->listen)
{
s->d1->handshake_write_seq = s->d1->next_handshake_write_seq;
s->d1->next_handshake_write_seq++;
}
dtls1_set_message_header_int(s, mt, len, s->d1->handshake_write_seq,
frag_off, frag_len);
return p += DTLS1_HM_HEADER_LENGTH;
}
static void
dtls1_set_message_header_int(SSL *s, unsigned char mt,
unsigned long len, unsigned short seq_num, unsigned long frag_off,
unsigned long frag_len)
{
struct hm_header_st *msg_hdr = &s->d1->w_msg_hdr;
msg_hdr->type = mt;
msg_hdr->msg_len = len;
msg_hdr->seq = seq_num;
msg_hdr->frag_off = frag_off;
msg_hdr->frag_len = frag_len;
}
static void
dtls1_fix_message_header(SSL *s, unsigned long frag_off,
unsigned long frag_len)
{
struct hm_header_st *msg_hdr = &s->d1->w_msg_hdr;
msg_hdr->frag_off = frag_off;
msg_hdr->frag_len = frag_len;
}
static unsigned char *
dtls1_write_message_header(SSL *s, unsigned char *p)
{
struct hm_header_st *msg_hdr = &s->d1->w_msg_hdr;
*p++ = msg_hdr->type;
l2n3(msg_hdr->msg_len, p);
s2n(msg_hdr->seq, p);
l2n3(msg_hdr->frag_off, p);
l2n3(msg_hdr->frag_len, p);
return p;
}
unsigned int
dtls1_min_mtu(void)
{
return (g_probable_mtu[(sizeof(g_probable_mtu) /
sizeof(g_probable_mtu[0])) - 1]);
}
static unsigned int
dtls1_guess_mtu(unsigned int curr_mtu)
{
unsigned int i;
if ( curr_mtu == 0 )
return g_probable_mtu[0] ;
for ( i = 0; i < sizeof(g_probable_mtu)/sizeof(g_probable_mtu[0]); i++)
if ( curr_mtu > g_probable_mtu[i])
return g_probable_mtu[i];
return curr_mtu;
}
void
dtls1_get_message_header(unsigned char *data, struct hm_header_st *msg_hdr)
{
memset(msg_hdr, 0x00, sizeof(struct hm_header_st));
msg_hdr->type = *(data++);
n2l3(data, msg_hdr->msg_len);
n2s(data, msg_hdr->seq);
n2l3(data, msg_hdr->frag_off);
n2l3(data, msg_hdr->frag_len);
}
void
dtls1_get_ccs_header(unsigned char *data, struct ccs_header_st *ccs_hdr)
{
memset(ccs_hdr, 0x00, sizeof(struct ccs_header_st));
ccs_hdr->type = *(data++);
}
int dtls1_shutdown(SSL *s)
{
int ret;
#ifndef OPENSSL_NO_SCTP
if (BIO_dgram_is_sctp(SSL_get_wbio(s)) &&
!(s->shutdown & SSL_SENT_SHUTDOWN))
{
ret = BIO_dgram_sctp_wait_for_dry(SSL_get_wbio(s));
if (ret < 0) return -1;
if (ret == 0)
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_SAVE_SHUTDOWN, 1, NULL);
}
#endif
ret = ssl3_shutdown(s);
#ifndef OPENSSL_NO_SCTP
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_SCTP_SAVE_SHUTDOWN, 0, NULL);
#endif
return ret;
}
int
dtls1_process_heartbeat(SSL *s)
{
unsigned char *p = &s->s3->rrec.data[0], *pl;
unsigned short hbtype;
unsigned int payload;
unsigned int padding = 16;
hbtype = *p++;
n2s(p, payload);
pl = p;
if (s->msg_callback)
s->msg_callback(0, s->version, TLS1_RT_HEARTBEAT,
&s->s3->rrec.data[0], s->s3->rrec.length,
s, s->msg_callback_arg);
if (hbtype == TLS1_HB_REQUEST)
{
unsigned char *buffer, *bp;
int r;
buffer = OPENSSL_malloc(1 + 2 + payload + padding);
bp = buffer;
*bp++ = TLS1_HB_RESPONSE;
s2n(payload, bp);
memcpy(bp, pl, payload);
bp += payload;
RAND_pseudo_bytes(bp, padding);
r = dtls1_write_bytes(s, TLS1_RT_HEARTBEAT, buffer, 3 + payload + padding);
if (r >= 0 && s->msg_callback)
s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
buffer, 3 + payload + padding,
s, s->msg_callback_arg);
OPENSSL_free(buffer);
if (r < 0)
return r;
}
else if (hbtype == TLS1_HB_RESPONSE)
{
unsigned int seq;
n2s(pl, seq);
if (payload == 18 && seq == s->tlsext_hb_seq)
{
dtls1_stop_timer(s);
s->tlsext_hb_seq++;
s->tlsext_hb_pending = 0;
}
}
return 0;
}
int
dtls1_heartbeat(SSL *s)
{
unsigned char *buf, *p;
int ret;
unsigned int payload = 18;
unsigned int padding = 16;
if (!(s->tlsext_heartbeat & SSL_TLSEXT_HB_ENABLED) ||
s->tlsext_heartbeat & SSL_TLSEXT_HB_DONT_SEND_REQUESTS)
{
SSLerr(SSL_F_DTLS1_HEARTBEAT,SSL_R_TLS_HEARTBEAT_PEER_DOESNT_ACCEPT);
return -1;
}
if (s->tlsext_hb_pending)
{
SSLerr(SSL_F_DTLS1_HEARTBEAT,SSL_R_TLS_HEARTBEAT_PENDING);
return -1;
}
if (SSL_in_init(s) || s->in_handshake)
{
SSLerr(SSL_F_DTLS1_HEARTBEAT,SSL_R_UNEXPECTED_MESSAGE);
return -1;
}
OPENSSL_assert(payload + padding <= 16381);
buf = OPENSSL_malloc(1 + 2 + payload + padding);
p = buf;
*p++ = TLS1_HB_REQUEST;
s2n(payload, p);
s2n(s->tlsext_hb_seq, p);
RAND_pseudo_bytes(p, 16);
p += 16;
RAND_pseudo_bytes(p, padding);
ret = dtls1_write_bytes(s, TLS1_RT_HEARTBEAT, buf, 3 + payload + padding);
if (ret >= 0)
{
if (s->msg_callback)
s->msg_callback(1, s->version, TLS1_RT_HEARTBEAT,
buf, 3 + payload + padding,
s, s->msg_callback_arg);
dtls1_start_timer(s);
s->tlsext_hb_pending = 1;
}
OPENSSL_free(buf);
return ret;
}
