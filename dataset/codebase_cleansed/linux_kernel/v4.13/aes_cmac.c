void ieee80211_aes_cmac(struct crypto_shash *tfm, const u8 *aad,
const u8 *data, size_t data_len, u8 *mic)
{
SHASH_DESC_ON_STACK(desc, tfm);
u8 out[AES_BLOCK_SIZE];
desc->tfm = tfm;
crypto_shash_init(desc);
crypto_shash_update(desc, aad, AAD_LEN);
crypto_shash_update(desc, data, data_len - CMAC_TLEN);
crypto_shash_finup(desc, zero, CMAC_TLEN, out);
memcpy(mic, out, CMAC_TLEN);
}
void ieee80211_aes_cmac_256(struct crypto_shash *tfm, const u8 *aad,
const u8 *data, size_t data_len, u8 *mic)
{
SHASH_DESC_ON_STACK(desc, tfm);
desc->tfm = tfm;
crypto_shash_init(desc);
crypto_shash_update(desc, aad, AAD_LEN);
crypto_shash_update(desc, data, data_len - CMAC_TLEN_256);
crypto_shash_finup(desc, zero, CMAC_TLEN_256, mic);
}
struct crypto_shash *ieee80211_aes_cmac_key_setup(const u8 key[],
size_t key_len)
{
struct crypto_shash *tfm;
tfm = crypto_alloc_shash("cmac(aes)", 0, 0);
if (!IS_ERR(tfm))
crypto_shash_setkey(tfm, key, key_len);
return tfm;
}
void ieee80211_aes_cmac_key_free(struct crypto_shash *tfm)
{
crypto_free_shash(tfm);
}
