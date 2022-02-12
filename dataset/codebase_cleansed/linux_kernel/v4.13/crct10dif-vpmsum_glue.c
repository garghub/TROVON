static u16 crct10dif_vpmsum(u16 crci, unsigned char const *p, size_t len)
{
unsigned int prealign;
unsigned int tail;
u32 crc = crci;
if (len < (VECTOR_BREAKPOINT + VMX_ALIGN) || in_interrupt())
return crc_t10dif_generic(crc, p, len);
if ((unsigned long)p & VMX_ALIGN_MASK) {
prealign = VMX_ALIGN - ((unsigned long)p & VMX_ALIGN_MASK);
crc = crc_t10dif_generic(crc, p, prealign);
len -= prealign;
p += prealign;
}
if (len & ~VMX_ALIGN_MASK) {
crc <<= 16;
preempt_disable();
pagefault_disable();
enable_kernel_altivec();
crc = __crct10dif_vpmsum(crc, p, len & ~VMX_ALIGN_MASK);
disable_kernel_altivec();
pagefault_enable();
preempt_enable();
crc >>= 16;
}
tail = len & VMX_ALIGN_MASK;
if (tail) {
p += len & ~VMX_ALIGN_MASK;
crc = crc_t10dif_generic(crc, p, tail);
}
return crc & 0xffff;
}
static int crct10dif_vpmsum_init(struct shash_desc *desc)
{
u16 *crc = shash_desc_ctx(desc);
*crc = 0;
return 0;
}
static int crct10dif_vpmsum_update(struct shash_desc *desc, const u8 *data,
unsigned int length)
{
u16 *crc = shash_desc_ctx(desc);
*crc = crct10dif_vpmsum(*crc, data, length);
return 0;
}
static int crct10dif_vpmsum_final(struct shash_desc *desc, u8 *out)
{
u16 *crcp = shash_desc_ctx(desc);
*(u16 *)out = *crcp;
return 0;
}
static int __init crct10dif_vpmsum_mod_init(void)
{
if (!cpu_has_feature(CPU_FTR_ARCH_207S))
return -ENODEV;
return crypto_register_shash(&alg);
}
static void __exit crct10dif_vpmsum_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
