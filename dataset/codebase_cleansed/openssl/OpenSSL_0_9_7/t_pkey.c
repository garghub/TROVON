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
char str[128];
const char *s;
unsigned char *m=NULL;
int ret=0;
size_t buf_len=0, i;
if (x->n)
buf_len = (size_t)BN_num_bytes(x->n);
if (x->e)
if (buf_len < (i = (size_t)BN_num_bytes(x->e)))
buf_len = i;
if (x->d)
if (buf_len < (i = (size_t)BN_num_bytes(x->d)))
buf_len = i;
if (x->p)
if (buf_len < (i = (size_t)BN_num_bytes(x->p)))
buf_len = i;
if (x->q)
if (buf_len < (i = (size_t)BN_num_bytes(x->q)))
buf_len = i;
if (x->dmp1)
if (buf_len < (i = (size_t)BN_num_bytes(x->dmp1)))
buf_len = i;
if (x->dmq1)
if (buf_len < (i = (size_t)BN_num_bytes(x->dmq1)))
buf_len = i;
if (x->iqmp)
if (buf_len < (i = (size_t)BN_num_bytes(x->iqmp)))
buf_len = i;
m=(unsigned char *)OPENSSL_malloc(buf_len+10);
if (m == NULL)
{
RSAerr(RSA_F_RSA_PRINT,ERR_R_MALLOC_FAILURE);
goto err;
}
if (x->d != NULL)
{
if(!BIO_indent(bp,off,128))
goto err;
if (BIO_printf(bp,"Private-Key: (%d bit)\n",BN_num_bits(x->n))
<= 0) goto err;
}
if (x->d == NULL)
sprintf(str,"Modulus (%d bit):",BN_num_bits(x->n));
else
strcpy(str,"modulus:");
if (!print(bp,str,x->n,m,off)) goto err;
s=(x->d == NULL)?"Exponent:":"publicExponent:";
if (!print(bp,s,x->e,m,off)) goto err;
if (!print(bp,"privateExponent:",x->d,m,off)) goto err;
if (!print(bp,"prime1:",x->p,m,off)) goto err;
if (!print(bp,"prime2:",x->q,m,off)) goto err;
if (!print(bp,"exponent1:",x->dmp1,m,off)) goto err;
if (!print(bp,"exponent2:",x->dmq1,m,off)) goto err;
if (!print(bp,"coefficient:",x->iqmp,m,off)) goto err;
ret=1;
err:
if (m != NULL) OPENSSL_free(m);
return(ret);
}
int DSA_print_fp(FILE *fp, const DSA *x, int off)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
DSAerr(DSA_F_DSA_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=DSA_print(b,x,off);
BIO_free(b);
return(ret);
}
int DSA_print(BIO *bp, const DSA *x, int off)
{
unsigned char *m=NULL;
int ret=0;
size_t buf_len=0,i;
if (x->p)
buf_len = (size_t)BN_num_bytes(x->p);
if (x->q)
if (buf_len < (i = (size_t)BN_num_bytes(x->q)))
buf_len = i;
if (x->g)
if (buf_len < (i = (size_t)BN_num_bytes(x->g)))
buf_len = i;
if (x->priv_key)
if (buf_len < (i = (size_t)BN_num_bytes(x->priv_key)))
buf_len = i;
if (x->pub_key)
if (buf_len < (i = (size_t)BN_num_bytes(x->pub_key)))
buf_len = i;
m=(unsigned char *)OPENSSL_malloc(buf_len+10);
if (m == NULL)
{
DSAerr(DSA_F_DSA_PRINT,ERR_R_MALLOC_FAILURE);
goto err;
}
if (x->priv_key != NULL)
{
if(!BIO_indent(bp,off,128))
goto err;
if (BIO_printf(bp,"Private-Key: (%d bit)\n",BN_num_bits(x->p))
<= 0) goto err;
}
if ((x->priv_key != NULL) && !print(bp,"priv:",x->priv_key,m,off))
goto err;
if ((x->pub_key != NULL) && !print(bp,"pub: ",x->pub_key,m,off))
goto err;
if ((x->p != NULL) && !print(bp,"P: ",x->p,m,off)) goto err;
if ((x->q != NULL) && !print(bp,"Q: ",x->q,m,off)) goto err;
if ((x->g != NULL) && !print(bp,"G: ",x->g,m,off)) goto err;
ret=1;
err:
if (m != NULL) OPENSSL_free(m);
return(ret);
}
static int print(BIO *bp, const char *number, BIGNUM *num, unsigned char *buf,
int off)
{
int n,i;
const char *neg;
if (num == NULL) return(1);
neg=(num->neg)?"-":"";
if(!BIO_indent(bp,off,128))
return 0;
if (BN_num_bytes(num) <= BN_BYTES)
{
if (BIO_printf(bp,"%s %s%lu (%s0x%lx)\n",number,neg,
(unsigned long)num->d[0],neg,(unsigned long)num->d[0])
<= 0) return(0);
}
else
{
buf[0]=0;
if (BIO_printf(bp,"%s%s",number,
(neg[0] == '-')?" (Negative)":"") <= 0)
return(0);
n=BN_bn2bin(num,&buf[1]);
if (buf[1] & 0x80)
n++;
else buf++;
for (i=0; i<n; i++)
{
if ((i%15) == 0)
{
if(BIO_puts(bp,"\n") <= 0
|| !BIO_indent(bp,off+4,128))
return 0;
}
if (BIO_printf(bp,"%02x%s",buf[i],((i+1) == n)?"":":")
<= 0) return(0);
}
if (BIO_write(bp,"\n",1) <= 0) return(0);
}
return(1);
}
int DHparams_print_fp(FILE *fp, const DH *x)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
DHerr(DH_F_DHPARAMS_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=DHparams_print(b, x);
BIO_free(b);
return(ret);
}
int DHparams_print(BIO *bp, const DH *x)
{
unsigned char *m=NULL;
int reason=ERR_R_BUF_LIB,ret=0;
size_t buf_len=0, i;
if (x->p)
buf_len = (size_t)BN_num_bytes(x->p);
if (x->g)
if (buf_len < (i = (size_t)BN_num_bytes(x->g)))
buf_len = i;
m=(unsigned char *)OPENSSL_malloc(buf_len+10);
if (m == NULL)
{
reason=ERR_R_MALLOC_FAILURE;
goto err;
}
if (BIO_printf(bp,"Diffie-Hellman-Parameters: (%d bit)\n",
BN_num_bits(x->p)) <= 0)
goto err;
if (!print(bp,"prime:",x->p,m,4)) goto err;
if (!print(bp,"generator:",x->g,m,4)) goto err;
if (x->length != 0)
{
if (BIO_printf(bp," recommended-private-length: %d bits\n",
(int)x->length) <= 0) goto err;
}
ret=1;
if (0)
{
err:
DHerr(DH_F_DHPARAMS_PRINT,reason);
}
if (m != NULL) OPENSSL_free(m);
return(ret);
}
int DSAparams_print_fp(FILE *fp, const DSA *x)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
DSAerr(DSA_F_DSAPARAMS_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=DSAparams_print(b, x);
BIO_free(b);
return(ret);
}
int DSAparams_print(BIO *bp, const DSA *x)
{
unsigned char *m=NULL;
int reason=ERR_R_BUF_LIB,ret=0;
size_t buf_len=0,i;
if (x->p)
buf_len = (size_t)BN_num_bytes(x->p);
if (x->q)
if (buf_len < (i = (size_t)BN_num_bytes(x->q)))
buf_len = i;
if (x->g)
if (buf_len < (i = (size_t)BN_num_bytes(x->g)))
buf_len = i;
m=(unsigned char *)OPENSSL_malloc(buf_len+10);
if (m == NULL)
{
reason=ERR_R_MALLOC_FAILURE;
goto err;
}
if (BIO_printf(bp,"DSA-Parameters: (%d bit)\n",
BN_num_bits(x->p)) <= 0)
goto err;
if (!print(bp,"p:",x->p,m,4)) goto err;
if (!print(bp,"q:",x->q,m,4)) goto err;
if (!print(bp,"g:",x->g,m,4)) goto err;
ret=1;
err:
if (m != NULL) OPENSSL_free(m);
DSAerr(DSA_F_DSAPARAMS_PRINT,reason);
return(ret);
}
