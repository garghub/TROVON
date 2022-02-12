int i2d_AUTHORITY_KEYID(AUTHORITY_KEYID *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len_IMP_opt (a->keyid, i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len_IMP_opt (a->issuer, i2d_GENERAL_NAMES);
M_ASN1_I2D_len_IMP_opt (a->serial, i2d_ASN1_INTEGER);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put_IMP_opt (a->keyid, i2d_ASN1_OCTET_STRING, 0);
M_ASN1_I2D_put_IMP_opt (a->issuer, i2d_GENERAL_NAMES, 1);
M_ASN1_I2D_put_IMP_opt (a->serial, i2d_ASN1_INTEGER, 2);
M_ASN1_I2D_finish();
}
AUTHORITY_KEYID *AUTHORITY_KEYID_new(void)
{
AUTHORITY_KEYID *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, AUTHORITY_KEYID);
ret->keyid = NULL;
ret->issuer = NULL;
ret->serial = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_AUTHORITY_KEYID_NEW);
}
AUTHORITY_KEYID *d2i_AUTHORITY_KEYID(AUTHORITY_KEYID **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,AUTHORITY_KEYID *,AUTHORITY_KEYID_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get_IMP_opt (ret->keyid, d2i_ASN1_OCTET_STRING, 0,
V_ASN1_OCTET_STRING);
M_ASN1_D2I_get_IMP_opt (ret->issuer, d2i_GENERAL_NAMES, 1,
V_ASN1_SEQUENCE);
M_ASN1_D2I_get_IMP_opt (ret->serial, d2i_ASN1_INTEGER, 2,
V_ASN1_INTEGER);
M_ASN1_D2I_Finish(a, AUTHORITY_KEYID_free, ASN1_F_D2I_AUTHORITY_KEYID);
}
void AUTHORITY_KEYID_free(AUTHORITY_KEYID *a)
{
if (a == NULL) return;
ASN1_OCTET_STRING_free(a->keyid);
sk_GENERAL_NAME_pop_free(a->issuer, GENERAL_NAME_free);
ASN1_INTEGER_free (a->serial);
Free ((char *)a);
}
static STACK *i2v_AUTHORITY_KEYID(X509V3_EXT_METHOD *method,
AUTHORITY_KEYID *akeyid, STACK *extlist)
{
char *tmp;
if(akeyid->keyid) {
tmp = hex_to_string(akeyid->keyid->data, akeyid->keyid->length);
X509V3_add_value("keyid", tmp, &extlist);
Free(tmp);
}
if(akeyid->issuer)
extlist = i2v_GENERAL_NAMES(NULL, akeyid->issuer, extlist);
if(akeyid->serial) {
tmp = hex_to_string(akeyid->serial->data,
akeyid->serial->length);
X509V3_add_value("serial", tmp, &extlist);
Free(tmp);
}
return extlist;
}
static AUTHORITY_KEYID *v2i_AUTHORITY_KEYID(X509V3_EXT_METHOD *method,
X509V3_CTX *ctx, STACK *values)
{
char keyid=0, issuer=0;
int i;
CONF_VALUE *cnf;
ASN1_OCTET_STRING *ikeyid = NULL;
X509_NAME *isname = NULL;
STACK_OF(GENERAL_NAME) * gens = NULL;
GENERAL_NAME *gen = NULL;
ASN1_INTEGER *serial = NULL;
X509_EXTENSION *ext;
X509 *cert;
AUTHORITY_KEYID *akeyid;
for(i = 0; i < sk_num(values); i++) {
cnf = (CONF_VALUE *)sk_value(values, i);
if(!strcmp(cnf->name, "keyid")) {
keyid = 1;
if(cnf->value && !strcmp(cnf->value, "always")) keyid = 2;
} else if(!strcmp(cnf->name, "issuer")) {
issuer = 1;
if(cnf->value && !strcmp(cnf->value, "always")) issuer = 2;
} else {
X509V3err(X509V3_F_V2I_AUTHORITY_KEYID,X509V3_R_UNKNOWN_OPTION);
ERR_add_error_data(2, "name=", cnf->name);
return NULL;
}
}
if(!ctx || !ctx->issuer_cert) {
if(ctx && (ctx->flags==CTX_TEST)) return AUTHORITY_KEYID_new();
X509V3err(X509V3_F_V2I_AUTHORITY_KEYID,X509V3_R_NO_ISSUER_CERTIFICATE);
return NULL;
}
cert = ctx->issuer_cert;
if(keyid) {
i = X509_get_ext_by_NID(cert, NID_subject_key_identifier, -1);
if((i >= 0) && (ext = X509_get_ext(cert, i)))
ikeyid = X509V3_EXT_d2i(ext);
if(keyid==2 && !ikeyid) {
X509V3err(X509V3_F_V2I_AUTHORITY_KEYID,X509V3_R_UNABLE_TO_GET_ISSUER_KEYID);
return NULL;
}
}
if((issuer && !ikeyid) || (issuer == 2)) {
isname = X509_NAME_dup(X509_get_issuer_name(cert));
serial = ASN1_INTEGER_dup(X509_get_serialNumber(cert));
if(!isname || !serial) {
X509V3err(X509V3_F_V2I_AUTHORITY_KEYID,X509V3_R_UNABLE_TO_GET_ISSUER_DETAILS);
goto err;
}
}
if(!(akeyid = AUTHORITY_KEYID_new())) goto err;
if(isname) {
if(!(gens = sk_GENERAL_NAME_new(NULL)) || !(gen = GENERAL_NAME_new())
|| !sk_GENERAL_NAME_push(gens, gen)) {
X509V3err(X509V3_F_V2I_AUTHORITY_KEYID,ERR_R_MALLOC_FAILURE);
goto err;
}
gen->type = GEN_DIRNAME;
gen->d.dirn = isname;
}
akeyid->issuer = gens;
akeyid->serial = serial;
akeyid->keyid = ikeyid;
return akeyid;
err:
X509_NAME_free(isname);
ASN1_INTEGER_free(serial);
ASN1_OCTET_STRING_free(ikeyid);
return NULL;
}
