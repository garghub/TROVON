static irqreturn_t cvm_oct_do_interrupt(int irq, void *napi_id)
{
disable_irq_nosync(irq);
napi_schedule(napi_id);
return IRQ_HANDLED;
}
static inline int cvm_oct_check_rcv_error(cvmx_wqe_t *work)
{
int port;
if (octeon_has_feature(OCTEON_FEATURE_PKND))
port = work->word0.pip.cn68xx.pknd;
else
port = work->word1.cn38xx.ipprt;
if ((work->word2.snoip.err_code == 10) && (work->word1.len <= 64)) {
} else if (work->word2.snoip.err_code == 5 ||
work->word2.snoip.err_code == 7) {
int interface = cvmx_helper_get_interface_num(port);
int index = cvmx_helper_get_interface_index_num(port);
union cvmx_gmxx_rxx_frm_ctl gmxx_rxx_frm_ctl;
gmxx_rxx_frm_ctl.u64 =
cvmx_read_csr(CVMX_GMXX_RXX_FRM_CTL(index, interface));
if (gmxx_rxx_frm_ctl.s.pre_chk == 0) {
u8 *ptr =
cvmx_phys_to_ptr(work->packet_ptr.s.addr);
int i = 0;
while (i < work->word1.len - 1) {
if (*ptr != 0x55)
break;
ptr++;
i++;
}
if (*ptr == 0xd5) {
work->packet_ptr.s.addr += i + 1;
work->word1.len -= i + 5;
} else if ((*ptr & 0xf) == 0xd) {
work->packet_ptr.s.addr += i;
work->word1.len -= i + 4;
for (i = 0; i < work->word1.len; i++) {
*ptr =
((*ptr & 0xf0) >> 4) |
((*(ptr + 1) & 0xf) << 4);
ptr++;
}
} else {
printk_ratelimited("Port %d unknown preamble, packet dropped\n",
port);
cvm_oct_free_work(work);
return 1;
}
}
} else {
printk_ratelimited("Port %d receive error code %d, packet dropped\n",
port, work->word2.snoip.err_code);
cvm_oct_free_work(work);
return 1;
}
return 0;
}
static int cvm_oct_poll(struct oct_rx_group *rx_group, int budget)
{
const int coreid = cvmx_get_core_num();
u64 old_group_mask;
u64 old_scratch;
int rx_count = 0;
int did_work_request = 0;
int packet_not_copied;
prefetch(cvm_oct_device);
if (USE_ASYNC_IOBDMA) {
CVMX_SYNCIOBDMA;
old_scratch = cvmx_scratch_read64(CVMX_SCR_SCRATCH);
}
if (OCTEON_IS_MODEL(OCTEON_CN68XX)) {
old_group_mask = cvmx_read_csr(CVMX_SSO_PPX_GRP_MSK(coreid));
cvmx_write_csr(CVMX_SSO_PPX_GRP_MSK(coreid),
BIT(rx_group->group));
cvmx_read_csr(CVMX_SSO_PPX_GRP_MSK(coreid));
} else {
old_group_mask = cvmx_read_csr(CVMX_POW_PP_GRP_MSKX(coreid));
cvmx_write_csr(CVMX_POW_PP_GRP_MSKX(coreid),
(old_group_mask & ~0xFFFFull) |
BIT(rx_group->group));
}
if (USE_ASYNC_IOBDMA) {
cvmx_pow_work_request_async(CVMX_SCR_SCRATCH, CVMX_POW_NO_WAIT);
did_work_request = 1;
}
while (rx_count < budget) {
struct sk_buff *skb = NULL;
struct sk_buff **pskb = NULL;
int skb_in_hw;
cvmx_wqe_t *work;
int port;
if (USE_ASYNC_IOBDMA && did_work_request)
work = cvmx_pow_work_response_async(CVMX_SCR_SCRATCH);
else
work = cvmx_pow_work_request_sync(CVMX_POW_NO_WAIT);
prefetch(work);
did_work_request = 0;
if (!work) {
if (OCTEON_IS_MODEL(OCTEON_CN68XX)) {
cvmx_write_csr(CVMX_SSO_WQ_IQ_DIS,
BIT(rx_group->group));
cvmx_write_csr(CVMX_SSO_WQ_INT,
BIT(rx_group->group));
} else {
union cvmx_pow_wq_int wq_int;
wq_int.u64 = 0;
wq_int.s.iq_dis = BIT(rx_group->group);
wq_int.s.wq_int = BIT(rx_group->group);
cvmx_write_csr(CVMX_POW_WQ_INT, wq_int.u64);
}
break;
}
pskb = (struct sk_buff **)
(cvm_oct_get_buffer_ptr(work->packet_ptr) -
sizeof(void *));
prefetch(pskb);
if (USE_ASYNC_IOBDMA && rx_count < (budget - 1)) {
cvmx_pow_work_request_async_nocheck(CVMX_SCR_SCRATCH,
CVMX_POW_NO_WAIT);
did_work_request = 1;
}
rx_count++;
skb_in_hw = work->word2.s.bufs == 1;
if (likely(skb_in_hw)) {
skb = *pskb;
prefetch(&skb->head);
prefetch(&skb->len);
}
if (octeon_has_feature(OCTEON_FEATURE_PKND))
port = work->word0.pip.cn68xx.pknd;
else
port = work->word1.cn38xx.ipprt;
prefetch(cvm_oct_device[port]);
if (unlikely(work->word2.snoip.rcv_error)) {
if (cvm_oct_check_rcv_error(work))
continue;
}
if (likely(skb_in_hw)) {
skb->data = skb->head + work->packet_ptr.s.addr -
cvmx_ptr_to_phys(skb->head);
prefetch(skb->data);
skb->len = work->word1.len;
skb_set_tail_pointer(skb, skb->len);
packet_not_copied = 1;
} else {
skb = dev_alloc_skb(work->word1.len);
if (!skb) {
cvm_oct_free_work(work);
continue;
}
if (unlikely(work->word2.s.bufs == 0)) {
u8 *ptr = work->packet_data;
if (likely(!work->word2.s.not_IP)) {
if (work->word2.s.is_v6)
ptr += 2;
else
ptr += 6;
}
skb_put_data(skb, ptr, work->word1.len);
} else {
int segments = work->word2.s.bufs;
union cvmx_buf_ptr segment_ptr =
work->packet_ptr;
int len = work->word1.len;
while (segments--) {
union cvmx_buf_ptr next_ptr =
*(union cvmx_buf_ptr *)
cvmx_phys_to_ptr(
segment_ptr.s.addr - 8);
int segment_size =
CVMX_FPA_PACKET_POOL_SIZE -
(segment_ptr.s.addr -
(((segment_ptr.s.addr >> 7) -
segment_ptr.s.back) << 7));
if (segment_size > len)
segment_size = len;
skb_put_data(skb,
cvmx_phys_to_ptr(segment_ptr.s.addr),
segment_size);
len -= segment_size;
segment_ptr = next_ptr;
}
}
packet_not_copied = 0;
}
if (likely((port < TOTAL_NUMBER_OF_PORTS) &&
cvm_oct_device[port])) {
struct net_device *dev = cvm_oct_device[port];
if (likely(dev->flags & IFF_UP)) {
skb->protocol = eth_type_trans(skb, dev);
skb->dev = dev;
if (unlikely(work->word2.s.not_IP ||
work->word2.s.IP_exc ||
work->word2.s.L4_error ||
!work->word2.s.tcp_or_udp))
skb->ip_summed = CHECKSUM_NONE;
else
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (port >= CVMX_PIP_NUM_INPUT_PORTS) {
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
}
netif_receive_skb(skb);
} else {
dev->stats.rx_dropped++;
dev_kfree_skb_irq(skb);
}
} else {
printk_ratelimited("Port %d not controlled by Linux, packet dropped\n",
port);
dev_kfree_skb_irq(skb);
}
if (likely(packet_not_copied)) {
cvmx_fau_atomic_add32(FAU_NUM_PACKET_BUFFERS_TO_FREE,
1);
cvmx_fpa_free(work, CVMX_FPA_WQE_POOL, 1);
} else {
cvm_oct_free_work(work);
}
}
if (OCTEON_IS_MODEL(OCTEON_CN68XX)) {
cvmx_write_csr(CVMX_SSO_PPX_GRP_MSK(coreid), old_group_mask);
cvmx_read_csr(CVMX_SSO_PPX_GRP_MSK(coreid));
} else {
cvmx_write_csr(CVMX_POW_PP_GRP_MSKX(coreid), old_group_mask);
}
if (USE_ASYNC_IOBDMA) {
cvmx_scratch_write64(CVMX_SCR_SCRATCH, old_scratch);
}
cvm_oct_rx_refill_pool(0);
return rx_count;
}
static int cvm_oct_napi_poll(struct napi_struct *napi, int budget)
{
struct oct_rx_group *rx_group = container_of(napi, struct oct_rx_group,
napi);
int rx_count;
rx_count = cvm_oct_poll(rx_group, budget);
if (rx_count < budget) {
napi_complete_done(napi, rx_count);
enable_irq(rx_group->irq);
}
return rx_count;
}
void cvm_oct_poll_controller(struct net_device *dev)
{
int i;
if (!atomic_read(&oct_rx_ready))
return;
for (i = 0; i < ARRAY_SIZE(oct_rx_group); i++) {
if (!(pow_receive_groups & BIT(i)))
continue;
cvm_oct_poll(&oct_rx_group[i], 16);
}
}
void cvm_oct_rx_initialize(void)
{
int i;
struct net_device *dev_for_napi = NULL;
for (i = 0; i < TOTAL_NUMBER_OF_PORTS; i++) {
if (cvm_oct_device[i]) {
dev_for_napi = cvm_oct_device[i];
break;
}
}
if (!dev_for_napi)
panic("No net_devices were allocated.");
for (i = 0; i < ARRAY_SIZE(oct_rx_group); i++) {
int ret;
if (!(pow_receive_groups & BIT(i)))
continue;
netif_napi_add(dev_for_napi, &oct_rx_group[i].napi,
cvm_oct_napi_poll, rx_napi_weight);
napi_enable(&oct_rx_group[i].napi);
oct_rx_group[i].irq = OCTEON_IRQ_WORKQ0 + i;
oct_rx_group[i].group = i;
ret = request_irq(oct_rx_group[i].irq, cvm_oct_do_interrupt, 0,
"Ethernet", &oct_rx_group[i].napi);
if (ret)
panic("Could not acquire Ethernet IRQ %d\n",
oct_rx_group[i].irq);
disable_irq_nosync(oct_rx_group[i].irq);
if (OCTEON_IS_MODEL(OCTEON_CN68XX)) {
union cvmx_sso_wq_int_thrx int_thr;
union cvmx_pow_wq_int_pc int_pc;
int_thr.u64 = 0;
int_thr.s.tc_en = 1;
int_thr.s.tc_thr = 1;
cvmx_write_csr(CVMX_SSO_WQ_INT_THRX(i), int_thr.u64);
int_pc.u64 = 0;
int_pc.s.pc_thr = 5;
cvmx_write_csr(CVMX_SSO_WQ_INT_PC, int_pc.u64);
} else {
union cvmx_pow_wq_int_thrx int_thr;
union cvmx_pow_wq_int_pc int_pc;
int_thr.u64 = 0;
int_thr.s.tc_en = 1;
int_thr.s.tc_thr = 1;
cvmx_write_csr(CVMX_POW_WQ_INT_THRX(i), int_thr.u64);
int_pc.u64 = 0;
int_pc.s.pc_thr = 5;
cvmx_write_csr(CVMX_POW_WQ_INT_PC, int_pc.u64);
}
napi_schedule(&oct_rx_group[i].napi);
}
atomic_inc(&oct_rx_ready);
}
void cvm_oct_rx_shutdown(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(oct_rx_group); i++) {
if (!(pow_receive_groups & BIT(i)))
continue;
if (OCTEON_IS_MODEL(OCTEON_CN68XX))
cvmx_write_csr(CVMX_SSO_WQ_INT_THRX(i), 0);
else
cvmx_write_csr(CVMX_POW_WQ_INT_THRX(i), 0);
free_irq(oct_rx_group[i].irq, cvm_oct_device);
netif_napi_del(&oct_rx_group[i].napi);
}
}
