static inline int kbd_defleds(void)
{
return 0;
}
int register_keyboard_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&keyboard_notifier_list, nb);
}
int unregister_keyboard_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&keyboard_notifier_list, nb);
}
static int getkeycode_helper(struct input_handle *handle, void *data)
{
struct getset_keycode_data *d = data;
d->error = input_get_keycode(handle->dev, &d->ke);
return d->error == 0;
}
static int getkeycode(unsigned int scancode)
{
struct getset_keycode_data d = {
.ke = {
.flags = 0,
.len = sizeof(scancode),
.keycode = 0,
},
.error = -ENODEV,
};
memcpy(d.ke.scancode, &scancode, sizeof(scancode));
input_handler_for_each_handle(&kbd_handler, &d, getkeycode_helper);
return d.error ?: d.ke.keycode;
}
static int setkeycode_helper(struct input_handle *handle, void *data)
{
struct getset_keycode_data *d = data;
d->error = input_set_keycode(handle->dev, &d->ke);
return d->error == 0;
}
static int setkeycode(unsigned int scancode, unsigned int keycode)
{
struct getset_keycode_data d = {
.ke = {
.flags = 0,
.len = sizeof(scancode),
.keycode = keycode,
},
.error = -ENODEV,
};
memcpy(d.ke.scancode, &scancode, sizeof(scancode));
input_handler_for_each_handle(&kbd_handler, &d, setkeycode_helper);
return d.error;
}
static int kd_sound_helper(struct input_handle *handle, void *data)
{
unsigned int *hz = data;
struct input_dev *dev = handle->dev;
if (test_bit(EV_SND, dev->evbit)) {
if (test_bit(SND_TONE, dev->sndbit)) {
input_inject_event(handle, EV_SND, SND_TONE, *hz);
if (*hz)
return 0;
}
if (test_bit(SND_BELL, dev->sndbit))
input_inject_event(handle, EV_SND, SND_BELL, *hz ? 1 : 0);
}
return 0;
}
static void kd_nosound(unsigned long ignored)
{
static unsigned int zero;
input_handler_for_each_handle(&kbd_handler, &zero, kd_sound_helper);
}
void kd_mksound(unsigned int hz, unsigned int ticks)
{
del_timer_sync(&kd_mksound_timer);
input_handler_for_each_handle(&kbd_handler, &hz, kd_sound_helper);
if (hz && ticks)
mod_timer(&kd_mksound_timer, jiffies + ticks);
}
static int kbd_rate_helper(struct input_handle *handle, void *data)
{
struct input_dev *dev = handle->dev;
struct kbd_repeat *rep = data;
if (test_bit(EV_REP, dev->evbit)) {
if (rep[0].delay > 0)
input_inject_event(handle,
EV_REP, REP_DELAY, rep[0].delay);
if (rep[0].period > 0)
input_inject_event(handle,
EV_REP, REP_PERIOD, rep[0].period);
rep[1].delay = dev->rep[REP_DELAY];
rep[1].period = dev->rep[REP_PERIOD];
}
return 0;
}
int kbd_rate(struct kbd_repeat *rep)
{
struct kbd_repeat data[2] = { *rep };
input_handler_for_each_handle(&kbd_handler, data, kbd_rate_helper);
*rep = data[1];
return 0;
}
static void put_queue(struct vc_data *vc, int ch)
{
tty_insert_flip_char(&vc->port, ch, 0);
tty_schedule_flip(&vc->port);
}
static void puts_queue(struct vc_data *vc, char *cp)
{
while (*cp) {
tty_insert_flip_char(&vc->port, *cp, 0);
cp++;
}
tty_schedule_flip(&vc->port);
}
static void applkey(struct vc_data *vc, int key, char mode)
{
static char buf[] = { 0x1b, 'O', 0x00, 0x00 };
buf[1] = (mode ? 'O' : '[');
buf[2] = key;
puts_queue(vc, buf);
}
static void to_utf8(struct vc_data *vc, uint c)
{
if (c < 0x80)
put_queue(vc, c);
else if (c < 0x800) {
put_queue(vc, 0xc0 | (c >> 6));
put_queue(vc, 0x80 | (c & 0x3f));
} else if (c < 0x10000) {
if (c >= 0xD800 && c < 0xE000)
return;
if (c == 0xFFFF)
return;
put_queue(vc, 0xe0 | (c >> 12));
put_queue(vc, 0x80 | ((c >> 6) & 0x3f));
put_queue(vc, 0x80 | (c & 0x3f));
} else if (c < 0x110000) {
put_queue(vc, 0xf0 | (c >> 18));
put_queue(vc, 0x80 | ((c >> 12) & 0x3f));
put_queue(vc, 0x80 | ((c >> 6) & 0x3f));
put_queue(vc, 0x80 | (c & 0x3f));
}
}
static void do_compute_shiftstate(void)
{
unsigned int i, j, k, sym, val;
shift_state = 0;
memset(shift_down, 0, sizeof(shift_down));
for (i = 0; i < ARRAY_SIZE(key_down); i++) {
if (!key_down[i])
continue;
k = i * BITS_PER_LONG;
for (j = 0; j < BITS_PER_LONG; j++, k++) {
if (!test_bit(k, key_down))
continue;
sym = U(key_maps[0][k]);
if (KTYP(sym) != KT_SHIFT && KTYP(sym) != KT_SLOCK)
continue;
val = KVAL(sym);
if (val == KVAL(K_CAPSSHIFT))
val = KVAL(K_SHIFT);
shift_down[val]++;
shift_state |= (1 << val);
}
}
}
void compute_shiftstate(void)
{
unsigned long flags;
spin_lock_irqsave(&kbd_event_lock, flags);
do_compute_shiftstate();
spin_unlock_irqrestore(&kbd_event_lock, flags);
}
static unsigned int handle_diacr(struct vc_data *vc, unsigned int ch)
{
unsigned int d = diacr;
unsigned int i;
diacr = 0;
if ((d & ~0xff) == BRL_UC_ROW) {
if ((ch & ~0xff) == BRL_UC_ROW)
return d | ch;
} else {
for (i = 0; i < accent_table_size; i++)
if (accent_table[i].diacr == d && accent_table[i].base == ch)
return accent_table[i].result;
}
if (ch == ' ' || ch == (BRL_UC_ROW|0) || ch == d)
return d;
if (kbd->kbdmode == VC_UNICODE)
to_utf8(vc, d);
else {
int c = conv_uni_to_8bit(d);
if (c != -1)
put_queue(vc, c);
}
return ch;
}
static void fn_enter(struct vc_data *vc)
{
if (diacr) {
if (kbd->kbdmode == VC_UNICODE)
to_utf8(vc, diacr);
else {
int c = conv_uni_to_8bit(diacr);
if (c != -1)
put_queue(vc, c);
}
diacr = 0;
}
put_queue(vc, 13);
if (vc_kbd_mode(kbd, VC_CRLF))
put_queue(vc, 10);
}
static void fn_caps_toggle(struct vc_data *vc)
{
if (rep)
return;
chg_vc_kbd_led(kbd, VC_CAPSLOCK);
}
static void fn_caps_on(struct vc_data *vc)
{
if (rep)
return;
set_vc_kbd_led(kbd, VC_CAPSLOCK);
}
static void fn_show_ptregs(struct vc_data *vc)
{
struct pt_regs *regs = get_irq_regs();
if (regs)
show_regs(regs);
}
static void fn_hold(struct vc_data *vc)
{
struct tty_struct *tty = vc->port.tty;
if (rep || !tty)
return;
if (tty->stopped)
start_tty(tty);
else
stop_tty(tty);
}
static void fn_num(struct vc_data *vc)
{
if (vc_kbd_mode(kbd, VC_APPLIC))
applkey(vc, 'P', 1);
else
fn_bare_num(vc);
}
static void fn_bare_num(struct vc_data *vc)
{
if (!rep)
chg_vc_kbd_led(kbd, VC_NUMLOCK);
}
static void fn_lastcons(struct vc_data *vc)
{
set_console(last_console);
}
static void fn_dec_console(struct vc_data *vc)
{
int i, cur = fg_console;
if (want_console != -1)
cur = want_console;
for (i = cur - 1; i != cur; i--) {
if (i == -1)
i = MAX_NR_CONSOLES - 1;
if (vc_cons_allocated(i))
break;
}
set_console(i);
}
static void fn_inc_console(struct vc_data *vc)
{
int i, cur = fg_console;
if (want_console != -1)
cur = want_console;
for (i = cur+1; i != cur; i++) {
if (i == MAX_NR_CONSOLES)
i = 0;
if (vc_cons_allocated(i))
break;
}
set_console(i);
}
static void fn_send_intr(struct vc_data *vc)
{
tty_insert_flip_char(&vc->port, 0, TTY_BREAK);
tty_schedule_flip(&vc->port);
}
static void fn_scroll_forw(struct vc_data *vc)
{
scrollfront(vc, 0);
}
static void fn_scroll_back(struct vc_data *vc)
{
scrollback(vc, 0);
}
static void fn_show_mem(struct vc_data *vc)
{
show_mem(0);
}
static void fn_show_state(struct vc_data *vc)
{
show_state();
}
static void fn_boot_it(struct vc_data *vc)
{
ctrl_alt_del();
}
static void fn_compose(struct vc_data *vc)
{
dead_key_next = true;
}
static void fn_spawn_con(struct vc_data *vc)
{
spin_lock(&vt_spawn_con.lock);
if (vt_spawn_con.pid)
if (kill_pid(vt_spawn_con.pid, vt_spawn_con.sig, 1)) {
put_pid(vt_spawn_con.pid);
vt_spawn_con.pid = NULL;
}
spin_unlock(&vt_spawn_con.lock);
}
static void fn_SAK(struct vc_data *vc)
{
struct work_struct *SAK_work = &vc_cons[fg_console].SAK_work;
schedule_work(SAK_work);
}
static void fn_null(struct vc_data *vc)
{
do_compute_shiftstate();
}
static void k_ignore(struct vc_data *vc, unsigned char value, char up_flag)
{
}
static void k_spec(struct vc_data *vc, unsigned char value, char up_flag)
{
if (up_flag)
return;
if (value >= ARRAY_SIZE(fn_handler))
return;
if ((kbd->kbdmode == VC_RAW ||
kbd->kbdmode == VC_MEDIUMRAW ||
kbd->kbdmode == VC_OFF) &&
value != KVAL(K_SAK))
return;
fn_handler[value](vc);
}
static void k_lowercase(struct vc_data *vc, unsigned char value, char up_flag)
{
pr_err("k_lowercase was called - impossible\n");
}
static void k_unicode(struct vc_data *vc, unsigned int value, char up_flag)
{
if (up_flag)
return;
if (diacr)
value = handle_diacr(vc, value);
if (dead_key_next) {
dead_key_next = false;
diacr = value;
return;
}
if (kbd->kbdmode == VC_UNICODE)
to_utf8(vc, value);
else {
int c = conv_uni_to_8bit(value);
if (c != -1)
put_queue(vc, c);
}
}
static void k_deadunicode(struct vc_data *vc, unsigned int value, char up_flag)
{
if (up_flag)
return;
diacr = (diacr ? handle_diacr(vc, value) : value);
}
static void k_self(struct vc_data *vc, unsigned char value, char up_flag)
{
k_unicode(vc, conv_8bit_to_uni(value), up_flag);
}
static void k_dead2(struct vc_data *vc, unsigned char value, char up_flag)
{
k_deadunicode(vc, value, up_flag);
}
static void k_dead(struct vc_data *vc, unsigned char value, char up_flag)
{
static const unsigned char ret_diacr[NR_DEAD] = {'`', '\'', '^', '~', '"', ',' };
k_deadunicode(vc, ret_diacr[value], up_flag);
}
static void k_cons(struct vc_data *vc, unsigned char value, char up_flag)
{
if (up_flag)
return;
set_console(value);
}
static void k_fn(struct vc_data *vc, unsigned char value, char up_flag)
{
if (up_flag)
return;
if ((unsigned)value < ARRAY_SIZE(func_table)) {
if (func_table[value])
puts_queue(vc, func_table[value]);
} else
pr_err("k_fn called with value=%d\n", value);
}
static void k_cur(struct vc_data *vc, unsigned char value, char up_flag)
{
static const char cur_chars[] = "BDCA";
if (up_flag)
return;
applkey(vc, cur_chars[value], vc_kbd_mode(kbd, VC_CKMODE));
}
static void k_pad(struct vc_data *vc, unsigned char value, char up_flag)
{
static const char pad_chars[] = "0123456789+-*/\015,.?()#";
static const char app_map[] = "pqrstuvwxylSRQMnnmPQS";
if (up_flag)
return;
if (vc_kbd_mode(kbd, VC_APPLIC) && !shift_down[KG_SHIFT]) {
applkey(vc, app_map[value], 1);
return;
}
if (!vc_kbd_led(kbd, VC_NUMLOCK)) {
switch (value) {
case KVAL(K_PCOMMA):
case KVAL(K_PDOT):
k_fn(vc, KVAL(K_REMOVE), 0);
return;
case KVAL(K_P0):
k_fn(vc, KVAL(K_INSERT), 0);
return;
case KVAL(K_P1):
k_fn(vc, KVAL(K_SELECT), 0);
return;
case KVAL(K_P2):
k_cur(vc, KVAL(K_DOWN), 0);
return;
case KVAL(K_P3):
k_fn(vc, KVAL(K_PGDN), 0);
return;
case KVAL(K_P4):
k_cur(vc, KVAL(K_LEFT), 0);
return;
case KVAL(K_P6):
k_cur(vc, KVAL(K_RIGHT), 0);
return;
case KVAL(K_P7):
k_fn(vc, KVAL(K_FIND), 0);
return;
case KVAL(K_P8):
k_cur(vc, KVAL(K_UP), 0);
return;
case KVAL(K_P9):
k_fn(vc, KVAL(K_PGUP), 0);
return;
case KVAL(K_P5):
applkey(vc, 'G', vc_kbd_mode(kbd, VC_APPLIC));
return;
}
}
put_queue(vc, pad_chars[value]);
if (value == KVAL(K_PENTER) && vc_kbd_mode(kbd, VC_CRLF))
put_queue(vc, 10);
}
static void k_shift(struct vc_data *vc, unsigned char value, char up_flag)
{
int old_state = shift_state;
if (rep)
return;
if (value == KVAL(K_CAPSSHIFT)) {
value = KVAL(K_SHIFT);
if (!up_flag)
clr_vc_kbd_led(kbd, VC_CAPSLOCK);
}
if (up_flag) {
if (shift_down[value])
shift_down[value]--;
} else
shift_down[value]++;
if (shift_down[value])
shift_state |= (1 << value);
else
shift_state &= ~(1 << value);
if (up_flag && shift_state != old_state && npadch != -1) {
if (kbd->kbdmode == VC_UNICODE)
to_utf8(vc, npadch);
else
put_queue(vc, npadch & 0xff);
npadch = -1;
}
}
static void k_meta(struct vc_data *vc, unsigned char value, char up_flag)
{
if (up_flag)
return;
if (vc_kbd_mode(kbd, VC_META)) {
put_queue(vc, '\033');
put_queue(vc, value);
} else
put_queue(vc, value | 0x80);
}
static void k_ascii(struct vc_data *vc, unsigned char value, char up_flag)
{
int base;
if (up_flag)
return;
if (value < 10) {
base = 10;
} else {
value -= 10;
base = 16;
}
if (npadch == -1)
npadch = value;
else
npadch = npadch * base + value;
}
static void k_lock(struct vc_data *vc, unsigned char value, char up_flag)
{
if (up_flag || rep)
return;
chg_vc_kbd_lock(kbd, value);
}
static void k_slock(struct vc_data *vc, unsigned char value, char up_flag)
{
k_shift(vc, value, up_flag);
if (up_flag || rep)
return;
chg_vc_kbd_slock(kbd, value);
if (!key_maps[kbd->lockstate ^ kbd->slockstate]) {
kbd->slockstate = 0;
chg_vc_kbd_slock(kbd, value);
}
}
static void k_brlcommit(struct vc_data *vc, unsigned int pattern, char up_flag)
{
static unsigned long chords;
static unsigned committed;
if (!brl_nbchords)
k_deadunicode(vc, BRL_UC_ROW | pattern, up_flag);
else {
committed |= pattern;
chords++;
if (chords == brl_nbchords) {
k_unicode(vc, BRL_UC_ROW | committed, up_flag);
chords = 0;
committed = 0;
}
}
}
static void k_brl(struct vc_data *vc, unsigned char value, char up_flag)
{
static unsigned pressed, committing;
static unsigned long releasestart;
if (kbd->kbdmode != VC_UNICODE) {
if (!up_flag)
pr_warning("keyboard mode must be unicode for braille patterns\n");
return;
}
if (!value) {
k_unicode(vc, BRL_UC_ROW, up_flag);
return;
}
if (value > 8)
return;
if (!up_flag) {
pressed |= 1 << (value - 1);
if (!brl_timeout)
committing = pressed;
} else if (brl_timeout) {
if (!committing ||
time_after(jiffies,
releasestart + msecs_to_jiffies(brl_timeout))) {
committing = pressed;
releasestart = jiffies;
}
pressed &= ~(1 << (value - 1));
if (!pressed && committing) {
k_brlcommit(vc, committing, 0);
committing = 0;
}
} else {
if (committing) {
k_brlcommit(vc, committing, 0);
committing = 0;
}
pressed &= ~(1 << (value - 1));
}
}
static unsigned char getledstate(void)
{
return ledstate;
}
void setledstate(struct kbd_struct *kbd, unsigned int led)
{
unsigned long flags;
spin_lock_irqsave(&led_lock, flags);
if (!(led & ~7)) {
ledioctl = led;
kbd->ledmode = LED_SHOW_IOCTL;
} else
kbd->ledmode = LED_SHOW_FLAGS;
set_leds();
spin_unlock_irqrestore(&led_lock, flags);
}
static inline unsigned char getleds(void)
{
struct kbd_struct *kbd = kbd_table + fg_console;
unsigned char leds;
int i;
if (kbd->ledmode == LED_SHOW_IOCTL)
return ledioctl;
leds = kbd->ledflagstate;
if (kbd->ledmode == LED_SHOW_MEM) {
for (i = 0; i < 3; i++)
if (ledptrs[i].valid) {
if (*ledptrs[i].addr & ledptrs[i].mask)
leds |= (1 << i);
else
leds &= ~(1 << i);
}
}
return leds;
}
static int kbd_update_leds_helper(struct input_handle *handle, void *data)
{
unsigned char leds = *(unsigned char *)data;
if (test_bit(EV_LED, handle->dev->evbit)) {
input_inject_event(handle, EV_LED, LED_SCROLLL, !!(leds & 0x01));
input_inject_event(handle, EV_LED, LED_NUML, !!(leds & 0x02));
input_inject_event(handle, EV_LED, LED_CAPSL, !!(leds & 0x04));
input_inject_event(handle, EV_SYN, SYN_REPORT, 0);
}
return 0;
}
int vt_get_leds(int console, int flag)
{
struct kbd_struct * kbd = kbd_table + console;
int ret;
unsigned long flags;
spin_lock_irqsave(&led_lock, flags);
ret = vc_kbd_led(kbd, flag);
spin_unlock_irqrestore(&led_lock, flags);
return ret;
}
void vt_set_led_state(int console, int leds)
{
struct kbd_struct * kbd = kbd_table + console;
setledstate(kbd, leds);
}
void vt_kbd_con_start(int console)
{
struct kbd_struct * kbd = kbd_table + console;
unsigned long flags;
spin_lock_irqsave(&led_lock, flags);
clr_vc_kbd_led(kbd, VC_SCROLLOCK);
set_leds();
spin_unlock_irqrestore(&led_lock, flags);
}
void vt_kbd_con_stop(int console)
{
struct kbd_struct * kbd = kbd_table + console;
unsigned long flags;
spin_lock_irqsave(&led_lock, flags);
set_vc_kbd_led(kbd, VC_SCROLLOCK);
set_leds();
spin_unlock_irqrestore(&led_lock, flags);
}
static void kbd_bh(unsigned long dummy)
{
unsigned char leds;
unsigned long flags;
spin_lock_irqsave(&led_lock, flags);
leds = getleds();
spin_unlock_irqrestore(&led_lock, flags);
if (leds != ledstate) {
input_handler_for_each_handle(&kbd_handler, &leds,
kbd_update_leds_helper);
ledstate = leds;
}
}
static int emulate_raw(struct vc_data *vc, unsigned int keycode,
unsigned char up_flag)
{
int code;
switch (keycode) {
case KEY_PAUSE:
put_queue(vc, 0xe1);
put_queue(vc, 0x1d | up_flag);
put_queue(vc, 0x45 | up_flag);
break;
case KEY_HANGEUL:
if (!up_flag)
put_queue(vc, 0xf2);
break;
case KEY_HANJA:
if (!up_flag)
put_queue(vc, 0xf1);
break;
case KEY_SYSRQ:
if (test_bit(KEY_LEFTALT, key_down) ||
test_bit(KEY_RIGHTALT, key_down)) {
put_queue(vc, 0x54 | up_flag);
} else {
put_queue(vc, 0xe0);
put_queue(vc, 0x2a | up_flag);
put_queue(vc, 0xe0);
put_queue(vc, 0x37 | up_flag);
}
break;
default:
if (keycode > 255)
return -1;
code = x86_keycodes[keycode];
if (!code)
return -1;
if (code & 0x100)
put_queue(vc, 0xe0);
put_queue(vc, (code & 0x7f) | up_flag);
break;
}
return 0;
}
static int emulate_raw(struct vc_data *vc, unsigned int keycode, unsigned char up_flag)
{
if (keycode > 127)
return -1;
put_queue(vc, keycode | up_flag);
return 0;
}
static void kbd_rawcode(unsigned char data)
{
struct vc_data *vc = vc_cons[fg_console].d;
kbd = kbd_table + vc->vc_num;
if (kbd->kbdmode == VC_RAW)
put_queue(vc, data);
}
static void kbd_keycode(unsigned int keycode, int down, int hw_raw)
{
struct vc_data *vc = vc_cons[fg_console].d;
unsigned short keysym, *key_map;
unsigned char type;
bool raw_mode;
struct tty_struct *tty;
int shift_final;
struct keyboard_notifier_param param = { .vc = vc, .value = keycode, .down = down };
int rc;
tty = vc->port.tty;
if (tty && (!tty->driver_data)) {
tty->driver_data = vc;
}
kbd = kbd_table + vc->vc_num;
#ifdef CONFIG_SPARC
if (keycode == KEY_STOP)
sparc_l1_a_state = down;
#endif
rep = (down == 2);
raw_mode = (kbd->kbdmode == VC_RAW);
if (raw_mode && !hw_raw)
if (emulate_raw(vc, keycode, !down << 7))
if (keycode < BTN_MISC && printk_ratelimit())
pr_warning("can't emulate rawmode for keycode %d\n",
keycode);
#ifdef CONFIG_SPARC
if (keycode == KEY_A && sparc_l1_a_state) {
sparc_l1_a_state = false;
sun_do_break();
}
#endif
if (kbd->kbdmode == VC_MEDIUMRAW) {
if (keycode < 128) {
put_queue(vc, keycode | (!down << 7));
} else {
put_queue(vc, !down << 7);
put_queue(vc, (keycode >> 7) | 0x80);
put_queue(vc, keycode | 0x80);
}
raw_mode = true;
}
if (down)
set_bit(keycode, key_down);
else
clear_bit(keycode, key_down);
if (rep &&
(!vc_kbd_mode(kbd, VC_REPEAT) ||
(tty && !L_ECHO(tty) && tty_chars_in_buffer(tty)))) {
return;
}
param.shift = shift_final = (shift_state | kbd->slockstate) ^ kbd->lockstate;
param.ledstate = kbd->ledflagstate;
key_map = key_maps[shift_final];
rc = atomic_notifier_call_chain(&keyboard_notifier_list,
KBD_KEYCODE, &param);
if (rc == NOTIFY_STOP || !key_map) {
atomic_notifier_call_chain(&keyboard_notifier_list,
KBD_UNBOUND_KEYCODE, &param);
do_compute_shiftstate();
kbd->slockstate = 0;
return;
}
if (keycode < NR_KEYS)
keysym = key_map[keycode];
else if (keycode >= KEY_BRL_DOT1 && keycode <= KEY_BRL_DOT8)
keysym = U(K(KT_BRL, keycode - KEY_BRL_DOT1 + 1));
else
return;
type = KTYP(keysym);
if (type < 0xf0) {
param.value = keysym;
rc = atomic_notifier_call_chain(&keyboard_notifier_list,
KBD_UNICODE, &param);
if (rc != NOTIFY_STOP)
if (down && !raw_mode)
to_utf8(vc, keysym);
return;
}
type -= 0xf0;
if (type == KT_LETTER) {
type = KT_LATIN;
if (vc_kbd_led(kbd, VC_CAPSLOCK)) {
key_map = key_maps[shift_final ^ (1 << KG_SHIFT)];
if (key_map)
keysym = key_map[keycode];
}
}
param.value = keysym;
rc = atomic_notifier_call_chain(&keyboard_notifier_list,
KBD_KEYSYM, &param);
if (rc == NOTIFY_STOP)
return;
if ((raw_mode || kbd->kbdmode == VC_OFF) && type != KT_SPEC && type != KT_SHIFT)
return;
(*k_handler[type])(vc, keysym & 0xff, !down);
param.ledstate = kbd->ledflagstate;
atomic_notifier_call_chain(&keyboard_notifier_list, KBD_POST_KEYSYM, &param);
if (type != KT_SLOCK)
kbd->slockstate = 0;
}
static void kbd_event(struct input_handle *handle, unsigned int event_type,
unsigned int event_code, int value)
{
spin_lock(&kbd_event_lock);
if (event_type == EV_MSC && event_code == MSC_RAW && HW_RAW(handle->dev))
kbd_rawcode(value);
if (event_type == EV_KEY)
kbd_keycode(event_code, value, HW_RAW(handle->dev));
spin_unlock(&kbd_event_lock);
tasklet_schedule(&keyboard_tasklet);
do_poke_blanked_console = 1;
schedule_console_callback();
}
static bool kbd_match(struct input_handler *handler, struct input_dev *dev)
{
int i;
if (test_bit(EV_SND, dev->evbit))
return true;
if (test_bit(EV_KEY, dev->evbit)) {
for (i = KEY_RESERVED; i < BTN_MISC; i++)
if (test_bit(i, dev->keybit))
return true;
for (i = KEY_BRL_DOT1; i <= KEY_BRL_DOT10; i++)
if (test_bit(i, dev->keybit))
return true;
}
return false;
}
static int kbd_connect(struct input_handler *handler, struct input_dev *dev,
const struct input_device_id *id)
{
struct input_handle *handle;
int error;
handle = kzalloc(sizeof(struct input_handle), GFP_KERNEL);
if (!handle)
return -ENOMEM;
handle->dev = dev;
handle->handler = handler;
handle->name = "kbd";
error = input_register_handle(handle);
if (error)
goto err_free_handle;
error = input_open_device(handle);
if (error)
goto err_unregister_handle;
return 0;
err_unregister_handle:
input_unregister_handle(handle);
err_free_handle:
kfree(handle);
return error;
}
static void kbd_disconnect(struct input_handle *handle)
{
input_close_device(handle);
input_unregister_handle(handle);
kfree(handle);
}
static void kbd_start(struct input_handle *handle)
{
tasklet_disable(&keyboard_tasklet);
if (ledstate != 0xff)
kbd_update_leds_helper(handle, &ledstate);
tasklet_enable(&keyboard_tasklet);
}
int __init kbd_init(void)
{
int i;
int error;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
kbd_table[i].ledflagstate = kbd_defleds();
kbd_table[i].default_ledflagstate = kbd_defleds();
kbd_table[i].ledmode = LED_SHOW_FLAGS;
kbd_table[i].lockstate = KBD_DEFLOCK;
kbd_table[i].slockstate = 0;
kbd_table[i].modeflags = KBD_DEFMODE;
kbd_table[i].kbdmode = default_utf8 ? VC_UNICODE : VC_XLATE;
}
error = input_register_handler(&kbd_handler);
if (error)
return error;
tasklet_enable(&keyboard_tasklet);
tasklet_schedule(&keyboard_tasklet);
return 0;
}
int vt_do_diacrit(unsigned int cmd, void __user *up, int perm)
{
struct kbdiacrs __user *a = up;
unsigned long flags;
int asize;
int ret = 0;
switch (cmd) {
case KDGKBDIACR:
{
struct kbdiacr *diacr;
int i;
diacr = kmalloc(MAX_DIACR * sizeof(struct kbdiacr),
GFP_KERNEL);
if (diacr == NULL)
return -ENOMEM;
spin_lock_irqsave(&kbd_event_lock, flags);
asize = accent_table_size;
for (i = 0; i < asize; i++) {
diacr[i].diacr = conv_uni_to_8bit(
accent_table[i].diacr);
diacr[i].base = conv_uni_to_8bit(
accent_table[i].base);
diacr[i].result = conv_uni_to_8bit(
accent_table[i].result);
}
spin_unlock_irqrestore(&kbd_event_lock, flags);
if (put_user(asize, &a->kb_cnt))
ret = -EFAULT;
else if (copy_to_user(a->kbdiacr, diacr,
asize * sizeof(struct kbdiacr)))
ret = -EFAULT;
kfree(diacr);
return ret;
}
case KDGKBDIACRUC:
{
struct kbdiacrsuc __user *a = up;
void *buf;
buf = kmalloc(MAX_DIACR * sizeof(struct kbdiacruc),
GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
spin_lock_irqsave(&kbd_event_lock, flags);
asize = accent_table_size;
memcpy(buf, accent_table, asize * sizeof(struct kbdiacruc));
spin_unlock_irqrestore(&kbd_event_lock, flags);
if (put_user(asize, &a->kb_cnt))
ret = -EFAULT;
else if (copy_to_user(a->kbdiacruc, buf,
asize*sizeof(struct kbdiacruc)))
ret = -EFAULT;
kfree(buf);
return ret;
}
case KDSKBDIACR:
{
struct kbdiacrs __user *a = up;
struct kbdiacr *diacr = NULL;
unsigned int ct;
int i;
if (!perm)
return -EPERM;
if (get_user(ct, &a->kb_cnt))
return -EFAULT;
if (ct >= MAX_DIACR)
return -EINVAL;
if (ct) {
diacr = kmalloc(sizeof(struct kbdiacr) * ct,
GFP_KERNEL);
if (diacr == NULL)
return -ENOMEM;
if (copy_from_user(diacr, a->kbdiacr,
sizeof(struct kbdiacr) * ct)) {
kfree(diacr);
return -EFAULT;
}
}
spin_lock_irqsave(&kbd_event_lock, flags);
accent_table_size = ct;
for (i = 0; i < ct; i++) {
accent_table[i].diacr =
conv_8bit_to_uni(diacr[i].diacr);
accent_table[i].base =
conv_8bit_to_uni(diacr[i].base);
accent_table[i].result =
conv_8bit_to_uni(diacr[i].result);
}
spin_unlock_irqrestore(&kbd_event_lock, flags);
kfree(diacr);
return 0;
}
case KDSKBDIACRUC:
{
struct kbdiacrsuc __user *a = up;
unsigned int ct;
void *buf = NULL;
if (!perm)
return -EPERM;
if (get_user(ct, &a->kb_cnt))
return -EFAULT;
if (ct >= MAX_DIACR)
return -EINVAL;
if (ct) {
buf = kmalloc(ct * sizeof(struct kbdiacruc),
GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
if (copy_from_user(buf, a->kbdiacruc,
ct * sizeof(struct kbdiacruc))) {
kfree(buf);
return -EFAULT;
}
}
spin_lock_irqsave(&kbd_event_lock, flags);
if (ct)
memcpy(accent_table, buf,
ct * sizeof(struct kbdiacruc));
accent_table_size = ct;
spin_unlock_irqrestore(&kbd_event_lock, flags);
kfree(buf);
return 0;
}
}
return ret;
}
int vt_do_kdskbmode(int console, unsigned int arg)
{
struct kbd_struct * kbd = kbd_table + console;
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&kbd_event_lock, flags);
switch(arg) {
case K_RAW:
kbd->kbdmode = VC_RAW;
break;
case K_MEDIUMRAW:
kbd->kbdmode = VC_MEDIUMRAW;
break;
case K_XLATE:
kbd->kbdmode = VC_XLATE;
do_compute_shiftstate();
break;
case K_UNICODE:
kbd->kbdmode = VC_UNICODE;
do_compute_shiftstate();
break;
case K_OFF:
kbd->kbdmode = VC_OFF;
break;
default:
ret = -EINVAL;
}
spin_unlock_irqrestore(&kbd_event_lock, flags);
return ret;
}
int vt_do_kdskbmeta(int console, unsigned int arg)
{
struct kbd_struct * kbd = kbd_table + console;
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&kbd_event_lock, flags);
switch(arg) {
case K_METABIT:
clr_vc_kbd_mode(kbd, VC_META);
break;
case K_ESCPREFIX:
set_vc_kbd_mode(kbd, VC_META);
break;
default:
ret = -EINVAL;
}
spin_unlock_irqrestore(&kbd_event_lock, flags);
return ret;
}
int vt_do_kbkeycode_ioctl(int cmd, struct kbkeycode __user *user_kbkc,
int perm)
{
struct kbkeycode tmp;
int kc = 0;
if (copy_from_user(&tmp, user_kbkc, sizeof(struct kbkeycode)))
return -EFAULT;
switch (cmd) {
case KDGETKEYCODE:
kc = getkeycode(tmp.scancode);
if (kc >= 0)
kc = put_user(kc, &user_kbkc->keycode);
break;
case KDSETKEYCODE:
if (!perm)
return -EPERM;
kc = setkeycode(tmp.scancode, tmp.keycode);
break;
}
return kc;
}
int vt_do_kdsk_ioctl(int cmd, struct kbentry __user *user_kbe, int perm,
int console)
{
struct kbd_struct * kbd = kbd_table + console;
struct kbentry tmp;
ushort *key_map, *new_map, val, ov;
unsigned long flags;
if (copy_from_user(&tmp, user_kbe, sizeof(struct kbentry)))
return -EFAULT;
if (!capable(CAP_SYS_TTY_CONFIG))
perm = 0;
switch (cmd) {
case KDGKBENT:
spin_lock_irqsave(&kbd_event_lock, flags);
key_map = key_maps[s];
if (key_map) {
val = U(key_map[i]);
if (kbd->kbdmode != VC_UNICODE && KTYP(val) >= NR_TYPES)
val = K_HOLE;
} else
val = (i ? K_HOLE : K_NOSUCHMAP);
spin_unlock_irqrestore(&kbd_event_lock, flags);
return put_user(val, &user_kbe->kb_value);
case KDSKBENT:
if (!perm)
return -EPERM;
if (!i && v == K_NOSUCHMAP) {
spin_lock_irqsave(&kbd_event_lock, flags);
key_map = key_maps[s];
if (s && key_map) {
key_maps[s] = NULL;
if (key_map[0] == U(K_ALLOCATED)) {
kfree(key_map);
keymap_count--;
}
}
spin_unlock_irqrestore(&kbd_event_lock, flags);
break;
}
if (KTYP(v) < NR_TYPES) {
if (KVAL(v) > max_vals[KTYP(v)])
return -EINVAL;
} else
if (kbd->kbdmode != VC_UNICODE)
return -EINVAL;
#if !defined(__mc68000__) && !defined(__powerpc__)
if (!i)
break;
#endif
new_map = kmalloc(sizeof(plain_map), GFP_KERNEL);
if (!new_map)
return -ENOMEM;
spin_lock_irqsave(&kbd_event_lock, flags);
key_map = key_maps[s];
if (key_map == NULL) {
int j;
if (keymap_count >= MAX_NR_OF_USER_KEYMAPS &&
!capable(CAP_SYS_RESOURCE)) {
spin_unlock_irqrestore(&kbd_event_lock, flags);
kfree(new_map);
return -EPERM;
}
key_maps[s] = new_map;
key_map = new_map;
key_map[0] = U(K_ALLOCATED);
for (j = 1; j < NR_KEYS; j++)
key_map[j] = U(K_HOLE);
keymap_count++;
} else
kfree(new_map);
ov = U(key_map[i]);
if (v == ov)
goto out;
if (((ov == K_SAK) || (v == K_SAK)) && !capable(CAP_SYS_ADMIN)) {
spin_unlock_irqrestore(&kbd_event_lock, flags);
return -EPERM;
}
key_map[i] = U(v);
if (!s && (KTYP(ov) == KT_SHIFT || KTYP(v) == KT_SHIFT))
do_compute_shiftstate();
out:
spin_unlock_irqrestore(&kbd_event_lock, flags);
break;
}
return 0;
}
int vt_do_kdgkb_ioctl(int cmd, struct kbsentry __user *user_kdgkb, int perm)
{
struct kbsentry *kbs;
char *p;
u_char *q;
u_char __user *up;
int sz;
int delta;
char *first_free, *fj, *fnw;
int i, j, k;
int ret;
if (!capable(CAP_SYS_TTY_CONFIG))
perm = 0;
kbs = kmalloc(sizeof(*kbs), GFP_KERNEL);
if (!kbs) {
ret = -ENOMEM;
goto reterr;
}
if (copy_from_user(kbs, user_kdgkb, sizeof(struct kbsentry))) {
ret = -EFAULT;
goto reterr;
}
kbs->kb_string[sizeof(kbs->kb_string)-1] = '\0';
i = kbs->kb_func;
switch (cmd) {
case KDGKBSENT:
sz = sizeof(kbs->kb_string) - 1;
up = user_kdgkb->kb_string;
p = func_table[i];
if(p)
for ( ; *p && sz; p++, sz--)
if (put_user(*p, up++)) {
ret = -EFAULT;
goto reterr;
}
if (put_user('\0', up)) {
ret = -EFAULT;
goto reterr;
}
kfree(kbs);
return ((p && *p) ? -EOVERFLOW : 0);
case KDSKBSENT:
if (!perm) {
ret = -EPERM;
goto reterr;
}
q = func_table[i];
first_free = funcbufptr + (funcbufsize - funcbufleft);
for (j = i+1; j < MAX_NR_FUNC && !func_table[j]; j++)
;
if (j < MAX_NR_FUNC)
fj = func_table[j];
else
fj = first_free;
delta = (q ? -strlen(q) : 1) + strlen(kbs->kb_string);
if (delta <= funcbufleft) {
if (j < MAX_NR_FUNC) {
memmove(fj + delta, fj, first_free - fj);
for (k = j; k < MAX_NR_FUNC; k++)
if (func_table[k])
func_table[k] += delta;
}
if (!q)
func_table[i] = fj;
funcbufleft -= delta;
} else {
sz = 256;
while (sz < funcbufsize - funcbufleft + delta)
sz <<= 1;
fnw = kmalloc(sz, GFP_KERNEL);
if(!fnw) {
ret = -ENOMEM;
goto reterr;
}
if (!q)
func_table[i] = fj;
if (fj > funcbufptr)
memmove(fnw, funcbufptr, fj - funcbufptr);
for (k = 0; k < j; k++)
if (func_table[k])
func_table[k] = fnw + (func_table[k] - funcbufptr);
if (first_free > fj) {
memmove(fnw + (fj - funcbufptr) + delta, fj, first_free - fj);
for (k = j; k < MAX_NR_FUNC; k++)
if (func_table[k])
func_table[k] = fnw + (func_table[k] - funcbufptr) + delta;
}
if (funcbufptr != func_buf)
kfree(funcbufptr);
funcbufptr = fnw;
funcbufleft = funcbufleft - delta + sz - funcbufsize;
funcbufsize = sz;
}
strcpy(func_table[i], kbs->kb_string);
break;
}
ret = 0;
reterr:
kfree(kbs);
return ret;
}
int vt_do_kdskled(int console, int cmd, unsigned long arg, int perm)
{
struct kbd_struct * kbd = kbd_table + console;
unsigned long flags;
unsigned char ucval;
switch(cmd) {
case KDGKBLED:
spin_lock_irqsave(&kbd_event_lock, flags);
ucval = kbd->ledflagstate | (kbd->default_ledflagstate << 4);
spin_unlock_irqrestore(&kbd_event_lock, flags);
return put_user(ucval, (char __user *)arg);
case KDSKBLED:
if (!perm)
return -EPERM;
if (arg & ~0x77)
return -EINVAL;
spin_lock_irqsave(&led_lock, flags);
kbd->ledflagstate = (arg & 7);
kbd->default_ledflagstate = ((arg >> 4) & 7);
set_leds();
spin_unlock_irqrestore(&led_lock, flags);
return 0;
case KDGETLED:
ucval = getledstate();
return put_user(ucval, (char __user *)arg);
case KDSETLED:
if (!perm)
return -EPERM;
setledstate(kbd, arg);
return 0;
}
return -ENOIOCTLCMD;
}
int vt_do_kdgkbmode(int console)
{
struct kbd_struct * kbd = kbd_table + console;
switch (kbd->kbdmode) {
case VC_RAW:
return K_RAW;
case VC_MEDIUMRAW:
return K_MEDIUMRAW;
case VC_UNICODE:
return K_UNICODE;
case VC_OFF:
return K_OFF;
default:
return K_XLATE;
}
}
int vt_do_kdgkbmeta(int console)
{
struct kbd_struct * kbd = kbd_table + console;
return vc_kbd_mode(kbd, VC_META) ? K_ESCPREFIX : K_METABIT;
}
void vt_reset_unicode(int console)
{
unsigned long flags;
spin_lock_irqsave(&kbd_event_lock, flags);
kbd_table[console].kbdmode = default_utf8 ? VC_UNICODE : VC_XLATE;
spin_unlock_irqrestore(&kbd_event_lock, flags);
}
int vt_get_shift_state(void)
{
return shift_state;
}
void vt_reset_keyboard(int console)
{
struct kbd_struct * kbd = kbd_table + console;
unsigned long flags;
spin_lock_irqsave(&kbd_event_lock, flags);
set_vc_kbd_mode(kbd, VC_REPEAT);
clr_vc_kbd_mode(kbd, VC_CKMODE);
clr_vc_kbd_mode(kbd, VC_APPLIC);
clr_vc_kbd_mode(kbd, VC_CRLF);
kbd->lockstate = 0;
kbd->slockstate = 0;
spin_lock(&led_lock);
kbd->ledmode = LED_SHOW_FLAGS;
kbd->ledflagstate = kbd->default_ledflagstate;
spin_unlock(&led_lock);
spin_unlock_irqrestore(&kbd_event_lock, flags);
}
int vt_get_kbd_mode_bit(int console, int bit)
{
struct kbd_struct * kbd = kbd_table + console;
return vc_kbd_mode(kbd, bit);
}
void vt_set_kbd_mode_bit(int console, int bit)
{
struct kbd_struct * kbd = kbd_table + console;
unsigned long flags;
spin_lock_irqsave(&kbd_event_lock, flags);
set_vc_kbd_mode(kbd, bit);
spin_unlock_irqrestore(&kbd_event_lock, flags);
}
void vt_clr_kbd_mode_bit(int console, int bit)
{
struct kbd_struct * kbd = kbd_table + console;
unsigned long flags;
spin_lock_irqsave(&kbd_event_lock, flags);
clr_vc_kbd_mode(kbd, bit);
spin_unlock_irqrestore(&kbd_event_lock, flags);
}
