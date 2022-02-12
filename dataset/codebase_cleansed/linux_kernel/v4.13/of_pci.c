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
int of_pci_get_max_link_speed(struct device_node *node)
{
u32 max_link_speed;
if (of_property_read_u32(node, "max-link-speed", &max_link_speed) ||
max_link_speed > 4)
return -EINVAL;
return max_link_speed;
}
void of_pci_check_probe_only(void)
{
u32 val;
int ret;
ret = of_property_read_u32(of_chosen, "linux,pci-probe-only", &val);
if (ret) {
if (ret == -ENODATA || ret == -EOVERFLOW)
pr_warn("linux,pci-probe-only without valid value, ignoring\n");
return;
}
if (val)
pci_add_flags(PCI_PROBE_ONLY);
else
pci_clear_flags(PCI_PROBE_ONLY);
pr_info("PROBE_ONLY %sabled\n", val ? "en" : "dis");
}
int of_pci_get_host_bridge_resources(struct device_node *dev,
unsigned char busno, unsigned char bus_max,
struct list_head *resources, resource_size_t *io_base)
{
struct resource_entry *window;
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
pr_info("host bridge %s ranges:\n", dev->full_name);
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
if (err) {
kfree(res);
continue;
}
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
resource_list_for_each_entry(window, resources)
kfree(window->res);
pci_free_resource_list(resources);
return err;
}
int of_pci_map_rid(struct device_node *np, u32 rid,
const char *map_name, const char *map_mask_name,
struct device_node **target, u32 *id_out)
{
u32 map_mask, masked_rid;
int map_len;
const __be32 *map = NULL;
if (!np || !map_name || (!target && !id_out))
return -EINVAL;
map = of_get_property(np, map_name, &map_len);
if (!map) {
if (target)
return -ENODEV;
*id_out = rid;
return 0;
}
if (!map_len || map_len % (4 * sizeof(*map))) {
pr_err("%s: Error: Bad %s length: %d\n", np->full_name,
map_name, map_len);
return -EINVAL;
}
map_mask = 0xffffffff;
if (map_mask_name)
of_property_read_u32(np, map_mask_name, &map_mask);
masked_rid = map_mask & rid;
for ( ; map_len > 0; map_len -= 4 * sizeof(*map), map += 4) {
struct device_node *phandle_node;
u32 rid_base = be32_to_cpup(map + 0);
u32 phandle = be32_to_cpup(map + 1);
u32 out_base = be32_to_cpup(map + 2);
u32 rid_len = be32_to_cpup(map + 3);
if (rid_base & ~map_mask) {
pr_err("%s: Invalid %s translation - %s-mask (0x%x) ignores rid-base (0x%x)\n",
np->full_name, map_name, map_name,
map_mask, rid_base);
return -EFAULT;
}
if (masked_rid < rid_base || masked_rid >= rid_base + rid_len)
continue;
phandle_node = of_find_node_by_phandle(phandle);
if (!phandle_node)
return -ENODEV;
if (target) {
if (*target)
of_node_put(phandle_node);
else
*target = phandle_node;
if (*target != phandle_node)
continue;
}
if (id_out)
*id_out = masked_rid - rid_base + out_base;
pr_debug("%s: %s, using mask %08x, rid-base: %08x, out-base: %08x, length: %08x, rid: %08x -> %08x\n",
np->full_name, map_name, map_mask, rid_base, out_base,
rid_len, rid, *id_out);
return 0;
}
pr_err("%s: Invalid %s translation - no match for rid 0x%x on %s\n",
np->full_name, map_name, rid,
target && *target ? (*target)->full_name : "any target");
return -EFAULT;
}
