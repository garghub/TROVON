static int qed_ptp_hw_read_rx_ts(struct qed_dev *cdev, u64 *timestamp)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
u32 val;
*timestamp = 0;
val = qed_rd(p_hwfn, p_ptt, NIG_REG_LLH_PTP_HOST_BUF_SEQID);
if (!(val & QED_TIMESTAMP_MASK)) {
DP_INFO(p_hwfn, "Invalid Rx timestamp, buf_seqid = %d\n", val);
return -EINVAL;
}
val = qed_rd(p_hwfn, p_ptt, NIG_REG_LLH_PTP_HOST_BUF_TS_LSB);
*timestamp = qed_rd(p_hwfn, p_ptt, NIG_REG_LLH_PTP_HOST_BUF_TS_MSB);
*timestamp <<= 32;
*timestamp |= val;
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_HOST_BUF_SEQID,
QED_TIMESTAMP_MASK);
return 0;
}
static int qed_ptp_hw_read_tx_ts(struct qed_dev *cdev, u64 *timestamp)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
u32 val;
*timestamp = 0;
val = qed_rd(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_BUF_SEQID);
if (!(val & QED_TIMESTAMP_MASK)) {
DP_INFO(p_hwfn, "Invalid Tx timestamp, buf_seqid = %d\n", val);
return -EINVAL;
}
val = qed_rd(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_BUF_TS_LSB);
*timestamp = qed_rd(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_BUF_TS_MSB);
*timestamp <<= 32;
*timestamp |= val;
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_BUF_SEQID, QED_TIMESTAMP_MASK);
return 0;
}
static int qed_ptp_hw_read_cc(struct qed_dev *cdev, u64 *phc_cycles)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
u32 temp = 0;
temp = qed_rd(p_hwfn, p_ptt, NIG_REG_TSGEN_SYNC_TIME_LSB);
*phc_cycles = qed_rd(p_hwfn, p_ptt, NIG_REG_TSGEN_SYNC_TIME_MSB);
*phc_cycles <<= 32;
*phc_cycles |= temp;
return 0;
}
static int qed_ptp_hw_cfg_rx_filters(struct qed_dev *cdev,
enum qed_ptp_filter_type type)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
u32 rule_mask, parm_mask;
switch (type) {
case QED_PTP_FILTER_L2_IPV4_IPV6:
parm_mask = 0x6AA;
rule_mask = 0x3EEE;
break;
case QED_PTP_FILTER_L2:
parm_mask = 0x6BF;
rule_mask = 0x3EFF;
break;
case QED_PTP_FILTER_IPV4_IPV6:
parm_mask = 0x7EA;
rule_mask = 0x3FFE;
break;
case QED_PTP_FILTER_IPV4:
parm_mask = 0x7EE;
rule_mask = 0x3FFE;
break;
default:
DP_INFO(p_hwfn, "Invalid PTP filter type %d\n", type);
return -EINVAL;
}
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_PARAM_MASK, parm_mask);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_RULE_MASK, rule_mask);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_TO_HOST, 0x1);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_HOST_BUF_SEQID,
QED_TIMESTAMP_MASK);
return 0;
}
static int qed_ptp_hw_adjfreq(struct qed_dev *cdev, s32 ppb)
{
s64 best_val = 0, val, best_period = 0, period, approx_dev, dif, dif2;
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
u32 drift_ctr_cfg = 0, drift_state;
int drift_dir = 1;
if (ppb < 0) {
ppb = -ppb;
drift_dir = 0;
}
if (ppb > 1) {
s64 best_dif = ppb, best_approx_dev = 1;
for (val = 7; val > 0; val--) {
period = div_s64(val * 1000000000, ppb);
period -= 8;
period >>= 4;
if (period < 1)
period = 1;
if (period > 0xFFFFFFE)
period = 0xFFFFFFE;
approx_dev = period * 16 + 8;
dif = ppb * approx_dev - val * 1000000000;
dif2 = dif + 16 * ppb;
if (dif < 0)
dif = -dif;
if (dif2 < 0)
dif2 = -dif2;
if (dif * (approx_dev + 16) > dif2 * approx_dev) {
period++;
approx_dev += 16;
dif = dif2;
}
if (best_dif * approx_dev > dif * best_approx_dev) {
best_dif = dif;
best_val = val;
best_period = period;
best_approx_dev = approx_dev;
}
}
} else if (ppb == 1) {
best_val = 4;
best_period = 0xee6b27f;
} else {
best_val = 0;
best_period = 0xFFFFFFF;
}
drift_ctr_cfg = (best_period << QED_DRIFT_CNTR_TIME_QUANTA_SHIFT) |
(((int)best_val) << QED_DRIFT_CNTR_ADJUSTMENT_SHIFT) |
(((int)drift_dir) << QED_DRIFT_CNTR_DIRECTION_SHIFT);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_RST_DRIFT_CNTR, 0x1);
drift_state = qed_rd(p_hwfn, p_ptt, NIG_REG_TSGEN_RST_DRIFT_CNTR);
if (drift_state & 1) {
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_DRIFT_CNTR_CONF,
drift_ctr_cfg);
} else {
DP_INFO(p_hwfn, "Drift counter is not reset\n");
return -EINVAL;
}
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_RST_DRIFT_CNTR, 0x0);
return 0;
}
static int qed_ptp_hw_enable(struct qed_dev *cdev)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_PTP_EN, 7);
qed_wr(p_hwfn, p_ptt, NIG_REG_RX_PTP_EN, 7);
qed_wr(p_hwfn, p_ptt, NIG_REG_TS_OUTPUT_ENABLE_PDA, 0x1);
qed_wr(p_hwfn, p_ptt, NIG_REG_TIMESYNC_GEN_REG_BB, 2);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_FREE_CNT_VALUE_LSB, 0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_FREE_CNT_VALUE_MSB, 0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TIMESYNC_GEN_REG_BB, 4);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_DRIFT_CNTR_CONF, 0x0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_RST_DRIFT_CNTR, 0x0);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_HOST_BUF_SEQID,
QED_TIMESTAMP_MASK);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_BUF_SEQID, QED_TIMESTAMP_MASK);
return 0;
}
static int qed_ptp_hw_hwtstamp_tx_on(struct qed_dev *cdev)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_PARAM_MASK, 0x6AA);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_RULE_MASK, 0x3EEE);
return 0;
}
static int qed_ptp_hw_disable(struct qed_dev *cdev)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_RX_PTP_EN, 0x0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_PTP_EN, 0x0);
return 0;
}
