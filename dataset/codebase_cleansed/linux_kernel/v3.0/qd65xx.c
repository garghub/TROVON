static void qd65xx_dev_select(ide_drive_t *drive)
{
u8 index = (( (QD_TIMREG(drive)) & 0x80 ) >> 7) |
(QD_TIMREG(drive) & 0x02);
if (timings[index] != QD_TIMING(drive))
outb(timings[index] = QD_TIMING(drive), QD_TIMREG(drive));
outb(drive->select | ATA_DEVICE_OBS, drive->hwif->io_ports.device_addr);
}
static u8 qd6500_compute_timing (ide_hwif_t *hwif, int active_time, int recovery_time)
{
int clk = ide_vlb_clk ? ide_vlb_clk : 50;
u8 act_cyc, rec_cyc;
if (clk <= 33) {
act_cyc = 9 - IDE_IN(active_time * clk / 1000 + 1, 2, 9);
rec_cyc = 15 - IDE_IN(recovery_time * clk / 1000 + 1, 0, 15);
} else {
act_cyc = 8 - IDE_IN(active_time * clk / 1000 + 1, 1, 8);
rec_cyc = 18 - IDE_IN(recovery_time * clk / 1000 + 1, 3, 18);
}
return (rec_cyc << 4) | 0x08 | act_cyc;
}
static u8 qd6580_compute_timing (int active_time, int recovery_time)
{
int clk = ide_vlb_clk ? ide_vlb_clk : 50;
u8 act_cyc, rec_cyc;
act_cyc = 17 - IDE_IN(active_time * clk / 1000 + 1, 2, 17);
rec_cyc = 15 - IDE_IN(recovery_time * clk / 1000 + 1, 2, 15);
return (rec_cyc << 4) | act_cyc;
}
static int qd_find_disk_type (ide_drive_t *drive,
int *active_time, int *recovery_time)
{
struct qd65xx_timing_s *p;
char *m = (char *)&drive->id[ATA_ID_PROD];
char model[ATA_ID_PROD_LEN];
if (*m == 0)
return 0;
strncpy(model, m, ATA_ID_PROD_LEN);
ide_fixstring(model, ATA_ID_PROD_LEN, 1);
for (p = qd65xx_timing ; p->offset != -1 ; p++) {
if (!strncmp(p->model, model+p->offset, 4)) {
printk(KERN_DEBUG "%s: listed !\n", drive->name);
*active_time = p->active;
*recovery_time = p->recovery;
return 1;
}
}
return 0;
}
static void qd_set_timing (ide_drive_t *drive, u8 timing)
{
unsigned long data = (unsigned long)ide_get_drivedata(drive);
data &= 0xff00;
data |= timing;
ide_set_drivedata(drive, (void *)data);
printk(KERN_DEBUG "%s: %#x\n", drive->name, timing);
}
static void qd6500_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
u16 *id = drive->id;
int active_time = 175;
int recovery_time = 415;
if (!qd_find_disk_type(drive, &active_time, &recovery_time) &&
(id[ATA_ID_OLD_PIO_MODES] & 0xff) && (id[ATA_ID_FIELD_VALID] & 2) &&
id[ATA_ID_EIDE_PIO] >= 240) {
printk(KERN_INFO "%s: PIO mode%d\n", drive->name,
id[ATA_ID_OLD_PIO_MODES] & 0xff);
active_time = 110;
recovery_time = drive->id[ATA_ID_EIDE_PIO] - 120;
}
qd_set_timing(drive, qd6500_compute_timing(drive->hwif,
active_time, recovery_time));
}
static void qd6580_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
const u8 pio = drive->pio_mode - XFER_PIO_0;
struct ide_timing *t = ide_timing_find_mode(XFER_PIO_0 + pio);
unsigned int cycle_time;
int active_time = 175;
int recovery_time = 415;
u8 base = (hwif->config_data & 0xff00) >> 8;
if (drive->id && !qd_find_disk_type(drive, &active_time, &recovery_time)) {
cycle_time = ide_pio_cycle_time(drive, pio);
switch (pio) {
case 0: break;
case 3:
if (cycle_time >= 110) {
active_time = 86;
recovery_time = cycle_time - 102;
} else
printk(KERN_WARNING "%s: Strange recovery time !\n",drive->name);
break;
case 4:
if (cycle_time >= 69) {
active_time = 70;
recovery_time = cycle_time - 61;
} else
printk(KERN_WARNING "%s: Strange recovery time !\n",drive->name);
break;
default:
if (cycle_time >= 180) {
active_time = 110;
recovery_time = cycle_time - 120;
} else {
active_time = t->active;
recovery_time = cycle_time - active_time;
}
}
printk(KERN_INFO "%s: PIO mode%d\n", drive->name,pio);
}
if (!hwif->channel && drive->media != ide_disk) {
outb(0x5f, QD_CONTROL_PORT);
printk(KERN_WARNING "%s: ATAPI: disabled read-ahead FIFO "
"and post-write buffer on %s.\n",
drive->name, hwif->name);
}
qd_set_timing(drive, qd6580_compute_timing(active_time, recovery_time));
}
static int __init qd_testreg(int port)
{
unsigned long flags;
u8 savereg, readreg;
local_irq_save(flags);
savereg = inb_p(port);
outb_p(QD_TESTVAL, port);
readreg = inb_p(port);
outb(savereg, port);
local_irq_restore(flags);
if (savereg == QD_TESTVAL) {
printk(KERN_ERR "Outch ! the probe for qd65xx isn't reliable !\n");
printk(KERN_ERR "Please contact maintainers to tell about your hardware\n");
printk(KERN_ERR "Assuming qd65xx is not present.\n");
return 1;
}
return (readreg != QD_TESTVAL);
}
static void __init qd6500_init_dev(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u8 base = (hwif->config_data & 0xff00) >> 8;
u8 config = QD_CONFIG(hwif);
ide_set_drivedata(drive, (void *)QD6500_DEF_DATA);
}
static void __init qd6580_init_dev(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
u16 t1, t2;
u8 base = (hwif->config_data & 0xff00) >> 8;
u8 config = QD_CONFIG(hwif);
if (hwif->host_flags & IDE_HFLAG_SINGLE) {
t1 = QD6580_DEF_DATA;
t2 = QD6580_DEF_DATA2;
} else
t2 = t1 = hwif->channel ? QD6580_DEF_DATA2 : QD6580_DEF_DATA;
ide_set_drivedata(drive, (void *)((drive->dn & 1) ? t2 : t1));
}
static int __init qd_probe(int base)
{
int rc;
u8 config, unit, control;
struct ide_port_info d = qd65xx_port_info;
config = inb(QD_CONFIG_PORT);
if (! ((config & QD_CONFIG_BASEPORT) >> 1 == (base == 0xb0)) )
return -ENODEV;
unit = ! (config & QD_CONFIG_IDE_BASEPORT);
if (unit)
d.host_flags |= IDE_HFLAG_QD_2ND_PORT;
switch (config & 0xf0) {
case QD_CONFIG_QD6500:
if (qd_testreg(base))
return -ENODEV;
if (config & QD_CONFIG_DISABLED) {
printk(KERN_WARNING "qd6500 is disabled !\n");
return -ENODEV;
}
printk(KERN_NOTICE "qd6500 at %#x\n", base);
printk(KERN_DEBUG "qd6500: config=%#x, ID3=%u\n",
config, QD_ID3);
d.port_ops = &qd6500_port_ops;
d.host_flags |= IDE_HFLAG_SINGLE;
break;
case QD_CONFIG_QD6580_A:
case QD_CONFIG_QD6580_B:
if (qd_testreg(base) || qd_testreg(base + 0x02))
return -ENODEV;
control = inb(QD_CONTROL_PORT);
printk(KERN_NOTICE "qd6580 at %#x\n", base);
printk(KERN_DEBUG "qd6580: config=%#x, control=%#x, ID3=%u\n",
config, control, QD_ID3);
outb(QD_DEF_CONTR, QD_CONTROL_PORT);
d.port_ops = &qd6580_port_ops;
if (control & QD_CONTR_SEC_DISABLED)
d.host_flags |= IDE_HFLAG_SINGLE;
printk(KERN_INFO "qd6580: %s IDE board\n",
(control & QD_CONTR_SEC_DISABLED) ? "single" : "dual");
break;
default:
return -ENODEV;
}
rc = ide_legacy_device_add(&d, (base << 8) | config);
if (d.host_flags & IDE_HFLAG_SINGLE)
return (rc == 0) ? 1 : rc;
return rc;
}
static int __init qd65xx_init(void)
{
int rc1, rc2 = -ENODEV;
if (probe_qd65xx == 0)
return -ENODEV;
rc1 = qd_probe(0x30);
if (rc1)
rc2 = qd_probe(0xb0);
if (rc1 < 0 && rc2 < 0)
return -ENODEV;
return 0;
}
