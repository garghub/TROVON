static bool rt2800pci_hwcrypt_disabled(struct rt2x00_dev *rt2x00dev)
{
return modparam_nohwcrypt;
}
static void rt2800pci_mcu_status(struct rt2x00_dev *rt2x00dev, const u8 token)
{
unsigned int i;
u32 reg;
if (rt2x00_is_soc(rt2x00dev))
return;
for (i = 0; i < 200; i++) {
rt2x00pci_register_read(rt2x00dev, H2M_MAILBOX_CID, &reg);
if ((rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD0) == token) ||
(rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD1) == token) ||
(rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD2) == token) ||
(rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD3) == token))
break;
udelay(REGISTER_BUSY_DELAY);
}
if (i == 200)
ERROR(rt2x00dev, "MCU request failed, no response from hardware\n");
rt2x00pci_register_write(rt2x00dev, H2M_MAILBOX_STATUS, ~0);
rt2x00pci_register_write(rt2x00dev, H2M_MAILBOX_CID, ~0);
}
static int rt2800pci_read_eeprom_soc(struct rt2x00_dev *rt2x00dev)
{
void __iomem *base_addr = ioremap(0x1F040000, EEPROM_SIZE);
if (!base_addr)
return -ENOMEM;
memcpy_fromio(rt2x00dev->eeprom, base_addr, EEPROM_SIZE);
iounmap(base_addr);
return 0;
}
static inline int rt2800pci_read_eeprom_soc(struct rt2x00_dev *rt2x00dev)
{
return -ENOMEM;
}
static void rt2800pci_eepromregister_read(struct eeprom_93cx6 *eeprom)
{
struct rt2x00_dev *rt2x00dev = eeprom->data;
u32 reg;
rt2x00pci_register_read(rt2x00dev, E2PROM_CSR, &reg);
eeprom->reg_data_in = !!rt2x00_get_field32(reg, E2PROM_CSR_DATA_IN);
eeprom->reg_data_out = !!rt2x00_get_field32(reg, E2PROM_CSR_DATA_OUT);
eeprom->reg_data_clock =
!!rt2x00_get_field32(reg, E2PROM_CSR_DATA_CLOCK);
eeprom->reg_chip_select =
!!rt2x00_get_field32(reg, E2PROM_CSR_CHIP_SELECT);
}
static void rt2800pci_eepromregister_write(struct eeprom_93cx6 *eeprom)
{
struct rt2x00_dev *rt2x00dev = eeprom->data;
u32 reg = 0;
rt2x00_set_field32(&reg, E2PROM_CSR_DATA_IN, !!eeprom->reg_data_in);
rt2x00_set_field32(&reg, E2PROM_CSR_DATA_OUT, !!eeprom->reg_data_out);
rt2x00_set_field32(&reg, E2PROM_CSR_DATA_CLOCK,
!!eeprom->reg_data_clock);
rt2x00_set_field32(&reg, E2PROM_CSR_CHIP_SELECT,
!!eeprom->reg_chip_select);
rt2x00pci_register_write(rt2x00dev, E2PROM_CSR, reg);
}
static int rt2800pci_read_eeprom_pci(struct rt2x00_dev *rt2x00dev)
{
struct eeprom_93cx6 eeprom;
u32 reg;
rt2x00pci_register_read(rt2x00dev, E2PROM_CSR, &reg);
eeprom.data = rt2x00dev;
eeprom.register_read = rt2800pci_eepromregister_read;
eeprom.register_write = rt2800pci_eepromregister_write;
switch (rt2x00_get_field32(reg, E2PROM_CSR_TYPE))
{
case 0:
eeprom.width = PCI_EEPROM_WIDTH_93C46;
break;
case 1:
eeprom.width = PCI_EEPROM_WIDTH_93C66;
break;
default:
eeprom.width = PCI_EEPROM_WIDTH_93C86;
break;
}
eeprom.reg_data_in = 0;
eeprom.reg_data_out = 0;
eeprom.reg_data_clock = 0;
eeprom.reg_chip_select = 0;
eeprom_93cx6_multiread(&eeprom, EEPROM_BASE, rt2x00dev->eeprom,
EEPROM_SIZE / sizeof(u16));
return 0;
}
static int rt2800pci_efuse_detect(struct rt2x00_dev *rt2x00dev)
{
return rt2800_efuse_detect(rt2x00dev);
}
static inline int rt2800pci_read_eeprom_efuse(struct rt2x00_dev *rt2x00dev)
{
return rt2800_read_eeprom_efuse(rt2x00dev);
}
static inline int rt2800pci_read_eeprom_pci(struct rt2x00_dev *rt2x00dev)
{
return -EOPNOTSUPP;
}
static inline int rt2800pci_efuse_detect(struct rt2x00_dev *rt2x00dev)
{
return 0;
}
static inline int rt2800pci_read_eeprom_efuse(struct rt2x00_dev *rt2x00dev)
{
return -EOPNOTSUPP;
}
static void rt2800pci_start_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_RX:
rt2x00pci_register_read(rt2x00dev, MAC_SYS_CTRL, &reg);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 1);
rt2x00pci_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
break;
case QID_BEACON:
rt2x00pci_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_TICKING, 1);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TBTT_ENABLE, 1);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 1);
rt2x00pci_register_write(rt2x00dev, BCN_TIME_CFG, reg);
rt2x00pci_register_read(rt2x00dev, INT_TIMER_EN, &reg);
rt2x00_set_field32(&reg, INT_TIMER_EN_PRE_TBTT_TIMER, 1);
rt2x00pci_register_write(rt2x00dev, INT_TIMER_EN, reg);
break;
default:
break;
}
}
static void rt2800pci_kick_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
struct queue_entry *entry;
switch (queue->qid) {
case QID_AC_VO:
case QID_AC_VI:
case QID_AC_BE:
case QID_AC_BK:
entry = rt2x00queue_get_entry(queue, Q_INDEX);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX(queue->qid),
entry->entry_idx);
break;
case QID_MGMT:
entry = rt2x00queue_get_entry(queue, Q_INDEX);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX(5),
entry->entry_idx);
break;
default:
break;
}
}
static void rt2800pci_stop_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_RX:
rt2x00pci_register_read(rt2x00dev, MAC_SYS_CTRL, &reg);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 0);
rt2x00pci_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
break;
case QID_BEACON:
rt2x00pci_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_TICKING, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_TBTT_ENABLE, 0);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 0);
rt2x00pci_register_write(rt2x00dev, BCN_TIME_CFG, reg);
rt2x00pci_register_read(rt2x00dev, INT_TIMER_EN, &reg);
rt2x00_set_field32(&reg, INT_TIMER_EN_PRE_TBTT_TIMER, 0);
rt2x00pci_register_write(rt2x00dev, INT_TIMER_EN, reg);
tasklet_kill(&rt2x00dev->tbtt_tasklet);
tasklet_kill(&rt2x00dev->pretbtt_tasklet);
break;
default:
break;
}
}
static char *rt2800pci_get_firmware_name(struct rt2x00_dev *rt2x00dev)
{
if (rt2x00_rt(rt2x00dev, RT3290))
return FIRMWARE_RT3290;
else
return FIRMWARE_RT2860;
}
static int rt2800pci_write_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
u32 reg;
reg = 0;
rt2x00_set_field32(&reg, PBF_SYS_CTRL_HOST_RAM_WRITE, 1);
rt2x00pci_register_write(rt2x00dev, PBF_SYS_CTRL, reg);
rt2x00pci_register_multiwrite(rt2x00dev, FIRMWARE_IMAGE_BASE,
data, len);
rt2x00pci_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00000);
rt2x00pci_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00001);
rt2x00pci_register_write(rt2x00dev, H2M_BBP_AGENT, 0);
rt2x00pci_register_write(rt2x00dev, H2M_MAILBOX_CSR, 0);
return 0;
}
static bool rt2800pci_get_entry_state(struct queue_entry *entry)
{
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
u32 word;
if (entry->queue->qid == QID_RX) {
rt2x00_desc_read(entry_priv->desc, 1, &word);
return (!rt2x00_get_field32(word, RXD_W1_DMA_DONE));
} else {
rt2x00_desc_read(entry_priv->desc, 1, &word);
return (!rt2x00_get_field32(word, TXD_W1_DMA_DONE));
}
}
static void rt2800pci_clear_entry(struct queue_entry *entry)
{
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
u32 word;
if (entry->queue->qid == QID_RX) {
rt2x00_desc_read(entry_priv->desc, 0, &word);
rt2x00_set_field32(&word, RXD_W0_SDP0, skbdesc->skb_dma);
rt2x00_desc_write(entry_priv->desc, 0, word);
rt2x00_desc_read(entry_priv->desc, 1, &word);
rt2x00_set_field32(&word, RXD_W1_DMA_DONE, 0);
rt2x00_desc_write(entry_priv->desc, 1, word);
rt2x00pci_register_write(rt2x00dev, RX_CRX_IDX,
entry->entry_idx);
} else {
rt2x00_desc_read(entry_priv->desc, 1, &word);
rt2x00_set_field32(&word, TXD_W1_DMA_DONE, 1);
rt2x00_desc_write(entry_priv->desc, 1, word);
}
}
static int rt2800pci_init_queues(struct rt2x00_dev *rt2x00dev)
{
struct queue_entry_priv_pci *entry_priv;
entry_priv = rt2x00dev->tx[0].entries[0].priv_data;
rt2x00pci_register_write(rt2x00dev, TX_BASE_PTR0, entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TX_MAX_CNT0,
rt2x00dev->tx[0].limit);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX0, 0);
rt2x00pci_register_write(rt2x00dev, TX_DTX_IDX0, 0);
entry_priv = rt2x00dev->tx[1].entries[0].priv_data;
rt2x00pci_register_write(rt2x00dev, TX_BASE_PTR1, entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TX_MAX_CNT1,
rt2x00dev->tx[1].limit);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX1, 0);
rt2x00pci_register_write(rt2x00dev, TX_DTX_IDX1, 0);
entry_priv = rt2x00dev->tx[2].entries[0].priv_data;
rt2x00pci_register_write(rt2x00dev, TX_BASE_PTR2, entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TX_MAX_CNT2,
rt2x00dev->tx[2].limit);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX2, 0);
rt2x00pci_register_write(rt2x00dev, TX_DTX_IDX2, 0);
entry_priv = rt2x00dev->tx[3].entries[0].priv_data;
rt2x00pci_register_write(rt2x00dev, TX_BASE_PTR3, entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TX_MAX_CNT3,
rt2x00dev->tx[3].limit);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX3, 0);
rt2x00pci_register_write(rt2x00dev, TX_DTX_IDX3, 0);
rt2x00pci_register_write(rt2x00dev, TX_BASE_PTR4, 0);
rt2x00pci_register_write(rt2x00dev, TX_MAX_CNT4, 0);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX4, 0);
rt2x00pci_register_write(rt2x00dev, TX_DTX_IDX4, 0);
rt2x00pci_register_write(rt2x00dev, TX_BASE_PTR5, 0);
rt2x00pci_register_write(rt2x00dev, TX_MAX_CNT5, 0);
rt2x00pci_register_write(rt2x00dev, TX_CTX_IDX5, 0);
rt2x00pci_register_write(rt2x00dev, TX_DTX_IDX5, 0);
entry_priv = rt2x00dev->rx->entries[0].priv_data;
rt2x00pci_register_write(rt2x00dev, RX_BASE_PTR, entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, RX_MAX_CNT,
rt2x00dev->rx[0].limit);
rt2x00pci_register_write(rt2x00dev, RX_CRX_IDX,
rt2x00dev->rx[0].limit - 1);
rt2x00pci_register_write(rt2x00dev, RX_DRX_IDX, 0);
rt2800_disable_wpdma(rt2x00dev);
rt2x00pci_register_write(rt2x00dev, DELAY_INT_CFG, 0);
return 0;
}
static void rt2800pci_toggle_irq(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
u32 reg;
unsigned long flags;
if (state == STATE_RADIO_IRQ_ON) {
rt2x00pci_register_read(rt2x00dev, INT_SOURCE_CSR, &reg);
rt2x00pci_register_write(rt2x00dev, INT_SOURCE_CSR, reg);
}
spin_lock_irqsave(&rt2x00dev->irqmask_lock, flags);
reg = 0;
if (state == STATE_RADIO_IRQ_ON) {
rt2x00_set_field32(&reg, INT_MASK_CSR_RX_DONE, 1);
rt2x00_set_field32(&reg, INT_MASK_CSR_TBTT, 1);
rt2x00_set_field32(&reg, INT_MASK_CSR_PRE_TBTT, 1);
rt2x00_set_field32(&reg, INT_MASK_CSR_TX_FIFO_STATUS, 1);
rt2x00_set_field32(&reg, INT_MASK_CSR_AUTO_WAKEUP, 1);
}
rt2x00pci_register_write(rt2x00dev, INT_MASK_CSR, reg);
spin_unlock_irqrestore(&rt2x00dev->irqmask_lock, flags);
if (state == STATE_RADIO_IRQ_OFF) {
tasklet_kill(&rt2x00dev->txstatus_tasklet);
tasklet_kill(&rt2x00dev->rxdone_tasklet);
tasklet_kill(&rt2x00dev->autowake_tasklet);
tasklet_kill(&rt2x00dev->tbtt_tasklet);
tasklet_kill(&rt2x00dev->pretbtt_tasklet);
}
}
static int rt2800pci_init_registers(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
rt2x00pci_register_read(rt2x00dev, WPDMA_RST_IDX, &reg);
rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX0, 1);
rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX1, 1);
rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX2, 1);
rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX3, 1);
rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX4, 1);
rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX5, 1);
rt2x00_set_field32(&reg, WPDMA_RST_IDX_DRX_IDX0, 1);
rt2x00pci_register_write(rt2x00dev, WPDMA_RST_IDX, reg);
rt2x00pci_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00000e1f);
rt2x00pci_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00000e00);
if (rt2x00_is_pcie(rt2x00dev) &&
(rt2x00_rt(rt2x00dev, RT3572) ||
rt2x00_rt(rt2x00dev, RT5390) ||
rt2x00_rt(rt2x00dev, RT5392))) {
rt2x00pci_register_read(rt2x00dev, AUX_CTRL, &reg);
rt2x00_set_field32(&reg, AUX_CTRL_FORCE_PCIE_CLK, 1);
rt2x00_set_field32(&reg, AUX_CTRL_WAKE_PCIE_EN, 1);
rt2x00pci_register_write(rt2x00dev, AUX_CTRL, reg);
}
rt2x00pci_register_write(rt2x00dev, PWR_PIN_CFG, 0x00000003);
reg = 0;
rt2x00_set_field32(&reg, MAC_SYS_CTRL_RESET_CSR, 1);
rt2x00_set_field32(&reg, MAC_SYS_CTRL_RESET_BBP, 1);
rt2x00pci_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
rt2x00pci_register_write(rt2x00dev, MAC_SYS_CTRL, 0x00000000);
return 0;
}
static int rt2800pci_enable_radio(struct rt2x00_dev *rt2x00dev)
{
int retval;
rt2800_wait_wpdma_ready(rt2x00dev);
if (unlikely(rt2800pci_init_queues(rt2x00dev)))
return -EIO;
retval = rt2800_enable_radio(rt2x00dev);
if (retval)
return retval;
rt2x00pci_register_write(rt2x00dev, H2M_MAILBOX_STATUS, ~0);
rt2x00pci_register_write(rt2x00dev, H2M_MAILBOX_CID, ~0);
rt2800_mcu_request(rt2x00dev, MCU_SLEEP, TOKEN_RADIO_OFF, 0xff, 0x02);
rt2800pci_mcu_status(rt2x00dev, TOKEN_RADIO_OFF);
rt2800_mcu_request(rt2x00dev, MCU_WAKEUP, TOKEN_WAKEUP, 0, 0);
rt2800pci_mcu_status(rt2x00dev, TOKEN_WAKEUP);
return retval;
}
static void rt2800pci_disable_radio(struct rt2x00_dev *rt2x00dev)
{
if (rt2x00_is_soc(rt2x00dev)) {
rt2800_disable_radio(rt2x00dev);
rt2x00pci_register_write(rt2x00dev, PWR_PIN_CFG, 0);
rt2x00pci_register_write(rt2x00dev, TX_PIN_CFG, 0);
}
}
static int rt2800pci_set_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
if (state == STATE_AWAKE) {
rt2800_mcu_request(rt2x00dev, MCU_WAKEUP, TOKEN_WAKEUP,
0, 0x02);
rt2800pci_mcu_status(rt2x00dev, TOKEN_WAKEUP);
} else if (state == STATE_SLEEP) {
rt2x00pci_register_write(rt2x00dev, H2M_MAILBOX_STATUS,
0xffffffff);
rt2x00pci_register_write(rt2x00dev, H2M_MAILBOX_CID,
0xffffffff);
rt2800_mcu_request(rt2x00dev, MCU_SLEEP, TOKEN_SLEEP,
0xff, 0x01);
}
return 0;
}
static int rt2800pci_set_device_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int retval = 0;
switch (state) {
case STATE_RADIO_ON:
retval = rt2800pci_enable_radio(rt2x00dev);
break;
case STATE_RADIO_OFF:
rt2800pci_disable_radio(rt2x00dev);
rt2800pci_set_state(rt2x00dev, STATE_SLEEP);
break;
case STATE_RADIO_IRQ_ON:
case STATE_RADIO_IRQ_OFF:
rt2800pci_toggle_irq(rt2x00dev, state);
break;
case STATE_DEEP_SLEEP:
case STATE_SLEEP:
case STATE_STANDBY:
case STATE_AWAKE:
retval = rt2800pci_set_state(rt2x00dev, state);
break;
default:
retval = -ENOTSUPP;
break;
}
if (unlikely(retval))
ERROR(rt2x00dev, "Device failed to enter state %d (%d).\n",
state, retval);
return retval;
}
static __le32 *rt2800pci_get_txwi(struct queue_entry *entry)
{
return (__le32 *) entry->skb->data;
}
static void rt2800pci_write_tx_desc(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
__le32 *txd = entry_priv->desc;
u32 word;
word = 0;
rt2x00_set_field32(&word, TXD_W0_SD_PTR0, skbdesc->skb_dma);
rt2x00_desc_write(txd, 0, word);
word = 0;
rt2x00_set_field32(&word, TXD_W1_SD_LEN1, entry->skb->len);
rt2x00_set_field32(&word, TXD_W1_LAST_SEC1,
!test_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W1_BURST,
test_bit(ENTRY_TXD_BURST, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W1_SD_LEN0, TXWI_DESC_SIZE);
rt2x00_set_field32(&word, TXD_W1_LAST_SEC0, 0);
rt2x00_set_field32(&word, TXD_W1_DMA_DONE, 0);
rt2x00_desc_write(txd, 1, word);
word = 0;
rt2x00_set_field32(&word, TXD_W2_SD_PTR1,
skbdesc->skb_dma + TXWI_DESC_SIZE);
rt2x00_desc_write(txd, 2, word);
word = 0;
rt2x00_set_field32(&word, TXD_W3_WIV,
!test_bit(ENTRY_TXD_ENCRYPT_IV, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W3_QSEL, 2);
rt2x00_desc_write(txd, 3, word);
skbdesc->desc = txd;
skbdesc->desc_len = TXD_DESC_SIZE;
}
static void rt2800pci_fill_rxdone(struct queue_entry *entry,
struct rxdone_entry_desc *rxdesc)
{
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
__le32 *rxd = entry_priv->desc;
u32 word;
rt2x00_desc_read(rxd, 3, &word);
if (rt2x00_get_field32(word, RXD_W3_CRC_ERROR))
rxdesc->flags |= RX_FLAG_FAILED_FCS_CRC;
rxdesc->cipher_status = rt2x00_get_field32(word, RXD_W3_CIPHER_ERROR);
if (rt2x00_get_field32(word, RXD_W3_DECRYPTED)) {
rxdesc->flags |= RX_FLAG_IV_STRIPPED;
rxdesc->flags |= RX_FLAG_MMIC_STRIPPED;
if (rxdesc->cipher_status == RX_CRYPTO_SUCCESS)
rxdesc->flags |= RX_FLAG_DECRYPTED;
else if (rxdesc->cipher_status == RX_CRYPTO_FAIL_MIC)
rxdesc->flags |= RX_FLAG_MMIC_ERROR;
}
if (rt2x00_get_field32(word, RXD_W3_MY_BSS))
rxdesc->dev_flags |= RXDONE_MY_BSS;
if (rt2x00_get_field32(word, RXD_W3_L2PAD))
rxdesc->dev_flags |= RXDONE_L2PAD;
rt2800_process_rxwi(entry, rxdesc);
}
static void rt2800pci_wakeup(struct rt2x00_dev *rt2x00dev)
{
struct ieee80211_conf conf = { .flags = 0 };
struct rt2x00lib_conf libconf = { .conf = &conf };
rt2800_config(rt2x00dev, &libconf, IEEE80211_CONF_CHANGE_PS);
}
static bool rt2800pci_txdone(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
struct queue_entry *entry;
u32 status;
u8 qid;
int max_tx_done = 16;
while (kfifo_get(&rt2x00dev->txstatus_fifo, &status)) {
qid = rt2x00_get_field32(status, TX_STA_FIFO_PID_QUEUE);
if (unlikely(qid >= QID_RX)) {
WARNING(rt2x00dev, "Got TX status report with "
"unexpected pid %u, dropping\n", qid);
break;
}
queue = rt2x00queue_get_tx_queue(rt2x00dev, qid);
if (unlikely(queue == NULL)) {
WARNING(rt2x00dev, "Got TX status for an unavailable "
"queue %u, dropping\n", qid);
break;
}
if (unlikely(rt2x00queue_empty(queue))) {
WARNING(rt2x00dev, "Got TX status for an empty "
"queue %u, dropping\n", qid);
break;
}
entry = rt2x00queue_get_entry(queue, Q_INDEX_DONE);
rt2800_txdone_entry(entry, status, rt2800pci_get_txwi(entry));
if (--max_tx_done == 0)
break;
}
return !max_tx_done;
}
static inline void rt2800pci_enable_interrupt(struct rt2x00_dev *rt2x00dev,
struct rt2x00_field32 irq_field)
{
u32 reg;
spin_lock_irq(&rt2x00dev->irqmask_lock);
rt2x00pci_register_read(rt2x00dev, INT_MASK_CSR, &reg);
rt2x00_set_field32(&reg, irq_field, 1);
rt2x00pci_register_write(rt2x00dev, INT_MASK_CSR, reg);
spin_unlock_irq(&rt2x00dev->irqmask_lock);
}
static void rt2800pci_txstatus_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
if (rt2800pci_txdone(rt2x00dev))
tasklet_schedule(&rt2x00dev->txstatus_tasklet);
}
static void rt2800pci_pretbtt_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
rt2x00lib_pretbtt(rt2x00dev);
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2800pci_enable_interrupt(rt2x00dev, INT_MASK_CSR_PRE_TBTT);
}
static void rt2800pci_tbtt_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
struct rt2800_drv_data *drv_data = rt2x00dev->drv_data;
u32 reg;
rt2x00lib_beacondone(rt2x00dev);
if (rt2x00dev->intf_ap_count) {
if (drv_data->tbtt_tick == (BCN_TBTT_OFFSET - 2)) {
rt2x00pci_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_INTERVAL,
(rt2x00dev->beacon_int * 16) - 1);
rt2x00pci_register_write(rt2x00dev, BCN_TIME_CFG, reg);
} else if (drv_data->tbtt_tick == (BCN_TBTT_OFFSET - 1)) {
rt2x00pci_register_read(rt2x00dev, BCN_TIME_CFG, &reg);
rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_INTERVAL,
(rt2x00dev->beacon_int * 16));
rt2x00pci_register_write(rt2x00dev, BCN_TIME_CFG, reg);
}
drv_data->tbtt_tick++;
drv_data->tbtt_tick %= BCN_TBTT_OFFSET;
}
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2800pci_enable_interrupt(rt2x00dev, INT_MASK_CSR_TBTT);
}
static void rt2800pci_rxdone_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
if (rt2x00pci_rxdone(rt2x00dev))
tasklet_schedule(&rt2x00dev->rxdone_tasklet);
else if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2800pci_enable_interrupt(rt2x00dev, INT_MASK_CSR_RX_DONE);
}
static void rt2800pci_autowake_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
rt2800pci_wakeup(rt2x00dev);
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2800pci_enable_interrupt(rt2x00dev, INT_MASK_CSR_AUTO_WAKEUP);
}
static void rt2800pci_txstatus_interrupt(struct rt2x00_dev *rt2x00dev)
{
u32 status;
int i;
for (i = 0; i < rt2x00dev->ops->tx->entry_num; i++) {
rt2x00pci_register_read(rt2x00dev, TX_STA_FIFO, &status);
if (!rt2x00_get_field32(status, TX_STA_FIFO_VALID))
break;
if (!kfifo_put(&rt2x00dev->txstatus_fifo, &status)) {
WARNING(rt2x00dev, "TX status FIFO overrun,"
"drop tx status report.\n");
break;
}
}
tasklet_schedule(&rt2x00dev->txstatus_tasklet);
}
static irqreturn_t rt2800pci_interrupt(int irq, void *dev_instance)
{
struct rt2x00_dev *rt2x00dev = dev_instance;
u32 reg, mask;
rt2x00pci_register_read(rt2x00dev, INT_SOURCE_CSR, &reg);
rt2x00pci_register_write(rt2x00dev, INT_SOURCE_CSR, reg);
if (!reg)
return IRQ_NONE;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return IRQ_HANDLED;
mask = ~reg;
if (rt2x00_get_field32(reg, INT_SOURCE_CSR_TX_FIFO_STATUS)) {
rt2800pci_txstatus_interrupt(rt2x00dev);
rt2x00_set_field32(&mask, INT_MASK_CSR_TX_FIFO_STATUS, 1);
}
if (rt2x00_get_field32(reg, INT_SOURCE_CSR_PRE_TBTT))
tasklet_hi_schedule(&rt2x00dev->pretbtt_tasklet);
if (rt2x00_get_field32(reg, INT_SOURCE_CSR_TBTT))
tasklet_hi_schedule(&rt2x00dev->tbtt_tasklet);
if (rt2x00_get_field32(reg, INT_SOURCE_CSR_RX_DONE))
tasklet_schedule(&rt2x00dev->rxdone_tasklet);
if (rt2x00_get_field32(reg, INT_SOURCE_CSR_AUTO_WAKEUP))
tasklet_schedule(&rt2x00dev->autowake_tasklet);
spin_lock(&rt2x00dev->irqmask_lock);
rt2x00pci_register_read(rt2x00dev, INT_MASK_CSR, &reg);
reg &= mask;
rt2x00pci_register_write(rt2x00dev, INT_MASK_CSR, reg);
spin_unlock(&rt2x00dev->irqmask_lock);
return IRQ_HANDLED;
}
static int rt2800pci_read_eeprom(struct rt2x00_dev *rt2x00dev)
{
int retval;
if (rt2x00_is_soc(rt2x00dev))
retval = rt2800pci_read_eeprom_soc(rt2x00dev);
else if (rt2800pci_efuse_detect(rt2x00dev))
retval = rt2800pci_read_eeprom_efuse(rt2x00dev);
else
retval = rt2800pci_read_eeprom_pci(rt2x00dev);
return retval;
}
static int rt2800soc_probe(struct platform_device *pdev)
{
return rt2x00soc_probe(pdev, &rt2800pci_ops);
}
static int rt2800pci_probe(struct pci_dev *pci_dev,
const struct pci_device_id *id)
{
return rt2x00pci_probe(pci_dev, &rt2800pci_ops);
}
static int __init rt2800pci_init(void)
{
int ret = 0;
#if defined(CONFIG_SOC_RT288X) || defined(CONFIG_SOC_RT305X)
ret = platform_driver_register(&rt2800soc_driver);
if (ret)
return ret;
#endif
#ifdef CONFIG_PCI
ret = pci_register_driver(&rt2800pci_driver);
if (ret) {
#if defined(CONFIG_SOC_RT288X) || defined(CONFIG_SOC_RT305X)
platform_driver_unregister(&rt2800soc_driver);
#endif
return ret;
}
#endif
return ret;
}
static void __exit rt2800pci_exit(void)
{
#ifdef CONFIG_PCI
pci_unregister_driver(&rt2800pci_driver);
#endif
#if defined(CONFIG_SOC_RT288X) || defined(CONFIG_SOC_RT305X)
platform_driver_unregister(&rt2800soc_driver);
#endif
}
