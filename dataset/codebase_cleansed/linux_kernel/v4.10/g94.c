void
g94_gpio_intr_stat(struct nvkm_gpio *gpio, u32 *hi, u32 *lo)
{
struct nvkm_device *device = gpio->subdev.device;
u32 intr0 = nvkm_rd32(device, 0x00e054);
u32 intr1 = nvkm_rd32(device, 0x00e074);
u32 stat0 = nvkm_rd32(device, 0x00e050) & intr0;
u32 stat1 = nvkm_rd32(device, 0x00e070) & intr1;
*lo = (stat1 & 0xffff0000) | (stat0 >> 16);
*hi = (stat1 << 16) | (stat0 & 0x0000ffff);
nvkm_wr32(device, 0x00e054, intr0);
nvkm_wr32(device, 0x00e074, intr1);
}
void
g94_gpio_intr_mask(struct nvkm_gpio *gpio, u32 type, u32 mask, u32 data)
{
struct nvkm_device *device = gpio->subdev.device;
u32 inte0 = nvkm_rd32(device, 0x00e050);
u32 inte1 = nvkm_rd32(device, 0x00e070);
if (type & NVKM_GPIO_LO)
inte0 = (inte0 & ~(mask << 16)) | (data << 16);
if (type & NVKM_GPIO_HI)
inte0 = (inte0 & ~(mask & 0xffff)) | (data & 0xffff);
mask >>= 16;
data >>= 16;
if (type & NVKM_GPIO_LO)
inte1 = (inte1 & ~(mask << 16)) | (data << 16);
if (type & NVKM_GPIO_HI)
inte1 = (inte1 & ~mask) | data;
nvkm_wr32(device, 0x00e050, inte0);
nvkm_wr32(device, 0x00e070, inte1);
}
int
g94_gpio_new(struct nvkm_device *device, int index, struct nvkm_gpio **pgpio)
{
return nvkm_gpio_new_(&g94_gpio, device, index, pgpio);
}
