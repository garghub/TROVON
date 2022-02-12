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
static int pwm_lpss_wait_for_update(struct pwm_device *pwm)
{
struct pwm_lpss_chip *lpwm = to_lpwm(pwm->chip);
const void __iomem *addr = lpwm->regs + pwm->hwpwm * PWM_SIZE + PWM;
const unsigned int ms = 500 * USEC_PER_MSEC;
u32 val;
int err;
err = readl_poll_timeout(addr, val, !(val & PWM_SW_UPDATE), 40, ms);
if (err)
dev_err(pwm->chip->dev, "PWM_SW_UPDATE was not cleared\n");
return err;
}
static inline int pwm_lpss_is_updating(struct pwm_device *pwm)
{
return (pwm_lpss_read(pwm) & PWM_SW_UPDATE) ? -EBUSY : 0;
}
static void pwm_lpss_prepare(struct pwm_lpss_chip *lpwm, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
unsigned long long on_time_div;
unsigned long c = lpwm->info->clk_rate, base_unit_range;
unsigned long long base_unit, freq = NSEC_PER_SEC;
u32 ctrl;
do_div(freq, period_ns);
base_unit_range = BIT(lpwm->info->base_unit_bits) - 1;
freq *= base_unit_range;
base_unit = DIV_ROUND_CLOSEST_ULL(freq, c);
on_time_div = 255ULL * duty_ns;
do_div(on_time_div, period_ns);
on_time_div = 255ULL - on_time_div;
ctrl = pwm_lpss_read(pwm);
ctrl &= ~PWM_ON_TIME_DIV_MASK;
ctrl &= ~(base_unit_range << PWM_BASE_UNIT_SHIFT);
base_unit &= base_unit_range;
ctrl |= (u32) base_unit << PWM_BASE_UNIT_SHIFT;
ctrl |= on_time_div;
pwm_lpss_write(pwm, ctrl);
}
static inline void pwm_lpss_cond_enable(struct pwm_device *pwm, bool cond)
{
if (cond)
pwm_lpss_write(pwm, pwm_lpss_read(pwm) | PWM_ENABLE);
}
static int pwm_lpss_apply(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
int ret;
if (state->enabled) {
if (!pwm_is_enabled(pwm)) {
pm_runtime_get_sync(chip->dev);
ret = pwm_lpss_is_updating(pwm);
if (ret) {
pm_runtime_put(chip->dev);
return ret;
}
pwm_lpss_prepare(lpwm, pwm, state->duty_cycle, state->period);
pwm_lpss_write(pwm, pwm_lpss_read(pwm) | PWM_SW_UPDATE);
pwm_lpss_cond_enable(pwm, lpwm->info->bypass == false);
ret = pwm_lpss_wait_for_update(pwm);
if (ret) {
pm_runtime_put(chip->dev);
return ret;
}
pwm_lpss_cond_enable(pwm, lpwm->info->bypass == true);
} else {
ret = pwm_lpss_is_updating(pwm);
if (ret)
return ret;
pwm_lpss_prepare(lpwm, pwm, state->duty_cycle, state->period);
pwm_lpss_write(pwm, pwm_lpss_read(pwm) | PWM_SW_UPDATE);
return pwm_lpss_wait_for_update(pwm);
}
} else if (pwm_is_enabled(pwm)) {
pwm_lpss_write(pwm, pwm_lpss_read(pwm) & ~PWM_ENABLE);
pm_runtime_put(chip->dev);
}
return 0;
}
struct pwm_lpss_chip *pwm_lpss_probe(struct device *dev, struct resource *r,
const struct pwm_lpss_boardinfo *info)
{
struct pwm_lpss_chip *lpwm;
unsigned long c;
int ret;
lpwm = devm_kzalloc(dev, sizeof(*lpwm), GFP_KERNEL);
if (!lpwm)
return ERR_PTR(-ENOMEM);
lpwm->regs = devm_ioremap_resource(dev, r);
if (IS_ERR(lpwm->regs))
return ERR_CAST(lpwm->regs);
lpwm->info = info;
c = lpwm->info->clk_rate;
if (!c)
return ERR_PTR(-EINVAL);
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
