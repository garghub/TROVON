static int oid_module_init(CONF_IMODULE *md, const CONF *cnf)
{
int i;
const char *oid_section;
STACK_OF(CONF_VALUE) *sktmp;
CONF_VALUE *oval;
oid_section = CONF_imodule_get_value(md);
if(!(sktmp = NCONF_get_section(cnf, oid_section)))
{
ASN1err(ASN1_F_OID_MODULE_INIT, ASN1_R_ERROR_LOADING_SECTION);
return 0;
}
for(i = 0; i < sk_CONF_VALUE_num(sktmp); i++)
{
oval = sk_CONF_VALUE_value(sktmp, i);
if(OBJ_create(oval->value, oval->name, oval->name) == NID_undef)
{
ASN1err(ASN1_F_OID_MODULE_INIT, ASN1_R_ADDING_OBJECT);
return 0;
}
}
return 1;
}
void ASN1_add_oid_module(void)
{
CONF_module_add("oid_section", oid_module_init, 0);
}
