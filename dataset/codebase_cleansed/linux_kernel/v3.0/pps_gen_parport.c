static enum hrtimer_restart hrtimer_event(struct hrtimer *timer)
{
struct timespec expire_time, ts1, ts2, ts3, dts;
struct pps_generator_pp *dev;
struct parport *port;
long lim, delta;
unsigned long flags;
local_irq_save(flags);
getnstimeofday(&ts1);
expire_time = ktime_to_timespec(hrtimer_get_softexpires(timer));
dev = container_of(timer, struct pps_generator_pp, timer);
lim = NSEC_PER_SEC - send_delay - dev->port_write_time;
if (expire_time.tv_sec != ts1.tv_sec || ts1.tv_nsec > lim) {
local_irq_restore(flags);
pr_err("we are late this time %ld.%09ld\n",
ts1.tv_sec, ts1.tv_nsec);
goto done;
}
do {
getnstimeofday(&ts2);
} while (expire_time.tv_sec == ts2.tv_sec && ts2.tv_nsec < lim);
port = dev->pardev->port;
port->ops->write_control(port, SIGNAL);
lim = NSEC_PER_SEC - dev->port_write_time;
do {
getnstimeofday(&ts2);
} while (expire_time.tv_sec == ts2.tv_sec && ts2.tv_nsec < lim);
port->ops->write_control(port, NO_SIGNAL);
getnstimeofday(&ts3);
local_irq_restore(flags);
dts = timespec_sub(ts3, ts2);
dev->port_write_time =
(dev->port_write_time + timespec_to_ns(&dts)) >> 1;
done:
dts = timespec_sub(ts1, expire_time);
delta = timespec_to_ns(&dts);
if (delta >= hrtimer_error)
hrtimer_error = delta;
else
hrtimer_error = (3 * hrtimer_error + delta) >> 2;
hrtimer_set_expires(timer,
ktime_set(expire_time.tv_sec + 1,
NSEC_PER_SEC - (send_delay +
dev->port_write_time + SAFETY_INTERVAL +
2 * hrtimer_error)));
return HRTIMER_RESTART;
}
static void calibrate_port(struct pps_generator_pp *dev)
{
struct parport *port = dev->pardev->port;
int i;
long acc = 0;
for (i = 0; i < (1 << PORT_NTESTS_SHIFT); i++) {
struct timespec a, b;
unsigned long irq_flags;
local_irq_save(irq_flags);
getnstimeofday(&a);
port->ops->write_control(port, NO_SIGNAL);
getnstimeofday(&b);
local_irq_restore(irq_flags);
b = timespec_sub(b, a);
acc += timespec_to_ns(&b);
}
dev->port_write_time = acc >> PORT_NTESTS_SHIFT;
pr_info("port write takes %ldns\n", dev->port_write_time);
}
static inline ktime_t next_intr_time(struct pps_generator_pp *dev)
{
struct timespec ts;
getnstimeofday(&ts);
return ktime_set(ts.tv_sec +
((ts.tv_nsec > 990 * NSEC_PER_MSEC) ? 1 : 0),
NSEC_PER_SEC - (send_delay +
dev->port_write_time + 3 * SAFETY_INTERVAL));
}
static void parport_attach(struct parport *port)
{
if (attached) {
return;
}
device.pardev = parport_register_device(port, KBUILD_MODNAME,
NULL, NULL, NULL, PARPORT_FLAG_EXCL, &device);
if (!device.pardev) {
pr_err("couldn't register with %s\n", port->name);
return;
}
if (parport_claim_or_block(device.pardev) < 0) {
pr_err("couldn't claim %s\n", port->name);
goto err_unregister_dev;
}
pr_info("attached to %s\n", port->name);
attached = 1;
calibrate_port(&device);
hrtimer_init(&device.timer, CLOCK_REALTIME, HRTIMER_MODE_ABS);
device.timer.function = hrtimer_event;
hrtimer_start(&device.timer, next_intr_time(&device), HRTIMER_MODE_ABS);
return;
err_unregister_dev:
parport_unregister_device(device.pardev);
}
static void parport_detach(struct parport *port)
{
if (port->cad != device.pardev)
return;
hrtimer_cancel(&device.timer);
parport_release(device.pardev);
parport_unregister_device(device.pardev);
}
static int __init pps_gen_parport_init(void)
{
int ret;
pr_info(DRVDESC "\n");
if (send_delay > SEND_DELAY_MAX) {
pr_err("delay value should be not greater"
" then %d\n", SEND_DELAY_MAX);
return -EINVAL;
}
ret = parport_register_driver(&pps_gen_parport_driver);
if (ret) {
pr_err("unable to register with parport\n");
return ret;
}
return 0;
}
static void __exit pps_gen_parport_exit(void)
{
parport_unregister_driver(&pps_gen_parport_driver);
pr_info("hrtimer avg error is %ldns\n", hrtimer_error);
}
