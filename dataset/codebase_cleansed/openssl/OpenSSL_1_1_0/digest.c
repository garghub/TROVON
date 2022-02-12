int EVP_MD_CTX_reset(EVP_MD_CTX *ctx)
{
if (ctx == NULL)
return 1;
if (ctx->digest && ctx->digest->cleanup
&& !EVP_MD_CTX_test_flags(ctx, EVP_MD_CTX_FLAG_CLEANED))
ctx->digest->cleanup(ctx);
if (ctx->digest && ctx->digest->ctx_size && ctx->md_data
&& !EVP_MD_CTX_test_flags(ctx, EVP_MD_CTX_FLAG_REUSE)) {
OPENSSL_clear_free(ctx->md_data, ctx->digest->ctx_size);
}
EVP_PKEY_CTX_free(ctx->pctx);
#ifndef OPENSSL_NO_ENGINE
ENGINE_finish(ctx->engine);
#endif
OPENSSL_cleanse(ctx, sizeof(*ctx));
return 1;
}
EVP_MD_CTX *EVP_MD_CTX_new(void)
{
return OPENSSL_zalloc(sizeof(EVP_MD_CTX));
}
void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
{
EVP_MD_CTX_reset(ctx);
OPENSSL_free(ctx);
}
int EVP_DigestInit(EVP_MD_CTX *ctx, const EVP_MD *type)
{
EVP_MD_CTX_reset(ctx);
return EVP_DigestInit_ex(ctx, type, NULL);
}
int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, ENGINE *impl)
{
EVP_MD_CTX_clear_flags(ctx, EVP_MD_CTX_FLAG_CLEANED);
#ifndef OPENSSL_NO_ENGINE
if (ctx->engine && ctx->digest &&
(type == NULL || (type->type == ctx->digest->type)))
goto skip_to_init;
if (type) {
ENGINE_finish(ctx->engine);
if (impl != NULL) {
if (!ENGINE_init(impl)) {
EVPerr(EVP_F_EVP_DIGESTINIT_EX, EVP_R_INITIALIZATION_ERROR);
return 0;
}
} else {
impl = ENGINE_get_digest_engine(type->type);
}
if (impl != NULL) {
const EVP_MD *d = ENGINE_get_digest(impl, type->type);
if (d == NULL) {
EVPerr(EVP_F_EVP_DIGESTINIT_EX, EVP_R_INITIALIZATION_ERROR);
ENGINE_finish(impl);
return 0;
}
type = d;
ctx->engine = impl;
} else
ctx->engine = NULL;
} else {
if (!ctx->digest) {
EVPerr(EVP_F_EVP_DIGESTINIT_EX, EVP_R_NO_DIGEST_SET);
return 0;
}
type = ctx->digest;
}
#endif
if (ctx->digest != type) {
if (ctx->digest && ctx->digest->ctx_size) {
OPENSSL_clear_free(ctx->md_data, ctx->digest->ctx_size);
ctx->md_data = NULL;
}
ctx->digest = type;
if (!(ctx->flags & EVP_MD_CTX_FLAG_NO_INIT) && type->ctx_size) {
ctx->update = type->update;
ctx->md_data = OPENSSL_zalloc(type->ctx_size);
if (ctx->md_data == NULL) {
EVPerr(EVP_F_EVP_DIGESTINIT_EX, ERR_R_MALLOC_FAILURE);
return 0;
}
}
}
#ifndef OPENSSL_NO_ENGINE
skip_to_init:
#endif
if (ctx->pctx) {
int r;
r = EVP_PKEY_CTX_ctrl(ctx->pctx, -1, EVP_PKEY_OP_TYPE_SIG,
EVP_PKEY_CTRL_DIGESTINIT, 0, ctx);
if (r <= 0 && (r != -2))
return 0;
}
if (ctx->flags & EVP_MD_CTX_FLAG_NO_INIT)
return 1;
return ctx->digest->init(ctx);
}
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return ctx->update(ctx, data, count);
}
int EVP_DigestFinal(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *size)
{
int ret;
ret = EVP_DigestFinal_ex(ctx, md, size);
EVP_MD_CTX_reset(ctx);
return ret;
}
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *size)
{
int ret;
OPENSSL_assert(ctx->digest->md_size <= EVP_MAX_MD_SIZE);
ret = ctx->digest->final(ctx, md);
if (size != NULL)
*size = ctx->digest->md_size;
if (ctx->digest->cleanup) {
ctx->digest->cleanup(ctx);
EVP_MD_CTX_set_flags(ctx, EVP_MD_CTX_FLAG_CLEANED);
}
OPENSSL_cleanse(ctx->md_data, ctx->digest->ctx_size);
return ret;
}
int EVP_MD_CTX_copy(EVP_MD_CTX *out, const EVP_MD_CTX *in)
{
EVP_MD_CTX_reset(out);
return EVP_MD_CTX_copy_ex(out, in);
}
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out, const EVP_MD_CTX *in)
{
unsigned char *tmp_buf;
if ((in == NULL) || (in->digest == NULL)) {
EVPerr(EVP_F_EVP_MD_CTX_COPY_EX, EVP_R_INPUT_NOT_INITIALIZED);
return 0;
}
#ifndef OPENSSL_NO_ENGINE
if (in->engine && !ENGINE_init(in->engine)) {
EVPerr(EVP_F_EVP_MD_CTX_COPY_EX, ERR_R_ENGINE_LIB);
return 0;
}
#endif
if (out->digest == in->digest) {
tmp_buf = out->md_data;
EVP_MD_CTX_set_flags(out, EVP_MD_CTX_FLAG_REUSE);
} else
tmp_buf = NULL;
EVP_MD_CTX_reset(out);
memcpy(out, in, sizeof(*out));
out->md_data = NULL;
out->pctx = NULL;
if (in->md_data && out->digest->ctx_size) {
if (tmp_buf)
out->md_data = tmp_buf;
else {
out->md_data = OPENSSL_malloc(out->digest->ctx_size);
if (out->md_data == NULL) {
EVPerr(EVP_F_EVP_MD_CTX_COPY_EX, ERR_R_MALLOC_FAILURE);
return 0;
}
}
memcpy(out->md_data, in->md_data, out->digest->ctx_size);
}
out->update = in->update;
if (in->pctx) {
out->pctx = EVP_PKEY_CTX_dup(in->pctx);
if (!out->pctx) {
EVP_MD_CTX_reset(out);
return 0;
}
}
if (out->digest->copy)
return out->digest->copy(out, in);
return 1;
}
int EVP_Digest(const void *data, size_t count,
unsigned char *md, unsigned int *size, const EVP_MD *type,
ENGINE *impl)
{
EVP_MD_CTX *ctx = EVP_MD_CTX_new();
int ret;
if (ctx == NULL)
return 0;
EVP_MD_CTX_set_flags(ctx, EVP_MD_CTX_FLAG_ONESHOT);
ret = EVP_DigestInit_ex(ctx, type, impl)
&& EVP_DigestUpdate(ctx, data, count)
&& EVP_DigestFinal_ex(ctx, md, size);
EVP_MD_CTX_free(ctx);
return ret;
}
int EVP_MD_CTX_ctrl(EVP_MD_CTX *ctx, int cmd, int p1, void *p2)
{
if (ctx->digest && ctx->digest->md_ctrl) {
int ret = ctx->digest->md_ctrl(ctx, cmd, p1, p2);
if (ret <= 0)
return 0;
return 1;
}
return 0;
}
