int X509_CRL_print_fp(FILE *fp, X509_CRL *x)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
X509err(X509_F_X509_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=X509_CRL_print(b, x);
BIO_free(b);
return(ret);
}
int X509_CRL_print(BIO *out, X509_CRL *x)
{
char buf[256];
unsigned char *s;
STACK_OF(X509_REVOKED) *rev;
X509_REVOKED *r;
long l;
int i, j, n;
BIO_printf(out, "Certificate Revocation List (CRL):\n");
l = X509_CRL_get_version(x);
BIO_printf(out, "%8sVersion %lu (0x%lx)\n", "", l+1, l);
i = OBJ_obj2nid(x->sig_alg->algorithm);
BIO_printf(out, "%8sSignature Algorithm: %s\n", "",
(i == NID_undef) ? "NONE" : OBJ_nid2ln(i));
X509_NAME_oneline(X509_CRL_get_issuer(x),buf,256);
BIO_printf(out,"%8sIssuer: %s\n","",buf);
BIO_printf(out,"%8sLast Update: ","");
ASN1_TIME_print(out,X509_CRL_get_lastUpdate(x));
BIO_printf(out,"\n%8sNext Update: ","");
if (X509_CRL_get_nextUpdate(x))
ASN1_TIME_print(out,X509_CRL_get_nextUpdate(x));
else BIO_printf(out,"NONE");
BIO_printf(out,"\n");
n=X509_CRL_get_ext_count(x);
if (n > 0) {
BIO_printf(out,"%8sCRL extensions:\n","");
for (i=0; i<n; i++) ext_print(out, X509_CRL_get_ext(x, i));
}
rev = X509_CRL_get_REVOKED(x);
if(sk_X509_REVOKED_num(rev))
BIO_printf(out, "Revoked Certificates:\n");
else BIO_printf(out, "No Revoked Certificates.\n");
for(i = 0; i < sk_X509_REVOKED_num(rev); i++) {
r = sk_X509_REVOKED_value(rev, i);
BIO_printf(out," Serial Number: ");
i2a_ASN1_INTEGER(out,r->serialNumber);
BIO_printf(out,"\n Revocation Date: ","");
ASN1_TIME_print(out,r->revocationDate);
BIO_printf(out,"\n");
for(j = 0; j < X509_REVOKED_get_ext_count(r); j++)
ext_print(out, X509_REVOKED_get_ext(r, j));
}
i=OBJ_obj2nid(x->sig_alg->algorithm);
BIO_printf(out," Signature Algorithm: %s",
(i == NID_undef)?"UNKNOWN":OBJ_nid2ln(i));
s = x->signature->data;
n = x->signature->length;
for (i=0; i<n; i++, s++)
{
if ((i%18) == 0) BIO_write(out,"\n ",9);
BIO_printf(out,"%02x%s",*s, ((i+1) == n)?"":":");
}
BIO_write(out,"\n",1);
return 1;
}
static void ext_print(BIO *out, X509_EXTENSION *ex)
{
ASN1_OBJECT *obj;
int j;
BIO_printf(out,"%12s","");
obj=X509_EXTENSION_get_object(ex);
i2a_ASN1_OBJECT(out,obj);
j=X509_EXTENSION_get_critical(ex);
BIO_printf(out, ": %s\n", j ? "critical":"","");
if(!X509V3_EXT_print(out, ex, 0, 16)) {
BIO_printf(out, "%16s", "");
M_ASN1_OCTET_STRING_print(out,ex->value);
}
BIO_write(out,"\n",1);
}
