static inline struct pxa_pwm_chip *to_pxa_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct pxa_pwm_chip, chip);
}
static int pxa_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct pxa_pwm_chip *pc = to_pxa_pwm_chip(chip);
unsigned long long c;
unsigned long period_cycles, prescale, pv, dc;
unsigned long offset;
int rc;
offset = pwm->hwpwm ? 0x10 : 0;
c = clk_get_rate(pc->clk);
c = c * period_ns;
do_div(c, 1000000000);
period_cycles = c;
if (period_cycles < 1)
period_cycles = 1;
prescale = (period_cycles - 1) / 1024;
pv = period_cycles / (prescale + 1) - 1;
if (prescale > 63)
return -EINVAL;
if (duty_ns == period_ns)
dc = PWMDCR_FD;
else
dc = (pv + 1) * duty_ns / period_ns;
rc = clk_prepare_enable(pc->clk);
if (rc < 0)
return rc;
writel(prescale, pc->mmio_base + offset + PWMCR);
writel(dc, pc->mmio_base + offset + PWMDCR);
writel(pv, pc->mmio_base + offset + PWMPCR);
clk_disable_unprepare(pc->clk);
return 0;
}
static int pxa_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pxa_pwm_chip *pc = to_pxa_pwm_chip(chip);
int rc = 0;
if (!pc->clk_enabled) {
rc = clk_prepare_enable(pc->clk);
if (!rc)
pc->clk_enabled++;
}
return rc;
}
static void pxa_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pxa_pwm_chip *pc = to_pxa_pwm_chip(chip);
if (pc->clk_enabled) {
clk_disable_unprepare(pc->clk);
pc->clk_enabled--;
}
}
static int pwm_probe(struct platform_device *pdev)
{
const struct platform_device_id *id = platform_get_device_id(pdev);
struct pxa_pwm_chip *pwm;
struct resource *r;
int ret = 0;
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (pwm == NULL) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
pwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pwm->clk))
return PTR_ERR(pwm->clk);
pwm->clk_enabled = 0;
pwm->chip.dev = &pdev->dev;
pwm->chip.ops = &pxa_pwm_ops;
pwm->chip.base = -1;
pwm->chip.npwm = (id->driver_data & HAS_SECONDARY_PWM) ? 2 : 1;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
dev_err(&pdev->dev, "no memory resource defined\n");
return -ENODEV;
}
pwm->mmio_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(pwm->mmio_base))
return PTR_ERR(pwm->mmio_base);
ret = pwmchip_add(&pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, pwm);
return 0;
}
static int pwm_remove(struct platform_device *pdev)
{
struct pxa_pwm_chip *chip;
chip = platform_get_drvdata(pdev);
if (chip == NULL)
return -ENODEV;
return pwmchip_remove(&chip->chip);
}
static int __init pwm_init(void)
{
return platform_driver_register(&pwm_driver);
}
static void __exit pwm_exit(void)
{
platform_driver_unregister(&pwm_driver);
}
