static enum qed_resc_lock qed_ptcdev_to_resc(struct qed_hwfn *p_hwfn)
{
switch (qed_device_get_port_id(p_hwfn->cdev)) {
case 0:
return QED_RESC_LOCK_PTP_PORT0;
case 1:
return QED_RESC_LOCK_PTP_PORT1;
case 2:
return QED_RESC_LOCK_PTP_PORT2;
case 3:
return QED_RESC_LOCK_PTP_PORT3;
default:
return QED_RESC_LOCK_RESC_INVALID;
}
}
static int qed_ptp_res_lock(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt)
{
struct qed_resc_lock_params params;
enum qed_resc_lock resource;
int rc;
resource = qed_ptcdev_to_resc(p_hwfn);
if (resource == QED_RESC_LOCK_RESC_INVALID)
return -EINVAL;
qed_mcp_resc_lock_default_init(&params, NULL, resource, true);
rc = qed_mcp_resc_lock(p_hwfn, p_ptt, &params);
if (rc && rc != -EINVAL) {
return rc;
} else if (rc == -EINVAL) {
if (p_hwfn->abs_pf_id < p_hwfn->cdev->num_ports_in_engines)
return 0;
DP_INFO(p_hwfn, "PF doesn't have lock ownership\n");
return -EBUSY;
} else if (!rc && !params.b_granted) {
DP_INFO(p_hwfn, "Failed to acquire ptp resource lock\n");
return -EBUSY;
}
return rc;
}
static int qed_ptp_res_unlock(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt)
{
struct qed_resc_unlock_params params;
enum qed_resc_lock resource;
int rc;
resource = qed_ptcdev_to_resc(p_hwfn);
if (resource == QED_RESC_LOCK_RESC_INVALID)
return -EINVAL;
qed_mcp_resc_lock_default_init(NULL, &params, resource, true);
rc = qed_mcp_resc_unlock(p_hwfn, p_ptt, &params);
if (rc == -EINVAL) {
if (p_hwfn->abs_pf_id < p_hwfn->cdev->num_ports_in_engines) {
rc = 0;
} else {
DP_INFO(p_hwfn, "PF doesn't have lock ownership\n");
return -EINVAL;
}
} else if (rc) {
DP_INFO(p_hwfn, "Failed to release the ptp resource lock\n");
}
return rc;
}
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
static int qed_ptp_hw_cfg_filters(struct qed_dev *cdev,
enum qed_ptp_filter_type rx_type,
enum qed_ptp_hwtstamp_tx_type tx_type)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
u32 rule_mask, enable_cfg = 0x0;
switch (rx_type) {
case QED_PTP_FILTER_NONE:
enable_cfg = 0x0;
rule_mask = 0x3FFF;
break;
case QED_PTP_FILTER_ALL:
enable_cfg = 0x7;
rule_mask = 0x3CAA;
break;
case QED_PTP_FILTER_V1_L4_EVENT:
enable_cfg = 0x3;
rule_mask = 0x3FFA;
break;
case QED_PTP_FILTER_V1_L4_GEN:
enable_cfg = 0x3;
rule_mask = 0x3FFE;
break;
case QED_PTP_FILTER_V2_L4_EVENT:
enable_cfg = 0x5;
rule_mask = 0x3FAA;
break;
case QED_PTP_FILTER_V2_L4_GEN:
enable_cfg = 0x5;
rule_mask = 0x3FEE;
break;
case QED_PTP_FILTER_V2_L2_EVENT:
enable_cfg = 0x5;
rule_mask = 0x3CFF;
break;
case QED_PTP_FILTER_V2_L2_GEN:
enable_cfg = 0x5;
rule_mask = 0x3EFF;
break;
case QED_PTP_FILTER_V2_EVENT:
enable_cfg = 0x5;
rule_mask = 0x3CAA;
break;
case QED_PTP_FILTER_V2_GEN:
enable_cfg = 0x5;
rule_mask = 0x3EEE;
break;
default:
DP_INFO(p_hwfn, "Invalid PTP filter type %d\n", rx_type);
return -EINVAL;
}
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_PARAM_MASK, 0);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_RULE_MASK, rule_mask);
qed_wr(p_hwfn, p_ptt, NIG_REG_RX_PTP_EN, enable_cfg);
if (tx_type == QED_PTP_HWTSTAMP_TX_OFF) {
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_PTP_EN, 0x0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_RULE_MASK, 0x3FFF);
} else {
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_PTP_EN, enable_cfg);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_PARAM_MASK, 0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_RULE_MASK, rule_mask);
}
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
struct qed_ptt *p_ptt;
int rc;
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt) {
DP_NOTICE(p_hwfn, "Failed to acquire PTT for PTP\n");
return -EBUSY;
}
p_hwfn->p_ptp_ptt = p_ptt;
rc = qed_ptp_res_lock(p_hwfn, p_ptt);
if (rc) {
DP_INFO(p_hwfn,
"Couldn't acquire the resource lock, skip ptp enable for this PF\n");
qed_ptt_release(p_hwfn, p_ptt);
p_hwfn->p_ptp_ptt = NULL;
return rc;
}
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_PTP_EN, 7);
qed_wr(p_hwfn, p_ptt, NIG_REG_RX_PTP_EN, 7);
qed_wr(p_hwfn, p_ptt, NIG_REG_TS_OUTPUT_ENABLE_PDA, 0x1);
if (QED_IS_BB_B0(p_hwfn->cdev))
qed_wr(p_hwfn, p_ptt, NIG_REG_TIMESYNC_GEN_REG_BB, 2);
if (QED_IS_AH(p_hwfn->cdev))
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_FREECNT_UPDATE_K2, 2);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_FREE_CNT_VALUE_LSB, 0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_FREE_CNT_VALUE_MSB, 0);
if (QED_IS_BB_B0(p_hwfn->cdev))
qed_wr(p_hwfn, p_ptt, NIG_REG_TIMESYNC_GEN_REG_BB, 4);
if (QED_IS_AH(p_hwfn->cdev)) {
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_FREECNT_UPDATE_K2, 4);
qed_wr(p_hwfn, p_ptt, NIG_REG_PTP_LATCH_OSTS_PKT_TIME, 1);
}
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_DRIFT_CNTR_CONF, 0x0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TSGEN_RST_DRIFT_CNTR, 0x0);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_HOST_BUF_SEQID,
QED_TIMESTAMP_MASK);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_BUF_SEQID, QED_TIMESTAMP_MASK);
return 0;
}
static int qed_ptp_hw_disable(struct qed_dev *cdev)
{
struct qed_hwfn *p_hwfn = QED_LEADING_HWFN(cdev);
struct qed_ptt *p_ptt = p_hwfn->p_ptp_ptt;
qed_ptp_res_unlock(p_hwfn, p_ptt);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_PARAM_MASK, 0x7FF);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_LLH_PTP_RULE_MASK, 0x3FFF);
qed_wr(p_hwfn, p_ptt, NIG_REG_RX_PTP_EN, 0x0);
qed_wr(p_hwfn, p_ptt, NIG_REG_TX_PTP_EN, 0x0);
qed_ptt_release(p_hwfn, p_ptt);
p_hwfn->p_ptp_ptt = NULL;
return 0;
}
