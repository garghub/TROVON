static int oid_module_init(CONF_IMODULE *md, const CONF *cnf)
{
int i;
const char *oid_section;
STACK_OF(CONF_VALUE) *sktmp;
CONF_VALUE *oval;
oid_section = CONF_imodule_get_value(md);
if (!(sktmp = NCONF_get_section(cnf, oid_section))) {
ASN1err(ASN1_F_OID_MODULE_INIT, ASN1_R_ERROR_LOADING_SECTION);
return 0;
}
for (i = 0; i < sk_CONF_VALUE_num(sktmp); i++) {
oval = sk_CONF_VALUE_value(sktmp, i);
if (!do_create(oval->value, oval->name)) {
ASN1err(ASN1_F_OID_MODULE_INIT, ASN1_R_ADDING_OBJECT);
return 0;
}
}
return 1;
}
static void oid_module_finish(CONF_IMODULE *md)
{
OBJ_cleanup();
}
void ASN1_add_oid_module(void)
{
CONF_module_add("oid_section", oid_module_init, oid_module_finish);
}
static int do_create(char *value, char *name)
{
int nid;
ASN1_OBJECT *oid;
char *ln, *ostr, *p, *lntmp;
p = strrchr(value, ',');
if (!p) {
ln = name;
ostr = value;
} else {
ln = NULL;
ostr = p + 1;
if (!*ostr)
return 0;
while (isspace((unsigned char)*ostr))
ostr++;
}
nid = OBJ_create(ostr, name, ln);
if (nid == NID_undef)
return 0;
if (p) {
ln = value;
while (isspace((unsigned char)*ln))
ln++;
p--;
while (isspace((unsigned char)*p)) {
if (p == ln)
return 0;
p--;
}
p++;
lntmp = OPENSSL_malloc((p - ln) + 1);
if (lntmp == NULL)
return 0;
memcpy(lntmp, ln, p - ln);
lntmp[p - ln] = 0;
oid = OBJ_nid2obj(nid);
oid->ln = lntmp;
}
return 1;
}
