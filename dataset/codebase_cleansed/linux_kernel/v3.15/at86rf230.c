static bool is_rf212(struct at86rf230_local *local)
{
return local->part == 7;
}
static int
__at86rf230_detect_device(struct spi_device *spi, u16 *man_id, u8 *part,
u8 *version)
{
u8 data[4];
u8 *buf = kmalloc(2, GFP_KERNEL);
int status;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 2,
.tx_buf = buf,
.rx_buf = buf,
};
u8 reg;
if (!buf)
return -ENOMEM;
for (reg = RG_PART_NUM; reg <= RG_MAN_ID_1; reg++) {
buf[0] = (reg & CMD_REG_MASK) | CMD_REG;
buf[1] = 0xff;
dev_vdbg(&spi->dev, "buf[0] = %02x\n", buf[0]);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
status = spi_sync(spi, &msg);
dev_vdbg(&spi->dev, "status = %d\n", status);
if (msg.status)
status = msg.status;
dev_vdbg(&spi->dev, "status = %d\n", status);
dev_vdbg(&spi->dev, "buf[0] = %02x\n", buf[0]);
dev_vdbg(&spi->dev, "buf[1] = %02x\n", buf[1]);
if (status == 0)
data[reg - RG_PART_NUM] = buf[1];
else
break;
}
if (status == 0) {
*part = data[0];
*version = data[1];
*man_id = (data[3] << 8) | data[2];
}
kfree(buf);
return status;
}
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
*data = (buf[1] & mask) >> shift;
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
if (val == desired_status ||
(desired_status == STATE_RX_ON && val == STATE_BUSY_RX) ||
(desired_status == STATE_RX_AACK_ON && val == STATE_BUSY_RX_AACK))
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
rc = at86rf230_state(dev, STATE_TX_ON);
if (rc)
return rc;
return at86rf230_state(dev, STATE_RX_AACK_ON);
}
static void
at86rf230_stop(struct ieee802154_dev *dev)
{
at86rf230_state(dev, STATE_FORCE_TRX_OFF);
}
static int
at86rf230_set_channel(struct at86rf230_local *lp, int page, int channel)
{
lp->rssi_base_val = -91;
return at86rf230_write_subreg(lp, SR_CHANNEL, channel);
}
static int
at86rf212_set_channel(struct at86rf230_local *lp, int page, int channel)
{
int rc;
if (channel == 0)
rc = at86rf230_write_subreg(lp, SR_SUB_MODE, 0);
else
rc = at86rf230_write_subreg(lp, SR_SUB_MODE, 1);
if (rc < 0)
return rc;
if (page == 0) {
rc = at86rf230_write_subreg(lp, SR_BPSK_QPSK, 0);
lp->rssi_base_val = -100;
} else {
rc = at86rf230_write_subreg(lp, SR_BPSK_QPSK, 1);
lp->rssi_base_val = -98;
}
if (rc < 0)
return rc;
return at86rf230_write_subreg(lp, SR_CHANNEL, channel);
}
static int
at86rf230_channel(struct ieee802154_dev *dev, int page, int channel)
{
struct at86rf230_local *lp = dev->priv;
int rc;
might_sleep();
if (page < 0 || page > 31 ||
!(lp->dev->phy->channels_supported[page] & BIT(channel))) {
WARN_ON(1);
return -EINVAL;
}
if (is_rf212(lp))
rc = at86rf212_set_channel(lp, page, channel);
else
rc = at86rf230_set_channel(lp, page, channel);
if (rc < 0)
return rc;
msleep(1);
dev->phy->current_channel = channel;
dev->phy->current_page = page;
return 0;
}
static int
at86rf230_xmit(struct ieee802154_dev *dev, struct sk_buff *skb)
{
struct at86rf230_local *lp = dev->priv;
int rc;
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
if (lp->irq_busy) {
spin_unlock_irqrestore(&lp->lock, flags);
return -EBUSY;
}
spin_unlock_irqrestore(&lp->lock, flags);
might_sleep();
rc = at86rf230_state(dev, STATE_FORCE_TX_ON);
if (rc)
goto err;
spin_lock_irqsave(&lp->lock, flags);
lp->is_tx = 1;
reinit_completion(&lp->tx_complete);
spin_unlock_irqrestore(&lp->lock, flags);
rc = at86rf230_write_fbuf(lp, skb->data, skb->len);
if (rc)
goto err_rx;
if (lp->tx_aret) {
rc = at86rf230_write_subreg(lp, SR_TRX_CMD, STATE_TX_ARET_ON);
if (rc)
goto err_rx;
}
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
static int
at86rf230_set_hw_addr_filt(struct ieee802154_dev *dev,
struct ieee802154_hw_addr_filt *filt,
unsigned long changed)
{
struct at86rf230_local *lp = dev->priv;
if (changed & IEEE802515_AFILT_SADDR_CHANGED) {
u16 addr = le16_to_cpu(filt->short_addr);
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for saddr\n");
__at86rf230_write(lp, RG_SHORT_ADDR_0, addr);
__at86rf230_write(lp, RG_SHORT_ADDR_1, addr >> 8);
}
if (changed & IEEE802515_AFILT_PANID_CHANGED) {
u16 pan = le16_to_cpu(filt->pan_id);
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for pan id\n");
__at86rf230_write(lp, RG_PAN_ID_0, pan);
__at86rf230_write(lp, RG_PAN_ID_1, pan >> 8);
}
if (changed & IEEE802515_AFILT_IEEEADDR_CHANGED) {
u8 i, addr[8];
memcpy(addr, &filt->ieee_addr, 8);
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for IEEE addr\n");
for (i = 0; i < 8; i++)
__at86rf230_write(lp, RG_IEEE_ADDR_0 + i, addr[i]);
}
if (changed & IEEE802515_AFILT_PANC_CHANGED) {
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for panc change\n");
if (filt->pan_coord)
at86rf230_write_subreg(lp, SR_AACK_I_AM_COORD, 1);
else
at86rf230_write_subreg(lp, SR_AACK_I_AM_COORD, 0);
}
return 0;
}
static int
at86rf212_set_txpower(struct ieee802154_dev *dev, int db)
{
struct at86rf230_local *lp = dev->priv;
if (db > 5 || db < -26)
return -EINVAL;
db = -(db - 5);
return __at86rf230_write(lp, RG_PHY_TX_PWR, 0x60 | db);
}
static int
at86rf212_set_lbt(struct ieee802154_dev *dev, bool on)
{
struct at86rf230_local *lp = dev->priv;
return at86rf230_write_subreg(lp, SR_CSMA_LBT_MODE, on);
}
static int
at86rf212_set_cca_mode(struct ieee802154_dev *dev, u8 mode)
{
struct at86rf230_local *lp = dev->priv;
return at86rf230_write_subreg(lp, SR_CCA_MODE, mode);
}
static int
at86rf212_set_cca_ed_level(struct ieee802154_dev *dev, s32 level)
{
struct at86rf230_local *lp = dev->priv;
int desens_steps;
if (level < lp->rssi_base_val || level > 30)
return -EINVAL;
desens_steps = (level - lp->rssi_base_val) * 100 / 207;
return at86rf230_write_subreg(lp, SR_CCA_ED_THRES, desens_steps);
}
static int
at86rf212_set_csma_params(struct ieee802154_dev *dev, u8 min_be, u8 max_be,
u8 retries)
{
struct at86rf230_local *lp = dev->priv;
int rc;
if (min_be > max_be || max_be > 8 || retries > 5)
return -EINVAL;
rc = at86rf230_write_subreg(lp, SR_MIN_BE, min_be);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_MAX_BE, max_be);
if (rc)
return rc;
return at86rf230_write_subreg(lp, SR_MAX_CSMA_RETRIES, retries);
}
static int
at86rf212_set_frame_retries(struct ieee802154_dev *dev, s8 retries)
{
struct at86rf230_local *lp = dev->priv;
int rc = 0;
if (retries < -1 || retries > 15)
return -EINVAL;
lp->tx_aret = retries >= 0;
if (retries >= 0)
rc = at86rf230_write_subreg(lp, SR_MAX_FRAME_RETRIES, retries);
return rc;
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
status &= ~IRQ_TRX_END;
spin_lock_irqsave(&lp->lock, flags);
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
lp->irq_busy = 0;
spin_unlock_irqrestore(&lp->lock, flags);
}
static void at86rf230_irqwork_level(struct work_struct *work)
{
struct at86rf230_local *lp =
container_of(work, struct at86rf230_local, irqwork);
at86rf230_irqwork(work);
enable_irq(lp->spi->irq);
}
static irqreturn_t at86rf230_isr(int irq, void *data)
{
struct at86rf230_local *lp = data;
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
lp->irq_busy = 1;
spin_unlock_irqrestore(&lp->lock, flags);
schedule_work(&lp->irqwork);
return IRQ_HANDLED;
}
static irqreturn_t at86rf230_isr_level(int irq, void *data)
{
disable_irq_nosync(irq);
return at86rf230_isr(irq, data);
}
static int at86rf230_irq_polarity(struct at86rf230_local *lp, int pol)
{
return at86rf230_write_subreg(lp, SR_IRQ_POLARITY, pol);
}
static int at86rf230_hw_init(struct at86rf230_local *lp)
{
struct at86rf230_platform_data *pdata = lp->spi->dev.platform_data;
int rc, irq_pol;
u8 status;
u8 csma_seed[2];
rc = at86rf230_read_subreg(lp, SR_TRX_STATUS, &status);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_TRX_CMD, STATE_FORCE_TRX_OFF);
if (rc)
return rc;
if (pdata->irq_type & (IRQF_TRIGGER_FALLING | IRQF_TRIGGER_LOW))
irq_pol = IRQ_ACTIVE_LOW;
else
irq_pol = IRQ_ACTIVE_HIGH;
rc = at86rf230_irq_polarity(lp, irq_pol);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_IRQ_MASK, IRQ_TRX_END);
if (rc)
return rc;
get_random_bytes(csma_seed, ARRAY_SIZE(csma_seed));
rc = at86rf230_write_subreg(lp, SR_CSMA_SEED_0, csma_seed[0]);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CSMA_SEED_1, csma_seed[1]);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CLKM_SHA_SEL, 0x00);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CLKM_CTRL, 0x00);
if (rc)
return rc;
msleep(100);
rc = at86rf230_read_subreg(lp, SR_DVDD_OK, &status);
if (rc)
return rc;
if (!status) {
dev_err(&lp->spi->dev, "DVDD error\n");
return -EINVAL;
}
return 0;
}
static struct at86rf230_platform_data *
at86rf230_get_pdata(struct spi_device *spi)
{
struct at86rf230_platform_data *pdata;
const char *irq_type;
if (!IS_ENABLED(CONFIG_OF) || !spi->dev.of_node)
return spi->dev.platform_data;
pdata = devm_kzalloc(&spi->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
goto done;
pdata->rstn = of_get_named_gpio(spi->dev.of_node, "reset-gpio", 0);
pdata->slp_tr = of_get_named_gpio(spi->dev.of_node, "sleep-gpio", 0);
pdata->irq_type = IRQF_TRIGGER_RISING;
of_property_read_string(spi->dev.of_node, "irq-type", &irq_type);
if (!strcmp(irq_type, "level-high"))
pdata->irq_type = IRQF_TRIGGER_HIGH;
else if (!strcmp(irq_type, "level-low"))
pdata->irq_type = IRQF_TRIGGER_LOW;
else if (!strcmp(irq_type, "edge-rising"))
pdata->irq_type = IRQF_TRIGGER_RISING;
else if (!strcmp(irq_type, "edge-falling"))
pdata->irq_type = IRQF_TRIGGER_FALLING;
else
dev_warn(&spi->dev, "wrong irq-type specified using edge-rising\n");
spi->dev.platform_data = pdata;
done:
return pdata;
}
static int at86rf230_probe(struct spi_device *spi)
{
struct at86rf230_platform_data *pdata;
struct ieee802154_dev *dev;
struct at86rf230_local *lp;
u16 man_id = 0;
u8 part = 0, version = 0, status;
irq_handler_t irq_handler;
work_func_t irq_worker;
int rc;
const char *chip;
struct ieee802154_ops *ops = NULL;
if (!spi->irq) {
dev_err(&spi->dev, "no IRQ specified\n");
return -EINVAL;
}
pdata = at86rf230_get_pdata(spi);
if (!pdata) {
dev_err(&spi->dev, "no platform_data\n");
return -EINVAL;
}
if (gpio_is_valid(pdata->rstn)) {
rc = gpio_request(pdata->rstn, "rstn");
if (rc)
return rc;
}
if (gpio_is_valid(pdata->slp_tr)) {
rc = gpio_request(pdata->slp_tr, "slp_tr");
if (rc)
goto err_slp_tr;
}
if (gpio_is_valid(pdata->rstn)) {
rc = gpio_direction_output(pdata->rstn, 1);
if (rc)
goto err_gpio_dir;
}
if (gpio_is_valid(pdata->slp_tr)) {
rc = gpio_direction_output(pdata->slp_tr, 0);
if (rc)
goto err_gpio_dir;
}
if (gpio_is_valid(pdata->rstn)) {
udelay(1);
gpio_set_value(pdata->rstn, 0);
udelay(1);
gpio_set_value(pdata->rstn, 1);
usleep_range(120, 240);
}
rc = __at86rf230_detect_device(spi, &man_id, &part, &version);
if (rc < 0)
goto err_gpio_dir;
if (man_id != 0x001f) {
dev_err(&spi->dev, "Non-Atmel dev found (MAN_ID %02x %02x)\n",
man_id >> 8, man_id & 0xFF);
rc = -EINVAL;
goto err_gpio_dir;
}
switch (part) {
case 2:
chip = "at86rf230";
break;
case 3:
chip = "at86rf231";
ops = &at86rf230_ops;
break;
case 7:
chip = "at86rf212";
if (version == 1)
ops = &at86rf212_ops;
break;
case 11:
chip = "at86rf233";
ops = &at86rf230_ops;
break;
default:
chip = "UNKNOWN";
break;
}
dev_info(&spi->dev, "Detected %s chip version %d\n", chip, version);
if (!ops) {
rc = -ENOTSUPP;
goto err_gpio_dir;
}
dev = ieee802154_alloc_device(sizeof(*lp), ops);
if (!dev) {
rc = -ENOMEM;
goto err_gpio_dir;
}
lp = dev->priv;
lp->dev = dev;
lp->part = part;
lp->vers = version;
lp->spi = spi;
dev->parent = &spi->dev;
dev->extra_tx_headroom = 0;
dev->flags = IEEE802154_HW_OMIT_CKSUM | IEEE802154_HW_AACK;
if (pdata->irq_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)) {
irq_worker = at86rf230_irqwork;
irq_handler = at86rf230_isr;
} else {
irq_worker = at86rf230_irqwork_level;
irq_handler = at86rf230_isr_level;
}
mutex_init(&lp->bmux);
INIT_WORK(&lp->irqwork, irq_worker);
spin_lock_init(&lp->lock);
init_completion(&lp->tx_complete);
spi_set_drvdata(spi, lp);
if (is_rf212(lp)) {
dev->phy->channels_supported[0] = 0x00007FF;
dev->phy->channels_supported[2] = 0x00007FF;
} else {
dev->phy->channels_supported[0] = 0x7FFF800;
}
rc = at86rf230_hw_init(lp);
if (rc)
goto err_hw_init;
rc = request_irq(spi->irq, irq_handler,
IRQF_SHARED | pdata->irq_type,
dev_name(&spi->dev), lp);
if (rc)
goto err_hw_init;
rc = at86rf230_read_subreg(lp, RG_IRQ_STATUS, 0xff, 0, &status);
if (rc)
goto err_irq;
rc = ieee802154_register_device(lp->dev);
if (rc)
goto err_irq;
return rc;
err_irq:
free_irq(spi->irq, lp);
err_hw_init:
flush_work(&lp->irqwork);
spi_set_drvdata(spi, NULL);
mutex_destroy(&lp->bmux);
ieee802154_free_device(lp->dev);
err_gpio_dir:
if (gpio_is_valid(pdata->slp_tr))
gpio_free(pdata->slp_tr);
err_slp_tr:
if (gpio_is_valid(pdata->rstn))
gpio_free(pdata->rstn);
return rc;
}
static int at86rf230_remove(struct spi_device *spi)
{
struct at86rf230_local *lp = spi_get_drvdata(spi);
struct at86rf230_platform_data *pdata = spi->dev.platform_data;
at86rf230_write_subreg(lp, SR_IRQ_MASK, 0);
ieee802154_unregister_device(lp->dev);
free_irq(spi->irq, lp);
flush_work(&lp->irqwork);
if (gpio_is_valid(pdata->slp_tr))
gpio_free(pdata->slp_tr);
if (gpio_is_valid(pdata->rstn))
gpio_free(pdata->rstn);
mutex_destroy(&lp->bmux);
ieee802154_free_device(lp->dev);
dev_dbg(&spi->dev, "unregistered at86rf230\n");
return 0;
}
