static cycle_t igb_ptp_read_82576(const struct cyclecounter *cc)
{
struct igb_adapter *igb = container_of(cc, struct igb_adapter, cc);
struct e1000_hw *hw = &igb->hw;
u64 val;
u32 lo, hi;
lo = rd32(E1000_SYSTIML);
hi = rd32(E1000_SYSTIMH);
val = ((u64) hi) << 32;
val |= lo;
return val;
}
static cycle_t igb_ptp_read_82580(const struct cyclecounter *cc)
{
struct igb_adapter *igb = container_of(cc, struct igb_adapter, cc);
struct e1000_hw *hw = &igb->hw;
u32 lo, hi;
u64 val;
rd32(E1000_SYSTIMR);
lo = rd32(E1000_SYSTIML);
hi = rd32(E1000_SYSTIMH);
val = ((u64) hi) << 32;
val |= lo;
return val;
}
static void igb_ptp_read_i210(struct igb_adapter *adapter, struct timespec *ts)
{
struct e1000_hw *hw = &adapter->hw;
u32 sec, nsec;
rd32(E1000_SYSTIMR);
nsec = rd32(E1000_SYSTIML);
sec = rd32(E1000_SYSTIMH);
ts->tv_sec = sec;
ts->tv_nsec = nsec;
}
static void igb_ptp_write_i210(struct igb_adapter *adapter,
const struct timespec *ts)
{
struct e1000_hw *hw = &adapter->hw;
wr32(E1000_SYSTIML, ts->tv_nsec);
wr32(E1000_SYSTIMH, ts->tv_sec);
}
static void igb_ptp_systim_to_hwtstamp(struct igb_adapter *adapter,
struct skb_shared_hwtstamps *hwtstamps,
u64 systim)
{
unsigned long flags;
u64 ns;
switch (adapter->hw.mac.type) {
case e1000_82576:
case e1000_82580:
case e1000_i354:
case e1000_i350:
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_cyc2time(&adapter->tc, systim);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
memset(hwtstamps, 0, sizeof(*hwtstamps));
hwtstamps->hwtstamp = ns_to_ktime(ns);
break;
case e1000_i210:
case e1000_i211:
memset(hwtstamps, 0, sizeof(*hwtstamps));
hwtstamps->hwtstamp = ktime_set(systim >> 32,
systim & 0xFFFFFFFF);
break;
default:
break;
}
}
static int igb_ptp_adjfreq_82576(struct ptp_clock_info *ptp, s32 ppb)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
struct e1000_hw *hw = &igb->hw;
int neg_adj = 0;
u64 rate;
u32 incvalue;
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
rate = ppb;
rate <<= 14;
rate = div_u64(rate, 1953125);
incvalue = 16 << IGB_82576_TSYNC_SHIFT;
if (neg_adj)
incvalue -= rate;
else
incvalue += rate;
wr32(E1000_TIMINCA, INCPERIOD_82576 | (incvalue & INCVALUE_82576_MASK));
return 0;
}
static int igb_ptp_adjfreq_82580(struct ptp_clock_info *ptp, s32 ppb)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
struct e1000_hw *hw = &igb->hw;
int neg_adj = 0;
u64 rate;
u32 inca;
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
rate = ppb;
rate <<= 26;
rate = div_u64(rate, 1953125);
inca = rate & INCVALUE_MASK;
if (neg_adj)
inca |= ISGN;
wr32(E1000_TIMINCA, inca);
return 0;
}
static int igb_ptp_adjtime_82576(struct ptp_clock_info *ptp, s64 delta)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
unsigned long flags;
s64 now;
spin_lock_irqsave(&igb->tmreg_lock, flags);
now = timecounter_read(&igb->tc);
now += delta;
timecounter_init(&igb->tc, &igb->cc, now);
spin_unlock_irqrestore(&igb->tmreg_lock, flags);
return 0;
}
static int igb_ptp_adjtime_i210(struct ptp_clock_info *ptp, s64 delta)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
unsigned long flags;
struct timespec now, then = ns_to_timespec(delta);
spin_lock_irqsave(&igb->tmreg_lock, flags);
igb_ptp_read_i210(igb, &now);
now = timespec_add(now, then);
igb_ptp_write_i210(igb, (const struct timespec *)&now);
spin_unlock_irqrestore(&igb->tmreg_lock, flags);
return 0;
}
static int igb_ptp_gettime_82576(struct ptp_clock_info *ptp,
struct timespec *ts)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
unsigned long flags;
u64 ns;
u32 remainder;
spin_lock_irqsave(&igb->tmreg_lock, flags);
ns = timecounter_read(&igb->tc);
spin_unlock_irqrestore(&igb->tmreg_lock, flags);
ts->tv_sec = div_u64_rem(ns, 1000000000, &remainder);
ts->tv_nsec = remainder;
return 0;
}
static int igb_ptp_gettime_i210(struct ptp_clock_info *ptp,
struct timespec *ts)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
unsigned long flags;
spin_lock_irqsave(&igb->tmreg_lock, flags);
igb_ptp_read_i210(igb, ts);
spin_unlock_irqrestore(&igb->tmreg_lock, flags);
return 0;
}
static int igb_ptp_settime_82576(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
unsigned long flags;
u64 ns;
ns = ts->tv_sec * 1000000000ULL;
ns += ts->tv_nsec;
spin_lock_irqsave(&igb->tmreg_lock, flags);
timecounter_init(&igb->tc, &igb->cc, ns);
spin_unlock_irqrestore(&igb->tmreg_lock, flags);
return 0;
}
static int igb_ptp_settime_i210(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
struct igb_adapter *igb = container_of(ptp, struct igb_adapter,
ptp_caps);
unsigned long flags;
spin_lock_irqsave(&igb->tmreg_lock, flags);
igb_ptp_write_i210(igb, ts);
spin_unlock_irqrestore(&igb->tmreg_lock, flags);
return 0;
}
static int igb_ptp_feature_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
static void igb_ptp_tx_work(struct work_struct *work)
{
struct igb_adapter *adapter = container_of(work, struct igb_adapter,
ptp_tx_work);
struct e1000_hw *hw = &adapter->hw;
u32 tsynctxctl;
if (!adapter->ptp_tx_skb)
return;
if (time_is_before_jiffies(adapter->ptp_tx_start +
IGB_PTP_TX_TIMEOUT)) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
clear_bit_unlock(__IGB_PTP_TX_IN_PROGRESS, &adapter->state);
adapter->tx_hwtstamp_timeouts++;
dev_warn(&adapter->pdev->dev, "clearing Tx timestamp hang\n");
return;
}
tsynctxctl = rd32(E1000_TSYNCTXCTL);
if (tsynctxctl & E1000_TSYNCTXCTL_VALID)
igb_ptp_tx_hwtstamp(adapter);
else
schedule_work(&adapter->ptp_tx_work);
}
static void igb_ptp_overflow_check(struct work_struct *work)
{
struct igb_adapter *igb =
container_of(work, struct igb_adapter, ptp_overflow_work.work);
struct timespec ts;
igb->ptp_caps.gettime(&igb->ptp_caps, &ts);
pr_debug("igb overflow check at %ld.%09lu\n", ts.tv_sec, ts.tv_nsec);
schedule_delayed_work(&igb->ptp_overflow_work,
IGB_SYSTIM_OVERFLOW_PERIOD);
}
void igb_ptp_rx_hang(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 tsyncrxctl = rd32(E1000_TSYNCRXCTL);
unsigned long rx_event;
if (hw->mac.type != e1000_82576)
return;
if (!(tsyncrxctl & E1000_TSYNCRXCTL_VALID)) {
adapter->last_rx_ptp_check = jiffies;
return;
}
rx_event = adapter->last_rx_ptp_check;
if (time_after(adapter->last_rx_timestamp, rx_event))
rx_event = adapter->last_rx_timestamp;
if (time_is_before_jiffies(rx_event + 5 * HZ)) {
rd32(E1000_RXSTMPH);
adapter->last_rx_ptp_check = jiffies;
adapter->rx_hwtstamp_cleared++;
dev_warn(&adapter->pdev->dev, "clearing Rx timestamp hang\n");
}
}
static void igb_ptp_tx_hwtstamp(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
struct skb_shared_hwtstamps shhwtstamps;
u64 regval;
regval = rd32(E1000_TXSTMPL);
regval |= (u64)rd32(E1000_TXSTMPH) << 32;
igb_ptp_systim_to_hwtstamp(adapter, &shhwtstamps, regval);
skb_tstamp_tx(adapter->ptp_tx_skb, &shhwtstamps);
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
clear_bit_unlock(__IGB_PTP_TX_IN_PROGRESS, &adapter->state);
}
void igb_ptp_rx_pktstamp(struct igb_q_vector *q_vector,
unsigned char *va,
struct sk_buff *skb)
{
__le64 *regval = (__le64 *)va;
igb_ptp_systim_to_hwtstamp(q_vector->adapter, skb_hwtstamps(skb),
le64_to_cpu(regval[1]));
}
void igb_ptp_rx_rgtstamp(struct igb_q_vector *q_vector,
struct sk_buff *skb)
{
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
u64 regval;
if (!(rd32(E1000_TSYNCRXCTL) & E1000_TSYNCRXCTL_VALID))
return;
regval = rd32(E1000_RXSTMPL);
regval |= (u64)rd32(E1000_RXSTMPH) << 32;
igb_ptp_systim_to_hwtstamp(adapter, skb_hwtstamps(skb), regval);
adapter->last_rx_timestamp = jiffies;
}
int igb_ptp_get_ts_config(struct net_device *netdev, struct ifreq *ifr)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct hwtstamp_config *config = &adapter->tstamp_config;
return copy_to_user(ifr->ifr_data, config, sizeof(*config)) ?
-EFAULT : 0;
}
static int igb_ptp_set_timestamp_mode(struct igb_adapter *adapter,
struct hwtstamp_config *config)
{
struct e1000_hw *hw = &adapter->hw;
u32 tsync_tx_ctl = E1000_TSYNCTXCTL_ENABLED;
u32 tsync_rx_ctl = E1000_TSYNCRXCTL_ENABLED;
u32 tsync_rx_cfg = 0;
bool is_l4 = false;
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
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_cfg = E1000_TSYNCRXCFG_PTP_V1_SYNC_MESSAGE;
is_l4 = true;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_cfg = E1000_TSYNCRXCFG_PTP_V1_DELAY_REQ_MESSAGE;
is_l4 = true;
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
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_EVENT_V2;
config->rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
is_l2 = true;
is_l4 = true;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_ALL:
if (hw->mac.type != e1000_82576) {
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_ALL;
config->rx_filter = HWTSTAMP_FILTER_ALL;
break;
}
default:
config->rx_filter = HWTSTAMP_FILTER_NONE;
return -ERANGE;
}
if (hw->mac.type == e1000_82575) {
if (tsync_rx_ctl | tsync_tx_ctl)
return -EINVAL;
return 0;
}
if ((hw->mac.type >= e1000_82580) && tsync_rx_ctl) {
tsync_rx_ctl = E1000_TSYNCRXCTL_ENABLED;
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_ALL;
config->rx_filter = HWTSTAMP_FILTER_ALL;
is_l2 = true;
is_l4 = true;
if ((hw->mac.type == e1000_i210) ||
(hw->mac.type == e1000_i211)) {
regval = rd32(E1000_RXPBS);
regval |= E1000_RXPBS_CFG_TS_EN;
wr32(E1000_RXPBS, regval);
}
}
regval = rd32(E1000_TSYNCTXCTL);
regval &= ~E1000_TSYNCTXCTL_ENABLED;
regval |= tsync_tx_ctl;
wr32(E1000_TSYNCTXCTL, regval);
regval = rd32(E1000_TSYNCRXCTL);
regval &= ~(E1000_TSYNCRXCTL_ENABLED | E1000_TSYNCRXCTL_TYPE_MASK);
regval |= tsync_rx_ctl;
wr32(E1000_TSYNCRXCTL, regval);
wr32(E1000_TSYNCRXCFG, tsync_rx_cfg);
if (is_l2)
wr32(E1000_ETQF(3),
(E1000_ETQF_FILTER_ENABLE |
E1000_ETQF_1588 |
ETH_P_1588));
else
wr32(E1000_ETQF(3), 0);
if (is_l4) {
u32 ftqf = (IPPROTO_UDP
| E1000_FTQF_VF_BP
| E1000_FTQF_1588_TIME_STAMP
| E1000_FTQF_MASK);
ftqf &= ~E1000_FTQF_MASK_PROTO_BP;
wr32(E1000_IMIR(3), htons(PTP_EV_PORT));
wr32(E1000_IMIREXT(3),
(E1000_IMIREXT_SIZE_BP | E1000_IMIREXT_CTRL_BP));
if (hw->mac.type == e1000_82576) {
wr32(E1000_SPQF(3), htons(PTP_EV_PORT));
ftqf &= ~E1000_FTQF_MASK_SOURCE_PORT_BP;
}
wr32(E1000_FTQF(3), ftqf);
} else {
wr32(E1000_FTQF(3), E1000_FTQF_MASK);
}
wrfl();
regval = rd32(E1000_TXSTMPL);
regval = rd32(E1000_TXSTMPH);
regval = rd32(E1000_RXSTMPL);
regval = rd32(E1000_RXSTMPH);
return 0;
}
int igb_ptp_set_ts_config(struct net_device *netdev, struct ifreq *ifr)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct hwtstamp_config config;
int err;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
err = igb_ptp_set_timestamp_mode(adapter, &config);
if (err)
return err;
memcpy(&adapter->tstamp_config, &config,
sizeof(adapter->tstamp_config));
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
void igb_ptp_init(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
switch (hw->mac.type) {
case e1000_82576:
snprintf(adapter->ptp_caps.name, 16, "%pm", netdev->dev_addr);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 999999881;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.pps = 0;
adapter->ptp_caps.adjfreq = igb_ptp_adjfreq_82576;
adapter->ptp_caps.adjtime = igb_ptp_adjtime_82576;
adapter->ptp_caps.gettime = igb_ptp_gettime_82576;
adapter->ptp_caps.settime = igb_ptp_settime_82576;
adapter->ptp_caps.enable = igb_ptp_feature_enable;
adapter->cc.read = igb_ptp_read_82576;
adapter->cc.mask = CLOCKSOURCE_MASK(64);
adapter->cc.mult = 1;
adapter->cc.shift = IGB_82576_TSYNC_SHIFT;
wr32(E1000_TIMINCA, INCPERIOD_82576 | INCVALUE_82576);
break;
case e1000_82580:
case e1000_i354:
case e1000_i350:
snprintf(adapter->ptp_caps.name, 16, "%pm", netdev->dev_addr);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 62499999;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.pps = 0;
adapter->ptp_caps.adjfreq = igb_ptp_adjfreq_82580;
adapter->ptp_caps.adjtime = igb_ptp_adjtime_82576;
adapter->ptp_caps.gettime = igb_ptp_gettime_82576;
adapter->ptp_caps.settime = igb_ptp_settime_82576;
adapter->ptp_caps.enable = igb_ptp_feature_enable;
adapter->cc.read = igb_ptp_read_82580;
adapter->cc.mask = CLOCKSOURCE_MASK(IGB_NBITS_82580);
adapter->cc.mult = 1;
adapter->cc.shift = 0;
wr32(E1000_TSAUXC, 0x0);
break;
case e1000_i210:
case e1000_i211:
snprintf(adapter->ptp_caps.name, 16, "%pm", netdev->dev_addr);
adapter->ptp_caps.owner = THIS_MODULE;
adapter->ptp_caps.max_adj = 62499999;
adapter->ptp_caps.n_ext_ts = 0;
adapter->ptp_caps.pps = 0;
adapter->ptp_caps.adjfreq = igb_ptp_adjfreq_82580;
adapter->ptp_caps.adjtime = igb_ptp_adjtime_i210;
adapter->ptp_caps.gettime = igb_ptp_gettime_i210;
adapter->ptp_caps.settime = igb_ptp_settime_i210;
adapter->ptp_caps.enable = igb_ptp_feature_enable;
wr32(E1000_TSAUXC, 0x0);
break;
default:
adapter->ptp_clock = NULL;
return;
}
wrfl();
spin_lock_init(&adapter->tmreg_lock);
INIT_WORK(&adapter->ptp_tx_work, igb_ptp_tx_work);
if ((hw->mac.type == e1000_i210) || (hw->mac.type == e1000_i211)) {
struct timespec ts = ktime_to_timespec(ktime_get_real());
igb_ptp_settime_i210(&adapter->ptp_caps, &ts);
} else {
timecounter_init(&adapter->tc, &adapter->cc,
ktime_to_ns(ktime_get_real()));
INIT_DELAYED_WORK(&adapter->ptp_overflow_work,
igb_ptp_overflow_check);
schedule_delayed_work(&adapter->ptp_overflow_work,
IGB_SYSTIM_OVERFLOW_PERIOD);
}
if (hw->mac.type >= e1000_82580) {
wr32(E1000_TSIM, TSYNC_INTERRUPTS);
wr32(E1000_IMS, E1000_IMS_TS);
}
adapter->tstamp_config.rx_filter = HWTSTAMP_FILTER_NONE;
adapter->tstamp_config.tx_type = HWTSTAMP_TX_OFF;
adapter->ptp_clock = ptp_clock_register(&adapter->ptp_caps,
&adapter->pdev->dev);
if (IS_ERR(adapter->ptp_clock)) {
adapter->ptp_clock = NULL;
dev_err(&adapter->pdev->dev, "ptp_clock_register failed\n");
} else {
dev_info(&adapter->pdev->dev, "added PHC on %s\n",
adapter->netdev->name);
adapter->flags |= IGB_FLAG_PTP;
}
}
void igb_ptp_stop(struct igb_adapter *adapter)
{
switch (adapter->hw.mac.type) {
case e1000_82576:
case e1000_82580:
case e1000_i354:
case e1000_i350:
cancel_delayed_work_sync(&adapter->ptp_overflow_work);
break;
case e1000_i210:
case e1000_i211:
break;
default:
return;
}
cancel_work_sync(&adapter->ptp_tx_work);
if (adapter->ptp_tx_skb) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
clear_bit_unlock(__IGB_PTP_TX_IN_PROGRESS, &adapter->state);
}
if (adapter->ptp_clock) {
ptp_clock_unregister(adapter->ptp_clock);
dev_info(&adapter->pdev->dev, "removed PHC on %s\n",
adapter->netdev->name);
adapter->flags &= ~IGB_FLAG_PTP;
}
}
void igb_ptp_reset(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
if (!(adapter->flags & IGB_FLAG_PTP))
return;
igb_ptp_set_timestamp_mode(adapter, &adapter->tstamp_config);
switch (adapter->hw.mac.type) {
case e1000_82576:
wr32(E1000_TIMINCA, INCPERIOD_82576 | INCVALUE_82576);
break;
case e1000_82580:
case e1000_i354:
case e1000_i350:
case e1000_i210:
case e1000_i211:
wr32(E1000_TSAUXC, 0x0);
wr32(E1000_TSIM, TSYNC_INTERRUPTS);
wr32(E1000_IMS, E1000_IMS_TS);
break;
default:
return;
}
if ((hw->mac.type == e1000_i210) || (hw->mac.type == e1000_i211)) {
struct timespec ts = ktime_to_timespec(ktime_get_real());
igb_ptp_settime_i210(&adapter->ptp_caps, &ts);
} else {
timecounter_init(&adapter->tc, &adapter->cc,
ktime_to_ns(ktime_get_real()));
}
}
