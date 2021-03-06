static inline int signal_is_set(struct parport *port)
{
return (port->ops->read_status(port) & PARPORT_STATUS_ACK) != 0;
}
static void parport_irq(void *handle)
{
struct pps_event_time ts_assert, ts_clear;
struct pps_client_pp *dev = handle;
struct parport *port = dev->pardev->port;
unsigned int i;
unsigned long flags;
pps_get_ts(&ts_assert);
if (dev->cw == 0)
goto out_assert;
local_irq_save(flags);
if (!signal_is_set(port)) {
local_irq_restore(flags);
dev_err(dev->pps->dev, "lost the signal\n");
goto out_assert;
}
for (i = dev->cw; i; i--)
if (!signal_is_set(port)) {
pps_get_ts(&ts_clear);
local_irq_restore(flags);
dev->cw_err = 0;
goto out_both;
}
local_irq_restore(flags);
dev->cw_err++;
if (dev->cw_err >= CLEAR_WAIT_MAX_ERRORS) {
dev_err(dev->pps->dev, "disabled clear edge capture after %d"
" timeouts\n", dev->cw_err);
dev->cw = 0;
dev->cw_err = 0;
}
out_assert:
pps_event(dev->pps, &ts_assert,
PPS_CAPTUREASSERT, NULL);
return;
out_both:
pps_event(dev->pps, &ts_assert,
PPS_CAPTUREASSERT, NULL);
pps_event(dev->pps, &ts_clear,
PPS_CAPTURECLEAR, NULL);
return;
}
static void parport_attach(struct parport *port)
{
struct pps_client_pp *device;
struct pps_source_info info = {
.name = KBUILD_MODNAME,
.path = "",
.mode = PPS_CAPTUREBOTH | \
PPS_OFFSETASSERT | PPS_OFFSETCLEAR | \
PPS_ECHOASSERT | PPS_ECHOCLEAR | \
PPS_CANWAIT | PPS_TSFMT_TSPEC,
.owner = THIS_MODULE,
.dev = NULL
};
device = kzalloc(sizeof(struct pps_client_pp), GFP_KERNEL);
if (!device) {
pr_err("memory allocation failed, not attaching\n");
return;
}
device->pardev = parport_register_device(port, KBUILD_MODNAME,
NULL, NULL, parport_irq, PARPORT_FLAG_EXCL, device);
if (!device->pardev) {
pr_err("couldn't register with %s\n", port->name);
goto err_free;
}
if (parport_claim_or_block(device->pardev) < 0) {
pr_err("couldn't claim %s\n", port->name);
goto err_unregister_dev;
}
device->pps = pps_register_source(&info,
PPS_CAPTUREBOTH | PPS_OFFSETASSERT | PPS_OFFSETCLEAR);
if (device->pps == NULL) {
pr_err("couldn't register PPS source\n");
goto err_release_dev;
}
device->cw = clear_wait;
port->ops->enable_irq(port);
pr_info("attached to %s\n", port->name);
return;
err_release_dev:
parport_release(device->pardev);
err_unregister_dev:
parport_unregister_device(device->pardev);
err_free:
kfree(device);
}
static void parport_detach(struct parport *port)
{
struct pardevice *pardev = port->cad;
struct pps_client_pp *device;
if (strcmp(pardev->name, KBUILD_MODNAME))
return;
device = pardev->private;
port->ops->disable_irq(port);
pps_unregister_source(device->pps);
parport_release(pardev);
parport_unregister_device(pardev);
kfree(device);
}
static int __init pps_parport_init(void)
{
int ret;
pr_info(DRVDESC "\n");
if (clear_wait > CLEAR_WAIT_MAX) {
pr_err("clear_wait value should be not greater"
" then %d\n", CLEAR_WAIT_MAX);
return -EINVAL;
}
ret = parport_register_driver(&pps_parport_driver);
if (ret) {
pr_err("unable to register with parport\n");
return ret;
}
return 0;
}
static void __exit pps_parport_exit(void)
{
parport_unregister_driver(&pps_parport_driver);
}
