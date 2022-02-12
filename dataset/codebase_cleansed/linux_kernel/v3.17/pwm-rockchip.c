static inline struct rockchip_pwm_chip *to_rockchip_pwm_chip(struct pwm_chip *c)
{
return container_of(c, struct rockchip_pwm_chip, chip);
}
static void rockchip_pwm_set_enable_v1(struct pwm_chip *chip, bool enable)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
u32 enable_conf = PWM_CTRL_OUTPUT_EN | PWM_CTRL_TIMER_EN;
u32 val;
val = readl_relaxed(pc->base + pc->data->regs.ctrl);
if (enable)
val |= enable_conf;
else
val &= ~enable_conf;
writel_relaxed(val, pc->base + pc->data->regs.ctrl);
}
static void rockchip_pwm_set_enable_v2(struct pwm_chip *chip, bool enable)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
u32 enable_conf = PWM_OUTPUT_LEFT | PWM_LP_DISABLE | PWM_ENABLE |
PWM_CONTINUOUS | PWM_DUTY_POSITIVE |
PWM_INACTIVE_NEGATIVE;
u32 val;
val = readl_relaxed(pc->base + pc->data->regs.ctrl);
if (enable)
val |= enable_conf;
else
val &= ~enable_conf;
writel_relaxed(val, pc->base + pc->data->regs.ctrl);
}
static int rockchip_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
unsigned long period, duty;
u64 clk_rate, div;
int ret;
clk_rate = clk_get_rate(pc->clk);
div = clk_rate * period_ns;
do_div(div, pc->data->prescaler * NSEC_PER_SEC);
period = div;
div = clk_rate * duty_ns;
do_div(div, pc->data->prescaler * NSEC_PER_SEC);
duty = div;
ret = clk_enable(pc->clk);
if (ret)
return ret;
writel(period, pc->base + pc->data->regs.period);
writel(duty, pc->base + pc->data->regs.duty);
writel(0, pc->base + pc->data->regs.cntr);
clk_disable(pc->clk);
return 0;
}
static int rockchip_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
int ret;
ret = clk_enable(pc->clk);
if (ret)
return ret;
pc->data->set_enable(chip, true);
return 0;
}
static void rockchip_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
pc->data->set_enable(chip, false);
clk_disable(pc->clk);
}
static int rockchip_pwm_probe(struct platform_device *pdev)
{
const struct of_device_id *id;
struct rockchip_pwm_chip *pc;
struct resource *r;
int ret;
id = of_match_device(rockchip_pwm_dt_ids, &pdev->dev);
if (!id)
return -EINVAL;
pc = devm_kzalloc(&pdev->dev, sizeof(*pc), GFP_KERNEL);
if (!pc)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pc->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(pc->base))
return PTR_ERR(pc->base);
pc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pc->clk))
return PTR_ERR(pc->clk);
ret = clk_prepare(pc->clk);
if (ret)
return ret;
platform_set_drvdata(pdev, pc);
pc->data = id->data;
pc->chip.dev = &pdev->dev;
pc->chip.ops = &rockchip_pwm_ops;
pc->chip.base = -1;
pc->chip.npwm = 1;
ret = pwmchip_add(&pc->chip);
if (ret < 0) {
clk_unprepare(pc->clk);
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
}
return ret;
}
static int rockchip_pwm_remove(struct platform_device *pdev)
{
struct rockchip_pwm_chip *pc = platform_get_drvdata(pdev);
clk_unprepare(pc->clk);
return pwmchip_remove(&pc->chip);
}
