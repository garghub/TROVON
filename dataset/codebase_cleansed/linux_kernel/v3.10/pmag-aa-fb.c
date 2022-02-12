static void aafb_set_cursor(struct aafb_info *info, int on)
{
struct aafb_cursor *c = &info->cursor;
if (on) {
bt431_position_cursor(info->bt431, c->x, c->y);
bt431_enable_cursor(info->bt431);
} else
bt431_erase_cursor(info->bt431);
}
static void aafbcon_cursor(struct display *disp, int mode, int x, int y)
{
struct aafb_info *info = (struct aafb_info *)disp->fb_info;
struct aafb_cursor *c = &info->cursor;
x *= fontwidth(disp);
y *= fontheight(disp);
if (c->x == x && c->y == y && (mode == CM_ERASE) == !c->enable)
return;
c->enable = 0;
if (c->on)
aafb_set_cursor(info, 0);
c->x = x - disp->var.xoffset;
c->y = y - disp->var.yoffset;
switch (mode) {
case CM_ERASE:
c->on = 0;
break;
case CM_DRAW:
case CM_MOVE:
if (c->on)
aafb_set_cursor(info, c->on);
else
c->vbl_cnt = CURSOR_DRAW_DELAY;
c->enable = 1;
break;
}
}
static int aafbcon_set_font(struct display *disp, int width, int height)
{
struct aafb_info *info = (struct aafb_info *)disp->fb_info;
struct aafb_cursor *c = &info->cursor;
u8 fgc = ~attr_bgcol_ec(disp, disp->conp, &info->info);
if (width > 64 || height > 64 || width < 0 || height < 0)
return -EINVAL;
c->height = height;
c->width = width;
bt431_set_font(info->bt431, fgc, width, height);
return 1;
}
static void aafb_cursor_timer_handler(unsigned long data)
{
struct aafb_info *info = (struct aafb_info *)data;
struct aafb_cursor *c = &info->cursor;
if (!c->enable)
goto out;
if (c->vbl_cnt && --c->vbl_cnt == 0) {
c->on ^= 1;
aafb_set_cursor(info, c->on);
c->vbl_cnt = c->blink_rate;
}
out:
c->timer.expires = jiffies + CURSOR_TIMER_FREQ;
add_timer(&c->timer);
}
static void __init aafb_cursor_init(struct aafb_info *info)
{
struct aafb_cursor *c = &info->cursor;
c->enable = 1;
c->on = 1;
c->x = c->y = 0;
c->width = c->height = 0;
c->vbl_cnt = CURSOR_DRAW_DELAY;
c->blink_rate = CURSOR_BLINK_RATE;
init_timer(&c->timer);
c->timer.data = (unsigned long)info;
c->timer.function = aafb_cursor_timer_handler;
mod_timer(&c->timer, jiffies + CURSOR_TIMER_FREQ);
}
static void __exit aafb_cursor_exit(struct aafb_info *info)
{
struct aafb_cursor *c = &info->cursor;
del_timer_sync(&c->timer);
}
static void aafb_get_par(struct aafb_par *par)
{
*par = current_par;
}
static int aafb_get_fix(struct fb_fix_screeninfo *fix, int con,
struct fb_info *info)
{
struct aafb_info *ip = (struct aafb_info *)info;
memset(fix, 0, sizeof(struct fb_fix_screeninfo));
strcpy(fix->id, "PMAG-AA");
fix->smem_start = ip->fb_start;
fix->smem_len = ip->fb_size;
fix->type = FB_TYPE_PACKED_PIXELS;
fix->ypanstep = 1;
fix->ywrapstep = 1;
fix->visual = FB_VISUAL_MONO10;
fix->line_length = 1280;
fix->accel = FB_ACCEL_NONE;
return 0;
}
static void aafb_set_disp(struct display *disp, int con,
struct aafb_info *info)
{
struct fb_fix_screeninfo fix;
disp->fb_info = &info->info;
aafb_set_var(&disp->var, con, &info->info);
if (disp->conp && disp->conp->vc_sw && disp->conp->vc_sw->con_cursor)
disp->conp->vc_sw->con_cursor(disp->conp, CM_ERASE);
disp->dispsw = &aafb_switch8;
disp->dispsw_data = 0;
aafb_get_fix(&fix, con, &info->info);
disp->screen_base = (u8 *) fix.smem_start;
disp->visual = fix.visual;
disp->type = fix.type;
disp->type_aux = fix.type_aux;
disp->ypanstep = fix.ypanstep;
disp->ywrapstep = fix.ywrapstep;
disp->line_length = fix.line_length;
disp->next_line = 2048;
disp->can_soft_blank = 1;
disp->inverse = 0;
disp->scrollmode = SCROLL_YREDRAW;
aafbcon_set_font(disp, fontwidth(disp), fontheight(disp));
}
static int aafb_get_cmap(struct fb_cmap *cmap, int kspc, int con,
struct fb_info *info)
{
static u16 color[2] = {0x0000, 0x000f};
static struct fb_cmap aafb_cmap = {0, 2, color, color, color, NULL};
fb_copy_cmap(&aafb_cmap, cmap, kspc ? 0 : 2);
return 0;
}
static int aafb_set_cmap(struct fb_cmap *cmap, int kspc, int con,
struct fb_info *info)
{
u16 color[2] = {0x0000, 0x000f};
if (cmap->start == 0
&& cmap->len == 2
&& memcmp(cmap->red, color, sizeof(color)) == 0
&& memcmp(cmap->green, color, sizeof(color)) == 0
&& memcmp(cmap->blue, color, sizeof(color)) == 0
&& cmap->transp == NULL)
return 0;
else
return -EINVAL;
}
static int aafb_ioctl(struct fb_info *info, u32 cmd, unsigned long arg)
{
return -ENOIOCTLCMD;
}
static int aafb_switch(int con, struct fb_info *info)
{
struct aafb_info *ip = (struct aafb_info *)info;
struct display *old = (currcon < 0) ? &ip->disp : (fb_display + currcon);
struct display *new = (con < 0) ? &ip->disp : (fb_display + con);
if (old->conp && old->conp->vc_sw && old->conp->vc_sw->con_cursor)
old->conp->vc_sw->con_cursor(old->conp, CM_ERASE);
currcon = con;
aafb_set_disp(new, con, ip);
return 0;
}
static void aafb_encode_var(struct fb_var_screeninfo *var,
struct aafb_par *par)
{
var->xres = 1280;
var->yres = 1024;
var->xres_virtual = 2048;
var->yres_virtual = 1024;
var->xoffset = 0;
var->yoffset = 0;
var->bits_per_pixel = 8;
var->grayscale = 1;
var->red.offset = 0;
var->red.length = 0;
var->red.msb_right = 0;
var->green.offset = 0;
var->green.length = 1;
var->green.msb_right = 0;
var->blue.offset = 0;
var->blue.length = 0;
var->blue.msb_right = 0;
var->transp.offset = 0;
var->transp.length = 0;
var->transp.msb_right = 0;
var->nonstd = 0;
var->activate &= ~FB_ACTIVATE_MASK & FB_ACTIVATE_NOW;
var->accel_flags = 0;
var->sync = FB_SYNC_ON_GREEN;
var->vmode &= ~FB_VMODE_MASK & FB_VMODE_NONINTERLACED;
}
static int aafb_get_var(struct fb_var_screeninfo *var, int con,
struct fb_info *info)
{
if (con < 0) {
struct aafb_par par;
memset(var, 0, sizeof(struct fb_var_screeninfo));
aafb_get_par(&par);
aafb_encode_var(var, &par);
} else
*var = info->var;
return 0;
}
static int aafb_set_var(struct fb_var_screeninfo *var, int con,
struct fb_info *info)
{
struct aafb_par par;
aafb_get_par(&par);
aafb_encode_var(var, &par);
info->var = *var;
return 0;
}
static int aafb_update_var(int con, struct fb_info *info)
{
struct aafb_info *ip = (struct aafb_info *)info;
struct display *disp = (con < 0) ? &ip->disp : (fb_display + con);
if (con == currcon)
aafbcon_cursor(disp, CM_ERASE, ip->cursor.x, ip->cursor.y);
return 0;
}
static void aafb_blank(int blank, struct fb_info *info)
{
struct aafb_info *ip = (struct aafb_info *)info;
u8 val = blank ? 0x00 : 0x0f;
bt455_write_cmap_entry(ip->bt455, 1, val, val, val);
aafbcon_cursor(&ip->disp, CM_ERASE, ip->cursor.x, ip->cursor.y);
}
static int __init init_one(int slot)
{
unsigned long base_addr = CKSEG1ADDR(get_tc_base_addr(slot));
struct aafb_info *ip = &my_fb_info[slot];
memset(ip, 0, sizeof(struct aafb_info));
ip->bt455 = (struct bt455_regs *) (base_addr + PMAG_AA_BT455_OFFSET);
ip->bt431 = (struct bt431_regs *) (base_addr + PMAG_AA_BT431_OFFSET);
ip->fb_start = base_addr + PMAG_AA_ONBOARD_FBMEM_OFFSET;
ip->fb_size = 2048 * 1024;
ip->fb_line_length = 2048;
strcpy(ip->info.modename, "PMAG-AA");
ip->info.node = -1;
ip->info.flags = FBINFO_FLAG_DEFAULT;
ip->info.fbops = &aafb_ops;
ip->info.disp = &ip->disp;
ip->info.changevar = NULL;
ip->info.switch_con = &aafb_switch;
ip->info.updatevar = &aafb_update_var;
ip->info.blank = &aafb_blank;
aafb_set_disp(&ip->disp, currcon, ip);
bt455_erase_cursor(ip->bt455);
bt455_write_cmap_entry(ip->bt455, 0, 0x00, 0x00, 0x00);
bt455_write_cmap_entry(ip->bt455, 1, 0x0f, 0x0f, 0x0f);
bt431_init_cursor(ip->bt431);
aafb_cursor_init(ip);
memset ((void *)ip->fb_start, 0, ip->fb_size);
if (register_framebuffer(&ip->info) < 0)
return -EINVAL;
printk(KERN_INFO "fb%d: %s frame buffer in TC slot %d\n",
GET_FB_IDX(ip->info.node), ip->info.modename, slot);
return 0;
}
static int __exit exit_one(int slot)
{
struct aafb_info *ip = &my_fb_info[slot];
if (unregister_framebuffer(&ip->info) < 0)
return -EINVAL;
return 0;
}
int __init pmagaafb_init(void)
{
int sid;
int found = 0;
while ((sid = search_tc_card("PMAG-AA")) >= 0) {
found = 1;
claim_tc_card(sid);
init_one(sid);
}
return found ? 0 : -ENXIO;
}
static void __exit pmagaafb_exit(void)
{
int sid;
while ((sid = search_tc_card("PMAG-AA")) >= 0) {
exit_one(sid);
release_tc_card(sid);
}
}
