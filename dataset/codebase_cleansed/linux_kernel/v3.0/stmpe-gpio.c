static inline struct stmpe_gpio *to_stmpe_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct stmpe_gpio, chip);
}
static int stmpe_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct stmpe_gpio *stmpe_gpio = to_stmpe_gpio(chip);
struct stmpe *stmpe = stmpe_gpio->stmpe;
u8 reg = stmpe->regs[STMPE_IDX_GPMR_LSB] - (offset / 8);
u8 mask = 1 << (offset % 8);
int ret;
ret = stmpe_reg_read(stmpe, reg);
if (ret < 0)
return ret;
return ret & mask;
}
static void stmpe_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct stmpe_gpio *stmpe_gpio = to_stmpe_gpio(chip);
struct stmpe *stmpe = stmpe_gpio->stmpe;
int which = val ? STMPE_IDX_GPSR_LSB : STMPE_IDX_GPCR_LSB;
u8 reg = stmpe->regs[which] - (offset / 8);
u8 mask = 1 << (offset % 8);
stmpe_reg_write(stmpe, reg, mask);
}
static int stmpe_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int val)
{
struct stmpe_gpio *stmpe_gpio = to_stmpe_gpio(chip);
struct stmpe *stmpe = stmpe_gpio->stmpe;
u8 reg = stmpe->regs[STMPE_IDX_GPDR_LSB] - (offset / 8);
u8 mask = 1 << (offset % 8);
stmpe_gpio_set(chip, offset, val);
return stmpe_set_bits(stmpe, reg, mask, mask);
}
static int stmpe_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct stmpe_gpio *stmpe_gpio = to_stmpe_gpio(chip);
struct stmpe *stmpe = stmpe_gpio->stmpe;
u8 reg = stmpe->regs[STMPE_IDX_GPDR_LSB] - (offset / 8);
u8 mask = 1 << (offset % 8);
return stmpe_set_bits(stmpe, reg, mask, 0);
}
static int stmpe_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct stmpe_gpio *stmpe_gpio = to_stmpe_gpio(chip);
return stmpe_gpio->irq_base + offset;
}
static int stmpe_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct stmpe_gpio *stmpe_gpio = to_stmpe_gpio(chip);
struct stmpe *stmpe = stmpe_gpio->stmpe;
if (stmpe_gpio->norequest_mask & (1 << offset))
return -EINVAL;
return stmpe_set_altfunc(stmpe, 1 << offset, STMPE_BLOCK_GPIO);
}
static int stmpe_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
struct stmpe_gpio *stmpe_gpio = irq_data_get_irq_chip_data(d);
int offset = d->irq - stmpe_gpio->irq_base;
int regoffset = offset / 8;
int mask = 1 << (offset % 8);
if (type == IRQ_TYPE_LEVEL_LOW || type == IRQ_TYPE_LEVEL_HIGH)
return -EINVAL;
if (type == IRQ_TYPE_EDGE_RISING)
stmpe_gpio->regs[REG_RE][regoffset] |= mask;
else
stmpe_gpio->regs[REG_RE][regoffset] &= ~mask;
if (type == IRQ_TYPE_EDGE_FALLING)
stmpe_gpio->regs[REG_FE][regoffset] |= mask;
else
stmpe_gpio->regs[REG_FE][regoffset] &= ~mask;
return 0;
}
static void stmpe_gpio_irq_lock(struct irq_data *d)
{
struct stmpe_gpio *stmpe_gpio = irq_data_get_irq_chip_data(d);
mutex_lock(&stmpe_gpio->irq_lock);
}
static void stmpe_gpio_irq_sync_unlock(struct irq_data *d)
{
struct stmpe_gpio *stmpe_gpio = irq_data_get_irq_chip_data(d);
struct stmpe *stmpe = stmpe_gpio->stmpe;
int num_banks = DIV_ROUND_UP(stmpe->num_gpios, 8);
static const u8 regmap[] = {
[REG_RE] = STMPE_IDX_GPRER_LSB,
[REG_FE] = STMPE_IDX_GPFER_LSB,
[REG_IE] = STMPE_IDX_IEGPIOR_LSB,
};
int i, j;
for (i = 0; i < CACHE_NR_REGS; i++) {
for (j = 0; j < num_banks; j++) {
u8 old = stmpe_gpio->oldregs[i][j];
u8 new = stmpe_gpio->regs[i][j];
if (new == old)
continue;
stmpe_gpio->oldregs[i][j] = new;
stmpe_reg_write(stmpe, stmpe->regs[regmap[i]] - j, new);
}
}
mutex_unlock(&stmpe_gpio->irq_lock);
}
static void stmpe_gpio_irq_mask(struct irq_data *d)
{
struct stmpe_gpio *stmpe_gpio = irq_data_get_irq_chip_data(d);
int offset = d->irq - stmpe_gpio->irq_base;
int regoffset = offset / 8;
int mask = 1 << (offset % 8);
stmpe_gpio->regs[REG_IE][regoffset] &= ~mask;
}
static void stmpe_gpio_irq_unmask(struct irq_data *d)
{
struct stmpe_gpio *stmpe_gpio = irq_data_get_irq_chip_data(d);
int offset = d->irq - stmpe_gpio->irq_base;
int regoffset = offset / 8;
int mask = 1 << (offset % 8);
stmpe_gpio->regs[REG_IE][regoffset] |= mask;
}
static irqreturn_t stmpe_gpio_irq(int irq, void *dev)
{
struct stmpe_gpio *stmpe_gpio = dev;
struct stmpe *stmpe = stmpe_gpio->stmpe;
u8 statmsbreg = stmpe->regs[STMPE_IDX_ISGPIOR_MSB];
int num_banks = DIV_ROUND_UP(stmpe->num_gpios, 8);
u8 status[num_banks];
int ret;
int i;
ret = stmpe_block_read(stmpe, statmsbreg, num_banks, status);
if (ret < 0)
return IRQ_NONE;
for (i = 0; i < num_banks; i++) {
int bank = num_banks - i - 1;
unsigned int enabled = stmpe_gpio->regs[REG_IE][bank];
unsigned int stat = status[i];
stat &= enabled;
if (!stat)
continue;
while (stat) {
int bit = __ffs(stat);
int line = bank * 8 + bit;
handle_nested_irq(stmpe_gpio->irq_base + line);
stat &= ~(1 << bit);
}
stmpe_reg_write(stmpe, statmsbreg + i, status[i]);
stmpe_reg_write(stmpe, stmpe->regs[STMPE_IDX_GPEDR_MSB] + i,
status[i]);
}
return IRQ_HANDLED;
}
static int __devinit stmpe_gpio_irq_init(struct stmpe_gpio *stmpe_gpio)
{
int base = stmpe_gpio->irq_base;
int irq;
for (irq = base; irq < base + stmpe_gpio->chip.ngpio; irq++) {
irq_set_chip_data(irq, stmpe_gpio);
irq_set_chip_and_handler(irq, &stmpe_gpio_irq_chip,
handle_simple_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
return 0;
}
static void stmpe_gpio_irq_remove(struct stmpe_gpio *stmpe_gpio)
{
int base = stmpe_gpio->irq_base;
int irq;
for (irq = base; irq < base + stmpe_gpio->chip.ngpio; irq++) {
#ifdef CONFIG_ARM
set_irq_flags(irq, 0);
#endif
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
}
static int __devinit stmpe_gpio_probe(struct platform_device *pdev)
{
struct stmpe *stmpe = dev_get_drvdata(pdev->dev.parent);
struct stmpe_gpio_platform_data *pdata;
struct stmpe_gpio *stmpe_gpio;
int ret;
int irq;
pdata = stmpe->pdata->gpio;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
stmpe_gpio = kzalloc(sizeof(struct stmpe_gpio), GFP_KERNEL);
if (!stmpe_gpio)
return -ENOMEM;
mutex_init(&stmpe_gpio->irq_lock);
stmpe_gpio->dev = &pdev->dev;
stmpe_gpio->stmpe = stmpe;
stmpe_gpio->norequest_mask = pdata ? pdata->norequest_mask : 0;
stmpe_gpio->chip = template_chip;
stmpe_gpio->chip.ngpio = stmpe->num_gpios;
stmpe_gpio->chip.dev = &pdev->dev;
stmpe_gpio->chip.base = pdata ? pdata->gpio_base : -1;
stmpe_gpio->irq_base = stmpe->irq_base + STMPE_INT_GPIO(0);
ret = stmpe_enable(stmpe, STMPE_BLOCK_GPIO);
if (ret)
goto out_free;
ret = stmpe_gpio_irq_init(stmpe_gpio);
if (ret)
goto out_disable;
ret = request_threaded_irq(irq, NULL, stmpe_gpio_irq, IRQF_ONESHOT,
"stmpe-gpio", stmpe_gpio);
if (ret) {
dev_err(&pdev->dev, "unable to get irq: %d\n", ret);
goto out_removeirq;
}
ret = gpiochip_add(&stmpe_gpio->chip);
if (ret) {
dev_err(&pdev->dev, "unable to add gpiochip: %d\n", ret);
goto out_freeirq;
}
if (pdata && pdata->setup)
pdata->setup(stmpe, stmpe_gpio->chip.base);
platform_set_drvdata(pdev, stmpe_gpio);
return 0;
out_freeirq:
free_irq(irq, stmpe_gpio);
out_removeirq:
stmpe_gpio_irq_remove(stmpe_gpio);
out_disable:
stmpe_disable(stmpe, STMPE_BLOCK_GPIO);
out_free:
kfree(stmpe_gpio);
return ret;
}
static int __devexit stmpe_gpio_remove(struct platform_device *pdev)
{
struct stmpe_gpio *stmpe_gpio = platform_get_drvdata(pdev);
struct stmpe *stmpe = stmpe_gpio->stmpe;
struct stmpe_gpio_platform_data *pdata = stmpe->pdata->gpio;
int irq = platform_get_irq(pdev, 0);
int ret;
if (pdata && pdata->remove)
pdata->remove(stmpe, stmpe_gpio->chip.base);
ret = gpiochip_remove(&stmpe_gpio->chip);
if (ret < 0) {
dev_err(stmpe_gpio->dev,
"unable to remove gpiochip: %d\n", ret);
return ret;
}
stmpe_disable(stmpe, STMPE_BLOCK_GPIO);
free_irq(irq, stmpe_gpio);
stmpe_gpio_irq_remove(stmpe_gpio);
platform_set_drvdata(pdev, NULL);
kfree(stmpe_gpio);
return 0;
}
static int __init stmpe_gpio_init(void)
{
return platform_driver_register(&stmpe_gpio_driver);
}
static void __exit stmpe_gpio_exit(void)
{
platform_driver_unregister(&stmpe_gpio_driver);
}
