static void __iomem *gen_pci_map_cfg_bus_cam(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct gen_pci *pci = bus->sysdata;
resource_size_t idx = bus->number - pci->cfg.bus_range->start;
return pci->cfg.win[idx] + ((devfn << 8) | where);
}
static void __iomem *gen_pci_map_cfg_bus_ecam(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct gen_pci *pci = bus->sysdata;
resource_size_t idx = bus->number - pci->cfg.bus_range->start;
return pci->cfg.win[idx] + ((devfn << 12) | where);
}
static int gen_pci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
struct gen_pci *pci = devm_kzalloc(dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
of_id = of_match_node(gen_pci_of_match, dev->of_node);
pci->cfg.ops = (struct gen_pci_cfg_bus_ops *)of_id->data;
return pci_host_common_probe(pdev, pci);
}
