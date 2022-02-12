static inline struct iproc_pwmc *to_iproc_pwmc(struct pwm_chip *chip)
{
return container_of(chip, struct iproc_pwmc, chip);
}
static void iproc_pwmc_enable(struct iproc_pwmc *ip, unsigned int channel)
{
u32 value;
value = readl(ip->base + IPROC_PWM_CTRL_OFFSET);
value |= 1 << IPROC_PWM_CTRL_EN_SHIFT(channel);
writel(value, ip->base + IPROC_PWM_CTRL_OFFSET);
ndelay(400);
}
static void iproc_pwmc_disable(struct iproc_pwmc *ip, unsigned int channel)
{
u32 value;
value = readl(ip->base + IPROC_PWM_CTRL_OFFSET);
value &= ~(1 << IPROC_PWM_CTRL_EN_SHIFT(channel));
writel(value, ip->base + IPROC_PWM_CTRL_OFFSET);
ndelay(400);
}
static void iproc_pwmc_get_state(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct iproc_pwmc *ip = to_iproc_pwmc(chip);
u64 tmp, multi, rate;
u32 value, prescale;
rate = clk_get_rate(ip->clk);
value = readl(ip->base + IPROC_PWM_CTRL_OFFSET);
if (value & BIT(IPROC_PWM_CTRL_EN_SHIFT(pwm->hwpwm)))
state->enabled = true;
else
state->enabled = false;
if (value & BIT(IPROC_PWM_CTRL_POLARITY_SHIFT(pwm->hwpwm)))
state->polarity = PWM_POLARITY_NORMAL;
else
state->polarity = PWM_POLARITY_INVERSED;
value = readl(ip->base + IPROC_PWM_PRESCALE_OFFSET);
prescale = value >> IPROC_PWM_PRESCALE_SHIFT(pwm->hwpwm);
prescale &= IPROC_PWM_PRESCALE_MAX;
multi = NSEC_PER_SEC * (prescale + 1);
value = readl(ip->base + IPROC_PWM_PERIOD_OFFSET(pwm->hwpwm));
tmp = (value & IPROC_PWM_PERIOD_MAX) * multi;
state->period = div64_u64(tmp, rate);
value = readl(ip->base + IPROC_PWM_DUTY_CYCLE_OFFSET(pwm->hwpwm));
tmp = (value & IPROC_PWM_PERIOD_MAX) * multi;
state->duty_cycle = div64_u64(tmp, rate);
}
static int iproc_pwmc_apply(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
unsigned long prescale = IPROC_PWM_PRESCALE_MIN;
struct iproc_pwmc *ip = to_iproc_pwmc(chip);
u32 value, period, duty;
u64 rate;
rate = clk_get_rate(ip->clk);
while (1) {
u64 value, div;
div = NSEC_PER_SEC * (prescale + 1);
value = rate * state->period;
period = div64_u64(value, div);
value = rate * state->duty_cycle;
duty = div64_u64(value, div);
if (period < IPROC_PWM_PERIOD_MIN ||
duty < IPROC_PWM_DUTY_CYCLE_MIN)
return -EINVAL;
if (period <= IPROC_PWM_PERIOD_MAX &&
duty <= IPROC_PWM_DUTY_CYCLE_MAX)
break;
if (++prescale > IPROC_PWM_PRESCALE_MAX)
return -EINVAL;
}
iproc_pwmc_disable(ip, pwm->hwpwm);
value = readl(ip->base + IPROC_PWM_PRESCALE_OFFSET);
value &= ~IPROC_PWM_PRESCALE_MASK(pwm->hwpwm);
value |= prescale << IPROC_PWM_PRESCALE_SHIFT(pwm->hwpwm);
writel(value, ip->base + IPROC_PWM_PRESCALE_OFFSET);
writel(period, ip->base + IPROC_PWM_PERIOD_OFFSET(pwm->hwpwm));
writel(duty, ip->base + IPROC_PWM_DUTY_CYCLE_OFFSET(pwm->hwpwm));
value = readl(ip->base + IPROC_PWM_CTRL_OFFSET);
if (state->polarity == PWM_POLARITY_NORMAL)
value |= 1 << IPROC_PWM_CTRL_POLARITY_SHIFT(pwm->hwpwm);
else
value &= ~(1 << IPROC_PWM_CTRL_POLARITY_SHIFT(pwm->hwpwm));
writel(value, ip->base + IPROC_PWM_CTRL_OFFSET);
if (state->enabled)
iproc_pwmc_enable(ip, pwm->hwpwm);
return 0;
}
static int iproc_pwmc_probe(struct platform_device *pdev)
{
struct iproc_pwmc *ip;
struct resource *res;
unsigned int i;
u32 value;
int ret;
ip = devm_kzalloc(&pdev->dev, sizeof(*ip), GFP_KERNEL);
if (!ip)
return -ENOMEM;
platform_set_drvdata(pdev, ip);
ip->chip.dev = &pdev->dev;
ip->chip.ops = &iproc_pwm_ops;
ip->chip.base = -1;
ip->chip.npwm = 4;
ip->chip.of_xlate = of_pwm_xlate_with_flags;
ip->chip.of_pwm_n_cells = 3;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ip->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ip->base))
return PTR_ERR(ip->base);
ip->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(ip->clk)) {
dev_err(&pdev->dev, "failed to get clock: %ld\n",
PTR_ERR(ip->clk));
return PTR_ERR(ip->clk);
}
ret = clk_prepare_enable(ip->clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable clock: %d\n", ret);
return ret;
}
value = readl(ip->base + IPROC_PWM_CTRL_OFFSET);
for (i = 0; i < ip->chip.npwm; i++) {
value &= ~(1 << IPROC_PWM_CTRL_TYPE_SHIFT(i));
value |= 1 << IPROC_PWM_CTRL_POLARITY_SHIFT(i);
}
writel(value, ip->base + IPROC_PWM_CTRL_OFFSET);
ret = pwmchip_add(&ip->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
clk_disable_unprepare(ip->clk);
}
return ret;
}
static int iproc_pwmc_remove(struct platform_device *pdev)
{
struct iproc_pwmc *ip = platform_get_drvdata(pdev);
clk_disable_unprepare(ip->clk);
return pwmchip_remove(&ip->chip);
}
