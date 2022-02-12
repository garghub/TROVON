static inline struct sun4i_pwm_chip *to_sun4i_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct sun4i_pwm_chip, chip);
}
static inline u32 sun4i_pwm_readl(struct sun4i_pwm_chip *chip,
unsigned long offset)
{
return readl(chip->base + offset);
}
static inline void sun4i_pwm_writel(struct sun4i_pwm_chip *chip,
u32 val, unsigned long offset)
{
writel(val, chip->base + offset);
}
static int sun4i_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct sun4i_pwm_chip *sun4i_pwm = to_sun4i_pwm_chip(chip);
u32 prd, dty, val, clk_gate;
u64 clk_rate, div = 0;
unsigned int prescaler = 0;
int err;
clk_rate = clk_get_rate(sun4i_pwm->clk);
if (sun4i_pwm->data->has_prescaler_bypass) {
prescaler = PWM_PRESCAL_MASK;
div = clk_rate * period_ns + NSEC_PER_SEC / 2;
do_div(div, NSEC_PER_SEC);
if (div - 1 > PWM_PRD_MASK)
prescaler = 0;
}
if (prescaler == 0) {
for (prescaler = 0; prescaler < PWM_PRESCAL_MASK; prescaler++) {
if (!prescaler_table[prescaler])
continue;
div = clk_rate;
do_div(div, prescaler_table[prescaler]);
div = div * period_ns;
do_div(div, NSEC_PER_SEC);
if (div - 1 <= PWM_PRD_MASK)
break;
}
if (div - 1 > PWM_PRD_MASK) {
dev_err(chip->dev, "period exceeds the maximum value\n");
return -EINVAL;
}
}
prd = div;
div *= duty_ns;
do_div(div, period_ns);
dty = div;
err = clk_prepare_enable(sun4i_pwm->clk);
if (err) {
dev_err(chip->dev, "failed to enable PWM clock\n");
return err;
}
spin_lock(&sun4i_pwm->ctrl_lock);
val = sun4i_pwm_readl(sun4i_pwm, PWM_CTRL_REG);
if (sun4i_pwm->data->has_rdy && (val & PWM_RDY(pwm->hwpwm))) {
spin_unlock(&sun4i_pwm->ctrl_lock);
clk_disable_unprepare(sun4i_pwm->clk);
return -EBUSY;
}
clk_gate = val & BIT_CH(PWM_CLK_GATING, pwm->hwpwm);
if (clk_gate) {
val &= ~BIT_CH(PWM_CLK_GATING, pwm->hwpwm);
sun4i_pwm_writel(sun4i_pwm, val, PWM_CTRL_REG);
}
val = sun4i_pwm_readl(sun4i_pwm, PWM_CTRL_REG);
val &= ~BIT_CH(PWM_PRESCAL_MASK, pwm->hwpwm);
val |= BIT_CH(prescaler, pwm->hwpwm);
sun4i_pwm_writel(sun4i_pwm, val, PWM_CTRL_REG);
val = (dty & PWM_DTY_MASK) | PWM_PRD(prd);
sun4i_pwm_writel(sun4i_pwm, val, PWM_CH_PRD(pwm->hwpwm));
if (clk_gate) {
val = sun4i_pwm_readl(sun4i_pwm, PWM_CTRL_REG);
val |= clk_gate;
sun4i_pwm_writel(sun4i_pwm, val, PWM_CTRL_REG);
}
spin_unlock(&sun4i_pwm->ctrl_lock);
clk_disable_unprepare(sun4i_pwm->clk);
return 0;
}
static int sun4i_pwm_set_polarity(struct pwm_chip *chip, struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct sun4i_pwm_chip *sun4i_pwm = to_sun4i_pwm_chip(chip);
u32 val;
int ret;
ret = clk_prepare_enable(sun4i_pwm->clk);
if (ret) {
dev_err(chip->dev, "failed to enable PWM clock\n");
return ret;
}
spin_lock(&sun4i_pwm->ctrl_lock);
val = sun4i_pwm_readl(sun4i_pwm, PWM_CTRL_REG);
if (polarity != PWM_POLARITY_NORMAL)
val &= ~BIT_CH(PWM_ACT_STATE, pwm->hwpwm);
else
val |= BIT_CH(PWM_ACT_STATE, pwm->hwpwm);
sun4i_pwm_writel(sun4i_pwm, val, PWM_CTRL_REG);
spin_unlock(&sun4i_pwm->ctrl_lock);
clk_disable_unprepare(sun4i_pwm->clk);
return 0;
}
static int sun4i_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct sun4i_pwm_chip *sun4i_pwm = to_sun4i_pwm_chip(chip);
u32 val;
int ret;
ret = clk_prepare_enable(sun4i_pwm->clk);
if (ret) {
dev_err(chip->dev, "failed to enable PWM clock\n");
return ret;
}
spin_lock(&sun4i_pwm->ctrl_lock);
val = sun4i_pwm_readl(sun4i_pwm, PWM_CTRL_REG);
val |= BIT_CH(PWM_EN, pwm->hwpwm);
val |= BIT_CH(PWM_CLK_GATING, pwm->hwpwm);
sun4i_pwm_writel(sun4i_pwm, val, PWM_CTRL_REG);
spin_unlock(&sun4i_pwm->ctrl_lock);
return 0;
}
static void sun4i_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct sun4i_pwm_chip *sun4i_pwm = to_sun4i_pwm_chip(chip);
u32 val;
spin_lock(&sun4i_pwm->ctrl_lock);
val = sun4i_pwm_readl(sun4i_pwm, PWM_CTRL_REG);
val &= ~BIT_CH(PWM_EN, pwm->hwpwm);
val &= ~BIT_CH(PWM_CLK_GATING, pwm->hwpwm);
sun4i_pwm_writel(sun4i_pwm, val, PWM_CTRL_REG);
spin_unlock(&sun4i_pwm->ctrl_lock);
clk_disable_unprepare(sun4i_pwm->clk);
}
static int sun4i_pwm_probe(struct platform_device *pdev)
{
struct sun4i_pwm_chip *pwm;
struct resource *res;
u32 val;
int i, ret;
const struct of_device_id *match;
match = of_match_device(sun4i_pwm_dt_ids, &pdev->dev);
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (!pwm)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pwm->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pwm->base))
return PTR_ERR(pwm->base);
pwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pwm->clk))
return PTR_ERR(pwm->clk);
pwm->data = match->data;
pwm->chip.dev = &pdev->dev;
pwm->chip.ops = &sun4i_pwm_ops;
pwm->chip.base = -1;
pwm->chip.npwm = pwm->data->npwm;
pwm->chip.of_xlate = of_pwm_xlate_with_flags;
pwm->chip.of_pwm_n_cells = 3;
spin_lock_init(&pwm->ctrl_lock);
ret = pwmchip_add(&pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, pwm);
ret = clk_prepare_enable(pwm->clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable PWM clock\n");
goto clk_error;
}
val = sun4i_pwm_readl(pwm, PWM_CTRL_REG);
for (i = 0; i < pwm->chip.npwm; i++)
if (!(val & BIT_CH(PWM_ACT_STATE, i)))
pwm_set_polarity(&pwm->chip.pwms[i],
PWM_POLARITY_INVERSED);
clk_disable_unprepare(pwm->clk);
return 0;
clk_error:
pwmchip_remove(&pwm->chip);
return ret;
}
static int sun4i_pwm_remove(struct platform_device *pdev)
{
struct sun4i_pwm_chip *pwm = platform_get_drvdata(pdev);
return pwmchip_remove(&pwm->chip);
}
