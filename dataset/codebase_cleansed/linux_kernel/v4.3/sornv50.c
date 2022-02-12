int
nv50_sor_power(NV50_DISP_MTHD_V1)
{
struct nvkm_device *device = disp->base.engine.subdev.device;
union {
struct nv50_disp_sor_pwr_v0 v0;
} *args = data;
const u32 soff = outp->or * 0x800;
u32 stat;
int ret;
nvif_ioctl(object, "disp sor pwr size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, false)) {
nvif_ioctl(object, "disp sor pwr vers %d state %d\n",
args->v0.version, args->v0.state);
stat = !!args->v0.state;
} else
return ret;
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61c004 + soff) & 0x80000000))
break;
);
nvkm_mask(device, 0x61c004 + soff, 0x80000001, 0x80000000 | stat);
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61c004 + soff) & 0x80000000))
break;
);
nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x61c030 + soff) & 0x10000000))
break;
);
return 0;
}
int
nv50_sor_output_new(struct nvkm_disp *disp, int index,
struct dcb_output *dcbE, struct nvkm_output **poutp)
{
return nvkm_output_new_(&nv50_sor_output_func, disp,
index, dcbE, poutp);
}
