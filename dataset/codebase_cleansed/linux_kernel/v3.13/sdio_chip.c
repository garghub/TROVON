u8
brcmf_sdio_chip_getinfidx(struct chip_info *ci, u16 coreid)
{
u8 idx;
for (idx = 0; idx < BRCMF_MAX_CORENUM; idx++)
if (coreid == ci->c_inf[idx].id)
return idx;
return BRCMF_MAX_CORENUM;
}
static u32
brcmf_sdio_sb_corerev(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid)
{
u32 regdata;
u8 idx;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbidhigh),
NULL);
return SBCOREREV(regdata);
}
static u32
brcmf_sdio_ai_corerev(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid)
{
u8 idx;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
return (ci->c_inf[idx].cib & CIB_REV_MASK) >> CIB_REV_SHIFT;
}
static bool
brcmf_sdio_sb_iscoreup(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid)
{
u32 regdata;
u8 idx;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
if (idx == BRCMF_MAX_CORENUM)
return false;
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbtmstatelow),
NULL);
regdata &= (SSB_TMSLOW_RESET | SSB_TMSLOW_REJECT |
SSB_IMSTATE_REJECT | SSB_TMSLOW_CLOCK);
return (SSB_TMSLOW_CLOCK == regdata);
}
static bool
brcmf_sdio_ai_iscoreup(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid)
{
u32 regdata;
u8 idx;
bool ret;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
if (idx == BRCMF_MAX_CORENUM)
return false;
regdata = brcmf_sdio_regrl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_IOCTL,
NULL);
ret = (regdata & (BCMA_IOCTL_FGC | BCMA_IOCTL_CLK)) == BCMA_IOCTL_CLK;
regdata = brcmf_sdio_regrl(sdiodev,
ci->c_inf[idx].wrapbase+BCMA_RESET_CTL,
NULL);
ret = ret && ((regdata & BCMA_RESET_CTL_RESET) == 0);
return ret;
}
static void
brcmf_sdio_sb_coredisable(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid, u32 core_bits)
{
u32 regdata, base;
u8 idx;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
base = ci->c_inf[idx].base;
regdata = brcmf_sdio_regrl(sdiodev, CORE_SB(base, sbtmstatelow), NULL);
if (regdata & SSB_TMSLOW_RESET)
return;
regdata = brcmf_sdio_regrl(sdiodev, CORE_SB(base, sbtmstatelow), NULL);
if ((regdata & SSB_TMSLOW_CLOCK) != 0) {
regdata = brcmf_sdio_regrl(sdiodev, CORE_SB(base, sbtmstatelow),
NULL);
brcmf_sdio_regwl(sdiodev, CORE_SB(base, sbtmstatelow),
regdata | SSB_TMSLOW_REJECT, NULL);
regdata = brcmf_sdio_regrl(sdiodev, CORE_SB(base, sbtmstatelow),
NULL);
udelay(1);
SPINWAIT((brcmf_sdio_regrl(sdiodev,
CORE_SB(base, sbtmstatehigh),
NULL) &
SSB_TMSHIGH_BUSY), 100000);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(base, sbtmstatehigh),
NULL);
if (regdata & SSB_TMSHIGH_BUSY)
brcmf_err("core state still busy\n");
regdata = brcmf_sdio_regrl(sdiodev, CORE_SB(base, sbidlow),
NULL);
if (regdata & SSB_IDLOW_INITIATOR) {
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(base, sbimstate),
NULL);
regdata |= SSB_IMSTATE_REJECT;
brcmf_sdio_regwl(sdiodev, CORE_SB(base, sbimstate),
regdata, NULL);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(base, sbimstate),
NULL);
udelay(1);
SPINWAIT((brcmf_sdio_regrl(sdiodev,
CORE_SB(base, sbimstate),
NULL) &
SSB_IMSTATE_BUSY), 100000);
}
regdata = SSB_TMSLOW_FGC | SSB_TMSLOW_CLOCK |
SSB_TMSLOW_REJECT | SSB_TMSLOW_RESET;
brcmf_sdio_regwl(sdiodev, CORE_SB(base, sbtmstatelow),
regdata, NULL);
regdata = brcmf_sdio_regrl(sdiodev, CORE_SB(base, sbtmstatelow),
NULL);
udelay(10);
regdata = brcmf_sdio_regrl(sdiodev, CORE_SB(base, sbidlow),
NULL);
if (regdata & SSB_IDLOW_INITIATOR) {
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(base, sbimstate),
NULL);
regdata &= ~SSB_IMSTATE_REJECT;
brcmf_sdio_regwl(sdiodev, CORE_SB(base, sbimstate),
regdata, NULL);
}
}
brcmf_sdio_regwl(sdiodev, CORE_SB(base, sbtmstatelow),
(SSB_TMSLOW_REJECT | SSB_TMSLOW_RESET), NULL);
udelay(1);
}
static void
brcmf_sdio_ai_coredisable(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid, u32 core_bits)
{
u8 idx;
u32 regdata;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
if (idx == BRCMF_MAX_CORENUM)
return;
regdata = brcmf_sdio_regrl(sdiodev,
ci->c_inf[idx].wrapbase+BCMA_RESET_CTL,
NULL);
if ((regdata & BCMA_RESET_CTL_RESET) != 0)
return;
SPINWAIT(brcmf_sdio_regrl(sdiodev,
ci->c_inf[idx].wrapbase+BCMA_RESET_ST,
NULL), 10300);
regdata = brcmf_sdio_regrl(sdiodev,
ci->c_inf[idx].wrapbase+BCMA_RESET_ST,
NULL);
if (regdata)
brcmf_err("disabling core 0x%x with reset status %x\n",
coreid, regdata);
brcmf_sdio_regwl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_RESET_CTL,
BCMA_RESET_CTL_RESET, NULL);
udelay(1);
brcmf_sdio_regwl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_IOCTL,
core_bits, NULL);
regdata = brcmf_sdio_regrl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_IOCTL,
NULL);
usleep_range(10, 20);
}
static void
brcmf_sdio_sb_resetcore(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid, u32 core_bits)
{
u32 regdata;
u8 idx;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
if (idx == BRCMF_MAX_CORENUM)
return;
brcmf_sdio_sb_coredisable(sdiodev, ci, coreid, 0);
brcmf_sdio_regwl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbtmstatelow),
SSB_TMSLOW_FGC | SSB_TMSLOW_CLOCK | SSB_TMSLOW_RESET,
NULL);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbtmstatelow),
NULL);
udelay(1);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbtmstatehigh),
NULL);
if (regdata & SSB_TMSHIGH_SERR)
brcmf_sdio_regwl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbtmstatehigh),
0, NULL);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbimstate),
NULL);
if (regdata & (SSB_IMSTATE_IBE | SSB_IMSTATE_TO))
brcmf_sdio_regwl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbimstate),
regdata & ~(SSB_IMSTATE_IBE | SSB_IMSTATE_TO),
NULL);
brcmf_sdio_regwl(sdiodev, CORE_SB(ci->c_inf[idx].base, sbtmstatelow),
SSB_TMSLOW_FGC | SSB_TMSLOW_CLOCK, NULL);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbtmstatelow),
NULL);
udelay(1);
brcmf_sdio_regwl(sdiodev, CORE_SB(ci->c_inf[idx].base, sbtmstatelow),
SSB_TMSLOW_CLOCK, NULL);
regdata = brcmf_sdio_regrl(sdiodev,
CORE_SB(ci->c_inf[idx].base, sbtmstatelow),
NULL);
udelay(1);
}
static void
brcmf_sdio_ai_resetcore(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u16 coreid, u32 core_bits)
{
u8 idx;
u32 regdata;
idx = brcmf_sdio_chip_getinfidx(ci, coreid);
if (idx == BRCMF_MAX_CORENUM)
return;
brcmf_sdio_ai_coredisable(sdiodev, ci, coreid, core_bits);
brcmf_sdio_regwl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_IOCTL,
core_bits | BCMA_IOCTL_FGC | BCMA_IOCTL_CLK, NULL);
regdata = brcmf_sdio_regrl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_IOCTL,
NULL);
brcmf_sdio_regwl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_RESET_CTL,
0, NULL);
regdata = brcmf_sdio_regrl(sdiodev,
ci->c_inf[idx].wrapbase+BCMA_RESET_CTL,
NULL);
udelay(1);
brcmf_sdio_regwl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_IOCTL,
core_bits | BCMA_IOCTL_CLK, NULL);
regdata = brcmf_sdio_regrl(sdiodev, ci->c_inf[idx].wrapbase+BCMA_IOCTL,
NULL);
udelay(1);
}
static int brcmf_sdio_chip_cichk(struct chip_info *ci)
{
u8 core_idx;
core_idx = brcmf_sdio_chip_getinfidx(ci, BCMA_CORE_ARM_CM3);
if (BRCMF_MAX_CORENUM != core_idx) {
core_idx = brcmf_sdio_chip_getinfidx(ci,
BCMA_CORE_INTERNAL_MEM);
if (BRCMF_MAX_CORENUM == core_idx) {
brcmf_err("RAM core not provided with ARM CM3 core\n");
return -ENODEV;
}
}
core_idx = brcmf_sdio_chip_getinfidx(ci, BCMA_CORE_ARM_CR4);
if (BRCMF_MAX_CORENUM != core_idx) {
if (ci->rambase == 0) {
brcmf_err("RAM base not provided with ARM CR4 core\n");
return -ENOMEM;
}
}
return 0;
}
static inline int brcmf_sdio_chip_cichk(struct chip_info *ci)
{
return 0;
}
static int brcmf_sdio_chip_recognition(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u32 regs)
{
u32 regdata;
int ret;
ci->c_inf[0].id = BCMA_CORE_CHIPCOMMON;
ci->c_inf[0].base = regs;
regdata = brcmf_sdio_regrl(sdiodev,
CORE_CC_REG(ci->c_inf[0].base, chipid),
NULL);
ci->chip = regdata & CID_ID_MASK;
ci->chiprev = (regdata & CID_REV_MASK) >> CID_REV_SHIFT;
if (sdiodev->func[0]->device == SDIO_DEVICE_ID_BROADCOM_4335_4339 &&
ci->chiprev >= 2)
ci->chip = BCM4339_CHIP_ID;
ci->socitype = (regdata & CID_TYPE_MASK) >> CID_TYPE_SHIFT;
brcmf_dbg(INFO, "chipid=0x%x chiprev=%d\n", ci->chip, ci->chiprev);
switch (ci->chip) {
case BCM43143_CHIP_ID:
ci->c_inf[0].wrapbase = ci->c_inf[0].base + 0x00100000;
ci->c_inf[0].cib = 0x2b000000;
ci->c_inf[1].id = BCMA_CORE_SDIO_DEV;
ci->c_inf[1].base = BCM43143_CORE_BUS_BASE;
ci->c_inf[1].wrapbase = ci->c_inf[1].base + 0x00100000;
ci->c_inf[1].cib = 0x18000000;
ci->c_inf[2].id = BCMA_CORE_INTERNAL_MEM;
ci->c_inf[2].base = BCM43143_CORE_SOCRAM_BASE;
ci->c_inf[2].wrapbase = ci->c_inf[2].base + 0x00100000;
ci->c_inf[2].cib = 0x14000000;
ci->c_inf[3].id = BCMA_CORE_ARM_CM3;
ci->c_inf[3].base = BCM43143_CORE_ARM_BASE;
ci->c_inf[3].wrapbase = ci->c_inf[3].base + 0x00100000;
ci->c_inf[3].cib = 0x07000000;
ci->ramsize = BCM43143_RAMSIZE;
break;
case BCM43241_CHIP_ID:
ci->c_inf[0].wrapbase = 0x18100000;
ci->c_inf[0].cib = 0x2a084411;
ci->c_inf[1].id = BCMA_CORE_SDIO_DEV;
ci->c_inf[1].base = 0x18002000;
ci->c_inf[1].wrapbase = 0x18102000;
ci->c_inf[1].cib = 0x0e004211;
ci->c_inf[2].id = BCMA_CORE_INTERNAL_MEM;
ci->c_inf[2].base = 0x18004000;
ci->c_inf[2].wrapbase = 0x18104000;
ci->c_inf[2].cib = 0x14080401;
ci->c_inf[3].id = BCMA_CORE_ARM_CM3;
ci->c_inf[3].base = 0x18003000;
ci->c_inf[3].wrapbase = 0x18103000;
ci->c_inf[3].cib = 0x07004211;
ci->ramsize = 0x90000;
break;
case BCM4329_CHIP_ID:
ci->c_inf[1].id = BCMA_CORE_SDIO_DEV;
ci->c_inf[1].base = BCM4329_CORE_BUS_BASE;
ci->c_inf[2].id = BCMA_CORE_INTERNAL_MEM;
ci->c_inf[2].base = BCM4329_CORE_SOCRAM_BASE;
ci->c_inf[3].id = BCMA_CORE_ARM_CM3;
ci->c_inf[3].base = BCM4329_CORE_ARM_BASE;
ci->ramsize = BCM4329_RAMSIZE;
break;
case BCM4330_CHIP_ID:
ci->c_inf[0].wrapbase = 0x18100000;
ci->c_inf[0].cib = 0x27004211;
ci->c_inf[1].id = BCMA_CORE_SDIO_DEV;
ci->c_inf[1].base = 0x18002000;
ci->c_inf[1].wrapbase = 0x18102000;
ci->c_inf[1].cib = 0x07004211;
ci->c_inf[2].id = BCMA_CORE_INTERNAL_MEM;
ci->c_inf[2].base = 0x18004000;
ci->c_inf[2].wrapbase = 0x18104000;
ci->c_inf[2].cib = 0x0d080401;
ci->c_inf[3].id = BCMA_CORE_ARM_CM3;
ci->c_inf[3].base = 0x18003000;
ci->c_inf[3].wrapbase = 0x18103000;
ci->c_inf[3].cib = 0x03004211;
ci->ramsize = 0x48000;
break;
case BCM4334_CHIP_ID:
ci->c_inf[0].wrapbase = 0x18100000;
ci->c_inf[0].cib = 0x29004211;
ci->c_inf[1].id = BCMA_CORE_SDIO_DEV;
ci->c_inf[1].base = 0x18002000;
ci->c_inf[1].wrapbase = 0x18102000;
ci->c_inf[1].cib = 0x0d004211;
ci->c_inf[2].id = BCMA_CORE_INTERNAL_MEM;
ci->c_inf[2].base = 0x18004000;
ci->c_inf[2].wrapbase = 0x18104000;
ci->c_inf[2].cib = 0x13080401;
ci->c_inf[3].id = BCMA_CORE_ARM_CM3;
ci->c_inf[3].base = 0x18003000;
ci->c_inf[3].wrapbase = 0x18103000;
ci->c_inf[3].cib = 0x07004211;
ci->ramsize = 0x80000;
break;
case BCM4335_CHIP_ID:
ci->c_inf[0].wrapbase = 0x18100000;
ci->c_inf[0].cib = 0x2b084411;
ci->c_inf[1].id = BCMA_CORE_SDIO_DEV;
ci->c_inf[1].base = 0x18005000;
ci->c_inf[1].wrapbase = 0x18105000;
ci->c_inf[1].cib = 0x0f004211;
ci->c_inf[2].id = BCMA_CORE_ARM_CR4;
ci->c_inf[2].base = 0x18002000;
ci->c_inf[2].wrapbase = 0x18102000;
ci->c_inf[2].cib = 0x01084411;
ci->ramsize = 0xc0000;
ci->rambase = 0x180000;
break;
case BCM4339_CHIP_ID:
ci->c_inf[0].wrapbase = 0x18100000;
ci->c_inf[0].cib = 0x2e084411;
ci->c_inf[1].id = BCMA_CORE_SDIO_DEV;
ci->c_inf[1].base = 0x18005000;
ci->c_inf[1].wrapbase = 0x18105000;
ci->c_inf[1].cib = 0x15004211;
ci->c_inf[2].id = BCMA_CORE_ARM_CR4;
ci->c_inf[2].base = 0x18002000;
ci->c_inf[2].wrapbase = 0x18102000;
ci->c_inf[2].cib = 0x04084411;
ci->ramsize = 0xc0000;
ci->rambase = 0x180000;
break;
default:
brcmf_err("chipid 0x%x is not supported\n", ci->chip);
return -ENODEV;
}
ret = brcmf_sdio_chip_cichk(ci);
if (ret)
return ret;
switch (ci->socitype) {
case SOCI_SB:
ci->iscoreup = brcmf_sdio_sb_iscoreup;
ci->corerev = brcmf_sdio_sb_corerev;
ci->coredisable = brcmf_sdio_sb_coredisable;
ci->resetcore = brcmf_sdio_sb_resetcore;
break;
case SOCI_AI:
ci->iscoreup = brcmf_sdio_ai_iscoreup;
ci->corerev = brcmf_sdio_ai_corerev;
ci->coredisable = brcmf_sdio_ai_coredisable;
ci->resetcore = brcmf_sdio_ai_resetcore;
break;
default:
brcmf_err("socitype %u not supported\n", ci->socitype);
return -ENODEV;
}
return 0;
}
static int
brcmf_sdio_chip_buscoreprep(struct brcmf_sdio_dev *sdiodev)
{
int err = 0;
u8 clkval, clkset;
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF | SBSDIO_ALP_AVAIL_REQ;
brcmf_sdio_regwb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR, clkset, &err);
if (err) {
brcmf_err("error writing for HT off\n");
return err;
}
clkval = brcmf_sdio_regrb(sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, NULL);
if ((clkval & ~SBSDIO_AVBITS) != clkset) {
brcmf_err("ChipClkCSR access: wrote 0x%02x read 0x%02x\n",
clkset, clkval);
return -EACCES;
}
SPINWAIT(((clkval = brcmf_sdio_regrb(sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, NULL)),
!SBSDIO_ALPAV(clkval)),
PMU_MAX_TRANSITION_DLY);
if (!SBSDIO_ALPAV(clkval)) {
brcmf_err("timeout on ALPAV wait, clkval 0x%02x\n",
clkval);
return -EBUSY;
}
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF | SBSDIO_FORCE_ALP;
brcmf_sdio_regwb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR, clkset, &err);
udelay(65);
brcmf_sdio_regwb(sdiodev, SBSDIO_FUNC1_SDIOPULLUP, 0, NULL);
return 0;
}
static void
brcmf_sdio_chip_buscoresetup(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci)
{
u32 base = ci->c_inf[0].base;
ci->c_inf[0].rev = ci->corerev(sdiodev, ci, ci->c_inf[0].id);
ci->c_inf[0].caps = brcmf_sdio_regrl(sdiodev,
CORE_CC_REG(base, capabilities),
NULL);
if (ci->c_inf[0].caps & CC_CAP_PMU) {
ci->pmucaps =
brcmf_sdio_regrl(sdiodev,
CORE_CC_REG(base, pmucapabilities),
NULL);
ci->pmurev = ci->pmucaps & PCAP_REV_MASK;
}
ci->c_inf[1].rev = ci->corerev(sdiodev, ci, ci->c_inf[1].id);
brcmf_dbg(INFO, "ccrev=%d, pmurev=%d, buscore rev/type=%d/0x%x\n",
ci->c_inf[0].rev, ci->pmurev,
ci->c_inf[1].rev, ci->c_inf[1].id);
ci->coredisable(sdiodev, ci, BCMA_CORE_ARM_CM3, 0);
}
int brcmf_sdio_chip_attach(struct brcmf_sdio_dev *sdiodev,
struct chip_info **ci_ptr, u32 regs)
{
int ret;
struct chip_info *ci;
brcmf_dbg(TRACE, "Enter\n");
ci = kzalloc(sizeof(struct chip_info), GFP_ATOMIC);
if (!ci)
return -ENOMEM;
ret = brcmf_sdio_chip_buscoreprep(sdiodev);
if (ret != 0)
goto err;
ret = brcmf_sdio_chip_recognition(sdiodev, ci, regs);
if (ret != 0)
goto err;
brcmf_sdio_chip_buscoresetup(sdiodev, ci);
brcmf_sdio_regwl(sdiodev, CORE_CC_REG(ci->c_inf[0].base, gpiopullup),
0, NULL);
brcmf_sdio_regwl(sdiodev, CORE_CC_REG(ci->c_inf[0].base, gpiopulldown),
0, NULL);
*ci_ptr = ci;
return 0;
err:
kfree(ci);
return ret;
}
void
brcmf_sdio_chip_detach(struct chip_info **ci_ptr)
{
brcmf_dbg(TRACE, "Enter\n");
kfree(*ci_ptr);
*ci_ptr = NULL;
}
static char *brcmf_sdio_chip_name(uint chipid, char *buf, uint len)
{
const char *fmt;
fmt = ((chipid > 0xa000) || (chipid < 0x4000)) ? "%d" : "%x";
snprintf(buf, len, fmt, chipid);
return buf;
}
void
brcmf_sdio_chip_drivestrengthinit(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, u32 drivestrength)
{
const struct sdiod_drive_str *str_tab = NULL;
u32 str_mask;
u32 str_shift;
char chn[8];
u32 base = ci->c_inf[0].base;
u32 i;
u32 drivestrength_sel = 0;
u32 cc_data_temp;
u32 addr;
if (!(ci->c_inf[0].caps & CC_CAP_PMU))
return;
switch (SDIOD_DRVSTR_KEY(ci->chip, ci->pmurev)) {
case SDIOD_DRVSTR_KEY(BCM4330_CHIP_ID, 12):
str_tab = sdiod_drvstr_tab1_1v8;
str_mask = 0x00003800;
str_shift = 11;
break;
case SDIOD_DRVSTR_KEY(BCM43143_CHIP_ID, 17):
i = ARRAY_SIZE(sdiod_drvstr_tab2_3v3) - 1;
if (drivestrength >= sdiod_drvstr_tab2_3v3[i].strength) {
str_tab = sdiod_drvstr_tab2_3v3;
str_mask = 0x00000007;
str_shift = 0;
} else
brcmf_err("Invalid SDIO Drive strength for chip %s, strength=%d\n",
brcmf_sdio_chip_name(ci->chip, chn, 8),
drivestrength);
break;
default:
brcmf_err("No SDIO Drive strength init done for chip %s rev %d pmurev %d\n",
brcmf_sdio_chip_name(ci->chip, chn, 8),
ci->chiprev, ci->pmurev);
break;
}
if (str_tab != NULL) {
for (i = 0; str_tab[i].strength != 0; i++) {
if (drivestrength >= str_tab[i].strength) {
drivestrength_sel = str_tab[i].sel;
break;
}
}
addr = CORE_CC_REG(base, chipcontrol_addr);
brcmf_sdio_regwl(sdiodev, addr, 1, NULL);
cc_data_temp = brcmf_sdio_regrl(sdiodev, addr, NULL);
cc_data_temp &= ~str_mask;
drivestrength_sel <<= str_shift;
cc_data_temp |= drivestrength_sel;
brcmf_sdio_regwl(sdiodev, addr, cc_data_temp, NULL);
brcmf_dbg(INFO, "SDIO: %d mA (req=%d mA) drive strength selected, set to 0x%08x\n",
str_tab[i].strength, drivestrength, cc_data_temp);
}
}
static bool
brcmf_sdio_chip_verifynvram(struct brcmf_sdio_dev *sdiodev, u32 nvram_addr,
char *nvram_dat, uint nvram_sz)
{
char *nvram_ularray;
int err;
bool ret = true;
brcmf_dbg(INFO, "Compare NVRAM dl & ul; size=%d\n", nvram_sz);
nvram_ularray = kmalloc(nvram_sz, GFP_KERNEL);
if (!nvram_ularray)
return true;
memset(nvram_ularray, 0xaa, nvram_sz);
err = brcmf_sdio_ramrw(sdiodev, false, nvram_addr, nvram_ularray,
nvram_sz);
if (err) {
brcmf_err("error %d on reading %d nvram bytes at 0x%08x\n",
err, nvram_sz, nvram_addr);
} else if (memcmp(nvram_dat, nvram_ularray, nvram_sz)) {
brcmf_err("Downloaded NVRAM image is corrupted\n");
ret = false;
}
kfree(nvram_ularray);
return ret;
}
static inline bool
brcmf_sdio_chip_verifynvram(struct brcmf_sdio_dev *sdiodev, u32 nvram_addr,
char *nvram_dat, uint nvram_sz)
{
return true;
}
static bool brcmf_sdio_chip_writenvram(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci,
char *nvram_dat, uint nvram_sz)
{
int err;
u32 nvram_addr;
u32 token;
__le32 token_le;
nvram_addr = (ci->ramsize - 4) - nvram_sz + ci->rambase;
err = brcmf_sdio_ramrw(sdiodev, true, nvram_addr, nvram_dat, nvram_sz);
if (err) {
brcmf_err("error %d on writing %d nvram bytes at 0x%08x\n",
err, nvram_sz, nvram_addr);
return false;
}
if (!brcmf_sdio_chip_verifynvram(sdiodev, nvram_addr,
nvram_dat, nvram_sz))
return false;
token = nvram_sz / 4;
token = (~token << 16) | (token & 0x0000FFFF);
token_le = cpu_to_le32(token);
brcmf_dbg(INFO, "RAM size: %d\n", ci->ramsize);
brcmf_dbg(INFO, "nvram is placed at %d, size %d, token=0x%08x\n",
nvram_addr, nvram_sz, token);
if (brcmf_sdio_ramrw(sdiodev, true, (ci->ramsize - 4 + ci->rambase),
(u8 *)&token_le, 4))
return false;
return true;
}
static void
brcmf_sdio_chip_cm3_enterdl(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci)
{
u32 zeros = 0;
ci->coredisable(sdiodev, ci, BCMA_CORE_ARM_CM3, 0);
ci->resetcore(sdiodev, ci, BCMA_CORE_INTERNAL_MEM, 0);
brcmf_sdio_ramrw(sdiodev, true, ci->ramsize - 4, (u8 *)&zeros, 4);
}
static bool
brcmf_sdio_chip_cm3_exitdl(struct brcmf_sdio_dev *sdiodev, struct chip_info *ci,
char *nvram_dat, uint nvram_sz)
{
u8 core_idx;
u32 reg_addr;
if (!ci->iscoreup(sdiodev, ci, BCMA_CORE_INTERNAL_MEM)) {
brcmf_err("SOCRAM core is down after reset?\n");
return false;
}
if (!brcmf_sdio_chip_writenvram(sdiodev, ci, nvram_dat, nvram_sz))
return false;
core_idx = brcmf_sdio_chip_getinfidx(ci, BCMA_CORE_SDIO_DEV);
reg_addr = ci->c_inf[core_idx].base;
reg_addr += offsetof(struct sdpcmd_regs, intstatus);
brcmf_sdio_regwl(sdiodev, reg_addr, 0xFFFFFFFF, NULL);
ci->resetcore(sdiodev, ci, BCMA_CORE_ARM_CM3, 0);
return true;
}
static inline void
brcmf_sdio_chip_cr4_enterdl(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci)
{
ci->resetcore(sdiodev, ci, BCMA_CORE_ARM_CR4,
ARMCR4_BCMA_IOCTL_CPUHALT);
}
static bool
brcmf_sdio_chip_cr4_exitdl(struct brcmf_sdio_dev *sdiodev, struct chip_info *ci,
char *nvram_dat, uint nvram_sz)
{
u8 core_idx;
u32 reg_addr;
if (!brcmf_sdio_chip_writenvram(sdiodev, ci, nvram_dat, nvram_sz))
return false;
core_idx = brcmf_sdio_chip_getinfidx(ci, BCMA_CORE_SDIO_DEV);
reg_addr = ci->c_inf[core_idx].base;
reg_addr += offsetof(struct sdpcmd_regs, intstatus);
brcmf_sdio_regwl(sdiodev, reg_addr, 0xFFFFFFFF, NULL);
brcmf_sdio_ramrw(sdiodev, true, 0, (void *)&ci->rst_vec,
sizeof(ci->rst_vec));
ci->resetcore(sdiodev, ci, BCMA_CORE_ARM_CR4, 0);
return true;
}
void brcmf_sdio_chip_enter_download(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci)
{
u8 arm_core_idx;
arm_core_idx = brcmf_sdio_chip_getinfidx(ci, BCMA_CORE_ARM_CM3);
if (BRCMF_MAX_CORENUM != arm_core_idx) {
brcmf_sdio_chip_cm3_enterdl(sdiodev, ci);
return;
}
brcmf_sdio_chip_cr4_enterdl(sdiodev, ci);
}
bool brcmf_sdio_chip_exit_download(struct brcmf_sdio_dev *sdiodev,
struct chip_info *ci, char *nvram_dat,
uint nvram_sz)
{
u8 arm_core_idx;
arm_core_idx = brcmf_sdio_chip_getinfidx(ci, BCMA_CORE_ARM_CM3);
if (BRCMF_MAX_CORENUM != arm_core_idx)
return brcmf_sdio_chip_cm3_exitdl(sdiodev, ci, nvram_dat,
nvram_sz);
return brcmf_sdio_chip_cr4_exitdl(sdiodev, ci, nvram_dat, nvram_sz);
}
