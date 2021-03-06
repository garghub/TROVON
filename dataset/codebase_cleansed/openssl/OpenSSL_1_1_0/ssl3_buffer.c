void SSL3_BUFFER_set_data(SSL3_BUFFER *b, const unsigned char *d, int n)
{
if (d != NULL)
memcpy(b->buf, d, n);
b->left = n;
b->offset = 0;
}
void SSL3_BUFFER_clear(SSL3_BUFFER *b)
{
b->offset = 0;
b->left = 0;
}
void SSL3_BUFFER_release(SSL3_BUFFER *b)
{
OPENSSL_free(b->buf);
b->buf = NULL;
}
int ssl3_setup_read_buffer(SSL *s)
{
unsigned char *p;
size_t len, align = 0, headerlen;
SSL3_BUFFER *b;
b = RECORD_LAYER_get_rbuf(&s->rlayer);
if (SSL_IS_DTLS(s))
headerlen = DTLS1_RT_HEADER_LENGTH;
else
headerlen = SSL3_RT_HEADER_LENGTH;
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
align = (-SSL3_RT_HEADER_LENGTH) & (SSL3_ALIGN_PAYLOAD - 1);
#endif
if (b->buf == NULL) {
len = SSL3_RT_MAX_PLAIN_LENGTH
+ SSL3_RT_MAX_ENCRYPTED_OVERHEAD + headerlen + align;
#ifndef OPENSSL_NO_COMP
if (ssl_allow_compression(s))
len += SSL3_RT_MAX_COMPRESSED_OVERHEAD;
#endif
if (b->default_len > len)
len = b->default_len;
if ((p = OPENSSL_malloc(len)) == NULL)
goto err;
b->buf = p;
b->len = len;
}
RECORD_LAYER_set_packet(&s->rlayer, &(b->buf[0]));
return 1;
err:
SSLerr(SSL_F_SSL3_SETUP_READ_BUFFER, ERR_R_MALLOC_FAILURE);
return 0;
}
int ssl3_setup_write_buffer(SSL *s, unsigned int numwpipes, size_t len)
{
unsigned char *p;
size_t align = 0, headerlen;
SSL3_BUFFER *wb;
unsigned int currpipe;
s->rlayer.numwpipes = numwpipes;
if (len == 0) {
if (SSL_IS_DTLS(s))
headerlen = DTLS1_RT_HEADER_LENGTH + 1;
else
headerlen = SSL3_RT_HEADER_LENGTH;
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
align = (-SSL3_RT_HEADER_LENGTH) & (SSL3_ALIGN_PAYLOAD - 1);
#endif
len = s->max_send_fragment
+ SSL3_RT_SEND_MAX_ENCRYPTED_OVERHEAD + headerlen + align;
#ifndef OPENSSL_NO_COMP
if (ssl_allow_compression(s))
len += SSL3_RT_MAX_COMPRESSED_OVERHEAD;
#endif
if (!(s->options & SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS))
len += headerlen + align + SSL3_RT_SEND_MAX_ENCRYPTED_OVERHEAD;
}
wb = RECORD_LAYER_get_wbuf(&s->rlayer);
for (currpipe = 0; currpipe < numwpipes; currpipe++) {
if (wb[currpipe].buf == NULL) {
if ((p = OPENSSL_malloc(len)) == NULL) {
s->rlayer.numwpipes = currpipe;
goto err;
}
wb[currpipe].buf = p;
wb[currpipe].len = len;
}
}
return 1;
err:
SSLerr(SSL_F_SSL3_SETUP_WRITE_BUFFER, ERR_R_MALLOC_FAILURE);
return 0;
}
int ssl3_setup_buffers(SSL *s)
{
if (!ssl3_setup_read_buffer(s))
return 0;
if (!ssl3_setup_write_buffer(s, 1, 0))
return 0;
return 1;
}
int ssl3_release_write_buffer(SSL *s)
{
SSL3_BUFFER *wb;
unsigned int pipes;
pipes = s->rlayer.numwpipes;
while (pipes > 0) {
wb = &RECORD_LAYER_get_wbuf(&s->rlayer)[pipes - 1];
OPENSSL_free(wb->buf);
wb->buf = NULL;
pipes--;
}
s->rlayer.numwpipes = 0;
return 1;
}
int ssl3_release_read_buffer(SSL *s)
{
SSL3_BUFFER *b;
b = RECORD_LAYER_get_rbuf(&s->rlayer);
OPENSSL_free(b->buf);
b->buf = NULL;
return 1;
}
