static inline struct cafe_camera *to_cam(struct v4l2_device *dev)
{
return container_of(dev, struct cafe_camera, v4l2_dev);
}
static struct cafe_format_struct *cafe_find_format(u32 pixelformat)
{
unsigned i;
for (i = 0; i < N_CAFE_FMTS; i++)
if (cafe_formats[i].pixelformat == pixelformat)
return cafe_formats + i;
return cafe_formats;
}
static void cafe_reset_buffers(struct cafe_camera *cam)
{
int i;
cam->next_buf = -1;
for (i = 0; i < cam->nbufs; i++)
clear_bit(i, &cam->flags);
cam->specframes = 0;
}
static inline int cafe_needs_config(struct cafe_camera *cam)
{
return test_bit(CF_CONFIG_NEEDED, &cam->flags);
}
static void cafe_set_config_needed(struct cafe_camera *cam, int needed)
{
if (needed)
set_bit(CF_CONFIG_NEEDED, &cam->flags);
else
clear_bit(CF_CONFIG_NEEDED, &cam->flags);
}
static inline void cafe_reg_write(struct cafe_camera *cam, unsigned int reg,
unsigned int val)
{
iowrite32(val, cam->regs + reg);
}
static inline unsigned int cafe_reg_read(struct cafe_camera *cam,
unsigned int reg)
{
return ioread32(cam->regs + reg);
}
static inline void cafe_reg_write_mask(struct cafe_camera *cam, unsigned int reg,
unsigned int val, unsigned int mask)
{
unsigned int v = cafe_reg_read(cam, reg);
v = (v & ~mask) | (val & mask);
cafe_reg_write(cam, reg, v);
}
static inline void cafe_reg_clear_bit(struct cafe_camera *cam,
unsigned int reg, unsigned int val)
{
cafe_reg_write_mask(cam, reg, 0, val);
}
static inline void cafe_reg_set_bit(struct cafe_camera *cam,
unsigned int reg, unsigned int val)
{
cafe_reg_write_mask(cam, reg, val, val);
}
static int cafe_smbus_write_done(struct cafe_camera *cam)
{
unsigned long flags;
int c1;
udelay(20);
spin_lock_irqsave(&cam->dev_lock, flags);
c1 = cafe_reg_read(cam, REG_TWSIC1);
spin_unlock_irqrestore(&cam->dev_lock, flags);
return (c1 & (TWSIC1_WSTAT|TWSIC1_ERROR)) != TWSIC1_WSTAT;
}
static int cafe_smbus_write_data(struct cafe_camera *cam,
u16 addr, u8 command, u8 value)
{
unsigned int rval;
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
rval = TWSIC0_EN | ((addr << TWSIC0_SID_SHIFT) & TWSIC0_SID);
rval |= TWSIC0_OVMAGIC;
rval |= TWSIC0_CLKDIV;
cafe_reg_write(cam, REG_TWSIC0, rval);
(void) cafe_reg_read(cam, REG_TWSIC1);
rval = value | ((command << TWSIC1_ADDR_SHIFT) & TWSIC1_ADDR);
cafe_reg_write(cam, REG_TWSIC1, rval);
spin_unlock_irqrestore(&cam->dev_lock, flags);
mdelay(2);
wait_event_timeout(cam->smbus_wait, cafe_smbus_write_done(cam),
CAFE_SMBUS_TIMEOUT);
spin_lock_irqsave(&cam->dev_lock, flags);
rval = cafe_reg_read(cam, REG_TWSIC1);
spin_unlock_irqrestore(&cam->dev_lock, flags);
if (rval & TWSIC1_WSTAT) {
cam_err(cam, "SMBUS write (%02x/%02x/%02x) timed out\n", addr,
command, value);
return -EIO;
}
if (rval & TWSIC1_ERROR) {
cam_err(cam, "SMBUS write (%02x/%02x/%02x) error\n", addr,
command, value);
return -EIO;
}
return 0;
}
static int cafe_smbus_read_done(struct cafe_camera *cam)
{
unsigned long flags;
int c1;
udelay(20);
spin_lock_irqsave(&cam->dev_lock, flags);
c1 = cafe_reg_read(cam, REG_TWSIC1);
spin_unlock_irqrestore(&cam->dev_lock, flags);
return c1 & (TWSIC1_RVALID|TWSIC1_ERROR);
}
static int cafe_smbus_read_data(struct cafe_camera *cam,
u16 addr, u8 command, u8 *value)
{
unsigned int rval;
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
rval = TWSIC0_EN | ((addr << TWSIC0_SID_SHIFT) & TWSIC0_SID);
rval |= TWSIC0_OVMAGIC;
rval |= TWSIC0_CLKDIV;
cafe_reg_write(cam, REG_TWSIC0, rval);
(void) cafe_reg_read(cam, REG_TWSIC1);
rval = TWSIC1_READ | ((command << TWSIC1_ADDR_SHIFT) & TWSIC1_ADDR);
cafe_reg_write(cam, REG_TWSIC1, rval);
spin_unlock_irqrestore(&cam->dev_lock, flags);
wait_event_timeout(cam->smbus_wait,
cafe_smbus_read_done(cam), CAFE_SMBUS_TIMEOUT);
spin_lock_irqsave(&cam->dev_lock, flags);
rval = cafe_reg_read(cam, REG_TWSIC1);
spin_unlock_irqrestore(&cam->dev_lock, flags);
if (rval & TWSIC1_ERROR) {
cam_err(cam, "SMBUS read (%02x/%02x) error\n", addr, command);
return -EIO;
}
if (! (rval & TWSIC1_RVALID)) {
cam_err(cam, "SMBUS read (%02x/%02x) timed out\n", addr,
command);
return -EIO;
}
*value = rval & 0xff;
return 0;
}
static int cafe_smbus_xfer(struct i2c_adapter *adapter, u16 addr,
unsigned short flags, char rw, u8 command,
int size, union i2c_smbus_data *data)
{
struct v4l2_device *v4l2_dev = i2c_get_adapdata(adapter);
struct cafe_camera *cam = to_cam(v4l2_dev);
int ret = -EINVAL;
if (size != I2C_SMBUS_BYTE_DATA) {
cam_err(cam, "funky xfer size %d\n", size);
return -EINVAL;
}
if (rw == I2C_SMBUS_WRITE)
ret = cafe_smbus_write_data(cam, addr, command, data->byte);
else if (rw == I2C_SMBUS_READ)
ret = cafe_smbus_read_data(cam, addr, command, &data->byte);
return ret;
}
static void cafe_smbus_enable_irq(struct cafe_camera *cam)
{
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_reg_set_bit(cam, REG_IRQMASK, TWSIIRQS);
spin_unlock_irqrestore(&cam->dev_lock, flags);
}
static u32 cafe_smbus_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_READ_BYTE_DATA |
I2C_FUNC_SMBUS_WRITE_BYTE_DATA;
}
static int cafe_smbus_setup(struct cafe_camera *cam)
{
struct i2c_adapter *adap = &cam->i2c_adapter;
int ret;
cafe_smbus_enable_irq(cam);
adap->owner = THIS_MODULE;
adap->algo = &cafe_smbus_algo;
strcpy(adap->name, "cafe_ccic");
adap->dev.parent = &cam->pdev->dev;
i2c_set_adapdata(adap, &cam->v4l2_dev);
ret = i2c_add_adapter(adap);
if (ret)
printk(KERN_ERR "Unable to register cafe i2c adapter\n");
return ret;
}
static void cafe_smbus_shutdown(struct cafe_camera *cam)
{
i2c_del_adapter(&cam->i2c_adapter);
}
static void cafe_ctlr_dma(struct cafe_camera *cam)
{
cafe_reg_write(cam, REG_Y0BAR, cam->dma_handles[0]);
cafe_reg_write(cam, REG_Y1BAR, cam->dma_handles[1]);
if (cam->nbufs > 2) {
cafe_reg_write(cam, REG_Y2BAR, cam->dma_handles[2]);
cafe_reg_clear_bit(cam, REG_CTRL1, C1_TWOBUFS);
}
else
cafe_reg_set_bit(cam, REG_CTRL1, C1_TWOBUFS);
cafe_reg_write(cam, REG_UBAR, 0);
}
static void cafe_ctlr_image(struct cafe_camera *cam)
{
int imgsz;
struct v4l2_pix_format *fmt = &cam->pix_format;
imgsz = ((fmt->height << IMGSZ_V_SHIFT) & IMGSZ_V_MASK) |
(fmt->bytesperline & IMGSZ_H_MASK);
cafe_reg_write(cam, REG_IMGSIZE, imgsz);
cafe_reg_write(cam, REG_IMGOFFSET, 0);
cafe_reg_write_mask(cam, REG_IMGPITCH, fmt->bytesperline,
IMGP_YP_MASK);
switch (cam->pix_format.pixelformat) {
case V4L2_PIX_FMT_YUYV:
cafe_reg_write_mask(cam, REG_CTRL0,
C0_DF_YUV|C0_YUV_PACKED|C0_YUVE_YUYV,
C0_DF_MASK);
break;
case V4L2_PIX_FMT_RGB444:
cafe_reg_write_mask(cam, REG_CTRL0,
C0_DF_RGB|C0_RGBF_444|C0_RGB4_XRGB,
C0_DF_MASK);
break;
case V4L2_PIX_FMT_RGB565:
cafe_reg_write_mask(cam, REG_CTRL0,
C0_DF_RGB|C0_RGBF_565|C0_RGB5_BGGR,
C0_DF_MASK);
break;
default:
cam_err(cam, "Unknown format %x\n", cam->pix_format.pixelformat);
break;
}
cafe_reg_write_mask(cam, REG_CTRL0, C0_SIF_HVSYNC,
C0_SIFM_MASK);
}
static int cafe_ctlr_configure(struct cafe_camera *cam)
{
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_ctlr_dma(cam);
cafe_ctlr_image(cam);
cafe_set_config_needed(cam, 0);
spin_unlock_irqrestore(&cam->dev_lock, flags);
return 0;
}
static void cafe_ctlr_irq_enable(struct cafe_camera *cam)
{
cafe_reg_write(cam, REG_IRQSTAT, FRAMEIRQS);
cafe_reg_set_bit(cam, REG_IRQMASK, FRAMEIRQS);
}
static void cafe_ctlr_irq_disable(struct cafe_camera *cam)
{
cafe_reg_clear_bit(cam, REG_IRQMASK, FRAMEIRQS);
}
static void cafe_ctlr_start(struct cafe_camera *cam)
{
cafe_reg_set_bit(cam, REG_CTRL0, C0_ENABLE);
}
static void cafe_ctlr_stop(struct cafe_camera *cam)
{
cafe_reg_clear_bit(cam, REG_CTRL0, C0_ENABLE);
}
static void cafe_ctlr_init(struct cafe_camera *cam)
{
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_reg_write(cam, 0x3038, 0x8);
cafe_reg_write(cam, 0x315c, 0x80008);
cafe_reg_write(cam, REG_GL_CSR, GCSR_SRS|GCSR_MRS);
cafe_reg_write(cam, REG_GL_CSR, GCSR_SRC|GCSR_MRC);
cafe_reg_write(cam, REG_GL_CSR, GCSR_SRC|GCSR_MRS);
spin_unlock_irqrestore(&cam->dev_lock, flags);
msleep(5);
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_reg_write(cam, REG_GL_CSR, GCSR_CCIC_EN|GCSR_SRC|GCSR_MRC);
cafe_reg_set_bit(cam, REG_GL_IMASK, GIMSK_CCIC_EN);
cafe_reg_clear_bit(cam, REG_CTRL1, C1_PWRDWN);
cafe_reg_clear_bit(cam, REG_CTRL0, C0_ENABLE);
cafe_reg_write(cam, REG_IRQMASK, 0);
cafe_reg_write_mask(cam, REG_CLKCTRL, 2, CLK_DIV_MASK);
spin_unlock_irqrestore(&cam->dev_lock, flags);
}
static void cafe_ctlr_stop_dma(struct cafe_camera *cam)
{
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_ctlr_stop(cam);
spin_unlock_irqrestore(&cam->dev_lock, flags);
mdelay(1);
wait_event_timeout(cam->iowait,
!test_bit(CF_DMA_ACTIVE, &cam->flags), HZ);
if (test_bit(CF_DMA_ACTIVE, &cam->flags))
cam_err(cam, "Timeout waiting for DMA to end\n");
spin_lock_irqsave(&cam->dev_lock, flags);
cam->state = S_IDLE;
cafe_ctlr_irq_disable(cam);
spin_unlock_irqrestore(&cam->dev_lock, flags);
}
static void cafe_ctlr_power_up(struct cafe_camera *cam)
{
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_reg_clear_bit(cam, REG_CTRL1, C1_PWRDWN);
cafe_reg_write(cam, REG_GL_FCR, GFCR_GPIO_ON);
cafe_reg_write(cam, REG_GL_GPIOR, GGPIO_OUT|GGPIO_VAL);
cafe_reg_write(cam, REG_GPR, GPR_C1EN|GPR_C0EN);
cafe_reg_write(cam, REG_GPR, GPR_C1EN|GPR_C0EN|GPR_C0);
spin_unlock_irqrestore(&cam->dev_lock, flags);
msleep(5);
}
static void cafe_ctlr_power_down(struct cafe_camera *cam)
{
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_reg_write(cam, REG_GPR, GPR_C1EN|GPR_C0EN|GPR_C1);
cafe_reg_write(cam, REG_GL_FCR, GFCR_GPIO_ON);
cafe_reg_write(cam, REG_GL_GPIOR, GGPIO_OUT);
cafe_reg_set_bit(cam, REG_CTRL1, C1_PWRDWN);
spin_unlock_irqrestore(&cam->dev_lock, flags);
}
static int __cafe_cam_reset(struct cafe_camera *cam)
{
return sensor_call(cam, core, reset, 0);
}
static int cafe_cam_init(struct cafe_camera *cam)
{
struct v4l2_dbg_chip_ident chip;
int ret;
mutex_lock(&cam->s_mutex);
if (cam->state != S_NOTREADY)
cam_warn(cam, "Cam init with device in funky state %d",
cam->state);
ret = __cafe_cam_reset(cam);
if (ret)
goto out;
chip.ident = V4L2_IDENT_NONE;
chip.match.type = V4L2_CHIP_MATCH_I2C_ADDR;
chip.match.addr = cam->sensor_addr;
ret = sensor_call(cam, core, g_chip_ident, &chip);
if (ret)
goto out;
cam->sensor_type = chip.ident;
if (cam->sensor_type != V4L2_IDENT_OV7670) {
cam_err(cam, "Unsupported sensor type 0x%x", cam->sensor_type);
ret = -EINVAL;
goto out;
}
ret = 0;
cam->state = S_IDLE;
out:
cafe_ctlr_power_down(cam);
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_cam_set_flip(struct cafe_camera *cam)
{
struct v4l2_control ctrl;
memset(&ctrl, 0, sizeof(ctrl));
ctrl.id = V4L2_CID_VFLIP;
ctrl.value = flip;
return sensor_call(cam, core, s_ctrl, &ctrl);
}
static int cafe_cam_configure(struct cafe_camera *cam)
{
struct v4l2_mbus_framefmt mbus_fmt;
int ret;
v4l2_fill_mbus_format(&mbus_fmt, &cam->pix_format, cam->mbus_code);
ret = sensor_call(cam, core, init, 0);
if (ret == 0)
ret = sensor_call(cam, video, s_mbus_fmt, &mbus_fmt);
ret += cafe_cam_set_flip(cam);
return ret;
}
static int cafe_alloc_dma_bufs(struct cafe_camera *cam, int loadtime)
{
int i;
cafe_set_config_needed(cam, 1);
if (loadtime)
cam->dma_buf_size = dma_buf_size;
else
cam->dma_buf_size = cam->pix_format.sizeimage;
if (n_dma_bufs > 3)
n_dma_bufs = 3;
cam->nbufs = 0;
for (i = 0; i < n_dma_bufs; i++) {
cam->dma_bufs[i] = dma_alloc_coherent(&cam->pdev->dev,
cam->dma_buf_size, cam->dma_handles + i,
GFP_KERNEL);
if (cam->dma_bufs[i] == NULL) {
cam_warn(cam, "Failed to allocate DMA buffer\n");
break;
}
memset(cam->dma_bufs[i], 0xcc, cam->dma_buf_size);
(cam->nbufs)++;
}
switch (cam->nbufs) {
case 1:
dma_free_coherent(&cam->pdev->dev, cam->dma_buf_size,
cam->dma_bufs[0], cam->dma_handles[0]);
cam->nbufs = 0;
case 0:
cam_err(cam, "Insufficient DMA buffers, cannot operate\n");
return -ENOMEM;
case 2:
if (n_dma_bufs > 2)
cam_warn(cam, "Will limp along with only 2 buffers\n");
break;
}
return 0;
}
static void cafe_free_dma_bufs(struct cafe_camera *cam)
{
int i;
for (i = 0; i < cam->nbufs; i++) {
dma_free_coherent(&cam->pdev->dev, cam->dma_buf_size,
cam->dma_bufs[i], cam->dma_handles[i]);
cam->dma_bufs[i] = NULL;
}
cam->nbufs = 0;
}
static ssize_t cafe_deliver_buffer(struct cafe_camera *cam,
char __user *buffer, size_t len, loff_t *pos)
{
int bufno;
unsigned long flags;
spin_lock_irqsave(&cam->dev_lock, flags);
if (cam->next_buf < 0) {
cam_err(cam, "deliver_buffer: No next buffer\n");
spin_unlock_irqrestore(&cam->dev_lock, flags);
return -EIO;
}
bufno = cam->next_buf;
clear_bit(bufno, &cam->flags);
if (++(cam->next_buf) >= cam->nbufs)
cam->next_buf = 0;
if (! test_bit(cam->next_buf, &cam->flags))
cam->next_buf = -1;
cam->specframes = 0;
spin_unlock_irqrestore(&cam->dev_lock, flags);
if (len > cam->pix_format.sizeimage)
len = cam->pix_format.sizeimage;
if (copy_to_user(buffer, cam->dma_bufs[bufno], len))
return -EFAULT;
(*pos) += len;
return len;
}
static int cafe_read_setup(struct cafe_camera *cam, enum cafe_state state)
{
int ret;
unsigned long flags;
if (cam->nbufs == 0)
if (cafe_alloc_dma_bufs(cam, 0))
return -ENOMEM;
if (cafe_needs_config(cam)) {
cafe_cam_configure(cam);
ret = cafe_ctlr_configure(cam);
if (ret)
return ret;
}
spin_lock_irqsave(&cam->dev_lock, flags);
cafe_reset_buffers(cam);
cafe_ctlr_irq_enable(cam);
cam->state = state;
cafe_ctlr_start(cam);
spin_unlock_irqrestore(&cam->dev_lock, flags);
return 0;
}
static ssize_t cafe_v4l_read(struct file *filp,
char __user *buffer, size_t len, loff_t *pos)
{
struct cafe_camera *cam = filp->private_data;
int ret = 0;
mutex_lock(&cam->s_mutex);
if (cam->state == S_SPECREAD) {
if (cam->next_buf >= 0) {
ret = cafe_deliver_buffer(cam, buffer, len, pos);
if (ret != 0)
goto out_unlock;
}
} else if (cam->state == S_FLAKED || cam->state == S_NOTREADY) {
ret = -EIO;
goto out_unlock;
} else if (cam->state != S_IDLE) {
ret = -EBUSY;
goto out_unlock;
}
if (cam->owner && cam->owner != filp) {
ret = -EBUSY;
goto out_unlock;
}
cam->owner = filp;
if (cam->state != S_SPECREAD) {
ret = cafe_read_setup(cam, S_SINGLEREAD);
if (ret)
goto out_unlock;
}
wait_event_timeout(cam->iowait, cam->next_buf >= 0, HZ);
if (cam->next_buf < 0) {
cam_err(cam, "read() operation timed out\n");
cafe_ctlr_stop_dma(cam);
ret = -EIO;
goto out_unlock;
}
ret = cafe_deliver_buffer(cam, buffer, len, pos);
out_unlock:
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_streamon(struct file *filp, void *priv,
enum v4l2_buf_type type)
{
struct cafe_camera *cam = filp->private_data;
int ret = -EINVAL;
if (type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
goto out;
mutex_lock(&cam->s_mutex);
if (cam->state != S_IDLE || cam->n_sbufs == 0)
goto out_unlock;
cam->sequence = 0;
ret = cafe_read_setup(cam, S_STREAMING);
out_unlock:
mutex_unlock(&cam->s_mutex);
out:
return ret;
}
static int cafe_vidioc_streamoff(struct file *filp, void *priv,
enum v4l2_buf_type type)
{
struct cafe_camera *cam = filp->private_data;
int ret = -EINVAL;
if (type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
goto out;
mutex_lock(&cam->s_mutex);
if (cam->state != S_STREAMING)
goto out_unlock;
cafe_ctlr_stop_dma(cam);
ret = 0;
out_unlock:
mutex_unlock(&cam->s_mutex);
out:
return ret;
}
static int cafe_setup_siobuf(struct cafe_camera *cam, int index)
{
struct cafe_sio_buffer *buf = cam->sb_bufs + index;
INIT_LIST_HEAD(&buf->list);
buf->v4lbuf.length = PAGE_ALIGN(cam->pix_format.sizeimage);
buf->buffer = vmalloc_user(buf->v4lbuf.length);
if (buf->buffer == NULL)
return -ENOMEM;
buf->mapcount = 0;
buf->cam = cam;
buf->v4lbuf.index = index;
buf->v4lbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
buf->v4lbuf.field = V4L2_FIELD_NONE;
buf->v4lbuf.memory = V4L2_MEMORY_MMAP;
buf->v4lbuf.m.offset = 2*index*buf->v4lbuf.length;
return 0;
}
static int cafe_free_sio_buffers(struct cafe_camera *cam)
{
int i;
for (i = 0; i < cam->n_sbufs; i++)
if (cam->sb_bufs[i].mapcount > 0)
return -EBUSY;
for (i = 0; i < cam->n_sbufs; i++)
vfree(cam->sb_bufs[i].buffer);
cam->n_sbufs = 0;
kfree(cam->sb_bufs);
cam->sb_bufs = NULL;
INIT_LIST_HEAD(&cam->sb_avail);
INIT_LIST_HEAD(&cam->sb_full);
return 0;
}
static int cafe_vidioc_reqbufs(struct file *filp, void *priv,
struct v4l2_requestbuffers *req)
{
struct cafe_camera *cam = filp->private_data;
int ret = 0;
if (req->memory != V4L2_MEMORY_MMAP)
return -EINVAL;
mutex_lock(&cam->s_mutex);
if (req->count == 0) {
if (cam->state == S_STREAMING)
cafe_ctlr_stop_dma(cam);
ret = cafe_free_sio_buffers (cam);
goto out;
}
if (cam->state != S_IDLE || (cam->owner && cam->owner != filp)) {
ret = -EBUSY;
goto out;
}
cam->owner = filp;
if (req->count < min_buffers)
req->count = min_buffers;
else if (req->count > max_buffers)
req->count = max_buffers;
if (cam->n_sbufs > 0) {
ret = cafe_free_sio_buffers(cam);
if (ret)
goto out;
}
cam->sb_bufs = kzalloc(req->count*sizeof(struct cafe_sio_buffer),
GFP_KERNEL);
if (cam->sb_bufs == NULL) {
ret = -ENOMEM;
goto out;
}
for (cam->n_sbufs = 0; cam->n_sbufs < req->count; (cam->n_sbufs++)) {
ret = cafe_setup_siobuf(cam, cam->n_sbufs);
if (ret)
break;
}
if (cam->n_sbufs == 0)
kfree(cam->sb_bufs);
req->count = cam->n_sbufs;
out:
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_querybuf(struct file *filp, void *priv,
struct v4l2_buffer *buf)
{
struct cafe_camera *cam = filp->private_data;
int ret = -EINVAL;
mutex_lock(&cam->s_mutex);
if (buf->index >= cam->n_sbufs)
goto out;
*buf = cam->sb_bufs[buf->index].v4lbuf;
ret = 0;
out:
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_qbuf(struct file *filp, void *priv,
struct v4l2_buffer *buf)
{
struct cafe_camera *cam = filp->private_data;
struct cafe_sio_buffer *sbuf;
int ret = -EINVAL;
unsigned long flags;
mutex_lock(&cam->s_mutex);
if (buf->index >= cam->n_sbufs)
goto out;
sbuf = cam->sb_bufs + buf->index;
if (sbuf->v4lbuf.flags & V4L2_BUF_FLAG_QUEUED) {
ret = 0;
goto out;
}
if (sbuf->v4lbuf.flags & V4L2_BUF_FLAG_DONE) {
ret = -EBUSY;
goto out;
}
sbuf->v4lbuf.flags |= V4L2_BUF_FLAG_QUEUED;
spin_lock_irqsave(&cam->dev_lock, flags);
list_add(&sbuf->list, &cam->sb_avail);
spin_unlock_irqrestore(&cam->dev_lock, flags);
ret = 0;
out:
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_dqbuf(struct file *filp, void *priv,
struct v4l2_buffer *buf)
{
struct cafe_camera *cam = filp->private_data;
struct cafe_sio_buffer *sbuf;
int ret = -EINVAL;
unsigned long flags;
mutex_lock(&cam->s_mutex);
if (cam->state != S_STREAMING)
goto out_unlock;
if (list_empty(&cam->sb_full) && filp->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
goto out_unlock;
}
while (list_empty(&cam->sb_full) && cam->state == S_STREAMING) {
mutex_unlock(&cam->s_mutex);
if (wait_event_interruptible(cam->iowait,
!list_empty(&cam->sb_full))) {
ret = -ERESTARTSYS;
goto out;
}
mutex_lock(&cam->s_mutex);
}
if (cam->state != S_STREAMING)
ret = -EINTR;
else {
spin_lock_irqsave(&cam->dev_lock, flags);
sbuf = list_entry(cam->sb_full.next,
struct cafe_sio_buffer, list);
list_del_init(&sbuf->list);
spin_unlock_irqrestore(&cam->dev_lock, flags);
sbuf->v4lbuf.flags &= ~V4L2_BUF_FLAG_DONE;
*buf = sbuf->v4lbuf;
ret = 0;
}
out_unlock:
mutex_unlock(&cam->s_mutex);
out:
return ret;
}
static void cafe_v4l_vm_open(struct vm_area_struct *vma)
{
struct cafe_sio_buffer *sbuf = vma->vm_private_data;
sbuf->mapcount++;
}
static void cafe_v4l_vm_close(struct vm_area_struct *vma)
{
struct cafe_sio_buffer *sbuf = vma->vm_private_data;
mutex_lock(&sbuf->cam->s_mutex);
sbuf->mapcount--;
if (sbuf->mapcount == 0)
sbuf->v4lbuf.flags &= ~V4L2_BUF_FLAG_MAPPED;
mutex_unlock(&sbuf->cam->s_mutex);
}
static int cafe_v4l_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct cafe_camera *cam = filp->private_data;
unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
int ret = -EINVAL;
int i;
struct cafe_sio_buffer *sbuf = NULL;
if (! (vma->vm_flags & VM_WRITE) || ! (vma->vm_flags & VM_SHARED))
return -EINVAL;
mutex_lock(&cam->s_mutex);
for (i = 0; i < cam->n_sbufs; i++)
if (cam->sb_bufs[i].v4lbuf.m.offset == offset) {
sbuf = cam->sb_bufs + i;
break;
}
if (sbuf == NULL)
goto out;
ret = remap_vmalloc_range(vma, sbuf->buffer, 0);
if (ret)
goto out;
vma->vm_flags |= VM_DONTEXPAND;
vma->vm_private_data = sbuf;
vma->vm_ops = &cafe_v4l_vm_ops;
sbuf->v4lbuf.flags |= V4L2_BUF_FLAG_MAPPED;
cafe_v4l_vm_open(vma);
ret = 0;
out:
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_v4l_open(struct file *filp)
{
struct cafe_camera *cam = video_drvdata(filp);
filp->private_data = cam;
mutex_lock(&cam->s_mutex);
if (cam->users == 0) {
cafe_ctlr_power_up(cam);
__cafe_cam_reset(cam);
cafe_set_config_needed(cam, 1);
}
(cam->users)++;
mutex_unlock(&cam->s_mutex);
return 0;
}
static int cafe_v4l_release(struct file *filp)
{
struct cafe_camera *cam = filp->private_data;
mutex_lock(&cam->s_mutex);
(cam->users)--;
if (filp == cam->owner) {
cafe_ctlr_stop_dma(cam);
cafe_free_sio_buffers(cam);
cam->owner = NULL;
}
if (cam->users == 0) {
cafe_ctlr_power_down(cam);
if (alloc_bufs_at_read)
cafe_free_dma_bufs(cam);
}
mutex_unlock(&cam->s_mutex);
return 0;
}
static unsigned int cafe_v4l_poll(struct file *filp,
struct poll_table_struct *pt)
{
struct cafe_camera *cam = filp->private_data;
poll_wait(filp, &cam->iowait, pt);
if (cam->next_buf >= 0)
return POLLIN | POLLRDNORM;
return 0;
}
static int cafe_vidioc_queryctrl(struct file *filp, void *priv,
struct v4l2_queryctrl *qc)
{
struct cafe_camera *cam = priv;
int ret;
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, core, queryctrl, qc);
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_g_ctrl(struct file *filp, void *priv,
struct v4l2_control *ctrl)
{
struct cafe_camera *cam = priv;
int ret;
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, core, g_ctrl, ctrl);
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_s_ctrl(struct file *filp, void *priv,
struct v4l2_control *ctrl)
{
struct cafe_camera *cam = priv;
int ret;
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, core, s_ctrl, ctrl);
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strcpy(cap->driver, "cafe_ccic");
strcpy(cap->card, "cafe_ccic");
cap->version = CAFE_VERSION;
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE | V4L2_CAP_STREAMING;
return 0;
}
static int cafe_vidioc_enum_fmt_vid_cap(struct file *filp,
void *priv, struct v4l2_fmtdesc *fmt)
{
if (fmt->index >= N_CAFE_FMTS)
return -EINVAL;
strlcpy(fmt->description, cafe_formats[fmt->index].desc,
sizeof(fmt->description));
fmt->pixelformat = cafe_formats[fmt->index].pixelformat;
return 0;
}
static int cafe_vidioc_try_fmt_vid_cap(struct file *filp, void *priv,
struct v4l2_format *fmt)
{
struct cafe_camera *cam = priv;
struct cafe_format_struct *f;
struct v4l2_pix_format *pix = &fmt->fmt.pix;
struct v4l2_mbus_framefmt mbus_fmt;
int ret;
f = cafe_find_format(pix->pixelformat);
pix->pixelformat = f->pixelformat;
v4l2_fill_mbus_format(&mbus_fmt, pix, f->mbus_code);
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, video, try_mbus_fmt, &mbus_fmt);
mutex_unlock(&cam->s_mutex);
v4l2_fill_pix_format(pix, &mbus_fmt);
pix->bytesperline = pix->width * f->bpp;
pix->sizeimage = pix->height * pix->bytesperline;
return ret;
}
static int cafe_vidioc_s_fmt_vid_cap(struct file *filp, void *priv,
struct v4l2_format *fmt)
{
struct cafe_camera *cam = priv;
struct cafe_format_struct *f;
int ret;
if (cam->state != S_IDLE || cam->n_sbufs > 0)
return -EBUSY;
f = cafe_find_format(fmt->fmt.pix.pixelformat);
ret = cafe_vidioc_try_fmt_vid_cap(filp, priv, fmt);
if (ret)
return ret;
mutex_lock(&cam->s_mutex);
cam->pix_format = fmt->fmt.pix;
cam->mbus_code = f->mbus_code;
ret = -ENOMEM;
if (cam->nbufs > 0 && cam->dma_buf_size < cam->pix_format.sizeimage)
cafe_free_dma_bufs(cam);
if (cam->nbufs == 0) {
if (cafe_alloc_dma_bufs(cam, 0))
goto out;
}
ret = cafe_cam_configure(cam);
if (! ret)
ret = cafe_ctlr_configure(cam);
out:
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_g_fmt_vid_cap(struct file *filp, void *priv,
struct v4l2_format *f)
{
struct cafe_camera *cam = priv;
f->fmt.pix = cam->pix_format;
return 0;
}
static int cafe_vidioc_enum_input(struct file *filp, void *priv,
struct v4l2_input *input)
{
if (input->index != 0)
return -EINVAL;
input->type = V4L2_INPUT_TYPE_CAMERA;
input->std = V4L2_STD_ALL;
strcpy(input->name, "Camera");
return 0;
}
static int cafe_vidioc_g_input(struct file *filp, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int cafe_vidioc_s_input(struct file *filp, void *priv, unsigned int i)
{
if (i != 0)
return -EINVAL;
return 0;
}
static int cafe_vidioc_s_std(struct file *filp, void *priv, v4l2_std_id *a)
{
return 0;
}
static int cafe_vidioc_g_parm(struct file *filp, void *priv,
struct v4l2_streamparm *parms)
{
struct cafe_camera *cam = priv;
int ret;
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, video, g_parm, parms);
mutex_unlock(&cam->s_mutex);
parms->parm.capture.readbuffers = n_dma_bufs;
return ret;
}
static int cafe_vidioc_s_parm(struct file *filp, void *priv,
struct v4l2_streamparm *parms)
{
struct cafe_camera *cam = priv;
int ret;
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, video, s_parm, parms);
mutex_unlock(&cam->s_mutex);
parms->parm.capture.readbuffers = n_dma_bufs;
return ret;
}
static int cafe_vidioc_g_chip_ident(struct file *file, void *priv,
struct v4l2_dbg_chip_ident *chip)
{
struct cafe_camera *cam = priv;
chip->ident = V4L2_IDENT_NONE;
chip->revision = 0;
if (v4l2_chip_match_host(&chip->match)) {
chip->ident = V4L2_IDENT_CAFE;
return 0;
}
return sensor_call(cam, core, g_chip_ident, chip);
}
static int cafe_vidioc_enum_framesizes(struct file *filp, void *priv,
struct v4l2_frmsizeenum *sizes)
{
struct cafe_camera *cam = priv;
int ret;
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, video, enum_framesizes, sizes);
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_enum_frameintervals(struct file *filp, void *priv,
struct v4l2_frmivalenum *interval)
{
struct cafe_camera *cam = priv;
int ret;
mutex_lock(&cam->s_mutex);
ret = sensor_call(cam, video, enum_frameintervals, interval);
mutex_unlock(&cam->s_mutex);
return ret;
}
static int cafe_vidioc_g_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct cafe_camera *cam = priv;
if (v4l2_chip_match_host(&reg->match)) {
reg->val = cafe_reg_read(cam, reg->reg);
reg->size = 4;
return 0;
}
return sensor_call(cam, core, g_register, reg);
}
static int cafe_vidioc_s_register(struct file *file, void *priv,
struct v4l2_dbg_register *reg)
{
struct cafe_camera *cam = priv;
if (v4l2_chip_match_host(&reg->match)) {
cafe_reg_write(cam, reg->reg, reg->val);
return 0;
}
return sensor_call(cam, core, s_register, reg);
}
static void cafe_frame_tasklet(unsigned long data)
{
struct cafe_camera *cam = (struct cafe_camera *) data;
int i;
unsigned long flags;
struct cafe_sio_buffer *sbuf;
spin_lock_irqsave(&cam->dev_lock, flags);
for (i = 0; i < cam->nbufs; i++) {
int bufno = cam->next_buf;
if (bufno < 0) {
cam_err(cam, "No valid bufs in tasklet!\n");
break;
}
if (++(cam->next_buf) >= cam->nbufs)
cam->next_buf = 0;
if (! test_bit(bufno, &cam->flags))
continue;
if (list_empty(&cam->sb_avail))
break;
clear_bit(bufno, &cam->flags);
sbuf = list_entry(cam->sb_avail.next,
struct cafe_sio_buffer, list);
spin_unlock_irqrestore(&cam->dev_lock, flags);
memcpy(sbuf->buffer, cam->dma_bufs[bufno],
cam->pix_format.sizeimage);
sbuf->v4lbuf.bytesused = cam->pix_format.sizeimage;
sbuf->v4lbuf.sequence = cam->buf_seq[bufno];
sbuf->v4lbuf.flags &= ~V4L2_BUF_FLAG_QUEUED;
sbuf->v4lbuf.flags |= V4L2_BUF_FLAG_DONE;
spin_lock_irqsave(&cam->dev_lock, flags);
list_move_tail(&sbuf->list, &cam->sb_full);
}
if (! list_empty(&cam->sb_full))
wake_up(&cam->iowait);
spin_unlock_irqrestore(&cam->dev_lock, flags);
}
static void cafe_frame_complete(struct cafe_camera *cam, int frame)
{
if (test_bit(frame, &cam->flags) && printk_ratelimit())
cam_err(cam, "Frame overrun on %d, frames lost\n", frame);
set_bit(frame, &cam->flags);
clear_bit(CF_DMA_ACTIVE, &cam->flags);
if (cam->next_buf < 0)
cam->next_buf = frame;
cam->buf_seq[frame] = ++(cam->sequence);
switch (cam->state) {
case S_SINGLEREAD:
cam->state = S_SPECREAD;
cam->specframes = 0;
wake_up(&cam->iowait);
break;
case S_SPECREAD:
if (++(cam->specframes) >= cam->nbufs) {
cafe_ctlr_stop(cam);
cafe_ctlr_irq_disable(cam);
cam->state = S_IDLE;
}
wake_up(&cam->iowait);
break;
case S_STREAMING:
tasklet_schedule(&cam->s_tasklet);
break;
default:
cam_err(cam, "Frame interrupt in non-operational state\n");
break;
}
}
static void cafe_frame_irq(struct cafe_camera *cam, unsigned int irqs)
{
unsigned int frame;
cafe_reg_write(cam, REG_IRQSTAT, FRAMEIRQS);
for (frame = 0; frame < cam->nbufs; frame++)
if (irqs & (IRQ_EOF0 << frame))
cafe_frame_complete(cam, frame);
if (irqs & (IRQ_SOF0 | IRQ_SOF1 | IRQ_SOF2))
set_bit(CF_DMA_ACTIVE, &cam->flags);
}
static irqreturn_t cafe_irq(int irq, void *data)
{
struct cafe_camera *cam = data;
unsigned int irqs;
spin_lock(&cam->dev_lock);
irqs = cafe_reg_read(cam, REG_IRQSTAT);
if ((irqs & ALLIRQS) == 0) {
spin_unlock(&cam->dev_lock);
return IRQ_NONE;
}
if (irqs & FRAMEIRQS)
cafe_frame_irq(cam, irqs);
if (irqs & TWSIIRQS) {
cafe_reg_write(cam, REG_IRQSTAT, TWSIIRQS);
wake_up(&cam->smbus_wait);
}
spin_unlock(&cam->dev_lock);
return IRQ_HANDLED;
}
static int cafe_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int ret;
struct cafe_camera *cam;
struct ov7670_config sensor_cfg = {
.use_smbus = true,
.min_width = 320,
.min_height = 240,
};
struct i2c_board_info ov7670_info = {
.type = "ov7670",
.addr = 0x42,
.platform_data = &sensor_cfg,
};
ret = -ENOMEM;
cam = kzalloc(sizeof(struct cafe_camera), GFP_KERNEL);
if (cam == NULL)
goto out;
ret = v4l2_device_register(&pdev->dev, &cam->v4l2_dev);
if (ret)
goto out_free;
mutex_init(&cam->s_mutex);
spin_lock_init(&cam->dev_lock);
cam->state = S_NOTREADY;
cafe_set_config_needed(cam, 1);
init_waitqueue_head(&cam->smbus_wait);
init_waitqueue_head(&cam->iowait);
cam->pdev = pdev;
cam->pix_format = cafe_def_pix_format;
cam->mbus_code = cafe_def_mbus_code;
INIT_LIST_HEAD(&cam->dev_list);
INIT_LIST_HEAD(&cam->sb_avail);
INIT_LIST_HEAD(&cam->sb_full);
tasklet_init(&cam->s_tasklet, cafe_frame_tasklet, (unsigned long) cam);
ret = pci_enable_device(pdev);
if (ret)
goto out_unreg;
pci_set_master(pdev);
ret = -EIO;
cam->regs = pci_iomap(pdev, 0, 0);
if (! cam->regs) {
printk(KERN_ERR "Unable to ioremap cafe-ccic regs\n");
goto out_unreg;
}
ret = request_irq(pdev->irq, cafe_irq, IRQF_SHARED, "cafe-ccic", cam);
if (ret)
goto out_iounmap;
cafe_ctlr_init(cam);
cafe_ctlr_power_up(cam);
ret = cafe_smbus_setup(cam);
if (ret)
goto out_freeirq;
if (dmi_check_system(olpc_xo1_dmi))
sensor_cfg.clock_speed = 45;
cam->sensor_addr = ov7670_info.addr;
cam->sensor = v4l2_i2c_new_subdev_board(&cam->v4l2_dev, &cam->i2c_adapter,
&ov7670_info, NULL);
if (cam->sensor == NULL) {
ret = -ENODEV;
goto out_smbus;
}
ret = cafe_cam_init(cam);
if (ret)
goto out_smbus;
mutex_lock(&cam->s_mutex);
cam->vdev = cafe_v4l_template;
cam->vdev.debug = 0;
cam->vdev.v4l2_dev = &cam->v4l2_dev;
ret = video_register_device(&cam->vdev, VFL_TYPE_GRABBER, -1);
if (ret)
goto out_unlock;
video_set_drvdata(&cam->vdev, cam);
if (!alloc_bufs_at_read) {
if (cafe_alloc_dma_bufs(cam, 1))
cam_warn(cam, "Unable to alloc DMA buffers at load"
" will try again later.");
}
mutex_unlock(&cam->s_mutex);
return 0;
out_unlock:
mutex_unlock(&cam->s_mutex);
out_smbus:
cafe_smbus_shutdown(cam);
out_freeirq:
cafe_ctlr_power_down(cam);
free_irq(pdev->irq, cam);
out_iounmap:
pci_iounmap(pdev, cam->regs);
out_free:
v4l2_device_unregister(&cam->v4l2_dev);
out_unreg:
kfree(cam);
out:
return ret;
}
static void cafe_shutdown(struct cafe_camera *cam)
{
if (cam->n_sbufs > 0)
cafe_free_sio_buffers(cam);
cafe_ctlr_stop_dma(cam);
cafe_ctlr_power_down(cam);
cafe_smbus_shutdown(cam);
cafe_free_dma_bufs(cam);
free_irq(cam->pdev->irq, cam);
pci_iounmap(cam->pdev, cam->regs);
video_unregister_device(&cam->vdev);
}
static void cafe_pci_remove(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct cafe_camera *cam = to_cam(v4l2_dev);
if (cam == NULL) {
printk(KERN_WARNING "pci_remove on unknown pdev %p\n", pdev);
return;
}
mutex_lock(&cam->s_mutex);
if (cam->users > 0)
cam_warn(cam, "Removing a device with users!\n");
cafe_shutdown(cam);
v4l2_device_unregister(&cam->v4l2_dev);
kfree(cam);
}
static int cafe_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct cafe_camera *cam = to_cam(v4l2_dev);
int ret;
enum cafe_state cstate;
ret = pci_save_state(pdev);
if (ret)
return ret;
cstate = cam->state;
cafe_ctlr_stop_dma(cam);
cafe_ctlr_power_down(cam);
pci_disable_device(pdev);
cam->state = cstate;
return 0;
}
static int cafe_pci_resume(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct cafe_camera *cam = to_cam(v4l2_dev);
int ret = 0;
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret) {
cam_warn(cam, "Unable to re-enable device on resume!\n");
return ret;
}
cafe_ctlr_init(cam);
mutex_lock(&cam->s_mutex);
if (cam->users > 0) {
cafe_ctlr_power_up(cam);
__cafe_cam_reset(cam);
} else {
cafe_ctlr_power_down(cam);
}
mutex_unlock(&cam->s_mutex);
set_bit(CF_CONFIG_NEEDED, &cam->flags);
if (cam->state == S_SPECREAD)
cam->state = S_IDLE;
else if (cam->state == S_SINGLEREAD || cam->state == S_STREAMING)
ret = cafe_read_setup(cam, cam->state);
return ret;
}
static int __init cafe_init(void)
{
int ret;
printk(KERN_NOTICE "Marvell M88ALP01 'CAFE' Camera Controller version %d\n",
CAFE_VERSION);
ret = pci_register_driver(&cafe_pci_driver);
if (ret) {
printk(KERN_ERR "Unable to register cafe_ccic driver\n");
goto out;
}
ret = 0;
out:
return ret;
}
static void __exit cafe_exit(void)
{
pci_unregister_driver(&cafe_pci_driver);
}
