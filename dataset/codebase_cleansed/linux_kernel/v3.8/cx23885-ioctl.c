int cx23885_g_chip_ident(struct file *file, void *fh,
struct v4l2_dbg_chip_ident *chip)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)fh)->dev;
int err = 0;
u8 rev;
chip->ident = V4L2_IDENT_NONE;
chip->revision = 0;
switch (chip->match.type) {
case V4L2_CHIP_MATCH_HOST:
switch (chip->match.addr) {
case 0:
rev = cx_read(RDR_CFG2) & 0xff;
switch (dev->pci->device) {
case 0x8852:
if (rev == 0x04)
chip->ident = V4L2_IDENT_CX23888;
else
chip->ident = V4L2_IDENT_CX23885;
break;
case 0x8880:
if (rev == 0x0e || rev == 0x0f)
chip->ident = V4L2_IDENT_CX23887;
else
chip->ident = V4L2_IDENT_CX23888;
break;
default:
chip->ident = V4L2_IDENT_UNKNOWN;
break;
}
chip->revision = (dev->pci->device << 16) | (rev << 8) |
(dev->hwrevision & 0xff);
break;
case 1:
if (dev->v4l_device != NULL) {
chip->ident = V4L2_IDENT_CX23417;
chip->revision = 0;
}
break;
case 2:
call_hw(dev, CX23885_HW_888_IR, core, g_chip_ident,
chip);
break;
default:
err = -EINVAL;
break;
}
break;
case V4L2_CHIP_MATCH_I2C_DRIVER:
call_all(dev, core, g_chip_ident, chip);
break;
case V4L2_CHIP_MATCH_I2C_ADDR:
call_all(dev, core, g_chip_ident, chip);
break;
default:
err = -EINVAL;
break;
}
return err;
}
static int cx23885_g_host_register(struct cx23885_dev *dev,
struct v4l2_dbg_register *reg)
{
if ((reg->reg & 0x3) != 0 || reg->reg >= pci_resource_len(dev->pci, 0))
return -EINVAL;
reg->size = 4;
reg->val = cx_read(reg->reg);
return 0;
}
static int cx23417_g_register(struct cx23885_dev *dev,
struct v4l2_dbg_register *reg)
{
u32 value;
if (dev->v4l_device == NULL)
return -EINVAL;
if ((reg->reg & 0x3) != 0 || reg->reg >= 0x10000)
return -EINVAL;
if (mc417_register_read(dev, (u16) reg->reg, &value))
return -EINVAL;
reg->size = 4;
reg->val = value;
return 0;
}
int cx23885_g_register(struct file *file, void *fh,
struct v4l2_dbg_register *reg)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)fh)->dev;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (reg->match.type == V4L2_CHIP_MATCH_HOST) {
switch (reg->match.addr) {
case 0:
return cx23885_g_host_register(dev, reg);
case 1:
return cx23417_g_register(dev, reg);
default:
break;
}
}
call_all(dev, core, g_register, reg);
return 0;
}
static int cx23885_s_host_register(struct cx23885_dev *dev,
struct v4l2_dbg_register *reg)
{
if ((reg->reg & 0x3) != 0 || reg->reg >= pci_resource_len(dev->pci, 0))
return -EINVAL;
reg->size = 4;
cx_write(reg->reg, reg->val);
return 0;
}
static int cx23417_s_register(struct cx23885_dev *dev,
struct v4l2_dbg_register *reg)
{
if (dev->v4l_device == NULL)
return -EINVAL;
if ((reg->reg & 0x3) != 0 || reg->reg >= 0x10000)
return -EINVAL;
if (mc417_register_write(dev, (u16) reg->reg, (u32) reg->val))
return -EINVAL;
reg->size = 4;
return 0;
}
int cx23885_s_register(struct file *file, void *fh,
struct v4l2_dbg_register *reg)
{
struct cx23885_dev *dev = ((struct cx23885_fh *)fh)->dev;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (reg->match.type == V4L2_CHIP_MATCH_HOST) {
switch (reg->match.addr) {
case 0:
return cx23885_s_host_register(dev, reg);
case 1:
return cx23417_s_register(dev, reg);
default:
break;
}
}
call_all(dev, core, s_register, reg);
return 0;
}
