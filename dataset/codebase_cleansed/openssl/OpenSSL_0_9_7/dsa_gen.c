DSA *DSA_generate_parameters(int bits,
unsigned char *seed_in, int seed_len,
int *counter_ret, unsigned long *h_ret,
void (*callback)(int, int, void *),
void *cb_arg)
{
int ok=0;
unsigned char seed[SHA_DIGEST_LENGTH];
unsigned char md[SHA_DIGEST_LENGTH];
unsigned char buf[SHA_DIGEST_LENGTH],buf2[SHA_DIGEST_LENGTH];
BIGNUM *r0,*W,*X,*c,*test;
BIGNUM *g=NULL,*q=NULL,*p=NULL;
BN_MONT_CTX *mont=NULL;
int k,n=0,i,b,m=0;
int counter=0;
int r=0;
BN_CTX *ctx=NULL,*ctx2=NULL,*ctx3=NULL;
unsigned int h=2;
DSA *ret=NULL;
if (bits < 512) bits=512;
bits=(bits+63)/64*64;
if (seed_len < 20)
seed_in = NULL;
if (seed_len > 20)
seed_len = 20;
if ((seed_in != NULL) && (seed_len == 20))
memcpy(seed,seed_in,seed_len);
if ((ctx=BN_CTX_new()) == NULL) goto err;
if ((ctx2=BN_CTX_new()) == NULL) goto err;
if ((ctx3=BN_CTX_new()) == NULL) goto err;
if ((ret=DSA_new()) == NULL) goto err;
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
BN_CTX_start(ctx2);
r0 = BN_CTX_get(ctx2);
g = BN_CTX_get(ctx2);
W = BN_CTX_get(ctx2);
q = BN_CTX_get(ctx2);
X = BN_CTX_get(ctx2);
c = BN_CTX_get(ctx2);
p = BN_CTX_get(ctx2);
test = BN_CTX_get(ctx2);
BN_lshift(test,BN_value_one(),bits-1);
for (;;)
{
for (;;)
{
int seed_is_random;
if (callback != NULL) callback(0,m++,cb_arg);
if (!seed_len)
{
RAND_pseudo_bytes(seed,SHA_DIGEST_LENGTH);
seed_is_random = 1;
}
else
{
seed_is_random = 0;
seed_len=0;
}
memcpy(buf,seed,SHA_DIGEST_LENGTH);
memcpy(buf2,seed,SHA_DIGEST_LENGTH);
for (i=SHA_DIGEST_LENGTH-1; i >= 0; i--)
{
buf[i]++;
if (buf[i] != 0) break;
}
EVP_Digest(seed,SHA_DIGEST_LENGTH,md,NULL,HASH, NULL);
EVP_Digest(buf,SHA_DIGEST_LENGTH,buf2,NULL,HASH, NULL);
for (i=0; i<SHA_DIGEST_LENGTH; i++)
md[i]^=buf2[i];
md[0]|=0x80;
md[SHA_DIGEST_LENGTH-1]|=0x01;
if (!BN_bin2bn(md,SHA_DIGEST_LENGTH,q)) goto err;
r = BN_is_prime_fasttest(q, DSS_prime_checks, callback, ctx3, cb_arg, seed_is_random);
if (r > 0)
break;
if (r != 0)
goto err;
}
if (callback != NULL) callback(2,0,cb_arg);
if (callback != NULL) callback(3,0,cb_arg);
counter=0;
n=(bits-1)/160;
b=(bits-1)-n*160;
for (;;)
{
if (callback != NULL && counter != 0)
callback(0,counter,cb_arg);
BN_zero(W);
for (k=0; k<=n; k++)
{
for (i=SHA_DIGEST_LENGTH-1; i >= 0; i--)
{
buf[i]++;
if (buf[i] != 0) break;
}
EVP_Digest(buf,SHA_DIGEST_LENGTH,md,NULL,HASH, NULL);
if (!BN_bin2bn(md,SHA_DIGEST_LENGTH,r0))
goto err;
BN_lshift(r0,r0,160*k);
BN_add(W,W,r0);
}
BN_mask_bits(W,bits-1);
BN_copy(X,W);
BN_add(X,X,test);
BN_lshift1(r0,q);
BN_mod(c,X,r0,ctx);
BN_sub(r0,c,BN_value_one());
BN_sub(p,X,r0);
if (BN_cmp(p,test) >= 0)
{
r = BN_is_prime_fasttest(p, DSS_prime_checks, callback, ctx3, cb_arg, 1);
if (r > 0)
goto end;
if (r != 0)
goto err;
}
counter++;
if (counter >= 4096) break;
}
}
end:
if (callback != NULL) callback(2,1,cb_arg);
BN_sub(test,p,BN_value_one());
BN_div(r0,NULL,test,q,ctx);
BN_set_word(test,h);
BN_MONT_CTX_set(mont,p,ctx);
for (;;)
{
BN_mod_exp_mont(g,test,r0,p,ctx,mont);
if (!BN_is_one(g)) break;
BN_add(test,test,BN_value_one());
h++;
}
if (callback != NULL) callback(3,1,cb_arg);
ok=1;
err:
if (!ok)
{
if (ret != NULL) DSA_free(ret);
}
else
{
ret->p=BN_dup(p);
ret->q=BN_dup(q);
ret->g=BN_dup(g);
if ((m > 1) && (seed_in != NULL)) memcpy(seed_in,seed,20);
if (counter_ret != NULL) *counter_ret=counter;
if (h_ret != NULL) *h_ret=h;
}
if (ctx != NULL) BN_CTX_free(ctx);
if (ctx2 != NULL)
{
BN_CTX_end(ctx2);
BN_CTX_free(ctx2);
}
if (ctx3 != NULL) BN_CTX_free(ctx3);
if (mont != NULL) BN_MONT_CTX_free(mont);
return(ok?ret:NULL);
}
