static void *zlib_zalloc(void *opaque, unsigned int no, unsigned int size)
{
void *p;
p = OPENSSL_zalloc(no * size);
return p;
}
static void zlib_zfree(void *opaque, void *address)
{
OPENSSL_free(address);
}
static int zlib_stateful_init(COMP_CTX *ctx)
{
int err;
struct zlib_state *state = OPENSSL_zalloc(sizeof(*state));
if (state == NULL)
goto err;
state->istream.zalloc = zlib_zalloc;
state->istream.zfree = zlib_zfree;
state->istream.opaque = Z_NULL;
state->istream.next_in = Z_NULL;
state->istream.next_out = Z_NULL;
err = inflateInit_(&state->istream, ZLIB_VERSION, sizeof(z_stream));
if (err != Z_OK)
goto err;
state->ostream.zalloc = zlib_zalloc;
state->ostream.zfree = zlib_zfree;
state->ostream.opaque = Z_NULL;
state->ostream.next_in = Z_NULL;
state->ostream.next_out = Z_NULL;
err = deflateInit_(&state->ostream, Z_DEFAULT_COMPRESSION,
ZLIB_VERSION, sizeof(z_stream));
if (err != Z_OK)
goto err;
ctx->data = state;
return 1;
err:
OPENSSL_free(state);
return 0;
}
static void zlib_stateful_finish(COMP_CTX *ctx)
{
struct zlib_state *state = ctx->data;
inflateEnd(&state->istream);
deflateEnd(&state->ostream);
OPENSSL_free(state);
}
static int zlib_stateful_compress_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in,
unsigned int ilen)
{
int err = Z_OK;
struct zlib_state *state = ctx->data;
if (state == NULL)
return -1;
state->ostream.next_in = in;
state->ostream.avail_in = ilen;
state->ostream.next_out = out;
state->ostream.avail_out = olen;
if (ilen > 0)
err = deflate(&state->ostream, Z_SYNC_FLUSH);
if (err != Z_OK)
return -1;
return olen - state->ostream.avail_out;
}
static int zlib_stateful_expand_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in,
unsigned int ilen)
{
int err = Z_OK;
struct zlib_state *state = ctx->data;
if (state == NULL)
return 0;
state->istream.next_in = in;
state->istream.avail_in = ilen;
state->istream.next_out = out;
state->istream.avail_out = olen;
if (ilen > 0)
err = inflate(&state->istream, Z_SYNC_FLUSH);
if (err != Z_OK)
return -1;
return olen - state->istream.avail_out;
}
COMP_METHOD *COMP_zlib(void)
{
COMP_METHOD *meth = &zlib_method_nozlib;
#ifdef ZLIB_SHARED
# ifndef LIBZ
# if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32)
# define LIBZ "ZLIB1"
# elif defined(OPENSSL_SYS_VMS)
# define LIBZ "LIBZ"
# else
# define LIBZ "z"
# endif
# endif
if (!zlib_loaded) {
zlib_dso = DSO_load(NULL, LIBZ, NULL, 0);
if (zlib_dso != NULL) {
p_compress = (compress_ft) DSO_bind_func(zlib_dso, "compress");
p_inflateEnd
= (inflateEnd_ft) DSO_bind_func(zlib_dso, "inflateEnd");
p_inflate = (inflate_ft) DSO_bind_func(zlib_dso, "inflate");
p_inflateInit_
= (inflateInit__ft) DSO_bind_func(zlib_dso, "inflateInit_");
p_deflateEnd
= (deflateEnd_ft) DSO_bind_func(zlib_dso, "deflateEnd");
p_deflate = (deflate_ft) DSO_bind_func(zlib_dso, "deflate");
p_deflateInit_
= (deflateInit__ft) DSO_bind_func(zlib_dso, "deflateInit_");
p_zError = (zError__ft) DSO_bind_func(zlib_dso, "zError");
if (p_compress && p_inflateEnd && p_inflate
&& p_inflateInit_ && p_deflateEnd
&& p_deflate && p_deflateInit_ && p_zError)
zlib_loaded++;
if (!OPENSSL_init_crypto(OPENSSL_INIT_ZLIB, NULL)) {
comp_zlib_cleanup_int();
return meth;
}
if (zlib_loaded)
meth = &zlib_stateful_method;
}
}
#endif
#if defined(ZLIB)
meth = &zlib_stateful_method;
#endif
return (meth);
}
void comp_zlib_cleanup_int(void)
{
#ifdef ZLIB_SHARED
if (zlib_dso != NULL)
DSO_free(zlib_dso);
zlib_dso = NULL;
#endif
}
const BIO_METHOD *BIO_f_zlib(void)
{
return &bio_meth_zlib;
}
static int bio_zlib_new(BIO *bi)
{
BIO_ZLIB_CTX *ctx;
# ifdef ZLIB_SHARED
(void)COMP_zlib();
if (!zlib_loaded) {
COMPerr(COMP_F_BIO_ZLIB_NEW, COMP_R_ZLIB_NOT_SUPPORTED);
return 0;
}
# endif
ctx = OPENSSL_zalloc(sizeof(*ctx));
if (ctx == NULL) {
COMPerr(COMP_F_BIO_ZLIB_NEW, ERR_R_MALLOC_FAILURE);
return 0;
}
ctx->ibufsize = ZLIB_DEFAULT_BUFSIZE;
ctx->obufsize = ZLIB_DEFAULT_BUFSIZE;
ctx->zin.zalloc = Z_NULL;
ctx->zin.zfree = Z_NULL;
ctx->zout.zalloc = Z_NULL;
ctx->zout.zfree = Z_NULL;
ctx->comp_level = Z_DEFAULT_COMPRESSION;
BIO_set_init(bi, 1);
BIO_set_data(bi, ctx);
return 1;
}
static int bio_zlib_free(BIO *bi)
{
BIO_ZLIB_CTX *ctx;
if (!bi)
return 0;
ctx = BIO_get_data(bi);
if (ctx->ibuf) {
inflateEnd(&ctx->zin);
OPENSSL_free(ctx->ibuf);
}
if (ctx->obuf) {
deflateEnd(&ctx->zout);
OPENSSL_free(ctx->obuf);
}
OPENSSL_free(ctx);
BIO_set_data(bi, NULL);
BIO_set_init(bi, 0);
return 1;
}
static int bio_zlib_read(BIO *b, char *out, int outl)
{
BIO_ZLIB_CTX *ctx;
int ret;
z_stream *zin;
BIO *next = BIO_next(b);
if (!out || !outl)
return 0;
ctx = BIO_get_data(b);
zin = &ctx->zin;
BIO_clear_retry_flags(b);
if (!ctx->ibuf) {
ctx->ibuf = OPENSSL_malloc(ctx->ibufsize);
if (ctx->ibuf == NULL) {
COMPerr(COMP_F_BIO_ZLIB_READ, ERR_R_MALLOC_FAILURE);
return 0;
}
inflateInit(zin);
zin->next_in = ctx->ibuf;
zin->avail_in = 0;
}
zin->next_out = (unsigned char *)out;
zin->avail_out = (unsigned int)outl;
for (;;) {
while (zin->avail_in) {
ret = inflate(zin, 0);
if ((ret != Z_OK) && (ret != Z_STREAM_END)) {
COMPerr(COMP_F_BIO_ZLIB_READ, COMP_R_ZLIB_INFLATE_ERROR);
ERR_add_error_data(2, "zlib error:", zError(ret));
return 0;
}
if ((ret == Z_STREAM_END) || !zin->avail_out)
return outl - zin->avail_out;
}
ret = BIO_read(next, ctx->ibuf, ctx->ibufsize);
if (ret <= 0) {
int tot = outl - zin->avail_out;
BIO_copy_next_retry(b);
if (ret < 0)
return (tot > 0) ? tot : ret;
return tot;
}
zin->avail_in = ret;
zin->next_in = ctx->ibuf;
}
}
static int bio_zlib_write(BIO *b, const char *in, int inl)
{
BIO_ZLIB_CTX *ctx;
int ret;
z_stream *zout;
BIO *next = BIO_next(b);
if (!in || !inl)
return 0;
ctx = BIO_get_data(b);
if (ctx->odone)
return 0;
zout = &ctx->zout;
BIO_clear_retry_flags(b);
if (!ctx->obuf) {
ctx->obuf = OPENSSL_malloc(ctx->obufsize);
if (ctx->obuf == NULL) {
COMPerr(COMP_F_BIO_ZLIB_WRITE, ERR_R_MALLOC_FAILURE);
return 0;
}
ctx->optr = ctx->obuf;
ctx->ocount = 0;
deflateInit(zout, ctx->comp_level);
zout->next_out = ctx->obuf;
zout->avail_out = ctx->obufsize;
}
zout->next_in = (void *)in;
zout->avail_in = inl;
for (;;) {
while (ctx->ocount) {
ret = BIO_write(next, ctx->optr, ctx->ocount);
if (ret <= 0) {
int tot = inl - zout->avail_in;
BIO_copy_next_retry(b);
if (ret < 0)
return (tot > 0) ? tot : ret;
return tot;
}
ctx->optr += ret;
ctx->ocount -= ret;
}
if (!zout->avail_in)
return inl;
ctx->optr = ctx->obuf;
zout->next_out = ctx->obuf;
zout->avail_out = ctx->obufsize;
ret = deflate(zout, 0);
if (ret != Z_OK) {
COMPerr(COMP_F_BIO_ZLIB_WRITE, COMP_R_ZLIB_DEFLATE_ERROR);
ERR_add_error_data(2, "zlib error:", zError(ret));
return 0;
}
ctx->ocount = ctx->obufsize - zout->avail_out;
}
}
static int bio_zlib_flush(BIO *b)
{
BIO_ZLIB_CTX *ctx;
int ret;
z_stream *zout;
BIO *next = BIO_next(b);
ctx = BIO_get_data(b);
if (!ctx->obuf || (ctx->odone && !ctx->ocount))
return 1;
zout = &ctx->zout;
BIO_clear_retry_flags(b);
zout->next_in = NULL;
zout->avail_in = 0;
for (;;) {
while (ctx->ocount) {
ret = BIO_write(next, ctx->optr, ctx->ocount);
if (ret <= 0) {
BIO_copy_next_retry(b);
return ret;
}
ctx->optr += ret;
ctx->ocount -= ret;
}
if (ctx->odone)
return 1;
ctx->optr = ctx->obuf;
zout->next_out = ctx->obuf;
zout->avail_out = ctx->obufsize;
ret = deflate(zout, Z_FINISH);
if (ret == Z_STREAM_END)
ctx->odone = 1;
else if (ret != Z_OK) {
COMPerr(COMP_F_BIO_ZLIB_FLUSH, COMP_R_ZLIB_DEFLATE_ERROR);
ERR_add_error_data(2, "zlib error:", zError(ret));
return 0;
}
ctx->ocount = ctx->obufsize - zout->avail_out;
}
}
static long bio_zlib_ctrl(BIO *b, int cmd, long num, void *ptr)
{
BIO_ZLIB_CTX *ctx;
int ret, *ip;
int ibs, obs;
BIO *next = BIO_next(b);
if (next == NULL)
return 0;
ctx = BIO_get_data(b);
switch (cmd) {
case BIO_CTRL_RESET:
ctx->ocount = 0;
ctx->odone = 0;
ret = 1;
break;
case BIO_CTRL_FLUSH:
ret = bio_zlib_flush(b);
if (ret > 0)
ret = BIO_flush(next);
break;
case BIO_C_SET_BUFF_SIZE:
ibs = -1;
obs = -1;
if (ptr != NULL) {
ip = ptr;
if (*ip == 0)
ibs = (int)num;
else
obs = (int)num;
} else {
ibs = (int)num;
obs = ibs;
}
if (ibs != -1) {
OPENSSL_free(ctx->ibuf);
ctx->ibuf = NULL;
ctx->ibufsize = ibs;
}
if (obs != -1) {
OPENSSL_free(ctx->obuf);
ctx->obuf = NULL;
ctx->obufsize = obs;
}
ret = 1;
break;
case BIO_C_DO_STATE_MACHINE:
BIO_clear_retry_flags(b);
ret = BIO_ctrl(next, cmd, num, ptr);
BIO_copy_next_retry(b);
break;
default:
ret = BIO_ctrl(next, cmd, num, ptr);
break;
}
return ret;
}
static long bio_zlib_callback_ctrl(BIO *b, int cmd, bio_info_cb *fp)
{
BIO *next = BIO_next(b);
if (next == NULL)
return 0;
return BIO_callback_ctrl(next, cmd, fp);
}
