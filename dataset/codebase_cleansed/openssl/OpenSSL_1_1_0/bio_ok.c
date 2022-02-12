const BIO_METHOD *BIO_f_reliable(void)
{
return (&methods_ok);
}
static int ok_new(BIO *bi)
{
BIO_OK_CTX *ctx;
ctx = OPENSSL_zalloc(sizeof(*ctx));
if (ctx == NULL)
return 0;
ctx->cont = 1;
ctx->sigio = 1;
ctx->md = EVP_MD_CTX_new();
if (ctx->md == NULL) {
OPENSSL_free(ctx);
return 0;
}
BIO_set_init(bi, 0);
BIO_set_data(bi, ctx);
return 1;
}
static int ok_free(BIO *a)
{
BIO_OK_CTX *ctx;
if (a == NULL)
return 0;
ctx = BIO_get_data(a);
EVP_MD_CTX_free(ctx->md);
OPENSSL_clear_free(ctx, sizeof(BIO_OK_CTX));
BIO_set_data(a, NULL);
BIO_set_init(a, 0);
return 1;
}
static int ok_read(BIO *b, char *out, int outl)
{
int ret = 0, i, n;
BIO_OK_CTX *ctx;
BIO *next;
if (out == NULL)
return 0;
ctx = BIO_get_data(b);
next = BIO_next(b);
if ((ctx == NULL) || (next == NULL) || (BIO_get_init(b) == 0))
return 0;
while (outl > 0) {
if (ctx->blockout) {
i = ctx->buf_len - ctx->buf_off;
if (i > outl)
i = outl;
memcpy(out, &(ctx->buf[ctx->buf_off]), i);
ret += i;
out += i;
outl -= i;
ctx->buf_off += i;
if (ctx->buf_len == ctx->buf_off) {
ctx->buf_off = 0;
if (ctx->buf_len_save - ctx->buf_off_save > 0) {
ctx->buf_len = ctx->buf_len_save - ctx->buf_off_save;
memmove(ctx->buf, &(ctx->buf[ctx->buf_off_save]),
ctx->buf_len);
} else {
ctx->buf_len = 0;
}
ctx->blockout = 0;
}
}
if (outl == 0)
break;
n = IOBS - ctx->buf_len;
i = BIO_read(next, &(ctx->buf[ctx->buf_len]), n);
if (i <= 0)
break;
ctx->buf_len += i;
if (ctx->sigio == 1) {
if (!sig_in(b)) {
BIO_clear_retry_flags(b);
return 0;
}
}
if (ctx->sigio == 0) {
if (!block_in(b)) {
BIO_clear_retry_flags(b);
return 0;
}
}
if (ctx->cont <= 0)
break;
}
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return ret;
}
static int ok_write(BIO *b, const char *in, int inl)
{
int ret = 0, n, i;
BIO_OK_CTX *ctx;
BIO *next;
if (inl <= 0)
return inl;
ctx = BIO_get_data(b);
next = BIO_next(b);
ret = inl;
if ((ctx == NULL) || (next == NULL) || (BIO_get_init(b) == 0))
return (0);
if (ctx->sigio && !sig_out(b))
return 0;
do {
BIO_clear_retry_flags(b);
n = ctx->buf_len - ctx->buf_off;
while (ctx->blockout && n > 0) {
i = BIO_write(next, &(ctx->buf[ctx->buf_off]), n);
if (i <= 0) {
BIO_copy_next_retry(b);
if (!BIO_should_retry(b))
ctx->cont = 0;
return (i);
}
ctx->buf_off += i;
n -= i;
}
ctx->blockout = 0;
if (ctx->buf_len == ctx->buf_off) {
ctx->buf_len = OK_BLOCK_BLOCK;
ctx->buf_off = 0;
}
if ((in == NULL) || (inl <= 0))
return (0);
n = (inl + ctx->buf_len > OK_BLOCK_SIZE + OK_BLOCK_BLOCK) ?
(int)(OK_BLOCK_SIZE + OK_BLOCK_BLOCK - ctx->buf_len) : inl;
memcpy(&ctx->buf[ctx->buf_len], in, n);
ctx->buf_len += n;
inl -= n;
in += n;
if (ctx->buf_len >= OK_BLOCK_SIZE + OK_BLOCK_BLOCK) {
if (!block_out(b)) {
BIO_clear_retry_flags(b);
return 0;
}
}
} while (inl > 0);
BIO_clear_retry_flags(b);
BIO_copy_next_retry(b);
return (ret);
}
static long ok_ctrl(BIO *b, int cmd, long num, void *ptr)
{
BIO_OK_CTX *ctx;
EVP_MD *md;
const EVP_MD **ppmd;
long ret = 1;
int i;
BIO *next;
ctx = BIO_get_data(b);
next = BIO_next(b);
switch (cmd) {
case BIO_CTRL_RESET:
ctx->buf_len = 0;
ctx->buf_off = 0;
ctx->buf_len_save = 0;
ctx->buf_off_save = 0;
ctx->cont = 1;
ctx->finished = 0;
ctx->blockout = 0;
ctx->sigio = 1;
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_CTRL_EOF:
if (ctx->cont <= 0)
ret = 1;
else
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_CTRL_PENDING:
case BIO_CTRL_WPENDING:
ret = ctx->blockout ? ctx->buf_len - ctx->buf_off : 0;
if (ret <= 0)
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_CTRL_FLUSH:
if (ctx->blockout == 0)
if (!block_out(b))
return 0;
while (ctx->blockout) {
i = ok_write(b, NULL, 0);
if (i < 0) {
ret = i;
break;
}
}
ctx->finished = 1;
ctx->buf_off = ctx->buf_len = 0;
ctx->cont = (int)ret;
ret = BIO_ctrl(next, cmd, num, ptr);
break;
case BIO_C_DO_STATE_MACHINE:
BIO_clear_retry_flags(b);
ret = BIO_ctrl(next, cmd, num, ptr);
BIO_copy_next_retry(b);
break;
case BIO_CTRL_INFO:
ret = (long)ctx->cont;
break;
case BIO_C_SET_MD:
md = ptr;
if (!EVP_DigestInit_ex(ctx->md, md, NULL))
return 0;
BIO_set_init(b, 1);
break;
case BIO_C_GET_MD:
if (BIO_get_init(b)) {
ppmd = ptr;
*ppmd = EVP_MD_CTX_md(ctx->md);
} else
ret = 0;
break;
default:
ret = BIO_ctrl(next, cmd, num, ptr);
break;
}
return ret;
}
static long ok_callback_ctrl(BIO *b, int cmd, bio_info_cb *fp)
{
long ret = 1;
BIO *next;
next = BIO_next(b);
if (next == NULL)
return 0;
switch (cmd) {
default:
ret = BIO_callback_ctrl(next, cmd, fp);
break;
}
return ret;
}
static void longswap(void *_ptr, size_t len)
{
const union {
long one;
char little;
} is_endian = {
1
};
if (is_endian.little) {
size_t i;
unsigned char *p = _ptr, c;
for (i = 0; i < len; i += 4) {
c = p[0], p[0] = p[3], p[3] = c;
c = p[1], p[1] = p[2], p[2] = c;
}
}
}
static int sig_out(BIO *b)
{
BIO_OK_CTX *ctx;
EVP_MD_CTX *md;
const EVP_MD *digest;
int md_size;
void *md_data;
ctx = BIO_get_data(b);
md = ctx->md;
digest = EVP_MD_CTX_md(md);
md_size = EVP_MD_size(digest);
md_data = EVP_MD_CTX_md_data(md);
if (ctx->buf_len + 2 * md_size > OK_BLOCK_SIZE)
return 1;
if (!EVP_DigestInit_ex(md, digest, NULL))
goto berr;
if (RAND_bytes(md_data, md_size) <= 0)
goto berr;
memcpy(&(ctx->buf[ctx->buf_len]), md_data, md_size);
longswap(&(ctx->buf[ctx->buf_len]), md_size);
ctx->buf_len += md_size;
if (!EVP_DigestUpdate(md, WELLKNOWN, strlen(WELLKNOWN)))
goto berr;
if (!EVP_DigestFinal_ex(md, &(ctx->buf[ctx->buf_len]), NULL))
goto berr;
ctx->buf_len += md_size;
ctx->blockout = 1;
ctx->sigio = 0;
return 1;
berr:
BIO_clear_retry_flags(b);
return 0;
}
static int sig_in(BIO *b)
{
BIO_OK_CTX *ctx;
EVP_MD_CTX *md;
unsigned char tmp[EVP_MAX_MD_SIZE];
int ret = 0;
const EVP_MD *digest;
int md_size;
void *md_data;
ctx = BIO_get_data(b);
md = ctx->md;
digest = EVP_MD_CTX_md(md);
md_size = EVP_MD_size(digest);
md_data = EVP_MD_CTX_md_data(md);
if ((int)(ctx->buf_len - ctx->buf_off) < 2 * md_size)
return 1;
if (!EVP_DigestInit_ex(md, digest, NULL))
goto berr;
memcpy(md_data, &(ctx->buf[ctx->buf_off]), md_size);
longswap(md_data, md_size);
ctx->buf_off += md_size;
if (!EVP_DigestUpdate(md, WELLKNOWN, strlen(WELLKNOWN)))
goto berr;
if (!EVP_DigestFinal_ex(md, tmp, NULL))
goto berr;
ret = memcmp(&(ctx->buf[ctx->buf_off]), tmp, md_size) == 0;
ctx->buf_off += md_size;
if (ret == 1) {
ctx->sigio = 0;
if (ctx->buf_len != ctx->buf_off) {
memmove(ctx->buf, &(ctx->buf[ctx->buf_off]),
ctx->buf_len - ctx->buf_off);
}
ctx->buf_len -= ctx->buf_off;
ctx->buf_off = 0;
} else {
ctx->cont = 0;
}
return 1;
berr:
BIO_clear_retry_flags(b);
return 0;
}
static int block_out(BIO *b)
{
BIO_OK_CTX *ctx;
EVP_MD_CTX *md;
unsigned long tl;
const EVP_MD *digest;
int md_size;
ctx = BIO_get_data(b);
md = ctx->md;
digest = EVP_MD_CTX_md(md);
md_size = EVP_MD_size(digest);
tl = ctx->buf_len - OK_BLOCK_BLOCK;
ctx->buf[0] = (unsigned char)(tl >> 24);
ctx->buf[1] = (unsigned char)(tl >> 16);
ctx->buf[2] = (unsigned char)(tl >> 8);
ctx->buf[3] = (unsigned char)(tl);
if (!EVP_DigestUpdate(md,
(unsigned char *)&(ctx->buf[OK_BLOCK_BLOCK]), tl))
goto berr;
if (!EVP_DigestFinal_ex(md, &(ctx->buf[ctx->buf_len]), NULL))
goto berr;
ctx->buf_len += md_size;
ctx->blockout = 1;
return 1;
berr:
BIO_clear_retry_flags(b);
return 0;
}
static int block_in(BIO *b)
{
BIO_OK_CTX *ctx;
EVP_MD_CTX *md;
unsigned long tl = 0;
unsigned char tmp[EVP_MAX_MD_SIZE];
int md_size;
ctx = BIO_get_data(b);
md = ctx->md;
md_size = EVP_MD_size(EVP_MD_CTX_md(md));
assert(sizeof(tl) >= OK_BLOCK_BLOCK);
tl = ctx->buf[0];
tl <<= 8;
tl |= ctx->buf[1];
tl <<= 8;
tl |= ctx->buf[2];
tl <<= 8;
tl |= ctx->buf[3];
if (ctx->buf_len < tl + OK_BLOCK_BLOCK + md_size)
return 1;
if (!EVP_DigestUpdate(md,
(unsigned char *)&(ctx->buf[OK_BLOCK_BLOCK]), tl))
goto berr;
if (!EVP_DigestFinal_ex(md, tmp, NULL))
goto berr;
if (memcmp(&(ctx->buf[tl + OK_BLOCK_BLOCK]), tmp, md_size) == 0) {
ctx->buf_off_save = tl + OK_BLOCK_BLOCK + md_size;
ctx->buf_len_save = ctx->buf_len;
ctx->buf_off = OK_BLOCK_BLOCK;
ctx->buf_len = tl + OK_BLOCK_BLOCK;
ctx->blockout = 1;
} else {
ctx->cont = 0;
}
return 1;
berr:
BIO_clear_retry_flags(b);
return 0;
}
