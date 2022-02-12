static int null_callback(int ok, X509_STORE_CTX *e)
{
return ok;
}
static int cert_self_signed(X509 *x)
{
X509_check_purpose(x, -1, 0);
if (x->ex_flags & EXFLAG_SS)
return 1;
else
return 0;
}
static X509 *lookup_cert_match(X509_STORE_CTX *ctx, X509 *x)
{
STACK_OF(X509) *certs;
X509 *xtmp = NULL;
int i;
certs = ctx->lookup_certs(ctx, X509_get_subject_name(x));
if (certs == NULL)
return NULL;
for (i = 0; i < sk_X509_num(certs); i++) {
xtmp = sk_X509_value(certs, i);
if (!X509_cmp(xtmp, x))
break;
}
if (i < sk_X509_num(certs))
X509_up_ref(xtmp);
else
xtmp = NULL;
sk_X509_pop_free(certs, X509_free);
return xtmp;
}
static int verify_cb_cert(X509_STORE_CTX *ctx, X509 *x, int depth, int err)
{
ctx->error_depth = depth;
ctx->current_cert = (x != NULL) ? x : sk_X509_value(ctx->chain, depth);
if (err != X509_V_OK)
ctx->error = err;
return ctx->verify_cb(0, ctx);
}
static int verify_cb_crl(X509_STORE_CTX *ctx, int err)
{
ctx->error = err;
return ctx->verify_cb(0, ctx);
}
static int check_auth_level(X509_STORE_CTX *ctx)
{
int i;
int num = sk_X509_num(ctx->chain);
if (ctx->param->auth_level <= 0)
return 1;
for (i = 0; i < num; ++i) {
X509 *cert = sk_X509_value(ctx->chain, i);
if (i > 0 && !check_key_level(ctx, cert) &&
verify_cb_cert(ctx, cert, i, X509_V_ERR_CA_KEY_TOO_SMALL) == 0)
return 0;
if (i < num - 1 && !check_sig_level(ctx, cert) &&
verify_cb_cert(ctx, cert, i, X509_V_ERR_CA_MD_TOO_WEAK) == 0)
return 0;
}
return 1;
}
static int verify_chain(X509_STORE_CTX *ctx)
{
int err;
int ok;
if ((ok = build_chain(ctx)) == 0 ||
(ok = check_chain_extensions(ctx)) == 0 ||
(ok = check_auth_level(ctx)) == 0 ||
(ok = check_name_constraints(ctx)) == 0 ||
(ok = check_id(ctx)) == 0 || 1)
X509_get_pubkey_parameters(NULL, ctx->chain);
if (ok == 0 || (ok = ctx->check_revocation(ctx)) == 0)
return ok;
err = X509_chain_check_suiteb(&ctx->error_depth, NULL, ctx->chain,
ctx->param->flags);
if (err != X509_V_OK) {
if ((ok = verify_cb_cert(ctx, NULL, ctx->error_depth, err)) == 0)
return ok;
}
ok = (ctx->verify != NULL) ? ctx->verify(ctx) : internal_verify(ctx);
if (!ok)
return ok;
#ifndef OPENSSL_NO_RFC3779
if ((ok = X509v3_asid_validate_path(ctx)) == 0)
return ok;
if ((ok = X509v3_addr_validate_path(ctx)) == 0)
return ok;
#endif
if (ctx->param->flags & X509_V_FLAG_POLICY_CHECK)
ok = ctx->check_policy(ctx);
return ok;
}
int X509_verify_cert(X509_STORE_CTX *ctx)
{
SSL_DANE *dane = ctx->dane;
int ret;
if (ctx->cert == NULL) {
X509err(X509_F_X509_VERIFY_CERT, X509_R_NO_CERT_SET_FOR_US_TO_VERIFY);
ctx->error = X509_V_ERR_INVALID_CALL;
return -1;
}
if (ctx->chain != NULL) {
X509err(X509_F_X509_VERIFY_CERT, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
ctx->error = X509_V_ERR_INVALID_CALL;
return -1;
}
if (((ctx->chain = sk_X509_new_null()) == NULL) ||
(!sk_X509_push(ctx->chain, ctx->cert))) {
X509err(X509_F_X509_VERIFY_CERT, ERR_R_MALLOC_FAILURE);
ctx->error = X509_V_ERR_OUT_OF_MEM;
return -1;
}
X509_up_ref(ctx->cert);
ctx->num_untrusted = 1;
if (!check_key_level(ctx, ctx->cert) &&
!verify_cb_cert(ctx, ctx->cert, 0, X509_V_ERR_EE_KEY_TOO_SMALL))
return 0;
if (DANETLS_ENABLED(dane))
ret = dane_verify(ctx);
else
ret = verify_chain(ctx);
if (ret <= 0 && ctx->error == X509_V_OK)
ctx->error = X509_V_ERR_UNSPECIFIED;
return ret;
}
static int check_issued(X509_STORE_CTX *ctx, X509 *x, X509 *issuer)
{
int ret;
if (x == issuer)
return cert_self_signed(x);
ret = X509_check_issued(issuer, x);
if (ret == X509_V_OK) {
int i;
X509 *ch;
if (cert_self_signed(x) && sk_X509_num(ctx->chain) == 1)
return 1;
for (i = 0; i < sk_X509_num(ctx->chain); i++) {
ch = sk_X509_value(ctx->chain, i);
if (ch == issuer || !X509_cmp(ch, issuer)) {
ret = X509_V_ERR_PATH_LOOP;
break;
}
}
}
return (ret == X509_V_OK);
}
static int get_issuer_sk(X509 **issuer, X509_STORE_CTX *ctx, X509 *x)
{
*issuer = find_issuer(ctx, ctx->other_ctx, x);
if (*issuer) {
X509_up_ref(*issuer);
return 1;
} else
return 0;
}
int check_purpose(X509_STORE_CTX *ctx, X509 *x, int purpose, int depth,
int must_be_ca)
{
int tr_ok = X509_TRUST_UNTRUSTED;
if (depth >= ctx->num_untrusted && purpose == ctx->param->purpose)
tr_ok = X509_check_trust(x, ctx->param->trust, X509_TRUST_NO_SS_COMPAT);
switch (tr_ok) {
case X509_TRUST_TRUSTED:
return 1;
case X509_TRUST_REJECTED:
break;
default:
switch (X509_check_purpose(x, purpose, must_be_ca > 0)) {
case 1:
return 1;
case 0:
break;
default:
if ((ctx->param->flags & X509_V_FLAG_X509_STRICT) == 0)
return 1;
}
break;
}
return verify_cb_cert(ctx, x, depth, X509_V_ERR_INVALID_PURPOSE);
}
static int check_chain_extensions(X509_STORE_CTX *ctx)
{
int i, must_be_ca, plen = 0;
X509 *x;
int proxy_path_length = 0;
int purpose;
int allow_proxy_certs;
int num = sk_X509_num(ctx->chain);
must_be_ca = -1;
if (ctx->parent) {
allow_proxy_certs = 0;
purpose = X509_PURPOSE_CRL_SIGN;
} else {
allow_proxy_certs =
! !(ctx->param->flags & X509_V_FLAG_ALLOW_PROXY_CERTS);
purpose = ctx->param->purpose;
}
for (i = 0; i < num; i++) {
int ret;
x = sk_X509_value(ctx->chain, i);
if (!(ctx->param->flags & X509_V_FLAG_IGNORE_CRITICAL)
&& (x->ex_flags & EXFLAG_CRITICAL)) {
if (!verify_cb_cert(ctx, x, i,
X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION))
return 0;
}
if (!allow_proxy_certs && (x->ex_flags & EXFLAG_PROXY)) {
if (!verify_cb_cert(ctx, x, i,
X509_V_ERR_PROXY_CERTIFICATES_NOT_ALLOWED))
return 0;
}
ret = X509_check_ca(x);
switch (must_be_ca) {
case -1:
if ((ctx->param->flags & X509_V_FLAG_X509_STRICT)
&& (ret != 1) && (ret != 0)) {
ret = 0;
ctx->error = X509_V_ERR_INVALID_CA;
} else
ret = 1;
break;
case 0:
if (ret != 0) {
ret = 0;
ctx->error = X509_V_ERR_INVALID_NON_CA;
} else
ret = 1;
break;
default:
if ((ret == 0)
|| ((i + 1 < num || ctx->param->flags & X509_V_FLAG_X509_STRICT)
&& (ret != 1))) {
ret = 0;
ctx->error = X509_V_ERR_INVALID_CA;
} else
ret = 1;
break;
}
if (ret == 0 && !verify_cb_cert(ctx, x, i, X509_V_OK))
return 0;
if (purpose > 0 && !check_purpose(ctx, x, purpose, i, must_be_ca))
return 0;
if ((i > 1) && !(x->ex_flags & EXFLAG_SI)
&& (x->ex_pathlen != -1)
&& (plen > (x->ex_pathlen + proxy_path_length + 1))) {
if (!verify_cb_cert(ctx, x, i, X509_V_ERR_PATH_LENGTH_EXCEEDED))
return 0;
}
if (!(x->ex_flags & EXFLAG_SI))
plen++;
if (x->ex_flags & EXFLAG_PROXY) {
if (x->ex_pcpathlen != -1) {
if (proxy_path_length > x->ex_pcpathlen) {
if (!verify_cb_cert(ctx, x, i,
X509_V_ERR_PROXY_PATH_LENGTH_EXCEEDED))
return 0;
}
proxy_path_length = x->ex_pcpathlen;
}
proxy_path_length++;
must_be_ca = 0;
} else
must_be_ca = 1;
}
return 1;
}
static int check_name_constraints(X509_STORE_CTX *ctx)
{
int i;
for (i = sk_X509_num(ctx->chain) - 1; i >= 0; i--) {
X509 *x = sk_X509_value(ctx->chain, i);
int j;
if (i && (x->ex_flags & EXFLAG_SI))
continue;
if (x->ex_flags & EXFLAG_PROXY) {
X509_NAME *tmpsubject = X509_get_subject_name(x);
X509_NAME *tmpissuer = X509_get_issuer_name(x);
X509_NAME_ENTRY *tmpentry = NULL;
int last_object_nid = 0;
int err = X509_V_OK;
int last_object_loc = X509_NAME_entry_count(tmpsubject) - 1;
if (last_object_loc < 1) {
err = X509_V_ERR_PROXY_SUBJECT_NAME_VIOLATION;
goto proxy_name_done;
}
if (X509_NAME_entry_count(tmpsubject)
!= X509_NAME_entry_count(tmpissuer) + 1) {
err = X509_V_ERR_PROXY_SUBJECT_NAME_VIOLATION;
goto proxy_name_done;
}
if (X509_NAME_ENTRY_set(X509_NAME_get_entry(tmpsubject,
last_object_loc))
== X509_NAME_ENTRY_set(X509_NAME_get_entry(tmpsubject,
last_object_loc - 1))) {
err = X509_V_ERR_PROXY_SUBJECT_NAME_VIOLATION;
goto proxy_name_done;
}
tmpsubject = X509_NAME_dup(tmpsubject);
if (tmpsubject == NULL) {
X509err(X509_F_CHECK_NAME_CONSTRAINTS, ERR_R_MALLOC_FAILURE);
ctx->error = X509_V_ERR_OUT_OF_MEM;
return 0;
}
tmpentry =
X509_NAME_delete_entry(tmpsubject, last_object_loc);
last_object_nid =
OBJ_obj2nid(X509_NAME_ENTRY_get_object(tmpentry));
if (last_object_nid != NID_commonName
|| X509_NAME_cmp(tmpsubject, tmpissuer) != 0) {
err = X509_V_ERR_PROXY_SUBJECT_NAME_VIOLATION;
}
X509_NAME_ENTRY_free(tmpentry);
X509_NAME_free(tmpsubject);
proxy_name_done:
if (err != X509_V_OK
&& !verify_cb_cert(ctx, x, i, err))
return 0;
}
for (j = sk_X509_num(ctx->chain) - 1; j > i; j--) {
NAME_CONSTRAINTS *nc = sk_X509_value(ctx->chain, j)->nc;
if (nc) {
int rv = NAME_CONSTRAINTS_check(x, nc);
if (rv == X509_V_OK && i == 0)
rv = NAME_CONSTRAINTS_check_CN(x, nc);
switch (rv) {
case X509_V_OK:
break;
case X509_V_ERR_OUT_OF_MEM:
return 0;
default:
if (!verify_cb_cert(ctx, x, i, rv))
return 0;
break;
}
}
}
}
return 1;
}
static int check_id_error(X509_STORE_CTX *ctx, int errcode)
{
return verify_cb_cert(ctx, ctx->cert, 0, errcode);
}
static int check_hosts(X509 *x, X509_VERIFY_PARAM *vpm)
{
int i;
int n = sk_OPENSSL_STRING_num(vpm->hosts);
char *name;
if (vpm->peername != NULL) {
OPENSSL_free(vpm->peername);
vpm->peername = NULL;
}
for (i = 0; i < n; ++i) {
name = sk_OPENSSL_STRING_value(vpm->hosts, i);
if (X509_check_host(x, name, 0, vpm->hostflags, &vpm->peername) > 0)
return 1;
}
return n == 0;
}
static int check_id(X509_STORE_CTX *ctx)
{
X509_VERIFY_PARAM *vpm = ctx->param;
X509 *x = ctx->cert;
if (vpm->hosts && check_hosts(x, vpm) <= 0) {
if (!check_id_error(ctx, X509_V_ERR_HOSTNAME_MISMATCH))
return 0;
}
if (vpm->email && X509_check_email(x, vpm->email, vpm->emaillen, 0) <= 0) {
if (!check_id_error(ctx, X509_V_ERR_EMAIL_MISMATCH))
return 0;
}
if (vpm->ip && X509_check_ip(x, vpm->ip, vpm->iplen, 0) <= 0) {
if (!check_id_error(ctx, X509_V_ERR_IP_ADDRESS_MISMATCH))
return 0;
}
return 1;
}
static int check_trust(X509_STORE_CTX *ctx, int num_untrusted)
{
int i;
X509 *x = NULL;
X509 *mx;
SSL_DANE *dane = ctx->dane;
int num = sk_X509_num(ctx->chain);
int trust;
if (DANETLS_HAS_TA(dane) && num_untrusted > 0 && num_untrusted < num) {
switch (trust = check_dane_issuer(ctx, num_untrusted)) {
case X509_TRUST_TRUSTED:
case X509_TRUST_REJECTED:
return trust;
}
}
for (i = num_untrusted; i < num; i++) {
x = sk_X509_value(ctx->chain, i);
trust = X509_check_trust(x, ctx->param->trust, 0);
if (trust == X509_TRUST_TRUSTED)
goto trusted;
if (trust == X509_TRUST_REJECTED)
goto rejected;
}
if (num_untrusted < num) {
if (ctx->param->flags & X509_V_FLAG_PARTIAL_CHAIN)
goto trusted;
return X509_TRUST_UNTRUSTED;
}
if (num_untrusted == num && ctx->param->flags & X509_V_FLAG_PARTIAL_CHAIN) {
i = 0;
x = sk_X509_value(ctx->chain, i);
mx = lookup_cert_match(ctx, x);
if (!mx)
return X509_TRUST_UNTRUSTED;
trust = X509_check_trust(mx, ctx->param->trust, 0);
if (trust == X509_TRUST_REJECTED) {
X509_free(mx);
goto rejected;
}
(void) sk_X509_set(ctx->chain, 0, mx);
X509_free(x);
ctx->num_untrusted = 0;
goto trusted;
}
return X509_TRUST_UNTRUSTED;
rejected:
if (!verify_cb_cert(ctx, x, i, X509_V_ERR_CERT_REJECTED))
return X509_TRUST_REJECTED;
return X509_TRUST_UNTRUSTED;
trusted:
if (!DANETLS_ENABLED(dane))
return X509_TRUST_TRUSTED;
if (dane->pdpth < 0)
dane->pdpth = num_untrusted;
if (dane->mdpth >= 0)
return X509_TRUST_TRUSTED;
return X509_TRUST_UNTRUSTED;
}
static int check_revocation(X509_STORE_CTX *ctx)
{
int i = 0, last = 0, ok = 0;
if (!(ctx->param->flags & X509_V_FLAG_CRL_CHECK))
return 1;
if (ctx->param->flags & X509_V_FLAG_CRL_CHECK_ALL)
last = sk_X509_num(ctx->chain) - 1;
else {
if (ctx->parent)
return 1;
last = 0;
}
for (i = 0; i <= last; i++) {
ctx->error_depth = i;
ok = check_cert(ctx);
if (!ok)
return ok;
}
return 1;
}
static int check_cert(X509_STORE_CTX *ctx)
{
X509_CRL *crl = NULL, *dcrl = NULL;
int ok = 0;
int cnum = ctx->error_depth;
X509 *x = sk_X509_value(ctx->chain, cnum);
ctx->current_cert = x;
ctx->current_issuer = NULL;
ctx->current_crl_score = 0;
ctx->current_reasons = 0;
if (x->ex_flags & EXFLAG_PROXY)
return 1;
while (ctx->current_reasons != CRLDP_ALL_REASONS) {
unsigned int last_reasons = ctx->current_reasons;
if (ctx->get_crl)
ok = ctx->get_crl(ctx, &crl, x);
else
ok = get_crl_delta(ctx, &crl, &dcrl, x);
if (!ok) {
ok = verify_cb_crl(ctx, X509_V_ERR_UNABLE_TO_GET_CRL);
goto done;
}
ctx->current_crl = crl;
ok = ctx->check_crl(ctx, crl);
if (!ok)
goto done;
if (dcrl) {
ok = ctx->check_crl(ctx, dcrl);
if (!ok)
goto done;
ok = ctx->cert_crl(ctx, dcrl, x);
if (!ok)
goto done;
} else
ok = 1;
if (ok != 2) {
ok = ctx->cert_crl(ctx, crl, x);
if (!ok)
goto done;
}
X509_CRL_free(crl);
X509_CRL_free(dcrl);
crl = NULL;
dcrl = NULL;
if (last_reasons == ctx->current_reasons) {
ok = verify_cb_crl(ctx, X509_V_ERR_UNABLE_TO_GET_CRL);
goto done;
}
}
done:
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
else if (ctx->param->flags & X509_V_FLAG_NO_CHECK_TIME)
return 1;
else
ptime = NULL;
i = X509_cmp_time(X509_CRL_get0_lastUpdate(crl), ptime);
if (i == 0) {
if (!notify)
return 0;
if (!verify_cb_crl(ctx, X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD))
return 0;
}
if (i > 0) {
if (!notify)
return 0;
if (!verify_cb_crl(ctx, X509_V_ERR_CRL_NOT_YET_VALID))
return 0;
}
if (X509_CRL_get0_nextUpdate(crl)) {
i = X509_cmp_time(X509_CRL_get0_nextUpdate(crl), ptime);
if (i == 0) {
if (!notify)
return 0;
if (!verify_cb_crl(ctx, X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD))
return 0;
}
if ((i < 0) && !(ctx->current_crl_score & CRL_SCORE_TIME_DELTA)) {
if (!notify)
return 0;
if (!verify_cb_crl(ctx, X509_V_ERR_CRL_HAS_EXPIRED))
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
i = X509_CRL_get_ext_by_NID(a, nid, -1);
if (i >= 0) {
if (X509_CRL_get_ext_by_NID(a, nid, i) != -1)
return 0;
exta = X509_EXTENSION_get_data(X509_CRL_get_ext(a, i));
} else
exta = NULL;
i = X509_CRL_get_ext_by_NID(b, nid, -1);
if (i >= 0) {
if (X509_CRL_get_ext_by_NID(b, nid, i) != -1)
return 0;
extb = X509_EXTENSION_get_data(X509_CRL_get_ext(b, i));
} else
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
if (X509_NAME_cmp(X509_CRL_get_issuer(base), X509_CRL_get_issuer(delta)))
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
unsigned int *preasons, X509_CRL *crl, X509 *x)
{
int crl_score = 0;
unsigned int tmp_reasons = *preasons, crl_reasons;
if (crl->idp_flags & IDP_INVALID)
return 0;
if (!(ctx->param->flags & X509_V_FLAG_EXTENDED_CRL_SUPPORT)) {
if (crl->idp_flags & (IDP_INDIRECT | IDP_REASONS))
return 0;
} else if (crl->idp_flags & IDP_REASONS) {
if (!(crl->idp_reasons & ~tmp_reasons))
return 0;
}
else if (crl->base_crl_number)
return 0;
if (X509_NAME_cmp(X509_get_issuer_name(x), X509_CRL_get_issuer(crl))) {
if (!(crl->idp_flags & IDP_INDIRECT))
return 0;
} else
crl_score |= CRL_SCORE_ISSUER_NAME;
if (!(crl->flags & EXFLAG_CRITICAL))
crl_score |= CRL_SCORE_NOCRITICAL;
if (check_crl_time(ctx, crl, 0))
crl_score |= CRL_SCORE_TIME;
crl_akid_check(ctx, crl, pissuer, &crl_score);
if (!(crl_score & CRL_SCORE_AKID))
return 0;
if (crl_crldp_check(x, crl, crl_score, &crl_reasons)) {
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
if (X509_check_akid(crl_issuer, crl->akid) == X509_V_OK) {
if (*pcrl_score & CRL_SCORE_ISSUER_NAME) {
*pcrl_score |= CRL_SCORE_AKID | CRL_SCORE_ISSUER_CERT;
*pissuer = crl_issuer;
return;
}
}
for (cidx++; cidx < sk_X509_num(ctx->chain); cidx++) {
crl_issuer = sk_X509_value(ctx->chain, cidx);
if (X509_NAME_cmp(X509_get_subject_name(crl_issuer), cnm))
continue;
if (X509_check_akid(crl_issuer, crl->akid) == X509_V_OK) {
*pcrl_score |= CRL_SCORE_AKID | CRL_SCORE_SAME_PATH;
*pissuer = crl_issuer;
return;
}
}
if (!(ctx->param->flags & X509_V_FLAG_EXTENDED_CRL_SUPPORT))
return;
for (i = 0; i < sk_X509_num(ctx->untrusted); i++) {
crl_issuer = sk_X509_value(ctx->untrusted, i);
if (X509_NAME_cmp(X509_get_subject_name(crl_issuer), cnm))
continue;
if (X509_check_akid(crl_issuer, crl->akid) == X509_V_OK) {
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
if (a->type == 1) {
if (!a->dpname)
return 0;
if (b->type == 1) {
if (!b->dpname)
return 0;
if (!X509_NAME_cmp(a->dpname, b->dpname))
return 1;
else
return 0;
}
nm = a->dpname;
gens = b->name.fullname;
} else if (b->type == 1) {
if (!b->dpname)
return 0;
gens = a->name.fullname;
nm = b->dpname;
}
if (nm) {
for (i = 0; i < sk_GENERAL_NAME_num(gens); i++) {
gena = sk_GENERAL_NAME_value(gens, i);
if (gena->type != GEN_DIRNAME)
continue;
if (!X509_NAME_cmp(nm, gena->d.directoryName))
return 1;
}
return 0;
}
for (i = 0; i < sk_GENERAL_NAME_num(a->name.fullname); i++) {
gena = sk_GENERAL_NAME_value(a->name.fullname, i);
for (j = 0; j < sk_GENERAL_NAME_num(b->name.fullname); j++) {
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
return ! !(crl_score & CRL_SCORE_ISSUER_NAME);
for (i = 0; i < sk_GENERAL_NAME_num(dp->CRLissuer); i++) {
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
if (x->ex_flags & EXFLAG_CA) {
if (crl->idp_flags & IDP_ONLYUSER)
return 0;
} else {
if (crl->idp_flags & IDP_ONLYCA)
return 0;
}
*preasons = crl->idp_reasons;
for (i = 0; i < sk_DIST_POINT_num(x->crldp); i++) {
DIST_POINT *dp = sk_DIST_POINT_value(x->crldp, i);
if (crldp_check_crlissuer(dp, crl, crl_score)) {
if (!crl->idp || idp_check_dp(dp->distpoint, crl->idp->distpoint)) {
*preasons &= dp->dp_reasons;
return 1;
}
}
}
if ((!crl->idp || !crl->idp->distpoint)
&& (crl_score & CRL_SCORE_ISSUER_NAME))
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
if (crl) {
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
int cnum = ctx->error_depth;
int chnum = sk_X509_num(ctx->chain) - 1;
if (ctx->current_issuer)
issuer = ctx->current_issuer;
else if (cnum < chnum)
issuer = sk_X509_value(ctx->chain, cnum + 1);
else {
issuer = sk_X509_value(ctx->chain, chnum);
if (!ctx->check_issued(ctx, issuer, issuer) &&
!verify_cb_crl(ctx, X509_V_ERR_UNABLE_TO_GET_CRL_ISSUER))
return 0;
}
if (issuer == NULL)
return 1;
if (!crl->base_crl_number) {
if ((issuer->ex_flags & EXFLAG_KUSAGE) &&
!(issuer->ex_kusage & KU_CRL_SIGN) &&
!verify_cb_crl(ctx, X509_V_ERR_KEYUSAGE_NO_CRL_SIGN))
return 0;
if (!(ctx->current_crl_score & CRL_SCORE_SCOPE) &&
!verify_cb_crl(ctx, X509_V_ERR_DIFFERENT_CRL_SCOPE))
return 0;
if (!(ctx->current_crl_score & CRL_SCORE_SAME_PATH) &&
check_crl_path(ctx, ctx->current_issuer) <= 0 &&
!verify_cb_crl(ctx, X509_V_ERR_CRL_PATH_VALIDATION_ERROR))
return 0;
if ((crl->idp_flags & IDP_INVALID) &&
!verify_cb_crl(ctx, X509_V_ERR_INVALID_EXTENSION))
return 0;
}
if (!(ctx->current_crl_score & CRL_SCORE_TIME) &&
!check_crl_time(ctx, crl, 1))
return 0;
ikey = X509_get0_pubkey(issuer);
if (!ikey &&
!verify_cb_crl(ctx, X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY))
return 0;
if (ikey) {
int rv = X509_CRL_check_suiteb(crl, ikey, ctx->param->flags);
if (rv != X509_V_OK && !verify_cb_crl(ctx, rv))
return 0;
if (X509_CRL_verify(crl, ikey) <= 0 &&
!verify_cb_crl(ctx, X509_V_ERR_CRL_SIGNATURE_FAILURE))
return 0;
}
return 1;
}
static int cert_crl(X509_STORE_CTX *ctx, X509_CRL *crl, X509 *x)
{
X509_REVOKED *rev;
if (!(ctx->param->flags & X509_V_FLAG_IGNORE_CRITICAL)
&& (crl->flags & EXFLAG_CRITICAL) &&
!verify_cb_crl(ctx, X509_V_ERR_UNHANDLED_CRITICAL_CRL_EXTENSION))
return 0;
if (X509_CRL_get0_by_cert(crl, &rev, x)) {
if (rev->reason == CRL_REASON_REMOVE_FROM_CRL)
return 2;
if (!verify_cb_crl(ctx, X509_V_ERR_CERT_REVOKED))
return 0;
}
return 1;
}
static int check_policy(X509_STORE_CTX *ctx)
{
int ret;
if (ctx->parent)
return 1;
if (ctx->bare_ta_signed && !sk_X509_push(ctx->chain, NULL)) {
X509err(X509_F_CHECK_POLICY, ERR_R_MALLOC_FAILURE);
ctx->error = X509_V_ERR_OUT_OF_MEM;
return 0;
}
ret = X509_policy_check(&ctx->tree, &ctx->explicit_policy, ctx->chain,
ctx->param->policies, ctx->param->flags);
if (ctx->bare_ta_signed)
sk_X509_pop(ctx->chain);
if (ret == X509_PCY_TREE_INTERNAL) {
X509err(X509_F_CHECK_POLICY, ERR_R_MALLOC_FAILURE);
ctx->error = X509_V_ERR_OUT_OF_MEM;
return 0;
}
if (ret == X509_PCY_TREE_INVALID) {
int i;
for (i = 1; i < sk_X509_num(ctx->chain); i++) {
X509 *x = sk_X509_value(ctx->chain, i);
if (!(x->ex_flags & EXFLAG_INVALID_POLICY))
continue;
if (!verify_cb_cert(ctx, x, i,
X509_V_ERR_INVALID_POLICY_EXTENSION))
return 0;
}
return 1;
}
if (ret == X509_PCY_TREE_FAILURE) {
ctx->current_cert = NULL;
ctx->error = X509_V_ERR_NO_EXPLICIT_POLICY;
return ctx->verify_cb(0, ctx);
}
if (ret != X509_PCY_TREE_VALID) {
X509err(X509_F_CHECK_POLICY, ERR_R_INTERNAL_ERROR);
return 0;
}
if (ctx->param->flags & X509_V_FLAG_NOTIFY_POLICY) {
ctx->current_cert = NULL;
if (!ctx->verify_cb(2, ctx))
return 0;
}
return 1;
}
int x509_check_cert_time(X509_STORE_CTX *ctx, X509 *x, int depth)
{
time_t *ptime;
int i;
if (ctx->param->flags & X509_V_FLAG_USE_CHECK_TIME)
ptime = &ctx->param->check_time;
else if (ctx->param->flags & X509_V_FLAG_NO_CHECK_TIME)
return 1;
else
ptime = NULL;
i = X509_cmp_time(X509_get0_notBefore(x), ptime);
if (i >= 0 && depth < 0)
return 0;
if (i == 0 && !verify_cb_cert(ctx, x, depth,
X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD))
return 0;
if (i > 0 && !verify_cb_cert(ctx, x, depth, X509_V_ERR_CERT_NOT_YET_VALID))
return 0;
i = X509_cmp_time(X509_get0_notAfter(x), ptime);
if (i <= 0 && depth < 0)
return 0;
if (i == 0 && !verify_cb_cert(ctx, x, depth,
X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD))
return 0;
if (i < 0 && !verify_cb_cert(ctx, x, depth, X509_V_ERR_CERT_HAS_EXPIRED))
return 0;
return 1;
}
static int internal_verify(X509_STORE_CTX *ctx)
{
int n = sk_X509_num(ctx->chain) - 1;
X509 *xi = sk_X509_value(ctx->chain, n);
X509 *xs;
if (ctx->bare_ta_signed) {
xs = xi;
xi = NULL;
goto check_cert;
}
if (ctx->check_issued(ctx, xi, xi))
xs = xi;
else {
if (ctx->param->flags & X509_V_FLAG_PARTIAL_CHAIN) {
xs = xi;
goto check_cert;
}
if (n <= 0)
return verify_cb_cert(ctx, xi, 0,
X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE);
n--;
ctx->error_depth = n;
xs = sk_X509_value(ctx->chain, n);
}
while (n >= 0) {
EVP_PKEY *pkey;
if (xs != xi || (ctx->param->flags & X509_V_FLAG_CHECK_SS_SIGNATURE)) {
if ((pkey = X509_get0_pubkey(xi)) == NULL) {
if (!verify_cb_cert(ctx, xi, xi != xs ? n+1 : n,
X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY))
return 0;
} else if (X509_verify(xs, pkey) <= 0) {
if (!verify_cb_cert(ctx, xs, n,
X509_V_ERR_CERT_SIGNATURE_FAILURE))
return 0;
}
}
check_cert:
if (!x509_check_cert_time(ctx, xs, n))
return 0;
ctx->current_issuer = xi;
ctx->current_cert = xs;
ctx->error_depth = n;
if (!ctx->verify_cb(1, ctx))
return 0;
if (--n >= 0) {
xi = xs;
xs = sk_X509_value(ctx->chain, n);
}
}
return 1;
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
char buff1[24], buff2[24], *p;
int i, j, remaining;
p = buff1;
remaining = ctm->length;
str = (char *)ctm->data;
if (ctm->type == V_ASN1_UTCTIME) {
int min_length = sizeof("YYMMDDHHMMZ") - 1;
int max_length = sizeof("YYMMDDHHMMSS+hhmm") - 1;
if (remaining < min_length || remaining > max_length)
return 0;
memcpy(p, str, 10);
p += 10;
str += 10;
remaining -= 10;
} else {
int min_length = sizeof("YYYYMMDDHHMMZ") - 1;
int max_length = sizeof("YYYYMMDDHHMMSS.fff+hhmm") - 1;
if (remaining < min_length || remaining > max_length)
return 0;
memcpy(p, str, 12);
p += 12;
str += 12;
remaining -= 12;
}
if ((*str == 'Z') || (*str == '-') || (*str == '+')) {
*(p++) = '0';
*(p++) = '0';
} else {
if (remaining < 2)
return 0;
*(p++) = *(str++);
*(p++) = *(str++);
remaining -= 2;
if (remaining && *str == '.') {
str++;
remaining--;
for (i = 0; i < 3 && remaining; i++, str++, remaining--) {
if (*str < '0' || *str > '9')
break;
}
}
}
*(p++) = 'Z';
*(p++) = '\0';
if (!remaining)
return 0;
if (*str == 'Z') {
if (remaining != 1)
return 0;
offset = 0;
} else {
if ((*str != '+') && (*str != '-'))
return 0;
if (remaining != 5)
return 0;
if (str[1] < '0' || str[1] > '9' || str[2] < '0' || str[2] > '9' ||
str[3] < '0' || str[3] > '9' || str[4] < '0' || str[4] > '9')
return 0;
offset = ((str[1] - '0') * 10 + (str[2] - '0')) * 60;
offset += (str[3] - '0') * 10 + (str[4] - '0');
if (*str == '-')
offset = -offset;
}
atm.type = ctm->type;
atm.flags = 0;
atm.length = sizeof(buff2);
atm.data = (unsigned char *)buff2;
if (X509_time_adj(&atm, offset * 60, cmp_time) == NULL)
return 0;
if (ctm->type == V_ASN1_UTCTIME) {
i = (buff1[0] - '0') * 10 + (buff1[1] - '0');
if (i < 50)
i += 100;
j = (buff2[0] - '0') * 10 + (buff2[1] - '0');
if (j < 50)
j += 100;
if (i < j)
return -1;
if (i > j)
return 1;
}
i = strcmp(buff1, buff2);
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
if (in_tm)
t = *in_tm;
else
time(&t);
if (s && !(s->flags & ASN1_STRING_FLAG_MSTRING)) {
if (s->type == V_ASN1_UTCTIME)
return ASN1_UTCTIME_adj(s, t, offset_day, offset_sec);
if (s->type == V_ASN1_GENERALIZEDTIME)
return ASN1_GENERALIZEDTIME_adj(s, t, offset_day, offset_sec);
}
return ASN1_TIME_adj(s, t, offset_day, offset_sec);
}
X509_CRL *X509_CRL_diff(X509_CRL *base, X509_CRL *newer,
EVP_PKEY *skey, const EVP_MD *md, unsigned int flags)
{
X509_CRL *crl = NULL;
int i;
STACK_OF(X509_REVOKED) *revs = NULL;
if (base->base_crl_number || newer->base_crl_number) {
X509err(X509_F_X509_CRL_DIFF, X509_R_CRL_ALREADY_DELTA);
return NULL;
}
if (!base->crl_number || !newer->crl_number) {
X509err(X509_F_X509_CRL_DIFF, X509_R_NO_CRL_NUMBER);
return NULL;
}
if (X509_NAME_cmp(X509_CRL_get_issuer(base), X509_CRL_get_issuer(newer))) {
X509err(X509_F_X509_CRL_DIFF, X509_R_ISSUER_MISMATCH);
return NULL;
}
if (!crl_extension_match(base, newer, NID_authority_key_identifier)) {
X509err(X509_F_X509_CRL_DIFF, X509_R_AKID_MISMATCH);
return NULL;
}
if (!crl_extension_match(base, newer, NID_issuing_distribution_point)) {
X509err(X509_F_X509_CRL_DIFF, X509_R_IDP_MISMATCH);
return NULL;
}
if (ASN1_INTEGER_cmp(newer->crl_number, base->crl_number) <= 0) {
X509err(X509_F_X509_CRL_DIFF, X509_R_NEWER_CRL_NOT_NEWER);
return NULL;
}
if (skey && (X509_CRL_verify(base, skey) <= 0 ||
X509_CRL_verify(newer, skey) <= 0)) {
X509err(X509_F_X509_CRL_DIFF, X509_R_CRL_VERIFY_FAILURE);
return NULL;
}
crl = X509_CRL_new();
if (crl == NULL || !X509_CRL_set_version(crl, 1))
goto memerr;
if (!X509_CRL_set_issuer_name(crl, X509_CRL_get_issuer(newer)))
goto memerr;
if (!X509_CRL_set1_lastUpdate(crl, X509_CRL_get0_lastUpdate(newer)))
goto memerr;
if (!X509_CRL_set1_nextUpdate(crl, X509_CRL_get0_nextUpdate(newer)))
goto memerr;
if (!X509_CRL_add1_ext_i2d(crl, NID_delta_crl, base->crl_number, 1, 0))
goto memerr;
for (i = 0; i < X509_CRL_get_ext_count(newer); i++) {
X509_EXTENSION *ext;
ext = X509_CRL_get_ext(newer, i);
if (!X509_CRL_add_ext(crl, ext, -1))
goto memerr;
}
revs = X509_CRL_get_REVOKED(newer);
for (i = 0; i < sk_X509_REVOKED_num(revs); i++) {
X509_REVOKED *rvn, *rvtmp;
rvn = sk_X509_REVOKED_value(revs, i);
if (!X509_CRL_get0_by_serial(base, &rvtmp, &rvn->serialNumber)) {
rvtmp = X509_REVOKED_dup(rvn);
if (!rvtmp)
goto memerr;
if (!X509_CRL_add0_revoked(crl, rvtmp)) {
X509_REVOKED_free(rvtmp);
goto memerr;
}
}
}
if (skey && md && !X509_CRL_sign(crl, skey, md))
goto memerr;
return crl;
memerr:
X509err(X509_F_X509_CRL_DIFF, ERR_R_MALLOC_FAILURE);
X509_CRL_free(crl);
return NULL;
}
int X509_STORE_CTX_set_ex_data(X509_STORE_CTX *ctx, int idx, void *data)
{
return CRYPTO_set_ex_data(&ctx->ex_data, idx, data);
}
void *X509_STORE_CTX_get_ex_data(X509_STORE_CTX *ctx, int idx)
{
return CRYPTO_get_ex_data(&ctx->ex_data, idx);
}
int X509_STORE_CTX_get_error(X509_STORE_CTX *ctx)
{
return ctx->error;
}
void X509_STORE_CTX_set_error(X509_STORE_CTX *ctx, int err)
{
ctx->error = err;
}
int X509_STORE_CTX_get_error_depth(X509_STORE_CTX *ctx)
{
return ctx->error_depth;
}
void X509_STORE_CTX_set_error_depth(X509_STORE_CTX *ctx, int depth)
{
ctx->error_depth = depth;
}
X509 *X509_STORE_CTX_get_current_cert(X509_STORE_CTX *ctx)
{
return ctx->current_cert;
}
void X509_STORE_CTX_set_current_cert(X509_STORE_CTX *ctx, X509 *x)
{
ctx->current_cert = x;
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
ctx->cert = x;
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
if (!purpose)
purpose = def_purpose;
if (purpose) {
X509_PURPOSE *ptmp;
idx = X509_PURPOSE_get_by_id(purpose);
if (idx == -1) {
X509err(X509_F_X509_STORE_CTX_PURPOSE_INHERIT,
X509_R_UNKNOWN_PURPOSE_ID);
return 0;
}
ptmp = X509_PURPOSE_get0(idx);
if (ptmp->trust == X509_TRUST_DEFAULT) {
idx = X509_PURPOSE_get_by_id(def_purpose);
if (idx == -1) {
X509err(X509_F_X509_STORE_CTX_PURPOSE_INHERIT,
X509_R_UNKNOWN_PURPOSE_ID);
return 0;
}
ptmp = X509_PURPOSE_get0(idx);
}
if (!trust)
trust = ptmp->trust;
}
if (trust) {
idx = X509_TRUST_get_by_id(trust);
if (idx == -1) {
X509err(X509_F_X509_STORE_CTX_PURPOSE_INHERIT,
X509_R_UNKNOWN_TRUST_ID);
return 0;
}
}
if (purpose && !ctx->param->purpose)
ctx->param->purpose = purpose;
if (trust && !ctx->param->trust)
ctx->param->trust = trust;
return 1;
}
X509_STORE_CTX *X509_STORE_CTX_new(void)
{
X509_STORE_CTX *ctx = OPENSSL_zalloc(sizeof(*ctx));
if (ctx == NULL) {
X509err(X509_F_X509_STORE_CTX_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
return ctx;
}
void X509_STORE_CTX_free(X509_STORE_CTX *ctx)
{
if (ctx == NULL)
return;
X509_STORE_CTX_cleanup(ctx);
OPENSSL_free(ctx);
}
void X509_STORE_CTX_cleanup(X509_STORE_CTX *ctx)
{
if (ctx->cleanup != NULL) {
ctx->cleanup(ctx);
ctx->cleanup = NULL;
}
if (ctx->param != NULL) {
if (ctx->parent == NULL)
X509_VERIFY_PARAM_free(ctx->param);
ctx->param = NULL;
}
X509_policy_tree_free(ctx->tree);
ctx->tree = NULL;
sk_X509_pop_free(ctx->chain, X509_free);
ctx->chain = NULL;
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_X509_STORE_CTX, ctx, &(ctx->ex_data));
memset(&ctx->ex_data, 0, sizeof(ctx->ex_data));
}
void X509_STORE_CTX_set_depth(X509_STORE_CTX *ctx, int depth)
{
X509_VERIFY_PARAM_set_depth(ctx->param, depth);
}
void X509_STORE_CTX_set_flags(X509_STORE_CTX *ctx, unsigned long flags)
{
X509_VERIFY_PARAM_set_flags(ctx->param, flags);
}
void X509_STORE_CTX_set_time(X509_STORE_CTX *ctx, unsigned long flags,
time_t t)
{
X509_VERIFY_PARAM_set_time(ctx->param, t);
}
X509 *X509_STORE_CTX_get0_cert(X509_STORE_CTX *ctx)
{
return ctx->cert;
}
void X509_STORE_CTX_set_verify_cb(X509_STORE_CTX *ctx,
X509_STORE_CTX_verify_cb verify_cb)
{
ctx->verify_cb = verify_cb;
}
X509_STORE_CTX_verify_cb X509_STORE_CTX_get_verify_cb(X509_STORE_CTX *ctx)
{
return ctx->verify_cb;
}
void X509_STORE_CTX_set_verify(X509_STORE_CTX *ctx,
X509_STORE_CTX_verify_fn verify)
{
ctx->verify = verify;
}
X509_STORE_CTX_verify_fn X509_STORE_CTX_get_verify(X509_STORE_CTX *ctx)
{
return ctx->verify;
}
X509_STORE_CTX_get_issuer_fn X509_STORE_CTX_get_get_issuer(X509_STORE_CTX *ctx)
{
return ctx->get_issuer;
}
X509_STORE_CTX_check_issued_fn X509_STORE_CTX_get_check_issued(X509_STORE_CTX *ctx)
{
return ctx->check_issued;
}
X509_STORE_CTX_check_revocation_fn X509_STORE_CTX_get_check_revocation(X509_STORE_CTX *ctx)
{
return ctx->check_revocation;
}
X509_STORE_CTX_get_crl_fn X509_STORE_CTX_get_get_crl(X509_STORE_CTX *ctx)
{
return ctx->get_crl;
}
X509_STORE_CTX_check_crl_fn X509_STORE_CTX_get_check_crl(X509_STORE_CTX *ctx)
{
return ctx->check_crl;
}
X509_STORE_CTX_cert_crl_fn X509_STORE_CTX_get_cert_crl(X509_STORE_CTX *ctx)
{
return ctx->cert_crl;
}
X509_STORE_CTX_check_policy_fn X509_STORE_CTX_get_check_policy(X509_STORE_CTX *ctx)
{
return ctx->check_policy;
}
X509_STORE_CTX_lookup_certs_fn X509_STORE_CTX_get_lookup_certs(X509_STORE_CTX *ctx)
{
return ctx->lookup_certs;
}
X509_STORE_CTX_lookup_crls_fn X509_STORE_CTX_get_lookup_crls(X509_STORE_CTX *ctx)
{
return ctx->lookup_crls;
}
X509_STORE_CTX_cleanup_fn X509_STORE_CTX_get_cleanup(X509_STORE_CTX *ctx)
{
return ctx->cleanup;
}
X509_POLICY_TREE *X509_STORE_CTX_get0_policy_tree(X509_STORE_CTX *ctx)
{
return ctx->tree;
}
int X509_STORE_CTX_get_explicit_policy(X509_STORE_CTX *ctx)
{
return ctx->explicit_policy;
}
int X509_STORE_CTX_get_num_untrusted(X509_STORE_CTX *ctx)
{
return ctx->num_untrusted;
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
X509_VERIFY_PARAM_free(ctx->param);
ctx->param = param;
}
void X509_STORE_CTX_set0_dane(X509_STORE_CTX *ctx, SSL_DANE *dane)
{
ctx->dane = dane;
}
static unsigned char *dane_i2d(
X509 *cert,
uint8_t selector,
unsigned int *i2dlen)
{
unsigned char *buf = NULL;
int len;
switch (selector) {
case DANETLS_SELECTOR_CERT:
len = i2d_X509(cert, &buf);
break;
case DANETLS_SELECTOR_SPKI:
len = i2d_X509_PUBKEY(X509_get_X509_PUBKEY(cert), &buf);
break;
default:
X509err(X509_F_DANE_I2D, X509_R_BAD_SELECTOR);
return NULL;
}
if (len < 0 || buf == NULL) {
X509err(X509_F_DANE_I2D, ERR_R_MALLOC_FAILURE);
return NULL;
}
*i2dlen = (unsigned int)len;
return buf;
}
static int dane_match(X509_STORE_CTX *ctx, X509 *cert, int depth)
{
SSL_DANE *dane = ctx->dane;
unsigned usage = DANETLS_NONE;
unsigned selector = DANETLS_NONE;
unsigned ordinal = DANETLS_NONE;
unsigned mtype = DANETLS_NONE;
unsigned char *i2dbuf = NULL;
unsigned int i2dlen = 0;
unsigned char mdbuf[EVP_MAX_MD_SIZE];
unsigned char *cmpbuf = NULL;
unsigned int cmplen = 0;
int i;
int recnum;
int matched = 0;
danetls_record *t = NULL;
uint32_t mask;
mask = (depth == 0) ? DANETLS_EE_MASK : DANETLS_TA_MASK;
if (depth >= ctx->num_untrusted)
mask &= DANETLS_PKIX_MASK;
if (dane->mdpth >= 0)
mask &= ~DANETLS_PKIX_MASK;
recnum = (dane->umask & mask) ? sk_danetls_record_num(dane->trecs) : 0;
for (i = 0; matched == 0 && i < recnum; ++i) {
t = sk_danetls_record_value(dane->trecs, i);
if ((DANETLS_USAGE_BIT(t->usage) & mask) == 0)
continue;
if (t->usage != usage) {
usage = t->usage;
mtype = DANETLS_NONE;
ordinal = dane->dctx->mdord[t->mtype];
}
if (t->selector != selector) {
selector = t->selector;
OPENSSL_free(i2dbuf);
i2dbuf = dane_i2d(cert, selector, &i2dlen);
if (i2dbuf == NULL)
return -1;
mtype = DANETLS_NONE;
ordinal = dane->dctx->mdord[t->mtype];
} else if (t->mtype != DANETLS_MATCHING_FULL) {
if (dane->dctx->mdord[t->mtype] < ordinal)
continue;
}
if (t->mtype != mtype) {
const EVP_MD *md = dane->dctx->mdevp[mtype = t->mtype];
cmpbuf = i2dbuf;
cmplen = i2dlen;
if (md != NULL) {
cmpbuf = mdbuf;
if (!EVP_Digest(i2dbuf, i2dlen, cmpbuf, &cmplen, md, 0)) {
matched = -1;
break;
}
}
}
if (cmplen == t->dlen &&
memcmp(cmpbuf, t->data, cmplen) == 0) {
if (DANETLS_USAGE_BIT(usage) & DANETLS_DANE_MASK)
matched = 1;
if (matched || dane->mdpth < 0) {
dane->mdpth = depth;
dane->mtlsa = t;
OPENSSL_free(dane->mcert);
dane->mcert = cert;
X509_up_ref(cert);
}
break;
}
}
OPENSSL_free(i2dbuf);
return matched;
}
static int check_dane_issuer(X509_STORE_CTX *ctx, int depth)
{
SSL_DANE *dane = ctx->dane;
int matched = 0;
X509 *cert;
if (!DANETLS_HAS_TA(dane) || depth == 0)
return X509_TRUST_UNTRUSTED;
cert = sk_X509_value(ctx->chain, depth);
if (cert != NULL && (matched = dane_match(ctx, cert, depth)) < 0)
return X509_TRUST_REJECTED;
if (matched > 0) {
ctx->num_untrusted = depth - 1;
return X509_TRUST_TRUSTED;
}
return X509_TRUST_UNTRUSTED;
}
static int check_dane_pkeys(X509_STORE_CTX *ctx)
{
SSL_DANE *dane = ctx->dane;
danetls_record *t;
int num = ctx->num_untrusted;
X509 *cert = sk_X509_value(ctx->chain, num - 1);
int recnum = sk_danetls_record_num(dane->trecs);
int i;
for (i = 0; i < recnum; ++i) {
t = sk_danetls_record_value(dane->trecs, i);
if (t->usage != DANETLS_USAGE_DANE_TA ||
t->selector != DANETLS_SELECTOR_SPKI ||
t->mtype != DANETLS_MATCHING_FULL ||
X509_verify(cert, t->spki) <= 0)
continue;
X509_free(dane->mcert);
dane->mcert = NULL;
ctx->bare_ta_signed = 1;
dane->mdpth = num - 1;
dane->mtlsa = t;
num = sk_X509_num(ctx->chain);
for (; num > ctx->num_untrusted; --num)
X509_free(sk_X509_pop(ctx->chain));
return X509_TRUST_TRUSTED;
}
return X509_TRUST_UNTRUSTED;
}
static void dane_reset(SSL_DANE *dane)
{
X509_free(dane->mcert);
dane->mcert = NULL;
dane->mtlsa = NULL;
dane->mdpth = -1;
dane->pdpth = -1;
}
static int check_leaf_suiteb(X509_STORE_CTX *ctx, X509 *cert)
{
int err = X509_chain_check_suiteb(NULL, cert, NULL, ctx->param->flags);
if (err == X509_V_OK)
return 1;
return verify_cb_cert(ctx, cert, 0, err);
}
static int dane_verify(X509_STORE_CTX *ctx)
{
X509 *cert = ctx->cert;
SSL_DANE *dane = ctx->dane;
int matched;
int done;
dane_reset(dane);
matched = dane_match(ctx, ctx->cert, 0);
done = matched != 0 || (!DANETLS_HAS_TA(dane) && dane->mdpth < 0);
if (done)
X509_get_pubkey_parameters(NULL, ctx->chain);
if (matched > 0) {
if (!check_leaf_suiteb(ctx, cert))
return 0;
if ((dane->flags & DANE_FLAG_NO_DANE_EE_NAMECHECKS) == 0 &&
!check_id(ctx))
return 0;
ctx->error_depth = 0;
ctx->current_cert = cert;
return ctx->verify_cb(1, ctx);
}
if (matched < 0) {
ctx->error_depth = 0;
ctx->current_cert = cert;
ctx->error = X509_V_ERR_OUT_OF_MEM;
return -1;
}
if (done) {
if (!check_leaf_suiteb(ctx, cert))
return 0;
return verify_cb_cert(ctx, cert, 0, X509_V_ERR_DANE_NO_MATCH);
}
return verify_chain(ctx);
}
static int get_issuer(X509 **issuer, X509_STORE_CTX *ctx, X509 *cert)
{
STACK_OF(X509) *saved_chain = ctx->chain;
int ok;
ctx->chain = NULL;
ok = ctx->get_issuer(issuer, ctx, cert);
ctx->chain = saved_chain;
return ok;
}
static int build_chain(X509_STORE_CTX *ctx)
{
SSL_DANE *dane = ctx->dane;
int num = sk_X509_num(ctx->chain);
X509 *cert = sk_X509_value(ctx->chain, num - 1);
int ss = cert_self_signed(cert);
STACK_OF(X509) *sktmp = NULL;
unsigned int search;
int may_trusted = 0;
int may_alternate = 0;
int trust = X509_TRUST_UNTRUSTED;
int alt_untrusted = 0;
int depth;
int ok = 0;
int i;
OPENSSL_assert(num == 1 && ctx->num_untrusted == num);
#define S_DOUNTRUSTED (1 << 0)
#define S_DOTRUSTED (1 << 1)
#define S_DOALTERNATE (1 << 2)
search = (ctx->untrusted != NULL) ? S_DOUNTRUSTED : 0;
if (DANETLS_HAS_PKIX(dane) || !DANETLS_HAS_DANE(dane)) {
if (search == 0 || ctx->param->flags & X509_V_FLAG_TRUSTED_FIRST)
search |= S_DOTRUSTED;
else if (!(ctx->param->flags & X509_V_FLAG_NO_ALT_CHAINS))
may_alternate = 1;
may_trusted = 1;
}
if (ctx->untrusted && (sktmp = sk_X509_dup(ctx->untrusted)) == NULL) {
X509err(X509_F_BUILD_CHAIN, ERR_R_MALLOC_FAILURE);
ctx->error = X509_V_ERR_OUT_OF_MEM;
return 0;
}
if (DANETLS_ENABLED(dane) && dane->certs != NULL) {
if (sktmp == NULL && (sktmp = sk_X509_new_null()) == NULL) {
X509err(X509_F_BUILD_CHAIN, ERR_R_MALLOC_FAILURE);
ctx->error = X509_V_ERR_OUT_OF_MEM;
return 0;
}
for (i = 0; i < sk_X509_num(dane->certs); ++i) {
if (!sk_X509_push(sktmp, sk_X509_value(dane->certs, i))) {
sk_X509_free(sktmp);
X509err(X509_F_BUILD_CHAIN, ERR_R_MALLOC_FAILURE);
ctx->error = X509_V_ERR_OUT_OF_MEM;
return 0;
}
}
}
if (ctx->param->depth > INT_MAX/2)
ctx->param->depth = INT_MAX/2;
depth = ctx->param->depth + 1;
while (search != 0) {
X509 *x;
X509 *xtmp = NULL;
if ((search & S_DOTRUSTED) != 0) {
i = num = sk_X509_num(ctx->chain);
if ((search & S_DOALTERNATE) != 0) {
i = alt_untrusted;
}
x = sk_X509_value(ctx->chain, i-1);
ok = (depth < num) ? 0 : get_issuer(&xtmp, ctx, x);
if (ok < 0) {
trust = X509_TRUST_REJECTED;
ctx->error = X509_V_ERR_STORE_LOOKUP;
search = 0;
continue;
}
if (ok > 0) {
if ((search & S_DOALTERNATE) != 0) {
OPENSSL_assert(num > i && i > 0 && ss == 0);
search &= ~S_DOALTERNATE;
for (; num > i; --num)
X509_free(sk_X509_pop(ctx->chain));
ctx->num_untrusted = num;
if (DANETLS_ENABLED(dane) &&
dane->mdpth >= ctx->num_untrusted) {
dane->mdpth = -1;
X509_free(dane->mcert);
dane->mcert = NULL;
}
if (DANETLS_ENABLED(dane) &&
dane->pdpth >= ctx->num_untrusted)
dane->pdpth = -1;
}
if (ss == 0) {
if (!sk_X509_push(ctx->chain, x = xtmp)) {
X509_free(xtmp);
X509err(X509_F_BUILD_CHAIN, ERR_R_MALLOC_FAILURE);
trust = X509_TRUST_REJECTED;
ctx->error = X509_V_ERR_OUT_OF_MEM;
search = 0;
continue;
}
ss = cert_self_signed(x);
} else if (num == ctx->num_untrusted) {
if (X509_cmp(x, xtmp) != 0) {
X509_free(xtmp);
ok = 0;
} else {
X509_free(x);
ctx->num_untrusted = --num;
(void) sk_X509_set(ctx->chain, num, x = xtmp);
}
}
if (ok) {
OPENSSL_assert(ctx->num_untrusted <= num);
search &= ~S_DOUNTRUSTED;
switch (trust = check_trust(ctx, num)) {
case X509_TRUST_TRUSTED:
case X509_TRUST_REJECTED:
search = 0;
continue;
}
if (ss == 0)
continue;
}
}
if ((search & S_DOUNTRUSTED) == 0) {
if ((search & S_DOALTERNATE) != 0 && --alt_untrusted > 0)
continue;
if (!may_alternate || (search & S_DOALTERNATE) != 0 ||
ctx->num_untrusted < 2)
break;
search |= S_DOALTERNATE;
alt_untrusted = ctx->num_untrusted - 1;
ss = 0;
}
}
if ((search & S_DOUNTRUSTED) != 0) {
num = sk_X509_num(ctx->chain);
OPENSSL_assert(num == ctx->num_untrusted);
x = sk_X509_value(ctx->chain, num-1);
xtmp = (ss || depth < num) ? NULL : find_issuer(ctx, sktmp, x);
if (xtmp == NULL) {
search &= ~S_DOUNTRUSTED;
if (may_trusted)
search |= S_DOTRUSTED;
continue;
}
(void) sk_X509_delete_ptr(sktmp, xtmp);
if (!sk_X509_push(ctx->chain, xtmp)) {
X509err(X509_F_BUILD_CHAIN, ERR_R_MALLOC_FAILURE);
trust = X509_TRUST_REJECTED;
ctx->error = X509_V_ERR_OUT_OF_MEM;
search = 0;
continue;
}
X509_up_ref(x = xtmp);
++ctx->num_untrusted;
ss = cert_self_signed(xtmp);
switch (trust = check_dane_issuer(ctx, ctx->num_untrusted - 1)) {
case X509_TRUST_TRUSTED:
case X509_TRUST_REJECTED:
search = 0;
continue;
}
}
}
sk_X509_free(sktmp);
num = sk_X509_num(ctx->chain);
if (num <= depth) {
if (trust == X509_TRUST_UNTRUSTED && DANETLS_HAS_DANE_TA(dane))
trust = check_dane_pkeys(ctx);
if (trust == X509_TRUST_UNTRUSTED && num == ctx->num_untrusted)
trust = check_trust(ctx, num);
}
switch (trust) {
case X509_TRUST_TRUSTED:
return 1;
case X509_TRUST_REJECTED:
return 0;
case X509_TRUST_UNTRUSTED:
default:
num = sk_X509_num(ctx->chain);
if (num > depth)
return verify_cb_cert(ctx, NULL, num-1,
X509_V_ERR_CERT_CHAIN_TOO_LONG);
if (DANETLS_ENABLED(dane) &&
(!DANETLS_HAS_PKIX(dane) || dane->pdpth >= 0))
return verify_cb_cert(ctx, NULL, num-1, X509_V_ERR_DANE_NO_MATCH);
if (ss && sk_X509_num(ctx->chain) == 1)
return verify_cb_cert(ctx, NULL, num-1,
X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT);
if (ss)
return verify_cb_cert(ctx, NULL, num-1,
X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN);
if (ctx->num_untrusted < num)
return verify_cb_cert(ctx, NULL, num-1,
X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT);
return verify_cb_cert(ctx, NULL, num-1,
X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY);
}
}
static int check_key_level(X509_STORE_CTX *ctx, X509 *cert)
{
EVP_PKEY *pkey = X509_get0_pubkey(cert);
int level = ctx->param->auth_level;
if (pkey == NULL)
return 0;
if (level <= 0)
return 1;
if (level > NUM_AUTH_LEVELS)
level = NUM_AUTH_LEVELS;
return EVP_PKEY_security_bits(pkey) >= minbits_table[level - 1];
}
static int check_sig_level(X509_STORE_CTX *ctx, X509 *cert)
{
int nid = X509_get_signature_nid(cert);
int mdnid = NID_undef;
int secbits = -1;
int level = ctx->param->auth_level;
if (level <= 0)
return 1;
if (level > NUM_AUTH_LEVELS)
level = NUM_AUTH_LEVELS;
if (nid && OBJ_find_sigid_algs(nid, &mdnid, NULL)) {
const EVP_MD *md;
if (mdnid != NID_undef && (md = EVP_get_digestbynid(mdnid)) != NULL)
secbits = EVP_MD_size(md) * 4;
}
return secbits >= minbits_table[level - 1];
}
