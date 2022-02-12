static inline int iort_set_fwnode(struct acpi_iort_node *iort_node,
struct fwnode_handle *fwnode)
{
struct iort_fwnode *np;
np = kzalloc(sizeof(struct iort_fwnode), GFP_ATOMIC);
if (WARN_ON(!np))
return -ENOMEM;
INIT_LIST_HEAD(&np->list);
np->iort_node = iort_node;
np->fwnode = fwnode;
spin_lock(&iort_fwnode_lock);
list_add_tail(&np->list, &iort_fwnode_list);
spin_unlock(&iort_fwnode_lock);
return 0;
}
static inline
struct fwnode_handle *iort_get_fwnode(struct acpi_iort_node *node)
{
struct iort_fwnode *curr;
struct fwnode_handle *fwnode = NULL;
spin_lock(&iort_fwnode_lock);
list_for_each_entry(curr, &iort_fwnode_list, list) {
if (curr->iort_node == node) {
fwnode = curr->fwnode;
break;
}
}
spin_unlock(&iort_fwnode_lock);
return fwnode;
}
static inline void iort_delete_fwnode(struct acpi_iort_node *node)
{
struct iort_fwnode *curr, *tmp;
spin_lock(&iort_fwnode_lock);
list_for_each_entry_safe(curr, tmp, &iort_fwnode_list, list) {
if (curr->iort_node == node) {
list_del(&curr->list);
kfree(curr);
break;
}
}
spin_unlock(&iort_fwnode_lock);
}
int iort_register_domain_token(int trans_id, struct fwnode_handle *fw_node)
{
struct iort_its_msi_chip *its_msi_chip;
its_msi_chip = kzalloc(sizeof(*its_msi_chip), GFP_KERNEL);
if (!its_msi_chip)
return -ENOMEM;
its_msi_chip->fw_node = fw_node;
its_msi_chip->translation_id = trans_id;
spin_lock(&iort_msi_chip_lock);
list_add(&its_msi_chip->list, &iort_msi_chip_list);
spin_unlock(&iort_msi_chip_lock);
return 0;
}
void iort_deregister_domain_token(int trans_id)
{
struct iort_its_msi_chip *its_msi_chip, *t;
spin_lock(&iort_msi_chip_lock);
list_for_each_entry_safe(its_msi_chip, t, &iort_msi_chip_list, list) {
if (its_msi_chip->translation_id == trans_id) {
list_del(&its_msi_chip->list);
kfree(its_msi_chip);
break;
}
}
spin_unlock(&iort_msi_chip_lock);
}
struct fwnode_handle *iort_find_domain_token(int trans_id)
{
struct fwnode_handle *fw_node = NULL;
struct iort_its_msi_chip *its_msi_chip;
spin_lock(&iort_msi_chip_lock);
list_for_each_entry(its_msi_chip, &iort_msi_chip_list, list) {
if (its_msi_chip->translation_id == trans_id) {
fw_node = its_msi_chip->fw_node;
break;
}
}
spin_unlock(&iort_msi_chip_lock);
return fw_node;
}
static struct acpi_iort_node *iort_scan_node(enum acpi_iort_node_type type,
iort_find_node_callback callback,
void *context)
{
struct acpi_iort_node *iort_node, *iort_end;
struct acpi_table_iort *iort;
int i;
if (!iort_table)
return NULL;
iort = (struct acpi_table_iort *)iort_table;
iort_node = ACPI_ADD_PTR(struct acpi_iort_node, iort,
iort->node_offset);
iort_end = ACPI_ADD_PTR(struct acpi_iort_node, iort_table,
iort_table->length);
for (i = 0; i < iort->node_count; i++) {
if (WARN_TAINT(iort_node >= iort_end, TAINT_FIRMWARE_WORKAROUND,
"IORT node pointer overflows, bad table!\n"))
return NULL;
if (iort_node->type == type &&
ACPI_SUCCESS(callback(iort_node, context)))
return iort_node;
iort_node = ACPI_ADD_PTR(struct acpi_iort_node, iort_node,
iort_node->length);
}
return NULL;
}
static acpi_status iort_match_node_callback(struct acpi_iort_node *node,
void *context)
{
struct device *dev = context;
acpi_status status = AE_NOT_FOUND;
if (node->type == ACPI_IORT_NODE_NAMED_COMPONENT) {
struct acpi_buffer buf = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_device *adev = to_acpi_device_node(dev->fwnode);
struct acpi_iort_named_component *ncomp;
if (!adev)
goto out;
status = acpi_get_name(adev->handle, ACPI_FULL_PATHNAME, &buf);
if (ACPI_FAILURE(status)) {
dev_warn(dev, "Can't get device full path name\n");
goto out;
}
ncomp = (struct acpi_iort_named_component *)node->node_data;
status = !strcmp(ncomp->device_name, buf.pointer) ?
AE_OK : AE_NOT_FOUND;
acpi_os_free(buf.pointer);
} else if (node->type == ACPI_IORT_NODE_PCI_ROOT_COMPLEX) {
struct acpi_iort_root_complex *pci_rc;
struct pci_bus *bus;
bus = to_pci_bus(dev);
pci_rc = (struct acpi_iort_root_complex *)node->node_data;
status = pci_rc->pci_segment_number == pci_domain_nr(bus) ?
AE_OK : AE_NOT_FOUND;
}
out:
return status;
}
static int iort_id_map(struct acpi_iort_id_mapping *map, u8 type, u32 rid_in,
u32 *rid_out)
{
if (map->flags & ACPI_IORT_ID_SINGLE_MAPPING) {
if (type == ACPI_IORT_NODE_NAMED_COMPONENT ||
type == ACPI_IORT_NODE_PCI_ROOT_COMPLEX) {
*rid_out = map->output_base;
return 0;
}
pr_warn(FW_BUG "[map %p] SINGLE MAPPING flag not allowed for node type %d, skipping ID map\n",
map, type);
return -ENXIO;
}
if (rid_in < map->input_base ||
(rid_in >= map->input_base + map->id_count))
return -ENXIO;
*rid_out = map->output_base + (rid_in - map->input_base);
return 0;
}
static
struct acpi_iort_node *iort_node_get_id(struct acpi_iort_node *node,
u32 *id_out, int index)
{
struct acpi_iort_node *parent;
struct acpi_iort_id_mapping *map;
if (!node->mapping_offset || !node->mapping_count ||
index >= node->mapping_count)
return NULL;
map = ACPI_ADD_PTR(struct acpi_iort_id_mapping, node,
node->mapping_offset + index * sizeof(*map));
if (!map->output_reference) {
pr_err(FW_BUG "[node %p type %d] ID map has NULL parent reference\n",
node, node->type);
return NULL;
}
parent = ACPI_ADD_PTR(struct acpi_iort_node, iort_table,
map->output_reference);
if (map->flags & ACPI_IORT_ID_SINGLE_MAPPING) {
if (node->type == ACPI_IORT_NODE_NAMED_COMPONENT ||
node->type == ACPI_IORT_NODE_PCI_ROOT_COMPLEX) {
*id_out = map->output_base;
return parent;
}
}
return NULL;
}
static struct acpi_iort_node *iort_node_map_id(struct acpi_iort_node *node,
u32 id_in, u32 *id_out,
u8 type_mask)
{
u32 id = id_in;
while (node) {
struct acpi_iort_id_mapping *map;
int i;
if (IORT_TYPE_MASK(node->type) & type_mask) {
if (id_out)
*id_out = id;
return node;
}
if (!node->mapping_offset || !node->mapping_count)
goto fail_map;
map = ACPI_ADD_PTR(struct acpi_iort_id_mapping, node,
node->mapping_offset);
if (!map->output_reference) {
pr_err(FW_BUG "[node %p type %d] ID map has NULL parent reference\n",
node, node->type);
goto fail_map;
}
for (i = 0; i < node->mapping_count; i++, map++) {
if (!iort_id_map(map, node->type, id, &id))
break;
}
if (i == node->mapping_count)
goto fail_map;
node = ACPI_ADD_PTR(struct acpi_iort_node, iort_table,
map->output_reference);
}
fail_map:
if (id_out)
*id_out = id_in;
return NULL;
}
static
struct acpi_iort_node *iort_node_map_platform_id(struct acpi_iort_node *node,
u32 *id_out, u8 type_mask,
int index)
{
struct acpi_iort_node *parent;
u32 id;
parent = iort_node_get_id(node, &id, index);
if (!parent)
return NULL;
if (!(IORT_TYPE_MASK(parent->type) & type_mask))
parent = iort_node_map_id(parent, id, id_out, type_mask);
else
if (id_out)
*id_out = id;
return parent;
}
static struct acpi_iort_node *iort_find_dev_node(struct device *dev)
{
struct pci_bus *pbus;
if (!dev_is_pci(dev))
return iort_scan_node(ACPI_IORT_NODE_NAMED_COMPONENT,
iort_match_node_callback, dev);
pbus = to_pci_dev(dev)->bus;
while (!pci_is_root_bus(pbus))
pbus = pbus->parent;
return iort_scan_node(ACPI_IORT_NODE_PCI_ROOT_COMPLEX,
iort_match_node_callback, &pbus->dev);
}
u32 iort_msi_map_rid(struct device *dev, u32 req_id)
{
struct acpi_iort_node *node;
u32 dev_id;
node = iort_find_dev_node(dev);
if (!node)
return req_id;
iort_node_map_id(node, req_id, &dev_id, IORT_MSI_TYPE);
return dev_id;
}
int iort_pmsi_get_dev_id(struct device *dev, u32 *dev_id)
{
int i;
struct acpi_iort_node *node;
node = iort_find_dev_node(dev);
if (!node)
return -ENODEV;
for (i = 0; i < node->mapping_count; i++) {
if (iort_node_map_platform_id(node, dev_id, IORT_MSI_TYPE, i))
return 0;
}
return -ENODEV;
}
static int iort_dev_find_its_id(struct device *dev, u32 req_id,
unsigned int idx, int *its_id)
{
struct acpi_iort_its_group *its;
struct acpi_iort_node *node;
node = iort_find_dev_node(dev);
if (!node)
return -ENXIO;
node = iort_node_map_id(node, req_id, NULL, IORT_MSI_TYPE);
if (!node)
return -ENXIO;
its = (struct acpi_iort_its_group *)node->node_data;
if (idx > its->its_count) {
dev_err(dev, "requested ITS ID index [%d] is greater than available [%d]\n",
idx, its->its_count);
return -ENXIO;
}
*its_id = its->identifiers[idx];
return 0;
}
struct irq_domain *iort_get_device_domain(struct device *dev, u32 req_id)
{
struct fwnode_handle *handle;
int its_id;
if (iort_dev_find_its_id(dev, req_id, 0, &its_id))
return NULL;
handle = iort_find_domain_token(its_id);
if (!handle)
return NULL;
return irq_find_matching_fwnode(handle, DOMAIN_BUS_PCI_MSI);
}
static struct irq_domain *iort_get_platform_device_domain(struct device *dev)
{
struct acpi_iort_node *node, *msi_parent;
struct fwnode_handle *iort_fwnode;
struct acpi_iort_its_group *its;
int i;
node = iort_scan_node(ACPI_IORT_NODE_NAMED_COMPONENT,
iort_match_node_callback, dev);
if (!node)
return NULL;
for (i = 0; i < node->mapping_count; i++) {
msi_parent = iort_node_map_platform_id(node, NULL,
IORT_MSI_TYPE, i);
if (msi_parent)
break;
}
if (!msi_parent)
return NULL;
its = (struct acpi_iort_its_group *)msi_parent->node_data;
iort_fwnode = iort_find_domain_token(its->identifiers[0]);
if (!iort_fwnode)
return NULL;
return irq_find_matching_fwnode(iort_fwnode, DOMAIN_BUS_PLATFORM_MSI);
}
void acpi_configure_pmsi_domain(struct device *dev)
{
struct irq_domain *msi_domain;
msi_domain = iort_get_platform_device_domain(dev);
if (msi_domain)
dev_set_msi_domain(dev, msi_domain);
}
static int __get_pci_rid(struct pci_dev *pdev, u16 alias, void *data)
{
u32 *rid = data;
*rid = alias;
return 0;
}
static int arm_smmu_iort_xlate(struct device *dev, u32 streamid,
struct fwnode_handle *fwnode,
const struct iommu_ops *ops)
{
int ret = iommu_fwspec_init(dev, fwnode, ops);
if (!ret)
ret = iommu_fwspec_add_ids(dev, &streamid, 1);
return ret;
}
static inline bool iort_iommu_driver_enabled(u8 type)
{
switch (type) {
case ACPI_IORT_NODE_SMMU_V3:
return IS_BUILTIN(CONFIG_ARM_SMMU_V3);
case ACPI_IORT_NODE_SMMU:
return IS_BUILTIN(CONFIG_ARM_SMMU);
default:
pr_warn("IORT node type %u does not describe an SMMU\n", type);
return false;
}
}
static inline
const struct iommu_ops *iort_fwspec_iommu_ops(struct iommu_fwspec *fwspec)
{
return (fwspec && fwspec->ops) ? fwspec->ops : NULL;
}
static inline
int iort_add_device_replay(const struct iommu_ops *ops, struct device *dev)
{
int err = 0;
if (!IS_ERR_OR_NULL(ops) && ops->add_device && dev->bus &&
!dev->iommu_group)
err = ops->add_device(dev);
return err;
}
static inline
const struct iommu_ops *iort_fwspec_iommu_ops(struct iommu_fwspec *fwspec)
{ return NULL; }
static inline
int iort_add_device_replay(const struct iommu_ops *ops, struct device *dev)
{ return 0; }
static const struct iommu_ops *iort_iommu_xlate(struct device *dev,
struct acpi_iort_node *node,
u32 streamid)
{
const struct iommu_ops *ops = NULL;
int ret = -ENODEV;
struct fwnode_handle *iort_fwnode;
if (node) {
iort_fwnode = iort_get_fwnode(node);
if (!iort_fwnode)
return NULL;
ops = iommu_ops_from_fwnode(iort_fwnode);
if (!ops)
return iort_iommu_driver_enabled(node->type) ?
ERR_PTR(-EPROBE_DEFER) : NULL;
ret = arm_smmu_iort_xlate(dev, streamid, iort_fwnode, ops);
}
return ret ? NULL : ops;
}
void iort_set_dma_mask(struct device *dev)
{
if (!dev->coherent_dma_mask)
dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (!dev->dma_mask)
dev->dma_mask = &dev->coherent_dma_mask;
}
const struct iommu_ops *iort_iommu_configure(struct device *dev)
{
struct acpi_iort_node *node, *parent;
const struct iommu_ops *ops = NULL;
u32 streamid = 0;
int err;
ops = iort_fwspec_iommu_ops(dev->iommu_fwspec);
if (ops)
return ops;
if (dev_is_pci(dev)) {
struct pci_bus *bus = to_pci_dev(dev)->bus;
u32 rid;
pci_for_each_dma_alias(to_pci_dev(dev), __get_pci_rid,
&rid);
node = iort_scan_node(ACPI_IORT_NODE_PCI_ROOT_COMPLEX,
iort_match_node_callback, &bus->dev);
if (!node)
return NULL;
parent = iort_node_map_id(node, rid, &streamid,
IORT_IOMMU_TYPE);
ops = iort_iommu_xlate(dev, parent, streamid);
} else {
int i = 0;
node = iort_scan_node(ACPI_IORT_NODE_NAMED_COMPONENT,
iort_match_node_callback, dev);
if (!node)
return NULL;
parent = iort_node_map_platform_id(node, &streamid,
IORT_IOMMU_TYPE, i++);
while (parent) {
ops = iort_iommu_xlate(dev, parent, streamid);
if (IS_ERR_OR_NULL(ops))
return ops;
parent = iort_node_map_platform_id(node, &streamid,
IORT_IOMMU_TYPE,
i++);
}
}
err = iort_add_device_replay(ops, dev);
if (err)
ops = ERR_PTR(err);
if (IS_ERR(ops) && (PTR_ERR(ops) != -EPROBE_DEFER)) {
dev_dbg(dev, "Adding to IOMMU failed: %ld\n", PTR_ERR(ops));
ops = NULL;
}
return ops;
}
static void __init acpi_iort_register_irq(int hwirq, const char *name,
int trigger,
struct resource *res)
{
int irq = acpi_register_gsi(NULL, hwirq, trigger,
ACPI_ACTIVE_HIGH);
if (irq <= 0) {
pr_err("could not register gsi hwirq %d name [%s]\n", hwirq,
name);
return;
}
res->start = irq;
res->end = irq;
res->flags = IORESOURCE_IRQ;
res->name = name;
}
static int __init arm_smmu_v3_count_resources(struct acpi_iort_node *node)
{
struct acpi_iort_smmu_v3 *smmu;
int num_res = 1;
smmu = (struct acpi_iort_smmu_v3 *)node->node_data;
if (smmu->event_gsiv)
num_res++;
if (smmu->pri_gsiv)
num_res++;
if (smmu->gerr_gsiv)
num_res++;
if (smmu->sync_gsiv)
num_res++;
return num_res;
}
static bool arm_smmu_v3_is_combined_irq(struct acpi_iort_smmu_v3 *smmu)
{
if (smmu->model != ACPI_IORT_SMMU_V3_CAVIUM_CN99XX)
return false;
return smmu->event_gsiv == smmu->pri_gsiv &&
smmu->event_gsiv == smmu->gerr_gsiv &&
smmu->event_gsiv == smmu->sync_gsiv;
}
static unsigned long arm_smmu_v3_resource_size(struct acpi_iort_smmu_v3 *smmu)
{
if (smmu->model == ACPI_IORT_SMMU_V3_CAVIUM_CN99XX)
return SZ_64K;
return SZ_128K;
}
static void __init arm_smmu_v3_init_resources(struct resource *res,
struct acpi_iort_node *node)
{
struct acpi_iort_smmu_v3 *smmu;
int num_res = 0;
smmu = (struct acpi_iort_smmu_v3 *)node->node_data;
res[num_res].start = smmu->base_address;
res[num_res].end = smmu->base_address +
arm_smmu_v3_resource_size(smmu) - 1;
res[num_res].flags = IORESOURCE_MEM;
num_res++;
if (arm_smmu_v3_is_combined_irq(smmu)) {
if (smmu->event_gsiv)
acpi_iort_register_irq(smmu->event_gsiv, "combined",
ACPI_EDGE_SENSITIVE,
&res[num_res++]);
} else {
if (smmu->event_gsiv)
acpi_iort_register_irq(smmu->event_gsiv, "eventq",
ACPI_EDGE_SENSITIVE,
&res[num_res++]);
if (smmu->pri_gsiv)
acpi_iort_register_irq(smmu->pri_gsiv, "priq",
ACPI_EDGE_SENSITIVE,
&res[num_res++]);
if (smmu->gerr_gsiv)
acpi_iort_register_irq(smmu->gerr_gsiv, "gerror",
ACPI_EDGE_SENSITIVE,
&res[num_res++]);
if (smmu->sync_gsiv)
acpi_iort_register_irq(smmu->sync_gsiv, "cmdq-sync",
ACPI_EDGE_SENSITIVE,
&res[num_res++]);
}
}
static bool __init arm_smmu_v3_is_coherent(struct acpi_iort_node *node)
{
struct acpi_iort_smmu_v3 *smmu;
smmu = (struct acpi_iort_smmu_v3 *)node->node_data;
return smmu->flags & ACPI_IORT_SMMU_V3_COHACC_OVERRIDE;
}
static int __init arm_smmu_count_resources(struct acpi_iort_node *node)
{
struct acpi_iort_smmu *smmu;
smmu = (struct acpi_iort_smmu *)node->node_data;
return smmu->context_interrupt_count + 2;
}
static void __init arm_smmu_init_resources(struct resource *res,
struct acpi_iort_node *node)
{
struct acpi_iort_smmu *smmu;
int i, hw_irq, trigger, num_res = 0;
u64 *ctx_irq, *glb_irq;
smmu = (struct acpi_iort_smmu *)node->node_data;
res[num_res].start = smmu->base_address;
res[num_res].end = smmu->base_address + smmu->span - 1;
res[num_res].flags = IORESOURCE_MEM;
num_res++;
glb_irq = ACPI_ADD_PTR(u64, node, smmu->global_interrupt_offset);
hw_irq = IORT_IRQ_MASK(glb_irq[0]);
trigger = IORT_IRQ_TRIGGER_MASK(glb_irq[0]);
acpi_iort_register_irq(hw_irq, "arm-smmu-global", trigger,
&res[num_res++]);
ctx_irq = ACPI_ADD_PTR(u64, node, smmu->context_interrupt_offset);
for (i = 0; i < smmu->context_interrupt_count; i++) {
hw_irq = IORT_IRQ_MASK(ctx_irq[i]);
trigger = IORT_IRQ_TRIGGER_MASK(ctx_irq[i]);
acpi_iort_register_irq(hw_irq, "arm-smmu-context", trigger,
&res[num_res++]);
}
}
static bool __init arm_smmu_is_coherent(struct acpi_iort_node *node)
{
struct acpi_iort_smmu *smmu;
smmu = (struct acpi_iort_smmu *)node->node_data;
return smmu->flags & ACPI_IORT_SMMU_COHERENT_WALK;
}
int __init iort_add_smmu_platform_device(struct acpi_iort_node *node)
{
struct fwnode_handle *fwnode;
struct platform_device *pdev;
struct resource *r;
enum dev_dma_attr attr;
int ret, count;
const struct iort_iommu_config *ops = iort_get_iommu_cfg(node);
if (!ops)
return -ENODEV;
pdev = platform_device_alloc(ops->name, PLATFORM_DEVID_AUTO);
if (!pdev)
return -ENOMEM;
count = ops->iommu_count_resources(node);
r = kcalloc(count, sizeof(*r), GFP_KERNEL);
if (!r) {
ret = -ENOMEM;
goto dev_put;
}
ops->iommu_init_resources(r, node);
ret = platform_device_add_resources(pdev, r, count);
kfree(r);
if (ret)
goto dev_put;
ret = platform_device_add_data(pdev, &node, sizeof(node));
if (ret)
goto dev_put;
pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
fwnode = iort_get_fwnode(node);
if (!fwnode) {
ret = -ENODEV;
goto dev_put;
}
pdev->dev.fwnode = fwnode;
attr = ops->iommu_is_coherent(node) ?
DEV_DMA_COHERENT : DEV_DMA_NON_COHERENT;
acpi_dma_configure(&pdev->dev, attr);
ret = platform_device_add(pdev);
if (ret)
goto dma_deconfigure;
return 0;
dma_deconfigure:
acpi_dma_deconfigure(&pdev->dev);
dev_put:
platform_device_put(pdev);
return ret;
}
static void __init iort_init_platform_devices(void)
{
struct acpi_iort_node *iort_node, *iort_end;
struct acpi_table_iort *iort;
struct fwnode_handle *fwnode;
int i, ret;
iort = (struct acpi_table_iort *)iort_table;
iort_node = ACPI_ADD_PTR(struct acpi_iort_node, iort,
iort->node_offset);
iort_end = ACPI_ADD_PTR(struct acpi_iort_node, iort,
iort_table->length);
for (i = 0; i < iort->node_count; i++) {
if (iort_node >= iort_end) {
pr_err("iort node pointer overflows, bad table\n");
return;
}
if ((iort_node->type == ACPI_IORT_NODE_SMMU) ||
(iort_node->type == ACPI_IORT_NODE_SMMU_V3)) {
fwnode = acpi_alloc_fwnode_static();
if (!fwnode)
return;
iort_set_fwnode(iort_node, fwnode);
ret = iort_add_smmu_platform_device(iort_node);
if (ret) {
iort_delete_fwnode(iort_node);
acpi_free_fwnode_static(fwnode);
return;
}
}
iort_node = ACPI_ADD_PTR(struct acpi_iort_node, iort_node,
iort_node->length);
}
}
void __init acpi_iort_init(void)
{
acpi_status status;
status = acpi_get_table(ACPI_SIG_IORT, 0, &iort_table);
if (ACPI_FAILURE(status)) {
if (status != AE_NOT_FOUND) {
const char *msg = acpi_format_exception(status);
pr_err("Failed to get table, %s\n", msg);
}
return;
}
iort_init_platform_devices();
}
