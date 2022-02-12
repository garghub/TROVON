static void hdac_ext_writel(u32 value, u32 __iomem *addr)
{
writel(value, addr);
}
static u32 hdac_ext_readl(u32 __iomem *addr)
{
return readl(addr);
}
static void hdac_ext_writew(u16 value, u16 __iomem *addr)
{
writew(value, addr);
}
static u16 hdac_ext_readw(u16 __iomem *addr)
{
return readw(addr);
}
static void hdac_ext_writeb(u8 value, u8 __iomem *addr)
{
writeb(value, addr);
}
static u8 hdac_ext_readb(u8 __iomem *addr)
{
return readb(addr);
}
static int hdac_ext_dma_alloc_pages(struct hdac_bus *bus, int type,
size_t size, struct snd_dma_buffer *buf)
{
return snd_dma_alloc_pages(type, bus->dev, size, buf);
}
static void hdac_ext_dma_free_pages(struct hdac_bus *bus, struct snd_dma_buffer *buf)
{
snd_dma_free_pages(buf);
}
int snd_hdac_ext_bus_init(struct hdac_ext_bus *ebus, struct device *dev,
const struct hdac_bus_ops *ops,
const struct hdac_io_ops *io_ops)
{
int ret;
static int idx;
if (io_ops == NULL)
io_ops = &hdac_ext_default_io;
ret = snd_hdac_bus_init(&ebus->bus, dev, ops, io_ops);
if (ret < 0)
return ret;
INIT_LIST_HEAD(&ebus->hlink_list);
ebus->idx = idx++;
return 0;
}
void snd_hdac_ext_bus_exit(struct hdac_ext_bus *ebus)
{
snd_hdac_bus_exit(&ebus->bus);
WARN_ON(!list_empty(&ebus->hlink_list));
}
static void default_release(struct device *dev)
{
snd_hdac_ext_bus_device_exit(container_of(dev, struct hdac_device, dev));
}
int snd_hdac_ext_bus_device_init(struct hdac_ext_bus *ebus, int addr)
{
struct hdac_ext_device *edev;
struct hdac_device *hdev = NULL;
struct hdac_bus *bus = ebus_to_hbus(ebus);
char name[15];
int ret;
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev)
return -ENOMEM;
hdev = &edev->hdac;
snprintf(name, sizeof(name), "ehdaudio%dD%d", ebus->idx, addr);
ret = snd_hdac_device_init(hdev, bus, name, addr);
if (ret < 0) {
dev_err(bus->dev, "device init failed for hdac device\n");
return ret;
}
hdev->type = HDA_DEV_ASOC;
hdev->dev.release = default_release;
ret = snd_hdac_device_register(hdev);
if (ret) {
dev_err(bus->dev, "failed to register hdac device\n");
snd_hdac_ext_bus_device_exit(hdev);
return ret;
}
return 0;
}
void snd_hdac_ext_bus_device_exit(struct hdac_device *hdev)
{
struct hdac_ext_device *edev = to_ehdac_device(hdev);
snd_hdac_device_exit(hdev);
kfree(edev);
}
void snd_hdac_ext_bus_device_remove(struct hdac_ext_bus *ebus)
{
struct hdac_device *codec, *__codec;
list_for_each_entry_safe(codec, __codec, &ebus->bus.codec_list, list) {
snd_hdac_device_unregister(codec);
put_device(&codec->dev);
}
}
static inline struct hdac_ext_driver *get_edrv(struct device *dev)
{
struct hdac_driver *hdrv = drv_to_hdac_driver(dev->driver);
struct hdac_ext_driver *edrv = to_ehdac_driver(hdrv);
return edrv;
}
static inline struct hdac_ext_device *get_edev(struct device *dev)
{
struct hdac_device *hdev = dev_to_hdac_dev(dev);
struct hdac_ext_device *edev = to_ehdac_device(hdev);
return edev;
}
static int hda_ext_drv_probe(struct device *dev)
{
return (get_edrv(dev))->probe(get_edev(dev));
}
static int hdac_ext_drv_remove(struct device *dev)
{
return (get_edrv(dev))->remove(get_edev(dev));
}
static void hdac_ext_drv_shutdown(struct device *dev)
{
return (get_edrv(dev))->shutdown(get_edev(dev));
}
int snd_hda_ext_driver_register(struct hdac_ext_driver *drv)
{
drv->hdac.type = HDA_DEV_ASOC;
drv->hdac.driver.bus = &snd_hda_bus_type;
if (drv->probe)
drv->hdac.driver.probe = hda_ext_drv_probe;
if (drv->remove)
drv->hdac.driver.remove = hdac_ext_drv_remove;
if (drv->shutdown)
drv->hdac.driver.shutdown = hdac_ext_drv_shutdown;
return driver_register(&drv->hdac.driver);
}
void snd_hda_ext_driver_unregister(struct hdac_ext_driver *drv)
{
driver_unregister(&drv->hdac.driver);
}
