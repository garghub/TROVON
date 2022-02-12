STACK *ext_ku_new(void)
{
return sk_new_null();
}
void ext_ku_free(STACK *eku)
{
sk_pop_free(eku, ASN1_OBJECT_free);
return;
}
int i2d_ext_ku(STACK *a, unsigned char **pp)
{
return i2d_ASN1_SET(a, pp, i2d_ASN1_OBJECT, V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL, IS_SEQUENCE);
}
STACK *d2i_ext_ku(STACK **a, unsigned char **pp, long length)
{
return d2i_ASN1_SET(a, pp, length, (char *(*)())(d2i_ASN1_OBJECT),
ASN1_OBJECT_free, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL);
}
static STACK *i2v_ext_ku(X509V3_EXT_METHOD *method, STACK *eku,
STACK *ext_list)
{
int i;
ASN1_OBJECT *obj;
char obj_tmp[80];
for(i = 0; i < sk_num(eku); i++) {
obj = (ASN1_OBJECT *)sk_value(eku, i);
i2t_ASN1_OBJECT(obj_tmp, 80, obj);
X509V3_add_value(NULL, obj_tmp, &ext_list);
}
return ext_list;
}
static STACK *v2i_ext_ku(X509V3_EXT_METHOD *method, X509V3_CTX *ctx,
STACK *nval)
{
STACK *extku;
char *extval;
ASN1_OBJECT *objtmp;
CONF_VALUE *val;
int i;
if(!(extku = sk_new(NULL))) {
X509V3err(X509V3_F_V2I_EXT_KU,ERR_R_MALLOC_FAILURE);
return NULL;
}
for(i = 0; i < sk_num(nval); i++) {
val = (CONF_VALUE *)sk_value(nval, i);
if(val->value) extval = val->value;
else extval = val->name;
if(!(objtmp = OBJ_txt2obj(extval, 0))) {
sk_pop_free(extku, ASN1_OBJECT_free);
X509V3err(X509V3_F_V2I_EXT_KU,X509V3_R_INVALID_OBJECT_IDENTIFIER);
X509V3_conf_err(val);
return NULL;
}
sk_push(extku, (char *)objtmp);
}
return extku;
}
