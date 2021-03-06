bool vgacon_text_force(void)
{
return vgacon_text_mode_force ? true : false;
}
static int __init text_mode(char *str)
{
vgacon_text_mode_force = 1;
return 1;
}
static int __init no_scroll(char *str)
{
vga_hardscroll_user_enable = vga_hardscroll_enabled = 0;
return 1;
}
static inline void write_vga(unsigned char reg, unsigned int val)
{
unsigned int v1, v2;
unsigned long flags;
raw_spin_lock_irqsave(&vga_lock, flags);
#ifndef SLOW_VGA
v1 = reg + (val & 0xff00);
v2 = reg + 1 + ((val << 8) & 0xff00);
outw(v1, vga_video_port_reg);
outw(v2, vga_video_port_reg);
#else
outb_p(reg, vga_video_port_reg);
outb_p(val >> 8, vga_video_port_val);
outb_p(reg + 1, vga_video_port_reg);
outb_p(val & 0xff, vga_video_port_val);
#endif
raw_spin_unlock_irqrestore(&vga_lock, flags);
}
static inline void vga_set_mem_top(struct vc_data *c)
{
write_vga(12, (c->vc_visible_origin - vga_vram_base) / 2);
}
static void vgacon_scrollback_init(int pitch)
{
int rows = CONFIG_VGACON_SOFT_SCROLLBACK_SIZE * 1024/pitch;
if (vgacon_scrollback) {
vgacon_scrollback_cnt = 0;
vgacon_scrollback_tail = 0;
vgacon_scrollback_cur = 0;
vgacon_scrollback_rows = rows - 1;
vgacon_scrollback_size = rows * pitch;
}
}
static void vgacon_scrollback_startup(void)
{
vgacon_scrollback = kcalloc(CONFIG_VGACON_SOFT_SCROLLBACK_SIZE, 1024, GFP_NOWAIT);
vgacon_scrollback_init(vga_video_num_columns * 2);
}
static void vgacon_scrollback_update(struct vc_data *c, int t, int count)
{
void *p;
if (!vgacon_scrollback_size || c->vc_num != fg_console)
return;
p = (void *) (c->vc_origin + t * c->vc_size_row);
while (count--) {
scr_memcpyw(vgacon_scrollback + vgacon_scrollback_tail,
p, c->vc_size_row);
vgacon_scrollback_cnt++;
p += c->vc_size_row;
vgacon_scrollback_tail += c->vc_size_row;
if (vgacon_scrollback_tail >= vgacon_scrollback_size)
vgacon_scrollback_tail = 0;
if (vgacon_scrollback_cnt > vgacon_scrollback_rows)
vgacon_scrollback_cnt = vgacon_scrollback_rows;
vgacon_scrollback_cur = vgacon_scrollback_cnt;
}
}
static void vgacon_restore_screen(struct vc_data *c)
{
vgacon_scrollback_save = 0;
if (!vga_is_gfx && !vgacon_scrollback_restore) {
scr_memcpyw((u16 *) c->vc_origin, (u16 *) c->vc_screenbuf,
c->vc_screenbuf_size > vga_vram_size ?
vga_vram_size : c->vc_screenbuf_size);
vgacon_scrollback_restore = 1;
vgacon_scrollback_cur = vgacon_scrollback_cnt;
}
}
static int vgacon_scrolldelta(struct vc_data *c, int lines)
{
int start, end, count, soff;
if (!lines) {
c->vc_visible_origin = c->vc_origin;
vga_set_mem_top(c);
return 1;
}
if (!vgacon_scrollback)
return 1;
if (!vgacon_scrollback_save) {
vgacon_cursor(c, CM_ERASE);
vgacon_save_screen(c);
vgacon_scrollback_save = 1;
}
vgacon_scrollback_restore = 0;
start = vgacon_scrollback_cur + lines;
end = start + abs(lines);
if (start < 0)
start = 0;
if (start > vgacon_scrollback_cnt)
start = vgacon_scrollback_cnt;
if (end < 0)
end = 0;
if (end > vgacon_scrollback_cnt)
end = vgacon_scrollback_cnt;
vgacon_scrollback_cur = start;
count = end - start;
soff = vgacon_scrollback_tail - ((vgacon_scrollback_cnt - end) *
c->vc_size_row);
soff -= count * c->vc_size_row;
if (soff < 0)
soff += vgacon_scrollback_size;
count = vgacon_scrollback_cnt - start;
if (count > c->vc_rows)
count = c->vc_rows;
if (count) {
int copysize;
int diff = c->vc_rows - count;
void *d = (void *) c->vc_origin;
void *s = (void *) c->vc_screenbuf;
count *= c->vc_size_row;
copysize = min(count, vgacon_scrollback_size - soff);
scr_memcpyw(d, vgacon_scrollback + soff, copysize);
d += copysize;
count -= copysize;
if (count) {
scr_memcpyw(d, vgacon_scrollback, count);
d += count;
}
if (diff)
scr_memcpyw(d, s, diff * c->vc_size_row);
} else
vgacon_cursor(c, CM_MOVE);
return 1;
}
static void vgacon_restore_screen(struct vc_data *c)
{
if (c->vc_origin != c->vc_visible_origin)
vgacon_scrolldelta(c, 0);
}
static int vgacon_scrolldelta(struct vc_data *c, int lines)
{
if (!lines)
c->vc_visible_origin = c->vc_origin;
else {
int margin = c->vc_size_row * 4;
int ul, we, p, st;
if (vga_rolled_over >
(c->vc_scr_end - vga_vram_base) + margin) {
ul = c->vc_scr_end - vga_vram_base;
we = vga_rolled_over + c->vc_size_row;
} else {
ul = 0;
we = vga_vram_size;
}
p = (c->vc_visible_origin - vga_vram_base - ul + we) % we +
lines * c->vc_size_row;
st = (c->vc_origin - vga_vram_base - ul + we) % we;
if (st < 2 * margin)
margin = 0;
if (p < margin)
p = 0;
if (p > st - margin)
p = st;
c->vc_visible_origin = vga_vram_base + (p + ul) % we;
}
vga_set_mem_top(c);
return 1;
}
static const char *vgacon_startup(void)
{
const char *display_desc = NULL;
u16 saved1, saved2;
volatile u16 *p;
if (screen_info.orig_video_isVGA == VIDEO_TYPE_VLFB ||
screen_info.orig_video_isVGA == VIDEO_TYPE_EFI) {
no_vga:
#ifdef CONFIG_DUMMY_CONSOLE
conswitchp = &dummy_con;
return conswitchp->con_startup();
#else
return NULL;
#endif
}
if ((screen_info.orig_video_mode == 0) &&
(screen_info.orig_video_lines == 0) &&
(screen_info.orig_video_cols == 0))
goto no_vga;
if ((screen_info.orig_video_mode == 0x0D) ||
(screen_info.orig_video_mode == 0x0E) ||
(screen_info.orig_video_mode == 0x10) ||
(screen_info.orig_video_mode == 0x12) ||
(screen_info.orig_video_mode == 0x6A))
goto no_vga;
vga_video_num_lines = screen_info.orig_video_lines;
vga_video_num_columns = screen_info.orig_video_cols;
state.vgabase = NULL;
if (screen_info.orig_video_mode == 7) {
vga_vram_base = 0xb0000;
vga_video_port_reg = VGA_CRT_IM;
vga_video_port_val = VGA_CRT_DM;
if ((screen_info.orig_video_ega_bx & 0xff) != 0x10) {
static struct resource ega_console_resource =
{ .name = "ega", .start = 0x3B0, .end = 0x3BF };
vga_video_type = VIDEO_TYPE_EGAM;
vga_vram_size = 0x8000;
display_desc = "EGA+";
request_resource(&ioport_resource,
&ega_console_resource);
} else {
static struct resource mda1_console_resource =
{ .name = "mda", .start = 0x3B0, .end = 0x3BB };
static struct resource mda2_console_resource =
{ .name = "mda", .start = 0x3BF, .end = 0x3BF };
vga_video_type = VIDEO_TYPE_MDA;
vga_vram_size = 0x2000;
display_desc = "*MDA";
request_resource(&ioport_resource,
&mda1_console_resource);
request_resource(&ioport_resource,
&mda2_console_resource);
vga_video_font_height = 14;
}
} else {
vga_can_do_color = 1;
vga_vram_base = 0xb8000;
vga_video_port_reg = VGA_CRT_IC;
vga_video_port_val = VGA_CRT_DC;
if ((screen_info.orig_video_ega_bx & 0xff) != 0x10) {
int i;
vga_vram_size = 0x8000;
if (!screen_info.orig_video_isVGA) {
static struct resource ega_console_resource
= { .name = "ega", .start = 0x3C0, .end = 0x3DF };
vga_video_type = VIDEO_TYPE_EGAC;
display_desc = "EGA";
request_resource(&ioport_resource,
&ega_console_resource);
} else {
static struct resource vga_console_resource
= { .name = "vga+", .start = 0x3C0, .end = 0x3DF };
vga_video_type = VIDEO_TYPE_VGAC;
display_desc = "VGA+";
request_resource(&ioport_resource,
&vga_console_resource);
#ifdef VGA_CAN_DO_64KB
vga_vram_base = 0xa0000;
vga_vram_size = 0x10000;
outb_p(6, VGA_GFX_I);
outb_p(6, VGA_GFX_D);
#endif
for (i = 0; i < 16; i++) {
inb_p(VGA_IS1_RC);
outb_p(i, VGA_ATT_W);
outb_p(i, VGA_ATT_W);
}
outb_p(0x20, VGA_ATT_W);
for (i = 0; i < 16; i++) {
outb_p(color_table[i], VGA_PEL_IW);
outb_p(default_red[i], VGA_PEL_D);
outb_p(default_grn[i], VGA_PEL_D);
outb_p(default_blu[i], VGA_PEL_D);
}
}
} else {
static struct resource cga_console_resource =
{ .name = "cga", .start = 0x3D4, .end = 0x3D5 };
vga_video_type = VIDEO_TYPE_CGA;
vga_vram_size = 0x2000;
display_desc = "*CGA";
request_resource(&ioport_resource,
&cga_console_resource);
vga_video_font_height = 8;
}
}
vga_vram_base = VGA_MAP_MEM(vga_vram_base, vga_vram_size);
vga_vram_end = vga_vram_base + vga_vram_size;
p = (volatile u16 *) vga_vram_base;
saved1 = scr_readw(p);
saved2 = scr_readw(p + 1);
scr_writew(0xAA55, p);
scr_writew(0x55AA, p + 1);
if (scr_readw(p) != 0xAA55 || scr_readw(p + 1) != 0x55AA) {
scr_writew(saved1, p);
scr_writew(saved2, p + 1);
goto no_vga;
}
scr_writew(0x55AA, p);
scr_writew(0xAA55, p + 1);
if (scr_readw(p) != 0x55AA || scr_readw(p + 1) != 0xAA55) {
scr_writew(saved1, p);
scr_writew(saved2, p + 1);
goto no_vga;
}
scr_writew(saved1, p);
scr_writew(saved2, p + 1);
if (vga_video_type == VIDEO_TYPE_EGAC
|| vga_video_type == VIDEO_TYPE_VGAC
|| vga_video_type == VIDEO_TYPE_EGAM) {
vga_hardscroll_enabled = vga_hardscroll_user_enable;
vga_default_font_height = screen_info.orig_video_points;
vga_video_font_height = screen_info.orig_video_points;
vga_scan_lines =
vga_video_font_height * vga_video_num_lines;
}
vgacon_xres = screen_info.orig_video_cols * VGA_FONTWIDTH;
vgacon_yres = vga_scan_lines;
if (!vga_init_done) {
vgacon_scrollback_startup();
vga_init_done = 1;
}
return display_desc;
}
static void vgacon_init(struct vc_data *c, int init)
{
unsigned long p;
c->vc_can_do_color = vga_can_do_color;
if (init) {
c->vc_cols = vga_video_num_columns;
c->vc_rows = vga_video_num_lines;
} else
vc_resize(c, vga_video_num_columns, vga_video_num_lines);
c->vc_scan_lines = vga_scan_lines;
c->vc_font.height = vga_video_font_height;
c->vc_complement_mask = 0x7700;
if (vga_512_chars)
c->vc_hi_font_mask = 0x0800;
p = *c->vc_uni_pagedir_loc;
if (c->vc_uni_pagedir_loc == &c->vc_uni_pagedir ||
!--c->vc_uni_pagedir_loc[1])
con_free_unimap(c);
c->vc_uni_pagedir_loc = vgacon_uni_pagedir;
vgacon_uni_pagedir[1]++;
if (!vgacon_uni_pagedir[0] && p)
con_set_default_unimap(c);
if (global_cursor_default == -1)
global_cursor_default =
!(screen_info.flags & VIDEO_FLAGS_NOCURSOR);
}
static void vgacon_deinit(struct vc_data *c)
{
if (CON_IS_VISIBLE(c)) {
c->vc_visible_origin = vga_vram_base;
vga_set_mem_top(c);
}
if (!--vgacon_uni_pagedir[1])
con_free_unimap(c);
c->vc_uni_pagedir_loc = &c->vc_uni_pagedir;
con_set_default_unimap(c);
}
static u8 vgacon_build_attr(struct vc_data *c, u8 color, u8 intensity,
u8 blink, u8 underline, u8 reverse, u8 italic)
{
u8 attr = color;
if (vga_can_do_color) {
if (italic)
attr = (attr & 0xF0) | c->vc_itcolor;
else if (underline)
attr = (attr & 0xf0) | c->vc_ulcolor;
else if (intensity == 0)
attr = (attr & 0xf0) | c->vc_halfcolor;
}
if (reverse)
attr =
((attr) & 0x88) | ((((attr) >> 4) | ((attr) << 4)) &
0x77);
if (blink)
attr ^= 0x80;
if (intensity == 2)
attr ^= 0x08;
if (!vga_can_do_color) {
if (italic)
attr = (attr & 0xF8) | 0x02;
else if (underline)
attr = (attr & 0xf8) | 0x01;
else if (intensity == 0)
attr = (attr & 0xf0) | 0x08;
}
return attr;
}
static void vgacon_invert_region(struct vc_data *c, u16 * p, int count)
{
int col = vga_can_do_color;
while (count--) {
u16 a = scr_readw(p);
if (col)
a = ((a) & 0x88ff) | (((a) & 0x7000) >> 4) |
(((a) & 0x0700) << 4);
else
a ^= ((a & 0x0700) == 0x0100) ? 0x7000 : 0x7700;
scr_writew(a, p++);
}
}
static void vgacon_set_cursor_size(int xpos, int from, int to)
{
unsigned long flags;
int curs, cure;
#ifdef TRIDENT_GLITCH
if (xpos < 16)
from--, to--;
#endif
if ((from == cursor_size_lastfrom) && (to == cursor_size_lastto))
return;
cursor_size_lastfrom = from;
cursor_size_lastto = to;
raw_spin_lock_irqsave(&vga_lock, flags);
if (vga_video_type >= VIDEO_TYPE_VGAC) {
outb_p(VGA_CRTC_CURSOR_START, vga_video_port_reg);
curs = inb_p(vga_video_port_val);
outb_p(VGA_CRTC_CURSOR_END, vga_video_port_reg);
cure = inb_p(vga_video_port_val);
} else {
curs = 0;
cure = 0;
}
curs = (curs & 0xc0) | from;
cure = (cure & 0xe0) | to;
outb_p(VGA_CRTC_CURSOR_START, vga_video_port_reg);
outb_p(curs, vga_video_port_val);
outb_p(VGA_CRTC_CURSOR_END, vga_video_port_reg);
outb_p(cure, vga_video_port_val);
raw_spin_unlock_irqrestore(&vga_lock, flags);
}
static void vgacon_cursor(struct vc_data *c, int mode)
{
if (c->vc_mode != KD_TEXT)
return;
vgacon_restore_screen(c);
switch (mode) {
case CM_ERASE:
write_vga(14, (c->vc_pos - vga_vram_base) / 2);
if (vga_video_type >= VIDEO_TYPE_VGAC)
vgacon_set_cursor_size(c->vc_x, 31, 30);
else
vgacon_set_cursor_size(c->vc_x, 31, 31);
break;
case CM_MOVE:
case CM_DRAW:
write_vga(14, (c->vc_pos - vga_vram_base) / 2);
switch (c->vc_cursor_type & 0x0f) {
case CUR_UNDERLINE:
vgacon_set_cursor_size(c->vc_x,
c->vc_font.height -
(c->vc_font.height <
10 ? 2 : 3),
c->vc_font.height -
(c->vc_font.height <
10 ? 1 : 2));
break;
case CUR_TWO_THIRDS:
vgacon_set_cursor_size(c->vc_x,
c->vc_font.height / 3,
c->vc_font.height -
(c->vc_font.height <
10 ? 1 : 2));
break;
case CUR_LOWER_THIRD:
vgacon_set_cursor_size(c->vc_x,
(c->vc_font.height * 2) / 3,
c->vc_font.height -
(c->vc_font.height <
10 ? 1 : 2));
break;
case CUR_LOWER_HALF:
vgacon_set_cursor_size(c->vc_x,
c->vc_font.height / 2,
c->vc_font.height -
(c->vc_font.height <
10 ? 1 : 2));
break;
case CUR_NONE:
if (vga_video_type >= VIDEO_TYPE_VGAC)
vgacon_set_cursor_size(c->vc_x, 31, 30);
else
vgacon_set_cursor_size(c->vc_x, 31, 31);
break;
default:
vgacon_set_cursor_size(c->vc_x, 1,
c->vc_font.height);
break;
}
break;
}
}
static int vgacon_doresize(struct vc_data *c,
unsigned int width, unsigned int height)
{
unsigned long flags;
unsigned int scanlines = height * c->vc_font.height;
u8 scanlines_lo = 0, r7 = 0, vsync_end = 0, mode, max_scan;
raw_spin_lock_irqsave(&vga_lock, flags);
vgacon_xres = width * VGA_FONTWIDTH;
vgacon_yres = height * c->vc_font.height;
if (vga_video_type >= VIDEO_TYPE_VGAC) {
outb_p(VGA_CRTC_MAX_SCAN, vga_video_port_reg);
max_scan = inb_p(vga_video_port_val);
if (max_scan & 0x80)
scanlines <<= 1;
outb_p(VGA_CRTC_MODE, vga_video_port_reg);
mode = inb_p(vga_video_port_val);
if (mode & 0x04)
scanlines >>= 1;
scanlines -= 1;
scanlines_lo = scanlines & 0xff;
outb_p(VGA_CRTC_OVERFLOW, vga_video_port_reg);
r7 = inb_p(vga_video_port_val) & ~0x42;
if (scanlines & 0x100)
r7 |= 0x02;
if (scanlines & 0x200)
r7 |= 0x40;
outb_p(VGA_CRTC_V_SYNC_END, vga_video_port_reg);
vsync_end = inb_p(vga_video_port_val);
outb_p(VGA_CRTC_V_SYNC_END, vga_video_port_reg);
outb_p(vsync_end & ~0x80, vga_video_port_val);
}
outb_p(VGA_CRTC_H_DISP, vga_video_port_reg);
outb_p(width - 1, vga_video_port_val);
outb_p(VGA_CRTC_OFFSET, vga_video_port_reg);
outb_p(width >> 1, vga_video_port_val);
if (vga_video_type >= VIDEO_TYPE_VGAC) {
outb_p(VGA_CRTC_V_DISP_END, vga_video_port_reg);
outb_p(scanlines_lo, vga_video_port_val);
outb_p(VGA_CRTC_OVERFLOW, vga_video_port_reg);
outb_p(r7,vga_video_port_val);
outb_p(VGA_CRTC_V_SYNC_END, vga_video_port_reg);
outb_p(vsync_end, vga_video_port_val);
}
raw_spin_unlock_irqrestore(&vga_lock, flags);
return 0;
}
static int vgacon_switch(struct vc_data *c)
{
int x = c->vc_cols * VGA_FONTWIDTH;
int y = c->vc_rows * c->vc_font.height;
int rows = screen_info.orig_video_lines * vga_default_font_height/
c->vc_font.height;
vga_video_num_columns = c->vc_cols;
vga_video_num_lines = c->vc_rows;
if (!vga_is_gfx) {
scr_memcpyw((u16 *) c->vc_origin, (u16 *) c->vc_screenbuf,
c->vc_screenbuf_size > vga_vram_size ?
vga_vram_size : c->vc_screenbuf_size);
if ((vgacon_xres != x || vgacon_yres != y) &&
(!(vga_video_num_columns % 2) &&
vga_video_num_columns <= screen_info.orig_video_cols &&
vga_video_num_lines <= rows))
vgacon_doresize(c, c->vc_cols, c->vc_rows);
}
vgacon_scrollback_init(c->vc_size_row);
return 0;
}
static void vga_set_palette(struct vc_data *vc, unsigned char *table)
{
int i, j;
vga_w(state.vgabase, VGA_PEL_MSK, 0xff);
for (i = j = 0; i < 16; i++) {
vga_w(state.vgabase, VGA_PEL_IW, table[i]);
vga_w(state.vgabase, VGA_PEL_D, vc->vc_palette[j++] >> 2);
vga_w(state.vgabase, VGA_PEL_D, vc->vc_palette[j++] >> 2);
vga_w(state.vgabase, VGA_PEL_D, vc->vc_palette[j++] >> 2);
}
}
static int vgacon_set_palette(struct vc_data *vc, unsigned char *table)
{
#ifdef CAN_LOAD_PALETTE
if (vga_video_type != VIDEO_TYPE_VGAC || vga_palette_blanked
|| !CON_IS_VISIBLE(vc))
return -EINVAL;
vga_set_palette(vc, table);
return 0;
#else
return -EINVAL;
#endif
}
static void vga_vesa_blank(struct vgastate *state, int mode)
{
if (!vga_vesa_blanked) {
raw_spin_lock_irq(&vga_lock);
vga_state.SeqCtrlIndex = vga_r(state->vgabase, VGA_SEQ_I);
vga_state.CrtCtrlIndex = inb_p(vga_video_port_reg);
vga_state.CrtMiscIO = vga_r(state->vgabase, VGA_MIS_R);
raw_spin_unlock_irq(&vga_lock);
outb_p(0x00, vga_video_port_reg);
vga_state.HorizontalTotal = inb_p(vga_video_port_val);
outb_p(0x01, vga_video_port_reg);
vga_state.HorizDisplayEnd = inb_p(vga_video_port_val);
outb_p(0x04, vga_video_port_reg);
vga_state.StartHorizRetrace = inb_p(vga_video_port_val);
outb_p(0x05, vga_video_port_reg);
vga_state.EndHorizRetrace = inb_p(vga_video_port_val);
outb_p(0x07, vga_video_port_reg);
vga_state.Overflow = inb_p(vga_video_port_val);
outb_p(0x10, vga_video_port_reg);
vga_state.StartVertRetrace = inb_p(vga_video_port_val);
outb_p(0x11, vga_video_port_reg);
vga_state.EndVertRetrace = inb_p(vga_video_port_val);
outb_p(0x17, vga_video_port_reg);
vga_state.ModeControl = inb_p(vga_video_port_val);
vga_state.ClockingMode = vga_rseq(state->vgabase, VGA_SEQ_CLOCK_MODE);
}
raw_spin_lock_irq(&vga_lock);
vga_wseq(state->vgabase, VGA_SEQ_CLOCK_MODE, vga_state.ClockingMode | 0x20);
if ((vga_state.CrtMiscIO & 0x80) == 0x80)
vga_w(state->vgabase, VGA_MIS_W, vga_state.CrtMiscIO & 0xEF);
if (mode & VESA_VSYNC_SUSPEND) {
outb_p(0x10, vga_video_port_reg);
outb_p(0xff, vga_video_port_val);
outb_p(0x11, vga_video_port_reg);
outb_p(0x40, vga_video_port_val);
outb_p(0x07, vga_video_port_reg);
outb_p(vga_state.Overflow | 0x84, vga_video_port_val);
}
if (mode & VESA_HSYNC_SUSPEND) {
outb_p(0x04, vga_video_port_reg);
outb_p(0xff, vga_video_port_val);
outb_p(0x05, vga_video_port_reg);
outb_p(0x00, vga_video_port_val);
}
vga_w(state->vgabase, VGA_SEQ_I, vga_state.SeqCtrlIndex);
outb_p(vga_state.CrtCtrlIndex, vga_video_port_reg);
raw_spin_unlock_irq(&vga_lock);
}
static void vga_vesa_unblank(struct vgastate *state)
{
raw_spin_lock_irq(&vga_lock);
vga_w(state->vgabase, VGA_MIS_W, vga_state.CrtMiscIO);
outb_p(0x00, vga_video_port_reg);
outb_p(vga_state.HorizontalTotal, vga_video_port_val);
outb_p(0x01, vga_video_port_reg);
outb_p(vga_state.HorizDisplayEnd, vga_video_port_val);
outb_p(0x04, vga_video_port_reg);
outb_p(vga_state.StartHorizRetrace, vga_video_port_val);
outb_p(0x05, vga_video_port_reg);
outb_p(vga_state.EndHorizRetrace, vga_video_port_val);
outb_p(0x07, vga_video_port_reg);
outb_p(vga_state.Overflow, vga_video_port_val);
outb_p(0x10, vga_video_port_reg);
outb_p(vga_state.StartVertRetrace, vga_video_port_val);
outb_p(0x11, vga_video_port_reg);
outb_p(vga_state.EndVertRetrace, vga_video_port_val);
outb_p(0x17, vga_video_port_reg);
outb_p(vga_state.ModeControl, vga_video_port_val);
vga_wseq(state->vgabase, VGA_SEQ_CLOCK_MODE, vga_state.ClockingMode);
vga_w(state->vgabase, VGA_SEQ_I, vga_state.SeqCtrlIndex);
outb_p(vga_state.CrtCtrlIndex, vga_video_port_reg);
raw_spin_unlock_irq(&vga_lock);
}
static void vga_pal_blank(struct vgastate *state)
{
int i;
vga_w(state->vgabase, VGA_PEL_MSK, 0xff);
for (i = 0; i < 16; i++) {
vga_w(state->vgabase, VGA_PEL_IW, i);
vga_w(state->vgabase, VGA_PEL_D, 0);
vga_w(state->vgabase, VGA_PEL_D, 0);
vga_w(state->vgabase, VGA_PEL_D, 0);
}
}
static int vgacon_blank(struct vc_data *c, int blank, int mode_switch)
{
switch (blank) {
case 0:
if (vga_vesa_blanked) {
vga_vesa_unblank(&state);
vga_vesa_blanked = 0;
}
if (vga_palette_blanked) {
vga_set_palette(c, color_table);
vga_palette_blanked = 0;
return 0;
}
vga_is_gfx = 0;
return 1;
case 1:
case -1:
if (!mode_switch && vga_video_type == VIDEO_TYPE_VGAC) {
vga_pal_blank(&state);
vga_palette_blanked = 1;
return 0;
}
vgacon_set_origin(c);
scr_memsetw((void *) vga_vram_base, BLANK,
c->vc_screenbuf_size);
if (mode_switch)
vga_is_gfx = 1;
return 1;
default:
if (vga_video_type == VIDEO_TYPE_VGAC) {
vga_vesa_blank(&state, blank - 1);
vga_vesa_blanked = blank;
}
return 0;
}
}
static int vgacon_do_font_op(struct vgastate *state,char *arg,int set,int ch512)
{
unsigned short video_port_status = vga_video_port_reg + 6;
int font_select = 0x00, beg, i;
char *charmap;
if (vga_video_type != VIDEO_TYPE_EGAM) {
charmap = (char *) VGA_MAP_MEM(colourmap, 0);
beg = 0x0e;
#ifdef VGA_CAN_DO_64KB
if (vga_video_type == VIDEO_TYPE_VGAC)
beg = 0x06;
#endif
} else {
charmap = (char *) VGA_MAP_MEM(blackwmap, 0);
beg = 0x0a;
}
#ifdef BROKEN_GRAPHICS_PROGRAMS
if (!arg)
return -EINVAL;
vga_font_is_default = 0;
font_select = ch512 ? 0x04 : 0x00;
#else
if (set) {
vga_font_is_default = !arg;
if (!arg)
ch512 = 0;
font_select = arg ? (ch512 ? 0x0e : 0x0a) : 0x00;
}
if (!vga_font_is_default)
charmap += 4 * cmapsz;
#endif
raw_spin_lock_irq(&vga_lock);
vga_wseq(state->vgabase, VGA_SEQ_RESET, 0x1);
vga_wseq(state->vgabase, VGA_SEQ_PLANE_WRITE, 0x04);
vga_wseq(state->vgabase, VGA_SEQ_MEMORY_MODE, 0x07);
vga_wseq(state->vgabase, VGA_SEQ_RESET, 0x03);
vga_wgfx(state->vgabase, VGA_GFX_PLANE_READ, 0x02);
vga_wgfx(state->vgabase, VGA_GFX_MODE, 0x00);
vga_wgfx(state->vgabase, VGA_GFX_MISC, 0x00);
raw_spin_unlock_irq(&vga_lock);
if (arg) {
if (set)
for (i = 0; i < cmapsz; i++)
vga_writeb(arg[i], charmap + i);
else
for (i = 0; i < cmapsz; i++)
arg[i] = vga_readb(charmap + i);
if (ch512) {
charmap += 2 * cmapsz;
arg += cmapsz;
if (set)
for (i = 0; i < cmapsz; i++)
vga_writeb(arg[i], charmap + i);
else
for (i = 0; i < cmapsz; i++)
arg[i] = vga_readb(charmap + i);
}
}
raw_spin_lock_irq(&vga_lock);
vga_wseq(state->vgabase, VGA_SEQ_RESET, 0x01);
vga_wseq(state->vgabase, VGA_SEQ_PLANE_WRITE, 0x03);
vga_wseq(state->vgabase, VGA_SEQ_MEMORY_MODE, 0x03);
if (set)
vga_wseq(state->vgabase, VGA_SEQ_CHARACTER_MAP, font_select);
vga_wseq(state->vgabase, VGA_SEQ_RESET, 0x03);
vga_wgfx(state->vgabase, VGA_GFX_PLANE_READ, 0x00);
vga_wgfx(state->vgabase, VGA_GFX_MODE, 0x10);
vga_wgfx(state->vgabase, VGA_GFX_MISC, beg);
if ((set) && (ch512 != vga_512_chars)) {
for (i = 0; i < MAX_NR_CONSOLES; i++) {
struct vc_data *c = vc_cons[i].d;
if (c && c->vc_sw == &vga_con)
c->vc_hi_font_mask = ch512 ? 0x0800 : 0;
}
vga_512_chars = ch512;
inb_p(video_port_status);
vga_wattr(state->vgabase, VGA_ATC_PLANE_ENABLE, ch512 ? 0x07 : 0x0f);
inb_p(video_port_status);
vga_wattr(state->vgabase, VGA_AR_ENABLE_DISPLAY, 0);
}
raw_spin_unlock_irq(&vga_lock);
return 0;
}
static int vgacon_adjust_height(struct vc_data *vc, unsigned fontheight)
{
unsigned char ovr, vde, fsr;
int rows, maxscan, i;
rows = vc->vc_scan_lines / fontheight;
maxscan = rows * fontheight - 1;
raw_spin_lock_irq(&vga_lock);
outb_p(0x07, vga_video_port_reg);
ovr = inb_p(vga_video_port_val);
outb_p(0x09, vga_video_port_reg);
fsr = inb_p(vga_video_port_val);
raw_spin_unlock_irq(&vga_lock);
vde = maxscan & 0xff;
ovr = (ovr & 0xbd) +
((maxscan & 0x100) >> 7) + ((maxscan & 0x200) >> 3);
fsr = (fsr & 0xe0) + (fontheight - 1);
raw_spin_lock_irq(&vga_lock);
outb_p(0x07, vga_video_port_reg);
outb_p(ovr, vga_video_port_val);
outb_p(0x09, vga_video_port_reg);
outb_p(fsr, vga_video_port_val);
outb_p(0x12, vga_video_port_reg);
outb_p(vde, vga_video_port_val);
raw_spin_unlock_irq(&vga_lock);
vga_video_font_height = fontheight;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
struct vc_data *c = vc_cons[i].d;
if (c && c->vc_sw == &vga_con) {
if (CON_IS_VISIBLE(c)) {
cursor_size_lastfrom = 0;
cursor_size_lastto = 0;
c->vc_sw->con_cursor(c, CM_DRAW);
}
c->vc_font.height = fontheight;
vc_resize(c, 0, rows);
}
}
return 0;
}
static int vgacon_font_set(struct vc_data *c, struct console_font *font, unsigned flags)
{
unsigned charcount = font->charcount;
int rc;
if (vga_video_type < VIDEO_TYPE_EGAM)
return -EINVAL;
if (font->width != VGA_FONTWIDTH ||
(charcount != 256 && charcount != 512))
return -EINVAL;
rc = vgacon_do_font_op(&state, font->data, 1, charcount == 512);
if (rc)
return rc;
if (!(flags & KD_FONT_FLAG_DONT_RECALC))
rc = vgacon_adjust_height(c, font->height);
return rc;
}
static int vgacon_font_get(struct vc_data *c, struct console_font *font)
{
if (vga_video_type < VIDEO_TYPE_EGAM)
return -EINVAL;
font->width = VGA_FONTWIDTH;
font->height = c->vc_font.height;
font->charcount = vga_512_chars ? 512 : 256;
if (!font->data)
return 0;
return vgacon_do_font_op(&state, font->data, 0, vga_512_chars);
}
static int vgacon_resize(struct vc_data *c, unsigned int width,
unsigned int height, unsigned int user)
{
if (width % 2 || width > screen_info.orig_video_cols ||
height > (screen_info.orig_video_lines * vga_default_font_height)/
c->vc_font.height)
return (user) ? 0 : -EINVAL;
if (CON_IS_VISIBLE(c) && !vga_is_gfx)
vgacon_doresize(c, width, height);
return 0;
}
static int vgacon_set_origin(struct vc_data *c)
{
if (vga_is_gfx ||
(console_blanked && !vga_palette_blanked))
return 0;
c->vc_origin = c->vc_visible_origin = vga_vram_base;
vga_set_mem_top(c);
vga_rolled_over = 0;
return 1;
}
static void vgacon_save_screen(struct vc_data *c)
{
static int vga_bootup_console = 0;
if (!vga_bootup_console) {
vga_bootup_console = 1;
c->vc_x = screen_info.orig_x;
c->vc_y = screen_info.orig_y;
}
if (!vga_is_gfx)
scr_memcpyw((u16 *) c->vc_screenbuf, (u16 *) c->vc_origin,
c->vc_screenbuf_size > vga_vram_size ? vga_vram_size : c->vc_screenbuf_size);
}
static int vgacon_scroll(struct vc_data *c, int t, int b, int dir,
int lines)
{
unsigned long oldo;
unsigned int delta;
if (t || b != c->vc_rows || vga_is_gfx || c->vc_mode != KD_TEXT)
return 0;
if (!vga_hardscroll_enabled || lines >= c->vc_rows / 2)
return 0;
vgacon_restore_screen(c);
oldo = c->vc_origin;
delta = lines * c->vc_size_row;
if (dir == SM_UP) {
vgacon_scrollback_update(c, t, lines);
if (c->vc_scr_end + delta >= vga_vram_end) {
scr_memcpyw((u16 *) vga_vram_base,
(u16 *) (oldo + delta),
c->vc_screenbuf_size - delta);
c->vc_origin = vga_vram_base;
vga_rolled_over = oldo - vga_vram_base;
} else
c->vc_origin += delta;
scr_memsetw((u16 *) (c->vc_origin + c->vc_screenbuf_size -
delta), c->vc_video_erase_char,
delta);
} else {
if (oldo - delta < vga_vram_base) {
scr_memmovew((u16 *) (vga_vram_end -
c->vc_screenbuf_size +
delta), (u16 *) oldo,
c->vc_screenbuf_size - delta);
c->vc_origin = vga_vram_end - c->vc_screenbuf_size;
vga_rolled_over = 0;
} else
c->vc_origin -= delta;
c->vc_scr_end = c->vc_origin + c->vc_screenbuf_size;
scr_memsetw((u16 *) (c->vc_origin), c->vc_video_erase_char,
delta);
}
c->vc_scr_end = c->vc_origin + c->vc_screenbuf_size;
c->vc_visible_origin = c->vc_origin;
vga_set_mem_top(c);
c->vc_pos = (c->vc_pos - oldo) + c->vc_origin;
return 1;
}
static int vgacon_dummy(struct vc_data *c)
{
return 0;
}
