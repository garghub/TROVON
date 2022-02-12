static int pwm_ir_set_duty_cycle(struct rc_dev *dev, u32 duty_cycle)
{
struct pwm_ir *pwm_ir = dev->priv;
pwm_ir->duty_cycle = duty_cycle;
return 0;
}
static int pwm_ir_set_carrier(struct rc_dev *dev, u32 carrier)
{
struct pwm_ir *pwm_ir = dev->priv;
if (!carrier)
return -EINVAL;
pwm_ir->carrier = carrier;
return 0;
}
static int pwm_ir_tx(struct rc_dev *dev, unsigned int *txbuf,
unsigned int count)
{
struct pwm_ir *pwm_ir = dev->priv;
struct pwm_device *pwm = pwm_ir->pwm;
int i, duty, period;
ktime_t edge;
long delta;
period = DIV_ROUND_CLOSEST(NSEC_PER_SEC, pwm_ir->carrier);
duty = DIV_ROUND_CLOSEST(pwm_ir->duty_cycle * period, 100);
pwm_config(pwm, duty, period);
edge = ktime_get();
for (i = 0; i < count; i++) {
if (i % 2)
pwm_disable(pwm);
else
pwm_enable(pwm);
edge = ktime_add_us(edge, txbuf[i]);
delta = ktime_us_delta(edge, ktime_get());
if (delta > 0)
usleep_range(delta, delta + 10);
}
pwm_disable(pwm);
return count;
}
static int pwm_ir_probe(struct platform_device *pdev)
{
struct pwm_ir *pwm_ir;
struct rc_dev *rcdev;
int rc;
pwm_ir = devm_kmalloc(&pdev->dev, sizeof(*pwm_ir), GFP_KERNEL);
if (!pwm_ir)
return -ENOMEM;
pwm_ir->pwm = devm_pwm_get(&pdev->dev, NULL);
if (IS_ERR(pwm_ir->pwm))
return PTR_ERR(pwm_ir->pwm);
pwm_ir->carrier = 38000;
pwm_ir->duty_cycle = 50;
rcdev = devm_rc_allocate_device(&pdev->dev, RC_DRIVER_IR_RAW_TX);
if (!rcdev)
return -ENOMEM;
rcdev->priv = pwm_ir;
rcdev->driver_name = DRIVER_NAME;
rcdev->device_name = DEVICE_NAME;
rcdev->tx_ir = pwm_ir_tx;
rcdev->s_tx_duty_cycle = pwm_ir_set_duty_cycle;
rcdev->s_tx_carrier = pwm_ir_set_carrier;
rc = devm_rc_register_device(&pdev->dev, rcdev);
if (rc < 0)
dev_err(&pdev->dev, "failed to register rc device\n");
return rc;
}
