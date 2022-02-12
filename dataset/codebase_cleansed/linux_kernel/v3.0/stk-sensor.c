static int stk_sensor_outb(struct stk_camera *dev, u8 reg, u8 val)
{
int i = 0;
int tmpval = 0;
if (stk_camera_write_reg(dev, STK_IIC_TX_INDEX, reg))
return 1;
if (stk_camera_write_reg(dev, STK_IIC_TX_VALUE, val))
return 1;
if (stk_camera_write_reg(dev, STK_IIC_OP, STK_IIC_OP_TX))
return 1;
do {
if (stk_camera_read_reg(dev, STK_IIC_STAT, &tmpval))
return 1;
i++;
} while (tmpval == 0 && i < MAX_RETRIES);
if (tmpval != STK_IIC_STAT_TX_OK) {
if (tmpval)
STK_ERROR("stk_sensor_outb failed, status=0x%02x\n",
tmpval);
return 1;
} else
return 0;
}
static int stk_sensor_inb(struct stk_camera *dev, u8 reg, u8 *val)
{
int i = 0;
int tmpval = 0;
if (stk_camera_write_reg(dev, STK_IIC_RX_INDEX, reg))
return 1;
if (stk_camera_write_reg(dev, STK_IIC_OP, STK_IIC_OP_RX))
return 1;
do {
if (stk_camera_read_reg(dev, STK_IIC_STAT, &tmpval))
return 1;
i++;
} while (tmpval == 0 && i < MAX_RETRIES);
if (tmpval != STK_IIC_STAT_RX_OK) {
if (tmpval)
STK_ERROR("stk_sensor_inb failed, status=0x%02x\n",
tmpval);
return 1;
}
if (stk_camera_read_reg(dev, STK_IIC_RX_VALUE, &tmpval))
return 1;
*val = (u8) tmpval;
return 0;
}
static int stk_sensor_write_regvals(struct stk_camera *dev,
struct regval *rv)
{
int ret;
if (rv == NULL)
return 0;
while (rv->reg != 0xff || rv->val != 0xff) {
ret = stk_sensor_outb(dev, rv->reg, rv->val);
if (ret != 0)
return ret;
rv++;
}
return 0;
}
int stk_sensor_sleep(struct stk_camera *dev)
{
u8 tmp;
return stk_sensor_inb(dev, REG_COM2, &tmp)
|| stk_sensor_outb(dev, REG_COM2, tmp|COM2_SSLEEP);
}
int stk_sensor_wakeup(struct stk_camera *dev)
{
u8 tmp;
return stk_sensor_inb(dev, REG_COM2, &tmp)
|| stk_sensor_outb(dev, REG_COM2, tmp&~COM2_SSLEEP);
}
int stk_sensor_init(struct stk_camera *dev)
{
u8 idl = 0;
u8 idh = 0;
if (stk_camera_write_reg(dev, STK_IIC_ENABLE, STK_IIC_ENABLE_YES)
|| stk_camera_write_reg(dev, STK_IIC_ADDR, SENSOR_ADDRESS)
|| stk_sensor_outb(dev, REG_COM7, COM7_RESET)) {
STK_ERROR("Sensor resetting failed\n");
return -ENODEV;
}
msleep(10);
if (stk_sensor_inb(dev, REG_MIDH, &idh)
|| stk_sensor_inb(dev, REG_MIDL, &idl)) {
STK_ERROR("Strange error reading sensor ID\n");
return -ENODEV;
}
if (idh != 0x7f || idl != 0xa2) {
STK_ERROR("Huh? you don't have a sensor from ovt\n");
return -ENODEV;
}
if (stk_sensor_inb(dev, REG_PID, &idh)
|| stk_sensor_inb(dev, REG_VER, &idl)) {
STK_ERROR("Could not read sensor model\n");
return -ENODEV;
}
stk_sensor_write_regvals(dev, ov_initvals);
msleep(10);
STK_INFO("OmniVision sensor detected, id %02X%02X"
" at address %x\n", idh, idl, SENSOR_ADDRESS);
return 0;
}
static int stk_sensor_set_hw(struct stk_camera *dev,
int hstart, int hstop, int vstart, int vstop)
{
int ret;
unsigned char v;
ret = stk_sensor_outb(dev, REG_HSTART, (hstart >> 3) & 0xff);
ret += stk_sensor_outb(dev, REG_HSTOP, (hstop >> 3) & 0xff);
ret += stk_sensor_inb(dev, REG_HREF, &v);
v = (v & 0xc0) | ((hstop & 0x7) << 3) | (hstart & 0x7);
msleep(10);
ret += stk_sensor_outb(dev, REG_HREF, v);
ret += stk_sensor_outb(dev, REG_VSTART, (vstart >> 3) & 0xff);
ret += stk_sensor_outb(dev, REG_VSTOP, (vstop >> 3) & 0xff);
ret += stk_sensor_inb(dev, REG_VREF, &v);
v = (v & 0xc0) | ((vstop & 0x7) << 3) | (vstart & 0x7);
msleep(10);
ret += stk_sensor_outb(dev, REG_VREF, v);
return ret;
}
int stk_sensor_configure(struct stk_camera *dev)
{
int com7;
unsigned dummylines;
int flip;
struct regval *rv;
switch (dev->vsettings.mode) {
case MODE_QCIF: com7 = COM7_FMT_QCIF;
dummylines = 604;
break;
case MODE_QVGA: com7 = COM7_FMT_QVGA;
dummylines = 267;
break;
case MODE_CIF: com7 = COM7_FMT_CIF;
dummylines = 412;
break;
case MODE_VGA: com7 = COM7_FMT_VGA;
dummylines = 11;
break;
case MODE_SXGA: com7 = COM7_FMT_SXGA;
dummylines = 0;
break;
default: STK_ERROR("Unsupported mode %d\n", dev->vsettings.mode);
return -EFAULT;
}
switch (dev->vsettings.palette) {
case V4L2_PIX_FMT_UYVY:
com7 |= COM7_YUV;
rv = ov_fmt_uyvy;
break;
case V4L2_PIX_FMT_YUYV:
com7 |= COM7_YUV;
rv = ov_fmt_yuyv;
break;
case V4L2_PIX_FMT_RGB565:
com7 |= COM7_RGB;
rv = ov_fmt_rgbp;
break;
case V4L2_PIX_FMT_RGB565X:
com7 |= COM7_RGB;
rv = ov_fmt_rgbr;
break;
case V4L2_PIX_FMT_SBGGR8:
com7 |= COM7_PBAYER;
rv = ov_fmt_bayer;
break;
default: STK_ERROR("Unsupported colorspace\n");
return -EFAULT;
}
stk_sensor_outb(dev, REG_COM7, com7);
msleep(50);
stk_sensor_write_regvals(dev, rv);
flip = (dev->vsettings.vflip?MVFP_FLIP:0)
| (dev->vsettings.hflip?MVFP_MIRROR:0);
stk_sensor_outb(dev, REG_MVFP, flip);
if (dev->vsettings.palette == V4L2_PIX_FMT_SBGGR8
&& !dev->vsettings.vflip)
stk_sensor_outb(dev, REG_TSLB, 0x08);
stk_sensor_outb(dev, REG_ADVFH, dummylines >> 8);
stk_sensor_outb(dev, REG_ADVFL, dummylines & 0xff);
msleep(50);
switch (dev->vsettings.mode) {
case MODE_VGA:
if (stk_sensor_set_hw(dev, 302, 1582, 6, 486))
STK_ERROR("stk_sensor_set_hw failed (VGA)\n");
break;
case MODE_SXGA:
case MODE_CIF:
case MODE_QVGA:
case MODE_QCIF:
break;
}
msleep(10);
return 0;
}
int stk_sensor_set_brightness(struct stk_camera *dev, int br)
{
if (br < 0 || br > 0xff)
return -EINVAL;
stk_sensor_outb(dev, REG_AEB, max(0x00, br - 6));
stk_sensor_outb(dev, REG_AEW, min(0xff, br + 6));
return 0;
}
