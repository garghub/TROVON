static inline void pdregw(void *data, u32 val)
{
struct Hydra *hydra = (struct Hydra *)data;
writel(val, &hydra->CachePD);
}
static inline u32 pdregr(void *data)
{
struct Hydra *hydra = (struct Hydra *)data;
return readl(&hydra->CachePD);
}
static void hydra_bit_setscl(void *data, int state)
{
u32 val = pdregr(data);
if (state)
val &= ~HYDRA_SCLK_OE;
else {
val &= ~HYDRA_SCLK;
val |= HYDRA_SCLK_OE;
}
pdregw(data, val);
}
static void hydra_bit_setsda(void *data, int state)
{
u32 val = pdregr(data);
if (state)
val &= ~HYDRA_SDAT_OE;
else {
val &= ~HYDRA_SDAT;
val |= HYDRA_SDAT_OE;
}
pdregw(data, val);
}
static int hydra_bit_getscl(void *data)
{
return (pdregr(data) & HYDRA_SCLK) != 0;
}
static int hydra_bit_getsda(void *data)
{
return (pdregr(data) & HYDRA_SDAT) != 0;
}
static int __devinit hydra_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
unsigned long base = pci_resource_start(dev, 0);
int res;
if (!request_mem_region(base+offsetof(struct Hydra, CachePD), 4,
hydra_adap.name))
return -EBUSY;
hydra_bit_data.data = pci_ioremap_bar(dev, 0);
if (hydra_bit_data.data == NULL) {
release_mem_region(base+offsetof(struct Hydra, CachePD), 4);
return -ENODEV;
}
pdregw(hydra_bit_data.data, 0);
hydra_adap.dev.parent = &dev->dev;
res = i2c_bit_add_bus(&hydra_adap);
if (res < 0) {
iounmap(hydra_bit_data.data);
release_mem_region(base+offsetof(struct Hydra, CachePD), 4);
return res;
}
return 0;
}
static void __devexit hydra_remove(struct pci_dev *dev)
{
pdregw(hydra_bit_data.data, 0);
i2c_del_adapter(&hydra_adap);
iounmap(hydra_bit_data.data);
release_mem_region(pci_resource_start(dev, 0)+
offsetof(struct Hydra, CachePD), 4);
}
