static int lynxfb_ops_cursor(struct fb_info *info, struct fb_cursor *fbcursor)
{
struct lynxfb_par *par;
struct lynxfb_crtc *crtc;
struct lynx_cursor *cursor;
par = info->par;
crtc = &par->crtc;
cursor = &crtc->cursor;
if (fbcursor->image.width > cursor->maxW ||
fbcursor->image.height > cursor->maxH ||
fbcursor->image.depth > 1) {
return -ENXIO;
}
cursor->disable(cursor);
if (fbcursor->set & FB_CUR_SETSIZE)
cursor->setSize(cursor,
fbcursor->image.width,
fbcursor->image.height);
if (fbcursor->set & FB_CUR_SETPOS)
cursor->setPos(cursor,
fbcursor->image.dx - info->var.xoffset,
fbcursor->image.dy - info->var.yoffset);
if (fbcursor->set & FB_CUR_SETCMAP) {
u16 fg, bg;
fg = ((info->cmap.red[fbcursor->image.fg_color] & 0xf800))|
((info->cmap.green[fbcursor->image.fg_color] & 0xfc00) >> 5)|
((info->cmap.blue[fbcursor->image.fg_color] & 0xf800) >> 11);
bg = ((info->cmap.red[fbcursor->image.bg_color] & 0xf800))|
((info->cmap.green[fbcursor->image.bg_color] & 0xfc00) >> 5)|
((info->cmap.blue[fbcursor->image.bg_color] & 0xf800) >> 11);
cursor->setColor(cursor, fg, bg);
}
if (fbcursor->set & (FB_CUR_SETSHAPE | FB_CUR_SETIMAGE)) {
cursor->setData(cursor,
fbcursor->rop,
fbcursor->image.data,
fbcursor->mask);
}
if (fbcursor->enable)
cursor->enable(cursor);
return 0;
}
static void lynxfb_ops_fillrect(struct fb_info *info,
const struct fb_fillrect *region)
{
struct lynxfb_par *par;
struct lynx_share *share;
unsigned int base, pitch, Bpp, rop;
u32 color;
if (info->state != FBINFO_STATE_RUNNING)
return;
par = info->par;
share = par->share;
base = par->crtc.oScreen;
pitch = info->fix.line_length;
Bpp = info->var.bits_per_pixel >> 3;
color = (Bpp == 1)?region->color:((u32 *)info->pseudo_palette)[region->color];
rop = (region->rop != ROP_COPY) ? HW_ROP2_XOR:HW_ROP2_COPY;
if (share->dual)
spin_lock(&share->slock);
share->accel.de_fillrect(&share->accel,
base, pitch, Bpp,
region->dx, region->dy,
region->width, region->height,
color, rop);
if (share->dual)
spin_unlock(&share->slock);
}
static void lynxfb_ops_copyarea(struct fb_info *info,
const struct fb_copyarea *region)
{
struct lynxfb_par *par;
struct lynx_share *share;
unsigned int base, pitch, Bpp;
par = info->par;
share = par->share;
base = par->crtc.oScreen;
pitch = info->fix.line_length;
Bpp = info->var.bits_per_pixel >> 3;
if (share->dual)
spin_lock(&share->slock);
share->accel.de_copyarea(&share->accel,
base, pitch, region->sx, region->sy,
base, pitch, Bpp, region->dx, region->dy,
region->width, region->height, HW_ROP2_COPY);
if (share->dual)
spin_unlock(&share->slock);
}
static void lynxfb_ops_imageblit(struct fb_info *info,
const struct fb_image *image)
{
unsigned int base, pitch, Bpp;
unsigned int fgcol, bgcol;
struct lynxfb_par *par;
struct lynx_share *share;
par = info->par;
share = par->share;
base = par->crtc.oScreen;
pitch = info->fix.line_length;
Bpp = info->var.bits_per_pixel >> 3;
if (image->depth == 1) {
if (info->fix.visual == FB_VISUAL_TRUECOLOR ||
info->fix.visual == FB_VISUAL_DIRECTCOLOR) {
fgcol = ((u32 *)info->pseudo_palette)[image->fg_color];
bgcol = ((u32 *)info->pseudo_palette)[image->bg_color];
} else {
fgcol = image->fg_color;
bgcol = image->bg_color;
}
goto _do_work;
}
return;
_do_work:
if (share->dual)
spin_lock(&share->slock);
share->accel.de_imageblit(&share->accel,
image->data, image->width>>3, 0,
base, pitch, Bpp,
image->dx, image->dy,
image->width, image->height,
fgcol, bgcol, HW_ROP2_COPY);
if (share->dual)
spin_unlock(&share->slock);
}
static int lynxfb_ops_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct lynxfb_par *par;
struct lynxfb_crtc *crtc;
int ret;
if (!info)
return -EINVAL;
ret = 0;
par = info->par;
crtc = &par->crtc;
ret = crtc->proc_panDisplay(crtc, var, info);
return ret;
}
static int lynxfb_ops_set_par(struct fb_info *info)
{
struct lynxfb_par *par;
struct lynx_share *share;
struct lynxfb_crtc *crtc;
struct lynxfb_output *output;
struct fb_var_screeninfo *var;
struct fb_fix_screeninfo *fix;
int ret;
unsigned int line_length;
if (!info)
return -EINVAL;
ret = 0;
par = info->par;
share = par->share;
crtc = &par->crtc;
output = &par->output;
var = &info->var;
fix = &info->fix;
line_length = var->xres_virtual * var->bits_per_pixel / 8;
line_length = PADDING(crtc->line_pad, line_length);
fix->line_length = line_length;
pr_err("fix->line_length = %d\n", fix->line_length);
switch (var->bits_per_pixel) {
case 8:
fix->visual = FB_VISUAL_PSEUDOCOLOR;
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.length = 0;
var->transp.offset = 0;
break;
case 16:
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
var->transp.length = 0;
var->transp.offset = 0;
fix->visual = FB_VISUAL_TRUECOLOR;
break;
case 24:
case 32:
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
fix->visual = FB_VISUAL_TRUECOLOR;
break;
default:
ret = -EINVAL;
break;
}
var->height = var->width = -1;
var->accel_flags = 0;
if (ret) {
pr_err("pixel bpp format not satisfied\n.");
return ret;
}
ret = crtc->proc_setMode(crtc, var, fix);
if (!ret)
ret = output->proc_setMode(output, var, fix);
return ret;
}
static inline unsigned int chan_to_field(unsigned int chan,
struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int lynxfb_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
struct fb_info *info;
struct lynx_share *share;
int ret;
if (mesg.event == pdev->dev.power.power_state.event)
return 0;
ret = 0;
share = pci_get_drvdata(pdev);
switch (mesg.event) {
case PM_EVENT_FREEZE:
case PM_EVENT_PRETHAW:
pdev->dev.power.power_state = mesg;
return 0;
}
console_lock();
if (mesg.event & PM_EVENT_SLEEP) {
info = share->fbinfo[0];
if (info)
fb_set_suspend(info, 1);
info = share->fbinfo[1];
if (info)
fb_set_suspend(info, 1);
ret = pci_save_state(pdev);
if (ret) {
pr_err("error:%d occurred in pci_save_state\n", ret);
return ret;
}
if (share->suspend)
(*share->suspend)(share);
pci_disable_device(pdev);
ret = pci_set_power_state(pdev, pci_choose_state(pdev, mesg));
if (ret) {
pr_err("error:%d occurred in pci_set_power_state\n", ret);
return ret;
}
}
pdev->dev.power.power_state = mesg;
console_unlock();
return ret;
}
static int lynxfb_resume(struct pci_dev *pdev)
{
struct fb_info *info;
struct lynx_share *share;
struct lynxfb_par *par;
struct lynxfb_crtc *crtc;
struct lynx_cursor *cursor;
int ret;
ret = 0;
share = pci_get_drvdata(pdev);
console_lock();
ret = pci_set_power_state(pdev, PCI_D0);
if (ret) {
pr_err("error:%d occured in pci_set_power_state\n", ret);
return ret;
}
if (pdev->dev.power.power_state.event != PM_EVENT_FREEZE) {
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret) {
pr_err("error:%d occured in pci_enable_device\n", ret);
return ret;
}
pci_set_master(pdev);
}
if (share->resume)
(*share->resume)(share);
hw_sm750_inithw(share, pdev);
info = share->fbinfo[0];
if (info) {
par = info->par;
crtc = &par->crtc;
cursor = &crtc->cursor;
memset_io(cursor->vstart, 0x0, cursor->size);
memset_io(crtc->vScreen, 0x0, crtc->vidmem_size);
lynxfb_ops_set_par(info);
fb_set_suspend(info, 0);
}
info = share->fbinfo[1];
if (info) {
par = info->par;
crtc = &par->crtc;
cursor = &crtc->cursor;
memset_io(cursor->vstart, 0x0, cursor->size);
memset_io(crtc->vScreen, 0x0, crtc->vidmem_size);
lynxfb_ops_set_par(info);
fb_set_suspend(info, 0);
}
console_unlock();
return ret;
}
static int lynxfb_ops_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct lynxfb_par *par;
struct lynxfb_crtc *crtc;
struct lynxfb_output *output;
struct lynx_share *share;
int ret;
resource_size_t request;
par = info->par;
crtc = &par->crtc;
output = &par->output;
share = par->share;
ret = 0;
pr_debug("check var:%dx%d-%d\n",
var->xres,
var->yres,
var->bits_per_pixel);
switch (var->bits_per_pixel) {
case 8:
case 16:
case 24:
case 32:
break;
default:
pr_err("bpp %d not supported\n", var->bits_per_pixel);
ret = -EINVAL;
goto exit;
}
switch (var->bits_per_pixel) {
case 8:
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.length = 0;
var->transp.offset = 0;
break;
case 16:
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
var->transp.length = 0;
var->transp.offset = 0;
info->fix.visual = FB_VISUAL_TRUECOLOR;
break;
case 24:
case 32:
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
info->fix.visual = FB_VISUAL_TRUECOLOR;
break;
default:
ret = -EINVAL;
break;
}
var->height = var->width = -1;
var->accel_flags = 0;
request = var->xres_virtual * (var->bits_per_pixel >> 3);
request = PADDING(crtc->line_pad, request);
request = request * var->yres_virtual;
if (crtc->vidmem_size < request) {
pr_err("not enough video memory for mode\n");
return -ENOMEM;
}
ret = output->proc_checkMode(output, var);
if (!ret)
ret = crtc->proc_checkMode(crtc, var);
exit:
return ret;
}
static int lynxfb_ops_setcolreg(unsigned regno,
unsigned red,
unsigned green,
unsigned blue,
unsigned transp,
struct fb_info *info)
{
struct lynxfb_par *par;
struct lynxfb_crtc *crtc;
struct fb_var_screeninfo *var;
int ret;
par = info->par;
crtc = &par->crtc;
var = &info->var;
ret = 0;
if (regno > 256) {
pr_err("regno = %d\n", regno);
return -EINVAL;
}
if (info->var.grayscale)
red = green = blue = (red * 77 + green * 151 + blue * 28) >> 8;
if (var->bits_per_pixel == 8 &&
info->fix.visual == FB_VISUAL_PSEUDOCOLOR) {
red >>= 8;
green >>= 8;
blue >>= 8;
ret = crtc->proc_setColReg(crtc, regno, red, green, blue);
goto exit;
}
if (info->fix.visual == FB_VISUAL_TRUECOLOR && regno < 256) {
u32 val;
if (var->bits_per_pixel == 16 ||
var->bits_per_pixel == 32 ||
var->bits_per_pixel == 24) {
val = chan_to_field(red, &var->red);
val |= chan_to_field(green, &var->green);
val |= chan_to_field(blue, &var->blue);
par->pseudo_palette[regno] = val;
goto exit;
}
}
ret = -EINVAL;
exit:
return ret;
}
static int lynxfb_ops_blank(int blank, struct fb_info *info)
{
struct lynxfb_par *par;
struct lynxfb_output *output;
pr_debug("blank = %d.\n", blank);
par = info->par;
output = &par->output;
return output->proc_setBLANK(output, blank);
}
static int sm750fb_set_drv(struct lynxfb_par *par)
{
int ret;
struct lynx_share *share;
struct sm750_share *spec_share;
struct lynxfb_output *output;
struct lynxfb_crtc *crtc;
ret = 0;
share = par->share;
spec_share = container_of(share, struct sm750_share, share);
output = &par->output;
crtc = &par->crtc;
crtc->vidmem_size = (share->dual)?share->vidmem_size>>1:share->vidmem_size;
spec_share->hwCursor = g_hwcursor;
crtc->proc_setMode = hw_sm750_crtc_setMode;
crtc->proc_checkMode = hw_sm750_crtc_checkMode;
crtc->proc_setColReg = hw_sm750_setColReg;
crtc->proc_panDisplay = hw_sm750_pan_display;
crtc->clear = hw_sm750_crtc_clear;
crtc->line_pad = 16;
crtc->xpanstep = 8;
crtc->ypanstep = 1;
crtc->ywrapstep = 0;
output->proc_setMode = hw_sm750_output_setMode;
output->proc_checkMode = hw_sm750_output_checkMode;
output->proc_setBLANK = (share->revid == SM750LE_REVISION_ID)?hw_sm750le_setBLANK:hw_sm750_setBLANK;
output->clear = hw_sm750_output_clear;
share->accel.de_wait = (share->revid == SM750LE_REVISION_ID)?hw_sm750le_deWait : hw_sm750_deWait;
switch (spec_share->state.dataflow) {
case sm750_simul_pri:
output->paths = sm750_pnc;
crtc->channel = sm750_primary;
crtc->oScreen = 0;
crtc->vScreen = share->pvMem;
pr_info("use simul primary mode\n");
break;
case sm750_simul_sec:
output->paths = sm750_pnc;
crtc->channel = sm750_secondary;
crtc->oScreen = 0;
crtc->vScreen = share->pvMem;
break;
case sm750_dual_normal:
if (par->index == 0) {
output->paths = sm750_panel;
crtc->channel = sm750_primary;
crtc->oScreen = 0;
crtc->vScreen = share->pvMem;
} else {
output->paths = sm750_crt;
crtc->channel = sm750_secondary;
crtc->oScreen = (share->vidmem_size >> 1);
crtc->vScreen = share->pvMem + crtc->oScreen;
}
break;
case sm750_dual_swap:
if (par->index == 0) {
output->paths = sm750_panel;
crtc->channel = sm750_secondary;
crtc->oScreen = 0;
crtc->vScreen = share->pvMem;
} else {
output->paths = sm750_crt;
crtc->channel = sm750_primary;
crtc->oScreen = (share->vidmem_size >> 1);
crtc->vScreen = share->pvMem + crtc->oScreen;
}
break;
default:
ret = -EINVAL;
}
return ret;
}
static int lynxfb_set_fbinfo(struct fb_info *info, int index)
{
int i;
struct lynxfb_par *par;
struct lynx_share *share;
struct lynxfb_crtc *crtc;
struct lynxfb_output *output;
struct fb_var_screeninfo *var;
struct fb_fix_screeninfo *fix;
const struct fb_videomode *pdb[] = {
lynx750_ext, NULL, vesa_modes,
};
int cdb[] = {ARRAY_SIZE(lynx750_ext), 0, VESA_MODEDB_SIZE};
static const char *mdb_desc[] = {
"driver prepared modes",
"kernel prepared default modedb",
"kernel HELPERS prepared vesa_modes",
};
static const char *fixId[2] = {
"sm750_fb1", "sm750_fb2",
};
int ret, line_length;
ret = 0;
par = (struct lynxfb_par *)info->par;
share = par->share;
crtc = &par->crtc;
output = &par->output;
var = &info->var;
fix = &info->fix;
par->index = index;
output->channel = &crtc->channel;
sm750fb_set_drv(par);
lynxfb_ops.fb_pan_display = lynxfb_ops_pan_display;
crtc->cursor.offset = crtc->oScreen + crtc->vidmem_size - 1024;
crtc->cursor.mmio = share->pvReg + 0x800f0 + (int)crtc->channel * 0x140;
pr_info("crtc->cursor.mmio = %p\n", crtc->cursor.mmio);
crtc->cursor.maxH = crtc->cursor.maxW = 64;
crtc->cursor.size = crtc->cursor.maxH*crtc->cursor.maxW*2/8;
crtc->cursor.disable = hw_cursor_disable;
crtc->cursor.enable = hw_cursor_enable;
crtc->cursor.setColor = hw_cursor_setColor;
crtc->cursor.setPos = hw_cursor_setPos;
crtc->cursor.setSize = hw_cursor_setSize;
crtc->cursor.setData = hw_cursor_setData;
crtc->cursor.vstart = share->pvMem + crtc->cursor.offset;
crtc->cursor.share = share;
memset_io(crtc->cursor.vstart, 0, crtc->cursor.size);
if (!g_hwcursor) {
lynxfb_ops.fb_cursor = NULL;
crtc->cursor.disable(&crtc->cursor);
}
if (!share->accel_off) {
lynxfb_ops.fb_fillrect = lynxfb_ops_fillrect;
lynxfb_ops.fb_copyarea = lynxfb_ops_copyarea;
lynxfb_ops.fb_imageblit = lynxfb_ops_imageblit;
}
info->fbops = &lynxfb_ops;
if (!g_fbmode[index]) {
g_fbmode[index] = g_def_fbmode;
if (index)
g_fbmode[index] = g_fbmode[0];
}
for (i = 0; i < 3; i++) {
ret = fb_find_mode(var, info, g_fbmode[index],
pdb[i], cdb[i], NULL, 8);
if (ret == 1) {
pr_info("success! use specified mode:%s in %s\n",
g_fbmode[index],
mdb_desc[i]);
break;
} else if (ret == 2) {
pr_warn("use specified mode:%s in %s,with an ignored refresh rate\n",
g_fbmode[index],
mdb_desc[i]);
break;
} else if (ret == 3) {
pr_warn("wanna use default mode\n");
} else if (ret == 4) {
pr_warn("fall back to any valid mode\n");
} else {
pr_warn("ret = %d,fb_find_mode failed,with %s\n",
ret,
mdb_desc[i]);
}
}
pr_info("Member of info->var is :\n\
xres=%d\n\
yres=%d\n\
xres_virtual=%d\n\
yres_virtual=%d\n\
xoffset=%d\n\
yoffset=%d\n\
bits_per_pixel=%d\n \
...\n",
var->xres,
var->yres,
var->xres_virtual,
var->yres_virtual,
var->xoffset,
var->yoffset,
var->bits_per_pixel);
par->info = info;
line_length = PADDING(crtc->line_pad,
(var->xres_virtual * var->bits_per_pixel/8));
info->pseudo_palette = &par->pseudo_palette[0];
info->screen_base = crtc->vScreen;
pr_debug("screen_base vaddr = %p\n", info->screen_base);
info->screen_size = line_length * var->yres_virtual;
info->flags = FBINFO_FLAG_DEFAULT|0;
fix->type = FB_TYPE_PACKED_PIXELS;
fix->type_aux = 0;
fix->xpanstep = crtc->xpanstep;
fix->ypanstep = crtc->ypanstep;
fix->ywrapstep = crtc->ywrapstep;
fix->accel = FB_ACCEL_SMI;
strlcpy(fix->id, fixId[index], sizeof(fix->id));
fix->smem_start = crtc->oScreen + share->vidmem_start;
pr_info("fix->smem_start = %lx\n", fix->smem_start);
fix->smem_len = crtc->vidmem_size;
pr_info("fix->smem_len = %x\n", fix->smem_len);
info->screen_size = fix->smem_len;
fix->line_length = line_length;
fix->mmio_start = share->vidreg_start;
pr_info("fix->mmio_start = %lx\n", fix->mmio_start);
fix->mmio_len = share->vidreg_size;
pr_info("fix->mmio_len = %x\n", fix->mmio_len);
switch (var->bits_per_pixel) {
case 8:
fix->visual = FB_VISUAL_PSEUDOCOLOR;
break;
case 16:
case 32:
fix->visual = FB_VISUAL_TRUECOLOR;
break;
}
var->activate = FB_ACTIVATE_NOW;
var->accel_flags = 0;
var->vmode = FB_VMODE_NONINTERLACED;
pr_debug("#1 show info->cmap : \nstart=%d,len=%d,red=%p,green=%p,blue=%p,transp=%p\n",
info->cmap.start, info->cmap.len,
info->cmap.red, info->cmap.green, info->cmap.blue,
info->cmap.transp);
ret = fb_alloc_cmap(&info->cmap, 256, 0);
if (ret < 0) {
pr_err("Could not allcate memory for cmap.\n");
goto exit;
}
pr_debug("#2 show info->cmap :\nstart=%d,len=%d,red=%p,green=%p,blue=%p,transp=%p\n",
info->cmap.start, info->cmap.len,
info->cmap.red, info->cmap.green, info->cmap.blue,
info->cmap.transp);
exit:
lynxfb_ops_check_var(var, info);
return ret;
}
static void sm750fb_setup(struct lynx_share *share, char *src)
{
struct sm750_share *spec_share;
char *opt;
#ifdef CAP_EXPENSION
char *exp_res;
#endif
int swap;
spec_share = container_of(share, struct sm750_share, share);
#ifdef CAP_EXPENSIION
exp_res = NULL;
#endif
swap = 0;
spec_share->state.initParm.chip_clk = 0;
spec_share->state.initParm.mem_clk = 0;
spec_share->state.initParm.master_clk = 0;
spec_share->state.initParm.powerMode = 0;
spec_share->state.initParm.setAllEngOff = 0;
spec_share->state.initParm.resetMemory = 1;
g_hwcursor = 3;
if (!src || !*src) {
pr_warn("no specific g_option.\n");
goto NO_PARAM;
}
while ((opt = strsep(&src, ":")) != NULL && *opt != 0) {
pr_err("opt=%s\n", opt);
pr_err("src=%s\n", src);
if (!strncmp(opt, "swap", strlen("swap")))
swap = 1;
else if (!strncmp(opt, "nocrt", strlen("nocrt")))
spec_share->state.nocrt = 1;
else if (!strncmp(opt, "36bit", strlen("36bit")))
spec_share->state.pnltype = sm750_doubleTFT;
else if (!strncmp(opt, "18bit", strlen("18bit")))
spec_share->state.pnltype = sm750_dualTFT;
else if (!strncmp(opt, "24bit", strlen("24bit")))
spec_share->state.pnltype = sm750_24TFT;
#ifdef CAP_EXPANSION
else if (!strncmp(opt, "exp:", strlen("exp:")))
exp_res = opt + strlen("exp:");
#endif
else if (!strncmp(opt, "nohwc0", strlen("nohwc0")))
g_hwcursor &= ~0x1;
else if (!strncmp(opt, "nohwc1", strlen("nohwc1")))
g_hwcursor &= ~0x2;
else if (!strncmp(opt, "nohwc", strlen("nohwc")))
g_hwcursor = 0;
else {
if (!g_fbmode[0]) {
g_fbmode[0] = opt;
pr_info("find fbmode0 : %s\n", g_fbmode[0]);
} else if (!g_fbmode[1]) {
g_fbmode[1] = opt;
pr_info("find fbmode1 : %s\n", g_fbmode[1]);
} else {
pr_warn("How many view you wann set?\n");
}
}
}
#ifdef CAP_EXPANSION
if (getExpRes(exp_res,
&spec_share->state.xLCD,
&spec_share->state.yLCD)) {
spec_share->state.xLCD = spec_share->state.yLCD = 0;
}
#endif
NO_PARAM:
if (share->revid != SM750LE_REVISION_ID) {
if (share->dual) {
if (swap)
spec_share->state.dataflow = sm750_dual_swap;
else
spec_share->state.dataflow = sm750_dual_normal;
} else {
if (swap)
spec_share->state.dataflow = sm750_simul_sec;
else
spec_share->state.dataflow = sm750_simul_pri;
}
} else {
spec_share->state.dataflow = sm750_simul_sec;
spec_share->state.nocrt = 0;
}
}
static int lynxfb_pci_probe(struct pci_dev *pdev,
const struct pci_device_id * ent)
{
struct fb_info *info[] = {NULL, NULL};
struct lynx_share *share = NULL;
struct sm750_share *spec_share = NULL;
size_t spec_offset = 0;
int fbidx;
if (pci_enable_device(pdev)) {
pr_err("can not enable device.\n");
goto err_enable;
}
spec_offset = offsetof(struct sm750_share, share);
spec_share = kzalloc(sizeof(*spec_share), GFP_KERNEL);
if (!spec_share) {
pr_err("Could not allocate memory for share.\n");
goto err_share;
}
share = (struct lynx_share *)(&(spec_share->share));
share->fbinfo[0] = share->fbinfo[1] = NULL;
share->devid = pdev->device;
share->revid = pdev->revision;
pr_info("share->revid = %02x\n", share->revid);
share->pdev = pdev;
#ifdef CONFIG_MTRR
share->mtrr_off = g_nomtrr;
share->mtrr.vram = 0;
share->mtrr.vram_added = 0;
#endif
share->accel_off = g_noaccel;
share->dual = g_dualview;
spin_lock_init(&share->slock);
if (!share->accel_off) {
share->accel.de_init = hw_de_init;
share->accel.de_fillrect = hw_fillrect;
share->accel.de_copyarea = hw_copyarea;
share->accel.de_imageblit = hw_imageblit;
pr_info("enable 2d acceleration\n");
} else {
pr_info("disable 2d acceleration\n");
}
sm750fb_setup(share, g_settings);
if (hw_sm750_map(share, pdev)) {
pr_err("Memory map failed\n");
goto err_map;
}
#ifdef CONFIG_MTRR
if (!share->mtrr_off) {
pr_info("enable mtrr\n");
share->mtrr.vram = mtrr_add(share->vidmem_start,
share->vidmem_size,
MTRR_TYPE_WRCOMB, 1);
if (share->mtrr.vram < 0) {
pr_err("Unable to setup MTRR.\n");
} else {
share->mtrr.vram_added = 1;
pr_info("MTRR added succesfully\n");
}
}
#endif
memset_io(share->pvMem, 0, share->vidmem_size);
pr_info("sm%3x mmio address = %p\n", share->devid, share->pvReg);
pci_set_drvdata(pdev, share);
hw_sm750_inithw(share, pdev);
fbidx = 0;
ALLOC_FB:
info[fbidx] = framebuffer_alloc(sizeof(struct lynxfb_par), &pdev->dev);
if (!info[fbidx]) {
pr_err("Could not allocate framebuffer #%d.\n", fbidx);
if (fbidx == 0)
goto err_info0_alloc;
else
goto err_info1_alloc;
} else {
struct lynxfb_par *par;
int errno;
pr_info("framebuffer #%d alloc okay\n", fbidx);
share->fbinfo[fbidx] = info[fbidx];
par = info[fbidx]->par;
par->share = share;
if (lynxfb_set_fbinfo(info[fbidx], fbidx)) {
pr_err("Failed to initial fb_info #%d.\n", fbidx);
if (fbidx == 0)
goto err_info0_set;
else
goto err_info1_set;
}
pr_info("Ready to register framebuffer #%d.\n", fbidx);
errno = register_framebuffer(info[fbidx]);
if (errno < 0) {
pr_err("Failed to register fb_info #%d. err %d\n",
fbidx,
errno);
if (fbidx == 0)
goto err_register0;
else
goto err_register1;
}
pr_info("Accomplished register framebuffer #%d.\n", fbidx);
}
fbidx++;
if (share->dual && fbidx < 2)
goto ALLOC_FB;
return 0;
err_register1:
err_info1_set:
framebuffer_release(info[1]);
err_info1_alloc:
unregister_framebuffer(info[0]);
err_register0:
err_info0_set:
framebuffer_release(info[0]);
err_info0_alloc:
err_map:
kfree(spec_share);
err_share:
err_enable:
return -ENODEV;
}
static void lynxfb_pci_remove(struct pci_dev *pdev)
{
struct fb_info *info;
struct lynx_share *share;
void *spec_share;
struct lynxfb_par *par;
int cnt;
cnt = 2;
share = pci_get_drvdata(pdev);
while (cnt-- > 0) {
info = share->fbinfo[cnt];
if (!info)
continue;
par = info->par;
unregister_framebuffer(info);
par->crtc.clear(&par->crtc);
par->output.clear(&par->output);
framebuffer_release(info);
}
#ifdef CONFIG_MTRR
if (share->mtrr.vram_added)
mtrr_del(share->mtrr.vram,
share->vidmem_start,
share->vidmem_size);
#endif
iounmap(share->pvReg);
iounmap(share->pvMem);
spec_share = container_of(share, struct sm750_share, share);
kfree(g_settings);
kfree(spec_share);
pci_set_drvdata(pdev, NULL);
}
static int __init lynxfb_setup(char *options)
{
int len;
char *opt, *tmp;
if (!options || !*options) {
pr_warn("no options.\n");
return 0;
}
pr_info("options:%s\n", options);
len = strlen(options) + 1;
g_settings = kzalloc(len, GFP_KERNEL);
if (!g_settings)
return -ENOMEM;
tmp = g_settings;
while ((opt = strsep(&options, ":")) != NULL) {
if (!strncmp(opt, "noaccel", strlen("noaccel")))
g_noaccel = 1;
#ifdef CONFIG_MTRR
else if (!strncmp(opt, "nomtrr", strlen("nomtrr")))
g_nomtrr = 1;
#endif
else if (!strncmp(opt, "dual", strlen("dual")))
g_dualview = 1;
else {
strcat(tmp, opt);
tmp += strlen(opt);
if (options != NULL)
*tmp++ = ':';
else
*tmp++ = 0;
}
}
pr_info("parameter left for chip specific analysis:%s\n", g_settings);
return 0;
}
static int __init lynxfb_init(void)
{
char *option;
int ret;
#ifdef MODULE
option = g_option;
#else
if (fb_get_options("sm750fb", &option))
return -ENODEV;
#endif
lynxfb_setup(option);
ret = pci_register_driver(&lynxfb_driver);
return ret;
}
static void __exit lynxfb_exit(void)
{
pci_unregister_driver(&lynxfb_driver);
}
