static inline void lirc_rx51_on(struct lirc_rx51 *lirc_rx51)
{
pwm_enable(lirc_rx51->pwm);
}
static inline void lirc_rx51_off(struct lirc_rx51 *lirc_rx51)
{
pwm_disable(lirc_rx51->pwm);
}
static int init_timing_params(struct lirc_rx51 *lirc_rx51)
{
struct pwm_device *pwm = lirc_rx51->pwm;
int duty, period = DIV_ROUND_CLOSEST(NSEC_PER_SEC, lirc_rx51->freq);
duty = DIV_ROUND_CLOSEST(lirc_rx51->duty_cycle * period, 100);
pwm_config(pwm, duty, period);
return 0;
}
static enum hrtimer_restart lirc_rx51_timer_cb(struct hrtimer *timer)
{
struct lirc_rx51 *lirc_rx51 =
container_of(timer, struct lirc_rx51, timer);
ktime_t now;
if (lirc_rx51->wbuf_index < 0) {
dev_err_ratelimited(lirc_rx51->dev,
"BUG wbuf_index has value of %i\n",
lirc_rx51->wbuf_index);
goto end;
}
do {
u64 ns;
if (lirc_rx51->wbuf_index >= WBUF_LEN)
goto end;
if (lirc_rx51->wbuf[lirc_rx51->wbuf_index] == -1)
goto end;
if (lirc_rx51->wbuf_index % 2)
lirc_rx51_off(lirc_rx51);
else
lirc_rx51_on(lirc_rx51);
ns = 1000 * lirc_rx51->wbuf[lirc_rx51->wbuf_index];
hrtimer_add_expires_ns(timer, ns);
lirc_rx51->wbuf_index++;
now = timer->base->get_time();
} while (hrtimer_get_expires_tv64(timer) < now.tv64);
return HRTIMER_RESTART;
end:
lirc_rx51_off(lirc_rx51);
lirc_rx51->wbuf_index = -1;
wake_up_interruptible(&lirc_rx51->wqueue);
return HRTIMER_NORESTART;
}
static ssize_t lirc_rx51_write(struct file *file, const char *buf,
size_t n, loff_t *ppos)
{
int count, i;
struct lirc_rx51 *lirc_rx51 = file->private_data;
if (n % sizeof(int))
return -EINVAL;
count = n / sizeof(int);
if ((count > WBUF_LEN) || (count % 2 == 0))
return -EINVAL;
wait_event_interruptible(lirc_rx51->wqueue, lirc_rx51->wbuf_index < 0);
if (copy_from_user(lirc_rx51->wbuf, buf, n))
return -EFAULT;
for (i = 0; i < count; i++)
if (lirc_rx51->wbuf[i] < 0)
return -EINVAL;
init_timing_params(lirc_rx51);
if (count < WBUF_LEN)
lirc_rx51->wbuf[count] = -1;
lirc_rx51->pdata->set_max_mpu_wakeup_lat(lirc_rx51->dev, 50);
lirc_rx51_on(lirc_rx51);
lirc_rx51->wbuf_index = 1;
hrtimer_start(&lirc_rx51->timer,
ns_to_ktime(1000 * lirc_rx51->wbuf[0]),
HRTIMER_MODE_REL);
wait_event_interruptible(lirc_rx51->wqueue, lirc_rx51->wbuf_index < 0);
lirc_rx51->pdata->set_max_mpu_wakeup_lat(lirc_rx51->dev, -1);
return n;
}
static long lirc_rx51_ioctl(struct file *filep,
unsigned int cmd, unsigned long arg)
{
int result;
unsigned long value;
unsigned int ivalue;
struct lirc_rx51 *lirc_rx51 = filep->private_data;
switch (cmd) {
case LIRC_GET_SEND_MODE:
result = put_user(LIRC_MODE_PULSE, (unsigned long *)arg);
if (result)
return result;
break;
case LIRC_SET_SEND_MODE:
result = get_user(value, (unsigned long *)arg);
if (result)
return result;
if (value != LIRC_MODE_PULSE)
return -ENOSYS;
break;
case LIRC_GET_REC_MODE:
result = put_user(0, (unsigned long *) arg);
if (result)
return result;
break;
case LIRC_GET_LENGTH:
return -ENOSYS;
break;
case LIRC_SET_SEND_DUTY_CYCLE:
result = get_user(ivalue, (unsigned int *) arg);
if (result)
return result;
if (ivalue <= 0 || ivalue > 100) {
dev_err(lirc_rx51->dev, ": invalid duty cycle %d\n",
ivalue);
return -EINVAL;
}
lirc_rx51->duty_cycle = ivalue;
break;
case LIRC_SET_SEND_CARRIER:
result = get_user(ivalue, (unsigned int *) arg);
if (result)
return result;
if (ivalue > 500000 || ivalue < 20000) {
dev_err(lirc_rx51->dev, ": invalid carrier freq %d\n",
ivalue);
return -EINVAL;
}
lirc_rx51->freq = ivalue;
break;
case LIRC_GET_FEATURES:
result = put_user(LIRC_RX51_DRIVER_FEATURES,
(unsigned long *) arg);
if (result)
return result;
break;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int lirc_rx51_open(struct inode *inode, struct file *file)
{
struct lirc_rx51 *lirc_rx51 = lirc_get_pdata(file);
BUG_ON(!lirc_rx51);
file->private_data = lirc_rx51;
if (test_and_set_bit(1, &lirc_rx51->device_is_open))
return -EBUSY;
lirc_rx51->pwm = pwm_get(lirc_rx51->dev, NULL);
if (IS_ERR(lirc_rx51->pwm)) {
int res = PTR_ERR(lirc_rx51->pwm);
dev_err(lirc_rx51->dev, "pwm_get failed: %d\n", res);
return res;
}
return 0;
}
static int lirc_rx51_release(struct inode *inode, struct file *file)
{
struct lirc_rx51 *lirc_rx51 = file->private_data;
hrtimer_cancel(&lirc_rx51->timer);
lirc_rx51_off(lirc_rx51);
pwm_put(lirc_rx51->pwm);
clear_bit(1, &lirc_rx51->device_is_open);
return 0;
}
static int lirc_rx51_suspend(struct platform_device *dev, pm_message_t state)
{
if (test_and_set_bit(1, &lirc_rx51.device_is_open))
return -EAGAIN;
clear_bit(1, &lirc_rx51.device_is_open);
return 0;
}
static int lirc_rx51_resume(struct platform_device *dev)
{
return 0;
}
static int lirc_rx51_probe(struct platform_device *dev)
{
struct pwm_device *pwm;
lirc_rx51_driver.features = LIRC_RX51_DRIVER_FEATURES;
lirc_rx51.pdata = dev->dev.platform_data;
if (!lirc_rx51.pdata) {
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
lirc_rx51.freq = DIV_ROUND_CLOSEST(pwm_get_period(pwm), NSEC_PER_SEC);
pwm_put(pwm);
hrtimer_init(&lirc_rx51.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
lirc_rx51.timer.function = lirc_rx51_timer_cb;
lirc_rx51.dev = &dev->dev;
lirc_rx51_driver.dev = &dev->dev;
lirc_rx51_driver.minor = lirc_register_driver(&lirc_rx51_driver);
init_waitqueue_head(&lirc_rx51.wqueue);
if (lirc_rx51_driver.minor < 0) {
dev_err(lirc_rx51.dev, ": lirc_register_driver failed: %d\n",
lirc_rx51_driver.minor);
return lirc_rx51_driver.minor;
}
return 0;
}
static int lirc_rx51_remove(struct platform_device *dev)
{
return lirc_unregister_driver(lirc_rx51_driver.minor);
}
