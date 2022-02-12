static int sct_ctx_update(EVP_MD_CTX *ctx, const SCT_CTX *sctx, const SCT *sct)
{
unsigned char tmpbuf[12];
unsigned char *p, *der;
size_t derlen;
if (sct->entry_type == CT_LOG_ENTRY_TYPE_NOT_SET)
return 0;
if (sct->entry_type == CT_LOG_ENTRY_TYPE_PRECERT && sctx->ihash == NULL)
return 0;
p = tmpbuf;
*p++ = sct->version;
*p++ = SIGNATURE_TYPE_CERT_TIMESTAMP;
l2n8(sct->timestamp, p);
s2n(sct->entry_type, p);
if (!EVP_DigestUpdate(ctx, tmpbuf, p - tmpbuf))
return 0;
if (sct->entry_type == CT_LOG_ENTRY_TYPE_X509) {
der = sctx->certder;
derlen = sctx->certderlen;
} else {
if (!EVP_DigestUpdate(ctx, sctx->ihash, sctx->ihashlen))
return 0;
der = sctx->preder;
derlen = sctx->prederlen;
}
if (der == NULL)
return 0;
p = tmpbuf;
l2n3(derlen, p);
if (!EVP_DigestUpdate(ctx, tmpbuf, 3))
return 0;
if (!EVP_DigestUpdate(ctx, der, derlen))
return 0;
p = tmpbuf;
s2n(sct->ext_len, p);
if (!EVP_DigestUpdate(ctx, tmpbuf, 2))
return 0;
if (sct->ext_len && !EVP_DigestUpdate(ctx, sct->ext, sct->ext_len))
return 0;
return 1;
}
int SCT_CTX_verify(const SCT_CTX *sctx, const SCT *sct)
{
EVP_MD_CTX *ctx = NULL;
int ret = 0;
if (!SCT_is_complete(sct) || sctx->pkey == NULL ||
sct->entry_type == CT_LOG_ENTRY_TYPE_NOT_SET ||
(sct->entry_type == CT_LOG_ENTRY_TYPE_PRECERT && sctx->ihash == NULL)) {
CTerr(CT_F_SCT_CTX_VERIFY, CT_R_SCT_NOT_SET);
return 0;
}
if (sct->version != SCT_VERSION_V1) {
CTerr(CT_F_SCT_CTX_VERIFY, CT_R_SCT_UNSUPPORTED_VERSION);
return 0;
}
if (sct->log_id_len != sctx->pkeyhashlen ||
memcmp(sct->log_id, sctx->pkeyhash, sctx->pkeyhashlen) != 0) {
CTerr(CT_F_SCT_CTX_VERIFY, CT_R_SCT_LOG_ID_MISMATCH);
return 0;
}
ctx = EVP_MD_CTX_new();
if (ctx == NULL)
goto end;
if (!EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, sctx->pkey))
goto end;
if (!sct_ctx_update(ctx, sctx, sct))
goto end;
ret = EVP_DigestVerifyFinal(ctx, sct->sig, sct->sig_len);
if (ret == 0)
CTerr(CT_F_SCT_CTX_VERIFY, CT_R_SCT_INVALID_SIGNATURE);
end:
EVP_MD_CTX_free(ctx);
return ret;
}
