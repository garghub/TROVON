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
static bool of_iommu_driver_present(struct device_node *np)
{
if (system_state >= SYSTEM_RUNNING)
return false;
return of_match_node(&__iommu_of_table, np);
}
static int of_iommu_xlate(struct device *dev,
struct of_phandle_args *iommu_spec)
{
const struct iommu_ops *ops;
struct fwnode_handle *fwnode = &iommu_spec->np->fwnode;
int err;
ops = iommu_ops_from_fwnode(fwnode);
if ((ops && !ops->of_xlate) ||
!of_device_is_available(iommu_spec->np) ||
(!ops && !of_iommu_driver_present(iommu_spec->np)))
return NO_IOMMU;
err = iommu_fwspec_init(dev, &iommu_spec->np->fwnode, ops);
if (err)
return err;
if (!ops)
return -EPROBE_DEFER;
return ops->of_xlate(dev, iommu_spec);
}
static int of_pci_iommu_init(struct pci_dev *pdev, u16 alias, void *data)
{
struct of_pci_iommu_alias_info *info = data;
struct of_phandle_args iommu_spec = { .args_count = 1 };
int err;
err = of_pci_map_rid(info->np, alias, "iommu-map",
"iommu-map-mask", &iommu_spec.np,
iommu_spec.args);
if (err)
return err == -ENODEV ? NO_IOMMU : err;
err = of_iommu_xlate(info->dev, &iommu_spec);
of_node_put(iommu_spec.np);
return err;
}
const struct iommu_ops *of_iommu_configure(struct device *dev,
struct device_node *master_np)
{
const struct iommu_ops *ops = NULL;
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
int err = NO_IOMMU;
if (!master_np)
return NULL;
if (fwspec) {
if (fwspec->ops)
return fwspec->ops;
iommu_fwspec_free(dev);
}
if (dev_is_pci(dev)) {
struct of_pci_iommu_alias_info info = {
.dev = dev,
.np = master_np,
};
err = pci_for_each_dma_alias(to_pci_dev(dev),
of_pci_iommu_init, &info);
} else {
struct of_phandle_args iommu_spec;
int idx = 0;
while (!of_parse_phandle_with_args(master_np, "iommus",
"#iommu-cells",
idx, &iommu_spec)) {
err = of_iommu_xlate(dev, &iommu_spec);
of_node_put(iommu_spec.np);
idx++;
if (err)
break;
}
}
if (!err)
ops = dev->iommu_fwspec->ops;
if (ops && ops->add_device && dev->bus && !dev->iommu_group)
err = ops->add_device(dev);
if (err == -EPROBE_DEFER) {
ops = ERR_PTR(err);
} else if (err < 0) {
dev_dbg(dev, "Adding to IOMMU failed: %d\n", err);
ops = NULL;
}
return ops;
}
static int __init of_iommu_init(void)
{
struct device_node *np;
const struct of_device_id *match, *matches = &__iommu_of_table;
for_each_matching_node_and_match(np, matches, &match) {
const of_iommu_init_fn init_fn = match->data;
if (init_fn && init_fn(np))
pr_err("Failed to initialise IOMMU %pOF\n", np);
}
return 0;
}
