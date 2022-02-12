static hm_fragment *
dtls1_hm_fragment_new(unsigned long frag_len)
{
hm_fragment *frag = NULL;
unsigned char *buf = NULL;
frag = (hm_fragment *)OPENSSL_malloc(sizeof(hm_fragment));
if ( frag == NULL)
return NULL;
buf = (unsigned char *)OPENSSL_malloc(frag_len
+ DTLS1_HM_HEADER_LENGTH);
if ( buf == NULL)
{
OPENSSL_free(frag);
return NULL;
}
frag->fragment = buf;
return frag;
}
static void
dtls1_hm_fragment_free(hm_fragment *frag)
{
OPENSSL_free(frag->fragment);
OPENSSL_free(frag);
}
int dtls1_do_write(SSL *s, int type)
{
int ret;
int curr_mtu;
unsigned int len, frag_off;
if ( ! (SSL_get_options(s) & SSL_OP_NO_QUERY_MTU))
{
s->d1->mtu =
BIO_ctrl(SSL_get_wbio(s), BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
if ( s->d1->mtu < dtls1_min_mtu())
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
OPENSSL_assert(mtu > 0);
#endif
if ( s->init_off == 0 && type == SSL3_RT_HANDSHAKE)
OPENSSL_assert(s->init_num ==
(int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH);
frag_off = 0;
while( s->init_num)
{
curr_mtu = s->d1->mtu - BIO_wpending(SSL_get_wbio(s)) -
DTLS1_RT_HEADER_LENGTH;
if ( curr_mtu <= DTLS1_HM_HEADER_LENGTH)
{
ret = BIO_flush(SSL_get_wbio(s));
if ( ret <= 0)
return ret;
curr_mtu = s->d1->mtu - DTLS1_RT_HEADER_LENGTH;
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
BIO_CTRL_DGRAM_MTU_EXCEEDED, 0, NULL))
s->d1->mtu = BIO_ctrl(SSL_get_wbio(s),
BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
else
return(-1);
}
else
{
OPENSSL_assert(len == (unsigned int)ret);
if (type == SSL3_RT_HANDSHAKE && ! s->d1->retransmitting)
ssl3_finish_mac(s,
(unsigned char *)&s->init_buf->data[s->init_off +
DTLS1_HM_HEADER_LENGTH], ret - DTLS1_HM_HEADER_LENGTH);
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
do
{
if ( s->d1->r_msg_hdr.frag_off == 0)
{
memset(&(s->d1->r_msg_hdr), 0x00, sizeof(struct hm_header_st));
}
i = dtls1_get_message_fragment(s, st1, stn, max, ok);
if ( i == DTLS1_HM_BAD_FRAGMENT ||
i == DTLS1_HM_FRAGMENT_RETRY)
continue;
else if ( i <= 0 && !*ok)
return i;
if (s->d1->r_msg_hdr.msg_len == (unsigned int)s->init_num - DTLS1_HM_HEADER_LENGTH)
{
memset(&(s->d1->r_msg_hdr), 0x00, sizeof(struct hm_header_st));
s->d1->handshake_read_seq++;
dtls1_clear_record_buffer(s);
s->init_msg = s->init_buf->data + DTLS1_HM_HEADER_LENGTH;
return s->init_num - DTLS1_HM_HEADER_LENGTH;
}
else
s->d1->r_msg_hdr.frag_off = i;
} while(1) ;
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
*ok = 0;
return -1;
}
static int
dtls1_retrieve_buffered_fragment(SSL *s, unsigned long *copied)
{
pitem *item;
hm_fragment *frag;
unsigned long overlap;
unsigned char *p;
item = pqueue_peek(s->d1->buffered_messages);
if ( item == NULL)
return 0;
frag = (hm_fragment *)item->data;
if ( s->d1->handshake_read_seq == frag->msg_header.seq &&
frag->msg_header.frag_off <= (unsigned int)s->init_num - DTLS1_HM_HEADER_LENGTH)
{
pqueue_pop(s->d1->buffered_messages);
overlap = s->init_num - DTLS1_HM_HEADER_LENGTH
- frag->msg_header.frag_off;
p = frag->fragment;
memcpy(&s->init_buf->data[s->init_num],
p + DTLS1_HM_HEADER_LENGTH + overlap,
frag->msg_header.frag_len - overlap);
OPENSSL_free(frag->fragment);
OPENSSL_free(frag);
pitem_free(item);
*copied = frag->msg_header.frag_len - overlap;
return *copied;
}
else
return 0;
}
static int
dtls1_buffer_handshake_fragment(SSL *s, struct hm_header_st* msg_hdr)
{
hm_fragment *frag = NULL;
pitem *item = NULL;
PQ_64BIT seq64;
frag = dtls1_hm_fragment_new(msg_hdr->frag_len);
if ( frag == NULL)
goto err;
memcpy(frag->fragment, &(s->init_buf->data[s->init_num]),
msg_hdr->frag_len + DTLS1_HM_HEADER_LENGTH);
memcpy(&(frag->msg_header), msg_hdr, sizeof(*msg_hdr));
pq_64bit_init(&seq64);
pq_64bit_assign_word(&seq64, msg_hdr->seq);
item = pitem_new(seq64, frag);
if ( item == NULL)
goto err;
pq_64bit_free(&seq64);
pqueue_insert(s->d1->buffered_messages, item);
return 1;
err:
if ( frag != NULL) dtls1_hm_fragment_free(frag);
if ( item != NULL) OPENSSL_free(item);
return 0;
}
static void
dtls1_process_handshake_fragment(SSL *s, int frag_len)
{
unsigned char *p;
p = (unsigned char *)s->init_buf->data;
ssl3_finish_mac(s, &p[s->init_num - frag_len], frag_len);
}
static int
dtls1_process_out_of_seq_message(SSL *s, struct hm_header_st *msg_hdr, int *ok)
{
int i;
unsigned char *p;
if ( (int)msg_hdr->frag_len && !BUF_MEM_grow_clean(s->init_buf,
(int)msg_hdr->frag_len + DTLS1_HM_HEADER_LENGTH + s->init_num))
{
SSLerr(SSL_F_DTLS1_PROCESS_OUT_OF_SEQ_MESSAGE,ERR_R_BUF_LIB);
goto err;
}
p = (unsigned char *)s->init_buf->data;
if ( msg_hdr->frag_len > 0)
{
i=s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,
&p[s->init_num],
msg_hdr->frag_len,0);
if (i <= 0)
{
*ok = 0;
return i;
}
}
if ( msg_hdr->seq > s->d1->handshake_read_seq)
dtls1_buffer_handshake_fragment(s, msg_hdr);
else
OPENSSL_assert(msg_hdr->seq < s->d1->handshake_read_seq);
return DTLS1_HM_FRAGMENT_RETRY;
err:
*ok = 0;
return -1;
}
static long
dtls1_get_message_fragment(SSL *s, int st1, int stn, long max, int *ok)
{
unsigned char *p;
unsigned long l, frag_off, frag_len;
int i,al;
struct hm_header_st msg_hdr;
unsigned long overlap;
if (dtls1_retrieve_buffered_fragment(s, &l))
{
dtls1_process_handshake_fragment(s, l);
s->init_msg = s->init_buf->data + DTLS1_HM_HEADER_LENGTH;
s->state = stn;
return 1;
}
p = (unsigned char *)s->init_buf->data;
i=s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,&p[s->init_num],
DTLS1_HM_HEADER_LENGTH, 0);
if (i <= 0)
{
s->rwstate=SSL_READING;
*ok = 0;
return i;
}
OPENSSL_assert(i == DTLS1_HM_HEADER_LENGTH);
p += s->init_num;
dtls1_get_message_header(p, &msg_hdr);
if ( msg_hdr.seq != s->d1->handshake_read_seq)
return dtls1_process_out_of_seq_message(s, &msg_hdr, ok);
l = msg_hdr.msg_len;
frag_off = msg_hdr.frag_off;
frag_len = msg_hdr.frag_len;
if ( frag_off + frag_len > l)
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if (!s->server && s->d1->r_msg_hdr.frag_off == 0 &&
p[0] == SSL3_MT_HELLO_REQUEST)
{
if (p[1] == 0 && p[2] == 0 &&p[3] == 0)
{
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE,
p, DTLS1_HM_HEADER_LENGTH, s,
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
s->init_num += i;
if ( s->d1->r_msg_hdr.frag_off == 0)
{
if (l > (INT_MAX-DTLS1_HM_HEADER_LENGTH))
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if (l && !BUF_MEM_grow_clean(s->init_buf,(int)l
+ DTLS1_HM_HEADER_LENGTH))
{
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,ERR_R_BUF_LIB);
goto err;
}
if ( l > (unsigned long)max)
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
s->s3->tmp.message_size=l;
}
if ( frag_len > (unsigned long)max)
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if ( frag_len + s->init_num > (INT_MAX - DTLS1_HM_HEADER_LENGTH))
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if ( frag_len & !BUF_MEM_grow_clean(s->init_buf, (int)frag_len
+ DTLS1_HM_HEADER_LENGTH + s->init_num))
{
SSLerr(SSL_F_DTLS1_GET_MESSAGE_FRAGMENT,ERR_R_BUF_LIB);
goto err;
}
if ( s->d1->r_msg_hdr.frag_off == 0)
{
s->s3->tmp.message_type = msg_hdr.type;
s->d1->r_msg_hdr.type = msg_hdr.type;
s->d1->r_msg_hdr.msg_len = l;
}
s->state=stn;
p = (unsigned char *)s->init_buf->data;
if ( frag_len > 0)
{
i=s->method->ssl_read_bytes(s,SSL3_RT_HANDSHAKE,
&p[s->init_num],
frag_len,0);
if (i <= 0)
{
s->rwstate=SSL_READING;
*ok = 0;
return i;
}
}
else
i = 0;
OPENSSL_assert(i == (int)frag_len);
#if 0
if ( msg_hdr.seq > s->d1->handshake_read_seq ||
frag_off > s->init_num - DTLS1_HM_HEADER_LENGTH)
{
dtls1_buffer_handshake_fragment(s, &msg_hdr);
return DTLS1_HM_FRAGMENT_RETRY;
}
if ( msg_hdr.seq < s->d1->handshake_read_seq ||
frag_off + frag_len < s->init_num - DTLS1_HM_HEADER_LENGTH)
{
s->init_num -= DTLS1_HM_HEADER_LENGTH;
return DTLS1_HM_FRAGMENT_RETRY;
}
#endif
overlap = (s->init_num - DTLS1_HM_HEADER_LENGTH) - frag_off;
if ( s->init_num > DTLS1_HM_HEADER_LENGTH)
{
memmove(&(s->init_buf->data[s->init_num]),
&(s->init_buf->data[s->init_num + DTLS1_HM_HEADER_LENGTH + overlap]),
frag_len - overlap);
s->init_num += frag_len - overlap;
}
else
s->init_num += frag_len;
dtls1_process_handshake_fragment(s, frag_len - overlap);
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE, s->init_buf->data,
(size_t)s->init_num, s,
s->msg_callback_arg);
*ok=1;
return s->init_num;
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
s->init_num = 0;
err:
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
&(s->s3->finish_dgst1),
&(s->s3->finish_dgst2),
sender,slen,s->s3->tmp.finish_md);
s->s3->tmp.finish_md_len = i;
memcpy(p, s->s3->tmp.finish_md, i);
p+=i;
l=i;
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
s->d1->next_handshake_write_seq++;
s2n(s->d1->handshake_write_seq,p);
s->init_num=DTLS1_CCS_HEADER_LENGTH;
s->init_off=0;
dtls1_set_message_header_int(s, SSL3_MT_CCS, 0,
s->d1->handshake_write_seq, 0, 0);
dtls1_buffer_message(s, 1);
s->state=b;
}
return(dtls1_do_write(s,SSL3_RT_CHANGE_CIPHER_SPEC));
}
unsigned long dtls1_output_cert_chain(SSL *s, X509 *x)
{
unsigned char *p;
int n,i;
unsigned long l= 3 + DTLS1_HM_HEADER_LENGTH;
BUF_MEM *buf;
X509_STORE_CTX xs_ctx;
X509_OBJECT obj;
buf=s->init_buf;
if (!BUF_MEM_grow_clean(buf,10))
{
SSLerr(SSL_F_DTLS1_OUTPUT_CERT_CHAIN,ERR_R_BUF_LIB);
return(0);
}
if (x != NULL)
{
if(!X509_STORE_CTX_init(&xs_ctx,s->ctx->cert_store,NULL,NULL))
{
SSLerr(SSL_F_DTLS1_OUTPUT_CERT_CHAIN,ERR_R_X509_LIB);
return(0);
}
for (;;)
{
n=i2d_X509(x,NULL);
if (!BUF_MEM_grow_clean(buf,(int)(n+l+3)))
{
SSLerr(SSL_F_DTLS1_OUTPUT_CERT_CHAIN,ERR_R_BUF_LIB);
return(0);
}
p=(unsigned char *)&(buf->data[l]);
l2n3(n,p);
i2d_X509(x,&p);
l+=n+3;
if (X509_NAME_cmp(X509_get_subject_name(x),
X509_get_issuer_name(x)) == 0) break;
i=X509_STORE_get_by_subject(&xs_ctx,X509_LU_X509,
X509_get_issuer_name(x),&obj);
if (i <= 0) break;
x=obj.data.x509;
X509_free(x);
}
X509_STORE_CTX_cleanup(&xs_ctx);
}
if (s->ctx->extra_certs != NULL)
for (i=0; i<sk_X509_num(s->ctx->extra_certs); i++)
{
x=sk_X509_value(s->ctx->extra_certs,i);
n=i2d_X509(x,NULL);
if (!BUF_MEM_grow_clean(buf,(int)(n+l+3)))
{
SSLerr(SSL_F_DTLS1_OUTPUT_CERT_CHAIN,ERR_R_BUF_LIB);
return(0);
}
p=(unsigned char *)&(buf->data[l]);
l2n3(n,p);
i2d_X509(x,&p);
l+=n+3;
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
DTLS1_STATE *state;
BIO *bio;
int send_alert = 0;
if ( code > 0)
{
fprintf( stderr, "invalid state reached %s:%d", __FILE__, __LINE__);
return 1;
}
bio = SSL_get_rbio(s);
if ( ! BIO_dgram_recv_timedout(bio))
{
return code;
}
if ( ! SSL_in_init(s))
{
BIO_set_flags(SSL_get_rbio(s), BIO_FLAGS_READ);
return code;
}
state = s->d1;
state->timeout.num_alerts++;
if ( state->timeout.num_alerts > DTLS1_TMO_ALERT_COUNT)
{
SSLerr(SSL_F_DTLS1_READ_FAILED,SSL_R_READ_TIMEOUT_EXPIRED);
return 0;
}
state->timeout.read_timeouts++;
if ( state->timeout.read_timeouts > DTLS1_TMO_READ_COUNT)
{
send_alert = 1;
state->timeout.read_timeouts = 1;
}
#if 0
item = pqueue_peek(state->rcvd_records);
if ( item )
{
}
else
#endif
#if 0
if ( send_alert)
ssl3_send_alert(s,SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
return dtls1_retransmit_buffered_messages(s) ;
}
static int
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
if ( dtls1_retransmit_message(s, frag->msg_header.seq, 0, &found) <= 0 &&
found)
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
PQ_64BIT seq64;
OPENSSL_assert(s->init_off == 0);
frag = dtls1_hm_fragment_new(s->init_num);
memcpy(frag->fragment, s->init_buf->data, s->init_num);
if ( is_ccs)
{
OPENSSL_assert(s->d1->w_msg_hdr.msg_len +
DTLS1_CCS_HEADER_LENGTH == (unsigned int)s->init_num);
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
pq_64bit_init(&seq64);
pq_64bit_assign_word(&seq64, frag->msg_header.seq);
item = pitem_new(seq64, frag);
pq_64bit_free(&seq64);
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
PQ_64BIT seq64;
pq_64bit_init(&seq64);
pq_64bit_assign_word(&seq64, seq);
item = pqueue_find(s->d1->sent_messages, seq64);
pq_64bit_free(&seq64);
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
s->d1->retransmitting = 1;
ret = dtls1_do_write(s, frag->msg_header.is_ccs ?
SSL3_RT_CHANGE_CIPHER_SPEC : SSL3_RT_HANDSHAKE);
s->d1->retransmitting = 0;
BIO_flush(SSL_get_wbio(s));
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
if ( frag_off == 0)
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
static unsigned int
dtls1_min_mtu(void)
{
return
g_probable_mtu[(sizeof(g_probable_mtu) /
sizeof(g_probable_mtu[0])) - 1];
}
static unsigned int
dtls1_guess_mtu(unsigned int curr_mtu)
{
int i;
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
n2s(data, ccs_hdr->seq);
}
