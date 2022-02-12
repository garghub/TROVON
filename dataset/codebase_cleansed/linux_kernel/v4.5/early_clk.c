u32 pic32_get_sysclk(void)
{
u32 osc_freq = 0;
u32 pllclk;
u32 frcdivn;
u32 osccon;
u32 spllcon;
int curr_osc;
u32 plliclk;
u32 pllidiv;
u32 pllodiv;
u32 pllmult;
u32 frcdiv;
void __iomem *osc_base = ioremap(PIC32_BASE_OSC, 0x200);
osccon = __raw_readl(osc_base + OSCCON);
spllcon = __raw_readl(osc_base + SPLLCON);
plliclk = (spllcon & ICLK_MASK);
pllidiv = ((spllcon >> 8) & PLLDIV_MASK) + 1;
pllodiv = ((spllcon >> 24) & PLLDIV_MASK);
pllmult = ((spllcon >> 16) & PLLMUL_MASK) + 1;
frcdiv = ((osccon >> 24) & PLLDIV_MASK);
pllclk = plliclk ? FRC_CLK : PIC32_POSC_FREQ;
frcdivn = ((1 << frcdiv) + 1) + (128 * (frcdiv == 7));
if (pllodiv < 2)
pllodiv = 2;
else if (pllodiv < 5)
pllodiv = (1 << pllodiv);
else
pllodiv = 32;
curr_osc = (int)((osccon >> 12) & CUROSC_MASK);
switch (curr_osc) {
case FRC1:
case FRC2:
osc_freq = FRC_CLK / frcdivn;
break;
case SPLL:
osc_freq = ((pllclk / pllidiv) * pllmult) / pllodiv;
break;
case POSC:
osc_freq = PIC32_POSC_FREQ;
break;
default:
break;
}
iounmap(osc_base);
return osc_freq;
}
u32 pic32_get_pbclk(int bus)
{
u32 clk_freq;
void __iomem *osc_base = ioremap(PIC32_BASE_OSC, 0x200);
u32 pbxdiv = PB1DIV + ((bus - 1) * 0x10);
u32 pbdiv = (__raw_readl(osc_base + pbxdiv) & PB_MASK) + 1;
iounmap(osc_base);
clk_freq = pic32_get_sysclk();
return clk_freq / pbdiv;
}
