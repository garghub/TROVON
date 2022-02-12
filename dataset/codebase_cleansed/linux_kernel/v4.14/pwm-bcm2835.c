static inline struct bcm2835_pwm *to_bcm2835_pwm(struct pwm_chip *chip)
{
return container_of(chip, struct bcm2835_pwm, chip);
}
static int bcm2835_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bcm2835_pwm *pc = to_bcm2835_pwm(chip);
u32 value;
value = readl(pc->base + PWM_CONTROL);
value &= ~(PWM_CONTROL_MASK << PWM_CONTROL_SHIFT(pwm->hwpwm));
value |= (PWM_MODE << PWM_CONTROL_SHIFT(pwm->hwpwm));
writel(value, pc->base + PWM_CONTROL);
return 0;
}
static void bcm2835_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bcm2835_pwm *pc = to_bcm2835_pwm(chip);
u32 value;
value = readl(pc->base + PWM_CONTROL);
value &= ~(PWM_CONTROL_MASK << PWM_CONTROL_SHIFT(pwm->hwpwm));
writel(value, pc->base + PWM_CONTROL);
}
static int bcm2835_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct bcm2835_pwm *pc = to_bcm2835_pwm(chip);
unsigned long rate = clk_get_rate(pc->clk);
unsigned long scaler;
if (!rate) {
dev_err(pc->dev, "failed to get clock rate\n");
return -EINVAL;
}
scaler = NSEC_PER_SEC / rate;
if (period_ns <= MIN_PERIOD) {
dev_err(pc->dev, "period %d not supported, minimum %d\n",
period_ns, MIN_PERIOD);
return -EINVAL;
}
writel(duty_ns / scaler, pc->base + DUTY(pwm->hwpwm));
writel(period_ns / scaler, pc->base + PERIOD(pwm->hwpwm));
return 0;
}
static int bcm2835_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bcm2835_pwm *pc = to_bcm2835_pwm(chip);
u32 value;
value = readl(pc->base + PWM_CONTROL);
value |= PWM_ENABLE << PWM_CONTROL_SHIFT(pwm->hwpwm);
writel(value, pc->base + PWM_CONTROL);
return 0;
}
static void bcm2835_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bcm2835_pwm *pc = to_bcm2835_pwm(chip);
u32 value;
value = readl(pc->base + PWM_CONTROL);
value &= ~(PWM_ENABLE << PWM_CONTROL_SHIFT(pwm->hwpwm));
writel(value, pc->base + PWM_CONTROL);
}
static int bcm2835_set_polarity(struct pwm_chip *chip, struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct bcm2835_pwm *pc = to_bcm2835_pwm(chip);
u32 value;
value = readl(pc->base + PWM_CONTROL);
if (polarity == PWM_POLARITY_NORMAL)
value &= ~(PWM_POLARITY << PWM_CONTROL_SHIFT(pwm->hwpwm));
else
value |= PWM_POLARITY << PWM_CONTROL_SHIFT(pwm->hwpwm);
writel(value, pc->base + PWM_CONTROL);
return 0;
}
static int bcm2835_pwm_probe(struct platform_device *pdev)
{
struct bcm2835_pwm *pc;
struct resource *res;
int ret;
pc = devm_kzalloc(&pdev->dev, sizeof(*pc), GFP_KERNEL);
if (!pc)
return -ENOMEM;
pc->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pc->base))
return PTR_ERR(pc->base);
pc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pc->clk)) {
dev_err(&pdev->dev, "clock not found: %ld\n", PTR_ERR(pc->clk));
return PTR_ERR(pc->clk);
}
ret = clk_prepare_enable(pc->clk);
if (ret)
return ret;
pc->chip.dev = &pdev->dev;
pc->chip.ops = &bcm2835_pwm_ops;
pc->chip.npwm = 2;
pc->chip.of_xlate = of_pwm_xlate_with_flags;
pc->chip.of_pwm_n_cells = 3;
platform_set_drvdata(pdev, pc);
ret = pwmchip_add(&pc->chip);
if (ret < 0)
goto add_fail;
return 0;
add_fail:
clk_disable_unprepare(pc->clk);
return ret;
}
static int bcm2835_pwm_remove(struct platform_device *pdev)
{
struct bcm2835_pwm *pc = platform_get_drvdata(pdev);
clk_disable_unprepare(pc->clk);
return pwmchip_remove(&pc->chip);
}
