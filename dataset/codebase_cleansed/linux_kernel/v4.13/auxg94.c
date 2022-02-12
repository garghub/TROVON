static void
g94_i2c_aux_fini(struct g94_i2c_aux *aux)
{
struct nvkm_device *device = aux->base.pad->i2c->subdev.device;
nvkm_mask(device, 0x00e4e4 + (aux->ch * 0x50), 0x00310000, 0x00000000);
}
static int
g94_i2c_aux_init(struct g94_i2c_aux *aux)
{
struct nvkm_device *device = aux->base.pad->i2c->subdev.device;
const u32 unksel = 1;
const u32 ureq = unksel ? 0x00100000 : 0x00200000;
const u32 urep = unksel ? 0x01000000 : 0x02000000;
u32 ctrl, timeout;
timeout = 1000;
do {
ctrl = nvkm_rd32(device, 0x00e4e4 + (aux->ch * 0x50));
udelay(1);
if (!timeout--) {
AUX_ERR(&aux->base, "begin idle timeout %08x", ctrl);
return -EBUSY;
}
} while (ctrl & 0x03010000);
nvkm_mask(device, 0x00e4e4 + (aux->ch * 0x50), 0x00300000, ureq);
timeout = 1000;
do {
ctrl = nvkm_rd32(device, 0x00e4e4 + (aux->ch * 0x50));
udelay(1);
if (!timeout--) {
AUX_ERR(&aux->base, "magic wait %08x", ctrl);
g94_i2c_aux_fini(aux);
return -EBUSY;
}
} while ((ctrl & 0x03000000) != urep);
return 0;
}
int
g94_i2c_aux_xfer(struct nvkm_i2c_aux *obj, bool retry,
u8 type, u32 addr, u8 *data, u8 *size)
{
struct g94_i2c_aux *aux = g94_i2c_aux(obj);
struct nvkm_device *device = aux->base.pad->i2c->subdev.device;
const u32 base = aux->ch * 0x50;
u32 ctrl, stat, timeout, retries = 0;
u32 xbuf[4] = {};
int ret, i;
AUX_TRACE(&aux->base, "%d: %08x %d", type, addr, *size);
ret = g94_i2c_aux_init(aux);
if (ret < 0)
goto out;
stat = nvkm_rd32(device, 0x00e4e8 + base);
if (!(stat & 0x10000000)) {
AUX_TRACE(&aux->base, "sink not detected");
ret = -ENXIO;
goto out;
}
if (!(type & 1)) {
memcpy(xbuf, data, *size);
for (i = 0; i < 16; i += 4) {
AUX_TRACE(&aux->base, "wr %08x", xbuf[i / 4]);
nvkm_wr32(device, 0x00e4c0 + base + i, xbuf[i / 4]);
}
}
ctrl = nvkm_rd32(device, 0x00e4e4 + base);
ctrl &= ~0x0001f1ff;
ctrl |= type << 12;
ctrl |= (*size ? (*size - 1) : 0x00000100);
nvkm_wr32(device, 0x00e4e0 + base, addr);
do {
nvkm_wr32(device, 0x00e4e4 + base, 0x80000000 | ctrl);
nvkm_wr32(device, 0x00e4e4 + base, 0x00000000 | ctrl);
if (retries)
udelay(400);
nvkm_wr32(device, 0x00e4e4 + base, 0x00010000 | ctrl);
timeout = 1000;
do {
ctrl = nvkm_rd32(device, 0x00e4e4 + base);
udelay(1);
if (!timeout--) {
AUX_ERR(&aux->base, "timeout %08x", ctrl);
ret = -EIO;
goto out;
}
} while (ctrl & 0x00010000);
ret = 0;
stat = nvkm_mask(device, 0x00e4e8 + base, 0, 0);
if ((stat & 0x000f0000) == 0x00080000 ||
(stat & 0x000f0000) == 0x00020000)
ret = 1;
if ((stat & 0x00000100))
ret = -ETIMEDOUT;
if ((stat & 0x00000e00))
ret = -EIO;
AUX_TRACE(&aux->base, "%02d %08x %08x", retries, ctrl, stat);
} while (ret && retry && retries++ < 32);
if (type & 1) {
for (i = 0; i < 16; i += 4) {
xbuf[i / 4] = nvkm_rd32(device, 0x00e4d0 + base + i);
AUX_TRACE(&aux->base, "rd %08x", xbuf[i / 4]);
}
memcpy(data, xbuf, *size);
*size = stat & 0x0000001f;
}
out:
g94_i2c_aux_fini(aux);
return ret < 0 ? ret : (stat & 0x000f0000) >> 16;
}
int
g94_i2c_aux_new_(const struct nvkm_i2c_aux_func *func,
struct nvkm_i2c_pad *pad, int index, u8 drive,
struct nvkm_i2c_aux **paux)
{
struct g94_i2c_aux *aux;
if (!(aux = kzalloc(sizeof(*aux), GFP_KERNEL)))
return -ENOMEM;
*paux = &aux->base;
nvkm_i2c_aux_ctor(func, pad, index, &aux->base);
aux->ch = drive;
aux->base.intr = 1 << aux->ch;
return 0;
}
int
g94_i2c_aux_new(struct nvkm_i2c_pad *pad, int index, u8 drive,
struct nvkm_i2c_aux **paux)
{
return g94_i2c_aux_new_(&g94_i2c_aux, pad, index, drive, paux);
}
