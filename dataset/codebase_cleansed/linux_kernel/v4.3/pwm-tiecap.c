static inline struct ecap_pwm_chip *to_ecap_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct ecap_pwm_chip, chip);
}
static int ecap_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct ecap_pwm_chip *pc = to_ecap_pwm_chip(chip);
unsigned long long c;
unsigned long period_cycles, duty_cycles;
unsigned int reg_val;
if (period_ns > NSEC_PER_SEC)
return -ERANGE;
c = pc->clk_rate;
c = c * period_ns;
do_div(c, NSEC_PER_SEC);
period_cycles = (unsigned long)c;
if (period_cycles < 1) {
period_cycles = 1;
duty_cycles = 1;
} else {
c = pc->clk_rate;
c = c * duty_ns;
do_div(c, NSEC_PER_SEC);
duty_cycles = (unsigned long)c;
}
pm_runtime_get_sync(pc->chip.dev);
reg_val = readw(pc->mmio_base + ECCTL2);
reg_val |= ECCTL2_APWM_MODE | ECCTL2_SYNC_SEL_DISA;
writew(reg_val, pc->mmio_base + ECCTL2);
if (!pwm_is_enabled(pwm)) {
writel(duty_cycles, pc->mmio_base + CAP2);
writel(period_cycles, pc->mmio_base + CAP1);
} else {
writel(duty_cycles, pc->mmio_base + CAP4);
writel(period_cycles, pc->mmio_base + CAP3);
}
if (!pwm_is_enabled(pwm)) {
reg_val = readw(pc->mmio_base + ECCTL2);
reg_val &= ~ECCTL2_APWM_MODE;
writew(reg_val, pc->mmio_base + ECCTL2);
}
pm_runtime_put_sync(pc->chip.dev);
return 0;
}
static int ecap_pwm_set_polarity(struct pwm_chip *chip, struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct ecap_pwm_chip *pc = to_ecap_pwm_chip(chip);
unsigned short reg_val;
pm_runtime_get_sync(pc->chip.dev);
reg_val = readw(pc->mmio_base + ECCTL2);
if (polarity == PWM_POLARITY_INVERSED)
reg_val |= ECCTL2_APWM_POL_LOW;
else
reg_val &= ~ECCTL2_APWM_POL_LOW;
writew(reg_val, pc->mmio_base + ECCTL2);
pm_runtime_put_sync(pc->chip.dev);
return 0;
}
static int ecap_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct ecap_pwm_chip *pc = to_ecap_pwm_chip(chip);
unsigned int reg_val;
pm_runtime_get_sync(pc->chip.dev);
reg_val = readw(pc->mmio_base + ECCTL2);
reg_val |= ECCTL2_TSCTR_FREERUN | ECCTL2_APWM_MODE;
writew(reg_val, pc->mmio_base + ECCTL2);
return 0;
}
static void ecap_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct ecap_pwm_chip *pc = to_ecap_pwm_chip(chip);
unsigned int reg_val;
reg_val = readw(pc->mmio_base + ECCTL2);
reg_val &= ~(ECCTL2_TSCTR_FREERUN | ECCTL2_APWM_MODE);
writew(reg_val, pc->mmio_base + ECCTL2);
pm_runtime_put_sync(pc->chip.dev);
}
static void ecap_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
if (pwm_is_enabled(pwm)) {
dev_warn(chip->dev, "Removing PWM device without disabling\n");
pm_runtime_put_sync(chip->dev);
}
}
static int ecap_pwm_probe(struct platform_device *pdev)
{
int ret;
struct resource *r;
struct clk *clk;
struct ecap_pwm_chip *pc;
u16 status;
pc = devm_kzalloc(&pdev->dev, sizeof(*pc), GFP_KERNEL);
if (!pc)
return -ENOMEM;
clk = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(clk);
}
pc->clk_rate = clk_get_rate(clk);
if (!pc->clk_rate) {
dev_err(&pdev->dev, "failed to get clock rate\n");
return -EINVAL;
}
pc->chip.dev = &pdev->dev;
pc->chip.ops = &ecap_pwm_ops;
pc->chip.of_xlate = of_pwm_xlate_with_flags;
pc->chip.of_pwm_n_cells = 3;
pc->chip.base = -1;
pc->chip.npwm = 1;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pc->mmio_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(pc->mmio_base))
return PTR_ERR(pc->mmio_base);
ret = pwmchip_add(&pc->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
return ret;
}
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
status = pwmss_submodule_state_change(pdev->dev.parent,
PWMSS_ECAPCLK_EN);
if (!(status & PWMSS_ECAPCLK_EN_ACK)) {
dev_err(&pdev->dev, "PWMSS config space clock enable failed\n");
ret = -EINVAL;
goto pwmss_clk_failure;
}
pm_runtime_put_sync(&pdev->dev);
platform_set_drvdata(pdev, pc);
return 0;
pwmss_clk_failure:
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
pwmchip_remove(&pc->chip);
return ret;
}
static int ecap_pwm_remove(struct platform_device *pdev)
{
struct ecap_pwm_chip *pc = platform_get_drvdata(pdev);
pm_runtime_get_sync(&pdev->dev);
pwmss_submodule_state_change(pdev->dev.parent, PWMSS_ECAPCLK_STOP_REQ);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return pwmchip_remove(&pc->chip);
}
static void ecap_pwm_save_context(struct ecap_pwm_chip *pc)
{
pm_runtime_get_sync(pc->chip.dev);
pc->ctx.ecctl2 = readw(pc->mmio_base + ECCTL2);
pc->ctx.cap4 = readl(pc->mmio_base + CAP4);
pc->ctx.cap3 = readl(pc->mmio_base + CAP3);
pm_runtime_put_sync(pc->chip.dev);
}
static void ecap_pwm_restore_context(struct ecap_pwm_chip *pc)
{
writel(pc->ctx.cap3, pc->mmio_base + CAP3);
writel(pc->ctx.cap4, pc->mmio_base + CAP4);
writew(pc->ctx.ecctl2, pc->mmio_base + ECCTL2);
}
static int ecap_pwm_suspend(struct device *dev)
{
struct ecap_pwm_chip *pc = dev_get_drvdata(dev);
struct pwm_device *pwm = pc->chip.pwms;
ecap_pwm_save_context(pc);
if (pwm_is_enabled(pwm))
pm_runtime_put_sync(dev);
return 0;
}
static int ecap_pwm_resume(struct device *dev)
{
struct ecap_pwm_chip *pc = dev_get_drvdata(dev);
struct pwm_device *pwm = pc->chip.pwms;
if (pwm_is_enabled(pwm))
pm_runtime_get_sync(dev);
ecap_pwm_restore_context(pc);
return 0;
}
