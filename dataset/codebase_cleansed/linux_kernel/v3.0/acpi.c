static int __init set_use_crs(const struct dmi_system_id *id)
{
pci_use_crs = true;
return 0;
}
void __init pci_acpi_crs_quirks(void)
{
int year;
if (dmi_get_date(DMI_BIOS_DATE, &year, NULL, NULL) && year < 2008)
pci_use_crs = false;
dmi_check_system(pci_use_crs_table);
if (pci_probe & PCI_ROOT_NO_CRS)
pci_use_crs = false;
else if (pci_probe & PCI_USE__CRS)
pci_use_crs = true;
printk(KERN_INFO "PCI: %s host bridge windows from ACPI; "
"if necessary, use \"pci=%s\" and report a bug\n",
pci_use_crs ? "Using" : "Ignoring",
pci_use_crs ? "nocrs" : "use_crs");
}
static acpi_status
resource_to_addr(struct acpi_resource *resource,
struct acpi_resource_address64 *addr)
{
acpi_status status;
struct acpi_resource_memory24 *memory24;
struct acpi_resource_memory32 *memory32;
struct acpi_resource_fixed_memory32 *fixed_memory32;
memset(addr, 0, sizeof(*addr));
switch (resource->type) {
case ACPI_RESOURCE_TYPE_MEMORY24:
memory24 = &resource->data.memory24;
addr->resource_type = ACPI_MEMORY_RANGE;
addr->minimum = memory24->minimum;
addr->address_length = memory24->address_length;
addr->maximum = addr->minimum + addr->address_length - 1;
return AE_OK;
case ACPI_RESOURCE_TYPE_MEMORY32:
memory32 = &resource->data.memory32;
addr->resource_type = ACPI_MEMORY_RANGE;
addr->minimum = memory32->minimum;
addr->address_length = memory32->address_length;
addr->maximum = addr->minimum + addr->address_length - 1;
return AE_OK;
case ACPI_RESOURCE_TYPE_FIXED_MEMORY32:
fixed_memory32 = &resource->data.fixed_memory32;
addr->resource_type = ACPI_MEMORY_RANGE;
addr->minimum = fixed_memory32->address;
addr->address_length = fixed_memory32->address_length;
addr->maximum = addr->minimum + addr->address_length - 1;
return AE_OK;
case ACPI_RESOURCE_TYPE_ADDRESS16:
case ACPI_RESOURCE_TYPE_ADDRESS32:
case ACPI_RESOURCE_TYPE_ADDRESS64:
status = acpi_resource_to_address64(resource, addr);
if (ACPI_SUCCESS(status) &&
(addr->resource_type == ACPI_MEMORY_RANGE ||
addr->resource_type == ACPI_IO_RANGE) &&
addr->address_length > 0) {
return AE_OK;
}
break;
}
return AE_ERROR;
}
static acpi_status
count_resource(struct acpi_resource *acpi_res, void *data)
{
struct pci_root_info *info = data;
struct acpi_resource_address64 addr;
acpi_status status;
status = resource_to_addr(acpi_res, &addr);
if (ACPI_SUCCESS(status))
info->res_num++;
return AE_OK;
}
static acpi_status
setup_resource(struct acpi_resource *acpi_res, void *data)
{
struct pci_root_info *info = data;
struct resource *res;
struct acpi_resource_address64 addr;
acpi_status status;
unsigned long flags;
u64 start, end;
status = resource_to_addr(acpi_res, &addr);
if (!ACPI_SUCCESS(status))
return AE_OK;
if (addr.resource_type == ACPI_MEMORY_RANGE) {
flags = IORESOURCE_MEM;
if (addr.info.mem.caching == ACPI_PREFETCHABLE_MEMORY)
flags |= IORESOURCE_PREFETCH;
} else if (addr.resource_type == ACPI_IO_RANGE) {
flags = IORESOURCE_IO;
} else
return AE_OK;
start = addr.minimum + addr.translation_offset;
end = addr.maximum + addr.translation_offset;
res = &info->res[info->res_num];
res->name = info->name;
res->flags = flags;
res->start = start;
res->end = end;
res->child = NULL;
if (!pci_use_crs) {
dev_printk(KERN_DEBUG, &info->bridge->dev,
"host bridge window %pR (ignored)\n", res);
return AE_OK;
}
info->res_num++;
if (addr.translation_offset)
dev_info(&info->bridge->dev, "host bridge window %pR "
"(PCI address [%#llx-%#llx])\n",
res, res->start - addr.translation_offset,
res->end - addr.translation_offset);
else
dev_info(&info->bridge->dev, "host bridge window %pR\n", res);
return AE_OK;
}
static bool resource_contains(struct resource *res, resource_size_t point)
{
if (res->start <= point && point <= res->end)
return true;
return false;
}
static void coalesce_windows(struct pci_root_info *info, unsigned long type)
{
int i, j;
struct resource *res1, *res2;
for (i = 0; i < info->res_num; i++) {
res1 = &info->res[i];
if (!(res1->flags & type))
continue;
for (j = i + 1; j < info->res_num; j++) {
res2 = &info->res[j];
if (!(res2->flags & type))
continue;
if (resource_contains(res1, res2->start) ||
resource_contains(res1, res2->end) ||
resource_contains(res2, res1->start) ||
resource_contains(res2, res1->end)) {
res1->start = min(res1->start, res2->start);
res1->end = max(res1->end, res2->end);
dev_info(&info->bridge->dev,
"host bridge window expanded to %pR; %pR ignored\n",
res1, res2);
res2->flags = 0;
}
}
}
}
static void add_resources(struct pci_root_info *info)
{
int i;
struct resource *res, *root, *conflict;
if (!pci_use_crs)
return;
coalesce_windows(info, IORESOURCE_MEM);
coalesce_windows(info, IORESOURCE_IO);
for (i = 0; i < info->res_num; i++) {
res = &info->res[i];
if (res->flags & IORESOURCE_MEM)
root = &iomem_resource;
else if (res->flags & IORESOURCE_IO)
root = &ioport_resource;
else
continue;
conflict = insert_resource_conflict(root, res);
if (conflict)
dev_err(&info->bridge->dev,
"address space collision: host bridge window %pR "
"conflicts with %s %pR\n",
res, conflict->name, conflict);
else
pci_bus_add_resource(info->bus, res, 0);
}
}
static void
get_current_resources(struct acpi_device *device, int busnum,
int domain, struct pci_bus *bus)
{
struct pci_root_info info;
size_t size;
if (pci_use_crs)
pci_bus_remove_resources(bus);
info.bridge = device;
info.bus = bus;
info.res_num = 0;
acpi_walk_resources(device->handle, METHOD_NAME__CRS, count_resource,
&info);
if (!info.res_num)
return;
size = sizeof(*info.res) * info.res_num;
info.res = kmalloc(size, GFP_KERNEL);
if (!info.res)
goto res_alloc_fail;
info.name = kasprintf(GFP_KERNEL, "PCI Bus %04x:%02x", domain, busnum);
if (!info.name)
goto name_alloc_fail;
info.res_num = 0;
acpi_walk_resources(device->handle, METHOD_NAME__CRS, setup_resource,
&info);
add_resources(&info);
return;
name_alloc_fail:
kfree(info.res);
res_alloc_fail:
return;
}
struct pci_bus * __devinit pci_acpi_scan_root(struct acpi_pci_root *root)
{
struct acpi_device *device = root->device;
int domain = root->segment;
int busnum = root->secondary.start;
struct pci_bus *bus;
struct pci_sysdata *sd;
int node;
#ifdef CONFIG_ACPI_NUMA
int pxm;
#endif
if (domain && !pci_domains_supported) {
printk(KERN_WARNING "pci_bus %04x:%02x: "
"ignored (multiple domains not supported)\n",
domain, busnum);
return NULL;
}
node = -1;
#ifdef CONFIG_ACPI_NUMA
pxm = acpi_get_pxm(device->handle);
if (pxm >= 0)
node = pxm_to_node(pxm);
if (node != -1)
set_mp_bus_to_node(busnum, node);
else
#endif
node = get_mp_bus_to_node(busnum);
if (node != -1 && !node_online(node))
node = -1;
sd = kzalloc(sizeof(*sd), GFP_KERNEL);
if (!sd) {
printk(KERN_WARNING "pci_bus %04x:%02x: "
"ignored (out of memory)\n", domain, busnum);
return NULL;
}
sd->domain = domain;
sd->node = node;
bus = pci_find_bus(domain, busnum);
if (bus) {
memcpy(bus->sysdata, sd, sizeof(*sd));
kfree(sd);
} else {
bus = pci_create_bus(NULL, busnum, &pci_root_ops, sd);
if (bus) {
get_current_resources(device, busnum, domain, bus);
bus->subordinate = pci_scan_child_bus(bus);
}
}
if (!bus)
kfree(sd);
if (bus && node != -1) {
#ifdef CONFIG_ACPI_NUMA
if (pxm >= 0)
dev_printk(KERN_DEBUG, &bus->dev,
"on NUMA node %d (pxm %d)\n", node, pxm);
#else
dev_printk(KERN_DEBUG, &bus->dev, "on NUMA node %d\n", node);
#endif
}
return bus;
}
int __init pci_acpi_init(void)
{
struct pci_dev *dev = NULL;
if (acpi_noirq)
return -ENODEV;
printk(KERN_INFO "PCI: Using ACPI for IRQ routing\n");
acpi_irq_penalty_init();
pcibios_enable_irq = acpi_pci_irq_enable;
pcibios_disable_irq = acpi_pci_irq_disable;
x86_init.pci.init_irq = x86_init_noop;
if (pci_routeirq) {
printk(KERN_INFO "PCI: Routing PCI interrupts for all devices because \"pci=routeirq\" specified\n");
for_each_pci_dev(dev)
acpi_pci_irq_enable(dev);
}
return 0;
}
