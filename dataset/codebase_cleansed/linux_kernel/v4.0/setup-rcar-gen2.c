u32 rcar_gen2_read_mode_pins(void)
{
static u32 mode;
static bool mode_valid;
if (!mode_valid) {
void __iomem *modemr = ioremap_nocache(MODEMR, 4);
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
mode_valid = true;
}
return mode;
}
void __init rcar_gen2_timer_init(void)
{
#if defined(CONFIG_ARM_ARCH_TIMER) || defined(CONFIG_COMMON_CLK)
u32 mode = rcar_gen2_read_mode_pins();
#endif
#ifdef CONFIG_ARM_ARCH_TIMER
void __iomem *base;
int extal_mhz = 0;
u32 freq;
if (of_machine_is_compatible("renesas,r8a7794")) {
freq = 260000000 / 8;
asm volatile(
" cps 0x16\n"
" mrc p15, 0, r1, c1, c1, 0\n"
" orr r0, r1, #1\n"
" mcr p15, 0, r0, c1, c1, 0\n"
" isb\n"
" mov r0, #0\n"
" mcrr p15, 4, r0, r0, c14\n"
" isb\n"
" mcr p15, 0, r1, c1, c1, 0\n"
" isb\n"
" cps 0x13\n"
: : : "r0", "r1");
} else {
switch (mode & (MD(14) | MD(13))) {
case 0:
extal_mhz = 15;
break;
case MD(13):
extal_mhz = 20;
break;
case MD(14):
extal_mhz = 26;
break;
case MD(13) | MD(14):
extal_mhz = 30;
break;
}
freq = extal_mhz * (1000000 / 2);
}
base = ioremap(0xe6080000, PAGE_SIZE);
if ((ioread32(base + CNTCR) & 1) == 0 ||
ioread32(base + CNTFID0) != freq) {
iowrite32(freq, base + CNTFID0);
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
iowrite32(1, base + CNTCR);
}
iounmap(base);
#endif
#ifdef CONFIG_COMMON_CLK
rcar_gen2_clocks_init(mode);
#endif
#ifdef CONFIG_ARCH_SHMOBILE_MULTI
clocksource_of_init();
#endif
}
static int __init rcar_gen2_scan_mem(unsigned long node, const char *uname,
int depth, void *data)
{
const char *type = of_get_flat_dt_prop(node, "device_type", NULL);
const __be32 *reg, *endp;
int l;
struct memory_reserve_config *mrc = data;
u64 lpae_start = 1ULL << 32;
if (type == NULL || strcmp(type, "memory"))
return 0;
reg = of_get_flat_dt_prop(node, "linux,usable-memory", &l);
if (reg == NULL)
reg = of_get_flat_dt_prop(node, "reg", &l);
if (reg == NULL)
return 0;
endp = reg + (l / sizeof(__be32));
while ((endp - reg) >= (dt_root_addr_cells + dt_root_size_cells)) {
u64 base, size;
base = dt_mem_next_cell(dt_root_addr_cells, &reg);
size = dt_mem_next_cell(dt_root_size_cells, &reg);
if (base >= lpae_start)
continue;
if ((base + size) >= lpae_start)
size = lpae_start - base;
if (size < mrc->reserved)
continue;
if (base < mrc->base)
continue;
mrc->base = base + size - mrc->reserved;
mrc->size = mrc->reserved;
}
return 0;
}
void __init rcar_gen2_reserve(void)
{
struct memory_reserve_config mrc;
memset(&mrc, 0, sizeof(mrc));
mrc.reserved = SZ_256M;
of_scan_flat_dt(rcar_gen2_scan_mem, &mrc);
#ifdef CONFIG_DMA_CMA
if (mrc.size)
dma_contiguous_reserve_area(mrc.size, mrc.base, 0,
&rcar_gen2_dma_contiguous, true);
#endif
}
