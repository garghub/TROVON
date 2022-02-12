int X509_REQ_print_fp(FILE *fp, X509_REQ *x)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
X509err(X509_F_X509_REQ_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=X509_REQ_print(b, x);
BIO_free(b);
return(ret);
}
int X509_REQ_print_ex(BIO *bp, X509_REQ *x, unsigned long nmflags, unsigned long cflag)
{
unsigned long l;
int i;
const char *neg;
X509_REQ_INFO *ri;
EVP_PKEY *pkey;
STACK_OF(X509_ATTRIBUTE) *sk;
STACK_OF(X509_EXTENSION) *exts;
char mlch = ' ';
int nmindent = 0;
if((nmflags & XN_FLAG_SEP_MASK) == XN_FLAG_SEP_MULTILINE) {
mlch = '\n';
nmindent = 12;
}
if(nmflags == X509_FLAG_COMPAT)
nmindent = 16;
ri=x->req_info;
if(!(cflag & X509_FLAG_NO_HEADER))
{
if (BIO_write(bp,"Certificate Request:\n",21) <= 0) goto err;
if (BIO_write(bp," Data:\n",10) <= 0) goto err;
}
if(!(cflag & X509_FLAG_NO_VERSION))
{
neg=(ri->version->type == V_ASN1_NEG_INTEGER)?"-":"";
l=0;
for (i=0; i<ri->version->length; i++)
{ l<<=8; l+=ri->version->data[i]; }
if(BIO_printf(bp,"%8sVersion: %s%lu (%s0x%lx)\n","",neg,l,neg,
l) <= 0)
goto err;
}
if(!(cflag & X509_FLAG_NO_SUBJECT))
{
if (BIO_printf(bp," Subject:%c",mlch) <= 0) goto err;
if (X509_NAME_print_ex(bp,ri->subject,nmindent, nmflags) < 0) goto err;
if (BIO_write(bp,"\n",1) <= 0) goto err;
}
if(!(cflag & X509_FLAG_NO_PUBKEY))
{
if (BIO_write(bp," Subject Public Key Info:\n",33) <= 0)
goto err;
if (BIO_printf(bp,"%12sPublic Key Algorithm: ","") <= 0)
goto err;
if (i2a_ASN1_OBJECT(bp, ri->pubkey->algor->algorithm) <= 0)
goto err;
if (BIO_puts(bp, "\n") <= 0)
goto err;
pkey=X509_REQ_get_pubkey(x);
if (pkey == NULL)
{
BIO_printf(bp,"%12sUnable to load Public Key\n","");
ERR_print_errors(bp);
}
else
{
EVP_PKEY_print_public(bp, pkey, 16, NULL);
EVP_PKEY_free(pkey);
}
}
if(!(cflag & X509_FLAG_NO_ATTRIBUTES))
{
if(BIO_printf(bp,"%8sAttributes:\n","") <= 0)
goto err;
sk=x->req_info->attributes;
if (sk_X509_ATTRIBUTE_num(sk) == 0)
{
if(BIO_printf(bp,"%12sa0:00\n","") <= 0)
goto err;
}
else
{
for (i=0; i<sk_X509_ATTRIBUTE_num(sk); i++)
{
ASN1_TYPE *at;
X509_ATTRIBUTE *a;
ASN1_BIT_STRING *bs=NULL;
ASN1_TYPE *t;
int j,type=0,count=1,ii=0;
a=sk_X509_ATTRIBUTE_value(sk,i);
if(X509_REQ_extension_nid(OBJ_obj2nid(a->object)))
continue;
if(BIO_printf(bp,"%12s","") <= 0)
goto err;
if ((j=i2a_ASN1_OBJECT(bp,a->object)) > 0)
{
if (a->single)
{
t=a->value.single;
type=t->type;
bs=t->value.bit_string;
}
else
{
ii=0;
count=sk_ASN1_TYPE_num(a->value.set);
get_next:
at=sk_ASN1_TYPE_value(a->value.set,ii);
type=at->type;
bs=at->value.asn1_string;
}
}
for (j=25-j; j>0; j--)
if (BIO_write(bp," ",1) != 1) goto err;
if (BIO_puts(bp,":") <= 0) goto err;
if ( (type == V_ASN1_PRINTABLESTRING) ||
(type == V_ASN1_T61STRING) ||
(type == V_ASN1_IA5STRING))
{
if (BIO_write(bp,(char *)bs->data,bs->length)
!= bs->length)
goto err;
BIO_puts(bp,"\n");
}
else
{
BIO_puts(bp,"unable to print attribute\n");
}
if (++ii < count) goto get_next;
}
}
}
if(!(cflag & X509_FLAG_NO_EXTENSIONS))
{
exts = X509_REQ_get_extensions(x);
if(exts)
{
BIO_printf(bp,"%8sRequested Extensions:\n","");
for (i=0; i<sk_X509_EXTENSION_num(exts); i++)
{
ASN1_OBJECT *obj;
X509_EXTENSION *ex;
int j;
ex=sk_X509_EXTENSION_value(exts, i);
if (BIO_printf(bp,"%12s","") <= 0) goto err;
obj=X509_EXTENSION_get_object(ex);
i2a_ASN1_OBJECT(bp,obj);
j=X509_EXTENSION_get_critical(ex);
if (BIO_printf(bp,": %s\n",j?"critical":"") <= 0)
goto err;
if(!X509V3_EXT_print(bp, ex, cflag, 16))
{
BIO_printf(bp, "%16s", "");
M_ASN1_OCTET_STRING_print(bp,ex->value);
}
if (BIO_write(bp,"\n",1) <= 0) goto err;
}
sk_X509_EXTENSION_pop_free(exts, X509_EXTENSION_free);
}
}
if(!(cflag & X509_FLAG_NO_SIGDUMP))
{
if(!X509_signature_print(bp, x->sig_alg, x->signature)) goto err;
}
return(1);
err:
X509err(X509_F_X509_REQ_PRINT_EX,ERR_R_BUF_LIB);
return(0);
}
int X509_REQ_print(BIO *bp, X509_REQ *x)
{
return X509_REQ_print_ex(bp, x, XN_FLAG_COMPAT, X509_FLAG_COMPAT);
}
