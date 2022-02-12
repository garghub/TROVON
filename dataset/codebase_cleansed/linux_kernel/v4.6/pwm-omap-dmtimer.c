static inline struct pwm_omap_dmtimer_chip *
to_pwm_omap_dmtimer_chip(struct pwm_chip *chip)
{
return container_of(chip, struct pwm_omap_dmtimer_chip, chip);
}
static u32 pwm_omap_dmtimer_get_clock_cycles(unsigned long clk_rate, int ns)
{
return DIV_ROUND_CLOSEST_ULL((u64)clk_rate * ns, NSEC_PER_SEC);
}
static void pwm_omap_dmtimer_start(struct pwm_omap_dmtimer_chip *omap)
{
omap->pdata->enable(omap->dm_timer);
omap->pdata->write_counter(omap->dm_timer, DM_TIMER_LOAD_MIN);
omap->pdata->disable(omap->dm_timer);
omap->pdata->start(omap->dm_timer);
}
static int pwm_omap_dmtimer_enable(struct pwm_chip *chip,
struct pwm_device *pwm)
{
struct pwm_omap_dmtimer_chip *omap = to_pwm_omap_dmtimer_chip(chip);
mutex_lock(&omap->mutex);
pwm_omap_dmtimer_start(omap);
mutex_unlock(&omap->mutex);
return 0;
}
static void pwm_omap_dmtimer_disable(struct pwm_chip *chip,
struct pwm_device *pwm)
{
struct pwm_omap_dmtimer_chip *omap = to_pwm_omap_dmtimer_chip(chip);
mutex_lock(&omap->mutex);
omap->pdata->stop(omap->dm_timer);
mutex_unlock(&omap->mutex);
}
static int pwm_omap_dmtimer_config(struct pwm_chip *chip,
struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct pwm_omap_dmtimer_chip *omap = to_pwm_omap_dmtimer_chip(chip);
u32 period_cycles, duty_cycles;
u32 load_value, match_value;
struct clk *fclk;
unsigned long clk_rate;
bool timer_active;
dev_dbg(chip->dev, "requested duty cycle: %d ns, period: %d ns\n",
duty_ns, period_ns);
mutex_lock(&omap->mutex);
if (duty_ns == pwm_get_duty_cycle(pwm) &&
period_ns == pwm_get_period(pwm)) {
mutex_unlock(&omap->mutex);
return 0;
}
fclk = omap->pdata->get_fclk(omap->dm_timer);
if (!fclk) {
dev_err(chip->dev, "invalid pmtimer fclk\n");
goto err_einval;
}
clk_rate = clk_get_rate(fclk);
if (!clk_rate) {
dev_err(chip->dev, "invalid pmtimer fclk rate\n");
goto err_einval;
}
dev_dbg(chip->dev, "clk rate: %luHz\n", clk_rate);
period_cycles = pwm_omap_dmtimer_get_clock_cycles(clk_rate, period_ns);
duty_cycles = pwm_omap_dmtimer_get_clock_cycles(clk_rate, duty_ns);
if (period_cycles < 2) {
dev_info(chip->dev,
"period %d ns too short for clock rate %lu Hz\n",
period_ns, clk_rate);
goto err_einval;
}
if (duty_cycles < 1) {
dev_dbg(chip->dev,
"duty cycle %d ns is too short for clock rate %lu Hz\n",
duty_ns, clk_rate);
dev_dbg(chip->dev, "using minimum of 1 clock cycle\n");
duty_cycles = 1;
} else if (duty_cycles >= period_cycles) {
dev_dbg(chip->dev,
"duty cycle %d ns is too long for period %d ns at clock rate %lu Hz\n",
duty_ns, period_ns, clk_rate);
dev_dbg(chip->dev, "using maximum of 1 clock cycle less than period\n");
duty_cycles = period_cycles - 1;
}
dev_dbg(chip->dev, "effective duty cycle: %lld ns, period: %lld ns\n",
DIV_ROUND_CLOSEST_ULL((u64)NSEC_PER_SEC * duty_cycles,
clk_rate),
DIV_ROUND_CLOSEST_ULL((u64)NSEC_PER_SEC * period_cycles,
clk_rate));
load_value = (DM_TIMER_MAX - period_cycles) + 1;
match_value = load_value + duty_cycles - 1;
timer_active = pm_runtime_active(&omap->dm_timer_pdev->dev);
if (timer_active)
omap->pdata->stop(omap->dm_timer);
omap->pdata->set_load(omap->dm_timer, true, load_value);
omap->pdata->set_match(omap->dm_timer, true, match_value);
dev_dbg(chip->dev, "load value: %#08x (%d), match value: %#08x (%d)\n",
load_value, load_value, match_value, match_value);
omap->pdata->set_pwm(omap->dm_timer,
pwm->polarity == PWM_POLARITY_INVERSED,
true,
PWM_OMAP_DMTIMER_TRIGGER_OVERFLOW_AND_COMPARE);
if (timer_active)
pwm_omap_dmtimer_start(omap);
mutex_unlock(&omap->mutex);
return 0;
err_einval:
mutex_unlock(&omap->mutex);
return -EINVAL;
}
static int pwm_omap_dmtimer_set_polarity(struct pwm_chip *chip,
struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct pwm_omap_dmtimer_chip *omap = to_pwm_omap_dmtimer_chip(chip);
mutex_lock(&omap->mutex);
omap->pdata->set_pwm(omap->dm_timer,
polarity == PWM_POLARITY_INVERSED,
true,
PWM_OMAP_DMTIMER_TRIGGER_OVERFLOW_AND_COMPARE);
mutex_unlock(&omap->mutex);
return 0;
}
static int pwm_omap_dmtimer_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *timer;
struct pwm_omap_dmtimer_chip *omap;
struct pwm_omap_dmtimer_pdata *pdata;
pwm_omap_dmtimer *dm_timer;
u32 prescaler;
int status;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "Missing dmtimer platform data\n");
return -EINVAL;
}
if (!pdata->request_by_node ||
!pdata->free ||
!pdata->enable ||
!pdata->disable ||
!pdata->get_fclk ||
!pdata->start ||
!pdata->stop ||
!pdata->set_load ||
!pdata->set_match ||
!pdata->set_pwm ||
!pdata->set_prescaler ||
!pdata->write_counter) {
dev_err(&pdev->dev, "Incomplete dmtimer pdata structure\n");
return -EINVAL;
}
timer = of_parse_phandle(np, "ti,timers", 0);
if (!timer)
return -ENODEV;
if (!of_get_property(timer, "ti,timer-pwm", NULL)) {
dev_err(&pdev->dev, "Missing ti,timer-pwm capability\n");
return -ENODEV;
}
dm_timer = pdata->request_by_node(timer);
if (!dm_timer)
return -EPROBE_DEFER;
omap = devm_kzalloc(&pdev->dev, sizeof(*omap), GFP_KERNEL);
if (!omap) {
pdata->free(dm_timer);
return -ENOMEM;
}
omap->pdata = pdata;
omap->dm_timer = dm_timer;
omap->dm_timer_pdev = of_find_device_by_node(timer);
if (!omap->dm_timer_pdev) {
dev_err(&pdev->dev, "Unable to find timer pdev\n");
omap->pdata->free(dm_timer);
return -EINVAL;
}
if (pm_runtime_active(&omap->dm_timer_pdev->dev))
omap->pdata->stop(omap->dm_timer);
if (!of_property_read_u32(pdev->dev.of_node, "ti,prescaler",
&prescaler))
omap->pdata->set_prescaler(omap->dm_timer, prescaler);
omap->chip.dev = &pdev->dev;
omap->chip.ops = &pwm_omap_dmtimer_ops;
omap->chip.base = -1;
omap->chip.npwm = 1;
omap->chip.of_xlate = of_pwm_xlate_with_flags;
omap->chip.of_pwm_n_cells = 3;
mutex_init(&omap->mutex);
status = pwmchip_add(&omap->chip);
if (status < 0) {
dev_err(&pdev->dev, "failed to register PWM\n");
omap->pdata->free(omap->dm_timer);
return status;
}
platform_set_drvdata(pdev, omap);
return 0;
}
static int pwm_omap_dmtimer_remove(struct platform_device *pdev)
{
struct pwm_omap_dmtimer_chip *omap = platform_get_drvdata(pdev);
if (pm_runtime_active(&omap->dm_timer_pdev->dev))
omap->pdata->stop(omap->dm_timer);
omap->pdata->free(omap->dm_timer);
mutex_destroy(&omap->mutex);
return pwmchip_remove(&omap->chip);
}
