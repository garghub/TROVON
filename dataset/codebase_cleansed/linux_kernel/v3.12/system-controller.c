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
static int __init mvebu_system_controller_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, of_system_controller_table);
if (np) {
const struct of_device_id *match =
of_match_node(of_system_controller_table, np);
BUG_ON(!match);
system_controller_base = of_iomap(np, 0);
mvebu_sc = (struct mvebu_system_controller *)match->data;
of_node_put(np);
}
return 0;
}
