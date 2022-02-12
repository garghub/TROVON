static bool rt2800usb_hwcrypt_disabled(struct rt2x00_dev *rt2x00dev)
{
return modparam_nohwcrypt;
}
static void rt2800usb_start_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_RX:
rt2x00usb_register_read(rt2x00dev, MAC_SYS_CTRL, &reg);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 1);
rt2x00usb_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
break;
case QID_BEACON:
rt2x00usb_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_TICKING, 1);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TBTT_ENABLE, 1);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 1);
rt2x00usb_register_write(rt2x00dev, BCN_TIME_CFG, reg);
break;
default:
break;
}
}
static void rt2800usb_stop_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_RX:
rt2x00usb_register_read(rt2x00dev, MAC_SYS_CTRL, &reg);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 0);
rt2x00usb_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
break;
case QID_BEACON:
rt2x00usb_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_TICKING, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TBTT_ENABLE, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 0);
rt2x00usb_register_write(rt2x00dev, BCN_TIME_CFG, reg);
break;
default:
break;
}
}
static bool rt2800usb_txstatus_pending(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
tx_queue_for_each(rt2x00dev, queue) {
if (rt2x00queue_get_entry(queue, Q_INDEX_DMA_DONE) !=
rt2x00queue_get_entry(queue, Q_INDEX_DONE))
return true;
}
return false;
}
static inline bool rt2800usb_entry_txstatus_timeout(struct queue_entry *entry)
{
bool tout;
if (!test_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags))
return false;
tout = time_after(jiffies, entry->last_action + msecs_to_jiffies(100));
if (unlikely(tout))
rt2x00_dbg(entry->queue->rt2x00dev,
"TX status timeout for entry %d in queue %d\n",
entry->entry_idx, entry->queue->qid);
return tout;
}
static bool rt2800usb_txstatus_timeout(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
struct queue_entry *entry;
tx_queue_for_each(rt2x00dev, queue) {
entry = rt2x00queue_get_entry(queue, Q_INDEX_DONE);
if (rt2800usb_entry_txstatus_timeout(entry))
return true;
}
return false;
}
static bool rt2800usb_tx_sta_fifo_read_completed(struct rt2x00_dev *rt2x00dev,
int urb_status, u32 tx_status)
{
bool valid;
if (urb_status) {
rt2x00_warn(rt2x00dev, "TX status read failed %d\n",
urb_status);
goto stop_reading;
}
valid = rt2x00_get_field32(tx_status, TX_STA_FIFO_VALID);
if (valid) {
if (!kfifo_put(&rt2x00dev->txstatus_fifo, tx_status))
rt2x00_warn(rt2x00dev, "TX status FIFO overrun\n");
queue_work(rt2x00dev->workqueue, &rt2x00dev->txdone_work);
return true;
}
if (rt2800usb_txstatus_timeout(rt2x00dev))
queue_work(rt2x00dev->workqueue, &rt2x00dev->txdone_work);
if (rt2800usb_txstatus_pending(rt2x00dev)) {
hrtimer_start(&rt2x00dev->txstatus_timer,
TXSTATUS_READ_INTERVAL,
HRTIMER_MODE_REL);
return false;
}
stop_reading:
clear_bit(TX_STATUS_READING, &rt2x00dev->flags);
if (rt2800usb_txstatus_pending(rt2x00dev) &&
!test_and_set_bit(TX_STATUS_READING, &rt2x00dev->flags))
return true;
else
return false;
}
static void rt2800usb_async_read_tx_status(struct rt2x00_dev *rt2x00dev)
{
if (test_and_set_bit(TX_STATUS_READING, &rt2x00dev->flags))
return;
hrtimer_start(&rt2x00dev->txstatus_timer,
2 * TXSTATUS_READ_INTERVAL,
HRTIMER_MODE_REL);
}
static void rt2800usb_tx_dma_done(struct queue_entry *entry)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
rt2800usb_async_read_tx_status(rt2x00dev);
}
static enum hrtimer_restart rt2800usb_tx_sta_fifo_timeout(struct hrtimer *timer)
{
struct rt2x00_dev *rt2x00dev =
container_of(timer, struct rt2x00_dev, txstatus_timer);
rt2x00usb_register_read_async(rt2x00dev, TX_STA_FIFO,
rt2800usb_tx_sta_fifo_read_completed);
return HRTIMER_NORESTART;
}
static int rt2800usb_autorun_detect(struct rt2x00_dev *rt2x00dev)
{
__le32 *reg;
u32 fw_mode;
int ret;
reg = kmalloc(sizeof(*reg), GFP_KERNEL);
if (reg == NULL)
return -ENOMEM;
ret = rt2x00usb_vendor_request(rt2x00dev, USB_DEVICE_MODE,
USB_VENDOR_REQUEST_IN, 0,
USB_MODE_AUTORUN, reg, sizeof(*reg),
REGISTER_TIMEOUT_FIRMWARE);
fw_mode = le32_to_cpu(*reg);
kfree(reg);
if (ret < 0)
return ret;
if ((fw_mode & 0x00000003) == 2)
return 1;
return 0;
}
static char *rt2800usb_get_firmware_name(struct rt2x00_dev *rt2x00dev)
{
return FIRMWARE_RT2870;
}
static int rt2800usb_write_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
int status;
u32 offset;
u32 length;
int retval;
if (rt2x00_rt(rt2x00dev, RT2860) ||
rt2x00_rt(rt2x00dev, RT2872) ||
rt2x00_rt(rt2x00dev, RT3070)) {
offset = 0;
length = 4096;
} else {
offset = 4096;
length = 4096;
}
retval = rt2800usb_autorun_detect(rt2x00dev);
if (retval < 0)
return retval;
if (retval) {
rt2x00_info(rt2x00dev,
"Firmware loading not required - NIC in AutoRun mode\n");
__clear_bit(REQUIRE_FIRMWARE, &rt2x00dev->cap_flags);
} else {
rt2x00usb_register_multiwrite(rt2x00dev, FIRMWARE_IMAGE_BASE,
data + offset, length);
}
rt2x00usb_register_write(rt2x00dev, H2M_MAILBOX_CID, ~0);
rt2x00usb_register_write(rt2x00dev, H2M_MAILBOX_STATUS, ~0);
status = rt2x00usb_vendor_request_sw(rt2x00dev, USB_DEVICE_MODE,
0, USB_MODE_FIRMWARE,
REGISTER_TIMEOUT_FIRMWARE);
if (status < 0) {
rt2x00_err(rt2x00dev, "Failed to write Firmware to device\n");
return status;
}
msleep(10);
rt2x00usb_register_write(rt2x00dev, H2M_MAILBOX_CSR, 0);
return 0;
}
static int rt2800usb_init_registers(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
if (rt2800_wait_csr_ready(rt2x00dev))
return -EBUSY;
rt2x00usb_register_read(rt2x00dev, PBF_SYS_CTRL, &reg);
rt2x00usb_register_write(rt2x00dev, PBF_SYS_CTRL, reg & ~0x00002000);
reg = 0;
rt2x00_set_field32(&reg, MAC_SYS_CTRL_RESET_CSR, 1);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_RESET_BBP, 1);
rt2x00usb_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
rt2x00usb_vendor_request_sw(rt2x00dev, USB_DEVICE_MODE, 0,
USB_MODE_RESET, REGISTER_TIMEOUT);
rt2x00usb_register_write(rt2x00dev, MAC_SYS_CTRL, 0x00000000);
return 0;
}
static int rt2800usb_enable_radio(struct rt2x00_dev *rt2x00dev)
{
u32 reg = 0;
if (unlikely(rt2800_wait_wpdma_ready(rt2x00dev)))
return -EIO;
rt2x00_set_field32(&reg, USB_DMA_CFG_PHY_CLEAR, 0);
rt2x00_set_field32(&reg, USB_DMA_CFG_RX_BULK_AGG_EN, 0);
rt2x00_set_field32(&reg, USB_DMA_CFG_RX_BULK_AGG_TIMEOUT, 128);
rt2x00_set_field32(&reg, USB_DMA_CFG_RX_BULK_AGG_LIMIT,
((rt2x00dev->rx->limit * DATA_FRAME_SIZE)
/ 1024) - 3);
rt2x00_set_field32(&reg, USB_DMA_CFG_RX_BULK_EN, 1);
rt2x00_set_field32(&reg, USB_DMA_CFG_TX_BULK_EN, 1);
rt2x00usb_register_write(rt2x00dev, USB_DMA_CFG, reg);
return rt2800_enable_radio(rt2x00dev);
}
static void rt2800usb_disable_radio(struct rt2x00_dev *rt2x00dev)
{
rt2800_disable_radio(rt2x00dev);
}
static int rt2800usb_set_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
if (state == STATE_AWAKE)
rt2800_mcu_request(rt2x00dev, MCU_WAKEUP, 0xff, 0, 2);
else
rt2800_mcu_request(rt2x00dev, MCU_SLEEP, 0xff, 0xff, 2);
return 0;
}
static int rt2800usb_set_device_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int retval = 0;
switch (state) {
case STATE_RADIO_ON:
rt2800usb_set_state(rt2x00dev, STATE_AWAKE);
msleep(1);
retval = rt2800usb_enable_radio(rt2x00dev);
break;
case STATE_RADIO_OFF:
rt2800usb_disable_radio(rt2x00dev);
rt2800usb_set_state(rt2x00dev, STATE_SLEEP);
break;
case STATE_RADIO_IRQ_ON:
case STATE_RADIO_IRQ_OFF:
break;
case STATE_DEEP_SLEEP:
case STATE_SLEEP:
case STATE_STANDBY:
case STATE_AWAKE:
retval = rt2800usb_set_state(rt2x00dev, state);
break;
default:
retval = -ENOTSUPP;
break;
}
if (unlikely(retval))
rt2x00_err(rt2x00dev, "Device failed to enter state %d (%d)\n",
state, retval);
return retval;
}
static void rt2800usb_watchdog(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u32 reg;
rt2x00usb_register_read(rt2x00dev, TXRXQ_PCNT, &reg);
if (rt2x00_get_field32(reg, TXRXQ_PCNT_TX0Q)) {
rt2x00_warn(rt2x00dev, "TX HW queue 0 timed out, invoke forced kick\n");
rt2x00usb_register_write(rt2x00dev, PBF_CFG, 0xf40012);
for (i = 0; i < 10; i++) {
udelay(10);
if (!rt2x00_get_field32(reg, TXRXQ_PCNT_TX0Q))
break;
}
rt2x00usb_register_write(rt2x00dev, PBF_CFG, 0xf40006);
}
rt2x00usb_register_read(rt2x00dev, TXRXQ_PCNT, &reg);
if (rt2x00_get_field32(reg, TXRXQ_PCNT_TX1Q)) {
rt2x00_warn(rt2x00dev, "TX HW queue 1 timed out, invoke forced kick\n");
rt2x00usb_register_write(rt2x00dev, PBF_CFG, 0xf4000a);
for (i = 0; i < 10; i++) {
udelay(10);
if (!rt2x00_get_field32(reg, TXRXQ_PCNT_TX1Q))
break;
}
rt2x00usb_register_write(rt2x00dev, PBF_CFG, 0xf40006);
}
rt2x00usb_watchdog(rt2x00dev);
}
static __le32 *rt2800usb_get_txwi(struct queue_entry *entry)
{
if (entry->queue->qid == QID_BEACON)
return (__le32 *) (entry->skb->data);
else
return (__le32 *) (entry->skb->data + TXINFO_DESC_SIZE);
}
static void rt2800usb_write_tx_desc(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
__le32 *txi = (__le32 *) entry->skb->data;
u32 word;
rt2x00_desc_read(txi, 0, &word);
rt2x00_set_field32(&word, TXINFO_W0_USB_DMA_TX_PKT_LEN,
roundup(entry->skb->len, 4) - TXINFO_DESC_SIZE);
rt2x00_set_field32(&word, TXINFO_W0_WIV,
!test_bit(ENTRY_TXD_ENCRYPT_IV, &txdesc->flags));
rt2x00_set_field32(&word, TXINFO_W0_QSEL, 2);
rt2x00_set_field32(&word, TXINFO_W0_SW_USE_LAST_ROUND, 0);
rt2x00_set_field32(&word, TXINFO_W0_USB_DMA_NEXT_VALID, 0);
rt2x00_set_field32(&word, TXINFO_W0_USB_DMA_TX_BURST,
test_bit(ENTRY_TXD_BURST, &txdesc->flags));
rt2x00_desc_write(txi, 0, word);
skbdesc->flags |= SKBDESC_DESC_IN_SKB;
skbdesc->desc = txi;
skbdesc->desc_len = TXINFO_DESC_SIZE + entry->queue->winfo_size;
}
static int rt2800usb_get_tx_data_len(struct queue_entry *entry)
{
return roundup(entry->skb->len, 4) + 4;
}
static enum txdone_entry_desc_flags
rt2800usb_txdone_entry_check(struct queue_entry *entry, u32 reg)
{
__le32 *txwi;
u32 word;
int wcid, ack, pid;
int tx_wcid, tx_ack, tx_pid, is_agg;
if (test_bit(ENTRY_DATA_IO_FAILED, &entry->flags))
return TXDONE_FAILURE;
wcid = rt2x00_get_field32(reg, TX_STA_FIFO_WCID);
ack = rt2x00_get_field32(reg, TX_STA_FIFO_TX_ACK_REQUIRED);
pid = rt2x00_get_field32(reg, TX_STA_FIFO_PID_TYPE);
is_agg = rt2x00_get_field32(reg, TX_STA_FIFO_TX_AGGRE);
txwi = rt2800usb_get_txwi(entry);
rt2x00_desc_read(txwi, 1, &word);
tx_wcid = rt2x00_get_field32(word, TXWI_W1_WIRELESS_CLI_ID);
tx_ack = rt2x00_get_field32(word, TXWI_W1_ACK);
tx_pid = rt2x00_get_field32(word, TXWI_W1_PACKETID);
if (wcid != tx_wcid || ack != tx_ack || (!is_agg && pid != tx_pid)) {
rt2x00_dbg(entry->queue->rt2x00dev,
"TX status report missed for queue %d entry %d\n",
entry->queue->qid, entry->entry_idx);
return TXDONE_UNKNOWN;
}
return TXDONE_SUCCESS;
}
static void rt2800usb_txdone(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
struct queue_entry *entry;
u32 reg;
u8 qid;
enum txdone_entry_desc_flags done_status;
while (kfifo_get(&rt2x00dev->txstatus_fifo, &reg)) {
qid = rt2x00_get_field32(reg, TX_STA_FIFO_PID_QUEUE);
queue = rt2x00queue_get_tx_queue(rt2x00dev, qid);
if (unlikely(rt2x00queue_empty(queue))) {
rt2x00_dbg(rt2x00dev, "Got TX status for an empty queue %u, dropping\n",
qid);
break;
}
entry = rt2x00queue_get_entry(queue, Q_INDEX_DONE);
if (unlikely(test_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags) ||
!test_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags))) {
rt2x00_warn(rt2x00dev, "Data pending for entry %u in queue %u\n",
entry->entry_idx, qid);
break;
}
done_status = rt2800usb_txdone_entry_check(entry, reg);
if (likely(done_status == TXDONE_SUCCESS))
rt2800_txdone_entry(entry, reg, rt2800usb_get_txwi(entry));
else
rt2x00lib_txdone_noinfo(entry, done_status);
}
}
static void rt2800usb_txdone_nostatus(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
struct queue_entry *entry;
tx_queue_for_each(rt2x00dev, queue) {
while (!rt2x00queue_empty(queue)) {
entry = rt2x00queue_get_entry(queue, Q_INDEX_DONE);
if (test_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags) ||
!test_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags))
break;
if (test_bit(ENTRY_DATA_IO_FAILED, &entry->flags))
rt2x00lib_txdone_noinfo(entry, TXDONE_FAILURE);
else if (rt2800usb_entry_txstatus_timeout(entry))
rt2x00lib_txdone_noinfo(entry, TXDONE_UNKNOWN);
else
break;
}
}
}
static void rt2800usb_work_txdone(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, txdone_work);
while (!kfifo_is_empty(&rt2x00dev->txstatus_fifo) ||
rt2800usb_txstatus_timeout(rt2x00dev)) {
rt2800usb_txdone(rt2x00dev);
rt2800usb_txdone_nostatus(rt2x00dev);
if (rt2800usb_txstatus_pending(rt2x00dev))
rt2800usb_async_read_tx_status(rt2x00dev);
}
}
static void rt2800usb_fill_rxdone(struct queue_entry *entry,
struct rxdone_entry_desc *rxdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
__le32 *rxi = (__le32 *)entry->skb->data;
__le32 *rxd;
u32 word;
int rx_pkt_len;
memcpy(skbdesc->desc, rxi, skbdesc->desc_len);
rt2x00_desc_read(rxi, 0, &word);
rx_pkt_len = rt2x00_get_field32(word, RXINFO_W0_USB_DMA_RX_PKT_LEN);
skb_pull(entry->skb, RXINFO_DESC_SIZE);
if (unlikely(rx_pkt_len == 0 ||
rx_pkt_len > entry->queue->data_size)) {
rt2x00_err(entry->queue->rt2x00dev,
"Bad frame size %d, forcing to 0\n", rx_pkt_len);
return;
}
rxd = (__le32 *)(entry->skb->data + rx_pkt_len);
rt2x00_desc_read(rxd, 0, &word);
if (rt2x00_get_field32(word, RXD_W0_CRC_ERROR))
rxdesc->flags |= RX_FLAG_FAILED_FCS_CRC;
rxdesc->cipher_status = rt2x00_get_field32(word, RXD_W0_CIPHER_ERROR);
if (rt2x00_get_field32(word, RXD_W0_DECRYPTED)) {
rxdesc->flags |= RX_FLAG_IV_STRIPPED;
rxdesc->flags |= RX_FLAG_MMIC_STRIPPED;
if (rxdesc->cipher_status == RX_CRYPTO_SUCCESS)
rxdesc->flags |= RX_FLAG_DECRYPTED;
else if (rxdesc->cipher_status == RX_CRYPTO_FAIL_MIC)
rxdesc->flags |= RX_FLAG_MMIC_ERROR;
}
if (rt2x00_get_field32(word, RXD_W0_MY_BSS))
rxdesc->dev_flags |= RXDONE_MY_BSS;
if (rt2x00_get_field32(word, RXD_W0_L2PAD))
rxdesc->dev_flags |= RXDONE_L2PAD;
skb_trim(entry->skb, rx_pkt_len);
rt2800_process_rxwi(entry, rxdesc);
}
static int rt2800usb_efuse_detect(struct rt2x00_dev *rt2x00dev)
{
int retval;
retval = rt2800usb_autorun_detect(rt2x00dev);
if (retval < 0)
return retval;
if (retval)
return 1;
return rt2800_efuse_detect(rt2x00dev);
}
static int rt2800usb_read_eeprom(struct rt2x00_dev *rt2x00dev)
{
int retval;
retval = rt2800usb_efuse_detect(rt2x00dev);
if (retval < 0)
return retval;
if (retval)
retval = rt2800_read_eeprom_efuse(rt2x00dev);
else
retval = rt2x00usb_eeprom_read(rt2x00dev, rt2x00dev->eeprom,
EEPROM_SIZE);
return retval;
}
static int rt2800usb_probe_hw(struct rt2x00_dev *rt2x00dev)
{
int retval;
retval = rt2800_probe_hw(rt2x00dev);
if (retval)
return retval;
rt2x00dev->txstatus_timer.function = rt2800usb_tx_sta_fifo_timeout;
INIT_WORK(&rt2x00dev->txdone_work, rt2800usb_work_txdone);
return 0;
}
static void rt2800usb_queue_init(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
unsigned short txwi_size, rxwi_size;
rt2800_get_txwi_rxwi_size(rt2x00dev, &txwi_size, &rxwi_size);
switch (queue->qid) {
case QID_RX:
queue->limit = 128;
queue->data_size = AGGREGATION_SIZE;
queue->desc_size = RXINFO_DESC_SIZE;
queue->winfo_size = rxwi_size;
queue->priv_size = sizeof(struct queue_entry_priv_usb);
break;
case QID_AC_VO:
case QID_AC_VI:
case QID_AC_BE:
case QID_AC_BK:
queue->limit = 16;
queue->data_size = AGGREGATION_SIZE;
queue->desc_size = TXINFO_DESC_SIZE;
queue->winfo_size = txwi_size;
queue->priv_size = sizeof(struct queue_entry_priv_usb);
break;
case QID_BEACON:
queue->limit = 8;
queue->data_size = MGMT_FRAME_SIZE;
queue->desc_size = TXINFO_DESC_SIZE;
queue->winfo_size = txwi_size;
queue->priv_size = sizeof(struct queue_entry_priv_usb);
break;
case QID_ATIM:
default:
BUG();
break;
}
}
static int rt2800usb_probe(struct usb_interface *usb_intf,
const struct usb_device_id *id)
{
return rt2x00usb_probe(usb_intf, &rt2800usb_ops);
}
