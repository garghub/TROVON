static inline void tauros2_clean_pa(unsigned long addr)
{
__asm__("mcr p15, 1, %0, c7, c11, 3" : : "r" (addr));
}
static inline void tauros2_clean_inv_pa(unsigned long addr)
{
__asm__("mcr p15, 1, %0, c7, c15, 3" : : "r" (addr));
}
static inline void tauros2_inv_pa(unsigned long addr)
{
__asm__("mcr p15, 1, %0, c7, c7, 3" : : "r" (addr));
}
static void tauros2_inv_range(unsigned long start, unsigned long end)
{
if (start & (CACHE_LINE_SIZE - 1)) {
tauros2_clean_inv_pa(start & ~(CACHE_LINE_SIZE - 1));
start = (start | (CACHE_LINE_SIZE - 1)) + 1;
}
if (end & (CACHE_LINE_SIZE - 1)) {
tauros2_clean_inv_pa(end & ~(CACHE_LINE_SIZE - 1));
end &= ~(CACHE_LINE_SIZE - 1);
}
while (start < end) {
tauros2_inv_pa(start);
start += CACHE_LINE_SIZE;
}
dsb();
}
static void tauros2_clean_range(unsigned long start, unsigned long end)
{
start &= ~(CACHE_LINE_SIZE - 1);
while (start < end) {
tauros2_clean_pa(start);
start += CACHE_LINE_SIZE;
}
dsb();
}
static void tauros2_flush_range(unsigned long start, unsigned long end)
{
start &= ~(CACHE_LINE_SIZE - 1);
while (start < end) {
tauros2_clean_inv_pa(start);
start += CACHE_LINE_SIZE;
}
dsb();
}
static void tauros2_disable(void)
{
__asm__ __volatile__ (
"mcr p15, 1, %0, c7, c11, 0 @L2 Cache Clean All\n\t"
"mrc p15, 0, %0, c1, c0, 0\n\t"
"bic %0, %0, #(1 << 26)\n\t"
"mcr p15, 0, %0, c1, c0, 0 @Disable L2 Cache\n\t"
: : "r" (0x0));
}
static void tauros2_resume(void)
{
__asm__ __volatile__ (
"mcr p15, 1, %0, c7, c7, 0 @L2 Cache Invalidate All\n\t"
"mrc p15, 0, %0, c1, c0, 0\n\t"
"orr %0, %0, #(1 << 26)\n\t"
"mcr p15, 0, %0, c1, c0, 0 @Enable L2 Cache\n\t"
: : "r" (0x0));
}
static inline u32 __init read_extra_features(void)
{
u32 u;
__asm__("mrc p15, 1, %0, c15, c1, 0" : "=r" (u));
return u;
}
static inline void __init write_extra_features(u32 u)
{
__asm__("mcr p15, 1, %0, c15, c1, 0" : : "r" (u));
}
static inline int __init cpuid_scheme(void)
{
return !!((processor_id & 0x000f0000) == 0x000f0000);
}
static inline u32 __init read_mmfr3(void)
{
u32 mmfr3;
__asm__("mrc p15, 0, %0, c0, c1, 7\n" : "=r" (mmfr3));
return mmfr3;
}
static inline u32 __init read_actlr(void)
{
u32 actlr;
__asm__("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
return actlr;
}
static inline void __init write_actlr(u32 actlr)
{
__asm__("mcr p15, 0, %0, c1, c0, 1\n" : : "r" (actlr));
}
static void enable_extra_feature(unsigned int features)
{
u32 u;
u = read_extra_features();
if (features & CACHE_TAUROS2_PREFETCH_ON)
u &= ~0x01000000;
else
u |= 0x01000000;
printk(KERN_INFO "Tauros2: %s L2 prefetch.\n",
(features & CACHE_TAUROS2_PREFETCH_ON)
? "Enabling" : "Disabling");
if (features & CACHE_TAUROS2_LINEFILL_BURST8)
u |= 0x00100000;
else
u &= ~0x00100000;
printk(KERN_INFO "Tauros2: %s line fill burt8.\n",
(features & CACHE_TAUROS2_LINEFILL_BURST8)
? "Enabling" : "Disabling");
write_extra_features(u);
}
static void __init tauros2_internal_init(unsigned int features)
{
char *mode = NULL;
enable_extra_feature(features);
#ifdef CONFIG_CPU_32v5
if ((processor_id & 0xff0f0000) == 0x56050000) {
u32 feat;
feat = read_extra_features();
if (!(feat & 0x00400000)) {
printk(KERN_INFO "Tauros2: Enabling L2 cache.\n");
write_extra_features(feat | 0x00400000);
}
mode = "ARMv5";
outer_cache.inv_range = tauros2_inv_range;
outer_cache.clean_range = tauros2_clean_range;
outer_cache.flush_range = tauros2_flush_range;
outer_cache.disable = tauros2_disable;
outer_cache.resume = tauros2_resume;
}
#endif
#ifdef CONFIG_CPU_32v6
if (cpuid_scheme() && (read_mmfr3() & 0xf) == 0) {
if (!(get_cr() & 0x04000000)) {
printk(KERN_INFO "Tauros2: Enabling L2 cache.\n");
adjust_cr(0x04000000, 0x04000000);
}
mode = "ARMv6";
outer_cache.inv_range = tauros2_inv_range;
outer_cache.clean_range = tauros2_clean_range;
outer_cache.flush_range = tauros2_flush_range;
outer_cache.disable = tauros2_disable;
outer_cache.resume = tauros2_resume;
}
#endif
#ifdef CONFIG_CPU_32v7
if (cpuid_scheme() && (read_mmfr3() & 0xf) == 1) {
u32 actlr;
actlr = read_actlr();
if (!(actlr & 0x00000002)) {
printk(KERN_INFO "Tauros2: Enabling L2 cache.\n");
write_actlr(actlr | 0x00000002);
}
mode = "ARMv7";
}
#endif
if (mode == NULL) {
printk(KERN_CRIT "Tauros2: Unable to detect CPU mode.\n");
return;
}
printk(KERN_INFO "Tauros2: L2 cache support initialised "
"in %s mode.\n", mode);
}
void __init tauros2_init(unsigned int features)
{
#ifdef CONFIG_OF
struct device_node *node;
int ret;
unsigned int f;
node = of_find_matching_node(NULL, tauros2_ids);
if (!node) {
pr_info("Not found marvell,tauros2-cache, disable it\n");
return;
}
ret = of_property_read_u32(node, "marvell,tauros2-cache-features", &f);
if (ret) {
pr_info("Not found marvell,tauros-cache-features property, "
"disable extra features\n");
features = 0;
} else
features = f;
#endif
tauros2_internal_init(features);
}
