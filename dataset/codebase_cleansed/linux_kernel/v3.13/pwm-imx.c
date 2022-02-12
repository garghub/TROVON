static int imx_pwm_config_v1(struct pwm_chip *chip,
struct pwm_device *pwm, int duty_ns, int period_ns)
{
struct imx_chip *imx = to_imx_chip(chip);
u32 max = readl(imx->mmio_base + MX1_PWMP);
u32 p = max * duty_ns / period_ns;
writel(max - p, imx->mmio_base + MX1_PWMS);
return 0;
}
static void imx_pwm_set_enable_v1(struct pwm_chip *chip, bool enable)
{
struct imx_chip *imx = to_imx_chip(chip);
u32 val;
val = readl(imx->mmio_base + MX1_PWMC);
if (enable)
val |= MX1_PWMC_EN;
else
val &= ~MX1_PWMC_EN;
writel(val, imx->mmio_base + MX1_PWMC);
}
static int imx_pwm_config_v2(struct pwm_chip *chip,
struct pwm_device *pwm, int duty_ns, int period_ns)
{
struct imx_chip *imx = to_imx_chip(chip);
unsigned long long c;
unsigned long period_cycles, duty_cycles, prescale;
u32 cr;
c = clk_get_rate(imx->clk_per);
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
MX3_PWMCR_DBGEN | MX3_PWMCR_CLKSRC_IPG_HIGH;
if (test_bit(PWMF_ENABLED, &pwm->flags))
cr |= MX3_PWMCR_EN;
writel(cr, imx->mmio_base + MX3_PWMCR);
return 0;
}
static void imx_pwm_set_enable_v2(struct pwm_chip *chip, bool enable)
{
struct imx_chip *imx = to_imx_chip(chip);
u32 val;
val = readl(imx->mmio_base + MX3_PWMCR);
if (enable)
val |= MX3_PWMCR_EN;
else
val &= ~MX3_PWMCR_EN;
writel(val, imx->mmio_base + MX3_PWMCR);
}
static int imx_pwm_config(struct pwm_chip *chip,
struct pwm_device *pwm, int duty_ns, int period_ns)
{
struct imx_chip *imx = to_imx_chip(chip);
int ret;
ret = clk_prepare_enable(imx->clk_ipg);
if (ret)
return ret;
ret = imx->config(chip, pwm, duty_ns, period_ns);
clk_disable_unprepare(imx->clk_ipg);
return ret;
}
static int imx_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct imx_chip *imx = to_imx_chip(chip);
int ret;
ret = clk_prepare_enable(imx->clk_per);
if (ret)
return ret;
imx->set_enable(chip, true);
return 0;
}
static void imx_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct imx_chip *imx = to_imx_chip(chip);
imx->set_enable(chip, false);
clk_disable_unprepare(imx->clk_per);
}
static int imx_pwm_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(imx_pwm_dt_ids, &pdev->dev);
const struct imx_pwm_data *data;
struct imx_chip *imx;
struct resource *r;
int ret = 0;
if (!of_id)
return -ENODEV;
imx = devm_kzalloc(&pdev->dev, sizeof(*imx), GFP_KERNEL);
if (imx == NULL) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
imx->clk_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(imx->clk_per)) {
dev_err(&pdev->dev, "getting per clock failed with %ld\n",
PTR_ERR(imx->clk_per));
return PTR_ERR(imx->clk_per);
}
imx->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(imx->clk_ipg)) {
dev_err(&pdev->dev, "getting ipg clock failed with %ld\n",
PTR_ERR(imx->clk_ipg));
return PTR_ERR(imx->clk_ipg);
}
imx->chip.ops = &imx_pwm_ops;
imx->chip.dev = &pdev->dev;
imx->chip.base = -1;
imx->chip.npwm = 1;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
imx->mmio_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(imx->mmio_base))
return PTR_ERR(imx->mmio_base);
data = of_id->data;
imx->config = data->config;
imx->set_enable = data->set_enable;
ret = pwmchip_add(&imx->chip);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, imx);
return 0;
}
static int imx_pwm_remove(struct platform_device *pdev)
{
struct imx_chip *imx;
imx = platform_get_drvdata(pdev);
if (imx == NULL)
return -ENODEV;
return pwmchip_remove(&imx->chip);
}
