long MS_CALLBACK BIO_debug_callback(BIO *bio, int cmd, const char *argp,
int argi, long argl, long ret)
{
BIO *b;
MS_STATIC char buf[256];
char *p;
long r=1;
if (BIO_CB_RETURN & cmd)
r=ret;
sprintf(buf,"BIO[%08lX]:",(unsigned long)bio);
p= &(buf[14]);
switch (cmd)
{
case BIO_CB_FREE:
sprintf(p,"Free - %s\n",bio->method->name);
break;
case BIO_CB_READ:
if (bio->method->type & BIO_TYPE_DESCRIPTOR)
sprintf(p,"read(%d,%d) - %s fd=%d\n",bio->num,argi,bio->method->name,bio->num);
else
sprintf(p,"read(%d,%d) - %s\n",bio->num,argi,bio->method->name);
break;
case BIO_CB_WRITE:
if (bio->method->type & BIO_TYPE_DESCRIPTOR)
sprintf(p,"write(%d,%d) - %s fd=%d\n",bio->num,argi,bio->method->name,bio->num);
else
sprintf(p,"write(%d,%d) - %s\n",bio->num,argi,bio->method->name);
break;
case BIO_CB_PUTS:
sprintf(p,"puts() - %s\n",bio->method->name);
break;
case BIO_CB_GETS:
sprintf(p,"gets(%d) - %s\n",argi,bio->method->name);
break;
case BIO_CB_CTRL:
sprintf(p,"ctrl(%d) - %s\n",argi,bio->method->name);
break;
case BIO_CB_RETURN|BIO_CB_READ:
sprintf(p,"read return %ld\n",ret);
break;
case BIO_CB_RETURN|BIO_CB_WRITE:
sprintf(p,"write return %ld\n",ret);
break;
case BIO_CB_RETURN|BIO_CB_GETS:
sprintf(p,"gets return %ld\n",ret);
break;
case BIO_CB_RETURN|BIO_CB_PUTS:
sprintf(p,"puts return %ld\n",ret);
break;
case BIO_CB_RETURN|BIO_CB_CTRL:
sprintf(p,"ctrl return %ld\n",ret);
break;
default:
sprintf(p,"bio callback - unknown type (%d)\n",cmd);
break;
}
b=(BIO *)bio->cb_arg;
if (b != NULL)
BIO_write(b,buf,strlen(buf));
#if !defined(NO_STDIO) && !defined(WIN16)
else
fputs(buf,stderr);
#endif
return(r);
}
