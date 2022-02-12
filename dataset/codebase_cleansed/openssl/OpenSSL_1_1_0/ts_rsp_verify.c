static ESS_SIGNING_CERT *ess_get_signing_cert(PKCS7_SIGNER_INFO *si)
{
ASN1_TYPE *attr;
const unsigned char *p;
attr = PKCS7_get_signed_attribute(si, NID_id_smime_aa_signingCertificate);
if (!attr)
return NULL;
p = attr->value.sequence->data;
return d2i_ESS_SIGNING_CERT(NULL, &p, attr->value.sequence->length);
}
static int ts_issuer_serial_cmp(ESS_ISSUER_SERIAL *is, X509 *cert)
{
GENERAL_NAME *issuer;
if (!is || !cert || sk_GENERAL_NAME_num(is->issuer) != 1)
return -1;
issuer = sk_GENERAL_NAME_value(is->issuer, 0);
if (issuer->type != GEN_DIRNAME
|| X509_NAME_cmp(issuer->d.dirn, X509_get_issuer_name(cert)))
return -1;
if (ASN1_INTEGER_cmp(is->serial, X509_get_serialNumber(cert)))
return -1;
return 0;
}
int TS_RESP_verify_response(TS_VERIFY_CTX *ctx, TS_RESP *response)
{
PKCS7 *token = response->token;
TS_TST_INFO *tst_info = response->tst_info;
int ret = 0;
if (!ts_check_status_info(response))
goto err;
if (!int_ts_RESP_verify_token(ctx, token, tst_info))
goto err;
ret = 1;
err:
return ret;
}
int TS_RESP_verify_token(TS_VERIFY_CTX *ctx, PKCS7 *token)
{
TS_TST_INFO *tst_info = PKCS7_to_TS_TST_INFO(token);
int ret = 0;
if (tst_info) {
ret = int_ts_RESP_verify_token(ctx, token, tst_info);
TS_TST_INFO_free(tst_info);
}
return ret;
}
static int int_ts_RESP_verify_token(TS_VERIFY_CTX *ctx,
PKCS7 *token, TS_TST_INFO *tst_info)
{
X509 *signer = NULL;
GENERAL_NAME *tsa_name = tst_info->tsa;
X509_ALGOR *md_alg = NULL;
unsigned char *imprint = NULL;
unsigned imprint_len = 0;
int ret = 0;
int flags = ctx->flags;
if (((flags & TS_VFY_SIGNER) && tsa_name != NULL)
|| (flags & TS_VFY_TSA_NAME)) {
flags |= TS_VFY_SIGNATURE;
}
if ((flags & TS_VFY_SIGNATURE)
&& !TS_RESP_verify_signature(token, ctx->certs, ctx->store, &signer))
goto err;
if ((flags & TS_VFY_VERSION)
&& TS_TST_INFO_get_version(tst_info) != 1) {
TSerr(TS_F_INT_TS_RESP_VERIFY_TOKEN, TS_R_UNSUPPORTED_VERSION);
goto err;
}
if ((flags & TS_VFY_POLICY)
&& !ts_check_policy(ctx->policy, tst_info))
goto err;
if ((flags & TS_VFY_IMPRINT)
&& !ts_check_imprints(ctx->md_alg, ctx->imprint, ctx->imprint_len,
tst_info))
goto err;
if ((flags & TS_VFY_DATA)
&& (!ts_compute_imprint(ctx->data, tst_info,
&md_alg, &imprint, &imprint_len)
|| !ts_check_imprints(md_alg, imprint, imprint_len, tst_info)))
goto err;
if ((flags & TS_VFY_NONCE)
&& !ts_check_nonces(ctx->nonce, tst_info))
goto err;
if ((flags & TS_VFY_SIGNER)
&& tsa_name && !ts_check_signer_name(tsa_name, signer)) {
TSerr(TS_F_INT_TS_RESP_VERIFY_TOKEN, TS_R_TSA_NAME_MISMATCH);
goto err;
}
if ((flags & TS_VFY_TSA_NAME)
&& !ts_check_signer_name(ctx->tsa_name, signer)) {
TSerr(TS_F_INT_TS_RESP_VERIFY_TOKEN, TS_R_TSA_UNTRUSTED);
goto err;
}
ret = 1;
err:
X509_free(signer);
X509_ALGOR_free(md_alg);
OPENSSL_free(imprint);
return ret;
}
static int ts_check_status_info(TS_RESP *response)
{
TS_STATUS_INFO *info = response->status_info;
long status = ASN1_INTEGER_get(info->status);
const char *status_text = NULL;
char *embedded_status_text = NULL;
char failure_text[TS_STATUS_BUF_SIZE] = "";
if (status == 0 || status == 1)
return 1;
if (0 <= status && status < (long) OSSL_NELEM(ts_status_text))
status_text = ts_status_text[status];
else
status_text = "unknown code";
if (sk_ASN1_UTF8STRING_num(info->text) > 0
&& (embedded_status_text = ts_get_status_text(info->text)) == NULL)
return 0;
if (info->failure_info) {
int i;
int first = 1;
for (i = 0; i < (int)OSSL_NELEM(ts_failure_info); ++i) {
if (ASN1_BIT_STRING_get_bit(info->failure_info,
ts_failure_info[i].code)) {
if (!first)
strcat(failure_text, ",");
else
first = 0;
strcat(failure_text, ts_failure_info[i].text);
}
}
}
if (failure_text[0] == '\0')
strcpy(failure_text, "unspecified");
TSerr(TS_F_TS_CHECK_STATUS_INFO, TS_R_NO_TIME_STAMP_TOKEN);
ERR_add_error_data(6,
"status code: ", status_text,
", status text: ", embedded_status_text ?
embedded_status_text : "unspecified",
", failure codes: ", failure_text);
OPENSSL_free(embedded_status_text);
return 0;
}
static int ts_check_policy(const ASN1_OBJECT *req_oid,
const TS_TST_INFO *tst_info)
{
const ASN1_OBJECT *resp_oid = tst_info->policy_id;
if (OBJ_cmp(req_oid, resp_oid) != 0) {
TSerr(TS_F_TS_CHECK_POLICY, TS_R_POLICY_MISMATCH);
return 0;
}
return 1;
}
static int ts_compute_imprint(BIO *data, TS_TST_INFO *tst_info,
X509_ALGOR **md_alg,
unsigned char **imprint, unsigned *imprint_len)
{
TS_MSG_IMPRINT *msg_imprint = tst_info->msg_imprint;
X509_ALGOR *md_alg_resp = msg_imprint->hash_algo;
const EVP_MD *md;
EVP_MD_CTX *md_ctx = NULL;
unsigned char buffer[4096];
int length;
*md_alg = NULL;
*imprint = NULL;
if ((*md_alg = X509_ALGOR_dup(md_alg_resp)) == NULL)
goto err;
if ((md = EVP_get_digestbyobj((*md_alg)->algorithm)) == NULL) {
TSerr(TS_F_TS_COMPUTE_IMPRINT, TS_R_UNSUPPORTED_MD_ALGORITHM);
goto err;
}
length = EVP_MD_size(md);
if (length < 0)
goto err;
*imprint_len = length;
if ((*imprint = OPENSSL_malloc(*imprint_len)) == NULL) {
TSerr(TS_F_TS_COMPUTE_IMPRINT, ERR_R_MALLOC_FAILURE);
goto err;
}
md_ctx = EVP_MD_CTX_new();
if (md_ctx == NULL) {
TSerr(TS_F_TS_COMPUTE_IMPRINT, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!EVP_DigestInit(md_ctx, md))
goto err;
while ((length = BIO_read(data, buffer, sizeof(buffer))) > 0) {
if (!EVP_DigestUpdate(md_ctx, buffer, length))
goto err;
}
if (!EVP_DigestFinal(md_ctx, *imprint, NULL))
goto err;
EVP_MD_CTX_free(md_ctx);
return 1;
err:
EVP_MD_CTX_free(md_ctx);
X509_ALGOR_free(*md_alg);
OPENSSL_free(*imprint);
*imprint_len = 0;
*imprint = 0;
return 0;
}
static int ts_check_imprints(X509_ALGOR *algor_a,
const unsigned char *imprint_a, unsigned len_a,
TS_TST_INFO *tst_info)
{
TS_MSG_IMPRINT *b = tst_info->msg_imprint;
X509_ALGOR *algor_b = b->hash_algo;
int ret = 0;
if (algor_a) {
if (OBJ_cmp(algor_a->algorithm, algor_b->algorithm))
goto err;
if ((algor_a->parameter
&& ASN1_TYPE_get(algor_a->parameter) != V_ASN1_NULL)
|| (algor_b->parameter
&& ASN1_TYPE_get(algor_b->parameter) != V_ASN1_NULL))
goto err;
}
ret = len_a == (unsigned)ASN1_STRING_length(b->hashed_msg) &&
memcmp(imprint_a, ASN1_STRING_get0_data(b->hashed_msg), len_a) == 0;
err:
if (!ret)
TSerr(TS_F_TS_CHECK_IMPRINTS, TS_R_MESSAGE_IMPRINT_MISMATCH);
return ret;
}
static int ts_check_nonces(const ASN1_INTEGER *a, TS_TST_INFO *tst_info)
{
const ASN1_INTEGER *b = tst_info->nonce;
if (!b) {
TSerr(TS_F_TS_CHECK_NONCES, TS_R_NONCE_NOT_RETURNED);
return 0;
}
if (ASN1_INTEGER_cmp(a, b) != 0) {
TSerr(TS_F_TS_CHECK_NONCES, TS_R_NONCE_MISMATCH);
return 0;
}
return 1;
}
static int ts_check_signer_name(GENERAL_NAME *tsa_name, X509 *signer)
{
STACK_OF(GENERAL_NAME) *gen_names = NULL;
int idx = -1;
int found = 0;
if (tsa_name->type == GEN_DIRNAME
&& X509_name_cmp(tsa_name->d.dirn, X509_get_subject_name(signer)) == 0)
return 1;
gen_names = X509_get_ext_d2i(signer, NID_subject_alt_name, NULL, &idx);
while (gen_names != NULL) {
found = ts_find_name(gen_names, tsa_name) >= 0;
if (found)
break;
GENERAL_NAMES_free(gen_names);
gen_names = X509_get_ext_d2i(signer, NID_subject_alt_name, NULL, &idx);
}
GENERAL_NAMES_free(gen_names);
return found;
}
