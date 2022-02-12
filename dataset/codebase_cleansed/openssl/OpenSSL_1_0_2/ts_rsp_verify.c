static ESS_SIGNING_CERT *ESS_get_signing_cert(PKCS7_SIGNER_INFO *si)
{
ASN1_TYPE *attr;
const unsigned char *p;
attr = PKCS7_get_signed_attribute(si, NID_id_smime_aa_signingCertificate);
if (!attr)
return NULL;
p = attr->value.sequence->data;
return d2i_ESS_SIGNING_CERT(NULL, &p, attr->value.sequence->length);
}
static int TS_issuer_serial_cmp(ESS_ISSUER_SERIAL *is, X509_CINF *cinfo)
{
GENERAL_NAME *issuer;
if (!is || !cinfo || sk_GENERAL_NAME_num(is->issuer) != 1)
return -1;
issuer = sk_GENERAL_NAME_value(is->issuer, 0);
if (issuer->type != GEN_DIRNAME
|| X509_NAME_cmp(issuer->d.dirn, cinfo->issuer))
return -1;
if (ASN1_INTEGER_cmp(is->serial, cinfo->serialNumber))
return -1;
return 0;
}
int TS_RESP_verify_response(TS_VERIFY_CTX *ctx, TS_RESP *response)
{
PKCS7 *token = TS_RESP_get_token(response);
TS_TST_INFO *tst_info = TS_RESP_get_tst_info(response);
int ret = 0;
if (!TS_check_status_info(response))
goto err;
if (!int_TS_RESP_verify_token(ctx, token, tst_info))
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
ret = int_TS_RESP_verify_token(ctx, token, tst_info);
TS_TST_INFO_free(tst_info);
}
return ret;
}
static int int_TS_RESP_verify_token(TS_VERIFY_CTX *ctx,
PKCS7 *token, TS_TST_INFO *tst_info)
{
X509 *signer = NULL;
GENERAL_NAME *tsa_name = TS_TST_INFO_get_tsa(tst_info);
X509_ALGOR *md_alg = NULL;
unsigned char *imprint = NULL;
unsigned imprint_len = 0;
int ret = 0;
if ((ctx->flags & TS_VFY_SIGNATURE)
&& !TS_RESP_verify_signature(token, ctx->certs, ctx->store, &signer))
goto err;
if ((ctx->flags & TS_VFY_VERSION)
&& TS_TST_INFO_get_version(tst_info) != 1) {
TSerr(TS_F_INT_TS_RESP_VERIFY_TOKEN, TS_R_UNSUPPORTED_VERSION);
goto err;
}
if ((ctx->flags & TS_VFY_POLICY)
&& !TS_check_policy(ctx->policy, tst_info))
goto err;
if ((ctx->flags & TS_VFY_IMPRINT)
&& !TS_check_imprints(ctx->md_alg, ctx->imprint, ctx->imprint_len,
tst_info))
goto err;
if ((ctx->flags & TS_VFY_DATA)
&& (!TS_compute_imprint(ctx->data, tst_info,
&md_alg, &imprint, &imprint_len)
|| !TS_check_imprints(md_alg, imprint, imprint_len, tst_info)))
goto err;
if ((ctx->flags & TS_VFY_NONCE)
&& !TS_check_nonces(ctx->nonce, tst_info))
goto err;
if ((ctx->flags & TS_VFY_SIGNER)
&& tsa_name && !TS_check_signer_name(tsa_name, signer)) {
TSerr(TS_F_INT_TS_RESP_VERIFY_TOKEN, TS_R_TSA_NAME_MISMATCH);
goto err;
}
if ((ctx->flags & TS_VFY_TSA_NAME)
&& !TS_check_signer_name(ctx->tsa_name, signer)) {
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
static int TS_check_status_info(TS_RESP *response)
{
TS_STATUS_INFO *info = TS_RESP_get_status_info(response);
long status = ASN1_INTEGER_get(info->status);
const char *status_text = NULL;
char *embedded_status_text = NULL;
char failure_text[TS_STATUS_BUF_SIZE] = "";
if (status == 0 || status == 1)
return 1;
if (0 <= status && status < (long)TS_STATUS_TEXT_SIZE)
status_text = TS_status_text[status];
else
status_text = "unknown code";
if (sk_ASN1_UTF8STRING_num(info->text) > 0
&& !(embedded_status_text = TS_get_status_text(info->text)))
return 0;
if (info->failure_info) {
int i;
int first = 1;
for (i = 0; i < (int)TS_FAILURE_INFO_SIZE; ++i) {
if (ASN1_BIT_STRING_get_bit(info->failure_info,
TS_failure_info[i].code)) {
if (!first)
strcpy(failure_text, ",");
else
first = 0;
strcat(failure_text, TS_failure_info[i].text);
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
static int TS_check_policy(ASN1_OBJECT *req_oid, TS_TST_INFO *tst_info)
{
ASN1_OBJECT *resp_oid = TS_TST_INFO_get_policy_id(tst_info);
if (OBJ_cmp(req_oid, resp_oid) != 0) {
TSerr(TS_F_TS_CHECK_POLICY, TS_R_POLICY_MISMATCH);
return 0;
}
return 1;
}
static int TS_compute_imprint(BIO *data, TS_TST_INFO *tst_info,
X509_ALGOR **md_alg,
unsigned char **imprint, unsigned *imprint_len)
{
TS_MSG_IMPRINT *msg_imprint = TS_TST_INFO_get_msg_imprint(tst_info);
X509_ALGOR *md_alg_resp = TS_MSG_IMPRINT_get_algo(msg_imprint);
const EVP_MD *md;
EVP_MD_CTX md_ctx;
unsigned char buffer[4096];
int length;
*md_alg = NULL;
*imprint = NULL;
if (!(*md_alg = X509_ALGOR_dup(md_alg_resp)))
goto err;
if (!(md = EVP_get_digestbyobj((*md_alg)->algorithm))) {
TSerr(TS_F_TS_COMPUTE_IMPRINT, TS_R_UNSUPPORTED_MD_ALGORITHM);
goto err;
}
length = EVP_MD_size(md);
if (length < 0)
goto err;
*imprint_len = length;
if (!(*imprint = OPENSSL_malloc(*imprint_len))) {
TSerr(TS_F_TS_COMPUTE_IMPRINT, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!EVP_DigestInit(&md_ctx, md))
goto err;
while ((length = BIO_read(data, buffer, sizeof(buffer))) > 0) {
if (!EVP_DigestUpdate(&md_ctx, buffer, length))
goto err;
}
if (!EVP_DigestFinal(&md_ctx, *imprint, NULL))
goto err;
return 1;
err:
X509_ALGOR_free(*md_alg);
OPENSSL_free(*imprint);
*imprint_len = 0;
*imprint = 0;
return 0;
}
static int TS_check_imprints(X509_ALGOR *algor_a,
unsigned char *imprint_a, unsigned len_a,
TS_TST_INFO *tst_info)
{
TS_MSG_IMPRINT *b = TS_TST_INFO_get_msg_imprint(tst_info);
X509_ALGOR *algor_b = TS_MSG_IMPRINT_get_algo(b);
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
memcmp(imprint_a, ASN1_STRING_data(b->hashed_msg), len_a) == 0;
err:
if (!ret)
TSerr(TS_F_TS_CHECK_IMPRINTS, TS_R_MESSAGE_IMPRINT_MISMATCH);
return ret;
}
static int TS_check_nonces(const ASN1_INTEGER *a, TS_TST_INFO *tst_info)
{
const ASN1_INTEGER *b = TS_TST_INFO_get_nonce(tst_info);
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
static int TS_check_signer_name(GENERAL_NAME *tsa_name, X509 *signer)
{
STACK_OF(GENERAL_NAME) *gen_names = NULL;
int idx = -1;
int found = 0;
if (tsa_name->type == GEN_DIRNAME
&& X509_name_cmp(tsa_name->d.dirn, signer->cert_info->subject) == 0)
return 1;
gen_names = X509_get_ext_d2i(signer, NID_subject_alt_name, NULL, &idx);
while (gen_names != NULL
&& !(found = TS_find_name(gen_names, tsa_name) >= 0)) {
GENERAL_NAMES_free(gen_names);
gen_names = X509_get_ext_d2i(signer, NID_subject_alt_name,
NULL, &idx);
}
if (gen_names)
GENERAL_NAMES_free(gen_names);
return found;
}
