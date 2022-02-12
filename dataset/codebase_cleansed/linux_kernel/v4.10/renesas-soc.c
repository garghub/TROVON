static int __init renesas_soc_init(void)
{
struct soc_device_attribute *soc_dev_attr;
const struct renesas_family *family;
const struct of_device_id *match;
const struct renesas_soc *soc;
void __iomem *chipid = NULL;
struct soc_device *soc_dev;
struct device_node *np;
unsigned int product;
match = of_match_node(renesas_socs, of_root);
if (!match)
return -ENODEV;
soc = match->data;
family = soc->family;
np = of_find_compatible_node(NULL, NULL, "renesas,prr");
if (np) {
chipid = of_iomap(np, 0);
of_node_put(np);
} else if (soc->id) {
chipid = ioremap(family->reg, 4);
}
if (chipid) {
product = readl(chipid);
iounmap(chipid);
if (soc->id && ((product >> 8) & 0xff) != soc->id) {
pr_warn("SoC mismatch (product = 0x%x)\n", product);
return -ENODEV;
}
}
soc_dev_attr = kzalloc(sizeof(*soc_dev_attr), GFP_KERNEL);
if (!soc_dev_attr)
return -ENOMEM;
np = of_find_node_by_path("/");
of_property_read_string(np, "model", &soc_dev_attr->machine);
of_node_put(np);
soc_dev_attr->family = kstrdup_const(family->name, GFP_KERNEL);
soc_dev_attr->soc_id = kstrdup_const(strchr(match->compatible, ',') + 1,
GFP_KERNEL);
if (chipid)
soc_dev_attr->revision = kasprintf(GFP_KERNEL, "ES%u.%u",
((product >> 4) & 0x0f) + 1,
product & 0xf);
pr_info("Detected Renesas %s %s %s\n", soc_dev_attr->family,
soc_dev_attr->soc_id, soc_dev_attr->revision ?: "");
soc_dev = soc_device_register(soc_dev_attr);
if (IS_ERR(soc_dev)) {
kfree(soc_dev_attr->revision);
kfree_const(soc_dev_attr->soc_id);
kfree_const(soc_dev_attr->family);
kfree(soc_dev_attr);
return PTR_ERR(soc_dev);
}
return 0;
}
