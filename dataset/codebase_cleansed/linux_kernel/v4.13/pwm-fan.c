static int __set_pwm(struct pwm_fan_ctx *ctx, unsigned long pwm)
{
unsigned long period;
int ret = 0;
struct pwm_state state = { };
mutex_lock(&ctx->lock);
if (ctx->pwm_value == pwm)
goto exit_set_pwm_err;
pwm_init_state(ctx->pwm, &state);
period = ctx->pwm->args.period;
state.duty_cycle = DIV_ROUND_UP(pwm * (period - 1), MAX_PWM);
state.enabled = pwm ? true : false;
ret = pwm_apply_state(ctx->pwm, &state);
if (!ret)
ctx->pwm_value = pwm;
exit_set_pwm_err:
mutex_unlock(&ctx->lock);
return ret;
}
static void pwm_fan_update_state(struct pwm_fan_ctx *ctx, unsigned long pwm)
{
int i;
for (i = 0; i < ctx->pwm_fan_max_state; ++i)
if (pwm < ctx->pwm_fan_cooling_levels[i + 1])
break;
ctx->pwm_fan_state = i;
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct pwm_fan_ctx *ctx = dev_get_drvdata(dev);
unsigned long pwm;
int ret;
if (kstrtoul(buf, 10, &pwm) || pwm > MAX_PWM)
return -EINVAL;
ret = __set_pwm(ctx, pwm);
if (ret)
return ret;
pwm_fan_update_state(ctx, pwm);
return count;
}
static ssize_t show_pwm(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct pwm_fan_ctx *ctx = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", ctx->pwm_value);
}
static int pwm_fan_get_max_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct pwm_fan_ctx *ctx = cdev->devdata;
if (!ctx)
return -EINVAL;
*state = ctx->pwm_fan_max_state;
return 0;
}
static int pwm_fan_get_cur_state(struct thermal_cooling_device *cdev,
unsigned long *state)
{
struct pwm_fan_ctx *ctx = cdev->devdata;
if (!ctx)
return -EINVAL;
*state = ctx->pwm_fan_state;
return 0;
}
static int
pwm_fan_set_cur_state(struct thermal_cooling_device *cdev, unsigned long state)
{
struct pwm_fan_ctx *ctx = cdev->devdata;
int ret;
if (!ctx || (state > ctx->pwm_fan_max_state))
return -EINVAL;
if (state == ctx->pwm_fan_state)
return 0;
ret = __set_pwm(ctx, ctx->pwm_fan_cooling_levels[state]);
if (ret) {
dev_err(&cdev->device, "Cannot set pwm!\n");
return ret;
}
ctx->pwm_fan_state = state;
return ret;
}
static int pwm_fan_of_get_cooling_data(struct device *dev,
struct pwm_fan_ctx *ctx)
{
struct device_node *np = dev->of_node;
int num, i, ret;
if (!of_find_property(np, "cooling-levels", NULL))
return 0;
ret = of_property_count_u32_elems(np, "cooling-levels");
if (ret <= 0) {
dev_err(dev, "Wrong data!\n");
return ret ? : -EINVAL;
}
num = ret;
ctx->pwm_fan_cooling_levels = devm_kzalloc(dev, num * sizeof(u32),
GFP_KERNEL);
if (!ctx->pwm_fan_cooling_levels)
return -ENOMEM;
ret = of_property_read_u32_array(np, "cooling-levels",
ctx->pwm_fan_cooling_levels, num);
if (ret) {
dev_err(dev, "Property 'cooling-levels' cannot be read!\n");
return ret;
}
for (i = 0; i < num; i++) {
if (ctx->pwm_fan_cooling_levels[i] > MAX_PWM) {
dev_err(dev, "PWM fan state[%d]:%d > %d\n", i,
ctx->pwm_fan_cooling_levels[i], MAX_PWM);
return -EINVAL;
}
}
ctx->pwm_fan_max_state = num - 1;
return 0;
}
static int pwm_fan_probe(struct platform_device *pdev)
{
struct thermal_cooling_device *cdev;
struct pwm_fan_ctx *ctx;
struct device *hwmon;
int ret;
struct pwm_state state = { };
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
ctx->pwm_value = MAX_PWM;
pwm_init_state(ctx->pwm, &state);
state.duty_cycle = ctx->pwm->args.period - 1;
state.enabled = true;
ret = pwm_apply_state(ctx->pwm, &state);
if (ret) {
dev_err(&pdev->dev, "Failed to configure PWM\n");
return ret;
}
hwmon = devm_hwmon_device_register_with_groups(&pdev->dev, "pwmfan",
ctx, pwm_fan_groups);
if (IS_ERR(hwmon)) {
dev_err(&pdev->dev, "Failed to register hwmon device\n");
ret = PTR_ERR(hwmon);
goto err_pwm_disable;
}
ret = pwm_fan_of_get_cooling_data(&pdev->dev, ctx);
if (ret)
return ret;
ctx->pwm_fan_state = ctx->pwm_fan_max_state;
if (IS_ENABLED(CONFIG_THERMAL)) {
cdev = thermal_of_cooling_device_register(pdev->dev.of_node,
"pwm-fan", ctx,
&pwm_fan_cooling_ops);
if (IS_ERR(cdev)) {
dev_err(&pdev->dev,
"Failed to register pwm-fan as cooling device");
ret = PTR_ERR(cdev);
goto err_pwm_disable;
}
ctx->cdev = cdev;
thermal_cdev_update(cdev);
}
return 0;
err_pwm_disable:
state.enabled = false;
pwm_apply_state(ctx->pwm, &state);
return ret;
}
static int pwm_fan_remove(struct platform_device *pdev)
{
struct pwm_fan_ctx *ctx = platform_get_drvdata(pdev);
thermal_cooling_device_unregister(ctx->cdev);
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
struct pwm_args pargs;
unsigned long duty;
int ret;
if (ctx->pwm_value == 0)
return 0;
pwm_get_args(ctx->pwm, &pargs);
duty = DIV_ROUND_UP(ctx->pwm_value * (pargs.period - 1), MAX_PWM);
ret = pwm_config(ctx->pwm, duty, pargs.period);
if (ret)
return ret;
return pwm_enable(ctx->pwm);
}
