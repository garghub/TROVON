static int ndesc_get_tx_status(void *data, struct stmmac_extra_stats *x,
struct dma_desc *p, void __iomem *ioaddr)
{
int ret = 0;
struct net_device_stats *stats = (struct net_device_stats *)data;
if (unlikely(p->des01.tx.error_summary)) {
if (unlikely(p->des01.tx.underflow_error)) {
x->tx_underflow++;
stats->tx_fifo_errors++;
}
if (unlikely(p->des01.tx.no_carrier)) {
x->tx_carrier++;
stats->tx_carrier_errors++;
}
if (unlikely(p->des01.tx.loss_carrier)) {
x->tx_losscarrier++;
stats->tx_carrier_errors++;
}
if (unlikely((p->des01.tx.excessive_deferral) ||
(p->des01.tx.excessive_collisions) ||
(p->des01.tx.late_collision)))
stats->collisions += p->des01.tx.collision_count;
ret = -1;
}
if (p->des01.etx.vlan_frame) {
CHIP_DBG(KERN_INFO "GMAC TX status: VLAN frame\n");
x->tx_vlan++;
}
if (unlikely(p->des01.tx.deferred))
x->tx_deferred++;
return ret;
}
static int ndesc_get_tx_len(struct dma_desc *p)
{
return p->des01.tx.buffer1_size;
}
static int ndesc_get_rx_status(void *data, struct stmmac_extra_stats *x,
struct dma_desc *p)
{
int ret = good_frame;
struct net_device_stats *stats = (struct net_device_stats *)data;
if (unlikely(p->des01.rx.last_descriptor == 0)) {
pr_warning("ndesc Error: Oversized Ethernet "
"frame spanned multiple buffers\n");
stats->rx_length_errors++;
return discard_frame;
}
if (unlikely(p->des01.rx.error_summary)) {
if (unlikely(p->des01.rx.descriptor_error))
x->rx_desc++;
if (unlikely(p->des01.rx.sa_filter_fail))
x->sa_filter_fail++;
if (unlikely(p->des01.rx.overflow_error))
x->overflow_error++;
if (unlikely(p->des01.rx.ipc_csum_error))
x->ipc_csum_error++;
if (unlikely(p->des01.rx.collision)) {
x->rx_collision++;
stats->collisions++;
}
if (unlikely(p->des01.rx.crc_error)) {
x->rx_crc++;
stats->rx_crc_errors++;
}
ret = discard_frame;
}
if (unlikely(p->des01.rx.dribbling))
x->dribbling_bit++;
if (unlikely(p->des01.rx.length_error)) {
x->rx_length++;
ret = discard_frame;
}
if (unlikely(p->des01.rx.mii_error)) {
x->rx_mii++;
ret = discard_frame;
}
#ifdef STMMAC_VLAN_TAG_USED
if (p->des01.rx.vlan_tag)
x->vlan_tag++;
#endif
return ret;
}
static void ndesc_init_rx_desc(struct dma_desc *p, unsigned int ring_size,
int disable_rx_ic)
{
int i;
for (i = 0; i < ring_size; i++) {
p->des01.rx.own = 1;
p->des01.rx.buffer1_size = BUF_SIZE_2KiB - 1;
ndesc_rx_set_on_ring_chain(p, (i == ring_size - 1));
if (disable_rx_ic)
p->des01.rx.disable_ic = 1;
p++;
}
}
static void ndesc_init_tx_desc(struct dma_desc *p, unsigned int ring_size)
{
int i;
for (i = 0; i < ring_size; i++) {
p->des01.tx.own = 0;
ndesc_tx_set_on_ring_chain(p, (i == (ring_size - 1)));
p++;
}
}
static int ndesc_get_tx_owner(struct dma_desc *p)
{
return p->des01.tx.own;
}
static int ndesc_get_rx_owner(struct dma_desc *p)
{
return p->des01.rx.own;
}
static void ndesc_set_tx_owner(struct dma_desc *p)
{
p->des01.tx.own = 1;
}
static void ndesc_set_rx_owner(struct dma_desc *p)
{
p->des01.rx.own = 1;
}
static int ndesc_get_tx_ls(struct dma_desc *p)
{
return p->des01.tx.last_segment;
}
static void ndesc_release_tx_desc(struct dma_desc *p)
{
int ter = p->des01.tx.end_ring;
memset(p, 0, offsetof(struct dma_desc, des2));
ndesc_end_tx_desc(p, ter);
}
static void ndesc_prepare_tx_desc(struct dma_desc *p, int is_fs, int len,
int csum_flag)
{
p->des01.tx.first_segment = is_fs;
norm_set_tx_desc_len(p, len);
if (likely(csum_flag))
p->des01.tx.checksum_insertion = cic_full;
}
static void ndesc_clear_tx_ic(struct dma_desc *p)
{
p->des01.tx.interrupt = 0;
}
static void ndesc_close_tx_desc(struct dma_desc *p)
{
p->des01.tx.last_segment = 1;
p->des01.tx.interrupt = 1;
}
static int ndesc_get_rx_frame_len(struct dma_desc *p)
{
return p->des01.rx.frame_length;
}
