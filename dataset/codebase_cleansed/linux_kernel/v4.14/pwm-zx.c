static inline struct zx_pwm_chip *to_zx_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct zx_pwm_chip, chip);
}
static inline u32 zx_pwm_readl(struct zx_pwm_chip *zpc, unsigned int hwpwm,
unsigned int offset)
{
return readl(zpc->base + (hwpwm + 1) * 0x10 + offset);
}
static inline void zx_pwm_writel(struct zx_pwm_chip *zpc, unsigned int hwpwm,
unsigned int offset, u32 value)
{
writel(value, zpc->base + (hwpwm + 1) * 0x10 + offset);
}
static void zx_pwm_set_mask(struct zx_pwm_chip *zpc, unsigned int hwpwm,
unsigned int offset, u32 mask, u32 value)
{
u32 data;
data = zx_pwm_readl(zpc, hwpwm, offset);
data &= ~mask;
data |= value & mask;
zx_pwm_writel(zpc, hwpwm, offset, data);
}
static void zx_pwm_get_state(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct zx_pwm_chip *zpc = to_zx_pwm_chip(chip);
unsigned long rate;
unsigned int div;
u32 value;
u64 tmp;
value = zx_pwm_readl(zpc, pwm->hwpwm, ZX_PWM_MODE);
if (value & ZX_PWM_POLAR)
state->polarity = PWM_POLARITY_NORMAL;
else
state->polarity = PWM_POLARITY_INVERSED;
if (value & ZX_PWM_EN)
state->enabled = true;
else
state->enabled = false;
div = (value & ZX_PWM_CLKDIV_MASK) >> ZX_PWM_CLKDIV_SHIFT;
rate = clk_get_rate(zpc->wclk);
tmp = zx_pwm_readl(zpc, pwm->hwpwm, ZX_PWM_PERIOD);
tmp *= div * NSEC_PER_SEC;
state->period = DIV_ROUND_CLOSEST_ULL(tmp, rate);
tmp = zx_pwm_readl(zpc, pwm->hwpwm, ZX_PWM_DUTY);
tmp *= div * NSEC_PER_SEC;
state->duty_cycle = DIV_ROUND_CLOSEST_ULL(tmp, rate);
}
static int zx_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
unsigned int duty_ns, unsigned int period_ns)
{
struct zx_pwm_chip *zpc = to_zx_pwm_chip(chip);
unsigned int period_cycles, duty_cycles;
unsigned long long c;
unsigned int div = 1;
unsigned long rate;
rate = clk_get_rate(zpc->wclk);
while (1) {
c = rate / div;
c = c * period_ns;
do_div(c, NSEC_PER_SEC);
if (c < ZX_PWM_PERIOD_MAX)
break;
div++;
if (div > ZX_PWM_CLKDIV_MAX)
return -ERANGE;
}
period_cycles = c;
c *= duty_ns;
do_div(c, period_ns);
duty_cycles = c;
if (pwm_is_enabled(pwm))
zx_pwm_set_mask(zpc, pwm->hwpwm, ZX_PWM_MODE, ZX_PWM_EN, 0);
zx_pwm_set_mask(zpc, pwm->hwpwm, ZX_PWM_MODE, ZX_PWM_CLKDIV_MASK,
ZX_PWM_CLKDIV(div));
zx_pwm_writel(zpc, pwm->hwpwm, ZX_PWM_PERIOD, period_cycles);
zx_pwm_writel(zpc, pwm->hwpwm, ZX_PWM_DUTY, duty_cycles);
if (pwm_is_enabled(pwm))
zx_pwm_set_mask(zpc, pwm->hwpwm, ZX_PWM_MODE,
ZX_PWM_EN, ZX_PWM_EN);
return 0;
}
static int zx_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct zx_pwm_chip *zpc = to_zx_pwm_chip(chip);
struct pwm_state cstate;
int ret;
pwm_get_state(pwm, &cstate);
if (state->polarity != cstate.polarity)
zx_pwm_set_mask(zpc, pwm->hwpwm, ZX_PWM_MODE, ZX_PWM_POLAR,
(state->polarity == PWM_POLARITY_INVERSED) ?
0 : ZX_PWM_POLAR);
if (state->period != cstate.period ||
state->duty_cycle != cstate.duty_cycle) {
ret = zx_pwm_config(chip, pwm, state->duty_cycle,
state->period);
if (ret)
return ret;
}
if (state->enabled != cstate.enabled) {
if (state->enabled) {
ret = clk_prepare_enable(zpc->wclk);
if (ret)
return ret;
zx_pwm_set_mask(zpc, pwm->hwpwm, ZX_PWM_MODE,
ZX_PWM_EN, ZX_PWM_EN);
} else {
zx_pwm_set_mask(zpc, pwm->hwpwm, ZX_PWM_MODE,
ZX_PWM_EN, 0);
clk_disable_unprepare(zpc->wclk);
}
}
return 0;
}
static int zx_pwm_probe(struct platform_device *pdev)
{
struct zx_pwm_chip *zpc;
struct resource *res;
unsigned int i;
int ret;
zpc = devm_kzalloc(&pdev->dev, sizeof(*zpc), GFP_KERNEL);
if (!zpc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
zpc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(zpc->base))
return PTR_ERR(zpc->base);
zpc->pclk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(zpc->pclk))
return PTR_ERR(zpc->pclk);
zpc->wclk = devm_clk_get(&pdev->dev, "wclk");
if (IS_ERR(zpc->wclk))
return PTR_ERR(zpc->wclk);
ret = clk_prepare_enable(zpc->pclk);
if (ret)
return ret;
zpc->chip.dev = &pdev->dev;
zpc->chip.ops = &zx_pwm_ops;
zpc->chip.base = -1;
zpc->chip.npwm = 4;
zpc->chip.of_xlate = of_pwm_xlate_with_flags;
zpc->chip.of_pwm_n_cells = 3;
for (i = 0; i < zpc->chip.npwm; i++)
zx_pwm_set_mask(zpc, i, ZX_PWM_MODE, ZX_PWM_EN, 0);
ret = pwmchip_add(&zpc->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, zpc);
return 0;
}
static int zx_pwm_remove(struct platform_device *pdev)
{
struct zx_pwm_chip *zpc = platform_get_drvdata(pdev);
int ret;
ret = pwmchip_remove(&zpc->chip);
clk_disable_unprepare(zpc->pclk);
return ret;
}
