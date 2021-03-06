static int
ath5k_hw_setup_2word_tx_desc(struct ath5k_hw *ah,
struct ath5k_desc *desc,
unsigned int pkt_len, unsigned int hdr_len,
int padsize,
enum ath5k_pkt_type type,
unsigned int tx_power,
unsigned int tx_rate0, unsigned int tx_tries0,
unsigned int key_index,
unsigned int antenna_mode,
unsigned int flags,
unsigned int rtscts_rate, unsigned int rtscts_duration)
{
u32 frame_type;
struct ath5k_hw_2w_tx_ctl *tx_ctl;
unsigned int frame_len;
tx_ctl = &desc->ud.ds_tx5210.tx_ctl;
if (unlikely(tx_tries0 == 0)) {
ATH5K_ERR(ah, "zero retries\n");
WARN_ON(1);
return -EINVAL;
}
if (unlikely(tx_rate0 == 0)) {
ATH5K_ERR(ah, "zero rate\n");
WARN_ON(1);
return -EINVAL;
}
memset(&desc->ud.ds_tx5210, 0, sizeof(struct ath5k_hw_5210_tx_desc));
frame_len = pkt_len - padsize + FCS_LEN;
if (frame_len & ~AR5K_2W_TX_DESC_CTL0_FRAME_LEN)
return -EINVAL;
tx_ctl->tx_control_0 = frame_len & AR5K_2W_TX_DESC_CTL0_FRAME_LEN;
if (type == AR5K_PKT_TYPE_BEACON)
pkt_len = roundup(pkt_len, 4);
if (pkt_len & ~AR5K_2W_TX_DESC_CTL1_BUF_LEN)
return -EINVAL;
tx_ctl->tx_control_1 = pkt_len & AR5K_2W_TX_DESC_CTL1_BUF_LEN;
if (ah->ah_version == AR5K_AR5210) {
if (hdr_len & ~AR5K_2W_TX_DESC_CTL0_HEADER_LEN_5210)
return -EINVAL;
tx_ctl->tx_control_0 |=
AR5K_REG_SM(hdr_len, AR5K_2W_TX_DESC_CTL0_HEADER_LEN_5210);
}
if (ah->ah_version == AR5K_AR5210) {
switch (type) {
case AR5K_PKT_TYPE_BEACON:
case AR5K_PKT_TYPE_PROBE_RESP:
frame_type = AR5K_AR5210_TX_DESC_FRAME_TYPE_NO_DELAY;
break;
case AR5K_PKT_TYPE_PIFS:
frame_type = AR5K_AR5210_TX_DESC_FRAME_TYPE_PIFS;
break;
default:
frame_type = type;
break;
}
tx_ctl->tx_control_0 |=
AR5K_REG_SM(frame_type, AR5K_2W_TX_DESC_CTL0_FRAME_TYPE_5210) |
AR5K_REG_SM(tx_rate0, AR5K_2W_TX_DESC_CTL0_XMIT_RATE);
} else {
tx_ctl->tx_control_0 |=
AR5K_REG_SM(tx_rate0, AR5K_2W_TX_DESC_CTL0_XMIT_RATE) |
AR5K_REG_SM(antenna_mode,
AR5K_2W_TX_DESC_CTL0_ANT_MODE_XMIT);
tx_ctl->tx_control_1 |=
AR5K_REG_SM(type, AR5K_2W_TX_DESC_CTL1_FRAME_TYPE_5211);
}
#define _TX_FLAGS(_c, _flag) \
if (flags & AR5K_TXDESC_##_flag) { \
tx_ctl->tx_control_##_c |= \
AR5K_2W_TX_DESC_CTL##_c##_##_flag; \
}
#define _TX_FLAGS_5211(_c, _flag) \
if (flags & AR5K_TXDESC_##_flag) { \
tx_ctl->tx_control_##_c |= \
AR5K_2W_TX_DESC_CTL##_c##_##_flag##_5211; \
}
_TX_FLAGS(0, CLRDMASK);
_TX_FLAGS(0, INTREQ);
_TX_FLAGS(0, RTSENA);
if (ah->ah_version == AR5K_AR5211) {
_TX_FLAGS_5211(0, VEOL);
_TX_FLAGS_5211(1, NOACK);
}
#undef _TX_FLAGS
#undef _TX_FLAGS_5211
if (key_index != AR5K_TXKEYIX_INVALID) {
tx_ctl->tx_control_0 |=
AR5K_2W_TX_DESC_CTL0_ENCRYPT_KEY_VALID;
tx_ctl->tx_control_1 |=
AR5K_REG_SM(key_index,
AR5K_2W_TX_DESC_CTL1_ENC_KEY_IDX);
}
if ((ah->ah_version == AR5K_AR5210) &&
(flags & (AR5K_TXDESC_RTSENA | AR5K_TXDESC_CTSENA)))
tx_ctl->tx_control_1 |= rtscts_duration &
AR5K_2W_TX_DESC_CTL1_RTS_DURATION_5210;
return 0;
}
static int
ath5k_hw_setup_4word_tx_desc(struct ath5k_hw *ah,
struct ath5k_desc *desc,
unsigned int pkt_len, unsigned int hdr_len,
int padsize,
enum ath5k_pkt_type type,
unsigned int tx_power,
unsigned int tx_rate0, unsigned int tx_tries0,
unsigned int key_index,
unsigned int antenna_mode,
unsigned int flags,
unsigned int rtscts_rate, unsigned int rtscts_duration)
{
struct ath5k_hw_4w_tx_ctl *tx_ctl;
unsigned int frame_len;
u32 txctl0 = 0, txctl1 = 0, txctl2 = 0, txctl3 = 0;
tx_ctl = &desc->ud.ds_tx5212.tx_ctl;
if (unlikely(tx_tries0 == 0)) {
ATH5K_ERR(ah, "zero retries\n");
WARN_ON(1);
return -EINVAL;
}
if (unlikely(tx_rate0 == 0)) {
ATH5K_ERR(ah, "zero rate\n");
WARN_ON(1);
return -EINVAL;
}
tx_power += ah->ah_txpower.txp_offset;
if (tx_power > AR5K_TUNE_MAX_TXPOWER)
tx_power = AR5K_TUNE_MAX_TXPOWER;
memset(&desc->ud.ds_tx5212.tx_stat, 0,
sizeof(desc->ud.ds_tx5212.tx_stat));
frame_len = pkt_len - padsize + FCS_LEN;
if (frame_len & ~AR5K_4W_TX_DESC_CTL0_FRAME_LEN)
return -EINVAL;
txctl0 = frame_len & AR5K_4W_TX_DESC_CTL0_FRAME_LEN;
if (type == AR5K_PKT_TYPE_BEACON)
pkt_len = roundup(pkt_len, 4);
if (pkt_len & ~AR5K_4W_TX_DESC_CTL1_BUF_LEN)
return -EINVAL;
txctl1 = pkt_len & AR5K_4W_TX_DESC_CTL1_BUF_LEN;
txctl0 |= AR5K_REG_SM(tx_power, AR5K_4W_TX_DESC_CTL0_XMIT_POWER) |
AR5K_REG_SM(antenna_mode, AR5K_4W_TX_DESC_CTL0_ANT_MODE_XMIT);
txctl1 |= AR5K_REG_SM(type, AR5K_4W_TX_DESC_CTL1_FRAME_TYPE);
txctl2 = AR5K_REG_SM(tx_tries0, AR5K_4W_TX_DESC_CTL2_XMIT_TRIES0);
txctl3 = tx_rate0 & AR5K_4W_TX_DESC_CTL3_XMIT_RATE0;
#define _TX_FLAGS(_c, _flag) \
if (flags & AR5K_TXDESC_##_flag) { \
txctl##_c |= AR5K_4W_TX_DESC_CTL##_c##_##_flag; \
}
_TX_FLAGS(0, CLRDMASK);
_TX_FLAGS(0, VEOL);
_TX_FLAGS(0, INTREQ);
_TX_FLAGS(0, RTSENA);
_TX_FLAGS(0, CTSENA);
_TX_FLAGS(1, NOACK);
#undef _TX_FLAGS
if (key_index != AR5K_TXKEYIX_INVALID) {
txctl0 |= AR5K_4W_TX_DESC_CTL0_ENCRYPT_KEY_VALID;
txctl1 |= AR5K_REG_SM(key_index,
AR5K_4W_TX_DESC_CTL1_ENCRYPT_KEY_IDX);
}
if (flags & (AR5K_TXDESC_RTSENA | AR5K_TXDESC_CTSENA)) {
if ((flags & AR5K_TXDESC_RTSENA) &&
(flags & AR5K_TXDESC_CTSENA))
return -EINVAL;
txctl2 |= rtscts_duration & AR5K_4W_TX_DESC_CTL2_RTS_DURATION;
txctl3 |= AR5K_REG_SM(rtscts_rate,
AR5K_4W_TX_DESC_CTL3_RTS_CTS_RATE);
}
tx_ctl->tx_control_0 = txctl0;
tx_ctl->tx_control_1 = txctl1;
tx_ctl->tx_control_2 = txctl2;
tx_ctl->tx_control_3 = txctl3;
return 0;
}
int
ath5k_hw_setup_mrr_tx_desc(struct ath5k_hw *ah,
struct ath5k_desc *desc,
u_int tx_rate1, u_int tx_tries1,
u_int tx_rate2, u_int tx_tries2,
u_int tx_rate3, u_int tx_tries3)
{
struct ath5k_hw_4w_tx_ctl *tx_ctl;
if (ah->ah_version < AR5K_AR5212)
return 0;
if (unlikely((tx_rate1 == 0 && tx_tries1 != 0) ||
(tx_rate2 == 0 && tx_tries2 != 0) ||
(tx_rate3 == 0 && tx_tries3 != 0))) {
ATH5K_ERR(ah, "zero rate\n");
WARN_ON(1);
return -EINVAL;
}
if (ah->ah_version == AR5K_AR5212) {
tx_ctl = &desc->ud.ds_tx5212.tx_ctl;
#define _XTX_TRIES(_n) \
if (tx_tries##_n) { \
tx_ctl->tx_control_2 |= \
AR5K_REG_SM(tx_tries##_n, \
AR5K_4W_TX_DESC_CTL2_XMIT_TRIES##_n); \
tx_ctl->tx_control_3 |= \
AR5K_REG_SM(tx_rate##_n, \
AR5K_4W_TX_DESC_CTL3_XMIT_RATE##_n); \
}
_XTX_TRIES(1);
_XTX_TRIES(2);
_XTX_TRIES(3);
#undef _XTX_TRIES
return 1;
}
return 0;
}
static int
ath5k_hw_proc_2word_tx_status(struct ath5k_hw *ah,
struct ath5k_desc *desc,
struct ath5k_tx_status *ts)
{
struct ath5k_hw_2w_tx_ctl *tx_ctl;
struct ath5k_hw_tx_status *tx_status;
tx_ctl = &desc->ud.ds_tx5210.tx_ctl;
tx_status = &desc->ud.ds_tx5210.tx_stat;
if (unlikely((tx_status->tx_status_1 & AR5K_DESC_TX_STATUS1_DONE) == 0))
return -EINPROGRESS;
ts->ts_tstamp = AR5K_REG_MS(tx_status->tx_status_0,
AR5K_DESC_TX_STATUS0_SEND_TIMESTAMP);
ts->ts_shortretry = AR5K_REG_MS(tx_status->tx_status_0,
AR5K_DESC_TX_STATUS0_SHORT_RETRY_COUNT);
ts->ts_final_retry = AR5K_REG_MS(tx_status->tx_status_0,
AR5K_DESC_TX_STATUS0_LONG_RETRY_COUNT);
ts->ts_seqnum = AR5K_REG_MS(tx_status->tx_status_1,
AR5K_DESC_TX_STATUS1_SEQ_NUM);
ts->ts_rssi = AR5K_REG_MS(tx_status->tx_status_1,
AR5K_DESC_TX_STATUS1_ACK_SIG_STRENGTH);
ts->ts_antenna = 1;
ts->ts_status = 0;
ts->ts_final_idx = 0;
if (!(tx_status->tx_status_0 & AR5K_DESC_TX_STATUS0_FRAME_XMIT_OK)) {
if (tx_status->tx_status_0 &
AR5K_DESC_TX_STATUS0_EXCESSIVE_RETRIES)
ts->ts_status |= AR5K_TXERR_XRETRY;
if (tx_status->tx_status_0 & AR5K_DESC_TX_STATUS0_FIFO_UNDERRUN)
ts->ts_status |= AR5K_TXERR_FIFO;
if (tx_status->tx_status_0 & AR5K_DESC_TX_STATUS0_FILTERED)
ts->ts_status |= AR5K_TXERR_FILT;
}
return 0;
}
static int
ath5k_hw_proc_4word_tx_status(struct ath5k_hw *ah,
struct ath5k_desc *desc,
struct ath5k_tx_status *ts)
{
struct ath5k_hw_4w_tx_ctl *tx_ctl;
struct ath5k_hw_tx_status *tx_status;
u32 txstat0, txstat1;
tx_ctl = &desc->ud.ds_tx5212.tx_ctl;
tx_status = &desc->ud.ds_tx5212.tx_stat;
txstat1 = ACCESS_ONCE(tx_status->tx_status_1);
if (unlikely(!(txstat1 & AR5K_DESC_TX_STATUS1_DONE)))
return -EINPROGRESS;
txstat0 = ACCESS_ONCE(tx_status->tx_status_0);
ts->ts_tstamp = AR5K_REG_MS(txstat0,
AR5K_DESC_TX_STATUS0_SEND_TIMESTAMP);
ts->ts_shortretry = AR5K_REG_MS(txstat0,
AR5K_DESC_TX_STATUS0_SHORT_RETRY_COUNT);
ts->ts_final_retry = AR5K_REG_MS(txstat0,
AR5K_DESC_TX_STATUS0_LONG_RETRY_COUNT);
ts->ts_seqnum = AR5K_REG_MS(txstat1,
AR5K_DESC_TX_STATUS1_SEQ_NUM);
ts->ts_rssi = AR5K_REG_MS(txstat1,
AR5K_DESC_TX_STATUS1_ACK_SIG_STRENGTH);
ts->ts_antenna = (txstat1 &
AR5K_DESC_TX_STATUS1_XMIT_ANTENNA_5212) ? 2 : 1;
ts->ts_status = 0;
ts->ts_final_idx = AR5K_REG_MS(txstat1,
AR5K_DESC_TX_STATUS1_FINAL_TS_IX_5212);
if (!(txstat0 & AR5K_DESC_TX_STATUS0_FRAME_XMIT_OK)) {
if (txstat0 & AR5K_DESC_TX_STATUS0_EXCESSIVE_RETRIES)
ts->ts_status |= AR5K_TXERR_XRETRY;
if (txstat0 & AR5K_DESC_TX_STATUS0_FIFO_UNDERRUN)
ts->ts_status |= AR5K_TXERR_FIFO;
if (txstat0 & AR5K_DESC_TX_STATUS0_FILTERED)
ts->ts_status |= AR5K_TXERR_FILT;
}
return 0;
}
int
ath5k_hw_setup_rx_desc(struct ath5k_hw *ah,
struct ath5k_desc *desc,
u32 size, unsigned int flags)
{
struct ath5k_hw_rx_ctl *rx_ctl;
rx_ctl = &desc->ud.ds_rx.rx_ctl;
memset(&desc->ud.ds_rx, 0, sizeof(struct ath5k_hw_all_rx_desc));
if (unlikely(size & ~AR5K_DESC_RX_CTL1_BUF_LEN))
return -EINVAL;
rx_ctl->rx_control_1 = size & AR5K_DESC_RX_CTL1_BUF_LEN;
if (flags & AR5K_RXDESC_INTREQ)
rx_ctl->rx_control_1 |= AR5K_DESC_RX_CTL1_INTREQ;
return 0;
}
static int
ath5k_hw_proc_5210_rx_status(struct ath5k_hw *ah,
struct ath5k_desc *desc,
struct ath5k_rx_status *rs)
{
struct ath5k_hw_rx_status *rx_status;
rx_status = &desc->ud.ds_rx.rx_stat;
if (unlikely(!(rx_status->rx_status_1 &
AR5K_5210_RX_DESC_STATUS1_DONE)))
return -EINPROGRESS;
memset(rs, 0, sizeof(struct ath5k_rx_status));
rs->rs_datalen = rx_status->rx_status_0 &
AR5K_5210_RX_DESC_STATUS0_DATA_LEN;
rs->rs_rssi = AR5K_REG_MS(rx_status->rx_status_0,
AR5K_5210_RX_DESC_STATUS0_RECEIVE_SIGNAL);
rs->rs_rate = AR5K_REG_MS(rx_status->rx_status_0,
AR5K_5210_RX_DESC_STATUS0_RECEIVE_RATE);
rs->rs_more = !!(rx_status->rx_status_0 &
AR5K_5210_RX_DESC_STATUS0_MORE);
rs->rs_tstamp = AR5K_REG_MS(rx_status->rx_status_1,
AR5K_5210_RX_DESC_STATUS1_RECEIVE_TIMESTAMP);
if (ah->ah_version == AR5K_AR5211)
rs->rs_antenna = AR5K_REG_MS(rx_status->rx_status_0,
AR5K_5210_RX_DESC_STATUS0_RECEIVE_ANT_5211);
else
rs->rs_antenna = (rx_status->rx_status_0 &
AR5K_5210_RX_DESC_STATUS0_RECEIVE_ANT_5210)
? 2 : 1;
if (rx_status->rx_status_1 & AR5K_5210_RX_DESC_STATUS1_KEY_INDEX_VALID)
rs->rs_keyix = AR5K_REG_MS(rx_status->rx_status_1,
AR5K_5210_RX_DESC_STATUS1_KEY_INDEX);
else
rs->rs_keyix = AR5K_RXKEYIX_INVALID;
if (!(rx_status->rx_status_1 &
AR5K_5210_RX_DESC_STATUS1_FRAME_RECEIVE_OK)) {
if (rx_status->rx_status_1 &
AR5K_5210_RX_DESC_STATUS1_CRC_ERROR)
rs->rs_status |= AR5K_RXERR_CRC;
if ((ah->ah_version == AR5K_AR5210) &&
(rx_status->rx_status_1 &
AR5K_5210_RX_DESC_STATUS1_FIFO_OVERRUN_5210))
rs->rs_status |= AR5K_RXERR_FIFO;
if (rx_status->rx_status_1 &
AR5K_5210_RX_DESC_STATUS1_PHY_ERROR) {
rs->rs_status |= AR5K_RXERR_PHY;
rs->rs_phyerr = AR5K_REG_MS(rx_status->rx_status_1,
AR5K_5210_RX_DESC_STATUS1_PHY_ERROR);
}
if (rx_status->rx_status_1 &
AR5K_5210_RX_DESC_STATUS1_DECRYPT_CRC_ERROR)
rs->rs_status |= AR5K_RXERR_DECRYPT;
}
return 0;
}
static int
ath5k_hw_proc_5212_rx_status(struct ath5k_hw *ah,
struct ath5k_desc *desc,
struct ath5k_rx_status *rs)
{
struct ath5k_hw_rx_status *rx_status;
u32 rxstat0, rxstat1;
rx_status = &desc->ud.ds_rx.rx_stat;
rxstat1 = ACCESS_ONCE(rx_status->rx_status_1);
if (unlikely(!(rxstat1 & AR5K_5212_RX_DESC_STATUS1_DONE)))
return -EINPROGRESS;
memset(rs, 0, sizeof(struct ath5k_rx_status));
rxstat0 = ACCESS_ONCE(rx_status->rx_status_0);
rs->rs_datalen = rxstat0 & AR5K_5212_RX_DESC_STATUS0_DATA_LEN;
rs->rs_rssi = AR5K_REG_MS(rxstat0,
AR5K_5212_RX_DESC_STATUS0_RECEIVE_SIGNAL);
rs->rs_rate = AR5K_REG_MS(rxstat0,
AR5K_5212_RX_DESC_STATUS0_RECEIVE_RATE);
rs->rs_antenna = AR5K_REG_MS(rxstat0,
AR5K_5212_RX_DESC_STATUS0_RECEIVE_ANTENNA);
rs->rs_more = !!(rxstat0 & AR5K_5212_RX_DESC_STATUS0_MORE);
rs->rs_tstamp = AR5K_REG_MS(rxstat1,
AR5K_5212_RX_DESC_STATUS1_RECEIVE_TIMESTAMP);
if (rxstat1 & AR5K_5212_RX_DESC_STATUS1_KEY_INDEX_VALID)
rs->rs_keyix = AR5K_REG_MS(rxstat1,
AR5K_5212_RX_DESC_STATUS1_KEY_INDEX);
else
rs->rs_keyix = AR5K_RXKEYIX_INVALID;
if (!(rxstat1 & AR5K_5212_RX_DESC_STATUS1_FRAME_RECEIVE_OK)) {
if (rxstat1 & AR5K_5212_RX_DESC_STATUS1_CRC_ERROR)
rs->rs_status |= AR5K_RXERR_CRC;
if (rxstat1 & AR5K_5212_RX_DESC_STATUS1_PHY_ERROR) {
rs->rs_status |= AR5K_RXERR_PHY;
rs->rs_phyerr = AR5K_REG_MS(rxstat1,
AR5K_5212_RX_DESC_STATUS1_PHY_ERROR_CODE);
if (!ah->ah_capabilities.cap_has_phyerr_counters)
ath5k_ani_phy_error_report(ah, rs->rs_phyerr);
}
if (rxstat1 & AR5K_5212_RX_DESC_STATUS1_DECRYPT_CRC_ERROR)
rs->rs_status |= AR5K_RXERR_DECRYPT;
if (rxstat1 & AR5K_5212_RX_DESC_STATUS1_MIC_ERROR)
rs->rs_status |= AR5K_RXERR_MIC;
}
return 0;
}
int
ath5k_hw_init_desc_functions(struct ath5k_hw *ah)
{
if (ah->ah_version == AR5K_AR5212) {
ah->ah_setup_tx_desc = ath5k_hw_setup_4word_tx_desc;
ah->ah_proc_tx_desc = ath5k_hw_proc_4word_tx_status;
ah->ah_proc_rx_desc = ath5k_hw_proc_5212_rx_status;
} else if (ah->ah_version <= AR5K_AR5211) {
ah->ah_setup_tx_desc = ath5k_hw_setup_2word_tx_desc;
ah->ah_proc_tx_desc = ath5k_hw_proc_2word_tx_status;
ah->ah_proc_rx_desc = ath5k_hw_proc_5210_rx_status;
} else
return -ENOTSUPP;
return 0;
}
