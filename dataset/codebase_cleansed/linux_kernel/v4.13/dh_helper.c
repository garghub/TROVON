static inline u8 *dh_pack_data(void *dst, const void *src, size_t size)
{
memcpy(dst, src, size);
return dst + size;
}
static inline const u8 *dh_unpack_data(void *dst, const void *src, size_t size)
{
memcpy(dst, src, size);
return src + size;
}
static inline int dh_data_size(const struct dh *p)
{
return p->key_size + p->p_size + p->g_size;
}
int crypto_dh_key_len(const struct dh *p)
{
return DH_KPP_SECRET_MIN_SIZE + dh_data_size(p);
}
int crypto_dh_encode_key(char *buf, unsigned int len, const struct dh *params)
{
u8 *ptr = buf;
struct kpp_secret secret = {
.type = CRYPTO_KPP_SECRET_TYPE_DH,
.len = len
};
if (unlikely(!buf))
return -EINVAL;
if (len != crypto_dh_key_len(params))
return -EINVAL;
ptr = dh_pack_data(ptr, &secret, sizeof(secret));
ptr = dh_pack_data(ptr, &params->key_size, sizeof(params->key_size));
ptr = dh_pack_data(ptr, &params->p_size, sizeof(params->p_size));
ptr = dh_pack_data(ptr, &params->g_size, sizeof(params->g_size));
ptr = dh_pack_data(ptr, params->key, params->key_size);
ptr = dh_pack_data(ptr, params->p, params->p_size);
dh_pack_data(ptr, params->g, params->g_size);
return 0;
}
int crypto_dh_decode_key(const char *buf, unsigned int len, struct dh *params)
{
const u8 *ptr = buf;
struct kpp_secret secret;
if (unlikely(!buf || len < DH_KPP_SECRET_MIN_SIZE))
return -EINVAL;
ptr = dh_unpack_data(&secret, ptr, sizeof(secret));
if (secret.type != CRYPTO_KPP_SECRET_TYPE_DH)
return -EINVAL;
ptr = dh_unpack_data(&params->key_size, ptr, sizeof(params->key_size));
ptr = dh_unpack_data(&params->p_size, ptr, sizeof(params->p_size));
ptr = dh_unpack_data(&params->g_size, ptr, sizeof(params->g_size));
if (secret.len != crypto_dh_key_len(params))
return -EINVAL;
params->key = (void *)ptr;
params->p = (void *)(ptr + params->key_size);
params->g = (void *)(ptr + params->key_size + params->p_size);
return 0;
}
