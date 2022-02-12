int i2d_X509_PUBKEY(X509_PUBKEY *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->algor, i2d_X509_ALGOR);
M_ASN1_I2D_len(a->public_key, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->algor, i2d_X509_ALGOR);
M_ASN1_I2D_put(a->public_key, i2d_ASN1_BIT_STRING);
M_ASN1_I2D_finish();
}
X509_PUBKEY *d2i_X509_PUBKEY(X509_PUBKEY **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,X509_PUBKEY *,X509_PUBKEY_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->algor,d2i_X509_ALGOR);
M_ASN1_D2I_get(ret->public_key,d2i_ASN1_BIT_STRING);
if (ret->pkey != NULL)
{
EVP_PKEY_free(ret->pkey);
ret->pkey=NULL;
}
M_ASN1_D2I_Finish(a,X509_PUBKEY_free,ASN1_F_D2I_X509_PUBKEY);
}
X509_PUBKEY *X509_PUBKEY_new(void)
{
X509_PUBKEY *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_PUBKEY);
M_ASN1_New(ret->algor,X509_ALGOR_new);
M_ASN1_New(ret->public_key,M_ASN1_BIT_STRING_new);
ret->pkey=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_PUBKEY_NEW);
}
void X509_PUBKEY_free(X509_PUBKEY *a)
{
if (a == NULL) return;
X509_ALGOR_free(a->algor);
M_ASN1_BIT_STRING_free(a->public_key);
if (a->pkey != NULL) EVP_PKEY_free(a->pkey);
Free(a);
}
int X509_PUBKEY_set(X509_PUBKEY **x, EVP_PKEY *pkey)
{
int ok=0;
X509_PUBKEY *pk;
X509_ALGOR *a;
ASN1_OBJECT *o;
unsigned char *s,*p;
int i;
if (x == NULL) return(0);
if ((pk=X509_PUBKEY_new()) == NULL) goto err;
a=pk->algor;
if ((o=OBJ_nid2obj(pkey->type)) == NULL) goto err;
ASN1_OBJECT_free(a->algorithm);
a->algorithm=o;
if (!pkey->save_parameters || (pkey->type == EVP_PKEY_RSA))
{
if ((a->parameter == NULL) ||
(a->parameter->type != V_ASN1_NULL))
{
ASN1_TYPE_free(a->parameter);
a->parameter=ASN1_TYPE_new();
a->parameter->type=V_ASN1_NULL;
}
}
else
#ifndef NO_DSA
if (pkey->type == EVP_PKEY_DSA)
{
unsigned char *pp;
DSA *dsa;
dsa=pkey->pkey.dsa;
dsa->write_params=0;
ASN1_TYPE_free(a->parameter);
i=i2d_DSAparams(dsa,NULL);
p=(unsigned char *)Malloc(i);
pp=p;
i2d_DSAparams(dsa,&pp);
a->parameter=ASN1_TYPE_new();
a->parameter->type=V_ASN1_SEQUENCE;
a->parameter->value.sequence=ASN1_STRING_new();
ASN1_STRING_set(a->parameter->value.sequence,p,i);
Free(p);
}
else
#endif
{
X509err(X509_F_X509_PUBKEY_SET,X509_R_UNSUPPORTED_ALGORITHM);
goto err;
}
if ((i=i2d_PublicKey(pkey,NULL)) <= 0) goto err;
if ((s=(unsigned char *)Malloc(i+1)) == NULL) goto err;
p=s;
i2d_PublicKey(pkey,&p);
if (!M_ASN1_BIT_STRING_set(pk->public_key,s,i)) goto err;
pk->public_key->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
pk->public_key->flags|=ASN1_STRING_FLAG_BITS_LEFT;
Free(s);
CRYPTO_add(&pkey->references,1,CRYPTO_LOCK_EVP_PKEY);
pk->pkey=pkey;
if (*x != NULL)
X509_PUBKEY_free(*x);
*x=pk;
pk=NULL;
ok=1;
err:
if (pk != NULL) X509_PUBKEY_free(pk);
return(ok);
}
EVP_PKEY *X509_PUBKEY_get(X509_PUBKEY *key)
{
EVP_PKEY *ret=NULL;
long j;
int type;
unsigned char *p;
#ifndef NO_DSA
X509_ALGOR *a;
#endif
if (key == NULL) goto err;
if (key->pkey != NULL)
{
CRYPTO_add(&key->pkey->references,1,CRYPTO_LOCK_EVP_PKEY);
return(key->pkey);
}
if (key->public_key == NULL) goto err;
type=OBJ_obj2nid(key->algor->algorithm);
p=key->public_key->data;
j=key->public_key->length;
if ((ret=d2i_PublicKey(type,NULL,&p,(long)j)) == NULL)
{
X509err(X509_F_X509_PUBKEY_GET,X509_R_ERR_ASN1_LIB);
goto err;
}
ret->save_parameters=0;
#ifndef NO_DSA
a=key->algor;
if (ret->type == EVP_PKEY_DSA)
{
if (a->parameter->type == V_ASN1_SEQUENCE)
{
ret->pkey.dsa->write_params=0;
p=a->parameter->value.sequence->data;
j=a->parameter->value.sequence->length;
if (!d2i_DSAparams(&ret->pkey.dsa,&p,(long)j))
goto err;
}
ret->save_parameters=1;
}
#endif
key->pkey=ret;
CRYPTO_add(&ret->references,1,CRYPTO_LOCK_EVP_PKEY);
return(ret);
err:
if (ret != NULL)
EVP_PKEY_free(ret);
return(NULL);
}
EVP_PKEY *d2i_PUBKEY(EVP_PKEY **a, unsigned char **pp,
long length)
{
X509_PUBKEY *xpk;
EVP_PKEY *pktmp;
xpk = d2i_X509_PUBKEY(NULL, pp, length);
if(!xpk) return NULL;
pktmp = X509_PUBKEY_get(xpk);
X509_PUBKEY_free(xpk);
if(!pktmp) return NULL;
if(a) {
EVP_PKEY_free(*a);
*a = pktmp;
}
return pktmp;
}
int i2d_PUBKEY(EVP_PKEY *a, unsigned char **pp)
{
X509_PUBKEY *xpk=NULL;
int ret;
if(!a) return 0;
if(!X509_PUBKEY_set(&xpk, a)) return 0;
ret = i2d_X509_PUBKEY(xpk, pp);
X509_PUBKEY_free(xpk);
return ret;
}
RSA *d2i_RSA_PUBKEY(RSA **a, unsigned char **pp,
long length)
{
EVP_PKEY *pkey;
RSA *key;
unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if(!pkey) return NULL;
key = EVP_PKEY_get1_RSA(pkey);
EVP_PKEY_free(pkey);
if(!key) return NULL;
*pp = q;
if(a) {
RSA_free(*a);
*a = key;
}
return key;
}
int i2d_RSA_PUBKEY(RSA *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if(!a) return 0;
pktmp = EVP_PKEY_new();
if(!pktmp) {
ASN1err(ASN1_F_I2D_RSA_PUBKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
EVP_PKEY_set1_RSA(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return ret;
}
DSA *d2i_DSA_PUBKEY(DSA **a, unsigned char **pp,
long length)
{
EVP_PKEY *pkey;
DSA *key;
unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if(!pkey) return NULL;
key = EVP_PKEY_get1_DSA(pkey);
EVP_PKEY_free(pkey);
if(!key) return NULL;
*pp = q;
if(a) {
DSA_free(*a);
*a = key;
}
return key;
}
int i2d_DSA_PUBKEY(DSA *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if(!a) return 0;
pktmp = EVP_PKEY_new();
if(!pktmp) {
ASN1err(ASN1_F_I2D_DSA_PUBKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
EVP_PKEY_set1_DSA(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return ret;
}
