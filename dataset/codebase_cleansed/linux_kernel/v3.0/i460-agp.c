static int i460_fetch_size (void)
{
int i;
u8 temp;
struct aper_size_info_8 *values;
pci_read_config_byte(agp_bridge->dev, INTEL_I460_GXBCTL, &temp);
i460.io_page_shift = (temp & I460_4M_PS) ? 22 : 12;
pr_debug("i460_fetch_size: io_page_shift=%d\n", i460.io_page_shift);
if (i460.io_page_shift != I460_IO_PAGE_SHIFT) {
printk(KERN_ERR PFX
"I/O (GART) page-size %luKB doesn't match expected "
"size %luKB\n",
1UL << (i460.io_page_shift - 10),
1UL << (I460_IO_PAGE_SHIFT));
return 0;
}
values = A_SIZE_8(agp_bridge->driver->aperture_sizes);
pci_read_config_byte(agp_bridge->dev, INTEL_I460_AGPSIZ, &temp);
if (temp & I460_SRAM_IO_DISABLE) {
printk(KERN_ERR PFX "GART SRAMS disabled on 460GX chipset\n");
printk(KERN_ERR PFX "AGPGART operation not possible\n");
return 0;
}
if ((i460.io_page_shift == 0) && ((temp & I460_AGPSIZ_MASK) == 4)) {
printk(KERN_ERR PFX "We can't have a 32GB aperture with 4KB GART pages\n");
return 0;
}
if (temp & I460_BAPBASE_ENABLE)
i460.dynamic_apbase = INTEL_I460_BAPBASE;
else
i460.dynamic_apbase = AGP_APBASE;
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
values[i].num_entries = (values[i].size << 8) >> (I460_IO_PAGE_SHIFT - 12);
values[i].page_order = ilog2((sizeof(u32)*values[i].num_entries) >> PAGE_SHIFT);
}
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
if ((temp & I460_AGPSIZ_MASK) == values[i].size_value) {
agp_bridge->previous_size = agp_bridge->current_size = (void *) (values + i);
agp_bridge->aperture_size_idx = i;
return values[i].size;
}
}
return 0;
}
static void i460_tlb_flush (struct agp_memory *mem)
{
return;
}
static void i460_write_agpsiz (u8 size_value)
{
u8 temp;
pci_read_config_byte(agp_bridge->dev, INTEL_I460_AGPSIZ, &temp);
pci_write_config_byte(agp_bridge->dev, INTEL_I460_AGPSIZ,
((temp & ~I460_AGPSIZ_MASK) | size_value));
}
static void i460_cleanup (void)
{
struct aper_size_info_8 *previous_size;
previous_size = A_SIZE_8(agp_bridge->previous_size);
i460_write_agpsiz(previous_size->size_value);
if (I460_IO_PAGE_SHIFT > PAGE_SHIFT)
kfree(i460.lp_desc);
}
static int i460_configure (void)
{
union {
u32 small[2];
u64 large;
} temp;
size_t size;
u8 scratch;
struct aper_size_info_8 *current_size;
temp.large = 0;
current_size = A_SIZE_8(agp_bridge->current_size);
i460_write_agpsiz(current_size->size_value);
pci_read_config_dword(agp_bridge->dev, i460.dynamic_apbase, &(temp.small[0]));
pci_read_config_dword(agp_bridge->dev, i460.dynamic_apbase + 4, &(temp.small[1]));
agp_bridge->gart_bus_addr = temp.large & ~((1UL << 3) - 1);
pci_read_config_byte(agp_bridge->dev, INTEL_I460_GXBCTL, &scratch);
pci_write_config_byte(agp_bridge->dev, INTEL_I460_GXBCTL,
(scratch & 0x02) | I460_GXBCTL_OOG | I460_GXBCTL_BWC);
if (I460_IO_PAGE_SHIFT > PAGE_SHIFT) {
size = current_size->num_entries * sizeof(i460.lp_desc[0]);
i460.lp_desc = kzalloc(size, GFP_KERNEL);
if (!i460.lp_desc)
return -ENOMEM;
}
return 0;
}
static int i460_create_gatt_table (struct agp_bridge_data *bridge)
{
int page_order, num_entries, i;
void *temp;
temp = agp_bridge->current_size;
page_order = A_SIZE_8(temp)->page_order;
num_entries = A_SIZE_8(temp)->num_entries;
i460.gatt = ioremap(INTEL_I460_ATTBASE, PAGE_SIZE << page_order);
if (!i460.gatt) {
printk(KERN_ERR PFX "ioremap failed\n");
return -ENOMEM;
}
agp_bridge->gatt_table_real = NULL;
agp_bridge->gatt_table = NULL;
agp_bridge->gatt_bus_addr = 0;
for (i = 0; i < num_entries; ++i)
WR_GATT(i, 0);
WR_FLUSH_GATT(i - 1);
return 0;
}
static int i460_free_gatt_table (struct agp_bridge_data *bridge)
{
int num_entries, i;
void *temp;
temp = agp_bridge->current_size;
num_entries = A_SIZE_8(temp)->num_entries;
for (i = 0; i < num_entries; ++i)
WR_GATT(i, 0);
WR_FLUSH_GATT(num_entries - 1);
iounmap(i460.gatt);
return 0;
}
static int i460_insert_memory_small_io_page (struct agp_memory *mem,
off_t pg_start, int type)
{
unsigned long paddr, io_pg_start, io_page_size;
int i, j, k, num_entries;
void *temp;
pr_debug("i460_insert_memory_small_io_page(mem=%p, pg_start=%ld, type=%d, paddr0=0x%lx)\n",
mem, pg_start, type, page_to_phys(mem->pages[0]));
if (type >= AGP_USER_TYPES || mem->type >= AGP_USER_TYPES)
return -EINVAL;
io_pg_start = I460_IOPAGES_PER_KPAGE * pg_start;
temp = agp_bridge->current_size;
num_entries = A_SIZE_8(temp)->num_entries;
if ((io_pg_start + I460_IOPAGES_PER_KPAGE * mem->page_count) > num_entries) {
printk(KERN_ERR PFX "Looks like we're out of AGP memory\n");
return -EINVAL;
}
j = io_pg_start;
while (j < (io_pg_start + I460_IOPAGES_PER_KPAGE * mem->page_count)) {
if (!PGE_EMPTY(agp_bridge, RD_GATT(j))) {
pr_debug("i460_insert_memory_small_io_page: GATT[%d]=0x%x is busy\n",
j, RD_GATT(j));
return -EBUSY;
}
j++;
}
io_page_size = 1UL << I460_IO_PAGE_SHIFT;
for (i = 0, j = io_pg_start; i < mem->page_count; i++) {
paddr = page_to_phys(mem->pages[i]);
for (k = 0; k < I460_IOPAGES_PER_KPAGE; k++, j++, paddr += io_page_size)
WR_GATT(j, i460_mask_memory(agp_bridge, paddr, mem->type));
}
WR_FLUSH_GATT(j - 1);
return 0;
}
static int i460_remove_memory_small_io_page(struct agp_memory *mem,
off_t pg_start, int type)
{
int i;
pr_debug("i460_remove_memory_small_io_page(mem=%p, pg_start=%ld, type=%d)\n",
mem, pg_start, type);
pg_start = I460_IOPAGES_PER_KPAGE * pg_start;
for (i = pg_start; i < (pg_start + I460_IOPAGES_PER_KPAGE * mem->page_count); i++)
WR_GATT(i, 0);
WR_FLUSH_GATT(i - 1);
return 0;
}
static int i460_alloc_large_page (struct lp_desc *lp)
{
unsigned long order = I460_IO_PAGE_SHIFT - PAGE_SHIFT;
size_t map_size;
lp->page = alloc_pages(GFP_KERNEL, order);
if (!lp->page) {
printk(KERN_ERR PFX "Couldn't alloc 4M GART page...\n");
return -ENOMEM;
}
map_size = ((I460_KPAGES_PER_IOPAGE + BITS_PER_LONG - 1) & -BITS_PER_LONG)/8;
lp->alloced_map = kzalloc(map_size, GFP_KERNEL);
if (!lp->alloced_map) {
__free_pages(lp->page, order);
printk(KERN_ERR PFX "Out of memory, we're in trouble...\n");
return -ENOMEM;
}
lp->paddr = page_to_phys(lp->page);
lp->refcount = 0;
atomic_add(I460_KPAGES_PER_IOPAGE, &agp_bridge->current_memory_agp);
return 0;
}
static void i460_free_large_page (struct lp_desc *lp)
{
kfree(lp->alloced_map);
lp->alloced_map = NULL;
__free_pages(lp->page, I460_IO_PAGE_SHIFT - PAGE_SHIFT);
atomic_sub(I460_KPAGES_PER_IOPAGE, &agp_bridge->current_memory_agp);
}
static int i460_insert_memory_large_io_page (struct agp_memory *mem,
off_t pg_start, int type)
{
int i, start_offset, end_offset, idx, pg, num_entries;
struct lp_desc *start, *end, *lp;
void *temp;
if (type >= AGP_USER_TYPES || mem->type >= AGP_USER_TYPES)
return -EINVAL;
temp = agp_bridge->current_size;
num_entries = A_SIZE_8(temp)->num_entries;
start = &i460.lp_desc[pg_start / I460_KPAGES_PER_IOPAGE];
end = &i460.lp_desc[(pg_start + mem->page_count - 1) / I460_KPAGES_PER_IOPAGE];
start_offset = pg_start % I460_KPAGES_PER_IOPAGE;
end_offset = (pg_start + mem->page_count - 1) % I460_KPAGES_PER_IOPAGE;
if (end > i460.lp_desc + num_entries) {
printk(KERN_ERR PFX "Looks like we're out of AGP memory\n");
return -EINVAL;
}
for (lp = start; lp <= end; ++lp) {
if (!lp->alloced_map)
continue;
for (idx = ((lp == start) ? start_offset : 0);
idx < ((lp == end) ? (end_offset + 1) : I460_KPAGES_PER_IOPAGE);
idx++)
{
if (test_bit(idx, lp->alloced_map))
return -EBUSY;
}
}
for (lp = start, i = 0; lp <= end; ++lp) {
if (!lp->alloced_map) {
if (i460_alloc_large_page(lp) < 0)
return -ENOMEM;
pg = lp - i460.lp_desc;
WR_GATT(pg, i460_mask_memory(agp_bridge,
lp->paddr, 0));
WR_FLUSH_GATT(pg);
}
for (idx = ((lp == start) ? start_offset : 0);
idx < ((lp == end) ? (end_offset + 1) : I460_KPAGES_PER_IOPAGE);
idx++, i++)
{
mem->pages[i] = lp->page;
__set_bit(idx, lp->alloced_map);
++lp->refcount;
}
}
return 0;
}
static int i460_remove_memory_large_io_page (struct agp_memory *mem,
off_t pg_start, int type)
{
int i, pg, start_offset, end_offset, idx, num_entries;
struct lp_desc *start, *end, *lp;
void *temp;
temp = agp_bridge->current_size;
num_entries = A_SIZE_8(temp)->num_entries;
start = &i460.lp_desc[pg_start / I460_KPAGES_PER_IOPAGE];
end = &i460.lp_desc[(pg_start + mem->page_count - 1) / I460_KPAGES_PER_IOPAGE];
start_offset = pg_start % I460_KPAGES_PER_IOPAGE;
end_offset = (pg_start + mem->page_count - 1) % I460_KPAGES_PER_IOPAGE;
for (i = 0, lp = start; lp <= end; ++lp) {
for (idx = ((lp == start) ? start_offset : 0);
idx < ((lp == end) ? (end_offset + 1) : I460_KPAGES_PER_IOPAGE);
idx++, i++)
{
mem->pages[i] = NULL;
__clear_bit(idx, lp->alloced_map);
--lp->refcount;
}
if (lp->refcount == 0) {
pg = lp - i460.lp_desc;
WR_GATT(pg, 0);
WR_FLUSH_GATT(pg);
i460_free_large_page(lp);
}
}
return 0;
}
static int i460_insert_memory (struct agp_memory *mem,
off_t pg_start, int type)
{
if (I460_IO_PAGE_SHIFT <= PAGE_SHIFT)
return i460_insert_memory_small_io_page(mem, pg_start, type);
else
return i460_insert_memory_large_io_page(mem, pg_start, type);
}
static int i460_remove_memory (struct agp_memory *mem,
off_t pg_start, int type)
{
if (I460_IO_PAGE_SHIFT <= PAGE_SHIFT)
return i460_remove_memory_small_io_page(mem, pg_start, type);
else
return i460_remove_memory_large_io_page(mem, pg_start, type);
}
static struct page *i460_alloc_page (struct agp_bridge_data *bridge)
{
void *page;
if (I460_IO_PAGE_SHIFT <= PAGE_SHIFT) {
page = agp_generic_alloc_page(agp_bridge);
} else
page = (void *)~0UL;
return page;
}
static void i460_destroy_page (struct page *page, int flags)
{
if (I460_IO_PAGE_SHIFT <= PAGE_SHIFT) {
agp_generic_destroy_page(page, flags);
}
}
static unsigned long i460_mask_memory (struct agp_bridge_data *bridge,
dma_addr_t addr, int type)
{
return bridge->driver->masks[0].mask
| (((addr & ~((1 << I460_IO_PAGE_SHIFT) - 1)) & 0xfffff000) >> 12);
}
static int __devinit agp_intel_i460_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct agp_bridge_data *bridge;
u8 cap_ptr;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->driver = &intel_i460_driver;
bridge->dev = pdev;
bridge->capndx = cap_ptr;
printk(KERN_INFO PFX "Detected Intel 460GX chipset\n");
pci_set_drvdata(pdev, bridge);
return agp_add_bridge(bridge);
}
static void __devexit agp_intel_i460_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
}
static int __init agp_intel_i460_init(void)
{
if (agp_off)
return -EINVAL;
return pci_register_driver(&agp_intel_i460_pci_driver);
}
static void __exit agp_intel_i460_cleanup(void)
{
pci_unregister_driver(&agp_intel_i460_pci_driver);
}
