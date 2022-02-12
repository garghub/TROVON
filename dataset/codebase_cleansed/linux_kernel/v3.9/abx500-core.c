static void lookup_ops(struct device *dev, struct abx500_ops **ops)
{
struct abx500_device_entry *dev_entry;
*ops = NULL;
list_for_each_entry(dev_entry, &abx500_list, list) {
if (dev_entry->dev == dev) {
*ops = &dev_entry->ops;
return;
}
}
}
int abx500_register_ops(struct device *dev, struct abx500_ops *ops)
{
struct abx500_device_entry *dev_entry;
dev_entry = kzalloc(sizeof(struct abx500_device_entry), GFP_KERNEL);
if (!dev_entry) {
dev_err(dev, "register_ops kzalloc failed");
return -ENOMEM;
}
dev_entry->dev = dev;
memcpy(&dev_entry->ops, ops, sizeof(struct abx500_ops));
list_add_tail(&dev_entry->list, &abx500_list);
return 0;
}
void abx500_remove_ops(struct device *dev)
{
struct abx500_device_entry *dev_entry, *tmp;
list_for_each_entry_safe(dev_entry, tmp, &abx500_list, list)
{
if (dev_entry->dev == dev) {
list_del(&dev_entry->list);
kfree(dev_entry);
}
}
}
int abx500_set_register_interruptible(struct device *dev, u8 bank, u8 reg,
u8 value)
{
struct abx500_ops *ops;
lookup_ops(dev->parent, &ops);
if ((ops != NULL) && (ops->set_register != NULL))
return ops->set_register(dev, bank, reg, value);
else
return -ENOTSUPP;
}
int abx500_get_register_interruptible(struct device *dev, u8 bank, u8 reg,
u8 *value)
{
struct abx500_ops *ops;
lookup_ops(dev->parent, &ops);
if ((ops != NULL) && (ops->get_register != NULL))
return ops->get_register(dev, bank, reg, value);
else
return -ENOTSUPP;
}
int abx500_get_register_page_interruptible(struct device *dev, u8 bank,
u8 first_reg, u8 *regvals, u8 numregs)
{
struct abx500_ops *ops;
lookup_ops(dev->parent, &ops);
if ((ops != NULL) && (ops->get_register_page != NULL))
return ops->get_register_page(dev, bank,
first_reg, regvals, numregs);
else
return -ENOTSUPP;
}
int abx500_mask_and_set_register_interruptible(struct device *dev, u8 bank,
u8 reg, u8 bitmask, u8 bitvalues)
{
struct abx500_ops *ops;
lookup_ops(dev->parent, &ops);
if ((ops != NULL) && (ops->mask_and_set_register != NULL))
return ops->mask_and_set_register(dev, bank,
reg, bitmask, bitvalues);
else
return -ENOTSUPP;
}
int abx500_get_chip_id(struct device *dev)
{
struct abx500_ops *ops;
lookup_ops(dev->parent, &ops);
if ((ops != NULL) && (ops->get_chip_id != NULL))
return ops->get_chip_id(dev);
else
return -ENOTSUPP;
}
int abx500_event_registers_startup_state_get(struct device *dev, u8 *event)
{
struct abx500_ops *ops;
lookup_ops(dev->parent, &ops);
if ((ops != NULL) && (ops->event_registers_startup_state_get != NULL))
return ops->event_registers_startup_state_get(dev, event);
else
return -ENOTSUPP;
}
int abx500_startup_irq_enabled(struct device *dev, unsigned int irq)
{
struct abx500_ops *ops;
lookup_ops(dev->parent, &ops);
if ((ops != NULL) && (ops->startup_irq_enabled != NULL))
return ops->startup_irq_enabled(dev, irq);
else
return -ENOTSUPP;
}
void abx500_dump_all_banks(void)
{
struct abx500_ops *ops;
struct device dummy_child = {0};
struct abx500_device_entry *dev_entry;
list_for_each_entry(dev_entry, &abx500_list, list) {
dummy_child.parent = dev_entry->dev;
ops = &dev_entry->ops;
if ((ops != NULL) && (ops->dump_all_banks != NULL))
ops->dump_all_banks(&dummy_child);
}
}
