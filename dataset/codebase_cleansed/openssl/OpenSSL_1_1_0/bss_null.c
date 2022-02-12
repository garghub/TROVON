const BIO_METHOD *BIO_s_null(void)
{
return (&null_method);
}
static int null_new(BIO *bi)
{
bi->init = 1;
bi->num = 0;
bi->ptr = (NULL);
return (1);
}
static int null_free(BIO *a)
{
if (a == NULL)
return (0);
return (1);
}
static int null_read(BIO *b, char *out, int outl)
{
return (0);
}
static int null_write(BIO *b, const char *in, int inl)
{
return (inl);
}
static long null_ctrl(BIO *b, int cmd, long num, void *ptr)
{
long ret = 1;
switch (cmd) {
case BIO_CTRL_RESET:
case BIO_CTRL_EOF:
case BIO_CTRL_SET:
case BIO_CTRL_SET_CLOSE:
case BIO_CTRL_FLUSH:
case BIO_CTRL_DUP:
ret = 1;
break;
case BIO_CTRL_GET_CLOSE:
case BIO_CTRL_INFO:
case BIO_CTRL_GET:
case BIO_CTRL_PENDING:
case BIO_CTRL_WPENDING:
default:
ret = 0;
break;
}
return (ret);
}
static int null_gets(BIO *bp, char *buf, int size)
{
return (0);
}
static int null_puts(BIO *bp, const char *str)
{
if (str == NULL)
return (0);
return (strlen(str));
}
