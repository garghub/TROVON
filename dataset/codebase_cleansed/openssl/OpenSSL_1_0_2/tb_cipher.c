void ENGINE_unregister_ciphers(ENGINE *e)
{
engine_table_unregister(&cipher_table, e);
}
static void engine_unregister_all_ciphers(void)
{
engine_table_cleanup(&cipher_table);
}
int ENGINE_register_ciphers(ENGINE *e)
{
if (e->ciphers) {
const int *nids;
int num_nids = e->ciphers(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&cipher_table,
engine_unregister_all_ciphers, e,
nids, num_nids, 0);
}
return 1;
}
void ENGINE_register_all_ciphers()
{
ENGINE *e;
for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
ENGINE_register_ciphers(e);
}
int ENGINE_set_default_ciphers(ENGINE *e)
{
if (e->ciphers) {
const int *nids;
int num_nids = e->ciphers(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&cipher_table,
engine_unregister_all_ciphers, e,
nids, num_nids, 1);
}
return 1;
}
ENGINE *ENGINE_get_cipher_engine(int nid)
{
return engine_table_select(&cipher_table, nid);
}
const EVP_CIPHER *ENGINE_get_cipher(ENGINE *e, int nid)
{
const EVP_CIPHER *ret;
ENGINE_CIPHERS_PTR fn = ENGINE_get_ciphers(e);
if (!fn || !fn(e, &ret, NULL, nid)) {
ENGINEerr(ENGINE_F_ENGINE_GET_CIPHER, ENGINE_R_UNIMPLEMENTED_CIPHER);
return NULL;
}
return ret;
}
ENGINE_CIPHERS_PTR ENGINE_get_ciphers(const ENGINE *e)
{
return e->ciphers;
}
int ENGINE_set_ciphers(ENGINE *e, ENGINE_CIPHERS_PTR f)
{
e->ciphers = f;
return 1;
}
