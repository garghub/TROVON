void ENGINE_unregister_ECDH(ENGINE *e)
{
engine_table_unregister(&ecdh_table, e);
}
static void engine_unregister_all_ECDH(void)
{
engine_table_cleanup(&ecdh_table);
}
int ENGINE_register_ECDH(ENGINE *e)
{
if(e->ecdh_meth)
return engine_table_register(&ecdh_table,
engine_unregister_all_ECDH, e, &dummy_nid, 1, 0);
return 1;
}
void ENGINE_register_all_ECDH()
{
ENGINE *e;
for(e=ENGINE_get_first() ; e ; e=ENGINE_get_next(e))
ENGINE_register_ECDH(e);
}
int ENGINE_set_default_ECDH(ENGINE *e)
{
if(e->ecdh_meth)
return engine_table_register(&ecdh_table,
engine_unregister_all_ECDH, e, &dummy_nid, 1, 0);
return 1;
}
ENGINE *ENGINE_get_default_ECDH(void)
{
return engine_table_select(&ecdh_table, dummy_nid);
}
const ECDH_METHOD *ENGINE_get_ECDH(const ENGINE *e)
{
return e->ecdh_meth;
}
int ENGINE_set_ECDH(ENGINE *e, const ECDH_METHOD *ecdh_meth)
{
e->ecdh_meth = ecdh_meth;
return 1;
}
