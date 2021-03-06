static void ar5008_rf_bank_setup(u32 *bank, struct ar5416IniArray *array,
int col)
{
int i;
for (i = 0; i < array->ia_rows; i++)
bank[i] = INI_RA(array, i, col);
}
static void ar5008_write_rf_array(struct ath_hw *ah, struct ar5416IniArray *array,
u32 *data, unsigned int *writecnt)
{
int r;
ENABLE_REGWRITE_BUFFER(ah);
for (r = 0; r < array->ia_rows; r++) {
REG_WRITE(ah, INI_RA(array, r, 0), data[r]);
DO_DELAY(*writecnt);
}
REGWRITE_BUFFER_FLUSH(ah);
}
static void ar5008_hw_phy_modify_rx_buffer(u32 *rfBuf, u32 reg32,
u32 numBits, u32 firstBit,
u32 column)
{
u32 tmp32, mask, arrayEntry, lastBit;
int32_t bitPosition, bitsLeft;
tmp32 = ath9k_hw_reverse_bits(reg32, numBits);
arrayEntry = (firstBit - 1) / 8;
bitPosition = (firstBit - 1) % 8;
bitsLeft = numBits;
while (bitsLeft > 0) {
lastBit = (bitPosition + bitsLeft > 8) ?
8 : bitPosition + bitsLeft;
mask = (((1 << lastBit) - 1) ^ ((1 << bitPosition) - 1)) <<
(column * 8);
rfBuf[arrayEntry] &= ~mask;
rfBuf[arrayEntry] |= ((tmp32 << bitPosition) <<
(column * 8)) & mask;
bitsLeft -= 8 - bitPosition;
tmp32 = tmp32 >> (8 - bitPosition);
bitPosition = 0;
arrayEntry++;
}
}
static void ar5008_hw_force_bias(struct ath_hw *ah, u16 synth_freq)
{
struct ath_common *common = ath9k_hw_common(ah);
u32 tmp_reg;
int reg_writes = 0;
u32 new_bias = 0;
if (!AR_SREV_5416(ah) || synth_freq >= 3000)
return;
BUG_ON(AR_SREV_9280_20_OR_LATER(ah));
if (synth_freq < 2412)
new_bias = 0;
else if (synth_freq < 2422)
new_bias = 1;
else
new_bias = 2;
tmp_reg = ath9k_hw_reverse_bits(new_bias, 3);
ath_dbg(common, CONFIG, "Force rf_pwd_icsyndiv to %1d on %4d\n",
new_bias, synth_freq);
ar5008_hw_phy_modify_rx_buffer(ah->analogBank6Data, tmp_reg, 3, 181, 3);
REG_WRITE_RF_ARRAY(&ah->iniBank6, ah->analogBank6Data, reg_writes);
}
static int ar5008_hw_set_channel(struct ath_hw *ah, struct ath9k_channel *chan)
{
struct ath_common *common = ath9k_hw_common(ah);
u32 channelSel = 0;
u32 bModeSynth = 0;
u32 aModeRefSel = 0;
u32 reg32 = 0;
u16 freq;
struct chan_centers centers;
ath9k_hw_get_channel_centers(ah, chan, &centers);
freq = centers.synth_center;
if (freq < 4800) {
u32 txctl;
if (((freq - 2192) % 5) == 0) {
channelSel = ((freq - 672) * 2 - 3040) / 10;
bModeSynth = 0;
} else if (((freq - 2224) % 5) == 0) {
channelSel = ((freq - 704) * 2 - 3040) / 10;
bModeSynth = 1;
} else {
ath_err(common, "Invalid channel %u MHz\n", freq);
return -EINVAL;
}
channelSel = (channelSel << 2) & 0xff;
channelSel = ath9k_hw_reverse_bits(channelSel, 8);
txctl = REG_READ(ah, AR_PHY_CCK_TX_CTRL);
if (freq == 2484) {
REG_WRITE(ah, AR_PHY_CCK_TX_CTRL,
txctl | AR_PHY_CCK_TX_CTRL_JAPAN);
} else {
REG_WRITE(ah, AR_PHY_CCK_TX_CTRL,
txctl & ~AR_PHY_CCK_TX_CTRL_JAPAN);
}
} else if ((freq % 20) == 0 && freq >= 5120) {
channelSel =
ath9k_hw_reverse_bits(((freq - 4800) / 20 << 2), 8);
aModeRefSel = ath9k_hw_reverse_bits(1, 2);
} else if ((freq % 10) == 0) {
channelSel =
ath9k_hw_reverse_bits(((freq - 4800) / 10 << 1), 8);
if (AR_SREV_9100(ah) || AR_SREV_9160_10_OR_LATER(ah))
aModeRefSel = ath9k_hw_reverse_bits(2, 2);
else
aModeRefSel = ath9k_hw_reverse_bits(1, 2);
} else if ((freq % 5) == 0) {
channelSel = ath9k_hw_reverse_bits((freq - 4800) / 5, 8);
aModeRefSel = ath9k_hw_reverse_bits(1, 2);
} else {
ath_err(common, "Invalid channel %u MHz\n", freq);
return -EINVAL;
}
ar5008_hw_force_bias(ah, freq);
reg32 =
(channelSel << 8) | (aModeRefSel << 2) | (bModeSynth << 1) |
(1 << 5) | 0x1;
REG_WRITE(ah, AR_PHY(0x37), reg32);
ah->curchan = chan;
return 0;
}
static void ar5008_hw_spur_mitigate(struct ath_hw *ah,
struct ath9k_channel *chan)
{
int bb_spur = AR_NO_SPUR;
int bin, cur_bin;
int spur_freq_sd;
int spur_delta_phase;
int denominator;
int upper, lower, cur_vit_mask;
int tmp, new;
int i;
static int pilot_mask_reg[4] = {
AR_PHY_TIMING7, AR_PHY_TIMING8,
AR_PHY_PILOT_MASK_01_30, AR_PHY_PILOT_MASK_31_60
};
static int chan_mask_reg[4] = {
AR_PHY_TIMING9, AR_PHY_TIMING10,
AR_PHY_CHANNEL_MASK_01_30, AR_PHY_CHANNEL_MASK_31_60
};
static int inc[4] = { 0, 100, 0, 0 };
int8_t mask_m[123];
int8_t mask_p[123];
int8_t mask_amt;
int tmp_mask;
int cur_bb_spur;
bool is2GHz = IS_CHAN_2GHZ(chan);
memset(&mask_m, 0, sizeof(int8_t) * 123);
memset(&mask_p, 0, sizeof(int8_t) * 123);
for (i = 0; i < AR_EEPROM_MODAL_SPURS; i++) {
cur_bb_spur = ah->eep_ops->get_spur_channel(ah, i, is2GHz);
if (AR_NO_SPUR == cur_bb_spur)
break;
cur_bb_spur = cur_bb_spur - (chan->channel * 10);
if ((cur_bb_spur > -95) && (cur_bb_spur < 95)) {
bb_spur = cur_bb_spur;
break;
}
}
if (AR_NO_SPUR == bb_spur)
return;
bin = bb_spur * 32;
tmp = REG_READ(ah, AR_PHY_TIMING_CTRL4(0));
new = tmp | (AR_PHY_TIMING_CTRL4_ENABLE_SPUR_RSSI |
AR_PHY_TIMING_CTRL4_ENABLE_SPUR_FILTER |
AR_PHY_TIMING_CTRL4_ENABLE_CHAN_MASK |
AR_PHY_TIMING_CTRL4_ENABLE_PILOT_MASK);
REG_WRITE(ah, AR_PHY_TIMING_CTRL4(0), new);
new = (AR_PHY_SPUR_REG_MASK_RATE_CNTL |
AR_PHY_SPUR_REG_ENABLE_MASK_PPM |
AR_PHY_SPUR_REG_MASK_RATE_SELECT |
AR_PHY_SPUR_REG_ENABLE_VIT_SPUR_RSSI |
SM(SPUR_RSSI_THRESH, AR_PHY_SPUR_REG_SPUR_RSSI_THRESH));
REG_WRITE(ah, AR_PHY_SPUR_REG, new);
spur_delta_phase = ((bb_spur * 524288) / 100) &
AR_PHY_TIMING11_SPUR_DELTA_PHASE;
denominator = IS_CHAN_2GHZ(chan) ? 440 : 400;
spur_freq_sd = ((bb_spur * 2048) / denominator) & 0x3ff;
new = (AR_PHY_TIMING11_USE_SPUR_IN_AGC |
SM(spur_freq_sd, AR_PHY_TIMING11_SPUR_FREQ_SD) |
SM(spur_delta_phase, AR_PHY_TIMING11_SPUR_DELTA_PHASE));
REG_WRITE(ah, AR_PHY_TIMING11, new);
cur_bin = -6000;
upper = bin + 100;
lower = bin - 100;
for (i = 0; i < 4; i++) {
int pilot_mask = 0;
int chan_mask = 0;
int bp = 0;
for (bp = 0; bp < 30; bp++) {
if ((cur_bin > lower) && (cur_bin < upper)) {
pilot_mask = pilot_mask | 0x1 << bp;
chan_mask = chan_mask | 0x1 << bp;
}
cur_bin += 100;
}
cur_bin += inc[i];
REG_WRITE(ah, pilot_mask_reg[i], pilot_mask);
REG_WRITE(ah, chan_mask_reg[i], chan_mask);
}
cur_vit_mask = 6100;
upper = bin + 120;
lower = bin - 120;
for (i = 0; i < 123; i++) {
if ((cur_vit_mask > lower) && (cur_vit_mask < upper)) {
volatile int tmp_v = abs(cur_vit_mask - bin);
if (tmp_v < 75)
mask_amt = 1;
else
mask_amt = 0;
if (cur_vit_mask < 0)
mask_m[abs(cur_vit_mask / 100)] = mask_amt;
else
mask_p[cur_vit_mask / 100] = mask_amt;
}
cur_vit_mask -= 100;
}
tmp_mask = (mask_m[46] << 30) | (mask_m[47] << 28)
| (mask_m[48] << 26) | (mask_m[49] << 24)
| (mask_m[50] << 22) | (mask_m[51] << 20)
| (mask_m[52] << 18) | (mask_m[53] << 16)
| (mask_m[54] << 14) | (mask_m[55] << 12)
| (mask_m[56] << 10) | (mask_m[57] << 8)
| (mask_m[58] << 6) | (mask_m[59] << 4)
| (mask_m[60] << 2) | (mask_m[61] << 0);
REG_WRITE(ah, AR_PHY_BIN_MASK_1, tmp_mask);
REG_WRITE(ah, AR_PHY_VIT_MASK2_M_46_61, tmp_mask);
tmp_mask = (mask_m[31] << 28)
| (mask_m[32] << 26) | (mask_m[33] << 24)
| (mask_m[34] << 22) | (mask_m[35] << 20)
| (mask_m[36] << 18) | (mask_m[37] << 16)
| (mask_m[48] << 14) | (mask_m[39] << 12)
| (mask_m[40] << 10) | (mask_m[41] << 8)
| (mask_m[42] << 6) | (mask_m[43] << 4)
| (mask_m[44] << 2) | (mask_m[45] << 0);
REG_WRITE(ah, AR_PHY_BIN_MASK_2, tmp_mask);
REG_WRITE(ah, AR_PHY_MASK2_M_31_45, tmp_mask);
tmp_mask = (mask_m[16] << 30) | (mask_m[16] << 28)
| (mask_m[18] << 26) | (mask_m[18] << 24)
| (mask_m[20] << 22) | (mask_m[20] << 20)
| (mask_m[22] << 18) | (mask_m[22] << 16)
| (mask_m[24] << 14) | (mask_m[24] << 12)
| (mask_m[25] << 10) | (mask_m[26] << 8)
| (mask_m[27] << 6) | (mask_m[28] << 4)
| (mask_m[29] << 2) | (mask_m[30] << 0);
REG_WRITE(ah, AR_PHY_BIN_MASK_3, tmp_mask);
REG_WRITE(ah, AR_PHY_MASK2_M_16_30, tmp_mask);
tmp_mask = (mask_m[0] << 30) | (mask_m[1] << 28)
| (mask_m[2] << 26) | (mask_m[3] << 24)
| (mask_m[4] << 22) | (mask_m[5] << 20)
| (mask_m[6] << 18) | (mask_m[7] << 16)
| (mask_m[8] << 14) | (mask_m[9] << 12)
| (mask_m[10] << 10) | (mask_m[11] << 8)
| (mask_m[12] << 6) | (mask_m[13] << 4)
| (mask_m[14] << 2) | (mask_m[15] << 0);
REG_WRITE(ah, AR_PHY_MASK_CTL, tmp_mask);
REG_WRITE(ah, AR_PHY_MASK2_M_00_15, tmp_mask);
tmp_mask = (mask_p[15] << 28)
| (mask_p[14] << 26) | (mask_p[13] << 24)
| (mask_p[12] << 22) | (mask_p[11] << 20)
| (mask_p[10] << 18) | (mask_p[9] << 16)
| (mask_p[8] << 14) | (mask_p[7] << 12)
| (mask_p[6] << 10) | (mask_p[5] << 8)
| (mask_p[4] << 6) | (mask_p[3] << 4)
| (mask_p[2] << 2) | (mask_p[1] << 0);
REG_WRITE(ah, AR_PHY_BIN_MASK2_1, tmp_mask);
REG_WRITE(ah, AR_PHY_MASK2_P_15_01, tmp_mask);
tmp_mask = (mask_p[30] << 28)
| (mask_p[29] << 26) | (mask_p[28] << 24)
| (mask_p[27] << 22) | (mask_p[26] << 20)
| (mask_p[25] << 18) | (mask_p[24] << 16)
| (mask_p[23] << 14) | (mask_p[22] << 12)
| (mask_p[21] << 10) | (mask_p[20] << 8)
| (mask_p[19] << 6) | (mask_p[18] << 4)
| (mask_p[17] << 2) | (mask_p[16] << 0);
REG_WRITE(ah, AR_PHY_BIN_MASK2_2, tmp_mask);
REG_WRITE(ah, AR_PHY_MASK2_P_30_16, tmp_mask);
tmp_mask = (mask_p[45] << 28)
| (mask_p[44] << 26) | (mask_p[43] << 24)
| (mask_p[42] << 22) | (mask_p[41] << 20)
| (mask_p[40] << 18) | (mask_p[39] << 16)
| (mask_p[38] << 14) | (mask_p[37] << 12)
| (mask_p[36] << 10) | (mask_p[35] << 8)
| (mask_p[34] << 6) | (mask_p[33] << 4)
| (mask_p[32] << 2) | (mask_p[31] << 0);
REG_WRITE(ah, AR_PHY_BIN_MASK2_3, tmp_mask);
REG_WRITE(ah, AR_PHY_MASK2_P_45_31, tmp_mask);
tmp_mask = (mask_p[61] << 30) | (mask_p[60] << 28)
| (mask_p[59] << 26) | (mask_p[58] << 24)
| (mask_p[57] << 22) | (mask_p[56] << 20)
| (mask_p[55] << 18) | (mask_p[54] << 16)
| (mask_p[53] << 14) | (mask_p[52] << 12)
| (mask_p[51] << 10) | (mask_p[50] << 8)
| (mask_p[49] << 6) | (mask_p[48] << 4)
| (mask_p[47] << 2) | (mask_p[46] << 0);
REG_WRITE(ah, AR_PHY_BIN_MASK2_4, tmp_mask);
REG_WRITE(ah, AR_PHY_MASK2_P_61_45, tmp_mask);
}
static int ar5008_hw_rf_alloc_ext_banks(struct ath_hw *ah)
{
#define ATH_ALLOC_BANK(bank, size) do { \
bank = devm_kzalloc(ah->dev, sizeof(u32) * size, GFP_KERNEL); \
if (!bank) \
goto error; \
} while (0);
struct ath_common *common = ath9k_hw_common(ah);
if (AR_SREV_9280_20_OR_LATER(ah))
return 0;
ATH_ALLOC_BANK(ah->analogBank0Data, ah->iniBank0.ia_rows);
ATH_ALLOC_BANK(ah->analogBank1Data, ah->iniBank1.ia_rows);
ATH_ALLOC_BANK(ah->analogBank2Data, ah->iniBank2.ia_rows);
ATH_ALLOC_BANK(ah->analogBank3Data, ah->iniBank3.ia_rows);
ATH_ALLOC_BANK(ah->analogBank6Data, ah->iniBank6.ia_rows);
ATH_ALLOC_BANK(ah->analogBank6TPCData, ah->iniBank6TPC.ia_rows);
ATH_ALLOC_BANK(ah->analogBank7Data, ah->iniBank7.ia_rows);
ATH_ALLOC_BANK(ah->bank6Temp, ah->iniBank6.ia_rows);
return 0;
#undef ATH_ALLOC_BANK
error:
ath_err(common, "Cannot allocate RF banks\n");
return -ENOMEM;
}
static bool ar5008_hw_set_rf_regs(struct ath_hw *ah,
struct ath9k_channel *chan,
u16 modesIndex)
{
u32 eepMinorRev;
u32 ob5GHz = 0, db5GHz = 0;
u32 ob2GHz = 0, db2GHz = 0;
int regWrites = 0;
if (AR_SREV_9280_20_OR_LATER(ah))
return true;
eepMinorRev = ah->eep_ops->get_eeprom(ah, EEP_MINOR_REV);
ar5008_rf_bank_setup(ah->analogBank0Data, &ah->iniBank0, 1);
ar5008_rf_bank_setup(ah->analogBank1Data, &ah->iniBank1, 1);
ar5008_rf_bank_setup(ah->analogBank2Data, &ah->iniBank2, 1);
ar5008_rf_bank_setup(ah->analogBank3Data, &ah->iniBank3,
modesIndex);
{
int i;
for (i = 0; i < ah->iniBank6TPC.ia_rows; i++) {
ah->analogBank6Data[i] =
INI_RA(&ah->iniBank6TPC, i, modesIndex);
}
}
if (eepMinorRev >= 2) {
if (IS_CHAN_2GHZ(chan)) {
ob2GHz = ah->eep_ops->get_eeprom(ah, EEP_OB_2);
db2GHz = ah->eep_ops->get_eeprom(ah, EEP_DB_2);
ar5008_hw_phy_modify_rx_buffer(ah->analogBank6Data,
ob2GHz, 3, 197, 0);
ar5008_hw_phy_modify_rx_buffer(ah->analogBank6Data,
db2GHz, 3, 194, 0);
} else {
ob5GHz = ah->eep_ops->get_eeprom(ah, EEP_OB_5);
db5GHz = ah->eep_ops->get_eeprom(ah, EEP_DB_5);
ar5008_hw_phy_modify_rx_buffer(ah->analogBank6Data,
ob5GHz, 3, 203, 0);
ar5008_hw_phy_modify_rx_buffer(ah->analogBank6Data,
db5GHz, 3, 200, 0);
}
}
ar5008_rf_bank_setup(ah->analogBank7Data, &ah->iniBank7, 1);
REG_WRITE_RF_ARRAY(&ah->iniBank0, ah->analogBank0Data,
regWrites);
REG_WRITE_RF_ARRAY(&ah->iniBank1, ah->analogBank1Data,
regWrites);
REG_WRITE_RF_ARRAY(&ah->iniBank2, ah->analogBank2Data,
regWrites);
REG_WRITE_RF_ARRAY(&ah->iniBank3, ah->analogBank3Data,
regWrites);
REG_WRITE_RF_ARRAY(&ah->iniBank6TPC, ah->analogBank6Data,
regWrites);
REG_WRITE_RF_ARRAY(&ah->iniBank7, ah->analogBank7Data,
regWrites);
return true;
}
static void ar5008_hw_init_bb(struct ath_hw *ah,
struct ath9k_channel *chan)
{
u32 synthDelay;
synthDelay = REG_READ(ah, AR_PHY_RX_DELAY) & AR_PHY_RX_DELAY_DELAY;
REG_WRITE(ah, AR_PHY_ACTIVE, AR_PHY_ACTIVE_EN);
ath9k_hw_synth_delay(ah, chan, synthDelay);
}
static void ar5008_hw_init_chain_masks(struct ath_hw *ah)
{
int rx_chainmask, tx_chainmask;
rx_chainmask = ah->rxchainmask;
tx_chainmask = ah->txchainmask;
switch (rx_chainmask) {
case 0x5:
REG_SET_BIT(ah, AR_PHY_ANALOG_SWAP,
AR_PHY_SWAP_ALT_CHAIN);
case 0x3:
if (ah->hw_version.macVersion == AR_SREV_REVISION_5416_10) {
REG_WRITE(ah, AR_PHY_RX_CHAINMASK, 0x7);
REG_WRITE(ah, AR_PHY_CAL_CHAINMASK, 0x7);
break;
}
case 0x1:
case 0x2:
case 0x7:
ENABLE_REGWRITE_BUFFER(ah);
REG_WRITE(ah, AR_PHY_RX_CHAINMASK, rx_chainmask);
REG_WRITE(ah, AR_PHY_CAL_CHAINMASK, rx_chainmask);
break;
default:
ENABLE_REGWRITE_BUFFER(ah);
break;
}
REG_WRITE(ah, AR_SELFGEN_MASK, tx_chainmask);
REGWRITE_BUFFER_FLUSH(ah);
if (tx_chainmask == 0x5) {
REG_SET_BIT(ah, AR_PHY_ANALOG_SWAP,
AR_PHY_SWAP_ALT_CHAIN);
}
if (AR_SREV_9100(ah))
REG_WRITE(ah, AR_PHY_ANALOG_SWAP,
REG_READ(ah, AR_PHY_ANALOG_SWAP) | 0x00000001);
}
static void ar5008_hw_override_ini(struct ath_hw *ah,
struct ath9k_channel *chan)
{
u32 val;
REG_SET_BIT(ah, AR_DIAG_SW, (AR_DIAG_RX_DIS | AR_DIAG_RX_ABORT));
if (AR_SREV_9280_20_OR_LATER(ah)) {
val = REG_READ(ah, AR_PCU_MISC_MODE2);
if (!AR_SREV_9271(ah))
val &= ~AR_PCU_MISC_MODE2_HWWAR1;
if (AR_SREV_9287_11_OR_LATER(ah))
val = val & (~AR_PCU_MISC_MODE2_HWWAR2);
REG_WRITE(ah, AR_PCU_MISC_MODE2, val);
}
REG_SET_BIT(ah, AR_PHY_CCK_DETECT,
AR_PHY_CCK_DETECT_BB_ENABLE_ANT_FAST_DIV);
if (AR_SREV_9280_20_OR_LATER(ah))
return;
REG_WRITE(ah, 0x9800 + (651 << 2), 0x11);
if (AR_SREV_9100(ah) || AR_SREV_9160(ah)) {
val = REG_READ(ah, AR_PHY_HEAVY_CLIP_FACTOR_RIFS);
val &= ~AR_PHY_RIFS_INIT_DELAY;
REG_WRITE(ah, AR_PHY_HEAVY_CLIP_FACTOR_RIFS, val);
}
}
static void ar5008_hw_set_channel_regs(struct ath_hw *ah,
struct ath9k_channel *chan)
{
u32 phymode;
u32 enableDacFifo = 0;
if (AR_SREV_9285_12_OR_LATER(ah))
enableDacFifo = (REG_READ(ah, AR_PHY_TURBO) &
AR_PHY_FC_ENABLE_DAC_FIFO);
phymode = AR_PHY_FC_HT_EN | AR_PHY_FC_SHORT_GI_40
| AR_PHY_FC_SINGLE_HT_LTF1 | AR_PHY_FC_WALSH | enableDacFifo;
if (IS_CHAN_HT40(chan)) {
phymode |= AR_PHY_FC_DYN2040_EN;
if ((chan->chanmode == CHANNEL_A_HT40PLUS) ||
(chan->chanmode == CHANNEL_G_HT40PLUS))
phymode |= AR_PHY_FC_DYN2040_PRI_CH;
}
REG_WRITE(ah, AR_PHY_TURBO, phymode);
ath9k_hw_set11nmac2040(ah);
ENABLE_REGWRITE_BUFFER(ah);
REG_WRITE(ah, AR_GTXTO, 25 << AR_GTXTO_TIMEOUT_LIMIT_S);
REG_WRITE(ah, AR_CST, 0xF << AR_CST_TIMEOUT_LIMIT_S);
REGWRITE_BUFFER_FLUSH(ah);
}
static int ar5008_hw_process_ini(struct ath_hw *ah,
struct ath9k_channel *chan)
{
struct ath_common *common = ath9k_hw_common(ah);
int i, regWrites = 0;
u32 modesIndex, freqIndex;
switch (chan->chanmode) {
case CHANNEL_A:
case CHANNEL_A_HT20:
modesIndex = 1;
freqIndex = 1;
break;
case CHANNEL_A_HT40PLUS:
case CHANNEL_A_HT40MINUS:
modesIndex = 2;
freqIndex = 1;
break;
case CHANNEL_G:
case CHANNEL_G_HT20:
case CHANNEL_B:
modesIndex = 4;
freqIndex = 2;
break;
case CHANNEL_G_HT40PLUS:
case CHANNEL_G_HT40MINUS:
modesIndex = 3;
freqIndex = 2;
break;
default:
return -EINVAL;
}
REG_WRITE(ah, AR_PHY(0), 0x00000007);
REG_WRITE(ah, AR_PHY_ADC_SERIAL_CTL, AR_PHY_SEL_EXTERNAL_RADIO);
if (ah->eep_ops->set_addac)
ah->eep_ops->set_addac(ah, chan);
REG_WRITE_ARRAY(&ah->iniAddac, 1, regWrites);
REG_WRITE(ah, AR_PHY_ADC_SERIAL_CTL, AR_PHY_SEL_INTERNAL_ADDAC);
ENABLE_REGWRITE_BUFFER(ah);
for (i = 0; i < ah->iniModes.ia_rows; i++) {
u32 reg = INI_RA(&ah->iniModes, i, 0);
u32 val = INI_RA(&ah->iniModes, i, modesIndex);
if (reg == AR_AN_TOP2 && ah->need_an_top2_fixup)
val &= ~AR_AN_TOP2_PWDCLKIND;
REG_WRITE(ah, reg, val);
if (reg >= 0x7800 && reg < 0x78a0
&& ah->config.analog_shiftreg
&& (common->bus_ops->ath_bus_type != ATH_USB)) {
udelay(100);
}
DO_DELAY(regWrites);
}
REGWRITE_BUFFER_FLUSH(ah);
if (AR_SREV_9280(ah) || AR_SREV_9287_11_OR_LATER(ah))
REG_WRITE_ARRAY(&ah->iniModesRxGain, modesIndex, regWrites);
if (AR_SREV_9280(ah) || AR_SREV_9285_12_OR_LATER(ah) ||
AR_SREV_9287_11_OR_LATER(ah))
REG_WRITE_ARRAY(&ah->iniModesTxGain, modesIndex, regWrites);
if (AR_SREV_9271_10(ah)) {
REG_SET_BIT(ah, AR_PHY_SPECTRAL_SCAN, AR_PHY_SPECTRAL_SCAN_ENA);
REG_RMW_FIELD(ah, AR_PHY_RF_CTL3, AR_PHY_TX_END_TO_ADC_ON, 0xa);
}
ENABLE_REGWRITE_BUFFER(ah);
for (i = 0; i < ah->iniCommon.ia_rows; i++) {
u32 reg = INI_RA(&ah->iniCommon, i, 0);
u32 val = INI_RA(&ah->iniCommon, i, 1);
REG_WRITE(ah, reg, val);
if (reg >= 0x7800 && reg < 0x78a0
&& ah->config.analog_shiftreg
&& (common->bus_ops->ath_bus_type != ATH_USB)) {
udelay(100);
}
DO_DELAY(regWrites);
}
REGWRITE_BUFFER_FLUSH(ah);
REG_WRITE_ARRAY(&ah->iniBB_RfGain, freqIndex, regWrites);
if (IS_CHAN_A_FAST_CLOCK(ah, chan))
REG_WRITE_ARRAY(&ah->iniModesFastClock, modesIndex,
regWrites);
ar5008_hw_override_ini(ah, chan);
ar5008_hw_set_channel_regs(ah, chan);
ar5008_hw_init_chain_masks(ah);
ath9k_olc_init(ah);
ath9k_hw_apply_txpower(ah, chan, false);
if (!ath9k_hw_set_rf_regs(ah, chan, freqIndex)) {
ath_err(ath9k_hw_common(ah), "ar5416SetRfRegs failed\n");
return -EIO;
}
return 0;
}
static void ar5008_hw_set_rfmode(struct ath_hw *ah, struct ath9k_channel *chan)
{
u32 rfMode = 0;
if (chan == NULL)
return;
rfMode |= (IS_CHAN_B(chan) || IS_CHAN_G(chan))
? AR_PHY_MODE_DYNAMIC : AR_PHY_MODE_OFDM;
if (!AR_SREV_9280_20_OR_LATER(ah))
rfMode |= (IS_CHAN_5GHZ(chan)) ?
AR_PHY_MODE_RF5GHZ : AR_PHY_MODE_RF2GHZ;
if (IS_CHAN_A_FAST_CLOCK(ah, chan))
rfMode |= (AR_PHY_MODE_DYNAMIC | AR_PHY_MODE_DYN_CCK_DISABLE);
REG_WRITE(ah, AR_PHY_MODE, rfMode);
}
static void ar5008_hw_mark_phy_inactive(struct ath_hw *ah)
{
REG_WRITE(ah, AR_PHY_ACTIVE, AR_PHY_ACTIVE_DIS);
}
static void ar5008_hw_set_delta_slope(struct ath_hw *ah,
struct ath9k_channel *chan)
{
u32 coef_scaled, ds_coef_exp, ds_coef_man;
u32 clockMhzScaled = 0x64000000;
struct chan_centers centers;
if (IS_CHAN_HALF_RATE(chan))
clockMhzScaled = clockMhzScaled >> 1;
else if (IS_CHAN_QUARTER_RATE(chan))
clockMhzScaled = clockMhzScaled >> 2;
ath9k_hw_get_channel_centers(ah, chan, &centers);
coef_scaled = clockMhzScaled / centers.synth_center;
ath9k_hw_get_delta_slope_vals(ah, coef_scaled, &ds_coef_man,
&ds_coef_exp);
REG_RMW_FIELD(ah, AR_PHY_TIMING3,
AR_PHY_TIMING3_DSC_MAN, ds_coef_man);
REG_RMW_FIELD(ah, AR_PHY_TIMING3,
AR_PHY_TIMING3_DSC_EXP, ds_coef_exp);
coef_scaled = (9 * coef_scaled) / 10;
ath9k_hw_get_delta_slope_vals(ah, coef_scaled, &ds_coef_man,
&ds_coef_exp);
REG_RMW_FIELD(ah, AR_PHY_HALFGI,
AR_PHY_HALFGI_DSC_MAN, ds_coef_man);
REG_RMW_FIELD(ah, AR_PHY_HALFGI,
AR_PHY_HALFGI_DSC_EXP, ds_coef_exp);
}
static bool ar5008_hw_rfbus_req(struct ath_hw *ah)
{
REG_WRITE(ah, AR_PHY_RFBUS_REQ, AR_PHY_RFBUS_REQ_EN);
return ath9k_hw_wait(ah, AR_PHY_RFBUS_GRANT, AR_PHY_RFBUS_GRANT_EN,
AR_PHY_RFBUS_GRANT_EN, AH_WAIT_TIMEOUT);
}
static void ar5008_hw_rfbus_done(struct ath_hw *ah)
{
u32 synthDelay = REG_READ(ah, AR_PHY_RX_DELAY) & AR_PHY_RX_DELAY_DELAY;
ath9k_hw_synth_delay(ah, ah->curchan, synthDelay);
REG_WRITE(ah, AR_PHY_RFBUS_REQ, 0);
}
static void ar5008_restore_chainmask(struct ath_hw *ah)
{
int rx_chainmask = ah->rxchainmask;
if ((rx_chainmask == 0x5) || (rx_chainmask == 0x3)) {
REG_WRITE(ah, AR_PHY_RX_CHAINMASK, rx_chainmask);
REG_WRITE(ah, AR_PHY_CAL_CHAINMASK, rx_chainmask);
}
}
static u32 ar9160_hw_compute_pll_control(struct ath_hw *ah,
struct ath9k_channel *chan)
{
u32 pll;
pll = SM(0x5, AR_RTC_9160_PLL_REFDIV);
if (chan && IS_CHAN_HALF_RATE(chan))
pll |= SM(0x1, AR_RTC_9160_PLL_CLKSEL);
else if (chan && IS_CHAN_QUARTER_RATE(chan))
pll |= SM(0x2, AR_RTC_9160_PLL_CLKSEL);
if (chan && IS_CHAN_5GHZ(chan))
pll |= SM(0x50, AR_RTC_9160_PLL_DIV);
else
pll |= SM(0x58, AR_RTC_9160_PLL_DIV);
return pll;
}
static u32 ar5008_hw_compute_pll_control(struct ath_hw *ah,
struct ath9k_channel *chan)
{
u32 pll;
pll = AR_RTC_PLL_REFDIV_5 | AR_RTC_PLL_DIV2;
if (chan && IS_CHAN_HALF_RATE(chan))
pll |= SM(0x1, AR_RTC_PLL_CLKSEL);
else if (chan && IS_CHAN_QUARTER_RATE(chan))
pll |= SM(0x2, AR_RTC_PLL_CLKSEL);
if (chan && IS_CHAN_5GHZ(chan))
pll |= SM(0xa, AR_RTC_PLL_DIV);
else
pll |= SM(0xb, AR_RTC_PLL_DIV);
return pll;
}
static bool ar5008_hw_ani_control_new(struct ath_hw *ah,
enum ath9k_ani_cmd cmd,
int param)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_channel *chan = ah->curchan;
struct ar5416AniState *aniState = &chan->ani;
s32 value, value2;
switch (cmd & ah->ani_function) {
case ATH9K_ANI_OFDM_WEAK_SIGNAL_DETECTION:{
u32 on = param ? 1 : 0;
int m1ThreshLow = on ?
aniState->iniDef.m1ThreshLow : m1ThreshLow_off;
int m2ThreshLow = on ?
aniState->iniDef.m2ThreshLow : m2ThreshLow_off;
int m1Thresh = on ?
aniState->iniDef.m1Thresh : m1Thresh_off;
int m2Thresh = on ?
aniState->iniDef.m2Thresh : m2Thresh_off;
int m2CountThr = on ?
aniState->iniDef.m2CountThr : m2CountThr_off;
int m2CountThrLow = on ?
aniState->iniDef.m2CountThrLow : m2CountThrLow_off;
int m1ThreshLowExt = on ?
aniState->iniDef.m1ThreshLowExt : m1ThreshLowExt_off;
int m2ThreshLowExt = on ?
aniState->iniDef.m2ThreshLowExt : m2ThreshLowExt_off;
int m1ThreshExt = on ?
aniState->iniDef.m1ThreshExt : m1ThreshExt_off;
int m2ThreshExt = on ?
aniState->iniDef.m2ThreshExt : m2ThreshExt_off;
REG_RMW_FIELD(ah, AR_PHY_SFCORR_LOW,
AR_PHY_SFCORR_LOW_M1_THRESH_LOW,
m1ThreshLow);
REG_RMW_FIELD(ah, AR_PHY_SFCORR_LOW,
AR_PHY_SFCORR_LOW_M2_THRESH_LOW,
m2ThreshLow);
REG_RMW_FIELD(ah, AR_PHY_SFCORR,
AR_PHY_SFCORR_M1_THRESH, m1Thresh);
REG_RMW_FIELD(ah, AR_PHY_SFCORR,
AR_PHY_SFCORR_M2_THRESH, m2Thresh);
REG_RMW_FIELD(ah, AR_PHY_SFCORR,
AR_PHY_SFCORR_M2COUNT_THR, m2CountThr);
REG_RMW_FIELD(ah, AR_PHY_SFCORR_LOW,
AR_PHY_SFCORR_LOW_M2COUNT_THR_LOW,
m2CountThrLow);
REG_RMW_FIELD(ah, AR_PHY_SFCORR_EXT,
AR_PHY_SFCORR_EXT_M1_THRESH_LOW, m1ThreshLowExt);
REG_RMW_FIELD(ah, AR_PHY_SFCORR_EXT,
AR_PHY_SFCORR_EXT_M2_THRESH_LOW, m2ThreshLowExt);
REG_RMW_FIELD(ah, AR_PHY_SFCORR_EXT,
AR_PHY_SFCORR_EXT_M1_THRESH, m1ThreshExt);
REG_RMW_FIELD(ah, AR_PHY_SFCORR_EXT,
AR_PHY_SFCORR_EXT_M2_THRESH, m2ThreshExt);
if (on)
REG_SET_BIT(ah, AR_PHY_SFCORR_LOW,
AR_PHY_SFCORR_LOW_USE_SELF_CORR_LOW);
else
REG_CLR_BIT(ah, AR_PHY_SFCORR_LOW,
AR_PHY_SFCORR_LOW_USE_SELF_CORR_LOW);
if (on != aniState->ofdmWeakSigDetect) {
ath_dbg(common, ANI,
"** ch %d: ofdm weak signal: %s=>%s\n",
chan->channel,
aniState->ofdmWeakSigDetect ?
"on" : "off",
on ? "on" : "off");
if (on)
ah->stats.ast_ani_ofdmon++;
else
ah->stats.ast_ani_ofdmoff++;
aniState->ofdmWeakSigDetect = on;
}
break;
}
case ATH9K_ANI_FIRSTEP_LEVEL:{
u32 level = param;
if (level >= ARRAY_SIZE(firstep_table)) {
ath_dbg(common, ANI,
"ATH9K_ANI_FIRSTEP_LEVEL: level out of range (%u > %zu)\n",
level, ARRAY_SIZE(firstep_table));
return false;
}
value = firstep_table[level] -
firstep_table[ATH9K_ANI_FIRSTEP_LVL] +
aniState->iniDef.firstep;
if (value < ATH9K_SIG_FIRSTEP_SETTING_MIN)
value = ATH9K_SIG_FIRSTEP_SETTING_MIN;
if (value > ATH9K_SIG_FIRSTEP_SETTING_MAX)
value = ATH9K_SIG_FIRSTEP_SETTING_MAX;
REG_RMW_FIELD(ah, AR_PHY_FIND_SIG,
AR_PHY_FIND_SIG_FIRSTEP,
value);
value2 = firstep_table[level] -
firstep_table[ATH9K_ANI_FIRSTEP_LVL] +
aniState->iniDef.firstepLow;
if (value2 < ATH9K_SIG_FIRSTEP_SETTING_MIN)
value2 = ATH9K_SIG_FIRSTEP_SETTING_MIN;
if (value2 > ATH9K_SIG_FIRSTEP_SETTING_MAX)
value2 = ATH9K_SIG_FIRSTEP_SETTING_MAX;
REG_RMW_FIELD(ah, AR_PHY_FIND_SIG_LOW,
AR_PHY_FIND_SIG_FIRSTEP_LOW, value2);
if (level != aniState->firstepLevel) {
ath_dbg(common, ANI,
"** ch %d: level %d=>%d[def:%d] firstep[level]=%d ini=%d\n",
chan->channel,
aniState->firstepLevel,
level,
ATH9K_ANI_FIRSTEP_LVL,
value,
aniState->iniDef.firstep);
ath_dbg(common, ANI,
"** ch %d: level %d=>%d[def:%d] firstep_low[level]=%d ini=%d\n",
chan->channel,
aniState->firstepLevel,
level,
ATH9K_ANI_FIRSTEP_LVL,
value2,
aniState->iniDef.firstepLow);
if (level > aniState->firstepLevel)
ah->stats.ast_ani_stepup++;
else if (level < aniState->firstepLevel)
ah->stats.ast_ani_stepdown++;
aniState->firstepLevel = level;
}
break;
}
case ATH9K_ANI_SPUR_IMMUNITY_LEVEL:{
u32 level = param;
if (level >= ARRAY_SIZE(cycpwrThr1_table)) {
ath_dbg(common, ANI,
"ATH9K_ANI_SPUR_IMMUNITY_LEVEL: level out of range (%u > %zu)\n",
level, ARRAY_SIZE(cycpwrThr1_table));
return false;
}
value = cycpwrThr1_table[level] -
cycpwrThr1_table[ATH9K_ANI_SPUR_IMMUNE_LVL] +
aniState->iniDef.cycpwrThr1;
if (value < ATH9K_SIG_SPUR_IMM_SETTING_MIN)
value = ATH9K_SIG_SPUR_IMM_SETTING_MIN;
if (value > ATH9K_SIG_SPUR_IMM_SETTING_MAX)
value = ATH9K_SIG_SPUR_IMM_SETTING_MAX;
REG_RMW_FIELD(ah, AR_PHY_TIMING5,
AR_PHY_TIMING5_CYCPWR_THR1,
value);
value2 = cycpwrThr1_table[level] -
cycpwrThr1_table[ATH9K_ANI_SPUR_IMMUNE_LVL] +
aniState->iniDef.cycpwrThr1Ext;
if (value2 < ATH9K_SIG_SPUR_IMM_SETTING_MIN)
value2 = ATH9K_SIG_SPUR_IMM_SETTING_MIN;
if (value2 > ATH9K_SIG_SPUR_IMM_SETTING_MAX)
value2 = ATH9K_SIG_SPUR_IMM_SETTING_MAX;
REG_RMW_FIELD(ah, AR_PHY_EXT_CCA,
AR_PHY_EXT_TIMING5_CYCPWR_THR1, value2);
if (level != aniState->spurImmunityLevel) {
ath_dbg(common, ANI,
"** ch %d: level %d=>%d[def:%d] cycpwrThr1[level]=%d ini=%d\n",
chan->channel,
aniState->spurImmunityLevel,
level,
ATH9K_ANI_SPUR_IMMUNE_LVL,
value,
aniState->iniDef.cycpwrThr1);
ath_dbg(common, ANI,
"** ch %d: level %d=>%d[def:%d] cycpwrThr1Ext[level]=%d ini=%d\n",
chan->channel,
aniState->spurImmunityLevel,
level,
ATH9K_ANI_SPUR_IMMUNE_LVL,
value2,
aniState->iniDef.cycpwrThr1Ext);
if (level > aniState->spurImmunityLevel)
ah->stats.ast_ani_spurup++;
else if (level < aniState->spurImmunityLevel)
ah->stats.ast_ani_spurdown++;
aniState->spurImmunityLevel = level;
}
break;
}
case ATH9K_ANI_MRC_CCK:
WARN_ON(1);
break;
case ATH9K_ANI_PRESENT:
break;
default:
ath_dbg(common, ANI, "invalid cmd %u\n", cmd);
return false;
}
ath_dbg(common, ANI,
"ANI parameters: SI=%d, ofdmWS=%s FS=%d MRCcck=%s listenTime=%d ofdmErrs=%d cckErrs=%d\n",
aniState->spurImmunityLevel,
aniState->ofdmWeakSigDetect ? "on" : "off",
aniState->firstepLevel,
aniState->mrcCCK ? "on" : "off",
aniState->listenTime,
aniState->ofdmPhyErrCount,
aniState->cckPhyErrCount);
return true;
}
static void ar5008_hw_do_getnf(struct ath_hw *ah,
int16_t nfarray[NUM_NF_READINGS])
{
int16_t nf;
nf = MS(REG_READ(ah, AR_PHY_CCA), AR_PHY_MINCCA_PWR);
nfarray[0] = sign_extend32(nf, 8);
nf = MS(REG_READ(ah, AR_PHY_CH1_CCA), AR_PHY_CH1_MINCCA_PWR);
nfarray[1] = sign_extend32(nf, 8);
nf = MS(REG_READ(ah, AR_PHY_CH2_CCA), AR_PHY_CH2_MINCCA_PWR);
nfarray[2] = sign_extend32(nf, 8);
if (!IS_CHAN_HT40(ah->curchan))
return;
nf = MS(REG_READ(ah, AR_PHY_EXT_CCA), AR_PHY_EXT_MINCCA_PWR);
nfarray[3] = sign_extend32(nf, 8);
nf = MS(REG_READ(ah, AR_PHY_CH1_EXT_CCA), AR_PHY_CH1_EXT_MINCCA_PWR);
nfarray[4] = sign_extend32(nf, 8);
nf = MS(REG_READ(ah, AR_PHY_CH2_EXT_CCA), AR_PHY_CH2_EXT_MINCCA_PWR);
nfarray[5] = sign_extend32(nf, 8);
}
static void ar5008_hw_ani_cache_ini_regs(struct ath_hw *ah)
{
struct ath_common *common = ath9k_hw_common(ah);
struct ath9k_channel *chan = ah->curchan;
struct ar5416AniState *aniState = &chan->ani;
struct ath9k_ani_default *iniDef;
u32 val;
iniDef = &aniState->iniDef;
ath_dbg(common, ANI, "ver %d.%d opmode %u chan %d Mhz/0x%x\n",
ah->hw_version.macVersion,
ah->hw_version.macRev,
ah->opmode,
chan->channel,
chan->channelFlags);
val = REG_READ(ah, AR_PHY_SFCORR);
iniDef->m1Thresh = MS(val, AR_PHY_SFCORR_M1_THRESH);
iniDef->m2Thresh = MS(val, AR_PHY_SFCORR_M2_THRESH);
iniDef->m2CountThr = MS(val, AR_PHY_SFCORR_M2COUNT_THR);
val = REG_READ(ah, AR_PHY_SFCORR_LOW);
iniDef->m1ThreshLow = MS(val, AR_PHY_SFCORR_LOW_M1_THRESH_LOW);
iniDef->m2ThreshLow = MS(val, AR_PHY_SFCORR_LOW_M2_THRESH_LOW);
iniDef->m2CountThrLow = MS(val, AR_PHY_SFCORR_LOW_M2COUNT_THR_LOW);
val = REG_READ(ah, AR_PHY_SFCORR_EXT);
iniDef->m1ThreshExt = MS(val, AR_PHY_SFCORR_EXT_M1_THRESH);
iniDef->m2ThreshExt = MS(val, AR_PHY_SFCORR_EXT_M2_THRESH);
iniDef->m1ThreshLowExt = MS(val, AR_PHY_SFCORR_EXT_M1_THRESH_LOW);
iniDef->m2ThreshLowExt = MS(val, AR_PHY_SFCORR_EXT_M2_THRESH_LOW);
iniDef->firstep = REG_READ_FIELD(ah,
AR_PHY_FIND_SIG,
AR_PHY_FIND_SIG_FIRSTEP);
iniDef->firstepLow = REG_READ_FIELD(ah,
AR_PHY_FIND_SIG_LOW,
AR_PHY_FIND_SIG_FIRSTEP_LOW);
iniDef->cycpwrThr1 = REG_READ_FIELD(ah,
AR_PHY_TIMING5,
AR_PHY_TIMING5_CYCPWR_THR1);
iniDef->cycpwrThr1Ext = REG_READ_FIELD(ah,
AR_PHY_EXT_CCA,
AR_PHY_EXT_TIMING5_CYCPWR_THR1);
aniState->spurImmunityLevel = ATH9K_ANI_SPUR_IMMUNE_LVL;
aniState->firstepLevel = ATH9K_ANI_FIRSTEP_LVL;
aniState->ofdmWeakSigDetect = ATH9K_ANI_USE_OFDM_WEAK_SIG;
aniState->mrcCCK = false;
}
static void ar5008_hw_set_nf_limits(struct ath_hw *ah)
{
ah->nf_2g.max = AR_PHY_CCA_MAX_GOOD_VAL_5416_2GHZ;
ah->nf_2g.min = AR_PHY_CCA_MIN_GOOD_VAL_5416_2GHZ;
ah->nf_2g.nominal = AR_PHY_CCA_NOM_VAL_5416_2GHZ;
ah->nf_5g.max = AR_PHY_CCA_MAX_GOOD_VAL_5416_5GHZ;
ah->nf_5g.min = AR_PHY_CCA_MIN_GOOD_VAL_5416_5GHZ;
ah->nf_5g.nominal = AR_PHY_CCA_NOM_VAL_5416_5GHZ;
}
static void ar5008_hw_set_radar_params(struct ath_hw *ah,
struct ath_hw_radar_conf *conf)
{
u32 radar_0 = 0, radar_1 = 0;
if (!conf) {
REG_CLR_BIT(ah, AR_PHY_RADAR_0, AR_PHY_RADAR_0_ENA);
return;
}
radar_0 |= AR_PHY_RADAR_0_ENA | AR_PHY_RADAR_0_FFT_ENA;
radar_0 |= SM(conf->fir_power, AR_PHY_RADAR_0_FIRPWR);
radar_0 |= SM(conf->radar_rssi, AR_PHY_RADAR_0_RRSSI);
radar_0 |= SM(conf->pulse_height, AR_PHY_RADAR_0_HEIGHT);
radar_0 |= SM(conf->pulse_rssi, AR_PHY_RADAR_0_PRSSI);
radar_0 |= SM(conf->pulse_inband, AR_PHY_RADAR_0_INBAND);
radar_1 |= AR_PHY_RADAR_1_MAX_RRSSI;
radar_1 |= AR_PHY_RADAR_1_BLOCK_CHECK;
radar_1 |= SM(conf->pulse_maxlen, AR_PHY_RADAR_1_MAXLEN);
radar_1 |= SM(conf->pulse_inband_step, AR_PHY_RADAR_1_RELSTEP_THRESH);
radar_1 |= SM(conf->radar_inband, AR_PHY_RADAR_1_RELPWR_THRESH);
REG_WRITE(ah, AR_PHY_RADAR_0, radar_0);
REG_WRITE(ah, AR_PHY_RADAR_1, radar_1);
if (conf->ext_channel)
REG_SET_BIT(ah, AR_PHY_RADAR_EXT, AR_PHY_RADAR_EXT_ENA);
else
REG_CLR_BIT(ah, AR_PHY_RADAR_EXT, AR_PHY_RADAR_EXT_ENA);
}
static void ar5008_hw_set_radar_conf(struct ath_hw *ah)
{
struct ath_hw_radar_conf *conf = &ah->radar_conf;
conf->fir_power = -33;
conf->radar_rssi = 20;
conf->pulse_height = 10;
conf->pulse_rssi = 24;
conf->pulse_inband = 15;
conf->pulse_maxlen = 255;
conf->pulse_inband_step = 12;
conf->radar_inband = 8;
}
int ar5008_hw_attach_phy_ops(struct ath_hw *ah)
{
struct ath_hw_private_ops *priv_ops = ath9k_hw_private_ops(ah);
static const u32 ar5416_cca_regs[6] = {
AR_PHY_CCA,
AR_PHY_CH1_CCA,
AR_PHY_CH2_CCA,
AR_PHY_EXT_CCA,
AR_PHY_CH1_EXT_CCA,
AR_PHY_CH2_EXT_CCA
};
int ret;
ret = ar5008_hw_rf_alloc_ext_banks(ah);
if (ret)
return ret;
priv_ops->rf_set_freq = ar5008_hw_set_channel;
priv_ops->spur_mitigate_freq = ar5008_hw_spur_mitigate;
priv_ops->set_rf_regs = ar5008_hw_set_rf_regs;
priv_ops->set_channel_regs = ar5008_hw_set_channel_regs;
priv_ops->init_bb = ar5008_hw_init_bb;
priv_ops->process_ini = ar5008_hw_process_ini;
priv_ops->set_rfmode = ar5008_hw_set_rfmode;
priv_ops->mark_phy_inactive = ar5008_hw_mark_phy_inactive;
priv_ops->set_delta_slope = ar5008_hw_set_delta_slope;
priv_ops->rfbus_req = ar5008_hw_rfbus_req;
priv_ops->rfbus_done = ar5008_hw_rfbus_done;
priv_ops->restore_chainmask = ar5008_restore_chainmask;
priv_ops->do_getnf = ar5008_hw_do_getnf;
priv_ops->set_radar_params = ar5008_hw_set_radar_params;
priv_ops->ani_control = ar5008_hw_ani_control_new;
priv_ops->ani_cache_ini_regs = ar5008_hw_ani_cache_ini_regs;
if (AR_SREV_9100(ah) || AR_SREV_9160_10_OR_LATER(ah))
priv_ops->compute_pll_control = ar9160_hw_compute_pll_control;
else
priv_ops->compute_pll_control = ar5008_hw_compute_pll_control;
ar5008_hw_set_nf_limits(ah);
ar5008_hw_set_radar_conf(ah);
memcpy(ah->nf_regs, ar5416_cca_regs, sizeof(ah->nf_regs));
return 0;
}
