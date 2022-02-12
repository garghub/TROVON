void EVP_MD_CTX_init(EVP_MD_CTX *ctx)
{
memset(ctx,'\0',sizeof *ctx);
}
EVP_MD_CTX *EVP_MD_CTX_create(void)
{
EVP_MD_CTX *ctx=OPENSSL_malloc(sizeof *ctx);
EVP_MD_CTX_init(ctx);
return ctx;
}
int EVP_DigestInit(EVP_MD_CTX *ctx, const EVP_MD *type)
{
EVP_MD_CTX_init(ctx);
return EVP_DigestInit_ex(ctx, type, NULL);
}
int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, ENGINE *impl)
{
EVP_MD_CTX_clear_flags(ctx,EVP_MD_CTX_FLAG_CLEANED);
if (ctx->engine && ctx->digest && (!type ||
(type && (type->type == ctx->digest->type))))
goto skip_to_init;
if (type)
{
if(ctx->engine)
ENGINE_finish(ctx->engine);
if(impl)
{
if (!ENGINE_init(impl))
{
EVPerr(EVP_F_EVP_DIGESTINIT, EVP_R_INITIALIZATION_ERROR);
return 0;
}
}
else
impl = ENGINE_get_digest_engine(type->type);
if(impl)
{
const EVP_MD *d = ENGINE_get_digest(impl, type->type);
if(!d)
{
EVPerr(EVP_F_EVP_DIGESTINIT, EVP_R_INITIALIZATION_ERROR);
return 0;
}
type = d;
ctx->engine = impl;
}
else
ctx->engine = NULL;
}
else if(!ctx->digest)
{
EVPerr(EVP_F_EVP_DIGESTINIT, EVP_R_NO_DIGEST_SET);
return 0;
}
if (ctx->digest != type)
{
if (ctx->digest && ctx->digest->ctx_size)
OPENSSL_free(ctx->md_data);
ctx->digest=type;
if (type->ctx_size)
ctx->md_data=OPENSSL_malloc(type->ctx_size);
}
skip_to_init:
return ctx->digest->init(ctx);
}
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *data,
unsigned int count)
{
return ctx->digest->update(ctx,data,(unsigned long)count);
}
int EVP_DigestFinal(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *size)
{
int ret;
ret = EVP_DigestFinal_ex(ctx, md, size);
EVP_MD_CTX_cleanup(ctx);
return ret;
}
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *size)
{
int ret;
OPENSSL_assert(ctx->digest->md_size <= EVP_MAX_MD_SIZE);
ret=ctx->digest->final(ctx,md);
if (size != NULL)
*size=ctx->digest->md_size;
if (ctx->digest->cleanup)
{
ctx->digest->cleanup(ctx);
EVP_MD_CTX_set_flags(ctx,EVP_MD_CTX_FLAG_CLEANED);
}
memset(ctx->md_data,0,ctx->digest->ctx_size);
return ret;
}
int EVP_MD_CTX_copy(EVP_MD_CTX *out, const EVP_MD_CTX *in)
{
EVP_MD_CTX_init(out);
return EVP_MD_CTX_copy_ex(out, in);
}
int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out, const EVP_MD_CTX *in)
{
if ((in == NULL) || (in->digest == NULL))
{
EVPerr(EVP_F_EVP_MD_CTX_COPY,EVP_R_INPUT_NOT_INITIALIZED);
return 0;
}
if (in->engine && !ENGINE_init(in->engine))
{
EVPerr(EVP_F_EVP_MD_CTX_COPY,ERR_R_ENGINE_LIB);
return 0;
}
EVP_MD_CTX_cleanup(out);
memcpy(out,in,sizeof *out);
if (out->digest->ctx_size)
{
out->md_data=OPENSSL_malloc(out->digest->ctx_size);
memcpy(out->md_data,in->md_data,out->digest->ctx_size);
}
if (out->digest->copy)
return out->digest->copy(out,in);
return 1;
}
int EVP_Digest(void *data, unsigned int count,
unsigned char *md, unsigned int *size, const EVP_MD *type, ENGINE *impl)
{
EVP_MD_CTX ctx;
int ret;
EVP_MD_CTX_init(&ctx);
EVP_MD_CTX_set_flags(&ctx,EVP_MD_CTX_FLAG_ONESHOT);
ret=EVP_DigestInit_ex(&ctx, type, impl)
&& EVP_DigestUpdate(&ctx, data, count)
&& EVP_DigestFinal_ex(&ctx, md, size);
EVP_MD_CTX_cleanup(&ctx);
return ret;
}
void EVP_MD_CTX_destroy(EVP_MD_CTX *ctx)
{
EVP_MD_CTX_cleanup(ctx);
OPENSSL_free(ctx);
}
int EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx)
{
if (ctx->digest && ctx->digest->cleanup
&& !EVP_MD_CTX_test_flags(ctx,EVP_MD_CTX_FLAG_CLEANED))
ctx->digest->cleanup(ctx);
if (ctx->digest && ctx->digest->ctx_size && ctx->md_data)
{
OPENSSL_cleanse(ctx->md_data,ctx->digest->ctx_size);
OPENSSL_free(ctx->md_data);
}
if(ctx->engine)
ENGINE_finish(ctx->engine);
memset(ctx,'\0',sizeof *ctx);
return 1;
}
