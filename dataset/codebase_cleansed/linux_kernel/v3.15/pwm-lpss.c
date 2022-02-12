static inline struct pwm_lpss_chip *to_lpwm(struct pwm_chip *chip)
{
return container_of(chip, struct pwm_lpss_chip, chip);
}
static int pwm_lpss_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
u8 on_time_div;
unsigned long c;
unsigned long long base_unit, freq = NSECS_PER_SEC;
u32 ctrl;
do_div(freq, period_ns);
base_unit = freq * 65536;
c = clk_get_rate(lpwm->clk);
if (!c)
return -EINVAL;
do_div(base_unit, c);
base_unit += PWM_DIVISION_CORRECTION;
if (base_unit > PWM_LIMIT)
return -EINVAL;
if (duty_ns <= 0)
duty_ns = 1;
on_time_div = 255 - (255 * duty_ns / period_ns);
ctrl = readl(lpwm->regs + PWM);
ctrl &= ~(PWM_BASE_UNIT_MASK | PWM_ON_TIME_DIV_MASK);
ctrl |= (u16) base_unit << PWM_BASE_UNIT_SHIFT;
ctrl |= on_time_div;
ctrl |= PWM_SW_UPDATE;
writel(ctrl, lpwm->regs + PWM);
return 0;
}
static int pwm_lpss_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
u32 ctrl;
int ret;
ret = clk_prepare_enable(lpwm->clk);
if (ret)
return ret;
ctrl = readl(lpwm->regs + PWM);
writel(ctrl | PWM_ENABLE, lpwm->regs + PWM);
return 0;
}
static void pwm_lpss_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
u32 ctrl;
ctrl = readl(lpwm->regs + PWM);
writel(ctrl & ~PWM_ENABLE, lpwm->regs + PWM);
clk_disable_unprepare(lpwm->clk);
}
static int pwm_lpss_probe(struct platform_device *pdev)
{
struct pwm_lpss_chip *lpwm;
struct resource *r;
int ret;
lpwm = devm_kzalloc(&pdev->dev, sizeof(*lpwm), GFP_KERNEL);
if (!lpwm)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
lpwm->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(lpwm->regs))
return PTR_ERR(lpwm->regs);
lpwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(lpwm->clk)) {
dev_err(&pdev->dev, "failed to get PWM clock\n");
return PTR_ERR(lpwm->clk);
}
lpwm->chip.dev = &pdev->dev;
lpwm->chip.ops = &pwm_lpss_ops;
lpwm->chip.base = -1;
lpwm->chip.npwm = 1;
ret = pwmchip_add(&lpwm->chip);
if (ret) {
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, lpwm);
return 0;
}
static int pwm_lpss_remove(struct platform_device *pdev)
{
struct pwm_lpss_chip *lpwm = platform_get_drvdata(pdev);
u32 ctrl;
ctrl = readl(lpwm->regs + PWM);
writel(ctrl & ~PWM_ENABLE, lpwm->regs + PWM);
return pwmchip_remove(&lpwm->chip);
}
