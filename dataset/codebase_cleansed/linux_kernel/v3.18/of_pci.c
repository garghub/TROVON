static inline int __of_pci_pci_compare(struct device_node *node,
unsigned int data)
{
int devfn;
devfn = of_pci_get_devfn(node);
if (devfn < 0)
return 0;
return devfn == data;
}
struct device_node *of_pci_find_child_device(struct device_node *parent,
unsigned int devfn)
{
struct device_node *node, *node2;
for_each_child_of_node(parent, node) {
if (__of_pci_pci_compare(node, devfn))
return node;
if (!strcmp(node->name, "multifunc-device")) {
for_each_child_of_node(node, node2) {
if (__of_pci_pci_compare(node2, devfn)) {
of_node_put(node);
return node2;
}
}
}
}
return NULL;
}
int of_pci_get_devfn(struct device_node *np)
{
unsigned int size;
const __be32 *reg;
reg = of_get_property(np, "reg", &size);
if (!reg || size < 5 * sizeof(__be32))
return -EINVAL;
return (be32_to_cpup(reg) >> 8) & 0xff;
}
int of_pci_parse_bus_range(struct device_node *node, struct resource *res)
{
const __be32 *values;
int len;
values = of_get_property(node, "bus-range", &len);
if (!values || len < sizeof(*values) * 2)
return -EINVAL;
res->name = node->name;
res->start = be32_to_cpup(values++);
res->end = be32_to_cpup(values);
res->flags = IORESOURCE_BUS;
return 0;
}
int of_get_pci_domain_nr(struct device_node *node)
{
const __be32 *value;
int len;
u16 domain;
value = of_get_property(node, "linux,pci-domain", &len);
if (!value || len < sizeof(*value))
return -EINVAL;
domain = (u16)be32_to_cpup(value);
return domain;
}
int of_pci_get_host_bridge_resources(struct device_node *dev,
unsigned char busno, unsigned char bus_max,
struct list_head *resources, resource_size_t *io_base)
{
struct resource *res;
struct resource *bus_range;
struct of_pci_range range;
struct of_pci_range_parser parser;
char range_type[4];
int err;
if (io_base)
*io_base = (resource_size_t)OF_BAD_ADDR;
bus_range = kzalloc(sizeof(*bus_range), GFP_KERNEL);
if (!bus_range)
return -ENOMEM;
pr_info("PCI host bridge %s ranges:\n", dev->full_name);
err = of_pci_parse_bus_range(dev, bus_range);
if (err) {
bus_range->start = busno;
bus_range->end = bus_max;
bus_range->flags = IORESOURCE_BUS;
pr_info(" No bus range found for %s, using %pR\n",
dev->full_name, bus_range);
} else {
if (bus_range->end > bus_range->start + bus_max)
bus_range->end = bus_range->start + bus_max;
}
pci_add_resource(resources, bus_range);
err = of_pci_range_parser_init(&parser, dev);
if (err)
goto parse_failed;
pr_debug("Parsing ranges property...\n");
for_each_of_pci_range(&parser, &range) {
if ((range.flags & IORESOURCE_TYPE_BITS) == IORESOURCE_IO)
snprintf(range_type, 4, " IO");
else if ((range.flags & IORESOURCE_TYPE_BITS) == IORESOURCE_MEM)
snprintf(range_type, 4, "MEM");
else
snprintf(range_type, 4, "err");
pr_info(" %s %#010llx..%#010llx -> %#010llx\n", range_type,
range.cpu_addr, range.cpu_addr + range.size - 1,
range.pci_addr);
if (range.cpu_addr == OF_BAD_ADDR || range.size == 0)
continue;
res = kzalloc(sizeof(struct resource), GFP_KERNEL);
if (!res) {
err = -ENOMEM;
goto parse_failed;
}
err = of_pci_range_to_resource(&range, dev, res);
if (err)
goto conversion_failed;
if (resource_type(res) == IORESOURCE_IO) {
if (!io_base) {
pr_err("I/O range found for %s. Please provide an io_base pointer to save CPU base address\n",
dev->full_name);
err = -EINVAL;
goto conversion_failed;
}
if (*io_base != (resource_size_t)OF_BAD_ADDR)
pr_warn("More than one I/O resource converted for %s. CPU base address for old range lost!\n",
dev->full_name);
*io_base = range.cpu_addr;
}
pci_add_resource_offset(resources, res, res->start - range.pci_addr);
}
return 0;
conversion_failed:
kfree(res);
parse_failed:
pci_free_resource_list(resources);
return err;
}
int of_pci_msi_chip_add(struct msi_chip *chip)
{
if (!of_property_read_bool(chip->of_node, "msi-controller"))
return -EINVAL;
mutex_lock(&of_pci_msi_chip_mutex);
list_add(&chip->list, &of_pci_msi_chip_list);
mutex_unlock(&of_pci_msi_chip_mutex);
return 0;
}
void of_pci_msi_chip_remove(struct msi_chip *chip)
{
mutex_lock(&of_pci_msi_chip_mutex);
list_del(&chip->list);
mutex_unlock(&of_pci_msi_chip_mutex);
}
struct msi_chip *of_pci_find_msi_chip_by_node(struct device_node *of_node)
{
struct msi_chip *c;
mutex_lock(&of_pci_msi_chip_mutex);
list_for_each_entry(c, &of_pci_msi_chip_list, list) {
if (c->of_node == of_node) {
mutex_unlock(&of_pci_msi_chip_mutex);
return c;
}
}
mutex_unlock(&of_pci_msi_chip_mutex);
return NULL;
}
