int cx25840_write(struct i2c_client *client, u16 addr, u8 value)
{
u8 buffer[3];
buffer[0] = addr >> 8;
buffer[1] = addr & 0xff;
buffer[2] = value;
return i2c_master_send(client, buffer, 3);
}
int cx25840_write4(struct i2c_client *client, u16 addr, u32 value)
{
u8 buffer[6];
buffer[0] = addr >> 8;
buffer[1] = addr & 0xff;
buffer[2] = value & 0xff;
buffer[3] = (value >> 8) & 0xff;
buffer[4] = (value >> 16) & 0xff;
buffer[5] = value >> 24;
return i2c_master_send(client, buffer, 6);
}
u8 cx25840_read(struct i2c_client * client, u16 addr)
{
struct i2c_msg msgs[2];
u8 tx_buf[2], rx_buf[1];
tx_buf[0] = addr >> 8;
tx_buf[1] = addr & 0xff;
msgs[0].addr = client->addr;
msgs[0].flags = 0;
msgs[0].len = 2;
msgs[0].buf = (char *) tx_buf;
msgs[1].addr = client->addr;
msgs[1].flags = I2C_M_RD;
msgs[1].len = 1;
msgs[1].buf = (char *) rx_buf;
if (i2c_transfer(client->adapter, msgs, 2) < 2)
return 0;
return rx_buf[0];
}
u32 cx25840_read4(struct i2c_client * client, u16 addr)
{
struct i2c_msg msgs[2];
u8 tx_buf[2], rx_buf[4];
tx_buf[0] = addr >> 8;
tx_buf[1] = addr & 0xff;
msgs[0].addr = client->addr;
msgs[0].flags = 0;
msgs[0].len = 2;
msgs[0].buf = (char *) tx_buf;
msgs[1].addr = client->addr;
msgs[1].flags = I2C_M_RD;
msgs[1].len = 4;
msgs[1].buf = (char *) rx_buf;
if (i2c_transfer(client->adapter, msgs, 2) < 2)
return 0;
return (rx_buf[3] << 24) | (rx_buf[2] << 16) | (rx_buf[1] << 8) |
rx_buf[0];
}
int cx25840_and_or(struct i2c_client *client, u16 addr, unsigned and_mask,
u8 or_value)
{
return cx25840_write(client, addr,
(cx25840_read(client, addr) & and_mask) |
or_value);
}
int cx25840_and_or4(struct i2c_client *client, u16 addr, u32 and_mask,
u32 or_value)
{
return cx25840_write4(client, addr,
(cx25840_read4(client, addr) & and_mask) |
or_value);
}
static int cx23885_s_io_pin_config(struct v4l2_subdev *sd, size_t n,
struct v4l2_subdev_io_pin_config *p)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
int i;
u32 pin_ctrl;
u8 gpio_oe, gpio_data, strength;
pin_ctrl = cx25840_read4(client, 0x120);
gpio_oe = cx25840_read(client, 0x160);
gpio_data = cx25840_read(client, 0x164);
for (i = 0; i < n; i++) {
strength = p[i].strength;
if (strength > CX25840_PIN_DRIVE_FAST)
strength = CX25840_PIN_DRIVE_FAST;
switch (p[i].pin) {
case CX23885_PIN_IRQ_N_GPIO16:
if (p[i].function != CX23885_PAD_IRQ_N) {
pin_ctrl &= ~(0x1 << 25);
} else {
if (p[i].flags &
(V4L2_SUBDEV_IO_PIN_DISABLE |
V4L2_SUBDEV_IO_PIN_INPUT)) {
pin_ctrl &= ~(0x1 << 25);
} else {
pin_ctrl |= (0x1 << 25);
}
if (p[i].flags &
V4L2_SUBDEV_IO_PIN_ACTIVE_LOW) {
pin_ctrl &= ~(0x1 << 24);
} else {
pin_ctrl |= (0x1 << 24);
}
}
break;
case CX23885_PIN_IR_RX_GPIO19:
if (p[i].function != CX23885_PAD_GPIO19) {
gpio_oe |= (0x1 << 0);
pin_ctrl &= ~(0x3 << 18);
pin_ctrl |= (strength << 18);
} else {
gpio_oe &= ~(0x1 << 0);
if (p[i].flags & V4L2_SUBDEV_IO_PIN_SET_VALUE) {
gpio_data &= ~(0x1 << 0);
gpio_data |= ((p[i].value & 0x1) << 0);
}
pin_ctrl &= ~(0x3 << 12);
pin_ctrl |= (strength << 12);
}
break;
case CX23885_PIN_IR_TX_GPIO20:
if (p[i].function != CX23885_PAD_GPIO20) {
gpio_oe |= (0x1 << 1);
if (p[i].flags & V4L2_SUBDEV_IO_PIN_DISABLE)
pin_ctrl &= ~(0x1 << 10);
else
pin_ctrl |= (0x1 << 10);
pin_ctrl &= ~(0x3 << 18);
pin_ctrl |= (strength << 18);
} else {
gpio_oe &= ~(0x1 << 1);
if (p[i].flags & V4L2_SUBDEV_IO_PIN_SET_VALUE) {
gpio_data &= ~(0x1 << 1);
gpio_data |= ((p[i].value & 0x1) << 1);
}
pin_ctrl &= ~(0x3 << 12);
pin_ctrl |= (strength << 12);
}
break;
case CX23885_PIN_I2S_SDAT_GPIO21:
if (p[i].function != CX23885_PAD_GPIO21) {
gpio_oe |= (0x1 << 2);
pin_ctrl &= ~(0x3 << 22);
pin_ctrl |= (strength << 22);
} else {
gpio_oe &= ~(0x1 << 2);
if (p[i].flags & V4L2_SUBDEV_IO_PIN_SET_VALUE) {
gpio_data &= ~(0x1 << 2);
gpio_data |= ((p[i].value & 0x1) << 2);
}
pin_ctrl &= ~(0x3 << 12);
pin_ctrl |= (strength << 12);
}
break;
case CX23885_PIN_I2S_WCLK_GPIO22:
if (p[i].function != CX23885_PAD_GPIO22) {
gpio_oe |= (0x1 << 3);
pin_ctrl &= ~(0x3 << 22);
pin_ctrl |= (strength << 22);
} else {
gpio_oe &= ~(0x1 << 3);
if (p[i].flags & V4L2_SUBDEV_IO_PIN_SET_VALUE) {
gpio_data &= ~(0x1 << 3);
gpio_data |= ((p[i].value & 0x1) << 3);
}
pin_ctrl &= ~(0x3 << 12);
pin_ctrl |= (strength << 12);
}
break;
case CX23885_PIN_I2S_BCLK_GPIO23:
if (p[i].function != CX23885_PAD_GPIO23) {
gpio_oe |= (0x1 << 4);
pin_ctrl &= ~(0x3 << 22);
pin_ctrl |= (strength << 22);
} else {
gpio_oe &= ~(0x1 << 4);
if (p[i].flags & V4L2_SUBDEV_IO_PIN_SET_VALUE) {
gpio_data &= ~(0x1 << 4);
gpio_data |= ((p[i].value & 0x1) << 4);
}
pin_ctrl &= ~(0x3 << 12);
pin_ctrl |= (strength << 12);
}
break;
}
}
cx25840_write(client, 0x164, gpio_data);
cx25840_write(client, 0x160, gpio_oe);
cx25840_write4(client, 0x120, pin_ctrl);
return 0;
}
static int common_s_io_pin_config(struct v4l2_subdev *sd, size_t n,
struct v4l2_subdev_io_pin_config *pincfg)
{
struct cx25840_state *state = to_state(sd);
if (is_cx2388x(state))
return cx23885_s_io_pin_config(sd, n, pincfg);
return 0;
}
static void init_dll1(struct i2c_client *client)
{
cx25840_write(client, 0x159, 0x23);
cx25840_write(client, 0x15a, 0x87);
cx25840_write(client, 0x15b, 0x06);
udelay(10);
cx25840_write(client, 0x159, 0xe1);
udelay(10);
cx25840_write(client, 0x15a, 0x86);
cx25840_write(client, 0x159, 0xe0);
cx25840_write(client, 0x159, 0xe1);
cx25840_write(client, 0x15b, 0x10);
}
static void init_dll2(struct i2c_client *client)
{
cx25840_write(client, 0x15d, 0xe3);
cx25840_write(client, 0x15e, 0x86);
cx25840_write(client, 0x15f, 0x06);
udelay(10);
cx25840_write(client, 0x15d, 0xe1);
cx25840_write(client, 0x15d, 0xe0);
cx25840_write(client, 0x15d, 0xe1);
}
static void cx25836_initialize(struct i2c_client *client)
{
cx25840_and_or(client, 0x000, ~0x01, 0x01);
cx25840_and_or(client, 0x000, ~0x01, 0x00);
cx25840_and_or(client, 0x15a, ~0x70, 0x00);
cx25840_and_or(client, 0x15b, ~0x1e, 0x06);
cx25840_and_or(client, 0x159, ~0x02, 0x02);
udelay(10);
cx25840_and_or(client, 0x159, ~0x02, 0x00);
cx25840_and_or(client, 0x159, ~0xc0, 0xc0);
cx25840_and_or(client, 0x159, ~0x01, 0x00);
cx25840_and_or(client, 0x159, ~0x01, 0x01);
cx25840_and_or(client, 0x15b, ~0x1e, 0x10);
}
static void cx25840_work_handler(struct work_struct *work)
{
struct cx25840_state *state = container_of(work, struct cx25840_state, fw_work);
cx25840_loadfw(state->c);
wake_up(&state->fw_wait);
}
static void cx25840_initialize(struct i2c_client *client)
{
DEFINE_WAIT(wait);
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
struct workqueue_struct *q;
cx25840_and_or(client, 0x803, ~0x10, 0x00);
cx25840_write(client, 0x000, 0x04);
init_dll1(client);
init_dll2(client);
cx25840_write(client, 0x136, 0x0a);
cx25840_write(client, 0x13c, 0x01);
cx25840_write(client, 0x13c, 0x00);
INIT_WORK(&state->fw_work, cx25840_work_handler);
init_waitqueue_head(&state->fw_wait);
q = create_singlethread_workqueue("cx25840_fw");
prepare_to_wait(&state->fw_wait, &wait, TASK_UNINTERRUPTIBLE);
queue_work(q, &state->fw_work);
schedule();
finish_wait(&state->fw_wait, &wait);
destroy_workqueue(q);
cx25840_write(client, 0x115, 0x8c);
cx25840_write(client, 0x116, 0x07);
cx25840_write(client, 0x118, 0x02);
cx25840_write(client, 0x4a5, 0x80);
cx25840_write(client, 0x4a5, 0x00);
cx25840_write(client, 0x402, 0x00);
cx25840_and_or(client, 0x401, ~0x18, 0);
cx25840_and_or(client, 0x4a2, ~0x10, 0x10);
cx25840_write(client, 0x8d3, 0x1f);
cx25840_write(client, 0x8e3, 0x03);
cx25840_std_setup(client);
cx25840_write(client, 0x914, 0xa0);
cx25840_write(client, 0x918, 0xa0);
cx25840_write(client, 0x919, 0x01);
cx25840_write(client, 0x809, 0x04);
cx25840_write(client, 0x8cf, 0x0f);
set_input(client, state->vid_input, state->aud_input);
cx25840_and_or(client, 0x803, ~0x10, 0x10);
}
static void cx23885_initialize(struct i2c_client *client)
{
DEFINE_WAIT(wait);
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
struct workqueue_struct *q;
cx25840_write(client, 0x000, 0);
cx25840_and_or(client, 0x102, ~0x01, 0x01);
cx25840_and_or(client, 0x102, ~0x01, 0x00);
cx25840_and_or(client, 0x803, ~0x10, 0x00);
cx25840_write(client, 0x398, 0);
cx25840_write(client, 0x2, 0x76);
cx25840_write(client, 0x1, 0x40);
switch (state->id) {
case V4L2_IDENT_CX23888_AV:
cx25840_write4(client, 0x11c, 0x00e8ba26);
cx25840_write4(client, 0x118, 0x0000040b);
break;
case V4L2_IDENT_CX23887_AV:
cx25840_write4(client, 0x11c, 0x01d1744c);
cx25840_write4(client, 0x118, 0x00000416);
break;
case V4L2_IDENT_CX23885_AV:
default:
cx25840_write4(client, 0x11c, 0x00000000);
cx25840_write4(client, 0x118, 0x00000414);
break;
}
cx25840_write4(client, 0x33c, 0x00000001);
cx25840_write4(client, 0x340, 0x0df7df83);
cx25840_write4(client, 0x10c, 0x002be2c9);
cx25840_write4(client, 0x108, 0x0000040f);
cx25840_write4(client, 0x414, 0x00107d12);
cx25840_write4(client, 0x420, 0x3d008282);
switch (state->id) {
case V4L2_IDENT_CX23888_AV:
cx25840_write4(client, 0x114, 0x00bedfa4);
cx25840_write4(client, 0x110, 0x000a0307);
break;
case V4L2_IDENT_CX23887_AV:
cx25840_write4(client, 0x114, 0x017dbf48);
cx25840_write4(client, 0x110, 0x000a030e);
break;
case V4L2_IDENT_CX23885_AV:
default:
cx25840_write4(client, 0x114, 0x01bf0c9e);
cx25840_write4(client, 0x110, 0x000a030c);
break;
};
cx25840_write(client, 0x102, 0x10);
cx25840_write(client, 0x103, 0x11);
cx25840_write(client, 0x400, 0);
cx25840_write(client, 0x401, 0xe8);
cx25840_write(client, 0x144, 0x05);
cx25840_write(client, 0x160, 0x1d);
cx25840_write(client, 0x164, 0x00);
INIT_WORK(&state->fw_work, cx25840_work_handler);
init_waitqueue_head(&state->fw_wait);
q = create_singlethread_workqueue("cx25840_fw");
prepare_to_wait(&state->fw_wait, &wait, TASK_UNINTERRUPTIBLE);
queue_work(q, &state->fw_work);
schedule();
finish_wait(&state->fw_wait, &wait);
destroy_workqueue(q);
cx25840_std_setup(client);
set_input(client, state->vid_input, state->aud_input);
cx25840_and_or(client, 0x803, ~0x10, 0x10);
cx25840_write4(client, CX25840_VID_INT_STAT_REG, 0xffffffff);
cx25840_write(client, CX25840_AUD_INT_CTRL_REG, 0xff);
cx25840_write(client, CX25840_AUD_INT_STAT_REG, 0xff);
}
static void cx231xx_initialize(struct i2c_client *client)
{
DEFINE_WAIT(wait);
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
struct workqueue_struct *q;
cx25840_and_or(client, 0x102, ~0x01, 0x01);
cx25840_and_or(client, 0x102, ~0x01, 0x00);
cx25840_and_or(client, 0x803, ~0x10, 0x00);
cx25840_write(client, 0x398, 0);
cx25840_write(client, 0x2, 0x76);
cx25840_write(client, 0x1, 0x40);
cx25840_write4(client, 0x33c, 0x00000001);
cx25840_write4(client, 0x340, 0x0df7df83);
cx25840_write4(client, 0x414, 0x00107d12);
cx25840_write4(client, 0x420, 0x3d008282);
cx25840_write(client, 0x102, 0x10);
cx25840_write(client, 0x103, 0x11);
cx25840_write(client, 0x400, 0);
cx25840_write(client, 0x401, 0xe8);
INIT_WORK(&state->fw_work, cx25840_work_handler);
init_waitqueue_head(&state->fw_wait);
q = create_singlethread_workqueue("cx25840_fw");
prepare_to_wait(&state->fw_wait, &wait, TASK_UNINTERRUPTIBLE);
queue_work(q, &state->fw_work);
schedule();
finish_wait(&state->fw_wait, &wait);
destroy_workqueue(q);
cx25840_std_setup(client);
set_input(client, state->vid_input, state->aud_input);
cx25840_and_or(client, 0x803, ~0x10, 0x10);
}
void cx25840_std_setup(struct i2c_client *client)
{
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
v4l2_std_id std = state->std;
int hblank, hactive, burst, vblank, vactive, sc;
int vblank656, src_decimation;
int luma_lpf, uv_lpf, comb;
u32 pll_int, pll_frac, pll_post;
if (std & ~V4L2_STD_NTSC)
cx25840_write(client, 0x49f, 0x11);
else
cx25840_write(client, 0x49f, 0x14);
if (std & V4L2_STD_625_50) {
hblank = 132;
hactive = 720;
burst = 93;
vblank = 36;
vactive = 580;
vblank656 = 40;
src_decimation = 0x21f;
luma_lpf = 2;
if (std & V4L2_STD_SECAM) {
uv_lpf = 0;
comb = 0;
sc = 0x0a425f;
} else if (std == V4L2_STD_PAL_Nc) {
uv_lpf = 1;
comb = 0x20;
sc = 556453;
} else {
uv_lpf = 1;
comb = 0x20;
sc = 688739;
}
} else {
hactive = 720;
hblank = 122;
vactive = 487;
luma_lpf = 1;
uv_lpf = 1;
src_decimation = 0x21f;
if (std == V4L2_STD_PAL_60) {
vblank = 26;
vblank656 = 26;
burst = 0x5b;
luma_lpf = 2;
comb = 0x20;
sc = 688739;
} else if (std == V4L2_STD_PAL_M) {
vblank = 20;
vblank656 = 24;
burst = 0x61;
comb = 0x20;
sc = 555452;
} else {
vblank = 26;
vblank656 = 26;
burst = 0x5b;
comb = 0x66;
sc = 556063;
}
}
if (!is_cx231xx(state)) {
pll_int = cx25840_read(client, 0x108);
pll_frac = cx25840_read4(client, 0x10c) & 0x1ffffff;
pll_post = cx25840_read(client, 0x109);
v4l_dbg(1, cx25840_debug, client,
"PLL regs = int: %u, frac: %u, post: %u\n",
pll_int, pll_frac, pll_post);
if (pll_post) {
int fin, fsc;
int pll = (28636363L * ((((u64)pll_int) << 25L) + pll_frac)) >> 25L;
pll /= pll_post;
v4l_dbg(1, cx25840_debug, client, "PLL = %d.%06d MHz\n",
pll / 1000000, pll % 1000000);
v4l_dbg(1, cx25840_debug, client, "PLL/8 = %d.%06d MHz\n",
pll / 8000000, (pll / 8) % 1000000);
fin = ((u64)src_decimation * pll) >> 12;
v4l_dbg(1, cx25840_debug, client,
"ADC Sampling freq = %d.%06d MHz\n",
fin / 1000000, fin % 1000000);
fsc = (((u64)sc) * pll) >> 24L;
v4l_dbg(1, cx25840_debug, client,
"Chroma sub-carrier freq = %d.%06d MHz\n",
fsc / 1000000, fsc % 1000000);
v4l_dbg(1, cx25840_debug, client, "hblank %i, hactive %i, "
"vblank %i, vactive %i, vblank656 %i, src_dec %i, "
"burst 0x%02x, luma_lpf %i, uv_lpf %i, comb 0x%02x, "
"sc 0x%06x\n",
hblank, hactive, vblank, vactive, vblank656,
src_decimation, burst, luma_lpf, uv_lpf, comb, sc);
}
}
cx25840_write(client, 0x470, hblank);
cx25840_write(client, 0x471,
0xff & (((hblank >> 8) & 0x3) | (hactive << 4)));
cx25840_write(client, 0x472, hactive >> 4);
cx25840_write(client, 0x473, burst);
cx25840_write(client, 0x474, vblank);
cx25840_write(client, 0x475,
0xff & (((vblank >> 8) & 0x3) | (vactive << 4)));
cx25840_write(client, 0x476, vactive >> 4);
cx25840_write(client, 0x477, vblank656);
cx25840_write(client, 0x478, 0xff & src_decimation);
cx25840_write(client, 0x479, 0xff & (src_decimation >> 8));
cx25840_write(client, 0x47a, luma_lpf << 6 | ((uv_lpf << 4) & 0x30));
cx25840_write(client, 0x47b, comb);
cx25840_write(client, 0x47c, sc);
cx25840_write(client, 0x47d, 0xff & sc >> 8);
cx25840_write(client, 0x47e, 0xff & sc >> 16);
if (std & V4L2_STD_625_50) {
cx25840_write(client, 0x47f, 0x01);
state->vbi_line_offset = 5;
} else {
cx25840_write(client, 0x47f, 0x00);
state->vbi_line_offset = 8;
}
}
static void input_change(struct i2c_client *client)
{
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
v4l2_std_id std = state->std;
if (std & V4L2_STD_SECAM) {
cx25840_write(client, 0x402, 0);
}
else {
cx25840_write(client, 0x402, 0x04);
cx25840_write(client, 0x49f, (std & V4L2_STD_NTSC) ? 0x14 : 0x11);
}
cx25840_and_or(client, 0x401, ~0x60, 0);
cx25840_and_or(client, 0x401, ~0x60, 0x60);
if (is_cx2583x(state))
return;
cx25840_and_or(client, 0x810, ~0x01, 1);
if (state->radio) {
cx25840_write(client, 0x808, 0xf9);
cx25840_write(client, 0x80b, 0x00);
}
else if (std & V4L2_STD_525_60) {
int hw_fix = state->pvr150_workaround;
if (std == V4L2_STD_NTSC_M_JP) {
cx25840_write(client, 0x808, hw_fix ? 0x2f : 0xf7);
} else if (std == V4L2_STD_NTSC_M_KR) {
cx25840_write(client, 0x808, hw_fix ? 0x3f : 0xf8);
} else {
cx25840_write(client, 0x808, hw_fix ? 0x1f : 0xf6);
}
cx25840_write(client, 0x80b, 0x00);
} else if (std & V4L2_STD_PAL) {
cx25840_write(client, 0x808, 0xff);
cx25840_write(client, 0x80b, 0x00);
} else if (std & V4L2_STD_SECAM) {
cx25840_write(client, 0x808, 0xff);
if ((std & V4L2_STD_SECAM_DK) &&
!(std & (V4L2_STD_SECAM_L | V4L2_STD_SECAM_LC))) {
cx25840_write(client, 0x80b, 0x00);
} else if (!(std & V4L2_STD_SECAM_DK) &&
(std & (V4L2_STD_SECAM_L | V4L2_STD_SECAM_LC))) {
cx25840_write(client, 0x80b, 0x08);
} else {
cx25840_write(client, 0x80b, 0x10);
}
}
cx25840_and_or(client, 0x810, ~0x01, 0);
}
static int set_input(struct i2c_client *client, enum cx25840_video_input vid_input,
enum cx25840_audio_input aud_input)
{
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
u8 is_composite = (vid_input >= CX25840_COMPOSITE1 &&
vid_input <= CX25840_COMPOSITE8);
u8 is_component = (vid_input & CX25840_COMPONENT_ON) ==
CX25840_COMPONENT_ON;
int luma = vid_input & 0xf0;
int chroma = vid_input & 0xf00;
u8 reg;
v4l_dbg(1, cx25840_debug, client,
"decoder set video input %d, audio input %d\n",
vid_input, aud_input);
if (vid_input >= CX25840_VIN1_CH1) {
v4l_dbg(1, cx25840_debug, client, "vid_input 0x%x\n",
vid_input);
reg = vid_input & 0xff;
is_composite = !is_component &&
((vid_input & CX25840_SVIDEO_ON) != CX25840_SVIDEO_ON);
v4l_dbg(1, cx25840_debug, client, "mux cfg 0x%x comp=%d\n",
reg, is_composite);
} else if (is_composite) {
reg = 0xf0 + (vid_input - CX25840_COMPOSITE1);
} else {
if ((vid_input & ~0xff0) ||
luma < CX25840_SVIDEO_LUMA1 || luma > CX25840_SVIDEO_LUMA8 ||
chroma < CX25840_SVIDEO_CHROMA4 || chroma > CX25840_SVIDEO_CHROMA8) {
v4l_err(client, "0x%04x is not a valid video input!\n",
vid_input);
return -EINVAL;
}
reg = 0xf0 + ((luma - CX25840_SVIDEO_LUMA1) >> 4);
if (chroma >= CX25840_SVIDEO_CHROMA7) {
reg &= 0x3f;
reg |= (chroma - CX25840_SVIDEO_CHROMA7) >> 2;
} else {
reg &= 0xcf;
reg |= (chroma - CX25840_SVIDEO_CHROMA4) >> 4;
}
}
if (!is_cx2388x(state) && !is_cx231xx(state)) {
switch (aud_input) {
case CX25840_AUDIO_SERIAL:
break;
case CX25840_AUDIO4: reg &= ~0x30; break;
case CX25840_AUDIO5: reg &= ~0x30; reg |= 0x10; break;
case CX25840_AUDIO6: reg &= ~0x30; reg |= 0x20; break;
case CX25840_AUDIO7: reg &= ~0xc0; break;
case CX25840_AUDIO8: reg &= ~0xc0; reg |= 0x40; break;
default:
v4l_err(client, "0x%04x is not a valid audio input!\n",
aud_input);
return -EINVAL;
}
}
cx25840_write(client, 0x103, reg);
if (is_component)
cx25840_and_or(client, 0x401, ~0x6, 0x6);
else
cx25840_and_or(client, 0x401, ~0x6, is_composite ? 0 : 0x02);
if (!is_cx2388x(state) && !is_cx231xx(state)) {
cx25840_and_or(client, 0x102, ~0x2, (reg & 0x80) == 0 ? 2 : 0);
if ((reg & 0xc0) != 0xc0 && (reg & 0x30) != 0x30)
cx25840_and_or(client, 0x102, ~0x4, 4);
else
cx25840_and_or(client, 0x102, ~0x4, 0);
} else {
cx25840_and_or(client, 0x102, ~0x4, is_component ? 0x4 : 0x0);
if (is_composite) {
cx25840_and_or(client, 0x102, ~0x2, 0);
} else if (!is_component) {
if (chroma >= CX25840_SVIDEO_CHROMA7) {
cx25840_and_or(client, 0x102, ~0x2, 2);
} else {
cx25840_and_or(client, 0x102, ~0x2, 0);
}
}
}
state->vid_input = vid_input;
state->aud_input = aud_input;
cx25840_audio_set_path(client);
input_change(client);
if (is_cx2388x(state)) {
cx25840_write(client, 0x124, 0x03);
cx25840_write(client, 0x144, 0x05);
cx25840_write(client, 0x914, 0xa0);
cx25840_write(client, 0x918, 0xa0);
cx25840_write(client, 0x919, 0x01);
} else if (is_cx231xx(state)) {
cx25840_write(client, 0x124, 0x03);
cx25840_write(client, 0x914, 0xa0);
cx25840_write(client, 0x918, 0xa0);
cx25840_write(client, 0x919, 0x01);
}
return 0;
}
static int set_v4lstd(struct i2c_client *client)
{
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
u8 fmt = 0;
u8 pal_m = 0;
if (state->std == V4L2_STD_NTSC_M_JP) {
fmt = 0x2;
} else if (state->std == V4L2_STD_NTSC_443) {
fmt = 0x3;
} else if (state->std == V4L2_STD_PAL_M) {
pal_m = 1;
fmt = 0x5;
} else if (state->std == V4L2_STD_PAL_N) {
fmt = 0x6;
} else if (state->std == V4L2_STD_PAL_Nc) {
fmt = 0x7;
} else if (state->std == V4L2_STD_PAL_60) {
fmt = 0x8;
} else {
if (state->std & V4L2_STD_NTSC)
fmt = 0x1;
else if (state->std & V4L2_STD_PAL)
fmt = 0x4;
else if (state->std & V4L2_STD_SECAM)
fmt = 0xc;
}
v4l_dbg(1, cx25840_debug, client, "changing video std to fmt %i\n",fmt);
if (fmt >= 4 && fmt < 8) {
cx25840_and_or(client, 0x400, ~0xf, 1);
cx25840_and_or(client, 0x47b, ~6, 0);
}
cx25840_and_or(client, 0x400, ~0xf, fmt);
cx25840_and_or(client, 0x403, ~0x3, pal_m);
cx25840_std_setup(client);
if (!is_cx2583x(state))
input_change(client);
return 0;
}
static int cx25840_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct i2c_client *client = v4l2_get_subdevdata(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
cx25840_write(client, 0x414, ctrl->val - 128);
break;
case V4L2_CID_CONTRAST:
cx25840_write(client, 0x415, ctrl->val << 1);
break;
case V4L2_CID_SATURATION:
cx25840_write(client, 0x420, ctrl->val << 1);
cx25840_write(client, 0x421, ctrl->val << 1);
break;
case V4L2_CID_HUE:
cx25840_write(client, 0x422, ctrl->val);
break;
default:
return -EINVAL;
}
return 0;
}
static int cx25840_s_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *fmt)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int HSC, VSC, Vsrc, Hsrc, filter, Vlines;
int is_50Hz = !(state->std & V4L2_STD_525_60);
if (fmt->code != V4L2_MBUS_FMT_FIXED)
return -EINVAL;
fmt->field = V4L2_FIELD_INTERLACED;
fmt->colorspace = V4L2_COLORSPACE_SMPTE170M;
Vsrc = (cx25840_read(client, 0x476) & 0x3f) << 4;
Vsrc |= (cx25840_read(client, 0x475) & 0xf0) >> 4;
Hsrc = (cx25840_read(client, 0x472) & 0x3f) << 4;
Hsrc |= (cx25840_read(client, 0x471) & 0xf0) >> 4;
Vlines = fmt->height + (is_50Hz ? 4 : 7);
if ((fmt->width * 16 < Hsrc) || (Hsrc < fmt->width) ||
(Vlines * 8 < Vsrc) || (Vsrc < Vlines)) {
v4l_err(client, "%dx%d is not a valid size!\n",
fmt->width, fmt->height);
return -ERANGE;
}
HSC = (Hsrc * (1 << 20)) / fmt->width - (1 << 20);
VSC = (1 << 16) - (Vsrc * (1 << 9) / Vlines - (1 << 9));
VSC &= 0x1fff;
if (fmt->width >= 385)
filter = 0;
else if (fmt->width > 192)
filter = 1;
else if (fmt->width > 96)
filter = 2;
else
filter = 3;
v4l_dbg(1, cx25840_debug, client, "decoder set size %dx%d -> scale %ux%u\n",
fmt->width, fmt->height, HSC, VSC);
cx25840_write(client, 0x418, HSC & 0xff);
cx25840_write(client, 0x419, (HSC >> 8) & 0xff);
cx25840_write(client, 0x41a, HSC >> 16);
cx25840_write(client, 0x41c, VSC & 0xff);
cx25840_write(client, 0x41d, VSC >> 8);
cx25840_write(client, 0x41e, 0x8 | filter);
return 0;
}
static void log_video_status(struct i2c_client *client)
{
static const char *const fmt_strs[] = {
"0x0",
"NTSC-M", "NTSC-J", "NTSC-4.43",
"PAL-BDGHI", "PAL-M", "PAL-N", "PAL-Nc", "PAL-60",
"0x9", "0xA", "0xB",
"SECAM",
"0xD", "0xE", "0xF"
};
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
u8 vidfmt_sel = cx25840_read(client, 0x400) & 0xf;
u8 gen_stat1 = cx25840_read(client, 0x40d);
u8 gen_stat2 = cx25840_read(client, 0x40e);
int vid_input = state->vid_input;
v4l_info(client, "Video signal: %spresent\n",
(gen_stat2 & 0x20) ? "" : "not ");
v4l_info(client, "Detected format: %s\n",
fmt_strs[gen_stat1 & 0xf]);
v4l_info(client, "Specified standard: %s\n",
vidfmt_sel ? fmt_strs[vidfmt_sel] : "automatic detection");
if (vid_input >= CX25840_COMPOSITE1 &&
vid_input <= CX25840_COMPOSITE8) {
v4l_info(client, "Specified video input: Composite %d\n",
vid_input - CX25840_COMPOSITE1 + 1);
} else {
v4l_info(client, "Specified video input: S-Video (Luma In%d, Chroma In%d)\n",
(vid_input & 0xf0) >> 4, (vid_input & 0xf00) >> 8);
}
v4l_info(client, "Specified audioclock freq: %d Hz\n", state->audclk_freq);
}
static void log_audio_status(struct i2c_client *client)
{
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
u8 download_ctl = cx25840_read(client, 0x803);
u8 mod_det_stat0 = cx25840_read(client, 0x804);
u8 mod_det_stat1 = cx25840_read(client, 0x805);
u8 audio_config = cx25840_read(client, 0x808);
u8 pref_mode = cx25840_read(client, 0x809);
u8 afc0 = cx25840_read(client, 0x80b);
u8 mute_ctl = cx25840_read(client, 0x8d3);
int aud_input = state->aud_input;
char *p;
switch (mod_det_stat0) {
case 0x00: p = "mono"; break;
case 0x01: p = "stereo"; break;
case 0x02: p = "dual"; break;
case 0x04: p = "tri"; break;
case 0x10: p = "mono with SAP"; break;
case 0x11: p = "stereo with SAP"; break;
case 0x12: p = "dual with SAP"; break;
case 0x14: p = "tri with SAP"; break;
case 0xfe: p = "forced mode"; break;
default: p = "not defined";
}
v4l_info(client, "Detected audio mode: %s\n", p);
switch (mod_det_stat1) {
case 0x00: p = "not defined"; break;
case 0x01: p = "EIAJ"; break;
case 0x02: p = "A2-M"; break;
case 0x03: p = "A2-BG"; break;
case 0x04: p = "A2-DK1"; break;
case 0x05: p = "A2-DK2"; break;
case 0x06: p = "A2-DK3"; break;
case 0x07: p = "A1 (6.0 MHz FM Mono)"; break;
case 0x08: p = "AM-L"; break;
case 0x09: p = "NICAM-BG"; break;
case 0x0a: p = "NICAM-DK"; break;
case 0x0b: p = "NICAM-I"; break;
case 0x0c: p = "NICAM-L"; break;
case 0x0d: p = "BTSC/EIAJ/A2-M Mono (4.5 MHz FMMono)"; break;
case 0x0e: p = "IF FM Radio"; break;
case 0x0f: p = "BTSC"; break;
case 0x10: p = "high-deviation FM"; break;
case 0x11: p = "very high-deviation FM"; break;
case 0xfd: p = "unknown audio standard"; break;
case 0xfe: p = "forced audio standard"; break;
case 0xff: p = "no detected audio standard"; break;
default: p = "not defined";
}
v4l_info(client, "Detected audio standard: %s\n", p);
v4l_info(client, "Audio microcontroller: %s\n",
(download_ctl & 0x10) ?
((mute_ctl & 0x2) ? "detecting" : "running") : "stopped");
switch (audio_config >> 4) {
case 0x00: p = "undefined"; break;
case 0x01: p = "BTSC"; break;
case 0x02: p = "EIAJ"; break;
case 0x03: p = "A2-M"; break;
case 0x04: p = "A2-BG"; break;
case 0x05: p = "A2-DK1"; break;
case 0x06: p = "A2-DK2"; break;
case 0x07: p = "A2-DK3"; break;
case 0x08: p = "A1 (6.0 MHz FM Mono)"; break;
case 0x09: p = "AM-L"; break;
case 0x0a: p = "NICAM-BG"; break;
case 0x0b: p = "NICAM-DK"; break;
case 0x0c: p = "NICAM-I"; break;
case 0x0d: p = "NICAM-L"; break;
case 0x0e: p = "FM radio"; break;
case 0x0f: p = "automatic detection"; break;
default: p = "undefined";
}
v4l_info(client, "Configured audio standard: %s\n", p);
if ((audio_config >> 4) < 0xF) {
switch (audio_config & 0xF) {
case 0x00: p = "MONO1 (LANGUAGE A/Mono L+R channel for BTSC, EIAJ, A2)"; break;
case 0x01: p = "MONO2 (LANGUAGE B)"; break;
case 0x02: p = "MONO3 (STEREO forced MONO)"; break;
case 0x03: p = "MONO4 (NICAM ANALOG-Language C/Analog Fallback)"; break;
case 0x04: p = "STEREO"; break;
case 0x05: p = "DUAL1 (AB)"; break;
case 0x06: p = "DUAL2 (AC) (FM)"; break;
case 0x07: p = "DUAL3 (BC) (FM)"; break;
case 0x08: p = "DUAL4 (AC) (AM)"; break;
case 0x09: p = "DUAL5 (BC) (AM)"; break;
case 0x0a: p = "SAP"; break;
default: p = "undefined";
}
v4l_info(client, "Configured audio mode: %s\n", p);
} else {
switch (audio_config & 0xF) {
case 0x00: p = "BG"; break;
case 0x01: p = "DK1"; break;
case 0x02: p = "DK2"; break;
case 0x03: p = "DK3"; break;
case 0x04: p = "I"; break;
case 0x05: p = "L"; break;
case 0x06: p = "BTSC"; break;
case 0x07: p = "EIAJ"; break;
case 0x08: p = "A2-M"; break;
case 0x09: p = "FM Radio"; break;
case 0x0f: p = "automatic standard and mode detection"; break;
default: p = "undefined";
}
v4l_info(client, "Configured audio system: %s\n", p);
}
if (aud_input) {
v4l_info(client, "Specified audio input: Tuner (In%d)\n", aud_input);
} else {
v4l_info(client, "Specified audio input: External\n");
}
switch (pref_mode & 0xf) {
case 0: p = "mono/language A"; break;
case 1: p = "language B"; break;
case 2: p = "language C"; break;
case 3: p = "analog fallback"; break;
case 4: p = "stereo"; break;
case 5: p = "language AC"; break;
case 6: p = "language BC"; break;
case 7: p = "language AB"; break;
default: p = "undefined";
}
v4l_info(client, "Preferred audio mode: %s\n", p);
if ((audio_config & 0xf) == 0xf) {
switch ((afc0 >> 3) & 0x3) {
case 0: p = "system DK"; break;
case 1: p = "system L"; break;
case 2: p = "autodetect"; break;
default: p = "undefined";
}
v4l_info(client, "Selected 65 MHz format: %s\n", p);
switch (afc0 & 0x7) {
case 0: p = "chroma"; break;
case 1: p = "BTSC"; break;
case 2: p = "EIAJ"; break;
case 3: p = "A2-M"; break;
case 4: p = "autodetect"; break;
default: p = "undefined";
}
v4l_info(client, "Selected 45 MHz format: %s\n", p);
}
}
static int cx25840_load_fw(struct v4l2_subdev *sd)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!state->is_initialized) {
state->is_initialized = 1;
if (is_cx2583x(state))
cx25836_initialize(client);
else if (is_cx2388x(state))
cx23885_initialize(client);
else if (is_cx231xx(state))
cx231xx_initialize(client);
else
cx25840_initialize(client);
}
return 0;
}
static int cx25840_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->size = 1;
reg->val = cx25840_read(client, reg->reg & 0x0fff);
return 0;
}
static int cx25840_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
cx25840_write(client, reg->reg & 0x0fff, reg->val & 0xff);
return 0;
}
static int cx25840_s_audio_stream(struct v4l2_subdev *sd, int enable)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 v;
if (is_cx2583x(state) || is_cx2388x(state) || is_cx231xx(state))
return 0;
v4l_dbg(1, cx25840_debug, client, "%s audio output\n",
enable ? "enable" : "disable");
if (enable) {
v = cx25840_read(client, 0x115) | 0x80;
cx25840_write(client, 0x115, v);
v = cx25840_read(client, 0x116) | 0x03;
cx25840_write(client, 0x116, v);
} else {
v = cx25840_read(client, 0x115) & ~(0x80);
cx25840_write(client, 0x115, v);
v = cx25840_read(client, 0x116) & ~(0x03);
cx25840_write(client, 0x116, v);
}
return 0;
}
static int cx25840_s_stream(struct v4l2_subdev *sd, int enable)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 v;
v4l_dbg(1, cx25840_debug, client, "%s video output\n",
enable ? "enable" : "disable");
if (enable) {
if (is_cx2388x(state) || is_cx231xx(state)) {
v = cx25840_read(client, 0x421) | 0x0b;
cx25840_write(client, 0x421, v);
} else {
v = cx25840_read(client, 0x115) | 0x0c;
cx25840_write(client, 0x115, v);
v = cx25840_read(client, 0x116) | 0x04;
cx25840_write(client, 0x116, v);
}
} else {
if (is_cx2388x(state) || is_cx231xx(state)) {
v = cx25840_read(client, 0x421) & ~(0x0b);
cx25840_write(client, 0x421, v);
} else {
v = cx25840_read(client, 0x115) & ~(0x0c);
cx25840_write(client, 0x115, v);
v = cx25840_read(client, 0x116) & ~(0x04);
cx25840_write(client, 0x116, v);
}
}
return 0;
}
static int cx25840_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (state->radio == 0 && state->std == std)
return 0;
state->radio = 0;
state->std = std;
return set_v4lstd(client);
}
static int cx25840_s_radio(struct v4l2_subdev *sd)
{
struct cx25840_state *state = to_state(sd);
state->radio = 1;
return 0;
}
static int cx25840_s_video_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
return set_input(client, input, state->aud_input);
}
static int cx25840_s_audio_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
return set_input(client, state->vid_input, input);
}
static int cx25840_s_frequency(struct v4l2_subdev *sd, struct v4l2_frequency *freq)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
input_change(client);
return 0;
}
static int cx25840_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 vpres = cx25840_read(client, 0x40e) & 0x20;
u8 mode;
int val = 0;
if (state->radio)
return 0;
vt->signal = vpres ? 0xffff : 0x0;
if (is_cx2583x(state))
return 0;
vt->capability |=
V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LANG1 |
V4L2_TUNER_CAP_LANG2 | V4L2_TUNER_CAP_SAP;
mode = cx25840_read(client, 0x804);
if ((mode & 0xf) == 1)
val |= V4L2_TUNER_SUB_STEREO;
else
val |= V4L2_TUNER_SUB_MONO;
if (mode == 2 || mode == 4)
val = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
if (mode & 0x10)
val |= V4L2_TUNER_SUB_SAP;
vt->rxsubchans = val;
vt->audmode = state->audmode;
return 0;
}
static int cx25840_s_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (state->radio || is_cx2583x(state))
return 0;
switch (vt->audmode) {
case V4L2_TUNER_MODE_MONO:
cx25840_and_or(client, 0x809, ~0xf, 0x00);
break;
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1:
cx25840_and_or(client, 0x809, ~0xf, 0x04);
break;
case V4L2_TUNER_MODE_LANG1_LANG2:
cx25840_and_or(client, 0x809, ~0xf, 0x07);
break;
case V4L2_TUNER_MODE_LANG2:
cx25840_and_or(client, 0x809, ~0xf, 0x01);
break;
default:
return -EINVAL;
}
state->audmode = vt->audmode;
return 0;
}
static int cx25840_reset(struct v4l2_subdev *sd, u32 val)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (is_cx2583x(state))
cx25836_initialize(client);
else if (is_cx2388x(state))
cx23885_initialize(client);
else if (is_cx231xx(state))
cx231xx_initialize(client);
else
cx25840_initialize(client);
return 0;
}
static int cx25840_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, state->id, state->rev);
}
static int cx25840_log_status(struct v4l2_subdev *sd)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
log_video_status(client);
if (!is_cx2583x(state))
log_audio_status(client);
cx25840_ir_log_status(sd);
v4l2_ctrl_handler_log_status(&state->hdl, sd->name);
return 0;
}
static int cx23885_irq_handler(struct v4l2_subdev *sd, u32 status,
bool *handled)
{
struct cx25840_state *state = to_state(sd);
struct i2c_client *c = v4l2_get_subdevdata(sd);
u8 irq_stat, aud_stat, aud_en, ir_stat, ir_en;
u32 vid_stat, aud_mc_stat;
bool block_handled;
int ret = 0;
irq_stat = cx25840_read(c, CX23885_PIN_CTRL_IRQ_REG);
v4l_dbg(2, cx25840_debug, c, "AV Core IRQ status (entry): %s %s %s\n",
irq_stat & CX23885_PIN_CTRL_IRQ_IR_STAT ? "ir" : " ",
irq_stat & CX23885_PIN_CTRL_IRQ_AUD_STAT ? "aud" : " ",
irq_stat & CX23885_PIN_CTRL_IRQ_VID_STAT ? "vid" : " ");
if ((is_cx23885(state) || is_cx23887(state))) {
ir_stat = cx25840_read(c, CX25840_IR_STATS_REG);
ir_en = cx25840_read(c, CX25840_IR_IRQEN_REG);
v4l_dbg(2, cx25840_debug, c,
"AV Core ir IRQ status: %#04x disables: %#04x\n",
ir_stat, ir_en);
if (irq_stat & CX23885_PIN_CTRL_IRQ_IR_STAT) {
block_handled = false;
ret = cx25840_ir_irq_handler(sd,
status, &block_handled);
if (block_handled)
*handled = true;
}
}
aud_stat = cx25840_read(c, CX25840_AUD_INT_STAT_REG);
aud_en = cx25840_read(c, CX25840_AUD_INT_CTRL_REG);
v4l_dbg(2, cx25840_debug, c,
"AV Core audio IRQ status: %#04x disables: %#04x\n",
aud_stat, aud_en);
aud_mc_stat = cx25840_read4(c, CX23885_AUD_MC_INT_MASK_REG);
v4l_dbg(2, cx25840_debug, c,
"AV Core audio MC IRQ status: %#06x enables: %#06x\n",
aud_mc_stat >> CX23885_AUD_MC_INT_STAT_SHFT,
aud_mc_stat & CX23885_AUD_MC_INT_CTRL_BITS);
if (irq_stat & CX23885_PIN_CTRL_IRQ_AUD_STAT) {
if (aud_stat) {
cx25840_write(c, CX25840_AUD_INT_STAT_REG, aud_stat);
*handled = true;
}
}
vid_stat = cx25840_read4(c, CX25840_VID_INT_STAT_REG);
v4l_dbg(2, cx25840_debug, c,
"AV Core video IRQ status: %#06x disables: %#06x\n",
vid_stat & CX25840_VID_INT_STAT_BITS,
vid_stat >> CX25840_VID_INT_MASK_SHFT);
if (irq_stat & CX23885_PIN_CTRL_IRQ_VID_STAT) {
if (vid_stat & CX25840_VID_INT_STAT_BITS) {
cx25840_write4(c, CX25840_VID_INT_STAT_REG, vid_stat);
*handled = true;
}
}
irq_stat = cx25840_read(c, CX23885_PIN_CTRL_IRQ_REG);
v4l_dbg(2, cx25840_debug, c, "AV Core IRQ status (exit): %s %s %s\n",
irq_stat & CX23885_PIN_CTRL_IRQ_IR_STAT ? "ir" : " ",
irq_stat & CX23885_PIN_CTRL_IRQ_AUD_STAT ? "aud" : " ",
irq_stat & CX23885_PIN_CTRL_IRQ_VID_STAT ? "vid" : " ");
return ret;
}
static int cx25840_irq_handler(struct v4l2_subdev *sd, u32 status,
bool *handled)
{
struct cx25840_state *state = to_state(sd);
*handled = false;
if (is_cx2388x(state))
return cx23885_irq_handler(sd, status, handled);
return -ENODEV;
}
static u32 get_cx2388x_ident(struct i2c_client *client)
{
u32 ret;
cx25840_write(client, 0x000, 0);
if (cx25840_read4(client, 0x204) & 0xffff) {
ret = cx25840_read4(client, 0x300);
if (((ret & 0xffff0000) >> 16) == (ret & 0xffff)) {
ret = V4L2_IDENT_CX23885_AV;
} else {
ret = V4L2_IDENT_CX23887_AV;
}
} else if (cx25840_read4(client, 0x300) & 0x0fffffff) {
ret = V4L2_IDENT_CX23888_AV;
} else {
v4l_err(client, "Unable to detect h/w, assuming cx23887\n");
ret = V4L2_IDENT_CX23887_AV;
}
cx25840_write(client, 0x000, 2);
return ret;
}
static int cx25840_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct cx25840_state *state;
struct v4l2_subdev *sd;
int default_volume;
u32 id = V4L2_IDENT_NONE;
u16 device_id;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_dbg(1, cx25840_debug, client, "detecting cx25840 client on address 0x%x\n", client->addr << 1);
device_id = cx25840_read(client, 0x101) << 8;
device_id |= cx25840_read(client, 0x100);
v4l_dbg(1, cx25840_debug, client, "device_id = 0x%04x\n", device_id);
if ((device_id & 0xff00) == 0x8300) {
id = V4L2_IDENT_CX25836 + ((device_id >> 4) & 0xf) - 6;
} else if ((device_id & 0xff00) == 0x8400) {
id = V4L2_IDENT_CX25840 + ((device_id >> 4) & 0xf);
} else if (device_id == 0x0000) {
id = get_cx2388x_ident(client);
} else if ((device_id & 0xfff0) == 0x5A30) {
id = V4L2_IDENT_CX2310X_AV;
} else if ((device_id & 0xff) == (device_id >> 8)) {
v4l_err(client,
"likely a confused/unresponsive cx2388[578] A/V decoder"
" found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
v4l_err(client, "A method to reset it from the cx25840 driver"
" software is not known at this time\n");
return -ENODEV;
} else {
v4l_dbg(1, cx25840_debug, client, "cx25840 not found\n");
return -ENODEV;
}
state = kzalloc(sizeof(struct cx25840_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &cx25840_ops);
switch (id) {
case V4L2_IDENT_CX23885_AV:
v4l_info(client, "cx23885 A/V decoder found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
break;
case V4L2_IDENT_CX23887_AV:
v4l_info(client, "cx23887 A/V decoder found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
break;
case V4L2_IDENT_CX23888_AV:
v4l_info(client, "cx23888 A/V decoder found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
break;
case V4L2_IDENT_CX2310X_AV:
v4l_info(client, "cx%d A/V decoder found @ 0x%x (%s)\n",
device_id, client->addr << 1, client->adapter->name);
break;
case V4L2_IDENT_CX25840:
case V4L2_IDENT_CX25841:
case V4L2_IDENT_CX25842:
case V4L2_IDENT_CX25843:
v4l_info(client, "cx25%3x-2%x found @ 0x%x (%s)\n",
(device_id & 0xfff0) >> 4,
(device_id & 0x0f) < 3 ? (device_id & 0x0f) + 1
: (device_id & 0x0f),
client->addr << 1, client->adapter->name);
break;
case V4L2_IDENT_CX25836:
case V4L2_IDENT_CX25837:
default:
v4l_info(client, "cx25%3x-%x found @ 0x%x (%s)\n",
(device_id & 0xfff0) >> 4, device_id & 0x0f,
client->addr << 1, client->adapter->name);
break;
}
state->c = client;
state->vid_input = CX25840_COMPOSITE7;
state->aud_input = CX25840_AUDIO8;
state->audclk_freq = 48000;
state->audmode = V4L2_TUNER_MODE_LANG1;
state->vbi_line_offset = 8;
state->id = id;
state->rev = device_id;
v4l2_ctrl_handler_init(&state->hdl, 9);
v4l2_ctrl_new_std(&state->hdl, &cx25840_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
v4l2_ctrl_new_std(&state->hdl, &cx25840_ctrl_ops,
V4L2_CID_CONTRAST, 0, 127, 1, 64);
v4l2_ctrl_new_std(&state->hdl, &cx25840_ctrl_ops,
V4L2_CID_SATURATION, 0, 127, 1, 64);
v4l2_ctrl_new_std(&state->hdl, &cx25840_ctrl_ops,
V4L2_CID_HUE, -128, 127, 1, 0);
if (!is_cx2583x(state)) {
default_volume = cx25840_read(client, 0x8d4);
if (default_volume > 228) {
default_volume = 228;
cx25840_write(client, 0x8d4, 228);
}
else if (default_volume < 20) {
default_volume = 20;
cx25840_write(client, 0x8d4, 20);
}
default_volume = (((228 - default_volume) >> 1) + 23) << 9;
state->volume = v4l2_ctrl_new_std(&state->hdl,
&cx25840_audio_ctrl_ops, V4L2_CID_AUDIO_VOLUME,
0, 65535, 65535 / 100, default_volume);
state->mute = v4l2_ctrl_new_std(&state->hdl,
&cx25840_audio_ctrl_ops, V4L2_CID_AUDIO_MUTE,
0, 1, 1, 0);
v4l2_ctrl_new_std(&state->hdl, &cx25840_audio_ctrl_ops,
V4L2_CID_AUDIO_BALANCE,
0, 65535, 65535 / 100, 32768);
v4l2_ctrl_new_std(&state->hdl, &cx25840_audio_ctrl_ops,
V4L2_CID_AUDIO_BASS,
0, 65535, 65535 / 100, 32768);
v4l2_ctrl_new_std(&state->hdl, &cx25840_audio_ctrl_ops,
V4L2_CID_AUDIO_TREBLE,
0, 65535, 65535 / 100, 32768);
}
sd->ctrl_handler = &state->hdl;
if (state->hdl.error) {
int err = state->hdl.error;
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return err;
}
if (!is_cx2583x(state))
v4l2_ctrl_cluster(2, &state->volume);
v4l2_ctrl_handler_setup(&state->hdl);
if (client->dev.platform_data) {
struct cx25840_platform_data *pdata = client->dev.platform_data;
state->pvr150_workaround = pdata->pvr150_workaround;
}
cx25840_ir_probe(sd);
return 0;
}
static int cx25840_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct cx25840_state *state = to_state(sd);
cx25840_ir_remove(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return 0;
}
static __init int init_cx25840(void)
{
return i2c_add_driver(&cx25840_driver);
}
static __exit void exit_cx25840(void)
{
i2c_del_driver(&cx25840_driver);
}
