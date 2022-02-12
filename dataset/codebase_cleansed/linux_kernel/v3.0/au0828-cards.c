void hvr950q_cs5340_audio(void *priv, int enable)
{
struct au0828_dev *dev = priv;
if (enable == 1)
au0828_set(dev, REG_000, 0x10);
else
au0828_clear(dev, REG_000, 0x10);
}
int au0828_tuner_callback(void *priv, int component, int command, int arg)
{
struct au0828_dev *dev = priv;
dprintk(1, "%s()\n", __func__);
switch (dev->boardnr) {
case AU0828_BOARD_HAUPPAUGE_HVR850:
case AU0828_BOARD_HAUPPAUGE_HVR950Q:
case AU0828_BOARD_HAUPPAUGE_HVR950Q_MXL:
case AU0828_BOARD_DVICO_FUSIONHDTV7:
if (command == 0) {
au0828_clear(dev, REG_001, 2);
mdelay(10);
au0828_set(dev, REG_001, 2);
mdelay(10);
return 0;
} else {
printk(KERN_ERR
"%s(): Unknown command.\n", __func__);
return -EINVAL;
}
break;
}
return 0;
}
static void hauppauge_eeprom(struct au0828_dev *dev, u8 *eeprom_data)
{
struct tveeprom tv;
tveeprom_hauppauge_analog(&dev->i2c_client, &tv, eeprom_data);
dev->board.tuner_type = tv.tuner_type;
switch (tv.model) {
case 72000:
case 72001:
case 72211:
case 72221:
case 72231:
case 72241:
case 72251:
case 72301:
case 72500:
break;
default:
printk(KERN_WARNING "%s: warning: "
"unknown hauppauge model #%d\n", __func__, tv.model);
break;
}
printk(KERN_INFO "%s: hauppauge eeprom: model=%d\n",
__func__, tv.model);
}
void au0828_card_setup(struct au0828_dev *dev)
{
static u8 eeprom[256];
struct tuner_setup tun_setup;
struct v4l2_subdev *sd;
unsigned int mode_mask = T_ANALOG_TV;
dprintk(1, "%s()\n", __func__);
memcpy(&dev->board, &au0828_boards[dev->boardnr], sizeof(dev->board));
if (dev->i2c_rc == 0) {
dev->i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_client, eeprom, sizeof(eeprom));
}
switch (dev->boardnr) {
case AU0828_BOARD_HAUPPAUGE_HVR850:
case AU0828_BOARD_HAUPPAUGE_HVR950Q:
case AU0828_BOARD_HAUPPAUGE_HVR950Q_MXL:
case AU0828_BOARD_HAUPPAUGE_WOODBURY:
if (dev->i2c_rc == 0)
hauppauge_eeprom(dev, eeprom+0xa0);
break;
}
if (AUVI_INPUT(0).type != AU0828_VMUX_UNDEFINED) {
sd = v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"au8522", 0x8e >> 1, NULL);
if (sd == NULL)
printk(KERN_ERR "analog subdev registration failed\n");
}
if (dev->board.tuner_type != TUNER_ABSENT) {
sd = v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"tuner", dev->board.tuner_addr, NULL);
if (sd == NULL)
printk(KERN_ERR "tuner subdev registration fail\n");
tun_setup.mode_mask = mode_mask;
tun_setup.type = dev->board.tuner_type;
tun_setup.addr = dev->board.tuner_addr;
tun_setup.tuner_callback = au0828_tuner_callback;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_type_addr,
&tun_setup);
}
}
void au0828_gpio_setup(struct au0828_dev *dev)
{
dprintk(1, "%s()\n", __func__);
switch (dev->boardnr) {
case AU0828_BOARD_HAUPPAUGE_HVR850:
case AU0828_BOARD_HAUPPAUGE_HVR950Q:
case AU0828_BOARD_HAUPPAUGE_HVR950Q_MXL:
case AU0828_BOARD_HAUPPAUGE_WOODBURY:
au0828_write(dev, REG_003, 0x02);
au0828_write(dev, REG_002, 0x80 | 0x20 | 0x10);
au0828_write(dev, REG_001, 0x0);
au0828_write(dev, REG_000, 0x0);
msleep(100);
au0828_write(dev, REG_003, 0x02);
au0828_write(dev, REG_001, 0x02);
au0828_write(dev, REG_002, 0x80 | 0x20 | 0x10);
au0828_write(dev, REG_000, 0x80 | 0x40 | 0x20);
msleep(250);
break;
case AU0828_BOARD_DVICO_FUSIONHDTV7:
au0828_write(dev, REG_003, 0x02);
au0828_write(dev, REG_002, 0xa0);
au0828_write(dev, REG_001, 0x0);
au0828_write(dev, REG_000, 0x0);
msleep(100);
au0828_write(dev, REG_003, 0x02);
au0828_write(dev, REG_002, 0xa0);
au0828_write(dev, REG_001, 0x02);
au0828_write(dev, REG_000, 0xa0);
msleep(250);
break;
}
}
