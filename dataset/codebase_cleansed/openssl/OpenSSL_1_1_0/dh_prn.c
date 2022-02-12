int DHparams_print_fp(FILE *fp, const DH *x)
{
BIO *b;
int ret;
if ((b = BIO_new(BIO_s_file())) == NULL) {
DHerr(DH_F_DHPARAMS_PRINT_FP, ERR_R_BUF_LIB);
return (0);
}
BIO_set_fp(b, fp, BIO_NOCLOSE);
ret = DHparams_print(b, x);
BIO_free(b);
return (ret);
}
