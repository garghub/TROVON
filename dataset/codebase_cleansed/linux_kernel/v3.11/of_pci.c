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
