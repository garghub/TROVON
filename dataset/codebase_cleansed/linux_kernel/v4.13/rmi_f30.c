static int rmi_f30_read_control_parameters(struct rmi_function *fn,
struct f30_data *f30)
{
int error;
error = rmi_read_block(fn->rmi_dev, fn->fd.control_base_addr,
f30->ctrl_regs, f30->ctrl_regs_size);
if (error) {
dev_err(&fn->dev,
"%s: Could not read control registers at 0x%x: %d\n",
__func__, fn->fd.control_base_addr, error);
return error;
}
return 0;
}
static void rmi_f30_report_button(struct rmi_function *fn,
struct f30_data *f30, unsigned int button)
{
unsigned int reg_num = button >> 3;
unsigned int bit_num = button & 0x07;
u16 key_code = f30->gpioled_key_map[button];
bool key_down = !(f30->data_regs[reg_num] & BIT(bit_num));
if (f30->trackstick_buttons &&
button >= TRACKSTICK_RANGE_START &&
button <= TRACKSTICK_RANGE_END) {
rmi_f03_overwrite_button(f30->f03, key_code, key_down);
} else {
rmi_dbg(RMI_DEBUG_FN, &fn->dev,
"%s: call input report key (0x%04x) value (0x%02x)",
__func__, key_code, key_down);
input_report_key(f30->input, key_code, key_down);
}
}
static int rmi_f30_attention(struct rmi_function *fn, unsigned long *irq_bits)
{
struct f30_data *f30 = dev_get_drvdata(&fn->dev);
struct rmi_driver_data *drvdata = dev_get_drvdata(&fn->rmi_dev->dev);
int error;
int i;
if (drvdata->attn_data.data) {
if (drvdata->attn_data.size < f30->register_count) {
dev_warn(&fn->dev,
"F30 interrupted, but data is missing\n");
return 0;
}
memcpy(f30->data_regs, drvdata->attn_data.data,
f30->register_count);
drvdata->attn_data.data += f30->register_count;
drvdata->attn_data.size -= f30->register_count;
} else {
error = rmi_read_block(fn->rmi_dev, fn->fd.data_base_addr,
f30->data_regs, f30->register_count);
if (error) {
dev_err(&fn->dev,
"%s: Failed to read F30 data registers: %d\n",
__func__, error);
return error;
}
}
if (f30->has_gpio) {
for (i = 0; i < f30->gpioled_count; i++)
if (f30->gpioled_key_map[i] != KEY_RESERVED)
rmi_f30_report_button(fn, f30, i);
if (f30->trackstick_buttons)
rmi_f03_commit_buttons(f30->f03);
}
return 0;
}
static int rmi_f30_config(struct rmi_function *fn)
{
struct f30_data *f30 = dev_get_drvdata(&fn->dev);
struct rmi_driver *drv = fn->rmi_dev->driver;
const struct rmi_device_platform_data *pdata =
rmi_get_platform_data(fn->rmi_dev);
int error;
if (!f30)
return 0;
if (pdata->f30_data.trackstick_buttons) {
f30->f03 = rmi_find_function(fn->rmi_dev, 0x03);
f30->trackstick_buttons = f30->f03 != NULL;
}
if (pdata->f30_data.disable) {
drv->clear_irq_bits(fn->rmi_dev, fn->irq_mask);
} else {
error = rmi_write_block(fn->rmi_dev, fn->fd.control_base_addr,
f30->ctrl_regs, f30->ctrl_regs_size);
if (error) {
dev_err(&fn->dev,
"%s: Could not write control registers at 0x%x: %d\n",
__func__, fn->fd.control_base_addr, error);
return error;
}
drv->set_irq_bits(fn->rmi_dev, fn->irq_mask);
}
return 0;
}
static void rmi_f30_set_ctrl_data(struct rmi_f30_ctrl_data *ctrl,
int *ctrl_addr, int len, u8 **reg)
{
ctrl->address = *ctrl_addr;
ctrl->length = len;
ctrl->regs = *reg;
*ctrl_addr += len;
*reg += len;
}
static bool rmi_f30_is_valid_button(int button, struct rmi_f30_ctrl_data *ctrl)
{
int byte_position = button >> 3;
int bit_position = button & 0x07;
return !(ctrl[2].regs[byte_position] & BIT(bit_position)) &&
(ctrl[3].regs[byte_position] & BIT(bit_position));
}
static int rmi_f30_map_gpios(struct rmi_function *fn,
struct f30_data *f30)
{
const struct rmi_device_platform_data *pdata =
rmi_get_platform_data(fn->rmi_dev);
struct input_dev *input = f30->input;
unsigned int button = BTN_LEFT;
unsigned int trackstick_button = BTN_LEFT;
bool button_mapped = false;
int i;
f30->gpioled_key_map = devm_kcalloc(&fn->dev,
f30->gpioled_count,
sizeof(f30->gpioled_key_map[0]),
GFP_KERNEL);
if (!f30->gpioled_key_map) {
dev_err(&fn->dev, "Failed to allocate gpioled map memory.\n");
return -ENOMEM;
}
for (i = 0; i < f30->gpioled_count; i++) {
if (!rmi_f30_is_valid_button(i, f30->ctrl))
continue;
if (pdata->f30_data.trackstick_buttons &&
i >= TRACKSTICK_RANGE_START && i < TRACKSTICK_RANGE_END) {
f30->gpioled_key_map[i] = trackstick_button++;
} else if (!pdata->f30_data.buttonpad || !button_mapped) {
f30->gpioled_key_map[i] = button;
input_set_capability(input, EV_KEY, button++);
button_mapped = true;
}
}
input->keycode = f30->gpioled_key_map;
input->keycodesize = sizeof(f30->gpioled_key_map[0]);
input->keycodemax = f30->gpioled_count;
if (pdata->f30_data.buttonpad || (button - BTN_LEFT == 1))
__set_bit(INPUT_PROP_BUTTONPAD, input->propbit);
return 0;
}
static int rmi_f30_initialize(struct rmi_function *fn, struct f30_data *f30)
{
u8 *ctrl_reg = f30->ctrl_regs;
int control_address = fn->fd.control_base_addr;
u8 buf[RMI_F30_QUERY_SIZE];
int error;
error = rmi_read_block(fn->rmi_dev, fn->fd.query_base_addr,
buf, RMI_F30_QUERY_SIZE);
if (error) {
dev_err(&fn->dev, "Failed to read query register\n");
return error;
}
f30->has_extended_pattern = buf[0] & RMI_F30_EXTENDED_PATTERNS;
f30->has_mappable_buttons = buf[0] & RMI_F30_HAS_MAPPABLE_BUTTONS;
f30->has_led = buf[0] & RMI_F30_HAS_LED;
f30->has_gpio = buf[0] & RMI_F30_HAS_GPIO;
f30->has_haptic = buf[0] & RMI_F30_HAS_HAPTIC;
f30->has_gpio_driver_control = buf[0] & RMI_F30_HAS_GPIO_DRV_CTL;
f30->has_mech_mouse_btns = buf[0] & RMI_F30_HAS_MECH_MOUSE_BTNS;
f30->gpioled_count = buf[1] & RMI_F30_GPIO_LED_COUNT;
f30->register_count = DIV_ROUND_UP(f30->gpioled_count, 8);
if (f30->has_gpio && f30->has_led)
rmi_f30_set_ctrl_data(&f30->ctrl[0], &control_address,
f30->register_count, &ctrl_reg);
rmi_f30_set_ctrl_data(&f30->ctrl[1], &control_address,
sizeof(u8), &ctrl_reg);
if (f30->has_gpio) {
rmi_f30_set_ctrl_data(&f30->ctrl[2], &control_address,
f30->register_count, &ctrl_reg);
rmi_f30_set_ctrl_data(&f30->ctrl[3], &control_address,
f30->register_count, &ctrl_reg);
}
if (f30->has_led) {
rmi_f30_set_ctrl_data(&f30->ctrl[4], &control_address,
f30->register_count, &ctrl_reg);
rmi_f30_set_ctrl_data(&f30->ctrl[5], &control_address,
f30->has_extended_pattern ? 6 : 2,
&ctrl_reg);
}
if (f30->has_led || f30->has_gpio_driver_control) {
rmi_f30_set_ctrl_data(&f30->ctrl[6], &control_address,
f30->gpioled_count, &ctrl_reg);
}
if (f30->has_mappable_buttons) {
rmi_f30_set_ctrl_data(&f30->ctrl[7], &control_address,
f30->gpioled_count, &ctrl_reg);
}
if (f30->has_haptic) {
rmi_f30_set_ctrl_data(&f30->ctrl[8], &control_address,
f30->register_count, &ctrl_reg);
rmi_f30_set_ctrl_data(&f30->ctrl[9], &control_address,
sizeof(u8), &ctrl_reg);
}
if (f30->has_mech_mouse_btns)
rmi_f30_set_ctrl_data(&f30->ctrl[10], &control_address,
sizeof(u8), &ctrl_reg);
f30->ctrl_regs_size = ctrl_reg -
f30->ctrl_regs ?: RMI_F30_CTRL_REGS_MAX_SIZE;
error = rmi_f30_read_control_parameters(fn, f30);
if (error) {
dev_err(&fn->dev,
"Failed to initialize F30 control params: %d\n",
error);
return error;
}
if (f30->has_gpio) {
error = rmi_f30_map_gpios(fn, f30);
if (error)
return error;
}
return 0;
}
static int rmi_f30_probe(struct rmi_function *fn)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
const struct rmi_device_platform_data *pdata =
rmi_get_platform_data(rmi_dev);
struct rmi_driver_data *drv_data = dev_get_drvdata(&rmi_dev->dev);
struct f30_data *f30;
int error;
if (pdata->f30_data.disable)
return 0;
if (!drv_data->input) {
dev_info(&fn->dev, "F30: no input device found, ignoring\n");
return -ENXIO;
}
f30 = devm_kzalloc(&fn->dev, sizeof(*f30), GFP_KERNEL);
if (!f30)
return -ENOMEM;
f30->input = drv_data->input;
error = rmi_f30_initialize(fn, f30);
if (error)
return error;
dev_set_drvdata(&fn->dev, f30);
return 0;
}
