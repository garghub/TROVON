static inline void cursor_undrawn(void)
{
vbl_cursor_cnt = 0;
cursor_drawn = 0;
}
static const char *sticon_startup(void)
{
return "STI console";
}
static void sticon_putc(struct vc_data *conp, int c, int ypos, int xpos)
{
int redraw_cursor = 0;
if (vga_is_gfx || console_blanked)
return;
if (conp->vc_mode != KD_TEXT)
return;
#if 0
if ((p->cursor_x == xpos) && (p->cursor_y == ypos)) {
cursor_undrawn();
redraw_cursor = 1;
}
#endif
sti_putc(sticon_sti, c, ypos, xpos);
if (redraw_cursor)
vbl_cursor_cnt = CURSOR_DRAW_DELAY;
}
static void sticon_putcs(struct vc_data *conp, const unsigned short *s,
int count, int ypos, int xpos)
{
int redraw_cursor = 0;
if (vga_is_gfx || console_blanked)
return;
if (conp->vc_mode != KD_TEXT)
return;
#if 0
if ((p->cursor_y == ypos) && (xpos <= p->cursor_x) &&
(p->cursor_x < (xpos + count))) {
cursor_undrawn();
redraw_cursor = 1;
}
#endif
while (count--) {
sti_putc(sticon_sti, scr_readw(s++), ypos, xpos++);
}
if (redraw_cursor)
vbl_cursor_cnt = CURSOR_DRAW_DELAY;
}
static void sticon_cursor(struct vc_data *conp, int mode)
{
unsigned short car1;
car1 = conp->vc_screenbuf[conp->vc_x + conp->vc_y * conp->vc_cols];
switch (mode) {
case CM_ERASE:
sti_putc(sticon_sti, car1, conp->vc_y, conp->vc_x);
break;
case CM_MOVE:
case CM_DRAW:
switch (conp->vc_cursor_type & 0x0f) {
case CUR_UNDERLINE:
case CUR_LOWER_THIRD:
case CUR_LOWER_HALF:
case CUR_TWO_THIRDS:
case CUR_BLOCK:
sti_putc(sticon_sti, (car1 & 255) + (0 << 8) + (7 << 11),
conp->vc_y, conp->vc_x);
break;
}
break;
}
}
static bool sticon_scroll(struct vc_data *conp, unsigned int t,
unsigned int b, enum con_scroll dir, unsigned int count)
{
struct sti_struct *sti = sticon_sti;
if (vga_is_gfx)
return false;
sticon_cursor(conp, CM_ERASE);
switch (dir) {
case SM_UP:
sti_bmove(sti, t + count, 0, t, 0, b - t - count, conp->vc_cols);
sti_clear(sti, b - count, 0, count, conp->vc_cols, conp->vc_video_erase_char);
break;
case SM_DOWN:
sti_bmove(sti, t, 0, t + count, 0, b - t - count, conp->vc_cols);
sti_clear(sti, t, 0, count, conp->vc_cols, conp->vc_video_erase_char);
break;
}
return false;
}
static void sticon_init(struct vc_data *c, int init)
{
struct sti_struct *sti = sticon_sti;
int vc_cols, vc_rows;
sti_set(sti, 0, 0, sti_onscreen_y(sti), sti_onscreen_x(sti), 0);
vc_cols = sti_onscreen_x(sti) / sti->font_width;
vc_rows = sti_onscreen_y(sti) / sti->font_height;
c->vc_can_do_color = 1;
if (init) {
c->vc_cols = vc_cols;
c->vc_rows = vc_rows;
} else {
vc_resize(c, vc_cols, vc_rows);
}
}
static void sticon_deinit(struct vc_data *c)
{
}
static void sticon_clear(struct vc_data *conp, int sy, int sx, int height,
int width)
{
if (!height || !width)
return;
sti_clear(sticon_sti, sy, sx, height, width, conp->vc_video_erase_char);
}
static int sticon_switch(struct vc_data *conp)
{
return 1;
}
static int sticon_set_origin(struct vc_data *conp)
{
return 0;
}
static int sticon_blank(struct vc_data *c, int blank, int mode_switch)
{
if (blank == 0) {
if (mode_switch)
vga_is_gfx = 0;
return 1;
}
sticon_set_origin(c);
sti_clear(sticon_sti, 0,0, c->vc_rows, c->vc_cols, BLANK);
if (mode_switch)
vga_is_gfx = 1;
return 1;
}
static u16 *sticon_screen_pos(struct vc_data *conp, int offset)
{
int line;
unsigned long p;
if (conp->vc_num != fg_console || !softback_lines)
return (u16 *)(conp->vc_origin + offset);
line = offset / conp->vc_size_row;
if (line >= softback_lines)
return (u16 *)(conp->vc_origin + offset - softback_lines * conp->vc_size_row);
p = softback_curr + offset;
if (p >= softback_end)
p += softback_buf - softback_end;
return (u16 *)p;
}
static unsigned long sticon_getxy(struct vc_data *conp, unsigned long pos,
int *px, int *py)
{
int x, y;
unsigned long ret;
if (pos >= conp->vc_origin && pos < conp->vc_scr_end) {
unsigned long offset = (pos - conp->vc_origin) / 2;
x = offset % conp->vc_cols;
y = offset / conp->vc_cols;
if (conp->vc_num == fg_console)
y += softback_lines;
ret = pos + (conp->vc_cols - x) * 2;
} else if (conp->vc_num == fg_console && softback_lines) {
unsigned long offset = pos - softback_curr;
if (pos < softback_curr)
offset += softback_end - softback_buf;
offset /= 2;
x = offset % conp->vc_cols;
y = offset / conp->vc_cols;
ret = pos + (conp->vc_cols - x) * 2;
if (ret == softback_end)
ret = softback_buf;
if (ret == softback_in)
ret = conp->vc_origin;
} else {
x = y = 0;
ret = conp->vc_origin;
}
if (px) *px = x;
if (py) *py = y;
return ret;
}
static u8 sticon_build_attr(struct vc_data *conp, u8 color, u8 intens,
u8 blink, u8 underline, u8 reverse, u8 italic)
{
u8 attr = ((color & 0x70) >> 1) | ((color & 7));
if (reverse) {
color = ((color >> 3) & 0x7) | ((color & 0x7) << 3);
}
return attr;
}
static void sticon_invert_region(struct vc_data *conp, u16 *p, int count)
{
int col = 1;
while (count--) {
u16 a = scr_readw(p);
if (col)
a = ((a) & 0x88ff) | (((a) & 0x7000) >> 4) | (((a) & 0x0700) << 4);
else
a = ((a & 0x0700) == 0x0100) ? 0x7000 : 0x7700;
scr_writew(a, p++);
}
}
static void sticon_save_screen(struct vc_data *conp)
{
}
static int __init sticonsole_init(void)
{
int err;
if (sticon_sti)
return 0;
sticon_sti = sti_get_rom(0);
if (!sticon_sti)
return -ENODEV;
if (conswitchp == &dummy_con) {
printk(KERN_INFO "sticon: Initializing STI text console.\n");
console_lock();
err = do_take_over_console(&sti_con, 0, MAX_NR_CONSOLES - 1, 1);
console_unlock();
return err;
}
return 0;
}
