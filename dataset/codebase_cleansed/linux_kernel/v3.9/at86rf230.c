static int
__at86rf230_write(struct at86rf230_local *lp, u8 addr, u8 data)
{
u8 *buf = lp->buf;
int status;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 2,
.tx_buf = buf,
};
buf[0] = (addr & CMD_REG_MASK) | CMD_REG | CMD_WRITE;
buf[1] = data;
dev_vdbg(&lp->spi->dev, "buf[0] = %02x\n", buf[0]);
dev_vdbg(&lp->spi->dev, "buf[1] = %02x\n", buf[1]);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
status = spi_sync(lp->spi, &msg);
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
if (msg.status)
status = msg.status;
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
dev_vdbg(&lp->spi->dev, "buf[0] = %02x\n", buf[0]);
dev_vdbg(&lp->spi->dev, "buf[1] = %02x\n", buf[1]);
return status;
}
static int
__at86rf230_read_subreg(struct at86rf230_local *lp,
u8 addr, u8 mask, int shift, u8 *data)
{
u8 *buf = lp->buf;
int status;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 2,
.tx_buf = buf,
.rx_buf = buf,
};
buf[0] = (addr & CMD_REG_MASK) | CMD_REG;
buf[1] = 0xff;
dev_vdbg(&lp->spi->dev, "buf[0] = %02x\n", buf[0]);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
status = spi_sync(lp->spi, &msg);
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
if (msg.status)
status = msg.status;
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
dev_vdbg(&lp->spi->dev, "buf[0] = %02x\n", buf[0]);
dev_vdbg(&lp->spi->dev, "buf[1] = %02x\n", buf[1]);
if (status == 0)
*data = buf[1];
return status;
}
static int
at86rf230_read_subreg(struct at86rf230_local *lp,
u8 addr, u8 mask, int shift, u8 *data)
{
int status;
mutex_lock(&lp->bmux);
status = __at86rf230_read_subreg(lp, addr, mask, shift, data);
mutex_unlock(&lp->bmux);
return status;
}
static int
at86rf230_write_subreg(struct at86rf230_local *lp,
u8 addr, u8 mask, int shift, u8 data)
{
int status;
u8 val;
mutex_lock(&lp->bmux);
status = __at86rf230_read_subreg(lp, addr, 0xff, 0, &val);
if (status)
goto out;
val &= ~mask;
val |= (data << shift) & mask;
status = __at86rf230_write(lp, addr, val);
out:
mutex_unlock(&lp->bmux);
return status;
}
static int
at86rf230_write_fbuf(struct at86rf230_local *lp, u8 *data, u8 len)
{
u8 *buf = lp->buf;
int status;
struct spi_message msg;
struct spi_transfer xfer_head = {
.len = 2,
.tx_buf = buf,
};
struct spi_transfer xfer_buf = {
.len = len,
.tx_buf = data,
};
mutex_lock(&lp->bmux);
buf[0] = CMD_WRITE | CMD_FB;
buf[1] = len + 2;
dev_vdbg(&lp->spi->dev, "buf[0] = %02x\n", buf[0]);
dev_vdbg(&lp->spi->dev, "buf[1] = %02x\n", buf[1]);
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
spi_message_add_tail(&xfer_buf, &msg);
status = spi_sync(lp->spi, &msg);
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
if (msg.status)
status = msg.status;
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
dev_vdbg(&lp->spi->dev, "buf[0] = %02x\n", buf[0]);
dev_vdbg(&lp->spi->dev, "buf[1] = %02x\n", buf[1]);
mutex_unlock(&lp->bmux);
return status;
}
static int
at86rf230_read_fbuf(struct at86rf230_local *lp, u8 *data, u8 *len, u8 *lqi)
{
u8 *buf = lp->buf;
int status;
struct spi_message msg;
struct spi_transfer xfer_head = {
.len = 2,
.tx_buf = buf,
.rx_buf = buf,
};
struct spi_transfer xfer_head1 = {
.len = 2,
.tx_buf = buf,
.rx_buf = buf,
};
struct spi_transfer xfer_buf = {
.len = 0,
.rx_buf = data,
};
mutex_lock(&lp->bmux);
buf[0] = CMD_FB;
buf[1] = 0x00;
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
status = spi_sync(lp->spi, &msg);
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
xfer_buf.len = *(buf + 1) + 1;
*len = buf[1];
buf[0] = CMD_FB;
buf[1] = 0x00;
spi_message_init(&msg);
spi_message_add_tail(&xfer_head1, &msg);
spi_message_add_tail(&xfer_buf, &msg);
status = spi_sync(lp->spi, &msg);
if (msg.status)
status = msg.status;
dev_vdbg(&lp->spi->dev, "status = %d\n", status);
dev_vdbg(&lp->spi->dev, "buf[0] = %02x\n", buf[0]);
dev_vdbg(&lp->spi->dev, "buf[1] = %02x\n", buf[1]);
if (status) {
if (lqi && (*len > lp->buf[1]))
*lqi = data[lp->buf[1]];
}
mutex_unlock(&lp->bmux);
return status;
}
static int
at86rf230_ed(struct ieee802154_dev *dev, u8 *level)
{
might_sleep();
BUG_ON(!level);
*level = 0xbe;
return 0;
}
static int
at86rf230_state(struct ieee802154_dev *dev, int state)
{
struct at86rf230_local *lp = dev->priv;
int rc;
u8 val;
u8 desired_status;
might_sleep();
if (state == STATE_FORCE_TX_ON)
desired_status = STATE_TX_ON;
else if (state == STATE_FORCE_TRX_OFF)
desired_status = STATE_TRX_OFF;
else
desired_status = state;
do {
rc = at86rf230_read_subreg(lp, SR_TRX_STATUS, &val);
if (rc)
goto err;
} while (val == STATE_TRANSITION_IN_PROGRESS);
if (val == desired_status)
return 0;
rc = at86rf230_write_subreg(lp, SR_TRX_CMD, state);
if (rc)
goto err;
do {
rc = at86rf230_read_subreg(lp, SR_TRX_STATUS, &val);
if (rc)
goto err;
} while (val == STATE_TRANSITION_IN_PROGRESS);
if (val == desired_status)
return 0;
pr_err("unexpected state change: %d, asked for %d\n", val, state);
return -EBUSY;
err:
pr_err("error: %d\n", rc);
return rc;
}
static int
at86rf230_start(struct ieee802154_dev *dev)
{
struct at86rf230_local *lp = dev->priv;
u8 rc;
rc = at86rf230_write_subreg(lp, SR_RX_SAFE_MODE, 1);
if (rc)
return rc;
return at86rf230_state(dev, STATE_RX_ON);
}
static void
at86rf230_stop(struct ieee802154_dev *dev)
{
at86rf230_state(dev, STATE_FORCE_TRX_OFF);
}
static int
at86rf230_channel(struct ieee802154_dev *dev, int page, int channel)
{
struct at86rf230_local *lp = dev->priv;
int rc;
might_sleep();
if (page != 0 || channel < 11 || channel > 26) {
WARN_ON(1);
return -EINVAL;
}
rc = at86rf230_write_subreg(lp, SR_CHANNEL, channel);
msleep(1);
dev->phy->current_channel = channel;
return 0;
}
static int
at86rf230_xmit(struct ieee802154_dev *dev, struct sk_buff *skb)
{
struct at86rf230_local *lp = dev->priv;
int rc;
unsigned long flags;
spin_lock(&lp->lock);
if (lp->irq_disabled) {
spin_unlock(&lp->lock);
return -EBUSY;
}
spin_unlock(&lp->lock);
might_sleep();
rc = at86rf230_state(dev, STATE_FORCE_TX_ON);
if (rc)
goto err;
spin_lock_irqsave(&lp->lock, flags);
lp->is_tx = 1;
INIT_COMPLETION(lp->tx_complete);
spin_unlock_irqrestore(&lp->lock, flags);
rc = at86rf230_write_fbuf(lp, skb->data, skb->len);
if (rc)
goto err_rx;
rc = at86rf230_write_subreg(lp, SR_TRX_CMD, STATE_BUSY_TX);
if (rc)
goto err_rx;
rc = wait_for_completion_interruptible(&lp->tx_complete);
if (rc < 0)
goto err_rx;
rc = at86rf230_start(dev);
return rc;
err_rx:
at86rf230_start(dev);
err:
pr_err("error: %d\n", rc);
spin_lock_irqsave(&lp->lock, flags);
lp->is_tx = 0;
spin_unlock_irqrestore(&lp->lock, flags);
return rc;
}
static int at86rf230_rx(struct at86rf230_local *lp)
{
u8 len = 128, lqi = 0;
struct sk_buff *skb;
skb = alloc_skb(len, GFP_KERNEL);
if (!skb)
return -ENOMEM;
if (at86rf230_read_fbuf(lp, skb_put(skb, len), &len, &lqi))
goto err;
if (len < 2)
goto err;
skb_trim(skb, len - 2);
ieee802154_rx_irqsafe(lp->dev, skb, lqi);
dev_dbg(&lp->spi->dev, "READ_FBUF: %d %x\n", len, lqi);
return 0;
err:
pr_debug("received frame is too small\n");
kfree_skb(skb);
return -EINVAL;
}
static void at86rf230_irqwork(struct work_struct *work)
{
struct at86rf230_local *lp =
container_of(work, struct at86rf230_local, irqwork);
u8 status = 0, val;
int rc;
unsigned long flags;
rc = at86rf230_read_subreg(lp, RG_IRQ_STATUS, 0xff, 0, &val);
status |= val;
status &= ~IRQ_PLL_LOCK;
status &= ~IRQ_RX_START;
status &= ~IRQ_AMI;
status &= ~IRQ_TRX_UR;
if (status & IRQ_TRX_END) {
spin_lock_irqsave(&lp->lock, flags);
status &= ~IRQ_TRX_END;
if (lp->is_tx) {
lp->is_tx = 0;
spin_unlock_irqrestore(&lp->lock, flags);
complete(&lp->tx_complete);
} else {
spin_unlock_irqrestore(&lp->lock, flags);
at86rf230_rx(lp);
}
}
spin_lock_irqsave(&lp->lock, flags);
lp->irq_disabled = 0;
spin_unlock_irqrestore(&lp->lock, flags);
enable_irq(lp->spi->irq);
}
static irqreturn_t at86rf230_isr(int irq, void *data)
{
struct at86rf230_local *lp = data;
disable_irq_nosync(irq);
spin_lock(&lp->lock);
lp->irq_disabled = 1;
spin_unlock(&lp->lock);
schedule_work(&lp->irqwork);
return IRQ_HANDLED;
}
static int at86rf230_hw_init(struct at86rf230_local *lp)
{
u8 status;
int rc;
rc = at86rf230_read_subreg(lp, SR_TRX_STATUS, &status);
if (rc)
return rc;
dev_info(&lp->spi->dev, "Status: %02x\n", status);
if (status == STATE_P_ON) {
rc = at86rf230_write_subreg(lp, SR_TRX_CMD, STATE_TRX_OFF);
if (rc)
return rc;
msleep(1);
rc = at86rf230_read_subreg(lp, SR_TRX_STATUS, &status);
if (rc)
return rc;
dev_info(&lp->spi->dev, "Status: %02x\n", status);
}
rc = at86rf230_write_subreg(lp, SR_IRQ_MASK, 0xff);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CLKM_SHA_SEL, 0x00);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CLKM_CTRL, 0x00);
if (rc)
return rc;
msleep(100);
rc = at86rf230_write_subreg(lp, SR_TRX_CMD, STATE_TX_ON);
if (rc)
return rc;
msleep(1);
rc = at86rf230_read_subreg(lp, SR_TRX_STATUS, &status);
if (rc)
return rc;
dev_info(&lp->spi->dev, "Status: %02x\n", status);
rc = at86rf230_read_subreg(lp, SR_DVDD_OK, &status);
if (rc)
return rc;
if (!status) {
dev_err(&lp->spi->dev, "DVDD error\n");
return -EINVAL;
}
rc = at86rf230_read_subreg(lp, SR_AVDD_OK, &status);
if (rc)
return rc;
if (!status) {
dev_err(&lp->spi->dev, "AVDD error\n");
return -EINVAL;
}
return 0;
}
static int at86rf230_fill_data(struct spi_device *spi)
{
struct at86rf230_local *lp = spi_get_drvdata(spi);
struct at86rf230_platform_data *pdata = spi->dev.platform_data;
if (!pdata) {
dev_err(&spi->dev, "no platform_data\n");
return -EINVAL;
}
lp->rstn = pdata->rstn;
lp->slp_tr = pdata->slp_tr;
lp->dig2 = pdata->dig2;
return 0;
}
static int at86rf230_probe(struct spi_device *spi)
{
struct ieee802154_dev *dev;
struct at86rf230_local *lp;
u8 man_id_0, man_id_1;
int rc;
const char *chip;
int supported = 0;
if (!spi->irq) {
dev_err(&spi->dev, "no IRQ specified\n");
return -EINVAL;
}
dev = ieee802154_alloc_device(sizeof(*lp), &at86rf230_ops);
if (!dev)
return -ENOMEM;
lp = dev->priv;
lp->dev = dev;
lp->spi = spi;
dev->priv = lp;
dev->parent = &spi->dev;
dev->extra_tx_headroom = 0;
dev->phy->channels_supported[0] = 0x7FFF800;
dev->flags = IEEE802154_HW_OMIT_CKSUM;
mutex_init(&lp->bmux);
INIT_WORK(&lp->irqwork, at86rf230_irqwork);
spin_lock_init(&lp->lock);
init_completion(&lp->tx_complete);
spi_set_drvdata(spi, lp);
rc = at86rf230_fill_data(spi);
if (rc)
goto err_fill;
rc = gpio_request(lp->rstn, "rstn");
if (rc)
goto err_rstn;
if (gpio_is_valid(lp->slp_tr)) {
rc = gpio_request(lp->slp_tr, "slp_tr");
if (rc)
goto err_slp_tr;
}
rc = gpio_direction_output(lp->rstn, 1);
if (rc)
goto err_gpio_dir;
if (gpio_is_valid(lp->slp_tr)) {
rc = gpio_direction_output(lp->slp_tr, 0);
if (rc)
goto err_gpio_dir;
}
msleep(1);
gpio_set_value(lp->rstn, 0);
msleep(1);
gpio_set_value(lp->rstn, 1);
msleep(1);
rc = at86rf230_read_subreg(lp, SR_MAN_ID_0, &man_id_0);
if (rc)
goto err_gpio_dir;
rc = at86rf230_read_subreg(lp, SR_MAN_ID_1, &man_id_1);
if (rc)
goto err_gpio_dir;
if (man_id_1 != 0x00 || man_id_0 != 0x1f) {
dev_err(&spi->dev, "Non-Atmel dev found (MAN_ID %02x %02x)\n",
man_id_1, man_id_0);
rc = -EINVAL;
goto err_gpio_dir;
}
rc = at86rf230_read_subreg(lp, SR_PART_NUM, &lp->part);
if (rc)
goto err_gpio_dir;
rc = at86rf230_read_subreg(lp, SR_VERSION_NUM, &lp->vers);
if (rc)
goto err_gpio_dir;
switch (lp->part) {
case 2:
chip = "at86rf230";
break;
case 3:
chip = "at86rf231";
supported = 1;
break;
default:
chip = "UNKNOWN";
break;
}
dev_info(&spi->dev, "Detected %s chip version %d\n", chip, lp->vers);
if (!supported) {
rc = -ENOTSUPP;
goto err_gpio_dir;
}
rc = at86rf230_hw_init(lp);
if (rc)
goto err_gpio_dir;
rc = request_irq(spi->irq, at86rf230_isr, IRQF_SHARED,
dev_name(&spi->dev), lp);
if (rc)
goto err_gpio_dir;
rc = ieee802154_register_device(lp->dev);
if (rc)
goto err_irq;
return rc;
ieee802154_unregister_device(lp->dev);
err_irq:
free_irq(spi->irq, lp);
flush_work(&lp->irqwork);
err_gpio_dir:
if (gpio_is_valid(lp->slp_tr))
gpio_free(lp->slp_tr);
err_slp_tr:
gpio_free(lp->rstn);
err_rstn:
err_fill:
spi_set_drvdata(spi, NULL);
mutex_destroy(&lp->bmux);
ieee802154_free_device(lp->dev);
return rc;
}
static int at86rf230_remove(struct spi_device *spi)
{
struct at86rf230_local *lp = spi_get_drvdata(spi);
ieee802154_unregister_device(lp->dev);
free_irq(spi->irq, lp);
flush_work(&lp->irqwork);
if (gpio_is_valid(lp->slp_tr))
gpio_free(lp->slp_tr);
gpio_free(lp->rstn);
spi_set_drvdata(spi, NULL);
mutex_destroy(&lp->bmux);
ieee802154_free_device(lp->dev);
dev_dbg(&spi->dev, "unregistered at86rf230\n");
return 0;
}
