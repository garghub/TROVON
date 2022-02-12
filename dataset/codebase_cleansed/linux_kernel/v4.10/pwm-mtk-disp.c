static inline struct mtk_disp_pwm *to_mtk_disp_pwm(struct pwm_chip *chip)
{
return container_of(chip, struct mtk_disp_pwm, chip);
}
static void mtk_disp_pwm_update_bits(struct mtk_disp_pwm *mdp, u32 offset,
u32 mask, u32 data)
{
void __iomem *address = mdp->base + offset;
u32 value;
value = readl(address);
value &= ~mask;
value |= data;
writel(value, address);
}
static int mtk_disp_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct mtk_disp_pwm *mdp = to_mtk_disp_pwm(chip);
u32 clk_div, period, high_width, value;
u64 div, rate;
int err;
rate = clk_get_rate(mdp->clk_main);
clk_div = div_u64(rate * period_ns, NSEC_PER_SEC) >>
PWM_PERIOD_BIT_WIDTH;
if (clk_div > PWM_CLKDIV_MAX)
return -EINVAL;
div = NSEC_PER_SEC * (clk_div + 1);
period = div64_u64(rate * period_ns, div);
if (period > 0)
period--;
high_width = div64_u64(rate * duty_ns, div);
value = period | (high_width << PWM_HIGH_WIDTH_SHIFT);
err = clk_enable(mdp->clk_main);
if (err < 0)
return err;
err = clk_enable(mdp->clk_mm);
if (err < 0) {
clk_disable(mdp->clk_main);
return err;
}
mtk_disp_pwm_update_bits(mdp, mdp->data->con0,
PWM_CLKDIV_MASK,
clk_div << PWM_CLKDIV_SHIFT);
mtk_disp_pwm_update_bits(mdp, mdp->data->con1,
PWM_PERIOD_MASK | PWM_HIGH_WIDTH_MASK,
value);
if (mdp->data->has_commit) {
mtk_disp_pwm_update_bits(mdp, mdp->data->commit,
mdp->data->commit_mask,
mdp->data->commit_mask);
mtk_disp_pwm_update_bits(mdp, mdp->data->commit,
mdp->data->commit_mask,
0x0);
}
clk_disable(mdp->clk_mm);
clk_disable(mdp->clk_main);
return 0;
}
static int mtk_disp_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mtk_disp_pwm *mdp = to_mtk_disp_pwm(chip);
int err;
err = clk_enable(mdp->clk_main);
if (err < 0)
return err;
err = clk_enable(mdp->clk_mm);
if (err < 0) {
clk_disable(mdp->clk_main);
return err;
}
mtk_disp_pwm_update_bits(mdp, DISP_PWM_EN, mdp->data->enable_mask,
mdp->data->enable_mask);
return 0;
}
static void mtk_disp_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mtk_disp_pwm *mdp = to_mtk_disp_pwm(chip);
mtk_disp_pwm_update_bits(mdp, DISP_PWM_EN, mdp->data->enable_mask,
0x0);
clk_disable(mdp->clk_mm);
clk_disable(mdp->clk_main);
}
static int mtk_disp_pwm_probe(struct platform_device *pdev)
{
struct mtk_disp_pwm *mdp;
struct resource *r;
int ret;
mdp = devm_kzalloc(&pdev->dev, sizeof(*mdp), GFP_KERNEL);
if (!mdp)
return -ENOMEM;
mdp->data = of_device_get_match_data(&pdev->dev);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mdp->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(mdp->base))
return PTR_ERR(mdp->base);
mdp->clk_main = devm_clk_get(&pdev->dev, "main");
if (IS_ERR(mdp->clk_main))
return PTR_ERR(mdp->clk_main);
mdp->clk_mm = devm_clk_get(&pdev->dev, "mm");
if (IS_ERR(mdp->clk_mm))
return PTR_ERR(mdp->clk_mm);
ret = clk_prepare(mdp->clk_main);
if (ret < 0)
return ret;
ret = clk_prepare(mdp->clk_mm);
if (ret < 0)
goto disable_clk_main;
mdp->chip.dev = &pdev->dev;
mdp->chip.ops = &mtk_disp_pwm_ops;
mdp->chip.base = -1;
mdp->chip.npwm = 1;
ret = pwmchip_add(&mdp->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
goto disable_clk_mm;
}
platform_set_drvdata(pdev, mdp);
if (!mdp->data->has_commit) {
mtk_disp_pwm_update_bits(mdp, mdp->data->bls_debug,
mdp->data->bls_debug_mask,
mdp->data->bls_debug_mask);
mtk_disp_pwm_update_bits(mdp, mdp->data->con0,
mdp->data->con0_sel,
mdp->data->con0_sel);
}
return 0;
disable_clk_mm:
clk_unprepare(mdp->clk_mm);
disable_clk_main:
clk_unprepare(mdp->clk_main);
return ret;
}
static int mtk_disp_pwm_remove(struct platform_device *pdev)
{
struct mtk_disp_pwm *mdp = platform_get_drvdata(pdev);
int ret;
ret = pwmchip_remove(&mdp->chip);
clk_unprepare(mdp->clk_mm);
clk_unprepare(mdp->clk_main);
return ret;
}
