static void __init r8a7791_sysc_init(void)
{
void __iomem *base = rcar_sysc_init(0xe6180000);
iowrite32(0x0131000e, base + SYSCIER);
iowrite32(0, base + SYSCIMR);
}
static inline void r8a7791_sysc_init(void) {}
void __init r8a7791_pm_init(void)
{
void __iomem *p;
u32 bar;
static int once;
if (once++)
return;
p = ioremap_nocache(RAM, shmobile_boot_size);
memcpy_toio(p, shmobile_boot_vector, shmobile_boot_size);
iounmap(p);
p = ioremap_nocache(RST, 0x63);
bar = (RAM >> 8) & 0xfffffc00;
writel_relaxed(bar, p + CA15BAR);
writel_relaxed(bar | 0x10, p + CA15BAR);
writel_relaxed((readl_relaxed(p + CA15RESCNT) & ~0x0f) | 0xa5a50000,
p + CA15RESCNT);
iounmap(p);
r8a7791_sysc_init();
shmobile_smp_apmu_suspend_init();
}
