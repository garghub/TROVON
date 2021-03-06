static void __iomem *mvebu_gpioreg_out(struct mvebu_gpio_chip *mvchip)
{
return mvchip->membase + GPIO_OUT_OFF;
}
static void __iomem *mvebu_gpioreg_blink(struct mvebu_gpio_chip *mvchip)
{
return mvchip->membase + GPIO_BLINK_EN_OFF;
}
static void __iomem *mvebu_gpioreg_blink_counter_select(struct mvebu_gpio_chip
*mvchip)
{
return mvchip->membase + GPIO_BLINK_CNT_SELECT_OFF;
}
static void __iomem *mvebu_gpioreg_io_conf(struct mvebu_gpio_chip *mvchip)
{
return mvchip->membase + GPIO_IO_CONF_OFF;
}
static void __iomem *mvebu_gpioreg_in_pol(struct mvebu_gpio_chip *mvchip)
{
return mvchip->membase + GPIO_IN_POL_OFF;
}
static void __iomem *mvebu_gpioreg_data_in(struct mvebu_gpio_chip *mvchip)
{
return mvchip->membase + GPIO_DATA_IN_OFF;
}
static void __iomem *mvebu_gpioreg_edge_cause(struct mvebu_gpio_chip *mvchip)
{
int cpu;
switch (mvchip->soc_variant) {
case MVEBU_GPIO_SOC_VARIANT_ORION:
case MVEBU_GPIO_SOC_VARIANT_MV78200:
return mvchip->membase + GPIO_EDGE_CAUSE_OFF;
case MVEBU_GPIO_SOC_VARIANT_ARMADAXP:
cpu = smp_processor_id();
return mvchip->percpu_membase +
GPIO_EDGE_CAUSE_ARMADAXP_OFF(cpu);
default:
BUG();
}
}
static void __iomem *mvebu_gpioreg_edge_mask(struct mvebu_gpio_chip *mvchip)
{
int cpu;
switch (mvchip->soc_variant) {
case MVEBU_GPIO_SOC_VARIANT_ORION:
return mvchip->membase + GPIO_EDGE_MASK_OFF;
case MVEBU_GPIO_SOC_VARIANT_MV78200:
cpu = smp_processor_id();
return mvchip->membase + GPIO_EDGE_MASK_MV78200_OFF(cpu);
case MVEBU_GPIO_SOC_VARIANT_ARMADAXP:
cpu = smp_processor_id();
return mvchip->percpu_membase +
GPIO_EDGE_MASK_ARMADAXP_OFF(cpu);
default:
BUG();
}
}
static void __iomem *mvebu_gpioreg_level_mask(struct mvebu_gpio_chip *mvchip)
{
int cpu;
switch (mvchip->soc_variant) {
case MVEBU_GPIO_SOC_VARIANT_ORION:
return mvchip->membase + GPIO_LEVEL_MASK_OFF;
case MVEBU_GPIO_SOC_VARIANT_MV78200:
cpu = smp_processor_id();
return mvchip->membase + GPIO_LEVEL_MASK_MV78200_OFF(cpu);
case MVEBU_GPIO_SOC_VARIANT_ARMADAXP:
cpu = smp_processor_id();
return mvchip->percpu_membase +
GPIO_LEVEL_MASK_ARMADAXP_OFF(cpu);
default:
BUG();
}
}
static void __iomem *mvebu_pwmreg_blink_on_duration(struct mvebu_pwm *mvpwm)
{
return mvpwm->membase + PWM_BLINK_ON_DURATION_OFF;
}
static void __iomem *mvebu_pwmreg_blink_off_duration(struct mvebu_pwm *mvpwm)
{
return mvpwm->membase + PWM_BLINK_OFF_DURATION_OFF;
}
static void mvebu_gpio_set(struct gpio_chip *chip, unsigned int pin, int value)
{
struct mvebu_gpio_chip *mvchip = gpiochip_get_data(chip);
unsigned long flags;
u32 u;
spin_lock_irqsave(&mvchip->lock, flags);
u = readl_relaxed(mvebu_gpioreg_out(mvchip));
if (value)
u |= BIT(pin);
else
u &= ~BIT(pin);
writel_relaxed(u, mvebu_gpioreg_out(mvchip));
spin_unlock_irqrestore(&mvchip->lock, flags);
}
static int mvebu_gpio_get(struct gpio_chip *chip, unsigned int pin)
{
struct mvebu_gpio_chip *mvchip = gpiochip_get_data(chip);
u32 u;
if (readl_relaxed(mvebu_gpioreg_io_conf(mvchip)) & BIT(pin)) {
u = readl_relaxed(mvebu_gpioreg_data_in(mvchip)) ^
readl_relaxed(mvebu_gpioreg_in_pol(mvchip));
} else {
u = readl_relaxed(mvebu_gpioreg_out(mvchip));
}
return (u >> pin) & 1;
}
static void mvebu_gpio_blink(struct gpio_chip *chip, unsigned int pin,
int value)
{
struct mvebu_gpio_chip *mvchip = gpiochip_get_data(chip);
unsigned long flags;
u32 u;
spin_lock_irqsave(&mvchip->lock, flags);
u = readl_relaxed(mvebu_gpioreg_blink(mvchip));
if (value)
u |= BIT(pin);
else
u &= ~BIT(pin);
writel_relaxed(u, mvebu_gpioreg_blink(mvchip));
spin_unlock_irqrestore(&mvchip->lock, flags);
}
static int mvebu_gpio_direction_input(struct gpio_chip *chip, unsigned int pin)
{
struct mvebu_gpio_chip *mvchip = gpiochip_get_data(chip);
unsigned long flags;
int ret;
u32 u;
ret = pinctrl_gpio_direction_input(chip->base + pin);
if (ret)
return ret;
spin_lock_irqsave(&mvchip->lock, flags);
u = readl_relaxed(mvebu_gpioreg_io_conf(mvchip));
u |= BIT(pin);
writel_relaxed(u, mvebu_gpioreg_io_conf(mvchip));
spin_unlock_irqrestore(&mvchip->lock, flags);
return 0;
}
static int mvebu_gpio_direction_output(struct gpio_chip *chip, unsigned int pin,
int value)
{
struct mvebu_gpio_chip *mvchip = gpiochip_get_data(chip);
unsigned long flags;
int ret;
u32 u;
ret = pinctrl_gpio_direction_output(chip->base + pin);
if (ret)
return ret;
mvebu_gpio_blink(chip, pin, 0);
mvebu_gpio_set(chip, pin, value);
spin_lock_irqsave(&mvchip->lock, flags);
u = readl_relaxed(mvebu_gpioreg_io_conf(mvchip));
u &= ~BIT(pin);
writel_relaxed(u, mvebu_gpioreg_io_conf(mvchip));
spin_unlock_irqrestore(&mvchip->lock, flags);
return 0;
}
static int mvebu_gpio_to_irq(struct gpio_chip *chip, unsigned int pin)
{
struct mvebu_gpio_chip *mvchip = gpiochip_get_data(chip);
return irq_create_mapping(mvchip->domain, pin);
}
static void mvebu_gpio_irq_ack(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mvebu_gpio_chip *mvchip = gc->private;
u32 mask = d->mask;
irq_gc_lock(gc);
writel_relaxed(~mask, mvebu_gpioreg_edge_cause(mvchip));
irq_gc_unlock(gc);
}
static void mvebu_gpio_edge_irq_mask(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mvebu_gpio_chip *mvchip = gc->private;
struct irq_chip_type *ct = irq_data_get_chip_type(d);
u32 mask = d->mask;
irq_gc_lock(gc);
ct->mask_cache_priv &= ~mask;
writel_relaxed(ct->mask_cache_priv, mvebu_gpioreg_edge_mask(mvchip));
irq_gc_unlock(gc);
}
static void mvebu_gpio_edge_irq_unmask(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mvebu_gpio_chip *mvchip = gc->private;
struct irq_chip_type *ct = irq_data_get_chip_type(d);
u32 mask = d->mask;
irq_gc_lock(gc);
ct->mask_cache_priv |= mask;
writel_relaxed(ct->mask_cache_priv, mvebu_gpioreg_edge_mask(mvchip));
irq_gc_unlock(gc);
}
static void mvebu_gpio_level_irq_mask(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mvebu_gpio_chip *mvchip = gc->private;
struct irq_chip_type *ct = irq_data_get_chip_type(d);
u32 mask = d->mask;
irq_gc_lock(gc);
ct->mask_cache_priv &= ~mask;
writel_relaxed(ct->mask_cache_priv, mvebu_gpioreg_level_mask(mvchip));
irq_gc_unlock(gc);
}
static void mvebu_gpio_level_irq_unmask(struct irq_data *d)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct mvebu_gpio_chip *mvchip = gc->private;
struct irq_chip_type *ct = irq_data_get_chip_type(d);
u32 mask = d->mask;
irq_gc_lock(gc);
ct->mask_cache_priv |= mask;
writel_relaxed(ct->mask_cache_priv, mvebu_gpioreg_level_mask(mvchip));
irq_gc_unlock(gc);
}
static int mvebu_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct irq_chip_type *ct = irq_data_get_chip_type(d);
struct mvebu_gpio_chip *mvchip = gc->private;
int pin;
u32 u;
pin = d->hwirq;
u = readl_relaxed(mvebu_gpioreg_io_conf(mvchip)) & BIT(pin);
if (!u)
return -EINVAL;
type &= IRQ_TYPE_SENSE_MASK;
if (type == IRQ_TYPE_NONE)
return -EINVAL;
if (!(ct->type & type))
if (irq_setup_alt_chip(d, type))
return -EINVAL;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
case IRQ_TYPE_LEVEL_HIGH:
u = readl_relaxed(mvebu_gpioreg_in_pol(mvchip));
u &= ~BIT(pin);
writel_relaxed(u, mvebu_gpioreg_in_pol(mvchip));
break;
case IRQ_TYPE_EDGE_FALLING:
case IRQ_TYPE_LEVEL_LOW:
u = readl_relaxed(mvebu_gpioreg_in_pol(mvchip));
u |= BIT(pin);
writel_relaxed(u, mvebu_gpioreg_in_pol(mvchip));
break;
case IRQ_TYPE_EDGE_BOTH: {
u32 v;
v = readl_relaxed(mvebu_gpioreg_in_pol(mvchip)) ^
readl_relaxed(mvebu_gpioreg_data_in(mvchip));
u = readl_relaxed(mvebu_gpioreg_in_pol(mvchip));
if (v & BIT(pin))
u |= BIT(pin);
else
u &= ~BIT(pin);
writel_relaxed(u, mvebu_gpioreg_in_pol(mvchip));
break;
}
}
return 0;
}
static void mvebu_gpio_irq_handler(struct irq_desc *desc)
{
struct mvebu_gpio_chip *mvchip = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
u32 cause, type;
int i;
if (mvchip == NULL)
return;
chained_irq_enter(chip, desc);
cause = readl_relaxed(mvebu_gpioreg_data_in(mvchip)) &
readl_relaxed(mvebu_gpioreg_level_mask(mvchip));
cause |= readl_relaxed(mvebu_gpioreg_edge_cause(mvchip)) &
readl_relaxed(mvebu_gpioreg_edge_mask(mvchip));
for (i = 0; i < mvchip->chip.ngpio; i++) {
int irq;
irq = irq_find_mapping(mvchip->domain, i);
if (!(cause & BIT(i)))
continue;
type = irq_get_trigger_type(irq);
if ((type & IRQ_TYPE_SENSE_MASK) == IRQ_TYPE_EDGE_BOTH) {
u32 polarity;
polarity = readl_relaxed(mvebu_gpioreg_in_pol(mvchip));
polarity ^= BIT(i);
writel_relaxed(polarity, mvebu_gpioreg_in_pol(mvchip));
}
generic_handle_irq(irq);
}
chained_irq_exit(chip, desc);
}
static struct mvebu_pwm *to_mvebu_pwm(struct pwm_chip *chip)
{
return container_of(chip, struct mvebu_pwm, chip);
}
static int mvebu_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mvebu_pwm *mvpwm = to_mvebu_pwm(chip);
struct mvebu_gpio_chip *mvchip = mvpwm->mvchip;
struct gpio_desc *desc;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&mvpwm->lock, flags);
if (mvpwm->gpiod) {
ret = -EBUSY;
} else {
desc = gpio_to_desc(mvchip->chip.base + pwm->hwpwm);
if (!desc) {
ret = -ENODEV;
goto out;
}
ret = gpiod_request(desc, "mvebu-pwm");
if (ret)
goto out;
ret = gpiod_direction_output(desc, 0);
if (ret) {
gpiod_free(desc);
goto out;
}
mvpwm->gpiod = desc;
}
out:
spin_unlock_irqrestore(&mvpwm->lock, flags);
return ret;
}
static void mvebu_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mvebu_pwm *mvpwm = to_mvebu_pwm(chip);
unsigned long flags;
spin_lock_irqsave(&mvpwm->lock, flags);
gpiod_free(mvpwm->gpiod);
mvpwm->gpiod = NULL;
spin_unlock_irqrestore(&mvpwm->lock, flags);
}
static void mvebu_pwm_get_state(struct pwm_chip *chip,
struct pwm_device *pwm,
struct pwm_state *state) {
struct mvebu_pwm *mvpwm = to_mvebu_pwm(chip);
struct mvebu_gpio_chip *mvchip = mvpwm->mvchip;
unsigned long long val;
unsigned long flags;
u32 u;
spin_lock_irqsave(&mvpwm->lock, flags);
val = (unsigned long long)
readl_relaxed(mvebu_pwmreg_blink_on_duration(mvpwm));
val *= NSEC_PER_SEC;
do_div(val, mvpwm->clk_rate);
if (val > UINT_MAX)
state->duty_cycle = UINT_MAX;
else if (val)
state->duty_cycle = val;
else
state->duty_cycle = 1;
val = (unsigned long long)
readl_relaxed(mvebu_pwmreg_blink_off_duration(mvpwm));
val *= NSEC_PER_SEC;
do_div(val, mvpwm->clk_rate);
if (val < state->duty_cycle) {
state->period = 1;
} else {
val -= state->duty_cycle;
if (val > UINT_MAX)
state->period = UINT_MAX;
else if (val)
state->period = val;
else
state->period = 1;
}
u = readl_relaxed(mvebu_gpioreg_blink(mvchip));
if (u)
state->enabled = true;
else
state->enabled = false;
spin_unlock_irqrestore(&mvpwm->lock, flags);
}
static int mvebu_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct mvebu_pwm *mvpwm = to_mvebu_pwm(chip);
struct mvebu_gpio_chip *mvchip = mvpwm->mvchip;
unsigned long long val;
unsigned long flags;
unsigned int on, off;
val = (unsigned long long) mvpwm->clk_rate * state->duty_cycle;
do_div(val, NSEC_PER_SEC);
if (val > UINT_MAX)
return -EINVAL;
if (val)
on = val;
else
on = 1;
val = (unsigned long long) mvpwm->clk_rate *
(state->period - state->duty_cycle);
do_div(val, NSEC_PER_SEC);
if (val > UINT_MAX)
return -EINVAL;
if (val)
off = val;
else
off = 1;
spin_lock_irqsave(&mvpwm->lock, flags);
writel_relaxed(on, mvebu_pwmreg_blink_on_duration(mvpwm));
writel_relaxed(off, mvebu_pwmreg_blink_off_duration(mvpwm));
if (state->enabled)
mvebu_gpio_blink(&mvchip->chip, pwm->hwpwm, 1);
else
mvebu_gpio_blink(&mvchip->chip, pwm->hwpwm, 0);
spin_unlock_irqrestore(&mvpwm->lock, flags);
return 0;
}
static void __maybe_unused mvebu_pwm_suspend(struct mvebu_gpio_chip *mvchip)
{
struct mvebu_pwm *mvpwm = mvchip->mvpwm;
mvpwm->blink_select =
readl_relaxed(mvebu_gpioreg_blink_counter_select(mvchip));
mvpwm->blink_on_duration =
readl_relaxed(mvebu_pwmreg_blink_on_duration(mvpwm));
mvpwm->blink_off_duration =
readl_relaxed(mvebu_pwmreg_blink_off_duration(mvpwm));
}
static void __maybe_unused mvebu_pwm_resume(struct mvebu_gpio_chip *mvchip)
{
struct mvebu_pwm *mvpwm = mvchip->mvpwm;
writel_relaxed(mvpwm->blink_select,
mvebu_gpioreg_blink_counter_select(mvchip));
writel_relaxed(mvpwm->blink_on_duration,
mvebu_pwmreg_blink_on_duration(mvpwm));
writel_relaxed(mvpwm->blink_off_duration,
mvebu_pwmreg_blink_off_duration(mvpwm));
}
static int mvebu_pwm_probe(struct platform_device *pdev,
struct mvebu_gpio_chip *mvchip,
int id)
{
struct device *dev = &pdev->dev;
struct mvebu_pwm *mvpwm;
struct resource *res;
u32 set;
if (!of_device_is_compatible(mvchip->chip.of_node,
"marvell,armada-370-gpio"))
return 0;
if (IS_ERR(mvchip->clk))
return PTR_ERR(mvchip->clk);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pwm");
if (!res)
return 0;
if (id == 0)
set = 0;
else if (id == 1)
set = U32_MAX;
else
return -EINVAL;
writel_relaxed(set, mvebu_gpioreg_blink_counter_select(mvchip));
mvpwm = devm_kzalloc(dev, sizeof(struct mvebu_pwm), GFP_KERNEL);
if (!mvpwm)
return -ENOMEM;
mvchip->mvpwm = mvpwm;
mvpwm->mvchip = mvchip;
mvpwm->membase = devm_ioremap_resource(dev, res);
if (IS_ERR(mvpwm->membase))
return PTR_ERR(mvpwm->membase);
mvpwm->clk_rate = clk_get_rate(mvchip->clk);
if (!mvpwm->clk_rate) {
dev_err(dev, "failed to get clock rate\n");
return -EINVAL;
}
mvpwm->chip.dev = dev;
mvpwm->chip.ops = &mvebu_pwm_ops;
mvpwm->chip.npwm = mvchip->chip.ngpio;
mvpwm->chip.base = -1;
spin_lock_init(&mvpwm->lock);
return pwmchip_add(&mvpwm->chip);
}
static void mvebu_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
struct mvebu_gpio_chip *mvchip = gpiochip_get_data(chip);
u32 out, io_conf, blink, in_pol, data_in, cause, edg_msk, lvl_msk;
int i;
out = readl_relaxed(mvebu_gpioreg_out(mvchip));
io_conf = readl_relaxed(mvebu_gpioreg_io_conf(mvchip));
blink = readl_relaxed(mvebu_gpioreg_blink(mvchip));
in_pol = readl_relaxed(mvebu_gpioreg_in_pol(mvchip));
data_in = readl_relaxed(mvebu_gpioreg_data_in(mvchip));
cause = readl_relaxed(mvebu_gpioreg_edge_cause(mvchip));
edg_msk = readl_relaxed(mvebu_gpioreg_edge_mask(mvchip));
lvl_msk = readl_relaxed(mvebu_gpioreg_level_mask(mvchip));
for (i = 0; i < chip->ngpio; i++) {
const char *label;
u32 msk;
bool is_out;
label = gpiochip_is_requested(chip, i);
if (!label)
continue;
msk = BIT(i);
is_out = !(io_conf & msk);
seq_printf(s, " gpio-%-3d (%-20.20s)", chip->base + i, label);
if (is_out) {
seq_printf(s, " out %s %s\n",
out & msk ? "hi" : "lo",
blink & msk ? "(blink )" : "");
continue;
}
seq_printf(s, " in %s (act %s) - IRQ",
(data_in ^ in_pol) & msk ? "hi" : "lo",
in_pol & msk ? "lo" : "hi");
if (!((edg_msk | lvl_msk) & msk)) {
seq_puts(s, " disabled\n");
continue;
}
if (edg_msk & msk)
seq_puts(s, " edge ");
if (lvl_msk & msk)
seq_puts(s, " level");
seq_printf(s, " (%s)\n", cause & msk ? "pending" : "clear ");
}
}
static int mvebu_gpio_suspend(struct platform_device *pdev, pm_message_t state)
{
struct mvebu_gpio_chip *mvchip = platform_get_drvdata(pdev);
int i;
mvchip->out_reg = readl(mvebu_gpioreg_out(mvchip));
mvchip->io_conf_reg = readl(mvebu_gpioreg_io_conf(mvchip));
mvchip->blink_en_reg = readl(mvebu_gpioreg_blink(mvchip));
mvchip->in_pol_reg = readl(mvebu_gpioreg_in_pol(mvchip));
switch (mvchip->soc_variant) {
case MVEBU_GPIO_SOC_VARIANT_ORION:
mvchip->edge_mask_regs[0] =
readl(mvchip->membase + GPIO_EDGE_MASK_OFF);
mvchip->level_mask_regs[0] =
readl(mvchip->membase + GPIO_LEVEL_MASK_OFF);
break;
case MVEBU_GPIO_SOC_VARIANT_MV78200:
for (i = 0; i < 2; i++) {
mvchip->edge_mask_regs[i] =
readl(mvchip->membase +
GPIO_EDGE_MASK_MV78200_OFF(i));
mvchip->level_mask_regs[i] =
readl(mvchip->membase +
GPIO_LEVEL_MASK_MV78200_OFF(i));
}
break;
case MVEBU_GPIO_SOC_VARIANT_ARMADAXP:
for (i = 0; i < 4; i++) {
mvchip->edge_mask_regs[i] =
readl(mvchip->membase +
GPIO_EDGE_MASK_ARMADAXP_OFF(i));
mvchip->level_mask_regs[i] =
readl(mvchip->membase +
GPIO_LEVEL_MASK_ARMADAXP_OFF(i));
}
break;
default:
BUG();
}
if (IS_ENABLED(CONFIG_PWM))
mvebu_pwm_suspend(mvchip);
return 0;
}
static int mvebu_gpio_resume(struct platform_device *pdev)
{
struct mvebu_gpio_chip *mvchip = platform_get_drvdata(pdev);
int i;
writel(mvchip->out_reg, mvebu_gpioreg_out(mvchip));
writel(mvchip->io_conf_reg, mvebu_gpioreg_io_conf(mvchip));
writel(mvchip->blink_en_reg, mvebu_gpioreg_blink(mvchip));
writel(mvchip->in_pol_reg, mvebu_gpioreg_in_pol(mvchip));
switch (mvchip->soc_variant) {
case MVEBU_GPIO_SOC_VARIANT_ORION:
writel(mvchip->edge_mask_regs[0],
mvchip->membase + GPIO_EDGE_MASK_OFF);
writel(mvchip->level_mask_regs[0],
mvchip->membase + GPIO_LEVEL_MASK_OFF);
break;
case MVEBU_GPIO_SOC_VARIANT_MV78200:
for (i = 0; i < 2; i++) {
writel(mvchip->edge_mask_regs[i],
mvchip->membase + GPIO_EDGE_MASK_MV78200_OFF(i));
writel(mvchip->level_mask_regs[i],
mvchip->membase +
GPIO_LEVEL_MASK_MV78200_OFF(i));
}
break;
case MVEBU_GPIO_SOC_VARIANT_ARMADAXP:
for (i = 0; i < 4; i++) {
writel(mvchip->edge_mask_regs[i],
mvchip->membase +
GPIO_EDGE_MASK_ARMADAXP_OFF(i));
writel(mvchip->level_mask_regs[i],
mvchip->membase +
GPIO_LEVEL_MASK_ARMADAXP_OFF(i));
}
break;
default:
BUG();
}
if (IS_ENABLED(CONFIG_PWM))
mvebu_pwm_resume(mvchip);
return 0;
}
static int mvebu_gpio_probe(struct platform_device *pdev)
{
struct mvebu_gpio_chip *mvchip;
const struct of_device_id *match;
struct device_node *np = pdev->dev.of_node;
struct resource *res;
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
unsigned int ngpios;
bool have_irqs;
int soc_variant;
int i, cpu, id;
int err;
match = of_match_device(mvebu_gpio_of_match, &pdev->dev);
if (match)
soc_variant = (unsigned long) match->data;
else
soc_variant = MVEBU_GPIO_SOC_VARIANT_ORION;
have_irqs = of_irq_count(np) != 0;
mvchip = devm_kzalloc(&pdev->dev, sizeof(struct mvebu_gpio_chip),
GFP_KERNEL);
if (!mvchip)
return -ENOMEM;
platform_set_drvdata(pdev, mvchip);
if (of_property_read_u32(pdev->dev.of_node, "ngpios", &ngpios)) {
dev_err(&pdev->dev, "Missing ngpios OF property\n");
return -ENODEV;
}
id = of_alias_get_id(pdev->dev.of_node, "gpio");
if (id < 0) {
dev_err(&pdev->dev, "Couldn't get OF id\n");
return id;
}
mvchip->clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(mvchip->clk))
clk_prepare_enable(mvchip->clk);
mvchip->soc_variant = soc_variant;
mvchip->chip.label = dev_name(&pdev->dev);
mvchip->chip.parent = &pdev->dev;
mvchip->chip.request = gpiochip_generic_request;
mvchip->chip.free = gpiochip_generic_free;
mvchip->chip.direction_input = mvebu_gpio_direction_input;
mvchip->chip.get = mvebu_gpio_get;
mvchip->chip.direction_output = mvebu_gpio_direction_output;
mvchip->chip.set = mvebu_gpio_set;
if (have_irqs)
mvchip->chip.to_irq = mvebu_gpio_to_irq;
mvchip->chip.base = id * MVEBU_MAX_GPIO_PER_BANK;
mvchip->chip.ngpio = ngpios;
mvchip->chip.can_sleep = false;
mvchip->chip.of_node = np;
mvchip->chip.dbg_show = mvebu_gpio_dbg_show;
spin_lock_init(&mvchip->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mvchip->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mvchip->membase))
return PTR_ERR(mvchip->membase);
if (soc_variant == MVEBU_GPIO_SOC_VARIANT_ARMADAXP) {
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
mvchip->percpu_membase = devm_ioremap_resource(&pdev->dev,
res);
if (IS_ERR(mvchip->percpu_membase))
return PTR_ERR(mvchip->percpu_membase);
}
switch (soc_variant) {
case MVEBU_GPIO_SOC_VARIANT_ORION:
writel_relaxed(0, mvchip->membase + GPIO_EDGE_CAUSE_OFF);
writel_relaxed(0, mvchip->membase + GPIO_EDGE_MASK_OFF);
writel_relaxed(0, mvchip->membase + GPIO_LEVEL_MASK_OFF);
break;
case MVEBU_GPIO_SOC_VARIANT_MV78200:
writel_relaxed(0, mvchip->membase + GPIO_EDGE_CAUSE_OFF);
for (cpu = 0; cpu < 2; cpu++) {
writel_relaxed(0, mvchip->membase +
GPIO_EDGE_MASK_MV78200_OFF(cpu));
writel_relaxed(0, mvchip->membase +
GPIO_LEVEL_MASK_MV78200_OFF(cpu));
}
break;
case MVEBU_GPIO_SOC_VARIANT_ARMADAXP:
writel_relaxed(0, mvchip->membase + GPIO_EDGE_CAUSE_OFF);
writel_relaxed(0, mvchip->membase + GPIO_EDGE_MASK_OFF);
writel_relaxed(0, mvchip->membase + GPIO_LEVEL_MASK_OFF);
for (cpu = 0; cpu < 4; cpu++) {
writel_relaxed(0, mvchip->percpu_membase +
GPIO_EDGE_CAUSE_ARMADAXP_OFF(cpu));
writel_relaxed(0, mvchip->percpu_membase +
GPIO_EDGE_MASK_ARMADAXP_OFF(cpu));
writel_relaxed(0, mvchip->percpu_membase +
GPIO_LEVEL_MASK_ARMADAXP_OFF(cpu));
}
break;
default:
BUG();
}
devm_gpiochip_add_data(&pdev->dev, &mvchip->chip, mvchip);
if (!have_irqs)
return 0;
mvchip->domain =
irq_domain_add_linear(np, ngpios, &irq_generic_chip_ops, NULL);
if (!mvchip->domain) {
dev_err(&pdev->dev, "couldn't allocate irq domain %s (DT).\n",
mvchip->chip.label);
return -ENODEV;
}
err = irq_alloc_domain_generic_chips(
mvchip->domain, ngpios, 2, np->name, handle_level_irq,
IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_LEVEL, 0, 0);
if (err) {
dev_err(&pdev->dev, "couldn't allocate irq chips %s (DT).\n",
mvchip->chip.label);
goto err_domain;
}
gc = irq_get_domain_generic_chip(mvchip->domain, 0);
gc->private = mvchip;
ct = &gc->chip_types[0];
ct->type = IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW;
ct->chip.irq_mask = mvebu_gpio_level_irq_mask;
ct->chip.irq_unmask = mvebu_gpio_level_irq_unmask;
ct->chip.irq_set_type = mvebu_gpio_irq_set_type;
ct->chip.name = mvchip->chip.label;
ct = &gc->chip_types[1];
ct->type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
ct->chip.irq_ack = mvebu_gpio_irq_ack;
ct->chip.irq_mask = mvebu_gpio_edge_irq_mask;
ct->chip.irq_unmask = mvebu_gpio_edge_irq_unmask;
ct->chip.irq_set_type = mvebu_gpio_irq_set_type;
ct->handler = handle_edge_irq;
ct->chip.name = mvchip->chip.label;
for (i = 0; i < 4; i++) {
int irq = platform_get_irq(pdev, i);
if (irq < 0)
continue;
irq_set_chained_handler_and_data(irq, mvebu_gpio_irq_handler,
mvchip);
}
if (IS_ENABLED(CONFIG_PWM))
return mvebu_pwm_probe(pdev, mvchip, id);
return 0;
err_domain:
irq_domain_remove(mvchip->domain);
return err;
}
