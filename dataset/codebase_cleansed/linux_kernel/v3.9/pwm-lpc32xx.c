static int lpc32xx_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct lpc32xx_pwm_chip *lpc32xx = to_lpc32xx_pwm_chip(chip);
unsigned long long c;
int period_cycles, duty_cycles;
c = clk_get_rate(lpc32xx->clk) / 256;
c = c * period_ns;
do_div(c, NSEC_PER_SEC);
if (c == 0)
c = 1;
if (c > 255)
c = 0;
period_cycles = c;
c = 256 * duty_ns;
do_div(c, period_ns);
if (c > 255)
c = 255;
duty_cycles = 256 - c;
writel(PWM_ENABLE | PWM_RELOADV(period_cycles) | PWM_DUTY(duty_cycles),
lpc32xx->base + (pwm->hwpwm << 2));
return 0;
}
static int lpc32xx_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct lpc32xx_pwm_chip *lpc32xx = to_lpc32xx_pwm_chip(chip);
return clk_enable(lpc32xx->clk);
}
static void lpc32xx_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct lpc32xx_pwm_chip *lpc32xx = to_lpc32xx_pwm_chip(chip);
writel(0, lpc32xx->base + (pwm->hwpwm << 2));
clk_disable(lpc32xx->clk);
}
static int lpc32xx_pwm_probe(struct platform_device *pdev)
{
struct lpc32xx_pwm_chip *lpc32xx;
struct resource *res;
int ret;
lpc32xx = devm_kzalloc(&pdev->dev, sizeof(*lpc32xx), GFP_KERNEL);
if (!lpc32xx)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
lpc32xx->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(lpc32xx->base))
return PTR_ERR(lpc32xx->base);
lpc32xx->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(lpc32xx->clk))
return PTR_ERR(lpc32xx->clk);
lpc32xx->chip.dev = &pdev->dev;
lpc32xx->chip.ops = &lpc32xx_pwm_ops;
lpc32xx->chip.npwm = 2;
lpc32xx->chip.base = -1;
ret = pwmchip_add(&lpc32xx->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip, error %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, lpc32xx);
return 0;
}
static int lpc32xx_pwm_remove(struct platform_device *pdev)
{
struct lpc32xx_pwm_chip *lpc32xx = platform_get_drvdata(pdev);
unsigned int i;
for (i = 0; i < lpc32xx->chip.npwm; i++)
pwm_disable(&lpc32xx->chip.pwms[i]);
return pwmchip_remove(&lpc32xx->chip);
}
