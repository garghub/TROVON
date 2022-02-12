static inline int mpipe_instance(struct net_device *dev)
{
struct tile_net_priv *priv = netdev_priv(dev);
return priv->instance;
}
static bool network_cpus_init(void)
{
char buf[1024];
int rc;
if (network_cpus_string == NULL)
return false;
rc = cpulist_parse_crop(network_cpus_string, &network_cpus_map);
if (rc != 0) {
pr_warn("tile_net.cpus=%s: malformed cpu list\n",
network_cpus_string);
return false;
}
cpumask_and(&network_cpus_map, &network_cpus_map, cpu_possible_mask);
if (cpumask_empty(&network_cpus_map)) {
pr_warn("Ignoring empty tile_net.cpus='%s'.\n",
network_cpus_string);
return false;
}
cpulist_scnprintf(buf, sizeof(buf), &network_cpus_map);
pr_info("Linux network CPUs: %s\n", buf);
return true;
}
static void tile_net_stats_add(unsigned long value, unsigned long *field)
{
BUILD_BUG_ON(sizeof(atomic_long_t) != sizeof(unsigned long));
atomic_long_add(value, (atomic_long_t *)field);
}
static bool tile_net_provide_buffer(int instance, int kind)
{
struct mpipe_data *md = &mpipe_data[instance];
gxio_mpipe_buffer_size_enum_t bse = buffer_size_enums[kind];
size_t bs = gxio_mpipe_buffer_size_enum_to_buffer_size(bse);
const unsigned long buffer_alignment = 128;
struct sk_buff *skb;
int len;
len = sizeof(struct sk_buff **) + buffer_alignment + bs;
skb = dev_alloc_skb(len);
if (skb == NULL)
return false;
skb_reserve(skb, sizeof(struct sk_buff **));
skb_reserve(skb, -(long)skb->data & (buffer_alignment - 1));
*(struct sk_buff **)(skb->data - sizeof(struct sk_buff **)) = skb;
wmb();
gxio_mpipe_push_buffer(&md->context, md->first_buffer_stack + kind,
(void *)va_to_tile_io_addr(skb->data));
return true;
}
static struct sk_buff *mpipe_buf_to_skb(void *va)
{
struct sk_buff **skb_ptr = va - sizeof(*skb_ptr);
struct sk_buff *skb = *skb_ptr;
if (skb->data != va) {
panic("Corrupt linux buffer! va=%p, skb=%p, skb->data=%p",
va, skb, skb->data);
}
return skb;
}
static void tile_net_pop_all_buffers(int instance, int stack)
{
struct mpipe_data *md = &mpipe_data[instance];
for (;;) {
tile_io_addr_t addr =
(tile_io_addr_t)gxio_mpipe_pop_buffer(&md->context,
stack);
if (addr == 0)
break;
dev_kfree_skb_irq(mpipe_buf_to_skb(tile_io_addr_to_va(addr)));
}
}
static void tile_net_provide_needed_buffers(void)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
int instance, kind;
for (instance = 0; instance < NR_MPIPE_MAX &&
info->mpipe[instance].has_iqueue; instance++) {
for (kind = 0; kind < MAX_KINDS; kind++) {
while (info->mpipe[instance].num_needed_buffers[kind]
!= 0) {
if (!tile_net_provide_buffer(instance, kind)) {
pr_notice("Tile %d still needs"
" some buffers\n",
info->my_cpu);
return;
}
info->mpipe[instance].
num_needed_buffers[kind]--;
}
}
}
}
static void tile_rx_timestamp(struct tile_net_priv *priv, struct sk_buff *skb,
gxio_mpipe_idesc_t *idesc)
{
if (unlikely(priv->stamp_cfg.rx_filter != HWTSTAMP_FILTER_NONE)) {
struct skb_shared_hwtstamps *shhwtstamps = skb_hwtstamps(skb);
memset(shhwtstamps, 0, sizeof(*shhwtstamps));
shhwtstamps->hwtstamp = ktime_set(idesc->time_stamp_sec,
idesc->time_stamp_ns);
}
}
static void tile_tx_timestamp(struct sk_buff *skb, int instance)
{
struct skb_shared_info *shtx = skb_shinfo(skb);
if (unlikely((shtx->tx_flags & SKBTX_HW_TSTAMP) != 0)) {
struct mpipe_data *md = &mpipe_data[instance];
struct skb_shared_hwtstamps shhwtstamps;
struct timespec ts;
shtx->tx_flags |= SKBTX_IN_PROGRESS;
gxio_mpipe_get_timestamp(&md->context, &ts);
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
shhwtstamps.hwtstamp = ktime_set(ts.tv_sec, ts.tv_nsec);
skb_tstamp_tx(skb, &shhwtstamps);
}
}
static int tile_hwtstamp_set(struct net_device *dev, struct ifreq *rq)
{
struct hwtstamp_config config;
struct tile_net_priv *priv = netdev_priv(dev);
if (copy_from_user(&config, rq->ifr_data, sizeof(config)))
return -EFAULT;
if (config.flags)
return -EINVAL;
switch (config.tx_type) {
case HWTSTAMP_TX_OFF:
case HWTSTAMP_TX_ON:
break;
default:
return -ERANGE;
}
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
break;
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_SOME:
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
config.rx_filter = HWTSTAMP_FILTER_ALL;
break;
default:
return -ERANGE;
}
if (copy_to_user(rq->ifr_data, &config, sizeof(config)))
return -EFAULT;
priv->stamp_cfg = config;
return 0;
}
static int tile_hwtstamp_get(struct net_device *dev, struct ifreq *rq)
{
struct tile_net_priv *priv = netdev_priv(dev);
if (copy_to_user(rq->ifr_data, &priv->stamp_cfg,
sizeof(priv->stamp_cfg)))
return -EFAULT;
return 0;
}
static inline bool filter_packet(struct net_device *dev, void *buf)
{
if (dev == NULL || !(dev->flags & IFF_UP))
return true;
if (!(dev->flags & IFF_PROMISC) &&
!is_multicast_ether_addr(buf) &&
!ether_addr_equal(dev->dev_addr, buf))
return true;
return false;
}
static void tile_net_receive_skb(struct net_device *dev, struct sk_buff *skb,
gxio_mpipe_idesc_t *idesc, unsigned long len)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
struct tile_net_priv *priv = netdev_priv(dev);
int instance = priv->instance;
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, dev);
if (idesc->cs && idesc->csum_seed_val == 0xFFFF)
skb->ip_summed = CHECKSUM_UNNECESSARY;
tile_rx_timestamp(priv, skb, idesc);
napi_gro_receive(&info->mpipe[instance].napi, skb);
tile_net_stats_add(1, &dev->stats.rx_packets);
tile_net_stats_add(len, &dev->stats.rx_bytes);
if (idesc->size == buffer_size_enums[0])
info->mpipe[instance].num_needed_buffers[0]++;
else if (idesc->size == buffer_size_enums[1])
info->mpipe[instance].num_needed_buffers[1]++;
else
info->mpipe[instance].num_needed_buffers[2]++;
}
static bool tile_net_handle_packet(int instance, gxio_mpipe_idesc_t *idesc)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
struct mpipe_data *md = &mpipe_data[instance];
struct net_device *dev = md->tile_net_devs_for_channel[idesc->channel];
uint8_t l2_offset;
void *va;
void *buf;
unsigned long len;
bool filter;
if (idesc->be || idesc->me || idesc->tr || idesc->ce) {
if (dev)
tile_net_stats_add(1, &dev->stats.rx_errors);
goto drop;
}
l2_offset = custom_flag ? 0 : gxio_mpipe_idesc_get_l2_offset(idesc);
va = tile_io_addr_to_va((unsigned long)idesc->va);
buf = va + l2_offset;
len = idesc->l2_size - l2_offset;
va -= NET_IP_ALIGN;
filter = filter_packet(dev, buf);
if (filter) {
if (dev)
tile_net_stats_add(1, &dev->stats.rx_dropped);
drop:
gxio_mpipe_iqueue_drop(&info->mpipe[instance].iqueue, idesc);
} else {
struct sk_buff *skb = mpipe_buf_to_skb(va);
skb_reserve(skb, NET_IP_ALIGN + l2_offset);
tile_net_receive_skb(dev, skb, idesc, len);
}
gxio_mpipe_iqueue_consume(&info->mpipe[instance].iqueue, idesc);
return !filter;
}
static int tile_net_poll(struct napi_struct *napi, int budget)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
unsigned int work = 0;
gxio_mpipe_idesc_t *idesc;
int instance, i, n;
struct mpipe_data *md;
struct info_mpipe *info_mpipe =
container_of(napi, struct info_mpipe, napi);
if (budget <= 0)
goto done;
instance = info_mpipe->instance;
while ((n = gxio_mpipe_iqueue_try_peek(
&info_mpipe->iqueue,
&idesc)) > 0) {
for (i = 0; i < n; i++) {
if (i == TILE_NET_BATCH)
goto done;
if (tile_net_handle_packet(instance,
idesc + i)) {
if (++work >= budget)
goto done;
}
}
}
napi_complete(&info_mpipe->napi);
md = &mpipe_data[instance];
gxio_mpipe_enable_notif_ring_interrupt(
&md->context, info->mpipe[instance].iqueue.ring);
if (gxio_mpipe_iqueue_try_peek(&info_mpipe->iqueue, &idesc) > 0)
napi_schedule(&info_mpipe->napi);
done:
tile_net_provide_needed_buffers();
return work;
}
static irqreturn_t tile_net_handle_ingress_irq(int irq, void *id)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
napi_schedule(&info->mpipe[(uint64_t)id].napi);
return IRQ_HANDLED;
}
static int tile_net_free_comps(gxio_mpipe_equeue_t *equeue,
struct tile_net_comps *comps,
int limit, bool force_update)
{
int n = 0;
while (comps->comp_last < comps->comp_next) {
unsigned int cid = comps->comp_last % TILE_NET_MAX_COMPS;
struct tile_net_comp *comp = &comps->comp_queue[cid];
if (!gxio_mpipe_equeue_is_complete(equeue, comp->when,
force_update || n == 0))
break;
dev_kfree_skb_irq(comp->skb);
comps->comp_last++;
if (++n == limit)
break;
}
return n;
}
static void add_comp(gxio_mpipe_equeue_t *equeue,
struct tile_net_comps *comps,
uint64_t when, struct sk_buff *skb)
{
int cid = comps->comp_next % TILE_NET_MAX_COMPS;
comps->comp_queue[cid].when = when;
comps->comp_queue[cid].skb = skb;
comps->comp_next++;
}
static void tile_net_schedule_tx_wake_timer(struct net_device *dev,
int tx_queue_idx)
{
struct tile_net_info *info = &per_cpu(per_cpu_info, tx_queue_idx);
struct tile_net_priv *priv = netdev_priv(dev);
int instance = priv->instance;
struct tile_net_tx_wake *tx_wake =
&info->mpipe[instance].tx_wake[priv->echannel];
hrtimer_start(&tx_wake->timer,
ktime_set(0, TX_TIMER_DELAY_USEC * 1000UL),
HRTIMER_MODE_REL_PINNED);
}
static enum hrtimer_restart tile_net_handle_tx_wake_timer(struct hrtimer *t)
{
struct tile_net_tx_wake *tx_wake =
container_of(t, struct tile_net_tx_wake, timer);
netif_wake_subqueue(tx_wake->dev, tx_wake->tx_queue_idx);
return HRTIMER_NORESTART;
}
static void tile_net_schedule_egress_timer(void)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
if (!info->egress_timer_scheduled) {
hrtimer_start(&info->egress_timer,
ktime_set(0, EGRESS_TIMER_DELAY_USEC * 1000UL),
HRTIMER_MODE_REL_PINNED);
info->egress_timer_scheduled = true;
}
}
static enum hrtimer_restart tile_net_handle_egress_timer(struct hrtimer *t)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
unsigned long irqflags;
bool pending = false;
int i, instance;
local_irq_save(irqflags);
info->egress_timer_scheduled = false;
for (instance = 0; instance < NR_MPIPE_MAX &&
info->mpipe[instance].has_iqueue; instance++) {
for (i = 0; i < TILE_NET_CHANNELS; i++) {
struct tile_net_egress *egress =
&mpipe_data[instance].egress_for_echannel[i];
struct tile_net_comps *comps =
info->mpipe[instance].comps_for_echannel[i];
if (!egress || comps->comp_last >= comps->comp_next)
continue;
tile_net_free_comps(egress->equeue, comps, -1, true);
pending = pending ||
(comps->comp_last < comps->comp_next);
}
}
if (pending)
tile_net_schedule_egress_timer();
local_irq_restore(irqflags);
return HRTIMER_NORESTART;
}
static int ptp_mpipe_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
int ret = 0;
struct mpipe_data *md = container_of(ptp, struct mpipe_data, caps);
mutex_lock(&md->ptp_lock);
if (gxio_mpipe_adjust_timestamp_freq(&md->context, ppb))
ret = -EINVAL;
mutex_unlock(&md->ptp_lock);
return ret;
}
static int ptp_mpipe_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
int ret = 0;
struct mpipe_data *md = container_of(ptp, struct mpipe_data, caps);
mutex_lock(&md->ptp_lock);
if (gxio_mpipe_adjust_timestamp(&md->context, delta))
ret = -EBUSY;
mutex_unlock(&md->ptp_lock);
return ret;
}
static int ptp_mpipe_gettime(struct ptp_clock_info *ptp, struct timespec *ts)
{
int ret = 0;
struct mpipe_data *md = container_of(ptp, struct mpipe_data, caps);
mutex_lock(&md->ptp_lock);
if (gxio_mpipe_get_timestamp(&md->context, ts))
ret = -EBUSY;
mutex_unlock(&md->ptp_lock);
return ret;
}
static int ptp_mpipe_settime(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
int ret = 0;
struct mpipe_data *md = container_of(ptp, struct mpipe_data, caps);
mutex_lock(&md->ptp_lock);
if (gxio_mpipe_set_timestamp(&md->context, ts))
ret = -EBUSY;
mutex_unlock(&md->ptp_lock);
return ret;
}
static int ptp_mpipe_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *request, int on)
{
return -EOPNOTSUPP;
}
static void register_ptp_clock(struct net_device *dev, struct mpipe_data *md)
{
struct timespec ts;
getnstimeofday(&ts);
gxio_mpipe_set_timestamp(&md->context, &ts);
mutex_init(&md->ptp_lock);
md->caps = ptp_mpipe_caps;
md->ptp_clock = ptp_clock_register(&md->caps, NULL);
if (IS_ERR(md->ptp_clock))
netdev_err(dev, "ptp_clock_register failed %ld\n",
PTR_ERR(md->ptp_clock));
}
static void init_ptp_dev(struct tile_net_priv *priv)
{
priv->stamp_cfg.rx_filter = HWTSTAMP_FILTER_NONE;
priv->stamp_cfg.tx_type = HWTSTAMP_TX_OFF;
}
static void enable_ingress_irq(void *irq)
{
enable_percpu_irq((long)irq, 0);
}
static void disable_ingress_irq(void *irq)
{
disable_percpu_irq((long)irq);
}
static int tile_net_update(struct net_device *dev)
{
static gxio_mpipe_rules_t rules;
bool saw_channel = false;
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
int channel;
int rc;
int cpu;
saw_channel = false;
gxio_mpipe_rules_init(&rules, &md->context);
for (channel = 0; channel < TILE_NET_CHANNELS; channel++) {
if (md->tile_net_devs_for_channel[channel] == NULL)
continue;
if (!saw_channel) {
saw_channel = true;
gxio_mpipe_rules_begin(&rules, md->first_bucket,
md->num_buckets, NULL);
gxio_mpipe_rules_set_headroom(&rules, NET_IP_ALIGN);
}
gxio_mpipe_rules_add_channel(&rules, channel);
}
rc = gxio_mpipe_rules_commit(&rules);
if (rc != 0) {
netdev_warn(dev, "gxio_mpipe_rules_commit: mpipe[%d] %d\n",
instance, rc);
return -EIO;
}
if (!saw_channel)
on_each_cpu(disable_ingress_irq,
(void *)(long)(md->ingress_irq), 1);
for_each_online_cpu(cpu) {
struct tile_net_info *info = &per_cpu(per_cpu_info, cpu);
if (!info->mpipe[instance].has_iqueue)
continue;
if (saw_channel) {
if (!info->mpipe[instance].napi_added) {
netif_napi_add(dev, &info->mpipe[instance].napi,
tile_net_poll, TILE_NET_WEIGHT);
info->mpipe[instance].napi_added = true;
}
if (!info->mpipe[instance].napi_enabled) {
napi_enable(&info->mpipe[instance].napi);
info->mpipe[instance].napi_enabled = true;
}
} else {
if (info->mpipe[instance].napi_enabled) {
napi_disable(&info->mpipe[instance].napi);
info->mpipe[instance].napi_enabled = false;
}
}
}
if (saw_channel)
on_each_cpu(enable_ingress_irq,
(void *)(long)(md->ingress_irq), 1);
if (saw_channel)
sim_enable_mpipe_links(instance, -1);
return 0;
}
static int create_buffer_stack(struct net_device *dev,
int kind, size_t num_buffers)
{
pte_t hash_pte = pte_set_home((pte_t) { 0 }, PAGE_HOME_HASH);
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
size_t needed = gxio_mpipe_calc_buffer_stack_bytes(num_buffers);
int stack_idx = md->first_buffer_stack + kind;
void *va;
int i, rc;
md->buffer_stack_bytes[kind] =
ALIGN(needed, 64 * 1024);
va = alloc_pages_exact(md->buffer_stack_bytes[kind], GFP_KERNEL);
if (va == NULL) {
netdev_err(dev,
"Could not alloc %zd bytes for buffer stack %d\n",
md->buffer_stack_bytes[kind], kind);
return -ENOMEM;
}
rc = gxio_mpipe_init_buffer_stack(&md->context, stack_idx,
buffer_size_enums[kind], va,
md->buffer_stack_bytes[kind], 0);
if (rc != 0) {
netdev_err(dev, "gxio_mpipe_init_buffer_stack: mpipe[%d] %d\n",
instance, rc);
free_pages_exact(va, md->buffer_stack_bytes[kind]);
return rc;
}
md->buffer_stack_vas[kind] = va;
rc = gxio_mpipe_register_client_memory(&md->context, stack_idx,
hash_pte, 0);
if (rc != 0) {
netdev_err(dev,
"gxio_mpipe_register_client_memory: mpipe[%d] %d\n",
instance, rc);
return rc;
}
for (i = 0; i < num_buffers; i++) {
if (!tile_net_provide_buffer(instance, kind)) {
netdev_err(dev, "Cannot allocate initial sk_bufs!\n");
return -ENOMEM;
}
}
return 0;
}
static int init_buffer_stacks(struct net_device *dev,
int network_cpus_count)
{
int num_kinds = MAX_KINDS - (jumbo_num == 0);
size_t num_buffers;
int rc;
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
rc = gxio_mpipe_alloc_buffer_stacks(&md->context, num_kinds, 0, 0);
if (rc < 0) {
netdev_err(dev,
"gxio_mpipe_alloc_buffer_stacks: mpipe[%d] %d\n",
instance, rc);
return rc;
}
md->first_buffer_stack = rc;
num_buffers =
network_cpus_count * (IQUEUE_ENTRIES + TILE_NET_BATCH);
if (rc >= 0)
rc = create_buffer_stack(dev, 0, num_buffers);
if (rc >= 0)
rc = create_buffer_stack(dev, 1, num_buffers);
if (rc >= 0 && jumbo_num != 0)
rc = create_buffer_stack(dev, 2, jumbo_num);
return rc;
}
static int alloc_percpu_mpipe_resources(struct net_device *dev,
int cpu, int ring)
{
struct tile_net_info *info = &per_cpu(per_cpu_info, cpu);
int order, i, rc;
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
struct page *page;
void *addr;
order = get_order(COMPS_SIZE);
page = homecache_alloc_pages(GFP_KERNEL, order, cpu);
if (page == NULL) {
netdev_err(dev, "Failed to alloc %zd bytes comps memory\n",
COMPS_SIZE);
return -ENOMEM;
}
addr = pfn_to_kaddr(page_to_pfn(page));
memset(addr, 0, COMPS_SIZE);
for (i = 0; i < TILE_NET_CHANNELS; i++)
info->mpipe[instance].comps_for_echannel[i] =
addr + i * sizeof(struct tile_net_comps);
if (cpu_isset(cpu, network_cpus_map)) {
order = get_order(NOTIF_RING_SIZE);
page = homecache_alloc_pages(GFP_KERNEL, order, cpu);
if (page == NULL) {
netdev_err(dev,
"Failed to alloc %zd bytes iqueue memory\n",
NOTIF_RING_SIZE);
return -ENOMEM;
}
addr = pfn_to_kaddr(page_to_pfn(page));
rc = gxio_mpipe_iqueue_init(&info->mpipe[instance].iqueue,
&md->context, ring++, addr,
NOTIF_RING_SIZE, 0);
if (rc < 0) {
netdev_err(dev,
"gxio_mpipe_iqueue_init failed: %d\n", rc);
return rc;
}
info->mpipe[instance].has_iqueue = true;
}
return ring;
}
static int init_notif_group_and_buckets(struct net_device *dev,
int ring, int network_cpus_count)
{
int group, rc;
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
rc = gxio_mpipe_alloc_notif_groups(&md->context, 1, 0, 0);
if (rc < 0) {
netdev_err(dev, "gxio_mpipe_alloc_notif_groups: mpipe[%d] %d\n",
instance, rc);
return rc;
}
group = rc;
if (network_cpus_count > 4)
md->num_buckets = 256;
else if (network_cpus_count > 1)
md->num_buckets = 16;
rc = gxio_mpipe_alloc_buckets(&md->context, md->num_buckets, 0, 0);
if (rc < 0) {
netdev_err(dev, "gxio_mpipe_alloc_buckets: mpipe[%d] %d\n",
instance, rc);
return rc;
}
md->first_bucket = rc;
rc = gxio_mpipe_init_notif_group_and_buckets(
&md->context, group, ring, network_cpus_count,
md->first_bucket, md->num_buckets,
GXIO_MPIPE_BUCKET_STICKY_FLOW_LOCALITY);
if (rc != 0) {
netdev_err(dev, "gxio_mpipe_init_notif_group_and_buckets: "
"mpipe[%d] %d\n", instance, rc);
return rc;
}
return 0;
}
static int tile_net_setup_interrupts(struct net_device *dev)
{
int cpu, rc, irq;
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
irq = md->ingress_irq;
if (irq < 0) {
irq = irq_alloc_hwirq(-1);
if (!irq) {
netdev_err(dev,
"create_irq failed: mpipe[%d] %d\n",
instance, irq);
return irq;
}
tile_irq_activate(irq, TILE_IRQ_PERCPU);
rc = request_irq(irq, tile_net_handle_ingress_irq,
0, "tile_net", (void *)((uint64_t)instance));
if (rc != 0) {
netdev_err(dev, "request_irq failed: mpipe[%d] %d\n",
instance, rc);
irq_free_hwirq(irq);
return rc;
}
md->ingress_irq = irq;
}
for_each_online_cpu(cpu) {
struct tile_net_info *info = &per_cpu(per_cpu_info, cpu);
if (info->mpipe[instance].has_iqueue) {
gxio_mpipe_request_notif_ring_interrupt(&md->context,
cpu_x(cpu), cpu_y(cpu), KERNEL_PL, irq,
info->mpipe[instance].iqueue.ring);
}
}
return 0;
}
static void tile_net_init_mpipe_fail(int instance)
{
int kind, cpu;
struct mpipe_data *md = &mpipe_data[instance];
for (kind = 0; kind < MAX_KINDS; kind++) {
if (md->buffer_stack_vas[kind] != NULL) {
tile_net_pop_all_buffers(instance,
md->first_buffer_stack +
kind);
}
}
gxio_mpipe_destroy(&md->context);
for_each_online_cpu(cpu) {
struct tile_net_info *info = &per_cpu(per_cpu_info, cpu);
free_pages(
(unsigned long)(
info->mpipe[instance].comps_for_echannel[0]),
get_order(COMPS_SIZE));
info->mpipe[instance].comps_for_echannel[0] = NULL;
free_pages((unsigned long)(info->mpipe[instance].iqueue.idescs),
get_order(NOTIF_RING_SIZE));
info->mpipe[instance].iqueue.idescs = NULL;
}
for (kind = 0; kind < MAX_KINDS; kind++) {
if (md->buffer_stack_vas[kind] != NULL) {
free_pages_exact(md->buffer_stack_vas[kind],
md->buffer_stack_bytes[kind]);
md->buffer_stack_vas[kind] = NULL;
}
}
md->first_buffer_stack = -1;
md->first_bucket = -1;
}
static int tile_net_init_mpipe(struct net_device *dev)
{
int rc;
int cpu;
int first_ring, ring;
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
int network_cpus_count = cpus_weight(network_cpus_map);
if (!hash_default) {
netdev_err(dev, "Networking requires hash_default!\n");
return -EIO;
}
rc = gxio_mpipe_init(&md->context, instance);
if (rc != 0) {
netdev_err(dev, "gxio_mpipe_init: mpipe[%d] %d\n",
instance, rc);
return -EIO;
}
rc = init_buffer_stacks(dev, network_cpus_count);
if (rc != 0)
goto fail;
rc = gxio_mpipe_alloc_notif_rings(&md->context,
network_cpus_count, 0, 0);
if (rc < 0) {
netdev_err(dev, "gxio_mpipe_alloc_notif_rings failed %d\n",
rc);
goto fail;
}
first_ring = rc;
ring = first_ring;
for_each_online_cpu(cpu) {
rc = alloc_percpu_mpipe_resources(dev, cpu, ring);
if (rc < 0)
goto fail;
ring = rc;
}
rc = init_notif_group_and_buckets(dev, first_ring, network_cpus_count);
if (rc != 0)
goto fail;
rc = tile_net_setup_interrupts(dev);
if (rc != 0)
goto fail;
register_ptp_clock(dev, md);
return 0;
fail:
tile_net_init_mpipe_fail(instance);
return rc;
}
static int tile_net_init_egress(struct net_device *dev, int echannel)
{
static int ering = -1;
struct page *headers_page, *edescs_page, *equeue_page;
gxio_mpipe_edesc_t *edescs;
gxio_mpipe_equeue_t *equeue;
unsigned char *headers;
int headers_order, edescs_order, equeue_order;
size_t edescs_size;
int rc = -ENOMEM;
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
if (md->egress_for_echannel[echannel].equeue != NULL)
return 0;
headers_order = get_order(EQUEUE_ENTRIES * HEADER_BYTES);
headers_page = alloc_pages(GFP_KERNEL, headers_order);
if (headers_page == NULL) {
netdev_warn(dev,
"Could not alloc %zd bytes for TSO headers.\n",
PAGE_SIZE << headers_order);
goto fail;
}
headers = pfn_to_kaddr(page_to_pfn(headers_page));
edescs_size = EQUEUE_ENTRIES * sizeof(*edescs);
edescs_order = get_order(edescs_size);
edescs_page = alloc_pages(GFP_KERNEL, edescs_order);
if (edescs_page == NULL) {
netdev_warn(dev,
"Could not alloc %zd bytes for eDMA ring.\n",
edescs_size);
goto fail_headers;
}
edescs = pfn_to_kaddr(page_to_pfn(edescs_page));
equeue_order = get_order(sizeof(*equeue));
equeue_page = alloc_pages(GFP_KERNEL, equeue_order);
if (equeue_page == NULL) {
netdev_warn(dev,
"Could not alloc %zd bytes for equeue info.\n",
PAGE_SIZE << equeue_order);
goto fail_edescs;
}
equeue = pfn_to_kaddr(page_to_pfn(equeue_page));
if (ering < 0) {
rc = gxio_mpipe_alloc_edma_rings(&md->context, 1, 0, 0);
if (rc < 0) {
netdev_warn(dev, "gxio_mpipe_alloc_edma_rings: "
"mpipe[%d] %d\n", instance, rc);
goto fail_equeue;
}
ering = rc;
}
rc = gxio_mpipe_equeue_init(equeue, &md->context, ering, echannel,
edescs, edescs_size, 0);
if (rc != 0) {
netdev_err(dev, "gxio_mpipe_equeue_init: mpipe[%d] %d\n",
instance, rc);
goto fail_equeue;
}
ering = -1;
if (jumbo_num != 0) {
if (gxio_mpipe_equeue_set_snf_size(equeue, 10368) < 0) {
netdev_warn(dev, "Jumbo packets may not be egressed"
" properly on channel %d\n", echannel);
}
}
md->egress_for_echannel[echannel].equeue = equeue;
md->egress_for_echannel[echannel].headers = headers;
return 0;
fail_equeue:
__free_pages(equeue_page, equeue_order);
fail_edescs:
__free_pages(edescs_page, edescs_order);
fail_headers:
__free_pages(headers_page, headers_order);
fail:
return rc;
}
static int tile_net_link_open(struct net_device *dev, gxio_mpipe_link_t *link,
const char *link_name)
{
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
int rc = gxio_mpipe_link_open(link, &md->context, link_name, 0);
if (rc < 0) {
netdev_err(dev, "Failed to open '%s', mpipe[%d], %d\n",
link_name, instance, rc);
return rc;
}
if (jumbo_num != 0) {
u32 attr = GXIO_MPIPE_LINK_RECEIVE_JUMBO;
rc = gxio_mpipe_link_set_attr(link, attr, 1);
if (rc != 0) {
netdev_err(dev,
"Cannot receive jumbo packets on '%s'\n",
link_name);
gxio_mpipe_link_close(link);
return rc;
}
}
rc = gxio_mpipe_link_channel(link);
if (rc < 0 || rc >= TILE_NET_CHANNELS) {
netdev_err(dev, "gxio_mpipe_link_channel bad value: %d\n", rc);
gxio_mpipe_link_close(link);
return -EINVAL;
}
return rc;
}
static int tile_net_open(struct net_device *dev)
{
struct tile_net_priv *priv = netdev_priv(dev);
int cpu, rc, instance;
mutex_lock(&tile_net_devs_for_channel_mutex);
rc = gxio_mpipe_link_instance(dev->name);
if (rc < 0 || rc >= NR_MPIPE_MAX) {
mutex_unlock(&tile_net_devs_for_channel_mutex);
return -EIO;
}
priv->instance = rc;
instance = rc;
if (!mpipe_data[rc].context.mmio_fast_base) {
rc = tile_net_init_mpipe(dev);
if (rc != 0)
goto fail;
}
if (unlikely((loopify_link_name != NULL) &&
!strcmp(dev->name, loopify_link_name))) {
rc = tile_net_link_open(dev, &priv->link, "loop0");
if (rc < 0)
goto fail;
priv->channel = rc;
rc = tile_net_link_open(dev, &priv->loopify_link, "loop1");
if (rc < 0)
goto fail;
priv->loopify_channel = rc;
priv->echannel = rc;
} else {
rc = tile_net_link_open(dev, &priv->link, dev->name);
if (rc < 0)
goto fail;
priv->channel = rc;
priv->echannel = rc;
}
rc = tile_net_init_egress(dev, priv->echannel);
if (rc != 0)
goto fail;
mpipe_data[instance].tile_net_devs_for_channel[priv->channel] = dev;
rc = tile_net_update(dev);
if (rc != 0)
goto fail;
mutex_unlock(&tile_net_devs_for_channel_mutex);
for_each_online_cpu(cpu) {
struct tile_net_info *info = &per_cpu(per_cpu_info, cpu);
struct tile_net_tx_wake *tx_wake =
&info->mpipe[instance].tx_wake[priv->echannel];
hrtimer_init(&tx_wake->timer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
tx_wake->tx_queue_idx = cpu;
tx_wake->timer.function = tile_net_handle_tx_wake_timer;
tx_wake->dev = dev;
}
for_each_online_cpu(cpu)
netif_start_subqueue(dev, cpu);
netif_carrier_on(dev);
return 0;
fail:
if (priv->loopify_channel >= 0) {
if (gxio_mpipe_link_close(&priv->loopify_link) != 0)
netdev_warn(dev, "Failed to close loopify link!\n");
priv->loopify_channel = -1;
}
if (priv->channel >= 0) {
if (gxio_mpipe_link_close(&priv->link) != 0)
netdev_warn(dev, "Failed to close link!\n");
priv->channel = -1;
}
priv->echannel = -1;
mpipe_data[instance].tile_net_devs_for_channel[priv->channel] = NULL;
mutex_unlock(&tile_net_devs_for_channel_mutex);
return (rc > -512) ? rc : -EIO;
}
static int tile_net_stop(struct net_device *dev)
{
struct tile_net_priv *priv = netdev_priv(dev);
int cpu;
int instance = priv->instance;
struct mpipe_data *md = &mpipe_data[instance];
for_each_online_cpu(cpu) {
struct tile_net_info *info = &per_cpu(per_cpu_info, cpu);
struct tile_net_tx_wake *tx_wake =
&info->mpipe[instance].tx_wake[priv->echannel];
hrtimer_cancel(&tx_wake->timer);
netif_stop_subqueue(dev, cpu);
}
mutex_lock(&tile_net_devs_for_channel_mutex);
md->tile_net_devs_for_channel[priv->channel] = NULL;
(void)tile_net_update(dev);
if (priv->loopify_channel >= 0) {
if (gxio_mpipe_link_close(&priv->loopify_link) != 0)
netdev_warn(dev, "Failed to close loopify link!\n");
priv->loopify_channel = -1;
}
if (priv->channel >= 0) {
if (gxio_mpipe_link_close(&priv->link) != 0)
netdev_warn(dev, "Failed to close link!\n");
priv->channel = -1;
}
priv->echannel = -1;
mutex_unlock(&tile_net_devs_for_channel_mutex);
return 0;
}
static inline void *tile_net_frag_buf(skb_frag_t *f)
{
unsigned long pfn = page_to_pfn(skb_frag_page(f));
return pfn_to_kaddr(pfn) + f->page_offset;
}
static s64 tile_net_equeue_try_reserve(struct net_device *dev,
int tx_queue_idx,
struct tile_net_comps *comps,
gxio_mpipe_equeue_t *equeue,
int num_edescs)
{
if (comps->comp_next - comps->comp_last < TILE_NET_MAX_COMPS - 1 ||
tile_net_free_comps(equeue, comps, 32, false) != 0) {
s64 slot = gxio_mpipe_equeue_try_reserve(equeue, num_edescs);
if (slot >= 0)
return slot;
tile_net_free_comps(equeue, comps, TILE_NET_MAX_COMPS, false);
slot = gxio_mpipe_equeue_try_reserve(equeue, num_edescs);
if (slot >= 0)
return slot;
}
netif_stop_subqueue(dev, tx_queue_idx);
tile_net_schedule_tx_wake_timer(dev, tx_queue_idx);
return -1;
}
static int tso_count_edescs(struct sk_buff *skb)
{
struct skb_shared_info *sh = skb_shinfo(skb);
unsigned int sh_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
unsigned int data_len = skb->len - sh_len;
unsigned int p_len = sh->gso_size;
long f_id = -1;
long f_size = skb_headlen(skb) - sh_len;
long f_used = 0;
long n;
int num_edescs = 0;
int segment;
for (segment = 0; segment < sh->gso_segs; segment++) {
unsigned int p_used = 0;
for (num_edescs++; p_used < p_len; num_edescs++) {
while (f_used >= f_size) {
f_id++;
f_size = skb_frag_size(&sh->frags[f_id]);
f_used = 0;
}
n = p_len - p_used;
if (n > f_size - f_used)
n = f_size - f_used;
f_used += n;
p_used += n;
}
data_len -= p_len;
if (data_len < p_len)
p_len = data_len;
}
return num_edescs;
}
static void tso_headers_prepare(struct sk_buff *skb, unsigned char *headers,
s64 slot)
{
struct skb_shared_info *sh = skb_shinfo(skb);
struct iphdr *ih;
struct ipv6hdr *ih6;
struct tcphdr *th;
unsigned int sh_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
unsigned int data_len = skb->len - sh_len;
unsigned char *data = skb->data;
unsigned int ih_off, th_off, p_len;
unsigned int isum_seed, tsum_seed, seq;
unsigned int uninitialized_var(id);
int is_ipv6;
long f_id = -1;
long f_size = skb_headlen(skb) - sh_len;
long f_used = 0;
long n;
int segment;
is_ipv6 = skb_is_gso_v6(skb);
if (is_ipv6) {
ih6 = ipv6_hdr(skb);
ih_off = skb_network_offset(skb);
} else {
ih = ip_hdr(skb);
ih_off = skb_network_offset(skb);
isum_seed = ((0xFFFF - ih->check) +
(0xFFFF - ih->tot_len) +
(0xFFFF - ih->id));
id = ntohs(ih->id);
}
th = tcp_hdr(skb);
th_off = skb_transport_offset(skb);
p_len = sh->gso_size;
tsum_seed = th->check + (0xFFFF ^ htons(skb->len));
seq = ntohl(th->seq);
for (segment = 0; segment < sh->gso_segs; segment++) {
unsigned char *buf;
unsigned int p_used = 0;
buf = headers + (slot % EQUEUE_ENTRIES) * HEADER_BYTES +
NET_IP_ALIGN;
memcpy(buf, data, sh_len);
if (is_ipv6) {
ih6 = (struct ipv6hdr *)(buf + ih_off);
ih6->payload_len = htons(sh_len + p_len - ih_off -
sizeof(*ih6));
} else {
ih = (struct iphdr *)(buf + ih_off);
ih->tot_len = htons(sh_len + p_len - ih_off);
ih->id = htons(id++);
ih->check = csum_long(isum_seed + ih->tot_len +
ih->id) ^ 0xffff;
}
th = (struct tcphdr *)(buf + th_off);
th->seq = htonl(seq);
th->check = csum_long(tsum_seed + htons(sh_len + p_len));
if (segment != sh->gso_segs - 1) {
th->fin = 0;
th->psh = 0;
}
slot++;
while (p_used < p_len) {
while (f_used >= f_size) {
f_id++;
f_size = skb_frag_size(&sh->frags[f_id]);
f_used = 0;
}
n = p_len - p_used;
if (n > f_size - f_used)
n = f_size - f_used;
f_used += n;
p_used += n;
slot++;
}
seq += p_len;
data_len -= p_len;
if (data_len < p_len)
p_len = data_len;
}
wmb();
}
static void tso_egress(struct net_device *dev, gxio_mpipe_equeue_t *equeue,
struct sk_buff *skb, unsigned char *headers, s64 slot)
{
struct skb_shared_info *sh = skb_shinfo(skb);
int instance = mpipe_instance(dev);
struct mpipe_data *md = &mpipe_data[instance];
unsigned int sh_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
unsigned int data_len = skb->len - sh_len;
unsigned int p_len = sh->gso_size;
gxio_mpipe_edesc_t edesc_head = { { 0 } };
gxio_mpipe_edesc_t edesc_body = { { 0 } };
long f_id = -1;
long f_size = skb_headlen(skb) - sh_len;
long f_used = 0;
void *f_data = skb->data + sh_len;
long n;
unsigned long tx_packets = 0, tx_bytes = 0;
unsigned int csum_start;
int segment;
csum_start = skb_checksum_start_offset(skb);
edesc_head.csum = 1;
edesc_head.csum_start = csum_start;
edesc_head.csum_dest = csum_start + skb->csum_offset;
edesc_head.xfer_size = sh_len;
edesc_head.stack_idx = md->first_buffer_stack;
edesc_body.stack_idx = md->first_buffer_stack;
for (segment = 0; segment < sh->gso_segs; segment++) {
unsigned char *buf;
unsigned int p_used = 0;
buf = headers + (slot % EQUEUE_ENTRIES) * HEADER_BYTES +
NET_IP_ALIGN;
edesc_head.va = va_to_tile_io_addr(buf);
gxio_mpipe_equeue_put_at(equeue, edesc_head, slot);
slot++;
while (p_used < p_len) {
void *va;
while (f_used >= f_size) {
f_id++;
f_size = skb_frag_size(&sh->frags[f_id]);
f_data = tile_net_frag_buf(&sh->frags[f_id]);
f_used = 0;
}
va = f_data + f_used;
n = p_len - p_used;
if (n > f_size - f_used)
n = f_size - f_used;
f_used += n;
p_used += n;
edesc_body.va = va_to_tile_io_addr(va);
edesc_body.xfer_size = n;
edesc_body.bound = !(p_used < p_len);
gxio_mpipe_equeue_put_at(equeue, edesc_body, slot);
slot++;
}
tx_packets++;
tx_bytes += sh_len + p_len;
data_len -= p_len;
if (data_len < p_len)
p_len = data_len;
}
tile_net_stats_add(tx_packets, &dev->stats.tx_packets);
tile_net_stats_add(tx_bytes, &dev->stats.tx_bytes);
}
static int tile_net_tx_tso(struct sk_buff *skb, struct net_device *dev)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
struct tile_net_priv *priv = netdev_priv(dev);
int channel = priv->echannel;
int instance = priv->instance;
struct mpipe_data *md = &mpipe_data[instance];
struct tile_net_egress *egress = &md->egress_for_echannel[channel];
struct tile_net_comps *comps =
info->mpipe[instance].comps_for_echannel[channel];
gxio_mpipe_equeue_t *equeue = egress->equeue;
unsigned long irqflags;
int num_edescs;
s64 slot;
num_edescs = tso_count_edescs(skb);
local_irq_save(irqflags);
slot = tile_net_equeue_try_reserve(dev, skb->queue_mapping, comps,
equeue, num_edescs);
if (slot < 0) {
local_irq_restore(irqflags);
return NETDEV_TX_BUSY;
}
tso_headers_prepare(skb, egress->headers, slot);
tso_egress(dev, equeue, skb, egress->headers, slot);
add_comp(equeue, comps, slot + num_edescs - 1, skb);
local_irq_restore(irqflags);
tile_net_schedule_egress_timer();
return NETDEV_TX_OK;
}
static unsigned int tile_net_tx_frags(struct frag *frags,
struct sk_buff *skb,
void *b_data, unsigned int b_len)
{
unsigned int i, n = 0;
struct skb_shared_info *sh = skb_shinfo(skb);
if (b_len != 0) {
frags[n].buf = b_data;
frags[n++].length = b_len;
}
for (i = 0; i < sh->nr_frags; i++) {
skb_frag_t *f = &sh->frags[i];
frags[n].buf = tile_net_frag_buf(f);
frags[n++].length = skb_frag_size(f);
}
return n;
}
static int tile_net_tx(struct sk_buff *skb, struct net_device *dev)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
struct tile_net_priv *priv = netdev_priv(dev);
int instance = priv->instance;
struct mpipe_data *md = &mpipe_data[instance];
struct tile_net_egress *egress =
&md->egress_for_echannel[priv->echannel];
gxio_mpipe_equeue_t *equeue = egress->equeue;
struct tile_net_comps *comps =
info->mpipe[instance].comps_for_echannel[priv->echannel];
unsigned int len = skb->len;
unsigned char *data = skb->data;
unsigned int num_edescs;
struct frag frags[MAX_FRAGS];
gxio_mpipe_edesc_t edescs[MAX_FRAGS];
unsigned long irqflags;
gxio_mpipe_edesc_t edesc = { { 0 } };
unsigned int i;
s64 slot;
if (skb_is_gso(skb))
return tile_net_tx_tso(skb, dev);
num_edescs = tile_net_tx_frags(frags, skb, data, skb_headlen(skb));
edesc.stack_idx = md->first_buffer_stack;
for (i = 0; i < num_edescs; i++) {
edesc.xfer_size = frags[i].length;
edesc.va = va_to_tile_io_addr(frags[i].buf);
edescs[i] = edesc;
}
edescs[num_edescs - 1].bound = 1;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
unsigned int csum_start = skb_checksum_start_offset(skb);
edescs[0].csum = 1;
edescs[0].csum_start = csum_start;
edescs[0].csum_dest = csum_start + skb->csum_offset;
}
local_irq_save(irqflags);
slot = tile_net_equeue_try_reserve(dev, skb->queue_mapping, comps,
equeue, num_edescs);
if (slot < 0) {
local_irq_restore(irqflags);
return NETDEV_TX_BUSY;
}
for (i = 0; i < num_edescs; i++)
gxio_mpipe_equeue_put_at(equeue, edescs[i], slot++);
tile_tx_timestamp(skb, instance);
add_comp(equeue, comps, slot - 1, skb);
tile_net_stats_add(1, &dev->stats.tx_packets);
tile_net_stats_add(max_t(unsigned int, len, ETH_ZLEN),
&dev->stats.tx_bytes);
local_irq_restore(irqflags);
tile_net_schedule_egress_timer();
return NETDEV_TX_OK;
}
static u16 tile_net_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
return smp_processor_id();
}
static void tile_net_tx_timeout(struct net_device *dev)
{
int cpu;
for_each_online_cpu(cpu)
netif_wake_subqueue(dev, cpu);
}
static int tile_net_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
if (cmd == SIOCSHWTSTAMP)
return tile_hwtstamp_set(dev, rq);
if (cmd == SIOCGHWTSTAMP)
return tile_hwtstamp_get(dev, rq);
return -EOPNOTSUPP;
}
static int tile_net_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < 68)
return -EINVAL;
if (new_mtu > ((jumbo_num != 0) ? 9000 : 1500))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static int tile_net_set_mac_address(struct net_device *dev, void *p)
{
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EINVAL;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
return 0;
}
static void tile_net_netpoll(struct net_device *dev)
{
int instance = mpipe_instance(dev);
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
struct mpipe_data *md = &mpipe_data[instance];
disable_percpu_irq(md->ingress_irq);
napi_schedule(&info->mpipe[instance].napi);
enable_percpu_irq(md->ingress_irq, 0);
}
static void tile_net_setup(struct net_device *dev)
{
netdev_features_t features = 0;
ether_setup(dev);
dev->netdev_ops = &tile_net_ops;
dev->watchdog_timeo = TILE_NET_TIMEOUT;
dev->mtu = 1500;
features |= NETIF_F_HW_CSUM;
features |= NETIF_F_SG;
features |= NETIF_F_TSO;
features |= NETIF_F_TSO6;
dev->hw_features |= features;
dev->vlan_features |= features;
dev->features |= features;
}
static void tile_net_dev_init(const char *name, const uint8_t *mac)
{
int ret;
struct net_device *dev;
struct tile_net_priv *priv;
if (strncmp(name, "loop", 4) == 0)
return;
dev = alloc_netdev_mqs(sizeof(*priv), name, NET_NAME_UNKNOWN,
tile_net_setup, NR_CPUS, 1);
if (!dev) {
pr_err("alloc_netdev_mqs(%s) failed\n", name);
return;
}
priv = netdev_priv(dev);
priv->dev = dev;
priv->channel = -1;
priv->loopify_channel = -1;
priv->echannel = -1;
init_ptp_dev(priv);
if (!is_zero_ether_addr(mac))
ether_addr_copy(dev->dev_addr, mac);
else
eth_hw_addr_random(dev);
ret = register_netdev(dev);
if (ret) {
netdev_err(dev, "register_netdev failed %d\n", ret);
free_netdev(dev);
return;
}
}
static void tile_net_init_module_percpu(void *unused)
{
struct tile_net_info *info = this_cpu_ptr(&per_cpu_info);
int my_cpu = smp_processor_id();
int instance;
for (instance = 0; instance < NR_MPIPE_MAX; instance++) {
info->mpipe[instance].has_iqueue = false;
info->mpipe[instance].instance = instance;
}
info->my_cpu = my_cpu;
hrtimer_init(&info->egress_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
info->egress_timer.function = tile_net_handle_egress_timer;
}
static int __init tile_net_init_module(void)
{
int i;
char name[GXIO_MPIPE_LINK_NAME_LEN];
uint8_t mac[6];
pr_info("Tilera Network Driver\n");
BUILD_BUG_ON(NR_MPIPE_MAX != 2);
mutex_init(&tile_net_devs_for_channel_mutex);
on_each_cpu(tile_net_init_module_percpu, NULL, 1);
for (i = 0; gxio_mpipe_link_enumerate_mac(i, name, mac) >= 0; i++)
tile_net_dev_init(name, mac);
if (!network_cpus_init())
network_cpus_map = *cpu_online_mask;
return 0;
}
