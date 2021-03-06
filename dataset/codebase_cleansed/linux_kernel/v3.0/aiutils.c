static u32
get_erom_ent(si_t *sih, u32 **eromptr, u32 mask, u32 match)
{
u32 ent;
uint inv = 0, nom = 0;
while (true) {
ent = R_REG(*eromptr);
(*eromptr)++;
if (mask == 0)
break;
if ((ent & ER_VALID) == 0) {
inv++;
continue;
}
if (ent == (ER_END | ER_VALID))
break;
if ((ent & mask) == match)
break;
nom++;
}
SI_VMSG(("%s: Returning ent 0x%08x\n", __func__, ent));
if (inv + nom) {
SI_VMSG((" after %d invalid and %d non-matching entries\n",
inv, nom));
}
return ent;
}
static u32
get_asd(si_t *sih, u32 **eromptr, uint sp, uint ad, uint st,
u32 *addrl, u32 *addrh, u32 *sizel, u32 *sizeh)
{
u32 asd, sz, szd;
asd = get_erom_ent(sih, eromptr, ER_VALID, ER_VALID);
if (((asd & ER_TAG1) != ER_ADD) ||
(((asd & AD_SP_MASK) >> AD_SP_SHIFT) != sp) ||
((asd & AD_ST_MASK) != st)) {
(*eromptr)--;
return 0;
}
*addrl = asd & AD_ADDR_MASK;
if (asd & AD_AG32)
*addrh = get_erom_ent(sih, eromptr, 0, 0);
else
*addrh = 0;
*sizeh = 0;
sz = asd & AD_SZ_MASK;
if (sz == AD_SZ_SZD) {
szd = get_erom_ent(sih, eromptr, 0, 0);
*sizel = szd & SD_SZ_MASK;
if (szd & SD_SG32)
*sizeh = get_erom_ent(sih, eromptr, 0, 0);
} else
*sizel = AD_SZ_BASE << (sz >> AD_SZ_SHIFT);
SI_VMSG((" SP %d, ad %d: st = %d, 0x%08x_0x%08x @ 0x%08x_0x%08x\n",
sp, ad, st, *sizeh, *sizel, *addrh, *addrl));
return asd;
}
static void ai_hwfixup(si_info_t *sii)
{
}
void ai_scan(si_t *sih, void *regs, uint devid)
{
si_info_t *sii = SI_INFO(sih);
chipcregs_t *cc = (chipcregs_t *) regs;
u32 erombase, *eromptr, *eromlim;
erombase = R_REG(&cc->eromptr);
switch (sih->bustype) {
case SI_BUS:
eromptr = (u32 *) REG_MAP(erombase, SI_CORE_SIZE);
break;
case PCI_BUS:
sii->curwrap = (void *)((unsigned long)regs + SI_CORE_SIZE);
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN, erombase);
eromptr = regs;
break;
case SPI_BUS:
case SDIO_BUS:
eromptr = (u32 *)(unsigned long)erombase;
break;
default:
SI_ERROR(("Don't know how to do AXI enumertion on bus %d\n",
sih->bustype));
return;
}
eromlim = eromptr + (ER_REMAPCONTROL / sizeof(u32));
SI_VMSG(("ai_scan: regs = 0x%p, erombase = 0x%08x, eromptr = 0x%p, eromlim = 0x%p\n", regs, erombase, eromptr, eromlim));
while (eromptr < eromlim) {
u32 cia, cib, cid, mfg, crev, nmw, nsw, nmp, nsp;
u32 mpd, asd, addrl, addrh, sizel, sizeh;
u32 *base;
uint i, j, idx;
bool br;
br = false;
cia = get_erom_ent(sih, &eromptr, ER_TAG, ER_CI);
if (cia == (ER_END | ER_VALID)) {
SI_VMSG(("Found END of erom after %d cores\n",
sii->numcores));
ai_hwfixup(sii);
return;
}
base = eromptr - 1;
cib = get_erom_ent(sih, &eromptr, 0, 0);
if ((cib & ER_TAG) != ER_CI) {
SI_ERROR(("CIA not followed by CIB\n"));
goto error;
}
cid = (cia & CIA_CID_MASK) >> CIA_CID_SHIFT;
mfg = (cia & CIA_MFG_MASK) >> CIA_MFG_SHIFT;
crev = (cib & CIB_REV_MASK) >> CIB_REV_SHIFT;
nmw = (cib & CIB_NMW_MASK) >> CIB_NMW_SHIFT;
nsw = (cib & CIB_NSW_MASK) >> CIB_NSW_SHIFT;
nmp = (cib & CIB_NMP_MASK) >> CIB_NMP_SHIFT;
nsp = (cib & CIB_NSP_MASK) >> CIB_NSP_SHIFT;
SI_VMSG(("Found component 0x%04x/0x%04x rev %d at erom addr 0x%p, with nmw = %d, " "nsw = %d, nmp = %d & nsp = %d\n", mfg, cid, crev, base, nmw, nsw, nmp, nsp));
if (((mfg == MFGID_ARM) && (cid == DEF_AI_COMP)) || (nsp == 0))
continue;
if ((nmw + nsw == 0)) {
if (cid == OOB_ROUTER_CORE_ID) {
asd = get_asd(sih, &eromptr, 0, 0, AD_ST_SLAVE,
&addrl, &addrh, &sizel, &sizeh);
if (asd != 0) {
sii->oob_router = addrl;
}
}
continue;
}
idx = sii->numcores;
sii->cia[idx] = cia;
sii->cib[idx] = cib;
sii->coreid[idx] = cid;
for (i = 0; i < nmp; i++) {
mpd = get_erom_ent(sih, &eromptr, ER_VALID, ER_VALID);
if ((mpd & ER_TAG) != ER_MP) {
SI_ERROR(("Not enough MP entries for component 0x%x\n", cid));
goto error;
}
SI_VMSG((" Master port %d, mp: %d id: %d\n", i,
(mpd & MPD_MP_MASK) >> MPD_MP_SHIFT,
(mpd & MPD_MUI_MASK) >> MPD_MUI_SHIFT));
}
asd =
get_asd(sih, &eromptr, 0, 0, AD_ST_SLAVE, &addrl, &addrh,
&sizel, &sizeh);
if (asd == 0) {
asd =
get_asd(sih, &eromptr, 0, 0, AD_ST_BRIDGE, &addrl,
&addrh, &sizel, &sizeh);
if (asd != 0)
br = true;
else if ((addrh != 0) || (sizeh != 0)
|| (sizel != SI_CORE_SIZE)) {
SI_ERROR(("First Slave ASD for core 0x%04x malformed " "(0x%08x)\n", cid, asd));
goto error;
}
}
sii->coresba[idx] = addrl;
sii->coresba_size[idx] = sizel;
j = 1;
do {
asd =
get_asd(sih, &eromptr, 0, j, AD_ST_SLAVE, &addrl,
&addrh, &sizel, &sizeh);
if ((asd != 0) && (j == 1) && (sizel == SI_CORE_SIZE)) {
sii->coresba2[idx] = addrl;
sii->coresba2_size[idx] = sizel;
}
j++;
} while (asd != 0);
for (i = 1; i < nsp; i++) {
j = 0;
do {
asd =
get_asd(sih, &eromptr, i, j++, AD_ST_SLAVE,
&addrl, &addrh, &sizel, &sizeh);
} while (asd != 0);
if (j == 0) {
SI_ERROR((" SP %d has no address descriptors\n",
i));
goto error;
}
}
for (i = 0; i < nmw; i++) {
asd =
get_asd(sih, &eromptr, i, 0, AD_ST_MWRAP, &addrl,
&addrh, &sizel, &sizeh);
if (asd == 0) {
SI_ERROR(("Missing descriptor for MW %d\n", i));
goto error;
}
if ((sizeh != 0) || (sizel != SI_CORE_SIZE)) {
SI_ERROR(("Master wrapper %d is not 4KB\n", i));
goto error;
}
if (i == 0)
sii->wrapba[idx] = addrl;
}
for (i = 0; i < nsw; i++) {
uint fwp = (nsp == 1) ? 0 : 1;
asd =
get_asd(sih, &eromptr, fwp + i, 0, AD_ST_SWRAP,
&addrl, &addrh, &sizel, &sizeh);
if (asd == 0) {
SI_ERROR(("Missing descriptor for SW %d\n", i));
goto error;
}
if ((sizeh != 0) || (sizel != SI_CORE_SIZE)) {
SI_ERROR(("Slave wrapper %d is not 4KB\n", i));
goto error;
}
if ((nmw == 0) && (i == 0))
sii->wrapba[idx] = addrl;
}
if (br)
continue;
sii->numcores++;
}
SI_ERROR(("Reached end of erom without finding END"));
error:
sii->numcores = 0;
return;
}
void *ai_setcoreidx(si_t *sih, uint coreidx)
{
si_info_t *sii = SI_INFO(sih);
u32 addr = sii->coresba[coreidx];
u32 wrap = sii->wrapba[coreidx];
void *regs;
if (coreidx >= sii->numcores)
return NULL;
switch (sih->bustype) {
case SI_BUS:
if (!sii->regs[coreidx]) {
sii->regs[coreidx] = REG_MAP(addr, SI_CORE_SIZE);
}
sii->curmap = regs = sii->regs[coreidx];
if (!sii->wrappers[coreidx]) {
sii->wrappers[coreidx] = REG_MAP(wrap, SI_CORE_SIZE);
}
sii->curwrap = sii->wrappers[coreidx];
break;
case PCI_BUS:
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN, addr);
regs = sii->curmap;
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN2, wrap);
break;
case SPI_BUS:
case SDIO_BUS:
sii->curmap = regs = (void *)(unsigned long)addr;
sii->curwrap = (void *)(unsigned long)wrap;
break;
default:
regs = NULL;
break;
}
sii->curmap = regs;
sii->curidx = coreidx;
return regs;
}
int ai_numaddrspaces(si_t *sih)
{
return 2;
}
u32 ai_addrspace(si_t *sih, uint asidx)
{
si_info_t *sii;
uint cidx;
sii = SI_INFO(sih);
cidx = sii->curidx;
if (asidx == 0)
return sii->coresba[cidx];
else if (asidx == 1)
return sii->coresba2[cidx];
else {
SI_ERROR(("%s: Need to parse the erom again to find addr space %d\n", __func__, asidx));
return 0;
}
}
u32 ai_addrspacesize(si_t *sih, uint asidx)
{
si_info_t *sii;
uint cidx;
sii = SI_INFO(sih);
cidx = sii->curidx;
if (asidx == 0)
return sii->coresba_size[cidx];
else if (asidx == 1)
return sii->coresba2_size[cidx];
else {
SI_ERROR(("%s: Need to parse the erom again to find addr space %d\n", __func__, asidx));
return 0;
}
}
uint ai_flag(si_t *sih)
{
si_info_t *sii;
aidmp_t *ai;
sii = SI_INFO(sih);
if (BCM47162_DMP()) {
SI_ERROR(("%s: Attempting to read MIPS DMP registers on 47162a0", __func__));
return sii->curidx;
}
ai = sii->curwrap;
return R_REG(&ai->oobselouta30) & 0x1f;
}
void ai_setint(si_t *sih, int siflag)
{
}
uint ai_corevendor(si_t *sih)
{
si_info_t *sii;
u32 cia;
sii = SI_INFO(sih);
cia = sii->cia[sii->curidx];
return (cia & CIA_MFG_MASK) >> CIA_MFG_SHIFT;
}
uint ai_corerev(si_t *sih)
{
si_info_t *sii;
u32 cib;
sii = SI_INFO(sih);
cib = sii->cib[sii->curidx];
return (cib & CIB_REV_MASK) >> CIB_REV_SHIFT;
}
bool ai_iscoreup(si_t *sih)
{
si_info_t *sii;
aidmp_t *ai;
sii = SI_INFO(sih);
ai = sii->curwrap;
return (((R_REG(&ai->ioctrl) & (SICF_FGC | SICF_CLOCK_EN)) ==
SICF_CLOCK_EN)
&& ((R_REG(&ai->resetctrl) & AIRC_RESET) == 0));
}
void ai_core_cflags_wo(si_t *sih, u32 mask, u32 val)
{
si_info_t *sii;
aidmp_t *ai;
u32 w;
sii = SI_INFO(sih);
if (BCM47162_DMP()) {
SI_ERROR(("%s: Accessing MIPS DMP register (ioctrl) on 47162a0",
__func__));
return;
}
ai = sii->curwrap;
if (mask || val) {
w = ((R_REG(&ai->ioctrl) & ~mask) | val);
W_REG(&ai->ioctrl, w);
}
}
u32 ai_core_cflags(si_t *sih, u32 mask, u32 val)
{
si_info_t *sii;
aidmp_t *ai;
u32 w;
sii = SI_INFO(sih);
if (BCM47162_DMP()) {
SI_ERROR(("%s: Accessing MIPS DMP register (ioctrl) on 47162a0",
__func__));
return 0;
}
ai = sii->curwrap;
if (mask || val) {
w = ((R_REG(&ai->ioctrl) & ~mask) | val);
W_REG(&ai->ioctrl, w);
}
return R_REG(&ai->ioctrl);
}
u32 ai_core_sflags(si_t *sih, u32 mask, u32 val)
{
si_info_t *sii;
aidmp_t *ai;
u32 w;
sii = SI_INFO(sih);
if (BCM47162_DMP()) {
SI_ERROR(("%s: Accessing MIPS DMP register (iostatus) on 47162a0", __func__));
return 0;
}
ai = sii->curwrap;
if (mask || val) {
w = ((R_REG(&ai->iostatus) & ~mask) | val);
W_REG(&ai->iostatus, w);
}
return R_REG(&ai->iostatus);
}
si_t *ai_attach(uint devid, void *regs, uint bustype,
void *sdh, char **vars, uint *varsz)
{
si_info_t *sii;
sii = kmalloc(sizeof(si_info_t), GFP_ATOMIC);
if (sii == NULL) {
SI_ERROR(("si_attach: malloc failed!\n"));
return NULL;
}
if (ai_doattach(sii, devid, regs, bustype, sdh, vars, varsz) ==
NULL) {
kfree(sii);
return NULL;
}
sii->vars = vars ? *vars : NULL;
sii->varsz = varsz ? *varsz : 0;
return (si_t *) sii;
}
static bool ai_buscore_prep(si_info_t *sii, uint bustype, uint devid,
void *sdh)
{
if (bustype == PCI_BUS && !ai_ispcie(sii))
ai_clkctl_xtal(&sii->pub, XTAL | PLL, ON);
return true;
}
static bool ai_buscore_setup(si_info_t *sii, chipcregs_t *cc, uint bustype,
u32 savewin, uint *origidx, void *regs)
{
bool pci, pcie;
uint i;
uint pciidx, pcieidx, pcirev, pcierev;
cc = ai_setcoreidx(&sii->pub, SI_CC_IDX);
sii->pub.ccrev = (int)ai_corerev(&sii->pub);
if (sii->pub.ccrev >= 11)
sii->pub.chipst = R_REG(&cc->chipstatus);
sii->pub.cccaps = R_REG(&cc->capabilities);
if (sii->pub.ccrev >= 35)
sii->pub.cccaps_ext = R_REG(&cc->capabilities_ext);
if (sii->pub.cccaps & CC_CAP_PMU) {
sii->pub.pmucaps = R_REG(&cc->pmucapabilities);
sii->pub.pmurev = sii->pub.pmucaps & PCAP_REV_MASK;
}
sii->pub.buscoretype = NODEV_CORE_ID;
sii->pub.buscorerev = NOREV;
sii->pub.buscoreidx = BADIDX;
pci = pcie = false;
pcirev = pcierev = NOREV;
pciidx = pcieidx = BADIDX;
for (i = 0; i < sii->numcores; i++) {
uint cid, crev;
ai_setcoreidx(&sii->pub, i);
cid = ai_coreid(&sii->pub);
crev = ai_corerev(&sii->pub);
SI_VMSG(("CORE[%d]: id 0x%x rev %d base 0x%x regs 0x%p\n",
i, cid, crev, sii->coresba[i], sii->regs[i]));
if (bustype == PCI_BUS) {
if (cid == PCI_CORE_ID) {
pciidx = i;
pcirev = crev;
pci = true;
} else if (cid == PCIE_CORE_ID) {
pcieidx = i;
pcierev = crev;
pcie = true;
}
}
if ((savewin && (savewin == sii->coresba[i])) ||
(regs == sii->regs[i]))
*origidx = i;
}
if (pci && pcie) {
if (ai_ispcie(sii))
pci = false;
else
pcie = false;
}
if (pci) {
sii->pub.buscoretype = PCI_CORE_ID;
sii->pub.buscorerev = pcirev;
sii->pub.buscoreidx = pciidx;
} else if (pcie) {
sii->pub.buscoretype = PCIE_CORE_ID;
sii->pub.buscorerev = pcierev;
sii->pub.buscoreidx = pcieidx;
}
SI_VMSG(("Buscore id/type/rev %d/0x%x/%d\n", sii->pub.buscoreidx,
sii->pub.buscoretype, sii->pub.buscorerev));
if (sii->pub.bustype == PCI_BUS) {
if (SI_FAST(sii)) {
if (!sii->pch) {
sii->pch = (void *)pcicore_init(
&sii->pub, sii->pbus,
(void *)PCIEREGS(sii));
if (sii->pch == NULL)
return false;
}
}
if (ai_pci_fixcfg(&sii->pub)) {
SI_ERROR(("si_doattach: si_pci_fixcfg failed\n"));
return false;
}
}
ai_setcoreidx(&sii->pub, *origidx);
return true;
}
static __used void ai_nvram_process(si_info_t *sii, char *pvars)
{
uint w = 0;
switch (sii->pub.bustype) {
case PCI_BUS:
pci_read_config_dword(sii->pbus, PCI_SUBSYSTEM_VENDOR_ID, &w);
sii->pub.boardvendor = (u16)ai_getdevpathintvar(&sii->pub,
"boardvendor");
if (sii->pub.boardvendor == 0)
sii->pub.boardvendor = w & 0xffff;
else
SI_ERROR(("Overriding boardvendor: 0x%x instead of "
"0x%x\n", sii->pub.boardvendor, w & 0xffff));
sii->pub.boardtype = (u16)ai_getdevpathintvar(&sii->pub,
"boardtype");
if (sii->pub.boardtype == 0)
sii->pub.boardtype = (w >> 16) & 0xffff;
else
SI_ERROR(("Overriding boardtype: 0x%x instead of 0x%x\n"
, sii->pub.boardtype, (w >> 16) & 0xffff));
break;
sii->pub.boardvendor = getintvar(pvars, "manfid");
sii->pub.boardtype = getintvar(pvars, "prodid");
break;
case SI_BUS:
case JTAG_BUS:
sii->pub.boardvendor = PCI_VENDOR_ID_BROADCOM;
sii->pub.boardtype = getintvar(pvars, "prodid");
if (pvars == NULL || (sii->pub.boardtype == 0)) {
sii->pub.boardtype = getintvar(NULL, "boardtype");
if (sii->pub.boardtype == 0)
sii->pub.boardtype = 0xffff;
}
break;
}
if (sii->pub.boardtype == 0) {
SI_ERROR(("si_doattach: unknown board type\n"));
}
sii->pub.boardflags = getintvar(pvars, "boardflags");
}
static si_info_t *ai_doattach(si_info_t *sii, uint devid,
void *regs, uint bustype, void *pbus,
char **vars, uint *varsz)
{
struct si_pub *sih = &sii->pub;
u32 w, savewin;
chipcregs_t *cc;
char *pvars = NULL;
uint socitype;
uint origidx;
memset((unsigned char *) sii, 0, sizeof(si_info_t));
savewin = 0;
sih->buscoreidx = BADIDX;
sii->curmap = regs;
sii->pbus = pbus;
if (bustype == PCI_BUS) {
pci_read_config_dword(sii->pbus, PCI_SPROM_CONTROL, &w);
if (w == 0xffffffff) {
SI_ERROR(("%s: incoming bus is PCI but it's a lie, "
" switching to SI devid:0x%x\n",
__func__, devid));
bustype = SI_BUS;
}
}
if (bustype == PCI_BUS) {
pci_read_config_dword(sii->pbus, PCI_BAR0_WIN, &savewin);
if (!GOODCOREADDR(savewin, SI_ENUM_BASE))
savewin = SI_ENUM_BASE;
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN,
SI_ENUM_BASE);
cc = (chipcregs_t *) regs;
} else {
cc = (chipcregs_t *) REG_MAP(SI_ENUM_BASE, SI_CORE_SIZE);
}
sih->bustype = bustype;
if (!ai_buscore_prep(sii, bustype, devid, pbus)) {
SI_ERROR(("si_doattach: si_core_clk_prep failed %d\n",
bustype));
return NULL;
}
w = R_REG(&cc->chipid);
socitype = (w & CID_TYPE_MASK) >> CID_TYPE_SHIFT;
sih->chip = w & CID_ID_MASK;
sih->chiprev = (w & CID_REV_MASK) >> CID_REV_SHIFT;
sih->chippkg = (w & CID_PKG_MASK) >> CID_PKG_SHIFT;
sih->issim = IS_SIM(sih->chippkg);
if (socitype == SOCI_AI) {
SI_MSG(("Found chip type AI (0x%08x)\n", w));
ai_scan(&sii->pub, (void *)cc, devid);
} else {
SI_ERROR(("Found chip of unknown type (0x%08x)\n", w));
return NULL;
}
if (sii->numcores == 0) {
SI_ERROR(("si_doattach: could not find any cores\n"));
return NULL;
}
origidx = SI_CC_IDX;
if (!ai_buscore_setup(sii, cc, bustype, savewin, &origidx, regs)) {
SI_ERROR(("si_doattach: si_buscore_setup failed\n"));
goto exit;
}
if ((sii->pub.ccrev == 0x25)
&&
((sih->chip == BCM43236_CHIP_ID
|| sih->chip == BCM43235_CHIP_ID
|| sih->chip == BCM43238_CHIP_ID)
&& (sii->pub.chiprev <= 2))) {
if ((cc->chipstatus & CST43236_BP_CLK) != 0) {
uint clkdiv;
clkdiv = R_REG(&cc->clkdiv);
clkdiv = (clkdiv & ~CLKD_OTP) | (14 << CLKD_OTP_SHIFT);
W_REG(&cc->clkdiv, clkdiv);
SI_ERROR(("%s: set clkdiv to %x\n", __func__, clkdiv));
}
udelay(10);
}
nvram_init();
if (srom_var_init
(&sii->pub, bustype, regs, vars, varsz)) {
SI_ERROR(("si_doattach: srom_var_init failed: bad srom\n"));
goto exit;
}
pvars = vars ? *vars : NULL;
ai_nvram_process(sii, pvars);
cc = (chipcregs_t *) ai_setcore(sih, CC_CORE_ID, 0);
W_REG(&cc->gpiopullup, 0);
W_REG(&cc->gpiopulldown, 0);
ai_setcoreidx(sih, origidx);
if (PMUCTL_ENAB(sih)) {
u32 xtalfreq;
si_pmu_init(sih);
si_pmu_chip_init(sih);
xtalfreq = getintvar(pvars, "xtalfreq");
if (xtalfreq == 0)
xtalfreq = si_pmu_measure_alpclk(sih);
si_pmu_pll_init(sih, xtalfreq);
si_pmu_res_init(sih);
si_pmu_swreg_init(sih);
}
w = getintvar(pvars, "leddc");
if (w == 0)
w = DEFAULT_GPIOTIMERVAL;
ai_corereg(sih, SI_CC_IDX, offsetof(chipcregs_t, gpiotimerval), ~0, w);
if (PCIE(sii)) {
pcicore_attach(sii->pch, pvars, SI_DOATTACH);
}
if ((sih->chip == BCM43224_CHIP_ID) ||
(sih->chip == BCM43421_CHIP_ID)) {
if (sih->chiprev == 0) {
SI_MSG(("Applying 43224A0 WARs\n"));
ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol),
CCTRL43224_GPIO_TOGGLE,
CCTRL43224_GPIO_TOGGLE);
si_pmu_chipcontrol(sih, 0, CCTRL_43224A0_12MA_LED_DRIVE,
CCTRL_43224A0_12MA_LED_DRIVE);
}
if (sih->chiprev >= 1) {
SI_MSG(("Applying 43224B0+ WARs\n"));
si_pmu_chipcontrol(sih, 0, CCTRL_43224B0_12MA_LED_DRIVE,
CCTRL_43224B0_12MA_LED_DRIVE);
}
}
if (sih->chip == BCM4313_CHIP_ID) {
SI_MSG(("Applying 4313 WARs\n"));
si_pmu_chipcontrol(sih, 0, CCTRL_4313_12MA_LED_DRIVE,
CCTRL_4313_12MA_LED_DRIVE);
}
if (sih->chip == BCM4331_CHIP_ID) {
ai_chipcontrl_epa4331(sih, true);
}
return sii;
exit:
if (sih->bustype == PCI_BUS) {
if (sii->pch)
pcicore_deinit(sii->pch);
sii->pch = NULL;
}
return NULL;
}
void ai_detach(si_t *sih)
{
si_info_t *sii;
uint idx;
struct si_pub *si_local = NULL;
bcopy(&sih, &si_local, sizeof(si_t **));
sii = SI_INFO(sih);
if (sii == NULL)
return;
if (sih->bustype == SI_BUS)
for (idx = 0; idx < SI_MAXCORES; idx++)
if (sii->regs[idx]) {
iounmap(sii->regs[idx]);
sii->regs[idx] = NULL;
}
nvram_exit();
if (sih->bustype == PCI_BUS) {
if (sii->pch)
pcicore_deinit(sii->pch);
sii->pch = NULL;
}
if (sii != &ksii)
kfree(sii);
}
void
ai_register_intr_callback(si_t *sih, void *intrsoff_fn, void *intrsrestore_fn,
void *intrsenabled_fn, void *intr_arg)
{
si_info_t *sii;
sii = SI_INFO(sih);
sii->intr_arg = intr_arg;
sii->intrsoff_fn = (si_intrsoff_t) intrsoff_fn;
sii->intrsrestore_fn = (si_intrsrestore_t) intrsrestore_fn;
sii->intrsenabled_fn = (si_intrsenabled_t) intrsenabled_fn;
sii->dev_coreid = sii->coreid[sii->curidx];
}
void ai_deregister_intr_callback(si_t *sih)
{
si_info_t *sii;
sii = SI_INFO(sih);
sii->intrsoff_fn = NULL;
}
uint ai_coreid(si_t *sih)
{
si_info_t *sii;
sii = SI_INFO(sih);
return sii->coreid[sii->curidx];
}
uint ai_coreidx(si_t *sih)
{
si_info_t *sii;
sii = SI_INFO(sih);
return sii->curidx;
}
bool ai_backplane64(si_t *sih)
{
return (sih->cccaps & CC_CAP_BKPLN64) != 0;
}
uint ai_findcoreidx(si_t *sih, uint coreid, uint coreunit)
{
si_info_t *sii;
uint found;
uint i;
sii = SI_INFO(sih);
found = 0;
for (i = 0; i < sii->numcores; i++)
if (sii->coreid[i] == coreid) {
if (found == coreunit)
return i;
found++;
}
return BADIDX;
}
void *ai_setcore(si_t *sih, uint coreid, uint coreunit)
{
uint idx;
idx = ai_findcoreidx(sih, coreid, coreunit);
if (!GOODIDX(idx))
return NULL;
return ai_setcoreidx(sih, idx);
}
void *ai_switch_core(si_t *sih, uint coreid, uint *origidx, uint *intr_val)
{
void *cc;
si_info_t *sii;
sii = SI_INFO(sih);
if (SI_FAST(sii)) {
*origidx = coreid;
if (coreid == CC_CORE_ID)
return (void *)CCREGS_FAST(sii);
else if (coreid == sih->buscoretype)
return (void *)PCIEREGS(sii);
}
INTR_OFF(sii, *intr_val);
*origidx = sii->curidx;
cc = ai_setcore(sih, coreid, 0);
return cc;
}
void ai_restore_core(si_t *sih, uint coreid, uint intr_val)
{
si_info_t *sii;
sii = SI_INFO(sih);
if (SI_FAST(sii)
&& ((coreid == CC_CORE_ID) || (coreid == sih->buscoretype)))
return;
ai_setcoreidx(sih, coreid);
INTR_RESTORE(sii, intr_val);
}
void ai_write_wrapperreg(si_t *sih, u32 offset, u32 val)
{
si_info_t *sii = SI_INFO(sih);
u32 *w = (u32 *) sii->curwrap;
W_REG(w + (offset / 4), val);
return;
}
uint ai_corereg(si_t *sih, uint coreidx, uint regoff, uint mask, uint val)
{
uint origidx = 0;
u32 *r = NULL;
uint w;
uint intr_val = 0;
bool fast = false;
si_info_t *sii;
sii = SI_INFO(sih);
if (coreidx >= SI_MAXCORES)
return 0;
if (sih->bustype == SI_BUS) {
fast = true;
if (!sii->regs[coreidx]) {
sii->regs[coreidx] = REG_MAP(sii->coresba[coreidx],
SI_CORE_SIZE);
}
r = (u32 *) ((unsigned char *) sii->regs[coreidx] + regoff);
} else if (sih->bustype == PCI_BUS) {
if ((sii->coreid[coreidx] == CC_CORE_ID) && SI_FAST(sii)) {
fast = true;
r = (u32 *) ((char *)sii->curmap +
PCI_16KB0_CCREGS_OFFSET + regoff);
} else if (sii->pub.buscoreidx == coreidx) {
fast = true;
if (SI_FAST(sii))
r = (u32 *) ((char *)sii->curmap +
PCI_16KB0_PCIREGS_OFFSET +
regoff);
else
r = (u32 *) ((char *)sii->curmap +
((regoff >= SBCONFIGOFF) ?
PCI_BAR0_PCISBR_OFFSET :
PCI_BAR0_PCIREGS_OFFSET) +
regoff);
}
}
if (!fast) {
INTR_OFF(sii, intr_val);
origidx = ai_coreidx(&sii->pub);
r = (u32 *) ((unsigned char *) ai_setcoreidx(&sii->pub, coreidx)
+ regoff);
}
if (mask || val) {
w = (R_REG(r) & ~mask) | val;
W_REG(r, w);
}
w = R_REG(r);
if (!fast) {
if (origidx != coreidx)
ai_setcoreidx(&sii->pub, origidx);
INTR_RESTORE(sii, intr_val);
}
return w;
}
void ai_core_disable(si_t *sih, u32 bits)
{
si_info_t *sii;
u32 dummy;
aidmp_t *ai;
sii = SI_INFO(sih);
ai = sii->curwrap;
if (R_REG(&ai->resetctrl) & AIRC_RESET)
return;
W_REG(&ai->ioctrl, bits);
dummy = R_REG(&ai->ioctrl);
udelay(10);
W_REG(&ai->resetctrl, AIRC_RESET);
udelay(1);
}
void ai_core_reset(si_t *sih, u32 bits, u32 resetbits)
{
si_info_t *sii;
aidmp_t *ai;
u32 dummy;
sii = SI_INFO(sih);
ai = sii->curwrap;
ai_core_disable(sih, (bits | resetbits));
W_REG(&ai->ioctrl, (bits | SICF_FGC | SICF_CLOCK_EN));
dummy = R_REG(&ai->ioctrl);
W_REG(&ai->resetctrl, 0);
udelay(1);
W_REG(&ai->ioctrl, (bits | SICF_CLOCK_EN));
dummy = R_REG(&ai->ioctrl);
udelay(1);
}
static uint ai_slowclk_src(si_info_t *sii)
{
chipcregs_t *cc;
u32 val;
if (sii->pub.ccrev < 6) {
if (sii->pub.bustype == PCI_BUS) {
pci_read_config_dword(sii->pbus, PCI_GPIO_OUT,
&val);
if (val & PCI_CFG_GPIO_SCS)
return SCC_SS_PCI;
}
return SCC_SS_XTAL;
} else if (sii->pub.ccrev < 10) {
cc = (chipcregs_t *) ai_setcoreidx(&sii->pub, sii->curidx);
return R_REG(&cc->slow_clk_ctl) & SCC_SS_MASK;
} else
return SCC_SS_XTAL;
}
static uint ai_slowclk_freq(si_info_t *sii, bool max_freq, chipcregs_t *cc)
{
u32 slowclk;
uint div;
slowclk = ai_slowclk_src(sii);
if (sii->pub.ccrev < 6) {
if (slowclk == SCC_SS_PCI)
return max_freq ? (PCIMAXFREQ / 64)
: (PCIMINFREQ / 64);
else
return max_freq ? (XTALMAXFREQ / 32)
: (XTALMINFREQ / 32);
} else if (sii->pub.ccrev < 10) {
div = 4 *
(((R_REG(&cc->slow_clk_ctl) & SCC_CD_MASK) >>
SCC_CD_SHIFT) + 1);
if (slowclk == SCC_SS_LPO)
return max_freq ? LPOMAXFREQ : LPOMINFREQ;
else if (slowclk == SCC_SS_XTAL)
return max_freq ? (XTALMAXFREQ / div)
: (XTALMINFREQ / div);
else if (slowclk == SCC_SS_PCI)
return max_freq ? (PCIMAXFREQ / div)
: (PCIMINFREQ / div);
} else {
div = R_REG(&cc->system_clk_ctl) >> SYCC_CD_SHIFT;
div = 4 * (div + 1);
return max_freq ? XTALMAXFREQ : (XTALMINFREQ / div);
}
return 0;
}
static void ai_clkctl_setdelay(si_info_t *sii, void *chipcregs)
{
chipcregs_t *cc = (chipcregs_t *) chipcregs;
uint slowmaxfreq, pll_delay, slowclk;
uint pll_on_delay, fref_sel_delay;
pll_delay = PLL_DELAY;
slowclk = ai_slowclk_src(sii);
if (slowclk != SCC_SS_XTAL)
pll_delay += XTAL_ON_DELAY;
slowmaxfreq =
ai_slowclk_freq(sii, (sii->pub.ccrev >= 10) ? false : true, cc);
pll_on_delay = ((slowmaxfreq * pll_delay) + 999999) / 1000000;
fref_sel_delay = ((slowmaxfreq * FREF_DELAY) + 999999) / 1000000;
W_REG(&cc->pll_on_delay, pll_on_delay);
W_REG(&cc->fref_sel_delay, fref_sel_delay);
}
void ai_clkctl_init(si_t *sih)
{
si_info_t *sii;
uint origidx = 0;
chipcregs_t *cc;
bool fast;
if (!CCCTL_ENAB(sih))
return;
sii = SI_INFO(sih);
fast = SI_FAST(sii);
if (!fast) {
origidx = sii->curidx;
cc = (chipcregs_t *) ai_setcore(sih, CC_CORE_ID, 0);
if (cc == NULL)
return;
} else {
cc = (chipcregs_t *) CCREGS_FAST(sii);
if (cc == NULL)
return;
}
if (sih->ccrev >= 10)
SET_REG(&cc->system_clk_ctl, SYCC_CD_MASK,
(ILP_DIV_1MHZ << SYCC_CD_SHIFT));
ai_clkctl_setdelay(sii, (void *)cc);
if (!fast)
ai_setcoreidx(sih, origidx);
}
u16 ai_clkctl_fast_pwrup_delay(si_t *sih)
{
si_info_t *sii;
uint origidx = 0;
chipcregs_t *cc;
uint slowminfreq;
u16 fpdelay;
uint intr_val = 0;
bool fast;
sii = SI_INFO(sih);
if (PMUCTL_ENAB(sih)) {
INTR_OFF(sii, intr_val);
fpdelay = si_pmu_fast_pwrup_delay(sih);
INTR_RESTORE(sii, intr_val);
return fpdelay;
}
if (!CCCTL_ENAB(sih))
return 0;
fast = SI_FAST(sii);
fpdelay = 0;
if (!fast) {
origidx = sii->curidx;
INTR_OFF(sii, intr_val);
cc = (chipcregs_t *) ai_setcore(sih, CC_CORE_ID, 0);
if (cc == NULL)
goto done;
} else {
cc = (chipcregs_t *) CCREGS_FAST(sii);
if (cc == NULL)
goto done;
}
slowminfreq = ai_slowclk_freq(sii, false, cc);
fpdelay = (((R_REG(&cc->pll_on_delay) + 2) * 1000000) +
(slowminfreq - 1)) / slowminfreq;
done:
if (!fast) {
ai_setcoreidx(sih, origidx);
INTR_RESTORE(sii, intr_val);
}
return fpdelay;
}
int ai_clkctl_xtal(si_t *sih, uint what, bool on)
{
si_info_t *sii;
u32 in, out, outen;
sii = SI_INFO(sih);
switch (sih->bustype) {
case PCI_BUS:
if (PCIE(sii))
return -1;
pci_read_config_dword(sii->pbus, PCI_GPIO_IN, &in);
pci_read_config_dword(sii->pbus, PCI_GPIO_OUT, &out);
pci_read_config_dword(sii->pbus, PCI_GPIO_OUTEN, &outen);
if (on && (in & PCI_CFG_GPIO_XTAL))
return 0;
if (what & XTAL)
outen |= PCI_CFG_GPIO_XTAL;
if (what & PLL)
outen |= PCI_CFG_GPIO_PLL;
if (on) {
if (what & XTAL) {
out |= PCI_CFG_GPIO_XTAL;
if (what & PLL)
out |= PCI_CFG_GPIO_PLL;
pci_write_config_dword(sii->pbus,
PCI_GPIO_OUT, out);
pci_write_config_dword(sii->pbus,
PCI_GPIO_OUTEN, outen);
udelay(XTAL_ON_DELAY);
}
if (what & PLL) {
out &= ~PCI_CFG_GPIO_PLL;
pci_write_config_dword(sii->pbus,
PCI_GPIO_OUT, out);
mdelay(2);
}
} else {
if (what & XTAL)
out &= ~PCI_CFG_GPIO_XTAL;
if (what & PLL)
out |= PCI_CFG_GPIO_PLL;
pci_write_config_dword(sii->pbus,
PCI_GPIO_OUT, out);
pci_write_config_dword(sii->pbus,
PCI_GPIO_OUTEN, outen);
}
default:
return -1;
}
return 0;
}
bool ai_clkctl_cc(si_t *sih, uint mode)
{
si_info_t *sii;
sii = SI_INFO(sih);
if (sih->ccrev < 6)
return false;
if (PCI_FORCEHT(sii))
return mode == CLK_FAST;
return _ai_clkctl_cc(sii, mode);
}
static bool _ai_clkctl_cc(si_info_t *sii, uint mode)
{
uint origidx = 0;
chipcregs_t *cc;
u32 scc;
uint intr_val = 0;
bool fast = SI_FAST(sii);
if (sii->pub.ccrev < 6)
return false;
if (!fast) {
INTR_OFF(sii, intr_val);
origidx = sii->curidx;
if ((sii->pub.bustype == SI_BUS) &&
ai_setcore(&sii->pub, MIPS33_CORE_ID, 0) &&
(ai_corerev(&sii->pub) <= 7) && (sii->pub.ccrev >= 10))
goto done;
cc = (chipcregs_t *) ai_setcore(&sii->pub, CC_CORE_ID, 0);
} else {
cc = (chipcregs_t *) CCREGS_FAST(sii);
if (cc == NULL)
goto done;
}
if (!CCCTL_ENAB(&sii->pub) && (sii->pub.ccrev < 20))
goto done;
switch (mode) {
case CLK_FAST:
if (sii->pub.ccrev < 10) {
ai_clkctl_xtal(&sii->pub, XTAL, ON);
SET_REG(&cc->slow_clk_ctl,
(SCC_XC | SCC_FS | SCC_IP), SCC_IP);
} else if (sii->pub.ccrev < 20) {
OR_REG(&cc->system_clk_ctl, SYCC_HR);
} else {
OR_REG(&cc->clk_ctl_st, CCS_FORCEHT);
}
if (PMUCTL_ENAB(&sii->pub)) {
u32 htavail = CCS_HTAVAIL;
SPINWAIT(((R_REG(&cc->clk_ctl_st) & htavail)
== 0), PMU_MAX_TRANSITION_DLY);
} else {
udelay(PLL_DELAY);
}
break;
case CLK_DYNAMIC:
if (sii->pub.ccrev < 10) {
scc = R_REG(&cc->slow_clk_ctl);
scc &= ~(SCC_FS | SCC_IP | SCC_XC);
if ((scc & SCC_SS_MASK) != SCC_SS_XTAL)
scc |= SCC_XC;
W_REG(&cc->slow_clk_ctl, scc);
if (scc & SCC_XC)
ai_clkctl_xtal(&sii->pub, XTAL, OFF);
} else if (sii->pub.ccrev < 20) {
AND_REG(&cc->system_clk_ctl, ~SYCC_HR);
} else {
AND_REG(&cc->clk_ctl_st, ~CCS_FORCEHT);
}
break;
default:
break;
}
done:
if (!fast) {
ai_setcoreidx(&sii->pub, origidx);
INTR_RESTORE(sii, intr_val);
}
return mode == CLK_FAST;
}
int ai_devpath(si_t *sih, char *path, int size)
{
int slen;
if (!path || size <= 0)
return -1;
switch (sih->bustype) {
case SI_BUS:
case JTAG_BUS:
slen = snprintf(path, (size_t) size, "sb/%u/", ai_coreidx(sih));
break;
case PCI_BUS:
slen = snprintf(path, (size_t) size, "pci/%u/%u/",
((struct pci_dev *)((SI_INFO(sih))->pbus))->bus->number,
PCI_SLOT(
((struct pci_dev *)((SI_INFO(sih))->pbus))->devfn));
break;
default:
slen = -1;
break;
}
if (slen < 0 || slen >= size) {
path[0] = '\0';
return -1;
}
return 0;
}
char *ai_getdevpathvar(si_t *sih, const char *name)
{
char varname[SI_DEVPATH_BUFSZ + 32];
ai_devpathvar(sih, varname, sizeof(varname), name);
return getvar(NULL, varname);
}
int ai_getdevpathintvar(si_t *sih, const char *name)
{
#if defined(BCMBUSTYPE) && (BCMBUSTYPE == SI_BUS)
return getintvar(NULL, name);
#else
char varname[SI_DEVPATH_BUFSZ + 32];
ai_devpathvar(sih, varname, sizeof(varname), name);
return getintvar(NULL, varname);
#endif
}
char *ai_getnvramflvar(si_t *sih, const char *name)
{
return getvar(NULL, name);
}
static char *ai_devpathvar(si_t *sih, char *var, int len, const char *name)
{
uint path_len;
if (!var || len <= 0)
return var;
if (ai_devpath(sih, var, len) == 0) {
path_len = strlen(var);
if (strlen(name) + 1 > (uint) (len - path_len))
var[0] = '\0';
else
strncpy(var + path_len, name, len - path_len - 1);
}
return var;
}
static __used bool ai_ispcie(si_info_t *sii)
{
u8 cap_ptr;
if (sii->pub.bustype != PCI_BUS)
return false;
cap_ptr =
pcicore_find_pci_capability(sii->pbus, PCI_CAP_ID_EXP, NULL,
NULL);
if (!cap_ptr)
return false;
return true;
}
bool ai_pci_war16165(si_t *sih)
{
si_info_t *sii;
sii = SI_INFO(sih);
return PCI(sii) && (sih->buscorerev <= 10);
}
void ai_pci_up(si_t *sih)
{
si_info_t *sii;
sii = SI_INFO(sih);
if (sih->bustype != PCI_BUS)
return;
if (PCI_FORCEHT(sii))
_ai_clkctl_cc(sii, CLK_FAST);
if (PCIE(sii))
pcicore_up(sii->pch, SI_PCIUP);
}
void ai_pci_sleep(si_t *sih)
{
si_info_t *sii;
sii = SI_INFO(sih);
pcicore_sleep(sii->pch);
}
void ai_pci_down(si_t *sih)
{
si_info_t *sii;
sii = SI_INFO(sih);
if (sih->bustype != PCI_BUS)
return;
if (PCI_FORCEHT(sii))
_ai_clkctl_cc(sii, CLK_DYNAMIC);
pcicore_down(sii->pch, SI_PCIDOWN);
}
void ai_pci_setup(si_t *sih, uint coremask)
{
si_info_t *sii;
struct sbpciregs *pciregs = NULL;
u32 siflag = 0, w;
uint idx = 0;
sii = SI_INFO(sih);
if (sii->pub.bustype != PCI_BUS)
return;
if (PCI(sii)) {
idx = sii->curidx;
siflag = ai_flag(sih);
pciregs = ai_setcoreidx(sih, sii->pub.buscoreidx);
}
if (PCIE(sii) || (PCI(sii) && ((sii->pub.buscorerev) >= 6))) {
pci_read_config_dword(sii->pbus, PCI_INT_MASK, &w);
w |= (coremask << PCI_SBIM_SHIFT);
pci_write_config_dword(sii->pbus, PCI_INT_MASK, w);
} else {
ai_setint(sih, siflag);
}
if (PCI(sii)) {
OR_REG(&pciregs->sbtopci2,
(SBTOPCI_PREF | SBTOPCI_BURST));
if (sii->pub.buscorerev >= 11) {
OR_REG(&pciregs->sbtopci2,
SBTOPCI_RC_READMULTI);
w = R_REG(&pciregs->clkrun);
W_REG(&pciregs->clkrun,
(w | PCI_CLKRUN_DSBL));
w = R_REG(&pciregs->clkrun);
}
ai_setcoreidx(sih, idx);
}
}
int ai_pci_fixcfg(si_t *sih)
{
uint origidx, pciidx;
struct sbpciregs *pciregs = NULL;
sbpcieregs_t *pcieregs = NULL;
void *regs = NULL;
u16 val16, *reg16 = NULL;
si_info_t *sii = SI_INFO(sih);
origidx = ai_coreidx(&sii->pub);
if (sii->pub.buscoretype == PCIE_CORE_ID) {
pcieregs = ai_setcore(&sii->pub, PCIE_CORE_ID, 0);
regs = pcieregs;
reg16 = &pcieregs->sprom[SRSH_PI_OFFSET];
} else if (sii->pub.buscoretype == PCI_CORE_ID) {
pciregs = ai_setcore(&sii->pub, PCI_CORE_ID, 0);
regs = pciregs;
reg16 = &pciregs->sprom[SRSH_PI_OFFSET];
}
pciidx = ai_coreidx(&sii->pub);
val16 = R_REG(reg16);
if (((val16 & SRSH_PI_MASK) >> SRSH_PI_SHIFT) != (u16) pciidx) {
val16 =
(u16) (pciidx << SRSH_PI_SHIFT) | (val16 &
~SRSH_PI_MASK);
W_REG(reg16, val16);
}
ai_setcoreidx(&sii->pub, origidx);
pcicore_hwup(sii->pch);
return 0;
}
u32 ai_gpiocontrol(si_t *sih, u32 mask, u32 val, u8 priority)
{
uint regoff;
regoff = 0;
if ((priority != GPIO_HI_PRIORITY) &&
(sih->bustype == SI_BUS) && (val || mask)) {
mask = priority ? (ai_gpioreservation & mask) :
((ai_gpioreservation | mask) & ~(ai_gpioreservation));
val &= mask;
}
regoff = offsetof(chipcregs_t, gpiocontrol);
return ai_corereg(sih, SI_CC_IDX, regoff, mask, val);
}
void ai_chipcontrl_epa4331(si_t *sih, bool on)
{
si_info_t *sii;
chipcregs_t *cc;
uint origidx;
u32 val;
sii = SI_INFO(sih);
origidx = ai_coreidx(sih);
cc = (chipcregs_t *) ai_setcore(sih, CC_CORE_ID, 0);
val = R_REG(&cc->chipcontrol);
if (on) {
if (sih->chippkg == 9 || sih->chippkg == 0xb) {
W_REG(&cc->chipcontrol, val |
(CCTRL4331_EXTPA_EN |
CCTRL4331_EXTPA_ON_GPIO2_5));
} else {
W_REG(&cc->chipcontrol,
val | (CCTRL4331_EXTPA_EN));
}
} else {
val &= ~(CCTRL4331_EXTPA_EN | CCTRL4331_EXTPA_ON_GPIO2_5);
W_REG(&cc->chipcontrol, val);
}
ai_setcoreidx(sih, origidx);
}
void ai_epa_4313war(si_t *sih)
{
si_info_t *sii;
chipcregs_t *cc;
uint origidx;
sii = SI_INFO(sih);
origidx = ai_coreidx(sih);
cc = (chipcregs_t *) ai_setcore(sih, CC_CORE_ID, 0);
W_REG(&cc->gpiocontrol,
R_REG(&cc->gpiocontrol) | GPIO_CTRL_EPA_EN_MASK);
ai_setcoreidx(sih, origidx);
}
bool ai_deviceremoved(si_t *sih)
{
u32 w;
si_info_t *sii;
sii = SI_INFO(sih);
switch (sih->bustype) {
case PCI_BUS:
pci_read_config_dword(sii->pbus, PCI_VENDOR_ID, &w);
if ((w & 0xFFFF) != PCI_VENDOR_ID_BROADCOM)
return true;
break;
}
return false;
}
bool ai_is_sprom_available(si_t *sih)
{
if (sih->ccrev >= 31) {
si_info_t *sii;
uint origidx;
chipcregs_t *cc;
u32 sromctrl;
if ((sih->cccaps & CC_CAP_SROM) == 0)
return false;
sii = SI_INFO(sih);
origidx = sii->curidx;
cc = ai_setcoreidx(sih, SI_CC_IDX);
sromctrl = R_REG(&cc->sromcontrol);
ai_setcoreidx(sih, origidx);
return sromctrl & SRC_PRESENT;
}
switch (sih->chip) {
case BCM4329_CHIP_ID:
return (sih->chipst & CST4329_SPROM_SEL) != 0;
case BCM4319_CHIP_ID:
return (sih->chipst & CST4319_SPROM_SEL) != 0;
case BCM4336_CHIP_ID:
return (sih->chipst & CST4336_SPROM_PRESENT) != 0;
case BCM4330_CHIP_ID:
return (sih->chipst & CST4330_SPROM_PRESENT) != 0;
case BCM4313_CHIP_ID:
return (sih->chipst & CST4313_SPROM_PRESENT) != 0;
case BCM4331_CHIP_ID:
return (sih->chipst & CST4331_SPROM_PRESENT) != 0;
default:
return true;
}
}
bool ai_is_otp_disabled(si_t *sih)
{
switch (sih->chip) {
case BCM4329_CHIP_ID:
return (sih->chipst & CST4329_SPROM_OTP_SEL_MASK) ==
CST4329_OTP_PWRDN;
case BCM4319_CHIP_ID:
return (sih->chipst & CST4319_SPROM_OTP_SEL_MASK) ==
CST4319_OTP_PWRDN;
case BCM4336_CHIP_ID:
return (sih->chipst & CST4336_OTP_PRESENT) == 0;
case BCM4330_CHIP_ID:
return (sih->chipst & CST4330_OTP_PRESENT) == 0;
case BCM4313_CHIP_ID:
return (sih->chipst & CST4313_OTP_PRESENT) == 0;
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM43421_CHIP_ID:
case BCM43235_CHIP_ID:
case BCM43236_CHIP_ID:
case BCM43238_CHIP_ID:
case BCM4331_CHIP_ID:
default:
return false;
}
}
bool ai_is_otp_powered(si_t *sih)
{
if (PMUCTL_ENAB(sih))
return si_pmu_is_otp_powered(sih);
return true;
}
void ai_otp_power(si_t *sih, bool on)
{
if (PMUCTL_ENAB(sih))
si_pmu_otp_power(sih, on);
udelay(1000);
}
