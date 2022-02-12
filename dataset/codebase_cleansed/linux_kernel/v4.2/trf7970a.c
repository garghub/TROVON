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
static int trf7970a_read_cont(struct trf7970a *trf, u8 reg, u8 *buf, size_t len)
{
u8 addr = reg | TRF7970A_CMD_BIT_RW | TRF7970A_CMD_BIT_CONTINUOUS;
struct spi_transfer t[2];
struct spi_message m;
int ret;
dev_dbg(trf->dev, "read_cont(0x%x, %zd)\n", addr, len);
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t[0].tx_buf = &addr;
t[0].len = sizeof(addr);
spi_message_add_tail(&t[0], &m);
t[1].rx_buf = buf;
t[1].len = len;
spi_message_add_tail(&t[1], &m);
ret = spi_sync(trf->spi, &m);
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
if (trf->quirks & TRF7970A_QUIRK_IRQ_STATUS_READ) {
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
static int trf7970a_read_target_proto(struct trf7970a *trf, u8 *target_proto)
{
int ret;
u8 buf[2];
u8 addr;
addr = TRF79070A_NFC_TARGET_PROTOCOL | TRF7970A_CMD_BIT_RW |
TRF7970A_CMD_BIT_CONTINUOUS;
ret = spi_write_then_read(trf->spi, &addr, 1, buf, 2);
if (ret)
dev_err(trf->dev, "%s - target_proto: Read failed: %d\n",
__func__, ret);
else
*target_proto = buf[0];
return ret;
}
static int trf7970a_mode_detect(struct trf7970a *trf, u8 *rf_tech)
{
int ret;
u8 target_proto, tech;
ret = trf7970a_read_target_proto(trf, &target_proto);
if (ret)
return ret;
switch (target_proto) {
case TRF79070A_NFC_TARGET_PROTOCOL_106A:
tech = NFC_DIGITAL_RF_TECH_106A;
break;
case TRF79070A_NFC_TARGET_PROTOCOL_106B:
tech = NFC_DIGITAL_RF_TECH_106B;
break;
case TRF79070A_NFC_TARGET_PROTOCOL_212F:
tech = NFC_DIGITAL_RF_TECH_212F;
break;
case TRF79070A_NFC_TARGET_PROTOCOL_424F:
tech = NFC_DIGITAL_RF_TECH_424F;
break;
default:
dev_dbg(trf->dev, "%s - mode_detect: target_proto: 0x%x\n",
__func__, target_proto);
return -EIO;
}
*rf_tech = tech;
return ret;
}
static void trf7970a_send_upstream(struct trf7970a *trf)
{
dev_kfree_skb_any(trf->tx_skb);
trf->tx_skb = NULL;
if (trf->rx_skb && !IS_ERR(trf->rx_skb) && !trf->aborting)
print_hex_dump_debug("trf7970a rx data: ", DUMP_PREFIX_NONE,
16, 1, trf->rx_skb->data, trf->rx_skb->len,
false);
trf->state = TRF7970A_ST_IDLE;
if (trf->aborting) {
dev_dbg(trf->dev, "Abort process complete\n");
if (!IS_ERR(trf->rx_skb)) {
kfree_skb(trf->rx_skb);
trf->rx_skb = ERR_PTR(-ECANCELED);
}
trf->aborting = false;
}
if (trf->adjust_resp_len) {
skb_trim(trf->rx_skb, trf->rx_skb->len - 1);
trf->adjust_resp_len = false;
}
trf->cb(trf->ddev, trf->cb_arg, trf->rx_skb);
trf->rx_skb = NULL;
}
static void trf7970a_send_err_upstream(struct trf7970a *trf, int errno)
{
dev_dbg(trf->dev, "Error - state: %d, errno: %d\n", trf->state, errno);
cancel_delayed_work(&trf->timeout_work);
kfree_skb(trf->rx_skb);
trf->rx_skb = ERR_PTR(errno);
trf7970a_send_upstream(trf);
}
static int trf7970a_transmit(struct trf7970a *trf, struct sk_buff *skb,
unsigned int len, u8 *prefix, unsigned int prefix_len)
{
struct spi_transfer t[2];
struct spi_message m;
unsigned int timeout;
int ret;
print_hex_dump_debug("trf7970a tx data: ", DUMP_PREFIX_NONE,
16, 1, skb->data, len, false);
spi_message_init(&m);
memset(&t, 0, sizeof(t));
t[0].tx_buf = prefix;
t[0].len = prefix_len;
spi_message_add_tail(&t[0], &m);
t[1].tx_buf = skb->data;
t[1].len = len;
spi_message_add_tail(&t[1], &m);
ret = spi_sync(trf->spi, &m);
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
if (!trf->timeout)
timeout = TRF7970A_WAIT_FOR_TX_IRQ;
else
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
u8 prefix;
ret = trf7970a_read(trf, TRF7970A_FIFO_STATUS, &fifo_bytes);
if (ret) {
trf7970a_send_err_upstream(trf, ret);
return;
}
dev_dbg(trf->dev, "Filling FIFO - fifo_bytes: 0x%x\n", fifo_bytes);
fifo_bytes &= ~TRF7970A_FIFO_STATUS_OVERFLOW;
len = TRF7970A_FIFO_SIZE - fifo_bytes;
if (!len) {
schedule_delayed_work(&trf->timeout_work,
msecs_to_jiffies(TRF7970A_WAIT_FOR_FIFO_DRAIN_TIMEOUT));
return;
}
len = min(skb->len, len);
prefix = TRF7970A_CMD_BIT_CONTINUOUS | TRF7970A_FIFO_IO_REGISTER;
ret = trf7970a_transmit(trf, skb, len, &prefix, sizeof(prefix));
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
fifo_bytes &= ~TRF7970A_FIFO_STATUS_OVERFLOW;
if (!fifo_bytes)
goto no_rx_data;
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
ret = trf7970a_read(trf, TRF7970A_FIFO_STATUS, &fifo_bytes);
if (ret) {
trf7970a_send_err_upstream(trf, ret);
return;
}
fifo_bytes &= ~TRF7970A_FIFO_STATUS_OVERFLOW;
if (fifo_bytes)
status = 0;
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
u8 status, fifo_bytes, iso_ctrl;
mutex_lock(&trf->lock);
if (trf->state == TRF7970A_ST_RF_OFF) {
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
if (trf->is_initiator && (status & TRF7970A_IRQ_STATUS_ERROR)) {
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
} else if (status & TRF7970A_IRQ_STATUS_FIFO) {
ret = trf7970a_read(trf, TRF7970A_FIFO_STATUS,
&fifo_bytes);
fifo_bytes &= ~TRF7970A_FIFO_STATUS_OVERFLOW;
if (ret)
trf7970a_send_err_upstream(trf, ret);
else if (!fifo_bytes)
trf7970a_cmd(trf, TRF7970A_CMD_FIFO_RESET);
} else if ((status == TRF7970A_IRQ_STATUS_TX) ||
(!trf->is_initiator &&
(status == (TRF7970A_IRQ_STATUS_TX |
TRF7970A_IRQ_STATUS_NFC_RF)))) {
trf7970a_cmd(trf, TRF7970A_CMD_FIFO_RESET);
if (!trf->timeout) {
trf->ignore_timeout = !cancel_delayed_work(
&trf->timeout_work);
trf->rx_skb = ERR_PTR(0);
trf7970a_send_upstream(trf);
break;
}
if (trf->is_initiator)
break;
iso_ctrl = trf->iso_ctrl;
switch (trf->framing) {
case NFC_DIGITAL_FRAMING_NFCA_STANDARD:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT_NO_CRC;
iso_ctrl |= TRF7970A_ISO_CTRL_RX_CRC_N;
trf->iso_ctrl = 0xff;
break;
case NFC_DIGITAL_FRAMING_NFCA_STANDARD_WITH_CRC_A:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT;
iso_ctrl &= ~TRF7970A_ISO_CTRL_RX_CRC_N;
trf->iso_ctrl = 0xff;
break;
case NFC_DIGITAL_FRAMING_NFCA_ANTICOL_COMPLETE:
ret = trf7970a_write(trf,
TRF7970A_SPECIAL_FCN_REG1,
TRF7970A_SPECIAL_FCN_REG1_14_ANTICOLL);
if (ret)
goto err_unlock_exit;
trf->special_fcn_reg1 =
TRF7970A_SPECIAL_FCN_REG1_14_ANTICOLL;
break;
default:
break;
}
if (iso_ctrl != trf->iso_ctrl) {
ret = trf7970a_write(trf, TRF7970A_ISO_CTRL,
iso_ctrl);
if (ret)
goto err_unlock_exit;
trf->iso_ctrl = iso_ctrl;
}
} else {
trf7970a_send_err_upstream(trf, -EIO);
}
break;
case TRF7970A_ST_WAIT_TO_ISSUE_EOF:
if (status != TRF7970A_IRQ_STATUS_TX)
trf7970a_send_err_upstream(trf, -EIO);
break;
case TRF7970A_ST_LISTENING:
if (status & TRF7970A_IRQ_STATUS_SRX) {
trf->ignore_timeout =
!cancel_delayed_work(&trf->timeout_work);
trf7970a_drain_fifo(trf, status);
} else if (!(status & TRF7970A_IRQ_STATUS_NFC_RF)) {
trf7970a_send_err_upstream(trf, -EIO);
}
break;
case TRF7970A_ST_LISTENING_MD:
if (status & TRF7970A_IRQ_STATUS_SRX) {
trf->ignore_timeout =
!cancel_delayed_work(&trf->timeout_work);
ret = trf7970a_mode_detect(trf, &trf->md_rf_tech);
if (ret) {
trf7970a_send_err_upstream(trf, ret);
} else {
trf->state = TRF7970A_ST_LISTENING;
trf7970a_drain_fifo(trf, status);
}
} else if (!(status & TRF7970A_IRQ_STATUS_NFC_RF)) {
trf7970a_send_err_upstream(trf, -EIO);
}
break;
default:
dev_err(trf->dev, "%s - Driver in invalid state: %d\n",
__func__, trf->state);
}
err_unlock_exit:
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
trf7970a_drain_fifo(trf, TRF7970A_IRQ_STATUS_SRX);
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
usleep_range(1000, 2000);
trf->chip_status_ctrl &= ~TRF7970A_CHIP_STATUS_RF_ON;
ret = trf7970a_write(trf, TRF7970A_MODULATOR_SYS_CLK_CTRL, 0);
if (ret)
goto err_out;
trf->modulator_sys_clk_ctrl = 0;
ret = trf7970a_write(trf, TRF7970A_ADJUTABLE_FIFO_IRQ_LEVELS,
TRF7970A_ADJUTABLE_FIFO_IRQ_LEVELS_WLH_96 |
TRF7970A_ADJUTABLE_FIFO_IRQ_LEVELS_WLL_32);
if (ret)
goto err_out;
ret = trf7970a_write(trf, TRF7970A_SPECIAL_FCN_REG1, 0);
if (ret)
goto err_out;
trf->special_fcn_reg1 = 0;
trf->iso_ctrl = 0xff;
return 0;
err_out:
dev_dbg(trf->dev, "Couldn't init device: %d\n", ret);
return ret;
}
static void trf7970a_switch_rf_off(struct trf7970a *trf)
{
if ((trf->state == TRF7970A_ST_PWR_OFF) ||
(trf->state == TRF7970A_ST_RF_OFF))
return;
dev_dbg(trf->dev, "Switching rf off\n");
trf->chip_status_ctrl &= ~TRF7970A_CHIP_STATUS_RF_ON;
trf7970a_write(trf, TRF7970A_CHIP_STATUS_CTRL, trf->chip_status_ctrl);
trf->aborting = false;
trf->state = TRF7970A_ST_RF_OFF;
pm_runtime_mark_last_busy(trf->dev);
pm_runtime_put_autosuspend(trf->dev);
}
static int trf7970a_switch_rf_on(struct trf7970a *trf)
{
int ret;
dev_dbg(trf->dev, "Switching rf on\n");
pm_runtime_get_sync(trf->dev);
if (trf->state != TRF7970A_ST_RF_OFF) {
dev_err(trf->dev, "%s - Incorrect state: %d\n", __func__,
trf->state);
return -EINVAL;
}
ret = trf7970a_init(trf);
if (ret) {
dev_err(trf->dev, "%s - Can't initialize: %d\n", __func__, ret);
return ret;
}
trf->state = TRF7970A_ST_IDLE;
return 0;
}
static int trf7970a_switch_rf(struct nfc_digital_dev *ddev, bool on)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
int ret = 0;
dev_dbg(trf->dev, "Switching RF - state: %d, on: %d\n", trf->state, on);
mutex_lock(&trf->lock);
if (on) {
switch (trf->state) {
case TRF7970A_ST_PWR_OFF:
case TRF7970A_ST_RF_OFF:
ret = trf7970a_switch_rf_on(trf);
break;
case TRF7970A_ST_IDLE:
case TRF7970A_ST_IDLE_RX_BLOCKED:
break;
default:
dev_err(trf->dev, "%s - Invalid request: %d %d\n",
__func__, trf->state, on);
trf7970a_switch_rf_off(trf);
ret = -EINVAL;
}
} else {
switch (trf->state) {
case TRF7970A_ST_PWR_OFF:
case TRF7970A_ST_RF_OFF:
break;
default:
dev_err(trf->dev, "%s - Invalid request: %d %d\n",
__func__, trf->state, on);
ret = -EINVAL;
case TRF7970A_ST_IDLE:
case TRF7970A_ST_IDLE_RX_BLOCKED:
case TRF7970A_ST_WAIT_FOR_RX_DATA:
case TRF7970A_ST_WAIT_FOR_RX_DATA_CONT:
trf7970a_switch_rf_off(trf);
}
}
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_in_config_rf_tech(struct trf7970a *trf, int tech)
{
int ret = 0;
dev_dbg(trf->dev, "rf technology: %d\n", tech);
switch (tech) {
case NFC_DIGITAL_RF_TECH_106A:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_14443A_106;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_OOK;
trf->guard_time = TRF7970A_GUARD_TIME_NFCA;
break;
case NFC_DIGITAL_RF_TECH_106B:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_14443B_106;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_ASK10;
trf->guard_time = TRF7970A_GUARD_TIME_NFCB;
break;
case NFC_DIGITAL_RF_TECH_212F:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_FELICA_212;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_ASK10;
trf->guard_time = TRF7970A_GUARD_TIME_NFCF;
break;
case NFC_DIGITAL_RF_TECH_424F:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_FELICA_424;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_ASK10;
trf->guard_time = TRF7970A_GUARD_TIME_NFCF;
break;
case NFC_DIGITAL_RF_TECH_ISO15693:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_15693_SGL_1OF4_2648;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_OOK;
trf->guard_time = TRF7970A_GUARD_TIME_15693;
break;
default:
dev_dbg(trf->dev, "Unsupported rf technology: %d\n", tech);
return -EINVAL;
}
trf->technology = tech;
if (trf->iso_ctrl == 0xff)
ret = trf7970a_write(trf, TRF7970A_NFC_TARGET_LEVEL, 0);
return ret;
}
static int trf7970a_is_rf_field(struct trf7970a *trf, bool *is_rf_field)
{
int ret;
u8 rssi;
ret = trf7970a_write(trf, TRF7970A_CHIP_STATUS_CTRL,
trf->chip_status_ctrl | TRF7970A_CHIP_STATUS_REC_ON);
if (ret)
return ret;
ret = trf7970a_cmd(trf, TRF7970A_CMD_TEST_EXT_RF);
if (ret)
return ret;
usleep_range(50, 60);
ret = trf7970a_read(trf, TRF7970A_RSSI_OSC_STATUS, &rssi);
if (ret)
return ret;
ret = trf7970a_write(trf, TRF7970A_CHIP_STATUS_CTRL,
trf->chip_status_ctrl);
if (ret)
return ret;
if (rssi & TRF7970A_RSSI_OSC_STATUS_RSSI_MASK)
*is_rf_field = true;
else
*is_rf_field = false;
return 0;
}
static int trf7970a_in_config_framing(struct trf7970a *trf, int framing)
{
u8 iso_ctrl = trf->iso_ctrl_tech;
bool is_rf_field = false;
int ret;
dev_dbg(trf->dev, "framing: %d\n", framing);
switch (framing) {
case NFC_DIGITAL_FRAMING_NFCA_SHORT:
case NFC_DIGITAL_FRAMING_NFCA_STANDARD:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT_NO_CRC;
iso_ctrl |= TRF7970A_ISO_CTRL_RX_CRC_N;
break;
case NFC_DIGITAL_FRAMING_NFCA_STANDARD_WITH_CRC_A:
case NFC_DIGITAL_FRAMING_NFCA_T4T:
case NFC_DIGITAL_FRAMING_NFCB:
case NFC_DIGITAL_FRAMING_NFCB_T4T:
case NFC_DIGITAL_FRAMING_NFCF:
case NFC_DIGITAL_FRAMING_NFCF_T3T:
case NFC_DIGITAL_FRAMING_ISO15693_INVENTORY:
case NFC_DIGITAL_FRAMING_ISO15693_T5T:
case NFC_DIGITAL_FRAMING_NFCA_NFC_DEP:
case NFC_DIGITAL_FRAMING_NFCF_NFC_DEP:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT;
iso_ctrl &= ~TRF7970A_ISO_CTRL_RX_CRC_N;
break;
case NFC_DIGITAL_FRAMING_NFCA_T2T:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT;
iso_ctrl |= TRF7970A_ISO_CTRL_RX_CRC_N;
break;
default:
dev_dbg(trf->dev, "Unsupported Framing: %d\n", framing);
return -EINVAL;
}
trf->framing = framing;
if (!(trf->chip_status_ctrl & TRF7970A_CHIP_STATUS_RF_ON)) {
ret = trf7970a_is_rf_field(trf, &is_rf_field);
if (ret)
return ret;
if (is_rf_field)
return -EBUSY;
}
if (iso_ctrl != trf->iso_ctrl) {
ret = trf7970a_write(trf, TRF7970A_ISO_CTRL, iso_ctrl);
if (ret)
return ret;
trf->iso_ctrl = iso_ctrl;
ret = trf7970a_write(trf, TRF7970A_MODULATOR_SYS_CLK_CTRL,
trf->modulator_sys_clk_ctrl);
if (ret)
return ret;
}
if (!(trf->chip_status_ctrl & TRF7970A_CHIP_STATUS_RF_ON)) {
ret = trf7970a_write(trf, TRF7970A_CHIP_STATUS_CTRL,
trf->chip_status_ctrl |
TRF7970A_CHIP_STATUS_RF_ON);
if (ret)
return ret;
trf->chip_status_ctrl |= TRF7970A_CHIP_STATUS_RF_ON;
usleep_range(trf->guard_time, trf->guard_time + 1000);
}
return 0;
}
static int trf7970a_in_configure_hw(struct nfc_digital_dev *ddev, int type,
int param)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
int ret;
dev_dbg(trf->dev, "Configure hw - type: %d, param: %d\n", type, param);
mutex_lock(&trf->lock);
trf->is_initiator = true;
if ((trf->state == TRF7970A_ST_PWR_OFF) ||
(trf->state == TRF7970A_ST_RF_OFF)) {
ret = trf7970a_switch_rf_on(trf);
if (ret)
goto err_unlock;
}
switch (type) {
case NFC_DIGITAL_CONFIG_RF_TECH:
ret = trf7970a_in_config_rf_tech(trf, param);
break;
case NFC_DIGITAL_CONFIG_FRAMING:
ret = trf7970a_in_config_framing(trf, param);
break;
default:
dev_dbg(trf->dev, "Unknown type: %d\n", type);
ret = -EINVAL;
}
err_unlock:
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
if (trf->framing == NFC_DIGITAL_FRAMING_ISO15693_T5T) {
if (trf7970a_is_iso15693_write_or_lock(req[1]) &&
(req[0] & ISO15693_REQ_FLAG_OPTION))
trf->issue_eof = true;
else if ((trf->quirks &
TRF7970A_QUIRK_T5T_RMB_EXTRA_BYTE) &&
(req[1] == ISO15693_CMD_READ_MULTIPLE_BLOCK))
trf->adjust_resp_len = true;
}
}
return 0;
}
static int trf7970a_send_cmd(struct nfc_digital_dev *ddev,
struct sk_buff *skb, u16 timeout,
nfc_digital_cmd_complete_t cb, void *arg)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
u8 prefix[5];
unsigned int len;
int ret;
u8 status;
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
if (timeout) {
trf->rx_skb = nfc_alloc_recv_skb(TRF7970A_RX_SKB_ALLOC_SIZE,
GFP_KERNEL);
if (!trf->rx_skb) {
dev_dbg(trf->dev, "Can't alloc rx_skb\n");
ret = -ENOMEM;
goto out_err;
}
}
if (trf->state == TRF7970A_ST_IDLE_RX_BLOCKED) {
ret = trf7970a_cmd(trf, TRF7970A_CMD_ENABLE_RX);
if (ret)
goto out_err;
trf->state = TRF7970A_ST_IDLE;
}
if (trf->is_initiator) {
ret = trf7970a_per_cmd_config(trf, skb);
if (ret)
goto out_err;
}
trf->ddev = ddev;
trf->tx_skb = skb;
trf->cb = cb;
trf->cb_arg = arg;
trf->timeout = timeout;
trf->ignore_timeout = false;
len = skb->len;
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
ret = trf7970a_read_irqstatus(trf, &status);
if (ret)
goto out_err;
ret = trf7970a_transmit(trf, skb, len, prefix, sizeof(prefix));
if (ret) {
kfree_skb(trf->rx_skb);
trf->rx_skb = NULL;
}
out_err:
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_tg_config_rf_tech(struct trf7970a *trf, int tech)
{
int ret = 0;
dev_dbg(trf->dev, "rf technology: %d\n", tech);
switch (tech) {
case NFC_DIGITAL_RF_TECH_106A:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_NFC_NFC_CE_MODE |
TRF7970A_ISO_CTRL_NFC_CE |
TRF7970A_ISO_CTRL_NFC_CE_14443A;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_OOK;
break;
case NFC_DIGITAL_RF_TECH_212F:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_NFC_NFC_CE_MODE |
TRF7970A_ISO_CTRL_NFC_NFCF_212;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_ASK10;
break;
case NFC_DIGITAL_RF_TECH_424F:
trf->iso_ctrl_tech = TRF7970A_ISO_CTRL_NFC_NFC_CE_MODE |
TRF7970A_ISO_CTRL_NFC_NFCF_424;
trf->modulator_sys_clk_ctrl = TRF7970A_MODULATOR_DEPTH_ASK10;
break;
default:
dev_dbg(trf->dev, "Unsupported rf technology: %d\n", tech);
return -EINVAL;
}
trf->technology = tech;
if ((trf->framing == NFC_DIGITAL_FRAMING_NFC_DEP_ACTIVATED) &&
(trf->iso_ctrl_tech != trf->iso_ctrl)) {
ret = trf7970a_write(trf, TRF7970A_ISO_CTRL,
trf->iso_ctrl_tech);
trf->iso_ctrl = trf->iso_ctrl_tech;
}
return ret;
}
static int trf7970a_tg_config_framing(struct trf7970a *trf, int framing)
{
u8 iso_ctrl = trf->iso_ctrl_tech;
int ret;
dev_dbg(trf->dev, "framing: %d\n", framing);
switch (framing) {
case NFC_DIGITAL_FRAMING_NFCA_NFC_DEP:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT_NO_CRC;
iso_ctrl |= TRF7970A_ISO_CTRL_RX_CRC_N;
break;
case NFC_DIGITAL_FRAMING_NFCA_STANDARD:
case NFC_DIGITAL_FRAMING_NFCA_STANDARD_WITH_CRC_A:
case NFC_DIGITAL_FRAMING_NFCA_ANTICOL_COMPLETE:
iso_ctrl = trf->iso_ctrl;
break;
case NFC_DIGITAL_FRAMING_NFCF_NFC_DEP:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT;
iso_ctrl &= ~TRF7970A_ISO_CTRL_RX_CRC_N;
break;
case NFC_DIGITAL_FRAMING_NFC_DEP_ACTIVATED:
trf->tx_cmd = TRF7970A_CMD_TRANSMIT;
iso_ctrl &= ~TRF7970A_ISO_CTRL_RX_CRC_N;
break;
default:
dev_dbg(trf->dev, "Unsupported Framing: %d\n", framing);
return -EINVAL;
}
trf->framing = framing;
if (iso_ctrl != trf->iso_ctrl) {
ret = trf7970a_write(trf, TRF7970A_ISO_CTRL, iso_ctrl);
if (ret)
return ret;
trf->iso_ctrl = iso_ctrl;
ret = trf7970a_write(trf, TRF7970A_MODULATOR_SYS_CLK_CTRL,
trf->modulator_sys_clk_ctrl);
if (ret)
return ret;
}
if (!(trf->chip_status_ctrl & TRF7970A_CHIP_STATUS_RF_ON)) {
ret = trf7970a_write(trf, TRF7970A_CHIP_STATUS_CTRL,
trf->chip_status_ctrl |
TRF7970A_CHIP_STATUS_RF_ON);
if (ret)
return ret;
trf->chip_status_ctrl |= TRF7970A_CHIP_STATUS_RF_ON;
}
return 0;
}
static int trf7970a_tg_configure_hw(struct nfc_digital_dev *ddev, int type,
int param)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
int ret;
dev_dbg(trf->dev, "Configure hw - type: %d, param: %d\n", type, param);
mutex_lock(&trf->lock);
trf->is_initiator = false;
if ((trf->state == TRF7970A_ST_PWR_OFF) ||
(trf->state == TRF7970A_ST_RF_OFF)) {
ret = trf7970a_switch_rf_on(trf);
if (ret)
goto err_unlock;
}
switch (type) {
case NFC_DIGITAL_CONFIG_RF_TECH:
ret = trf7970a_tg_config_rf_tech(trf, param);
break;
case NFC_DIGITAL_CONFIG_FRAMING:
ret = trf7970a_tg_config_framing(trf, param);
break;
default:
dev_dbg(trf->dev, "Unknown type: %d\n", type);
ret = -EINVAL;
}
err_unlock:
mutex_unlock(&trf->lock);
return ret;
}
static int _trf7970a_tg_listen(struct nfc_digital_dev *ddev, u16 timeout,
nfc_digital_cmd_complete_t cb, void *arg, bool mode_detect)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
int ret;
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
ret = trf7970a_write(trf, TRF7970A_RX_SPECIAL_SETTINGS,
TRF7970A_RX_SPECIAL_SETTINGS_HBT |
TRF7970A_RX_SPECIAL_SETTINGS_M848 |
TRF7970A_RX_SPECIAL_SETTINGS_C424 |
TRF7970A_RX_SPECIAL_SETTINGS_C212);
if (ret)
goto out_err;
ret = trf7970a_write(trf, TRF7970A_REG_IO_CTRL,
TRF7970A_REG_IO_CTRL_VRS(0x1));
if (ret)
goto out_err;
ret = trf7970a_write(trf, TRF7970A_NFC_LOW_FIELD_LEVEL,
TRF7970A_NFC_LOW_FIELD_LEVEL_RFDET(0x3));
if (ret)
goto out_err;
ret = trf7970a_write(trf, TRF7970A_NFC_TARGET_LEVEL,
TRF7970A_NFC_TARGET_LEVEL_RFDET(0x7));
if (ret)
goto out_err;
trf->ddev = ddev;
trf->cb = cb;
trf->cb_arg = arg;
trf->timeout = timeout;
trf->ignore_timeout = false;
ret = trf7970a_cmd(trf, TRF7970A_CMD_ENABLE_RX);
if (ret)
goto out_err;
trf->state = mode_detect ? TRF7970A_ST_LISTENING_MD :
TRF7970A_ST_LISTENING;
schedule_delayed_work(&trf->timeout_work, msecs_to_jiffies(timeout));
out_err:
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_tg_listen(struct nfc_digital_dev *ddev, u16 timeout,
nfc_digital_cmd_complete_t cb, void *arg)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Listen - state: %d, timeout: %d ms\n",
trf->state, timeout);
return _trf7970a_tg_listen(ddev, timeout, cb, arg, false);
}
static int trf7970a_tg_listen_md(struct nfc_digital_dev *ddev,
u16 timeout, nfc_digital_cmd_complete_t cb, void *arg)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
int ret;
dev_dbg(trf->dev, "Listen MD - state: %d, timeout: %d ms\n",
trf->state, timeout);
ret = trf7970a_tg_configure_hw(ddev, NFC_DIGITAL_CONFIG_RF_TECH,
NFC_DIGITAL_RF_TECH_106A);
if (ret)
return ret;
ret = trf7970a_tg_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_NFCA_NFC_DEP);
if (ret)
return ret;
return _trf7970a_tg_listen(ddev, timeout, cb, arg, true);
}
static int trf7970a_tg_get_rf_tech(struct nfc_digital_dev *ddev, u8 *rf_tech)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Get RF Tech - state: %d, rf_tech: %d\n",
trf->state, trf->md_rf_tech);
*rf_tech = trf->md_rf_tech;
return 0;
}
static void trf7970a_abort_cmd(struct nfc_digital_dev *ddev)
{
struct trf7970a *trf = nfc_digital_get_drvdata(ddev);
dev_dbg(trf->dev, "Abort process initiated\n");
mutex_lock(&trf->lock);
switch (trf->state) {
case TRF7970A_ST_WAIT_FOR_TX_FIFO:
case TRF7970A_ST_WAIT_FOR_RX_DATA:
case TRF7970A_ST_WAIT_FOR_RX_DATA_CONT:
case TRF7970A_ST_WAIT_TO_ISSUE_EOF:
trf->aborting = true;
break;
case TRF7970A_ST_LISTENING:
trf->ignore_timeout = !cancel_delayed_work(&trf->timeout_work);
trf7970a_send_err_upstream(trf, -ECANCELED);
dev_dbg(trf->dev, "Abort process complete\n");
break;
default:
break;
}
mutex_unlock(&trf->lock);
}
static int trf7970a_power_up(struct trf7970a *trf)
{
int ret;
dev_dbg(trf->dev, "Powering up - state: %d\n", trf->state);
if (trf->state != TRF7970A_ST_PWR_OFF)
return 0;
ret = regulator_enable(trf->regulator);
if (ret) {
dev_err(trf->dev, "%s - Can't enable VIN: %d\n", __func__, ret);
return ret;
}
usleep_range(5000, 6000);
if (!(trf->quirks & TRF7970A_QUIRK_EN2_MUST_STAY_LOW)) {
gpio_set_value(trf->en2_gpio, 1);
usleep_range(1000, 2000);
}
gpio_set_value(trf->en_gpio, 1);
usleep_range(20000, 21000);
trf->state = TRF7970A_ST_RF_OFF;
return 0;
}
static int trf7970a_power_down(struct trf7970a *trf)
{
int ret;
dev_dbg(trf->dev, "Powering down - state: %d\n", trf->state);
if (trf->state == TRF7970A_ST_PWR_OFF)
return 0;
if (trf->state != TRF7970A_ST_RF_OFF) {
dev_dbg(trf->dev, "Can't power down - not RF_OFF state (%d)\n",
trf->state);
return -EBUSY;
}
gpio_set_value(trf->en_gpio, 0);
gpio_set_value(trf->en2_gpio, 0);
ret = regulator_disable(trf->regulator);
if (ret)
dev_err(trf->dev, "%s - Can't disable VIN: %d\n", __func__,
ret);
trf->state = TRF7970A_ST_PWR_OFF;
return ret;
}
static int trf7970a_startup(struct trf7970a *trf)
{
int ret;
ret = trf7970a_power_up(trf);
if (ret)
return ret;
pm_runtime_set_active(trf->dev);
pm_runtime_enable(trf->dev);
pm_runtime_mark_last_busy(trf->dev);
return 0;
}
static void trf7970a_shutdown(struct trf7970a *trf)
{
switch (trf->state) {
case TRF7970A_ST_WAIT_FOR_TX_FIFO:
case TRF7970A_ST_WAIT_FOR_RX_DATA:
case TRF7970A_ST_WAIT_FOR_RX_DATA_CONT:
case TRF7970A_ST_WAIT_TO_ISSUE_EOF:
case TRF7970A_ST_LISTENING:
trf7970a_send_err_upstream(trf, -ECANCELED);
case TRF7970A_ST_IDLE:
case TRF7970A_ST_IDLE_RX_BLOCKED:
trf7970a_switch_rf_off(trf);
break;
default:
break;
}
pm_runtime_disable(trf->dev);
pm_runtime_set_suspended(trf->dev);
trf7970a_power_down(trf);
}
static int trf7970a_get_autosuspend_delay(struct device_node *np)
{
int autosuspend_delay, ret;
ret = of_property_read_u32(np, "autosuspend-delay", &autosuspend_delay);
if (ret)
autosuspend_delay = TRF7970A_AUTOSUSPEND_DELAY;
return autosuspend_delay;
}
static int trf7970a_get_vin_voltage_override(struct device_node *np,
u32 *vin_uvolts)
{
return of_property_read_u32(np, "vin-voltage-override", vin_uvolts);
}
static int trf7970a_probe(struct spi_device *spi)
{
struct device_node *np = spi->dev.of_node;
struct trf7970a *trf;
int uvolts, autosuspend_delay, ret;
if (!np) {
dev_err(&spi->dev, "No Device Tree entry\n");
return -EINVAL;
}
trf = devm_kzalloc(&spi->dev, sizeof(*trf), GFP_KERNEL);
if (!trf)
return -ENOMEM;
trf->state = TRF7970A_ST_PWR_OFF;
trf->dev = &spi->dev;
trf->spi = spi;
spi->mode = SPI_MODE_1;
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret < 0) {
dev_err(trf->dev, "Can't set up SPI Communication\n");
return ret;
}
if (of_property_read_bool(np, "t5t-rmb-extra-byte-quirk"))
trf->quirks |= TRF7970A_QUIRK_T5T_RMB_EXTRA_BYTE;
if (of_property_read_bool(np, "irq-status-read-quirk"))
trf->quirks |= TRF7970A_QUIRK_IRQ_STATUS_READ;
trf->en_gpio = of_get_named_gpio(np, "ti,enable-gpios", 0);
if (!gpio_is_valid(trf->en_gpio)) {
dev_err(trf->dev, "No EN GPIO property\n");
return trf->en_gpio;
}
ret = devm_gpio_request_one(trf->dev, trf->en_gpio,
GPIOF_DIR_OUT | GPIOF_INIT_LOW, "trf7970a EN");
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
GPIOF_DIR_OUT | GPIOF_INIT_LOW, "trf7970a EN2");
if (ret) {
dev_err(trf->dev, "Can't request EN2 GPIO: %d\n", ret);
return ret;
}
if (of_property_read_bool(np, "en2-rf-quirk"))
trf->quirks |= TRF7970A_QUIRK_EN2_MUST_STAY_LOW;
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
ret = trf7970a_get_vin_voltage_override(np, &uvolts);
if (ret)
uvolts = regulator_get_voltage(trf->regulator);
if (uvolts > 4000000)
trf->chip_status_ctrl = TRF7970A_CHIP_STATUS_VRS5_3;
trf->ddev = nfc_digital_allocate_device(&trf7970a_nfc_ops,
TRF7970A_SUPPORTED_PROTOCOLS,
NFC_DIGITAL_DRV_CAPS_IN_CRC |
NFC_DIGITAL_DRV_CAPS_TG_CRC, 0, 0);
if (!trf->ddev) {
dev_err(trf->dev, "Can't allocate NFC digital device\n");
ret = -ENOMEM;
goto err_disable_regulator;
}
nfc_digital_set_parent_dev(trf->ddev, trf->dev);
nfc_digital_set_drvdata(trf->ddev, trf);
spi_set_drvdata(spi, trf);
autosuspend_delay = trf7970a_get_autosuspend_delay(np);
pm_runtime_set_autosuspend_delay(trf->dev, autosuspend_delay);
pm_runtime_use_autosuspend(trf->dev);
ret = trf7970a_startup(trf);
if (ret)
goto err_free_ddev;
ret = nfc_digital_register_device(trf->ddev);
if (ret) {
dev_err(trf->dev, "Can't register NFC digital device: %d\n",
ret);
goto err_shutdown;
}
return 0;
err_shutdown:
trf7970a_shutdown(trf);
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
trf7970a_shutdown(trf);
mutex_unlock(&trf->lock);
nfc_digital_unregister_device(trf->ddev);
nfc_digital_free_device(trf->ddev);
regulator_disable(trf->regulator);
mutex_destroy(&trf->lock);
return 0;
}
static int trf7970a_suspend(struct device *dev)
{
struct spi_device *spi = container_of(dev, struct spi_device, dev);
struct trf7970a *trf = spi_get_drvdata(spi);
dev_dbg(dev, "Suspend\n");
mutex_lock(&trf->lock);
trf7970a_shutdown(trf);
mutex_unlock(&trf->lock);
return 0;
}
static int trf7970a_resume(struct device *dev)
{
struct spi_device *spi = container_of(dev, struct spi_device, dev);
struct trf7970a *trf = spi_get_drvdata(spi);
int ret;
dev_dbg(dev, "Resume\n");
mutex_lock(&trf->lock);
ret = trf7970a_startup(trf);
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_pm_runtime_suspend(struct device *dev)
{
struct spi_device *spi = container_of(dev, struct spi_device, dev);
struct trf7970a *trf = spi_get_drvdata(spi);
int ret;
dev_dbg(dev, "Runtime suspend\n");
mutex_lock(&trf->lock);
ret = trf7970a_power_down(trf);
mutex_unlock(&trf->lock);
return ret;
}
static int trf7970a_pm_runtime_resume(struct device *dev)
{
struct spi_device *spi = container_of(dev, struct spi_device, dev);
struct trf7970a *trf = spi_get_drvdata(spi);
int ret;
dev_dbg(dev, "Runtime resume\n");
ret = trf7970a_power_up(trf);
if (!ret)
pm_runtime_mark_last_busy(dev);
return ret;
}
