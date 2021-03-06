static int __init c6x_emifa_init(void)
{
struct emifa_regs __iomem *regs;
struct device_node *node;
const __be32 *p;
u32 val;
int i, len, err;
node = of_find_matching_node(NULL, emifa_match);
if (!node)
return 0;
regs = of_iomap(node, 0);
if (!regs)
return 0;
err = of_property_read_u32_array(node, "ti,dscr-dev-enable", &val, 1);
if (!err)
dscr_set_devstate(val, DSCR_DEVSTATE_ENABLED);
p = of_get_property(node, "ti,emifa-ce-config", &len);
if (p) {
len /= sizeof(u32);
if (len > NUM_EMIFA_CHIP_ENABLES)
len = NUM_EMIFA_CHIP_ENABLES;
for (i = 0; i <= len; i++)
soc_writel(be32_to_cpup(&p[i]), &regs->cecfg[i]);
}
err = of_property_read_u32_array(node, "ti,emifa-burst-priority", &val, 1);
if (!err)
soc_writel(val, &regs->bprio);
err = of_property_read_u32_array(node, "ti,emifa-async-wait-control", &val, 1);
if (!err)
soc_writel(val, &regs->awcc);
iounmap(regs);
of_node_put(node);
return 0;
}
