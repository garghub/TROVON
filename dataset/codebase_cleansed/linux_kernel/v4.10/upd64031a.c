static inline struct upd64031a_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct upd64031a_state, sd);
}
static u8 upd64031a_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[2];
if (reg >= sizeof(buf))
return 0xff;
i2c_master_recv(client, buf, 2);
return buf[reg];
}
static void upd64031a_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[2];
buf[0] = reg;
buf[1] = val;
v4l2_dbg(1, debug, sd, "write reg: %02X val: %02X\n", reg, val);
if (i2c_master_send(client, buf, 2) != 2)
v4l2_err(sd, "I/O error write 0x%02x/0x%02x\n", reg, val);
}
static int upd64031a_s_frequency(struct v4l2_subdev *sd, const struct v4l2_frequency *freq)
{
struct upd64031a_state *state = to_state(sd);
u8 reg = state->regs[R00];
v4l2_dbg(1, debug, sd, "changed input or channel\n");
upd64031a_write(sd, R00, reg | 0x10);
upd64031a_write(sd, R00, reg & ~0x10);
return 0;
}
static int upd64031a_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct upd64031a_state *state = to_state(sd);
u8 r00, r05, r08;
state->gr_mode = (input & 3) << 6;
state->direct_3dycs_connect = (input & 0xc) << 4;
state->ext_comp_sync =
(input & UPD64031A_COMPOSITE_EXTERNAL) << 1;
state->ext_vert_sync =
(input & UPD64031A_VERTICAL_EXTERNAL) << 2;
r00 = (state->regs[R00] & ~GR_MODE_MASK) | state->gr_mode;
r05 = (state->regs[R00] & ~SYNC_CIRCUIT_MASK) |
state->ext_comp_sync | state->ext_vert_sync;
r08 = (state->regs[R08] & ~DIRECT_3DYCS_CONNECT_MASK) |
state->direct_3dycs_connect;
upd64031a_write(sd, R00, r00);
upd64031a_write(sd, R05, r05);
upd64031a_write(sd, R08, r08);
return upd64031a_s_frequency(sd, NULL);
}
static int upd64031a_log_status(struct v4l2_subdev *sd)
{
v4l2_info(sd, "Status: SA00=0x%02x SA01=0x%02x\n",
upd64031a_read(sd, 0), upd64031a_read(sd, 1));
return 0;
}
static int upd64031a_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
reg->val = upd64031a_read(sd, reg->reg & 0xff);
reg->size = 1;
return 0;
}
static int upd64031a_s_register(struct v4l2_subdev *sd, const struct v4l2_dbg_register *reg)
{
upd64031a_write(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int upd64031a_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct upd64031a_state *state;
struct v4l2_subdev *sd;
int i;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = devm_kzalloc(&client->dev, sizeof(*state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &upd64031a_ops);
memcpy(state->regs, upd64031a_init, sizeof(state->regs));
state->gr_mode = UPD64031A_GR_ON << 6;
state->direct_3dycs_connect = UPD64031A_3DYCS_COMPOSITE << 4;
state->ext_comp_sync = state->ext_vert_sync = 0;
for (i = 0; i < TOT_REGS; i++)
upd64031a_write(sd, i, state->regs[i]);
return 0;
}
static int upd64031a_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
return 0;
}
