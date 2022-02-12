const RSA_METHOD *RSA_null_method(void)
{
return(&rsa_null_meth);
}
static int RSA_null_public_encrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
RSAerr(RSA_F_RSA_NULL, RSA_R_RSA_OPERATIONS_NOT_SUPPORTED);
return -1;
}
static int RSA_null_private_encrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
RSAerr(RSA_F_RSA_NULL, RSA_R_RSA_OPERATIONS_NOT_SUPPORTED);
return -1;
}
static int RSA_null_private_decrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
RSAerr(RSA_F_RSA_NULL, RSA_R_RSA_OPERATIONS_NOT_SUPPORTED);
return -1;
}
static int RSA_null_public_decrypt(int flen, const unsigned char *from,
unsigned char *to, RSA *rsa, int padding)
{
RSAerr(RSA_F_RSA_NULL, RSA_R_RSA_OPERATIONS_NOT_SUPPORTED);
return -1;
}
static int RSA_null_init(RSA *rsa)
{
return(1);
}
static int RSA_null_finish(RSA *rsa)
{
return(1);
}
