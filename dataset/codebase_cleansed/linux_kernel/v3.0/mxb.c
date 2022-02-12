static inline void tea6420_route_cd(struct mxb *mxb, int idx)
{
v4l2_subdev_call(mxb->tea6420_1, audio, s_routing,
TEA6420_cd[idx][0].input, TEA6420_cd[idx][0].output, 0);
v4l2_subdev_call(mxb->tea6420_2, audio, s_routing,
TEA6420_cd[idx][1].input, TEA6420_cd[idx][1].output, 0);
}
static inline void tea6420_route_line(struct mxb *mxb, int idx)
{
v4l2_subdev_call(mxb->tea6420_1, audio, s_routing,
TEA6420_line[idx][0].input, TEA6420_line[idx][0].output, 0);
v4l2_subdev_call(mxb->tea6420_2, audio, s_routing,
TEA6420_line[idx][1].input, TEA6420_line[idx][1].output, 0);
}
static int mxb_probe(struct saa7146_dev *dev)
{
struct mxb *mxb = NULL;
mxb = kzalloc(sizeof(struct mxb), GFP_KERNEL);
if (mxb == NULL) {
DEB_D(("not enough kernel memory.\n"));
return -ENOMEM;
}
snprintf(mxb->i2c_adapter.name, sizeof(mxb->i2c_adapter.name), "mxb%d", mxb_num);
saa7146_i2c_adapter_prepare(dev, &mxb->i2c_adapter, SAA7146_I2C_BUS_BIT_RATE_480);
if (i2c_add_adapter(&mxb->i2c_adapter) < 0) {
DEB_S(("cannot register i2c-device. skipping.\n"));
kfree(mxb);
return -EFAULT;
}
mxb->saa7111a = v4l2_i2c_new_subdev(&dev->v4l2_dev, &mxb->i2c_adapter,
"saa7111", I2C_SAA7111A, NULL);
mxb->tea6420_1 = v4l2_i2c_new_subdev(&dev->v4l2_dev, &mxb->i2c_adapter,
"tea6420", I2C_TEA6420_1, NULL);
mxb->tea6420_2 = v4l2_i2c_new_subdev(&dev->v4l2_dev, &mxb->i2c_adapter,
"tea6420", I2C_TEA6420_2, NULL);
mxb->tea6415c = v4l2_i2c_new_subdev(&dev->v4l2_dev, &mxb->i2c_adapter,
"tea6415c", I2C_TEA6415C, NULL);
mxb->tda9840 = v4l2_i2c_new_subdev(&dev->v4l2_dev, &mxb->i2c_adapter,
"tda9840", I2C_TDA9840, NULL);
mxb->tuner = v4l2_i2c_new_subdev(&dev->v4l2_dev, &mxb->i2c_adapter,
"tuner", I2C_TUNER, NULL);
if (!mxb->tea6420_1 || !mxb->tea6420_2 || !mxb->tea6415c ||
!mxb->tda9840 || !mxb->saa7111a || !mxb->tuner) {
printk("mxb: did not find all i2c devices. aborting\n");
i2c_del_adapter(&mxb->i2c_adapter);
kfree(mxb);
return -ENODEV;
}
dev->ext_priv = mxb;
return 0;
}
static int mxb_init_done(struct saa7146_dev* dev)
{
struct mxb* mxb = (struct mxb*)dev->ext_priv;
struct i2c_msg msg;
struct tuner_setup tun_setup;
v4l2_std_id std = V4L2_STD_PAL_BG;
int i = 0, err = 0;
saa7111a_call(mxb, core, s_std, std);
i = 0;
saa7111a_call(mxb, video, s_routing, SAA7115_COMPOSITE0,
SAA7111_FMT_CCIR, 0);
tun_setup.mode_mask = T_ANALOG_TV;
tun_setup.addr = ADDR_UNSET;
tun_setup.type = TUNER_PHILIPS_PAL;
tuner_call(mxb, tuner, s_type_addr, &tun_setup);
mxb->cur_freq.tuner = 0;
mxb->cur_freq.type = V4L2_TUNER_ANALOG_TV;
mxb->cur_freq.frequency = freq;
tuner_call(mxb, tuner, s_frequency, &mxb->cur_freq);
tuner_call(mxb, core, s_std, std);
tea6420_route_line(mxb, 6);
tea6420_route_cd(mxb, 6);
tea6415c_call(mxb, video, s_routing, 3, 17, 0);
tea6415c_call(mxb, video, s_routing, 3, 13, 0);
mxb->cur_input = 0;
mxb->cur_mute = 1;
mxb->cur_mode = V4L2_TUNER_MODE_STEREO;
msg.addr = 0x1b;
msg.flags = 0;
msg.len = mxb_saa7740_init[0].length;
msg.buf = &mxb_saa7740_init[0].data[0];
err = i2c_transfer(&mxb->i2c_adapter, &msg, 1);
if (err == 1) {
extension.flags &= ~SAA7146_USE_I2C_IRQ;
for (i = 1; ; i++) {
if (-1 == mxb_saa7740_init[i].length)
break;
msg.len = mxb_saa7740_init[i].length;
msg.buf = &mxb_saa7740_init[i].data[0];
err = i2c_transfer(&mxb->i2c_adapter, &msg, 1);
if (err != 1) {
DEB_D(("failed to initialize 'sound arena module'.\n"));
goto err;
}
}
INFO(("'sound arena module' detected.\n"));
}
err:
saa7146_set_hps_source_and_sync(dev, input_port_selection[mxb->cur_input].hps_source,
input_port_selection[mxb->cur_input].hps_sync);
saa7146_write(dev, DD1_STREAM_B, 0x00000000);
saa7146_write(dev, DD1_INIT, 0x02000200);
saa7146_write(dev, MC2, (MASK_09 | MASK_25 | MASK_10 | MASK_26));
return 0;
}
static int vidioc_queryctrl(struct file *file, void *fh, struct v4l2_queryctrl *qc)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
int i;
for (i = MAXCONTROLS - 1; i >= 0; i--) {
if (mxb_controls[i].id == qc->id) {
*qc = mxb_controls[i];
DEB_D(("VIDIOC_QUERYCTRL %d.\n", qc->id));
return 0;
}
}
return dev->ext_vv_data->core_ops->vidioc_queryctrl(file, fh, qc);
}
static int vidioc_g_ctrl(struct file *file, void *fh, struct v4l2_control *vc)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
int i;
for (i = MAXCONTROLS - 1; i >= 0; i--) {
if (mxb_controls[i].id == vc->id)
break;
}
if (i < 0)
return dev->ext_vv_data->core_ops->vidioc_g_ctrl(file, fh, vc);
if (vc->id == V4L2_CID_AUDIO_MUTE) {
vc->value = mxb->cur_mute;
DEB_D(("VIDIOC_G_CTRL V4L2_CID_AUDIO_MUTE:%d.\n", vc->value));
return 0;
}
DEB_EE(("VIDIOC_G_CTRL V4L2_CID_AUDIO_MUTE:%d.\n", vc->value));
return 0;
}
static int vidioc_s_ctrl(struct file *file, void *fh, struct v4l2_control *vc)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
int i = 0;
for (i = MAXCONTROLS - 1; i >= 0; i--) {
if (mxb_controls[i].id == vc->id)
break;
}
if (i < 0)
return dev->ext_vv_data->core_ops->vidioc_s_ctrl(file, fh, vc);
if (vc->id == V4L2_CID_AUDIO_MUTE) {
mxb->cur_mute = vc->value;
tea6420_route_line(mxb, vc->value ? 6 :
video_audio_connect[mxb->cur_input]);
DEB_EE(("VIDIOC_S_CTRL, V4L2_CID_AUDIO_MUTE: %d.\n", vc->value));
}
return 0;
}
static int vidioc_enum_input(struct file *file, void *fh, struct v4l2_input *i)
{
DEB_EE(("VIDIOC_ENUMINPUT %d.\n", i->index));
if (i->index >= MXB_INPUTS)
return -EINVAL;
memcpy(i, &mxb_inputs[i->index], sizeof(struct v4l2_input));
return 0;
}
static int vidioc_g_input(struct file *file, void *fh, unsigned int *i)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
*i = mxb->cur_input;
DEB_EE(("VIDIOC_G_INPUT %d.\n", *i));
return 0;
}
static int vidioc_s_input(struct file *file, void *fh, unsigned int input)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
int err = 0;
int i = 0;
DEB_EE(("VIDIOC_S_INPUT %d.\n", input));
if (input >= MXB_INPUTS)
return -EINVAL;
mxb->cur_input = input;
saa7146_set_hps_source_and_sync(dev, input_port_selection[input].hps_source,
input_port_selection[input].hps_sync);
switch (input) {
case TUNER:
i = SAA7115_COMPOSITE0;
err = tea6415c_call(mxb, video, s_routing, 3, 17, 0);
if (!err)
err = tea6415c_call(mxb, video, s_routing, 3, 13, 0);
break;
case AUX3_YC:
i = SAA7115_SVIDEO1;
break;
case AUX3:
i = SAA7115_COMPOSITE1;
break;
case AUX1:
i = SAA7115_COMPOSITE0;
err = tea6415c_call(mxb, video, s_routing, 1, 17, 0);
break;
}
if (err)
return err;
if (saa7111a_call(mxb, video, s_routing, i, SAA7111_FMT_CCIR, 0))
printk(KERN_ERR "VIDIOC_S_INPUT: could not address saa7111a.\n");
if (0 == mxb->cur_mute)
tea6420_route_line(mxb, video_audio_connect[input]);
return 0;
}
static int vidioc_g_tuner(struct file *file, void *fh, struct v4l2_tuner *t)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
if (t->index) {
DEB_D(("VIDIOC_G_TUNER: channel %d does not have a tuner attached.\n", t->index));
return -EINVAL;
}
DEB_EE(("VIDIOC_G_TUNER: %d\n", t->index));
memset(t, 0, sizeof(*t));
strlcpy(t->name, "TV Tuner", sizeof(t->name));
t->type = V4L2_TUNER_ANALOG_TV;
t->capability = V4L2_TUNER_CAP_NORM | V4L2_TUNER_CAP_STEREO |
V4L2_TUNER_CAP_LANG1 | V4L2_TUNER_CAP_LANG2 | V4L2_TUNER_CAP_SAP;
t->audmode = mxb->cur_mode;
return call_all(dev, tuner, g_tuner, t);
}
static int vidioc_s_tuner(struct file *file, void *fh, struct v4l2_tuner *t)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
if (t->index) {
DEB_D(("VIDIOC_S_TUNER: channel %d does not have a tuner attached.\n", t->index));
return -EINVAL;
}
mxb->cur_mode = t->audmode;
return call_all(dev, tuner, s_tuner, t);
}
static int vidioc_g_frequency(struct file *file, void *fh, struct v4l2_frequency *f)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
if (mxb->cur_input) {
DEB_D(("VIDIOC_G_FREQ: channel %d does not have a tuner!\n",
mxb->cur_input));
return -EINVAL;
}
*f = mxb->cur_freq;
DEB_EE(("VIDIOC_G_FREQ: freq:0x%08x.\n", mxb->cur_freq.frequency));
return 0;
}
static int vidioc_s_frequency(struct file *file, void *fh, struct v4l2_frequency *f)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
struct saa7146_vv *vv = dev->vv_data;
if (f->tuner)
return -EINVAL;
if (V4L2_TUNER_ANALOG_TV != f->type)
return -EINVAL;
if (mxb->cur_input) {
DEB_D(("VIDIOC_S_FREQ: channel %d does not have a tuner!\n", mxb->cur_input));
return -EINVAL;
}
mxb->cur_freq = *f;
DEB_EE(("VIDIOC_S_FREQUENCY: freq:0x%08x.\n", mxb->cur_freq.frequency));
tuner_call(mxb, tuner, s_frequency, &mxb->cur_freq);
spin_lock(&dev->slock);
vv->vbi_fieldcount = 0;
spin_unlock(&dev->slock);
return 0;
}
static int vidioc_g_audio(struct file *file, void *fh, struct v4l2_audio *a)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
if (a->index > MXB_INPUTS) {
DEB_D(("VIDIOC_G_AUDIO %d out of range.\n", a->index));
return -EINVAL;
}
DEB_EE(("VIDIOC_G_AUDIO %d.\n", a->index));
memcpy(a, &mxb_audios[video_audio_connect[mxb->cur_input]], sizeof(struct v4l2_audio));
return 0;
}
static int vidioc_s_audio(struct file *file, void *fh, struct v4l2_audio *a)
{
DEB_D(("VIDIOC_S_AUDIO %d.\n", a->index));
return 0;
}
static int vidioc_g_register(struct file *file, void *fh, struct v4l2_dbg_register *reg)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
return call_all(dev, core, g_register, reg);
}
static int vidioc_s_register(struct file *file, void *fh, struct v4l2_dbg_register *reg)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
return call_all(dev, core, s_register, reg);
}
static long vidioc_default(struct file *file, void *fh, bool valid_prio,
int cmd, void *arg)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct mxb *mxb = (struct mxb *)dev->ext_priv;
switch (cmd) {
case MXB_S_AUDIO_CD:
{
int i = *(int *)arg;
if (i < 0 || i >= MXB_AUDIOS) {
DEB_D(("illegal argument to MXB_S_AUDIO_CD: i:%d.\n", i));
return -EINVAL;
}
DEB_EE(("MXB_S_AUDIO_CD: i:%d.\n", i));
tea6420_route_cd(mxb, i);
return 0;
}
case MXB_S_AUDIO_LINE:
{
int i = *(int *)arg;
if (i < 0 || i >= MXB_AUDIOS) {
DEB_D(("illegal argument to MXB_S_AUDIO_LINE: i:%d.\n", i));
return -EINVAL;
}
DEB_EE(("MXB_S_AUDIO_LINE: i:%d.\n", i));
tea6420_route_line(mxb, i);
return 0;
}
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int mxb_attach(struct saa7146_dev *dev, struct saa7146_pci_extension_data *info)
{
struct mxb *mxb;
DEB_EE(("dev:%p\n", dev));
saa7146_vv_init(dev, &vv_data);
if (mxb_probe(dev)) {
saa7146_vv_release(dev);
return -1;
}
mxb = (struct mxb *)dev->ext_priv;
vv_data.ops.vidioc_queryctrl = vidioc_queryctrl;
vv_data.ops.vidioc_g_ctrl = vidioc_g_ctrl;
vv_data.ops.vidioc_s_ctrl = vidioc_s_ctrl;
vv_data.ops.vidioc_enum_input = vidioc_enum_input;
vv_data.ops.vidioc_g_input = vidioc_g_input;
vv_data.ops.vidioc_s_input = vidioc_s_input;
vv_data.ops.vidioc_g_tuner = vidioc_g_tuner;
vv_data.ops.vidioc_s_tuner = vidioc_s_tuner;
vv_data.ops.vidioc_g_frequency = vidioc_g_frequency;
vv_data.ops.vidioc_s_frequency = vidioc_s_frequency;
vv_data.ops.vidioc_g_audio = vidioc_g_audio;
vv_data.ops.vidioc_s_audio = vidioc_s_audio;
#ifdef CONFIG_VIDEO_ADV_DEBUG
vv_data.ops.vidioc_g_register = vidioc_g_register;
vv_data.ops.vidioc_s_register = vidioc_s_register;
#endif
vv_data.ops.vidioc_default = vidioc_default;
if (saa7146_register_device(&mxb->video_dev, dev, "mxb", VFL_TYPE_GRABBER)) {
ERR(("cannot register capture v4l2 device. skipping.\n"));
saa7146_vv_release(dev);
return -1;
}
if (MXB_BOARD_CAN_DO_VBI(dev)) {
if (saa7146_register_device(&mxb->vbi_dev, dev, "mxb", VFL_TYPE_VBI)) {
ERR(("cannot register vbi v4l2 device. skipping.\n"));
}
}
printk("mxb: found Multimedia eXtension Board #%d.\n", mxb_num);
mxb_num++;
mxb_init_done(dev);
return 0;
}
static int mxb_detach(struct saa7146_dev *dev)
{
struct mxb *mxb = (struct mxb *)dev->ext_priv;
DEB_EE(("dev:%p\n", dev));
saa7146_unregister_device(&mxb->video_dev,dev);
if (MXB_BOARD_CAN_DO_VBI(dev))
saa7146_unregister_device(&mxb->vbi_dev, dev);
saa7146_vv_release(dev);
mxb_num--;
i2c_del_adapter(&mxb->i2c_adapter);
kfree(mxb);
return 0;
}
static int std_callback(struct saa7146_dev *dev, struct saa7146_standard *standard)
{
struct mxb *mxb = (struct mxb *)dev->ext_priv;
if (V4L2_STD_PAL_I == standard->id) {
v4l2_std_id std = V4L2_STD_PAL_I;
DEB_D(("VIDIOC_S_STD: setting mxb for PAL_I.\n"));
saa7146_write(dev, GPIO_CTRL, 0x00404050);
saa7111a_call(mxb, core, s_gpio, 0);
tuner_call(mxb, core, s_std, std);
} else {
v4l2_std_id std = V4L2_STD_PAL_BG;
DEB_D(("VIDIOC_S_STD: setting mxb for PAL/NTSC/SECAM.\n"));
saa7146_write(dev, GPIO_CTRL, 0x00404050);
saa7111a_call(mxb, core, s_gpio, 1);
tuner_call(mxb, core, s_std, std);
}
return 0;
}
static int __init mxb_init_module(void)
{
if (saa7146_register_extension(&extension)) {
DEB_S(("failed to register extension.\n"));
return -ENODEV;
}
return 0;
}
static void __exit mxb_cleanup_module(void)
{
saa7146_unregister_extension(&extension);
}
