static
int i2400mu_tx(struct i2400mu *i2400mu, struct i2400m_msg_hdr *tx_msg,
size_t tx_msg_size)
{
int result = 0;
struct i2400m *i2400m = &i2400mu->i2400m;
struct device *dev = &i2400mu->usb_iface->dev;
int usb_pipe, sent_size, do_autopm;
struct usb_endpoint_descriptor *epd;
d_fnstart(4, dev, "(i2400mu %p)\n", i2400mu);
do_autopm = atomic_read(&i2400mu->do_autopm);
result = do_autopm ?
usb_autopm_get_interface(i2400mu->usb_iface) : 0;
if (result < 0) {
dev_err(dev, "TX: can't get autopm: %d\n", result);
do_autopm = 0;
}
epd = usb_get_epd(i2400mu->usb_iface, i2400mu->endpoint_cfg.bulk_out);
usb_pipe = usb_sndbulkpipe(i2400mu->usb_dev, epd->bEndpointAddress);
retry:
result = usb_bulk_msg(i2400mu->usb_dev, usb_pipe,
tx_msg, tx_msg_size, &sent_size, 200);
usb_mark_last_busy(i2400mu->usb_dev);
switch (result) {
case 0:
if (sent_size != tx_msg_size) {
dev_err(dev, "TX: short write (%d B vs %zu "
"expected)\n", sent_size, tx_msg_size);
result = -EIO;
}
break;
case -EPIPE:
if (edc_inc(&i2400mu->urb_edc,
10 * EDC_MAX_ERRORS, EDC_ERROR_TIMEFRAME)) {
dev_err(dev, "BM-CMD: too many stalls in "
"URB; resetting device\n");
usb_queue_reset_device(i2400mu->usb_iface);
} else {
usb_clear_halt(i2400mu->usb_dev, usb_pipe);
msleep(10);
goto retry;
}
case -EINVAL:
case -ENODEV:
case -ENOENT:
case -ESHUTDOWN:
case -ECONNRESET:
result = -ESHUTDOWN;
break;
default:
if (edc_inc(&i2400mu->urb_edc,
EDC_MAX_ERRORS, EDC_ERROR_TIMEFRAME)) {
dev_err(dev, "TX: maximum errors in URB "
"exceeded; resetting device\n");
usb_queue_reset_device(i2400mu->usb_iface);
} else {
dev_err(dev, "TX: cannot send URB; retrying. "
"tx_msg @%zu %zu B [%d sent]: %d\n",
(void *) tx_msg - i2400m->tx_buf,
tx_msg_size, sent_size, result);
goto retry;
}
}
if (do_autopm)
usb_autopm_put_interface(i2400mu->usb_iface);
d_fnend(4, dev, "(i2400mu %p) = result\n", i2400mu);
return result;
}
static
int i2400mu_txd(void *_i2400mu)
{
int result = 0;
struct i2400mu *i2400mu = _i2400mu;
struct i2400m *i2400m = &i2400mu->i2400m;
struct device *dev = &i2400mu->usb_iface->dev;
struct i2400m_msg_hdr *tx_msg;
size_t tx_msg_size;
unsigned long flags;
d_fnstart(4, dev, "(i2400mu %p)\n", i2400mu);
spin_lock_irqsave(&i2400m->tx_lock, flags);
BUG_ON(i2400mu->tx_kthread != NULL);
i2400mu->tx_kthread = current;
spin_unlock_irqrestore(&i2400m->tx_lock, flags);
while (1) {
d_printf(2, dev, "TX: waiting for messages\n");
tx_msg = NULL;
wait_event_interruptible(
i2400mu->tx_wq,
(kthread_should_stop()
|| (tx_msg = i2400m_tx_msg_get(i2400m, &tx_msg_size)))
);
if (kthread_should_stop())
break;
WARN_ON(tx_msg == NULL);
d_printf(2, dev, "TX: submitting %zu bytes\n", tx_msg_size);
d_dump(5, dev, tx_msg, tx_msg_size);
i2400mu_tx(i2400mu, tx_msg, tx_msg_size);
i2400m_tx_msg_sent(i2400m);
if (result < 0)
break;
}
spin_lock_irqsave(&i2400m->tx_lock, flags);
i2400mu->tx_kthread = NULL;
spin_unlock_irqrestore(&i2400m->tx_lock, flags);
d_fnend(4, dev, "(i2400mu %p) = %d\n", i2400mu, result);
return result;
}
void i2400mu_bus_tx_kick(struct i2400m *i2400m)
{
struct i2400mu *i2400mu = container_of(i2400m, struct i2400mu, i2400m);
struct device *dev = &i2400mu->usb_iface->dev;
d_fnstart(3, dev, "(i2400m %p) = void\n", i2400m);
wake_up_all(&i2400mu->tx_wq);
d_fnend(3, dev, "(i2400m %p) = void\n", i2400m);
}
int i2400mu_tx_setup(struct i2400mu *i2400mu)
{
int result = 0;
struct i2400m *i2400m = &i2400mu->i2400m;
struct device *dev = &i2400mu->usb_iface->dev;
struct wimax_dev *wimax_dev = &i2400m->wimax_dev;
struct task_struct *kthread;
kthread = kthread_run(i2400mu_txd, i2400mu, "%s-tx",
wimax_dev->name);
if (IS_ERR(kthread)) {
result = PTR_ERR(kthread);
dev_err(dev, "TX: cannot start thread: %d\n", result);
}
return result;
}
void i2400mu_tx_release(struct i2400mu *i2400mu)
{
unsigned long flags;
struct i2400m *i2400m = &i2400mu->i2400m;
struct device *dev = i2400m_dev(i2400m);
struct task_struct *kthread;
spin_lock_irqsave(&i2400m->tx_lock, flags);
kthread = i2400mu->tx_kthread;
i2400mu->tx_kthread = NULL;
spin_unlock_irqrestore(&i2400m->tx_lock, flags);
if (kthread)
kthread_stop(kthread);
else
d_printf(1, dev, "TX: kthread had already exited\n");
}
