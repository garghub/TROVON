static struct coh901318_lli *
coh901318_lli_next(struct coh901318_lli *data)
{
if (data == NULL || data->link_addr == 0)
return NULL;
return (struct coh901318_lli *) data->virt_link_addr;
}
int coh901318_pool_create(struct coh901318_pool *pool,
struct device *dev,
size_t size, size_t align)
{
spin_lock_init(&pool->lock);
pool->dev = dev;
pool->dmapool = dma_pool_create("lli_pool", dev, size, align, 0);
DEBUGFS_POOL_COUNTER_RESET(pool);
return 0;
}
int coh901318_pool_destroy(struct coh901318_pool *pool)
{
dma_pool_destroy(pool->dmapool);
return 0;
}
struct coh901318_lli *
coh901318_lli_alloc(struct coh901318_pool *pool, unsigned int len)
{
int i;
struct coh901318_lli *head;
struct coh901318_lli *lli;
struct coh901318_lli *lli_prev;
dma_addr_t phy;
if (len == 0)
goto err;
spin_lock(&pool->lock);
head = dma_pool_alloc(pool->dmapool, GFP_NOWAIT, &phy);
if (head == NULL)
goto err;
DEBUGFS_POOL_COUNTER_ADD(pool, 1);
lli = head;
lli->phy_this = phy;
lli->link_addr = 0x00000000;
lli->virt_link_addr = 0x00000000U;
for (i = 1; i < len; i++) {
lli_prev = lli;
lli = dma_pool_alloc(pool->dmapool, GFP_NOWAIT, &phy);
if (lli == NULL)
goto err_clean_up;
DEBUGFS_POOL_COUNTER_ADD(pool, 1);
lli->phy_this = phy;
lli->link_addr = 0x00000000;
lli->virt_link_addr = 0x00000000U;
lli_prev->link_addr = phy;
lli_prev->virt_link_addr = lli;
}
spin_unlock(&pool->lock);
return head;
err:
spin_unlock(&pool->lock);
return NULL;
err_clean_up:
lli_prev->link_addr = 0x00000000U;
spin_unlock(&pool->lock);
coh901318_lli_free(pool, &head);
return NULL;
}
void coh901318_lli_free(struct coh901318_pool *pool,
struct coh901318_lli **lli)
{
struct coh901318_lli *l;
struct coh901318_lli *next;
if (lli == NULL)
return;
l = *lli;
if (l == NULL)
return;
spin_lock(&pool->lock);
while (l->link_addr) {
next = l->virt_link_addr;
dma_pool_free(pool->dmapool, l, l->phy_this);
DEBUGFS_POOL_COUNTER_ADD(pool, -1);
l = next;
}
dma_pool_free(pool->dmapool, l, l->phy_this);
DEBUGFS_POOL_COUNTER_ADD(pool, -1);
spin_unlock(&pool->lock);
*lli = NULL;
}
int
coh901318_lli_fill_memcpy(struct coh901318_pool *pool,
struct coh901318_lli *lli,
dma_addr_t source, unsigned int size,
dma_addr_t destination, u32 ctrl_chained,
u32 ctrl_eom)
{
int s = size;
dma_addr_t src = source;
dma_addr_t dst = destination;
lli->src_addr = src;
lli->dst_addr = dst;
while (lli->link_addr) {
lli->control = ctrl_chained | MAX_DMA_PACKET_SIZE;
lli->src_addr = src;
lli->dst_addr = dst;
s -= MAX_DMA_PACKET_SIZE;
lli = coh901318_lli_next(lli);
src += MAX_DMA_PACKET_SIZE;
dst += MAX_DMA_PACKET_SIZE;
}
lli->control = ctrl_eom | s;
lli->src_addr = src;
lli->dst_addr = dst;
return 0;
}
int
coh901318_lli_fill_single(struct coh901318_pool *pool,
struct coh901318_lli *lli,
dma_addr_t buf, unsigned int size,
dma_addr_t dev_addr, u32 ctrl_chained, u32 ctrl_eom,
enum dma_transfer_direction dir)
{
int s = size;
dma_addr_t src;
dma_addr_t dst;
if (dir == DMA_MEM_TO_DEV) {
src = buf;
dst = dev_addr;
} else if (dir == DMA_DEV_TO_MEM) {
src = dev_addr;
dst = buf;
} else {
return -EINVAL;
}
while (lli->link_addr) {
size_t block_size = MAX_DMA_PACKET_SIZE;
lli->control = ctrl_chained | MAX_DMA_PACKET_SIZE;
if (s < (MAX_DMA_PACKET_SIZE + MAX_DMA_PACKET_SIZE/2))
block_size = MAX_DMA_PACKET_SIZE/2;
s -= block_size;
lli->src_addr = src;
lli->dst_addr = dst;
lli = coh901318_lli_next(lli);
if (dir == DMA_MEM_TO_DEV)
src += block_size;
else if (dir == DMA_DEV_TO_MEM)
dst += block_size;
}
lli->control = ctrl_eom | s;
lli->src_addr = src;
lli->dst_addr = dst;
return 0;
}
int
coh901318_lli_fill_sg(struct coh901318_pool *pool,
struct coh901318_lli *lli,
struct scatterlist *sgl, unsigned int nents,
dma_addr_t dev_addr, u32 ctrl_chained, u32 ctrl,
u32 ctrl_last,
enum dma_transfer_direction dir, u32 ctrl_irq_mask)
{
int i;
struct scatterlist *sg;
u32 ctrl_sg;
dma_addr_t src = 0;
dma_addr_t dst = 0;
u32 bytes_to_transfer;
u32 elem_size;
if (lli == NULL)
goto err;
spin_lock(&pool->lock);
if (dir == DMA_MEM_TO_DEV)
dst = dev_addr;
else if (dir == DMA_DEV_TO_MEM)
src = dev_addr;
else
goto err;
for_each_sg(sgl, sg, nents, i) {
if (sg_is_chain(sg)) {
ctrl_sg = ctrl_chained;
} else if (i == nents - 1)
ctrl_sg = ctrl_last;
else
ctrl_sg = ctrl ? ctrl : ctrl_last;
if (dir == DMA_MEM_TO_DEV)
src = sg_dma_address(sg);
else
dst = sg_dma_address(sg);
bytes_to_transfer = sg_dma_len(sg);
while (bytes_to_transfer) {
u32 val;
if (bytes_to_transfer > MAX_DMA_PACKET_SIZE) {
elem_size = MAX_DMA_PACKET_SIZE;
val = ctrl_chained;
} else {
elem_size = bytes_to_transfer;
val = ctrl_sg;
}
lli->control = val | elem_size;
lli->src_addr = src;
lli->dst_addr = dst;
if (dir == DMA_DEV_TO_MEM)
dst += elem_size;
else
src += elem_size;
BUG_ON(lli->link_addr & 3);
bytes_to_transfer -= elem_size;
lli = coh901318_lli_next(lli);
}
}
spin_unlock(&pool->lock);
return 0;
err:
spin_unlock(&pool->lock);
return -EINVAL;
}
