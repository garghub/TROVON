static void __init rcar_gen2_sysc_init(u32 syscier)
{
void __iomem *base = rcar_sysc_init(0xe6180000);
iowrite32(syscier, base + SYSCIER);
iowrite32(0, base + SYSCIMR);
}
static inline void rcar_gen2_sysc_init(u32 syscier) {}
void __init rcar_gen2_pm_init(void)
{
void __iomem *p;
u32 bar;
static int once;
struct device_node *np, *cpus;
bool has_a7 = false;
bool has_a15 = false;
phys_addr_t boot_vector_addr = 0;
u32 syscier = 0;
if (once++)
return;
cpus = of_find_node_by_path("/cpus");
if (!cpus)
return;
for_each_child_of_node(cpus, np) {
if (of_device_is_compatible(np, "arm,cortex-a15"))
has_a15 = true;
else if (of_device_is_compatible(np, "arm,cortex-a7"))
has_a7 = true;
}
if (of_machine_is_compatible("renesas,r8a7790")) {
boot_vector_addr = MERAM;
syscier = 0x013111ef;
} else if (of_machine_is_compatible("renesas,r8a7791")) {
boot_vector_addr = RAM;
syscier = 0x00111003;
}
p = ioremap_nocache(boot_vector_addr, shmobile_boot_size);
memcpy_toio(p, shmobile_boot_vector, shmobile_boot_size);
iounmap(p);
p = ioremap_nocache(RST, 0x63);
bar = (boot_vector_addr >> 8) & 0xfffffc00;
if (has_a15) {
writel_relaxed(bar, p + CA15BAR);
writel_relaxed(bar | 0x10, p + CA15BAR);
writel_relaxed((readl_relaxed(p + CA15RESCNT) & ~0x0f) |
0xa5a50000, p + CA15RESCNT);
}
if (has_a7) {
writel_relaxed(bar, p + CA7BAR);
writel_relaxed(bar | 0x10, p + CA7BAR);
writel_relaxed((readl_relaxed(p + CA7RESCNT) & ~0x0f) |
0x5a5a0000, p + CA7RESCNT);
}
iounmap(p);
rcar_gen2_sysc_init(syscier);
shmobile_smp_apmu_suspend_init();
}
