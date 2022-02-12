static inline void highlight(const int s, const int e)
{
invert_screen(sel_cons, s, e-s+2, 1);
}
static inline void highlight_pointer(const int where)
{
complement_pos(sel_cons, where);
}
static u16
sel_pos(int n)
{
return inverse_translate(sel_cons, screen_glyph(sel_cons, n),
use_unicode);
}
void clear_selection(void)
{
highlight_pointer(-1);
if (sel_start != -1) {
highlight(sel_start, sel_end);
sel_start = -1;
}
}
static inline int inword(const u16 c) {
return c > 0x7f || (( inwordLut[c>>5] >> (c & 0x1F) ) & 1);
}
int sel_loadlut(char __user *p)
{
u32 tmplut[ARRAY_SIZE(inwordLut)];
if (copy_from_user(tmplut, (u32 __user *)(p+4), sizeof(inwordLut)))
return -EFAULT;
memcpy(inwordLut, tmplut, sizeof(inwordLut));
return 0;
}
static inline int atedge(const int p, int size_row)
{
return (!(p % size_row) || !((p + 2) % size_row));
}
static inline unsigned short limit(const unsigned short v, const unsigned short u)
{
return (v > u) ? u : v;
}
static int store_utf8(u16 c, char *p)
{
if (c < 0x80) {
p[0] = c;
return 1;
} else if (c < 0x800) {
p[0] = 0xc0 | (c >> 6);
p[1] = 0x80 | (c & 0x3f);
return 2;
} else {
p[0] = 0xe0 | (c >> 12);
p[1] = 0x80 | ((c >> 6) & 0x3f);
p[2] = 0x80 | (c & 0x3f);
return 3;
}
}
int set_selection(const struct tiocl_selection __user *sel, struct tty_struct *tty)
{
struct vc_data *vc = vc_cons[fg_console].d;
int sel_mode, new_sel_start, new_sel_end, spc;
char *bp, *obp;
int i, ps, pe, multiplier;
u16 c;
int mode;
poke_blanked_console();
{ unsigned short xs, ys, xe, ye;
if (!access_ok(VERIFY_READ, sel, sizeof(*sel)))
return -EFAULT;
__get_user(xs, &sel->xs);
__get_user(ys, &sel->ys);
__get_user(xe, &sel->xe);
__get_user(ye, &sel->ye);
__get_user(sel_mode, &sel->sel_mode);
xs--; ys--; xe--; ye--;
xs = limit(xs, vc->vc_cols - 1);
ys = limit(ys, vc->vc_rows - 1);
xe = limit(xe, vc->vc_cols - 1);
ye = limit(ye, vc->vc_rows - 1);
ps = ys * vc->vc_size_row + (xs << 1);
pe = ye * vc->vc_size_row + (xe << 1);
if (sel_mode == TIOCL_SELCLEAR) {
clear_selection();
return 0;
}
if (mouse_reporting() && (sel_mode & TIOCL_SELMOUSEREPORT)) {
mouse_report(tty, sel_mode & TIOCL_SELBUTTONMASK, xs, ys);
return 0;
}
}
if (ps > pe)
{
int tmp = ps;
ps = pe;
pe = tmp;
}
if (sel_cons != vc_cons[fg_console].d) {
clear_selection();
sel_cons = vc_cons[fg_console].d;
}
mode = vt_do_kdgkbmode(fg_console);
if (mode == K_UNICODE)
use_unicode = 1;
else
use_unicode = 0;
switch (sel_mode)
{
case TIOCL_SELCHAR:
new_sel_start = ps;
new_sel_end = pe;
break;
case TIOCL_SELWORD:
spc = isspace(sel_pos(ps));
for (new_sel_start = ps; ; ps -= 2)
{
if ((spc && !isspace(sel_pos(ps))) ||
(!spc && !inword(sel_pos(ps))))
break;
new_sel_start = ps;
if (!(ps % vc->vc_size_row))
break;
}
spc = isspace(sel_pos(pe));
for (new_sel_end = pe; ; pe += 2)
{
if ((spc && !isspace(sel_pos(pe))) ||
(!spc && !inword(sel_pos(pe))))
break;
new_sel_end = pe;
if (!((pe + 2) % vc->vc_size_row))
break;
}
break;
case TIOCL_SELLINE:
new_sel_start = ps - ps % vc->vc_size_row;
new_sel_end = pe + vc->vc_size_row
- pe % vc->vc_size_row - 2;
break;
case TIOCL_SELPOINTER:
highlight_pointer(pe);
return 0;
default:
return -EINVAL;
}
highlight_pointer(-1);
if (new_sel_end > new_sel_start &&
!atedge(new_sel_end, vc->vc_size_row) &&
isspace(sel_pos(new_sel_end))) {
for (pe = new_sel_end + 2; ; pe += 2)
if (!isspace(sel_pos(pe)) ||
atedge(pe, vc->vc_size_row))
break;
if (isspace(sel_pos(pe)))
new_sel_end = pe;
}
if (sel_start == -1)
highlight(new_sel_start, new_sel_end);
else if (new_sel_start == sel_start)
{
if (new_sel_end == sel_end)
return 0;
else if (new_sel_end > sel_end)
highlight(sel_end + 2, new_sel_end);
else
highlight(new_sel_end + 2, sel_end);
}
else if (new_sel_end == sel_end)
{
if (new_sel_start < sel_start)
highlight(new_sel_start, sel_start - 2);
else
highlight(sel_start, new_sel_start - 2);
}
else
{
clear_selection();
highlight(new_sel_start, new_sel_end);
}
sel_start = new_sel_start;
sel_end = new_sel_end;
multiplier = use_unicode ? 3 : 1;
bp = kmalloc(((sel_end-sel_start)/2+1)*multiplier, GFP_KERNEL);
if (!bp) {
printk(KERN_WARNING "selection: kmalloc() failed\n");
clear_selection();
return -ENOMEM;
}
kfree(sel_buffer);
sel_buffer = bp;
obp = bp;
for (i = sel_start; i <= sel_end; i += 2) {
c = sel_pos(i);
if (use_unicode)
bp += store_utf8(c, bp);
else
*bp++ = c;
if (!isspace(c))
obp = bp;
if (! ((i + 2) % vc->vc_size_row)) {
if (obp != bp) {
bp = obp;
*bp++ = '\r';
}
obp = bp;
}
}
sel_buffer_lth = bp - sel_buffer;
return 0;
}
int paste_selection(struct tty_struct *tty)
{
struct vc_data *vc = tty->driver_data;
int pasted = 0;
unsigned int count;
struct tty_ldisc *ld;
DECLARE_WAITQUEUE(wait, current);
console_lock();
poke_blanked_console();
console_unlock();
ld = tty_ldisc_ref_wait(tty);
if (!ld)
return -EIO;
tty_buffer_lock_exclusive(&vc->port);
add_wait_queue(&vc->paste_wait, &wait);
while (sel_buffer && sel_buffer_lth > pasted) {
set_current_state(TASK_INTERRUPTIBLE);
if (tty_throttled(tty)) {
schedule();
continue;
}
__set_current_state(TASK_RUNNING);
count = sel_buffer_lth - pasted;
count = tty_ldisc_receive_buf(ld, sel_buffer + pasted, NULL,
count);
pasted += count;
}
remove_wait_queue(&vc->paste_wait, &wait);
__set_current_state(TASK_RUNNING);
tty_buffer_unlock_exclusive(&vc->port);
tty_ldisc_deref(ld);
return 0;
}
