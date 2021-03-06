static irqreturn_t atari_keyboard_interrupt(int irq, void *dummy)
{
u_char acia_stat;
int scancode;
int break_flag;
repeat:
if (acia.mid_ctrl & ACIA_IRQ)
if (atari_MIDI_interrupt_hook)
atari_MIDI_interrupt_hook();
acia_stat = acia.key_ctrl;
if (!((acia_stat | acia.mid_ctrl) & ACIA_IRQ))
return IRQ_HANDLED;
if (acia_stat & ACIA_OVRN) {
printk(KERN_DEBUG "Keyboard overrun\n");
scancode = acia.key_data;
if (ikbd_self_test)
goto interpret_scancode;
else if (IS_SYNC_CODE(scancode)) {
kb_state.state = KEYBOARD;
goto interpret_scancode;
} else {
kb_state.state = RESYNC;
kb_state.len = 1;
goto repeat;
}
}
if (acia_stat & ACIA_RDRF) {
scancode = acia.key_data;
interpret_scancode:
switch (kb_state.state) {
case KEYBOARD:
switch (scancode) {
case 0xF7:
kb_state.state = AMOUSE;
kb_state.len = 0;
break;
case 0xF8:
case 0xF9:
case 0xFA:
case 0xFB:
kb_state.state = RMOUSE;
kb_state.len = 1;
kb_state.buf[0] = scancode;
break;
case 0xFC:
kb_state.state = CLOCK;
kb_state.len = 0;
break;
case 0xFE:
case 0xFF:
kb_state.state = JOYSTICK;
kb_state.len = 1;
kb_state.buf[0] = scancode;
break;
case 0xF1:
if (ikbd_self_test) {
++ikbd_self_test;
self_test_last_rcv = jiffies;
break;
}
default:
break_flag = scancode & BREAK_MASK;
scancode &= ~BREAK_MASK;
if (ikbd_self_test) {
int keyval, keytyp;
set_bit(scancode, broken_keys);
self_test_last_rcv = jiffies;
keyval = scancode;
keytyp = KTYP(keyval) - 0xf0;
keyval = KVAL(keyval);
printk(KERN_WARNING "Key with scancode %d ", scancode);
if (keytyp == KT_LATIN || keytyp == KT_LETTER) {
if (keyval < ' ')
printk("('^%c') ", keyval + '@');
else
printk("('%c') ", keyval);
}
printk("is broken -- will be ignored.\n");
break;
} else if (test_bit(scancode, broken_keys))
break;
if (atari_input_keyboard_interrupt_hook)
atari_input_keyboard_interrupt_hook((unsigned char)scancode, !break_flag);
break;
}
break;
case AMOUSE:
kb_state.buf[kb_state.len++] = scancode;
if (kb_state.len == 5) {
kb_state.state = KEYBOARD;
}
break;
case RMOUSE:
kb_state.buf[kb_state.len++] = scancode;
if (kb_state.len == 3) {
kb_state.state = KEYBOARD;
if (atari_input_mouse_interrupt_hook)
atari_input_mouse_interrupt_hook(kb_state.buf);
}
break;
case JOYSTICK:
kb_state.buf[1] = scancode;
kb_state.state = KEYBOARD;
#ifdef FIXED_ATARI_JOYSTICK
atari_joystick_interrupt(kb_state.buf);
#endif
break;
case CLOCK:
kb_state.buf[kb_state.len++] = scancode;
if (kb_state.len == 6) {
kb_state.state = KEYBOARD;
}
break;
case RESYNC:
if (kb_state.len <= 0 || IS_SYNC_CODE(scancode)) {
kb_state.state = KEYBOARD;
goto interpret_scancode;
}
kb_state.len--;
break;
}
}
#if 0
if (acia_stat & ACIA_CTS)
;
#endif
if (acia_stat & (ACIA_FE | ACIA_PE)) {
printk("Error in keyboard communication\n");
}
goto repeat;
}
void ikbd_write(const char *str, int len)
{
u_char acia_stat;
if ((len < 1) || (len > 7))
panic("ikbd: maximum string length exceeded");
while (len) {
acia_stat = acia.key_ctrl;
if (acia_stat & ACIA_TDRE) {
acia.key_data = *str++;
len--;
}
}
}
void ikbd_reset(void)
{
static const char cmd[2] = { 0x80, 0x01 };
ikbd_write(cmd, 2);
}
void ikbd_mouse_button_action(int mode)
{
char cmd[2] = { 0x07, mode };
ikbd_write(cmd, 2);
}
void ikbd_mouse_rel_pos(void)
{
static const char cmd[1] = { 0x08 };
ikbd_write(cmd, 1);
}
void ikbd_mouse_abs_pos(int xmax, int ymax)
{
char cmd[5] = { 0x09, xmax>>8, xmax&0xFF, ymax>>8, ymax&0xFF };
ikbd_write(cmd, 5);
}
void ikbd_mouse_kbd_mode(int dx, int dy)
{
char cmd[3] = { 0x0A, dx, dy };
ikbd_write(cmd, 3);
}
void ikbd_mouse_thresh(int x, int y)
{
char cmd[3] = { 0x0B, x, y };
ikbd_write(cmd, 3);
}
void ikbd_mouse_scale(int x, int y)
{
char cmd[3] = { 0x0C, x, y };
ikbd_write(cmd, 3);
}
void ikbd_mouse_pos_get(int *x, int *y)
{
static const char cmd[1] = { 0x0D };
ikbd_write(cmd, 1);
}
void ikbd_mouse_pos_set(int x, int y)
{
char cmd[6] = { 0x0E, 0x00, x>>8, x&0xFF, y>>8, y&0xFF };
ikbd_write(cmd, 6);
}
void ikbd_mouse_y0_bot(void)
{
static const char cmd[1] = { 0x0F };
ikbd_write(cmd, 1);
}
void ikbd_mouse_y0_top(void)
{
static const char cmd[1] = { 0x10 };
ikbd_write(cmd, 1);
}
void ikbd_mouse_disable(void)
{
static const char cmd[1] = { 0x12 };
ikbd_write(cmd, 1);
}
void ikbd_joystick_event_on(void)
{
static const char cmd[1] = { 0x14 };
ikbd_write(cmd, 1);
}
void ikbd_joystick_event_off(void)
{
static const char cmd[1] = { 0x15 };
ikbd_write(cmd, 1);
}
void ikbd_joystick_get_state(void)
{
static const char cmd[1] = { 0x16 };
ikbd_write(cmd, 1);
}
void ikbd_joystick_disable(void)
{
static const char cmd[1] = { 0x1A };
ikbd_write(cmd, 1);
}
int atari_keyb_init(void)
{
int error;
if (atari_keyb_done)
return 0;
kb_state.state = KEYBOARD;
kb_state.len = 0;
error = request_irq(IRQ_MFP_ACIA, atari_keyboard_interrupt, 0,
"keyboard,mouse,MIDI", atari_keyboard_interrupt);
if (error)
return error;
atari_turnoff_irq(IRQ_MFP_ACIA);
do {
acia.key_ctrl = ACIA_RESET |
((atari_switches & ATARI_SWITCH_IKBD) ?
ACIA_RHTID : 0);
(void)acia.key_ctrl;
(void)acia.key_data;
acia.mid_ctrl = ACIA_RESET |
((atari_switches & ATARI_SWITCH_MIDI) ?
ACIA_RHTID : 0);
(void)acia.mid_ctrl;
(void)acia.mid_data;
acia.key_ctrl = (ACIA_DIV64|ACIA_D8N1S|ACIA_RIE) |
((atari_switches & ATARI_SWITCH_IKBD) ?
ACIA_RHTID : ACIA_RLTID);
acia.mid_ctrl = ACIA_DIV16 | ACIA_D8N1S |
((atari_switches & ATARI_SWITCH_MIDI) ?
ACIA_RHTID : 0);
} while ((st_mfp.par_dt_reg & 0x10) == 0);
st_mfp.active_edge &= ~0x10;
atari_turnon_irq(IRQ_MFP_ACIA);
ikbd_self_test = 1;
ikbd_reset();
self_test_last_rcv = jiffies;
while (time_before(jiffies, self_test_last_rcv + HZ/4))
barrier();
if (ikbd_self_test == 1)
printk(KERN_ERR "WARNING: keyboard self test failed!\n");
ikbd_self_test = 0;
ikbd_mouse_disable();
ikbd_joystick_disable();
#ifdef FIXED_ATARI_JOYSTICK
atari_joystick_init();
#endif
atari_keyb_done = 1;
return 0;
}
