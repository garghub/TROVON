static inline u32
gf110_sor_soff(struct nvkm_output_dp *outp)
{
return (ffs(outp->base.info.or) - 1) * 0x800;
}
static inline u32
gf110_sor_loff(struct nvkm_output_dp *outp)
{
return gf110_sor_soff(outp) + !(outp->base.info.sorconf.link & 1) * 0x80;
}
static inline u32
gf110_sor_dp_lane_map(struct nv50_disp_priv *priv, u8 lane)
{
static const u8 gf110[] = { 16, 8, 0, 24 };
return gf110[lane];
}
static int
gf110_sor_dp_pattern(struct nvkm_output_dp *outp, int pattern)
{
struct nv50_disp_priv *priv = (void *)nvkm_disp(outp);
const u32 loff = gf110_sor_loff(outp);
nv_mask(priv, 0x61c110 + loff, 0x0f0f0f0f, 0x01010101 * pattern);
return 0;
}
int
gf110_sor_dp_lnk_ctl(struct nvkm_output_dp *outp, int nr, int bw, bool ef)
{
struct nv50_disp_priv *priv = (void *)nvkm_disp(outp);
const u32 soff = gf110_sor_soff(outp);
const u32 loff = gf110_sor_loff(outp);
u32 dpctrl = 0x00000000;
u32 clksor = 0x00000000;
clksor |= bw << 18;
dpctrl |= ((1 << nr) - 1) << 16;
if (ef)
dpctrl |= 0x00004000;
nv_mask(priv, 0x612300 + soff, 0x007c0000, clksor);
nv_mask(priv, 0x61c10c + loff, 0x001f4000, dpctrl);
return 0;
}
static int
gf110_sor_dp_drv_ctl(struct nvkm_output_dp *outp,
int ln, int vs, int pe, int pc)
{
struct nv50_disp_priv *priv = (void *)nvkm_disp(outp);
struct nvkm_bios *bios = nvkm_bios(priv);
const u32 shift = gf110_sor_dp_lane_map(priv, ln);
const u32 loff = gf110_sor_loff(outp);
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
data[0] = nv_rd32(priv, 0x61c118 + loff) & ~(0x000000ff << shift);
data[1] = nv_rd32(priv, 0x61c120 + loff) & ~(0x000000ff << shift);
data[2] = nv_rd32(priv, 0x61c130 + loff);
if ((data[2] & 0x0000ff00) < (ocfg.tx_pu << 8) || ln == 0)
data[2] = (data[2] & ~0x0000ff00) | (ocfg.tx_pu << 8);
nv_wr32(priv, 0x61c118 + loff, data[0] | (ocfg.dc << shift));
nv_wr32(priv, 0x61c120 + loff, data[1] | (ocfg.pe << shift));
nv_wr32(priv, 0x61c130 + loff, data[2] | (ocfg.tx_pu << 8));
data[3] = nv_rd32(priv, 0x61c13c + loff) & ~(0x000000ff << shift);
nv_wr32(priv, 0x61c13c + loff, data[3] | (ocfg.pc << shift));
return 0;
}
