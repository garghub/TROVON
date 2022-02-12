int gost_digest_init(EVP_MD_CTX *ctx)
{
struct ossl_gost_digest_ctx *c = ctx->md_data;
memset(&(c->dctx),0,sizeof(gost_hash_ctx));
gost_init(&(c->cctx),&GostR3411_94_CryptoProParamSet);
c->dctx.cipher_ctx= &(c->cctx);
return 1;
}
int gost_digest_update(EVP_MD_CTX *ctx,const void *data,size_t count)
{
return hash_block((gost_hash_ctx *)ctx->md_data,data,count);
}
int gost_digest_final(EVP_MD_CTX *ctx,unsigned char *md)
{
return finish_hash((gost_hash_ctx *)ctx->md_data,md);
}
int gost_digest_copy(EVP_MD_CTX *to,const EVP_MD_CTX *from)
{
struct ossl_gost_digest_ctx *md_ctx=to->md_data;
if (to->md_data && from->md_data) {
memcpy(to->md_data,from->md_data,sizeof(struct ossl_gost_digest_ctx));
md_ctx->dctx.cipher_ctx=&(md_ctx->cctx);
}
return 1;
}
int gost_digest_cleanup(EVP_MD_CTX *ctx)
{
if (ctx->md_data)
memset(ctx->md_data,0,sizeof(struct ossl_gost_digest_ctx));
return 1;
}
