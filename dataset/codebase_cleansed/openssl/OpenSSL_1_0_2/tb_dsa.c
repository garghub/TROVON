void ENGINE_unregister_DSA(ENGINE *e)
{
engine_table_unregister(&dsa_table, e);
}
static void engine_unregister_all_DSA(void)
{
engine_table_cleanup(&dsa_table);
}
int ENGINE_register_DSA(ENGINE *e)
{
if (e->dsa_meth)
return engine_table_register(&dsa_table,
engine_unregister_all_DSA, e, &dummy_nid,
1, 0);
return 1;
}
void ENGINE_register_all_DSA()
{
ENGINE *e;
for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
ENGINE_register_DSA(e);
}
int ENGINE_set_default_DSA(ENGINE *e)
{
if (e->dsa_meth)
return engine_table_register(&dsa_table,
engine_unregister_all_DSA, e, &dummy_nid,
1, 1);
return 1;
}
ENGINE *ENGINE_get_default_DSA(void)
{
return engine_table_select(&dsa_table, dummy_nid);
}
const DSA_METHOD *ENGINE_get_DSA(const ENGINE *e)
{
return e->dsa_meth;
}
int ENGINE_set_DSA(ENGINE *e, const DSA_METHOD *dsa_meth)
{
e->dsa_meth = dsa_meth;
return 1;
}
