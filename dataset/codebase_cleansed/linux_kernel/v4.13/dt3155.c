static int read_i2c_reg(void __iomem *addr, u8 index, u8 *data)
{
u32 tmp = index;
iowrite32((tmp << 17) | IIC_READ, addr + IIC_CSR2);
mmiowb();
udelay(45);
if (ioread32(addr + IIC_CSR2) & NEW_CYCLE)
return -EIO;
tmp = ioread32(addr + IIC_CSR1);
if (tmp & DIRECT_ABORT) {
iowrite32(DIRECT_ABORT, addr + IIC_CSR1);
return -EIO;
}
*data = tmp >> 24;
return 0;
}
static int write_i2c_reg(void __iomem *addr, u8 index, u8 data)
{
u32 tmp = index;
iowrite32((tmp << 17) | IIC_WRITE | data, addr + IIC_CSR2);
mmiowb();
udelay(65);
if (ioread32(addr + IIC_CSR2) & NEW_CYCLE)
return -EIO;
if (ioread32(addr + IIC_CSR1) & DIRECT_ABORT) {
iowrite32(DIRECT_ABORT, addr + IIC_CSR1);
return -EIO;
}
return 0;
}
static void write_i2c_reg_nowait(void __iomem *addr, u8 index, u8 data)
{
u32 tmp = index;
iowrite32((tmp << 17) | IIC_WRITE | data, addr + IIC_CSR2);
mmiowb();
}
static int wait_i2c_reg(void __iomem *addr)
{
if (ioread32(addr + IIC_CSR2) & NEW_CYCLE)
udelay(65);
if (ioread32(addr + IIC_CSR2) & NEW_CYCLE)
return -EIO;
if (ioread32(addr + IIC_CSR1) & DIRECT_ABORT) {
iowrite32(DIRECT_ABORT, addr + IIC_CSR1);
return -EIO;
}
return 0;
}
static int
dt3155_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers, unsigned int *num_planes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct dt3155_priv *pd = vb2_get_drv_priv(vq);
unsigned size = pd->width * pd->height;
if (vq->num_buffers + *nbuffers < 2)
*nbuffers = 2 - vq->num_buffers;
if (*num_planes)
return sizes[0] < size ? -EINVAL : 0;
*num_planes = 1;
sizes[0] = size;
return 0;
}
static int dt3155_buf_prepare(struct vb2_buffer *vb)
{
struct dt3155_priv *pd = vb2_get_drv_priv(vb->vb2_queue);
vb2_set_plane_payload(vb, 0, pd->width * pd->height);
return 0;
}
static int dt3155_start_streaming(struct vb2_queue *q, unsigned count)
{
struct dt3155_priv *pd = vb2_get_drv_priv(q);
struct vb2_buffer *vb = &pd->curr_buf->vb2_buf;
dma_addr_t dma_addr;
pd->sequence = 0;
dma_addr = vb2_dma_contig_plane_dma_addr(vb, 0);
iowrite32(dma_addr, pd->regs + EVEN_DMA_START);
iowrite32(dma_addr + pd->width, pd->regs + ODD_DMA_START);
iowrite32(pd->width, pd->regs + EVEN_DMA_STRIDE);
iowrite32(pd->width, pd->regs + ODD_DMA_STRIDE);
iowrite32(FLD_START_EN | FLD_END_ODD_EN | FLD_START |
FLD_END_EVEN | FLD_END_ODD, pd->regs + INT_CSR);
iowrite32(FIFO_EN | SRST | FLD_CRPT_ODD | FLD_CRPT_EVEN |
FLD_DN_ODD | FLD_DN_EVEN | CAP_CONT_EVEN | CAP_CONT_ODD,
pd->regs + CSR1);
wait_i2c_reg(pd->regs);
write_i2c_reg(pd->regs, CONFIG, pd->config);
write_i2c_reg(pd->regs, EVEN_CSR, CSR_ERROR | CSR_DONE);
write_i2c_reg(pd->regs, ODD_CSR, CSR_ERROR | CSR_DONE);
write_i2c_reg(pd->regs, CSR2, pd->csr2 | BUSY_EVEN | BUSY_ODD);
return 0;
}
static void dt3155_stop_streaming(struct vb2_queue *q)
{
struct dt3155_priv *pd = vb2_get_drv_priv(q);
struct vb2_buffer *vb;
spin_lock_irq(&pd->lock);
write_i2c_reg_nowait(pd->regs, CSR2, pd->csr2);
iowrite32(FIFO_EN | SRST | FLD_CRPT_ODD | FLD_CRPT_EVEN |
FLD_DN_ODD | FLD_DN_EVEN, pd->regs + CSR1);
iowrite32(FLD_START | FLD_END_EVEN | FLD_END_ODD, pd->regs + INT_CSR);
spin_unlock_irq(&pd->lock);
msleep(45);
spin_lock_irq(&pd->lock);
if (pd->curr_buf) {
vb2_buffer_done(&pd->curr_buf->vb2_buf, VB2_BUF_STATE_ERROR);
pd->curr_buf = NULL;
}
while (!list_empty(&pd->dmaq)) {
vb = list_first_entry(&pd->dmaq, typeof(*vb), done_entry);
list_del(&vb->done_entry);
vb2_buffer_done(vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irq(&pd->lock);
}
static void dt3155_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct dt3155_priv *pd = vb2_get_drv_priv(vb->vb2_queue);
spin_lock_irq(&pd->lock);
if (pd->curr_buf)
list_add_tail(&vb->done_entry, &pd->dmaq);
else
pd->curr_buf = vbuf;
spin_unlock_irq(&pd->lock);
}
static irqreturn_t dt3155_irq_handler_even(int irq, void *dev_id)
{
struct dt3155_priv *ipd = dev_id;
struct vb2_buffer *ivb;
dma_addr_t dma_addr;
u32 tmp;
tmp = ioread32(ipd->regs + INT_CSR) & (FLD_START | FLD_END_ODD);
if (!tmp)
return IRQ_NONE;
if ((tmp & FLD_START) && !(tmp & FLD_END_ODD)) {
iowrite32(FLD_START_EN | FLD_END_ODD_EN | FLD_START,
ipd->regs + INT_CSR);
return IRQ_HANDLED;
}
tmp = ioread32(ipd->regs + CSR1) & (FLD_CRPT_EVEN | FLD_CRPT_ODD);
if (tmp) {
iowrite32(FIFO_EN | SRST | FLD_CRPT_ODD | FLD_CRPT_EVEN |
FLD_DN_ODD | FLD_DN_EVEN |
CAP_CONT_EVEN | CAP_CONT_ODD,
ipd->regs + CSR1);
mmiowb();
}
spin_lock(&ipd->lock);
if (ipd->curr_buf && !list_empty(&ipd->dmaq)) {
ipd->curr_buf->vb2_buf.timestamp = ktime_get_ns();
ipd->curr_buf->sequence = ipd->sequence++;
ipd->curr_buf->field = V4L2_FIELD_NONE;
vb2_buffer_done(&ipd->curr_buf->vb2_buf, VB2_BUF_STATE_DONE);
ivb = list_first_entry(&ipd->dmaq, typeof(*ivb), done_entry);
list_del(&ivb->done_entry);
ipd->curr_buf = to_vb2_v4l2_buffer(ivb);
dma_addr = vb2_dma_contig_plane_dma_addr(ivb, 0);
iowrite32(dma_addr, ipd->regs + EVEN_DMA_START);
iowrite32(dma_addr + ipd->width, ipd->regs + ODD_DMA_START);
iowrite32(ipd->width, ipd->regs + EVEN_DMA_STRIDE);
iowrite32(ipd->width, ipd->regs + ODD_DMA_STRIDE);
mmiowb();
}
iowrite32(FLD_START_EN | FLD_END_ODD_EN | FLD_START |
FLD_END_EVEN | FLD_END_ODD, ipd->regs + INT_CSR);
spin_unlock(&ipd->lock);
return IRQ_HANDLED;
}
static int dt3155_querycap(struct file *filp, void *p,
struct v4l2_capability *cap)
{
struct dt3155_priv *pd = video_drvdata(filp);
strcpy(cap->driver, DT3155_NAME);
strcpy(cap->card, DT3155_NAME " frame grabber");
sprintf(cap->bus_info, "PCI:%s", pci_name(pd->pdev));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int dt3155_enum_fmt_vid_cap(struct file *filp,
void *p, struct v4l2_fmtdesc *f)
{
if (f->index)
return -EINVAL;
f->pixelformat = V4L2_PIX_FMT_GREY;
strcpy(f->description, "8-bit Greyscale");
return 0;
}
static int dt3155_fmt_vid_cap(struct file *filp, void *p, struct v4l2_format *f)
{
struct dt3155_priv *pd = video_drvdata(filp);
f->fmt.pix.width = pd->width;
f->fmt.pix.height = pd->height;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_GREY;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.bytesperline = f->fmt.pix.width;
f->fmt.pix.sizeimage = f->fmt.pix.width * f->fmt.pix.height;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int dt3155_g_std(struct file *filp, void *p, v4l2_std_id *norm)
{
struct dt3155_priv *pd = video_drvdata(filp);
*norm = pd->std;
return 0;
}
static int dt3155_s_std(struct file *filp, void *p, v4l2_std_id norm)
{
struct dt3155_priv *pd = video_drvdata(filp);
if (pd->std == norm)
return 0;
if (vb2_is_busy(&pd->vidq))
return -EBUSY;
pd->std = norm;
if (pd->std & V4L2_STD_525_60) {
pd->csr2 = VT_60HZ;
pd->width = 640;
pd->height = 480;
} else {
pd->csr2 = VT_50HZ;
pd->width = 768;
pd->height = 576;
}
return 0;
}
static int dt3155_enum_input(struct file *filp, void *p,
struct v4l2_input *input)
{
if (input->index > 3)
return -EINVAL;
if (input->index)
snprintf(input->name, sizeof(input->name), "VID%d",
input->index);
else
strlcpy(input->name, "J2/VID0", sizeof(input->name));
input->type = V4L2_INPUT_TYPE_CAMERA;
input->std = V4L2_STD_ALL;
input->status = 0;
return 0;
}
static int dt3155_g_input(struct file *filp, void *p, unsigned int *i)
{
struct dt3155_priv *pd = video_drvdata(filp);
*i = pd->input;
return 0;
}
static int dt3155_s_input(struct file *filp, void *p, unsigned int i)
{
struct dt3155_priv *pd = video_drvdata(filp);
if (i > 3)
return -EINVAL;
pd->input = i;
write_i2c_reg(pd->regs, AD_ADDR, AD_CMD_REG);
write_i2c_reg(pd->regs, AD_CMD, (i << 6) | (i << 4) | SYNC_LVL_3);
return 0;
}
static int dt3155_init_board(struct dt3155_priv *pd)
{
struct pci_dev *pdev = pd->pdev;
int i;
u8 tmp = 0;
pci_set_master(pdev);
iowrite32(ADDR_ERR_ODD | ADDR_ERR_EVEN | FLD_CRPT_ODD | FLD_CRPT_EVEN |
FLD_DN_ODD | FLD_DN_EVEN, pd->regs + CSR1);
mmiowb();
msleep(20);
iowrite32(FIFO_EN | SRST, pd->regs + CSR1);
mmiowb();
iowrite32(0xEEEEEE01, pd->regs + EVEN_PIXEL_FMT);
iowrite32(0xEEEEEE01, pd->regs + ODD_PIXEL_FMT);
iowrite32(0x00000020, pd->regs + FIFO_TRIGER);
iowrite32(0x00000103, pd->regs + XFER_MODE);
iowrite32(0, pd->regs + RETRY_WAIT_CNT);
iowrite32(0, pd->regs + INT_CSR);
iowrite32(1, pd->regs + EVEN_FLD_MASK);
iowrite32(1, pd->regs + ODD_FLD_MASK);
iowrite32(0, pd->regs + MASK_LENGTH);
iowrite32(0x0005007C, pd->regs + FIFO_FLAG_CNT);
iowrite32(0x01010101, pd->regs + IIC_CLK_DUR);
mmiowb();
read_i2c_reg(pd->regs, DT_ID, &tmp);
if (tmp != DT3155_ID)
return -ENODEV;
write_i2c_reg(pd->regs, AD_ADDR, 0);
for (i = 0; i < 256; i++)
write_i2c_reg(pd->regs, AD_LUT, i);
write_i2c_reg(pd->regs, AD_ADDR, AD_CMD_REG);
write_i2c_reg(pd->regs, AD_CMD, VIDEO_CNL_1 | SYNC_CNL_1 | SYNC_LVL_3);
write_i2c_reg(pd->regs, AD_ADDR, AD_POS_REF);
write_i2c_reg(pd->regs, AD_CMD, 34);
write_i2c_reg(pd->regs, AD_ADDR, AD_NEG_REF);
write_i2c_reg(pd->regs, AD_CMD, 0);
write_i2c_reg(pd->regs, CONFIG, pd->config | PM_LUT_PGM);
for (i = 0; i < 256; i++) {
write_i2c_reg(pd->regs, PM_LUT_ADDR, i);
write_i2c_reg(pd->regs, PM_LUT_DATA, i);
}
write_i2c_reg(pd->regs, CONFIG, pd->config | PM_LUT_PGM | PM_LUT_SEL);
for (i = 0; i < 256; i++) {
write_i2c_reg(pd->regs, PM_LUT_ADDR, i);
write_i2c_reg(pd->regs, PM_LUT_DATA, i);
}
write_i2c_reg(pd->regs, CONFIG, pd->config);
write_i2c_reg(pd->regs, AD_ADDR, AD_CMD_REG);
write_i2c_reg(pd->regs, AD_CMD, VIDEO_CNL_1 | SYNC_CNL_1 | SYNC_LVL_3);
iowrite32(FLD_START | FLD_END_EVEN | FLD_END_ODD,
pd->regs + INT_CSR);
return 0;
}
static int dt3155_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int err;
struct dt3155_priv *pd;
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err)
return -ENODEV;
pd = devm_kzalloc(&pdev->dev, sizeof(*pd), GFP_KERNEL);
if (!pd)
return -ENOMEM;
err = v4l2_device_register(&pdev->dev, &pd->v4l2_dev);
if (err)
return err;
pd->vdev = dt3155_vdev;
pd->vdev.v4l2_dev = &pd->v4l2_dev;
video_set_drvdata(&pd->vdev, pd);
pd->pdev = pdev;
pd->std = V4L2_STD_625_50;
pd->csr2 = VT_50HZ;
pd->width = 768;
pd->height = 576;
INIT_LIST_HEAD(&pd->dmaq);
mutex_init(&pd->mux);
pd->vdev.lock = &pd->mux;
pd->vidq.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
pd->vidq.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
pd->vidq.io_modes = VB2_MMAP | VB2_DMABUF | VB2_READ;
pd->vidq.ops = &q_ops;
pd->vidq.mem_ops = &vb2_dma_contig_memops;
pd->vidq.drv_priv = pd;
pd->vidq.min_buffers_needed = 2;
pd->vidq.gfp_flags = GFP_DMA32;
pd->vidq.lock = &pd->mux;
pd->vidq.dev = &pdev->dev;
pd->vdev.queue = &pd->vidq;
err = vb2_queue_init(&pd->vidq);
if (err < 0)
goto err_v4l2_dev_unreg;
spin_lock_init(&pd->lock);
pd->config = ACQ_MODE_EVEN;
err = pci_enable_device(pdev);
if (err)
goto err_v4l2_dev_unreg;
err = pci_request_region(pdev, 0, pci_name(pdev));
if (err)
goto err_pci_disable;
pd->regs = pci_iomap(pdev, 0, pci_resource_len(pd->pdev, 0));
if (!pd->regs) {
err = -ENOMEM;
goto err_free_reg;
}
err = dt3155_init_board(pd);
if (err)
goto err_iounmap;
err = request_irq(pd->pdev->irq, dt3155_irq_handler_even,
IRQF_SHARED, DT3155_NAME, pd);
if (err)
goto err_iounmap;
err = video_register_device(&pd->vdev, VFL_TYPE_GRABBER, -1);
if (err)
goto err_free_irq;
dev_info(&pdev->dev, "/dev/video%i is ready\n", pd->vdev.minor);
return 0;
err_free_irq:
free_irq(pd->pdev->irq, pd);
err_iounmap:
pci_iounmap(pdev, pd->regs);
err_free_reg:
pci_release_region(pdev, 0);
err_pci_disable:
pci_disable_device(pdev);
err_v4l2_dev_unreg:
v4l2_device_unregister(&pd->v4l2_dev);
return err;
}
static void dt3155_remove(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pdev);
struct dt3155_priv *pd = container_of(v4l2_dev, struct dt3155_priv,
v4l2_dev);
video_unregister_device(&pd->vdev);
free_irq(pd->pdev->irq, pd);
vb2_queue_release(&pd->vidq);
v4l2_device_unregister(&pd->v4l2_dev);
pci_iounmap(pdev, pd->regs);
pci_release_region(pdev, 0);
pci_disable_device(pdev);
}
