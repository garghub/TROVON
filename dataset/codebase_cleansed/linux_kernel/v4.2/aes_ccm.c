void ieee80211_aes_ccm_encrypt(struct crypto_aead *tfm, u8 *b_0, u8 *aad,
u8 *data, size_t data_len, u8 *mic,
size_t mic_len)
{
struct scatterlist sg[3];
char aead_req_data[sizeof(struct aead_request) +
crypto_aead_reqsize(tfm)]
__aligned(__alignof__(struct aead_request));
struct aead_request *aead_req = (void *) aead_req_data;
memset(aead_req, 0, sizeof(aead_req_data));
sg_init_table(sg, 3);
sg_set_buf(&sg[0], &aad[2], be16_to_cpup((__be16 *)aad));
sg_set_buf(&sg[1], data, data_len);
sg_set_buf(&sg[2], mic, mic_len);
aead_request_set_tfm(aead_req, tfm);
aead_request_set_crypt(aead_req, sg, sg, data_len, b_0);
aead_request_set_ad(aead_req, sg[0].length);
crypto_aead_encrypt(aead_req);
}
int ieee80211_aes_ccm_decrypt(struct crypto_aead *tfm, u8 *b_0, u8 *aad,
u8 *data, size_t data_len, u8 *mic,
size_t mic_len)
{
struct scatterlist sg[3];
char aead_req_data[sizeof(struct aead_request) +
crypto_aead_reqsize(tfm)]
__aligned(__alignof__(struct aead_request));
struct aead_request *aead_req = (void *) aead_req_data;
if (data_len == 0)
return -EINVAL;
memset(aead_req, 0, sizeof(aead_req_data));
sg_init_table(sg, 3);
sg_set_buf(&sg[0], &aad[2], be16_to_cpup((__be16 *)aad));
sg_set_buf(&sg[1], data, data_len);
sg_set_buf(&sg[2], mic, mic_len);
aead_request_set_tfm(aead_req, tfm);
aead_request_set_crypt(aead_req, sg, sg, data_len + mic_len, b_0);
aead_request_set_ad(aead_req, sg[0].length);
return crypto_aead_decrypt(aead_req);
}
struct crypto_aead *ieee80211_aes_key_setup_encrypt(const u8 key[],
size_t key_len,
size_t mic_len)
{
struct crypto_aead *tfm;
int err;
tfm = crypto_alloc_aead("ccm(aes)", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm))
return tfm;
err = crypto_aead_setkey(tfm, key, key_len);
if (err)
goto free_aead;
err = crypto_aead_setauthsize(tfm, mic_len);
if (err)
goto free_aead;
return tfm;
free_aead:
crypto_free_aead(tfm);
return ERR_PTR(err);
}
void ieee80211_aes_key_free(struct crypto_aead *tfm)
{
crypto_free_aead(tfm);
}
