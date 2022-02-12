int i2d_GENERAL_NAME(GENERAL_NAME *a, unsigned char **pp)
{
unsigned char *p;
int ret;
ret = 0;
if(pp) p = *pp;
else p = NULL;
if(a->type == GEN_DIRNAME) {
int v = 0;
M_ASN1_I2D_len_EXP_opt(a->d.dirn, i2d_X509_NAME, 4, v);
if(!p) return ret;
M_ASN1_I2D_put_EXP_opt(a->d.dirn, i2d_X509_NAME, 4, v);
*pp = p;
return ret;
}
switch(a->type) {
case GEN_OTHERNAME:
case GEN_X400:
case GEN_EDIPARTY:
ret = i2d_ASN1_TYPE(a->d.other, pp);
break;
case GEN_EMAIL:
case GEN_DNS:
case GEN_URI:
ret = i2d_ASN1_IA5STRING(a->d.ia5, pp);
break;
case GEN_IPADD:
ret = i2d_ASN1_OCTET_STRING(a->d.ip, pp);
break;
case GEN_RID:
ret = i2d_ASN1_OBJECT(a->d.rid, pp);
break;
}
if(p) *p = (*p & V_ASN1_CONSTRUCTED) | a->type;
return ret;
}
GENERAL_NAME *GENERAL_NAME_new()
{
GENERAL_NAME *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, GENERAL_NAME);
ret->type = -1;
ret->d.ptr = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_GENERAL_NAME_NEW);
}
GENERAL_NAME *d2i_GENERAL_NAME(GENERAL_NAME **a, unsigned char **pp,
long length)
{
unsigned char _tmp;
M_ASN1_D2I_vars(a,GENERAL_NAME *,GENERAL_NAME_new);
M_ASN1_D2I_Init();
c.slen = length;
_tmp = M_ASN1_next;
ret->type = _tmp & ~V_ASN1_CONSTRUCTED;
switch(ret->type) {
case GEN_OTHERNAME:
case GEN_X400:
case GEN_EDIPARTY:
M_ASN1_D2I_get_imp(ret->d.other, d2i_ASN1_TYPE,V_ASN1_SEQUENCE);
break;
case GEN_EMAIL:
case GEN_DNS:
case GEN_URI:
M_ASN1_D2I_get_imp(ret->d.ia5, d2i_ASN1_IA5STRING,
V_ASN1_IA5STRING);
break;
case GEN_DIRNAME:
M_ASN1_D2I_get_EXP_opt(ret->d.dirn, d2i_X509_NAME, 4);
break;
case GEN_IPADD:
M_ASN1_D2I_get_imp(ret->d.ip, d2i_ASN1_OCTET_STRING,
V_ASN1_OCTET_STRING);
break;
case GEN_RID:
M_ASN1_D2I_get_imp(ret->d.rid, d2i_ASN1_OBJECT,V_ASN1_OBJECT);
break;
default:
c.error = ASN1_R_BAD_TAG;
goto err;
}
c.slen = 0;
M_ASN1_D2I_Finish(a, GENERAL_NAME_free, ASN1_F_D2I_GENERAL_NAME);
}
void GENERAL_NAME_free(GENERAL_NAME *a)
{
if (a == NULL) return;
switch(a->type) {
case GEN_OTHERNAME:
case GEN_X400:
case GEN_EDIPARTY:
ASN1_TYPE_free(a->d.other);
break;
case GEN_EMAIL:
case GEN_DNS:
case GEN_URI:
ASN1_IA5STRING_free(a->d.ia5);
break;
case GEN_DIRNAME:
X509_NAME_free(a->d.dirn);
break;
case GEN_IPADD:
ASN1_OCTET_STRING_free(a->d.ip);
break;
case GEN_RID:
ASN1_OBJECT_free(a->d.rid);
break;
}
Free ((char *)a);
}
