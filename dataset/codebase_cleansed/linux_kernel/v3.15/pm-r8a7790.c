static void __init r8a7790_sysc_init(void)
{
void __iomem *base = rcar_sysc_init(0xe6180000);
iowrite32(0x0131000e, base + SYSCIER);
iowrite32(0, base + SYSCIMR);
}
static inline void r8a7790_sysc_init(void) {}
void __init r8a7790_pm_init(void)
{
static int once;
if (!once++)
r8a7790_sysc_init();
}
