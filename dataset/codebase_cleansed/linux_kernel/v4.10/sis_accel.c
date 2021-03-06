static void
SiS300Sync(struct sis_video_info *ivideo)
{
SiS300Idle
}
static void
SiS300SetupForScreenToScreenCopy(struct sis_video_info *ivideo, int xdir, int ydir,
int rop, int trans_color)
{
SiS300SetupDSTColorDepth(ivideo->DstColor);
SiS300SetupSRCPitch(ivideo->video_linelength)
SiS300SetupDSTRect(ivideo->video_linelength, 0xffff)
if(trans_color != -1) {
SiS300SetupROP(0x0A)
SiS300SetupSRCTrans(trans_color)
SiS300SetupCMDFlag(TRANSPARENT_BITBLT)
} else {
SiS300SetupROP(sisALUConv[rop])
}
if(xdir > 0) {
SiS300SetupCMDFlag(X_INC)
}
if(ydir > 0) {
SiS300SetupCMDFlag(Y_INC)
}
}
static void
SiS300SubsequentScreenToScreenCopy(struct sis_video_info *ivideo, int src_x,
int src_y, int dst_x, int dst_y, int width, int height)
{
u32 srcbase = 0, dstbase = 0;
if(src_y >= 2048) {
srcbase = ivideo->video_linelength * src_y;
src_y = 0;
}
if(dst_y >= 2048) {
dstbase = ivideo->video_linelength * dst_y;
dst_y = 0;
}
SiS300SetupSRCBase(srcbase);
SiS300SetupDSTBase(dstbase);
if(!(ivideo->CommandReg & X_INC)) {
src_x += width-1;
dst_x += width-1;
}
if(!(ivideo->CommandReg & Y_INC)) {
src_y += height-1;
dst_y += height-1;
}
SiS300SetupRect(width, height)
SiS300SetupSRCXY(src_x, src_y)
SiS300SetupDSTXY(dst_x, dst_y)
SiS300DoCMD
}
static void
SiS300SetupForSolidFill(struct sis_video_info *ivideo, u32 color, int rop)
{
SiS300SetupPATFG(color)
SiS300SetupDSTRect(ivideo->video_linelength, 0xffff)
SiS300SetupDSTColorDepth(ivideo->DstColor);
SiS300SetupROP(sisPatALUConv[rop])
SiS300SetupCMDFlag(PATFG)
}
static void
SiS300SubsequentSolidFillRect(struct sis_video_info *ivideo, int x, int y, int w, int h)
{
u32 dstbase = 0;
if(y >= 2048) {
dstbase = ivideo->video_linelength * y;
y = 0;
}
SiS300SetupDSTBase(dstbase)
SiS300SetupDSTXY(x,y)
SiS300SetupRect(w,h)
SiS300SetupCMDFlag(X_INC | Y_INC | BITBLT)
SiS300DoCMD
}
static void
SiS310Sync(struct sis_video_info *ivideo)
{
SiS310Idle
}
static void
SiS310SetupForScreenToScreenCopy(struct sis_video_info *ivideo, int rop, int trans_color)
{
SiS310SetupDSTColorDepth(ivideo->DstColor);
SiS310SetupSRCPitch(ivideo->video_linelength)
SiS310SetupDSTRect(ivideo->video_linelength, 0x0fff)
if(trans_color != -1) {
SiS310SetupROP(0x0A)
SiS310SetupSRCTrans(trans_color)
SiS310SetupCMDFlag(TRANSPARENT_BITBLT)
} else {
SiS310SetupROP(sisALUConv[rop])
}
SiS310SetupCMDFlag(ivideo->SiS310_AccelDepth)
}
static void
SiS310SubsequentScreenToScreenCopy(struct sis_video_info *ivideo, int src_x, int src_y,
int dst_x, int dst_y, int width, int height)
{
u32 srcbase = 0, dstbase = 0;
int mymin = min(src_y, dst_y);
int mymax = max(src_y, dst_y);
if((mymax - mymin) < height) {
if((src_y >= 2048) || (dst_y >= 2048)) {
srcbase = ivideo->video_linelength * mymin;
dstbase = ivideo->video_linelength * mymin;
src_y -= mymin;
dst_y -= mymin;
}
} else {
if(src_y >= 2048) {
srcbase = ivideo->video_linelength * src_y;
src_y = 0;
}
if(dst_y >= 2048) {
dstbase = ivideo->video_linelength * dst_y;
dst_y = 0;
}
}
srcbase += ivideo->video_offset;
dstbase += ivideo->video_offset;
SiS310SetupSRCBase(srcbase);
SiS310SetupDSTBase(dstbase);
SiS310SetupRect(width, height)
SiS310SetupSRCXY(src_x, src_y)
SiS310SetupDSTXY(dst_x, dst_y)
SiS310DoCMD
}
static void
SiS310SetupForSolidFill(struct sis_video_info *ivideo, u32 color, int rop)
{
SiS310SetupPATFG(color)
SiS310SetupDSTRect(ivideo->video_linelength, 0x0fff)
SiS310SetupDSTColorDepth(ivideo->DstColor);
SiS310SetupROP(sisPatALUConv[rop])
SiS310SetupCMDFlag(PATFG | ivideo->SiS310_AccelDepth)
}
static void
SiS310SubsequentSolidFillRect(struct sis_video_info *ivideo, int x, int y, int w, int h)
{
u32 dstbase = 0;
if(y >= 2048) {
dstbase = ivideo->video_linelength * y;
y = 0;
}
dstbase += ivideo->video_offset;
SiS310SetupDSTBase(dstbase)
SiS310SetupDSTXY(x,y)
SiS310SetupRect(w,h)
SiS310SetupCMDFlag(BITBLT)
SiS310DoCMD
}
int sisfb_initaccel(struct sis_video_info *ivideo)
{
#ifdef SISFB_USE_SPINLOCKS
spin_lock_init(&ivideo->lockaccel);
#endif
return 0;
}
void sisfb_syncaccel(struct sis_video_info *ivideo)
{
if(ivideo->sisvga_engine == SIS_300_VGA) {
#ifdef CONFIG_FB_SIS_300
SiS300Sync(ivideo);
#endif
} else {
#ifdef CONFIG_FB_SIS_315
SiS310Sync(ivideo);
#endif
}
}
int fbcon_sis_sync(struct fb_info *info)
{
struct sis_video_info *ivideo = (struct sis_video_info *)info->par;
CRITFLAGS
if((!ivideo->accel) || (!ivideo->engineok))
return 0;
CRITBEGIN
sisfb_syncaccel(ivideo);
CRITEND
return 0;
}
void fbcon_sis_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct sis_video_info *ivideo = (struct sis_video_info *)info->par;
u32 col = 0;
u32 vxres = info->var.xres_virtual;
u32 vyres = info->var.yres_virtual;
int width, height;
CRITFLAGS
if(info->state != FBINFO_STATE_RUNNING)
return;
if((!ivideo->accel) || (!ivideo->engineok)) {
cfb_fillrect(info, rect);
return;
}
if(!rect->width || !rect->height || rect->dx >= vxres || rect->dy >= vyres)
return;
width = ((rect->dx + rect->width) > vxres) ? (vxres - rect->dx) : rect->width;
height = ((rect->dy + rect->height) > vyres) ? (vyres - rect->dy) : rect->height;
switch(info->var.bits_per_pixel) {
case 8: col = rect->color;
break;
case 16:
case 32: col = ((u32 *)(info->pseudo_palette))[rect->color];
break;
}
if(ivideo->sisvga_engine == SIS_300_VGA) {
#ifdef CONFIG_FB_SIS_300
CRITBEGIN
SiS300SetupForSolidFill(ivideo, col, myrops[rect->rop]);
SiS300SubsequentSolidFillRect(ivideo, rect->dx, rect->dy, width, height);
CRITEND
#endif
} else {
#ifdef CONFIG_FB_SIS_315
CRITBEGIN
SiS310SetupForSolidFill(ivideo, col, myrops[rect->rop]);
SiS310SubsequentSolidFillRect(ivideo, rect->dx, rect->dy, width, height);
CRITEND
#endif
}
sisfb_syncaccel(ivideo);
}
void fbcon_sis_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct sis_video_info *ivideo = (struct sis_video_info *)info->par;
u32 vxres = info->var.xres_virtual;
u32 vyres = info->var.yres_virtual;
int width = area->width;
int height = area->height;
CRITFLAGS
if(info->state != FBINFO_STATE_RUNNING)
return;
if((!ivideo->accel) || (!ivideo->engineok)) {
cfb_copyarea(info, area);
return;
}
if(!width || !height ||
area->sx >= vxres || area->sy >= vyres ||
area->dx >= vxres || area->dy >= vyres)
return;
if((area->sx + width) > vxres) width = vxres - area->sx;
if((area->dx + width) > vxres) width = vxres - area->dx;
if((area->sy + height) > vyres) height = vyres - area->sy;
if((area->dy + height) > vyres) height = vyres - area->dy;
if(ivideo->sisvga_engine == SIS_300_VGA) {
#ifdef CONFIG_FB_SIS_300
int xdir, ydir;
if(area->sx < area->dx) xdir = 0;
else xdir = 1;
if(area->sy < area->dy) ydir = 0;
else ydir = 1;
CRITBEGIN
SiS300SetupForScreenToScreenCopy(ivideo, xdir, ydir, 3, -1);
SiS300SubsequentScreenToScreenCopy(ivideo, area->sx, area->sy,
area->dx, area->dy, width, height);
CRITEND
#endif
} else {
#ifdef CONFIG_FB_SIS_315
CRITBEGIN
SiS310SetupForScreenToScreenCopy(ivideo, 3, -1);
SiS310SubsequentScreenToScreenCopy(ivideo, area->sx, area->sy,
area->dx, area->dy, width, height);
CRITEND
#endif
}
sisfb_syncaccel(ivideo);
}
