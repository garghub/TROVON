static void ixgbe_ptp_setup_sdp_x540(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int shift = adapter->hw_cc.shift;
u32 esdp, tsauxc, clktiml, clktimh, trgttiml, trgttimh, rem;
u64 ns = 0, clock_edge = 0;
IXGBE_WRITE_REG(hw, IXGBE_TSAUXC, 0x0);
IXGBE_WRITE_FLUSH(hw);
if (!(adapter->flags2 & IXGBE_FLAG2_PTP_PPS_ENABLED))
return;
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp |= IXGBE_ESDP_SDP0_DIR |
IXGBE_ESDP_SDP0_NATIVE;
tsauxc = IXGBE_TSAUXC_EN_CLK |
IXGBE_TSAUXC_SYNCLK |
IXGBE_TSAUXC_SDP0_INT;
clktiml = (u32)(IXGBE_PTP_PPS_HALF_SECOND << shift);
clktimh = (u32)((IXGBE_PTP_PPS_HALF_SECOND << shift) >> 32);
clock_edge |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIML);
clock_edge |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIMH) << 32;
ns = timecounter_cyc2time(&adapter->hw_tc, clock_edge);
div_u64_rem(ns, IXGBE_PTP_PPS_HALF_SECOND, &rem);
clock_edge += ((IXGBE_PTP_PPS_HALF_SECOND - (u64)rem) << shift);
trgttiml = (u32)clock_edge;
trgttimh = (u32)(clock_edge >> 32);
IXGBE_WRITE_REG(hw, IXGBE_CLKTIML, clktiml);
IXGBE_WRITE_REG(hw, IXGBE_CLKTIMH, clktimh);
IXGBE_WRITE_REG(hw, IXGBE_TRGTTIML0, trgttiml);
IXGBE_WRITE_REG(hw, IXGBE_TRGTTIMH0, trgttimh);
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_REG(hw, IXGBE_TSAUXC, tsauxc);
IXGBE_WRITE_FLUSH(hw);
}
static cycle_t ixgbe_ptp_read_X550(const struct cyclecounter *hw_cc)
{
struct ixgbe_adapter *adapter =
container_of(hw_cc, struct ixgbe_adapter, hw_cc);
struct ixgbe_hw *hw = &adapter->hw;
struct timespec64 ts;
IXGBE_READ_REG(hw, IXGBE_SYSTIMR);
ts.tv_nsec = IXGBE_READ_REG(hw, IXGBE_SYSTIML);
ts.tv_sec = IXGBE_READ_REG(hw, IXGBE_SYSTIMH);
return (u64)timespec64_to_ns(&ts);
}
static cycle_t ixgbe_ptp_read_82599(const struct cyclecounter *cc)
{
struct ixgbe_adapter *adapter =
container_of(cc, struct ixgbe_adapter, hw_cc);
struct ixgbe_hw *hw = &adapter->hw;
u64 stamp = 0;
stamp |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIML);
stamp |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIMH) << 32;
return stamp;
}
static void ixgbe_ptp_convert_to_hwtstamp(struct ixgbe_adapter *adapter,
struct skb_shared_hwtstamps *hwtstamp,
u64 timestamp)
{
unsigned long flags;
struct timespec64 systime;
u64 ns;
memset(hwtstamp, 0, sizeof(*hwtstamp));
switch (adapter->hw.mac.type) {
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
systime.tv_sec = timestamp >> 32;
systime.tv_nsec = timestamp & 0xFFFFFFFF;
timestamp = timespec64_to_ns(&systime);
break;
default:
break;
}
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_cyc2time(&adapter->hw_tc, timestamp);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
hwtstamp->hwtstamp = ns_to_ktime(ns);
}
static int ixgbe_ptp_adjfreq_82599(struct ptp_clock_info *ptp, s32 ppb)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
struct ixgbe_hw *hw = &adapter->hw;
u64 freq, incval;
u32 diff;
int neg_adj = 0;
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
smp_mb();
incval = ACCESS_ONCE(adapter->base_incval);
freq = incval;
freq *= ppb;
diff = div_u64(freq, 1000000000ULL);
incval = neg_adj ? (incval - diff) : (incval + diff);
switch (hw->mac.type) {
case ixgbe_mac_X540:
if (incval > 0xFFFFFFFFULL)
e_dev_warn("PTP ppb adjusted SYSTIME rate overflowed!\n");
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA, (u32)incval);
break;
case ixgbe_mac_82599EB:
if (incval > 0x00FFFFFFULL)
e_dev_warn("PTP ppb adjusted SYSTIME rate overflowed!\n");
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA,
(1 << IXGBE_INCPER_SHIFT_82599) |
((u32)incval & 0x00FFFFFFUL));
break;
default:
break;
}
return 0;
}
static int ixgbe_ptp_adjfreq_X550(struct ptp_clock_info *ptp, s32 ppb)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
struct ixgbe_hw *hw = &adapter->hw;
int neg_adj = 0;
u64 rate = IXGBE_X550_BASE_PERIOD;
u32 inca;
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
rate *= ppb;
rate = div_u64(rate, 1000000000ULL);
if (rate >= INCVALUE_MASK)
e_dev_warn("PTP ppb adjusted SYSTIME rate overflowed!\n");
inca = rate & INCVALUE_MASK;
if (neg_adj)
inca |= ISGN;
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA, inca);
return 0;
}
static int ixgbe_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
unsigned long flags;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_adjtime(&adapter->hw_tc, delta);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
if (adapter->ptp_setup_sdp)
adapter->ptp_setup_sdp(adapter);
return 0;
}
static int ixgbe_ptp_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
unsigned long flags;
u64 ns;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_read(&adapter->hw_tc);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
*ts = ns_to_timespec64(ns);
return 0;
}
static int ixgbe_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
unsigned long flags;
u64 ns = timespec64_to_ns(ts);
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_init(&adapter->hw_tc, &adapter->hw_cc, ns);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
if (adapter->ptp_setup_sdp)
adapter->ptp_setup_sdp(adapter);
return 0;
}
static int ixgbe_ptp_feature_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
if (rq->type != PTP_CLK_REQ_PPS || !adapter->ptp_setup_sdp)
return -ENOTSUPP;
if (on)
adapter->flags2 |= IXGBE_FLAG2_PTP_PPS_ENABLED;
else
adapter->flags2 &= ~IXGBE_FLAG2_PTP_PPS_ENABLED;
adapter->ptp_setup_sdp(adapter);
return 0;
}
void ixgbe_ptp_check_pps_event(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct ptp_clock_event event;
event.type = PTP_CLOCK_PPS;
if (!adapter->ptp_clock)
return;
switch (hw->mac.type) {
case ixgbe_mac_X540:
ptp_clock_event(adapter->ptp_clock, &event);
break;
default:
break;
}
}
void ixgbe_ptp_overflow_check(struct ixgbe_adapter *adapter)
{
bool timeout = time_is_before_jiffies(adapter->last_overflow_check +
IXGBE_OVERFLOW_PERIOD);
struct timespec64 ts;
if (timeout) {
ixgbe_ptp_gettime(&adapter->ptp_caps, &ts);
adapter->last_overflow_check = jiffies;
}
}
void ixgbe_ptp_rx_hang(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 tsyncrxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCRXCTL);
struct ixgbe_ring *rx_ring;
unsigned long rx_event;
int n;
if (!(tsyncrxctl & IXGBE_TSYNCRXCTL_VALID)) {
adapter->last_rx_ptp_check = jiffies;
return;
}
rx_event = adapter->last_rx_ptp_check;
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
if (time_after(rx_ring->last_rx_timestamp, rx_event))
rx_event = rx_ring->last_rx_timestamp;
}
if (time_is_before_jiffies(rx_event + 5 * HZ)) {
IXGBE_READ_REG(hw, IXGBE_RXSTMPH);
adapter->last_rx_ptp_check = jiffies;
adapter->rx_hwtstamp_cleared++;
e_warn(drv, "clearing RX Timestamp hang\n");
}
}
static void ixgbe_ptp_clear_tx_timestamp(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_READ_REG(hw, IXGBE_TXSTMPH);
if (adapter->ptp_tx_skb) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
}
clear_bit_unlock(__IXGBE_PTP_TX_IN_PROGRESS, &adapter->state);
}
static void ixgbe_ptp_tx_hwtstamp(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct skb_shared_hwtstamps shhwtstamps;
u64 regval = 0;
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_TXSTMPL);
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_TXSTMPH) << 32;
ixgbe_ptp_convert_to_hwtstamp(adapter, &shhwtstamps, regval);
skb_tstamp_tx(adapter->ptp_tx_skb, &shhwtstamps);
ixgbe_ptp_clear_tx_timestamp(adapter);
}
static void ixgbe_ptp_tx_hwtstamp_work(struct work_struct *work)
{
struct ixgbe_adapter *adapter = container_of(work, struct ixgbe_adapter,
ptp_tx_work);
struct ixgbe_hw *hw = &adapter->hw;
bool timeout = time_is_before_jiffies(adapter->ptp_tx_start +
IXGBE_PTP_TX_TIMEOUT);
u32 tsynctxctl;
if (!adapter->ptp_tx_skb) {
ixgbe_ptp_clear_tx_timestamp(adapter);
return;
}
tsynctxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCTXCTL);
if (tsynctxctl & IXGBE_TSYNCTXCTL_VALID) {
ixgbe_ptp_tx_hwtstamp(adapter);
return;
}
if (timeout) {
ixgbe_ptp_clear_tx_timestamp(adapter);
adapter->tx_hwtstamp_timeouts++;
e_warn(drv, "clearing Tx Timestamp hang\n");
} else {
schedule_work(&adapter->ptp_tx_work);
}
}
void ixgbe_ptp_rx_pktstamp(struct ixgbe_q_vector *q_vector,
struct sk_buff *skb)
{
__le64 regval;
skb_copy_bits(skb, skb->len - IXGBE_TS_HDR_LEN, &regval,
IXGBE_TS_HDR_LEN);
__pskb_trim(skb, skb->len - IXGBE_TS_HDR_LEN);
ixgbe_ptp_convert_to_hwtstamp(q_vector->adapter, skb_hwtstamps(skb),
le64_to_cpu(regval));
}
void ixgbe_ptp_rx_rgtstamp(struct ixgbe_q_vector *q_vector,
struct sk_buff *skb)
{
struct ixgbe_adapter *adapter;
struct ixgbe_hw *hw;
u64 regval = 0;
u32 tsyncrxctl;
if (!q_vector || !q_vector->adapter)
return;
adapter = q_vector->adapter;
hw = &adapter->hw;
tsyncrxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCRXCTL);
if (!(tsyncrxctl & IXGBE_TSYNCRXCTL_VALID))
return;
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_RXSTMPL);
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_RXSTMPH) << 32;
ixgbe_ptp_convert_to_hwtstamp(adapter, skb_hwtstamps(skb), regval);
}
int ixgbe_ptp_get_ts_config(struct ixgbe_adapter *adapter, struct ifreq *ifr)
{
struct hwtstamp_config *config = &adapter->tstamp_config;
return copy_to_user(ifr->ifr_data, config,
sizeof(*config)) ? -EFAULT : 0;
}
static int ixgbe_ptp_set_timestamp_mode(struct ixgbe_adapter *adapter,
struct hwtstamp_config *config)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 tsync_tx_ctl = IXGBE_TSYNCTXCTL_ENABLED;
u32 tsync_rx_ctl = IXGBE_TSYNCRXCTL_ENABLED;
u32 tsync_rx_mtrl = PTP_EV_PORT << 16;
bool is_l2 = false;
u32 regval;
if (config->flags)
return -EINVAL;
switch (config->tx_type) {
case HWTSTAMP_TX_OFF:
tsync_tx_ctl = 0;
case HWTSTAMP_TX_ON:
break;
default:
return -ERANGE;
}
switch (config->rx_filter) {
case HWTSTAMP_FILTER_NONE:
tsync_rx_ctl = 0;
tsync_rx_mtrl = 0;
adapter->flags &= ~(IXGBE_FLAG_RX_HWTSTAMP_ENABLED |
IXGBE_FLAG_RX_HWTSTAMP_IN_REGISTER);
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_mtrl |= IXGBE_RXMTRL_V1_SYNC_MSG;
adapter->flags &= ~(IXGBE_FLAG_RX_HWTSTAMP_ENABLED |
IXGBE_FLAG_RX_HWTSTAMP_IN_REGISTER);
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_mtrl |= IXGBE_RXMTRL_V1_DELAY_REQ_MSG;
adapter->flags &= ~(IXGBE_FLAG_RX_HWTSTAMP_ENABLED |
IXGBE_FLAG_RX_HWTSTAMP_IN_REGISTER);
break;
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_EVENT_V2;
is_l2 = true;
config->rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
adapter->flags &= ~(IXGBE_FLAG_RX_HWTSTAMP_ENABLED |
IXGBE_FLAG_RX_HWTSTAMP_IN_REGISTER);
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_ALL:
if (hw->mac.type >= ixgbe_mac_X550) {
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_ALL;
config->rx_filter = HWTSTAMP_FILTER_ALL;
adapter->flags |= IXGBE_FLAG_RX_HWTSTAMP_ENABLED;
break;
}
default:
adapter->flags &= ~(IXGBE_FLAG_RX_HWTSTAMP_ENABLED |
IXGBE_FLAG_RX_HWTSTAMP_IN_REGISTER);
config->rx_filter = HWTSTAMP_FILTER_NONE;
return -ERANGE;
}
if (hw->mac.type == ixgbe_mac_82598EB) {
adapter->flags &= ~(IXGBE_FLAG_RX_HWTSTAMP_ENABLED |
IXGBE_FLAG_RX_HWTSTAMP_IN_REGISTER);
if (tsync_rx_ctl | tsync_tx_ctl)
return -ERANGE;
return 0;
}
switch (hw->mac.type) {
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
if (config->rx_filter == HWTSTAMP_FILTER_NONE)
break;
tsync_rx_ctl = IXGBE_TSYNCRXCTL_ENABLED |
IXGBE_TSYNCRXCTL_TYPE_ALL |
IXGBE_TSYNCRXCTL_TSIP_UT_EN;
config->rx_filter = HWTSTAMP_FILTER_ALL;
adapter->flags |= IXGBE_FLAG_RX_HWTSTAMP_ENABLED;
adapter->flags &= ~IXGBE_FLAG_RX_HWTSTAMP_IN_REGISTER;
is_l2 = true;
break;
default:
break;
}
if (is_l2)
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_1588),
(IXGBE_ETQF_FILTER_EN |
IXGBE_ETQF_1588 |
ETH_P_1588));
else
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_1588), 0);
regval = IXGBE_READ_REG(hw, IXGBE_TSYNCTXCTL);
regval &= ~IXGBE_TSYNCTXCTL_ENABLED;
regval |= tsync_tx_ctl;
IXGBE_WRITE_REG(hw, IXGBE_TSYNCTXCTL, regval);
regval = IXGBE_READ_REG(hw, IXGBE_TSYNCRXCTL);
regval &= ~(IXGBE_TSYNCRXCTL_ENABLED | IXGBE_TSYNCRXCTL_TYPE_MASK);
regval |= tsync_rx_ctl;
IXGBE_WRITE_REG(hw, IXGBE_TSYNCRXCTL, regval);
IXGBE_WRITE_REG(hw, IXGBE_RXMTRL, tsync_rx_mtrl);
IXGBE_WRITE_FLUSH(hw);
ixgbe_ptp_clear_tx_timestamp(adapter);
IXGBE_READ_REG(hw, IXGBE_RXSTMPH);
return 0;
}
int ixgbe_ptp_set_ts_config(struct ixgbe_adapter *adapter, struct ifreq *ifr)
{
struct hwtstamp_config config;
int err;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
err = ixgbe_ptp_set_timestamp_mode(adapter, &config);
if (err)
return err;
memcpy(&adapter->tstamp_config, &config,
sizeof(adapter->tstamp_config));
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static void ixgbe_ptp_link_speed_adjust(struct ixgbe_adapter *adapter,
u32 *shift, u32 *incval)
{
switch (adapter->link_speed) {
case IXGBE_LINK_SPEED_100_FULL:
*shift = IXGBE_INCVAL_SHIFT_100;
*incval = IXGBE_INCVAL_100;
break;
case IXGBE_LINK_SPEED_1GB_FULL:
*shift = IXGBE_INCVAL_SHIFT_1GB;
*incval = IXGBE_INCVAL_1GB;
break;
case IXGBE_LINK_SPEED_10GB_FULL:
default:
*shift = IXGBE_INCVAL_SHIFT_10GB;
*incval = IXGBE_INCVAL_10GB;
break;
}
}
void ixgbe_ptp_start_cyclecounter(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct cyclecounter cc;
unsigned long flags;
u32 incval = 0;
u32 tsauxc = 0;
u32 fuse0 = 0;
cc.mask = CLOCKSOURCE_MASK(64);
cc.mult = 1;
cc.shift = 0;
switch (hw->mac.type) {
case ixgbe_mac_X550EM_x:
fuse0 = IXGBE_READ_REG(hw, IXGBE_FUSES0_GROUP(0));
if (!(fuse0 & IXGBE_FUSES0_300MHZ)) {
cc.mult = 3;
cc.shift = 2;
}
case ixgbe_mac_X550:
cc.read = ixgbe_ptp_read_X550;
IXGBE_WRITE_REG(hw, IXGBE_SYSTIMR, 0);
IXGBE_WRITE_REG(hw, IXGBE_SYSTIML, 0);
IXGBE_WRITE_REG(hw, IXGBE_SYSTIMH, 0);
tsauxc = IXGBE_READ_REG(hw, IXGBE_TSAUXC);
IXGBE_WRITE_REG(hw, IXGBE_TSAUXC,
tsauxc & ~IXGBE_TSAUXC_DISABLE_SYSTIME);
IXGBE_WRITE_REG(hw, IXGBE_TSIM, IXGBE_TSIM_TXTS);
IXGBE_WRITE_REG(hw, IXGBE_EIMS, IXGBE_EIMS_TIMESYNC);
IXGBE_WRITE_FLUSH(hw);
break;
case ixgbe_mac_X540:
cc.read = ixgbe_ptp_read_82599;
ixgbe_ptp_link_speed_adjust(adapter, &cc.shift, &incval);
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA, incval);
break;
case ixgbe_mac_82599EB:
cc.read = ixgbe_ptp_read_82599;
ixgbe_ptp_link_speed_adjust(adapter, &cc.shift, &incval);
incval >>= IXGBE_INCVAL_SHIFT_82599;
cc.shift -= IXGBE_INCVAL_SHIFT_82599;
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA,
(1 << IXGBE_INCPER_SHIFT_82599) | incval);
break;
default:
return;
}
ACCESS_ONCE(adapter->base_incval) = incval;
smp_mb();
spin_lock_irqsave(&adapter->tmreg_lock, flags);
memcpy(&adapter->hw_cc, &cc, sizeof(adapter->hw_cc));
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
}
void ixgbe_ptp_reset(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
unsigned long flags;
ixgbe_ptp_set_timestamp_mode(adapter, &adapter->tstamp_config);
if (hw->mac.type == ixgbe_mac_82598EB)
return;
ixgbe_ptp_start_cyclecounter(adapter);
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_init(&adapter->hw_tc, &adapter->hw_cc,
ktime_to_ns(ktime_get_real()));
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
adapter->last_overflow_check = jiffies;
if (adapter->ptp_setup_sdp)
adapter->ptp_setup_sdp(adapter);
}
static long ixgbe_ptp_create_clock(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
long err;
if (!IS_ERR_OR_NULL(adapter->ptp_clock))
return 0;
switch (adapter->hw.mac.type) {
case ixgbe_mac_X540:
snprintf(adapter->ptp_caps.name,
sizeof(adapter->ptp_caps.name),
"%s", netdev->name);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 250000000;
adapter->ptp_caps.n_alarm = 0;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.n_per_out = 0;
adapter->ptp_caps.pps = 1;
adapter->ptp_caps.adjfreq = ixgbe_ptp_adjfreq_82599;
adapter->ptp_caps.adjtime = ixgbe_ptp_adjtime;
adapter->ptp_caps.gettime64 = ixgbe_ptp_gettime;
adapter->ptp_caps.settime64 = ixgbe_ptp_settime;
adapter->ptp_caps.enable = ixgbe_ptp_feature_enable;
adapter->ptp_setup_sdp = ixgbe_ptp_setup_sdp_x540;
break;
case ixgbe_mac_82599EB:
snprintf(adapter->ptp_caps.name,
sizeof(adapter->ptp_caps.name),
"%s", netdev->name);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 250000000;
adapter->ptp_caps.n_alarm = 0;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.n_per_out = 0;
adapter->ptp_caps.pps = 0;
adapter->ptp_caps.adjfreq = ixgbe_ptp_adjfreq_82599;
adapter->ptp_caps.adjtime = ixgbe_ptp_adjtime;
adapter->ptp_caps.gettime64 = ixgbe_ptp_gettime;
adapter->ptp_caps.settime64 = ixgbe_ptp_settime;
adapter->ptp_caps.enable = ixgbe_ptp_feature_enable;
break;
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
snprintf(adapter->ptp_caps.name, 16, "%s", netdev->name);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 30000000;
adapter->ptp_caps.n_alarm = 0;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.n_per_out = 0;
adapter->ptp_caps.pps = 0;
adapter->ptp_caps.adjfreq = ixgbe_ptp_adjfreq_X550;
adapter->ptp_caps.adjtime = ixgbe_ptp_adjtime;
adapter->ptp_caps.gettime64 = ixgbe_ptp_gettime;
adapter->ptp_caps.settime64 = ixgbe_ptp_settime;
adapter->ptp_caps.enable = ixgbe_ptp_feature_enable;
adapter->ptp_setup_sdp = NULL;
break;
default:
adapter->ptp_clock = NULL;
adapter->ptp_setup_sdp = NULL;
return -EOPNOTSUPP;
}
adapter->ptp_clock = ptp_clock_register(&adapter->ptp_caps,
&adapter->pdev->dev);
if (IS_ERR(adapter->ptp_clock)) {
err = PTR_ERR(adapter->ptp_clock);
adapter->ptp_clock = NULL;
e_dev_err("ptp_clock_register failed\n");
return err;
} else
e_dev_info("registered PHC device on %s\n", netdev->name);
adapter->tstamp_config.rx_filter = HWTSTAMP_FILTER_NONE;
adapter->tstamp_config.tx_type = HWTSTAMP_TX_OFF;
return 0;
}
void ixgbe_ptp_init(struct ixgbe_adapter *adapter)
{
spin_lock_init(&adapter->tmreg_lock);
if (ixgbe_ptp_create_clock(adapter))
return;
INIT_WORK(&adapter->ptp_tx_work, ixgbe_ptp_tx_hwtstamp_work);
ixgbe_ptp_reset(adapter);
set_bit(__IXGBE_PTP_RUNNING, &adapter->state);
return;
}
void ixgbe_ptp_suspend(struct ixgbe_adapter *adapter)
{
if (!test_and_clear_bit(__IXGBE_PTP_RUNNING, &adapter->state))
return;
adapter->flags2 &= ~IXGBE_FLAG2_PTP_PPS_ENABLED;
if (adapter->ptp_setup_sdp)
adapter->ptp_setup_sdp(adapter);
cancel_work_sync(&adapter->ptp_tx_work);
ixgbe_ptp_clear_tx_timestamp(adapter);
}
void ixgbe_ptp_stop(struct ixgbe_adapter *adapter)
{
ixgbe_ptp_suspend(adapter);
if (adapter->ptp_clock) {
ptp_clock_unregister(adapter->ptp_clock);
adapter->ptp_clock = NULL;
e_dev_info("removed PHC on %s\n",
adapter->netdev->name);
}
}
