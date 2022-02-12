int pwm_config(struct pwm_device *pwm, int duty_ns, int period_ns)
{
int ret = 0;
unsigned int higher_val, lower_val;
u8 reg;
lower_val = duty_ns & 0x00FF;
higher_val = ((duty_ns & 0x0300) >> 8);
reg = AB8500_PWM_OUT_CTRL1_REG + ((pwm->pwm_id - 1) * 2);
ret = abx500_set_register_interruptible(pwm->dev, AB8500_MISC,
reg, (u8)lower_val);
if (ret < 0)
return ret;
ret = abx500_set_register_interruptible(pwm->dev, AB8500_MISC,
(reg + 1), (u8)higher_val);
return ret;
}
int pwm_enable(struct pwm_device *pwm)
{
int ret;
ret = abx500_mask_and_set_register_interruptible(pwm->dev,
AB8500_MISC, AB8500_PWM_OUT_CTRL7_REG,
1 << (pwm->pwm_id-1), ENABLE_PWM);
if (ret < 0)
dev_err(pwm->dev, "%s: Failed to disable PWM, Error %d\n",
pwm->label, ret);
return ret;
}
void pwm_disable(struct pwm_device *pwm)
{
int ret;
ret = abx500_mask_and_set_register_interruptible(pwm->dev,
AB8500_MISC, AB8500_PWM_OUT_CTRL7_REG,
1 << (pwm->pwm_id-1), DISABLE_PWM);
if (ret < 0)
dev_err(pwm->dev, "%s: Failed to disable PWM, Error %d\n",
pwm->label, ret);
return;
}
struct pwm_device *pwm_request(int pwm_id, const char *label)
{
struct pwm_device *pwm;
list_for_each_entry(pwm, &pwm_list, node) {
if (pwm->pwm_id == pwm_id) {
pwm->label = label;
pwm->pwm_id = pwm_id;
return pwm;
}
}
return ERR_PTR(-ENOENT);
}
void pwm_free(struct pwm_device *pwm)
{
pwm_disable(pwm);
}
static int __devinit ab8500_pwm_probe(struct platform_device *pdev)
{
struct pwm_device *pwm;
pwm = kzalloc(sizeof(struct pwm_device), GFP_KERNEL);
if (pwm == NULL) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
pwm->dev = &pdev->dev;
pwm->pwm_id = pdev->id;
list_add_tail(&pwm->node, &pwm_list);
platform_set_drvdata(pdev, pwm);
dev_dbg(pwm->dev, "pwm probe successful\n");
return 0;
}
static int __devexit ab8500_pwm_remove(struct platform_device *pdev)
{
struct pwm_device *pwm = platform_get_drvdata(pdev);
list_del(&pwm->node);
dev_dbg(&pdev->dev, "pwm driver removed\n");
kfree(pwm);
return 0;
}
static int __init ab8500_pwm_init(void)
{
return platform_driver_register(&ab8500_pwm_driver);
}
static void __exit ab8500_pwm_exit(void)
{
platform_driver_unregister(&ab8500_pwm_driver);
}
