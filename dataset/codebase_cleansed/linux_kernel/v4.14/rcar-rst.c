static int __init rcar_rst_init(void)
{
const struct of_device_id *match;
const struct rst_config *cfg;
struct device_node *np;
void __iomem *base;
int error = 0;
np = of_find_matching_node_and_match(NULL, rcar_rst_matches, &match);
if (!np)
return -ENODEV;
base = of_iomap(np, 0);
if (!base) {
pr_warn("%pOF: Cannot map regs\n", np);
error = -ENOMEM;
goto out_put;
}
rcar_rst_base = base;
cfg = match->data;
saved_mode = ioread32(base + cfg->modemr);
pr_debug("%pOF: MODE = 0x%08x\n", np, saved_mode);
out_put:
of_node_put(np);
return error;
}
int __init rcar_rst_read_mode_pins(u32 *mode)
{
int error;
if (!rcar_rst_base) {
error = rcar_rst_init();
if (error)
return error;
}
*mode = saved_mode;
return 0;
}
