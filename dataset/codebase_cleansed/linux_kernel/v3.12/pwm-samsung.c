static inline
struct samsung_pwm_chip *to_samsung_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct samsung_pwm_chip, chip);
}
static inline unsigned int to_tcon_channel(unsigned int channel)
{
return (channel == 0) ? 0 : (channel + 1);
}
static void pwm_samsung_set_divisor(struct samsung_pwm_chip *pwm,
unsigned int channel, u8 divisor)
{
u8 shift = TCFG1_SHIFT(channel);
unsigned long flags;
u32 reg;
u8 bits;
bits = (fls(divisor) - 1) - pwm->variant.div_base;
spin_lock_irqsave(&samsung_pwm_lock, flags);
reg = readl(pwm->base + REG_TCFG1);
reg &= ~(TCFG1_MUX_MASK << shift);
reg |= bits << shift;
writel(reg, pwm->base + REG_TCFG1);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static int pwm_samsung_is_tdiv(struct samsung_pwm_chip *chip, unsigned int chan)
{
struct samsung_pwm_variant *variant = &chip->variant;
u32 reg;
reg = readl(chip->base + REG_TCFG1);
reg >>= TCFG1_SHIFT(chan);
reg &= TCFG1_MUX_MASK;
return (BIT(reg) & variant->tclk_mask) == 0;
}
static unsigned long pwm_samsung_get_tin_rate(struct samsung_pwm_chip *chip,
unsigned int chan)
{
unsigned long rate;
u32 reg;
rate = clk_get_rate(chip->base_clk);
reg = readl(chip->base + REG_TCFG0);
if (chan >= 2)
reg >>= TCFG0_PRESCALER1_SHIFT;
reg &= TCFG0_PRESCALER_MASK;
return rate / (reg + 1);
}
static unsigned long pwm_samsung_calc_tin(struct samsung_pwm_chip *chip,
unsigned int chan, unsigned long freq)
{
struct samsung_pwm_variant *variant = &chip->variant;
unsigned long rate;
struct clk *clk;
u8 div;
if (!pwm_samsung_is_tdiv(chip, chan)) {
clk = (chan < 2) ? chip->tclk0 : chip->tclk1;
if (!IS_ERR(clk)) {
rate = clk_get_rate(clk);
if (rate)
return rate;
}
dev_warn(chip->chip.dev,
"tclk of PWM %d is inoperational, using tdiv\n", chan);
}
rate = pwm_samsung_get_tin_rate(chip, chan);
dev_dbg(chip->chip.dev, "tin parent at %lu\n", rate);
for (div = variant->div_base; div < 4; ++div)
if ((rate >> (variant->bits + div)) < freq)
break;
pwm_samsung_set_divisor(chip, chan, BIT(div));
return rate >> div;
}
static int pwm_samsung_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct samsung_pwm_chip *our_chip = to_samsung_pwm_chip(chip);
struct samsung_pwm_channel *our_chan;
if (!(our_chip->variant.output_mask & BIT(pwm->hwpwm))) {
dev_warn(chip->dev,
"tried to request PWM channel %d without output\n",
pwm->hwpwm);
return -EINVAL;
}
our_chan = devm_kzalloc(chip->dev, sizeof(*our_chan), GFP_KERNEL);
if (!our_chan)
return -ENOMEM;
pwm_set_chip_data(pwm, our_chan);
return 0;
}
static void pwm_samsung_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
pwm_set_chip_data(pwm, NULL);
devm_kfree(chip->dev, pwm_get_chip_data(pwm));
}
static int pwm_samsung_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct samsung_pwm_chip *our_chip = to_samsung_pwm_chip(chip);
unsigned int tcon_chan = to_tcon_channel(pwm->hwpwm);
unsigned long flags;
u32 tcon;
spin_lock_irqsave(&samsung_pwm_lock, flags);
tcon = readl(our_chip->base + REG_TCON);
tcon &= ~TCON_START(tcon_chan);
tcon |= TCON_MANUALUPDATE(tcon_chan);
writel(tcon, our_chip->base + REG_TCON);
tcon &= ~TCON_MANUALUPDATE(tcon_chan);
tcon |= TCON_START(tcon_chan) | TCON_AUTORELOAD(tcon_chan);
writel(tcon, our_chip->base + REG_TCON);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
return 0;
}
static void pwm_samsung_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct samsung_pwm_chip *our_chip = to_samsung_pwm_chip(chip);
unsigned int tcon_chan = to_tcon_channel(pwm->hwpwm);
unsigned long flags;
u32 tcon;
spin_lock_irqsave(&samsung_pwm_lock, flags);
tcon = readl(our_chip->base + REG_TCON);
tcon &= ~TCON_AUTORELOAD(tcon_chan);
writel(tcon, our_chip->base + REG_TCON);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static int pwm_samsung_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct samsung_pwm_chip *our_chip = to_samsung_pwm_chip(chip);
struct samsung_pwm_channel *chan = pwm_get_chip_data(pwm);
u32 tin_ns = chan->tin_ns, tcnt, tcmp;
if (period_ns > NSEC_PER_SEC)
return -ERANGE;
if (period_ns == chan->period_ns && duty_ns == chan->duty_ns)
return 0;
tcnt = readl(our_chip->base + REG_TCNTB(pwm->hwpwm));
++tcnt;
if (chan->period_ns != period_ns) {
unsigned long tin_rate;
u32 period;
period = NSEC_PER_SEC / period_ns;
dev_dbg(our_chip->chip.dev, "duty_ns=%d, period_ns=%d (%u)\n",
duty_ns, period_ns, period);
tin_rate = pwm_samsung_calc_tin(our_chip, pwm->hwpwm, period);
dev_dbg(our_chip->chip.dev, "tin_rate=%lu\n", tin_rate);
tin_ns = NSEC_PER_SEC / tin_rate;
tcnt = period_ns / tin_ns;
}
if (tcnt <= 1)
return -ERANGE;
tcmp = duty_ns / tin_ns;
if (!tcmp)
++tcmp;
tcmp = tcnt - tcmp;
--tcnt;
--tcmp;
dev_dbg(our_chip->chip.dev,
"tin_ns=%u, tcmp=%u/%u\n", tin_ns, tcmp, tcnt);
writel(tcnt, our_chip->base + REG_TCNTB(pwm->hwpwm));
writel(tcmp, our_chip->base + REG_TCMPB(pwm->hwpwm));
if (test_bit(PWMF_ENABLED, &pwm->flags))
pwm_samsung_enable(chip, pwm);
chan->period_ns = period_ns;
chan->tin_ns = tin_ns;
chan->duty_ns = duty_ns;
return 0;
}
static void pwm_samsung_set_invert(struct samsung_pwm_chip *chip,
unsigned int channel, bool invert)
{
unsigned int tcon_chan = to_tcon_channel(channel);
unsigned long flags;
u32 tcon;
spin_lock_irqsave(&samsung_pwm_lock, flags);
tcon = readl(chip->base + REG_TCON);
if (invert) {
chip->inverter_mask |= BIT(channel);
tcon |= TCON_INVERT(tcon_chan);
} else {
chip->inverter_mask &= ~BIT(channel);
tcon &= ~TCON_INVERT(tcon_chan);
}
writel(tcon, chip->base + REG_TCON);
spin_unlock_irqrestore(&samsung_pwm_lock, flags);
}
static int pwm_samsung_set_polarity(struct pwm_chip *chip,
struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct samsung_pwm_chip *our_chip = to_samsung_pwm_chip(chip);
bool invert = (polarity == PWM_POLARITY_NORMAL);
pwm_samsung_set_invert(our_chip, pwm->hwpwm, invert);
return 0;
}
static int pwm_samsung_parse_dt(struct samsung_pwm_chip *chip)
{
struct device_node *np = chip->chip.dev->of_node;
const struct of_device_id *match;
struct property *prop;
const __be32 *cur;
u32 val;
match = of_match_node(samsung_pwm_matches, np);
if (!match)
return -ENODEV;
memcpy(&chip->variant, match->data, sizeof(chip->variant));
of_property_for_each_u32(np, "samsung,pwm-outputs", prop, cur, val) {
if (val >= SAMSUNG_PWM_NUM) {
dev_err(chip->chip.dev,
"%s: invalid channel index in samsung,pwm-outputs property\n",
__func__);
continue;
}
chip->variant.output_mask |= BIT(val);
}
return 0;
}
static int pwm_samsung_parse_dt(struct samsung_pwm_chip *chip)
{
return -ENODEV;
}
static int pwm_samsung_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct samsung_pwm_chip *chip;
struct resource *res;
unsigned int chan;
int ret;
chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->chip.dev = &pdev->dev;
chip->chip.ops = &pwm_samsung_ops;
chip->chip.base = -1;
chip->chip.npwm = SAMSUNG_PWM_NUM;
chip->inverter_mask = BIT(SAMSUNG_PWM_NUM) - 1;
if (IS_ENABLED(CONFIG_OF) && pdev->dev.of_node) {
ret = pwm_samsung_parse_dt(chip);
if (ret)
return ret;
chip->chip.of_xlate = of_pwm_xlate_with_flags;
chip->chip.of_pwm_n_cells = 3;
} else {
if (!pdev->dev.platform_data) {
dev_err(&pdev->dev, "no platform data specified\n");
return -EINVAL;
}
memcpy(&chip->variant, pdev->dev.platform_data,
sizeof(chip->variant));
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
chip->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(chip->base))
return PTR_ERR(chip->base);
chip->base_clk = devm_clk_get(&pdev->dev, "timers");
if (IS_ERR(chip->base_clk)) {
dev_err(dev, "failed to get timer base clk\n");
return PTR_ERR(chip->base_clk);
}
ret = clk_prepare_enable(chip->base_clk);
if (ret < 0) {
dev_err(dev, "failed to enable base clock\n");
return ret;
}
for (chan = 0; chan < SAMSUNG_PWM_NUM; ++chan)
if (chip->variant.output_mask & BIT(chan))
pwm_samsung_set_invert(chip, chan, true);
chip->tclk0 = devm_clk_get(&pdev->dev, "pwm-tclk0");
chip->tclk1 = devm_clk_get(&pdev->dev, "pwm-tclk1");
platform_set_drvdata(pdev, chip);
ret = pwmchip_add(&chip->chip);
if (ret < 0) {
dev_err(dev, "failed to register PWM chip\n");
clk_disable_unprepare(chip->base_clk);
return ret;
}
dev_dbg(dev, "base_clk at %lu, tclk0 at %lu, tclk1 at %lu\n",
clk_get_rate(chip->base_clk),
!IS_ERR(chip->tclk0) ? clk_get_rate(chip->tclk0) : 0,
!IS_ERR(chip->tclk1) ? clk_get_rate(chip->tclk1) : 0);
return 0;
}
static int pwm_samsung_remove(struct platform_device *pdev)
{
struct samsung_pwm_chip *chip = platform_get_drvdata(pdev);
int ret;
ret = pwmchip_remove(&chip->chip);
if (ret < 0)
return ret;
clk_disable_unprepare(chip->base_clk);
return 0;
}
static int pwm_samsung_suspend(struct device *dev)
{
struct samsung_pwm_chip *chip = dev_get_drvdata(dev);
unsigned int i;
for (i = 0; i < SAMSUNG_PWM_NUM; ++i) {
struct pwm_device *pwm = &chip->chip.pwms[i];
struct samsung_pwm_channel *chan = pwm_get_chip_data(pwm);
if (!chan)
continue;
chan->period_ns = 0;
chan->duty_ns = 0;
}
return 0;
}
static int pwm_samsung_resume(struct device *dev)
{
struct samsung_pwm_chip *chip = dev_get_drvdata(dev);
unsigned int chan;
for (chan = 0; chan < SAMSUNG_PWM_NUM; ++chan) {
if (chip->variant.output_mask & BIT(chan))
pwm_samsung_set_invert(chip, chan,
chip->inverter_mask & BIT(chan));
}
return 0;
}
