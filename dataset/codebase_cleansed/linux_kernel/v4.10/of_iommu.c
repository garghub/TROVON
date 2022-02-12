int of_get_dma_window(struct device_node *dn, const char *prefix, int index,
unsigned long *busno, dma_addr_t *addr, size_t *size)
{
const __be32 *dma_window, *end;
int bytes, cur_index = 0;
char propname[NAME_MAX], addrname[NAME_MAX], sizename[NAME_MAX];
if (!dn || !addr || !size)
return -EINVAL;
if (!prefix)
prefix = "";
snprintf(propname, sizeof(propname), "%sdma-window", prefix);
snprintf(addrname, sizeof(addrname), "%s#dma-address-cells", prefix);
snprintf(sizename, sizeof(sizename), "%s#dma-size-cells", prefix);
dma_window = of_get_property(dn, propname, &bytes);
if (!dma_window)
return -ENODEV;
end = dma_window + bytes / sizeof(*dma_window);
while (dma_window < end) {
u32 cells;
const void *prop;
if (busno)
*busno = be32_to_cpup(dma_window++);
prop = of_get_property(dn, addrname, NULL);
if (!prop)
prop = of_get_property(dn, "#address-cells", NULL);
cells = prop ? be32_to_cpup(prop) : of_n_addr_cells(dn);
if (!cells)
return -EINVAL;
*addr = of_read_number(dma_window, cells);
dma_window += cells;
prop = of_get_property(dn, sizename, NULL);
cells = prop ? be32_to_cpup(prop) : of_n_size_cells(dn);
if (!cells)
return -EINVAL;
*size = of_read_number(dma_window, cells);
dma_window += cells;
if (cur_index++ == index)
break;
}
return 0;
}
static int __get_pci_rid(struct pci_dev *pdev, u16 alias, void *data)
{
struct of_phandle_args *iommu_spec = data;
iommu_spec->args[0] = alias;
return iommu_spec->np == pdev->bus->dev.of_node;
}
static const struct iommu_ops
*of_pci_iommu_configure(struct pci_dev *pdev, struct device_node *bridge_np)
{
const struct iommu_ops *ops;
struct of_phandle_args iommu_spec;
iommu_spec.args_count = 1;
iommu_spec.np = bridge_np;
pci_for_each_dma_alias(pdev, __get_pci_rid, &iommu_spec);
iommu_spec.np = NULL;
if (of_pci_map_rid(bridge_np, iommu_spec.args[0], "iommu-map",
"iommu-map-mask", &iommu_spec.np, iommu_spec.args))
return NULL;
ops = of_iommu_get_ops(iommu_spec.np);
if (!ops || !ops->of_xlate ||
iommu_fwspec_init(&pdev->dev, &iommu_spec.np->fwnode, ops) ||
ops->of_xlate(&pdev->dev, &iommu_spec))
ops = NULL;
of_node_put(iommu_spec.np);
return ops;
}
const struct iommu_ops *of_iommu_configure(struct device *dev,
struct device_node *master_np)
{
struct of_phandle_args iommu_spec;
struct device_node *np;
const struct iommu_ops *ops = NULL;
int idx = 0;
if (dev_is_pci(dev))
return of_pci_iommu_configure(to_pci_dev(dev), master_np);
while (!of_parse_phandle_with_args(master_np, "iommus",
"#iommu-cells", idx,
&iommu_spec)) {
np = iommu_spec.np;
ops = of_iommu_get_ops(np);
if (!ops || !ops->of_xlate ||
iommu_fwspec_init(dev, &np->fwnode, ops) ||
ops->of_xlate(dev, &iommu_spec))
goto err_put_node;
of_node_put(np);
idx++;
}
return ops;
err_put_node:
of_node_put(np);
return NULL;
}
static int __init of_iommu_init(void)
{
struct device_node *np;
const struct of_device_id *match, *matches = &__iommu_of_table;
for_each_matching_node_and_match(np, matches, &match) {
const of_iommu_init_fn init_fn = match->data;
if (init_fn(np))
pr_err("Failed to initialise IOMMU %s\n",
of_node_full_name(np));
}
return 0;
}
