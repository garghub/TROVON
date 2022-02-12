void ENGINE_unregister_RSA(ENGINE *e)
{
engine_table_unregister(&rsa_table, e);
}
static void engine_unregister_all_RSA(void)
{
engine_table_cleanup(&rsa_table);
}
int ENGINE_register_RSA(ENGINE *e)
{
if(e->rsa_meth)
return engine_table_register(&rsa_table,
engine_unregister_all_RSA, e, &dummy_nid, 1, 0);
return 1;
}
void ENGINE_register_all_RSA()
{
ENGINE *e;
for(e=ENGINE_get_first() ; e ; e=ENGINE_get_next(e))
ENGINE_register_RSA(e);
}
int ENGINE_set_default_RSA(ENGINE *e)
{
if(e->rsa_meth)
return engine_table_register(&rsa_table,
engine_unregister_all_RSA, e, &dummy_nid, 1, 1);
return 1;
}
ENGINE *ENGINE_get_default_RSA(void)
{
return engine_table_select(&rsa_table, dummy_nid);
}
const RSA_METHOD *ENGINE_get_RSA(const ENGINE *e)
{
return e->rsa_meth;
}
int ENGINE_set_RSA(ENGINE *e, const RSA_METHOD *rsa_meth)
{
e->rsa_meth = rsa_meth;
return 1;
}
