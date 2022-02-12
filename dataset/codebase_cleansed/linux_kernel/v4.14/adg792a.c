static int adg792a_write_cmd(struct i2c_client *i2c, u8 cmd, int reset)
{
u8 data = ADG792A_RESETB | ADG792A_LDSW;
if (reset)
data &= ~ADG792A_RESETB;
return i2c_smbus_write_byte_data(i2c, cmd, data);
}
static int adg792a_set(struct mux_control *mux, int state)
{
struct i2c_client *i2c = to_i2c_client(mux->chip->dev.parent);
u8 cmd;
if (mux->chip->controllers == 1) {
if (state == MUX_IDLE_DISCONNECT)
cmd = ADG792A_DISABLE_ALL;
else
cmd = ADG792A_MUX_ALL(state);
} else {
unsigned int controller = mux_control_get_index(mux);
if (state == MUX_IDLE_DISCONNECT)
cmd = ADG792A_DISABLE(controller);
else
cmd = ADG792A_MUX(controller, state);
}
return adg792a_write_cmd(i2c, cmd, 0);
}
static int adg792a_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct device *dev = &i2c->dev;
struct mux_chip *mux_chip;
s32 idle_state[3];
u32 cells;
int ret;
int i;
if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
ret = device_property_read_u32(dev, "#mux-control-cells", &cells);
if (ret < 0)
return ret;
if (cells >= 2)
return -EINVAL;
mux_chip = devm_mux_chip_alloc(dev, cells ? 3 : 1, 0);
if (IS_ERR(mux_chip))
return PTR_ERR(mux_chip);
mux_chip->ops = &adg792a_ops;
ret = adg792a_write_cmd(i2c, ADG792A_DISABLE_ALL, 1);
if (ret < 0)
return ret;
ret = device_property_read_u32_array(dev, "idle-state",
(u32 *)idle_state,
mux_chip->controllers);
if (ret < 0) {
idle_state[0] = MUX_IDLE_AS_IS;
idle_state[1] = MUX_IDLE_AS_IS;
idle_state[2] = MUX_IDLE_AS_IS;
}
for (i = 0; i < mux_chip->controllers; ++i) {
struct mux_control *mux = &mux_chip->mux[i];
mux->states = 4;
switch (idle_state[i]) {
case MUX_IDLE_DISCONNECT:
case MUX_IDLE_AS_IS:
case 0 ... 4:
mux->idle_state = idle_state[i];
break;
default:
dev_err(dev, "invalid idle-state %d\n", idle_state[i]);
return -EINVAL;
}
}
ret = devm_mux_chip_register(dev, mux_chip);
if (ret < 0)
return ret;
if (cells)
dev_info(dev, "3x single pole quadruple throw muxes registered\n");
else
dev_info(dev, "triple pole quadruple throw mux registered\n");
return 0;
}
