static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct pwm_fan_ctx *ctx = dev_get_drvdata(dev);
unsigned long pwm, duty;
ssize_t ret;
if (kstrtoul(buf, 10, &pwm) || pwm > MAX_PWM)
return -EINVAL;
mutex_lock(&ctx->lock);
if (ctx->pwm_value == pwm)
goto exit_set_pwm_no_change;
if (pwm == 0) {
pwm_disable(ctx->pwm);
goto exit_set_pwm;
}
duty = DIV_ROUND_UP(pwm * (ctx->pwm->period - 1), MAX_PWM);
ret = pwm_config(ctx->pwm, duty, ctx->pwm->period);
if (ret)
goto exit_set_pwm_err;
if (ctx->pwm_value == 0) {
ret = pwm_enable(ctx->pwm);
if (ret)
goto exit_set_pwm_err;
}
exit_set_pwm:
ctx->pwm_value = pwm;
exit_set_pwm_no_change:
ret = count;
exit_set_pwm_err:
mutex_unlock(&ctx->lock);
return ret;
}
static ssize_t show_pwm(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pwm_fan_ctx *ctx = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", ctx->pwm_value);
}
static int pwm_fan_probe(struct platform_device *pdev)
{
struct device *hwmon;
struct pwm_fan_ctx *ctx;
int duty_cycle;
int ret;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
mutex_init(&ctx->lock);
ctx->pwm = devm_of_pwm_get(&pdev->dev, pdev->dev.of_node, NULL);
if (IS_ERR(ctx->pwm)) {
dev_err(&pdev->dev, "Could not get PWM\n");
return PTR_ERR(ctx->pwm);
}
platform_set_drvdata(pdev, ctx);
duty_cycle = ctx->pwm->period - 1;
ctx->pwm_value = MAX_PWM;
ret = pwm_config(ctx->pwm, duty_cycle, ctx->pwm->period);
if (ret) {
dev_err(&pdev->dev, "Failed to configure PWM\n");
return ret;
}
ret = pwm_enable(ctx->pwm);
if (ret) {
dev_err(&pdev->dev, "Failed to enable PWM\n");
return ret;
}
hwmon = devm_hwmon_device_register_with_groups(&pdev->dev, "pwmfan",
ctx, pwm_fan_groups);
if (IS_ERR(hwmon)) {
dev_err(&pdev->dev, "Failed to register hwmon device\n");
pwm_disable(ctx->pwm);
return PTR_ERR(hwmon);
}
return 0;
}
static int pwm_fan_remove(struct platform_device *pdev)
{
struct pwm_fan_ctx *ctx = platform_get_drvdata(pdev);
if (ctx->pwm_value)
pwm_disable(ctx->pwm);
return 0;
}
static int pwm_fan_suspend(struct device *dev)
{
struct pwm_fan_ctx *ctx = dev_get_drvdata(dev);
if (ctx->pwm_value)
pwm_disable(ctx->pwm);
return 0;
}
static int pwm_fan_resume(struct device *dev)
{
struct pwm_fan_ctx *ctx = dev_get_drvdata(dev);
if (ctx->pwm_value)
return pwm_enable(ctx->pwm);
return 0;
}
