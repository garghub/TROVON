static int bfin_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bfin_pwm *priv;
int ret;
if (pwm->hwpwm >= ARRAY_SIZE(pwm_to_gptimer_per))
return -EINVAL;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->pin = pwm_to_gptimer_per[pwm->hwpwm];
ret = peripheral_request(priv->pin, NULL);
if (ret) {
kfree(priv);
return ret;
}
pwm_set_chip_data(pwm, priv);
return 0;
}
static void bfin_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bfin_pwm *priv = pwm_get_chip_data(pwm);
if (priv) {
peripheral_free(priv->pin);
kfree(priv);
}
}
static int bfin_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct bfin_pwm *priv = pwm_get_chip_data(pwm);
unsigned long period, duty;
unsigned long long val;
if (duty_ns < 0 || duty_ns > period_ns)
return -EINVAL;
val = (unsigned long long)get_sclk() * period_ns;
do_div(val, NSEC_PER_SEC);
period = val;
val = (unsigned long long)period * duty_ns;
do_div(val, period_ns);
duty = period - val;
if (duty >= period)
duty = period - 1;
set_gptimer_config(priv->pin, TIMER_MODE_PWM | TIMER_PERIOD_CNT);
set_gptimer_pwidth(priv->pin, duty);
set_gptimer_period(priv->pin, period);
return 0;
}
static int bfin_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bfin_pwm *priv = pwm_get_chip_data(pwm);
enable_gptimer(priv->pin);
return 0;
}
static void bfin_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct bfin_pwm *priv = pwm_get_chip_data(pwm);
disable_gptimer(priv->pin);
}
static int bfin_pwm_probe(struct platform_device *pdev)
{
struct bfin_pwm_chip *pwm;
int ret;
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (!pwm) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, pwm);
pwm->chip.dev = &pdev->dev;
pwm->chip.ops = &bfin_pwm_ops;
pwm->chip.base = -1;
pwm->chip.npwm = 12;
ret = pwmchip_add(&pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
return ret;
}
return 0;
}
static int __devexit bfin_pwm_remove(struct platform_device *pdev)
{
struct bfin_pwm_chip *pwm = platform_get_drvdata(pdev);
return pwmchip_remove(&pwm->chip);
}
