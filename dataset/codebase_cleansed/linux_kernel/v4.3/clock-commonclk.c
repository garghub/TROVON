static void mpc512x_clk_determine_soc(void)
{
if (of_machine_is_compatible("fsl,mpc5121")) {
soc = MPC512x_SOC_MPC5121;
return;
}
if (of_machine_is_compatible("fsl,mpc5123")) {
soc = MPC512x_SOC_MPC5123;
return;
}
if (of_machine_is_compatible("fsl,mpc5125")) {
soc = MPC512x_SOC_MPC5125;
return;
}
}
static bool soc_has_mbx(void)
{
if (soc == MPC512x_SOC_MPC5121)
return true;
return false;
}
static bool soc_has_axe(void)
{
if (soc == MPC512x_SOC_MPC5125)
return false;
return true;
}
static bool soc_has_viu(void)
{
if (soc == MPC512x_SOC_MPC5125)
return false;
return true;
}
static bool soc_has_spdif(void)
{
if (soc == MPC512x_SOC_MPC5125)
return false;
return true;
}
static bool soc_has_pata(void)
{
if (soc == MPC512x_SOC_MPC5125)
return false;
return true;
}
static bool soc_has_sata(void)
{
if (soc == MPC512x_SOC_MPC5125)
return false;
return true;
}
static bool soc_has_pci(void)
{
if (soc == MPC512x_SOC_MPC5125)
return false;
return true;
}
static bool soc_has_fec2(void)
{
if (soc == MPC512x_SOC_MPC5125)
return true;
return false;
}
static int soc_max_pscnum(void)
{
if (soc == MPC512x_SOC_MPC5125)
return 10;
return 12;
}
static bool soc_has_sdhc2(void)
{
if (soc == MPC512x_SOC_MPC5125)
return true;
return false;
}
static bool soc_has_nfc_5125(void)
{
if (soc == MPC512x_SOC_MPC5125)
return true;
return false;
}
static bool soc_has_outclk(void)
{
if (soc == MPC512x_SOC_MPC5125)
return true;
return false;
}
static bool soc_has_cpmf_0_bypass(void)
{
if (soc == MPC512x_SOC_MPC5125)
return true;
return false;
}
static bool soc_has_mclk_mux0_canin(void)
{
if (soc == MPC512x_SOC_MPC5125)
return true;
return false;
}
static inline struct clk *mpc512x_clk_fixed(const char *name, int rate)
{
return clk_register_fixed_rate(NULL, name, NULL, CLK_IS_ROOT, rate);
}
static inline struct clk *mpc512x_clk_factor(
const char *name, const char *parent_name,
int mul, int div)
{
int clkflags;
clkflags = CLK_SET_RATE_PARENT;
return clk_register_fixed_factor(NULL, name, parent_name, clkflags,
mul, div);
}
static inline struct clk *mpc512x_clk_divider(
const char *name, const char *parent_name, u8 clkflags,
u32 __iomem *reg, u8 pos, u8 len, int divflags)
{
return clk_register_divider(NULL, name, parent_name, clkflags,
reg, pos, len, divflags, &clklock);
}
static inline struct clk *mpc512x_clk_divtable(
const char *name, const char *parent_name,
u32 __iomem *reg, u8 pos, u8 len,
const struct clk_div_table *divtab)
{
u8 divflags;
divflags = 0;
return clk_register_divider_table(NULL, name, parent_name, 0,
reg, pos, len, divflags,
divtab, &clklock);
}
static inline struct clk *mpc512x_clk_gated(
const char *name, const char *parent_name,
u32 __iomem *reg, u8 pos)
{
int clkflags;
clkflags = CLK_SET_RATE_PARENT;
return clk_register_gate(NULL, name, parent_name, clkflags,
reg, pos, 0, &clklock);
}
static inline struct clk *mpc512x_clk_muxed(const char *name,
const char **parent_names, int parent_count,
u32 __iomem *reg, u8 pos, u8 len)
{
int clkflags;
u8 muxflags;
clkflags = CLK_SET_RATE_PARENT;
muxflags = 0;
return clk_register_mux(NULL, name,
parent_names, parent_count, clkflags,
reg, pos, len, muxflags, &clklock);
}
static inline int get_bit_field(uint32_t __iomem *reg, uint8_t pos, uint8_t len)
{
uint32_t val;
val = in_be32(reg);
val >>= pos;
val &= (1 << len) - 1;
return val;
}
static int get_spmf_mult(void)
{
static int spmf_to_mult[] = {
68, 1, 12, 16, 20, 24, 28, 32,
36, 40, 44, 48, 52, 56, 60, 64,
};
int spmf;
spmf = get_bit_field(&clkregs->spmr, 24, 4);
return spmf_to_mult[spmf];
}
static int get_sys_div_x2(void)
{
static int sysdiv_code_to_x2[] = {
4, 5, 6, 7, 8, 9, 10, 14,
12, 16, 18, 22, 20, 24, 26, 30,
28, 32, 34, 38, 36, 40, 42, 46,
44, 48, 50, 54, 52, 56, 58, 62,
60, 64, 66,
};
int divcode;
divcode = get_bit_field(&clkregs->scfr2, 26, 6);
return sysdiv_code_to_x2[divcode];
}
static int get_cpmf_mult_x2(void)
{
static int cpmf_to_mult_x36[] = {
72, 2, 2, 3, 4, 5, 6, 7,
};
static int cpmf_to_mult_0by[] = {
2, 2, 2, 3, 4, 5, 6, 7,
};
int *cpmf_to_mult;
int cpmf;
cpmf = get_bit_field(&clkregs->spmr, 16, 4);
if (soc_has_cpmf_0_bypass())
cpmf_to_mult = cpmf_to_mult_0by;
else
cpmf_to_mult = cpmf_to_mult_x36;
return cpmf_to_mult[cpmf];
}
static int get_freq_from_dt(char *propname)
{
struct device_node *np;
const unsigned int *prop;
int val;
val = 0;
np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-immr");
if (np) {
prop = of_get_property(np, propname, NULL);
if (prop)
val = *prop;
of_node_put(np);
}
return val;
}
static void mpc512x_clk_preset_data(void)
{
size_t i;
for (i = 0; i < ARRAY_SIZE(clks); i++)
clks[i] = ERR_PTR(-ENODEV);
}
static void mpc512x_clk_setup_ref_clock(struct device_node *np, int bus_freq,
int *sys_mul, int *sys_div,
int *ips_div)
{
struct clk *osc_clk;
int calc_freq;
*sys_mul = get_spmf_mult();
*sys_mul *= 2;
*sys_div = get_sys_div_x2();
*ips_div = get_bit_field(&clkregs->scfr1, 23, 3);
osc_clk = of_clk_get_by_name(np, "osc");
if (!IS_ERR(osc_clk)) {
clks[MPC512x_CLK_REF] = mpc512x_clk_factor("ref", "osc", 1, 1);
calc_freq = clk_get_rate(clks[MPC512x_CLK_REF]);
calc_freq *= *sys_mul;
calc_freq /= *sys_div;
calc_freq /= 2;
calc_freq /= *ips_div;
if (bus_freq && calc_freq != bus_freq)
pr_warn("calc rate %d != OF spec %d\n",
calc_freq, bus_freq);
} else {
calc_freq = bus_freq;
calc_freq *= *ips_div;
calc_freq *= 2;
calc_freq *= *sys_div;
calc_freq /= *sys_mul;
clks[MPC512x_CLK_REF] = mpc512x_clk_fixed("ref", calc_freq);
}
}
static void mpc512x_clk_setup_mclk(struct mclk_setup_data *entry, size_t idx)
{
size_t clks_idx_pub, clks_idx_int;
u32 __iomem *mccr_reg;
int div;
switch (entry->type) {
case MCLK_TYPE_PSC:
clks_idx_pub = MPC512x_CLK_PSC0_MCLK + idx;
clks_idx_int = MPC512x_CLK_MCLKS_FIRST
+ (idx) * MCLK_MAX_IDX;
mccr_reg = &clkregs->psc_ccr[idx];
break;
case MCLK_TYPE_MSCAN:
clks_idx_pub = MPC512x_CLK_MSCAN0_MCLK + idx;
clks_idx_int = MPC512x_CLK_MCLKS_FIRST
+ (NR_PSCS + idx) * MCLK_MAX_IDX;
mccr_reg = &clkregs->mscan_ccr[idx];
break;
case MCLK_TYPE_SPDIF:
clks_idx_pub = MPC512x_CLK_SPDIF_MCLK;
clks_idx_int = MPC512x_CLK_MCLKS_FIRST
+ (NR_PSCS + NR_MSCANS) * MCLK_MAX_IDX;
mccr_reg = &clkregs->spccr;
break;
case MCLK_TYPE_OUTCLK:
clks_idx_pub = MPC512x_CLK_OUT0_CLK + idx;
clks_idx_int = MPC512x_CLK_MCLKS_FIRST
+ (NR_PSCS + NR_MSCANS + NR_SPDIFS + idx)
* MCLK_MAX_IDX;
mccr_reg = &clkregs->out_ccr[idx];
break;
default:
return;
}
div = clk_get_rate(clks[MPC512x_CLK_SYS]);
div /= clk_get_rate(clks[MPC512x_CLK_IPS]);
out_be32(mccr_reg, (0 << 16));
out_be32(mccr_reg, (0 << 16) | ((div - 1) << 17));
out_be32(mccr_reg, (1 << 16) | ((div - 1) << 17));
clks[clks_idx_int + MCLK_IDX_MUX0] = mpc512x_clk_muxed(
entry->name_mux0,
soc_has_mclk_mux0_canin()
? &parent_names_mux0_canin[0]
: &parent_names_mux0_spdif[0],
ARRAY_SIZE(parent_names_mux0_spdif),
mccr_reg, 14, 2);
clks[clks_idx_int + MCLK_IDX_EN0] = mpc512x_clk_gated(
entry->name_en0, entry->name_mux0,
mccr_reg, 16);
clks[clks_idx_int + MCLK_IDX_DIV0] = mpc512x_clk_divider(
entry->name_div0,
entry->name_en0, CLK_SET_RATE_GATE,
mccr_reg, 17, 15, 0);
if (entry->has_mclk1) {
clks[clks_idx_pub] = mpc512x_clk_muxed(
entry->name_mclk,
&entry->parent_names_mux1[0],
ARRAY_SIZE(entry->parent_names_mux1),
mccr_reg, 7, 1);
} else {
clks[clks_idx_pub] = mpc512x_clk_factor(
entry->name_mclk,
entry->parent_names_mux1[0],
1, 1);
}
}
static void mpc512x_clk_setup_clock_tree(struct device_node *np, int busfreq)
{
int sys_mul, sys_div, ips_div;
int mul, div;
size_t mclk_idx;
int freq;
mpc512x_clk_setup_ref_clock(np, busfreq, &sys_mul, &sys_div, &ips_div);
clks[MPC512x_CLK_SYS] = mpc512x_clk_factor("sys", "ref",
sys_mul, sys_div);
clks[MPC512x_CLK_CSB] = mpc512x_clk_factor("csb", "sys", 1, 2);
clks[MPC512x_CLK_IPS] = mpc512x_clk_divtable("ips", "csb",
&clkregs->scfr1, 23, 3,
divtab_2346);
clks[MPC512x_CLK_DDR_UG] = mpc512x_clk_factor("ddr-ug", "sys", 1, 2);
clks[MPC512x_CLK_SDHC_x4] = mpc512x_clk_factor("sdhc-x4", "csb", 2, 1);
clks[MPC512x_CLK_SDHC_UG] = mpc512x_clk_divider("sdhc-ug", "sdhc-x4", 0,
&clkregs->scfr2, 1, 7,
CLK_DIVIDER_ONE_BASED);
if (soc_has_sdhc2()) {
clks[MPC512x_CLK_SDHC2_UG] = mpc512x_clk_divider(
"sdhc2-ug", "sdhc-x4", 0, &clkregs->scfr2,
9, 7, CLK_DIVIDER_ONE_BASED);
}
clks[MPC512x_CLK_DIU_x4] = mpc512x_clk_factor("diu-x4", "csb", 4, 1);
clks[MPC512x_CLK_DIU_UG] = mpc512x_clk_divider("diu-ug", "diu-x4", 0,
&clkregs->scfr1, 0, 8,
CLK_DIVIDER_ONE_BASED);
mul = get_cpmf_mult_x2();
div = 2;
clks[MPC512x_CLK_E300] = mpc512x_clk_factor("e300", "csb", mul, div);
if (soc_has_mbx()) {
clks[MPC512x_CLK_MBX_BUS_UG] = mpc512x_clk_factor(
"mbx-bus-ug", "csb", 1, 2);
clks[MPC512x_CLK_MBX_UG] = mpc512x_clk_divtable(
"mbx-ug", "mbx-bus-ug", &clkregs->scfr1,
14, 3, divtab_1234);
clks[MPC512x_CLK_MBX_3D_UG] = mpc512x_clk_factor(
"mbx-3d-ug", "mbx-ug", 1, 1);
}
if (soc_has_pci()) {
clks[MPC512x_CLK_PCI_UG] = mpc512x_clk_divtable(
"pci-ug", "csb", &clkregs->scfr1,
20, 3, divtab_2346);
}
if (soc_has_nfc_5125()) {
clks[MPC512x_CLK_NFC_UG] = ERR_PTR(-ENOTSUPP);
} else {
clks[MPC512x_CLK_NFC_UG] = mpc512x_clk_divtable(
"nfc-ug", "ips", &clkregs->scfr1,
8, 3, divtab_1234);
}
clks[MPC512x_CLK_LPC_UG] = mpc512x_clk_divtable("lpc-ug", "ips",
&clkregs->scfr1, 11, 3,
divtab_1234);
clks[MPC512x_CLK_LPC] = mpc512x_clk_gated("lpc", "lpc-ug",
&clkregs->sccr1, 30);
clks[MPC512x_CLK_NFC] = mpc512x_clk_gated("nfc", "nfc-ug",
&clkregs->sccr1, 29);
if (soc_has_pata()) {
clks[MPC512x_CLK_PATA] = mpc512x_clk_gated(
"pata", "ips", &clkregs->sccr1, 28);
}
for (mclk_idx = 0; mclk_idx < soc_max_pscnum(); mclk_idx++) {
char name[12];
snprintf(name, sizeof(name), "psc%d", mclk_idx);
clks[MPC512x_CLK_PSC0 + mclk_idx] = mpc512x_clk_gated(
name, "ips", &clkregs->sccr1, 27 - mclk_idx);
mpc512x_clk_setup_mclk(&mclk_psc_data[mclk_idx], mclk_idx);
}
clks[MPC512x_CLK_PSC_FIFO] = mpc512x_clk_gated("psc-fifo", "ips",
&clkregs->sccr1, 15);
if (soc_has_sata()) {
clks[MPC512x_CLK_SATA] = mpc512x_clk_gated(
"sata", "ips", &clkregs->sccr1, 14);
}
clks[MPC512x_CLK_FEC] = mpc512x_clk_gated("fec", "ips",
&clkregs->sccr1, 13);
if (soc_has_pci()) {
clks[MPC512x_CLK_PCI] = mpc512x_clk_gated(
"pci", "pci-ug", &clkregs->sccr1, 11);
}
clks[MPC512x_CLK_DDR] = mpc512x_clk_gated("ddr", "ddr-ug",
&clkregs->sccr1, 10);
if (soc_has_fec2()) {
clks[MPC512x_CLK_FEC2] = mpc512x_clk_gated(
"fec2", "ips", &clkregs->sccr1, 9);
}
clks[MPC512x_CLK_DIU] = mpc512x_clk_gated("diu", "diu-ug",
&clkregs->sccr2, 31);
if (soc_has_axe()) {
clks[MPC512x_CLK_AXE] = mpc512x_clk_gated(
"axe", "csb", &clkregs->sccr2, 30);
}
clks[MPC512x_CLK_MEM] = mpc512x_clk_gated("mem", "ips",
&clkregs->sccr2, 29);
clks[MPC512x_CLK_USB1] = mpc512x_clk_gated("usb1", "csb",
&clkregs->sccr2, 28);
clks[MPC512x_CLK_USB2] = mpc512x_clk_gated("usb2", "csb",
&clkregs->sccr2, 27);
clks[MPC512x_CLK_I2C] = mpc512x_clk_gated("i2c", "ips",
&clkregs->sccr2, 26);
clks[MPC512x_CLK_BDLC] = mpc512x_clk_gated("bdlc", "ips",
&clkregs->sccr2, 25);
for (mclk_idx = 0; mclk_idx < ARRAY_SIZE(mclk_mscan_data); mclk_idx++)
mpc512x_clk_setup_mclk(&mclk_mscan_data[mclk_idx], mclk_idx);
clks[MPC512x_CLK_SDHC] = mpc512x_clk_gated("sdhc", "sdhc-ug",
&clkregs->sccr2, 24);
if (soc_has_spdif()) {
clks[MPC512x_CLK_SPDIF] = mpc512x_clk_gated(
"spdif", "ips", &clkregs->sccr2, 23);
mpc512x_clk_setup_mclk(&mclk_spdif_data[0], 0);
}
if (soc_has_mbx()) {
clks[MPC512x_CLK_MBX_BUS] = mpc512x_clk_gated(
"mbx-bus", "mbx-bus-ug", &clkregs->sccr2, 22);
clks[MPC512x_CLK_MBX] = mpc512x_clk_gated(
"mbx", "mbx-ug", &clkregs->sccr2, 21);
clks[MPC512x_CLK_MBX_3D] = mpc512x_clk_gated(
"mbx-3d", "mbx-3d-ug", &clkregs->sccr2, 20);
}
clks[MPC512x_CLK_IIM] = mpc512x_clk_gated("iim", "csb",
&clkregs->sccr2, 19);
if (soc_has_viu()) {
clks[MPC512x_CLK_VIU] = mpc512x_clk_gated(
"viu", "csb", &clkregs->sccr2, 18);
}
if (soc_has_sdhc2()) {
clks[MPC512x_CLK_SDHC2] = mpc512x_clk_gated(
"sdhc-2", "sdhc2-ug", &clkregs->sccr2, 17);
}
if (soc_has_outclk()) {
size_t idx;
for (idx = 0; idx < ARRAY_SIZE(mclk_outclk_data); idx++)
mpc512x_clk_setup_mclk(&mclk_outclk_data[idx], idx);
}
freq = get_freq_from_dt("psc_mclk_in");
if (!freq)
freq = 25000000;
clks[MPC512x_CLK_PSC_MCLK_IN] = mpc512x_clk_fixed("psc_mclk_in", freq);
if (soc_has_mclk_mux0_canin()) {
freq = get_freq_from_dt("can_clk_in");
clks[MPC512x_CLK_CAN_CLK_IN] = mpc512x_clk_fixed(
"can_clk_in", freq);
} else {
freq = get_freq_from_dt("spdif_tx_in");
clks[MPC512x_CLK_SPDIF_TX_IN] = mpc512x_clk_fixed(
"spdif_tx_in", freq);
freq = get_freq_from_dt("spdif_rx_in");
clks[MPC512x_CLK_SPDIF_TX_IN] = mpc512x_clk_fixed(
"spdif_rx_in", freq);
}
clks[MPC512x_CLK_AC97] = mpc512x_clk_fixed("ac97", 24567000);
clk_prepare_enable(clks[MPC512x_CLK_DUMMY]);
clk_prepare_enable(clks[MPC512x_CLK_E300]);
clk_prepare_enable(clks[MPC512x_CLK_DDR]);
clk_prepare_enable(clks[MPC512x_CLK_MEM]);
clk_prepare_enable(clks[MPC512x_CLK_IPS]);
clk_prepare_enable(clks[MPC512x_CLK_LPC]);
}
static void mpc5121_clk_register_of_provider(struct device_node *np)
{
clk_data.clks = clks;
clk_data.clk_num = MPC512x_CLK_LAST_PUBLIC + 1;
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
}
static void mpc5121_clk_provide_migration_support(void)
{
clk_prepare_enable(clks[MPC512x_CLK_PSC3_MCLK]);
if (of_find_compatible_node(NULL, "pci", "fsl,mpc5121-pci"))
clk_prepare_enable(clks[MPC512x_CLK_PCI]);
}
static void mpc5121_clk_provide_backwards_compat(void)
{
enum did_reg_flags {
DID_REG_PSC = BIT(0),
DID_REG_PSCFIFO = BIT(1),
DID_REG_NFC = BIT(2),
DID_REG_CAN = BIT(3),
DID_REG_I2C = BIT(4),
DID_REG_DIU = BIT(5),
DID_REG_VIU = BIT(6),
DID_REG_FEC = BIT(7),
DID_REG_USB = BIT(8),
DID_REG_PATA = BIT(9),
};
int did_register;
struct device_node *np;
struct resource res;
int idx;
char devname[32];
did_register = 0;
FOR_NODES(mpc512x_select_psc_compat()) {
NODE_PREP;
idx = (res.start >> 8) & 0xf;
NODE_CHK("ipg", clks[MPC512x_CLK_PSC0 + idx], 0, PSC);
NODE_CHK("mclk", clks[MPC512x_CLK_PSC0_MCLK + idx], 0, PSC);
}
FOR_NODES("fsl,mpc5121-psc-fifo") {
NODE_PREP;
NODE_CHK("ipg", clks[MPC512x_CLK_PSC_FIFO], 1, PSCFIFO);
}
FOR_NODES("fsl,mpc5121-nfc") {
NODE_PREP;
NODE_CHK("ipg", clks[MPC512x_CLK_NFC], 0, NFC);
}
FOR_NODES("fsl,mpc5121-mscan") {
NODE_PREP;
idx = 0;
idx += (res.start & 0x2000) ? 2 : 0;
idx += (res.start & 0x0080) ? 1 : 0;
NODE_CHK("ipg", clks[MPC512x_CLK_BDLC], 0, CAN);
NODE_CHK("mclk", clks[MPC512x_CLK_MSCAN0_MCLK + idx], 0, CAN);
}
if (did_register & DID_REG_CAN) {
clk_register_clkdev(clks[MPC512x_CLK_IPS], "ips", NULL);
clk_register_clkdev(clks[MPC512x_CLK_SYS], "sys", NULL);
clk_register_clkdev(clks[MPC512x_CLK_REF], "ref", NULL);
}
FOR_NODES("fsl,mpc5121-i2c") {
NODE_PREP;
NODE_CHK("ipg", clks[MPC512x_CLK_I2C], 0, I2C);
}
if (did_register & DID_REG_I2C)
clk_prepare_enable(clks[MPC512x_CLK_I2C]);
FOR_NODES("fsl,mpc5121-diu") {
NODE_PREP;
NODE_CHK("ipg", clks[MPC512x_CLK_DIU], 1, DIU);
}
FOR_NODES("fsl,mpc5121-viu") {
NODE_PREP;
NODE_CHK("ipg", clks[MPC512x_CLK_VIU], 0, VIU);
}
FOR_NODES("fsl,mpc5121-fec") {
NODE_PREP;
NODE_CHK("per", clks[MPC512x_CLK_FEC], 0, FEC);
}
FOR_NODES("fsl,mpc5121-fec-mdio") {
NODE_PREP;
NODE_CHK("per", clks[MPC512x_CLK_FEC], 0, FEC);
}
FOR_NODES("fsl,mpc5125-fec") {
NODE_PREP;
if (res.start & 0x4000)
idx = MPC512x_CLK_FEC2;
else
idx = MPC512x_CLK_FEC;
NODE_CHK("per", clks[idx], 0, FEC);
}
FOR_NODES("fsl,mpc5121-usb2-dr") {
NODE_PREP;
idx = (res.start & 0x4000) ? 1 : 0;
NODE_CHK("ipg", clks[MPC512x_CLK_USB1 + idx], 0, USB);
}
FOR_NODES("fsl,mpc5121-pata") {
NODE_PREP;
NODE_CHK("ipg", clks[MPC512x_CLK_PATA], 0, PATA);
}
if (did_register) {
pr_notice("device tree lacks clock specs, adding fallbacks (0x%x,%s%s%s%s%s%s%s%s%s%s)\n",
did_register,
(did_register & DID_REG_PSC) ? " PSC" : "",
(did_register & DID_REG_PSCFIFO) ? " PSCFIFO" : "",
(did_register & DID_REG_NFC) ? " NFC" : "",
(did_register & DID_REG_CAN) ? " CAN" : "",
(did_register & DID_REG_I2C) ? " I2C" : "",
(did_register & DID_REG_DIU) ? " DIU" : "",
(did_register & DID_REG_VIU) ? " VIU" : "",
(did_register & DID_REG_FEC) ? " FEC" : "",
(did_register & DID_REG_USB) ? " USB" : "",
(did_register & DID_REG_PATA) ? " PATA" : "");
} else {
pr_debug("device tree has clock specs, no fallbacks added\n");
}
}
int __init mpc5121_clk_init(void)
{
struct device_node *clk_np;
int busfreq;
clk_np = of_find_compatible_node(NULL, NULL, "fsl,mpc5121-clock");
if (!clk_np)
return -ENODEV;
clkregs = of_iomap(clk_np, 0);
WARN_ON(!clkregs);
mpc512x_clk_determine_soc();
mpc512x_clk_preset_data();
clks[MPC512x_CLK_DUMMY] = mpc512x_clk_fixed("dummy", 0);
busfreq = get_freq_from_dt("bus-frequency");
mpc512x_clk_setup_clock_tree(clk_np, busfreq);
mpc5121_clk_register_of_provider(clk_np);
mpc5121_clk_provide_migration_support();
mpc5121_clk_provide_backwards_compat();
return 0;
}
