static inline struct tef6862_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct tef6862_state, sd);
}
static u16 tef6862_sigstr(struct i2c_client *client)
{
u8 buf[4];
int err = i2c_master_recv(client, buf, sizeof(buf));
if (err == sizeof(buf))
return buf[3] << 8;
return 0;
}
static int tef6862_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *v)
{
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = TEF6862_LO_FREQ;
v->rangehigh = TEF6862_HI_FREQ;
v->rxsubchans = V4L2_TUNER_SUB_MONO;
v->capability = V4L2_TUNER_CAP_LOW;
v->audmode = V4L2_TUNER_MODE_STEREO;
v->signal = tef6862_sigstr(v4l2_get_subdevdata(sd));
return 0;
}
static int tef6862_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *v)
{
return v->index ? -EINVAL : 0;
}
static int tef6862_s_frequency(struct v4l2_subdev *sd, const struct v4l2_frequency *f)
{
struct tef6862_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u16 pll;
u8 i2cmsg[3];
int err;
if (f->tuner != 0)
return -EINVAL;
pll = 1964 + ((f->frequency - TEF6862_LO_FREQ) * 20) / FREQ_MUL;
i2cmsg[0] = (MODE_PRESET << MODE_SHIFT) | WM_SUB_PLLM;
i2cmsg[1] = (pll >> 8) & 0xff;
i2cmsg[2] = pll & 0xff;
err = i2c_master_send(client, i2cmsg, sizeof(i2cmsg));
if (err != sizeof(i2cmsg))
return err < 0 ? err : -EIO;
state->freq = f->frequency;
return 0;
}
static int tef6862_g_frequency(struct v4l2_subdev *sd, struct v4l2_frequency *f)
{
struct tef6862_state *state = to_state(sd);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = state->freq;
return 0;
}
static int tef6862_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_TEF6862, 0);
}
static int tef6862_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tef6862_state *state;
struct v4l2_subdev *sd;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
state = kzalloc(sizeof(struct tef6862_state), GFP_KERNEL);
if (state == NULL)
return -ENOMEM;
state->freq = TEF6862_LO_FREQ;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &tef6862_ops);
return 0;
}
static int tef6862_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
