static ASN1_BIT_STRING *asn1_bit_string_new(void)
{
return ASN1_BIT_STRING_new();
}
static STACK *i2v_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,
ASN1_BIT_STRING *bits, STACK *ret)
{
BIT_STRING_BITNAME *bnam;
for(bnam =method->usr_data; bnam->lname; bnam++) {
if(ASN1_BIT_STRING_get_bit(bits, bnam->bitnum))
X509V3_add_value(bnam->lname, NULL, &ret);
}
return ret;
}
static ASN1_BIT_STRING *v2i_ASN1_BIT_STRING(X509V3_EXT_METHOD *method,
X509V3_CTX *ctx, STACK *nval)
{
CONF_VALUE *val;
ASN1_BIT_STRING *bs;
int i;
BIT_STRING_BITNAME *bnam;
if(!(bs = ASN1_BIT_STRING_new())) {
X509V3err(X509V3_F_V2I_ASN1_BIT_STRING,ERR_R_MALLOC_FAILURE);
return NULL;
}
for(i = 0; i < sk_num(nval); i++) {
val = (CONF_VALUE *)sk_value(nval, i);
for(bnam = method->usr_data; bnam->lname;
bnam++) {
if(!strcmp(bnam->sname, val->name) ||
!strcmp(bnam->lname, val->name) ) {
ASN1_BIT_STRING_set_bit(bs, bnam->bitnum, 1);
break;
}
}
if(!bnam->lname) {
X509V3err(X509V3_F_V2I_ASN1_BIT_STRING,X509V3_R_UNKNOWN_BIT_STRING_ARGUMENT);
X509V3_conf_err(val);
ASN1_BIT_STRING_free(bs);
return NULL;
}
}
return bs;
}
