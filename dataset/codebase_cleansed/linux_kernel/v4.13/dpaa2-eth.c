static void *dpaa2_iova_to_virt(struct iommu_domain *domain,
dma_addr_t iova_addr)
{
phys_addr_t phys_addr;
phys_addr = domain ? iommu_iova_to_phys(domain, iova_addr) : iova_addr;
return phys_to_virt(phys_addr);
}
static void validate_rx_csum(struct dpaa2_eth_priv *priv,
u32 fd_status,
struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (!(priv->net_dev->features & NETIF_F_RXCSUM))
return;
if (!((fd_status & DPAA2_FAS_L3CV) &&
(fd_status & DPAA2_FAS_L4CV)))
return;
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static void free_rx_fd(struct dpaa2_eth_priv *priv,
const struct dpaa2_fd *fd,
void *vaddr)
{
struct device *dev = priv->net_dev->dev.parent;
dma_addr_t addr = dpaa2_fd_get_addr(fd);
u8 fd_format = dpaa2_fd_get_format(fd);
struct dpaa2_sg_entry *sgt;
void *sg_vaddr;
int i;
if (fd_format == dpaa2_fd_single)
goto free_buf;
else if (fd_format != dpaa2_fd_sg)
return;
sgt = vaddr + dpaa2_fd_get_offset(fd);
for (i = 0; i < DPAA2_ETH_MAX_SG_ENTRIES; i++) {
addr = dpaa2_sg_get_addr(&sgt[i]);
sg_vaddr = dpaa2_iova_to_virt(priv->iommu_domain, addr);
dma_unmap_single(dev, addr, DPAA2_ETH_RX_BUF_SIZE,
DMA_FROM_DEVICE);
skb_free_frag(sg_vaddr);
if (dpaa2_sg_is_final(&sgt[i]))
break;
}
free_buf:
skb_free_frag(vaddr);
}
static struct sk_buff *build_linear_skb(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_channel *ch,
const struct dpaa2_fd *fd,
void *fd_vaddr)
{
struct sk_buff *skb = NULL;
u16 fd_offset = dpaa2_fd_get_offset(fd);
u32 fd_length = dpaa2_fd_get_len(fd);
skb = build_skb(fd_vaddr, DPAA2_ETH_RX_BUF_SIZE +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info)));
if (unlikely(!skb))
return NULL;
skb_reserve(skb, fd_offset);
skb_put(skb, fd_length);
ch->buf_count--;
return skb;
}
static struct sk_buff *build_frag_skb(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_channel *ch,
struct dpaa2_sg_entry *sgt)
{
struct sk_buff *skb = NULL;
struct device *dev = priv->net_dev->dev.parent;
void *sg_vaddr;
dma_addr_t sg_addr;
u16 sg_offset;
u32 sg_length;
struct page *page, *head_page;
int page_offset;
int i;
for (i = 0; i < DPAA2_ETH_MAX_SG_ENTRIES; i++) {
struct dpaa2_sg_entry *sge = &sgt[i];
sg_addr = dpaa2_sg_get_addr(sge);
sg_vaddr = dpaa2_iova_to_virt(priv->iommu_domain, sg_addr);
dma_unmap_single(dev, sg_addr, DPAA2_ETH_RX_BUF_SIZE,
DMA_FROM_DEVICE);
sg_length = dpaa2_sg_get_len(sge);
if (i == 0) {
skb = build_skb(sg_vaddr, DPAA2_ETH_RX_BUF_SIZE +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info)));
if (unlikely(!skb))
return NULL;
sg_offset = dpaa2_sg_get_offset(sge);
skb_reserve(skb, sg_offset);
skb_put(skb, sg_length);
} else {
page = virt_to_page(sg_vaddr);
head_page = virt_to_head_page(sg_vaddr);
page_offset = ((unsigned long)sg_vaddr &
(PAGE_SIZE - 1)) +
(page_address(page) - page_address(head_page));
skb_add_rx_frag(skb, i - 1, head_page, page_offset,
sg_length, DPAA2_ETH_RX_BUF_SIZE);
}
if (dpaa2_sg_is_final(sge))
break;
}
ch->buf_count -= i + 2;
return skb;
}
static void dpaa2_eth_rx(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_channel *ch,
const struct dpaa2_fd *fd,
struct napi_struct *napi)
{
dma_addr_t addr = dpaa2_fd_get_addr(fd);
u8 fd_format = dpaa2_fd_get_format(fd);
void *vaddr;
struct sk_buff *skb;
struct rtnl_link_stats64 *percpu_stats;
struct dpaa2_eth_drv_stats *percpu_extras;
struct device *dev = priv->net_dev->dev.parent;
struct dpaa2_fas *fas;
void *buf_data;
u32 status = 0;
trace_dpaa2_rx_fd(priv->net_dev, fd);
vaddr = dpaa2_iova_to_virt(priv->iommu_domain, addr);
dma_unmap_single(dev, addr, DPAA2_ETH_RX_BUF_SIZE, DMA_FROM_DEVICE);
fas = dpaa2_get_fas(vaddr);
prefetch(fas);
buf_data = vaddr + dpaa2_fd_get_offset(fd);
prefetch(buf_data);
percpu_stats = this_cpu_ptr(priv->percpu_stats);
percpu_extras = this_cpu_ptr(priv->percpu_extras);
if (fd_format == dpaa2_fd_single) {
skb = build_linear_skb(priv, ch, fd, vaddr);
} else if (fd_format == dpaa2_fd_sg) {
skb = build_frag_skb(priv, ch, buf_data);
skb_free_frag(vaddr);
percpu_extras->rx_sg_frames++;
percpu_extras->rx_sg_bytes += dpaa2_fd_get_len(fd);
} else {
goto err_frame_format;
}
if (unlikely(!skb))
goto err_build_skb;
prefetch(skb->data);
if (likely(dpaa2_fd_get_frc(fd) & DPAA2_FD_FRC_FASV)) {
status = le32_to_cpu(fas->status);
validate_rx_csum(priv, status, skb);
}
skb->protocol = eth_type_trans(skb, priv->net_dev);
percpu_stats->rx_packets++;
percpu_stats->rx_bytes += dpaa2_fd_get_len(fd);
napi_gro_receive(napi, skb);
return;
err_build_skb:
free_rx_fd(priv, fd, vaddr);
err_frame_format:
percpu_stats->rx_dropped++;
}
static int consume_frames(struct dpaa2_eth_channel *ch)
{
struct dpaa2_eth_priv *priv = ch->priv;
struct dpaa2_eth_fq *fq;
struct dpaa2_dq *dq;
const struct dpaa2_fd *fd;
int cleaned = 0;
int is_last;
do {
dq = dpaa2_io_store_next(ch->store, &is_last);
if (unlikely(!dq)) {
continue;
}
fd = dpaa2_dq_fd(dq);
fq = (struct dpaa2_eth_fq *)dpaa2_dq_fqd_ctx(dq);
fq->stats.frames++;
fq->consume(priv, ch, fd, &ch->napi);
cleaned++;
} while (!is_last);
return cleaned;
}
static int build_sg_fd(struct dpaa2_eth_priv *priv,
struct sk_buff *skb,
struct dpaa2_fd *fd)
{
struct device *dev = priv->net_dev->dev.parent;
void *sgt_buf = NULL;
dma_addr_t addr;
int nr_frags = skb_shinfo(skb)->nr_frags;
struct dpaa2_sg_entry *sgt;
int i, err;
int sgt_buf_size;
struct scatterlist *scl, *crt_scl;
int num_sg;
int num_dma_bufs;
struct dpaa2_eth_swa *swa;
struct dpaa2_fas *fas;
if (unlikely(PAGE_SIZE / sizeof(struct scatterlist) < nr_frags + 1))
return -EINVAL;
scl = kcalloc(nr_frags + 1, sizeof(struct scatterlist), GFP_ATOMIC);
if (unlikely(!scl))
return -ENOMEM;
sg_init_table(scl, nr_frags + 1);
num_sg = skb_to_sgvec(skb, scl, 0, skb->len);
num_dma_bufs = dma_map_sg(dev, scl, num_sg, DMA_BIDIRECTIONAL);
if (unlikely(!num_dma_bufs)) {
err = -ENOMEM;
goto dma_map_sg_failed;
}
sgt_buf_size = priv->tx_data_offset +
sizeof(struct dpaa2_sg_entry) * (1 + num_dma_bufs);
sgt_buf = kzalloc(sgt_buf_size + DPAA2_ETH_TX_BUF_ALIGN, GFP_ATOMIC);
if (unlikely(!sgt_buf)) {
err = -ENOMEM;
goto sgt_buf_alloc_failed;
}
sgt_buf = PTR_ALIGN(sgt_buf, DPAA2_ETH_TX_BUF_ALIGN);
fas = dpaa2_get_fas(sgt_buf);
memset(fas, 0, DPAA2_FAS_SIZE);
sgt = (struct dpaa2_sg_entry *)(sgt_buf + priv->tx_data_offset);
for_each_sg(scl, crt_scl, num_dma_bufs, i) {
dpaa2_sg_set_addr(&sgt[i], sg_dma_address(crt_scl));
dpaa2_sg_set_len(&sgt[i], sg_dma_len(crt_scl));
}
dpaa2_sg_set_final(&sgt[i - 1], true);
swa = (struct dpaa2_eth_swa *)sgt_buf;
swa->skb = skb;
swa->scl = scl;
swa->num_sg = num_sg;
swa->num_dma_bufs = num_dma_bufs;
addr = dma_map_single(dev, sgt_buf, sgt_buf_size, DMA_BIDIRECTIONAL);
if (unlikely(dma_mapping_error(dev, addr))) {
err = -ENOMEM;
goto dma_map_single_failed;
}
dpaa2_fd_set_offset(fd, priv->tx_data_offset);
dpaa2_fd_set_format(fd, dpaa2_fd_sg);
dpaa2_fd_set_addr(fd, addr);
dpaa2_fd_set_len(fd, skb->len);
dpaa2_fd_set_ctrl(fd, DPAA2_FD_CTRL_ASAL | DPAA2_FD_CTRL_PTA |
DPAA2_FD_CTRL_PTV1);
return 0;
dma_map_single_failed:
kfree(sgt_buf);
sgt_buf_alloc_failed:
dma_unmap_sg(dev, scl, num_sg, DMA_BIDIRECTIONAL);
dma_map_sg_failed:
kfree(scl);
return err;
}
static int build_single_fd(struct dpaa2_eth_priv *priv,
struct sk_buff *skb,
struct dpaa2_fd *fd)
{
struct device *dev = priv->net_dev->dev.parent;
u8 *buffer_start;
struct dpaa2_fas *fas;
struct sk_buff **skbh;
dma_addr_t addr;
buffer_start = PTR_ALIGN(skb->data - priv->tx_data_offset -
DPAA2_ETH_TX_BUF_ALIGN,
DPAA2_ETH_TX_BUF_ALIGN);
fas = dpaa2_get_fas(buffer_start);
memset(fas, 0, DPAA2_FAS_SIZE);
skbh = (struct sk_buff **)buffer_start;
*skbh = skb;
addr = dma_map_single(dev, buffer_start,
skb_tail_pointer(skb) - buffer_start,
DMA_BIDIRECTIONAL);
if (unlikely(dma_mapping_error(dev, addr)))
return -ENOMEM;
dpaa2_fd_set_addr(fd, addr);
dpaa2_fd_set_offset(fd, (u16)(skb->data - buffer_start));
dpaa2_fd_set_len(fd, skb->len);
dpaa2_fd_set_format(fd, dpaa2_fd_single);
dpaa2_fd_set_ctrl(fd, DPAA2_FD_CTRL_ASAL | DPAA2_FD_CTRL_PTA |
DPAA2_FD_CTRL_PTV1);
return 0;
}
static void free_tx_fd(const struct dpaa2_eth_priv *priv,
const struct dpaa2_fd *fd,
u32 *status)
{
struct device *dev = priv->net_dev->dev.parent;
dma_addr_t fd_addr;
struct sk_buff **skbh, *skb;
unsigned char *buffer_start;
int unmap_size;
struct scatterlist *scl;
int num_sg, num_dma_bufs;
struct dpaa2_eth_swa *swa;
u8 fd_format = dpaa2_fd_get_format(fd);
struct dpaa2_fas *fas;
fd_addr = dpaa2_fd_get_addr(fd);
skbh = dpaa2_iova_to_virt(priv->iommu_domain, fd_addr);
fas = dpaa2_get_fas(skbh);
if (fd_format == dpaa2_fd_single) {
skb = *skbh;
buffer_start = (unsigned char *)skbh;
dma_unmap_single(dev, fd_addr,
skb_tail_pointer(skb) - buffer_start,
DMA_BIDIRECTIONAL);
} else if (fd_format == dpaa2_fd_sg) {
swa = (struct dpaa2_eth_swa *)skbh;
skb = swa->skb;
scl = swa->scl;
num_sg = swa->num_sg;
num_dma_bufs = swa->num_dma_bufs;
dma_unmap_sg(dev, scl, num_sg, DMA_BIDIRECTIONAL);
kfree(scl);
unmap_size = priv->tx_data_offset +
sizeof(struct dpaa2_sg_entry) * (1 + num_dma_bufs);
dma_unmap_single(dev, fd_addr, unmap_size, DMA_BIDIRECTIONAL);
} else {
if (status)
*status = ~0;
return;
}
if (status)
*status = le32_to_cpu(fas->status);
if (fd_format != dpaa2_fd_single)
kfree(skbh);
dev_kfree_skb(skb);
}
static netdev_tx_t dpaa2_eth_tx(struct sk_buff *skb, struct net_device *net_dev)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
struct dpaa2_fd fd;
struct rtnl_link_stats64 *percpu_stats;
struct dpaa2_eth_drv_stats *percpu_extras;
struct dpaa2_eth_fq *fq;
u16 queue_mapping;
int err, i;
percpu_stats = this_cpu_ptr(priv->percpu_stats);
percpu_extras = this_cpu_ptr(priv->percpu_extras);
if (unlikely(skb_headroom(skb) < DPAA2_ETH_NEEDED_HEADROOM(priv))) {
struct sk_buff *ns;
ns = skb_realloc_headroom(skb, DPAA2_ETH_NEEDED_HEADROOM(priv));
if (unlikely(!ns)) {
percpu_stats->tx_dropped++;
goto err_alloc_headroom;
}
dev_kfree_skb(skb);
skb = ns;
}
skb = skb_unshare(skb, GFP_ATOMIC);
if (unlikely(!skb)) {
percpu_stats->tx_dropped++;
return NETDEV_TX_OK;
}
memset(&fd, 0, sizeof(fd));
if (skb_is_nonlinear(skb)) {
err = build_sg_fd(priv, skb, &fd);
percpu_extras->tx_sg_frames++;
percpu_extras->tx_sg_bytes += skb->len;
} else {
err = build_single_fd(priv, skb, &fd);
}
if (unlikely(err)) {
percpu_stats->tx_dropped++;
goto err_build_fd;
}
trace_dpaa2_tx_fd(net_dev, &fd);
queue_mapping = smp_processor_id() % dpaa2_eth_queue_count(priv);
fq = &priv->fq[queue_mapping];
for (i = 0; i < DPAA2_ETH_ENQUEUE_RETRIES; i++) {
err = dpaa2_io_service_enqueue_qd(NULL, priv->tx_qdid, 0,
fq->tx_qdbin, &fd);
if (err != -EBUSY)
break;
}
percpu_extras->tx_portal_busy += i;
if (unlikely(err < 0)) {
percpu_stats->tx_errors++;
free_tx_fd(priv, &fd, NULL);
} else {
percpu_stats->tx_packets++;
percpu_stats->tx_bytes += skb->len;
}
return NETDEV_TX_OK;
err_build_fd:
err_alloc_headroom:
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void dpaa2_eth_tx_conf(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_channel *ch,
const struct dpaa2_fd *fd,
struct napi_struct *napi __always_unused)
{
struct rtnl_link_stats64 *percpu_stats;
struct dpaa2_eth_drv_stats *percpu_extras;
u32 status = 0;
u32 fd_errors;
bool has_fas_errors = false;
trace_dpaa2_tx_conf_fd(priv->net_dev, fd);
percpu_extras = this_cpu_ptr(priv->percpu_extras);
percpu_extras->tx_conf_frames++;
percpu_extras->tx_conf_bytes += dpaa2_fd_get_len(fd);
fd_errors = dpaa2_fd_get_ctrl(fd) & DPAA2_FD_TX_ERR_MASK;
if (unlikely(fd_errors)) {
has_fas_errors = (fd_errors & DPAA2_FD_CTRL_FAERR) &&
!!(dpaa2_fd_get_frc(fd) & DPAA2_FD_FRC_FASV);
if (net_ratelimit())
netdev_dbg(priv->net_dev, "TX frame FD error: %x08\n",
fd_errors);
}
free_tx_fd(priv, fd, has_fas_errors ? &status : NULL);
if (likely(!fd_errors))
return;
percpu_stats = this_cpu_ptr(priv->percpu_stats);
percpu_stats->tx_errors++;
if (has_fas_errors && net_ratelimit())
netdev_dbg(priv->net_dev, "TX frame FAS error: %x08\n",
status & DPAA2_FAS_TX_ERR_MASK);
}
static int set_rx_csum(struct dpaa2_eth_priv *priv, bool enable)
{
int err;
err = dpni_set_offload(priv->mc_io, 0, priv->mc_token,
DPNI_OFF_RX_L3_CSUM, enable);
if (err) {
netdev_err(priv->net_dev,
"dpni_set_offload(RX_L3_CSUM) failed\n");
return err;
}
err = dpni_set_offload(priv->mc_io, 0, priv->mc_token,
DPNI_OFF_RX_L4_CSUM, enable);
if (err) {
netdev_err(priv->net_dev,
"dpni_set_offload(RX_L4_CSUM) failed\n");
return err;
}
return 0;
}
static int set_tx_csum(struct dpaa2_eth_priv *priv, bool enable)
{
int err;
err = dpni_set_offload(priv->mc_io, 0, priv->mc_token,
DPNI_OFF_TX_L3_CSUM, enable);
if (err) {
netdev_err(priv->net_dev, "dpni_set_offload(TX_L3_CSUM) failed\n");
return err;
}
err = dpni_set_offload(priv->mc_io, 0, priv->mc_token,
DPNI_OFF_TX_L4_CSUM, enable);
if (err) {
netdev_err(priv->net_dev, "dpni_set_offload(TX_L4_CSUM) failed\n");
return err;
}
return 0;
}
static int add_bufs(struct dpaa2_eth_priv *priv, u16 bpid)
{
struct device *dev = priv->net_dev->dev.parent;
u64 buf_array[DPAA2_ETH_BUFS_PER_CMD];
void *buf;
dma_addr_t addr;
int i;
for (i = 0; i < DPAA2_ETH_BUFS_PER_CMD; i++) {
buf = napi_alloc_frag(DPAA2_ETH_BUF_RAW_SIZE);
if (unlikely(!buf))
goto err_alloc;
buf = PTR_ALIGN(buf, DPAA2_ETH_RX_BUF_ALIGN);
addr = dma_map_single(dev, buf, DPAA2_ETH_RX_BUF_SIZE,
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(dev, addr)))
goto err_map;
buf_array[i] = addr;
trace_dpaa2_eth_buf_seed(priv->net_dev,
buf, DPAA2_ETH_BUF_RAW_SIZE,
addr, DPAA2_ETH_RX_BUF_SIZE,
bpid);
}
release_bufs:
while (dpaa2_io_service_release(NULL, bpid, buf_array, i))
cpu_relax();
return i;
err_map:
skb_free_frag(buf);
err_alloc:
if (i)
goto release_bufs;
return 0;
}
static int seed_pool(struct dpaa2_eth_priv *priv, u16 bpid)
{
int i, j;
int new_count;
preempt_disable();
for (j = 0; j < priv->num_channels; j++) {
for (i = 0; i < DPAA2_ETH_NUM_BUFS;
i += DPAA2_ETH_BUFS_PER_CMD) {
new_count = add_bufs(priv, bpid);
priv->channel[j]->buf_count += new_count;
if (new_count < DPAA2_ETH_BUFS_PER_CMD) {
preempt_enable();
return -ENOMEM;
}
}
}
preempt_enable();
return 0;
}
static void drain_bufs(struct dpaa2_eth_priv *priv, int count)
{
struct device *dev = priv->net_dev->dev.parent;
u64 buf_array[DPAA2_ETH_BUFS_PER_CMD];
void *vaddr;
int ret, i;
do {
ret = dpaa2_io_service_acquire(NULL, priv->bpid,
buf_array, count);
if (ret < 0) {
netdev_err(priv->net_dev, "dpaa2_io_service_acquire() failed\n");
return;
}
for (i = 0; i < ret; i++) {
vaddr = dpaa2_iova_to_virt(priv->iommu_domain,
buf_array[i]);
dma_unmap_single(dev, buf_array[i],
DPAA2_ETH_RX_BUF_SIZE,
DMA_FROM_DEVICE);
skb_free_frag(vaddr);
}
} while (ret);
}
static void drain_pool(struct dpaa2_eth_priv *priv)
{
int i;
drain_bufs(priv, DPAA2_ETH_BUFS_PER_CMD);
drain_bufs(priv, 1);
for (i = 0; i < priv->num_channels; i++)
priv->channel[i]->buf_count = 0;
}
static int refill_pool(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_channel *ch,
u16 bpid)
{
int new_count;
if (likely(ch->buf_count >= DPAA2_ETH_REFILL_THRESH))
return 0;
do {
new_count = add_bufs(priv, bpid);
if (unlikely(!new_count)) {
break;
}
ch->buf_count += new_count;
} while (ch->buf_count < DPAA2_ETH_NUM_BUFS);
if (unlikely(ch->buf_count < DPAA2_ETH_NUM_BUFS))
return -ENOMEM;
return 0;
}
static int pull_channel(struct dpaa2_eth_channel *ch)
{
int err;
int dequeues = -1;
do {
err = dpaa2_io_service_pull_channel(NULL, ch->ch_id, ch->store);
dequeues++;
cpu_relax();
} while (err == -EBUSY);
ch->stats.dequeue_portal_busy += dequeues;
if (unlikely(err))
ch->stats.pull_err++;
return err;
}
static int dpaa2_eth_poll(struct napi_struct *napi, int budget)
{
struct dpaa2_eth_channel *ch;
int cleaned = 0, store_cleaned;
struct dpaa2_eth_priv *priv;
int err;
ch = container_of(napi, struct dpaa2_eth_channel, napi);
priv = ch->priv;
while (cleaned < budget) {
err = pull_channel(ch);
if (unlikely(err))
break;
refill_pool(priv, ch, priv->bpid);
store_cleaned = consume_frames(ch);
cleaned += store_cleaned;
if (store_cleaned == 0 ||
cleaned > budget - DPAA2_ETH_STORE_SIZE)
break;
}
if (cleaned < budget) {
napi_complete_done(napi, cleaned);
do {
err = dpaa2_io_service_rearm(NULL, &ch->nctx);
cpu_relax();
} while (err == -EBUSY);
}
ch->stats.frames += cleaned;
return cleaned;
}
static void enable_ch_napi(struct dpaa2_eth_priv *priv)
{
struct dpaa2_eth_channel *ch;
int i;
for (i = 0; i < priv->num_channels; i++) {
ch = priv->channel[i];
napi_enable(&ch->napi);
}
}
static void disable_ch_napi(struct dpaa2_eth_priv *priv)
{
struct dpaa2_eth_channel *ch;
int i;
for (i = 0; i < priv->num_channels; i++) {
ch = priv->channel[i];
napi_disable(&ch->napi);
}
}
static int link_state_update(struct dpaa2_eth_priv *priv)
{
struct dpni_link_state state;
int err;
err = dpni_get_link_state(priv->mc_io, 0, priv->mc_token, &state);
if (unlikely(err)) {
netdev_err(priv->net_dev,
"dpni_get_link_state() failed\n");
return err;
}
if (priv->link_state.up == state.up)
return 0;
priv->link_state = state;
if (state.up) {
netif_carrier_on(priv->net_dev);
netif_tx_start_all_queues(priv->net_dev);
} else {
netif_tx_stop_all_queues(priv->net_dev);
netif_carrier_off(priv->net_dev);
}
netdev_info(priv->net_dev, "Link Event: state %s\n",
state.up ? "up" : "down");
return 0;
}
static int dpaa2_eth_open(struct net_device *net_dev)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
int err;
err = seed_pool(priv, priv->bpid);
if (err) {
netdev_err(net_dev, "Buffer seeding failed for DPBP %d (bpid=%d)\n",
priv->dpbp_dev->obj_desc.id, priv->bpid);
}
netif_tx_stop_all_queues(net_dev);
enable_ch_napi(priv);
netif_carrier_off(net_dev);
err = dpni_enable(priv->mc_io, 0, priv->mc_token);
if (err < 0) {
netdev_err(net_dev, "dpni_enable() failed\n");
goto enable_err;
}
err = link_state_update(priv);
if (err < 0) {
netdev_err(net_dev, "Can't update link state\n");
goto link_state_err;
}
return 0;
link_state_err:
enable_err:
disable_ch_napi(priv);
drain_pool(priv);
return err;
}
static u32 drain_channel(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_channel *ch)
{
u32 drained = 0, total = 0;
do {
pull_channel(ch);
drained = consume_frames(ch);
total += drained;
} while (drained);
return total;
}
static u32 drain_ingress_frames(struct dpaa2_eth_priv *priv)
{
struct dpaa2_eth_channel *ch;
int i;
u32 drained = 0;
for (i = 0; i < priv->num_channels; i++) {
ch = priv->channel[i];
drained += drain_channel(priv, ch);
}
return drained;
}
static int dpaa2_eth_stop(struct net_device *net_dev)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
int dpni_enabled;
int retries = 10;
u32 drained;
netif_tx_stop_all_queues(net_dev);
netif_carrier_off(net_dev);
do {
dpni_disable(priv->mc_io, 0, priv->mc_token);
dpni_is_enabled(priv->mc_io, 0, priv->mc_token, &dpni_enabled);
if (dpni_enabled)
msleep(100);
} while (dpni_enabled && --retries);
if (!retries) {
netdev_warn(net_dev, "Retry count exceeded disabling DPNI\n");
}
disable_ch_napi(priv);
drained = drain_ingress_frames(priv);
if (drained)
netdev_dbg(net_dev, "Drained %d frames.\n", drained);
drain_pool(priv);
return 0;
}
static int dpaa2_eth_init(struct net_device *net_dev)
{
u64 supported = 0;
u64 not_supported = 0;
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
u32 options = priv->dpni_attrs.options;
supported |= IFF_LIVE_ADDR_CHANGE;
if (options & DPNI_OPT_NO_MAC_FILTER)
not_supported |= IFF_UNICAST_FLT;
else
supported |= IFF_UNICAST_FLT;
net_dev->priv_flags |= supported;
net_dev->priv_flags &= ~not_supported;
net_dev->features = NETIF_F_RXCSUM |
NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_SG | NETIF_F_HIGHDMA |
NETIF_F_LLTX;
net_dev->hw_features = net_dev->features;
return 0;
}
static int dpaa2_eth_set_addr(struct net_device *net_dev, void *addr)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
struct device *dev = net_dev->dev.parent;
int err;
err = eth_mac_addr(net_dev, addr);
if (err < 0) {
dev_err(dev, "eth_mac_addr() failed (%d)\n", err);
return err;
}
err = dpni_set_primary_mac_addr(priv->mc_io, 0, priv->mc_token,
net_dev->dev_addr);
if (err) {
dev_err(dev, "dpni_set_primary_mac_addr() failed (%d)\n", err);
return err;
}
return 0;
}
static void dpaa2_eth_get_stats(struct net_device *net_dev,
struct rtnl_link_stats64 *stats)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
struct rtnl_link_stats64 *percpu_stats;
u64 *cpustats;
u64 *netstats = (u64 *)stats;
int i, j;
int num = sizeof(struct rtnl_link_stats64) / sizeof(u64);
for_each_possible_cpu(i) {
percpu_stats = per_cpu_ptr(priv->percpu_stats, i);
cpustats = (u64 *)percpu_stats;
for (j = 0; j < num; j++)
netstats[j] += cpustats[j];
}
}
static int dpaa2_eth_change_mtu(struct net_device *net_dev, int mtu)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
int err;
err = dpni_set_max_frame_length(priv->mc_io, 0, priv->mc_token,
(u16)DPAA2_ETH_L2_MAX_FRM(mtu));
if (err) {
netdev_err(net_dev, "dpni_set_max_frame_length() failed\n");
return err;
}
net_dev->mtu = mtu;
return 0;
}
static void add_uc_hw_addr(const struct net_device *net_dev,
struct dpaa2_eth_priv *priv)
{
struct netdev_hw_addr *ha;
int err;
netdev_for_each_uc_addr(ha, net_dev) {
err = dpni_add_mac_addr(priv->mc_io, 0, priv->mc_token,
ha->addr);
if (err)
netdev_warn(priv->net_dev,
"Could not add ucast MAC %pM to the filtering table (err %d)\n",
ha->addr, err);
}
}
static void add_mc_hw_addr(const struct net_device *net_dev,
struct dpaa2_eth_priv *priv)
{
struct netdev_hw_addr *ha;
int err;
netdev_for_each_mc_addr(ha, net_dev) {
err = dpni_add_mac_addr(priv->mc_io, 0, priv->mc_token,
ha->addr);
if (err)
netdev_warn(priv->net_dev,
"Could not add mcast MAC %pM to the filtering table (err %d)\n",
ha->addr, err);
}
}
static void dpaa2_eth_set_rx_mode(struct net_device *net_dev)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
int uc_count = netdev_uc_count(net_dev);
int mc_count = netdev_mc_count(net_dev);
u8 max_mac = priv->dpni_attrs.mac_filter_entries;
u32 options = priv->dpni_attrs.options;
u16 mc_token = priv->mc_token;
struct fsl_mc_io *mc_io = priv->mc_io;
int err;
if (options & DPNI_OPT_NO_MAC_FILTER && max_mac != 0)
netdev_info(net_dev,
"mac_filter_entries=%d, DPNI_OPT_NO_MAC_FILTER option must be disabled\n",
max_mac);
if (uc_count > max_mac) {
netdev_info(net_dev,
"Unicast addr count reached %d, max allowed is %d; forcing promisc\n",
uc_count, max_mac);
goto force_promisc;
}
if (mc_count + uc_count > max_mac) {
netdev_info(net_dev,
"Unicast + multicast addr count reached %d, max allowed is %d; forcing promisc\n",
uc_count + mc_count, max_mac);
goto force_mc_promisc;
}
if (net_dev->flags & IFF_PROMISC)
goto force_promisc;
if (net_dev->flags & IFF_ALLMULTI) {
err = dpni_set_unicast_promisc(mc_io, 0, mc_token, 1);
if (err)
netdev_warn(net_dev, "Can't set uc promisc\n");
err = dpni_clear_mac_filters(mc_io, 0, mc_token, 1, 0);
if (err)
netdev_warn(net_dev, "Can't clear uc filters\n");
add_uc_hw_addr(net_dev, priv);
err = dpni_set_unicast_promisc(mc_io, 0, mc_token, 0);
if (err)
netdev_warn(net_dev, "Can't clear uc promisc\n");
goto force_mc_promisc;
}
err = dpni_set_unicast_promisc(mc_io, 0, mc_token, 1);
if (err)
netdev_warn(net_dev, "Can't set uc promisc (%d)\n", err);
err = dpni_set_multicast_promisc(mc_io, 0, mc_token, 1);
if (err)
netdev_warn(net_dev, "Can't set mc promisc (%d)\n", err);
err = dpni_clear_mac_filters(mc_io, 0, mc_token, 1, 1);
if (err)
netdev_warn(net_dev, "Can't clear mac filters\n");
add_mc_hw_addr(net_dev, priv);
add_uc_hw_addr(net_dev, priv);
err = dpni_set_unicast_promisc(mc_io, 0, mc_token, 0);
if (err)
netdev_warn(net_dev, "Can't clear ucast promisc\n");
err = dpni_set_multicast_promisc(mc_io, 0, mc_token, 0);
if (err)
netdev_warn(net_dev, "Can't clear mcast promisc\n");
return;
force_promisc:
err = dpni_set_unicast_promisc(mc_io, 0, mc_token, 1);
if (err)
netdev_warn(net_dev, "Can't set ucast promisc\n");
force_mc_promisc:
err = dpni_set_multicast_promisc(mc_io, 0, mc_token, 1);
if (err)
netdev_warn(net_dev, "Can't set mcast promisc\n");
}
static int dpaa2_eth_set_features(struct net_device *net_dev,
netdev_features_t features)
{
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
netdev_features_t changed = features ^ net_dev->features;
bool enable;
int err;
if (changed & NETIF_F_RXCSUM) {
enable = !!(features & NETIF_F_RXCSUM);
err = set_rx_csum(priv, enable);
if (err)
return err;
}
if (changed & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM)) {
enable = !!(features & (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM));
err = set_tx_csum(priv, enable);
if (err)
return err;
}
return 0;
}
static void cdan_cb(struct dpaa2_io_notification_ctx *ctx)
{
struct dpaa2_eth_channel *ch;
ch = container_of(ctx, struct dpaa2_eth_channel, nctx);
ch->stats.cdan++;
napi_schedule_irqoff(&ch->napi);
}
static struct fsl_mc_device *setup_dpcon(struct dpaa2_eth_priv *priv)
{
struct fsl_mc_device *dpcon;
struct device *dev = priv->net_dev->dev.parent;
struct dpcon_attr attrs;
int err;
err = fsl_mc_object_allocate(to_fsl_mc_device(dev),
FSL_MC_POOL_DPCON, &dpcon);
if (err) {
dev_info(dev, "Not enough DPCONs, will go on as-is\n");
return NULL;
}
err = dpcon_open(priv->mc_io, 0, dpcon->obj_desc.id, &dpcon->mc_handle);
if (err) {
dev_err(dev, "dpcon_open() failed\n");
goto err_open;
}
err = dpcon_reset(priv->mc_io, 0, dpcon->mc_handle);
if (err) {
dev_err(dev, "dpcon_reset() failed\n");
goto err_reset;
}
err = dpcon_get_attributes(priv->mc_io, 0, dpcon->mc_handle, &attrs);
if (err) {
dev_err(dev, "dpcon_get_attributes() failed\n");
goto err_get_attr;
}
err = dpcon_enable(priv->mc_io, 0, dpcon->mc_handle);
if (err) {
dev_err(dev, "dpcon_enable() failed\n");
goto err_enable;
}
return dpcon;
err_enable:
err_get_attr:
err_reset:
dpcon_close(priv->mc_io, 0, dpcon->mc_handle);
err_open:
fsl_mc_object_free(dpcon);
return NULL;
}
static void free_dpcon(struct dpaa2_eth_priv *priv,
struct fsl_mc_device *dpcon)
{
dpcon_disable(priv->mc_io, 0, dpcon->mc_handle);
dpcon_close(priv->mc_io, 0, dpcon->mc_handle);
fsl_mc_object_free(dpcon);
}
static struct dpaa2_eth_channel *
alloc_channel(struct dpaa2_eth_priv *priv)
{
struct dpaa2_eth_channel *channel;
struct dpcon_attr attr;
struct device *dev = priv->net_dev->dev.parent;
int err;
channel = kzalloc(sizeof(*channel), GFP_KERNEL);
if (!channel)
return NULL;
channel->dpcon = setup_dpcon(priv);
if (!channel->dpcon)
goto err_setup;
err = dpcon_get_attributes(priv->mc_io, 0, channel->dpcon->mc_handle,
&attr);
if (err) {
dev_err(dev, "dpcon_get_attributes() failed\n");
goto err_get_attr;
}
channel->dpcon_id = attr.id;
channel->ch_id = attr.qbman_ch_id;
channel->priv = priv;
return channel;
err_get_attr:
free_dpcon(priv, channel->dpcon);
err_setup:
kfree(channel);
return NULL;
}
static void free_channel(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_channel *channel)
{
free_dpcon(priv, channel->dpcon);
kfree(channel);
}
static int setup_dpio(struct dpaa2_eth_priv *priv)
{
struct dpaa2_io_notification_ctx *nctx;
struct dpaa2_eth_channel *channel;
struct dpcon_notification_cfg dpcon_notif_cfg;
struct device *dev = priv->net_dev->dev.parent;
int i, err;
cpumask_clear(&priv->dpio_cpumask);
for_each_online_cpu(i) {
channel = alloc_channel(priv);
if (!channel) {
dev_info(dev,
"No affine channel for cpu %d and above\n", i);
err = -ENODEV;
goto err_alloc_ch;
}
priv->channel[priv->num_channels] = channel;
nctx = &channel->nctx;
nctx->is_cdan = 1;
nctx->cb = cdan_cb;
nctx->id = channel->ch_id;
nctx->desired_cpu = i;
err = dpaa2_io_service_register(NULL, nctx);
if (err) {
dev_dbg(dev, "No affine DPIO for cpu %d\n", i);
err = -EPROBE_DEFER;
goto err_service_reg;
}
dpcon_notif_cfg.dpio_id = nctx->dpio_id;
dpcon_notif_cfg.priority = 0;
dpcon_notif_cfg.user_ctx = nctx->qman64;
err = dpcon_set_notification(priv->mc_io, 0,
channel->dpcon->mc_handle,
&dpcon_notif_cfg);
if (err) {
dev_err(dev, "dpcon_set_notification failed()\n");
goto err_set_cdan;
}
cpumask_set_cpu(i, &priv->dpio_cpumask);
priv->num_channels++;
if (priv->num_channels == dpaa2_eth_queue_count(priv))
break;
}
return 0;
err_set_cdan:
dpaa2_io_service_deregister(NULL, nctx);
err_service_reg:
free_channel(priv, channel);
err_alloc_ch:
if (cpumask_empty(&priv->dpio_cpumask)) {
dev_err(dev, "No cpu with an affine DPIO/DPCON\n");
return err;
}
dev_info(dev, "Cores %*pbl available for processing ingress traffic\n",
cpumask_pr_args(&priv->dpio_cpumask));
return 0;
}
static void free_dpio(struct dpaa2_eth_priv *priv)
{
int i;
struct dpaa2_eth_channel *ch;
for (i = 0; i < priv->num_channels; i++) {
ch = priv->channel[i];
dpaa2_io_service_deregister(NULL, &ch->nctx);
free_channel(priv, ch);
}
}
static struct dpaa2_eth_channel *get_affine_channel(struct dpaa2_eth_priv *priv,
int cpu)
{
struct device *dev = priv->net_dev->dev.parent;
int i;
for (i = 0; i < priv->num_channels; i++)
if (priv->channel[i]->nctx.desired_cpu == cpu)
return priv->channel[i];
dev_warn(dev, "No affine channel found for cpu %d\n", cpu);
return priv->channel[0];
}
static void set_fq_affinity(struct dpaa2_eth_priv *priv)
{
struct device *dev = priv->net_dev->dev.parent;
struct dpaa2_eth_fq *fq;
int rx_cpu, txc_cpu;
int i;
rx_cpu = txc_cpu = cpumask_first(&priv->dpio_cpumask);
for (i = 0; i < priv->num_fqs; i++) {
fq = &priv->fq[i];
switch (fq->type) {
case DPAA2_RX_FQ:
fq->target_cpu = rx_cpu;
rx_cpu = cpumask_next(rx_cpu, &priv->dpio_cpumask);
if (rx_cpu >= nr_cpu_ids)
rx_cpu = cpumask_first(&priv->dpio_cpumask);
break;
case DPAA2_TX_CONF_FQ:
fq->target_cpu = txc_cpu;
txc_cpu = cpumask_next(txc_cpu, &priv->dpio_cpumask);
if (txc_cpu >= nr_cpu_ids)
txc_cpu = cpumask_first(&priv->dpio_cpumask);
break;
default:
dev_err(dev, "Unknown FQ type: %d\n", fq->type);
}
fq->channel = get_affine_channel(priv, fq->target_cpu);
}
}
static void setup_fqs(struct dpaa2_eth_priv *priv)
{
int i;
for (i = 0; i < dpaa2_eth_queue_count(priv); i++) {
priv->fq[priv->num_fqs].type = DPAA2_TX_CONF_FQ;
priv->fq[priv->num_fqs].consume = dpaa2_eth_tx_conf;
priv->fq[priv->num_fqs++].flowid = (u16)i;
}
for (i = 0; i < dpaa2_eth_queue_count(priv); i++) {
priv->fq[priv->num_fqs].type = DPAA2_RX_FQ;
priv->fq[priv->num_fqs].consume = dpaa2_eth_rx;
priv->fq[priv->num_fqs++].flowid = (u16)i;
}
set_fq_affinity(priv);
}
static int setup_dpbp(struct dpaa2_eth_priv *priv)
{
int err;
struct fsl_mc_device *dpbp_dev;
struct device *dev = priv->net_dev->dev.parent;
struct dpbp_attr dpbp_attrs;
err = fsl_mc_object_allocate(to_fsl_mc_device(dev), FSL_MC_POOL_DPBP,
&dpbp_dev);
if (err) {
dev_err(dev, "DPBP device allocation failed\n");
return err;
}
priv->dpbp_dev = dpbp_dev;
err = dpbp_open(priv->mc_io, 0, priv->dpbp_dev->obj_desc.id,
&dpbp_dev->mc_handle);
if (err) {
dev_err(dev, "dpbp_open() failed\n");
goto err_open;
}
err = dpbp_reset(priv->mc_io, 0, dpbp_dev->mc_handle);
if (err) {
dev_err(dev, "dpbp_reset() failed\n");
goto err_reset;
}
err = dpbp_enable(priv->mc_io, 0, dpbp_dev->mc_handle);
if (err) {
dev_err(dev, "dpbp_enable() failed\n");
goto err_enable;
}
err = dpbp_get_attributes(priv->mc_io, 0, dpbp_dev->mc_handle,
&dpbp_attrs);
if (err) {
dev_err(dev, "dpbp_get_attributes() failed\n");
goto err_get_attr;
}
priv->bpid = dpbp_attrs.bpid;
return 0;
err_get_attr:
dpbp_disable(priv->mc_io, 0, dpbp_dev->mc_handle);
err_enable:
err_reset:
dpbp_close(priv->mc_io, 0, dpbp_dev->mc_handle);
err_open:
fsl_mc_object_free(dpbp_dev);
return err;
}
static void free_dpbp(struct dpaa2_eth_priv *priv)
{
drain_pool(priv);
dpbp_disable(priv->mc_io, 0, priv->dpbp_dev->mc_handle);
dpbp_close(priv->mc_io, 0, priv->dpbp_dev->mc_handle);
fsl_mc_object_free(priv->dpbp_dev);
}
static int setup_dpni(struct fsl_mc_device *ls_dev)
{
struct device *dev = &ls_dev->dev;
struct dpaa2_eth_priv *priv;
struct net_device *net_dev;
struct dpni_buffer_layout buf_layout = {0};
int err;
net_dev = dev_get_drvdata(dev);
priv = netdev_priv(net_dev);
err = dpni_open(priv->mc_io, 0, ls_dev->obj_desc.id, &priv->mc_token);
if (err) {
dev_err(dev, "dpni_open() failed\n");
goto err_open;
}
ls_dev->mc_io = priv->mc_io;
ls_dev->mc_handle = priv->mc_token;
err = dpni_reset(priv->mc_io, 0, priv->mc_token);
if (err) {
dev_err(dev, "dpni_reset() failed\n");
goto err_reset;
}
err = dpni_get_attributes(priv->mc_io, 0, priv->mc_token,
&priv->dpni_attrs);
if (err) {
dev_err(dev, "dpni_get_attributes() failed (err=%d)\n", err);
goto err_get_attr;
}
buf_layout.pass_parser_result = true;
buf_layout.pass_frame_status = true;
buf_layout.private_data_size = DPAA2_ETH_SWA_SIZE;
buf_layout.data_align = DPAA2_ETH_RX_BUF_ALIGN;
buf_layout.options = DPNI_BUF_LAYOUT_OPT_PARSER_RESULT |
DPNI_BUF_LAYOUT_OPT_FRAME_STATUS |
DPNI_BUF_LAYOUT_OPT_PRIVATE_DATA_SIZE |
DPNI_BUF_LAYOUT_OPT_DATA_ALIGN;
err = dpni_set_buffer_layout(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_RX, &buf_layout);
if (err) {
dev_err(dev, "dpni_set_buffer_layout(RX) failed\n");
goto err_buf_layout;
}
buf_layout.options = DPNI_BUF_LAYOUT_OPT_FRAME_STATUS |
DPNI_BUF_LAYOUT_OPT_PRIVATE_DATA_SIZE;
err = dpni_set_buffer_layout(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_TX, &buf_layout);
if (err) {
dev_err(dev, "dpni_set_buffer_layout(TX) failed\n");
goto err_buf_layout;
}
buf_layout.options = DPNI_BUF_LAYOUT_OPT_FRAME_STATUS;
err = dpni_set_buffer_layout(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_TX_CONFIRM, &buf_layout);
if (err) {
dev_err(dev, "dpni_set_buffer_layout(TX_CONF) failed\n");
goto err_buf_layout;
}
err = dpni_get_tx_data_offset(priv->mc_io, 0, priv->mc_token,
&priv->tx_data_offset);
if (err) {
dev_err(dev, "dpni_get_tx_data_offset() failed\n");
goto err_data_offset;
}
if ((priv->tx_data_offset % 64) != 0)
dev_warn(dev, "Tx data offset (%d) not a multiple of 64B\n",
priv->tx_data_offset);
priv->tx_data_offset += DPAA2_ETH_SWA_SIZE;
return 0;
err_data_offset:
err_buf_layout:
err_get_attr:
err_reset:
dpni_close(priv->mc_io, 0, priv->mc_token);
err_open:
return err;
}
static void free_dpni(struct dpaa2_eth_priv *priv)
{
int err;
err = dpni_reset(priv->mc_io, 0, priv->mc_token);
if (err)
netdev_warn(priv->net_dev, "dpni_reset() failed (err %d)\n",
err);
dpni_close(priv->mc_io, 0, priv->mc_token);
}
static int setup_rx_flow(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_fq *fq)
{
struct device *dev = priv->net_dev->dev.parent;
struct dpni_queue queue;
struct dpni_queue_id qid;
struct dpni_taildrop td;
int err;
err = dpni_get_queue(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_RX, 0, fq->flowid, &queue, &qid);
if (err) {
dev_err(dev, "dpni_get_queue(RX) failed\n");
return err;
}
fq->fqid = qid.fqid;
queue.destination.id = fq->channel->dpcon_id;
queue.destination.type = DPNI_DEST_DPCON;
queue.destination.priority = 1;
queue.user_context = (u64)fq;
err = dpni_set_queue(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_RX, 0, fq->flowid,
DPNI_QUEUE_OPT_USER_CTX | DPNI_QUEUE_OPT_DEST,
&queue);
if (err) {
dev_err(dev, "dpni_set_queue(RX) failed\n");
return err;
}
td.enable = 1;
td.threshold = DPAA2_ETH_TAILDROP_THRESH;
err = dpni_set_taildrop(priv->mc_io, 0, priv->mc_token, DPNI_CP_QUEUE,
DPNI_QUEUE_RX, 0, fq->flowid, &td);
if (err) {
dev_err(dev, "dpni_set_threshold() failed\n");
return err;
}
return 0;
}
static int setup_tx_flow(struct dpaa2_eth_priv *priv,
struct dpaa2_eth_fq *fq)
{
struct device *dev = priv->net_dev->dev.parent;
struct dpni_queue queue;
struct dpni_queue_id qid;
int err;
err = dpni_get_queue(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_TX, 0, fq->flowid, &queue, &qid);
if (err) {
dev_err(dev, "dpni_get_queue(TX) failed\n");
return err;
}
fq->tx_qdbin = qid.qdbin;
err = dpni_get_queue(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_TX_CONFIRM, 0, fq->flowid,
&queue, &qid);
if (err) {
dev_err(dev, "dpni_get_queue(TX_CONF) failed\n");
return err;
}
fq->fqid = qid.fqid;
queue.destination.id = fq->channel->dpcon_id;
queue.destination.type = DPNI_DEST_DPCON;
queue.destination.priority = 0;
queue.user_context = (u64)fq;
err = dpni_set_queue(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_TX_CONFIRM, 0, fq->flowid,
DPNI_QUEUE_OPT_USER_CTX | DPNI_QUEUE_OPT_DEST,
&queue);
if (err) {
dev_err(dev, "dpni_set_queue(TX_CONF) failed\n");
return err;
}
return 0;
}
static int dpaa2_eth_set_hash(struct net_device *net_dev, u64 flags)
{
struct device *dev = net_dev->dev.parent;
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
struct dpkg_profile_cfg cls_cfg;
struct dpni_rx_tc_dist_cfg dist_cfg;
u8 *dma_mem;
int i;
int err = 0;
if (!dpaa2_eth_hash_enabled(priv)) {
dev_dbg(dev, "Hashing support is not enabled\n");
return 0;
}
memset(&cls_cfg, 0, sizeof(cls_cfg));
for (i = 0; i < ARRAY_SIZE(hash_fields); i++) {
struct dpkg_extract *key =
&cls_cfg.extracts[cls_cfg.num_extracts];
if (!(flags & hash_fields[i].rxnfc_field))
continue;
if (cls_cfg.num_extracts >= DPKG_MAX_NUM_OF_EXTRACTS) {
dev_err(dev, "error adding key extraction rule, too many rules?\n");
return -E2BIG;
}
key->type = DPKG_EXTRACT_FROM_HDR;
key->extract.from_hdr.prot = hash_fields[i].cls_prot;
key->extract.from_hdr.type = DPKG_FULL_FIELD;
key->extract.from_hdr.field = hash_fields[i].cls_field;
cls_cfg.num_extracts++;
priv->rx_hash_fields |= hash_fields[i].rxnfc_field;
}
dma_mem = kzalloc(DPAA2_CLASSIFIER_DMA_SIZE, GFP_KERNEL);
if (!dma_mem)
return -ENOMEM;
err = dpni_prepare_key_cfg(&cls_cfg, dma_mem);
if (err) {
dev_err(dev, "dpni_prepare_key_cfg error %d\n", err);
goto err_prep_key;
}
memset(&dist_cfg, 0, sizeof(dist_cfg));
dist_cfg.key_cfg_iova = dma_map_single(dev, dma_mem,
DPAA2_CLASSIFIER_DMA_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, dist_cfg.key_cfg_iova)) {
dev_err(dev, "DMA mapping failed\n");
err = -ENOMEM;
goto err_dma_map;
}
dist_cfg.dist_size = dpaa2_eth_queue_count(priv);
dist_cfg.dist_mode = DPNI_DIST_MODE_HASH;
err = dpni_set_rx_tc_dist(priv->mc_io, 0, priv->mc_token, 0, &dist_cfg);
dma_unmap_single(dev, dist_cfg.key_cfg_iova,
DPAA2_CLASSIFIER_DMA_SIZE, DMA_TO_DEVICE);
if (err)
dev_err(dev, "dpni_set_rx_tc_dist() error %d\n", err);
err_dma_map:
err_prep_key:
kfree(dma_mem);
return err;
}
static int bind_dpni(struct dpaa2_eth_priv *priv)
{
struct net_device *net_dev = priv->net_dev;
struct device *dev = net_dev->dev.parent;
struct dpni_pools_cfg pools_params;
struct dpni_error_cfg err_cfg;
int err = 0;
int i;
pools_params.num_dpbp = 1;
pools_params.pools[0].dpbp_id = priv->dpbp_dev->obj_desc.id;
pools_params.pools[0].backup_pool = 0;
pools_params.pools[0].buffer_size = DPAA2_ETH_RX_BUF_SIZE;
err = dpni_set_pools(priv->mc_io, 0, priv->mc_token, &pools_params);
if (err) {
dev_err(dev, "dpni_set_pools() failed\n");
return err;
}
err = dpaa2_eth_set_hash(net_dev, DPAA2_RXH_SUPPORTED);
if (err)
netdev_err(net_dev, "Failed to configure hashing\n");
err_cfg.errors = DPAA2_FAS_RX_ERR_MASK;
err_cfg.set_frame_annotation = 1;
err_cfg.error_action = DPNI_ERROR_ACTION_DISCARD;
err = dpni_set_errors_behavior(priv->mc_io, 0, priv->mc_token,
&err_cfg);
if (err) {
dev_err(dev, "dpni_set_errors_behavior failed\n");
return err;
}
for (i = 0; i < priv->num_fqs; i++) {
switch (priv->fq[i].type) {
case DPAA2_RX_FQ:
err = setup_rx_flow(priv, &priv->fq[i]);
break;
case DPAA2_TX_CONF_FQ:
err = setup_tx_flow(priv, &priv->fq[i]);
break;
default:
dev_err(dev, "Invalid FQ type %d\n", priv->fq[i].type);
return -EINVAL;
}
if (err)
return err;
}
err = dpni_get_qdid(priv->mc_io, 0, priv->mc_token,
DPNI_QUEUE_TX, &priv->tx_qdid);
if (err) {
dev_err(dev, "dpni_get_qdid() failed\n");
return err;
}
return 0;
}
static int alloc_rings(struct dpaa2_eth_priv *priv)
{
struct net_device *net_dev = priv->net_dev;
struct device *dev = net_dev->dev.parent;
int i;
for (i = 0; i < priv->num_channels; i++) {
priv->channel[i]->store =
dpaa2_io_store_create(DPAA2_ETH_STORE_SIZE, dev);
if (!priv->channel[i]->store) {
netdev_err(net_dev, "dpaa2_io_store_create() failed\n");
goto err_ring;
}
}
return 0;
err_ring:
for (i = 0; i < priv->num_channels; i++) {
if (!priv->channel[i]->store)
break;
dpaa2_io_store_destroy(priv->channel[i]->store);
}
return -ENOMEM;
}
static void free_rings(struct dpaa2_eth_priv *priv)
{
int i;
for (i = 0; i < priv->num_channels; i++)
dpaa2_io_store_destroy(priv->channel[i]->store);
}
static int set_mac_addr(struct dpaa2_eth_priv *priv)
{
struct net_device *net_dev = priv->net_dev;
struct device *dev = net_dev->dev.parent;
u8 mac_addr[ETH_ALEN], dpni_mac_addr[ETH_ALEN];
int err;
err = dpni_get_port_mac_addr(priv->mc_io, 0, priv->mc_token, mac_addr);
if (err) {
dev_err(dev, "dpni_get_port_mac_addr() failed\n");
return err;
}
err = dpni_get_primary_mac_addr(priv->mc_io, 0, priv->mc_token,
dpni_mac_addr);
if (err) {
dev_err(dev, "dpni_get_primary_mac_addr() failed\n");
return err;
}
if (!is_zero_ether_addr(mac_addr)) {
if (!ether_addr_equal(mac_addr, dpni_mac_addr)) {
err = dpni_set_primary_mac_addr(priv->mc_io, 0,
priv->mc_token,
mac_addr);
if (err) {
dev_err(dev, "dpni_set_primary_mac_addr() failed\n");
return err;
}
}
memcpy(net_dev->dev_addr, mac_addr, net_dev->addr_len);
} else if (is_zero_ether_addr(dpni_mac_addr)) {
eth_hw_addr_random(net_dev);
dev_dbg_once(dev, "device(s) have all-zero hwaddr, replaced with random\n");
err = dpni_set_primary_mac_addr(priv->mc_io, 0, priv->mc_token,
net_dev->dev_addr);
if (err) {
dev_err(dev, "dpni_set_primary_mac_addr() failed\n");
return err;
}
net_dev->addr_assign_type = NET_ADDR_PERM;
} else {
memcpy(net_dev->dev_addr, dpni_mac_addr, net_dev->addr_len);
}
return 0;
}
static int netdev_init(struct net_device *net_dev)
{
struct device *dev = net_dev->dev.parent;
struct dpaa2_eth_priv *priv = netdev_priv(net_dev);
u8 bcast_addr[ETH_ALEN];
u8 num_queues;
int err;
net_dev->netdev_ops = &dpaa2_eth_ops;
err = set_mac_addr(priv);
if (err)
return err;
eth_broadcast_addr(bcast_addr);
err = dpni_add_mac_addr(priv->mc_io, 0, priv->mc_token, bcast_addr);
if (err) {
dev_err(dev, "dpni_add_mac_addr() failed\n");
return err;
}
net_dev->needed_headroom = DPAA2_ETH_NEEDED_HEADROOM(priv);
net_dev->min_mtu = 68;
net_dev->max_mtu = DPAA2_ETH_MAX_MTU;
num_queues = dpaa2_eth_queue_count(priv);
err = netif_set_real_num_tx_queues(net_dev, num_queues);
if (err) {
dev_err(dev, "netif_set_real_num_tx_queues() failed\n");
return err;
}
err = netif_set_real_num_rx_queues(net_dev, num_queues);
if (err) {
dev_err(dev, "netif_set_real_num_rx_queues() failed\n");
return err;
}
err = register_netdev(net_dev);
if (err < 0) {
dev_err(dev, "register_netdev() failed\n");
return err;
}
return 0;
}
static int poll_link_state(void *arg)
{
struct dpaa2_eth_priv *priv = (struct dpaa2_eth_priv *)arg;
int err;
while (!kthread_should_stop()) {
err = link_state_update(priv);
if (unlikely(err))
return err;
msleep(DPAA2_ETH_LINK_STATE_REFRESH);
}
return 0;
}
static irqreturn_t dpni_irq0_handler(int irq_num, void *arg)
{
return IRQ_WAKE_THREAD;
}
static irqreturn_t dpni_irq0_handler_thread(int irq_num, void *arg)
{
u32 status = 0, clear = 0;
struct device *dev = (struct device *)arg;
struct fsl_mc_device *dpni_dev = to_fsl_mc_device(dev);
struct net_device *net_dev = dev_get_drvdata(dev);
int err;
err = dpni_get_irq_status(dpni_dev->mc_io, 0, dpni_dev->mc_handle,
DPNI_IRQ_INDEX, &status);
if (unlikely(err)) {
netdev_err(net_dev, "Can't get irq status (err %d)\n", err);
clear = 0xffffffff;
goto out;
}
if (status & DPNI_IRQ_EVENT_LINK_CHANGED) {
clear |= DPNI_IRQ_EVENT_LINK_CHANGED;
link_state_update(netdev_priv(net_dev));
}
out:
dpni_clear_irq_status(dpni_dev->mc_io, 0, dpni_dev->mc_handle,
DPNI_IRQ_INDEX, clear);
return IRQ_HANDLED;
}
static int setup_irqs(struct fsl_mc_device *ls_dev)
{
int err = 0;
struct fsl_mc_device_irq *irq;
err = fsl_mc_allocate_irqs(ls_dev);
if (err) {
dev_err(&ls_dev->dev, "MC irqs allocation failed\n");
return err;
}
irq = ls_dev->irqs[0];
err = devm_request_threaded_irq(&ls_dev->dev, irq->msi_desc->irq,
dpni_irq0_handler,
dpni_irq0_handler_thread,
IRQF_NO_SUSPEND | IRQF_ONESHOT,
dev_name(&ls_dev->dev), &ls_dev->dev);
if (err < 0) {
dev_err(&ls_dev->dev, "devm_request_threaded_irq(): %d\n", err);
goto free_mc_irq;
}
err = dpni_set_irq_mask(ls_dev->mc_io, 0, ls_dev->mc_handle,
DPNI_IRQ_INDEX, DPNI_IRQ_EVENT_LINK_CHANGED);
if (err < 0) {
dev_err(&ls_dev->dev, "dpni_set_irq_mask(): %d\n", err);
goto free_irq;
}
err = dpni_set_irq_enable(ls_dev->mc_io, 0, ls_dev->mc_handle,
DPNI_IRQ_INDEX, 1);
if (err < 0) {
dev_err(&ls_dev->dev, "dpni_set_irq_enable(): %d\n", err);
goto free_irq;
}
return 0;
free_irq:
devm_free_irq(&ls_dev->dev, irq->msi_desc->irq, &ls_dev->dev);
free_mc_irq:
fsl_mc_free_irqs(ls_dev);
return err;
}
static void add_ch_napi(struct dpaa2_eth_priv *priv)
{
int i;
struct dpaa2_eth_channel *ch;
for (i = 0; i < priv->num_channels; i++) {
ch = priv->channel[i];
netif_napi_add(priv->net_dev, &ch->napi, dpaa2_eth_poll,
NAPI_POLL_WEIGHT);
}
}
static void del_ch_napi(struct dpaa2_eth_priv *priv)
{
int i;
struct dpaa2_eth_channel *ch;
for (i = 0; i < priv->num_channels; i++) {
ch = priv->channel[i];
netif_napi_del(&ch->napi);
}
}
static int dpaa2_eth_probe(struct fsl_mc_device *dpni_dev)
{
struct device *dev;
struct net_device *net_dev = NULL;
struct dpaa2_eth_priv *priv = NULL;
int err = 0;
dev = &dpni_dev->dev;
net_dev = alloc_etherdev_mq(sizeof(*priv), DPAA2_ETH_MAX_TX_QUEUES);
if (!net_dev) {
dev_err(dev, "alloc_etherdev_mq() failed\n");
return -ENOMEM;
}
SET_NETDEV_DEV(net_dev, dev);
dev_set_drvdata(dev, net_dev);
priv = netdev_priv(net_dev);
priv->net_dev = net_dev;
priv->iommu_domain = iommu_get_domain_for_dev(dev);
err = fsl_mc_portal_allocate(dpni_dev, FSL_MC_IO_ATOMIC_CONTEXT_PORTAL,
&priv->mc_io);
if (err) {
dev_err(dev, "MC portal allocation failed\n");
goto err_portal_alloc;
}
err = setup_dpni(dpni_dev);
if (err)
goto err_dpni_setup;
err = setup_dpio(priv);
if (err)
goto err_dpio_setup;
setup_fqs(priv);
err = setup_dpbp(priv);
if (err)
goto err_dpbp_setup;
err = bind_dpni(priv);
if (err)
goto err_bind;
add_ch_napi(priv);
priv->percpu_stats = alloc_percpu(*priv->percpu_stats);
if (!priv->percpu_stats) {
dev_err(dev, "alloc_percpu(percpu_stats) failed\n");
err = -ENOMEM;
goto err_alloc_percpu_stats;
}
priv->percpu_extras = alloc_percpu(*priv->percpu_extras);
if (!priv->percpu_extras) {
dev_err(dev, "alloc_percpu(percpu_extras) failed\n");
err = -ENOMEM;
goto err_alloc_percpu_extras;
}
err = netdev_init(net_dev);
if (err)
goto err_netdev_init;
err = set_rx_csum(priv, !!(net_dev->features & NETIF_F_RXCSUM));
if (err)
goto err_csum;
err = set_tx_csum(priv, !!(net_dev->features &
(NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM)));
if (err)
goto err_csum;
err = alloc_rings(priv);
if (err)
goto err_alloc_rings;
net_dev->ethtool_ops = &dpaa2_ethtool_ops;
err = setup_irqs(dpni_dev);
if (err) {
netdev_warn(net_dev, "Failed to set link interrupt, fall back to polling\n");
priv->poll_thread = kthread_run(poll_link_state, priv,
"%s_poll_link", net_dev->name);
if (IS_ERR(priv->poll_thread)) {
netdev_err(net_dev, "Error starting polling thread\n");
goto err_poll_thread;
}
priv->do_link_poll = true;
}
dev_info(dev, "Probed interface %s\n", net_dev->name);
return 0;
err_poll_thread:
free_rings(priv);
err_alloc_rings:
err_csum:
unregister_netdev(net_dev);
err_netdev_init:
free_percpu(priv->percpu_extras);
err_alloc_percpu_extras:
free_percpu(priv->percpu_stats);
err_alloc_percpu_stats:
del_ch_napi(priv);
err_bind:
free_dpbp(priv);
err_dpbp_setup:
free_dpio(priv);
err_dpio_setup:
free_dpni(priv);
err_dpni_setup:
fsl_mc_portal_free(priv->mc_io);
err_portal_alloc:
dev_set_drvdata(dev, NULL);
free_netdev(net_dev);
return err;
}
static int dpaa2_eth_remove(struct fsl_mc_device *ls_dev)
{
struct device *dev;
struct net_device *net_dev;
struct dpaa2_eth_priv *priv;
dev = &ls_dev->dev;
net_dev = dev_get_drvdata(dev);
priv = netdev_priv(net_dev);
unregister_netdev(net_dev);
dev_info(net_dev->dev.parent, "Removed interface %s\n", net_dev->name);
if (priv->do_link_poll)
kthread_stop(priv->poll_thread);
else
fsl_mc_free_irqs(ls_dev);
free_rings(priv);
free_percpu(priv->percpu_stats);
free_percpu(priv->percpu_extras);
del_ch_napi(priv);
free_dpbp(priv);
free_dpio(priv);
free_dpni(priv);
fsl_mc_portal_free(priv->mc_io);
dev_set_drvdata(dev, NULL);
free_netdev(net_dev);
return 0;
}
