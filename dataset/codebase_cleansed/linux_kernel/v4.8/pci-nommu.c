static int
check_addr(char *name, struct device *hwdev, dma_addr_t bus, size_t size)
{
if (hwdev && !dma_capable(hwdev, bus, size)) {
if (*hwdev->dma_mask >= DMA_BIT_MASK(32))
printk(KERN_ERR
"nommu_%s: overflow %Lx+%zu of device mask %Lx\n",
name, (long long)bus, size,
(long long)*hwdev->dma_mask);
return 0;
}
return 1;
}
static dma_addr_t nommu_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
unsigned long attrs)
{
dma_addr_t bus = page_to_phys(page) + offset;
WARN_ON(size == 0);
if (!check_addr("map_single", dev, bus, size))
return DMA_ERROR_CODE;
flush_write_buffers();
return bus;
}
static int nommu_map_sg(struct device *hwdev, struct scatterlist *sg,
int nents, enum dma_data_direction dir,
unsigned long attrs)
{
struct scatterlist *s;
int i;
WARN_ON(nents == 0 || sg[0].length == 0);
for_each_sg(sg, s, nents, i) {
BUG_ON(!sg_page(s));
s->dma_address = sg_phys(s);
if (!check_addr("map_sg", hwdev, s->dma_address, s->length))
return 0;
s->dma_length = s->length;
}
flush_write_buffers();
return nents;
}
static void nommu_sync_single_for_device(struct device *dev,
dma_addr_t addr, size_t size,
enum dma_data_direction dir)
{
flush_write_buffers();
}
static void nommu_sync_sg_for_device(struct device *dev,
struct scatterlist *sg, int nelems,
enum dma_data_direction dir)
{
flush_write_buffers();
}
