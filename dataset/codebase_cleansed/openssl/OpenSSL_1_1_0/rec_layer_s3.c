void RECORD_LAYER_init(RECORD_LAYER *rl, SSL *s)
{
rl->s = s;
RECORD_LAYER_set_first_record(&s->rlayer);
SSL3_RECORD_clear(rl->rrec, SSL_MAX_PIPELINES);
}
void RECORD_LAYER_clear(RECORD_LAYER *rl)
{
unsigned int pipes;
rl->rstate = SSL_ST_READ_HEADER;
rl->packet = NULL;
rl->packet_length = 0;
rl->wnum = 0;
memset(rl->alert_fragment, 0, sizeof(rl->alert_fragment));
rl->alert_fragment_len = 0;
memset(rl->handshake_fragment, 0, sizeof(rl->handshake_fragment));
rl->handshake_fragment_len = 0;
rl->wpend_tot = 0;
rl->wpend_type = 0;
rl->wpend_ret = 0;
rl->wpend_buf = NULL;
SSL3_BUFFER_clear(&rl->rbuf);
for (pipes = 0; pipes < rl->numwpipes; pipes++)
SSL3_BUFFER_clear(&rl->wbuf[pipes]);
rl->numwpipes = 0;
rl->numrpipes = 0;
SSL3_RECORD_clear(rl->rrec, SSL_MAX_PIPELINES);
RECORD_LAYER_reset_read_sequence(rl);
RECORD_LAYER_reset_write_sequence(rl);
if (rl->d)
DTLS_RECORD_LAYER_clear(rl);
}
void RECORD_LAYER_release(RECORD_LAYER *rl)
{
if (SSL3_BUFFER_is_initialised(&rl->rbuf))
ssl3_release_read_buffer(rl->s);
if (rl->numwpipes > 0)
ssl3_release_write_buffer(rl->s);
SSL3_RECORD_release(rl->rrec, SSL_MAX_PIPELINES);
}
int RECORD_LAYER_read_pending(const RECORD_LAYER *rl)
{
return SSL3_BUFFER_get_left(&rl->rbuf) != 0;
}
int RECORD_LAYER_write_pending(const RECORD_LAYER *rl)
{
return (rl->numwpipes > 0)
&& SSL3_BUFFER_get_left(&rl->wbuf[rl->numwpipes - 1]) != 0;
}
int RECORD_LAYER_set_data(RECORD_LAYER *rl, const unsigned char *buf, int len)
{
rl->packet_length = len;
if (len != 0) {
rl->rstate = SSL_ST_READ_HEADER;
if (!SSL3_BUFFER_is_initialised(&rl->rbuf))
if (!ssl3_setup_read_buffer(rl->s))
return 0;
}
rl->packet = SSL3_BUFFER_get_buf(&rl->rbuf);
SSL3_BUFFER_set_data(&rl->rbuf, buf, len);
return 1;
}
void RECORD_LAYER_reset_read_sequence(RECORD_LAYER *rl)
{
memset(rl->read_sequence, 0, sizeof(rl->read_sequence));
}
void RECORD_LAYER_reset_write_sequence(RECORD_LAYER *rl)
{
memset(rl->write_sequence, 0, sizeof(rl->write_sequence));
}
int ssl3_pending(const SSL *s)
{
unsigned int i;
int num = 0;
if (s->rlayer.rstate == SSL_ST_READ_BODY)
return 0;
for (i = 0; i < RECORD_LAYER_get_numrpipes(&s->rlayer); i++) {
if (SSL3_RECORD_get_type(&s->rlayer.rrec[i])
!= SSL3_RT_APPLICATION_DATA)
return 0;
num += SSL3_RECORD_get_length(&s->rlayer.rrec[i]);
}
return num;
}
void SSL_CTX_set_default_read_buffer_len(SSL_CTX *ctx, size_t len)
{
ctx->default_read_buf_len = len;
}
void SSL_set_default_read_buffer_len(SSL *s, size_t len)
{
SSL3_BUFFER_set_default_len(RECORD_LAYER_get_rbuf(&s->rlayer), len);
}
const char *SSL_rstate_string_long(const SSL *s)
{
switch (s->rlayer.rstate) {
case SSL_ST_READ_HEADER:
return "read header";
case SSL_ST_READ_BODY:
return "read body";
case SSL_ST_READ_DONE:
return "read done";
default:
return "unknown";
}
}
const char *SSL_rstate_string(const SSL *s)
{
switch (s->rlayer.rstate) {
case SSL_ST_READ_HEADER:
return "RH";
case SSL_ST_READ_BODY:
return "RB";
case SSL_ST_READ_DONE:
return "RD";
default:
return "unknown";
}
}
int ssl3_read_n(SSL *s, int n, int max, int extend, int clearold)
{
int i, len, left;
size_t align = 0;
unsigned char *pkt;
SSL3_BUFFER *rb;
if (n <= 0)
return n;
rb = &s->rlayer.rbuf;
if (rb->buf == NULL)
if (!ssl3_setup_read_buffer(s))
return -1;
left = rb->left;
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
align = (size_t)rb->buf + SSL3_RT_HEADER_LENGTH;
align = SSL3_ALIGN_PAYLOAD - 1 - ((align - 1) % SSL3_ALIGN_PAYLOAD);
#endif
if (!extend) {
if (left == 0)
rb->offset = align;
else if (align != 0 && left >= SSL3_RT_HEADER_LENGTH) {
pkt = rb->buf + rb->offset;
if (pkt[0] == SSL3_RT_APPLICATION_DATA
&& (pkt[3] << 8 | pkt[4]) >= 128) {
memmove(rb->buf + align, pkt, left);
rb->offset = align;
}
}
s->rlayer.packet = rb->buf + rb->offset;
s->rlayer.packet_length = 0;
}
if (SSL_IS_DTLS(s)) {
if (left == 0 && extend)
return 0;
if (left > 0 && n > left)
n = left;
}
if (left >= n) {
s->rlayer.packet_length += n;
rb->left = left - n;
rb->offset += n;
return (n);
}
len = s->rlayer.packet_length;
pkt = rb->buf + align;
if (s->rlayer.packet != pkt && clearold == 1) {
memmove(pkt, s->rlayer.packet, len + left);
s->rlayer.packet = pkt;
rb->offset = len + align;
}
if (n > (int)(rb->len - rb->offset)) {
SSLerr(SSL_F_SSL3_READ_N, ERR_R_INTERNAL_ERROR);
return -1;
}
if (!s->rlayer.read_ahead && !SSL_IS_DTLS(s))
max = n;
else {
if (max < n)
max = n;
if (max > (int)(rb->len - rb->offset))
max = rb->len - rb->offset;
}
while (left < n) {
clear_sys_error();
if (s->rbio != NULL) {
s->rwstate = SSL_READING;
i = BIO_read(s->rbio, pkt + len + left, max - left);
} else {
SSLerr(SSL_F_SSL3_READ_N, SSL_R_READ_BIO_NOT_SET);
i = -1;
}
if (i <= 0) {
rb->left = left;
if (s->mode & SSL_MODE_RELEASE_BUFFERS && !SSL_IS_DTLS(s))
if (len + left == 0)
ssl3_release_read_buffer(s);
return (i);
}
left += i;
if (SSL_IS_DTLS(s)) {
if (n > left)
n = left;
}
}
rb->offset += n;
rb->left = left - n;
s->rlayer.packet_length += n;
s->rwstate = SSL_NOTHING;
return (n);
}
int ssl3_write_bytes(SSL *s, int type, const void *buf_, int len)
{
const unsigned char *buf = buf_;
int tot;
unsigned int n, split_send_fragment, maxpipes;
#if !defined(OPENSSL_NO_MULTIBLOCK) && EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK
unsigned int max_send_fragment, nw;
unsigned int u_len = (unsigned int)len;
#endif
SSL3_BUFFER *wb = &s->rlayer.wbuf[0];
int i;
if (len < 0) {
SSLerr(SSL_F_SSL3_WRITE_BYTES, SSL_R_SSL_NEGATIVE_LENGTH);
return -1;
}
s->rwstate = SSL_NOTHING;
tot = s->rlayer.wnum;
if ((unsigned int)len < s->rlayer.wnum) {
SSLerr(SSL_F_SSL3_WRITE_BYTES, SSL_R_BAD_LENGTH);
return -1;
}
s->rlayer.wnum = 0;
if (SSL_in_init(s) && !ossl_statem_get_in_handshake(s)) {
i = s->handshake_func(s);
if (i < 0)
return (i);
if (i == 0) {
SSLerr(SSL_F_SSL3_WRITE_BYTES, SSL_R_SSL_HANDSHAKE_FAILURE);
return -1;
}
}
if (wb->left != 0) {
i = ssl3_write_pending(s, type, &buf[tot], s->rlayer.wpend_tot);
if (i <= 0) {
s->rlayer.wnum = tot;
return i;
}
tot += i;
}
#if !defined(OPENSSL_NO_MULTIBLOCK) && EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK
if (type == SSL3_RT_APPLICATION_DATA &&
u_len >= 4 * (max_send_fragment = s->max_send_fragment) &&
s->compress == NULL && s->msg_callback == NULL &&
!SSL_USE_ETM(s) && SSL_USE_EXPLICIT_IV(s) &&
EVP_CIPHER_flags(EVP_CIPHER_CTX_cipher(s->enc_write_ctx)) &
EVP_CIPH_FLAG_TLS1_1_MULTIBLOCK) {
unsigned char aad[13];
EVP_CTRL_TLS1_1_MULTIBLOCK_PARAM mb_param;
int packlen;
if ((max_send_fragment & 0xfff) == 0)
max_send_fragment -= 512;
if (tot == 0 || wb->buf == NULL) {
ssl3_release_write_buffer(s);
packlen = EVP_CIPHER_CTX_ctrl(s->enc_write_ctx,
EVP_CTRL_TLS1_1_MULTIBLOCK_MAX_BUFSIZE,
max_send_fragment, NULL);
if (u_len >= 8 * max_send_fragment)
packlen *= 8;
else
packlen *= 4;
if (!ssl3_setup_write_buffer(s, 1, packlen)) {
SSLerr(SSL_F_SSL3_WRITE_BYTES, ERR_R_MALLOC_FAILURE);
return -1;
}
} else if (tot == len) {
ssl3_release_write_buffer(s);
return tot;
}
n = (len - tot);
for (;;) {
if (n < 4 * max_send_fragment) {
ssl3_release_write_buffer(s);
break;
}
if (s->s3->alert_dispatch) {
i = s->method->ssl_dispatch_alert(s);
if (i <= 0) {
s->rlayer.wnum = tot;
return i;
}
}
if (n >= 8 * max_send_fragment)
nw = max_send_fragment * (mb_param.interleave = 8);
else
nw = max_send_fragment * (mb_param.interleave = 4);
memcpy(aad, s->rlayer.write_sequence, 8);
aad[8] = type;
aad[9] = (unsigned char)(s->version >> 8);
aad[10] = (unsigned char)(s->version);
aad[11] = 0;
aad[12] = 0;
mb_param.out = NULL;
mb_param.inp = aad;
mb_param.len = nw;
packlen = EVP_CIPHER_CTX_ctrl(s->enc_write_ctx,
EVP_CTRL_TLS1_1_MULTIBLOCK_AAD,
sizeof(mb_param), &mb_param);
if (packlen <= 0 || packlen > (int)wb->len) {
ssl3_release_write_buffer(s);
break;
}
mb_param.out = wb->buf;
mb_param.inp = &buf[tot];
mb_param.len = nw;
if (EVP_CIPHER_CTX_ctrl(s->enc_write_ctx,
EVP_CTRL_TLS1_1_MULTIBLOCK_ENCRYPT,
sizeof(mb_param), &mb_param) <= 0)
return -1;
s->rlayer.write_sequence[7] += mb_param.interleave;
if (s->rlayer.write_sequence[7] < mb_param.interleave) {
int j = 6;
while (j >= 0 && (++s->rlayer.write_sequence[j--]) == 0) ;
}
wb->offset = 0;
wb->left = packlen;
s->rlayer.wpend_tot = nw;
s->rlayer.wpend_buf = &buf[tot];
s->rlayer.wpend_type = type;
s->rlayer.wpend_ret = nw;
i = ssl3_write_pending(s, type, &buf[tot], nw);
if (i <= 0) {
if (i < 0 && (!s->wbio || !BIO_should_retry(s->wbio))) {
ssl3_release_write_buffer(s);
}
s->rlayer.wnum = tot;
return i;
}
if (i == (int)n) {
ssl3_release_write_buffer(s);
return tot + i;
}
n -= i;
tot += i;
}
} else
#endif
if (tot == len) {
if (s->mode & SSL_MODE_RELEASE_BUFFERS && !SSL_IS_DTLS(s))
ssl3_release_write_buffer(s);
return tot;
}
n = (len - tot);
split_send_fragment = s->split_send_fragment;
maxpipes = s->max_pipelines;
if (maxpipes > SSL_MAX_PIPELINES) {
SSLerr(SSL_F_SSL3_WRITE_BYTES, ERR_R_INTERNAL_ERROR);
return -1;
}
if (maxpipes == 0
|| s->enc_write_ctx == NULL
|| !(EVP_CIPHER_flags(EVP_CIPHER_CTX_cipher(s->enc_write_ctx))
& EVP_CIPH_FLAG_PIPELINE)
|| !SSL_USE_EXPLICIT_IV(s))
maxpipes = 1;
if (s->max_send_fragment == 0 || split_send_fragment > s->max_send_fragment
|| split_send_fragment == 0) {
SSLerr(SSL_F_SSL3_WRITE_BYTES, ERR_R_INTERNAL_ERROR);
return -1;
}
for (;;) {
unsigned int pipelens[SSL_MAX_PIPELINES], tmppipelen, remain;
unsigned int numpipes, j;
if (n == 0)
numpipes = 1;
else
numpipes = ((n - 1) / split_send_fragment) + 1;
if (numpipes > maxpipes)
numpipes = maxpipes;
if (n / numpipes >= s->max_send_fragment) {
for (j = 0; j < numpipes; j++) {
pipelens[j] = s->max_send_fragment;
}
} else {
tmppipelen = n / numpipes;
remain = n % numpipes;
for (j = 0; j < numpipes; j++) {
pipelens[j] = tmppipelen;
if (j < remain)
pipelens[j]++;
}
}
i = do_ssl3_write(s, type, &(buf[tot]), pipelens, numpipes, 0);
if (i <= 0) {
s->rlayer.wnum = tot;
return i;
}
if ((i == (int)n) ||
(type == SSL3_RT_APPLICATION_DATA &&
(s->mode & SSL_MODE_ENABLE_PARTIAL_WRITE))) {
s->s3->empty_fragment_done = 0;
if ((i == (int)n) && s->mode & SSL_MODE_RELEASE_BUFFERS &&
!SSL_IS_DTLS(s))
ssl3_release_write_buffer(s);
return tot + i;
}
n -= i;
tot += i;
}
}
int do_ssl3_write(SSL *s, int type, const unsigned char *buf,
unsigned int *pipelens, unsigned int numpipes,
int create_empty_fragment)
{
unsigned char *outbuf[SSL_MAX_PIPELINES], *plen[SSL_MAX_PIPELINES];
SSL3_RECORD wr[SSL_MAX_PIPELINES];
int i, mac_size, clear = 0;
int prefix_len = 0;
int eivlen;
size_t align = 0;
SSL3_BUFFER *wb;
SSL_SESSION *sess;
unsigned int totlen = 0;
unsigned int j;
for (j = 0; j < numpipes; j++)
totlen += pipelens[j];
if (RECORD_LAYER_write_pending(&s->rlayer))
return (ssl3_write_pending(s, type, buf, totlen));
if (s->s3->alert_dispatch) {
i = s->method->ssl_dispatch_alert(s);
if (i <= 0)
return (i);
}
if (s->rlayer.numwpipes < numpipes)
if (!ssl3_setup_write_buffer(s, numpipes, 0))
return -1;
if (totlen == 0 && !create_empty_fragment)
return 0;
sess = s->session;
if ((sess == NULL) ||
(s->enc_write_ctx == NULL) || (EVP_MD_CTX_md(s->write_hash) == NULL)) {
clear = s->enc_write_ctx ? 0 : 1;
mac_size = 0;
} else {
mac_size = EVP_MD_CTX_size(s->write_hash);
if (mac_size < 0)
goto err;
}
if (!clear && !create_empty_fragment && !s->s3->empty_fragment_done) {
if (s->s3->need_empty_fragments && type == SSL3_RT_APPLICATION_DATA) {
unsigned int tmppipelen = 0;
prefix_len = do_ssl3_write(s, type, buf, &tmppipelen, 1, 1);
if (prefix_len <= 0)
goto err;
if (prefix_len >
(SSL3_RT_HEADER_LENGTH + SSL3_RT_SEND_MAX_ENCRYPTED_OVERHEAD)) {
SSLerr(SSL_F_DO_SSL3_WRITE, ERR_R_INTERNAL_ERROR);
goto err;
}
}
s->s3->empty_fragment_done = 1;
}
if (create_empty_fragment) {
wb = &s->rlayer.wbuf[0];
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
align = (size_t)SSL3_BUFFER_get_buf(wb) + 2 * SSL3_RT_HEADER_LENGTH;
align = SSL3_ALIGN_PAYLOAD - 1 - ((align - 1) % SSL3_ALIGN_PAYLOAD);
#endif
outbuf[0] = SSL3_BUFFER_get_buf(wb) + align;
SSL3_BUFFER_set_offset(wb, align);
} else if (prefix_len) {
wb = &s->rlayer.wbuf[0];
outbuf[0] = SSL3_BUFFER_get_buf(wb) + SSL3_BUFFER_get_offset(wb)
+ prefix_len;
} else {
for (j = 0; j < numpipes; j++) {
wb = &s->rlayer.wbuf[j];
#if defined(SSL3_ALIGN_PAYLOAD) && SSL3_ALIGN_PAYLOAD!=0
align = (size_t)SSL3_BUFFER_get_buf(wb) + SSL3_RT_HEADER_LENGTH;
align = SSL3_ALIGN_PAYLOAD - 1 - ((align - 1) % SSL3_ALIGN_PAYLOAD);
#endif
outbuf[j] = SSL3_BUFFER_get_buf(wb) + align;
SSL3_BUFFER_set_offset(wb, align);
}
}
if (s->enc_write_ctx && SSL_USE_EXPLICIT_IV(s)) {
int mode = EVP_CIPHER_CTX_mode(s->enc_write_ctx);
if (mode == EVP_CIPH_CBC_MODE) {
eivlen = EVP_CIPHER_CTX_iv_length(s->enc_write_ctx);
if (eivlen <= 1)
eivlen = 0;
}
else if (mode == EVP_CIPH_GCM_MODE)
eivlen = EVP_GCM_TLS_EXPLICIT_IV_LEN;
else if (mode == EVP_CIPH_CCM_MODE)
eivlen = EVP_CCM_TLS_EXPLICIT_IV_LEN;
else
eivlen = 0;
} else
eivlen = 0;
totlen = 0;
memset(wr, 0, sizeof wr);
for (j = 0; j < numpipes; j++) {
*(outbuf[j]++) = type & 0xff;
SSL3_RECORD_set_type(&wr[j], type);
*(outbuf[j]++) = (s->version >> 8);
if (SSL_get_state(s) == TLS_ST_CW_CLNT_HELLO
&& !s->renegotiate && TLS1_get_version(s) > TLS1_VERSION)
*(outbuf[j]++) = 0x1;
else
*(outbuf[j]++) = s->version & 0xff;
plen[j] = outbuf[j];
outbuf[j] += 2;
SSL3_RECORD_set_data(&wr[j], outbuf[j] + eivlen);
SSL3_RECORD_set_length(&wr[j], (int)pipelens[j]);
SSL3_RECORD_set_input(&wr[j], (unsigned char *)&buf[totlen]);
totlen += pipelens[j];
if (s->compress != NULL) {
if (!ssl3_do_compress(s, &wr[j])) {
SSLerr(SSL_F_DO_SSL3_WRITE, SSL_R_COMPRESSION_FAILURE);
goto err;
}
} else {
memcpy(wr[j].data, wr[j].input, wr[j].length);
SSL3_RECORD_reset_input(&wr[j]);
}
if (!SSL_USE_ETM(s) && mac_size != 0) {
if (s->method->ssl3_enc->mac(s, &wr[j],
&(outbuf[j][wr[j].length + eivlen]),
1) < 0)
goto err;
SSL3_RECORD_add_length(&wr[j], mac_size);
}
SSL3_RECORD_set_data(&wr[j], outbuf[j]);
SSL3_RECORD_reset_input(&wr[j]);
if (eivlen) {
SSL3_RECORD_add_length(&wr[j], eivlen);
}
}
if (s->method->ssl3_enc->enc(s, wr, numpipes, 1) < 1)
goto err;
for (j = 0; j < numpipes; j++) {
if (SSL_USE_ETM(s) && mac_size != 0) {
if (s->method->ssl3_enc->mac(s, &wr[j],
outbuf[j] + wr[j].length, 1) < 0)
goto err;
SSL3_RECORD_add_length(&wr[j], mac_size);
}
s2n(SSL3_RECORD_get_length(&wr[j]), plen[j]);
if (s->msg_callback)
s->msg_callback(1, 0, SSL3_RT_HEADER, plen[j] - 5, 5, s,
s->msg_callback_arg);
SSL3_RECORD_set_type(&wr[j], type);
SSL3_RECORD_add_length(&wr[j], SSL3_RT_HEADER_LENGTH);
if (create_empty_fragment) {
if (j > 0) {
SSLerr(SSL_F_DO_SSL3_WRITE, ERR_R_INTERNAL_ERROR);
goto err;
}
return SSL3_RECORD_get_length(wr);
}
SSL3_BUFFER_set_left(&s->rlayer.wbuf[j],
prefix_len + SSL3_RECORD_get_length(&wr[j]));
}
s->rlayer.wpend_tot = totlen;
s->rlayer.wpend_buf = buf;
s->rlayer.wpend_type = type;
s->rlayer.wpend_ret = totlen;
return ssl3_write_pending(s, type, buf, totlen);
err:
return -1;
}
int ssl3_write_pending(SSL *s, int type, const unsigned char *buf,
unsigned int len)
{
int i;
SSL3_BUFFER *wb = s->rlayer.wbuf;
unsigned int currbuf = 0;
if ((s->rlayer.wpend_tot > (int)len)
|| ((s->rlayer.wpend_buf != buf) &&
!(s->mode & SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER))
|| (s->rlayer.wpend_type != type)) {
SSLerr(SSL_F_SSL3_WRITE_PENDING, SSL_R_BAD_WRITE_RETRY);
return (-1);
}
for (;;) {
if (SSL3_BUFFER_get_left(&wb[currbuf]) == 0
&& currbuf < s->rlayer.numwpipes - 1) {
currbuf++;
continue;
}
clear_sys_error();
if (s->wbio != NULL) {
s->rwstate = SSL_WRITING;
i = BIO_write(s->wbio, (char *)
&(SSL3_BUFFER_get_buf(&wb[currbuf])
[SSL3_BUFFER_get_offset(&wb[currbuf])]),
(unsigned int)SSL3_BUFFER_get_left(&wb[currbuf]));
} else {
SSLerr(SSL_F_SSL3_WRITE_PENDING, SSL_R_BIO_NOT_SET);
i = -1;
}
if (i == SSL3_BUFFER_get_left(&wb[currbuf])) {
SSL3_BUFFER_set_left(&wb[currbuf], 0);
SSL3_BUFFER_add_offset(&wb[currbuf], i);
if (currbuf + 1 < s->rlayer.numwpipes)
continue;
s->rwstate = SSL_NOTHING;
return (s->rlayer.wpend_ret);
} else if (i <= 0) {
if (SSL_IS_DTLS(s)) {
SSL3_BUFFER_set_left(&wb[currbuf], 0);
}
return (i);
}
SSL3_BUFFER_add_offset(&wb[currbuf], i);
SSL3_BUFFER_add_left(&wb[currbuf], -i);
}
}
int ssl3_read_bytes(SSL *s, int type, int *recvd_type, unsigned char *buf,
int len, int peek)
{
int al, i, j, ret;
unsigned int n, curr_rec, num_recs, read_bytes;
SSL3_RECORD *rr;
SSL3_BUFFER *rbuf;
void (*cb) (const SSL *ssl, int type2, int val) = NULL;
rbuf = &s->rlayer.rbuf;
if (!SSL3_BUFFER_is_initialised(rbuf)) {
if (!ssl3_setup_read_buffer(s))
return (-1);
}
if ((type && (type != SSL3_RT_APPLICATION_DATA)
&& (type != SSL3_RT_HANDSHAKE)) || (peek
&& (type !=
SSL3_RT_APPLICATION_DATA))) {
SSLerr(SSL_F_SSL3_READ_BYTES, ERR_R_INTERNAL_ERROR);
return -1;
}
if ((type == SSL3_RT_HANDSHAKE) && (s->rlayer.handshake_fragment_len > 0))
{
unsigned char *src = s->rlayer.handshake_fragment;
unsigned char *dst = buf;
unsigned int k;
n = 0;
while ((len > 0) && (s->rlayer.handshake_fragment_len > 0)) {
*dst++ = *src++;
len--;
s->rlayer.handshake_fragment_len--;
n++;
}
for (k = 0; k < s->rlayer.handshake_fragment_len; k++)
s->rlayer.handshake_fragment[k] = *src++;
if (recvd_type != NULL)
*recvd_type = SSL3_RT_HANDSHAKE;
return n;
}
if (!ossl_statem_get_in_handshake(s) && SSL_in_init(s)) {
i = s->handshake_func(s);
if (i < 0)
return (i);
if (i == 0) {
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_SSL_HANDSHAKE_FAILURE);
return (-1);
}
}
start:
s->rwstate = SSL_NOTHING;
rr = s->rlayer.rrec;
num_recs = RECORD_LAYER_get_numrpipes(&s->rlayer);
do {
if (num_recs == 0) {
ret = ssl3_get_record(s);
if (ret <= 0)
return (ret);
num_recs = RECORD_LAYER_get_numrpipes(&s->rlayer);
if (num_recs == 0) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_SSL3_READ_BYTES, ERR_R_INTERNAL_ERROR);
goto f_err;
}
}
for (curr_rec = 0;
curr_rec < num_recs && SSL3_RECORD_is_read(&rr[curr_rec]);
curr_rec++) ;
if (curr_rec == num_recs) {
RECORD_LAYER_set_numrpipes(&s->rlayer, 0);
num_recs = 0;
curr_rec = 0;
}
} while (num_recs == 0);
rr = &rr[curr_rec];
if (s->s3->change_cipher_spec
&& (SSL3_RECORD_get_type(rr) != SSL3_RT_HANDSHAKE)) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_DATA_BETWEEN_CCS_AND_FINISHED);
goto f_err;
}
if (s->shutdown & SSL_RECEIVED_SHUTDOWN) {
SSL3_RECORD_set_length(rr, 0);
s->rwstate = SSL_NOTHING;
return (0);
}
if (type == SSL3_RECORD_get_type(rr)
|| (SSL3_RECORD_get_type(rr) == SSL3_RT_CHANGE_CIPHER_SPEC
&& type == SSL3_RT_HANDSHAKE && recvd_type != NULL)) {
if (SSL_in_init(s) && (type == SSL3_RT_APPLICATION_DATA) &&
(s->enc_read_ctx == NULL)) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_APP_DATA_IN_HANDSHAKE);
goto f_err;
}
if (type == SSL3_RT_HANDSHAKE
&& SSL3_RECORD_get_type(rr) == SSL3_RT_CHANGE_CIPHER_SPEC
&& s->rlayer.handshake_fragment_len > 0) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_CCS_RECEIVED_EARLY);
goto f_err;
}
if (recvd_type != NULL)
*recvd_type = SSL3_RECORD_get_type(rr);
if (len <= 0)
return (len);
read_bytes = 0;
do {
if ((unsigned int)len - read_bytes > SSL3_RECORD_get_length(rr))
n = SSL3_RECORD_get_length(rr);
else
n = (unsigned int)len - read_bytes;
memcpy(buf, &(rr->data[rr->off]), n);
buf += n;
if (!peek) {
SSL3_RECORD_sub_length(rr, n);
SSL3_RECORD_add_off(rr, n);
if (SSL3_RECORD_get_length(rr) == 0) {
s->rlayer.rstate = SSL_ST_READ_HEADER;
SSL3_RECORD_set_off(rr, 0);
SSL3_RECORD_set_read(rr);
}
}
if (SSL3_RECORD_get_length(rr) == 0
|| (peek && n == SSL3_RECORD_get_length(rr))) {
curr_rec++;
rr++;
}
read_bytes += n;
} while (type == SSL3_RT_APPLICATION_DATA && curr_rec < num_recs
&& read_bytes < (unsigned int)len);
if (read_bytes == 0) {
goto start;
}
if (!peek && curr_rec == num_recs
&& (s->mode & SSL_MODE_RELEASE_BUFFERS)
&& SSL3_BUFFER_get_left(rbuf) == 0)
ssl3_release_read_buffer(s);
return read_bytes;
}
if (rr->rec_version == SSL2_VERSION) {
al = SSL_AD_INTERNAL_ERROR;
SSLerr(SSL_F_SSL3_READ_BYTES, ERR_R_INTERNAL_ERROR);
goto f_err;
}
if (s->method->version == TLS_ANY_VERSION
&& (s->server || rr->type != SSL3_RT_ALERT)) {
s->version = rr->rec_version;
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
{
unsigned int dest_maxlen = 0;
unsigned char *dest = NULL;
unsigned int *dest_len = NULL;
if (SSL3_RECORD_get_type(rr) == SSL3_RT_HANDSHAKE) {
dest_maxlen = sizeof s->rlayer.handshake_fragment;
dest = s->rlayer.handshake_fragment;
dest_len = &s->rlayer.handshake_fragment_len;
} else if (SSL3_RECORD_get_type(rr) == SSL3_RT_ALERT) {
dest_maxlen = sizeof s->rlayer.alert_fragment;
dest = s->rlayer.alert_fragment;
dest_len = &s->rlayer.alert_fragment_len;
}
if (dest_maxlen > 0) {
n = dest_maxlen - *dest_len;
if (SSL3_RECORD_get_length(rr) < n)
n = SSL3_RECORD_get_length(rr);
while (n-- > 0) {
dest[(*dest_len)++] =
SSL3_RECORD_get_data(rr)[SSL3_RECORD_get_off(rr)];
SSL3_RECORD_add_off(rr, 1);
SSL3_RECORD_add_length(rr, -1);
}
if (*dest_len < dest_maxlen) {
SSL3_RECORD_set_read(rr);
goto start;
}
}
}
if ((!s->server) &&
(s->rlayer.handshake_fragment_len >= 4) &&
(s->rlayer.handshake_fragment[0] == SSL3_MT_HELLO_REQUEST) &&
(s->session != NULL) && (s->session->cipher != NULL)) {
s->rlayer.handshake_fragment_len = 0;
if ((s->rlayer.handshake_fragment[1] != 0) ||
(s->rlayer.handshake_fragment[2] != 0) ||
(s->rlayer.handshake_fragment[3] != 0)) {
al = SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_BAD_HELLO_REQUEST);
goto f_err;
}
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_HANDSHAKE,
s->rlayer.handshake_fragment, 4, s,
s->msg_callback_arg);
if (SSL_is_init_finished(s) &&
!(s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS) &&
!s->s3->renegotiate) {
ssl3_renegotiate(s);
if (ssl3_renegotiate_check(s)) {
i = s->handshake_func(s);
if (i < 0)
return (i);
if (i == 0) {
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_SSL_HANDSHAKE_FAILURE);
return (-1);
}
if (!(s->mode & SSL_MODE_AUTO_RETRY)) {
if (SSL3_BUFFER_get_left(rbuf) == 0) {
BIO *bio;
s->rwstate = SSL_READING;
bio = SSL_get_rbio(s);
BIO_clear_retry_flags(bio);
BIO_set_retry_read(bio);
return (-1);
}
}
}
}
goto start;
}
if (s->server &&
SSL_is_init_finished(s) &&
!s->s3->send_connection_binding &&
(s->version > SSL3_VERSION) &&
(s->rlayer.handshake_fragment_len >= 4) &&
(s->rlayer.handshake_fragment[0] == SSL3_MT_CLIENT_HELLO) &&
(s->session != NULL) && (s->session->cipher != NULL) &&
!(s->ctx->options & SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION)) {
SSL3_RECORD_set_length(rr, 0);
SSL3_RECORD_set_read(rr);
ssl3_send_alert(s, SSL3_AL_WARNING, SSL_AD_NO_RENEGOTIATION);
goto start;
}
if (s->rlayer.alert_fragment_len >= 2) {
int alert_level = s->rlayer.alert_fragment[0];
int alert_descr = s->rlayer.alert_fragment[1];
s->rlayer.alert_fragment_len = 0;
if (s->msg_callback)
s->msg_callback(0, s->version, SSL3_RT_ALERT,
s->rlayer.alert_fragment, 2, s,
s->msg_callback_arg);
if (s->info_callback != NULL)
cb = s->info_callback;
else if (s->ctx->info_callback != NULL)
cb = s->ctx->info_callback;
if (cb != NULL) {
j = (alert_level << 8) | alert_descr;
cb(s, SSL_CB_READ_ALERT, j);
}
if (alert_level == SSL3_AL_WARNING) {
s->s3->warn_alert = alert_descr;
SSL3_RECORD_set_read(rr);
if (alert_descr == SSL_AD_CLOSE_NOTIFY) {
s->shutdown |= SSL_RECEIVED_SHUTDOWN;
return (0);
}
else if (alert_descr == SSL_AD_NO_RENEGOTIATION) {
al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_NO_RENEGOTIATION);
goto f_err;
}
#ifdef SSL_AD_MISSING_SRP_USERNAME
else if (alert_descr == SSL_AD_MISSING_SRP_USERNAME)
return (0);
#endif
} else if (alert_level == SSL3_AL_FATAL) {
char tmp[16];
s->rwstate = SSL_NOTHING;
s->s3->fatal_alert = alert_descr;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_AD_REASON_OFFSET + alert_descr);
BIO_snprintf(tmp, sizeof tmp, "%d", alert_descr);
ERR_add_error_data(2, "SSL alert number ", tmp);
s->shutdown |= SSL_RECEIVED_SHUTDOWN;
SSL3_RECORD_set_read(rr);
SSL_CTX_remove_session(s->session_ctx, s->session);
return (0);
} else {
al = SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_UNKNOWN_ALERT_TYPE);
goto f_err;
}
goto start;
}
if (s->shutdown & SSL_SENT_SHUTDOWN) {
s->rwstate = SSL_NOTHING;
SSL3_RECORD_set_length(rr, 0);
SSL3_RECORD_set_read(rr);
return (0);
}
if (SSL3_RECORD_get_type(rr) == SSL3_RT_CHANGE_CIPHER_SPEC) {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_CCS_RECEIVED_EARLY);
goto f_err;
}
if ((s->rlayer.handshake_fragment_len >= 4)
&& !ossl_statem_get_in_handshake(s)) {
if (SSL_is_init_finished(s) &&
!(s->s3->flags & SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS)) {
ossl_statem_set_in_init(s, 1);
s->renegotiate = 1;
s->new_session = 1;
}
i = s->handshake_func(s);
if (i < 0)
return (i);
if (i == 0) {
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_SSL_HANDSHAKE_FAILURE);
return (-1);
}
if (!(s->mode & SSL_MODE_AUTO_RETRY)) {
if (SSL3_BUFFER_get_left(rbuf) == 0) {
BIO *bio;
s->rwstate = SSL_READING;
bio = SSL_get_rbio(s);
BIO_clear_retry_flags(bio);
BIO_set_retry_read(bio);
return (-1);
}
}
goto start;
}
switch (SSL3_RECORD_get_type(rr)) {
default:
if (s->version >= TLS1_VERSION && s->version <= TLS1_1_VERSION) {
SSL3_RECORD_set_length(rr, 0);
SSL3_RECORD_set_read(rr);
goto start;
}
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_UNEXPECTED_RECORD);
goto f_err;
case SSL3_RT_CHANGE_CIPHER_SPEC:
case SSL3_RT_ALERT:
case SSL3_RT_HANDSHAKE:
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, ERR_R_INTERNAL_ERROR);
goto f_err;
case SSL3_RT_APPLICATION_DATA:
if (ossl_statem_app_data_allowed(s)) {
s->s3->in_read_app_data = 2;
return (-1);
} else {
al = SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_READ_BYTES, SSL_R_UNEXPECTED_RECORD);
goto f_err;
}
}
f_err:
ssl3_send_alert(s, SSL3_AL_FATAL, al);
return (-1);
}
void ssl3_record_sequence_update(unsigned char *seq)
{
int i;
for (i = 7; i >= 0; i--) {
++seq[i];
if (seq[i] != 0)
break;
}
}
int RECORD_LAYER_is_sslv2_record(RECORD_LAYER *rl)
{
return SSL3_RECORD_is_sslv2_record(&rl->rrec[0]);
}
unsigned int RECORD_LAYER_get_rrec_length(RECORD_LAYER *rl)
{
return SSL3_RECORD_get_length(&rl->rrec[0]);
}
