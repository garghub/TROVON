long BIO_debug_callback(BIO *bio, int cmd, const char *argp,
int argi, long argl, long ret)
{
BIO *b;
char buf[256];
char *p;
long r = 1;
int len;
size_t p_maxlen;
if (BIO_CB_RETURN & cmd)
r = ret;
len = BIO_snprintf(buf, sizeof buf, "BIO[%p]: ", (void *)bio);
if (len < 0)
len = 0;
p = buf + len;
p_maxlen = sizeof(buf) - len;
switch (cmd) {
case BIO_CB_FREE:
BIO_snprintf(p, p_maxlen, "Free - %s\n", bio->method->name);
break;
case BIO_CB_READ:
if (bio->method->type & BIO_TYPE_DESCRIPTOR)
BIO_snprintf(p, p_maxlen, "read(%d,%lu) - %s fd=%d\n",
bio->num, (unsigned long)argi,
bio->method->name, bio->num);
else
BIO_snprintf(p, p_maxlen, "read(%d,%lu) - %s\n",
bio->num, (unsigned long)argi, bio->method->name);
break;
case BIO_CB_WRITE:
if (bio->method->type & BIO_TYPE_DESCRIPTOR)
BIO_snprintf(p, p_maxlen, "write(%d,%lu) - %s fd=%d\n",
bio->num, (unsigned long)argi,
bio->method->name, bio->num);
else
BIO_snprintf(p, p_maxlen, "write(%d,%lu) - %s\n",
bio->num, (unsigned long)argi, bio->method->name);
break;
case BIO_CB_PUTS:
BIO_snprintf(p, p_maxlen, "puts() - %s\n", bio->method->name);
break;
case BIO_CB_GETS:
BIO_snprintf(p, p_maxlen, "gets(%lu) - %s\n", (unsigned long)argi,
bio->method->name);
break;
case BIO_CB_CTRL:
BIO_snprintf(p, p_maxlen, "ctrl(%lu) - %s\n", (unsigned long)argi,
bio->method->name);
break;
case BIO_CB_RETURN | BIO_CB_READ:
BIO_snprintf(p, p_maxlen, "read return %ld\n", ret);
break;
case BIO_CB_RETURN | BIO_CB_WRITE:
BIO_snprintf(p, p_maxlen, "write return %ld\n", ret);
break;
case BIO_CB_RETURN | BIO_CB_GETS:
BIO_snprintf(p, p_maxlen, "gets return %ld\n", ret);
break;
case BIO_CB_RETURN | BIO_CB_PUTS:
BIO_snprintf(p, p_maxlen, "puts return %ld\n", ret);
break;
case BIO_CB_RETURN | BIO_CB_CTRL:
BIO_snprintf(p, p_maxlen, "ctrl return %ld\n", ret);
break;
default:
BIO_snprintf(p, p_maxlen, "bio callback - unknown type (%d)\n", cmd);
break;
}
b = (BIO *)bio->cb_arg;
if (b != NULL)
BIO_write(b, buf, strlen(buf));
#if !defined(OPENSSL_NO_STDIO)
else
fputs(buf, stderr);
#endif
return (r);
}
