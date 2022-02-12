int
nv50_pior_power(NV50_DISP_MTHD_V1)
{
struct nvkm_device *device = disp->base.engine.subdev.device;
const u32 soff = outp->or * 0x800;
union {
struct nv50_disp_pior_pwr_v0 v0;
} *args = data;
u32 ctrl, type;
int ret = -ENOSYS;
nvif_ioctl(object, "disp pior pwr size %d\n", size);
if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
nvif_ioctl(object, "disp pior pwr vers %d state %d type %x\n",
args->v0.version, args->v0.state, args->v0.type);
if (args->v0.type > 0x0f)
return -EINVAL;
ctrl = !!args->v0.state;
type = args->v0.type;
} else
return ret;
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61e004 + soff) & 0x80000000))
break;
);
nvkm_mask(device, 0x61e004 + soff, 0x80000101, 0x80000000 | ctrl);
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61e004 + soff) & 0x80000000))
break;
);
disp->pior.type[outp->or] = type;
return 0;
}
int
nv50_pior_output_new(struct nvkm_disp *disp, int index,
struct dcb_output *dcbE, struct nvkm_output **poutp)
{
return nvkm_output_new_(&nv50_pior_output_func, disp,
index, dcbE, poutp);
}
static int
nv50_pior_output_dp_pattern(struct nvkm_output_dp *outp, int pattern)
{
return 0;
}
static int
nv50_pior_output_dp_lnk_pwr(struct nvkm_output_dp *outp, int nr)
{
return 0;
}
static int
nv50_pior_output_dp_lnk_ctl(struct nvkm_output_dp *outp,
int nr, int bw, bool ef)
{
int ret = nvkm_i2c_aux_lnk_ctl(outp->aux, nr, bw, ef);
if (ret)
return ret;
return 1;
}
int
nv50_pior_dp_new(struct nvkm_disp *disp, int index, struct dcb_output *dcbE,
struct nvkm_output **poutp)
{
struct nvkm_i2c *i2c = disp->engine.subdev.device->i2c;
struct nvkm_i2c_aux *aux =
nvkm_i2c_aux_find(i2c, NVKM_I2C_AUX_EXT(dcbE->extdev));
struct nvkm_output_dp *outp;
if (!(outp = kzalloc(sizeof(*outp), GFP_KERNEL)))
return -ENOMEM;
*poutp = &outp->base;
return nvkm_output_dp_ctor(&nv50_pior_output_dp_func, disp,
index, dcbE, aux, outp);
}
