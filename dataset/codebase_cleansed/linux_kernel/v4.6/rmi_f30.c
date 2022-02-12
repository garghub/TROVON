static int rmi_f30_read_control_parameters(struct rmi_function *fn,
struct f30_data *f30)
{
struct rmi_device *rmi_dev = fn->rmi_dev;
int error = 0;
error = rmi_read_block(rmi_dev, fn->fd.control_base_addr,
f30->ctrl_regs, f30->ctrl_regs_size);
if (error) {
dev_err(&rmi_dev->dev, "%s : Could not read control registers at 0x%x error (%d)\n",
__func__, fn->fd.control_base_addr, error);
return error;
}
return 0;
}
static int rmi_f30_attention(struct rmi_function *fn, unsigned long *irq_bits)
{
struct f30_data *f30 = dev_get_drvdata(&fn->dev);
struct rmi_device *rmi_dev = fn->rmi_dev;
int retval;
int gpiled = 0;
int value = 0;
int i;
int reg_num;
if (!f30->input)
return 0;
if (rmi_dev->xport->attn_data) {
memcpy(f30->data_regs, rmi_dev->xport->attn_data,
f30->register_count);
rmi_dev->xport->attn_data += f30->register_count;
rmi_dev->xport->attn_size -= f30->register_count;
} else {
retval = rmi_read_block(rmi_dev, fn->fd.data_base_addr,
f30->data_regs, f30->register_count);
if (retval) {
dev_err(&fn->dev, "%s: Failed to read F30 data registers.\n",
__func__);
return retval;
}
}
for (reg_num = 0; reg_num < f30->register_count; ++reg_num) {
for (i = 0; gpiled < f30->gpioled_count && i < 8; ++i,
++gpiled) {
if (f30->gpioled_key_map[gpiled] != 0) {
value = (((f30->data_regs[reg_num] >> i) & 0x01)
== 0);
rmi_dbg(RMI_DEBUG_FN, &fn->dev,
"%s: call input report key (0x%04x) value (0x%02x)",
__func__,
f30->gpioled_key_map[gpiled], value);
input_report_key(f30->input,
f30->gpioled_key_map[gpiled],
value);
}
}
}
return 0;
}
static int rmi_f30_register_device(struct rmi_function *fn)
{
int i;
struct rmi_device *rmi_dev = fn->rmi_dev;
struct rmi_driver_data *drv_data = dev_get_drvdata(&rmi_dev->dev);
struct f30_data *f30 = dev_get_drvdata(&fn->dev);
struct input_dev *input_dev;
int button_count = 0;
input_dev = drv_data->input;
if (!input_dev) {
dev_info(&fn->dev, "F30: no input device found, ignoring.\n");
return -EINVAL;
}
f30->input = input_dev;
set_bit(EV_KEY, input_dev->evbit);
input_dev->keycode = f30->gpioled_key_map;
input_dev->keycodesize = sizeof(u16);
input_dev->keycodemax = f30->gpioled_count;
for (i = 0; i < f30->gpioled_count; i++) {
if (f30->gpioled_key_map[i] != 0) {
input_set_capability(input_dev, EV_KEY,
f30->gpioled_key_map[i]);
button_count++;
}
}
if (button_count == 1)
__set_bit(INPUT_PROP_BUTTONPAD, input_dev->propbit);
return 0;
}
static int rmi_f30_config(struct rmi_function *fn)
{
struct f30_data *f30 = dev_get_drvdata(&fn->dev);
struct rmi_driver *drv = fn->rmi_dev->driver;
const struct rmi_device_platform_data *pdata =
rmi_get_platform_data(fn->rmi_dev);
int error;
if (pdata->f30_data && pdata->f30_data->disable) {
drv->clear_irq_bits(fn->rmi_dev, fn->irq_mask);
} else {
error = rmi_write_block(fn->rmi_dev, fn->fd.control_base_addr,
f30->ctrl_regs, f30->ctrl_regs_size);
if (error) {
dev_err(&fn->rmi_dev->dev,
"%s : Could not write control registers at 0x%x error (%d)\n",
__func__, fn->fd.control_base_addr, error);
return error;
}
drv->set_irq_bits(fn->rmi_dev, fn->irq_mask);
}
return 0;
}
static inline void rmi_f30_set_ctrl_data(struct rmi_f30_ctrl_data *ctrl,
int *ctrl_addr, int len, u8 **reg)
{
ctrl->address = *ctrl_addr;
ctrl->length = len;
ctrl->regs = *reg;
*ctrl_addr += len;
*reg += len;
}
static inline bool rmi_f30_is_valid_button(int button,
struct rmi_f30_ctrl_data *ctrl)
{
int byte_position = button >> 3;
int bit_position = button & 0x07;
return !(ctrl[2].regs[byte_position] & BIT(bit_position)) &&
(ctrl[3].regs[byte_position] & BIT(bit_position));
}
static inline int rmi_f30_initialize(struct rmi_function *fn)
{
struct f30_data *f30;
struct rmi_device *rmi_dev = fn->rmi_dev;
const struct rmi_device_platform_data *pdata;
int retval = 0;
int control_address;
int i;
int button;
u8 buf[RMI_F30_QUERY_SIZE];
u8 *ctrl_reg;
u8 *map_memory;
f30 = devm_kzalloc(&fn->dev, sizeof(struct f30_data),
GFP_KERNEL);
if (!f30)
return -ENOMEM;
dev_set_drvdata(&fn->dev, f30);
retval = rmi_read_block(fn->rmi_dev, fn->fd.query_base_addr, buf,
RMI_F30_QUERY_SIZE);
if (retval) {
dev_err(&fn->dev, "Failed to read query register.\n");
return retval;
}
f30->has_extended_pattern = buf[0] & RMI_F30_EXTENDED_PATTERNS;
f30->has_mappable_buttons = buf[0] & RMI_F30_HAS_MAPPABLE_BUTTONS;
f30->has_led = buf[0] & RMI_F30_HAS_LED;
f30->has_gpio = buf[0] & RMI_F30_HAS_GPIO;
f30->has_haptic = buf[0] & RMI_F30_HAS_HAPTIC;
f30->has_gpio_driver_control = buf[0] & RMI_F30_HAS_GPIO_DRV_CTL;
f30->has_mech_mouse_btns = buf[0] & RMI_F30_HAS_MECH_MOUSE_BTNS;
f30->gpioled_count = buf[1] & RMI_F30_GPIO_LED_COUNT;
f30->register_count = (f30->gpioled_count + 7) >> 3;
control_address = fn->fd.control_base_addr;
ctrl_reg = f30->ctrl_regs;
if (f30->has_gpio && f30->has_led)
rmi_f30_set_ctrl_data(&f30->ctrl[0], &control_address,
f30->register_count, &ctrl_reg);
rmi_f30_set_ctrl_data(&f30->ctrl[1], &control_address, sizeof(u8),
&ctrl_reg);
if (f30->has_gpio) {
rmi_f30_set_ctrl_data(&f30->ctrl[2], &control_address,
f30->register_count, &ctrl_reg);
rmi_f30_set_ctrl_data(&f30->ctrl[3], &control_address,
f30->register_count, &ctrl_reg);
}
if (f30->has_led) {
int ctrl5_len;
rmi_f30_set_ctrl_data(&f30->ctrl[4], &control_address,
f30->register_count, &ctrl_reg);
if (f30->has_extended_pattern)
ctrl5_len = 6;
else
ctrl5_len = 2;
rmi_f30_set_ctrl_data(&f30->ctrl[5], &control_address,
ctrl5_len, &ctrl_reg);
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
f30->ctrl_regs_size = ctrl_reg - f30->ctrl_regs
?: RMI_F30_CTRL_REGS_MAX_SIZE;
retval = rmi_f30_read_control_parameters(fn, f30);
if (retval < 0) {
dev_err(&fn->dev,
"Failed to initialize F19 control params.\n");
return retval;
}
map_memory = devm_kzalloc(&fn->dev,
(f30->gpioled_count * (sizeof(u16))),
GFP_KERNEL);
if (!map_memory) {
dev_err(&fn->dev, "Failed to allocate gpioled map memory.\n");
return -ENOMEM;
}
f30->gpioled_key_map = (u16 *)map_memory;
pdata = rmi_get_platform_data(rmi_dev);
if (pdata && f30->has_gpio) {
button = BTN_LEFT;
for (i = 0; i < f30->gpioled_count; i++) {
if (rmi_f30_is_valid_button(i, f30->ctrl)) {
f30->gpioled_key_map[i] = button++;
if (pdata->f30_data &&
pdata->f30_data->buttonpad)
break;
}
}
}
return 0;
}
static int rmi_f30_probe(struct rmi_function *fn)
{
int rc;
const struct rmi_device_platform_data *pdata =
rmi_get_platform_data(fn->rmi_dev);
if (pdata->f30_data && pdata->f30_data->disable)
return 0;
rc = rmi_f30_initialize(fn);
if (rc < 0)
goto error_exit;
rc = rmi_f30_register_device(fn);
if (rc < 0)
goto error_exit;
return 0;
error_exit:
return rc;
}
