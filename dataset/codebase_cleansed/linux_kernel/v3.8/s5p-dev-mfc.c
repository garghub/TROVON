void __init s5p_mfc_reserve_mem(phys_addr_t rbase, unsigned int rsize,
phys_addr_t lbase, unsigned int lsize)
{
int i;
s5p_mfc_mem[0].dev = &s5p_device_mfc_r.dev;
s5p_mfc_mem[0].base = rbase;
s5p_mfc_mem[0].size = rsize;
s5p_mfc_mem[1].dev = &s5p_device_mfc_l.dev;
s5p_mfc_mem[1].base = lbase;
s5p_mfc_mem[1].size = lsize;
for (i = 0; i < ARRAY_SIZE(s5p_mfc_mem); i++) {
struct s5p_mfc_reserved_mem *area = &s5p_mfc_mem[i];
if (memblock_remove(area->base, area->size)) {
printk(KERN_ERR "Failed to reserve memory for MFC device (%ld bytes at 0x%08lx)\n",
area->size, (unsigned long) area->base);
area->base = 0;
}
}
}
static int __init s5p_mfc_memory_init(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(s5p_mfc_mem); i++) {
struct s5p_mfc_reserved_mem *area = &s5p_mfc_mem[i];
if (!area->base)
continue;
if (dma_declare_coherent_memory(area->dev, area->base,
area->base, area->size,
DMA_MEMORY_MAP | DMA_MEMORY_EXCLUSIVE) == 0)
printk(KERN_ERR "Failed to declare coherent memory for MFC device (%ld bytes at 0x%08lx)\n",
area->size, (unsigned long) area->base);
}
return 0;
}
int __init s5p_fdt_find_mfc_mem(unsigned long node, const char *uname,
int depth, void *data)
{
__be32 *prop;
unsigned long len;
struct s5p_mfc_dt_meminfo *mfc_mem = data;
if (!data)
return 0;
if (!of_flat_dt_is_compatible(node, mfc_mem->compatible))
return 0;
prop = of_get_flat_dt_prop(node, "samsung,mfc-l", &len);
if (!prop || (len != 2 * sizeof(unsigned long)))
return 0;
mfc_mem->loff = be32_to_cpu(prop[0]);
mfc_mem->lsize = be32_to_cpu(prop[1]);
prop = of_get_flat_dt_prop(node, "samsung,mfc-r", &len);
if (!prop || (len != 2 * sizeof(unsigned long)))
return 0;
mfc_mem->roff = be32_to_cpu(prop[0]);
mfc_mem->rsize = be32_to_cpu(prop[1]);
return 1;
}
