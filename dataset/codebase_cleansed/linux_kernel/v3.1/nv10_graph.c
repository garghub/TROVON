static void nv10_graph_save_pipe(struct nouveau_channel *chan)
{
struct graph_state *pgraph_ctx = chan->engctx[NVOBJ_ENGINE_GR];
struct pipe_state *pipe = &pgraph_ctx->pipe_state;
struct drm_device *dev = chan->dev;
PIPE_SAVE(dev, pipe->pipe_0x4400, 0x4400);
PIPE_SAVE(dev, pipe->pipe_0x0200, 0x0200);
PIPE_SAVE(dev, pipe->pipe_0x6400, 0x6400);
PIPE_SAVE(dev, pipe->pipe_0x6800, 0x6800);
PIPE_SAVE(dev, pipe->pipe_0x6c00, 0x6c00);
PIPE_SAVE(dev, pipe->pipe_0x7000, 0x7000);
PIPE_SAVE(dev, pipe->pipe_0x7400, 0x7400);
PIPE_SAVE(dev, pipe->pipe_0x7800, 0x7800);
PIPE_SAVE(dev, pipe->pipe_0x0040, 0x0040);
PIPE_SAVE(dev, pipe->pipe_0x0000, 0x0000);
}
static void nv10_graph_load_pipe(struct nouveau_channel *chan)
{
struct graph_state *pgraph_ctx = chan->engctx[NVOBJ_ENGINE_GR];
struct pipe_state *pipe = &pgraph_ctx->pipe_state;
struct drm_device *dev = chan->dev;
uint32_t xfmode0, xfmode1;
int i;
nouveau_wait_for_idle(dev);
xfmode0 = nv_rd32(dev, NV10_PGRAPH_XFMODE0);
xfmode1 = nv_rd32(dev, NV10_PGRAPH_XFMODE1);
nv_wr32(dev, NV10_PGRAPH_XFMODE0, 0x10000000);
nv_wr32(dev, NV10_PGRAPH_XFMODE1, 0x00000000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x000064c0);
for (i = 0; i < 4; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
for (i = 0; i < 4; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x00006ab0);
for (i = 0; i < 3; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x00006a80);
for (i = 0; i < 3; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x00000040);
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x00000008);
PIPE_RESTORE(dev, pipe->pipe_0x0200, 0x0200);
nouveau_wait_for_idle(dev);
nv_wr32(dev, NV10_PGRAPH_XFMODE0, xfmode0);
nv_wr32(dev, NV10_PGRAPH_XFMODE1, xfmode1);
PIPE_RESTORE(dev, pipe->pipe_0x6400, 0x6400);
PIPE_RESTORE(dev, pipe->pipe_0x6800, 0x6800);
PIPE_RESTORE(dev, pipe->pipe_0x6c00, 0x6c00);
PIPE_RESTORE(dev, pipe->pipe_0x7000, 0x7000);
PIPE_RESTORE(dev, pipe->pipe_0x7400, 0x7400);
PIPE_RESTORE(dev, pipe->pipe_0x7800, 0x7800);
PIPE_RESTORE(dev, pipe->pipe_0x4400, 0x4400);
PIPE_RESTORE(dev, pipe->pipe_0x0000, 0x0000);
PIPE_RESTORE(dev, pipe->pipe_0x0040, 0x0040);
nouveau_wait_for_idle(dev);
}
static void nv10_graph_create_pipe(struct nouveau_channel *chan)
{
struct graph_state *pgraph_ctx = chan->engctx[NVOBJ_ENGINE_GR];
struct pipe_state *fifo_pipe_state = &pgraph_ctx->pipe_state;
struct drm_device *dev = chan->dev;
uint32_t *fifo_pipe_state_addr;
int i;
#define PIPE_INIT(addr) \
do { \
fifo_pipe_state_addr = fifo_pipe_state->pipe_##addr; \
} while (0)
#define PIPE_INIT_END(addr) \
do { \
uint32_t *__end_addr = fifo_pipe_state->pipe_##addr + \
ARRAY_SIZE(fifo_pipe_state->pipe_##addr); \
if (fifo_pipe_state_addr != __end_addr) \
NV_ERROR(dev, "incomplete pipe init for 0x%x : %p/%p\n", \
addr, fifo_pipe_state_addr, __end_addr); \
} while (0)
#define NV_WRITE_PIPE_INIT(value) *(fifo_pipe_state_addr++) = value
PIPE_INIT(0x0200);
for (i = 0; i < 48; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x0200);
PIPE_INIT(0x6400);
for (i = 0; i < 211; i++)
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x3f800000);
NV_WRITE_PIPE_INIT(0x40000000);
NV_WRITE_PIPE_INIT(0x40000000);
NV_WRITE_PIPE_INIT(0x40000000);
NV_WRITE_PIPE_INIT(0x40000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x3f800000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x3f000000);
NV_WRITE_PIPE_INIT(0x3f000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x3f800000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x3f800000);
NV_WRITE_PIPE_INIT(0x3f800000);
NV_WRITE_PIPE_INIT(0x3f800000);
NV_WRITE_PIPE_INIT(0x3f800000);
PIPE_INIT_END(0x6400);
PIPE_INIT(0x6800);
for (i = 0; i < 162; i++)
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x3f800000);
for (i = 0; i < 25; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x6800);
PIPE_INIT(0x6c00);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0xbf800000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x6c00);
PIPE_INIT(0x7000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x00000000);
NV_WRITE_PIPE_INIT(0x7149f2ca);
for (i = 0; i < 35; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x7000);
PIPE_INIT(0x7400);
for (i = 0; i < 48; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x7400);
PIPE_INIT(0x7800);
for (i = 0; i < 48; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x7800);
PIPE_INIT(0x4400);
for (i = 0; i < 32; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x4400);
PIPE_INIT(0x0000);
for (i = 0; i < 16; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x0000);
PIPE_INIT(0x0040);
for (i = 0; i < 4; i++)
NV_WRITE_PIPE_INIT(0x00000000);
PIPE_INIT_END(0x0040);
#undef PIPE_INIT
#undef PIPE_INIT_END
#undef NV_WRITE_PIPE_INIT
}
static int nv10_graph_ctx_regs_find_offset(struct drm_device *dev, int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(nv10_graph_ctx_regs); i++) {
if (nv10_graph_ctx_regs[i] == reg)
return i;
}
NV_ERROR(dev, "unknow offset nv10_ctx_regs %d\n", reg);
return -1;
}
static int nv17_graph_ctx_regs_find_offset(struct drm_device *dev, int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(nv17_graph_ctx_regs); i++) {
if (nv17_graph_ctx_regs[i] == reg)
return i;
}
NV_ERROR(dev, "unknow offset nv17_ctx_regs %d\n", reg);
return -1;
}
static void nv10_graph_load_dma_vtxbuf(struct nouveau_channel *chan,
uint32_t inst)
{
struct drm_device *dev = chan->dev;
uint32_t st2, st2_dl, st2_dh, fifo_ptr, fifo[0x60/4];
uint32_t ctx_user, ctx_switch[5];
int i, subchan = -1;
for (i = 0; i < 8; i++) {
int class = nv_rd32(dev, NV10_PGRAPH_CTX_CACHE(i, 0)) & 0xfff;
if (class == 0x56 || class == 0x96 || class == 0x99) {
subchan = i;
break;
}
}
if (subchan < 0 || !inst)
return;
ctx_user = nv_rd32(dev, NV10_PGRAPH_CTX_USER);
for (i = 0; i < 5; i++)
ctx_switch[i] = nv_rd32(dev, NV10_PGRAPH_CTX_SWITCH(i));
st2 = nv_rd32(dev, NV10_PGRAPH_FFINTFC_ST2);
st2_dl = nv_rd32(dev, NV10_PGRAPH_FFINTFC_ST2_DL);
st2_dh = nv_rd32(dev, NV10_PGRAPH_FFINTFC_ST2_DH);
fifo_ptr = nv_rd32(dev, NV10_PGRAPH_FFINTFC_FIFO_PTR);
for (i = 0; i < ARRAY_SIZE(fifo); i++)
fifo[i] = nv_rd32(dev, 0x4007a0 + 4 * i);
for (i = 0; i < 5; i++)
nv_wr32(dev, NV10_PGRAPH_CTX_SWITCH(i),
nv_rd32(dev, NV10_PGRAPH_CTX_CACHE(subchan, i)));
nv_mask(dev, NV10_PGRAPH_CTX_USER, 0xe000, subchan << 13);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_FIFO_PTR, 0);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_ST2,
0x2c000000 | chan->id << 20 | subchan << 16 | 0x18c);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_ST2_DL, inst);
nv_mask(dev, NV10_PGRAPH_CTX_CONTROL, 0, 0x10000);
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000001);
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000000);
for (i = 0; i < ARRAY_SIZE(fifo); i++)
nv_wr32(dev, 0x4007a0 + 4 * i, fifo[i]);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_FIFO_PTR, fifo_ptr);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_ST2, st2);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_ST2_DL, st2_dl);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_ST2_DH, st2_dh);
for (i = 0; i < 5; i++)
nv_wr32(dev, NV10_PGRAPH_CTX_SWITCH(i), ctx_switch[i]);
nv_wr32(dev, NV10_PGRAPH_CTX_USER, ctx_user);
}
static int
nv10_graph_load_context(struct nouveau_channel *chan)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct graph_state *pgraph_ctx = chan->engctx[NVOBJ_ENGINE_GR];
uint32_t tmp;
int i;
for (i = 0; i < ARRAY_SIZE(nv10_graph_ctx_regs); i++)
nv_wr32(dev, nv10_graph_ctx_regs[i], pgraph_ctx->nv10[i]);
if (dev_priv->chipset >= 0x17) {
for (i = 0; i < ARRAY_SIZE(nv17_graph_ctx_regs); i++)
nv_wr32(dev, nv17_graph_ctx_regs[i],
pgraph_ctx->nv17[i]);
}
nv10_graph_load_pipe(chan);
nv10_graph_load_dma_vtxbuf(chan, (nv_rd32(dev, NV10_PGRAPH_GLOBALSTATE1)
& 0xffff));
nv_wr32(dev, NV10_PGRAPH_CTX_CONTROL, 0x10010100);
tmp = nv_rd32(dev, NV10_PGRAPH_CTX_USER);
nv_wr32(dev, NV10_PGRAPH_CTX_USER, (tmp & 0xffffff) | chan->id << 24);
tmp = nv_rd32(dev, NV10_PGRAPH_FFINTFC_ST2);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_ST2, tmp & 0xcfffffff);
return 0;
}
static int
nv10_graph_unload_context(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
struct nouveau_channel *chan;
struct graph_state *ctx;
uint32_t tmp;
int i;
chan = nv10_graph_channel(dev);
if (!chan)
return 0;
ctx = chan->engctx[NVOBJ_ENGINE_GR];
for (i = 0; i < ARRAY_SIZE(nv10_graph_ctx_regs); i++)
ctx->nv10[i] = nv_rd32(dev, nv10_graph_ctx_regs[i]);
if (dev_priv->chipset >= 0x17) {
for (i = 0; i < ARRAY_SIZE(nv17_graph_ctx_regs); i++)
ctx->nv17[i] = nv_rd32(dev, nv17_graph_ctx_regs[i]);
}
nv10_graph_save_pipe(chan);
nv_wr32(dev, NV10_PGRAPH_CTX_CONTROL, 0x10000000);
tmp = nv_rd32(dev, NV10_PGRAPH_CTX_USER) & 0x00ffffff;
tmp |= (pfifo->channels - 1) << 24;
nv_wr32(dev, NV10_PGRAPH_CTX_USER, tmp);
return 0;
}
static void
nv10_graph_context_switch(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_channel *chan = NULL;
int chid;
nouveau_wait_for_idle(dev);
nv10_graph_unload_context(dev);
chid = (nv_rd32(dev, NV04_PGRAPH_TRAPPED_ADDR) >> 20) & 0x1f;
chan = dev_priv->channels.ptr[chid];
if (chan && chan->engctx[NVOBJ_ENGINE_GR])
nv10_graph_load_context(chan);
}
struct nouveau_channel *
nv10_graph_channel(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
int chid = dev_priv->engine.fifo.channels;
if (nv_rd32(dev, NV10_PGRAPH_CTX_CONTROL) & 0x00010000)
chid = nv_rd32(dev, NV10_PGRAPH_CTX_USER) >> 24;
if (chid >= dev_priv->engine.fifo.channels)
return NULL;
return dev_priv->channels.ptr[chid];
}
static int
nv10_graph_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct graph_state *pgraph_ctx;
NV_DEBUG(dev, "nv10_graph_context_create %d\n", chan->id);
pgraph_ctx = kzalloc(sizeof(*pgraph_ctx), GFP_KERNEL);
if (pgraph_ctx == NULL)
return -ENOMEM;
chan->engctx[engine] = pgraph_ctx;
NV_WRITE_CTX(0x00400e88, 0x08000000);
NV_WRITE_CTX(0x00400e9c, 0x4b7fffff);
NV_WRITE_CTX(NV03_PGRAPH_XY_LOGIC_MISC0, 0x0001ffff);
NV_WRITE_CTX(0x00400e10, 0x00001000);
NV_WRITE_CTX(0x00400e14, 0x00001000);
NV_WRITE_CTX(0x00400e30, 0x00080008);
NV_WRITE_CTX(0x00400e34, 0x00080008);
if (dev_priv->chipset >= 0x17) {
NV17_WRITE_CTX(NV10_PGRAPH_DEBUG_4,
nv_rd32(dev, NV10_PGRAPH_DEBUG_4));
NV17_WRITE_CTX(0x004006b0, nv_rd32(dev, 0x004006b0));
NV17_WRITE_CTX(0x00400eac, 0x0fff0000);
NV17_WRITE_CTX(0x00400eb0, 0x0fff0000);
NV17_WRITE_CTX(0x00400ec0, 0x00000080);
NV17_WRITE_CTX(0x00400ed0, 0x00000080);
}
NV_WRITE_CTX(NV10_PGRAPH_CTX_USER, chan->id << 24);
nv10_graph_create_pipe(chan);
return 0;
}
static void
nv10_graph_context_del(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct graph_state *pgraph_ctx = chan->engctx[engine];
unsigned long flags;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000000);
if (nv10_graph_channel(dev) == chan)
nv10_graph_unload_context(dev);
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000001);
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
chan->engctx[engine] = NULL;
kfree(pgraph_ctx);
}
static void
nv10_graph_set_tile_region(struct drm_device *dev, int i)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_tile_reg *tile = &dev_priv->tile.reg[i];
nv_wr32(dev, NV10_PGRAPH_TLIMIT(i), tile->limit);
nv_wr32(dev, NV10_PGRAPH_TSIZE(i), tile->pitch);
nv_wr32(dev, NV10_PGRAPH_TILE(i), tile->addr);
}
static int
nv10_graph_init(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
u32 tmp;
int i;
nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) &
~NV_PMC_ENABLE_PGRAPH);
nv_wr32(dev, NV03_PMC_ENABLE, nv_rd32(dev, NV03_PMC_ENABLE) |
NV_PMC_ENABLE_PGRAPH);
nv_wr32(dev, NV03_PGRAPH_INTR , 0xFFFFFFFF);
nv_wr32(dev, NV03_PGRAPH_INTR_EN, 0xFFFFFFFF);
nv_wr32(dev, NV04_PGRAPH_DEBUG_0, 0xFFFFFFFF);
nv_wr32(dev, NV04_PGRAPH_DEBUG_0, 0x00000000);
nv_wr32(dev, NV04_PGRAPH_DEBUG_1, 0x00118700);
nv_wr32(dev, NV04_PGRAPH_DEBUG_2, 0x25f92ad9);
nv_wr32(dev, NV04_PGRAPH_DEBUG_3, 0x55DE0830 |
(1<<29) |
(1<<31));
if (dev_priv->chipset >= 0x17) {
nv_wr32(dev, NV10_PGRAPH_DEBUG_4, 0x1f000000);
nv_wr32(dev, 0x400a10, 0x3ff3fb6);
nv_wr32(dev, 0x400838, 0x2f8684);
nv_wr32(dev, 0x40083c, 0x115f3f);
nv_wr32(dev, 0x004006b0, 0x40000020);
} else
nv_wr32(dev, NV10_PGRAPH_DEBUG_4, 0x00000000);
for (i = 0; i < NV10_PFB_TILE__SIZE; i++)
nv10_graph_set_tile_region(dev, i);
nv_wr32(dev, NV10_PGRAPH_CTX_SWITCH(0), 0x00000000);
nv_wr32(dev, NV10_PGRAPH_CTX_SWITCH(1), 0x00000000);
nv_wr32(dev, NV10_PGRAPH_CTX_SWITCH(2), 0x00000000);
nv_wr32(dev, NV10_PGRAPH_CTX_SWITCH(3), 0x00000000);
nv_wr32(dev, NV10_PGRAPH_CTX_SWITCH(4), 0x00000000);
nv_wr32(dev, NV10_PGRAPH_STATE, 0xFFFFFFFF);
tmp = nv_rd32(dev, NV10_PGRAPH_CTX_USER) & 0x00ffffff;
tmp |= (dev_priv->engine.fifo.channels - 1) << 24;
nv_wr32(dev, NV10_PGRAPH_CTX_USER, tmp);
nv_wr32(dev, NV10_PGRAPH_CTX_CONTROL, 0x10000100);
nv_wr32(dev, NV10_PGRAPH_FFINTFC_ST2, 0x08000000);
return 0;
}
static int
nv10_graph_fini(struct drm_device *dev, int engine, bool suspend)
{
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000000);
if (!nv_wait(dev, NV04_PGRAPH_STATUS, ~0, 0) && suspend) {
nv_mask(dev, NV04_PGRAPH_FIFO, 0x00000001, 0x00000001);
return -EBUSY;
}
nv10_graph_unload_context(dev);
nv_wr32(dev, NV03_PGRAPH_INTR_EN, 0x00000000);
return 0;
}
static int
nv17_graph_mthd_lma_window(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
struct graph_state *ctx = chan->engctx[NVOBJ_ENGINE_GR];
struct drm_device *dev = chan->dev;
struct pipe_state *pipe = &ctx->pipe_state;
uint32_t pipe_0x0040[1], pipe_0x64c0[8], pipe_0x6a80[3], pipe_0x6ab0[3];
uint32_t xfmode0, xfmode1;
int i;
ctx->lma_window[(mthd - 0x1638) / 4] = data;
if (mthd != 0x1644)
return 0;
nouveau_wait_for_idle(dev);
PIPE_SAVE(dev, pipe_0x0040, 0x0040);
PIPE_SAVE(dev, pipe->pipe_0x0200, 0x0200);
PIPE_RESTORE(dev, ctx->lma_window, 0x6790);
nouveau_wait_for_idle(dev);
xfmode0 = nv_rd32(dev, NV10_PGRAPH_XFMODE0);
xfmode1 = nv_rd32(dev, NV10_PGRAPH_XFMODE1);
PIPE_SAVE(dev, pipe->pipe_0x4400, 0x4400);
PIPE_SAVE(dev, pipe_0x64c0, 0x64c0);
PIPE_SAVE(dev, pipe_0x6ab0, 0x6ab0);
PIPE_SAVE(dev, pipe_0x6a80, 0x6a80);
nouveau_wait_for_idle(dev);
nv_wr32(dev, NV10_PGRAPH_XFMODE0, 0x10000000);
nv_wr32(dev, NV10_PGRAPH_XFMODE1, 0x00000000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x000064c0);
for (i = 0; i < 4; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
for (i = 0; i < 4; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x00006ab0);
for (i = 0; i < 3; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x00006a80);
for (i = 0; i < 3; i++)
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x00000040);
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x00000008);
PIPE_RESTORE(dev, pipe->pipe_0x0200, 0x0200);
nouveau_wait_for_idle(dev);
PIPE_RESTORE(dev, pipe_0x0040, 0x0040);
nv_wr32(dev, NV10_PGRAPH_XFMODE0, xfmode0);
nv_wr32(dev, NV10_PGRAPH_XFMODE1, xfmode1);
PIPE_RESTORE(dev, pipe_0x64c0, 0x64c0);
PIPE_RESTORE(dev, pipe_0x6ab0, 0x6ab0);
PIPE_RESTORE(dev, pipe_0x6a80, 0x6a80);
PIPE_RESTORE(dev, pipe->pipe_0x4400, 0x4400);
nv_wr32(dev, NV10_PGRAPH_PIPE_ADDRESS, 0x000000c0);
nv_wr32(dev, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nouveau_wait_for_idle(dev);
return 0;
}
static int
nv17_graph_mthd_lma_enable(struct nouveau_channel *chan,
u32 class, u32 mthd, u32 data)
{
struct drm_device *dev = chan->dev;
nouveau_wait_for_idle(dev);
nv_wr32(dev, NV10_PGRAPH_DEBUG_4,
nv_rd32(dev, NV10_PGRAPH_DEBUG_4) | 0x1 << 8);
nv_wr32(dev, 0x004006b0,
nv_rd32(dev, 0x004006b0) | 0x8 << 24);
return 0;
}
static void
nv10_graph_isr(struct drm_device *dev)
{
u32 stat;
while ((stat = nv_rd32(dev, NV03_PGRAPH_INTR))) {
u32 nsource = nv_rd32(dev, NV03_PGRAPH_NSOURCE);
u32 nstatus = nv_rd32(dev, NV03_PGRAPH_NSTATUS);
u32 addr = nv_rd32(dev, NV04_PGRAPH_TRAPPED_ADDR);
u32 chid = (addr & 0x01f00000) >> 20;
u32 subc = (addr & 0x00070000) >> 16;
u32 mthd = (addr & 0x00001ffc);
u32 data = nv_rd32(dev, NV04_PGRAPH_TRAPPED_DATA);
u32 class = nv_rd32(dev, 0x400160 + subc * 4) & 0xfff;
u32 show = stat;
if (stat & NV_PGRAPH_INTR_ERROR) {
if (nsource & NV03_PGRAPH_NSOURCE_ILLEGAL_MTHD) {
if (!nouveau_gpuobj_mthd_call2(dev, chid, class, mthd, data))
show &= ~NV_PGRAPH_INTR_ERROR;
}
}
if (stat & NV_PGRAPH_INTR_CONTEXT_SWITCH) {
nv_wr32(dev, NV03_PGRAPH_INTR, NV_PGRAPH_INTR_CONTEXT_SWITCH);
stat &= ~NV_PGRAPH_INTR_CONTEXT_SWITCH;
show &= ~NV_PGRAPH_INTR_CONTEXT_SWITCH;
nv10_graph_context_switch(dev);
}
nv_wr32(dev, NV03_PGRAPH_INTR, stat);
nv_wr32(dev, NV04_PGRAPH_FIFO, 0x00000001);
if (show && nouveau_ratelimit()) {
NV_INFO(dev, "PGRAPH -");
nouveau_bitfield_print(nv10_graph_intr, show);
printk(" nsource:");
nouveau_bitfield_print(nv04_graph_nsource, nsource);
printk(" nstatus:");
nouveau_bitfield_print(nv10_graph_nstatus, nstatus);
printk("\n");
NV_INFO(dev, "PGRAPH - ch %d/%d class 0x%04x "
"mthd 0x%04x data 0x%08x\n",
chid, subc, class, mthd, data);
}
}
}
static void
nv10_graph_destroy(struct drm_device *dev, int engine)
{
struct nv10_graph_engine *pgraph = nv_engine(dev, engine);
nouveau_irq_unregister(dev, 12);
kfree(pgraph);
}
int
nv10_graph_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv10_graph_engine *pgraph;
pgraph = kzalloc(sizeof(*pgraph), GFP_KERNEL);
if (!pgraph)
return -ENOMEM;
pgraph->base.destroy = nv10_graph_destroy;
pgraph->base.init = nv10_graph_init;
pgraph->base.fini = nv10_graph_fini;
pgraph->base.context_new = nv10_graph_context_new;
pgraph->base.context_del = nv10_graph_context_del;
pgraph->base.object_new = nv04_graph_object_new;
pgraph->base.set_tile_region = nv10_graph_set_tile_region;
NVOBJ_ENGINE_ADD(dev, GR, &pgraph->base);
nouveau_irq_register(dev, 12, nv10_graph_isr);
NVOBJ_CLASS(dev, 0x506e, SW);
NVOBJ_MTHD (dev, 0x506e, 0x0500, nv04_graph_mthd_page_flip);
NVOBJ_CLASS(dev, 0x0030, GR);
NVOBJ_CLASS(dev, 0x0039, GR);
NVOBJ_CLASS(dev, 0x004a, GR);
NVOBJ_CLASS(dev, 0x005f, GR);
NVOBJ_CLASS(dev, 0x009f, GR);
NVOBJ_CLASS(dev, 0x008a, GR);
NVOBJ_CLASS(dev, 0x0089, GR);
NVOBJ_CLASS(dev, 0x0062, GR);
NVOBJ_CLASS(dev, 0x0043, GR);
NVOBJ_CLASS(dev, 0x0012, GR);
NVOBJ_CLASS(dev, 0x0072, GR);
NVOBJ_CLASS(dev, 0x0019, GR);
NVOBJ_CLASS(dev, 0x0044, GR);
NVOBJ_CLASS(dev, 0x0052, GR);
NVOBJ_CLASS(dev, 0x0093, GR);
NVOBJ_CLASS(dev, 0x0094, GR);
NVOBJ_CLASS(dev, 0x0095, GR);
if (dev_priv->chipset <= 0x10) {
NVOBJ_CLASS(dev, 0x0056, GR);
} else
if (dev_priv->chipset < 0x17 || dev_priv->chipset == 0x1a) {
NVOBJ_CLASS(dev, 0x0096, GR);
} else {
NVOBJ_CLASS(dev, 0x0099, GR);
NVOBJ_MTHD (dev, 0x0099, 0x1638, nv17_graph_mthd_lma_window);
NVOBJ_MTHD (dev, 0x0099, 0x163c, nv17_graph_mthd_lma_window);
NVOBJ_MTHD (dev, 0x0099, 0x1640, nv17_graph_mthd_lma_window);
NVOBJ_MTHD (dev, 0x0099, 0x1644, nv17_graph_mthd_lma_window);
NVOBJ_MTHD (dev, 0x0099, 0x1658, nv17_graph_mthd_lma_enable);
}
return 0;
}
