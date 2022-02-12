static int null_callback(int ok, X509_STORE_CTX *e)
{
return ok;
}
int X509_verify_cert(X509_STORE_CTX *ctx)
{
X509 *x,*xtmp,*chain_ss=NULL;
int bad_chain = 0;
X509_VERIFY_PARAM *param = ctx->param;
int depth,i,ok=0;
int num;
int (*cb)(int xok,X509_STORE_CTX *xctx);
STACK_OF(X509) *sktmp=NULL;
if (ctx->cert == NULL)
{
X509err(X509_F_X509_VERIFY_CERT,X509_R_NO_CERT_SET_FOR_US_TO_VERIFY);
return -1;
}
cb=ctx->verify_cb;
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
depth=param->depth;
for (;;)
{
if (depth < num) break;
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
(void)sk_X509_delete_ptr(sktmp,xtmp);
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
bad_chain = 1;
ok=cb(0,ctx);
if (!ok) goto end;
}
else
{
X509_free(x);
x = xtmp;
(void)sk_X509_set(ctx->chain, i - 1, x);
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
bad_chain = 1;
ok=cb(0,ctx);
if (!ok) goto end;
}
ok = check_chain_extensions(ctx);
if (!ok) goto end;
ok = check_name_constraints(ctx);
if (!ok) goto end;
if (param->trust > 0) ok = check_trust(ctx);
if (!ok) goto end;
X509_get_pubkey_parameters(NULL,ctx->chain);
ok = ctx->check_revocation(ctx);
if(!ok) goto end;
if (ctx->verify != NULL)
ok=ctx->verify(ctx);
else
ok=internal_verify(ctx);
if(!ok) goto end;
#ifndef OPENSSL_NO_RFC3779
ok = v3_asid_validate_path(ctx);
if (!ok) goto end;
ok = v3_addr_validate_path(ctx);
if (!ok) goto end;
#endif
if (!bad_chain && (ctx->param->flags & X509_V_FLAG_POLICY_CHECK))
ok = ctx->check_policy(ctx);
if(!ok) goto end;
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
if (!(ctx->param->flags & X509_V_FLAG_CB_ISSUER_CHECK))
return 0;
ctx->error = ret;
ctx->current_cert = x;
ctx->current_issuer = issuer;
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
static int check_chain_extensions(X509_STORE_CTX *ctx)
{
#ifdef OPENSSL_NO_CHAIN_VERIFY
return 1;
#else
int i, ok=0, must_be_ca, plen = 0;
X509 *x;
int (*cb)(int xok,X509_STORE_CTX *xctx);
int proxy_path_length = 0;
int purpose;
int allow_proxy_certs;
cb=ctx->verify_cb;
must_be_ca = -1;
if (ctx->parent)
{
allow_proxy_certs = 0;
purpose = X509_PURPOSE_CRL_SIGN;
}
else
{
allow_proxy_certs =
!!(ctx->param->flags & X509_V_FLAG_ALLOW_PROXY_CERTS);
if (getenv("OPENSSL_ALLOW_PROXY_CERTS"))
allow_proxy_certs = 1;
purpose = ctx->param->purpose;
}
for (i = 0; i < ctx->last_untrusted; i++)
{
int ret;
x = sk_X509_value(ctx->chain, i);
if (!(ctx->param->flags & X509_V_FLAG_IGNORE_CRITICAL)
&& (x->ex_flags & EXFLAG_CRITICAL))
{
ctx->error = X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION;
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
if (!allow_proxy_certs && (x->ex_flags & EXFLAG_PROXY))
{
ctx->error = X509_V_ERR_PROXY_CERTIFICATES_NOT_ALLOWED;
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
ret = X509_check_ca(x);
switch(must_be_ca)
{
case -1:
if ((ctx->param->flags & X509_V_FLAG_X509_STRICT)
&& (ret != 1) && (ret != 0))
{
ret = 0;
ctx->error = X509_V_ERR_INVALID_CA;
}
else
ret = 1;
break;
case 0:
if (ret != 0)
{
ret = 0;
ctx->error = X509_V_ERR_INVALID_NON_CA;
}
else
ret = 1;
break;
default:
if ((ret == 0)
|| ((ctx->param->flags & X509_V_FLAG_X509_STRICT)
&& (ret != 1)))
{
ret = 0;
ctx->error = X509_V_ERR_INVALID_CA;
}
else
ret = 1;
break;
}
if (ret == 0)
{
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
if (ctx->param->purpose > 0)
{
ret = X509_check_purpose(x, purpose, must_be_ca > 0);
if ((ret == 0)
|| ((ctx->param->flags & X509_V_FLAG_X509_STRICT)
&& (ret != 1)))
{
ctx->error = X509_V_ERR_INVALID_PURPOSE;
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
}
if ((i > 1) && !(x->ex_flags & EXFLAG_SI)
&& (x->ex_pathlen != -1)
&& (plen > (x->ex_pathlen + proxy_path_length + 1)))
{
ctx->error = X509_V_ERR_PATH_LENGTH_EXCEEDED;
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
if (!(x->ex_flags & EXFLAG_SI))
plen++;
if (x->ex_flags & EXFLAG_PROXY)
{
if (x->ex_pcpathlen != -1 && i > x->ex_pcpathlen)
{
ctx->error =
X509_V_ERR_PROXY_PATH_LENGTH_EXCEEDED;
ctx->error_depth = i;
ctx->current_cert = x;
ok=cb(0,ctx);
if (!ok) goto end;
}
proxy_path_length++;
must_be_ca = 0;
}
else
must_be_ca = 1;
}
ok = 1;
end:
return ok;
#endif
}
static int check_name_constraints(X509_STORE_CTX *ctx)
{
X509 *x;
int i, j, rv;
for (i = sk_X509_num(ctx->chain) - 1; i >= 0; i--)
{
x = sk_X509_value(ctx->chain, i);
if (i && (x->ex_flags & EXFLAG_SI))
continue;
for (j = sk_X509_num(ctx->chain) - 1; j > i; j--)
{
NAME_CONSTRAINTS *nc = sk_X509_value(ctx->chain, j)->nc;
if (nc)
{
rv = NAME_CONSTRAINTS_check(x, nc);
if (rv != X509_V_OK)
{
ctx->error = rv;
ctx->error_depth = i;
ctx->current_cert = x;
if (!ctx->verify_cb(0,ctx))
return 0;
}
}
}
}
return 1;
}
static int check_trust(X509_STORE_CTX *ctx)
{
#ifdef OPENSSL_NO_CHAIN_VERIFY
return 1;
#else
int i, ok;
X509 *x;
int (*cb)(int xok,X509_STORE_CTX *xctx);
cb=ctx->verify_cb;
i = sk_X509_num(ctx->chain) - 1;
x = sk_X509_value(ctx->chain, i);
ok = X509_check_trust(x, ctx->param->trust, 0);
if (ok == X509_TRUST_TRUSTED)
return 1;
ctx->error_depth = i;
ctx->current_cert = x;
if (ok == X509_TRUST_REJECTED)
ctx->error = X509_V_ERR_CERT_REJECTED;
else
ctx->error = X509_V_ERR_CERT_UNTRUSTED;
ok = cb(0, ctx);
return ok;
#endif
}
static int check_revocation(X509_STORE_CTX *ctx)
{
int i, last, ok;
if (!(ctx->param->flags & X509_V_FLAG_CRL_CHECK))
return 1;
if (ctx->param->flags & X509_V_FLAG_CRL_CHECK_ALL)
last = sk_X509_num(ctx->chain) - 1;
else
{
if (ctx->parent)
return 1;
last = 0;
}
for(i = 0; i <= last; i++)
{
ctx->error_depth = i;
ok = check_cert(ctx);
if (!ok) return ok;
}
return 1;
}
static int check_cert(X509_STORE_CTX *ctx)
{
X509_CRL *crl = NULL, *dcrl = NULL;
X509 *x;
int ok, cnum;
cnum = ctx->error_depth;
x = sk_X509_value(ctx->chain, cnum);
ctx->current_cert = x;
ctx->current_issuer = NULL;
ctx->current_crl_score = 0;
ctx->current_reasons = 0;
while (ctx->current_reasons != CRLDP_ALL_REASONS)
{
if (ctx->get_crl)
ok = ctx->get_crl(ctx, &crl, x);
else
ok = get_crl_delta(ctx, &crl, &dcrl, x);
if(!ok)
{
ctx->error = X509_V_ERR_UNABLE_TO_GET_CRL;
ok = ctx->verify_cb(0, ctx);
goto err;
}
ctx->current_crl = crl;
ok = ctx->check_crl(ctx, crl);
if (!ok)
goto err;
if (dcrl)
{
ok = ctx->check_crl(ctx, dcrl);
if (!ok)
goto err;
ok = ctx->cert_crl(ctx, dcrl, x);
if (!ok)
goto err;
}
else
ok = 1;
if (ok != 2)
{
ok = ctx->cert_crl(ctx, crl, x);
if (!ok)
goto err;
}
X509_CRL_free(crl);
X509_CRL_free(dcrl);
crl = NULL;
dcrl = NULL;
}
err:
X509_CRL_free(crl);
X509_CRL_free(dcrl);
ctx->current_crl = NULL;
return ok;
}
static int check_crl_time(X509_STORE_CTX *ctx, X509_CRL *crl, int notify)
{
time_t *ptime;
int i;
if (notify)
ctx->current_crl = crl;
if (ctx->param->flags & X509_V_FLAG_USE_CHECK_TIME)
ptime = &ctx->param->check_time;
else
ptime = NULL;
i=X509_cmp_time(X509_CRL_get_lastUpdate(crl), ptime);
if (i == 0)
{
if (!notify)
return 0;
ctx->error=X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD;
if (!ctx->verify_cb(0, ctx))
return 0;
}
if (i > 0)
{
if (!notify)
return 0;
ctx->error=X509_V_ERR_CRL_NOT_YET_VALID;
if (!ctx->verify_cb(0, ctx))
return 0;
}
if(X509_CRL_get_nextUpdate(crl))
{
i=X509_cmp_time(X509_CRL_get_nextUpdate(crl), ptime);
if (i == 0)
{
if (!notify)
return 0;
ctx->error=X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD;
if (!ctx->verify_cb(0, ctx))
return 0;
}
if ((i < 0) && !(ctx->current_crl_score & CRL_SCORE_TIME_DELTA))
{
if (!notify)
return 0;
ctx->error=X509_V_ERR_CRL_HAS_EXPIRED;
if (!ctx->verify_cb(0, ctx))
return 0;
}
}
if (notify)
ctx->current_crl = NULL;
return 1;
}
static int crl_extension_match(X509_CRL *a, X509_CRL *b, int nid)
{
ASN1_OCTET_STRING *exta, *extb;
int i;
i = X509_CRL_get_ext_by_NID(a, nid, 0);
if (i >= 0)
{
if (X509_CRL_get_ext_by_NID(a, nid, i) != -1)
return 0;
exta = X509_EXTENSION_get_data(X509_CRL_get_ext(a, i));
}
else
exta = NULL;
i = X509_CRL_get_ext_by_NID(b, nid, 0);
if (i >= 0)
{
if (X509_CRL_get_ext_by_NID(b, nid, i) != -1)
return 0;
extb = X509_EXTENSION_get_data(X509_CRL_get_ext(b, i));
}
else
extb = NULL;
if (!exta && !extb)
return 1;
if (!exta || !extb)
return 0;
if (ASN1_OCTET_STRING_cmp(exta, extb))
return 0;
return 1;
}
static int check_delta_base(X509_CRL *delta, X509_CRL *base)
{
if (!delta->base_crl_number)
return 0;
if (!base->crl_number)
return 0;
if (X509_NAME_cmp(X509_CRL_get_issuer(base),
X509_CRL_get_issuer(delta)))
return 0;
if (!crl_extension_match(delta, base, NID_authority_key_identifier))
return 0;
if (!crl_extension_match(delta, base, NID_issuing_distribution_point))
return 0;
if (ASN1_INTEGER_cmp(delta->base_crl_number, base->crl_number) > 0)
return 0;
if (ASN1_INTEGER_cmp(delta->crl_number, base->crl_number) > 0)
return 1;
return 0;
}
static int get_crl_score(X509_STORE_CTX *ctx, X509 **pissuer,
unsigned int *preasons,
X509_CRL *crl, X509 *x)
{
int crl_score = 0;
unsigned int tmp_reasons = *preasons, crl_reasons;
if (crl->idp_flags & IDP_INVALID)
return 0;
if (!(ctx->param->flags & X509_V_FLAG_EXTENDED_CRL_SUPPORT))
{
if (crl->idp_flags & (IDP_INDIRECT | IDP_REASONS))
return 0;
}
else if (crl->idp_flags & IDP_REASONS)
{
if (!(crl->idp_reasons & ~tmp_reasons))
return 0;
}
else if (crl->base_crl_number)
return 0;
if (X509_NAME_cmp(X509_get_issuer_name(x), X509_CRL_get_issuer(crl)))
{
if (!(crl->idp_flags & IDP_INDIRECT))
return 0;
}
else
crl_score |= CRL_SCORE_ISSUER_NAME;
if (!(crl->flags & EXFLAG_CRITICAL))
crl_score |= CRL_SCORE_NOCRITICAL;
if (check_crl_time(ctx, crl, 0))
crl_score |= CRL_SCORE_TIME;
crl_akid_check(ctx, crl, pissuer, &crl_score);
if (!(crl_score & CRL_SCORE_AKID))
return 0;
if (crl_crldp_check(x, crl, crl_score, &crl_reasons))
{
if (!(crl_reasons & ~tmp_reasons))
return 0;
tmp_reasons |= crl_reasons;
crl_score |= CRL_SCORE_SCOPE;
}
*preasons = tmp_reasons;
return crl_score;
}
static void crl_akid_check(X509_STORE_CTX *ctx, X509_CRL *crl,
X509 **pissuer, int *pcrl_score)
{
X509 *crl_issuer = NULL;
X509_NAME *cnm = X509_CRL_get_issuer(crl);
int cidx = ctx->error_depth;
int i;
if (cidx != sk_X509_num(ctx->chain) - 1)
cidx++;
crl_issuer = sk_X509_value(ctx->chain, cidx);
if (X509_check_akid(crl_issuer, crl->akid) == X509_V_OK)
{
if (*pcrl_score & CRL_SCORE_ISSUER_NAME)
{
*pcrl_score |= CRL_SCORE_AKID|CRL_SCORE_ISSUER_CERT;
*pissuer = crl_issuer;
return;
}
}
for (cidx++; cidx < sk_X509_num(ctx->chain); cidx++)
{
crl_issuer = sk_X509_value(ctx->chain, cidx);
if (X509_NAME_cmp(X509_get_subject_name(crl_issuer), cnm))
continue;
if (X509_check_akid(crl_issuer, crl->akid) == X509_V_OK)
{
*pcrl_score |= CRL_SCORE_AKID|CRL_SCORE_SAME_PATH;
*pissuer = crl_issuer;
return;
}
}
if (!(ctx->param->flags & X509_V_FLAG_EXTENDED_CRL_SUPPORT))
return;
for (i = 0; i < sk_X509_num(ctx->untrusted); i++)
{
crl_issuer = sk_X509_value(ctx->untrusted, i);
if (X509_NAME_cmp(X509_get_subject_name(crl_issuer), cnm))
continue;
if (X509_check_akid(crl_issuer, crl->akid) == X509_V_OK)
{
*pissuer = crl_issuer;
*pcrl_score |= CRL_SCORE_AKID;
return;
}
}
}
static int check_crl_path(X509_STORE_CTX *ctx, X509 *x)
{
X509_STORE_CTX crl_ctx;
int ret;
if (ctx->parent)
return 0;
if (!X509_STORE_CTX_init(&crl_ctx, ctx->ctx, x, ctx->untrusted))
return -1;
crl_ctx.crls = ctx->crls;
X509_STORE_CTX_set0_param(&crl_ctx, ctx->param);
crl_ctx.parent = ctx;
crl_ctx.verify_cb = ctx->verify_cb;
ret = X509_verify_cert(&crl_ctx);
if (ret <= 0)
goto err;
ret = check_crl_chain(ctx, ctx->chain, crl_ctx.chain);
err:
X509_STORE_CTX_cleanup(&crl_ctx);
return ret;
}
static int idp_check_dp(DIST_POINT_NAME *a, DIST_POINT_NAME *b)
{
X509_NAME *nm = NULL;
GENERAL_NAMES *gens = NULL;
GENERAL_NAME *gena, *genb;
int i, j;
if (!a || !b)
return 1;
if (a->type == 1)
{
if (!a->dpname)
return 0;
if (b->type == 1)
{
if (!b->dpname)
return 0;
if (!X509_NAME_cmp(a->dpname, b->dpname))
return 1;
else
return 0;
}
nm = a->dpname;
gens = b->name.fullname;
}
else if (b->type == 1)
{
if (!b->dpname)
return 0;
gens = a->name.fullname;
nm = b->dpname;
}
if (nm)
{
for (i = 0; i < sk_GENERAL_NAME_num(gens); i++)
{
gena = sk_GENERAL_NAME_value(gens, i);
if (gena->type != GEN_DIRNAME)
continue;
if (!X509_NAME_cmp(nm, gena->d.directoryName))
return 1;
}
return 0;
}
for (i = 0; i < sk_GENERAL_NAME_num(a->name.fullname); i++)
{
gena = sk_GENERAL_NAME_value(a->name.fullname, i);
for (j = 0; j < sk_GENERAL_NAME_num(b->name.fullname); j++)
{
genb = sk_GENERAL_NAME_value(b->name.fullname, j);
if (!GENERAL_NAME_cmp(gena, genb))
return 1;
}
}
return 0;
}
static int crldp_check_crlissuer(DIST_POINT *dp, X509_CRL *crl, int crl_score)
{
int i;
X509_NAME *nm = X509_CRL_get_issuer(crl);
if (!dp->CRLissuer)
return !!(crl_score & CRL_SCORE_ISSUER_NAME);
for (i = 0; i < sk_GENERAL_NAME_num(dp->CRLissuer); i++)
{
GENERAL_NAME *gen = sk_GENERAL_NAME_value(dp->CRLissuer, i);
if (gen->type != GEN_DIRNAME)
continue;
if (!X509_NAME_cmp(gen->d.directoryName, nm))
return 1;
}
return 0;
}
static int crl_crldp_check(X509 *x, X509_CRL *crl, int crl_score,
unsigned int *preasons)
{
int i;
if (crl->idp_flags & IDP_ONLYATTR)
return 0;
if (x->ex_flags & EXFLAG_CA)
{
if (crl->idp_flags & IDP_ONLYUSER)
return 0;
}
else
{
if (crl->idp_flags & IDP_ONLYCA)
return 0;
}
*preasons = crl->idp_reasons;
for (i = 0; i < sk_DIST_POINT_num(x->crldp); i++)
{
DIST_POINT *dp = sk_DIST_POINT_value(x->crldp, i);
if (crldp_check_crlissuer(dp, crl, crl_score))
{
if (!crl->idp ||
idp_check_dp(dp->distpoint, crl->idp->distpoint))
{
*preasons &= dp->dp_reasons;
return 1;
}
}
}
if ((!crl->idp || !crl->idp->distpoint) && (crl_score & CRL_SCORE_ISSUER_NAME))
return 1;
return 0;
}
static int get_crl_delta(X509_STORE_CTX *ctx,
X509_CRL **pcrl, X509_CRL **pdcrl, X509 *x)
{
int ok;
X509 *issuer = NULL;
int crl_score = 0;
unsigned int reasons;
X509_CRL *crl = NULL, *dcrl = NULL;
STACK_OF(X509_CRL) *skcrl;
X509_NAME *nm = X509_get_issuer_name(x);
reasons = ctx->current_reasons;
ok = get_crl_sk(ctx, &crl, &dcrl,
&issuer, &crl_score, &reasons, ctx->crls);
if (ok)
goto done;
skcrl = ctx->lookup_crls(ctx, nm);
if (!skcrl && crl)
goto done;
get_crl_sk(ctx, &crl, &dcrl, &issuer, &crl_score, &reasons, skcrl);
sk_X509_CRL_pop_free(skcrl, X509_CRL_free);
done:
if (crl)
{
ctx->current_issuer = issuer;
ctx->current_crl_score = crl_score;
ctx->current_reasons = reasons;
*pcrl = crl;
*pdcrl = dcrl;
return 1;
}
return 0;
}
static int check_crl(X509_STORE_CTX *ctx, X509_CRL *crl)
{
X509 *issuer = NULL;
EVP_PKEY *ikey = NULL;
int ok = 0, chnum, cnum;
cnum = ctx->error_depth;
chnum = sk_X509_num(ctx->chain) - 1;
if (ctx->current_issuer)
issuer = ctx->current_issuer;
else if (cnum < chnum)
issuer = sk_X509_value(ctx->chain, cnum + 1);
else
{
issuer = sk_X509_value(ctx->chain, chnum);
if(!ctx->check_issued(ctx, issuer, issuer))
{
ctx->error = X509_V_ERR_UNABLE_TO_GET_CRL_ISSUER;
ok = ctx->verify_cb(0, ctx);
if(!ok) goto err;
}
}
if(issuer)
{
if (!crl->base_crl_number)
{
if ((issuer->ex_flags & EXFLAG_KUSAGE) &&
!(issuer->ex_kusage & KU_CRL_SIGN))
{
ctx->error = X509_V_ERR_KEYUSAGE_NO_CRL_SIGN;
ok = ctx->verify_cb(0, ctx);
if(!ok) goto err;
}
if (!(ctx->current_crl_score & CRL_SCORE_SCOPE))
{
ctx->error = X509_V_ERR_DIFFERENT_CRL_SCOPE;
ok = ctx->verify_cb(0, ctx);
if(!ok) goto err;
}
if (!(ctx->current_crl_score & CRL_SCORE_SAME_PATH))
{
if (check_crl_path(ctx, ctx->current_issuer) <= 0)
{
ctx->error = X509_V_ERR_CRL_PATH_VALIDATION_ERROR;
ok = ctx->verify_cb(0, ctx);
if(!ok) goto err;
}
}
if (crl->idp_flags & IDP_INVALID)
{
ctx->error = X509_V_ERR_INVALID_EXTENSION;
ok = ctx->verify_cb(0, ctx);
if(!ok) goto err;
}
}
if (!(ctx->current_crl_score & CRL_SCORE_TIME))
{
ok = check_crl_time(ctx, crl, 1);
if (!ok)
goto err;
}
ikey = X509_get_pubkey(issuer);
if(!ikey)
{
ctx->error=X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY;
ok = ctx->verify_cb(0, ctx);
if (!ok) goto err;
}
else
{
if(X509_CRL_verify(crl, ikey) <= 0)
{
ctx->error=X509_V_ERR_CRL_SIGNATURE_FAILURE;
ok = ctx->verify_cb(0, ctx);
if (!ok) goto err;
}
}
}
ok = 1;
err:
EVP_PKEY_free(ikey);
return ok;
}
static int cert_crl(X509_STORE_CTX *ctx, X509_CRL *crl, X509 *x)
{
int ok;
X509_REVOKED *rev;
if (crl->flags & EXFLAG_CRITICAL)
{
if (ctx->param->flags & X509_V_FLAG_IGNORE_CRITICAL)
return 1;
ctx->error = X509_V_ERR_UNHANDLED_CRITICAL_CRL_EXTENSION;
ok = ctx->verify_cb(0, ctx);
if(!ok)
return 0;
}
if (X509_CRL_get0_by_cert(crl, &rev, x))
{
if (rev->reason == CRL_REASON_REMOVE_FROM_CRL)
return 2;
ctx->error = X509_V_ERR_CERT_REVOKED;
ok = ctx->verify_cb(0, ctx);
if (!ok)
return 0;
}
return 1;
}
static int check_policy(X509_STORE_CTX *ctx)
{
int ret;
if (ctx->parent)
return 1;
ret = X509_policy_check(&ctx->tree, &ctx->explicit_policy, ctx->chain,
ctx->param->policies, ctx->param->flags);
if (ret == 0)
{
X509err(X509_F_CHECK_POLICY,ERR_R_MALLOC_FAILURE);
return 0;
}
if (ret == -1)
{
X509 *x;
int i;
for (i = 1; i < sk_X509_num(ctx->chain); i++)
{
x = sk_X509_value(ctx->chain, i);
if (!(x->ex_flags & EXFLAG_INVALID_POLICY))
continue;
ctx->current_cert = x;
ctx->error = X509_V_ERR_INVALID_POLICY_EXTENSION;
if(!ctx->verify_cb(0, ctx))
return 0;
}
return 1;
}
if (ret == -2)
{
ctx->current_cert = NULL;
ctx->error = X509_V_ERR_NO_EXPLICIT_POLICY;
return ctx->verify_cb(0, ctx);
}
if (ctx->param->flags & X509_V_FLAG_NOTIFY_POLICY)
{
ctx->current_cert = NULL;
ctx->error = X509_V_OK;
if (!ctx->verify_cb(2, ctx))
return 0;
}
return 1;
}
static int check_cert_time(X509_STORE_CTX *ctx, X509 *x)
{
time_t *ptime;
int i;
if (ctx->param->flags & X509_V_FLAG_USE_CHECK_TIME)
ptime = &ctx->param->check_time;
else
ptime = NULL;
i=X509_cmp_time(X509_get_notBefore(x), ptime);
if (i == 0)
{
ctx->error=X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD;
ctx->current_cert=x;
if (!ctx->verify_cb(0, ctx))
return 0;
}
if (i > 0)
{
ctx->error=X509_V_ERR_CERT_NOT_YET_VALID;
ctx->current_cert=x;
if (!ctx->verify_cb(0, ctx))
return 0;
}
i=X509_cmp_time(X509_get_notAfter(x), ptime);
if (i == 0)
{
ctx->error=X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD;
ctx->current_cert=x;
if (!ctx->verify_cb(0, ctx))
return 0;
}
if (i < 0)
{
ctx->error=X509_V_ERR_CERT_HAS_EXPIRED;
ctx->current_cert=x;
if (!ctx->verify_cb(0, ctx))
return 0;
}
return 1;
}
static int internal_verify(X509_STORE_CTX *ctx)
{
int ok=0,n;
X509 *xs,*xi;
EVP_PKEY *pkey=NULL;
int (*cb)(int xok,X509_STORE_CTX *xctx);
cb=ctx->verify_cb;
n=sk_X509_num(ctx->chain);
ctx->error_depth=n-1;
n--;
xi=sk_X509_value(ctx->chain,n);
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
if (!xs->valid && (xs != xi || (ctx->param->flags & X509_V_FLAG_CHECK_SS_SIGNATURE)))
{
if ((pkey=X509_get_pubkey(xi)) == NULL)
{
ctx->error=X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY;
ctx->current_cert=xi;
ok=(*cb)(0,ctx);
if (!ok) goto end;
}
else if (X509_verify(xs,pkey) <= 0)
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
}
xs->valid = 1;
ok = check_cert_time(ctx, xs);
if (!ok)
goto end;
ctx->current_issuer=xi;
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
int X509_cmp_current_time(const ASN1_TIME *ctm)
{
return X509_cmp_time(ctm, NULL);
}
int X509_cmp_time(const ASN1_TIME *ctm, time_t *cmp_time)
{
char *str;
ASN1_TIME atm;
long offset;
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
if ((*str != '+') && (*str != '-'))
return 0;
offset=((str[1]-'0')*10+(str[2]-'0'))*60;
offset+=(str[3]-'0')*10+(str[4]-'0');
if (*str == '-')
offset= -offset;
}
atm.type=ctm->type;
atm.flags = 0;
atm.length=sizeof(buff2);
atm.data=(unsigned char *)buff2;
if (X509_time_adj(&atm, offset*60, cmp_time) == NULL)
return 0;
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
ASN1_TIME *X509_time_adj(ASN1_TIME *s, long offset_sec, time_t *in_tm)
{
return X509_time_adj_ex(s, 0, offset_sec, in_tm);
}
ASN1_TIME *X509_time_adj_ex(ASN1_TIME *s,
int offset_day, long offset_sec, time_t *in_tm)
{
time_t t;
if (in_tm) t = *in_tm;
else time(&t);
if (s && !(s->flags & ASN1_STRING_FLAG_MSTRING))
{
if (s->type == V_ASN1_UTCTIME)
return ASN1_UTCTIME_adj(s,t, offset_day, offset_sec);
if (s->type == V_ASN1_GENERALIZEDTIME)
return ASN1_GENERALIZEDTIME_adj(s, t, offset_day,
offset_sec);
}
return ASN1_TIME_adj(s, t, offset_day, offset_sec);
}
int X509_STORE_CTX_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_X509_STORE_CTX, argl, argp,
new_func, dup_func, free_func);
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
X509_CRL *X509_STORE_CTX_get0_current_crl(X509_STORE_CTX *ctx)
{
return ctx->current_crl;
}
X509_STORE_CTX *X509_STORE_CTX_get0_parent_ctx(X509_STORE_CTX *ctx)
{
return ctx->parent;
}
void X509_STORE_CTX_set_cert(X509_STORE_CTX *ctx, X509 *x)
{
ctx->cert=x;
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
if (purpose && !ctx->param->purpose) ctx->param->purpose = purpose;
if (trust && !ctx->param->trust) ctx->param->trust = trust;
return 1;
}
X509_STORE_CTX *X509_STORE_CTX_new(void)
{
X509_STORE_CTX *ctx;
ctx = (X509_STORE_CTX *)OPENSSL_malloc(sizeof(X509_STORE_CTX));
if (!ctx)
{
X509err(X509_F_X509_STORE_CTX_NEW,ERR_R_MALLOC_FAILURE);
return NULL;
}
memset(ctx, 0, sizeof(X509_STORE_CTX));
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
if (ctx->param != NULL)
{
if (ctx->parent == NULL)
X509_VERIFY_PARAM_free(ctx->param);
ctx->param=NULL;
}
if (ctx->tree != NULL)
{
X509_policy_tree_free(ctx->tree);
ctx->tree=NULL;
}
if (ctx->chain != NULL)
{
sk_X509_pop_free(ctx->chain,X509_free);
ctx->chain=NULL;
}
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_X509_STORE_CTX, ctx, &(ctx->ex_data));
memset(&ctx->ex_data,0,sizeof(CRYPTO_EX_DATA));
}
void X509_STORE_CTX_set_depth(X509_STORE_CTX *ctx, int depth)
{
X509_VERIFY_PARAM_set_depth(ctx->param, depth);
}
void X509_STORE_CTX_set_flags(X509_STORE_CTX *ctx, unsigned long flags)
{
X509_VERIFY_PARAM_set_flags(ctx->param, flags);
}
void X509_STORE_CTX_set_time(X509_STORE_CTX *ctx, unsigned long flags, time_t t)
{
X509_VERIFY_PARAM_set_time(ctx->param, t);
}
void X509_STORE_CTX_set_verify_cb(X509_STORE_CTX *ctx,
int (*verify_cb)(int, X509_STORE_CTX *))
{
ctx->verify_cb=verify_cb;
}
X509_POLICY_TREE *X509_STORE_CTX_get0_policy_tree(X509_STORE_CTX *ctx)
{
return ctx->tree;
}
int X509_STORE_CTX_get_explicit_policy(X509_STORE_CTX *ctx)
{
return ctx->explicit_policy;
}
int X509_STORE_CTX_set_default(X509_STORE_CTX *ctx, const char *name)
{
const X509_VERIFY_PARAM *param;
param = X509_VERIFY_PARAM_lookup(name);
if (!param)
return 0;
return X509_VERIFY_PARAM_inherit(ctx->param, param);
}
X509_VERIFY_PARAM *X509_STORE_CTX_get0_param(X509_STORE_CTX *ctx)
{
return ctx->param;
}
void X509_STORE_CTX_set0_param(X509_STORE_CTX *ctx, X509_VERIFY_PARAM *param)
{
if (ctx->param)
X509_VERIFY_PARAM_free(ctx->param);
ctx->param = param;
}
