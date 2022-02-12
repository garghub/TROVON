static void rc5t583_irq_lock(struct irq_data *irq_data)
{
struct rc5t583 *rc5t583 = irq_data_get_irq_chip_data(irq_data);
mutex_lock(&rc5t583->irq_lock);
}
static void rc5t583_irq_unmask(struct irq_data *irq_data)
{
struct rc5t583 *rc5t583 = irq_data_get_irq_chip_data(irq_data);
unsigned int __irq = irq_data->irq - rc5t583->irq_base;
const struct rc5t583_irq_data *data = &rc5t583_irqs[__irq];
rc5t583->group_irq_en[data->grp_index] |= 1 << data->grp_index;
rc5t583->intc_inten_reg |= 1 << data->master_bit;
rc5t583->irq_en_reg[data->mask_reg_index] |= 1 << data->int_en_bit;
}
static void rc5t583_irq_mask(struct irq_data *irq_data)
{
struct rc5t583 *rc5t583 = irq_data_get_irq_chip_data(irq_data);
unsigned int __irq = irq_data->irq - rc5t583->irq_base;
const struct rc5t583_irq_data *data = &rc5t583_irqs[__irq];
rc5t583->group_irq_en[data->grp_index] &= ~(1 << data->grp_index);
if (!rc5t583->group_irq_en[data->grp_index])
rc5t583->intc_inten_reg &= ~(1 << data->master_bit);
rc5t583->irq_en_reg[data->mask_reg_index] &= ~(1 << data->int_en_bit);
}
static int rc5t583_irq_set_type(struct irq_data *irq_data, unsigned int type)
{
struct rc5t583 *rc5t583 = irq_data_get_irq_chip_data(irq_data);
unsigned int __irq = irq_data->irq - rc5t583->irq_base;
const struct rc5t583_irq_data *data = &rc5t583_irqs[__irq];
int val = 0;
int gpedge_index;
int gpedge_bit_pos;
if ((data->int_type & GPIO_INT) && (type & IRQ_TYPE_EDGE_BOTH)) {
gpedge_index = data->int_en_bit / 4;
gpedge_bit_pos = data->int_en_bit % 4;
if (type & IRQ_TYPE_EDGE_FALLING)
val |= 0x2;
if (type & IRQ_TYPE_EDGE_RISING)
val |= 0x1;
rc5t583->gpedge_reg[gpedge_index] &= ~(3 << gpedge_bit_pos);
rc5t583->gpedge_reg[gpedge_index] |= (val << gpedge_bit_pos);
rc5t583_irq_unmask(irq_data);
return 0;
}
return -EINVAL;
}
static void rc5t583_irq_sync_unlock(struct irq_data *irq_data)
{
struct rc5t583 *rc5t583 = irq_data_get_irq_chip_data(irq_data);
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(rc5t583->gpedge_reg); i++) {
ret = rc5t583_write(rc5t583->dev, gpedge_add[i],
rc5t583->gpedge_reg[i]);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in writing reg 0x%02x error: %d\n",
gpedge_add[i], ret);
}
for (i = 0; i < ARRAY_SIZE(rc5t583->irq_en_reg); i++) {
ret = rc5t583_write(rc5t583->dev, irq_en_add[i],
rc5t583->irq_en_reg[i]);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in writing reg 0x%02x error: %d\n",
irq_en_add[i], ret);
}
ret = rc5t583_write(rc5t583->dev, RC5T583_INTC_INTEN,
rc5t583->intc_inten_reg);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in writing reg 0x%02x error: %d\n",
RC5T583_INTC_INTEN, ret);
mutex_unlock(&rc5t583->irq_lock);
}
static int rc5t583_irq_set_wake(struct irq_data *irq_data, unsigned int on)
{
struct rc5t583 *rc5t583 = irq_data_get_irq_chip_data(irq_data);
return irq_set_irq_wake(rc5t583->chip_irq, on);
}
static irqreturn_t rc5t583_irq(int irq, void *data)
{
struct rc5t583 *rc5t583 = data;
uint8_t int_sts[RC5T583_MAX_INTERRUPT_MASK_REGS];
uint8_t master_int = 0;
int i;
int ret;
unsigned int rtc_int_sts = 0;
for (i = 0; i < RC5T583_MAX_INTERRUPT_MASK_REGS; i++)
int_sts[i] = 0;
ret = rc5t583_read(rc5t583->dev, RC5T583_INTC_INTMON, &master_int);
if (ret < 0) {
dev_err(rc5t583->dev,
"Error in reading reg 0x%02x error: %d\n",
RC5T583_INTC_INTMON, ret);
return IRQ_HANDLED;
}
for (i = 0; i < RC5T583_MAX_INTERRUPT_MASK_REGS; ++i) {
if (!(master_int & main_int_type[i]))
continue;
ret = rc5t583_read(rc5t583->dev, irq_mon_add[i], &int_sts[i]);
if (ret < 0) {
dev_warn(rc5t583->dev,
"Error in reading reg 0x%02x error: %d\n",
irq_mon_add[i], ret);
int_sts[i] = 0;
continue;
}
if (main_int_type[i] & RTC_INT) {
rtc_int_sts = 0;
if (int_sts[i] & 0x1)
rtc_int_sts |= BIT(6);
if (int_sts[i] & 0x2)
rtc_int_sts |= BIT(7);
if (int_sts[i] & 0x4)
rtc_int_sts |= BIT(0);
if (int_sts[i] & 0x8)
rtc_int_sts |= BIT(5);
}
ret = rc5t583_write(rc5t583->dev, irq_clr_add[i],
~int_sts[i]);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in reading reg 0x%02x error: %d\n",
irq_clr_add[i], ret);
if (main_int_type[i] & RTC_INT)
int_sts[i] = rtc_int_sts;
}
int_sts[7] |= int_sts[8];
for (i = 0; i < RC5T583_MAX_IRQS; ++i) {
const struct rc5t583_irq_data *data = &rc5t583_irqs[i];
if ((int_sts[data->mask_reg_index] & (1 << data->int_en_bit)) &&
(rc5t583->group_irq_en[data->master_bit] &
(1 << data->grp_index)))
handle_nested_irq(rc5t583->irq_base + i);
}
return IRQ_HANDLED;
}
int rc5t583_irq_init(struct rc5t583 *rc5t583, int irq, int irq_base)
{
int i, ret;
if (!irq_base) {
dev_warn(rc5t583->dev, "No interrupt support on IRQ base\n");
return -EINVAL;
}
mutex_init(&rc5t583->irq_lock);
for (i = 0; i < RC5T583_MAX_INTERRUPT_EN_REGS; i++) {
ret = rc5t583_write(rc5t583->dev, irq_en_add[i],
rc5t583->irq_en_reg[i]);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in writing reg 0x%02x error: %d\n",
irq_en_add[i], ret);
}
for (i = 0; i < RC5T583_MAX_GPEDGE_REG; i++) {
ret = rc5t583_write(rc5t583->dev, gpedge_add[i],
rc5t583->gpedge_reg[i]);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in writing reg 0x%02x error: %d\n",
gpedge_add[i], ret);
}
ret = rc5t583_write(rc5t583->dev, RC5T583_INTC_INTEN, 0x0);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in writing reg 0x%02x error: %d\n",
RC5T583_INTC_INTEN, ret);
for (i = 0; i < RC5T583_MAX_INTERRUPT_MASK_REGS; i++) {
ret = rc5t583_write(rc5t583->dev, irq_clr_add[i], 0);
if (ret < 0)
dev_warn(rc5t583->dev,
"Error in writing reg 0x%02x error: %d\n",
irq_clr_add[i], ret);
}
rc5t583->irq_base = irq_base;
rc5t583->chip_irq = irq;
for (i = 0; i < RC5T583_MAX_IRQS; i++) {
int __irq = i + rc5t583->irq_base;
irq_set_chip_data(__irq, rc5t583);
irq_set_chip_and_handler(__irq, &rc5t583_irq_chip,
handle_simple_irq);
irq_set_nested_thread(__irq, 1);
irq_clear_status_flags(__irq, IRQ_NOREQUEST);
}
ret = request_threaded_irq(irq, NULL, rc5t583_irq, IRQF_ONESHOT,
"rc5t583", rc5t583);
if (ret < 0)
dev_err(rc5t583->dev,
"Error in registering interrupt error: %d\n", ret);
return ret;
}
int rc5t583_irq_exit(struct rc5t583 *rc5t583)
{
if (rc5t583->chip_irq)
free_irq(rc5t583->chip_irq, rc5t583);
return 0;
}
