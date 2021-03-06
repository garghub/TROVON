static inline bool rt2800_is_305x_soc(struct rt2x00_dev *rt2x00dev)
{
if (!rt2x00_is_soc(rt2x00dev) ||
!rt2x00_rt(rt2x00dev, RT2872))
return false;
if (rt2x00_rf(rt2x00dev, RF3020) ||
rt2x00_rf(rt2x00dev, RF3021) ||
rt2x00_rf(rt2x00dev, RF3022))
return true;
NOTICE(rt2x00dev, "Unknown RF chipset on rt305x\n");
return false;
}
static void rt2800_bbp_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u8 value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, BBP_CSR_CFG_VALUE, value);
rt2x00_set_field32(&reg, BBP_CSR_CFG_REGNUM, word);
rt2x00_set_field32(&reg, BBP_CSR_CFG_BUSY, 1);
rt2x00_set_field32(&reg, BBP_CSR_CFG_READ_CONTROL, 0);
rt2x00_set_field32(&reg, BBP_CSR_CFG_BBP_RW_MODE, 1);
rt2800_register_write_lock(rt2x00dev, BBP_CSR_CFG, reg);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2800_bbp_read(struct rt2x00_dev *rt2x00dev,
const unsigned int word, u8 *value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, BBP_CSR_CFG_REGNUM, word);
rt2x00_set_field32(&reg, BBP_CSR_CFG_BUSY, 1);
rt2x00_set_field32(&reg, BBP_CSR_CFG_READ_CONTROL, 1);
rt2x00_set_field32(&reg, BBP_CSR_CFG_BBP_RW_MODE, 1);
rt2800_register_write_lock(rt2x00dev, BBP_CSR_CFG, reg);
WAIT_FOR_BBP(rt2x00dev, &reg);
}
*value = rt2x00_get_field32(reg, BBP_CSR_CFG_VALUE);
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2800_rfcsr_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u8 value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_RFCSR(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, RF_CSR_CFG_DATA, value);
rt2x00_set_field32(&reg, RF_CSR_CFG_REGNUM, word);
rt2x00_set_field32(&reg, RF_CSR_CFG_WRITE, 1);
rt2x00_set_field32(&reg, RF_CSR_CFG_BUSY, 1);
rt2800_register_write_lock(rt2x00dev, RF_CSR_CFG, reg);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2800_rfcsr_read(struct rt2x00_dev *rt2x00dev,
const unsigned int word, u8 *value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_RFCSR(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, RF_CSR_CFG_REGNUM, word);
rt2x00_set_field32(&reg, RF_CSR_CFG_WRITE, 0);
rt2x00_set_field32(&reg, RF_CSR_CFG_BUSY, 1);
rt2800_register_write_lock(rt2x00dev, RF_CSR_CFG, reg);
WAIT_FOR_RFCSR(rt2x00dev, &reg);
}
*value = rt2x00_get_field32(reg, RF_CSR_CFG_DATA);
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2800_rf_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u32 value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_RF(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, RF_CSR_CFG0_REG_VALUE_BW, value);
rt2x00_set_field32(&reg, RF_CSR_CFG0_STANDBYMODE, 0);
rt2x00_set_field32(&reg, RF_CSR_CFG0_SEL, 0);
rt2x00_set_field32(&reg, RF_CSR_CFG0_BUSY, 1);
rt2800_register_write_lock(rt2x00dev, RF_CSR_CFG0, reg);
rt2x00_rf_write(rt2x00dev, word, value);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static int rt2800_enable_wlan_rt3290(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
int i, count;
rt2800_register_read(rt2x00dev, WLAN_FUN_CTRL, &reg);
if (rt2x00_get_field32(reg, WLAN_EN))
return 0;
rt2x00_set_field32(&reg, WLAN_GPIO_OUT_OE_BIT_ALL, 0xff);
rt2x00_set_field32(&reg, FRC_WL_ANT_SET, 1);
rt2x00_set_field32(&reg, WLAN_CLK_EN, 0);
rt2x00_set_field32(&reg, WLAN_EN, 1);
rt2800_register_write(rt2x00dev, WLAN_FUN_CTRL, reg);
udelay(REGISTER_BUSY_DELAY);
count = 0;
do {
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2800_register_read(rt2x00dev, CMB_CTRL, &reg);
if (rt2x00_get_field32(reg, PLL_LD) &&
rt2x00_get_field32(reg, XTAL_RDY))
break;
udelay(REGISTER_BUSY_DELAY);
}
if (i >= REGISTER_BUSY_COUNT) {
if (count >= 10)
return -EIO;
rt2800_register_write(rt2x00dev, 0x58, 0x018);
udelay(REGISTER_BUSY_DELAY);
rt2800_register_write(rt2x00dev, 0x58, 0x418);
udelay(REGISTER_BUSY_DELAY);
rt2800_register_write(rt2x00dev, 0x58, 0x618);
udelay(REGISTER_BUSY_DELAY);
count++;
} else {
count = 0;
}
rt2800_register_read(rt2x00dev, WLAN_FUN_CTRL, &reg);
rt2x00_set_field32(&reg, PCIE_APP0_CLK_REQ, 0);
rt2x00_set_field32(&reg, WLAN_CLK_EN, 1);
rt2x00_set_field32(&reg, WLAN_RESET, 1);
rt2800_register_write(rt2x00dev, WLAN_FUN_CTRL, reg);
udelay(10);
rt2x00_set_field32(&reg, WLAN_RESET, 0);
rt2800_register_write(rt2x00dev, WLAN_FUN_CTRL, reg);
udelay(10);
rt2800_register_write(rt2x00dev, INT_SOURCE_CSR, 0x7fffffff);
} while (count != 0);
return 0;
}
void rt2800_mcu_request(struct rt2x00_dev *rt2x00dev,
const u8 command, const u8 token,
const u8 arg0, const u8 arg1)
{
u32 reg;
if (rt2x00_is_soc(rt2x00dev))
return;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_MCU(rt2x00dev, &reg)) {
rt2x00_set_field32(&reg, H2M_MAILBOX_CSR_OWNER, 1);
rt2x00_set_field32(&reg, H2M_MAILBOX_CSR_CMD_TOKEN, token);
rt2x00_set_field32(&reg, H2M_MAILBOX_CSR_ARG0, arg0);
rt2x00_set_field32(&reg, H2M_MAILBOX_CSR_ARG1, arg1);
rt2800_register_write_lock(rt2x00dev, H2M_MAILBOX_CSR, reg);
reg = 0;
rt2x00_set_field32(&reg, HOST_CMD_CSR_HOST_COMMAND, command);
rt2800_register_write_lock(rt2x00dev, HOST_CMD_CSR, reg);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
int rt2800_wait_csr_ready(struct rt2x00_dev *rt2x00dev)
{
unsigned int i = 0;
u32 reg;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2800_register_read(rt2x00dev, MAC_CSR0, &reg);
if (reg && reg != ~0)
return 0;
msleep(1);
}
ERROR(rt2x00dev, "Unstable hardware.\n");
return -EBUSY;
}
int rt2800_wait_wpdma_ready(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u32 reg;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2800_register_read(rt2x00dev, WPDMA_GLO_CFG, &reg);
if (!rt2x00_get_field32(reg, WPDMA_GLO_CFG_TX_DMA_BUSY) &&
!rt2x00_get_field32(reg, WPDMA_GLO_CFG_RX_DMA_BUSY))
return 0;
msleep(10);
}
ERROR(rt2x00dev, "WPDMA TX/RX busy [0x%08x].\n", reg);
return -EACCES;
}
void rt2800_disable_wpdma(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
rt2800_register_read(rt2x00dev, WPDMA_GLO_CFG, &reg);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_ENABLE_TX_DMA, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_TX_DMA_BUSY, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_ENABLE_RX_DMA, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_RX_DMA_BUSY, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_TX_WRITEBACK_DONE, 1);
rt2800_register_write(rt2x00dev, WPDMA_GLO_CFG, reg);
}
static bool rt2800_check_firmware_crc(const u8 *data, const size_t len)
{
u16 fw_crc;
u16 crc;
fw_crc = (data[len - 2] << 8 | data[len - 1]);
crc = crc_ccitt(~0, data, len - 2);
crc = swab16(crc);
return fw_crc == crc;
}
int rt2800_check_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
size_t offset = 0;
size_t fw_len;
bool multiple;
if (rt2x00_is_usb(rt2x00dev) || rt2x00_rt(rt2x00dev, RT3290))
fw_len = 4096;
else
fw_len = 8192;
multiple = true;
if (len != fw_len && (!multiple || (len % fw_len) != 0))
return FW_BAD_LENGTH;
if (rt2x00_is_usb(rt2x00dev) &&
!rt2x00_rt(rt2x00dev, RT2860) &&
!rt2x00_rt(rt2x00dev, RT2872) &&
!rt2x00_rt(rt2x00dev, RT3070) &&
((len / fw_len) == 1))
return FW_BAD_VERSION;
while (offset < len) {
if (!rt2800_check_firmware_crc(data + offset, fw_len))
return FW_BAD_CRC;
offset += fw_len;
}
return FW_OK;
}
int rt2800_load_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
unsigned int i;
u32 reg;
int retval;
if (rt2x00_rt(rt2x00dev, RT3290)) {
retval = rt2800_enable_wlan_rt3290(rt2x00dev);
if (retval)
return -EBUSY;
}
rt2800_register_write(rt2x00dev, AUTOWAKEUP_CFG, 0x00000000);
if (rt2800_wait_csr_ready(rt2x00dev))
return -EBUSY;
if (rt2x00_is_pci(rt2x00dev)) {
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT3572) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_register_read(rt2x00dev, AUX_CTRL, &reg);
rt2x00_set_field32(&reg, AUX_CTRL_FORCE_PCIE_CLK, 1);
rt2x00_set_field32(&reg, AUX_CTRL_WAKE_PCIE_EN, 1);
rt2800_register_write(rt2x00dev, AUX_CTRL, reg);
}
rt2800_register_write(rt2x00dev, PWR_PIN_CFG, 0x00000002);
}
rt2800_disable_wpdma(rt2x00dev);
rt2800_drv_write_firmware(rt2x00dev, data, len);
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2800_register_read(rt2x00dev, PBF_SYS_CTRL, &reg);
if (rt2x00_get_field32(reg, PBF_SYS_CTRL_READY))
break;
msleep(1);
}
if (i == REGISTER_BUSY_COUNT) {
ERROR(rt2x00dev, "PBF system register not ready.\n");
return -EBUSY;
}
rt2800_disable_wpdma(rt2x00dev);
rt2800_register_write(rt2x00dev, H2M_BBP_AGENT, 0);
rt2800_register_write(rt2x00dev, H2M_MAILBOX_CSR, 0);
if (rt2x00_is_usb(rt2x00dev))
rt2800_register_write(rt2x00dev, H2M_INT_SRC, 0);
msleep(1);
return 0;
}
void rt2800_write_tx_data(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
__le32 *txwi = rt2800_drv_get_txwi(entry);
u32 word;
rt2x00_desc_read(txwi, 0, &word);
rt2x00_set_field32(&word, TXWI_W0_FRAG,
test_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W0_MIMO_PS,
test_bit(ENTRY_TXD_HT_MIMO_PS, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W0_CF_ACK, 0);
rt2x00_set_field32(&word, TXWI_W0_TS,
test_bit(ENTRY_TXD_REQ_TIMESTAMP, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W0_AMPDU,
test_bit(ENTRY_TXD_HT_AMPDU, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W0_MPDU_DENSITY,
txdesc->u.ht.mpdu_density);
rt2x00_set_field32(&word, TXWI_W0_TX_OP, txdesc->u.ht.txop);
rt2x00_set_field32(&word, TXWI_W0_MCS, txdesc->u.ht.mcs);
rt2x00_set_field32(&word, TXWI_W0_BW,
test_bit(ENTRY_TXD_HT_BW_40, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W0_SHORT_GI,
test_bit(ENTRY_TXD_HT_SHORT_GI, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W0_STBC, txdesc->u.ht.stbc);
rt2x00_set_field32(&word, TXWI_W0_PHYMODE, txdesc->rate_mode);
rt2x00_desc_write(txwi, 0, word);
rt2x00_desc_read(txwi, 1, &word);
rt2x00_set_field32(&word, TXWI_W1_ACK,
test_bit(ENTRY_TXD_ACK, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W1_NSEQ,
test_bit(ENTRY_TXD_GENERATE_SEQ, &txdesc->flags));
rt2x00_set_field32(&word, TXWI_W1_BW_WIN_SIZE, txdesc->u.ht.ba_size);
rt2x00_set_field32(&word, TXWI_W1_WIRELESS_CLI_ID,
test_bit(ENTRY_TXD_ENCRYPT, &txdesc->flags) ?
txdesc->key_idx : txdesc->u.ht.wcid);
rt2x00_set_field32(&word, TXWI_W1_MPDU_TOTAL_BYTE_COUNT,
txdesc->length);
rt2x00_set_field32(&word, TXWI_W1_PACKETID_QUEUE, entry->queue->qid);
rt2x00_set_field32(&word, TXWI_W1_PACKETID_ENTRY, (entry->entry_idx % 3) + 1);
rt2x00_desc_write(txwi, 1, word);
_rt2x00_desc_write(txwi, 2, 0 );
_rt2x00_desc_write(txwi, 3, 0 );
}
static int rt2800_agc_to_rssi(struct rt2x00_dev *rt2x00dev, u32 rxwi_w2)
{
s8 rssi0 = rt2x00_get_field32(rxwi_w2, RXWI_W2_RSSI0);
s8 rssi1 = rt2x00_get_field32(rxwi_w2, RXWI_W2_RSSI1);
s8 rssi2 = rt2x00_get_field32(rxwi_w2, RXWI_W2_RSSI2);
u16 eeprom;
u8 offset0;
u8 offset1;
u8 offset2;
if (rt2x00dev->curr_band == IEEE80211_BAND_2GHZ) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_BG, &eeprom);
offset0 = rt2x00_get_field16(eeprom, EEPROM_RSSI_BG_OFFSET0);
offset1 = rt2x00_get_field16(eeprom, EEPROM_RSSI_BG_OFFSET1);
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_BG2, &eeprom);
offset2 = rt2x00_get_field16(eeprom, EEPROM_RSSI_BG2_OFFSET2);
} else {
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_A, &eeprom);
offset0 = rt2x00_get_field16(eeprom, EEPROM_RSSI_A_OFFSET0);
offset1 = rt2x00_get_field16(eeprom, EEPROM_RSSI_A_OFFSET1);
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_A2, &eeprom);
offset2 = rt2x00_get_field16(eeprom, EEPROM_RSSI_A2_OFFSET2);
}
rssi0 = (rssi0) ? (-12 - offset0 - rt2x00dev->lna_gain - rssi0) : -128;
rssi1 = (rssi1) ? (-12 - offset1 - rt2x00dev->lna_gain - rssi1) : -128;
rssi2 = (rssi2) ? (-12 - offset2 - rt2x00dev->lna_gain - rssi2) : -128;
rssi0 = max(rssi0, rssi1);
return (int)max(rssi0, rssi2);
}
void rt2800_process_rxwi(struct queue_entry *entry,
struct rxdone_entry_desc *rxdesc)
{
__le32 *rxwi = (__le32 *) entry->skb->data;
u32 word;
rt2x00_desc_read(rxwi, 0, &word);
rxdesc->cipher = rt2x00_get_field32(word, RXWI_W0_UDF);
rxdesc->size = rt2x00_get_field32(word, RXWI_W0_MPDU_TOTAL_BYTE_COUNT);
rt2x00_desc_read(rxwi, 1, &word);
if (rt2x00_get_field32(word, RXWI_W1_SHORT_GI))
rxdesc->flags |= RX_FLAG_SHORT_GI;
if (rt2x00_get_field32(word, RXWI_W1_BW))
rxdesc->flags |= RX_FLAG_40MHZ;
rxdesc->dev_flags |= RXDONE_SIGNAL_MCS;
rxdesc->signal = rt2x00_get_field32(word, RXWI_W1_MCS);
rxdesc->rate_mode = rt2x00_get_field32(word, RXWI_W1_PHYMODE);
if (rxdesc->rate_mode == RATE_MODE_CCK)
rxdesc->signal &= ~0x8;
rt2x00_desc_read(rxwi, 2, &word);
rxdesc->rssi = rt2800_agc_to_rssi(entry->queue->rt2x00dev, word);
skb_pull(entry->skb, RXWI_DESC_SIZE);
}
void rt2800_txdone_entry(struct queue_entry *entry, u32 status, __le32 *txwi)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
struct txdone_entry_desc txdesc;
u32 word;
u16 mcs, real_mcs;
int aggr, ampdu;
txdesc.flags = 0;
rt2x00_desc_read(txwi, 0, &word);
mcs = rt2x00_get_field32(word, TXWI_W0_MCS);
ampdu = rt2x00_get_field32(word, TXWI_W0_AMPDU);
real_mcs = rt2x00_get_field32(status, TX_STA_FIFO_MCS);
aggr = rt2x00_get_field32(status, TX_STA_FIFO_TX_AGGRE);
if (unlikely(aggr == 1 && ampdu == 0 && real_mcs != mcs)) {
skbdesc->tx_rate_idx = real_mcs;
mcs = real_mcs;
}
if (aggr == 1 || ampdu == 1)
__set_bit(TXDONE_AMPDU, &txdesc.flags);
if (rt2x00_get_field32(status, TX_STA_FIFO_TX_SUCCESS)) {
__set_bit(TXDONE_SUCCESS, &txdesc.flags);
txdesc.retry = ((mcs > real_mcs) ? mcs - real_mcs : 0);
} else {
__set_bit(TXDONE_FAILURE, &txdesc.flags);
txdesc.retry = rt2x00dev->long_retry;
}
if (txdesc.retry)
__set_bit(TXDONE_FALLBACK, &txdesc.flags);
rt2x00lib_txdone(entry, &txdesc);
}
void rt2800_write_beacon(struct queue_entry *entry, struct txentry_desc *txdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
unsigned int beacon_base;
unsigned int padding_len;
u32 orig_reg, reg;
rt2800_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
orig_reg = reg;
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 0);
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, reg);
memset(skb_push(entry->skb, TXWI_DESC_SIZE), 0, TXWI_DESC_SIZE);
skbdesc->flags |= SKBDESC_DESC_IN_SKB;
skbdesc->desc = entry->skb->data;
skbdesc->desc_len = TXWI_DESC_SIZE;
rt2800_write_tx_data(entry, txdesc);
rt2x00debug_dump_frame(rt2x00dev, DUMP_FRAME_BEACON, entry->skb);
padding_len = roundup(entry->skb->len, 4) - entry->skb->len;
if (padding_len && skb_pad(entry->skb, padding_len)) {
ERROR(rt2x00dev, "Failure padding beacon, aborting\n");
entry->skb = NULL;
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, orig_reg);
return;
}
beacon_base = HW_BEACON_OFFSET(entry->entry_idx);
rt2800_register_multiwrite(rt2x00dev, beacon_base, entry->skb->data,
entry->skb->len + padding_len);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 1);
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, reg);
dev_kfree_skb_any(entry->skb);
entry->skb = NULL;
}
static inline void rt2800_clear_beacon_register(struct rt2x00_dev *rt2x00dev,
unsigned int beacon_base)
{
int i;
for (i = 0; i < TXWI_DESC_SIZE; i += sizeof(__le32))
rt2800_register_write(rt2x00dev, beacon_base + i, 0);
}
void rt2800_clear_beacon(struct queue_entry *entry)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
u32 reg;
rt2800_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 0);
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, reg);
rt2800_clear_beacon_register(rt2x00dev,
HW_BEACON_OFFSET(entry->entry_idx));
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 1);
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, reg);
}
int rt2800_rfkill_poll(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
if (rt2x00_rt(rt2x00dev, RT3290)) {
rt2800_register_read(rt2x00dev, WLAN_FUN_CTRL, &reg);
return rt2x00_get_field32(reg, WLAN_GPIO_IN_BIT0);
} else {
rt2800_register_read(rt2x00dev, GPIO_CTRL_CFG, &reg);
return rt2x00_get_field32(reg, GPIO_CTRL_CFG_BIT2);
}
}
static void rt2800_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct rt2x00_led *led =
container_of(led_cdev, struct rt2x00_led, led_dev);
unsigned int enabled = brightness != LED_OFF;
unsigned int bg_mode =
(enabled && led->rt2x00dev->curr_band == IEEE80211_BAND_2GHZ);
unsigned int polarity =
rt2x00_get_field16(led->rt2x00dev->led_mcu_reg,
EEPROM_FREQ_LED_POLARITY);
unsigned int ledmode =
rt2x00_get_field16(led->rt2x00dev->led_mcu_reg,
EEPROM_FREQ_LED_MODE);
u32 reg;
if (rt2x00_is_soc(led->rt2x00dev)) {
rt2800_register_read(led->rt2x00dev, LED_CFG, &reg);
rt2x00_set_field32(&reg, LED_CFG_LED_POLAR, polarity);
if (led->type == LED_TYPE_RADIO) {
rt2x00_set_field32(&reg, LED_CFG_G_LED_MODE,
enabled ? 3 : 0);
} else if (led->type == LED_TYPE_ASSOC) {
rt2x00_set_field32(&reg, LED_CFG_Y_LED_MODE,
enabled ? 3 : 0);
} else if (led->type == LED_TYPE_QUALITY) {
rt2x00_set_field32(&reg, LED_CFG_R_LED_MODE,
enabled ? 3 : 0);
}
rt2800_register_write(led->rt2x00dev, LED_CFG, reg);
} else {
if (led->type == LED_TYPE_RADIO) {
rt2800_mcu_request(led->rt2x00dev, MCU_LED, 0xff, ledmode,
enabled ? 0x20 : 0);
} else if (led->type == LED_TYPE_ASSOC) {
rt2800_mcu_request(led->rt2x00dev, MCU_LED, 0xff, ledmode,
enabled ? (bg_mode ? 0x60 : 0xa0) : 0x20);
} else if (led->type == LED_TYPE_QUALITY) {
rt2800_mcu_request(led->rt2x00dev, MCU_LED_STRENGTH, 0xff,
(1 << brightness / (LED_FULL / 6)) - 1,
polarity);
}
}
}
static void rt2800_init_led(struct rt2x00_dev *rt2x00dev,
struct rt2x00_led *led, enum led_type type)
{
led->rt2x00dev = rt2x00dev;
led->type = type;
led->led_dev.brightness_set = rt2800_brightness_set;
led->flags = LED_INITIALIZED;
}
static void rt2800_config_wcid(struct rt2x00_dev *rt2x00dev,
const u8 *address,
int wcid)
{
struct mac_wcid_entry wcid_entry;
u32 offset;
offset = MAC_WCID_ENTRY(wcid);
memset(&wcid_entry, 0xff, sizeof(wcid_entry));
if (address)
memcpy(wcid_entry.mac, address, ETH_ALEN);
rt2800_register_multiwrite(rt2x00dev, offset,
&wcid_entry, sizeof(wcid_entry));
}
static void rt2800_delete_wcid_attr(struct rt2x00_dev *rt2x00dev, int wcid)
{
u32 offset;
offset = MAC_WCID_ATTR_ENTRY(wcid);
rt2800_register_write(rt2x00dev, offset, 0);
}
static void rt2800_config_wcid_attr_bssidx(struct rt2x00_dev *rt2x00dev,
int wcid, u32 bssidx)
{
u32 offset = MAC_WCID_ATTR_ENTRY(wcid);
u32 reg;
rt2800_register_read(rt2x00dev, offset, &reg);
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_BSS_IDX, (bssidx & 0x7));
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_BSS_IDX_EXT,
(bssidx & 0x8) >> 3);
rt2800_register_write(rt2x00dev, offset, reg);
}
static void rt2800_config_wcid_attr_cipher(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_crypto *crypto,
struct ieee80211_key_conf *key)
{
struct mac_iveiv_entry iveiv_entry;
u32 offset;
u32 reg;
offset = MAC_WCID_ATTR_ENTRY(key->hw_key_idx);
if (crypto->cmd == SET_KEY) {
rt2800_register_read(rt2x00dev, offset, &reg);
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_KEYTAB,
!!(key->flags & IEEE80211_KEY_FLAG_PAIRWISE));
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_CIPHER,
(crypto->cipher & 0x7));
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_CIPHER_EXT,
(crypto->cipher & 0x8) >> 3);
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_RX_WIUDF, crypto->cipher);
rt2800_register_write(rt2x00dev, offset, reg);
} else {
rt2800_register_read(rt2x00dev, offset, &reg);
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_KEYTAB, 0);
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_CIPHER, 0);
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_CIPHER_EXT, 0);
rt2x00_set_field32(&reg, MAC_WCID_ATTRIBUTE_RX_WIUDF, 0);
rt2800_register_write(rt2x00dev, offset, reg);
}
offset = MAC_IVEIV_ENTRY(key->hw_key_idx);
memset(&iveiv_entry, 0, sizeof(iveiv_entry));
if ((crypto->cipher == CIPHER_TKIP) ||
(crypto->cipher == CIPHER_TKIP_NO_MIC) ||
(crypto->cipher == CIPHER_AES))
iveiv_entry.iv[3] |= 0x20;
iveiv_entry.iv[3] |= key->keyidx << 6;
rt2800_register_multiwrite(rt2x00dev, offset,
&iveiv_entry, sizeof(iveiv_entry));
}
int rt2800_config_shared_key(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_crypto *crypto,
struct ieee80211_key_conf *key)
{
struct hw_key_entry key_entry;
struct rt2x00_field32 field;
u32 offset;
u32 reg;
if (crypto->cmd == SET_KEY) {
key->hw_key_idx = (4 * crypto->bssidx) + key->keyidx;
memcpy(key_entry.key, crypto->key,
sizeof(key_entry.key));
memcpy(key_entry.tx_mic, crypto->tx_mic,
sizeof(key_entry.tx_mic));
memcpy(key_entry.rx_mic, crypto->rx_mic,
sizeof(key_entry.rx_mic));
offset = SHARED_KEY_ENTRY(key->hw_key_idx);
rt2800_register_multiwrite(rt2x00dev, offset,
&key_entry, sizeof(key_entry));
}
field.bit_offset = 4 * (key->hw_key_idx % 8);
field.bit_mask = 0x7 << field.bit_offset;
offset = SHARED_KEY_MODE_ENTRY(key->hw_key_idx / 8);
rt2800_register_read(rt2x00dev, offset, &reg);
rt2x00_set_field32(&reg, field,
(crypto->cmd == SET_KEY) * crypto->cipher);
rt2800_register_write(rt2x00dev, offset, reg);
rt2800_config_wcid(rt2x00dev, crypto->address, key->hw_key_idx);
rt2800_config_wcid_attr_bssidx(rt2x00dev, key->hw_key_idx,
crypto->bssidx);
rt2800_config_wcid_attr_cipher(rt2x00dev, crypto, key);
return 0;
}
static inline int rt2800_find_wcid(struct rt2x00_dev *rt2x00dev)
{
struct mac_wcid_entry wcid_entry;
int idx;
u32 offset;
for (idx = 33; idx <= 222; idx++) {
offset = MAC_WCID_ENTRY(idx);
rt2800_register_multiread(rt2x00dev, offset, &wcid_entry,
sizeof(wcid_entry));
if (is_broadcast_ether_addr(wcid_entry.mac))
return idx;
}
return -1;
}
int rt2800_config_pairwise_key(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_crypto *crypto,
struct ieee80211_key_conf *key)
{
struct hw_key_entry key_entry;
u32 offset;
if (crypto->cmd == SET_KEY) {
if (crypto->wcid < 0)
return -ENOSPC;
key->hw_key_idx = crypto->wcid;
memcpy(key_entry.key, crypto->key,
sizeof(key_entry.key));
memcpy(key_entry.tx_mic, crypto->tx_mic,
sizeof(key_entry.tx_mic));
memcpy(key_entry.rx_mic, crypto->rx_mic,
sizeof(key_entry.rx_mic));
offset = PAIRWISE_KEY_ENTRY(key->hw_key_idx);
rt2800_register_multiwrite(rt2x00dev, offset,
&key_entry, sizeof(key_entry));
}
rt2800_config_wcid_attr_cipher(rt2x00dev, crypto, key);
return 0;
}
int rt2800_sta_add(struct rt2x00_dev *rt2x00dev, struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
int wcid;
struct rt2x00_sta *sta_priv = sta_to_rt2x00_sta(sta);
wcid = rt2800_find_wcid(rt2x00dev);
sta_priv->wcid = wcid;
if (wcid < 0)
return 0;
rt2800_delete_wcid_attr(rt2x00dev, wcid);
rt2800_config_wcid(rt2x00dev, sta->addr, wcid);
rt2800_config_wcid_attr_bssidx(rt2x00dev, wcid,
rt2x00lib_get_bssidx(rt2x00dev, vif));
return 0;
}
int rt2800_sta_remove(struct rt2x00_dev *rt2x00dev, int wcid)
{
rt2800_config_wcid(rt2x00dev, NULL, wcid);
return 0;
}
void rt2800_config_filter(struct rt2x00_dev *rt2x00dev,
const unsigned int filter_flags)
{
u32 reg;
rt2800_register_read(rt2x00dev, RX_FILTER_CFG, &reg);
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_CRC_ERROR,
!(filter_flags & FIF_FCSFAIL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_PHY_ERROR,
!(filter_flags & FIF_PLCPFAIL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_NOT_TO_ME,
!(filter_flags & FIF_PROMISC_IN_BSS));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_NOT_MY_BSSD, 0);
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_VER_ERROR, 1);
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_MULTICAST,
!(filter_flags & FIF_ALLMULTI));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_BROADCAST, 0);
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_DUPLICATE, 1);
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_CF_END_ACK,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_CF_END,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_ACK,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_CTS,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_RTS,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_PSPOLL,
!(filter_flags & FIF_PSPOLL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_BA,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_BAR,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RX_FILTER_CFG_DROP_CNTL,
!(filter_flags & FIF_CONTROL));
rt2800_register_write(rt2x00dev, RX_FILTER_CFG, reg);
}
void rt2800_config_intf(struct rt2x00_dev *rt2x00dev, struct rt2x00_intf *intf,
struct rt2x00intf_conf *conf, const unsigned int flags)
{
u32 reg;
bool update_bssid = false;
if (flags & CONFIG_UPDATE_TYPE) {
rt2800_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_SYNC, conf->sync);
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, reg);
if (conf->sync == TSF_SYNC_AP_NONE) {
rt2800_register_read(rt2x00dev, TBTT_SYNC_CFG, &reg);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_BCN_CWMIN, 0);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_BCN_AIFSN, 1);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_BCN_EXP_WIN, 32);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_TBTT_ADJUST, 0);
rt2800_register_write(rt2x00dev, TBTT_SYNC_CFG, reg);
} else {
rt2800_register_read(rt2x00dev, TBTT_SYNC_CFG, &reg);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_BCN_CWMIN, 4);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_BCN_AIFSN, 2);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_BCN_EXP_WIN, 32);
rt2x00_set_field32(&reg, TBTT_SYNC_CFG_TBTT_ADJUST, 16);
rt2800_register_write(rt2x00dev, TBTT_SYNC_CFG, reg);
}
}
if (flags & CONFIG_UPDATE_MAC) {
if (flags & CONFIG_UPDATE_TYPE &&
conf->sync == TSF_SYNC_AP_NONE) {
memcpy(conf->bssid, conf->mac, sizeof(conf->mac));
update_bssid = true;
}
if (!is_zero_ether_addr((const u8 *)conf->mac)) {
reg = le32_to_cpu(conf->mac[1]);
rt2x00_set_field32(&reg, MAC_ADDR_DW1_UNICAST_TO_ME_MASK, 0xff);
conf->mac[1] = cpu_to_le32(reg);
}
rt2800_register_multiwrite(rt2x00dev, MAC_ADDR_DW0,
conf->mac, sizeof(conf->mac));
}
if ((flags & CONFIG_UPDATE_BSSID) || update_bssid) {
if (!is_zero_ether_addr((const u8 *)conf->bssid)) {
reg = le32_to_cpu(conf->bssid[1]);
rt2x00_set_field32(&reg, MAC_BSSID_DW1_BSS_ID_MASK, 3);
rt2x00_set_field32(&reg, MAC_BSSID_DW1_BSS_BCN_NUM, 7);
conf->bssid[1] = cpu_to_le32(reg);
}
rt2800_register_multiwrite(rt2x00dev, MAC_BSSID_DW0,
conf->bssid, sizeof(conf->bssid));
}
}
static void rt2800_config_ht_opmode(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_erp *erp)
{
bool any_sta_nongf = !!(erp->ht_opmode &
IEEE80211_HT_OP_MODE_NON_GF_STA_PRSNT);
u8 protection = erp->ht_opmode & IEEE80211_HT_OP_MODE_PROTECTION;
u8 mm20_mode, mm40_mode, gf20_mode, gf40_mode;
u16 mm20_rate, mm40_rate, gf20_rate, gf40_rate;
u32 reg;
mm20_rate = gf20_rate = 0x4004;
mm40_rate = gf40_rate = 0x4084;
switch (protection) {
case IEEE80211_HT_OP_MODE_PROTECTION_NONE:
mm20_mode = mm40_mode = gf20_mode = gf40_mode = 0;
break;
case IEEE80211_HT_OP_MODE_PROTECTION_20MHZ:
mm20_mode = gf20_mode = 0;
mm40_mode = gf40_mode = 2;
break;
case IEEE80211_HT_OP_MODE_PROTECTION_NONMEMBER:
case IEEE80211_HT_OP_MODE_PROTECTION_NONHT_MIXED:
mm20_mode = mm40_mode = gf20_mode = gf40_mode = 2;
if (erp->cts_protection) {
mm20_rate = mm40_rate = 0x0003;
gf20_rate = gf40_rate = 0x0003;
}
break;
}
if (any_sta_nongf)
gf20_mode = gf40_mode = 2;
rt2800_register_read(rt2x00dev, MM20_PROT_CFG, &reg);
rt2x00_set_field32(&reg, MM20_PROT_CFG_PROTECT_RATE, mm20_rate);
rt2x00_set_field32(&reg, MM20_PROT_CFG_PROTECT_CTRL, mm20_mode);
rt2800_register_write(rt2x00dev, MM20_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, MM40_PROT_CFG, &reg);
rt2x00_set_field32(&reg, MM40_PROT_CFG_PROTECT_RATE, mm40_rate);
rt2x00_set_field32(&reg, MM40_PROT_CFG_PROTECT_CTRL, mm40_mode);
rt2800_register_write(rt2x00dev, MM40_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, GF20_PROT_CFG, &reg);
rt2x00_set_field32(&reg, GF20_PROT_CFG_PROTECT_RATE, gf20_rate);
rt2x00_set_field32(&reg, GF20_PROT_CFG_PROTECT_CTRL, gf20_mode);
rt2800_register_write(rt2x00dev, GF20_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, GF40_PROT_CFG, &reg);
rt2x00_set_field32(&reg, GF40_PROT_CFG_PROTECT_RATE, gf40_rate);
rt2x00_set_field32(&reg, GF40_PROT_CFG_PROTECT_CTRL, gf40_mode);
rt2800_register_write(rt2x00dev, GF40_PROT_CFG, reg);
}
void rt2800_config_erp(struct rt2x00_dev *rt2x00dev, struct rt2x00lib_erp *erp,
u32 changed)
{
u32 reg;
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
rt2800_register_read(rt2x00dev, AUTO_RSP_CFG, &reg);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_BAC_ACK_POLICY,
!!erp->short_preamble);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_AR_PREAMBLE,
!!erp->short_preamble);
rt2800_register_write(rt2x00dev, AUTO_RSP_CFG, reg);
}
if (changed & BSS_CHANGED_ERP_CTS_PROT) {
rt2800_register_read(rt2x00dev, OFDM_PROT_CFG, &reg);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_PROTECT_CTRL,
erp->cts_protection ? 2 : 0);
rt2800_register_write(rt2x00dev, OFDM_PROT_CFG, reg);
}
if (changed & BSS_CHANGED_BASIC_RATES) {
rt2800_register_write(rt2x00dev, LEGACY_BASIC_RATE,
erp->basic_rates);
rt2800_register_write(rt2x00dev, HT_BASIC_RATE, 0x00008003);
}
if (changed & BSS_CHANGED_ERP_SLOT) {
rt2800_register_read(rt2x00dev, BKOFF_SLOT_CFG, &reg);
rt2x00_set_field32(&reg, BKOFF_SLOT_CFG_SLOT_TIME,
erp->slot_time);
rt2800_register_write(rt2x00dev, BKOFF_SLOT_CFG, reg);
rt2800_register_read(rt2x00dev, XIFS_TIME_CFG, &reg);
rt2x00_set_field32(&reg, XIFS_TIME_CFG_EIFS, erp->eifs);
rt2800_register_write(rt2x00dev, XIFS_TIME_CFG, reg);
}
if (changed & BSS_CHANGED_BEACON_INT) {
rt2800_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_INTERVAL,
erp->beacon_int * 16);
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, reg);
}
if (changed & BSS_CHANGED_HT)
rt2800_config_ht_opmode(rt2x00dev, erp);
}
static void rt2800_config_3572bt_ant(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
u16 eeprom;
u8 led_ctrl, led_g_mode, led_r_mode;
rt2800_register_read(rt2x00dev, GPIO_SWITCH, &reg);
if (rt2x00dev->curr_band == IEEE80211_BAND_5GHZ) {
rt2x00_set_field32(&reg, GPIO_SWITCH_0, 1);
rt2x00_set_field32(&reg, GPIO_SWITCH_1, 1);
} else {
rt2x00_set_field32(&reg, GPIO_SWITCH_0, 0);
rt2x00_set_field32(&reg, GPIO_SWITCH_1, 0);
}
rt2800_register_write(rt2x00dev, GPIO_SWITCH, reg);
rt2800_register_read(rt2x00dev, LED_CFG, &reg);
led_g_mode = rt2x00_get_field32(reg, LED_CFG_LED_POLAR) ? 3 : 0;
led_r_mode = rt2x00_get_field32(reg, LED_CFG_LED_POLAR) ? 0 : 3;
if (led_g_mode != rt2x00_get_field32(reg, LED_CFG_G_LED_MODE) ||
led_r_mode != rt2x00_get_field32(reg, LED_CFG_R_LED_MODE)) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_FREQ, &eeprom);
led_ctrl = rt2x00_get_field16(eeprom, EEPROM_FREQ_LED_MODE);
if (led_ctrl == 0 || led_ctrl > 0x40) {
rt2x00_set_field32(&reg, LED_CFG_G_LED_MODE, led_g_mode);
rt2x00_set_field32(&reg, LED_CFG_R_LED_MODE, led_r_mode);
rt2800_register_write(rt2x00dev, LED_CFG, reg);
} else {
rt2800_mcu_request(rt2x00dev, MCU_BAND_SELECT, 0xff,
(led_g_mode << 2) | led_r_mode, 1);
}
}
}
static void rt2800_set_ant_diversity(struct rt2x00_dev *rt2x00dev,
enum antenna ant)
{
u32 reg;
u8 eesk_pin = (ant == ANTENNA_A) ? 1 : 0;
u8 gpio_bit3 = (ant == ANTENNA_A) ? 0 : 1;
if (rt2x00_is_pci(rt2x00dev)) {
rt2800_register_read(rt2x00dev, E2PROM_CSR, &reg);
rt2x00_set_field32(&reg, E2PROM_CSR_DATA_CLOCK, eesk_pin);
rt2800_register_write(rt2x00dev, E2PROM_CSR, reg);
} else if (rt2x00_is_usb(rt2x00dev))
rt2800_mcu_request(rt2x00dev, MCU_ANT_SELECT, 0xff,
eesk_pin, 0);
rt2800_register_read(rt2x00dev, GPIO_CTRL_CFG, &reg);
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_GPIOD_BIT3, 0);
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_BIT3, gpio_bit3);
rt2800_register_write(rt2x00dev, GPIO_CTRL_CFG, reg);
}
void rt2800_config_ant(struct rt2x00_dev *rt2x00dev, struct antenna_setup *ant)
{
u8 r1;
u8 r3;
u16 eeprom;
rt2800_bbp_read(rt2x00dev, 1, &r1);
rt2800_bbp_read(rt2x00dev, 3, &r3);
if (rt2x00_rt(rt2x00dev, RT3572) &&
test_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags))
rt2800_config_3572bt_ant(rt2x00dev);
switch (ant->tx_chain_num) {
case 1:
rt2x00_set_field8(&r1, BBP1_TX_ANTENNA, 0);
break;
case 2:
if (rt2x00_rt(rt2x00dev, RT3572) &&
test_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags))
rt2x00_set_field8(&r1, BBP1_TX_ANTENNA, 1);
else
rt2x00_set_field8(&r1, BBP1_TX_ANTENNA, 2);
break;
case 3:
rt2x00_set_field8(&r1, BBP1_TX_ANTENNA, 0);
break;
}
switch (ant->rx_chain_num) {
case 1:
if (rt2x00_rt(rt2x00dev, RT3070) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3390)) {
rt2x00_eeprom_read(rt2x00dev,
EEPROM_NIC_CONF1, &eeprom);
if (rt2x00_get_field16(eeprom,
EEPROM_NIC_CONF1_ANT_DIVERSITY))
rt2800_set_ant_diversity(rt2x00dev,
rt2x00dev->default_ant.rx);
}
rt2x00_set_field8(&r3, BBP3_RX_ANTENNA, 0);
break;
case 2:
if (rt2x00_rt(rt2x00dev, RT3572) &&
test_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags)) {
rt2x00_set_field8(&r3, BBP3_RX_ADC, 1);
rt2x00_set_field8(&r3, BBP3_RX_ANTENNA,
rt2x00dev->curr_band == IEEE80211_BAND_5GHZ);
rt2800_set_ant_diversity(rt2x00dev, ANTENNA_B);
} else {
rt2x00_set_field8(&r3, BBP3_RX_ANTENNA, 1);
}
break;
case 3:
rt2x00_set_field8(&r3, BBP3_RX_ANTENNA, 2);
break;
}
rt2800_bbp_write(rt2x00dev, 3, r3);
rt2800_bbp_write(rt2x00dev, 1, r1);
}
static void rt2800_config_lna_gain(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
u16 eeprom;
short lna_gain;
if (libconf->rf.channel <= 14) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_LNA, &eeprom);
lna_gain = rt2x00_get_field16(eeprom, EEPROM_LNA_BG);
} else if (libconf->rf.channel <= 64) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_LNA, &eeprom);
lna_gain = rt2x00_get_field16(eeprom, EEPROM_LNA_A0);
} else if (libconf->rf.channel <= 128) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_BG2, &eeprom);
lna_gain = rt2x00_get_field16(eeprom, EEPROM_RSSI_BG2_LNA_A1);
} else {
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_A2, &eeprom);
lna_gain = rt2x00_get_field16(eeprom, EEPROM_RSSI_A2_LNA_A2);
}
rt2x00dev->lna_gain = lna_gain;
}
static void rt2800_config_channel_rf2xxx(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf,
struct rf_channel *rf,
struct channel_info *info)
{
rt2x00_set_field32(&rf->rf4, RF4_FREQ_OFFSET, rt2x00dev->freq_offset);
if (rt2x00dev->default_ant.tx_chain_num == 1)
rt2x00_set_field32(&rf->rf2, RF2_ANTENNA_TX1, 1);
if (rt2x00dev->default_ant.rx_chain_num == 1) {
rt2x00_set_field32(&rf->rf2, RF2_ANTENNA_RX1, 1);
rt2x00_set_field32(&rf->rf2, RF2_ANTENNA_RX2, 1);
} else if (rt2x00dev->default_ant.rx_chain_num == 2)
rt2x00_set_field32(&rf->rf2, RF2_ANTENNA_RX2, 1);
if (rf->channel > 14) {
rt2x00_set_field32(&rf->rf3, RF3_TXPOWER_A_7DBM_BOOST,
(info->default_power1 >= 0));
if (info->default_power1 < 0)
info->default_power1 += 7;
rt2x00_set_field32(&rf->rf3, RF3_TXPOWER_A, info->default_power1);
rt2x00_set_field32(&rf->rf4, RF4_TXPOWER_A_7DBM_BOOST,
(info->default_power2 >= 0));
if (info->default_power2 < 0)
info->default_power2 += 7;
rt2x00_set_field32(&rf->rf4, RF4_TXPOWER_A, info->default_power2);
} else {
rt2x00_set_field32(&rf->rf3, RF3_TXPOWER_G, info->default_power1);
rt2x00_set_field32(&rf->rf4, RF4_TXPOWER_G, info->default_power2);
}
rt2x00_set_field32(&rf->rf4, RF4_HT40, conf_is_ht40(conf));
rt2800_rf_write(rt2x00dev, 1, rf->rf1);
rt2800_rf_write(rt2x00dev, 2, rf->rf2);
rt2800_rf_write(rt2x00dev, 3, rf->rf3 & ~0x00000004);
rt2800_rf_write(rt2x00dev, 4, rf->rf4);
udelay(200);
rt2800_rf_write(rt2x00dev, 1, rf->rf1);
rt2800_rf_write(rt2x00dev, 2, rf->rf2);
rt2800_rf_write(rt2x00dev, 3, rf->rf3 | 0x00000004);
rt2800_rf_write(rt2x00dev, 4, rf->rf4);
udelay(200);
rt2800_rf_write(rt2x00dev, 1, rf->rf1);
rt2800_rf_write(rt2x00dev, 2, rf->rf2);
rt2800_rf_write(rt2x00dev, 3, rf->rf3 & ~0x00000004);
rt2800_rf_write(rt2x00dev, 4, rf->rf4);
}
static void rt2800_config_channel_rf3xxx(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf,
struct rf_channel *rf,
struct channel_info *info)
{
struct rt2800_drv_data *drv_data = rt2x00dev->drv_data;
u8 rfcsr, calib_tx, calib_rx;
rt2800_rfcsr_write(rt2x00dev, 2, rf->rf1);
rt2800_rfcsr_read(rt2x00dev, 3, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR3_K, rf->rf3);
rt2800_rfcsr_write(rt2x00dev, 3, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 6, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR6_R1, rf->rf2);
rt2800_rfcsr_write(rt2x00dev, 6, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 12, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR12_TX_POWER, info->default_power1);
rt2800_rfcsr_write(rt2x00dev, 12, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 13, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR13_TX_POWER, info->default_power2);
rt2800_rfcsr_write(rt2x00dev, 13, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 1, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR1_RX0_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_TX0_PD, 0);
if (rt2x00_rt(rt2x00dev, RT3390)) {
rt2x00_set_field8(&rfcsr, RFCSR1_RX1_PD,
rt2x00dev->default_ant.rx_chain_num == 1);
rt2x00_set_field8(&rfcsr, RFCSR1_TX1_PD,
rt2x00dev->default_ant.tx_chain_num == 1);
} else {
rt2x00_set_field8(&rfcsr, RFCSR1_RX1_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_TX1_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_RX2_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_TX2_PD, 0);
switch (rt2x00dev->default_ant.tx_chain_num) {
case 1:
rt2x00_set_field8(&rfcsr, RFCSR1_TX1_PD, 1);
case 2:
rt2x00_set_field8(&rfcsr, RFCSR1_TX2_PD, 1);
break;
}
switch (rt2x00dev->default_ant.rx_chain_num) {
case 1:
rt2x00_set_field8(&rfcsr, RFCSR1_RX1_PD, 1);
case 2:
rt2x00_set_field8(&rfcsr, RFCSR1_RX2_PD, 1);
break;
}
}
rt2800_rfcsr_write(rt2x00dev, 1, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 30, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 1);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
msleep(1);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 0);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 23, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR23_FREQ_OFFSET, rt2x00dev->freq_offset);
rt2800_rfcsr_write(rt2x00dev, 23, rfcsr);
if (rt2x00_rt(rt2x00dev, RT3390)) {
calib_tx = conf_is_ht40(conf) ? 0x68 : 0x4f;
calib_rx = conf_is_ht40(conf) ? 0x6f : 0x4f;
} else {
if (conf_is_ht40(conf)) {
calib_tx = drv_data->calibration_bw40;
calib_rx = drv_data->calibration_bw40;
} else {
calib_tx = drv_data->calibration_bw20;
calib_rx = drv_data->calibration_bw20;
}
}
rt2800_rfcsr_read(rt2x00dev, 24, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR24_TX_CALIB, calib_tx);
rt2800_rfcsr_write(rt2x00dev, 24, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 31, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR31_RX_CALIB, calib_rx);
rt2800_rfcsr_write(rt2x00dev, 31, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 7, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR7_RF_TUNING, 1);
rt2800_rfcsr_write(rt2x00dev, 7, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 30, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 1);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
msleep(1);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 0);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
}
static void rt2800_config_channel_rf3052(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf,
struct rf_channel *rf,
struct channel_info *info)
{
struct rt2800_drv_data *drv_data = rt2x00dev->drv_data;
u8 rfcsr;
u32 reg;
if (rf->channel <= 14) {
rt2800_bbp_write(rt2x00dev, 25, drv_data->bbp25);
rt2800_bbp_write(rt2x00dev, 26, drv_data->bbp26);
} else {
rt2800_bbp_write(rt2x00dev, 25, 0x09);
rt2800_bbp_write(rt2x00dev, 26, 0xff);
}
rt2800_rfcsr_write(rt2x00dev, 2, rf->rf1);
rt2800_rfcsr_write(rt2x00dev, 3, rf->rf3);
rt2800_rfcsr_read(rt2x00dev, 6, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR6_R1, rf->rf2);
if (rf->channel <= 14)
rt2x00_set_field8(&rfcsr, RFCSR6_TXDIV, 2);
else
rt2x00_set_field8(&rfcsr, RFCSR6_TXDIV, 1);
rt2800_rfcsr_write(rt2x00dev, 6, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 5, &rfcsr);
if (rf->channel <= 14)
rt2x00_set_field8(&rfcsr, RFCSR5_R1, 1);
else
rt2x00_set_field8(&rfcsr, RFCSR5_R1, 2);
rt2800_rfcsr_write(rt2x00dev, 5, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 12, &rfcsr);
if (rf->channel <= 14) {
rt2x00_set_field8(&rfcsr, RFCSR12_DR0, 3);
rt2x00_set_field8(&rfcsr, RFCSR12_TX_POWER,
info->default_power1);
} else {
rt2x00_set_field8(&rfcsr, RFCSR12_DR0, 7);
rt2x00_set_field8(&rfcsr, RFCSR12_TX_POWER,
(info->default_power1 & 0x3) |
((info->default_power1 & 0xC) << 1));
}
rt2800_rfcsr_write(rt2x00dev, 12, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 13, &rfcsr);
if (rf->channel <= 14) {
rt2x00_set_field8(&rfcsr, RFCSR13_DR0, 3);
rt2x00_set_field8(&rfcsr, RFCSR13_TX_POWER,
info->default_power2);
} else {
rt2x00_set_field8(&rfcsr, RFCSR13_DR0, 7);
rt2x00_set_field8(&rfcsr, RFCSR13_TX_POWER,
(info->default_power2 & 0x3) |
((info->default_power2 & 0xC) << 1));
}
rt2800_rfcsr_write(rt2x00dev, 13, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 1, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR1_RX0_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_TX0_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_RX1_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_TX1_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_RX2_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_TX2_PD, 0);
if (test_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags)) {
if (rf->channel <= 14) {
rt2x00_set_field8(&rfcsr, RFCSR1_RX0_PD, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_TX0_PD, 1);
}
rt2x00_set_field8(&rfcsr, RFCSR1_RX2_PD, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_TX2_PD, 1);
} else {
switch (rt2x00dev->default_ant.tx_chain_num) {
case 1:
rt2x00_set_field8(&rfcsr, RFCSR1_TX1_PD, 1);
case 2:
rt2x00_set_field8(&rfcsr, RFCSR1_TX2_PD, 1);
break;
}
switch (rt2x00dev->default_ant.rx_chain_num) {
case 1:
rt2x00_set_field8(&rfcsr, RFCSR1_RX1_PD, 1);
case 2:
rt2x00_set_field8(&rfcsr, RFCSR1_RX2_PD, 1);
break;
}
}
rt2800_rfcsr_write(rt2x00dev, 1, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 23, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR23_FREQ_OFFSET, rt2x00dev->freq_offset);
rt2800_rfcsr_write(rt2x00dev, 23, rfcsr);
if (conf_is_ht40(conf)) {
rt2800_rfcsr_write(rt2x00dev, 24, drv_data->calibration_bw40);
rt2800_rfcsr_write(rt2x00dev, 31, drv_data->calibration_bw40);
} else {
rt2800_rfcsr_write(rt2x00dev, 24, drv_data->calibration_bw20);
rt2800_rfcsr_write(rt2x00dev, 31, drv_data->calibration_bw20);
}
if (rf->channel <= 14) {
rt2800_rfcsr_write(rt2x00dev, 7, 0xd8);
rt2800_rfcsr_write(rt2x00dev, 9, 0xc3);
rt2800_rfcsr_write(rt2x00dev, 10, 0xf1);
rt2800_rfcsr_write(rt2x00dev, 11, 0xb9);
rt2800_rfcsr_write(rt2x00dev, 15, 0x53);
rfcsr = 0x4c;
rt2x00_set_field8(&rfcsr, RFCSR16_TXMIXER_GAIN,
drv_data->txmixer_gain_24g);
rt2800_rfcsr_write(rt2x00dev, 16, rfcsr);
rt2800_rfcsr_write(rt2x00dev, 17, 0x23);
rt2800_rfcsr_write(rt2x00dev, 19, 0x93);
rt2800_rfcsr_write(rt2x00dev, 20, 0xb3);
rt2800_rfcsr_write(rt2x00dev, 25, 0x15);
rt2800_rfcsr_write(rt2x00dev, 26, 0x85);
rt2800_rfcsr_write(rt2x00dev, 27, 0x00);
rt2800_rfcsr_write(rt2x00dev, 29, 0x9b);
} else {
rt2800_rfcsr_read(rt2x00dev, 7, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR7_BIT2, 1);
rt2x00_set_field8(&rfcsr, RFCSR7_BIT3, 0);
rt2x00_set_field8(&rfcsr, RFCSR7_BIT4, 1);
rt2x00_set_field8(&rfcsr, RFCSR7_BITS67, 0);
rt2800_rfcsr_write(rt2x00dev, 7, rfcsr);
rt2800_rfcsr_write(rt2x00dev, 9, 0xc0);
rt2800_rfcsr_write(rt2x00dev, 10, 0xf1);
rt2800_rfcsr_write(rt2x00dev, 11, 0x00);
rt2800_rfcsr_write(rt2x00dev, 15, 0x43);
rfcsr = 0x7a;
rt2x00_set_field8(&rfcsr, RFCSR16_TXMIXER_GAIN,
drv_data->txmixer_gain_5g);
rt2800_rfcsr_write(rt2x00dev, 16, rfcsr);
rt2800_rfcsr_write(rt2x00dev, 17, 0x23);
if (rf->channel <= 64) {
rt2800_rfcsr_write(rt2x00dev, 19, 0xb7);
rt2800_rfcsr_write(rt2x00dev, 20, 0xf6);
rt2800_rfcsr_write(rt2x00dev, 25, 0x3d);
} else if (rf->channel <= 128) {
rt2800_rfcsr_write(rt2x00dev, 19, 0x74);
rt2800_rfcsr_write(rt2x00dev, 20, 0xf4);
rt2800_rfcsr_write(rt2x00dev, 25, 0x01);
} else {
rt2800_rfcsr_write(rt2x00dev, 19, 0x72);
rt2800_rfcsr_write(rt2x00dev, 20, 0xf3);
rt2800_rfcsr_write(rt2x00dev, 25, 0x01);
}
rt2800_rfcsr_write(rt2x00dev, 26, 0x87);
rt2800_rfcsr_write(rt2x00dev, 27, 0x01);
rt2800_rfcsr_write(rt2x00dev, 29, 0x9f);
}
rt2800_register_read(rt2x00dev, GPIO_CTRL_CFG, &reg);
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_GPIOD_BIT7, 0);
if (rf->channel <= 14)
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_BIT7, 1);
else
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_BIT7, 0);
rt2800_register_write(rt2x00dev, GPIO_CTRL_CFG, reg);
rt2800_rfcsr_read(rt2x00dev, 7, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR7_RF_TUNING, 1);
rt2800_rfcsr_write(rt2x00dev, 7, rfcsr);
}
static void rt2800_config_channel_rf3290(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf,
struct rf_channel *rf,
struct channel_info *info)
{
u8 rfcsr;
rt2800_rfcsr_write(rt2x00dev, 8, rf->rf1);
rt2800_rfcsr_write(rt2x00dev, 9, rf->rf3);
rt2800_rfcsr_read(rt2x00dev, 11, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR11_R, rf->rf2);
rt2800_rfcsr_write(rt2x00dev, 11, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 49, &rfcsr);
if (info->default_power1 > POWER_BOUND)
rt2x00_set_field8(&rfcsr, RFCSR49_TX, POWER_BOUND);
else
rt2x00_set_field8(&rfcsr, RFCSR49_TX, info->default_power1);
rt2800_rfcsr_write(rt2x00dev, 49, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 17, &rfcsr);
if (rt2x00dev->freq_offset > FREQ_OFFSET_BOUND)
rt2x00_set_field8(&rfcsr, RFCSR17_CODE, FREQ_OFFSET_BOUND);
else
rt2x00_set_field8(&rfcsr, RFCSR17_CODE, rt2x00dev->freq_offset);
rt2800_rfcsr_write(rt2x00dev, 17, rfcsr);
if (rf->channel <= 14) {
if (rf->channel == 6)
rt2800_bbp_write(rt2x00dev, 68, 0x0c);
else
rt2800_bbp_write(rt2x00dev, 68, 0x0b);
if (rf->channel >= 1 && rf->channel <= 6)
rt2800_bbp_write(rt2x00dev, 59, 0x0f);
else if (rf->channel >= 7 && rf->channel <= 11)
rt2800_bbp_write(rt2x00dev, 59, 0x0e);
else if (rf->channel >= 12 && rf->channel <= 14)
rt2800_bbp_write(rt2x00dev, 59, 0x0d);
}
}
static void rt2800_config_channel_rf53xx(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf,
struct rf_channel *rf,
struct channel_info *info)
{
u8 rfcsr;
rt2800_rfcsr_write(rt2x00dev, 8, rf->rf1);
rt2800_rfcsr_write(rt2x00dev, 9, rf->rf3);
rt2800_rfcsr_read(rt2x00dev, 11, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR11_R, rf->rf2);
rt2800_rfcsr_write(rt2x00dev, 11, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 49, &rfcsr);
if (info->default_power1 > POWER_BOUND)
rt2x00_set_field8(&rfcsr, RFCSR49_TX, POWER_BOUND);
else
rt2x00_set_field8(&rfcsr, RFCSR49_TX, info->default_power1);
rt2800_rfcsr_write(rt2x00dev, 49, rfcsr);
if (rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_rfcsr_read(rt2x00dev, 50, &rfcsr);
if (info->default_power1 > POWER_BOUND)
rt2x00_set_field8(&rfcsr, RFCSR50_TX, POWER_BOUND);
else
rt2x00_set_field8(&rfcsr, RFCSR50_TX,
info->default_power2);
rt2800_rfcsr_write(rt2x00dev, 50, rfcsr);
}
rt2800_rfcsr_read(rt2x00dev, 1, &rfcsr);
if (rt2x00_rt(rt2x00dev, RT5392)) {
rt2x00_set_field8(&rfcsr, RFCSR1_RX1_PD, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_TX1_PD, 1);
}
rt2x00_set_field8(&rfcsr, RFCSR1_RF_BLOCK_EN, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_PLL_PD, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_RX0_PD, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_TX0_PD, 1);
rt2800_rfcsr_write(rt2x00dev, 1, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 17, &rfcsr);
if (rt2x00dev->freq_offset > FREQ_OFFSET_BOUND)
rt2x00_set_field8(&rfcsr, RFCSR17_CODE, FREQ_OFFSET_BOUND);
else
rt2x00_set_field8(&rfcsr, RFCSR17_CODE, rt2x00dev->freq_offset);
rt2800_rfcsr_write(rt2x00dev, 17, rfcsr);
if (rf->channel <= 14) {
int idx = rf->channel-1;
if (test_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags)) {
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F)) {
static const char r55_bt_rev[] = {0x83, 0x83,
0x83, 0x73, 0x73, 0x63, 0x53, 0x53,
0x53, 0x43, 0x43, 0x43, 0x43, 0x43};
static const char r59_bt_rev[] = {0x0e, 0x0e,
0x0e, 0x0e, 0x0e, 0x0b, 0x0a, 0x09,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07};
rt2800_rfcsr_write(rt2x00dev, 55,
r55_bt_rev[idx]);
rt2800_rfcsr_write(rt2x00dev, 59,
r59_bt_rev[idx]);
} else {
static const char r59_bt[] = {0x8b, 0x8b, 0x8b,
0x8b, 0x8b, 0x8b, 0x8b, 0x8a, 0x89,
0x88, 0x88, 0x86, 0x85, 0x84};
rt2800_rfcsr_write(rt2x00dev, 59, r59_bt[idx]);
}
} else {
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F)) {
static const char r55_nonbt_rev[] = {0x23, 0x23,
0x23, 0x23, 0x13, 0x13, 0x03, 0x03,
0x03, 0x03, 0x03, 0x03, 0x03, 0x03};
static const char r59_nonbt_rev[] = {0x07, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0x06, 0x05, 0x04, 0x04};
rt2800_rfcsr_write(rt2x00dev, 55,
r55_nonbt_rev[idx]);
rt2800_rfcsr_write(rt2x00dev, 59,
r59_nonbt_rev[idx]);
} else if (rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
static const char r59_non_bt[] = {0x8f, 0x8f,
0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8d,
0x8a, 0x88, 0x88, 0x87, 0x87, 0x86};
rt2800_rfcsr_write(rt2x00dev, 59,
r59_non_bt[idx]);
}
}
}
}
static void rt2800_config_channel(struct rt2x00_dev *rt2x00dev,
struct ieee80211_conf *conf,
struct rf_channel *rf,
struct channel_info *info)
{
u32 reg;
unsigned int tx_pin;
u8 bbp, rfcsr;
if (rf->channel <= 14) {
info->default_power1 = TXPOWER_G_TO_DEV(info->default_power1);
info->default_power2 = TXPOWER_G_TO_DEV(info->default_power2);
} else {
info->default_power1 = TXPOWER_A_TO_DEV(info->default_power1);
info->default_power2 = TXPOWER_A_TO_DEV(info->default_power2);
}
switch (rt2x00dev->chip.rf) {
case RF2020:
case RF3020:
case RF3021:
case RF3022:
case RF3320:
rt2800_config_channel_rf3xxx(rt2x00dev, conf, rf, info);
break;
case RF3052:
rt2800_config_channel_rf3052(rt2x00dev, conf, rf, info);
break;
case RF3290:
rt2800_config_channel_rf3290(rt2x00dev, conf, rf, info);
break;
case RF5360:
case RF5370:
case RF5372:
case RF5390:
case RF5392:
rt2800_config_channel_rf53xx(rt2x00dev, conf, rf, info);
break;
default:
rt2800_config_channel_rf2xxx(rt2x00dev, conf, rf, info);
}
if (rt2x00_rf(rt2x00dev, RF3290) ||
rt2x00_rf(rt2x00dev, RF5360) ||
rt2x00_rf(rt2x00dev, RF5370) ||
rt2x00_rf(rt2x00dev, RF5372) ||
rt2x00_rf(rt2x00dev, RF5390) ||
rt2x00_rf(rt2x00dev, RF5392)) {
rt2800_rfcsr_read(rt2x00dev, 30, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR30_TX_H20M, 0);
rt2x00_set_field8(&rfcsr, RFCSR30_RX_H20M, 0);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 3, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 1);
rt2800_rfcsr_write(rt2x00dev, 3, rfcsr);
}
rt2800_bbp_write(rt2x00dev, 62, 0x37 - rt2x00dev->lna_gain);
rt2800_bbp_write(rt2x00dev, 63, 0x37 - rt2x00dev->lna_gain);
rt2800_bbp_write(rt2x00dev, 64, 0x37 - rt2x00dev->lna_gain);
rt2800_bbp_write(rt2x00dev, 86, 0);
if (rf->channel <= 14) {
if (!rt2x00_rt(rt2x00dev, RT5390) &&
!rt2x00_rt(rt2x00dev, RT5392)) {
if (test_bit(CAPABILITY_EXTERNAL_LNA_BG,
&rt2x00dev->cap_flags)) {
rt2800_bbp_write(rt2x00dev, 82, 0x62);
rt2800_bbp_write(rt2x00dev, 75, 0x46);
} else {
rt2800_bbp_write(rt2x00dev, 82, 0x84);
rt2800_bbp_write(rt2x00dev, 75, 0x50);
}
}
} else {
if (rt2x00_rt(rt2x00dev, RT3572))
rt2800_bbp_write(rt2x00dev, 82, 0x94);
else
rt2800_bbp_write(rt2x00dev, 82, 0xf2);
if (test_bit(CAPABILITY_EXTERNAL_LNA_A, &rt2x00dev->cap_flags))
rt2800_bbp_write(rt2x00dev, 75, 0x46);
else
rt2800_bbp_write(rt2x00dev, 75, 0x50);
}
rt2800_register_read(rt2x00dev, TX_BAND_CFG, &reg);
rt2x00_set_field32(&reg, TX_BAND_CFG_HT40_MINUS, conf_is_ht40_minus(conf));
rt2x00_set_field32(&reg, TX_BAND_CFG_A, rf->channel > 14);
rt2x00_set_field32(&reg, TX_BAND_CFG_BG, rf->channel <= 14);
rt2800_register_write(rt2x00dev, TX_BAND_CFG, reg);
if (rt2x00_rt(rt2x00dev, RT3572))
rt2800_rfcsr_write(rt2x00dev, 8, 0);
tx_pin = 0;
if (rt2x00dev->default_ant.tx_chain_num == 2) {
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_A1_EN,
rf->channel > 14);
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_G1_EN,
rf->channel <= 14);
}
if (rt2x00dev->default_ant.rx_chain_num == 2) {
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_LNA_PE_A1_EN, 1);
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_LNA_PE_G1_EN, 1);
}
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_LNA_PE_A0_EN, 1);
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_LNA_PE_G0_EN, 1);
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_RFTR_EN, 1);
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_TRSW_EN, 1);
if (test_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags))
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_G0_EN, 1);
else
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_G0_EN,
rf->channel <= 14);
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_A0_EN, rf->channel > 14);
rt2800_register_write(rt2x00dev, TX_PIN_CFG, tx_pin);
if (rt2x00_rt(rt2x00dev, RT3572))
rt2800_rfcsr_write(rt2x00dev, 8, 0x80);
rt2800_bbp_read(rt2x00dev, 4, &bbp);
rt2x00_set_field8(&bbp, BBP4_BANDWIDTH, 2 * conf_is_ht40(conf));
rt2800_bbp_write(rt2x00dev, 4, bbp);
rt2800_bbp_read(rt2x00dev, 3, &bbp);
rt2x00_set_field8(&bbp, BBP3_HT40_MINUS, conf_is_ht40_minus(conf));
rt2800_bbp_write(rt2x00dev, 3, bbp);
if (rt2x00_rt_rev(rt2x00dev, RT2860, REV_RT2860C)) {
if (conf_is_ht40(conf)) {
rt2800_bbp_write(rt2x00dev, 69, 0x1a);
rt2800_bbp_write(rt2x00dev, 70, 0x0a);
rt2800_bbp_write(rt2x00dev, 73, 0x16);
} else {
rt2800_bbp_write(rt2x00dev, 69, 0x16);
rt2800_bbp_write(rt2x00dev, 70, 0x08);
rt2800_bbp_write(rt2x00dev, 73, 0x11);
}
}
msleep(1);
rt2800_register_read(rt2x00dev, CH_IDLE_STA, &reg);
rt2800_register_read(rt2x00dev, CH_BUSY_STA, &reg);
rt2800_register_read(rt2x00dev, CH_BUSY_STA_SEC, &reg);
}
static int rt2800_get_gain_calibration_delta(struct rt2x00_dev *rt2x00dev)
{
u8 tssi_bounds[9];
u8 current_tssi;
u16 eeprom;
u8 step;
int i;
if (rt2x00dev->curr_band == IEEE80211_BAND_2GHZ) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_BG1, &eeprom);
tssi_bounds[0] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG1_MINUS4);
tssi_bounds[1] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG1_MINUS3);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_BG2, &eeprom);
tssi_bounds[2] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG2_MINUS2);
tssi_bounds[3] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG2_MINUS1);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_BG3, &eeprom);
tssi_bounds[4] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG3_REF);
tssi_bounds[5] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG3_PLUS1);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_BG4, &eeprom);
tssi_bounds[6] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG4_PLUS2);
tssi_bounds[7] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG4_PLUS3);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_BG5, &eeprom);
tssi_bounds[8] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG5_PLUS4);
step = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_BG5_AGC_STEP);
} else {
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_A1, &eeprom);
tssi_bounds[0] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A1_MINUS4);
tssi_bounds[1] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A1_MINUS3);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_A2, &eeprom);
tssi_bounds[2] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A2_MINUS2);
tssi_bounds[3] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A2_MINUS1);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_A3, &eeprom);
tssi_bounds[4] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A3_REF);
tssi_bounds[5] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A3_PLUS1);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_A4, &eeprom);
tssi_bounds[6] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A4_PLUS2);
tssi_bounds[7] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A4_PLUS3);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TSSI_BOUND_A5, &eeprom);
tssi_bounds[8] = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A5_PLUS4);
step = rt2x00_get_field16(eeprom,
EEPROM_TSSI_BOUND_A5_AGC_STEP);
}
if (tssi_bounds[4] == 0xff)
return 0;
rt2800_bbp_read(rt2x00dev, 49, &current_tssi);
for (i = 0; i <= 3; i++) {
if (current_tssi > tssi_bounds[i])
break;
}
if (i == 4) {
for (i = 8; i >= 5; i--) {
if (current_tssi < tssi_bounds[i])
break;
}
}
return (i - 4) * step;
}
static int rt2800_get_txpower_bw_comp(struct rt2x00_dev *rt2x00dev,
enum ieee80211_band band)
{
u16 eeprom;
u8 comp_en;
u8 comp_type;
int comp_value = 0;
rt2x00_eeprom_read(rt2x00dev, EEPROM_TXPOWER_DELTA, &eeprom);
if (eeprom == 0xffff ||
!test_bit(CONFIG_CHANNEL_HT40, &rt2x00dev->flags))
return 0;
if (band == IEEE80211_BAND_2GHZ) {
comp_en = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_DELTA_ENABLE_2G);
if (comp_en) {
comp_type = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_DELTA_TYPE_2G);
comp_value = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_DELTA_VALUE_2G);
if (!comp_type)
comp_value = -comp_value;
}
} else {
comp_en = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_DELTA_ENABLE_5G);
if (comp_en) {
comp_type = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_DELTA_TYPE_5G);
comp_value = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_DELTA_VALUE_5G);
if (!comp_type)
comp_value = -comp_value;
}
}
return comp_value;
}
static u8 rt2800_compensate_txpower(struct rt2x00_dev *rt2x00dev, int is_rate_b,
enum ieee80211_band band, int power_level,
u8 txpower, int delta)
{
u32 reg;
u16 eeprom;
u8 criterion;
u8 eirp_txpower;
u8 eirp_txpower_criterion;
u8 reg_limit;
if (!((band == IEEE80211_BAND_5GHZ) && is_rate_b))
return txpower;
if (test_bit(CAPABILITY_POWER_LIMIT, &rt2x00dev->cap_flags)) {
rt2800_register_read(rt2x00dev, TX_PWR_CFG_0, &reg);
criterion = rt2x00_get_field32(reg, TX_PWR_CFG_0_6MBS);
rt2x00_eeprom_read(rt2x00dev,
EEPROM_EIRP_MAX_TX_POWER, &eeprom);
if (band == IEEE80211_BAND_2GHZ)
eirp_txpower_criterion = rt2x00_get_field16(eeprom,
EEPROM_EIRP_MAX_TX_POWER_2GHZ);
else
eirp_txpower_criterion = rt2x00_get_field16(eeprom,
EEPROM_EIRP_MAX_TX_POWER_5GHZ);
eirp_txpower = eirp_txpower_criterion + (txpower - criterion) +
(is_rate_b ? 4 : 0) + delta;
reg_limit = (eirp_txpower > power_level) ?
(eirp_txpower - power_level) : 0;
} else
reg_limit = 0;
return txpower + delta - reg_limit;
}
static void rt2800_config_txpower(struct rt2x00_dev *rt2x00dev,
enum ieee80211_band band,
int power_level)
{
u8 txpower;
u16 eeprom;
int i, is_rate_b;
u32 reg;
u8 r1;
u32 offset;
int delta;
delta = rt2800_get_txpower_bw_comp(rt2x00dev, band);
delta += rt2800_get_gain_calibration_delta(rt2x00dev);
rt2800_bbp_read(rt2x00dev, 1, &r1);
rt2x00_set_field8(&r1, BBP1_TX_POWER_CTRL, 0);
rt2800_bbp_write(rt2x00dev, 1, r1);
offset = TX_PWR_CFG_0;
for (i = 0; i < EEPROM_TXPOWER_BYRATE_SIZE; i += 2) {
if (offset > TX_PWR_CFG_4)
break;
rt2800_register_read(rt2x00dev, offset, &reg);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TXPOWER_BYRATE + i,
&eeprom);
is_rate_b = i ? 0 : 1;
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE0);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE0, txpower);
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE1);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE1, txpower);
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE2);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE2, txpower);
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE3);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE3, txpower);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TXPOWER_BYRATE + i + 1,
&eeprom);
is_rate_b = 0;
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE0);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE4, txpower);
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE1);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE5, txpower);
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE2);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE6, txpower);
txpower = rt2x00_get_field16(eeprom,
EEPROM_TXPOWER_BYRATE_RATE3);
txpower = rt2800_compensate_txpower(rt2x00dev, is_rate_b, band,
power_level, txpower, delta);
rt2x00_set_field32(&reg, TX_PWR_CFG_RATE7, txpower);
rt2800_register_write(rt2x00dev, offset, reg);
offset += 4;
}
}
void rt2800_gain_calibration(struct rt2x00_dev *rt2x00dev)
{
rt2800_config_txpower(rt2x00dev, rt2x00dev->curr_band,
rt2x00dev->tx_power);
}
void rt2800_vco_calibration(struct rt2x00_dev *rt2x00dev)
{
u32 tx_pin;
u8 rfcsr;
rt2800_register_read(rt2x00dev, TX_PIN_CFG, &tx_pin);
tx_pin &= TX_PIN_CFG_PA_PE_DISABLE;
rt2800_register_write(rt2x00dev, TX_PIN_CFG, tx_pin);
switch (rt2x00dev->chip.rf) {
case RF2020:
case RF3020:
case RF3021:
case RF3022:
case RF3320:
case RF3052:
rt2800_rfcsr_read(rt2x00dev, 7, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR7_RF_TUNING, 1);
rt2800_rfcsr_write(rt2x00dev, 7, rfcsr);
break;
case RF3290:
case RF5360:
case RF5370:
case RF5372:
case RF5390:
case RF5392:
rt2800_rfcsr_read(rt2x00dev, 3, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 1);
rt2800_rfcsr_write(rt2x00dev, 3, rfcsr);
break;
default:
return;
}
mdelay(1);
rt2800_register_read(rt2x00dev, TX_PIN_CFG, &tx_pin);
if (rt2x00dev->rf_channel <= 14) {
switch (rt2x00dev->default_ant.tx_chain_num) {
case 3:
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_G2_EN, 1);
case 2:
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_G1_EN, 1);
case 1:
default:
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_G0_EN, 1);
break;
}
} else {
switch (rt2x00dev->default_ant.tx_chain_num) {
case 3:
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_A2_EN, 1);
case 2:
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_A1_EN, 1);
case 1:
default:
rt2x00_set_field32(&tx_pin, TX_PIN_CFG_PA_PE_A0_EN, 1);
break;
}
}
rt2800_register_write(rt2x00dev, TX_PIN_CFG, tx_pin);
}
static void rt2800_config_retry_limit(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
u32 reg;
rt2800_register_read(rt2x00dev, TX_RTY_CFG, &reg);
rt2x00_set_field32(&reg, TX_RTY_CFG_SHORT_RTY_LIMIT,
libconf->conf->short_frame_max_tx_count);
rt2x00_set_field32(&reg, TX_RTY_CFG_LONG_RTY_LIMIT,
libconf->conf->long_frame_max_tx_count);
rt2800_register_write(rt2x00dev, TX_RTY_CFG, reg);
}
static void rt2800_config_ps(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
enum dev_state state =
(libconf->conf->flags & IEEE80211_CONF_PS) ?
STATE_SLEEP : STATE_AWAKE;
u32 reg;
if (state == STATE_SLEEP) {
rt2800_register_write(rt2x00dev, AUTOWAKEUP_CFG, 0);
rt2800_register_read(rt2x00dev, AUTOWAKEUP_CFG, &reg);
rt2x00_set_field32(&reg, AUTOWAKEUP_CFG_AUTO_LEAD_TIME, 5);
rt2x00_set_field32(&reg, AUTOWAKEUP_CFG_TBCN_BEFORE_WAKE,
libconf->conf->listen_interval - 1);
rt2x00_set_field32(&reg, AUTOWAKEUP_CFG_AUTOWAKE, 1);
rt2800_register_write(rt2x00dev, AUTOWAKEUP_CFG, reg);
rt2x00dev->ops->lib->set_device_state(rt2x00dev, state);
} else {
rt2800_register_read(rt2x00dev, AUTOWAKEUP_CFG, &reg);
rt2x00_set_field32(&reg, AUTOWAKEUP_CFG_AUTO_LEAD_TIME, 0);
rt2x00_set_field32(&reg, AUTOWAKEUP_CFG_TBCN_BEFORE_WAKE, 0);
rt2x00_set_field32(&reg, AUTOWAKEUP_CFG_AUTOWAKE, 0);
rt2800_register_write(rt2x00dev, AUTOWAKEUP_CFG, reg);
rt2x00dev->ops->lib->set_device_state(rt2x00dev, state);
}
}
void rt2800_config(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf,
const unsigned int flags)
{
rt2800_config_lna_gain(rt2x00dev, libconf);
if (flags & IEEE80211_CONF_CHANGE_CHANNEL) {
rt2800_config_channel(rt2x00dev, libconf->conf,
&libconf->rf, &libconf->channel);
rt2800_config_txpower(rt2x00dev, libconf->conf->channel->band,
libconf->conf->power_level);
}
if (flags & IEEE80211_CONF_CHANGE_POWER)
rt2800_config_txpower(rt2x00dev, libconf->conf->channel->band,
libconf->conf->power_level);
if (flags & IEEE80211_CONF_CHANGE_RETRY_LIMITS)
rt2800_config_retry_limit(rt2x00dev, libconf);
if (flags & IEEE80211_CONF_CHANGE_PS)
rt2800_config_ps(rt2x00dev, libconf);
}
void rt2800_link_stats(struct rt2x00_dev *rt2x00dev, struct link_qual *qual)
{
u32 reg;
rt2800_register_read(rt2x00dev, RX_STA_CNT0, &reg);
qual->rx_failed = rt2x00_get_field32(reg, RX_STA_CNT0_CRC_ERR);
}
static u8 rt2800_get_default_vgc(struct rt2x00_dev *rt2x00dev)
{
if (rt2x00dev->curr_band == IEEE80211_BAND_2GHZ) {
if (rt2x00_rt(rt2x00dev, RT3070) ||
rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT3390) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
return 0x1c + (2 * rt2x00dev->lna_gain);
else
return 0x2e + rt2x00dev->lna_gain;
}
if (!test_bit(CONFIG_CHANNEL_HT40, &rt2x00dev->flags))
return 0x32 + (rt2x00dev->lna_gain * 5) / 3;
else
return 0x3a + (rt2x00dev->lna_gain * 5) / 3;
}
static inline void rt2800_set_vgc(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual, u8 vgc_level)
{
if (qual->vgc_level != vgc_level) {
rt2800_bbp_write(rt2x00dev, 66, vgc_level);
qual->vgc_level = vgc_level;
qual->vgc_level_reg = vgc_level;
}
}
void rt2800_reset_tuner(struct rt2x00_dev *rt2x00dev, struct link_qual *qual)
{
rt2800_set_vgc(rt2x00dev, qual, rt2800_get_default_vgc(rt2x00dev));
}
void rt2800_link_tuner(struct rt2x00_dev *rt2x00dev, struct link_qual *qual,
const u32 count)
{
if (rt2x00_rt_rev(rt2x00dev, RT2860, REV_RT2860C))
return;
rt2800_set_vgc(rt2x00dev, qual,
rt2800_get_default_vgc(rt2x00dev) +
((qual->rssi > -80) * 0x10));
}
static int rt2800_init_registers(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
u16 eeprom;
unsigned int i;
int ret;
rt2800_disable_wpdma(rt2x00dev);
ret = rt2800_drv_init_registers(rt2x00dev);
if (ret)
return ret;
rt2800_register_read(rt2x00dev, BCN_OFFSET0, &reg);
rt2x00_set_field32(&reg, BCN_OFFSET0_BCN0, 0xe0);
rt2x00_set_field32(&reg, BCN_OFFSET0_BCN1, 0xe8);
rt2x00_set_field32(&reg, BCN_OFFSET0_BCN2, 0xf0);
rt2x00_set_field32(&reg, BCN_OFFSET0_BCN3, 0xf8);
rt2800_register_write(rt2x00dev, BCN_OFFSET0, reg);
rt2800_register_read(rt2x00dev, BCN_OFFSET1, &reg);
rt2x00_set_field32(&reg, BCN_OFFSET1_BCN4, 0xc8);
rt2x00_set_field32(&reg, BCN_OFFSET1_BCN5, 0xd0);
rt2x00_set_field32(&reg, BCN_OFFSET1_BCN6, 0x77);
rt2x00_set_field32(&reg, BCN_OFFSET1_BCN7, 0x6f);
rt2800_register_write(rt2x00dev, BCN_OFFSET1, reg);
rt2800_register_write(rt2x00dev, LEGACY_BASIC_RATE, 0x0000013f);
rt2800_register_write(rt2x00dev, HT_BASIC_RATE, 0x00008003);
rt2800_register_write(rt2x00dev, MAC_SYS_CTRL, 0x00000000);
rt2800_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_INTERVAL, 1600);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_TICKING, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_SYNC, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TBTT_ENABLE, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TX_TIME_COMPENSATE, 0);
rt2800_register_write(rt2x00dev, BCN_TIME_CFG, reg);
rt2800_config_filter(rt2x00dev, FIF_ALLMULTI);
rt2800_register_read(rt2x00dev, BKOFF_SLOT_CFG, &reg);
rt2x00_set_field32(&reg, BKOFF_SLOT_CFG_SLOT_TIME, 9);
rt2x00_set_field32(&reg, BKOFF_SLOT_CFG_CC_DELAY_TIME, 2);
rt2800_register_write(rt2x00dev, BKOFF_SLOT_CFG, reg);
if (rt2x00_rt(rt2x00dev, RT3290)) {
rt2800_register_read(rt2x00dev, WLAN_FUN_CTRL, &reg);
if (rt2x00_get_field32(reg, WLAN_EN) == 1) {
rt2x00_set_field32(&reg, PCIE_APP0_CLK_REQ, 1);
rt2800_register_write(rt2x00dev, WLAN_FUN_CTRL, reg);
}
rt2800_register_read(rt2x00dev, CMB_CTRL, &reg);
if (!(rt2x00_get_field32(reg, LDO0_EN) == 1)) {
rt2x00_set_field32(&reg, LDO0_EN, 1);
rt2x00_set_field32(&reg, LDO_BGSEL, 3);
rt2800_register_write(rt2x00dev, CMB_CTRL, reg);
}
rt2800_register_read(rt2x00dev, OSC_CTRL, &reg);
rt2x00_set_field32(&reg, OSC_ROSC_EN, 1);
rt2x00_set_field32(&reg, OSC_CAL_REQ, 1);
rt2x00_set_field32(&reg, OSC_REF_CYCLE, 0x27);
rt2800_register_write(rt2x00dev, OSC_CTRL, reg);
rt2800_register_read(rt2x00dev, COEX_CFG0, &reg);
rt2x00_set_field32(&reg, COEX_CFG_ANT, 0x5e);
rt2800_register_write(rt2x00dev, COEX_CFG0, reg);
rt2800_register_read(rt2x00dev, COEX_CFG2, &reg);
rt2x00_set_field32(&reg, BT_COEX_CFG1, 0x00);
rt2x00_set_field32(&reg, BT_COEX_CFG0, 0x17);
rt2x00_set_field32(&reg, WL_COEX_CFG1, 0x93);
rt2x00_set_field32(&reg, WL_COEX_CFG0, 0x7f);
rt2800_register_write(rt2x00dev, COEX_CFG2, reg);
rt2800_register_read(rt2x00dev, PLL_CTRL, &reg);
rt2x00_set_field32(&reg, PLL_CONTROL, 1);
rt2800_register_write(rt2x00dev, PLL_CTRL, reg);
}
if (rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT3390)) {
if (rt2x00_rt(rt2x00dev, RT3290))
rt2800_register_write(rt2x00dev, TX_SW_CFG0,
0x00000404);
else
rt2800_register_write(rt2x00dev, TX_SW_CFG0,
0x00000400);
rt2800_register_write(rt2x00dev, TX_SW_CFG1, 0x00000000);
if (rt2x00_rt_rev_lt(rt2x00dev, RT3071, REV_RT3071E) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3090, REV_RT3090E) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3390, REV_RT3390E)) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF1, &eeprom);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF1_DAC_TEST))
rt2800_register_write(rt2x00dev, TX_SW_CFG2,
0x0000002c);
else
rt2800_register_write(rt2x00dev, TX_SW_CFG2,
0x0000000f);
} else {
rt2800_register_write(rt2x00dev, TX_SW_CFG2, 0x00000000);
}
} else if (rt2x00_rt(rt2x00dev, RT3070)) {
rt2800_register_write(rt2x00dev, TX_SW_CFG0, 0x00000400);
if (rt2x00_rt_rev_lt(rt2x00dev, RT3070, REV_RT3070F)) {
rt2800_register_write(rt2x00dev, TX_SW_CFG1, 0x00000000);
rt2800_register_write(rt2x00dev, TX_SW_CFG2, 0x0000002c);
} else {
rt2800_register_write(rt2x00dev, TX_SW_CFG1, 0x00080606);
rt2800_register_write(rt2x00dev, TX_SW_CFG2, 0x00000000);
}
} else if (rt2800_is_305x_soc(rt2x00dev)) {
rt2800_register_write(rt2x00dev, TX_SW_CFG0, 0x00000400);
rt2800_register_write(rt2x00dev, TX_SW_CFG1, 0x00000000);
rt2800_register_write(rt2x00dev, TX_SW_CFG2, 0x00000030);
} else if (rt2x00_rt(rt2x00dev, RT3572)) {
rt2800_register_write(rt2x00dev, TX_SW_CFG0, 0x00000400);
rt2800_register_write(rt2x00dev, TX_SW_CFG1, 0x00080606);
} else if (rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_register_write(rt2x00dev, TX_SW_CFG0, 0x00000404);
rt2800_register_write(rt2x00dev, TX_SW_CFG1, 0x00080606);
rt2800_register_write(rt2x00dev, TX_SW_CFG2, 0x00000000);
} else {
rt2800_register_write(rt2x00dev, TX_SW_CFG0, 0x00000000);
rt2800_register_write(rt2x00dev, TX_SW_CFG1, 0x00080606);
}
rt2800_register_read(rt2x00dev, TX_LINK_CFG, &reg);
rt2x00_set_field32(&reg, TX_LINK_CFG_REMOTE_MFB_LIFETIME, 32);
rt2x00_set_field32(&reg, TX_LINK_CFG_MFB_ENABLE, 0);
rt2x00_set_field32(&reg, TX_LINK_CFG_REMOTE_UMFS_ENABLE, 0);
rt2x00_set_field32(&reg, TX_LINK_CFG_TX_MRQ_EN, 0);
rt2x00_set_field32(&reg, TX_LINK_CFG_TX_RDG_EN, 0);
rt2x00_set_field32(&reg, TX_LINK_CFG_TX_CF_ACK_EN, 1);
rt2x00_set_field32(&reg, TX_LINK_CFG_REMOTE_MFB, 0);
rt2x00_set_field32(&reg, TX_LINK_CFG_REMOTE_MFS, 0);
rt2800_register_write(rt2x00dev, TX_LINK_CFG, reg);
rt2800_register_read(rt2x00dev, TX_TIMEOUT_CFG, &reg);
rt2x00_set_field32(&reg, TX_TIMEOUT_CFG_MPDU_LIFETIME, 9);
rt2x00_set_field32(&reg, TX_TIMEOUT_CFG_RX_ACK_TIMEOUT, 32);
rt2x00_set_field32(&reg, TX_TIMEOUT_CFG_TX_OP_TIMEOUT, 10);
rt2800_register_write(rt2x00dev, TX_TIMEOUT_CFG, reg);
rt2800_register_read(rt2x00dev, MAX_LEN_CFG, &reg);
rt2x00_set_field32(&reg, MAX_LEN_CFG_MAX_MPDU, AGGREGATION_SIZE);
if (rt2x00_rt_rev_gte(rt2x00dev, RT2872, REV_RT2872E) ||
rt2x00_rt(rt2x00dev, RT2883) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3070, REV_RT3070E))
rt2x00_set_field32(&reg, MAX_LEN_CFG_MAX_PSDU, 2);
else
rt2x00_set_field32(&reg, MAX_LEN_CFG_MAX_PSDU, 1);
rt2x00_set_field32(&reg, MAX_LEN_CFG_MIN_PSDU, 0);
rt2x00_set_field32(&reg, MAX_LEN_CFG_MIN_MPDU, 0);
rt2800_register_write(rt2x00dev, MAX_LEN_CFG, reg);
rt2800_register_read(rt2x00dev, LED_CFG, &reg);
rt2x00_set_field32(&reg, LED_CFG_ON_PERIOD, 70);
rt2x00_set_field32(&reg, LED_CFG_OFF_PERIOD, 30);
rt2x00_set_field32(&reg, LED_CFG_SLOW_BLINK_PERIOD, 3);
rt2x00_set_field32(&reg, LED_CFG_R_LED_MODE, 3);
rt2x00_set_field32(&reg, LED_CFG_G_LED_MODE, 3);
rt2x00_set_field32(&reg, LED_CFG_Y_LED_MODE, 3);
rt2x00_set_field32(&reg, LED_CFG_LED_POLAR, 1);
rt2800_register_write(rt2x00dev, LED_CFG, reg);
rt2800_register_write(rt2x00dev, PBF_MAX_PCNT, 0x1f3fbf9f);
rt2800_register_read(rt2x00dev, TX_RTY_CFG, &reg);
rt2x00_set_field32(&reg, TX_RTY_CFG_SHORT_RTY_LIMIT, 15);
rt2x00_set_field32(&reg, TX_RTY_CFG_LONG_RTY_LIMIT, 31);
rt2x00_set_field32(&reg, TX_RTY_CFG_LONG_RTY_THRE, 2000);
rt2x00_set_field32(&reg, TX_RTY_CFG_NON_AGG_RTY_MODE, 0);
rt2x00_set_field32(&reg, TX_RTY_CFG_AGG_RTY_MODE, 0);
rt2x00_set_field32(&reg, TX_RTY_CFG_TX_AUTO_FB_ENABLE, 1);
rt2800_register_write(rt2x00dev, TX_RTY_CFG, reg);
rt2800_register_read(rt2x00dev, AUTO_RSP_CFG, &reg);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_AUTORESPONDER, 1);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_BAC_ACK_POLICY, 1);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_CTS_40_MMODE, 0);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_CTS_40_MREF, 0);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_AR_PREAMBLE, 1);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_DUAL_CTS_EN, 0);
rt2x00_set_field32(&reg, AUTO_RSP_CFG_ACK_CTS_PSM_BIT, 0);
rt2800_register_write(rt2x00dev, AUTO_RSP_CFG, reg);
rt2800_register_read(rt2x00dev, CCK_PROT_CFG, &reg);
rt2x00_set_field32(&reg, CCK_PROT_CFG_PROTECT_RATE, 3);
rt2x00_set_field32(&reg, CCK_PROT_CFG_PROTECT_CTRL, 0);
rt2x00_set_field32(&reg, CCK_PROT_CFG_PROTECT_NAV_SHORT, 1);
rt2x00_set_field32(&reg, CCK_PROT_CFG_TX_OP_ALLOW_CCK, 1);
rt2x00_set_field32(&reg, CCK_PROT_CFG_TX_OP_ALLOW_OFDM, 1);
rt2x00_set_field32(&reg, CCK_PROT_CFG_TX_OP_ALLOW_MM20, 1);
rt2x00_set_field32(&reg, CCK_PROT_CFG_TX_OP_ALLOW_MM40, 0);
rt2x00_set_field32(&reg, CCK_PROT_CFG_TX_OP_ALLOW_GF20, 1);
rt2x00_set_field32(&reg, CCK_PROT_CFG_TX_OP_ALLOW_GF40, 0);
rt2x00_set_field32(&reg, CCK_PROT_CFG_RTS_TH_EN, 1);
rt2800_register_write(rt2x00dev, CCK_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, OFDM_PROT_CFG, &reg);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_PROTECT_RATE, 3);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_PROTECT_CTRL, 0);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_PROTECT_NAV_SHORT, 1);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_TX_OP_ALLOW_CCK, 1);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_TX_OP_ALLOW_OFDM, 1);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_TX_OP_ALLOW_MM20, 1);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_TX_OP_ALLOW_MM40, 0);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_TX_OP_ALLOW_GF20, 1);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_TX_OP_ALLOW_GF40, 0);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_RTS_TH_EN, 1);
rt2800_register_write(rt2x00dev, OFDM_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, MM20_PROT_CFG, &reg);
rt2x00_set_field32(&reg, MM20_PROT_CFG_PROTECT_RATE, 0x4004);
rt2x00_set_field32(&reg, MM20_PROT_CFG_PROTECT_CTRL, 0);
rt2x00_set_field32(&reg, MM20_PROT_CFG_PROTECT_NAV_SHORT, 1);
rt2x00_set_field32(&reg, MM20_PROT_CFG_TX_OP_ALLOW_CCK, 1);
rt2x00_set_field32(&reg, MM20_PROT_CFG_TX_OP_ALLOW_OFDM, 1);
rt2x00_set_field32(&reg, MM20_PROT_CFG_TX_OP_ALLOW_MM20, 1);
rt2x00_set_field32(&reg, MM20_PROT_CFG_TX_OP_ALLOW_MM40, 0);
rt2x00_set_field32(&reg, MM20_PROT_CFG_TX_OP_ALLOW_GF20, 1);
rt2x00_set_field32(&reg, MM20_PROT_CFG_TX_OP_ALLOW_GF40, 0);
rt2x00_set_field32(&reg, MM20_PROT_CFG_RTS_TH_EN, 0);
rt2800_register_write(rt2x00dev, MM20_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, MM40_PROT_CFG, &reg);
rt2x00_set_field32(&reg, MM40_PROT_CFG_PROTECT_RATE, 0x4084);
rt2x00_set_field32(&reg, MM40_PROT_CFG_PROTECT_CTRL, 0);
rt2x00_set_field32(&reg, MM40_PROT_CFG_PROTECT_NAV_SHORT, 1);
rt2x00_set_field32(&reg, MM40_PROT_CFG_TX_OP_ALLOW_CCK, 1);
rt2x00_set_field32(&reg, MM40_PROT_CFG_TX_OP_ALLOW_OFDM, 1);
rt2x00_set_field32(&reg, MM40_PROT_CFG_TX_OP_ALLOW_MM20, 1);
rt2x00_set_field32(&reg, MM40_PROT_CFG_TX_OP_ALLOW_MM40, 1);
rt2x00_set_field32(&reg, MM40_PROT_CFG_TX_OP_ALLOW_GF20, 1);
rt2x00_set_field32(&reg, MM40_PROT_CFG_TX_OP_ALLOW_GF40, 1);
rt2x00_set_field32(&reg, MM40_PROT_CFG_RTS_TH_EN, 0);
rt2800_register_write(rt2x00dev, MM40_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, GF20_PROT_CFG, &reg);
rt2x00_set_field32(&reg, GF20_PROT_CFG_PROTECT_RATE, 0x4004);
rt2x00_set_field32(&reg, GF20_PROT_CFG_PROTECT_CTRL, 0);
rt2x00_set_field32(&reg, GF20_PROT_CFG_PROTECT_NAV_SHORT, 1);
rt2x00_set_field32(&reg, GF20_PROT_CFG_TX_OP_ALLOW_CCK, 1);
rt2x00_set_field32(&reg, GF20_PROT_CFG_TX_OP_ALLOW_OFDM, 1);
rt2x00_set_field32(&reg, GF20_PROT_CFG_TX_OP_ALLOW_MM20, 1);
rt2x00_set_field32(&reg, GF20_PROT_CFG_TX_OP_ALLOW_MM40, 0);
rt2x00_set_field32(&reg, GF20_PROT_CFG_TX_OP_ALLOW_GF20, 1);
rt2x00_set_field32(&reg, GF20_PROT_CFG_TX_OP_ALLOW_GF40, 0);
rt2x00_set_field32(&reg, GF20_PROT_CFG_RTS_TH_EN, 0);
rt2800_register_write(rt2x00dev, GF20_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, GF40_PROT_CFG, &reg);
rt2x00_set_field32(&reg, GF40_PROT_CFG_PROTECT_RATE, 0x4084);
rt2x00_set_field32(&reg, GF40_PROT_CFG_PROTECT_CTRL, 0);
rt2x00_set_field32(&reg, GF40_PROT_CFG_PROTECT_NAV_SHORT, 1);
rt2x00_set_field32(&reg, GF40_PROT_CFG_TX_OP_ALLOW_CCK, 1);
rt2x00_set_field32(&reg, GF40_PROT_CFG_TX_OP_ALLOW_OFDM, 1);
rt2x00_set_field32(&reg, GF40_PROT_CFG_TX_OP_ALLOW_MM20, 1);
rt2x00_set_field32(&reg, GF40_PROT_CFG_TX_OP_ALLOW_MM40, 1);
rt2x00_set_field32(&reg, GF40_PROT_CFG_TX_OP_ALLOW_GF20, 1);
rt2x00_set_field32(&reg, GF40_PROT_CFG_TX_OP_ALLOW_GF40, 1);
rt2x00_set_field32(&reg, GF40_PROT_CFG_RTS_TH_EN, 0);
rt2800_register_write(rt2x00dev, GF40_PROT_CFG, reg);
if (rt2x00_is_usb(rt2x00dev)) {
rt2800_register_write(rt2x00dev, PBF_CFG, 0xf40006);
rt2800_register_read(rt2x00dev, WPDMA_GLO_CFG, &reg);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_ENABLE_TX_DMA, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_TX_DMA_BUSY, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_ENABLE_RX_DMA, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_RX_DMA_BUSY, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_WP_DMA_BURST_SIZE, 3);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_TX_WRITEBACK_DONE, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_BIG_ENDIAN, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_RX_HDR_SCATTER, 0);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_HDR_SEG_LEN, 0);
rt2800_register_write(rt2x00dev, WPDMA_GLO_CFG, reg);
}
rt2800_register_read(rt2x00dev, TXOP_CTRL_CFG, &reg);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_TIMEOUT_TRUN_EN, 1);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_AC_TRUN_EN, 1);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_TXRATEGRP_TRUN_EN, 1);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_USER_MODE_TRUN_EN, 1);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_MIMO_PS_TRUN_EN, 1);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_RESERVED_TRUN_EN, 1);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_LSIG_TXOP_EN, 0);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_EXT_CCA_EN, 0);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_EXT_CCA_DLY, 88);
rt2x00_set_field32(&reg, TXOP_CTRL_CFG_EXT_CWMIN, 0);
rt2800_register_write(rt2x00dev, TXOP_CTRL_CFG, reg);
rt2800_register_write(rt2x00dev, TXOP_HLDR_ET, 0x00000002);
rt2800_register_read(rt2x00dev, TX_RTS_CFG, &reg);
rt2x00_set_field32(&reg, TX_RTS_CFG_AUTO_RTS_RETRY_LIMIT, 32);
rt2x00_set_field32(&reg, TX_RTS_CFG_RTS_THRES,
IEEE80211_MAX_RTS_THRESHOLD);
rt2x00_set_field32(&reg, TX_RTS_CFG_RTS_FBK_EN, 0);
rt2800_register_write(rt2x00dev, TX_RTS_CFG, reg);
rt2800_register_write(rt2x00dev, EXP_ACK_TIME, 0x002400ca);
rt2800_register_read(rt2x00dev, XIFS_TIME_CFG, &reg);
rt2x00_set_field32(&reg, XIFS_TIME_CFG_CCKM_SIFS_TIME, 16);
rt2x00_set_field32(&reg, XIFS_TIME_CFG_OFDM_SIFS_TIME, 16);
rt2x00_set_field32(&reg, XIFS_TIME_CFG_OFDM_XIFS_TIME, 4);
rt2x00_set_field32(&reg, XIFS_TIME_CFG_EIFS, 314);
rt2x00_set_field32(&reg, XIFS_TIME_CFG_BB_RXEND_ENABLE, 1);
rt2800_register_write(rt2x00dev, XIFS_TIME_CFG, reg);
rt2800_register_write(rt2x00dev, PWR_PIN_CFG, 0x00000003);
for (i = 0; i < 4; i++)
rt2800_register_write(rt2x00dev,
SHARED_KEY_MODE_ENTRY(i), 0);
for (i = 0; i < 256; i++) {
rt2800_config_wcid(rt2x00dev, NULL, i);
rt2800_delete_wcid_attr(rt2x00dev, i);
rt2800_register_write(rt2x00dev, MAC_IVEIV_ENTRY(i), 0);
}
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE0);
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE1);
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE2);
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE3);
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE4);
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE5);
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE6);
rt2800_clear_beacon_register(rt2x00dev, HW_BEACON_BASE7);
if (rt2x00_is_usb(rt2x00dev)) {
rt2800_register_read(rt2x00dev, US_CYC_CNT, &reg);
rt2x00_set_field32(&reg, US_CYC_CNT_CLOCK_CYCLE, 30);
rt2800_register_write(rt2x00dev, US_CYC_CNT, reg);
} else if (rt2x00_is_pcie(rt2x00dev)) {
rt2800_register_read(rt2x00dev, US_CYC_CNT, &reg);
rt2x00_set_field32(&reg, US_CYC_CNT_CLOCK_CYCLE, 125);
rt2800_register_write(rt2x00dev, US_CYC_CNT, reg);
}
rt2800_register_read(rt2x00dev, HT_FBK_CFG0, &reg);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS0FBK, 0);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS1FBK, 0);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS2FBK, 1);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS3FBK, 2);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS4FBK, 3);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS5FBK, 4);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS6FBK, 5);
rt2x00_set_field32(&reg, HT_FBK_CFG0_HTMCS7FBK, 6);
rt2800_register_write(rt2x00dev, HT_FBK_CFG0, reg);
rt2800_register_read(rt2x00dev, HT_FBK_CFG1, &reg);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS8FBK, 8);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS9FBK, 8);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS10FBK, 9);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS11FBK, 10);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS12FBK, 11);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS13FBK, 12);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS14FBK, 13);
rt2x00_set_field32(&reg, HT_FBK_CFG1_HTMCS15FBK, 14);
rt2800_register_write(rt2x00dev, HT_FBK_CFG1, reg);
rt2800_register_read(rt2x00dev, LG_FBK_CFG0, &reg);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS0FBK, 8);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS1FBK, 8);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS2FBK, 9);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS3FBK, 10);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS4FBK, 11);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS5FBK, 12);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS6FBK, 13);
rt2x00_set_field32(&reg, LG_FBK_CFG0_OFDMMCS7FBK, 14);
rt2800_register_write(rt2x00dev, LG_FBK_CFG0, reg);
rt2800_register_read(rt2x00dev, LG_FBK_CFG1, &reg);
rt2x00_set_field32(&reg, LG_FBK_CFG0_CCKMCS0FBK, 0);
rt2x00_set_field32(&reg, LG_FBK_CFG0_CCKMCS1FBK, 0);
rt2x00_set_field32(&reg, LG_FBK_CFG0_CCKMCS2FBK, 1);
rt2x00_set_field32(&reg, LG_FBK_CFG0_CCKMCS3FBK, 2);
rt2800_register_write(rt2x00dev, LG_FBK_CFG1, reg);
rt2800_register_read(rt2x00dev, AMPDU_BA_WINSIZE, &reg);
rt2x00_set_field32(&reg, AMPDU_BA_WINSIZE_FORCE_WINSIZE_ENABLE, 0);
rt2x00_set_field32(&reg, AMPDU_BA_WINSIZE_FORCE_WINSIZE, 0);
rt2800_register_write(rt2x00dev, AMPDU_BA_WINSIZE, reg);
rt2800_register_read(rt2x00dev, RX_STA_CNT0, &reg);
rt2800_register_read(rt2x00dev, RX_STA_CNT1, &reg);
rt2800_register_read(rt2x00dev, RX_STA_CNT2, &reg);
rt2800_register_read(rt2x00dev, TX_STA_CNT0, &reg);
rt2800_register_read(rt2x00dev, TX_STA_CNT1, &reg);
rt2800_register_read(rt2x00dev, TX_STA_CNT2, &reg);
rt2800_register_read(rt2x00dev, INT_TIMER_CFG, &reg);
rt2x00_set_field32(&reg, INT_TIMER_CFG_PRE_TBTT_TIMER, 6 << 4);
rt2800_register_write(rt2x00dev, INT_TIMER_CFG, reg);
rt2800_register_read(rt2x00dev, CH_TIME_CFG, &reg);
rt2x00_set_field32(&reg, CH_TIME_CFG_EIFS_BUSY, 1);
rt2x00_set_field32(&reg, CH_TIME_CFG_NAV_BUSY, 1);
rt2x00_set_field32(&reg, CH_TIME_CFG_RX_BUSY, 1);
rt2x00_set_field32(&reg, CH_TIME_CFG_TX_BUSY, 1);
rt2x00_set_field32(&reg, CH_TIME_CFG_TMR_EN, 1);
rt2800_register_write(rt2x00dev, CH_TIME_CFG, reg);
return 0;
}
static int rt2800_wait_bbp_rf_ready(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u32 reg;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2800_register_read(rt2x00dev, MAC_STATUS_CFG, &reg);
if (!rt2x00_get_field32(reg, MAC_STATUS_CFG_BBP_RF_BUSY))
return 0;
udelay(REGISTER_BUSY_DELAY);
}
ERROR(rt2x00dev, "BBP/RF register access failed, aborting.\n");
return -EACCES;
}
static int rt2800_wait_bbp_ready(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u8 value;
rt2800_register_write(rt2x00dev, H2M_BBP_AGENT, 0);
rt2800_register_write(rt2x00dev, H2M_MAILBOX_CSR, 0);
msleep(1);
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2800_bbp_read(rt2x00dev, 0, &value);
if ((value != 0xff) && (value != 0x00))
return 0;
udelay(REGISTER_BUSY_DELAY);
}
ERROR(rt2x00dev, "BBP register access failed, aborting.\n");
return -EACCES;
}
static int rt2800_init_bbp(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u16 eeprom;
u8 reg_id;
u8 value;
if (unlikely(rt2800_wait_bbp_rf_ready(rt2x00dev) ||
rt2800_wait_bbp_ready(rt2x00dev)))
return -EACCES;
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_bbp_read(rt2x00dev, 4, &value);
rt2x00_set_field8(&value, BBP4_MAC_IF_CTRL, 1);
rt2800_bbp_write(rt2x00dev, 4, value);
}
if (rt2800_is_305x_soc(rt2x00dev) ||
rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT3572) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 31, 0x08);
rt2800_bbp_write(rt2x00dev, 65, 0x2c);
rt2800_bbp_write(rt2x00dev, 66, 0x38);
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 68, 0x0b);
if (rt2x00_rt_rev(rt2x00dev, RT2860, REV_RT2860C)) {
rt2800_bbp_write(rt2x00dev, 69, 0x16);
rt2800_bbp_write(rt2x00dev, 73, 0x12);
} else if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_bbp_write(rt2x00dev, 69, 0x12);
rt2800_bbp_write(rt2x00dev, 73, 0x13);
rt2800_bbp_write(rt2x00dev, 75, 0x46);
rt2800_bbp_write(rt2x00dev, 76, 0x28);
if (rt2x00_rt(rt2x00dev, RT3290))
rt2800_bbp_write(rt2x00dev, 77, 0x58);
else
rt2800_bbp_write(rt2x00dev, 77, 0x59);
} else {
rt2800_bbp_write(rt2x00dev, 69, 0x12);
rt2800_bbp_write(rt2x00dev, 73, 0x10);
}
rt2800_bbp_write(rt2x00dev, 70, 0x0a);
if (rt2x00_rt(rt2x00dev, RT3070) ||
rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3390) ||
rt2x00_rt(rt2x00dev, RT3572) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_bbp_write(rt2x00dev, 79, 0x13);
rt2800_bbp_write(rt2x00dev, 80, 0x05);
rt2800_bbp_write(rt2x00dev, 81, 0x33);
} else if (rt2800_is_305x_soc(rt2x00dev)) {
rt2800_bbp_write(rt2x00dev, 78, 0x0e);
rt2800_bbp_write(rt2x00dev, 80, 0x08);
} else {
rt2800_bbp_write(rt2x00dev, 81, 0x37);
}
if (rt2x00_rt(rt2x00dev, RT3290)) {
rt2800_bbp_write(rt2x00dev, 74, 0x0b);
rt2800_bbp_write(rt2x00dev, 79, 0x18);
rt2800_bbp_write(rt2x00dev, 80, 0x09);
rt2800_bbp_write(rt2x00dev, 81, 0x33);
}
rt2800_bbp_write(rt2x00dev, 82, 0x62);
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 83, 0x7a);
else
rt2800_bbp_write(rt2x00dev, 83, 0x6a);
if (rt2x00_rt_rev(rt2x00dev, RT2860, REV_RT2860D))
rt2800_bbp_write(rt2x00dev, 84, 0x19);
else if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 84, 0x9a);
else
rt2800_bbp_write(rt2x00dev, 84, 0x99);
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 86, 0x38);
else
rt2800_bbp_write(rt2x00dev, 86, 0x00);
if (rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 88, 0x90);
rt2800_bbp_write(rt2x00dev, 91, 0x04);
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 92, 0x02);
else
rt2800_bbp_write(rt2x00dev, 92, 0x00);
if (rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_bbp_write(rt2x00dev, 95, 0x9a);
rt2800_bbp_write(rt2x00dev, 98, 0x12);
}
if (rt2x00_rt_rev_gte(rt2x00dev, RT3070, REV_RT3070F) ||
rt2x00_rt_rev_gte(rt2x00dev, RT3071, REV_RT3071E) ||
rt2x00_rt_rev_gte(rt2x00dev, RT3090, REV_RT3090E) ||
rt2x00_rt_rev_gte(rt2x00dev, RT3390, REV_RT3390E) ||
rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT3572) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392) ||
rt2800_is_305x_soc(rt2x00dev))
rt2800_bbp_write(rt2x00dev, 103, 0xc0);
else
rt2800_bbp_write(rt2x00dev, 103, 0x00);
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 104, 0x92);
if (rt2800_is_305x_soc(rt2x00dev))
rt2800_bbp_write(rt2x00dev, 105, 0x01);
else if (rt2x00_rt(rt2x00dev, RT3290))
rt2800_bbp_write(rt2x00dev, 105, 0x1c);
else if (rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 105, 0x3c);
else
rt2800_bbp_write(rt2x00dev, 105, 0x05);
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390))
rt2800_bbp_write(rt2x00dev, 106, 0x03);
else if (rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 106, 0x12);
else
rt2800_bbp_write(rt2x00dev, 106, 0x35);
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))
rt2800_bbp_write(rt2x00dev, 128, 0x12);
if (rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_bbp_write(rt2x00dev, 134, 0xd0);
rt2800_bbp_write(rt2x00dev, 135, 0xf6);
}
if (rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3390) ||
rt2x00_rt(rt2x00dev, RT3572) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_bbp_read(rt2x00dev, 138, &value);
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF0, &eeprom);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_TXPATH) == 1)
value |= 0x20;
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_RXPATH) == 1)
value &= ~0x02;
rt2800_bbp_write(rt2x00dev, 138, value);
}
if (rt2x00_rt(rt2x00dev, RT3290)) {
rt2800_bbp_write(rt2x00dev, 67, 0x24);
rt2800_bbp_write(rt2x00dev, 143, 0x04);
rt2800_bbp_write(rt2x00dev, 142, 0x99);
rt2800_bbp_write(rt2x00dev, 150, 0x30);
rt2800_bbp_write(rt2x00dev, 151, 0x2e);
rt2800_bbp_write(rt2x00dev, 152, 0x20);
rt2800_bbp_write(rt2x00dev, 153, 0x34);
rt2800_bbp_write(rt2x00dev, 154, 0x40);
rt2800_bbp_write(rt2x00dev, 155, 0x3b);
rt2800_bbp_write(rt2x00dev, 253, 0x04);
rt2800_bbp_read(rt2x00dev, 47, &value);
rt2x00_set_field8(&value, BBP47_TSSI_ADC6, 1);
rt2800_bbp_write(rt2x00dev, 47, value);
rt2800_bbp_read(rt2x00dev, 3, &value);
rt2x00_set_field8(&value, BBP3_ADC_MODE_SWITCH, 1);
rt2x00_set_field8(&value, BBP3_ADC_INIT_MODE, 1);
rt2800_bbp_write(rt2x00dev, 3, value);
}
if (rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
int ant, div_mode;
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF1, &eeprom);
div_mode = rt2x00_get_field16(eeprom,
EEPROM_NIC_CONF1_ANT_DIVERSITY);
ant = (div_mode == 3) ? 1 : 0;
if (test_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags)) {
u32 reg;
rt2800_register_read(rt2x00dev, GPIO_CTRL_CFG, &reg);
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_GPIOD_BIT3, 0);
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_GPIOD_BIT6, 0);
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_BIT3, 0);
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_BIT6, 0);
if (ant == 0)
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_BIT3, 1);
else if (ant == 1)
rt2x00_set_field32(&reg, GPIO_CTRL_CFG_BIT6, 1);
rt2800_register_write(rt2x00dev, GPIO_CTRL_CFG, reg);
}
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390R)) {
rt2800_bbp_write(rt2x00dev, 150, 0);
rt2800_bbp_write(rt2x00dev, 151, 0);
rt2800_bbp_write(rt2x00dev, 154, 0);
}
rt2800_bbp_read(rt2x00dev, 152, &value);
if (ant == 0)
rt2x00_set_field8(&value, BBP152_RX_DEFAULT_ANT, 1);
else
rt2x00_set_field8(&value, BBP152_RX_DEFAULT_ANT, 0);
rt2800_bbp_write(rt2x00dev, 152, value);
rt2800_bbp_write(rt2x00dev, 142, 1);
rt2800_bbp_write(rt2x00dev, 143, 57);
}
for (i = 0; i < EEPROM_BBP_SIZE; i++) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBP_START + i, &eeprom);
if (eeprom != 0xffff && eeprom != 0x0000) {
reg_id = rt2x00_get_field16(eeprom, EEPROM_BBP_REG_ID);
value = rt2x00_get_field16(eeprom, EEPROM_BBP_VALUE);
rt2800_bbp_write(rt2x00dev, reg_id, value);
}
}
return 0;
}
static u8 rt2800_init_rx_filter(struct rt2x00_dev *rt2x00dev,
bool bw40, u8 rfcsr24, u8 filter_target)
{
unsigned int i;
u8 bbp;
u8 rfcsr;
u8 passband;
u8 stopband;
u8 overtuned = 0;
rt2800_rfcsr_write(rt2x00dev, 24, rfcsr24);
rt2800_bbp_read(rt2x00dev, 4, &bbp);
rt2x00_set_field8(&bbp, BBP4_BANDWIDTH, 2 * bw40);
rt2800_bbp_write(rt2x00dev, 4, bbp);
rt2800_rfcsr_read(rt2x00dev, 31, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR31_RX_H20M, bw40);
rt2800_rfcsr_write(rt2x00dev, 31, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 22, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR22_BASEBAND_LOOPBACK, 1);
rt2800_rfcsr_write(rt2x00dev, 22, rfcsr);
rt2800_bbp_write(rt2x00dev, 24, 0);
for (i = 0; i < 100; i++) {
rt2800_bbp_write(rt2x00dev, 25, 0x90);
msleep(1);
rt2800_bbp_read(rt2x00dev, 55, &passband);
if (passband)
break;
}
rt2800_bbp_write(rt2x00dev, 24, 0x06);
for (i = 0; i < 100; i++) {
rt2800_bbp_write(rt2x00dev, 25, 0x90);
msleep(1);
rt2800_bbp_read(rt2x00dev, 55, &stopband);
if ((passband - stopband) <= filter_target) {
rfcsr24++;
overtuned += ((passband - stopband) == filter_target);
} else
break;
rt2800_rfcsr_write(rt2x00dev, 24, rfcsr24);
}
rfcsr24 -= !!overtuned;
rt2800_rfcsr_write(rt2x00dev, 24, rfcsr24);
return rfcsr24;
}
static int rt2800_init_rfcsr(struct rt2x00_dev *rt2x00dev)
{
struct rt2800_drv_data *drv_data = rt2x00dev->drv_data;
u8 rfcsr;
u8 bbp;
u32 reg;
u16 eeprom;
if (!rt2x00_rt(rt2x00dev, RT3070) &&
!rt2x00_rt(rt2x00dev, RT3071) &&
!rt2x00_rt(rt2x00dev, RT3090) &&
!rt2x00_rt(rt2x00dev, RT3290) &&
!rt2x00_rt(rt2x00dev, RT3390) &&
!rt2x00_rt(rt2x00dev, RT3572) &&
!rt2x00_rt(rt2x00dev, RT5390) &&
!rt2x00_rt(rt2x00dev, RT5392) &&
!rt2800_is_305x_soc(rt2x00dev))
return 0;
if (rt2x00_rt(rt2x00dev, RT3290) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_rfcsr_read(rt2x00dev, 2, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR2_RESCAL_EN, 1);
rt2800_rfcsr_write(rt2x00dev, 2, rfcsr);
msleep(1);
rt2x00_set_field8(&rfcsr, RFCSR2_RESCAL_EN, 0);
rt2800_rfcsr_write(rt2x00dev, 2, rfcsr);
} else {
rt2800_rfcsr_read(rt2x00dev, 30, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 1);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
msleep(1);
rt2x00_set_field8(&rfcsr, RFCSR30_RF_CALIBRATION, 0);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
}
if (rt2x00_rt(rt2x00dev, RT3070) ||
rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090)) {
rt2800_rfcsr_write(rt2x00dev, 4, 0x40);
rt2800_rfcsr_write(rt2x00dev, 5, 0x03);
rt2800_rfcsr_write(rt2x00dev, 6, 0x02);
rt2800_rfcsr_write(rt2x00dev, 7, 0x60);
rt2800_rfcsr_write(rt2x00dev, 9, 0x0f);
rt2800_rfcsr_write(rt2x00dev, 10, 0x41);
rt2800_rfcsr_write(rt2x00dev, 11, 0x21);
rt2800_rfcsr_write(rt2x00dev, 12, 0x7b);
rt2800_rfcsr_write(rt2x00dev, 14, 0x90);
rt2800_rfcsr_write(rt2x00dev, 15, 0x58);
rt2800_rfcsr_write(rt2x00dev, 16, 0xb3);
rt2800_rfcsr_write(rt2x00dev, 17, 0x92);
rt2800_rfcsr_write(rt2x00dev, 18, 0x2c);
rt2800_rfcsr_write(rt2x00dev, 19, 0x02);
rt2800_rfcsr_write(rt2x00dev, 20, 0xba);
rt2800_rfcsr_write(rt2x00dev, 21, 0xdb);
rt2800_rfcsr_write(rt2x00dev, 24, 0x16);
rt2800_rfcsr_write(rt2x00dev, 25, 0x01);
rt2800_rfcsr_write(rt2x00dev, 29, 0x1f);
} else if (rt2x00_rt(rt2x00dev, RT3290)) {
rt2800_rfcsr_write(rt2x00dev, 1, 0x0f);
rt2800_rfcsr_write(rt2x00dev, 2, 0x80);
rt2800_rfcsr_write(rt2x00dev, 3, 0x08);
rt2800_rfcsr_write(rt2x00dev, 4, 0x00);
rt2800_rfcsr_write(rt2x00dev, 6, 0xa0);
rt2800_rfcsr_write(rt2x00dev, 8, 0xf3);
rt2800_rfcsr_write(rt2x00dev, 9, 0x02);
rt2800_rfcsr_write(rt2x00dev, 10, 0x53);
rt2800_rfcsr_write(rt2x00dev, 11, 0x4a);
rt2800_rfcsr_write(rt2x00dev, 12, 0x46);
rt2800_rfcsr_write(rt2x00dev, 13, 0x9f);
rt2800_rfcsr_write(rt2x00dev, 18, 0x02);
rt2800_rfcsr_write(rt2x00dev, 22, 0x20);
rt2800_rfcsr_write(rt2x00dev, 25, 0x83);
rt2800_rfcsr_write(rt2x00dev, 26, 0x82);
rt2800_rfcsr_write(rt2x00dev, 27, 0x09);
rt2800_rfcsr_write(rt2x00dev, 29, 0x10);
rt2800_rfcsr_write(rt2x00dev, 30, 0x10);
rt2800_rfcsr_write(rt2x00dev, 31, 0x80);
rt2800_rfcsr_write(rt2x00dev, 32, 0x80);
rt2800_rfcsr_write(rt2x00dev, 33, 0x00);
rt2800_rfcsr_write(rt2x00dev, 34, 0x05);
rt2800_rfcsr_write(rt2x00dev, 35, 0x12);
rt2800_rfcsr_write(rt2x00dev, 36, 0x00);
rt2800_rfcsr_write(rt2x00dev, 38, 0x85);
rt2800_rfcsr_write(rt2x00dev, 39, 0x1b);
rt2800_rfcsr_write(rt2x00dev, 40, 0x0b);
rt2800_rfcsr_write(rt2x00dev, 41, 0xbb);
rt2800_rfcsr_write(rt2x00dev, 42, 0xd5);
rt2800_rfcsr_write(rt2x00dev, 43, 0x7b);
rt2800_rfcsr_write(rt2x00dev, 44, 0x0e);
rt2800_rfcsr_write(rt2x00dev, 45, 0xa2);
rt2800_rfcsr_write(rt2x00dev, 46, 0x73);
rt2800_rfcsr_write(rt2x00dev, 47, 0x00);
rt2800_rfcsr_write(rt2x00dev, 48, 0x10);
rt2800_rfcsr_write(rt2x00dev, 49, 0x98);
rt2800_rfcsr_write(rt2x00dev, 52, 0x38);
rt2800_rfcsr_write(rt2x00dev, 53, 0x00);
rt2800_rfcsr_write(rt2x00dev, 54, 0x78);
rt2800_rfcsr_write(rt2x00dev, 55, 0x43);
rt2800_rfcsr_write(rt2x00dev, 56, 0x02);
rt2800_rfcsr_write(rt2x00dev, 57, 0x80);
rt2800_rfcsr_write(rt2x00dev, 58, 0x7f);
rt2800_rfcsr_write(rt2x00dev, 59, 0x09);
rt2800_rfcsr_write(rt2x00dev, 60, 0x45);
rt2800_rfcsr_write(rt2x00dev, 61, 0xc1);
} else if (rt2x00_rt(rt2x00dev, RT3390)) {
rt2800_rfcsr_write(rt2x00dev, 0, 0xa0);
rt2800_rfcsr_write(rt2x00dev, 1, 0xe1);
rt2800_rfcsr_write(rt2x00dev, 2, 0xf1);
rt2800_rfcsr_write(rt2x00dev, 3, 0x62);
rt2800_rfcsr_write(rt2x00dev, 4, 0x40);
rt2800_rfcsr_write(rt2x00dev, 5, 0x8b);
rt2800_rfcsr_write(rt2x00dev, 6, 0x42);
rt2800_rfcsr_write(rt2x00dev, 7, 0x34);
rt2800_rfcsr_write(rt2x00dev, 8, 0x00);
rt2800_rfcsr_write(rt2x00dev, 9, 0xc0);
rt2800_rfcsr_write(rt2x00dev, 10, 0x61);
rt2800_rfcsr_write(rt2x00dev, 11, 0x21);
rt2800_rfcsr_write(rt2x00dev, 12, 0x3b);
rt2800_rfcsr_write(rt2x00dev, 13, 0xe0);
rt2800_rfcsr_write(rt2x00dev, 14, 0x90);
rt2800_rfcsr_write(rt2x00dev, 15, 0x53);
rt2800_rfcsr_write(rt2x00dev, 16, 0xe0);
rt2800_rfcsr_write(rt2x00dev, 17, 0x94);
rt2800_rfcsr_write(rt2x00dev, 18, 0x5c);
rt2800_rfcsr_write(rt2x00dev, 19, 0x4a);
rt2800_rfcsr_write(rt2x00dev, 20, 0xb2);
rt2800_rfcsr_write(rt2x00dev, 21, 0xf6);
rt2800_rfcsr_write(rt2x00dev, 22, 0x00);
rt2800_rfcsr_write(rt2x00dev, 23, 0x14);
rt2800_rfcsr_write(rt2x00dev, 24, 0x08);
rt2800_rfcsr_write(rt2x00dev, 25, 0x3d);
rt2800_rfcsr_write(rt2x00dev, 26, 0x85);
rt2800_rfcsr_write(rt2x00dev, 27, 0x00);
rt2800_rfcsr_write(rt2x00dev, 28, 0x41);
rt2800_rfcsr_write(rt2x00dev, 29, 0x8f);
rt2800_rfcsr_write(rt2x00dev, 30, 0x20);
rt2800_rfcsr_write(rt2x00dev, 31, 0x0f);
} else if (rt2x00_rt(rt2x00dev, RT3572)) {
rt2800_rfcsr_write(rt2x00dev, 0, 0x70);
rt2800_rfcsr_write(rt2x00dev, 1, 0x81);
rt2800_rfcsr_write(rt2x00dev, 2, 0xf1);
rt2800_rfcsr_write(rt2x00dev, 3, 0x02);
rt2800_rfcsr_write(rt2x00dev, 4, 0x4c);
rt2800_rfcsr_write(rt2x00dev, 5, 0x05);
rt2800_rfcsr_write(rt2x00dev, 6, 0x4a);
rt2800_rfcsr_write(rt2x00dev, 7, 0xd8);
rt2800_rfcsr_write(rt2x00dev, 9, 0xc3);
rt2800_rfcsr_write(rt2x00dev, 10, 0xf1);
rt2800_rfcsr_write(rt2x00dev, 11, 0xb9);
rt2800_rfcsr_write(rt2x00dev, 12, 0x70);
rt2800_rfcsr_write(rt2x00dev, 13, 0x65);
rt2800_rfcsr_write(rt2x00dev, 14, 0xa0);
rt2800_rfcsr_write(rt2x00dev, 15, 0x53);
rt2800_rfcsr_write(rt2x00dev, 16, 0x4c);
rt2800_rfcsr_write(rt2x00dev, 17, 0x23);
rt2800_rfcsr_write(rt2x00dev, 18, 0xac);
rt2800_rfcsr_write(rt2x00dev, 19, 0x93);
rt2800_rfcsr_write(rt2x00dev, 20, 0xb3);
rt2800_rfcsr_write(rt2x00dev, 21, 0xd0);
rt2800_rfcsr_write(rt2x00dev, 22, 0x00);
rt2800_rfcsr_write(rt2x00dev, 23, 0x3c);
rt2800_rfcsr_write(rt2x00dev, 24, 0x16);
rt2800_rfcsr_write(rt2x00dev, 25, 0x15);
rt2800_rfcsr_write(rt2x00dev, 26, 0x85);
rt2800_rfcsr_write(rt2x00dev, 27, 0x00);
rt2800_rfcsr_write(rt2x00dev, 28, 0x00);
rt2800_rfcsr_write(rt2x00dev, 29, 0x9b);
rt2800_rfcsr_write(rt2x00dev, 30, 0x09);
rt2800_rfcsr_write(rt2x00dev, 31, 0x10);
} else if (rt2800_is_305x_soc(rt2x00dev)) {
rt2800_rfcsr_write(rt2x00dev, 0, 0x50);
rt2800_rfcsr_write(rt2x00dev, 1, 0x01);
rt2800_rfcsr_write(rt2x00dev, 2, 0xf7);
rt2800_rfcsr_write(rt2x00dev, 3, 0x75);
rt2800_rfcsr_write(rt2x00dev, 4, 0x40);
rt2800_rfcsr_write(rt2x00dev, 5, 0x03);
rt2800_rfcsr_write(rt2x00dev, 6, 0x02);
rt2800_rfcsr_write(rt2x00dev, 7, 0x50);
rt2800_rfcsr_write(rt2x00dev, 8, 0x39);
rt2800_rfcsr_write(rt2x00dev, 9, 0x0f);
rt2800_rfcsr_write(rt2x00dev, 10, 0x60);
rt2800_rfcsr_write(rt2x00dev, 11, 0x21);
rt2800_rfcsr_write(rt2x00dev, 12, 0x75);
rt2800_rfcsr_write(rt2x00dev, 13, 0x75);
rt2800_rfcsr_write(rt2x00dev, 14, 0x90);
rt2800_rfcsr_write(rt2x00dev, 15, 0x58);
rt2800_rfcsr_write(rt2x00dev, 16, 0xb3);
rt2800_rfcsr_write(rt2x00dev, 17, 0x92);
rt2800_rfcsr_write(rt2x00dev, 18, 0x2c);
rt2800_rfcsr_write(rt2x00dev, 19, 0x02);
rt2800_rfcsr_write(rt2x00dev, 20, 0xba);
rt2800_rfcsr_write(rt2x00dev, 21, 0xdb);
rt2800_rfcsr_write(rt2x00dev, 22, 0x00);
rt2800_rfcsr_write(rt2x00dev, 23, 0x31);
rt2800_rfcsr_write(rt2x00dev, 24, 0x08);
rt2800_rfcsr_write(rt2x00dev, 25, 0x01);
rt2800_rfcsr_write(rt2x00dev, 26, 0x25);
rt2800_rfcsr_write(rt2x00dev, 27, 0x23);
rt2800_rfcsr_write(rt2x00dev, 28, 0x13);
rt2800_rfcsr_write(rt2x00dev, 29, 0x83);
rt2800_rfcsr_write(rt2x00dev, 30, 0x00);
rt2800_rfcsr_write(rt2x00dev, 31, 0x00);
return 0;
} else if (rt2x00_rt(rt2x00dev, RT5390)) {
rt2800_rfcsr_write(rt2x00dev, 1, 0x0f);
rt2800_rfcsr_write(rt2x00dev, 2, 0x80);
rt2800_rfcsr_write(rt2x00dev, 3, 0x88);
rt2800_rfcsr_write(rt2x00dev, 5, 0x10);
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F))
rt2800_rfcsr_write(rt2x00dev, 6, 0xe0);
else
rt2800_rfcsr_write(rt2x00dev, 6, 0xa0);
rt2800_rfcsr_write(rt2x00dev, 7, 0x00);
rt2800_rfcsr_write(rt2x00dev, 10, 0x53);
rt2800_rfcsr_write(rt2x00dev, 11, 0x4a);
rt2800_rfcsr_write(rt2x00dev, 12, 0xc6);
rt2800_rfcsr_write(rt2x00dev, 13, 0x9f);
rt2800_rfcsr_write(rt2x00dev, 14, 0x00);
rt2800_rfcsr_write(rt2x00dev, 15, 0x00);
rt2800_rfcsr_write(rt2x00dev, 16, 0x00);
rt2800_rfcsr_write(rt2x00dev, 18, 0x03);
rt2800_rfcsr_write(rt2x00dev, 19, 0x00);
rt2800_rfcsr_write(rt2x00dev, 20, 0x00);
rt2800_rfcsr_write(rt2x00dev, 21, 0x00);
rt2800_rfcsr_write(rt2x00dev, 22, 0x20);
rt2800_rfcsr_write(rt2x00dev, 23, 0x00);
rt2800_rfcsr_write(rt2x00dev, 24, 0x00);
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F))
rt2800_rfcsr_write(rt2x00dev, 25, 0x80);
else
rt2800_rfcsr_write(rt2x00dev, 25, 0xc0);
rt2800_rfcsr_write(rt2x00dev, 26, 0x00);
rt2800_rfcsr_write(rt2x00dev, 27, 0x09);
rt2800_rfcsr_write(rt2x00dev, 28, 0x00);
rt2800_rfcsr_write(rt2x00dev, 29, 0x10);
rt2800_rfcsr_write(rt2x00dev, 30, 0x00);
rt2800_rfcsr_write(rt2x00dev, 31, 0x80);
rt2800_rfcsr_write(rt2x00dev, 32, 0x80);
rt2800_rfcsr_write(rt2x00dev, 33, 0x00);
rt2800_rfcsr_write(rt2x00dev, 34, 0x07);
rt2800_rfcsr_write(rt2x00dev, 35, 0x12);
rt2800_rfcsr_write(rt2x00dev, 36, 0x00);
rt2800_rfcsr_write(rt2x00dev, 37, 0x08);
rt2800_rfcsr_write(rt2x00dev, 38, 0x85);
rt2800_rfcsr_write(rt2x00dev, 39, 0x1b);
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F))
rt2800_rfcsr_write(rt2x00dev, 40, 0x0b);
else
rt2800_rfcsr_write(rt2x00dev, 40, 0x4b);
rt2800_rfcsr_write(rt2x00dev, 41, 0xbb);
rt2800_rfcsr_write(rt2x00dev, 42, 0xd2);
rt2800_rfcsr_write(rt2x00dev, 43, 0x9a);
rt2800_rfcsr_write(rt2x00dev, 44, 0x0e);
rt2800_rfcsr_write(rt2x00dev, 45, 0xa2);
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F))
rt2800_rfcsr_write(rt2x00dev, 46, 0x73);
else
rt2800_rfcsr_write(rt2x00dev, 46, 0x7b);
rt2800_rfcsr_write(rt2x00dev, 47, 0x00);
rt2800_rfcsr_write(rt2x00dev, 48, 0x10);
rt2800_rfcsr_write(rt2x00dev, 49, 0x94);
rt2800_rfcsr_write(rt2x00dev, 52, 0x38);
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F))
rt2800_rfcsr_write(rt2x00dev, 53, 0x00);
else
rt2800_rfcsr_write(rt2x00dev, 53, 0x84);
rt2800_rfcsr_write(rt2x00dev, 54, 0x78);
rt2800_rfcsr_write(rt2x00dev, 55, 0x44);
rt2800_rfcsr_write(rt2x00dev, 56, 0x22);
rt2800_rfcsr_write(rt2x00dev, 57, 0x80);
rt2800_rfcsr_write(rt2x00dev, 58, 0x7f);
rt2800_rfcsr_write(rt2x00dev, 59, 0x63);
rt2800_rfcsr_write(rt2x00dev, 60, 0x45);
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390F))
rt2800_rfcsr_write(rt2x00dev, 61, 0xd1);
else
rt2800_rfcsr_write(rt2x00dev, 61, 0xdd);
rt2800_rfcsr_write(rt2x00dev, 62, 0x00);
rt2800_rfcsr_write(rt2x00dev, 63, 0x00);
} else if (rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_rfcsr_write(rt2x00dev, 1, 0x17);
rt2800_rfcsr_write(rt2x00dev, 2, 0x80);
rt2800_rfcsr_write(rt2x00dev, 3, 0x88);
rt2800_rfcsr_write(rt2x00dev, 5, 0x10);
rt2800_rfcsr_write(rt2x00dev, 6, 0xe0);
rt2800_rfcsr_write(rt2x00dev, 7, 0x00);
rt2800_rfcsr_write(rt2x00dev, 10, 0x53);
rt2800_rfcsr_write(rt2x00dev, 11, 0x4a);
rt2800_rfcsr_write(rt2x00dev, 12, 0x46);
rt2800_rfcsr_write(rt2x00dev, 13, 0x9f);
rt2800_rfcsr_write(rt2x00dev, 14, 0x00);
rt2800_rfcsr_write(rt2x00dev, 15, 0x00);
rt2800_rfcsr_write(rt2x00dev, 16, 0x00);
rt2800_rfcsr_write(rt2x00dev, 18, 0x03);
rt2800_rfcsr_write(rt2x00dev, 19, 0x4d);
rt2800_rfcsr_write(rt2x00dev, 20, 0x00);
rt2800_rfcsr_write(rt2x00dev, 21, 0x8d);
rt2800_rfcsr_write(rt2x00dev, 22, 0x20);
rt2800_rfcsr_write(rt2x00dev, 23, 0x0b);
rt2800_rfcsr_write(rt2x00dev, 24, 0x44);
rt2800_rfcsr_write(rt2x00dev, 25, 0x80);
rt2800_rfcsr_write(rt2x00dev, 26, 0x82);
rt2800_rfcsr_write(rt2x00dev, 27, 0x09);
rt2800_rfcsr_write(rt2x00dev, 28, 0x00);
rt2800_rfcsr_write(rt2x00dev, 29, 0x10);
rt2800_rfcsr_write(rt2x00dev, 30, 0x10);
rt2800_rfcsr_write(rt2x00dev, 31, 0x80);
rt2800_rfcsr_write(rt2x00dev, 32, 0x20);
rt2800_rfcsr_write(rt2x00dev, 33, 0xC0);
rt2800_rfcsr_write(rt2x00dev, 34, 0x07);
rt2800_rfcsr_write(rt2x00dev, 35, 0x12);
rt2800_rfcsr_write(rt2x00dev, 36, 0x00);
rt2800_rfcsr_write(rt2x00dev, 37, 0x08);
rt2800_rfcsr_write(rt2x00dev, 38, 0x89);
rt2800_rfcsr_write(rt2x00dev, 39, 0x1b);
rt2800_rfcsr_write(rt2x00dev, 40, 0x0f);
rt2800_rfcsr_write(rt2x00dev, 41, 0xbb);
rt2800_rfcsr_write(rt2x00dev, 42, 0xd5);
rt2800_rfcsr_write(rt2x00dev, 43, 0x9b);
rt2800_rfcsr_write(rt2x00dev, 44, 0x0e);
rt2800_rfcsr_write(rt2x00dev, 45, 0xa2);
rt2800_rfcsr_write(rt2x00dev, 46, 0x73);
rt2800_rfcsr_write(rt2x00dev, 47, 0x0c);
rt2800_rfcsr_write(rt2x00dev, 48, 0x10);
rt2800_rfcsr_write(rt2x00dev, 49, 0x94);
rt2800_rfcsr_write(rt2x00dev, 50, 0x94);
rt2800_rfcsr_write(rt2x00dev, 51, 0x3a);
rt2800_rfcsr_write(rt2x00dev, 52, 0x48);
rt2800_rfcsr_write(rt2x00dev, 53, 0x44);
rt2800_rfcsr_write(rt2x00dev, 54, 0x38);
rt2800_rfcsr_write(rt2x00dev, 55, 0x43);
rt2800_rfcsr_write(rt2x00dev, 56, 0xa1);
rt2800_rfcsr_write(rt2x00dev, 57, 0x00);
rt2800_rfcsr_write(rt2x00dev, 58, 0x39);
rt2800_rfcsr_write(rt2x00dev, 59, 0x07);
rt2800_rfcsr_write(rt2x00dev, 60, 0x45);
rt2800_rfcsr_write(rt2x00dev, 61, 0x91);
rt2800_rfcsr_write(rt2x00dev, 62, 0x39);
rt2800_rfcsr_write(rt2x00dev, 63, 0x07);
}
if (rt2x00_rt_rev_lt(rt2x00dev, RT3070, REV_RT3070F)) {
rt2800_register_read(rt2x00dev, LDO_CFG0, &reg);
rt2x00_set_field32(&reg, LDO_CFG0_BGSEL, 1);
rt2x00_set_field32(&reg, LDO_CFG0_LDO_CORE_VLEVEL, 3);
rt2800_register_write(rt2x00dev, LDO_CFG0, reg);
} else if (rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090)) {
rt2800_rfcsr_write(rt2x00dev, 31, 0x14);
rt2800_rfcsr_read(rt2x00dev, 6, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR6_R2, 1);
rt2800_rfcsr_write(rt2x00dev, 6, rfcsr);
rt2800_register_read(rt2x00dev, LDO_CFG0, &reg);
rt2x00_set_field32(&reg, LDO_CFG0_BGSEL, 1);
if (rt2x00_rt_rev_lt(rt2x00dev, RT3071, REV_RT3071E) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3090, REV_RT3090E)) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF1, &eeprom);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF1_DAC_TEST))
rt2x00_set_field32(&reg, LDO_CFG0_LDO_CORE_VLEVEL, 3);
else
rt2x00_set_field32(&reg, LDO_CFG0_LDO_CORE_VLEVEL, 0);
}
rt2800_register_write(rt2x00dev, LDO_CFG0, reg);
rt2800_register_read(rt2x00dev, GPIO_SWITCH, &reg);
rt2x00_set_field32(&reg, GPIO_SWITCH_5, 0);
rt2800_register_write(rt2x00dev, GPIO_SWITCH, reg);
} else if (rt2x00_rt(rt2x00dev, RT3390)) {
rt2800_register_read(rt2x00dev, GPIO_SWITCH, &reg);
rt2x00_set_field32(&reg, GPIO_SWITCH_5, 0);
rt2800_register_write(rt2x00dev, GPIO_SWITCH, reg);
} else if (rt2x00_rt(rt2x00dev, RT3572)) {
rt2800_rfcsr_read(rt2x00dev, 6, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR6_R2, 1);
rt2800_rfcsr_write(rt2x00dev, 6, rfcsr);
rt2800_register_read(rt2x00dev, LDO_CFG0, &reg);
rt2x00_set_field32(&reg, LDO_CFG0_LDO_CORE_VLEVEL, 3);
rt2x00_set_field32(&reg, LDO_CFG0_BGSEL, 1);
rt2800_register_write(rt2x00dev, LDO_CFG0, reg);
msleep(1);
rt2800_register_read(rt2x00dev, LDO_CFG0, &reg);
rt2x00_set_field32(&reg, LDO_CFG0_LDO_CORE_VLEVEL, 0);
rt2x00_set_field32(&reg, LDO_CFG0_BGSEL, 1);
rt2800_register_write(rt2x00dev, LDO_CFG0, reg);
}
if (rt2x00_rt(rt2x00dev, RT3070)) {
drv_data->calibration_bw20 =
rt2800_init_rx_filter(rt2x00dev, false, 0x07, 0x16);
drv_data->calibration_bw40 =
rt2800_init_rx_filter(rt2x00dev, true, 0x27, 0x19);
} else if (rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3390) ||
rt2x00_rt(rt2x00dev, RT3572)) {
drv_data->calibration_bw20 =
rt2800_init_rx_filter(rt2x00dev, false, 0x07, 0x13);
drv_data->calibration_bw40 =
rt2800_init_rx_filter(rt2x00dev, true, 0x27, 0x15);
}
rt2800_bbp_read(rt2x00dev, 25, &drv_data->bbp25);
rt2800_bbp_read(rt2x00dev, 26, &drv_data->bbp26);
if (!rt2x00_rt(rt2x00dev, RT5390) &&
!rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_bbp_write(rt2x00dev, 24, 0);
rt2800_rfcsr_read(rt2x00dev, 22, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR22_BASEBAND_LOOPBACK, 0);
rt2800_rfcsr_write(rt2x00dev, 22, rfcsr);
rt2800_bbp_read(rt2x00dev, 4, &bbp);
rt2x00_set_field8(&bbp, BBP4_BANDWIDTH, 0);
rt2800_bbp_write(rt2x00dev, 4, bbp);
}
if (rt2x00_rt_rev_lt(rt2x00dev, RT3070, REV_RT3070F) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3071, REV_RT3071E) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3090, REV_RT3090E) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3390, REV_RT3390E))
rt2800_rfcsr_write(rt2x00dev, 27, 0x03);
rt2800_register_read(rt2x00dev, OPT_14_CSR, &reg);
rt2x00_set_field32(&reg, OPT_14_CSR_BIT0, 1);
rt2800_register_write(rt2x00dev, OPT_14_CSR, reg);
if (!rt2x00_rt(rt2x00dev, RT5390) &&
!rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_rfcsr_read(rt2x00dev, 17, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR17_TX_LO1_EN, 0);
if (rt2x00_rt(rt2x00dev, RT3070) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3071, REV_RT3071E) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3090, REV_RT3090E) ||
rt2x00_rt_rev_lt(rt2x00dev, RT3390, REV_RT3390E)) {
if (!test_bit(CAPABILITY_EXTERNAL_LNA_BG,
&rt2x00dev->cap_flags))
rt2x00_set_field8(&rfcsr, RFCSR17_R, 1);
}
rt2x00_set_field8(&rfcsr, RFCSR17_TXMIXER_GAIN,
drv_data->txmixer_gain_24g);
rt2800_rfcsr_write(rt2x00dev, 17, rfcsr);
}
if (rt2x00_rt(rt2x00dev, RT3090)) {
rt2800_bbp_read(rt2x00dev, 138, &bbp);
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF0, &eeprom);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_RXPATH) == 1)
rt2x00_set_field8(&bbp, BBP138_RX_ADC1, 0);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_TXPATH) == 1)
rt2x00_set_field8(&bbp, BBP138_TX_DAC1, 1);
rt2800_bbp_write(rt2x00dev, 138, bbp);
}
if (rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3390)) {
rt2800_rfcsr_read(rt2x00dev, 1, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR1_RF_BLOCK_EN, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_RX0_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_TX0_PD, 0);
rt2x00_set_field8(&rfcsr, RFCSR1_RX1_PD, 1);
rt2x00_set_field8(&rfcsr, RFCSR1_TX1_PD, 1);
rt2800_rfcsr_write(rt2x00dev, 1, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 15, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR15_TX_LO2_EN, 0);
rt2800_rfcsr_write(rt2x00dev, 15, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 20, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR20_RX_LO1_EN, 0);
rt2800_rfcsr_write(rt2x00dev, 20, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 21, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR21_RX_LO2_EN, 0);
rt2800_rfcsr_write(rt2x00dev, 21, rfcsr);
}
if (rt2x00_rt(rt2x00dev, RT3070)) {
rt2800_rfcsr_read(rt2x00dev, 27, &rfcsr);
if (rt2x00_rt_rev_lt(rt2x00dev, RT3070, REV_RT3070F))
rt2x00_set_field8(&rfcsr, RFCSR27_R1, 3);
else
rt2x00_set_field8(&rfcsr, RFCSR27_R1, 0);
rt2x00_set_field8(&rfcsr, RFCSR27_R2, 0);
rt2x00_set_field8(&rfcsr, RFCSR27_R3, 0);
rt2x00_set_field8(&rfcsr, RFCSR27_R4, 0);
rt2800_rfcsr_write(rt2x00dev, 27, rfcsr);
}
if (rt2x00_rt(rt2x00dev, RT3290)) {
rt2800_rfcsr_read(rt2x00dev, 29, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR29_RSSI_GAIN, 3);
rt2800_rfcsr_write(rt2x00dev, 29, rfcsr);
}
if (rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392)) {
rt2800_rfcsr_read(rt2x00dev, 38, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR38_RX_LO1_EN, 0);
rt2800_rfcsr_write(rt2x00dev, 38, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 39, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR39_RX_LO2_EN, 0);
rt2800_rfcsr_write(rt2x00dev, 39, rfcsr);
rt2800_rfcsr_read(rt2x00dev, 30, &rfcsr);
rt2x00_set_field8(&rfcsr, RFCSR30_RX_VCM, 2);
rt2800_rfcsr_write(rt2x00dev, 30, rfcsr);
}
return 0;
}
int rt2800_enable_radio(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
u16 word;
if (unlikely(rt2800_wait_wpdma_ready(rt2x00dev) ||
rt2800_init_registers(rt2x00dev) ||
rt2800_init_bbp(rt2x00dev) ||
rt2800_init_rfcsr(rt2x00dev)))
return -EIO;
rt2800_mcu_request(rt2x00dev, MCU_BOOT_SIGNAL, 0, 0, 0);
if (rt2x00_is_usb(rt2x00dev) &&
(rt2x00_rt(rt2x00dev, RT3070) ||
rt2x00_rt(rt2x00dev, RT3071) ||
rt2x00_rt(rt2x00dev, RT3572))) {
udelay(200);
rt2800_mcu_request(rt2x00dev, MCU_CURRENT, 0, 0, 0);
udelay(10);
}
rt2800_register_read(rt2x00dev, MAC_SYS_CTRL, &reg);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_TX, 1);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 0);
rt2800_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
udelay(50);
rt2800_register_read(rt2x00dev, WPDMA_GLO_CFG, &reg);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_ENABLE_TX_DMA, 1);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_ENABLE_RX_DMA, 1);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_WP_DMA_BURST_SIZE, 2);
rt2x00_set_field32(&reg, WPDMA_GLO_CFG_TX_WRITEBACK_DONE, 1);
rt2800_register_write(rt2x00dev, WPDMA_GLO_CFG, reg);
rt2800_register_read(rt2x00dev, MAC_SYS_CTRL, &reg);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_TX, 1);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 1);
rt2800_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
rt2x00_eeprom_read(rt2x00dev, EEPROM_LED_AG_CONF, &word);
rt2800_mcu_request(rt2x00dev, MCU_LED_AG_CONF, 0xff,
word & 0xff, (word >> 8) & 0xff);
rt2x00_eeprom_read(rt2x00dev, EEPROM_LED_ACT_CONF, &word);
rt2800_mcu_request(rt2x00dev, MCU_LED_ACT_CONF, 0xff,
word & 0xff, (word >> 8) & 0xff);
rt2x00_eeprom_read(rt2x00dev, EEPROM_LED_POLARITY, &word);
rt2800_mcu_request(rt2x00dev, MCU_LED_LED_POLARITY, 0xff,
word & 0xff, (word >> 8) & 0xff);
return 0;
}
void rt2800_disable_radio(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
rt2800_disable_wpdma(rt2x00dev);
rt2800_wait_wpdma_ready(rt2x00dev);
rt2800_register_read(rt2x00dev, MAC_SYS_CTRL, &reg);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_TX, 0);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 0);
rt2800_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
}
int rt2800_efuse_detect(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
u16 efuse_ctrl_reg;
if (rt2x00_rt(rt2x00dev, RT3290))
efuse_ctrl_reg = EFUSE_CTRL_3290;
else
efuse_ctrl_reg = EFUSE_CTRL;
rt2800_register_read(rt2x00dev, efuse_ctrl_reg, &reg);
return rt2x00_get_field32(reg, EFUSE_CTRL_PRESENT);
}
static void rt2800_efuse_read(struct rt2x00_dev *rt2x00dev, unsigned int i)
{
u32 reg;
u16 efuse_ctrl_reg;
u16 efuse_data0_reg;
u16 efuse_data1_reg;
u16 efuse_data2_reg;
u16 efuse_data3_reg;
if (rt2x00_rt(rt2x00dev, RT3290)) {
efuse_ctrl_reg = EFUSE_CTRL_3290;
efuse_data0_reg = EFUSE_DATA0_3290;
efuse_data1_reg = EFUSE_DATA1_3290;
efuse_data2_reg = EFUSE_DATA2_3290;
efuse_data3_reg = EFUSE_DATA3_3290;
} else {
efuse_ctrl_reg = EFUSE_CTRL;
efuse_data0_reg = EFUSE_DATA0;
efuse_data1_reg = EFUSE_DATA1;
efuse_data2_reg = EFUSE_DATA2;
efuse_data3_reg = EFUSE_DATA3;
}
mutex_lock(&rt2x00dev->csr_mutex);
rt2800_register_read_lock(rt2x00dev, efuse_ctrl_reg, &reg);
rt2x00_set_field32(&reg, EFUSE_CTRL_ADDRESS_IN, i);
rt2x00_set_field32(&reg, EFUSE_CTRL_MODE, 0);
rt2x00_set_field32(&reg, EFUSE_CTRL_KICK, 1);
rt2800_register_write_lock(rt2x00dev, efuse_ctrl_reg, reg);
rt2800_regbusy_read(rt2x00dev, efuse_ctrl_reg, EFUSE_CTRL_KICK, &reg);
rt2800_register_read_lock(rt2x00dev, efuse_data3_reg, &reg);
*(u32 *)&rt2x00dev->eeprom[i] = cpu_to_le32(reg);
rt2800_register_read_lock(rt2x00dev, efuse_data2_reg, &reg);
*(u32 *)&rt2x00dev->eeprom[i + 2] = cpu_to_le32(reg);
rt2800_register_read_lock(rt2x00dev, efuse_data1_reg, &reg);
*(u32 *)&rt2x00dev->eeprom[i + 4] = cpu_to_le32(reg);
rt2800_register_read_lock(rt2x00dev, efuse_data0_reg, &reg);
*(u32 *)&rt2x00dev->eeprom[i + 6] = cpu_to_le32(reg);
mutex_unlock(&rt2x00dev->csr_mutex);
}
void rt2800_read_eeprom_efuse(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
for (i = 0; i < EEPROM_SIZE / sizeof(u16); i += 8)
rt2800_efuse_read(rt2x00dev, i);
}
int rt2800_validate_eeprom(struct rt2x00_dev *rt2x00dev)
{
struct rt2800_drv_data *drv_data = rt2x00dev->drv_data;
u16 word;
u8 *mac;
u8 default_lna_gain;
mac = rt2x00_eeprom_addr(rt2x00dev, EEPROM_MAC_ADDR_0);
if (!is_valid_ether_addr(mac)) {
eth_random_addr(mac);
EEPROM(rt2x00dev, "MAC: %pM\n", mac);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF0, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_NIC_CONF0_RXPATH, 2);
rt2x00_set_field16(&word, EEPROM_NIC_CONF0_TXPATH, 1);
rt2x00_set_field16(&word, EEPROM_NIC_CONF0_RF_TYPE, RF2820);
rt2x00_eeprom_write(rt2x00dev, EEPROM_NIC_CONF0, word);
EEPROM(rt2x00dev, "Antenna: 0x%04x\n", word);
} else if (rt2x00_rt(rt2x00dev, RT2860) ||
rt2x00_rt(rt2x00dev, RT2872)) {
if (rt2x00_get_field16(word, EEPROM_NIC_CONF0_RXPATH) > 2)
rt2x00_set_field16(&word, EEPROM_NIC_CONF0_RXPATH, 2);
rt2x00_eeprom_write(rt2x00dev, EEPROM_NIC_CONF0, word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF1, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_HW_RADIO, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_EXTERNAL_TX_ALC, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_EXTERNAL_LNA_2G, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_EXTERNAL_LNA_5G, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_CARDBUS_ACCEL, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_BW40M_SB_2G, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_BW40M_SB_5G, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_WPS_PBC, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_BW40M_2G, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_BW40M_5G, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_BROADBAND_EXT_LNA, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_ANT_DIVERSITY, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_INTERNAL_TX_ALC, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_BT_COEXIST, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CONF1_DAC_TEST, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_NIC_CONF1, word);
EEPROM(rt2x00dev, "NIC: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_FREQ, &word);
if ((word & 0x00ff) == 0x00ff) {
rt2x00_set_field16(&word, EEPROM_FREQ_OFFSET, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_FREQ, word);
EEPROM(rt2x00dev, "Freq: 0x%04x\n", word);
}
if ((word & 0xff00) == 0xff00) {
rt2x00_set_field16(&word, EEPROM_FREQ_LED_MODE,
LED_MODE_TXRX_ACTIVITY);
rt2x00_set_field16(&word, EEPROM_FREQ_LED_POLARITY, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_FREQ, word);
rt2x00_eeprom_write(rt2x00dev, EEPROM_LED_AG_CONF, 0x5555);
rt2x00_eeprom_write(rt2x00dev, EEPROM_LED_ACT_CONF, 0x2221);
rt2x00_eeprom_write(rt2x00dev, EEPROM_LED_POLARITY, 0xa9f8);
EEPROM(rt2x00dev, "Led Mode: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_LNA, &word);
default_lna_gain = rt2x00_get_field16(word, EEPROM_LNA_A0);
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_BG, &word);
if (abs(rt2x00_get_field16(word, EEPROM_RSSI_BG_OFFSET0)) > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_BG_OFFSET0, 0);
if (abs(rt2x00_get_field16(word, EEPROM_RSSI_BG_OFFSET1)) > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_BG_OFFSET1, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_BG, word);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TXMIXER_GAIN_BG, &word);
if ((word & 0x00ff) != 0x00ff) {
drv_data->txmixer_gain_24g =
rt2x00_get_field16(word, EEPROM_TXMIXER_GAIN_BG_VAL);
} else {
drv_data->txmixer_gain_24g = 0;
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_BG2, &word);
if (abs(rt2x00_get_field16(word, EEPROM_RSSI_BG2_OFFSET2)) > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_BG2_OFFSET2, 0);
if (rt2x00_get_field16(word, EEPROM_RSSI_BG2_LNA_A1) == 0x00 ||
rt2x00_get_field16(word, EEPROM_RSSI_BG2_LNA_A1) == 0xff)
rt2x00_set_field16(&word, EEPROM_RSSI_BG2_LNA_A1,
default_lna_gain);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_BG2, word);
rt2x00_eeprom_read(rt2x00dev, EEPROM_TXMIXER_GAIN_A, &word);
if ((word & 0x00ff) != 0x00ff) {
drv_data->txmixer_gain_5g =
rt2x00_get_field16(word, EEPROM_TXMIXER_GAIN_A_VAL);
} else {
drv_data->txmixer_gain_5g = 0;
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_A, &word);
if (abs(rt2x00_get_field16(word, EEPROM_RSSI_A_OFFSET0)) > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_A_OFFSET0, 0);
if (abs(rt2x00_get_field16(word, EEPROM_RSSI_A_OFFSET1)) > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_A_OFFSET1, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_A, word);
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_A2, &word);
if (abs(rt2x00_get_field16(word, EEPROM_RSSI_A2_OFFSET2)) > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_A2_OFFSET2, 0);
if (rt2x00_get_field16(word, EEPROM_RSSI_A2_LNA_A2) == 0x00 ||
rt2x00_get_field16(word, EEPROM_RSSI_A2_LNA_A2) == 0xff)
rt2x00_set_field16(&word, EEPROM_RSSI_A2_LNA_A2,
default_lna_gain);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_A2, word);
return 0;
}
int rt2800_init_eeprom(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
u16 value;
u16 eeprom;
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF0, &eeprom);
if (rt2x00_rt(rt2x00dev, RT3290))
rt2800_register_read(rt2x00dev, MAC_CSR0_3290, &reg);
else
rt2800_register_read(rt2x00dev, MAC_CSR0, &reg);
if (rt2x00_get_field32(reg, MAC_CSR0_CHIPSET) == RT3290 ||
rt2x00_get_field32(reg, MAC_CSR0_CHIPSET) == RT5390 ||
rt2x00_get_field32(reg, MAC_CSR0_CHIPSET) == RT5392)
rt2x00_eeprom_read(rt2x00dev, EEPROM_CHIP_ID, &value);
else
value = rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_RF_TYPE);
rt2x00_set_chip(rt2x00dev, rt2x00_get_field32(reg, MAC_CSR0_CHIPSET),
value, rt2x00_get_field32(reg, MAC_CSR0_REVISION));
switch (rt2x00dev->chip.rt) {
case RT2860:
case RT2872:
case RT2883:
case RT3070:
case RT3071:
case RT3090:
case RT3290:
case RT3390:
case RT3572:
case RT5390:
case RT5392:
break;
default:
ERROR(rt2x00dev, "Invalid RT chipset 0x%04x detected.\n", rt2x00dev->chip.rt);
return -ENODEV;
}
switch (rt2x00dev->chip.rf) {
case RF2820:
case RF2850:
case RF2720:
case RF2750:
case RF3020:
case RF2020:
case RF3021:
case RF3022:
case RF3052:
case RF3290:
case RF3320:
case RF5360:
case RF5370:
case RF5372:
case RF5390:
case RF5392:
break;
default:
ERROR(rt2x00dev, "Invalid RF chipset 0x%04x detected.\n",
rt2x00dev->chip.rf);
return -ENODEV;
}
rt2x00dev->default_ant.tx_chain_num =
rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_TXPATH);
rt2x00dev->default_ant.rx_chain_num =
rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_RXPATH);
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF1, &eeprom);
if (rt2x00_rt(rt2x00dev, RT3070) ||
rt2x00_rt(rt2x00dev, RT3090) ||
rt2x00_rt(rt2x00dev, RT3390)) {
value = rt2x00_get_field16(eeprom,
EEPROM_NIC_CONF1_ANT_DIVERSITY);
switch (value) {
case 0:
case 1:
case 2:
rt2x00dev->default_ant.tx = ANTENNA_A;
rt2x00dev->default_ant.rx = ANTENNA_A;
break;
case 3:
rt2x00dev->default_ant.tx = ANTENNA_A;
rt2x00dev->default_ant.rx = ANTENNA_B;
break;
}
} else {
rt2x00dev->default_ant.tx = ANTENNA_A;
rt2x00dev->default_ant.rx = ANTENNA_A;
}
if (rt2x00_rt_rev_gte(rt2x00dev, RT5390, REV_RT5390R)) {
rt2x00dev->default_ant.tx = ANTENNA_HW_DIVERSITY;
rt2x00dev->default_ant.rx = ANTENNA_HW_DIVERSITY;
}
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF1_EXTERNAL_LNA_5G))
__set_bit(CAPABILITY_EXTERNAL_LNA_A, &rt2x00dev->cap_flags);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF1_EXTERNAL_LNA_2G))
__set_bit(CAPABILITY_EXTERNAL_LNA_BG, &rt2x00dev->cap_flags);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF1_HW_RADIO))
__set_bit(CAPABILITY_HW_BUTTON, &rt2x00dev->cap_flags);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF1_BT_COEXIST))
__set_bit(CAPABILITY_BT_COEXIST, &rt2x00dev->cap_flags);
rt2x00_eeprom_read(rt2x00dev, EEPROM_FREQ, &eeprom);
rt2x00dev->freq_offset = rt2x00_get_field16(eeprom, EEPROM_FREQ_OFFSET);
#ifdef CONFIG_RT2X00_LIB_LEDS
rt2800_init_led(rt2x00dev, &rt2x00dev->led_radio, LED_TYPE_RADIO);
rt2800_init_led(rt2x00dev, &rt2x00dev->led_assoc, LED_TYPE_ASSOC);
rt2800_init_led(rt2x00dev, &rt2x00dev->led_qual, LED_TYPE_QUALITY);
rt2x00dev->led_mcu_reg = eeprom;
#endif
rt2x00_eeprom_read(rt2x00dev, EEPROM_EIRP_MAX_TX_POWER, &eeprom);
if (rt2x00_get_field16(eeprom, EEPROM_EIRP_MAX_TX_POWER_2GHZ) <
EIRP_MAX_TX_POWER_LIMIT)
__set_bit(CAPABILITY_POWER_LIMIT, &rt2x00dev->cap_flags);
return 0;
}
int rt2800_probe_hw_mode(struct rt2x00_dev *rt2x00dev)
{
struct hw_mode_spec *spec = &rt2x00dev->spec;
struct channel_info *info;
char *default_power1;
char *default_power2;
unsigned int i;
u16 eeprom;
if (rt2x00_is_pci(rt2x00dev) || rt2x00_is_soc(rt2x00dev))
rt2x00dev->hw->wiphy->flags &= ~WIPHY_FLAG_PS_ON_BY_DEFAULT;
rt2x00dev->hw->flags =
IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_PS_NULLFUNC_STACK |
IEEE80211_HW_AMPDU_AGGREGATION |
IEEE80211_HW_REPORTS_TX_ACK_STATUS;
if (!rt2x00_is_usb(rt2x00dev))
rt2x00dev->hw->flags |=
IEEE80211_HW_HOST_BROADCAST_PS_BUFFERING;
SET_IEEE80211_DEV(rt2x00dev->hw, rt2x00dev->dev);
SET_IEEE80211_PERM_ADDR(rt2x00dev->hw,
rt2x00_eeprom_addr(rt2x00dev,
EEPROM_MAC_ADDR_0));
rt2x00dev->hw->max_rates = 1;
rt2x00dev->hw->max_report_rates = 7;
rt2x00dev->hw->max_rate_tries = 1;
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC_CONF0, &eeprom);
spec->supported_bands = SUPPORT_BAND_2GHZ;
spec->supported_rates = SUPPORT_RATE_CCK | SUPPORT_RATE_OFDM;
if (rt2x00_rf(rt2x00dev, RF2820) ||
rt2x00_rf(rt2x00dev, RF2720)) {
spec->num_channels = 14;
spec->channels = rf_vals;
} else if (rt2x00_rf(rt2x00dev, RF2850) ||
rt2x00_rf(rt2x00dev, RF2750)) {
spec->supported_bands |= SUPPORT_BAND_5GHZ;
spec->num_channels = ARRAY_SIZE(rf_vals);
spec->channels = rf_vals;
} else if (rt2x00_rf(rt2x00dev, RF3020) ||
rt2x00_rf(rt2x00dev, RF2020) ||
rt2x00_rf(rt2x00dev, RF3021) ||
rt2x00_rf(rt2x00dev, RF3022) ||
rt2x00_rf(rt2x00dev, RF3290) ||
rt2x00_rf(rt2x00dev, RF3320) ||
rt2x00_rf(rt2x00dev, RF5360) ||
rt2x00_rf(rt2x00dev, RF5370) ||
rt2x00_rf(rt2x00dev, RF5372) ||
rt2x00_rf(rt2x00dev, RF5390) ||
rt2x00_rf(rt2x00dev, RF5392)) {
spec->num_channels = 14;
spec->channels = rf_vals_3x;
} else if (rt2x00_rf(rt2x00dev, RF3052)) {
spec->supported_bands |= SUPPORT_BAND_5GHZ;
spec->num_channels = ARRAY_SIZE(rf_vals_3x);
spec->channels = rf_vals_3x;
}
if (!rt2x00_rf(rt2x00dev, RF2020))
spec->ht.ht_supported = true;
else
spec->ht.ht_supported = false;
spec->ht.cap =
IEEE80211_HT_CAP_SUP_WIDTH_20_40 |
IEEE80211_HT_CAP_GRN_FLD |
IEEE80211_HT_CAP_SGI_20 |
IEEE80211_HT_CAP_SGI_40;
if (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_TXPATH) >= 2)
spec->ht.cap |= IEEE80211_HT_CAP_TX_STBC;
spec->ht.cap |=
rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_RXPATH) <<
IEEE80211_HT_CAP_RX_STBC_SHIFT;
spec->ht.ampdu_factor = 3;
spec->ht.ampdu_density = 4;
spec->ht.mcs.tx_params =
IEEE80211_HT_MCS_TX_DEFINED |
IEEE80211_HT_MCS_TX_RX_DIFF |
((rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_TXPATH) - 1) <<
IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT);
switch (rt2x00_get_field16(eeprom, EEPROM_NIC_CONF0_RXPATH)) {
case 3:
spec->ht.mcs.rx_mask[2] = 0xff;
case 2:
spec->ht.mcs.rx_mask[1] = 0xff;
case 1:
spec->ht.mcs.rx_mask[0] = 0xff;
spec->ht.mcs.rx_mask[4] = 0x1;
break;
}
info = kcalloc(spec->num_channels, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
spec->channels_info = info;
default_power1 = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_BG1);
default_power2 = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_BG2);
for (i = 0; i < 14; i++) {
info[i].default_power1 = default_power1[i];
info[i].default_power2 = default_power2[i];
}
if (spec->num_channels > 14) {
default_power1 = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_A1);
default_power2 = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_A2);
for (i = 14; i < spec->num_channels; i++) {
info[i].default_power1 = default_power1[i];
info[i].default_power2 = default_power2[i];
}
}
switch (rt2x00dev->chip.rf) {
case RF2020:
case RF3020:
case RF3021:
case RF3022:
case RF3320:
case RF3052:
case RF3290:
case RF5360:
case RF5370:
case RF5372:
case RF5390:
case RF5392:
__set_bit(CAPABILITY_VCO_RECALIBRATION, &rt2x00dev->cap_flags);
break;
}
return 0;
}
void rt2800_get_tkip_seq(struct ieee80211_hw *hw, u8 hw_key_idx, u32 *iv32,
u16 *iv16)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
struct mac_iveiv_entry iveiv_entry;
u32 offset;
offset = MAC_IVEIV_ENTRY(hw_key_idx);
rt2800_register_multiread(rt2x00dev, offset,
&iveiv_entry, sizeof(iveiv_entry));
memcpy(iv16, &iveiv_entry.iv[0], sizeof(*iv16));
memcpy(iv32, &iveiv_entry.iv[4], sizeof(*iv32));
}
int rt2800_set_rts_threshold(struct ieee80211_hw *hw, u32 value)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
u32 reg;
bool enabled = (value < IEEE80211_MAX_RTS_THRESHOLD);
rt2800_register_read(rt2x00dev, TX_RTS_CFG, &reg);
rt2x00_set_field32(&reg, TX_RTS_CFG_RTS_THRES, value);
rt2800_register_write(rt2x00dev, TX_RTS_CFG, reg);
rt2800_register_read(rt2x00dev, CCK_PROT_CFG, &reg);
rt2x00_set_field32(&reg, CCK_PROT_CFG_RTS_TH_EN, enabled);
rt2800_register_write(rt2x00dev, CCK_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, OFDM_PROT_CFG, &reg);
rt2x00_set_field32(&reg, OFDM_PROT_CFG_RTS_TH_EN, enabled);
rt2800_register_write(rt2x00dev, OFDM_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, MM20_PROT_CFG, &reg);
rt2x00_set_field32(&reg, MM20_PROT_CFG_RTS_TH_EN, enabled);
rt2800_register_write(rt2x00dev, MM20_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, MM40_PROT_CFG, &reg);
rt2x00_set_field32(&reg, MM40_PROT_CFG_RTS_TH_EN, enabled);
rt2800_register_write(rt2x00dev, MM40_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, GF20_PROT_CFG, &reg);
rt2x00_set_field32(&reg, GF20_PROT_CFG_RTS_TH_EN, enabled);
rt2800_register_write(rt2x00dev, GF20_PROT_CFG, reg);
rt2800_register_read(rt2x00dev, GF40_PROT_CFG, &reg);
rt2x00_set_field32(&reg, GF40_PROT_CFG_RTS_TH_EN, enabled);
rt2800_register_write(rt2x00dev, GF40_PROT_CFG, reg);
return 0;
}
int rt2800_conf_tx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u16 queue_idx,
const struct ieee80211_tx_queue_params *params)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
struct data_queue *queue;
struct rt2x00_field32 field;
int retval;
u32 reg;
u32 offset;
retval = rt2x00mac_conf_tx(hw, vif, queue_idx, params);
if (retval)
return retval;
if (queue_idx >= 4)
return 0;
queue = rt2x00queue_get_tx_queue(rt2x00dev, queue_idx);
offset = WMM_TXOP0_CFG + (sizeof(u32) * (!!(queue_idx & 2)));
field.bit_offset = (queue_idx & 1) * 16;
field.bit_mask = 0xffff << field.bit_offset;
rt2800_register_read(rt2x00dev, offset, &reg);
rt2x00_set_field32(&reg, field, queue->txop);
rt2800_register_write(rt2x00dev, offset, reg);
field.bit_offset = queue_idx * 4;
field.bit_mask = 0xf << field.bit_offset;
rt2800_register_read(rt2x00dev, WMM_AIFSN_CFG, &reg);
rt2x00_set_field32(&reg, field, queue->aifs);
rt2800_register_write(rt2x00dev, WMM_AIFSN_CFG, reg);
rt2800_register_read(rt2x00dev, WMM_CWMIN_CFG, &reg);
rt2x00_set_field32(&reg, field, queue->cw_min);
rt2800_register_write(rt2x00dev, WMM_CWMIN_CFG, reg);
rt2800_register_read(rt2x00dev, WMM_CWMAX_CFG, &reg);
rt2x00_set_field32(&reg, field, queue->cw_max);
rt2800_register_write(rt2x00dev, WMM_CWMAX_CFG, reg);
offset = EDCA_AC0_CFG + (sizeof(u32) * queue_idx);
rt2800_register_read(rt2x00dev, offset, &reg);
rt2x00_set_field32(&reg, EDCA_AC0_CFG_TX_OP, queue->txop);
rt2x00_set_field32(&reg, EDCA_AC0_CFG_AIFSN, queue->aifs);
rt2x00_set_field32(&reg, EDCA_AC0_CFG_CWMIN, queue->cw_min);
rt2x00_set_field32(&reg, EDCA_AC0_CFG_CWMAX, queue->cw_max);
rt2800_register_write(rt2x00dev, offset, reg);
return 0;
}
u64 rt2800_get_tsf(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
u64 tsf;
u32 reg;
rt2800_register_read(rt2x00dev, TSF_TIMER_DW1, &reg);
tsf = (u64) rt2x00_get_field32(reg, TSF_TIMER_DW1_HIGH_WORD) << 32;
rt2800_register_read(rt2x00dev, TSF_TIMER_DW0, &reg);
tsf |= rt2x00_get_field32(reg, TSF_TIMER_DW0_LOW_WORD);
return tsf;
}
int rt2800_ampdu_action(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
enum ieee80211_ampdu_mlme_action action,
struct ieee80211_sta *sta, u16 tid, u16 *ssn,
u8 buf_size)
{
struct rt2x00_sta *sta_priv = (struct rt2x00_sta *)sta->drv_priv;
int ret = 0;
if (sta_priv->wcid < 0)
return 1;
switch (action) {
case IEEE80211_AMPDU_RX_START:
case IEEE80211_AMPDU_RX_STOP:
break;
case IEEE80211_AMPDU_TX_START:
ieee80211_start_tx_ba_cb_irqsafe(vif, sta->addr, tid);
break;
case IEEE80211_AMPDU_TX_STOP:
ieee80211_stop_tx_ba_cb_irqsafe(vif, sta->addr, tid);
break;
case IEEE80211_AMPDU_TX_OPERATIONAL:
break;
default:
WARNING((struct rt2x00_dev *)hw->priv, "Unknown AMPDU action\n");
}
return ret;
}
int rt2800_get_survey(struct ieee80211_hw *hw, int idx,
struct survey_info *survey)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
struct ieee80211_conf *conf = &hw->conf;
u32 idle, busy, busy_ext;
if (idx != 0)
return -ENOENT;
survey->channel = conf->channel;
rt2800_register_read(rt2x00dev, CH_IDLE_STA, &idle);
rt2800_register_read(rt2x00dev, CH_BUSY_STA, &busy);
rt2800_register_read(rt2x00dev, CH_BUSY_STA_SEC, &busy_ext);
if (idle || busy) {
survey->filled = SURVEY_INFO_CHANNEL_TIME |
SURVEY_INFO_CHANNEL_TIME_BUSY |
SURVEY_INFO_CHANNEL_TIME_EXT_BUSY;
survey->channel_time = (idle + busy) / 1000;
survey->channel_time_busy = busy / 1000;
survey->channel_time_ext_busy = busy_ext / 1000;
}
if (!(hw->conf.flags & IEEE80211_CONF_OFFCHANNEL))
survey->filled |= SURVEY_INFO_IN_USE;
return 0;
}
