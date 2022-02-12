char *i2s_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method, ASN1_OCTET_STRING *oct)
{
return hex_to_string(oct->data, oct->length);
}
ASN1_OCTET_STRING *s2i_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,
X509V3_CTX *ctx, char *str)
{
ASN1_OCTET_STRING *oct;
long length;
if (!(oct = M_ASN1_OCTET_STRING_new())) {
X509V3err(X509V3_F_S2I_ASN1_OCTET_STRING, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (!(oct->data = string_to_hex(str, &length))) {
M_ASN1_OCTET_STRING_free(oct);
return NULL;
}
oct->length = length;
return oct;
}
static ASN1_OCTET_STRING *s2i_skey_id(X509V3_EXT_METHOD *method,
X509V3_CTX *ctx, char *str)
{
ASN1_OCTET_STRING *oct;
ASN1_BIT_STRING *pk;
unsigned char pkey_dig[EVP_MAX_MD_SIZE];
unsigned int diglen;
if (strcmp(str, "hash"))
return s2i_ASN1_OCTET_STRING(method, ctx, str);
if (!(oct = M_ASN1_OCTET_STRING_new())) {
X509V3err(X509V3_F_S2I_SKEY_ID, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (ctx && (ctx->flags == CTX_TEST))
return oct;
if (!ctx || (!ctx->subject_req && !ctx->subject_cert)) {
X509V3err(X509V3_F_S2I_SKEY_ID, X509V3_R_NO_PUBLIC_KEY);
goto err;
}
if (ctx->subject_req)
pk = ctx->subject_req->req_info->pubkey->public_key;
else
pk = ctx->subject_cert->cert_info->key->public_key;
if (!pk) {
X509V3err(X509V3_F_S2I_SKEY_ID, X509V3_R_NO_PUBLIC_KEY);
goto err;
}
if (!EVP_Digest
(pk->data, pk->length, pkey_dig, &diglen, EVP_sha1(), NULL))
goto err;
if (!M_ASN1_OCTET_STRING_set(oct, pkey_dig, diglen)) {
X509V3err(X509V3_F_S2I_SKEY_ID, ERR_R_MALLOC_FAILURE);
goto err;
}
return oct;
err:
M_ASN1_OCTET_STRING_free(oct);
return NULL;
}
