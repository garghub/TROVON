static int vmw_gmr2_bind(struct vmw_private *dev_priv,
struct vmw_piter *iter,
unsigned long num_pages,
int gmr_id)
{
SVGAFifoCmdDefineGMR2 define_cmd;
SVGAFifoCmdRemapGMR2 remap_cmd;
uint32_t *cmd;
uint32_t *cmd_orig;
uint32_t define_size = sizeof(define_cmd) + sizeof(*cmd);
uint32_t remap_num = num_pages / VMW_PPN_PER_REMAP + ((num_pages % VMW_PPN_PER_REMAP) > 0);
uint32_t remap_size = VMW_PPN_SIZE * num_pages + (sizeof(remap_cmd) + sizeof(*cmd)) * remap_num;
uint32_t remap_pos = 0;
uint32_t cmd_size = define_size + remap_size;
uint32_t i;
cmd_orig = cmd = vmw_fifo_reserve(dev_priv, cmd_size);
if (unlikely(cmd == NULL))
return -ENOMEM;
define_cmd.gmrId = gmr_id;
define_cmd.numPages = num_pages;
*cmd++ = SVGA_CMD_DEFINE_GMR2;
memcpy(cmd, &define_cmd, sizeof(define_cmd));
cmd += sizeof(define_cmd) / sizeof(*cmd);
remap_cmd.gmrId = gmr_id;
remap_cmd.flags = (VMW_PPN_SIZE > sizeof(*cmd)) ?
SVGA_REMAP_GMR2_PPN64 : SVGA_REMAP_GMR2_PPN32;
while (num_pages > 0) {
unsigned long nr = min(num_pages, (unsigned long)VMW_PPN_PER_REMAP);
remap_cmd.offsetPages = remap_pos;
remap_cmd.numPages = nr;
*cmd++ = SVGA_CMD_REMAP_GMR2;
memcpy(cmd, &remap_cmd, sizeof(remap_cmd));
cmd += sizeof(remap_cmd) / sizeof(*cmd);
for (i = 0; i < nr; ++i) {
if (VMW_PPN_SIZE <= 4)
*cmd = vmw_piter_dma_addr(iter) >> PAGE_SHIFT;
else
*((uint64_t *)cmd) = vmw_piter_dma_addr(iter) >>
PAGE_SHIFT;
cmd += VMW_PPN_SIZE / sizeof(*cmd);
vmw_piter_next(iter);
}
num_pages -= nr;
remap_pos += nr;
}
BUG_ON(cmd != cmd_orig + cmd_size / sizeof(*cmd));
vmw_fifo_commit(dev_priv, cmd_size);
return 0;
}
static void vmw_gmr2_unbind(struct vmw_private *dev_priv,
int gmr_id)
{
SVGAFifoCmdDefineGMR2 define_cmd;
uint32_t define_size = sizeof(define_cmd) + 4;
uint32_t *cmd;
cmd = vmw_fifo_reserve(dev_priv, define_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("GMR2 unbind failed.\n");
return;
}
define_cmd.gmrId = gmr_id;
define_cmd.numPages = 0;
*cmd++ = SVGA_CMD_DEFINE_GMR2;
memcpy(cmd, &define_cmd, sizeof(define_cmd));
vmw_fifo_commit(dev_priv, define_size);
}
static void vmw_gmr_free_descriptors(struct device *dev, dma_addr_t desc_dma,
struct list_head *desc_pages)
{
struct page *page, *next;
struct svga_guest_mem_descriptor *page_virtual;
unsigned int desc_per_page = PAGE_SIZE /
sizeof(struct svga_guest_mem_descriptor) - 1;
if (list_empty(desc_pages))
return;
list_for_each_entry_safe(page, next, desc_pages, lru) {
list_del_init(&page->lru);
if (likely(desc_dma != DMA_ADDR_INVALID)) {
dma_unmap_page(dev, desc_dma, PAGE_SIZE,
DMA_TO_DEVICE);
}
page_virtual = kmap_atomic(page);
desc_dma = (dma_addr_t)
le32_to_cpu(page_virtual[desc_per_page].ppn) <<
PAGE_SHIFT;
kunmap_atomic(page_virtual);
__free_page(page);
}
}
static int vmw_gmr_build_descriptors(struct device *dev,
struct list_head *desc_pages,
struct vmw_piter *iter,
unsigned long num_pages,
dma_addr_t *first_dma)
{
struct page *page;
struct svga_guest_mem_descriptor *page_virtual = NULL;
struct svga_guest_mem_descriptor *desc_virtual = NULL;
unsigned int desc_per_page;
unsigned long prev_pfn;
unsigned long pfn;
int ret;
dma_addr_t desc_dma;
desc_per_page = PAGE_SIZE /
sizeof(struct svga_guest_mem_descriptor) - 1;
while (likely(num_pages != 0)) {
page = alloc_page(__GFP_HIGHMEM);
if (unlikely(page == NULL)) {
ret = -ENOMEM;
goto out_err;
}
list_add_tail(&page->lru, desc_pages);
page_virtual = kmap_atomic(page);
desc_virtual = page_virtual - 1;
prev_pfn = ~(0UL);
while (likely(num_pages != 0)) {
pfn = vmw_piter_dma_addr(iter) >> PAGE_SHIFT;
if (pfn != prev_pfn + 1) {
if (desc_virtual - page_virtual ==
desc_per_page - 1)
break;
(++desc_virtual)->ppn = cpu_to_le32(pfn);
desc_virtual->num_pages = cpu_to_le32(1);
} else {
uint32_t tmp =
le32_to_cpu(desc_virtual->num_pages);
desc_virtual->num_pages = cpu_to_le32(tmp + 1);
}
prev_pfn = pfn;
--num_pages;
vmw_piter_next(iter);
}
(++desc_virtual)->ppn = DMA_PAGE_INVALID;
desc_virtual->num_pages = cpu_to_le32(0);
kunmap_atomic(page_virtual);
}
desc_dma = 0;
list_for_each_entry_reverse(page, desc_pages, lru) {
page_virtual = kmap_atomic(page);
page_virtual[desc_per_page].ppn = cpu_to_le32
(desc_dma >> PAGE_SHIFT);
kunmap_atomic(page_virtual);
desc_dma = dma_map_page(dev, page, 0, PAGE_SIZE,
DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(dev, desc_dma)))
goto out_err;
}
*first_dma = desc_dma;
return 0;
out_err:
vmw_gmr_free_descriptors(dev, DMA_ADDR_INVALID, desc_pages);
return ret;
}
static void vmw_gmr_fire_descriptors(struct vmw_private *dev_priv,
int gmr_id, dma_addr_t desc_dma)
{
mutex_lock(&dev_priv->hw_mutex);
vmw_write(dev_priv, SVGA_REG_GMR_ID, gmr_id);
wmb();
vmw_write(dev_priv, SVGA_REG_GMR_DESCRIPTOR, desc_dma >> PAGE_SHIFT);
mb();
mutex_unlock(&dev_priv->hw_mutex);
}
int vmw_gmr_bind(struct vmw_private *dev_priv,
const struct vmw_sg_table *vsgt,
unsigned long num_pages,
int gmr_id)
{
struct list_head desc_pages;
dma_addr_t desc_dma = 0;
struct device *dev = dev_priv->dev->dev;
struct vmw_piter data_iter;
int ret;
vmw_piter_start(&data_iter, vsgt, 0);
if (unlikely(!vmw_piter_next(&data_iter)))
return 0;
if (likely(dev_priv->capabilities & SVGA_CAP_GMR2))
return vmw_gmr2_bind(dev_priv, &data_iter, num_pages, gmr_id);
if (unlikely(!(dev_priv->capabilities & SVGA_CAP_GMR)))
return -EINVAL;
if (vsgt->num_regions > dev_priv->max_gmr_descriptors)
return -EINVAL;
INIT_LIST_HEAD(&desc_pages);
ret = vmw_gmr_build_descriptors(dev, &desc_pages, &data_iter,
num_pages, &desc_dma);
if (unlikely(ret != 0))
return ret;
vmw_gmr_fire_descriptors(dev_priv, gmr_id, desc_dma);
vmw_gmr_free_descriptors(dev, desc_dma, &desc_pages);
return 0;
}
void vmw_gmr_unbind(struct vmw_private *dev_priv, int gmr_id)
{
if (likely(dev_priv->capabilities & SVGA_CAP_GMR2)) {
vmw_gmr2_unbind(dev_priv, gmr_id);
return;
}
mutex_lock(&dev_priv->hw_mutex);
vmw_write(dev_priv, SVGA_REG_GMR_ID, gmr_id);
wmb();
vmw_write(dev_priv, SVGA_REG_GMR_DESCRIPTOR, 0);
mb();
mutex_unlock(&dev_priv->hw_mutex);
}
