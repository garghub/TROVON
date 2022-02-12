static int init(EVP_MD_CTX *ctx)
{
return MD2_Init(ctx->md_data);
}
static int update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
return MD2_Update(ctx->md_data, data, count);
}
static int final(EVP_MD_CTX *ctx, unsigned char *md)
{
return MD2_Final(md, ctx->md_data);
}
const EVP_MD *EVP_md2(void)
{
return (&md2_md);
}
