static int loop_set_tx_mask(struct rc_dev *dev, u32 mask)
{
struct loopback_dev *lodev = dev->priv;
if ((mask & (RXMASK_REGULAR | RXMASK_LEARNING)) != mask) {
dprintk("invalid tx mask: %u\n", mask);
return -EINVAL;
}
dprintk("setting tx mask: %u\n", mask);
lodev->txmask = mask;
return 0;
}
static int loop_set_tx_carrier(struct rc_dev *dev, u32 carrier)
{
struct loopback_dev *lodev = dev->priv;
dprintk("setting tx carrier: %u\n", carrier);
lodev->txcarrier = carrier;
return 0;
}
static int loop_set_tx_duty_cycle(struct rc_dev *dev, u32 duty_cycle)
{
struct loopback_dev *lodev = dev->priv;
if (duty_cycle < 1 || duty_cycle > 99) {
dprintk("invalid duty cycle: %u\n", duty_cycle);
return -EINVAL;
}
dprintk("setting duty cycle: %u\n", duty_cycle);
lodev->txduty = duty_cycle;
return 0;
}
static int loop_set_rx_carrier_range(struct rc_dev *dev, u32 min, u32 max)
{
struct loopback_dev *lodev = dev->priv;
if (min < 1 || min > max) {
dprintk("invalid rx carrier range %u to %u\n", min, max);
return -EINVAL;
}
dprintk("setting rx carrier range %u to %u\n", min, max);
lodev->rxcarriermin = min;
lodev->rxcarriermax = max;
return 0;
}
static int loop_tx_ir(struct rc_dev *dev, unsigned *txbuf, unsigned count)
{
struct loopback_dev *lodev = dev->priv;
u32 rxmask;
unsigned i;
DEFINE_IR_RAW_EVENT(rawir);
if (lodev->txcarrier < lodev->rxcarriermin ||
lodev->txcarrier > lodev->rxcarriermax) {
dprintk("ignoring tx, carrier out of range\n");
goto out;
}
if (lodev->learning)
rxmask = RXMASK_LEARNING;
else
rxmask = RXMASK_REGULAR;
if (!(rxmask & lodev->txmask)) {
dprintk("ignoring tx, rx mask mismatch\n");
goto out;
}
for (i = 0; i < count; i++) {
rawir.pulse = i % 2 ? false : true;
rawir.duration = txbuf[i] * 1000;
if (rawir.duration)
ir_raw_event_store_with_filter(dev, &rawir);
}
rawir.pulse = false;
rawir.duration = dev->timeout;
ir_raw_event_store_with_filter(dev, &rawir);
ir_raw_event_handle(dev);
out:
return count;
}
static void loop_set_idle(struct rc_dev *dev, bool enable)
{
struct loopback_dev *lodev = dev->priv;
if (lodev->idle != enable) {
dprintk("%sing idle mode\n", enable ? "enter" : "exit");
lodev->idle = enable;
}
}
static int loop_set_learning_mode(struct rc_dev *dev, int enable)
{
struct loopback_dev *lodev = dev->priv;
if (lodev->learning != enable) {
dprintk("%sing learning mode\n", enable ? "enter" : "exit");
lodev->learning = !!enable;
}
return 0;
}
static int loop_set_carrier_report(struct rc_dev *dev, int enable)
{
struct loopback_dev *lodev = dev->priv;
if (lodev->carrierreport != enable) {
dprintk("%sabling carrier reports\n", enable ? "en" : "dis");
lodev->carrierreport = !!enable;
}
return 0;
}
static int __init loop_init(void)
{
struct rc_dev *rc;
int ret;
rc = rc_allocate_device();
if (!rc) {
printk(KERN_ERR DRIVER_NAME ": rc_dev allocation failed\n");
return -ENOMEM;
}
rc->input_name = "rc-core loopback device";
rc->input_phys = "rc-core/virtual";
rc->input_id.bustype = BUS_VIRTUAL;
rc->input_id.version = 1;
rc->driver_name = DRIVER_NAME;
rc->map_name = RC_MAP_EMPTY;
rc->priv = &loopdev;
rc->driver_type = RC_DRIVER_IR_RAW;
rc->allowed_protocols = RC_BIT_ALL;
rc->timeout = 100 * 1000 * 1000;
rc->min_timeout = 1;
rc->max_timeout = UINT_MAX;
rc->rx_resolution = 1000;
rc->tx_resolution = 1000;
rc->s_tx_mask = loop_set_tx_mask;
rc->s_tx_carrier = loop_set_tx_carrier;
rc->s_tx_duty_cycle = loop_set_tx_duty_cycle;
rc->s_rx_carrier_range = loop_set_rx_carrier_range;
rc->tx_ir = loop_tx_ir;
rc->s_idle = loop_set_idle;
rc->s_learning_mode = loop_set_learning_mode;
rc->s_carrier_report = loop_set_carrier_report;
loopdev.txmask = RXMASK_REGULAR;
loopdev.txcarrier = 36000;
loopdev.txduty = 50;
loopdev.rxcarriermin = 1;
loopdev.rxcarriermax = ~0;
loopdev.idle = true;
loopdev.learning = false;
loopdev.carrierreport = false;
ret = rc_register_device(rc);
if (ret < 0) {
printk(KERN_ERR DRIVER_NAME ": rc_dev registration failed\n");
rc_free_device(rc);
return ret;
}
loopdev.dev = rc;
return 0;
}
static void __exit loop_exit(void)
{
rc_unregister_device(loopdev.dev);
}
