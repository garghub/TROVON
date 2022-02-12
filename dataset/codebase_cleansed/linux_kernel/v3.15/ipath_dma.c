static int ipath_mapping_error(struct ib_device *dev, u64 dma_addr)
{
return dma_addr == BAD_DMA_ADDRESS;
}
static u64 ipath_dma_map_single(struct ib_device *dev,
void *cpu_addr, size_t size,
enum dma_data_direction direction)
{
BUG_ON(!valid_dma_direction(direction));
return (u64) cpu_addr;
}
static void ipath_dma_unmap_single(struct ib_device *dev,
u64 addr, size_t size,
enum dma_data_direction direction)
{
BUG_ON(!valid_dma_direction(direction));
}
static u64 ipath_dma_map_page(struct ib_device *dev,
struct page *page,
unsigned long offset,
size_t size,
enum dma_data_direction direction)
{
u64 addr;
BUG_ON(!valid_dma_direction(direction));
if (offset + size > PAGE_SIZE) {
addr = BAD_DMA_ADDRESS;
goto done;
}
addr = (u64) page_address(page);
if (addr)
addr += offset;
done:
return addr;
}
static void ipath_dma_unmap_page(struct ib_device *dev,
u64 addr, size_t size,
enum dma_data_direction direction)
{
BUG_ON(!valid_dma_direction(direction));
}
static int ipath_map_sg(struct ib_device *dev, struct scatterlist *sgl,
int nents, enum dma_data_direction direction)
{
struct scatterlist *sg;
u64 addr;
int i;
int ret = nents;
BUG_ON(!valid_dma_direction(direction));
for_each_sg(sgl, sg, nents, i) {
addr = (u64) page_address(sg_page(sg));
if (!addr) {
ret = 0;
break;
}
sg->dma_address = addr + sg->offset;
#ifdef CONFIG_NEED_SG_DMA_LENGTH
sg->dma_length = sg->length;
#endif
}
return ret;
}
static void ipath_unmap_sg(struct ib_device *dev,
struct scatterlist *sg, int nents,
enum dma_data_direction direction)
{
BUG_ON(!valid_dma_direction(direction));
}
static void ipath_sync_single_for_cpu(struct ib_device *dev,
u64 addr,
size_t size,
enum dma_data_direction dir)
{
}
static void ipath_sync_single_for_device(struct ib_device *dev,
u64 addr,
size_t size,
enum dma_data_direction dir)
{
}
static void *ipath_dma_alloc_coherent(struct ib_device *dev, size_t size,
u64 *dma_handle, gfp_t flag)
{
struct page *p;
void *addr = NULL;
p = alloc_pages(flag, get_order(size));
if (p)
addr = page_address(p);
if (dma_handle)
*dma_handle = (u64) addr;
return addr;
}
static void ipath_dma_free_coherent(struct ib_device *dev, size_t size,
void *cpu_addr, u64 dma_handle)
{
free_pages((unsigned long) cpu_addr, get_order(size));
}
