static inline struct saa7134_go7007 *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct saa7134_go7007, sd);
}
static int gpio_write(struct saa7134_dev *dev, u8 addr, u16 data)
{
saa_writeb(SAA7134_GPIO_GPMODE0, 0xff);
saa_writeb(SAA7134_GPIO_GPSTATUS0, addr);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_ADDR);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
saa_writeb(SAA7134_GPIO_GPSTATUS0, data & 0xff);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_WRITE);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
saa_writeb(SAA7134_GPIO_GPSTATUS0, data >> 8);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_WRITE);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
return 0;
}
static int gpio_read(struct saa7134_dev *dev, u8 addr, u16 *data)
{
saa_writeb(SAA7134_GPIO_GPMODE0, 0xff);
saa_writeb(SAA7134_GPIO_GPSTATUS0, addr);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_ADDR);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
saa_writeb(SAA7134_GPIO_GPMODE0, 0x00);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_READ);
saa_clearb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
saa_setb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
*data = saa_readb(SAA7134_GPIO_GPSTATUS0);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_READ);
saa_clearb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
saa_setb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
*data |= saa_readb(SAA7134_GPIO_GPSTATUS0) << 8;
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
return 0;
}
static int saa7134_go7007_interface_reset(struct go7007 *go)
{
struct saa7134_go7007 *saa = go->hpi_context;
struct saa7134_dev *dev = saa->dev;
u16 intr_val, intr_data;
int count = 20;
saa_clearb(SAA7134_TS_PARALLEL, 0x80);
saa_writeb(SAA7134_GPIO_GPMODE2, 0xa4);
saa_writeb(SAA7134_GPIO_GPMODE0, 0xff);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_REQ1);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_RESET);
msleep(1);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_REQ1);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_REQ2);
msleep(10);
saa_clearb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
saa_setb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
saa_readb(SAA7134_GPIO_GPSTATUS2);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_REQ1);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_REQ2);
do {
saa_clearb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
saa_setb(SAA7134_GPIO_GPMODE3, SAA7134_GPIO_GPRESCAN);
saa_readb(SAA7134_GPIO_GPSTATUS2);
} while (--count > 0);
if (go7007_read_interrupt(go, &intr_val, &intr_data) < 0 ||
(intr_val & ~0x1) != 0x55aa) {
pr_err("saa7134-go7007: unable to reset the GO7007\n");
return -1;
}
return 0;
}
static int saa7134_go7007_write_interrupt(struct go7007 *go, int addr, int data)
{
struct saa7134_go7007 *saa = go->hpi_context;
struct saa7134_dev *dev = saa->dev;
int i;
u16 status_reg;
#ifdef GO7007_HPI_DEBUG
pr_debug("saa7134-go7007: WriteInterrupt: %04x %04x\n", addr, data);
#endif
for (i = 0; i < 100; ++i) {
gpio_read(dev, HPI_ADDR_INTR_STATUS, &status_reg);
if (!(status_reg & 0x0010))
break;
msleep(10);
}
if (i == 100) {
pr_err("saa7134-go7007: device is hung, status reg = 0x%04x\n",
status_reg);
return -1;
}
gpio_write(dev, HPI_ADDR_INTR_WR_PARAM, data);
gpio_write(dev, HPI_ADDR_INTR_WR_INDEX, addr);
return 0;
}
static int saa7134_go7007_read_interrupt(struct go7007 *go)
{
struct saa7134_go7007 *saa = go->hpi_context;
struct saa7134_dev *dev = saa->dev;
go->interrupt_available = 1;
gpio_read(dev, HPI_ADDR_INTR_RET_VALUE, &go->interrupt_value);
gpio_read(dev, HPI_ADDR_INTR_RET_DATA, &go->interrupt_data);
#ifdef GO7007_HPI_DEBUG
pr_debug("saa7134-go7007: ReadInterrupt: %04x %04x\n",
go->interrupt_value, go->interrupt_data);
#endif
return 0;
}
static void saa7134_go7007_irq_ts_done(struct saa7134_dev *dev,
unsigned long status)
{
struct go7007 *go = video_get_drvdata(dev->empress_dev);
struct saa7134_go7007 *saa = go->hpi_context;
if (!vb2_is_streaming(&go->vidq))
return;
if (0 != (status & 0x000f0000))
pr_debug("saa7134-go7007: irq: lost %ld\n",
(status >> 16) & 0x0f);
if (status & 0x100000) {
dma_sync_single_for_cpu(&dev->pci->dev,
saa->bottom_dma, PAGE_SIZE, DMA_FROM_DEVICE);
go7007_parse_video_stream(go, saa->bottom, PAGE_SIZE);
saa_writel(SAA7134_RS_BA2(5), saa->bottom_dma);
} else {
dma_sync_single_for_cpu(&dev->pci->dev,
saa->top_dma, PAGE_SIZE, DMA_FROM_DEVICE);
go7007_parse_video_stream(go, saa->top, PAGE_SIZE);
saa_writel(SAA7134_RS_BA1(5), saa->top_dma);
}
}
static int saa7134_go7007_stream_start(struct go7007 *go)
{
struct saa7134_go7007 *saa = go->hpi_context;
struct saa7134_dev *dev = saa->dev;
saa->top_dma = dma_map_page(&dev->pci->dev, virt_to_page(saa->top),
0, PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&dev->pci->dev, saa->top_dma))
return -ENOMEM;
saa->bottom_dma = dma_map_page(&dev->pci->dev,
virt_to_page(saa->bottom),
0, PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&dev->pci->dev, saa->bottom_dma)) {
dma_unmap_page(&dev->pci->dev, saa->top_dma, PAGE_SIZE,
DMA_FROM_DEVICE);
return -ENOMEM;
}
saa_writel(SAA7134_VIDEO_PORT_CTRL0 >> 2, 0xA300B000);
saa_writel(SAA7134_VIDEO_PORT_CTRL4 >> 2, 0x40000200);
saa_writeb(SAA7134_GPIO_GPMODE0, 0xff);
saa_writeb(SAA7134_GPIO_GPSTATUS0, HPI_ADDR_VIDEO_BUFFER);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_ADDR);
saa_writeb(SAA7134_GPIO_GPMODE0, 0x00);
saa_writeb(SAA7134_TS_PARALLEL, 0xe6);
saa_setb(SAA7134_TS_SERIAL1, 0x01);
saa_clearb(SAA7134_TS_SERIAL1, 0x01);
saa_writeb(SAA7134_TS_PARALLEL_SERIAL, 128 - 1);
saa_writeb(SAA7134_TS_DMA0, ((PAGE_SIZE >> 7) - 1) & 0xff);
saa_writeb(SAA7134_TS_DMA1, (PAGE_SIZE >> 15) & 0xff);
saa_writeb(SAA7134_TS_DMA2, (PAGE_SIZE >> 31) & 0x3f);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_VIDEO);
saa_writel(SAA7134_RS_BA1(5), saa->top_dma);
saa_writel(SAA7134_RS_BA2(5), saa->bottom_dma);
saa_writel(SAA7134_RS_PITCH(5), 128);
saa_writel(SAA7134_RS_CONTROL(5), SAA7134_RS_CONTROL_BURST_MAX);
saa_setl(SAA7134_MAIN_CTRL, SAA7134_MAIN_CTRL_TE5);
saa_setl(SAA7134_IRQ1,
SAA7134_IRQ1_INTE_RA2_1 | SAA7134_IRQ1_INTE_RA2_0);
return 0;
}
static int saa7134_go7007_stream_stop(struct go7007 *go)
{
struct saa7134_go7007 *saa = go->hpi_context;
struct saa7134_dev *dev;
if (!saa)
return -EINVAL;
dev = saa->dev;
if (!dev)
return -EINVAL;
saa_clearl(SAA7134_MAIN_CTRL, SAA7134_MAIN_CTRL_TE5);
saa_clearl(SAA7134_IRQ1,
SAA7134_IRQ1_INTE_RA2_1 | SAA7134_IRQ1_INTE_RA2_0);
saa_clearb(SAA7134_TS_PARALLEL, 0x80);
dma_unmap_page(&dev->pci->dev, saa->top_dma, PAGE_SIZE,
DMA_FROM_DEVICE);
dma_unmap_page(&dev->pci->dev, saa->bottom_dma, PAGE_SIZE,
DMA_FROM_DEVICE);
return 0;
}
static int saa7134_go7007_send_firmware(struct go7007 *go, u8 *data, int len)
{
struct saa7134_go7007 *saa = go->hpi_context;
struct saa7134_dev *dev = saa->dev;
u16 status_reg;
int i;
#ifdef GO7007_HPI_DEBUG
pr_debug("saa7134-go7007: DownloadBuffer sending %d bytes\n", len);
#endif
while (len > 0) {
i = len > 64 ? 64 : len;
saa_writeb(SAA7134_GPIO_GPMODE0, 0xff);
saa_writeb(SAA7134_GPIO_GPSTATUS0, HPI_ADDR_INIT_BUFFER);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_ADDR);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
while (i-- > 0) {
saa_writeb(SAA7134_GPIO_GPSTATUS0, *data);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_WRITE);
saa_writeb(SAA7134_GPIO_GPSTATUS2, GPIO_COMMAND_IDLE);
++data;
--len;
}
for (i = 0; i < 100; ++i) {
gpio_read(dev, HPI_ADDR_INTR_STATUS, &status_reg);
if (!(status_reg & 0x0002))
break;
}
if (i == 100) {
pr_err("saa7134-go7007: device is hung, status reg = 0x%04x\n",
status_reg);
return -1;
}
}
return 0;
}
static int saa7134_go7007_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
#if 0
struct saa7134_go7007 *saa = to_state(sd);
struct saa7134_dev *dev = saa->dev;
return saa7134_s_std_internal(dev, NULL, norm);
#else
return 0;
#endif
}
static int saa7134_go7007_init(struct saa7134_dev *dev)
{
struct go7007 *go;
struct saa7134_go7007 *saa;
struct v4l2_subdev *sd;
pr_debug("saa7134-go7007: probing new SAA713X board\n");
go = go7007_alloc(&board_voyager, &dev->pci->dev);
if (go == NULL)
return -ENOMEM;
saa = kzalloc(sizeof(struct saa7134_go7007), GFP_KERNEL);
if (saa == NULL) {
kfree(go);
return -ENOMEM;
}
go->board_id = GO7007_BOARDID_PCI_VOYAGER;
snprintf(go->bus_info, sizeof(go->bus_info), "PCI:%s", pci_name(dev->pci));
strlcpy(go->name, saa7134_boards[dev->board].name, sizeof(go->name));
go->hpi_ops = &saa7134_go7007_hpi_ops;
go->hpi_context = saa;
saa->dev = dev;
sd = &saa->sd;
v4l2_subdev_init(sd, &saa7134_go7007_sd_ops);
v4l2_set_subdevdata(sd, saa);
strncpy(sd->name, "saa7134-go7007", sizeof(sd->name));
saa->top = (u8 *)get_zeroed_page(GFP_KERNEL);
if (!saa->top)
goto allocfail;
saa->bottom = (u8 *)get_zeroed_page(GFP_KERNEL);
if (!saa->bottom)
goto allocfail;
if (go7007_boot_encoder(go, go->board_info->flags &
GO7007_BOARD_USE_ONBOARD_I2C) < 0)
goto allocfail;
if (go7007_register_encoder(go, go->board_info->num_i2c_devs) < 0)
goto allocfail;
if (v4l2_device_register_subdev(&go->v4l2_dev, sd) < 0)
pr_info("saa7134-go7007: register subdev failed\n");
dev->empress_dev = &go->vdev;
go->status = STATUS_ONLINE;
return 0;
allocfail:
if (saa->top)
free_page((unsigned long)saa->top);
if (saa->bottom)
free_page((unsigned long)saa->bottom);
kfree(saa);
kfree(go);
return -ENOMEM;
}
static int saa7134_go7007_fini(struct saa7134_dev *dev)
{
struct go7007 *go;
struct saa7134_go7007 *saa;
if (NULL == dev->empress_dev)
return 0;
go = video_get_drvdata(dev->empress_dev);
if (go->audio_enabled)
go7007_snd_remove(go);
saa = go->hpi_context;
go->status = STATUS_SHUTDOWN;
free_page((unsigned long)saa->top);
free_page((unsigned long)saa->bottom);
v4l2_device_unregister_subdev(&saa->sd);
kfree(saa);
video_unregister_device(&go->vdev);
v4l2_device_put(&go->v4l2_dev);
dev->empress_dev = NULL;
return 0;
}
static int __init saa7134_go7007_mod_init(void)
{
return saa7134_ts_register(&saa7134_go7007_ops);
}
static void __exit saa7134_go7007_mod_cleanup(void)
{
saa7134_ts_unregister(&saa7134_go7007_ops);
}
