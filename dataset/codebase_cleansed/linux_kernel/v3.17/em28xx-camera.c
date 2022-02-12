static int em28xx_initialize_mt9m111(struct em28xx *dev)
{
int i;
unsigned char regs[][3] = {
{ 0x0d, 0x00, 0x01, },
{ 0x0d, 0x00, 0x00, },
{ 0x0a, 0x00, 0x21, },
{ 0x21, 0x04, 0x00, },
};
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client[dev->def_i2c_bus],
&regs[i][0], 3);
return 0;
}
static int em28xx_initialize_mt9m001(struct em28xx *dev)
{
int i;
unsigned char regs[][3] = {
{ 0x0d, 0x00, 0x01, },
{ 0x0d, 0x00, 0x00, },
{ 0x04, 0x05, 0x00, },
{ 0x03, 0x04, 0x00, },
{ 0x20, 0x11, 0x00, },
{ 0x06, 0x00, 0x10, },
{ 0x2b, 0x00, 0x24, },
{ 0x2e, 0x00, 0x24, },
{ 0x35, 0x00, 0x24, },
{ 0x2d, 0x00, 0x20, },
{ 0x2c, 0x00, 0x20, },
{ 0x09, 0x0a, 0xd4, },
{ 0x35, 0x00, 0x57, },
};
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client[dev->def_i2c_bus],
&regs[i][0], 3);
return 0;
}
static int em28xx_probe_sensor_micron(struct em28xx *dev)
{
int ret, i;
char *name;
u8 reg;
__be16 id_be;
u16 id;
struct i2c_client client = dev->i2c_client[dev->def_i2c_bus];
dev->em28xx_sensor = EM28XX_NOSENSOR;
for (i = 0; micron_sensor_addrs[i] != I2C_CLIENT_END; i++) {
client.addr = micron_sensor_addrs[i];
reg = 0x00;
ret = i2c_master_send(&client, &reg, 1);
if (ret < 0) {
if (ret != -ENXIO)
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
ret = i2c_master_recv(&client, (u8 *)&id_be, 2);
if (ret < 0) {
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
id = be16_to_cpu(id_be);
reg = 0xff;
ret = i2c_master_send(&client, &reg, 1);
if (ret < 0) {
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
ret = i2c_master_recv(&client, (u8 *)&id_be, 2);
if (ret < 0) {
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
if (id != be16_to_cpu(id_be))
continue;
id = be16_to_cpu(id_be);
switch (id) {
case 0x1222:
name = "MT9V012";
break;
case 0x1229:
name = "MT9V112";
break;
case 0x1433:
name = "MT9M011";
break;
case 0x143a:
name = "MT9M111";
dev->em28xx_sensor = EM28XX_MT9M111;
break;
case 0x148c:
name = "MT9M112";
break;
case 0x1511:
name = "MT9D011";
break;
case 0x8232:
case 0x8243:
name = "MT9V011";
dev->em28xx_sensor = EM28XX_MT9V011;
break;
case 0x8431:
name = "MT9M001";
dev->em28xx_sensor = EM28XX_MT9M001;
break;
default:
em28xx_info("unknown Micron sensor detected: 0x%04x\n",
id);
return 0;
}
if (dev->em28xx_sensor == EM28XX_NOSENSOR)
em28xx_info("unsupported sensor detected: %s\n", name);
else
em28xx_info("sensor %s detected\n", name);
dev->i2c_client[dev->def_i2c_bus].addr = client.addr;
return 0;
}
return -ENODEV;
}
static int em28xx_probe_sensor_omnivision(struct em28xx *dev)
{
int ret, i;
char *name;
u8 reg;
u16 id;
struct i2c_client client = dev->i2c_client[dev->def_i2c_bus];
dev->em28xx_sensor = EM28XX_NOSENSOR;
for (i = 0; omnivision_sensor_addrs[i] != I2C_CLIENT_END; i++) {
client.addr = omnivision_sensor_addrs[i];
reg = 0x1c;
ret = i2c_smbus_read_byte_data(&client, reg);
if (ret < 0) {
if (ret != -ENXIO)
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
id = ret << 8;
reg = 0x1d;
ret = i2c_smbus_read_byte_data(&client, reg);
if (ret < 0) {
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
id += ret;
if (id != 0x7fa2)
continue;
reg = 0x0a;
ret = i2c_smbus_read_byte_data(&client, reg);
if (ret < 0) {
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
id = ret << 8;
reg = 0x0b;
ret = i2c_smbus_read_byte_data(&client, reg);
if (ret < 0) {
em28xx_errdev("couldn't read from i2c device 0x%02x: error %i\n",
client.addr << 1, ret);
continue;
}
id += ret;
switch (id) {
case 0x2642:
name = "OV2640";
dev->em28xx_sensor = EM28XX_OV2640;
break;
case 0x7648:
name = "OV7648";
break;
case 0x7660:
name = "OV7660";
break;
case 0x7673:
name = "OV7670";
break;
case 0x7720:
name = "OV7720";
break;
case 0x7721:
name = "OV7725";
break;
case 0x9648:
case 0x9649:
name = "OV9640";
break;
case 0x9650:
case 0x9652:
name = "OV9650";
break;
case 0x9656:
case 0x9657:
name = "OV9655";
break;
default:
em28xx_info("unknown OmniVision sensor detected: 0x%04x\n",
id);
return 0;
}
if (dev->em28xx_sensor == EM28XX_NOSENSOR)
em28xx_info("unsupported sensor detected: %s\n", name);
else
em28xx_info("sensor %s detected\n", name);
dev->i2c_client[dev->def_i2c_bus].addr = client.addr;
return 0;
}
return -ENODEV;
}
int em28xx_detect_sensor(struct em28xx *dev)
{
int ret;
ret = em28xx_probe_sensor_micron(dev);
if (dev->em28xx_sensor == EM28XX_NOSENSOR && ret < 0)
ret = em28xx_probe_sensor_omnivision(dev);
if (dev->em28xx_sensor == EM28XX_NOSENSOR && ret < 0) {
em28xx_info("No sensor detected\n");
return -ENODEV;
}
return 0;
}
int em28xx_init_camera(struct em28xx *dev)
{
char clk_name[V4L2_SUBDEV_NAME_SIZE];
struct i2c_client *client = &dev->i2c_client[dev->def_i2c_bus];
struct i2c_adapter *adap = &dev->i2c_adap[dev->def_i2c_bus];
struct em28xx_v4l2 *v4l2 = dev->v4l2;
int ret = 0;
v4l2_clk_name_i2c(clk_name, sizeof(clk_name),
i2c_adapter_id(adap), client->addr);
v4l2->clk = v4l2_clk_register_fixed(clk_name, "mclk", -EINVAL);
if (IS_ERR(v4l2->clk))
return PTR_ERR(v4l2->clk);
switch (dev->em28xx_sensor) {
case EM28XX_MT9V011:
{
struct mt9v011_platform_data pdata;
struct i2c_board_info mt9v011_info = {
.type = "mt9v011",
.addr = client->addr,
.platform_data = &pdata,
};
v4l2->sensor_xres = 640;
v4l2->sensor_yres = 480;
dev->board.xclk = EM28XX_XCLK_FREQUENCY_4_3MHZ;
em28xx_write_reg(dev, EM28XX_R0F_XCLK, dev->board.xclk);
v4l2->sensor_xtal = 4300000;
pdata.xtal = v4l2->sensor_xtal;
if (NULL ==
v4l2_i2c_new_subdev_board(&v4l2->v4l2_dev, adap,
&mt9v011_info, NULL)) {
ret = -ENODEV;
break;
}
v4l2->vinmode = 0x0d;
v4l2->vinctl = 0x00;
break;
}
case EM28XX_MT9M001:
v4l2->sensor_xres = 1280;
v4l2->sensor_yres = 1024;
em28xx_initialize_mt9m001(dev);
v4l2->vinmode = 0x0c;
v4l2->vinctl = 0x00;
break;
case EM28XX_MT9M111:
v4l2->sensor_xres = 640;
v4l2->sensor_yres = 512;
dev->board.xclk = EM28XX_XCLK_FREQUENCY_48MHZ;
em28xx_write_reg(dev, EM28XX_R0F_XCLK, dev->board.xclk);
em28xx_initialize_mt9m111(dev);
v4l2->vinmode = 0x0a;
v4l2->vinctl = 0x00;
break;
case EM28XX_OV2640:
{
struct v4l2_subdev *subdev;
struct i2c_board_info ov2640_info = {
.type = "ov2640",
.flags = I2C_CLIENT_SCCB,
.addr = client->addr,
.platform_data = &camlink,
};
struct v4l2_mbus_framefmt fmt;
v4l2->sensor_xres = 640;
v4l2->sensor_yres = 480;
subdev =
v4l2_i2c_new_subdev_board(&v4l2->v4l2_dev, adap,
&ov2640_info, NULL);
if (NULL == subdev) {
ret = -ENODEV;
break;
}
fmt.code = V4L2_MBUS_FMT_YUYV8_2X8;
fmt.width = 640;
fmt.height = 480;
v4l2_subdev_call(subdev, video, s_mbus_fmt, &fmt);
dev->board.xclk = EM28XX_XCLK_FREQUENCY_24MHZ;
em28xx_write_reg(dev, EM28XX_R0F_XCLK, dev->board.xclk);
v4l2->vinmode = 0x08;
v4l2->vinctl = 0x00;
break;
}
case EM28XX_NOSENSOR:
default:
ret = -EINVAL;
}
if (ret < 0) {
v4l2_clk_unregister_fixed(v4l2->clk);
v4l2->clk = NULL;
}
return ret;
}
