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
