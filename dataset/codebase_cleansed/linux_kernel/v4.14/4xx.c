static unsigned long chip_11_errata(unsigned long memsize)
{
unsigned long pvr;
pvr = mfpvr();
switch (pvr & 0xf0000ff0) {
case 0x40000850:
case 0x400008d0:
case 0x200008d0:
memsize -= 4096;
break;
default:
break;
}
return memsize;
}
void ibm4xx_sdram_fixup_memsize(void)
{
int i;
unsigned long memsize, bank_config;
memsize = 0;
for (i = 0; i < ARRAY_SIZE(sdram_bxcr); i++) {
bank_config = SDRAM0_READ(sdram_bxcr[i]);
if (bank_config & SDRAM_CONFIG_BANK_ENABLE)
memsize += SDRAM_CONFIG_BANK_SIZE(bank_config);
}
memsize = chip_11_errata(memsize);
dt_fixup_memory(0, memsize);
}
static u64 ibm440spe_decode_bas(u32 bas)
{
u64 base = ((u64)(bas & 0xFFE00000u)) << 2;
switch ((bas >> 4) & 0xFFF) {
case 0:
return 0;
case 0xffc:
return base + 0x000800000ull;
case 0xff8:
return base + 0x001000000ull;
case 0xff0:
return base + 0x002000000ull;
case 0xfe0:
return base + 0x004000000ull;
case 0xfc0:
return base + 0x008000000ull;
case 0xf80:
return base + 0x010000000ull;
case 0xf00:
return base + 0x020000000ull;
case 0xe00:
return base + 0x040000000ull;
case 0xc00:
return base + 0x080000000ull;
case 0x800:
return base + 0x100000000ull;
}
printf("Memory BAS value 0x%08x unsupported !\n", bas);
return 0;
}
void ibm440spe_fixup_memsize(void)
{
u64 banktop, memsize = 0;
banktop = ibm440spe_decode_bas(mfdcr(DCRN_MQ0_B0BAS));
if (banktop > memsize)
memsize = banktop;
banktop = ibm440spe_decode_bas(mfdcr(DCRN_MQ0_B1BAS));
if (banktop > memsize)
memsize = banktop;
banktop = ibm440spe_decode_bas(mfdcr(DCRN_MQ0_B2BAS));
if (banktop > memsize)
memsize = banktop;
banktop = ibm440spe_decode_bas(mfdcr(DCRN_MQ0_B3BAS));
if (banktop > memsize)
memsize = banktop;
dt_fixup_memory(0, memsize);
}
static inline u32 ibm4xx_denali_get_cs(void)
{
void *devp;
char model[64];
u32 val, cs;
devp = finddevice("/");
if (!devp)
goto read_cs;
if (getprop(devp, "model", model, sizeof(model)) <= 0)
goto read_cs;
model[sizeof(model)-1] = 0;
if (!strcmp(model, "amcc,sequoia") ||
!strcmp(model, "amcc,rainier"))
return 1;
read_cs:
val = SDRAM0_READ(DDR0_10);
val = DDR_GET_VAL(val, DDR_CS_MAP, DDR_CS_MAP_SHIFT);
cs = 0;
while (val) {
if (val & 0x1)
cs++;
val = val >> 1;
}
return cs;
}
void ibm4xx_denali_fixup_memsize(void)
{
u32 val, max_cs, max_col, max_row;
u32 cs, col, row, bank, dpath;
unsigned long memsize;
val = SDRAM0_READ(DDR0_02);
if (!DDR_GET_VAL(val, DDR_START, DDR_START_SHIFT))
fatal("DDR controller is not initialized\n");
max_cs = DDR_GET_VAL(val, DDR_MAX_CS_REG, DDR_MAX_CS_REG_SHIFT);
max_col = DDR_GET_VAL(val, DDR_MAX_COL_REG, DDR_MAX_COL_REG_SHIFT);
max_row = DDR_GET_VAL(val, DDR_MAX_ROW_REG, DDR_MAX_ROW_REG_SHIFT);
cs = ibm4xx_denali_get_cs();
if (!cs)
fatal("No memory installed\n");
if (cs > max_cs)
fatal("DDR wrong CS configuration\n");
val = SDRAM0_READ(DDR0_14);
if (DDR_GET_VAL(val, DDR_REDUC, DDR_REDUC_SHIFT))
dpath = 4;
else
dpath = 8;
val = SDRAM0_READ(DDR0_42);
row = DDR_GET_VAL(val, DDR_APIN, DDR_APIN_SHIFT);
if (row > max_row)
fatal("DDR wrong APIN configuration\n");
row = max_row - row;
val = SDRAM0_READ(DDR0_43);
col = DDR_GET_VAL(val, DDR_COL_SZ, DDR_COL_SZ_SHIFT);
if (col > max_col)
fatal("DDR wrong COL configuration\n");
col = max_col - col;
if (DDR_GET_VAL(val, DDR_BANK8, DDR_BANK8_SHIFT))
bank = 8;
else
bank = 4;
memsize = cs * (1 << (col+row)) * bank * dpath;
memsize = chip_11_errata(memsize);
dt_fixup_memory(0, memsize);
}
void ibm44x_dbcr_reset(void)
{
unsigned long tmp;
asm volatile (
"mfspr %0,%1\n"
"oris %0,%0,%2@h\n"
"mtspr %1,%0"
: "=&r"(tmp) : "i"(SPRN_DBCR0_44X), "i"(DBCR0_RST_SYSTEM)
);
}
void ibm40x_dbcr_reset(void)
{
unsigned long tmp;
asm volatile (
"mfspr %0,%1\n"
"oris %0,%0,%2@h\n"
"mtspr %1,%0"
: "=&r"(tmp) : "i"(SPRN_DBCR0_40X), "i"(DBCR0_RST_SYSTEM)
);
}
void ibm4xx_quiesce_eth(u32 *emac0, u32 *emac1)
{
if (emac0)
*emac0 = EMAC_RESET;
if (emac1)
*emac1 = EMAC_RESET;
mtdcr(DCRN_MAL0_CFG, MAL_RESET);
while (mfdcr(DCRN_MAL0_CFG) & MAL_RESET)
;
}
void ibm4xx_fixup_ebc_ranges(const char *ebc)
{
void *devp;
u32 bxcr;
u32 ranges[EBC_NUM_BANKS*4];
u32 *p = ranges;
int i;
for (i = 0; i < EBC_NUM_BANKS; i++) {
mtdcr(DCRN_EBC0_CFGADDR, EBC_BXCR(i));
bxcr = mfdcr(DCRN_EBC0_CFGDATA);
if ((bxcr & EBC_BXCR_BU) != EBC_BXCR_BU_OFF) {
*p++ = i;
*p++ = 0;
*p++ = bxcr & EBC_BXCR_BAS;
*p++ = EBC_BXCR_BANK_SIZE(bxcr);
}
}
devp = finddevice(ebc);
if (! devp)
fatal("Couldn't locate EBC node %s\n\r", ebc);
setprop(devp, "ranges", ranges, (p - ranges) * sizeof(u32));
}
void ibm440gp_fixup_clocks(unsigned int sys_clk, unsigned int ser_clk)
{
u32 sys0 = mfdcr(DCRN_CPC0_SYS0);
u32 cr0 = mfdcr(DCRN_CPC0_CR0);
u32 cpu, plb, opb, ebc, tb, uart0, uart1, m;
u32 opdv = CPC0_SYS0_OPDV(sys0);
u32 epdv = CPC0_SYS0_EPDV(sys0);
if (sys0 & CPC0_SYS0_BYPASS) {
cpu = plb = sys_clk;
} else {
if (sys0 & CPC0_SYS0_EXTSL)
m = CPC0_SYS0_FWDVB(sys0) * opdv * epdv;
else
m = CPC0_SYS0_FBDV(sys0) * CPC0_SYS0_FWDVA(sys0);
cpu = sys_clk * m / CPC0_SYS0_FWDVA(sys0);
plb = sys_clk * m / CPC0_SYS0_FWDVB(sys0);
}
opb = plb / opdv;
ebc = opb / epdv;
if ((mfpvr() & 0xf0000fff) == 0x40000440)
tb = sys_clk;
else
tb = cpu;
if (cr0 & CPC0_CR0_U0EC)
uart0 = ser_clk;
else
uart0 = plb / CPC0_CR0_UDIV(cr0);
if (cr0 & CPC0_CR0_U1EC)
uart1 = ser_clk;
else
uart1 = plb / CPC0_CR0_UDIV(cr0);
printf("PPC440GP: SysClk = %dMHz (%x)\n\r",
(sys_clk + 500000) / 1000000, sys_clk);
dt_fixup_cpu_clocks(cpu, tb, 0);
dt_fixup_clock("/plb", plb);
dt_fixup_clock("/plb/opb", opb);
dt_fixup_clock("/plb/opb/ebc", ebc);
dt_fixup_clock("/plb/opb/serial@40000200", uart0);
dt_fixup_clock("/plb/opb/serial@40000300", uart1);
}
static inline u32 __fix_zero(u32 v, u32 def)
{
return v ? v : def;
}
static unsigned int __ibm440eplike_fixup_clocks(unsigned int sys_clk,
unsigned int tmr_clk,
int per_clk_from_opb)
{
u32 pllc = CPR0_READ(DCRN_CPR0_PLLC);
u32 plld = CPR0_READ(DCRN_CPR0_PLLD);
u32 fbdv = __fix_zero((plld >> 24) & 0x1f, 32);
u32 fwdva = __fix_zero((plld >> 16) & 0xf, 16);
u32 fwdvb = __fix_zero((plld >> 8) & 7, 8);
u32 lfbdv = __fix_zero(plld & 0x3f, 64);
u32 pradv0 = __fix_zero((CPR0_READ(DCRN_CPR0_PRIMAD) >> 24) & 7, 8);
u32 prbdv0 = __fix_zero((CPR0_READ(DCRN_CPR0_PRIMBD) >> 24) & 7, 8);
u32 opbdv0 = __fix_zero((CPR0_READ(DCRN_CPR0_OPBD) >> 24) & 3, 4);
u32 perdv0 = __fix_zero((CPR0_READ(DCRN_CPR0_PERD) >> 24) & 3, 4);
u32 clk_a, clk_b;
u32 cpu, plb, opb, ebc, vco;
u32 ccr1, tb = tmr_clk;
if (pllc & 0x40000000) {
u32 m;
switch ((pllc >> 24) & 7) {
case 0:
m = ((pllc & 0x20000000) ? fwdvb : fwdva) * lfbdv;
break;
case 1:
m = fwdva * pradv0;
break;
case 5:
m = fwdvb * prbdv0 * opbdv0 * perdv0;
break;
default:
printf("WARNING ! Invalid PLL feedback source !\n");
goto bypass;
}
m *= fbdv;
vco = sys_clk * m;
clk_a = vco / fwdva;
clk_b = vco / fwdvb;
} else {
bypass:
vco = 0;
clk_a = clk_b = sys_clk;
}
cpu = clk_a / pradv0;
plb = clk_b / prbdv0;
opb = plb / opbdv0;
ebc = (per_clk_from_opb ? opb : plb) / perdv0;
ccr1 = mfspr(SPRN_CCR1);
if (tb == 0) {
ccr1 &= ~0x80u;
mtspr(SPRN_CCR1, ccr1);
}
if ((ccr1 & 0x0080) == 0)
tb = cpu;
dt_fixup_cpu_clocks(cpu, tb, 0);
dt_fixup_clock("/plb", plb);
dt_fixup_clock("/plb/opb", opb);
dt_fixup_clock("/plb/opb/ebc", ebc);
return plb;
}
static void eplike_fixup_uart_clk(int index, const char *path,
unsigned int ser_clk,
unsigned int plb_clk)
{
unsigned int sdr;
unsigned int clock;
switch (index) {
case 0:
sdr = SDR0_READ(DCRN_SDR0_UART0);
break;
case 1:
sdr = SDR0_READ(DCRN_SDR0_UART1);
break;
case 2:
sdr = SDR0_READ(DCRN_SDR0_UART2);
break;
case 3:
sdr = SDR0_READ(DCRN_SDR0_UART3);
break;
default:
return;
}
if (sdr & 0x00800000u)
clock = ser_clk;
else
clock = plb_clk / __fix_zero(sdr & 0xff, 256);
dt_fixup_clock(path, clock);
}
void ibm440ep_fixup_clocks(unsigned int sys_clk,
unsigned int ser_clk,
unsigned int tmr_clk)
{
unsigned int plb_clk = __ibm440eplike_fixup_clocks(sys_clk, tmr_clk, 0);
eplike_fixup_uart_clk(0, "/plb/opb/serial@ef600300", ser_clk, plb_clk);
eplike_fixup_uart_clk(1, "/plb/opb/serial@ef600400", ser_clk, plb_clk);
eplike_fixup_uart_clk(2, "/plb/opb/serial@ef600500", ser_clk, plb_clk);
eplike_fixup_uart_clk(3, "/plb/opb/serial@ef600600", ser_clk, plb_clk);
}
void ibm440gx_fixup_clocks(unsigned int sys_clk,
unsigned int ser_clk,
unsigned int tmr_clk)
{
unsigned int plb_clk = __ibm440eplike_fixup_clocks(sys_clk, tmr_clk, 1);
eplike_fixup_uart_clk(0, "/plb/opb/serial@40000200", ser_clk, plb_clk);
eplike_fixup_uart_clk(1, "/plb/opb/serial@40000300", ser_clk, plb_clk);
}
void ibm440spe_fixup_clocks(unsigned int sys_clk,
unsigned int ser_clk,
unsigned int tmr_clk)
{
unsigned int plb_clk = __ibm440eplike_fixup_clocks(sys_clk, tmr_clk, 1);
eplike_fixup_uart_clk(0, "/plb/opb/serial@f0000200", ser_clk, plb_clk);
eplike_fixup_uart_clk(1, "/plb/opb/serial@f0000300", ser_clk, plb_clk);
eplike_fixup_uart_clk(2, "/plb/opb/serial@f0000600", ser_clk, plb_clk);
}
void ibm405gp_fixup_clocks(unsigned int sys_clk, unsigned int ser_clk)
{
u32 pllmr = mfdcr(DCRN_CPC0_PLLMR);
u32 cpc0_cr0 = mfdcr(DCRN_405_CPC0_CR0);
u32 cpc0_cr1 = mfdcr(DCRN_405_CPC0_CR1);
u32 psr = mfdcr(DCRN_405_CPC0_PSR);
u32 cpu, plb, opb, ebc, tb, uart0, uart1, m;
u32 fwdv, fwdvb, fbdv, cbdv, opdv, epdv, ppdv, udiv;
fwdv = (8 - ((pllmr & 0xe0000000) >> 29));
fbdv = (pllmr & 0x1e000000) >> 25;
if (fbdv == 0)
fbdv = 16;
cbdv = ((pllmr & 0x00060000) >> 17) + 1;
opdv = ((pllmr & 0x00018000) >> 15) + 1;
ppdv = ((pllmr & 0x00006000) >> 13) + 1;
epdv = ((pllmr & 0x00001800) >> 11) + 2;
udiv = ((cpc0_cr0 & 0x3e) >> 1) + 1;
if ((mfpvr() & 0xfffffff0) == (0x50910951 & 0xfffffff0)) {
fwdvb = 8 - (pllmr & 0x00000007);
if (!(psr & 0x00001000))
if (psr & 0x00000020)
m = fwdvb * 2 * ppdv;
else
m = fwdvb * cbdv * ppdv;
else if (psr & 0x00000020)
if (psr & 0x00000800)
m = fwdvb * 2 * epdv;
else
m = fbdv * fwdv;
else if (epdv == fbdv)
m = fbdv * cbdv * epdv;
else
m = fbdv * fwdvb * cbdv;
cpu = sys_clk * m / fwdv;
plb = sys_clk * m / (fwdvb * cbdv);
} else {
m = fwdv * fbdv * cbdv;
cpu = sys_clk * m / fwdv;
plb = cpu / cbdv;
}
opb = plb / opdv;
ebc = plb / epdv;
if (cpc0_cr0 & 0x80)
uart0 = ser_clk;
else
uart0 = cpu / udiv;
if (cpc0_cr0 & 0x40)
uart1 = ser_clk;
else
uart1 = cpu / udiv;
cpc0_cr1 = cpc0_cr1 & ~0x00800000;
mtdcr(DCRN_405_CPC0_CR1, cpc0_cr1);
tb = cpu;
dt_fixup_cpu_clocks(cpu, tb, 0);
dt_fixup_clock("/plb", plb);
dt_fixup_clock("/plb/opb", opb);
dt_fixup_clock("/plb/ebc", ebc);
dt_fixup_clock("/plb/opb/serial@ef600300", uart0);
dt_fixup_clock("/plb/opb/serial@ef600400", uart1);
}
void ibm405ep_fixup_clocks(unsigned int sys_clk)
{
u32 pllmr0 = mfdcr(DCRN_CPC0_PLLMR0);
u32 pllmr1 = mfdcr(DCRN_CPC0_PLLMR1);
u32 cpc0_ucr = mfdcr(DCRN_CPC0_UCR);
u32 cpu, plb, opb, ebc, uart0, uart1;
u32 fwdva, fwdvb, fbdv, cbdv, opdv, epdv;
u32 pllmr0_ccdv, tb, m;
fwdva = 8 - ((pllmr1 & 0x00070000) >> 16);
fwdvb = 8 - ((pllmr1 & 0x00007000) >> 12);
fbdv = (pllmr1 & 0x00f00000) >> 20;
if (fbdv == 0)
fbdv = 16;
cbdv = ((pllmr0 & 0x00030000) >> 16) + 1;
epdv = ((pllmr0 & 0x00000300) >> 8) + 2;
opdv = ((pllmr0 & 0x00003000) >> 12) + 1;
m = fbdv * fwdvb;
pllmr0_ccdv = ((pllmr0 & 0x00300000) >> 20) + 1;
if (pllmr1 & 0x80000000)
cpu = sys_clk * m / (fwdva * pllmr0_ccdv);
else
cpu = sys_clk / pllmr0_ccdv;
plb = cpu / cbdv;
opb = plb / opdv;
ebc = plb / epdv;
tb = cpu;
uart0 = cpu / (cpc0_ucr & 0x0000007f);
uart1 = cpu / ((cpc0_ucr & 0x00007f00) >> 8);
dt_fixup_cpu_clocks(cpu, tb, 0);
dt_fixup_clock("/plb", plb);
dt_fixup_clock("/plb/opb", opb);
dt_fixup_clock("/plb/ebc", ebc);
dt_fixup_clock("/plb/opb/serial@ef600300", uart0);
dt_fixup_clock("/plb/opb/serial@ef600400", uart1);
}
u32 ibm405ex_get_fwdva(unsigned long cpr_fwdv)
{
u32 index;
for (index = 0; index < ARRAY_SIZE(ibm405ex_fwdv_multi_bits); index++)
if (cpr_fwdv == (u32)ibm405ex_fwdv_multi_bits[index])
return index + 1;
return 0;
}
u32 ibm405ex_get_fbdv(unsigned long cpr_fbdv)
{
u32 index;
for (index = 0; index < ARRAY_SIZE(ibm405ex_fbdv_multi_bits); index++)
if (cpr_fbdv == (u32)ibm405ex_fbdv_multi_bits[index])
return index + 1;
return 0;
}
void ibm405ex_fixup_clocks(unsigned int sys_clk, unsigned int uart_clk)
{
u32 pllc = CPR0_READ(DCRN_CPR0_PLLC);
u32 plld = CPR0_READ(DCRN_CPR0_PLLD);
u32 cpud = CPR0_READ(DCRN_CPR0_PRIMAD);
u32 plbd = CPR0_READ(DCRN_CPR0_PRIMBD);
u32 opbd = CPR0_READ(DCRN_CPR0_OPBD);
u32 perd = CPR0_READ(DCRN_CPR0_PERD);
u32 fbdv = ibm405ex_get_fbdv(__fix_zero((plld >> 24) & 0xff, 1));
u32 fwdva = ibm405ex_get_fwdva(__fix_zero((plld >> 16) & 0x0f, 1));
u32 cpudv0 = __fix_zero((cpud >> 24) & 7, 8);
u32 plbdv0 = 2;
u32 plb2xdv0 = __fix_zero((plbd >> 16) & 7, 8);
u32 opbdv0 = __fix_zero((opbd >> 24) & 3, 4);
u32 perdv0 = __fix_zero((perd >> 24) & 3, 4);
u32 cpu, plb, opb, ebc, vco, tb, uart0, uart1;
if (pllc & 0x40000000) {
u32 m;
switch ((pllc >> 24) & 7) {
case 0:
m = fbdv;
break;
case 1:
m = fbdv * fwdva * cpudv0;
break;
case 5:
m = fbdv * fwdva * plb2xdv0 * plbdv0 * opbdv0 * perdv0;
break;
default:
printf("WARNING ! Invalid PLL feedback source !\n");
goto bypass;
}
vco = (unsigned int)(sys_clk * m);
} else {
bypass:
vco = 0;
}
cpu = vco / (fwdva * cpudv0);
plb = vco / (fwdva * plb2xdv0 * plbdv0);
opb = plb / opbdv0;
ebc = opb / perdv0;
tb = cpu;
uart0 = uart1 = uart_clk;
dt_fixup_cpu_clocks(cpu, tb, 0);
dt_fixup_clock("/plb", plb);
dt_fixup_clock("/plb/opb", opb);
dt_fixup_clock("/plb/opb/ebc", ebc);
dt_fixup_clock("/plb/opb/serial@ef600200", uart0);
dt_fixup_clock("/plb/opb/serial@ef600300", uart1);
}
