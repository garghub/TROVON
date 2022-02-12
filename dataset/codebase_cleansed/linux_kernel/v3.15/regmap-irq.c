static inline const
struct regmap_irq *irq_to_regmap_irq(struct regmap_irq_chip_data *data,
int irq)
{
return &data->chip->irqs[irq];
}
static void regmap_irq_lock(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
mutex_lock(&d->lock);
}
static void regmap_irq_sync_unlock(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
struct regmap *map = d->map;
int i, ret;
u32 reg;
if (d->chip->runtime_pm) {
ret = pm_runtime_get_sync(map->dev);
if (ret < 0)
dev_err(map->dev, "IRQ sync failed to resume: %d\n",
ret);
}
for (i = 0; i < d->chip->num_regs; i++) {
reg = d->chip->mask_base +
(i * map->reg_stride * d->irq_reg_stride);
if (d->chip->mask_invert)
ret = regmap_update_bits(d->map, reg,
d->mask_buf_def[i], ~d->mask_buf[i]);
else
ret = regmap_update_bits(d->map, reg,
d->mask_buf_def[i], d->mask_buf[i]);
if (ret != 0)
dev_err(d->map->dev, "Failed to sync masks in %x\n",
reg);
reg = d->chip->wake_base +
(i * map->reg_stride * d->irq_reg_stride);
if (d->wake_buf) {
if (d->chip->wake_invert)
ret = regmap_update_bits(d->map, reg,
d->mask_buf_def[i],
~d->wake_buf[i]);
else
ret = regmap_update_bits(d->map, reg,
d->mask_buf_def[i],
d->wake_buf[i]);
if (ret != 0)
dev_err(d->map->dev,
"Failed to sync wakes in %x: %d\n",
reg, ret);
}
if (!d->chip->init_ack_masked)
continue;
if (d->mask_buf[i] && (d->chip->ack_base || d->chip->use_ack)) {
reg = d->chip->ack_base +
(i * map->reg_stride * d->irq_reg_stride);
ret = regmap_write(map, reg, d->mask_buf[i]);
if (ret != 0)
dev_err(d->map->dev, "Failed to ack 0x%x: %d\n",
reg, ret);
}
}
if (d->chip->runtime_pm)
pm_runtime_put(map->dev);
if (d->wake_count < 0)
for (i = d->wake_count; i < 0; i++)
irq_set_irq_wake(d->irq, 0);
else if (d->wake_count > 0)
for (i = 0; i < d->wake_count; i++)
irq_set_irq_wake(d->irq, 1);
d->wake_count = 0;
mutex_unlock(&d->lock);
}
static void regmap_irq_enable(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
struct regmap *map = d->map;
const struct regmap_irq *irq_data = irq_to_regmap_irq(d, data->hwirq);
d->mask_buf[irq_data->reg_offset / map->reg_stride] &= ~irq_data->mask;
}
static void regmap_irq_disable(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
struct regmap *map = d->map;
const struct regmap_irq *irq_data = irq_to_regmap_irq(d, data->hwirq);
d->mask_buf[irq_data->reg_offset / map->reg_stride] |= irq_data->mask;
}
static int regmap_irq_set_wake(struct irq_data *data, unsigned int on)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
struct regmap *map = d->map;
const struct regmap_irq *irq_data = irq_to_regmap_irq(d, data->hwirq);
if (on) {
if (d->wake_buf)
d->wake_buf[irq_data->reg_offset / map->reg_stride]
&= ~irq_data->mask;
d->wake_count++;
} else {
if (d->wake_buf)
d->wake_buf[irq_data->reg_offset / map->reg_stride]
|= irq_data->mask;
d->wake_count--;
}
return 0;
}
static irqreturn_t regmap_irq_thread(int irq, void *d)
{
struct regmap_irq_chip_data *data = d;
const struct regmap_irq_chip *chip = data->chip;
struct regmap *map = data->map;
int ret, i;
bool handled = false;
u32 reg;
if (chip->runtime_pm) {
ret = pm_runtime_get_sync(map->dev);
if (ret < 0) {
dev_err(map->dev, "IRQ thread failed to resume: %d\n",
ret);
pm_runtime_put(map->dev);
return IRQ_NONE;
}
}
if (!map->use_single_rw && map->reg_stride == 1 &&
data->irq_reg_stride == 1) {
u8 *buf8 = data->status_reg_buf;
u16 *buf16 = data->status_reg_buf;
u32 *buf32 = data->status_reg_buf;
BUG_ON(!data->status_reg_buf);
ret = regmap_bulk_read(map, chip->status_base,
data->status_reg_buf,
chip->num_regs);
if (ret != 0) {
dev_err(map->dev, "Failed to read IRQ status: %d\n",
ret);
return IRQ_NONE;
}
for (i = 0; i < data->chip->num_regs; i++) {
switch (map->format.val_bytes) {
case 1:
data->status_buf[i] = buf8[i];
break;
case 2:
data->status_buf[i] = buf16[i];
break;
case 4:
data->status_buf[i] = buf32[i];
break;
default:
BUG();
return IRQ_NONE;
}
}
} else {
for (i = 0; i < data->chip->num_regs; i++) {
ret = regmap_read(map, chip->status_base +
(i * map->reg_stride
* data->irq_reg_stride),
&data->status_buf[i]);
if (ret != 0) {
dev_err(map->dev,
"Failed to read IRQ status: %d\n",
ret);
if (chip->runtime_pm)
pm_runtime_put(map->dev);
return IRQ_NONE;
}
}
}
for (i = 0; i < data->chip->num_regs; i++) {
data->status_buf[i] &= ~data->mask_buf[i];
if (data->status_buf[i] && (chip->ack_base || chip->use_ack)) {
reg = chip->ack_base +
(i * map->reg_stride * data->irq_reg_stride);
ret = regmap_write(map, reg, data->status_buf[i]);
if (ret != 0)
dev_err(map->dev, "Failed to ack 0x%x: %d\n",
reg, ret);
}
}
for (i = 0; i < chip->num_irqs; i++) {
if (data->status_buf[chip->irqs[i].reg_offset /
map->reg_stride] & chip->irqs[i].mask) {
handle_nested_irq(irq_find_mapping(data->domain, i));
handled = true;
}
}
if (chip->runtime_pm)
pm_runtime_put(map->dev);
if (handled)
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static int regmap_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct regmap_irq_chip_data *data = h->host_data;
irq_set_chip_data(virq, data);
irq_set_chip(virq, &data->irq_chip);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
int regmap_add_irq_chip(struct regmap *map, int irq, int irq_flags,
int irq_base, const struct regmap_irq_chip *chip,
struct regmap_irq_chip_data **data)
{
struct regmap_irq_chip_data *d;
int i;
int ret = -ENOMEM;
u32 reg;
for (i = 0; i < chip->num_irqs; i++) {
if (chip->irqs[i].reg_offset % map->reg_stride)
return -EINVAL;
if (chip->irqs[i].reg_offset / map->reg_stride >=
chip->num_regs)
return -EINVAL;
}
if (irq_base) {
irq_base = irq_alloc_descs(irq_base, 0, chip->num_irqs, 0);
if (irq_base < 0) {
dev_warn(map->dev, "Failed to allocate IRQs: %d\n",
irq_base);
return irq_base;
}
}
d = kzalloc(sizeof(*d), GFP_KERNEL);
if (!d)
return -ENOMEM;
d->status_buf = kzalloc(sizeof(unsigned int) * chip->num_regs,
GFP_KERNEL);
if (!d->status_buf)
goto err_alloc;
d->mask_buf = kzalloc(sizeof(unsigned int) * chip->num_regs,
GFP_KERNEL);
if (!d->mask_buf)
goto err_alloc;
d->mask_buf_def = kzalloc(sizeof(unsigned int) * chip->num_regs,
GFP_KERNEL);
if (!d->mask_buf_def)
goto err_alloc;
if (chip->wake_base) {
d->wake_buf = kzalloc(sizeof(unsigned int) * chip->num_regs,
GFP_KERNEL);
if (!d->wake_buf)
goto err_alloc;
}
d->irq_chip = regmap_irq_chip;
d->irq_chip.name = chip->name;
d->irq = irq;
d->map = map;
d->chip = chip;
d->irq_base = irq_base;
if (chip->irq_reg_stride)
d->irq_reg_stride = chip->irq_reg_stride;
else
d->irq_reg_stride = 1;
if (!map->use_single_rw && map->reg_stride == 1 &&
d->irq_reg_stride == 1) {
d->status_reg_buf = kmalloc(map->format.val_bytes *
chip->num_regs, GFP_KERNEL);
if (!d->status_reg_buf)
goto err_alloc;
}
mutex_init(&d->lock);
for (i = 0; i < chip->num_irqs; i++)
d->mask_buf_def[chip->irqs[i].reg_offset / map->reg_stride]
|= chip->irqs[i].mask;
for (i = 0; i < chip->num_regs; i++) {
d->mask_buf[i] = d->mask_buf_def[i];
reg = chip->mask_base +
(i * map->reg_stride * d->irq_reg_stride);
if (chip->mask_invert)
ret = regmap_update_bits(map, reg,
d->mask_buf[i], ~d->mask_buf[i]);
else
ret = regmap_update_bits(map, reg,
d->mask_buf[i], d->mask_buf[i]);
if (ret != 0) {
dev_err(map->dev, "Failed to set masks in 0x%x: %d\n",
reg, ret);
goto err_alloc;
}
if (!chip->init_ack_masked)
continue;
reg = chip->status_base +
(i * map->reg_stride * d->irq_reg_stride);
ret = regmap_read(map, reg, &d->status_buf[i]);
if (ret != 0) {
dev_err(map->dev, "Failed to read IRQ status: %d\n",
ret);
goto err_alloc;
}
if (d->status_buf[i] && (chip->ack_base || chip->use_ack)) {
reg = chip->ack_base +
(i * map->reg_stride * d->irq_reg_stride);
ret = regmap_write(map, reg,
d->status_buf[i] & d->mask_buf[i]);
if (ret != 0) {
dev_err(map->dev, "Failed to ack 0x%x: %d\n",
reg, ret);
goto err_alloc;
}
}
}
if (d->wake_buf) {
for (i = 0; i < chip->num_regs; i++) {
d->wake_buf[i] = d->mask_buf_def[i];
reg = chip->wake_base +
(i * map->reg_stride * d->irq_reg_stride);
if (chip->wake_invert)
ret = regmap_update_bits(map, reg,
d->mask_buf_def[i],
0);
else
ret = regmap_update_bits(map, reg,
d->mask_buf_def[i],
d->wake_buf[i]);
if (ret != 0) {
dev_err(map->dev, "Failed to set masks in 0x%x: %d\n",
reg, ret);
goto err_alloc;
}
}
}
if (irq_base)
d->domain = irq_domain_add_legacy(map->dev->of_node,
chip->num_irqs, irq_base, 0,
&regmap_domain_ops, d);
else
d->domain = irq_domain_add_linear(map->dev->of_node,
chip->num_irqs,
&regmap_domain_ops, d);
if (!d->domain) {
dev_err(map->dev, "Failed to create IRQ domain\n");
ret = -ENOMEM;
goto err_alloc;
}
ret = request_threaded_irq(irq, NULL, regmap_irq_thread, irq_flags,
chip->name, d);
if (ret != 0) {
dev_err(map->dev, "Failed to request IRQ %d for %s: %d\n",
irq, chip->name, ret);
goto err_domain;
}
*data = d;
return 0;
err_domain:
err_alloc:
kfree(d->wake_buf);
kfree(d->mask_buf_def);
kfree(d->mask_buf);
kfree(d->status_buf);
kfree(d->status_reg_buf);
kfree(d);
return ret;
}
void regmap_del_irq_chip(int irq, struct regmap_irq_chip_data *d)
{
if (!d)
return;
free_irq(irq, d);
irq_domain_remove(d->domain);
kfree(d->wake_buf);
kfree(d->mask_buf_def);
kfree(d->mask_buf);
kfree(d->status_reg_buf);
kfree(d->status_buf);
kfree(d);
}
int regmap_irq_chip_get_base(struct regmap_irq_chip_data *data)
{
WARN_ON(!data->irq_base);
return data->irq_base;
}
int regmap_irq_get_virq(struct regmap_irq_chip_data *data, int irq)
{
if (!data->chip->irqs[irq].mask)
return -EINVAL;
return irq_create_mapping(data->domain, irq);
}
struct irq_domain *regmap_irq_get_domain(struct regmap_irq_chip_data *data)
{
if (data)
return data->domain;
else
return NULL;
}
