const BIO_METHOD *BIO_f_cipher(void)
{
return (&methods_enc);
}
static int enc_new(BIO *bi)
{
BIO_ENC_CTX *ctx;
ctx = OPENSSL_zalloc(sizeof(*ctx));
if (ctx == NULL)
return 0;
ctx->cipher = EVP_CIPHER_CTX_new();
if (ctx->cipher == NULL) {
OPENSSL_free(ctx);
return 0;
}
ctx->cont = 1;
ctx->ok = 1;
ctx->read_end = ctx->read_start = &(ctx->buf[BUF_OFFSET]);
BIO_set_data(bi, ctx);
BIO_set_init(bi, 1);
return 1;
}
static int enc_free(BIO *a)
{
BIO_ENC_CTX *b;
if (a == NULL)
return 0;
b = BIO_get_data(a);
if (b == NULL)
return 0;
EVP_CIPHER_CTX_free(b->cipher);
OPENSSL_clear_free(b, sizeof(BIO_ENC_CTX));
BIO_set_data(a, NULL);
BIO_set_init(a, 0);
return 1;
}
static int enc_read(BIO *b, char *out, int outl)
{
int ret = 0, i, blocksize;
BIO_ENC_CTX *ctx;
BIO *next;
if (out == NULL)
return (0);
ctx = BIO_get_data(b);
next = BIO_next(b);
if ((ctx == NULL) || (next == NULL))
return 0;
if (ctx->buf_len > 0) {
i = ctx->buf_len - ctx->buf_off;
if (i > outl)
i = outl;
memcpy(out, &(ctx->buf[ctx->buf_off]), i);
ret = i;
out += i;
outl -= i;
ctx->buf_off += i;
if (ctx->buf_len == ctx->buf_off) {
ctx->buf_len = 0;
ctx->buf_off = 0;
}
}
blocksize = EVP_CIPHER_CTX_block_size(ctx->cipher);
if (blocksize == 1)
blocksize = 0;
while (outl > 0) {
if (ctx->cont <= 0)
break;
if (ctx->read_start == ctx->read_end) {
ctx->read_end = ctx->read_start = &(ctx->buf[BUF_OFFSET]);
i = BIO_read(next, ctx->read_start, ENC_BLOCK_SIZE);
if (i > 0)
ctx->read_end += i;
} else {
i = ctx->read_end - ctx->read_start;
}
if (i <= 0) {
if (!BIO_should_retry(next)) {
ctx->cont = i;
i = EVP_CipherFinal_ex(ctx->cipher,
ctx->buf, &(ctx->buf_len));
ctx->ok = i;
ctx->buf_off = 0;
} else {
ret = (ret == 0) ? i : ret;
break;
}
} else {
if (outl > ENC_MIN_CHUNK) {
int j = outl - blocksize, buf_len;
if (!EVP_CipherUpdate(ctx->cipher,
(unsigned char *)out, &buf_len,
ctx->read_start, i > j ? j : i)) {
BIO_clear_retry_flags(b);
return 0;
}
ret += buf_len;
out += buf_len;
outl -= buf_len;
if ((i -= j) <= 0) {
ctx->read_start = ctx->read_end;
continue;
}
ctx->read_start += j;
}
if (i > ENC_MIN_CHUNK)
i = ENC_MIN_CHUNK;
if (!EVP_CipherUpdate(ctx->cipher,
ctx->buf, &ctx->buf_len,
ctx->read_start, i)) {
BIO_clear_retry_flags(b);
ctx->ok = 0;
return 0;
}
ctx->read_start += i;
ctx->cont = 1;
if (ctx->buf_len == 0)
continue;
}
if (ctx->buf_len <= outl)
i = ctx->buf_len;
else
i = outl;
if (i <= 0)
break;
memcpy(out, ctx->buf, i);
ret += i;
ctx->buf_off = i;
outl -= i;
out += i;
}
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return ((ret == 0) ? ctx->cont : ret);
}
static int enc_write(BIO *b, const char *in, int inl)
{
int ret = 0, n, i;
BIO_ENC_CTX *ctx;
BIO *next;
ctx = BIO_get_data(b);
next = BIO_next(b);
if ((ctx == NULL) || (next == NULL))
return 0;
ret = inl;
BIO_clear_retry_flags(b);
n = ctx->buf_len - ctx->buf_off;
while (n > 0) {
i = BIO_write(next, &(ctx->buf[ctx->buf_off]), n);
if (i <= 0) {
BIO_copy_next_retry(b);
return (i);
}
ctx->buf_off += i;
n -= i;
}
if ((in == NULL) || (inl <= 0))
return (0);
ctx->buf_off = 0;
while (inl > 0) {
n = (inl > ENC_BLOCK_SIZE) ? ENC_BLOCK_SIZE : inl;
if (!EVP_CipherUpdate(ctx->cipher,
ctx->buf, &ctx->buf_len,
(const unsigned char *)in, n)) {
BIO_clear_retry_flags(b);
ctx->ok = 0;
return 0;
}
inl -= n;
in += n;
ctx->buf_off = 0;
n = ctx->buf_len;
while (n > 0) {
i = BIO_write(next, &(ctx->buf[ctx->buf_off]), n);
if (i <= 0) {
BIO_copy_next_retry(b);
return (ret == inl) ? i : ret - inl;
}
n -= i;
ctx->buf_off += i;
}
ctx->buf_len = 0;
ctx->buf_off = 0;
}
BIO_copy_next_retry(b);
return (ret);
}
static long enc_ctrl(BIO *b, int cmd, long num, void *ptr)
{
BIO *dbio;
BIO_ENC_CTX *ctx, *dctx;
long ret = 1;
int i;
EVP_CIPHER_CTX **c_ctx;
BIO *next;
ctx = BIO_get_data(b);
next = BIO_next(b);
if (ctx == NULL)
return 0;
switch (cmd) {
case BIO_CTRL_RESET:
ctx->ok = 1;
ctx->finished = 0;
if (!EVP_CipherInit_ex(ctx->cipher, NULL, NULL, NULL, NULL,
EVP_CIPHER_CTX_encrypting(ctx->cipher)))
return 0;
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_CTRL_EOF:
if (ctx->cont <= 0)
ret = 1;
else
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_CTRL_WPENDING:
ret = ctx->buf_len - ctx->buf_off;
if (ret <= 0)
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_CTRL_PENDING:
ret = ctx->buf_len - ctx->buf_off;
if (ret <= 0)
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_CTRL_FLUSH:
again:
while (ctx->buf_len != ctx->buf_off) {
i = enc_write(b, NULL, 0);
if (i < 0)
return i;
}
if (!ctx->finished) {
ctx->finished = 1;
ctx->buf_off = 0;
ret = EVP_CipherFinal_ex(ctx->cipher,
(unsigned char *)ctx->buf,
&(ctx->buf_len));
ctx->ok = (int)ret;
if (ret <= 0)
break;
goto again;
}
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_C_GET_CIPHER_STATUS:
ret = (long)ctx->ok;
break;
case BIO_C_DO_STATE_MACHINE:
BIO_clear_retry_flags(b);
ret = BIO_ctrl(next, cmd, num, ptr);
BIO_copy_next_retry(b);
break;
case BIO_C_GET_CIPHER_CTX:
c_ctx = (EVP_CIPHER_CTX **)ptr;
*c_ctx = ctx->cipher;
BIO_set_init(b, 1);
break;
case BIO_CTRL_DUP:
dbio = (BIO *)ptr;
dctx = BIO_get_data(dbio);
dctx->cipher = EVP_CIPHER_CTX_new();
if (dctx->cipher == NULL)
return 0;
ret = EVP_CIPHER_CTX_copy(dctx->cipher, ctx->cipher);
if (ret)
BIO_set_init(dbio, 1);
break;
default:
ret = BIO_ctrl(next, cmd, num, ptr);
break;
}
return (ret);
}
static long enc_callback_ctrl(BIO *b, int cmd, bio_info_cb *fp)
{
long ret = 1;
BIO *next = BIO_next(b);
if (next == NULL)
return (0);
switch (cmd) {
default:
ret = BIO_callback_ctrl(next, cmd, fp);
break;
}
return (ret);
}
int BIO_set_cipher(BIO *b, const EVP_CIPHER *c, const unsigned char *k,
const unsigned char *i, int e)
{
BIO_ENC_CTX *ctx;
long (*callback) (struct bio_st *, int, const char *, int, long, long);
ctx = BIO_get_data(b);
if (ctx == NULL)
return 0;
callback = BIO_get_callback(b);
if ((callback != NULL) &&
(callback(b, BIO_CB_CTRL, (const char *)c, BIO_CTRL_SET, e,
0L) <= 0))
return 0;
BIO_set_init(b, 1);
if (!EVP_CipherInit_ex(ctx->cipher, c, NULL, k, i, e))
return 0;
if (callback != NULL)
return callback(b, BIO_CB_CTRL, (const char *)c, BIO_CTRL_SET, e, 1L);
return 1;
}
