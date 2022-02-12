static int __init match_acpi_dev(struct device *dev, void *data)
{
struct acpi_hid_uid hid_uid = *(struct acpi_hid_uid *)data;
struct acpi_device *adev = to_acpi_device(dev);
if (acpi_match_device_ids(adev, hid_uid.hid))
return 0;
if (adev->pnp.unique_id)
return !strcmp(adev->pnp.unique_id, hid_uid.uid);
else
return !strcmp("0", hid_uid.uid);
}
static long __init parse_acpi_path(struct efi_dev_path *node,
struct device *parent, struct device **child)
{
struct acpi_hid_uid hid_uid = {};
struct device *phys_dev;
if (node->length != 12)
return -EINVAL;
sprintf(hid_uid.hid[0].id, "%c%c%c%04X",
'A' + ((node->acpi.hid >> 10) & 0x1f) - 1,
'A' + ((node->acpi.hid >> 5) & 0x1f) - 1,
'A' + ((node->acpi.hid >> 0) & 0x1f) - 1,
node->acpi.hid >> 16);
sprintf(hid_uid.uid, "%u", node->acpi.uid);
*child = bus_find_device(&acpi_bus_type, NULL, &hid_uid,
match_acpi_dev);
if (!*child)
return -ENODEV;
phys_dev = acpi_get_first_physical_node(to_acpi_device(*child));
if (phys_dev) {
get_device(phys_dev);
put_device(*child);
*child = phys_dev;
}
return 0;
}
static int __init match_pci_dev(struct device *dev, void *data)
{
unsigned int devfn = *(unsigned int *)data;
return dev_is_pci(dev) && to_pci_dev(dev)->devfn == devfn;
}
static long __init parse_pci_path(struct efi_dev_path *node,
struct device *parent, struct device **child)
{
unsigned int devfn;
if (node->length != 6)
return -EINVAL;
if (!parent)
return -EINVAL;
devfn = PCI_DEVFN(node->pci.dev, node->pci.fn);
*child = device_find_child(parent, &devfn, match_pci_dev);
if (!*child)
return -ENODEV;
return 0;
}
static long __init parse_end_path(struct efi_dev_path *node,
struct device *parent, struct device **child)
{
if (node->length != 4)
return -EINVAL;
if (node->sub_type != EFI_DEV_END_INSTANCE &&
node->sub_type != EFI_DEV_END_ENTIRE)
return -EINVAL;
if (!parent)
return -ENODEV;
*child = get_device(parent);
return node->sub_type;
}
struct device * __init efi_get_device_by_path(struct efi_dev_path **node,
size_t *len)
{
struct device *parent = NULL, *child;
long ret = 0;
if (!*len)
return NULL;
while (!ret) {
if (*len < 4 || *len < (*node)->length)
ret = -EINVAL;
else if ((*node)->type == EFI_DEV_ACPI &&
(*node)->sub_type == EFI_DEV_BASIC_ACPI)
ret = parse_acpi_path(*node, parent, &child);
else if ((*node)->type == EFI_DEV_HW &&
(*node)->sub_type == EFI_DEV_PCI)
ret = parse_pci_path(*node, parent, &child);
else if (((*node)->type == EFI_DEV_END_PATH ||
(*node)->type == EFI_DEV_END_PATH2))
ret = parse_end_path(*node, parent, &child);
else
ret = -ENOTSUPP;
put_device(parent);
if (ret < 0)
return ERR_PTR(ret);
parent = child;
*node = (void *)*node + (*node)->length;
*len -= (*node)->length;
}
if (ret == EFI_DEV_END_ENTIRE)
*len = 0;
return child;
}
