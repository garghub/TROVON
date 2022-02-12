static inline int irq_to_tps65912_irq(struct tps65912 *tps65912,
int irq)
{
return irq - tps65912->irq_base;
}
static irqreturn_t tps65912_irq(int irq, void *irq_data)
{
struct tps65912 *tps65912 = irq_data;
u32 irq_sts;
u32 irq_mask;
u8 reg;
int i;
tps65912->read(tps65912, TPS65912_INT_STS, 1, &reg);
irq_sts = reg;
tps65912->read(tps65912, TPS65912_INT_STS2, 1, &reg);
irq_sts |= reg << 8;
tps65912->read(tps65912, TPS65912_INT_STS3, 1, &reg);
irq_sts |= reg << 16;
tps65912->read(tps65912, TPS65912_INT_STS4, 1, &reg);
irq_sts |= reg << 24;
tps65912->read(tps65912, TPS65912_INT_MSK, 1, &reg);
irq_mask = reg;
tps65912->read(tps65912, TPS65912_INT_MSK2, 1, &reg);
irq_mask |= reg << 8;
tps65912->read(tps65912, TPS65912_INT_MSK3, 1, &reg);
irq_mask |= reg << 16;
tps65912->read(tps65912, TPS65912_INT_MSK4, 1, &reg);
irq_mask |= reg << 24;
irq_sts &= ~irq_mask;
if (!irq_sts)
return IRQ_NONE;
for (i = 0; i < tps65912->irq_num; i++) {
if (!(irq_sts & (1 << i)))
continue;
handle_nested_irq(tps65912->irq_base + i);
}
reg = irq_sts & 0xFF;
irq_sts >>= 8;
if (reg)
tps65912->write(tps65912, TPS65912_INT_STS, 1, &reg);
reg = irq_sts & 0xFF;
irq_sts >>= 8;
if (reg)
tps65912->write(tps65912, TPS65912_INT_STS2, 1, &reg);
reg = irq_sts & 0xFF;
irq_sts >>= 8;
if (reg)
tps65912->write(tps65912, TPS65912_INT_STS3, 1, &reg);
reg = irq_sts & 0xFF;
if (reg)
tps65912->write(tps65912, TPS65912_INT_STS4, 1, &reg);
return IRQ_HANDLED;
}
static void tps65912_irq_lock(struct irq_data *data)
{
struct tps65912 *tps65912 = irq_data_get_irq_chip_data(data);
mutex_lock(&tps65912->irq_lock);
}
static void tps65912_irq_sync_unlock(struct irq_data *data)
{
struct tps65912 *tps65912 = irq_data_get_irq_chip_data(data);
u32 reg_mask;
u8 reg;
tps65912->read(tps65912, TPS65912_INT_MSK, 1, &reg);
reg_mask = reg;
tps65912->read(tps65912, TPS65912_INT_MSK2, 1, &reg);
reg_mask |= reg << 8;
tps65912->read(tps65912, TPS65912_INT_MSK3, 1, &reg);
reg_mask |= reg << 16;
tps65912->read(tps65912, TPS65912_INT_MSK4, 1, &reg);
reg_mask |= reg << 24;
if (tps65912->irq_mask != reg_mask) {
reg = tps65912->irq_mask & 0xFF;
tps65912->write(tps65912, TPS65912_INT_MSK, 1, &reg);
reg = tps65912->irq_mask >> 8 & 0xFF;
tps65912->write(tps65912, TPS65912_INT_MSK2, 1, &reg);
reg = tps65912->irq_mask >> 16 & 0xFF;
tps65912->write(tps65912, TPS65912_INT_MSK3, 1, &reg);
reg = tps65912->irq_mask >> 24 & 0xFF;
tps65912->write(tps65912, TPS65912_INT_MSK4, 1, &reg);
}
mutex_unlock(&tps65912->irq_lock);
}
static void tps65912_irq_enable(struct irq_data *data)
{
struct tps65912 *tps65912 = irq_data_get_irq_chip_data(data);
tps65912->irq_mask &= ~(1 << irq_to_tps65912_irq(tps65912, data->irq));
}
static void tps65912_irq_disable(struct irq_data *data)
{
struct tps65912 *tps65912 = irq_data_get_irq_chip_data(data);
tps65912->irq_mask |= (1 << irq_to_tps65912_irq(tps65912, data->irq));
}
int tps65912_irq_init(struct tps65912 *tps65912, int irq,
struct tps65912_platform_data *pdata)
{
int ret, cur_irq;
int flags = IRQF_ONESHOT;
u8 reg;
if (!irq) {
dev_warn(tps65912->dev, "No interrupt support, no core IRQ\n");
return 0;
}
if (!pdata || !pdata->irq_base) {
dev_warn(tps65912->dev, "No interrupt support, no IRQ base\n");
return 0;
}
tps65912->read(tps65912, TPS65912_INT_STS, 1, &reg);
tps65912->write(tps65912, TPS65912_INT_STS, 1, &reg);
tps65912->read(tps65912, TPS65912_INT_STS2, 1, &reg);
tps65912->write(tps65912, TPS65912_INT_STS2, 1, &reg);
tps65912->read(tps65912, TPS65912_INT_STS3, 1, &reg);
tps65912->write(tps65912, TPS65912_INT_STS3, 1, &reg);
tps65912->read(tps65912, TPS65912_INT_STS4, 1, &reg);
tps65912->write(tps65912, TPS65912_INT_STS4, 1, &reg);
tps65912->irq_mask = 0xFFFFFFFF;
mutex_init(&tps65912->irq_lock);
tps65912->chip_irq = irq;
tps65912->irq_base = pdata->irq_base;
tps65912->irq_num = TPS65912_NUM_IRQ;
for (cur_irq = tps65912->irq_base;
cur_irq < tps65912->irq_num + tps65912->irq_base;
cur_irq++) {
irq_set_chip_data(cur_irq, tps65912);
irq_set_chip_and_handler(cur_irq, &tps65912_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
irq_clear_status_flags(cur_irq, IRQ_NOREQUEST | IRQ_NOPROBE);
}
ret = request_threaded_irq(irq, NULL, tps65912_irq, flags,
"tps65912", tps65912);
irq_set_irq_type(irq, IRQ_TYPE_LEVEL_LOW);
if (ret != 0)
dev_err(tps65912->dev, "Failed to request IRQ: %d\n", ret);
return ret;
}
int tps65912_irq_exit(struct tps65912 *tps65912)
{
free_irq(tps65912->chip_irq, tps65912);
return 0;
}
