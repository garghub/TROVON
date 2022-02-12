static int hexium_init_done(struct saa7146_dev *dev)
{
struct hexium *hexium = (struct hexium *) dev->ext_priv;
union i2c_smbus_data data;
int i = 0;
DEB_D("hexium_init_done called\n");
for (i = 0; i < sizeof(hexium_ks0127b); i++) {
data.byte = hexium_ks0127b[i];
if (0 != i2c_smbus_xfer(&hexium->i2c_adapter, 0x6c, 0, I2C_SMBUS_WRITE, i, I2C_SMBUS_BYTE_DATA, &data)) {
pr_err("hexium_init_done() failed for address 0x%02x\n",
i);
}
}
return 0;
}
static int hexium_set_input(struct hexium *hexium, int input)
{
union i2c_smbus_data data;
DEB_D("\n");
data.byte = hexium_input_select[input].byte;
if (0 != i2c_smbus_xfer(&hexium->i2c_adapter, 0x6c, 0, I2C_SMBUS_WRITE, hexium_input_select[input].adr, I2C_SMBUS_BYTE_DATA, &data)) {
return -1;
}
return 0;
}
static int hexium_set_standard(struct hexium *hexium, struct hexium_data *vdec)
{
union i2c_smbus_data data;
int i = 0;
DEB_D("\n");
while (vdec[i].adr != -1) {
data.byte = vdec[i].byte;
if (0 != i2c_smbus_xfer(&hexium->i2c_adapter, 0x6c, 0, I2C_SMBUS_WRITE, vdec[i].adr, I2C_SMBUS_BYTE_DATA, &data)) {
pr_err("hexium_init_done: hexium_set_standard() failed for address 0x%02x\n",
i);
return -1;
}
i++;
}
return 0;
}
static int vidioc_enum_input(struct file *file, void *fh, struct v4l2_input *i)
{
DEB_EE("VIDIOC_ENUMINPUT %d\n", i->index);
if (i->index >= HEXIUM_INPUTS)
return -EINVAL;
memcpy(i, &hexium_inputs[i->index], sizeof(struct v4l2_input));
DEB_D("v4l2_ioctl: VIDIOC_ENUMINPUT %d\n", i->index);
return 0;
}
static int vidioc_g_input(struct file *file, void *fh, unsigned int *input)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct hexium *hexium = (struct hexium *) dev->ext_priv;
*input = hexium->cur_input;
DEB_D("VIDIOC_G_INPUT: %d\n", *input);
return 0;
}
static int vidioc_s_input(struct file *file, void *fh, unsigned int input)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct hexium *hexium = (struct hexium *) dev->ext_priv;
DEB_EE("VIDIOC_S_INPUT %d\n", input);
if (input >= HEXIUM_INPUTS)
return -EINVAL;
hexium->cur_input = input;
hexium_set_input(hexium, input);
return 0;
}
static int vidioc_queryctrl(struct file *file, void *fh, struct v4l2_queryctrl *qc)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
int i;
for (i = HEXIUM_CONTROLS - 1; i >= 0; i--) {
if (hexium_controls[i].id == qc->id) {
*qc = hexium_controls[i];
DEB_D("VIDIOC_QUERYCTRL %d\n", qc->id);
return 0;
}
}
return dev->ext_vv_data->core_ops->vidioc_queryctrl(file, fh, qc);
}
static int vidioc_g_ctrl(struct file *file, void *fh, struct v4l2_control *vc)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct hexium *hexium = (struct hexium *) dev->ext_priv;
int i;
for (i = HEXIUM_CONTROLS - 1; i >= 0; i--) {
if (hexium_controls[i].id == vc->id)
break;
}
if (i < 0)
return dev->ext_vv_data->core_ops->vidioc_g_ctrl(file, fh, vc);
if (vc->id == V4L2_CID_PRIVATE_BASE) {
vc->value = hexium->cur_bw;
DEB_D("VIDIOC_G_CTRL BW:%d\n", vc->value);
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *fh, struct v4l2_control *vc)
{
struct saa7146_dev *dev = ((struct saa7146_fh *)fh)->dev;
struct hexium *hexium = (struct hexium *) dev->ext_priv;
int i = 0;
for (i = HEXIUM_CONTROLS - 1; i >= 0; i--) {
if (hexium_controls[i].id == vc->id)
break;
}
if (i < 0)
return dev->ext_vv_data->core_ops->vidioc_s_ctrl(file, fh, vc);
if (vc->id == V4L2_CID_PRIVATE_BASE)
hexium->cur_bw = vc->value;
DEB_D("VIDIOC_S_CTRL BW:%d\n", hexium->cur_bw);
if (0 == hexium->cur_bw && V4L2_STD_PAL == hexium->cur_std) {
hexium_set_standard(hexium, hexium_pal);
return 0;
}
if (0 == hexium->cur_bw && V4L2_STD_NTSC == hexium->cur_std) {
hexium_set_standard(hexium, hexium_ntsc);
return 0;
}
if (0 == hexium->cur_bw && V4L2_STD_SECAM == hexium->cur_std) {
hexium_set_standard(hexium, hexium_secam);
return 0;
}
if (1 == hexium->cur_bw && V4L2_STD_PAL == hexium->cur_std) {
hexium_set_standard(hexium, hexium_pal_bw);
return 0;
}
if (1 == hexium->cur_bw && V4L2_STD_NTSC == hexium->cur_std) {
hexium_set_standard(hexium, hexium_ntsc_bw);
return 0;
}
if (1 == hexium->cur_bw && V4L2_STD_SECAM == hexium->cur_std)
return -EINVAL;
return -EINVAL;
}
static int hexium_attach(struct saa7146_dev *dev, struct saa7146_pci_extension_data *info)
{
struct hexium *hexium;
int ret;
DEB_EE("\n");
hexium = kzalloc(sizeof(struct hexium), GFP_KERNEL);
if (NULL == hexium) {
pr_err("not enough kernel memory in hexium_attach()\n");
return -ENOMEM;
}
dev->ext_priv = hexium;
saa7146_write(dev, MC1, (MASK_08 | MASK_24 | MASK_10 | MASK_26));
hexium->i2c_adapter = (struct i2c_adapter) {
.name = "hexium gemini",
};
saa7146_i2c_adapter_prepare(dev, &hexium->i2c_adapter, SAA7146_I2C_BUS_BIT_RATE_480);
if (i2c_add_adapter(&hexium->i2c_adapter) < 0) {
DEB_S("cannot register i2c-device. skipping.\n");
kfree(hexium);
return -EFAULT;
}
saa7146_setgpio(dev, 2, SAA7146_GPIO_OUTHI);
saa7146_write(dev, DD1_INIT, 0x07000700);
saa7146_write(dev, DD1_STREAM_B, 0x00000000);
saa7146_write(dev, MC2, (MASK_09 | MASK_25 | MASK_10 | MASK_26));
hexium->cur_input = 0;
hexium_init_done(dev);
hexium_set_standard(hexium, hexium_pal);
hexium->cur_std = V4L2_STD_PAL;
hexium_set_input(hexium, 0);
hexium->cur_input = 0;
saa7146_vv_init(dev, &vv_data);
vv_data.ops.vidioc_queryctrl = vidioc_queryctrl;
vv_data.ops.vidioc_g_ctrl = vidioc_g_ctrl;
vv_data.ops.vidioc_s_ctrl = vidioc_s_ctrl;
vv_data.ops.vidioc_enum_input = vidioc_enum_input;
vv_data.ops.vidioc_g_input = vidioc_g_input;
vv_data.ops.vidioc_s_input = vidioc_s_input;
ret = saa7146_register_device(&hexium->video_dev, dev, "hexium gemini", VFL_TYPE_GRABBER);
if (ret < 0) {
pr_err("cannot register capture v4l2 device. skipping.\n");
return ret;
}
pr_info("found 'hexium gemini' frame grabber-%d\n", hexium_num);
hexium_num++;
return 0;
}
static int hexium_detach(struct saa7146_dev *dev)
{
struct hexium *hexium = (struct hexium *) dev->ext_priv;
DEB_EE("dev:%p\n", dev);
saa7146_unregister_device(&hexium->video_dev, dev);
saa7146_vv_release(dev);
hexium_num--;
i2c_del_adapter(&hexium->i2c_adapter);
kfree(hexium);
return 0;
}
static int std_callback(struct saa7146_dev *dev, struct saa7146_standard *std)
{
struct hexium *hexium = (struct hexium *) dev->ext_priv;
if (V4L2_STD_PAL == std->id) {
hexium_set_standard(hexium, hexium_pal);
hexium->cur_std = V4L2_STD_PAL;
return 0;
} else if (V4L2_STD_NTSC == std->id) {
hexium_set_standard(hexium, hexium_ntsc);
hexium->cur_std = V4L2_STD_NTSC;
return 0;
} else if (V4L2_STD_SECAM == std->id) {
hexium_set_standard(hexium, hexium_secam);
hexium->cur_std = V4L2_STD_SECAM;
return 0;
}
return -1;
}
static int __init hexium_init_module(void)
{
if (0 != saa7146_register_extension(&hexium_extension)) {
DEB_S("failed to register extension\n");
return -ENODEV;
}
return 0;
}
static void __exit hexium_cleanup_module(void)
{
saa7146_unregister_extension(&hexium_extension);
}
