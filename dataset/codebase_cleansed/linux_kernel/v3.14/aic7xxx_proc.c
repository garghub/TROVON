static u_int
ahc_calc_syncsrate(u_int period_factor)
{
int i;
for (i = 0; i < ARRAY_SIZE(scsi_syncrates); i++) {
if (period_factor == scsi_syncrates[i].period_factor) {
return (100000000 / scsi_syncrates[i].period);
}
}
return (10000000 / (period_factor * 4 * 10));
}
static void
ahc_format_transinfo(struct seq_file *m, struct ahc_transinfo *tinfo)
{
u_int speed;
u_int freq;
u_int mb;
speed = 3300;
freq = 0;
if (tinfo->offset != 0) {
freq = ahc_calc_syncsrate(tinfo->period);
speed = freq;
}
speed *= (0x01 << tinfo->width);
mb = speed / 1000;
if (mb > 0)
seq_printf(m, "%d.%03dMB/s transfers", mb, speed % 1000);
else
seq_printf(m, "%dKB/s transfers", speed);
if (freq != 0) {
seq_printf(m, " (%d.%03dMHz%s, offset %d",
freq / 1000, freq % 1000,
(tinfo->ppr_options & MSG_EXT_PPR_DT_REQ) != 0
? " DT" : "", tinfo->offset);
}
if (tinfo->width > 0) {
if (freq != 0) {
seq_printf(m, ", ");
} else {
seq_printf(m, " (");
}
seq_printf(m, "%dbit)", 8 * (0x01 << tinfo->width));
} else if (freq != 0) {
seq_printf(m, ")");
}
seq_printf(m, "\n");
}
static void
ahc_dump_target_state(struct ahc_softc *ahc, struct seq_file *m,
u_int our_id, char channel, u_int target_id,
u_int target_offset)
{
struct scsi_target *starget;
struct ahc_initiator_tinfo *tinfo;
struct ahc_tmode_tstate *tstate;
int lun;
tinfo = ahc_fetch_transinfo(ahc, channel, our_id,
target_id, &tstate);
if ((ahc->features & AHC_TWIN) != 0)
seq_printf(m, "Channel %c ", channel);
seq_printf(m, "Target %d Negotiation Settings\n", target_id);
seq_printf(m, "\tUser: ");
ahc_format_transinfo(m, &tinfo->user);
starget = ahc->platform_data->starget[target_offset];
if (!starget)
return;
seq_printf(m, "\tGoal: ");
ahc_format_transinfo(m, &tinfo->goal);
seq_printf(m, "\tCurr: ");
ahc_format_transinfo(m, &tinfo->curr);
for (lun = 0; lun < AHC_NUM_LUNS; lun++) {
struct scsi_device *sdev;
sdev = scsi_device_lookup_by_target(starget, lun);
if (sdev == NULL)
continue;
ahc_dump_device_state(m, sdev);
}
}
static void
ahc_dump_device_state(struct seq_file *m, struct scsi_device *sdev)
{
struct ahc_linux_device *dev = scsi_transport_device_data(sdev);
seq_printf(m, "\tChannel %c Target %d Lun %d Settings\n",
sdev->sdev_target->channel + 'A',
sdev->sdev_target->id, sdev->lun);
seq_printf(m, "\t\tCommands Queued %ld\n", dev->commands_issued);
seq_printf(m, "\t\tCommands Active %d\n", dev->active);
seq_printf(m, "\t\tCommand Openings %d\n", dev->openings);
seq_printf(m, "\t\tMax Tagged Openings %d\n", dev->maxtags);
seq_printf(m, "\t\tDevice Queue Frozen Count %d\n", dev->qfrozen);
}
int
ahc_proc_write_seeprom(struct Scsi_Host *shost, char *buffer, int length)
{
struct ahc_softc *ahc = *(struct ahc_softc **)shost->hostdata;
struct seeprom_descriptor sd;
int have_seeprom;
u_long s;
int paused;
int written;
written = -EINVAL;
ahc_lock(ahc, &s);
paused = ahc_is_paused(ahc);
if (!paused)
ahc_pause(ahc);
if (length != sizeof(struct seeprom_config)) {
printk("ahc_proc_write_seeprom: incorrect buffer size\n");
goto done;
}
have_seeprom = ahc_verify_cksum((struct seeprom_config*)buffer);
if (have_seeprom == 0) {
printk("ahc_proc_write_seeprom: cksum verification failed\n");
goto done;
}
sd.sd_ahc = ahc;
#if AHC_PCI_CONFIG > 0
if ((ahc->chip & AHC_PCI) != 0) {
sd.sd_control_offset = SEECTL;
sd.sd_status_offset = SEECTL;
sd.sd_dataout_offset = SEECTL;
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
} else
#endif
if ((ahc->chip & AHC_VL) != 0) {
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
have_seeprom = TRUE;
} else {
printk("ahc_proc_write_seeprom: unsupported adapter type\n");
goto done;
}
if (!have_seeprom) {
printk("ahc_proc_write_seeprom: No Serial EEPROM\n");
goto done;
} else {
u_int start_addr;
if (ahc->seep_config == NULL) {
ahc->seep_config = kmalloc(sizeof(*ahc->seep_config), GFP_ATOMIC);
if (ahc->seep_config == NULL) {
printk("aic7xxx: Unable to allocate serial "
"eeprom buffer. Write failing\n");
goto done;
}
}
printk("aic7xxx: Writing Serial EEPROM\n");
start_addr = 32 * (ahc->channel - 'A');
ahc_write_seeprom(&sd, (u_int16_t *)buffer, start_addr,
sizeof(struct seeprom_config)/2);
ahc_read_seeprom(&sd, (uint16_t *)ahc->seep_config,
start_addr, sizeof(struct seeprom_config)/2);
#if AHC_PCI_CONFIG > 0
if ((ahc->chip & AHC_VL) == 0)
ahc_release_seeprom(&sd);
#endif
written = length;
}
done:
if (!paused)
ahc_unpause(ahc);
ahc_unlock(ahc, &s);
return (written);
}
int
ahc_linux_show_info(struct seq_file *m, struct Scsi_Host *shost)
{
struct ahc_softc *ahc = *(struct ahc_softc **)shost->hostdata;
char ahc_info[256];
u_int max_targ;
u_int i;
seq_printf(m, "Adaptec AIC7xxx driver version: %s\n",
AIC7XXX_DRIVER_VERSION);
seq_printf(m, "%s\n", ahc->description);
ahc_controller_info(ahc, ahc_info);
seq_printf(m, "%s\n", ahc_info);
seq_printf(m, "Allocated SCBs: %d, SG List Length: %d\n\n",
ahc->scb_data->numscbs, AHC_NSEG);
if (ahc->seep_config == NULL)
seq_printf(m, "No Serial EEPROM\n");
else {
seq_printf(m, "Serial EEPROM:\n");
for (i = 0; i < sizeof(*ahc->seep_config)/2; i++) {
if (((i % 8) == 0) && (i != 0)) {
seq_printf(m, "\n");
}
seq_printf(m, "0x%.4x ",
((uint16_t*)ahc->seep_config)[i]);
}
seq_printf(m, "\n");
}
seq_printf(m, "\n");
max_targ = 16;
if ((ahc->features & (AHC_WIDE|AHC_TWIN)) == 0)
max_targ = 8;
for (i = 0; i < max_targ; i++) {
u_int our_id;
u_int target_id;
char channel;
channel = 'A';
our_id = ahc->our_id;
target_id = i;
if (i > 7 && (ahc->features & AHC_TWIN) != 0) {
channel = 'B';
our_id = ahc->our_id_b;
target_id = i % 8;
}
ahc_dump_target_state(ahc, m, our_id,
channel, target_id, i);
}
return 0;
}
