int pwm_config(struct pwm_device *pwm, int duty_ns, int period_ns)
{
u8 duty_cycle;
int ret;
if (pwm == NULL || period_ns == 0 || duty_ns > period_ns)
return -EINVAL;
duty_cycle = (duty_ns * PWM_CTRL1_MAX) / period_ns;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, duty_cycle, LED_PWM_CTRL1);
if (ret < 0) {
pr_err("%s: Failed to configure PWM, Error %d\n",
pwm->label, ret);
return ret;
}
return 0;
}
int pwm_enable(struct pwm_device *pwm)
{
u8 val;
int ret;
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, LED_PWM_CTRL2);
if (ret < 0) {
pr_err("%s: Failed to enable PWM, Error %d\n", pwm->label, ret);
return ret;
}
val &= ~PWM_CTRL2_MODE_MASK;
val |= PWM_CTRL2_MODE_SW;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, LED_PWM_CTRL2);
if (ret < 0) {
pr_err("%s: Failed to enable PWM, Error %d\n", pwm->label, ret);
return ret;
}
twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, LED_PWM_CTRL2);
return 0;
}
void pwm_disable(struct pwm_device *pwm)
{
u8 val;
int ret;
ret = twl_i2c_read_u8(TWL6030_MODULE_ID1, &val, LED_PWM_CTRL2);
if (ret < 0) {
pr_err("%s: Failed to disable PWM, Error %d\n",
pwm->label, ret);
return;
}
val &= ~PWM_CTRL2_MODE_MASK;
val |= PWM_CTRL2_MODE_HW;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, LED_PWM_CTRL2);
if (ret < 0) {
pr_err("%s: Failed to disable PWM, Error %d\n",
pwm->label, ret);
return;
}
return;
}
struct pwm_device *pwm_request(int pwm_id, const char *label)
{
u8 val;
int ret;
struct pwm_device *pwm;
pwm = kzalloc(sizeof(struct pwm_device), GFP_KERNEL);
if (pwm == NULL) {
pr_err("%s: failed to allocate memory\n", label);
return NULL;
}
pwm->label = label;
pwm->pwm_id = pwm_id;
val = PWM_CTRL2_DIS_PD | PWM_CTRL2_CURR_02 | PWM_CTRL2_SRC_VAC |
PWM_CTRL2_MODE_HW;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, val, LED_PWM_CTRL2);
if (ret < 0) {
pr_err("%s: Failed to configure PWM, Error %d\n",
pwm->label, ret);
kfree(pwm);
return NULL;
}
return pwm;
}
void pwm_free(struct pwm_device *pwm)
{
pwm_disable(pwm);
kfree(pwm);
}
