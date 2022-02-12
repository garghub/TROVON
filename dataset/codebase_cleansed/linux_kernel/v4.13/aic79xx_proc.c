static u_int
ahd_calc_syncsrate(u_int period_factor)
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
ahd_format_transinfo(struct seq_file *m, struct ahd_transinfo *tinfo)
{
u_int speed;
u_int freq;
u_int mb;
if (tinfo->period == AHD_PERIOD_UNKNOWN) {
seq_puts(m, "Renegotiation Pending\n");
return;
}
speed = 3300;
freq = 0;
if (tinfo->offset != 0) {
freq = ahd_calc_syncsrate(tinfo->period);
speed = freq;
}
speed *= (0x01 << tinfo->width);
mb = speed / 1000;
if (mb > 0)
seq_printf(m, "%d.%03dMB/s transfers", mb, speed % 1000);
else
seq_printf(m, "%dKB/s transfers", speed);
if (freq != 0) {
int printed_options;
printed_options = 0;
seq_printf(m, " (%d.%03dMHz", freq / 1000, freq % 1000);
if ((tinfo->ppr_options & MSG_EXT_PPR_RD_STRM) != 0) {
seq_puts(m, " RDSTRM");
printed_options++;
}
if ((tinfo->ppr_options & MSG_EXT_PPR_DT_REQ) != 0) {
seq_puts(m, printed_options ? "|DT" : " DT");
printed_options++;
}
if ((tinfo->ppr_options & MSG_EXT_PPR_IU_REQ) != 0) {
seq_puts(m, printed_options ? "|IU" : " IU");
printed_options++;
}
if ((tinfo->ppr_options & MSG_EXT_PPR_RTI) != 0) {
seq_puts(m, printed_options ? "|RTI" : " RTI");
printed_options++;
}
if ((tinfo->ppr_options & MSG_EXT_PPR_QAS_REQ) != 0) {
seq_puts(m, printed_options ? "|QAS" : " QAS");
printed_options++;
}
}
if (tinfo->width > 0) {
if (freq != 0) {
seq_puts(m, ", ");
} else {
seq_puts(m, " (");
}
seq_printf(m, "%dbit)", 8 * (0x01 << tinfo->width));
} else if (freq != 0) {
seq_putc(m, ')');
}
seq_putc(m, '\n');
}
static void
ahd_dump_target_state(struct ahd_softc *ahd, struct seq_file *m,
u_int our_id, char channel, u_int target_id)
{
struct scsi_target *starget;
struct ahd_initiator_tinfo *tinfo;
struct ahd_tmode_tstate *tstate;
int lun;
tinfo = ahd_fetch_transinfo(ahd, channel, our_id,
target_id, &tstate);
seq_printf(m, "Target %d Negotiation Settings\n", target_id);
seq_puts(m, "\tUser: ");
ahd_format_transinfo(m, &tinfo->user);
starget = ahd->platform_data->starget[target_id];
if (starget == NULL)
return;
seq_puts(m, "\tGoal: ");
ahd_format_transinfo(m, &tinfo->goal);
seq_puts(m, "\tCurr: ");
ahd_format_transinfo(m, &tinfo->curr);
for (lun = 0; lun < AHD_NUM_LUNS; lun++) {
struct scsi_device *dev;
dev = scsi_device_lookup_by_target(starget, lun);
if (dev == NULL)
continue;
ahd_dump_device_state(m, dev);
}
}
static void
ahd_dump_device_state(struct seq_file *m, struct scsi_device *sdev)
{
struct ahd_linux_device *dev = scsi_transport_device_data(sdev);
seq_printf(m, "\tChannel %c Target %d Lun %d Settings\n",
sdev->sdev_target->channel + 'A',
sdev->sdev_target->id, (u8)sdev->lun);
seq_printf(m, "\t\tCommands Queued %ld\n", dev->commands_issued);
seq_printf(m, "\t\tCommands Active %d\n", dev->active);
seq_printf(m, "\t\tCommand Openings %d\n", dev->openings);
seq_printf(m, "\t\tMax Tagged Openings %d\n", dev->maxtags);
seq_printf(m, "\t\tDevice Queue Frozen Count %d\n", dev->qfrozen);
}
int
ahd_proc_write_seeprom(struct Scsi_Host *shost, char *buffer, int length)
{
struct ahd_softc *ahd = *(struct ahd_softc **)shost->hostdata;
ahd_mode_state saved_modes;
int have_seeprom;
u_long s;
int paused;
int written;
written = -EINVAL;
ahd_lock(ahd, &s);
paused = ahd_is_paused(ahd);
if (!paused)
ahd_pause(ahd);
saved_modes = ahd_save_modes(ahd);
ahd_set_modes(ahd, AHD_MODE_SCSI, AHD_MODE_SCSI);
if (length != sizeof(struct seeprom_config)) {
printk("ahd_proc_write_seeprom: incorrect buffer size\n");
goto done;
}
have_seeprom = ahd_verify_cksum((struct seeprom_config*)buffer);
if (have_seeprom == 0) {
printk("ahd_proc_write_seeprom: cksum verification failed\n");
goto done;
}
have_seeprom = ahd_acquire_seeprom(ahd);
if (!have_seeprom) {
printk("ahd_proc_write_seeprom: No Serial EEPROM\n");
goto done;
} else {
u_int start_addr;
if (ahd->seep_config == NULL) {
ahd->seep_config = kmalloc(sizeof(*ahd->seep_config), GFP_ATOMIC);
if (ahd->seep_config == NULL) {
printk("aic79xx: Unable to allocate serial "
"eeprom buffer. Write failing\n");
goto done;
}
}
printk("aic79xx: Writing Serial EEPROM\n");
start_addr = 32 * (ahd->channel - 'A');
ahd_write_seeprom(ahd, (u_int16_t *)buffer, start_addr,
sizeof(struct seeprom_config)/2);
ahd_read_seeprom(ahd, (uint16_t *)ahd->seep_config,
start_addr, sizeof(struct seeprom_config)/2,
FALSE);
ahd_release_seeprom(ahd);
written = length;
}
done:
ahd_restore_modes(ahd, saved_modes);
if (!paused)
ahd_unpause(ahd);
ahd_unlock(ahd, &s);
return (written);
}
int
ahd_linux_show_info(struct seq_file *m, struct Scsi_Host *shost)
{
struct ahd_softc *ahd = *(struct ahd_softc **)shost->hostdata;
char ahd_info[256];
u_int max_targ;
u_int i;
seq_printf(m, "Adaptec AIC79xx driver version: %s\n",
AIC79XX_DRIVER_VERSION);
seq_printf(m, "%s\n", ahd->description);
ahd_controller_info(ahd, ahd_info);
seq_printf(m, "%s\n", ahd_info);
seq_printf(m, "Allocated SCBs: %d, SG List Length: %d\n\n",
ahd->scb_data.numscbs, AHD_NSEG);
max_targ = 16;
if (ahd->seep_config == NULL)
seq_puts(m, "No Serial EEPROM\n");
else {
seq_puts(m, "Serial EEPROM:\n");
for (i = 0; i < sizeof(*ahd->seep_config)/2; i++) {
if (((i % 8) == 0) && (i != 0)) {
seq_putc(m, '\n');
}
seq_printf(m, "0x%.4x ",
((uint16_t*)ahd->seep_config)[i]);
}
seq_putc(m, '\n');
}
seq_putc(m, '\n');
if ((ahd->features & AHD_WIDE) == 0)
max_targ = 8;
for (i = 0; i < max_targ; i++) {
ahd_dump_target_state(ahd, m, ahd->our_id, 'A',
i);
}
return 0;
}
