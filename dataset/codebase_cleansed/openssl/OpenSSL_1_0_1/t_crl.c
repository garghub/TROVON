int X509_CRL_print_fp(FILE *fp, X509_CRL *x)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
X509err(X509_F_X509_CRL_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=X509_CRL_print(b, x);
BIO_free(b);
return(ret);
}
int X509_CRL_print(BIO *out, X509_CRL *x)
{
STACK_OF(X509_REVOKED) *rev;
X509_REVOKED *r;
long l;
int i;
char *p;
BIO_printf(out, "Certificate Revocation List (CRL):\n");
l = X509_CRL_get_version(x);
BIO_printf(out, "%8sVersion %lu (0x%lx)\n", "", l+1, l);
i = OBJ_obj2nid(x->sig_alg->algorithm);
X509_signature_print(out, x->sig_alg, NULL);
p=X509_NAME_oneline(X509_CRL_get_issuer(x),NULL,0);
BIO_printf(out,"%8sIssuer: %s\n","",p);
OPENSSL_free(p);
BIO_printf(out,"%8sLast Update: ","");
ASN1_TIME_print(out,X509_CRL_get_lastUpdate(x));
BIO_printf(out,"\n%8sNext Update: ","");
if (X509_CRL_get_nextUpdate(x))
ASN1_TIME_print(out,X509_CRL_get_nextUpdate(x));
else BIO_printf(out,"NONE");
BIO_printf(out,"\n");
X509V3_extensions_print(out, "CRL extensions",
x->crl->extensions, 0, 8);
rev = X509_CRL_get_REVOKED(x);
if(sk_X509_REVOKED_num(rev) > 0)
BIO_printf(out, "Revoked Certificates:\n");
else BIO_printf(out, "No Revoked Certificates.\n");
for(i = 0; i < sk_X509_REVOKED_num(rev); i++) {
r = sk_X509_REVOKED_value(rev, i);
BIO_printf(out," Serial Number: ");
i2a_ASN1_INTEGER(out,r->serialNumber);
BIO_printf(out,"\n Revocation Date: ");
ASN1_TIME_print(out,r->revocationDate);
BIO_printf(out,"\n");
X509V3_extensions_print(out, "CRL entry extensions",
r->extensions, 0, 8);
}
X509_signature_print(out, x->sig_alg, x->signature);
return 1;
}
