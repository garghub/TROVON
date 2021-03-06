static void gpio_write(struct cx18 *cx)
{
u32 dir_lo = cx->gpio_dir & 0xffff;
u32 val_lo = cx->gpio_val & 0xffff;
u32 dir_hi = cx->gpio_dir >> 16;
u32 val_hi = cx->gpio_val >> 16;
cx18_write_reg_expect(cx, dir_lo << 16,
CX18_REG_GPIO_DIR1, ~dir_lo, dir_lo);
cx18_write_reg_expect(cx, (dir_lo << 16) | val_lo,
CX18_REG_GPIO_OUT1, val_lo, dir_lo);
cx18_write_reg_expect(cx, dir_hi << 16,
CX18_REG_GPIO_DIR2, ~dir_hi, dir_hi);
cx18_write_reg_expect(cx, (dir_hi << 16) | val_hi,
CX18_REG_GPIO_OUT2, val_hi, dir_hi);
}
static void gpio_update(struct cx18 *cx, u32 mask, u32 data)
{
if (mask == 0)
return;
mutex_lock(&cx->gpio_lock);
cx->gpio_val = (cx->gpio_val & ~mask) | (data & mask);
gpio_write(cx);
mutex_unlock(&cx->gpio_lock);
}
static void gpio_reset_seq(struct cx18 *cx, u32 active_lo, u32 active_hi,
unsigned int assert_msecs,
unsigned int recovery_msecs)
{
u32 mask;
mask = active_lo | active_hi;
if (mask == 0)
return;
gpio_update(cx, mask, ~active_lo);
schedule_timeout_uninterruptible(msecs_to_jiffies(assert_msecs));
gpio_update(cx, mask, ~active_hi);
schedule_timeout_uninterruptible(msecs_to_jiffies(recovery_msecs));
}
static int gpiomux_log_status(struct v4l2_subdev *sd)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
mutex_lock(&cx->gpio_lock);
CX18_INFO_DEV(sd, "GPIO: direction 0x%08x, value 0x%08x\n",
cx->gpio_dir, cx->gpio_val);
mutex_unlock(&cx->gpio_lock);
return 0;
}
static int gpiomux_s_radio(struct v4l2_subdev *sd)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
gpio_update(cx, cx->card->gpio_audio_input.mask,
cx->card->gpio_audio_input.radio);
return 0;
}
static int gpiomux_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
u32 data;
switch (cx->card->audio_inputs[cx->audio_input].muxer_input) {
case 1:
data = cx->card->gpio_audio_input.linein;
break;
case 0:
data = cx->card->gpio_audio_input.tuner;
break;
default:
data = cx->card->gpio_audio_input.tuner;
break;
}
gpio_update(cx, cx->card->gpio_audio_input.mask, data);
return 0;
}
static int gpiomux_s_audio_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
u32 data;
switch (input) {
case 0:
data = cx->card->gpio_audio_input.tuner;
break;
case 1:
data = cx->card->gpio_audio_input.linein;
break;
case 2:
data = cx->card->gpio_audio_input.radio;
break;
default:
return -EINVAL;
}
gpio_update(cx, cx->card->gpio_audio_input.mask, data);
return 0;
}
static int resetctrl_log_status(struct v4l2_subdev *sd)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
mutex_lock(&cx->gpio_lock);
CX18_INFO_DEV(sd, "GPIO: direction 0x%08x, value 0x%08x\n",
cx->gpio_dir, cx->gpio_val);
mutex_unlock(&cx->gpio_lock);
return 0;
}
static int resetctrl_reset(struct v4l2_subdev *sd, u32 val)
{
struct cx18 *cx = v4l2_get_subdevdata(sd);
const struct cx18_gpio_i2c_slave_reset *p;
p = &cx->card->gpio_i2c_slave_reset;
switch (val) {
case CX18_GPIO_RESET_I2C:
gpio_reset_seq(cx, p->active_lo_mask, p->active_hi_mask,
p->msecs_asserted, p->msecs_recovery);
break;
case CX18_GPIO_RESET_Z8F0811:
gpio_reset_seq(cx, p->ir_reset_mask, 0,
p->msecs_asserted, p->msecs_recovery);
break;
case CX18_GPIO_RESET_XC2028:
if (cx->card->tuners[0].tuner == TUNER_XC2028)
gpio_reset_seq(cx, (1 << cx->card->xceive_pin), 0,
1, 1);
break;
}
return 0;
}
void cx18_gpio_init(struct cx18 *cx)
{
mutex_lock(&cx->gpio_lock);
cx->gpio_dir = cx->card->gpio_init.direction;
cx->gpio_val = cx->card->gpio_init.initial_value;
if (cx->card->tuners[0].tuner == TUNER_XC2028) {
cx->gpio_dir |= 1 << cx->card->xceive_pin;
cx->gpio_val |= 1 << cx->card->xceive_pin;
}
if (cx->gpio_dir == 0) {
mutex_unlock(&cx->gpio_lock);
return;
}
CX18_DEBUG_INFO("GPIO initial dir: %08x/%08x out: %08x/%08x\n",
cx18_read_reg(cx, CX18_REG_GPIO_DIR1),
cx18_read_reg(cx, CX18_REG_GPIO_DIR2),
cx18_read_reg(cx, CX18_REG_GPIO_OUT1),
cx18_read_reg(cx, CX18_REG_GPIO_OUT2));
gpio_write(cx);
mutex_unlock(&cx->gpio_lock);
}
int cx18_gpio_register(struct cx18 *cx, u32 hw)
{
struct v4l2_subdev *sd;
const struct v4l2_subdev_ops *ops;
char *str;
switch (hw) {
case CX18_HW_GPIO_MUX:
sd = &cx->sd_gpiomux;
ops = &gpiomux_ops;
str = "gpio-mux";
break;
case CX18_HW_GPIO_RESET_CTRL:
sd = &cx->sd_resetctrl;
ops = &resetctrl_ops;
str = "gpio-reset-ctrl";
break;
default:
return -EINVAL;
}
v4l2_subdev_init(sd, ops);
v4l2_set_subdevdata(sd, cx);
snprintf(sd->name, sizeof(sd->name), "%s %s", cx->v4l2_dev.name, str);
sd->grp_id = hw;
return v4l2_device_register_subdev(&cx->v4l2_dev, sd);
}
void cx18_reset_ir_gpio(void *data)
{
struct cx18 *cx = to_cx18((struct v4l2_device *)data);
if (cx->card->gpio_i2c_slave_reset.ir_reset_mask == 0)
return;
CX18_DEBUG_INFO("Resetting IR microcontroller\n");
v4l2_subdev_call(&cx->sd_resetctrl,
core, reset, CX18_GPIO_RESET_Z8F0811);
}
int cx18_reset_tuner_gpio(void *dev, int component, int cmd, int value)
{
struct i2c_algo_bit_data *algo = dev;
struct cx18_i2c_algo_callback_data *cb_data = algo->data;
struct cx18 *cx = cb_data->cx;
if (cmd != XC2028_TUNER_RESET ||
cx->card->tuners[0].tuner != TUNER_XC2028)
return 0;
CX18_DEBUG_INFO("Resetting XCeive tuner\n");
return v4l2_subdev_call(&cx->sd_resetctrl,
core, reset, CX18_GPIO_RESET_XC2028);
}
