void ieee80211_aes_ccm_encrypt(struct crypto_aead *tfm, u8 *b_0, u8 *aad,
u8 *data, size_t data_len, u8 *mic)
{
struct scatterlist assoc, pt, ct[2];
struct {
struct aead_request req;
u8 priv[crypto_aead_reqsize(tfm)];
} aead_req;
memset(&aead_req, 0, sizeof(aead_req));
sg_init_one(&pt, data, data_len);
sg_init_one(&assoc, &aad[2], be16_to_cpup((__be16 *)aad));
sg_init_table(ct, 2);
sg_set_buf(&ct[0], data, data_len);
sg_set_buf(&ct[1], mic, IEEE80211_CCMP_MIC_LEN);
aead_request_set_tfm(&aead_req.req, tfm);
aead_request_set_assoc(&aead_req.req, &assoc, assoc.length);
aead_request_set_crypt(&aead_req.req, &pt, ct, data_len, b_0);
crypto_aead_encrypt(&aead_req.req);
}
int ieee80211_aes_ccm_decrypt(struct crypto_aead *tfm, u8 *b_0, u8 *aad,
u8 *data, size_t data_len, u8 *mic)
{
struct scatterlist assoc, pt, ct[2];
struct {
struct aead_request req;
u8 priv[crypto_aead_reqsize(tfm)];
} aead_req;
memset(&aead_req, 0, sizeof(aead_req));
sg_init_one(&pt, data, data_len);
sg_init_one(&assoc, &aad[2], be16_to_cpup((__be16 *)aad));
sg_init_table(ct, 2);
sg_set_buf(&ct[0], data, data_len);
sg_set_buf(&ct[1], mic, IEEE80211_CCMP_MIC_LEN);
aead_request_set_tfm(&aead_req.req, tfm);
aead_request_set_assoc(&aead_req.req, &assoc, assoc.length);
aead_request_set_crypt(&aead_req.req, ct, &pt,
data_len + IEEE80211_CCMP_MIC_LEN, b_0);
return crypto_aead_decrypt(&aead_req.req);
}
struct crypto_aead *ieee80211_aes_key_setup_encrypt(const u8 key[])
{
struct crypto_aead *tfm;
int err;
tfm = crypto_alloc_aead("ccm(aes)", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm))
return tfm;
err = crypto_aead_setkey(tfm, key, WLAN_KEY_LEN_CCMP);
if (!err)
err = crypto_aead_setauthsize(tfm, IEEE80211_CCMP_MIC_LEN);
if (!err)
return tfm;
crypto_free_aead(tfm);
return ERR_PTR(err);
}
void ieee80211_aes_key_free(struct crypto_aead *tfm)
{
crypto_free_aead(tfm);
}
