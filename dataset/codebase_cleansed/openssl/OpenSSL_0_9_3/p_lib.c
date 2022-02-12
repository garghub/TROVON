int EVP_PKEY_bits(EVP_PKEY *pkey)
{
#ifndef NO_RSA
if (pkey->type == EVP_PKEY_RSA)
return(BN_num_bits(pkey->pkey.rsa->n));
else
#endif
#ifndef NO_DSA
if (pkey->type == EVP_PKEY_DSA)
return(BN_num_bits(pkey->pkey.dsa->p));
#endif
return(0);
}
int EVP_PKEY_size(EVP_PKEY *pkey)
{
if (pkey == NULL)
return(0);
#ifndef NO_RSA
if (pkey->type == EVP_PKEY_RSA)
return(RSA_size(pkey->pkey.rsa));
else
#endif
#ifndef NO_DSA
if (pkey->type == EVP_PKEY_DSA)
return(DSA_size(pkey->pkey.dsa));
#endif
return(0);
}
int EVP_PKEY_save_parameters(EVP_PKEY *pkey, int mode)
{
#ifndef NO_DSA
if (pkey->type == EVP_PKEY_DSA)
{
int ret=pkey->save_parameters=mode;
if (mode >= 0)
pkey->save_parameters=mode;
return(ret);
}
#endif
return(0);
}
int EVP_PKEY_copy_parameters(EVP_PKEY *to, EVP_PKEY *from)
{
if (to->type != from->type)
{
EVPerr(EVP_F_EVP_PKEY_COPY_PARAMETERS,EVP_R_DIFFERENT_KEY_TYPES);
goto err;
}
if (EVP_PKEY_missing_parameters(from))
{
EVPerr(EVP_F_EVP_PKEY_COPY_PARAMETERS,EVP_R_MISSING_PARMATERS);
goto err;
}
#ifndef NO_DSA
if (to->type == EVP_PKEY_DSA)
{
BIGNUM *a;
if ((a=BN_dup(from->pkey.dsa->p)) == NULL) goto err;
if (to->pkey.dsa->p != NULL) BN_free(to->pkey.dsa->p);
to->pkey.dsa->p=a;
if ((a=BN_dup(from->pkey.dsa->q)) == NULL) goto err;
if (to->pkey.dsa->q != NULL) BN_free(to->pkey.dsa->q);
to->pkey.dsa->q=a;
if ((a=BN_dup(from->pkey.dsa->g)) == NULL) goto err;
if (to->pkey.dsa->g != NULL) BN_free(to->pkey.dsa->g);
to->pkey.dsa->g=a;
}
#endif
return(1);
err:
return(0);
}
int EVP_PKEY_missing_parameters(EVP_PKEY *pkey)
{
#ifndef NO_DSA
if (pkey->type == EVP_PKEY_DSA)
{
DSA *dsa;
dsa=pkey->pkey.dsa;
if ((dsa->p == NULL) || (dsa->q == NULL) || (dsa->g == NULL))
return(1);
}
#endif
return(0);
}
int EVP_PKEY_cmp_parameters(EVP_PKEY *a, EVP_PKEY *b)
{
#ifndef NO_DSA
if ((a->type == EVP_PKEY_DSA) && (b->type == EVP_PKEY_DSA))
{
if ( BN_cmp(a->pkey.dsa->p,b->pkey.dsa->p) ||
BN_cmp(a->pkey.dsa->q,b->pkey.dsa->q) ||
BN_cmp(a->pkey.dsa->g,b->pkey.dsa->g))
return(0);
else
return(1);
}
#endif
return(-1);
}
EVP_PKEY *EVP_PKEY_new(void)
{
EVP_PKEY *ret;
ret=(EVP_PKEY *)Malloc(sizeof(EVP_PKEY));
if (ret == NULL)
{
EVPerr(EVP_F_EVP_PKEY_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->type=EVP_PKEY_NONE;
ret->references=1;
ret->pkey.ptr=NULL;
ret->attributes=NULL;
ret->save_parameters=1;
return(ret);
}
int EVP_PKEY_assign(EVP_PKEY *pkey, int type, char *key)
{
if (pkey == NULL) return(0);
if (pkey->pkey.ptr != NULL)
EVP_PKEY_free_it(pkey);
pkey->type=EVP_PKEY_type(type);
pkey->save_type=type;
pkey->pkey.ptr=key;
return(1);
}
int EVP_PKEY_type(int type)
{
switch (type)
{
case EVP_PKEY_RSA:
case EVP_PKEY_RSA2:
return(EVP_PKEY_RSA);
case EVP_PKEY_DSA:
case EVP_PKEY_DSA1:
case EVP_PKEY_DSA2:
case EVP_PKEY_DSA3:
case EVP_PKEY_DSA4:
return(EVP_PKEY_DSA);
case EVP_PKEY_DH:
return(EVP_PKEY_DH);
default:
return(NID_undef);
}
}
void EVP_PKEY_free(EVP_PKEY *x)
{
int i;
if (x == NULL) return;
i=CRYPTO_add(&x->references,-1,CRYPTO_LOCK_EVP_PKEY);
#ifdef REF_PRINT
REF_PRINT("EVP_PKEY",x);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"EVP_PKEY_free, bad reference count\n");
abort();
}
#endif
EVP_PKEY_free_it(x);
Free((char *)x);
}
static void EVP_PKEY_free_it(EVP_PKEY *x)
{
switch (x->type)
{
#ifndef NO_RSA
case EVP_PKEY_RSA:
case EVP_PKEY_RSA2:
RSA_free(x->pkey.rsa);
break;
#endif
#ifndef NO_DSA
case EVP_PKEY_DSA:
case EVP_PKEY_DSA2:
case EVP_PKEY_DSA3:
case EVP_PKEY_DSA4:
DSA_free(x->pkey.dsa);
break;
#endif
#ifndef NO_DH
case EVP_PKEY_DH:
DH_free(x->pkey.dh);
break;
#endif
}
}
