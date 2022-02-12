static int smart_enable(ide_drive_t *drive)
{
struct ide_cmd cmd;
struct ide_taskfile *tf = &cmd.tf;
memset(&cmd, 0, sizeof(cmd));
tf->feature = ATA_SMART_ENABLE;
tf->lbam = ATA_SMART_LBAM_PASS;
tf->lbah = ATA_SMART_LBAH_PASS;
tf->command = ATA_CMD_SMART;
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
return ide_no_data_taskfile(drive, &cmd);
}
static int get_smart_data(ide_drive_t *drive, u8 *buf, u8 sub_cmd)
{
struct ide_cmd cmd;
struct ide_taskfile *tf = &cmd.tf;
memset(&cmd, 0, sizeof(cmd));
tf->feature = sub_cmd;
tf->nsect = 0x01;
tf->lbam = ATA_SMART_LBAM_PASS;
tf->lbah = ATA_SMART_LBAH_PASS;
tf->command = ATA_CMD_SMART;
cmd.valid.out.tf = IDE_VALID_OUT_TF | IDE_VALID_DEVICE;
cmd.valid.in.tf = IDE_VALID_IN_TF | IDE_VALID_DEVICE;
cmd.protocol = ATA_PROT_PIO;
return ide_raw_taskfile(drive, &cmd, buf, 1);
}
static int idedisk_cache_proc_show(struct seq_file *m, void *v)
{
ide_drive_t *drive = (ide_drive_t *) m->private;
if (drive->dev_flags & IDE_DFLAG_ID_READ)
seq_printf(m, "%i\n", drive->id[ATA_ID_BUF_SIZE] / 2);
else
seq_printf(m, "(none)\n");
return 0;
}
static int idedisk_cache_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, idedisk_cache_proc_show, PDE(inode)->data);
}
static int idedisk_capacity_proc_show(struct seq_file *m, void *v)
{
ide_drive_t*drive = (ide_drive_t *)m->private;
seq_printf(m, "%llu\n", (long long)ide_gd_capacity(drive));
return 0;
}
static int idedisk_capacity_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, idedisk_capacity_proc_show, PDE(inode)->data);
}
static int __idedisk_proc_show(struct seq_file *m, ide_drive_t *drive, u8 sub_cmd)
{
u8 *buf;
buf = kmalloc(SECTOR_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
(void)smart_enable(drive);
if (get_smart_data(drive, buf, sub_cmd) == 0) {
__le16 *val = (__le16 *)buf;
int i;
for (i = 0; i < SECTOR_SIZE / 2; i++) {
seq_printf(m, "%04x%c", le16_to_cpu(val[i]),
(i % 8) == 7 ? '\n' : ' ');
}
}
kfree(buf);
return 0;
}
static int idedisk_sv_proc_show(struct seq_file *m, void *v)
{
return __idedisk_proc_show(m, m->private, ATA_SMART_READ_VALUES);
}
static int idedisk_sv_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, idedisk_sv_proc_show, PDE(inode)->data);
}
static int idedisk_st_proc_show(struct seq_file *m, void *v)
{
return __idedisk_proc_show(m, m->private, ATA_SMART_READ_THRESHOLDS);
}
static int idedisk_st_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, idedisk_st_proc_show, PDE(inode)->data);
}
