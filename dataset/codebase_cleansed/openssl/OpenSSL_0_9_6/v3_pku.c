int i2d_PKEY_USAGE_PERIOD(PKEY_USAGE_PERIOD *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len_IMP_opt (a->notBefore, i2d_ASN1_GENERALIZEDTIME);
M_ASN1_I2D_len_IMP_opt (a->notAfter, i2d_ASN1_GENERALIZEDTIME);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put_IMP_opt (a->notBefore, i2d_ASN1_GENERALIZEDTIME, 0);
M_ASN1_I2D_put_IMP_opt (a->notAfter, i2d_ASN1_GENERALIZEDTIME, 1);
M_ASN1_I2D_finish();
}
PKEY_USAGE_PERIOD *PKEY_USAGE_PERIOD_new(void)
{
PKEY_USAGE_PERIOD *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret, PKEY_USAGE_PERIOD);
ret->notBefore = NULL;
ret->notAfter = NULL;
return (ret);
M_ASN1_New_Error(ASN1_F_PKEY_USAGE_PERIOD_NEW);
}
PKEY_USAGE_PERIOD *d2i_PKEY_USAGE_PERIOD(PKEY_USAGE_PERIOD **a,
unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKEY_USAGE_PERIOD *,PKEY_USAGE_PERIOD_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get_IMP_opt (ret->notBefore, d2i_ASN1_GENERALIZEDTIME, 0,
V_ASN1_GENERALIZEDTIME);
M_ASN1_D2I_get_IMP_opt (ret->notAfter, d2i_ASN1_GENERALIZEDTIME, 1,
V_ASN1_GENERALIZEDTIME);
M_ASN1_D2I_Finish(a, PKEY_USAGE_PERIOD_free, ASN1_F_D2I_PKEY_USAGE_PERIOD);
}
void PKEY_USAGE_PERIOD_free(PKEY_USAGE_PERIOD *a)
{
if (a == NULL) return;
M_ASN1_GENERALIZEDTIME_free(a->notBefore);
M_ASN1_GENERALIZEDTIME_free(a->notAfter);
OPENSSL_free (a);
}
static int i2r_PKEY_USAGE_PERIOD(X509V3_EXT_METHOD *method,
PKEY_USAGE_PERIOD *usage, BIO *out, int indent)
{
BIO_printf(out, "%*s", indent, "");
if(usage->notBefore) {
BIO_write(out, "Not Before: ", 12);
ASN1_GENERALIZEDTIME_print(out, usage->notBefore);
if(usage->notAfter) BIO_write(out, ", ", 2);
}
if(usage->notAfter) {
BIO_write(out, "Not After: ", 11);
ASN1_GENERALIZEDTIME_print(out, usage->notAfter);
}
return 1;
}
