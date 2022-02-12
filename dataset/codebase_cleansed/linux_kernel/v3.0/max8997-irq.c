static struct i2c_client *get_i2c(struct max8997_dev *max8997,
enum max8997_irq_source src)
{
switch (src) {
case PMIC_INT1 ... PMIC_INT4:
return max8997->i2c;
case FUEL_GAUGE:
return NULL;
case MUIC_INT1 ... MUIC_INT3:
return max8997->muic;
case GPIO_LOW ... GPIO_HI:
return max8997->i2c;
case FLASH_STATUS:
return max8997->i2c;
default:
return ERR_PTR(-EINVAL);
}
return ERR_PTR(-EINVAL);
}
static void max8997_irq_lock(struct irq_data *data)
{
struct max8997_dev *max8997 = irq_get_chip_data(data->irq);
mutex_lock(&max8997->irqlock);
}
static void max8997_irq_sync_unlock(struct irq_data *data)
{
struct max8997_dev *max8997 = irq_get_chip_data(data->irq);
int i;
for (i = 0; i < MAX8997_IRQ_GROUP_NR; i++) {
u8 mask_reg = max8997_mask_reg[i];
struct i2c_client *i2c = get_i2c(max8997, i);
if (mask_reg == MAX8997_REG_INVALID ||
IS_ERR_OR_NULL(i2c))
continue;
max8997->irq_masks_cache[i] = max8997->irq_masks_cur[i];
max8997_write_reg(i2c, max8997_mask_reg[i],
max8997->irq_masks_cur[i]);
}
mutex_unlock(&max8997->irqlock);
}
static const inline struct max8997_irq_data *
irq_to_max8997_irq(struct max8997_dev *max8997, int irq)
{
return &max8997_irqs[irq - max8997->irq_base];
}
static void max8997_irq_mask(struct irq_data *data)
{
struct max8997_dev *max8997 = irq_get_chip_data(data->irq);
const struct max8997_irq_data *irq_data = irq_to_max8997_irq(max8997,
data->irq);
max8997->irq_masks_cur[irq_data->group] |= irq_data->mask;
}
static void max8997_irq_unmask(struct irq_data *data)
{
struct max8997_dev *max8997 = irq_get_chip_data(data->irq);
const struct max8997_irq_data *irq_data = irq_to_max8997_irq(max8997,
data->irq);
max8997->irq_masks_cur[irq_data->group] &= ~irq_data->mask;
}
static irqreturn_t max8997_irq_thread(int irq, void *data)
{
struct max8997_dev *max8997 = data;
u8 irq_reg[MAX8997_IRQ_GROUP_NR] = {};
u8 irq_src;
int ret;
int i;
ret = max8997_read_reg(max8997->i2c, MAX8997_REG_INTSRC, &irq_src);
if (ret < 0) {
dev_err(max8997->dev, "Failed to read interrupt source: %d\n",
ret);
return IRQ_NONE;
}
if (irq_src & MAX8997_IRQSRC_PMIC) {
max8997_bulk_read(max8997->i2c, MAX8997_REG_INT1, 4,
&irq_reg[PMIC_INT1]);
}
if (irq_src & MAX8997_IRQSRC_FUELGAUGE) {
irq_reg[FUEL_GAUGE] = 0;
}
if (irq_src & MAX8997_IRQSRC_MUIC) {
max8997_bulk_read(max8997->muic, MAX8997_MUIC_REG_INT1, 3,
&irq_reg[MUIC_INT1]);
}
if (irq_src & MAX8997_IRQSRC_GPIO) {
u8 gpio_info[MAX8997_NUM_GPIO];
irq_reg[GPIO_LOW] = 0;
irq_reg[GPIO_HI] = 0;
max8997_bulk_read(max8997->i2c, MAX8997_REG_GPIOCNTL1,
MAX8997_NUM_GPIO, gpio_info);
for (i = 0; i < MAX8997_NUM_GPIO; i++) {
bool interrupt = false;
switch (gpio_info[i] & MAX8997_GPIO_INT_MASK) {
case MAX8997_GPIO_INT_BOTH:
if (max8997->gpio_status[i] != gpio_info[i])
interrupt = true;
break;
case MAX8997_GPIO_INT_RISE:
if ((max8997->gpio_status[i] != gpio_info[i]) &&
(gpio_info[i] & MAX8997_GPIO_DATA_MASK))
interrupt = true;
break;
case MAX8997_GPIO_INT_FALL:
if ((max8997->gpio_status[i] != gpio_info[i]) &&
!(gpio_info[i] & MAX8997_GPIO_DATA_MASK))
interrupt = true;
break;
default:
break;
}
if (interrupt) {
if (i < 8)
irq_reg[GPIO_LOW] |= (1 << i);
else
irq_reg[GPIO_HI] |= (1 << (i - 8));
}
}
}
if (irq_src & MAX8997_IRQSRC_FLASH) {
ret = max8997_read_reg(max8997->i2c, MAX8997_REG_FLASHSTATUS,
&irq_reg[FLASH_STATUS]);
}
for (i = 0; i < MAX8997_IRQ_GROUP_NR; i++)
irq_reg[i] &= ~max8997->irq_masks_cur[i];
for (i = 0; i < MAX8997_IRQ_NR; i++) {
if (irq_reg[max8997_irqs[i].group] & max8997_irqs[i].mask)
handle_nested_irq(max8997->irq_base + i);
}
return IRQ_HANDLED;
}
int max8997_irq_resume(struct max8997_dev *max8997)
{
if (max8997->irq && max8997->irq_base)
max8997_irq_thread(max8997->irq_base, max8997);
return 0;
}
int max8997_irq_init(struct max8997_dev *max8997)
{
int i;
int cur_irq;
int ret;
u8 val;
if (!max8997->irq) {
dev_warn(max8997->dev, "No interrupt specified.\n");
max8997->irq_base = 0;
return 0;
}
if (!max8997->irq_base) {
dev_err(max8997->dev, "No interrupt base specified.\n");
return 0;
}
mutex_init(&max8997->irqlock);
for (i = 0; i < MAX8997_IRQ_GROUP_NR; i++) {
struct i2c_client *i2c;
max8997->irq_masks_cur[i] = 0xff;
max8997->irq_masks_cache[i] = 0xff;
i2c = get_i2c(max8997, i);
if (IS_ERR_OR_NULL(i2c))
continue;
if (max8997_mask_reg[i] == MAX8997_REG_INVALID)
continue;
max8997_write_reg(i2c, max8997_mask_reg[i], 0xff);
}
for (i = 0; i < MAX8997_NUM_GPIO; i++) {
max8997->gpio_status[i] = (max8997_read_reg(max8997->i2c,
MAX8997_REG_GPIOCNTL1 + i,
&val)
& MAX8997_GPIO_DATA_MASK) ?
true : false;
}
for (i = 0; i < MAX8997_IRQ_NR; i++) {
cur_irq = i + max8997->irq_base;
irq_set_chip_data(cur_irq, max8997);
irq_set_chip_and_handler(cur_irq, &max8997_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(cur_irq, IRQF_VALID);
#else
irq_set_noprobe(cur_irq);
#endif
}
ret = request_threaded_irq(max8997->irq, NULL, max8997_irq_thread,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"max8997-irq", max8997);
if (ret) {
dev_err(max8997->dev, "Failed to request IRQ %d: %d\n",
max8997->irq, ret);
return ret;
}
if (!max8997->ono)
return 0;
ret = request_threaded_irq(max8997->ono, NULL, max8997_irq_thread,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING |
IRQF_ONESHOT, "max8997-ono", max8997);
if (ret)
dev_err(max8997->dev, "Failed to request ono-IRQ %d: %d\n",
max8997->ono, ret);
return 0;
}
void max8997_irq_exit(struct max8997_dev *max8997)
{
if (max8997->ono)
free_irq(max8997->ono, max8997);
if (max8997->irq)
free_irq(max8997->irq, max8997);
}
