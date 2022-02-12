static inline struct kona_pwmc *to_kona_pwmc(struct pwm_chip *_chip)
{
return container_of(_chip, struct kona_pwmc, chip);
}
static void kona_pwmc_prepare_for_settings(struct kona_pwmc *kp,
unsigned int chan)
{
unsigned int value = readl(kp->base + PWM_CONTROL_OFFSET);
value |= 1 << PWM_CONTROL_SMOOTH_SHIFT(chan);
value &= ~(1 << PWM_CONTROL_TRIGGER_SHIFT(chan));
writel(value, kp->base + PWM_CONTROL_OFFSET);
ndelay(400);
}
static void kona_pwmc_apply_settings(struct kona_pwmc *kp, unsigned int chan)
{
unsigned int value = readl(kp->base + PWM_CONTROL_OFFSET);
value &= ~(1 << PWM_CONTROL_SMOOTH_SHIFT(chan));
value |= 1 << PWM_CONTROL_TRIGGER_SHIFT(chan);
writel(value, kp->base + PWM_CONTROL_OFFSET);
ndelay(400);
}
static int kona_pwmc_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct kona_pwmc *kp = to_kona_pwmc(chip);
u64 val, div, rate;
unsigned long prescale = PRESCALE_MIN, pc, dc;
unsigned int value, chan = pwm->hwpwm;
rate = clk_get_rate(kp->clk);
while (1) {
div = 1000000000;
div *= 1 + prescale;
val = rate * period_ns;
pc = div64_u64(val, div);
val = rate * duty_ns;
dc = div64_u64(val, div);
if (pc < PERIOD_COUNT_MIN || dc < DUTY_CYCLE_HIGH_MIN)
return -EINVAL;
if (pc <= PERIOD_COUNT_MAX && dc <= DUTY_CYCLE_HIGH_MAX)
break;
if (++prescale > PRESCALE_MAX)
return -EINVAL;
}
if (pwm_is_enabled(pwm)) {
kona_pwmc_prepare_for_settings(kp, chan);
value = readl(kp->base + PRESCALE_OFFSET);
value &= ~PRESCALE_MASK(chan);
value |= prescale << PRESCALE_SHIFT(chan);
writel(value, kp->base + PRESCALE_OFFSET);
writel(pc, kp->base + PERIOD_COUNT_OFFSET(chan));
writel(dc, kp->base + DUTY_CYCLE_HIGH_OFFSET(chan));
kona_pwmc_apply_settings(kp, chan);
}
return 0;
}
static int kona_pwmc_set_polarity(struct pwm_chip *chip, struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct kona_pwmc *kp = to_kona_pwmc(chip);
unsigned int chan = pwm->hwpwm;
unsigned int value;
int ret;
ret = clk_prepare_enable(kp->clk);
if (ret < 0) {
dev_err(chip->dev, "failed to enable clock: %d\n", ret);
return ret;
}
kona_pwmc_prepare_for_settings(kp, chan);
value = readl(kp->base + PWM_CONTROL_OFFSET);
if (polarity == PWM_POLARITY_NORMAL)
value |= 1 << PWM_CONTROL_POLARITY_SHIFT(chan);
else
value &= ~(1 << PWM_CONTROL_POLARITY_SHIFT(chan));
writel(value, kp->base + PWM_CONTROL_OFFSET);
kona_pwmc_apply_settings(kp, chan);
clk_disable_unprepare(kp->clk);
return 0;
}
static int kona_pwmc_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct kona_pwmc *kp = to_kona_pwmc(chip);
int ret;
ret = clk_prepare_enable(kp->clk);
if (ret < 0) {
dev_err(chip->dev, "failed to enable clock: %d\n", ret);
return ret;
}
ret = kona_pwmc_config(chip, pwm, pwm_get_duty_cycle(pwm),
pwm_get_period(pwm));
if (ret < 0) {
clk_disable_unprepare(kp->clk);
return ret;
}
return 0;
}
static void kona_pwmc_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct kona_pwmc *kp = to_kona_pwmc(chip);
unsigned int chan = pwm->hwpwm;
unsigned int value;
kona_pwmc_prepare_for_settings(kp, chan);
writel(0, kp->base + DUTY_CYCLE_HIGH_OFFSET(chan));
writel(0, kp->base + PERIOD_COUNT_OFFSET(chan));
value = readl(kp->base + PRESCALE_OFFSET);
value &= ~PRESCALE_MASK(chan);
writel(value, kp->base + PRESCALE_OFFSET);
kona_pwmc_apply_settings(kp, chan);
clk_disable_unprepare(kp->clk);
}
static int kona_pwmc_probe(struct platform_device *pdev)
{
struct kona_pwmc *kp;
struct resource *res;
unsigned int chan;
unsigned int value = 0;
int ret = 0;
kp = devm_kzalloc(&pdev->dev, sizeof(*kp), GFP_KERNEL);
if (kp == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, kp);
kp->chip.dev = &pdev->dev;
kp->chip.ops = &kona_pwm_ops;
kp->chip.base = -1;
kp->chip.npwm = 6;
kp->chip.of_xlate = of_pwm_xlate_with_flags;
kp->chip.of_pwm_n_cells = 3;
kp->chip.can_sleep = true;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
kp->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(kp->base))
return PTR_ERR(kp->base);
kp->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(kp->clk)) {
dev_err(&pdev->dev, "failed to get clock: %ld\n",
PTR_ERR(kp->clk));
return PTR_ERR(kp->clk);
}
ret = clk_prepare_enable(kp->clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable clock: %d\n", ret);
return ret;
}
for (chan = 0; chan < kp->chip.npwm; chan++)
value |= (1 << PWM_CONTROL_TYPE_SHIFT(chan));
writel(value, kp->base + PWM_CONTROL_OFFSET);
clk_disable_unprepare(kp->clk);
ret = pwmchip_add_with_polarity(&kp->chip, PWM_POLARITY_INVERSED);
if (ret < 0)
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
return ret;
}
static int kona_pwmc_remove(struct platform_device *pdev)
{
struct kona_pwmc *kp = platform_get_drvdata(pdev);
unsigned int chan;
for (chan = 0; chan < kp->chip.npwm; chan++)
if (pwm_is_enabled(&kp->chip.pwms[chan]))
clk_disable_unprepare(kp->clk);
return pwmchip_remove(&kp->chip);
}
