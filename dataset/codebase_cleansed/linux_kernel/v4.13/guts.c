static const struct fsl_soc_die_attr *fsl_soc_die_match(
u32 svr, const struct fsl_soc_die_attr *matches)
{
while (matches->svr) {
if (matches->svr == (svr & matches->mask))
return matches;
matches++;
};
return NULL;
}
u32 fsl_guts_get_svr(void)
{
u32 svr = 0;
if (!guts || !guts->regs)
return svr;
if (guts->little_endian)
svr = ioread32(&guts->regs->svr);
else
svr = ioread32be(&guts->regs->svr);
return svr;
}
static int fsl_guts_probe(struct platform_device *pdev)
{
struct device_node *root, *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct resource *res;
const struct fsl_soc_die_attr *soc_die;
const char *machine;
u32 svr;
guts = devm_kzalloc(dev, sizeof(*guts), GFP_KERNEL);
if (!guts)
return -ENOMEM;
guts->little_endian = of_property_read_bool(np, "little-endian");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
guts->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(guts->regs))
return PTR_ERR(guts->regs);
root = of_find_node_by_path("/");
if (of_property_read_string(root, "model", &machine))
of_property_read_string_index(root, "compatible", 0, &machine);
of_node_put(root);
if (machine)
soc_dev_attr.machine = devm_kstrdup(dev, machine, GFP_KERNEL);
svr = fsl_guts_get_svr();
soc_die = fsl_soc_die_match(svr, fsl_soc_die);
if (soc_die) {
soc_dev_attr.family = devm_kasprintf(dev, GFP_KERNEL,
"QorIQ %s", soc_die->die);
} else {
soc_dev_attr.family = devm_kasprintf(dev, GFP_KERNEL, "QorIQ");
}
soc_dev_attr.soc_id = devm_kasprintf(dev, GFP_KERNEL,
"svr:0x%08x", svr);
soc_dev_attr.revision = devm_kasprintf(dev, GFP_KERNEL, "%d.%d",
(svr >> 4) & 0xf, svr & 0xf);
soc_dev = soc_device_register(&soc_dev_attr);
if (IS_ERR(soc_dev))
return PTR_ERR(soc_dev);
pr_info("Machine: %s\n", soc_dev_attr.machine);
pr_info("SoC family: %s\n", soc_dev_attr.family);
pr_info("SoC ID: %s, Revision: %s\n",
soc_dev_attr.soc_id, soc_dev_attr.revision);
return 0;
}
static int fsl_guts_remove(struct platform_device *dev)
{
soc_device_unregister(soc_dev);
return 0;
}
static int __init fsl_guts_init(void)
{
return platform_driver_register(&fsl_guts_driver);
}
static void __exit fsl_guts_exit(void)
{
platform_driver_unregister(&fsl_guts_driver);
}
