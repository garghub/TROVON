static int coreboot_table_acpi_probe(struct platform_device *pdev)
{
phys_addr_t phyaddr;
resource_size_t len;
struct coreboot_table_header __iomem *header = NULL;
struct resource *res;
void __iomem *ptr = NULL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
len = resource_size(res);
if (!res->start || !len)
return -EINVAL;
phyaddr = res->start;
header = ioremap_cache(phyaddr, sizeof(*header));
if (header == NULL)
return -ENOMEM;
ptr = ioremap_cache(phyaddr,
header->header_bytes + header->table_bytes);
iounmap(header);
if (!ptr)
return -ENOMEM;
return coreboot_table_init(ptr);
}
static int coreboot_table_acpi_remove(struct platform_device *pdev)
{
return coreboot_table_exit();
}
static int __init coreboot_table_acpi_init(void)
{
return platform_driver_register(&coreboot_table_acpi_driver);
}
