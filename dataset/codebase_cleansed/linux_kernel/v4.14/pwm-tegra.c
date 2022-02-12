static inline struct tegra_pwm_chip *to_tegra_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct tegra_pwm_chip, chip);
}
static inline u32 pwm_readl(struct tegra_pwm_chip *chip, unsigned int num)
{
return readl(chip->regs + (num << 4));
}
static inline void pwm_writel(struct tegra_pwm_chip *chip, unsigned int num,
unsigned long val)
{
writel(val, chip->regs + (num << 4));
}
static int tegra_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct tegra_pwm_chip *pc = to_tegra_pwm_chip(chip);
unsigned long long c = duty_ns, hz;
unsigned long rate;
u32 val = 0;
int err;
c *= (1 << PWM_DUTY_WIDTH);
c = DIV_ROUND_CLOSEST_ULL(c, period_ns);
val = (u32)c << PWM_DUTY_SHIFT;
rate = pc->clk_rate >> PWM_DUTY_WIDTH;
hz = DIV_ROUND_CLOSEST_ULL(100ULL * NSEC_PER_SEC, period_ns);
rate = DIV_ROUND_CLOSEST_ULL(100ULL * rate, hz);
if (rate > 0)
rate--;
if (rate >> PWM_SCALE_WIDTH)
return -EINVAL;
val |= rate << PWM_SCALE_SHIFT;
if (!pwm_is_enabled(pwm)) {
err = clk_prepare_enable(pc->clk);
if (err < 0)
return err;
} else
val |= PWM_ENABLE;
pwm_writel(pc, pwm->hwpwm, val);
if (!pwm_is_enabled(pwm))
clk_disable_unprepare(pc->clk);
return 0;
}
static int tegra_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct tegra_pwm_chip *pc = to_tegra_pwm_chip(chip);
int rc = 0;
u32 val;
rc = clk_prepare_enable(pc->clk);
if (rc < 0)
return rc;
val = pwm_readl(pc, pwm->hwpwm);
val |= PWM_ENABLE;
pwm_writel(pc, pwm->hwpwm, val);
return 0;
}
static void tegra_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct tegra_pwm_chip *pc = to_tegra_pwm_chip(chip);
u32 val;
val = pwm_readl(pc, pwm->hwpwm);
val &= ~PWM_ENABLE;
pwm_writel(pc, pwm->hwpwm, val);
clk_disable_unprepare(pc->clk);
}
static int tegra_pwm_probe(struct platform_device *pdev)
{
struct tegra_pwm_chip *pwm;
struct resource *r;
int ret;
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (!pwm)
return -ENOMEM;
pwm->soc = of_device_get_match_data(&pdev->dev);
pwm->dev = &pdev->dev;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pwm->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(pwm->regs))
return PTR_ERR(pwm->regs);
platform_set_drvdata(pdev, pwm);
pwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pwm->clk))
return PTR_ERR(pwm->clk);
ret = clk_set_rate(pwm->clk, pwm->soc->max_frequency);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to set max frequency: %d\n", ret);
return ret;
}
pwm->clk_rate = clk_get_rate(pwm->clk);
pwm->rst = devm_reset_control_get_exclusive(&pdev->dev, "pwm");
if (IS_ERR(pwm->rst)) {
ret = PTR_ERR(pwm->rst);
dev_err(&pdev->dev, "Reset control is not found: %d\n", ret);
return ret;
}
reset_control_deassert(pwm->rst);
pwm->chip.dev = &pdev->dev;
pwm->chip.ops = &tegra_pwm_ops;
pwm->chip.base = -1;
pwm->chip.npwm = pwm->soc->num_channels;
ret = pwmchip_add(&pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
reset_control_assert(pwm->rst);
return ret;
}
return 0;
}
static int tegra_pwm_remove(struct platform_device *pdev)
{
struct tegra_pwm_chip *pc = platform_get_drvdata(pdev);
unsigned int i;
int err;
if (WARN_ON(!pc))
return -ENODEV;
err = clk_prepare_enable(pc->clk);
if (err < 0)
return err;
for (i = 0; i < pc->chip.npwm; i++) {
struct pwm_device *pwm = &pc->chip.pwms[i];
if (!pwm_is_enabled(pwm))
if (clk_prepare_enable(pc->clk) < 0)
continue;
pwm_writel(pc, i, 0);
clk_disable_unprepare(pc->clk);
}
reset_control_assert(pc->rst);
clk_disable_unprepare(pc->clk);
return pwmchip_remove(&pc->chip);
}
static int tegra_pwm_suspend(struct device *dev)
{
return pinctrl_pm_select_sleep_state(dev);
}
static int tegra_pwm_resume(struct device *dev)
{
return pinctrl_pm_select_default_state(dev);
}
