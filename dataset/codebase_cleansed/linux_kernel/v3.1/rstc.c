static int __init sirfsoc_of_rstc_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, rstc_ids);
if (!np)
panic("unable to find compatible rstc node in dtb\n");
sirfsoc_rstc_base = of_iomap(np, 0);
if (!sirfsoc_rstc_base)
panic("unable to map rstc cpu registers\n");
of_node_put(np);
return 0;
}
int sirfsoc_reset_device(struct device *dev)
{
const unsigned int *prop = of_get_property(dev->of_node, "reset-bit", NULL);
unsigned int reset_bit;
if (!prop)
return -ENODEV;
reset_bit = be32_to_cpup(prop);
mutex_lock(&rstc_lock);
writel(readl(sirfsoc_rstc_base + (reset_bit / 32) * 4) | reset_bit,
sirfsoc_rstc_base + (reset_bit / 32) * 4);
msleep(10);
writel(readl(sirfsoc_rstc_base + (reset_bit / 32) * 4) & ~reset_bit,
sirfsoc_rstc_base + (reset_bit / 32) * 4);
mutex_unlock(&rstc_lock);
return 0;
}
