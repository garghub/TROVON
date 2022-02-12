int mxs_iomux_setup_pad(iomux_cfg_t pad)
{
u32 reg, ofs, bp, bm;
void __iomem *iomux_base = MXS_IO_ADDRESS(MXS_PINCTRL_BASE_ADDR);
ofs = 0x100;
ofs += PAD_BANK(pad) * 0x20 + PAD_PIN(pad) / 16 * 0x10;
bp = PAD_PIN(pad) % 16 * 2;
bm = 0x3 << bp;
reg = __raw_readl(iomux_base + ofs);
reg &= ~bm;
reg |= PAD_MUXSEL(pad) << bp;
__raw_writel(reg, iomux_base + ofs);
ofs = cpu_is_mx23() ? 0x200 : 0x300;
ofs += PAD_BANK(pad) * 0x40 + PAD_PIN(pad) / 8 * 0x10;
if (PAD_MA_VALID(pad)) {
bp = PAD_PIN(pad) % 8 * 4;
bm = 0x3 << bp;
reg = __raw_readl(iomux_base + ofs);
reg &= ~bm;
reg |= PAD_MA(pad) << bp;
__raw_writel(reg, iomux_base + ofs);
}
if (PAD_VOL_VALID(pad)) {
bp = PAD_PIN(pad) % 8 * 4 + 2;
if (PAD_VOL(pad))
__mxs_setl(1 << bp, iomux_base + ofs);
else
__mxs_clrl(1 << bp, iomux_base + ofs);
}
if (PAD_PULL_VALID(pad)) {
ofs = cpu_is_mx23() ? 0x400 : 0x600;
ofs += PAD_BANK(pad) * 0x10;
bp = PAD_PIN(pad);
if (PAD_PULL(pad))
__mxs_setl(1 << bp, iomux_base + ofs);
else
__mxs_clrl(1 << bp, iomux_base + ofs);
}
return 0;
}
int mxs_iomux_setup_multiple_pads(const iomux_cfg_t *pad_list, unsigned count)
{
const iomux_cfg_t *p = pad_list;
int i;
int ret;
for (i = 0; i < count; i++) {
ret = mxs_iomux_setup_pad(*p);
if (ret)
return ret;
p++;
}
return 0;
}
