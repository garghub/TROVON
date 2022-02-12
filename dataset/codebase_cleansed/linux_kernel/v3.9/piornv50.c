static struct nouveau_i2c_port *
nv50_pior_dp_find(struct nouveau_disp *disp, struct dcb_output *outp)
{
struct nouveau_i2c *i2c = nouveau_i2c(disp);
return i2c->find_type(i2c, NV_I2C_TYPE_EXTAUX(outp->extdev));
}
static int
nv50_pior_dp_pattern(struct nouveau_disp *disp, struct dcb_output *outp,
int head, int pattern)
{
struct nouveau_i2c_port *port;
int ret = -EINVAL;
port = nv50_pior_dp_find(disp, outp);
if (port) {
if (port->func->pattern)
ret = port->func->pattern(port, pattern);
else
ret = 0;
}
return ret;
}
static int
nv50_pior_dp_lnk_ctl(struct nouveau_disp *disp, struct dcb_output *outp,
int head, int lane_nr, int link_bw, bool enh)
{
struct nouveau_i2c_port *port;
int ret = -EINVAL;
port = nv50_pior_dp_find(disp, outp);
if (port && port->func->lnk_ctl)
ret = port->func->lnk_ctl(port, lane_nr, link_bw, enh);
return ret;
}
static int
nv50_pior_dp_drv_ctl(struct nouveau_disp *disp, struct dcb_output *outp,
int head, int lane, int vsw, int pre)
{
struct nouveau_i2c_port *port;
int ret = -EINVAL;
port = nv50_pior_dp_find(disp, outp);
if (port) {
if (port->func->drv_ctl)
ret = port->func->drv_ctl(port, lane, vsw, pre);
else
ret = 0;
}
return ret;
}
int
nv50_pior_power(struct nv50_disp_priv *priv, int or, u32 data)
{
const u32 stat = data & NV50_DISP_PIOR_PWR_STATE;
const u32 soff = (or * 0x800);
nv_wait(priv, 0x61e004 + soff, 0x80000000, 0x00000000);
nv_mask(priv, 0x61e004 + soff, 0x80000101, 0x80000000 | stat);
nv_wait(priv, 0x61e004 + soff, 0x80000000, 0x00000000);
return 0;
}
int
nv50_pior_mthd(struct nouveau_object *object, u32 mthd, void *args, u32 size)
{
struct nv50_disp_priv *priv = (void *)object->engine;
const u8 type = (mthd & NV50_DISP_PIOR_MTHD_TYPE) >> 12;
const u8 or = (mthd & NV50_DISP_PIOR_MTHD_OR);
u32 *data = args;
int ret;
if (size < sizeof(u32))
return -EINVAL;
mthd &= ~NV50_DISP_PIOR_MTHD_TYPE;
mthd &= ~NV50_DISP_PIOR_MTHD_OR;
switch (mthd) {
case NV50_DISP_PIOR_PWR:
ret = priv->pior.power(priv, or, data[0]);
priv->pior.type[or] = type;
break;
default:
return -EINVAL;
}
return ret;
}
