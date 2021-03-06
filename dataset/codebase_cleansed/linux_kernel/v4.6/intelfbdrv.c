static __inline__ char * get_opt_string(const char *this_opt, const char *name)
{
const char *p;
int i;
char *ret;
p = OPT_STRVAL(this_opt, name);
i = 0;
while (p[i] && p[i] != ' ' && p[i] != ',')
i++;
ret = kmalloc(i + 1, GFP_KERNEL);
if (ret) {
strncpy(ret, p, i);
ret[i] = '\0';
}
return ret;
}
static __inline__ int get_opt_int(const char *this_opt, const char *name,
int *ret)
{
if (!ret)
return 0;
if (!OPT_EQUAL(this_opt, name))
return 0;
*ret = OPT_INTVAL(this_opt, name);
return 1;
}
static __inline__ int get_opt_bool(const char *this_opt, const char *name,
bool *ret)
{
if (!ret)
return 0;
if (OPT_EQUAL(this_opt, name)) {
if (this_opt[strlen(name)] == '=')
*ret = simple_strtoul(this_opt + strlen(name) + 1,
NULL, 0);
else
*ret = 1;
} else {
if (OPT_EQUAL(this_opt, "no") && OPT_EQUAL(this_opt + 2, name))
*ret = 0;
else
return 0;
}
return 1;
}
static int __init intelfb_setup(char *options)
{
char *this_opt;
DBG_MSG("intelfb_setup\n");
if (!options || !*options) {
DBG_MSG("no options\n");
return 0;
} else
DBG_MSG("options: %s\n", options);
while ((this_opt = strsep(&options, ","))) {
if (!*this_opt)
continue;
if (get_opt_bool(this_opt, "accel", &accel))
;
else if (get_opt_int(this_opt, "vram", &vram))
;
else if (get_opt_bool(this_opt, "hwcursor", &hwcursor))
;
else if (get_opt_bool(this_opt, "mtrr", &mtrr))
;
else if (get_opt_bool(this_opt, "fixed", &fixed))
;
else if (get_opt_bool(this_opt, "init", &noinit))
noinit = !noinit;
else if (OPT_EQUAL(this_opt, "mode="))
mode = get_opt_string(this_opt, "mode=");
else
mode = this_opt;
}
return 0;
}
static int __init intelfb_init(void)
{
#ifndef MODULE
char *option = NULL;
#endif
DBG_MSG("intelfb_init\n");
INF_MSG("Framebuffer driver for "
"Intel(R) " SUPPORTED_CHIPSETS " chipsets\n");
INF_MSG("Version " INTELFB_VERSION "\n");
if (idonly)
return -ENODEV;
#ifndef MODULE
if (fb_get_options("intelfb", &option))
return -ENODEV;
intelfb_setup(option);
#endif
return pci_register_driver(&intelfb_driver);
}
static void __exit intelfb_exit(void)
{
DBG_MSG("intelfb_exit\n");
pci_unregister_driver(&intelfb_driver);
}
static void cleanup(struct intelfb_info *dinfo)
{
DBG_MSG("cleanup\n");
if (!dinfo)
return;
intelfbhw_disable_irq(dinfo);
fb_dealloc_cmap(&dinfo->info->cmap);
kfree(dinfo->info->pixmap.addr);
if (dinfo->registered)
unregister_framebuffer(dinfo->info);
arch_phys_wc_del(dinfo->wc_cookie);
if (dinfo->fbmem_gart && dinfo->gtt_fb_mem) {
agp_unbind_memory(dinfo->gtt_fb_mem);
agp_free_memory(dinfo->gtt_fb_mem);
}
if (dinfo->gtt_cursor_mem) {
agp_unbind_memory(dinfo->gtt_cursor_mem);
agp_free_memory(dinfo->gtt_cursor_mem);
}
if (dinfo->gtt_ring_mem) {
agp_unbind_memory(dinfo->gtt_ring_mem);
agp_free_memory(dinfo->gtt_ring_mem);
}
#ifdef CONFIG_FB_INTEL_I2C
intelfb_delete_i2c_busses(dinfo);
#endif
if (dinfo->mmio_base)
iounmap((void __iomem *)dinfo->mmio_base);
if (dinfo->aperture.virtual)
iounmap((void __iomem *)dinfo->aperture.virtual);
if (dinfo->flag & INTELFB_MMIO_ACQUIRED)
release_mem_region(dinfo->mmio_base_phys, INTEL_REG_SIZE);
if (dinfo->flag & INTELFB_FB_ACQUIRED)
release_mem_region(dinfo->aperture.physical,
dinfo->aperture.size);
framebuffer_release(dinfo->info);
}
static int intelfb_pci_register(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct fb_info *info;
struct intelfb_info *dinfo;
int i, err, dvo;
int aperture_size, stolen_size;
struct agp_kern_info gtt_info;
int agp_memtype;
const char *s;
struct agp_bridge_data *bridge;
int aperture_bar = 0;
int mmio_bar = 1;
int offset;
DBG_MSG("intelfb_pci_register\n");
num_registered++;
if (num_registered != 1) {
ERR_MSG("Attempted to register %d devices "
"(should be only 1).\n", num_registered);
return -ENODEV;
}
info = framebuffer_alloc(sizeof(struct intelfb_info), &pdev->dev);
if (!info) {
ERR_MSG("Could not allocate memory for intelfb_info.\n");
return -ENODEV;
}
if (fb_alloc_cmap(&info->cmap, 256, 1) < 0) {
ERR_MSG("Could not allocate cmap for intelfb_info.\n");
goto err_out_cmap;
}
dinfo = info->par;
dinfo->info = info;
dinfo->fbops = &intel_fb_ops;
dinfo->pdev = pdev;
info->pixmap.addr = kzalloc(64 * 1024, GFP_KERNEL);
if (info->pixmap.addr == NULL) {
ERR_MSG("Cannot reserve pixmap memory.\n");
goto err_out_pixmap;
}
dinfo->fixed_mode = fixed;
if ((err = pci_enable_device(pdev))) {
ERR_MSG("Cannot enable device.\n");
cleanup(dinfo);
return -ENODEV;
}
if ((ent->device == PCI_DEVICE_ID_INTEL_915G) ||
(ent->device == PCI_DEVICE_ID_INTEL_915GM) ||
(ent->device == PCI_DEVICE_ID_INTEL_945G) ||
(ent->device == PCI_DEVICE_ID_INTEL_945GM) ||
(ent->device == PCI_DEVICE_ID_INTEL_945GME) ||
(ent->device == PCI_DEVICE_ID_INTEL_965G) ||
(ent->device == PCI_DEVICE_ID_INTEL_965GM)) {
aperture_bar = 2;
mmio_bar = 0;
}
dinfo->aperture.physical = pci_resource_start(pdev, aperture_bar);
dinfo->aperture.size = pci_resource_len(pdev, aperture_bar);
dinfo->mmio_base_phys = pci_resource_start(pdev, mmio_bar);
DBG_MSG("fb aperture: 0x%llx/0x%llx, MMIO region: 0x%llx/0x%llx\n",
(unsigned long long)pci_resource_start(pdev, aperture_bar),
(unsigned long long)pci_resource_len(pdev, aperture_bar),
(unsigned long long)pci_resource_start(pdev, mmio_bar),
(unsigned long long)pci_resource_len(pdev, mmio_bar));
if (!request_mem_region(dinfo->aperture.physical, dinfo->aperture.size,
INTELFB_MODULE_NAME)) {
ERR_MSG("Cannot reserve FB region.\n");
cleanup(dinfo);
return -ENODEV;
}
dinfo->flag |= INTELFB_FB_ACQUIRED;
if (!request_mem_region(dinfo->mmio_base_phys,
INTEL_REG_SIZE,
INTELFB_MODULE_NAME)) {
ERR_MSG("Cannot reserve MMIO region.\n");
cleanup(dinfo);
return -ENODEV;
}
dinfo->flag |= INTELFB_MMIO_ACQUIRED;
dinfo->pci_chipset = pdev->device;
if (intelfbhw_get_chipset(pdev, dinfo)) {
cleanup(dinfo);
return -ENODEV;
}
if (intelfbhw_get_memory(pdev, &aperture_size,&stolen_size)) {
cleanup(dinfo);
return -ENODEV;
}
INF_MSG("%02x:%02x.%d: %s, aperture size %dMB, "
"stolen memory %dkB\n",
pdev->bus->number, PCI_SLOT(pdev->devfn),
PCI_FUNC(pdev->devfn), dinfo->name,
BtoMB(aperture_size), BtoKB(stolen_size));
dinfo->accel = accel;
dinfo->hwcursor = hwcursor;
if (NOACCEL_CHIPSET(dinfo) && dinfo->accel == 1) {
INF_MSG("Acceleration is not supported for the %s chipset.\n",
dinfo->name);
dinfo->accel = 0;
}
if (ROUND_UP_TO_PAGE(stolen_size) >= MB(vram)) {
dinfo->fb.size = ROUND_UP_TO_PAGE(stolen_size);
dinfo->fbmem_gart = 0;
} else {
dinfo->fb.size = MB(vram);
dinfo->fbmem_gart = 1;
}
if (dinfo->accel) {
dinfo->ring.size = RINGBUFFER_SIZE;
dinfo->ring_tail_mask = dinfo->ring.size - 1;
}
if (dinfo->hwcursor)
dinfo->cursor.size = HW_CURSOR_SIZE;
if (!(bridge = agp_backend_acquire(pdev))) {
ERR_MSG("cannot acquire agp\n");
cleanup(dinfo);
return -ENODEV;
}
if (agp_copy_info(bridge, &gtt_info)) {
ERR_MSG("cannot get agp info\n");
agp_backend_release(bridge);
cleanup(dinfo);
return -ENODEV;
}
if (MB(voffset) < stolen_size)
offset = (stolen_size >> 12);
else
offset = ROUND_UP_TO_PAGE(MB(voffset))/GTT_PAGE_SIZE;
if (dinfo->accel)
dinfo->ring.offset = offset + gtt_info.current_memory;
if (dinfo->hwcursor)
dinfo->cursor.offset = offset +
+ gtt_info.current_memory + (dinfo->ring.size >> 12);
if (dinfo->fbmem_gart)
dinfo->fb.offset = offset +
+ gtt_info.current_memory + (dinfo->ring.size >> 12)
+ (dinfo->cursor.size >> 12);
dinfo->aperture.virtual = (u8 __iomem *)ioremap_wc
(dinfo->aperture.physical, ((offset + dinfo->fb.offset) << 12)
+ dinfo->fb.size);
if (!dinfo->aperture.virtual) {
ERR_MSG("Cannot remap FB region.\n");
agp_backend_release(bridge);
cleanup(dinfo);
return -ENODEV;
}
dinfo->mmio_base =
(u8 __iomem *)ioremap_nocache(dinfo->mmio_base_phys,
INTEL_REG_SIZE);
if (!dinfo->mmio_base) {
ERR_MSG("Cannot remap MMIO region.\n");
agp_backend_release(bridge);
cleanup(dinfo);
return -ENODEV;
}
if (dinfo->accel) {
if (!(dinfo->gtt_ring_mem =
agp_allocate_memory(bridge, dinfo->ring.size >> 12,
AGP_NORMAL_MEMORY))) {
ERR_MSG("cannot allocate ring buffer memory\n");
agp_backend_release(bridge);
cleanup(dinfo);
return -ENOMEM;
}
if (agp_bind_memory(dinfo->gtt_ring_mem,
dinfo->ring.offset)) {
ERR_MSG("cannot bind ring buffer memory\n");
agp_backend_release(bridge);
cleanup(dinfo);
return -EBUSY;
}
dinfo->ring.physical = dinfo->aperture.physical
+ (dinfo->ring.offset << 12);
dinfo->ring.virtual = dinfo->aperture.virtual
+ (dinfo->ring.offset << 12);
dinfo->ring_head = 0;
}
if (dinfo->hwcursor) {
agp_memtype = dinfo->mobile ? AGP_PHYSICAL_MEMORY
: AGP_NORMAL_MEMORY;
if (!(dinfo->gtt_cursor_mem =
agp_allocate_memory(bridge, dinfo->cursor.size >> 12,
agp_memtype))) {
ERR_MSG("cannot allocate cursor memory\n");
agp_backend_release(bridge);
cleanup(dinfo);
return -ENOMEM;
}
if (agp_bind_memory(dinfo->gtt_cursor_mem,
dinfo->cursor.offset)) {
ERR_MSG("cannot bind cursor memory\n");
agp_backend_release(bridge);
cleanup(dinfo);
return -EBUSY;
}
if (dinfo->mobile)
dinfo->cursor.physical
= dinfo->gtt_cursor_mem->physical;
else
dinfo->cursor.physical = dinfo->aperture.physical
+ (dinfo->cursor.offset << 12);
dinfo->cursor.virtual = dinfo->aperture.virtual
+ (dinfo->cursor.offset << 12);
}
if (dinfo->fbmem_gart) {
if (!(dinfo->gtt_fb_mem =
agp_allocate_memory(bridge, dinfo->fb.size >> 12,
AGP_NORMAL_MEMORY))) {
WRN_MSG("cannot allocate framebuffer memory - use "
"the stolen one\n");
dinfo->fbmem_gart = 0;
}
if (agp_bind_memory(dinfo->gtt_fb_mem,
dinfo->fb.offset)) {
WRN_MSG("cannot bind framebuffer memory - use "
"the stolen one\n");
dinfo->fbmem_gart = 0;
}
}
if (!dinfo->fbmem_gart)
dinfo->fb.offset = 0;
dinfo->fb.physical = dinfo->aperture.physical
+ (dinfo->fb.offset << 12);
dinfo->fb.virtual = dinfo->aperture.virtual + (dinfo->fb.offset << 12);
dinfo->fb_start = dinfo->fb.offset << 12;
agp_backend_release(bridge);
if (mtrr)
dinfo->wc_cookie = arch_phys_wc_add(dinfo->aperture.physical,
dinfo->aperture.size);
DBG_MSG("fb: 0x%x(+ 0x%x)/0x%x (0x%p)\n",
dinfo->fb.physical, dinfo->fb.offset, dinfo->fb.size,
dinfo->fb.virtual);
DBG_MSG("MMIO: 0x%x/0x%x (0x%p)\n",
dinfo->mmio_base_phys, INTEL_REG_SIZE,
dinfo->mmio_base);
DBG_MSG("ring buffer: 0x%x/0x%x (0x%p)\n",
dinfo->ring.physical, dinfo->ring.size,
dinfo->ring.virtual);
DBG_MSG("HW cursor: 0x%x/0x%x (0x%p) (offset 0x%x) (phys 0x%x)\n",
dinfo->cursor.physical, dinfo->cursor.size,
dinfo->cursor.virtual, dinfo->cursor.offset,
dinfo->cursor.physical);
DBG_MSG("options: vram = %d, accel = %d, hwcursor = %d, fixed = %d, "
"noinit = %d\n", vram, accel, hwcursor, fixed, noinit);
DBG_MSG("options: mode = \"%s\"\n", mode ? mode : "");
if (probeonly)
bailout(dinfo);
dvo = intelfbhw_check_non_crt(dinfo);
if (dvo) {
dinfo->fixed_mode = 1;
WRN_MSG("Non-CRT device is enabled ( ");
i = 0;
while (dvo) {
if (dvo & 1) {
s = intelfbhw_dvo_to_string(1 << i);
if (s)
printk("%s ", s);
}
dvo >>= 1;
++i;
}
printk("). Disabling mode switching.\n");
}
if (bailearly == 1)
bailout(dinfo);
if (FIXED_MODE(dinfo) &&
screen_info.orig_video_isVGA != VIDEO_TYPE_VLFB) {
ERR_MSG("Video mode must be programmed at boot time.\n");
cleanup(dinfo);
return -ENODEV;
}
if (bailearly == 2)
bailout(dinfo);
if (screen_info.orig_video_isVGA == VIDEO_TYPE_VLFB)
get_initial_mode(dinfo);
if (bailearly == 3)
bailout(dinfo);
if (FIXED_MODE(dinfo))
update_dinfo(dinfo, &dinfo->initial_var);
if (bailearly == 4)
bailout(dinfo);
if (intelfb_set_fbinfo(dinfo)) {
cleanup(dinfo);
return -ENODEV;
}
if (bailearly == 5)
bailout(dinfo);
#ifdef CONFIG_FB_INTEL_I2C
intelfb_create_i2c_busses(dinfo);
#endif
if (bailearly == 6)
bailout(dinfo);
pci_set_drvdata(pdev, dinfo);
i = intelfbhw_read_hw_state(dinfo, &dinfo->save_state,
bailearly > 6 ? bailearly - 6 : 0);
if (i != 0) {
DBG_MSG("intelfbhw_read_hw_state returned %d\n", i);
bailout(dinfo);
}
intelfbhw_print_hw_state(dinfo, &dinfo->save_state);
if (bailearly == 18)
bailout(dinfo);
dinfo->pipe = intelfbhw_active_pipe(&dinfo->save_state);
if (dinfo->hwcursor) {
intelfbhw_cursor_init(dinfo);
intelfbhw_cursor_reset(dinfo);
}
if (bailearly == 19)
bailout(dinfo);
if (dinfo->accel)
intelfbhw_2d_start(dinfo);
if (bailearly == 20)
bailout(dinfo);
if (noregister)
bailout(dinfo);
if (register_framebuffer(dinfo->info) < 0) {
ERR_MSG("Cannot register framebuffer.\n");
cleanup(dinfo);
return -ENODEV;
}
dinfo->registered = 1;
dinfo->open = 0;
init_waitqueue_head(&dinfo->vsync.wait);
spin_lock_init(&dinfo->int_lock);
dinfo->irq_flags = 0;
dinfo->vsync.pan_display = 0;
dinfo->vsync.pan_offset = 0;
return 0;
err_out_pixmap:
fb_dealloc_cmap(&info->cmap);
err_out_cmap:
framebuffer_release(info);
return -ENODEV;
}
static void intelfb_pci_unregister(struct pci_dev *pdev)
{
struct intelfb_info *dinfo = pci_get_drvdata(pdev);
DBG_MSG("intelfb_pci_unregister\n");
if (!dinfo)
return;
cleanup(dinfo);
}
int __inline__ intelfb_var_to_depth(const struct fb_var_screeninfo *var)
{
DBG_MSG("intelfb_var_to_depth: bpp: %d, green.length is %d\n",
var->bits_per_pixel, var->green.length);
switch (var->bits_per_pixel) {
case 16:
return (var->green.length == 6) ? 16 : 15;
case 32:
return 24;
default:
return var->bits_per_pixel;
}
}
static __inline__ int var_to_refresh(const struct fb_var_screeninfo *var)
{
int xtot = var->xres + var->left_margin + var->right_margin +
var->hsync_len;
int ytot = var->yres + var->upper_margin + var->lower_margin +
var->vsync_len;
return (1000000000 / var->pixclock * 1000 + 500) / xtot / ytot;
}
static void get_initial_mode(struct intelfb_info *dinfo)
{
struct fb_var_screeninfo *var;
int xtot, ytot;
DBG_MSG("get_initial_mode\n");
dinfo->initial_vga = 1;
dinfo->initial_fb_base = screen_info.lfb_base;
dinfo->initial_video_ram = screen_info.lfb_size * KB(64);
dinfo->initial_pitch = screen_info.lfb_linelength;
var = &dinfo->initial_var;
memset(var, 0, sizeof(*var));
var->xres = screen_info.lfb_width;
var->yres = screen_info.lfb_height;
var->bits_per_pixel = screen_info.lfb_depth;
switch (screen_info.lfb_depth) {
case 15:
var->bits_per_pixel = 16;
break;
case 24:
var->bits_per_pixel = 32;
break;
}
DBG_MSG("Initial info: FB is 0x%x/0x%x (%d kByte)\n",
dinfo->initial_fb_base, dinfo->initial_video_ram,
BtoKB(dinfo->initial_video_ram));
DBG_MSG("Initial info: mode is %dx%d-%d (%d)\n",
var->xres, var->yres, var->bits_per_pixel,
dinfo->initial_pitch);
var->left_margin = (var->xres / 8) & 0xf8;
var->right_margin = 32;
var->upper_margin = 16;
var->lower_margin = 4;
var->hsync_len = (var->xres / 8) & 0xf8;
var->vsync_len = 4;
xtot = var->xres + var->left_margin +
var->right_margin + var->hsync_len;
ytot = var->yres + var->upper_margin +
var->lower_margin + var->vsync_len;
var->pixclock = 10000000 / xtot * 1000 / ytot * 100 / 60;
var->height = -1;
var->width = -1;
if (var->bits_per_pixel > 8) {
var->red.offset = screen_info.red_pos;
var->red.length = screen_info.red_size;
var->green.offset = screen_info.green_pos;
var->green.length = screen_info.green_size;
var->blue.offset = screen_info.blue_pos;
var->blue.length = screen_info.blue_size;
var->transp.offset = screen_info.rsvd_pos;
var->transp.length = screen_info.rsvd_size;
} else {
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
}
}
static int intelfb_init_var(struct intelfb_info *dinfo)
{
struct fb_var_screeninfo *var;
int msrc = 0;
DBG_MSG("intelfb_init_var\n");
var = &dinfo->info->var;
if (FIXED_MODE(dinfo)) {
memcpy(var, &dinfo->initial_var,
sizeof(struct fb_var_screeninfo));
msrc = 5;
} else {
const u8 *edid_s = fb_firmware_edid(&dinfo->pdev->dev);
u8 *edid_d = NULL;
if (edid_s) {
edid_d = kmemdup(edid_s, EDID_LENGTH, GFP_KERNEL);
if (edid_d) {
fb_edid_to_monspecs(edid_d,
&dinfo->info->monspecs);
kfree(edid_d);
}
}
if (mode) {
printk("intelfb: Looking for mode in private "
"database\n");
msrc = fb_find_mode(var, dinfo->info, mode,
dinfo->info->monspecs.modedb,
dinfo->info->monspecs.modedb_len,
NULL, 0);
if (msrc && msrc > 1) {
printk("intelfb: No mode in private database, "
"intelfb: looking for mode in global "
"database ");
msrc = fb_find_mode(var, dinfo->info, mode,
NULL, 0, NULL, 0);
if (msrc)
msrc |= 8;
}
}
if (!msrc)
msrc = fb_find_mode(var, dinfo->info, PREFERRED_MODE,
NULL, 0, NULL, 0);
}
if (!msrc) {
ERR_MSG("Cannot find a suitable video mode.\n");
return 1;
}
INF_MSG("Initial video mode is %dx%d-%d@%d.\n", var->xres, var->yres,
var->bits_per_pixel, var_to_refresh(var));
DBG_MSG("Initial video mode is from %d.\n", msrc);
#if ALLOCATE_FOR_PANNING
var->xres_virtual = var->xres;
var->yres_virtual =
dinfo->fb.size / 2 / (var->bits_per_pixel * var->xres);
if (var->yres_virtual < var->yres)
var->yres_virtual = var->yres;
#else
var->yres_virtual = var->yres;
#endif
if (dinfo->accel)
var->accel_flags |= FB_ACCELF_TEXT;
else
var->accel_flags &= ~FB_ACCELF_TEXT;
return 0;
}
static int intelfb_set_fbinfo(struct intelfb_info *dinfo)
{
struct fb_info *info = dinfo->info;
DBG_MSG("intelfb_set_fbinfo\n");
info->flags = FBINFO_FLAG_DEFAULT;
info->fbops = &intel_fb_ops;
info->pseudo_palette = dinfo->pseudo_palette;
info->pixmap.size = 64*1024;
info->pixmap.buf_align = 8;
info->pixmap.access_align = 32;
info->pixmap.flags = FB_PIXMAP_SYSTEM;
if (intelfb_init_var(dinfo))
return 1;
info->pixmap.scan_align = 1;
strcpy(info->fix.id, dinfo->name);
info->fix.smem_start = dinfo->fb.physical;
info->fix.smem_len = dinfo->fb.size;
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.type_aux = 0;
info->fix.xpanstep = 8;
info->fix.ypanstep = 1;
info->fix.ywrapstep = 0;
info->fix.mmio_start = dinfo->mmio_base_phys;
info->fix.mmio_len = INTEL_REG_SIZE;
info->fix.accel = FB_ACCEL_I830;
update_dinfo(dinfo, &info->var);
return 0;
}
static void update_dinfo(struct intelfb_info *dinfo,
struct fb_var_screeninfo *var)
{
DBG_MSG("update_dinfo\n");
dinfo->bpp = var->bits_per_pixel;
dinfo->depth = intelfb_var_to_depth(var);
dinfo->xres = var->xres;
dinfo->yres = var->xres;
dinfo->pixclock = var->pixclock;
dinfo->info->fix.visual = dinfo->visual;
dinfo->info->fix.line_length = dinfo->pitch;
switch (dinfo->bpp) {
case 8:
dinfo->visual = FB_VISUAL_PSEUDOCOLOR;
dinfo->pitch = var->xres_virtual;
break;
case 16:
dinfo->visual = FB_VISUAL_TRUECOLOR;
dinfo->pitch = var->xres_virtual * 2;
break;
case 32:
dinfo->visual = FB_VISUAL_TRUECOLOR;
dinfo->pitch = var->xres_virtual * 4;
break;
}
if (IS_I9XX(dinfo))
dinfo->pitch = ROUND_UP_TO(dinfo->pitch, STRIDE_ALIGNMENT_I9XX);
else
dinfo->pitch = ROUND_UP_TO(dinfo->pitch, STRIDE_ALIGNMENT);
if (FIXED_MODE(dinfo))
dinfo->pitch = dinfo->initial_pitch;
dinfo->info->screen_base = (char __iomem *)dinfo->fb.virtual;
dinfo->info->fix.line_length = dinfo->pitch;
dinfo->info->fix.visual = dinfo->visual;
}
static int intelfb_open(struct fb_info *info, int user)
{
struct intelfb_info *dinfo = GET_DINFO(info);
if (user)
dinfo->open++;
return 0;
}
static int intelfb_release(struct fb_info *info, int user)
{
struct intelfb_info *dinfo = GET_DINFO(info);
if (user) {
dinfo->open--;
msleep(1);
if (!dinfo->open)
intelfbhw_disable_irq(dinfo);
}
return 0;
}
static int intelfb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
int change_var = 0;
struct fb_var_screeninfo v;
struct intelfb_info *dinfo;
static int first = 1;
int i;
static const int pitches[] = {
128 * 8,
128 * 16,
128 * 32,
128 * 64,
0
};
DBG_MSG("intelfb_check_var: accel_flags is %d\n", var->accel_flags);
dinfo = GET_DINFO(info);
if (intelfbhw_validate_mode(dinfo, var) != 0)
return -EINVAL;
v = *var;
for (i = 0; pitches[i] != 0; i++) {
if (pitches[i] >= v.xres_virtual) {
v.xres_virtual = pitches[i];
break;
}
}
if (v.bits_per_pixel <= 8)
v.bits_per_pixel = 8;
else if (v.bits_per_pixel <= 16) {
if (v.bits_per_pixel == 16)
v.green.length = 6;
v.bits_per_pixel = 16;
} else if (v.bits_per_pixel <= 32)
v.bits_per_pixel = 32;
else
return -EINVAL;
change_var = ((info->var.xres != var->xres) ||
(info->var.yres != var->yres) ||
(info->var.xres_virtual != var->xres_virtual) ||
(info->var.yres_virtual != var->yres_virtual) ||
(info->var.bits_per_pixel != var->bits_per_pixel) ||
memcmp(&info->var.red, &var->red, sizeof(var->red)) ||
memcmp(&info->var.green, &var->green,
sizeof(var->green)) ||
memcmp(&info->var.blue, &var->blue, sizeof(var->blue)));
if (FIXED_MODE(dinfo) &&
(change_var ||
var->yres_virtual > dinfo->initial_var.yres_virtual ||
var->yres_virtual < dinfo->initial_var.yres ||
var->xoffset || var->nonstd)) {
if (first) {
ERR_MSG("Changing the video mode is not supported.\n");
first = 0;
}
return -EINVAL;
}
switch (intelfb_var_to_depth(&v)) {
case 8:
v.red.offset = v.green.offset = v.blue.offset = 0;
v.red.length = v.green.length = v.blue.length = 8;
v.transp.offset = v.transp.length = 0;
break;
case 15:
v.red.offset = 10;
v.green.offset = 5;
v.blue.offset = 0;
v.red.length = v.green.length = v.blue.length = 5;
v.transp.offset = v.transp.length = 0;
break;
case 16:
v.red.offset = 11;
v.green.offset = 5;
v.blue.offset = 0;
v.red.length = 5;
v.green.length = 6;
v.blue.length = 5;
v.transp.offset = v.transp.length = 0;
break;
case 24:
v.red.offset = 16;
v.green.offset = 8;
v.blue.offset = 0;
v.red.length = v.green.length = v.blue.length = 8;
v.transp.offset = v.transp.length = 0;
break;
case 32:
v.red.offset = 16;
v.green.offset = 8;
v.blue.offset = 0;
v.red.length = v.green.length = v.blue.length = 8;
v.transp.offset = 24;
v.transp.length = 8;
break;
}
if (v.xoffset < 0)
v.xoffset = 0;
if (v.yoffset < 0)
v.yoffset = 0;
if (v.xoffset > v.xres_virtual - v.xres)
v.xoffset = v.xres_virtual - v.xres;
if (v.yoffset > v.yres_virtual - v.yres)
v.yoffset = v.yres_virtual - v.yres;
v.red.msb_right = v.green.msb_right = v.blue.msb_right =
v.transp.msb_right = 0;
*var = v;
return 0;
}
static int intelfb_set_par(struct fb_info *info)
{
struct intelfb_hwstate *hw;
struct intelfb_info *dinfo = GET_DINFO(info);
if (FIXED_MODE(dinfo)) {
ERR_MSG("Changing the video mode is not supported.\n");
return -EINVAL;
}
hw = kmalloc(sizeof(*hw), GFP_ATOMIC);
if (!hw)
return -ENOMEM;
DBG_MSG("intelfb_set_par (%dx%d-%d)\n", info->var.xres,
info->var.yres, info->var.bits_per_pixel);
OUTREG(DPLL_A, INREG(DPLL_A) & ~DPLL_VCO_ENABLE);
intelfb_blank(FB_BLANK_POWERDOWN, info);
if (ACCEL(dinfo, info))
intelfbhw_2d_stop(dinfo);
memcpy(hw, &dinfo->save_state, sizeof(*hw));
if (intelfbhw_mode_to_hw(dinfo, hw, &info->var))
goto invalid_mode;
if (intelfbhw_program_mode(dinfo, hw, 0))
goto invalid_mode;
#if REGDUMP > 0
intelfbhw_read_hw_state(dinfo, hw, 0);
intelfbhw_print_hw_state(dinfo, hw);
#endif
update_dinfo(dinfo, &info->var);
if (ACCEL(dinfo, info))
intelfbhw_2d_start(dinfo);
intelfb_pan_display(&info->var, info);
intelfb_blank(FB_BLANK_UNBLANK, info);
if (ACCEL(dinfo, info)) {
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN |
FBINFO_HWACCEL_COPYAREA | FBINFO_HWACCEL_FILLRECT |
FBINFO_HWACCEL_IMAGEBLIT;
} else
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
kfree(hw);
return 0;
invalid_mode:
kfree(hw);
return -EINVAL;
}
static int intelfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct intelfb_info *dinfo = GET_DINFO(info);
#if VERBOSE > 0
DBG_MSG("intelfb_setcolreg: regno %d, depth %d\n", regno, dinfo->depth);
#endif
if (regno > 255)
return 1;
if (dinfo->depth == 8) {
red >>= 8;
green >>= 8;
blue >>= 8;
intelfbhw_setcolreg(dinfo, regno, red, green, blue,
transp);
}
if (regno < 16) {
switch (dinfo->depth) {
case 15:
dinfo->pseudo_palette[regno] = ((red & 0xf800) >> 1) |
((green & 0xf800) >> 6) |
((blue & 0xf800) >> 11);
break;
case 16:
dinfo->pseudo_palette[regno] = (red & 0xf800) |
((green & 0xfc00) >> 5) |
((blue & 0xf800) >> 11);
break;
case 24:
dinfo->pseudo_palette[regno] = ((red & 0xff00) << 8) |
(green & 0xff00) |
((blue & 0xff00) >> 8);
break;
}
}
return 0;
}
static int intelfb_blank(int blank, struct fb_info *info)
{
intelfbhw_do_blank(blank, info);
return 0;
}
static int intelfb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
intelfbhw_pan_display(var, info);
return 0;
}
static int intelfb_ioctl(struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
int retval = 0;
struct intelfb_info *dinfo = GET_DINFO(info);
u32 pipe = 0;
switch (cmd) {
case FBIO_WAITFORVSYNC:
if (get_user(pipe, (__u32 __user *)arg))
return -EFAULT;
retval = intelfbhw_wait_for_vsync(dinfo, pipe);
break;
default:
break;
}
return retval;
}
static void intelfb_fillrect (struct fb_info *info,
const struct fb_fillrect *rect)
{
struct intelfb_info *dinfo = GET_DINFO(info);
u32 rop, color;
#if VERBOSE > 0
DBG_MSG("intelfb_fillrect\n");
#endif
if (!ACCEL(dinfo, info) || dinfo->depth == 4) {
cfb_fillrect(info, rect);
return;
}
if (rect->rop == ROP_COPY)
rop = PAT_ROP_GXCOPY;
else
rop = PAT_ROP_GXXOR;
if (dinfo->depth != 8)
color = dinfo->pseudo_palette[rect->color];
else
color = rect->color;
intelfbhw_do_fillrect(dinfo, rect->dx, rect->dy,
rect->width, rect->height, color,
dinfo->pitch, info->var.bits_per_pixel,
rop);
}
static void intelfb_copyarea(struct fb_info *info,
const struct fb_copyarea *region)
{
struct intelfb_info *dinfo = GET_DINFO(info);
#if VERBOSE > 0
DBG_MSG("intelfb_copyarea\n");
#endif
if (!ACCEL(dinfo, info) || dinfo->depth == 4) {
cfb_copyarea(info, region);
return;
}
intelfbhw_do_bitblt(dinfo, region->sx, region->sy, region->dx,
region->dy, region->width, region->height,
dinfo->pitch, info->var.bits_per_pixel);
}
static void intelfb_imageblit(struct fb_info *info,
const struct fb_image *image)
{
struct intelfb_info *dinfo = GET_DINFO(info);
u32 fgcolor, bgcolor;
#if VERBOSE > 0
DBG_MSG("intelfb_imageblit\n");
#endif
if (!ACCEL(dinfo, info) || dinfo->depth == 4
|| image->depth != 1) {
cfb_imageblit(info, image);
return;
}
if (dinfo->depth != 8) {
fgcolor = dinfo->pseudo_palette[image->fg_color];
bgcolor = dinfo->pseudo_palette[image->bg_color];
} else {
fgcolor = image->fg_color;
bgcolor = image->bg_color;
}
if (!intelfbhw_do_drawglyph(dinfo, fgcolor, bgcolor, image->width,
image->height, image->data,
image->dx, image->dy,
dinfo->pitch, info->var.bits_per_pixel)) {
cfb_imageblit(info, image);
return;
}
}
static int intelfb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
struct intelfb_info *dinfo = GET_DINFO(info);
u32 physical;
#if VERBOSE > 0
DBG_MSG("intelfb_cursor\n");
#endif
if (!dinfo->hwcursor)
return -ENODEV;
intelfbhw_cursor_hide(dinfo);
physical = (dinfo->mobile || IS_I9XX(dinfo)) ? dinfo->cursor.physical :
(dinfo->cursor.offset << 12);
if (INREG(CURSOR_A_BASEADDR) != physical) {
u32 fg, bg;
DBG_MSG("the cursor was killed - restore it !!\n");
DBG_MSG("size %d, %d pos %d, %d\n",
cursor->image.width, cursor->image.height,
cursor->image.dx, cursor->image.dy);
intelfbhw_cursor_init(dinfo);
intelfbhw_cursor_reset(dinfo);
intelfbhw_cursor_setpos(dinfo, cursor->image.dx,
cursor->image.dy);
if (dinfo->depth != 8) {
fg =dinfo->pseudo_palette[cursor->image.fg_color];
bg =dinfo->pseudo_palette[cursor->image.bg_color];
} else {
fg = cursor->image.fg_color;
bg = cursor->image.bg_color;
}
intelfbhw_cursor_setcolor(dinfo, bg, fg);
intelfbhw_cursor_load(dinfo, cursor->image.width,
cursor->image.height,
dinfo->cursor_src);
if (cursor->enable)
intelfbhw_cursor_show(dinfo);
return 0;
}
if (cursor->set & FB_CUR_SETPOS) {
u32 dx, dy;
dx = cursor->image.dx - info->var.xoffset;
dy = cursor->image.dy - info->var.yoffset;
intelfbhw_cursor_setpos(dinfo, dx, dy);
}
if (cursor->set & FB_CUR_SETSIZE) {
if (cursor->image.width > 64 || cursor->image.height > 64)
return -ENXIO;
intelfbhw_cursor_reset(dinfo);
}
if (cursor->set & FB_CUR_SETCMAP) {
u32 fg, bg;
if (dinfo->depth != 8) {
fg = dinfo->pseudo_palette[cursor->image.fg_color];
bg = dinfo->pseudo_palette[cursor->image.bg_color];
} else {
fg = cursor->image.fg_color;
bg = cursor->image.bg_color;
}
intelfbhw_cursor_setcolor(dinfo, bg, fg);
}
if (cursor->set & (FB_CUR_SETSHAPE | FB_CUR_SETIMAGE)) {
u32 s_pitch = (ROUND_UP_TO(cursor->image.width, 8) / 8);
u32 size = s_pitch * cursor->image.height;
u8 *dat = (u8 *) cursor->image.data;
u8 *msk = (u8 *) cursor->mask;
u8 src[64];
u32 i;
if (cursor->image.depth != 1)
return -ENXIO;
switch (cursor->rop) {
case ROP_XOR:
for (i = 0; i < size; i++)
src[i] = dat[i] ^ msk[i];
break;
case ROP_COPY:
default:
for (i = 0; i < size; i++)
src[i] = dat[i] & msk[i];
break;
}
memcpy(dinfo->cursor_src, src, size);
intelfbhw_cursor_load(dinfo, cursor->image.width,
cursor->image.height, src);
}
if (cursor->enable)
intelfbhw_cursor_show(dinfo);
return 0;
}
static int intelfb_sync(struct fb_info *info)
{
struct intelfb_info *dinfo = GET_DINFO(info);
#if VERBOSE > 0
DBG_MSG("intelfb_sync\n");
#endif
if (dinfo->ring_lockup)
return 0;
intelfbhw_do_sync(dinfo);
return 0;
}
