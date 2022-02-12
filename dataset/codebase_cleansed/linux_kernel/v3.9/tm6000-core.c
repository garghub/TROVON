int tm6000_read_write_usb(struct tm6000_core *dev, u8 req_type, u8 req,
u16 value, u16 index, u8 *buf, u16 len)
{
int ret, i;
unsigned int pipe;
u8 *data = NULL;
int delay = 5000;
if (len) {
data = kzalloc(len, GFP_KERNEL);
if (!data)
return -ENOMEM;
}
mutex_lock(&dev->usb_lock);
if (req_type & USB_DIR_IN)
pipe = usb_rcvctrlpipe(dev->udev, 0);
else {
pipe = usb_sndctrlpipe(dev->udev, 0);
memcpy(data, buf, len);
}
if (tm6000_debug & V4L2_DEBUG_I2C) {
printk(KERN_DEBUG "(dev %p, pipe %08x): ", dev->udev, pipe);
printk(KERN_CONT "%s: %02x %02x %02x %02x %02x %02x %02x %02x ",
(req_type & USB_DIR_IN) ? " IN" : "OUT",
req_type, req, value&0xff, value>>8, index&0xff,
index>>8, len&0xff, len>>8);
if (!(req_type & USB_DIR_IN)) {
printk(KERN_CONT ">>> ");
for (i = 0; i < len; i++)
printk(KERN_CONT " %02x", buf[i]);
printk(KERN_CONT "\n");
}
}
ret = usb_control_msg(dev->udev, pipe, req, req_type, value, index,
data, len, USB_TIMEOUT);
if (req_type & USB_DIR_IN)
memcpy(buf, data, len);
if (tm6000_debug & V4L2_DEBUG_I2C) {
if (ret < 0) {
if (req_type & USB_DIR_IN)
printk(KERN_DEBUG "<<< (len=%d)\n", len);
printk(KERN_CONT "%s: Error #%d\n", __func__, ret);
} else if (req_type & USB_DIR_IN) {
printk(KERN_CONT "<<< ");
for (i = 0; i < len; i++)
printk(KERN_CONT " %02x", buf[i]);
printk(KERN_CONT "\n");
}
}
kfree(data);
if (dev->quirks & TM6000_QUIRK_NO_USB_DELAY)
delay = 0;
if (req == REQ_16_SET_GET_I2C_WR1_RDN && !(req_type & USB_DIR_IN)) {
unsigned int tsleep;
tsleep = (len * 200) + 200;
if (tsleep < delay)
tsleep = delay;
usleep_range(tsleep, tsleep + 1000);
}
else if (delay)
usleep_range(delay, delay + 1000);
mutex_unlock(&dev->usb_lock);
return ret;
}
int tm6000_set_reg(struct tm6000_core *dev, u8 req, u16 value, u16 index)
{
return
tm6000_read_write_usb(dev, USB_DIR_OUT | USB_TYPE_VENDOR,
req, value, index, NULL, 0);
}
int tm6000_get_reg(struct tm6000_core *dev, u8 req, u16 value, u16 index)
{
int rc;
u8 buf[1];
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR, req,
value, index, buf, 1);
if (rc < 0)
return rc;
return *buf;
}
int tm6000_set_reg_mask(struct tm6000_core *dev, u8 req, u16 value,
u16 index, u16 mask)
{
int rc;
u8 buf[1];
u8 new_index;
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR, req,
value, 0, buf, 1);
if (rc < 0)
return rc;
new_index = (buf[0] & ~mask) | (index & mask);
if (new_index == buf[0])
return 0;
return tm6000_read_write_usb(dev, USB_DIR_OUT | USB_TYPE_VENDOR,
req, value, new_index, NULL, 0);
}
int tm6000_get_reg16(struct tm6000_core *dev, u8 req, u16 value, u16 index)
{
int rc;
u8 buf[2];
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR, req,
value, index, buf, 2);
if (rc < 0)
return rc;
return buf[1]|buf[0]<<8;
}
int tm6000_get_reg32(struct tm6000_core *dev, u8 req, u16 value, u16 index)
{
int rc;
u8 buf[4];
rc = tm6000_read_write_usb(dev, USB_DIR_IN | USB_TYPE_VENDOR, req,
value, index, buf, 4);
if (rc < 0)
return rc;
return buf[3] | buf[2] << 8 | buf[1] << 16 | buf[0] << 24;
}
int tm6000_i2c_reset(struct tm6000_core *dev, u16 tsleep)
{
int rc;
rc = tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, TM6000_GPIO_CLK, 0);
if (rc < 0)
return rc;
msleep(tsleep);
rc = tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, TM6000_GPIO_CLK, 1);
msleep(tsleep);
return rc;
}
void tm6000_set_fourcc_format(struct tm6000_core *dev)
{
if (dev->dev_type == TM6010) {
int val;
val = tm6000_get_reg(dev, TM6010_REQ07_RCC_ACTIVE_IF, 0) & 0xfc;
if (dev->fourcc == V4L2_PIX_FMT_UYVY)
tm6000_set_reg(dev, TM6010_REQ07_RCC_ACTIVE_IF, val);
else
tm6000_set_reg(dev, TM6010_REQ07_RCC_ACTIVE_IF, val | 1);
} else {
if (dev->fourcc == V4L2_PIX_FMT_UYVY)
tm6000_set_reg(dev, TM6010_REQ07_RC1_TRESHOLD, 0xd0);
else
tm6000_set_reg(dev, TM6010_REQ07_RC1_TRESHOLD, 0x90);
}
}
static void tm6000_set_vbi(struct tm6000_core *dev)
{
if (dev->dev_type == TM6010) {
tm6000_set_reg(dev, TM6010_REQ07_R3F_RESET, 0x01);
tm6000_set_reg(dev, TM6010_REQ07_R41_TELETEXT_VBI_CODE1, 0x27);
tm6000_set_reg(dev, TM6010_REQ07_R42_VBI_DATA_HIGH_LEVEL, 0x55);
tm6000_set_reg(dev, TM6010_REQ07_R43_VBI_DATA_TYPE_LINE7, 0x66);
tm6000_set_reg(dev, TM6010_REQ07_R44_VBI_DATA_TYPE_LINE8, 0x66);
tm6000_set_reg(dev, TM6010_REQ07_R45_VBI_DATA_TYPE_LINE9, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R46_VBI_DATA_TYPE_LINE10, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R47_VBI_DATA_TYPE_LINE11, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R48_VBI_DATA_TYPE_LINE12, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R49_VBI_DATA_TYPE_LINE13, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R4A_VBI_DATA_TYPE_LINE14, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R4B_VBI_DATA_TYPE_LINE15, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R4C_VBI_DATA_TYPE_LINE16, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R4D_VBI_DATA_TYPE_LINE17, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R4E_VBI_DATA_TYPE_LINE18, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R4F_VBI_DATA_TYPE_LINE19, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R50_VBI_DATA_TYPE_LINE20, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R51_VBI_DATA_TYPE_LINE21, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R52_VBI_DATA_TYPE_LINE22, 0x66);
tm6000_set_reg(dev,
TM6010_REQ07_R53_VBI_DATA_TYPE_LINE23, 0x00);
tm6000_set_reg(dev,
TM6010_REQ07_R54_VBI_DATA_TYPE_RLINES, 0x00);
tm6000_set_reg(dev,
TM6010_REQ07_R55_VBI_LOOP_FILTER_GAIN, 0x01);
tm6000_set_reg(dev,
TM6010_REQ07_R56_VBI_LOOP_FILTER_I_GAIN, 0x00);
tm6000_set_reg(dev,
TM6010_REQ07_R57_VBI_LOOP_FILTER_P_GAIN, 0x02);
tm6000_set_reg(dev, TM6010_REQ07_R58_VBI_CAPTION_DTO1, 0x35);
tm6000_set_reg(dev, TM6010_REQ07_R59_VBI_CAPTION_DTO0, 0xa0);
tm6000_set_reg(dev, TM6010_REQ07_R5A_VBI_TELETEXT_DTO1, 0x11);
tm6000_set_reg(dev, TM6010_REQ07_R5B_VBI_TELETEXT_DTO0, 0x4c);
tm6000_set_reg(dev, TM6010_REQ07_R40_TELETEXT_VBI_CODE0, 0x01);
tm6000_set_reg(dev, TM6010_REQ07_R3F_RESET, 0x00);
}
}
int tm6000_init_analog_mode(struct tm6000_core *dev)
{
struct v4l2_frequency f;
if (dev->dev_type == TM6010) {
u8 active = TM6010_REQ07_RCC_ACTIVE_IF_AUDIO_ENABLE;
if (!dev->radio)
active |= TM6010_REQ07_RCC_ACTIVE_IF_VIDEO_ENABLE;
tm6000_set_reg_mask(dev, TM6010_REQ07_RCC_ACTIVE_IF,
active, 0x60);
tm6000_set_reg_mask(dev, TM6010_REQ07_RC0_ACTIVE_VIDEO_SOURCE,
0x00, 0x40);
} else {
tm6000_set_reg(dev, TM6010_REQ07_R3F_RESET, 0x01);
if (dev->scaler)
tm6000_set_reg(dev, TM6010_REQ07_RC0_ACTIVE_VIDEO_SOURCE, 0x20);
else
tm6000_set_reg(dev, TM6010_REQ07_RC0_ACTIVE_VIDEO_SOURCE, 0x80);
tm6000_set_reg(dev, TM6010_REQ07_RC3_HSTART1, 0x88);
tm6000_set_reg(dev, TM6000_REQ07_RDA_CLK_SEL, 0x23);
tm6000_set_reg(dev, TM6010_REQ07_RD1_ADDR_FOR_REQ1, 0xc0);
tm6000_set_reg(dev, TM6010_REQ07_RD2_ADDR_FOR_REQ2, 0xd8);
tm6000_set_reg(dev, TM6010_REQ07_RD6_ENDP_REQ1_REQ2, 0x06);
tm6000_set_reg(dev, TM6000_REQ07_RDF_PWDOWN_ACLK, 0x1f);
tm6000_set_reg(dev, TM6010_REQ07_RFF_SOFT_RESET, 0x08);
tm6000_set_reg(dev, TM6010_REQ07_RFF_SOFT_RESET, 0x00);
tm6000_set_fourcc_format(dev);
tm6000_set_reg(dev, TM6010_REQ07_R3F_RESET, 0x00);
}
msleep(20);
f.frequency = dev->freq;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, &f);
msleep(100);
tm6000_set_standard(dev);
tm6000_set_vbi(dev);
tm6000_set_audio_bitrate(dev, 48000);
if (dev->gpio.dvb_led) {
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.dvb_led, 0x01);
}
return 0;
}
int tm6000_init_digital_mode(struct tm6000_core *dev)
{
if (dev->dev_type == TM6010) {
tm6000_set_reg_mask(dev, TM6010_REQ07_RCC_ACTIVE_IF,
0x00, 0x60);
tm6000_set_reg_mask(dev, TM6010_REQ07_RC0_ACTIVE_VIDEO_SOURCE,
0x40, 0x40);
tm6000_set_reg(dev, TM6010_REQ07_RFE_POWER_DOWN, 0x28);
tm6000_set_reg(dev, TM6010_REQ08_RE2_POWER_DOWN_CTRL1, 0xfc);
tm6000_set_reg(dev, TM6010_REQ08_RE6_POWER_DOWN_CTRL2, 0xff);
} else {
tm6000_set_reg(dev, TM6010_REQ07_RFF_SOFT_RESET, 0x08);
tm6000_set_reg(dev, TM6010_REQ07_RFF_SOFT_RESET, 0x00);
tm6000_set_reg(dev, TM6010_REQ07_R3F_RESET, 0x01);
tm6000_set_reg(dev, TM6000_REQ07_RDF_PWDOWN_ACLK, 0x08);
tm6000_set_reg(dev, TM6000_REQ07_RE2_VADC_STATUS_CTL, 0x0c);
tm6000_set_reg(dev, TM6000_REQ07_RE8_VADC_PWDOWN_CTL, 0xff);
tm6000_set_reg(dev, TM6000_REQ07_REB_VADC_AADC_MODE, 0xd8);
tm6000_set_reg(dev, TM6010_REQ07_RC0_ACTIVE_VIDEO_SOURCE, 0x40);
tm6000_set_reg(dev, TM6010_REQ07_RC1_TRESHOLD, 0xd0);
tm6000_set_reg(dev, TM6010_REQ07_RC3_HSTART1, 0x09);
tm6000_set_reg(dev, TM6000_REQ07_RDA_CLK_SEL, 0x37);
tm6000_set_reg(dev, TM6010_REQ07_RD1_ADDR_FOR_REQ1, 0xd8);
tm6000_set_reg(dev, TM6010_REQ07_RD2_ADDR_FOR_REQ2, 0xc0);
tm6000_set_reg(dev, TM6010_REQ07_RD6_ENDP_REQ1_REQ2, 0x60);
tm6000_set_reg(dev, TM6000_REQ07_RE2_VADC_STATUS_CTL, 0x0c);
tm6000_set_reg(dev, TM6000_REQ07_RE8_VADC_PWDOWN_CTL, 0xff);
tm6000_set_reg(dev, TM6000_REQ07_REB_VADC_AADC_MODE, 0x08);
msleep(50);
tm6000_set_reg(dev, REQ_04_EN_DISABLE_MCU_INT, 0x0020, 0x00);
msleep(50);
tm6000_set_reg(dev, REQ_04_EN_DISABLE_MCU_INT, 0x0020, 0x01);
msleep(50);
tm6000_set_reg(dev, REQ_04_EN_DISABLE_MCU_INT, 0x0020, 0x00);
msleep(100);
}
if (dev->gpio.dvb_led) {
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.dvb_led, 0x00);
}
return 0;
}
int tm6000_init(struct tm6000_core *dev)
{
int board, rc = 0, i, size;
struct reg_init *tab;
board = tm6000_get_reg32(dev, REQ_40_GET_VERSION, 0, 0);
if (board >= 0) {
switch (board & 0xff) {
case 0xf3:
printk(KERN_INFO "Found tm6000\n");
if (dev->dev_type != TM6000)
dev->dev_type = TM6000;
break;
case 0xf4:
printk(KERN_INFO "Found tm6010\n");
if (dev->dev_type != TM6010)
dev->dev_type = TM6010;
break;
default:
printk(KERN_INFO "Unknown board version = 0x%08x\n", board);
}
} else
printk(KERN_ERR "Error %i while retrieving board version\n", board);
if (dev->dev_type == TM6010) {
tab = tm6010_init_tab;
size = ARRAY_SIZE(tm6010_init_tab);
} else {
tab = tm6000_init_tab;
size = ARRAY_SIZE(tm6000_init_tab);
}
for (i = 0; i < size; i++) {
rc = tm6000_set_reg(dev, tab[i].req, tab[i].reg, tab[i].val);
if (rc < 0) {
printk(KERN_ERR "Error %i while setting req %d, "
"reg %d to value %d\n", rc,
tab[i].req, tab[i].reg, tab[i].val);
return rc;
}
}
msleep(5);
rc = tm6000_cards_setup(dev);
return rc;
}
int tm6000_set_audio_bitrate(struct tm6000_core *dev, int bitrate)
{
int val = 0;
u8 areg_f0 = 0x60;
u8 areg_0a = 0x91;
switch (bitrate) {
case 48000:
areg_f0 = 0x60;
areg_0a = 0x91;
dev->audio_bitrate = bitrate;
break;
case 32000:
areg_f0 = 0x00;
areg_0a = 0x90;
dev->audio_bitrate = bitrate;
break;
default:
return -EINVAL;
}
if (dev->dev_type == TM6010) {
val = tm6000_set_reg(dev, TM6010_REQ08_R0A_A_I2S_MOD, areg_0a);
if (val < 0)
return val;
val = tm6000_set_reg_mask(dev, TM6010_REQ08_RF0_DAUDIO_INPUT_CONFIG,
areg_f0, 0xf0);
if (val < 0)
return val;
} else {
val = tm6000_set_reg_mask(dev, TM6000_REQ07_REB_VADC_AADC_MODE,
areg_f0, 0xf0);
if (val < 0)
return val;
}
return 0;
}
int tm6000_set_audio_rinput(struct tm6000_core *dev)
{
if (dev->dev_type == TM6010) {
u8 areg_f0;
u8 areg_07 = 0x10;
switch (dev->rinput.amux) {
case TM6000_AMUX_SIF1:
case TM6000_AMUX_SIF2:
areg_f0 = 0x03;
areg_07 = 0x30;
break;
case TM6000_AMUX_ADC1:
areg_f0 = 0x00;
break;
case TM6000_AMUX_ADC2:
areg_f0 = 0x08;
break;
case TM6000_AMUX_I2S:
areg_f0 = 0x04;
break;
default:
printk(KERN_INFO "%s: audio input dosn't support\n",
dev->name);
return 0;
break;
}
tm6000_set_reg_mask(dev, TM6010_REQ08_RF0_DAUDIO_INPUT_CONFIG,
areg_f0, 0x0f);
tm6000_set_reg_mask(dev, TM6010_REQ07_R07_OUTPUT_CONTROL,
areg_07, 0xf0);
} else {
u8 areg_eb;
switch (dev->rinput.amux) {
case TM6000_AMUX_ADC1:
areg_eb = 0x00;
break;
case TM6000_AMUX_ADC2:
areg_eb = 0x04;
break;
default:
printk(KERN_INFO "%s: audio input dosn't support\n",
dev->name);
return 0;
break;
}
tm6000_set_reg_mask(dev, TM6000_REQ07_REB_VADC_AADC_MODE,
areg_eb, 0x0f);
}
return 0;
}
static void tm6010_set_mute_sif(struct tm6000_core *dev, u8 mute)
{
u8 mute_reg = 0;
if (mute)
mute_reg = 0x08;
tm6000_set_reg_mask(dev, TM6010_REQ08_R0A_A_I2S_MOD, mute_reg, 0x08);
}
static void tm6010_set_mute_adc(struct tm6000_core *dev, u8 mute)
{
u8 mute_reg = 0;
if (mute)
mute_reg = 0x20;
if (dev->dev_type == TM6010) {
tm6000_set_reg_mask(dev, TM6010_REQ08_RF2_LEFT_CHANNEL_VOL,
mute_reg, 0x20);
tm6000_set_reg_mask(dev, TM6010_REQ08_RF3_RIGHT_CHANNEL_VOL,
mute_reg, 0x20);
} else {
tm6000_set_reg_mask(dev, TM6000_REQ07_REC_VADC_AADC_LVOL,
mute_reg, 0x20);
tm6000_set_reg_mask(dev, TM6000_REQ07_RED_VADC_AADC_RVOL,
mute_reg, 0x20);
}
}
int tm6000_tvaudio_set_mute(struct tm6000_core *dev, u8 mute)
{
enum tm6000_mux mux;
if (dev->radio)
mux = dev->rinput.amux;
else
mux = dev->vinput[dev->input].amux;
switch (mux) {
case TM6000_AMUX_SIF1:
case TM6000_AMUX_SIF2:
if (dev->dev_type == TM6010)
tm6010_set_mute_sif(dev, mute);
else {
printk(KERN_INFO "ERROR: TM5600 and TM6000 don't has"
" SIF audio inputs. Please check the %s"
" configuration.\n", dev->name);
return -EINVAL;
}
break;
case TM6000_AMUX_ADC1:
case TM6000_AMUX_ADC2:
tm6010_set_mute_adc(dev, mute);
break;
default:
return -EINVAL;
break;
}
return 0;
}
static void tm6010_set_volume_sif(struct tm6000_core *dev, int vol)
{
u8 vol_reg;
vol_reg = vol & 0x0F;
if (vol < 0)
vol_reg |= 0x40;
tm6000_set_reg(dev, TM6010_REQ08_R07_A_LEFT_VOL, vol_reg);
tm6000_set_reg(dev, TM6010_REQ08_R08_A_RIGHT_VOL, vol_reg);
}
static void tm6010_set_volume_adc(struct tm6000_core *dev, int vol)
{
u8 vol_reg;
vol_reg = (vol + 0x10) & 0x1f;
if (dev->dev_type == TM6010) {
tm6000_set_reg(dev, TM6010_REQ08_RF2_LEFT_CHANNEL_VOL, vol_reg);
tm6000_set_reg(dev, TM6010_REQ08_RF3_RIGHT_CHANNEL_VOL, vol_reg);
} else {
tm6000_set_reg(dev, TM6000_REQ07_REC_VADC_AADC_LVOL, vol_reg);
tm6000_set_reg(dev, TM6000_REQ07_RED_VADC_AADC_RVOL, vol_reg);
}
}
void tm6000_set_volume(struct tm6000_core *dev, int vol)
{
enum tm6000_mux mux;
if (dev->radio) {
mux = dev->rinput.amux;
vol += 8;
} else
mux = dev->vinput[dev->input].amux;
switch (mux) {
case TM6000_AMUX_SIF1:
case TM6000_AMUX_SIF2:
if (dev->dev_type == TM6010)
tm6010_set_volume_sif(dev, vol);
else
printk(KERN_INFO "ERROR: TM5600 and TM6000 don't has"
" SIF audio inputs. Please check the %s"
" configuration.\n", dev->name);
break;
case TM6000_AMUX_ADC1:
case TM6000_AMUX_ADC2:
tm6010_set_volume_adc(dev, vol);
break;
default:
break;
}
}
void tm6000_remove_from_devlist(struct tm6000_core *dev)
{
mutex_lock(&tm6000_devlist_mutex);
list_del(&dev->devlist);
mutex_unlock(&tm6000_devlist_mutex);
}
void tm6000_add_into_devlist(struct tm6000_core *dev)
{
mutex_lock(&tm6000_devlist_mutex);
list_add_tail(&dev->devlist, &tm6000_devlist);
mutex_unlock(&tm6000_devlist_mutex);
}
int tm6000_call_fillbuf(struct tm6000_core *dev, enum tm6000_ops_type type,
char *buf, int size)
{
struct tm6000_ops *ops = NULL;
if (!list_empty(&tm6000_extension_devlist)) {
list_for_each_entry(ops, &tm6000_extension_devlist, next) {
if (ops->fillbuf && ops->type == type)
ops->fillbuf(dev, buf, size);
}
}
return 0;
}
int tm6000_register_extension(struct tm6000_ops *ops)
{
struct tm6000_core *dev = NULL;
mutex_lock(&tm6000_devlist_mutex);
list_add_tail(&ops->next, &tm6000_extension_devlist);
list_for_each_entry(dev, &tm6000_devlist, devlist) {
ops->init(dev);
printk(KERN_INFO "%s: Initialized (%s) extension\n",
dev->name, ops->name);
}
mutex_unlock(&tm6000_devlist_mutex);
return 0;
}
void tm6000_unregister_extension(struct tm6000_ops *ops)
{
struct tm6000_core *dev = NULL;
mutex_lock(&tm6000_devlist_mutex);
list_for_each_entry(dev, &tm6000_devlist, devlist)
ops->fini(dev);
printk(KERN_INFO "tm6000: Remove (%s) extension\n", ops->name);
list_del(&ops->next);
mutex_unlock(&tm6000_devlist_mutex);
}
void tm6000_init_extension(struct tm6000_core *dev)
{
struct tm6000_ops *ops = NULL;
mutex_lock(&tm6000_devlist_mutex);
if (!list_empty(&tm6000_extension_devlist)) {
list_for_each_entry(ops, &tm6000_extension_devlist, next) {
if (ops->init)
ops->init(dev);
}
}
mutex_unlock(&tm6000_devlist_mutex);
}
void tm6000_close_extension(struct tm6000_core *dev)
{
struct tm6000_ops *ops = NULL;
mutex_lock(&tm6000_devlist_mutex);
if (!list_empty(&tm6000_extension_devlist)) {
list_for_each_entry(ops, &tm6000_extension_devlist, next) {
if (ops->fini)
ops->fini(dev);
}
}
mutex_unlock(&tm6000_devlist_mutex);
}
