static inline struct twl_pwmled_chip *to_twl(struct pwm_chip *chip)
{
return container_of(chip, struct twl_pwmled_chip, chip);
}
static int twl4030_pwmled_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
int duty_cycle = DIV_ROUND_UP(duty_ns * TWL4030_LED_MAX, period_ns) + 1;
u8 pwm_config[2] = { 1, 0 };
int base, ret;
if (duty_cycle == 1)
duty_cycle = 2;
else if (duty_cycle > TWL4030_LED_MAX)
duty_cycle = 1;
base = pwm->hwpwm * 2 + TWL4030_PWMA_REG;
pwm_config[1] = duty_cycle;
ret = twl_i2c_write(TWL4030_MODULE_LED, pwm_config, base, 2);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to configure PWM\n", pwm->label);
return ret;
}
static int twl4030_pwmled_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwmled_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL4030_MODULE_LED, &val, TWL4030_LEDEN_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read LEDEN\n", pwm->label);
goto out;
}
val |= TWL4030_LED_TOGGLE(pwm->hwpwm, TWL4030_LED_PINS);
ret = twl_i2c_write_u8(TWL4030_MODULE_LED, val, TWL4030_LEDEN_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to enable PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
return ret;
}
static void twl4030_pwmled_disable(struct pwm_chip *chip,
struct pwm_device *pwm)
{
struct twl_pwmled_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL4030_MODULE_LED, &val, TWL4030_LEDEN_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read LEDEN\n", pwm->label);
goto out;
}
val &= ~TWL4030_LED_TOGGLE(pwm->hwpwm, TWL4030_LED_PINS);
ret = twl_i2c_write_u8(TWL4030_MODULE_LED, val, TWL4030_LEDEN_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to disable PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
}
static int twl6030_pwmled_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
int duty_cycle = (duty_ns * TWL6030_LED_MAX) / period_ns;
u8 on_time;
int ret;
on_time = duty_cycle & 0xff;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, on_time,
TWL6030_LED_PWM_CTRL1);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to configure PWM\n", pwm->label);
return ret;
}
static int twl6030_pwmled_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwmled_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, TWL6030_LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read PWM_CTRL2\n",
pwm->label);
goto out;
}
val &= ~TWL6040_LED_MODE_MASK;
val |= TWL6040_LED_MODE_ON;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, TWL6030_LED_PWM_CTRL2);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to enable PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
return ret;
}
static void twl6030_pwmled_disable(struct pwm_chip *chip,
struct pwm_device *pwm)
{
struct twl_pwmled_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, TWL6030_LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read PWM_CTRL2\n",
pwm->label);
goto out;
}
val &= ~TWL6040_LED_MODE_MASK;
val |= TWL6040_LED_MODE_OFF;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, TWL6030_LED_PWM_CTRL2);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to disable PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
}
static int twl6030_pwmled_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwmled_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, TWL6030_LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read PWM_CTRL2\n",
pwm->label);
goto out;
}
val &= ~TWL6040_LED_MODE_MASK;
val |= TWL6040_LED_MODE_OFF;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, TWL6030_LED_PWM_CTRL2);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to request PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
return ret;
}
static void twl6030_pwmled_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwmled_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, TWL6030_LED_PWM_CTRL2);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read PWM_CTRL2\n",
pwm->label);
goto out;
}
val &= ~TWL6040_LED_MODE_MASK;
val |= TWL6040_LED_MODE_HW;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, TWL6030_LED_PWM_CTRL2);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to free PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
}
static int twl_pwmled_probe(struct platform_device *pdev)
{
struct twl_pwmled_chip *twl;
int ret;
twl = devm_kzalloc(&pdev->dev, sizeof(*twl), GFP_KERNEL);
if (!twl)
return -ENOMEM;
if (twl_class_is_4030()) {
twl->chip.ops = &twl4030_pwmled_ops;
twl->chip.npwm = 2;
} else {
twl->chip.ops = &twl6030_pwmled_ops;
twl->chip.npwm = 1;
}
twl->chip.dev = &pdev->dev;
twl->chip.base = -1;
twl->chip.can_sleep = true;
mutex_init(&twl->mutex);
ret = pwmchip_add(&twl->chip);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, twl);
return 0;
}
static int twl_pwmled_remove(struct platform_device *pdev)
{
struct twl_pwmled_chip *twl = platform_get_drvdata(pdev);
return pwmchip_remove(&twl->chip);
}
