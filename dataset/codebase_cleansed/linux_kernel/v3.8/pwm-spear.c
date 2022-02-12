static inline struct spear_pwm_chip *to_spear_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct spear_pwm_chip, chip);
}
static inline u32 spear_pwm_readl(struct spear_pwm_chip *chip, unsigned int num,
unsigned long offset)
{
return readl_relaxed(chip->mmio_base + (num << 4) + offset);
}
static inline void spear_pwm_writel(struct spear_pwm_chip *chip,
unsigned int num, unsigned long offset,
unsigned long val)
{
writel_relaxed(val, chip->mmio_base + (num << 4) + offset);
}
static int spear_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct spear_pwm_chip *pc = to_spear_pwm_chip(chip);
u64 val, div, clk_rate;
unsigned long prescale = PWMCR_MIN_PRESCALE, pv, dc;
int ret;
clk_rate = clk_get_rate(pc->clk);
while (1) {
div = 1000000000;
div *= 1 + prescale;
val = clk_rate * period_ns;
pv = div64_u64(val, div);
val = clk_rate * duty_ns;
dc = div64_u64(val, div);
if (pv < PWMPCR_MIN_PERIOD || dc < PWMDCR_MIN_DUTY)
return -EINVAL;
if (pv > PWMPCR_MAX_PERIOD || dc > PWMDCR_MAX_DUTY) {
if (++prescale > PWMCR_MAX_PRESCALE)
return -EINVAL;
continue;
}
break;
}
ret = clk_enable(pc->clk);
if (ret)
return ret;
spear_pwm_writel(pc, pwm->hwpwm, PWMCR,
prescale << PWMCR_PRESCALE_SHIFT);
spear_pwm_writel(pc, pwm->hwpwm, PWMDCR, dc);
spear_pwm_writel(pc, pwm->hwpwm, PWMPCR, pv);
clk_disable(pc->clk);
return 0;
}
static int spear_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct spear_pwm_chip *pc = to_spear_pwm_chip(chip);
int rc = 0;
u32 val;
rc = clk_enable(pc->clk);
if (!rc)
return rc;
val = spear_pwm_readl(pc, pwm->hwpwm, PWMCR);
val |= PWMCR_PWM_ENABLE;
spear_pwm_writel(pc, pwm->hwpwm, PWMCR, val);
return 0;
}
static void spear_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct spear_pwm_chip *pc = to_spear_pwm_chip(chip);
u32 val;
val = spear_pwm_readl(pc, pwm->hwpwm, PWMCR);
val &= ~PWMCR_PWM_ENABLE;
spear_pwm_writel(pc, pwm->hwpwm, PWMCR, val);
clk_disable(pc->clk);
}
static int spear_pwm_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct spear_pwm_chip *pc;
struct resource *r;
int ret;
u32 val;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no memory resources defined\n");
return -ENODEV;
}
pc = devm_kzalloc(&pdev->dev, sizeof(*pc), GFP_KERNEL);
if (!pc) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
pc->mmio_base = devm_request_and_ioremap(&pdev->dev, r);
if (!pc->mmio_base)
return -EADDRNOTAVAIL;
pc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pc->clk))
return PTR_ERR(pc->clk);
pc->dev = &pdev->dev;
platform_set_drvdata(pdev, pc);
pc->chip.dev = &pdev->dev;
pc->chip.ops = &spear_pwm_ops;
pc->chip.base = -1;
pc->chip.npwm = NUM_PWM;
ret = clk_prepare(pc->clk);
if (!ret)
return ret;
if (of_device_is_compatible(np, "st,spear1340-pwm")) {
ret = clk_enable(pc->clk);
if (!ret) {
clk_unprepare(pc->clk);
return ret;
}
val = readl_relaxed(pc->mmio_base + PWMMCR);
val |= PWMMCR_PWM_ENABLE;
writel_relaxed(val, pc->mmio_base + PWMMCR);
clk_disable(pc->clk);
}
ret = pwmchip_add(&pc->chip);
if (!ret) {
clk_unprepare(pc->clk);
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
}
return ret;
}
static int spear_pwm_remove(struct platform_device *pdev)
{
struct spear_pwm_chip *pc = platform_get_drvdata(pdev);
int i;
for (i = 0; i < NUM_PWM; i++)
pwm_disable(&pc->chip.pwms[i]);
clk_unprepare(pc->clk);
return pwmchip_remove(&pc->chip);
}
