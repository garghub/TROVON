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
static int regmap_irq_update_bits(struct regmap_irq_chip_data *d,
unsigned int reg, unsigned int mask,
unsigned int val)
{
if (d->chip->mask_writeonly)
return regmap_write_bits(d->map, reg, mask, val);
else
return regmap_update_bits(d->map, reg, mask, val);
}
static void regmap_irq_sync_unlock(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
struct regmap *map = d->map;
int i, ret;
u32 reg;
u32 unmask_offset;
if (d->chip->runtime_pm) {
ret = pm_runtime_get_sync(map->dev);
if (ret < 0)
dev_err(map->dev, "IRQ sync failed to resume: %d\n",
ret);
}
for (i = 0; i < d->chip->num_regs; i++) {
reg = d->chip->mask_base +
(i * map->reg_stride * d->irq_reg_stride);
if (d->chip->mask_invert) {
ret = regmap_irq_update_bits(d, reg,
d->mask_buf_def[i], ~d->mask_buf[i]);
} else if (d->chip->unmask_base) {
ret = regmap_irq_update_bits(d, reg,
d->mask_buf_def[i], ~d->mask_buf[i]);
if (ret < 0)
dev_err(d->map->dev,
"Failed to sync unmasks in %x\n",
reg);
unmask_offset = d->chip->unmask_base -
d->chip->mask_base;
ret = regmap_irq_update_bits(d,
reg + unmask_offset,
d->mask_buf_def[i],
d->mask_buf[i]);
} else {
ret = regmap_irq_update_bits(d, reg,
d->mask_buf_def[i], d->mask_buf[i]);
}
if (ret != 0)
dev_err(d->map->dev, "Failed to sync masks in %x\n",
reg);
reg = d->chip->wake_base +
(i * map->reg_stride * d->irq_reg_stride);
if (d->wake_buf) {
if (d->chip->wake_invert)
ret = regmap_irq_update_bits(d, reg,
d->mask_buf_def[i],
~d->wake_buf[i]);
else
ret = regmap_irq_update_bits(d, reg,
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
if (d->chip->ack_invert)
ret = regmap_write(map, reg, ~d->mask_buf[i]);
else
ret = regmap_write(map, reg, d->mask_buf[i]);
if (ret != 0)
dev_err(d->map->dev, "Failed to ack 0x%x: %d\n",
reg, ret);
}
}
for (i = 0; i < d->chip->num_type_reg; i++) {
if (!d->type_buf_def[i])
continue;
reg = d->chip->type_base +
(i * map->reg_stride * d->type_reg_stride);
if (d->chip->type_invert)
ret = regmap_irq_update_bits(d, reg,
d->type_buf_def[i], ~d->type_buf[i]);
else
ret = regmap_irq_update_bits(d, reg,
d->type_buf_def[i], d->type_buf[i]);
if (ret != 0)
dev_err(d->map->dev, "Failed to sync type in %x\n",
reg);
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
static int regmap_irq_set_type(struct irq_data *data, unsigned int type)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
struct regmap *map = d->map;
const struct regmap_irq *irq_data = irq_to_regmap_irq(d, data->hwirq);
int reg = irq_data->type_reg_offset / map->reg_stride;
if (!(irq_data->type_rising_mask | irq_data->type_falling_mask))
return 0;
d->type_buf[reg] &= ~(irq_data->type_falling_mask |
irq_data->type_rising_mask);
switch (type) {
case IRQ_TYPE_EDGE_FALLING:
d->type_buf[reg] |= irq_data->type_falling_mask;
break;
case IRQ_TYPE_EDGE_RISING:
d->type_buf[reg] |= irq_data->type_rising_mask;
break;
case IRQ_TYPE_EDGE_BOTH:
d->type_buf[reg] |= (irq_data->type_falling_mask |
irq_data->type_rising_mask);
break;
default:
return -EINVAL;
}
return 0;
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
if (chip->handle_pre_irq)
chip->handle_pre_irq(chip->irq_drv_data);
if (chip->runtime_pm) {
ret = pm_runtime_get_sync(map->dev);
if (ret < 0) {
dev_err(map->dev, "IRQ thread failed to resume: %d\n",
ret);
pm_runtime_put(map->dev);
goto exit;
}
}
if (!map->use_single_read && map->reg_stride == 1 &&
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
goto exit;
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
goto exit;
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
goto exit;
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
exit:
if (chip->handle_post_irq)
chip->handle_post_irq(chip->irq_drv_data);
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
irq_set_parent(virq, data->irq);
irq_set_noprobe(virq);
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
u32 unmask_offset;
if (chip->num_regs <= 0)
return -EINVAL;
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
d->status_buf = kcalloc(chip->num_regs, sizeof(unsigned int),
GFP_KERNEL);
if (!d->status_buf)
goto err_alloc;
d->mask_buf = kcalloc(chip->num_regs, sizeof(unsigned int),
GFP_KERNEL);
if (!d->mask_buf)
goto err_alloc;
d->mask_buf_def = kcalloc(chip->num_regs, sizeof(unsigned int),
GFP_KERNEL);
if (!d->mask_buf_def)
goto err_alloc;
if (chip->wake_base) {
d->wake_buf = kcalloc(chip->num_regs, sizeof(unsigned int),
GFP_KERNEL);
if (!d->wake_buf)
goto err_alloc;
}
if (chip->num_type_reg) {
d->type_buf_def = kcalloc(chip->num_type_reg,
sizeof(unsigned int), GFP_KERNEL);
if (!d->type_buf_def)
goto err_alloc;
d->type_buf = kcalloc(chip->num_type_reg, sizeof(unsigned int),
GFP_KERNEL);
if (!d->type_buf)
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
if (chip->type_reg_stride)
d->type_reg_stride = chip->type_reg_stride;
else
d->type_reg_stride = 1;
if (!map->use_single_read && map->reg_stride == 1 &&
d->irq_reg_stride == 1) {
d->status_reg_buf = kmalloc_array(chip->num_regs,
map->format.val_bytes,
GFP_KERNEL);
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
ret = regmap_irq_update_bits(d, reg,
d->mask_buf[i], ~d->mask_buf[i]);
else if (d->chip->unmask_base) {
unmask_offset = d->chip->unmask_base -
d->chip->mask_base;
ret = regmap_irq_update_bits(d,
reg + unmask_offset,
d->mask_buf[i],
d->mask_buf[i]);
} else
ret = regmap_irq_update_bits(d, reg,
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
if (chip->ack_invert)
ret = regmap_write(map, reg,
~(d->status_buf[i] & d->mask_buf[i]));
else
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
ret = regmap_irq_update_bits(d, reg,
d->mask_buf_def[i],
0);
else
ret = regmap_irq_update_bits(d, reg,
d->mask_buf_def[i],
d->wake_buf[i]);
if (ret != 0) {
dev_err(map->dev, "Failed to set masks in 0x%x: %d\n",
reg, ret);
goto err_alloc;
}
}
}
if (chip->num_type_reg) {
for (i = 0; i < chip->num_irqs; i++) {
reg = chip->irqs[i].type_reg_offset / map->reg_stride;
d->type_buf_def[reg] |= chip->irqs[i].type_rising_mask |
chip->irqs[i].type_falling_mask;
}
for (i = 0; i < chip->num_type_reg; ++i) {
if (!d->type_buf_def[i])
continue;
reg = chip->type_base +
(i * map->reg_stride * d->type_reg_stride);
if (chip->type_invert)
ret = regmap_irq_update_bits(d, reg,
d->type_buf_def[i], 0xFF);
else
ret = regmap_irq_update_bits(d, reg,
d->type_buf_def[i], 0x0);
if (ret != 0) {
dev_err(map->dev,
"Failed to set type in 0x%x: %x\n",
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
ret = request_threaded_irq(irq, NULL, regmap_irq_thread,
irq_flags | IRQF_ONESHOT,
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
kfree(d->type_buf);
kfree(d->type_buf_def);
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
unsigned int virq;
int hwirq;
if (!d)
return;
free_irq(irq, d);
for (hwirq = 0; hwirq < d->chip->num_irqs; hwirq++) {
if (!d->chip->irqs[hwirq].mask)
continue;
virq = irq_find_mapping(d->domain, hwirq);
if (virq)
irq_dispose_mapping(virq);
}
irq_domain_remove(d->domain);
kfree(d->type_buf);
kfree(d->type_buf_def);
kfree(d->wake_buf);
kfree(d->mask_buf_def);
kfree(d->mask_buf);
kfree(d->status_reg_buf);
kfree(d->status_buf);
kfree(d);
}
static void devm_regmap_irq_chip_release(struct device *dev, void *res)
{
struct regmap_irq_chip_data *d = *(struct regmap_irq_chip_data **)res;
regmap_del_irq_chip(d->irq, d);
}
static int devm_regmap_irq_chip_match(struct device *dev, void *res, void *data)
{
struct regmap_irq_chip_data **r = res;
if (!r || !*r) {
WARN_ON(!r || !*r);
return 0;
}
return *r == data;
}
int devm_regmap_add_irq_chip(struct device *dev, struct regmap *map, int irq,
int irq_flags, int irq_base,
const struct regmap_irq_chip *chip,
struct regmap_irq_chip_data **data)
{
struct regmap_irq_chip_data **ptr, *d;
int ret;
ptr = devres_alloc(devm_regmap_irq_chip_release, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return -ENOMEM;
ret = regmap_add_irq_chip(map, irq, irq_flags, irq_base,
chip, &d);
if (ret < 0) {
devres_free(ptr);
return ret;
}
*ptr = d;
devres_add(dev, ptr);
*data = d;
return 0;
}
void devm_regmap_del_irq_chip(struct device *dev, int irq,
struct regmap_irq_chip_data *data)
{
int rc;
WARN_ON(irq != data->irq);
rc = devres_release(dev, devm_regmap_irq_chip_release,
devm_regmap_irq_chip_match, data);
if (rc != 0)
WARN_ON(rc);
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
