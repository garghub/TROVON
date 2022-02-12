static inline struct m52790_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct m52790_state, sd);
}
static int m52790_write(struct v4l2_subdev *sd)
{
struct m52790_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 sw1 = (state->input | state->output) & 0xff;
u8 sw2 = (state->input | state->output) >> 8;
return i2c_smbus_write_byte_data(client, sw1, sw2);
}
static int m52790_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct m52790_state *state = to_state(sd);
state->input = input;
state->output = output;
m52790_write(sd);
return 0;
}
static int m52790_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct m52790_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (reg->reg != 0)
return -EINVAL;
reg->size = 1;
reg->val = state->input | state->output;
return 0;
}
static int m52790_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct m52790_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (reg->reg != 0)
return -EINVAL;
state->input = reg->val & 0x0303;
state->output = reg->val & ~0x0303;
m52790_write(sd);
return 0;
}
static int m52790_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_M52790, 0);
}
static int m52790_log_status(struct v4l2_subdev *sd)
{
struct m52790_state *state = to_state(sd);
v4l2_info(sd, "Switch 1: %02x\n",
(state->input | state->output) & 0xff);
v4l2_info(sd, "Switch 2: %02x\n",
(state->input | state->output) >> 8);
return 0;
}
static int m52790_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct m52790_state *state;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct m52790_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &m52790_ops);
state->input = M52790_IN_TUNER;
state->output = M52790_OUT_STEREO;
m52790_write(sd);
return 0;
}
static int m52790_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
static __init int init_m52790(void)
{
return i2c_add_driver(&m52790_driver);
}
static __exit void exit_m52790(void)
{
i2c_del_driver(&m52790_driver);
}
