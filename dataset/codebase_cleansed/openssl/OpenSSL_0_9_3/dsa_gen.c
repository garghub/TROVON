DSA *DSA_generate_parameters(int bits, unsigned char *seed_in, int seed_len,
int *counter_ret, unsigned long *h_ret, void (*callback)(),
char *cb_arg)
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
BN_CTX *ctx=NULL,*ctx2=NULL;
unsigned int h=2;
DSA *ret=NULL;
if (bits < 512) bits=512;
bits=(bits+63)/64*64;
if ((seed_in != NULL) && (seed_len == 20))
memcpy(seed,seed_in,seed_len);
if ((ctx=BN_CTX_new()) == NULL) goto err;
if ((ctx2=BN_CTX_new()) == NULL) goto err;
if ((ret=DSA_new()) == NULL) goto err;
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
r0= &(ctx2->bn[0]);
g= &(ctx2->bn[1]);
W= &(ctx2->bn[2]);
q= &(ctx2->bn[3]);
X= &(ctx2->bn[4]);
c= &(ctx2->bn[5]);
p= &(ctx2->bn[6]);
test= &(ctx2->bn[7]);
BN_lshift(test,BN_value_one(),bits-1);
for (;;)
{
for (;;)
{
if (callback != NULL) callback(0,m++,cb_arg);
if (!seed_len)
RAND_bytes(seed,SHA_DIGEST_LENGTH);
else
seed_len=0;
memcpy(buf,seed,SHA_DIGEST_LENGTH);
memcpy(buf2,seed,SHA_DIGEST_LENGTH);
for (i=SHA_DIGEST_LENGTH-1; i >= 0; i--)
{
buf[i]++;
if (buf[i] != 0) break;
}
HASH(seed,SHA_DIGEST_LENGTH,md);
HASH(buf,SHA_DIGEST_LENGTH,buf2);
for (i=0; i<SHA_DIGEST_LENGTH; i++)
md[i]^=buf2[i];
md[0]|=0x80;
md[SHA_DIGEST_LENGTH-1]|=0x01;
if (!BN_bin2bn(md,SHA_DIGEST_LENGTH,q)) abort();
if (DSA_is_prime(q,callback,cb_arg) > 0) break;
}
if (callback != NULL) callback(2,0,cb_arg);
if (callback != NULL) callback(3,0,cb_arg);
counter=0;
n=(bits-1)/160;
b=(bits-1)-n*160;
for (;;)
{
BN_zero(W);
for (k=0; k<=n; k++)
{
for (i=SHA_DIGEST_LENGTH-1; i >= 0; i--)
{
buf[i]++;
if (buf[i] != 0) break;
}
HASH(buf,SHA_DIGEST_LENGTH,md);
if (!BN_bin2bn(md,SHA_DIGEST_LENGTH,r0)) abort();
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
if (DSA_is_prime(p,callback,cb_arg) > 0)
goto end;
}
counter++;
if (counter >= 4096) break;
if (callback != NULL) callback(0,counter,cb_arg);
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
if (ctx != NULL) BN_CTX_free(ctx2);
if (mont != NULL) BN_MONT_CTX_free(mont);
return(ok?ret:NULL);
}
int DSA_is_prime(BIGNUM *w, void (*callback)(), char *cb_arg)
{
int ok= -1,j,i,n;
BN_CTX *ctx=NULL,*ctx2=NULL;
BIGNUM *w_1,*b,*m,*z,*tmp,*mont_1;
int a;
BN_MONT_CTX *mont=NULL;
if (!BN_is_bit_set(w,0)) return(0);
if ((ctx=BN_CTX_new()) == NULL) goto err;
if ((ctx2=BN_CTX_new()) == NULL) goto err;
if ((mont=BN_MONT_CTX_new()) == NULL) goto err;
m= &(ctx2->bn[2]);
b= &(ctx2->bn[3]);
z= &(ctx2->bn[4]);
w_1= &(ctx2->bn[5]);
tmp= &(ctx2->bn[6]);
mont_1= &(ctx2->bn[7]);
n=50;
if (!BN_sub(w_1,w,BN_value_one())) goto err;
for (a=1; !BN_is_bit_set(w_1,a); a++)
;
if (!BN_rshift(m,w_1,a)) goto err;
BN_MONT_CTX_set(mont,w,ctx);
BN_to_montgomery(mont_1,BN_value_one(),mont,ctx);
BN_to_montgomery(w_1,w_1,mont,ctx);
for (i=1; i < n; i++)
{
BN_rand(b,BN_num_bits(w)-2,0,0);
j=0;
if (!BN_mod_exp_mont(z,b,m,w,ctx,mont)) goto err;
if (!BN_to_montgomery(z,z,mont,ctx)) goto err;
for (;;)
{
if (((j == 0) && (BN_cmp(z,mont_1) == 0)) ||
(BN_cmp(z,w_1) == 0))
break;
if ((j > 0) && (BN_cmp(z,mont_1) == 0))
{
ok=0;
goto err;
}
j++;
if (j >= a)
{
ok=0;
goto err;
}
if (!BN_mod_mul_montgomery(z,z,z,mont,ctx)) goto err;
if (callback != NULL) callback(1,j,cb_arg);
}
}
ok=1;
err:
if (ok == -1) DSAerr(DSA_F_DSA_IS_PRIME,ERR_R_BN_LIB);
BN_CTX_free(ctx);
BN_CTX_free(ctx2);
return(ok);
}
