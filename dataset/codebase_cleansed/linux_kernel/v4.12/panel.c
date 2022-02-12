static void lcd_get_bits(unsigned int port, int *val)
{
unsigned int bit, state;
for (bit = 0; bit < LCD_BITS; bit++) {
state = test_bit(bit, bits) ? BIT_SET : BIT_CLR;
*val &= lcd_bits[port][bit][BIT_MSK];
*val |= lcd_bits[port][bit][state];
}
}
static int set_data_bits(void)
{
int val;
val = r_dtr(pprt);
lcd_get_bits(LCD_PORT_D, &val);
w_dtr(pprt, val);
return val;
}
static int set_ctrl_bits(void)
{
int val;
val = r_ctr(pprt);
lcd_get_bits(LCD_PORT_C, &val);
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
static void lcd_send_serial(int byte)
{
int bit;
for (bit = 0; bit < 8; bit++) {
clear_bit(LCD_BIT_CL, bits);
panel_set_bits();
if (byte & 1) {
set_bit(LCD_BIT_DA, bits);
} else {
clear_bit(LCD_BIT_DA, bits);
}
panel_set_bits();
udelay(2);
set_bit(LCD_BIT_CL, bits);
panel_set_bits();
udelay(1);
byte >>= 1;
}
}
static void lcd_backlight(struct charlcd *charlcd, int on)
{
if (lcd.pins.bl == PIN_NONE)
return;
spin_lock_irq(&pprt_lock);
if (on)
set_bit(LCD_BIT_BL, bits);
else
clear_bit(LCD_BIT_BL, bits);
panel_set_bits();
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_cmd_s(struct charlcd *charlcd, int cmd)
{
spin_lock_irq(&pprt_lock);
lcd_send_serial(0x1F);
lcd_send_serial(cmd & 0x0F);
lcd_send_serial((cmd >> 4) & 0x0F);
udelay(40);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_data_s(struct charlcd *charlcd, int data)
{
spin_lock_irq(&pprt_lock);
lcd_send_serial(0x5F);
lcd_send_serial(data & 0x0F);
lcd_send_serial((data >> 4) & 0x0F);
udelay(40);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_cmd_p8(struct charlcd *charlcd, int cmd)
{
spin_lock_irq(&pprt_lock);
w_dtr(pprt, cmd);
udelay(20);
set_bit(LCD_BIT_E, bits);
clear_bit(LCD_BIT_RS, bits);
clear_bit(LCD_BIT_RW, bits);
set_ctrl_bits();
udelay(40);
clear_bit(LCD_BIT_E, bits);
set_ctrl_bits();
udelay(120);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_data_p8(struct charlcd *charlcd, int data)
{
spin_lock_irq(&pprt_lock);
w_dtr(pprt, data);
udelay(20);
set_bit(LCD_BIT_E, bits);
set_bit(LCD_BIT_RS, bits);
clear_bit(LCD_BIT_RW, bits);
set_ctrl_bits();
udelay(40);
clear_bit(LCD_BIT_E, bits);
set_ctrl_bits();
udelay(45);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_cmd_tilcd(struct charlcd *charlcd, int cmd)
{
spin_lock_irq(&pprt_lock);
w_ctr(pprt, cmd);
udelay(60);
spin_unlock_irq(&pprt_lock);
}
static void lcd_write_data_tilcd(struct charlcd *charlcd, int data)
{
spin_lock_irq(&pprt_lock);
w_dtr(pprt, data);
udelay(60);
spin_unlock_irq(&pprt_lock);
}
static void lcd_clear_fast_s(struct charlcd *charlcd)
{
int pos;
spin_lock_irq(&pprt_lock);
for (pos = 0; pos < charlcd->height * charlcd->hwidth; pos++) {
lcd_send_serial(0x5F);
lcd_send_serial(' ' & 0x0F);
lcd_send_serial((' ' >> 4) & 0x0F);
udelay(40);
}
spin_unlock_irq(&pprt_lock);
}
static void lcd_clear_fast_p8(struct charlcd *charlcd)
{
int pos;
spin_lock_irq(&pprt_lock);
for (pos = 0; pos < charlcd->height * charlcd->hwidth; pos++) {
w_dtr(pprt, ' ');
udelay(20);
set_bit(LCD_BIT_E, bits);
set_bit(LCD_BIT_RS, bits);
clear_bit(LCD_BIT_RW, bits);
set_ctrl_bits();
udelay(40);
clear_bit(LCD_BIT_E, bits);
set_ctrl_bits();
udelay(45);
}
spin_unlock_irq(&pprt_lock);
}
static void lcd_clear_fast_tilcd(struct charlcd *charlcd)
{
int pos;
spin_lock_irq(&pprt_lock);
for (pos = 0; pos < charlcd->height * charlcd->hwidth; pos++) {
w_dtr(pprt, ' ');
udelay(60);
}
spin_unlock_irq(&pprt_lock);
}
static void lcd_init(void)
{
struct charlcd *charlcd;
charlcd = charlcd_alloc(0);
if (!charlcd)
return;
charlcd->height = lcd_height;
charlcd->width = lcd_width;
charlcd->bwidth = lcd_bwidth;
charlcd->hwidth = lcd_hwidth;
switch (selected_lcd_type) {
case LCD_TYPE_OLD:
lcd.proto = LCD_PROTO_PARALLEL;
lcd.charset = LCD_CHARSET_NORMAL;
lcd.pins.e = PIN_STROBE;
lcd.pins.rs = PIN_AUTOLF;
charlcd->width = 40;
charlcd->bwidth = 40;
charlcd->hwidth = 64;
charlcd->height = 2;
break;
case LCD_TYPE_KS0074:
lcd.proto = LCD_PROTO_SERIAL;
lcd.charset = LCD_CHARSET_KS0074;
lcd.pins.bl = PIN_AUTOLF;
lcd.pins.cl = PIN_STROBE;
lcd.pins.da = PIN_D0;
charlcd->width = 16;
charlcd->bwidth = 40;
charlcd->hwidth = 16;
charlcd->height = 2;
break;
case LCD_TYPE_NEXCOM:
lcd.proto = LCD_PROTO_PARALLEL;
lcd.charset = LCD_CHARSET_NORMAL;
lcd.pins.e = PIN_AUTOLF;
lcd.pins.rs = PIN_SELECP;
lcd.pins.rw = PIN_INITP;
charlcd->width = 16;
charlcd->bwidth = 40;
charlcd->hwidth = 64;
charlcd->height = 2;
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
charlcd->width = 16;
charlcd->bwidth = 40;
charlcd->hwidth = 64;
charlcd->height = 2;
break;
}
if (lcd_height != NOT_SET)
charlcd->height = lcd_height;
if (lcd_width != NOT_SET)
charlcd->width = lcd_width;
if (lcd_bwidth != NOT_SET)
charlcd->bwidth = lcd_bwidth;
if (lcd_hwidth != NOT_SET)
charlcd->hwidth = lcd_hwidth;
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
if (charlcd->width <= 0)
charlcd->width = DEFAULT_LCD_WIDTH;
if (charlcd->bwidth <= 0)
charlcd->bwidth = DEFAULT_LCD_BWIDTH;
if (charlcd->hwidth <= 0)
charlcd->hwidth = DEFAULT_LCD_HWIDTH;
if (charlcd->height <= 0)
charlcd->height = DEFAULT_LCD_HEIGHT;
if (lcd.proto == LCD_PROTO_SERIAL) {
charlcd->ops = &charlcd_serial_ops;
if (lcd.pins.cl == PIN_NOT_SET)
lcd.pins.cl = DEFAULT_LCD_PIN_SCL;
if (lcd.pins.da == PIN_NOT_SET)
lcd.pins.da = DEFAULT_LCD_PIN_SDA;
} else if (lcd.proto == LCD_PROTO_PARALLEL) {
charlcd->ops = &charlcd_parallel_ops;
if (lcd.pins.e == PIN_NOT_SET)
lcd.pins.e = DEFAULT_LCD_PIN_E;
if (lcd.pins.rs == PIN_NOT_SET)
lcd.pins.rs = DEFAULT_LCD_PIN_RS;
if (lcd.pins.rw == PIN_NOT_SET)
lcd.pins.rw = DEFAULT_LCD_PIN_RW;
} else {
charlcd->ops = &charlcd_tilcd_ops;
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
charlcd->char_conv = lcd_char_conv_ks0074;
else
charlcd->char_conv = NULL;
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
lcd.charlcd = charlcd;
lcd.initialized = true;
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
phys_read |= (__u64)gndmask << 40;
if (bitmask != gndmask) {
for (bit = 0; bit < 8; bit++) {
bitval = BIT(bit);
if (!(scan_mask_o & bitval))
continue;
w_dtr(pprt, oldval & ~bitval);
bitmask = PNL_PINPUT(r_str(pprt)) & ~gndmask;
phys_read |= (__u64)bitmask << (5 * bit);
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
if (input->u.std.press_fct)
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
if (release_fct)
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
if (keypressed && lcd.enabled && lcd.initialized)
charlcd_poke(lcd.charlcd);
mod_timer(&scan_timer, jiffies + INPUT_POLL_TIME);
}
static void init_scan_timer(void)
{
if (scan_timer.function)
return;
setup_timer(&scan_timer, (void *)&panel_scan_timer, 0);
scan_timer.expires = jiffies + INPUT_POLL_TIME;
add_timer(&scan_timer);
}
static u8 input_name2mask(const char *name, __u64 *mask, __u64 *value,
u8 *imask, u8 *omask)
{
const char sigtab[] = "EeSsPpAaBb";
u8 im, om;
__u64 m, v;
om = 0;
im = 0;
m = 0ULL;
v = 0ULL;
while (*name) {
int in, out, bit, neg;
const char *idx;
idx = strchr(sigtab, *name);
if (!idx)
return 0;
in = idx - sigtab;
neg = (in & 1);
in >>= 1;
im |= BIT(in);
name++;
if (*name >= '0' && *name <= '7') {
out = *name - '0';
om |= BIT(out);
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
static void panel_attach(struct parport *port)
{
struct pardev_cb panel_cb;
if (port->number != parport)
return;
if (pprt) {
pr_err("%s: port->number=%d parport=%d, already registered!\n",
__func__, port->number, parport);
return;
}
memset(&panel_cb, 0, sizeof(panel_cb));
panel_cb.private = &pprt;
pprt = parport_register_dev_model(port, "panel", &panel_cb, 0);
if (!pprt) {
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
if (!lcd.charlcd || charlcd_register(lcd.charlcd))
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
charlcd_unregister(lcd.charlcd);
err_unreg_device:
kfree(lcd.charlcd);
lcd.charlcd = NULL;
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
if (scan_timer.function)
del_timer_sync(&scan_timer);
if (keypad.enabled) {
misc_deregister(&keypad_dev);
keypad_initialized = 0;
}
if (lcd.enabled) {
charlcd_unregister(lcd.charlcd);
lcd.initialized = false;
kfree(lcd.charlcd);
lcd.charlcd = NULL;
}
parport_release(pprt);
parport_unregister_device(pprt);
pprt = NULL;
}
static int __init panel_init_module(void)
{
int selected_keypad_type = NOT_SET, err;
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
if (lcd.enabled) {
lcd.charset = lcd_charset;
lcd.proto = lcd_proto;
lcd.pins.e = lcd_e_pin;
lcd.pins.rs = lcd_rs_pin;
lcd.pins.rw = lcd_rw_pin;
lcd.pins.cl = lcd_cl_pin;
lcd.pins.da = lcd_da_pin;
lcd.pins.bl = lcd_bl_pin;
}
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
if (!lcd.enabled && !keypad.enabled) {
pr_err("panel driver disabled.\n");
return -ENODEV;
}
err = parport_register_driver(&panel_driver);
if (err) {
pr_err("could not register with parport. Aborting.\n");
return err;
}
if (pprt)
pr_info("panel driver registered on parport%d (io=0x%lx).\n",
parport, pprt->port->base);
else
pr_info("panel driver not yet registered\n");
return 0;
}
static void __exit panel_cleanup_module(void)
{
parport_unregister_driver(&panel_driver);
}
