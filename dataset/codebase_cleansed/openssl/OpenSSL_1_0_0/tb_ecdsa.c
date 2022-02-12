void ENGINE_unregister_ECDSA(ENGINE *e)
{
engine_table_unregister(&ecdsa_table, e);
}
static void engine_unregister_all_ECDSA(void)
{
engine_table_cleanup(&ecdsa_table);
}
int ENGINE_register_ECDSA(ENGINE *e)
{
if(e->ecdsa_meth)
return engine_table_register(&ecdsa_table,
engine_unregister_all_ECDSA, e, &dummy_nid, 1, 0);
return 1;
}
void ENGINE_register_all_ECDSA()
{
ENGINE *e;
for(e=ENGINE_get_first() ; e ; e=ENGINE_get_next(e))
ENGINE_register_ECDSA(e);
}
int ENGINE_set_default_ECDSA(ENGINE *e)
{
if(e->ecdsa_meth)
return engine_table_register(&ecdsa_table,
engine_unregister_all_ECDSA, e, &dummy_nid, 1, 1);
return 1;
}
ENGINE *ENGINE_get_default_ECDSA(void)
{
return engine_table_select(&ecdsa_table, dummy_nid);
}
const ECDSA_METHOD *ENGINE_get_ECDSA(const ENGINE *e)
{
return e->ecdsa_meth;
}
int ENGINE_set_ECDSA(ENGINE *e, const ECDSA_METHOD *ecdsa_meth)
{
e->ecdsa_meth = ecdsa_meth;
return 1;
}
