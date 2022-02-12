static int crct10dif_init(struct shash_desc *desc)
{
u16 *crc = shash_desc_ctx(desc);
*crc = 0;
return 0;
}
static int crct10dif_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
u16 *crc = shash_desc_ctx(desc);
unsigned int l;
if (unlikely((u64)data % CRC_T10DIF_PMULL_CHUNK_SIZE)) {
l = min_t(u32, length, CRC_T10DIF_PMULL_CHUNK_SIZE -
((u64)data % CRC_T10DIF_PMULL_CHUNK_SIZE));
*crc = crc_t10dif_generic(*crc, data, l);
length -= l;
data += l;
}
if (length > 0) {
if (may_use_simd()) {
kernel_neon_begin();
*crc = crc_t10dif_pmull(*crc, data, length);
kernel_neon_end();
} else {
*crc = crc_t10dif_generic(*crc, data, length);
}
}
return 0;
}
static int crct10dif_final(struct shash_desc *desc, u8 *out)
{
u16 *crc = shash_desc_ctx(desc);
*(u16 *)out = *crc;
return 0;
}
static int __init crc_t10dif_mod_init(void)
{
return crypto_register_shash(&crc_t10dif_alg);
}
static void __exit crc_t10dif_mod_exit(void)
{
crypto_unregister_shash(&crc_t10dif_alg);
}
