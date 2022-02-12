void ENGINE_unregister_STORE(ENGINE *e)
{
engine_table_unregister(&store_table, e);
}
static void engine_unregister_all_STORE(void)
{
engine_table_cleanup(&store_table);
}
int ENGINE_register_STORE(ENGINE *e)
{
if (e->store_meth)
return engine_table_register(&store_table,
engine_unregister_all_STORE, e,
&dummy_nid, 1, 0);
return 1;
}
void ENGINE_register_all_STORE()
{
ENGINE *e;
for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
ENGINE_register_STORE(e);
}
const STORE_METHOD *ENGINE_get_STORE(const ENGINE *e)
{
return e->store_meth;
}
int ENGINE_set_STORE(ENGINE *e, const STORE_METHOD *store_meth)
{
e->store_meth = store_meth;
return 1;
}
