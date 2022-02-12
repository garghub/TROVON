int i2d_DIST_POINT(DIST_POINT *a, unsigned char **pp)
{
int v = 0;
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len_EXP_opt (a->distpoint, i2d_DIST_POINT_NAME, 0, v);
M_ASN1_I2D_len_IMP_opt (a->reasons, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_len_IMP_opt (a->CRLissuer, i2d_GENERAL_NAMES);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put_EXP_opt (a->distpoint, i2d_DIST_POINT_NAME, 0, v);
M_ASN1_I2D_put_IMP_opt (a->reasons, i2d_ASN1_BIT_STRING, 1);
M_ASN1_I2D_put_IMP_opt (a->CRLissuer, i2d_GENERAL_NAMES, 2);
M_ASN1_I2D_finish();
}
DIST_POINT *DIST_POINT_new(void)
{
DIST_POINT *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, DIST_POINT);
ret->distpoint = NULL;
ret->reasons = NULL;
ret->CRLissuer = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_DIST_POINT_NEW);
}
DIST_POINT *d2i_DIST_POINT(DIST_POINT **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,DIST_POINT *,DIST_POINT_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get_EXP_opt (ret->distpoint, d2i_DIST_POINT_NAME, 0);
M_ASN1_D2I_get_IMP_opt (ret->reasons, d2i_ASN1_BIT_STRING, 1,
V_ASN1_BIT_STRING);
M_ASN1_D2I_get_IMP_opt (ret->CRLissuer, d2i_GENERAL_NAMES, 2,
V_ASN1_SEQUENCE);
M_ASN1_D2I_Finish(a, DIST_POINT_free, ASN1_F_D2I_DIST_POINT);
}
void DIST_POINT_free(DIST_POINT *a)
{
if (a == NULL) return;
DIST_POINT_NAME_free(a->distpoint);
M_ASN1_BIT_STRING_free(a->reasons);
sk_GENERAL_NAME_pop_free(a->CRLissuer, GENERAL_NAME_free);
OPENSSL_free (a);
}
int i2d_DIST_POINT_NAME(DIST_POINT_NAME *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
if(a->fullname) {
M_ASN1_I2D_len_IMP_opt (a->fullname, i2d_GENERAL_NAMES);
} else {
M_ASN1_I2D_len_IMP_SET_opt_type(X509_NAME_ENTRY,
a->relativename, i2d_X509_NAME_ENTRY, 1);
}
if(pp == NULL) return ret;
p = *pp;
if(a->fullname) {
M_ASN1_I2D_put_IMP_opt (a->fullname, i2d_GENERAL_NAMES, 0);
} else {
M_ASN1_I2D_put_IMP_SET_opt_type(X509_NAME_ENTRY,
a->relativename, i2d_X509_NAME_ENTRY, 1);
}
M_ASN1_I2D_finish();
}
DIST_POINT_NAME *DIST_POINT_NAME_new(void)
{
DIST_POINT_NAME *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, DIST_POINT_NAME);
ret->fullname = NULL;
ret->relativename = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_DIST_POINT_NAME_NEW);
}
void DIST_POINT_NAME_free(DIST_POINT_NAME *a)
{
if (a == NULL) return;
sk_X509_NAME_ENTRY_pop_free(a->relativename, X509_NAME_ENTRY_free);
sk_GENERAL_NAME_pop_free(a->fullname, GENERAL_NAME_free);
OPENSSL_free (a);
}
DIST_POINT_NAME *d2i_DIST_POINT_NAME(DIST_POINT_NAME **a, unsigned char **pp,
long length)
{
unsigned char _tmp, tag;
M_ASN1_D2I_vars(a,DIST_POINT_NAME *,DIST_POINT_NAME_new);
M_ASN1_D2I_Init();
c.slen = length;
_tmp = M_ASN1_next;
tag = _tmp & ~V_ASN1_CONSTRUCTED;
if(tag == (0|V_ASN1_CONTEXT_SPECIFIC)) {
M_ASN1_D2I_get_imp(ret->fullname, d2i_GENERAL_NAMES,
V_ASN1_SEQUENCE);
} else if (tag == (1|V_ASN1_CONTEXT_SPECIFIC)) {
M_ASN1_D2I_get_IMP_set_opt_type (X509_NAME_ENTRY,
ret->relativename, d2i_X509_NAME_ENTRY, X509_NAME_ENTRY_free, 1);
} else {
c.error = ASN1_R_BAD_TAG;
goto err;
}
M_ASN1_D2I_Finish(a, DIST_POINT_NAME_free, ASN1_F_D2I_DIST_POINT_NAME);
}
