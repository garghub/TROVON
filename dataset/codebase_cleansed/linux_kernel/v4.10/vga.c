u8
nvkm_rdport(struct nvkm_device *device, int head, u16 port)
{
if (device->card_type >= NV_50)
return nvkm_rd08(device, 0x601000 + port);
if (port == 0x03c0 || port == 0x03c1 ||
port == 0x03c2 || port == 0x03da ||
port == 0x03d4 || port == 0x03d5)
return nvkm_rd08(device, 0x601000 + (head * 0x2000) + port);
if (port == 0x03c2 || port == 0x03cc ||
port == 0x03c4 || port == 0x03c5 ||
port == 0x03ce || port == 0x03cf) {
if (device->card_type < NV_40)
head = 0;
return nvkm_rd08(device, 0x0c0000 + (head * 0x2000) + port);
}
return 0x00;
}
void
nvkm_wrport(struct nvkm_device *device, int head, u16 port, u8 data)
{
if (device->card_type >= NV_50)
nvkm_wr08(device, 0x601000 + port, data);
else
if (port == 0x03c0 || port == 0x03c1 ||
port == 0x03c2 || port == 0x03da ||
port == 0x03d4 || port == 0x03d5)
nvkm_wr08(device, 0x601000 + (head * 0x2000) + port, data);
else
if (port == 0x03c2 || port == 0x03cc ||
port == 0x03c4 || port == 0x03c5 ||
port == 0x03ce || port == 0x03cf) {
if (device->card_type < NV_40)
head = 0;
nvkm_wr08(device, 0x0c0000 + (head * 0x2000) + port, data);
}
}
u8
nvkm_rdvgas(struct nvkm_device *device, int head, u8 index)
{
nvkm_wrport(device, head, 0x03c4, index);
return nvkm_rdport(device, head, 0x03c5);
}
void
nvkm_wrvgas(struct nvkm_device *device, int head, u8 index, u8 value)
{
nvkm_wrport(device, head, 0x03c4, index);
nvkm_wrport(device, head, 0x03c5, value);
}
u8
nvkm_rdvgag(struct nvkm_device *device, int head, u8 index)
{
nvkm_wrport(device, head, 0x03ce, index);
return nvkm_rdport(device, head, 0x03cf);
}
void
nvkm_wrvgag(struct nvkm_device *device, int head, u8 index, u8 value)
{
nvkm_wrport(device, head, 0x03ce, index);
nvkm_wrport(device, head, 0x03cf, value);
}
u8
nvkm_rdvgac(struct nvkm_device *device, int head, u8 index)
{
nvkm_wrport(device, head, 0x03d4, index);
return nvkm_rdport(device, head, 0x03d5);
}
void
nvkm_wrvgac(struct nvkm_device *device, int head, u8 index, u8 value)
{
nvkm_wrport(device, head, 0x03d4, index);
nvkm_wrport(device, head, 0x03d5, value);
}
u8
nvkm_rdvgai(struct nvkm_device *device, int head, u16 port, u8 index)
{
if (port == 0x03c4) return nvkm_rdvgas(device, head, index);
if (port == 0x03ce) return nvkm_rdvgag(device, head, index);
if (port == 0x03d4) return nvkm_rdvgac(device, head, index);
return 0x00;
}
void
nvkm_wrvgai(struct nvkm_device *device, int head, u16 port, u8 index, u8 value)
{
if (port == 0x03c4) nvkm_wrvgas(device, head, index, value);
else if (port == 0x03ce) nvkm_wrvgag(device, head, index, value);
else if (port == 0x03d4) nvkm_wrvgac(device, head, index, value);
}
bool
nvkm_lockvgac(struct nvkm_device *device, bool lock)
{
bool locked = !nvkm_rdvgac(device, 0, 0x1f);
u8 data = lock ? 0x99 : 0x57;
if (device->card_type < NV_50)
nvkm_wrvgac(device, 0, 0x1f, data);
else
nvkm_wrvgac(device, 0, 0x3f, data);
if (device->chipset == 0x11) {
if (!(nvkm_rd32(device, 0x001084) & 0x10000000))
nvkm_wrvgac(device, 1, 0x1f, data);
}
return locked;
}
u8
nvkm_rdvgaowner(struct nvkm_device *device)
{
if (device->card_type < NV_50) {
if (device->chipset == 0x11) {
u32 tied = nvkm_rd32(device, 0x001084) & 0x10000000;
if (tied == 0) {
u8 slA = nvkm_rdvgac(device, 0, 0x28) & 0x80;
u8 tvA = nvkm_rdvgac(device, 0, 0x33) & 0x01;
u8 slB = nvkm_rdvgac(device, 1, 0x28) & 0x80;
u8 tvB = nvkm_rdvgac(device, 1, 0x33) & 0x01;
if (slA && !tvA) return 0x00;
if (slB && !tvB) return 0x03;
if (slA) return 0x00;
if (slB) return 0x03;
return 0x00;
}
return 0x04;
}
return nvkm_rdvgac(device, 0, 0x44);
}
return 0x00;
}
void
nvkm_wrvgaowner(struct nvkm_device *device, u8 select)
{
if (device->card_type < NV_50) {
u8 owner = (select == 1) ? 3 : select;
if (device->chipset == 0x11) {
nvkm_rdvgac(device, 0, 0x1f);
nvkm_rdvgac(device, 1, 0x1f);
}
nvkm_wrvgac(device, 0, 0x44, owner);
if (device->chipset == 0x11) {
nvkm_wrvgac(device, 0, 0x2e, owner);
nvkm_wrvgac(device, 0, 0x2e, owner);
}
}
}
