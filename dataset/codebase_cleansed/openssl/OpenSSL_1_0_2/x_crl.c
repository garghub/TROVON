static int crl_inf_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
X509_CRL_INFO *a = (X509_CRL_INFO *)*pval;
if (!a || !a->revoked)
return 1;
switch (operation) {
case ASN1_OP_D2I_POST:
(void)sk_X509_REVOKED_set_cmp_func(a->revoked, X509_REVOKED_cmp);
break;
}
return 1;
}
int crl_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
X509_CRL *crl = (X509_CRL *)*pval;
STACK_OF(X509_EXTENSION) *exts;
X509_EXTENSION *ext;
int idx;
switch (operation) {
case ASN1_OP_NEW_POST:
crl->idp = NULL;
crl->akid = NULL;
crl->flags = 0;
crl->idp_flags = 0;
crl->idp_reasons = CRLDP_ALL_REASONS;
crl->meth = default_crl_method;
crl->meth_data = NULL;
crl->issuers = NULL;
crl->crl_number = NULL;
crl->base_crl_number = NULL;
break;
case ASN1_OP_D2I_POST:
#ifndef OPENSSL_NO_SHA
X509_CRL_digest(crl, EVP_sha1(), crl->sha1_hash, NULL);
#endif
crl->idp = X509_CRL_get_ext_d2i(crl,
NID_issuing_distribution_point, NULL,
NULL);
if (crl->idp)
setup_idp(crl, crl->idp);
crl->akid = X509_CRL_get_ext_d2i(crl,
NID_authority_key_identifier, NULL,
NULL);
crl->crl_number = X509_CRL_get_ext_d2i(crl,
NID_crl_number, NULL, NULL);
crl->base_crl_number = X509_CRL_get_ext_d2i(crl,
NID_delta_crl, NULL,
NULL);
if (crl->base_crl_number && !crl->crl_number)
crl->flags |= EXFLAG_INVALID;
exts = crl->crl->extensions;
for (idx = 0; idx < sk_X509_EXTENSION_num(exts); idx++) {
int nid;
ext = sk_X509_EXTENSION_value(exts, idx);
nid = OBJ_obj2nid(ext->object);
if (nid == NID_freshest_crl)
crl->flags |= EXFLAG_FRESHEST;
if (ext->critical > 0) {
if ((nid == NID_issuing_distribution_point)
|| (nid == NID_authority_key_identifier)
|| (nid == NID_delta_crl))
break;;
crl->flags |= EXFLAG_CRITICAL;
break;
}
}
if (!crl_set_issuers(crl))
return 0;
if (crl->meth->crl_init) {
if (crl->meth->crl_init(crl) == 0)
return 0;
}
break;
case ASN1_OP_FREE_POST:
if (crl->meth->crl_free) {
if (!crl->meth->crl_free(crl))
return 0;
}
if (crl->akid)
AUTHORITY_KEYID_free(crl->akid);
if (crl->idp)
ISSUING_DIST_POINT_free(crl->idp);
ASN1_INTEGER_free(crl->crl_number);
ASN1_INTEGER_free(crl->base_crl_number);
sk_GENERAL_NAMES_pop_free(crl->issuers, GENERAL_NAMES_free);
break;
}
return 1;
}
static void setup_idp(X509_CRL *crl, ISSUING_DIST_POINT *idp)
{
int idp_only = 0;
crl->idp_flags |= IDP_PRESENT;
if (idp->onlyuser > 0) {
idp_only++;
crl->idp_flags |= IDP_ONLYUSER;
}
if (idp->onlyCA > 0) {
idp_only++;
crl->idp_flags |= IDP_ONLYCA;
}
if (idp->onlyattr > 0) {
idp_only++;
crl->idp_flags |= IDP_ONLYATTR;
}
if (idp_only > 1)
crl->idp_flags |= IDP_INVALID;
if (idp->indirectCRL > 0)
crl->idp_flags |= IDP_INDIRECT;
if (idp->onlysomereasons) {
crl->idp_flags |= IDP_REASONS;
if (idp->onlysomereasons->length > 0)
crl->idp_reasons = idp->onlysomereasons->data[0];
if (idp->onlysomereasons->length > 1)
crl->idp_reasons |= (idp->onlysomereasons->data[1] << 8);
crl->idp_reasons &= CRLDP_ALL_REASONS;
}
DIST_POINT_set_dpname(idp->distpoint, X509_CRL_get_issuer(crl));
}
int X509_CRL_add0_revoked(X509_CRL *crl, X509_REVOKED *rev)
{
X509_CRL_INFO *inf;
inf = crl->crl;
if (!inf->revoked)
inf->revoked = sk_X509_REVOKED_new(X509_REVOKED_cmp);
if (!inf->revoked || !sk_X509_REVOKED_push(inf->revoked, rev)) {
ASN1err(ASN1_F_X509_CRL_ADD0_REVOKED, ERR_R_MALLOC_FAILURE);
return 0;
}
inf->enc.modified = 1;
return 1;
}
int X509_CRL_verify(X509_CRL *crl, EVP_PKEY *r)
{
if (crl->meth->crl_verify)
return crl->meth->crl_verify(crl, r);
return 0;
}
int X509_CRL_get0_by_serial(X509_CRL *crl,
X509_REVOKED **ret, ASN1_INTEGER *serial)
{
if (crl->meth->crl_lookup)
return crl->meth->crl_lookup(crl, ret, serial, NULL);
return 0;
}
int X509_CRL_get0_by_cert(X509_CRL *crl, X509_REVOKED **ret, X509 *x)
{
if (crl->meth->crl_lookup)
return crl->meth->crl_lookup(crl, ret,
X509_get_serialNumber(x),
X509_get_issuer_name(x));
return 0;
}
static int def_crl_verify(X509_CRL *crl, EVP_PKEY *r)
{
return (ASN1_item_verify(ASN1_ITEM_rptr(X509_CRL_INFO),
crl->sig_alg, crl->signature, crl->crl, r));
}
static int crl_revoked_issuer_match(X509_CRL *crl, X509_NAME *nm,
X509_REVOKED *rev)
{
int i;
if (!rev->issuer) {
if (!nm)
return 1;
if (!X509_NAME_cmp(nm, X509_CRL_get_issuer(crl)))
return 1;
return 0;
}
if (!nm)
nm = X509_CRL_get_issuer(crl);
for (i = 0; i < sk_GENERAL_NAME_num(rev->issuer); i++) {
GENERAL_NAME *gen = sk_GENERAL_NAME_value(rev->issuer, i);
if (gen->type != GEN_DIRNAME)
continue;
if (!X509_NAME_cmp(nm, gen->d.directoryName))
return 1;
}
return 0;
}
static int def_crl_lookup(X509_CRL *crl,
X509_REVOKED **ret, ASN1_INTEGER *serial,
X509_NAME *issuer)
{
X509_REVOKED rtmp, *rev;
int idx;
rtmp.serialNumber = serial;
if (!sk_X509_REVOKED_is_sorted(crl->crl->revoked)) {
CRYPTO_w_lock(CRYPTO_LOCK_X509_CRL);
sk_X509_REVOKED_sort(crl->crl->revoked);
CRYPTO_w_unlock(CRYPTO_LOCK_X509_CRL);
}
idx = sk_X509_REVOKED_find(crl->crl->revoked, &rtmp);
if (idx < 0)
return 0;
for (; idx < sk_X509_REVOKED_num(crl->crl->revoked); idx++) {
rev = sk_X509_REVOKED_value(crl->crl->revoked, idx);
if (ASN1_INTEGER_cmp(rev->serialNumber, serial))
return 0;
if (crl_revoked_issuer_match(crl, issuer, rev)) {
if (ret)
*ret = rev;
if (rev->reason == CRL_REASON_REMOVE_FROM_CRL)
return 2;
return 1;
}
}
return 0;
}
void X509_CRL_set_default_method(const X509_CRL_METHOD *meth)
{
if (meth == NULL)
default_crl_method = &int_crl_meth;
else
default_crl_method = meth;
}
X509_CRL_METHOD *X509_CRL_METHOD_new(int (*crl_init) (X509_CRL *crl),
int (*crl_free) (X509_CRL *crl),
int (*crl_lookup) (X509_CRL *crl,
X509_REVOKED **ret,
ASN1_INTEGER *ser,
X509_NAME *issuer),
int (*crl_verify) (X509_CRL *crl,
EVP_PKEY *pk))
{
X509_CRL_METHOD *m;
m = OPENSSL_malloc(sizeof(X509_CRL_METHOD));
if (!m)
return NULL;
m->crl_init = crl_init;
m->crl_free = crl_free;
m->crl_lookup = crl_lookup;
m->crl_verify = crl_verify;
m->flags = X509_CRL_METHOD_DYNAMIC;
return m;
}
void X509_CRL_METHOD_free(X509_CRL_METHOD *m)
{
if (!(m->flags & X509_CRL_METHOD_DYNAMIC))
return;
OPENSSL_free(m);
}
void X509_CRL_set_meth_data(X509_CRL *crl, void *dat)
{
crl->meth_data = dat;
}
void *X509_CRL_get_meth_data(X509_CRL *crl)
{
return crl->meth_data;
}
