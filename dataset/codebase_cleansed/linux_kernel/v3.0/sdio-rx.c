static ssize_t __i2400ms_rx_get_size(struct i2400ms *i2400ms)
{
int ret, cnt, val;
ssize_t rx_size;
unsigned xfer_size_addr;
struct sdio_func *func = i2400ms->func;
struct device *dev = &i2400ms->func->dev;
d_fnstart(7, dev, "(i2400ms %p)\n", i2400ms);
xfer_size_addr = I2400MS_INTR_GET_SIZE_ADDR;
rx_size = 0;
for (cnt = 0; cnt < 3; cnt++) {
val = sdio_readb(func, xfer_size_addr + cnt, &ret);
if (ret < 0) {
dev_err(dev, "RX: Can't read byte %d of RX size from "
"0x%08x: %d\n", cnt, xfer_size_addr + cnt, ret);
rx_size = ret;
goto error_read;
}
rx_size = rx_size << 8 | (val & 0xff);
}
d_printf(6, dev, "RX: rx_size is %ld\n", (long) rx_size);
error_read:
d_fnend(7, dev, "(i2400ms %p) = %ld\n", i2400ms, (long) rx_size);
return rx_size;
}
static
void i2400ms_rx(struct i2400ms *i2400ms)
{
int ret;
struct sdio_func *func = i2400ms->func;
struct device *dev = &func->dev;
struct i2400m *i2400m = &i2400ms->i2400m;
struct sk_buff *skb;
ssize_t rx_size;
d_fnstart(7, dev, "(i2400ms %p)\n", i2400ms);
rx_size = __i2400ms_rx_get_size(i2400ms);
if (rx_size < 0) {
ret = rx_size;
goto error_get_size;
}
sdio_writeb(func, 1, I2400MS_INTR_CLEAR_ADDR, &ret);
ret = -ENOMEM;
skb = alloc_skb(rx_size, GFP_ATOMIC);
if (NULL == skb) {
dev_err(dev, "RX: unable to alloc skb\n");
goto error_alloc_skb;
}
ret = sdio_memcpy_fromio(func, skb->data,
I2400MS_DATA_ADDR, rx_size);
if (ret < 0) {
dev_err(dev, "RX: SDIO data read failed: %d\n", ret);
goto error_memcpy_fromio;
}
rmb();
if (unlikely(i2400m->boot_mode == 1)) {
spin_lock(&i2400m->rx_lock);
i2400ms->bm_ack_size = rx_size;
spin_unlock(&i2400m->rx_lock);
memcpy(i2400m->bm_ack_buf, skb->data, rx_size);
wake_up(&i2400ms->bm_wfa_wq);
d_printf(5, dev, "RX: SDIO boot mode message\n");
kfree_skb(skb);
goto out;
}
ret = -EIO;
if (unlikely(rx_size < sizeof(__le32))) {
dev_err(dev, "HW BUG? only %zu bytes received\n", rx_size);
goto error_bad_size;
}
if (likely(i2400m_is_d2h_barker(skb->data))) {
skb_put(skb, rx_size);
i2400m_rx(i2400m, skb);
} else if (unlikely(i2400m_is_boot_barker(i2400m,
skb->data, rx_size))) {
ret = i2400m_dev_reset_handle(i2400m, "device rebooted");
dev_err(dev, "RX: SDIO reboot barker\n");
kfree_skb(skb);
} else {
i2400m_unknown_barker(i2400m, skb->data, rx_size);
kfree_skb(skb);
}
out:
d_fnend(7, dev, "(i2400ms %p) = void\n", i2400ms);
return;
error_memcpy_fromio:
kfree_skb(skb);
error_alloc_skb:
error_get_size:
error_bad_size:
d_fnend(7, dev, "(i2400ms %p) = %d\n", i2400ms, ret);
}
static
void i2400ms_irq(struct sdio_func *func)
{
int ret;
struct i2400ms *i2400ms = sdio_get_drvdata(func);
struct device *dev = &func->dev;
int val;
d_fnstart(6, dev, "(i2400ms %p)\n", i2400ms);
val = sdio_readb(func, I2400MS_INTR_STATUS_ADDR, &ret);
if (ret < 0) {
dev_err(dev, "RX: Can't read interrupt status: %d\n", ret);
goto error_no_irq;
}
if (!val) {
dev_err(dev, "RX: BUG? got IRQ but no interrupt ready?\n");
goto error_no_irq;
}
i2400ms_rx(i2400ms);
error_no_irq:
d_fnend(6, dev, "(i2400ms %p) = void\n", i2400ms);
}
int i2400ms_rx_setup(struct i2400ms *i2400ms)
{
int result;
struct sdio_func *func = i2400ms->func;
struct device *dev = &func->dev;
struct i2400m *i2400m = &i2400ms->i2400m;
d_fnstart(5, dev, "(i2400ms %p)\n", i2400ms);
init_waitqueue_head(&i2400ms->bm_wfa_wq);
spin_lock(&i2400m->rx_lock);
i2400ms->bm_wait_result = -EINPROGRESS;
i2400ms->bm_ack_size = -EINPROGRESS;
spin_unlock(&i2400m->rx_lock);
sdio_claim_host(func);
result = sdio_claim_irq(func, i2400ms_irq);
if (result < 0) {
dev_err(dev, "Cannot claim IRQ: %d\n", result);
goto error_irq_claim;
}
result = 0;
sdio_writeb(func, 1, I2400MS_INTR_ENABLE_ADDR, &result);
if (result < 0) {
sdio_release_irq(func);
dev_err(dev, "Failed to enable interrupts %d\n", result);
}
error_irq_claim:
sdio_release_host(func);
d_fnend(5, dev, "(i2400ms %p) = %d\n", i2400ms, result);
return result;
}
void i2400ms_rx_release(struct i2400ms *i2400ms)
{
int result;
struct sdio_func *func = i2400ms->func;
struct device *dev = &func->dev;
struct i2400m *i2400m = &i2400ms->i2400m;
d_fnstart(5, dev, "(i2400ms %p)\n", i2400ms);
spin_lock(&i2400m->rx_lock);
i2400ms->bm_ack_size = -EINTR;
spin_unlock(&i2400m->rx_lock);
wake_up_all(&i2400ms->bm_wfa_wq);
sdio_claim_host(func);
sdio_writeb(func, 0, I2400MS_INTR_ENABLE_ADDR, &result);
sdio_release_irq(func);
sdio_release_host(func);
d_fnend(5, dev, "(i2400ms %p) = %d\n", i2400ms, result);
}
