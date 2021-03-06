static int event_expired(struct cpts_event *event)
{
return time_after(jiffies, event->tmo);
}
static int event_type(struct cpts_event *event)
{
return (event->high >> EVENT_TYPE_SHIFT) & EVENT_TYPE_MASK;
}
static int cpts_fifo_pop(struct cpts *cpts, u32 *high, u32 *low)
{
u32 r = cpts_read32(cpts, intstat_raw);
if (r & TS_PEND_RAW) {
*high = cpts_read32(cpts, event_high);
*low = cpts_read32(cpts, event_low);
cpts_write32(cpts, EVENT_POP, event_pop);
return 0;
}
return -1;
}
static int cpts_purge_events(struct cpts *cpts)
{
struct list_head *this, *next;
struct cpts_event *event;
int removed = 0;
list_for_each_safe(this, next, &cpts->events) {
event = list_entry(this, struct cpts_event, list);
if (event_expired(event)) {
list_del_init(&event->list);
list_add(&event->list, &cpts->pool);
++removed;
}
}
if (removed)
pr_debug("cpts: event pool cleaned up %d\n", removed);
return removed ? 0 : -1;
}
static bool cpts_match_tx_ts(struct cpts *cpts, struct cpts_event *event)
{
struct sk_buff *skb, *tmp;
u16 seqid;
u8 mtype;
bool found = false;
mtype = (event->high >> MESSAGE_TYPE_SHIFT) & MESSAGE_TYPE_MASK;
seqid = (event->high >> SEQUENCE_ID_SHIFT) & SEQUENCE_ID_MASK;
skb_queue_walk_safe(&cpts->txq, skb, tmp) {
struct skb_shared_hwtstamps ssh;
unsigned int class = ptp_classify_raw(skb);
struct cpts_skb_cb_data *skb_cb =
(struct cpts_skb_cb_data *)skb->cb;
if (cpts_match(skb, class, seqid, mtype)) {
u64 ns = timecounter_cyc2time(&cpts->tc, event->low);
memset(&ssh, 0, sizeof(ssh));
ssh.hwtstamp = ns_to_ktime(ns);
skb_tstamp_tx(skb, &ssh);
found = true;
__skb_unlink(skb, &cpts->txq);
dev_consume_skb_any(skb);
dev_dbg(cpts->dev, "match tx timestamp mtype %u seqid %04x\n",
mtype, seqid);
} else if (time_after(jiffies, skb_cb->tmo)) {
dev_dbg(cpts->dev,
"expiring tx timestamp mtype %u seqid %04x\n",
mtype, seqid);
__skb_unlink(skb, &cpts->txq);
dev_consume_skb_any(skb);
}
}
return found;
}
static int cpts_fifo_read(struct cpts *cpts, int match)
{
int i, type = -1;
u32 hi, lo;
struct cpts_event *event;
for (i = 0; i < CPTS_FIFO_DEPTH; i++) {
if (cpts_fifo_pop(cpts, &hi, &lo))
break;
if (list_empty(&cpts->pool) && cpts_purge_events(cpts)) {
pr_err("cpts: event pool empty\n");
return -1;
}
event = list_first_entry(&cpts->pool, struct cpts_event, list);
event->tmo = jiffies + 2;
event->high = hi;
event->low = lo;
type = event_type(event);
switch (type) {
case CPTS_EV_TX:
if (cpts_match_tx_ts(cpts, event)) {
break;
}
case CPTS_EV_PUSH:
case CPTS_EV_RX:
list_del_init(&event->list);
list_add_tail(&event->list, &cpts->events);
break;
case CPTS_EV_ROLL:
case CPTS_EV_HALF:
case CPTS_EV_HW:
break;
default:
pr_err("cpts: unknown event type\n");
break;
}
if (type == match)
break;
}
return type == match ? 0 : -1;
}
static u64 cpts_systim_read(const struct cyclecounter *cc)
{
u64 val = 0;
struct cpts_event *event;
struct list_head *this, *next;
struct cpts *cpts = container_of(cc, struct cpts, cc);
cpts_write32(cpts, TS_PUSH, ts_push);
if (cpts_fifo_read(cpts, CPTS_EV_PUSH))
pr_err("cpts: unable to obtain a time stamp\n");
list_for_each_safe(this, next, &cpts->events) {
event = list_entry(this, struct cpts_event, list);
if (event_type(event) == CPTS_EV_PUSH) {
list_del_init(&event->list);
list_add(&event->list, &cpts->pool);
val = event->low;
break;
}
}
return val;
}
static int cpts_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
u64 adj;
u32 diff, mult;
int neg_adj = 0;
unsigned long flags;
struct cpts *cpts = container_of(ptp, struct cpts, info);
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
mult = cpts->cc_mult;
adj = mult;
adj *= ppb;
diff = div_u64(adj, 1000000000ULL);
spin_lock_irqsave(&cpts->lock, flags);
timecounter_read(&cpts->tc);
cpts->cc.mult = neg_adj ? mult - diff : mult + diff;
spin_unlock_irqrestore(&cpts->lock, flags);
return 0;
}
static int cpts_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
unsigned long flags;
struct cpts *cpts = container_of(ptp, struct cpts, info);
spin_lock_irqsave(&cpts->lock, flags);
timecounter_adjtime(&cpts->tc, delta);
spin_unlock_irqrestore(&cpts->lock, flags);
return 0;
}
static int cpts_ptp_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
u64 ns;
unsigned long flags;
struct cpts *cpts = container_of(ptp, struct cpts, info);
spin_lock_irqsave(&cpts->lock, flags);
ns = timecounter_read(&cpts->tc);
spin_unlock_irqrestore(&cpts->lock, flags);
*ts = ns_to_timespec64(ns);
return 0;
}
static int cpts_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
u64 ns;
unsigned long flags;
struct cpts *cpts = container_of(ptp, struct cpts, info);
ns = timespec64_to_ns(ts);
spin_lock_irqsave(&cpts->lock, flags);
timecounter_init(&cpts->tc, &cpts->cc, ns);
spin_unlock_irqrestore(&cpts->lock, flags);
return 0;
}
static int cpts_ptp_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
static long cpts_overflow_check(struct ptp_clock_info *ptp)
{
struct cpts *cpts = container_of(ptp, struct cpts, info);
unsigned long delay = cpts->ov_check_period;
struct timespec64 ts;
unsigned long flags;
spin_lock_irqsave(&cpts->lock, flags);
ts = ns_to_timespec64(timecounter_read(&cpts->tc));
if (!skb_queue_empty(&cpts->txq))
delay = CPTS_SKB_TX_WORK_TIMEOUT;
spin_unlock_irqrestore(&cpts->lock, flags);
pr_debug("cpts overflow check at %lld.%09lu\n", ts.tv_sec, ts.tv_nsec);
return (long)delay;
}
static int cpts_match(struct sk_buff *skb, unsigned int ptp_class,
u16 ts_seqid, u8 ts_msgtype)
{
u16 *seqid;
unsigned int offset = 0;
u8 *msgtype, *data = skb->data;
if (ptp_class & PTP_CLASS_VLAN)
offset += VLAN_HLEN;
switch (ptp_class & PTP_CLASS_PMASK) {
case PTP_CLASS_IPV4:
offset += ETH_HLEN + IPV4_HLEN(data + offset) + UDP_HLEN;
break;
case PTP_CLASS_IPV6:
offset += ETH_HLEN + IP6_HLEN + UDP_HLEN;
break;
case PTP_CLASS_L2:
offset += ETH_HLEN;
break;
default:
return 0;
}
if (skb->len + ETH_HLEN < offset + OFF_PTP_SEQUENCE_ID + sizeof(*seqid))
return 0;
if (unlikely(ptp_class & PTP_CLASS_V1))
msgtype = data + offset + OFF_PTP_CONTROL;
else
msgtype = data + offset;
seqid = (u16 *)(data + offset + OFF_PTP_SEQUENCE_ID);
return (ts_msgtype == (*msgtype & 0xf) && ts_seqid == ntohs(*seqid));
}
static u64 cpts_find_ts(struct cpts *cpts, struct sk_buff *skb, int ev_type)
{
u64 ns = 0;
struct cpts_event *event;
struct list_head *this, *next;
unsigned int class = ptp_classify_raw(skb);
unsigned long flags;
u16 seqid;
u8 mtype;
if (class == PTP_CLASS_NONE)
return 0;
spin_lock_irqsave(&cpts->lock, flags);
cpts_fifo_read(cpts, -1);
list_for_each_safe(this, next, &cpts->events) {
event = list_entry(this, struct cpts_event, list);
if (event_expired(event)) {
list_del_init(&event->list);
list_add(&event->list, &cpts->pool);
continue;
}
mtype = (event->high >> MESSAGE_TYPE_SHIFT) & MESSAGE_TYPE_MASK;
seqid = (event->high >> SEQUENCE_ID_SHIFT) & SEQUENCE_ID_MASK;
if (ev_type == event_type(event) &&
cpts_match(skb, class, seqid, mtype)) {
ns = timecounter_cyc2time(&cpts->tc, event->low);
list_del_init(&event->list);
list_add(&event->list, &cpts->pool);
break;
}
}
if (ev_type == CPTS_EV_TX && !ns) {
struct cpts_skb_cb_data *skb_cb =
(struct cpts_skb_cb_data *)skb->cb;
skb_get(skb);
skb_cb->tmo = jiffies + msecs_to_jiffies(100);
__skb_queue_tail(&cpts->txq, skb);
ptp_schedule_worker(cpts->clock, 0);
}
spin_unlock_irqrestore(&cpts->lock, flags);
return ns;
}
void cpts_rx_timestamp(struct cpts *cpts, struct sk_buff *skb)
{
u64 ns;
struct skb_shared_hwtstamps *ssh;
if (!cpts->rx_enable)
return;
ns = cpts_find_ts(cpts, skb, CPTS_EV_RX);
if (!ns)
return;
ssh = skb_hwtstamps(skb);
memset(ssh, 0, sizeof(*ssh));
ssh->hwtstamp = ns_to_ktime(ns);
}
void cpts_tx_timestamp(struct cpts *cpts, struct sk_buff *skb)
{
u64 ns;
struct skb_shared_hwtstamps ssh;
if (!(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS))
return;
ns = cpts_find_ts(cpts, skb, CPTS_EV_TX);
if (!ns)
return;
memset(&ssh, 0, sizeof(ssh));
ssh.hwtstamp = ns_to_ktime(ns);
skb_tstamp_tx(skb, &ssh);
}
int cpts_register(struct cpts *cpts)
{
int err, i;
skb_queue_head_init(&cpts->txq);
INIT_LIST_HEAD(&cpts->events);
INIT_LIST_HEAD(&cpts->pool);
for (i = 0; i < CPTS_MAX_EVENTS; i++)
list_add(&cpts->pool_data[i].list, &cpts->pool);
clk_enable(cpts->refclk);
cpts_write32(cpts, CPTS_EN, control);
cpts_write32(cpts, TS_PEND_EN, int_enable);
timecounter_init(&cpts->tc, &cpts->cc, ktime_to_ns(ktime_get_real()));
cpts->clock = ptp_clock_register(&cpts->info, cpts->dev);
if (IS_ERR(cpts->clock)) {
err = PTR_ERR(cpts->clock);
cpts->clock = NULL;
goto err_ptp;
}
cpts->phc_index = ptp_clock_index(cpts->clock);
ptp_schedule_worker(cpts->clock, cpts->ov_check_period);
return 0;
err_ptp:
clk_disable(cpts->refclk);
return err;
}
void cpts_unregister(struct cpts *cpts)
{
if (WARN_ON(!cpts->clock))
return;
ptp_clock_unregister(cpts->clock);
cpts->clock = NULL;
cpts_write32(cpts, 0, int_enable);
cpts_write32(cpts, 0, control);
skb_queue_purge(&cpts->txq);
clk_disable(cpts->refclk);
}
static void cpts_calc_mult_shift(struct cpts *cpts)
{
u64 frac, maxsec, ns;
u32 freq;
freq = clk_get_rate(cpts->refclk);
maxsec = cpts->cc.mask;
do_div(maxsec, freq);
if (maxsec > 10)
maxsec = 10;
cpts->ov_check_period = (HZ * maxsec) / 2;
dev_info(cpts->dev, "cpts: overflow check period %lu (jiffies)\n",
cpts->ov_check_period);
if (cpts->cc.mult || cpts->cc.shift)
return;
clocks_calc_mult_shift(&cpts->cc.mult, &cpts->cc.shift,
freq, NSEC_PER_SEC, maxsec);
frac = 0;
ns = cyclecounter_cyc2ns(&cpts->cc, freq, cpts->cc.mask, &frac);
dev_info(cpts->dev,
"CPTS: ref_clk_freq:%u calc_mult:%u calc_shift:%u error:%lld nsec/sec\n",
freq, cpts->cc.mult, cpts->cc.shift, (ns - NSEC_PER_SEC));
}
static int cpts_of_parse(struct cpts *cpts, struct device_node *node)
{
int ret = -EINVAL;
u32 prop;
if (!of_property_read_u32(node, "cpts_clock_mult", &prop))
cpts->cc.mult = prop;
if (!of_property_read_u32(node, "cpts_clock_shift", &prop))
cpts->cc.shift = prop;
if ((cpts->cc.mult && !cpts->cc.shift) ||
(!cpts->cc.mult && cpts->cc.shift))
goto of_error;
return 0;
of_error:
dev_err(cpts->dev, "CPTS: Missing property in the DT.\n");
return ret;
}
struct cpts *cpts_create(struct device *dev, void __iomem *regs,
struct device_node *node)
{
struct cpts *cpts;
int ret;
cpts = devm_kzalloc(dev, sizeof(*cpts), GFP_KERNEL);
if (!cpts)
return ERR_PTR(-ENOMEM);
cpts->dev = dev;
cpts->reg = (struct cpsw_cpts __iomem *)regs;
spin_lock_init(&cpts->lock);
ret = cpts_of_parse(cpts, node);
if (ret)
return ERR_PTR(ret);
cpts->refclk = devm_clk_get(dev, "cpts");
if (IS_ERR(cpts->refclk)) {
dev_err(dev, "Failed to get cpts refclk\n");
return ERR_PTR(PTR_ERR(cpts->refclk));
}
clk_prepare(cpts->refclk);
cpts->cc.read = cpts_systim_read;
cpts->cc.mask = CLOCKSOURCE_MASK(32);
cpts->info = cpts_info;
cpts_calc_mult_shift(cpts);
cpts->cc_mult = cpts->cc.mult;
return cpts;
}
void cpts_release(struct cpts *cpts)
{
if (!cpts)
return;
if (WARN_ON(!cpts->refclk))
return;
clk_unprepare(cpts->refclk);
}
