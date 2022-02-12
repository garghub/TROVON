static int get_video_mode(char *vname)
{
char ***name_list;
char **name;
int i;
name_list = fb_var_names;
for (i = 0; i < num_atafb_predefined; i++) {
name = *name_list++;
if (!name || !*name)
break;
while (*name) {
if (!strcmp(vname, *name))
return i + 1;
name++;
}
}
return 0;
}
static int tt_encode_fix(struct fb_fix_screeninfo *fix, struct atafb_par *par)
{
int mode;
strcpy(fix->id, "Atari Builtin");
fix->smem_start = phys_screen_base;
fix->smem_len = screen_len;
fix->type = FB_TYPE_INTERLEAVED_PLANES;
fix->type_aux = 2;
fix->visual = FB_VISUAL_PSEUDOCOLOR;
mode = par->hw.tt.mode & TT_SHIFTER_MODEMASK;
if (mode == TT_SHIFTER_TTHIGH || mode == TT_SHIFTER_STHIGH) {
fix->type = FB_TYPE_PACKED_PIXELS;
fix->type_aux = 0;
if (mode == TT_SHIFTER_TTHIGH)
fix->visual = FB_VISUAL_MONO01;
}
fix->xpanstep = 0;
fix->ypanstep = 1;
fix->ywrapstep = 0;
fix->line_length = par->next_line;
fix->accel = FB_ACCEL_ATARIBLITT;
return 0;
}
static int tt_decode_var(struct fb_var_screeninfo *var, struct atafb_par *par)
{
int xres = var->xres;
int yres = var->yres;
int bpp = var->bits_per_pixel;
int linelen;
int yres_virtual = var->yres_virtual;
if (mono_moni) {
if (bpp > 1 || xres > sttt_xres * 2 || yres > tt_yres * 2)
return -EINVAL;
par->hw.tt.mode = TT_SHIFTER_TTHIGH;
xres = sttt_xres * 2;
yres = tt_yres * 2;
bpp = 1;
} else {
if (bpp > 8 || xres > sttt_xres || yres > tt_yres)
return -EINVAL;
if (bpp > 4) {
if (xres > sttt_xres / 2 || yres > tt_yres)
return -EINVAL;
par->hw.tt.mode = TT_SHIFTER_TTLOW;
xres = sttt_xres / 2;
yres = tt_yres;
bpp = 8;
} else if (bpp > 2) {
if (xres > sttt_xres || yres > tt_yres)
return -EINVAL;
if (xres > sttt_xres / 2 || yres > st_yres / 2) {
par->hw.tt.mode = TT_SHIFTER_TTMID;
xres = sttt_xres;
yres = tt_yres;
bpp = 4;
} else {
par->hw.tt.mode = TT_SHIFTER_STLOW;
xres = sttt_xres / 2;
yres = st_yres / 2;
bpp = 4;
}
} else if (bpp > 1) {
if (xres > sttt_xres || yres > st_yres / 2)
return -EINVAL;
par->hw.tt.mode = TT_SHIFTER_STMID;
xres = sttt_xres;
yres = st_yres / 2;
bpp = 2;
} else if (var->xres > sttt_xres || var->yres > st_yres) {
return -EINVAL;
} else {
par->hw.tt.mode = TT_SHIFTER_STHIGH;
xres = sttt_xres;
yres = st_yres;
bpp = 1;
}
}
if (yres_virtual <= 0)
yres_virtual = 0;
else if (yres_virtual < yres)
yres_virtual = yres;
if (var->sync & FB_SYNC_EXT)
par->hw.tt.sync = 0;
else
par->hw.tt.sync = 1;
linelen = xres * bpp / 8;
if (yres_virtual * linelen > screen_len && screen_len)
return -EINVAL;
if (yres * linelen > screen_len && screen_len)
return -EINVAL;
if (var->yoffset + yres > yres_virtual && yres_virtual)
return -EINVAL;
par->yres_virtual = yres_virtual;
par->screen_base = screen_base + var->yoffset * linelen;
par->next_line = linelen;
return 0;
}
static int tt_encode_var(struct fb_var_screeninfo *var, struct atafb_par *par)
{
int linelen;
memset(var, 0, sizeof(struct fb_var_screeninfo));
var->red.offset = 0;
var->red.length = 4;
var->red.msb_right = 0;
var->grayscale = 0;
var->pixclock = 31041;
var->left_margin = 120;
var->right_margin = 100;
var->upper_margin = 8;
var->lower_margin = 16;
var->hsync_len = 140;
var->vsync_len = 30;
var->height = -1;
var->width = -1;
if (par->hw.tt.sync & 1)
var->sync = 0;
else
var->sync = FB_SYNC_EXT;
switch (par->hw.tt.mode & TT_SHIFTER_MODEMASK) {
case TT_SHIFTER_STLOW:
var->xres = sttt_xres / 2;
var->xres_virtual = sttt_xres_virtual / 2;
var->yres = st_yres / 2;
var->bits_per_pixel = 4;
break;
case TT_SHIFTER_STMID:
var->xres = sttt_xres;
var->xres_virtual = sttt_xres_virtual;
var->yres = st_yres / 2;
var->bits_per_pixel = 2;
break;
case TT_SHIFTER_STHIGH:
var->xres = sttt_xres;
var->xres_virtual = sttt_xres_virtual;
var->yres = st_yres;
var->bits_per_pixel = 1;
break;
case TT_SHIFTER_TTLOW:
var->xres = sttt_xres / 2;
var->xres_virtual = sttt_xres_virtual / 2;
var->yres = tt_yres;
var->bits_per_pixel = 8;
break;
case TT_SHIFTER_TTMID:
var->xres = sttt_xres;
var->xres_virtual = sttt_xres_virtual;
var->yres = tt_yres;
var->bits_per_pixel = 4;
break;
case TT_SHIFTER_TTHIGH:
var->red.length = 0;
var->xres = sttt_xres * 2;
var->xres_virtual = sttt_xres_virtual * 2;
var->yres = tt_yres * 2;
var->bits_per_pixel = 1;
break;
}
var->blue = var->green = var->red;
var->transp.offset = 0;
var->transp.length = 0;
var->transp.msb_right = 0;
linelen = var->xres_virtual * var->bits_per_pixel / 8;
if (!use_hwscroll)
var->yres_virtual = var->yres;
else if (screen_len) {
if (par->yres_virtual)
var->yres_virtual = par->yres_virtual;
else
var->yres_virtual = screen_len / linelen;
} else {
if (hwscroll < 0)
var->yres_virtual = 2 * var->yres;
else
var->yres_virtual = var->yres + hwscroll * 16;
}
var->xoffset = 0;
if (screen_base)
var->yoffset = (par->screen_base - screen_base) / linelen;
else
var->yoffset = 0;
var->nonstd = 0;
var->activate = 0;
var->vmode = FB_VMODE_NONINTERLACED;
return 0;
}
static void tt_get_par(struct atafb_par *par)
{
unsigned long addr;
par->hw.tt.mode = shifter_tt.tt_shiftmode;
par->hw.tt.sync = shifter.syncmode;
addr = ((shifter.bas_hi & 0xff) << 16) |
((shifter.bas_md & 0xff) << 8) |
((shifter.bas_lo & 0xff));
par->screen_base = atari_stram_to_virt(addr);
}
static void tt_set_par(struct atafb_par *par)
{
shifter_tt.tt_shiftmode = par->hw.tt.mode;
shifter.syncmode = par->hw.tt.sync;
if (current_par.screen_base != par->screen_base)
fbhw->set_screen_base(par->screen_base);
}
static int tt_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
if ((shifter_tt.tt_shiftmode & TT_SHIFTER_MODEMASK) == TT_SHIFTER_STHIGH)
regno += 254;
if (regno > 255)
return 1;
tt_palette[regno] = (((red >> 12) << 8) | ((green >> 12) << 4) |
(blue >> 12));
if ((shifter_tt.tt_shiftmode & TT_SHIFTER_MODEMASK) ==
TT_SHIFTER_STHIGH && regno == 254)
tt_palette[0] = 0;
return 0;
}
static int tt_detect(void)
{
struct atafb_par par;
if (ATARIHW_PRESENT(PCM_8BIT)) {
tt_dmasnd.ctrl = DMASND_CTRL_OFF;
udelay(20);
}
mono_moni = (st_mfp.par_dt_reg & 0x80) == 0;
tt_get_par(&par);
tt_encode_var(&atafb_predefined[0], &par);
return 1;
}
static inline int hxx_prescale(struct falcon_hw *hw)
{
return hw->ste_mode ? 16
: vdl_prescale[mon_type][hw->vid_mode >> 2 & 0x3];
}
static int falcon_encode_fix(struct fb_fix_screeninfo *fix,
struct atafb_par *par)
{
strcpy(fix->id, "Atari Builtin");
fix->smem_start = phys_screen_base;
fix->smem_len = screen_len;
fix->type = FB_TYPE_INTERLEAVED_PLANES;
fix->type_aux = 2;
fix->visual = FB_VISUAL_PSEUDOCOLOR;
fix->xpanstep = 1;
fix->ypanstep = 1;
fix->ywrapstep = 0;
if (par->hw.falcon.mono) {
fix->type = FB_TYPE_PACKED_PIXELS;
fix->type_aux = 0;
fix->xpanstep = 32;
} else if (par->hw.falcon.f_shift & 0x100) {
fix->type = FB_TYPE_PACKED_PIXELS;
fix->type_aux = 0;
fix->visual = FB_VISUAL_TRUECOLOR;
fix->xpanstep = 2;
}
fix->line_length = par->next_line;
fix->accel = FB_ACCEL_ATARIBLITT;
return 0;
}
static int falcon_decode_var(struct fb_var_screeninfo *var,
struct atafb_par *par)
{
int bpp = var->bits_per_pixel;
int xres = var->xres;
int yres = var->yres;
int xres_virtual = var->xres_virtual;
int yres_virtual = var->yres_virtual;
int left_margin, right_margin, hsync_len;
int upper_margin, lower_margin, vsync_len;
int linelen;
int interlace = 0, doubleline = 0;
struct pixel_clock *pclock;
int plen;
int xstretch;
int prescale;
int longoffset = 0;
int hfreq, vfreq;
int hdb_off, hde_off, base_off;
int gstart, gend1, gend2, align;
if (!xres || !yres || !bpp)
return -EINVAL;
if (mon_type == F_MON_SM && bpp != 1)
return -EINVAL;
if (bpp <= 1) {
bpp = 1;
par->hw.falcon.f_shift = 0x400;
par->hw.falcon.st_shift = 0x200;
} else if (bpp <= 2) {
bpp = 2;
par->hw.falcon.f_shift = 0x000;
par->hw.falcon.st_shift = 0x100;
} else if (bpp <= 4) {
bpp = 4;
par->hw.falcon.f_shift = 0x000;
par->hw.falcon.st_shift = 0x000;
} else if (bpp <= 8) {
bpp = 8;
par->hw.falcon.f_shift = 0x010;
} else if (bpp <= 16) {
bpp = 16;
par->hw.falcon.f_shift = 0x100;
} else
return -EINVAL;
par->hw.falcon.bpp = bpp;
if (mon_type == F_MON_SM || DontCalcRes) {
struct fb_var_screeninfo *myvar = &atafb_predefined[0];
if (bpp > myvar->bits_per_pixel ||
var->xres > myvar->xres ||
var->yres > myvar->yres)
return -EINVAL;
fbhw->get_par(par);
goto set_screen_base;
}
if (xres <= 320)
xres = 320;
else if (xres <= 640 && bpp != 16)
xres = 640;
if (yres <= 200)
yres = 200;
else if (yres <= 240)
yres = 240;
else if (yres <= 400)
yres = 400;
par->hw.falcon.ste_mode = bpp == 2;
par->hw.falcon.mono = bpp == 1;
if (par->hw.falcon.ste_mode)
xres = (xres + 63) & ~63;
else if (bpp == 1)
xres = (xres + 31) & ~31;
else
xres = (xres + 15) & ~15;
if (yres >= 400)
yres = (yres + 15) & ~15;
else
yres = (yres + 7) & ~7;
if (xres_virtual < xres)
xres_virtual = xres;
else if (bpp == 1)
xres_virtual = (xres_virtual + 31) & ~31;
else
xres_virtual = (xres_virtual + 15) & ~15;
if (yres_virtual <= 0)
yres_virtual = 0;
else if (yres_virtual < yres)
yres_virtual = yres;
if (var->pixclock > 1)
var->pixclock -= 1;
par->hw.falcon.line_width = bpp * xres / 16;
par->hw.falcon.line_offset = bpp * (xres_virtual - xres) / 16;
xstretch = (xres < 640) ? 2 : 1;
#if 0
if (mon_type == F_MON_SM) {
if (xres != 640 && yres != 400)
return -EINVAL;
plen = 1;
pclock = &f32;
par->hw.falcon.ste_mode = 1;
par->hw.falcon.f_shift = 0x000;
par->hw.falcon.st_shift = 0x200;
left_margin = hsync_len = 128 / plen;
right_margin = 0;
} else
#endif
if (mon_type == F_MON_SC || mon_type == F_MON_TV) {
plen = 2 * xstretch;
if (var->pixclock > f32.t * plen)
return -EINVAL;
pclock = &f32;
if (yres > 240)
interlace = 1;
if (var->pixclock == 0) {
left_margin = 32;
right_margin = 18;
hsync_len = pclock->hsync / plen;
upper_margin = 31;
lower_margin = 14;
vsync_len = interlace ? 3 : 4;
} else {
left_margin = var->left_margin;
right_margin = var->right_margin;
hsync_len = var->hsync_len;
upper_margin = var->upper_margin;
lower_margin = var->lower_margin;
vsync_len = var->vsync_len;
if (var->vmode & FB_VMODE_INTERLACED) {
upper_margin = (upper_margin + 1) / 2;
lower_margin = (lower_margin + 1) / 2;
vsync_len = (vsync_len + 1) / 2;
} else if (var->vmode & FB_VMODE_DOUBLE) {
upper_margin *= 2;
lower_margin *= 2;
vsync_len *= 2;
}
}
} else {
if (bpp == 16)
xstretch = 2;
if (var->pixclock == 0) {
int linesize;
plen = 1 * xstretch;
if ((plen * xres + f25.right + f25.hsync + f25.left) *
fb_info.monspecs.hfmin < f25.f)
pclock = &f25;
else if ((plen * xres + f32.right + f32.hsync +
f32.left) * fb_info.monspecs.hfmin < f32.f)
pclock = &f32;
else if ((plen * xres + fext.right + fext.hsync +
fext.left) * fb_info.monspecs.hfmin < fext.f &&
fext.f)
pclock = &fext;
else
return -EINVAL;
left_margin = pclock->left / plen;
right_margin = pclock->right / plen;
hsync_len = pclock->hsync / plen;
linesize = left_margin + xres + right_margin + hsync_len;
upper_margin = 31;
lower_margin = 11;
vsync_len = 3;
} else {
int i;
unsigned long pcl = ULONG_MAX;
pclock = 0;
for (i = 1; i <= 4; i *= 2) {
if (f25.t * i >= var->pixclock &&
f25.t * i < pcl) {
pcl = f25.t * i;
pclock = &f25;
}
if (f32.t * i >= var->pixclock &&
f32.t * i < pcl) {
pcl = f32.t * i;
pclock = &f32;
}
if (fext.t && fext.t * i >= var->pixclock &&
fext.t * i < pcl) {
pcl = fext.t * i;
pclock = &fext;
}
}
if (!pclock)
return -EINVAL;
plen = pcl / pclock->t;
left_margin = var->left_margin;
right_margin = var->right_margin;
hsync_len = var->hsync_len;
upper_margin = var->upper_margin;
lower_margin = var->lower_margin;
vsync_len = var->vsync_len;
if (var->vmode & FB_VMODE_INTERLACED) {
upper_margin = (upper_margin + 1) / 2;
lower_margin = (lower_margin + 1) / 2;
vsync_len = (vsync_len + 1) / 2;
} else if (var->vmode & FB_VMODE_DOUBLE) {
upper_margin *= 2;
lower_margin *= 2;
vsync_len *= 2;
}
}
if (pclock == &fext)
longoffset = 1;
}
if (pclock->f / plen / 8 * bpp > 32000000L)
return -EINVAL;
if (vsync_len < 1)
vsync_len = 1;
right_margin += hsync_len;
lower_margin += vsync_len;
again:
par->hw.falcon.vid_control = mon_type | f030_bus_width;
if (!longoffset)
par->hw.falcon.vid_control |= VCO_SHORTOFFS;
if (var->sync & FB_SYNC_HOR_HIGH_ACT)
par->hw.falcon.vid_control |= VCO_HSYPOS;
if (var->sync & FB_SYNC_VERT_HIGH_ACT)
par->hw.falcon.vid_control |= VCO_VSYPOS;
par->hw.falcon.vid_control |= pclock->control_mask;
par->hw.falcon.sync = pclock->sync_mask | 0x2;
par->hw.falcon.vid_mode = (2 / plen) << 2;
if (doubleline)
par->hw.falcon.vid_mode |= VMO_DOUBLE;
if (interlace)
par->hw.falcon.vid_mode |= VMO_INTER;
{
prescale = hxx_prescale(&par->hw.falcon);
base_off = par->hw.falcon.vid_control & VCO_SHORTOFFS ? 64 : 128;
if (par->hw.falcon.f_shift & 0x100) {
align = 1;
hde_off = 0;
hdb_off = (base_off + 16 * plen) + prescale;
} else {
align = 128 / bpp;
hde_off = ((128 / bpp + 2) * plen);
if (par->hw.falcon.ste_mode)
hdb_off = (64 + base_off + (128 / bpp + 2) * plen) + prescale;
else
hdb_off = (base_off + (128 / bpp + 18) * plen) + prescale;
}
gstart = (prescale / 2 + plen * left_margin) / prescale;
gend1 = gstart + roundup(xres, align) * plen / prescale;
gend2 = gstart + xres * plen / prescale;
par->HHT = plen * (left_margin + xres + right_margin) /
(2 * prescale) - 2;
par->HDB = gstart - hdb_off / prescale;
par->HBE = gstart;
if (par->HDB < 0)
par->HDB += par->HHT + 2 + 0x200;
par->HDE = gend1 - par->HHT - 2 - hde_off / prescale;
par->HBB = gend2 - par->HHT - 2;
#if 0
if ((par->HDB & 0x200) && (par->HDB & ~0x200) - par->HDE <= 5) {
}
#endif
if (hde_off % prescale)
par->HBB++;
par->HSS = par->HHT + 2 - plen * hsync_len / prescale;
if (par->HSS < par->HBB)
par->HSS = par->HBB;
}
hfreq = pclock->f / ((par->HHT + 2) * prescale * 2);
if (hfreq > fb_info.monspecs.hfmax && mon_type != F_MON_VGA) {
left_margin += 1;
right_margin += 1;
goto again;
}
if (hfreq > fb_info.monspecs.hfmax || hfreq < fb_info.monspecs.hfmin)
return -EINVAL;
par->VBE = (upper_margin * 2 + 1);
par->VDB = par->VBE;
par->VDE = yres;
if (!interlace)
par->VDE <<= 1;
if (doubleline)
par->VDE <<= 1;
par->VDE += par->VDB;
par->VBB = par->VDE;
par->VFT = par->VBB + (lower_margin * 2 - 1) - 1;
par->VSS = par->VFT + 1 - (vsync_len * 2 - 1);
if (interlace) {
par->VBB++;
par->VSS++;
par->VFT++;
}
vfreq = (hfreq * 2) / (par->VFT + 1);
if (vfreq > fb_info.monspecs.vfmax && !doubleline && !interlace) {
doubleline = 1;
goto again;
} else if (vfreq < fb_info.monspecs.vfmin && !interlace && !doubleline) {
interlace = 1;
goto again;
} else if (vfreq < fb_info.monspecs.vfmin && doubleline) {
int lines;
doubleline = 0;
for (lines = 0;
(hfreq * 2) / (par->VFT + 1 + 4 * lines - 2 * yres) >
fb_info.monspecs.vfmax;
lines++)
;
upper_margin += lines;
lower_margin += lines;
goto again;
} else if (vfreq > fb_info.monspecs.vfmax && doubleline) {
int lines;
for (lines = 0;
(hfreq * 2) / (par->VFT + 1 + 4 * lines) >
fb_info.monspecs.vfmax;
lines += 2)
;
upper_margin += lines;
lower_margin += lines;
goto again;
} else if (vfreq > fb_info.monspecs.vfmax && interlace) {
int lines;
for (lines = 0;
(hfreq * 2) / (par->VFT + 1 + 4 * lines) >
fb_info.monspecs.vfmax;
lines++)
;
upper_margin += lines;
lower_margin += lines;
goto again;
} else if (vfreq < fb_info.monspecs.vfmin ||
vfreq > fb_info.monspecs.vfmax)
return -EINVAL;
set_screen_base:
linelen = xres_virtual * bpp / 8;
if (yres_virtual * linelen > screen_len && screen_len)
return -EINVAL;
if (yres * linelen > screen_len && screen_len)
return -EINVAL;
if (var->yoffset + yres > yres_virtual && yres_virtual)
return -EINVAL;
par->yres_virtual = yres_virtual;
par->screen_base = screen_base + var->yoffset * linelen;
par->hw.falcon.xoffset = 0;
par->next_line = linelen;
return 0;
}
static int falcon_encode_var(struct fb_var_screeninfo *var,
struct atafb_par *par)
{
int linelen;
int prescale, plen;
int hdb_off, hde_off, base_off;
struct falcon_hw *hw = &par->hw.falcon;
memset(var, 0, sizeof(struct fb_var_screeninfo));
var->pixclock = hw->sync & 0x1 ? fext.t :
hw->vid_control & VCO_CLOCK25 ? f25.t : f32.t;
var->height = -1;
var->width = -1;
var->sync = 0;
if (hw->vid_control & VCO_HSYPOS)
var->sync |= FB_SYNC_HOR_HIGH_ACT;
if (hw->vid_control & VCO_VSYPOS)
var->sync |= FB_SYNC_VERT_HIGH_ACT;
var->vmode = FB_VMODE_NONINTERLACED;
if (hw->vid_mode & VMO_INTER)
var->vmode |= FB_VMODE_INTERLACED;
if (hw->vid_mode & VMO_DOUBLE)
var->vmode |= FB_VMODE_DOUBLE;
var->yres = hw->vde - hw->vdb;
if (!(var->vmode & FB_VMODE_INTERLACED))
var->yres >>= 1;
if (var->vmode & FB_VMODE_DOUBLE)
var->yres >>= 1;
if (hw->f_shift & 0x400)
var->bits_per_pixel = 1;
else if (hw->f_shift & 0x100)
var->bits_per_pixel = 16;
else if (hw->f_shift & 0x010)
var->bits_per_pixel = 8;
else if (hw->st_shift == 0)
var->bits_per_pixel = 4;
else if (hw->st_shift == 0x100)
var->bits_per_pixel = 2;
else
var->bits_per_pixel = 1;
var->xres = hw->line_width * 16 / var->bits_per_pixel;
var->xres_virtual = var->xres + hw->line_offset * 16 / var->bits_per_pixel;
if (hw->xoffset)
var->xres_virtual += 16;
if (var->bits_per_pixel == 16) {
var->red.offset = 11;
var->red.length = 5;
var->red.msb_right = 0;
var->green.offset = 5;
var->green.length = 6;
var->green.msb_right = 0;
var->blue.offset = 0;
var->blue.length = 5;
var->blue.msb_right = 0;
} else {
var->red.offset = 0;
var->red.length = hw->ste_mode ? 4 : 6;
if (var->red.length > var->bits_per_pixel)
var->red.length = var->bits_per_pixel;
var->red.msb_right = 0;
var->grayscale = 0;
var->blue = var->green = var->red;
}
var->transp.offset = 0;
var->transp.length = 0;
var->transp.msb_right = 0;
linelen = var->xres_virtual * var->bits_per_pixel / 8;
if (screen_len) {
if (par->yres_virtual)
var->yres_virtual = par->yres_virtual;
else
var->yres_virtual = screen_len / linelen;
} else {
if (hwscroll < 0)
var->yres_virtual = 2 * var->yres;
else
var->yres_virtual = var->yres + hwscroll * 16;
}
var->xoffset = 0;
prescale = hxx_prescale(hw);
plen = 4 >> (hw->vid_mode >> 2 & 0x3);
base_off = hw->vid_control & VCO_SHORTOFFS ? 64 : 128;
if (hw->f_shift & 0x100) {
hde_off = 0;
hdb_off = (base_off + 16 * plen) + prescale;
} else {
hde_off = ((128 / var->bits_per_pixel + 2) * plen);
if (hw->ste_mode)
hdb_off = (64 + base_off + (128 / var->bits_per_pixel + 2) * plen)
+ prescale;
else
hdb_off = (base_off + (128 / var->bits_per_pixel + 18) * plen)
+ prescale;
}
var->left_margin = hdb_off + prescale * ((hw->hdb & 0x1ff) -
(hw->hdb & 0x200 ? 2 + hw->hht : 0));
if (hw->ste_mode || mon_type != F_MON_VGA)
var->right_margin = prescale * (hw->hht + 2 - hw->hde) - hde_off;
else
var->right_margin = prescale * (hw->hht + 2 - hw->hbb);
var->hsync_len = prescale * (hw->hht + 2 - hw->hss);
var->upper_margin = hw->vdb / 2;
var->lower_margin = (hw->vft + 1 - hw->vde + 1) / 2;
var->vsync_len = (hw->vft + 1 - hw->vss + 1) / 2;
if (var->vmode & FB_VMODE_INTERLACED) {
var->upper_margin *= 2;
var->lower_margin *= 2;
var->vsync_len *= 2;
} else if (var->vmode & FB_VMODE_DOUBLE) {
var->upper_margin = (var->upper_margin + 1) / 2;
var->lower_margin = (var->lower_margin + 1) / 2;
var->vsync_len = (var->vsync_len + 1) / 2;
}
var->pixclock *= plen;
var->left_margin /= plen;
var->right_margin /= plen;
var->hsync_len /= plen;
var->right_margin -= var->hsync_len;
var->lower_margin -= var->vsync_len;
if (screen_base)
var->yoffset = (par->screen_base - screen_base) / linelen;
else
var->yoffset = 0;
var->nonstd = 0;
var->activate = 0;
return 0;
}
static void falcon_get_par(struct atafb_par *par)
{
unsigned long addr;
struct falcon_hw *hw = &par->hw.falcon;
hw->line_width = shifter_f030.scn_width;
hw->line_offset = shifter_f030.off_next;
hw->st_shift = videl.st_shift & 0x300;
hw->f_shift = videl.f_shift;
hw->vid_control = videl.control;
hw->vid_mode = videl.mode;
hw->sync = shifter.syncmode & 0x1;
hw->xoffset = videl.xoffset & 0xf;
hw->hht = videl.hht;
hw->hbb = videl.hbb;
hw->hbe = videl.hbe;
hw->hdb = videl.hdb;
hw->hde = videl.hde;
hw->hss = videl.hss;
hw->vft = videl.vft;
hw->vbb = videl.vbb;
hw->vbe = videl.vbe;
hw->vdb = videl.vdb;
hw->vde = videl.vde;
hw->vss = videl.vss;
addr = (shifter.bas_hi & 0xff) << 16 |
(shifter.bas_md & 0xff) << 8 |
(shifter.bas_lo & 0xff);
par->screen_base = atari_stram_to_virt(addr);
hw->ste_mode = (hw->f_shift & 0x510) == 0 && hw->st_shift == 0x100;
hw->mono = (hw->f_shift & 0x400) ||
((hw->f_shift & 0x510) == 0 && hw->st_shift == 0x200);
}
static void falcon_set_par(struct atafb_par *par)
{
f_change_mode = 0;
if (current_par.screen_base != par->screen_base)
fbhw->set_screen_base(par->screen_base);
if (DontCalcRes)
return;
f_new_mode = par->hw.falcon;
f_change_mode = 1;
}
static irqreturn_t falcon_vbl_switcher(int irq, void *dummy)
{
struct falcon_hw *hw = &f_new_mode;
if (f_change_mode) {
f_change_mode = 0;
if (hw->sync & 0x1) {
*(volatile unsigned short *)0xffff9202 = 0xffbf;
} else {
*(volatile unsigned short *)0xffff9202;
}
shifter.syncmode = hw->sync;
videl.hht = hw->hht;
videl.hbb = hw->hbb;
videl.hbe = hw->hbe;
videl.hdb = hw->hdb;
videl.hde = hw->hde;
videl.hss = hw->hss;
videl.vft = hw->vft;
videl.vbb = hw->vbb;
videl.vbe = hw->vbe;
videl.vdb = hw->vdb;
videl.vde = hw->vde;
videl.vss = hw->vss;
videl.f_shift = 0;
if (hw->ste_mode) {
videl.st_shift = hw->st_shift;
} else {
videl.st_shift = 0;
videl.f_shift = hw->f_shift;
}
videl.xoffset = hw->xoffset;
shifter_f030.scn_width = hw->line_width;
shifter_f030.off_next = hw->line_offset;
videl.control = hw->vid_control;
videl.mode = hw->vid_mode;
}
if (f_pan_display) {
f_pan_display = 0;
videl.xoffset = current_par.hw.falcon.xoffset;
shifter_f030.off_next = current_par.hw.falcon.line_offset;
}
return IRQ_HANDLED;
}
static int falcon_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct atafb_par *par = (struct atafb_par *)info->par;
int xoffset;
int bpp = info->var.bits_per_pixel;
if (bpp == 1)
var->xoffset = up(var->xoffset, 32);
if (bpp != 16)
par->hw.falcon.xoffset = var->xoffset & 15;
else {
par->hw.falcon.xoffset = 0;
var->xoffset = up(var->xoffset, 2);
}
par->hw.falcon.line_offset = bpp *
(info->var.xres_virtual - info->var.xres) / 16;
if (par->hw.falcon.xoffset)
par->hw.falcon.line_offset -= bpp;
xoffset = var->xoffset - par->hw.falcon.xoffset;
par->screen_base = screen_base +
(var->yoffset * info->var.xres_virtual + xoffset) * bpp / 8;
if (fbhw->set_screen_base)
fbhw->set_screen_base(par->screen_base);
else
return -EINVAL;
f_pan_display = 1;
return 0;
}
static int falcon_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
if (regno > 255)
return 1;
f030_col[regno] = (((red & 0xfc00) << 16) |
((green & 0xfc00) << 8) |
((blue & 0xfc00) >> 8));
if (regno < 16) {
shifter_tt.color_reg[regno] =
(((red & 0xe000) >> 13) | ((red & 0x1000) >> 12) << 8) |
(((green & 0xe000) >> 13) | ((green & 0x1000) >> 12) << 4) |
((blue & 0xe000) >> 13) | ((blue & 0x1000) >> 12);
((u32 *)info->pseudo_palette)[regno] = ((red & 0xf800) |
((green & 0xfc00) >> 5) |
((blue & 0xf800) >> 11));
}
return 0;
}
static int falcon_blank(int blank_mode)
{
int vdb, vss, hbe, hss;
if (mon_type == F_MON_SM)
return 1;
vdb = current_par.VDB;
vss = current_par.VSS;
hbe = current_par.HBE;
hss = current_par.HSS;
if (blank_mode >= 1) {
vdb = current_par.VFT + 1;
hbe = current_par.HHT + 2;
}
if (mon_type == F_MON_VGA) {
if (blank_mode == 2 || blank_mode == 4)
vss = current_par.VFT + 1;
if (blank_mode == 3 || blank_mode == 4)
hss = current_par.HHT + 2;
}
videl.vdb = vdb;
videl.vss = vss;
videl.hbe = hbe;
videl.hss = hss;
return 0;
}
static int falcon_detect(void)
{
struct atafb_par par;
unsigned char fhw;
fhw = *(unsigned char *)0xffff8006;
mon_type = fhw >> 6 & 0x3;
f030_bus_width = fhw << 6 & 0x80;
switch (mon_type) {
case F_MON_SM:
fb_info.monspecs.vfmin = 70;
fb_info.monspecs.vfmax = 72;
fb_info.monspecs.hfmin = 35713;
fb_info.monspecs.hfmax = 35715;
break;
case F_MON_SC:
case F_MON_TV:
fb_info.monspecs.vfmin = 49;
fb_info.monspecs.vfmax = 60;
fb_info.monspecs.hfmin = 15620;
fb_info.monspecs.hfmax = 15755;
break;
}
f25.hsync = h_syncs[mon_type] / f25.t;
f32.hsync = h_syncs[mon_type] / f32.t;
if (fext.t)
fext.hsync = h_syncs[mon_type] / fext.t;
falcon_get_par(&par);
falcon_encode_var(&atafb_predefined[0], &par);
return 1;
}
static int stste_encode_fix(struct fb_fix_screeninfo *fix,
struct atafb_par *par)
{
int mode;
strcpy(fix->id, "Atari Builtin");
fix->smem_start = phys_screen_base;
fix->smem_len = screen_len;
fix->type = FB_TYPE_INTERLEAVED_PLANES;
fix->type_aux = 2;
fix->visual = FB_VISUAL_PSEUDOCOLOR;
mode = par->hw.st.mode & 3;
if (mode == ST_HIGH) {
fix->type = FB_TYPE_PACKED_PIXELS;
fix->type_aux = 0;
fix->visual = FB_VISUAL_MONO10;
}
if (ATARIHW_PRESENT(EXTD_SHIFTER)) {
fix->xpanstep = 16;
fix->ypanstep = 1;
} else {
fix->xpanstep = 0;
fix->ypanstep = 0;
}
fix->ywrapstep = 0;
fix->line_length = par->next_line;
fix->accel = FB_ACCEL_ATARIBLITT;
return 0;
}
static int stste_decode_var(struct fb_var_screeninfo *var,
struct atafb_par *par)
{
int xres = var->xres;
int yres = var->yres;
int bpp = var->bits_per_pixel;
int linelen;
int yres_virtual = var->yres_virtual;
if (mono_moni) {
if (bpp > 1 || xres > sttt_xres || yres > st_yres)
return -EINVAL;
par->hw.st.mode = ST_HIGH;
xres = sttt_xres;
yres = st_yres;
bpp = 1;
} else {
if (bpp > 4 || xres > sttt_xres || yres > st_yres)
return -EINVAL;
if (bpp > 2) {
if (xres > sttt_xres / 2 || yres > st_yres / 2)
return -EINVAL;
par->hw.st.mode = ST_LOW;
xres = sttt_xres / 2;
yres = st_yres / 2;
bpp = 4;
} else if (bpp > 1) {
if (xres > sttt_xres || yres > st_yres / 2)
return -EINVAL;
par->hw.st.mode = ST_MID;
xres = sttt_xres;
yres = st_yres / 2;
bpp = 2;
} else
return -EINVAL;
}
if (yres_virtual <= 0)
yres_virtual = 0;
else if (yres_virtual < yres)
yres_virtual = yres;
if (var->sync & FB_SYNC_EXT)
par->hw.st.sync = (par->hw.st.sync & ~1) | 1;
else
par->hw.st.sync = (par->hw.st.sync & ~1);
linelen = xres * bpp / 8;
if (yres_virtual * linelen > screen_len && screen_len)
return -EINVAL;
if (yres * linelen > screen_len && screen_len)
return -EINVAL;
if (var->yoffset + yres > yres_virtual && yres_virtual)
return -EINVAL;
par->yres_virtual = yres_virtual;
par->screen_base = screen_base + var->yoffset * linelen;
par->next_line = linelen;
return 0;
}
static int stste_encode_var(struct fb_var_screeninfo *var,
struct atafb_par *par)
{
int linelen;
memset(var, 0, sizeof(struct fb_var_screeninfo));
var->red.offset = 0;
var->red.length = ATARIHW_PRESENT(EXTD_SHIFTER) ? 4 : 3;
var->red.msb_right = 0;
var->grayscale = 0;
var->pixclock = 31041;
var->left_margin = 120;
var->right_margin = 100;
var->upper_margin = 8;
var->lower_margin = 16;
var->hsync_len = 140;
var->vsync_len = 30;
var->height = -1;
var->width = -1;
if (!(par->hw.st.sync & 1))
var->sync = 0;
else
var->sync = FB_SYNC_EXT;
switch (par->hw.st.mode & 3) {
case ST_LOW:
var->xres = sttt_xres / 2;
var->yres = st_yres / 2;
var->bits_per_pixel = 4;
break;
case ST_MID:
var->xres = sttt_xres;
var->yres = st_yres / 2;
var->bits_per_pixel = 2;
break;
case ST_HIGH:
var->xres = sttt_xres;
var->yres = st_yres;
var->bits_per_pixel = 1;
break;
}
var->blue = var->green = var->red;
var->transp.offset = 0;
var->transp.length = 0;
var->transp.msb_right = 0;
var->xres_virtual = sttt_xres_virtual;
linelen = var->xres_virtual * var->bits_per_pixel / 8;
ovsc_addlen = linelen * (sttt_yres_virtual - st_yres);
if (!use_hwscroll)
var->yres_virtual = var->yres;
else if (screen_len) {
if (par->yres_virtual)
var->yres_virtual = par->yres_virtual;
else
var->yres_virtual = screen_len / linelen;
} else {
if (hwscroll < 0)
var->yres_virtual = 2 * var->yres;
else
var->yres_virtual = var->yres + hwscroll * 16;
}
var->xoffset = 0;
if (screen_base)
var->yoffset = (par->screen_base - screen_base) / linelen;
else
var->yoffset = 0;
var->nonstd = 0;
var->activate = 0;
var->vmode = FB_VMODE_NONINTERLACED;
return 0;
}
static void stste_get_par(struct atafb_par *par)
{
unsigned long addr;
par->hw.st.mode = shifter_tt.st_shiftmode;
par->hw.st.sync = shifter.syncmode;
addr = ((shifter.bas_hi & 0xff) << 16) |
((shifter.bas_md & 0xff) << 8);
if (ATARIHW_PRESENT(EXTD_SHIFTER))
addr |= (shifter.bas_lo & 0xff);
par->screen_base = atari_stram_to_virt(addr);
}
static void stste_set_par(struct atafb_par *par)
{
shifter_tt.st_shiftmode = par->hw.st.mode;
shifter.syncmode = par->hw.st.sync;
if (current_par.screen_base != par->screen_base)
fbhw->set_screen_base(par->screen_base);
}
static int stste_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
if (regno > 15)
return 1;
red >>= 12;
blue >>= 12;
green >>= 12;
if (ATARIHW_PRESENT(EXTD_SHIFTER))
shifter_tt.color_reg[regno] =
(((red & 0xe) >> 1) | ((red & 1) << 3) << 8) |
(((green & 0xe) >> 1) | ((green & 1) << 3) << 4) |
((blue & 0xe) >> 1) | ((blue & 1) << 3);
else
shifter_tt.color_reg[regno] =
((red & 0xe) << 7) |
((green & 0xe) << 3) |
((blue & 0xe) >> 1);
return 0;
}
static int stste_detect(void)
{
struct atafb_par par;
if (ATARIHW_PRESENT(PCM_8BIT)) {
tt_dmasnd.ctrl = DMASND_CTRL_OFF;
udelay(20);
}
mono_moni = (st_mfp.par_dt_reg & 0x80) == 0;
stste_get_par(&par);
stste_encode_var(&atafb_predefined[0], &par);
if (!ATARIHW_PRESENT(EXTD_SHIFTER))
use_hwscroll = 0;
return 1;
}
static void stste_set_screen_base(void *s_base)
{
unsigned long addr;
addr = atari_stram_to_phys(s_base);
shifter.bas_hi = (unsigned char)((addr & 0xff0000) >> 16);
shifter.bas_md = (unsigned char)((addr & 0x00ff00) >> 8);
if (ATARIHW_PRESENT(EXTD_SHIFTER))
shifter.bas_lo = (unsigned char)(addr & 0x0000ff);
}
static void st_ovsc_switch(void)
{
unsigned long flags;
register unsigned char old, new;
if (!(atari_switches & ATARI_SWITCH_OVSC_MASK))
return;
local_irq_save(flags);
st_mfp.tim_ct_b = 0x10;
st_mfp.active_edge |= 8;
st_mfp.tim_ct_b = 0;
st_mfp.tim_dt_b = 0xf0;
st_mfp.tim_ct_b = 8;
while (st_mfp.tim_dt_b > 1)
;
new = st_mfp.tim_dt_b;
do {
udelay(LINE_DELAY);
old = new;
new = st_mfp.tim_dt_b;
} while (old != new);
st_mfp.tim_ct_b = 0x10;
udelay(SYNC_DELAY);
if (atari_switches & ATARI_SWITCH_OVSC_IKBD)
acia.key_ctrl = ACIA_DIV64 | ACIA_D8N1S | ACIA_RHTID | ACIA_RIE;
if (atari_switches & ATARI_SWITCH_OVSC_MIDI)
acia.mid_ctrl = ACIA_DIV16 | ACIA_D8N1S | ACIA_RHTID;
if (atari_switches & (ATARI_SWITCH_OVSC_SND6|ATARI_SWITCH_OVSC_SND7)) {
sound_ym.rd_data_reg_sel = 14;
sound_ym.wd_data = sound_ym.rd_data_reg_sel |
((atari_switches & ATARI_SWITCH_OVSC_SND6) ? 0x40:0) |
((atari_switches & ATARI_SWITCH_OVSC_SND7) ? 0x80:0);
}
local_irq_restore(flags);
}
static int ext_encode_fix(struct fb_fix_screeninfo *fix, struct atafb_par *par)
{
strcpy(fix->id, "Unknown Extern");
fix->smem_start = external_addr;
fix->smem_len = PAGE_ALIGN(external_len);
if (external_depth == 1) {
fix->type = FB_TYPE_PACKED_PIXELS;
fix->visual =
(external_pmode == FB_TYPE_INTERLEAVED_PLANES ||
external_pmode == FB_TYPE_PACKED_PIXELS) ?
FB_VISUAL_MONO10 : FB_VISUAL_MONO01;
} else {
int visual = external_vgaiobase ?
FB_VISUAL_PSEUDOCOLOR :
FB_VISUAL_STATIC_PSEUDOCOLOR;
switch (external_pmode) {
case -1:
fix->type = FB_TYPE_PACKED_PIXELS;
fix->visual = FB_VISUAL_TRUECOLOR;
break;
case FB_TYPE_PACKED_PIXELS:
fix->type = FB_TYPE_PACKED_PIXELS;
fix->visual = visual;
break;
case FB_TYPE_PLANES:
fix->type = FB_TYPE_PLANES;
fix->visual = visual;
break;
case FB_TYPE_INTERLEAVED_PLANES:
fix->type = FB_TYPE_INTERLEAVED_PLANES;
fix->type_aux = 2;
fix->visual = visual;
break;
}
}
fix->xpanstep = 0;
fix->ypanstep = 0;
fix->ywrapstep = 0;
fix->line_length = par->next_line;
return 0;
}
static int ext_decode_var(struct fb_var_screeninfo *var, struct atafb_par *par)
{
struct fb_var_screeninfo *myvar = &atafb_predefined[0];
if (var->bits_per_pixel > myvar->bits_per_pixel ||
var->xres > myvar->xres ||
var->xres_virtual > myvar->xres_virtual ||
var->yres > myvar->yres ||
var->xoffset > 0 ||
var->yoffset > 0)
return -EINVAL;
par->next_line = external_xres_virtual * external_depth / 8;
return 0;
}
static int ext_encode_var(struct fb_var_screeninfo *var, struct atafb_par *par)
{
memset(var, 0, sizeof(struct fb_var_screeninfo));
var->red.offset = 0;
var->red.length = (external_pmode == -1) ? external_depth / 3 :
(external_vgaiobase ? external_bitspercol : 0);
var->red.msb_right = 0;
var->grayscale = 0;
var->pixclock = 31041;
var->left_margin = 120;
var->right_margin = 100;
var->upper_margin = 8;
var->lower_margin = 16;
var->hsync_len = 140;
var->vsync_len = 30;
var->height = -1;
var->width = -1;
var->sync = 0;
var->xres = external_xres;
var->yres = external_yres;
var->xres_virtual = external_xres_virtual;
var->bits_per_pixel = external_depth;
var->blue = var->green = var->red;
var->transp.offset = 0;
var->transp.length = 0;
var->transp.msb_right = 0;
var->yres_virtual = var->yres;
var->xoffset = 0;
var->yoffset = 0;
var->nonstd = 0;
var->activate = 0;
var->vmode = FB_VMODE_NONINTERLACED;
return 0;
}
static void ext_get_par(struct atafb_par *par)
{
par->screen_base = external_screen_base;
}
static void ext_set_par(struct atafb_par *par)
{
}
static int ext_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
unsigned char colmask = (1 << external_bitspercol) - 1;
if (!external_vgaiobase)
return 1;
if (regno > 255)
return 1;
switch (external_card_type) {
case IS_VGA:
OUTB(0x3c8, regno);
DACDelay;
OUTB(0x3c9, red & colmask);
DACDelay;
OUTB(0x3c9, green & colmask);
DACDelay;
OUTB(0x3c9, blue & colmask);
DACDelay;
return 0;
case IS_MV300:
OUTB((MV300_reg[regno] << 2) + 1, red);
OUTB((MV300_reg[regno] << 2) + 1, green);
OUTB((MV300_reg[regno] << 2) + 1, blue);
return 0;
default:
return 1;
}
}
static int ext_detect(void)
{
struct fb_var_screeninfo *myvar = &atafb_predefined[0];
struct atafb_par dummy_par;
myvar->xres = external_xres;
myvar->xres_virtual = external_xres_virtual;
myvar->yres = external_yres;
myvar->bits_per_pixel = external_depth;
ext_encode_var(myvar, &dummy_par);
return 1;
}
static void set_screen_base(void *s_base)
{
unsigned long addr;
addr = atari_stram_to_phys(s_base);
shifter.bas_hi = (unsigned char)((addr & 0xff0000) >> 16);
shifter.bas_md = (unsigned char)((addr & 0x00ff00) >> 8);
shifter.bas_lo = (unsigned char)(addr & 0x0000ff);
}
static int pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct atafb_par *par = (struct atafb_par *)info->par;
if (!fbhw->set_screen_base ||
(!ATARIHW_PRESENT(EXTD_SHIFTER) && var->xoffset))
return -EINVAL;
var->xoffset = up(var->xoffset, 16);
par->screen_base = screen_base +
(var->yoffset * info->var.xres_virtual + var->xoffset)
* info->var.bits_per_pixel / 8;
fbhw->set_screen_base(par->screen_base);
return 0;
}
static void ata_get_par(struct atafb_par *par)
{
if (current_par_valid)
*par = current_par;
else
fbhw->get_par(par);
}
static void ata_set_par(struct atafb_par *par)
{
fbhw->set_par(par);
current_par = *par;
current_par_valid = 1;
}
static int do_fb_set_var(struct fb_var_screeninfo *var, int isactive)
{
int err, activate;
struct atafb_par par;
err = fbhw->decode_var(var, &par);
if (err)
return err;
activate = var->activate;
if (((var->activate & FB_ACTIVATE_MASK) == FB_ACTIVATE_NOW) && isactive)
ata_set_par(&par);
fbhw->encode_var(var, &par);
var->activate = activate;
return 0;
}
static int atafb_get_fix(struct fb_fix_screeninfo *fix, struct fb_info *info)
{
struct atafb_par par;
int err;
err = fbhw->decode_var(&info->var, &par);
if (err)
return err;
memset(fix, 0, sizeof(struct fb_fix_screeninfo));
err = fbhw->encode_fix(fix, &par);
return err;
}
static int atafb_get_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct atafb_par par;
ata_get_par(&par);
fbhw->encode_var(var, &par);
return 0;
}
static void atafb_set_disp(struct fb_info *info)
{
atafb_get_var(&info->var, info);
atafb_get_fix(&info->fix, info);
info->screen_base = (external_addr ? external_screen_base :
atari_stram_to_virt(info->fix.smem_start));
}
static int atafb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
red >>= 8;
green >>= 8;
blue >>= 8;
return info->fbops->fb_setcolreg(regno, red, green, blue, transp, info);
}
static int
atafb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
int xoffset = var->xoffset;
int yoffset = var->yoffset;
int err;
if (var->vmode & FB_VMODE_YWRAP) {
if (yoffset < 0 || yoffset >= info->var.yres_virtual || xoffset)
return -EINVAL;
} else {
if (xoffset + info->var.xres > info->var.xres_virtual ||
yoffset + info->var.yres > info->var.yres_virtual)
return -EINVAL;
}
if (fbhw->pan_display) {
err = fbhw->pan_display(var, info);
if (err)
return err;
} else
return -EINVAL;
info->var.xoffset = xoffset;
info->var.yoffset = yoffset;
if (var->vmode & FB_VMODE_YWRAP)
info->var.vmode |= FB_VMODE_YWRAP;
else
info->var.vmode &= ~FB_VMODE_YWRAP;
return 0;
}
static void atafb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct atafb_par *par = (struct atafb_par *)info->par;
int x2, y2;
u32 width, height;
if (!rect->width || !rect->height)
return;
#ifdef ATAFB_FALCON
if (info->var.bits_per_pixel == 16) {
cfb_fillrect(info, rect);
return;
}
#endif
x2 = rect->dx + rect->width;
y2 = rect->dy + rect->height;
x2 = x2 < info->var.xres_virtual ? x2 : info->var.xres_virtual;
y2 = y2 < info->var.yres_virtual ? y2 : info->var.yres_virtual;
width = x2 - rect->dx;
height = y2 - rect->dy;
if (info->var.bits_per_pixel == 1)
atafb_mfb_fillrect(info, par->next_line, rect->color,
rect->dy, rect->dx, height, width);
else if (info->var.bits_per_pixel == 2)
atafb_iplan2p2_fillrect(info, par->next_line, rect->color,
rect->dy, rect->dx, height, width);
else if (info->var.bits_per_pixel == 4)
atafb_iplan2p4_fillrect(info, par->next_line, rect->color,
rect->dy, rect->dx, height, width);
else
atafb_iplan2p8_fillrect(info, par->next_line, rect->color,
rect->dy, rect->dx, height, width);
return;
}
static void atafb_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct atafb_par *par = (struct atafb_par *)info->par;
int x2, y2;
u32 dx, dy, sx, sy, width, height;
int rev_copy = 0;
#ifdef ATAFB_FALCON
if (info->var.bits_per_pixel == 16) {
cfb_copyarea(info, area);
return;
}
#endif
x2 = area->dx + area->width;
y2 = area->dy + area->height;
dx = area->dx > 0 ? area->dx : 0;
dy = area->dy > 0 ? area->dy : 0;
x2 = x2 < info->var.xres_virtual ? x2 : info->var.xres_virtual;
y2 = y2 < info->var.yres_virtual ? y2 : info->var.yres_virtual;
width = x2 - dx;
height = y2 - dy;
if (area->sx + dx < area->dx || area->sy + dy < area->dy)
return;
sx = area->sx + (dx - area->dx);
sy = area->sy + (dy - area->dy);
if (sx + width > info->var.xres_virtual ||
sy + height > info->var.yres_virtual)
return;
if (dy > sy || (dy == sy && dx > sx)) {
dy += height;
sy += height;
rev_copy = 1;
}
if (info->var.bits_per_pixel == 1)
atafb_mfb_copyarea(info, par->next_line, sy, sx, dy, dx, height, width);
else if (info->var.bits_per_pixel == 2)
atafb_iplan2p2_copyarea(info, par->next_line, sy, sx, dy, dx, height, width);
else if (info->var.bits_per_pixel == 4)
atafb_iplan2p4_copyarea(info, par->next_line, sy, sx, dy, dx, height, width);
else
atafb_iplan2p8_copyarea(info, par->next_line, sy, sx, dy, dx, height, width);
return;
}
static void atafb_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct atafb_par *par = (struct atafb_par *)info->par;
int x2, y2;
unsigned long *dst;
int dst_idx;
const char *src;
u32 dx, dy, width, height, pitch;
#ifdef ATAFB_FALCON
if (info->var.bits_per_pixel == 16) {
cfb_imageblit(info, image);
return;
}
#endif
x2 = image->dx + image->width;
y2 = image->dy + image->height;
dx = image->dx;
dy = image->dy;
x2 = x2 < info->var.xres_virtual ? x2 : info->var.xres_virtual;
y2 = y2 < info->var.yres_virtual ? y2 : info->var.yres_virtual;
width = x2 - dx;
height = y2 - dy;
if (image->depth == 1) {
dst = (unsigned long *)
((unsigned long)info->screen_base & ~(BYTES_PER_LONG - 1));
dst_idx = ((unsigned long)info->screen_base & (BYTES_PER_LONG - 1)) * 8;
dst_idx += dy * par->next_line * 8 + dx;
src = image->data;
pitch = (image->width + 7) / 8;
while (height--) {
if (info->var.bits_per_pixel == 1)
atafb_mfb_linefill(info, par->next_line,
dy, dx, width, src,
image->bg_color, image->fg_color);
else if (info->var.bits_per_pixel == 2)
atafb_iplan2p2_linefill(info, par->next_line,
dy, dx, width, src,
image->bg_color, image->fg_color);
else if (info->var.bits_per_pixel == 4)
atafb_iplan2p4_linefill(info, par->next_line,
dy, dx, width, src,
image->bg_color, image->fg_color);
else
atafb_iplan2p8_linefill(info, par->next_line,
dy, dx, width, src,
image->bg_color, image->fg_color);
dy++;
src += pitch;
}
} else {
c2p_iplan2(info->screen_base, image->data, dx, dy, width,
height, par->next_line, image->width,
info->var.bits_per_pixel);
}
}
static int
atafb_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
switch (cmd) {
#ifdef FBCMD_GET_CURRENTPAR
case FBCMD_GET_CURRENTPAR:
if (copy_to_user((void *)arg, (void *)&current_par,
sizeof(struct atafb_par)))
return -EFAULT;
return 0;
#endif
#ifdef FBCMD_SET_CURRENTPAR
case FBCMD_SET_CURRENTPAR:
if (copy_from_user((void *)&current_par, (void *)arg,
sizeof(struct atafb_par)))
return -EFAULT;
ata_set_par(&current_par);
return 0;
#endif
}
return -EINVAL;
}
static int atafb_blank(int blank, struct fb_info *info)
{
unsigned short black[16];
struct fb_cmap cmap;
if (fbhw->blank && !fbhw->blank(blank))
return 1;
if (blank) {
memset(black, 0, 16 * sizeof(unsigned short));
cmap.red = black;
cmap.green = black;
cmap.blue = black;
cmap.transp = NULL;
cmap.start = 0;
cmap.len = 16;
fb_set_cmap(&cmap, info);
}
#if 0
else
do_install_cmap(info);
#endif
return 0;
}
static int atafb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
int err;
struct atafb_par par;
err = fbhw->decode_var(var, &par);
if (err)
return err;
fbhw->encode_var(var, &par);
return 0;
}
static int atafb_set_par(struct fb_info *info)
{
struct atafb_par *par = (struct atafb_par *)info->par;
fbhw->decode_var(&info->var, par);
mutex_lock(&info->mm_lock);
fbhw->encode_fix(&info->fix, par);
mutex_unlock(&info->mm_lock);
ata_set_par(par);
return 0;
}
static void check_default_par(int detected_mode)
{
char default_name[10];
int i;
struct fb_var_screeninfo var;
unsigned long min_mem;
if (default_par) {
var = atafb_predefined[default_par - 1];
var.activate = FB_ACTIVATE_TEST;
if (do_fb_set_var(&var, 1))
default_par = 0;
}
if (!default_par) {
var = atafb_predefined[detected_mode - 1];
var.activate = FB_ACTIVATE_TEST;
if (!do_fb_set_var(&var, 1))
default_par = detected_mode;
}
if (!default_par) {
for (i = 1; i < 10; i++) {
sprintf(default_name,"default%d", i);
default_par = get_video_mode(default_name);
if (!default_par)
panic("can't set default video mode");
var = atafb_predefined[default_par - 1];
var.activate = FB_ACTIVATE_TEST;
if (!do_fb_set_var(&var,1))
break;
}
}
min_mem = var.xres_virtual * var.yres_virtual * var.bits_per_pixel / 8;
if (default_mem_req < min_mem)
default_mem_req = min_mem;
}
static void __init atafb_setup_ext(char *spec)
{
int xres, xres_virtual, yres, depth, planes;
unsigned long addr, len;
char *p;
p = strsep(&spec, ";");
if (!p || !*p)
return;
xres_virtual = xres = simple_strtoul(p, NULL, 10);
if (xres <= 0)
return;
p = strsep(&spec, ";");
if (!p || !*p)
return;
yres = simple_strtoul(p, NULL, 10);
if (yres <= 0)
return;
p = strsep(&spec, ";");
if (!p || !*p)
return;
depth = simple_strtoul(p, NULL, 10);
if (depth != 1 && depth != 2 && depth != 4 && depth != 8 &&
depth != 16 && depth != 24)
return;
p = strsep(&spec, ";");
if (!p || !*p)
return;
if (*p == 'i')
planes = FB_TYPE_INTERLEAVED_PLANES;
else if (*p == 'p')
planes = FB_TYPE_PACKED_PIXELS;
else if (*p == 'n')
planes = FB_TYPE_PLANES;
else if (*p == 't')
planes = -1;
else
return;
p = strsep(&spec, ";");
if (!p || !*p)
return;
addr = simple_strtoul(p, NULL, 0);
p = strsep(&spec, ";");
if (!p || !*p)
len = xres * yres * depth / 8;
else
len = simple_strtoul(p, NULL, 0);
p = strsep(&spec, ";");
if (p && *p)
external_vgaiobase = simple_strtoul(p, NULL, 0);
p = strsep(&spec, ";");
if (p && *p) {
external_bitspercol = simple_strtoul(p, NULL, 0);
if (external_bitspercol > 8)
external_bitspercol = 8;
else if (external_bitspercol < 1)
external_bitspercol = 1;
}
p = strsep(&spec, ";");
if (p && *p) {
if (!strcmp(p, "vga"))
external_card_type = IS_VGA;
if (!strcmp(p, "mv300"))
external_card_type = IS_MV300;
}
p = strsep(&spec, ";");
if (p && *p) {
xres_virtual = simple_strtoul(p, NULL, 10);
if (xres_virtual < xres)
xres_virtual = xres;
if (xres_virtual * yres * depth / 8 > len)
len = xres_virtual * yres * depth / 8;
}
external_xres = xres;
external_xres_virtual = xres_virtual;
external_yres = yres;
external_depth = depth;
external_pmode = planes;
external_addr = addr;
external_len = len;
if (external_card_type == IS_MV300) {
switch (external_depth) {
case 1:
MV300_reg = MV300_reg_1bit;
break;
case 4:
MV300_reg = MV300_reg_4bit;
break;
case 8:
MV300_reg = MV300_reg_8bit;
break;
}
}
}
static void __init atafb_setup_int(char *spec)
{
int xres;
char *p;
if (!(p = strsep(&spec, ";")) || !*p)
return;
xres = simple_strtoul(p, NULL, 10);
if (!(p = strsep(&spec, ";")) || !*p)
return;
sttt_xres = xres;
tt_yres = st_yres = simple_strtoul(p, NULL, 10);
if ((p = strsep(&spec, ";")) && *p)
sttt_xres_virtual = simple_strtoul(p, NULL, 10);
if ((p = strsep(&spec, ";")) && *p)
sttt_yres_virtual = simple_strtoul(p, NULL, 0);
if ((p = strsep(&spec, ";")) && *p)
ovsc_offset = simple_strtoul(p, NULL, 0);
if (ovsc_offset || (sttt_yres_virtual != st_yres))
use_hwscroll = 0;
}
static void __init atafb_setup_mcap(char *spec)
{
char *p;
int vmin, vmax, hmin, hmax;
if (!(p = strsep(&spec, ";")) || !*p)
return;
vmin = simple_strtoul(p, NULL, 10);
if (vmin <= 0)
return;
if (!(p = strsep(&spec, ";")) || !*p)
return;
vmax = simple_strtoul(p, NULL, 10);
if (vmax <= 0 || vmax <= vmin)
return;
if (!(p = strsep(&spec, ";")) || !*p)
return;
hmin = 1000 * simple_strtoul(p, NULL, 10);
if (hmin <= 0)
return;
if (!(p = strsep(&spec, "")) || !*p)
return;
hmax = 1000 * simple_strtoul(p, NULL, 10);
if (hmax <= 0 || hmax <= hmin)
return;
fb_info.monspecs.vfmin = vmin;
fb_info.monspecs.vfmax = vmax;
fb_info.monspecs.hfmin = hmin;
fb_info.monspecs.hfmax = hmax;
}
static void __init atafb_setup_user(char *spec)
{
char *p;
int xres, yres, depth, temp;
p = strsep(&spec, ";");
if (!p || !*p)
return;
xres = simple_strtoul(p, NULL, 10);
p = strsep(&spec, ";");
if (!p || !*p)
return;
yres = simple_strtoul(p, NULL, 10);
p = strsep(&spec, "");
if (!p || !*p)
return;
depth = simple_strtoul(p, NULL, 10);
temp = get_video_mode("user0");
if (temp) {
default_par = temp;
atafb_predefined[default_par - 1].xres = xres;
atafb_predefined[default_par - 1].yres = yres;
atafb_predefined[default_par - 1].bits_per_pixel = depth;
}
}
int __init atafb_setup(char *options)
{
char *this_opt;
int temp;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!*this_opt)
continue;
if ((temp = get_video_mode(this_opt))) {
default_par = temp;
mode_option = this_opt;
} else if (!strcmp(this_opt, "inverse"))
inverse = 1;
else if (!strncmp(this_opt, "hwscroll_", 9)) {
hwscroll = simple_strtoul(this_opt + 9, NULL, 10);
if (hwscroll < 0)
hwscroll = 0;
if (hwscroll > 200)
hwscroll = 200;
}
#ifdef ATAFB_EXT
else if (!strcmp(this_opt, "mv300")) {
external_bitspercol = 8;
external_card_type = IS_MV300;
} else if (!strncmp(this_opt, "external:", 9))
atafb_setup_ext(this_opt + 9);
#endif
else if (!strncmp(this_opt, "internal:", 9))
atafb_setup_int(this_opt + 9);
#ifdef ATAFB_FALCON
else if (!strncmp(this_opt, "eclock:", 7)) {
fext.f = simple_strtoul(this_opt + 7, NULL, 10);
fext.t = 1000000000 / fext.f;
fext.f *= 1000;
} else if (!strncmp(this_opt, "monitorcap:", 11))
atafb_setup_mcap(this_opt + 11);
#endif
else if (!strcmp(this_opt, "keep"))
DontCalcRes = 1;
else if (!strncmp(this_opt, "R", 1))
atafb_setup_user(this_opt + 1);
}
return 0;
}
int __init atafb_init(void)
{
int pad, detected_mode, error;
unsigned int defmode = 0;
unsigned long mem_req;
#ifndef MODULE
char *option = NULL;
if (fb_get_options("atafb", &option))
return -ENODEV;
atafb_setup(option);
#endif
printk("atafb_init: start\n");
if (!MACH_IS_ATARI)
return -ENODEV;
do {
#ifdef ATAFB_EXT
if (external_addr) {
printk("atafb_init: initializing external hw\n");
fbhw = &ext_switch;
atafb_ops.fb_setcolreg = &ext_setcolreg;
defmode = DEFMODE_EXT;
break;
}
#endif
#ifdef ATAFB_TT
if (ATARIHW_PRESENT(TT_SHIFTER)) {
printk("atafb_init: initializing TT hw\n");
fbhw = &tt_switch;
atafb_ops.fb_setcolreg = &tt_setcolreg;
defmode = DEFMODE_TT;
break;
}
#endif
#ifdef ATAFB_FALCON
if (ATARIHW_PRESENT(VIDEL_SHIFTER)) {
printk("atafb_init: initializing Falcon hw\n");
fbhw = &falcon_switch;
atafb_ops.fb_setcolreg = &falcon_setcolreg;
error = request_irq(IRQ_AUTO_4, falcon_vbl_switcher, 0,
"framebuffer:modeswitch",
falcon_vbl_switcher);
if (error)
return error;
defmode = DEFMODE_F30;
break;
}
#endif
#ifdef ATAFB_STE
if (ATARIHW_PRESENT(STND_SHIFTER) ||
ATARIHW_PRESENT(EXTD_SHIFTER)) {
printk("atafb_init: initializing ST/E hw\n");
fbhw = &st_switch;
atafb_ops.fb_setcolreg = &stste_setcolreg;
defmode = DEFMODE_STE;
break;
}
fbhw = &st_switch;
atafb_ops.fb_setcolreg = &stste_setcolreg;
printk("Cannot determine video hardware; defaulting to ST(e)\n");
#else
panic("Cannot initialize video hardware");
#endif
} while (0);
if (fb_info.monspecs.hfmin == 0) {
fb_info.monspecs.hfmin = 31000;
fb_info.monspecs.hfmax = 32000;
fb_info.monspecs.vfmin = 58;
fb_info.monspecs.vfmax = 62;
}
detected_mode = fbhw->detect();
check_default_par(detected_mode);
#ifdef ATAFB_EXT
if (!external_addr) {
#endif
mem_req = default_mem_req + ovsc_offset + ovsc_addlen;
mem_req = PAGE_ALIGN(mem_req) + PAGE_SIZE;
screen_base = atari_stram_alloc(mem_req, "atafb");
if (!screen_base)
panic("Cannot allocate screen memory");
memset(screen_base, 0, mem_req);
pad = -(unsigned long)screen_base & (PAGE_SIZE - 1);
screen_base += pad;
phys_screen_base = atari_stram_to_phys(screen_base + ovsc_offset);
screen_len = (mem_req - pad - ovsc_offset) & PAGE_MASK;
st_ovsc_switch();
if (CPU_IS_040_OR_060) {
cache_push(atari_stram_to_phys(screen_base), screen_len);
kernel_set_cachemode(screen_base, screen_len,
IOMAP_WRITETHROUGH);
}
printk("atafb: screen_base %p phys_screen_base %lx screen_len %d\n",
screen_base, phys_screen_base, screen_len);
#ifdef ATAFB_EXT
} else {
external_screen_base = ioremap_writethrough(external_addr,
external_len);
if (external_vgaiobase)
external_vgaiobase =
(unsigned long)ioremap(external_vgaiobase, 0x10000);
screen_base = external_screen_base;
phys_screen_base = external_addr;
screen_len = external_len & PAGE_MASK;
memset (screen_base, 0, external_len);
}
#endif
fb_info.fbops = &atafb_ops;
do_fb_set_var(&atafb_predefined[default_par - 1], 1);
ata_get_par(&current_par);
fb_info.par = &current_par;
atafb_get_var(&fb_info.var, &fb_info);
#ifdef ATAFB_FALCON
fb_info.pseudo_palette = current_par.hw.falcon.pseudo_palette;
#endif
fb_info.flags = FBINFO_FLAG_DEFAULT;
if (!fb_find_mode(&fb_info.var, &fb_info, mode_option, atafb_modedb,
NUM_TOTAL_MODES, &atafb_modedb[defmode],
fb_info.var.bits_per_pixel)) {
return -EINVAL;
}
fb_videomode_to_modelist(atafb_modedb, NUM_TOTAL_MODES,
&fb_info.modelist);
atafb_set_disp(&fb_info);
fb_alloc_cmap(&(fb_info.cmap), 1 << fb_info.var.bits_per_pixel, 0);
printk("Determined %dx%d, depth %d\n",
fb_info.var.xres, fb_info.var.yres, fb_info.var.bits_per_pixel);
if ((fb_info.var.xres != fb_info.var.xres_virtual) ||
(fb_info.var.yres != fb_info.var.yres_virtual))
printk(" virtual %dx%d\n", fb_info.var.xres_virtual,
fb_info.var.yres_virtual);
if (register_framebuffer(&fb_info) < 0) {
#ifdef ATAFB_EXT
if (external_addr) {
iounmap(external_screen_base);
external_addr = 0;
}
if (external_vgaiobase) {
iounmap((void*)external_vgaiobase);
external_vgaiobase = 0;
}
#endif
return -EINVAL;
}
fb_info(&fb_info, "frame buffer device, using %dK of video memory\n",
screen_len >> 10);
return 0;
}
int cleanup_module(void)
{
unregister_framebuffer(&fb_info);
return atafb_deinit();
}
