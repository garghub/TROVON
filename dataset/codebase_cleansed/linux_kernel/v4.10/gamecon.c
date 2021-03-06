static void gc_n64_send_command(struct gc *gc, unsigned long cmd,
unsigned char target)
{
struct parport *port = gc->pd->port;
int i;
for (i = 0; i < GC_N64_LENGTH; i++) {
unsigned char data = (cmd >> i) & 1 ? target : 0;
parport_write_data(port, GC_N64_POWER_W | data);
udelay(GC_N64_DWS);
}
}
static void gc_n64_send_stop_bit(struct gc *gc, unsigned char target)
{
struct parport *port = gc->pd->port;
int i;
for (i = 0; i < GC_N64_STOP_LENGTH; i++) {
unsigned char data = (GC_N64_STOP_BIT >> i) & 1 ? target : 0;
parport_write_data(port, GC_N64_POWER_W | data);
udelay(GC_N64_DWS);
}
}
static void gc_n64_read_packet(struct gc *gc, unsigned char *data)
{
int i;
unsigned long flags;
local_irq_save(flags);
gc_n64_send_command(gc, GC_N64_REQUEST_DATA, GC_N64_OUT);
gc_n64_send_stop_bit(gc, GC_N64_OUT);
local_irq_restore(flags);
udelay(GC_N64_DELAY);
for (i = 0; i < GC_N64_LENGTH; i++) {
parport_write_data(gc->pd->port, GC_N64_POWER_R);
udelay(2);
data[i] = parport_read_status(gc->pd->port);
parport_write_data(gc->pd->port, GC_N64_POWER_R | GC_N64_CLOCK);
}
}
static void gc_n64_process_packet(struct gc *gc)
{
unsigned char data[GC_N64_LENGTH];
struct input_dev *dev;
int i, j, s;
signed char x, y;
gc_n64_read_packet(gc, data);
for (i = 0; i < GC_MAX_DEVICES; i++) {
if (gc->pads[i].type != GC_N64)
continue;
dev = gc->pads[i].dev;
s = gc_status_bit[i];
if (s & ~(data[8] | data[9])) {
x = y = 0;
for (j = 0; j < 8; j++) {
if (data[23 - j] & s)
x |= 1 << j;
if (data[31 - j] & s)
y |= 1 << j;
}
input_report_abs(dev, ABS_X, x);
input_report_abs(dev, ABS_Y, -y);
input_report_abs(dev, ABS_HAT0X,
!(s & data[6]) - !(s & data[7]));
input_report_abs(dev, ABS_HAT0Y,
!(s & data[4]) - !(s & data[5]));
for (j = 0; j < 10; j++)
input_report_key(dev, gc_n64_btn[j],
s & data[gc_n64_bytes[j]]);
input_sync(dev);
}
}
}
static int gc_n64_play_effect(struct input_dev *dev, void *data,
struct ff_effect *effect)
{
int i;
unsigned long flags;
struct gc *gc = input_get_drvdata(dev);
struct gc_subdev *sdev = data;
unsigned char target = 1 << sdev->idx;
if (effect->type == FF_RUMBLE) {
struct ff_rumble_effect *rumble = &effect->u.rumble;
unsigned int cmd =
rumble->strong_magnitude || rumble->weak_magnitude ?
GC_N64_CMD_01 : GC_N64_CMD_00;
local_irq_save(flags);
gc_n64_send_command(gc, GC_N64_CMD_03, target);
gc_n64_send_command(gc, GC_N64_CMD_80, target);
gc_n64_send_command(gc, GC_N64_CMD_01, target);
for (i = 0; i < 32; i++)
gc_n64_send_command(gc, GC_N64_CMD_80, target);
gc_n64_send_stop_bit(gc, target);
udelay(GC_N64_DELAY);
gc_n64_send_command(gc, GC_N64_CMD_03, target);
gc_n64_send_command(gc, GC_N64_CMD_c0, target);
gc_n64_send_command(gc, GC_N64_CMD_1b, target);
for (i = 0; i < 32; i++)
gc_n64_send_command(gc, cmd, target);
gc_n64_send_stop_bit(gc, target);
local_irq_restore(flags);
}
return 0;
}
static int gc_n64_init_ff(struct input_dev *dev, int i)
{
struct gc_subdev *sdev;
int err;
sdev = kmalloc(sizeof(*sdev), GFP_KERNEL);
if (!sdev)
return -ENOMEM;
sdev->idx = i;
input_set_capability(dev, EV_FF, FF_RUMBLE);
err = input_ff_create_memless(dev, sdev, gc_n64_play_effect);
if (err) {
kfree(sdev);
return err;
}
return 0;
}
static void gc_nes_read_packet(struct gc *gc, int length, unsigned char *data)
{
int i;
parport_write_data(gc->pd->port, GC_NES_POWER | GC_NES_CLOCK | GC_NES_LATCH);
udelay(GC_NES_DELAY * 2);
parport_write_data(gc->pd->port, GC_NES_POWER | GC_NES_CLOCK);
for (i = 0; i < length; i++) {
udelay(GC_NES_DELAY);
parport_write_data(gc->pd->port, GC_NES_POWER);
data[i] = parport_read_status(gc->pd->port) ^ 0x7f;
udelay(GC_NES_DELAY);
parport_write_data(gc->pd->port, GC_NES_POWER | GC_NES_CLOCK);
}
}
static void gc_nes_process_packet(struct gc *gc)
{
unsigned char data[GC_SNESMOUSE_LENGTH];
struct gc_pad *pad;
struct input_dev *dev;
int i, j, s, len;
char x_rel, y_rel;
len = gc->pad_count[GC_SNESMOUSE] ? GC_SNESMOUSE_LENGTH :
(gc->pad_count[GC_SNES] ? GC_SNES_LENGTH : GC_NES_LENGTH);
gc_nes_read_packet(gc, len, data);
for (i = 0; i < GC_MAX_DEVICES; i++) {
pad = &gc->pads[i];
dev = pad->dev;
s = gc_status_bit[i];
switch (pad->type) {
case GC_NES:
input_report_abs(dev, ABS_X, !(s & data[6]) - !(s & data[7]));
input_report_abs(dev, ABS_Y, !(s & data[4]) - !(s & data[5]));
for (j = 0; j < 4; j++)
input_report_key(dev, gc_snes_btn[j],
s & data[gc_nes_bytes[j]]);
input_sync(dev);
break;
case GC_SNES:
input_report_abs(dev, ABS_X, !(s & data[6]) - !(s & data[7]));
input_report_abs(dev, ABS_Y, !(s & data[4]) - !(s & data[5]));
for (j = 0; j < 8; j++)
input_report_key(dev, gc_snes_btn[j],
s & data[gc_snes_bytes[j]]);
input_sync(dev);
break;
case GC_SNESMOUSE:
if (!(s & data[12]) && !(s & data[13]) &&
!(s & data[14]) && (s & data[15])) {
input_report_key(dev, BTN_LEFT, s & data[9]);
input_report_key(dev, BTN_RIGHT, s & data[8]);
x_rel = y_rel = 0;
for (j = 0; j < 7; j++) {
x_rel <<= 1;
if (data[25 + j] & s)
x_rel |= 1;
y_rel <<= 1;
if (data[17 + j] & s)
y_rel |= 1;
}
if (x_rel) {
if (data[24] & s)
x_rel = -x_rel;
input_report_rel(dev, REL_X, x_rel);
}
if (y_rel) {
if (data[16] & s)
y_rel = -y_rel;
input_report_rel(dev, REL_Y, y_rel);
}
input_sync(dev);
}
break;
default:
break;
}
}
}
static void gc_multi_read_packet(struct gc *gc, int length, unsigned char *data)
{
int i;
for (i = 0; i < length; i++) {
parport_write_data(gc->pd->port, ~(1 << i));
data[i] = parport_read_status(gc->pd->port) ^ 0x7f;
}
}
static void gc_multi_process_packet(struct gc *gc)
{
unsigned char data[GC_MULTI2_LENGTH];
int data_len = gc->pad_count[GC_MULTI2] ? GC_MULTI2_LENGTH : GC_MULTI_LENGTH;
struct gc_pad *pad;
struct input_dev *dev;
int i, s;
gc_multi_read_packet(gc, data_len, data);
for (i = 0; i < GC_MAX_DEVICES; i++) {
pad = &gc->pads[i];
dev = pad->dev;
s = gc_status_bit[i];
switch (pad->type) {
case GC_MULTI2:
input_report_key(dev, BTN_THUMB, s & data[5]);
case GC_MULTI:
input_report_abs(dev, ABS_X,
!(s & data[2]) - !(s & data[3]));
input_report_abs(dev, ABS_Y,
!(s & data[0]) - !(s & data[1]));
input_report_key(dev, BTN_TRIGGER, s & data[4]);
input_sync(dev);
break;
default:
break;
}
}
}
static void gc_psx_command(struct gc *gc, int b, unsigned char *data)
{
struct parport *port = gc->pd->port;
int i, j, cmd, read;
memset(data, 0, GC_MAX_DEVICES);
for (i = 0; i < GC_PSX_LENGTH; i++, b >>= 1) {
cmd = (b & 1) ? GC_PSX_COMMAND : 0;
parport_write_data(port, cmd | GC_PSX_POWER);
udelay(gc_psx_delay);
read = parport_read_status(port) ^ 0x80;
for (j = 0; j < GC_MAX_DEVICES; j++) {
struct gc_pad *pad = &gc->pads[j];
if (pad->type == GC_PSX || pad->type == GC_DDR)
data[j] |= (read & gc_status_bit[j]) ? (1 << i) : 0;
}
parport_write_data(gc->pd->port, cmd | GC_PSX_CLOCK | GC_PSX_POWER);
udelay(gc_psx_delay);
}
}
static void gc_psx_read_packet(struct gc *gc,
unsigned char data[GC_MAX_DEVICES][GC_PSX_BYTES],
unsigned char id[GC_MAX_DEVICES])
{
int i, j, max_len = 0;
unsigned long flags;
unsigned char data2[GC_MAX_DEVICES];
parport_write_data(gc->pd->port, GC_PSX_CLOCK | GC_PSX_SELECT | GC_PSX_POWER);
udelay(gc_psx_delay);
parport_write_data(gc->pd->port, GC_PSX_CLOCK | GC_PSX_POWER);
udelay(gc_psx_delay);
local_irq_save(flags);
gc_psx_command(gc, 0x01, data2);
gc_psx_command(gc, 0x42, id);
gc_psx_command(gc, 0, data2);
for (i = 0; i < GC_MAX_DEVICES; i++) {
struct gc_pad *pad = &gc->pads[i];
if ((pad->type == GC_PSX || pad->type == GC_DDR) &&
GC_PSX_LEN(id[i]) > max_len &&
GC_PSX_LEN(id[i]) <= GC_PSX_BYTES) {
max_len = GC_PSX_LEN(id[i]);
}
}
for (i = 0; i < max_len; i++) {
gc_psx_command(gc, 0, data2);
for (j = 0; j < GC_MAX_DEVICES; j++)
data[j][i] = data2[j];
}
local_irq_restore(flags);
parport_write_data(gc->pd->port, GC_PSX_CLOCK | GC_PSX_SELECT | GC_PSX_POWER);
for (i = 0; i < GC_MAX_DEVICES; i++)
id[i] = GC_PSX_ID(id[i]);
}
static void gc_psx_report_one(struct gc_pad *pad, unsigned char psx_type,
unsigned char *data)
{
struct input_dev *dev = pad->dev;
int i;
switch (psx_type) {
case GC_PSX_RUMBLE:
input_report_key(dev, BTN_THUMBL, ~data[0] & 0x04);
input_report_key(dev, BTN_THUMBR, ~data[0] & 0x02);
case GC_PSX_NEGCON:
case GC_PSX_ANALOG:
if (pad->type == GC_DDR) {
for (i = 0; i < 4; i++)
input_report_key(dev, gc_psx_ddr_btn[i],
~data[0] & (0x10 << i));
} else {
for (i = 0; i < 4; i++)
input_report_abs(dev, gc_psx_abs[i + 2],
data[i + 2]);
input_report_abs(dev, ABS_X,
!!(data[0] & 0x80) * 128 + !(data[0] & 0x20) * 127);
input_report_abs(dev, ABS_Y,
!!(data[0] & 0x10) * 128 + !(data[0] & 0x40) * 127);
}
for (i = 0; i < 8; i++)
input_report_key(dev, gc_psx_btn[i], ~data[1] & (1 << i));
input_report_key(dev, BTN_START, ~data[0] & 0x08);
input_report_key(dev, BTN_SELECT, ~data[0] & 0x01);
input_sync(dev);
break;
case GC_PSX_NORMAL:
if (pad->type == GC_DDR) {
for (i = 0; i < 4; i++)
input_report_key(dev, gc_psx_ddr_btn[i],
~data[0] & (0x10 << i));
} else {
input_report_abs(dev, ABS_X,
!!(data[0] & 0x80) * 128 + !(data[0] & 0x20) * 127);
input_report_abs(dev, ABS_Y,
!!(data[0] & 0x10) * 128 + !(data[0] & 0x40) * 127);
}
for (i = 0; i < 8; i++)
input_report_key(dev, gc_psx_btn[i], ~data[1] & (1 << i));
input_report_key(dev, BTN_START, ~data[0] & 0x08);
input_report_key(dev, BTN_SELECT, ~data[0] & 0x01);
input_sync(dev);
break;
default:
break;
}
}
static void gc_psx_process_packet(struct gc *gc)
{
unsigned char data[GC_MAX_DEVICES][GC_PSX_BYTES];
unsigned char id[GC_MAX_DEVICES];
struct gc_pad *pad;
int i;
gc_psx_read_packet(gc, data, id);
for (i = 0; i < GC_MAX_DEVICES; i++) {
pad = &gc->pads[i];
if (pad->type == GC_PSX || pad->type == GC_DDR)
gc_psx_report_one(pad, id[i], data[i]);
}
}
static void gc_timer(unsigned long private)
{
struct gc *gc = (void *) private;
if (gc->pad_count[GC_N64])
gc_n64_process_packet(gc);
if (gc->pad_count[GC_NES] ||
gc->pad_count[GC_SNES] ||
gc->pad_count[GC_SNESMOUSE]) {
gc_nes_process_packet(gc);
}
if (gc->pad_count[GC_MULTI] || gc->pad_count[GC_MULTI2])
gc_multi_process_packet(gc);
if (gc->pad_count[GC_PSX] || gc->pad_count[GC_DDR])
gc_psx_process_packet(gc);
mod_timer(&gc->timer, jiffies + GC_REFRESH_TIME);
}
static int gc_open(struct input_dev *dev)
{
struct gc *gc = input_get_drvdata(dev);
int err;
err = mutex_lock_interruptible(&gc->mutex);
if (err)
return err;
if (!gc->used++) {
parport_claim(gc->pd);
parport_write_control(gc->pd->port, 0x04);
mod_timer(&gc->timer, jiffies + GC_REFRESH_TIME);
}
mutex_unlock(&gc->mutex);
return 0;
}
static void gc_close(struct input_dev *dev)
{
struct gc *gc = input_get_drvdata(dev);
mutex_lock(&gc->mutex);
if (!--gc->used) {
del_timer_sync(&gc->timer);
parport_write_control(gc->pd->port, 0x00);
parport_release(gc->pd);
}
mutex_unlock(&gc->mutex);
}
static int gc_setup_pad(struct gc *gc, int idx, int pad_type)
{
struct gc_pad *pad = &gc->pads[idx];
struct input_dev *input_dev;
int i;
int err;
if (pad_type < 1 || pad_type >= GC_MAX) {
pr_err("Pad type %d unknown\n", pad_type);
return -EINVAL;
}
pad->dev = input_dev = input_allocate_device();
if (!input_dev) {
pr_err("Not enough memory for input device\n");
return -ENOMEM;
}
pad->type = pad_type;
snprintf(pad->phys, sizeof(pad->phys),
"%s/input%d", gc->pd->port->name, idx);
input_dev->name = gc_names[pad_type];
input_dev->phys = pad->phys;
input_dev->id.bustype = BUS_PARPORT;
input_dev->id.vendor = 0x0001;
input_dev->id.product = pad_type;
input_dev->id.version = 0x0100;
input_set_drvdata(input_dev, gc);
input_dev->open = gc_open;
input_dev->close = gc_close;
if (pad_type != GC_SNESMOUSE) {
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
for (i = 0; i < 2; i++)
input_set_abs_params(input_dev, ABS_X + i, -1, 1, 0, 0);
} else
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL);
gc->pad_count[pad_type]++;
switch (pad_type) {
case GC_N64:
for (i = 0; i < 10; i++)
__set_bit(gc_n64_btn[i], input_dev->keybit);
for (i = 0; i < 2; i++) {
input_set_abs_params(input_dev, ABS_X + i, -127, 126, 0, 2);
input_set_abs_params(input_dev, ABS_HAT0X + i, -1, 1, 0, 0);
}
err = gc_n64_init_ff(input_dev, idx);
if (err) {
pr_warning("Failed to initiate rumble for N64 device %d\n", idx);
goto err_free_dev;
}
break;
case GC_SNESMOUSE:
__set_bit(BTN_LEFT, input_dev->keybit);
__set_bit(BTN_RIGHT, input_dev->keybit);
__set_bit(REL_X, input_dev->relbit);
__set_bit(REL_Y, input_dev->relbit);
break;
case GC_SNES:
for (i = 4; i < 8; i++)
__set_bit(gc_snes_btn[i], input_dev->keybit);
case GC_NES:
for (i = 0; i < 4; i++)
__set_bit(gc_snes_btn[i], input_dev->keybit);
break;
case GC_MULTI2:
__set_bit(BTN_THUMB, input_dev->keybit);
case GC_MULTI:
__set_bit(BTN_TRIGGER, input_dev->keybit);
break;
case GC_PSX:
for (i = 0; i < 6; i++)
input_set_abs_params(input_dev,
gc_psx_abs[i], 4, 252, 0, 2);
for (i = 0; i < 12; i++)
__set_bit(gc_psx_btn[i], input_dev->keybit);
break;
case GC_DDR:
for (i = 0; i < 4; i++)
__set_bit(gc_psx_ddr_btn[i], input_dev->keybit);
for (i = 0; i < 12; i++)
__set_bit(gc_psx_btn[i], input_dev->keybit);
break;
}
err = input_register_device(pad->dev);
if (err)
goto err_free_dev;
return 0;
err_free_dev:
input_free_device(pad->dev);
pad->dev = NULL;
return err;
}
static void gc_attach(struct parport *pp)
{
struct gc *gc;
struct pardevice *pd;
int i, port_idx;
int count = 0;
int *pads, n_pads;
struct pardev_cb gc_parport_cb;
for (port_idx = 0; port_idx < GC_MAX_PORTS; port_idx++) {
if (gc_cfg[port_idx].nargs == 0 || gc_cfg[port_idx].args[0] < 0)
continue;
if (gc_cfg[port_idx].args[0] == pp->number)
break;
}
if (port_idx == GC_MAX_PORTS) {
pr_debug("Not using parport%d.\n", pp->number);
return;
}
pads = gc_cfg[port_idx].args + 1;
n_pads = gc_cfg[port_idx].nargs - 1;
memset(&gc_parport_cb, 0, sizeof(gc_parport_cb));
gc_parport_cb.flags = PARPORT_FLAG_EXCL;
pd = parport_register_dev_model(pp, "gamecon", &gc_parport_cb,
port_idx);
if (!pd) {
pr_err("parport busy already - lp.o loaded?\n");
return;
}
gc = kzalloc(sizeof(struct gc), GFP_KERNEL);
if (!gc) {
pr_err("Not enough memory\n");
goto err_unreg_pardev;
}
mutex_init(&gc->mutex);
gc->pd = pd;
gc->parportno = pp->number;
setup_timer(&gc->timer, gc_timer, (long) gc);
for (i = 0; i < n_pads && i < GC_MAX_DEVICES; i++) {
if (!pads[i])
continue;
if (gc_setup_pad(gc, i, pads[i]))
goto err_unreg_devs;
count++;
}
if (count == 0) {
pr_err("No valid devices specified\n");
goto err_free_gc;
}
gc_base[port_idx] = gc;
return;
err_unreg_devs:
while (--i >= 0)
if (gc->pads[i].dev)
input_unregister_device(gc->pads[i].dev);
err_free_gc:
kfree(gc);
err_unreg_pardev:
parport_unregister_device(pd);
}
static void gc_detach(struct parport *port)
{
int i;
struct gc *gc;
for (i = 0; i < GC_MAX_PORTS; i++) {
if (gc_base[i] && gc_base[i]->parportno == port->number)
break;
}
if (i == GC_MAX_PORTS)
return;
gc = gc_base[i];
gc_base[i] = NULL;
for (i = 0; i < GC_MAX_DEVICES; i++)
if (gc->pads[i].dev)
input_unregister_device(gc->pads[i].dev);
parport_unregister_device(gc->pd);
kfree(gc);
}
static int __init gc_init(void)
{
int i;
int have_dev = 0;
for (i = 0; i < GC_MAX_PORTS; i++) {
if (gc_cfg[i].nargs == 0 || gc_cfg[i].args[0] < 0)
continue;
if (gc_cfg[i].nargs < 2) {
pr_err("at least one device must be specified\n");
return -EINVAL;
}
have_dev = 1;
}
if (!have_dev)
return -ENODEV;
return parport_register_driver(&gc_parport_driver);
}
static void __exit gc_exit(void)
{
parport_unregister_driver(&gc_parport_driver);
}
