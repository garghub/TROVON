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
adapter->flags2 &=
~IXGBE_FLAG2_PTP_PPS_ENABLED;
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
if (!adapter->ptp_clock ||
!(adapter->flags2 & IXGBE_FLAG2_PTP_PPS_ENABLED))
return;
if (unlikely(eicr & IXGBE_EICR_TIMESYNC)) {
switch (hw->mac.type) {
case ixgbe_mac_X540:
ptp_clock_event(adapter->ptp_clock, &event);
break;
default:
break;
}
}
}
static void ixgbe_ptp_enable_sdp(struct ixgbe_hw *hw, int shift)
{
u32 esdp, tsauxc, clktiml, clktimh, trgttiml, trgttimh;
u64 clock_edge = 0;
u32 rem;
switch (hw->mac.type) {
case ixgbe_mac_X540:
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
clock_edge >>= shift;
div_u64_rem(clock_edge, NSECS_PER_SEC, &rem);
clock_edge += (NSECS_PER_SEC - rem);
clock_edge <<= shift;
trgttiml = (u32)clock_edge;
trgttimh = (u32)(clock_edge >> 32);
IXGBE_WRITE_REG(hw, IXGBE_CLKTIML, clktiml);
IXGBE_WRITE_REG(hw, IXGBE_CLKTIMH, clktimh);
IXGBE_WRITE_REG(hw, IXGBE_TRGTTIML0, trgttiml);
IXGBE_WRITE_REG(hw, IXGBE_TRGTTIMH0, trgttimh);
IXGBE_WRITE_REG(hw, IXGBE_ESDP, esdp);
IXGBE_WRITE_REG(hw, IXGBE_TSAUXC, tsauxc);
IXGBE_WRITE_REG(hw, IXGBE_EIMS, IXGBE_EICR_TIMESYNC);
break;
default:
break;
}
}
static void ixgbe_ptp_disable_sdp(struct ixgbe_hw *hw)
{
IXGBE_WRITE_REG(hw, IXGBE_EIMC, IXGBE_EICR_TIMESYNC);
IXGBE_WRITE_REG(hw, IXGBE_TSAUXC, 0);
}
void ixgbe_ptp_overflow_check(struct ixgbe_adapter *adapter)
{
unsigned long elapsed_jiffies = adapter->last_overflow_check - jiffies;
struct timespec ts;
if ((adapter->flags2 & IXGBE_FLAG2_OVERFLOW_CHECK_ENABLED) &&
(elapsed_jiffies >= IXGBE_OVERFLOW_PERIOD)) {
ixgbe_ptp_gettime(&adapter->ptp_caps, &ts);
adapter->last_overflow_check = jiffies;
}
}
static int ixgbe_ptp_match(struct sk_buff *skb, int rx_filter)
{
struct iphdr iph;
u8 msgtype;
unsigned int type, offset;
if (rx_filter == HWTSTAMP_FILTER_NONE)
return 0;
type = sk_run_filter(skb, ptp_filter);
if (likely(rx_filter == HWTSTAMP_FILTER_PTP_V2_EVENT))
return type & PTP_CLASS_V2;
switch (type) {
case PTP_CLASS_V1_IPV4:
skb_copy_bits(skb, OFF_IHL, &iph, sizeof(iph));
offset = ETH_HLEN + (iph.ihl << 2) + UDP_HLEN + OFF_PTP_CONTROL;
break;
case PTP_CLASS_V1_IPV6:
offset = OFF_PTP6 + OFF_PTP_CONTROL;
break;
default:
return 0;
}
if (skb->len < offset)
return 0;
skb_copy_bits(skb, offset, &msgtype, sizeof(msgtype));
switch (rx_filter) {
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
return (msgtype == IXGBE_RXMTRL_V1_SYNC_MSG);
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
return (msgtype == IXGBE_RXMTRL_V1_DELAY_REQ_MSG);
break;
default:
return 0;
}
}
void ixgbe_ptp_tx_hwtstamp(struct ixgbe_q_vector *q_vector,
struct sk_buff *skb)
{
struct ixgbe_adapter *adapter;
struct ixgbe_hw *hw;
struct skb_shared_hwtstamps shhwtstamps;
u64 regval = 0, ns;
u32 tsynctxctl;
unsigned long flags;
if (!q_vector || !q_vector->adapter)
return;
adapter = q_vector->adapter;
hw = &adapter->hw;
tsynctxctl = IXGBE_READ_REG(hw, IXGBE_TSYNCTXCTL);
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_TXSTMPL);
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_TXSTMPH) << 32;
if (!(tsynctxctl & IXGBE_TSYNCTXCTL_VALID))
return;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_cyc2time(&adapter->tc, regval);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
shhwtstamps.hwtstamp = ns_to_ktime(ns);
skb_tstamp_tx(skb, &shhwtstamps);
}
void ixgbe_ptp_rx_hwtstamp(struct ixgbe_q_vector *q_vector,
union ixgbe_adv_rx_desc *rx_desc,
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
if (likely(!(tsyncrxctl & IXGBE_TSYNCRXCTL_VALID) ||
!ixgbe_ptp_match(skb, adapter->rx_hwtstamp_filter)))
return;
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_RXSTMPL);
regval |= (u64)IXGBE_READ_REG(hw, IXGBE_RXSTMPH) << 32;
if (unlikely(!ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_STAT_TS)))
return;
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
u32 tsync_rx_mtrl = 0;
bool is_l4 = false;
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
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_mtrl = IXGBE_RXMTRL_V1_SYNC_MSG;
is_l4 = true;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_mtrl = IXGBE_RXMTRL_V1_DELAY_REQ_MSG;
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
tsync_rx_ctl |= IXGBE_TSYNCRXCTL_TYPE_EVENT_V2;
is_l2 = true;
is_l4 = true;
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
adapter->rx_hwtstamp_filter = config.rx_filter;
if (is_l2)
IXGBE_WRITE_REG(hw, IXGBE_ETQF(3),
(IXGBE_ETQF_FILTER_EN |
IXGBE_ETQF_1588 |
ETH_P_1588));
else
IXGBE_WRITE_REG(hw, IXGBE_ETQF(3), 0);
#define PTP_PORT 319
if (is_l4) {
u32 ftqf = (IXGBE_FTQF_PROTOCOL_UDP
| IXGBE_FTQF_POOL_MASK_EN
| IXGBE_FTQF_QUEUE_ENABLE);
ftqf |= ((IXGBE_FTQF_PROTOCOL_COMP_MASK
& IXGBE_FTQF_DEST_PORT_MASK
& IXGBE_FTQF_SOURCE_PORT_MASK)
<< IXGBE_FTQF_5TUPLE_MASK_SHIFT);
IXGBE_WRITE_REG(hw, IXGBE_L34T_IMIR(3),
(3 << IXGBE_IMIR_RX_QUEUE_SHIFT_82599 |
IXGBE_IMIR_SIZE_BP_82599));
IXGBE_WRITE_REG(hw, IXGBE_SDPQF(3),
(htons(PTP_PORT) |
htons(PTP_PORT) << 16));
IXGBE_WRITE_REG(hw, IXGBE_FTQF(3), ftqf);
tsync_rx_mtrl |= PTP_PORT << 16;
} else {
IXGBE_WRITE_REG(hw, IXGBE_FTQF(3), 0);
}
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
u32 timinca = 0;
u32 shift = 0;
u32 cycle_speed;
unsigned long flags;
switch (adapter->link_speed) {
case IXGBE_LINK_SPEED_100_FULL:
case IXGBE_LINK_SPEED_1GB_FULL:
case IXGBE_LINK_SPEED_10GB_FULL:
cycle_speed = adapter->link_speed;
break;
default:
cycle_speed = IXGBE_LINK_SPEED_10GB_FULL;
break;
}
timinca = IXGBE_READ_REG(hw, IXGBE_TIMINCA);
if (adapter->cycle_speed == cycle_speed && timinca)
return;
ixgbe_ptp_disable_sdp(hw);
switch (cycle_speed) {
case IXGBE_LINK_SPEED_100_FULL:
incval = IXGBE_INCVAL_100;
shift = IXGBE_INCVAL_SHIFT_100;
break;
case IXGBE_LINK_SPEED_1GB_FULL:
incval = IXGBE_INCVAL_1GB;
shift = IXGBE_INCVAL_SHIFT_1GB;
break;
case IXGBE_LINK_SPEED_10GB_FULL:
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
IXGBE_WRITE_REG(hw, IXGBE_SYSTIML, 0x00000000);
IXGBE_WRITE_REG(hw, IXGBE_SYSTIMH, 0x00000000);
IXGBE_WRITE_FLUSH(hw);
ixgbe_ptp_enable_sdp(hw, shift);
adapter->cycle_speed = cycle_speed;
ACCESS_ONCE(adapter->base_incval) = incval;
smp_mb();
spin_lock_irqsave(&adapter->tmreg_lock, flags);
memset(&adapter->cc, 0, sizeof(adapter->cc));
adapter->cc.read = ixgbe_ptp_read;
adapter->cc.mask = CLOCKSOURCE_MASK(64);
adapter->cc.shift = shift;
adapter->cc.mult = 1;
timecounter_init(&adapter->tc, &adapter->cc,
ktime_to_ns(ktime_get_real()));
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
}
void ixgbe_ptp_init(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
switch (adapter->hw.mac.type) {
case ixgbe_mac_X540:
snprintf(adapter->ptp_caps.name, 16, "%pm", netdev->dev_addr);
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
snprintf(adapter->ptp_caps.name, 16, "%pm", netdev->dev_addr);
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
if (ptp_filter_init(ptp_filter, ARRAY_SIZE(ptp_filter)))
e_dev_warn("ptp_filter_init failed\n");
spin_lock_init(&adapter->tmreg_lock);
ixgbe_ptp_start_cyclecounter(adapter);
adapter->flags2 |= IXGBE_FLAG2_OVERFLOW_CHECK_ENABLED;
adapter->ptp_clock = ptp_clock_register(&adapter->ptp_caps);
if (IS_ERR(adapter->ptp_clock)) {
adapter->ptp_clock = NULL;
e_dev_err("ptp_clock_register failed\n");
} else
e_dev_info("registered PHC device on %s\n", netdev->name);
return;
}
void ixgbe_ptp_stop(struct ixgbe_adapter *adapter)
{
ixgbe_ptp_disable_sdp(&adapter->hw);
adapter->flags2 &= ~IXGBE_FLAG2_OVERFLOW_CHECK_ENABLED;
if (adapter->ptp_clock) {
ptp_clock_unregister(adapter->ptp_clock);
adapter->ptp_clock = NULL;
e_dev_info("removed PHC on %s\n",
adapter->netdev->name);
}
}
