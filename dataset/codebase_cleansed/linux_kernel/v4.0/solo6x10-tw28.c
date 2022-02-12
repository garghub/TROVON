static u8 tw_readbyte(struct solo_dev *solo_dev, int chip_id, u8 tw6x_off,
u8 tw_off)
{
if (is_tw286x(solo_dev, chip_id))
return solo_i2c_readbyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_id),
tw6x_off);
else
return solo_i2c_readbyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_id),
tw_off);
}
static void tw_writebyte(struct solo_dev *solo_dev, int chip_id,
u8 tw6x_off, u8 tw_off, u8 val)
{
if (is_tw286x(solo_dev, chip_id))
solo_i2c_writebyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_id),
tw6x_off, val);
else
solo_i2c_writebyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_id),
tw_off, val);
}
static void tw_write_and_verify(struct solo_dev *solo_dev, u8 addr, u8 off,
u8 val)
{
int i;
for (i = 0; i < 5; i++) {
u8 rval = solo_i2c_readbyte(solo_dev, SOLO_I2C_TW, addr, off);
if (rval == val)
return;
solo_i2c_writebyte(solo_dev, SOLO_I2C_TW, addr, off, val);
msleep_interruptible(1);
}
}
static int tw2865_setup(struct solo_dev *solo_dev, u8 dev_addr)
{
u8 tbl_tw2865_common[256];
int i;
if (solo_dev->video_type == SOLO_VO_FMT_TYPE_PAL)
memcpy(tbl_tw2865_common, tbl_tw2865_pal_template,
sizeof(tbl_tw2865_common));
else
memcpy(tbl_tw2865_common, tbl_tw2865_ntsc_template,
sizeof(tbl_tw2865_common));
if (solo_dev->nr_chans == 4) {
tbl_tw2865_common[0xd2] = 0x01;
tbl_tw2865_common[0xcf] = 0x00;
} else if (solo_dev->nr_chans == 8) {
tbl_tw2865_common[0xd2] = 0x02;
if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2865_common[0xcf] = 0x80;
} else if (solo_dev->nr_chans == 16) {
tbl_tw2865_common[0xd2] = 0x03;
if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2865_common[0xcf] = 0x83;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(2))
tbl_tw2865_common[0xcf] = 0x83;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(3))
tbl_tw2865_common[0xcf] = 0x80;
}
for (i = 0; i < 0xff; i++) {
switch (i) {
case 0xb8 ... 0xc1:
case 0xc4 ... 0xc7:
case 0xfd:
continue;
}
switch (i & ~0x30) {
case 0x00:
case 0x0c ... 0x0d:
continue;
}
tw_write_and_verify(solo_dev, dev_addr, i,
tbl_tw2865_common[i]);
}
return 0;
}
static int tw2864_setup(struct solo_dev *solo_dev, u8 dev_addr)
{
u8 tbl_tw2864_common[256];
int i;
if (solo_dev->video_type == SOLO_VO_FMT_TYPE_PAL)
memcpy(tbl_tw2864_common, tbl_tw2864_pal_template,
sizeof(tbl_tw2864_common));
else
memcpy(tbl_tw2864_common, tbl_tw2864_ntsc_template,
sizeof(tbl_tw2864_common));
if (solo_dev->tw2865 == 0) {
if (solo_dev->nr_chans == 4) {
tbl_tw2864_common[0xd2] = 0x01;
tbl_tw2864_common[0xcf] = 0x00;
} else if (solo_dev->nr_chans == 8) {
tbl_tw2864_common[0xd2] = 0x02;
if (dev_addr == TW_CHIP_OFFSET_ADDR(0))
tbl_tw2864_common[0xcf] = 0x43;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2864_common[0xcf] = 0x40;
} else if (solo_dev->nr_chans == 16) {
tbl_tw2864_common[0xd2] = 0x03;
if (dev_addr == TW_CHIP_OFFSET_ADDR(0))
tbl_tw2864_common[0xcf] = 0x43;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2864_common[0xcf] = 0x43;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(2))
tbl_tw2864_common[0xcf] = 0x43;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(3))
tbl_tw2864_common[0xcf] = 0x40;
}
} else {
for (i = 0; i <= 4; i++)
tbl_tw2864_common[0x08 | i << 4] = 0x12;
if (solo_dev->nr_chans == 8) {
tbl_tw2864_common[0xd2] = 0x02;
if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2864_common[0xcf] = 0x80;
} else if (solo_dev->nr_chans == 16) {
tbl_tw2864_common[0xd2] = 0x03;
if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2864_common[0xcf] = 0x83;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(2))
tbl_tw2864_common[0xcf] = 0x83;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(3))
tbl_tw2864_common[0xcf] = 0x80;
}
}
for (i = 0; i < 0xff; i++) {
switch (i) {
case 0xb8 ... 0xc1:
case 0xfd:
continue;
}
switch (i & ~0x30) {
case 0x00:
case 0x0c:
case 0x0d:
continue;
}
tw_write_and_verify(solo_dev, dev_addr, i,
tbl_tw2864_common[i]);
}
return 0;
}
static int tw2815_setup(struct solo_dev *solo_dev, u8 dev_addr)
{
u8 tbl_ntsc_tw2815_common[] = {
0x00, 0xc8, 0x20, 0xd0, 0x06, 0xf0, 0x08, 0x80,
0x80, 0x80, 0x80, 0x02, 0x06, 0x00, 0x11,
};
u8 tbl_pal_tw2815_common[] = {
0x00, 0x88, 0x20, 0xd0, 0x05, 0x20, 0x28, 0x80,
0x80, 0x80, 0x80, 0x82, 0x06, 0x00, 0x11,
};
u8 tbl_tw2815_sfr[] = {
0x00, 0x00, 0x00, 0xc0, 0x45, 0xa0, 0xd0, 0x2f,
0x64, 0x80, 0x80, 0x82, 0x82, 0x00, 0x00, 0x00,
0x00, 0x0f, 0x05, 0x00, 0x00, 0x80, 0x06, 0x00,
0x00, 0x00, 0x00, 0xff, 0x8f, 0x00, 0x00, 0x00,
0x88, 0x88, 0xc0, 0x00, 0x20, 0x64, 0xa8, 0xec,
0x31, 0x75, 0xb9, 0xfd, 0x00, 0x00, 0x88, 0x88,
0x88, 0x11, 0x00, 0x88, 0x88, 0x00,
};
u8 *tbl_tw2815_common;
int i;
int ch;
tbl_ntsc_tw2815_common[0x06] = 0;
tbl_ntsc_tw2815_common[0x02] = DEFAULT_HDELAY_NTSC & 0xff;
tbl_ntsc_tw2815_common[0x06] |= 0x03 & (DEFAULT_HDELAY_NTSC >> 8);
tbl_ntsc_tw2815_common[0x03] = DEFAULT_HACTIVE_NTSC & 0xff;
tbl_ntsc_tw2815_common[0x06] |=
((0x03 & (DEFAULT_HACTIVE_NTSC >> 8)) << 2);
tbl_ntsc_tw2815_common[0x04] = DEFAULT_VDELAY_NTSC & 0xff;
tbl_ntsc_tw2815_common[0x06] |=
((0x01 & (DEFAULT_VDELAY_NTSC >> 8)) << 4);
tbl_ntsc_tw2815_common[0x05] = DEFAULT_VACTIVE_NTSC & 0xff;
tbl_ntsc_tw2815_common[0x06] |=
((0x01 & (DEFAULT_VACTIVE_NTSC >> 8)) << 5);
tbl_pal_tw2815_common[0x06] = 0;
tbl_pal_tw2815_common[0x02] = DEFAULT_HDELAY_PAL & 0xff;
tbl_pal_tw2815_common[0x06] |= 0x03 & (DEFAULT_HDELAY_PAL >> 8);
tbl_pal_tw2815_common[0x03] = DEFAULT_HACTIVE_PAL & 0xff;
tbl_pal_tw2815_common[0x06] |=
((0x03 & (DEFAULT_HACTIVE_PAL >> 8)) << 2);
tbl_pal_tw2815_common[0x04] = DEFAULT_VDELAY_PAL & 0xff;
tbl_pal_tw2815_common[0x06] |=
((0x01 & (DEFAULT_VDELAY_PAL >> 8)) << 4);
tbl_pal_tw2815_common[0x05] = DEFAULT_VACTIVE_PAL & 0xff;
tbl_pal_tw2815_common[0x06] |=
((0x01 & (DEFAULT_VACTIVE_PAL >> 8)) << 5);
tbl_tw2815_common =
(solo_dev->video_type == SOLO_VO_FMT_TYPE_NTSC) ?
tbl_ntsc_tw2815_common : tbl_pal_tw2815_common;
tbl_tw2815_common[0x0d] |= 0x04;
tbl_tw2815_sfr[0x62 - 0x40] &= ~(3 << 6);
if (solo_dev->nr_chans == 4) {
tbl_tw2815_sfr[0x63 - 0x40] |= 1;
tbl_tw2815_sfr[0x62 - 0x40] |= 3 << 6;
} else if (solo_dev->nr_chans == 8) {
tbl_tw2815_sfr[0x63 - 0x40] |= 2;
if (dev_addr == TW_CHIP_OFFSET_ADDR(0))
tbl_tw2815_sfr[0x62 - 0x40] |= 1 << 6;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2815_sfr[0x62 - 0x40] |= 2 << 6;
} else if (solo_dev->nr_chans == 16) {
tbl_tw2815_sfr[0x63 - 0x40] |= 3;
if (dev_addr == TW_CHIP_OFFSET_ADDR(0))
tbl_tw2815_sfr[0x62 - 0x40] |= 1 << 6;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(1))
tbl_tw2815_sfr[0x62 - 0x40] |= 0 << 6;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(2))
tbl_tw2815_sfr[0x62 - 0x40] |= 0 << 6;
else if (dev_addr == TW_CHIP_OFFSET_ADDR(3))
tbl_tw2815_sfr[0x62 - 0x40] |= 2 << 6;
}
tbl_tw2815_sfr[0x62 - 0x40] |= 0 << 2;
tbl_tw2815_sfr[0x6c - 0x40] |= 0 << 2;
tbl_tw2815_sfr[0x6c - 0x40] |= 1 << 5;
tbl_tw2815_sfr[0x5c - 0x40] |= 1 << 5;
tbl_tw2815_sfr[0x70 - 0x40] |= 0xff;
tbl_tw2815_sfr[0x71 - 0x40] |= 0x10;
tbl_tw2815_sfr[0x6d - 0x40] |= 0x0f;
for (ch = 0; ch < 4; ch++) {
tbl_tw2815_common[0x0d] &= ~3;
switch (ch) {
case 0:
tbl_tw2815_common[0x0d] |= 0x21;
break;
case 1:
tbl_tw2815_common[0x0d] |= 0x20;
break;
case 2:
tbl_tw2815_common[0x0d] |= 0x23;
break;
case 3:
tbl_tw2815_common[0x0d] |= 0x22;
break;
}
for (i = 0; i < 0x0f; i++) {
if (i == 0x00)
continue;
solo_i2c_writebyte(solo_dev, SOLO_I2C_TW,
dev_addr, (ch * 0x10) + i,
tbl_tw2815_common[i]);
}
}
for (i = 0x40; i < 0x76; i++) {
if (i == 0x40 || i == 0x59 || i == 0x5a ||
i == 0x5d || i == 0x5e || i == 0x5f)
continue;
solo_i2c_writebyte(solo_dev, SOLO_I2C_TW, dev_addr, i,
tbl_tw2815_sfr[i - 0x40]);
}
return 0;
}
static void saa712x_write_regs(struct solo_dev *dev, const u8 *vals,
int start, int n)
{
for (; start < n; start++, vals++) {
switch (start) {
case 0x2e ... 0x37:
case 0x60:
case 0x7d:
continue;
}
solo_i2c_writebyte(dev, SOLO_I2C_SAA, 0x46, start, *vals);
}
}
static void saa712x_setup(struct solo_dev *dev)
{
const int reg_start = 0x26;
const u8 saa7128_regs_ntsc[] = {
0x0d, 0x00,
0x59, 0x1d, 0x75, 0x3f, 0x06, 0x3f,
0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x1a, 0x1a, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x68, 0x10, 0x97, 0x4c, 0x18,
0x9b, 0x93, 0x9f, 0xff, 0x7c, 0x34, 0x3f, 0x3f,
0x3f, 0x83, 0x83, 0x80, 0x0d, 0x0f, 0xc3, 0x06,
0x02, 0x80, 0x71, 0x77, 0xa7, 0x67, 0x66, 0x2e,
0x7b, 0x11, 0x4f, 0x1f, 0x7c, 0xf0, 0x21, 0x77,
0x41, 0x88, 0x41, 0x52, 0xed, 0x10, 0x10, 0x00,
0x41, 0xc3, 0x00, 0x3e, 0xb8, 0x02, 0x00, 0x00,
0x00, 0x00, FIRST_ACTIVE_LINE, LAST_ACTIVE_LINE & 0xff,
SAA712x_reg7c, 0x00, 0xff, 0xff,
}, saa7128_regs_pal[] = {
0x0d, 0x00,
0xe1, 0x1d, 0x75, 0x3f, 0x06, 0x3f,
0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x1a, 0x1a, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x68, 0x10, 0x97, 0x4c, 0x18,
0x9b, 0x93, 0x9f, 0xff, 0x7c, 0x34, 0x3f, 0x3f,
0x3f, 0x83, 0x83, 0x80, 0x0d, 0x0f, 0xc3, 0x06,
0x02, 0x80, 0x0f, 0x77, 0xa7, 0x67, 0x66, 0x2e,
0x7b, 0x02, 0x35, 0xcb, 0x8a, 0x09, 0x2a, 0x77,
0x41, 0x88, 0x41, 0x52, 0xf1, 0x10, 0x20, 0x00,
0x41, 0xc3, 0x00, 0x3e, 0xb8, 0x02, 0x00, 0x00,
0x00, 0x00, 0x12, 0x30,
SAA712x_reg7c | 0x40, 0x00, 0xff, 0xff,
};
if (dev->video_type == SOLO_VO_FMT_TYPE_PAL)
saa712x_write_regs(dev, saa7128_regs_pal, reg_start,
sizeof(saa7128_regs_pal));
else
saa712x_write_regs(dev, saa7128_regs_ntsc, reg_start,
sizeof(saa7128_regs_ntsc));
}
int solo_tw28_init(struct solo_dev *solo_dev)
{
int i;
u8 value;
solo_dev->tw28_cnt = 0;
for (i = 0; i < solo_dev->nr_chans / 4; i++) {
value = solo_i2c_readbyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(i), 0xFF);
switch (value >> 3) {
case 0x18:
solo_dev->tw2865 |= 1 << i;
solo_dev->tw28_cnt++;
break;
case 0x0c:
solo_dev->tw2864 |= 1 << i;
solo_dev->tw28_cnt++;
break;
default:
value = solo_i2c_readbyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(i),
0x59);
if ((value >> 3) == 0x04) {
solo_dev->tw2815 |= 1 << i;
solo_dev->tw28_cnt++;
}
}
}
if (solo_dev->tw28_cnt != (solo_dev->nr_chans >> 2)) {
dev_err(&solo_dev->pdev->dev,
"Could not initialize any techwell chips\n");
return -EINVAL;
}
saa712x_setup(solo_dev);
for (i = 0; i < solo_dev->tw28_cnt; i++) {
if ((solo_dev->tw2865 & (1 << i)))
tw2865_setup(solo_dev, TW_CHIP_OFFSET_ADDR(i));
else if ((solo_dev->tw2864 & (1 << i)))
tw2864_setup(solo_dev, TW_CHIP_OFFSET_ADDR(i));
else
tw2815_setup(solo_dev, TW_CHIP_OFFSET_ADDR(i));
}
return 0;
}
int tw28_get_video_status(struct solo_dev *solo_dev, u8 ch)
{
u8 val, chip_num;
chip_num = ch / 4;
ch %= 4;
val = tw_readbyte(solo_dev, chip_num, TW286x_AV_STAT_ADDR,
TW_AV_STAT_ADDR) & 0x0f;
return val & (1 << ch) ? 1 : 0;
}
bool tw28_has_sharpness(struct solo_dev *solo_dev, u8 ch)
{
return is_tw286x(solo_dev, ch / 4);
}
int tw28_set_ctrl_val(struct solo_dev *solo_dev, u32 ctrl, u8 ch,
s32 val)
{
char sval;
u8 chip_num;
chip_num = ch / 4;
ch %= 4;
if (val > 255 || val < 0)
return -ERANGE;
switch (ctrl) {
case V4L2_CID_SHARPNESS:
if (is_tw286x(solo_dev, chip_num)) {
u8 v = solo_i2c_readbyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_num),
TW286x_SHARPNESS(chip_num));
v &= 0xf0;
v |= val;
solo_i2c_writebyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_num),
TW286x_SHARPNESS(chip_num), v);
} else {
return -EINVAL;
}
break;
case V4L2_CID_HUE:
if (is_tw286x(solo_dev, chip_num))
sval = val - 128;
else
sval = (char)val;
tw_writebyte(solo_dev, chip_num, TW286x_HUE_ADDR(ch),
TW_HUE_ADDR(ch), sval);
break;
case V4L2_CID_SATURATION:
if (is_tw286x(solo_dev, chip_num)) {
solo_i2c_writebyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_num),
TW286x_SATURATIONU_ADDR(ch), val);
}
tw_writebyte(solo_dev, chip_num, TW286x_SATURATIONV_ADDR(ch),
TW_SATURATION_ADDR(ch), val);
break;
case V4L2_CID_CONTRAST:
tw_writebyte(solo_dev, chip_num, TW286x_CONTRAST_ADDR(ch),
TW_CONTRAST_ADDR(ch), val);
break;
case V4L2_CID_BRIGHTNESS:
if (is_tw286x(solo_dev, chip_num))
sval = val - 128;
else
sval = (char)val;
tw_writebyte(solo_dev, chip_num, TW286x_BRIGHTNESS_ADDR(ch),
TW_BRIGHTNESS_ADDR(ch), sval);
break;
default:
return -EINVAL;
}
return 0;
}
int tw28_get_ctrl_val(struct solo_dev *solo_dev, u32 ctrl, u8 ch,
s32 *val)
{
u8 rval, chip_num;
chip_num = ch / 4;
ch %= 4;
switch (ctrl) {
case V4L2_CID_SHARPNESS:
if (is_tw286x(solo_dev, chip_num)) {
rval = solo_i2c_readbyte(solo_dev, SOLO_I2C_TW,
TW_CHIP_OFFSET_ADDR(chip_num),
TW286x_SHARPNESS(chip_num));
*val = rval & 0x0f;
} else
*val = 0;
break;
case V4L2_CID_HUE:
rval = tw_readbyte(solo_dev, chip_num, TW286x_HUE_ADDR(ch),
TW_HUE_ADDR(ch));
if (is_tw286x(solo_dev, chip_num))
*val = (s32)((char)rval) + 128;
else
*val = rval;
break;
case V4L2_CID_SATURATION:
*val = tw_readbyte(solo_dev, chip_num,
TW286x_SATURATIONU_ADDR(ch),
TW_SATURATION_ADDR(ch));
break;
case V4L2_CID_CONTRAST:
*val = tw_readbyte(solo_dev, chip_num,
TW286x_CONTRAST_ADDR(ch),
TW_CONTRAST_ADDR(ch));
break;
case V4L2_CID_BRIGHTNESS:
rval = tw_readbyte(solo_dev, chip_num,
TW286x_BRIGHTNESS_ADDR(ch),
TW_BRIGHTNESS_ADDR(ch));
if (is_tw286x(solo_dev, chip_num))
*val = (s32)((char)rval) + 128;
else
*val = rval;
break;
default:
return -EINVAL;
}
return 0;
}
u8 tw28_get_audio_gain(struct solo_dev *solo_dev, u8 ch)
{
u8 val;
u8 chip_num;
chip_num = ch / 4;
ch %= 4;
val = tw_readbyte(solo_dev, chip_num,
TW286x_AUDIO_INPUT_GAIN_ADDR(ch),
TW_AUDIO_INPUT_GAIN_ADDR(ch));
return (ch % 2) ? (val >> 4) : (val & 0x0f);
}
void tw28_set_audio_gain(struct solo_dev *solo_dev, u8 ch, u8 val)
{
u8 old_val;
u8 chip_num;
chip_num = ch / 4;
ch %= 4;
old_val = tw_readbyte(solo_dev, chip_num,
TW286x_AUDIO_INPUT_GAIN_ADDR(ch),
TW_AUDIO_INPUT_GAIN_ADDR(ch));
val = (old_val & ((ch % 2) ? 0x0f : 0xf0)) |
((ch % 2) ? (val << 4) : val);
tw_writebyte(solo_dev, chip_num, TW286x_AUDIO_INPUT_GAIN_ADDR(ch),
TW_AUDIO_INPUT_GAIN_ADDR(ch), val);
}
