void MTO_Init(struct wbsoft_priv *adapter)
{
int i;
MTO_PREAMBLE_TYPE() = MTO_PREAMBLE_SHORT;
MTO_CNT_ANT(0) = 0;
MTO_CNT_ANT(1) = 0;
MTO_SQ_ANT(0) = 0;
MTO_SQ_ANT(1) = 0;
MTO_AGING_TIMEOUT() = 0;
MTO_RATE_LEVEL() = 0;
MTO_FRAG_TH_LEVEL() = 4;
MTO_RTS_THRESHOLD() = MTO_FRAG_TH() + 1;
MTO_RTS_THRESHOLD_SETUP() = MTO_FRAG_TH() + 1;
MTO_RATE_CHANGE_ENABLE() = 1;
MTO_FRAG_CHANGE_ENABLE() = 0;
MTO_POWER_CHANGE_ENABLE() = 1;
MTO_PREAMBLE_CHANGE_ENABLE() = 1;
MTO_RTS_CHANGE_ENABLE() = 0;
for (i = 0; i < MTO_MAX_DATA_RATE_LEVELS; i++)
retryrate_rec[i] = 5;
MTO_TXFLOWCOUNT() = 0;
MTOPARA_PERIODIC_CHECK_CYCLE() = 10;
MTOPARA_RSSI_TH_FOR_ANTDIV() = 10;
MTOPARA_TXCOUNT_TH_FOR_CALC_RATE() = 50;
MTOPARA_TXRATE_INC_TH() = 10;
MTOPARA_TXRATE_DEC_TH() = 30;
MTOPARA_TXRATE_EQ_TH() = 40;
MTOPARA_TXRATE_BACKOFF() = 12;
MTOPARA_TXRETRYRATE_REDUCE() = 6;
if (MTO_TXPOWER_FROM_EEPROM == 0xff) {
switch (MTO_HAL()->phy_type) {
case RF_AIROHA_2230:
case RF_AIROHA_2230S:
MTOPARA_TXPOWER_INDEX() = 46;
break;
case RF_AIROHA_7230:
MTOPARA_TXPOWER_INDEX() = 49;
break;
case RF_WB_242:
MTOPARA_TXPOWER_INDEX() = 10;
break;
case RF_WB_242_1:
MTOPARA_TXPOWER_INDEX() = 24;
break;
}
} else {
MTOPARA_TXPOWER_INDEX() = MTO_TXPOWER_FROM_EEPROM;
}
RFSynthesizer_SetPowerIndex(MTO_HAL(), (u8) MTOPARA_TXPOWER_INDEX());
MTO_DATA().RSSI_high = -41;
MTO_DATA().RSSI_low = -60;
}
void MTO_SetTxCount(struct wbsoft_priv *adapter, u8 tx_rate, u8 index)
{
MTO_TXFLOWCOUNT()++;
if ((MTO_ENABLE == 1) && (MTO_RATE_CHANGE_ENABLE() == 1)) {
if (tx_rate == MTO_DATA_RATE()) {
if (index == 0) {
if (boSparseTxTraffic)
MTO_HAL()->dto_tx_frag_count += MTOPARA_PERIODIC_CHECK_CYCLE();
else
MTO_HAL()->dto_tx_frag_count += 1;
} else {
if (index < 8) {
MTO_HAL()->dto_tx_retry_count += index;
MTO_HAL()->dto_tx_frag_count += (index + 1);
} else {
MTO_HAL()->dto_tx_retry_count += 7;
MTO_HAL()->dto_tx_frag_count += 7;
}
}
} else if (MTO_DATA_RATE() > 48 && tx_rate == 48) {
if (index < 3) {
MTO_HAL()->dto_tx_retry_count += index;
MTO_HAL()->dto_tx_frag_count += (index + 1);
} else {
MTO_HAL()->dto_tx_retry_count += 3;
MTO_HAL()->dto_tx_frag_count += 3;
}
}
} else {
MTO_HAL()->dto_tx_retry_count += index;
MTO_HAL()->dto_tx_frag_count += (index + 1);
}
}
