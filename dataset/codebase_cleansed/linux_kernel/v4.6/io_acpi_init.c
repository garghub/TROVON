static long
sal_ioif_init(u64 *result)
{
struct ia64_sal_retval isrv = {0,0,0,0};
SAL_CALL_NOLOCK(isrv,
SN_SAL_IOIF_INIT, 0, 0, 0, 0, 0, 0, 0);
*result = isrv.v0;
return isrv.status;
}
static acpi_status __init
sn_acpi_hubdev_init(acpi_handle handle, u32 depth, void *context, void **ret)
{
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer name_buffer = { ACPI_ALLOCATE_BUFFER, NULL };
u64 addr;
struct hubdev_info *hubdev;
struct hubdev_info *hubdev_ptr;
int i;
u64 nasid;
struct acpi_resource *resource;
acpi_status status;
struct acpi_resource_vendor_typed *vendor;
extern void sn_common_hubdev_init(struct hubdev_info *);
status = acpi_get_vendor_resource(handle, METHOD_NAME__CRS,
&sn_uuid, &buffer);
if (ACPI_FAILURE(status)) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR
"sn_acpi_hubdev_init: acpi_get_vendor_resource() "
"(0x%x) failed for: %s\n", status,
(char *)name_buffer.pointer);
kfree(name_buffer.pointer);
return AE_OK;
}
resource = buffer.pointer;
vendor = &resource->data.vendor_typed;
if ((vendor->byte_length - sizeof(struct acpi_vendor_uuid)) !=
sizeof(struct hubdev_info *)) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR
"sn_acpi_hubdev_init: Invalid vendor data length: "
"%d for: %s\n",
vendor->byte_length, (char *)name_buffer.pointer);
kfree(name_buffer.pointer);
goto exit;
}
memcpy(&addr, vendor->byte_data, sizeof(struct hubdev_info *));
hubdev_ptr = __va((struct hubdev_info *) addr);
nasid = hubdev_ptr->hdi_nasid;
i = nasid_to_cnodeid(nasid);
hubdev = (struct hubdev_info *)(NODEPDA(i)->pdinfo);
*hubdev = *hubdev_ptr;
sn_common_hubdev_init(hubdev);
exit:
kfree(buffer.pointer);
return AE_OK;
}
static struct pcibus_bussoft *
sn_get_bussoft_ptr(struct pci_bus *bus)
{
u64 addr;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer name_buffer = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_handle handle;
struct pcibus_bussoft *prom_bussoft_ptr;
struct acpi_resource *resource;
acpi_status status;
struct acpi_resource_vendor_typed *vendor;
handle = acpi_device_handle(PCI_CONTROLLER(bus)->companion);
status = acpi_get_vendor_resource(handle, METHOD_NAME__CRS,
&sn_uuid, &buffer);
if (ACPI_FAILURE(status)) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR "%s: "
"acpi_get_vendor_resource() failed (0x%x) for: %s\n",
__func__, status, (char *)name_buffer.pointer);
kfree(name_buffer.pointer);
return NULL;
}
resource = buffer.pointer;
vendor = &resource->data.vendor_typed;
if ((vendor->byte_length - sizeof(struct acpi_vendor_uuid)) !=
sizeof(struct pcibus_bussoft *)) {
printk(KERN_ERR
"%s: Invalid vendor data length %d\n",
__func__, vendor->byte_length);
kfree(buffer.pointer);
return NULL;
}
memcpy(&addr, vendor->byte_data, sizeof(struct pcibus_bussoft *));
prom_bussoft_ptr = __va((struct pcibus_bussoft *) addr);
kfree(buffer.pointer);
return prom_bussoft_ptr;
}
static int
sn_extract_device_info(acpi_handle handle, struct pcidev_info **pcidev_info,
struct sn_irq_info **sn_irq_info)
{
u64 addr;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer name_buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct sn_irq_info *irq_info, *irq_info_prom;
struct pcidev_info *pcidev_ptr, *pcidev_prom_ptr;
struct acpi_resource *resource;
int ret = 0;
acpi_status status;
struct acpi_resource_vendor_typed *vendor;
status = acpi_get_vendor_resource(handle, METHOD_NAME__CRS,
&sn_uuid, &buffer);
if (ACPI_FAILURE(status)) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR
"%s: acpi_get_vendor_resource() failed (0x%x) for: %s\n",
__func__, status, (char *)name_buffer.pointer);
kfree(name_buffer.pointer);
return 1;
}
resource = buffer.pointer;
vendor = &resource->data.vendor_typed;
if ((vendor->byte_length - sizeof(struct acpi_vendor_uuid)) !=
sizeof(struct pci_devdev_info *)) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR
"%s: Invalid vendor data length: %d for: %s\n",
__func__, vendor->byte_length,
(char *)name_buffer.pointer);
kfree(name_buffer.pointer);
ret = 1;
goto exit;
}
pcidev_ptr = kzalloc(sizeof(struct pcidev_info), GFP_KERNEL);
if (!pcidev_ptr)
panic("%s: Unable to alloc memory for pcidev_info", __func__);
memcpy(&addr, vendor->byte_data, sizeof(struct pcidev_info *));
pcidev_prom_ptr = __va(addr);
memcpy(pcidev_ptr, pcidev_prom_ptr, sizeof(struct pcidev_info));
irq_info = kzalloc(sizeof(struct sn_irq_info), GFP_KERNEL);
if (!irq_info)
panic("%s: Unable to alloc memory for sn_irq_info", __func__);
if (pcidev_ptr->pdi_sn_irq_info) {
irq_info_prom = __va(pcidev_ptr->pdi_sn_irq_info);
memcpy(irq_info, irq_info_prom, sizeof(struct sn_irq_info));
}
*pcidev_info = pcidev_ptr;
*sn_irq_info = irq_info;
exit:
kfree(buffer.pointer);
return ret;
}
static unsigned int
get_host_devfn(acpi_handle device_handle, acpi_handle rootbus_handle)
{
unsigned long long adr;
acpi_handle child;
unsigned int devfn;
int function;
acpi_handle parent;
int slot;
acpi_status status;
struct acpi_buffer name_buffer = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_get_name(device_handle, ACPI_FULL_PATHNAME, &name_buffer);
child = device_handle;
while (child) {
status = acpi_get_parent(child, &parent);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR "%s: acpi_get_parent() failed "
"(0x%x) for: %s\n", __func__, status,
(char *)name_buffer.pointer);
panic("%s: Unable to find host devfn\n", __func__);
}
if (parent == rootbus_handle)
break;
child = parent;
}
if (!child) {
printk(KERN_ERR "%s: Unable to find root bus for: %s\n",
__func__, (char *)name_buffer.pointer);
BUG();
}
status = acpi_evaluate_integer(child, METHOD_NAME__ADR, NULL, &adr);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR "%s: Unable to get _ADR (0x%x) for: %s\n",
__func__, status, (char *)name_buffer.pointer);
panic("%s: Unable to find host devfn\n", __func__);
}
kfree(name_buffer.pointer);
slot = (adr >> 16) & 0xffff;
function = adr & 0xffff;
devfn = PCI_DEVFN(slot, function);
return devfn;
}
static acpi_status
find_matching_device(acpi_handle handle, u32 lvl, void *context, void **rv)
{
unsigned long long bbn = -1;
unsigned long long adr;
acpi_handle parent = NULL;
acpi_status status;
unsigned int devfn;
int function;
int slot;
struct sn_pcidev_match *info = context;
struct acpi_buffer name_buffer = { ACPI_ALLOCATE_BUFFER, NULL };
status = acpi_evaluate_integer(handle, METHOD_NAME__ADR, NULL,
&adr);
if (ACPI_SUCCESS(status)) {
status = acpi_get_parent(handle, &parent);
if (ACPI_FAILURE(status)) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR
"%s: acpi_get_parent() failed (0x%x) for: %s\n",
__func__, status, (char *)name_buffer.pointer);
kfree(name_buffer.pointer);
return AE_OK;
}
status = acpi_evaluate_integer(parent, METHOD_NAME__BBN,
NULL, &bbn);
if (ACPI_FAILURE(status)) {
acpi_get_name(handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR
"%s: Failed to find _BBN in parent of: %s\n",
__func__, (char *)name_buffer.pointer);
kfree(name_buffer.pointer);
return AE_OK;
}
slot = (adr >> 16) & 0xffff;
function = adr & 0xffff;
devfn = PCI_DEVFN(slot, function);
if ((info->devfn == devfn) && (info->bus == bbn)) {
info->handle = handle;
return 1;
}
}
return AE_OK;
}
int
sn_acpi_get_pcidev_info(struct pci_dev *dev, struct pcidev_info **pcidev_info,
struct sn_irq_info **sn_irq_info)
{
unsigned int host_devfn;
struct sn_pcidev_match pcidev_match;
acpi_handle rootbus_handle;
unsigned long long segment;
acpi_status status;
struct acpi_buffer name_buffer = { ACPI_ALLOCATE_BUFFER, NULL };
rootbus_handle = acpi_device_handle(PCI_CONTROLLER(dev)->companion);
status = acpi_evaluate_integer(rootbus_handle, METHOD_NAME__SEG, NULL,
&segment);
if (ACPI_SUCCESS(status)) {
if (segment != pci_domain_nr(dev)) {
acpi_get_name(rootbus_handle, ACPI_FULL_PATHNAME,
&name_buffer);
printk(KERN_ERR
"%s: Segment number mismatch, 0x%llx vs 0x%x for: %s\n",
__func__, segment, pci_domain_nr(dev),
(char *)name_buffer.pointer);
kfree(name_buffer.pointer);
return 1;
}
} else {
acpi_get_name(rootbus_handle, ACPI_FULL_PATHNAME, &name_buffer);
printk(KERN_ERR "%s: Unable to get __SEG from: %s\n",
__func__, (char *)name_buffer.pointer);
kfree(name_buffer.pointer);
return 1;
}
pcidev_match.bus = dev->bus->number;
pcidev_match.devfn = dev->devfn;
pcidev_match.handle = NULL;
acpi_walk_namespace(ACPI_TYPE_DEVICE, rootbus_handle, ACPI_UINT32_MAX,
find_matching_device, NULL, &pcidev_match, NULL);
if (!pcidev_match.handle) {
printk(KERN_ERR
"%s: Could not find matching ACPI device for %s.\n",
__func__, pci_name(dev));
return 1;
}
if (sn_extract_device_info(pcidev_match.handle, pcidev_info, sn_irq_info))
return 1;
host_devfn = get_host_devfn(pcidev_match.handle, rootbus_handle);
(*pcidev_info)->pdi_slot_host_handle =
((unsigned long) pci_domain_nr(dev) << 40) |
host_devfn;
return 0;
}
void
sn_acpi_slot_fixup(struct pci_dev *dev)
{
void __iomem *addr;
struct pcidev_info *pcidev_info = NULL;
struct sn_irq_info *sn_irq_info = NULL;
struct resource *res;
size_t size;
if (sn_acpi_get_pcidev_info(dev, &pcidev_info, &sn_irq_info)) {
panic("%s: Failure obtaining pcidev_info for %s\n",
__func__, pci_name(dev));
}
if (pcidev_info->pdi_pio_mapped_addr[PCI_ROM_RESOURCE]) {
size = pci_resource_len(dev, PCI_ROM_RESOURCE);
res = &dev->resource[PCI_ROM_RESOURCE];
pci_disable_rom(dev);
if (res->parent)
release_resource(res);
res->start = pcidev_info->pdi_pio_mapped_addr[PCI_ROM_RESOURCE];
res->end = res->start + size - 1;
res->flags = IORESOURCE_MEM | IORESOURCE_ROM_SHADOW |
IORESOURCE_PCI_FIXED;
}
sn_pci_fixup_slot(dev, pcidev_info, sn_irq_info);
}
void
sn_acpi_bus_fixup(struct pci_bus *bus)
{
struct pci_dev *pci_dev = NULL;
struct pcibus_bussoft *prom_bussoft_ptr;
if (!bus->parent) {
prom_bussoft_ptr = sn_get_bussoft_ptr(bus);
if (prom_bussoft_ptr == NULL) {
printk(KERN_ERR
"%s: 0x%04x:0x%02x Unable to "
"obtain prom_bussoft_ptr\n",
__func__, pci_domain_nr(bus), bus->number);
return;
}
sn_common_bus_fixup(bus, prom_bussoft_ptr);
}
list_for_each_entry(pci_dev, &bus->devices, bus_list) {
sn_acpi_slot_fixup(pci_dev);
}
}
void __init
sn_io_acpi_init(void)
{
u64 result;
long status;
acpi_irq_model = ACPI_IRQ_MODEL_PLATFORM;
acpi_get_devices("SGIHUB", sn_acpi_hubdev_init, NULL, NULL);
acpi_get_devices("SGITIO", sn_acpi_hubdev_init, NULL, NULL);
status = sal_ioif_init(&result);
if (status || result)
panic("sal_ioif_init failed: [%lx] %s\n",
status, ia64_sal_strerror(status));
}
