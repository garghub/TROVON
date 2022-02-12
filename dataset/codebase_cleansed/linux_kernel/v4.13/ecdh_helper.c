static inline u8 *ecdh_pack_data(void *dst, const void *src, size_t sz)
{
memcpy(dst, src, sz);
return dst + sz;
}
static inline const u8 *ecdh_unpack_data(void *dst, const void *src, size_t sz)
{
memcpy(dst, src, sz);
return src + sz;
}
int crypto_ecdh_key_len(const struct ecdh *params)
{
return ECDH_KPP_SECRET_MIN_SIZE + params->key_size;
}
int crypto_ecdh_encode_key(char *buf, unsigned int len,
const struct ecdh *params)
{
u8 *ptr = buf;
struct kpp_secret secret = {
.type = CRYPTO_KPP_SECRET_TYPE_ECDH,
.len = len
};
if (unlikely(!buf))
return -EINVAL;
if (len != crypto_ecdh_key_len(params))
return -EINVAL;
ptr = ecdh_pack_data(ptr, &secret, sizeof(secret));
ptr = ecdh_pack_data(ptr, &params->curve_id, sizeof(params->curve_id));
ptr = ecdh_pack_data(ptr, &params->key_size, sizeof(params->key_size));
ecdh_pack_data(ptr, params->key, params->key_size);
return 0;
}
int crypto_ecdh_decode_key(const char *buf, unsigned int len,
struct ecdh *params)
{
const u8 *ptr = buf;
struct kpp_secret secret;
if (unlikely(!buf || len < ECDH_KPP_SECRET_MIN_SIZE))
return -EINVAL;
ptr = ecdh_unpack_data(&secret, ptr, sizeof(secret));
if (secret.type != CRYPTO_KPP_SECRET_TYPE_ECDH)
return -EINVAL;
ptr = ecdh_unpack_data(&params->curve_id, ptr, sizeof(params->curve_id));
ptr = ecdh_unpack_data(&params->key_size, ptr, sizeof(params->key_size));
if (secret.len != crypto_ecdh_key_len(params))
return -EINVAL;
params->key = (void *)ptr;
return 0;
}
