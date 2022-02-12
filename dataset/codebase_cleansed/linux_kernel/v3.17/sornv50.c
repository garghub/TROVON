int
nv50_sor_power(NV50_DISP_MTHD_V1)
{
union {
struct nv50_disp_sor_pwr_v0 v0;
} *args = data;
const u32 soff = outp->or * 0x800;
u32 stat;
int ret;
nv_ioctl(object, "disp sor pwr size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, false)) {
nv_ioctl(object, "disp sor pwr vers %d state %d\n",
args->v0.version, args->v0.state);
stat = !!args->v0.state;
} else
return ret;
nv_wait(priv, 0x61c004 + soff, 0x80000000, 0x00000000);
nv_mask(priv, 0x61c004 + soff, 0x80000001, 0x80000000 | stat);
nv_wait(priv, 0x61c004 + soff, 0x80000000, 0x00000000);
nv_wait(priv, 0x61c030 + soff, 0x10000000, 0x00000000);
return 0;
}
