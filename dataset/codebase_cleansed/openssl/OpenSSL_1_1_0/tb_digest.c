void ENGINE_unregister_digests(ENGINE *e)
{
engine_table_unregister(&digest_table, e);
}
static void engine_unregister_all_digests(void)
{
engine_table_cleanup(&digest_table);
}
int ENGINE_register_digests(ENGINE *e)
{
if (e->digests) {
const int *nids;
int num_nids = e->digests(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&digest_table,
engine_unregister_all_digests, e,
nids, num_nids, 0);
}
return 1;
}
void ENGINE_register_all_digests()
{
ENGINE *e;
for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
ENGINE_register_digests(e);
}
int ENGINE_set_default_digests(ENGINE *e)
{
if (e->digests) {
const int *nids;
int num_nids = e->digests(e, NULL, &nids, 0);
if (num_nids > 0)
return engine_table_register(&digest_table,
engine_unregister_all_digests, e,
nids, num_nids, 1);
}
return 1;
}
ENGINE *ENGINE_get_digest_engine(int nid)
{
return engine_table_select(&digest_table, nid);
}
const EVP_MD *ENGINE_get_digest(ENGINE *e, int nid)
{
const EVP_MD *ret;
ENGINE_DIGESTS_PTR fn = ENGINE_get_digests(e);
if (!fn || !fn(e, &ret, NULL, nid)) {
ENGINEerr(ENGINE_F_ENGINE_GET_DIGEST, ENGINE_R_UNIMPLEMENTED_DIGEST);
return NULL;
}
return ret;
}
ENGINE_DIGESTS_PTR ENGINE_get_digests(const ENGINE *e)
{
return e->digests;
}
int ENGINE_set_digests(ENGINE *e, ENGINE_DIGESTS_PTR f)
{
e->digests = f;
return 1;
}
