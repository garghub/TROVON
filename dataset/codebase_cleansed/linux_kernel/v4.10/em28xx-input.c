static int em28xx_get_key_terratec(struct i2c_client *i2c_dev,
enum rc_type *protocol, u32 *scancode)
{
unsigned char b;
if (1 != i2c_master_recv(i2c_dev, &b, 1))
return -EIO;
if (b == 0xff)
return 0;
if (b == 0xfe)
return 1;
*protocol = RC_TYPE_UNKNOWN;
*scancode = b;
return 1;
}
static int em28xx_get_key_em_haup(struct i2c_client *i2c_dev,
enum rc_type *protocol, u32 *scancode)
{
unsigned char buf[2];
int size;
size = i2c_master_recv(i2c_dev, buf, sizeof(buf));
if (size != 2)
return -EIO;
if (buf[1] == 0xff)
return 0;
*protocol = RC_TYPE_RC5;
*scancode = (bitrev8(buf[1]) & 0x1f) << 8 | bitrev8(buf[0]) >> 2;
return 1;
}
static int em28xx_get_key_pinnacle_usb_grey(struct i2c_client *i2c_dev,
enum rc_type *protocol, u32 *scancode)
{
unsigned char buf[3];
if (3 != i2c_master_recv(i2c_dev, buf, 3))
return -EIO;
if (buf[0] != 0x00)
return 0;
*protocol = RC_TYPE_UNKNOWN;
*scancode = buf[2] & 0x3f;
return 1;
}
static int em28xx_get_key_winfast_usbii_deluxe(struct i2c_client *i2c_dev,
enum rc_type *protocol, u32 *scancode)
{
unsigned char subaddr, keydetect, key;
struct i2c_msg msg[] = { { .addr = i2c_dev->addr, .flags = 0, .buf = &subaddr, .len = 1},
{ .addr = i2c_dev->addr, .flags = I2C_M_RD, .buf = &keydetect, .len = 1} };
subaddr = 0x10;
if (2 != i2c_transfer(i2c_dev->adapter, msg, 2))
return -EIO;
if (keydetect == 0x00)
return 0;
subaddr = 0x00;
msg[1].buf = &key;
if (2 != i2c_transfer(i2c_dev->adapter, msg, 2))
return -EIO;
if (key == 0x00)
return 0;
*protocol = RC_TYPE_UNKNOWN;
*scancode = key;
return 1;
}
static int default_polling_getkey(struct em28xx_IR *ir,
struct em28xx_ir_poll_result *poll_result)
{
struct em28xx *dev = ir->dev;
int rc;
u8 msg[3] = { 0, 0, 0 };
rc = dev->em28xx_read_reg_req_len(dev, 0, EM28XX_R45_IR,
msg, sizeof(msg));
if (rc < 0)
return rc;
poll_result->toggle_bit = (msg[0] >> 7);
poll_result->read_count = (msg[0] & 0x7f);
switch (ir->rc_type) {
case RC_BIT_RC5:
poll_result->protocol = RC_TYPE_RC5;
poll_result->scancode = RC_SCANCODE_RC5(msg[1], msg[2]);
break;
case RC_BIT_NEC:
poll_result->protocol = RC_TYPE_NEC;
poll_result->scancode = RC_SCANCODE_NEC(msg[1], msg[2]);
break;
default:
poll_result->protocol = RC_TYPE_UNKNOWN;
poll_result->scancode = msg[1] << 8 | msg[2];
break;
}
return 0;
}
static int em2874_polling_getkey(struct em28xx_IR *ir,
struct em28xx_ir_poll_result *poll_result)
{
struct em28xx *dev = ir->dev;
int rc;
u8 msg[5] = { 0, 0, 0, 0, 0 };
rc = dev->em28xx_read_reg_req_len(dev, 0, EM2874_R51_IR,
msg, sizeof(msg));
if (rc < 0)
return rc;
poll_result->toggle_bit = (msg[0] >> 7);
poll_result->read_count = (msg[0] & 0x7f);
switch (ir->rc_type) {
case RC_BIT_RC5:
poll_result->protocol = RC_TYPE_RC5;
poll_result->scancode = RC_SCANCODE_RC5(msg[1], msg[2]);
break;
case RC_BIT_NEC:
poll_result->protocol = RC_TYPE_RC5;
poll_result->scancode = msg[1] << 8 | msg[2];
if ((msg[3] ^ msg[4]) != 0xff)
poll_result->scancode = RC_SCANCODE_NEC32((msg[1] << 24) |
(msg[2] << 16) |
(msg[3] << 8) |
(msg[4]));
else if ((msg[1] ^ msg[2]) != 0xff)
poll_result->scancode = RC_SCANCODE_NECX(msg[1] << 8 |
msg[2], msg[3]);
else
poll_result->scancode = RC_SCANCODE_NEC(msg[1], msg[3]);
break;
case RC_BIT_RC6_0:
poll_result->protocol = RC_TYPE_RC6_0;
poll_result->scancode = RC_SCANCODE_RC6_0(msg[1], msg[2]);
break;
default:
poll_result->protocol = RC_TYPE_UNKNOWN;
poll_result->scancode = (msg[1] << 24) | (msg[2] << 16) |
(msg[3] << 8) | msg[4];
break;
}
return 0;
}
static int em28xx_i2c_ir_handle_key(struct em28xx_IR *ir)
{
static u32 scancode;
enum rc_type protocol;
int rc;
rc = ir->get_key_i2c(ir->i2c_client, &protocol, &scancode);
if (rc < 0) {
dprintk("ir->get_key_i2c() failed: %d\n", rc);
return rc;
}
if (rc) {
dprintk("%s: proto = 0x%04x, scancode = 0x%04x\n",
__func__, protocol, scancode);
rc_keydown(ir->rc, protocol, scancode, 0);
}
return 0;
}
static void em28xx_ir_handle_key(struct em28xx_IR *ir)
{
int result;
struct em28xx_ir_poll_result poll_result;
result = ir->get_key(ir, &poll_result);
if (unlikely(result < 0)) {
dprintk("ir->get_key() failed: %d\n", result);
return;
}
if (unlikely(poll_result.read_count != ir->last_readcount)) {
dprintk("%s: toggle: %d, count: %d, key 0x%04x\n", __func__,
poll_result.toggle_bit, poll_result.read_count,
poll_result.scancode);
if (ir->full_code)
rc_keydown(ir->rc,
poll_result.protocol,
poll_result.scancode,
poll_result.toggle_bit);
else
rc_keydown(ir->rc,
RC_TYPE_UNKNOWN,
poll_result.scancode & 0xff,
poll_result.toggle_bit);
if (ir->dev->chip_id == CHIP_ID_EM2874 ||
ir->dev->chip_id == CHIP_ID_EM2884)
ir->last_readcount = 0;
else
ir->last_readcount = poll_result.read_count;
}
}
static void em28xx_ir_work(struct work_struct *work)
{
struct em28xx_IR *ir = container_of(work, struct em28xx_IR, work.work);
if (ir->i2c_client)
em28xx_i2c_ir_handle_key(ir);
else
em28xx_ir_handle_key(ir);
schedule_delayed_work(&ir->work, msecs_to_jiffies(ir->polling));
}
static int em28xx_ir_start(struct rc_dev *rc)
{
struct em28xx_IR *ir = rc->priv;
INIT_DELAYED_WORK(&ir->work, em28xx_ir_work);
schedule_delayed_work(&ir->work, 0);
return 0;
}
static void em28xx_ir_stop(struct rc_dev *rc)
{
struct em28xx_IR *ir = rc->priv;
cancel_delayed_work_sync(&ir->work);
}
static int em2860_ir_change_protocol(struct rc_dev *rc_dev, u64 *rc_type)
{
struct em28xx_IR *ir = rc_dev->priv;
struct em28xx *dev = ir->dev;
if (*rc_type & RC_BIT_RC5) {
dev->board.xclk |= EM28XX_XCLK_IR_RC5_MODE;
ir->full_code = 1;
*rc_type = RC_BIT_RC5;
} else if (*rc_type & RC_BIT_NEC) {
dev->board.xclk &= ~EM28XX_XCLK_IR_RC5_MODE;
ir->full_code = 1;
*rc_type = RC_BIT_NEC;
} else if (*rc_type & RC_BIT_UNKNOWN) {
*rc_type = RC_BIT_UNKNOWN;
} else {
*rc_type = ir->rc_type;
return -EINVAL;
}
em28xx_write_reg_bits(dev, EM28XX_R0F_XCLK, dev->board.xclk,
EM28XX_XCLK_IR_RC5_MODE);
ir->rc_type = *rc_type;
return 0;
}
static int em2874_ir_change_protocol(struct rc_dev *rc_dev, u64 *rc_type)
{
struct em28xx_IR *ir = rc_dev->priv;
struct em28xx *dev = ir->dev;
u8 ir_config = EM2874_IR_RC5;
if (*rc_type & RC_BIT_RC5) {
dev->board.xclk |= EM28XX_XCLK_IR_RC5_MODE;
ir->full_code = 1;
*rc_type = RC_BIT_RC5;
} else if (*rc_type & RC_BIT_NEC) {
dev->board.xclk &= ~EM28XX_XCLK_IR_RC5_MODE;
ir_config = EM2874_IR_NEC | EM2874_IR_NEC_NO_PARITY;
ir->full_code = 1;
*rc_type = RC_BIT_NEC;
} else if (*rc_type & RC_BIT_RC6_0) {
dev->board.xclk |= EM28XX_XCLK_IR_RC5_MODE;
ir_config = EM2874_IR_RC6_MODE_0;
ir->full_code = 1;
*rc_type = RC_BIT_RC6_0;
} else if (*rc_type & RC_BIT_UNKNOWN) {
*rc_type = RC_BIT_UNKNOWN;
} else {
*rc_type = ir->rc_type;
return -EINVAL;
}
em28xx_write_regs(dev, EM2874_R50_IR_CONFIG, &ir_config, 1);
em28xx_write_reg_bits(dev, EM28XX_R0F_XCLK, dev->board.xclk,
EM28XX_XCLK_IR_RC5_MODE);
ir->rc_type = *rc_type;
return 0;
}
static int em28xx_ir_change_protocol(struct rc_dev *rc_dev, u64 *rc_type)
{
struct em28xx_IR *ir = rc_dev->priv;
struct em28xx *dev = ir->dev;
switch (dev->chip_id) {
case CHIP_ID_EM2860:
case CHIP_ID_EM2883:
return em2860_ir_change_protocol(rc_dev, rc_type);
case CHIP_ID_EM2884:
case CHIP_ID_EM2874:
case CHIP_ID_EM28174:
case CHIP_ID_EM28178:
return em2874_ir_change_protocol(rc_dev, rc_type);
default:
dev_err(&ir->dev->intf->dev,
"Unrecognized em28xx chip id 0x%02x: IR not supported\n",
dev->chip_id);
return -EINVAL;
}
}
static int em28xx_probe_i2c_ir(struct em28xx *dev)
{
int i = 0;
const unsigned short addr_list[] = {
0x1f, 0x30, 0x47, I2C_CLIENT_END
};
while (addr_list[i] != I2C_CLIENT_END) {
if (i2c_probe_func_quick_read(&dev->i2c_adap[dev->def_i2c_bus], addr_list[i]) == 1)
return addr_list[i];
i++;
}
return -ENODEV;
}
static void em28xx_query_buttons(struct work_struct *work)
{
struct em28xx *dev =
container_of(work, struct em28xx, buttons_query_work.work);
u8 i, j;
int regval;
bool is_pressed, was_pressed;
const struct em28xx_led *led;
for (i = 0; i < dev->num_button_polling_addresses; i++) {
regval = em28xx_read_reg(dev, dev->button_polling_addresses[i]);
if (regval < 0)
continue;
j = 0;
while (dev->board.buttons[j].role >= 0 &&
dev->board.buttons[j].role < EM28XX_NUM_BUTTON_ROLES) {
struct em28xx_button *button = &dev->board.buttons[j];
if (button->reg_r != dev->button_polling_addresses[i]) {
j++;
continue;
}
is_pressed = regval & button->mask;
was_pressed = dev->button_polling_last_values[i]
& button->mask;
if (button->inverted) {
is_pressed = !is_pressed;
was_pressed = !was_pressed;
}
if (is_pressed && button->reg_clearing)
em28xx_write_reg(dev, button->reg_clearing,
(~regval & button->mask)
| (regval & ~button->mask));
if (!is_pressed || was_pressed) {
j++;
continue;
}
switch (button->role) {
case EM28XX_BUTTON_SNAPSHOT:
input_report_key(dev->sbutton_input_dev,
EM28XX_SNAPSHOT_KEY, 1);
input_report_key(dev->sbutton_input_dev,
EM28XX_SNAPSHOT_KEY, 0);
break;
case EM28XX_BUTTON_ILLUMINATION:
led = em28xx_find_led(dev,
EM28XX_LED_ILLUMINATION);
if (led)
em28xx_toggle_reg_bits(dev,
led->gpio_reg,
led->gpio_mask);
break;
default:
WARN_ONCE(1, "BUG: unhandled button role.");
}
j++;
}
dev->button_polling_last_values[i] = regval;
}
schedule_delayed_work(&dev->buttons_query_work,
msecs_to_jiffies(dev->button_polling_interval));
}
static int em28xx_register_snapshot_button(struct em28xx *dev)
{
struct usb_device *udev = interface_to_usbdev(dev->intf);
struct input_dev *input_dev;
int err;
dev_info(&dev->intf->dev, "Registering snapshot button...\n");
input_dev = input_allocate_device();
if (!input_dev)
return -ENOMEM;
usb_make_path(udev, dev->snapshot_button_path,
sizeof(dev->snapshot_button_path));
strlcat(dev->snapshot_button_path, "/sbutton",
sizeof(dev->snapshot_button_path));
input_dev->name = "em28xx snapshot button";
input_dev->phys = dev->snapshot_button_path;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
set_bit(EM28XX_SNAPSHOT_KEY, input_dev->keybit);
input_dev->keycodesize = 0;
input_dev->keycodemax = 0;
input_dev->id.bustype = BUS_USB;
input_dev->id.vendor = le16_to_cpu(udev->descriptor.idVendor);
input_dev->id.product = le16_to_cpu(udev->descriptor.idProduct);
input_dev->id.version = 1;
input_dev->dev.parent = &dev->intf->dev;
err = input_register_device(input_dev);
if (err) {
dev_err(&dev->intf->dev, "input_register_device failed\n");
input_free_device(input_dev);
return err;
}
dev->sbutton_input_dev = input_dev;
return 0;
}
static void em28xx_init_buttons(struct em28xx *dev)
{
u8 i = 0, j = 0;
bool addr_new = false;
dev->button_polling_interval = EM28XX_BUTTONS_DEBOUNCED_QUERY_INTERVAL;
while (dev->board.buttons[i].role >= 0 &&
dev->board.buttons[i].role < EM28XX_NUM_BUTTON_ROLES) {
struct em28xx_button *button = &dev->board.buttons[i];
addr_new = true;
for (j = 0; j < dev->num_button_polling_addresses; j++) {
if (button->reg_r == dev->button_polling_addresses[j]) {
addr_new = false;
break;
}
}
if (addr_new && dev->num_button_polling_addresses
>= EM28XX_NUM_BUTTON_ADDRESSES_MAX) {
WARN_ONCE(1, "BUG: maximum number of button polling addresses exceeded.");
goto next_button;
}
if (button->role == EM28XX_BUTTON_SNAPSHOT) {
if (em28xx_register_snapshot_button(dev) < 0)
goto next_button;
} else if (button->role == EM28XX_BUTTON_ILLUMINATION) {
if (!em28xx_find_led(dev, EM28XX_LED_ILLUMINATION)) {
dev_err(&dev->intf->dev,
"BUG: illumination button defined, but no illumination LED.\n");
goto next_button;
}
}
if (addr_new) {
unsigned int index = dev->num_button_polling_addresses;
dev->button_polling_addresses[index] = button->reg_r;
dev->num_button_polling_addresses++;
}
if (!button->reg_clearing)
dev->button_polling_interval =
EM28XX_BUTTONS_VOLATILE_QUERY_INTERVAL;
next_button:
i++;
}
if (dev->num_button_polling_addresses) {
memset(dev->button_polling_last_values, 0,
EM28XX_NUM_BUTTON_ADDRESSES_MAX);
schedule_delayed_work(&dev->buttons_query_work,
msecs_to_jiffies(dev->button_polling_interval));
}
}
static void em28xx_shutdown_buttons(struct em28xx *dev)
{
cancel_delayed_work_sync(&dev->buttons_query_work);
dev->num_button_polling_addresses = 0;
if (dev->sbutton_input_dev != NULL) {
dev_info(&dev->intf->dev, "Deregistering snapshot button\n");
input_unregister_device(dev->sbutton_input_dev);
dev->sbutton_input_dev = NULL;
}
}
static int em28xx_ir_init(struct em28xx *dev)
{
struct usb_device *udev = interface_to_usbdev(dev->intf);
struct em28xx_IR *ir;
struct rc_dev *rc;
int err = -ENOMEM;
u64 rc_type;
u16 i2c_rc_dev_addr = 0;
if (dev->is_audio_only) {
return 0;
}
kref_get(&dev->ref);
INIT_DELAYED_WORK(&dev->buttons_query_work, em28xx_query_buttons);
if (dev->board.buttons)
em28xx_init_buttons(dev);
if (dev->board.has_ir_i2c) {
i2c_rc_dev_addr = em28xx_probe_i2c_ir(dev);
if (!i2c_rc_dev_addr) {
dev->board.has_ir_i2c = 0;
dev_warn(&dev->intf->dev,
"No i2c IR remote control device found.\n");
return -ENODEV;
}
}
if (dev->board.ir_codes == NULL && !dev->board.has_ir_i2c) {
dev_warn(&dev->intf->dev,
"Remote control support is not available for this card.\n");
return 0;
}
dev_info(&dev->intf->dev, "Registering input extension\n");
ir = kzalloc(sizeof(*ir), GFP_KERNEL);
if (!ir)
return -ENOMEM;
rc = rc_allocate_device();
if (!rc)
goto error;
ir->dev = dev;
dev->ir = ir;
ir->rc = rc;
rc->priv = ir;
rc->open = em28xx_ir_start;
rc->close = em28xx_ir_stop;
if (dev->board.has_ir_i2c) {
switch (dev->model) {
case EM2800_BOARD_TERRATEC_CINERGY_200:
case EM2820_BOARD_TERRATEC_CINERGY_250:
rc->map_name = RC_MAP_EM_TERRATEC;
ir->get_key_i2c = em28xx_get_key_terratec;
break;
case EM2820_BOARD_PINNACLE_USB_2:
rc->map_name = RC_MAP_PINNACLE_GREY;
ir->get_key_i2c = em28xx_get_key_pinnacle_usb_grey;
break;
case EM2820_BOARD_HAUPPAUGE_WINTV_USB_2:
rc->map_name = RC_MAP_HAUPPAUGE;
ir->get_key_i2c = em28xx_get_key_em_haup;
rc->allowed_protocols = RC_BIT_RC5;
break;
case EM2820_BOARD_LEADTEK_WINFAST_USBII_DELUXE:
rc->map_name = RC_MAP_WINFAST_USBII_DELUXE;
ir->get_key_i2c = em28xx_get_key_winfast_usbii_deluxe;
break;
default:
err = -ENODEV;
goto error;
}
ir->i2c_client = kzalloc(sizeof(struct i2c_client), GFP_KERNEL);
if (!ir->i2c_client)
goto error;
ir->i2c_client->adapter = &ir->dev->i2c_adap[dev->def_i2c_bus];
ir->i2c_client->addr = i2c_rc_dev_addr;
ir->i2c_client->flags = 0;
} else {
switch (dev->chip_id) {
case CHIP_ID_EM2860:
case CHIP_ID_EM2883:
rc->allowed_protocols = RC_BIT_RC5 | RC_BIT_NEC;
ir->get_key = default_polling_getkey;
break;
case CHIP_ID_EM2884:
case CHIP_ID_EM2874:
case CHIP_ID_EM28174:
case CHIP_ID_EM28178:
ir->get_key = em2874_polling_getkey;
rc->allowed_protocols = RC_BIT_RC5 | RC_BIT_NEC |
RC_BIT_RC6_0;
break;
default:
err = -ENODEV;
goto error;
}
rc->change_protocol = em28xx_ir_change_protocol;
rc->map_name = dev->board.ir_codes;
rc_type = RC_BIT_UNKNOWN;
err = em28xx_ir_change_protocol(rc, &rc_type);
if (err)
goto error;
}
ir->polling = 100;
snprintf(ir->name, sizeof(ir->name), "%s IR",
dev_name(&dev->intf->dev));
usb_make_path(udev, ir->phys, sizeof(ir->phys));
strlcat(ir->phys, "/input0", sizeof(ir->phys));
rc->input_name = ir->name;
rc->input_phys = ir->phys;
rc->input_id.bustype = BUS_USB;
rc->input_id.version = 1;
rc->input_id.vendor = le16_to_cpu(udev->descriptor.idVendor);
rc->input_id.product = le16_to_cpu(udev->descriptor.idProduct);
rc->dev.parent = &dev->intf->dev;
rc->driver_name = MODULE_NAME;
err = rc_register_device(rc);
if (err)
goto error;
dev_info(&dev->intf->dev, "Input extension successfully initalized\n");
return 0;
error:
kfree(ir->i2c_client);
dev->ir = NULL;
rc_free_device(rc);
kfree(ir);
return err;
}
static int em28xx_ir_fini(struct em28xx *dev)
{
struct em28xx_IR *ir = dev->ir;
if (dev->is_audio_only) {
return 0;
}
dev_info(&dev->intf->dev, "Closing input extension\n");
em28xx_shutdown_buttons(dev);
if (!ir)
goto ref_put;
rc_unregister_device(ir->rc);
kfree(ir->i2c_client);
kfree(ir);
dev->ir = NULL;
ref_put:
kref_put(&dev->ref, em28xx_free_device);
return 0;
}
static int em28xx_ir_suspend(struct em28xx *dev)
{
struct em28xx_IR *ir = dev->ir;
if (dev->is_audio_only)
return 0;
dev_info(&dev->intf->dev, "Suspending input extension\n");
if (ir)
cancel_delayed_work_sync(&ir->work);
cancel_delayed_work_sync(&dev->buttons_query_work);
return 0;
}
static int em28xx_ir_resume(struct em28xx *dev)
{
struct em28xx_IR *ir = dev->ir;
if (dev->is_audio_only)
return 0;
dev_info(&dev->intf->dev, "Resuming input extension\n");
if (ir)
schedule_delayed_work(&ir->work, msecs_to_jiffies(ir->polling));
if (dev->num_button_polling_addresses)
schedule_delayed_work(&dev->buttons_query_work,
msecs_to_jiffies(dev->button_polling_interval));
return 0;
}
static int __init em28xx_rc_register(void)
{
return em28xx_register_extension(&rc_ops);
}
static void __exit em28xx_rc_unregister(void)
{
em28xx_unregister_extension(&rc_ops);
}
