static int null_callback(int ok, X509_STORE_CTX *e)
{
return ok;
}
int X509_verify_cert(X509_STORE_CTX *ctx)
{
X509 *x,*xtmp,*chain_ss=NULL;
X509_NAME *xn;
int depth,i,ok=0;
int num;
int (*cb)();
STACK_OF(X509) *sktmp=NULL;
if (ctx->cert == NULL)
{
X509err(X509_F_X509_VERIFY_CERT,X509_R_NO_CERT_SET_FOR_US_TO_VERIFY);
return -1;
}
cb=ctx->verify_cb;
if (cb == NULL) cb=null_callback;
if (ctx->chain == NULL)
{
if ( ((ctx->chain=sk_X509_new_null()) == NULL) ||
(!sk_X509_push(ctx->chain,ctx->cert)))
{
X509err(X509_F_X509_VERIFY_CERT,ERR_R_MALLOC_FAILURE);
goto end;
}
CRYPTO_add(&ctx->cert->references,1,CRYPTO_LOCK_X509);
ctx->last_untrusted=1;
}
if (ctx->untrusted != NULL
&& (sktmp=sk_X509_dup(ctx->untrusted)) == NULL)
{
X509err(X509_F_X509_VERIFY_CERT,ERR_R_MALLOC_FAILURE);
goto end;
}
num=sk_X509_num(ctx->chain);
x=sk_X509_value(ctx->chain,num-1);
depth=ctx->depth;
for (;;)
{
if (depth < num) break;
xn=X509_get_issuer_name(x);
if (ctx->check_issued(ctx, x,x)) break;
if (ctx->untrusted != NULL)
{
xtmp=find_issuer(ctx, sktmp,x);
if (xtmp != NULL)
{
if (!sk_X509_push(ctx->chain,xtmp))
{
X509err(X509_F_X509_VERIFY_CERT,ERR_R_MALLOC_FAILURE);
goto end;
}
CRYPTO_add(&xtmp->references,1,CRYPTO_LOCK_X509);
sk_X509_delete_ptr(sktmp,xtmp);
ctx->last_untrusted++;
x=xtmp;
num++;
continue;
}
}
break;
}
i=sk_X509_num(ctx->chain);
x=sk_X509_value(ctx->chain,i-1);
xn = X509_get_subject_name(x);
if (ctx->check_issued(ctx, x, x))
{
if (sk_X509_num(ctx->chain) == 1)
{
ok = ctx->get_issuer(&xtmp, ctx, x);
if ((ok <= 0) || X509_cmp(x, xtmp))
{
ctx->error=X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT;
ctx->current_cert=x;
ctx->error_depth=i-1;
if (ok == 1) X509_free(xtmp);
ok=cb(0,ctx);
if (!ok) goto end;
}
else
{
X509_free(x);
x = xtmp;
sk_X509_set(ctx->chain, i - 1, x);
ctx->last_untrusted=0;
}
}
else
{
chain_ss=sk_X509_pop(ctx->chain);
ctx->last_untrusted--;
num--;
x=sk_X509_value(ctx->chain,num-1);
}
}
for (;;)
{
if (depth < num) break;
xn=X509_get_issuer_name(x);
if (ctx->check_issued(ctx,x,x)) break;
ok = ctx->get_issuer(&xtmp, ctx, x);
if (ok < 0) return ok;
if (ok == 0) break;
x = xtmp;
if (!sk_X509_push(ctx->chain,x))
{
X509_free(xtmp);
X509err(X509_F_X509_VERIFY_CERT,ERR_R_MALLOC_FAILURE);
return 0;
}
num++;
}
xn=X509_get_issuer_name(x);
if (!ctx->check_issued(ctx,x,x))
{
if ((chain_ss == NULL) || !ctx->check_issued(ctx, x, chain_ss))
{
if (ctx->last_untrusted >= num)
ctx->error=X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY;
else
ctx->error=X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT;
ctx->current_cert=x;
}
else
{
sk_X509_push(ctx->chain,chain_ss);
num++;
ctx->last_untrusted=num;
ctx->current_cert=chain_ss;
ctx->error=X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN;
chain_ss=NULL;
}
ctx->error_depth=num-1;
ok=cb(0,ctx);
if (!ok) goto end;
}
if (ctx->purpose > 0) ok = check_chain_purpose(ctx);
if (!ok) goto end;
if (ctx->trust > 0) ok = check_trust(ctx);
if (!ok) goto end;
X509_get_pubkey_parameters(NULL,ctx->chain);
if (ctx->verify != NULL)
ok=ctx->verify(ctx);
else
ok=internal_verify(ctx);
if (0)
{
end:
X509_get_pubkey_parameters(NULL,ctx->chain);
}
if (sktmp != NULL) sk_X509_free(sktmp);
if (chain_ss != NULL) X509_free(chain_ss);
return ok;
}
static int check_issued(X509_STORE_CTX *ctx, X509 *x, X509 *issuer)
{
int ret;
ret = X509_check_issued(issuer, x);
if (ret == X509_V_OK)
return 1;
if (!(ctx->flags & X509_V_FLAG_CB_ISSUER_CHECK))
return 0;
ctx->error = ret;
ctx->current_cert = x;
ctx->current_issuer = issuer;
if (ctx->verify_cb)
return ctx->verify_cb(0, ctx);
return 0;
}
static int get_issuer_sk(X509 **issuer, X509_STORE_CTX *ctx, X509 *x)
{
*issuer = find_issuer(ctx, ctx->other_ctx, x);
if (*issuer)
{
CRYPTO_add(&(*issuer)->references,1,CRYPTO_LOCK_X509);
return 1;
}
else
return 0;
}
static int check_chain_purpose(X509_STORE_CTX *ctx)
{
#ifdef NO_CHAIN_VERIFY
return 1;
#else
int i, ok=0;
X509 *x;
int (*cb)();
cb=ctx->verify_cb;
if (cb == NULL) cb=null_callback;
for (i = 0; i < ctx->last_untrusted; i++)
{
x = sk_X509_value(ctx->chain, i);
if (!X509_check_purpose(x, ctx->purpose, i))
{
if (i)
ctx->error = X509_V_ERR_INVALID_CA;
else
ctx->error = X509_V_ERR_INVALID_PURPOSE;
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
if ((i > 1) && (x->ex_pathlen != -1)
&& (i > (x->ex_pathlen + 1)))
{
ctx->error = X509_V_ERR_PATH_LENGTH_EXCEEDED;
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
}
ok = 1;
end:
return ok;
#endif
}
static int check_trust(X509_STORE_CTX *ctx)
{
#ifdef NO_CHAIN_VERIFY
return 1;
#else
int i, ok;
X509 *x;
int (*cb)();
cb=ctx->verify_cb;
if (cb == NULL) cb=null_callback;
i = sk_X509_num(ctx->chain) - 1;
x = sk_X509_value(ctx->chain, i);
ok = X509_check_trust(x, ctx->trust, 0);
if (ok == X509_TRUST_TRUSTED)
return 1;
ctx->error_depth = sk_X509_num(ctx->chain) - 1;
ctx->current_cert = x;
if (ok == X509_TRUST_REJECTED)
ctx->error = X509_V_ERR_CERT_REJECTED;
else
ctx->error = X509_V_ERR_CERT_UNTRUSTED;
ok = cb(0, ctx);
return ok;
#endif
}
static int internal_verify(X509_STORE_CTX *ctx)
{
int i,ok=0,n;
X509 *xs,*xi;
EVP_PKEY *pkey=NULL;
time_t *ptime;
int (*cb)();
cb=ctx->verify_cb;
if (cb == NULL) cb=null_callback;
n=sk_X509_num(ctx->chain);
ctx->error_depth=n-1;
n--;
xi=sk_X509_value(ctx->chain,n);
if (ctx->flags & X509_V_FLAG_USE_CHECK_TIME)
ptime = &ctx->check_time;
else
ptime = NULL;
if (ctx->check_issued(ctx, xi, xi))
xs=xi;
else
{
if (n <= 0)
{
ctx->error=X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE;
ctx->current_cert=xi;
ok=cb(0,ctx);
goto end;
}
else
{
n--;
ctx->error_depth=n;
xs=sk_X509_value(ctx->chain,n);
}
}
while (n >= 0)
{
ctx->error_depth=n;
if (!xs->valid)
{
if ((pkey=X509_get_pubkey(xi)) == NULL)
{
ctx->error=X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY;
ctx->current_cert=xi;
ok=(*cb)(0,ctx);
if (!ok) goto end;
}
if (X509_verify(xs,pkey) <= 0)
{
ctx->error=X509_V_ERR_CERT_SIGNATURE_FAILURE;
ctx->current_cert=xs;
ok=(*cb)(0,ctx);
if (!ok)
{
EVP_PKEY_free(pkey);
goto end;
}
}
EVP_PKEY_free(pkey);
pkey=NULL;
i=X509_cmp_time(X509_get_notBefore(xs), ptime);
if (i == 0)
{
ctx->error=X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD;
ctx->current_cert=xs;
ok=(*cb)(0,ctx);
if (!ok) goto end;
}
if (i > 0)
{
ctx->error=X509_V_ERR_CERT_NOT_YET_VALID;
ctx->current_cert=xs;
ok=(*cb)(0,ctx);
if (!ok) goto end;
}
xs->valid=1;
}
i=X509_cmp_time(X509_get_notAfter(xs), ptime);
if (i == 0)
{
ctx->error=X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD;
ctx->current_cert=xs;
ok=(*cb)(0,ctx);
if (!ok) goto end;
}
if (i < 0)
{
ctx->error=X509_V_ERR_CERT_HAS_EXPIRED;
ctx->current_cert=xs;
ok=(*cb)(0,ctx);
if (!ok) goto end;
}
ctx->current_cert=xs;
ok=(*cb)(1,ctx);
if (!ok) goto end;
n--;
if (n >= 0)
{
xi=xs;
xs=sk_X509_value(ctx->chain,n);
}
}
ok=1;
end:
return ok;
}
int X509_cmp_current_time(ASN1_TIME *ctm)
{
return X509_cmp_time(ctm, NULL);
}
int X509_cmp_time(ASN1_TIME *ctm, time_t *cmp_time)
{
char *str;
ASN1_TIME atm;
time_t offset;
char buff1[24],buff2[24],*p;
int i,j;
p=buff1;
i=ctm->length;
str=(char *)ctm->data;
if (ctm->type == V_ASN1_UTCTIME)
{
if ((i < 11) || (i > 17)) return 0;
memcpy(p,str,10);
p+=10;
str+=10;
}
else
{
if (i < 13) return 0;
memcpy(p,str,12);
p+=12;
str+=12;
}
if ((*str == 'Z') || (*str == '-') || (*str == '+'))
{ *(p++)='0'; *(p++)='0'; }
else
{
*(p++)= *(str++);
*(p++)= *(str++);
if (*str == '.')
{
str++;
while ((*str >= '0') && (*str <= '9')) str++;
}
}
*(p++)='Z';
*(p++)='\0';
if (*str == 'Z')
offset=0;
else
{
if ((*str != '+') && (str[5] != '-'))
return 0;
offset=((str[1]-'0')*10+(str[2]-'0'))*60;
offset+=(str[3]-'0')*10+(str[4]-'0');
if (*str == '-')
offset= -offset;
}
atm.type=ctm->type;
atm.length=sizeof(buff2);
atm.data=(unsigned char *)buff2;
X509_time_adj(&atm,-offset*60, cmp_time);
if (ctm->type == V_ASN1_UTCTIME)
{
i=(buff1[0]-'0')*10+(buff1[1]-'0');
if (i < 50) i+=100;
j=(buff2[0]-'0')*10+(buff2[1]-'0');
if (j < 50) j+=100;
if (i < j) return -1;
if (i > j) return 1;
}
i=strcmp(buff1,buff2);
if (i == 0)
return -1;
else
return i;
}
ASN1_TIME *X509_gmtime_adj(ASN1_TIME *s, long adj)
{
return X509_time_adj(s, adj, NULL);
}
ASN1_TIME *X509_time_adj(ASN1_TIME *s, long adj, time_t *in_tm)
{
time_t t;
if (in_tm) t = *in_tm;
else time(&t);
t+=adj;
if (!s) return ASN1_TIME_set(s, t);
if (s->type == V_ASN1_UTCTIME) return ASN1_UTCTIME_set(s,t);
return ASN1_GENERALIZEDTIME_set(s, t);
}
int X509_STORE_CTX_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
x509_store_ctx_num++;
return CRYPTO_get_ex_new_index(x509_store_ctx_num-1,
&x509_store_ctx_method,
argl,argp,new_func,dup_func,free_func);
}
int X509_STORE_CTX_set_ex_data(X509_STORE_CTX *ctx, int idx, void *data)
{
return CRYPTO_set_ex_data(&ctx->ex_data,idx,data);
}
void *X509_STORE_CTX_get_ex_data(X509_STORE_CTX *ctx, int idx)
{
return CRYPTO_get_ex_data(&ctx->ex_data,idx);
}
int X509_STORE_CTX_get_error(X509_STORE_CTX *ctx)
{
return ctx->error;
}
void X509_STORE_CTX_set_error(X509_STORE_CTX *ctx, int err)
{
ctx->error=err;
}
int X509_STORE_CTX_get_error_depth(X509_STORE_CTX *ctx)
{
return ctx->error_depth;
}
X509 *X509_STORE_CTX_get_current_cert(X509_STORE_CTX *ctx)
{
return ctx->current_cert;
}
int X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx, int purpose)
{
return X509_STORE_CTX_purpose_inherit(ctx, 0, purpose, 0);
}
int X509_STORE_CTX_set_trust(X509_STORE_CTX *ctx, int trust)
{
return X509_STORE_CTX_purpose_inherit(ctx, 0, 0, trust);
}
int X509_STORE_CTX_purpose_inherit(X509_STORE_CTX *ctx, int def_purpose,
int purpose, int trust)
{
int idx;
if (!purpose) purpose = def_purpose;
if (purpose)
{
X509_PURPOSE *ptmp;
idx = X509_PURPOSE_get_by_id(purpose);
if (idx == -1)
{
X509err(X509_F_X509_STORE_CTX_PURPOSE_INHERIT,
X509_R_UNKNOWN_PURPOSE_ID);
return 0;
}
ptmp = X509_PURPOSE_get0(idx);
if (ptmp->trust == X509_TRUST_DEFAULT)
{
idx = X509_PURPOSE_get_by_id(def_purpose);
if (idx == -1)
{
X509err(X509_F_X509_STORE_CTX_PURPOSE_INHERIT,
X509_R_UNKNOWN_PURPOSE_ID);
return 0;
}
ptmp = X509_PURPOSE_get0(idx);
}
if (!trust) trust = ptmp->trust;
}
if (trust)
{
idx = X509_TRUST_get_by_id(trust);
if (idx == -1)
{
X509err(X509_F_X509_STORE_CTX_PURPOSE_INHERIT,
X509_R_UNKNOWN_TRUST_ID);
return 0;
}
}
if (purpose) ctx->purpose = purpose;
if (trust) ctx->trust = trust;
return 1;
}
X509_STORE_CTX *X509_STORE_CTX_new(void)
{
X509_STORE_CTX *ctx;
ctx = (X509_STORE_CTX *)OPENSSL_malloc(sizeof(X509_STORE_CTX));
if (ctx) memset(ctx, 0, sizeof(X509_STORE_CTX));
return ctx;
}
void X509_STORE_CTX_free(X509_STORE_CTX *ctx)
{
X509_STORE_CTX_cleanup(ctx);
OPENSSL_free(ctx);
}
void X509_STORE_CTX_cleanup(X509_STORE_CTX *ctx)
{
if (ctx->cleanup) ctx->cleanup(ctx);
if (ctx->chain != NULL)
{
sk_X509_pop_free(ctx->chain,X509_free);
ctx->chain=NULL;
}
CRYPTO_free_ex_data(x509_store_ctx_method,ctx,&(ctx->ex_data));
memset(&ctx->ex_data,0,sizeof(CRYPTO_EX_DATA));
}
void X509_STORE_CTX_set_flags(X509_STORE_CTX *ctx, long flags)
{
ctx->flags |= flags;
}
void X509_STORE_CTX_set_time(X509_STORE_CTX *ctx, long flags, time_t t)
{
ctx->check_time = t;
ctx->flags |= X509_V_FLAG_USE_CHECK_TIME;
}
