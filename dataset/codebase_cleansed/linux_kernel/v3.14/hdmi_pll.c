void hdmi_pll_dump(struct hdmi_pll_data *pll, struct seq_file *s)
{
#define DUMPPLL(r) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(pll->base, r))
DUMPPLL(PLLCTRL_PLL_CONTROL);
DUMPPLL(PLLCTRL_PLL_STATUS);
DUMPPLL(PLLCTRL_PLL_GO);
DUMPPLL(PLLCTRL_CFG1);
DUMPPLL(PLLCTRL_CFG2);
DUMPPLL(PLLCTRL_CFG3);
DUMPPLL(PLLCTRL_SSC_CFG1);
DUMPPLL(PLLCTRL_SSC_CFG2);
DUMPPLL(PLLCTRL_CFG4);
}
void hdmi_pll_compute(struct hdmi_pll_data *pll, unsigned long clkin, int phy)
{
struct hdmi_pll_info *pi = &pll->info;
unsigned long refclk;
u32 mf;
clkin /= 10000;
pi->regn = HDMI_DEFAULT_REGN;
refclk = clkin / pi->regn;
pi->regm2 = HDMI_DEFAULT_REGM2;
pi->regm = phy * pi->regm2 / refclk;
mf = (phy - pi->regm / pi->regm2 * refclk) * 262144;
pi->regmf = pi->regm2 * mf / refclk;
pi->dcofreq = phy > 1000 * 100;
pi->regsd = ((pi->regm * clkin / 10) / (pi->regn * 250) + 5) / 10;
pi->refsel = HDMI_REFSEL_SYSCLK;
DSSDBG("M = %d Mf = %d\n", pi->regm, pi->regmf);
DSSDBG("range = %d sd = %d\n", pi->dcofreq, pi->regsd);
}
static int hdmi_pll_config(struct hdmi_pll_data *pll)
{
u32 r;
struct hdmi_pll_info *fmt = &pll->info;
REG_FLD_MOD(pll->base, PLLCTRL_PLL_CONTROL, 0x0, 0, 0);
r = hdmi_read_reg(pll->base, PLLCTRL_CFG1);
r = FLD_MOD(r, fmt->regm, 20, 9);
r = FLD_MOD(r, fmt->regn - 1, 8, 1);
hdmi_write_reg(pll->base, PLLCTRL_CFG1, r);
r = hdmi_read_reg(pll->base, PLLCTRL_CFG2);
r = FLD_MOD(r, 0x0, 12, 12);
r = FLD_MOD(r, 0x1, 13, 13);
r = FLD_MOD(r, 0x0, 14, 14);
r = FLD_MOD(r, fmt->refsel, 22, 21);
if (fmt->dcofreq) {
REG_FLD_MOD(pll->base, PLLCTRL_CFG3, fmt->regsd, 17, 10);
r = FLD_MOD(r, 0x4, 3, 1);
} else {
r = FLD_MOD(r, 0x2, 3, 1);
}
hdmi_write_reg(pll->base, PLLCTRL_CFG2, r);
r = hdmi_read_reg(pll->base, PLLCTRL_CFG4);
r = FLD_MOD(r, fmt->regm2, 24, 18);
r = FLD_MOD(r, fmt->regmf, 17, 0);
hdmi_write_reg(pll->base, PLLCTRL_CFG4, r);
REG_FLD_MOD(pll->base, PLLCTRL_PLL_GO, 0x1, 0, 0);
if (hdmi_wait_for_bit_change(pll->base, PLLCTRL_PLL_GO,
0, 0, 1) != 1) {
DSSERR("PLL GO bit not set\n");
return -ETIMEDOUT;
}
if (hdmi_wait_for_bit_change(pll->base,
PLLCTRL_PLL_STATUS, 1, 1, 1) != 1) {
DSSERR("cannot lock PLL\n");
DSSERR("CFG1 0x%x\n",
hdmi_read_reg(pll->base, PLLCTRL_CFG1));
DSSERR("CFG2 0x%x\n",
hdmi_read_reg(pll->base, PLLCTRL_CFG2));
DSSERR("CFG4 0x%x\n",
hdmi_read_reg(pll->base, PLLCTRL_CFG4));
return -ETIMEDOUT;
}
DSSDBG("PLL locked!\n");
return 0;
}
static int hdmi_pll_reset(struct hdmi_pll_data *pll)
{
REG_FLD_MOD(pll->base, PLLCTRL_PLL_CONTROL, 0x0, 3, 3);
if (hdmi_wait_for_bit_change(pll->base, PLLCTRL_PLL_STATUS, 0, 0, 1)
!= 1) {
DSSERR("Failed to sysreset PLL\n");
return -ETIMEDOUT;
}
return 0;
}
int hdmi_pll_enable(struct hdmi_pll_data *pll, struct hdmi_wp_data *wp)
{
u16 r = 0;
r = hdmi_wp_set_pll_pwr(wp, HDMI_PLLPWRCMD_ALLOFF);
if (r)
return r;
r = hdmi_wp_set_pll_pwr(wp, HDMI_PLLPWRCMD_BOTHON_ALLCLKS);
if (r)
return r;
r = hdmi_pll_reset(pll);
if (r)
return r;
r = hdmi_pll_config(pll);
if (r)
return r;
return 0;
}
void hdmi_pll_disable(struct hdmi_pll_data *pll, struct hdmi_wp_data *wp)
{
hdmi_wp_set_pll_pwr(wp, HDMI_PLLPWRCMD_ALLOFF);
}
int hdmi_pll_init(struct platform_device *pdev, struct hdmi_pll_data *pll)
{
struct resource *res;
struct resource temp_res;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pll");
if (!res) {
DSSDBG("can't get PLL mem resource by name\n");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
DSSERR("can't get PLL mem resource\n");
return -EINVAL;
}
temp_res.start = res->start + PLL_OFFSET;
temp_res.end = temp_res.start + PLL_SIZE - 1;
res = &temp_res;
}
pll->base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!pll->base) {
DSSERR("can't ioremap PLLCTRL\n");
return -ENOMEM;
}
return 0;
}
