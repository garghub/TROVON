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
void mvebu_system_controller_set_cpu_boot_addr(void *boot_addr)
{
BUG_ON(system_controller_base == NULL);
BUG_ON(mvebu_sc->resume_boot_addr == 0);
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
system_controller_base = of_iomap(np, 0);
mvebu_sc = (struct mvebu_system_controller *)match->data;
of_node_put(np);
}
return 0;
}
