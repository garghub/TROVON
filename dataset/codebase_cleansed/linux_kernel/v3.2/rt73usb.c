static void rt73usb_bbp_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u8 value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, PHY_CSR3_VALUE, value);
rt2x00_set_field32(&reg, PHY_CSR3_REGNUM, word);
rt2x00_set_field32(&reg, PHY_CSR3_BUSY, 1);
rt2x00_set_field32(&reg, PHY_CSR3_READ_CONTROL, 0);
rt2x00usb_register_write_lock(rt2x00dev, PHY_CSR3, reg);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt73usb_bbp_read(struct rt2x00_dev *rt2x00dev,
const unsigned int word, u8 *value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, PHY_CSR3_REGNUM, word);
rt2x00_set_field32(&reg, PHY_CSR3_BUSY, 1);
rt2x00_set_field32(&reg, PHY_CSR3_READ_CONTROL, 1);
rt2x00usb_register_write_lock(rt2x00dev, PHY_CSR3, reg);
WAIT_FOR_BBP(rt2x00dev, &reg);
}
*value = rt2x00_get_field32(reg, PHY_CSR3_VALUE);
mutex_unlock(&rt2x00dev->csr_mutex);
}
static void rt73usb_rf_write(struct rt2x00_dev *rt2x00dev,
const unsigned int word, const u32 value)
{
u32 reg;
mutex_lock(&rt2x00dev->csr_mutex);
if (WAIT_FOR_RF(rt2x00dev, &reg)) {
reg = 0;
rt2x00_set_field32(&reg, PHY_CSR4_VALUE, value);
rt2x00_set_field32(&reg, PHY_CSR4_NUMBER_OF_BITS,
20 + (rt2x00_rf(rt2x00dev, RF5225) ||
rt2x00_rf(rt2x00dev, RF2527)));
rt2x00_set_field32(&reg, PHY_CSR4_IF_SELECT, 0);
rt2x00_set_field32(&reg, PHY_CSR4_BUSY, 1);
rt2x00usb_register_write_lock(rt2x00dev, PHY_CSR4, reg);
rt2x00_rf_write(rt2x00dev, word, value);
}
mutex_unlock(&rt2x00dev->csr_mutex);
}
static int rt73usb_rfkill_poll(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
rt2x00usb_register_read(rt2x00dev, MAC_CSR13, &reg);
return rt2x00_get_field32(reg, MAC_CSR13_BIT7);
}
static void rt73usb_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct rt2x00_led *led =
container_of(led_cdev, struct rt2x00_led, led_dev);
unsigned int enabled = brightness != LED_OFF;
unsigned int a_mode =
(enabled && led->rt2x00dev->curr_band == IEEE80211_BAND_5GHZ);
unsigned int bg_mode =
(enabled && led->rt2x00dev->curr_band == IEEE80211_BAND_2GHZ);
if (led->type == LED_TYPE_RADIO) {
rt2x00_set_field16(&led->rt2x00dev->led_mcu_reg,
MCU_LEDCS_RADIO_STATUS, enabled);
rt2x00usb_vendor_request_sw(led->rt2x00dev, USB_LED_CONTROL,
0, led->rt2x00dev->led_mcu_reg,
REGISTER_TIMEOUT);
} else if (led->type == LED_TYPE_ASSOC) {
rt2x00_set_field16(&led->rt2x00dev->led_mcu_reg,
MCU_LEDCS_LINK_BG_STATUS, bg_mode);
rt2x00_set_field16(&led->rt2x00dev->led_mcu_reg,
MCU_LEDCS_LINK_A_STATUS, a_mode);
rt2x00usb_vendor_request_sw(led->rt2x00dev, USB_LED_CONTROL,
0, led->rt2x00dev->led_mcu_reg,
REGISTER_TIMEOUT);
} else if (led->type == LED_TYPE_QUALITY) {
rt2x00usb_vendor_request_sw(led->rt2x00dev, USB_LED_CONTROL,
brightness / (LED_FULL / 6),
led->rt2x00dev->led_mcu_reg,
REGISTER_TIMEOUT);
}
}
static int rt73usb_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct rt2x00_led *led =
container_of(led_cdev, struct rt2x00_led, led_dev);
u32 reg;
rt2x00usb_register_read(led->rt2x00dev, MAC_CSR14, &reg);
rt2x00_set_field32(&reg, MAC_CSR14_ON_PERIOD, *delay_on);
rt2x00_set_field32(&reg, MAC_CSR14_OFF_PERIOD, *delay_off);
rt2x00usb_register_write(led->rt2x00dev, MAC_CSR14, reg);
return 0;
}
static void rt73usb_init_led(struct rt2x00_dev *rt2x00dev,
struct rt2x00_led *led,
enum led_type type)
{
led->rt2x00dev = rt2x00dev;
led->type = type;
led->led_dev.brightness_set = rt73usb_brightness_set;
led->led_dev.blink_set = rt73usb_blink_set;
led->flags = LED_INITIALIZED;
}
static int rt73usb_config_shared_key(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_crypto *crypto,
struct ieee80211_key_conf *key)
{
struct hw_key_entry key_entry;
struct rt2x00_field32 field;
u32 mask;
u32 reg;
if (crypto->cmd == SET_KEY) {
mask = (0xf << crypto->bssidx);
rt2x00usb_register_read(rt2x00dev, SEC_CSR0, &reg);
reg &= mask;
if (reg && reg == mask)
return -ENOSPC;
key->hw_key_idx += reg ? ffz(reg) : 0;
memcpy(key_entry.key, crypto->key,
sizeof(key_entry.key));
memcpy(key_entry.tx_mic, crypto->tx_mic,
sizeof(key_entry.tx_mic));
memcpy(key_entry.rx_mic, crypto->rx_mic,
sizeof(key_entry.rx_mic));
reg = SHARED_KEY_ENTRY(key->hw_key_idx);
rt2x00usb_register_multiwrite(rt2x00dev, reg,
&key_entry, sizeof(key_entry));
if (key->hw_key_idx < 8) {
field.bit_offset = (3 * key->hw_key_idx);
field.bit_mask = 0x7 << field.bit_offset;
rt2x00usb_register_read(rt2x00dev, SEC_CSR1, &reg);
rt2x00_set_field32(&reg, field, crypto->cipher);
rt2x00usb_register_write(rt2x00dev, SEC_CSR1, reg);
} else {
field.bit_offset = (3 * (key->hw_key_idx - 8));
field.bit_mask = 0x7 << field.bit_offset;
rt2x00usb_register_read(rt2x00dev, SEC_CSR5, &reg);
rt2x00_set_field32(&reg, field, crypto->cipher);
rt2x00usb_register_write(rt2x00dev, SEC_CSR5, reg);
}
key->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
}
mask = 1 << key->hw_key_idx;
rt2x00usb_register_read(rt2x00dev, SEC_CSR0, &reg);
if (crypto->cmd == SET_KEY)
reg |= mask;
else if (crypto->cmd == DISABLE_KEY)
reg &= ~mask;
rt2x00usb_register_write(rt2x00dev, SEC_CSR0, reg);
return 0;
}
static int rt73usb_config_pairwise_key(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_crypto *crypto,
struct ieee80211_key_conf *key)
{
struct hw_pairwise_ta_entry addr_entry;
struct hw_key_entry key_entry;
u32 mask;
u32 reg;
if (crypto->cmd == SET_KEY) {
rt2x00usb_register_read(rt2x00dev, SEC_CSR2, &reg);
if (reg && reg == ~0) {
key->hw_key_idx = 32;
rt2x00usb_register_read(rt2x00dev, SEC_CSR3, &reg);
if (reg && reg == ~0)
return -ENOSPC;
}
key->hw_key_idx += reg ? ffz(reg) : 0;
memcpy(key_entry.key, crypto->key,
sizeof(key_entry.key));
memcpy(key_entry.tx_mic, crypto->tx_mic,
sizeof(key_entry.tx_mic));
memcpy(key_entry.rx_mic, crypto->rx_mic,
sizeof(key_entry.rx_mic));
reg = PAIRWISE_KEY_ENTRY(key->hw_key_idx);
rt2x00usb_register_multiwrite(rt2x00dev, reg,
&key_entry, sizeof(key_entry));
memset(&addr_entry, 0, sizeof(addr_entry));
memcpy(&addr_entry, crypto->address, ETH_ALEN);
addr_entry.cipher = crypto->cipher;
reg = PAIRWISE_TA_ENTRY(key->hw_key_idx);
rt2x00usb_register_multiwrite(rt2x00dev, reg,
&addr_entry, sizeof(addr_entry));
rt2x00usb_register_read(rt2x00dev, SEC_CSR4, &reg);
reg |= (1 << crypto->bssidx);
rt2x00usb_register_write(rt2x00dev, SEC_CSR4, reg);
key->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
}
if (key->hw_key_idx < 32) {
mask = 1 << key->hw_key_idx;
rt2x00usb_register_read(rt2x00dev, SEC_CSR2, &reg);
if (crypto->cmd == SET_KEY)
reg |= mask;
else if (crypto->cmd == DISABLE_KEY)
reg &= ~mask;
rt2x00usb_register_write(rt2x00dev, SEC_CSR2, reg);
} else {
mask = 1 << (key->hw_key_idx - 32);
rt2x00usb_register_read(rt2x00dev, SEC_CSR3, &reg);
if (crypto->cmd == SET_KEY)
reg |= mask;
else if (crypto->cmd == DISABLE_KEY)
reg &= ~mask;
rt2x00usb_register_write(rt2x00dev, SEC_CSR3, reg);
}
return 0;
}
static void rt73usb_config_filter(struct rt2x00_dev *rt2x00dev,
const unsigned int filter_flags)
{
u32 reg;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_CRC,
!(filter_flags & FIF_FCSFAIL));
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_PHYSICAL,
!(filter_flags & FIF_PLCPFAIL));
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_CONTROL,
!(filter_flags & (FIF_CONTROL | FIF_PSPOLL)));
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_NOT_TO_ME,
!(filter_flags & FIF_PROMISC_IN_BSS));
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_TO_DS,
!(filter_flags & FIF_PROMISC_IN_BSS) &&
!rt2x00dev->intf_ap_count);
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_VERSION_ERROR, 1);
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_MULTICAST,
!(filter_flags & FIF_ALLMULTI));
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_BROADCAST, 0);
rt2x00_set_field32(&reg, TXRX_CSR0_DROP_ACK_CTS,
!(filter_flags & FIF_CONTROL));
rt2x00usb_register_write(rt2x00dev, TXRX_CSR0, reg);
}
static void rt73usb_config_intf(struct rt2x00_dev *rt2x00dev,
struct rt2x00_intf *intf,
struct rt2x00intf_conf *conf,
const unsigned int flags)
{
u32 reg;
if (flags & CONFIG_UPDATE_TYPE) {
rt2x00usb_register_read(rt2x00dev, TXRX_CSR9, &reg);
rt2x00_set_field32(&reg, TXRX_CSR9_TSF_SYNC, conf->sync);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
}
if (flags & CONFIG_UPDATE_MAC) {
reg = le32_to_cpu(conf->mac[1]);
rt2x00_set_field32(&reg, MAC_CSR3_UNICAST_TO_ME_MASK, 0xff);
conf->mac[1] = cpu_to_le32(reg);
rt2x00usb_register_multiwrite(rt2x00dev, MAC_CSR2,
conf->mac, sizeof(conf->mac));
}
if (flags & CONFIG_UPDATE_BSSID) {
reg = le32_to_cpu(conf->bssid[1]);
rt2x00_set_field32(&reg, MAC_CSR5_BSS_ID_MASK, 3);
conf->bssid[1] = cpu_to_le32(reg);
rt2x00usb_register_multiwrite(rt2x00dev, MAC_CSR4,
conf->bssid, sizeof(conf->bssid));
}
}
static void rt73usb_config_erp(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_erp *erp,
u32 changed)
{
u32 reg;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
rt2x00_set_field32(&reg, TXRX_CSR0_RX_ACK_TIMEOUT, 0x32);
rt2x00_set_field32(&reg, TXRX_CSR0_TSF_OFFSET, IEEE80211_HEADER);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR0, reg);
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
rt2x00usb_register_read(rt2x00dev, TXRX_CSR4, &reg);
rt2x00_set_field32(&reg, TXRX_CSR4_AUTORESPOND_ENABLE, 1);
rt2x00_set_field32(&reg, TXRX_CSR4_AUTORESPOND_PREAMBLE,
!!erp->short_preamble);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR4, reg);
}
if (changed & BSS_CHANGED_BASIC_RATES)
rt2x00usb_register_write(rt2x00dev, TXRX_CSR5,
erp->basic_rates);
if (changed & BSS_CHANGED_BEACON_INT) {
rt2x00usb_register_read(rt2x00dev, TXRX_CSR9, &reg);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_INTERVAL,
erp->beacon_int * 16);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
}
if (changed & BSS_CHANGED_ERP_SLOT) {
rt2x00usb_register_read(rt2x00dev, MAC_CSR9, &reg);
rt2x00_set_field32(&reg, MAC_CSR9_SLOT_TIME, erp->slot_time);
rt2x00usb_register_write(rt2x00dev, MAC_CSR9, reg);
rt2x00usb_register_read(rt2x00dev, MAC_CSR8, &reg);
rt2x00_set_field32(&reg, MAC_CSR8_SIFS, erp->sifs);
rt2x00_set_field32(&reg, MAC_CSR8_SIFS_AFTER_RX_OFDM, 3);
rt2x00_set_field32(&reg, MAC_CSR8_EIFS, erp->eifs);
rt2x00usb_register_write(rt2x00dev, MAC_CSR8, reg);
}
}
static void rt73usb_config_antenna_5x(struct rt2x00_dev *rt2x00dev,
struct antenna_setup *ant)
{
u8 r3;
u8 r4;
u8 r77;
u8 temp;
rt73usb_bbp_read(rt2x00dev, 3, &r3);
rt73usb_bbp_read(rt2x00dev, 4, &r4);
rt73usb_bbp_read(rt2x00dev, 77, &r77);
rt2x00_set_field8(&r3, BBP_R3_SMART_MODE, 0);
switch (ant->rx) {
case ANTENNA_HW_DIVERSITY:
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA_CONTROL, 2);
temp = !test_bit(CAPABILITY_FRAME_TYPE, &rt2x00dev->cap_flags)
&& (rt2x00dev->curr_band != IEEE80211_BAND_5GHZ);
rt2x00_set_field8(&r4, BBP_R4_RX_FRAME_END, temp);
break;
case ANTENNA_A:
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA_CONTROL, 1);
rt2x00_set_field8(&r4, BBP_R4_RX_FRAME_END, 0);
if (rt2x00dev->curr_band == IEEE80211_BAND_5GHZ)
rt2x00_set_field8(&r77, BBP_R77_RX_ANTENNA, 0);
else
rt2x00_set_field8(&r77, BBP_R77_RX_ANTENNA, 3);
break;
case ANTENNA_B:
default:
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA_CONTROL, 1);
rt2x00_set_field8(&r4, BBP_R4_RX_FRAME_END, 0);
if (rt2x00dev->curr_band == IEEE80211_BAND_5GHZ)
rt2x00_set_field8(&r77, BBP_R77_RX_ANTENNA, 3);
else
rt2x00_set_field8(&r77, BBP_R77_RX_ANTENNA, 0);
break;
}
rt73usb_bbp_write(rt2x00dev, 77, r77);
rt73usb_bbp_write(rt2x00dev, 3, r3);
rt73usb_bbp_write(rt2x00dev, 4, r4);
}
static void rt73usb_config_antenna_2x(struct rt2x00_dev *rt2x00dev,
struct antenna_setup *ant)
{
u8 r3;
u8 r4;
u8 r77;
rt73usb_bbp_read(rt2x00dev, 3, &r3);
rt73usb_bbp_read(rt2x00dev, 4, &r4);
rt73usb_bbp_read(rt2x00dev, 77, &r77);
rt2x00_set_field8(&r3, BBP_R3_SMART_MODE, 0);
rt2x00_set_field8(&r4, BBP_R4_RX_FRAME_END,
!test_bit(CAPABILITY_FRAME_TYPE, &rt2x00dev->cap_flags));
switch (ant->rx) {
case ANTENNA_HW_DIVERSITY:
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA_CONTROL, 2);
break;
case ANTENNA_A:
rt2x00_set_field8(&r77, BBP_R77_RX_ANTENNA, 3);
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA_CONTROL, 1);
break;
case ANTENNA_B:
default:
rt2x00_set_field8(&r77, BBP_R77_RX_ANTENNA, 0);
rt2x00_set_field8(&r4, BBP_R4_RX_ANTENNA_CONTROL, 1);
break;
}
rt73usb_bbp_write(rt2x00dev, 77, r77);
rt73usb_bbp_write(rt2x00dev, 3, r3);
rt73usb_bbp_write(rt2x00dev, 4, r4);
}
static void rt73usb_config_ant(struct rt2x00_dev *rt2x00dev,
struct antenna_setup *ant)
{
const struct antenna_sel *sel;
unsigned int lna;
unsigned int i;
u32 reg;
BUG_ON(ant->rx == ANTENNA_SW_DIVERSITY ||
ant->tx == ANTENNA_SW_DIVERSITY);
if (rt2x00dev->curr_band == IEEE80211_BAND_5GHZ) {
sel = antenna_sel_a;
lna = test_bit(CAPABILITY_EXTERNAL_LNA_A, &rt2x00dev->cap_flags);
} else {
sel = antenna_sel_bg;
lna = test_bit(CAPABILITY_EXTERNAL_LNA_BG, &rt2x00dev->cap_flags);
}
for (i = 0; i < ARRAY_SIZE(antenna_sel_a); i++)
rt73usb_bbp_write(rt2x00dev, sel[i].word, sel[i].value[lna]);
rt2x00usb_register_read(rt2x00dev, PHY_CSR0, &reg);
rt2x00_set_field32(&reg, PHY_CSR0_PA_PE_BG,
(rt2x00dev->curr_band == IEEE80211_BAND_2GHZ));
rt2x00_set_field32(&reg, PHY_CSR0_PA_PE_A,
(rt2x00dev->curr_band == IEEE80211_BAND_5GHZ));
rt2x00usb_register_write(rt2x00dev, PHY_CSR0, reg);
if (rt2x00_rf(rt2x00dev, RF5226) || rt2x00_rf(rt2x00dev, RF5225))
rt73usb_config_antenna_5x(rt2x00dev, ant);
else if (rt2x00_rf(rt2x00dev, RF2528) || rt2x00_rf(rt2x00dev, RF2527))
rt73usb_config_antenna_2x(rt2x00dev, ant);
}
static void rt73usb_config_lna_gain(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
u16 eeprom;
short lna_gain = 0;
if (libconf->conf->channel->band == IEEE80211_BAND_2GHZ) {
if (test_bit(CAPABILITY_EXTERNAL_LNA_BG, &rt2x00dev->cap_flags))
lna_gain += 14;
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_OFFSET_BG, &eeprom);
lna_gain -= rt2x00_get_field16(eeprom, EEPROM_RSSI_OFFSET_BG_1);
} else {
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_OFFSET_A, &eeprom);
lna_gain -= rt2x00_get_field16(eeprom, EEPROM_RSSI_OFFSET_A_1);
}
rt2x00dev->lna_gain = lna_gain;
}
static void rt73usb_config_channel(struct rt2x00_dev *rt2x00dev,
struct rf_channel *rf, const int txpower)
{
u8 r3;
u8 r94;
u8 smart;
rt2x00_set_field32(&rf->rf3, RF3_TXPOWER, TXPOWER_TO_DEV(txpower));
rt2x00_set_field32(&rf->rf4, RF4_FREQ_OFFSET, rt2x00dev->freq_offset);
smart = !(rt2x00_rf(rt2x00dev, RF5225) || rt2x00_rf(rt2x00dev, RF2527));
rt73usb_bbp_read(rt2x00dev, 3, &r3);
rt2x00_set_field8(&r3, BBP_R3_SMART_MODE, smart);
rt73usb_bbp_write(rt2x00dev, 3, r3);
r94 = 6;
if (txpower > MAX_TXPOWER && txpower <= (MAX_TXPOWER + r94))
r94 += txpower - MAX_TXPOWER;
else if (txpower < MIN_TXPOWER && txpower >= (MIN_TXPOWER - r94))
r94 += txpower;
rt73usb_bbp_write(rt2x00dev, 94, r94);
rt73usb_rf_write(rt2x00dev, 1, rf->rf1);
rt73usb_rf_write(rt2x00dev, 2, rf->rf2);
rt73usb_rf_write(rt2x00dev, 3, rf->rf3 & ~0x00000004);
rt73usb_rf_write(rt2x00dev, 4, rf->rf4);
rt73usb_rf_write(rt2x00dev, 1, rf->rf1);
rt73usb_rf_write(rt2x00dev, 2, rf->rf2);
rt73usb_rf_write(rt2x00dev, 3, rf->rf3 | 0x00000004);
rt73usb_rf_write(rt2x00dev, 4, rf->rf4);
rt73usb_rf_write(rt2x00dev, 1, rf->rf1);
rt73usb_rf_write(rt2x00dev, 2, rf->rf2);
rt73usb_rf_write(rt2x00dev, 3, rf->rf3 & ~0x00000004);
rt73usb_rf_write(rt2x00dev, 4, rf->rf4);
udelay(10);
}
static void rt73usb_config_txpower(struct rt2x00_dev *rt2x00dev,
const int txpower)
{
struct rf_channel rf;
rt2x00_rf_read(rt2x00dev, 1, &rf.rf1);
rt2x00_rf_read(rt2x00dev, 2, &rf.rf2);
rt2x00_rf_read(rt2x00dev, 3, &rf.rf3);
rt2x00_rf_read(rt2x00dev, 4, &rf.rf4);
rt73usb_config_channel(rt2x00dev, &rf, txpower);
}
static void rt73usb_config_retry_limit(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
u32 reg;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR4, &reg);
rt2x00_set_field32(&reg, TXRX_CSR4_OFDM_TX_RATE_DOWN, 1);
rt2x00_set_field32(&reg, TXRX_CSR4_OFDM_TX_RATE_STEP, 0);
rt2x00_set_field32(&reg, TXRX_CSR4_OFDM_TX_FALLBACK_CCK, 0);
rt2x00_set_field32(&reg, TXRX_CSR4_LONG_RETRY_LIMIT,
libconf->conf->long_frame_max_tx_count);
rt2x00_set_field32(&reg, TXRX_CSR4_SHORT_RETRY_LIMIT,
libconf->conf->short_frame_max_tx_count);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR4, reg);
}
static void rt73usb_config_ps(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf)
{
enum dev_state state =
(libconf->conf->flags & IEEE80211_CONF_PS) ?
STATE_SLEEP : STATE_AWAKE;
u32 reg;
if (state == STATE_SLEEP) {
rt2x00usb_register_read(rt2x00dev, MAC_CSR11, &reg);
rt2x00_set_field32(&reg, MAC_CSR11_DELAY_AFTER_TBCN,
rt2x00dev->beacon_int - 10);
rt2x00_set_field32(&reg, MAC_CSR11_TBCN_BEFORE_WAKEUP,
libconf->conf->listen_interval - 1);
rt2x00_set_field32(&reg, MAC_CSR11_WAKEUP_LATENCY, 5);
rt2x00_set_field32(&reg, MAC_CSR11_AUTOWAKE, 0);
rt2x00usb_register_write(rt2x00dev, MAC_CSR11, reg);
rt2x00_set_field32(&reg, MAC_CSR11_AUTOWAKE, 1);
rt2x00usb_register_write(rt2x00dev, MAC_CSR11, reg);
rt2x00usb_vendor_request_sw(rt2x00dev, USB_DEVICE_MODE, 0,
USB_MODE_SLEEP, REGISTER_TIMEOUT);
} else {
rt2x00usb_register_read(rt2x00dev, MAC_CSR11, &reg);
rt2x00_set_field32(&reg, MAC_CSR11_DELAY_AFTER_TBCN, 0);
rt2x00_set_field32(&reg, MAC_CSR11_TBCN_BEFORE_WAKEUP, 0);
rt2x00_set_field32(&reg, MAC_CSR11_AUTOWAKE, 0);
rt2x00_set_field32(&reg, MAC_CSR11_WAKEUP_LATENCY, 0);
rt2x00usb_register_write(rt2x00dev, MAC_CSR11, reg);
rt2x00usb_vendor_request_sw(rt2x00dev, USB_DEVICE_MODE, 0,
USB_MODE_WAKEUP, REGISTER_TIMEOUT);
}
}
static void rt73usb_config(struct rt2x00_dev *rt2x00dev,
struct rt2x00lib_conf *libconf,
const unsigned int flags)
{
rt73usb_config_lna_gain(rt2x00dev, libconf);
if (flags & IEEE80211_CONF_CHANGE_CHANNEL)
rt73usb_config_channel(rt2x00dev, &libconf->rf,
libconf->conf->power_level);
if ((flags & IEEE80211_CONF_CHANGE_POWER) &&
!(flags & IEEE80211_CONF_CHANGE_CHANNEL))
rt73usb_config_txpower(rt2x00dev, libconf->conf->power_level);
if (flags & IEEE80211_CONF_CHANGE_RETRY_LIMITS)
rt73usb_config_retry_limit(rt2x00dev, libconf);
if (flags & IEEE80211_CONF_CHANGE_PS)
rt73usb_config_ps(rt2x00dev, libconf);
}
static void rt73usb_link_stats(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual)
{
u32 reg;
rt2x00usb_register_read(rt2x00dev, STA_CSR0, &reg);
qual->rx_failed = rt2x00_get_field32(reg, STA_CSR0_FCS_ERROR);
rt2x00usb_register_read(rt2x00dev, STA_CSR1, &reg);
qual->false_cca = rt2x00_get_field32(reg, STA_CSR1_FALSE_CCA_ERROR);
}
static inline void rt73usb_set_vgc(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual, u8 vgc_level)
{
if (qual->vgc_level != vgc_level) {
rt73usb_bbp_write(rt2x00dev, 17, vgc_level);
qual->vgc_level = vgc_level;
qual->vgc_level_reg = vgc_level;
}
}
static void rt73usb_reset_tuner(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual)
{
rt73usb_set_vgc(rt2x00dev, qual, 0x20);
}
static void rt73usb_link_tuner(struct rt2x00_dev *rt2x00dev,
struct link_qual *qual, const u32 count)
{
u8 up_bound;
u8 low_bound;
if (rt2x00dev->curr_band == IEEE80211_BAND_5GHZ) {
low_bound = 0x28;
up_bound = 0x48;
if (test_bit(CAPABILITY_EXTERNAL_LNA_A, &rt2x00dev->cap_flags)) {
low_bound += 0x10;
up_bound += 0x10;
}
} else {
if (qual->rssi > -82) {
low_bound = 0x1c;
up_bound = 0x40;
} else if (qual->rssi > -84) {
low_bound = 0x1c;
up_bound = 0x20;
} else {
low_bound = 0x1c;
up_bound = 0x1c;
}
if (test_bit(CAPABILITY_EXTERNAL_LNA_BG, &rt2x00dev->cap_flags)) {
low_bound += 0x14;
up_bound += 0x10;
}
}
if (!rt2x00dev->intf_associated)
goto dynamic_cca_tune;
if (qual->rssi > -35) {
rt73usb_set_vgc(rt2x00dev, qual, 0x60);
return;
}
if (qual->rssi >= -58) {
rt73usb_set_vgc(rt2x00dev, qual, up_bound);
return;
}
if (qual->rssi >= -66) {
rt73usb_set_vgc(rt2x00dev, qual, low_bound + 0x10);
return;
}
if (qual->rssi >= -74) {
rt73usb_set_vgc(rt2x00dev, qual, low_bound + 0x08);
return;
}
up_bound -= 2 * (-74 - qual->rssi);
if (low_bound > up_bound)
up_bound = low_bound;
if (qual->vgc_level > up_bound) {
rt73usb_set_vgc(rt2x00dev, qual, up_bound);
return;
}
dynamic_cca_tune:
if ((qual->false_cca > 512) && (qual->vgc_level < up_bound))
rt73usb_set_vgc(rt2x00dev, qual,
min_t(u8, qual->vgc_level + 4, up_bound));
else if ((qual->false_cca < 100) && (qual->vgc_level > low_bound))
rt73usb_set_vgc(rt2x00dev, qual,
max_t(u8, qual->vgc_level - 4, low_bound));
}
static void rt73usb_start_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_RX:
rt2x00usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
rt2x00_set_field32(&reg, TXRX_CSR0_DISABLE_RX, 0);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR0, reg);
break;
case QID_BEACON:
rt2x00usb_register_read(rt2x00dev, TXRX_CSR9, &reg);
rt2x00_set_field32(&reg, TXRX_CSR9_TSF_TICKING, 1);
rt2x00_set_field32(&reg, TXRX_CSR9_TBTT_ENABLE, 1);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 1);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
break;
default:
break;
}
}
static void rt73usb_stop_queue(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
u32 reg;
switch (queue->qid) {
case QID_RX:
rt2x00usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
rt2x00_set_field32(&reg, TXRX_CSR0_DISABLE_RX, 1);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR0, reg);
break;
case QID_BEACON:
rt2x00usb_register_read(rt2x00dev, TXRX_CSR9, &reg);
rt2x00_set_field32(&reg, TXRX_CSR9_TSF_TICKING, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_TBTT_ENABLE, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 0);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
break;
default:
break;
}
}
static char *rt73usb_get_firmware_name(struct rt2x00_dev *rt2x00dev)
{
return FIRMWARE_RT2571;
}
static int rt73usb_check_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
u16 fw_crc;
u16 crc;
if (len != 2048)
return FW_BAD_LENGTH;
fw_crc = (data[len - 2] << 8 | data[len - 1]);
crc = crc_itu_t(0, data, len - 2);
crc = crc_itu_t_byte(crc, 0);
crc = crc_itu_t_byte(crc, 0);
return (fw_crc == crc) ? FW_OK : FW_BAD_CRC;
}
static int rt73usb_load_firmware(struct rt2x00_dev *rt2x00dev,
const u8 *data, const size_t len)
{
unsigned int i;
int status;
u32 reg;
for (i = 0; i < 100; i++) {
rt2x00usb_register_read(rt2x00dev, MAC_CSR0, &reg);
if (reg)
break;
msleep(1);
}
if (!reg) {
ERROR(rt2x00dev, "Unstable hardware.\n");
return -EBUSY;
}
rt2x00usb_register_multiwrite(rt2x00dev, FIRMWARE_IMAGE_BASE, data, len);
status = rt2x00usb_vendor_request_sw(rt2x00dev, USB_DEVICE_MODE,
0, USB_MODE_FIRMWARE,
REGISTER_TIMEOUT_FIRMWARE);
if (status < 0) {
ERROR(rt2x00dev, "Failed to write Firmware to device.\n");
return status;
}
return 0;
}
static int rt73usb_init_registers(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR0, &reg);
rt2x00_set_field32(&reg, TXRX_CSR0_AUTO_TX_SEQ, 1);
rt2x00_set_field32(&reg, TXRX_CSR0_DISABLE_RX, 0);
rt2x00_set_field32(&reg, TXRX_CSR0_TX_WITHOUT_WAITING, 0);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR0, reg);
rt2x00usb_register_read(rt2x00dev, TXRX_CSR1, &reg);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID0, 47);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID0_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID1, 30);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID1_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID2, 42);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID2_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID3, 30);
rt2x00_set_field32(&reg, TXRX_CSR1_BBP_ID3_VALID, 1);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR1, reg);
rt2x00usb_register_read(rt2x00dev, TXRX_CSR2, &reg);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID0, 13);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID0_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID1, 12);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID1_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID2, 11);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID2_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID3, 10);
rt2x00_set_field32(&reg, TXRX_CSR2_BBP_ID3_VALID, 1);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR2, reg);
rt2x00usb_register_read(rt2x00dev, TXRX_CSR3, &reg);
rt2x00_set_field32(&reg, TXRX_CSR3_BBP_ID0, 7);
rt2x00_set_field32(&reg, TXRX_CSR3_BBP_ID0_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR3_BBP_ID1, 6);
rt2x00_set_field32(&reg, TXRX_CSR3_BBP_ID1_VALID, 1);
rt2x00_set_field32(&reg, TXRX_CSR3_BBP_ID2, 5);
rt2x00_set_field32(&reg, TXRX_CSR3_BBP_ID2_VALID, 1);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR3, reg);
rt2x00usb_register_read(rt2x00dev, TXRX_CSR7, &reg);
rt2x00_set_field32(&reg, TXRX_CSR7_ACK_CTS_6MBS, 59);
rt2x00_set_field32(&reg, TXRX_CSR7_ACK_CTS_9MBS, 53);
rt2x00_set_field32(&reg, TXRX_CSR7_ACK_CTS_12MBS, 49);
rt2x00_set_field32(&reg, TXRX_CSR7_ACK_CTS_18MBS, 46);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR7, reg);
rt2x00usb_register_read(rt2x00dev, TXRX_CSR8, &reg);
rt2x00_set_field32(&reg, TXRX_CSR8_ACK_CTS_24MBS, 44);
rt2x00_set_field32(&reg, TXRX_CSR8_ACK_CTS_36MBS, 42);
rt2x00_set_field32(&reg, TXRX_CSR8_ACK_CTS_48MBS, 42);
rt2x00_set_field32(&reg, TXRX_CSR8_ACK_CTS_54MBS, 42);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR8, reg);
rt2x00usb_register_read(rt2x00dev, TXRX_CSR9, &reg);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_INTERVAL, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_TSF_TICKING, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_TSF_SYNC, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_TBTT_ENABLE, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_TIMESTAMP_COMPENSATE, 0);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR15, 0x0000000f);
rt2x00usb_register_read(rt2x00dev, MAC_CSR6, &reg);
rt2x00_set_field32(&reg, MAC_CSR6_MAX_FRAME_UNIT, 0xfff);
rt2x00usb_register_write(rt2x00dev, MAC_CSR6, reg);
rt2x00usb_register_write(rt2x00dev, MAC_CSR10, 0x00000718);
if (rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_AWAKE))
return -EBUSY;
rt2x00usb_register_write(rt2x00dev, MAC_CSR13, 0x00007f00);
rt2x00usb_register_write(rt2x00dev, SEC_CSR0, 0x00000000);
rt2x00usb_register_write(rt2x00dev, SEC_CSR1, 0x00000000);
rt2x00usb_register_write(rt2x00dev, SEC_CSR5, 0x00000000);
reg = 0x000023b0;
if (rt2x00_rf(rt2x00dev, RF5225) || rt2x00_rf(rt2x00dev, RF2527))
rt2x00_set_field32(&reg, PHY_CSR1_RF_RPI, 1);
rt2x00usb_register_write(rt2x00dev, PHY_CSR1, reg);
rt2x00usb_register_write(rt2x00dev, PHY_CSR5, 0x00040a06);
rt2x00usb_register_write(rt2x00dev, PHY_CSR6, 0x00080606);
rt2x00usb_register_write(rt2x00dev, PHY_CSR7, 0x00000408);
rt2x00usb_register_read(rt2x00dev, MAC_CSR9, &reg);
rt2x00_set_field32(&reg, MAC_CSR9_CW_SELECT, 0);
rt2x00usb_register_write(rt2x00dev, MAC_CSR9, reg);
rt2x00usb_register_write(rt2x00dev, HW_BEACON_BASE0, 0);
rt2x00usb_register_write(rt2x00dev, HW_BEACON_BASE1, 0);
rt2x00usb_register_write(rt2x00dev, HW_BEACON_BASE2, 0);
rt2x00usb_register_write(rt2x00dev, HW_BEACON_BASE3, 0);
rt2x00usb_register_read(rt2x00dev, STA_CSR0, &reg);
rt2x00usb_register_read(rt2x00dev, STA_CSR1, &reg);
rt2x00usb_register_read(rt2x00dev, STA_CSR2, &reg);
rt2x00usb_register_read(rt2x00dev, MAC_CSR1, &reg);
rt2x00_set_field32(&reg, MAC_CSR1_SOFT_RESET, 1);
rt2x00_set_field32(&reg, MAC_CSR1_BBP_RESET, 1);
rt2x00usb_register_write(rt2x00dev, MAC_CSR1, reg);
rt2x00usb_register_read(rt2x00dev, MAC_CSR1, &reg);
rt2x00_set_field32(&reg, MAC_CSR1_SOFT_RESET, 0);
rt2x00_set_field32(&reg, MAC_CSR1_BBP_RESET, 0);
rt2x00usb_register_write(rt2x00dev, MAC_CSR1, reg);
rt2x00usb_register_read(rt2x00dev, MAC_CSR1, &reg);
rt2x00_set_field32(&reg, MAC_CSR1_HOST_READY, 1);
rt2x00usb_register_write(rt2x00dev, MAC_CSR1, reg);
return 0;
}
static int rt73usb_wait_bbp_ready(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u8 value;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt73usb_bbp_read(rt2x00dev, 0, &value);
if ((value != 0xff) && (value != 0x00))
return 0;
udelay(REGISTER_BUSY_DELAY);
}
ERROR(rt2x00dev, "BBP register access failed, aborting.\n");
return -EACCES;
}
static int rt73usb_init_bbp(struct rt2x00_dev *rt2x00dev)
{
unsigned int i;
u16 eeprom;
u8 reg_id;
u8 value;
if (unlikely(rt73usb_wait_bbp_ready(rt2x00dev)))
return -EACCES;
rt73usb_bbp_write(rt2x00dev, 3, 0x80);
rt73usb_bbp_write(rt2x00dev, 15, 0x30);
rt73usb_bbp_write(rt2x00dev, 21, 0xc8);
rt73usb_bbp_write(rt2x00dev, 22, 0x38);
rt73usb_bbp_write(rt2x00dev, 23, 0x06);
rt73usb_bbp_write(rt2x00dev, 24, 0xfe);
rt73usb_bbp_write(rt2x00dev, 25, 0x0a);
rt73usb_bbp_write(rt2x00dev, 26, 0x0d);
rt73usb_bbp_write(rt2x00dev, 32, 0x0b);
rt73usb_bbp_write(rt2x00dev, 34, 0x12);
rt73usb_bbp_write(rt2x00dev, 37, 0x07);
rt73usb_bbp_write(rt2x00dev, 39, 0xf8);
rt73usb_bbp_write(rt2x00dev, 41, 0x60);
rt73usb_bbp_write(rt2x00dev, 53, 0x10);
rt73usb_bbp_write(rt2x00dev, 54, 0x18);
rt73usb_bbp_write(rt2x00dev, 60, 0x10);
rt73usb_bbp_write(rt2x00dev, 61, 0x04);
rt73usb_bbp_write(rt2x00dev, 62, 0x04);
rt73usb_bbp_write(rt2x00dev, 75, 0xfe);
rt73usb_bbp_write(rt2x00dev, 86, 0xfe);
rt73usb_bbp_write(rt2x00dev, 88, 0xfe);
rt73usb_bbp_write(rt2x00dev, 90, 0x0f);
rt73usb_bbp_write(rt2x00dev, 99, 0x00);
rt73usb_bbp_write(rt2x00dev, 102, 0x16);
rt73usb_bbp_write(rt2x00dev, 107, 0x04);
for (i = 0; i < EEPROM_BBP_SIZE; i++) {
rt2x00_eeprom_read(rt2x00dev, EEPROM_BBP_START + i, &eeprom);
if (eeprom != 0xffff && eeprom != 0x0000) {
reg_id = rt2x00_get_field16(eeprom, EEPROM_BBP_REG_ID);
value = rt2x00_get_field16(eeprom, EEPROM_BBP_VALUE);
rt73usb_bbp_write(rt2x00dev, reg_id, value);
}
}
return 0;
}
static int rt73usb_enable_radio(struct rt2x00_dev *rt2x00dev)
{
if (unlikely(rt73usb_init_registers(rt2x00dev) ||
rt73usb_init_bbp(rt2x00dev)))
return -EIO;
return 0;
}
static void rt73usb_disable_radio(struct rt2x00_dev *rt2x00dev)
{
rt2x00usb_register_write(rt2x00dev, MAC_CSR10, 0x00001818);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, 0);
rt2x00usb_disable_radio(rt2x00dev);
}
static int rt73usb_set_state(struct rt2x00_dev *rt2x00dev, enum dev_state state)
{
u32 reg, reg2;
unsigned int i;
char put_to_sleep;
put_to_sleep = (state != STATE_AWAKE);
rt2x00usb_register_read(rt2x00dev, MAC_CSR12, &reg);
rt2x00_set_field32(&reg, MAC_CSR12_FORCE_WAKEUP, !put_to_sleep);
rt2x00_set_field32(&reg, MAC_CSR12_PUT_TO_SLEEP, put_to_sleep);
rt2x00usb_register_write(rt2x00dev, MAC_CSR12, reg);
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2x00usb_register_read(rt2x00dev, MAC_CSR12, &reg2);
state = rt2x00_get_field32(reg2, MAC_CSR12_BBP_CURRENT_STATE);
if (state == !put_to_sleep)
return 0;
rt2x00usb_register_write(rt2x00dev, MAC_CSR12, reg);
msleep(10);
}
return -EBUSY;
}
static int rt73usb_set_device_state(struct rt2x00_dev *rt2x00dev,
enum dev_state state)
{
int retval = 0;
switch (state) {
case STATE_RADIO_ON:
retval = rt73usb_enable_radio(rt2x00dev);
break;
case STATE_RADIO_OFF:
rt73usb_disable_radio(rt2x00dev);
break;
case STATE_RADIO_IRQ_ON:
case STATE_RADIO_IRQ_OFF:
break;
case STATE_DEEP_SLEEP:
case STATE_SLEEP:
case STATE_STANDBY:
case STATE_AWAKE:
retval = rt73usb_set_state(rt2x00dev, state);
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
static void rt73usb_write_tx_desc(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
__le32 *txd = (__le32 *) entry->skb->data;
u32 word;
rt2x00_desc_read(txd, 0, &word);
rt2x00_set_field32(&word, TXD_W0_BURST,
test_bit(ENTRY_TXD_BURST, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_VALID, 1);
rt2x00_set_field32(&word, TXD_W0_MORE_FRAG,
test_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_ACK,
test_bit(ENTRY_TXD_ACK, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_TIMESTAMP,
test_bit(ENTRY_TXD_REQ_TIMESTAMP, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_OFDM,
(txdesc->rate_mode == RATE_MODE_OFDM));
rt2x00_set_field32(&word, TXD_W0_IFS, txdesc->u.plcp.ifs);
rt2x00_set_field32(&word, TXD_W0_RETRY_MODE,
test_bit(ENTRY_TXD_RETRY_MODE, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_TKIP_MIC,
test_bit(ENTRY_TXD_ENCRYPT_MMIC, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_KEY_TABLE,
test_bit(ENTRY_TXD_ENCRYPT_PAIRWISE, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_KEY_INDEX, txdesc->key_idx);
rt2x00_set_field32(&word, TXD_W0_DATABYTE_COUNT, txdesc->length);
rt2x00_set_field32(&word, TXD_W0_BURST2,
test_bit(ENTRY_TXD_BURST, &txdesc->flags));
rt2x00_set_field32(&word, TXD_W0_CIPHER_ALG, txdesc->cipher);
rt2x00_desc_write(txd, 0, word);
rt2x00_desc_read(txd, 1, &word);
rt2x00_set_field32(&word, TXD_W1_HOST_Q_ID, entry->queue->qid);
rt2x00_set_field32(&word, TXD_W1_AIFSN, entry->queue->aifs);
rt2x00_set_field32(&word, TXD_W1_CWMIN, entry->queue->cw_min);
rt2x00_set_field32(&word, TXD_W1_CWMAX, entry->queue->cw_max);
rt2x00_set_field32(&word, TXD_W1_IV_OFFSET, txdesc->iv_offset);
rt2x00_set_field32(&word, TXD_W1_HW_SEQUENCE,
test_bit(ENTRY_TXD_GENERATE_SEQ, &txdesc->flags));
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
rt2x00_desc_read(txd, 5, &word);
rt2x00_set_field32(&word, TXD_W5_TX_POWER,
TXPOWER_TO_DEV(entry->queue->rt2x00dev->tx_power));
rt2x00_set_field32(&word, TXD_W5_WAITING_DMA_DONE_INT, 1);
rt2x00_desc_write(txd, 5, word);
skbdesc->flags |= SKBDESC_DESC_IN_SKB;
skbdesc->desc = txd;
skbdesc->desc_len = TXD_DESC_SIZE;
}
static void rt73usb_write_beacon(struct queue_entry *entry,
struct txentry_desc *txdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
unsigned int beacon_base;
unsigned int padding_len;
u32 orig_reg, reg;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR9, &reg);
orig_reg = reg;
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 0);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
skb_push(entry->skb, TXD_DESC_SIZE);
memset(entry->skb->data, 0, TXD_DESC_SIZE);
rt73usb_write_tx_desc(entry, txdesc);
rt2x00debug_dump_frame(rt2x00dev, DUMP_FRAME_BEACON, entry->skb);
padding_len = roundup(entry->skb->len, 4) - entry->skb->len;
if (padding_len && skb_pad(entry->skb, padding_len)) {
ERROR(rt2x00dev, "Failure padding beacon, aborting\n");
entry->skb = NULL;
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, orig_reg);
return;
}
beacon_base = HW_BEACON_OFFSET(entry->entry_idx);
rt2x00usb_register_multiwrite(rt2x00dev, beacon_base, entry->skb->data,
entry->skb->len + padding_len);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR10, 0x00001008);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 1);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
dev_kfree_skb(entry->skb);
entry->skb = NULL;
}
static void rt73usb_clear_beacon(struct queue_entry *entry)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
unsigned int beacon_base;
u32 reg;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR9, &reg);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 0);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
beacon_base = HW_BEACON_OFFSET(entry->entry_idx);
rt2x00usb_register_write(rt2x00dev, beacon_base, 0);
rt2x00_set_field32(&reg, TXRX_CSR9_BEACON_GEN, 1);
rt2x00usb_register_write(rt2x00dev, TXRX_CSR9, reg);
}
static int rt73usb_get_tx_data_len(struct queue_entry *entry)
{
int length;
length = roundup(entry->skb->len, 4);
length += (4 * !(length % entry->queue->usb_maxpacket));
return length;
}
static int rt73usb_agc_to_rssi(struct rt2x00_dev *rt2x00dev, int rxd_w1)
{
u8 offset = rt2x00dev->lna_gain;
u8 lna;
lna = rt2x00_get_field32(rxd_w1, RXD_W1_RSSI_LNA);
switch (lna) {
case 3:
offset += 90;
break;
case 2:
offset += 74;
break;
case 1:
offset += 64;
break;
default:
return 0;
}
if (rt2x00dev->curr_band == IEEE80211_BAND_5GHZ) {
if (test_bit(CAPABILITY_EXTERNAL_LNA_A, &rt2x00dev->cap_flags)) {
if (lna == 3 || lna == 2)
offset += 10;
} else {
if (lna == 3)
offset += 6;
else if (lna == 2)
offset += 8;
}
}
return rt2x00_get_field32(rxd_w1, RXD_W1_RSSI_AGC) * 2 - offset;
}
static void rt73usb_fill_rxdone(struct queue_entry *entry,
struct rxdone_entry_desc *rxdesc)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
__le32 *rxd = (__le32 *)entry->skb->data;
u32 word0;
u32 word1;
memcpy(skbdesc->desc, rxd, skbdesc->desc_len);
rxd = (__le32 *)skbdesc->desc;
rt2x00_desc_read(rxd, 0, &word0);
rt2x00_desc_read(rxd, 1, &word1);
if (rt2x00_get_field32(word0, RXD_W0_CRC_ERROR))
rxdesc->flags |= RX_FLAG_FAILED_FCS_CRC;
rxdesc->cipher = rt2x00_get_field32(word0, RXD_W0_CIPHER_ALG);
rxdesc->cipher_status = rt2x00_get_field32(word0, RXD_W0_CIPHER_ERROR);
if (rxdesc->cipher != CIPHER_NONE) {
_rt2x00_desc_read(rxd, 2, &rxdesc->iv[0]);
_rt2x00_desc_read(rxd, 3, &rxdesc->iv[1]);
rxdesc->dev_flags |= RXDONE_CRYPTO_IV;
_rt2x00_desc_read(rxd, 4, &rxdesc->icv);
rxdesc->dev_flags |= RXDONE_CRYPTO_ICV;
rxdesc->flags |= RX_FLAG_IV_STRIPPED;
rxdesc->flags |= RX_FLAG_MMIC_STRIPPED;
if (rxdesc->cipher_status == RX_CRYPTO_SUCCESS)
rxdesc->flags |= RX_FLAG_DECRYPTED;
else if (rxdesc->cipher_status == RX_CRYPTO_FAIL_MIC)
rxdesc->flags |= RX_FLAG_MMIC_ERROR;
}
rxdesc->signal = rt2x00_get_field32(word1, RXD_W1_SIGNAL);
rxdesc->rssi = rt73usb_agc_to_rssi(rt2x00dev, word1);
rxdesc->size = rt2x00_get_field32(word0, RXD_W0_DATABYTE_COUNT);
if (rt2x00_get_field32(word0, RXD_W0_OFDM))
rxdesc->dev_flags |= RXDONE_SIGNAL_PLCP;
else
rxdesc->dev_flags |= RXDONE_SIGNAL_BITRATE;
if (rt2x00_get_field32(word0, RXD_W0_MY_BSS))
rxdesc->dev_flags |= RXDONE_MY_BSS;
skb_pull(entry->skb, entry->queue->desc_size);
skb_trim(entry->skb, rxdesc->size);
}
static int rt73usb_validate_eeprom(struct rt2x00_dev *rt2x00dev)
{
u16 word;
u8 *mac;
s8 value;
rt2x00usb_eeprom_read(rt2x00dev, rt2x00dev->eeprom, EEPROM_SIZE);
mac = rt2x00_eeprom_addr(rt2x00dev, EEPROM_MAC_ADDR_0);
if (!is_valid_ether_addr(mac)) {
random_ether_addr(mac);
EEPROM(rt2x00dev, "MAC: %pM\n", mac);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_ANTENNA_NUM, 2);
rt2x00_set_field16(&word, EEPROM_ANTENNA_TX_DEFAULT,
ANTENNA_B);
rt2x00_set_field16(&word, EEPROM_ANTENNA_RX_DEFAULT,
ANTENNA_B);
rt2x00_set_field16(&word, EEPROM_ANTENNA_FRAME_TYPE, 0);
rt2x00_set_field16(&word, EEPROM_ANTENNA_DYN_TXAGC, 0);
rt2x00_set_field16(&word, EEPROM_ANTENNA_HARDWARE_RADIO, 0);
rt2x00_set_field16(&word, EEPROM_ANTENNA_RF_TYPE, RF5226);
rt2x00_eeprom_write(rt2x00dev, EEPROM_ANTENNA, word);
EEPROM(rt2x00dev, "Antenna: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_NIC_EXTERNAL_LNA, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_NIC, word);
EEPROM(rt2x00dev, "NIC: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_LED, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_RDY_G, 0);
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_RDY_A, 0);
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_ACT, 0);
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_GPIO_0, 0);
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_GPIO_1, 0);
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_GPIO_2, 0);
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_GPIO_3, 0);
rt2x00_set_field16(&word, EEPROM_LED_POLARITY_GPIO_4, 0);
rt2x00_set_field16(&word, EEPROM_LED_LED_MODE,
LED_MODE_DEFAULT);
rt2x00_eeprom_write(rt2x00dev, EEPROM_LED, word);
EEPROM(rt2x00dev, "Led: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_FREQ, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_FREQ_OFFSET, 0);
rt2x00_set_field16(&word, EEPROM_FREQ_SEQ, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_FREQ, word);
EEPROM(rt2x00dev, "Freq: 0x%04x\n", word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_OFFSET_BG, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_BG_1, 0);
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_BG_2, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_OFFSET_BG, word);
EEPROM(rt2x00dev, "RSSI OFFSET BG: 0x%04x\n", word);
} else {
value = rt2x00_get_field16(word, EEPROM_RSSI_OFFSET_BG_1);
if (value < -10 || value > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_BG_1, 0);
value = rt2x00_get_field16(word, EEPROM_RSSI_OFFSET_BG_2);
if (value < -10 || value > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_BG_2, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_OFFSET_BG, word);
}
rt2x00_eeprom_read(rt2x00dev, EEPROM_RSSI_OFFSET_A, &word);
if (word == 0xffff) {
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_A_1, 0);
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_A_2, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_OFFSET_A, word);
EEPROM(rt2x00dev, "RSSI OFFSET A: 0x%04x\n", word);
} else {
value = rt2x00_get_field16(word, EEPROM_RSSI_OFFSET_A_1);
if (value < -10 || value > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_A_1, 0);
value = rt2x00_get_field16(word, EEPROM_RSSI_OFFSET_A_2);
if (value < -10 || value > 10)
rt2x00_set_field16(&word, EEPROM_RSSI_OFFSET_A_2, 0);
rt2x00_eeprom_write(rt2x00dev, EEPROM_RSSI_OFFSET_A, word);
}
return 0;
}
static int rt73usb_init_eeprom(struct rt2x00_dev *rt2x00dev)
{
u32 reg;
u16 value;
u16 eeprom;
rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA, &eeprom);
value = rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RF_TYPE);
rt2x00usb_register_read(rt2x00dev, MAC_CSR0, &reg);
rt2x00_set_chip(rt2x00dev, rt2x00_get_field32(reg, MAC_CSR0_CHIPSET),
value, rt2x00_get_field32(reg, MAC_CSR0_REVISION));
if (!rt2x00_rt(rt2x00dev, RT2573) || (rt2x00_rev(rt2x00dev) == 0)) {
ERROR(rt2x00dev, "Invalid RT chipset detected.\n");
return -ENODEV;
}
if (!rt2x00_rf(rt2x00dev, RF5226) &&
!rt2x00_rf(rt2x00dev, RF2528) &&
!rt2x00_rf(rt2x00dev, RF5225) &&
!rt2x00_rf(rt2x00dev, RF2527)) {
ERROR(rt2x00dev, "Invalid RF chipset detected.\n");
return -ENODEV;
}
rt2x00dev->default_ant.tx =
rt2x00_get_field16(eeprom, EEPROM_ANTENNA_TX_DEFAULT);
rt2x00dev->default_ant.rx =
rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RX_DEFAULT);
if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_FRAME_TYPE))
__set_bit(CAPABILITY_FRAME_TYPE, &rt2x00dev->cap_flags);
if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_HARDWARE_RADIO))
__set_bit(CAPABILITY_HW_BUTTON, &rt2x00dev->cap_flags);
rt2x00_eeprom_read(rt2x00dev, EEPROM_FREQ, &eeprom);
rt2x00dev->freq_offset = rt2x00_get_field16(eeprom, EEPROM_FREQ_OFFSET);
rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC, &eeprom);
if (rt2x00_get_field16(eeprom, EEPROM_NIC_EXTERNAL_LNA)) {
__set_bit(CAPABILITY_EXTERNAL_LNA_A, &rt2x00dev->cap_flags);
__set_bit(CAPABILITY_EXTERNAL_LNA_BG, &rt2x00dev->cap_flags);
}
#ifdef CONFIG_RT2X00_LIB_LEDS
rt2x00_eeprom_read(rt2x00dev, EEPROM_LED, &eeprom);
rt73usb_init_led(rt2x00dev, &rt2x00dev->led_radio, LED_TYPE_RADIO);
rt73usb_init_led(rt2x00dev, &rt2x00dev->led_assoc, LED_TYPE_ASSOC);
if (value == LED_MODE_SIGNAL_STRENGTH)
rt73usb_init_led(rt2x00dev, &rt2x00dev->led_qual,
LED_TYPE_QUALITY);
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_LED_MODE, value);
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_0,
rt2x00_get_field16(eeprom,
EEPROM_LED_POLARITY_GPIO_0));
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_1,
rt2x00_get_field16(eeprom,
EEPROM_LED_POLARITY_GPIO_1));
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_2,
rt2x00_get_field16(eeprom,
EEPROM_LED_POLARITY_GPIO_2));
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_3,
rt2x00_get_field16(eeprom,
EEPROM_LED_POLARITY_GPIO_3));
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_GPIO_4,
rt2x00_get_field16(eeprom,
EEPROM_LED_POLARITY_GPIO_4));
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_ACT,
rt2x00_get_field16(eeprom, EEPROM_LED_POLARITY_ACT));
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_READY_BG,
rt2x00_get_field16(eeprom,
EEPROM_LED_POLARITY_RDY_G));
rt2x00_set_field16(&rt2x00dev->led_mcu_reg, MCU_LEDCS_POLARITY_READY_A,
rt2x00_get_field16(eeprom,
EEPROM_LED_POLARITY_RDY_A));
#endif
return 0;
}
static int rt73usb_probe_hw_mode(struct rt2x00_dev *rt2x00dev)
{
struct hw_mode_spec *spec = &rt2x00dev->spec;
struct channel_info *info;
char *tx_power;
unsigned int i;
rt2x00dev->hw->flags =
IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_SUPPORTS_PS |
IEEE80211_HW_PS_NULLFUNC_STACK;
SET_IEEE80211_DEV(rt2x00dev->hw, rt2x00dev->dev);
SET_IEEE80211_PERM_ADDR(rt2x00dev->hw,
rt2x00_eeprom_addr(rt2x00dev,
EEPROM_MAC_ADDR_0));
spec->supported_bands = SUPPORT_BAND_2GHZ;
spec->supported_rates = SUPPORT_RATE_CCK | SUPPORT_RATE_OFDM;
if (rt2x00_rf(rt2x00dev, RF2528)) {
spec->num_channels = ARRAY_SIZE(rf_vals_bg_2528);
spec->channels = rf_vals_bg_2528;
} else if (rt2x00_rf(rt2x00dev, RF5226)) {
spec->supported_bands |= SUPPORT_BAND_5GHZ;
spec->num_channels = ARRAY_SIZE(rf_vals_5226);
spec->channels = rf_vals_5226;
} else if (rt2x00_rf(rt2x00dev, RF2527)) {
spec->num_channels = 14;
spec->channels = rf_vals_5225_2527;
} else if (rt2x00_rf(rt2x00dev, RF5225)) {
spec->supported_bands |= SUPPORT_BAND_5GHZ;
spec->num_channels = ARRAY_SIZE(rf_vals_5225_2527);
spec->channels = rf_vals_5225_2527;
}
info = kcalloc(spec->num_channels, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
spec->channels_info = info;
tx_power = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_G_START);
for (i = 0; i < 14; i++) {
info[i].max_power = MAX_TXPOWER;
info[i].default_power1 = TXPOWER_FROM_DEV(tx_power[i]);
}
if (spec->num_channels > 14) {
tx_power = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_A_START);
for (i = 14; i < spec->num_channels; i++) {
info[i].max_power = MAX_TXPOWER;
info[i].default_power1 = TXPOWER_FROM_DEV(tx_power[i]);
}
}
return 0;
}
static int rt73usb_probe_hw(struct rt2x00_dev *rt2x00dev)
{
int retval;
retval = rt73usb_validate_eeprom(rt2x00dev);
if (retval)
return retval;
retval = rt73usb_init_eeprom(rt2x00dev);
if (retval)
return retval;
retval = rt73usb_probe_hw_mode(rt2x00dev);
if (retval)
return retval;
__set_bit(CAPABILITY_CONTROL_FILTERS, &rt2x00dev->cap_flags);
__set_bit(REQUIRE_FIRMWARE, &rt2x00dev->cap_flags);
if (!modparam_nohwcrypt)
__set_bit(CAPABILITY_HW_CRYPTO, &rt2x00dev->cap_flags);
__set_bit(CAPABILITY_LINK_TUNING, &rt2x00dev->cap_flags);
__set_bit(REQUIRE_PS_AUTOWAKE, &rt2x00dev->cap_flags);
rt2x00dev->rssi_offset = DEFAULT_RSSI_OFFSET;
return 0;
}
static int rt73usb_conf_tx(struct ieee80211_hw *hw,
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
offset = AC_TXOP_CSR0 + (sizeof(u32) * (!!(queue_idx & 2)));
field.bit_offset = (queue_idx & 1) * 16;
field.bit_mask = 0xffff << field.bit_offset;
rt2x00usb_register_read(rt2x00dev, offset, &reg);
rt2x00_set_field32(&reg, field, queue->txop);
rt2x00usb_register_write(rt2x00dev, offset, reg);
field.bit_offset = queue_idx * 4;
field.bit_mask = 0xf << field.bit_offset;
rt2x00usb_register_read(rt2x00dev, AIFSN_CSR, &reg);
rt2x00_set_field32(&reg, field, queue->aifs);
rt2x00usb_register_write(rt2x00dev, AIFSN_CSR, reg);
rt2x00usb_register_read(rt2x00dev, CWMIN_CSR, &reg);
rt2x00_set_field32(&reg, field, queue->cw_min);
rt2x00usb_register_write(rt2x00dev, CWMIN_CSR, reg);
rt2x00usb_register_read(rt2x00dev, CWMAX_CSR, &reg);
rt2x00_set_field32(&reg, field, queue->cw_max);
rt2x00usb_register_write(rt2x00dev, CWMAX_CSR, reg);
return 0;
}
static u64 rt73usb_get_tsf(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
struct rt2x00_dev *rt2x00dev = hw->priv;
u64 tsf;
u32 reg;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR13, &reg);
tsf = (u64) rt2x00_get_field32(reg, TXRX_CSR13_HIGH_TSFTIMER) << 32;
rt2x00usb_register_read(rt2x00dev, TXRX_CSR12, &reg);
tsf |= rt2x00_get_field32(reg, TXRX_CSR12_LOW_TSFTIMER);
return tsf;
}
static int rt73usb_probe(struct usb_interface *usb_intf,
const struct usb_device_id *id)
{
return rt2x00usb_probe(usb_intf, &rt73usb_ops);
}
static int __init rt73usb_init(void)
{
return usb_register(&rt73usb_driver);
}
static void __exit rt73usb_exit(void)
{
usb_deregister(&rt73usb_driver);
}
