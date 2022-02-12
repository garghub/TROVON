void *snd_malloc_pages(size_t size, gfp_t gfp_flags)
{
int pg;
if (WARN_ON(!size))
return NULL;
if (WARN_ON(!gfp_flags))
return NULL;
gfp_flags |= __GFP_COMP;
pg = get_order(size);
return (void *) __get_free_pages(gfp_flags, pg);
}
void snd_free_pages(void *ptr, size_t size)
{
int pg;
if (ptr == NULL)
return;
pg = get_order(size);
free_pages((unsigned long) ptr, pg);
}
static void *snd_malloc_dev_pages(struct device *dev, size_t size, dma_addr_t *dma)
{
int pg;
gfp_t gfp_flags;
if (WARN_ON(!dma))
return NULL;
pg = get_order(size);
gfp_flags = GFP_KERNEL
| __GFP_COMP
| __GFP_NORETRY
| __GFP_NOWARN;
return dma_alloc_coherent(dev, PAGE_SIZE << pg, dma, gfp_flags);
}
static void snd_free_dev_pages(struct device *dev, size_t size, void *ptr,
dma_addr_t dma)
{
int pg;
if (ptr == NULL)
return;
pg = get_order(size);
dma_free_coherent(dev, PAGE_SIZE << pg, ptr, dma);
}
static void snd_malloc_dev_iram(struct snd_dma_buffer *dmab, size_t size)
{
struct device *dev = dmab->dev.dev;
struct gen_pool *pool = NULL;
dmab->area = NULL;
dmab->addr = 0;
if (dev->of_node)
pool = of_gen_pool_get(dev->of_node, "iram", 0);
if (!pool)
return;
dmab->private_data = pool;
dmab->area = gen_pool_dma_alloc(pool, size, &dmab->addr);
}
static void snd_free_dev_iram(struct snd_dma_buffer *dmab)
{
struct gen_pool *pool = dmab->private_data;
if (pool && dmab->area)
gen_pool_free(pool, (unsigned long)dmab->area, dmab->bytes);
}
int snd_dma_alloc_pages(int type, struct device *device, size_t size,
struct snd_dma_buffer *dmab)
{
if (WARN_ON(!size))
return -ENXIO;
if (WARN_ON(!dmab))
return -ENXIO;
dmab->dev.type = type;
dmab->dev.dev = device;
dmab->bytes = 0;
switch (type) {
case SNDRV_DMA_TYPE_CONTINUOUS:
dmab->area = snd_malloc_pages(size,
(__force gfp_t)(unsigned long)device);
dmab->addr = 0;
break;
#ifdef CONFIG_HAS_DMA
#ifdef CONFIG_GENERIC_ALLOCATOR
case SNDRV_DMA_TYPE_DEV_IRAM:
snd_malloc_dev_iram(dmab, size);
if (dmab->area)
break;
dmab->dev.type = SNDRV_DMA_TYPE_DEV;
#endif
case SNDRV_DMA_TYPE_DEV:
dmab->area = snd_malloc_dev_pages(device, size, &dmab->addr);
break;
#endif
#ifdef CONFIG_SND_DMA_SGBUF
case SNDRV_DMA_TYPE_DEV_SG:
snd_malloc_sgbuf_pages(device, size, dmab, NULL);
break;
#endif
default:
pr_err("snd-malloc: invalid device type %d\n", type);
dmab->area = NULL;
dmab->addr = 0;
return -ENXIO;
}
if (! dmab->area)
return -ENOMEM;
dmab->bytes = size;
return 0;
}
int snd_dma_alloc_pages_fallback(int type, struct device *device, size_t size,
struct snd_dma_buffer *dmab)
{
int err;
while ((err = snd_dma_alloc_pages(type, device, size, dmab)) < 0) {
size_t aligned_size;
if (err != -ENOMEM)
return err;
if (size <= PAGE_SIZE)
return -ENOMEM;
aligned_size = PAGE_SIZE << get_order(size);
if (size != aligned_size)
size = aligned_size;
else
size >>= 1;
}
if (! dmab->area)
return -ENOMEM;
return 0;
}
void snd_dma_free_pages(struct snd_dma_buffer *dmab)
{
switch (dmab->dev.type) {
case SNDRV_DMA_TYPE_CONTINUOUS:
snd_free_pages(dmab->area, dmab->bytes);
break;
#ifdef CONFIG_HAS_DMA
#ifdef CONFIG_GENERIC_ALLOCATOR
case SNDRV_DMA_TYPE_DEV_IRAM:
snd_free_dev_iram(dmab);
break;
#endif
case SNDRV_DMA_TYPE_DEV:
snd_free_dev_pages(dmab->dev.dev, dmab->bytes, dmab->area, dmab->addr);
break;
#endif
#ifdef CONFIG_SND_DMA_SGBUF
case SNDRV_DMA_TYPE_DEV_SG:
snd_free_sgbuf_pages(dmab);
break;
#endif
default:
pr_err("snd-malloc: invalid device type %d\n", dmab->dev.type);
}
}
