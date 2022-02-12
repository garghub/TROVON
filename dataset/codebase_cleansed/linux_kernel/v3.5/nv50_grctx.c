static int
nv50_grctx_generate(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
switch (dev_priv->chipset) {
case 0x50:
case 0x84:
case 0x86:
case 0x92:
case 0x94:
case 0x96:
case 0x98:
case 0xa0:
case 0xa3:
case 0xa5:
case 0xa8:
case 0xaa:
case 0xac:
case 0xaf:
break;
default:
NV_ERROR(ctx->dev, "I don't know how to make a ctxprog for "
"your NV%x card.\n", dev_priv->chipset);
NV_ERROR(ctx->dev, "Disabling acceleration. Please contact "
"the devs.\n");
return -ENOSYS;
}
cp_set (ctx, STATE, RUNNING);
cp_set (ctx, XFER_SWITCH, ENABLE);
cp_bra (ctx, AUTO_SAVE, PENDING, cp_setup_save);
cp_bra (ctx, USER_SAVE, PENDING, cp_setup_save);
cp_name(ctx, cp_check_load);
cp_bra (ctx, AUTO_LOAD, PENDING, cp_setup_auto_load);
cp_bra (ctx, USER_LOAD, PENDING, cp_setup_load);
cp_bra (ctx, ALWAYS, TRUE, cp_prepare_exit);
cp_name(ctx, cp_setup_auto_load);
cp_out (ctx, CP_DISABLE1);
cp_out (ctx, CP_DISABLE2);
cp_out (ctx, CP_ENABLE);
cp_out (ctx, CP_NEXT_TO_SWAP);
cp_set (ctx, UNK01, SET);
cp_name(ctx, cp_setup_load);
cp_out (ctx, CP_NEWCTX);
cp_wait(ctx, NEWCTX, BUSY);
cp_set (ctx, UNK1D, CLEAR);
cp_set (ctx, SWAP_DIRECTION, LOAD);
cp_bra (ctx, UNK0B, SET, cp_prepare_exit);
cp_bra (ctx, ALWAYS, TRUE, cp_swap_state);
cp_name(ctx, cp_setup_save);
cp_set (ctx, UNK1D, SET);
cp_wait(ctx, STATUS, BUSY);
cp_wait(ctx, INTR, PENDING);
cp_bra (ctx, STATUS, BUSY, cp_setup_save);
cp_set (ctx, UNK01, SET);
cp_set (ctx, SWAP_DIRECTION, SAVE);
cp_name(ctx, cp_swap_state);
cp_set (ctx, UNK03, SET);
cp_pos (ctx, 0x00004/4);
cp_ctx (ctx, 0x400828, 1);
cp_pos (ctx, 0x00100/4);
nv50_graph_construct_mmio(ctx);
nv50_graph_construct_xfer1(ctx);
nv50_graph_construct_xfer2(ctx);
cp_bra (ctx, SWAP_DIRECTION, SAVE, cp_check_load);
cp_set (ctx, UNK20, SET);
cp_set (ctx, SWAP_DIRECTION, SAVE);
cp_lsr (ctx, ctx->ctxvals_base);
cp_out (ctx, CP_SET_XFER_POINTER);
cp_lsr (ctx, 4);
cp_out (ctx, CP_SEEK_1);
cp_out (ctx, CP_XFER_1);
cp_wait(ctx, XFER, BUSY);
cp_name(ctx, cp_prepare_exit);
cp_set (ctx, UNK01, CLEAR);
cp_set (ctx, UNK03, CLEAR);
cp_set (ctx, UNK1D, CLEAR);
cp_bra (ctx, USER_SAVE, PENDING, cp_exit);
cp_out (ctx, CP_NEXT_TO_CURRENT);
cp_name(ctx, cp_exit);
cp_set (ctx, USER_SAVE, NOT_PENDING);
cp_set (ctx, USER_LOAD, NOT_PENDING);
cp_set (ctx, XFER_SWITCH, DISABLE);
cp_set (ctx, STATE, STOPPED);
cp_out (ctx, CP_END);
ctx->ctxvals_pos += 0x400;
return 0;
}
void
nv50_grctx_fill(struct drm_device *dev, struct nouveau_gpuobj *mem)
{
nv50_grctx_generate(&(struct nouveau_grctx) {
.dev = dev,
.mode = NOUVEAU_GRCTX_VALS,
.data = mem,
});
}
int
nv50_grctx_init(struct drm_device *dev, u32 *data, u32 max, u32 *len, u32 *cnt)
{
struct nouveau_grctx ctx = {
.dev = dev,
.mode = NOUVEAU_GRCTX_PROG,
.data = data,
.ctxprog_max = max
};
int ret;
ret = nv50_grctx_generate(&ctx);
*cnt = ctx.ctxvals_pos * 4;
*len = ctx.ctxprog_len;
return ret;
}
static void
nv50_graph_construct_mmio(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int i, j;
int offset, base;
uint32_t units = nv_rd32 (ctx->dev, 0x1540);
cp_ctx(ctx, 0x400808, 7);
gr_def(ctx, 0x400814, 0x00000030);
cp_ctx(ctx, 0x400834, 0x32);
if (dev_priv->chipset == 0x50) {
gr_def(ctx, 0x400834, 0xff400040);
gr_def(ctx, 0x400838, 0xfff00080);
gr_def(ctx, 0x40083c, 0xfff70090);
gr_def(ctx, 0x400840, 0xffe806a8);
}
gr_def(ctx, 0x400844, 0x00000002);
if (IS_NVA3F(dev_priv->chipset))
gr_def(ctx, 0x400894, 0x00001000);
gr_def(ctx, 0x4008e8, 0x00000003);
gr_def(ctx, 0x4008ec, 0x00001000);
if (dev_priv->chipset == 0x50)
cp_ctx(ctx, 0x400908, 0xb);
else if (dev_priv->chipset < 0xa0)
cp_ctx(ctx, 0x400908, 0xc);
else
cp_ctx(ctx, 0x400908, 0xe);
if (dev_priv->chipset >= 0xa0)
cp_ctx(ctx, 0x400b00, 0x1);
if (IS_NVA3F(dev_priv->chipset)) {
cp_ctx(ctx, 0x400b10, 0x1);
gr_def(ctx, 0x400b10, 0x0001629d);
cp_ctx(ctx, 0x400b20, 0x1);
gr_def(ctx, 0x400b20, 0x0001629d);
}
nv50_graph_construct_mmio_ddata(ctx);
cp_ctx(ctx, 0x400c08, 0x2);
gr_def(ctx, 0x400c08, 0x0000fe0c);
if (dev_priv->chipset < 0xa0) {
cp_ctx(ctx, 0x401008, 0x4);
gr_def(ctx, 0x401014, 0x00001000);
} else if (!IS_NVA3F(dev_priv->chipset)) {
cp_ctx(ctx, 0x401008, 0x5);
gr_def(ctx, 0x401018, 0x00001000);
} else {
cp_ctx(ctx, 0x401008, 0x5);
gr_def(ctx, 0x401018, 0x00004000);
}
cp_ctx(ctx, 0x401400, 0x8);
cp_ctx(ctx, 0x401424, 0x3);
if (dev_priv->chipset == 0x50)
gr_def(ctx, 0x40142c, 0x0001fd87);
else
gr_def(ctx, 0x40142c, 0x00000187);
cp_ctx(ctx, 0x401540, 0x5);
gr_def(ctx, 0x401550, 0x00001018);
cp_ctx(ctx, 0x401814, 0x1);
gr_def(ctx, 0x401814, 0x000000ff);
if (dev_priv->chipset == 0x50) {
cp_ctx(ctx, 0x40181c, 0xe);
gr_def(ctx, 0x401850, 0x00000004);
} else if (dev_priv->chipset < 0xa0) {
cp_ctx(ctx, 0x40181c, 0xf);
gr_def(ctx, 0x401854, 0x00000004);
} else {
cp_ctx(ctx, 0x40181c, 0x13);
gr_def(ctx, 0x401864, 0x00000004);
}
cp_ctx(ctx, 0x401c00, 0x1);
switch (dev_priv->chipset) {
case 0x50:
gr_def(ctx, 0x401c00, 0x0001005f);
break;
case 0x84:
case 0x86:
case 0x94:
gr_def(ctx, 0x401c00, 0x044d00df);
break;
case 0x92:
case 0x96:
case 0x98:
case 0xa0:
case 0xaa:
case 0xac:
gr_def(ctx, 0x401c00, 0x042500df);
break;
case 0xa3:
case 0xa5:
case 0xa8:
case 0xaf:
gr_def(ctx, 0x401c00, 0x142500df);
break;
}
cp_ctx(ctx, 0x402400, 0x1);
if (dev_priv->chipset == 0x50)
cp_ctx(ctx, 0x402408, 0x1);
else
cp_ctx(ctx, 0x402408, 0x2);
gr_def(ctx, 0x402408, 0x00000600);
cp_ctx(ctx, 0x402800, 0x1);
if (dev_priv->chipset == 0x50)
gr_def(ctx, 0x402800, 0x00000006);
cp_ctx(ctx, 0x402c08, 0x6);
if (dev_priv->chipset != 0x50)
gr_def(ctx, 0x402c14, 0x01000000);
gr_def(ctx, 0x402c18, 0x000000ff);
if (dev_priv->chipset == 0x50)
cp_ctx(ctx, 0x402ca0, 0x1);
else
cp_ctx(ctx, 0x402ca0, 0x2);
if (dev_priv->chipset < 0xa0)
gr_def(ctx, 0x402ca0, 0x00000400);
else if (!IS_NVA3F(dev_priv->chipset))
gr_def(ctx, 0x402ca0, 0x00000800);
else
gr_def(ctx, 0x402ca0, 0x00000400);
cp_ctx(ctx, 0x402cac, 0x4);
cp_ctx(ctx, 0x403004, 0x1);
gr_def(ctx, 0x403004, 0x00000001);
if (dev_priv->chipset >= 0xa0) {
cp_ctx(ctx, 0x403404, 0x1);
gr_def(ctx, 0x403404, 0x00000001);
}
cp_ctx(ctx, 0x405000, 0x1);
switch (dev_priv->chipset) {
case 0x50:
gr_def(ctx, 0x405000, 0x00300080);
break;
case 0x84:
case 0xa0:
case 0xa3:
case 0xa5:
case 0xa8:
case 0xaa:
case 0xac:
case 0xaf:
gr_def(ctx, 0x405000, 0x000e0080);
break;
case 0x86:
case 0x92:
case 0x94:
case 0x96:
case 0x98:
gr_def(ctx, 0x405000, 0x00000080);
break;
}
cp_ctx(ctx, 0x405014, 0x1);
gr_def(ctx, 0x405014, 0x00000004);
cp_ctx(ctx, 0x40501c, 0x1);
cp_ctx(ctx, 0x405024, 0x1);
cp_ctx(ctx, 0x40502c, 0x1);
if (dev_priv->chipset == 0x50)
cp_ctx(ctx, 0x4063e0, 0x1);
if (dev_priv->chipset < 0x90) {
cp_ctx(ctx, 0x406814, 0x2b);
gr_def(ctx, 0x406818, 0x00000f80);
gr_def(ctx, 0x406860, 0x007f0080);
gr_def(ctx, 0x40689c, 0x007f0080);
} else {
cp_ctx(ctx, 0x406814, 0x4);
if (dev_priv->chipset == 0x98)
gr_def(ctx, 0x406818, 0x00000f80);
else
gr_def(ctx, 0x406818, 0x00001f80);
if (IS_NVA3F(dev_priv->chipset))
gr_def(ctx, 0x40681c, 0x00000030);
cp_ctx(ctx, 0x406830, 0x3);
}
for (i = 0; i < 8; i++) {
if (units & (1<<(i+16))) {
cp_ctx(ctx, 0x407000 + (i<<8), 3);
if (dev_priv->chipset == 0x50)
gr_def(ctx, 0x407000 + (i<<8), 0x1b74f820);
else if (dev_priv->chipset != 0xa5)
gr_def(ctx, 0x407000 + (i<<8), 0x3b74f821);
else
gr_def(ctx, 0x407000 + (i<<8), 0x7b74f821);
gr_def(ctx, 0x407004 + (i<<8), 0x89058001);
if (dev_priv->chipset == 0x50) {
cp_ctx(ctx, 0x407010 + (i<<8), 1);
} else if (dev_priv->chipset < 0xa0) {
cp_ctx(ctx, 0x407010 + (i<<8), 2);
gr_def(ctx, 0x407010 + (i<<8), 0x00001000);
gr_def(ctx, 0x407014 + (i<<8), 0x0000001f);
} else {
cp_ctx(ctx, 0x407010 + (i<<8), 3);
gr_def(ctx, 0x407010 + (i<<8), 0x00001000);
if (dev_priv->chipset != 0xa5)
gr_def(ctx, 0x407014 + (i<<8), 0x000000ff);
else
gr_def(ctx, 0x407014 + (i<<8), 0x000001ff);
}
cp_ctx(ctx, 0x407080 + (i<<8), 4);
if (dev_priv->chipset != 0xa5)
gr_def(ctx, 0x407080 + (i<<8), 0x027c10fa);
else
gr_def(ctx, 0x407080 + (i<<8), 0x827c10fa);
if (dev_priv->chipset == 0x50)
gr_def(ctx, 0x407084 + (i<<8), 0x000000c0);
else
gr_def(ctx, 0x407084 + (i<<8), 0x400000c0);
gr_def(ctx, 0x407088 + (i<<8), 0xb7892080);
if (dev_priv->chipset < 0xa0)
cp_ctx(ctx, 0x407094 + (i<<8), 1);
else if (!IS_NVA3F(dev_priv->chipset))
cp_ctx(ctx, 0x407094 + (i<<8), 3);
else {
cp_ctx(ctx, 0x407094 + (i<<8), 4);
gr_def(ctx, 0x4070a0 + (i<<8), 1);
}
}
}
cp_ctx(ctx, 0x407c00, 0x3);
if (dev_priv->chipset < 0x90)
gr_def(ctx, 0x407c00, 0x00010040);
else if (dev_priv->chipset < 0xa0)
gr_def(ctx, 0x407c00, 0x00390040);
else
gr_def(ctx, 0x407c00, 0x003d0040);
gr_def(ctx, 0x407c08, 0x00000022);
if (dev_priv->chipset >= 0xa0) {
cp_ctx(ctx, 0x407c10, 0x3);
cp_ctx(ctx, 0x407c20, 0x1);
cp_ctx(ctx, 0x407c2c, 0x1);
}
if (dev_priv->chipset < 0xa0) {
cp_ctx(ctx, 0x407d00, 0x9);
} else {
cp_ctx(ctx, 0x407d00, 0x15);
}
if (dev_priv->chipset == 0x98)
gr_def(ctx, 0x407d08, 0x00380040);
else {
if (dev_priv->chipset < 0x90)
gr_def(ctx, 0x407d08, 0x00010040);
else if (dev_priv->chipset < 0xa0)
gr_def(ctx, 0x407d08, 0x00390040);
else
gr_def(ctx, 0x407d08, 0x003d0040);
gr_def(ctx, 0x407d0c, 0x00000022);
}
for (i = 0; i < 10; i++) {
if (units & (1<<i)) {
if (dev_priv->chipset < 0xa0)
base = 0x408000 + (i<<12);
else
base = 0x408000 + (i<<11);
if (dev_priv->chipset < 0xa0)
offset = base + 0xc00;
else
offset = base + 0x80;
cp_ctx(ctx, offset + 0x00, 1);
gr_def(ctx, offset + 0x00, 0x0000ff0a);
cp_ctx(ctx, offset + 0x08, 1);
for (j = 0; j < (dev_priv->chipset < 0xa0 ? 2 : 4); j++) {
if (!(units & (1 << (j+24)))) continue;
if (dev_priv->chipset < 0xa0)
offset = base + 0x200 + (j<<7);
else
offset = base + 0x100 + (j<<7);
cp_ctx(ctx, offset, 0x20);
gr_def(ctx, offset + 0x00, 0x01800000);
gr_def(ctx, offset + 0x04, 0x00160000);
gr_def(ctx, offset + 0x08, 0x01800000);
gr_def(ctx, offset + 0x18, 0x0003ffff);
switch (dev_priv->chipset) {
case 0x50:
gr_def(ctx, offset + 0x1c, 0x00080000);
break;
case 0x84:
gr_def(ctx, offset + 0x1c, 0x00880000);
break;
case 0x86:
gr_def(ctx, offset + 0x1c, 0x018c0000);
break;
case 0x92:
case 0x96:
case 0x98:
gr_def(ctx, offset + 0x1c, 0x118c0000);
break;
case 0x94:
gr_def(ctx, offset + 0x1c, 0x10880000);
break;
case 0xa0:
case 0xa5:
gr_def(ctx, offset + 0x1c, 0x310c0000);
break;
case 0xa3:
case 0xa8:
case 0xaa:
case 0xac:
case 0xaf:
gr_def(ctx, offset + 0x1c, 0x300c0000);
break;
}
gr_def(ctx, offset + 0x40, 0x00010401);
if (dev_priv->chipset == 0x50)
gr_def(ctx, offset + 0x48, 0x00000040);
else
gr_def(ctx, offset + 0x48, 0x00000078);
gr_def(ctx, offset + 0x50, 0x000000bf);
gr_def(ctx, offset + 0x58, 0x00001210);
if (dev_priv->chipset == 0x50)
gr_def(ctx, offset + 0x5c, 0x00000080);
else
gr_def(ctx, offset + 0x5c, 0x08000080);
if (dev_priv->chipset >= 0xa0)
gr_def(ctx, offset + 0x68, 0x0000003e);
}
if (dev_priv->chipset < 0xa0)
cp_ctx(ctx, base + 0x300, 0x4);
else
cp_ctx(ctx, base + 0x300, 0x5);
if (dev_priv->chipset == 0x50)
gr_def(ctx, base + 0x304, 0x00007070);
else if (dev_priv->chipset < 0xa0)
gr_def(ctx, base + 0x304, 0x00027070);
else if (!IS_NVA3F(dev_priv->chipset))
gr_def(ctx, base + 0x304, 0x01127070);
else
gr_def(ctx, base + 0x304, 0x05127070);
if (dev_priv->chipset < 0xa0)
cp_ctx(ctx, base + 0x318, 1);
else
cp_ctx(ctx, base + 0x320, 1);
if (dev_priv->chipset == 0x50)
gr_def(ctx, base + 0x318, 0x0003ffff);
else if (dev_priv->chipset < 0xa0)
gr_def(ctx, base + 0x318, 0x03ffffff);
else
gr_def(ctx, base + 0x320, 0x07ffffff);
if (dev_priv->chipset < 0xa0)
cp_ctx(ctx, base + 0x324, 5);
else
cp_ctx(ctx, base + 0x328, 4);
if (dev_priv->chipset < 0xa0) {
cp_ctx(ctx, base + 0x340, 9);
offset = base + 0x340;
} else if (!IS_NVA3F(dev_priv->chipset)) {
cp_ctx(ctx, base + 0x33c, 0xb);
offset = base + 0x344;
} else {
cp_ctx(ctx, base + 0x33c, 0xd);
offset = base + 0x344;
}
gr_def(ctx, offset + 0x0, 0x00120407);
gr_def(ctx, offset + 0x4, 0x05091507);
if (dev_priv->chipset == 0x84)
gr_def(ctx, offset + 0x8, 0x05100202);
else
gr_def(ctx, offset + 0x8, 0x05010202);
gr_def(ctx, offset + 0xc, 0x00030201);
if (dev_priv->chipset == 0xa3)
cp_ctx(ctx, base + 0x36c, 1);
cp_ctx(ctx, base + 0x400, 2);
gr_def(ctx, base + 0x404, 0x00000040);
cp_ctx(ctx, base + 0x40c, 2);
gr_def(ctx, base + 0x40c, 0x0d0c0b0a);
gr_def(ctx, base + 0x410, 0x00141210);
if (dev_priv->chipset < 0xa0)
offset = base + 0x800;
else
offset = base + 0x500;
cp_ctx(ctx, offset, 6);
gr_def(ctx, offset + 0x0, 0x000001f0);
gr_def(ctx, offset + 0x4, 0x00000001);
gr_def(ctx, offset + 0x8, 0x00000003);
if (dev_priv->chipset == 0x50 || IS_NVAAF(dev_priv->chipset))
gr_def(ctx, offset + 0xc, 0x00008000);
gr_def(ctx, offset + 0x14, 0x00039e00);
cp_ctx(ctx, offset + 0x1c, 2);
if (dev_priv->chipset == 0x50)
gr_def(ctx, offset + 0x1c, 0x00000040);
else
gr_def(ctx, offset + 0x1c, 0x00000100);
gr_def(ctx, offset + 0x20, 0x00003800);
if (dev_priv->chipset >= 0xa0) {
cp_ctx(ctx, base + 0x54c, 2);
if (!IS_NVA3F(dev_priv->chipset))
gr_def(ctx, base + 0x54c, 0x003fe006);
else
gr_def(ctx, base + 0x54c, 0x003fe007);
gr_def(ctx, base + 0x550, 0x003fe000);
}
if (dev_priv->chipset < 0xa0)
offset = base + 0xa00;
else
offset = base + 0x680;
cp_ctx(ctx, offset, 1);
gr_def(ctx, offset, 0x00404040);
if (dev_priv->chipset < 0xa0)
offset = base + 0xe00;
else
offset = base + 0x700;
cp_ctx(ctx, offset, 2);
if (dev_priv->chipset < 0xa0)
gr_def(ctx, offset, 0x0077f005);
else if (dev_priv->chipset == 0xa5)
gr_def(ctx, offset, 0x6cf7f007);
else if (dev_priv->chipset == 0xa8)
gr_def(ctx, offset, 0x6cfff007);
else if (dev_priv->chipset == 0xac)
gr_def(ctx, offset, 0x0cfff007);
else
gr_def(ctx, offset, 0x0cf7f007);
if (dev_priv->chipset == 0x50)
gr_def(ctx, offset + 0x4, 0x00007fff);
else if (dev_priv->chipset < 0xa0)
gr_def(ctx, offset + 0x4, 0x003f7fff);
else
gr_def(ctx, offset + 0x4, 0x02bf7fff);
cp_ctx(ctx, offset + 0x2c, 1);
if (dev_priv->chipset == 0x50) {
cp_ctx(ctx, offset + 0x50, 9);
gr_def(ctx, offset + 0x54, 0x000003ff);
gr_def(ctx, offset + 0x58, 0x00000003);
gr_def(ctx, offset + 0x5c, 0x00000003);
gr_def(ctx, offset + 0x60, 0x000001ff);
gr_def(ctx, offset + 0x64, 0x0000001f);
gr_def(ctx, offset + 0x68, 0x0000000f);
gr_def(ctx, offset + 0x6c, 0x0000000f);
} else if (dev_priv->chipset < 0xa0) {
cp_ctx(ctx, offset + 0x50, 1);
cp_ctx(ctx, offset + 0x70, 1);
} else {
cp_ctx(ctx, offset + 0x50, 1);
cp_ctx(ctx, offset + 0x60, 5);
}
}
}
}
static void
dd_emit(struct nouveau_grctx *ctx, int num, uint32_t val) {
int i;
if (val && ctx->mode == NOUVEAU_GRCTX_VALS)
for (i = 0; i < num; i++)
nv_wo32(ctx->data, 4 * (ctx->ctxvals_pos + i), val);
ctx->ctxvals_pos += num;
}
static void
nv50_graph_construct_mmio_ddata(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int base, num;
base = ctx->ctxvals_pos;
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0x94)
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0x100);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0x3fffff);
dd_emit(ctx, 1, 0x1fff);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 1);
if (IS_NVA3F(dev_priv->chipset))
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 7);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 7);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
if (dev_priv->chipset == 0x50) {
dd_emit(ctx, 4, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0xa);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0x40);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 0x100);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0x100);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 0);
}
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 2, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0x100);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 2, 0);
dd_emit(ctx, 1, 0x100);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0x100);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 2, 0);
dd_emit(ctx, 1, 0x100);
if (dev_priv->chipset == 0x50) {
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 3);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
}
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 0x70);
dd_emit(ctx, 1, 0x80);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset)) {
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
} else {
dd_emit(ctx, 1, 0);
}
dd_emit(ctx, 1, 0xc);
if (dev_priv->chipset != 0x50)
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 8);
dd_emit(ctx, 1, 0x14);
if (dev_priv->chipset == 0x50) {
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
} else {
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0x29);
dd_emit(ctx, 1, 0x27);
dd_emit(ctx, 1, 0x26);
dd_emit(ctx, 1, 8);
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 0x27);
dd_emit(ctx, 1, 0);
}
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 3);
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 5);
dd_emit(ctx, 1, 6);
dd_emit(ctx, 1, 7);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 8, 0);
dd_emit(ctx, 8, 0);
dd_emit(ctx, 1, 0xcf);
dd_emit(ctx, 7, 0);
if (dev_priv->chipset != 0x50)
dd_emit(ctx, 3, 0);
else
dd_emit(ctx, 2, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0x80);
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 4);
if (IS_NVA3F(dev_priv->chipset)) {
dd_emit(ctx, 1, 3);
dd_emit(ctx, 1, 0);
}
if (dev_priv->chipset != 0x50)
dd_emit(ctx, 1, 3);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50)
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0x12);
dd_emit(ctx, 1, 0x10);
dd_emit(ctx, 1, 0xc);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 4);
if (dev_priv->chipset >= 0xa0)
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0x3fffff);
dd_emit(ctx, 1, 0x1fff);
dd_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50)
dd_emit(ctx, 8, 0);
if (dev_priv->chipset >= 0xa0) {
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 0);
}
dd_emit(ctx, 1, 4);
dd_emit(ctx, 1, 0x14);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 2);
if (dev_priv->chipset >= 0xa0)
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0xa0)
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 0x1000);
if (dev_priv->chipset != 0x50) {
dd_emit(ctx, 1, 0xe00);
dd_emit(ctx, 1, 0x1000);
dd_emit(ctx, 1, 0x1e00);
}
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0x200);
if (IS_NVA3F(dev_priv->chipset))
dd_emit(ctx, 1, 0x200);
dd_emit(ctx, 1, 0);
if (dev_priv->chipset < 0xa0) {
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0x70);
dd_emit(ctx, 1, 0x80);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0x70);
dd_emit(ctx, 1, 0x80);
dd_emit(ctx, 1, 0);
} else {
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0xf0);
dd_emit(ctx, 1, 0xff);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0xf0);
dd_emit(ctx, 1, 0xff);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 9);
}
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0xcf);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0xcf);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 2);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 1);
dd_emit(ctx, 1, 0);
dd_emit(ctx, 1, 0xcf);
dd_emit(ctx, 1, 0xcf);
dd_emit(ctx, 1, 1);
num = ctx->ctxvals_pos - base;
ctx->ctxvals_pos = base;
if (IS_NVA3F(dev_priv->chipset))
cp_ctx(ctx, 0x404800, num);
else
cp_ctx(ctx, 0x405400, num);
}
static void
xf_emit(struct nouveau_grctx *ctx, int num, uint32_t val) {
int i;
if (val && ctx->mode == NOUVEAU_GRCTX_VALS)
for (i = 0; i < num; i++)
nv_wo32(ctx->data, 4 * (ctx->ctxvals_pos + (i << 3)), val);
ctx->ctxvals_pos += num << 3;
}
static void
nv50_graph_construct_xfer1(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int i;
int offset;
int size = 0;
uint32_t units = nv_rd32 (ctx->dev, 0x1540);
offset = (ctx->ctxvals_pos+0x3f)&~0x3f;
ctx->ctxvals_base = offset;
if (dev_priv->chipset < 0xa0) {
ctx->ctxvals_pos = offset;
nv50_graph_construct_gene_dispatch(ctx);
nv50_graph_construct_gene_m2mf(ctx);
nv50_graph_construct_gene_unk24xx(ctx);
nv50_graph_construct_gene_clipid(ctx);
nv50_graph_construct_gene_zcull(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 0x1;
nv50_graph_construct_gene_vfetch(ctx);
nv50_graph_construct_gene_eng2d(ctx);
nv50_graph_construct_gene_csched(ctx);
nv50_graph_construct_gene_ropm1(ctx);
nv50_graph_construct_gene_ropm2(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 0x2;
nv50_graph_construct_gene_ccache(ctx);
nv50_graph_construct_gene_unk1cxx(ctx);
nv50_graph_construct_gene_strmout(ctx);
nv50_graph_construct_gene_unk14xx(ctx);
nv50_graph_construct_gene_unk10xx(ctx);
nv50_graph_construct_gene_unk34xx(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 3;
for (i = 0; i < 6; i++)
if (units & (1 << (i + 16)))
nv50_graph_construct_gene_ropc(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
for (i = 0; i < 4; i++) {
ctx->ctxvals_pos = offset + 4 + i;
if (units & (1 << (2 * i)))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << (2 * i + 1)))
nv50_graph_construct_xfer_tp(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
}
} else {
ctx->ctxvals_pos = offset;
nv50_graph_construct_gene_dispatch(ctx);
nv50_graph_construct_gene_m2mf(ctx);
nv50_graph_construct_gene_unk34xx(ctx);
nv50_graph_construct_gene_csched(ctx);
nv50_graph_construct_gene_unk1cxx(ctx);
nv50_graph_construct_gene_strmout(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 1;
nv50_graph_construct_gene_unk10xx(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 2;
if (dev_priv->chipset == 0xa0)
nv50_graph_construct_gene_unk14xx(ctx);
nv50_graph_construct_gene_unk24xx(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 3;
nv50_graph_construct_gene_vfetch(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 4;
nv50_graph_construct_gene_ccache(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 5;
nv50_graph_construct_gene_ropm2(ctx);
nv50_graph_construct_gene_ropm1(ctx);
for (i = 0; i < 8; i++)
if (units & (1<<(i+16)))
nv50_graph_construct_gene_ropc(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 6;
nv50_graph_construct_gene_zcull(ctx);
nv50_graph_construct_gene_clipid(ctx);
nv50_graph_construct_gene_eng2d(ctx);
if (units & (1 << 0))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 1))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 2))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 3))
nv50_graph_construct_xfer_tp(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 7;
if (dev_priv->chipset == 0xa0) {
if (units & (1 << 4))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 5))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 6))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 7))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 8))
nv50_graph_construct_xfer_tp(ctx);
if (units & (1 << 9))
nv50_graph_construct_xfer_tp(ctx);
} else {
nv50_graph_construct_gene_unk14xx(ctx);
}
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
}
ctx->ctxvals_pos = offset + size * 8;
ctx->ctxvals_pos = (ctx->ctxvals_pos+0x3f)&~0x3f;
cp_lsr (ctx, offset);
cp_out (ctx, CP_SET_XFER_POINTER);
cp_lsr (ctx, size);
cp_out (ctx, CP_SEEK_1);
cp_out (ctx, CP_XFER_1);
cp_wait(ctx, XFER, BUSY);
}
static void
nv50_graph_construct_gene_dispatch(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 5, 0);
else if (!IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 6, 0);
else
xf_emit(ctx, 4, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 8*3, 0);
else
xf_emit(ctx, 0x100*3, 0);
xf_emit(ctx, 3, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 3, 0);
xf_emit(ctx, 9, 0);
xf_emit(ctx, 9, 0);
xf_emit(ctx, 9, 0);
xf_emit(ctx, 9, 0);
if (dev_priv->chipset < 0x90)
xf_emit(ctx, 4, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 6*2, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 6*2, 0);
xf_emit(ctx, 2, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 0x1c, 0);
else if (dev_priv->chipset < 0xa0)
xf_emit(ctx, 0x1e, 0);
else
xf_emit(ctx, 0x22, 0);
xf_emit(ctx, 0x15, 0);
}
static void
nv50_graph_construct_gene_m2mf(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int smallm2mf = 0;
if (dev_priv->chipset < 0x92 || dev_priv->chipset == 0x98)
smallm2mf = 1;
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0x21);
xf_emit (ctx, 1, 1);
xf_emit (ctx, 1, 0x2);
xf_emit (ctx, 1, 0x100);
xf_emit (ctx, 1, 0x100);
xf_emit (ctx, 1, 1);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 1);
xf_emit (ctx, 1, 0x2);
xf_emit (ctx, 1, 0x100);
xf_emit (ctx, 1, 0x100);
xf_emit (ctx, 1, 1);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
xf_emit (ctx, 1, 0);
if (smallm2mf)
xf_emit(ctx, 0x40, 0);
else
xf_emit(ctx, 0x100, 0);
xf_emit(ctx, 4, 0);
if (smallm2mf)
xf_emit(ctx, 0x400, 0);
else
xf_emit(ctx, 0x800, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 0x40, 0);
xf_emit(ctx, 0x6, 0);
}
static void
nv50_graph_construct_gene_ccache(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 2, 0);
xf_emit(ctx, 0x800, 0);
switch (dev_priv->chipset) {
case 0x50:
case 0x92:
case 0xa0:
xf_emit(ctx, 0x2b, 0);
break;
case 0x84:
xf_emit(ctx, 0x29, 0);
break;
case 0x94:
case 0x96:
case 0xa3:
xf_emit(ctx, 0x27, 0);
break;
case 0x86:
case 0x98:
case 0xa5:
case 0xa8:
case 0xaa:
case 0xac:
case 0xaf:
xf_emit(ctx, 0x25, 0);
break;
}
xf_emit(ctx, 0x100, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x30, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 0x100, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x3fffff);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x1fff);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_unk10xx(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int i;
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x80);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0x80c14);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 1, 0x3ff);
else
xf_emit(ctx, 1, 0x7ff);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
for (i = 0; i < 8; i++) {
switch (dev_priv->chipset) {
case 0x50:
case 0x86:
case 0x98:
case 0xaa:
case 0xac:
xf_emit(ctx, 0xa0, 0);
break;
case 0x84:
case 0x92:
case 0x94:
case 0x96:
xf_emit(ctx, 0x120, 0);
break;
case 0xa5:
case 0xa8:
xf_emit(ctx, 0x100, 0);
break;
case 0xa0:
case 0xa3:
case 0xaf:
xf_emit(ctx, 0x400, 0);
break;
}
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 0);
}
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x80);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x27);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x26);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_unk34xx(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x10, 0x04000000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x20, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x04e3bfdf);
xf_emit(ctx, 1, 0x04e3bfdf);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x1fe21);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 1, 0x0fac6881);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 1);
xf_emit(ctx, 3, 0);
}
}
static void
nv50_graph_construct_gene_unk14xx(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
if (dev_priv->chipset != 0x50) {
xf_emit(ctx, 5, 0);
xf_emit(ctx, 1, 0x80c14);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x804);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 4);
xf_emit(ctx, 1, 0x8100c12);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x804);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x1a);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 0x7f);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x80c14);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x8100c12);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x8100c12);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 1, 0x3ff);
else
xf_emit(ctx, 1, 0x7ff);
xf_emit(ctx, 1, 0x80c14);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x30, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x30, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0x88);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x26);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x3f800000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x1a);
xf_emit(ctx, 1, 0x10);
if (dev_priv->chipset != 0x50) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 0x20, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x52);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x26);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x1a);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x00ffff00);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_zcull(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 1, 0x3f);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 2, 0x04000000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x1001);
xf_emit(ctx, 4, 0xffff);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 0x10, 0x3f800000);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_clipid(struct nouveau_grctx *ctx)
{
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2, 0x04000000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x80);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x80);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_unk24xx(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int i;
xf_emit(ctx, 0x33, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 4, 0);
xf_emit(ctx, 0xe10, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 9, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 0xe10, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 9, 0);
} else {
xf_emit(ctx, 0xc, 0);
xf_emit(ctx, 0xe10, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 0xc, 0);
xf_emit(ctx, 0xe10, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0x8100c12);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x8100c12);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x80c14);
xf_emit(ctx, 1, 1);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 2, 4);
xf_emit(ctx, 1, 0x80c14);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x8100c12);
xf_emit(ctx, 1, 0x27);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
for (i = 0; i < 10; i++) {
xf_emit(ctx, 0x40, 0);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 0x10, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x8100c12);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_vfetch(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int acnt = 0x10, rep, i;
if (IS_NVA3F(dev_priv->chipset))
acnt = 0x20;
if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, (acnt/8)-1, 0);
xf_emit(ctx, acnt/8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x20);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0xb, 0);
else if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 0x9, 0);
else
xf_emit(ctx, 0x8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x1a);
xf_emit(ctx, 0xc, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 8);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 1, 0x3ff);
else
xf_emit(ctx, 1, 0x7ff);
if (dev_priv->chipset == 0xa8)
xf_emit(ctx, 1, 0x1e00);
xf_emit(ctx, 0xc, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, (acnt/8)-1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset > 0x50 && dev_priv->chipset < 0xa0)
xf_emit(ctx, 2, 0);
else
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2, 0);
} else {
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, acnt, 0);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 1, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 3, 0);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, acnt, 0);
xf_emit(ctx, 3, 0);
}
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 2, 0);
else
xf_emit(ctx, 5, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset < 0xa0) {
xf_emit(ctx, 0x41, 0);
xf_emit(ctx, 0x11, 0);
} else if (!IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0x50, 0);
else
xf_emit(ctx, 0x58, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, (acnt/8)-1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, acnt*4, 0);
xf_emit(ctx, 4, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0x1d, 0);
else
xf_emit(ctx, 0x16, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, (acnt/8)-1, 0);
if (dev_priv->chipset < 0xa0)
xf_emit(ctx, 8, 0);
else if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0xc, 0);
else
xf_emit(ctx, 7, 0);
xf_emit(ctx, 0xa, 0);
if (dev_priv->chipset == 0xa0)
rep = 0xc;
else
rep = 4;
for (i = 0; i < rep; i++) {
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0x20, 0);
xf_emit(ctx, 0x200, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, (acnt/8)-1, 0);
xf_emit(ctx, acnt/8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 7, 0);
else
xf_emit(ctx, 5, 0);
}
static void
nv50_graph_construct_gene_eng2d(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset < 0xa0) {
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2, 1);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x100);
xf_emit(ctx, 1, 0x100);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 8);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0xcf);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x15);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x4444480);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 0x27, 0);
}
static void
nv50_graph_construct_gene_csched(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x8100c12);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x100);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x10001);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x10001);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x10001);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 0x40, 0);
switch (dev_priv->chipset) {
case 0x50:
case 0x92:
xf_emit(ctx, 8, 0);
xf_emit(ctx, 0x80, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 0x10*2, 0);
break;
case 0x84:
xf_emit(ctx, 8, 0);
xf_emit(ctx, 0x60, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 0xc*2, 0);
break;
case 0x94:
case 0x96:
xf_emit(ctx, 8, 0);
xf_emit(ctx, 0x40, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 8*2, 0);
break;
case 0x86:
case 0x98:
xf_emit(ctx, 4, 0);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2*2, 0);
break;
case 0xa0:
xf_emit(ctx, 8, 0);
xf_emit(ctx, 0xf0, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 0x1e*2, 0);
break;
case 0xa3:
xf_emit(ctx, 8, 0);
xf_emit(ctx, 0x60, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 0xc*2, 0);
break;
case 0xa5:
case 0xaf:
xf_emit(ctx, 8, 0);
xf_emit(ctx, 0x30, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 6*2, 0);
break;
case 0xaa:
xf_emit(ctx, 0x12, 0);
break;
case 0xa8:
case 0xac:
xf_emit(ctx, 4, 0);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2*2, 0);
break;
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_unk1cxx(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0x3f800000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0x1a);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x00ffff00);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 3);
else if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 2, 0x04000000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 5);
xf_emit(ctx, 1, 0x52);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
}
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 0x10, 0x3f800000);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 0x20, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x8100c12);
xf_emit(ctx, 1, 5);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0xffff);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 3);
if (dev_priv->chipset < 0xa0)
xf_emit(ctx, 0x1c, 0);
else if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0x9, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x00ffff00);
xf_emit(ctx, 1, 0x1a);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50) {
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
}
if (dev_priv->chipset < 0xa0)
xf_emit(ctx, 0x25, 0);
else
xf_emit(ctx, 0x3b, 0);
}
static void
nv50_graph_construct_gene_strmout(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 1, 0x102);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 4);
if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 0);
}
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 1, 0x3ff);
else
xf_emit(ctx, 1, 0x7ff);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x102);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 4);
if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x20, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
}
static void
nv50_graph_construct_gene_ropm1(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 1, 0x4e3bfdf);
xf_emit(ctx, 1, 0x4e3bfdf);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_ropm2(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0x4e3bfdf);
xf_emit(ctx, 1, 0x4e3bfdf);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_gene_ropc(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int magic2;
if (dev_priv->chipset == 0x50) {
magic2 = 0x00003e60;
} else if (!IS_NVA3F(dev_priv->chipset)) {
magic2 = 0x001ffe67;
} else {
magic2 = 0x00087e67;
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, magic2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0xa0 && !IS_NVAAF(dev_priv->chipset))
xf_emit(ctx, 1, 0x15);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x86 || dev_priv->chipset == 0x92 || dev_priv->chipset == 0x98 || dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0x400);
xf_emit(ctx, 1, 0x300);
xf_emit(ctx, 1, 0x1001);
if (dev_priv->chipset != 0xa0) {
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 0);
else
xf_emit(ctx, 1, 0x15);
}
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 0x10, 0x3f800000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x10);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x3f);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0x1001);
xf_emit(ctx, 0xb, 0);
} else {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset != 0x50) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, magic2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x0fac6881);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
} else if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
} else {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 4, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x50, 0);
}
static void
nv50_graph_construct_xfer_unk84xx(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int magic3;
switch (dev_priv->chipset) {
case 0x50:
magic3 = 0x1000;
break;
case 0x86:
case 0x98:
case 0xa8:
case 0xaa:
case 0xac:
case 0xaf:
magic3 = 0x1e00;
break;
default:
magic3 = 0;
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0x1f, 0);
else if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 0x0f, 0);
else
xf_emit(ctx, 0x10, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 1, 0x03020100);
else
xf_emit(ctx, 1, 0x00608080);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0x80);
if (magic3)
xf_emit(ctx, 1, magic3);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 0x1f, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0x80);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0x03020100);
xf_emit(ctx, 1, 3);
if (magic3)
xf_emit(ctx, 1, magic3);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x94 || dev_priv->chipset == 0x96)
xf_emit(ctx, 0x1020, 0);
else if (dev_priv->chipset < 0xa0)
xf_emit(ctx, 0xa20, 0);
else if (!IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0x210, 0);
else
xf_emit(ctx, 0x410, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_xfer_tprop(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int magic1, magic2;
if (dev_priv->chipset == 0x50) {
magic1 = 0x3ff;
magic2 = 0x00003e60;
} else if (!IS_NVA3F(dev_priv->chipset)) {
magic1 = 0x7ff;
magic2 = 0x001ffe67;
} else {
magic1 = 0x7ff;
magic2 = 0x00087e67;
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 4, 0xffff);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
} else if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
} else {
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0xcf);
xf_emit(ctx, 1, 0xcf);
xf_emit(ctx, 1, 0xcf);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, magic2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 1);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 1, 0);
else
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, magic1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 8, 8);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 8, 0x400);
xf_emit(ctx, 8, 0x300);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x20);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 0x100);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x40);
xf_emit(ctx, 1, 0x100);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, magic2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x400);
xf_emit(ctx, 1, 0x300);
xf_emit(ctx, 1, 0x1001);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 1, 0x0fac6881);
xf_emit(ctx, 1, magic2);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0xfac6881);
xf_emit(ctx, 4, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 1);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 0x9, 0);
else
xf_emit(ctx, 0x8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0xfac6881);
xf_emit(ctx, 1, 0xf);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 5, 0);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
}
}
}
static void
nv50_graph_construct_xfer_tex(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 2, 0);
if (dev_priv->chipset != 0x50)
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 1, 0);
else
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0x2a712488);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x4085c000);
xf_emit(ctx, 1, 0x40);
xf_emit(ctx, 1, 0x100);
xf_emit(ctx, 1, 0x10100);
xf_emit(ctx, 1, 0x02800000);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x50) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
} else if (!IS_NVAAF(dev_priv->chipset)) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
} else {
xf_emit(ctx, 0x6, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
static void
nv50_graph_construct_xfer_unk8cxx(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 2, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x04e3bfdf);
xf_emit(ctx, 1, 0x04e3bfdf);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x00ffff00);
xf_emit(ctx, 1, 1);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x00ffff00);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x30201000);
xf_emit(ctx, 1, 0x70605040);
xf_emit(ctx, 1, 0xb8a89888);
xf_emit(ctx, 1, 0xf8e8d8c8);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x1a);
}
static void
nv50_graph_construct_xfer_tp(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
if (dev_priv->chipset < 0xa0) {
nv50_graph_construct_xfer_unk84xx(ctx);
nv50_graph_construct_xfer_tprop(ctx);
nv50_graph_construct_xfer_tex(ctx);
nv50_graph_construct_xfer_unk8cxx(ctx);
} else {
nv50_graph_construct_xfer_tex(ctx);
nv50_graph_construct_xfer_tprop(ctx);
nv50_graph_construct_xfer_unk8cxx(ctx);
nv50_graph_construct_xfer_unk84xx(ctx);
}
}
static void
nv50_graph_construct_xfer_mpc(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int i, mpcnt = 2;
switch (dev_priv->chipset) {
case 0x98:
case 0xaa:
mpcnt = 1;
break;
case 0x50:
case 0x84:
case 0x86:
case 0x92:
case 0x94:
case 0x96:
case 0xa8:
case 0xac:
mpcnt = 2;
break;
case 0xa0:
case 0xa3:
case 0xa5:
case 0xaf:
mpcnt = 3;
break;
}
for (i = 0; i < mpcnt; i++) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x80);
xf_emit(ctx, 1, 0x80007004);
xf_emit(ctx, 1, 0x04000400);
if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 1, 0xc0);
xf_emit(ctx, 1, 0x1000);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x86 || dev_priv->chipset == 0x98 || dev_priv->chipset == 0xa8 || IS_NVAAF(dev_priv->chipset)) {
xf_emit(ctx, 1, 0xe00);
xf_emit(ctx, 1, 0x1e00);
}
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 2, 0x1000);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 2);
if (IS_NVAAF(dev_priv->chipset))
xf_emit(ctx, 0xb, 0);
else if (dev_priv->chipset >= 0xa0)
xf_emit(ctx, 0xc, 0);
else
xf_emit(ctx, 0xa, 0);
}
xf_emit(ctx, 1, 0x08100c12);
xf_emit(ctx, 1, 0);
if (dev_priv->chipset >= 0xa0) {
xf_emit(ctx, 1, 0x1fe21);
}
xf_emit(ctx, 3, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 4, 0xffff);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0x10001);
xf_emit(ctx, 1, 0x10001);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x1fe21);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0x08100c12);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 7, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0xfac6881);
xf_emit(ctx, 1, 0);
if (IS_NVA3F(dev_priv->chipset))
xf_emit(ctx, 1, 3);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
xf_emit(ctx, 8, 0);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 2);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 1, 1);
if (IS_NVA3F(dev_priv->chipset)) {
xf_emit(ctx, 1, 0);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 2);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 8, 1);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 0);
}
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 4);
if (dev_priv->chipset == 0x50)
xf_emit(ctx, 0x3a0, 0);
else if (dev_priv->chipset < 0x94)
xf_emit(ctx, 0x3a2, 0);
else if (dev_priv->chipset == 0x98 || dev_priv->chipset == 0xaa)
xf_emit(ctx, 0x39f, 0);
else
xf_emit(ctx, 0x3a3, 0);
xf_emit(ctx, 1, 0x11);
xf_emit(ctx, 1, 0);
xf_emit(ctx, 1, 1);
xf_emit(ctx, 0x2d, 0);
}
static void
nv50_graph_construct_xfer2(struct nouveau_grctx *ctx)
{
struct drm_nouveau_private *dev_priv = ctx->dev->dev_private;
int i;
uint32_t offset;
uint32_t units = nv_rd32 (ctx->dev, 0x1540);
int size = 0;
offset = (ctx->ctxvals_pos+0x3f)&~0x3f;
if (dev_priv->chipset < 0xa0) {
for (i = 0; i < 8; i++) {
ctx->ctxvals_pos = offset + i;
if (i == 0)
xf_emit(ctx, 1, 0x08100c12);
if (units & (1 << i))
nv50_graph_construct_xfer_mpc(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
}
} else {
ctx->ctxvals_pos = offset;
xf_emit(ctx, 1, 0x08100c12);
if (units & (1 << 0))
nv50_graph_construct_xfer_mpc(ctx);
if (units & (1 << 1))
nv50_graph_construct_xfer_mpc(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 1;
if (units & (1 << 2))
nv50_graph_construct_xfer_mpc(ctx);
if (units & (1 << 3))
nv50_graph_construct_xfer_mpc(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 2;
if (units & (1 << 4))
nv50_graph_construct_xfer_mpc(ctx);
if (units & (1 << 5))
nv50_graph_construct_xfer_mpc(ctx);
if (units & (1 << 6))
nv50_graph_construct_xfer_mpc(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
ctx->ctxvals_pos = offset + 3;
if (units & (1 << 7))
nv50_graph_construct_xfer_mpc(ctx);
if (units & (1 << 8))
nv50_graph_construct_xfer_mpc(ctx);
if (units & (1 << 9))
nv50_graph_construct_xfer_mpc(ctx);
if ((ctx->ctxvals_pos-offset)/8 > size)
size = (ctx->ctxvals_pos-offset)/8;
}
ctx->ctxvals_pos = offset + size * 8;
ctx->ctxvals_pos = (ctx->ctxvals_pos+0x3f)&~0x3f;
cp_lsr (ctx, offset);
cp_out (ctx, CP_SET_XFER_POINTER);
cp_lsr (ctx, size);
cp_out (ctx, CP_SEEK_2);
cp_out (ctx, CP_XFER_2);
cp_wait(ctx, XFER, BUSY);
}
