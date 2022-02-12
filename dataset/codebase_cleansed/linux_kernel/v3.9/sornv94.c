static inline u32
nv94_sor_soff(struct dcb_output *outp)
{
return (ffs(outp->or) - 1) * 0x800;
}
static inline u32
nv94_sor_loff(struct dcb_output *outp)
{
return nv94_sor_soff(outp) + !(outp->sorconf.link & 1) * 0x80;
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
nv94_sor_dp_pattern(struct nouveau_disp *disp, struct dcb_output *outp,
int head, int pattern)
{
struct nv50_disp_priv *priv = (void *)disp;
const u32 loff = nv94_sor_loff(outp);
nv_mask(priv, 0x61c10c + loff, 0x0f000000, pattern << 24);
return 0;
}
static int
nv94_sor_dp_lnk_ctl(struct nouveau_disp *disp, struct dcb_output *outp,
int head, int link_nr, int link_bw, bool enh_frame)
{
struct nv50_disp_priv *priv = (void *)disp;
const u32 soff = nv94_sor_soff(outp);
const u32 loff = nv94_sor_loff(outp);
u32 dpctrl = 0x00000000;
u32 clksor = 0x00000000;
u32 lane = 0;
int i;
dpctrl |= ((1 << link_nr) - 1) << 16;
if (enh_frame)
dpctrl |= 0x00004000;
if (link_bw > 0x06)
clksor |= 0x00040000;
for (i = 0; i < link_nr; i++)
lane |= 1 << (nv94_sor_dp_lane_map(priv, i) >> 3);
nv_mask(priv, 0x614300 + soff, 0x000c0000, clksor);
nv_mask(priv, 0x61c10c + loff, 0x001f4000, dpctrl);
nv_mask(priv, 0x61c130 + loff, 0x0000000f, lane);
return 0;
}
static int
nv94_sor_dp_drv_ctl(struct nouveau_disp *disp, struct dcb_output *outp,
int head, int lane, int swing, int preem)
{
struct nouveau_bios *bios = nouveau_bios(disp);
struct nv50_disp_priv *priv = (void *)disp;
const u32 loff = nv94_sor_loff(outp);
u32 addr, shift = nv94_sor_dp_lane_map(priv, lane);
u8 ver, hdr, cnt, len;
struct nvbios_dpout info;
struct nvbios_dpcfg ocfg;
addr = nvbios_dpout_match(bios, outp->hasht, outp->hashm,
&ver, &hdr, &cnt, &len, &info);
if (!addr)
return -ENODEV;
addr = nvbios_dpcfg_match(bios, addr, 0, swing, preem,
&ver, &hdr, &cnt, &len, &ocfg);
if (!addr)
return -EINVAL;
nv_mask(priv, 0x61c118 + loff, 0x000000ff << shift, ocfg.drv << shift);
nv_mask(priv, 0x61c120 + loff, 0x000000ff << shift, ocfg.pre << shift);
nv_mask(priv, 0x61c130 + loff, 0x0000ff00, ocfg.unk << 8);
return 0;
}
