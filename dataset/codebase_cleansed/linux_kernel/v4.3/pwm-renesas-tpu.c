static void tpu_pwm_write(struct tpu_pwm_device *pwm, int reg_nr, u16 value)
{
void __iomem *base = pwm->tpu->base + TPU_CHANNEL_OFFSET
+ pwm->channel * TPU_CHANNEL_SIZE;
iowrite16(value, base + reg_nr);
}
static void tpu_pwm_set_pin(struct tpu_pwm_device *pwm,
enum tpu_pin_state state)
{
static const char * const states[] = { "inactive", "PWM", "active" };
dev_dbg(&pwm->tpu->pdev->dev, "%u: configuring pin as %s\n",
pwm->channel, states[state]);
switch (state) {
case TPU_PIN_INACTIVE:
tpu_pwm_write(pwm, TPU_TIORn,
pwm->polarity == PWM_POLARITY_INVERSED ?
TPU_TIOR_IOA_1 : TPU_TIOR_IOA_0);
break;
case TPU_PIN_PWM:
tpu_pwm_write(pwm, TPU_TIORn,
pwm->polarity == PWM_POLARITY_INVERSED ?
TPU_TIOR_IOA_0_SET : TPU_TIOR_IOA_1_CLR);
break;
case TPU_PIN_ACTIVE:
tpu_pwm_write(pwm, TPU_TIORn,
pwm->polarity == PWM_POLARITY_INVERSED ?
TPU_TIOR_IOA_0 : TPU_TIOR_IOA_1);
break;
}
}
static void tpu_pwm_start_stop(struct tpu_pwm_device *pwm, int start)
{
unsigned long flags;
u16 value;
spin_lock_irqsave(&pwm->tpu->lock, flags);
value = ioread16(pwm->tpu->base + TPU_TSTR);
if (start)
value |= 1 << pwm->channel;
else
value &= ~(1 << pwm->channel);
iowrite16(value, pwm->tpu->base + TPU_TSTR);
spin_unlock_irqrestore(&pwm->tpu->lock, flags);
}
static int tpu_pwm_timer_start(struct tpu_pwm_device *pwm)
{
int ret;
if (!pwm->timer_on) {
pm_runtime_get_sync(&pwm->tpu->pdev->dev);
ret = clk_prepare_enable(pwm->tpu->clk);
if (ret) {
dev_err(&pwm->tpu->pdev->dev, "cannot enable clock\n");
return ret;
}
pwm->timer_on = true;
}
tpu_pwm_set_pin(pwm, TPU_PIN_INACTIVE);
tpu_pwm_start_stop(pwm, false);
tpu_pwm_write(pwm, TPU_TCRn, TPU_TCR_CCLR_TGRB | TPU_TCR_CKEG_RISING |
pwm->prescaler);
tpu_pwm_write(pwm, TPU_TMDRn, TPU_TMDR_MD_PWM);
tpu_pwm_set_pin(pwm, TPU_PIN_PWM);
tpu_pwm_write(pwm, TPU_TGRAn, pwm->duty);
tpu_pwm_write(pwm, TPU_TGRBn, pwm->period);
dev_dbg(&pwm->tpu->pdev->dev, "%u: TGRA 0x%04x TGRB 0x%04x\n",
pwm->channel, pwm->duty, pwm->period);
tpu_pwm_start_stop(pwm, true);
return 0;
}
static void tpu_pwm_timer_stop(struct tpu_pwm_device *pwm)
{
if (!pwm->timer_on)
return;
tpu_pwm_start_stop(pwm, false);
clk_disable_unprepare(pwm->tpu->clk);
pm_runtime_put(&pwm->tpu->pdev->dev);
pwm->timer_on = false;
}
static int tpu_pwm_request(struct pwm_chip *chip, struct pwm_device *_pwm)
{
struct tpu_device *tpu = to_tpu_device(chip);
struct tpu_pwm_device *pwm;
if (_pwm->hwpwm >= TPU_CHANNEL_MAX)
return -EINVAL;
pwm = kzalloc(sizeof(*pwm), GFP_KERNEL);
if (pwm == NULL)
return -ENOMEM;
pwm->tpu = tpu;
pwm->channel = _pwm->hwpwm;
pwm->polarity = PWM_POLARITY_NORMAL;
pwm->prescaler = 0;
pwm->period = 0;
pwm->duty = 0;
pwm->timer_on = false;
pwm_set_chip_data(_pwm, pwm);
return 0;
}
static void tpu_pwm_free(struct pwm_chip *chip, struct pwm_device *_pwm)
{
struct tpu_pwm_device *pwm = pwm_get_chip_data(_pwm);
tpu_pwm_timer_stop(pwm);
kfree(pwm);
}
static int tpu_pwm_config(struct pwm_chip *chip, struct pwm_device *_pwm,
int duty_ns, int period_ns)
{
static const unsigned int prescalers[] = { 1, 4, 16, 64 };
struct tpu_pwm_device *pwm = pwm_get_chip_data(_pwm);
struct tpu_device *tpu = to_tpu_device(chip);
unsigned int prescaler;
bool duty_only = false;
u32 clk_rate;
u32 period;
u32 duty;
int ret;
clk_rate = clk_get_rate(tpu->clk);
for (prescaler = 0; prescaler < ARRAY_SIZE(prescalers); ++prescaler) {
period = clk_rate / prescalers[prescaler]
/ (NSEC_PER_SEC / period_ns);
if (period <= 0xffff)
break;
}
if (prescaler == ARRAY_SIZE(prescalers) || period == 0) {
dev_err(&tpu->pdev->dev, "clock rate mismatch\n");
return -ENOTSUPP;
}
if (duty_ns) {
duty = clk_rate / prescalers[prescaler]
/ (NSEC_PER_SEC / duty_ns);
if (duty > period)
return -EINVAL;
} else {
duty = 0;
}
dev_dbg(&tpu->pdev->dev,
"rate %u, prescaler %u, period %u, duty %u\n",
clk_rate, prescalers[prescaler], period, duty);
if (pwm->prescaler == prescaler && pwm->period == period)
duty_only = true;
pwm->prescaler = prescaler;
pwm->period = period;
pwm->duty = duty;
if (!pwm_is_enabled(_pwm))
return 0;
if (duty_only && pwm->timer_on) {
tpu_pwm_write(pwm, TPU_TGRAn, pwm->duty);
dev_dbg(&tpu->pdev->dev, "%u: TGRA 0x%04x\n", pwm->channel,
pwm->duty);
} else {
ret = tpu_pwm_timer_start(pwm);
if (ret < 0)
return ret;
}
if (duty == 0 || duty == period) {
tpu_pwm_set_pin(pwm, duty ? TPU_PIN_ACTIVE : TPU_PIN_INACTIVE);
tpu_pwm_timer_stop(pwm);
}
return 0;
}
static int tpu_pwm_set_polarity(struct pwm_chip *chip, struct pwm_device *_pwm,
enum pwm_polarity polarity)
{
struct tpu_pwm_device *pwm = pwm_get_chip_data(_pwm);
pwm->polarity = polarity;
return 0;
}
static int tpu_pwm_enable(struct pwm_chip *chip, struct pwm_device *_pwm)
{
struct tpu_pwm_device *pwm = pwm_get_chip_data(_pwm);
int ret;
ret = tpu_pwm_timer_start(pwm);
if (ret < 0)
return ret;
if (pwm->duty == 0 || pwm->duty == pwm->period) {
tpu_pwm_set_pin(pwm, pwm->duty ?
TPU_PIN_ACTIVE : TPU_PIN_INACTIVE);
tpu_pwm_timer_stop(pwm);
}
return 0;
}
static void tpu_pwm_disable(struct pwm_chip *chip, struct pwm_device *_pwm)
{
struct tpu_pwm_device *pwm = pwm_get_chip_data(_pwm);
tpu_pwm_timer_start(pwm);
tpu_pwm_set_pin(pwm, TPU_PIN_INACTIVE);
tpu_pwm_timer_stop(pwm);
}
static int tpu_probe(struct platform_device *pdev)
{
struct tpu_device *tpu;
struct resource *res;
int ret;
tpu = devm_kzalloc(&pdev->dev, sizeof(*tpu), GFP_KERNEL);
if (tpu == NULL)
return -ENOMEM;
spin_lock_init(&tpu->lock);
tpu->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tpu->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tpu->base))
return PTR_ERR(tpu->base);
tpu->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(tpu->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
return PTR_ERR(tpu->clk);
}
platform_set_drvdata(pdev, tpu);
tpu->chip.dev = &pdev->dev;
tpu->chip.ops = &tpu_pwm_ops;
tpu->chip.of_xlate = of_pwm_xlate_with_flags;
tpu->chip.of_pwm_n_cells = 3;
tpu->chip.base = -1;
tpu->chip.npwm = TPU_CHANNEL_MAX;
ret = pwmchip_add(&tpu->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register PWM chip\n");
return ret;
}
dev_info(&pdev->dev, "TPU PWM %d registered\n", tpu->pdev->id);
pm_runtime_enable(&pdev->dev);
return 0;
}
static int tpu_remove(struct platform_device *pdev)
{
struct tpu_device *tpu = platform_get_drvdata(pdev);
int ret;
ret = pwmchip_remove(&tpu->chip);
if (ret)
return ret;
pm_runtime_disable(&pdev->dev);
return 0;
}
