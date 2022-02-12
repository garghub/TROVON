static int twl6030_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
int ret;
u8 val;
val = PWM_CTRL2_DIS_PD | PWM_CTRL2_CURR_02 | PWM_CTRL2_SRC_VAC |
PWM_CTRL2_MODE_HW;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to configure PWM, Error %d\n",
pwm->label, ret);
return ret;
}
return 0;
}
static int twl6030_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
u8 duty_cycle = (duty_ns * PWM_CTRL1_MAX) / period_ns;
int ret;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, duty_cycle, LED_PWM_CTRL1);
if (ret < 0) {
pr_err("%s: Failed to configure PWM, Error %d\n",
pwm->label, ret);
return ret;
}
return 0;
}
static int twl6030_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
int ret;
u8 val;
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to enable PWM, Error %d\n",
pwm->label, ret);
return ret;
}
val &= ~PWM_CTRL2_MODE_MASK;
val |= PWM_CTRL2_MODE_SW;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to enable PWM, Error %d\n",
pwm->label, ret);
return ret;
}
twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, LED_PWM_CTRL2);
return 0;
}
static void twl6030_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
int ret;
u8 val;
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to disable PWM, Error %d\n",
pwm->label, ret);
return;
}
val &= ~PWM_CTRL2_MODE_MASK;
val |= PWM_CTRL2_MODE_HW;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to disable PWM, Error %d\n",
pwm->label, ret);
}
}
static int twl6030_pwm_probe(struct platform_device *pdev)
{
struct twl6030_pwm_chip *twl6030;
int ret;
twl6030 = devm_kzalloc(&pdev->dev, sizeof(*twl6030), GFP_KERNEL);
if (!twl6030)
return -ENOMEM;
twl6030->chip.dev = &pdev->dev;
twl6030->chip.ops = &twl6030_pwm_ops;
twl6030->chip.base = -1;
twl6030->chip.npwm = 1;
ret = pwmchip_add(&twl6030->chip);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, twl6030);
return 0;
}
static int twl6030_pwm_remove(struct platform_device *pdev)
{
struct twl6030_pwm_chip *twl6030 = platform_get_drvdata(pdev);
return pwmchip_remove(&twl6030->chip);
}
