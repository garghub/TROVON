static struct regmap *max77686_get_regmap(struct max77686_dev *max77686,
enum max77686_irq_source src)
{
switch (src) {
case PMIC_INT1 ... PMIC_INT2:
return max77686->regmap;
case RTC_INT:
return max77686->rtc_regmap;
default:
return ERR_PTR(-EINVAL);
}
}
static void max77686_irq_lock(struct irq_data *data)
{
struct max77686_dev *max77686 = irq_get_chip_data(data->irq);
if (debug_mask & MAX77686_DEBUG_IRQ_MASK)
pr_info("%s\n", __func__);
mutex_lock(&max77686->irqlock);
}
static void max77686_irq_sync_unlock(struct irq_data *data)
{
struct max77686_dev *max77686 = irq_get_chip_data(data->irq);
int i;
for (i = 0; i < MAX77686_IRQ_GROUP_NR; i++) {
u8 mask_reg = max77686_mask_reg[i];
struct regmap *map = max77686_get_regmap(max77686, i);
if (debug_mask & MAX77686_DEBUG_IRQ_MASK)
pr_debug("%s: mask_reg[%d]=0x%x, cur=0x%x\n",
__func__, i, mask_reg, max77686->irq_masks_cur[i]);
if (mask_reg == MAX77686_REG_INVALID ||
IS_ERR_OR_NULL(map))
continue;
max77686->irq_masks_cache[i] = max77686->irq_masks_cur[i];
regmap_write(map, max77686_mask_reg[i],
max77686->irq_masks_cur[i]);
}
mutex_unlock(&max77686->irqlock);
}
static const inline struct max77686_irq_data *to_max77686_irq(int irq)
{
struct irq_data *data = irq_get_irq_data(irq);
return &max77686_irqs[data->hwirq];
}
static void max77686_irq_mask(struct irq_data *data)
{
struct max77686_dev *max77686 = irq_get_chip_data(data->irq);
const struct max77686_irq_data *irq_data = to_max77686_irq(data->irq);
max77686->irq_masks_cur[irq_data->group] |= irq_data->mask;
if (debug_mask & MAX77686_DEBUG_IRQ_MASK)
pr_info("%s: group=%d, cur=0x%x\n",
__func__, irq_data->group,
max77686->irq_masks_cur[irq_data->group]);
}
static void max77686_irq_unmask(struct irq_data *data)
{
struct max77686_dev *max77686 = irq_get_chip_data(data->irq);
const struct max77686_irq_data *irq_data = to_max77686_irq(data->irq);
max77686->irq_masks_cur[irq_data->group] &= ~irq_data->mask;
if (debug_mask & MAX77686_DEBUG_IRQ_MASK)
pr_info("%s: group=%d, cur=0x%x\n",
__func__, irq_data->group,
max77686->irq_masks_cur[irq_data->group]);
}
static irqreturn_t max77686_irq_thread(int irq, void *data)
{
struct max77686_dev *max77686 = data;
unsigned int irq_reg[MAX77686_IRQ_GROUP_NR] = {};
unsigned int irq_src;
int ret;
int i, cur_irq;
ret = regmap_read(max77686->regmap, MAX77686_REG_INTSRC, &irq_src);
if (ret < 0) {
dev_err(max77686->dev, "Failed to read interrupt source: %d\n",
ret);
return IRQ_NONE;
}
if (debug_mask & MAX77686_DEBUG_IRQ_INT)
pr_info("%s: irq_src=0x%x\n", __func__, irq_src);
if (irq_src == MAX77686_IRQSRC_PMIC) {
ret = regmap_bulk_read(max77686->regmap,
MAX77686_REG_INT1, irq_reg, 2);
if (ret < 0) {
dev_err(max77686->dev, "Failed to read interrupt source: %d\n",
ret);
return IRQ_NONE;
}
if (debug_mask & MAX77686_DEBUG_IRQ_INT)
pr_info("%s: int1=0x%x, int2=0x%x\n", __func__,
irq_reg[PMIC_INT1], irq_reg[PMIC_INT2]);
}
if (irq_src & MAX77686_IRQSRC_RTC) {
ret = regmap_read(max77686->rtc_regmap,
MAX77686_RTC_INT, &irq_reg[RTC_INT]);
if (ret < 0) {
dev_err(max77686->dev, "Failed to read interrupt source: %d\n",
ret);
return IRQ_NONE;
}
if (debug_mask & MAX77686_DEBUG_IRQ_INT)
pr_info("%s: rtc int=0x%x\n", __func__,
irq_reg[RTC_INT]);
}
for (i = 0; i < MAX77686_IRQ_GROUP_NR; i++)
irq_reg[i] &= ~max77686->irq_masks_cur[i];
for (i = 0; i < MAX77686_IRQ_NR; i++) {
if (irq_reg[max77686_irqs[i].group] & max77686_irqs[i].mask) {
cur_irq = irq_find_mapping(max77686->irq_domain, i);
if (cur_irq)
handle_nested_irq(cur_irq);
}
}
return IRQ_HANDLED;
}
static int max77686_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
struct max77686_dev *max77686 = d->host_data;
irq_set_chip_data(irq, max77686);
irq_set_chip_and_handler(irq, &max77686_irq_chip, handle_edge_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
return 0;
}
int max77686_irq_init(struct max77686_dev *max77686)
{
struct irq_domain *domain;
int i;
int ret;
int val;
struct regmap *map;
mutex_init(&max77686->irqlock);
if (max77686->irq_gpio && !max77686->irq) {
max77686->irq = gpio_to_irq(max77686->irq_gpio);
if (debug_mask & MAX77686_DEBUG_IRQ_INT) {
ret = gpio_request(max77686->irq_gpio, "pmic_irq");
if (ret < 0) {
dev_err(max77686->dev,
"Failed to request gpio %d with ret:"
"%d\n", max77686->irq_gpio, ret);
return IRQ_NONE;
}
gpio_direction_input(max77686->irq_gpio);
val = gpio_get_value(max77686->irq_gpio);
gpio_free(max77686->irq_gpio);
pr_info("%s: gpio_irq=%x\n", __func__, val);
}
}
if (!max77686->irq) {
dev_err(max77686->dev, "irq is not specified\n");
return -ENODEV;
}
for (i = 0; i < MAX77686_IRQ_GROUP_NR; i++) {
max77686->irq_masks_cur[i] = 0xff;
max77686->irq_masks_cache[i] = 0xff;
map = max77686_get_regmap(max77686, i);
if (IS_ERR_OR_NULL(map))
continue;
if (max77686_mask_reg[i] == MAX77686_REG_INVALID)
continue;
regmap_write(map, max77686_mask_reg[i], 0xff);
}
domain = irq_domain_add_linear(NULL, MAX77686_IRQ_NR,
&max77686_irq_domain_ops, max77686);
if (!domain) {
dev_err(max77686->dev, "could not create irq domain\n");
return -ENODEV;
}
max77686->irq_domain = domain;
ret = request_threaded_irq(max77686->irq, NULL, max77686_irq_thread,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"max77686-irq", max77686);
if (ret)
dev_err(max77686->dev, "Failed to request IRQ %d: %d\n",
max77686->irq, ret);
if (debug_mask & MAX77686_DEBUG_IRQ_INFO)
pr_info("%s-\n", __func__);
return 0;
}
void max77686_irq_exit(struct max77686_dev *max77686)
{
if (max77686->irq)
free_irq(max77686->irq, max77686);
}
