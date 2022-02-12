int RSA_print_fp(FILE *fp, const RSA *x, int off)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
RSAerr(RSA_F_RSA_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=RSA_print(b,x,off);
BIO_free(b);
return(ret);
}
int RSA_print(BIO *bp, const RSA *x, int off)
{
EVP_PKEY *pk;
int ret;
pk = EVP_PKEY_new();
if (!pk || !EVP_PKEY_set1_RSA(pk, (RSA *)x))
return 0;
ret = EVP_PKEY_print_private(bp, pk, off, NULL);
EVP_PKEY_free(pk);
return ret;
}
