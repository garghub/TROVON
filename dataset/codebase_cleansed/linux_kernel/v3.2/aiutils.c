static u32
get_erom_ent(struct si_pub *sih, u32 __iomem **eromptr, u32 mask, u32 match)
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
return ent;
}
static u32
get_asd(struct si_pub *sih, u32 __iomem **eromptr, uint sp, uint ad, uint st,
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
return asd;
}
static void ai_hwfixup(struct si_info *sii)
{
}
static void ai_scan(struct si_pub *sih, struct chipcregs __iomem *cc)
{
struct si_info *sii = (struct si_info *)sih;
u32 erombase;
u32 __iomem *eromptr, *eromlim;
void __iomem *regs = cc;
erombase = R_REG(&cc->eromptr);
sii->curwrap = (void *)((unsigned long)cc + SI_CORE_SIZE);
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN, erombase);
eromptr = regs;
eromlim = eromptr + (ER_REMAPCONTROL / sizeof(u32));
while (eromptr < eromlim) {
u32 cia, cib, cid, mfg, crev, nmw, nsw, nmp, nsp;
u32 mpd, asd, addrl, addrh, sizel, sizeh;
u32 __iomem *base;
uint i, j, idx;
bool br;
br = false;
cia = get_erom_ent(sih, &eromptr, ER_TAG, ER_CI);
if (cia == (ER_END | ER_VALID)) {
ai_hwfixup(sii);
return;
}
base = eromptr - 1;
cib = get_erom_ent(sih, &eromptr, 0, 0);
if ((cib & ER_TAG) != ER_CI) {
goto error;
}
cid = (cia & CIA_CID_MASK) >> CIA_CID_SHIFT;
mfg = (cia & CIA_MFG_MASK) >> CIA_MFG_SHIFT;
crev = (cib & CIB_REV_MASK) >> CIB_REV_SHIFT;
nmw = (cib & CIB_NMW_MASK) >> CIB_NMW_SHIFT;
nsw = (cib & CIB_NSW_MASK) >> CIB_NSW_SHIFT;
nmp = (cib & CIB_NMP_MASK) >> CIB_NMP_SHIFT;
nsp = (cib & CIB_NSP_MASK) >> CIB_NSP_SHIFT;
if (((mfg == MFGID_ARM) && (cid == DEF_AI_COMP)) || (nsp == 0))
continue;
if ((nmw + nsw == 0)) {
if (cid == OOB_ROUTER_CORE_ID) {
asd = get_asd(sih, &eromptr, 0, 0, AD_ST_SLAVE,
&addrl, &addrh, &sizel, &sizeh);
if (asd != 0)
sii->oob_router = addrl;
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
goto error;
}
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
goto error;
}
}
for (i = 0; i < nmw; i++) {
asd =
get_asd(sih, &eromptr, i, 0, AD_ST_MWRAP, &addrl,
&addrh, &sizel, &sizeh);
if (asd == 0) {
goto error;
}
if ((sizeh != 0) || (sizel != SI_CORE_SIZE)) {
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
goto error;
}
if ((sizeh != 0) || (sizel != SI_CORE_SIZE)) {
goto error;
}
if ((nmw == 0) && (i == 0))
sii->wrapba[idx] = addrl;
}
if (br)
continue;
sii->numcores++;
}
error:
sii->numcores = 0;
return;
}
void __iomem *ai_setcoreidx(struct si_pub *sih, uint coreidx)
{
struct si_info *sii = (struct si_info *)sih;
u32 addr = sii->coresba[coreidx];
u32 wrap = sii->wrapba[coreidx];
if (coreidx >= sii->numcores)
return NULL;
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN, addr);
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN2, wrap);
sii->curidx = coreidx;
return sii->curmap;
}
int ai_numaddrspaces(struct si_pub *sih)
{
return 2;
}
u32 ai_addrspace(struct si_pub *sih, uint asidx)
{
struct si_info *sii;
uint cidx;
sii = (struct si_info *)sih;
cidx = sii->curidx;
if (asidx == 0)
return sii->coresba[cidx];
else if (asidx == 1)
return sii->coresba2[cidx];
else {
return 0;
}
}
u32 ai_addrspacesize(struct si_pub *sih, uint asidx)
{
struct si_info *sii;
uint cidx;
sii = (struct si_info *)sih;
cidx = sii->curidx;
if (asidx == 0)
return sii->coresba_size[cidx];
else if (asidx == 1)
return sii->coresba2_size[cidx];
else {
return 0;
}
}
uint ai_flag(struct si_pub *sih)
{
struct si_info *sii;
struct aidmp *ai;
sii = (struct si_info *)sih;
ai = sii->curwrap;
return R_REG(&ai->oobselouta30) & 0x1f;
}
void ai_setint(struct si_pub *sih, int siflag)
{
}
uint ai_corevendor(struct si_pub *sih)
{
struct si_info *sii;
u32 cia;
sii = (struct si_info *)sih;
cia = sii->cia[sii->curidx];
return (cia & CIA_MFG_MASK) >> CIA_MFG_SHIFT;
}
uint ai_corerev(struct si_pub *sih)
{
struct si_info *sii;
u32 cib;
sii = (struct si_info *)sih;
cib = sii->cib[sii->curidx];
return (cib & CIB_REV_MASK) >> CIB_REV_SHIFT;
}
bool ai_iscoreup(struct si_pub *sih)
{
struct si_info *sii;
struct aidmp *ai;
sii = (struct si_info *)sih;
ai = sii->curwrap;
return (((R_REG(&ai->ioctrl) & (SICF_FGC | SICF_CLOCK_EN)) ==
SICF_CLOCK_EN)
&& ((R_REG(&ai->resetctrl) & AIRC_RESET) == 0));
}
void ai_core_cflags_wo(struct si_pub *sih, u32 mask, u32 val)
{
struct si_info *sii;
struct aidmp *ai;
u32 w;
sii = (struct si_info *)sih;
ai = sii->curwrap;
if (mask || val) {
w = ((R_REG(&ai->ioctrl) & ~mask) | val);
W_REG(&ai->ioctrl, w);
}
}
u32 ai_core_cflags(struct si_pub *sih, u32 mask, u32 val)
{
struct si_info *sii;
struct aidmp *ai;
u32 w;
sii = (struct si_info *)sih;
ai = sii->curwrap;
if (mask || val) {
w = ((R_REG(&ai->ioctrl) & ~mask) | val);
W_REG(&ai->ioctrl, w);
}
return R_REG(&ai->ioctrl);
}
static bool ai_ispcie(struct si_info *sii)
{
u8 cap_ptr;
cap_ptr =
pcicore_find_pci_capability(sii->pbus, PCI_CAP_ID_EXP, NULL,
NULL);
if (!cap_ptr)
return false;
return true;
}
static bool ai_buscore_prep(struct si_info *sii)
{
if (!ai_ispcie(sii))
ai_clkctl_xtal(&sii->pub, XTAL | PLL, ON);
return true;
}
u32 ai_core_sflags(struct si_pub *sih, u32 mask, u32 val)
{
struct si_info *sii;
struct aidmp *ai;
u32 w;
sii = (struct si_info *)sih;
ai = sii->curwrap;
if (mask || val) {
w = ((R_REG(&ai->iostatus) & ~mask) | val);
W_REG(&ai->iostatus, w);
}
return R_REG(&ai->iostatus);
}
static bool
ai_buscore_setup(struct si_info *sii, u32 savewin, uint *origidx)
{
bool pci, pcie;
uint i;
uint pciidx, pcieidx, pcirev, pcierev;
struct chipcregs __iomem *cc;
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
if (cid == PCI_CORE_ID) {
pciidx = i;
pcirev = crev;
pci = true;
} else if (cid == PCIE_CORE_ID) {
pcieidx = i;
pcierev = crev;
pcie = true;
}
if ((savewin && (savewin == sii->coresba[i])) ||
(cc == sii->regs[i]))
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
if (SI_FAST(sii)) {
if (!sii->pch) {
sii->pch = pcicore_init(&sii->pub, sii->pbus,
(__iomem void *)PCIEREGS(sii));
if (sii->pch == NULL)
return false;
}
}
if (ai_pci_fixcfg(&sii->pub)) {
return false;
}
ai_setcoreidx(&sii->pub, *origidx);
return true;
}
static __used void ai_nvram_process(struct si_info *sii)
{
uint w = 0;
pci_read_config_dword(sii->pbus, PCI_SUBSYSTEM_VENDOR_ID, &w);
sii->pub.boardvendor = w & 0xffff;
sii->pub.boardtype = (w >> 16) & 0xffff;
sii->pub.boardflags = getintvar(&sii->pub, BRCMS_SROM_BOARDFLAGS);
}
static struct si_info *ai_doattach(struct si_info *sii,
void __iomem *regs, struct pci_dev *pbus)
{
struct si_pub *sih = &sii->pub;
u32 w, savewin;
struct chipcregs __iomem *cc;
uint socitype;
uint origidx;
memset((unsigned char *) sii, 0, sizeof(struct si_info));
savewin = 0;
sih->buscoreidx = BADIDX;
sii->curmap = regs;
sii->pbus = pbus;
pci_read_config_dword(sii->pbus, PCI_BAR0_WIN, &savewin);
if (!GOODCOREADDR(savewin, SI_ENUM_BASE))
savewin = SI_ENUM_BASE;
pci_write_config_dword(sii->pbus, PCI_BAR0_WIN,
SI_ENUM_BASE);
cc = (struct chipcregs __iomem *) regs;
if (!ai_buscore_prep(sii))
return NULL;
w = R_REG(&cc->chipid);
socitype = (w & CID_TYPE_MASK) >> CID_TYPE_SHIFT;
sih->chip = w & CID_ID_MASK;
sih->chiprev = (w & CID_REV_MASK) >> CID_REV_SHIFT;
sih->chippkg = (w & CID_PKG_MASK) >> CID_PKG_SHIFT;
sih->issim = false;
if (socitype == SOCI_AI) {
SI_MSG(("Found chip type AI (0x%08x)\n", w));
ai_scan(&sii->pub, cc);
} else {
return NULL;
}
if (sii->numcores == 0)
return NULL;
origidx = SI_CC_IDX;
if (!ai_buscore_setup(sii, savewin, &origidx))
goto exit;
if (srom_var_init(&sii->pub, cc))
goto exit;
ai_nvram_process(sii);
cc = (struct chipcregs __iomem *) ai_setcore(sih, CC_CORE_ID, 0);
W_REG(&cc->gpiopullup, 0);
W_REG(&cc->gpiopulldown, 0);
ai_setcoreidx(sih, origidx);
if (sih->cccaps & CC_CAP_PMU) {
u32 xtalfreq;
si_pmu_init(sih);
si_pmu_chip_init(sih);
xtalfreq = si_pmu_measure_alpclk(sih);
si_pmu_pll_init(sih, xtalfreq);
si_pmu_res_init(sih);
si_pmu_swreg_init(sih);
}
w = getintvar(sih, BRCMS_SROM_LEDDC);
if (w == 0)
w = DEFAULT_GPIOTIMERVAL;
ai_corereg(sih, SI_CC_IDX, offsetof(struct chipcregs, gpiotimerval),
~0, w);
if (PCIE(sii))
pcicore_attach(sii->pch, SI_DOATTACH);
if (sih->chip == BCM43224_CHIP_ID) {
if (sih->chiprev == 0) {
SI_MSG(("Applying 43224A0 WARs\n"));
ai_corereg(sih, SI_CC_IDX,
offsetof(struct chipcregs, chipcontrol),
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
return sii;
exit:
if (sii->pch)
pcicore_deinit(sii->pch);
sii->pch = NULL;
return NULL;
}
struct si_pub *
ai_attach(void __iomem *regs, struct pci_dev *sdh)
{
struct si_info *sii;
sii = kmalloc(sizeof(struct si_info), GFP_ATOMIC);
if (sii == NULL)
return NULL;
if (ai_doattach(sii, regs, sdh) == NULL) {
kfree(sii);
return NULL;
}
return (struct si_pub *) sii;
}
void ai_detach(struct si_pub *sih)
{
struct si_info *sii;
struct si_pub *si_local = NULL;
memcpy(&si_local, &sih, sizeof(struct si_pub **));
sii = (struct si_info *)sih;
if (sii == NULL)
return;
if (sii->pch)
pcicore_deinit(sii->pch);
sii->pch = NULL;
srom_free_vars(sih);
kfree(sii);
}
void
ai_register_intr_callback(struct si_pub *sih, void *intrsoff_fn,
void *intrsrestore_fn,
void *intrsenabled_fn, void *intr_arg)
{
struct si_info *sii;
sii = (struct si_info *)sih;
sii->intr_arg = intr_arg;
sii->intrsoff_fn = (u32 (*)(void *)) intrsoff_fn;
sii->intrsrestore_fn = (void (*) (void *, u32)) intrsrestore_fn;
sii->intrsenabled_fn = (bool (*)(void *)) intrsenabled_fn;
sii->dev_coreid = sii->coreid[sii->curidx];
}
void ai_deregister_intr_callback(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
sii->intrsoff_fn = NULL;
}
uint ai_coreid(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
return sii->coreid[sii->curidx];
}
uint ai_coreidx(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
return sii->curidx;
}
bool ai_backplane64(struct si_pub *sih)
{
return (sih->cccaps & CC_CAP_BKPLN64) != 0;
}
uint ai_findcoreidx(struct si_pub *sih, uint coreid, uint coreunit)
{
struct si_info *sii;
uint found;
uint i;
sii = (struct si_info *)sih;
found = 0;
for (i = 0; i < sii->numcores; i++)
if (sii->coreid[i] == coreid) {
if (found == coreunit)
return i;
found++;
}
return BADIDX;
}
void __iomem *ai_setcore(struct si_pub *sih, uint coreid, uint coreunit)
{
uint idx;
idx = ai_findcoreidx(sih, coreid, coreunit);
if (idx >= SI_MAXCORES)
return NULL;
return ai_setcoreidx(sih, idx);
}
void __iomem *ai_switch_core(struct si_pub *sih, uint coreid, uint *origidx,
uint *intr_val)
{
void __iomem *cc;
struct si_info *sii;
sii = (struct si_info *)sih;
if (SI_FAST(sii)) {
*origidx = coreid;
if (coreid == CC_CORE_ID)
return CCREGS_FAST(sii);
else if (coreid == sih->buscoretype)
return PCIEREGS(sii);
}
INTR_OFF(sii, *intr_val);
*origidx = sii->curidx;
cc = ai_setcore(sih, coreid, 0);
return cc;
}
void ai_restore_core(struct si_pub *sih, uint coreid, uint intr_val)
{
struct si_info *sii;
sii = (struct si_info *)sih;
if (SI_FAST(sii)
&& ((coreid == CC_CORE_ID) || (coreid == sih->buscoretype)))
return;
ai_setcoreidx(sih, coreid);
INTR_RESTORE(sii, intr_val);
}
void ai_write_wrapperreg(struct si_pub *sih, u32 offset, u32 val)
{
struct si_info *sii = (struct si_info *)sih;
u32 *w = (u32 *) sii->curwrap;
W_REG(w + (offset / 4), val);
return;
}
uint ai_corereg(struct si_pub *sih, uint coreidx, uint regoff, uint mask,
uint val)
{
uint origidx = 0;
u32 __iomem *r = NULL;
uint w;
uint intr_val = 0;
bool fast = false;
struct si_info *sii;
sii = (struct si_info *)sih;
if (coreidx >= SI_MAXCORES)
return 0;
if ((sii->coreid[coreidx] == CC_CORE_ID) && SI_FAST(sii)) {
fast = true;
r = (u32 __iomem *)((__iomem char *)sii->curmap +
PCI_16KB0_CCREGS_OFFSET + regoff);
} else if (sii->pub.buscoreidx == coreidx) {
fast = true;
if (SI_FAST(sii))
r = (u32 __iomem *)((__iomem char *)sii->curmap +
PCI_16KB0_PCIREGS_OFFSET + regoff);
else
r = (u32 __iomem *)((__iomem char *)sii->curmap +
((regoff >= SBCONFIGOFF) ?
PCI_BAR0_PCISBR_OFFSET :
PCI_BAR0_PCIREGS_OFFSET) + regoff);
}
if (!fast) {
INTR_OFF(sii, intr_val);
origidx = ai_coreidx(&sii->pub);
r = (u32 __iomem *) ((unsigned char __iomem *)
ai_setcoreidx(&sii->pub, coreidx) + regoff);
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
void ai_core_disable(struct si_pub *sih, u32 bits)
{
struct si_info *sii;
u32 dummy;
struct aidmp *ai;
sii = (struct si_info *)sih;
ai = sii->curwrap;
if (R_REG(&ai->resetctrl) & AIRC_RESET)
return;
W_REG(&ai->ioctrl, bits);
dummy = R_REG(&ai->ioctrl);
udelay(10);
W_REG(&ai->resetctrl, AIRC_RESET);
udelay(1);
}
void ai_core_reset(struct si_pub *sih, u32 bits, u32 resetbits)
{
struct si_info *sii;
struct aidmp *ai;
u32 dummy;
sii = (struct si_info *)sih;
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
static uint ai_slowclk_src(struct si_info *sii)
{
struct chipcregs __iomem *cc;
u32 val;
if (sii->pub.ccrev < 6) {
pci_read_config_dword(sii->pbus, PCI_GPIO_OUT,
&val);
if (val & PCI_CFG_GPIO_SCS)
return SCC_SS_PCI;
return SCC_SS_XTAL;
} else if (sii->pub.ccrev < 10) {
cc = (struct chipcregs __iomem *)
ai_setcoreidx(&sii->pub, sii->curidx);
return R_REG(&cc->slow_clk_ctl) & SCC_SS_MASK;
} else
return SCC_SS_XTAL;
}
static uint ai_slowclk_freq(struct si_info *sii, bool max_freq,
struct chipcregs __iomem *cc)
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
static void
ai_clkctl_setdelay(struct si_info *sii, struct chipcregs __iomem *cc)
{
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
void ai_clkctl_init(struct si_pub *sih)
{
struct si_info *sii;
uint origidx = 0;
struct chipcregs __iomem *cc;
bool fast;
if (!(sih->cccaps & CC_CAP_PWR_CTL))
return;
sii = (struct si_info *)sih;
fast = SI_FAST(sii);
if (!fast) {
origidx = sii->curidx;
cc = (struct chipcregs __iomem *)
ai_setcore(sih, CC_CORE_ID, 0);
if (cc == NULL)
return;
} else {
cc = (struct chipcregs __iomem *) CCREGS_FAST(sii);
if (cc == NULL)
return;
}
if (sih->ccrev >= 10)
SET_REG(&cc->system_clk_ctl, SYCC_CD_MASK,
(ILP_DIV_1MHZ << SYCC_CD_SHIFT));
ai_clkctl_setdelay(sii, cc);
if (!fast)
ai_setcoreidx(sih, origidx);
}
u16 ai_clkctl_fast_pwrup_delay(struct si_pub *sih)
{
struct si_info *sii;
uint origidx = 0;
struct chipcregs __iomem *cc;
uint slowminfreq;
u16 fpdelay;
uint intr_val = 0;
bool fast;
sii = (struct si_info *)sih;
if (sih->cccaps & CC_CAP_PMU) {
INTR_OFF(sii, intr_val);
fpdelay = si_pmu_fast_pwrup_delay(sih);
INTR_RESTORE(sii, intr_val);
return fpdelay;
}
if (!(sih->cccaps & CC_CAP_PWR_CTL))
return 0;
fast = SI_FAST(sii);
fpdelay = 0;
if (!fast) {
origidx = sii->curidx;
INTR_OFF(sii, intr_val);
cc = (struct chipcregs __iomem *)
ai_setcore(sih, CC_CORE_ID, 0);
if (cc == NULL)
goto done;
} else {
cc = (struct chipcregs __iomem *) CCREGS_FAST(sii);
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
int ai_clkctl_xtal(struct si_pub *sih, uint what, bool on)
{
struct si_info *sii;
u32 in, out, outen;
sii = (struct si_info *)sih;
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
return 0;
}
static bool _ai_clkctl_cc(struct si_info *sii, uint mode)
{
uint origidx = 0;
struct chipcregs __iomem *cc;
u32 scc;
uint intr_val = 0;
bool fast = SI_FAST(sii);
if (sii->pub.ccrev < 6)
return false;
if (!fast) {
INTR_OFF(sii, intr_val);
origidx = sii->curidx;
cc = (struct chipcregs __iomem *)
ai_setcore(&sii->pub, CC_CORE_ID, 0);
} else {
cc = (struct chipcregs __iomem *) CCREGS_FAST(sii);
if (cc == NULL)
goto done;
}
if (!(sii->pub.cccaps & CC_CAP_PWR_CTL) && (sii->pub.ccrev < 20))
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
if (sii->pub.cccaps & CC_CAP_PMU) {
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
bool ai_clkctl_cc(struct si_pub *sih, uint mode)
{
struct si_info *sii;
sii = (struct si_info *)sih;
if (sih->ccrev < 6)
return false;
if (PCI_FORCEHT(sii))
return mode == CLK_FAST;
return _ai_clkctl_cc(sii, mode);
}
int ai_devpath(struct si_pub *sih, char *path, int size)
{
int slen;
if (!path || size <= 0)
return -1;
slen = snprintf(path, (size_t) size, "pci/%u/%u/",
((struct si_info *)sih)->pbus->bus->number,
PCI_SLOT(((struct pci_dev *)
(((struct si_info *)(sih))->pbus))->devfn));
if (slen < 0 || slen >= size) {
path[0] = '\0';
return -1;
}
return 0;
}
void ai_pci_up(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
if (PCI_FORCEHT(sii))
_ai_clkctl_cc(sii, CLK_FAST);
if (PCIE(sii))
pcicore_up(sii->pch, SI_PCIUP);
}
void ai_pci_sleep(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
pcicore_sleep(sii->pch);
}
void ai_pci_down(struct si_pub *sih)
{
struct si_info *sii;
sii = (struct si_info *)sih;
if (PCI_FORCEHT(sii))
_ai_clkctl_cc(sii, CLK_DYNAMIC);
pcicore_down(sii->pch, SI_PCIDOWN);
}
void ai_pci_setup(struct si_pub *sih, uint coremask)
{
struct si_info *sii;
struct sbpciregs __iomem *regs = NULL;
u32 siflag = 0, w;
uint idx = 0;
sii = (struct si_info *)sih;
if (PCI(sii)) {
idx = sii->curidx;
siflag = ai_flag(sih);
regs = ai_setcoreidx(sih, sii->pub.buscoreidx);
}
if (PCIE(sii) || (PCI(sii) && ((sii->pub.buscorerev) >= 6))) {
pci_read_config_dword(sii->pbus, PCI_INT_MASK, &w);
w |= (coremask << PCI_SBIM_SHIFT);
pci_write_config_dword(sii->pbus, PCI_INT_MASK, w);
} else {
ai_setint(sih, siflag);
}
if (PCI(sii)) {
pcicore_pci_setup(sii->pch, regs);
ai_setcoreidx(sih, idx);
}
}
int ai_pci_fixcfg(struct si_pub *sih)
{
uint origidx;
void __iomem *regs = NULL;
struct si_info *sii = (struct si_info *)sih;
origidx = ai_coreidx(&sii->pub);
regs = ai_setcore(&sii->pub, sii->pub.buscoretype, 0);
if (sii->pub.buscoretype == PCIE_CORE_ID)
pcicore_fixcfg_pcie(sii->pch,
(struct sbpcieregs __iomem *)regs);
else if (sii->pub.buscoretype == PCI_CORE_ID)
pcicore_fixcfg_pci(sii->pch, (struct sbpciregs __iomem *)regs);
ai_setcoreidx(&sii->pub, origidx);
pcicore_hwup(sii->pch);
return 0;
}
u32 ai_gpiocontrol(struct si_pub *sih, u32 mask, u32 val, u8 priority)
{
uint regoff;
regoff = offsetof(struct chipcregs, gpiocontrol);
return ai_corereg(sih, SI_CC_IDX, regoff, mask, val);
}
void ai_chipcontrl_epa4331(struct si_pub *sih, bool on)
{
struct si_info *sii;
struct chipcregs __iomem *cc;
uint origidx;
u32 val;
sii = (struct si_info *)sih;
origidx = ai_coreidx(sih);
cc = (struct chipcregs __iomem *) ai_setcore(sih, CC_CORE_ID, 0);
val = R_REG(&cc->chipcontrol);
if (on) {
if (sih->chippkg == 9 || sih->chippkg == 0xb)
W_REG(&cc->chipcontrol, val |
CCTRL4331_EXTPA_EN |
CCTRL4331_EXTPA_ON_GPIO2_5);
else
W_REG(&cc->chipcontrol,
val | CCTRL4331_EXTPA_EN);
} else {
val &= ~(CCTRL4331_EXTPA_EN | CCTRL4331_EXTPA_ON_GPIO2_5);
W_REG(&cc->chipcontrol, val);
}
ai_setcoreidx(sih, origidx);
}
void ai_epa_4313war(struct si_pub *sih)
{
struct si_info *sii;
struct chipcregs __iomem *cc;
uint origidx;
sii = (struct si_info *)sih;
origidx = ai_coreidx(sih);
cc = ai_setcore(sih, CC_CORE_ID, 0);
W_REG(&cc->gpiocontrol,
R_REG(&cc->gpiocontrol) | GPIO_CTRL_EPA_EN_MASK);
ai_setcoreidx(sih, origidx);
}
bool ai_deviceremoved(struct si_pub *sih)
{
u32 w;
struct si_info *sii;
sii = (struct si_info *)sih;
pci_read_config_dword(sii->pbus, PCI_VENDOR_ID, &w);
if ((w & 0xFFFF) != PCI_VENDOR_ID_BROADCOM)
return true;
return false;
}
bool ai_is_sprom_available(struct si_pub *sih)
{
if (sih->ccrev >= 31) {
struct si_info *sii;
uint origidx;
struct chipcregs __iomem *cc;
u32 sromctrl;
if ((sih->cccaps & CC_CAP_SROM) == 0)
return false;
sii = (struct si_info *)sih;
origidx = sii->curidx;
cc = ai_setcoreidx(sih, SI_CC_IDX);
sromctrl = R_REG(&cc->sromcontrol);
ai_setcoreidx(sih, origidx);
return sromctrl & SRC_PRESENT;
}
switch (sih->chip) {
case BCM4313_CHIP_ID:
return (sih->chipst & CST4313_SPROM_PRESENT) != 0;
default:
return true;
}
}
bool ai_is_otp_disabled(struct si_pub *sih)
{
switch (sih->chip) {
case BCM4313_CHIP_ID:
return (sih->chipst & CST4313_OTP_PRESENT) == 0;
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
default:
return false;
}
}
