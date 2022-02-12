BN_CTX *BN_CTX_new(void)
{
BN_CTX *ret;
ret=(BN_CTX *)Malloc(sizeof(BN_CTX));
if (ret == NULL)
{
BNerr(BN_F_BN_CTX_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
BN_CTX_init(ret);
ret->flags=BN_FLG_MALLOCED;
return(ret);
}
void BN_CTX_init(BN_CTX *ctx)
{
int i;
ctx->tos = 0;
ctx->flags = 0;
ctx->depth = 0;
ctx->too_many = 0;
for (i = 0; i < BN_CTX_NUM; i++)
BN_init(&(ctx->bn[i]));
}
void BN_CTX_free(BN_CTX *ctx)
{
int i;
if (ctx == NULL) return;
assert(ctx->depth == 0);
for (i=0; i < BN_CTX_NUM; i++)
BN_clear_free(&(ctx->bn[i]));
if (ctx->flags & BN_FLG_MALLOCED)
Free(ctx);
}
void BN_CTX_start(BN_CTX *ctx)
{
if (ctx->depth < BN_CTX_NUM_POS)
ctx->pos[ctx->depth] = ctx->tos;
ctx->depth++;
}
BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
if (ctx->depth > BN_CTX_NUM_POS || ctx->tos >= BN_CTX_NUM)
{
if (!ctx->too_many)
{
BNerr(BN_F_BN_CTX_GET,BN_R_TOO_MANY_TEMPORARY_VARIABLES);
ctx->too_many = 1;
}
return NULL;
}
return (&(ctx->bn[ctx->tos++]));
}
void BN_CTX_end(BN_CTX *ctx)
{
if (ctx == NULL) return;
assert(ctx->depth > 0);
if (ctx->depth == 0)
BN_CTX_start(ctx);
ctx->too_many = 0;
ctx->depth--;
if (ctx->depth < BN_CTX_NUM_POS)
ctx->tos = ctx->pos[ctx->depth];
}
