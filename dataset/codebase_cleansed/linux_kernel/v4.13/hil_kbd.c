static bool hil_dev_is_command_response(hil_packet p)
{
if ((p & ~HIL_CMDCT_POL) == (HIL_ERR_INT | HIL_PKT_CMD | HIL_CMD_POL))
return false;
if ((p & ~HIL_CMDCT_RPL) == (HIL_ERR_INT | HIL_PKT_CMD | HIL_CMD_RPL))
return false;
return true;
}
static void hil_dev_handle_command_response(struct hil_dev *dev)
{
hil_packet p;
char *buf;
int i, idx;
idx = dev->idx4 / 4;
p = dev->data[idx - 1];
switch (p & HIL_PKT_DATA_MASK) {
case HIL_CMD_IDD:
buf = dev->idd;
break;
case HIL_CMD_RSC:
buf = dev->rsc;
break;
case HIL_CMD_EXD:
buf = dev->exd;
break;
case HIL_CMD_RNM:
dev->rnm[HIL_PACKET_MAX_LENGTH] = 0;
buf = dev->rnm;
break;
default:
if (p != (HIL_ERR_INT | HIL_PKT_CMD)) {
printk(KERN_WARNING PREFIX "Device sent unknown record %x\n", p);
}
goto out;
}
for (i = 0; i < idx; i++)
buf[i] = dev->data[i] & HIL_PKT_DATA_MASK;
for (; i < HIL_PACKET_MAX_LENGTH; i++)
buf[i] = 0;
out:
complete(&dev->cmd_done);
}
static void hil_dev_handle_kbd_events(struct hil_dev *kbd)
{
struct input_dev *dev = kbd->dev;
int idx = kbd->idx4 / 4;
int i;
switch (kbd->data[0] & HIL_POL_CHARTYPE_MASK) {
case HIL_POL_CHARTYPE_NONE:
return;
case HIL_POL_CHARTYPE_ASCII:
for (i = 1; i < idx - 1; i++)
input_report_key(dev, kbd->data[i] & 0x7f, 1);
break;
case HIL_POL_CHARTYPE_RSVD1:
case HIL_POL_CHARTYPE_RSVD2:
case HIL_POL_CHARTYPE_BINARY:
for (i = 1; i < idx - 1; i++)
input_report_key(dev, kbd->data[i], 1);
break;
case HIL_POL_CHARTYPE_SET1:
for (i = 1; i < idx - 1; i++) {
unsigned int key = kbd->data[i];
int up = key & HIL_KBD_SET1_UPBIT;
key &= (~HIL_KBD_SET1_UPBIT & 0xff);
key = hil_kbd_set1[key >> HIL_KBD_SET1_SHIFT];
input_report_key(dev, key, !up);
}
break;
case HIL_POL_CHARTYPE_SET2:
for (i = 1; i < idx - 1; i++) {
unsigned int key = kbd->data[i];
int up = key & HIL_KBD_SET2_UPBIT;
key &= (~HIL_KBD_SET1_UPBIT & 0xff);
key = key >> HIL_KBD_SET2_SHIFT;
input_report_key(dev, key, !up);
}
break;
case HIL_POL_CHARTYPE_SET3:
for (i = 1; i < idx - 1; i++) {
unsigned int key = kbd->data[i];
int up = key & HIL_KBD_SET3_UPBIT;
key &= (~HIL_KBD_SET1_UPBIT & 0xff);
key = hil_kbd_set3[key >> HIL_KBD_SET3_SHIFT];
input_report_key(dev, key, !up);
}
break;
}
input_sync(dev);
}
static void hil_dev_handle_ptr_events(struct hil_dev *ptr)
{
struct input_dev *dev = ptr->dev;
int idx = ptr->idx4 / 4;
hil_packet p = ptr->data[idx - 1];
int i, cnt, laxis;
bool absdev, ax16;
if ((p & HIL_CMDCT_POL) != idx - 1) {
printk(KERN_WARNING PREFIX
"Malformed poll packet %x (idx = %i)\n", p, idx);
return;
}
i = (p & HIL_POL_AXIS_ALT) ? 3 : 0;
laxis = (p & HIL_POL_NUM_AXES_MASK) + i;
ax16 = ptr->idd[1] & HIL_IDD_HEADER_16BIT;
absdev = ptr->idd[1] & HIL_IDD_HEADER_ABS;
for (cnt = 1; i < laxis; i++) {
unsigned int lo, hi, val;
lo = ptr->data[cnt++] & HIL_PKT_DATA_MASK;
hi = ax16 ? (ptr->data[cnt++] & HIL_PKT_DATA_MASK) : 0;
if (absdev) {
val = lo + (hi << 8);
#ifdef TABLET_AUTOADJUST
if (val < input_abs_get_min(dev, ABS_X + i))
input_abs_set_min(dev, ABS_X + i, val);
if (val > input_abs_get_max(dev, ABS_X + i))
input_abs_set_max(dev, ABS_X + i, val);
#endif
if (i % 3)
val = input_abs_get_max(dev, ABS_X + i) - val;
input_report_abs(dev, ABS_X + i, val);
} else {
val = (int) (((int8_t) lo) | ((int8_t) hi << 8));
if (i % 3)
val *= -1;
input_report_rel(dev, REL_X + i, val);
}
}
while (cnt < idx - 1) {
unsigned int btn = ptr->data[cnt++];
int up = btn & 1;
btn &= 0xfe;
if (btn == 0x8e)
continue;
if (btn > 0x8c || btn < 0x80)
continue;
btn = (btn - 0x80) >> 1;
btn = ptr->btnmap[btn];
input_report_key(dev, btn, !up);
}
input_sync(dev);
}
static void hil_dev_process_err(struct hil_dev *dev)
{
printk(KERN_WARNING PREFIX "errored HIL packet\n");
dev->idx4 = 0;
complete(&dev->cmd_done);
}
static irqreturn_t hil_dev_interrupt(struct serio *serio,
unsigned char data, unsigned int flags)
{
struct hil_dev *dev;
hil_packet packet;
int idx;
dev = serio_get_drvdata(serio);
BUG_ON(dev == NULL);
if (dev->idx4 >= HIL_PACKET_MAX_LENGTH * sizeof(hil_packet)) {
hil_dev_process_err(dev);
goto out;
}
idx = dev->idx4 / 4;
if (!(dev->idx4 % 4))
dev->data[idx] = 0;
packet = dev->data[idx];
packet |= ((hil_packet)data) << ((3 - (dev->idx4 % 4)) * 8);
dev->data[idx] = packet;
if ((++dev->idx4 % 4) == 0) {
if ((packet & 0xffff0000) != HIL_ERR_INT) {
hil_dev_process_err(dev);
} else if (packet & HIL_PKT_CMD) {
if (hil_dev_is_command_response(packet))
hil_dev_handle_command_response(dev);
else if (dev->is_pointer)
hil_dev_handle_ptr_events(dev);
else
hil_dev_handle_kbd_events(dev);
dev->idx4 = 0;
}
}
out:
return IRQ_HANDLED;
}
static void hil_dev_disconnect(struct serio *serio)
{
struct hil_dev *dev = serio_get_drvdata(serio);
BUG_ON(dev == NULL);
serio_close(serio);
input_unregister_device(dev->dev);
serio_set_drvdata(serio, NULL);
kfree(dev);
}
static void hil_dev_keyboard_setup(struct hil_dev *kbd)
{
struct input_dev *input_dev = kbd->dev;
uint8_t did = kbd->idd[0];
int i;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_dev->ledbit[0] = BIT_MASK(LED_NUML) | BIT_MASK(LED_CAPSL) |
BIT_MASK(LED_SCROLLL);
for (i = 0; i < 128; i++) {
__set_bit(hil_kbd_set1[i], input_dev->keybit);
__set_bit(hil_kbd_set3[i], input_dev->keybit);
}
__clear_bit(KEY_RESERVED, input_dev->keybit);
input_dev->keycodemax = HIL_KEYCODES_SET1_TBLSIZE;
input_dev->keycodesize = sizeof(hil_kbd_set1[0]);
input_dev->keycode = hil_kbd_set1;
input_dev->name = strlen(kbd->rnm) ? kbd->rnm : "HIL keyboard";
input_dev->phys = "hpkbd/input0";
printk(KERN_INFO PREFIX "HIL keyboard found (did = 0x%02x, lang = %s)\n",
did, hil_language[did & HIL_IDD_DID_TYPE_KB_LANG_MASK]);
}
static void hil_dev_pointer_setup(struct hil_dev *ptr)
{
struct input_dev *input_dev = ptr->dev;
uint8_t did = ptr->idd[0];
uint8_t *idd = ptr->idd + 1;
unsigned int naxsets = HIL_IDD_NUM_AXSETS(*idd);
unsigned int i, btntype;
const char *txt;
ptr->naxes = HIL_IDD_NUM_AXES_PER_SET(*idd);
switch (did & HIL_IDD_DID_TYPE_MASK) {
case HIL_IDD_DID_TYPE_REL:
input_dev->evbit[0] = BIT_MASK(EV_REL);
for (i = 0; i < ptr->naxes; i++)
__set_bit(REL_X + i, input_dev->relbit);
for (i = 3; naxsets > 1 && i < ptr->naxes + 3; i++)
__set_bit(REL_X + i, input_dev->relbit);
txt = "relative";
break;
case HIL_IDD_DID_TYPE_ABS:
input_dev->evbit[0] = BIT_MASK(EV_ABS);
for (i = 0; i < ptr->naxes; i++)
input_set_abs_params(input_dev, ABS_X + i,
0, HIL_IDD_AXIS_MAX(idd, i), 0, 0);
for (i = 3; naxsets > 1 && i < ptr->naxes + 3; i++)
input_set_abs_params(input_dev, ABS_X + i,
0, HIL_IDD_AXIS_MAX(idd, i - 3), 0, 0);
#ifdef TABLET_AUTOADJUST
for (i = 0; i < ABS_MAX; i++) {
int diff = input_abs_get_max(input_dev, ABS_X + i) / 10;
input_abs_set_min(input_dev, ABS_X + i,
input_abs_get_min(input_dev, ABS_X + i) + diff);
input_abs_set_max(input_dev, ABS_X + i,
input_abs_get_max(input_dev, ABS_X + i) - diff);
}
#endif
txt = "absolute";
break;
default:
BUG();
}
ptr->nbtn = HIL_IDD_NUM_BUTTONS(idd);
if (ptr->nbtn)
input_dev->evbit[0] |= BIT_MASK(EV_KEY);
btntype = BTN_MISC;
if ((did & HIL_IDD_DID_ABS_TABLET_MASK) == HIL_IDD_DID_ABS_TABLET)
#ifdef TABLET_SIMULATES_MOUSE
btntype = BTN_TOUCH;
#else
btntype = BTN_DIGI;
#endif
if ((did & HIL_IDD_DID_ABS_TSCREEN_MASK) == HIL_IDD_DID_ABS_TSCREEN)
btntype = BTN_TOUCH;
if ((did & HIL_IDD_DID_REL_MOUSE_MASK) == HIL_IDD_DID_REL_MOUSE)
btntype = BTN_MOUSE;
for (i = 0; i < ptr->nbtn; i++) {
__set_bit(btntype | i, input_dev->keybit);
ptr->btnmap[i] = btntype | i;
}
if (btntype == BTN_MOUSE) {
ptr->btnmap[1] = BTN_MIDDLE;
ptr->btnmap[2] = BTN_RIGHT;
}
input_dev->name = strlen(ptr->rnm) ? ptr->rnm : "HIL pointer device";
printk(KERN_INFO PREFIX
"HIL pointer device found (did: 0x%02x, axis: %s)\n",
did, txt);
printk(KERN_INFO PREFIX
"HIL pointer has %i buttons and %i sets of %i axes\n",
ptr->nbtn, naxsets, ptr->naxes);
}
static int hil_dev_connect(struct serio *serio, struct serio_driver *drv)
{
struct hil_dev *dev;
struct input_dev *input_dev;
uint8_t did, *idd;
int error;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
input_dev = input_allocate_device();
if (!dev || !input_dev) {
error = -ENOMEM;
goto bail0;
}
dev->serio = serio;
dev->dev = input_dev;
error = serio_open(serio, drv);
if (error)
goto bail0;
serio_set_drvdata(serio, dev);
init_completion(&dev->cmd_done);
serio_write(serio, 0);
serio_write(serio, 0);
serio_write(serio, HIL_PKT_CMD >> 8);
serio_write(serio, HIL_CMD_IDD);
error = wait_for_completion_killable(&dev->cmd_done);
if (error)
goto bail1;
reinit_completion(&dev->cmd_done);
serio_write(serio, 0);
serio_write(serio, 0);
serio_write(serio, HIL_PKT_CMD >> 8);
serio_write(serio, HIL_CMD_RSC);
error = wait_for_completion_killable(&dev->cmd_done);
if (error)
goto bail1;
reinit_completion(&dev->cmd_done);
serio_write(serio, 0);
serio_write(serio, 0);
serio_write(serio, HIL_PKT_CMD >> 8);
serio_write(serio, HIL_CMD_RNM);
error = wait_for_completion_killable(&dev->cmd_done);
if (error)
goto bail1;
reinit_completion(&dev->cmd_done);
serio_write(serio, 0);
serio_write(serio, 0);
serio_write(serio, HIL_PKT_CMD >> 8);
serio_write(serio, HIL_CMD_EXD);
error = wait_for_completion_killable(&dev->cmd_done);
if (error)
goto bail1;
did = dev->idd[0];
idd = dev->idd + 1;
switch (did & HIL_IDD_DID_TYPE_MASK) {
case HIL_IDD_DID_TYPE_KB_INTEGRAL:
case HIL_IDD_DID_TYPE_KB_ITF:
case HIL_IDD_DID_TYPE_KB_RSVD:
case HIL_IDD_DID_TYPE_CHAR:
if (HIL_IDD_NUM_BUTTONS(idd) ||
HIL_IDD_NUM_AXES_PER_SET(*idd)) {
printk(KERN_INFO PREFIX
"combo devices are not supported.\n");
goto bail1;
}
dev->is_pointer = false;
hil_dev_keyboard_setup(dev);
break;
case HIL_IDD_DID_TYPE_REL:
case HIL_IDD_DID_TYPE_ABS:
dev->is_pointer = true;
hil_dev_pointer_setup(dev);
break;
default:
goto bail1;
}
input_dev->id.bustype = BUS_HIL;
input_dev->id.vendor = PCI_VENDOR_ID_HP;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &serio->dev;
if (!dev->is_pointer) {
serio_write(serio, 0);
serio_write(serio, 0);
serio_write(serio, HIL_PKT_CMD >> 8);
serio_write(serio, HIL_CMD_EK1);
}
error = input_register_device(input_dev);
if (error)
goto bail1;
return 0;
bail1:
serio_close(serio);
serio_set_drvdata(serio, NULL);
bail0:
input_free_device(input_dev);
kfree(dev);
return error;
}
