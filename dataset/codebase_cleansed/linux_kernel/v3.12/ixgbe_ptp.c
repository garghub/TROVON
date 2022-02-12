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
clktiml = (u32)(NSECS_PER_SEC << shift);
clktimh = (u32)((NSECS_PER_SEC << shift) >> 32);
clock_edge |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIML);
clock_edge |= (u64)IXGBE_READ_REG(hw, IXGBE_SYSTIMH) << 32;
ns = timecounter_cyc2time(&adapter->tc, clock_edge);
div_u64_rem(ns, NSECS_PER_SEC, &rem);
clock_edge += ((NSECS_PER_SEC - (u64)rem) << shift);
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
u64 now;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
now = timecounter_read(&adapter->tc);
now += delta;
timecounter_init(&adapter->tc,
&adapter->cc,
now);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ixgbe_ptp_setup_sdp(adapter);
return 0;
}
static int ixgbe_ptp_gettime(struct ptp_clock_info *ptp, struct timespec *ts)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
u64 ns;
u32 remainder;
unsigned long flags;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_read(&adapter->tc);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ts->tv_sec = div_u64_rem(ns, 1000000000ULL, &remainder);
ts->tv_nsec = remainder;
return 0;
}
static int ixgbe_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
struct ixgbe_adapter *adapter =
container_of(ptp, struct ixgbe_adapter, ptp_caps);
u64 ns;
unsigned long flags;
ns = ts->tv_sec * 1000000000ULL;
ns += ts->tv_nsec;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_init(&adapter->tc, &adapter->cc, ns);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ixgbe_ptp_setup_sdp(adapter);
return 0;
}
static int ixgbe_ptp_enable(struct ptp_clock_info *ptp,
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
struct timespec ts;
if (timeout) {
ixgbe_ptp_gettime(&adapter->ptp_caps, &ts);
adapter->last_overflow_check = jiffies;
}
}
void ixgbe_ptp_rx_hang(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_ring *rx_ring;
u32 tsyncrxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCRXCTL);
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
if (time_is_before_jiffies(rx_event + 5*HZ)) {
IXGBE_READ_REG(hw, IXGBE_RXSTMPH);
adapter->last_rx_ptp_check = jiffies;
e_warn(drv, "clearing RX Timestamp hang");
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
}
static void ixgbe_ptp_tx_hwtstamp_work(struct work_struct *work)
{
struct ixgbe_adapter *adapter = container_of(work, struct ixgbe_adapter,
ptp_tx_work);
struct ixgbe_hw *hw = &adapter->hw;
bool timeout = time_is_before_jiffies(adapter->ptp_tx_start +
IXGBE_PTP_TX_TIMEOUT);
u32 tsynctxctl;
if (!adapter->ptp_tx_skb)
return;
if (timeout) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
e_warn(drv, "clearing Tx Timestamp hang");
return;
}
tsynctxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCTXCTL);
if (tsynctxctl & IXGBE_TSYNCTXCTL_VALID)
ixgbe_ptp_tx_hwtstamp(adapter);
else
schedule_work(&adapter->ptp_tx_work);
}
void __ixgbe_ptp_rx_hwtstamp(struct ixgbe_q_vector *q_vector,
struct sk_buff *skb)
{
struct ixgbe_adapter *adapter;
struct ixgbe_hw *hw;
struct skb_shared_hwtstamps *shhwtstamps;
u64 regval = 0, ns;
u32 tsyncrxctl;
unsigned long flags;
if (!q_vector || !q_vector->adapter)
return;
adapter = q_vector->adapter;
hw = &adapter->hw;
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
}
int ixgbe_ptp_hwtstamp_ioctl(struct ixgbe_adapter *adapter,
struct ifreq *ifr, int cmd)
{
struct ixgbe_hw *hw = &adapter->hw;
struct hwtstamp_config config;
u32 tsync_tx_ctl = IXGBE_TSYNCTXCTL_ENABLED;
u32 tsync_rx_ctl = IXGBE_TSYNCRXCTL_ENABLED;
u32 tsync_rx_mtrl = PTP_EV_PORT << 16;
bool is_l2 = false;
u32 regval;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
if (config.flags)
return -EINVAL;
switch (config.tx_type) {
case HWTSTAMP_TX_OFF:
tsync_tx_ctl = 0;
case HWTSTAMP_TX_ON:
break;
default:
return -ERANGE;
}
switch (config.rx_filter) {
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
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_ALL:
default:
config.rx_filter = HWTSTAMP_FILTER_NONE;
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
adapter->cc.mask = CLOCKSOURCE_MASK(64);
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
ixgbe_ptp_start_cyclecounter(adapter);
spin_lock_irqsave(&adapter->tmreg_lock, flags);
timecounter_init(&adapter->tc, &adapter->cc,
ktime_to_ns(ktime_get_real()));
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ixgbe_ptp_setup_sdp(adapter);
}
void ixgbe_ptp_init(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
switch (adapter->hw.mac.type) {
case ixgbe_mac_X540:
snprintf(adapter->ptp_caps.name, 16, "%s", netdev->name);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 250000000;
adapter->ptp_caps.n_alarm = 0;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.n_per_out = 0;
adapter->ptp_caps.pps = 1;
adapter->ptp_caps.adjfreq = ixgbe_ptp_adjfreq;
adapter->ptp_caps.adjtime = ixgbe_ptp_adjtime;
adapter->ptp_caps.gettime = ixgbe_ptp_gettime;
adapter->ptp_caps.settime = ixgbe_ptp_settime;
adapter->ptp_caps.enable = ixgbe_ptp_enable;
break;
case ixgbe_mac_82599EB:
snprintf(adapter->ptp_caps.name, 16, "%s", netdev->name);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 250000000;
adapter->ptp_caps.n_alarm = 0;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.n_per_out = 0;
adapter->ptp_caps.pps = 0;
adapter->ptp_caps.adjfreq = ixgbe_ptp_adjfreq;
adapter->ptp_caps.adjtime = ixgbe_ptp_adjtime;
adapter->ptp_caps.gettime = ixgbe_ptp_gettime;
adapter->ptp_caps.settime = ixgbe_ptp_settime;
adapter->ptp_caps.enable = ixgbe_ptp_enable;
break;
default:
adapter->ptp_clock = NULL;
return;
}
spin_lock_init(&adapter->tmreg_lock);
INIT_WORK(&adapter->ptp_tx_work, ixgbe_ptp_tx_hwtstamp_work);
adapter->ptp_clock = ptp_clock_register(&adapter->ptp_caps,
&adapter->pdev->dev);
if (IS_ERR(adapter->ptp_clock)) {
adapter->ptp_clock = NULL;
e_dev_err("ptp_clock_register failed\n");
} else
e_dev_info("registered PHC device on %s\n", netdev->name);
ixgbe_ptp_reset(adapter);
set_bit(__IXGBE_PTP_RUNNING, &adapter->state);
return;
}
void ixgbe_ptp_stop(struct ixgbe_adapter *adapter)
{
if (!test_and_clear_bit(__IXGBE_PTP_RUNNING, &adapter->state))
return;
adapter->flags2 &= ~IXGBE_FLAG2_PTP_PPS_ENABLED;
ixgbe_ptp_setup_sdp(adapter);
cancel_work_sync(&adapter->ptp_tx_work);
if (adapter->ptp_tx_skb) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
}
if (adapter->ptp_clock) {
ptp_clock_unregister(adapter->ptp_clock);
adapter->ptp_clock = NULL;
e_dev_info("removed PHC on %s\n",
adapter->netdev->name);
}
}
