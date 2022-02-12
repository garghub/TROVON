static int hexium_probe(struct saa7146_dev *dev)
{
struct hexium *hexium = NULL;
union i2c_smbus_data data;
int err = 0;
DEB_EE("\n");
if (0 == dev->revision) {
return -EFAULT;
}
hexium = kzalloc(sizeof(struct hexium), GFP_KERNEL);
if (NULL == hexium) {
pr_err("hexium_probe: not enough kernel memory\n");
return -ENOMEM;
}
saa7146_write(dev, MC1, (MASK_08 | MASK_24 | MASK_10 | MASK_26));
saa7146_write(dev, DD1_INIT, 0x01000100);
saa7146_write(dev, DD1_STREAM_B, 0x00000000);
saa7146_write(dev, MC2, (MASK_09 | MASK_25 | MASK_10 | MASK_26));
hexium->i2c_adapter = (struct i2c_adapter) {
.name = "hexium orion",
};
saa7146_i2c_adapter_prepare(dev, &hexium->i2c_adapter, SAA7146_I2C_BUS_BIT_RATE_480);
if (i2c_add_adapter(&hexium->i2c_adapter) < 0) {
DEB_S("cannot register i2c-device. skipping.\n");
kfree(hexium);
return -EFAULT;
}
saa7146_setgpio(dev, 0, SAA7146_GPIO_OUTHI);
saa7146_setgpio(dev, 2, SAA7146_GPIO_OUTHI);
mdelay(10);
if (0x17c8 == dev->pci->subsystem_vendor && 0x0101 == dev->pci->subsystem_device) {
pr_info("device is a Hexium Orion w/ 1 SVHS + 3 BNC inputs\n");
dev->ext_priv = hexium;
hexium->type = HEXIUM_ORION_1SVHS_3BNC;
return 0;
}
if (0x17c8 == dev->pci->subsystem_vendor && 0x2101 == dev->pci->subsystem_device) {
pr_info("device is a Hexium Orion w/ 4 BNC inputs\n");
dev->ext_priv = hexium;
hexium->type = HEXIUM_ORION_4BNC;
return 0;
}
if (0 == (err = i2c_smbus_xfer(&hexium->i2c_adapter, 0x4e, 0, I2C_SMBUS_READ, 0x00, I2C_SMBUS_BYTE_DATA, &data))) {
pr_info("device is a Hexium HV-PCI6/Orion (old)\n");
dev->ext_priv = hexium;
hexium->type = HEXIUM_HV_PCI6_ORION;
return 0;
}
i2c_del_adapter(&hexium->i2c_adapter);
kfree(hexium);
return -EFAULT;
}
static int hexium_init_done(struct saa7146_dev *dev)
{
struct hexium *hexium = (struct hexium *) dev->ext_priv;
union i2c_smbus_data data;
int i = 0;
DEB_D("hexium_init_done called\n");
for (i = 0; i < sizeof(hexium_saa7110); i++) {
data.byte = hexium_saa7110[i];
if (0 != i2c_smbus_xfer(&hexium->i2c_adapter, 0x4e, 0, I2C_SMBUS_WRITE, i, I2C_SMBUS_BYTE_DATA, &data)) {
pr_err("failed for address 0x%02x\n", i);
}
}
return 0;
}
static int hexium_set_input(struct hexium *hexium, int input)
{
union i2c_smbus_data data;
int i = 0;
DEB_D("\n");
for (i = 0; i < 8; i++) {
int adr = hexium_input_select[input].data[i].adr;
data.byte = hexium_input_select[input].data[i].byte;
if (0 != i2c_smbus_xfer(&hexium->i2c_adapter, 0x4e, 0, I2C_SMBUS_WRITE, adr, I2C_SMBUS_BYTE_DATA, &data)) {
return -1;
}
pr_debug("%d: 0x%02x => 0x%02x\n", input, adr, data.byte);
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
if (input >= HEXIUM_INPUTS)
return -EINVAL;
hexium->cur_input = input;
hexium_set_input(hexium, input);
return 0;
}
static int hexium_attach(struct saa7146_dev *dev, struct saa7146_pci_extension_data *info)
{
struct hexium *hexium = (struct hexium *) dev->ext_priv;
DEB_EE("\n");
saa7146_vv_init(dev, &vv_data);
vv_data.ops.vidioc_enum_input = vidioc_enum_input;
vv_data.ops.vidioc_g_input = vidioc_g_input;
vv_data.ops.vidioc_s_input = vidioc_s_input;
if (0 != saa7146_register_device(&hexium->video_dev, dev, "hexium orion", VFL_TYPE_GRABBER)) {
pr_err("cannot register capture v4l2 device. skipping.\n");
return -1;
}
pr_err("found 'hexium orion' frame grabber-%d\n", hexium_num);
hexium_num++;
hexium->cur_input = 0;
hexium_init_done(dev);
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
return 0;
}
static int __init hexium_init_module(void)
{
if (0 != saa7146_register_extension(&extension)) {
DEB_S("failed to register extension\n");
return -ENODEV;
}
return 0;
}
static void __exit hexium_cleanup_module(void)
{
saa7146_unregister_extension(&extension);
}
