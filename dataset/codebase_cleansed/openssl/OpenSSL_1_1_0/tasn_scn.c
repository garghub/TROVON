ASN1_SCTX *ASN1_SCTX_new(int (*scan_cb) (ASN1_SCTX *ctx))
{
ASN1_SCTX *ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL) {
ASN1err(ASN1_F_ASN1_SCTX_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
ret->scan_cb = scan_cb;
return ret;
}
void ASN1_SCTX_free(ASN1_SCTX *p)
{
OPENSSL_free(p);
}
const ASN1_ITEM *ASN1_SCTX_get_item(ASN1_SCTX *p)
{
return p->it;
}
const ASN1_TEMPLATE *ASN1_SCTX_get_template(ASN1_SCTX *p)
{
return p->tt;
}
unsigned long ASN1_SCTX_get_flags(ASN1_SCTX *p)
{
return p->flags;
}
void ASN1_SCTX_set_app_data(ASN1_SCTX *p, void *data)
{
p->app_data = data;
}
void *ASN1_SCTX_get_app_data(ASN1_SCTX *p)
{
return p->app_data;
}
