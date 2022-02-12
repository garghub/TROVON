static inline struct upd64083_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct upd64083_state, sd);
}
static void upd64083_write(struct v4l2_subdev *sd, u8 reg, u8 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[2];
buf[0] = reg;
buf[1] = val;
v4l2_dbg(1, debug, sd, "write reg: %02x val: %02x\n", reg, val);
if (i2c_master_send(client, buf, 2) != 2)
v4l2_err(sd, "I/O error write 0x%02x/0x%02x\n", reg, val);
}
static u8 upd64083_read(struct v4l2_subdev *sd, u8 reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[7];
if (reg >= sizeof(buf))
return 0xff;
i2c_master_recv(client, buf, sizeof(buf));
return buf[reg];
}
static int upd64083_s_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct upd64083_state *state = to_state(sd);
u8 r00, r02;
if (input > 7 || (input & 6) == 6)
return -EINVAL;
state->mode = (input & 3) << 6;
state->ext_y_adc = (input & UPD64083_EXT_Y_ADC) << 3;
r00 = (state->regs[R00] & ~(3 << 6)) | state->mode;
r02 = (state->regs[R02] & ~(1 << 5)) | state->ext_y_adc;
upd64083_write(sd, R00, r00);
upd64083_write(sd, R02, r02);
return 0;
}
static int upd64083_g_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = upd64083_read(sd, reg->reg & 0xff);
reg->size = 1;
return 0;
}
static int upd64083_s_register(struct v4l2_subdev *sd, struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
upd64083_write(sd, reg->reg & 0xff, reg->val & 0xff);
return 0;
}
static int upd64083_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_UPD64083, 0);
}
static int upd64083_log_status(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 buf[7];
i2c_master_recv(client, buf, 7);
v4l2_info(sd, "Status: SA00=%02x SA01=%02x SA02=%02x SA03=%02x "
"SA04=%02x SA05=%02x SA06=%02x\n",
buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
return 0;
}
static int upd64083_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct upd64083_state *state;
struct v4l2_subdev *sd;
int i;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct upd64083_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &upd64083_ops);
state->mode = 0;
state->ext_y_adc = (1 << 5);
memcpy(state->regs, upd64083_init, TOT_REGS);
for (i = 0; i < TOT_REGS; i++)
upd64083_write(sd, i, state->regs[i]);
return 0;
}
static int upd64083_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
static __init int init_upd64083(void)
{
return i2c_add_driver(&upd64083_driver);
}
static __exit void exit_upd64083(void)
{
i2c_del_driver(&upd64083_driver);
}
