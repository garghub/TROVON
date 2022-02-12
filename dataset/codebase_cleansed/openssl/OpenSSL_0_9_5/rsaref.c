RSA_METHOD *RSA_PKCS1_RSAref(void)
{
return(&rsa_pkcs1_ref_meth);
}
static int RSA_ref_mod_exp(BIGNUM *r0, BIGNUM *I, RSA *rsa)
{
RSAREFerr(RSAREF_F_RSA_REF_MOD_EXP,ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
static int BN_ref_mod_exp(BIGNUM *r, BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
RSAREFerr(RSAREF_F_BN_REF_MOD_EXP,ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return(0);
}
static int RSAref_bn2bin(BIGNUM *from, unsigned char *to, int max)
{
int i;
i=BN_num_bytes(from);
if (i > max)
{
RSAREFerr(RSAREF_F_RSAREF_BN2BIN,RSAREF_R_LEN);
return(0);
}
memset(to,0,(unsigned int)max);
if (!BN_bn2bin(from,&(to[max-i])))
return(0);
return(1);
}
static BIGNUM *RSAref_bin2bn(unsigned char *from, BIGNUM *to, int max)
{
int i;
BIGNUM *ret;
for (i=0; i<max; i++)
if (from[i]) break;
ret=BN_bin2bn(&(from[i]),max-i,to);
return(ret);
}
static int RSAref_Public_ref2eay(RSArefPublicKey *from, RSA *to)
{
to->n=RSAref_bin2bn(from->m,NULL,RSAref_MAX_LEN);
to->e=RSAref_bin2bn(from->e,NULL,RSAref_MAX_LEN);
if ((to->n == NULL) || (to->e == NULL)) return(0);
return(1);
}
static int RSAref_Public_eay2ref(RSA *from, RSArefPublicKey *to)
{
to->bits=BN_num_bits(from->n);
if (!RSAref_bn2bin(from->n,to->m,RSAref_MAX_LEN)) return(0);
if (!RSAref_bn2bin(from->e,to->e,RSAref_MAX_LEN)) return(0);
return(1);
}
static int RSAref_Private_ref2eay(RSArefPrivateKey *from, RSA *to)
{
if ((to->n=RSAref_bin2bn(from->m,NULL,RSAref_MAX_LEN)) == NULL)
return(0);
if ((to->e=RSAref_bin2bn(from->e,NULL,RSAref_MAX_LEN)) == NULL)
return(0);
if ((to->d=RSAref_bin2bn(from->d,NULL,RSAref_MAX_LEN)) == NULL)
return(0);
if ((to->p=RSAref_bin2bn(from->prime[0],NULL,RSAref_MAX_PLEN)) == NULL)
return(0);
if ((to->q=RSAref_bin2bn(from->prime[1],NULL,RSAref_MAX_PLEN)) == NULL)
return(0);
if ((to->dmp1=RSAref_bin2bn(from->pexp[0],NULL,RSAref_MAX_PLEN))
== NULL)
return(0);
if ((to->dmq1=RSAref_bin2bn(from->pexp[1],NULL,RSAref_MAX_PLEN))
== NULL)
return(0);
if ((to->iqmp=RSAref_bin2bn(from->coef,NULL,RSAref_MAX_PLEN)) == NULL)
return(0);
return(1);
}
static int RSAref_Private_eay2ref(RSA *from, RSArefPrivateKey *to)
{
to->bits=BN_num_bits(from->n);
if (!RSAref_bn2bin(from->n,to->m,RSAref_MAX_LEN)) return(0);
if (!RSAref_bn2bin(from->e,to->e,RSAref_MAX_LEN)) return(0);
if (!RSAref_bn2bin(from->d,to->d,RSAref_MAX_LEN)) return(0);
if (!RSAref_bn2bin(from->p,to->prime[0],RSAref_MAX_PLEN)) return(0);
if (!RSAref_bn2bin(from->q,to->prime[1],RSAref_MAX_PLEN)) return(0);
if (!RSAref_bn2bin(from->dmp1,to->pexp[0],RSAref_MAX_PLEN)) return(0);
if (!RSAref_bn2bin(from->dmq1,to->pexp[1],RSAref_MAX_PLEN)) return(0);
if (!RSAref_bn2bin(from->iqmp,to->coef,RSAref_MAX_PLEN)) return(0);
return(1);
}
int RSA_ref_private_decrypt(int len, unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
int i,outlen= -1;
RSArefPrivateKey RSAkey;
if (!RSAref_Private_eay2ref(rsa,&RSAkey))
goto err;
if ((i=RSAPrivateDecrypt(to,&outlen,from,len,&RSAkey)) != 0)
{
RSAREFerr(RSAREF_F_RSA_REF_PRIVATE_DECRYPT,i);
outlen= -1;
}
err:
memset(&RSAkey,0,sizeof(RSAkey));
return(outlen);
}
int RSA_ref_private_encrypt(int len, unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
int i,outlen= -1;
RSArefPrivateKey RSAkey;
if (padding != RSA_PKCS1_PADDING)
{
RSAREFerr(RSAREF_F_RSA_REF_PRIVATE_ENCRYPT, RSA_R_UNKNOWN_PADDING_TYPE);
goto err;
}
if (!RSAref_Private_eay2ref(rsa,&RSAkey))
goto err;
if ((i=RSAPrivateEncrypt(to,&outlen,from,len,&RSAkey)) != 0)
{
RSAREFerr(RSAREF_F_RSA_REF_PRIVATE_ENCRYPT,i);
outlen= -1;
}
err:
memset(&RSAkey,0,sizeof(RSAkey));
return(outlen);
}
int RSA_ref_public_decrypt(int len, unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
int i,outlen= -1;
RSArefPublicKey RSAkey;
if (!RSAref_Public_eay2ref(rsa,&RSAkey))
goto err;
if ((i=RSAPublicDecrypt(to,&outlen,from,len,&RSAkey)) != 0)
{
RSAREFerr(RSAREF_F_RSA_REF_PUBLIC_DECRYPT,i);
outlen= -1;
}
err:
memset(&RSAkey,0,sizeof(RSAkey));
return(outlen);
}
int RSA_ref_public_encrypt(int len, unsigned char *from, unsigned char *to,
RSA *rsa, int padding)
{
int outlen= -1;
int i;
RSArefPublicKey RSAkey;
RSARandomState rnd;
unsigned char buf[16];
if (padding != RSA_PKCS1_PADDING && padding != RSA_SSLV23_PADDING)
{
RSAREFerr(RSAREF_F_RSA_REF_PUBLIC_ENCRYPT, RSA_R_UNKNOWN_PADDING_TYPE);
goto err;
}
R_RandomInit(&rnd);
R_GetRandomBytesNeeded((unsigned int *)&i,&rnd);
while (i > 0)
{
if (RAND_bytes(buf,16) <= 0)
goto err;
R_RandomUpdate(&rnd,buf,(unsigned int)((i>16)?16:i));
i-=16;
}
if (!RSAref_Public_eay2ref(rsa,&RSAkey))
goto err;
if ((i=RSAPublicEncrypt(to,&outlen,from,len,&RSAkey,&rnd)) != 0)
{
RSAREFerr(RSAREF_F_RSA_REF_PUBLIC_ENCRYPT,i);
outlen= -1;
goto err;
}
err:
memset(&RSAkey,0,sizeof(RSAkey));
R_RandomFinal(&rnd);
memset(&rnd,0,sizeof(rnd));
return(outlen);
}
