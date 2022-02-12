static u32 ipu_read_reg(struct ipu *ipu, unsigned long reg)
{
return __raw_readl(ipu->reg_ipu + reg);
}
static void ipu_write_reg(struct ipu *ipu, u32 value, unsigned long reg)
{
__raw_writel(value, ipu->reg_ipu + reg);
}
static struct ipu_irq_map *src2map(unsigned int src)
{
int i;
for (i = 0; i < CONFIG_MX3_IPU_IRQS; i++)
if (irq_map[i].source == src)
return irq_map + i;
return NULL;
}
static void ipu_irq_unmask(struct irq_data *d)
{
struct ipu_irq_map *map = irq_data_get_irq_chip_data(d);
struct ipu_irq_bank *bank;
uint32_t reg;
unsigned long lock_flags;
raw_spin_lock_irqsave(&bank_lock, lock_flags);
bank = map->bank;
if (!bank) {
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
pr_err("IPU: %s(%u) - unmapped!\n", __func__, d->irq);
return;
}
reg = ipu_read_reg(bank->ipu, bank->control);
reg |= (1UL << (map->source & 31));
ipu_write_reg(bank->ipu, reg, bank->control);
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
}
static void ipu_irq_mask(struct irq_data *d)
{
struct ipu_irq_map *map = irq_data_get_irq_chip_data(d);
struct ipu_irq_bank *bank;
uint32_t reg;
unsigned long lock_flags;
raw_spin_lock_irqsave(&bank_lock, lock_flags);
bank = map->bank;
if (!bank) {
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
pr_err("IPU: %s(%u) - unmapped!\n", __func__, d->irq);
return;
}
reg = ipu_read_reg(bank->ipu, bank->control);
reg &= ~(1UL << (map->source & 31));
ipu_write_reg(bank->ipu, reg, bank->control);
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
}
static void ipu_irq_ack(struct irq_data *d)
{
struct ipu_irq_map *map = irq_data_get_irq_chip_data(d);
struct ipu_irq_bank *bank;
unsigned long lock_flags;
raw_spin_lock_irqsave(&bank_lock, lock_flags);
bank = map->bank;
if (!bank) {
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
pr_err("IPU: %s(%u) - unmapped!\n", __func__, d->irq);
return;
}
ipu_write_reg(bank->ipu, 1UL << (map->source & 31), bank->status);
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
}
bool ipu_irq_status(unsigned int irq)
{
struct ipu_irq_map *map = irq_get_chip_data(irq);
struct ipu_irq_bank *bank;
unsigned long lock_flags;
bool ret;
raw_spin_lock_irqsave(&bank_lock, lock_flags);
bank = map->bank;
ret = bank && ipu_read_reg(bank->ipu, bank->status) &
(1UL << (map->source & 31));
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
return ret;
}
int ipu_irq_map(unsigned int source)
{
int i, ret = -ENOMEM;
struct ipu_irq_map *map;
might_sleep();
mutex_lock(&map_lock);
map = src2map(source);
if (map) {
pr_err("IPU: Source %u already mapped to IRQ %u\n", source, map->irq);
ret = -EBUSY;
goto out;
}
for (i = 0; i < CONFIG_MX3_IPU_IRQS; i++) {
if (irq_map[i].source < 0) {
unsigned long lock_flags;
raw_spin_lock_irqsave(&bank_lock, lock_flags);
irq_map[i].source = source;
irq_map[i].bank = irq_bank + source / 32;
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
ret = irq_map[i].irq;
pr_debug("IPU: mapped source %u to IRQ %u\n",
source, ret);
break;
}
}
out:
mutex_unlock(&map_lock);
if (ret < 0)
pr_err("IPU: couldn't map source %u: %d\n", source, ret);
return ret;
}
int ipu_irq_unmap(unsigned int source)
{
int i, ret = -EINVAL;
might_sleep();
mutex_lock(&map_lock);
for (i = 0; i < CONFIG_MX3_IPU_IRQS; i++) {
if (irq_map[i].source == source) {
unsigned long lock_flags;
pr_debug("IPU: unmapped source %u from IRQ %u\n",
source, irq_map[i].irq);
raw_spin_lock_irqsave(&bank_lock, lock_flags);
irq_map[i].source = -EINVAL;
irq_map[i].bank = NULL;
raw_spin_unlock_irqrestore(&bank_lock, lock_flags);
ret = 0;
break;
}
}
mutex_unlock(&map_lock);
return ret;
}
static void ipu_irq_handler(struct irq_desc *desc)
{
struct ipu *ipu = irq_desc_get_handler_data(desc);
u32 status;
int i, line;
for (i = IPU_IRQ_NR_FN_BANKS; i < IPU_IRQ_NR_BANKS; i++) {
struct ipu_irq_bank *bank = irq_bank + i;
raw_spin_lock(&bank_lock);
status = ipu_read_reg(ipu, bank->status);
status &= ipu_read_reg(ipu, bank->control);
raw_spin_unlock(&bank_lock);
while ((line = ffs(status))) {
struct ipu_irq_map *map;
unsigned int irq = NO_IRQ;
line--;
status &= ~(1UL << line);
raw_spin_lock(&bank_lock);
map = src2map(32 * i + line);
if (map)
irq = map->irq;
raw_spin_unlock(&bank_lock);
if (!map) {
pr_err("IPU: Interrupt on unmapped source %u bank %d\n",
line, i);
continue;
}
generic_handle_irq(irq);
}
}
}
int __init ipu_irq_attach_irq(struct ipu *ipu, struct platform_device *dev)
{
unsigned int irq, i;
int irq_base = irq_alloc_descs(-1, 0, CONFIG_MX3_IPU_IRQS,
numa_node_id());
if (irq_base < 0)
return irq_base;
for (i = 0; i < IPU_IRQ_NR_BANKS; i++)
irq_bank[i].ipu = ipu;
for (i = 0; i < CONFIG_MX3_IPU_IRQS; i++) {
int ret;
irq = irq_base + i;
ret = irq_set_chip(irq, &ipu_irq_chip);
if (ret < 0)
return ret;
ret = irq_set_chip_data(irq, irq_map + i);
if (ret < 0)
return ret;
irq_map[i].ipu = ipu;
irq_map[i].irq = irq;
irq_map[i].source = -EINVAL;
irq_set_handler(irq, handle_level_irq);
irq_clear_status_flags(irq, IRQ_NOREQUEST | IRQ_NOPROBE);
}
irq_set_chained_handler_and_data(ipu->irq_fn, ipu_irq_handler, ipu);
irq_set_chained_handler_and_data(ipu->irq_err, ipu_irq_handler, ipu);
ipu->irq_base = irq_base;
return 0;
}
void ipu_irq_detach_irq(struct ipu *ipu, struct platform_device *dev)
{
unsigned int irq, irq_base;
irq_base = ipu->irq_base;
irq_set_chained_handler_and_data(ipu->irq_fn, NULL, NULL);
irq_set_chained_handler_and_data(ipu->irq_err, NULL, NULL);
for (irq = irq_base; irq < irq_base + CONFIG_MX3_IPU_IRQS; irq++) {
irq_set_status_flags(irq, IRQ_NOREQUEST);
irq_set_chip(irq, NULL);
irq_set_chip_data(irq, NULL);
}
}
