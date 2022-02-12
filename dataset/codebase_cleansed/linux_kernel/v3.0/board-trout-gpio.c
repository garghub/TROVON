static int msm_gpiolib_get(struct gpio_chip *chip, unsigned offset)
{
struct msm_gpio_chip *msm_gpio = to_msm_gpio_chip(chip);
unsigned mask = 1 << offset;
return !!(readb(msm_gpio->reg) & mask);
}
static void msm_gpiolib_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct msm_gpio_chip *msm_gpio = to_msm_gpio_chip(chip);
unsigned mask = 1 << offset;
if (val)
msm_gpio->shadow |= mask;
else
msm_gpio->shadow &= ~mask;
writeb(msm_gpio->shadow, msm_gpio->reg);
}
static int msm_gpiolib_direction_input(struct gpio_chip *chip,
unsigned offset)
{
msm_gpiolib_set(chip, offset, 0);
return 0;
}
static int msm_gpiolib_direction_output(struct gpio_chip *chip,
unsigned offset, int val)
{
msm_gpiolib_set(chip, offset, val);
return 0;
}
static int trout_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
return TROUT_GPIO_TO_INT(offset + chip->base);
}
static void trout_gpio_irq_ack(struct irq_data *d)
{
int bank = TROUT_INT_TO_BANK(d->irq);
uint8_t mask = TROUT_INT_TO_MASK(d->irq);
int reg = TROUT_BANK_TO_STAT_REG(bank);
writeb(mask, TROUT_CPLD_BASE + reg);
}
static void trout_gpio_irq_mask(struct irq_data *d)
{
unsigned long flags;
uint8_t reg_val;
int bank = TROUT_INT_TO_BANK(d->irq);
uint8_t mask = TROUT_INT_TO_MASK(d->irq);
int reg = TROUT_BANK_TO_MASK_REG(bank);
local_irq_save(flags);
reg_val = trout_int_mask[bank] |= mask;
writeb(reg_val, TROUT_CPLD_BASE + reg);
local_irq_restore(flags);
}
static void trout_gpio_irq_unmask(struct irq_data *d)
{
unsigned long flags;
uint8_t reg_val;
int bank = TROUT_INT_TO_BANK(d->irq);
uint8_t mask = TROUT_INT_TO_MASK(d->irq);
int reg = TROUT_BANK_TO_MASK_REG(bank);
local_irq_save(flags);
reg_val = trout_int_mask[bank] &= ~mask;
writeb(reg_val, TROUT_CPLD_BASE + reg);
local_irq_restore(flags);
}
int trout_gpio_irq_set_wake(struct irq_data *d, unsigned int on)
{
unsigned long flags;
int bank = TROUT_INT_TO_BANK(d->irq);
uint8_t mask = TROUT_INT_TO_MASK(d->irq);
local_irq_save(flags);
if(on)
trout_sleep_int_mask[bank] &= ~mask;
else
trout_sleep_int_mask[bank] |= mask;
local_irq_restore(flags);
return 0;
}
static void trout_gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
int j, m;
unsigned v;
int bank;
int stat_reg;
int int_base = TROUT_INT_START;
uint8_t int_mask;
for (bank = 0; bank < 2; bank++) {
stat_reg = TROUT_BANK_TO_STAT_REG(bank);
v = readb(TROUT_CPLD_BASE + stat_reg);
int_mask = trout_int_mask[bank];
if (v & int_mask) {
writeb(v & int_mask, TROUT_CPLD_BASE + stat_reg);
printk(KERN_ERR "trout_gpio_irq_handler: got masked "
"interrupt: %d:%02x\n", bank, v & int_mask);
}
v &= ~int_mask;
while (v) {
m = v & -v;
j = fls(m) - 1;
v &= ~m;
generic_handle_irq(int_base + j);
}
int_base += TROUT_INT_BANK0_COUNT;
}
desc->irq_data.chip->irq_ack(&desc->irq_data);
}
int __init trout_init_gpio(void)
{
int i;
for(i = TROUT_INT_START; i <= TROUT_INT_END; i++) {
irq_set_chip_and_handler(i, &trout_gpio_irq_chip,
handle_edge_irq);
set_irq_flags(i, IRQF_VALID);
}
for (i = 0; i < ARRAY_SIZE(msm_gpio_banks); i++)
gpiochip_add(&msm_gpio_banks[i].chip);
irq_set_irq_type(MSM_GPIO_TO_INT(17), IRQF_TRIGGER_HIGH);
irq_set_chained_handler(MSM_GPIO_TO_INT(17), trout_gpio_irq_handler);
irq_set_irq_wake(MSM_GPIO_TO_INT(17), 1);
return 0;
}
