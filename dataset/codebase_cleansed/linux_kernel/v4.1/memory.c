u16 i2o_sg_tablesize(struct i2o_controller *c, u16 body_size)
{
i2o_status_block *sb = c->status_block.virt;
u16 sg_count =
(sb->inbound_frame_size - sizeof(struct i2o_message) / 4) -
body_size;
if (c->pae_support) {
sg_count -= 2;
sg_count /= 3;
} else
sg_count /= 2;
if (c->short_req && (sg_count > 8))
sg_count = 8;
return sg_count;
}
dma_addr_t i2o_dma_map_single(struct i2o_controller *c, void *ptr,
size_t size,
enum dma_data_direction direction,
u32 ** sg_ptr)
{
u32 sg_flags;
u32 *mptr = *sg_ptr;
dma_addr_t dma_addr;
switch (direction) {
case DMA_TO_DEVICE:
sg_flags = 0xd4000000;
break;
case DMA_FROM_DEVICE:
sg_flags = 0xd0000000;
break;
default:
return 0;
}
dma_addr = dma_map_single(&c->pdev->dev, ptr, size, direction);
if (!dma_mapping_error(&c->pdev->dev, dma_addr)) {
#ifdef CONFIG_I2O_EXT_ADAPTEC_DMA64
if ((sizeof(dma_addr_t) > 4) && c->pae_support) {
*mptr++ = cpu_to_le32(0x7C020002);
*mptr++ = cpu_to_le32(PAGE_SIZE);
}
#endif
*mptr++ = cpu_to_le32(sg_flags | size);
*mptr++ = cpu_to_le32(i2o_dma_low(dma_addr));
#ifdef CONFIG_I2O_EXT_ADAPTEC_DMA64
if ((sizeof(dma_addr_t) > 4) && c->pae_support)
*mptr++ = cpu_to_le32(i2o_dma_high(dma_addr));
#endif
*sg_ptr = mptr;
}
return dma_addr;
}
int i2o_dma_map_sg(struct i2o_controller *c, struct scatterlist *sg,
int sg_count, enum dma_data_direction direction, u32 ** sg_ptr)
{
u32 sg_flags;
u32 *mptr = *sg_ptr;
switch (direction) {
case DMA_TO_DEVICE:
sg_flags = 0x14000000;
break;
case DMA_FROM_DEVICE:
sg_flags = 0x10000000;
break;
default:
return 0;
}
sg_count = dma_map_sg(&c->pdev->dev, sg, sg_count, direction);
if (!sg_count)
return 0;
#ifdef CONFIG_I2O_EXT_ADAPTEC_DMA64
if ((sizeof(dma_addr_t) > 4) && c->pae_support) {
*mptr++ = cpu_to_le32(0x7C020002);
*mptr++ = cpu_to_le32(PAGE_SIZE);
}
#endif
while (sg_count-- > 0) {
if (!sg_count)
sg_flags |= 0xC0000000;
*mptr++ = cpu_to_le32(sg_flags | sg_dma_len(sg));
*mptr++ = cpu_to_le32(i2o_dma_low(sg_dma_address(sg)));
#ifdef CONFIG_I2O_EXT_ADAPTEC_DMA64
if ((sizeof(dma_addr_t) > 4) && c->pae_support)
*mptr++ = cpu_to_le32(i2o_dma_high(sg_dma_address(sg)));
#endif
sg = sg_next(sg);
}
*sg_ptr = mptr;
return 1;
}
int i2o_dma_alloc(struct device *dev, struct i2o_dma *addr, size_t len)
{
struct pci_dev *pdev = to_pci_dev(dev);
int dma_64 = 0;
mutex_lock(&mem_lock);
if ((sizeof(dma_addr_t) > 4) && (pdev->dma_mask == DMA_BIT_MASK(64))) {
dma_64 = 1;
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
mutex_unlock(&mem_lock);
return -ENOMEM;
}
}
addr->virt = dma_alloc_coherent(dev, len, &addr->phys, GFP_KERNEL);
if ((sizeof(dma_addr_t) > 4) && dma_64)
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64)))
printk(KERN_WARNING "i2o: unable to set 64-bit DMA");
mutex_unlock(&mem_lock);
if (!addr->virt)
return -ENOMEM;
memset(addr->virt, 0, len);
addr->len = len;
return 0;
}
void i2o_dma_free(struct device *dev, struct i2o_dma *addr)
{
if (addr->virt) {
if (addr->phys)
dma_free_coherent(dev, addr->len, addr->virt,
addr->phys);
else
kfree(addr->virt);
addr->virt = NULL;
}
}
int i2o_dma_realloc(struct device *dev, struct i2o_dma *addr, size_t len)
{
i2o_dma_free(dev, addr);
if (len)
return i2o_dma_alloc(dev, addr, len);
return 0;
}
int i2o_pool_alloc(struct i2o_pool *pool, const char *name,
size_t size, int min_nr)
{
pool->name = kstrdup(name, GFP_KERNEL);
if (!pool->name)
goto exit;
pool->slab =
kmem_cache_create(pool->name, size, 0, SLAB_HWCACHE_ALIGN, NULL);
if (!pool->slab)
goto free_name;
pool->mempool = mempool_create_slab_pool(min_nr, pool->slab);
if (!pool->mempool)
goto free_slab;
return 0;
free_slab:
kmem_cache_destroy(pool->slab);
free_name:
kfree(pool->name);
exit:
return -ENOMEM;
}
void i2o_pool_free(struct i2o_pool *pool)
{
mempool_destroy(pool->mempool);
kmem_cache_destroy(pool->slab);
kfree(pool->name);
}
