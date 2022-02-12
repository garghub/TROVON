static inline void tegra_ivc_invalidate(struct tegra_ivc *ivc, dma_addr_t phys)
{
if (!ivc->peer)
return;
dma_sync_single_for_cpu(ivc->peer, phys, TEGRA_IVC_ALIGN,
DMA_FROM_DEVICE);
}
static inline void tegra_ivc_flush(struct tegra_ivc *ivc, dma_addr_t phys)
{
if (!ivc->peer)
return;
dma_sync_single_for_device(ivc->peer, phys, TEGRA_IVC_ALIGN,
DMA_TO_DEVICE);
}
static inline bool tegra_ivc_empty(struct tegra_ivc *ivc,
struct tegra_ivc_header *header)
{
u32 tx = ACCESS_ONCE(header->tx.count);
u32 rx = ACCESS_ONCE(header->rx.count);
if (tx - rx > ivc->num_frames)
return true;
return tx == rx;
}
static inline bool tegra_ivc_full(struct tegra_ivc *ivc,
struct tegra_ivc_header *header)
{
u32 tx = ACCESS_ONCE(header->tx.count);
u32 rx = ACCESS_ONCE(header->rx.count);
return tx - rx >= ivc->num_frames;
}
static inline u32 tegra_ivc_available(struct tegra_ivc *ivc,
struct tegra_ivc_header *header)
{
u32 tx = ACCESS_ONCE(header->tx.count);
u32 rx = ACCESS_ONCE(header->rx.count);
return tx - rx;
}
static inline void tegra_ivc_advance_tx(struct tegra_ivc *ivc)
{
ACCESS_ONCE(ivc->tx.channel->tx.count) =
ACCESS_ONCE(ivc->tx.channel->tx.count) + 1;
if (ivc->tx.position == ivc->num_frames - 1)
ivc->tx.position = 0;
else
ivc->tx.position++;
}
static inline void tegra_ivc_advance_rx(struct tegra_ivc *ivc)
{
ACCESS_ONCE(ivc->rx.channel->rx.count) =
ACCESS_ONCE(ivc->rx.channel->rx.count) + 1;
if (ivc->rx.position == ivc->num_frames - 1)
ivc->rx.position = 0;
else
ivc->rx.position++;
}
static inline int tegra_ivc_check_read(struct tegra_ivc *ivc)
{
unsigned int offset = offsetof(struct tegra_ivc_header, tx.count);
if (ivc->tx.channel->tx.state != TEGRA_IVC_STATE_ESTABLISHED)
return -ECONNRESET;
if (!tegra_ivc_empty(ivc, ivc->rx.channel))
return 0;
tegra_ivc_invalidate(ivc, ivc->rx.phys + offset);
if (tegra_ivc_empty(ivc, ivc->rx.channel))
return -ENOSPC;
return 0;
}
static inline int tegra_ivc_check_write(struct tegra_ivc *ivc)
{
unsigned int offset = offsetof(struct tegra_ivc_header, rx.count);
if (ivc->tx.channel->tx.state != TEGRA_IVC_STATE_ESTABLISHED)
return -ECONNRESET;
if (!tegra_ivc_full(ivc, ivc->tx.channel))
return 0;
tegra_ivc_invalidate(ivc, ivc->tx.phys + offset);
if (tegra_ivc_full(ivc, ivc->tx.channel))
return -ENOSPC;
return 0;
}
static void *tegra_ivc_frame_virt(struct tegra_ivc *ivc,
struct tegra_ivc_header *header,
unsigned int frame)
{
if (WARN_ON(frame >= ivc->num_frames))
return ERR_PTR(-EINVAL);
return (void *)(header + 1) + ivc->frame_size * frame;
}
static inline dma_addr_t tegra_ivc_frame_phys(struct tegra_ivc *ivc,
dma_addr_t phys,
unsigned int frame)
{
unsigned long offset;
offset = sizeof(struct tegra_ivc_header) + ivc->frame_size * frame;
return phys + offset;
}
static inline void tegra_ivc_invalidate_frame(struct tegra_ivc *ivc,
dma_addr_t phys,
unsigned int frame,
unsigned int offset,
size_t size)
{
if (!ivc->peer || WARN_ON(frame >= ivc->num_frames))
return;
phys = tegra_ivc_frame_phys(ivc, phys, frame) + offset;
dma_sync_single_for_cpu(ivc->peer, phys, size, DMA_FROM_DEVICE);
}
static inline void tegra_ivc_flush_frame(struct tegra_ivc *ivc,
dma_addr_t phys,
unsigned int frame,
unsigned int offset,
size_t size)
{
if (!ivc->peer || WARN_ON(frame >= ivc->num_frames))
return;
phys = tegra_ivc_frame_phys(ivc, phys, frame) + offset;
dma_sync_single_for_device(ivc->peer, phys, size, DMA_TO_DEVICE);
}
void *tegra_ivc_read_get_next_frame(struct tegra_ivc *ivc)
{
int err;
if (WARN_ON(ivc == NULL))
return ERR_PTR(-EINVAL);
err = tegra_ivc_check_read(ivc);
if (err < 0)
return ERR_PTR(err);
smp_rmb();
tegra_ivc_invalidate_frame(ivc, ivc->rx.phys, ivc->rx.position, 0,
ivc->frame_size);
return tegra_ivc_frame_virt(ivc, ivc->rx.channel, ivc->rx.position);
}
int tegra_ivc_read_advance(struct tegra_ivc *ivc)
{
unsigned int rx = offsetof(struct tegra_ivc_header, rx.count);
unsigned int tx = offsetof(struct tegra_ivc_header, tx.count);
int err;
err = tegra_ivc_check_read(ivc);
if (err < 0)
return err;
tegra_ivc_advance_rx(ivc);
tegra_ivc_flush(ivc, ivc->rx.phys + rx);
smp_mb();
tegra_ivc_invalidate(ivc, ivc->rx.phys + tx);
if (tegra_ivc_available(ivc, ivc->rx.channel) == ivc->num_frames - 1)
ivc->notify(ivc, ivc->notify_data);
return 0;
}
void *tegra_ivc_write_get_next_frame(struct tegra_ivc *ivc)
{
int err;
err = tegra_ivc_check_write(ivc);
if (err < 0)
return ERR_PTR(err);
return tegra_ivc_frame_virt(ivc, ivc->tx.channel, ivc->tx.position);
}
int tegra_ivc_write_advance(struct tegra_ivc *ivc)
{
unsigned int tx = offsetof(struct tegra_ivc_header, tx.count);
unsigned int rx = offsetof(struct tegra_ivc_header, rx.count);
int err;
err = tegra_ivc_check_write(ivc);
if (err < 0)
return err;
tegra_ivc_flush_frame(ivc, ivc->tx.phys, ivc->tx.position, 0,
ivc->frame_size);
smp_wmb();
tegra_ivc_advance_tx(ivc);
tegra_ivc_flush(ivc, ivc->tx.phys + tx);
smp_mb();
tegra_ivc_invalidate(ivc, ivc->tx.phys + rx);
if (tegra_ivc_available(ivc, ivc->tx.channel) == 1)
ivc->notify(ivc, ivc->notify_data);
return 0;
}
void tegra_ivc_reset(struct tegra_ivc *ivc)
{
unsigned int offset = offsetof(struct tegra_ivc_header, tx.count);
ivc->tx.channel->tx.state = TEGRA_IVC_STATE_SYNC;
tegra_ivc_flush(ivc, ivc->tx.phys + offset);
ivc->notify(ivc, ivc->notify_data);
}
int tegra_ivc_notified(struct tegra_ivc *ivc)
{
unsigned int offset = offsetof(struct tegra_ivc_header, tx.count);
enum tegra_ivc_state state;
tegra_ivc_invalidate(ivc, ivc->rx.phys + offset);
state = ACCESS_ONCE(ivc->rx.channel->tx.state);
if (state == TEGRA_IVC_STATE_SYNC) {
offset = offsetof(struct tegra_ivc_header, tx.count);
smp_rmb();
ivc->tx.channel->tx.count = 0;
ivc->rx.channel->rx.count = 0;
ivc->tx.position = 0;
ivc->rx.position = 0;
smp_wmb();
ivc->tx.channel->tx.state = TEGRA_IVC_STATE_ACK;
tegra_ivc_flush(ivc, ivc->tx.phys + offset);
ivc->notify(ivc, ivc->notify_data);
} else if (ivc->tx.channel->tx.state == TEGRA_IVC_STATE_SYNC &&
state == TEGRA_IVC_STATE_ACK) {
offset = offsetof(struct tegra_ivc_header, tx.count);
smp_rmb();
ivc->tx.channel->tx.count = 0;
ivc->rx.channel->rx.count = 0;
ivc->tx.position = 0;
ivc->rx.position = 0;
smp_wmb();
ivc->tx.channel->tx.state = TEGRA_IVC_STATE_ESTABLISHED;
tegra_ivc_flush(ivc, ivc->tx.phys + offset);
ivc->notify(ivc, ivc->notify_data);
} else if (ivc->tx.channel->tx.state == TEGRA_IVC_STATE_ACK) {
offset = offsetof(struct tegra_ivc_header, tx.count);
smp_rmb();
ivc->tx.channel->tx.state = TEGRA_IVC_STATE_ESTABLISHED;
tegra_ivc_flush(ivc, ivc->tx.phys + offset);
ivc->notify(ivc, ivc->notify_data);
} else {
}
if (ivc->tx.channel->tx.state != TEGRA_IVC_STATE_ESTABLISHED)
return -EAGAIN;
return 0;
}
size_t tegra_ivc_align(size_t size)
{
return ALIGN(size, TEGRA_IVC_ALIGN);
}
unsigned tegra_ivc_total_queue_size(unsigned queue_size)
{
if (!IS_ALIGNED(queue_size, TEGRA_IVC_ALIGN)) {
pr_err("%s: queue_size (%u) must be %u-byte aligned\n",
__func__, queue_size, TEGRA_IVC_ALIGN);
return 0;
}
return queue_size + sizeof(struct tegra_ivc_header);
}
static int tegra_ivc_check_params(unsigned long rx, unsigned long tx,
unsigned int num_frames, size_t frame_size)
{
BUILD_BUG_ON(!IS_ALIGNED(offsetof(struct tegra_ivc_header, tx.count),
TEGRA_IVC_ALIGN));
BUILD_BUG_ON(!IS_ALIGNED(offsetof(struct tegra_ivc_header, rx.count),
TEGRA_IVC_ALIGN));
BUILD_BUG_ON(!IS_ALIGNED(sizeof(struct tegra_ivc_header),
TEGRA_IVC_ALIGN));
if ((uint64_t)num_frames * (uint64_t)frame_size >= 0x100000000UL) {
pr_err("num_frames * frame_size overflows\n");
return -EINVAL;
}
if (!IS_ALIGNED(frame_size, TEGRA_IVC_ALIGN)) {
pr_err("frame size not adequately aligned: %zu\n", frame_size);
return -EINVAL;
}
if (!IS_ALIGNED(rx, TEGRA_IVC_ALIGN)) {
pr_err("IVC channel start not aligned: %#lx\n", rx);
return -EINVAL;
}
if (!IS_ALIGNED(tx, TEGRA_IVC_ALIGN)) {
pr_err("IVC channel start not aligned: %#lx\n", tx);
return -EINVAL;
}
if (rx < tx) {
if (rx + frame_size * num_frames > tx) {
pr_err("queue regions overlap: %#lx + %zx > %#lx\n",
rx, frame_size * num_frames, tx);
return -EINVAL;
}
} else {
if (tx + frame_size * num_frames > rx) {
pr_err("queue regions overlap: %#lx + %zx > %#lx\n",
tx, frame_size * num_frames, rx);
return -EINVAL;
}
}
return 0;
}
int tegra_ivc_init(struct tegra_ivc *ivc, struct device *peer, void *rx,
dma_addr_t rx_phys, void *tx, dma_addr_t tx_phys,
unsigned int num_frames, size_t frame_size,
void (*notify)(struct tegra_ivc *ivc, void *data),
void *data)
{
size_t queue_size;
int err;
if (WARN_ON(!ivc || !notify))
return -EINVAL;
if (frame_size > INT_MAX)
return -E2BIG;
err = tegra_ivc_check_params((unsigned long)rx, (unsigned long)tx,
num_frames, frame_size);
if (err < 0)
return err;
queue_size = tegra_ivc_total_queue_size(num_frames * frame_size);
if (peer) {
ivc->rx.phys = dma_map_single(peer, rx, queue_size,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(peer, ivc->rx.phys))
return -ENOMEM;
ivc->tx.phys = dma_map_single(peer, tx, queue_size,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(peer, ivc->tx.phys)) {
dma_unmap_single(peer, ivc->rx.phys, queue_size,
DMA_BIDIRECTIONAL);
return -ENOMEM;
}
} else {
ivc->rx.phys = rx_phys;
ivc->tx.phys = tx_phys;
}
ivc->rx.channel = rx;
ivc->tx.channel = tx;
ivc->peer = peer;
ivc->notify = notify;
ivc->notify_data = data;
ivc->frame_size = frame_size;
ivc->num_frames = num_frames;
ivc->tx.position = 0;
ivc->rx.position = 0;
return 0;
}
void tegra_ivc_cleanup(struct tegra_ivc *ivc)
{
if (ivc->peer) {
size_t size = tegra_ivc_total_queue_size(ivc->num_frames *
ivc->frame_size);
dma_unmap_single(ivc->peer, ivc->rx.phys, size,
DMA_BIDIRECTIONAL);
dma_unmap_single(ivc->peer, ivc->tx.phys, size,
DMA_BIDIRECTIONAL);
}
}
