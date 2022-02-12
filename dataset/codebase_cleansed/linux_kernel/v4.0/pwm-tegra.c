static inline struct tegra_pwm_chip *to_tegra_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct tegra_pwm_chip, chip);
}
static inline u32 pwm_readl(struct tegra_pwm_chip *chip, unsigned int num)
{
return readl(chip->mmio_base + (num << 4));
}
static inline void pwm_writel(struct tegra_pwm_chip *chip, unsigned int num,
unsigned long val)
{
writel(val, chip->mmio_base + (num << 4));
}
static int tegra_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct tegra_pwm_chip *pc = to_tegra_pwm_chip(chip);
unsigned long long c;
unsigned long rate, hz;
u32 val = 0;
int err;
c = duty_ns * ((1 << PWM_DUTY_WIDTH) - 1) + period_ns / 2;
do_div(c, period_ns);
val = (u32)c << PWM_DUTY_SHIFT;
rate = clk_get_rate(pc->clk) >> PWM_DUTY_WIDTH;
hz = NSEC_PER_SEC / period_ns;
rate = (rate + (hz / 2)) / hz;
if (rate > 0)
rate--;
if (rate >> PWM_SCALE_WIDTH)
return -EINVAL;
val |= rate << PWM_SCALE_SHIFT;
if (!test_bit(PWMF_ENABLED, &pwm->flags)) {
err = clk_prepare_enable(pc->clk);
if (err < 0)
return err;
} else
val |= PWM_ENABLE;
pwm_writel(pc, pwm->hwpwm, val);
if (!test_bit(PWMF_ENABLED, &pwm->flags))
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
pwm->dev = &pdev->dev;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pwm->mmio_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(pwm->mmio_base))
return PTR_ERR(pwm->mmio_base);
platform_set_drvdata(pdev, pwm);
pwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pwm->clk))
return PTR_ERR(pwm->clk);
pwm->chip.dev = &pdev->dev;
pwm->chip.ops = &tegra_pwm_ops;
pwm->chip.base = -1;
pwm->chip.npwm = NUM_PWM;
ret = pwmchip_add(&pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
return ret;
}
return 0;
}
static int tegra_pwm_remove(struct platform_device *pdev)
{
struct tegra_pwm_chip *pc = platform_get_drvdata(pdev);
int i;
if (WARN_ON(!pc))
return -ENODEV;
for (i = 0; i < NUM_PWM; i++) {
struct pwm_device *pwm = &pc->chip.pwms[i];
if (!test_bit(PWMF_ENABLED, &pwm->flags))
if (clk_prepare_enable(pc->clk) < 0)
continue;
pwm_writel(pc, i, 0);
clk_disable_unprepare(pc->clk);
}
return pwmchip_remove(&pc->chip);
}
