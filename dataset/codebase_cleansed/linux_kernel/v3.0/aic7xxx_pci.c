static inline uint64_t
ahc_compose_id(u_int device, u_int vendor, u_int subdevice, u_int subvendor)
{
uint64_t id;
id = subvendor
| (subdevice << 16)
| ((uint64_t)vendor << 32)
| ((uint64_t)device << 48);
return (id);
}
static int
ahc_9005_subdevinfo_valid(uint16_t device, uint16_t vendor,
uint16_t subdevice, uint16_t subvendor)
{
int result;
result = 0;
if (vendor == 0x9005
&& subvendor == 0x9005
&& subdevice != device
&& SUBID_9005_TYPE_KNOWN(subdevice) != 0) {
switch (SUBID_9005_TYPE(subdevice)) {
case SUBID_9005_TYPE_MB:
break;
case SUBID_9005_TYPE_CARD:
case SUBID_9005_TYPE_LCCARD:
if (DEVID_9005_TYPE(device) == DEVID_9005_TYPE_HBA)
result = 1;
break;
case SUBID_9005_TYPE_RAID:
break;
default:
break;
}
}
return (result);
}
const struct ahc_pci_identity *
ahc_find_pci_device(ahc_dev_softc_t pci)
{
uint64_t full_id;
uint16_t device;
uint16_t vendor;
uint16_t subdevice;
uint16_t subvendor;
const struct ahc_pci_identity *entry;
u_int i;
vendor = ahc_pci_read_config(pci, PCIR_DEVVENDOR, 2);
device = ahc_pci_read_config(pci, PCIR_DEVICE, 2);
subvendor = ahc_pci_read_config(pci, PCIR_SUBVEND_0, 2);
subdevice = ahc_pci_read_config(pci, PCIR_SUBDEV_0, 2);
full_id = ahc_compose_id(device, vendor, subdevice, subvendor);
if (ahc_get_pci_function(pci) > 0
&& ahc_9005_subdevinfo_valid(vendor, device, subvendor, subdevice)
&& SUBID_9005_MFUNCENB(subdevice) == 0)
return (NULL);
for (i = 0; i < ahc_num_pci_devs; i++) {
entry = &ahc_pci_ident_table[i];
if (entry->full_id == (full_id & entry->id_mask)) {
if (entry->name == NULL)
return (NULL);
return (entry);
}
}
return (NULL);
}
int
ahc_pci_config(struct ahc_softc *ahc, const struct ahc_pci_identity *entry)
{
u_int command;
u_int our_id;
u_int sxfrctl1;
u_int scsiseq;
u_int dscommand0;
uint32_t devconfig;
int error;
uint8_t sblkctl;
our_id = 0;
error = entry->setup(ahc);
if (error != 0)
return (error);
ahc->chip |= AHC_PCI;
ahc->description = entry->name;
pci_set_power_state(ahc->dev_softc, AHC_POWER_STATE_D0);
error = ahc_pci_map_registers(ahc);
if (error != 0)
return (error);
ahc_intr_enable(ahc, FALSE);
devconfig = ahc_pci_read_config(ahc->dev_softc, DEVCONFIG, 4);
if ((ahc->flags & AHC_39BIT_ADDRESSING) != 0) {
if (bootverbose)
printk("%s: Enabling 39Bit Addressing\n",
ahc_name(ahc));
devconfig |= DACEN;
}
devconfig |= PCIERRGENDIS;
ahc_pci_write_config(ahc->dev_softc, DEVCONFIG, devconfig, 4);
command = ahc_pci_read_config(ahc->dev_softc, PCIR_COMMAND, 2);
command |= PCIM_CMD_BUSMASTEREN;
ahc_pci_write_config(ahc->dev_softc, PCIR_COMMAND, command, 2);
ahc->flags |= AHC_PAGESCBS;
error = ahc_softc_init(ahc);
if (error != 0)
return (error);
if ((ahc->flags & AHC_DISABLE_PCI_PERR) != 0)
ahc->seqctl |= FAILDIS;
ahc->bus_intr = ahc_pci_intr;
ahc->bus_chip_init = ahc_pci_chip_init;
if ((ahc_inb(ahc, HCNTRL) & POWRDN) == 0) {
ahc_pause(ahc);
if ((ahc->features & AHC_ULTRA2) != 0)
our_id = ahc_inb(ahc, SCSIID_ULTRA2) & OID;
else
our_id = ahc_inb(ahc, SCSIID) & OID;
sxfrctl1 = ahc_inb(ahc, SXFRCTL1) & STPWEN;
scsiseq = ahc_inb(ahc, SCSISEQ);
} else {
sxfrctl1 = STPWEN;
our_id = 7;
scsiseq = 0;
}
error = ahc_reset(ahc, FALSE);
if (error != 0)
return (ENXIO);
if ((ahc->features & AHC_DT) != 0) {
u_int sfunct;
sfunct = ahc_inb(ahc, SFUNCT) & ~ALT_MODE;
ahc_outb(ahc, SFUNCT, sfunct | ALT_MODE);
ahc_outb(ahc, OPTIONMODE,
OPTIONMODE_DEFAULTS|AUTOACKEN|BUSFREEREV|EXPPHASEDIS);
ahc_outb(ahc, SFUNCT, sfunct);
ahc_outb(ahc, CRCCONTROL1, CRCVALCHKEN|CRCENDCHKEN|CRCREQCHKEN
|TARGCRCENDEN);
}
dscommand0 = ahc_inb(ahc, DSCOMMAND0);
dscommand0 |= MPARCKEN|CACHETHEN;
if ((ahc->features & AHC_ULTRA2) != 0) {
dscommand0 &= ~DPARCKEN;
}
if ((ahc->bugs & AHC_CACHETHEN_DIS_BUG) != 0)
dscommand0 |= CACHETHEN;
if ((ahc->bugs & AHC_CACHETHEN_BUG) != 0)
dscommand0 &= ~CACHETHEN;
ahc_outb(ahc, DSCOMMAND0, dscommand0);
ahc->pci_cachesize =
ahc_pci_read_config(ahc->dev_softc, CSIZE_LATTIME,
1) & CACHESIZE;
ahc->pci_cachesize *= 4;
if ((ahc->bugs & AHC_PCI_2_1_RETRY_BUG) != 0
&& ahc->pci_cachesize == 4) {
ahc_pci_write_config(ahc->dev_softc, CSIZE_LATTIME,
0, 1);
ahc->pci_cachesize = 0;
}
if ((ahc->features & AHC_ULTRA) != 0) {
uint32_t devconfig;
devconfig = ahc_pci_read_config(ahc->dev_softc,
DEVCONFIG, 4);
if ((devconfig & REXTVALID) == 0)
ahc->features &= ~AHC_ULTRA;
}
check_extport(ahc, &sxfrctl1);
sblkctl = ahc_inb(ahc, SBLKCTL);
ahc_outb(ahc, SBLKCTL, (sblkctl & ~(DIAGLEDEN|DIAGLEDON)));
if ((ahc->features & AHC_ULTRA2) != 0) {
ahc_outb(ahc, DFF_THRSH, RD_DFTHRSH_MAX|WR_DFTHRSH_MAX);
} else {
ahc_outb(ahc, DSPCISTATUS, DFTHRSH_100);
}
if (ahc->flags & AHC_USEDEFAULTS) {
if ((ahc->flags & AHC_NO_BIOS_INIT) == 0
&& scsiseq != 0) {
printk("%s: Using left over BIOS settings\n",
ahc_name(ahc));
ahc->flags &= ~AHC_USEDEFAULTS;
ahc->flags |= AHC_BIOS_ENABLED;
} else {
our_id = 0x07;
sxfrctl1 = STPWEN;
}
ahc_outb(ahc, SCSICONF, our_id|ENSPCHK|RESET_SCSI);
ahc->our_id = our_id;
}
ahc_probe_ext_scbram(ahc);
if ((sxfrctl1 & STPWEN) != 0)
ahc->flags |= AHC_TERM_ENB_A;
ahc->bus_softc.pci_softc.devconfig =
ahc_pci_read_config(ahc->dev_softc, DEVCONFIG, 4);
ahc->bus_softc.pci_softc.command =
ahc_pci_read_config(ahc->dev_softc, PCIR_COMMAND, 1);
ahc->bus_softc.pci_softc.csize_lattime =
ahc_pci_read_config(ahc->dev_softc, CSIZE_LATTIME, 1);
ahc->bus_softc.pci_softc.dscommand0 = ahc_inb(ahc, DSCOMMAND0);
ahc->bus_softc.pci_softc.dspcistatus = ahc_inb(ahc, DSPCISTATUS);
if ((ahc->features & AHC_DT) != 0) {
u_int sfunct;
sfunct = ahc_inb(ahc, SFUNCT) & ~ALT_MODE;
ahc_outb(ahc, SFUNCT, sfunct | ALT_MODE);
ahc->bus_softc.pci_softc.optionmode = ahc_inb(ahc, OPTIONMODE);
ahc->bus_softc.pci_softc.targcrccnt = ahc_inw(ahc, TARGCRCCNT);
ahc_outb(ahc, SFUNCT, sfunct);
ahc->bus_softc.pci_softc.crccontrol1 =
ahc_inb(ahc, CRCCONTROL1);
}
if ((ahc->features & AHC_MULTI_FUNC) != 0)
ahc->bus_softc.pci_softc.scbbaddr = ahc_inb(ahc, SCBBADDR);
if ((ahc->features & AHC_ULTRA2) != 0)
ahc->bus_softc.pci_softc.dff_thrsh = ahc_inb(ahc, DFF_THRSH);
error = ahc_init(ahc);
if (error != 0)
return (error);
ahc->init_level++;
return ahc_pci_map_int(ahc);
}
static int
ahc_ext_scbram_present(struct ahc_softc *ahc)
{
u_int chip;
int ramps;
int single_user;
uint32_t devconfig;
chip = ahc->chip & AHC_CHIPID_MASK;
devconfig = ahc_pci_read_config(ahc->dev_softc,
DEVCONFIG, 4);
single_user = (devconfig & MPORTMODE) != 0;
if ((ahc->features & AHC_ULTRA2) != 0)
ramps = (ahc_inb(ahc, DSCOMMAND0) & RAMPS) != 0;
else if (chip == AHC_AIC7895 || chip == AHC_AIC7895C)
ramps = 0;
else if (chip >= AHC_AIC7870)
ramps = (devconfig & RAMPSM) != 0;
else
ramps = 0;
if (ramps && single_user)
return (1);
return (0);
}
static void
ahc_scbram_config(struct ahc_softc *ahc, int enable, int pcheck,
int fast, int large)
{
uint32_t devconfig;
if (ahc->features & AHC_MULTI_FUNC) {
ahc_outb(ahc, SCBBADDR, ahc_get_pci_function(ahc->dev_softc));
}
ahc->flags &= ~AHC_LSCBS_ENABLED;
if (large)
ahc->flags |= AHC_LSCBS_ENABLED;
devconfig = ahc_pci_read_config(ahc->dev_softc, DEVCONFIG, 4);
if ((ahc->features & AHC_ULTRA2) != 0) {
u_int dscommand0;
dscommand0 = ahc_inb(ahc, DSCOMMAND0);
if (enable)
dscommand0 &= ~INTSCBRAMSEL;
else
dscommand0 |= INTSCBRAMSEL;
if (large)
dscommand0 &= ~USCBSIZE32;
else
dscommand0 |= USCBSIZE32;
ahc_outb(ahc, DSCOMMAND0, dscommand0);
} else {
if (fast)
devconfig &= ~EXTSCBTIME;
else
devconfig |= EXTSCBTIME;
if (enable)
devconfig &= ~SCBRAMSEL;
else
devconfig |= SCBRAMSEL;
if (large)
devconfig &= ~SCBSIZE32;
else
devconfig |= SCBSIZE32;
}
if (pcheck)
devconfig |= EXTSCBPEN;
else
devconfig &= ~EXTSCBPEN;
ahc_pci_write_config(ahc->dev_softc, DEVCONFIG, devconfig, 4);
}
static void
ahc_probe_ext_scbram(struct ahc_softc *ahc)
{
int num_scbs;
int test_num_scbs;
int enable;
int pcheck;
int fast;
int large;
enable = FALSE;
pcheck = FALSE;
fast = FALSE;
large = FALSE;
num_scbs = 0;
if (ahc_ext_scbram_present(ahc) == 0)
goto done;
ahc_scbram_config(ahc, TRUE, pcheck, fast, large);
num_scbs = ahc_probe_scbs(ahc);
if (num_scbs == 0) {
goto done;
}
enable = TRUE;
ahc_outb(ahc, SEQCTL, 0);
ahc_outb(ahc, CLRINT, CLRPARERR);
ahc_outb(ahc, CLRINT, CLRBRKADRINT);
ahc_scbram_config(ahc, enable, TRUE, fast, large);
num_scbs = ahc_probe_scbs(ahc);
if ((ahc_inb(ahc, INTSTAT) & BRKADRINT) == 0
|| (ahc_inb(ahc, ERROR) & MPARERR) == 0)
pcheck = TRUE;
ahc_outb(ahc, CLRINT, CLRPARERR);
ahc_outb(ahc, CLRINT, CLRBRKADRINT);
ahc_scbram_config(ahc, enable, pcheck, TRUE, large);
test_num_scbs = ahc_probe_scbs(ahc);
if (test_num_scbs == num_scbs
&& ((ahc_inb(ahc, INTSTAT) & BRKADRINT) == 0
|| (ahc_inb(ahc, ERROR) & MPARERR) == 0))
fast = TRUE;
if ((ahc->features & AHC_LARGE_SCBS) != 0) {
ahc_scbram_config(ahc, enable, pcheck, fast, TRUE);
test_num_scbs = ahc_probe_scbs(ahc);
if (test_num_scbs >= num_scbs) {
large = TRUE;
num_scbs = test_num_scbs;
if (num_scbs >= 64) {
ahc->flags |= AHC_SCB_BTT;
}
}
}
done:
ahc_outb(ahc, SEQCTL, PERRORDIS|FAILDIS);
ahc_outb(ahc, CLRINT, CLRPARERR);
ahc_outb(ahc, CLRINT, CLRBRKADRINT);
if (bootverbose && enable) {
printk("%s: External SRAM, %s access%s, %dbytes/SCB\n",
ahc_name(ahc), fast ? "fast" : "slow",
pcheck ? ", parity checking enabled" : "",
large ? 64 : 32);
}
ahc_scbram_config(ahc, enable, pcheck, fast, large);
}
int
ahc_pci_test_register_access(struct ahc_softc *ahc)
{
int error;
u_int status1;
uint32_t cmd;
uint8_t hcntrl;
error = EIO;
cmd = ahc_pci_read_config(ahc->dev_softc, PCIR_COMMAND, 2);
ahc_pci_write_config(ahc->dev_softc, PCIR_COMMAND,
cmd & ~PCIM_CMD_SERRESPEN, 2);
hcntrl = ahc_inb(ahc, HCNTRL);
if (hcntrl == 0xFF)
goto fail;
if ((hcntrl & CHIPRST) != 0) {
ahc->flags |= AHC_NO_BIOS_INIT;
}
hcntrl &= ~CHIPRST;
ahc_outb(ahc, HCNTRL, hcntrl|PAUSE);
while (ahc_is_paused(ahc) == 0)
;
status1 = ahc_pci_read_config(ahc->dev_softc,
PCIR_STATUS + 1, 1);
ahc_pci_write_config(ahc->dev_softc, PCIR_STATUS + 1,
status1, 1);
ahc_outb(ahc, CLRINT, CLRPARERR);
ahc_outb(ahc, SEQCTL, PERRORDIS);
ahc_outb(ahc, SCBPTR, 0);
ahc_outl(ahc, SCB_BASE, 0x5aa555aa);
if (ahc_inl(ahc, SCB_BASE) != 0x5aa555aa)
goto fail;
status1 = ahc_pci_read_config(ahc->dev_softc,
PCIR_STATUS + 1, 1);
if ((status1 & STA) != 0)
goto fail;
error = 0;
fail:
status1 = ahc_pci_read_config(ahc->dev_softc,
PCIR_STATUS + 1, 1);
ahc_pci_write_config(ahc->dev_softc, PCIR_STATUS + 1,
status1, 1);
ahc_outb(ahc, CLRINT, CLRPARERR);
ahc_outb(ahc, SEQCTL, PERRORDIS|FAILDIS);
ahc_pci_write_config(ahc->dev_softc, PCIR_COMMAND, cmd, 2);
return (error);
}
static void
check_extport(struct ahc_softc *ahc, u_int *sxfrctl1)
{
struct seeprom_descriptor sd;
struct seeprom_config *sc;
int have_seeprom;
int have_autoterm;
sd.sd_ahc = ahc;
sd.sd_control_offset = SEECTL;
sd.sd_status_offset = SEECTL;
sd.sd_dataout_offset = SEECTL;
sc = ahc->seep_config;
if (ahc->flags & AHC_LARGE_SEEPROM)
sd.sd_chip = C56_66;
else
sd.sd_chip = C46;
sd.sd_MS = SEEMS;
sd.sd_RDY = SEERDY;
sd.sd_CS = SEECS;
sd.sd_CK = SEECK;
sd.sd_DO = SEEDO;
sd.sd_DI = SEEDI;
have_seeprom = ahc_acquire_seeprom(ahc, &sd);
if (have_seeprom) {
if (bootverbose)
printk("%s: Reading SEEPROM...", ahc_name(ahc));
for (;;) {
u_int start_addr;
start_addr = 32 * (ahc->channel - 'A');
have_seeprom = ahc_read_seeprom(&sd, (uint16_t *)sc,
start_addr,
sizeof(*sc)/2);
if (have_seeprom)
have_seeprom = ahc_verify_cksum(sc);
if (have_seeprom != 0 || sd.sd_chip == C56_66) {
if (bootverbose) {
if (have_seeprom == 0)
printk ("checksum error\n");
else
printk ("done.\n");
}
break;
}
sd.sd_chip = C56_66;
}
ahc_release_seeprom(&sd);
if (sd.sd_chip == C56_66)
ahc->flags |= AHC_LARGE_SEEPROM;
}
if (!have_seeprom) {
ahc_outb(ahc, SCBPTR, 2);
if (ahc_inb(ahc, SCB_BASE) == 'A'
&& ahc_inb(ahc, SCB_BASE + 1) == 'D'
&& ahc_inb(ahc, SCB_BASE + 2) == 'P'
&& ahc_inb(ahc, SCB_BASE + 3) == 'T') {
uint16_t *sc_data;
int i;
sc_data = (uint16_t *)sc;
for (i = 0; i < 32; i++, sc_data++) {
int j;
j = i * 2;
*sc_data = ahc_inb(ahc, SRAM_BASE + j)
| ahc_inb(ahc, SRAM_BASE + j + 1) << 8;
}
have_seeprom = ahc_verify_cksum(sc);
if (have_seeprom)
ahc->flags |= AHC_SCB_CONFIG_USED;
}
ahc_outb(ahc, CLRINT, CLRPARERR);
ahc_outb(ahc, CLRINT, CLRBRKADRINT);
}
if (!have_seeprom) {
if (bootverbose)
printk("%s: No SEEPROM available.\n", ahc_name(ahc));
ahc->flags |= AHC_USEDEFAULTS;
kfree(ahc->seep_config);
ahc->seep_config = NULL;
sc = NULL;
} else {
ahc_parse_pci_eeprom(ahc, sc);
}
have_autoterm = have_seeprom;
if ((ahc->features & AHC_SPIOCAP) != 0) {
if ((ahc_inb(ahc, SPIOCAP) & SSPIOCPS) == 0)
have_autoterm = FALSE;
}
if (have_autoterm) {
ahc->flags |= AHC_HAS_TERM_LOGIC;
ahc_acquire_seeprom(ahc, &sd);
configure_termination(ahc, &sd, sc->adapter_control, sxfrctl1);
ahc_release_seeprom(&sd);
} else if (have_seeprom) {
*sxfrctl1 &= ~STPWEN;
if ((sc->adapter_control & CFSTERM) != 0)
*sxfrctl1 |= STPWEN;
if (bootverbose)
printk("%s: Low byte termination %sabled\n",
ahc_name(ahc),
(*sxfrctl1 & STPWEN) ? "en" : "dis");
}
}
static void
ahc_parse_pci_eeprom(struct ahc_softc *ahc, struct seeprom_config *sc)
{
int i;
int max_targ = sc->max_targets & CFMAXTARG;
u_int scsi_conf;
uint16_t discenable;
uint16_t ultraenb;
discenable = 0;
ultraenb = 0;
if ((sc->adapter_control & CFULTRAEN) != 0) {
for (i = 0; i < max_targ; i++) {
if ((sc->device_flags[i] & CFSYNCHISULTRA) != 0) {
ahc->flags |= AHC_NEWEEPROM_FMT;
break;
}
}
}
for (i = 0; i < max_targ; i++) {
u_int scsirate;
uint16_t target_mask;
target_mask = 0x01 << i;
if (sc->device_flags[i] & CFDISC)
discenable |= target_mask;
if ((ahc->flags & AHC_NEWEEPROM_FMT) != 0) {
if ((sc->device_flags[i] & CFSYNCHISULTRA) != 0)
ultraenb |= target_mask;
} else if ((sc->adapter_control & CFULTRAEN) != 0) {
ultraenb |= target_mask;
}
if ((sc->device_flags[i] & CFXFER) == 0x04
&& (ultraenb & target_mask) != 0) {
sc->device_flags[i] &= ~CFXFER;
ultraenb &= ~target_mask;
}
if ((ahc->features & AHC_ULTRA2) != 0) {
u_int offset;
if (sc->device_flags[i] & CFSYNCH)
offset = MAX_OFFSET_ULTRA2;
else
offset = 0;
ahc_outb(ahc, TARG_OFFSET + i, offset);
scsirate = (sc->device_flags[i] & CFXFER)
| ((ultraenb & target_mask) ? 0x8 : 0x0);
if (sc->device_flags[i] & CFWIDEB)
scsirate |= WIDEXFER;
} else {
scsirate = (sc->device_flags[i] & CFXFER) << 4;
if (sc->device_flags[i] & CFSYNCH)
scsirate |= SOFS;
if (sc->device_flags[i] & CFWIDEB)
scsirate |= WIDEXFER;
}
ahc_outb(ahc, TARG_SCSIRATE + i, scsirate);
}
ahc->our_id = sc->brtime_id & CFSCSIID;
scsi_conf = (ahc->our_id & 0x7);
if (sc->adapter_control & CFSPARITY)
scsi_conf |= ENSPCHK;
if (sc->adapter_control & CFRESETB)
scsi_conf |= RESET_SCSI;
ahc->flags |= (sc->adapter_control & CFBOOTCHAN) >> CFBOOTCHANSHIFT;
if (sc->bios_control & CFEXTEND)
ahc->flags |= AHC_EXTENDED_TRANS_A;
if (sc->bios_control & CFBIOSEN)
ahc->flags |= AHC_BIOS_ENABLED;
if (ahc->features & AHC_ULTRA
&& (ahc->flags & AHC_NEWEEPROM_FMT) == 0) {
if (!(sc->adapter_control & CFULTRAEN))
ultraenb = 0;
}
if (sc->signature == CFSIGNATURE
|| sc->signature == CFSIGNATURE2) {
uint32_t devconfig;
devconfig = ahc_pci_read_config(ahc->dev_softc,
DEVCONFIG, 4);
devconfig &= ~STPWLEVEL;
if ((sc->bios_control & CFSTPWLEVEL) != 0)
devconfig |= STPWLEVEL;
ahc_pci_write_config(ahc->dev_softc, DEVCONFIG,
devconfig, 4);
}
ahc_outb(ahc, SCSICONF, scsi_conf);
ahc_outb(ahc, DISC_DSB, ~(discenable & 0xff));
ahc_outb(ahc, DISC_DSB + 1, ~((discenable >> 8) & 0xff));
ahc_outb(ahc, ULTRA_ENB, ultraenb & 0xff);
ahc_outb(ahc, ULTRA_ENB + 1, (ultraenb >> 8) & 0xff);
}
static void
configure_termination(struct ahc_softc *ahc,
struct seeprom_descriptor *sd,
u_int adapter_control,
u_int *sxfrctl1)
{
uint8_t brddat;
brddat = 0;
*sxfrctl1 = 0;
SEEPROM_OUTB(sd, sd->sd_MS | sd->sd_CS);
if ((adapter_control & CFAUTOTERM) != 0
|| (ahc->features & AHC_NEW_TERMCTL) != 0) {
int internal50_present;
int internal68_present;
int externalcable_present;
int eeprom_present;
int enableSEC_low;
int enableSEC_high;
int enablePRI_low;
int enablePRI_high;
int sum;
enableSEC_low = 0;
enableSEC_high = 0;
enablePRI_low = 0;
enablePRI_high = 0;
if ((ahc->features & AHC_NEW_TERMCTL) != 0) {
ahc_new_term_detect(ahc, &enableSEC_low,
&enableSEC_high,
&enablePRI_low,
&enablePRI_high,
&eeprom_present);
if ((adapter_control & CFSEAUTOTERM) == 0) {
if (bootverbose)
printk("%s: Manual SE Termination\n",
ahc_name(ahc));
enableSEC_low = (adapter_control & CFSELOWTERM);
enableSEC_high =
(adapter_control & CFSEHIGHTERM);
}
if ((adapter_control & CFAUTOTERM) == 0) {
if (bootverbose)
printk("%s: Manual LVD Termination\n",
ahc_name(ahc));
enablePRI_low = (adapter_control & CFSTERM);
enablePRI_high = (adapter_control & CFWSTERM);
}
internal50_present = 0;
internal68_present = 1;
externalcable_present = 1;
} else if ((ahc->features & AHC_SPIOCAP) != 0) {
aic785X_cable_detect(ahc, &internal50_present,
&externalcable_present,
&eeprom_present);
internal68_present = 0;
} else {
aic787X_cable_detect(ahc, &internal50_present,
&internal68_present,
&externalcable_present,
&eeprom_present);
}
if ((ahc->features & AHC_WIDE) == 0)
internal68_present = 0;
if (bootverbose
&& (ahc->features & AHC_ULTRA2) == 0) {
printk("%s: internal 50 cable %s present",
ahc_name(ahc),
internal50_present ? "is":"not");
if ((ahc->features & AHC_WIDE) != 0)
printk(", internal 68 cable %s present",
internal68_present ? "is":"not");
printk("\n%s: external cable %s present\n",
ahc_name(ahc),
externalcable_present ? "is":"not");
}
if (bootverbose)
printk("%s: BIOS eeprom %s present\n",
ahc_name(ahc), eeprom_present ? "is" : "not");
if ((ahc->flags & AHC_INT50_SPEEDFLEX) != 0) {
internal50_present = 0;
}
if ((ahc->features & AHC_ULTRA2) == 0
&& (internal50_present != 0)
&& (internal68_present != 0)
&& (externalcable_present != 0)) {
printk("%s: Illegal cable configuration!!. "
"Only two connectors on the "
"adapter may be used at a "
"time!\n", ahc_name(ahc));
internal50_present = 0;
internal68_present = 0;
externalcable_present = 0;
}
if ((ahc->features & AHC_WIDE) != 0
&& ((externalcable_present == 0)
|| (internal68_present == 0)
|| (enableSEC_high != 0))) {
brddat |= BRDDAT6;
if (bootverbose) {
if ((ahc->flags & AHC_INT50_SPEEDFLEX) != 0)
printk("%s: 68 pin termination "
"Enabled\n", ahc_name(ahc));
else
printk("%s: %sHigh byte termination "
"Enabled\n", ahc_name(ahc),
enableSEC_high ? "Secondary "
: "");
}
}
sum = internal50_present + internal68_present
+ externalcable_present;
if (sum < 2 || (enableSEC_low != 0)) {
if ((ahc->features & AHC_ULTRA2) != 0)
brddat |= BRDDAT5;
else
*sxfrctl1 |= STPWEN;
if (bootverbose) {
if ((ahc->flags & AHC_INT50_SPEEDFLEX) != 0)
printk("%s: 50 pin termination "
"Enabled\n", ahc_name(ahc));
else
printk("%s: %sLow byte termination "
"Enabled\n", ahc_name(ahc),
enableSEC_low ? "Secondary "
: "");
}
}
if (enablePRI_low != 0) {
*sxfrctl1 |= STPWEN;
if (bootverbose)
printk("%s: Primary Low Byte termination "
"Enabled\n", ahc_name(ahc));
}
ahc_outb(ahc, SXFRCTL1, *sxfrctl1);
if (enablePRI_high != 0) {
brddat |= BRDDAT4;
if (bootverbose)
printk("%s: Primary High Byte "
"termination Enabled\n",
ahc_name(ahc));
}
write_brdctl(ahc, brddat);
} else {
if ((adapter_control & CFSTERM) != 0) {
*sxfrctl1 |= STPWEN;
if (bootverbose)
printk("%s: %sLow byte termination Enabled\n",
ahc_name(ahc),
(ahc->features & AHC_ULTRA2) ? "Primary "
: "");
}
if ((adapter_control & CFWSTERM) != 0
&& (ahc->features & AHC_WIDE) != 0) {
brddat |= BRDDAT6;
if (bootverbose)
printk("%s: %sHigh byte termination Enabled\n",
ahc_name(ahc),
(ahc->features & AHC_ULTRA2)
? "Secondary " : "");
}
ahc_outb(ahc, SXFRCTL1, *sxfrctl1);
if ((ahc->features & AHC_WIDE) != 0)
write_brdctl(ahc, brddat);
}
SEEPROM_OUTB(sd, sd->sd_MS);
}
static void
ahc_new_term_detect(struct ahc_softc *ahc, int *enableSEC_low,
int *enableSEC_high, int *enablePRI_low,
int *enablePRI_high, int *eeprom_present)
{
uint8_t brdctl;
brdctl = read_brdctl(ahc);
*eeprom_present = brdctl & BRDDAT7;
*enableSEC_high = (brdctl & BRDDAT6);
*enableSEC_low = (brdctl & BRDDAT5);
*enablePRI_high = (brdctl & BRDDAT4);
*enablePRI_low = (brdctl & BRDDAT3);
}
static void
aic787X_cable_detect(struct ahc_softc *ahc, int *internal50_present,
int *internal68_present, int *externalcable_present,
int *eeprom_present)
{
uint8_t brdctl;
write_brdctl(ahc, 0);
brdctl = read_brdctl(ahc);
*internal50_present = (brdctl & BRDDAT6) ? 0 : 1;
*internal68_present = (brdctl & BRDDAT7) ? 0 : 1;
write_brdctl(ahc, BRDDAT5);
brdctl = read_brdctl(ahc);
*externalcable_present = (brdctl & BRDDAT6) ? 0 : 1;
*eeprom_present = (brdctl & BRDDAT7) ? 1 : 0;
}
static void
aic785X_cable_detect(struct ahc_softc *ahc, int *internal50_present,
int *externalcable_present, int *eeprom_present)
{
uint8_t brdctl;
uint8_t spiocap;
spiocap = ahc_inb(ahc, SPIOCAP);
spiocap &= ~SOFTCMDEN;
spiocap |= EXT_BRDCTL;
ahc_outb(ahc, SPIOCAP, spiocap);
ahc_outb(ahc, BRDCTL, BRDRW|BRDCS);
ahc_flush_device_writes(ahc);
ahc_delay(500);
ahc_outb(ahc, BRDCTL, 0);
ahc_flush_device_writes(ahc);
ahc_delay(500);
brdctl = ahc_inb(ahc, BRDCTL);
*internal50_present = (brdctl & BRDDAT5) ? 0 : 1;
*externalcable_present = (brdctl & BRDDAT6) ? 0 : 1;
*eeprom_present = (ahc_inb(ahc, SPIOCAP) & EEPROM) ? 1 : 0;
}
int
ahc_acquire_seeprom(struct ahc_softc *ahc, struct seeprom_descriptor *sd)
{
int wait;
if ((ahc->features & AHC_SPIOCAP) != 0
&& (ahc_inb(ahc, SPIOCAP) & SEEPROM) == 0)
return (0);
SEEPROM_OUTB(sd, sd->sd_MS);
wait = 1000;
while (--wait && ((SEEPROM_STATUS_INB(sd) & sd->sd_RDY) == 0)) {
ahc_delay(1000);
}
if ((SEEPROM_STATUS_INB(sd) & sd->sd_RDY) == 0) {
SEEPROM_OUTB(sd, 0);
return (0);
}
return(1);
}
void
ahc_release_seeprom(struct seeprom_descriptor *sd)
{
SEEPROM_OUTB(sd, 0);
}
static void
write_brdctl(struct ahc_softc *ahc, uint8_t value)
{
uint8_t brdctl;
if ((ahc->chip & AHC_CHIPID_MASK) == AHC_AIC7895) {
brdctl = BRDSTB;
if (ahc->channel == 'B')
brdctl |= BRDCS;
} else if ((ahc->features & AHC_ULTRA2) != 0) {
brdctl = 0;
} else {
brdctl = BRDSTB|BRDCS;
}
ahc_outb(ahc, BRDCTL, brdctl);
ahc_flush_device_writes(ahc);
brdctl |= value;
ahc_outb(ahc, BRDCTL, brdctl);
ahc_flush_device_writes(ahc);
if ((ahc->features & AHC_ULTRA2) != 0)
brdctl |= BRDSTB_ULTRA2;
else
brdctl &= ~BRDSTB;
ahc_outb(ahc, BRDCTL, brdctl);
ahc_flush_device_writes(ahc);
if ((ahc->features & AHC_ULTRA2) != 0)
brdctl = 0;
else
brdctl &= ~BRDCS;
ahc_outb(ahc, BRDCTL, brdctl);
}
static uint8_t
read_brdctl(struct ahc_softc *ahc)
{
uint8_t brdctl;
uint8_t value;
if ((ahc->chip & AHC_CHIPID_MASK) == AHC_AIC7895) {
brdctl = BRDRW;
if (ahc->channel == 'B')
brdctl |= BRDCS;
} else if ((ahc->features & AHC_ULTRA2) != 0) {
brdctl = BRDRW_ULTRA2;
} else {
brdctl = BRDRW|BRDCS;
}
ahc_outb(ahc, BRDCTL, brdctl);
ahc_flush_device_writes(ahc);
value = ahc_inb(ahc, BRDCTL);
ahc_outb(ahc, BRDCTL, 0);
return (value);
}
static void
ahc_pci_intr(struct ahc_softc *ahc)
{
u_int error;
u_int status1;
error = ahc_inb(ahc, ERROR);
if ((error & PCIERRSTAT) == 0)
return;
status1 = ahc_pci_read_config(ahc->dev_softc,
PCIR_STATUS + 1, 1);
printk("%s: PCI error Interrupt at seqaddr = 0x%x\n",
ahc_name(ahc),
ahc_inb(ahc, SEQADDR0) | (ahc_inb(ahc, SEQADDR1) << 8));
if (status1 & DPE) {
ahc->pci_target_perr_count++;
printk("%s: Data Parity Error Detected during address "
"or write data phase\n", ahc_name(ahc));
}
if (status1 & SSE) {
printk("%s: Signal System Error Detected\n", ahc_name(ahc));
}
if (status1 & RMA) {
printk("%s: Received a Master Abort\n", ahc_name(ahc));
}
if (status1 & RTA) {
printk("%s: Received a Target Abort\n", ahc_name(ahc));
}
if (status1 & STA) {
printk("%s: Signaled a Target Abort\n", ahc_name(ahc));
}
if (status1 & DPR) {
printk("%s: Data Parity Error has been reported via PERR#\n",
ahc_name(ahc));
}
ahc_pci_write_config(ahc->dev_softc, PCIR_STATUS + 1,
status1, 1);
if ((status1 & (DPE|SSE|RMA|RTA|STA|DPR)) == 0) {
printk("%s: Latched PCIERR interrupt with "
"no status bits set\n", ahc_name(ahc));
} else {
ahc_outb(ahc, CLRINT, CLRPARERR);
}
if (ahc->pci_target_perr_count > AHC_PCI_TARGET_PERR_THRESH) {
printk(
"%s: WARNING WARNING WARNING WARNING\n"
"%s: Too many PCI parity errors observed as a target.\n"
"%s: Some device on this bus is generating bad parity.\n"
"%s: This is an error *observed by*, not *generated by*, this controller.\n"
"%s: PCI parity error checking has been disabled.\n"
"%s: WARNING WARNING WARNING WARNING\n",
ahc_name(ahc), ahc_name(ahc), ahc_name(ahc),
ahc_name(ahc), ahc_name(ahc), ahc_name(ahc));
ahc->seqctl |= FAILDIS;
ahc_outb(ahc, SEQCTL, ahc->seqctl);
}
ahc_unpause(ahc);
}
static int
ahc_pci_chip_init(struct ahc_softc *ahc)
{
ahc_outb(ahc, DSCOMMAND0, ahc->bus_softc.pci_softc.dscommand0);
ahc_outb(ahc, DSPCISTATUS, ahc->bus_softc.pci_softc.dspcistatus);
if ((ahc->features & AHC_DT) != 0) {
u_int sfunct;
sfunct = ahc_inb(ahc, SFUNCT) & ~ALT_MODE;
ahc_outb(ahc, SFUNCT, sfunct | ALT_MODE);
ahc_outb(ahc, OPTIONMODE, ahc->bus_softc.pci_softc.optionmode);
ahc_outw(ahc, TARGCRCCNT, ahc->bus_softc.pci_softc.targcrccnt);
ahc_outb(ahc, SFUNCT, sfunct);
ahc_outb(ahc, CRCCONTROL1,
ahc->bus_softc.pci_softc.crccontrol1);
}
if ((ahc->features & AHC_MULTI_FUNC) != 0)
ahc_outb(ahc, SCBBADDR, ahc->bus_softc.pci_softc.scbbaddr);
if ((ahc->features & AHC_ULTRA2) != 0)
ahc_outb(ahc, DFF_THRSH, ahc->bus_softc.pci_softc.dff_thrsh);
return (ahc_chip_init(ahc));
}
void
ahc_pci_resume(struct ahc_softc *ahc)
{
ahc_pci_write_config(ahc->dev_softc, DEVCONFIG,
ahc->bus_softc.pci_softc.devconfig, 4);
ahc_pci_write_config(ahc->dev_softc, PCIR_COMMAND,
ahc->bus_softc.pci_softc.command, 1);
ahc_pci_write_config(ahc->dev_softc, CSIZE_LATTIME,
ahc->bus_softc.pci_softc.csize_lattime, 1);
if ((ahc->flags & AHC_HAS_TERM_LOGIC) != 0) {
struct seeprom_descriptor sd;
u_int sxfrctl1;
sd.sd_ahc = ahc;
sd.sd_control_offset = SEECTL;
sd.sd_status_offset = SEECTL;
sd.sd_dataout_offset = SEECTL;
ahc_acquire_seeprom(ahc, &sd);
configure_termination(ahc, &sd,
ahc->seep_config->adapter_control,
&sxfrctl1);
ahc_release_seeprom(&sd);
}
}
static int
ahc_aic785X_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
uint8_t rev;
pci = ahc->dev_softc;
ahc->channel = 'A';
ahc->chip = AHC_AIC7850;
ahc->features = AHC_AIC7850_FE;
ahc->bugs |= AHC_TMODE_WIDEODD_BUG|AHC_CACHETHEN_BUG|AHC_PCI_MWI_BUG;
rev = ahc_pci_read_config(pci, PCIR_REVID, 1);
if (rev >= 1)
ahc->bugs |= AHC_PCI_2_1_RETRY_BUG;
ahc->instruction_ram_size = 512;
return (0);
}
static int
ahc_aic7860_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
uint8_t rev;
pci = ahc->dev_softc;
ahc->channel = 'A';
ahc->chip = AHC_AIC7860;
ahc->features = AHC_AIC7860_FE;
ahc->bugs |= AHC_TMODE_WIDEODD_BUG|AHC_CACHETHEN_BUG|AHC_PCI_MWI_BUG;
rev = ahc_pci_read_config(pci, PCIR_REVID, 1);
if (rev >= 1)
ahc->bugs |= AHC_PCI_2_1_RETRY_BUG;
ahc->instruction_ram_size = 512;
return (0);
}
static int
ahc_apa1480_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7860_setup(ahc);
if (error != 0)
return (error);
ahc->features |= AHC_REMOVABLE;
return (0);
}
static int
ahc_aic7870_setup(struct ahc_softc *ahc)
{
ahc->channel = 'A';
ahc->chip = AHC_AIC7870;
ahc->features = AHC_AIC7870_FE;
ahc->bugs |= AHC_TMODE_WIDEODD_BUG|AHC_CACHETHEN_BUG|AHC_PCI_MWI_BUG;
ahc->instruction_ram_size = 512;
return (0);
}
static int
ahc_aic7870h_setup(struct ahc_softc *ahc)
{
int error = ahc_aic7870_setup(ahc);
ahc->features |= AHC_HVD;
return error;
}
static int
ahc_aha394X_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7870_setup(ahc);
if (error == 0)
error = ahc_aha394XX_setup(ahc);
return (error);
}
static int
ahc_aha394Xh_setup(struct ahc_softc *ahc)
{
int error = ahc_aha394X_setup(ahc);
ahc->features |= AHC_HVD;
return error;
}
static int
ahc_aha398X_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7870_setup(ahc);
if (error == 0)
error = ahc_aha398XX_setup(ahc);
return (error);
}
static int
ahc_aha494X_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7870_setup(ahc);
if (error == 0)
error = ahc_aha494XX_setup(ahc);
return (error);
}
static int
ahc_aha494Xh_setup(struct ahc_softc *ahc)
{
int error = ahc_aha494X_setup(ahc);
ahc->features |= AHC_HVD;
return error;
}
static int
ahc_aic7880_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
uint8_t rev;
pci = ahc->dev_softc;
ahc->channel = 'A';
ahc->chip = AHC_AIC7880;
ahc->features = AHC_AIC7880_FE;
ahc->bugs |= AHC_TMODE_WIDEODD_BUG;
rev = ahc_pci_read_config(pci, PCIR_REVID, 1);
if (rev >= 1) {
ahc->bugs |= AHC_PCI_2_1_RETRY_BUG;
} else {
ahc->bugs |= AHC_CACHETHEN_BUG|AHC_PCI_MWI_BUG;
}
ahc->instruction_ram_size = 512;
return (0);
}
static int
ahc_aic7880h_setup(struct ahc_softc *ahc)
{
int error = ahc_aic7880_setup(ahc);
ahc->features |= AHC_HVD;
return error;
}
static int
ahc_aha2940Pro_setup(struct ahc_softc *ahc)
{
ahc->flags |= AHC_INT50_SPEEDFLEX;
return (ahc_aic7880_setup(ahc));
}
static int
ahc_aha394XU_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7880_setup(ahc);
if (error == 0)
error = ahc_aha394XX_setup(ahc);
return (error);
}
static int
ahc_aha394XUh_setup(struct ahc_softc *ahc)
{
int error = ahc_aha394XU_setup(ahc);
ahc->features |= AHC_HVD;
return error;
}
static int
ahc_aha398XU_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7880_setup(ahc);
if (error == 0)
error = ahc_aha398XX_setup(ahc);
return (error);
}
static int
ahc_aic7890_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
uint8_t rev;
pci = ahc->dev_softc;
ahc->channel = 'A';
ahc->chip = AHC_AIC7890;
ahc->features = AHC_AIC7890_FE;
ahc->flags |= AHC_NEWEEPROM_FMT;
rev = ahc_pci_read_config(pci, PCIR_REVID, 1);
if (rev == 0)
ahc->bugs |= AHC_AUTOFLUSH_BUG|AHC_CACHETHEN_BUG;
ahc->instruction_ram_size = 768;
return (0);
}
static int
ahc_aic7892_setup(struct ahc_softc *ahc)
{
ahc->channel = 'A';
ahc->chip = AHC_AIC7892;
ahc->features = AHC_AIC7892_FE;
ahc->flags |= AHC_NEWEEPROM_FMT;
ahc->bugs |= AHC_SCBCHAN_UPLOAD_BUG;
ahc->instruction_ram_size = 1024;
return (0);
}
static int
ahc_aic7895_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
uint8_t rev;
pci = ahc->dev_softc;
ahc->channel = ahc_get_pci_function(pci) == 1 ? 'B' : 'A';
rev = ahc_pci_read_config(pci, PCIR_REVID, 1);
if (rev >= 4) {
ahc->chip = AHC_AIC7895C;
ahc->features = AHC_AIC7895C_FE;
} else {
u_int command;
ahc->chip = AHC_AIC7895;
ahc->features = AHC_AIC7895_FE;
command = ahc_pci_read_config(pci, PCIR_COMMAND, 1);
command |= PCIM_CMD_MWRICEN;
ahc_pci_write_config(pci, PCIR_COMMAND, command, 1);
ahc->bugs |= AHC_PCI_MWI_BUG;
}
ahc->bugs |= AHC_TMODE_WIDEODD_BUG|AHC_PCI_2_1_RETRY_BUG
| AHC_CACHETHEN_BUG;
#if 0
uint32_t devconfig;
ahc_pci_write_config(pci, CSIZE_LATTIME, 0, 1);
devconfig = ahc_pci_read_config(pci, DEVCONFIG, 1);
devconfig |= MRDCEN;
ahc_pci_write_config(pci, DEVCONFIG, devconfig, 1);
#endif
ahc->flags |= AHC_NEWEEPROM_FMT;
ahc->instruction_ram_size = 512;
return (0);
}
static int
ahc_aic7895h_setup(struct ahc_softc *ahc)
{
int error = ahc_aic7895_setup(ahc);
ahc->features |= AHC_HVD;
return error;
}
static int
ahc_aic7896_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
pci = ahc->dev_softc;
ahc->channel = ahc_get_pci_function(pci) == 1 ? 'B' : 'A';
ahc->chip = AHC_AIC7896;
ahc->features = AHC_AIC7896_FE;
ahc->flags |= AHC_NEWEEPROM_FMT;
ahc->bugs |= AHC_CACHETHEN_DIS_BUG;
ahc->instruction_ram_size = 768;
return (0);
}
static int
ahc_aic7899_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
pci = ahc->dev_softc;
ahc->channel = ahc_get_pci_function(pci) == 1 ? 'B' : 'A';
ahc->chip = AHC_AIC7899;
ahc->features = AHC_AIC7899_FE;
ahc->flags |= AHC_NEWEEPROM_FMT;
ahc->bugs |= AHC_SCBCHAN_UPLOAD_BUG;
ahc->instruction_ram_size = 1024;
return (0);
}
static int
ahc_aha29160C_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7899_setup(ahc);
if (error != 0)
return (error);
ahc->features |= AHC_REMOVABLE;
return (0);
}
static int
ahc_raid_setup(struct ahc_softc *ahc)
{
printk("RAID functionality unsupported\n");
return (ENXIO);
}
static int
ahc_aha394XX_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
pci = ahc->dev_softc;
switch (ahc_get_pci_slot(pci)) {
case AHC_394X_SLOT_CHANNEL_A:
ahc->channel = 'A';
break;
case AHC_394X_SLOT_CHANNEL_B:
ahc->channel = 'B';
break;
default:
printk("adapter at unexpected slot %d\n"
"unable to map to a channel\n",
ahc_get_pci_slot(pci));
ahc->channel = 'A';
}
return (0);
}
static int
ahc_aha398XX_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
pci = ahc->dev_softc;
switch (ahc_get_pci_slot(pci)) {
case AHC_398X_SLOT_CHANNEL_A:
ahc->channel = 'A';
break;
case AHC_398X_SLOT_CHANNEL_B:
ahc->channel = 'B';
break;
case AHC_398X_SLOT_CHANNEL_C:
ahc->channel = 'C';
break;
default:
printk("adapter at unexpected slot %d\n"
"unable to map to a channel\n",
ahc_get_pci_slot(pci));
ahc->channel = 'A';
break;
}
ahc->flags |= AHC_LARGE_SEEPROM;
return (0);
}
static int
ahc_aha494XX_setup(struct ahc_softc *ahc)
{
ahc_dev_softc_t pci;
pci = ahc->dev_softc;
switch (ahc_get_pci_slot(pci)) {
case AHC_494X_SLOT_CHANNEL_A:
ahc->channel = 'A';
break;
case AHC_494X_SLOT_CHANNEL_B:
ahc->channel = 'B';
break;
case AHC_494X_SLOT_CHANNEL_C:
ahc->channel = 'C';
break;
case AHC_494X_SLOT_CHANNEL_D:
ahc->channel = 'D';
break;
default:
printk("adapter at unexpected slot %d\n"
"unable to map to a channel\n",
ahc_get_pci_slot(pci));
ahc->channel = 'A';
}
ahc->flags |= AHC_LARGE_SEEPROM;
return (0);
}
