void ENGINE_unregister_pkey_meths(ENGINE *e)
{
engine_table_unregister(&pkey_meth_table, e);
}
static void engine_unregister_all_pkey_meths(void)
{
engine_table_cleanup(&pkey_meth_table);
}
int ENGINE_register_pkey_meths(ENGINE *e)
{
if (e->pkey_meths) {
const int *nids;
int num_nids = e->pkey_meths(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&pkey_meth_table,
engine_unregister_all_pkey_meths, e,
nids, num_nids, 0);
}
return 1;
}
void ENGINE_register_all_pkey_meths()
{
ENGINE *e;
for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
ENGINE_register_pkey_meths(e);
}
int ENGINE_set_default_pkey_meths(ENGINE *e)
{
if (e->pkey_meths) {
const int *nids;
int num_nids = e->pkey_meths(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&pkey_meth_table,
engine_unregister_all_pkey_meths, e,
nids, num_nids, 1);
}
return 1;
}
ENGINE *ENGINE_get_pkey_meth_engine(int nid)
{
return engine_table_select(&pkey_meth_table, nid);
}
const EVP_PKEY_METHOD *ENGINE_get_pkey_meth(ENGINE *e, int nid)
{
EVP_PKEY_METHOD *ret;
ENGINE_PKEY_METHS_PTR fn = ENGINE_get_pkey_meths(e);
if (!fn || !fn(e, &ret, NULL, nid)) {
ENGINEerr(ENGINE_F_ENGINE_GET_PKEY_METH,
ENGINE_R_UNIMPLEMENTED_PUBLIC_KEY_METHOD);
return NULL;
}
return ret;
}
ENGINE_PKEY_METHS_PTR ENGINE_get_pkey_meths(const ENGINE *e)
{
return e->pkey_meths;
}
int ENGINE_set_pkey_meths(ENGINE *e, ENGINE_PKEY_METHS_PTR f)
{
e->pkey_meths = f;
return 1;
}
void engine_pkey_meths_free(ENGINE *e)
{
int i;
EVP_PKEY_METHOD *pkm;
if (e->pkey_meths) {
const int *pknids;
int npknids;
npknids = e->pkey_meths(e, NULL, &pknids, 0);
for (i = 0; i < npknids; i++) {
if (e->pkey_meths(e, &pkm, NULL, pknids[i])) {
EVP_PKEY_meth_free(pkm);
}
}
}
}
