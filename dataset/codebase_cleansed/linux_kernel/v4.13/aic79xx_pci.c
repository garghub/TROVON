static inline uint64_t
ahd_compose_id(u_int device, u_int vendor, u_int subdevice, u_int subvendor)
{
uint64_t id;
id = subvendor
| (subdevice << 16)
| ((uint64_t)vendor << 32)
| ((uint64_t)device << 48);
return (id);
}
const struct ahd_pci_identity *
ahd_find_pci_device(ahd_dev_softc_t pci)
{
uint64_t full_id;
uint16_t device;
uint16_t vendor;
uint16_t subdevice;
uint16_t subvendor;
const struct ahd_pci_identity *entry;
u_int i;
vendor = ahd_pci_read_config(pci, PCIR_DEVVENDOR, 2);
device = ahd_pci_read_config(pci, PCIR_DEVICE, 2);
subvendor = ahd_pci_read_config(pci, PCIR_SUBVEND_0, 2);
subdevice = ahd_pci_read_config(pci, PCIR_SUBDEV_0, 2);
full_id = ahd_compose_id(device,
vendor,
subdevice,
subvendor);
full_id &= ID_ALL_IROC_MASK;
for (i = 0; i < ahd_num_pci_devs; i++) {
entry = &ahd_pci_ident_table[i];
if (entry->full_id == (full_id & entry->id_mask)) {
if (entry->name == NULL)
return (NULL);
return (entry);
}
}
return (NULL);
}
int
ahd_pci_config(struct ahd_softc *ahd, const struct ahd_pci_identity *entry)
{
struct scb_data *shared_scb_data;
u_int command;
uint32_t devconfig;
uint16_t subvendor;
int error;
shared_scb_data = NULL;
ahd->description = entry->name;
subvendor = ahd_pci_read_config(ahd->dev_softc,
PCIR_SUBVEND_0, 2);
if (subvendor == SUBID_HP)
ahd->flags |= AHD_HP_BOARD;
error = entry->setup(ahd);
if (error != 0)
return (error);
devconfig = ahd_pci_read_config(ahd->dev_softc, DEVCONFIG, 4);
if ((devconfig & PCIXINITPAT) == PCIXINIT_PCI33_66) {
ahd->chip |= AHD_PCI;
ahd->bugs &= ~AHD_PCIX_BUG_MASK;
} else {
ahd->chip |= AHD_PCIX;
}
ahd->bus_description = pci_bus_modes[PCI_BUS_MODES_INDEX(devconfig)];
ahd_power_state_change(ahd, AHD_POWER_STATE_D0);
error = ahd_pci_map_registers(ahd);
if (error != 0)
return (error);
if ((ahd->flags & (AHD_39BIT_ADDRESSING|AHD_64BIT_ADDRESSING)) != 0) {
if (bootverbose)
printk("%s: Enabling 39Bit Addressing\n",
ahd_name(ahd));
devconfig = ahd_pci_read_config(ahd->dev_softc,
DEVCONFIG, 4);
devconfig |= DACEN;
ahd_pci_write_config(ahd->dev_softc, DEVCONFIG,
devconfig, 4);
}
command = ahd_pci_read_config(ahd->dev_softc, PCIR_COMMAND, 2);
command |= PCIM_CMD_BUSMASTEREN;
ahd_pci_write_config(ahd->dev_softc, PCIR_COMMAND, command, 2);
error = ahd_softc_init(ahd);
if (error != 0)
return (error);
ahd->bus_intr = ahd_pci_intr;
error = ahd_reset(ahd, FALSE);
if (error != 0)
return (ENXIO);
ahd->pci_cachesize =
ahd_pci_read_config(ahd->dev_softc, CSIZE_LATTIME,
1) & CACHESIZE;
ahd->pci_cachesize *= 4;
ahd_set_modes(ahd, AHD_MODE_SCSI, AHD_MODE_SCSI);
error = ahd_check_extport(ahd);
if (error != 0)
return (error);
error = ahd_init(ahd);
if (error != 0)
return (error);
ahd->init_level++;
return ahd_pci_map_int(ahd);
}
void
ahd_pci_suspend(struct ahd_softc *ahd)
{
ahd->suspend_state.pci_state.devconfig =
ahd_pci_read_config(ahd->dev_softc, DEVCONFIG, 4);
ahd->suspend_state.pci_state.command =
ahd_pci_read_config(ahd->dev_softc, PCIR_COMMAND, 1);
ahd->suspend_state.pci_state.csize_lattime =
ahd_pci_read_config(ahd->dev_softc, CSIZE_LATTIME, 1);
}
void
ahd_pci_resume(struct ahd_softc *ahd)
{
ahd_pci_write_config(ahd->dev_softc, DEVCONFIG,
ahd->suspend_state.pci_state.devconfig, 4);
ahd_pci_write_config(ahd->dev_softc, PCIR_COMMAND,
ahd->suspend_state.pci_state.command, 1);
ahd_pci_write_config(ahd->dev_softc, CSIZE_LATTIME,
ahd->suspend_state.pci_state.csize_lattime, 1);
}
int
ahd_pci_test_register_access(struct ahd_softc *ahd)
{
uint32_t cmd;
u_int targpcistat;
u_int pci_status1;
int error;
uint8_t hcntrl;
error = EIO;
cmd = ahd_pci_read_config(ahd->dev_softc, PCIR_COMMAND, 2);
ahd_pci_write_config(ahd->dev_softc, PCIR_COMMAND,
cmd & ~PCIM_CMD_SERRESPEN, 2);
hcntrl = ahd_inb(ahd, HCNTRL);
if (hcntrl == 0xFF)
goto fail;
hcntrl &= ~CHIPRST;
ahd_outb(ahd, HCNTRL, hcntrl|PAUSE);
while (ahd_is_paused(ahd) == 0)
;
ahd_set_modes(ahd, AHD_MODE_CFG, AHD_MODE_CFG);
targpcistat = ahd_inb(ahd, TARGPCISTAT);
ahd_outb(ahd, TARGPCISTAT, targpcistat);
pci_status1 = ahd_pci_read_config(ahd->dev_softc,
PCIR_STATUS + 1, 1);
ahd_pci_write_config(ahd->dev_softc, PCIR_STATUS + 1,
pci_status1, 1);
ahd_set_modes(ahd, AHD_MODE_SCSI, AHD_MODE_SCSI);
ahd_outb(ahd, CLRINT, CLRPCIINT);
ahd_outb(ahd, SEQCTL0, PERRORDIS);
ahd_outl(ahd, SRAM_BASE, 0x5aa555aa);
if (ahd_inl(ahd, SRAM_BASE) != 0x5aa555aa)
goto fail;
if ((ahd_inb(ahd, INTSTAT) & PCIINT) != 0) {
ahd_set_modes(ahd, AHD_MODE_CFG, AHD_MODE_CFG);
targpcistat = ahd_inb(ahd, TARGPCISTAT);
if ((targpcistat & STA) != 0)
goto fail;
}
error = 0;
fail:
if ((ahd_inb(ahd, INTSTAT) & PCIINT) != 0) {
ahd_set_modes(ahd, AHD_MODE_CFG, AHD_MODE_CFG);
targpcistat = ahd_inb(ahd, TARGPCISTAT);
ahd_outb(ahd, TARGPCISTAT, targpcistat);
pci_status1 = ahd_pci_read_config(ahd->dev_softc,
PCIR_STATUS + 1, 1);
ahd_pci_write_config(ahd->dev_softc, PCIR_STATUS + 1,
pci_status1, 1);
ahd_outb(ahd, CLRINT, CLRPCIINT);
}
ahd_outb(ahd, SEQCTL0, PERRORDIS|FAILDIS);
ahd_pci_write_config(ahd->dev_softc, PCIR_COMMAND, cmd, 2);
return (error);
}
static int
ahd_check_extport(struct ahd_softc *ahd)
{
struct vpd_config vpd;
struct seeprom_config *sc;
u_int adapter_control;
int have_seeprom;
int error;
sc = ahd->seep_config;
have_seeprom = ahd_acquire_seeprom(ahd);
if (have_seeprom) {
u_int start_addr;
if (bootverbose)
printk("%s: Reading VPD from SEEPROM...",
ahd_name(ahd));
start_addr = ((2 * sizeof(*sc))
+ (sizeof(vpd) * (ahd->channel - 'A'))) / 2;
error = ahd_read_seeprom(ahd, (uint16_t *)&vpd,
start_addr, sizeof(vpd)/2,
TRUE);
if (error == 0)
error = ahd_parse_vpddata(ahd, &vpd);
if (bootverbose)
printk("%s: VPD parsing %s\n",
ahd_name(ahd),
error == 0 ? "successful" : "failed");
if (bootverbose)
printk("%s: Reading SEEPROM...", ahd_name(ahd));
start_addr = (sizeof(*sc) / 2) * (ahd->channel - 'A');
error = ahd_read_seeprom(ahd, (uint16_t *)sc,
start_addr, sizeof(*sc)/2,
FALSE);
if (error != 0) {
printk("Unable to read SEEPROM\n");
have_seeprom = 0;
} else {
have_seeprom = ahd_verify_cksum(sc);
if (bootverbose) {
if (have_seeprom == 0)
printk ("checksum error\n");
else
printk ("done.\n");
}
}
ahd_release_seeprom(ahd);
}
if (!have_seeprom) {
u_int nvram_scb;
ahd_set_scbptr(ahd, 0xFF);
nvram_scb = ahd_inb_scbram(ahd, SCB_BASE + NVRAM_SCB_OFFSET);
if (nvram_scb != 0xFF
&& ((ahd_inb_scbram(ahd, SCB_BASE + 0) == 'A'
&& ahd_inb_scbram(ahd, SCB_BASE + 1) == 'D'
&& ahd_inb_scbram(ahd, SCB_BASE + 2) == 'P'
&& ahd_inb_scbram(ahd, SCB_BASE + 3) == 'T')
|| (ahd_inb_scbram(ahd, SCB_BASE + 0) == 'B'
&& ahd_inb_scbram(ahd, SCB_BASE + 1) == 'I'
&& ahd_inb_scbram(ahd, SCB_BASE + 2) == 'O'
&& ahd_inb_scbram(ahd, SCB_BASE + 3) == 'S')
|| (ahd_inb_scbram(ahd, SCB_BASE + 0) == 'A'
&& ahd_inb_scbram(ahd, SCB_BASE + 1) == 'S'
&& ahd_inb_scbram(ahd, SCB_BASE + 2) == 'P'
&& ahd_inb_scbram(ahd, SCB_BASE + 3) == 'I'))) {
uint16_t *sc_data;
int i;
ahd_set_scbptr(ahd, nvram_scb);
sc_data = (uint16_t *)sc;
for (i = 0; i < 64; i += 2)
*sc_data++ = ahd_inw_scbram(ahd, SCB_BASE+i);
have_seeprom = ahd_verify_cksum(sc);
if (have_seeprom)
ahd->flags |= AHD_SCB_CONFIG_USED;
}
}
#ifdef AHD_DEBUG
if (have_seeprom != 0
&& (ahd_debug & AHD_DUMP_SEEPROM) != 0) {
uint16_t *sc_data;
int i;
printk("%s: Seeprom Contents:", ahd_name(ahd));
sc_data = (uint16_t *)sc;
for (i = 0; i < (sizeof(*sc)); i += 2)
printk("\n\t0x%.4x", sc_data[i]);
printk("\n");
}
#endif
if (!have_seeprom) {
if (bootverbose)
printk("%s: No SEEPROM available.\n", ahd_name(ahd));
ahd->flags |= AHD_USEDEFAULTS;
error = ahd_default_config(ahd);
adapter_control = CFAUTOTERM|CFSEAUTOTERM;
kfree(ahd->seep_config);
ahd->seep_config = NULL;
} else {
error = ahd_parse_cfgdata(ahd, sc);
adapter_control = sc->adapter_control;
}
if (error != 0)
return (error);
ahd_configure_termination(ahd, adapter_control);
return (0);
}
static void
ahd_configure_termination(struct ahd_softc *ahd, u_int adapter_control)
{
int error;
u_int sxfrctl1;
uint8_t termctl;
uint32_t devconfig;
devconfig = ahd_pci_read_config(ahd->dev_softc, DEVCONFIG, 4);
devconfig &= ~STPWLEVEL;
if ((ahd->flags & AHD_STPWLEVEL_A) != 0)
devconfig |= STPWLEVEL;
if (bootverbose)
printk("%s: STPWLEVEL is %s\n",
ahd_name(ahd), (devconfig & STPWLEVEL) ? "on" : "off");
ahd_pci_write_config(ahd->dev_softc, DEVCONFIG, devconfig, 4);
if ((ahd->flags & AHD_CURRENT_SENSING) != 0) {
(void)ahd_write_flexport(ahd, FLXADDR_ROMSTAT_CURSENSECTL, 0);
}
error = ahd_read_flexport(ahd, FLXADDR_TERMCTL, &termctl);
if ((adapter_control & CFAUTOTERM) == 0) {
if (bootverbose)
printk("%s: Manual Primary Termination\n",
ahd_name(ahd));
termctl &= ~(FLX_TERMCTL_ENPRILOW|FLX_TERMCTL_ENPRIHIGH);
if ((adapter_control & CFSTERM) != 0)
termctl |= FLX_TERMCTL_ENPRILOW;
if ((adapter_control & CFWSTERM) != 0)
termctl |= FLX_TERMCTL_ENPRIHIGH;
} else if (error != 0) {
printk("%s: Primary Auto-Term Sensing failed! "
"Using Defaults.\n", ahd_name(ahd));
termctl = FLX_TERMCTL_ENPRILOW|FLX_TERMCTL_ENPRIHIGH;
}
if ((adapter_control & CFSEAUTOTERM) == 0) {
if (bootverbose)
printk("%s: Manual Secondary Termination\n",
ahd_name(ahd));
termctl &= ~(FLX_TERMCTL_ENSECLOW|FLX_TERMCTL_ENSECHIGH);
if ((adapter_control & CFSELOWTERM) != 0)
termctl |= FLX_TERMCTL_ENSECLOW;
if ((adapter_control & CFSEHIGHTERM) != 0)
termctl |= FLX_TERMCTL_ENSECHIGH;
} else if (error != 0) {
printk("%s: Secondary Auto-Term Sensing failed! "
"Using Defaults.\n", ahd_name(ahd));
termctl |= FLX_TERMCTL_ENSECLOW|FLX_TERMCTL_ENSECHIGH;
}
sxfrctl1 = ahd_inb(ahd, SXFRCTL1) & ~STPWEN;
ahd->flags &= ~AHD_TERM_ENB_A;
if ((termctl & FLX_TERMCTL_ENPRILOW) != 0) {
ahd->flags |= AHD_TERM_ENB_A;
sxfrctl1 |= STPWEN;
}
ahd_outb(ahd, SXFRCTL1, sxfrctl1|STPWEN);
ahd_outb(ahd, SXFRCTL1, sxfrctl1);
error = ahd_write_flexport(ahd, FLXADDR_TERMCTL, termctl);
if (error != 0) {
printk("%s: Unable to set termination settings!\n",
ahd_name(ahd));
} else if (bootverbose) {
printk("%s: Primary High byte termination %sabled\n",
ahd_name(ahd),
(termctl & FLX_TERMCTL_ENPRIHIGH) ? "En" : "Dis");
printk("%s: Primary Low byte termination %sabled\n",
ahd_name(ahd),
(termctl & FLX_TERMCTL_ENPRILOW) ? "En" : "Dis");
printk("%s: Secondary High byte termination %sabled\n",
ahd_name(ahd),
(termctl & FLX_TERMCTL_ENSECHIGH) ? "En" : "Dis");
printk("%s: Secondary Low byte termination %sabled\n",
ahd_name(ahd),
(termctl & FLX_TERMCTL_ENSECLOW) ? "En" : "Dis");
}
return;
}
static void
ahd_pci_intr(struct ahd_softc *ahd)
{
uint8_t pci_status[8];
ahd_mode_state saved_modes;
u_int pci_status1;
u_int intstat;
u_int i;
u_int reg;
intstat = ahd_inb(ahd, INTSTAT);
if ((intstat & SPLTINT) != 0)
ahd_pci_split_intr(ahd, intstat);
if ((intstat & PCIINT) == 0)
return;
printk("%s: PCI error Interrupt\n", ahd_name(ahd));
saved_modes = ahd_save_modes(ahd);
ahd_dump_card_state(ahd);
ahd_set_modes(ahd, AHD_MODE_CFG, AHD_MODE_CFG);
for (i = 0, reg = DF0PCISTAT; i < 8; i++, reg++) {
if (i == 5)
continue;
pci_status[i] = ahd_inb(ahd, reg);
ahd_outb(ahd, reg, pci_status[i]);
}
for (i = 0; i < 8; i++) {
u_int bit;
if (i == 5)
continue;
for (bit = 0; bit < 8; bit++) {
if ((pci_status[i] & (0x1 << bit)) != 0) {
const char *s;
s = pci_status_strings[bit];
if (i == 7 && bit == 3)
s = "%s: Signaled Target Abort\n";
printk(s, ahd_name(ahd), pci_status_source[i]);
}
}
}
pci_status1 = ahd_pci_read_config(ahd->dev_softc,
PCIR_STATUS + 1, 1);
ahd_pci_write_config(ahd->dev_softc, PCIR_STATUS + 1,
pci_status1, 1);
ahd_restore_modes(ahd, saved_modes);
ahd_outb(ahd, CLRINT, CLRPCIINT);
ahd_unpause(ahd);
}
static void
ahd_pci_split_intr(struct ahd_softc *ahd, u_int intstat)
{
uint8_t split_status[4];
uint8_t split_status1[4];
uint8_t sg_split_status[2];
uint8_t sg_split_status1[2];
ahd_mode_state saved_modes;
u_int i;
uint16_t pcix_status;
pcix_status = ahd_pci_read_config(ahd->dev_softc, PCIXR_STATUS,
2);
printk("%s: PCI Split Interrupt - PCI-X status = 0x%x\n",
ahd_name(ahd), pcix_status);
saved_modes = ahd_save_modes(ahd);
for (i = 0; i < 4; i++) {
ahd_set_modes(ahd, i, i);
split_status[i] = ahd_inb(ahd, DCHSPLTSTAT0);
split_status1[i] = ahd_inb(ahd, DCHSPLTSTAT1);
ahd_outb(ahd, DCHSPLTSTAT0, split_status[i]);
ahd_outb(ahd, DCHSPLTSTAT1, split_status1[i]);
if (i > 1)
continue;
sg_split_status[i] = ahd_inb(ahd, SGSPLTSTAT0);
sg_split_status1[i] = ahd_inb(ahd, SGSPLTSTAT1);
ahd_outb(ahd, SGSPLTSTAT0, sg_split_status[i]);
ahd_outb(ahd, SGSPLTSTAT1, sg_split_status1[i]);
}
for (i = 0; i < 4; i++) {
u_int bit;
for (bit = 0; bit < 8; bit++) {
if ((split_status[i] & (0x1 << bit)) != 0)
printk(split_status_strings[bit], ahd_name(ahd),
split_status_source[i]);
if (i > 1)
continue;
if ((sg_split_status[i] & (0x1 << bit)) != 0)
printk(split_status_strings[bit], ahd_name(ahd), "SG");
}
}
ahd_pci_write_config(ahd->dev_softc, PCIXR_STATUS,
pcix_status, 2);
ahd_outb(ahd, CLRINT, CLRSPLTINT);
ahd_restore_modes(ahd, saved_modes);
}
static int
ahd_aic7901_setup(struct ahd_softc *ahd)
{
ahd->chip = AHD_AIC7901;
ahd->features = AHD_AIC7901_FE;
return (ahd_aic790X_setup(ahd));
}
static int
ahd_aic7901A_setup(struct ahd_softc *ahd)
{
ahd->chip = AHD_AIC7901A;
ahd->features = AHD_AIC7901A_FE;
return (ahd_aic790X_setup(ahd));
}
static int
ahd_aic7902_setup(struct ahd_softc *ahd)
{
ahd->chip = AHD_AIC7902;
ahd->features = AHD_AIC7902_FE;
return (ahd_aic790X_setup(ahd));
}
static int
ahd_aic790X_setup(struct ahd_softc *ahd)
{
ahd_dev_softc_t pci;
u_int rev;
pci = ahd->dev_softc;
rev = ahd_pci_read_config(pci, PCIR_REVID, 1);
if (rev < ID_AIC7902_PCI_REV_A4) {
printk("%s: Unable to attach to unsupported chip revision %d\n",
ahd_name(ahd), rev);
ahd_pci_write_config(pci, PCIR_COMMAND, 0, 2);
return (ENXIO);
}
ahd->channel = ahd_get_pci_function(pci) + 'A';
if (rev < ID_AIC7902_PCI_REV_B0) {
ahd->bugs |= AHD_SENT_SCB_UPDATE_BUG|AHD_ABORT_LQI_BUG
| AHD_PKT_BITBUCKET_BUG|AHD_LONG_SETIMO_BUG
| AHD_NLQICRC_DELAYED_BUG|AHD_SCSIRST_BUG
| AHD_LQO_ATNO_BUG|AHD_AUTOFLUSH_BUG
| AHD_CLRLQO_AUTOCLR_BUG|AHD_PCIX_MMAPIO_BUG
| AHD_PCIX_CHIPRST_BUG|AHD_PCIX_SCBRAM_RD_BUG
| AHD_PKTIZED_STATUS_BUG|AHD_PKT_LUN_BUG
| AHD_MDFF_WSCBPTR_BUG|AHD_REG_SLOW_SETTLE_BUG
| AHD_SET_MODE_BUG|AHD_BUSFREEREV_BUG
| AHD_NONPACKFIFO_BUG|AHD_PACED_NEGTABLE_BUG
| AHD_FAINT_LED_BUG;
AHD_SET_PRECOMP(ahd, AHD_PRECOMP_CUTBACK_29);
if ((ahd->flags & AHD_HP_BOARD) == 0)
AHD_SET_SLEWRATE(ahd, AHD_SLEWRATE_DEF_REVA);
} else {
extern uint32_t aic79xx_slowcrc;
u_int devconfig1;
ahd->features |= AHD_RTI|AHD_NEW_IOCELL_OPTS
| AHD_NEW_DFCNTRL_OPTS|AHD_FAST_CDB_DELIVERY
| AHD_BUSFREEREV_BUG;
ahd->bugs |= AHD_LQOOVERRUN_BUG|AHD_EARLY_REQ_BUG;
if (aic79xx_slowcrc)
ahd->features |= AHD_AIC79XXB_SLOWCRC;
if ((ahd->features & AHD_MULTI_FUNC) != 0)
ahd->bugs |= AHD_INTCOLLISION_BUG|AHD_ABORT_LQI_BUG;
AHD_SET_PRECOMP(ahd, AHD_PRECOMP_CUTBACK_29);
AHD_SET_SLEWRATE(ahd, AHD_SLEWRATE_DEF_REVB);
AHD_SET_AMPLITUDE(ahd, AHD_AMPLITUDE_DEF);
devconfig1 = ahd_pci_read_config(pci, DEVCONFIG1, 1);
ahd_pci_write_config(pci, DEVCONFIG1,
devconfig1|PREQDIS, 1);
devconfig1 = ahd_pci_read_config(pci, DEVCONFIG1, 1);
}
return (0);
}
