static inline void pwm_busy_wait(struct vt8500_chip *vt8500, int nr, u8 bitmask)
{
int loops = msecs_to_loops(10);
u32 mask = bitmask << (nr << 8);
while ((readl(vt8500->base + REG_STATUS) & mask) && --loops)
cpu_relax();
if (unlikely(!loops))
dev_warn(vt8500->chip.dev, "Waiting for status bits 0x%x to clear timed out\n",
mask);
}
static int vt8500_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
unsigned long long c;
unsigned long period_cycles, prescale, pv, dc;
int err;
u32 val;
err = clk_enable(vt8500->clk);
if (err < 0) {
dev_err(chip->dev, "failed to enable clock\n");
return err;
}
c = clk_get_rate(vt8500->clk);
c = c * period_ns;
do_div(c, 1000000000);
period_cycles = c;
if (period_cycles < 1)
period_cycles = 1;
prescale = (period_cycles - 1) / 4096;
pv = period_cycles / (prescale + 1) - 1;
if (pv > 4095)
pv = 4095;
if (prescale > 1023) {
clk_disable(vt8500->clk);
return -EINVAL;
}
c = (unsigned long long)pv * duty_ns;
do_div(c, period_ns);
dc = c;
writel(prescale, vt8500->base + REG_SCALAR(pwm->hwpwm));
pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_SCALAR_UPDATE);
writel(pv, vt8500->base + REG_PERIOD(pwm->hwpwm));
pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_PERIOD_UPDATE);
writel(dc, vt8500->base + REG_DUTY(pwm->hwpwm));
pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_DUTY_UPDATE);
val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));
val |= CTRL_AUTOLOAD;
writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);
clk_disable(vt8500->clk);
return 0;
}
static int vt8500_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
int err;
u32 val;
err = clk_enable(vt8500->clk);
if (err < 0) {
dev_err(chip->dev, "failed to enable clock\n");
return err;
}
val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));
val |= CTRL_ENABLE;
writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);
return 0;
}
static void vt8500_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
u32 val;
val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));
val &= ~CTRL_ENABLE;
writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);
clk_disable(vt8500->clk);
}
static int vt8500_pwm_set_polarity(struct pwm_chip *chip,
struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct vt8500_chip *vt8500 = to_vt8500_chip(chip);
u32 val;
val = readl(vt8500->base + REG_CTRL(pwm->hwpwm));
if (polarity == PWM_POLARITY_INVERSED)
val |= CTRL_INVERT;
else
val &= ~CTRL_INVERT;
writel(val, vt8500->base + REG_CTRL(pwm->hwpwm));
pwm_busy_wait(vt8500, pwm->hwpwm, STATUS_CTRL_UPDATE);
return 0;
}
static int vt8500_pwm_probe(struct platform_device *pdev)
{
struct vt8500_chip *chip;
struct resource *r;
struct device_node *np = pdev->dev.of_node;
int ret;
if (!np) {
dev_err(&pdev->dev, "invalid devicetree node\n");
return -EINVAL;
}
chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->chip.dev = &pdev->dev;
chip->chip.ops = &vt8500_pwm_ops;
chip->chip.of_xlate = of_pwm_xlate_with_flags;
chip->chip.of_pwm_n_cells = 3;
chip->chip.base = -1;
chip->chip.npwm = VT8500_NR_PWMS;
chip->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(chip->clk)) {
dev_err(&pdev->dev, "clock source not specified\n");
return PTR_ERR(chip->clk);
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
chip->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(chip->base))
return PTR_ERR(chip->base);
ret = clk_prepare(chip->clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to prepare clock\n");
return ret;
}
ret = pwmchip_add(&chip->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip\n");
return ret;
}
platform_set_drvdata(pdev, chip);
return ret;
}
static int vt8500_pwm_remove(struct platform_device *pdev)
{
struct vt8500_chip *chip;
chip = platform_get_drvdata(pdev);
if (chip == NULL)
return -ENODEV;
clk_unprepare(chip->clk);
return pwmchip_remove(&chip->chip);
}
