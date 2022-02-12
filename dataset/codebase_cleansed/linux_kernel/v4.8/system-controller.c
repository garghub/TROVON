void mvebu_restart(enum reboot_mode mode, const char *cmd)
{
if (!system_controller_base) {
pr_err("Cannot restart, system-controller not available: check the device tree\n");
} else {
writel(mvebu_sc->rstoutn_mask_reset_out_en,
system_controller_base +
mvebu_sc->rstoutn_mask_offset);
writel(mvebu_sc->system_soft_reset,
system_controller_base +
mvebu_sc->system_soft_reset_offset);
}
while (1)
;
}
int mvebu_system_controller_get_soc_id(u32 *dev, u32 *rev)
{
if (of_machine_is_compatible("marvell,armada380") &&
system_controller_base) {
*dev = readl(system_controller_base + mvebu_sc->dev_id) >> 16;
*rev = (readl(system_controller_base + mvebu_sc->rev_id) >> 8)
& 0xF;
return 0;
} else
return -ENODEV;
}
static void mvebu_armada375_smp_wa_init(void)
{
u32 dev, rev;
phys_addr_t resume_addr_reg;
if (mvebu_get_soc_id(&dev, &rev) != 0)
return;
if (rev != ARMADA_375_Z1_REV)
return;
resume_addr_reg = system_controller_phys_base +
mvebu_sc->resume_boot_addr;
mvebu_setup_boot_addr_wa(ARMADA_375_CRYPT0_ENG_TARGET,
ARMADA_375_CRYPT0_ENG_ATTR,
resume_addr_reg);
}
void mvebu_system_controller_set_cpu_boot_addr(void *boot_addr)
{
BUG_ON(system_controller_base == NULL);
BUG_ON(mvebu_sc->resume_boot_addr == 0);
if (of_machine_is_compatible("marvell,armada375"))
mvebu_armada375_smp_wa_init();
writel(virt_to_phys(boot_addr), system_controller_base +
mvebu_sc->resume_boot_addr);
}
static int __init mvebu_system_controller_init(void)
{
const struct of_device_id *match;
struct device_node *np;
np = of_find_matching_node_and_match(NULL, of_system_controller_table,
&match);
if (np) {
struct resource res;
system_controller_base = of_iomap(np, 0);
of_address_to_resource(np, 0, &res);
system_controller_phys_base = res.start;
mvebu_sc = (struct mvebu_system_controller *)match->data;
of_node_put(np);
}
return 0;
}
