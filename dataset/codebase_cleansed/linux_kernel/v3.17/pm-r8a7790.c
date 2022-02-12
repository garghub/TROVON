static void __init r8a7790_sysc_init(void)
{
void __iomem *base = rcar_sysc_init(0xe6180000);
iowrite32(0x0131000e, base + SYSCIER);
iowrite32(0, base + SYSCIMR);
}
static inline void r8a7790_sysc_init(void) {}
void __init r8a7790_pm_init(void)
{
void __iomem *p;
u32 bar;
static int once;
if (once++)
return;
p = ioremap_nocache(MERAM, shmobile_boot_size);
memcpy_toio(p, shmobile_boot_vector, shmobile_boot_size);
iounmap(p);
p = ioremap_nocache(RST, 0x63);
bar = (MERAM >> 8) & 0xfffffc00;
writel_relaxed(bar, p + CA15BAR);
writel_relaxed(bar, p + CA7BAR);
writel_relaxed(bar | 0x10, p + CA15BAR);
writel_relaxed(bar | 0x10, p + CA7BAR);
writel_relaxed((readl_relaxed(p + CA15RESCNT) & ~0x0f) | 0xa5a50000,
p + CA15RESCNT);
writel_relaxed((readl_relaxed(p + CA7RESCNT) & ~0x0f) | 0x5a5a0000,
p + CA7RESCNT);
iounmap(p);
r8a7790_sysc_init();
shmobile_smp_apmu_suspend_init();
}
