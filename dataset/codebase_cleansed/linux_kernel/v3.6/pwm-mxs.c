static int mxs_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct mxs_pwm_chip *mxs = to_mxs_pwm_chip(chip);
int ret, div = 0;
unsigned int period_cycles, duty_cycles;
unsigned long rate;
unsigned long long c;
rate = clk_get_rate(mxs->clk);
while (1) {
c = rate / (1 << div);
c = c * period_ns;
do_div(c, 1000000000);
if (c < PERIOD_PERIOD_MAX)
break;
div++;
if (div > PERIOD_CDIV_MAX)
return -EINVAL;
}
period_cycles = c;
c *= duty_ns;
do_div(c, period_ns);
duty_cycles = c;
if (!test_bit(PWMF_ENABLED, &pwm->flags)) {
ret = clk_prepare_enable(mxs->clk);
if (ret)
return ret;
}
writel(duty_cycles << 16,
mxs->base + PWM_ACTIVE0 + pwm->hwpwm * 0x20);
writel(PERIOD_PERIOD(period_cycles) | PERIOD_ACTIVE_HIGH |
PERIOD_INACTIVE_LOW | PERIOD_CDIV(div),
mxs->base + PWM_PERIOD0 + pwm->hwpwm * 0x20);
if (!test_bit(PWMF_ENABLED, &pwm->flags))
clk_disable_unprepare(mxs->clk);
return 0;
}
static int mxs_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mxs_pwm_chip *mxs = to_mxs_pwm_chip(chip);
int ret;
ret = clk_prepare_enable(mxs->clk);
if (ret)
return ret;
writel(1 << pwm->hwpwm, mxs->base + PWM_CTRL + SET);
return 0;
}
static void mxs_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mxs_pwm_chip *mxs = to_mxs_pwm_chip(chip);
writel(1 << pwm->hwpwm, mxs->base + PWM_CTRL + CLR);
clk_disable_unprepare(mxs->clk);
}
static int mxs_pwm_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mxs_pwm_chip *mxs;
struct resource *res;
struct pinctrl *pinctrl;
int ret;
mxs = devm_kzalloc(&pdev->dev, sizeof(*mxs), GFP_KERNEL);
if (!mxs)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mxs->base = devm_request_and_ioremap(&pdev->dev, res);
if (!mxs->base)
return -EADDRNOTAVAIL;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl))
return PTR_ERR(pinctrl);
mxs->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(mxs->clk))
return PTR_ERR(mxs->clk);
mxs->chip.dev = &pdev->dev;
mxs->chip.ops = &mxs_pwm_ops;
mxs->chip.base = -1;
ret = of_property_read_u32(np, "fsl,pwm-number", &mxs->chip.npwm);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get pwm number: %d\n", ret);
return ret;
}
ret = pwmchip_add(&mxs->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add pwm chip %d\n", ret);
return ret;
}
mxs->dev = &pdev->dev;
platform_set_drvdata(pdev, mxs);
stmp_reset_block(mxs->base);
return 0;
}
static int __devexit mxs_pwm_remove(struct platform_device *pdev)
{
struct mxs_pwm_chip *mxs = platform_get_drvdata(pdev);
return pwmchip_remove(&mxs->chip);
}
