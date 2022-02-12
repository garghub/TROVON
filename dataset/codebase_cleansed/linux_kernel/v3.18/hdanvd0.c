int
nvd0_hda_eld(NV50_DISP_MTHD_V1)
{
union {
struct nv50_disp_sor_hda_eld_v0 v0;
} *args = data;
const u32 soff = outp->or * 0x030;
const u32 hoff = head * 0x800;
int ret, i;
nv_ioctl(object, "disp sor hda eld size %d\n", size);
if (nvif_unpack(args->v0, 0, 0, true)) {
nv_ioctl(object, "disp sor hda eld vers %d\n", args->v0.version);
if (size > 0x60)
return -E2BIG;
} else
return ret;
if (size && args->v0.data[0]) {
if (outp->info.type == DCB_OUTPUT_DP) {
nv_mask(priv, 0x616618 + hoff, 0x8000000c, 0x80000001);
nv_wait(priv, 0x616618 + hoff, 0x80000000, 0x00000000);
}
nv_mask(priv, 0x616548 + hoff, 0x00000070, 0x00000000);
for (i = 0; i < size; i++)
nv_wr32(priv, 0x10ec00 + soff, (i << 8) | args->v0.data[i]);
for (; i < 0x60; i++)
nv_wr32(priv, 0x10ec00 + soff, (i << 8));
nv_mask(priv, 0x10ec10 + soff, 0x80000003, 0x80000003);
} else {
if (outp->info.type == DCB_OUTPUT_DP) {
nv_mask(priv, 0x616618 + hoff, 0x80000001, 0x80000000);
nv_wait(priv, 0x616618 + hoff, 0x80000000, 0x00000000);
}
nv_mask(priv, 0x10ec10 + soff, 0x80000003, 0x80000000 | !!size);
}
return 0;
}
