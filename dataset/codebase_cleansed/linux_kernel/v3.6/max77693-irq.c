static struct regmap *max77693_get_regmap(struct max77693_dev *max77693,
enum max77693_irq_source src)
{
switch (src) {
case LED_INT ... CHG_INT:
return max77693->regmap;
case MUIC_INT1 ... MUIC_INT3:
return max77693->regmap_muic;
default:
return ERR_PTR(-EINVAL);
}
}
static void max77693_irq_lock(struct irq_data *data)
{
struct max77693_dev *max77693 = irq_get_chip_data(data->irq);
mutex_lock(&max77693->irqlock);
}
static void max77693_irq_sync_unlock(struct irq_data *data)
{
struct max77693_dev *max77693 = irq_get_chip_data(data->irq);
int i;
for (i = 0; i < MAX77693_IRQ_GROUP_NR; i++) {
u8 mask_reg = max77693_mask_reg[i];
struct regmap *map = max77693_get_regmap(max77693, i);
if (mask_reg == MAX77693_REG_INVALID ||
IS_ERR_OR_NULL(map))
continue;
max77693->irq_masks_cache[i] = max77693->irq_masks_cur[i];
max77693_write_reg(map, max77693_mask_reg[i],
max77693->irq_masks_cur[i]);
}
mutex_unlock(&max77693->irqlock);
}
static const inline struct max77693_irq_data *
irq_to_max77693_irq(struct max77693_dev *max77693, int irq)
{
return &max77693_irqs[irq];
}
static void max77693_irq_mask(struct irq_data *data)
{
struct max77693_dev *max77693 = irq_get_chip_data(data->irq);
const struct max77693_irq_data *irq_data =
irq_to_max77693_irq(max77693, data->irq);
if (irq_data->group >= MAX77693_IRQ_GROUP_NR)
return;
if (irq_data->group >= MUIC_INT1 && irq_data->group <= MUIC_INT3)
max77693->irq_masks_cur[irq_data->group] &= ~irq_data->mask;
else
max77693->irq_masks_cur[irq_data->group] |= irq_data->mask;
}
static void max77693_irq_unmask(struct irq_data *data)
{
struct max77693_dev *max77693 = irq_get_chip_data(data->irq);
const struct max77693_irq_data *irq_data =
irq_to_max77693_irq(max77693, data->irq);
if (irq_data->group >= MAX77693_IRQ_GROUP_NR)
return;
if (irq_data->group >= MUIC_INT1 && irq_data->group <= MUIC_INT3)
max77693->irq_masks_cur[irq_data->group] |= irq_data->mask;
else
max77693->irq_masks_cur[irq_data->group] &= ~irq_data->mask;
}
static irqreturn_t max77693_irq_thread(int irq, void *data)
{
struct max77693_dev *max77693 = data;
u8 irq_reg[MAX77693_IRQ_GROUP_NR] = {};
u8 irq_src;
int ret;
int i, cur_irq;
ret = max77693_read_reg(max77693->regmap, MAX77693_PMIC_REG_INTSRC,
&irq_src);
if (ret < 0) {
dev_err(max77693->dev, "Failed to read interrupt source: %d\n",
ret);
return IRQ_NONE;
}
if (irq_src & MAX77693_IRQSRC_CHG)
ret = max77693_read_reg(max77693->regmap, MAX77693_CHG_REG_CHG_INT,
&irq_reg[CHG_INT]);
if (irq_src & MAX77693_IRQSRC_TOP)
ret = max77693_read_reg(max77693->regmap,
MAX77693_PMIC_REG_TOPSYS_INT, &irq_reg[TOPSYS_INT]);
if (irq_src & MAX77693_IRQSRC_FLASH)
ret = max77693_read_reg(max77693->regmap,
MAX77693_LED_REG_FLASH_INT, &irq_reg[LED_INT]);
if (irq_src & MAX77693_IRQSRC_MUIC)
max77693_bulk_read(max77693->regmap_muic, MAX77693_MUIC_REG_INT1,
MAX77693_NUM_IRQ_MUIC_REGS, &irq_reg[MUIC_INT1]);
for (i = 0; i < MAX77693_IRQ_GROUP_NR; i++) {
if (i >= MUIC_INT1 && i <= MUIC_INT3)
irq_reg[i] &= max77693->irq_masks_cur[i];
else
irq_reg[i] &= ~max77693->irq_masks_cur[i];
}
for (i = 0; i < MAX77693_IRQ_NR; i++) {
if (irq_reg[max77693_irqs[i].group] & max77693_irqs[i].mask) {
cur_irq = irq_find_mapping(max77693->irq_domain, i);
if (cur_irq)
handle_nested_irq(cur_irq);
}
}
return IRQ_HANDLED;
}
int max77693_irq_resume(struct max77693_dev *max77693)
{
if (max77693->irq)
max77693_irq_thread(0, max77693);
return 0;
}
static int max77693_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
struct max77693_dev *max77693 = d->host_data;
irq_set_chip_data(irq, max77693);
irq_set_chip_and_handler(irq, &max77693_irq_chip, handle_edge_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
return 0;
}
int max77693_irq_init(struct max77693_dev *max77693)
{
struct irq_domain *domain;
int i;
int ret = 0;
u8 intsrc_mask;
mutex_init(&max77693->irqlock);
for (i = 0; i < MAX77693_IRQ_GROUP_NR; i++) {
struct regmap *map;
if (i >= MUIC_INT1 && i <= MUIC_INT3) {
max77693->irq_masks_cur[i] = 0x00;
max77693->irq_masks_cache[i] = 0x00;
} else {
max77693->irq_masks_cur[i] = 0xff;
max77693->irq_masks_cache[i] = 0xff;
}
map = max77693_get_regmap(max77693, i);
if (IS_ERR_OR_NULL(map))
continue;
if (max77693_mask_reg[i] == MAX77693_REG_INVALID)
continue;
if (i >= MUIC_INT1 && i <= MUIC_INT3)
max77693_write_reg(map, max77693_mask_reg[i], 0x00);
else
max77693_write_reg(map, max77693_mask_reg[i], 0xff);
}
domain = irq_domain_add_linear(NULL, MAX77693_IRQ_NR,
&max77693_irq_domain_ops, max77693);
if (!domain) {
dev_err(max77693->dev, "could not create irq domain\n");
ret = -ENODEV;
goto err_irq;
}
max77693->irq_domain = domain;
ret = max77693_read_reg(max77693->regmap,
MAX77693_PMIC_REG_INTSRC_MASK, &intsrc_mask);
if (ret < 0) {
dev_err(max77693->dev, "fail to read PMIC register\n");
goto err_irq;
}
intsrc_mask &= ~(MAX77693_IRQSRC_CHG);
intsrc_mask &= ~(MAX77693_IRQSRC_FLASH);
intsrc_mask &= ~(MAX77693_IRQSRC_MUIC);
ret = max77693_write_reg(max77693->regmap,
MAX77693_PMIC_REG_INTSRC_MASK, intsrc_mask);
if (ret < 0) {
dev_err(max77693->dev, "fail to write PMIC register\n");
goto err_irq;
}
ret = request_threaded_irq(max77693->irq, NULL, max77693_irq_thread,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"max77693-irq", max77693);
if (ret)
dev_err(max77693->dev, "Failed to request IRQ %d: %d\n",
max77693->irq, ret);
err_irq:
return ret;
}
void max77693_irq_exit(struct max77693_dev *max77693)
{
if (max77693->irq)
free_irq(max77693->irq, max77693);
}
