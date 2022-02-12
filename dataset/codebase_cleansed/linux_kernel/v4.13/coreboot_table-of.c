static int coreboot_table_of_probe(struct platform_device *pdev)
{
struct device_node *fw_dn = pdev->dev.of_node;
void __iomem *ptr;
ptr = of_iomap(fw_dn, 0);
of_node_put(fw_dn);
if (!ptr)
return -ENOMEM;
return coreboot_table_init(ptr);
}
static int coreboot_table_of_remove(struct platform_device *pdev)
{
return coreboot_table_exit();
}
static int __init platform_coreboot_table_of_init(void)
{
struct platform_device *pdev;
struct device_node *of_node;
of_node = of_find_node_by_path("/firmware/coreboot");
if (!of_node)
return -ENODEV;
if (!of_match_node(coreboot_of_match, of_node))
return -ENODEV;
pdev = of_platform_device_create(of_node, "coreboot_table_of", NULL);
if (!pdev)
return -ENODEV;
return platform_driver_register(&coreboot_table_of_driver);
}
