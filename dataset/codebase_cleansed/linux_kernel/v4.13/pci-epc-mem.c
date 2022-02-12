int pci_epc_mem_init(struct pci_epc *epc, phys_addr_t phys_base, size_t size)
{
int ret;
struct pci_epc_mem *mem;
unsigned long *bitmap;
int pages = size >> PAGE_SHIFT;
int bitmap_size = BITS_TO_LONGS(pages) * sizeof(long);
mem = kzalloc(sizeof(*mem), GFP_KERNEL);
if (!mem) {
ret = -ENOMEM;
goto err;
}
bitmap = kzalloc(bitmap_size, GFP_KERNEL);
if (!bitmap) {
ret = -ENOMEM;
goto err_mem;
}
mem->bitmap = bitmap;
mem->phys_base = phys_base;
mem->pages = pages;
mem->size = size;
epc->mem = mem;
return 0;
err_mem:
kfree(mem);
err:
return ret;
}
void pci_epc_mem_exit(struct pci_epc *epc)
{
struct pci_epc_mem *mem = epc->mem;
epc->mem = NULL;
kfree(mem->bitmap);
kfree(mem);
}
void __iomem *pci_epc_mem_alloc_addr(struct pci_epc *epc,
phys_addr_t *phys_addr, size_t size)
{
int pageno;
void __iomem *virt_addr;
struct pci_epc_mem *mem = epc->mem;
int order = get_order(size);
pageno = bitmap_find_free_region(mem->bitmap, mem->pages, order);
if (pageno < 0)
return NULL;
*phys_addr = mem->phys_base + (pageno << PAGE_SHIFT);
virt_addr = ioremap(*phys_addr, size);
if (!virt_addr)
bitmap_release_region(mem->bitmap, pageno, order);
return virt_addr;
}
void pci_epc_mem_free_addr(struct pci_epc *epc, phys_addr_t phys_addr,
void __iomem *virt_addr, size_t size)
{
int pageno;
int order = get_order(size);
struct pci_epc_mem *mem = epc->mem;
iounmap(virt_addr);
pageno = (phys_addr - mem->phys_base) >> PAGE_SHIFT;
bitmap_release_region(mem->bitmap, pageno, order);
}
