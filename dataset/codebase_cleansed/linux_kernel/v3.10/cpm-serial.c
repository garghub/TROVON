static void cpm1_cmd(int op)
{
while (in_be16(cpcr) & 1)
;
out_be16(cpcr, (op << 8) | cpm_cmd | 1);
while (in_be16(cpcr) & 1)
;
}
static void cpm2_cmd(int op)
{
while (in_be32(cpcr) & 0x10000)
;
out_be32(cpcr, op | cpm_cmd | 0x10000);
while (in_be32(cpcr) & 0x10000)
;
}
static void smc_disable_port(void)
{
do_cmd(CPM_CMD_STOP_TX);
out_be16(&smc->smcmr, in_be16(&smc->smcmr) & ~3);
}
static void scc_disable_port(void)
{
do_cmd(CPM_CMD_STOP_TX);
out_be32(&scc->gsmrl, in_be32(&scc->gsmrl) & ~0x30);
}
static void smc_enable_port(void)
{
out_be16(&smc->smcmr, in_be16(&smc->smcmr) | 3);
do_cmd(CPM_CMD_RESTART_TX);
}
static void scc_enable_port(void)
{
out_be32(&scc->gsmrl, in_be32(&scc->gsmrl) | 0x30);
do_cmd(CPM_CMD_RESTART_TX);
}
static int cpm_serial_open(void)
{
disable_port();
out_8(&param->rfcr, 0x10);
out_8(&param->tfcr, 0x10);
out_be16(&param->mrblr, 1);
out_be16(&param->maxidl, 0);
out_be16(&param->brkec, 0);
out_be16(&param->brkln, 0);
out_be16(&param->brkcr, 0);
rbdf = cbd_addr;
rbdf->addr = (u8 *)rbdf - 1;
rbdf->sc = 0xa000;
rbdf->len = 1;
tbdf = rbdf + 1;
tbdf->addr = (u8 *)rbdf - 2;
tbdf->sc = 0x2000;
tbdf->len = 1;
sync();
out_be16(&param->rbase, cbd_offset);
out_be16(&param->tbase, cbd_offset + sizeof(struct cpm_bd));
do_cmd(CPM_CMD_INIT_RX_TX);
enable_port();
return 0;
}
static void cpm_serial_putc(unsigned char c)
{
while (tbdf->sc & 0x8000)
barrier();
sync();
tbdf->addr[0] = c;
eieio();
tbdf->sc |= 0x8000;
}
static unsigned char cpm_serial_tstc(void)
{
barrier();
return !(rbdf->sc & 0x8000);
}
static unsigned char cpm_serial_getc(void)
{
unsigned char c;
while (!cpm_serial_tstc())
;
sync();
c = rbdf->addr[0];
eieio();
rbdf->sc |= 0x8000;
return c;
}
int cpm_console_init(void *devp, struct serial_console_data *scdp)
{
void *vreg[2];
u32 reg[2];
int is_smc = 0, is_cpm2 = 0;
void *parent, *muram;
void *muram_addr;
unsigned long muram_offset, muram_size;
if (dt_is_compatible(devp, "fsl,cpm1-smc-uart")) {
is_smc = 1;
} else if (dt_is_compatible(devp, "fsl,cpm2-scc-uart")) {
is_cpm2 = 1;
} else if (dt_is_compatible(devp, "fsl,cpm2-smc-uart")) {
is_cpm2 = 1;
is_smc = 1;
}
if (is_smc) {
enable_port = smc_enable_port;
disable_port = smc_disable_port;
} else {
enable_port = scc_enable_port;
disable_port = scc_disable_port;
}
if (is_cpm2)
do_cmd = cpm2_cmd;
else
do_cmd = cpm1_cmd;
if (getprop(devp, "fsl,cpm-command", &cpm_cmd, 4) < 4)
return -1;
if (dt_get_virtual_reg(devp, vreg, 2) < 2)
return -1;
if (is_smc)
smc = vreg[0];
else
scc = vreg[0];
param = vreg[1];
parent = get_parent(devp);
if (!parent)
return -1;
if (dt_get_virtual_reg(parent, &cpcr, 1) < 1)
return -1;
muram = finddevice("/soc/cpm/muram/data");
if (!muram)
return -1;
if (dt_get_virtual_reg(muram, &muram_addr, 1) < 1)
return -1;
if (getprop(muram, "reg", reg, 8) < 8)
return -1;
muram_offset = reg[0];
muram_size = reg[1];
cbd_offset = muram_offset + muram_size - 2 * sizeof(struct cpm_bd);
if (is_cpm2 && is_smc) {
u16 *smc_base = (u16 *)param;
u16 pram_offset;
pram_offset = cbd_offset - 64;
pram_offset = _ALIGN_DOWN(pram_offset, 64);
disable_port();
out_be16(smc_base, pram_offset);
param = muram_addr - muram_offset + pram_offset;
}
cbd_addr = muram_addr - muram_offset + cbd_offset;
scdp->open = cpm_serial_open;
scdp->putc = cpm_serial_putc;
scdp->getc = cpm_serial_getc;
scdp->tstc = cpm_serial_tstc;
return 0;
}
