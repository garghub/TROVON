static void long_sleep(int ms)
{
if (in_interrupt())
mdelay(ms);
else
schedule_timeout_interruptible(msecs_to_jiffies(ms));
}
static void charlcd_backlight(struct charlcd *lcd, int on)
{
struct charlcd_priv *priv = to_priv(lcd);
if (!lcd->ops->backlight)
return;
mutex_lock(&priv->bl_tempo_lock);
if (!priv->bl_tempo)
lcd->ops->backlight(lcd, on);
mutex_unlock(&priv->bl_tempo_lock);
}
static void charlcd_bl_off(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct charlcd_priv *priv =
container_of(dwork, struct charlcd_priv, bl_work);
mutex_lock(&priv->bl_tempo_lock);
if (priv->bl_tempo) {
priv->bl_tempo = false;
if (!(priv->flags & LCD_FLAG_L))
priv->lcd.ops->backlight(&priv->lcd, 0);
}
mutex_unlock(&priv->bl_tempo_lock);
}
void charlcd_poke(struct charlcd *lcd)
{
struct charlcd_priv *priv = to_priv(lcd);
if (!lcd->ops->backlight)
return;
cancel_delayed_work_sync(&priv->bl_work);
mutex_lock(&priv->bl_tempo_lock);
if (!priv->bl_tempo && !(priv->flags & LCD_FLAG_L))
lcd->ops->backlight(lcd, 1);
priv->bl_tempo = true;
schedule_delayed_work(&priv->bl_work, LCD_BL_TEMPO_PERIOD * HZ);
mutex_unlock(&priv->bl_tempo_lock);
}
static void charlcd_gotoxy(struct charlcd *lcd)
{
struct charlcd_priv *priv = to_priv(lcd);
unsigned int addr;
addr = priv->addr.x < lcd->bwidth ? priv->addr.x & (lcd->hwidth - 1)
: lcd->bwidth - 1;
if (priv->addr.y & 1)
addr += lcd->hwidth;
if (priv->addr.y & 2)
addr += lcd->bwidth;
lcd->ops->write_cmd(lcd, LCD_CMD_SET_DDRAM_ADDR | addr);
}
static void charlcd_home(struct charlcd *lcd)
{
struct charlcd_priv *priv = to_priv(lcd);
priv->addr.x = 0;
priv->addr.y = 0;
charlcd_gotoxy(lcd);
}
static void charlcd_print(struct charlcd *lcd, char c)
{
struct charlcd_priv *priv = to_priv(lcd);
if (priv->addr.x < lcd->bwidth) {
if (lcd->char_conv)
c = lcd->char_conv[(unsigned char)c];
lcd->ops->write_data(lcd, c);
priv->addr.x++;
}
if (priv->addr.x == lcd->bwidth)
charlcd_gotoxy(lcd);
}
static void charlcd_clear_fast(struct charlcd *lcd)
{
int pos;
charlcd_home(lcd);
if (lcd->ops->clear_fast)
lcd->ops->clear_fast(lcd);
else
for (pos = 0; pos < min(2, lcd->height) * lcd->hwidth; pos++)
lcd->ops->write_data(lcd, ' ');
charlcd_home(lcd);
}
static void charlcd_clear_display(struct charlcd *lcd)
{
struct charlcd_priv *priv = to_priv(lcd);
lcd->ops->write_cmd(lcd, LCD_CMD_DISPLAY_CLEAR);
priv->addr.x = 0;
priv->addr.y = 0;
long_sleep(15);
}
static int charlcd_init_display(struct charlcd *lcd)
{
void (*write_cmd_raw)(struct charlcd *lcd, int cmd);
struct charlcd_priv *priv = to_priv(lcd);
u8 init;
if (lcd->ifwidth != 4 && lcd->ifwidth != 8)
return -EINVAL;
priv->flags = ((lcd->height > 1) ? LCD_FLAG_N : 0) | LCD_FLAG_D |
LCD_FLAG_C | LCD_FLAG_B;
long_sleep(20);
init = LCD_CMD_FUNCTION_SET | LCD_CMD_DATA_LEN_8BITS;
if (lcd->ifwidth == 4) {
init >>= 4;
write_cmd_raw = lcd->ops->write_cmd_raw4;
} else {
write_cmd_raw = lcd->ops->write_cmd;
}
write_cmd_raw(lcd, init);
long_sleep(10);
write_cmd_raw(lcd, init);
long_sleep(10);
write_cmd_raw(lcd, init);
long_sleep(10);
if (lcd->ifwidth == 4) {
lcd->ops->write_cmd_raw4(lcd, LCD_CMD_FUNCTION_SET >> 4);
long_sleep(10);
}
lcd->ops->write_cmd(lcd,
LCD_CMD_FUNCTION_SET |
((lcd->ifwidth == 8) ? LCD_CMD_DATA_LEN_8BITS : 0) |
((priv->flags & LCD_FLAG_F) ? LCD_CMD_FONT_5X10_DOTS : 0) |
((priv->flags & LCD_FLAG_N) ? LCD_CMD_TWO_LINES : 0));
long_sleep(10);
lcd->ops->write_cmd(lcd, LCD_CMD_DISPLAY_CTRL);
long_sleep(10);
lcd->ops->write_cmd(lcd,
LCD_CMD_DISPLAY_CTRL |
((priv->flags & LCD_FLAG_D) ? LCD_CMD_DISPLAY_ON : 0) |
((priv->flags & LCD_FLAG_C) ? LCD_CMD_CURSOR_ON : 0) |
((priv->flags & LCD_FLAG_B) ? LCD_CMD_BLINK_ON : 0));
charlcd_backlight(lcd, (priv->flags & LCD_FLAG_L) ? 1 : 0);
long_sleep(10);
lcd->ops->write_cmd(lcd, LCD_CMD_ENTRY_MODE | LCD_CMD_CURSOR_INC);
charlcd_clear_display(lcd);
return 0;
}
static inline int handle_lcd_special_code(struct charlcd *lcd)
{
struct charlcd_priv *priv = to_priv(lcd);
int processed = 0;
char *esc = priv->esc_seq.buf + 2;
int oldflags = priv->flags;
switch (*esc) {
case 'D':
priv->flags |= LCD_FLAG_D;
processed = 1;
break;
case 'd':
priv->flags &= ~LCD_FLAG_D;
processed = 1;
break;
case 'C':
priv->flags |= LCD_FLAG_C;
processed = 1;
break;
case 'c':
priv->flags &= ~LCD_FLAG_C;
processed = 1;
break;
case 'B':
priv->flags |= LCD_FLAG_B;
processed = 1;
break;
case 'b':
priv->flags &= ~LCD_FLAG_B;
processed = 1;
break;
case '+':
priv->flags |= LCD_FLAG_L;
processed = 1;
break;
case '-':
priv->flags &= ~LCD_FLAG_L;
processed = 1;
break;
case '*':
charlcd_poke(lcd);
processed = 1;
break;
case 'f':
priv->flags &= ~LCD_FLAG_F;
processed = 1;
break;
case 'F':
priv->flags |= LCD_FLAG_F;
processed = 1;
break;
case 'n':
priv->flags &= ~LCD_FLAG_N;
processed = 1;
break;
case 'N':
priv->flags |= LCD_FLAG_N;
break;
case 'l':
if (priv->addr.x > 0) {
if (priv->addr.x < lcd->bwidth)
lcd->ops->write_cmd(lcd, LCD_CMD_SHIFT);
priv->addr.x--;
}
processed = 1;
break;
case 'r':
if (priv->addr.x < lcd->width) {
if (priv->addr.x < (lcd->bwidth - 1))
lcd->ops->write_cmd(lcd,
LCD_CMD_SHIFT | LCD_CMD_SHIFT_RIGHT);
priv->addr.x++;
}
processed = 1;
break;
case 'L':
lcd->ops->write_cmd(lcd, LCD_CMD_SHIFT | LCD_CMD_DISPLAY_SHIFT);
processed = 1;
break;
case 'R':
lcd->ops->write_cmd(lcd,
LCD_CMD_SHIFT | LCD_CMD_DISPLAY_SHIFT |
LCD_CMD_SHIFT_RIGHT);
processed = 1;
break;
case 'k': {
int x;
for (x = priv->addr.x; x < lcd->bwidth; x++)
lcd->ops->write_data(lcd, ' ');
charlcd_gotoxy(lcd);
processed = 1;
break;
}
case 'I':
charlcd_init_display(lcd);
processed = 1;
break;
case 'G': {
unsigned char cgbytes[8];
unsigned char cgaddr;
int cgoffset;
int shift;
char value;
int addr;
if (!strchr(esc, ';'))
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
lcd->ops->write_cmd(lcd, LCD_CMD_SET_CGRAM_ADDR | (cgaddr * 8));
for (addr = 0; addr < cgoffset; addr++)
lcd->ops->write_data(lcd, cgbytes[addr]);
charlcd_gotoxy(lcd);
processed = 1;
break;
}
case 'x':
case 'y':
if (!strchr(esc, ';'))
break;
while (*esc) {
if (*esc == 'x') {
esc++;
if (kstrtoul(esc, 10, &priv->addr.x) < 0)
break;
} else if (*esc == 'y') {
esc++;
if (kstrtoul(esc, 10, &priv->addr.y) < 0)
break;
} else {
break;
}
}
charlcd_gotoxy(lcd);
processed = 1;
break;
}
if (oldflags == priv->flags)
return processed;
if ((oldflags ^ priv->flags) &
(LCD_FLAG_B | LCD_FLAG_C | LCD_FLAG_D))
lcd->ops->write_cmd(lcd,
LCD_CMD_DISPLAY_CTRL |
((priv->flags & LCD_FLAG_D) ? LCD_CMD_DISPLAY_ON : 0) |
((priv->flags & LCD_FLAG_C) ? LCD_CMD_CURSOR_ON : 0) |
((priv->flags & LCD_FLAG_B) ? LCD_CMD_BLINK_ON : 0));
else if ((oldflags ^ priv->flags) & (LCD_FLAG_F | LCD_FLAG_N))
lcd->ops->write_cmd(lcd,
LCD_CMD_FUNCTION_SET |
((lcd->ifwidth == 8) ? LCD_CMD_DATA_LEN_8BITS : 0) |
((priv->flags & LCD_FLAG_F) ? LCD_CMD_FONT_5X10_DOTS : 0) |
((priv->flags & LCD_FLAG_N) ? LCD_CMD_TWO_LINES : 0));
else if ((oldflags ^ priv->flags) & LCD_FLAG_L)
charlcd_backlight(lcd, !!(priv->flags & LCD_FLAG_L));
return processed;
}
static void charlcd_write_char(struct charlcd *lcd, char c)
{
struct charlcd_priv *priv = to_priv(lcd);
if ((c != '\n') && priv->esc_seq.len >= 0) {
priv->esc_seq.buf[priv->esc_seq.len++] = c;
priv->esc_seq.buf[priv->esc_seq.len] = 0;
} else {
priv->esc_seq.len = -1;
switch (c) {
case LCD_ESCAPE_CHAR:
priv->esc_seq.len = 0;
priv->esc_seq.buf[priv->esc_seq.len] = 0;
break;
case '\b':
if (priv->addr.x > 0) {
if (priv->addr.x < lcd->bwidth)
lcd->ops->write_cmd(lcd, LCD_CMD_SHIFT);
priv->addr.x--;
}
lcd->ops->write_data(lcd, ' ');
lcd->ops->write_cmd(lcd, LCD_CMD_SHIFT);
break;
case '\014':
charlcd_clear_fast(lcd);
break;
case '\n':
for (; priv->addr.x < lcd->bwidth; priv->addr.x++)
lcd->ops->write_data(lcd, ' ');
priv->addr.x = 0;
priv->addr.y = (priv->addr.y + 1) % lcd->height;
charlcd_gotoxy(lcd);
break;
case '\r':
priv->addr.x = 0;
charlcd_gotoxy(lcd);
break;
case '\t':
charlcd_print(lcd, ' ');
break;
default:
charlcd_print(lcd, c);
break;
}
}
if (priv->esc_seq.len >= 2) {
int processed = 0;
if (!strcmp(priv->esc_seq.buf, "[2J")) {
charlcd_clear_fast(lcd);
processed = 1;
} else if (!strcmp(priv->esc_seq.buf, "[H")) {
charlcd_home(lcd);
processed = 1;
}
else if ((priv->esc_seq.len >= 3) &&
(priv->esc_seq.buf[0] == '[') &&
(priv->esc_seq.buf[1] == 'L')) {
processed = handle_lcd_special_code(lcd);
}
if (processed || (priv->esc_seq.len >= LCD_ESCAPE_LEN))
priv->esc_seq.len = -1;
}
}
static ssize_t charlcd_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
const char __user *tmp = buf;
char c;
for (; count-- > 0; (*ppos)++, tmp++) {
if (!in_interrupt() && (((count + 1) & 0x1f) == 0))
schedule();
if (get_user(c, tmp))
return -EFAULT;
charlcd_write_char(the_charlcd, c);
}
return tmp - buf;
}
static int charlcd_open(struct inode *inode, struct file *file)
{
struct charlcd_priv *priv = to_priv(the_charlcd);
if (!atomic_dec_and_test(&charlcd_available))
return -EBUSY;
if (file->f_mode & FMODE_READ)
return -EPERM;
if (priv->must_clear) {
charlcd_clear_display(&priv->lcd);
priv->must_clear = false;
}
return nonseekable_open(inode, file);
}
static int charlcd_release(struct inode *inode, struct file *file)
{
atomic_inc(&charlcd_available);
return 0;
}
static void charlcd_puts(struct charlcd *lcd, const char *s)
{
const char *tmp = s;
int count = strlen(s);
for (; count-- > 0; tmp++) {
if (!in_interrupt() && (((count + 1) & 0x1f) == 0))
schedule();
charlcd_write_char(lcd, *tmp);
}
}
static int charlcd_init(struct charlcd *lcd)
{
struct charlcd_priv *priv = to_priv(lcd);
int ret;
if (lcd->ops->backlight) {
mutex_init(&priv->bl_tempo_lock);
INIT_DELAYED_WORK(&priv->bl_work, charlcd_bl_off);
}
ret = charlcd_init_display(lcd);
if (ret)
return ret;
#ifdef CONFIG_PANEL_CHANGE_MESSAGE
#ifdef CONFIG_PANEL_BOOT_MESSAGE
charlcd_puts(lcd, "\x1b[Lc\x1b[Lb\x1b[L*" CONFIG_PANEL_BOOT_MESSAGE);
#endif
#else
charlcd_puts(lcd, "\x1b[Lc\x1b[Lb\x1b[L*Linux-" UTS_RELEASE "\n");
#endif
priv->must_clear = true;
charlcd_home(lcd);
return 0;
}
struct charlcd *charlcd_alloc(unsigned int drvdata_size)
{
struct charlcd_priv *priv;
struct charlcd *lcd;
priv = kzalloc(sizeof(*priv) + drvdata_size, GFP_KERNEL);
if (!priv)
return NULL;
priv->esc_seq.len = -1;
lcd = &priv->lcd;
lcd->ifwidth = 8;
lcd->bwidth = DEFAULT_LCD_BWIDTH;
lcd->hwidth = DEFAULT_LCD_HWIDTH;
lcd->drvdata = priv->drvdata;
return lcd;
}
static int panel_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
struct charlcd *lcd = the_charlcd;
switch (code) {
case SYS_DOWN:
charlcd_puts(lcd,
"\x0cReloading\nSystem...\x1b[Lc\x1b[Lb\x1b[L+");
break;
case SYS_HALT:
charlcd_puts(lcd, "\x0cSystem Halted.\x1b[Lc\x1b[Lb\x1b[L+");
break;
case SYS_POWER_OFF:
charlcd_puts(lcd, "\x0cPower off.\x1b[Lc\x1b[Lb\x1b[L+");
break;
default:
break;
}
return NOTIFY_DONE;
}
int charlcd_register(struct charlcd *lcd)
{
int ret;
ret = charlcd_init(lcd);
if (ret)
return ret;
ret = misc_register(&charlcd_dev);
if (ret)
return ret;
the_charlcd = lcd;
register_reboot_notifier(&panel_notifier);
return 0;
}
int charlcd_unregister(struct charlcd *lcd)
{
struct charlcd_priv *priv = to_priv(lcd);
unregister_reboot_notifier(&panel_notifier);
charlcd_puts(lcd, "\x0cLCD driver unloaded.\x1b[Lc\x1b[Lb\x1b[L-");
misc_deregister(&charlcd_dev);
the_charlcd = NULL;
if (lcd->ops->backlight) {
cancel_delayed_work_sync(&priv->bl_work);
priv->lcd.ops->backlight(&priv->lcd, 0);
}
return 0;
}
