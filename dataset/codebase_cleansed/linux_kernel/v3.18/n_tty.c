static inline size_t read_cnt(struct n_tty_data *ldata)
{
return ldata->read_head - ldata->read_tail;
}
static inline unsigned char read_buf(struct n_tty_data *ldata, size_t i)
{
return ldata->read_buf[i & (N_TTY_BUF_SIZE - 1)];
}
static inline unsigned char *read_buf_addr(struct n_tty_data *ldata, size_t i)
{
return &ldata->read_buf[i & (N_TTY_BUF_SIZE - 1)];
}
static inline unsigned char echo_buf(struct n_tty_data *ldata, size_t i)
{
return ldata->echo_buf[i & (N_TTY_BUF_SIZE - 1)];
}
static inline unsigned char *echo_buf_addr(struct n_tty_data *ldata, size_t i)
{
return &ldata->echo_buf[i & (N_TTY_BUF_SIZE - 1)];
}
static inline int tty_put_user(struct tty_struct *tty, unsigned char x,
unsigned char __user *ptr)
{
struct n_tty_data *ldata = tty->disc_data;
tty_audit_add_data(tty, &x, 1, ldata->icanon);
return put_user(x, ptr);
}
static int receive_room(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
int left;
if (I_PARMRK(tty)) {
left = N_TTY_BUF_SIZE - read_cnt(ldata) * 3 - 1;
} else
left = N_TTY_BUF_SIZE - read_cnt(ldata) - 1;
if (left <= 0)
left = ldata->icanon && ldata->canon_head == ldata->read_tail;
return left;
}
static void n_tty_set_room(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
if (unlikely(ldata->no_room) && receive_room(tty)) {
ldata->no_room = 0;
WARN_RATELIMIT(tty->port->itty == NULL,
"scheduling with invalid itty\n");
WARN_RATELIMIT(test_bit(TTY_LDISC_HALTED, &tty->flags),
"scheduling buffer work for halted ldisc\n");
queue_work(system_unbound_wq, &tty->port->buf.work);
}
}
static ssize_t chars_in_buffer(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
ssize_t n = 0;
if (!ldata->icanon)
n = read_cnt(ldata);
else
n = ldata->canon_head - ldata->read_tail;
return n;
}
static void n_tty_write_wakeup(struct tty_struct *tty)
{
if (tty->fasync && test_and_clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags))
kill_fasync(&tty->fasync, SIGIO, POLL_OUT);
}
static void n_tty_check_throttle(struct tty_struct *tty)
{
if (tty->driver->type == TTY_DRIVER_TYPE_PTY)
return;
while (1) {
int throttled;
tty_set_flow_change(tty, TTY_THROTTLE_SAFE);
if (receive_room(tty) >= TTY_THRESHOLD_THROTTLE)
break;
throttled = tty_throttle_safe(tty);
if (!throttled)
break;
}
__tty_set_flow_change(tty, 0);
}
static void n_tty_check_unthrottle(struct tty_struct *tty)
{
if (tty->driver->type == TTY_DRIVER_TYPE_PTY &&
tty->link->ldisc->ops->write_wakeup == n_tty_write_wakeup) {
if (chars_in_buffer(tty) > TTY_THRESHOLD_UNTHROTTLE)
return;
if (!tty->count)
return;
n_tty_set_room(tty);
n_tty_write_wakeup(tty->link);
if (waitqueue_active(&tty->link->write_wait))
wake_up_interruptible_poll(&tty->link->write_wait, POLLOUT);
return;
}
while (1) {
int unthrottled;
tty_set_flow_change(tty, TTY_UNTHROTTLE_SAFE);
if (chars_in_buffer(tty) > TTY_THRESHOLD_UNTHROTTLE)
break;
if (!tty->count)
break;
n_tty_set_room(tty);
unthrottled = tty_unthrottle_safe(tty);
if (!unthrottled)
break;
}
__tty_set_flow_change(tty, 0);
}
static inline void put_tty_queue(unsigned char c, struct n_tty_data *ldata)
{
*read_buf_addr(ldata, ldata->read_head++) = c;
}
static void reset_buffer_flags(struct n_tty_data *ldata)
{
ldata->read_head = ldata->canon_head = ldata->read_tail = 0;
ldata->echo_head = ldata->echo_tail = ldata->echo_commit = 0;
ldata->echo_mark = 0;
ldata->line_start = 0;
ldata->erasing = 0;
bitmap_zero(ldata->read_flags, N_TTY_BUF_SIZE);
ldata->push = 0;
}
static void n_tty_packet_mode_flush(struct tty_struct *tty)
{
unsigned long flags;
spin_lock_irqsave(&tty->ctrl_lock, flags);
if (tty->link->packet) {
tty->ctrl_status |= TIOCPKT_FLUSHREAD;
if (waitqueue_active(&tty->link->read_wait))
wake_up_interruptible(&tty->link->read_wait);
}
spin_unlock_irqrestore(&tty->ctrl_lock, flags);
}
static void n_tty_flush_buffer(struct tty_struct *tty)
{
down_write(&tty->termios_rwsem);
reset_buffer_flags(tty->disc_data);
n_tty_set_room(tty);
if (tty->link)
n_tty_packet_mode_flush(tty);
up_write(&tty->termios_rwsem);
}
static ssize_t n_tty_chars_in_buffer(struct tty_struct *tty)
{
ssize_t n;
WARN_ONCE(1, "%s is deprecated and scheduled for removal.", __func__);
down_write(&tty->termios_rwsem);
n = chars_in_buffer(tty);
up_write(&tty->termios_rwsem);
return n;
}
static inline int is_utf8_continuation(unsigned char c)
{
return (c & 0xc0) == 0x80;
}
static inline int is_continuation(unsigned char c, struct tty_struct *tty)
{
return I_IUTF8(tty) && is_utf8_continuation(c);
}
static int do_output_char(unsigned char c, struct tty_struct *tty, int space)
{
struct n_tty_data *ldata = tty->disc_data;
int spaces;
if (!space)
return -1;
switch (c) {
case '\n':
if (O_ONLRET(tty))
ldata->column = 0;
if (O_ONLCR(tty)) {
if (space < 2)
return -1;
ldata->canon_column = ldata->column = 0;
tty->ops->write(tty, "\r\n", 2);
return 2;
}
ldata->canon_column = ldata->column;
break;
case '\r':
if (O_ONOCR(tty) && ldata->column == 0)
return 0;
if (O_OCRNL(tty)) {
c = '\n';
if (O_ONLRET(tty))
ldata->canon_column = ldata->column = 0;
break;
}
ldata->canon_column = ldata->column = 0;
break;
case '\t':
spaces = 8 - (ldata->column & 7);
if (O_TABDLY(tty) == XTABS) {
if (space < spaces)
return -1;
ldata->column += spaces;
tty->ops->write(tty, " ", spaces);
return spaces;
}
ldata->column += spaces;
break;
case '\b':
if (ldata->column > 0)
ldata->column--;
break;
default:
if (!iscntrl(c)) {
if (O_OLCUC(tty))
c = toupper(c);
if (!is_continuation(c, tty))
ldata->column++;
}
break;
}
tty_put_char(tty, c);
return 1;
}
static int process_output(unsigned char c, struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
int space, retval;
mutex_lock(&ldata->output_lock);
space = tty_write_room(tty);
retval = do_output_char(c, tty, space);
mutex_unlock(&ldata->output_lock);
if (retval < 0)
return -1;
else
return 0;
}
static ssize_t process_output_block(struct tty_struct *tty,
const unsigned char *buf, unsigned int nr)
{
struct n_tty_data *ldata = tty->disc_data;
int space;
int i;
const unsigned char *cp;
mutex_lock(&ldata->output_lock);
space = tty_write_room(tty);
if (!space) {
mutex_unlock(&ldata->output_lock);
return 0;
}
if (nr > space)
nr = space;
for (i = 0, cp = buf; i < nr; i++, cp++) {
unsigned char c = *cp;
switch (c) {
case '\n':
if (O_ONLRET(tty))
ldata->column = 0;
if (O_ONLCR(tty))
goto break_out;
ldata->canon_column = ldata->column;
break;
case '\r':
if (O_ONOCR(tty) && ldata->column == 0)
goto break_out;
if (O_OCRNL(tty))
goto break_out;
ldata->canon_column = ldata->column = 0;
break;
case '\t':
goto break_out;
case '\b':
if (ldata->column > 0)
ldata->column--;
break;
default:
if (!iscntrl(c)) {
if (O_OLCUC(tty))
goto break_out;
if (!is_continuation(c, tty))
ldata->column++;
}
break;
}
}
break_out:
i = tty->ops->write(tty, buf, i);
mutex_unlock(&ldata->output_lock);
return i;
}
static size_t __process_echoes(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
int space, old_space;
size_t tail;
unsigned char c;
old_space = space = tty_write_room(tty);
tail = ldata->echo_tail;
while (ldata->echo_commit != tail) {
c = echo_buf(ldata, tail);
if (c == ECHO_OP_START) {
unsigned char op;
int no_space_left = 0;
op = echo_buf(ldata, tail + 1);
switch (op) {
unsigned int num_chars, num_bs;
case ECHO_OP_ERASE_TAB:
num_chars = echo_buf(ldata, tail + 2);
if (!(num_chars & 0x80))
num_chars += ldata->canon_column;
num_bs = 8 - (num_chars & 7);
if (num_bs > space) {
no_space_left = 1;
break;
}
space -= num_bs;
while (num_bs--) {
tty_put_char(tty, '\b');
if (ldata->column > 0)
ldata->column--;
}
tail += 3;
break;
case ECHO_OP_SET_CANON_COL:
ldata->canon_column = ldata->column;
tail += 2;
break;
case ECHO_OP_MOVE_BACK_COL:
if (ldata->column > 0)
ldata->column--;
tail += 2;
break;
case ECHO_OP_START:
if (!space) {
no_space_left = 1;
break;
}
tty_put_char(tty, ECHO_OP_START);
ldata->column++;
space--;
tail += 2;
break;
default:
if (space < 2) {
no_space_left = 1;
break;
}
tty_put_char(tty, '^');
tty_put_char(tty, op ^ 0100);
ldata->column += 2;
space -= 2;
tail += 2;
}
if (no_space_left)
break;
} else {
if (O_OPOST(tty)) {
int retval = do_output_char(c, tty, space);
if (retval < 0)
break;
space -= retval;
} else {
if (!space)
break;
tty_put_char(tty, c);
space -= 1;
}
tail += 1;
}
}
while (ldata->echo_commit - tail >= ECHO_DISCARD_WATERMARK) {
if (echo_buf(ldata, tail) == ECHO_OP_START) {
if (echo_buf(ldata, tail + 1) == ECHO_OP_ERASE_TAB)
tail += 3;
else
tail += 2;
} else
tail++;
}
ldata->echo_tail = tail;
return old_space - space;
}
static void commit_echoes(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
size_t nr, old, echoed;
size_t head;
head = ldata->echo_head;
ldata->echo_mark = head;
old = ldata->echo_commit - ldata->echo_tail;
nr = head - ldata->echo_tail;
if (nr < ECHO_COMMIT_WATERMARK || (nr % ECHO_BLOCK > old % ECHO_BLOCK))
return;
mutex_lock(&ldata->output_lock);
ldata->echo_commit = head;
echoed = __process_echoes(tty);
mutex_unlock(&ldata->output_lock);
if (echoed && tty->ops->flush_chars)
tty->ops->flush_chars(tty);
}
static void process_echoes(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
size_t echoed;
if (ldata->echo_mark == ldata->echo_tail)
return;
mutex_lock(&ldata->output_lock);
ldata->echo_commit = ldata->echo_mark;
echoed = __process_echoes(tty);
mutex_unlock(&ldata->output_lock);
if (echoed && tty->ops->flush_chars)
tty->ops->flush_chars(tty);
}
static void flush_echoes(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
if ((!L_ECHO(tty) && !L_ECHONL(tty)) ||
ldata->echo_commit == ldata->echo_head)
return;
mutex_lock(&ldata->output_lock);
ldata->echo_commit = ldata->echo_head;
__process_echoes(tty);
mutex_unlock(&ldata->output_lock);
}
static inline void add_echo_byte(unsigned char c, struct n_tty_data *ldata)
{
*echo_buf_addr(ldata, ldata->echo_head++) = c;
}
static void echo_move_back_col(struct n_tty_data *ldata)
{
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_MOVE_BACK_COL, ldata);
}
static void echo_set_canon_col(struct n_tty_data *ldata)
{
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_SET_CANON_COL, ldata);
}
static void echo_erase_tab(unsigned int num_chars, int after_tab,
struct n_tty_data *ldata)
{
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_ERASE_TAB, ldata);
num_chars &= 7;
if (after_tab)
num_chars |= 0x80;
add_echo_byte(num_chars, ldata);
}
static void echo_char_raw(unsigned char c, struct n_tty_data *ldata)
{
if (c == ECHO_OP_START) {
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_START, ldata);
} else {
add_echo_byte(c, ldata);
}
}
static void echo_char(unsigned char c, struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
if (c == ECHO_OP_START) {
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_START, ldata);
} else {
if (L_ECHOCTL(tty) && iscntrl(c) && c != '\t')
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(c, ldata);
}
}
static inline void finish_erasing(struct n_tty_data *ldata)
{
if (ldata->erasing) {
echo_char_raw('/', ldata);
ldata->erasing = 0;
}
}
static void eraser(unsigned char c, struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
enum { ERASE, WERASE, KILL } kill_type;
size_t head;
size_t cnt;
int seen_alnums;
if (ldata->read_head == ldata->canon_head) {
return;
}
if (c == ERASE_CHAR(tty))
kill_type = ERASE;
else if (c == WERASE_CHAR(tty))
kill_type = WERASE;
else {
if (!L_ECHO(tty)) {
ldata->read_head = ldata->canon_head;
return;
}
if (!L_ECHOK(tty) || !L_ECHOKE(tty) || !L_ECHOE(tty)) {
ldata->read_head = ldata->canon_head;
finish_erasing(ldata);
echo_char(KILL_CHAR(tty), tty);
if (L_ECHOK(tty))
echo_char_raw('\n', ldata);
return;
}
kill_type = KILL;
}
seen_alnums = 0;
while (ldata->read_head != ldata->canon_head) {
head = ldata->read_head;
do {
head--;
c = read_buf(ldata, head);
} while (is_continuation(c, tty) && head != ldata->canon_head);
if (is_continuation(c, tty))
break;
if (kill_type == WERASE) {
if (isalnum(c) || c == '_')
seen_alnums++;
else if (seen_alnums)
break;
}
cnt = ldata->read_head - head;
ldata->read_head = head;
if (L_ECHO(tty)) {
if (L_ECHOPRT(tty)) {
if (!ldata->erasing) {
echo_char_raw('\\', ldata);
ldata->erasing = 1;
}
echo_char(c, tty);
while (--cnt > 0) {
head++;
echo_char_raw(read_buf(ldata, head), ldata);
echo_move_back_col(ldata);
}
} else if (kill_type == ERASE && !L_ECHOE(tty)) {
echo_char(ERASE_CHAR(tty), tty);
} else if (c == '\t') {
unsigned int num_chars = 0;
int after_tab = 0;
size_t tail = ldata->read_head;
while (tail != ldata->canon_head) {
tail--;
c = read_buf(ldata, tail);
if (c == '\t') {
after_tab = 1;
break;
} else if (iscntrl(c)) {
if (L_ECHOCTL(tty))
num_chars += 2;
} else if (!is_continuation(c, tty)) {
num_chars++;
}
}
echo_erase_tab(num_chars, after_tab, ldata);
} else {
if (iscntrl(c) && L_ECHOCTL(tty)) {
echo_char_raw('\b', ldata);
echo_char_raw(' ', ldata);
echo_char_raw('\b', ldata);
}
if (!iscntrl(c) || L_ECHOCTL(tty)) {
echo_char_raw('\b', ldata);
echo_char_raw(' ', ldata);
echo_char_raw('\b', ldata);
}
}
}
if (kill_type == ERASE)
break;
}
if (ldata->read_head == ldata->canon_head && L_ECHO(tty))
finish_erasing(ldata);
}
static void isig(int sig, struct tty_struct *tty)
{
struct pid *tty_pgrp = tty_get_pgrp(tty);
if (tty_pgrp) {
kill_pgrp(tty_pgrp, sig, 1);
put_pid(tty_pgrp);
}
}
static void n_tty_receive_break(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
if (I_IGNBRK(tty))
return;
if (I_BRKINT(tty)) {
isig(SIGINT, tty);
if (!L_NOFLSH(tty)) {
up_read(&tty->termios_rwsem);
n_tty_flush_buffer(tty);
tty_driver_flush_buffer(tty);
down_read(&tty->termios_rwsem);
}
return;
}
if (I_PARMRK(tty)) {
put_tty_queue('\377', ldata);
put_tty_queue('\0', ldata);
}
put_tty_queue('\0', ldata);
if (waitqueue_active(&tty->read_wait))
wake_up_interruptible_poll(&tty->read_wait, POLLIN);
}
static void n_tty_receive_overrun(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
char buf[64];
ldata->num_overrun++;
if (time_after(jiffies, ldata->overrun_time + HZ) ||
time_after(ldata->overrun_time, jiffies)) {
printk(KERN_WARNING "%s: %d input overrun(s)\n",
tty_name(tty, buf),
ldata->num_overrun);
ldata->overrun_time = jiffies;
ldata->num_overrun = 0;
}
}
static void n_tty_receive_parity_error(struct tty_struct *tty, unsigned char c)
{
struct n_tty_data *ldata = tty->disc_data;
if (I_INPCK(tty)) {
if (I_IGNPAR(tty))
return;
if (I_PARMRK(tty)) {
put_tty_queue('\377', ldata);
put_tty_queue('\0', ldata);
put_tty_queue(c, ldata);
} else
put_tty_queue('\0', ldata);
} else
put_tty_queue(c, ldata);
if (waitqueue_active(&tty->read_wait))
wake_up_interruptible_poll(&tty->read_wait, POLLIN);
}
static void
n_tty_receive_signal_char(struct tty_struct *tty, int signal, unsigned char c)
{
if (!L_NOFLSH(tty)) {
up_read(&tty->termios_rwsem);
n_tty_flush_buffer(tty);
tty_driver_flush_buffer(tty);
down_read(&tty->termios_rwsem);
}
if (I_IXON(tty))
start_tty(tty);
if (L_ECHO(tty)) {
echo_char(c, tty);
commit_echoes(tty);
} else
process_echoes(tty);
isig(signal, tty);
return;
}
static int
n_tty_receive_char_special(struct tty_struct *tty, unsigned char c)
{
struct n_tty_data *ldata = tty->disc_data;
if (I_IXON(tty)) {
if (c == START_CHAR(tty)) {
start_tty(tty);
process_echoes(tty);
return 0;
}
if (c == STOP_CHAR(tty)) {
stop_tty(tty);
return 0;
}
}
if (L_ISIG(tty)) {
if (c == INTR_CHAR(tty)) {
n_tty_receive_signal_char(tty, SIGINT, c);
return 0;
} else if (c == QUIT_CHAR(tty)) {
n_tty_receive_signal_char(tty, SIGQUIT, c);
return 0;
} else if (c == SUSP_CHAR(tty)) {
n_tty_receive_signal_char(tty, SIGTSTP, c);
return 0;
}
}
if (tty->stopped && !tty->flow_stopped && I_IXON(tty) && I_IXANY(tty)) {
start_tty(tty);
process_echoes(tty);
}
if (c == '\r') {
if (I_IGNCR(tty))
return 0;
if (I_ICRNL(tty))
c = '\n';
} else if (c == '\n' && I_INLCR(tty))
c = '\r';
if (ldata->icanon) {
if (c == ERASE_CHAR(tty) || c == KILL_CHAR(tty) ||
(c == WERASE_CHAR(tty) && L_IEXTEN(tty))) {
eraser(c, tty);
commit_echoes(tty);
return 0;
}
if (c == LNEXT_CHAR(tty) && L_IEXTEN(tty)) {
ldata->lnext = 1;
if (L_ECHO(tty)) {
finish_erasing(ldata);
if (L_ECHOCTL(tty)) {
echo_char_raw('^', ldata);
echo_char_raw('\b', ldata);
commit_echoes(tty);
}
}
return 1;
}
if (c == REPRINT_CHAR(tty) && L_ECHO(tty) && L_IEXTEN(tty)) {
size_t tail = ldata->canon_head;
finish_erasing(ldata);
echo_char(c, tty);
echo_char_raw('\n', ldata);
while (tail != ldata->read_head) {
echo_char(read_buf(ldata, tail), tty);
tail++;
}
commit_echoes(tty);
return 0;
}
if (c == '\n') {
if (L_ECHO(tty) || L_ECHONL(tty)) {
echo_char_raw('\n', ldata);
commit_echoes(tty);
}
goto handle_newline;
}
if (c == EOF_CHAR(tty)) {
c = __DISABLED_CHAR;
goto handle_newline;
}
if ((c == EOL_CHAR(tty)) ||
(c == EOL2_CHAR(tty) && L_IEXTEN(tty))) {
if (L_ECHO(tty)) {
if (ldata->canon_head == ldata->read_head)
echo_set_canon_col(ldata);
echo_char(c, tty);
commit_echoes(tty);
}
if (c == (unsigned char) '\377' && I_PARMRK(tty))
put_tty_queue(c, ldata);
handle_newline:
set_bit(ldata->read_head & (N_TTY_BUF_SIZE - 1), ldata->read_flags);
put_tty_queue(c, ldata);
ldata->canon_head = ldata->read_head;
kill_fasync(&tty->fasync, SIGIO, POLL_IN);
if (waitqueue_active(&tty->read_wait))
wake_up_interruptible_poll(&tty->read_wait, POLLIN);
return 0;
}
}
if (L_ECHO(tty)) {
finish_erasing(ldata);
if (c == '\n')
echo_char_raw('\n', ldata);
else {
if (ldata->canon_head == ldata->read_head)
echo_set_canon_col(ldata);
echo_char(c, tty);
}
commit_echoes(tty);
}
if (c == (unsigned char) '\377' && I_PARMRK(tty))
put_tty_queue(c, ldata);
put_tty_queue(c, ldata);
return 0;
}
static inline void
n_tty_receive_char_inline(struct tty_struct *tty, unsigned char c)
{
struct n_tty_data *ldata = tty->disc_data;
if (tty->stopped && !tty->flow_stopped && I_IXON(tty) && I_IXANY(tty)) {
start_tty(tty);
process_echoes(tty);
}
if (L_ECHO(tty)) {
finish_erasing(ldata);
if (ldata->canon_head == ldata->read_head)
echo_set_canon_col(ldata);
echo_char(c, tty);
commit_echoes(tty);
}
if (c == (unsigned char) '\377' && I_PARMRK(tty))
put_tty_queue(c, ldata);
put_tty_queue(c, ldata);
}
static void n_tty_receive_char(struct tty_struct *tty, unsigned char c)
{
n_tty_receive_char_inline(tty, c);
}
static inline void
n_tty_receive_char_fast(struct tty_struct *tty, unsigned char c)
{
struct n_tty_data *ldata = tty->disc_data;
if (tty->stopped && !tty->flow_stopped && I_IXON(tty) && I_IXANY(tty)) {
start_tty(tty);
process_echoes(tty);
}
if (L_ECHO(tty)) {
finish_erasing(ldata);
if (ldata->canon_head == ldata->read_head)
echo_set_canon_col(ldata);
echo_char(c, tty);
commit_echoes(tty);
}
put_tty_queue(c, ldata);
}
static void n_tty_receive_char_closing(struct tty_struct *tty, unsigned char c)
{
if (I_ISTRIP(tty))
c &= 0x7f;
if (I_IUCLC(tty) && L_IEXTEN(tty))
c = tolower(c);
if (I_IXON(tty)) {
if (c == STOP_CHAR(tty))
stop_tty(tty);
else if (c == START_CHAR(tty) ||
(tty->stopped && !tty->flow_stopped && I_IXANY(tty) &&
c != INTR_CHAR(tty) && c != QUIT_CHAR(tty) &&
c != SUSP_CHAR(tty))) {
start_tty(tty);
process_echoes(tty);
}
}
}
static void
n_tty_receive_char_flagged(struct tty_struct *tty, unsigned char c, char flag)
{
char buf[64];
switch (flag) {
case TTY_BREAK:
n_tty_receive_break(tty);
break;
case TTY_PARITY:
case TTY_FRAME:
n_tty_receive_parity_error(tty, c);
break;
case TTY_OVERRUN:
n_tty_receive_overrun(tty);
break;
default:
printk(KERN_ERR "%s: unknown flag %d\n",
tty_name(tty, buf), flag);
break;
}
}
static void
n_tty_receive_char_lnext(struct tty_struct *tty, unsigned char c, char flag)
{
struct n_tty_data *ldata = tty->disc_data;
ldata->lnext = 0;
if (likely(flag == TTY_NORMAL)) {
if (I_ISTRIP(tty))
c &= 0x7f;
if (I_IUCLC(tty) && L_IEXTEN(tty))
c = tolower(c);
n_tty_receive_char(tty, c);
} else
n_tty_receive_char_flagged(tty, c, flag);
}
static void
n_tty_receive_buf_real_raw(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
struct n_tty_data *ldata = tty->disc_data;
size_t n, head;
head = ldata->read_head & (N_TTY_BUF_SIZE - 1);
n = N_TTY_BUF_SIZE - max(read_cnt(ldata), head);
n = min_t(size_t, count, n);
memcpy(read_buf_addr(ldata, head), cp, n);
ldata->read_head += n;
cp += n;
count -= n;
head = ldata->read_head & (N_TTY_BUF_SIZE - 1);
n = N_TTY_BUF_SIZE - max(read_cnt(ldata), head);
n = min_t(size_t, count, n);
memcpy(read_buf_addr(ldata, head), cp, n);
ldata->read_head += n;
}
static void
n_tty_receive_buf_raw(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
struct n_tty_data *ldata = tty->disc_data;
char flag = TTY_NORMAL;
while (count--) {
if (fp)
flag = *fp++;
if (likely(flag == TTY_NORMAL))
put_tty_queue(*cp++, ldata);
else
n_tty_receive_char_flagged(tty, *cp++, flag);
}
}
static void
n_tty_receive_buf_closing(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
char flag = TTY_NORMAL;
while (count--) {
if (fp)
flag = *fp++;
if (likely(flag == TTY_NORMAL))
n_tty_receive_char_closing(tty, *cp++);
else
n_tty_receive_char_flagged(tty, *cp++, flag);
}
}
static void
n_tty_receive_buf_standard(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
struct n_tty_data *ldata = tty->disc_data;
char flag = TTY_NORMAL;
while (count--) {
if (fp)
flag = *fp++;
if (likely(flag == TTY_NORMAL)) {
unsigned char c = *cp++;
if (I_ISTRIP(tty))
c &= 0x7f;
if (I_IUCLC(tty) && L_IEXTEN(tty))
c = tolower(c);
if (L_EXTPROC(tty)) {
put_tty_queue(c, ldata);
continue;
}
if (!test_bit(c, ldata->char_map))
n_tty_receive_char_inline(tty, c);
else if (n_tty_receive_char_special(tty, c) && count) {
if (fp)
flag = *fp++;
n_tty_receive_char_lnext(tty, *cp++, flag);
count--;
}
} else
n_tty_receive_char_flagged(tty, *cp++, flag);
}
}
static void
n_tty_receive_buf_fast(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
struct n_tty_data *ldata = tty->disc_data;
char flag = TTY_NORMAL;
while (count--) {
if (fp)
flag = *fp++;
if (likely(flag == TTY_NORMAL)) {
unsigned char c = *cp++;
if (!test_bit(c, ldata->char_map))
n_tty_receive_char_fast(tty, c);
else if (n_tty_receive_char_special(tty, c) && count) {
if (fp)
flag = *fp++;
n_tty_receive_char_lnext(tty, *cp++, flag);
count--;
}
} else
n_tty_receive_char_flagged(tty, *cp++, flag);
}
}
static void __receive_buf(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
struct n_tty_data *ldata = tty->disc_data;
bool preops = I_ISTRIP(tty) || (I_IUCLC(tty) && L_IEXTEN(tty));
if (ldata->real_raw)
n_tty_receive_buf_real_raw(tty, cp, fp, count);
else if (ldata->raw || (L_EXTPROC(tty) && !preops))
n_tty_receive_buf_raw(tty, cp, fp, count);
else if (tty->closing && !L_EXTPROC(tty))
n_tty_receive_buf_closing(tty, cp, fp, count);
else {
if (ldata->lnext) {
char flag = TTY_NORMAL;
if (fp)
flag = *fp++;
n_tty_receive_char_lnext(tty, *cp++, flag);
count--;
}
if (!preops && !I_PARMRK(tty))
n_tty_receive_buf_fast(tty, cp, fp, count);
else
n_tty_receive_buf_standard(tty, cp, fp, count);
flush_echoes(tty);
if (tty->ops->flush_chars)
tty->ops->flush_chars(tty);
}
if ((!ldata->icanon && (read_cnt(ldata) >= ldata->minimum_to_wake)) ||
L_EXTPROC(tty)) {
kill_fasync(&tty->fasync, SIGIO, POLL_IN);
if (waitqueue_active(&tty->read_wait))
wake_up_interruptible_poll(&tty->read_wait, POLLIN);
}
}
static int
n_tty_receive_buf_common(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count, int flow)
{
struct n_tty_data *ldata = tty->disc_data;
int room, n, rcvd = 0;
down_read(&tty->termios_rwsem);
while (1) {
room = receive_room(tty);
n = min(count, room);
if (!n) {
if (flow && !room)
ldata->no_room = 1;
break;
}
__receive_buf(tty, cp, fp, n);
cp += n;
if (fp)
fp += n;
count -= n;
rcvd += n;
}
tty->receive_room = room;
n_tty_check_throttle(tty);
up_read(&tty->termios_rwsem);
return rcvd;
}
static void n_tty_receive_buf(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
n_tty_receive_buf_common(tty, cp, fp, count, 0);
}
static int n_tty_receive_buf2(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
return n_tty_receive_buf_common(tty, cp, fp, count, 1);
}
int is_ignored(int sig)
{
return (sigismember(&current->blocked, sig) ||
current->sighand->action[sig-1].sa.sa_handler == SIG_IGN);
}
static void n_tty_set_termios(struct tty_struct *tty, struct ktermios *old)
{
struct n_tty_data *ldata = tty->disc_data;
if (!old || (old->c_lflag ^ tty->termios.c_lflag) & ICANON) {
bitmap_zero(ldata->read_flags, N_TTY_BUF_SIZE);
ldata->line_start = ldata->read_tail;
if (!L_ICANON(tty) || !read_cnt(ldata)) {
ldata->canon_head = ldata->read_tail;
ldata->push = 0;
} else {
set_bit((ldata->read_head - 1) & (N_TTY_BUF_SIZE - 1),
ldata->read_flags);
ldata->canon_head = ldata->read_head;
ldata->push = 1;
}
ldata->erasing = 0;
ldata->lnext = 0;
}
ldata->icanon = (L_ICANON(tty) != 0);
if (I_ISTRIP(tty) || I_IUCLC(tty) || I_IGNCR(tty) ||
I_ICRNL(tty) || I_INLCR(tty) || L_ICANON(tty) ||
I_IXON(tty) || L_ISIG(tty) || L_ECHO(tty) ||
I_PARMRK(tty)) {
bitmap_zero(ldata->char_map, 256);
if (I_IGNCR(tty) || I_ICRNL(tty))
set_bit('\r', ldata->char_map);
if (I_INLCR(tty))
set_bit('\n', ldata->char_map);
if (L_ICANON(tty)) {
set_bit(ERASE_CHAR(tty), ldata->char_map);
set_bit(KILL_CHAR(tty), ldata->char_map);
set_bit(EOF_CHAR(tty), ldata->char_map);
set_bit('\n', ldata->char_map);
set_bit(EOL_CHAR(tty), ldata->char_map);
if (L_IEXTEN(tty)) {
set_bit(WERASE_CHAR(tty), ldata->char_map);
set_bit(LNEXT_CHAR(tty), ldata->char_map);
set_bit(EOL2_CHAR(tty), ldata->char_map);
if (L_ECHO(tty))
set_bit(REPRINT_CHAR(tty),
ldata->char_map);
}
}
if (I_IXON(tty)) {
set_bit(START_CHAR(tty), ldata->char_map);
set_bit(STOP_CHAR(tty), ldata->char_map);
}
if (L_ISIG(tty)) {
set_bit(INTR_CHAR(tty), ldata->char_map);
set_bit(QUIT_CHAR(tty), ldata->char_map);
set_bit(SUSP_CHAR(tty), ldata->char_map);
}
clear_bit(__DISABLED_CHAR, ldata->char_map);
ldata->raw = 0;
ldata->real_raw = 0;
} else {
ldata->raw = 1;
if ((I_IGNBRK(tty) || (!I_BRKINT(tty) && !I_PARMRK(tty))) &&
(I_IGNPAR(tty) || !I_INPCK(tty)) &&
(tty->driver->flags & TTY_DRIVER_REAL_RAW))
ldata->real_raw = 1;
else
ldata->real_raw = 0;
}
n_tty_set_room(tty);
if (!I_IXON(tty) && old && (old->c_iflag & IXON) && !tty->flow_stopped) {
start_tty(tty);
process_echoes(tty);
}
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
if (waitqueue_active(&tty->read_wait))
wake_up_interruptible(&tty->read_wait);
}
static void n_tty_close(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
if (tty->link)
n_tty_packet_mode_flush(tty);
vfree(ldata);
tty->disc_data = NULL;
}
static int n_tty_open(struct tty_struct *tty)
{
struct n_tty_data *ldata;
ldata = vmalloc(sizeof(*ldata));
if (!ldata)
goto err;
ldata->overrun_time = jiffies;
mutex_init(&ldata->atomic_read_lock);
mutex_init(&ldata->output_lock);
tty->disc_data = ldata;
reset_buffer_flags(tty->disc_data);
ldata->column = 0;
ldata->canon_column = 0;
ldata->minimum_to_wake = 1;
ldata->num_overrun = 0;
ldata->no_room = 0;
ldata->lnext = 0;
tty->closing = 0;
clear_bit(TTY_LDISC_HALTED, &tty->flags);
n_tty_set_termios(tty, NULL);
tty_unthrottle(tty);
return 0;
err:
return -ENOMEM;
}
static inline int input_available_p(struct tty_struct *tty, int poll)
{
struct n_tty_data *ldata = tty->disc_data;
int amt = poll && !TIME_CHAR(tty) && MIN_CHAR(tty) ? MIN_CHAR(tty) : 1;
if (ldata->icanon && !L_EXTPROC(tty))
return ldata->canon_head != ldata->read_tail;
else
return read_cnt(ldata) >= amt;
}
static int copy_from_read_buf(struct tty_struct *tty,
unsigned char __user **b,
size_t *nr)
{
struct n_tty_data *ldata = tty->disc_data;
int retval;
size_t n;
bool is_eof;
size_t tail = ldata->read_tail & (N_TTY_BUF_SIZE - 1);
retval = 0;
n = min(read_cnt(ldata), N_TTY_BUF_SIZE - tail);
n = min(*nr, n);
if (n) {
retval = copy_to_user(*b, read_buf_addr(ldata, tail), n);
n -= retval;
is_eof = n == 1 && read_buf(ldata, tail) == EOF_CHAR(tty);
tty_audit_add_data(tty, read_buf_addr(ldata, tail), n,
ldata->icanon);
ldata->read_tail += n;
if (L_EXTPROC(tty) && ldata->icanon && is_eof && !read_cnt(ldata))
n = 0;
*b += n;
*nr -= n;
}
return retval;
}
static int canon_copy_from_read_buf(struct tty_struct *tty,
unsigned char __user **b,
size_t *nr)
{
struct n_tty_data *ldata = tty->disc_data;
size_t n, size, more, c;
size_t eol;
size_t tail;
int ret, found = 0;
bool eof_push = 0;
n = min(*nr, read_cnt(ldata));
if (!n)
return 0;
tail = ldata->read_tail & (N_TTY_BUF_SIZE - 1);
size = min_t(size_t, tail + n, N_TTY_BUF_SIZE);
n_tty_trace("%s: nr:%zu tail:%zu n:%zu size:%zu\n",
__func__, *nr, tail, n, size);
eol = find_next_bit(ldata->read_flags, size, tail);
more = n - (size - tail);
if (eol == N_TTY_BUF_SIZE && more) {
eol = find_next_bit(ldata->read_flags, more, 0);
if (eol != more)
found = 1;
} else if (eol != size)
found = 1;
size = N_TTY_BUF_SIZE - tail;
n = eol - tail;
if (n > 4096)
n += 4096;
n += found;
c = n;
if (found && !ldata->push && read_buf(ldata, eol) == __DISABLED_CHAR) {
n--;
eof_push = !n && ldata->read_tail != ldata->line_start;
}
n_tty_trace("%s: eol:%zu found:%d n:%zu c:%zu size:%zu more:%zu\n",
__func__, eol, found, n, c, size, more);
if (n > size) {
ret = copy_to_user(*b, read_buf_addr(ldata, tail), size);
if (ret)
return -EFAULT;
ret = copy_to_user(*b + size, ldata->read_buf, n - size);
} else
ret = copy_to_user(*b, read_buf_addr(ldata, tail), n);
if (ret)
return -EFAULT;
*b += n;
*nr -= n;
if (found)
clear_bit(eol, ldata->read_flags);
smp_mb__after_atomic();
ldata->read_tail += c;
if (found) {
if (!ldata->push)
ldata->line_start = ldata->read_tail;
else
ldata->push = 0;
tty_audit_push(tty);
}
return eof_push ? -EAGAIN : 0;
}
static int job_control(struct tty_struct *tty, struct file *file)
{
if (file->f_op->write == redirected_tty_write ||
current->signal->tty != tty)
return 0;
spin_lock_irq(&tty->ctrl_lock);
if (!tty->pgrp)
printk(KERN_ERR "n_tty_read: no tty->pgrp!\n");
else if (task_pgrp(current) != tty->pgrp) {
spin_unlock_irq(&tty->ctrl_lock);
if (is_ignored(SIGTTIN) || is_current_pgrp_orphaned())
return -EIO;
kill_pgrp(task_pgrp(current), SIGTTIN, 1);
set_thread_flag(TIF_SIGPENDING);
return -ERESTARTSYS;
}
spin_unlock_irq(&tty->ctrl_lock);
return 0;
}
static ssize_t n_tty_read(struct tty_struct *tty, struct file *file,
unsigned char __user *buf, size_t nr)
{
struct n_tty_data *ldata = tty->disc_data;
unsigned char __user *b = buf;
DECLARE_WAITQUEUE(wait, current);
int c;
int minimum, time;
ssize_t retval = 0;
long timeout;
unsigned long flags;
int packet;
c = job_control(tty, file);
if (c < 0)
return c;
if (file->f_flags & O_NONBLOCK) {
if (!mutex_trylock(&ldata->atomic_read_lock))
return -EAGAIN;
} else {
if (mutex_lock_interruptible(&ldata->atomic_read_lock))
return -ERESTARTSYS;
}
down_read(&tty->termios_rwsem);
minimum = time = 0;
timeout = MAX_SCHEDULE_TIMEOUT;
if (!ldata->icanon) {
minimum = MIN_CHAR(tty);
if (minimum) {
time = (HZ / 10) * TIME_CHAR(tty);
if (time)
ldata->minimum_to_wake = 1;
else if (!waitqueue_active(&tty->read_wait) ||
(ldata->minimum_to_wake > minimum))
ldata->minimum_to_wake = minimum;
} else {
timeout = (HZ / 10) * TIME_CHAR(tty);
ldata->minimum_to_wake = minimum = 1;
}
}
packet = tty->packet;
add_wait_queue(&tty->read_wait, &wait);
while (nr) {
if (packet && tty->link->ctrl_status) {
unsigned char cs;
if (b != buf)
break;
spin_lock_irqsave(&tty->link->ctrl_lock, flags);
cs = tty->link->ctrl_status;
tty->link->ctrl_status = 0;
spin_unlock_irqrestore(&tty->link->ctrl_lock, flags);
if (tty_put_user(tty, cs, b++)) {
retval = -EFAULT;
b--;
break;
}
nr--;
break;
}
set_current_state(TASK_INTERRUPTIBLE);
if (((minimum - (b - buf)) < ldata->minimum_to_wake) &&
((minimum - (b - buf)) >= 1))
ldata->minimum_to_wake = (minimum - (b - buf));
if (!input_available_p(tty, 0)) {
if (test_bit(TTY_OTHER_CLOSED, &tty->flags)) {
up_read(&tty->termios_rwsem);
tty_flush_to_ldisc(tty);
down_read(&tty->termios_rwsem);
if (!input_available_p(tty, 0)) {
retval = -EIO;
break;
}
} else {
if (tty_hung_up_p(file))
break;
if (!timeout)
break;
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
break;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
n_tty_set_room(tty);
up_read(&tty->termios_rwsem);
timeout = schedule_timeout(timeout);
down_read(&tty->termios_rwsem);
continue;
}
}
__set_current_state(TASK_RUNNING);
if (packet && b == buf) {
if (tty_put_user(tty, TIOCPKT_DATA, b++)) {
retval = -EFAULT;
b--;
break;
}
nr--;
}
if (ldata->icanon && !L_EXTPROC(tty)) {
retval = canon_copy_from_read_buf(tty, &b, &nr);
if (retval == -EAGAIN) {
retval = 0;
continue;
} else if (retval)
break;
} else {
int uncopied;
uncopied = copy_from_read_buf(tty, &b, &nr);
uncopied += copy_from_read_buf(tty, &b, &nr);
if (uncopied) {
retval = -EFAULT;
break;
}
}
n_tty_check_unthrottle(tty);
if (b - buf >= minimum)
break;
if (time)
timeout = time;
}
n_tty_set_room(tty);
up_read(&tty->termios_rwsem);
remove_wait_queue(&tty->read_wait, &wait);
if (!waitqueue_active(&tty->read_wait))
ldata->minimum_to_wake = minimum;
mutex_unlock(&ldata->atomic_read_lock);
__set_current_state(TASK_RUNNING);
if (b - buf)
retval = b - buf;
return retval;
}
static ssize_t n_tty_write(struct tty_struct *tty, struct file *file,
const unsigned char *buf, size_t nr)
{
const unsigned char *b = buf;
DECLARE_WAITQUEUE(wait, current);
int c;
ssize_t retval = 0;
if (L_TOSTOP(tty) && file->f_op->write != redirected_tty_write) {
retval = tty_check_change(tty);
if (retval)
return retval;
}
down_read(&tty->termios_rwsem);
process_echoes(tty);
add_wait_queue(&tty->write_wait, &wait);
while (1) {
set_current_state(TASK_INTERRUPTIBLE);
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
if (tty_hung_up_p(file) || (tty->link && !tty->link->count)) {
retval = -EIO;
break;
}
if (O_OPOST(tty)) {
while (nr > 0) {
ssize_t num = process_output_block(tty, b, nr);
if (num < 0) {
if (num == -EAGAIN)
break;
retval = num;
goto break_out;
}
b += num;
nr -= num;
if (nr == 0)
break;
c = *b;
if (process_output(c, tty) < 0)
break;
b++; nr--;
}
if (tty->ops->flush_chars)
tty->ops->flush_chars(tty);
} else {
struct n_tty_data *ldata = tty->disc_data;
while (nr > 0) {
mutex_lock(&ldata->output_lock);
c = tty->ops->write(tty, b, nr);
mutex_unlock(&ldata->output_lock);
if (c < 0) {
retval = c;
goto break_out;
}
if (!c)
break;
b += c;
nr -= c;
}
}
if (!nr)
break;
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
break;
}
up_read(&tty->termios_rwsem);
schedule();
down_read(&tty->termios_rwsem);
}
break_out:
__set_current_state(TASK_RUNNING);
remove_wait_queue(&tty->write_wait, &wait);
if (b - buf != nr && tty->fasync)
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
up_read(&tty->termios_rwsem);
return (b - buf) ? b - buf : retval;
}
static unsigned int n_tty_poll(struct tty_struct *tty, struct file *file,
poll_table *wait)
{
struct n_tty_data *ldata = tty->disc_data;
unsigned int mask = 0;
poll_wait(file, &tty->read_wait, wait);
poll_wait(file, &tty->write_wait, wait);
if (test_bit(TTY_OTHER_CLOSED, &tty->flags))
mask |= POLLHUP;
if (input_available_p(tty, 1))
mask |= POLLIN | POLLRDNORM;
else if (mask & POLLHUP) {
tty_flush_to_ldisc(tty);
if (input_available_p(tty, 1))
mask |= POLLIN | POLLRDNORM;
}
if (tty->packet && tty->link->ctrl_status)
mask |= POLLPRI | POLLIN | POLLRDNORM;
if (tty_hung_up_p(file))
mask |= POLLHUP;
if (!(mask & (POLLHUP | POLLIN | POLLRDNORM))) {
if (MIN_CHAR(tty) && !TIME_CHAR(tty))
ldata->minimum_to_wake = MIN_CHAR(tty);
else
ldata->minimum_to_wake = 1;
}
if (tty->ops->write && !tty_is_writelocked(tty) &&
tty_chars_in_buffer(tty) < WAKEUP_CHARS &&
tty_write_room(tty) > 0)
mask |= POLLOUT | POLLWRNORM;
return mask;
}
static unsigned long inq_canon(struct n_tty_data *ldata)
{
size_t nr, head, tail;
if (ldata->canon_head == ldata->read_tail)
return 0;
head = ldata->canon_head;
tail = ldata->read_tail;
nr = head - tail;
while (head != tail) {
if (test_bit(tail & (N_TTY_BUF_SIZE - 1), ldata->read_flags) &&
read_buf(ldata, tail) == __DISABLED_CHAR)
nr--;
tail++;
}
return nr;
}
static int n_tty_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct n_tty_data *ldata = tty->disc_data;
int retval;
switch (cmd) {
case TIOCOUTQ:
return put_user(tty_chars_in_buffer(tty), (int __user *) arg);
case TIOCINQ:
down_write(&tty->termios_rwsem);
if (L_ICANON(tty))
retval = inq_canon(ldata);
else
retval = read_cnt(ldata);
up_write(&tty->termios_rwsem);
return put_user(retval, (unsigned int __user *) arg);
default:
return n_tty_ioctl_helper(tty, file, cmd, arg);
}
}
static void n_tty_fasync(struct tty_struct *tty, int on)
{
struct n_tty_data *ldata = tty->disc_data;
if (!waitqueue_active(&tty->read_wait)) {
if (on)
ldata->minimum_to_wake = 1;
else if (!tty->fasync)
ldata->minimum_to_wake = N_TTY_BUF_SIZE;
}
}
void n_tty_inherit_ops(struct tty_ldisc_ops *ops)
{
*ops = tty_ldisc_N_TTY;
ops->owner = NULL;
ops->refcount = ops->flags = 0;
}
