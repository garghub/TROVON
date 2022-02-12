static void i40e_ptp_read(struct i40e_pf *pf, struct timespec64 *ts)
{
struct i40e_hw *hw = &pf->hw;
u32 hi, lo;
u64 ns;
lo = rd32(hw, I40E_PRTTSYN_TIME_L);
hi = rd32(hw, I40E_PRTTSYN_TIME_H);
ns = (((u64)hi) << 32) | lo;
*ts = ns_to_timespec64(ns);
}
static void i40e_ptp_write(struct i40e_pf *pf, const struct timespec64 *ts)
{
struct i40e_hw *hw = &pf->hw;
u64 ns = timespec64_to_ns(ts);
wr32(hw, I40E_PRTTSYN_TIME_L, ns & 0xFFFFFFFF);
wr32(hw, I40E_PRTTSYN_TIME_H, ns >> 32);
}
static void i40e_ptp_convert_to_hwtstamp(struct skb_shared_hwtstamps *hwtstamps,
u64 timestamp)
{
memset(hwtstamps, 0, sizeof(*hwtstamps));
hwtstamps->hwtstamp = ns_to_ktime(timestamp);
}
static int i40e_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
struct i40e_pf *pf = container_of(ptp, struct i40e_pf, ptp_caps);
struct i40e_hw *hw = &pf->hw;
u64 adj, freq, diff;
int neg_adj = 0;
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
smp_mb();
adj = ACCESS_ONCE(pf->ptp_base_adj);
freq = adj;
freq *= ppb;
diff = div_u64(freq, 1000000000ULL);
if (neg_adj)
adj -= diff;
else
adj += diff;
wr32(hw, I40E_PRTTSYN_INC_L, adj & 0xFFFFFFFF);
wr32(hw, I40E_PRTTSYN_INC_H, adj >> 32);
return 0;
}
static int i40e_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct i40e_pf *pf = container_of(ptp, struct i40e_pf, ptp_caps);
struct timespec64 now;
mutex_lock(&pf->tmreg_lock);
i40e_ptp_read(pf, &now);
timespec64_add_ns(&now, delta);
i40e_ptp_write(pf, (const struct timespec64 *)&now);
mutex_unlock(&pf->tmreg_lock);
return 0;
}
static int i40e_ptp_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
struct i40e_pf *pf = container_of(ptp, struct i40e_pf, ptp_caps);
mutex_lock(&pf->tmreg_lock);
i40e_ptp_read(pf, ts);
mutex_unlock(&pf->tmreg_lock);
return 0;
}
static int i40e_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
struct i40e_pf *pf = container_of(ptp, struct i40e_pf, ptp_caps);
mutex_lock(&pf->tmreg_lock);
i40e_ptp_write(pf, ts);
mutex_unlock(&pf->tmreg_lock);
return 0;
}
static int i40e_ptp_feature_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
static u32 i40e_ptp_get_rx_events(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
u32 prttsyn_stat, new_latch_events;
int i;
prttsyn_stat = rd32(hw, I40E_PRTTSYN_STAT_1);
new_latch_events = prttsyn_stat & ~pf->latch_event_flags;
for (i = 0; i < 4; i++) {
if (new_latch_events & BIT(i))
pf->latch_events[i] = jiffies;
}
pf->latch_event_flags = prttsyn_stat;
return prttsyn_stat;
}
void i40e_ptp_rx_hang(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
unsigned int i, cleared = 0;
if (!(pf->flags & I40E_FLAG_PTP) || !pf->ptp_rx)
return;
spin_lock_bh(&pf->ptp_rx_lock);
i40e_ptp_get_rx_events(pf);
for (i = 0; i < 4; i++) {
if ((pf->latch_event_flags & BIT(i)) &&
time_is_before_jiffies(pf->latch_events[i] + HZ)) {
rd32(hw, I40E_PRTTSYN_RXTIME_H(i));
pf->latch_event_flags &= ~BIT(i);
cleared++;
}
}
spin_unlock_bh(&pf->ptp_rx_lock);
if (cleared > 2)
dev_dbg(&pf->pdev->dev,
"Dropped %d missed RXTIME timestamp events\n",
cleared);
pf->rx_hwtstamp_cleared += cleared;
}
void i40e_ptp_tx_hang(struct i40e_pf *pf)
{
if (!(pf->flags & I40E_FLAG_PTP) || !pf->ptp_tx)
return;
if (!test_bit(__I40E_PTP_TX_IN_PROGRESS, pf->state))
return;
if (time_is_before_jiffies(pf->ptp_tx_start + HZ)) {
dev_kfree_skb_any(pf->ptp_tx_skb);
pf->ptp_tx_skb = NULL;
clear_bit_unlock(__I40E_PTP_TX_IN_PROGRESS, pf->state);
pf->tx_hwtstamp_timeouts++;
}
}
void i40e_ptp_tx_hwtstamp(struct i40e_pf *pf)
{
struct skb_shared_hwtstamps shhwtstamps;
struct sk_buff *skb = pf->ptp_tx_skb;
struct i40e_hw *hw = &pf->hw;
u32 hi, lo;
u64 ns;
if (!(pf->flags & I40E_FLAG_PTP) || !pf->ptp_tx)
return;
if (!pf->ptp_tx_skb)
return;
lo = rd32(hw, I40E_PRTTSYN_TXTIME_L);
hi = rd32(hw, I40E_PRTTSYN_TXTIME_H);
ns = (((u64)hi) << 32) | lo;
i40e_ptp_convert_to_hwtstamp(&shhwtstamps, ns);
pf->ptp_tx_skb = NULL;
clear_bit_unlock(__I40E_PTP_TX_IN_PROGRESS, pf->state);
skb_tstamp_tx(skb, &shhwtstamps);
dev_kfree_skb_any(skb);
}
void i40e_ptp_rx_hwtstamp(struct i40e_pf *pf, struct sk_buff *skb, u8 index)
{
u32 prttsyn_stat, hi, lo;
struct i40e_hw *hw;
u64 ns;
if (!(pf->flags & I40E_FLAG_PTP) || !pf->ptp_rx)
return;
hw = &pf->hw;
spin_lock_bh(&pf->ptp_rx_lock);
prttsyn_stat = i40e_ptp_get_rx_events(pf);
if (!(prttsyn_stat & BIT(index))) {
spin_unlock_bh(&pf->ptp_rx_lock);
return;
}
pf->latch_event_flags &= ~BIT(index);
lo = rd32(hw, I40E_PRTTSYN_RXTIME_L(index));
hi = rd32(hw, I40E_PRTTSYN_RXTIME_H(index));
spin_unlock_bh(&pf->ptp_rx_lock);
ns = (((u64)hi) << 32) | lo;
i40e_ptp_convert_to_hwtstamp(skb_hwtstamps(skb), ns);
}
void i40e_ptp_set_increment(struct i40e_pf *pf)
{
struct i40e_link_status *hw_link_info;
struct i40e_hw *hw = &pf->hw;
u64 incval;
hw_link_info = &hw->phy.link_info;
i40e_aq_get_link_info(&pf->hw, true, NULL, NULL);
switch (hw_link_info->link_speed) {
case I40E_LINK_SPEED_10GB:
incval = I40E_PTP_10GB_INCVAL;
break;
case I40E_LINK_SPEED_1GB:
incval = I40E_PTP_1GB_INCVAL;
break;
case I40E_LINK_SPEED_100MB:
{
static int warn_once;
if (!warn_once) {
dev_warn(&pf->pdev->dev,
"1588 functionality is not supported at 100 Mbps. Stopping the PHC.\n");
warn_once++;
}
incval = 0;
break;
}
case I40E_LINK_SPEED_40GB:
default:
incval = I40E_PTP_40GB_INCVAL;
break;
}
wr32(hw, I40E_PRTTSYN_INC_L, incval & 0xFFFFFFFF);
wr32(hw, I40E_PRTTSYN_INC_H, incval >> 32);
ACCESS_ONCE(pf->ptp_base_adj) = incval;
smp_mb();
}
int i40e_ptp_get_ts_config(struct i40e_pf *pf, struct ifreq *ifr)
{
struct hwtstamp_config *config = &pf->tstamp_config;
if (!(pf->flags & I40E_FLAG_PTP))
return -EOPNOTSUPP;
return copy_to_user(ifr->ifr_data, config, sizeof(*config)) ?
-EFAULT : 0;
}
static int i40e_ptp_set_timestamp_mode(struct i40e_pf *pf,
struct hwtstamp_config *config)
{
struct i40e_hw *hw = &pf->hw;
u32 tsyntype, regval;
if (config->flags)
return -EINVAL;
switch (config->tx_type) {
case HWTSTAMP_TX_OFF:
pf->ptp_tx = false;
break;
case HWTSTAMP_TX_ON:
pf->ptp_tx = true;
break;
default:
return -ERANGE;
}
switch (config->rx_filter) {
case HWTSTAMP_FILTER_NONE:
pf->ptp_rx = false;
tsyntype = I40E_PRTTSYN_CTL1_TSYNTYPE_V1;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
if (!(pf->hw_features & I40E_HW_PTP_L4_CAPABLE))
return -ERANGE;
pf->ptp_rx = true;
tsyntype = I40E_PRTTSYN_CTL1_V1MESSTYPE0_MASK |
I40E_PRTTSYN_CTL1_TSYNTYPE_V1 |
I40E_PRTTSYN_CTL1_UDP_ENA_MASK;
config->rx_filter = HWTSTAMP_FILTER_PTP_V1_L4_EVENT;
break;
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
if (!(pf->hw_features & I40E_HW_PTP_L4_CAPABLE))
return -ERANGE;
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
pf->ptp_rx = true;
tsyntype = I40E_PRTTSYN_CTL1_V2MESSTYPE0_MASK |
I40E_PRTTSYN_CTL1_TSYNTYPE_V2;
if (pf->hw_features & I40E_HW_PTP_L4_CAPABLE) {
tsyntype |= I40E_PRTTSYN_CTL1_UDP_ENA_MASK;
config->rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
} else {
config->rx_filter = HWTSTAMP_FILTER_PTP_V2_L2_EVENT;
}
break;
case HWTSTAMP_FILTER_NTP_ALL:
case HWTSTAMP_FILTER_ALL:
default:
return -ERANGE;
}
spin_lock_bh(&pf->ptp_rx_lock);
rd32(hw, I40E_PRTTSYN_STAT_0);
rd32(hw, I40E_PRTTSYN_TXTIME_H);
rd32(hw, I40E_PRTTSYN_RXTIME_H(0));
rd32(hw, I40E_PRTTSYN_RXTIME_H(1));
rd32(hw, I40E_PRTTSYN_RXTIME_H(2));
rd32(hw, I40E_PRTTSYN_RXTIME_H(3));
pf->latch_event_flags = 0;
spin_unlock_bh(&pf->ptp_rx_lock);
regval = rd32(hw, I40E_PRTTSYN_CTL0);
if (pf->ptp_tx)
regval |= I40E_PRTTSYN_CTL0_TXTIME_INT_ENA_MASK;
else
regval &= ~I40E_PRTTSYN_CTL0_TXTIME_INT_ENA_MASK;
wr32(hw, I40E_PRTTSYN_CTL0, regval);
regval = rd32(hw, I40E_PFINT_ICR0_ENA);
if (pf->ptp_tx)
regval |= I40E_PFINT_ICR0_ENA_TIMESYNC_MASK;
else
regval &= ~I40E_PFINT_ICR0_ENA_TIMESYNC_MASK;
wr32(hw, I40E_PFINT_ICR0_ENA, regval);
regval = rd32(hw, I40E_PRTTSYN_CTL1);
regval &= I40E_PRTTSYN_CTL1_TSYNENA_MASK;
regval |= tsyntype;
wr32(hw, I40E_PRTTSYN_CTL1, regval);
return 0;
}
int i40e_ptp_set_ts_config(struct i40e_pf *pf, struct ifreq *ifr)
{
struct hwtstamp_config config;
int err;
if (!(pf->flags & I40E_FLAG_PTP))
return -EOPNOTSUPP;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
err = i40e_ptp_set_timestamp_mode(pf, &config);
if (err)
return err;
pf->tstamp_config = config;
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static long i40e_ptp_create_clock(struct i40e_pf *pf)
{
if (!IS_ERR_OR_NULL(pf->ptp_clock))
return 0;
strncpy(pf->ptp_caps.name, i40e_driver_name, sizeof(pf->ptp_caps.name));
pf->ptp_caps.owner = THIS_MODULE;
pf->ptp_caps.max_adj = 999999999;
pf->ptp_caps.n_ext_ts = 0;
pf->ptp_caps.pps = 0;
pf->ptp_caps.adjfreq = i40e_ptp_adjfreq;
pf->ptp_caps.adjtime = i40e_ptp_adjtime;
pf->ptp_caps.gettime64 = i40e_ptp_gettime;
pf->ptp_caps.settime64 = i40e_ptp_settime;
pf->ptp_caps.enable = i40e_ptp_feature_enable;
pf->ptp_clock = ptp_clock_register(&pf->ptp_caps, &pf->pdev->dev);
if (IS_ERR(pf->ptp_clock))
return PTR_ERR(pf->ptp_clock);
pf->tstamp_config.rx_filter = HWTSTAMP_FILTER_NONE;
pf->tstamp_config.tx_type = HWTSTAMP_TX_OFF;
return 0;
}
void i40e_ptp_init(struct i40e_pf *pf)
{
struct net_device *netdev = pf->vsi[pf->lan_vsi]->netdev;
struct i40e_hw *hw = &pf->hw;
u32 pf_id;
long err;
pf_id = (rd32(hw, I40E_PRTTSYN_CTL0) & I40E_PRTTSYN_CTL0_PF_ID_MASK) >>
I40E_PRTTSYN_CTL0_PF_ID_SHIFT;
if (hw->pf_id != pf_id) {
pf->flags &= ~I40E_FLAG_PTP;
dev_info(&pf->pdev->dev, "%s: PTP not supported on %s\n",
__func__,
netdev->name);
return;
}
mutex_init(&pf->tmreg_lock);
spin_lock_init(&pf->ptp_rx_lock);
err = i40e_ptp_create_clock(pf);
if (err) {
pf->ptp_clock = NULL;
dev_err(&pf->pdev->dev, "%s: ptp_clock_register failed\n",
__func__);
} else if (pf->ptp_clock) {
struct timespec64 ts;
u32 regval;
if (pf->hw.debug_mask & I40E_DEBUG_LAN)
dev_info(&pf->pdev->dev, "PHC enabled\n");
pf->flags |= I40E_FLAG_PTP;
regval = rd32(hw, I40E_PRTTSYN_CTL0);
regval |= I40E_PRTTSYN_CTL0_TSYNENA_MASK;
wr32(hw, I40E_PRTTSYN_CTL0, regval);
regval = rd32(hw, I40E_PRTTSYN_CTL1);
regval |= I40E_PRTTSYN_CTL1_TSYNENA_MASK;
wr32(hw, I40E_PRTTSYN_CTL1, regval);
i40e_ptp_set_increment(pf);
i40e_ptp_set_timestamp_mode(pf, &pf->tstamp_config);
ts = ktime_to_timespec64(ktime_get_real());
i40e_ptp_settime(&pf->ptp_caps, &ts);
}
}
void i40e_ptp_stop(struct i40e_pf *pf)
{
pf->flags &= ~I40E_FLAG_PTP;
pf->ptp_tx = false;
pf->ptp_rx = false;
if (pf->ptp_tx_skb) {
dev_kfree_skb_any(pf->ptp_tx_skb);
pf->ptp_tx_skb = NULL;
clear_bit_unlock(__I40E_PTP_TX_IN_PROGRESS, pf->state);
}
if (pf->ptp_clock) {
ptp_clock_unregister(pf->ptp_clock);
pf->ptp_clock = NULL;
dev_info(&pf->pdev->dev, "%s: removed PHC on %s\n", __func__,
pf->vsi[pf->lan_vsi]->netdev->name);
}
}
