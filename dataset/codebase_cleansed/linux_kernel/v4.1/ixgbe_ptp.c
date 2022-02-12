static void ixgbe_ptp_setup_sdp(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int shift = adapter->cc.shift;
u32 esdp, tsauxc, clktiml, clktimh, trgttiml, trgttimh, rem;
u64 ns = 0, clock_edge = 0;
if ((adapter->flags2 & IXGBE_FLAG2_PTP_PPS_ENABLED) &&
(hw->mac.type == ixgbe_mac_X540)) {
IXGBE_WRITE_REG(hw, IXGBE_TSAUXC, 0x0);
IXGBE_WRITE_FLUSH(hw);
esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
esdp |= (IXGBE_ESDP_SDP0_DIR |
IXGBE_ESDP_SDP0_NATIVE);
tsauxc = (IXGBE_TSAUXC_EN_CLK |
IXGBE_TSAUXC_SYNCLK |
IXGBE_TSAUXC_SDP0_INT);
clktiml = (u32)(IXGBE_PTP_PPS_HALF_SECOND << shift);
clktimh = (u32)((IXGBE_PTP_PPS_HALF_SECOND << shift) >> 32);
clock_edge |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIML);
clock_edge |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIMH) << 32;
ns = timecounter_cyc2time(&adapter->tc, clock_edge);
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
} else {
IXGBE_WRITE_REG(hw, IXGBE_TSAUXC, 0x0);
}
IXGBE_WRITE_FLUSH(hw);
}
static cycle_t ixgbe_ptp_read(const struct cyclecounter *cc)
{
struct ixgbe_adapter *adapter =
container_of(cc, struct ixgbe_adapter, cc);
struct ixgbe_hw *hw = &adapter->hw;
u64 stamp = 0;
stamp |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIML);
stamp |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIMH) << 32;
return stamp;
}
static int ixgbe_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
struct ixgbe_hw *hw = &adapter->hw;
u64 freq;
u32 diff, incval;
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
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA, incval);
break;
case ixgbe_mac_82599EB:
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA,
(1 << IXGBE_INCPER_SHIFT_82599) |
incval);
break;
default:
break;
}
return 0;
}
static int ixgbe_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
unsigned long flags;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_adjtime(&adapter->tc, delta);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ixgbe_ptp_setup_sdp(adapter);
return 0;
}
static int ixgbe_ptp_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
u64 ns;
unsigned long flags;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_read(&adapter->tc);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
*ts = ns_to_timespec64(ns);
return 0;
}
static int ixgbe_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
u64 ns;
unsigned long flags;
ns = timespec64_to_ns(ts);
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_init(&adapter->tc, &adapter->cc, ns);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ixgbe_ptp_setup_sdp(adapter);
return 0;
}
static int ixgbe_ptp_feature_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
if (rq->type == PTP_CLK_REQ_PPS) {
switch (adapter->hw.mac.type) {
case ixgbe_mac_X540:
if (on)
adapter->flags2 |= IXGBE_FLAG2_PTP_PPS_ENABLED;
else
adapter->flags2 &= ~IXGBE_FLAG2_PTP_PPS_ENABLED;
ixgbe_ptp_setup_sdp(adapter);
return 0;
default:
break;
}
}
return -ENOTSUPP;
}
void ixgbe_ptp_check_pps_event(struct ixgbe_adapter *adapter, u32 eicr)
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
unsigned long rx_event;
if (!(tsyncrxctl & IXGBE_TSYNCRXCTL_VALID)) {
adapter->last_rx_ptp_check = jiffies;
return;
}
rx_event = adapter->last_rx_ptp_check;
if (time_after(adapter->last_rx_timestamp, rx_event))
rx_event = adapter->last_rx_timestamp;
if (time_is_before_jiffies(rx_event + 5*HZ)) {
IXGBE_READ_REG(hw, IXGBE_RXSTMPH);
adapter->last_rx_ptp_check = jiffies;
e_warn(drv, "clearing RX Timestamp hang\n");
}
}
static void ixgbe_ptp_tx_hwtstamp(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct skb_shared_hwtstamps shhwtstamps;
u64 regval = 0, ns;
unsigned long flags;
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_TXSTMPL);
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_TXSTMPH) << 32;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_cyc2time(&adapter->tc, regval);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
shhwtstamps.hwtstamp = ns_to_ktime(ns);
skb_tstamp_tx(adapter->ptp_tx_skb, &shhwtstamps);
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
clear_bit_unlock(__IXGBE_PTP_TX_IN_PROGRESS, &adapter->state);
}
static void ixgbe_ptp_tx_hwtstamp_work(struct work_struct *work)
{
struct ixgbe_adapter *adapter = container_of(work, struct ixgbe_adapter,
ptp_tx_work);
struct ixgbe_hw *hw = &adapter->hw;
bool timeout = time_is_before_jiffies(adapter->ptp_tx_start +
IXGBE_PTP_TX_TIMEOUT);
u32 tsynctxctl;
if (timeout) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
clear_bit_unlock(__IXGBE_PTP_TX_IN_PROGRESS, &adapter->state);
e_warn(drv, "clearing Tx Timestamp hang\n");
return;
}
tsynctxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCTXCTL);
if (tsynctxctl & IXGBE_TSYNCTXCTL_VALID)
ixgbe_ptp_tx_hwtstamp(adapter);
else
schedule_work(&adapter->ptp_tx_work);
}
void ixgbe_ptp_rx_hwtstamp(struct ixgbe_adapter *adapter, struct sk_buff *skb)
{
struct ixgbe_hw *hw = &adapter->hw;
struct skb_shared_hwtstamps *shhwtstamps;
u64 regval = 0, ns;
u32 tsyncrxctl;
unsigned long flags;
tsyncrxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCRXCTL);
if (!(tsyncrxctl & IXGBE_TSYNCRXCTL_VALID))
return;
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_RXSTMPL);
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_RXSTMPH) << 32;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_cyc2time(&adapter->tc, regval);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
shhwtstamps = skb_hwtstamps(skb);
shhwtstamps->hwtstamp = ns_to_ktime(ns);
adapter->last_rx_timestamp = jiffies;
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
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_mtrl |= IXGBE_RXMTRL_V1_SYNC_MSG;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_mtrl |= IXGBE_RXMTRL_V1_DELAY_REQ_MSG;
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
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_ALL:
default:
config->rx_filter = HWTSTAMP_FILTER_NONE;
return -ERANGE;
}
if (hw->mac.type == ixgbe_mac_82598EB) {
if (tsync_rx_ctl | tsync_tx_ctl)
return -ERANGE;
return 0;
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
regval = IXGBE_READ_REG(hw, IXGBE_TXSTMPH);
regval = IXGBE_READ_REG(hw, IXGBE_RXSTMPH);
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
void ixgbe_ptp_start_cyclecounter(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 incval = 0;
u32 shift = 0;
unsigned long flags;
switch (adapter->link_speed) {
case IXGBE_LINK_SPEED_100_FULL:
incval = IXGBE_INCVAL_100;
shift = IXGBE_INCVAL_SHIFT_100;
break;
case IXGBE_LINK_SPEED_1GB_FULL:
incval = IXGBE_INCVAL_1GB;
shift = IXGBE_INCVAL_SHIFT_1GB;
break;
case IXGBE_LINK_SPEED_10GB_FULL:
default:
incval = IXGBE_INCVAL_10GB;
shift = IXGBE_INCVAL_SHIFT_10GB;
break;
}
switch (hw->mac.type) {
case ixgbe_mac_X540:
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA, incval);
break;
case ixgbe_mac_82599EB:
incval >>= IXGBE_INCVAL_SHIFT_82599;
shift -= IXGBE_INCVAL_SHIFT_82599;
IXGBE_WRITE_REG(hw, IXGBE_TIMINCA,
(1 << IXGBE_INCPER_SHIFT_82599) |
incval);
break;
default:
return;
}
ACCESS_ONCE(adapter->base_incval) = incval;
smp_mb();
spin_lock_irqsave(&adapter->tmreg_lock, flags);
memset(&adapter->cc, 0, sizeof(adapter->cc));
adapter->cc.read = ixgbe_ptp_read;
adapter->cc.mask = CYCLECOUNTER_MASK(64);
adapter->cc.shift = shift;
adapter->cc.mult = 1;
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
}
void ixgbe_ptp_reset(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
unsigned long flags;
IXGBE_WRITE_REG(hw, IXGBE_SYSTIML, 0x00000000);
IXGBE_WRITE_REG(hw, IXGBE_SYSTIMH, 0x00000000);
IXGBE_WRITE_FLUSH(hw);
ixgbe_ptp_set_timestamp_mode(adapter, &adapter->tstamp_config);
ixgbe_ptp_start_cyclecounter(adapter);
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_init(&adapter->tc, &adapter->cc,
ktime_to_ns(ktime_get_real()));
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ixgbe_ptp_setup_sdp(adapter);
}
static int ixgbe_ptp_create_clock(struct ixgbe_adapter *adapter)
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
adapter->ptp_caps.adjfreq = ixgbe_ptp_adjfreq;
adapter->ptp_caps.adjtime = ixgbe_ptp_adjtime;
adapter->ptp_caps.gettime64 = ixgbe_ptp_gettime;
adapter->ptp_caps.settime64 = ixgbe_ptp_settime;
adapter->ptp_caps.enable = ixgbe_ptp_feature_enable;
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
adapter->ptp_caps.adjfreq = ixgbe_ptp_adjfreq;
adapter->ptp_caps.adjtime = ixgbe_ptp_adjtime;
adapter->ptp_caps.gettime64 = ixgbe_ptp_gettime;
adapter->ptp_caps.settime64 = ixgbe_ptp_settime;
adapter->ptp_caps.enable = ixgbe_ptp_feature_enable;
break;
default:
adapter->ptp_clock = NULL;
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
IXGBE_WRITE_REG(&adapter->hw, IXGBE_TSAUXC, 0x0);
cancel_work_sync(&adapter->ptp_tx_work);
if (adapter->ptp_tx_skb) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
clear_bit_unlock(__IXGBE_PTP_TX_IN_PROGRESS, &adapter->state);
}
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
