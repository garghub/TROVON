static inline void __iomem *iram_phys_to_virt(unsigned long p)
{
return iram_virt_base + (p - iram_phys_base);
}
void __iomem *iram_alloc(unsigned int size, unsigned long *dma_addr)
{
if (!iram_pool)
return NULL;
*dma_addr = gen_pool_alloc(iram_pool, size);
pr_debug("iram alloc - %dB@0x%lX\n", size, *dma_addr);
if (!*dma_addr)
return NULL;
return iram_phys_to_virt(*dma_addr);
}
void iram_free(unsigned long addr, unsigned int size)
{
if (!iram_pool)
return;
gen_pool_free(iram_pool, addr, size);
}
int __init iram_init(unsigned long base, unsigned long size)
{
iram_phys_base = base;
iram_pool = gen_pool_create(PAGE_SHIFT, -1);
if (!iram_pool)
return -ENOMEM;
gen_pool_add(iram_pool, base, size, -1);
iram_virt_base = ioremap(iram_phys_base, size);
if (!iram_virt_base)
return -EIO;
pr_debug("i.MX IRAM pool: %ld KB@0x%p\n", size / 1024, iram_virt_base);
return 0;
}
