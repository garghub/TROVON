static inline struct rockchip_pwm_chip *to_rockchip_pwm_chip(struct pwm_chip *c)
{
return container_of(c, struct rockchip_pwm_chip, chip);
}
static void rockchip_pwm_get_state(struct pwm_chip *chip,
struct pwm_device *pwm,
struct pwm_state *state)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
u32 enable_conf = pc->data->enable_conf;
unsigned long clk_rate;
u64 tmp;
u32 val;
int ret;
ret = clk_enable(pc->pclk);
if (ret)
return;
clk_rate = clk_get_rate(pc->clk);
tmp = readl_relaxed(pc->base + pc->data->regs.period);
tmp *= pc->data->prescaler * NSEC_PER_SEC;
state->period = DIV_ROUND_CLOSEST_ULL(tmp, clk_rate);
tmp = readl_relaxed(pc->base + pc->data->regs.duty);
tmp *= pc->data->prescaler * NSEC_PER_SEC;
state->duty_cycle = DIV_ROUND_CLOSEST_ULL(tmp, clk_rate);
val = readl_relaxed(pc->base + pc->data->regs.ctrl);
if (pc->data->supports_polarity)
state->enabled = ((val & enable_conf) != enable_conf) ?
false : true;
else
state->enabled = ((val & enable_conf) == enable_conf) ?
true : false;
if (pc->data->supports_polarity) {
if (!(val & PWM_DUTY_POSITIVE))
state->polarity = PWM_POLARITY_INVERSED;
}
clk_disable(pc->pclk);
}
static void rockchip_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
unsigned long period, duty;
u64 clk_rate, div;
u32 ctrl;
clk_rate = clk_get_rate(pc->clk);
div = clk_rate * state->period;
period = DIV_ROUND_CLOSEST_ULL(div,
pc->data->prescaler * NSEC_PER_SEC);
div = clk_rate * state->duty_cycle;
duty = DIV_ROUND_CLOSEST_ULL(div, pc->data->prescaler * NSEC_PER_SEC);
ctrl = readl_relaxed(pc->base + pc->data->regs.ctrl);
if (pc->data->supports_lock) {
ctrl |= PWM_LOCK_EN;
writel_relaxed(ctrl, pc->base + pc->data->regs.ctrl);
}
writel(period, pc->base + pc->data->regs.period);
writel(duty, pc->base + pc->data->regs.duty);
if (pc->data->supports_polarity) {
ctrl &= ~PWM_POLARITY_MASK;
if (state->polarity == PWM_POLARITY_INVERSED)
ctrl |= PWM_DUTY_NEGATIVE | PWM_INACTIVE_POSITIVE;
else
ctrl |= PWM_DUTY_POSITIVE | PWM_INACTIVE_NEGATIVE;
}
if (pc->data->supports_lock)
ctrl &= ~PWM_LOCK_EN;
writel(ctrl, pc->base + pc->data->regs.ctrl);
}
static int rockchip_pwm_enable(struct pwm_chip *chip,
struct pwm_device *pwm,
bool enable)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
u32 enable_conf = pc->data->enable_conf;
int ret;
u32 val;
if (enable) {
ret = clk_enable(pc->clk);
if (ret)
return ret;
}
val = readl_relaxed(pc->base + pc->data->regs.ctrl);
if (enable)
val |= enable_conf;
else
val &= ~enable_conf;
writel_relaxed(val, pc->base + pc->data->regs.ctrl);
if (!enable)
clk_disable(pc->clk);
return 0;
}
static int rockchip_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct rockchip_pwm_chip *pc = to_rockchip_pwm_chip(chip);
struct pwm_state curstate;
bool enabled;
int ret = 0;
ret = clk_enable(pc->pclk);
if (ret)
return ret;
pwm_get_state(pwm, &curstate);
enabled = curstate.enabled;
if (state->polarity != curstate.polarity && enabled &&
!pc->data->supports_lock) {
ret = rockchip_pwm_enable(chip, pwm, false);
if (ret)
goto out;
enabled = false;
}
rockchip_pwm_config(chip, pwm, state);
if (state->enabled != enabled) {
ret = rockchip_pwm_enable(chip, pwm, state->enabled);
if (ret)
goto out;
}
rockchip_pwm_get_state(chip, pwm, state);
out:
clk_disable(pc->pclk);
return ret;
}
static int rockchip_pwm_probe(struct platform_device *pdev)
{
const struct of_device_id *id;
struct rockchip_pwm_chip *pc;
struct resource *r;
int ret, count;
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
pc->clk = devm_clk_get(&pdev->dev, "pwm");
if (IS_ERR(pc->clk)) {
pc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pc->clk)) {
ret = PTR_ERR(pc->clk);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Can't get bus clk: %d\n",
ret);
return ret;
}
}
count = of_count_phandle_with_args(pdev->dev.of_node,
"clocks", "#clock-cells");
if (count == 2)
pc->pclk = devm_clk_get(&pdev->dev, "pclk");
else
pc->pclk = pc->clk;
if (IS_ERR(pc->pclk)) {
ret = PTR_ERR(pc->pclk);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Can't get APB clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(pc->clk);
if (ret) {
dev_err(&pdev->dev, "Can't prepare enable bus clk: %d\n", ret);
return ret;
}
ret = clk_prepare(pc->pclk);
if (ret) {
dev_err(&pdev->dev, "Can't prepare APB clk: %d\n", ret);
goto err_clk;
}
platform_set_drvdata(pdev, pc);
pc->data = id->data;
pc->chip.dev = &pdev->dev;
pc->chip.ops = &rockchip_pwm_ops;
pc->chip.base = -1;
pc->chip.npwm = 1;
if (pc->data->supports_polarity) {
pc->chip.of_xlate = of_pwm_xlate_with_flags;
pc->chip.of_pwm_n_cells = 3;
}
ret = pwmchip_add(&pc->chip);
if (ret < 0) {
clk_unprepare(pc->clk);
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
goto err_pclk;
}
if (!pwm_is_enabled(pc->chip.pwms))
clk_disable(pc->clk);
return 0;
err_pclk:
clk_unprepare(pc->pclk);
err_clk:
clk_disable_unprepare(pc->clk);
return ret;
}
static int rockchip_pwm_remove(struct platform_device *pdev)
{
struct rockchip_pwm_chip *pc = platform_get_drvdata(pdev);
if (pwm_is_enabled(pc->chip.pwms))
clk_disable(pc->clk);
clk_unprepare(pc->pclk);
clk_unprepare(pc->clk);
return pwmchip_remove(&pc->chip);
}
