static struct nouveau_channel *
nv04_graph_channel(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
int chid = dev_priv->engine.fifo.channels;
if (nv_rd32(dev, NV04_PGRAPH_CTX_CONTROL) & 0x00010000)
chid = nv_rd32(dev, NV04_PGRAPH_CTX_USER) >> 24;
if (chid >= dev_priv->engine.fifo.channels)
return NULL;
return dev_priv->channels.ptr[chid];
}
static uint32_t *ctx_reg(struct graph_state *ctx, uint32_t reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(nv04_graph_ctx_regs); i++) {
if (nv04_graph_ctx_regs[i] == reg)
return &ctx->nv04[i];
}
return NULL;
}
static int
nv04_graph_load_context(struct nouveau_channel *chan)
{
struct graph_state *pgraph_ctx = chan->engctx[NVOBJ_ENGINE_GR];
struct drm_device *dev = chan->dev;
uint32_t tmp;
int i;
for (i = 0; i < ARRAY_SIZE(nv04_graph_ctx_regs); i++)
nv_wr32(dev, nv04_graph_ctx_regs[i], pgraph_ctx->nv04[i]);
nv_wr32(dev, NV04_PGRAPH_CTX_CONTROL, 0x10010100);
tmp = nv_rd32(dev, NV04_PGRAPH_CTX_USER) & 0x00ffffff;
nv_wr32(dev, NV04_PGRAPH_CTX_USER, tmp | chan->id << 24);
tmp = nv_rd32(dev, NV04_PGRAPH_FFINTFC_ST2);
nv_wr32(dev, NV04_PGRAPH_FFINTFC_ST2, tmp & 0x000fffff);
return 0;
}
static int
nv04_graph_unload_context(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_channel *chan = NULL;
struct graph_state *ctx;
uint32_t tmp;
int i;
chan = nv04_graph_channel(dev);
if (!chan)
return 0;
ctx = chan->engctx[NVOBJ_ENGINE_GR];
for (i = 0; i < ARRAY_SIZE(nv04_graph_ctx_regs); i++)
ctx->nv04[i] = nv_rd32(dev, nv04_graph_ctx_regs[i]);
nv_wr32(dev, NV04_PGRAPH_CTX_CONTROL, 0x10000000);
tmp = nv_rd32(dev, NV04_PGRAPH_CTX_USER) & 0x00ffffff;
tmp |= (dev_priv->engine.fifo.channels - 1) << 24;
nv_wr32(dev, NV04_PGRAPH_CTX_USER, tmp);
return 0;
}
static int
nv04_graph_context_new(struct nouveau_channel *chan, int engine)
{
struct graph_state *pgraph_ctx;
NV_DEBUG(chan->dev, "nv04_graph_context_create %d\n", chan->id);
pgraph_ctx = kzalloc(sizeof(*pgraph_ctx), GFP_KERNEL);
if (pgraph_ctx == NULL)
return -ENOMEM;
*ctx_reg(pgraph_ctx, NV04_PGRAPH_DEBUG_3) = 0xfad4ff31;
chan->engctx[engine] = pgraph_ctx;
return 0;
}
static void
nv04_graph_context_del(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct graph_state *pgraph_ctx = chan->engctx[engine];
unsigned long flags;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000000);
if (nv04_graph_channel(dev) == chan)
nv04_graph_unload_context(dev);
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000001);
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
kfree(pgraph_ctx);
chan->engctx[engine] = NULL;
}
int
nv04_graph_object_new(struct nouveau_channel *chan, int engine,
u32 handle, u16 class)
{
struct drm_device *dev = chan->dev;
struct nouveau_gpuobj *obj = NULL;
int ret;
ret = nouveau_gpuobj_new(dev, chan, 16, 16, NVOBJ_FLAG_ZERO_FREE, &obj);
if (ret)
return ret;
obj->engine = 1;
obj->class = class;
#ifdef __BIG_ENDIAN
nv_wo32(obj, 0x00, 0x00080000 | class);
#else
nv_wo32(obj, 0x00, class);
#endif
nv_wo32(obj, 0x04, 0x00000000);
nv_wo32(obj, 0x08, 0x00000000);
nv_wo32(obj, 0x0c, 0x00000000);
ret = nouveau_ramht_insert(chan, handle, obj);
nouveau_gpuobj_ref(NULL, &obj);
return ret;
}
static int
nv04_graph_init(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t tmp;
nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) &
~NV_PMC_ENABLE_PGRAPH);
nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) |
NV_PMC_ENABLE_PGRAPH);
nv_wr32(dev, NV03_PGRAPH_INTR, 0xFFFFFFFF);
nv_wr32(dev, NV03_PGRAPH_INTR_EN, 0xFFFFFFFF);
nv_wr32(dev, NV04_PGRAPH_VALID1, 0);
nv_wr32(dev, NV04_PGRAPH_VALID2, 0);
nv_wr32(dev, NV04_PGRAPH_DEBUG_0, 0x1231c000);
nv_wr32(dev, NV04_PGRAPH_DEBUG_1, 0x72111100);
nv_wr32(dev, NV04_PGRAPH_DEBUG_2, 0x11d5f071);
nv_wr32(dev, NV04_PGRAPH_DEBUG_3, 0xf0d4ff31);
nv_wr32(dev, NV04_PGRAPH_STATE , 0xFFFFFFFF);
nv_wr32(dev, NV04_PGRAPH_CTX_CONTROL , 0x10000100);
tmp = nv_rd32(dev, NV04_PGRAPH_CTX_USER) & 0x00ffffff;
tmp |= (dev_priv->engine.fifo.channels - 1) << 24;
nv_wr32(dev, NV04_PGRAPH_CTX_USER, tmp);
nv_wr32(dev, NV04_PGRAPH_PATTERN_SHAPE, 0x00000000);
nv_wr32(dev, NV04_PGRAPH_BETA_AND , 0xFFFFFFFF);
return 0;
}
static int
nv04_graph_fini(struct drm_device *dev, int engine, bool suspend)
{
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000000);
if (!nv_wait(dev, NV04_PGRAPH_STATUS, ~0, 0) && suspend) {
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000001);
return -EBUSY;
}
nv04_graph_unload_context(dev);
nv_wr32(dev, NV03_PGRAPH_INTR_EN, 0x00000000);
return 0;
}
static int
nv04_graph_mthd_set_ref(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
atomic_set(&chan->fence.last_sequence_irq, data);
return 0;
}
int
nv04_graph_mthd_page_flip(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
struct drm_device *dev = chan->dev;
struct nouveau_page_flip_state s;
if (!nouveau_finish_page_flip(chan, &s))
nv_set_crtc_base(dev, s.crtc,
s.offset + s.y * s.pitch + s.x * s.bpp / 8);
return 0;
}
static void
nv04_graph_set_ctx1(struct nouveau_channel *chan, u32 mask, u32 value)
{
struct drm_device *dev = chan->dev;
u32 instance = (nv_rd32(dev, NV04_PGRAPH_CTX_SWITCH4) & 0xffff) << 4;
int subc = (nv_rd32(dev, NV04_PGRAPH_TRAPPED_ADDR) >> 13) & 0x7;
u32 tmp;
tmp = nv_ri32(dev, instance);
tmp &= ~mask;
tmp |= value;
nv_wi32(dev, instance, tmp);
nv_wr32(dev, NV04_PGRAPH_CTX_SWITCH1, tmp);
nv_wr32(dev, NV04_PGRAPH_CTX_CACHE1 + (subc<<2), tmp);
}
static void
nv04_graph_set_ctx_val(struct nouveau_channel *chan, u32 mask, u32 value)
{
struct drm_device *dev = chan->dev;
u32 instance = (nv_rd32(dev, NV04_PGRAPH_CTX_SWITCH4) & 0xffff) << 4;
u32 tmp, ctx1;
int class, op, valid = 1;
ctx1 = nv_ri32(dev, instance);
class = ctx1 & 0xff;
op = (ctx1 >> 15) & 7;
tmp = nv_ri32(dev, instance + 0xc);
tmp &= ~mask;
tmp |= value;
nv_wi32(dev, instance + 0xc, tmp);
if (!(tmp & 0x02000000))
valid = 0;
if ((class == 0x1f || class == 0x48) && !(tmp & 0x04000000))
valid = 0;
switch (op) {
case 0:
case 3:
break;
case 1:
if (!(tmp & 0x18000000))
valid = 0;
break;
case 2:
if (!(tmp & 0x20000000))
valid = 0;
break;
case 4:
case 5:
if (!(tmp & 0x40000000))
valid = 0;
break;
}
nv04_graph_set_ctx1(chan, 0x01000000, valid << 24);
}
static int
nv04_graph_mthd_set_operation(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
if (data > 5)
return 1;
if (data > 2 && class < 0x40)
return 1;
nv04_graph_set_ctx1(chan, 0x00038000, data << 15);
nv04_graph_set_ctx_val(chan, 0, 0);
return 0;
}
static int
nv04_graph_mthd_surf3d_clip_h(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
uint32_t min = data & 0xffff, max;
uint32_t w = data >> 16;
if (min & 0x8000)
return 1;
if (w & 0x8000)
w |= 0xffff0000;
max = min + w;
max &= 0x3ffff;
nv_wr32(chan->dev, 0x40053c, min);
nv_wr32(chan->dev, 0x400544, max);
return 0;
}
static int
nv04_graph_mthd_surf3d_clip_v(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
uint32_t min = data & 0xffff, max;
uint32_t w = data >> 16;
if (min & 0x8000)
return 1;
if (w & 0x8000)
w |= 0xffff0000;
max = min + w;
max &= 0x3ffff;
nv_wr32(chan->dev, 0x400540, min);
nv_wr32(chan->dev, 0x400548, max);
return 0;
}
static int
nv04_graph_mthd_bind_surf2d(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx1(chan, 0x00004000, 0);
nv04_graph_set_ctx_val(chan, 0x02000000, 0);
return 0;
case 0x42:
nv04_graph_set_ctx1(chan, 0x00004000, 0);
nv04_graph_set_ctx_val(chan, 0x02000000, 0x02000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_surf2d_swzsurf(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx1(chan, 0x00004000, 0);
nv04_graph_set_ctx_val(chan, 0x02000000, 0);
return 0;
case 0x42:
nv04_graph_set_ctx1(chan, 0x00004000, 0);
nv04_graph_set_ctx_val(chan, 0x02000000, 0x02000000);
return 0;
case 0x52:
nv04_graph_set_ctx1(chan, 0x00004000, 0x00004000);
nv04_graph_set_ctx_val(chan, 0x02000000, 0x02000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_nv01_patt(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x08000000, 0);
return 0;
case 0x18:
nv04_graph_set_ctx_val(chan, 0x08000000, 0x08000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_nv04_patt(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x08000000, 0);
return 0;
case 0x44:
nv04_graph_set_ctx_val(chan, 0x08000000, 0x08000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_rop(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x10000000, 0);
return 0;
case 0x43:
nv04_graph_set_ctx_val(chan, 0x10000000, 0x10000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_beta1(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x20000000, 0);
return 0;
case 0x12:
nv04_graph_set_ctx_val(chan, 0x20000000, 0x20000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_beta4(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x40000000, 0);
return 0;
case 0x72:
nv04_graph_set_ctx_val(chan, 0x40000000, 0x40000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_surf_dst(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x02000000, 0);
return 0;
case 0x58:
nv04_graph_set_ctx_val(chan, 0x02000000, 0x02000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_surf_src(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x04000000, 0);
return 0;
case 0x59:
nv04_graph_set_ctx_val(chan, 0x04000000, 0x04000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_surf_color(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x02000000, 0);
return 0;
case 0x5a:
nv04_graph_set_ctx_val(chan, 0x02000000, 0x02000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_surf_zeta(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx_val(chan, 0x04000000, 0);
return 0;
case 0x5b:
nv04_graph_set_ctx_val(chan, 0x04000000, 0x04000000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_clip(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx1(chan, 0x2000, 0);
return 0;
case 0x19:
nv04_graph_set_ctx1(chan, 0x2000, 0x2000);
return 0;
}
return 1;
}
static int
nv04_graph_mthd_bind_chroma(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
switch (nv_ri32(chan->dev, data << 4) & 0xff) {
case 0x30:
nv04_graph_set_ctx1(chan, 0x1000, 0);
return 0;
case 0x57:
nv04_graph_set_ctx1(chan, 0x1000, 0x1000);
return 0;
}
return 1;
}
static void
nv04_graph_context_switch(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_channel *chan = NULL;
int chid;
nouveau_wait_for_idle(dev);
nv04_graph_unload_context(dev);
chid = dev_priv->engine.fifo.channel_id(dev);
chan = dev_priv->channels.ptr[chid];
if (chan)
nv04_graph_load_context(chan);
}
static void
nv04_graph_isr(struct drm_device *dev)
{
u32 stat;
while ((stat = nv_rd32(dev, NV03_PGRAPH_INTR))) {
u32 nsource = nv_rd32(dev, NV03_PGRAPH_NSOURCE);
u32 nstatus = nv_rd32(dev, NV03_PGRAPH_NSTATUS);
u32 addr = nv_rd32(dev, NV04_PGRAPH_TRAPPED_ADDR);
u32 chid = (addr & 0x0f000000) >> 24;
u32 subc = (addr & 0x0000e000) >> 13;
u32 mthd = (addr & 0x00001ffc);
u32 data = nv_rd32(dev, NV04_PGRAPH_TRAPPED_DATA);
u32 class = nv_rd32(dev, 0x400180 + subc * 4) & 0xff;
u32 show = stat;
if (stat & NV_PGRAPH_INTR_NOTIFY) {
if (nsource & NV03_PGRAPH_NSOURCE_ILLEGAL_MTHD) {
if (!nouveau_gpuobj_mthd_call2(dev, chid, class, mthd, data))
show &= ~NV_PGRAPH_INTR_NOTIFY;
}
}
if (stat & NV_PGRAPH_INTR_CONTEXT_SWITCH) {
nv_wr32(dev, NV03_PGRAPH_INTR, NV_PGRAPH_INTR_CONTEXT_SWITCH);
stat &= ~NV_PGRAPH_INTR_CONTEXT_SWITCH;
show &= ~NV_PGRAPH_INTR_CONTEXT_SWITCH;
nv04_graph_context_switch(dev);
}
nv_wr32(dev, NV03_PGRAPH_INTR, stat);
nv_wr32(dev, NV04_PGRAPH_FIFO, 0x00000001);
if (show && nouveau_ratelimit()) {
NV_INFO(dev, "PGRAPH -");
nouveau_bitfield_print(nv04_graph_intr, show);
printk(" nsource:");
nouveau_bitfield_print(nv04_graph_nsource, nsource);
printk(" nstatus:");
nouveau_bitfield_print(nv04_graph_nstatus, nstatus);
printk("\n");
NV_INFO(dev, "PGRAPH - ch %d/%d class 0x%04x "
"mthd 0x%04x data 0x%08x\n",
chid, subc, class, mthd, data);
}
}
}
static void
nv04_graph_destroy(struct drm_device *dev, int engine)
{
struct nv04_graph_engine *pgraph = nv_engine(dev, engine);
nouveau_irq_unregister(dev, 12);
NVOBJ_ENGINE_DEL(dev, GR);
kfree(pgraph);
}
int
nv04_graph_create(struct drm_device *dev)
{
struct nv04_graph_engine *pgraph;
pgraph = kzalloc(sizeof(*pgraph), GFP_KERNEL);
if (!pgraph)
return -ENOMEM;
pgraph->base.destroy = nv04_graph_destroy;
pgraph->base.init = nv04_graph_init;
pgraph->base.fini = nv04_graph_fini;
pgraph->base.context_new = nv04_graph_context_new;
pgraph->base.context_del = nv04_graph_context_del;
pgraph->base.object_new = nv04_graph_object_new;
NVOBJ_ENGINE_ADD(dev, GR, &pgraph->base);
nouveau_irq_register(dev, 12, nv04_graph_isr);
NVOBJ_CLASS(dev, 0x0038, GR);
NVOBJ_CLASS(dev, 0x0039, GR);
NVOBJ_CLASS(dev, 0x004b, GR);
NVOBJ_MTHD (dev, 0x004b, 0x0184, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x004b, 0x0188, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x004b, 0x018c, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x004b, 0x0190, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x004b, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x004a, GR);
NVOBJ_MTHD (dev, 0x004a, 0x0188, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x004a, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x004a, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x004a, 0x0194, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x004a, 0x0198, nv04_graph_mthd_bind_surf2d);
NVOBJ_MTHD (dev, 0x004a, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x001f, GR);
NVOBJ_MTHD (dev, 0x001f, 0x0184, nv04_graph_mthd_bind_chroma);
NVOBJ_MTHD (dev, 0x001f, 0x0188, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x001f, 0x018c, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x001f, 0x0190, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x001f, 0x0194, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x001f, 0x0198, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x001f, 0x019c, nv04_graph_mthd_bind_surf_src);
NVOBJ_MTHD (dev, 0x001f, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x005f, GR);
NVOBJ_MTHD (dev, 0x005f, 0x0184, nv04_graph_mthd_bind_chroma);
NVOBJ_MTHD (dev, 0x005f, 0x0188, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x005f, 0x018c, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x005f, 0x0190, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x005f, 0x0194, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x005f, 0x0198, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x005f, 0x019c, nv04_graph_mthd_bind_surf2d);
NVOBJ_MTHD (dev, 0x005f, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0060, GR);
NVOBJ_MTHD (dev, 0x0060, 0x0188, nv04_graph_mthd_bind_chroma);
NVOBJ_MTHD (dev, 0x0060, 0x018c, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x0060, 0x0190, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x0060, 0x0194, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x0060, 0x0198, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x0060, 0x019c, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x0060, 0x01a0, nv04_graph_mthd_bind_surf2d_swzsurf);
NVOBJ_MTHD (dev, 0x0060, 0x03e4, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0064, GR);
NVOBJ_CLASS(dev, 0x0021, GR);
NVOBJ_MTHD (dev, 0x0021, 0x0184, nv04_graph_mthd_bind_chroma);
NVOBJ_MTHD (dev, 0x0021, 0x0188, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x0021, 0x018c, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x0021, 0x0190, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x0021, 0x0194, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x0021, 0x0198, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x0021, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0061, GR);
NVOBJ_MTHD (dev, 0x0061, 0x0184, nv04_graph_mthd_bind_chroma);
NVOBJ_MTHD (dev, 0x0061, 0x0188, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x0061, 0x018c, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x0061, 0x0190, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x0061, 0x0194, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x0061, 0x0198, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x0061, 0x019c, nv04_graph_mthd_bind_surf2d);
NVOBJ_MTHD (dev, 0x0061, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0065, GR);
NVOBJ_CLASS(dev, 0x0036, GR);
NVOBJ_MTHD (dev, 0x0036, 0x0184, nv04_graph_mthd_bind_chroma);
NVOBJ_MTHD (dev, 0x0036, 0x0188, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x0036, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x0036, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x0036, 0x0194, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x0036, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0076, GR);
NVOBJ_MTHD (dev, 0x0076, 0x0184, nv04_graph_mthd_bind_chroma);
NVOBJ_MTHD (dev, 0x0076, 0x0188, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x0076, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x0076, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x0076, 0x0194, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x0076, 0x0198, nv04_graph_mthd_bind_surf2d);
NVOBJ_MTHD (dev, 0x0076, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0066, GR);
NVOBJ_CLASS(dev, 0x0037, GR);
NVOBJ_MTHD (dev, 0x0037, 0x0188, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x0037, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x0037, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x0037, 0x0194, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x0037, 0x0304, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0077, GR);
NVOBJ_MTHD (dev, 0x0077, 0x0188, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x0077, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x0077, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x0077, 0x0194, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x0077, 0x0198, nv04_graph_mthd_bind_surf2d_swzsurf);
NVOBJ_MTHD (dev, 0x0077, 0x0304, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x0030, GR);
NVOBJ_CLASS(dev, 0x0042, GR);
NVOBJ_CLASS(dev, 0x0043, GR);
NVOBJ_CLASS(dev, 0x0012, GR);
NVOBJ_CLASS(dev, 0x0072, GR);
NVOBJ_CLASS(dev, 0x0019, GR);
NVOBJ_CLASS(dev, 0x0018, GR);
NVOBJ_CLASS(dev, 0x0044, GR);
NVOBJ_CLASS(dev, 0x0052, GR);
NVOBJ_CLASS(dev, 0x0053, GR);
NVOBJ_MTHD (dev, 0x0053, 0x02f8, nv04_graph_mthd_surf3d_clip_h);
NVOBJ_MTHD (dev, 0x0053, 0x02fc, nv04_graph_mthd_surf3d_clip_v);
NVOBJ_CLASS(dev, 0x0048, GR);
NVOBJ_MTHD (dev, 0x0048, 0x0188, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x0048, 0x018c, nv04_graph_mthd_bind_surf_color);
NVOBJ_MTHD (dev, 0x0048, 0x0190, nv04_graph_mthd_bind_surf_zeta);
NVOBJ_CLASS(dev, 0x0054, GR);
NVOBJ_CLASS(dev, 0x0055, GR);
NVOBJ_CLASS(dev, 0x0017, GR);
NVOBJ_CLASS(dev, 0x0057, GR);
NVOBJ_CLASS(dev, 0x0058, GR);
NVOBJ_CLASS(dev, 0x0059, GR);
NVOBJ_CLASS(dev, 0x005a, GR);
NVOBJ_CLASS(dev, 0x005b, GR);
NVOBJ_CLASS(dev, 0x001c, GR);
NVOBJ_MTHD (dev, 0x001c, 0x0184, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x001c, 0x0188, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x001c, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x001c, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x001c, 0x0194, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x001c, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x005c, GR);
NVOBJ_MTHD (dev, 0x005c, 0x0184, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x005c, 0x0188, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x005c, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x005c, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x005c, 0x0194, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x005c, 0x0198, nv04_graph_mthd_bind_surf2d);
NVOBJ_MTHD (dev, 0x005c, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x001d, GR);
NVOBJ_MTHD (dev, 0x001d, 0x0184, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x001d, 0x0188, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x001d, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x001d, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x001d, 0x0194, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x001d, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x005d, GR);
NVOBJ_MTHD (dev, 0x005d, 0x0184, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x005d, 0x0188, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x005d, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x005d, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x005d, 0x0194, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x005d, 0x0198, nv04_graph_mthd_bind_surf2d);
NVOBJ_MTHD (dev, 0x005d, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x001e, GR);
NVOBJ_MTHD (dev, 0x001e, 0x0184, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x001e, 0x0188, nv04_graph_mthd_bind_nv01_patt);
NVOBJ_MTHD (dev, 0x001e, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x001e, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x001e, 0x0194, nv04_graph_mthd_bind_surf_dst);
NVOBJ_MTHD (dev, 0x001e, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x005e, GR);
NVOBJ_MTHD (dev, 0x005e, 0x0184, nv04_graph_mthd_bind_clip);
NVOBJ_MTHD (dev, 0x005e, 0x0188, nv04_graph_mthd_bind_nv04_patt);
NVOBJ_MTHD (dev, 0x005e, 0x018c, nv04_graph_mthd_bind_rop);
NVOBJ_MTHD (dev, 0x005e, 0x0190, nv04_graph_mthd_bind_beta1);
NVOBJ_MTHD (dev, 0x005e, 0x0194, nv04_graph_mthd_bind_beta4);
NVOBJ_MTHD (dev, 0x005e, 0x0198, nv04_graph_mthd_bind_surf2d);
NVOBJ_MTHD (dev, 0x005e, 0x02fc, nv04_graph_mthd_set_operation);
NVOBJ_CLASS(dev, 0x506e, SW);
NVOBJ_MTHD (dev, 0x506e, 0x0150, nv04_graph_mthd_set_ref);
NVOBJ_MTHD (dev, 0x506e, 0x0500, nv04_graph_mthd_page_flip);
return 0;
}
