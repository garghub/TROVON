static inline int __of_pci_pci_compare(struct device_node *node,
unsigned int devfn)
{
unsigned int size;
const __be32 *reg = of_get_property(node, "reg", &size);
if (!reg || size < 5 * sizeof(__be32))
return 0;
return ((be32_to_cpup(&reg[0]) >> 8) & 0xff) == devfn;
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
