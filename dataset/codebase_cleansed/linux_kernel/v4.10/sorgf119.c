static inline u32
gf119_sor_soff(struct nvkm_output_dp *outp)
{
return (ffs(outp->base.info.or) - 1) * 0x800;
}
static inline u32
gf119_sor_loff(struct nvkm_output_dp *outp)
{
return gf119_sor_soff(outp) + !(outp->base.info.sorconf.link & 1) * 0x80;
}
static int
gf119_sor_dp_pattern(struct nvkm_output_dp *outp, int pattern)
{
struct nvkm_device *device = outp->base.disp->engine.subdev.device;
const u32 soff = gf119_sor_soff(outp);
nvkm_mask(device, 0x61c110 + soff, 0x0f0f0f0f, 0x01010101 * pattern);
return 0;
}
int
gf119_sor_dp_lnk_ctl(struct nvkm_output_dp *outp, int nr, int bw, bool ef)
{
struct nvkm_device *device = outp->base.disp->engine.subdev.device;
const u32 soff = gf119_sor_soff(outp);
const u32 loff = gf119_sor_loff(outp);
u32 dpctrl = 0x00000000;
u32 clksor = 0x00000000;
clksor |= bw << 18;
dpctrl |= ((1 << nr) - 1) << 16;
if (outp->lt.mst)
dpctrl |= 0x40000000;
if (ef)
dpctrl |= 0x00004000;
nvkm_mask(device, 0x612300 + soff, 0x007c0000, clksor);
nvkm_mask(device, 0x61c10c + loff, 0x401f4000, dpctrl);
return 0;
}
int
gf119_sor_dp_drv_ctl(struct nvkm_output_dp *outp,
int ln, int vs, int pe, int pc)
{
struct nvkm_device *device = outp->base.disp->engine.subdev.device;
struct nvkm_bios *bios = device->bios;
const u32 shift = g94_sor_dp_lane_map(device, ln);
const u32 loff = gf119_sor_loff(outp);
u32 addr, data[4];
u8 ver, hdr, cnt, len;
struct nvbios_dpout info;
struct nvbios_dpcfg ocfg;
addr = nvbios_dpout_match(bios, outp->base.info.hasht,
outp->base.info.hashm,
&ver, &hdr, &cnt, &len, &info);
if (!addr)
return -ENODEV;
addr = nvbios_dpcfg_match(bios, addr, pc, vs, pe,
&ver, &hdr, &cnt, &len, &ocfg);
if (!addr)
return -EINVAL;
data[0] = nvkm_rd32(device, 0x61c118 + loff) & ~(0x000000ff << shift);
data[1] = nvkm_rd32(device, 0x61c120 + loff) & ~(0x000000ff << shift);
data[2] = nvkm_rd32(device, 0x61c130 + loff);
if ((data[2] & 0x0000ff00) < (ocfg.tx_pu << 8) || ln == 0)
data[2] = (data[2] & ~0x0000ff00) | (ocfg.tx_pu << 8);
nvkm_wr32(device, 0x61c118 + loff, data[0] | (ocfg.dc << shift));
nvkm_wr32(device, 0x61c120 + loff, data[1] | (ocfg.pe << shift));
nvkm_wr32(device, 0x61c130 + loff, data[2]);
data[3] = nvkm_rd32(device, 0x61c13c + loff) & ~(0x000000ff << shift);
nvkm_wr32(device, 0x61c13c + loff, data[3] | (ocfg.pc << shift));
return 0;
}
void
gf119_sor_dp_vcpi(struct nvkm_output_dp *outp, int head, u8 slot,
u8 slot_nr, u16 pbn, u16 aligned)
{
struct nvkm_device *device = outp->base.disp->engine.subdev.device;
const u32 hoff = head * 0x800;
nvkm_mask(device, 0x616588 + hoff, 0x00003f3f, (slot_nr << 8) | slot);
nvkm_mask(device, 0x61658c + hoff, 0xffffffff, (aligned << 16) | pbn);
}
int
gf119_sor_dp_new(struct nvkm_disp *disp, int index,
struct dcb_output *dcbE, struct nvkm_output **poutp)
{
return nvkm_output_dp_new_(&gf119_sor_dp_func, disp, index, dcbE, poutp);
}
