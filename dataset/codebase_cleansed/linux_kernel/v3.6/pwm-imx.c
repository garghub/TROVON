static int imx_pwm_config(struct pwm_chip *chip,
struct pwm_device *pwm, int duty_ns, int period_ns)
{
struct imx_chip *imx = to_imx_chip(chip);
if (!(cpu_is_mx1() || cpu_is_mx21())) {
unsigned long long c;
unsigned long period_cycles, duty_cycles, prescale;
u32 cr;
c = clk_get_rate(imx->clk);
c = c * period_ns;
do_div(c, 1000000000);
period_cycles = c;
prescale = period_cycles / 0x10000 + 1;
period_cycles /= prescale;
c = (unsigned long long)period_cycles * duty_ns;
do_div(c, period_ns);
duty_cycles = c;
if (period_cycles > 2)
period_cycles -= 2;
else
period_cycles = 0;
writel(duty_cycles, imx->mmio_base + MX3_PWMSAR);
writel(period_cycles, imx->mmio_base + MX3_PWMPR);
cr = MX3_PWMCR_PRESCALER(prescale) |
MX3_PWMCR_DOZEEN | MX3_PWMCR_WAITEN |
MX3_PWMCR_DBGEN | MX3_PWMCR_EN;
if (cpu_is_mx25())
cr |= MX3_PWMCR_CLKSRC_IPG;
else
cr |= MX3_PWMCR_CLKSRC_IPG_HIGH;
writel(cr, imx->mmio_base + MX3_PWMCR);
} else if (cpu_is_mx1() || cpu_is_mx21()) {
u32 max = readl(imx->mmio_base + MX1_PWMP);
u32 p = max * duty_ns / period_ns;
writel(max - p, imx->mmio_base + MX1_PWMS);
} else {
BUG();
}
return 0;
}
static int imx_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct imx_chip *imx = to_imx_chip(chip);
int rc = 0;
if (!imx->clk_enabled) {
rc = clk_prepare_enable(imx->clk);
if (!rc)
imx->clk_enabled = 1;
}
return rc;
}
static void imx_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct imx_chip *imx = to_imx_chip(chip);
writel(0, imx->mmio_base + MX3_PWMCR);
if (imx->clk_enabled) {
clk_disable_unprepare(imx->clk);
imx->clk_enabled = 0;
}
}
static int __devinit imx_pwm_probe(struct platform_device *pdev)
{
struct imx_chip *imx;
struct resource *r;
int ret = 0;
imx = devm_kzalloc(&pdev->dev, sizeof(*imx), GFP_KERNEL);
if (imx == NULL) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
imx->clk = devm_clk_get(&pdev->dev, "pwm");
if (IS_ERR(imx->clk))
return PTR_ERR(imx->clk);
imx->chip.ops = &imx_pwm_ops;
imx->chip.dev = &pdev->dev;
imx->chip.base = -1;
imx->chip.npwm = 1;
imx->clk_enabled = 0;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
dev_err(&pdev->dev, "no memory resource defined\n");
return -ENODEV;
}
imx->mmio_base = devm_request_and_ioremap(&pdev->dev, r);
if (imx->mmio_base == NULL)
return -EADDRNOTAVAIL;
ret = pwmchip_add(&imx->chip);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, imx);
return 0;
}
static int __devexit imx_pwm_remove(struct platform_device *pdev)
{
struct imx_chip *imx;
imx = platform_get_drvdata(pdev);
if (imx == NULL)
return -ENODEV;
return pwmchip_remove(&imx->chip);
}
static int __init imx_pwm_init(void)
{
return platform_driver_register(&imx_pwm_driver);
}
static void __exit imx_pwm_exit(void)
{
platform_driver_unregister(&imx_pwm_driver);
}
