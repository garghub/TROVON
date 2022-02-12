int o2i_SCT_signature(SCT *sct, const unsigned char **in, size_t len)
{
size_t siglen;
size_t len_remaining = len;
const unsigned char *p;
if (sct->version != SCT_VERSION_V1) {
CTerr(CT_F_O2I_SCT_SIGNATURE, CT_R_UNSUPPORTED_VERSION);
return -1;
}
if (len <= 4) {
CTerr(CT_F_O2I_SCT_SIGNATURE, CT_R_SCT_INVALID_SIGNATURE);
return -1;
}
p = *in;
sct->hash_alg = *p++;
sct->sig_alg = *p++;
if (SCT_get_signature_nid(sct) == NID_undef) {
CTerr(CT_F_O2I_SCT_SIGNATURE, CT_R_SCT_INVALID_SIGNATURE);
return -1;
}
n2s(p, siglen);
len_remaining -= (p - *in);
if (siglen > len_remaining) {
CTerr(CT_F_O2I_SCT_SIGNATURE, CT_R_SCT_INVALID_SIGNATURE);
return -1;
}
if (SCT_set1_signature(sct, p, siglen) != 1)
return -1;
len_remaining -= siglen;
*in = p + siglen;
return len - len_remaining;
}
SCT *o2i_SCT(SCT **psct, const unsigned char **in, size_t len)
{
SCT *sct = NULL;
const unsigned char *p;
if (len == 0 || len > MAX_SCT_SIZE) {
CTerr(CT_F_O2I_SCT, CT_R_SCT_INVALID);
goto err;
}
if ((sct = SCT_new()) == NULL)
goto err;
p = *in;
sct->version = *p;
if (sct->version == SCT_VERSION_V1) {
int sig_len;
size_t len2;
if (len < 43) {
CTerr(CT_F_O2I_SCT, CT_R_SCT_INVALID);
goto err;
}
len -= 43;
p++;
sct->log_id = BUF_memdup(p, CT_V1_HASHLEN);
if (sct->log_id == NULL)
goto err;
sct->log_id_len = CT_V1_HASHLEN;
p += CT_V1_HASHLEN;
n2l8(p, sct->timestamp);
n2s(p, len2);
if (len < len2) {
CTerr(CT_F_O2I_SCT, CT_R_SCT_INVALID);
goto err;
}
if (len2 > 0) {
sct->ext = BUF_memdup(p, len2);
if (sct->ext == NULL)
goto err;
}
sct->ext_len = len2;
p += len2;
len -= len2;
sig_len = o2i_SCT_signature(sct, &p, len);
if (sig_len <= 0) {
CTerr(CT_F_O2I_SCT, CT_R_SCT_INVALID);
goto err;
}
len -= sig_len;
*in = p + len;
} else {
sct->sct = BUF_memdup(p, len);
if (sct->sct == NULL)
goto err;
sct->sct_len = len;
*in = p + len;
}
if (psct != NULL) {
SCT_free(*psct);
*psct = sct;
}
return sct;
err:
SCT_free(sct);
return NULL;
}
int i2o_SCT_signature(const SCT *sct, unsigned char **out)
{
size_t len;
unsigned char *p = NULL;
if (!SCT_signature_is_complete(sct)) {
CTerr(CT_F_I2O_SCT_SIGNATURE, CT_R_SCT_INVALID_SIGNATURE);
goto err;
}
if (sct->version != SCT_VERSION_V1) {
CTerr(CT_F_I2O_SCT_SIGNATURE, CT_R_UNSUPPORTED_VERSION);
goto err;
}
len = 4 + sct->sig_len;
if (out != NULL) {
if (*out != NULL) {
p = *out;
*out += len;
} else {
p = OPENSSL_malloc(len);
if (p == NULL) {
CTerr(CT_F_I2O_SCT_SIGNATURE, ERR_R_MALLOC_FAILURE);
goto err;
}
*out = p;
}
*p++ = sct->hash_alg;
*p++ = sct->sig_alg;
s2n(sct->sig_len, p);
memcpy(p, sct->sig, sct->sig_len);
}
return len;
err:
OPENSSL_free(p);
return -1;
}
int i2o_SCT(const SCT *sct, unsigned char **out)
{
size_t len;
unsigned char *p = NULL;
if (!SCT_is_complete(sct)) {
CTerr(CT_F_I2O_SCT, CT_R_SCT_NOT_SET);
goto err;
}
if (sct->version == SCT_VERSION_V1)
len = 43 + sct->ext_len + 4 + sct->sig_len;
else
len = sct->sct_len;
if (out == NULL)
return len;
if (*out != NULL) {
p = *out;
*out += len;
} else {
p = OPENSSL_malloc(len);
if (p == NULL) {
CTerr(CT_F_I2O_SCT, ERR_R_MALLOC_FAILURE);
goto err;
}
*out = p;
}
if (sct->version == SCT_VERSION_V1) {
*p++ = sct->version;
memcpy(p, sct->log_id, CT_V1_HASHLEN);
p += CT_V1_HASHLEN;
l2n8(sct->timestamp, p);
s2n(sct->ext_len, p);
if (sct->ext_len > 0) {
memcpy(p, sct->ext, sct->ext_len);
p += sct->ext_len;
}
if (i2o_SCT_signature(sct, &p) <= 0)
goto err;
} else {
memcpy(p, sct->sct, len);
}
return len;
err:
OPENSSL_free(p);
return -1;
}
