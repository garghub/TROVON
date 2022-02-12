struct gen_pool *sram_get_gen_pool(void)
{
return sram_pool;
}
void *sram_alloc(size_t len, dma_addr_t *dma)
{
unsigned long vaddr;
dma_addr_t dma_base = davinci_soc_info.sram_dma;
if (dma)
*dma = 0;
if (!sram_pool || (dma && !dma_base))
return NULL;
vaddr = gen_pool_alloc(sram_pool, len);
if (!vaddr)
return NULL;
if (dma)
*dma = gen_pool_virt_to_phys(sram_pool, vaddr);
return (void *)vaddr;
}
void sram_free(void *addr, size_t len)
{
gen_pool_free(sram_pool, (unsigned long) addr, len);
}
static int __init sram_init(void)
{
phys_addr_t phys = davinci_soc_info.sram_dma;
unsigned len = davinci_soc_info.sram_len;
int status = 0;
void *addr;
if (len) {
len = min_t(unsigned, len, SRAM_SIZE);
sram_pool = gen_pool_create(ilog2(SRAM_GRANULARITY), -1);
if (!sram_pool)
status = -ENOMEM;
}
if (sram_pool) {
addr = ioremap(phys, len);
if (!addr)
return -ENOMEM;
status = gen_pool_add_virt(sram_pool, (unsigned)addr,
phys, len, -1);
if (status < 0)
iounmap(addr);
}
WARN_ON(status < 0);
return status;
}
