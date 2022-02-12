static inline void
sisusbcon_memsetw(u16 *s, u16 c, unsigned int count)
{
count /= 2;
while (count--)
sisusbcon_writew(c, s++);
}
static inline void
sisusb_initialize(struct sisusb_usb_data *sisusb)
{
if (sisusb_setidxreg(sisusb, SISCR, 0x0c, 0x00))
return;
if (sisusb_setidxreg(sisusb, SISCR, 0x0d, 0x00))
return;
if (sisusb_setidxreg(sisusb, SISCR, 0x0e, 0x00))
return;
sisusb_setidxreg(sisusb, SISCR, 0x0f, 0x00);
}
static inline void
sisusbcon_set_start_address(struct sisusb_usb_data *sisusb, struct vc_data *c)
{
sisusb->cur_start_addr = (c->vc_visible_origin - sisusb->scrbuf) / 2;
sisusb_setidxreg(sisusb, SISCR, 0x0c, (sisusb->cur_start_addr >> 8));
sisusb_setidxreg(sisusb, SISCR, 0x0d, (sisusb->cur_start_addr & 0xff));
}
void
sisusb_set_cursor(struct sisusb_usb_data *sisusb, unsigned int location)
{
if (sisusb->sisusb_cursor_loc == location)
return;
sisusb->sisusb_cursor_loc = location;
if ((location & 0x0007) == 0x0007) {
sisusb->bad_cursor_pos = 1;
location--;
if (sisusb_setidxregandor(sisusb, SISCR, 0x0b, 0x1f, 0x20))
return;
} else if (sisusb->bad_cursor_pos) {
if (sisusb_setidxregand(sisusb, SISCR, 0x0b, 0x1f))
return;
sisusb->bad_cursor_pos = 0;
}
if (sisusb_setidxreg(sisusb, SISCR, 0x0e, (location >> 8)))
return;
sisusb_setidxreg(sisusb, SISCR, 0x0f, (location & 0xff));
}
static inline struct sisusb_usb_data *
sisusb_get_sisusb(unsigned short console)
{
return mysisusbs[console];
}
static inline int
sisusb_sisusb_valid(struct sisusb_usb_data *sisusb)
{
if (!sisusb->present || !sisusb->ready || !sisusb->sisusb_dev)
return 0;
return 1;
}
static struct sisusb_usb_data *
sisusb_get_sisusb_lock_and_check(unsigned short console)
{
struct sisusb_usb_data *sisusb;
if (in_atomic())
return NULL;
sisusb = sisusb_get_sisusb(console);
if (!sisusb)
return NULL;
mutex_lock(&sisusb->lock);
if (!sisusb_sisusb_valid(sisusb) ||
!sisusb->havethisconsole[console]) {
mutex_unlock(&sisusb->lock);
return NULL;
}
return sisusb;
}
static int
sisusb_is_inactive(struct vc_data *c, struct sisusb_usb_data *sisusb)
{
if (sisusb->is_gfx ||
sisusb->textmodedestroyed ||
c->vc_mode != KD_TEXT)
return 1;
return 0;
}
static const char *
sisusbcon_startup(void)
{
return "SISUSBCON";
}
static void
sisusbcon_init(struct vc_data *c, int init)
{
struct sisusb_usb_data *sisusb;
int cols, rows;
sisusb = sisusb_get_sisusb(c->vc_num);
if (!sisusb)
return;
mutex_lock(&sisusb->lock);
if (!sisusb_sisusb_valid(sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
c->vc_can_do_color = 1;
c->vc_complement_mask = 0x7700;
c->vc_hi_font_mask = sisusb->current_font_512 ? 0x0800 : 0;
sisusb->haveconsole = 1;
sisusb->havethisconsole[c->vc_num] = 1;
c->vc_scan_lines = 400;
c->vc_font.height = sisusb->current_font_height;
cols = 80;
rows = c->vc_scan_lines / c->vc_font.height;
kref_get(&sisusb->kref);
if (!*c->vc_uni_pagedir_loc)
con_set_default_unimap(c);
mutex_unlock(&sisusb->lock);
if (init) {
c->vc_cols = cols;
c->vc_rows = rows;
} else
vc_resize(c, cols, rows);
}
static void
sisusbcon_deinit(struct vc_data *c)
{
struct sisusb_usb_data *sisusb;
int i;
sisusb = sisusb_get_sisusb(c->vc_num);
if (!sisusb)
return;
mutex_lock(&sisusb->lock);
mysisusbs[c->vc_num] = NULL;
sisusb->havethisconsole[c->vc_num] = 0;
if (sisusb->font_backup) {
for(i = 0; i < MAX_NR_CONSOLES; i++) {
if (sisusb->havethisconsole[c->vc_num])
break;
}
if (i == MAX_NR_CONSOLES) {
vfree(sisusb->font_backup);
sisusb->font_backup = NULL;
}
}
mutex_unlock(&sisusb->lock);
kref_put(&sisusb->kref, sisusb_delete);
}
static u8
sisusbcon_build_attr(struct vc_data *c, u8 color, u8 intensity,
u8 blink, u8 underline, u8 reverse, u8 unused)
{
u8 attr = color;
if (underline)
attr = (attr & 0xf0) | c->vc_ulcolor;
else if (intensity == 0)
attr = (attr & 0xf0) | c->vc_halfcolor;
if (reverse)
attr = ((attr) & 0x88) |
((((attr) >> 4) |
((attr) << 4)) & 0x77);
if (blink)
attr ^= 0x80;
if (intensity == 2)
attr ^= 0x08;
return attr;
}
static void
sisusbcon_invert_region(struct vc_data *vc, u16 *p, int count)
{
while (count--) {
u16 a = sisusbcon_readw(p);
a = ((a) & 0x88ff) |
(((a) & 0x7000) >> 4) |
(((a) & 0x0700) << 4);
sisusbcon_writew(a, p++);
}
}
static void
sisusbcon_putc(struct vc_data *c, int ch, int y, int x)
{
struct sisusb_usb_data *sisusb;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
sisusb_copy_memory(sisusb, (char *)SISUSB_VADDR(x, y),
(long)SISUSB_HADDR(x, y), 2);
mutex_unlock(&sisusb->lock);
}
static void
sisusbcon_putcs(struct vc_data *c, const unsigned short *s,
int count, int y, int x)
{
struct sisusb_usb_data *sisusb;
u16 *dest;
int i;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return;
dest = SISUSB_VADDR(x, y);
for (i = count; i > 0; i--)
sisusbcon_writew(sisusbcon_readw(s++), dest++);
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
sisusb_copy_memory(sisusb, (char *)SISUSB_VADDR(x, y),
(long)SISUSB_HADDR(x, y), count * 2);
mutex_unlock(&sisusb->lock);
}
static void
sisusbcon_clear(struct vc_data *c, int y, int x, int height, int width)
{
struct sisusb_usb_data *sisusb;
u16 eattr = c->vc_video_erase_char;
int i, length, cols;
u16 *dest;
if (width <= 0 || height <= 0)
return;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return;
dest = SISUSB_VADDR(x, y);
cols = sisusb->sisusb_num_columns;
if (width > cols)
width = cols;
if (x == 0 && width >= c->vc_cols) {
sisusbcon_memsetw(dest, eattr, height * cols * 2);
} else {
for (i = height; i > 0; i--, dest += cols)
sisusbcon_memsetw(dest, eattr, width * 2);
}
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
length = ((height * cols) - x - (cols - width - x)) * 2;
sisusb_copy_memory(sisusb, (unsigned char *)SISUSB_VADDR(x, y),
(long)SISUSB_HADDR(x, y), length);
mutex_unlock(&sisusb->lock);
}
static int
sisusbcon_switch(struct vc_data *c)
{
struct sisusb_usb_data *sisusb;
int length;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return 0;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return 0;
}
if (c->vc_origin == (unsigned long)c->vc_screenbuf) {
mutex_unlock(&sisusb->lock);
dev_dbg(&sisusb->sisusb_dev->dev, "ASSERT ORIGIN != SCREENBUF!\n");
return 0;
}
length = min((int)c->vc_screenbuf_size,
(int)(sisusb->scrbuf + sisusb->scrbuf_size - c->vc_origin));
sisusbcon_memcpyw((u16 *)c->vc_origin, (u16 *)c->vc_screenbuf,
length);
sisusb_copy_memory(sisusb, (unsigned char *)c->vc_origin,
(long)SISUSB_HADDR(0, 0),
length);
mutex_unlock(&sisusb->lock);
return 0;
}
static void
sisusbcon_save_screen(struct vc_data *c)
{
struct sisusb_usb_data *sisusb;
int length;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
length = min((int)c->vc_screenbuf_size,
(int)(sisusb->scrbuf + sisusb->scrbuf_size - c->vc_origin));
sisusbcon_memcpyw((u16 *)c->vc_screenbuf, (u16 *)c->vc_origin,
length);
mutex_unlock(&sisusb->lock);
}
static void
sisusbcon_set_palette(struct vc_data *c, const unsigned char *table)
{
struct sisusb_usb_data *sisusb;
int i, j;
if (!con_is_visible(c))
return;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
for (i = j = 0; i < 16; i++) {
if (sisusb_setreg(sisusb, SISCOLIDX, table[i]))
break;
if (sisusb_setreg(sisusb, SISCOLDATA, c->vc_palette[j++] >> 2))
break;
if (sisusb_setreg(sisusb, SISCOLDATA, c->vc_palette[j++] >> 2))
break;
if (sisusb_setreg(sisusb, SISCOLDATA, c->vc_palette[j++] >> 2))
break;
}
mutex_unlock(&sisusb->lock);
}
static int
sisusbcon_blank(struct vc_data *c, int blank, int mode_switch)
{
struct sisusb_usb_data *sisusb;
u8 sr1, cr17, pmreg, cr63;
int ret = 0;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return 0;
if (mode_switch)
sisusb->is_gfx = blank ? 1 : 0;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return 0;
}
switch (blank) {
case 1:
case -1:
sisusbcon_memsetw((u16 *)c->vc_origin,
c->vc_video_erase_char,
c->vc_screenbuf_size);
sisusb_copy_memory(sisusb,
(unsigned char *)c->vc_origin,
(u32)(sisusb->vrambase +
(c->vc_origin - sisusb->scrbuf)),
c->vc_screenbuf_size);
sisusb->con_blanked = 1;
ret = 1;
break;
default:
switch (blank) {
case 0:
sr1 = 0x00;
cr17 = 0x80;
pmreg = 0x00;
cr63 = 0x00;
ret = 1;
sisusb->con_blanked = 0;
break;
case VESA_VSYNC_SUSPEND + 1:
sr1 = 0x20;
cr17 = 0x80;
pmreg = 0x80;
cr63 = 0x40;
break;
case VESA_HSYNC_SUSPEND + 1:
sr1 = 0x20;
cr17 = 0x80;
pmreg = 0x40;
cr63 = 0x40;
break;
case VESA_POWERDOWN + 1:
sr1 = 0x20;
cr17 = 0x00;
pmreg = 0xc0;
cr63 = 0x40;
break;
default:
mutex_unlock(&sisusb->lock);
return -EINVAL;
}
sisusb_setidxregandor(sisusb, SISSR, 0x01, ~0x20, sr1);
sisusb_setidxregandor(sisusb, SISCR, 0x17, 0x7f, cr17);
sisusb_setidxregandor(sisusb, SISSR, 0x1f, 0x3f, pmreg);
sisusb_setidxregandor(sisusb, SISCR, 0x63, 0xbf, cr63);
}
mutex_unlock(&sisusb->lock);
return ret;
}
static void
sisusbcon_scrolldelta(struct vc_data *c, int lines)
{
struct sisusb_usb_data *sisusb;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
vc_scrolldelta_helper(c, lines, sisusb->con_rolled_over,
(void *)sisusb->scrbuf, sisusb->scrbuf_size);
sisusbcon_set_start_address(sisusb, c);
mutex_unlock(&sisusb->lock);
}
static void
sisusbcon_cursor(struct vc_data *c, int mode)
{
struct sisusb_usb_data *sisusb;
int from, to, baseline;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return;
}
if (c->vc_origin != c->vc_visible_origin) {
c->vc_visible_origin = c->vc_origin;
sisusbcon_set_start_address(sisusb, c);
}
if (mode == CM_ERASE) {
sisusb_setidxregor(sisusb, SISCR, 0x0a, 0x20);
sisusb->sisusb_cursor_size_to = -1;
mutex_unlock(&sisusb->lock);
return;
}
sisusb_set_cursor(sisusb, (c->vc_pos - sisusb->scrbuf) / 2);
baseline = c->vc_font.height - (c->vc_font.height < 10 ? 1 : 2);
switch (c->vc_cursor_type & 0x0f) {
case CUR_BLOCK: from = 1;
to = c->vc_font.height;
break;
case CUR_TWO_THIRDS: from = c->vc_font.height / 3;
to = baseline;
break;
case CUR_LOWER_HALF: from = c->vc_font.height / 2;
to = baseline;
break;
case CUR_LOWER_THIRD: from = (c->vc_font.height * 2) / 3;
to = baseline;
break;
case CUR_NONE: from = 31;
to = 30;
break;
default:
case CUR_UNDERLINE: from = baseline - 1;
to = baseline;
break;
}
if (sisusb->sisusb_cursor_size_from != from ||
sisusb->sisusb_cursor_size_to != to) {
sisusb_setidxreg(sisusb, SISCR, 0x0a, from);
sisusb_setidxregandor(sisusb, SISCR, 0x0b, 0xe0, to);
sisusb->sisusb_cursor_size_from = from;
sisusb->sisusb_cursor_size_to = to;
}
mutex_unlock(&sisusb->lock);
}
static bool
sisusbcon_scroll_area(struct vc_data *c, struct sisusb_usb_data *sisusb,
unsigned int t, unsigned int b, enum con_scroll dir,
unsigned int lines)
{
int cols = sisusb->sisusb_num_columns;
int length = ((b - t) * cols) * 2;
u16 eattr = c->vc_video_erase_char;
switch (dir) {
case SM_UP:
sisusbcon_memmovew(SISUSB_VADDR(0, t),
SISUSB_VADDR(0, t + lines),
(b - t - lines) * cols * 2);
sisusbcon_memsetw(SISUSB_VADDR(0, b - lines), eattr,
lines * cols * 2);
break;
case SM_DOWN:
sisusbcon_memmovew(SISUSB_VADDR(0, t + lines),
SISUSB_VADDR(0, t),
(b - t - lines) * cols * 2);
sisusbcon_memsetw(SISUSB_VADDR(0, t), eattr,
lines * cols * 2);
break;
}
sisusb_copy_memory(sisusb, (char *)SISUSB_VADDR(0, t),
(long)SISUSB_HADDR(0, t), length);
mutex_unlock(&sisusb->lock);
return 1;
}
static bool
sisusbcon_scroll(struct vc_data *c, unsigned int t, unsigned int b,
enum con_scroll dir, unsigned int lines)
{
struct sisusb_usb_data *sisusb;
u16 eattr = c->vc_video_erase_char;
int copyall = 0;
unsigned long oldorigin;
unsigned int delta = lines * c->vc_size_row;
u32 originoffset;
if (!lines)
return true;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return false;
if (sisusb_is_inactive(c, sisusb)) {
mutex_unlock(&sisusb->lock);
return false;
}
if (t || b != c->vc_rows)
return sisusbcon_scroll_area(c, sisusb, t, b, dir, lines);
if (c->vc_origin != c->vc_visible_origin) {
c->vc_visible_origin = c->vc_origin;
sisusbcon_set_start_address(sisusb, c);
}
if (lines > c->vc_rows)
lines = c->vc_rows;
oldorigin = c->vc_origin;
switch (dir) {
case SM_UP:
if (c->vc_scr_end + delta >=
sisusb->scrbuf + sisusb->scrbuf_size) {
sisusbcon_memcpyw((u16 *)sisusb->scrbuf,
(u16 *)(oldorigin + delta),
c->vc_screenbuf_size - delta);
c->vc_origin = sisusb->scrbuf;
sisusb->con_rolled_over = oldorigin - sisusb->scrbuf;
copyall = 1;
} else
c->vc_origin += delta;
sisusbcon_memsetw(
(u16 *)(c->vc_origin + c->vc_screenbuf_size - delta),
eattr, delta);
break;
case SM_DOWN:
if (oldorigin - delta < sisusb->scrbuf) {
sisusbcon_memmovew((u16 *)(sisusb->scrbuf +
sisusb->scrbuf_size -
c->vc_screenbuf_size +
delta),
(u16 *)oldorigin,
c->vc_screenbuf_size - delta);
c->vc_origin = sisusb->scrbuf +
sisusb->scrbuf_size -
c->vc_screenbuf_size;
sisusb->con_rolled_over = 0;
copyall = 1;
} else
c->vc_origin -= delta;
c->vc_scr_end = c->vc_origin + c->vc_screenbuf_size;
scr_memsetw((u16 *)(c->vc_origin), eattr, delta);
break;
}
originoffset = (u32)(c->vc_origin - sisusb->scrbuf);
if (copyall)
sisusb_copy_memory(sisusb,
(char *)c->vc_origin,
(u32)(sisusb->vrambase + originoffset),
c->vc_screenbuf_size);
else if (dir == SM_UP)
sisusb_copy_memory(sisusb,
(char *)c->vc_origin + c->vc_screenbuf_size - delta,
(u32)sisusb->vrambase + originoffset +
c->vc_screenbuf_size - delta,
delta);
else
sisusb_copy_memory(sisusb,
(char *)c->vc_origin,
(u32)(sisusb->vrambase + originoffset),
delta);
c->vc_scr_end = c->vc_origin + c->vc_screenbuf_size;
c->vc_visible_origin = c->vc_origin;
sisusbcon_set_start_address(sisusb, c);
c->vc_pos = c->vc_pos - oldorigin + c->vc_origin;
mutex_unlock(&sisusb->lock);
return true;
}
static int
sisusbcon_set_origin(struct vc_data *c)
{
struct sisusb_usb_data *sisusb;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return 0;
if (sisusb_is_inactive(c, sisusb) || sisusb->con_blanked) {
mutex_unlock(&sisusb->lock);
return 0;
}
c->vc_origin = c->vc_visible_origin = sisusb->scrbuf;
sisusbcon_set_start_address(sisusb, c);
sisusb->con_rolled_over = 0;
mutex_unlock(&sisusb->lock);
return 1;
}
static int
sisusbcon_resize(struct vc_data *c, unsigned int newcols, unsigned int newrows,
unsigned int user)
{
struct sisusb_usb_data *sisusb;
int fh;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return -ENODEV;
fh = sisusb->current_font_height;
mutex_unlock(&sisusb->lock);
if (newcols != 80 || c->vc_scan_lines / fh != newrows)
return -EINVAL;
return 0;
}
int
sisusbcon_do_font_op(struct sisusb_usb_data *sisusb, int set, int slot,
u8 *arg, int cmapsz, int ch512, int dorecalc,
struct vc_data *c, int fh, int uplock)
{
int font_select = 0x00, i, err = 0;
u32 offset = 0;
u8 dummy;
if ((slot != 0 && slot != 2) || !fh) {
if (uplock)
mutex_unlock(&sisusb->lock);
return -EINVAL;
}
if (set)
sisusb->font_slot = slot;
if (slot == 0)
ch512 = 0;
else
offset = 4 * cmapsz;
font_select = (slot == 0) ? 0x00 : (ch512 ? 0x0e : 0x0a);
err |= sisusb_setidxreg(sisusb, SISSR, 0x00, 0x01);
err |= sisusb_setidxreg(sisusb, SISSR, 0x02, 0x04);
err |= sisusb_setidxreg(sisusb, SISSR, 0x04, 0x07);
err |= sisusb_setidxreg(sisusb, SISSR, 0x00, 0x03);
if (err)
goto font_op_error;
err |= sisusb_setidxreg(sisusb, SISGR, 0x04, 0x03);
err |= sisusb_setidxreg(sisusb, SISGR, 0x05, 0x00);
err |= sisusb_setidxreg(sisusb, SISGR, 0x06, 0x00);
if (err)
goto font_op_error;
if (arg) {
if (set)
for (i = 0; i < cmapsz; i++) {
err |= sisusb_writeb(sisusb,
sisusb->vrambase + offset + i,
arg[i]);
if (err)
break;
}
else
for (i = 0; i < cmapsz; i++) {
err |= sisusb_readb(sisusb,
sisusb->vrambase + offset + i,
&arg[i]);
if (err)
break;
}
if (ch512) {
if (set)
for (i = 0; i < cmapsz; i++) {
err |= sisusb_writeb(sisusb,
sisusb->vrambase + offset +
(2 * cmapsz) + i,
arg[cmapsz + i]);
if (err)
break;
}
else
for (i = 0; i < cmapsz; i++) {
err |= sisusb_readb(sisusb,
sisusb->vrambase + offset +
(2 * cmapsz) + i,
&arg[cmapsz + i]);
if (err)
break;
}
}
}
if (err)
goto font_op_error;
err |= sisusb_setidxreg(sisusb, SISSR, 0x00, 0x01);
err |= sisusb_setidxreg(sisusb, SISSR, 0x02, 0x03);
err |= sisusb_setidxreg(sisusb, SISSR, 0x04, 0x03);
if (set)
sisusb_setidxreg(sisusb, SISSR, 0x03, font_select);
err |= sisusb_setidxreg(sisusb, SISSR, 0x00, 0x03);
if (err)
goto font_op_error;
err |= sisusb_setidxreg(sisusb, SISGR, 0x04, 0x00);
err |= sisusb_setidxreg(sisusb, SISGR, 0x05, 0x10);
err |= sisusb_setidxreg(sisusb, SISGR, 0x06, 0x06);
if (err)
goto font_op_error;
if ((set) && (ch512 != sisusb->current_font_512)) {
for (i = 0; i < MAX_NR_CONSOLES; i++) {
struct vc_data *d = vc_cons[i].d;
if (d && d->vc_sw == &sisusb_con)
d->vc_hi_font_mask = ch512 ? 0x0800 : 0;
}
sisusb->current_font_512 = ch512;
sisusb_getreg(sisusb, SISINPSTAT, &dummy);
sisusb_setreg(sisusb, SISAR, 0x12);
sisusb_setreg(sisusb, SISAR, ch512 ? 0x07 : 0x0f);
sisusb_getreg(sisusb, SISINPSTAT, &dummy);
sisusb_setreg(sisusb, SISAR, 0x20);
sisusb_getreg(sisusb, SISINPSTAT, &dummy);
}
if (dorecalc) {
unsigned char ovr, vde, fsr;
int rows = 0, maxscan = 0;
if (c) {
rows = c->vc_scan_lines / fh;
maxscan = rows * fh - 1;
sisusb_getidxreg(sisusb, SISCR, 0x07, &ovr);
vde = maxscan & 0xff;
ovr = (ovr & 0xbd) |
((maxscan & 0x100) >> 7) |
((maxscan & 0x200) >> 3);
sisusb_setidxreg(sisusb, SISCR, 0x07, ovr);
sisusb_setidxreg(sisusb, SISCR, 0x12, vde);
}
sisusb_getidxreg(sisusb, SISCR, 0x09, &fsr);
fsr = (fsr & 0xe0) | (fh - 1);
sisusb_setidxreg(sisusb, SISCR, 0x09, fsr);
sisusb->current_font_height = fh;
sisusb->sisusb_cursor_size_from = -1;
sisusb->sisusb_cursor_size_to = -1;
}
if (uplock)
mutex_unlock(&sisusb->lock);
if (dorecalc && c) {
int rows = c->vc_scan_lines / fh;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
struct vc_data *vc = vc_cons[i].d;
if (vc && vc->vc_sw == &sisusb_con) {
if (con_is_visible(vc)) {
vc->vc_sw->con_cursor(vc, CM_DRAW);
}
vc->vc_font.height = fh;
vc_resize(vc, 0, rows);
}
}
}
return 0;
font_op_error:
if (uplock)
mutex_unlock(&sisusb->lock);
return -EIO;
}
static int
sisusbcon_font_set(struct vc_data *c, struct console_font *font,
unsigned flags)
{
struct sisusb_usb_data *sisusb;
unsigned charcount = font->charcount;
if (font->width != 8 || (charcount != 256 && charcount != 512))
return -EINVAL;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return -ENODEV;
if (sisusb->font_backup) {
if (sisusb->font_backup_size < charcount) {
vfree(sisusb->font_backup);
sisusb->font_backup = NULL;
}
}
if (!sisusb->font_backup)
sisusb->font_backup = vmalloc(charcount * 32);
if (sisusb->font_backup) {
memcpy(sisusb->font_backup, font->data, charcount * 32);
sisusb->font_backup_size = charcount;
sisusb->font_backup_height = font->height;
sisusb->font_backup_512 = (charcount == 512) ? 1 : 0;
}
return sisusbcon_do_font_op(sisusb, 1, 2, font->data,
8192, (charcount == 512),
(!(flags & KD_FONT_FLAG_DONT_RECALC)) ? 1 : 0,
c, font->height, 1);
}
static int
sisusbcon_font_get(struct vc_data *c, struct console_font *font)
{
struct sisusb_usb_data *sisusb;
sisusb = sisusb_get_sisusb_lock_and_check(c->vc_num);
if (!sisusb)
return -ENODEV;
font->width = 8;
font->height = c->vc_font.height;
font->charcount = 256;
if (!font->data) {
mutex_unlock(&sisusb->lock);
return 0;
}
if (!sisusb->font_backup) {
mutex_unlock(&sisusb->lock);
return -ENODEV;
}
memcpy(font->data, sisusb->font_backup, 256 * 32);
mutex_unlock(&sisusb->lock);
return 0;
}
static const char *sisusbdummycon_startup(void)
{
return "SISUSBVGADUMMY";
}
static void sisusbdummycon_init(struct vc_data *vc, int init)
{
vc->vc_can_do_color = 1;
if (init) {
vc->vc_cols = 80;
vc->vc_rows = 25;
} else
vc_resize(vc, 80, 25);
}
static int sisusbdummycon_dummy(void)
{
return 0;
}
int
sisusb_console_init(struct sisusb_usb_data *sisusb, int first, int last)
{
int i, ret;
mutex_lock(&sisusb->lock);
if (sisusb->haveconsole || !sisusb->SiS_Pr) {
mutex_unlock(&sisusb->lock);
return 1;
}
sisusb->con_first = first;
sisusb->con_last = last;
if (first > last ||
first > MAX_NR_CONSOLES ||
last > MAX_NR_CONSOLES) {
mutex_unlock(&sisusb->lock);
return 1;
}
if (!sisusb->gfxinit || first < 1 || last < 1) {
mutex_unlock(&sisusb->lock);
return 0;
}
sisusb->sisusb_cursor_loc = -1;
sisusb->sisusb_cursor_size_from = -1;
sisusb->sisusb_cursor_size_to = -1;
if (sisusb_reset_text_mode(sisusb, 1)) {
mutex_unlock(&sisusb->lock);
dev_err(&sisusb->sisusb_dev->dev, "Failed to set up text mode\n");
return 1;
}
sisusb_initialize(sisusb);
for (i = first - 1; i <= last - 1; i++) {
mysisusbs[i] = sisusb;
}
sisusb->sisusb_num_columns = 80;
sisusb->scrbuf_size = 32 * 1024;
if (!(sisusb->scrbuf = (unsigned long)vmalloc(sisusb->scrbuf_size))) {
mutex_unlock(&sisusb->lock);
dev_err(&sisusb->sisusb_dev->dev, "Failed to allocate screen buffer\n");
return 1;
}
mutex_unlock(&sisusb->lock);
console_lock();
ret = do_take_over_console(&sisusb_con, first - 1, last - 1, 0);
console_unlock();
if (!ret)
sisusb->haveconsole = 1;
else {
for (i = first - 1; i <= last - 1; i++)
mysisusbs[i] = NULL;
}
return ret;
}
void
sisusb_console_exit(struct sisusb_usb_data *sisusb)
{
int i;
if (sisusb->haveconsole) {
for (i = 0; i < MAX_NR_CONSOLES; i++)
if (sisusb->havethisconsole[i]) {
console_lock();
do_take_over_console(&sisusb_dummy_con, i, i, 0);
console_unlock();
}
sisusb->haveconsole = 0;
}
vfree((void *)sisusb->scrbuf);
sisusb->scrbuf = 0;
vfree(sisusb->font_backup);
sisusb->font_backup = NULL;
}
void __init sisusb_init_concode(void)
{
int i;
for (i = 0; i < MAX_NR_CONSOLES; i++)
mysisusbs[i] = NULL;
}
