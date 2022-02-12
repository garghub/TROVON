void ENGINE_unregister_DH(ENGINE *e)
{
engine_table_unregister(&dh_table, e);
}
static void engine_unregister_all_DH(void)
{
engine_table_cleanup(&dh_table);
}
int ENGINE_register_DH(ENGINE *e)
{
if(e->dh_meth)
return engine_table_register(&dh_table,
engine_unregister_all_DH, e, &dummy_nid, 1, 0);
return 1;
}
void ENGINE_register_all_DH()
{
ENGINE *e;
for(e=ENGINE_get_first() ; e ; e=ENGINE_get_next(e))
ENGINE_register_DH(e);
}
int ENGINE_set_default_DH(ENGINE *e)
{
if(e->dh_meth)
return engine_table_register(&dh_table,
engine_unregister_all_DH, e, &dummy_nid, 1, 1);
return 1;
}
ENGINE *ENGINE_get_default_DH(void)
{
return engine_table_select(&dh_table, dummy_nid);
}
const DH_METHOD *ENGINE_get_DH(const ENGINE *e)
{
return e->dh_meth;
}
int ENGINE_set_DH(ENGINE *e, const DH_METHOD *dh_meth)
{
e->dh_meth = dh_meth;
return 1;
}
