static inline void rt2500usb_register_read(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
u16 *value)
{
__le16 reg;
rt2x00usb_vendor_request_buff(rt2x00dev, USB_MULTI_READ,
USB_VENDOR_REQUEST_IN, offset,
&reg, sizeof(reg), REGISTER_TIMEOUT);
*value = le16_to_cpu(reg);
}
static inline void rt2500usb_register_read_lock(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
u16 *value)
{
__le16 reg;
rt2x00usb_vendor_req_buff_lock(rt2x00dev, USB_MULTI_READ,
USB_VENDOR_REQUEST_IN, offset,
&reg, sizeof(reg), REGISTER_TIMEOUT);
*value = le16_to_cpu(reg);
}
static inline void rt2500usb_register_multiread(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
void *value, const u16 length)
{
rt2x00usb_vendor_request_buff(rt2x00dev, USB_MULTI_READ,
USB_VENDOR_REQUEST_IN, offset,
value, length,
REGISTER_TIMEOUT16(length));
}
static inline void rt2500usb_register_write(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
u16 value)
{
__le16 reg = cpu_to_le16(value);
rt2x00usb_vendor_request_buff(rt2x00dev, USB_MULTI_WRITE,
USB_VENDOR_REQUEST_OUT, offset,
&reg, sizeof(reg), REGISTER_TIMEOUT);
}
static inline void rt2500usb_register_write_lock(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
u16 value)
{
__le16 reg = cpu_to_le16(value);
rt2x00usb_vendor_req_buff_lock(rt2x00dev, USB_MULTI_WRITE,
USB_VENDOR_REQUEST_OUT, offset,
&reg, sizeof(reg), REGISTER_TIMEOUT);
}
static inline void rt2500usb_register_multiwrite(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
void *value, const u16 length)
{
rt2x00usb_vendor_request_buff(rt2x00dev, USB_MULTI_WRITE,
USB_VENDOR_REQUEST_OUT, offset,
value, length,
REGISTER_TIMEOUT16(length));
}
static int rt2500usb_regbusy_read(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
struct rt2x00_field16 field,
u16 *reg)
{
unsigned int i;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2500usb_register_read_lock(rt2x00dev, offset, reg);
if (!rt2x00_get_field16(*reg, field))
return 1;
udelay(REGISTER_BUSY_DELAY);
}
rt2x00_err(rt2x00dev, "Indirect register access failed: offset=0x%.08x, value=0x%.08x\n",
offset, *reg);
*reg = ~0;
return 0;
}
static void rt2500usb_bbp_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u8 value)
{
u16 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field16(&reg, PHY_CSR7_DATA, value);
rt2x00_set_field16(&reg, PHY_CSR7_REG_ID, word);
rt2x00_set_field16(&reg, PHY_CSR7_READ_CONTROL, 0);
rt2500usb_register_write_lock(rt2x00dev, PHY_CSR7, reg);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2500usb_bbp_read(struct rt2x00_dev *rt2x00dev,
const unsigned int word, u8 *value)
{
u16 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field16(&reg, PHY_CSR7_REG_ID, word);
rt2x00_set_field16(&reg, PHY_CSR7_READ_CONTROL, 1);
rt2500usb_register_write_lock(rt2x00dev, PHY_CSR7, reg);
if (WAIT_FOR_BBP(rt2x00dev, &reg))
rt2500usb_register_read_lock(rt2x00dev, PHY_CSR7, &reg);
}
*value = rt2x00_get_field16(reg, PHY_CSR7_DATA);
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt2500usb_rf_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u32 value)
{
u16 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_RF(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field16(&reg, PHY_CSR9_RF_VALUE, value);
rt2500usb_register_write_lock(rt2x00dev, PHY_CSR9, reg);
reg = 0;
rt2x00_set_field16(&reg, PHY_CSR10_RF_VALUE, value >> 16);
rt2x00_set_field16(&reg, PHY_CSR10_RF_NUMBER_OF_BITS, 20);
rt2x00_set_field16(&reg, PHY_CSR10_RF_IF_SELECT, 0);
rt2x00_set_field16(&reg, PHY_CSR10_RF_BUSY, 1);
rt2500usb_register_write_lock(rt2x00dev, PHY_CSR10, reg);
rt2x00_rf_write(rt2x00dev, word, value);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void _rt2500usb_register_read(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
u32 *value)
{
rt2500usb_register_read(rt2x00dev, offset, (u16 *)value);
}
static void _rt2500usb_register_write(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
u32 value)
{
rt2500usb_register_write(rt2x00dev, offset, value);
}
static int rt2500usb_rfkill_poll(struct rt2x00_dev *rt2x00dev)
{
u16 reg;
rt2500usb_register_read(rt2x00dev, MAC_CSR19, &reg);
return rt2x00_get_field16(reg, MAC_CSR19_VAL7);
}
static void rt2500usb_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct rt2x00_led *led =
container_of(led_cdev, struct rt2x00_led, led_dev);
unsigned int enabled = brightness != LED_OFF;
u16 reg;
rt2500usb_register_read(led->rt2x00dev, MAC_CSR20, &reg);
if (led->type == LED_TYPE_RADIO || led->type == LED_TYPE_ASSOC)
rt2x00_set_field16(&reg, MAC_CSR20_LINK, enabled);
else if (led->type == LED_TYPE_ACTIVITY)
rt2x00_set_field16(&reg, MAC_CSR20_ACTIVITY, enabled);
rt2500usb_register_write(led->rt2x00dev, MAC_CSR20, reg);
}
static int rt2500usb_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct rt2x00_led *led =
container_of(led_cdev, struct rt2x00_led, led_dev);
u16 reg;
rt2500usb_register_read(led->rt2x00dev, MAC_CSR21, &reg);
rt2x00_set_field16(&reg, MAC_CSR21_ON_PERIOD, *delay_on);
rt2x00_set_field16(&reg, MAC_CSR21_OFF_PERIOD, *delay_off);
rt2500usb_register_write(led->rt2x00dev, MAC_CSR21, reg);
return 0;
}
static void rt2500usb_init_led(struct rt2x00_dev *rt2x00dev,
struct rt2x00_led *led,
enum led_type type)
{
led->rt2x00dev = rt2x00dev;
led->type = type;
led->led_dev.brightness_set = rt2500usb_brightness_set;
led->led_dev.blink_set = rt2500usb_blink_set;
led->flags = LED_INITIALIZED;
}
static int rt2500usb_config_key(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_crypto *crypto,
struct ieee80211_key_conf *key)
{
u32 mask;
u16 reg;
enum cipher curr_cipher;
if (crypto->cmd == SET_KEY) {
if ((key->cipher == WLAN_CIPHER_SUITE_WEP40 ||
key->cipher == WLAN_CIPHER_SUITE_WEP104) &&
key->keyidx != 0)
return -EOPNOTSUPP;
mask = TXRX_CSR0_KEY_ID.bit_mask;
rt2500usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
curr_cipher = rt2x00_get_field16(reg, TXRX_CSR0_ALGORITHM);
reg &= mask;
if (reg && reg == mask)
return -ENOSPC;
reg = rt2x00_get_field16(reg, TXRX_CSR0_KEY_ID);
key->hw_key_idx += reg ? ffz(reg) : 0;
if (key->hw_key_idx > 0 && crypto->cipher != curr_cipher)
return -EOPNOTSUPP;
rt2500usb_register_multiwrite(rt2x00dev, KEY_ENTRY(key->hw_key_idx),
crypto->key, sizeof(crypto->key));
key->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
key->flags |= IEEE80211_KEY_FLAG_GENERATE_MMIC;
}
rt2500usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
rt2x00_set_field16(&reg, TXRX_CSR0_ALGORITHM, crypto->cipher);
rt2x00_set_field16(&reg, TXRX_CSR0_IV_OFFSET, IEEE80211_HEADER);
mask = rt2x00_get_field16(reg, TXRX_CSR0_KEY_ID);
if (crypto->cmd == SET_KEY)
mask |= 1 << key->hw_key_idx;
else if (crypto->cmd == DISABLE_KEY)
mask &= ~(1 << key->hw_key_idx);
rt2x00_set_field16(&reg, TXRX_CSR0_KEY_ID, mask);
rt2500usb_register_write(rt2x00dev, TXRX_CSR0, reg);
return 0;
}
static void rt2500usb_config_filter(struct rt2x00_dev *rt2x00dev,
const unsigned int filter_flags)
{
u16 reg;
rt2500usb_register_read(rt2x00dev, TXRX_CSR2, &reg);
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_CRC,
!(filter_flags & FIF_FCSFAIL));
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_PHYSICAL,
!(filter_flags & FIF_PLCPFAIL));
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_CONTROL,
!(filter_flags & FIF_CONTROL));
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_NOT_TO_ME,
!(filter_flags & FIF_PROMISC_IN_BSS));
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_TODS,
!(filter_flags & FIF_PROMISC_IN_BSS) &&
!rt2x00dev->intf_ap_count);
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_VERSION_ERROR, 1);
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_MULTICAST,
!(filter_flags & FIF_ALLMULTI));
rt2x00_set_field16(&reg, TXRX_CSR2_DROP_BROADCAST, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR2, reg);
}
static void rt2500usb_config_intf(struct rt2x00_dev *rt2x00dev,
struct rt2x00_intf *intf,
struct rt2x00intf_conf *conf,
const unsigned int flags)
{
unsigned int bcn_preload;
u16 reg;
if (flags & CONFIG_UPDATE_TYPE) {
bcn_preload = PREAMBLE + GET_DURATION(IEEE80211_HEADER, 20);
rt2500usb_register_read(rt2x00dev, TXRX_CSR20, &reg);
rt2x00_set_field16(&reg, TXRX_CSR20_OFFSET, bcn_preload >> 6);
rt2x00_set_field16(&reg, TXRX_CSR20_BCN_EXPECT_WINDOW,
2 * (conf->type != NL80211_IFTYPE_STATION));
rt2500usb_register_write(rt2x00dev, TXRX_CSR20, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR18, &reg);
rt2x00_set_field16(&reg, TXRX_CSR18_OFFSET, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR18, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR19, &reg);
rt2x00_set_field16(&reg, TXRX_CSR19_TSF_SYNC, conf->sync);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
}
if (flags & CONFIG_UPDATE_MAC)
rt2500usb_register_multiwrite(rt2x00dev, MAC_CSR2, conf->mac,
(3 * sizeof(__le16)));
if (flags & CONFIG_UPDATE_BSSID)
rt2500usb_register_multiwrite(rt2x00dev, MAC_CSR5, conf->bssid,
(3 * sizeof(__le16)));
}
static void rt2500usb_config_erp(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_erp *erp,
u32 changed)
{
u16 reg;
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
rt2500usb_register_read(rt2x00dev, TXRX_CSR10, &reg);
rt2x00_set_field16(&reg, TXRX_CSR10_AUTORESPOND_PREAMBLE,
!!erp->short_preamble);
rt2500usb_register_write(rt2x00dev, TXRX_CSR10, reg);
}
if (changed & BSS_CHANGED_BASIC_RATES)
rt2500usb_register_write(rt2x00dev, TXRX_CSR11,
erp->basic_rates);
if (changed & BSS_CHANGED_BEACON_INT) {
rt2500usb_register_read(rt2x00dev, TXRX_CSR18, &reg);
rt2x00_set_field16(&reg, TXRX_CSR18_INTERVAL,
erp->beacon_int * 4);
rt2500usb_register_write(rt2x00dev, TXRX_CSR18, reg);
}
if (changed & BSS_CHANGED_ERP_SLOT) {
rt2500usb_register_write(rt2x00dev, MAC_CSR10, erp->slot_time);
rt2500usb_register_write(rt2x00dev, MAC_CSR11, erp->sifs);
rt2500usb_register_write(rt2x00dev, MAC_CSR12, erp->eifs);
}
}
static void rt2500usb_config_ant(struct rt2x00_dev *rt2x00dev,
struct antenna_setup *ant)
{
u8 r2;
u8 r14;
u16 csr5;
u16 csr6;
BUG_ON(ant->rx == ANTENNA_SW_DIVERSITY ||
ant->tx == ANTENNA_SW_DIVERSITY);
rt2500usb_bbp_read(rt2x00dev, 2, &r2);
rt2500usb_bbp_read(rt2x00dev, 14, &r14);
rt2500usb_register_read(rt2x00dev, PHY_CSR5, &csr5);
rt2500usb_register_read(rt2x00dev, PHY_CSR6, &csr6);
switch (ant->tx) {
case ANTENNA_HW_DIVERSITY:
rt2x00_set_field8(&r2, BBP_R2_TX_ANTENNA, 1);
rt2x00_set_field16(&csr5, PHY_CSR5_CCK, 1);
rt2x00_set_field16(&csr6, PHY_CSR6_OFDM, 1);
break;
case ANTENNA_A:
rt2x00_set_field8(&r2, BBP_R2_TX_ANTENNA, 0);
rt2x00_set_field16(&csr5, PHY_CSR5_CCK, 0);
rt2x00_set_field16(&csr6, PHY_CSR6_OFDM, 0);
break;
case ANTENNA_B:
default:
rt2x00_set_field8(&r2, BBP_R2_TX_ANTENNA, 2);
rt2x00_set_field16(&csr5, PHY_CSR5_CCK, 2);
rt2x00_set_field16(&csr6, PHY_CSR6_OFDM, 2);
break;
}
switch (ant->rx) {
case ANTENNA_HW_DIVERSITY:
rt2x00_set_field8(&r14, BBP_R14_RX_ANTENNA, 1);
break;
case ANTENNA_A:
rt2x00_set_field8(&r14, BBP_R14_RX_ANTENNA, 0);
break;
case ANTENNA_B:
default:
rt2x00_set_field8(&r14, BBP_R14_RX_ANTENNA, 2);
break;
}
if (rt2x00_rf(rt2x00dev, RF2525E) || rt2x00_rf(rt2x00dev, RF5222)) {
rt2x00_set_field8(&r2, BBP_R2_TX_IQ_FLIP, 1);
rt2x00_set_field16(&csr5, PHY_CSR5_CCK_FLIP, 1);
rt2x00_set_field16(&csr6, PHY_CSR6_OFDM_FLIP, 1);
if (rt2x00_rf(rt2x00dev, RF2525E))
rt2x00_set_field8(&r14, BBP_R14_RX_IQ_FLIP, 0);
} else {
rt2x00_set_field16(&csr5, PHY_CSR5_CCK_FLIP, 0);
rt2x00_set_field16(&csr6, PHY_CSR6_OFDM_FLIP, 0);
}
rt2500usb_bbp_write(rt2x00dev, 2, r2);
rt2500usb_bbp_write(rt2x00dev, 14, r14);
rt2500usb_register_write(rt2x00dev, PHY_CSR5, csr5);
rt2500usb_register_write(rt2x00dev, PHY_CSR6, csr6);
}
static void rt2500usb_config_channel(struct rt2x00_dev *rt2x00dev,
struct rf_channel *rf, const int txpower)
{
rt2x00_set_field32(&rf->rf3, RF3_TXPOWER, TXPOWER_TO_DEV(txpower));
if (rt2x00_rf(rt2x00dev, RF2525E)) {
static const u32 vals[] = {
0x000008aa, 0x000008ae, 0x000008ae, 0x000008b2,
0x000008b2, 0x000008b6, 0x000008b6, 0x000008ba,
0x000008ba, 0x000008be, 0x000008b7, 0x00000902,
0x00000902, 0x00000906
};
rt2500usb_rf_write(rt2x00dev, 2, vals[rf->channel - 1]);
if (rf->rf4)
rt2500usb_rf_write(rt2x00dev, 4, rf->rf4);
}
rt2500usb_rf_write(rt2x00dev, 1, rf->rf1);
rt2500usb_rf_write(rt2x00dev, 2, rf->rf2);
rt2500usb_rf_write(rt2x00dev, 3, rf->rf3);
if (rf->rf4)
rt2500usb_rf_write(rt2x00dev, 4, rf->rf4);
}
static void rt2500usb_config_txpower(struct rt2x00_dev *rt2x00dev,
const int txpower)
{
u32 rf3;
rt2x00_rf_read(rt2x00dev, 3, &rf3);
rt2x00_set_field32(&rf3, RF3_TXPOWER, TXPOWER_TO_DEV(txpower));
rt2500usb_rf_write(rt2x00dev, 3, rf3);
}
static void rt2500usb_config_ps(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
enum dev_state state =
(libconf->conf->flags & IEEE80211_CONF_PS) ?
STATE_SLEEP : STATE_AWAKE;
u16 reg;
if (state == STATE_SLEEP) {
rt2500usb_register_read(rt2x00dev, MAC_CSR18, &reg);
rt2x00_set_field16(&reg, MAC_CSR18_DELAY_AFTER_BEACON,
rt2x00dev->beacon_int - 20);
rt2x00_set_field16(&reg, MAC_CSR18_BEACONS_BEFORE_WAKEUP,
libconf->conf->listen_interval - 1);
rt2x00_set_field16(&reg, MAC_CSR18_AUTO_WAKE, 0);
rt2500usb_register_write(rt2x00dev, MAC_CSR18, reg);
rt2x00_set_field16(&reg, MAC_CSR18_AUTO_WAKE, 1);
rt2500usb_register_write(rt2x00dev, MAC_CSR18, reg);
} else {
rt2500usb_register_read(rt2x00dev, MAC_CSR18, &reg);
rt2x00_set_field16(&reg, MAC_CSR18_AUTO_WAKE, 0);
rt2500usb_register_write(rt2x00dev, MAC_CSR18, reg);
}
rt2x00dev->ops->lib->set_device_state(rt2x00dev, state);
}
static void rt2500usb_config(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf,
const unsigned int flags)
{
if (flags & IEEE80211_CONF_CHANGE_CHANNEL)
rt2500usb_config_channel(rt2x00dev, &libconf->rf,
libconf->conf->power_level);
if ((flags & IEEE80211_CONF_CHANGE_POWER) &&
!(flags & IEEE80211_CONF_CHANGE_CHANNEL))
rt2500usb_config_txpower(rt2x00dev,
libconf->conf->power_level);
if (flags & IEEE80211_CONF_CHANGE_PS)
rt2500usb_config_ps(rt2x00dev, libconf);
}
static void rt2500usb_link_stats(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual)
{
u16 reg;
rt2500usb_register_read(rt2x00dev, STA_CSR0, &reg);
qual->rx_failed = rt2x00_get_field16(reg, STA_CSR0_FCS_ERROR);
rt2500usb_register_read(rt2x00dev, STA_CSR3, &reg);
qual->false_cca = rt2x00_get_field16(reg, STA_CSR3_FALSE_CCA_ERROR);
}
static void rt2500usb_reset_tuner(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual)
{
u16 eeprom;
u16 value;
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_R24, &eeprom);
value = rt2x00_get_field16(eeprom, EEPROM_BBPTUNE_R24_LOW);
rt2500usb_bbp_write(rt2x00dev, 24, value);
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_R25, &eeprom);
value = rt2x00_get_field16(eeprom, EEPROM_BBPTUNE_R25_LOW);
rt2500usb_bbp_write(rt2x00dev, 25, value);
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_R61, &eeprom);
value = rt2x00_get_field16(eeprom, EEPROM_BBPTUNE_R61_LOW);
rt2500usb_bbp_write(rt2x00dev, 61, value);
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_VGC, &eeprom);
value = rt2x00_get_field16(eeprom, EEPROM_BBPTUNE_VGCUPPER);
rt2500usb_bbp_write(rt2x00dev, 17, value);
qual->vgc_level = value;
}
static void rt2500usb_start_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u16 reg;
switch (queue->qid) {
case QID_RX:
rt2500usb_register_read(rt2x00dev, TXRX_CSR2, &reg);
rt2x00_set_field16(&reg, TXRX_CSR2_DISABLE_RX, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR2, reg);
break;
case QID_BEACON:
rt2500usb_register_read(rt2x00dev, TXRX_CSR19, &reg);
rt2x00_set_field16(&reg, TXRX_CSR19_TSF_COUNT, 1);
rt2x00_set_field16(&reg, TXRX_CSR19_TBCN, 1);
rt2x00_set_field16(&reg, TXRX_CSR19_BEACON_GEN, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
break;
default:
break;
}
}
static void rt2500usb_stop_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u16 reg;
switch (queue->qid) {
case QID_RX:
rt2500usb_register_read(rt2x00dev, TXRX_CSR2, &reg);
rt2x00_set_field16(&reg, TXRX_CSR2_DISABLE_RX, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR2, reg);
break;
case QID_BEACON:
rt2500usb_register_read(rt2x00dev, TXRX_CSR19, &reg);
rt2x00_set_field16(&reg, TXRX_CSR19_TSF_COUNT, 0);
rt2x00_set_field16(&reg, TXRX_CSR19_TBCN, 0);
rt2x00_set_field16(&reg, TXRX_CSR19_BEACON_GEN, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
break;
default:
break;
}
}
static int rt2500usb_init_registers(struct rt2x00_dev *rt2x00dev)
{
u16 reg;
rt2x00usb_vendor_request_sw(rt2x00dev, USB_DEVICE_MODE, 0x0001,
USB_MODE_TEST, REGISTER_TIMEOUT);
rt2x00usb_vendor_request_sw(rt2x00dev, USB_SINGLE_WRITE, 0x0308,
0x00f0, REGISTER_TIMEOUT);
rt2500usb_register_read(rt2x00dev, TXRX_CSR2, &reg);
rt2x00_set_field16(&reg, TXRX_CSR2_DISABLE_RX, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR2, reg);
rt2500usb_register_write(rt2x00dev, MAC_CSR13, 0x1111);
rt2500usb_register_write(rt2x00dev, MAC_CSR14, 0x1e11);
rt2500usb_register_read(rt2x00dev, MAC_CSR1, &reg);
rt2x00_set_field16(&reg, MAC_CSR1_SOFT_RESET, 1);
rt2x00_set_field16(&reg, MAC_CSR1_BBP_RESET, 1);
rt2x00_set_field16(&reg, MAC_CSR1_HOST_READY, 0);
rt2500usb_register_write(rt2x00dev, MAC_CSR1, reg);
rt2500usb_register_read(rt2x00dev, MAC_CSR1, &reg);
rt2x00_set_field16(&reg, MAC_CSR1_SOFT_RESET, 0);
rt2x00_set_field16(&reg, MAC_CSR1_BBP_RESET, 0);
rt2x00_set_field16(&reg, MAC_CSR1_HOST_READY, 0);
rt2500usb_register_write(rt2x00dev, MAC_CSR1, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR5, &reg);
rt2x00_set_field16(&reg, TXRX_CSR5_BBP_ID0, 13);
rt2x00_set_field16(&reg, TXRX_CSR5_BBP_ID0_VALID, 1);
rt2x00_set_field16(&reg, TXRX_CSR5_BBP_ID1, 12);
rt2x00_set_field16(&reg, TXRX_CSR5_BBP_ID1_VALID, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR5, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR6, &reg);
rt2x00_set_field16(&reg, TXRX_CSR6_BBP_ID0, 10);
rt2x00_set_field16(&reg, TXRX_CSR6_BBP_ID0_VALID, 1);
rt2x00_set_field16(&reg, TXRX_CSR6_BBP_ID1, 11);
rt2x00_set_field16(&reg, TXRX_CSR6_BBP_ID1_VALID, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR6, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR7, &reg);
rt2x00_set_field16(&reg, TXRX_CSR7_BBP_ID0, 7);
rt2x00_set_field16(&reg, TXRX_CSR7_BBP_ID0_VALID, 1);
rt2x00_set_field16(&reg, TXRX_CSR7_BBP_ID1, 6);
rt2x00_set_field16(&reg, TXRX_CSR7_BBP_ID1_VALID, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR7, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR8, &reg);
rt2x00_set_field16(&reg, TXRX_CSR8_BBP_ID0, 5);
rt2x00_set_field16(&reg, TXRX_CSR8_BBP_ID0_VALID, 1);
rt2x00_set_field16(&reg, TXRX_CSR8_BBP_ID1, 0);
rt2x00_set_field16(&reg, TXRX_CSR8_BBP_ID1_VALID, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR8, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR19, &reg);
rt2x00_set_field16(&reg, TXRX_CSR19_TSF_COUNT, 0);
rt2x00_set_field16(&reg, TXRX_CSR19_TSF_SYNC, 0);
rt2x00_set_field16(&reg, TXRX_CSR19_TBCN, 0);
rt2x00_set_field16(&reg, TXRX_CSR19_BEACON_GEN, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
rt2500usb_register_write(rt2x00dev, TXRX_CSR21, 0xe78f);
rt2500usb_register_write(rt2x00dev, MAC_CSR9, 0xff1d);
if (rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_AWAKE))
return -EBUSY;
rt2500usb_register_read(rt2x00dev, MAC_CSR1, &reg);
rt2x00_set_field16(&reg, MAC_CSR1_SOFT_RESET, 0);
rt2x00_set_field16(&reg, MAC_CSR1_BBP_RESET, 0);
rt2x00_set_field16(&reg, MAC_CSR1_HOST_READY, 1);
rt2500usb_register_write(rt2x00dev, MAC_CSR1, reg);
if (rt2x00_rev(rt2x00dev) >= RT2570_VERSION_C) {
rt2500usb_register_read(rt2x00dev, PHY_CSR2, &reg);
rt2x00_set_field16(&reg, PHY_CSR2_LNA, 0);
} else {
reg = 0;
rt2x00_set_field16(&reg, PHY_CSR2_LNA, 1);
rt2x00_set_field16(&reg, PHY_CSR2_LNA_MODE, 3);
}
rt2500usb_register_write(rt2x00dev, PHY_CSR2, reg);
rt2500usb_register_write(rt2x00dev, MAC_CSR11, 0x0002);
rt2500usb_register_write(rt2x00dev, MAC_CSR22, 0x0053);
rt2500usb_register_write(rt2x00dev, MAC_CSR15, 0x01ee);
rt2500usb_register_write(rt2x00dev, MAC_CSR16, 0x0000);
rt2500usb_register_read(rt2x00dev, MAC_CSR8, &reg);
rt2x00_set_field16(&reg, MAC_CSR8_MAX_FRAME_UNIT,
rt2x00dev->rx->data_size);
rt2500usb_register_write(rt2x00dev, MAC_CSR8, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
rt2x00_set_field16(&reg, TXRX_CSR0_ALGORITHM, CIPHER_NONE);
rt2x00_set_field16(&reg, TXRX_CSR0_IV_OFFSET, IEEE80211_HEADER);
rt2x00_set_field16(&reg, TXRX_CSR0_KEY_ID, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR0, reg);
rt2500usb_register_read(rt2x00dev, MAC_CSR18, &reg);
rt2x00_set_field16(&reg, MAC_CSR18_DELAY_AFTER_BEACON, 90);
rt2500usb_register_write(rt2x00dev, MAC_CSR18, reg);
rt2500usb_register_read(rt2x00dev, PHY_CSR4, &reg);
rt2x00_set_field16(&reg, PHY_CSR4_LOW_RF_LE, 1);
rt2500usb_register_write(rt2x00dev, PHY_CSR4, reg);
rt2500usb_register_read(rt2x00dev, TXRX_CSR1, &reg);
rt2x00_set_field16(&reg, TXRX_CSR1_AUTO_SEQUENCE, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR1, reg);
return 0;
}
static int rt2500usb_wait_bbp_ready(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u8 value;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2500usb_bbp_read(rt2x00dev, 0, &value);
if ((value != 0xff) && (value != 0x00))
return 0;
udelay(REGISTER_BUSY_DELAY);
}
rt2x00_err(rt2x00dev, "BBP register access failed, aborting\n");
return -EACCES;
}
static int rt2500usb_init_bbp(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u16 eeprom;
u8 value;
u8 reg_id;
if (unlikely(rt2500usb_wait_bbp_ready(rt2x00dev)))
return -EACCES;
rt2500usb_bbp_write(rt2x00dev, 3, 0x02);
rt2500usb_bbp_write(rt2x00dev, 4, 0x19);
rt2500usb_bbp_write(rt2x00dev, 14, 0x1c);
rt2500usb_bbp_write(rt2x00dev, 15, 0x30);
rt2500usb_bbp_write(rt2x00dev, 16, 0xac);
rt2500usb_bbp_write(rt2x00dev, 18, 0x18);
rt2500usb_bbp_write(rt2x00dev, 19, 0xff);
rt2500usb_bbp_write(rt2x00dev, 20, 0x1e);
rt2500usb_bbp_write(rt2x00dev, 21, 0x08);
rt2500usb_bbp_write(rt2x00dev, 22, 0x08);
rt2500usb_bbp_write(rt2x00dev, 23, 0x08);
rt2500usb_bbp_write(rt2x00dev, 24, 0x80);
rt2500usb_bbp_write(rt2x00dev, 25, 0x50);
rt2500usb_bbp_write(rt2x00dev, 26, 0x08);
rt2500usb_bbp_write(rt2x00dev, 27, 0x23);
rt2500usb_bbp_write(rt2x00dev, 30, 0x10);
rt2500usb_bbp_write(rt2x00dev, 31, 0x2b);
rt2500usb_bbp_write(rt2x00dev, 32, 0xb9);
rt2500usb_bbp_write(rt2x00dev, 34, 0x12);
rt2500usb_bbp_write(rt2x00dev, 35, 0x50);
rt2500usb_bbp_write(rt2x00dev, 39, 0xc4);
rt2500usb_bbp_write(rt2x00dev, 40, 0x02);
rt2500usb_bbp_write(rt2x00dev, 41, 0x60);
rt2500usb_bbp_write(rt2x00dev, 53, 0x10);
rt2500usb_bbp_write(rt2x00dev, 54, 0x18);
rt2500usb_bbp_write(rt2x00dev, 56, 0x08);
rt2500usb_bbp_write(rt2x00dev, 57, 0x10);
rt2500usb_bbp_write(rt2x00dev, 58, 0x08);
rt2500usb_bbp_write(rt2x00dev, 61, 0x60);
rt2500usb_bbp_write(rt2x00dev, 62, 0x10);
rt2500usb_bbp_write(rt2x00dev, 75, 0xff);
for (i = 0; i < EEPROM_BBP_SIZE; i++) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBP_START + i, &eeprom);
if (eeprom != 0xffff && eeprom != 0x0000) {
reg_id = rt2x00_get_field16(eeprom, EEPROM_BBP_REG_ID);
value = rt2x00_get_field16(eeprom, EEPROM_BBP_VALUE);
rt2500usb_bbp_write(rt2x00dev, reg_id, value);
}
}
return 0;
}
static int rt2500usb_enable_radio(struct rt2x00_dev *rt2x00dev)
{
if (unlikely(rt2500usb_init_registers(rt2x00dev) ||
rt2500usb_init_bbp(rt2x00dev)))
return -EIO;
return 0;
}
static void rt2500usb_disable_radio(struct rt2x00_dev *rt2x00dev)
{
rt2500usb_register_write(rt2x00dev, MAC_CSR13, 0x2121);
rt2500usb_register_write(rt2x00dev, MAC_CSR14, 0x2121);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, 0);
rt2x00usb_disable_radio(rt2x00dev);
}
static int rt2500usb_set_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
u16 reg;
u16 reg2;
unsigned int i;
char put_to_sleep;
char bbp_state;
char rf_state;
put_to_sleep = (state != STATE_AWAKE);
reg = 0;
rt2x00_set_field16(&reg, MAC_CSR17_BBP_DESIRE_STATE, state);
rt2x00_set_field16(&reg, MAC_CSR17_RF_DESIRE_STATE, state);
rt2x00_set_field16(&reg, MAC_CSR17_PUT_TO_SLEEP, put_to_sleep);
rt2500usb_register_write(rt2x00dev, MAC_CSR17, reg);
rt2x00_set_field16(&reg, MAC_CSR17_SET_STATE, 1);
rt2500usb_register_write(rt2x00dev, MAC_CSR17, reg);
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2500usb_register_read(rt2x00dev, MAC_CSR17, &reg2);
bbp_state = rt2x00_get_field16(reg2, MAC_CSR17_BBP_CURR_STATE);
rf_state = rt2x00_get_field16(reg2, MAC_CSR17_RF_CURR_STATE);
if (bbp_state == state && rf_state == state)
return 0;
rt2500usb_register_write(rt2x00dev, MAC_CSR17, reg);
msleep(30);
}
return -EBUSY;
}
static int rt2500usb_set_device_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int retval = 0;
switch (state) {
case STATE_RADIO_ON:
retval = rt2500usb_enable_radio(rt2x00dev);
break;
case STATE_RADIO_OFF:
rt2500usb_disable_radio(rt2x00dev);
break;
case STATE_RADIO_IRQ_ON:
case STATE_RADIO_IRQ_OFF:
break;
case STATE_DEEP_SLEEP:
case STATE_SLEEP:
case STATE_STANDBY:
case STATE_AWAKE:
retval = rt2500usb_set_state(rt2x00dev, state);
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
static void rt2500usb_write_tx_desc(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
__le32 *txd = (__le32 *) entry->skb->data;
u32 word;
rt2x00_desc_read(txd, 0, &word);
rt2x00_set_field32(&word, TXD_W0_RETRY_LIMIT, txdesc->retry_limit);
rt2x00_set_field32(&word, TXD_W0_MORE_FRAG,
test_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_ACK,
test_bit(ENTRY_TXD_ACK, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_TIMESTAMP,
test_bit(ENTRY_TXD_REQ_TIMESTAMP, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_OFDM,
(txdesc->rate_mode == RATE_MODE_OFDM));
rt2x00_set_field32(&word, TXD_W0_NEW_SEQ,
test_bit(ENTRY_TXD_FIRST_FRAGMENT, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_IFS, txdesc->u.plcp.ifs);
rt2x00_set_field32(&word, TXD_W0_DATABYTE_COUNT, txdesc->length);
rt2x00_set_field32(&word, TXD_W0_CIPHER, !!txdesc->cipher);
rt2x00_set_field32(&word, TXD_W0_KEY_ID, txdesc->key_idx);
rt2x00_desc_write(txd, 0, word);
rt2x00_desc_read(txd, 1, &word);
rt2x00_set_field32(&word, TXD_W1_IV_OFFSET, txdesc->iv_offset);
rt2x00_set_field32(&word, TXD_W1_AIFS, entry->queue->aifs);
rt2x00_set_field32(&word, TXD_W1_CWMIN, entry->queue->cw_min);
rt2x00_set_field32(&word, TXD_W1_CWMAX, entry->queue->cw_max);
rt2x00_desc_write(txd, 1, word);
rt2x00_desc_read(txd, 2, &word);
rt2x00_set_field32(&word, TXD_W2_PLCP_SIGNAL, txdesc->u.plcp.signal);
rt2x00_set_field32(&word, TXD_W2_PLCP_SERVICE, txdesc->u.plcp.service);
rt2x00_set_field32(&word, TXD_W2_PLCP_LENGTH_LOW,
txdesc->u.plcp.length_low);
rt2x00_set_field32(&word, TXD_W2_PLCP_LENGTH_HIGH,
txdesc->u.plcp.length_high);
rt2x00_desc_write(txd, 2, word);
if (test_bit(ENTRY_TXD_ENCRYPT, &txdesc->flags)) {
_rt2x00_desc_write(txd, 3, skbdesc->iv[0]);
_rt2x00_desc_write(txd, 4, skbdesc->iv[1]);
}
skbdesc->flags |= SKBDESC_DESC_IN_SKB;
skbdesc->desc = txd;
skbdesc->desc_len = TXD_DESC_SIZE;
}
static void rt2500usb_write_beacon(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct usb_device *usb_dev = to_usb_device_intf(rt2x00dev->dev);
struct queue_entry_priv_usb_bcn *bcn_priv = entry->priv_data;
int pipe = usb_sndbulkpipe(usb_dev, entry->queue->usb_endpoint);
int length;
u16 reg, reg0;
rt2500usb_register_read(rt2x00dev, TXRX_CSR19, &reg);
rt2x00_set_field16(&reg, TXRX_CSR19_BEACON_GEN, 0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
skb_push(entry->skb, TXD_DESC_SIZE);
memset(entry->skb->data, 0, TXD_DESC_SIZE);
rt2500usb_write_tx_desc(entry, txdesc);
rt2x00debug_dump_frame(rt2x00dev, DUMP_FRAME_BEACON, entry->skb);
length = rt2x00dev->ops->lib->get_tx_data_len(entry);
usb_fill_bulk_urb(bcn_priv->urb, usb_dev, pipe,
entry->skb->data, length, rt2500usb_beacondone,
entry);
bcn_priv->guardian_data = 0;
usb_fill_bulk_urb(bcn_priv->guardian_urb, usb_dev, pipe,
&bcn_priv->guardian_data, 1, rt2500usb_beacondone,
entry);
usb_submit_urb(bcn_priv->guardian_urb, GFP_ATOMIC);
rt2x00_set_field16(&reg, TXRX_CSR19_TSF_COUNT, 1);
rt2x00_set_field16(&reg, TXRX_CSR19_TBCN, 1);
reg0 = reg;
rt2x00_set_field16(&reg, TXRX_CSR19_BEACON_GEN, 1);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg0);
rt2500usb_register_write(rt2x00dev, TXRX_CSR19, reg);
}
static int rt2500usb_get_tx_data_len(struct queue_entry *entry)
{
int length;
length = roundup(entry->skb->len, 2);
length += (2 * !(length % entry->queue->usb_maxpacket));
return length;
}
static void rt2500usb_fill_rxdone(struct queue_entry *entry,
struct rxdone_entry_desc *rxdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct queue_entry_priv_usb *entry_priv = entry->priv_data;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
__le32 *rxd =
(__le32 *)(entry->skb->data +
(entry_priv->urb->actual_length -
entry->queue->desc_size));
u32 word0;
u32 word1;
memcpy(skbdesc->desc, rxd, skbdesc->desc_len);
rxd = (__le32 *)skbdesc->desc;
rt2x00_desc_read(rxd, 0, &word0);
rt2x00_desc_read(rxd, 1, &word1);
if (rt2x00_get_field32(word0, RXD_W0_CRC_ERROR))
rxdesc->flags |= RX_FLAG_FAILED_FCS_CRC;
if (rt2x00_get_field32(word0, RXD_W0_PHYSICAL_ERROR))
rxdesc->flags |= RX_FLAG_FAILED_PLCP_CRC;
rxdesc->cipher = rt2x00_get_field32(word0, RXD_W0_CIPHER);
if (rt2x00_get_field32(word0, RXD_W0_CIPHER_ERROR))
rxdesc->cipher_status = RX_CRYPTO_FAIL_KEY;
if (rxdesc->cipher != CIPHER_NONE) {
_rt2x00_desc_read(rxd, 2, &rxdesc->iv[0]);
_rt2x00_desc_read(rxd, 3, &rxdesc->iv[1]);
rxdesc->dev_flags |= RXDONE_CRYPTO_IV;
rxdesc->flags |= RX_FLAG_MMIC_STRIPPED;
if (rxdesc->cipher_status == RX_CRYPTO_SUCCESS)
rxdesc->flags |= RX_FLAG_DECRYPTED;
else if (rxdesc->cipher_status == RX_CRYPTO_FAIL_MIC)
rxdesc->flags |= RX_FLAG_MMIC_ERROR;
}
rxdesc->signal = rt2x00_get_field32(word1, RXD_W1_SIGNAL);
rxdesc->rssi =
rt2x00_get_field32(word1, RXD_W1_RSSI) - rt2x00dev->rssi_offset;
rxdesc->size = rt2x00_get_field32(word0, RXD_W0_DATABYTE_COUNT);
if (rt2x00_get_field32(word0, RXD_W0_OFDM))
rxdesc->dev_flags |= RXDONE_SIGNAL_PLCP;
else
rxdesc->dev_flags |= RXDONE_SIGNAL_BITRATE;
if (rt2x00_get_field32(word0, RXD_W0_MY_BSS))
rxdesc->dev_flags |= RXDONE_MY_BSS;
skb_trim(entry->skb, rxdesc->size);
}
static void rt2500usb_beacondone(struct urb *urb)
{
struct queue_entry *entry = (struct queue_entry *)urb->context;
struct queue_entry_priv_usb_bcn *bcn_priv = entry->priv_data;
if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &entry->queue->rt2x00dev->flags))
return;
if (bcn_priv->guardian_urb == urb) {
usb_submit_urb(bcn_priv->urb, GFP_ATOMIC);
} else if (bcn_priv->urb == urb) {
dev_kfree_skb(entry->skb);
entry->skb = NULL;
}
}
static int rt2500usb_validate_eeprom(struct rt2x00_dev *rt2x00dev)
{
u16 word;
u8 *mac;
u8 bbp;
rt2x00usb_eeprom_read(rt2x00dev, rt2x00dev->eeprom, EEPROM_SIZE);
mac = rt2x00_eeprom_addr(rt2x00dev, EEPROM_MAC_ADDR_0);
if (!is_valid_ether_addr(mac)) {
eth_random_addr(mac);
rt2x00_eeprom_dbg(rt2x00dev, "MAC: %pM\n", mac);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_ANTENNA_NUM, 2);
rt2x00_set_field16(&word, EEPROM_ANTENNA_TX_DEFAULT,
ANTENNA_SW_DIVERSITY);
rt2x00_set_field16(&word, EEPROM_ANTENNA_RX_DEFAULT,
ANTENNA_SW_DIVERSITY);
rt2x00_set_field16(&word, EEPROM_ANTENNA_LED_MODE,
LED_MODE_DEFAULT);
rt2x00_set_field16(&word, EEPROM_ANTENNA_DYN_TXAGC, 0);
rt2x00_set_field16(&word, EEPROM_ANTENNA_HARDWARE_RADIO, 0);
rt2x00_set_field16(&word, EEPROM_ANTENNA_RF_TYPE, RF2522);
rt2x00_eeprom_write(rt2x00dev, EEPROM_ANTENNA, word);
rt2x00_eeprom_dbg(rt2x00dev, "Antenna: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_NIC_CARDBUS_ACCEL, 0);
rt2x00_set_field16(&word, EEPROM_NIC_DYN_BBP_TUNE, 0);
rt2x00_set_field16(&word, EEPROM_NIC_CCK_TX_POWER, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_NIC, word);
rt2x00_eeprom_dbg(rt2x00dev, "NIC: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_CALIBRATE_OFFSET, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_CALIBRATE_OFFSET_RSSI,
DEFAULT_RSSI_OFFSET);
rt2x00_eeprom_write(rt2x00dev, EEPROM_CALIBRATE_OFFSET, word);
rt2x00_eeprom_dbg(rt2x00dev, "Calibrate offset: 0x%04x\n",
word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_BBPTUNE_THRESHOLD, 45);
rt2x00_eeprom_write(rt2x00dev, EEPROM_BBPTUNE, word);
rt2x00_eeprom_dbg(rt2x00dev, "BBPtune: 0x%04x\n", word);
}
rt2500usb_bbp_read(rt2x00dev, 17, &bbp);
bbp -= 6;
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_VGC, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_BBPTUNE_VGCUPPER, 0x40);
rt2x00_set_field16(&word, EEPROM_BBPTUNE_VGCLOWER, bbp);
rt2x00_eeprom_write(rt2x00dev, EEPROM_BBPTUNE_VGC, word);
rt2x00_eeprom_dbg(rt2x00dev, "BBPtune vgc: 0x%04x\n", word);
} else {
rt2x00_set_field16(&word, EEPROM_BBPTUNE_VGCLOWER, bbp);
rt2x00_eeprom_write(rt2x00dev, EEPROM_BBPTUNE_VGC, word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_R17, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R17_LOW, 0x48);
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R17_HIGH, 0x41);
rt2x00_eeprom_write(rt2x00dev, EEPROM_BBPTUNE_R17, word);
rt2x00_eeprom_dbg(rt2x00dev, "BBPtune r17: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_R24, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R24_LOW, 0x40);
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R24_HIGH, 0x80);
rt2x00_eeprom_write(rt2x00dev, EEPROM_BBPTUNE_R24, word);
rt2x00_eeprom_dbg(rt2x00dev, "BBPtune r24: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_R25, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R25_LOW, 0x40);
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R25_HIGH, 0x50);
rt2x00_eeprom_write(rt2x00dev, EEPROM_BBPTUNE_R25, word);
rt2x00_eeprom_dbg(rt2x00dev, "BBPtune r25: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBPTUNE_R61, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R61_LOW, 0x60);
rt2x00_set_field16(&word, EEPROM_BBPTUNE_R61_HIGH, 0x6d);
rt2x00_eeprom_write(rt2x00dev, EEPROM_BBPTUNE_R61, word);
rt2x00_eeprom_dbg(rt2x00dev, "BBPtune r61: 0x%04x\n", word);
}
return 0;
}
static int rt2500usb_init_eeprom(struct rt2x00_dev *rt2x00dev)
{
u16 reg;
u16 value;
u16 eeprom;
rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA, &eeprom);
value = rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RF_TYPE);
rt2500usb_register_read(rt2x00dev, MAC_CSR0, &reg);
rt2x00_set_chip(rt2x00dev, RT2570, value, reg);
if (((reg & 0xfff0) != 0) || ((reg & 0x0000000f) == 0)) {
rt2x00_err(rt2x00dev, "Invalid RT chipset detected\n");
return -ENODEV;
}
if (!rt2x00_rf(rt2x00dev, RF2522) &&
!rt2x00_rf(rt2x00dev, RF2523) &&
!rt2x00_rf(rt2x00dev, RF2524) &&
!rt2x00_rf(rt2x00dev, RF2525) &&
!rt2x00_rf(rt2x00dev, RF2525E) &&
!rt2x00_rf(rt2x00dev, RF5222)) {
rt2x00_err(rt2x00dev, "Invalid RF chipset detected\n");
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
rt2500usb_init_led(rt2x00dev, &rt2x00dev->led_radio, LED_TYPE_RADIO);
if (value == LED_MODE_TXRX_ACTIVITY ||
value == LED_MODE_DEFAULT ||
value == LED_MODE_ASUS)
rt2500usb_init_led(rt2x00dev, &rt2x00dev->led_qual,
LED_TYPE_ACTIVITY);
#endif
if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_HARDWARE_RADIO))
__set_bit(CAPABILITY_HW_BUTTON, &rt2x00dev->cap_flags);
rt2x00_eeprom_read(rt2x00dev, EEPROM_CALIBRATE_OFFSET, &eeprom);
rt2x00dev->rssi_offset =
rt2x00_get_field16(eeprom, EEPROM_CALIBRATE_OFFSET_RSSI);
return 0;
}
static int rt2500usb_probe_hw_mode(struct rt2x00_dev *rt2x00dev)
{
struct hw_mode_spec *spec = &rt2x00dev->spec;
struct channel_info *info;
char *tx_power;
unsigned int i;
rt2x00dev->hw->flags =
IEEE80211_HW_RX_INCLUDES_FCS |
IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_PS_NULLFUNC_STACK;
SET_IEEE80211_DEV(rt2x00dev->hw, rt2x00dev->dev);
SET_IEEE80211_PERM_ADDR(rt2x00dev->hw,
rt2x00_eeprom_addr(rt2x00dev,
EEPROM_MAC_ADDR_0));
spec->supported_bands = SUPPORT_BAND_2GHZ;
spec->supported_rates = SUPPORT_RATE_CCK | SUPPORT_RATE_OFDM;
if (rt2x00_rf(rt2x00dev, RF2522)) {
spec->num_channels = ARRAY_SIZE(rf_vals_bg_2522);
spec->channels = rf_vals_bg_2522;
} else if (rt2x00_rf(rt2x00dev, RF2523)) {
spec->num_channels = ARRAY_SIZE(rf_vals_bg_2523);
spec->channels = rf_vals_bg_2523;
} else if (rt2x00_rf(rt2x00dev, RF2524)) {
spec->num_channels = ARRAY_SIZE(rf_vals_bg_2524);
spec->channels = rf_vals_bg_2524;
} else if (rt2x00_rf(rt2x00dev, RF2525)) {
spec->num_channels = ARRAY_SIZE(rf_vals_bg_2525);
spec->channels = rf_vals_bg_2525;
} else if (rt2x00_rf(rt2x00dev, RF2525E)) {
spec->num_channels = ARRAY_SIZE(rf_vals_bg_2525e);
spec->channels = rf_vals_bg_2525e;
} else if (rt2x00_rf(rt2x00dev, RF5222)) {
spec->supported_bands |= SUPPORT_BAND_5GHZ;
spec->num_channels = ARRAY_SIZE(rf_vals_5222);
spec->channels = rf_vals_5222;
}
info = kcalloc(spec->num_channels, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
spec->channels_info = info;
tx_power = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_START);
for (i = 0; i < 14; i++) {
info[i].max_power = MAX_TXPOWER;
info[i].default_power1 = TXPOWER_FROM_DEV(tx_power[i]);
}
if (spec->num_channels > 14) {
for (i = 14; i < spec->num_channels; i++) {
info[i].max_power = MAX_TXPOWER;
info[i].default_power1 = DEFAULT_TXPOWER;
}
}
return 0;
}
static int rt2500usb_probe_hw(struct rt2x00_dev *rt2x00dev)
{
int retval;
u16 reg;
retval = rt2500usb_validate_eeprom(rt2x00dev);
if (retval)
return retval;
retval = rt2500usb_init_eeprom(rt2x00dev);
if (retval)
return retval;
rt2500usb_register_read(rt2x00dev, MAC_CSR19, &reg);
rt2x00_set_field16(&reg, MAC_CSR19_DIR0, 0);
rt2500usb_register_write(rt2x00dev, MAC_CSR19, reg);
retval = rt2500usb_probe_hw_mode(rt2x00dev);
if (retval)
return retval;
__set_bit(REQUIRE_ATIM_QUEUE, &rt2x00dev->cap_flags);
__set_bit(REQUIRE_BEACON_GUARD, &rt2x00dev->cap_flags);
if (!modparam_nohwcrypt) {
__set_bit(CAPABILITY_HW_CRYPTO, &rt2x00dev->cap_flags);
__set_bit(REQUIRE_COPY_IV, &rt2x00dev->cap_flags);
}
__set_bit(REQUIRE_SW_SEQNO, &rt2x00dev->cap_flags);
__set_bit(REQUIRE_PS_AUTOWAKE, &rt2x00dev->cap_flags);
rt2x00dev->rssi_offset = DEFAULT_RSSI_OFFSET;
return 0;
}
static int rt2500usb_probe(struct usb_interface *usb_intf,
const struct usb_device_id *id)
{
return rt2x00usb_probe(usb_intf, &rt2500usb_ops);
}
