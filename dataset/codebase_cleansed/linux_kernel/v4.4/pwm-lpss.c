static inline struct pwm_lpss_chip *to_lpwm(struct pwm_chip *chip)
{
return container_of(chip, struct pwm_lpss_chip, chip);
}
static inline u32 pwm_lpss_read(const struct pwm_device *pwm)
{
struct pwm_lpss_chip *lpwm = to_lpwm(pwm->chip);
return readl(lpwm->regs + pwm->hwpwm * PWM_SIZE + PWM);
}
static inline void pwm_lpss_write(const struct pwm_device *pwm, u32 value)
{
struct pwm_lpss_chip *lpwm = to_lpwm(pwm->chip);
writel(value, lpwm->regs + pwm->hwpwm * PWM_SIZE + PWM);
}
static int pwm_lpss_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
u8 on_time_div;
unsigned long c;
unsigned long long base_unit, freq = NSECS_PER_SEC;
u32 ctrl;
do_div(freq, period_ns);
base_unit = freq * 65536;
c = lpwm->clk_rate;
if (!c)
return -EINVAL;
do_div(base_unit, c);
base_unit += PWM_DIVISION_CORRECTION;
if (base_unit > PWM_LIMIT)
return -EINVAL;
if (duty_ns <= 0)
duty_ns = 1;
on_time_div = 255 - (255 * duty_ns / period_ns);
pm_runtime_get_sync(chip->dev);
ctrl = pwm_lpss_read(pwm);
ctrl &= ~(PWM_BASE_UNIT_MASK | PWM_ON_TIME_DIV_MASK);
ctrl |= (u16) base_unit << PWM_BASE_UNIT_SHIFT;
ctrl |= on_time_div;
ctrl |= PWM_SW_UPDATE;
pwm_lpss_write(pwm, ctrl);
pm_runtime_put(chip->dev);
return 0;
}
static int pwm_lpss_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
pm_runtime_get_sync(chip->dev);
pwm_lpss_write(pwm, pwm_lpss_read(pwm) | PWM_ENABLE);
return 0;
}
static void pwm_lpss_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
pwm_lpss_write(pwm, pwm_lpss_read(pwm) & ~PWM_ENABLE);
pm_runtime_put(chip->dev);
}
struct pwm_lpss_chip *pwm_lpss_probe(struct device *dev, struct resource *r,
const struct pwm_lpss_boardinfo *info)
{
struct pwm_lpss_chip *lpwm;
int ret;
lpwm = devm_kzalloc(dev, sizeof(*lpwm), GFP_KERNEL);
if (!lpwm)
return ERR_PTR(-ENOMEM);
lpwm->regs = devm_ioremap_resource(dev, r);
if (IS_ERR(lpwm->regs))
return ERR_CAST(lpwm->regs);
lpwm->clk_rate = info->clk_rate;
lpwm->chip.dev = dev;
lpwm->chip.ops = &pwm_lpss_ops;
lpwm->chip.base = -1;
lpwm->chip.npwm = info->npwm;
ret = pwmchip_add(&lpwm->chip);
if (ret) {
dev_err(dev, "failed to add PWM chip: %d\n", ret);
return ERR_PTR(ret);
}
return lpwm;
}
int pwm_lpss_remove(struct pwm_lpss_chip *lpwm)
{
return pwmchip_remove(&lpwm->chip);
}
