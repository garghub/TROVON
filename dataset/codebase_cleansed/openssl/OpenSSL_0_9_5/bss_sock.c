BIO_METHOD *BIO_s_socket(void)
{
return(&methods_sockp);
}
BIO_METHOD *BIO_s_fd(void)
{
return(&methods_fdp);
}
static int sock_gets(BIO *bp, char *buf,int size)
{
return(-1);
}
