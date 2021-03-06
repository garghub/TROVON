static inline unsigned int iga_inb(struct iga_par *par, unsigned int reg,
unsigned int idx)
{
pci_outb(par, idx, reg);
return pci_inb(par, reg + 1);
}
static inline void iga_outb(struct iga_par *par, unsigned char val,
unsigned int reg, unsigned int idx )
{
pci_outb(par, idx, reg);
pci_outb(par, val, reg+1);
}
static void iga_blank_border(struct iga_par *par)
{
int i;
#if 0
(void) pci_inb(par, 0x3DA);
pci_outb(par, IGA_IDX_VGA_OVERSCAN, IGA_ATTR_CTL);
(void) pci_inb(par, IGA_ATTR_CTL+1);
pci_outb(par, 0x38, IGA_ATTR_CTL);
pci_outb(par, 0x20, IGA_ATTR_CTL);
#endif
for (i=0; i < 3; i++)
iga_outb(par, 0, IGA_EXT_CNTRL, IGA_IDX_OVERSCAN_COLOR + i);
}
static int igafb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
struct iga_par *par = (struct iga_par *)info->par;
unsigned int size, page, map_size = 0;
unsigned long map_offset = 0;
int i;
if (!par->mmap_map)
return -ENXIO;
size = vma->vm_end - vma->vm_start;
for (page = 0; page < size; ) {
map_size = 0;
for (i = 0; par->mmap_map[i].size; i++) {
unsigned long start = par->mmap_map[i].voff;
unsigned long end = start + par->mmap_map[i].size;
unsigned long offset = (vma->vm_pgoff << PAGE_SHIFT) + page;
if (start > offset)
continue;
if (offset >= end)
continue;
map_size = par->mmap_map[i].size - (offset - start);
map_offset = par->mmap_map[i].poff + (offset - start);
break;
}
if (!map_size) {
page += PAGE_SIZE;
continue;
}
if (page + map_size > size)
map_size = size - page;
pgprot_val(vma->vm_page_prot) &= ~(par->mmap_map[i].prot_mask);
pgprot_val(vma->vm_page_prot) |= par->mmap_map[i].prot_flag;
if (remap_pfn_range(vma, vma->vm_start + page,
map_offset >> PAGE_SHIFT, map_size, vma->vm_page_prot))
return -EAGAIN;
page += map_size;
}
if (!map_size)
return -EINVAL;
vma->vm_flags |= VM_IO;
return 0;
}
static int igafb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct iga_par *par = (struct iga_par *)info->par;
if (regno >= info->cmap.len)
return 1;
pci_outb(par, regno, DAC_W_INDEX);
pci_outb(par, red, DAC_DATA);
pci_outb(par, green, DAC_DATA);
pci_outb(par, blue, DAC_DATA);
if (regno < 16) {
switch (info->var.bits_per_pixel) {
case 16:
((u16*)(info->pseudo_palette))[regno] =
(regno << 10) | (regno << 5) | regno;
break;
case 24:
((u32*)(info->pseudo_palette))[regno] =
(regno << 16) | (regno << 8) | regno;
break;
case 32:
{ int i;
i = (regno << 8) | regno;
((u32*)(info->pseudo_palette))[regno] = (i << 16) | i;
}
break;
}
}
return 0;
}
static int __init iga_init(struct fb_info *info, struct iga_par *par)
{
char vramsz = iga_inb(par, IGA_EXT_CNTRL, IGA_IDX_EXT_BUS_CNTL)
& MEM_SIZE_ALIAS;
int video_cmap_len;
switch (vramsz) {
case MEM_SIZE_1M:
info->fix.smem_len = 0x100000;
break;
case MEM_SIZE_2M:
info->fix.smem_len = 0x200000;
break;
case MEM_SIZE_4M:
case MEM_SIZE_RESERVED:
info->fix.smem_len = 0x400000;
break;
}
if (info->var.bits_per_pixel > 8)
video_cmap_len = 16;
else
video_cmap_len = 256;
info->fbops = &igafb_ops;
info->flags = FBINFO_DEFAULT;
fb_alloc_cmap(&info->cmap, video_cmap_len, 0);
if (register_framebuffer(info) < 0)
return 0;
printk("fb%d: %s frame buffer device at 0x%08lx [%dMB VRAM]\n",
info->node, info->fix.id,
par->frame_buffer_phys, info->fix.smem_len >> 20);
iga_blank_border(par);
return 1;
}
static int __init igafb_init(void)
{
struct fb_info *info;
struct pci_dev *pdev;
struct iga_par *par;
unsigned long addr;
int size, iga2000 = 0;
if (fb_get_options("igafb", NULL))
return -ENODEV;
pdev = pci_get_device(PCI_VENDOR_ID_INTERG,
PCI_DEVICE_ID_INTERG_1682, 0);
if (pdev == NULL) {
pdev = pci_get_device(PCI_VENDOR_ID_INTERG, 0x2000, 0);
if(pdev == NULL) {
return -ENXIO;
}
iga2000 = 1;
}
size = sizeof(struct iga_par) + sizeof(u32)*16;
info = framebuffer_alloc(size, &pdev->dev);
if (!info) {
printk("igafb_init: can't alloc fb_info\n");
pci_dev_put(pdev);
return -ENOMEM;
}
par = info->par;
if ((addr = pdev->resource[0].start) == 0) {
printk("igafb_init: no memory start\n");
kfree(info);
pci_dev_put(pdev);
return -ENXIO;
}
if ((info->screen_base = ioremap(addr, 1024*1024*2)) == 0) {
printk("igafb_init: can't remap %lx[2M]\n", addr);
kfree(info);
pci_dev_put(pdev);
return -ENXIO;
}
par->frame_buffer_phys = addr & PCI_BASE_ADDRESS_MEM_MASK;
#ifdef CONFIG_SPARC
if (iga2000) {
igafb_fix.mmio_start = par->frame_buffer_phys | 0x00800000;
} else {
igafb_fix.mmio_start = 0x30000000;
}
if ((par->io_base = (int) ioremap(igafb_fix.mmio_start, igafb_fix.smem_len)) == 0) {
printk("igafb_init: can't remap %lx[4K]\n", igafb_fix.mmio_start);
iounmap((void *)info->screen_base);
kfree(info);
pci_dev_put(pdev);
return -ENXIO;
}
par->mmap_map = kzalloc(4 * sizeof(*par->mmap_map), GFP_ATOMIC);
if (!par->mmap_map) {
printk("igafb_init: can't alloc mmap_map\n");
iounmap((void *)par->io_base);
iounmap(info->screen_base);
kfree(info);
pci_dev_put(pdev);
return -ENOMEM;
}
{
struct device_node *dp = pci_device_to_OF_node(pdev);
int node = dp->node;
int width = prom_getintdefault(node, "width", 1024);
int height = prom_getintdefault(node, "height", 768);
int depth = prom_getintdefault(node, "depth", 8);
switch (width) {
case 1024:
if (height == 768)
default_var = default_var_1024x768;
break;
case 1152:
if (height == 900)
default_var = default_var_1152x900;
break;
case 1280:
if (height == 1024)
default_var = default_var_1280x1024;
break;
default:
break;
}
switch (depth) {
case 8:
default_var.bits_per_pixel = 8;
break;
case 16:
default_var.bits_per_pixel = 16;
break;
case 24:
default_var.bits_per_pixel = 24;
break;
case 32:
default_var.bits_per_pixel = 32;
break;
default:
break;
}
}
#endif
igafb_fix.smem_start = (unsigned long) info->screen_base;
igafb_fix.line_length = default_var.xres*(default_var.bits_per_pixel/8);
igafb_fix.visual = default_var.bits_per_pixel <= 8 ? FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_DIRECTCOLOR;
info->var = default_var;
info->fix = igafb_fix;
info->pseudo_palette = (void *)(par + 1);
if (!iga_init(info, par)) {
iounmap((void *)par->io_base);
iounmap(info->screen_base);
kfree(par->mmap_map);
kfree(info);
return -ENODEV;
}
#ifdef CONFIG_SPARC
par->mmap_map[0].voff = 0x0;
par->mmap_map[0].poff = par->frame_buffer_phys & PAGE_MASK;
par->mmap_map[0].size = info->fix.smem_len & PAGE_MASK;
par->mmap_map[0].prot_mask = SRMMU_CACHE;
par->mmap_map[0].prot_flag = SRMMU_WRITE;
par->mmap_map[1].voff = par->frame_buffer_phys & PAGE_MASK;
par->mmap_map[1].poff = info->fix.smem_start & PAGE_MASK;
par->mmap_map[1].size = PAGE_SIZE * 2;
par->mmap_map[1].prot_mask = SRMMU_CACHE;
par->mmap_map[1].prot_flag = SRMMU_WRITE;
#endif
return 0;
}
static int __init igafb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
}
return 0;
}
