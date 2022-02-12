static inline u32 phys_to_sbar(phys_addr_t addr)
{
return (addr >> 8) & 0xfffffc00;
}
static void __init rcar_gen2_sysc_init(u32 syscier)
{
rcar_sysc_init(0xe6180000, syscier);
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
struct resource res;
u32 syscier = 0;
int error;
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
if (of_machine_is_compatible("renesas,r8a7790"))
syscier = 0x013111ef;
else if (of_machine_is_compatible("renesas,r8a7791"))
syscier = 0x00111003;
np = of_find_compatible_node(NULL, NULL, "renesas,smp-sram");
if (!np) {
res = (struct resource)DEFINE_RES_MEM(ICRAM1,
shmobile_boot_size);
goto map;
}
error = of_address_to_resource(np, 0, &res);
if (error) {
pr_err("Failed to get smp-sram address: %d\n", error);
return;
}
map:
if (res.start & (256 * 1024 - 1) ||
resource_size(&res) < shmobile_boot_size) {
pr_err("Invalid smp-sram region\n");
return;
}
p = ioremap(res.start, resource_size(&res));
if (!p)
return;
memcpy_toio(p, shmobile_boot_vector, shmobile_boot_size);
iounmap(p);
p = ioremap_nocache(RST, 0x63);
bar = phys_to_sbar(res.start);
if (has_a15) {
writel_relaxed(bar, p + CA15BAR);
writel_relaxed(bar | SBAR_BAREN, p + CA15BAR);
writel_relaxed((readl_relaxed(p + CA15RESCNT) &
~CA15RESCNT_CPUS) | CA15RESCNT_CODE,
p + CA15RESCNT);
}
if (has_a7) {
writel_relaxed(bar, p + CA7BAR);
writel_relaxed(bar | SBAR_BAREN, p + CA7BAR);
writel_relaxed((readl_relaxed(p + CA7RESCNT) &
~CA7RESCNT_CPUS) | CA7RESCNT_CODE,
p + CA7RESCNT);
}
iounmap(p);
rcar_gen2_sysc_init(syscier);
shmobile_smp_apmu_suspend_init();
}
