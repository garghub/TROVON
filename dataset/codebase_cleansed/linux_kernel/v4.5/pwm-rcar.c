static inline struct rcar_pwm_chip *to_rcar_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct rcar_pwm_chip, chip);
}
static void rcar_pwm_write(struct rcar_pwm_chip *rp, u32 data,
unsigned int offset)
{
writel(data, rp->base + offset);
}
static u32 rcar_pwm_read(struct rcar_pwm_chip *rp, unsigned int offset)
{
return readl(rp->base + offset);
}
static void rcar_pwm_update(struct rcar_pwm_chip *rp, u32 mask, u32 data,
unsigned int offset)
{
u32 value;
value = rcar_pwm_read(rp, offset);
value &= ~mask;
value |= data & mask;
rcar_pwm_write(rp, value, offset);
}
static int rcar_pwm_get_clock_division(struct rcar_pwm_chip *rp, int period_ns)
{
unsigned long clk_rate = clk_get_rate(rp->clk);
unsigned long long max;
unsigned int div;
if (clk_rate == 0)
return -EINVAL;
for (div = 0; div <= RCAR_PWM_MAX_DIVISION; div++) {
max = (unsigned long long)NSEC_PER_SEC * RCAR_PWM_MAX_CYCLE *
(1 << div);
do_div(max, clk_rate);
if (period_ns <= max)
break;
}
return (div <= RCAR_PWM_MAX_DIVISION) ? div : -ERANGE;
}
static void rcar_pwm_set_clock_control(struct rcar_pwm_chip *rp,
unsigned int div)
{
u32 value;
value = rcar_pwm_read(rp, RCAR_PWMCR);
value &= ~(RCAR_PWMCR_CCMD | RCAR_PWMCR_CC0_MASK);
if (div & 1)
value |= RCAR_PWMCR_CCMD;
div >>= 1;
value |= div << RCAR_PWMCR_CC0_SHIFT;
rcar_pwm_write(rp, value, RCAR_PWMCR);
}
static int rcar_pwm_set_counter(struct rcar_pwm_chip *rp, int div, int duty_ns,
int period_ns)
{
unsigned long long one_cycle, tmp;
unsigned long clk_rate = clk_get_rate(rp->clk);
u32 cyc, ph;
one_cycle = (unsigned long long)NSEC_PER_SEC * 100ULL * (1 << div);
do_div(one_cycle, clk_rate);
tmp = period_ns * 100ULL;
do_div(tmp, one_cycle);
cyc = (tmp << RCAR_PWMCNT_CYC0_SHIFT) & RCAR_PWMCNT_CYC0_MASK;
tmp = duty_ns * 100ULL;
do_div(tmp, one_cycle);
ph = tmp & RCAR_PWMCNT_PH0_MASK;
if (cyc == 0 || ph == 0)
return -EINVAL;
rcar_pwm_write(rp, cyc | ph, RCAR_PWMCNT);
return 0;
}
static int rcar_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct rcar_pwm_chip *rp = to_rcar_pwm_chip(chip);
return clk_prepare_enable(rp->clk);
}
static void rcar_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct rcar_pwm_chip *rp = to_rcar_pwm_chip(chip);
clk_disable_unprepare(rp->clk);
}
static int rcar_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct rcar_pwm_chip *rp = to_rcar_pwm_chip(chip);
int div, ret;
div = rcar_pwm_get_clock_division(rp, period_ns);
if (div < 0)
return div;
if (!test_bit(PWMF_ENABLED, &pwm->flags) && !duty_ns)
return 0;
rcar_pwm_update(rp, RCAR_PWMCR_SYNC, RCAR_PWMCR_SYNC, RCAR_PWMCR);
ret = rcar_pwm_set_counter(rp, div, duty_ns, period_ns);
if (!ret)
rcar_pwm_set_clock_control(rp, div);
rcar_pwm_update(rp, RCAR_PWMCR_SYNC, 0, RCAR_PWMCR);
return ret;
}
static int rcar_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct rcar_pwm_chip *rp = to_rcar_pwm_chip(chip);
u32 value;
value = rcar_pwm_read(rp, RCAR_PWMCNT);
if ((value & RCAR_PWMCNT_CYC0_MASK) == 0 ||
(value & RCAR_PWMCNT_PH0_MASK) == 0)
return -EINVAL;
rcar_pwm_update(rp, RCAR_PWMCR_EN0, RCAR_PWMCR_EN0, RCAR_PWMCR);
return 0;
}
static void rcar_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct rcar_pwm_chip *rp = to_rcar_pwm_chip(chip);
rcar_pwm_update(rp, RCAR_PWMCR_EN0, 0, RCAR_PWMCR);
}
static int rcar_pwm_probe(struct platform_device *pdev)
{
struct rcar_pwm_chip *rcar_pwm;
struct resource *res;
int ret;
rcar_pwm = devm_kzalloc(&pdev->dev, sizeof(*rcar_pwm), GFP_KERNEL);
if (rcar_pwm == NULL)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rcar_pwm->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rcar_pwm->base))
return PTR_ERR(rcar_pwm->base);
rcar_pwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(rcar_pwm->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
return PTR_ERR(rcar_pwm->clk);
}
platform_set_drvdata(pdev, rcar_pwm);
rcar_pwm->chip.dev = &pdev->dev;
rcar_pwm->chip.ops = &rcar_pwm_ops;
rcar_pwm->chip.base = -1;
rcar_pwm->chip.npwm = 1;
ret = pwmchip_add(&rcar_pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register PWM chip: %d\n", ret);
return ret;
}
pm_runtime_enable(&pdev->dev);
return 0;
}
static int rcar_pwm_remove(struct platform_device *pdev)
{
struct rcar_pwm_chip *rcar_pwm = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
return pwmchip_remove(&rcar_pwm->chip);
}
