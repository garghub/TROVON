static int __init sirfsoc_of_rstc_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, rstc_ids);
if (!np) {
pr_err("unable to find compatible sirf rstc node in dtb\n");
return -ENOENT;
}
sirfsoc_rstc_base = of_iomap(np, 0);
if (!sirfsoc_rstc_base)
panic("unable to map rstc cpu registers\n");
of_node_put(np);
return 0;
}
int sirfsoc_reset_device(struct device *dev)
{
u32 reset_bit;
if (of_property_read_u32(dev->of_node, "reset-bit", &reset_bit))
return -EINVAL;
mutex_lock(&rstc_lock);
if (of_device_is_compatible(dev->of_node, "sirf,prima2-rstc")) {
writel(readl(sirfsoc_rstc_base + (reset_bit / 32) * 4) | reset_bit,
sirfsoc_rstc_base + (reset_bit / 32) * 4);
msleep(10);
writel(readl(sirfsoc_rstc_base + (reset_bit / 32) * 4) & ~reset_bit,
sirfsoc_rstc_base + (reset_bit / 32) * 4);
} else {
writel(reset_bit, sirfsoc_rstc_base + (reset_bit / 32) * 8);
msleep(10);
writel(reset_bit, sirfsoc_rstc_base + (reset_bit / 32) * 8 + 4);
}
mutex_unlock(&rstc_lock);
return 0;
}
void sirfsoc_restart(char mode, const char *cmd)
{
writel(SIRFSOC_SYS_RST_BIT, sirfsoc_rstc_base);
}
