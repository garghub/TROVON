void fm10k_systime_to_hwtstamp(struct fm10k_intfc *interface,
struct skb_shared_hwtstamps *hwtstamp,
u64 systime)
{
unsigned long flags;
read_lock_irqsave(&interface->systime_lock, flags);
systime += interface->ptp_adjust;
read_unlock_irqrestore(&interface->systime_lock, flags);
hwtstamp->hwtstamp = ns_to_ktime(systime);
}
static struct sk_buff *fm10k_ts_tx_skb(struct fm10k_intfc *interface,
__le16 dglort)
{
struct sk_buff_head *list = &interface->ts_tx_skb_queue;
struct sk_buff *skb;
skb_queue_walk(list, skb) {
if (FM10K_CB(skb)->fi.w.dglort == dglort)
return skb;
}
return NULL;
}
void fm10k_ts_tx_enqueue(struct fm10k_intfc *interface, struct sk_buff *skb)
{
struct sk_buff_head *list = &interface->ts_tx_skb_queue;
struct sk_buff *clone;
unsigned long flags;
clone = skb_clone_sk(skb);
if (!clone)
return;
FM10K_CB(clone)->ts_tx_timeout = jiffies + FM10K_TS_TX_TIMEOUT;
spin_lock_irqsave(&list->lock, flags);
skb = fm10k_ts_tx_skb(interface, FM10K_CB(clone)->fi.w.dglort);
if (!skb)
__skb_queue_tail(list, clone);
spin_unlock_irqrestore(&list->lock, flags);
if (skb)
kfree_skb(skb);
else
skb_shinfo(clone)->tx_flags |= SKBTX_IN_PROGRESS;
}
void fm10k_ts_tx_hwtstamp(struct fm10k_intfc *interface, __le16 dglort,
u64 systime)
{
struct skb_shared_hwtstamps shhwtstamps;
struct sk_buff_head *list = &interface->ts_tx_skb_queue;
struct sk_buff *skb;
unsigned long flags;
spin_lock_irqsave(&list->lock, flags);
skb = fm10k_ts_tx_skb(interface, dglort);
if (skb)
__skb_unlink(skb, list);
spin_unlock_irqrestore(&list->lock, flags);
if (!skb)
return;
fm10k_systime_to_hwtstamp(interface, &shhwtstamps, systime);
skb_complete_tx_timestamp(skb, &shhwtstamps);
}
void fm10k_ts_tx_subtask(struct fm10k_intfc *interface)
{
struct sk_buff_head *list = &interface->ts_tx_skb_queue;
struct sk_buff *skb, *tmp;
unsigned long flags;
if (test_bit(__FM10K_DOWN, &interface->state) ||
test_bit(__FM10K_RESETTING, &interface->state))
return;
spin_lock_irqsave(&list->lock, flags);
skb_queue_walk_safe(list, skb, tmp) {
if (!time_is_after_jiffies(FM10K_CB(skb)->ts_tx_timeout))
continue;
__skb_unlink(skb, list);
kfree_skb(skb);
interface->tx_hwtstamp_timeouts++;
}
spin_unlock_irqrestore(&list->lock, flags);
}
static u64 fm10k_systime_read(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
return hw->mac.ops.read_systime(hw);
}
void fm10k_ts_reset(struct fm10k_intfc *interface)
{
s64 ns = ktime_to_ns(ktime_get_real());
unsigned long flags;
write_lock_irqsave(&interface->systime_lock, flags);
interface->ptp_adjust = fm10k_systime_read(interface) - ns;
write_unlock_irqrestore(&interface->systime_lock, flags);
}
void fm10k_ts_init(struct fm10k_intfc *interface)
{
rwlock_init(&interface->systime_lock);
skb_queue_head_init(&interface->ts_tx_skb_queue);
fm10k_ts_reset(interface);
}
int fm10k_get_ts_config(struct net_device *netdev, struct ifreq *ifr)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct hwtstamp_config *config = &interface->ts_config;
return copy_to_user(ifr->ifr_data, config, sizeof(*config)) ?
-EFAULT : 0;
}
int fm10k_set_ts_config(struct net_device *netdev, struct ifreq *ifr)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
struct hwtstamp_config ts_config;
if (copy_from_user(&ts_config, ifr->ifr_data, sizeof(ts_config)))
return -EFAULT;
if (ts_config.flags)
return -EINVAL;
switch (ts_config.tx_type) {
case HWTSTAMP_TX_OFF:
break;
case HWTSTAMP_TX_ON:
break;
default:
return -ERANGE;
}
switch (ts_config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
interface->flags &= ~FM10K_FLAG_RX_TS_ENABLED;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
case HWTSTAMP_FILTER_ALL:
interface->flags |= FM10K_FLAG_RX_TS_ENABLED;
ts_config.rx_filter = HWTSTAMP_FILTER_ALL;
break;
default:
return -ERANGE;
}
interface->ts_config = ts_config;
return copy_to_user(ifr->ifr_data, &ts_config, sizeof(ts_config)) ?
-EFAULT : 0;
}
static int fm10k_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
struct fm10k_intfc *interface;
struct fm10k_hw *hw;
int err;
interface = container_of(ptp, struct fm10k_intfc, ptp_caps);
hw = &interface->hw;
err = hw->mac.ops.adjust_systime(hw, ppb);
return (err == FM10K_ERR_PARAM) ? -ERANGE : err;
}
static int fm10k_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct fm10k_intfc *interface;
unsigned long flags;
interface = container_of(ptp, struct fm10k_intfc, ptp_caps);
write_lock_irqsave(&interface->systime_lock, flags);
interface->ptp_adjust += delta;
write_unlock_irqrestore(&interface->systime_lock, flags);
return 0;
}
static int fm10k_ptp_gettime(struct ptp_clock_info *ptp, struct timespec *ts)
{
struct fm10k_intfc *interface;
unsigned long flags;
u64 now;
interface = container_of(ptp, struct fm10k_intfc, ptp_caps);
read_lock_irqsave(&interface->systime_lock, flags);
now = fm10k_systime_read(interface) + interface->ptp_adjust;
read_unlock_irqrestore(&interface->systime_lock, flags);
*ts = ns_to_timespec(now);
return 0;
}
static int fm10k_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
struct fm10k_intfc *interface;
unsigned long flags;
u64 ns = timespec_to_ns(ts);
interface = container_of(ptp, struct fm10k_intfc, ptp_caps);
write_lock_irqsave(&interface->systime_lock, flags);
interface->ptp_adjust = fm10k_systime_read(interface) - ns;
write_unlock_irqrestore(&interface->systime_lock, flags);
return 0;
}
static int fm10k_ptp_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
struct ptp_clock_time *t = &rq->perout.period;
struct fm10k_intfc *interface;
struct fm10k_hw *hw;
u64 period;
u32 step;
if (rq->type != PTP_CLK_REQ_PEROUT)
return -EINVAL;
if (rq->perout.index >= ptp->n_per_out)
return -EINVAL;
if (t->sec > 4 || t->sec < 0)
return -ERANGE;
interface = container_of(ptp, struct fm10k_intfc, ptp_caps);
hw = &interface->hw;
if (!hw->sw_addr)
return -ENOTSUPP;
period = t->sec * 1000000000LL + t->nsec;
step = 2 * (fm10k_read_reg(hw, FM10K_SYSTIME_CFG) &
FM10K_SYSTIME_CFG_STEP_MASK);
if ((period && (period < step)) || (period > U32_MAX))
return -ERANGE;
fm10k_write_sw_reg(hw, FM10K_SW_SYSTIME_PULSE(rq->perout.index),
(u32)period);
return 0;
}
static int fm10k_ptp_verify(struct ptp_clock_info *ptp, unsigned int pin,
enum ptp_pin_function func, unsigned int chan)
{
if (pin >= ptp->n_pins || !ptp->pin_config)
return -EINVAL;
if (chan != ptp->pin_config[pin].chan)
return -EINVAL;
if (func != ptp->pin_config[pin].func)
return -EINVAL;
return 0;
}
void fm10k_ptp_register(struct fm10k_intfc *interface)
{
struct ptp_clock_info *ptp_caps = &interface->ptp_caps;
struct device *dev = &interface->pdev->dev;
struct ptp_clock *ptp_clock;
snprintf(ptp_caps->name, sizeof(ptp_caps->name),
"%s", interface->netdev->name);
ptp_caps->owner = THIS_MODULE;
ptp_caps->max_adj = 976562;
ptp_caps->adjfreq = fm10k_ptp_adjfreq;
ptp_caps->adjtime = fm10k_ptp_adjtime;
ptp_caps->gettime = fm10k_ptp_gettime;
ptp_caps->settime = fm10k_ptp_settime;
if (interface->sw_addr) {
ptp_caps->n_per_out = 2;
ptp_caps->enable = fm10k_ptp_enable;
ptp_caps->verify = fm10k_ptp_verify;
ptp_caps->n_pins = 2;
ptp_caps->pin_config = fm10k_ptp_pd;
}
ptp_clock = ptp_clock_register(ptp_caps, dev);
if (IS_ERR(ptp_clock)) {
ptp_clock = NULL;
dev_err(dev, "ptp_clock_register failed\n");
} else {
dev_info(dev, "registered PHC device %s\n", ptp_caps->name);
}
interface->ptp_clock = ptp_clock;
}
void fm10k_ptp_unregister(struct fm10k_intfc *interface)
{
struct ptp_clock *ptp_clock = interface->ptp_clock;
struct device *dev = &interface->pdev->dev;
if (!ptp_clock)
return;
interface->ptp_clock = NULL;
ptp_clock_unregister(ptp_clock);
dev_info(dev, "removed PHC %s\n", interface->ptp_caps.name);
}
