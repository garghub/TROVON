static inline struct nv10_graph_priv *
nv10_graph_priv(struct nv10_graph_chan *chan)
{
return (void *)nv_object(chan)->engine;
}
static int
nv17_graph_mthd_lma_window(struct nouveau_object *object, u32 mthd,
void *args, u32 size)
{
struct nv10_graph_chan *chan = (void *)object->parent;
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
struct pipe_state *pipe = &chan->pipe_state;
u32 pipe_0x0040[1], pipe_0x64c0[8], pipe_0x6a80[3], pipe_0x6ab0[3];
u32 xfmode0, xfmode1;
u32 data = *(u32 *)args;
int i;
chan->lma_window[(mthd - 0x1638) / 4] = data;
if (mthd != 0x1644)
return 0;
nv04_graph_idle(priv);
PIPE_SAVE(priv, pipe_0x0040, 0x0040);
PIPE_SAVE(priv, pipe->pipe_0x0200, 0x0200);
PIPE_RESTORE(priv, chan->lma_window, 0x6790);
nv04_graph_idle(priv);
xfmode0 = nv_rd32(priv, NV10_PGRAPH_XFMODE0);
xfmode1 = nv_rd32(priv, NV10_PGRAPH_XFMODE1);
PIPE_SAVE(priv, pipe->pipe_0x4400, 0x4400);
PIPE_SAVE(priv, pipe_0x64c0, 0x64c0);
PIPE_SAVE(priv, pipe_0x6ab0, 0x6ab0);
PIPE_SAVE(priv, pipe_0x6a80, 0x6a80);
nv04_graph_idle(priv);
nv_wr32(priv, NV10_PGRAPH_XFMODE0, 0x10000000);
nv_wr32(priv, NV10_PGRAPH_XFMODE1, 0x00000000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x000064c0);
for (i = 0; i < 4; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
for (i = 0; i < 4; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x00006ab0);
for (i = 0; i < 3; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x00006a80);
for (i = 0; i < 3; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x00000040);
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x00000008);
PIPE_RESTORE(priv, pipe->pipe_0x0200, 0x0200);
nv04_graph_idle(priv);
PIPE_RESTORE(priv, pipe_0x0040, 0x0040);
nv_wr32(priv, NV10_PGRAPH_XFMODE0, xfmode0);
nv_wr32(priv, NV10_PGRAPH_XFMODE1, xfmode1);
PIPE_RESTORE(priv, pipe_0x64c0, 0x64c0);
PIPE_RESTORE(priv, pipe_0x6ab0, 0x6ab0);
PIPE_RESTORE(priv, pipe_0x6a80, 0x6a80);
PIPE_RESTORE(priv, pipe->pipe_0x4400, 0x4400);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x000000c0);
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv04_graph_idle(priv);
return 0;
}
static int
nv17_graph_mthd_lma_enable(struct nouveau_object *object, u32 mthd,
void *args, u32 size)
{
struct nv10_graph_chan *chan = (void *)object->parent;
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
nv04_graph_idle(priv);
nv_mask(priv, NV10_PGRAPH_DEBUG_4, 0x00000100, 0x00000100);
nv_mask(priv, 0x4006b0, 0x08000000, 0x08000000);
return 0;
}
static struct nv10_graph_chan *
nv10_graph_channel(struct nv10_graph_priv *priv)
{
struct nv10_graph_chan *chan = NULL;
if (nv_rd32(priv, 0x400144) & 0x00010000) {
int chid = nv_rd32(priv, 0x400148) >> 24;
if (chid < ARRAY_SIZE(priv->chan))
chan = priv->chan[chid];
}
return chan;
}
static void
nv10_graph_save_pipe(struct nv10_graph_chan *chan)
{
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
struct pipe_state *pipe = &chan->pipe_state;
PIPE_SAVE(priv, pipe->pipe_0x4400, 0x4400);
PIPE_SAVE(priv, pipe->pipe_0x0200, 0x0200);
PIPE_SAVE(priv, pipe->pipe_0x6400, 0x6400);
PIPE_SAVE(priv, pipe->pipe_0x6800, 0x6800);
PIPE_SAVE(priv, pipe->pipe_0x6c00, 0x6c00);
PIPE_SAVE(priv, pipe->pipe_0x7000, 0x7000);
PIPE_SAVE(priv, pipe->pipe_0x7400, 0x7400);
PIPE_SAVE(priv, pipe->pipe_0x7800, 0x7800);
PIPE_SAVE(priv, pipe->pipe_0x0040, 0x0040);
PIPE_SAVE(priv, pipe->pipe_0x0000, 0x0000);
}
static void
nv10_graph_load_pipe(struct nv10_graph_chan *chan)
{
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
struct pipe_state *pipe = &chan->pipe_state;
u32 xfmode0, xfmode1;
int i;
nv04_graph_idle(priv);
xfmode0 = nv_rd32(priv, NV10_PGRAPH_XFMODE0);
xfmode1 = nv_rd32(priv, NV10_PGRAPH_XFMODE1);
nv_wr32(priv, NV10_PGRAPH_XFMODE0, 0x10000000);
nv_wr32(priv, NV10_PGRAPH_XFMODE1, 0x00000000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x000064c0);
for (i = 0; i < 4; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
for (i = 0; i < 4; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x00006ab0);
for (i = 0; i < 3; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x3f800000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x00006a80);
for (i = 0; i < 3; i++)
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x00000000);
nv_wr32(priv, NV10_PGRAPH_PIPE_ADDRESS, 0x00000040);
nv_wr32(priv, NV10_PGRAPH_PIPE_DATA, 0x00000008);
PIPE_RESTORE(priv, pipe->pipe_0x0200, 0x0200);
nv04_graph_idle(priv);
nv_wr32(priv, NV10_PGRAPH_XFMODE0, xfmode0);
nv_wr32(priv, NV10_PGRAPH_XFMODE1, xfmode1);
PIPE_RESTORE(priv, pipe->pipe_0x6400, 0x6400);
PIPE_RESTORE(priv, pipe->pipe_0x6800, 0x6800);
PIPE_RESTORE(priv, pipe->pipe_0x6c00, 0x6c00);
PIPE_RESTORE(priv, pipe->pipe_0x7000, 0x7000);
PIPE_RESTORE(priv, pipe->pipe_0x7400, 0x7400);
PIPE_RESTORE(priv, pipe->pipe_0x7800, 0x7800);
PIPE_RESTORE(priv, pipe->pipe_0x4400, 0x4400);
PIPE_RESTORE(priv, pipe->pipe_0x0000, 0x0000);
PIPE_RESTORE(priv, pipe->pipe_0x0040, 0x0040);
nv04_graph_idle(priv);
}
static void
nv10_graph_create_pipe(struct nv10_graph_chan *chan)
{
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
struct pipe_state *pipe_state = &chan->pipe_state;
u32 *pipe_state_addr;
int i;
#define PIPE_INIT(addr) \
do { \
pipe_state_addr = pipe_state->pipe_##addr; \
} while (0)
#define PIPE_INIT_END(addr) \
do { \
u32 *__end_addr = pipe_state->pipe_##addr + \
ARRAY_SIZE(pipe_state->pipe_##addr); \
if (pipe_state_addr != __end_addr) \
nv_error(priv, "incomplete pipe init for 0x%x : %p/%p\n", \
addr, pipe_state_addr, __end_addr); \
} while (0)
#define NV_WRITE_PIPE_INIT(value) *(pipe_state_addr++) = value
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
static int
nv10_graph_ctx_regs_find_offset(struct nv10_graph_priv *priv, int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(nv10_graph_ctx_regs); i++) {
if (nv10_graph_ctx_regs[i] == reg)
return i;
}
nv_error(priv, "unknow offset nv10_ctx_regs %d\n", reg);
return -1;
}
static int
nv17_graph_ctx_regs_find_offset(struct nv10_graph_priv *priv, int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(nv17_graph_ctx_regs); i++) {
if (nv17_graph_ctx_regs[i] == reg)
return i;
}
nv_error(priv, "unknow offset nv17_ctx_regs %d\n", reg);
return -1;
}
static void
nv10_graph_load_dma_vtxbuf(struct nv10_graph_chan *chan, int chid, u32 inst)
{
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
u32 st2, st2_dl, st2_dh, fifo_ptr, fifo[0x60/4];
u32 ctx_user, ctx_switch[5];
int i, subchan = -1;
for (i = 0; i < 8; i++) {
int class = nv_rd32(priv, NV10_PGRAPH_CTX_CACHE(i, 0)) & 0xfff;
if (class == 0x56 || class == 0x96 || class == 0x99) {
subchan = i;
break;
}
}
if (subchan < 0 || !inst)
return;
ctx_user = nv_rd32(priv, NV10_PGRAPH_CTX_USER);
for (i = 0; i < 5; i++)
ctx_switch[i] = nv_rd32(priv, NV10_PGRAPH_CTX_SWITCH(i));
st2 = nv_rd32(priv, NV10_PGRAPH_FFINTFC_ST2);
st2_dl = nv_rd32(priv, NV10_PGRAPH_FFINTFC_ST2_DL);
st2_dh = nv_rd32(priv, NV10_PGRAPH_FFINTFC_ST2_DH);
fifo_ptr = nv_rd32(priv, NV10_PGRAPH_FFINTFC_FIFO_PTR);
for (i = 0; i < ARRAY_SIZE(fifo); i++)
fifo[i] = nv_rd32(priv, 0x4007a0 + 4 * i);
for (i = 0; i < 5; i++)
nv_wr32(priv, NV10_PGRAPH_CTX_SWITCH(i),
nv_rd32(priv, NV10_PGRAPH_CTX_CACHE(subchan, i)));
nv_mask(priv, NV10_PGRAPH_CTX_USER, 0xe000, subchan << 13);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_FIFO_PTR, 0);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_ST2,
0x2c000000 | chid << 20 | subchan << 16 | 0x18c);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_ST2_DL, inst);
nv_mask(priv, NV10_PGRAPH_CTX_CONTROL, 0, 0x10000);
nv_mask(priv, NV04_PGRAPH_FIFO, 0x00000001, 0x00000001);
nv_mask(priv, NV04_PGRAPH_FIFO, 0x00000001, 0x00000000);
for (i = 0; i < ARRAY_SIZE(fifo); i++)
nv_wr32(priv, 0x4007a0 + 4 * i, fifo[i]);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_FIFO_PTR, fifo_ptr);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_ST2, st2);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_ST2_DL, st2_dl);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_ST2_DH, st2_dh);
for (i = 0; i < 5; i++)
nv_wr32(priv, NV10_PGRAPH_CTX_SWITCH(i), ctx_switch[i]);
nv_wr32(priv, NV10_PGRAPH_CTX_USER, ctx_user);
}
static int
nv10_graph_load_context(struct nv10_graph_chan *chan, int chid)
{
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
u32 inst;
int i;
for (i = 0; i < ARRAY_SIZE(nv10_graph_ctx_regs); i++)
nv_wr32(priv, nv10_graph_ctx_regs[i], chan->nv10[i]);
if (nv_device(priv)->chipset >= 0x17) {
for (i = 0; i < ARRAY_SIZE(nv17_graph_ctx_regs); i++)
nv_wr32(priv, nv17_graph_ctx_regs[i], chan->nv17[i]);
}
nv10_graph_load_pipe(chan);
inst = nv_rd32(priv, NV10_PGRAPH_GLOBALSTATE1) & 0xffff;
nv10_graph_load_dma_vtxbuf(chan, chid, inst);
nv_wr32(priv, NV10_PGRAPH_CTX_CONTROL, 0x10010100);
nv_mask(priv, NV10_PGRAPH_CTX_USER, 0xff000000, chid << 24);
nv_mask(priv, NV10_PGRAPH_FFINTFC_ST2, 0x30000000, 0x00000000);
return 0;
}
static int
nv10_graph_unload_context(struct nv10_graph_chan *chan)
{
struct nv10_graph_priv *priv = nv10_graph_priv(chan);
int i;
for (i = 0; i < ARRAY_SIZE(nv10_graph_ctx_regs); i++)
chan->nv10[i] = nv_rd32(priv, nv10_graph_ctx_regs[i]);
if (nv_device(priv)->chipset >= 0x17) {
for (i = 0; i < ARRAY_SIZE(nv17_graph_ctx_regs); i++)
chan->nv17[i] = nv_rd32(priv, nv17_graph_ctx_regs[i]);
}
nv10_graph_save_pipe(chan);
nv_wr32(priv, NV10_PGRAPH_CTX_CONTROL, 0x10000000);
nv_mask(priv, NV10_PGRAPH_CTX_USER, 0xff000000, 0x1f000000);
return 0;
}
static void
nv10_graph_context_switch(struct nv10_graph_priv *priv)
{
struct nv10_graph_chan *prev = NULL;
struct nv10_graph_chan *next = NULL;
unsigned long flags;
int chid;
spin_lock_irqsave(&priv->lock, flags);
nv04_graph_idle(priv);
prev = nv10_graph_channel(priv);
if (prev)
nv10_graph_unload_context(prev);
chid = (nv_rd32(priv, NV04_PGRAPH_TRAPPED_ADDR) >> 20) & 0x1f;
next = priv->chan[chid];
if (next)
nv10_graph_load_context(next, chid);
spin_unlock_irqrestore(&priv->lock, flags);
}
static int
nv10_graph_context_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nouveau_fifo_chan *fifo = (void *)parent;
struct nv10_graph_priv *priv = (void *)engine;
struct nv10_graph_chan *chan;
unsigned long flags;
int ret;
ret = nouveau_object_create(parent, engine, oclass, 0, &chan);
*pobject = nv_object(chan);
if (ret)
return ret;
spin_lock_irqsave(&priv->lock, flags);
if (priv->chan[fifo->chid]) {
*pobject = nv_object(priv->chan[fifo->chid]);
atomic_inc(&(*pobject)->refcount);
spin_unlock_irqrestore(&priv->lock, flags);
nouveau_object_destroy(&chan->base);
return 1;
}
NV_WRITE_CTX(0x00400e88, 0x08000000);
NV_WRITE_CTX(0x00400e9c, 0x4b7fffff);
NV_WRITE_CTX(NV03_PGRAPH_XY_LOGIC_MISC0, 0x0001ffff);
NV_WRITE_CTX(0x00400e10, 0x00001000);
NV_WRITE_CTX(0x00400e14, 0x00001000);
NV_WRITE_CTX(0x00400e30, 0x00080008);
NV_WRITE_CTX(0x00400e34, 0x00080008);
if (nv_device(priv)->chipset >= 0x17) {
NV17_WRITE_CTX(NV10_PGRAPH_DEBUG_4,
nv_rd32(priv, NV10_PGRAPH_DEBUG_4));
NV17_WRITE_CTX(0x004006b0, nv_rd32(priv, 0x004006b0));
NV17_WRITE_CTX(0x00400eac, 0x0fff0000);
NV17_WRITE_CTX(0x00400eb0, 0x0fff0000);
NV17_WRITE_CTX(0x00400ec0, 0x00000080);
NV17_WRITE_CTX(0x00400ed0, 0x00000080);
}
NV_WRITE_CTX(NV10_PGRAPH_CTX_USER, chan->chid << 24);
nv10_graph_create_pipe(chan);
priv->chan[fifo->chid] = chan;
chan->chid = fifo->chid;
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static void
nv10_graph_context_dtor(struct nouveau_object *object)
{
struct nv10_graph_priv *priv = (void *)object->engine;
struct nv10_graph_chan *chan = (void *)object;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
priv->chan[chan->chid] = NULL;
spin_unlock_irqrestore(&priv->lock, flags);
nouveau_object_destroy(&chan->base);
}
static int
nv10_graph_context_fini(struct nouveau_object *object, bool suspend)
{
struct nv10_graph_priv *priv = (void *)object->engine;
struct nv10_graph_chan *chan = (void *)object;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
nv_mask(priv, NV04_PGRAPH_FIFO, 0x00000001, 0x00000000);
if (nv10_graph_channel(priv) == chan)
nv10_graph_unload_context(chan);
nv_mask(priv, NV04_PGRAPH_FIFO, 0x00000001, 0x00000001);
spin_unlock_irqrestore(&priv->lock, flags);
return nouveau_object_fini(&chan->base, suspend);
}
static void
nv10_graph_tile_prog(struct nouveau_engine *engine, int i)
{
struct nouveau_fb_tile *tile = &nouveau_fb(engine)->tile.region[i];
struct nouveau_fifo *pfifo = nouveau_fifo(engine);
struct nv10_graph_priv *priv = (void *)engine;
unsigned long flags;
pfifo->pause(pfifo, &flags);
nv04_graph_idle(priv);
nv_wr32(priv, NV10_PGRAPH_TLIMIT(i), tile->limit);
nv_wr32(priv, NV10_PGRAPH_TSIZE(i), tile->pitch);
nv_wr32(priv, NV10_PGRAPH_TILE(i), tile->addr);
pfifo->start(pfifo, &flags);
}
static void
nv10_graph_intr(struct nouveau_subdev *subdev)
{
struct nv10_graph_priv *priv = (void *)subdev;
struct nv10_graph_chan *chan = NULL;
struct nouveau_namedb *namedb = NULL;
struct nouveau_handle *handle = NULL;
u32 stat = nv_rd32(priv, NV03_PGRAPH_INTR);
u32 nsource = nv_rd32(priv, NV03_PGRAPH_NSOURCE);
u32 nstatus = nv_rd32(priv, NV03_PGRAPH_NSTATUS);
u32 addr = nv_rd32(priv, NV04_PGRAPH_TRAPPED_ADDR);
u32 chid = (addr & 0x01f00000) >> 20;
u32 subc = (addr & 0x00070000) >> 16;
u32 mthd = (addr & 0x00001ffc);
u32 data = nv_rd32(priv, NV04_PGRAPH_TRAPPED_DATA);
u32 class = nv_rd32(priv, 0x400160 + subc * 4) & 0xfff;
u32 show = stat;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
chan = priv->chan[chid];
if (chan)
namedb = (void *)nv_pclass(nv_object(chan), NV_NAMEDB_CLASS);
spin_unlock_irqrestore(&priv->lock, flags);
if (stat & NV_PGRAPH_INTR_ERROR) {
if (chan && (nsource & NV03_PGRAPH_NSOURCE_ILLEGAL_MTHD)) {
handle = nouveau_namedb_get_class(namedb, class);
if (handle && !nv_call(handle->object, mthd, data))
show &= ~NV_PGRAPH_INTR_ERROR;
}
}
if (stat & NV_PGRAPH_INTR_CONTEXT_SWITCH) {
nv_wr32(priv, NV03_PGRAPH_INTR, NV_PGRAPH_INTR_CONTEXT_SWITCH);
stat &= ~NV_PGRAPH_INTR_CONTEXT_SWITCH;
show &= ~NV_PGRAPH_INTR_CONTEXT_SWITCH;
nv10_graph_context_switch(priv);
}
nv_wr32(priv, NV03_PGRAPH_INTR, stat);
nv_wr32(priv, NV04_PGRAPH_FIFO, 0x00000001);
if (show) {
nv_error(priv, "%s", "");
nouveau_bitfield_print(nv10_graph_intr_name, show);
pr_cont(" nsource:");
nouveau_bitfield_print(nv04_graph_nsource, nsource);
pr_cont(" nstatus:");
nouveau_bitfield_print(nv10_graph_nstatus, nstatus);
pr_cont("\n");
nv_error(priv,
"ch %d [%s] subc %d class 0x%04x mthd 0x%04x data 0x%08x\n",
chid, nouveau_client_name(chan), subc, class, mthd,
data);
}
nouveau_namedb_put(handle);
}
static int
nv10_graph_ctor(struct nouveau_object *parent, struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *data, u32 size,
struct nouveau_object **pobject)
{
struct nv10_graph_priv *priv;
int ret;
ret = nouveau_graph_create(parent, engine, oclass, true, &priv);
*pobject = nv_object(priv);
if (ret)
return ret;
nv_subdev(priv)->unit = 0x00001000;
nv_subdev(priv)->intr = nv10_graph_intr;
nv_engine(priv)->cclass = &nv10_graph_cclass;
if (nv_device(priv)->chipset <= 0x10)
nv_engine(priv)->sclass = nv10_graph_sclass;
else
if (nv_device(priv)->chipset < 0x17 ||
nv_device(priv)->chipset == 0x1a)
nv_engine(priv)->sclass = nv15_graph_sclass;
else
nv_engine(priv)->sclass = nv17_graph_sclass;
nv_engine(priv)->tile_prog = nv10_graph_tile_prog;
spin_lock_init(&priv->lock);
return 0;
}
static void
nv10_graph_dtor(struct nouveau_object *object)
{
struct nv10_graph_priv *priv = (void *)object;
nouveau_graph_destroy(&priv->base);
}
static int
nv10_graph_init(struct nouveau_object *object)
{
struct nouveau_engine *engine = nv_engine(object);
struct nouveau_fb *pfb = nouveau_fb(object);
struct nv10_graph_priv *priv = (void *)engine;
int ret, i;
ret = nouveau_graph_init(&priv->base);
if (ret)
return ret;
nv_wr32(priv, NV03_PGRAPH_INTR , 0xFFFFFFFF);
nv_wr32(priv, NV03_PGRAPH_INTR_EN, 0xFFFFFFFF);
nv_wr32(priv, NV04_PGRAPH_DEBUG_0, 0xFFFFFFFF);
nv_wr32(priv, NV04_PGRAPH_DEBUG_0, 0x00000000);
nv_wr32(priv, NV04_PGRAPH_DEBUG_1, 0x00118700);
nv_wr32(priv, NV04_PGRAPH_DEBUG_2, 0x25f92ad9);
nv_wr32(priv, NV04_PGRAPH_DEBUG_3, 0x55DE0830 | (1 << 29) | (1 << 31));
if (nv_device(priv)->chipset >= 0x17) {
nv_wr32(priv, NV10_PGRAPH_DEBUG_4, 0x1f000000);
nv_wr32(priv, 0x400a10, 0x03ff3fb6);
nv_wr32(priv, 0x400838, 0x002f8684);
nv_wr32(priv, 0x40083c, 0x00115f3f);
nv_wr32(priv, 0x4006b0, 0x40000020);
} else {
nv_wr32(priv, NV10_PGRAPH_DEBUG_4, 0x00000000);
}
for (i = 0; i < pfb->tile.regions; i++)
engine->tile_prog(engine, i);
nv_wr32(priv, NV10_PGRAPH_CTX_SWITCH(0), 0x00000000);
nv_wr32(priv, NV10_PGRAPH_CTX_SWITCH(1), 0x00000000);
nv_wr32(priv, NV10_PGRAPH_CTX_SWITCH(2), 0x00000000);
nv_wr32(priv, NV10_PGRAPH_CTX_SWITCH(3), 0x00000000);
nv_wr32(priv, NV10_PGRAPH_CTX_SWITCH(4), 0x00000000);
nv_wr32(priv, NV10_PGRAPH_STATE, 0xFFFFFFFF);
nv_mask(priv, NV10_PGRAPH_CTX_USER, 0xff000000, 0x1f000000);
nv_wr32(priv, NV10_PGRAPH_CTX_CONTROL, 0x10000100);
nv_wr32(priv, NV10_PGRAPH_FFINTFC_ST2, 0x08000000);
return 0;
}
static int
nv10_graph_fini(struct nouveau_object *object, bool suspend)
{
struct nv10_graph_priv *priv = (void *)object;
return nouveau_graph_fini(&priv->base, suspend);
}
