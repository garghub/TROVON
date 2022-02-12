static void __iomem *gen_pci_map_cfg_bus_cam(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct pci_sys_data *sys = bus->sysdata;
struct gen_pci *pci = sys->private_data;
resource_size_t idx = bus->number - pci->cfg.bus_range->start;
return pci->cfg.win[idx] + ((devfn << 8) | where);
}
static void __iomem *gen_pci_map_cfg_bus_ecam(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct pci_sys_data *sys = bus->sysdata;
struct gen_pci *pci = sys->private_data;
resource_size_t idx = bus->number - pci->cfg.bus_range->start;
return pci->cfg.win[idx] + ((devfn << 12) | where);
}
static void gen_pci_release_of_pci_ranges(struct gen_pci *pci)
{
pci_free_resource_list(&pci->resources);
}
static int gen_pci_parse_request_of_pci_ranges(struct gen_pci *pci)
{
int err, res_valid = 0;
struct device *dev = pci->host.dev.parent;
struct device_node *np = dev->of_node;
resource_size_t iobase;
struct resource_entry *win;
err = of_pci_get_host_bridge_resources(np, 0, 0xff, &pci->resources,
&iobase);
if (err)
return err;
resource_list_for_each_entry(win, &pci->resources) {
struct resource *parent, *res = win->res;
switch (resource_type(res)) {
case IORESOURCE_IO:
parent = &ioport_resource;
err = pci_remap_iospace(res, iobase);
if (err) {
dev_warn(dev, "error %d: failed to map resource %pR\n",
err, res);
continue;
}
break;
case IORESOURCE_MEM:
parent = &iomem_resource;
res_valid |= !(res->flags & IORESOURCE_PREFETCH);
break;
case IORESOURCE_BUS:
pci->cfg.bus_range = res;
default:
continue;
}
err = devm_request_resource(dev, parent, res);
if (err)
goto out_release_res;
}
if (!res_valid) {
dev_err(dev, "non-prefetchable memory resource required\n");
err = -EINVAL;
goto out_release_res;
}
return 0;
out_release_res:
gen_pci_release_of_pci_ranges(pci);
return err;
}
static int gen_pci_parse_map_cfg_windows(struct gen_pci *pci)
{
int err;
u8 bus_max;
resource_size_t busn;
struct resource *bus_range;
struct device *dev = pci->host.dev.parent;
struct device_node *np = dev->of_node;
err = of_address_to_resource(np, 0, &pci->cfg.res);
if (err) {
dev_err(dev, "missing \"reg\" property\n");
return err;
}
bus_max = pci->cfg.bus_range->start +
(resource_size(&pci->cfg.res) >> pci->cfg.ops->bus_shift) - 1;
pci->cfg.bus_range->end = min_t(resource_size_t,
pci->cfg.bus_range->end, bus_max);
pci->cfg.win = devm_kcalloc(dev, resource_size(pci->cfg.bus_range),
sizeof(*pci->cfg.win), GFP_KERNEL);
if (!pci->cfg.win)
return -ENOMEM;
if (!devm_request_mem_region(dev, pci->cfg.res.start,
resource_size(&pci->cfg.res),
"Configuration Space"))
return -ENOMEM;
bus_range = pci->cfg.bus_range;
for (busn = bus_range->start; busn <= bus_range->end; ++busn) {
u32 idx = busn - bus_range->start;
u32 sz = 1 << pci->cfg.ops->bus_shift;
pci->cfg.win[idx] = devm_ioremap(dev,
pci->cfg.res.start + busn * sz,
sz);
if (!pci->cfg.win[idx])
return -ENOMEM;
}
return 0;
}
static int gen_pci_setup(int nr, struct pci_sys_data *sys)
{
struct gen_pci *pci = sys->private_data;
list_splice_init(&pci->resources, &sys->resources);
return 1;
}
static int gen_pci_probe(struct platform_device *pdev)
{
int err;
const char *type;
const struct of_device_id *of_id;
const int *prop;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct gen_pci *pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
struct hw_pci hw = {
.nr_controllers = 1,
.private_data = (void **)&pci,
.setup = gen_pci_setup,
.map_irq = of_irq_parse_and_map_pci,
.ops = &gen_pci_ops,
};
if (!pci)
return -ENOMEM;
type = of_get_property(np, "device_type", NULL);
if (!type || strcmp(type, "pci")) {
dev_err(dev, "invalid \"device_type\" %s\n", type);
return -EINVAL;
}
prop = of_get_property(of_chosen, "linux,pci-probe-only", NULL);
if (prop) {
if (*prop)
pci_add_flags(PCI_PROBE_ONLY);
else
pci_clear_flags(PCI_PROBE_ONLY);
}
of_id = of_match_node(gen_pci_of_match, np);
pci->cfg.ops = of_id->data;
gen_pci_ops.map_bus = pci->cfg.ops->map_bus;
pci->host.dev.parent = dev;
INIT_LIST_HEAD(&pci->host.windows);
INIT_LIST_HEAD(&pci->resources);
err = gen_pci_parse_request_of_pci_ranges(pci);
if (err)
return err;
err = gen_pci_parse_map_cfg_windows(pci);
if (err) {
gen_pci_release_of_pci_ranges(pci);
return err;
}
pci_common_init_dev(dev, &hw);
return 0;
}
