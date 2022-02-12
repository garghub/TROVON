static inline u32 brcmstb_pwm_readl(struct brcmstb_pwm *p,
unsigned int offset)
{
if (IS_ENABLED(CONFIG_MIPS) && IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
return __raw_readl(p->base + offset);
else
return readl_relaxed(p->base + offset);
}
static inline void brcmstb_pwm_writel(struct brcmstb_pwm *p, u32 value,
unsigned int offset)
{
if (IS_ENABLED(CONFIG_MIPS) && IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
__raw_writel(value, p->base + offset);
else
writel_relaxed(value, p->base + offset);
}
static inline struct brcmstb_pwm *to_brcmstb_pwm(struct pwm_chip *chip)
{
return container_of(chip, struct brcmstb_pwm, chip);
}
static int brcmstb_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct brcmstb_pwm *p = to_brcmstb_pwm(chip);
unsigned long pc, dc, cword = CONST_VAR_F_MAX;
unsigned int channel = pwm->hwpwm;
u32 value;
if (duty_ns == period_ns) {
dc = PWM_ON_PERIOD_MAX;
pc = PWM_ON_PERIOD_MAX - 1;
goto done;
}
while (1) {
u64 rate, tmp;
rate = (u64)clk_get_rate(p->clk) * (u64)cword;
do_div(rate, 1 << CWORD_BIT_SIZE);
tmp = period_ns * rate;
do_div(tmp, NSEC_PER_SEC);
pc = tmp;
tmp = (duty_ns + 1) * rate;
do_div(tmp, NSEC_PER_SEC);
dc = tmp;
if (pc == PWM_PERIOD_MIN || (dc < PWM_ON_MIN && duty_ns))
return -EINVAL;
if (pc <= PWM_ON_PERIOD_MAX && dc <= PWM_ON_PERIOD_MAX)
break;
cword >>= 1;
if (cword < CONST_VAR_F_MIN)
return -EINVAL;
}
done:
spin_lock(&p->lock);
brcmstb_pwm_writel(p, cword >> 8, PWM_CWORD_MSB(channel));
brcmstb_pwm_writel(p, cword & 0xff, PWM_CWORD_LSB(channel));
value = brcmstb_pwm_readl(p, PWM_CTRL2);
value |= CTRL2_OUT_SELECT << (channel * CTRL_CHAN_OFFS);
brcmstb_pwm_writel(p, value, PWM_CTRL2);
brcmstb_pwm_writel(p, pc, PWM_PERIOD(channel));
brcmstb_pwm_writel(p, dc, PWM_ON(channel));
spin_unlock(&p->lock);
return 0;
}
static inline void brcmstb_pwm_enable_set(struct brcmstb_pwm *p,
unsigned int channel, bool enable)
{
unsigned int shift = channel * CTRL_CHAN_OFFS;
u32 value;
spin_lock(&p->lock);
value = brcmstb_pwm_readl(p, PWM_CTRL);
if (enable) {
value &= ~(CTRL_OEB << shift);
value |= (CTRL_START | CTRL_OPENDRAIN) << shift;
} else {
value &= ~((CTRL_START | CTRL_OPENDRAIN) << shift);
value |= CTRL_OEB << shift;
}
brcmstb_pwm_writel(p, value, PWM_CTRL);
spin_unlock(&p->lock);
}
static int brcmstb_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct brcmstb_pwm *p = to_brcmstb_pwm(chip);
brcmstb_pwm_enable_set(p, pwm->hwpwm, true);
return 0;
}
static void brcmstb_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct brcmstb_pwm *p = to_brcmstb_pwm(chip);
brcmstb_pwm_enable_set(p, pwm->hwpwm, false);
}
static int brcmstb_pwm_probe(struct platform_device *pdev)
{
struct brcmstb_pwm *p;
struct resource *res;
int ret;
p = devm_kzalloc(&pdev->dev, sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
spin_lock_init(&p->lock);
p->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(p->clk)) {
dev_err(&pdev->dev, "failed to obtain clock\n");
return PTR_ERR(p->clk);
}
ret = clk_prepare_enable(p->clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable clock: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, p);
p->chip.dev = &pdev->dev;
p->chip.ops = &brcmstb_pwm_ops;
p->chip.base = -1;
p->chip.npwm = 2;
p->chip.can_sleep = true;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
p->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(p->base)) {
ret = PTR_ERR(p->base);
goto out_clk;
}
ret = pwmchip_add(&p->chip);
if (ret) {
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
goto out_clk;
}
return 0;
out_clk:
clk_disable_unprepare(p->clk);
return ret;
}
static int brcmstb_pwm_remove(struct platform_device *pdev)
{
struct brcmstb_pwm *p = platform_get_drvdata(pdev);
int ret;
ret = pwmchip_remove(&p->chip);
clk_disable_unprepare(p->clk);
return ret;
}
static int brcmstb_pwm_suspend(struct device *dev)
{
struct brcmstb_pwm *p = dev_get_drvdata(dev);
clk_disable(p->clk);
return 0;
}
static int brcmstb_pwm_resume(struct device *dev)
{
struct brcmstb_pwm *p = dev_get_drvdata(dev);
clk_enable(p->clk);
return 0;
}
