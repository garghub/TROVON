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
struct hdac_device *hdev = NULL;
struct hdac_bus *bus = ebus_to_hbus(ebus);
char name[15];
int ret;
hdev = kzalloc(sizeof(*hdev), GFP_KERNEL);
if (!hdev)
return -ENOMEM;
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
snd_hdac_device_exit(hdev);
kfree(hdev);
}
