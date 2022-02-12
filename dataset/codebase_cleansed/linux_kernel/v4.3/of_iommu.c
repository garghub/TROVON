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
void of_iommu_set_ops(struct device_node *np, struct iommu_ops *ops)
{
struct of_iommu_node *iommu = kzalloc(sizeof(*iommu), GFP_KERNEL);
if (WARN_ON(!iommu))
return;
INIT_LIST_HEAD(&iommu->list);
iommu->np = np;
iommu->ops = ops;
spin_lock(&of_iommu_lock);
list_add_tail(&iommu->list, &of_iommu_list);
spin_unlock(&of_iommu_lock);
}
struct iommu_ops *of_iommu_get_ops(struct device_node *np)
{
struct of_iommu_node *node;
struct iommu_ops *ops = NULL;
spin_lock(&of_iommu_lock);
list_for_each_entry(node, &of_iommu_list, list)
if (node->np == np) {
ops = node->ops;
break;
}
spin_unlock(&of_iommu_lock);
return ops;
}
struct iommu_ops *of_iommu_configure(struct device *dev,
struct device_node *master_np)
{
struct of_phandle_args iommu_spec;
struct device_node *np;
struct iommu_ops *ops = NULL;
int idx = 0;
if (dev_is_pci(dev))
return NULL;
while (!of_parse_phandle_with_args(master_np, "iommus",
"#iommu-cells", idx,
&iommu_spec)) {
np = iommu_spec.np;
ops = of_iommu_get_ops(np);
if (!ops || !ops->of_xlate || ops->of_xlate(dev, &iommu_spec))
goto err_put_node;
of_node_put(np);
idx++;
}
return ops;
err_put_node:
of_node_put(np);
return NULL;
}
void __init of_iommu_init(void)
{
struct device_node *np;
const struct of_device_id *match, *matches = &__iommu_of_table;
for_each_matching_node_and_match(np, matches, &match) {
const of_iommu_init_fn init_fn = match->data;
if (init_fn(np))
pr_err("Failed to initialise IOMMU %s\n",
of_node_full_name(np));
}
}
