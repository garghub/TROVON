static inline const
struct regmap_irq *irq_to_regmap_irq(struct regmap_irq_chip_data *data,
int irq)
{
return &data->chip->irqs[irq - data->irq_base];
}
static void regmap_irq_lock(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
mutex_lock(&d->lock);
}
static void regmap_irq_sync_unlock(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
int i, ret;
for (i = 0; i < d->chip->num_regs; i++) {
ret = regmap_update_bits(d->map, d->chip->mask_base + i,
d->mask_buf_def[i], d->mask_buf[i]);
if (ret != 0)
dev_err(d->map->dev, "Failed to sync masks in %x\n",
d->chip->mask_base + i);
}
mutex_unlock(&d->lock);
}
static void regmap_irq_enable(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
const struct regmap_irq *irq_data = irq_to_regmap_irq(d, data->irq);
d->mask_buf[irq_data->reg_offset] &= ~irq_data->mask;
}
static void regmap_irq_disable(struct irq_data *data)
{
struct regmap_irq_chip_data *d = irq_data_get_irq_chip_data(data);
const struct regmap_irq *irq_data = irq_to_regmap_irq(d, data->irq);
d->mask_buf[irq_data->reg_offset] |= irq_data->mask;
}
static irqreturn_t regmap_irq_thread(int irq, void *d)
{
struct regmap_irq_chip_data *data = d;
struct regmap_irq_chip *chip = data->chip;
struct regmap *map = data->map;
int ret, i;
u8 *buf8 = data->status_reg_buf;
u16 *buf16 = data->status_reg_buf;
u32 *buf32 = data->status_reg_buf;
bool handled = false;
ret = regmap_bulk_read(map, chip->status_base, data->status_reg_buf,
chip->num_regs);
if (ret != 0) {
dev_err(map->dev, "Failed to read IRQ status: %d\n", ret);
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
data->status_buf[i] &= ~data->mask_buf[i];
if (data->status_buf[i] && chip->ack_base) {
ret = regmap_write(map, chip->ack_base + i,
data->status_buf[i]);
if (ret != 0)
dev_err(map->dev, "Failed to ack 0x%x: %d\n",
chip->ack_base + i, ret);
}
}
for (i = 0; i < chip->num_irqs; i++) {
if (data->status_buf[chip->irqs[i].reg_offset] &
chip->irqs[i].mask) {
handle_nested_irq(data->irq_base + i);
handled = true;
}
}
if (handled)
return IRQ_HANDLED;
else
return IRQ_NONE;
}
int regmap_add_irq_chip(struct regmap *map, int irq, int irq_flags,
int irq_base, struct regmap_irq_chip *chip,
struct regmap_irq_chip_data **data)
{
struct regmap_irq_chip_data *d;
int cur_irq, i;
int ret = -ENOMEM;
irq_base = irq_alloc_descs(irq_base, 0, chip->num_irqs, 0);
if (irq_base < 0) {
dev_warn(map->dev, "Failed to allocate IRQs: %d\n",
irq_base);
return irq_base;
}
d = kzalloc(sizeof(*d), GFP_KERNEL);
if (!d)
return -ENOMEM;
d->status_buf = kzalloc(sizeof(unsigned int) * chip->num_regs,
GFP_KERNEL);
if (!d->status_buf)
goto err_alloc;
d->status_reg_buf = kzalloc(map->format.val_bytes * chip->num_regs,
GFP_KERNEL);
if (!d->status_reg_buf)
goto err_alloc;
d->mask_buf = kzalloc(sizeof(unsigned int) * chip->num_regs,
GFP_KERNEL);
if (!d->mask_buf)
goto err_alloc;
d->mask_buf_def = kzalloc(sizeof(unsigned int) * chip->num_regs,
GFP_KERNEL);
if (!d->mask_buf_def)
goto err_alloc;
d->map = map;
d->chip = chip;
d->irq_base = irq_base;
mutex_init(&d->lock);
for (i = 0; i < chip->num_irqs; i++)
d->mask_buf_def[chip->irqs[i].reg_offset]
|= chip->irqs[i].mask;
for (i = 0; i < chip->num_regs; i++) {
d->mask_buf[i] = d->mask_buf_def[i];
ret = regmap_write(map, chip->mask_base + i, d->mask_buf[i]);
if (ret != 0) {
dev_err(map->dev, "Failed to set masks in 0x%x: %d\n",
chip->mask_base + i, ret);
goto err_alloc;
}
}
for (cur_irq = irq_base;
cur_irq < chip->num_irqs + irq_base;
cur_irq++) {
irq_set_chip_data(cur_irq, d);
irq_set_chip_and_handler(cur_irq, &regmap_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(cur_irq, IRQF_VALID);
#else
irq_set_noprobe(cur_irq);
#endif
}
ret = request_threaded_irq(irq, NULL, regmap_irq_thread, irq_flags,
chip->name, d);
if (ret != 0) {
dev_err(map->dev, "Failed to request IRQ %d: %d\n", irq, ret);
goto err_alloc;
}
return 0;
err_alloc:
kfree(d->mask_buf_def);
kfree(d->mask_buf);
kfree(d->status_reg_buf);
kfree(d->status_buf);
kfree(d);
return ret;
}
void regmap_del_irq_chip(int irq, struct regmap_irq_chip_data *d)
{
if (!d)
return;
free_irq(irq, d);
kfree(d->mask_buf_def);
kfree(d->mask_buf);
kfree(d->status_reg_buf);
kfree(d->status_buf);
kfree(d);
}
int regmap_irq_chip_get_base(struct regmap_irq_chip_data *data)
{
return data->irq_base;
}
