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
if (unlikely(p->des01.tx.heartbeat_fail)) {
x->tx_heartbeat++;
stats->tx_heartbeat_errors++;
ret = -1;
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
int ret = csum_none;
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
if (unlikely(p->des01.rx.partial_frame_error))
x->rx_partial++;
if (unlikely(p->des01.rx.run_frame))
x->rx_runt++;
if (unlikely(p->des01.rx.frame_too_long))
x->rx_toolong++;
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
ret = discard_frame;
if (unlikely(p->des01.rx.length_error)) {
x->rx_length++;
ret = discard_frame;
}
if (unlikely(p->des01.rx.mii_error)) {
x->rx_mii++;
ret = discard_frame;
}
if (p->des01.rx.multicast_frame) {
x->rx_multicast++;
stats->multicast++;
}
return ret;
}
static void ndesc_init_rx_desc(struct dma_desc *p, unsigned int ring_size,
int disable_rx_ic)
{
int i;
for (i = 0; i < ring_size; i++) {
p->des01.rx.own = 1;
p->des01.rx.buffer1_size = BUF_SIZE_2KiB - 1;
if (i == ring_size - 1)
p->des01.rx.end_ring = 1;
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
if (i == ring_size - 1)
p->des01.tx.end_ring = 1;
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
p->des01.tx.end_ring = ter;
}
static void ndesc_prepare_tx_desc(struct dma_desc *p, int is_fs, int len,
int csum_flag)
{
p->des01.tx.first_segment = is_fs;
p->des01.tx.buffer1_size = len;
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
