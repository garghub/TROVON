CT_POLICY_EVAL_CTX *CT_POLICY_EVAL_CTX_new(void)
{
CT_POLICY_EVAL_CTX *ctx = OPENSSL_zalloc(sizeof(CT_POLICY_EVAL_CTX));
if (ctx == NULL) {
CTerr(CT_F_CT_POLICY_EVAL_CTX_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
return ctx;
}
void CT_POLICY_EVAL_CTX_free(CT_POLICY_EVAL_CTX *ctx)
{
if (ctx == NULL)
return;
X509_free(ctx->cert);
X509_free(ctx->issuer);
OPENSSL_free(ctx);
}
int CT_POLICY_EVAL_CTX_set1_cert(CT_POLICY_EVAL_CTX *ctx, X509 *cert)
{
if (!X509_up_ref(cert))
return 0;
ctx->cert = cert;
return 1;
}
int CT_POLICY_EVAL_CTX_set1_issuer(CT_POLICY_EVAL_CTX *ctx, X509 *issuer)
{
if (!X509_up_ref(issuer))
return 0;
ctx->issuer = issuer;
return 1;
}
void CT_POLICY_EVAL_CTX_set_shared_CTLOG_STORE(CT_POLICY_EVAL_CTX *ctx,
CTLOG_STORE *log_store)
{
ctx->log_store = log_store;
}
X509* CT_POLICY_EVAL_CTX_get0_cert(const CT_POLICY_EVAL_CTX *ctx)
{
return ctx->cert;
}
X509* CT_POLICY_EVAL_CTX_get0_issuer(const CT_POLICY_EVAL_CTX *ctx)
{
return ctx->issuer;
}
const CTLOG_STORE *CT_POLICY_EVAL_CTX_get0_log_store(const CT_POLICY_EVAL_CTX *ctx)
{
return ctx->log_store;
}
