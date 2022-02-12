static inline int tty_put_user(struct tty_struct *tty, unsigned char x,
unsigned char __user *ptr)
{
struct n_tty_data *ldata = tty->disc_data;
tty_audit_add_data(tty, &x, 1, ldata->icanon);
return put_user(x, ptr);
}
static void n_tty_set_room(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
int left;
int old_left;
if (I_PARMRK(tty)) {
left = N_TTY_BUF_SIZE - ldata->read_cnt * 3 - 1;
} else
left = N_TTY_BUF_SIZE - ldata->read_cnt - 1;
if (left <= 0)
left = ldata->icanon && !ldata->canon_data;
old_left = tty->receive_room;
tty->receive_room = left;
if (left && !old_left) {
WARN_RATELIMIT(tty->port->itty == NULL,
"scheduling with invalid itty\n");
schedule_work(&tty->port->buf.work);
}
}
static void put_tty_queue_nolock(unsigned char c, struct n_tty_data *ldata)
{
if (ldata->read_cnt < N_TTY_BUF_SIZE) {
ldata->read_buf[ldata->read_head] = c;
ldata->read_head = (ldata->read_head + 1) & (N_TTY_BUF_SIZE-1);
ldata->read_cnt++;
}
}
static void put_tty_queue(unsigned char c, struct n_tty_data *ldata)
{
unsigned long flags;
raw_spin_lock_irqsave(&ldata->read_lock, flags);
put_tty_queue_nolock(c, ldata);
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
}
static void check_unthrottle(struct tty_struct *tty)
{
if (tty->count)
tty_unthrottle(tty);
}
static void reset_buffer_flags(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
unsigned long flags;
raw_spin_lock_irqsave(&ldata->read_lock, flags);
ldata->read_head = ldata->read_tail = ldata->read_cnt = 0;
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
mutex_lock(&ldata->echo_lock);
ldata->echo_pos = ldata->echo_cnt = ldata->echo_overrun = 0;
mutex_unlock(&ldata->echo_lock);
ldata->canon_head = ldata->canon_data = ldata->erasing = 0;
bitmap_zero(ldata->read_flags, N_TTY_BUF_SIZE);
n_tty_set_room(tty);
}
static void n_tty_flush_buffer(struct tty_struct *tty)
{
unsigned long flags;
reset_buffer_flags(tty);
if (!tty->link)
return;
spin_lock_irqsave(&tty->ctrl_lock, flags);
if (tty->link->packet) {
tty->ctrl_status |= TIOCPKT_FLUSHREAD;
wake_up_interruptible(&tty->link->read_wait);
}
spin_unlock_irqrestore(&tty->ctrl_lock, flags);
}
static ssize_t n_tty_chars_in_buffer(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
unsigned long flags;
ssize_t n = 0;
raw_spin_lock_irqsave(&ldata->read_lock, flags);
if (!ldata->icanon) {
n = ldata->read_cnt;
} else if (ldata->canon_data) {
n = (ldata->canon_head > ldata->read_tail) ?
ldata->canon_head - ldata->read_tail :
ldata->canon_head + (N_TTY_BUF_SIZE - ldata->read_tail);
}
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
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
static void process_echoes(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
int space, nr;
unsigned char c;
unsigned char *cp, *buf_end;
if (!ldata->echo_cnt)
return;
mutex_lock(&ldata->output_lock);
mutex_lock(&ldata->echo_lock);
space = tty_write_room(tty);
buf_end = ldata->echo_buf + N_TTY_BUF_SIZE;
cp = ldata->echo_buf + ldata->echo_pos;
nr = ldata->echo_cnt;
while (nr > 0) {
c = *cp;
if (c == ECHO_OP_START) {
unsigned char op;
unsigned char *opp;
int no_space_left = 0;
opp = cp + 1;
if (opp == buf_end)
opp -= N_TTY_BUF_SIZE;
op = *opp;
switch (op) {
unsigned int num_chars, num_bs;
case ECHO_OP_ERASE_TAB:
if (++opp == buf_end)
opp -= N_TTY_BUF_SIZE;
num_chars = *opp;
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
cp += 3;
nr -= 3;
break;
case ECHO_OP_SET_CANON_COL:
ldata->canon_column = ldata->column;
cp += 2;
nr -= 2;
break;
case ECHO_OP_MOVE_BACK_COL:
if (ldata->column > 0)
ldata->column--;
cp += 2;
nr -= 2;
break;
case ECHO_OP_START:
if (!space) {
no_space_left = 1;
break;
}
tty_put_char(tty, ECHO_OP_START);
ldata->column++;
space--;
cp += 2;
nr -= 2;
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
cp += 2;
nr -= 2;
}
if (no_space_left)
break;
} else {
if (O_OPOST(tty) &&
!(test_bit(TTY_HW_COOK_OUT, &tty->flags))) {
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
cp += 1;
nr -= 1;
}
if (cp >= buf_end)
cp -= N_TTY_BUF_SIZE;
}
if (nr == 0) {
ldata->echo_pos = 0;
ldata->echo_cnt = 0;
ldata->echo_overrun = 0;
} else {
int num_processed = ldata->echo_cnt - nr;
ldata->echo_pos += num_processed;
ldata->echo_pos &= N_TTY_BUF_SIZE - 1;
ldata->echo_cnt = nr;
if (num_processed > 0)
ldata->echo_overrun = 0;
}
mutex_unlock(&ldata->echo_lock);
mutex_unlock(&ldata->output_lock);
if (tty->ops->flush_chars)
tty->ops->flush_chars(tty);
}
static void add_echo_byte(unsigned char c, struct n_tty_data *ldata)
{
int new_byte_pos;
if (ldata->echo_cnt == N_TTY_BUF_SIZE) {
new_byte_pos = ldata->echo_pos;
if (ldata->echo_buf[ldata->echo_pos] == ECHO_OP_START) {
if (ldata->echo_buf[(ldata->echo_pos + 1) &
(N_TTY_BUF_SIZE - 1)] ==
ECHO_OP_ERASE_TAB) {
ldata->echo_pos += 3;
ldata->echo_cnt -= 2;
} else {
ldata->echo_pos += 2;
ldata->echo_cnt -= 1;
}
} else {
ldata->echo_pos++;
}
ldata->echo_pos &= N_TTY_BUF_SIZE - 1;
ldata->echo_overrun = 1;
} else {
new_byte_pos = ldata->echo_pos + ldata->echo_cnt;
new_byte_pos &= N_TTY_BUF_SIZE - 1;
ldata->echo_cnt++;
}
ldata->echo_buf[new_byte_pos] = c;
}
static void echo_move_back_col(struct n_tty_data *ldata)
{
mutex_lock(&ldata->echo_lock);
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_MOVE_BACK_COL, ldata);
mutex_unlock(&ldata->echo_lock);
}
static void echo_set_canon_col(struct n_tty_data *ldata)
{
mutex_lock(&ldata->echo_lock);
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_SET_CANON_COL, ldata);
mutex_unlock(&ldata->echo_lock);
}
static void echo_erase_tab(unsigned int num_chars, int after_tab,
struct n_tty_data *ldata)
{
mutex_lock(&ldata->echo_lock);
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_ERASE_TAB, ldata);
num_chars &= 7;
if (after_tab)
num_chars |= 0x80;
add_echo_byte(num_chars, ldata);
mutex_unlock(&ldata->echo_lock);
}
static void echo_char_raw(unsigned char c, struct n_tty_data *ldata)
{
mutex_lock(&ldata->echo_lock);
if (c == ECHO_OP_START) {
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_START, ldata);
} else {
add_echo_byte(c, ldata);
}
mutex_unlock(&ldata->echo_lock);
}
static void echo_char(unsigned char c, struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
mutex_lock(&ldata->echo_lock);
if (c == ECHO_OP_START) {
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(ECHO_OP_START, ldata);
} else {
if (L_ECHOCTL(tty) && iscntrl(c) && c != '\t')
add_echo_byte(ECHO_OP_START, ldata);
add_echo_byte(c, ldata);
}
mutex_unlock(&ldata->echo_lock);
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
int head, seen_alnums, cnt;
unsigned long flags;
if (ldata->read_head == ldata->canon_head) {
return;
}
if (c == ERASE_CHAR(tty))
kill_type = ERASE;
else if (c == WERASE_CHAR(tty))
kill_type = WERASE;
else {
if (!L_ECHO(tty)) {
raw_spin_lock_irqsave(&ldata->read_lock, flags);
ldata->read_cnt -= ((ldata->read_head - ldata->canon_head) &
(N_TTY_BUF_SIZE - 1));
ldata->read_head = ldata->canon_head;
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
return;
}
if (!L_ECHOK(tty) || !L_ECHOKE(tty) || !L_ECHOE(tty)) {
raw_spin_lock_irqsave(&ldata->read_lock, flags);
ldata->read_cnt -= ((ldata->read_head - ldata->canon_head) &
(N_TTY_BUF_SIZE - 1));
ldata->read_head = ldata->canon_head;
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
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
head = (head - 1) & (N_TTY_BUF_SIZE-1);
c = ldata->read_buf[head];
} while (is_continuation(c, tty) && head != ldata->canon_head);
if (is_continuation(c, tty))
break;
if (kill_type == WERASE) {
if (isalnum(c) || c == '_')
seen_alnums++;
else if (seen_alnums)
break;
}
cnt = (ldata->read_head - head) & (N_TTY_BUF_SIZE-1);
raw_spin_lock_irqsave(&ldata->read_lock, flags);
ldata->read_head = head;
ldata->read_cnt -= cnt;
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
if (L_ECHO(tty)) {
if (L_ECHOPRT(tty)) {
if (!ldata->erasing) {
echo_char_raw('\\', ldata);
ldata->erasing = 1;
}
echo_char(c, tty);
while (--cnt > 0) {
head = (head+1) & (N_TTY_BUF_SIZE-1);
echo_char_raw(ldata->read_buf[head],
ldata);
echo_move_back_col(ldata);
}
} else if (kill_type == ERASE && !L_ECHOE(tty)) {
echo_char(ERASE_CHAR(tty), tty);
} else if (c == '\t') {
unsigned int num_chars = 0;
int after_tab = 0;
unsigned long tail = ldata->read_head;
while (tail != ldata->canon_head) {
tail = (tail-1) & (N_TTY_BUF_SIZE-1);
c = ldata->read_buf[tail];
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
static inline void isig(int sig, struct tty_struct *tty, int flush)
{
if (tty->pgrp)
kill_pgrp(tty->pgrp, sig, 1);
if (flush || !L_NOFLSH(tty)) {
n_tty_flush_buffer(tty);
tty_driver_flush_buffer(tty);
}
}
static inline void n_tty_receive_break(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
if (I_IGNBRK(tty))
return;
if (I_BRKINT(tty)) {
isig(SIGINT, tty, 1);
return;
}
if (I_PARMRK(tty)) {
put_tty_queue('\377', ldata);
put_tty_queue('\0', ldata);
}
put_tty_queue('\0', ldata);
wake_up_interruptible(&tty->read_wait);
}
static inline void n_tty_receive_overrun(struct tty_struct *tty)
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
static inline void n_tty_receive_parity_error(struct tty_struct *tty,
unsigned char c)
{
struct n_tty_data *ldata = tty->disc_data;
if (I_IGNPAR(tty))
return;
if (I_PARMRK(tty)) {
put_tty_queue('\377', ldata);
put_tty_queue('\0', ldata);
put_tty_queue(c, ldata);
} else if (I_INPCK(tty))
put_tty_queue('\0', ldata);
else
put_tty_queue(c, ldata);
wake_up_interruptible(&tty->read_wait);
}
static inline void n_tty_receive_char(struct tty_struct *tty, unsigned char c)
{
struct n_tty_data *ldata = tty->disc_data;
unsigned long flags;
int parmrk;
if (ldata->raw) {
put_tty_queue(c, ldata);
return;
}
if (I_ISTRIP(tty))
c &= 0x7f;
if (I_IUCLC(tty) && L_IEXTEN(tty))
c = tolower(c);
if (L_EXTPROC(tty)) {
put_tty_queue(c, ldata);
return;
}
if (tty->stopped && !tty->flow_stopped && I_IXON(tty) &&
I_IXANY(tty) && c != START_CHAR(tty) && c != STOP_CHAR(tty) &&
c != INTR_CHAR(tty) && c != QUIT_CHAR(tty) && c != SUSP_CHAR(tty)) {
start_tty(tty);
process_echoes(tty);
}
if (tty->closing) {
if (I_IXON(tty)) {
if (c == START_CHAR(tty)) {
start_tty(tty);
process_echoes(tty);
} else if (c == STOP_CHAR(tty))
stop_tty(tty);
}
return;
}
if (!test_bit(c, ldata->process_char_map) || ldata->lnext) {
ldata->lnext = 0;
parmrk = (c == (unsigned char) '\377' && I_PARMRK(tty)) ? 1 : 0;
if (ldata->read_cnt >= (N_TTY_BUF_SIZE - parmrk - 1)) {
if (L_ECHO(tty))
process_output('\a', tty);
return;
}
if (L_ECHO(tty)) {
finish_erasing(ldata);
if (ldata->canon_head == ldata->read_head)
echo_set_canon_col(ldata);
echo_char(c, tty);
process_echoes(tty);
}
if (parmrk)
put_tty_queue(c, ldata);
put_tty_queue(c, ldata);
return;
}
if (I_IXON(tty)) {
if (c == START_CHAR(tty)) {
start_tty(tty);
process_echoes(tty);
return;
}
if (c == STOP_CHAR(tty)) {
stop_tty(tty);
return;
}
}
if (L_ISIG(tty)) {
int signal;
signal = SIGINT;
if (c == INTR_CHAR(tty))
goto send_signal;
signal = SIGQUIT;
if (c == QUIT_CHAR(tty))
goto send_signal;
signal = SIGTSTP;
if (c == SUSP_CHAR(tty)) {
send_signal:
if (!L_NOFLSH(tty)) {
n_tty_flush_buffer(tty);
tty_driver_flush_buffer(tty);
}
if (I_IXON(tty))
start_tty(tty);
if (L_ECHO(tty)) {
echo_char(c, tty);
process_echoes(tty);
}
if (tty->pgrp)
kill_pgrp(tty->pgrp, signal, 1);
return;
}
}
if (c == '\r') {
if (I_IGNCR(tty))
return;
if (I_ICRNL(tty))
c = '\n';
} else if (c == '\n' && I_INLCR(tty))
c = '\r';
if (ldata->icanon) {
if (c == ERASE_CHAR(tty) || c == KILL_CHAR(tty) ||
(c == WERASE_CHAR(tty) && L_IEXTEN(tty))) {
eraser(c, tty);
process_echoes(tty);
return;
}
if (c == LNEXT_CHAR(tty) && L_IEXTEN(tty)) {
ldata->lnext = 1;
if (L_ECHO(tty)) {
finish_erasing(ldata);
if (L_ECHOCTL(tty)) {
echo_char_raw('^', ldata);
echo_char_raw('\b', ldata);
process_echoes(tty);
}
}
return;
}
if (c == REPRINT_CHAR(tty) && L_ECHO(tty) &&
L_IEXTEN(tty)) {
unsigned long tail = ldata->canon_head;
finish_erasing(ldata);
echo_char(c, tty);
echo_char_raw('\n', ldata);
while (tail != ldata->read_head) {
echo_char(ldata->read_buf[tail], tty);
tail = (tail+1) & (N_TTY_BUF_SIZE-1);
}
process_echoes(tty);
return;
}
if (c == '\n') {
if (ldata->read_cnt >= N_TTY_BUF_SIZE) {
if (L_ECHO(tty))
process_output('\a', tty);
return;
}
if (L_ECHO(tty) || L_ECHONL(tty)) {
echo_char_raw('\n', ldata);
process_echoes(tty);
}
goto handle_newline;
}
if (c == EOF_CHAR(tty)) {
if (ldata->read_cnt >= N_TTY_BUF_SIZE)
return;
if (ldata->canon_head != ldata->read_head)
set_bit(TTY_PUSH, &tty->flags);
c = __DISABLED_CHAR;
goto handle_newline;
}
if ((c == EOL_CHAR(tty)) ||
(c == EOL2_CHAR(tty) && L_IEXTEN(tty))) {
parmrk = (c == (unsigned char) '\377' && I_PARMRK(tty))
? 1 : 0;
if (ldata->read_cnt >= (N_TTY_BUF_SIZE - parmrk)) {
if (L_ECHO(tty))
process_output('\a', tty);
return;
}
if (L_ECHO(tty)) {
if (ldata->canon_head == ldata->read_head)
echo_set_canon_col(ldata);
echo_char(c, tty);
process_echoes(tty);
}
if (parmrk)
put_tty_queue(c, ldata);
handle_newline:
raw_spin_lock_irqsave(&ldata->read_lock, flags);
set_bit(ldata->read_head, ldata->read_flags);
put_tty_queue_nolock(c, ldata);
ldata->canon_head = ldata->read_head;
ldata->canon_data++;
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
kill_fasync(&tty->fasync, SIGIO, POLL_IN);
if (waitqueue_active(&tty->read_wait))
wake_up_interruptible(&tty->read_wait);
return;
}
}
parmrk = (c == (unsigned char) '\377' && I_PARMRK(tty)) ? 1 : 0;
if (ldata->read_cnt >= (N_TTY_BUF_SIZE - parmrk - 1)) {
if (L_ECHO(tty))
process_output('\a', tty);
return;
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
process_echoes(tty);
}
if (parmrk)
put_tty_queue(c, ldata);
put_tty_queue(c, ldata);
}
static void n_tty_write_wakeup(struct tty_struct *tty)
{
if (tty->fasync && test_and_clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags))
kill_fasync(&tty->fasync, SIGIO, POLL_OUT);
}
static void n_tty_receive_buf(struct tty_struct *tty, const unsigned char *cp,
char *fp, int count)
{
struct n_tty_data *ldata = tty->disc_data;
const unsigned char *p;
char *f, flags = TTY_NORMAL;
int i;
char buf[64];
unsigned long cpuflags;
if (ldata->real_raw) {
raw_spin_lock_irqsave(&ldata->read_lock, cpuflags);
i = min(N_TTY_BUF_SIZE - ldata->read_cnt,
N_TTY_BUF_SIZE - ldata->read_head);
i = min(count, i);
memcpy(ldata->read_buf + ldata->read_head, cp, i);
ldata->read_head = (ldata->read_head + i) & (N_TTY_BUF_SIZE-1);
ldata->read_cnt += i;
cp += i;
count -= i;
i = min(N_TTY_BUF_SIZE - ldata->read_cnt,
N_TTY_BUF_SIZE - ldata->read_head);
i = min(count, i);
memcpy(ldata->read_buf + ldata->read_head, cp, i);
ldata->read_head = (ldata->read_head + i) & (N_TTY_BUF_SIZE-1);
ldata->read_cnt += i;
raw_spin_unlock_irqrestore(&ldata->read_lock, cpuflags);
} else {
for (i = count, p = cp, f = fp; i; i--, p++) {
if (f)
flags = *f++;
switch (flags) {
case TTY_NORMAL:
n_tty_receive_char(tty, *p);
break;
case TTY_BREAK:
n_tty_receive_break(tty);
break;
case TTY_PARITY:
case TTY_FRAME:
n_tty_receive_parity_error(tty, *p);
break;
case TTY_OVERRUN:
n_tty_receive_overrun(tty);
break;
default:
printk(KERN_ERR "%s: unknown flag %d\n",
tty_name(tty, buf), flags);
break;
}
}
if (tty->ops->flush_chars)
tty->ops->flush_chars(tty);
}
n_tty_set_room(tty);
if ((!ldata->icanon && (ldata->read_cnt >= tty->minimum_to_wake)) ||
L_EXTPROC(tty)) {
kill_fasync(&tty->fasync, SIGIO, POLL_IN);
if (waitqueue_active(&tty->read_wait))
wake_up_interruptible(&tty->read_wait);
}
if (tty->receive_room < TTY_THRESHOLD_THROTTLE)
tty_throttle(tty);
}
int is_ignored(int sig)
{
return (sigismember(&current->blocked, sig) ||
current->sighand->action[sig-1].sa.sa_handler == SIG_IGN);
}
static void n_tty_set_termios(struct tty_struct *tty, struct ktermios *old)
{
struct n_tty_data *ldata = tty->disc_data;
int canon_change = 1;
if (old)
canon_change = (old->c_lflag ^ tty->termios.c_lflag) & ICANON;
if (canon_change) {
bitmap_zero(ldata->read_flags, N_TTY_BUF_SIZE);
ldata->canon_head = ldata->read_tail;
ldata->canon_data = 0;
ldata->erasing = 0;
}
if (canon_change && !L_ICANON(tty) && ldata->read_cnt)
wake_up_interruptible(&tty->read_wait);
ldata->icanon = (L_ICANON(tty) != 0);
if (test_bit(TTY_HW_COOK_IN, &tty->flags)) {
ldata->raw = 1;
ldata->real_raw = 1;
n_tty_set_room(tty);
return;
}
if (I_ISTRIP(tty) || I_IUCLC(tty) || I_IGNCR(tty) ||
I_ICRNL(tty) || I_INLCR(tty) || L_ICANON(tty) ||
I_IXON(tty) || L_ISIG(tty) || L_ECHO(tty) ||
I_PARMRK(tty)) {
bitmap_zero(ldata->process_char_map, 256);
if (I_IGNCR(tty) || I_ICRNL(tty))
set_bit('\r', ldata->process_char_map);
if (I_INLCR(tty))
set_bit('\n', ldata->process_char_map);
if (L_ICANON(tty)) {
set_bit(ERASE_CHAR(tty), ldata->process_char_map);
set_bit(KILL_CHAR(tty), ldata->process_char_map);
set_bit(EOF_CHAR(tty), ldata->process_char_map);
set_bit('\n', ldata->process_char_map);
set_bit(EOL_CHAR(tty), ldata->process_char_map);
if (L_IEXTEN(tty)) {
set_bit(WERASE_CHAR(tty),
ldata->process_char_map);
set_bit(LNEXT_CHAR(tty),
ldata->process_char_map);
set_bit(EOL2_CHAR(tty),
ldata->process_char_map);
if (L_ECHO(tty))
set_bit(REPRINT_CHAR(tty),
ldata->process_char_map);
}
}
if (I_IXON(tty)) {
set_bit(START_CHAR(tty), ldata->process_char_map);
set_bit(STOP_CHAR(tty), ldata->process_char_map);
}
if (L_ISIG(tty)) {
set_bit(INTR_CHAR(tty), ldata->process_char_map);
set_bit(QUIT_CHAR(tty), ldata->process_char_map);
set_bit(SUSP_CHAR(tty), ldata->process_char_map);
}
clear_bit(__DISABLED_CHAR, ldata->process_char_map);
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
wake_up_interruptible(&tty->write_wait);
wake_up_interruptible(&tty->read_wait);
}
static void n_tty_close(struct tty_struct *tty)
{
struct n_tty_data *ldata = tty->disc_data;
n_tty_flush_buffer(tty);
kfree(ldata->read_buf);
kfree(ldata->echo_buf);
kfree(ldata);
tty->disc_data = NULL;
}
static int n_tty_open(struct tty_struct *tty)
{
struct n_tty_data *ldata;
ldata = kzalloc(sizeof(*ldata), GFP_KERNEL);
if (!ldata)
goto err;
ldata->overrun_time = jiffies;
mutex_init(&ldata->atomic_read_lock);
mutex_init(&ldata->output_lock);
mutex_init(&ldata->echo_lock);
raw_spin_lock_init(&ldata->read_lock);
ldata->read_buf = kzalloc(N_TTY_BUF_SIZE, GFP_KERNEL);
ldata->echo_buf = kzalloc(N_TTY_BUF_SIZE, GFP_KERNEL);
if (!ldata->read_buf || !ldata->echo_buf)
goto err_free_bufs;
tty->disc_data = ldata;
reset_buffer_flags(tty);
tty_unthrottle(tty);
ldata->column = 0;
n_tty_set_termios(tty, NULL);
tty->minimum_to_wake = 1;
tty->closing = 0;
return 0;
err_free_bufs:
kfree(ldata->read_buf);
kfree(ldata->echo_buf);
kfree(ldata);
err:
return -ENOMEM;
}
static inline int input_available_p(struct tty_struct *tty, int amt)
{
struct n_tty_data *ldata = tty->disc_data;
tty_flush_to_ldisc(tty);
if (ldata->icanon && !L_EXTPROC(tty)) {
if (ldata->canon_data)
return 1;
} else if (ldata->read_cnt >= (amt ? amt : 1))
return 1;
return 0;
}
static int copy_from_read_buf(struct tty_struct *tty,
unsigned char __user **b,
size_t *nr)
{
struct n_tty_data *ldata = tty->disc_data;
int retval;
size_t n;
unsigned long flags;
bool is_eof;
retval = 0;
raw_spin_lock_irqsave(&ldata->read_lock, flags);
n = min(ldata->read_cnt, N_TTY_BUF_SIZE - ldata->read_tail);
n = min(*nr, n);
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
if (n) {
retval = copy_to_user(*b, &ldata->read_buf[ldata->read_tail], n);
n -= retval;
is_eof = n == 1 &&
ldata->read_buf[ldata->read_tail] == EOF_CHAR(tty);
tty_audit_add_data(tty, &ldata->read_buf[ldata->read_tail], n,
ldata->icanon);
raw_spin_lock_irqsave(&ldata->read_lock, flags);
ldata->read_tail = (ldata->read_tail + n) & (N_TTY_BUF_SIZE-1);
ldata->read_cnt -= n;
if (L_EXTPROC(tty) && ldata->icanon && is_eof && !ldata->read_cnt)
n = 0;
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
*b += n;
*nr -= n;
}
return retval;
}
static int job_control(struct tty_struct *tty, struct file *file)
{
if (file->f_op->write != redirected_tty_write &&
current->signal->tty == tty) {
if (!tty->pgrp)
printk(KERN_ERR "n_tty_read: no tty->pgrp!\n");
else if (task_pgrp(current) != tty->pgrp) {
if (is_ignored(SIGTTIN) ||
is_current_pgrp_orphaned())
return -EIO;
kill_pgrp(task_pgrp(current), SIGTTIN, 1);
set_thread_flag(TIF_SIGPENDING);
return -ERESTARTSYS;
}
}
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
ssize_t size;
long timeout;
unsigned long flags;
int packet;
do_it_again:
c = job_control(tty, file);
if (c < 0)
return c;
minimum = time = 0;
timeout = MAX_SCHEDULE_TIMEOUT;
if (!ldata->icanon) {
time = (HZ / 10) * TIME_CHAR(tty);
minimum = MIN_CHAR(tty);
if (minimum) {
if (time)
tty->minimum_to_wake = 1;
else if (!waitqueue_active(&tty->read_wait) ||
(tty->minimum_to_wake > minimum))
tty->minimum_to_wake = minimum;
} else {
timeout = 0;
if (time) {
timeout = time;
time = 0;
}
tty->minimum_to_wake = minimum = 1;
}
}
if (file->f_flags & O_NONBLOCK) {
if (!mutex_trylock(&ldata->atomic_read_lock))
return -EAGAIN;
} else {
if (mutex_lock_interruptible(&ldata->atomic_read_lock))
return -ERESTARTSYS;
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
if (((minimum - (b - buf)) < tty->minimum_to_wake) &&
((minimum - (b - buf)) >= 1))
tty->minimum_to_wake = (minimum - (b - buf));
if (!input_available_p(tty, 0)) {
if (test_bit(TTY_OTHER_CLOSED, &tty->flags)) {
retval = -EIO;
break;
}
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
timeout = schedule_timeout(timeout);
continue;
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
raw_spin_lock_irqsave(&ldata->read_lock, flags);
while (nr && ldata->read_cnt) {
int eol;
eol = test_and_clear_bit(ldata->read_tail,
ldata->read_flags);
c = ldata->read_buf[ldata->read_tail];
ldata->read_tail = ((ldata->read_tail+1) &
(N_TTY_BUF_SIZE-1));
ldata->read_cnt--;
if (eol) {
if (--ldata->canon_data < 0)
ldata->canon_data = 0;
}
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
if (!eol || (c != __DISABLED_CHAR)) {
if (tty_put_user(tty, c, b++)) {
retval = -EFAULT;
b--;
raw_spin_lock_irqsave(&ldata->read_lock, flags);
break;
}
nr--;
}
if (eol) {
tty_audit_push(tty);
raw_spin_lock_irqsave(&ldata->read_lock, flags);
break;
}
raw_spin_lock_irqsave(&ldata->read_lock, flags);
}
raw_spin_unlock_irqrestore(&ldata->read_lock, flags);
if (retval)
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
if (n_tty_chars_in_buffer(tty) <= TTY_THRESHOLD_UNTHROTTLE) {
n_tty_set_room(tty);
check_unthrottle(tty);
}
if (b - buf >= minimum)
break;
if (time)
timeout = time;
}
mutex_unlock(&ldata->atomic_read_lock);
remove_wait_queue(&tty->read_wait, &wait);
if (!waitqueue_active(&tty->read_wait))
tty->minimum_to_wake = minimum;
__set_current_state(TASK_RUNNING);
size = b - buf;
if (size) {
retval = size;
if (nr)
clear_bit(TTY_PUSH, &tty->flags);
} else if (test_and_clear_bit(TTY_PUSH, &tty->flags))
goto do_it_again;
n_tty_set_room(tty);
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
if (O_OPOST(tty) && !(test_bit(TTY_HW_COOK_OUT, &tty->flags))) {
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
while (nr > 0) {
c = tty->ops->write(tty, b, nr);
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
schedule();
}
break_out:
__set_current_state(TASK_RUNNING);
remove_wait_queue(&tty->write_wait, &wait);
if (b - buf != nr && tty->fasync)
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
return (b - buf) ? b - buf : retval;
}
static unsigned int n_tty_poll(struct tty_struct *tty, struct file *file,
poll_table *wait)
{
unsigned int mask = 0;
poll_wait(file, &tty->read_wait, wait);
poll_wait(file, &tty->write_wait, wait);
if (input_available_p(tty, TIME_CHAR(tty) ? 0 : MIN_CHAR(tty)))
mask |= POLLIN | POLLRDNORM;
if (tty->packet && tty->link->ctrl_status)
mask |= POLLPRI | POLLIN | POLLRDNORM;
if (test_bit(TTY_OTHER_CLOSED, &tty->flags))
mask |= POLLHUP;
if (tty_hung_up_p(file))
mask |= POLLHUP;
if (!(mask & (POLLHUP | POLLIN | POLLRDNORM))) {
if (MIN_CHAR(tty) && !TIME_CHAR(tty))
tty->minimum_to_wake = MIN_CHAR(tty);
else
tty->minimum_to_wake = 1;
}
if (tty->ops->write && !tty_is_writelocked(tty) &&
tty_chars_in_buffer(tty) < WAKEUP_CHARS &&
tty_write_room(tty) > 0)
mask |= POLLOUT | POLLWRNORM;
return mask;
}
static unsigned long inq_canon(struct n_tty_data *ldata)
{
int nr, head, tail;
if (!ldata->canon_data)
return 0;
head = ldata->canon_head;
tail = ldata->read_tail;
nr = (head - tail) & (N_TTY_BUF_SIZE-1);
while (head != tail) {
if (test_bit(tail, ldata->read_flags) &&
ldata->read_buf[tail] == __DISABLED_CHAR)
nr--;
tail = (tail+1) & (N_TTY_BUF_SIZE-1);
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
retval = ldata->read_cnt;
if (L_ICANON(tty))
retval = inq_canon(ldata);
return put_user(retval, (unsigned int __user *) arg);
default:
return n_tty_ioctl_helper(tty, file, cmd, arg);
}
}
void n_tty_inherit_ops(struct tty_ldisc_ops *ops)
{
*ops = tty_ldisc_N_TTY;
ops->owner = NULL;
ops->refcount = ops->flags = 0;
}
