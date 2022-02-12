struct aic7770_identity *
aic7770_find_device(uint32_t id)
{
struct aic7770_identity *entry;
int i;
for (i = 0; i < ahc_num_aic7770_devs; i++) {
entry = &aic7770_ident_table[i];
if (entry->full_id == (id & entry->id_mask))
return (entry);
}
return (NULL);
}
int
aic7770_config(struct ahc_softc *ahc, struct aic7770_identity *entry, u_int io)
{
int error;
int have_seeprom;
u_int hostconf;
u_int irq;
u_int intdef;
error = entry->setup(ahc);
have_seeprom = 0;
if (error != 0)
return (error);
error = aic7770_map_registers(ahc, io);
if (error != 0)
return (error);
ahc_intr_enable(ahc, FALSE);
ahc->description = entry->name;
error = ahc_softc_init(ahc);
if (error != 0)
return (error);
ahc->bus_chip_init = aic7770_chip_init;
error = ahc_reset(ahc, FALSE);
if (error != 0)
return (error);
intdef = ahc_inb(ahc, INTDEF);
irq = intdef & VECTOR;
switch (irq) {
case 9:
case 10:
case 11:
case 12:
case 14:
case 15:
break;
default:
printk("aic7770_config: invalid irq setting %d\n", intdef);
return (ENXIO);
}
if ((intdef & EDGE_TRIG) != 0)
ahc->flags |= AHC_EDGE_INTERRUPT;
switch (ahc->chip & (AHC_EISA|AHC_VL)) {
case AHC_EISA:
{
u_int biosctrl;
u_int scsiconf;
u_int scsiconf1;
biosctrl = ahc_inb(ahc, HA_274_BIOSCTRL);
scsiconf = ahc_inb(ahc, SCSICONF);
scsiconf1 = ahc_inb(ahc, SCSICONF + 1);
if ((biosctrl & CHANNEL_B_PRIMARY) != 0)
ahc->flags |= 1;
if ((biosctrl & BIOSMODE) == BIOSDISABLED) {
ahc->flags |= AHC_USEDEFAULTS;
} else {
if ((ahc->features & AHC_WIDE) != 0) {
ahc->our_id = scsiconf1 & HWSCSIID;
if (scsiconf & TERM_ENB)
ahc->flags |= AHC_TERM_ENB_A;
} else {
ahc->our_id = scsiconf & HSCSIID;
ahc->our_id_b = scsiconf1 & HSCSIID;
if (scsiconf & TERM_ENB)
ahc->flags |= AHC_TERM_ENB_A;
if (scsiconf1 & TERM_ENB)
ahc->flags |= AHC_TERM_ENB_B;
}
}
if ((ahc_inb(ahc, HA_274_BIOSGLOBAL) & HA_274_EXTENDED_TRANS))
ahc->flags |= AHC_EXTENDED_TRANS_A|AHC_EXTENDED_TRANS_B;
break;
}
case AHC_VL:
{
have_seeprom = aha2840_load_seeprom(ahc);
break;
}
default:
break;
}
if (have_seeprom == 0) {
kfree(ahc->seep_config);
ahc->seep_config = NULL;
}
ahc_outb(ahc, SBLKCTL, ahc_inb(ahc, SBLKCTL) & ~AUTOFLUSHDIS);
hostconf = ahc_inb(ahc, HOSTCONF);
ahc_outb(ahc, BUSSPD, hostconf & DFTHRSH);
ahc_outb(ahc, BUSTIME, (hostconf << 2) & BOFF);
ahc->bus_softc.aic7770_softc.busspd = hostconf & DFTHRSH;
ahc->bus_softc.aic7770_softc.bustime = (hostconf << 2) & BOFF;
error = ahc_init(ahc);
if (error != 0)
return (error);
error = aic7770_map_int(ahc, irq);
if (error != 0)
return (error);
ahc->init_level++;
ahc_outb(ahc, BCTL, ENABLE);
return (0);
}
static int
aic7770_chip_init(struct ahc_softc *ahc)
{
ahc_outb(ahc, BUSSPD, ahc->bus_softc.aic7770_softc.busspd);
ahc_outb(ahc, BUSTIME, ahc->bus_softc.aic7770_softc.bustime);
ahc_outb(ahc, SBLKCTL, ahc_inb(ahc, SBLKCTL) & ~AUTOFLUSHDIS);
ahc_outb(ahc, BCTL, ENABLE);
return (ahc_chip_init(ahc));
}
static int
aha2840_load_seeprom(struct ahc_softc *ahc)
{
struct seeprom_descriptor sd;
struct seeprom_config *sc;
int have_seeprom;
uint8_t scsi_conf;
sd.sd_ahc = ahc;
sd.sd_control_offset = SEECTL_2840;
sd.sd_status_offset = STATUS_2840;
sd.sd_dataout_offset = STATUS_2840;
sd.sd_chip = C46;
sd.sd_MS = 0;
sd.sd_RDY = EEPROM_TF;
sd.sd_CS = CS_2840;
sd.sd_CK = CK_2840;
sd.sd_DO = DO_2840;
sd.sd_DI = DI_2840;
sc = ahc->seep_config;
if (bootverbose)
printk("%s: Reading SEEPROM...", ahc_name(ahc));
have_seeprom = ahc_read_seeprom(&sd, (uint16_t *)sc,
0, sizeof(*sc)/2);
if (have_seeprom) {
if (ahc_verify_cksum(sc) == 0) {
if(bootverbose)
printk ("checksum error\n");
have_seeprom = 0;
} else if (bootverbose) {
printk("done.\n");
}
}
if (!have_seeprom) {
if (bootverbose)
printk("%s: No SEEPROM available\n", ahc_name(ahc));
ahc->flags |= AHC_USEDEFAULTS;
} else {
int i;
int max_targ;
uint16_t discenable;
max_targ = (ahc->features & AHC_WIDE) != 0 ? 16 : 8;
discenable = 0;
for (i = 0; i < max_targ; i++){
uint8_t target_settings;
target_settings = (sc->device_flags[i] & CFXFER) << 4;
if (sc->device_flags[i] & CFSYNCH)
target_settings |= SOFS;
if (sc->device_flags[i] & CFWIDEB)
target_settings |= WIDEXFER;
if (sc->device_flags[i] & CFDISC)
discenable |= (0x01 << i);
ahc_outb(ahc, TARG_SCSIRATE + i, target_settings);
}
ahc_outb(ahc, DISC_DSB, ~(discenable & 0xff));
ahc_outb(ahc, DISC_DSB + 1, ~((discenable >> 8) & 0xff));
ahc->our_id = sc->brtime_id & CFSCSIID;
scsi_conf = (ahc->our_id & 0x7);
if (sc->adapter_control & CFSPARITY)
scsi_conf |= ENSPCHK;
if (sc->adapter_control & CFRESETB)
scsi_conf |= RESET_SCSI;
if (sc->bios_control & CF284XEXTEND)
ahc->flags |= AHC_EXTENDED_TRANS_A;
ahc_outb(ahc, SCSICONF, scsi_conf);
if (sc->adapter_control & CF284XSTERM)
ahc->flags |= AHC_TERM_ENB_A;
}
return (have_seeprom);
}
static int
ahc_aic7770_VL_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7770_setup(ahc);
ahc->chip |= AHC_VL;
return (error);
}
static int
ahc_aic7770_EISA_setup(struct ahc_softc *ahc)
{
int error;
error = ahc_aic7770_setup(ahc);
ahc->chip |= AHC_EISA;
return (error);
}
static int
ahc_aic7770_setup(struct ahc_softc *ahc)
{
ahc->channel = 'A';
ahc->channel_b = 'B';
ahc->chip = AHC_AIC7770;
ahc->features = AHC_AIC7770_FE;
ahc->bugs |= AHC_TMODE_WIDEODD_BUG;
ahc->flags |= AHC_PAGESCBS;
ahc->instruction_ram_size = 448;
return (0);
}
