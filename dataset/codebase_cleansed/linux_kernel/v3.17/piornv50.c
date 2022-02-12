static int
nv50_pior_tmds_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *info, u32 index,
struct nouveau_object **pobject)
{
struct nouveau_i2c *i2c = nouveau_i2c(parent);
struct nvkm_output *outp;
int ret;
ret = nvkm_output_create(parent, engine, oclass, info, index, &outp);
*pobject = nv_object(outp);
if (ret)
return ret;
outp->edid = i2c->find_type(i2c, NV_I2C_TYPE_EXTDDC(outp->info.extdev));
return 0;
}
static int
nv50_pior_dp_pattern(struct nvkm_output_dp *outp, int pattern)
{
struct nouveau_i2c_port *port = outp->base.edid;
if (port && port->func->pattern)
return port->func->pattern(port, pattern);
return port ? 0 : -ENODEV;
}
static int
nv50_pior_dp_lnk_pwr(struct nvkm_output_dp *outp, int nr)
{
return 0;
}
static int
nv50_pior_dp_lnk_ctl(struct nvkm_output_dp *outp, int nr, int bw, bool ef)
{
struct nouveau_i2c_port *port = outp->base.edid;
if (port && port->func->lnk_ctl)
return port->func->lnk_ctl(port, nr, bw, ef);
return port ? 0 : -ENODEV;
}
static int
nv50_pior_dp_drv_ctl(struct nvkm_output_dp *outp, int ln, int vs, int pe, int pc)
{
struct nouveau_i2c_port *port = outp->base.edid;
if (port && port->func->drv_ctl)
return port->func->drv_ctl(port, ln, vs, pe);
return port ? 0 : -ENODEV;
}
static int
nv50_pior_dp_ctor(struct nouveau_object *parent,
struct nouveau_object *engine,
struct nouveau_oclass *oclass, void *info, u32 index,
struct nouveau_object **pobject)
{
struct nouveau_i2c *i2c = nouveau_i2c(parent);
struct nvkm_output_dp *outp;
int ret;
ret = nvkm_output_dp_create(parent, engine, oclass, info, index, &outp);
*pobject = nv_object(outp);
if (ret)
return ret;
outp->base.edid = i2c->find_type(i2c, NV_I2C_TYPE_EXTAUX(
outp->base.info.extdev));
return 0;
}
int
nv50_pior_power(NV50_DISP_MTHD_V1)
{
const u32 soff = outp->or * 0x800;
union {
struct nv50_disp_pior_pwr_v0 v0;
} *args = data;
u32 ctrl, type;
int ret;
nv_ioctl(object, "disp pior pwr size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, false)) {
nv_ioctl(object, "disp pior pwr vers %d state %d type %x\n",
args->v0.version, args->v0.state, args->v0.type);
if (args->v0.type > 0x0f)
return -EINVAL;
ctrl = !!args->v0.state;
type = args->v0.type;
} else
return ret;
nv_wait(priv, 0x61e004 + soff, 0x80000000, 0x00000000);
nv_mask(priv, 0x61e004 + soff, 0x80000101, 0x80000000 | ctrl);
nv_wait(priv, 0x61e004 + soff, 0x80000000, 0x00000000);
priv->pior.type[outp->or] = type;
return 0;
}
