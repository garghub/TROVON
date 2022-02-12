static inline u32
nv94_sor_soff(struct nvkm_output_dp *outp)
{
return (ffs(outp->base.info.or) - 1) * 0x800;
}
static inline u32
nv94_sor_loff(struct nvkm_output_dp *outp)
{
return nv94_sor_soff(outp) + !(outp->base.info.sorconf.link & 1) * 0x80;
}
static inline u32
nv94_sor_dp_lane_map(struct nv50_disp_priv *priv, u8 lane)
{
static const u8 nvaf[] = { 24, 16, 8, 0 };
static const u8 nv94[] = { 16, 8, 0, 24 };
if (nv_device(priv)->chipset == 0xaf)
return nvaf[lane];
return nv94[lane];
}
static int
nv94_sor_dp_pattern(struct nvkm_output_dp *outp, int pattern)
{
struct nv50_disp_priv *priv = (void *)nouveau_disp(outp);
const u32 loff = nv94_sor_loff(outp);
nv_mask(priv, 0x61c10c + loff, 0x0f000000, pattern << 24);
return 0;
}
int
nv94_sor_dp_lnk_pwr(struct nvkm_output_dp *outp, int nr)
{
struct nv50_disp_priv *priv = (void *)nouveau_disp(outp);
const u32 soff = nv94_sor_soff(outp);
const u32 loff = nv94_sor_loff(outp);
u32 mask = 0, i;
for (i = 0; i < nr; i++)
mask |= 1 << (nv94_sor_dp_lane_map(priv, i) >> 3);
nv_mask(priv, 0x61c130 + loff, 0x0000000f, mask);
nv_mask(priv, 0x61c034 + soff, 0x80000000, 0x80000000);
nv_wait(priv, 0x61c034 + soff, 0x80000000, 0x00000000);
return 0;
}
static int
nv94_sor_dp_lnk_ctl(struct nvkm_output_dp *outp, int nr, int bw, bool ef)
{
struct nv50_disp_priv *priv = (void *)nouveau_disp(outp);
const u32 soff = nv94_sor_soff(outp);
const u32 loff = nv94_sor_loff(outp);
u32 dpctrl = 0x00000000;
u32 clksor = 0x00000000;
dpctrl |= ((1 << nr) - 1) << 16;
if (ef)
dpctrl |= 0x00004000;
if (bw > 0x06)
clksor |= 0x00040000;
nv_mask(priv, 0x614300 + soff, 0x000c0000, clksor);
nv_mask(priv, 0x61c10c + loff, 0x001f4000, dpctrl);
return 0;
}
static int
nv94_sor_dp_drv_ctl(struct nvkm_output_dp *outp, int ln, int vs, int pe, int pc)
{
struct nv50_disp_priv *priv = (void *)nouveau_disp(outp);
struct nouveau_bios *bios = nouveau_bios(priv);
const u32 shift = nv94_sor_dp_lane_map(priv, ln);
const u32 loff = nv94_sor_loff(outp);
u32 addr, data[3];
u8 ver, hdr, cnt, len;
struct nvbios_dpout info;
struct nvbios_dpcfg ocfg;
addr = nvbios_dpout_match(bios, outp->base.info.hasht,
outp->base.info.hashm,
&ver, &hdr, &cnt, &len, &info);
if (!addr)
return -ENODEV;
addr = nvbios_dpcfg_match(bios, addr, 0, vs, pe,
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
return 0;
}
