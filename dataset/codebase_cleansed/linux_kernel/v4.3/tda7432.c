static inline struct tda7432 *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct tda7432, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct tda7432, hdl)->sd;
}
static int tda7432_write(struct v4l2_subdev *sd, int subaddr, int val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned char buffer[2];
v4l2_dbg(2, debug, sd, "In tda7432_write\n");
v4l2_dbg(1, debug, sd, "Writing %d 0x%x\n", subaddr, val);
buffer[0] = subaddr;
buffer[1] = val;
if (2 != i2c_master_send(client, buffer, 2)) {
v4l2_err(sd, "I/O error, trying (write %d 0x%x)\n",
subaddr, val);
return -1;
}
return 0;
}
static int tda7432_set(struct v4l2_subdev *sd)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned char buf[16];
buf[0] = TDA7432_IN;
buf[1] = TDA7432_STEREO_IN |
TDA7432_BASS_SYM |
TDA7432_BASS_NORM;
buf[2] = 0x3b;
if (loudness)
buf[2] |= TDA7432_LD_ON;
buf[3] = TDA7432_TREBLE_0DB | (TDA7432_BASS_0DB << 4);
buf[4] = TDA7432_ATTEN_0DB;
buf[5] = TDA7432_ATTEN_0DB;
buf[6] = TDA7432_ATTEN_0DB;
buf[7] = TDA7432_ATTEN_0DB;
buf[8] = loudness;
if (9 != i2c_master_send(client, buf, 9)) {
v4l2_err(sd, "I/O error, trying tda7432_set\n");
return -1;
}
return 0;
}
static int tda7432_log_status(struct v4l2_subdev *sd)
{
struct tda7432 *state = to_state(sd);
v4l2_ctrl_handler_log_status(&state->hdl, sd->name);
return 0;
}
static int tda7432_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct tda7432 *t = to_state(sd);
u8 bass, treble, volume;
u8 lf, lr, rf, rr;
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
if (t->balance->val < 0) {
rr = rf = -t->balance->val;
lr = lf = TDA7432_ATTEN_0DB;
} else if (t->balance->val > 0) {
rr = rf = TDA7432_ATTEN_0DB;
lr = lf = t->balance->val;
} else {
rr = rf = TDA7432_ATTEN_0DB;
lr = lf = TDA7432_ATTEN_0DB;
}
if (t->mute->val) {
lf |= TDA7432_MUTE;
lr |= TDA7432_MUTE;
rf |= TDA7432_MUTE;
rr |= TDA7432_MUTE;
}
tda7432_write(sd, TDA7432_LF, lf);
tda7432_write(sd, TDA7432_LR, lr);
tda7432_write(sd, TDA7432_RF, rf);
tda7432_write(sd, TDA7432_RR, rr);
return 0;
case V4L2_CID_AUDIO_VOLUME:
volume = 0x6f - ctrl->val;
if (loudness)
volume |= TDA7432_LD_ON;
tda7432_write(sd, TDA7432_VL, volume);
return 0;
case V4L2_CID_AUDIO_BASS:
bass = t->bass->val;
treble = t->treble->val;
if (bass >= 0x8)
bass = 14 - (bass - 8);
if (treble >= 0x8)
treble = 14 - (treble - 8);
tda7432_write(sd, TDA7432_TN, 0x10 | (bass << 4) | treble);
return 0;
}
return -EINVAL;
}
static int tda7432_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tda7432 *t;
struct v4l2_subdev *sd;
v4l_info(client, "chip found @ 0x%02x (%s)\n",
client->addr << 1, client->adapter->name);
t = devm_kzalloc(&client->dev, sizeof(*t), GFP_KERNEL);
if (!t)
return -ENOMEM;
sd = &t->sd;
v4l2_i2c_subdev_init(sd, client, &tda7432_ops);
v4l2_ctrl_handler_init(&t->hdl, 5);
v4l2_ctrl_new_std(&t->hdl, &tda7432_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, maxvol ? 0x68 : 0x4f, 1, maxvol ? 0x5d : 0x47);
t->mute = v4l2_ctrl_new_std(&t->hdl, &tda7432_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
t->balance = v4l2_ctrl_new_std(&t->hdl, &tda7432_ctrl_ops,
V4L2_CID_AUDIO_BALANCE, -31, 31, 1, 0);
t->bass = v4l2_ctrl_new_std(&t->hdl, &tda7432_ctrl_ops,
V4L2_CID_AUDIO_BASS, 0, 14, 1, 7);
t->treble = v4l2_ctrl_new_std(&t->hdl, &tda7432_ctrl_ops,
V4L2_CID_AUDIO_TREBLE, 0, 14, 1, 7);
sd->ctrl_handler = &t->hdl;
if (t->hdl.error) {
int err = t->hdl.error;
v4l2_ctrl_handler_free(&t->hdl);
return err;
}
v4l2_ctrl_cluster(2, &t->bass);
v4l2_ctrl_cluster(2, &t->mute);
v4l2_ctrl_handler_setup(&t->hdl);
if (loudness < 0 || loudness > 15) {
v4l2_warn(sd, "loudness parameter must be between 0 and 15\n");
if (loudness < 0)
loudness = 0;
if (loudness > 15)
loudness = 15;
}
tda7432_set(sd);
return 0;
}
static int tda7432_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct tda7432 *t = to_state(sd);
tda7432_set(sd);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&t->hdl);
return 0;
}
