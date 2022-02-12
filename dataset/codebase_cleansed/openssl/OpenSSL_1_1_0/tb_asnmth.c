void ENGINE_unregister_pkey_asn1_meths(ENGINE *e)
{
engine_table_unregister(&pkey_asn1_meth_table, e);
}
static void engine_unregister_all_pkey_asn1_meths(void)
{
engine_table_cleanup(&pkey_asn1_meth_table);
}
int ENGINE_register_pkey_asn1_meths(ENGINE *e)
{
if (e->pkey_asn1_meths) {
const int *nids;
int num_nids = e->pkey_asn1_meths(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&pkey_asn1_meth_table,
engine_unregister_all_pkey_asn1_meths,
e, nids, num_nids, 0);
}
return 1;
}
void ENGINE_register_all_pkey_asn1_meths(void)
{
ENGINE *e;
for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
ENGINE_register_pkey_asn1_meths(e);
}
int ENGINE_set_default_pkey_asn1_meths(ENGINE *e)
{
if (e->pkey_asn1_meths) {
const int *nids;
int num_nids = e->pkey_asn1_meths(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&pkey_asn1_meth_table,
engine_unregister_all_pkey_asn1_meths,
e, nids, num_nids, 1);
}
return 1;
}
ENGINE *ENGINE_get_pkey_asn1_meth_engine(int nid)
{
return engine_table_select(&pkey_asn1_meth_table, nid);
}
const EVP_PKEY_ASN1_METHOD *ENGINE_get_pkey_asn1_meth(ENGINE *e, int nid)
{
EVP_PKEY_ASN1_METHOD *ret;
ENGINE_PKEY_ASN1_METHS_PTR fn = ENGINE_get_pkey_asn1_meths(e);
if (!fn || !fn(e, &ret, NULL, nid)) {
ENGINEerr(ENGINE_F_ENGINE_GET_PKEY_ASN1_METH,
ENGINE_R_UNIMPLEMENTED_PUBLIC_KEY_METHOD);
return NULL;
}
return ret;
}
ENGINE_PKEY_ASN1_METHS_PTR ENGINE_get_pkey_asn1_meths(const ENGINE *e)
{
return e->pkey_asn1_meths;
}
int ENGINE_set_pkey_asn1_meths(ENGINE *e, ENGINE_PKEY_ASN1_METHS_PTR f)
{
e->pkey_asn1_meths = f;
return 1;
}
void engine_pkey_asn1_meths_free(ENGINE *e)
{
int i;
EVP_PKEY_ASN1_METHOD *pkm;
if (e->pkey_asn1_meths) {
const int *pknids;
int npknids;
npknids = e->pkey_asn1_meths(e, NULL, &pknids, 0);
for (i = 0; i < npknids; i++) {
if (e->pkey_asn1_meths(e, &pkm, NULL, pknids[i])) {
EVP_PKEY_asn1_free(pkm);
}
}
}
}
const EVP_PKEY_ASN1_METHOD *ENGINE_get_pkey_asn1_meth_str(ENGINE *e,
const char *str,
int len)
{
int i, nidcount;
const int *nids;
EVP_PKEY_ASN1_METHOD *ameth;
if (!e->pkey_asn1_meths)
return NULL;
if (len == -1)
len = strlen(str);
nidcount = e->pkey_asn1_meths(e, NULL, &nids, 0);
for (i = 0; i < nidcount; i++) {
e->pkey_asn1_meths(e, &ameth, NULL, nids[i]);
if (((int)strlen(ameth->pem_str) == len)
&& strncasecmp(ameth->pem_str, str, len) == 0)
return ameth;
}
return NULL;
}
const EVP_PKEY_ASN1_METHOD *ENGINE_pkey_asn1_find_str(ENGINE **pe,
const char *str,
int len)
{
ENGINE_FIND_STR fstr;
fstr.e = NULL;
fstr.ameth = NULL;
fstr.str = str;
fstr.len = len;
if (!RUN_ONCE(&engine_lock_init, do_engine_lock_init)) {
ENGINEerr(ENGINE_F_ENGINE_PKEY_ASN1_FIND_STR, ERR_R_MALLOC_FAILURE);
return NULL;
}
CRYPTO_THREAD_write_lock(global_engine_lock);
engine_table_doall(pkey_asn1_meth_table, look_str_cb, &fstr);
if (fstr.e) {
fstr.e->struct_ref++;
engine_ref_debug(fstr.e, 0, 1);
}
*pe = fstr.e;
CRYPTO_THREAD_unlock(global_engine_lock);
return fstr.ameth;
}
