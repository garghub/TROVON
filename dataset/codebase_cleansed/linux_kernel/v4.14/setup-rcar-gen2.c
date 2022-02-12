static unsigned int __init get_extal_freq(void)
{
const struct of_device_id *match;
struct device_node *cpg, *extal;
u32 freq = 20000000;
int idx = 0;
cpg = of_find_matching_node_and_match(NULL, cpg_matches, &match);
if (!cpg)
return freq;
if (match->data)
idx = of_property_match_string(cpg, "clock-names", match->data);
extal = of_parse_phandle(cpg, "clocks", idx);
of_node_put(cpg);
if (!extal)
return freq;
of_property_read_u32(extal, "clock-frequency", &freq);
of_node_put(extal);
return freq;
}
void __init rcar_gen2_timer_init(void)
{
#ifdef CONFIG_ARM_ARCH_TIMER
void __iomem *base;
u32 freq;
if (of_machine_is_compatible("renesas,r8a7745") ||
of_machine_is_compatible("renesas,r8a7792") ||
of_machine_is_compatible("renesas,r8a7794")) {
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
freq = get_extal_freq() / 2;
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
of_clk_init(NULL);
timer_probe();
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
if (mrc.size && memblock_is_region_memory(mrc.base, mrc.size)) {
static struct cma *rcar_gen2_dma_contiguous;
dma_contiguous_reserve_area(mrc.size, mrc.base, 0,
&rcar_gen2_dma_contiguous, true);
}
#endif
}
