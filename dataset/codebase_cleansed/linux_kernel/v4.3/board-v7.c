static void __init mvebu_scu_enable(void)
{
struct device_node *np =
of_find_compatible_node(NULL, NULL, "arm,cortex-a9-scu");
if (np) {
scu_base = of_iomap(np, 0);
scu_enable(scu_base);
of_node_put(np);
}
}
void __iomem *mvebu_get_scu_base(void)
{
return scu_base;
}
static int __init mvebu_scan_mem(unsigned long node, const char *uname,
int depth, void *data)
{
const char *type = of_get_flat_dt_prop(node, "device_type", NULL);
const __be32 *reg, *endp;
int l;
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
memblock_reserve(base, MVEBU_DDR_TRAINING_AREA_SZ);
}
return 0;
}
static void __init mvebu_memblock_reserve(void)
{
of_scan_flat_dt(mvebu_scan_mem, NULL);
}
static void __init mvebu_memblock_reserve(void) {}
static int armada_375_external_abort_wa(unsigned long addr, unsigned int fsr,
struct pt_regs *regs)
{
static int ignore_first;
if (!ignore_first && fsr == 0x1406) {
ignore_first = 1;
return 0;
}
return 1;
}
static void __init mvebu_init_irq(void)
{
irqchip_init();
mvebu_scu_enable();
coherency_init();
BUG_ON(mvebu_mbus_dt_init(coherency_available()));
}
static void __init external_abort_quirk(void)
{
u32 dev, rev;
if (mvebu_get_soc_id(&dev, &rev) == 0 && rev > ARMADA_375_Z1_REV)
return;
hook_fault_code(16 + 6, armada_375_external_abort_wa, SIGBUS, 0,
"imprecise external abort");
}
static void __init i2c_quirk(void)
{
struct device_node *np;
u32 dev, rev;
if (mvebu_get_soc_id(&dev, &rev) == 0 && rev > MV78XX0_A0_REV)
return;
for_each_compatible_node(np, NULL, "marvell,mv78230-i2c") {
struct property *new_compat;
new_compat = kzalloc(sizeof(*new_compat), GFP_KERNEL);
new_compat->name = kstrdup("compatible", GFP_KERNEL);
new_compat->length = sizeof("marvell,mv78230-a0-i2c");
new_compat->value = kstrdup("marvell,mv78230-a0-i2c",
GFP_KERNEL);
of_update_property(np, new_compat);
}
return;
}
static void __init mvebu_dt_init(void)
{
if (of_machine_is_compatible("marvell,armadaxp"))
i2c_quirk();
if (of_machine_is_compatible("marvell,a375-db"))
external_abort_quirk();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
