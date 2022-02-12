static int img_ir_sony_scancode(int len, u64 raw, int *scancode, u64 protocols)
{
unsigned int dev, subdev, func;
switch (len) {
case 12:
if (!(protocols & RC_BIT_SONY12))
return -EINVAL;
func = raw & 0x7f;
raw >>= 7;
dev = raw & 0x1f;
subdev = 0;
break;
case 15:
if (!(protocols & RC_BIT_SONY15))
return -EINVAL;
func = raw & 0x7f;
raw >>= 7;
dev = raw & 0xff;
subdev = 0;
break;
case 20:
if (!(protocols & RC_BIT_SONY20))
return -EINVAL;
func = raw & 0x7f;
raw >>= 7;
dev = raw & 0x1f;
raw >>= 5;
subdev = raw & 0xff;
break;
default:
return -EINVAL;
}
*scancode = dev << 16 | subdev << 8 | func;
return IMG_IR_SCANCODE;
}
static int img_ir_sony_filter(const struct rc_scancode_filter *in,
struct img_ir_filter *out, u64 protocols)
{
unsigned int dev, subdev, func;
unsigned int dev_m, subdev_m, func_m;
unsigned int len = 0;
dev = (in->data >> 16) & 0xff;
dev_m = (in->mask >> 16) & 0xff;
subdev = (in->data >> 8) & 0xff;
subdev_m = (in->mask >> 8) & 0xff;
func = (in->data >> 0) & 0x7f;
func_m = (in->mask >> 0) & 0x7f;
if (subdev & subdev_m) {
if (dev & dev_m & 0xe0)
return -EINVAL;
if (!(protocols & RC_BIT_SONY20))
return -EINVAL;
len = 20;
dev_m &= 0x1f;
} else if (dev & dev_m & 0xe0) {
if (!(protocols & RC_BIT_SONY15))
return -EINVAL;
len = 15;
subdev_m = 0;
} else {
subdev_m &= (dev_m >> 5) | 0xf8;
dev_m &= 0x1f;
}
dev &= dev_m;
subdev &= subdev_m;
out->data = func |
dev << 7 |
subdev << 15;
out->mask = func_m |
dev_m << 7 |
subdev_m << 15;
if (len) {
out->minlen = len;
out->maxlen = len;
}
return 0;
}
