int msp_writereg(struct av7110 *av7110, u8 dev, u16 reg, u16 val)
{
u8 msg[5] = { dev, reg >> 8, reg & 0xff, val >> 8 , val & 0xff };
struct i2c_msg msgs = { .flags = 0, .len = 5, .buf = msg };
switch (av7110->adac_type) {
case DVB_ADAC_MSP34x0:
msgs.addr = 0x40;
break;
case DVB_ADAC_MSP34x5:
msgs.addr = 0x42;
break;
default:
return 0;
}
if (i2c_transfer(&av7110->i2c_adap, &msgs, 1) != 1) {
dprintk(1, "dvb-ttpci: failed @ card %d, %u = %u\n",
av7110->dvb_adapter.num, reg, val);
return -EIO;
}
return 0;
}
static int msp_readreg(struct av7110 *av7110, u8 dev, u16 reg, u16 *val)
{
u8 msg1[3] = { dev, reg >> 8, reg & 0xff };
u8 msg2[2];
struct i2c_msg msgs[2] = {
{ .flags = 0 , .len = 3, .buf = msg1 },
{ .flags = I2C_M_RD, .len = 2, .buf = msg2 }
};
switch (av7110->adac_type) {
case DVB_ADAC_MSP34x0:
msgs[0].addr = 0x40;
msgs[1].addr = 0x40;
break;
case DVB_ADAC_MSP34x5:
msgs[0].addr = 0x42;
msgs[1].addr = 0x42;
break;
default:
return 0;
}
if (i2c_transfer(&av7110->i2c_adap, &msgs[0], 2) != 2) {
dprintk(1, "dvb-ttpci: failed @ card %d, %u\n",
av7110->dvb_adapter.num, reg);
return -EIO;
}
*val = (msg2[0] << 8) | msg2[1];
return 0;
}
static int ves1820_writereg(struct saa7146_dev *dev, u8 addr, u8 reg, u8 data)
{
struct av7110 *av7110 = dev->ext_priv;
u8 buf[] = { 0x00, reg, data };
struct i2c_msg msg = { .addr = addr, .flags = 0, .buf = buf, .len = 3 };
dprintk(4, "dev: %p\n", dev);
if (1 != i2c_transfer(&av7110->i2c_adap, &msg, 1))
return -1;
return 0;
}
static int tuner_write(struct saa7146_dev *dev, u8 addr, u8 data [4])
{
struct av7110 *av7110 = dev->ext_priv;
struct i2c_msg msg = { .addr = addr, .flags = 0, .buf = data, .len = 4 };
dprintk(4, "dev: %p\n", dev);
if (1 != i2c_transfer(&av7110->i2c_adap, &msg, 1))
return -1;
return 0;
}
static int ves1820_set_tv_freq(struct saa7146_dev *dev, u32 freq)
{
u32 div;
u8 config;
u8 buf[4];
dprintk(4, "freq: 0x%08x\n", freq);
div = freq + 614;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0x8e;
if (freq < (u32) (16 * 168.25))
config = 0xa0;
else if (freq < (u32) (16 * 447.25))
config = 0x90;
else
config = 0x30;
config &= ~0x02;
buf[3] = config;
return tuner_write(dev, 0x61, buf);
}
static int stv0297_set_tv_freq(struct saa7146_dev *dev, u32 freq)
{
struct av7110 *av7110 = (struct av7110*)dev->ext_priv;
u32 div;
u8 data[4];
div = (freq + 38900000 + 31250) / 62500;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = 0xce;
if (freq < 45000000)
return -EINVAL;
else if (freq < 137000000)
data[3] = 0x01;
else if (freq < 403000000)
data[3] = 0x02;
else if (freq < 860000000)
data[3] = 0x04;
else
return -EINVAL;
if (av7110->fe->ops.i2c_gate_ctrl)
av7110->fe->ops.i2c_gate_ctrl(av7110->fe, 1);
return tuner_write(dev, 0x63, data);
}
static int av7110_dvb_c_switch(struct saa7146_fh *fh)
{
struct saa7146_dev *dev = fh->dev;
struct saa7146_vv *vv = dev->vv_data;
struct av7110 *av7110 = (struct av7110*)dev->ext_priv;
u16 adswitch;
int source, sync, err;
dprintk(4, "%p\n", av7110);
if ((vv->video_status & STATUS_OVERLAY) != 0) {
vv->ov_suspend = vv->video_fh;
err = saa7146_stop_preview(vv->video_fh);
if (err != 0) {
dprintk(2, "suspending video failed\n");
vv->ov_suspend = NULL;
}
}
if (0 != av7110->current_input) {
dprintk(1, "switching to analog TV:\n");
adswitch = 1;
source = SAA7146_HPS_SOURCE_PORT_B;
sync = SAA7146_HPS_SYNC_PORT_B;
memcpy(standard, analog_standard, sizeof(struct saa7146_standard) * 2);
switch (av7110->current_input) {
case 1:
dprintk(1, "switching SAA7113 to Analog Tuner Input.\n");
msp_writereg(av7110, MSP_WR_DSP, 0x0008, 0x0000);
msp_writereg(av7110, MSP_WR_DSP, 0x0009, 0x0000);
msp_writereg(av7110, MSP_WR_DSP, 0x000a, 0x0000);
msp_writereg(av7110, MSP_WR_DSP, 0x000e, 0x3000);
msp_writereg(av7110, MSP_WR_DSP, 0x0000, 0x4f00);
msp_writereg(av7110, MSP_WR_DSP, 0x0007, 0x4f00);
if (av7110->analog_tuner_flags & ANALOG_TUNER_VES1820) {
if (ves1820_writereg(dev, 0x09, 0x0f, 0x60))
dprintk(1, "setting band in demodulator failed.\n");
} else if (av7110->analog_tuner_flags & ANALOG_TUNER_STV0297) {
saa7146_setgpio(dev, 1, SAA7146_GPIO_OUTHI);
saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTHI);
}
if (i2c_writereg(av7110, 0x48, 0x02, 0xd0) != 1)
dprintk(1, "saa7113 write failed @ card %d", av7110->dvb_adapter.num);
break;
case 2:
dprintk(1, "switching SAA7113 to Video AV CVBS Input.\n");
if (i2c_writereg(av7110, 0x48, 0x02, 0xd2) != 1)
dprintk(1, "saa7113 write failed @ card %d", av7110->dvb_adapter.num);
break;
case 3:
dprintk(1, "switching SAA7113 to Video AV Y/C Input.\n");
if (i2c_writereg(av7110, 0x48, 0x02, 0xd9) != 1)
dprintk(1, "saa7113 write failed @ card %d", av7110->dvb_adapter.num);
break;
default:
dprintk(1, "switching SAA7113 to Input: AV7110: SAA7113: invalid input.\n");
}
} else {
adswitch = 0;
source = SAA7146_HPS_SOURCE_PORT_A;
sync = SAA7146_HPS_SYNC_PORT_A;
memcpy(standard, dvb_standard, sizeof(struct saa7146_standard) * 2);
dprintk(1, "switching DVB mode\n");
msp_writereg(av7110, MSP_WR_DSP, 0x0008, 0x0220);
msp_writereg(av7110, MSP_WR_DSP, 0x0009, 0x0220);
msp_writereg(av7110, MSP_WR_DSP, 0x000a, 0x0220);
msp_writereg(av7110, MSP_WR_DSP, 0x000e, 0x3000);
msp_writereg(av7110, MSP_WR_DSP, 0x0000, 0x7f00);
msp_writereg(av7110, MSP_WR_DSP, 0x0007, 0x7f00);
if (av7110->analog_tuner_flags & ANALOG_TUNER_VES1820) {
if (ves1820_writereg(dev, 0x09, 0x0f, 0x20))
dprintk(1, "setting band in demodulator failed.\n");
} else if (av7110->analog_tuner_flags & ANALOG_TUNER_STV0297) {
saa7146_setgpio(dev, 1, SAA7146_GPIO_OUTLO);
saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
}
}
if (av7110_fw_cmd(av7110, COMTYPE_AUDIODAC, ADSwitch, 1, adswitch))
dprintk(1, "ADSwitch error\n");
saa7146_set_hps_source_and_sync(dev, source, sync);
if (vv->ov_suspend != NULL) {
saa7146_start_preview(vv->ov_suspend);
vv->ov_suspend = NULL;
}
return 0;
}
static int vidioc_g_tuner(struct file *file, void *fh, struct v4l2_tuner *t)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
u16 stereo_det;
s8 stereo;
dprintk(2, "VIDIOC_G_TUNER: %d\n", t->index);
if (!av7110->analog_tuner_flags || t->index != 0)
return -EINVAL;
memset(t, 0, sizeof(*t));
strcpy((char *)t->name, "Television");
t->type = V4L2_TUNER_ANALOG_TV;
t->capability = V4L2_TUNER_CAP_NORM | V4L2_TUNER_CAP_STEREO |
V4L2_TUNER_CAP_LANG1 | V4L2_TUNER_CAP_LANG2 | V4L2_TUNER_CAP_SAP;
t->rangelow = 772;
t->rangehigh = 13684;
t->signal = 0xffff;
t->afc = 0;
msp_readreg(av7110, MSP_RD_DEM, 0x007e, &stereo_det);
dprintk(1, "VIDIOC_G_TUNER: msp3400 TV standard detection: 0x%04x\n", stereo_det);
msp_readreg(av7110, MSP_RD_DSP, 0x0018, &stereo_det);
dprintk(1, "VIDIOC_G_TUNER: msp3400 stereo detection: 0x%04x\n", stereo_det);
stereo = (s8)(stereo_det >> 8);
if (stereo > 0x10) {
t->rxsubchans = V4L2_TUNER_SUB_STEREO | V4L2_TUNER_SUB_MONO;
t->audmode = V4L2_TUNER_MODE_STEREO;
} else if (stereo < -0x10) {
t->rxsubchans = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
t->audmode = V4L2_TUNER_MODE_LANG1;
} else
t->rxsubchans = V4L2_TUNER_SUB_MONO;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *fh, struct v4l2_tuner *t)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
u16 fm_matrix, src;
dprintk(2, "VIDIOC_S_TUNER: %d\n", t->index);
if (!av7110->analog_tuner_flags || av7110->current_input != 1)
return -EINVAL;
switch (t->audmode) {
case V4L2_TUNER_MODE_STEREO:
dprintk(2, "VIDIOC_S_TUNER: V4L2_TUNER_MODE_STEREO\n");
fm_matrix = 0x3001;
src = 0x0020;
break;
case V4L2_TUNER_MODE_LANG1_LANG2:
dprintk(2, "VIDIOC_S_TUNER: V4L2_TUNER_MODE_LANG1_LANG2\n");
fm_matrix = 0x3000;
src = 0x0020;
break;
case V4L2_TUNER_MODE_LANG1:
dprintk(2, "VIDIOC_S_TUNER: V4L2_TUNER_MODE_LANG1\n");
fm_matrix = 0x3000;
src = 0x0000;
break;
case V4L2_TUNER_MODE_LANG2:
dprintk(2, "VIDIOC_S_TUNER: V4L2_TUNER_MODE_LANG2\n");
fm_matrix = 0x3000;
src = 0x0010;
break;
default:
dprintk(2, "VIDIOC_S_TUNER: TDA9840_SET_MONO\n");
fm_matrix = 0x3000;
src = 0x0030;
break;
}
msp_writereg(av7110, MSP_WR_DSP, 0x000e, fm_matrix);
msp_writereg(av7110, MSP_WR_DSP, 0x0008, src);
msp_writereg(av7110, MSP_WR_DSP, 0x0009, src);
msp_writereg(av7110, MSP_WR_DSP, 0x000a, src);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *fh, struct v4l2_frequency *f)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
dprintk(2, "VIDIOC_G_FREQ: freq:0x%08x.\n", f->frequency);
if (!av7110->analog_tuner_flags || av7110->current_input != 1)
return -EINVAL;
memset(f, 0, sizeof(*f));
f->type = V4L2_TUNER_ANALOG_TV;
f->frequency = av7110->current_freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *fh, struct v4l2_frequency *f)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
dprintk(2, "VIDIOC_S_FREQUENCY: freq:0x%08x.\n", f->frequency);
if (!av7110->analog_tuner_flags || av7110->current_input != 1)
return -EINVAL;
if (V4L2_TUNER_ANALOG_TV != f->type)
return -EINVAL;
msp_writereg(av7110, MSP_WR_DSP, 0x0000, 0xffe0);
msp_writereg(av7110, MSP_WR_DSP, 0x0007, 0xffe0);
if (av7110->analog_tuner_flags & ANALOG_TUNER_VES1820)
ves1820_set_tv_freq(dev, f->frequency);
else if (av7110->analog_tuner_flags & ANALOG_TUNER_STV0297)
stv0297_set_tv_freq(dev, f->frequency);
av7110->current_freq = f->frequency;
msp_writereg(av7110, MSP_WR_DSP, 0x0015, 0x003f);
msp_writereg(av7110, MSP_WR_DSP, 0x0015, 0x0000);
msp_writereg(av7110, MSP_WR_DSP, 0x0000, 0x4f00);
msp_writereg(av7110, MSP_WR_DSP, 0x0007, 0x4f00);
return 0;
}
static int vidioc_enum_input(struct file *file, void *fh, struct v4l2_input *i)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
dprintk(2, "VIDIOC_ENUMINPUT: %d\n", i->index);
if (av7110->analog_tuner_flags) {
if (i->index >= 4)
return -EINVAL;
} else {
if (i->index != 0)
return -EINVAL;
}
memcpy(i, &inputs[i->index], sizeof(struct v4l2_input));
return 0;
}
static int vidioc_g_input(struct file *file, void *fh, unsigned int *input)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
*input = av7110->current_input;
dprintk(2, "VIDIOC_G_INPUT: %d\n", *input);
return 0;
}
static int vidioc_s_input(struct file *file, void *fh, unsigned int input)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
dprintk(2, "VIDIOC_S_INPUT: %d\n", input);
if (!av7110->analog_tuner_flags)
return 0;
if (input >= 4)
return -EINVAL;
av7110->current_input = input;
return av7110_dvb_c_switch(fh);
}
static int vidioc_g_audio(struct file *file, void *fh, struct v4l2_audio *a)
{
dprintk(2, "VIDIOC_G_AUDIO: %d\n", a->index);
if (a->index != 0)
return -EINVAL;
memcpy(a, &msp3400_v4l2_audio, sizeof(struct v4l2_audio));
return 0;
}
static int vidioc_s_audio(struct file *file, void *fh, struct v4l2_audio *a)
{
dprintk(2, "VIDIOC_S_AUDIO: %d\n", a->index);
return 0;
}
static int vidioc_g_sliced_vbi_cap(struct file *file, void *fh,
struct v4l2_sliced_vbi_cap *cap)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
dprintk(2, "VIDIOC_G_SLICED_VBI_CAP\n");
if (cap->type != V4L2_BUF_TYPE_SLICED_VBI_OUTPUT)
return -EINVAL;
if (FW_VERSION(av7110->arm_app) >= 0x2623) {
cap->service_set = V4L2_SLICED_WSS_625;
cap->service_lines[0][23] = V4L2_SLICED_WSS_625;
}
return 0;
}
static int vidioc_g_fmt_sliced_vbi_out(struct file *file, void *fh,
struct v4l2_format *f)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
dprintk(2, "VIDIOC_G_FMT:\n");
if (FW_VERSION(av7110->arm_app) < 0x2623)
return -EINVAL;
memset(&f->fmt.sliced, 0, sizeof f->fmt.sliced);
if (av7110->wssMode) {
f->fmt.sliced.service_set = V4L2_SLICED_WSS_625;
f->fmt.sliced.service_lines[0][23] = V4L2_SLICED_WSS_625;
f->fmt.sliced.io_size = sizeof(struct v4l2_sliced_vbi_data);
}
return 0;
}
static int vidioc_s_fmt_sliced_vbi_out(struct file *file, void *fh,
struct v4l2_format *f)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct av7110 *av7110 = (struct av7110 *)dev->ext_priv;
dprintk(2, "VIDIOC_S_FMT\n");
if (FW_VERSION(av7110->arm_app) < 0x2623)
return -EINVAL;
if (f->fmt.sliced.service_set != V4L2_SLICED_WSS_625 &&
f->fmt.sliced.service_lines[0][23] != V4L2_SLICED_WSS_625) {
memset(&f->fmt.sliced, 0, sizeof(f->fmt.sliced));
av7110->wssMode = 0;
av7110->wssData = 0;
return av7110_fw_cmd(av7110, COMTYPE_ENCODER,
SetWSSConfig, 1, 0);
} else {
memset(&f->fmt.sliced, 0, sizeof(f->fmt.sliced));
f->fmt.sliced.service_set = V4L2_SLICED_WSS_625;
f->fmt.sliced.service_lines[0][23] = V4L2_SLICED_WSS_625;
f->fmt.sliced.io_size = sizeof(struct v4l2_sliced_vbi_data);
av7110->wssMode = 1;
av7110->wssData = 0;
}
return 0;
}
static int av7110_vbi_reset(struct file *file)
{
struct saa7146_fh *fh = file->private_data;
struct saa7146_dev *dev = fh->dev;
struct av7110 *av7110 = (struct av7110*) dev->ext_priv;
dprintk(2, "%s\n", __func__);
av7110->wssMode = 0;
av7110->wssData = 0;
if (FW_VERSION(av7110->arm_app) < 0x2623)
return 0;
else
return av7110_fw_cmd(av7110, COMTYPE_ENCODER, SetWSSConfig, 1, 0);
}
static ssize_t av7110_vbi_write(struct file *file, const char __user *data, size_t count, loff_t *ppos)
{
struct saa7146_fh *fh = file->private_data;
struct saa7146_dev *dev = fh->dev;
struct av7110 *av7110 = (struct av7110*) dev->ext_priv;
struct v4l2_sliced_vbi_data d;
int rc;
dprintk(2, "%s\n", __func__);
if (FW_VERSION(av7110->arm_app) < 0x2623 || !av7110->wssMode || count != sizeof d)
return -EINVAL;
if (copy_from_user(&d, data, count))
return -EFAULT;
if ((d.id != 0 && d.id != V4L2_SLICED_WSS_625) || d.field != 0 || d.line != 23)
return -EINVAL;
if (d.id)
av7110->wssData = ((d.data[1] << 8) & 0x3f00) | d.data[0];
else
av7110->wssData = 0x8000;
rc = av7110_fw_cmd(av7110, COMTYPE_ENCODER, SetWSSConfig, 2, 1, av7110->wssData);
return (rc < 0) ? rc : count;
}
int av7110_init_analog_module(struct av7110 *av7110)
{
u16 version1, version2;
if (i2c_writereg(av7110, 0x80, 0x0, 0x80) == 1 &&
i2c_writereg(av7110, 0x80, 0x0, 0) == 1) {
printk("dvb-ttpci: DVB-C analog module @ card %d detected, initializing MSP3400\n",
av7110->dvb_adapter.num);
av7110->adac_type = DVB_ADAC_MSP34x0;
} else if (i2c_writereg(av7110, 0x84, 0x0, 0x80) == 1 &&
i2c_writereg(av7110, 0x84, 0x0, 0) == 1) {
printk("dvb-ttpci: DVB-C analog module @ card %d detected, initializing MSP3415\n",
av7110->dvb_adapter.num);
av7110->adac_type = DVB_ADAC_MSP34x5;
} else
return -ENODEV;
msleep(100);
msp_readreg(av7110, MSP_RD_DSP, 0x001e, &version1);
msp_readreg(av7110, MSP_RD_DSP, 0x001f, &version2);
dprintk(1, "dvb-ttpci: @ card %d MSP34xx version 0x%04x 0x%04x\n",
av7110->dvb_adapter.num, version1, version2);
msp_writereg(av7110, MSP_WR_DSP, 0x0013, 0x0c00);
msp_writereg(av7110, MSP_WR_DSP, 0x0000, 0x7f00);
msp_writereg(av7110, MSP_WR_DSP, 0x0008, 0x0220);
msp_writereg(av7110, MSP_WR_DSP, 0x0009, 0x0220);
msp_writereg(av7110, MSP_WR_DSP, 0x0004, 0x7f00);
msp_writereg(av7110, MSP_WR_DSP, 0x000a, 0x0220);
msp_writereg(av7110, MSP_WR_DSP, 0x0007, 0x7f00);
msp_writereg(av7110, MSP_WR_DSP, 0x000d, 0x1900);
if (i2c_writereg(av7110, 0x48, 0x01, 0x00)!=1) {
INFO(("saa7113 not accessible.\n"));
} else {
u8 *i = saa7113_init_regs;
if ((av7110->dev->pci->subsystem_vendor == 0x110a) && (av7110->dev->pci->subsystem_device == 0x0000)) {
av7110->analog_tuner_flags |= ANALOG_TUNER_VES1820;
} else if ((av7110->dev->pci->subsystem_vendor == 0x13c2) && (av7110->dev->pci->subsystem_device == 0x0002)) {
av7110->analog_tuner_flags |= ANALOG_TUNER_VES1820;
} else if ((av7110->dev->pci->subsystem_vendor == 0x13c2) && (av7110->dev->pci->subsystem_device == 0x000A)) {
av7110->analog_tuner_flags |= ANALOG_TUNER_STV0297;
}
if (av7110->analog_tuner_flags & ANALOG_TUNER_VES1820) {
if (ves1820_writereg(av7110->dev, 0x09, 0x0f, 0x20))
dprintk(1, "setting band in demodulator failed.\n");
} else if (av7110->analog_tuner_flags & ANALOG_TUNER_STV0297) {
saa7146_setgpio(av7110->dev, 1, SAA7146_GPIO_OUTLO);
saa7146_setgpio(av7110->dev, 3, SAA7146_GPIO_OUTLO);
}
while (*i != 0xff) {
if (i2c_writereg(av7110, 0x48, i[0], i[1]) != 1) {
dprintk(1, "saa7113 initialization failed @ card %d", av7110->dvb_adapter.num);
break;
}
i += 2;
}
msp_writereg(av7110, MSP_WR_DEM, 0x00bb, 0x02d0);
msp_writereg(av7110, MSP_WR_DEM, 0x0001, 3);
msp_writereg(av7110, MSP_WR_DEM, 0x0001, 18);
msp_writereg(av7110, MSP_WR_DEM, 0x0001, 27);
msp_writereg(av7110, MSP_WR_DEM, 0x0001, 48);
msp_writereg(av7110, MSP_WR_DEM, 0x0001, 66);
msp_writereg(av7110, MSP_WR_DEM, 0x0001, 72);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 4);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 64);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 0);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 3);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 18);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 27);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 48);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 66);
msp_writereg(av7110, MSP_WR_DEM, 0x0005, 72);
msp_writereg(av7110, MSP_WR_DEM, 0x0083, 0xa000);
msp_writereg(av7110, MSP_WR_DEM, 0x0093, 0x00aa);
msp_writereg(av7110, MSP_WR_DEM, 0x009b, 0x04fc);
msp_writereg(av7110, MSP_WR_DEM, 0x00a3, 0x038e);
msp_writereg(av7110, MSP_WR_DEM, 0x00ab, 0x04c6);
msp_writereg(av7110, MSP_WR_DEM, 0x0056, 0);
}
memcpy(standard, dvb_standard, sizeof(struct saa7146_standard) * 2);
saa7146_write(av7110->dev, DD1_STREAM_B, 0x00000000);
saa7146_write(av7110->dev, DD1_INIT, 0x03000700);
saa7146_write(av7110->dev, MC2, (MASK_09 | MASK_25 | MASK_10 | MASK_26));
return 0;
}
int av7110_init_v4l(struct av7110 *av7110)
{
struct saa7146_dev* dev = av7110->dev;
struct saa7146_ext_vv *vv_data;
int ret;
if (av7110->analog_tuner_flags)
vv_data = &av7110_vv_data_c;
else
vv_data = &av7110_vv_data_st;
ret = saa7146_vv_init(dev, vv_data);
if (ret) {
ERR(("cannot init capture device. skipping.\n"));
return -ENODEV;
}
vv_data->ops.vidioc_enum_input = vidioc_enum_input;
vv_data->ops.vidioc_g_input = vidioc_g_input;
vv_data->ops.vidioc_s_input = vidioc_s_input;
vv_data->ops.vidioc_g_tuner = vidioc_g_tuner;
vv_data->ops.vidioc_s_tuner = vidioc_s_tuner;
vv_data->ops.vidioc_g_frequency = vidioc_g_frequency;
vv_data->ops.vidioc_s_frequency = vidioc_s_frequency;
vv_data->ops.vidioc_g_audio = vidioc_g_audio;
vv_data->ops.vidioc_s_audio = vidioc_s_audio;
vv_data->ops.vidioc_g_sliced_vbi_cap = vidioc_g_sliced_vbi_cap;
vv_data->ops.vidioc_g_fmt_sliced_vbi_out = vidioc_g_fmt_sliced_vbi_out;
vv_data->ops.vidioc_s_fmt_sliced_vbi_out = vidioc_s_fmt_sliced_vbi_out;
if (saa7146_register_device(&av7110->v4l_dev, dev, "av7110", VFL_TYPE_GRABBER)) {
ERR(("cannot register capture device. skipping.\n"));
saa7146_vv_release(dev);
return -ENODEV;
}
if (saa7146_register_device(&av7110->vbi_dev, dev, "av7110", VFL_TYPE_VBI))
ERR(("cannot register vbi v4l2 device. skipping.\n"));
return 0;
}
int av7110_exit_v4l(struct av7110 *av7110)
{
struct saa7146_dev* dev = av7110->dev;
saa7146_unregister_device(&av7110->v4l_dev, av7110->dev);
saa7146_unregister_device(&av7110->vbi_dev, av7110->dev);
saa7146_vv_release(dev);
return 0;
}
static int std_callback(struct saa7146_dev* dev, struct saa7146_standard *std)
{
struct av7110 *av7110 = (struct av7110*) dev->ext_priv;
if (std->id & V4L2_STD_PAL) {
av7110->vidmode = AV7110_VIDEO_MODE_PAL;
av7110_set_vidmode(av7110, av7110->vidmode);
}
else if (std->id & V4L2_STD_NTSC) {
av7110->vidmode = AV7110_VIDEO_MODE_NTSC;
av7110_set_vidmode(av7110, av7110->vidmode);
}
else
return -1;
return 0;
}
