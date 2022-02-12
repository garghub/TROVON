static int null_callback(int ok, X509_STORE_CTX *e)
{
return(ok);
}
int X509_verify_cert(X509_STORE_CTX *ctx)
{
X509 *x,*xtmp,*chain_ss=NULL;
X509_NAME *xn;
X509_OBJECT obj;
int depth,i,ok=0;
int num;
int (*cb)();
STACK_OF(X509) *sktmp=NULL;
if (ctx->cert == NULL)
{
X509err(X509_F_X509_VERIFY_CERT,X509_R_NO_CERT_SET_FOR_US_TO_VERIFY);
return(-1);
}
cb=ctx->ctx->verify_cb;
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
if (X509_NAME_cmp(X509_get_subject_name(x),xn) == 0)
break;
if (ctx->untrusted != NULL)
{
xtmp=X509_find_by_subject(sktmp,xn);
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
if (X509_NAME_cmp(X509_get_subject_name(x),X509_get_issuer_name(x))
== 0)
{
if (sk_X509_num(ctx->chain) == 1)
{
ctx->error=X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT;
ctx->current_cert=x;
ctx->error_depth=i-1;
ok=cb(0,ctx);
if (!ok) goto end;
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
if (X509_NAME_cmp(X509_get_subject_name(x),xn) == 0)
break;
ok=X509_STORE_get_by_subject(ctx,X509_LU_X509,xn,&obj);
if (ok != X509_LU_X509)
{
if (ok == X509_LU_RETRY)
{
X509_OBJECT_free_contents(&obj);
X509err(X509_F_X509_VERIFY_CERT,X509_R_SHOULD_RETRY);
return(ok);
}
else if (ok != X509_LU_FAIL)
{
X509_OBJECT_free_contents(&obj);
return(ok);
}
break;
}
x=obj.data.x509;
if (!sk_X509_push(ctx->chain,obj.data.x509))
{
X509_OBJECT_free_contents(&obj);
X509err(X509_F_X509_VERIFY_CERT,ERR_R_MALLOC_FAILURE);
return(0);
}
num++;
}
xn=X509_get_issuer_name(x);
if (X509_NAME_cmp(X509_get_subject_name(x),xn) != 0)
{
if ((chain_ss == NULL) || (X509_NAME_cmp(X509_get_subject_name(chain_ss),xn) != 0))
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
X509_get_pubkey_parameters(NULL,ctx->chain);
if (ctx->ctx->verify != NULL)
ok=ctx->ctx->verify(ctx);
else
ok=internal_verify(ctx);
if (0)
{
end:
X509_get_pubkey_parameters(NULL,ctx->chain);
}
if (sktmp != NULL) sk_X509_free(sktmp);
if (chain_ss != NULL) X509_free(chain_ss);
return(ok);
}
static int internal_verify(X509_STORE_CTX *ctx)
{
int i,ok=0,n;
X509 *xs,*xi;
EVP_PKEY *pkey=NULL;
int (*cb)();
cb=ctx->ctx->verify_cb;
if (cb == NULL) cb=null_callback;
n=sk_X509_num(ctx->chain);
ctx->error_depth=n-1;
n--;
xi=sk_X509_value(ctx->chain,n);
if (X509_NAME_cmp(X509_get_subject_name(xi),
X509_get_issuer_name(xi)) == 0)
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
EVP_PKEY_free(pkey);
ctx->error=X509_V_ERR_CERT_SIGNATURE_FAILURE;
ctx->current_cert=xs;
ok=(*cb)(0,ctx);
if (!ok) goto end;
}
EVP_PKEY_free(pkey);
pkey=NULL;
i=X509_cmp_current_time(X509_get_notBefore(xs));
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
i=X509_cmp_current_time(X509_get_notAfter(xs));
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
return(ok);
}
int X509_cmp_current_time(ASN1_UTCTIME *ctm)
{
char *str;
ASN1_UTCTIME atm;
time_t offset;
char buff1[24],buff2[24],*p;
int i,j;
p=buff1;
i=ctm->length;
str=(char *)ctm->data;
if ((i < 11) || (i > 17)) return(0);
memcpy(p,str,10);
p+=10;
str+=10;
if ((*str == 'Z') || (*str == '-') || (*str == '+'))
{ *(p++)='0'; *(p++)='0'; }
else { *(p++)= *(str++); *(p++)= *(str++); }
*(p++)='Z';
*(p++)='\0';
if (*str == 'Z')
offset=0;
else
{
if ((*str != '+') && (str[5] != '-'))
return(0);
offset=((str[1]-'0')*10+(str[2]-'0'))*60;
offset+=(str[3]-'0')*10+(str[4]-'0');
if (*str == '-')
offset= -offset;
}
atm.type=V_ASN1_UTCTIME;
atm.length=sizeof(buff2);
atm.data=(unsigned char *)buff2;
X509_gmtime_adj(&atm,-offset);
i=(buff1[0]-'0')*10+(buff1[1]-'0');
if (i < 50) i+=100;
j=(buff2[0]-'0')*10+(buff2[1]-'0');
if (j < 50) j+=100;
if (i < j) return (-1);
if (i > j) return (1);
i=strcmp(buff1,buff2);
if (i == 0)
return(-1);
else
return(i);
}
ASN1_UTCTIME *X509_gmtime_adj(ASN1_UTCTIME *s, long adj)
{
time_t t;
time(&t);
t+=adj;
return(ASN1_UTCTIME_set(s,t));
}
int X509_STORE_add_cert(X509_STORE *ctx, X509 *x)
{
X509_OBJECT *obj,*r;
int ret=1;
if (x == NULL) return(0);
obj=(X509_OBJECT *)Malloc(sizeof(X509_OBJECT));
if (obj == NULL)
{
X509err(X509_F_X509_STORE_ADD_CERT,ERR_R_MALLOC_FAILURE);
return(0);
}
obj->type=X509_LU_X509;
obj->data.x509=x;
CRYPTO_w_lock(CRYPTO_LOCK_X509_STORE);
X509_OBJECT_up_ref_count(obj);
r=(X509_OBJECT *)lh_insert(ctx->certs,(char *)obj);
if (r != NULL)
{
lh_delete(ctx->certs,(char *)obj);
X509_OBJECT_free_contents(obj);
Free(obj);
lh_insert(ctx->certs,(char *)r);
X509err(X509_F_X509_STORE_ADD_CERT,X509_R_CERT_ALREADY_IN_HASH_TABLE);
ret=0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_X509_STORE);
return(ret);
}
int X509_STORE_add_crl(X509_STORE *ctx, X509_CRL *x)
{
X509_OBJECT *obj,*r;
int ret=1;
if (x == NULL) return(0);
obj=(X509_OBJECT *)Malloc(sizeof(X509_OBJECT));
if (obj == NULL)
{
X509err(X509_F_X509_STORE_ADD_CRL,ERR_R_MALLOC_FAILURE);
return(0);
}
obj->type=X509_LU_CRL;
obj->data.crl=x;
CRYPTO_w_lock(CRYPTO_LOCK_X509_STORE);
X509_OBJECT_up_ref_count(obj);
r=(X509_OBJECT *)lh_insert(ctx->certs,(char *)obj);
if (r != NULL)
{
lh_delete(ctx->certs,(char *)obj);
X509_OBJECT_free_contents(obj);
Free(obj);
lh_insert(ctx->certs,(char *)r);
X509err(X509_F_X509_STORE_ADD_CRL,X509_R_CERT_ALREADY_IN_HASH_TABLE);
ret=0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_X509_STORE);
return(ret);
}
int X509_STORE_CTX_get_ex_new_index(long argl, char *argp, int (*new_func)(),
int (*dup_func)(), void (*free_func)())
{
x509_store_ctx_num++;
return(CRYPTO_get_ex_new_index(x509_store_ctx_num-1,
&x509_store_ctx_method,
argl,argp,new_func,dup_func,free_func));
}
int X509_STORE_CTX_set_ex_data(X509_STORE_CTX *ctx, int idx, void *data)
{
return(CRYPTO_set_ex_data(&ctx->ex_data,idx,data));
}
void *X509_STORE_CTX_get_ex_data(X509_STORE_CTX *ctx, int idx)
{
return(CRYPTO_get_ex_data(&ctx->ex_data,idx));
}
int X509_STORE_CTX_get_error(X509_STORE_CTX *ctx)
{
return(ctx->error);
}
void X509_STORE_CTX_set_error(X509_STORE_CTX *ctx, int err)
{
ctx->error=err;
}
int X509_STORE_CTX_get_error_depth(X509_STORE_CTX *ctx)
{
return(ctx->error_depth);
}
X509 *X509_STORE_CTX_get_current_cert(X509_STORE_CTX *ctx)
{
return(ctx->current_cert);
}
void X509_STORE_CTX_set_cert(X509_STORE_CTX *ctx, X509 *x)
{
ctx->cert=x;
}
