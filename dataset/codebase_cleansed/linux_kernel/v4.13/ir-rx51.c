static inline void ir_rx51_on(struct ir_rx51 *ir_rx51)
{
pwm_enable(ir_rx51->pwm);
}
static inline void ir_rx51_off(struct ir_rx51 *ir_rx51)
{
pwm_disable(ir_rx51->pwm);
}
static int init_timing_params(struct ir_rx51 *ir_rx51)
{
struct pwm_device *pwm = ir_rx51->pwm;
int duty, period = DIV_ROUND_CLOSEST(NSEC_PER_SEC, ir_rx51->freq);
duty = DIV_ROUND_CLOSEST(ir_rx51->duty_cycle * period, 100);
pwm_config(pwm, duty, period);
return 0;
}
static enum hrtimer_restart ir_rx51_timer_cb(struct hrtimer *timer)
{
struct ir_rx51 *ir_rx51 = container_of(timer, struct ir_rx51, timer);
ktime_t now;
if (ir_rx51->wbuf_index < 0) {
dev_err_ratelimited(ir_rx51->dev,
"BUG wbuf_index has value of %i\n",
ir_rx51->wbuf_index);
goto end;
}
do {
u64 ns;
if (ir_rx51->wbuf_index >= WBUF_LEN)
goto end;
if (ir_rx51->wbuf[ir_rx51->wbuf_index] == -1)
goto end;
if (ir_rx51->wbuf_index % 2)
ir_rx51_off(ir_rx51);
else
ir_rx51_on(ir_rx51);
ns = US_TO_NS(ir_rx51->wbuf[ir_rx51->wbuf_index]);
hrtimer_add_expires_ns(timer, ns);
ir_rx51->wbuf_index++;
now = timer->base->get_time();
} while (hrtimer_get_expires_tv64(timer) < now);
return HRTIMER_RESTART;
end:
ir_rx51_off(ir_rx51);
ir_rx51->wbuf_index = -1;
wake_up_interruptible(&ir_rx51->wqueue);
return HRTIMER_NORESTART;
}
static int ir_rx51_tx(struct rc_dev *dev, unsigned int *buffer,
unsigned int count)
{
struct ir_rx51 *ir_rx51 = dev->priv;
if (count > WBUF_LEN)
return -EINVAL;
memcpy(ir_rx51->wbuf, buffer, count * sizeof(unsigned int));
wait_event_interruptible(ir_rx51->wqueue, ir_rx51->wbuf_index < 0);
init_timing_params(ir_rx51);
if (count < WBUF_LEN)
ir_rx51->wbuf[count] = -1;
ir_rx51->pdata->set_max_mpu_wakeup_lat(ir_rx51->dev, 50);
ir_rx51_on(ir_rx51);
ir_rx51->wbuf_index = 1;
hrtimer_start(&ir_rx51->timer,
ns_to_ktime(US_TO_NS(ir_rx51->wbuf[0])),
HRTIMER_MODE_REL);
wait_event_interruptible(ir_rx51->wqueue, ir_rx51->wbuf_index < 0);
ir_rx51->pdata->set_max_mpu_wakeup_lat(ir_rx51->dev, -1);
return count;
}
static int ir_rx51_open(struct rc_dev *dev)
{
struct ir_rx51 *ir_rx51 = dev->priv;
if (test_and_set_bit(1, &ir_rx51->device_is_open))
return -EBUSY;
ir_rx51->pwm = pwm_get(ir_rx51->dev, NULL);
if (IS_ERR(ir_rx51->pwm)) {
int res = PTR_ERR(ir_rx51->pwm);
dev_err(ir_rx51->dev, "pwm_get failed: %d\n", res);
return res;
}
return 0;
}
static void ir_rx51_release(struct rc_dev *dev)
{
struct ir_rx51 *ir_rx51 = dev->priv;
hrtimer_cancel(&ir_rx51->timer);
ir_rx51_off(ir_rx51);
pwm_put(ir_rx51->pwm);
clear_bit(1, &ir_rx51->device_is_open);
}
static int ir_rx51_set_duty_cycle(struct rc_dev *dev, u32 duty)
{
struct ir_rx51 *ir_rx51 = dev->priv;
ir_rx51->duty_cycle = duty;
return 0;
}
static int ir_rx51_set_tx_carrier(struct rc_dev *dev, u32 carrier)
{
struct ir_rx51 *ir_rx51 = dev->priv;
if (carrier > 500000 || carrier < 20000)
return -EINVAL;
ir_rx51->freq = carrier;
return 0;
}
static int ir_rx51_suspend(struct platform_device *dev, pm_message_t state)
{
if (test_and_set_bit(1, &ir_rx51.device_is_open))
return -EAGAIN;
clear_bit(1, &ir_rx51.device_is_open);
return 0;
}
static int ir_rx51_resume(struct platform_device *dev)
{
return 0;
}
static int ir_rx51_probe(struct platform_device *dev)
{
struct pwm_device *pwm;
struct rc_dev *rcdev;
ir_rx51.pdata = dev->dev.platform_data;
if (!ir_rx51.pdata) {
dev_err(&dev->dev, "Platform Data is missing\n");
return -ENXIO;
}
pwm = pwm_get(&dev->dev, NULL);
if (IS_ERR(pwm)) {
int err = PTR_ERR(pwm);
if (err != -EPROBE_DEFER)
dev_err(&dev->dev, "pwm_get failed: %d\n", err);
return err;
}
ir_rx51.freq = DIV_ROUND_CLOSEST(pwm_get_period(pwm), NSEC_PER_SEC);
pwm_put(pwm);
hrtimer_init(&ir_rx51.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
ir_rx51.timer.function = ir_rx51_timer_cb;
ir_rx51.dev = &dev->dev;
rcdev = devm_rc_allocate_device(&dev->dev, RC_DRIVER_IR_RAW_TX);
if (!rcdev)
return -ENOMEM;
rcdev->priv = &ir_rx51;
rcdev->open = ir_rx51_open;
rcdev->close = ir_rx51_release;
rcdev->tx_ir = ir_rx51_tx;
rcdev->s_tx_duty_cycle = ir_rx51_set_duty_cycle;
rcdev->s_tx_carrier = ir_rx51_set_tx_carrier;
rcdev->driver_name = KBUILD_MODNAME;
ir_rx51.rcdev = rcdev;
return devm_rc_register_device(&dev->dev, ir_rx51.rcdev);
}
static int ir_rx51_remove(struct platform_device *dev)
{
return 0;
}
