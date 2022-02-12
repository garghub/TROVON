static ssize_t mlxcpld_hotplug_attr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct mlxcpld_hotplug_priv_data *priv = platform_get_drvdata(pdev);
int index = to_sensor_dev_attr_2(attr)->index;
int nr = to_sensor_dev_attr_2(attr)->nr;
u8 reg_val = 0;
switch (nr) {
case MLXCPLD_HOTPLUG_ATTR_TYPE_PSU:
reg_val = !!!(inb(priv->plat->psu_reg_offset) & BIT(index));
break;
case MLXCPLD_HOTPLUG_ATTR_TYPE_PWR:
reg_val = !!(inb(priv->plat->pwr_reg_offset) & BIT(index %
priv->plat->pwr_count));
break;
case MLXCPLD_HOTPLUG_ATTR_TYPE_FAN:
reg_val = !!!(inb(priv->plat->fan_reg_offset) & BIT(index %
priv->plat->fan_count));
break;
}
return sprintf(buf, "%u\n", reg_val);
}
static int mlxcpld_hotplug_attr_init(struct mlxcpld_hotplug_priv_data *priv)
{
int num_attrs = priv->plat->psu_count + priv->plat->pwr_count +
priv->plat->fan_count;
int i;
priv->group.attrs = devm_kzalloc(&priv->pdev->dev, num_attrs *
sizeof(struct attribute *),
GFP_KERNEL);
if (!priv->group.attrs)
return -ENOMEM;
for (i = 0; i < num_attrs; i++) {
PRIV_ATTR(i) = &PRIV_DEV_ATTR(i).dev_attr.attr;
if (i < priv->plat->psu_count) {
PRIV_ATTR(i)->name = devm_kasprintf(&priv->pdev->dev,
GFP_KERNEL, "psu%u", i + 1);
PRIV_DEV_ATTR(i).nr = MLXCPLD_HOTPLUG_ATTR_TYPE_PSU;
} else if (i < priv->plat->psu_count + priv->plat->pwr_count) {
PRIV_ATTR(i)->name = devm_kasprintf(&priv->pdev->dev,
GFP_KERNEL, "pwr%u", i %
priv->plat->pwr_count + 1);
PRIV_DEV_ATTR(i).nr = MLXCPLD_HOTPLUG_ATTR_TYPE_PWR;
} else {
PRIV_ATTR(i)->name = devm_kasprintf(&priv->pdev->dev,
GFP_KERNEL, "fan%u", i %
priv->plat->fan_count + 1);
PRIV_DEV_ATTR(i).nr = MLXCPLD_HOTPLUG_ATTR_TYPE_FAN;
}
if (!PRIV_ATTR(i)->name) {
dev_err(&priv->pdev->dev, "Memory allocation failed for sysfs attribute %d.\n",
i + 1);
return -ENOMEM;
}
PRIV_DEV_ATTR(i).dev_attr.attr.name = PRIV_ATTR(i)->name;
PRIV_DEV_ATTR(i).dev_attr.attr.mode = S_IRUGO;
PRIV_DEV_ATTR(i).dev_attr.show = mlxcpld_hotplug_attr_show;
PRIV_DEV_ATTR(i).index = i;
sysfs_attr_init(&PRIV_DEV_ATTR(i).dev_attr.attr);
}
priv->group.attrs = priv->mlxcpld_hotplug_attr;
priv->groups[0] = &priv->group;
priv->groups[1] = NULL;
return 0;
}
static int mlxcpld_hotplug_device_create(struct device *dev,
struct mlxcpld_hotplug_device *item)
{
item->adapter = i2c_get_adapter(item->bus);
if (!item->adapter) {
dev_err(dev, "Failed to get adapter for bus %d\n",
item->bus);
return -EFAULT;
}
item->client = i2c_new_device(item->adapter, &item->brdinfo);
if (!item->client) {
dev_err(dev, "Failed to create client %s at bus %d at addr 0x%02x\n",
item->brdinfo.type, item->bus, item->brdinfo.addr);
i2c_put_adapter(item->adapter);
item->adapter = NULL;
return -EFAULT;
}
return 0;
}
static void mlxcpld_hotplug_device_destroy(struct mlxcpld_hotplug_device *item)
{
if (item->client) {
i2c_unregister_device(item->client);
item->client = NULL;
}
if (item->adapter) {
i2c_put_adapter(item->adapter);
item->adapter = NULL;
}
}
static inline void
mlxcpld_hotplug_work_helper(struct device *dev,
struct mlxcpld_hotplug_device *item, u8 is_inverse,
u16 offset, u8 mask, u8 *cache)
{
u8 val, asserted;
int bit;
outb(0, offset + MLXCPLD_HOTPLUG_MASK_OFF);
val = inb(offset) & mask;
asserted = *cache ^ val;
*cache = val;
if (unlikely(!item)) {
dev_err(dev, "False signal is received: register at offset 0x%02x, mask 0x%02x.\n",
offset, mask);
return;
}
for_each_set_bit(bit, (unsigned long *)&asserted, 8) {
if (val & BIT(bit)) {
if (is_inverse)
mlxcpld_hotplug_device_destroy(item + bit);
else
mlxcpld_hotplug_device_create(dev, item + bit);
} else {
if (is_inverse)
mlxcpld_hotplug_device_create(dev, item + bit);
else
mlxcpld_hotplug_device_destroy(item + bit);
}
}
outb(0, offset + MLXCPLD_HOTPLUG_EVENT_OFF);
outb(mask, offset + MLXCPLD_HOTPLUG_MASK_OFF);
}
static void mlxcpld_hotplug_work_handler(struct work_struct *work)
{
struct mlxcpld_hotplug_priv_data *priv = container_of(work,
struct mlxcpld_hotplug_priv_data, dwork.work);
u8 val, aggr_asserted;
unsigned long flags;
outb(0, priv->plat->top_aggr_offset + MLXCPLD_HOTPLUG_AGGR_MASK_OFF);
val = inb(priv->plat->top_aggr_offset) & priv->plat->top_aggr_mask;
aggr_asserted = priv->aggr_cache ^ val;
priv->aggr_cache = val;
if (aggr_asserted & priv->plat->top_aggr_psu_mask)
mlxcpld_hotplug_work_helper(&priv->pdev->dev, priv->plat->psu,
1, priv->plat->psu_reg_offset,
priv->plat->psu_mask,
&priv->psu_cache);
if (aggr_asserted & priv->plat->top_aggr_pwr_mask)
mlxcpld_hotplug_work_helper(&priv->pdev->dev, priv->plat->pwr,
0, priv->plat->pwr_reg_offset,
priv->plat->pwr_mask,
&priv->pwr_cache);
if (aggr_asserted & priv->plat->top_aggr_fan_mask)
mlxcpld_hotplug_work_helper(&priv->pdev->dev, priv->plat->fan,
1, priv->plat->fan_reg_offset,
priv->plat->fan_mask,
&priv->fan_cache);
if (aggr_asserted) {
spin_lock_irqsave(&priv->lock, flags);
cancel_delayed_work(&priv->dwork);
schedule_delayed_work(&priv->dwork, 0);
spin_unlock_irqrestore(&priv->lock, flags);
return;
}
outb(priv->plat->top_aggr_mask, priv->plat->top_aggr_offset +
MLXCPLD_HOTPLUG_AGGR_MASK_OFF);
}
static void mlxcpld_hotplug_set_irq(struct mlxcpld_hotplug_priv_data *priv)
{
outb(0, priv->plat->psu_reg_offset + MLXCPLD_HOTPLUG_EVENT_OFF);
priv->psu_cache = priv->plat->psu_mask;
outb(priv->plat->psu_mask, priv->plat->psu_reg_offset +
MLXCPLD_HOTPLUG_MASK_OFF);
outb(0, priv->plat->pwr_reg_offset + MLXCPLD_HOTPLUG_EVENT_OFF);
outb(priv->plat->pwr_mask, priv->plat->pwr_reg_offset +
MLXCPLD_HOTPLUG_MASK_OFF);
outb(0, priv->plat->fan_reg_offset + MLXCPLD_HOTPLUG_EVENT_OFF);
priv->fan_cache = priv->plat->fan_mask;
outb(priv->plat->fan_mask, priv->plat->fan_reg_offset +
MLXCPLD_HOTPLUG_MASK_OFF);
outb(priv->plat->top_aggr_mask, priv->plat->top_aggr_offset +
MLXCPLD_HOTPLUG_AGGR_MASK_OFF);
mlxcpld_hotplug_work_handler(&priv->dwork.work);
enable_irq(priv->irq);
}
static void mlxcpld_hotplug_unset_irq(struct mlxcpld_hotplug_priv_data *priv)
{
int i;
disable_irq(priv->irq);
cancel_delayed_work_sync(&priv->dwork);
outb(0, priv->plat->top_aggr_offset + MLXCPLD_HOTPLUG_AGGR_MASK_OFF);
outb(0, priv->plat->psu_reg_offset + MLXCPLD_HOTPLUG_MASK_OFF);
outb(0, priv->plat->psu_reg_offset + MLXCPLD_HOTPLUG_EVENT_OFF);
outb(0, priv->plat->pwr_reg_offset + MLXCPLD_HOTPLUG_MASK_OFF);
outb(0, priv->plat->pwr_reg_offset + MLXCPLD_HOTPLUG_EVENT_OFF);
outb(0, priv->plat->fan_reg_offset + MLXCPLD_HOTPLUG_MASK_OFF);
outb(0, priv->plat->fan_reg_offset + MLXCPLD_HOTPLUG_EVENT_OFF);
for (i = 0; i < priv->plat->psu_count; i++)
mlxcpld_hotplug_device_destroy(priv->plat->psu + i);
for (i = 0; i < priv->plat->pwr_count; i++)
mlxcpld_hotplug_device_destroy(priv->plat->pwr + i);
for (i = 0; i < priv->plat->fan_count; i++)
mlxcpld_hotplug_device_destroy(priv->plat->fan + i);
}
static irqreturn_t mlxcpld_hotplug_irq_handler(int irq, void *dev)
{
struct mlxcpld_hotplug_priv_data *priv =
(struct mlxcpld_hotplug_priv_data *)dev;
schedule_delayed_work(&priv->dwork, 0);
return IRQ_HANDLED;
}
static int mlxcpld_hotplug_probe(struct platform_device *pdev)
{
struct mlxcpld_hotplug_platform_data *pdata;
struct mlxcpld_hotplug_priv_data *priv;
int err;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "Failed to get platform data.\n");
return -EINVAL;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->pdev = pdev;
priv->plat = pdata;
priv->irq = platform_get_irq(pdev, 0);
if (priv->irq < 0) {
dev_err(&pdev->dev, "Failed to get platform irq: %d\n",
priv->irq);
return priv->irq;
}
err = devm_request_irq(&pdev->dev, priv->irq,
mlxcpld_hotplug_irq_handler, 0, pdev->name,
priv);
if (err) {
dev_err(&pdev->dev, "Failed to request irq: %d\n", err);
return err;
}
disable_irq(priv->irq);
INIT_DELAYED_WORK(&priv->dwork, mlxcpld_hotplug_work_handler);
spin_lock_init(&priv->lock);
err = mlxcpld_hotplug_attr_init(priv);
if (err) {
dev_err(&pdev->dev, "Failed to allocate attributes: %d\n", err);
return err;
}
priv->hwmon = devm_hwmon_device_register_with_groups(&pdev->dev,
"mlxcpld_hotplug", priv, priv->groups);
if (IS_ERR(priv->hwmon)) {
dev_err(&pdev->dev, "Failed to register hwmon device %ld\n",
PTR_ERR(priv->hwmon));
return PTR_ERR(priv->hwmon);
}
platform_set_drvdata(pdev, priv);
mlxcpld_hotplug_set_irq(priv);
return 0;
}
static int mlxcpld_hotplug_remove(struct platform_device *pdev)
{
struct mlxcpld_hotplug_priv_data *priv = platform_get_drvdata(pdev);
mlxcpld_hotplug_unset_irq(priv);
return 0;
}
