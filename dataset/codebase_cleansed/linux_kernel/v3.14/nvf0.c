static int
nvf0_graph_fini(struct nouveau_object *object, bool suspend)
{
struct nvc0_graph_priv *priv = (void *)object;
static const struct {
u32 addr;
u32 data;
} magic[] = {
{ 0x020520, 0xfffffffc },
{ 0x020524, 0xfffffffe },
{ 0x020524, 0xfffffffc },
{ 0x020524, 0xfffffff8 },
{ 0x020524, 0xffffffe0 },
{ 0x020530, 0xfffffffe },
{ 0x02052c, 0xfffffffa },
{ 0x02052c, 0xfffffff0 },
{ 0x02052c, 0xffffffc0 },
{ 0x02052c, 0xffffff00 },
{ 0x02052c, 0xfffffc00 },
{ 0x02052c, 0xfffcfc00 },
{ 0x02052c, 0xfff0fc00 },
{ 0x02052c, 0xff80fc00 },
{ 0x020528, 0xfffffffe },
{ 0x020528, 0xfffffffc },
};
int i;
nv_mask(priv, 0x000200, 0x08001000, 0x00000000);
nv_mask(priv, 0x0206b4, 0x00000000, 0x00000000);
for (i = 0; i < ARRAY_SIZE(magic); i++) {
nv_wr32(priv, magic[i].addr, magic[i].data);
nv_wait(priv, magic[i].addr, 0x80000000, 0x00000000);
}
return nouveau_graph_fini(&priv->base, suspend);
}
