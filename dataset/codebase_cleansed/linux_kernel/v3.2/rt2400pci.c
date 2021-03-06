static void rt2400pci_bbp_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u8 value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, BBPCSR_VALUE, value);
rt2x00_set_field32(&reg, BBPCSR_REGNUM, word);
rt2x00_set_field32(&reg, BBPCSR_BUSY, 1);
rt2x00_set_field32(&reg, BBPCSR_WRITE_CONTROL, 1);
rt2x00pci_register_write(rt2x00dev, BBPCSR, reg);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2400pci_bbp_read(struct rt2x00_dev *rt2x00dev,
const unsigned int word, u8 *value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, BBPCSR_REGNUM, word);
rt2x00_set_field32(&reg, BBPCSR_BUSY, 1);
rt2x00_set_field32(&reg, BBPCSR_WRITE_CONTROL, 0);
rt2x00pci_register_write(rt2x00dev, BBPCSR, reg);
WAIT_FOR_BBP(rt2x00dev, &reg);
}
*value = rt2x00_get_field32(reg, BBPCSR_VALUE);
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2400pci_rf_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u32 value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_RF(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, RFCSR_VALUE, value);
rt2x00_set_field32(&reg, RFCSR_NUMBER_OF_BITS, 20);
rt2x00_set_field32(&reg, RFCSR_IF_SELECT, 0);
rt2x00_set_field32(&reg, RFCSR_BUSY, 1);
rt2x00pci_register_write(rt2x00dev, RFCSR, reg);
rt2x00_rf_write(rt2x00dev, word, value);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2400pci_eepromregister_read(struct eeprom_93cx6 *eeprom)
{
struct rt2x00_dev *rt2x00dev = eeprom->data;
u32 reg;
rt2x00pci_register_read(rt2x00dev, CSR21, &reg);
eeprom->reg_data_in = !!rt2x00_get_field32(reg, CSR21_EEPROM_DATA_IN);
eeprom->reg_data_out = !!rt2x00_get_field32(reg, CSR21_EEPROM_DATA_OUT);
eeprom->reg_data_clock =
!!rt2x00_get_field32(reg, CSR21_EEPROM_DATA_CLOCK);
eeprom->reg_chip_select =
!!rt2x00_get_field32(reg, CSR21_EEPROM_CHIP_SELECT);
}
static void rt2400pci_eepromregister_write(struct eeprom_93cx6 *eeprom)
{
struct rt2x00_dev *rt2x00dev = eeprom->data;
u32 reg = 0;
rt2x00_set_field32(&reg, CSR21_EEPROM_DATA_IN, !!eeprom->reg_data_in);
rt2x00_set_field32(&reg, CSR21_EEPROM_DATA_OUT, !!eeprom->reg_data_out);
rt2x00_set_field32(&reg, CSR21_EEPROM_DATA_CLOCK,
!!eeprom->reg_data_clock);
rt2x00_set_field32(&reg, CSR21_EEPROM_CHIP_SELECT,
!!eeprom->reg_chip_select);
rt2x00pci_register_write(rt2x00dev, CSR21, reg);
}
static int rt2400pci_rfkill_poll(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
rt2x00pci_register_read(rt2x00dev, GPIOCSR, &reg);
return rt2x00_get_field32(reg, GPIOCSR_BIT0);
}
static void rt2400pci_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct rt2x00_led *led =
container_of(led_cdev, struct rt2x00_led, led_dev);
unsigned int enabled = brightness != LED_OFF;
u32 reg;
rt2x00pci_register_read(led->rt2x00dev, LEDCSR, &reg);
if (led->type == LED_TYPE_RADIO || led->type == LED_TYPE_ASSOC)
rt2x00_set_field32(&reg, LEDCSR_LINK, enabled);
else if (led->type == LED_TYPE_ACTIVITY)
rt2x00_set_field32(&reg, LEDCSR_ACTIVITY, enabled);
rt2x00pci_register_write(led->rt2x00dev, LEDCSR, reg);
}
static int rt2400pci_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct rt2x00_led *led =
container_of(led_cdev, struct rt2x00_led, led_dev);
u32 reg;
rt2x00pci_register_read(led->rt2x00dev, LEDCSR, &reg);
rt2x00_set_field32(&reg, LEDCSR_ON_PERIOD, *delay_on);
rt2x00_set_field32(&reg, LEDCSR_OFF_PERIOD, *delay_off);
rt2x00pci_register_write(led->rt2x00dev, LEDCSR, reg);
return 0;
}
static void rt2400pci_init_led(struct rt2x00_dev *rt2x00dev,
struct rt2x00_led *led,
enum led_type type)
{
led->rt2x00dev = rt2x00dev;
led->type = type;
led->led_dev.brightness_set = rt2400pci_brightness_set;
led->led_dev.blink_set = rt2400pci_blink_set;
led->flags = LED_INITIALIZED;
}
static void rt2400pci_config_filter(struct rt2x00_dev *rt2x00dev,
const unsigned int filter_flags)
{
u32 reg;
rt2x00pci_register_read(rt2x00dev, RXCSR0, &reg);
rt2x00_set_field32(&reg, RXCSR0_DROP_CRC,
!(filter_flags & FIF_FCSFAIL));
rt2x00_set_field32(&reg, RXCSR0_DROP_PHYSICAL,
!(filter_flags & FIF_PLCPFAIL));
rt2x00_set_field32(&reg, RXCSR0_DROP_CONTROL,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field32(&reg, RXCSR0_DROP_NOT_TO_ME,
!(filter_flags & FIF_PROMISC_IN_BSS));
rt2x00_set_field32(&reg, RXCSR0_DROP_TODS,
!(filter_flags & FIF_PROMISC_IN_BSS) &&
!rt2x00dev->intf_ap_count);
rt2x00_set_field32(&reg, RXCSR0_DROP_VERSION_ERROR, 1);
rt2x00pci_register_write(rt2x00dev, RXCSR0, reg);
}
static void rt2400pci_config_intf(struct rt2x00_dev *rt2x00dev,
struct rt2x00_intf *intf,
struct rt2x00intf_conf *conf,
const unsigned int flags)
{
unsigned int bcn_preload;
u32 reg;
if (flags & CONFIG_UPDATE_TYPE) {
bcn_preload = PREAMBLE + GET_DURATION(IEEE80211_HEADER, 20);
rt2x00pci_register_read(rt2x00dev, BCNCSR1, &reg);
rt2x00_set_field32(&reg, BCNCSR1_PRELOAD, bcn_preload);
rt2x00pci_register_write(rt2x00dev, BCNCSR1, reg);
rt2x00pci_register_read(rt2x00dev, CSR14, &reg);
rt2x00_set_field32(&reg, CSR14_TSF_SYNC, conf->sync);
rt2x00pci_register_write(rt2x00dev, CSR14, reg);
}
if (flags & CONFIG_UPDATE_MAC)
rt2x00pci_register_multiwrite(rt2x00dev, CSR3,
conf->mac, sizeof(conf->mac));
if (flags & CONFIG_UPDATE_BSSID)
rt2x00pci_register_multiwrite(rt2x00dev, CSR5,
conf->bssid, sizeof(conf->bssid));
}
static void rt2400pci_config_erp(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_erp *erp,
u32 changed)
{
int preamble_mask;
u32 reg;
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
preamble_mask = erp->short_preamble << 3;
rt2x00pci_register_read(rt2x00dev, TXCSR1, &reg);
rt2x00_set_field32(&reg, TXCSR1_ACK_TIMEOUT, 0x1ff);
rt2x00_set_field32(&reg, TXCSR1_ACK_CONSUME_TIME, 0x13a);
rt2x00_set_field32(&reg, TXCSR1_TSF_OFFSET, IEEE80211_HEADER);
rt2x00_set_field32(&reg, TXCSR1_AUTORESPONDER, 1);
rt2x00pci_register_write(rt2x00dev, TXCSR1, reg);
rt2x00pci_register_read(rt2x00dev, ARCSR2, &reg);
rt2x00_set_field32(&reg, ARCSR2_SIGNAL, 0x00);
rt2x00_set_field32(&reg, ARCSR2_SERVICE, 0x04);
rt2x00_set_field32(&reg, ARCSR2_LENGTH,
GET_DURATION(ACK_SIZE, 10));
rt2x00pci_register_write(rt2x00dev, ARCSR2, reg);
rt2x00pci_register_read(rt2x00dev, ARCSR3, &reg);
rt2x00_set_field32(&reg, ARCSR3_SIGNAL, 0x01 | preamble_mask);
rt2x00_set_field32(&reg, ARCSR3_SERVICE, 0x04);
rt2x00_set_field32(&reg, ARCSR2_LENGTH,
GET_DURATION(ACK_SIZE, 20));
rt2x00pci_register_write(rt2x00dev, ARCSR3, reg);
rt2x00pci_register_read(rt2x00dev, ARCSR4, &reg);
rt2x00_set_field32(&reg, ARCSR4_SIGNAL, 0x02 | preamble_mask);
rt2x00_set_field32(&reg, ARCSR4_SERVICE, 0x04);
rt2x00_set_field32(&reg, ARCSR2_LENGTH,
GET_DURATION(ACK_SIZE, 55));
rt2x00pci_register_write(rt2x00dev, ARCSR4, reg);
rt2x00pci_register_read(rt2x00dev, ARCSR5, &reg);
rt2x00_set_field32(&reg, ARCSR5_SIGNAL, 0x03 | preamble_mask);
rt2x00_set_field32(&reg, ARCSR5_SERVICE, 0x84);
rt2x00_set_field32(&reg, ARCSR2_LENGTH,
GET_DURATION(ACK_SIZE, 110));
rt2x00pci_register_write(rt2x00dev, ARCSR5, reg);
}
if (changed & BSS_CHANGED_BASIC_RATES)
rt2x00pci_register_write(rt2x00dev, ARCSR1, erp->basic_rates);
if (changed & BSS_CHANGED_ERP_SLOT) {
rt2x00pci_register_read(rt2x00dev, CSR11, &reg);
rt2x00_set_field32(&reg, CSR11_SLOT_TIME, erp->slot_time);
rt2x00pci_register_write(rt2x00dev, CSR11, reg);
rt2x00pci_register_read(rt2x00dev, CSR18, &reg);
rt2x00_set_field32(&reg, CSR18_SIFS, erp->sifs);
rt2x00_set_field32(&reg, CSR18_PIFS, erp->pifs);
rt2x00pci_register_write(rt2x00dev, CSR18, reg);
rt2x00pci_register_read(rt2x00dev, CSR19, &reg);
rt2x00_set_field32(&reg, CSR19_DIFS, erp->difs);
rt2x00_set_field32(&reg, CSR19_EIFS, erp->eifs);
rt2x00pci_register_write(rt2x00dev, CSR19, reg);
}
if (changed & BSS_CHANGED_BEACON_INT) {
rt2x00pci_register_read(rt2x00dev, CSR12, &reg);
rt2x00_set_field32(&reg, CSR12_BEACON_INTERVAL,
erp->beacon_int * 16);
rt2x00_set_field32(&reg, CSR12_CFP_MAX_DURATION,
erp->beacon_int * 16);
rt2x00pci_register_write(rt2x00dev, CSR12, reg);
}
}
static void rt2400pci_config_ant(struct rt2x00_dev *rt2x00dev,
struct antenna_setup *ant)
{
u8 r1;
u8 r4;
BUG_ON(ant->rx == ANTENNA_SW_DIVERSITY ||
ant->tx == ANTENNA_SW_DIVERSITY);
rt2400pci_bbp_read(rt2x00dev, 4, &r4);
rt2400pci_bbp_read(rt2x00dev, 1, &r1);
switch (ant->tx) {
case ANTENNA_HW_DIVERSITY:
rt2x00_set_field8(&r1, BBP_R1_TX_ANTENNA, 1);
break;
case ANTENNA_A:
rt2x00_set_field8(&r1, BBP_R1_TX_ANTENNA, 0);
break;
case ANTENNA_B:
default:
rt2x00_set_field8(&r1, BBP_R1_TX_ANTENNA, 2);
break;
}
switch (ant->rx) {
case ANTENNA_HW_DIVERSITY:
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA, 1);
break;
case ANTENNA_A:
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA, 0);
break;
case ANTENNA_B:
default:
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA, 2);
break;
}
rt2400pci_bbp_write(rt2x00dev, 4, r4);
rt2400pci_bbp_write(rt2x00dev, 1, r1);
}
static void rt2400pci_config_channel(struct rt2x00_dev *rt2x00dev,
struct rf_channel *rf)
{
rt2x00_set_field32(&rf->rf1, RF1_TUNER, 1);
rt2x00_set_field32(&rf->rf3, RF3_TUNER, 1);
rt2400pci_rf_write(rt2x00dev, 1, rf->rf1);
rt2400pci_rf_write(rt2x00dev, 2, rf->rf2);
rt2400pci_rf_write(rt2x00dev, 3, rf->rf3);
if (rt2x00_rf(rt2x00dev, RF2420))
return;
rt2400pci_rf_write(rt2x00dev, 1, rf->rf1);
rt2400pci_rf_write(rt2x00dev, 2, 0x000c2a32);
rt2400pci_rf_write(rt2x00dev, 3, rf->rf3);
msleep(1);
rt2400pci_rf_write(rt2x00dev, 1, rf->rf1);
rt2400pci_rf_write(rt2x00dev, 2, rf->rf2);
rt2400pci_rf_write(rt2x00dev, 3, rf->rf3);
msleep(1);
rt2x00_set_field32(&rf->rf1, RF1_TUNER, 0);
rt2x00_set_field32(&rf->rf3, RF3_TUNER, 0);
rt2400pci_rf_write(rt2x00dev, 1, rf->rf1);
rt2400pci_rf_write(rt2x00dev, 3, rf->rf3);
rt2x00pci_register_read(rt2x00dev, CNT0, &rf->rf1);
}
static void rt2400pci_config_txpower(struct rt2x00_dev *rt2x00dev, int txpower)
{
rt2400pci_bbp_write(rt2x00dev, 3, TXPOWER_TO_DEV(txpower));
}
static void rt2400pci_config_retry_limit(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
u32 reg;
rt2x00pci_register_read(rt2x00dev, CSR11, &reg);
rt2x00_set_field32(&reg, CSR11_LONG_RETRY,
libconf->conf->long_frame_max_tx_count);
rt2x00_set_field32(&reg, CSR11_SHORT_RETRY,
libconf->conf->short_frame_max_tx_count);
rt2x00pci_register_write(rt2x00dev, CSR11, reg);
}
static void rt2400pci_config_ps(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
enum dev_state state =
(libconf->conf->flags & IEEE80211_CONF_PS) ?
STATE_SLEEP : STATE_AWAKE;
u32 reg;
if (state == STATE_SLEEP) {
rt2x00pci_register_read(rt2x00dev, CSR20, &reg);
rt2x00_set_field32(&reg, CSR20_DELAY_AFTER_TBCN,
(rt2x00dev->beacon_int - 20) * 16);
rt2x00_set_field32(&reg, CSR20_TBCN_BEFORE_WAKEUP,
libconf->conf->listen_interval - 1);
rt2x00_set_field32(&reg, CSR20_AUTOWAKE, 0);
rt2x00pci_register_write(rt2x00dev, CSR20, reg);
rt2x00_set_field32(&reg, CSR20_AUTOWAKE, 1);
rt2x00pci_register_write(rt2x00dev, CSR20, reg);
} else {
rt2x00pci_register_read(rt2x00dev, CSR20, &reg);
rt2x00_set_field32(&reg, CSR20_AUTOWAKE, 0);
rt2x00pci_register_write(rt2x00dev, CSR20, reg);
}
rt2x00dev->ops->lib->set_device_state(rt2x00dev, state);
}
static void rt2400pci_config(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf,
const unsigned int flags)
{
if (flags & IEEE80211_CONF_CHANGE_CHANNEL)
rt2400pci_config_channel(rt2x00dev, &libconf->rf);
if (flags & IEEE80211_CONF_CHANGE_POWER)
rt2400pci_config_txpower(rt2x00dev,
libconf->conf->power_level);
if (flags & IEEE80211_CONF_CHANGE_RETRY_LIMITS)
rt2400pci_config_retry_limit(rt2x00dev, libconf);
if (flags & IEEE80211_CONF_CHANGE_PS)
rt2400pci_config_ps(rt2x00dev, libconf);
}
static void rt2400pci_config_cw(struct rt2x00_dev *rt2x00dev,
const int cw_min, const int cw_max)
{
u32 reg;
rt2x00pci_register_read(rt2x00dev, CSR11, &reg);
rt2x00_set_field32(&reg, CSR11_CWMIN, cw_min);
rt2x00_set_field32(&reg, CSR11_CWMAX, cw_max);
rt2x00pci_register_write(rt2x00dev, CSR11, reg);
}
static void rt2400pci_link_stats(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual)
{
u32 reg;
u8 bbp;
rt2x00pci_register_read(rt2x00dev, CNT0, &reg);
qual->rx_failed = rt2x00_get_field32(reg, CNT0_FCS_ERROR);
rt2400pci_bbp_read(rt2x00dev, 39, &bbp);
qual->false_cca = bbp;
}
static inline void rt2400pci_set_vgc(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual, u8 vgc_level)
{
if (qual->vgc_level_reg != vgc_level) {
rt2400pci_bbp_write(rt2x00dev, 13, vgc_level);
qual->vgc_level = vgc_level;
qual->vgc_level_reg = vgc_level;
}
}
static void rt2400pci_reset_tuner(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual)
{
rt2400pci_set_vgc(rt2x00dev, qual, 0x08);
}
static void rt2400pci_link_tuner(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual, const u32 count)
{
if (count > 60 || !(count & 1))
return;
if ((qual->false_cca > 512) && (qual->vgc_level < 0x20))
rt2400pci_set_vgc(rt2x00dev, qual, ++qual->vgc_level);
else if ((qual->false_cca < 100) && (qual->vgc_level > 0x08))
rt2400pci_set_vgc(rt2x00dev, qual, --qual->vgc_level);
}
static void rt2400pci_start_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_RX:
rt2x00pci_register_read(rt2x00dev, RXCSR0, &reg);
rt2x00_set_field32(&reg, RXCSR0_DISABLE_RX, 0);
rt2x00pci_register_write(rt2x00dev, RXCSR0, reg);
break;
case QID_BEACON:
rt2x00pci_register_read(rt2x00dev, CSR14, &reg);
rt2x00_set_field32(&reg, CSR14_TSF_COUNT, 1);
rt2x00_set_field32(&reg, CSR14_TBCN, 1);
rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 1);
rt2x00pci_register_write(rt2x00dev, CSR14, reg);
break;
default:
break;
}
}
static void rt2400pci_kick_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_AC_VO:
rt2x00pci_register_read(rt2x00dev, TXCSR0, &reg);
rt2x00_set_field32(&reg, TXCSR0_KICK_PRIO, 1);
rt2x00pci_register_write(rt2x00dev, TXCSR0, reg);
break;
case QID_AC_VI:
rt2x00pci_register_read(rt2x00dev, TXCSR0, &reg);
rt2x00_set_field32(&reg, TXCSR0_KICK_TX, 1);
rt2x00pci_register_write(rt2x00dev, TXCSR0, reg);
break;
case QID_ATIM:
rt2x00pci_register_read(rt2x00dev, TXCSR0, &reg);
rt2x00_set_field32(&reg, TXCSR0_KICK_ATIM, 1);
rt2x00pci_register_write(rt2x00dev, TXCSR0, reg);
break;
default:
break;
}
}
static void rt2400pci_stop_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_AC_VO:
case QID_AC_VI:
case QID_ATIM:
rt2x00pci_register_read(rt2x00dev, TXCSR0, &reg);
rt2x00_set_field32(&reg, TXCSR0_ABORT, 1);
rt2x00pci_register_write(rt2x00dev, TXCSR0, reg);
break;
case QID_RX:
rt2x00pci_register_read(rt2x00dev, RXCSR0, &reg);
rt2x00_set_field32(&reg, RXCSR0_DISABLE_RX, 1);
rt2x00pci_register_write(rt2x00dev, RXCSR0, reg);
break;
case QID_BEACON:
rt2x00pci_register_read(rt2x00dev, CSR14, &reg);
rt2x00_set_field32(&reg, CSR14_TSF_COUNT, 0);
rt2x00_set_field32(&reg, CSR14_TBCN, 0);
rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 0);
rt2x00pci_register_write(rt2x00dev, CSR14, reg);
tasklet_kill(&rt2x00dev->tbtt_tasklet);
break;
default:
break;
}
}
static bool rt2400pci_get_entry_state(struct queue_entry *entry)
{
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
u32 word;
if (entry->queue->qid == QID_RX) {
rt2x00_desc_read(entry_priv->desc, 0, &word);
return rt2x00_get_field32(word, RXD_W0_OWNER_NIC);
} else {
rt2x00_desc_read(entry_priv->desc, 0, &word);
return (rt2x00_get_field32(word, TXD_W0_OWNER_NIC) ||
rt2x00_get_field32(word, TXD_W0_VALID));
}
}
static void rt2400pci_clear_entry(struct queue_entry *entry)
{
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
u32 word;
if (entry->queue->qid == QID_RX) {
rt2x00_desc_read(entry_priv->desc, 2, &word);
rt2x00_set_field32(&word, RXD_W2_BUFFER_LENGTH, entry->skb->len);
rt2x00_desc_write(entry_priv->desc, 2, word);
rt2x00_desc_read(entry_priv->desc, 1, &word);
rt2x00_set_field32(&word, RXD_W1_BUFFER_ADDRESS, skbdesc->skb_dma);
rt2x00_desc_write(entry_priv->desc, 1, word);
rt2x00_desc_read(entry_priv->desc, 0, &word);
rt2x00_set_field32(&word, RXD_W0_OWNER_NIC, 1);
rt2x00_desc_write(entry_priv->desc, 0, word);
} else {
rt2x00_desc_read(entry_priv->desc, 0, &word);
rt2x00_set_field32(&word, TXD_W0_VALID, 0);
rt2x00_set_field32(&word, TXD_W0_OWNER_NIC, 0);
rt2x00_desc_write(entry_priv->desc, 0, word);
}
}
static int rt2400pci_init_queues(struct rt2x00_dev *rt2x00dev)
{
struct queue_entry_priv_pci *entry_priv;
u32 reg;
rt2x00pci_register_read(rt2x00dev, TXCSR2, &reg);
rt2x00_set_field32(&reg, TXCSR2_TXD_SIZE, rt2x00dev->tx[0].desc_size);
rt2x00_set_field32(&reg, TXCSR2_NUM_TXD, rt2x00dev->tx[1].limit);
rt2x00_set_field32(&reg, TXCSR2_NUM_ATIM, rt2x00dev->atim->limit);
rt2x00_set_field32(&reg, TXCSR2_NUM_PRIO, rt2x00dev->tx[0].limit);
rt2x00pci_register_write(rt2x00dev, TXCSR2, reg);
entry_priv = rt2x00dev->tx[1].entries[0].priv_data;
rt2x00pci_register_read(rt2x00dev, TXCSR3, &reg);
rt2x00_set_field32(&reg, TXCSR3_TX_RING_REGISTER,
entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TXCSR3, reg);
entry_priv = rt2x00dev->tx[0].entries[0].priv_data;
rt2x00pci_register_read(rt2x00dev, TXCSR5, &reg);
rt2x00_set_field32(&reg, TXCSR5_PRIO_RING_REGISTER,
entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TXCSR5, reg);
entry_priv = rt2x00dev->atim->entries[0].priv_data;
rt2x00pci_register_read(rt2x00dev, TXCSR4, &reg);
rt2x00_set_field32(&reg, TXCSR4_ATIM_RING_REGISTER,
entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TXCSR4, reg);
entry_priv = rt2x00dev->bcn->entries[0].priv_data;
rt2x00pci_register_read(rt2x00dev, TXCSR6, &reg);
rt2x00_set_field32(&reg, TXCSR6_BEACON_RING_REGISTER,
entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, TXCSR6, reg);
rt2x00pci_register_read(rt2x00dev, RXCSR1, &reg);
rt2x00_set_field32(&reg, RXCSR1_RXD_SIZE, rt2x00dev->rx->desc_size);
rt2x00_set_field32(&reg, RXCSR1_NUM_RXD, rt2x00dev->rx->limit);
rt2x00pci_register_write(rt2x00dev, RXCSR1, reg);
entry_priv = rt2x00dev->rx->entries[0].priv_data;
rt2x00pci_register_read(rt2x00dev, RXCSR2, &reg);
rt2x00_set_field32(&reg, RXCSR2_RX_RING_REGISTER,
entry_priv->desc_dma);
rt2x00pci_register_write(rt2x00dev, RXCSR2, reg);
return 0;
}
static int rt2400pci_init_registers(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
rt2x00pci_register_write(rt2x00dev, PSCSR0, 0x00020002);
rt2x00pci_register_write(rt2x00dev, PSCSR1, 0x00000002);
rt2x00pci_register_write(rt2x00dev, PSCSR2, 0x00023f20);
rt2x00pci_register_write(rt2x00dev, PSCSR3, 0x00000002);
rt2x00pci_register_read(rt2x00dev, TIMECSR, &reg);
rt2x00_set_field32(&reg, TIMECSR_US_COUNT, 33);
rt2x00_set_field32(&reg, TIMECSR_US_64_COUNT, 63);
rt2x00_set_field32(&reg, TIMECSR_BEACON_EXPECT, 0);
rt2x00pci_register_write(rt2x00dev, TIMECSR, reg);
rt2x00pci_register_read(rt2x00dev, CSR9, &reg);
rt2x00_set_field32(&reg, CSR9_MAX_FRAME_UNIT,
(rt2x00dev->rx->data_size / 128));
rt2x00pci_register_write(rt2x00dev, CSR9, reg);
rt2x00pci_register_read(rt2x00dev, CSR14, &reg);
rt2x00_set_field32(&reg, CSR14_TSF_COUNT, 0);
rt2x00_set_field32(&reg, CSR14_TSF_SYNC, 0);
rt2x00_set_field32(&reg, CSR14_TBCN, 0);
rt2x00_set_field32(&reg, CSR14_TCFP, 0);
rt2x00_set_field32(&reg, CSR14_TATIMW, 0);
rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 0);
rt2x00_set_field32(&reg, CSR14_CFP_COUNT_PRELOAD, 0);
rt2x00_set_field32(&reg, CSR14_TBCM_PRELOAD, 0);
rt2x00pci_register_write(rt2x00dev, CSR14, reg);
rt2x00pci_register_write(rt2x00dev, CNT3, 0x3f080000);
rt2x00pci_register_read(rt2x00dev, ARCSR0, &reg);
rt2x00_set_field32(&reg, ARCSR0_AR_BBP_DATA0, 133);
rt2x00_set_field32(&reg, ARCSR0_AR_BBP_ID0, 134);
rt2x00_set_field32(&reg, ARCSR0_AR_BBP_DATA1, 136);
rt2x00_set_field32(&reg, ARCSR0_AR_BBP_ID1, 135);
rt2x00pci_register_write(rt2x00dev, ARCSR0, reg);
rt2x00pci_register_read(rt2x00dev, RXCSR3, &reg);
rt2x00_set_field32(&reg, RXCSR3_BBP_ID0, 3);
rt2x00_set_field32(&reg, RXCSR3_BBP_ID0_VALID, 1);
rt2x00_set_field32(&reg, RXCSR3_BBP_ID1, 32);
rt2x00_set_field32(&reg, RXCSR3_BBP_ID1_VALID, 1);
rt2x00_set_field32(&reg, RXCSR3_BBP_ID2, 36);
rt2x00_set_field32(&reg, RXCSR3_BBP_ID2_VALID, 1);
rt2x00pci_register_write(rt2x00dev, RXCSR3, reg);
rt2x00pci_register_write(rt2x00dev, PWRCSR0, 0x3f3b3100);
if (rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_AWAKE))
return -EBUSY;
rt2x00pci_register_write(rt2x00dev, MACCSR0, 0x00217223);
rt2x00pci_register_write(rt2x00dev, MACCSR1, 0x00235518);
rt2x00pci_register_read(rt2x00dev, MACCSR2, &reg);
rt2x00_set_field32(&reg, MACCSR2_DELAY, 64);
rt2x00pci_register_write(rt2x00dev, MACCSR2, reg);
rt2x00pci_register_read(rt2x00dev, RALINKCSR, &reg);
rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_DATA0, 17);
rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_ID0, 154);
rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_DATA1, 0);
rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_ID1, 154);
rt2x00pci_register_write(rt2x00dev, RALINKCSR, reg);
rt2x00pci_register_read(rt2x00dev, CSR1, &reg);
rt2x00_set_field32(&reg, CSR1_SOFT_RESET, 1);
rt2x00_set_field32(&reg, CSR1_BBP_RESET, 0);
rt2x00_set_field32(&reg, CSR1_HOST_READY, 0);
rt2x00pci_register_write(rt2x00dev, CSR1, reg);
rt2x00pci_register_read(rt2x00dev, CSR1, &reg);
rt2x00_set_field32(&reg, CSR1_SOFT_RESET, 0);
rt2x00_set_field32(&reg, CSR1_HOST_READY, 1);
rt2x00pci_register_write(rt2x00dev, CSR1, reg);
rt2x00pci_register_read(rt2x00dev, CNT0, &reg);
rt2x00pci_register_read(rt2x00dev, CNT4, &reg);
return 0;
}
static int rt2400pci_wait_bbp_ready(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u8 value;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2400pci_bbp_read(rt2x00dev, 0, &value);
if ((value != 0xff) && (value != 0x00))
return 0;
udelay(REGISTER_BUSY_DELAY);
}
ERROR(rt2x00dev, "BBP register access failed, aborting.\n");
return -EACCES;
}
static int rt2400pci_init_bbp(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u16 eeprom;
u8 reg_id;
u8 value;
if (unlikely(rt2400pci_wait_bbp_ready(rt2x00dev)))
return -EACCES;
rt2400pci_bbp_write(rt2x00dev, 1, 0x00);
rt2400pci_bbp_write(rt2x00dev, 3, 0x27);
rt2400pci_bbp_write(rt2x00dev, 4, 0x08);
rt2400pci_bbp_write(rt2x00dev, 10, 0x0f);
rt2400pci_bbp_write(rt2x00dev, 15, 0x72);
rt2400pci_bbp_write(rt2x00dev, 16, 0x74);
rt2400pci_bbp_write(rt2x00dev, 17, 0x20);
rt2400pci_bbp_write(rt2x00dev, 18, 0x72);
rt2400pci_bbp_write(rt2x00dev, 19, 0x0b);
rt2400pci_bbp_write(rt2x00dev, 20, 0x00);
rt2400pci_bbp_write(rt2x00dev, 28, 0x11);
rt2400pci_bbp_write(rt2x00dev, 29, 0x04);
rt2400pci_bbp_write(rt2x00dev, 30, 0x21);
rt2400pci_bbp_write(rt2x00dev, 31, 0x00);
for (i = 0; i < EEPROM_BBP_SIZE; i++) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBP_START + i, &eeprom);
if (eeprom != 0xffff && eeprom != 0x0000) {
reg_id = rt2x00_get_field16(eeprom, EEPROM_BBP_REG_ID);
value = rt2x00_get_field16(eeprom, EEPROM_BBP_VALUE);
rt2400pci_bbp_write(rt2x00dev, reg_id, value);
}
}
return 0;
}
static void rt2400pci_toggle_irq(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int mask = (state == STATE_RADIO_IRQ_OFF);
u32 reg;
unsigned long flags;
if (state == STATE_RADIO_IRQ_ON) {
rt2x00pci_register_read(rt2x00dev, CSR7, &reg);
rt2x00pci_register_write(rt2x00dev, CSR7, reg);
}
spin_lock_irqsave(&rt2x00dev->irqmask_lock, flags);
rt2x00pci_register_read(rt2x00dev, CSR8, &reg);
rt2x00_set_field32(&reg, CSR8_TBCN_EXPIRE, mask);
rt2x00_set_field32(&reg, CSR8_TXDONE_TXRING, mask);
rt2x00_set_field32(&reg, CSR8_TXDONE_ATIMRING, mask);
rt2x00_set_field32(&reg, CSR8_TXDONE_PRIORING, mask);
rt2x00_set_field32(&reg, CSR8_RXDONE, mask);
rt2x00pci_register_write(rt2x00dev, CSR8, reg);
spin_unlock_irqrestore(&rt2x00dev->irqmask_lock, flags);
if (state == STATE_RADIO_IRQ_OFF) {
tasklet_kill(&rt2x00dev->txstatus_tasklet);
tasklet_kill(&rt2x00dev->rxdone_tasklet);
tasklet_kill(&rt2x00dev->tbtt_tasklet);
}
}
static int rt2400pci_enable_radio(struct rt2x00_dev *rt2x00dev)
{
if (unlikely(rt2400pci_init_queues(rt2x00dev) ||
rt2400pci_init_registers(rt2x00dev) ||
rt2400pci_init_bbp(rt2x00dev)))
return -EIO;
return 0;
}
static void rt2400pci_disable_radio(struct rt2x00_dev *rt2x00dev)
{
rt2x00pci_register_write(rt2x00dev, PWRCSR0, 0);
}
static int rt2400pci_set_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
u32 reg, reg2;
unsigned int i;
char put_to_sleep;
char bbp_state;
char rf_state;
put_to_sleep = (state != STATE_AWAKE);
rt2x00pci_register_read(rt2x00dev, PWRCSR1, &reg);
rt2x00_set_field32(&reg, PWRCSR1_SET_STATE, 1);
rt2x00_set_field32(&reg, PWRCSR1_BBP_DESIRE_STATE, state);
rt2x00_set_field32(&reg, PWRCSR1_RF_DESIRE_STATE, state);
rt2x00_set_field32(&reg, PWRCSR1_PUT_TO_SLEEP, put_to_sleep);
rt2x00pci_register_write(rt2x00dev, PWRCSR1, reg);
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2x00pci_register_read(rt2x00dev, PWRCSR1, &reg2);
bbp_state = rt2x00_get_field32(reg2, PWRCSR1_BBP_CURR_STATE);
rf_state = rt2x00_get_field32(reg2, PWRCSR1_RF_CURR_STATE);
if (bbp_state == state && rf_state == state)
return 0;
rt2x00pci_register_write(rt2x00dev, PWRCSR1, reg);
msleep(10);
}
return -EBUSY;
}
static int rt2400pci_set_device_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int retval = 0;
switch (state) {
case STATE_RADIO_ON:
retval = rt2400pci_enable_radio(rt2x00dev);
break;
case STATE_RADIO_OFF:
rt2400pci_disable_radio(rt2x00dev);
break;
case STATE_RADIO_IRQ_ON:
case STATE_RADIO_IRQ_OFF:
rt2400pci_toggle_irq(rt2x00dev, state);
break;
case STATE_DEEP_SLEEP:
case STATE_SLEEP:
case STATE_STANDBY:
case STATE_AWAKE:
retval = rt2400pci_set_state(rt2x00dev, state);
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
static void rt2400pci_write_tx_desc(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
__le32 *txd = entry_priv->desc;
u32 word;
rt2x00_desc_read(txd, 1, &word);
rt2x00_set_field32(&word, TXD_W1_BUFFER_ADDRESS, skbdesc->skb_dma);
rt2x00_desc_write(txd, 1, word);
rt2x00_desc_read(txd, 2, &word);
rt2x00_set_field32(&word, TXD_W2_BUFFER_LENGTH, txdesc->length);
rt2x00_set_field32(&word, TXD_W2_DATABYTE_COUNT, txdesc->length);
rt2x00_desc_write(txd, 2, word);
rt2x00_desc_read(txd, 3, &word);
rt2x00_set_field32(&word, TXD_W3_PLCP_SIGNAL, txdesc->u.plcp.signal);
rt2x00_set_field32(&word, TXD_W3_PLCP_SIGNAL_REGNUM, 5);
rt2x00_set_field32(&word, TXD_W3_PLCP_SIGNAL_BUSY, 1);
rt2x00_set_field32(&word, TXD_W3_PLCP_SERVICE, txdesc->u.plcp.service);
rt2x00_set_field32(&word, TXD_W3_PLCP_SERVICE_REGNUM, 6);
rt2x00_set_field32(&word, TXD_W3_PLCP_SERVICE_BUSY, 1);
rt2x00_desc_write(txd, 3, word);
rt2x00_desc_read(txd, 4, &word);
rt2x00_set_field32(&word, TXD_W4_PLCP_LENGTH_LOW,
txdesc->u.plcp.length_low);
rt2x00_set_field32(&word, TXD_W3_PLCP_LENGTH_LOW_REGNUM, 8);
rt2x00_set_field32(&word, TXD_W3_PLCP_LENGTH_LOW_BUSY, 1);
rt2x00_set_field32(&word, TXD_W4_PLCP_LENGTH_HIGH,
txdesc->u.plcp.length_high);
rt2x00_set_field32(&word, TXD_W3_PLCP_LENGTH_HIGH_REGNUM, 7);
rt2x00_set_field32(&word, TXD_W3_PLCP_LENGTH_HIGH_BUSY, 1);
rt2x00_desc_write(txd, 4, word);
rt2x00_desc_read(txd, 0, &word);
rt2x00_set_field32(&word, TXD_W0_OWNER_NIC, 1);
rt2x00_set_field32(&word, TXD_W0_VALID, 1);
rt2x00_set_field32(&word, TXD_W0_MORE_FRAG,
test_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_ACK,
test_bit(ENTRY_TXD_ACK, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_TIMESTAMP,
test_bit(ENTRY_TXD_REQ_TIMESTAMP, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_RTS,
test_bit(ENTRY_TXD_RTS_FRAME, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_IFS, txdesc->u.plcp.ifs);
rt2x00_set_field32(&word, TXD_W0_RETRY_MODE,
test_bit(ENTRY_TXD_RETRY_MODE, &txdesc->flags));
rt2x00_desc_write(txd, 0, word);
skbdesc->desc = txd;
skbdesc->desc_len = TXD_DESC_SIZE;
}
static void rt2400pci_write_beacon(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
u32 reg;
rt2x00pci_register_read(rt2x00dev, CSR14, &reg);
rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 0);
rt2x00pci_register_write(rt2x00dev, CSR14, reg);
rt2x00queue_map_txskb(entry);
rt2400pci_write_tx_desc(entry, txdesc);
rt2x00debug_dump_frame(rt2x00dev, DUMP_FRAME_BEACON, entry->skb);
rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 1);
rt2x00pci_register_write(rt2x00dev, CSR14, reg);
}
static void rt2400pci_fill_rxdone(struct queue_entry *entry,
struct rxdone_entry_desc *rxdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct queue_entry_priv_pci *entry_priv = entry->priv_data;
u32 word0;
u32 word2;
u32 word3;
u32 word4;
u64 tsf;
u32 rx_low;
u32 rx_high;
rt2x00_desc_read(entry_priv->desc, 0, &word0);
rt2x00_desc_read(entry_priv->desc, 2, &word2);
rt2x00_desc_read(entry_priv->desc, 3, &word3);
rt2x00_desc_read(entry_priv->desc, 4, &word4);
if (rt2x00_get_field32(word0, RXD_W0_CRC_ERROR))
rxdesc->flags |= RX_FLAG_FAILED_FCS_CRC;
if (rt2x00_get_field32(word0, RXD_W0_PHYSICAL_ERROR))
rxdesc->flags |= RX_FLAG_FAILED_PLCP_CRC;
tsf = rt2x00dev->ops->hw->get_tsf(rt2x00dev->hw, NULL);
rx_low = rt2x00_get_field32(word4, RXD_W4_RX_END_TIME);
rx_high = upper_32_bits(tsf);
if ((u32)tsf <= rx_low)
rx_high--;
rxdesc->timestamp = ((u64)rx_high << 32) | rx_low;
rxdesc->signal = rt2x00_get_field32(word2, RXD_W2_SIGNAL) & ~0x08;
rxdesc->rssi = rt2x00_get_field32(word2, RXD_W3_RSSI) -
entry->queue->rt2x00dev->rssi_offset;
rxdesc->size = rt2x00_get_field32(word0, RXD_W0_DATABYTE_COUNT);
rxdesc->dev_flags |= RXDONE_SIGNAL_PLCP;
if (rt2x00_get_field32(word0, RXD_W0_MY_BSS))
rxdesc->dev_flags |= RXDONE_MY_BSS;
}
static void rt2400pci_txdone(struct rt2x00_dev *rt2x00dev,
const enum data_queue_qid queue_idx)
{
struct data_queue *queue = rt2x00queue_get_tx_queue(rt2x00dev, queue_idx);
struct queue_entry_priv_pci *entry_priv;
struct queue_entry *entry;
struct txdone_entry_desc txdesc;
u32 word;
while (!rt2x00queue_empty(queue)) {
entry = rt2x00queue_get_entry(queue, Q_INDEX_DONE);
entry_priv = entry->priv_data;
rt2x00_desc_read(entry_priv->desc, 0, &word);
if (rt2x00_get_field32(word, TXD_W0_OWNER_NIC) ||
!rt2x00_get_field32(word, TXD_W0_VALID))
break;
txdesc.flags = 0;
switch (rt2x00_get_field32(word, TXD_W0_RESULT)) {
case 0:
case 1:
__set_bit(TXDONE_SUCCESS, &txdesc.flags);
break;
case 2:
__set_bit(TXDONE_EXCESSIVE_RETRY, &txdesc.flags);
default:
__set_bit(TXDONE_FAILURE, &txdesc.flags);
}
txdesc.retry = rt2x00_get_field32(word, TXD_W0_RETRY_COUNT);
rt2x00lib_txdone(entry, &txdesc);
}
}
static inline void rt2400pci_enable_interrupt(struct rt2x00_dev *rt2x00dev,
struct rt2x00_field32 irq_field)
{
u32 reg;
spin_lock_irq(&rt2x00dev->irqmask_lock);
rt2x00pci_register_read(rt2x00dev, CSR8, &reg);
rt2x00_set_field32(&reg, irq_field, 0);
rt2x00pci_register_write(rt2x00dev, CSR8, reg);
spin_unlock_irq(&rt2x00dev->irqmask_lock);
}
static void rt2400pci_txstatus_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
u32 reg;
rt2400pci_txdone(rt2x00dev, QID_ATIM);
rt2400pci_txdone(rt2x00dev, QID_AC_VO);
rt2400pci_txdone(rt2x00dev, QID_AC_VI);
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags)) {
spin_lock_irq(&rt2x00dev->irqmask_lock);
rt2x00pci_register_read(rt2x00dev, CSR8, &reg);
rt2x00_set_field32(&reg, CSR8_TXDONE_TXRING, 0);
rt2x00_set_field32(&reg, CSR8_TXDONE_ATIMRING, 0);
rt2x00_set_field32(&reg, CSR8_TXDONE_PRIORING, 0);
rt2x00pci_register_write(rt2x00dev, CSR8, reg);
spin_unlock_irq(&rt2x00dev->irqmask_lock);
}
}
static void rt2400pci_tbtt_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
rt2x00lib_beacondone(rt2x00dev);
if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2400pci_enable_interrupt(rt2x00dev, CSR8_TBCN_EXPIRE);
}
static void rt2400pci_rxdone_tasklet(unsigned long data)
{
struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
if (rt2x00pci_rxdone(rt2x00dev))
tasklet_schedule(&rt2x00dev->rxdone_tasklet);
else if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
rt2400pci_enable_interrupt(rt2x00dev, CSR8_RXDONE);
}
static irqreturn_t rt2400pci_interrupt(int irq, void *dev_instance)
{
struct rt2x00_dev *rt2x00dev = dev_instance;
u32 reg, mask;
rt2x00pci_register_read(rt2x00dev, CSR7, &reg);
rt2x00pci_register_write(rt2x00dev, CSR7, reg);
if (!reg)
return IRQ_NONE;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
return IRQ_HANDLED;
mask = reg;
if (rt2x00_get_field32(reg, CSR7_TBCN_EXPIRE))
tasklet_hi_schedule(&rt2x00dev->tbtt_tasklet);
if (rt2x00_get_field32(reg, CSR7_RXDONE))
tasklet_schedule(&rt2x00dev->rxdone_tasklet);
if (rt2x00_get_field32(reg, CSR7_TXDONE_ATIMRING) ||
rt2x00_get_field32(reg, CSR7_TXDONE_PRIORING) ||
rt2x00_get_field32(reg, CSR7_TXDONE_TXRING)) {
tasklet_schedule(&rt2x00dev->txstatus_tasklet);
rt2x00_set_field32(&mask, CSR8_TXDONE_TXRING, 1);
rt2x00_set_field32(&mask, CSR8_TXDONE_ATIMRING, 1);
rt2x00_set_field32(&mask, CSR8_TXDONE_PRIORING, 1);
}
spin_lock(&rt2x00dev->irqmask_lock);
rt2x00pci_register_read(rt2x00dev, CSR8, &reg);
reg |= mask;
rt2x00pci_register_write(rt2x00dev, CSR8, reg);
spin_unlock(&rt2x00dev->irqmask_lock);
return IRQ_HANDLED;
}
static int rt2400pci_validate_eeprom(struct rt2x00_dev *rt2x00dev)
{
struct eeprom_93cx6 eeprom;
u32 reg;
u16 word;
u8 *mac;
rt2x00pci_register_read(rt2x00dev, CSR21, &reg);
eeprom.data = rt2x00dev;
eeprom.register_read = rt2400pci_eepromregister_read;
eeprom.register_write = rt2400pci_eepromregister_write;
eeprom.width = rt2x00_get_field32(reg, CSR21_TYPE_93C46) ?
PCI_EEPROM_WIDTH_93C46 : PCI_EEPROM_WIDTH_93C66;
eeprom.reg_data_in = 0;
eeprom.reg_data_out = 0;
eeprom.reg_data_clock = 0;
eeprom.reg_chip_select = 0;
eeprom_93cx6_multiread(&eeprom, EEPROM_BASE, rt2x00dev->eeprom,
EEPROM_SIZE / sizeof(u16));
mac = rt2x00_eeprom_addr(rt2x00dev, EEPROM_MAC_ADDR_0);
if (!is_valid_ether_addr(mac)) {
random_ether_addr(mac);
EEPROM(rt2x00dev, "MAC: %pM\n", mac);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA, &word);
if (word == 0xffff) {
ERROR(rt2x00dev, "Invalid EEPROM data detected.\n");
return -EINVAL;
}
return 0;
}
static int rt2400pci_init_eeprom(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
u16 value;
u16 eeprom;
rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA, &eeprom);
value = rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RF_TYPE);
rt2x00pci_register_read(rt2x00dev, CSR0, &reg);
rt2x00_set_chip(rt2x00dev, RT2460, value,
rt2x00_get_field32(reg, CSR0_REVISION));
if (!rt2x00_rf(rt2x00dev, RF2420) && !rt2x00_rf(rt2x00dev, RF2421)) {
ERROR(rt2x00dev, "Invalid RF chipset detected.\n");
return -ENODEV;
}
rt2x00dev->default_ant.tx =
rt2x00_get_field16(eeprom, EEPROM_ANTENNA_TX_DEFAULT);
rt2x00dev->default_ant.rx =
rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RX_DEFAULT);
if (rt2x00dev->default_ant.tx == ANTENNA_SW_DIVERSITY)
rt2x00dev->default_ant.tx = ANTENNA_HW_DIVERSITY;
if (rt2x00dev->default_ant.rx == ANTENNA_SW_DIVERSITY)
rt2x00dev->default_ant.rx = ANTENNA_HW_DIVERSITY;
#ifdef CONFIG_RT2X00_LIB_LEDS
value = rt2x00_get_field16(eeprom, EEPROM_ANTENNA_LED_MODE);
rt2400pci_init_led(rt2x00dev, &rt2x00dev->led_radio, LED_TYPE_RADIO);
if (value == LED_MODE_TXRX_ACTIVITY ||
value == LED_MODE_DEFAULT ||
value == LED_MODE_ASUS)
rt2400pci_init_led(rt2x00dev, &rt2x00dev->led_qual,
LED_TYPE_ACTIVITY);
#endif
if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_HARDWARE_RADIO))
__set_bit(CAPABILITY_HW_BUTTON, &rt2x00dev->cap_flags);
if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RX_AGCVGC_TUNING))
__set_bit(CAPABILITY_LINK_TUNING, &rt2x00dev->cap_flags);
return 0;
}
static int rt2400pci_probe_hw_mode(struct rt2x00_dev *rt2x00dev)
{
struct hw_mode_spec *spec = &rt2x00dev->spec;
struct channel_info *info;
char *tx_power;
unsigned int i;
rt2x00dev->hw->flags = IEEE80211_HW_HOST_BROADCAST_PS_BUFFERING |
IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_PS_NULLFUNC_STACK;
SET_IEEE80211_DEV(rt2x00dev->hw, rt2x00dev->dev);
SET_IEEE80211_PERM_ADDR(rt2x00dev->hw,
rt2x00_eeprom_addr(rt2x00dev,
EEPROM_MAC_ADDR_0));
spec->supported_bands = SUPPORT_BAND_2GHZ;
spec->supported_rates = SUPPORT_RATE_CCK;
spec->num_channels = ARRAY_SIZE(rf_vals_b);
spec->channels = rf_vals_b;
info = kcalloc(spec->num_channels, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
spec->channels_info = info;
tx_power = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_START);
for (i = 0; i < 14; i++) {
info[i].max_power = TXPOWER_FROM_DEV(MAX_TXPOWER);
info[i].default_power1 = TXPOWER_FROM_DEV(tx_power[i]);
}
return 0;
}
static int rt2400pci_probe_hw(struct rt2x00_dev *rt2x00dev)
{
int retval;
retval = rt2400pci_validate_eeprom(rt2x00dev);
if (retval)
return retval;
retval = rt2400pci_init_eeprom(rt2x00dev);
if (retval)
return retval;
retval = rt2400pci_probe_hw_mode(rt2x00dev);
if (retval)
return retval;
__set_bit(REQUIRE_ATIM_QUEUE, &rt2x00dev->cap_flags);
__set_bit(REQUIRE_DMA, &rt2x00dev->cap_flags);
__set_bit(REQUIRE_SW_SEQNO, &rt2x00dev->cap_flags);
rt2x00dev->rssi_offset = DEFAULT_RSSI_OFFSET;
return 0;
}
static int rt2400pci_conf_tx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u16 queue,
const struct ieee80211_tx_queue_params *params)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
if (queue != 0)
return -EINVAL;
if (rt2x00mac_conf_tx(hw, vif, queue, params))
return -EINVAL;
rt2400pci_config_cw(rt2x00dev,
rt2x00dev->tx->cw_min, rt2x00dev->tx->cw_max);
return 0;
}
static u64 rt2400pci_get_tsf(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
u64 tsf;
u32 reg;
rt2x00pci_register_read(rt2x00dev, CSR17, &reg);
tsf = (u64) rt2x00_get_field32(reg, CSR17_HIGH_TSFTIMER) << 32;
rt2x00pci_register_read(rt2x00dev, CSR16, &reg);
tsf |= rt2x00_get_field32(reg, CSR16_LOW_TSFTIMER);
return tsf;
}
static int rt2400pci_tx_last_beacon(struct ieee80211_hw *hw)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
u32 reg;
rt2x00pci_register_read(rt2x00dev, CSR15, &reg);
return rt2x00_get_field32(reg, CSR15_BEACON_SENT);
}
static int rt2400pci_probe(struct pci_dev *pci_dev,
const struct pci_device_id *id)
{
return rt2x00pci_probe(pci_dev, &rt2400pci_ops);
}
static int __init rt2400pci_init(void)
{
return pci_register_driver(&rt2400pci_driver);
}
static void __exit rt2400pci_exit(void)
{
pci_unregister_driver(&rt2400pci_driver);
}
