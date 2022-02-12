static inline u32 ipu_vdi_read(struct ipu_vdi *vdi, unsigned int offset)
{
return readl(vdi->base + offset);
}
static inline void ipu_vdi_write(struct ipu_vdi *vdi, u32 value,
unsigned int offset)
{
writel(value, vdi->base + offset);
}
void ipu_vdi_set_field_order(struct ipu_vdi *vdi, v4l2_std_id std, u32 field)
{
bool top_field_0 = false;
unsigned long flags;
u32 reg;
switch (field) {
case V4L2_FIELD_INTERLACED_TB:
case V4L2_FIELD_SEQ_TB:
case V4L2_FIELD_TOP:
top_field_0 = true;
break;
case V4L2_FIELD_INTERLACED_BT:
case V4L2_FIELD_SEQ_BT:
case V4L2_FIELD_BOTTOM:
top_field_0 = false;
break;
default:
top_field_0 = (std & V4L2_STD_525_60) ? true : false;
break;
}
spin_lock_irqsave(&vdi->lock, flags);
reg = ipu_vdi_read(vdi, VDI_C);
if (top_field_0)
reg &= ~VDI_C_TOP_FIELD_MAN_1;
else
reg |= VDI_C_TOP_FIELD_MAN_1;
ipu_vdi_write(vdi, reg, VDI_C);
spin_unlock_irqrestore(&vdi->lock, flags);
}
void ipu_vdi_set_motion(struct ipu_vdi *vdi, enum ipu_motion_sel motion_sel)
{
unsigned long flags;
u32 reg;
spin_lock_irqsave(&vdi->lock, flags);
reg = ipu_vdi_read(vdi, VDI_C);
reg &= ~VDI_C_MOT_SEL_MASK;
switch (motion_sel) {
case MED_MOTION:
reg |= VDI_C_MOT_SEL_MED;
break;
case HIGH_MOTION:
reg |= VDI_C_MOT_SEL_FULL;
break;
default:
reg |= VDI_C_MOT_SEL_LOW;
break;
}
ipu_vdi_write(vdi, reg, VDI_C);
spin_unlock_irqrestore(&vdi->lock, flags);
}
void ipu_vdi_setup(struct ipu_vdi *vdi, u32 code, int xres, int yres)
{
unsigned long flags;
u32 pixel_fmt, reg;
spin_lock_irqsave(&vdi->lock, flags);
reg = ((yres - 1) << 16) | (xres - 1);
ipu_vdi_write(vdi, reg, VDI_FSIZE);
if (code == MEDIA_BUS_FMT_UYVY8_2X8 ||
code == MEDIA_BUS_FMT_UYVY8_1X16 ||
code == MEDIA_BUS_FMT_YUYV8_2X8 ||
code == MEDIA_BUS_FMT_YUYV8_1X16)
pixel_fmt = VDI_C_CH_422;
else
pixel_fmt = VDI_C_CH_420;
reg = ipu_vdi_read(vdi, VDI_C);
reg |= pixel_fmt;
reg |= VDI_C_BURST_SIZE2_4;
reg |= VDI_C_BURST_SIZE1_4 | VDI_C_VWM1_CLR_2;
reg |= VDI_C_BURST_SIZE3_4 | VDI_C_VWM3_CLR_2;
ipu_vdi_write(vdi, reg, VDI_C);
spin_unlock_irqrestore(&vdi->lock, flags);
}
void ipu_vdi_unsetup(struct ipu_vdi *vdi)
{
unsigned long flags;
spin_lock_irqsave(&vdi->lock, flags);
ipu_vdi_write(vdi, 0, VDI_FSIZE);
ipu_vdi_write(vdi, 0, VDI_C);
spin_unlock_irqrestore(&vdi->lock, flags);
}
int ipu_vdi_enable(struct ipu_vdi *vdi)
{
unsigned long flags;
spin_lock_irqsave(&vdi->lock, flags);
if (!vdi->use_count)
ipu_module_enable(vdi->ipu, vdi->module);
vdi->use_count++;
spin_unlock_irqrestore(&vdi->lock, flags);
return 0;
}
int ipu_vdi_disable(struct ipu_vdi *vdi)
{
unsigned long flags;
spin_lock_irqsave(&vdi->lock, flags);
if (vdi->use_count) {
if (!--vdi->use_count)
ipu_module_disable(vdi->ipu, vdi->module);
}
spin_unlock_irqrestore(&vdi->lock, flags);
return 0;
}
struct ipu_vdi *ipu_vdi_get(struct ipu_soc *ipu)
{
return ipu->vdi_priv;
}
void ipu_vdi_put(struct ipu_vdi *vdi)
{
}
int ipu_vdi_init(struct ipu_soc *ipu, struct device *dev,
unsigned long base, u32 module)
{
struct ipu_vdi *vdi;
vdi = devm_kzalloc(dev, sizeof(*vdi), GFP_KERNEL);
if (!vdi)
return -ENOMEM;
ipu->vdi_priv = vdi;
spin_lock_init(&vdi->lock);
vdi->module = module;
vdi->base = devm_ioremap(dev, base, PAGE_SIZE);
if (!vdi->base)
return -ENOMEM;
dev_dbg(dev, "VDI base: 0x%08lx remapped to %p\n", base, vdi->base);
vdi->ipu = ipu;
return 0;
}
void ipu_vdi_exit(struct ipu_soc *ipu)
{
}
