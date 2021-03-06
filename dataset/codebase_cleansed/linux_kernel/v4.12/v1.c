static void
nvkm_falcon_v1_load_imem(struct nvkm_falcon *falcon, void *data, u32 start,
u32 size, u16 tag, u8 port, bool secure)
{
u8 rem = size % 4;
u32 reg;
int i;
size -= rem;
reg = start | BIT(24) | (secure ? BIT(28) : 0);
nvkm_falcon_wr32(falcon, 0x180 + (port * 16), reg);
for (i = 0; i < size / 4; i++) {
if ((i & 0x3f) == 0)
nvkm_falcon_wr32(falcon, 0x188 + (port * 16), tag++);
nvkm_falcon_wr32(falcon, 0x184 + (port * 16), ((u32 *)data)[i]);
}
if (rem) {
u32 extra = ((u32 *)data)[i];
if ((i & 0x3f) == 0)
nvkm_falcon_wr32(falcon, 0x188 + (port * 16), tag++);
nvkm_falcon_wr32(falcon, 0x184 + (port * 16),
extra & (BIT(rem * 8) - 1));
++i;
}
for (; i & 0x3f; i++)
nvkm_falcon_wr32(falcon, 0x184 + (port * 16), 0);
}
static void
nvkm_falcon_v1_load_emem(struct nvkm_falcon *falcon, void *data, u32 start,
u32 size, u8 port)
{
u8 rem = size % 4;
int i;
size -= rem;
nvkm_falcon_wr32(falcon, 0xac0 + (port * 8), start | (0x1 << 24));
for (i = 0; i < size / 4; i++)
nvkm_falcon_wr32(falcon, 0xac4 + (port * 8), ((u32 *)data)[i]);
if (rem) {
u32 extra = ((u32 *)data)[i];
nvkm_falcon_wr32(falcon, 0xac4 + (port * 8),
extra & (BIT(rem * 8) - 1));
}
}
static void
nvkm_falcon_v1_load_dmem(struct nvkm_falcon *falcon, void *data, u32 start,
u32 size, u8 port)
{
u8 rem = size % 4;
int i;
if (start >= EMEM_START_ADDR && falcon->has_emem)
return nvkm_falcon_v1_load_emem(falcon, data,
start - EMEM_START_ADDR, size,
port);
size -= rem;
nvkm_falcon_wr32(falcon, 0x1c0 + (port * 8), start | (0x1 << 24));
for (i = 0; i < size / 4; i++)
nvkm_falcon_wr32(falcon, 0x1c4 + (port * 8), ((u32 *)data)[i]);
if (rem) {
u32 extra = ((u32 *)data)[i];
nvkm_falcon_wr32(falcon, 0x1c4 + (port * 8),
extra & (BIT(rem * 8) - 1));
}
}
static void
nvkm_falcon_v1_read_emem(struct nvkm_falcon *falcon, u32 start, u32 size,
u8 port, void *data)
{
u8 rem = size % 4;
int i;
size -= rem;
nvkm_falcon_wr32(falcon, 0xac0 + (port * 8), start | (0x1 << 25));
for (i = 0; i < size / 4; i++)
((u32 *)data)[i] = nvkm_falcon_rd32(falcon, 0xac4 + (port * 8));
if (rem) {
u32 extra = nvkm_falcon_rd32(falcon, 0xac4 + (port * 8));
for (i = size; i < size + rem; i++) {
((u8 *)data)[i] = (u8)(extra & 0xff);
extra >>= 8;
}
}
}
static void
nvkm_falcon_v1_read_dmem(struct nvkm_falcon *falcon, u32 start, u32 size,
u8 port, void *data)
{
u8 rem = size % 4;
int i;
if (start >= EMEM_START_ADDR && falcon->has_emem)
return nvkm_falcon_v1_read_emem(falcon, start - EMEM_START_ADDR,
size, port, data);
size -= rem;
nvkm_falcon_wr32(falcon, 0x1c0 + (port * 8), start | (0x1 << 25));
for (i = 0; i < size / 4; i++)
((u32 *)data)[i] = nvkm_falcon_rd32(falcon, 0x1c4 + (port * 8));
if (rem) {
u32 extra = nvkm_falcon_rd32(falcon, 0x1c4 + (port * 8));
for (i = size; i < size + rem; i++) {
((u8 *)data)[i] = (u8)(extra & 0xff);
extra >>= 8;
}
}
}
static void
nvkm_falcon_v1_bind_context(struct nvkm_falcon *falcon, struct nvkm_gpuobj *ctx)
{
u32 inst_loc;
u32 fbif;
if (ctx == NULL) {
nvkm_falcon_wr32(falcon, 0x10c, 0x0);
return;
}
switch (falcon->owner->index) {
case NVKM_ENGINE_NVENC0:
case NVKM_ENGINE_NVENC1:
case NVKM_ENGINE_NVENC2:
fbif = 0x800;
break;
case NVKM_SUBDEV_PMU:
fbif = 0xe00;
break;
default:
fbif = 0x600;
break;
}
nvkm_falcon_wr32(falcon, 0x10c, 0x1);
nvkm_falcon_wr32(falcon, fbif + 4 * FALCON_DMAIDX_UCODE, 0x4);
nvkm_falcon_wr32(falcon, fbif + 4 * FALCON_DMAIDX_VIRT, 0x0);
nvkm_falcon_wr32(falcon, fbif + 4 * FALCON_DMAIDX_PHYS_VID, 0x4);
nvkm_falcon_wr32(falcon, fbif + 4 * FALCON_DMAIDX_PHYS_SYS_COH, 0x5);
nvkm_falcon_wr32(falcon, fbif + 4 * FALCON_DMAIDX_PHYS_SYS_NCOH, 0x6);
switch (nvkm_memory_target(ctx->memory)) {
case NVKM_MEM_TARGET_VRAM: inst_loc = 0; break;
case NVKM_MEM_TARGET_HOST: inst_loc = 2; break;
case NVKM_MEM_TARGET_NCOH: inst_loc = 3; break;
default:
WARN_ON(1);
return;
}
nvkm_falcon_mask(falcon, 0x048, 0x1, 0x1);
nvkm_falcon_wr32(falcon, 0x054,
((ctx->addr >> 12) & 0xfffffff) |
(inst_loc << 28) | (1 << 30));
nvkm_falcon_mask(falcon, 0x090, 0x10000, 0x10000);
nvkm_falcon_mask(falcon, 0x0a4, 0x8, 0x8);
}
static void
nvkm_falcon_v1_set_start_addr(struct nvkm_falcon *falcon, u32 start_addr)
{
nvkm_falcon_wr32(falcon, 0x104, start_addr);
}
static void
nvkm_falcon_v1_start(struct nvkm_falcon *falcon)
{
u32 reg = nvkm_falcon_rd32(falcon, 0x100);
if (reg & BIT(6))
nvkm_falcon_wr32(falcon, 0x130, 0x2);
else
nvkm_falcon_wr32(falcon, 0x100, 0x2);
}
static int
nvkm_falcon_v1_wait_for_halt(struct nvkm_falcon *falcon, u32 ms)
{
struct nvkm_device *device = falcon->owner->device;
int ret;
ret = nvkm_wait_msec(device, ms, falcon->addr + 0x100, 0x10, 0x10);
if (ret < 0)
return ret;
return 0;
}
static int
nvkm_falcon_v1_clear_interrupt(struct nvkm_falcon *falcon, u32 mask)
{
struct nvkm_device *device = falcon->owner->device;
int ret;
nvkm_falcon_mask(falcon, 0x004, mask, mask);
ret = nvkm_wait_msec(device, 10, falcon->addr + 0x008, mask, 0x0);
if (ret < 0)
return ret;
return 0;
}
static int
falcon_v1_wait_idle(struct nvkm_falcon *falcon)
{
struct nvkm_device *device = falcon->owner->device;
int ret;
ret = nvkm_wait_msec(device, 10, falcon->addr + 0x04c, 0xffff, 0x0);
if (ret < 0)
return ret;
return 0;
}
static int
nvkm_falcon_v1_enable(struct nvkm_falcon *falcon)
{
struct nvkm_device *device = falcon->owner->device;
int ret;
ret = nvkm_wait_msec(device, 10, falcon->addr + 0x10c, 0x6, 0x0);
if (ret < 0) {
nvkm_error(falcon->user, "Falcon mem scrubbing timeout\n");
return ret;
}
ret = falcon_v1_wait_idle(falcon);
if (ret)
return ret;
nvkm_falcon_wr32(falcon, 0x010, 0xff);
return 0;
}
static void
nvkm_falcon_v1_disable(struct nvkm_falcon *falcon)
{
nvkm_falcon_wr32(falcon, 0x014, 0xff);
falcon_v1_wait_idle(falcon);
}
int
nvkm_falcon_v1_new(struct nvkm_subdev *owner, const char *name, u32 addr,
struct nvkm_falcon **pfalcon)
{
struct nvkm_falcon *falcon;
if (!(falcon = *pfalcon = kzalloc(sizeof(*falcon), GFP_KERNEL)))
return -ENOMEM;
nvkm_falcon_ctor(&nvkm_falcon_v1, owner, name, addr, falcon);
return 0;
}
