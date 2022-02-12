static void acpi_platform_fill_resource(struct acpi_device *adev,
const struct resource *src, struct resource *dest)
{
struct device *parent;
*dest = *src;
parent = acpi_get_first_physical_node(adev->parent);
if (parent && dev_is_pci(parent))
dest->parent = pci_find_resource(to_pci_dev(parent), dest);
}
struct platform_device *acpi_create_platform_device(struct acpi_device *adev,
struct property_entry *properties)
{
struct platform_device *pdev = NULL;
struct platform_device_info pdevinfo;
struct resource_entry *rentry;
struct list_head resource_list;
struct resource *resources = NULL;
int count;
if (adev->physical_node_count)
return NULL;
if (!acpi_match_device_ids(adev, forbidden_id_list))
return ERR_PTR(-EINVAL);
INIT_LIST_HEAD(&resource_list);
count = acpi_dev_get_resources(adev, &resource_list, NULL, NULL);
if (count < 0) {
return NULL;
} else if (count > 0) {
resources = kzalloc(count * sizeof(struct resource),
GFP_KERNEL);
if (!resources) {
dev_err(&adev->dev, "No memory for resources\n");
acpi_dev_free_resource_list(&resource_list);
return ERR_PTR(-ENOMEM);
}
count = 0;
list_for_each_entry(rentry, &resource_list, node)
acpi_platform_fill_resource(adev, rentry->res,
&resources[count++]);
acpi_dev_free_resource_list(&resource_list);
}
memset(&pdevinfo, 0, sizeof(pdevinfo));
pdevinfo.parent = adev->parent ?
acpi_get_first_physical_node(adev->parent) : NULL;
pdevinfo.name = dev_name(&adev->dev);
pdevinfo.id = -1;
pdevinfo.res = resources;
pdevinfo.num_res = count;
pdevinfo.fwnode = acpi_fwnode_handle(adev);
pdevinfo.properties = properties;
if (acpi_dma_supported(adev))
pdevinfo.dma_mask = DMA_BIT_MASK(32);
else
pdevinfo.dma_mask = 0;
pdev = platform_device_register_full(&pdevinfo);
if (IS_ERR(pdev))
dev_err(&adev->dev, "platform device creation failed: %ld\n",
PTR_ERR(pdev));
else
dev_dbg(&adev->dev, "created platform device %s\n",
dev_name(&pdev->dev));
kfree(resources);
return pdev;
}
