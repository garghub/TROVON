static void __init mvebu_scu_enable(void)
{
void __iomem *scu_base;
struct device_node *np =
of_find_compatible_node(NULL, NULL, "arm,cortex-a9-scu");
if (np) {
scu_base = of_iomap(np, 0);
scu_enable(scu_base);
of_node_put(np);
}
}
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
static void __init thermal_quirk(void)
{
struct device_node *np;
u32 dev, rev;
if (mvebu_get_soc_id(&dev, &rev) == 0 && rev > ARMADA_375_Z1_REV)
return;
for_each_compatible_node(np, NULL, "marvell,armada375-thermal") {
struct property *prop;
__be32 newval, *newprop, *oldprop;
int len;
oldprop = (__be32 *)of_get_property(np, "reg", &len);
if (!oldprop)
continue;
prop = kzalloc(sizeof(*prop), GFP_KERNEL);
prop->length = len;
prop->name = kstrdup("reg", GFP_KERNEL);
prop->value = kzalloc(len, GFP_KERNEL);
memcpy(prop->value, oldprop, len);
oldprop += 2;
newprop = (__be32 *)prop->value + 2;
newval = cpu_to_be32(be32_to_cpu(*oldprop) -
A375_Z1_THERMAL_FIXUP_OFFSET);
*newprop = newval;
of_update_property(np, prop);
prop = kzalloc(sizeof(*prop), GFP_KERNEL);
prop->name = kstrdup("compatible", GFP_KERNEL);
prop->length = sizeof("marvell,armada375-z1-thermal");
prop->value = kstrdup("marvell,armada375-z1-thermal",
GFP_KERNEL);
of_update_property(np, prop);
}
return;
}
static void __init mvebu_dt_init(void)
{
if (of_machine_is_compatible("plathome,openblocks-ax3-4"))
i2c_quirk();
if (of_machine_is_compatible("marvell,a375-db")) {
external_abort_quirk();
thermal_quirk();
}
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
