static inline struct tda7432 *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct tda7432, sd);
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
struct tda7432 *t = to_state(sd);
unsigned char buf[16];
v4l2_dbg(1, debug, sd,
"tda7432: 7432_set(0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x)\n",
t->input, t->volume, t->bass, t->treble, t->lf, t->lr,
t->rf, t->rr, t->loud);
buf[0] = TDA7432_IN;
buf[1] = t->input;
buf[2] = t->volume;
buf[3] = t->bass;
buf[4] = t->treble;
buf[5] = t->lf;
buf[6] = t->lr;
buf[7] = t->rf;
buf[8] = t->rr;
buf[9] = t->loud;
if (10 != i2c_master_send(client, buf, 10)) {
v4l2_err(sd, "I/O error, trying tda7432_set\n");
return -1;
}
return 0;
}
static void do_tda7432_init(struct v4l2_subdev *sd)
{
struct tda7432 *t = to_state(sd);
v4l2_dbg(2, debug, sd, "In tda7432_init\n");
t->input = TDA7432_STEREO_IN |
TDA7432_BASS_SYM |
TDA7432_BASS_NORM;
t->volume = 0x3b ;
if (loudness)
t->volume |= TDA7432_LD_ON;
t->muted = 1;
t->treble = TDA7432_TREBLE_0DB;
t->bass = TDA7432_BASS_0DB;
t->lf = TDA7432_ATTEN_0DB;
t->lr = TDA7432_ATTEN_0DB;
t->rf = TDA7432_ATTEN_0DB;
t->rr = TDA7432_ATTEN_0DB;
t->loud = loudness;
tda7432_set(sd);
}
static int tda7432_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct tda7432 *t = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value=t->muted;
return 0;
case V4L2_CID_AUDIO_VOLUME:
if (!maxvol){
ctrl->value = ( 0x6f - (t->volume & 0x7F) ) * 630;
} else {
ctrl->value = ( 0x6f - (t->volume & 0x7F) ) * 829;
}
return 0;
case V4L2_CID_AUDIO_BALANCE:
{
if ( (t->lf) < (t->rf) )
ctrl->value = (32768 - 1057*(t->rf));
else
ctrl->value = (32768 + 1057*(t->lf));
return 0;
}
case V4L2_CID_AUDIO_BASS:
{
int bass=t->bass;
if(bass >= 0x8)
bass = ~(bass - 0x8) & 0xf;
ctrl->value = (bass << 12)+(bass << 8)+(bass << 4)+(bass);
return 0;
}
case V4L2_CID_AUDIO_TREBLE:
{
int treble=t->treble;
if(treble >= 0x8)
treble = ~(treble - 0x8) & 0xf;
ctrl->value = (treble << 12)+(treble << 8)+(treble << 4)+(treble);
return 0;
}
}
return -EINVAL;
}
static int tda7432_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct tda7432 *t = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
t->muted=ctrl->value;
break;
case V4L2_CID_AUDIO_VOLUME:
if(!maxvol){
t->volume = 0x6f - ((ctrl->value)/630);
} else {
t->volume = 0x6f - ((ctrl->value)/829);
}
if (loudness)
t->volume |= TDA7432_LD_ON;
tda7432_write(sd, TDA7432_VL, t->volume);
return 0;
case V4L2_CID_AUDIO_BALANCE:
if (ctrl->value < 32768) {
t->rr = (32768 - ctrl->value)/1057;
t->rf = t->rr;
t->lr = TDA7432_ATTEN_0DB;
t->lf = TDA7432_ATTEN_0DB;
} else if(ctrl->value > 32769) {
t->lf = (ctrl->value - 32768)/1057;
t->lr = t->lf;
t->rr = TDA7432_ATTEN_0DB;
t->rf = TDA7432_ATTEN_0DB;
} else {
t->rr = TDA7432_ATTEN_0DB;
t->rf = TDA7432_ATTEN_0DB;
t->lf = TDA7432_ATTEN_0DB;
t->lr = TDA7432_ATTEN_0DB;
}
break;
case V4L2_CID_AUDIO_BASS:
t->bass = ctrl->value >> 12;
if(t->bass>= 0x8)
t->bass = (~t->bass & 0xf) + 0x8 ;
tda7432_write(sd, TDA7432_TN, 0x10 | (t->bass << 4) | t->treble);
return 0;
case V4L2_CID_AUDIO_TREBLE:
t->treble= ctrl->value >> 12;
if(t->treble>= 0x8)
t->treble = (~t->treble & 0xf) + 0x8 ;
tda7432_write(sd, TDA7432_TN, 0x10 | (t->bass << 4) | t->treble);
return 0;
default:
return -EINVAL;
}
if (t->muted)
{
tda7432_write(sd, TDA7432_LF, t->lf | TDA7432_MUTE);
tda7432_write(sd, TDA7432_LR, t->lr | TDA7432_MUTE);
tda7432_write(sd, TDA7432_RF, t->rf | TDA7432_MUTE);
tda7432_write(sd, TDA7432_RR, t->rr | TDA7432_MUTE);
} else {
tda7432_write(sd, TDA7432_LF, t->lf);
tda7432_write(sd, TDA7432_LR, t->lr);
tda7432_write(sd, TDA7432_RF, t->rf);
tda7432_write(sd, TDA7432_RR, t->rr);
}
return 0;
}
static int tda7432_queryctrl(struct v4l2_subdev *sd, struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_VOLUME:
return v4l2_ctrl_query_fill(qc, 0, 65535, 65535 / 100, 58880);
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 0);
case V4L2_CID_AUDIO_BALANCE:
case V4L2_CID_AUDIO_BASS:
case V4L2_CID_AUDIO_TREBLE:
return v4l2_ctrl_query_fill(qc, 0, 65535, 65535 / 100, 32768);
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
t = kzalloc(sizeof(*t), GFP_KERNEL);
if (!t)
return -ENOMEM;
sd = &t->sd;
v4l2_i2c_subdev_init(sd, client, &tda7432_ops);
if (loudness < 0 || loudness > 15) {
v4l2_warn(sd, "loudness parameter must be between 0 and 15\n");
if (loudness < 0)
loudness = 0;
if (loudness > 15)
loudness = 15;
}
do_tda7432_init(sd);
return 0;
}
static int tda7432_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
do_tda7432_init(sd);
v4l2_device_unregister_subdev(sd);
kfree(to_state(sd));
return 0;
}
