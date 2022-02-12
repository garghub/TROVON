static int i2r_ocsp_crlid(X509V3_EXT_METHOD *method, void *in, BIO *bp, int ind)
{
OCSP_CRLID *a = in;
if (a->crlUrl)
{
if (!BIO_printf(bp, "%*scrlUrl: ", ind, "")) goto err;
if (!ASN1_STRING_print(bp, (ASN1_STRING*)a->crlUrl)) goto err;
if (!BIO_write(bp, "\n", 1)) goto err;
}
if (a->crlNum)
{
if (!BIO_printf(bp, "%*scrlNum: ", ind, "")) goto err;
if (!i2a_ASN1_INTEGER(bp, a->crlNum)) goto err;
if (!BIO_write(bp, "\n", 1)) goto err;
}
if (a->crlTime)
{
if (!BIO_printf(bp, "%*scrlTime: ", ind, "")) goto err;
if (!ASN1_GENERALIZEDTIME_print(bp, a->crlTime)) goto err;
if (!BIO_write(bp, "\n", 1)) goto err;
}
return 1;
err:
return 0;
}
static int i2r_ocsp_acutoff(X509V3_EXT_METHOD *method, void *cutoff, BIO *bp, int ind)
{
if (!BIO_printf(bp, "%*s", ind, "")) return 0;
if(!ASN1_GENERALIZEDTIME_print(bp, cutoff)) return 0;
return 1;
}
static int i2r_object(X509V3_EXT_METHOD *method, void *oid, BIO *bp, int ind)
{
if (!BIO_printf(bp, "%*s", ind, "")) return 0;
if(!i2a_ASN1_OBJECT(bp, oid)) return 0;
return 1;
}
static void *ocsp_nonce_new(void)
{
return ASN1_OCTET_STRING_new();
}
static int i2d_ocsp_nonce(void *a, unsigned char **pp)
{
ASN1_OCTET_STRING *os = a;
if(pp) {
memcpy(*pp, os->data, os->length);
*pp += os->length;
}
return os->length;
}
static void *d2i_ocsp_nonce(void *a, const unsigned char **pp, long length)
{
ASN1_OCTET_STRING *os, **pos;
pos = a;
if(!pos || !*pos) os = ASN1_OCTET_STRING_new();
else os = *pos;
if(!ASN1_OCTET_STRING_set(os, *pp, length)) goto err;
*pp += length;
if(pos) *pos = os;
return os;
err:
if(os && (!pos || (*pos != os))) M_ASN1_OCTET_STRING_free(os);
OCSPerr(OCSP_F_D2I_OCSP_NONCE, ERR_R_MALLOC_FAILURE);
return NULL;
}
static void ocsp_nonce_free(void *a)
{
M_ASN1_OCTET_STRING_free(a);
}
static int i2r_ocsp_nonce(X509V3_EXT_METHOD *method, void *nonce, BIO *out, int indent)
{
if(BIO_printf(out, "%*s", indent, "") <= 0) return 0;
if(i2a_ASN1_STRING(out, nonce, V_ASN1_OCTET_STRING) <= 0) return 0;
return 1;
}
static int i2r_ocsp_nocheck(X509V3_EXT_METHOD *method, void *nocheck, BIO *out, int indent)
{
return 1;
}
static void *s2i_ocsp_nocheck(X509V3_EXT_METHOD *method, X509V3_CTX *ctx, const char *str)
{
return ASN1_NULL_new();
}
static int i2r_ocsp_serviceloc(X509V3_EXT_METHOD *method, void *in, BIO *bp, int ind)
{
int i;
OCSP_SERVICELOC *a = in;
ACCESS_DESCRIPTION *ad;
if (BIO_printf(bp, "%*sIssuer: ", ind, "") <= 0) goto err;
if (X509_NAME_print_ex(bp, a->issuer, 0, XN_FLAG_ONELINE) <= 0) goto err;
for (i = 0; i < sk_ACCESS_DESCRIPTION_num(a->locator); i++)
{
ad = sk_ACCESS_DESCRIPTION_value(a->locator,i);
if (BIO_printf(bp, "\n%*s", (2*ind), "") <= 0)
goto err;
if(i2a_ASN1_OBJECT(bp, ad->method) <= 0) goto err;
if(BIO_puts(bp, " - ") <= 0) goto err;
if(GENERAL_NAME_print(bp, ad->location) <= 0) goto err;
}
return 1;
err:
return 0;
}
