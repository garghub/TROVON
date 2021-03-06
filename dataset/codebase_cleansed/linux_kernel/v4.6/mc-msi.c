static void fsl_mc_msi_set_desc(msi_alloc_info_t *arg,
struct msi_desc *desc)
{
arg->desc = desc;
arg->hwirq = (irq_hw_number_t)desc->fsl_mc.msi_index;
}
static void fsl_mc_msi_update_dom_ops(struct msi_domain_info *info)
{
struct msi_domain_ops *ops = info->ops;
if (WARN_ON(!ops))
return;
if (WARN_ON(ops->set_desc))
return;
ops->set_desc = fsl_mc_msi_set_desc;
}
static void __fsl_mc_msi_write_msg(struct fsl_mc_device *mc_bus_dev,
struct fsl_mc_device_irq *mc_dev_irq)
{
int error;
struct fsl_mc_device *owner_mc_dev = mc_dev_irq->mc_dev;
struct msi_desc *msi_desc = mc_dev_irq->msi_desc;
struct dprc_irq_cfg irq_cfg;
if (msi_desc->msg.address_lo == 0x0 && msi_desc->msg.address_hi == 0x0)
return;
if (WARN_ON(!owner_mc_dev))
return;
irq_cfg.paddr = ((u64)msi_desc->msg.address_hi << 32) |
msi_desc->msg.address_lo;
irq_cfg.val = msi_desc->msg.data;
irq_cfg.user_irq_id = msi_desc->irq;
if (owner_mc_dev == mc_bus_dev) {
error = dprc_set_irq(mc_bus_dev->mc_io,
MC_CMD_FLAG_INTR_DIS | MC_CMD_FLAG_PRI,
mc_bus_dev->mc_handle,
mc_dev_irq->dev_irq_index,
&irq_cfg);
if (error < 0) {
dev_err(&owner_mc_dev->dev,
"dprc_set_irq() failed: %d\n", error);
}
} else {
error = dprc_set_obj_irq(mc_bus_dev->mc_io,
MC_CMD_FLAG_INTR_DIS | MC_CMD_FLAG_PRI,
mc_bus_dev->mc_handle,
owner_mc_dev->obj_desc.type,
owner_mc_dev->obj_desc.id,
mc_dev_irq->dev_irq_index,
&irq_cfg);
if (error < 0) {
dev_err(&owner_mc_dev->dev,
"dprc_obj_set_irq() failed: %d\n", error);
}
}
}
static void fsl_mc_msi_write_msg(struct irq_data *irq_data,
struct msi_msg *msg)
{
struct msi_desc *msi_desc = irq_data_get_msi_desc(irq_data);
struct fsl_mc_device *mc_bus_dev = to_fsl_mc_device(msi_desc->dev);
struct fsl_mc_bus *mc_bus = to_fsl_mc_bus(mc_bus_dev);
struct fsl_mc_device_irq *mc_dev_irq =
&mc_bus->irq_resources[msi_desc->fsl_mc.msi_index];
WARN_ON(mc_dev_irq->msi_desc != msi_desc);
msi_desc->msg = *msg;
__fsl_mc_msi_write_msg(mc_bus_dev, mc_dev_irq);
}
static void fsl_mc_msi_update_chip_ops(struct msi_domain_info *info)
{
struct irq_chip *chip = info->chip;
if (WARN_ON((!chip)))
return;
if (WARN_ON(chip->irq_write_msi_msg))
return;
chip->irq_write_msi_msg = fsl_mc_msi_write_msg;
}
struct irq_domain *fsl_mc_msi_create_irq_domain(struct fwnode_handle *fwnode,
struct msi_domain_info *info,
struct irq_domain *parent)
{
struct irq_domain *domain;
if (info->flags & MSI_FLAG_USE_DEF_DOM_OPS)
fsl_mc_msi_update_dom_ops(info);
if (info->flags & MSI_FLAG_USE_DEF_CHIP_OPS)
fsl_mc_msi_update_chip_ops(info);
domain = msi_create_irq_domain(fwnode, info, parent);
if (domain)
domain->bus_token = DOMAIN_BUS_FSL_MC_MSI;
return domain;
}
int fsl_mc_find_msi_domain(struct device *mc_platform_dev,
struct irq_domain **mc_msi_domain)
{
struct irq_domain *msi_domain;
struct device_node *mc_of_node = mc_platform_dev->of_node;
msi_domain = of_msi_get_domain(mc_platform_dev, mc_of_node,
DOMAIN_BUS_FSL_MC_MSI);
if (!msi_domain) {
pr_err("Unable to find fsl-mc MSI domain for %s\n",
mc_of_node->full_name);
return -ENOENT;
}
*mc_msi_domain = msi_domain;
return 0;
}
static void fsl_mc_msi_free_descs(struct device *dev)
{
struct msi_desc *desc, *tmp;
list_for_each_entry_safe(desc, tmp, dev_to_msi_list(dev), list) {
list_del(&desc->list);
free_msi_entry(desc);
}
}
static int fsl_mc_msi_alloc_descs(struct device *dev, unsigned int irq_count)
{
unsigned int i;
int error;
struct msi_desc *msi_desc;
for (i = 0; i < irq_count; i++) {
msi_desc = alloc_msi_entry(dev);
if (!msi_desc) {
dev_err(dev, "Failed to allocate msi entry\n");
error = -ENOMEM;
goto cleanup_msi_descs;
}
msi_desc->fsl_mc.msi_index = i;
msi_desc->nvec_used = 1;
INIT_LIST_HEAD(&msi_desc->list);
list_add_tail(&msi_desc->list, dev_to_msi_list(dev));
}
return 0;
cleanup_msi_descs:
fsl_mc_msi_free_descs(dev);
return error;
}
int fsl_mc_msi_domain_alloc_irqs(struct device *dev,
unsigned int irq_count)
{
struct irq_domain *msi_domain;
int error;
if (WARN_ON(!list_empty(dev_to_msi_list(dev))))
return -EINVAL;
error = fsl_mc_msi_alloc_descs(dev, irq_count);
if (error < 0)
return error;
msi_domain = dev_get_msi_domain(dev);
if (WARN_ON(!msi_domain)) {
error = -EINVAL;
goto cleanup_msi_descs;
}
error = msi_domain_alloc_irqs(msi_domain, dev, irq_count);
if (error) {
dev_err(dev, "Failed to allocate IRQs\n");
goto cleanup_msi_descs;
}
return 0;
cleanup_msi_descs:
fsl_mc_msi_free_descs(dev);
return error;
}
void fsl_mc_msi_domain_free_irqs(struct device *dev)
{
struct irq_domain *msi_domain;
msi_domain = dev_get_msi_domain(dev);
if (WARN_ON(!msi_domain))
return;
msi_domain_free_irqs(msi_domain, dev);
if (WARN_ON(list_empty(dev_to_msi_list(dev))))
return;
fsl_mc_msi_free_descs(dev);
}
