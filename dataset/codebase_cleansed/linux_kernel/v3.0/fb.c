void omapfb_set_platform_data(struct omapfb_platform_data *data)
{
}
static inline int ranges_overlap(unsigned long start1, unsigned long size1,
unsigned long start2, unsigned long size2)
{
return (start1 >= start2 && start1 < start2 + size2) ||
(start2 >= start1 && start2 < start1 + size1);
}
static inline int range_included(unsigned long start1, unsigned long size1,
unsigned long start2, unsigned long size2)
{
return start1 >= start2 && start1 + size1 <= start2 + size2;
}
static int fbmem_region_reserved(unsigned long start, size_t size)
{
struct omapfb_mem_region *rg;
int i;
rg = &omapfb_config.mem_desc.region[0];
for (i = 0; i < OMAPFB_PLANE_NUM; i++, rg++) {
if (!rg->paddr)
continue;
if (ranges_overlap(start, size, rg->paddr, rg->size))
return 1;
}
return 0;
}
static int __init get_fbmem_region(int region_idx, struct omapfb_mem_region *rg)
{
const struct omap_fbmem_config *conf;
u32 paddr;
conf = omap_get_nr_config(OMAP_TAG_FBMEM,
struct omap_fbmem_config, region_idx);
if (conf == NULL)
return -ENOENT;
paddr = conf->start;
memset(rg, 0, sizeof(*rg));
rg->type = paddr & ~PAGE_MASK;
rg->paddr = paddr & PAGE_MASK;
rg->size = PAGE_ALIGN(conf->size);
return 0;
}
static int set_fbmem_region_type(struct omapfb_mem_region *rg, int mem_type,
unsigned long mem_start,
unsigned long mem_size)
{
if (rg->type || !rg->paddr)
return 0;
if (ranges_overlap(rg->paddr, rg->size, mem_start, mem_size)) {
rg->type = mem_type;
return 0;
}
return -1;
}
static int check_fbmem_region(int region_idx, struct omapfb_mem_region *rg,
unsigned long start_avail, unsigned size_avail)
{
unsigned long paddr = rg->paddr;
size_t size = rg->size;
if (rg->type > OMAPFB_MEMTYPE_MAX) {
printk(KERN_ERR
"Invalid start address for FB region %d\n", region_idx);
return -EINVAL;
}
if (!rg->size) {
printk(KERN_ERR "Zero size for FB region %d\n", region_idx);
return -EINVAL;
}
if (!paddr)
return 0;
if (fbmem_region_reserved(paddr, size) ||
!range_included(paddr, size, start_avail, size_avail)) {
printk(KERN_ERR "Trying to use reserved memory "
"for FB region %d\n", region_idx);
return -EINVAL;
}
return 0;
}
static int valid_sdram(unsigned long addr, unsigned long size)
{
return memblock_is_region_memory(addr, size);
}
static int reserve_sdram(unsigned long addr, unsigned long size)
{
if (memblock_is_region_reserved(addr, size))
return -EBUSY;
if (memblock_reserve(addr, size))
return -ENOMEM;
return 0;
}
void __init omapfb_reserve_sdram_memblock(void)
{
unsigned long reserved = 0;
int i;
if (config_invalid)
return;
for (i = 0; ; i++) {
struct omapfb_mem_region rg;
if (get_fbmem_region(i, &rg) < 0)
break;
if (i == OMAPFB_PLANE_NUM) {
pr_err("Extraneous FB mem configuration entries\n");
config_invalid = 1;
return;
}
if (rg.type != OMAPFB_MEMTYPE_SDRAM)
continue;
if (rg.paddr && !valid_sdram(rg.paddr, rg.size))
continue;
if (rg.size == 0) {
pr_err("Zero size for FB region %d\n", i);
config_invalid = 1;
return;
}
if (rg.paddr) {
if (reserve_sdram(rg.paddr, rg.size)) {
pr_err("Trying to use reserved memory for FB region %d\n",
i);
config_invalid = 1;
return;
}
reserved += rg.size;
}
if (omapfb_config.mem_desc.region[i].size) {
pr_err("FB region %d already set\n", i);
config_invalid = 1;
return;
}
omapfb_config.mem_desc.region[i] = rg;
configured_regions++;
}
omapfb_config.mem_desc.region_cnt = i;
if (reserved)
pr_info("Reserving %lu bytes SDRAM for frame buffer\n",
reserved);
}
unsigned long __init omapfb_reserve_sram(unsigned long sram_pstart,
unsigned long sram_vstart,
unsigned long sram_size,
unsigned long pstart_avail,
unsigned long size_avail)
{
struct omapfb_mem_region rg;
unsigned long pend_avail;
unsigned long reserved;
int i;
if (config_invalid)
return 0;
reserved = 0;
pend_avail = pstart_avail + size_avail;
for (i = 0; ; i++) {
if (get_fbmem_region(i, &rg) < 0)
break;
if (i == OMAPFB_PLANE_NUM) {
printk(KERN_ERR
"Extraneous FB mem configuration entries\n");
config_invalid = 1;
return 0;
}
if (set_fbmem_region_type(&rg, OMAPFB_MEMTYPE_SRAM,
sram_pstart, sram_size) < 0 ||
(rg.type != OMAPFB_MEMTYPE_SRAM))
continue;
BUG_ON(omapfb_config.mem_desc.region[i].size);
if (check_fbmem_region(i, &rg, pstart_avail, size_avail) < 0) {
config_invalid = 1;
return 0;
}
if (!rg.paddr) {
if ((size_avail & PAGE_MASK) < rg.size) {
printk("Not enough SRAM for FB region %d\n",
i);
config_invalid = 1;
return 0;
}
size_avail = (size_avail - rg.size) & PAGE_MASK;
rg.paddr = pstart_avail + size_avail;
}
if (pend_avail - rg.paddr > reserved)
reserved = pend_avail - rg.paddr;
size_avail = pend_avail - reserved - pstart_avail;
rg.vaddr = (void *)(sram_vstart + rg.paddr - sram_pstart);
omapfb_config.mem_desc.region[i] = rg;
configured_regions++;
}
omapfb_config.mem_desc.region_cnt = i;
if (reserved)
pr_info("Reserving %lu bytes SRAM for frame buffer\n",
reserved);
return reserved;
}
void omapfb_set_ctrl_platform_data(void *data)
{
omapfb_config.ctrl_platform_data = data;
}
static int __init omap_init_fb(void)
{
const struct omap_lcd_config *conf;
if (config_invalid)
return 0;
if (configured_regions != omapfb_config.mem_desc.region_cnt) {
printk(KERN_ERR "Invalid FB mem configuration entries\n");
return 0;
}
conf = omap_get_config(OMAP_TAG_LCD, struct omap_lcd_config);
if (conf == NULL) {
if (configured_regions)
printk(KERN_ERR "Missing LCD configuration\n");
return 0;
}
omapfb_config.lcd = *conf;
return platform_device_register(&omap_fb_device);
}
void omapfb_set_platform_data(struct omapfb_platform_data *data)
{
omapfb_config = *data;
}
static int __init omap_init_fb(void)
{
return platform_device_register(&omap_fb_device);
}
void omapfb_reserve_sdram_memblock(void)
{
}
unsigned long __init omapfb_reserve_sram(unsigned long sram_pstart,
unsigned long sram_vstart,
unsigned long sram_size,
unsigned long start_avail,
unsigned long size_avail)
{
return 0;
}
void omapfb_set_platform_data(struct omapfb_platform_data *data)
{
}
void omapfb_reserve_sdram_memblock(void)
{
}
unsigned long __init omapfb_reserve_sram(unsigned long sram_pstart,
unsigned long sram_vstart,
unsigned long sram_size,
unsigned long start_avail,
unsigned long size_avail)
{
return 0;
}
