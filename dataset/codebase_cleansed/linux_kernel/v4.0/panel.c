static int set_data_bits(void)
{
int val, bit;
val = r_dtr(pprt);
for (bit = 0; bit < LCD_BITS; bit++)
val &= lcd_bits[LCD_PORT_D][bit][BIT_MSK];
val |= lcd_bits[LCD_PORT_D][LCD_BIT_E][bits.e]
| lcd_bits[LCD_PORT_D][LCD_BIT_RS][bits.rs]
| lcd_bits[LCD_PORT_D][LCD_BIT_RW][bits.rw]
| lcd_bits[LCD_PORT_D][LCD_BIT_BL][bits.bl]
| lcd_bits[LCD_PORT_D][LCD_BIT_CL][bits.cl]
| lcd_bits[LCD_PORT_D][LCD_BIT_DA][bits.da];
w_dtr(pprt, val);
return val;
}
static int set_ctrl_bits(void)
{
int val, bit;
val = r_ctr(pprt);
for (bit = 0; bit < LCD_BITS; bit++)
val &= lcd_bits[LCD_PORT_C][bit][BIT_MSK];
val |= lcd_bits[LCD_PORT_C][LCD_BIT_E][bits.e]
| lcd_bits[LCD_PORT_C][LCD_BIT_RS][bits.rs]
| lcd_bits[LCD_PORT_C][LCD_BIT_RW][bits.rw]
| lcd_bits[LCD_PORT_C][LCD_BIT_BL][bits.bl]
| lcd_bits[LCD_PORT_C][LCD_BIT_CL][bits.cl]
| lcd_bits[LCD_PORT_C][LCD_BIT_DA][bits.da];
w_ctr(pprt, val);
return val;
}
static void panel_set_bits(void)
{
set_data_bits();
set_ctrl_bits();
}
static void pin_to_bits(int pin, unsigned char *d_val, unsigned char *c_val)
{
int d_bit, c_bit, inv;
d_val[0] = 0;
c_val[0] = 0;
d_val[1] = 0;
c_val[1] = 0;
d_val[2] = 0xFF;
c_val[2] = 0xFF;
if (pin == 0)
return;
inv = (pin < 0);
if (inv)
pin = -pin;
d_bit = 0;
c_bit = 0;
switch (pin) {
case PIN_STROBE:
c_bit = PNL_PSTROBE;
inv = !inv;
break;
case PIN_D0...PIN_D7:
d_bit = 1 << (pin - 2);
break;
case PIN_AUTOLF:
c_bit = PNL_PAUTOLF;
inv = !inv;
break;
case PIN_INITP:
c_bit = PNL_PINITP;
break;
case PIN_SELECP:
c_bit = PNL_PSELECP;
inv = !inv;
break;
default:
break;
}
if (c_bit) {
c_val[2] &= ~c_bit;
c_val[!inv] = c_bit;
} else if (d_bit) {
d_val[2] &= ~d_bit;
d_val[!inv] = d_bit;
}
}
static void long_sleep(int ms)
{
if (in_interrupt()) {
mdelay(ms);
} else {
__set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout((ms * HZ + 999) / 1000);
}
}
static void lcd_send_serial(int byte)
{
int bit;
for (bit = 0; bit < 8; bit++) {
bits.cl = BIT_CLR;
panel_set_bits();
bits.da = byte & 1;
panel_set_bits();
udelay(2);
bits.cl = BIT_SET;
panel_set_bits();
udelay(1);
byte >>= 1;
}
}
static void lcd_backlight(int on)
{
if (lcd.pins.bl == PIN_NONE)
return;
spin_lock_irq(&pprt_lock);
bits.bl = on;
panel_set_bits();
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_cmd_s(int cmd)
{
spin_lock_irq(&pprt_lock);
lcd_send_serial(0x1F);
lcd_send_serial(cmd & 0x0F);
lcd_send_serial((cmd >> 4) & 0x0F);
udelay(40);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_data_s(int data)
{
spin_lock_irq(&pprt_lock);
lcd_send_serial(0x5F);
lcd_send_serial(data & 0x0F);
lcd_send_serial((data >> 4) & 0x0F);
udelay(40);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_cmd_p8(int cmd)
{
spin_lock_irq(&pprt_lock);
w_dtr(pprt, cmd);
udelay(20);
bits.e = BIT_SET;
bits.rs = BIT_CLR;
bits.rw = BIT_CLR;
set_ctrl_bits();
udelay(40);
bits.e = BIT_CLR;
set_ctrl_bits();
udelay(120);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_data_p8(int data)
{
spin_lock_irq(&pprt_lock);
w_dtr(pprt, data);
udelay(20);
bits.e = BIT_SET;
bits.rs = BIT_SET;
bits.rw = BIT_CLR;
set_ctrl_bits();
udelay(40);
bits.e = BIT_CLR;
set_ctrl_bits();
udelay(45);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_cmd_tilcd(int cmd)
{
spin_lock_irq(&pprt_lock);
w_ctr(pprt, cmd);
udelay(60);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_data_tilcd(int data)
{
spin_lock_irq(&pprt_lock);
w_dtr(pprt, data);
udelay(60);
spin_unlock_irq(&pprt_lock);
}
static void lcd_gotoxy(void)
{
lcd_write_cmd(LCD_CMD_SET_DDRAM_ADDR
| (lcd.addr.y ? lcd.hwidth : 0)
| ((lcd.addr.x < lcd.bwidth) ? lcd.addr.x &
(lcd.hwidth - 1) : lcd.bwidth - 1));
}
static void lcd_print(char c)
{
if (lcd.addr.x < lcd.bwidth) {
if (lcd_char_conv != NULL)
c = lcd_char_conv[(unsigned char)c];
lcd_write_data(c);
lcd.addr.x++;
}
if (lcd.addr.x == lcd.bwidth)
lcd_gotoxy();
}
static void lcd_clear_fast_s(void)
{
int pos;
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd_gotoxy();
spin_lock_irq(&pprt_lock);
for (pos = 0; pos < lcd.height * lcd.hwidth; pos++) {
lcd_send_serial(0x5F);
lcd_send_serial(' ' & 0x0F);
lcd_send_serial((' ' >> 4) & 0x0F);
udelay(40);
}
spin_unlock_irq(&pprt_lock);
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd_gotoxy();
}
static void lcd_clear_fast_p8(void)
{
int pos;
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd_gotoxy();
spin_lock_irq(&pprt_lock);
for (pos = 0; pos < lcd.height * lcd.hwidth; pos++) {
w_dtr(pprt, ' ');
udelay(20);
bits.e = BIT_SET;
bits.rs = BIT_SET;
bits.rw = BIT_CLR;
set_ctrl_bits();
udelay(40);
bits.e = BIT_CLR;
set_ctrl_bits();
udelay(45);
}
spin_unlock_irq(&pprt_lock);
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd_gotoxy();
}
static void lcd_clear_fast_tilcd(void)
{
int pos;
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd_gotoxy();
spin_lock_irq(&pprt_lock);
for (pos = 0; pos < lcd.height * lcd.hwidth; pos++) {
w_dtr(pprt, ' ');
udelay(60);
}
spin_unlock_irq(&pprt_lock);
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd_gotoxy();
}
static void lcd_clear_display(void)
{
lcd_write_cmd(LCD_CMD_DISPLAY_CLEAR);
lcd.addr.x = 0;
lcd.addr.y = 0;
long_sleep(15);
}
static void lcd_init_display(void)
{
lcd.flags = ((lcd.height > 1) ? LCD_FLAG_N : 0)
| LCD_FLAG_D | LCD_FLAG_C | LCD_FLAG_B;
long_sleep(20);
lcd_write_cmd(LCD_CMD_FUNCTION_SET | LCD_CMD_DATA_LEN_8BITS);
long_sleep(10);
lcd_write_cmd(LCD_CMD_FUNCTION_SET | LCD_CMD_DATA_LEN_8BITS);
long_sleep(10);
lcd_write_cmd(LCD_CMD_FUNCTION_SET | LCD_CMD_DATA_LEN_8BITS);
long_sleep(10);
lcd_write_cmd(LCD_CMD_FUNCTION_SET | LCD_CMD_DATA_LEN_8BITS
| ((lcd.flags & LCD_FLAG_F) ? LCD_CMD_FONT_5X10_DOTS : 0)
| ((lcd.flags & LCD_FLAG_N) ? LCD_CMD_TWO_LINES : 0)
);
long_sleep(10);
lcd_write_cmd(LCD_CMD_DISPLAY_CTRL);
long_sleep(10);
lcd_write_cmd(LCD_CMD_DISPLAY_CTRL
| ((lcd.flags & LCD_FLAG_D) ? LCD_CMD_DISPLAY_ON : 0)
| ((lcd.flags & LCD_FLAG_C) ? LCD_CMD_CURSOR_ON : 0)
| ((lcd.flags & LCD_FLAG_B) ? LCD_CMD_BLINK_ON : 0)
);
lcd_backlight((lcd.flags & LCD_FLAG_L) ? 1 : 0);
long_sleep(10);
lcd_write_cmd(LCD_CMD_ENTRY_MODE | LCD_CMD_CURSOR_INC);
lcd_clear_display();
}
static inline int handle_lcd_special_code(void)
{
int processed = 0;
char *esc = lcd.esc_seq.buf + 2;
int oldflags = lcd.flags;
switch (*esc) {
case 'D':
lcd.flags |= LCD_FLAG_D;
processed = 1;
break;
case 'd':
lcd.flags &= ~LCD_FLAG_D;
processed = 1;
break;
case 'C':
lcd.flags |= LCD_FLAG_C;
processed = 1;
break;
case 'c':
lcd.flags &= ~LCD_FLAG_C;
processed = 1;
break;
case 'B':
lcd.flags |= LCD_FLAG_B;
processed = 1;
break;
case 'b':
lcd.flags &= ~LCD_FLAG_B;
processed = 1;
break;
case '+':
lcd.flags |= LCD_FLAG_L;
processed = 1;
break;
case '-':
lcd.flags &= ~LCD_FLAG_L;
processed = 1;
break;
case '*':
if (scan_timer.function != NULL) {
if (lcd.light_tempo == 0
&& ((lcd.flags & LCD_FLAG_L) == 0))
lcd_backlight(1);
lcd.light_tempo = FLASH_LIGHT_TEMPO;
}
processed = 1;
break;
case 'f':
lcd.flags &= ~LCD_FLAG_F;
processed = 1;
break;
case 'F':
lcd.flags |= LCD_FLAG_F;
processed = 1;
break;
case 'n':
lcd.flags &= ~LCD_FLAG_N;
processed = 1;
break;
case 'N':
lcd.flags |= LCD_FLAG_N;
break;
case 'l':
if (lcd.addr.x > 0) {
if (lcd.addr.x < lcd.bwidth)
lcd_write_cmd(LCD_CMD_SHIFT);
lcd.addr.x--;
}
processed = 1;
break;
case 'r':
if (lcd.addr.x < lcd.width) {
if (lcd.addr.x < (lcd.bwidth - 1))
lcd_write_cmd(LCD_CMD_SHIFT |
LCD_CMD_SHIFT_RIGHT);
lcd.addr.x++;
}
processed = 1;
break;
case 'L':
lcd_write_cmd(LCD_CMD_SHIFT | LCD_CMD_DISPLAY_SHIFT);
processed = 1;
break;
case 'R':
lcd_write_cmd(LCD_CMD_SHIFT | LCD_CMD_DISPLAY_SHIFT |
LCD_CMD_SHIFT_RIGHT);
processed = 1;
break;
case 'k': {
int x;
for (x = lcd.addr.x; x < lcd.bwidth; x++)
lcd_write_data(' ');
lcd_gotoxy();
processed = 1;
break;
}
case 'I':
lcd_init_display();
processed = 1;
break;
case 'G': {
unsigned char cgbytes[8];
unsigned char cgaddr;
int cgoffset;
int shift;
char value;
int addr;
if (strchr(esc, ';') == NULL)
break;
esc++;
cgaddr = *(esc++) - '0';
if (cgaddr > 7) {
processed = 1;
break;
}
cgoffset = 0;
shift = 0;
value = 0;
while (*esc && cgoffset < 8) {
shift ^= 4;
if (*esc >= '0' && *esc <= '9') {
value |= (*esc - '0') << shift;
} else if (*esc >= 'A' && *esc <= 'Z') {
value |= (*esc - 'A' + 10) << shift;
} else if (*esc >= 'a' && *esc <= 'z') {
value |= (*esc - 'a' + 10) << shift;
} else {
esc++;
continue;
}
if (shift == 0) {
cgbytes[cgoffset++] = value;
value = 0;
}
esc++;
}
lcd_write_cmd(LCD_CMD_SET_CGRAM_ADDR | (cgaddr * 8));
for (addr = 0; addr < cgoffset; addr++)
lcd_write_data(cgbytes[addr]);
lcd_gotoxy();
processed = 1;
break;
}
case 'x':
case 'y':
if (strchr(esc, ';') == NULL)
break;
while (*esc) {
if (*esc == 'x') {
esc++;
if (kstrtoul(esc, 10, &lcd.addr.x) < 0)
break;
} else if (*esc == 'y') {
esc++;
if (kstrtoul(esc, 10, &lcd.addr.y) < 0)
break;
} else {
break;
}
}
lcd_gotoxy();
processed = 1;
break;
}
if (oldflags != lcd.flags) {
if ((oldflags ^ lcd.flags) &
(LCD_FLAG_B | LCD_FLAG_C | LCD_FLAG_D))
lcd_write_cmd(LCD_CMD_DISPLAY_CTRL
| ((lcd.flags & LCD_FLAG_D)
? LCD_CMD_DISPLAY_ON : 0)
| ((lcd.flags & LCD_FLAG_C)
? LCD_CMD_CURSOR_ON : 0)
| ((lcd.flags & LCD_FLAG_B)
? LCD_CMD_BLINK_ON : 0));
else if ((oldflags ^ lcd.flags) & (LCD_FLAG_F | LCD_FLAG_N))
lcd_write_cmd(LCD_CMD_FUNCTION_SET
| LCD_CMD_DATA_LEN_8BITS
| ((lcd.flags & LCD_FLAG_F)
? LCD_CMD_TWO_LINES : 0)
| ((lcd.flags & LCD_FLAG_N)
? LCD_CMD_FONT_5X10_DOTS
: 0));
else if ((oldflags ^ lcd.flags) & (LCD_FLAG_L)) {
if (lcd.flags & (LCD_FLAG_L))
lcd_backlight(1);
else if (lcd.light_tempo == 0)
lcd_backlight(0);
}
}
return processed;
}
static void lcd_write_char(char c)
{
if ((c != '\n') && lcd.esc_seq.len >= 0) {
lcd.esc_seq.buf[lcd.esc_seq.len++] = c;
lcd.esc_seq.buf[lcd.esc_seq.len] = 0;
} else {
lcd.esc_seq.len = -1;
switch (c) {
case LCD_ESCAPE_CHAR:
lcd.esc_seq.len = 0;
lcd.esc_seq.buf[lcd.esc_seq.len] = 0;
break;
case '\b':
if (lcd.addr.x > 0) {
if (lcd.addr.x < lcd.bwidth)
lcd_write_cmd(LCD_CMD_SHIFT);
lcd.addr.x--;
}
lcd_write_data(' ');
lcd_write_cmd(LCD_CMD_SHIFT);
break;
case '\014':
lcd_clear_fast();
break;
case '\n':
for (; lcd.addr.x < lcd.bwidth; lcd.addr.x++)
lcd_write_data(' ');
lcd.addr.x = 0;
lcd.addr.y = (lcd.addr.y + 1) % lcd.height;
lcd_gotoxy();
break;
case '\r':
lcd.addr.x = 0;
lcd_gotoxy();
break;
case '\t':
lcd_print(' ');
break;
default:
lcd_print(c);
break;
}
}
if (lcd.esc_seq.len >= 2) {
int processed = 0;
if (!strcmp(lcd.esc_seq.buf, "[2J")) {
lcd_clear_fast();
processed = 1;
} else if (!strcmp(lcd.esc_seq.buf, "[H")) {
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd_gotoxy();
processed = 1;
}
else if ((lcd.esc_seq.len >= 3) &&
(lcd.esc_seq.buf[0] == '[') &&
(lcd.esc_seq.buf[1] == 'L')) {
processed = handle_lcd_special_code();
}
if (processed || (lcd.esc_seq.len >= LCD_ESCAPE_LEN))
lcd.esc_seq.len = -1;
}
}
static ssize_t lcd_write(struct file *file,
const char __user *buf, size_t count, loff_t *ppos)
{
const char __user *tmp = buf;
char c;
for (; count-- > 0; (*ppos)++, tmp++) {
if (!in_interrupt() && (((count + 1) & 0x1f) == 0))
schedule();
if (get_user(c, tmp))
return -EFAULT;
lcd_write_char(c);
}
return tmp - buf;
}
static int lcd_open(struct inode *inode, struct file *file)
{
if (!atomic_dec_and_test(&lcd_available))
return -EBUSY;
if (file->f_mode & FMODE_READ)
return -EPERM;
if (lcd.must_clear) {
lcd_clear_display();
lcd.must_clear = false;
}
return nonseekable_open(inode, file);
}
static int lcd_release(struct inode *inode, struct file *file)
{
atomic_inc(&lcd_available);
return 0;
}
static void panel_lcd_print(const char *s)
{
const char *tmp = s;
int count = strlen(s);
if (lcd.enabled && lcd.initialized) {
for (; count-- > 0; tmp++) {
if (!in_interrupt() && (((count + 1) & 0x1f) == 0))
schedule();
lcd_write_char(*tmp);
}
}
}
static void lcd_init(void)
{
switch (selected_lcd_type) {
case LCD_TYPE_OLD:
lcd.proto = LCD_PROTO_PARALLEL;
lcd.charset = LCD_CHARSET_NORMAL;
lcd.pins.e = PIN_STROBE;
lcd.pins.rs = PIN_AUTOLF;
lcd.width = 40;
lcd.bwidth = 40;
lcd.hwidth = 64;
lcd.height = 2;
break;
case LCD_TYPE_KS0074:
lcd.proto = LCD_PROTO_SERIAL;
lcd.charset = LCD_CHARSET_KS0074;
lcd.pins.bl = PIN_AUTOLF;
lcd.pins.cl = PIN_STROBE;
lcd.pins.da = PIN_D0;
lcd.width = 16;
lcd.bwidth = 40;
lcd.hwidth = 16;
lcd.height = 2;
break;
case LCD_TYPE_NEXCOM:
lcd.proto = LCD_PROTO_PARALLEL;
lcd.charset = LCD_CHARSET_NORMAL;
lcd.pins.e = PIN_AUTOLF;
lcd.pins.rs = PIN_SELECP;
lcd.pins.rw = PIN_INITP;
lcd.width = 16;
lcd.bwidth = 40;
lcd.hwidth = 64;
lcd.height = 2;
break;
case LCD_TYPE_CUSTOM:
lcd.proto = DEFAULT_LCD_PROTO;
lcd.charset = DEFAULT_LCD_CHARSET;
break;
case LCD_TYPE_HANTRONIX:
default:
lcd.proto = LCD_PROTO_PARALLEL;
lcd.charset = LCD_CHARSET_NORMAL;
lcd.pins.e = PIN_STROBE;
lcd.pins.rs = PIN_SELECP;
lcd.width = 16;
lcd.bwidth = 40;
lcd.hwidth = 64;
lcd.height = 2;
break;
}
if (lcd_height != NOT_SET)
lcd.height = lcd_height;
if (lcd_width != NOT_SET)
lcd.width = lcd_width;
if (lcd_bwidth != NOT_SET)
lcd.bwidth = lcd_bwidth;
if (lcd_hwidth != NOT_SET)
lcd.hwidth = lcd_hwidth;
if (lcd_charset != NOT_SET)
lcd.charset = lcd_charset;
if (lcd_proto != NOT_SET)
lcd.proto = lcd_proto;
if (lcd_e_pin != PIN_NOT_SET)
lcd.pins.e = lcd_e_pin;
if (lcd_rs_pin != PIN_NOT_SET)
lcd.pins.rs = lcd_rs_pin;
if (lcd_rw_pin != PIN_NOT_SET)
lcd.pins.rw = lcd_rw_pin;
if (lcd_cl_pin != PIN_NOT_SET)
lcd.pins.cl = lcd_cl_pin;
if (lcd_da_pin != PIN_NOT_SET)
lcd.pins.da = lcd_da_pin;
if (lcd_bl_pin != PIN_NOT_SET)
lcd.pins.bl = lcd_bl_pin;
if (lcd.width <= 0)
lcd.width = DEFAULT_LCD_WIDTH;
if (lcd.bwidth <= 0)
lcd.bwidth = DEFAULT_LCD_BWIDTH;
if (lcd.hwidth <= 0)
lcd.hwidth = DEFAULT_LCD_HWIDTH;
if (lcd.height <= 0)
lcd.height = DEFAULT_LCD_HEIGHT;
if (lcd.proto == LCD_PROTO_SERIAL) {
lcd_write_cmd = lcd_write_cmd_s;
lcd_write_data = lcd_write_data_s;
lcd_clear_fast = lcd_clear_fast_s;
if (lcd.pins.cl == PIN_NOT_SET)
lcd.pins.cl = DEFAULT_LCD_PIN_SCL;
if (lcd.pins.da == PIN_NOT_SET)
lcd.pins.da = DEFAULT_LCD_PIN_SDA;
} else if (lcd.proto == LCD_PROTO_PARALLEL) {
lcd_write_cmd = lcd_write_cmd_p8;
lcd_write_data = lcd_write_data_p8;
lcd_clear_fast = lcd_clear_fast_p8;
if (lcd.pins.e == PIN_NOT_SET)
lcd.pins.e = DEFAULT_LCD_PIN_E;
if (lcd.pins.rs == PIN_NOT_SET)
lcd.pins.rs = DEFAULT_LCD_PIN_RS;
if (lcd.pins.rw == PIN_NOT_SET)
lcd.pins.rw = DEFAULT_LCD_PIN_RW;
} else {
lcd_write_cmd = lcd_write_cmd_tilcd;
lcd_write_data = lcd_write_data_tilcd;
lcd_clear_fast = lcd_clear_fast_tilcd;
}
if (lcd.pins.bl == PIN_NOT_SET)
lcd.pins.bl = DEFAULT_LCD_PIN_BL;
if (lcd.pins.e == PIN_NOT_SET)
lcd.pins.e = PIN_NONE;
if (lcd.pins.rs == PIN_NOT_SET)
lcd.pins.rs = PIN_NONE;
if (lcd.pins.rw == PIN_NOT_SET)
lcd.pins.rw = PIN_NONE;
if (lcd.pins.bl == PIN_NOT_SET)
lcd.pins.bl = PIN_NONE;
if (lcd.pins.cl == PIN_NOT_SET)
lcd.pins.cl = PIN_NONE;
if (lcd.pins.da == PIN_NOT_SET)
lcd.pins.da = PIN_NONE;
if (lcd.charset == NOT_SET)
lcd.charset = DEFAULT_LCD_CHARSET;
if (lcd.charset == LCD_CHARSET_KS0074)
lcd_char_conv = lcd_char_conv_ks0074;
else
lcd_char_conv = NULL;
if (lcd.pins.bl != PIN_NONE)
init_scan_timer();
pin_to_bits(lcd.pins.e, lcd_bits[LCD_PORT_D][LCD_BIT_E],
lcd_bits[LCD_PORT_C][LCD_BIT_E]);
pin_to_bits(lcd.pins.rs, lcd_bits[LCD_PORT_D][LCD_BIT_RS],
lcd_bits[LCD_PORT_C][LCD_BIT_RS]);
pin_to_bits(lcd.pins.rw, lcd_bits[LCD_PORT_D][LCD_BIT_RW],
lcd_bits[LCD_PORT_C][LCD_BIT_RW]);
pin_to_bits(lcd.pins.bl, lcd_bits[LCD_PORT_D][LCD_BIT_BL],
lcd_bits[LCD_PORT_C][LCD_BIT_BL]);
pin_to_bits(lcd.pins.cl, lcd_bits[LCD_PORT_D][LCD_BIT_CL],
lcd_bits[LCD_PORT_C][LCD_BIT_CL]);
pin_to_bits(lcd.pins.da, lcd_bits[LCD_PORT_D][LCD_BIT_DA],
lcd_bits[LCD_PORT_C][LCD_BIT_DA]);
lcd.initialized = true;
lcd_init_display();
#ifdef CONFIG_PANEL_CHANGE_MESSAGE
#ifdef CONFIG_PANEL_BOOT_MESSAGE
panel_lcd_print("\x1b[Lc\x1b[Lb\x1b[L*" CONFIG_PANEL_BOOT_MESSAGE);
#endif
#else
panel_lcd_print("\x1b[Lc\x1b[Lb\x1b[L*Linux-" UTS_RELEASE "\nPanel-"
PANEL_VERSION);
#endif
lcd.addr.x = 0;
lcd.addr.y = 0;
lcd.must_clear = true;
lcd_gotoxy();
}
static ssize_t keypad_read(struct file *file,
char __user *buf, size_t count, loff_t *ppos)
{
unsigned i = *ppos;
char __user *tmp = buf;
if (keypad_buflen == 0) {
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
if (wait_event_interruptible(keypad_read_wait,
keypad_buflen != 0))
return -EINTR;
}
for (; count-- > 0 && (keypad_buflen > 0);
++i, ++tmp, --keypad_buflen) {
put_user(keypad_buffer[keypad_start], tmp);
keypad_start = (keypad_start + 1) % KEYPAD_BUFFER;
}
*ppos = i;
return tmp - buf;
}
static int keypad_open(struct inode *inode, struct file *file)
{
if (!atomic_dec_and_test(&keypad_available))
return -EBUSY;
if (file->f_mode & FMODE_WRITE)
return -EPERM;
keypad_buflen = 0;
return 0;
}
static int keypad_release(struct inode *inode, struct file *file)
{
atomic_inc(&keypad_available);
return 0;
}
static void keypad_send_key(const char *string, int max_len)
{
if (init_in_progress)
return;
if (!atomic_read(&keypad_available)) {
while (max_len-- && keypad_buflen < KEYPAD_BUFFER && *string) {
keypad_buffer[(keypad_start + keypad_buflen++) %
KEYPAD_BUFFER] = *string++;
}
wake_up_interruptible(&keypad_read_wait);
}
}
static void phys_scan_contacts(void)
{
int bit, bitval;
char oldval;
char bitmask;
char gndmask;
phys_prev = phys_curr;
phys_read_prev = phys_read;
phys_read = 0;
oldval = r_dtr(pprt) | scan_mask_o;
w_dtr(pprt, oldval & ~scan_mask_o);
bitmask = PNL_PINPUT(r_str(pprt)) & scan_mask_i;
w_dtr(pprt, oldval);
gndmask = PNL_PINPUT(r_str(pprt)) & scan_mask_i;
phys_read |= (pmask_t) gndmask << 40;
if (bitmask != gndmask) {
for (bit = 0; bit < 8; bit++) {
bitval = 1 << bit;
if (!(scan_mask_o & bitval))
continue;
w_dtr(pprt, oldval & ~bitval);
bitmask = PNL_PINPUT(r_str(pprt)) & ~gndmask;
phys_read |= (pmask_t) bitmask << (5 * bit);
}
w_dtr(pprt, oldval);
}
phys_curr = (phys_prev & (phys_read ^ phys_read_prev)) |
(phys_read & ~(phys_read ^ phys_read_prev));
}
static inline int input_state_high(struct logical_input *input)
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return 1;
}
#endif
if ((phys_curr & input->mask) == input->value) {
if ((input->type == INPUT_TYPE_STD) &&
(input->high_timer == 0)) {
input->high_timer++;
if (input->u.std.press_fct != NULL)
input->u.std.press_fct(input->u.std.press_data);
} else if (input->type == INPUT_TYPE_KBD) {
keypressed = 1;
if (input->high_timer == 0) {
char *press_str = input->u.kbd.press_str;
if (press_str[0]) {
int s = sizeof(input->u.kbd.press_str);
keypad_send_key(press_str, s);
}
}
if (input->u.kbd.repeat_str[0]) {
char *repeat_str = input->u.kbd.repeat_str;
if (input->high_timer >= KEYPAD_REP_START) {
int s = sizeof(input->u.kbd.repeat_str);
input->high_timer -= KEYPAD_REP_DELAY;
keypad_send_key(repeat_str, s);
}
inputs_stable = 0;
}
if (input->high_timer < 255)
input->high_timer++;
}
return 1;
}
input->state = INPUT_ST_FALLING;
input->fall_timer = 0;
return 0;
}
static inline void input_state_falling(struct logical_input *input)
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return;
}
#endif
if ((phys_curr & input->mask) == input->value) {
if (input->type == INPUT_TYPE_KBD) {
keypressed = 1;
if (input->u.kbd.repeat_str[0]) {
char *repeat_str = input->u.kbd.repeat_str;
if (input->high_timer >= KEYPAD_REP_START) {
int s = sizeof(input->u.kbd.repeat_str);
input->high_timer -= KEYPAD_REP_DELAY;
keypad_send_key(repeat_str, s);
}
inputs_stable = 0;
}
if (input->high_timer < 255)
input->high_timer++;
}
input->state = INPUT_ST_HIGH;
} else if (input->fall_timer >= input->fall_time) {
if (input->type == INPUT_TYPE_STD) {
void (*release_fct)(int) = input->u.std.release_fct;
if (release_fct != NULL)
release_fct(input->u.std.release_data);
} else if (input->type == INPUT_TYPE_KBD) {
char *release_str = input->u.kbd.release_str;
if (release_str[0]) {
int s = sizeof(input->u.kbd.release_str);
keypad_send_key(release_str, s);
}
}
input->state = INPUT_ST_LOW;
} else {
input->fall_timer++;
inputs_stable = 0;
}
}
static void panel_process_inputs(void)
{
struct list_head *item;
struct logical_input *input;
keypressed = 0;
inputs_stable = 1;
list_for_each(item, &logical_inputs) {
input = list_entry(item, struct logical_input, list);
switch (input->state) {
case INPUT_ST_LOW:
if ((phys_curr & input->mask) != input->value)
break;
if ((phys_prev & input->mask) == input->value)
break;
input->rise_timer = 0;
input->state = INPUT_ST_RISING;
case INPUT_ST_RISING:
if ((phys_curr & input->mask) != input->value) {
input->state = INPUT_ST_LOW;
break;
}
if (input->rise_timer < input->rise_time) {
inputs_stable = 0;
input->rise_timer++;
break;
}
input->high_timer = 0;
input->state = INPUT_ST_HIGH;
case INPUT_ST_HIGH:
if (input_state_high(input))
break;
case INPUT_ST_FALLING:
input_state_falling(input);
}
}
}
static void panel_scan_timer(void)
{
if (keypad.enabled && keypad_initialized) {
if (spin_trylock_irq(&pprt_lock)) {
phys_scan_contacts();
spin_unlock_irq(&pprt_lock);
}
if (!inputs_stable || phys_curr != phys_prev)
panel_process_inputs();
}
if (lcd.enabled && lcd.initialized) {
if (keypressed) {
if (lcd.light_tempo == 0
&& ((lcd.flags & LCD_FLAG_L) == 0))
lcd_backlight(1);
lcd.light_tempo = FLASH_LIGHT_TEMPO;
} else if (lcd.light_tempo > 0) {
lcd.light_tempo--;
if (lcd.light_tempo == 0
&& ((lcd.flags & LCD_FLAG_L) == 0))
lcd_backlight(0);
}
}
mod_timer(&scan_timer, jiffies + INPUT_POLL_TIME);
}
static void init_scan_timer(void)
{
if (scan_timer.function != NULL)
return;
init_timer(&scan_timer);
scan_timer.expires = jiffies + INPUT_POLL_TIME;
scan_timer.data = 0;
scan_timer.function = (void *)&panel_scan_timer;
add_timer(&scan_timer);
}
static int input_name2mask(const char *name, pmask_t *mask, pmask_t *value,
char *imask, char *omask)
{
static char sigtab[10] = "EeSsPpAaBb";
char im, om;
pmask_t m, v;
om = 0ULL;
im = 0ULL;
m = 0ULL;
v = 0ULL;
while (*name) {
int in, out, bit, neg;
for (in = 0; (in < sizeof(sigtab)) && (sigtab[in] != *name);
in++)
;
if (in >= sizeof(sigtab))
return 0;
neg = (in & 1);
in >>= 1;
im |= (1 << in);
name++;
if (isdigit(*name)) {
out = *name - '0';
om |= (1 << out);
} else if (*name == '-') {
out = 8;
} else {
return 0;
}
bit = (out * 5) + in;
m |= 1ULL << bit;
if (!neg)
v |= 1ULL << bit;
name++;
}
*mask = m;
*value = v;
if (imask)
*imask |= im;
if (omask)
*omask |= om;
return 1;
}
static struct logical_input *panel_bind_key(const char *name, const char *press,
const char *repeat,
const char *release)
{
struct logical_input *key;
key = kzalloc(sizeof(*key), GFP_KERNEL);
if (!key)
return NULL;
if (!input_name2mask(name, &key->mask, &key->value, &scan_mask_i,
&scan_mask_o)) {
kfree(key);
return NULL;
}
key->type = INPUT_TYPE_KBD;
key->state = INPUT_ST_LOW;
key->rise_time = 1;
key->fall_time = 1;
strncpy(key->u.kbd.press_str, press, sizeof(key->u.kbd.press_str));
strncpy(key->u.kbd.repeat_str, repeat, sizeof(key->u.kbd.repeat_str));
strncpy(key->u.kbd.release_str, release,
sizeof(key->u.kbd.release_str));
list_add(&key->list, &logical_inputs);
return key;
}
static void keypad_init(void)
{
int keynum;
init_waitqueue_head(&keypad_read_wait);
keypad_buflen = 0;
for (keynum = 0; keypad_profile[keynum][0][0]; keynum++) {
panel_bind_key(keypad_profile[keynum][0],
keypad_profile[keynum][1],
keypad_profile[keynum][2],
keypad_profile[keynum][3]);
}
init_scan_timer();
keypad_initialized = 1;
}
static int panel_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (lcd.enabled && lcd.initialized) {
switch (code) {
case SYS_DOWN:
panel_lcd_print
("\x0cReloading\nSystem...\x1b[Lc\x1b[Lb\x1b[L+");
break;
case SYS_HALT:
panel_lcd_print
("\x0cSystem Halted.\x1b[Lc\x1b[Lb\x1b[L+");
break;
case SYS_POWER_OFF:
panel_lcd_print("\x0cPower off.\x1b[Lc\x1b[Lb\x1b[L+");
break;
default:
break;
}
}
return NOTIFY_DONE;
}
static void panel_attach(struct parport *port)
{
if (port->number != parport)
return;
if (pprt) {
pr_err("%s: port->number=%d parport=%d, already registered!\n",
__func__, port->number, parport);
return;
}
pprt = parport_register_device(port, "panel", NULL, NULL,
NULL,
0, (void *)&pprt);
if (pprt == NULL) {
pr_err("%s: port->number=%d parport=%d, parport_register_device() failed\n",
__func__, port->number, parport);
return;
}
if (parport_claim(pprt)) {
pr_err("could not claim access to parport%d. Aborting.\n",
parport);
goto err_unreg_device;
}
if (lcd.enabled) {
lcd_init();
if (misc_register(&lcd_dev))
goto err_unreg_device;
}
if (keypad.enabled) {
keypad_init();
if (misc_register(&keypad_dev))
goto err_lcd_unreg;
}
return;
err_lcd_unreg:
if (lcd.enabled)
misc_deregister(&lcd_dev);
err_unreg_device:
parport_unregister_device(pprt);
pprt = NULL;
}
static void panel_detach(struct parport *port)
{
if (port->number != parport)
return;
if (!pprt) {
pr_err("%s: port->number=%d parport=%d, nothing to unregister.\n",
__func__, port->number, parport);
return;
}
if (keypad.enabled && keypad_initialized) {
misc_deregister(&keypad_dev);
keypad_initialized = 0;
}
if (lcd.enabled && lcd.initialized) {
misc_deregister(&lcd_dev);
lcd.initialized = false;
}
parport_release(pprt);
parport_unregister_device(pprt);
pprt = NULL;
}
static int __init panel_init_module(void)
{
int selected_keypad_type = NOT_SET;
switch (profile) {
case PANEL_PROFILE_CUSTOM:
selected_keypad_type = DEFAULT_KEYPAD_TYPE;
selected_lcd_type = DEFAULT_LCD_TYPE;
break;
case PANEL_PROFILE_OLD:
selected_keypad_type = KEYPAD_TYPE_OLD;
selected_lcd_type = LCD_TYPE_OLD;
if (lcd_width == NOT_SET)
lcd_width = 16;
if (lcd_hwidth == NOT_SET)
lcd_hwidth = 16;
break;
case PANEL_PROFILE_NEW:
selected_keypad_type = KEYPAD_TYPE_NEW;
selected_lcd_type = LCD_TYPE_KS0074;
break;
case PANEL_PROFILE_HANTRONIX:
selected_keypad_type = KEYPAD_TYPE_NONE;
selected_lcd_type = LCD_TYPE_HANTRONIX;
break;
case PANEL_PROFILE_NEXCOM:
selected_keypad_type = KEYPAD_TYPE_NEXCOM;
selected_lcd_type = LCD_TYPE_NEXCOM;
break;
case PANEL_PROFILE_LARGE:
selected_keypad_type = KEYPAD_TYPE_OLD;
selected_lcd_type = LCD_TYPE_OLD;
break;
}
lcd.height = lcd_height;
lcd.width = lcd_width;
lcd.bwidth = lcd_bwidth;
lcd.hwidth = lcd_hwidth;
lcd.charset = lcd_charset;
lcd.proto = lcd_proto;
lcd.pins.e = lcd_e_pin;
lcd.pins.rs = lcd_rs_pin;
lcd.pins.rw = lcd_rw_pin;
lcd.pins.cl = lcd_cl_pin;
lcd.pins.da = lcd_da_pin;
lcd.pins.bl = lcd_bl_pin;
lcd.esc_seq.len = -1;
if (keypad_enabled != NOT_SET)
selected_keypad_type = keypad_enabled;
if (keypad_type != NOT_SET)
selected_keypad_type = keypad_type;
keypad.enabled = (selected_keypad_type > 0);
if (lcd_enabled != NOT_SET)
selected_lcd_type = lcd_enabled;
if (lcd_type != NOT_SET)
selected_lcd_type = lcd_type;
lcd.enabled = (selected_lcd_type > 0);
switch (selected_keypad_type) {
case KEYPAD_TYPE_OLD:
keypad_profile = old_keypad_profile;
break;
case KEYPAD_TYPE_NEW:
keypad_profile = new_keypad_profile;
break;
case KEYPAD_TYPE_NEXCOM:
keypad_profile = nexcom_keypad_profile;
break;
default:
keypad_profile = NULL;
break;
}
init_in_progress = 1;
if (parport_register_driver(&panel_driver)) {
pr_err("could not register with parport. Aborting.\n");
return -EIO;
}
if (!lcd.enabled && !keypad.enabled) {
if (pprt) {
parport_release(pprt);
parport_unregister_device(pprt);
pprt = NULL;
}
parport_unregister_driver(&panel_driver);
pr_err("driver version " PANEL_VERSION " disabled.\n");
return -ENODEV;
}
register_reboot_notifier(&panel_notifier);
if (pprt)
pr_info("driver version " PANEL_VERSION
" registered on parport%d (io=0x%lx).\n", parport,
pprt->port->base);
else
pr_info("driver version " PANEL_VERSION
" not yet registered\n");
init_in_progress = 0;
return 0;
}
static void __exit panel_cleanup_module(void)
{
unregister_reboot_notifier(&panel_notifier);
if (scan_timer.function != NULL)
del_timer_sync(&scan_timer);
if (pprt != NULL) {
if (keypad.enabled) {
misc_deregister(&keypad_dev);
keypad_initialized = 0;
}
if (lcd.enabled) {
panel_lcd_print("\x0cLCD driver " PANEL_VERSION
"\nunloaded.\x1b[Lc\x1b[Lb\x1b[L-");
misc_deregister(&lcd_dev);
lcd.initialized = false;
}
parport_release(pprt);
parport_unregister_device(pprt);
pprt = NULL;
}
parport_unregister_driver(&panel_driver);
}
