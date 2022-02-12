static int lm3646_mode_ctrl(struct lm3646_flash *flash,
enum v4l2_flash_led_mode led_mode)
{
switch (led_mode) {
case V4L2_FLASH_LED_MODE_NONE:
return regmap_write(flash->regmap,
REG_ENABLE, flash->mode_reg | MODE_SHDN);
case V4L2_FLASH_LED_MODE_TORCH:
return regmap_write(flash->regmap,
REG_ENABLE, flash->mode_reg | MODE_TORCH);
case V4L2_FLASH_LED_MODE_FLASH:
return regmap_write(flash->regmap,
REG_ENABLE, flash->mode_reg | MODE_FLASH);
}
return -EINVAL;
}
static int lm3646_get_ctrl(struct v4l2_ctrl *ctrl)
{
struct lm3646_flash *flash = to_lm3646_flash(ctrl);
unsigned int reg_val;
int rval;
if (ctrl->id != V4L2_CID_FLASH_FAULT)
return -EINVAL;
rval = regmap_read(flash->regmap, REG_FLAG, &reg_val);
if (rval < 0)
return rval;
ctrl->val = 0;
if (reg_val & FAULT_TIMEOUT)
ctrl->val |= V4L2_FLASH_FAULT_TIMEOUT;
if (reg_val & FAULT_SHORT_CIRCUIT)
ctrl->val |= V4L2_FLASH_FAULT_SHORT_CIRCUIT;
if (reg_val & FAULT_UVLO)
ctrl->val |= V4L2_FLASH_FAULT_UNDER_VOLTAGE;
if (reg_val & FAULT_IVFM)
ctrl->val |= V4L2_FLASH_FAULT_INPUT_VOLTAGE;
if (reg_val & FAULT_OCP)
ctrl->val |= V4L2_FLASH_FAULT_OVER_CURRENT;
if (reg_val & FAULT_OVERTEMP)
ctrl->val |= V4L2_FLASH_FAULT_OVER_TEMPERATURE;
if (reg_val & FAULT_NTC_TRIP)
ctrl->val |= V4L2_FLASH_FAULT_LED_OVER_TEMPERATURE;
if (reg_val & FAULT_OVP)
ctrl->val |= V4L2_FLASH_FAULT_OVER_VOLTAGE;
return 0;
}
static int lm3646_set_ctrl(struct v4l2_ctrl *ctrl)
{
struct lm3646_flash *flash = to_lm3646_flash(ctrl);
unsigned int reg_val;
int rval = -EINVAL;
switch (ctrl->id) {
case V4L2_CID_FLASH_LED_MODE:
if (ctrl->val != V4L2_FLASH_LED_MODE_FLASH)
return lm3646_mode_ctrl(flash, ctrl->val);
return lm3646_mode_ctrl(flash, V4L2_FLASH_LED_MODE_NONE);
case V4L2_CID_FLASH_STROBE_SOURCE:
return regmap_update_bits(flash->regmap,
REG_STROBE_SRC, MASK_STROBE_SRC,
(ctrl->val) << 7);
case V4L2_CID_FLASH_STROBE:
rval = regmap_read(flash->regmap, REG_ENABLE, &reg_val);
if (rval < 0 || ((reg_val & MASK_ENABLE) != MODE_SHDN))
return rval;
return lm3646_mode_ctrl(flash, V4L2_FLASH_LED_MODE_FLASH);
case V4L2_CID_FLASH_STROBE_STOP:
rval = regmap_read(flash->regmap, REG_ENABLE, &reg_val);
if (rval < 0)
return rval;
if ((reg_val & MASK_ENABLE) == MODE_FLASH)
return lm3646_mode_ctrl(flash,
V4L2_FLASH_LED_MODE_NONE);
return rval;
case V4L2_CID_FLASH_TIMEOUT:
return regmap_update_bits(flash->regmap,
REG_FLASH_TOUT, MASK_FLASH_TOUT,
LM3646_FLASH_TOUT_ms_TO_REG
(ctrl->val));
case V4L2_CID_FLASH_INTENSITY:
return regmap_update_bits(flash->regmap,
REG_FLASH_BR, MASK_FLASH_BR,
LM3646_TOTAL_FLASH_BRT_uA_TO_REG
(ctrl->val));
case V4L2_CID_FLASH_TORCH_INTENSITY:
return regmap_update_bits(flash->regmap,
REG_TORCH_BR, MASK_TORCH_BR,
LM3646_TOTAL_TORCH_BRT_uA_TO_REG
(ctrl->val) << 4);
}
return -EINVAL;
}
static int lm3646_init_controls(struct lm3646_flash *flash)
{
struct v4l2_ctrl *fault;
struct v4l2_ctrl_handler *hdl = &flash->ctrls_led;
const struct v4l2_ctrl_ops *ops = &lm3646_led_ctrl_ops;
v4l2_ctrl_handler_init(hdl, 8);
v4l2_ctrl_new_std_menu(hdl, ops, V4L2_CID_FLASH_LED_MODE,
V4L2_FLASH_LED_MODE_TORCH, ~0x7,
V4L2_FLASH_LED_MODE_NONE);
v4l2_ctrl_new_std_menu(hdl, ops, V4L2_CID_FLASH_STROBE_SOURCE,
0x1, ~0x3, V4L2_FLASH_STROBE_SOURCE_SOFTWARE);
v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_STROBE, 0, 0, 0, 0);
v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_STROBE_STOP, 0, 0, 0, 0);
v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_TIMEOUT,
LM3646_FLASH_TOUT_MIN,
LM3646_FLASH_TOUT_MAX,
LM3646_FLASH_TOUT_STEP, flash->pdata->flash_timeout);
v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_INTENSITY,
LM3646_TOTAL_FLASH_BRT_MIN,
LM3646_TOTAL_FLASH_BRT_MAX,
LM3646_TOTAL_FLASH_BRT_STEP,
LM3646_TOTAL_FLASH_BRT_MAX);
v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_TORCH_INTENSITY,
LM3646_TOTAL_TORCH_BRT_MIN,
LM3646_TOTAL_TORCH_BRT_MAX,
LM3646_TOTAL_TORCH_BRT_STEP,
LM3646_TOTAL_TORCH_BRT_MAX);
fault = v4l2_ctrl_new_std(hdl, ops, V4L2_CID_FLASH_FAULT, 0,
V4L2_FLASH_FAULT_OVER_VOLTAGE
| V4L2_FLASH_FAULT_OVER_TEMPERATURE
| V4L2_FLASH_FAULT_SHORT_CIRCUIT
| V4L2_FLASH_FAULT_TIMEOUT, 0, 0);
if (fault != NULL)
fault->flags |= V4L2_CTRL_FLAG_VOLATILE;
if (hdl->error)
return hdl->error;
flash->subdev_led.ctrl_handler = hdl;
return 0;
}
static int lm3646_subdev_init(struct lm3646_flash *flash)
{
struct i2c_client *client = to_i2c_client(flash->dev);
int rval;
v4l2_i2c_subdev_init(&flash->subdev_led, client, &lm3646_ops);
flash->subdev_led.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
strcpy(flash->subdev_led.name, LM3646_NAME);
rval = lm3646_init_controls(flash);
if (rval)
goto err_out;
rval = media_entity_init(&flash->subdev_led.entity, 0, NULL, 0);
if (rval < 0)
goto err_out;
flash->subdev_led.entity.type = MEDIA_ENT_T_V4L2_SUBDEV_FLASH;
return rval;
err_out:
v4l2_ctrl_handler_free(&flash->ctrls_led);
return rval;
}
static int lm3646_init_device(struct lm3646_flash *flash)
{
unsigned int reg_val;
int rval;
rval = regmap_read(flash->regmap, REG_ENABLE, &reg_val);
if (rval < 0)
return rval;
flash->mode_reg = reg_val & 0xfc;
rval = lm3646_mode_ctrl(flash, V4L2_FLASH_LED_MODE_NONE);
if (rval < 0)
return rval;
rval = regmap_update_bits(flash->regmap,
REG_LED1_FLASH_BR, 0x7F,
LM3646_LED1_FLASH_BRT_uA_TO_REG
(flash->pdata->led1_flash_brt));
if (rval < 0)
return rval;
rval = regmap_update_bits(flash->regmap,
REG_LED1_TORCH_BR, 0x7F,
LM3646_LED1_TORCH_BRT_uA_TO_REG
(flash->pdata->led1_torch_brt));
if (rval < 0)
return rval;
return regmap_read(flash->regmap, REG_FLAG, &reg_val);
}
static int lm3646_probe(struct i2c_client *client,
const struct i2c_device_id *devid)
{
struct lm3646_flash *flash;
struct lm3646_platform_data *pdata = dev_get_platdata(&client->dev);
int rval;
flash = devm_kzalloc(&client->dev, sizeof(*flash), GFP_KERNEL);
if (flash == NULL)
return -ENOMEM;
flash->regmap = devm_regmap_init_i2c(client, &lm3646_regmap);
if (IS_ERR(flash->regmap))
return PTR_ERR(flash->regmap);
if (pdata == NULL) {
pdata = devm_kzalloc(&client->dev,
sizeof(struct lm3646_platform_data),
GFP_KERNEL);
if (pdata == NULL)
return -ENOMEM;
pdata->flash_timeout = LM3646_FLASH_TOUT_MAX;
pdata->led1_torch_brt = LM3646_LED1_TORCH_BRT_MAX;
pdata->led1_flash_brt = LM3646_LED1_FLASH_BRT_MAX;
}
flash->pdata = pdata;
flash->dev = &client->dev;
rval = lm3646_subdev_init(flash);
if (rval < 0)
return rval;
rval = lm3646_init_device(flash);
if (rval < 0)
return rval;
i2c_set_clientdata(client, flash);
return 0;
}
static int lm3646_remove(struct i2c_client *client)
{
struct lm3646_flash *flash = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(&flash->subdev_led);
v4l2_ctrl_handler_free(&flash->ctrls_led);
media_entity_cleanup(&flash->subdev_led.entity);
return 0;
}
