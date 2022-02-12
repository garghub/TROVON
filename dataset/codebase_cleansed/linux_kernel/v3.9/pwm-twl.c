static inline struct twl_pwm_chip *to_twl(struct pwm_chip *chip)
{
return container_of(chip, struct twl_pwm_chip, chip);
}
static int twl_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
int duty_cycle = DIV_ROUND_UP(duty_ns * TWL_PWM_MAX, period_ns) + 1;
u8 pwm_config[2] = { 1, 0 };
int base, ret;
if (duty_cycle == 1)
duty_cycle = 2;
else if (duty_cycle > TWL_PWM_MAX)
duty_cycle = 1;
base = pwm->hwpwm * 3;
pwm_config[1] = duty_cycle;
ret = twl_i2c_write(TWL_MODULE_PWM, pwm_config, base, 2);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to configure PWM\n", pwm->label);
return ret;
}
static int twl4030_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwm_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL4030_MODULE_INTBR, &val, TWL4030_GPBR1_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read GPBR1\n", pwm->label);
goto out;
}
val |= TWL4030_PWM_TOGGLE(pwm->hwpwm, TWL4030_PWMXCLK_ENABLE);
ret = twl_i2c_write_u8(TWL4030_MODULE_INTBR, val, TWL4030_GPBR1_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to enable PWM\n", pwm->label);
val |= TWL4030_PWM_TOGGLE(pwm->hwpwm, TWL4030_PWMX_ENABLE);
ret = twl_i2c_write_u8(TWL4030_MODULE_INTBR, val, TWL4030_GPBR1_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to enable PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
return ret;
}
static void twl4030_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwm_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL4030_MODULE_INTBR, &val, TWL4030_GPBR1_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read GPBR1\n", pwm->label);
goto out;
}
val &= ~TWL4030_PWM_TOGGLE(pwm->hwpwm, TWL4030_PWMX_ENABLE);
ret = twl_i2c_write_u8(TWL4030_MODULE_INTBR, val, TWL4030_GPBR1_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to disable PWM\n", pwm->label);
val &= ~TWL4030_PWM_TOGGLE(pwm->hwpwm, TWL4030_PWMXCLK_ENABLE);
ret = twl_i2c_write_u8(TWL4030_MODULE_INTBR, val, TWL4030_GPBR1_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to disable PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
}
static int twl4030_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwm_chip *twl = to_twl(chip);
int ret;
u8 val, mask, bits;
if (pwm->hwpwm == 1) {
mask = TWL4030_GPIO7_VIBRASYNC_PWM1_MASK;
bits = TWL4030_GPIO7_VIBRASYNC_PWM1_PWM1;
} else {
mask = TWL4030_GPIO6_PWM0_MUTE_MASK;
bits = TWL4030_GPIO6_PWM0_MUTE_PWM0;
}
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL4030_MODULE_INTBR, &val, TWL4030_PMBR1_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read PMBR1\n", pwm->label);
goto out;
}
twl->twl4030_pwm_mux &= ~mask;
twl->twl4030_pwm_mux |= (val & mask);
val &= ~mask;
val |= bits;
ret = twl_i2c_write_u8(TWL4030_MODULE_INTBR, val, TWL4030_PMBR1_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to request PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
return ret;
}
static void twl4030_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwm_chip *twl = to_twl(chip);
int ret;
u8 val, mask;
if (pwm->hwpwm == 1)
mask = TWL4030_GPIO7_VIBRASYNC_PWM1_MASK;
else
mask = TWL4030_GPIO6_PWM0_MUTE_MASK;
mutex_lock(&twl->mutex);
ret = twl_i2c_read_u8(TWL4030_MODULE_INTBR, &val, TWL4030_PMBR1_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read PMBR1\n", pwm->label);
goto out;
}
val &= ~mask;
val |= (twl->twl4030_pwm_mux & mask);
ret = twl_i2c_write_u8(TWL4030_MODULE_INTBR, val, TWL4030_PMBR1_REG);
if (ret < 0)
dev_err(chip->dev, "%s: Failed to free PWM\n", pwm->label);
out:
mutex_unlock(&twl->mutex);
}
static int twl6030_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwm_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
val = twl->twl6030_toggle3;
val |= TWL6030_PWM_TOGGLE(pwm->hwpwm, TWL6030_PWMXS | TWL6030_PWMXEN);
val &= ~TWL6030_PWM_TOGGLE(pwm->hwpwm, TWL6030_PWMXR);
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, TWL6030_TOGGLE3_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to enable PWM\n", pwm->label);
goto out;
}
twl->twl6030_toggle3 = val;
out:
mutex_unlock(&twl->mutex);
return 0;
}
static void twl6030_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct twl_pwm_chip *twl = to_twl(chip);
int ret;
u8 val;
mutex_lock(&twl->mutex);
val = twl->twl6030_toggle3;
val |= TWL6030_PWM_TOGGLE(pwm->hwpwm, TWL6030_PWMXR);
val &= ~TWL6030_PWM_TOGGLE(pwm->hwpwm, TWL6030_PWMXS | TWL6030_PWMXEN);
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, TWL6030_TOGGLE3_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to read TOGGLE3\n", pwm->label);
goto out;
}
val |= TWL6030_PWM_TOGGLE(pwm->hwpwm, TWL6030_PWMXS | TWL6030_PWMXEN);
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, TWL6030_TOGGLE3_REG);
if (ret < 0) {
dev_err(chip->dev, "%s: Failed to disable PWM\n", pwm->label);
goto out;
}
twl->twl6030_toggle3 = val;
out:
mutex_unlock(&twl->mutex);
}
static int twl_pwm_probe(struct platform_device *pdev)
{
struct twl_pwm_chip *twl;
int ret;
twl = devm_kzalloc(&pdev->dev, sizeof(*twl), GFP_KERNEL);
if (!twl)
return -ENOMEM;
if (twl_class_is_4030())
twl->chip.ops = &twl4030_pwm_ops;
else
twl->chip.ops = &twl6030_pwm_ops;
twl->chip.dev = &pdev->dev;
twl->chip.base = -1;
twl->chip.npwm = 2;
twl->chip.can_sleep = true;
mutex_init(&twl->mutex);
ret = pwmchip_add(&twl->chip);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, twl);
return 0;
}
static int twl_pwm_remove(struct platform_device *pdev)
{
struct twl_pwm_chip *twl = platform_get_drvdata(pdev);
return pwmchip_remove(&twl->chip);
}
