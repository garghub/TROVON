static int trf7970a_cmd(struct trf7970a *trf, u8 opcode)
{
u8 cmd = TRF7970A_CMD_BIT_CTRL | TRF7970A_CMD_BIT_OPCODE(opcode);
int ret;
dev_dbg(trf->dev, "cmd: 0x%x\n", cmd);
ret = spi_write(trf->spi, &cmd, 1);
if (ret)
dev_err(trf->dev, "%s - cmd: 0x%x, ret: %d\n", __func__, cmd,
ret);
return ret;
}
static int trf7970a_read(struct trf7970a *trf, u8 reg, u8 *val)
{
u8 addr = TRF7970A_CMD_BIT_RW | reg;
int ret;
ret = spi_write_then_read(trf->spi, &addr, 1, val, 1);
if (ret)
dev_err(trf->dev, "%s - addr: 0x%x, ret: %d\n", __func__, addr,
ret);
dev_dbg(trf->dev, "read(0x%x): 0x%x\n", addr, *val);
return ret;
}
static int trf7970a_read_cont(struct trf7970a *trf, u8 reg,
u8 *buf, size_t len)
{
u8 addr = reg | TRF7970A_CMD_BIT_RW | TRF7970A_CMD_BIT_CONTINUOUS;
int ret;
dev_dbg(trf->dev, "read_cont(0x%x, %zd)\n", addr, len);
ret = spi_write_then_read(trf->spi, &addr, 1, buf, len);
if (ret)
dev_err(trf->dev, "%s - addr: 0x%x, ret: %d\n", __func__, addr,
ret);
return ret;
}
static int trf7970a_write(struct trf7970a *trf, u8 reg, u8 val)
{
u8 buf[2] = { reg, val };
int ret;
dev_dbg(trf->dev, "write(0x%x): 0x%x\n", reg, val);
ret = spi_write(trf->spi, buf, 2);
if (ret)
dev_err(trf->dev, "%s - write: 0x%x 0x%x, ret: %d\n", __func__,
buf[0], buf[1], ret);
return ret;
}
static int trf7970a_read_irqstatus(struct trf7970a *trf, u8 *status)
{
int ret;
u8 buf[2];
u8 addr;
addr = TRF7970A_IRQ_STATUS | TRF7970A_CMD_BIT_RW;
if (trf->quirks & TRF7970A_QUIRK_IRQ_STATUS_READ_ERRATA) {
addr |= TRF7970A_CMD_BIT_CONTINUOUS;
ret = spi_write_then_read(trf->spi, &addr, 1, buf, 2);
} else {
ret = spi_write_then_read(trf->spi, &addr, 1, buf, 1);
}
if (ret)
dev_err(trf->dev, "%s - irqstatus: Status read failed: %d\n",
__func__, ret);
else
*status = buf[0];
return ret;
}
static void trf7970a_send_upstream(struct trf7970a *trf)
{
u8 rssi;
dev_kfree_skb_any(trf->tx_skb);
trf->tx_skb = NULL;
if (trf->rx_skb && !IS_ERR(trf->rx_skb) && !trf->aborting)
print_hex_dump_debug("trf7970a rx data: ", DUMP_PREFIX_NONE,
16, 1, trf->rx_skb->data, trf->rx_skb->len,
false);
trf7970a_cmd(trf, TRF7970A_CMD_FIFO_RESET);
trf7970a_read(trf, TRF7970A_RSSI_OSC_STATUS, &rssi);
trf->state = TRF7970A_ST_IDLE;
if (trf->aborting) {
dev_dbg(trf->dev, "Abort process complete\n");
if (!IS_ERR(trf->rx_skb)) {
kfree_skb(trf->rx_skb);
trf->rx_skb = ERR_PTR(-ECANCELED);
}
trf->aborting = false;
}
trf->cb(trf->ddev, trf->cb_arg, trf->rx_skb);
trf->rx_skb = NULL;
}
static void trf7970a_send_err_upstream(struct trf7970a *trf, int errno)
{
dev_dbg(trf->dev, "Error - state: %d, errno: %d\n", trf->state, errno);
kfree_skb(trf->rx_skb);
trf->rx_skb = ERR_PTR(errno);
trf7970a_send_upstream(trf);
}
static int trf7970a_transmit(struct trf7970a *trf, struct sk_buff *skb,
unsigned int len)
{
unsigned int timeout;
int ret;
print_hex_dump_debug("trf7970a tx data: ", DUMP_PREFIX_NONE,
16, 1, skb->data, len, false);
ret = spi_write(trf->spi, skb->data, len);
if (ret) {
dev_err(trf->dev, "%s - Can't send tx data: %d\n", __func__,
ret);
return ret;
}
skb_pull(skb, len);
if (skb->len > 0) {
trf->state = TRF7970A_ST_WAIT_FOR_TX_FIFO;
timeout = TRF7970A_WAIT_FOR_FIFO_DRAIN_TIMEOUT;
} else {
if (trf->issue_eof) {
trf->state = TRF7970A_ST_WAIT_TO_ISSUE_EOF;
timeout = TRF7970A_WAIT_TO_ISSUE_ISO15693_EOF;
} else {
trf->state = TRF7970A_ST_WAIT_FOR_RX_DATA;
timeout = trf->timeout;
}
}
dev_dbg(trf->dev, "Setting timeout for %d ms, state: %d\n", timeout,
trf->state);
schedule_delayed_work(&trf->timeout_work, msecs_to_jiffies(timeout));
return 0;
}
static void trf7970a_fill_fifo(struct trf7970a *trf)
{
struct sk_buff *skb = trf->tx_skb;
unsigned int len;
int ret;
u8 fifo_bytes;
ret = trf7970a_read(trf, TRF7970A_FIFO_STATUS, &fifo_bytes);
if (ret) {
trf7970a_send_err_upstream(trf, ret);
return;
}
dev_dbg(trf->dev, "Filling FIFO - fifo_bytes: 0x%x\n", fifo_bytes);
if (fifo_bytes & TRF7970A_FIFO_STATUS_OVERFLOW) {
dev_err(trf->dev, "%s - fifo overflow: 0x%x\n", __func__,
fifo_bytes);
trf7970a_send_err_upstream(trf, -EIO);
return;
}
len = TRF7970A_FIFO_SIZE - fifo_bytes;
len = min(skb->len, len);
ret = trf7970a_transmit(trf, skb, len);
if (ret)
trf7970a_send_err_upstream(trf, ret);
}
static void trf7970a_drain_fifo(struct trf7970a *trf, u8 status)
{
struct sk_buff *skb = trf->rx_skb;
int ret;
u8 fifo_bytes;
if (status & TRF7970A_IRQ_STATUS_ERROR) {
trf7970a_send_err_upstream(trf, -EIO);
return;
}
ret = trf7970a_read(trf, TRF7970A_FIFO_STATUS, &fifo_bytes);
if (ret) {
trf7970a_send_err_upstream(trf, ret);
return;
}
dev_dbg(trf->dev, "Draining FIFO - fifo_bytes: 0x%x\n", fifo_bytes);
if (!fifo_bytes)
goto no_rx_data;
if (fifo_bytes & TRF7970A_FIFO_STATUS_OVERFLOW) {
dev_err(trf->dev, "%s - fifo overflow: 0x%x\n", __func__,
fifo_bytes);
trf7970a_send_err_upstream(trf, -EIO);
return;
}
if (fifo_bytes > skb_tailroom(skb)) {
skb = skb_copy_expand(skb, skb_headroom(skb),
max_t(int, fifo_bytes,
TRF7970A_RX_SKB_ALLOC_SIZE),
GFP_KERNEL);
if (!skb) {
trf7970a_send_err_upstream(trf, -ENOMEM);
return;
}
kfree_skb(trf->rx_skb);
trf->rx_skb = skb;
}
ret = trf7970a_read_cont(trf, TRF7970A_FIFO_IO_REGISTER,
skb_put(skb, fifo_bytes), fifo_bytes);
if (ret) {
trf7970a_send_err_upstream(trf, ret);
return;
}
if ((trf->framing == NFC_DIGITAL_FRAMING_NFCA_T2T) && (skb->len == 1) &&
(trf->special_fcn_reg1 ==
TRF7970A_SPECIAL_FCN_REG1_4_BIT_RX)) {
skb->data[0] >>= 4;
status = TRF7970A_IRQ_STATUS_SRX;
} else {
trf->state = TRF7970A_ST_WAIT_FOR_RX_DATA_CONT;
}
no_rx_data:
if (status == TRF7970A_IRQ_STATUS_SRX) {
trf7970a_send_upstream(trf);
return;
}
dev_dbg(trf->dev, "Setting timeout for %d ms\n",
TRF7970A_WAIT_FOR_RX_DATA_TIMEOUT);
schedule_delayed_work(&trf->timeout_work,
msecs_to_jiffies(TRF7970A_WAIT_FOR_RX_DATA_TIMEOUT));
}
static irqreturn_t trf7970a_irq(int irq, void *dev_id)
{
struct trf7970a *trf = dev_id;
int ret;
u8 status;
mutex_lock(&trf->lock);
if (trf->state == TRF7970A_ST_OFF) {
mutex_unlock(&trf->lock);
return IRQ_NONE;
}
ret = trf7970a_read_irqstatus(trf, &status);
if (ret) {
mutex_unlock(&trf->lock);
return IRQ_NONE;
}
dev_dbg(trf->dev, "IRQ - state: %d, status: 0x%x\n", trf->state,
status);
if (!status) {
mutex_unlock(&trf->lock);
return IRQ_NONE;
}
switch (trf->state) {
case TRF7970A_ST_IDLE:
case TRF7970A_ST_IDLE_RX_BLOCKED:
if (status & TRF7970A_IRQ_STATUS_ERROR) {
trf7970a_cmd(trf, TRF7970A_CMD_BLOCK_RX);
trf->state = TRF7970A_ST_IDLE_RX_BLOCKED;
}
trf7970a_cmd(trf, TRF7970A_CMD_FIFO_RESET);
break;
case TRF7970A_ST_WAIT_FOR_TX_FIFO:
if (status & TRF7970A_IRQ_STATUS_TX) {
trf->ignore_timeout =
!cancel_delayed_work(&trf->timeout_work);
trf7970a_fill_fifo(trf);
} else {
trf7970a_send_err_upstream(trf, -EIO);
}
break;
case TRF7970A_ST_WAIT_FOR_RX_DATA:
case TRF7970A_ST_WAIT_FOR_RX_DATA_CONT:
if (status & TRF7970A_IRQ_STATUS_SRX) {
trf->ignore_timeout =
!cancel_delayed_work(&trf->timeout_work);
trf7970a_drain_fifo(trf, status);
} else if (!(status & TRF7970A_IRQ_STATUS_TX)) {
trf7970a_send_err_upstream(trf, -EIO);
}
break;
case TRF7970A_ST_WAIT_TO_ISSUE_EOF:
if (status != TRF7970A_IRQ_STATUS_TX)
trf7970a_send_err_upstream(trf, -EIO);
break;
default:
dev_err(trf->dev, "%s - Driver in invalid state: %d\n",
__func__, trf->state);
}
mutex_unlock(&trf->lock);
return IRQ_HANDLED;
}
static void trf7970a_issue_eof(struct trf7970a *trf)
{
int ret;
dev_dbg(trf->dev, "Issuing EOF\n");
ret = trf7970a_cmd(trf, TRF7970A_CMD_FIFO_RESET);
if (ret)
trf7970a_send_err_upstream(trf, ret);
ret = trf7970a_cmd(trf, TRF7970A_CMD_EOF);
if (ret)
trf7970a_send_err_upstream(trf, ret);
trf->state = TRF7970A_ST_WAIT_FOR_RX_DATA;
dev_dbg(trf->dev, "Setting timeout for %d ms, state: %d\n",
trf->timeout, trf->state);
schedule_delayed_work(&trf->timeout_work,
msecs_to_jiffies(trf->timeout));
}
static void trf7970a_timeout_work_handler(struct work_struct *work)
{
struct trf7970a *trf = container_of(work, struct trf7970a,
timeout_work.work);
dev_dbg(trf->dev, "Timeout - state: %d, ignore_timeout: %d\n",
trf->state, trf->ignore_timeout);
mutex_lock(&trf->lock);
if (trf->ignore_timeout)
trf->ignore_timeout = false;
else if (trf->state == TRF7970A_ST_WAIT_FOR_RX_DATA_CONT)
trf7970a_send_upstream(trf);
else if (trf->state == TRF7970A_ST_WAIT_TO_ISSUE_EOF)
trf7970a_issue_eof(trf);
else
trf7970a_send_err_upstream(trf, -ETIMEDOUT);
mutex_unlock(&trf->lock);
}
static int trf7970a_init(struct trf7970a *trf)
{
int ret;
dev_dbg(trf->dev, "Initializing device - state: %d\n", trf->state);
ret = trf7970a_cmd(trf, TRF7970A_CMD_SOFT_INIT);
if (ret)
goto err_out;
ret = trf7970a_cmd(trf, TRF7970A_CMD_IDLE);
if (ret)
goto err_out;
ret = trf7970a_write(trf, TRF7970A_MODULATOR_SYS_CLK_CTRL,
TRF7970A_MODULATOR_DEPTH_OOK);
if (ret)
goto err_out;
ret = trf7970a_write(trf, TRF7970A_ADJUTABLE_FIFO_IRQ_LEVELS,
TRF7970A_ADJUTABLE_FIFO_IRQ_LEVELS_WLH_96 |
TRF7970A_ADJUTABLE_FIFO_IRQ_LEVELS_WLL_32);
if (ret)
goto err_out;
ret = trf7970a_write(trf, TRF7970A_SPECIAL_FCN_REG1, 0);
if (ret)
goto err_out;
trf->special_fcn_reg1 = 0;
ret = trf7970a_write(trf, TRF7970A_CHIP_STATUS_CTRL,
TRF7970A_CHIP_STATUS_RF_ON |
TRF7970A_CHIP_STATUS_VRS5_3);
if (ret)
goto err_out;
return 0;
err_out:
dev_dbg(trf->dev, "Couldn't init device: %d\n", ret);
return ret;
}
static void trf7970a_switch_rf_off(struct trf7970a *trf)
{
dev_dbg(trf->dev, "Switching rf off\n");
gpio_set_value(trf->en_gpio, 0);
gpio_set_value(trf->en2_gpio, 0);
trf->aborting = false;
trf->state = TRF7970A_ST_OFF;
}
static int trf7970a_switch_rf_on(struct trf7970a *trf)
{
unsigned long delay;
int ret;
dev_dbg(trf->dev, "Switching rf on\n");
if (trf->powering_up)
usleep_range(5000, 6000);
gpio_set_value(trf->en2_gpio, 1);
usleep_range(1000, 2000);
gpio_set_value(trf->en_gpio, 1);
if (trf->powering_up) {
delay = 20000;
trf->powering_up = false;
} else {
delay = 5000;
}
usleep_range(delay, delay + 1000);
ret = trf7970a_init(trf);
if (ret)
trf7970a_switch_rf_off(trf);
else
trf->state = TRF7970A_ST_IDLE;
return ret;
}
static int trf7970a_switch_rf(struct nfc_digital_dev *ddev, bool on)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
int ret = 0;
dev_dbg(trf->dev, "Switching RF - state: %d, on: %d\n", trf->state, on);
mutex_lock(&trf->lock);
if (on) {
switch (trf->state) {
case TRF7970A_ST_OFF:
ret = trf7970a_switch_rf_on(trf);
break;
case TRF7970A_ST_IDLE:
case TRF7970A_ST_IDLE_RX_BLOCKED:
break;
default:
dev_err(trf->dev, "%s - Invalid request: %d %d\n",
__func__, trf->state, on);
trf7970a_switch_rf_off(trf);
}
} else {
switch (trf->state) {
case TRF7970A_ST_OFF:
break;
default:
dev_err(trf->dev, "%s - Invalid request: %d %d\n",
__func__, trf->state, on);
case TRF7970A_ST_IDLE:
case TRF7970A_ST_IDLE_RX_BLOCKED:
trf7970a_switch_rf_off(trf);
}
}
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_config_rf_tech(struct trf7970a *trf, int tech)
{
int ret = 0;
dev_dbg(trf->dev, "rf technology: %d\n", tech);
switch (tech) {
case NFC_DIGITAL_RF_TECH_106A:
trf->iso_ctrl = TRF7970A_ISO_CTRL_14443A_106;
break;
case NFC_DIGITAL_RF_TECH_ISO15693:
trf->iso_ctrl = TRF7970A_ISO_CTRL_15693_SGL_1OF4_2648;
break;
default:
dev_dbg(trf->dev, "Unsupported rf technology: %d\n", tech);
return -EINVAL;
}
trf->technology = tech;
return ret;
}
static int trf7970a_config_framing(struct trf7970a *trf, int framing)
{
dev_dbg(trf->dev, "framing: %d\n", framing);
switch (framing) {
case NFC_DIGITAL_FRAMING_NFCA_SHORT:
case NFC_DIGITAL_FRAMING_NFCA_STANDARD:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT_NO_CRC;
trf->iso_ctrl |= TRF7970A_ISO_CTRL_RX_CRC_N;
break;
case NFC_DIGITAL_FRAMING_NFCA_STANDARD_WITH_CRC_A:
case NFC_DIGITAL_FRAMING_NFCA_T4T:
case NFC_DIGITAL_FRAMING_ISO15693_INVENTORY:
case NFC_DIGITAL_FRAMING_ISO15693_T5T:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT;
trf->iso_ctrl &= ~TRF7970A_ISO_CTRL_RX_CRC_N;
break;
case NFC_DIGITAL_FRAMING_NFCA_T2T:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT;
trf->iso_ctrl |= TRF7970A_ISO_CTRL_RX_CRC_N;
break;
default:
dev_dbg(trf->dev, "Unsupported Framing: %d\n", framing);
return -EINVAL;
}
trf->framing = framing;
return trf7970a_write(trf, TRF7970A_ISO_CTRL, trf->iso_ctrl);
}
static int trf7970a_in_configure_hw(struct nfc_digital_dev *ddev, int type,
int param)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
int ret = 0;
dev_dbg(trf->dev, "Configure hw - type: %d, param: %d\n", type, param);
mutex_lock(&trf->lock);
if (trf->state == TRF7970A_ST_OFF) {
ret = trf7970a_switch_rf_on(trf);
if (ret)
goto err_out;
}
switch (type) {
case NFC_DIGITAL_CONFIG_RF_TECH:
ret = trf7970a_config_rf_tech(trf, param);
break;
case NFC_DIGITAL_CONFIG_FRAMING:
ret = trf7970a_config_framing(trf, param);
break;
default:
dev_dbg(trf->dev, "Unknown type: %d\n", type);
ret = -EINVAL;
}
err_out:
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_is_iso15693_write_or_lock(u8 cmd)
{
switch (cmd) {
case ISO15693_CMD_WRITE_SINGLE_BLOCK:
case ISO15693_CMD_LOCK_BLOCK:
case ISO15693_CMD_WRITE_MULTIPLE_BLOCK:
case ISO15693_CMD_WRITE_AFI:
case ISO15693_CMD_LOCK_AFI:
case ISO15693_CMD_WRITE_DSFID:
case ISO15693_CMD_LOCK_DSFID:
return 1;
break;
default:
return 0;
}
}
static int trf7970a_per_cmd_config(struct trf7970a *trf, struct sk_buff *skb)
{
u8 *req = skb->data;
u8 special_fcn_reg1, iso_ctrl;
int ret;
trf->issue_eof = false;
if ((trf->technology == NFC_DIGITAL_RF_TECH_106A) &&
(trf->framing == NFC_DIGITAL_FRAMING_NFCA_T2T)) {
if (req[0] == NFC_T2T_CMD_READ)
special_fcn_reg1 = 0;
else
special_fcn_reg1 = TRF7970A_SPECIAL_FCN_REG1_4_BIT_RX;
if (special_fcn_reg1 != trf->special_fcn_reg1) {
ret = trf7970a_write(trf, TRF7970A_SPECIAL_FCN_REG1,
special_fcn_reg1);
if (ret)
return ret;
trf->special_fcn_reg1 = special_fcn_reg1;
}
} else if (trf->technology == NFC_DIGITAL_RF_TECH_ISO15693) {
iso_ctrl = trf->iso_ctrl & ~TRF7970A_ISO_CTRL_RFID_SPEED_MASK;
switch (req[0] & ISO15693_REQ_FLAG_SPEED_MASK) {
case 0x00:
iso_ctrl |= TRF7970A_ISO_CTRL_15693_SGL_1OF4_662;
break;
case ISO15693_REQ_FLAG_SUB_CARRIER:
iso_ctrl |= TRF7970A_ISO_CTRL_15693_DBL_1OF4_667a;
break;
case ISO15693_REQ_FLAG_DATA_RATE:
iso_ctrl |= TRF7970A_ISO_CTRL_15693_SGL_1OF4_2648;
break;
case (ISO15693_REQ_FLAG_SUB_CARRIER |
ISO15693_REQ_FLAG_DATA_RATE):
iso_ctrl |= TRF7970A_ISO_CTRL_15693_DBL_1OF4_2669;
break;
}
if (iso_ctrl != trf->iso_ctrl) {
ret = trf7970a_write(trf, TRF7970A_ISO_CTRL, iso_ctrl);
if (ret)
return ret;
trf->iso_ctrl = iso_ctrl;
}
if ((trf->framing == NFC_DIGITAL_FRAMING_ISO15693_T5T) &&
trf7970a_is_iso15693_write_or_lock(req[1]) &&
(req[0] & ISO15693_REQ_FLAG_OPTION))
trf->issue_eof = true;
}
return 0;
}
static int trf7970a_in_send_cmd(struct nfc_digital_dev *ddev,
struct sk_buff *skb, u16 timeout,
nfc_digital_cmd_complete_t cb, void *arg)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
char *prefix;
unsigned int len;
int ret;
dev_dbg(trf->dev, "New request - state: %d, timeout: %d ms, len: %d\n",
trf->state, timeout, skb->len);
if (skb->len > TRF7970A_TX_MAX)
return -EINVAL;
mutex_lock(&trf->lock);
if ((trf->state != TRF7970A_ST_IDLE) &&
(trf->state != TRF7970A_ST_IDLE_RX_BLOCKED)) {
dev_err(trf->dev, "%s - Bogus state: %d\n", __func__,
trf->state);
ret = -EIO;
goto out_err;
}
if (trf->aborting) {
dev_dbg(trf->dev, "Abort process complete\n");
trf->aborting = false;
ret = -ECANCELED;
goto out_err;
}
trf->rx_skb = nfc_alloc_recv_skb(TRF7970A_RX_SKB_ALLOC_SIZE,
GFP_KERNEL);
if (!trf->rx_skb) {
dev_dbg(trf->dev, "Can't alloc rx_skb\n");
ret = -ENOMEM;
goto out_err;
}
if (trf->state == TRF7970A_ST_IDLE_RX_BLOCKED) {
ret = trf7970a_cmd(trf, TRF7970A_CMD_ENABLE_RX);
if (ret)
goto out_err;
trf->state = TRF7970A_ST_IDLE;
}
ret = trf7970a_per_cmd_config(trf, skb);
if (ret)
goto out_err;
trf->ddev = ddev;
trf->tx_skb = skb;
trf->cb = cb;
trf->cb_arg = arg;
trf->timeout = timeout;
trf->ignore_timeout = false;
len = skb->len;
prefix = skb_push(skb, TRF7970A_TX_SKB_HEADROOM);
prefix[0] = TRF7970A_CMD_BIT_CTRL |
TRF7970A_CMD_BIT_OPCODE(TRF7970A_CMD_FIFO_RESET);
prefix[1] = TRF7970A_CMD_BIT_CTRL |
TRF7970A_CMD_BIT_OPCODE(trf->tx_cmd);
prefix[2] = TRF7970A_CMD_BIT_CONTINUOUS | TRF7970A_TX_LENGTH_BYTE1;
if (trf->framing == NFC_DIGITAL_FRAMING_NFCA_SHORT) {
prefix[3] = 0x00;
prefix[4] = 0x0f;
} else {
prefix[3] = (len & 0xf00) >> 4;
prefix[3] |= ((len & 0xf0) >> 4);
prefix[4] = ((len & 0x0f) << 4);
}
len = min_t(int, skb->len, TRF7970A_FIFO_SIZE);
usleep_range(1000, 2000);
ret = trf7970a_transmit(trf, skb, len);
if (ret) {
kfree_skb(trf->rx_skb);
trf->rx_skb = NULL;
}
out_err:
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_tg_configure_hw(struct nfc_digital_dev *ddev,
int type, int param)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Unsupported interface\n");
return -EINVAL;
}
static int trf7970a_tg_send_cmd(struct nfc_digital_dev *ddev,
struct sk_buff *skb, u16 timeout,
nfc_digital_cmd_complete_t cb, void *arg)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Unsupported interface\n");
return -EINVAL;
}
static int trf7970a_tg_listen(struct nfc_digital_dev *ddev,
u16 timeout, nfc_digital_cmd_complete_t cb, void *arg)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Unsupported interface\n");
return -EINVAL;
}
static int trf7970a_tg_listen_mdaa(struct nfc_digital_dev *ddev,
struct digital_tg_mdaa_params *mdaa_params,
u16 timeout, nfc_digital_cmd_complete_t cb, void *arg)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Unsupported interface\n");
return -EINVAL;
}
static void trf7970a_abort_cmd(struct nfc_digital_dev *ddev)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Abort process initiated\n");
mutex_lock(&trf->lock);
trf->aborting = true;
mutex_unlock(&trf->lock);
}
static int trf7970a_probe(struct spi_device *spi)
{
struct device_node *np = spi->dev.of_node;
const struct spi_device_id *id = spi_get_device_id(spi);
struct trf7970a *trf;
int ret;
if (!np) {
dev_err(&spi->dev, "No Device Tree entry\n");
return -EINVAL;
}
trf = devm_kzalloc(&spi->dev, sizeof(*trf), GFP_KERNEL);
if (!trf)
return -ENOMEM;
trf->state = TRF7970A_ST_OFF;
trf->dev = &spi->dev;
trf->spi = spi;
trf->quirks = id->driver_data;
spi->mode = SPI_MODE_1;
spi->bits_per_word = 8;
trf->en_gpio = of_get_named_gpio(np, "ti,enable-gpios", 0);
if (!gpio_is_valid(trf->en_gpio)) {
dev_err(trf->dev, "No EN GPIO property\n");
return trf->en_gpio;
}
ret = devm_gpio_request_one(trf->dev, trf->en_gpio,
GPIOF_DIR_OUT | GPIOF_INIT_LOW, "EN");
if (ret) {
dev_err(trf->dev, "Can't request EN GPIO: %d\n", ret);
return ret;
}
trf->en2_gpio = of_get_named_gpio(np, "ti,enable-gpios", 1);
if (!gpio_is_valid(trf->en2_gpio)) {
dev_err(trf->dev, "No EN2 GPIO property\n");
return trf->en2_gpio;
}
ret = devm_gpio_request_one(trf->dev, trf->en2_gpio,
GPIOF_DIR_OUT | GPIOF_INIT_LOW, "EN2");
if (ret) {
dev_err(trf->dev, "Can't request EN2 GPIO: %d\n", ret);
return ret;
}
ret = devm_request_threaded_irq(trf->dev, spi->irq, NULL,
trf7970a_irq, IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"trf7970a", trf);
if (ret) {
dev_err(trf->dev, "Can't request IRQ#%d: %d\n", spi->irq, ret);
return ret;
}
mutex_init(&trf->lock);
INIT_DELAYED_WORK(&trf->timeout_work, trf7970a_timeout_work_handler);
trf->regulator = devm_regulator_get(&spi->dev, "vin");
if (IS_ERR(trf->regulator)) {
ret = PTR_ERR(trf->regulator);
dev_err(trf->dev, "Can't get VIN regulator: %d\n", ret);
goto err_destroy_lock;
}
ret = regulator_enable(trf->regulator);
if (ret) {
dev_err(trf->dev, "Can't enable VIN: %d\n", ret);
goto err_destroy_lock;
}
trf->powering_up = true;
trf->ddev = nfc_digital_allocate_device(&trf7970a_nfc_ops,
TRF7970A_SUPPORTED_PROTOCOLS,
NFC_DIGITAL_DRV_CAPS_IN_CRC, TRF7970A_TX_SKB_HEADROOM,
0);
if (!trf->ddev) {
dev_err(trf->dev, "Can't allocate NFC digital device\n");
ret = -ENOMEM;
goto err_disable_regulator;
}
nfc_digital_set_parent_dev(trf->ddev, trf->dev);
nfc_digital_set_drvdata(trf->ddev, trf);
spi_set_drvdata(spi, trf);
ret = nfc_digital_register_device(trf->ddev);
if (ret) {
dev_err(trf->dev, "Can't register NFC digital device: %d\n",
ret);
goto err_free_ddev;
}
return 0;
err_free_ddev:
nfc_digital_free_device(trf->ddev);
err_disable_regulator:
regulator_disable(trf->regulator);
err_destroy_lock:
mutex_destroy(&trf->lock);
return ret;
}
static int trf7970a_remove(struct spi_device *spi)
{
struct trf7970a *trf = spi_get_drvdata(spi);
mutex_lock(&trf->lock);
trf7970a_switch_rf_off(trf);
trf7970a_init(trf);
switch (trf->state) {
case TRF7970A_ST_WAIT_FOR_TX_FIFO:
case TRF7970A_ST_WAIT_FOR_RX_DATA:
case TRF7970A_ST_WAIT_FOR_RX_DATA_CONT:
case TRF7970A_ST_WAIT_TO_ISSUE_EOF:
trf7970a_send_err_upstream(trf, -ECANCELED);
break;
default:
break;
}
mutex_unlock(&trf->lock);
nfc_digital_unregister_device(trf->ddev);
nfc_digital_free_device(trf->ddev);
regulator_disable(trf->regulator);
mutex_destroy(&trf->lock);
return 0;
}
