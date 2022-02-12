int acpi_create_platform_device(struct acpi_device *adev,
const struct acpi_device_id *id)
{
struct platform_device *pdev = NULL;
struct acpi_device *acpi_parent;
struct platform_device_info pdevinfo;
struct resource_list_entry *rentry;
struct list_head resource_list;
struct resource *resources = NULL;
int count;
if (adev->physical_node_count)
return 0;
INIT_LIST_HEAD(&resource_list);
count = acpi_dev_get_resources(adev, &resource_list, NULL, NULL);
if (count < 0) {
return 0;
} else if (count > 0) {
resources = kmalloc(count * sizeof(struct resource),
GFP_KERNEL);
if (!resources) {
dev_err(&adev->dev, "No memory for resources\n");
acpi_dev_free_resource_list(&resource_list);
return -ENOMEM;
}
count = 0;
list_for_each_entry(rentry, &resource_list, node)
resources[count++] = rentry->res;
acpi_dev_free_resource_list(&resource_list);
}
memset(&pdevinfo, 0, sizeof(pdevinfo));
pdevinfo.parent = NULL;
acpi_parent = adev->parent;
if (acpi_parent) {
struct acpi_device_physical_node *entry;
struct list_head *list;
mutex_lock(&acpi_parent->physical_node_lock);
list = &acpi_parent->physical_node_list;
if (!list_empty(list)) {
entry = list_first_entry(list,
struct acpi_device_physical_node,
node);
pdevinfo.parent = entry->dev;
}
mutex_unlock(&acpi_parent->physical_node_lock);
}
pdevinfo.name = dev_name(&adev->dev);
pdevinfo.id = -1;
pdevinfo.res = resources;
pdevinfo.num_res = count;
pdevinfo.acpi_node.companion = adev;
pdev = platform_device_register_full(&pdevinfo);
if (IS_ERR(pdev)) {
dev_err(&adev->dev, "platform device creation failed: %ld\n",
PTR_ERR(pdev));
pdev = NULL;
} else {
dev_dbg(&adev->dev, "created platform device %s\n",
dev_name(&pdev->dev));
}
kfree(resources);
return 1;
}
void __init acpi_platform_init(void)
{
acpi_scan_add_handler(&platform_handler);
}
