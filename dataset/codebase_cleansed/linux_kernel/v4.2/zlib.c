static void zlib_comp_exit(struct zlib_ctx *ctx)
{
struct z_stream_s *stream = &ctx->comp_stream;
if (stream->workspace) {
zlib_deflateEnd(stream);
vfree(stream->workspace);
stream->workspace = NULL;
}
}
static void zlib_decomp_exit(struct zlib_ctx *ctx)
{
struct z_stream_s *stream = &ctx->decomp_stream;
if (stream->workspace) {
zlib_inflateEnd(stream);
vfree(stream->workspace);
stream->workspace = NULL;
}
}
static int zlib_init(struct crypto_tfm *tfm)
{
return 0;
}
static void zlib_exit(struct crypto_tfm *tfm)
{
struct zlib_ctx *ctx = crypto_tfm_ctx(tfm);
zlib_comp_exit(ctx);
zlib_decomp_exit(ctx);
}
static int zlib_compress_setup(struct crypto_pcomp *tfm, const void *params,
unsigned int len)
{
struct zlib_ctx *ctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &ctx->comp_stream;
struct nlattr *tb[ZLIB_COMP_MAX + 1];
int window_bits, mem_level;
size_t workspacesize;
int ret;
ret = nla_parse(tb, ZLIB_COMP_MAX, params, len, NULL);
if (ret)
return ret;
zlib_comp_exit(ctx);
window_bits = tb[ZLIB_COMP_WINDOWBITS]
? nla_get_u32(tb[ZLIB_COMP_WINDOWBITS])
: MAX_WBITS;
mem_level = tb[ZLIB_COMP_MEMLEVEL]
? nla_get_u32(tb[ZLIB_COMP_MEMLEVEL])
: DEF_MEM_LEVEL;
workspacesize = zlib_deflate_workspacesize(window_bits, mem_level);
stream->workspace = vzalloc(workspacesize);
if (!stream->workspace)
return -ENOMEM;
ret = zlib_deflateInit2(stream,
tb[ZLIB_COMP_LEVEL]
? nla_get_u32(tb[ZLIB_COMP_LEVEL])
: Z_DEFAULT_COMPRESSION,
tb[ZLIB_COMP_METHOD]
? nla_get_u32(tb[ZLIB_COMP_METHOD])
: Z_DEFLATED,
window_bits,
mem_level,
tb[ZLIB_COMP_STRATEGY]
? nla_get_u32(tb[ZLIB_COMP_STRATEGY])
: Z_DEFAULT_STRATEGY);
if (ret != Z_OK) {
vfree(stream->workspace);
stream->workspace = NULL;
return -EINVAL;
}
return 0;
}
static int zlib_compress_init(struct crypto_pcomp *tfm)
{
int ret;
struct zlib_ctx *dctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &dctx->comp_stream;
ret = zlib_deflateReset(stream);
if (ret != Z_OK)
return -EINVAL;
return 0;
}
static int zlib_compress_update(struct crypto_pcomp *tfm,
struct comp_request *req)
{
int ret;
struct zlib_ctx *dctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &dctx->comp_stream;
pr_debug("avail_in %u, avail_out %u\n", req->avail_in, req->avail_out);
stream->next_in = req->next_in;
stream->avail_in = req->avail_in;
stream->next_out = req->next_out;
stream->avail_out = req->avail_out;
ret = zlib_deflate(stream, Z_NO_FLUSH);
switch (ret) {
case Z_OK:
break;
case Z_BUF_ERROR:
pr_debug("zlib_deflate could not make progress\n");
return -EAGAIN;
default:
pr_debug("zlib_deflate failed %d\n", ret);
return -EINVAL;
}
ret = req->avail_out - stream->avail_out;
pr_debug("avail_in %lu, avail_out %lu (consumed %lu, produced %u)\n",
stream->avail_in, stream->avail_out,
req->avail_in - stream->avail_in, ret);
req->next_in = stream->next_in;
req->avail_in = stream->avail_in;
req->next_out = stream->next_out;
req->avail_out = stream->avail_out;
return ret;
}
static int zlib_compress_final(struct crypto_pcomp *tfm,
struct comp_request *req)
{
int ret;
struct zlib_ctx *dctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &dctx->comp_stream;
pr_debug("avail_in %u, avail_out %u\n", req->avail_in, req->avail_out);
stream->next_in = req->next_in;
stream->avail_in = req->avail_in;
stream->next_out = req->next_out;
stream->avail_out = req->avail_out;
ret = zlib_deflate(stream, Z_FINISH);
if (ret != Z_STREAM_END) {
pr_debug("zlib_deflate failed %d\n", ret);
return -EINVAL;
}
ret = req->avail_out - stream->avail_out;
pr_debug("avail_in %lu, avail_out %lu (consumed %lu, produced %u)\n",
stream->avail_in, stream->avail_out,
req->avail_in - stream->avail_in, ret);
req->next_in = stream->next_in;
req->avail_in = stream->avail_in;
req->next_out = stream->next_out;
req->avail_out = stream->avail_out;
return ret;
}
static int zlib_decompress_setup(struct crypto_pcomp *tfm, const void *params,
unsigned int len)
{
struct zlib_ctx *ctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &ctx->decomp_stream;
struct nlattr *tb[ZLIB_DECOMP_MAX + 1];
int ret = 0;
ret = nla_parse(tb, ZLIB_DECOMP_MAX, params, len, NULL);
if (ret)
return ret;
zlib_decomp_exit(ctx);
ctx->decomp_windowBits = tb[ZLIB_DECOMP_WINDOWBITS]
? nla_get_u32(tb[ZLIB_DECOMP_WINDOWBITS])
: DEF_WBITS;
stream->workspace = vzalloc(zlib_inflate_workspacesize());
if (!stream->workspace)
return -ENOMEM;
ret = zlib_inflateInit2(stream, ctx->decomp_windowBits);
if (ret != Z_OK) {
vfree(stream->workspace);
stream->workspace = NULL;
return -EINVAL;
}
return 0;
}
static int zlib_decompress_init(struct crypto_pcomp *tfm)
{
int ret;
struct zlib_ctx *dctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &dctx->decomp_stream;
ret = zlib_inflateReset(stream);
if (ret != Z_OK)
return -EINVAL;
return 0;
}
static int zlib_decompress_update(struct crypto_pcomp *tfm,
struct comp_request *req)
{
int ret;
struct zlib_ctx *dctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &dctx->decomp_stream;
pr_debug("avail_in %u, avail_out %u\n", req->avail_in, req->avail_out);
stream->next_in = req->next_in;
stream->avail_in = req->avail_in;
stream->next_out = req->next_out;
stream->avail_out = req->avail_out;
ret = zlib_inflate(stream, Z_SYNC_FLUSH);
switch (ret) {
case Z_OK:
case Z_STREAM_END:
break;
case Z_BUF_ERROR:
pr_debug("zlib_inflate could not make progress\n");
return -EAGAIN;
default:
pr_debug("zlib_inflate failed %d\n", ret);
return -EINVAL;
}
ret = req->avail_out - stream->avail_out;
pr_debug("avail_in %lu, avail_out %lu (consumed %lu, produced %u)\n",
stream->avail_in, stream->avail_out,
req->avail_in - stream->avail_in, ret);
req->next_in = stream->next_in;
req->avail_in = stream->avail_in;
req->next_out = stream->next_out;
req->avail_out = stream->avail_out;
return ret;
}
static int zlib_decompress_final(struct crypto_pcomp *tfm,
struct comp_request *req)
{
int ret;
struct zlib_ctx *dctx = crypto_tfm_ctx(crypto_pcomp_tfm(tfm));
struct z_stream_s *stream = &dctx->decomp_stream;
pr_debug("avail_in %u, avail_out %u\n", req->avail_in, req->avail_out);
stream->next_in = req->next_in;
stream->avail_in = req->avail_in;
stream->next_out = req->next_out;
stream->avail_out = req->avail_out;
if (dctx->decomp_windowBits < 0) {
ret = zlib_inflate(stream, Z_SYNC_FLUSH);
if (ret == Z_OK && !stream->avail_in && stream->avail_out) {
const void *saved_next_in = stream->next_in;
u8 zerostuff = 0;
stream->next_in = &zerostuff;
stream->avail_in = 1;
ret = zlib_inflate(stream, Z_FINISH);
stream->next_in = saved_next_in;
stream->avail_in = 0;
}
} else
ret = zlib_inflate(stream, Z_FINISH);
if (ret != Z_STREAM_END) {
pr_debug("zlib_inflate failed %d\n", ret);
return -EINVAL;
}
ret = req->avail_out - stream->avail_out;
pr_debug("avail_in %lu, avail_out %lu (consumed %lu, produced %u)\n",
stream->avail_in, stream->avail_out,
req->avail_in - stream->avail_in, ret);
req->next_in = stream->next_in;
req->avail_in = stream->avail_in;
req->next_out = stream->next_out;
req->avail_out = stream->avail_out;
return ret;
}
static int __init zlib_mod_init(void)
{
return crypto_register_pcomp(&zlib_alg);
}
static void __exit zlib_mod_fini(void)
{
crypto_unregister_pcomp(&zlib_alg);
}
