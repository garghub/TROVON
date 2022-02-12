static unsigned char sel_pos(int n)
{
return inverse_translate(spk_sel_cons,
screen_glyph(spk_sel_cons, n), 0);
}
void speakup_clear_selection(void)
{
sel_start = -1;
}
static int atedge(const int p, int size_row)
{
return !(p % size_row) || !((p + 2) % size_row);
}
static unsigned short limit(const unsigned short v, const unsigned short u)
{
return (v > u) ? u : v;
}
int speakup_set_selection(struct tty_struct *tty)
{
int new_sel_start, new_sel_end;
char *bp, *obp;
int i, ps, pe;
struct vc_data *vc = vc_cons[fg_console].d;
spk_xs = limit(spk_xs, vc->vc_cols - 1);
spk_ys = limit(spk_ys, vc->vc_rows - 1);
spk_xe = limit(spk_xe, vc->vc_cols - 1);
spk_ye = limit(spk_ye, vc->vc_rows - 1);
ps = spk_ys * vc->vc_size_row + (spk_xs << 1);
pe = spk_ye * vc->vc_size_row + (spk_xe << 1);
if (ps > pe) {
int tmp = ps;
ps = pe;
pe = tmp;
}
if (spk_sel_cons != vc_cons[fg_console].d) {
speakup_clear_selection();
spk_sel_cons = vc_cons[fg_console].d;
dev_warn(tty->dev,
"Selection: mark console not the same as cut\n");
return -EINVAL;
}
new_sel_start = ps;
new_sel_end = pe;
if (new_sel_end > new_sel_start &&
!atedge(new_sel_end, vc->vc_size_row) &&
ishardspace(sel_pos(new_sel_end))) {
for (pe = new_sel_end + 2; ; pe += 2)
if (!ishardspace(sel_pos(pe)) ||
atedge(pe, vc->vc_size_row))
break;
if (ishardspace(sel_pos(pe)))
new_sel_end = pe;
}
if ((new_sel_start == sel_start) && (new_sel_end == sel_end))
return 0;
sel_start = new_sel_start;
sel_end = new_sel_end;
bp = kmalloc((sel_end-sel_start)/2+1, GFP_ATOMIC);
if (!bp) {
speakup_clear_selection();
return -ENOMEM;
}
kfree(sel_buffer);
sel_buffer = bp;
obp = bp;
for (i = sel_start; i <= sel_end; i += 2) {
*bp = sel_pos(i);
if (!ishardspace(*bp++))
obp = bp;
if (!((i + 2) % vc->vc_size_row)) {
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
static void __speakup_paste_selection(struct work_struct *work)
{
struct speakup_paste_work *spw =
container_of(work, struct speakup_paste_work, work);
struct tty_struct *tty = xchg(&spw->tty, NULL);
struct vc_data *vc = (struct vc_data *) tty->driver_data;
int pasted = 0, count;
struct tty_ldisc *ld;
DECLARE_WAITQUEUE(wait, current);
ld = tty_ldisc_ref(tty);
if (!ld)
goto tty_unref;
tty_buffer_lock_exclusive(&vc->port);
add_wait_queue(&vc->paste_wait, &wait);
while (sel_buffer && sel_buffer_lth > pasted) {
set_current_state(TASK_INTERRUPTIBLE);
if (test_bit(TTY_THROTTLED, &tty->flags)) {
schedule();
continue;
}
count = sel_buffer_lth - pasted;
count = tty_ldisc_receive_buf(ld, sel_buffer + pasted, NULL,
count);
pasted += count;
}
remove_wait_queue(&vc->paste_wait, &wait);
__set_current_state(TASK_RUNNING);
tty_buffer_unlock_exclusive(&vc->port);
tty_ldisc_deref(ld);
tty_unref:
tty_kref_put(tty);
}
int speakup_paste_selection(struct tty_struct *tty)
{
if (cmpxchg(&speakup_paste_work.tty, NULL, tty) != NULL)
return -EBUSY;
tty_kref_get(tty);
schedule_work_on(WORK_CPU_UNBOUND, &speakup_paste_work.work);
return 0;
}
void speakup_cancel_paste(void)
{
cancel_work_sync(&speakup_paste_work.work);
tty_kref_put(speakup_paste_work.tty);
}
