static irq_hw_number_t platform_msi_calc_hwirq(struct msi_desc *desc)
{
u32 devid;
devid = desc->platform.msi_priv_data->devid;
return (devid << (32 - DEV_ID_SHIFT)) | desc->platform.msi_index;
}
static void platform_msi_set_desc(msi_alloc_info_t *arg, struct msi_desc *desc)
{
arg->desc = desc;
arg->hwirq = platform_msi_calc_hwirq(desc);
}
static int platform_msi_init(struct irq_domain *domain,
struct msi_domain_info *info,
unsigned int virq, irq_hw_number_t hwirq,
msi_alloc_info_t *arg)
{
return irq_domain_set_hwirq_and_chip(domain, virq, hwirq,
info->chip, info->chip_data);
}
static void platform_msi_update_dom_ops(struct msi_domain_info *info)
{
struct msi_domain_ops *ops = info->ops;
BUG_ON(!ops);
if (ops->msi_init == NULL)
ops->msi_init = platform_msi_init;
if (ops->set_desc == NULL)
ops->set_desc = platform_msi_set_desc;
}
static void platform_msi_write_msg(struct irq_data *data, struct msi_msg *msg)
{
struct msi_desc *desc = irq_data_get_msi_desc(data);
struct platform_msi_priv_data *priv_data;
priv_data = desc->platform.msi_priv_data;
priv_data->write_msg(desc, msg);
}
static void platform_msi_update_chip_ops(struct msi_domain_info *info)
{
struct irq_chip *chip = info->chip;
BUG_ON(!chip);
if (!chip->irq_mask)
chip->irq_mask = irq_chip_mask_parent;
if (!chip->irq_unmask)
chip->irq_unmask = irq_chip_unmask_parent;
if (!chip->irq_eoi)
chip->irq_eoi = irq_chip_eoi_parent;
if (!chip->irq_set_affinity)
chip->irq_set_affinity = msi_domain_set_affinity;
if (!chip->irq_write_msi_msg)
chip->irq_write_msi_msg = platform_msi_write_msg;
}
static void platform_msi_free_descs(struct device *dev)
{
struct msi_desc *desc, *tmp;
list_for_each_entry_safe(desc, tmp, dev_to_msi_list(dev), list) {
list_del(&desc->list);
free_msi_entry(desc);
}
}
static int platform_msi_alloc_descs(struct device *dev, int nvec,
struct platform_msi_priv_data *data)
{
int i;
for (i = 0; i < nvec; i++) {
struct msi_desc *desc;
desc = alloc_msi_entry(dev);
if (!desc)
break;
desc->platform.msi_priv_data = data;
desc->platform.msi_index = i;
desc->nvec_used = 1;
list_add_tail(&desc->list, dev_to_msi_list(dev));
}
if (i != nvec) {
platform_msi_free_descs(dev);
return -ENOMEM;
}
return 0;
}
struct irq_domain *platform_msi_create_irq_domain(struct device_node *np,
struct msi_domain_info *info,
struct irq_domain *parent)
{
struct irq_domain *domain;
if (info->flags & MSI_FLAG_USE_DEF_DOM_OPS)
platform_msi_update_dom_ops(info);
if (info->flags & MSI_FLAG_USE_DEF_CHIP_OPS)
platform_msi_update_chip_ops(info);
domain = msi_create_irq_domain(np, info, parent);
if (domain)
domain->bus_token = DOMAIN_BUS_PLATFORM_MSI;
return domain;
}
int platform_msi_domain_alloc_irqs(struct device *dev, unsigned int nvec,
irq_write_msi_msg_t write_msi_msg)
{
struct platform_msi_priv_data *priv_data;
int err;
if (!dev->msi_domain || !write_msi_msg || !nvec ||
nvec > (1 << (32 - DEV_ID_SHIFT)))
return -EINVAL;
if (dev->msi_domain->bus_token != DOMAIN_BUS_PLATFORM_MSI) {
dev_err(dev, "Incompatible msi_domain, giving up\n");
return -EINVAL;
}
if (!list_empty(dev_to_msi_list(dev)))
return -EBUSY;
priv_data = kzalloc(sizeof(*priv_data), GFP_KERNEL);
if (!priv_data)
return -ENOMEM;
priv_data->devid = ida_simple_get(&platform_msi_devid_ida,
0, 1 << DEV_ID_SHIFT, GFP_KERNEL);
if (priv_data->devid < 0) {
err = priv_data->devid;
goto out_free_data;
}
priv_data->write_msg = write_msi_msg;
err = platform_msi_alloc_descs(dev, nvec, priv_data);
if (err)
goto out_free_id;
err = msi_domain_alloc_irqs(dev->msi_domain, dev, nvec);
if (err)
goto out_free_desc;
return 0;
out_free_desc:
platform_msi_free_descs(dev);
out_free_id:
ida_simple_remove(&platform_msi_devid_ida, priv_data->devid);
out_free_data:
kfree(priv_data);
return err;
}
void platform_msi_domain_free_irqs(struct device *dev)
{
struct msi_desc *desc;
desc = first_msi_entry(dev);
if (desc) {
struct platform_msi_priv_data *data;
data = desc->platform.msi_priv_data;
ida_simple_remove(&platform_msi_devid_ida, data->devid);
kfree(data);
}
msi_domain_free_irqs(dev->msi_domain, dev);
platform_msi_free_descs(dev);
}
