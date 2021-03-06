static int ide_imodel_proc_show(struct seq_file *m, void *v)
{
ide_hwif_t *hwif = (ide_hwif_t *) m->private;
const char *name;
switch (hwif->chipset) {
case ide_generic: name = "generic"; break;
case ide_pci: name = "pci"; break;
case ide_cmd640: name = "cmd640"; break;
case ide_dtc2278: name = "dtc2278"; break;
case ide_ali14xx: name = "ali14xx"; break;
case ide_qd65xx: name = "qd65xx"; break;
case ide_umc8672: name = "umc8672"; break;
case ide_ht6560b: name = "ht6560b"; break;
case ide_4drives: name = "4drives"; break;
case ide_pmac: name = "mac-io"; break;
case ide_au1xxx: name = "au1xxx"; break;
case ide_palm3710: name = "palm3710"; break;
case ide_acorn: name = "acorn"; break;
default: name = "(unknown)"; break;
}
seq_printf(m, "%s\n", name);
return 0;
}
static int ide_imodel_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_imodel_proc_show, PDE(inode)->data);
}
static int ide_mate_proc_show(struct seq_file *m, void *v)
{
ide_hwif_t *hwif = (ide_hwif_t *) m->private;
if (hwif && hwif->mate)
seq_printf(m, "%s\n", hwif->mate->name);
else
seq_printf(m, "(none)\n");
return 0;
}
static int ide_mate_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_mate_proc_show, PDE(inode)->data);
}
static int ide_channel_proc_show(struct seq_file *m, void *v)
{
ide_hwif_t *hwif = (ide_hwif_t *) m->private;
seq_printf(m, "%c\n", hwif->channel ? '1' : '0');
return 0;
}
static int ide_channel_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_channel_proc_show, PDE(inode)->data);
}
static int ide_identify_proc_show(struct seq_file *m, void *v)
{
ide_drive_t *drive = (ide_drive_t *)m->private;
u8 *buf;
if (!drive) {
seq_putc(m, '\n');
return 0;
}
buf = kmalloc(SECTOR_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (taskfile_lib_get_identify(drive, buf) == 0) {
__le16 *val = (__le16 *)buf;
int i;
for (i = 0; i < SECTOR_SIZE / 2; i++) {
seq_printf(m, "%04x%c", le16_to_cpu(val[i]),
(i % 8) == 7 ? '\n' : ' ');
}
} else
seq_putc(m, buf[0]);
kfree(buf);
return 0;
}
static int ide_identify_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_identify_proc_show, PDE(inode)->data);
}
static
const struct ide_proc_devset *ide_find_setting(const struct ide_proc_devset *st,
char *name)
{
while (st->name) {
if (strcmp(st->name, name) == 0)
break;
st++;
}
return st->name ? st : NULL;
}
static int ide_read_setting(ide_drive_t *drive,
const struct ide_proc_devset *setting)
{
const struct ide_devset *ds = setting->setting;
int val = -EINVAL;
if (ds->get)
val = ds->get(drive);
return val;
}
static int ide_write_setting(ide_drive_t *drive,
const struct ide_proc_devset *setting, int val)
{
const struct ide_devset *ds = setting->setting;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (!ds->set)
return -EPERM;
if ((ds->flags & DS_SYNC)
&& (val < setting->min || val > setting->max))
return -EINVAL;
return ide_devset_execute(drive, ds, val);
}
static int set_xfer_rate (ide_drive_t *drive, int arg)
{
struct ide_cmd cmd;
if (arg < XFER_PIO_0 || arg > XFER_UDMA_6)
return -EINVAL;
memset(&cmd, 0, sizeof(cmd));
cmd.tf.command = ATA_CMD_SET_FEATURES;
cmd.tf.feature = SETFEATURES_XFER;
cmd.tf.nsect = (u8)arg;
cmd.valid.out.tf = IDE_VALID_FEATURE | IDE_VALID_NSECT;
cmd.valid.in.tf = IDE_VALID_NSECT;
cmd.tf_flags = IDE_TFLAG_SET_XFER;
return ide_no_data_taskfile(drive, &cmd);
}
static void proc_ide_settings_warn(void)
{
printk_once(KERN_WARNING "Warning: /proc/ide/hd?/settings interface is "
"obsolete, and will be removed soon!\n");
}
static int ide_settings_proc_show(struct seq_file *m, void *v)
{
const struct ide_proc_devset *setting, *g, *d;
const struct ide_devset *ds;
ide_drive_t *drive = (ide_drive_t *) m->private;
int rc, mul_factor, div_factor;
proc_ide_settings_warn();
mutex_lock(&ide_setting_mtx);
g = ide_generic_settings;
d = drive->settings;
seq_printf(m, "name\t\t\tvalue\t\tmin\t\tmax\t\tmode\n");
seq_printf(m, "----\t\t\t-----\t\t---\t\t---\t\t----\n");
while (g->name || (d && d->name)) {
if (g->name && d && d->name) {
if (strcmp(d->name, g->name) < 0)
setting = d++;
else
setting = g++;
} else if (d && d->name) {
setting = d++;
} else
setting = g++;
mul_factor = setting->mulf ? setting->mulf(drive) : 1;
div_factor = setting->divf ? setting->divf(drive) : 1;
seq_printf(m, "%-24s", setting->name);
rc = ide_read_setting(drive, setting);
if (rc >= 0)
seq_printf(m, "%-16d", rc * mul_factor / div_factor);
else
seq_printf(m, "%-16s", "write-only");
seq_printf(m, "%-16d%-16d", (setting->min * mul_factor + div_factor - 1) / div_factor, setting->max * mul_factor / div_factor);
ds = setting->setting;
if (ds->get)
seq_printf(m, "r");
if (ds->set)
seq_printf(m, "w");
seq_printf(m, "\n");
}
mutex_unlock(&ide_setting_mtx);
return 0;
}
static int ide_settings_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_settings_proc_show, PDE(inode)->data);
}
static ssize_t ide_settings_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
ide_drive_t *drive = (ide_drive_t *) PDE(file->f_path.dentry->d_inode)->data;
char name[MAX_LEN + 1];
int for_real = 0, mul_factor, div_factor;
unsigned long n;
const struct ide_proc_devset *setting;
char *buf, *s;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
proc_ide_settings_warn();
if (count >= PAGE_SIZE)
return -EINVAL;
s = buf = (char *)__get_free_page(GFP_USER);
if (!buf)
return -ENOMEM;
if (copy_from_user(buf, buffer, count)) {
free_page((unsigned long)buf);
return -EFAULT;
}
buf[count] = '\0';
while (count && isspace(*s)) {
--count;
++s;
}
do {
char *p = s;
n = count;
while (n > 0) {
unsigned val;
char *q = p;
while (n > 0 && *p != ':') {
--n;
p++;
}
if (*p != ':')
goto parse_error;
if (p - q > MAX_LEN)
goto parse_error;
memcpy(name, q, p - q);
name[p - q] = 0;
if (n > 0) {
--n;
p++;
} else
goto parse_error;
val = simple_strtoul(p, &q, 10);
n -= q - p;
p = q;
if (n > 0 && !isspace(*p))
goto parse_error;
while (n > 0 && isspace(*p)) {
--n;
++p;
}
mutex_lock(&ide_setting_mtx);
setting = ide_find_setting(ide_generic_settings, name);
if (!setting) {
if (drive->settings)
setting = ide_find_setting(drive->settings, name);
if (!setting) {
mutex_unlock(&ide_setting_mtx);
goto parse_error;
}
}
if (for_real) {
mul_factor = setting->mulf ? setting->mulf(drive) : 1;
div_factor = setting->divf ? setting->divf(drive) : 1;
ide_write_setting(drive, setting, val * div_factor / mul_factor);
}
mutex_unlock(&ide_setting_mtx);
}
} while (!for_real++);
free_page((unsigned long)buf);
return count;
parse_error:
free_page((unsigned long)buf);
printk("%s(): parse error\n", __func__);
return -EINVAL;
}
static int ide_capacity_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%llu\n", (long long)0x7fffffff);
return 0;
}
static int ide_capacity_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_capacity_proc_show, NULL);
}
static int ide_geometry_proc_show(struct seq_file *m, void *v)
{
ide_drive_t *drive = (ide_drive_t *) m->private;
seq_printf(m, "physical %d/%d/%d\n",
drive->cyl, drive->head, drive->sect);
seq_printf(m, "logical %d/%d/%d\n",
drive->bios_cyl, drive->bios_head, drive->bios_sect);
return 0;
}
static int ide_geometry_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_geometry_proc_show, PDE(inode)->data);
}
static int ide_dmodel_proc_show(struct seq_file *seq, void *v)
{
ide_drive_t *drive = (ide_drive_t *) seq->private;
char *m = (char *)&drive->id[ATA_ID_PROD];
seq_printf(seq, "%.40s\n", m[0] ? m : "(none)");
return 0;
}
static int ide_dmodel_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_dmodel_proc_show, PDE(inode)->data);
}
static int ide_driver_proc_show(struct seq_file *m, void *v)
{
ide_drive_t *drive = (ide_drive_t *)m->private;
struct device *dev = &drive->gendev;
struct ide_driver *ide_drv;
if (dev->driver) {
ide_drv = to_ide_driver(dev->driver);
seq_printf(m, "%s version %s\n",
dev->driver->name, ide_drv->version);
} else
seq_printf(m, "ide-default version 0.9.newide\n");
return 0;
}
static int ide_driver_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_driver_proc_show, PDE(inode)->data);
}
static int ide_replace_subdriver(ide_drive_t *drive, const char *driver)
{
struct device *dev = &drive->gendev;
int ret = 1;
int err;
device_release_driver(dev);
strlcpy(drive->driver_req, driver, sizeof(drive->driver_req));
err = device_attach(dev);
if (err < 0)
printk(KERN_WARNING "IDE: %s: device_attach error: %d\n",
__func__, err);
drive->driver_req[0] = 0;
if (dev->driver == NULL) {
err = device_attach(dev);
if (err < 0)
printk(KERN_WARNING
"IDE: %s: device_attach(2) error: %d\n",
__func__, err);
}
if (dev->driver && !strcmp(dev->driver->name, driver))
ret = 0;
return ret;
}
static ssize_t ide_driver_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
ide_drive_t *drive = (ide_drive_t *) PDE(file->f_path.dentry->d_inode)->data;
char name[32];
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (count > 31)
count = 31;
if (copy_from_user(name, buffer, count))
return -EFAULT;
name[count] = '\0';
if (ide_replace_subdriver(drive, name))
return -EINVAL;
return count;
}
static int ide_media_proc_show(struct seq_file *m, void *v)
{
ide_drive_t *drive = (ide_drive_t *) m->private;
const char *media;
switch (drive->media) {
case ide_disk: media = "disk\n"; break;
case ide_cdrom: media = "cdrom\n"; break;
case ide_tape: media = "tape\n"; break;
case ide_floppy: media = "floppy\n"; break;
case ide_optical: media = "optical\n"; break;
default: media = "UNKNOWN\n"; break;
}
seq_puts(m, media);
return 0;
}
static int ide_media_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ide_media_proc_show, PDE(inode)->data);
}
static void ide_add_proc_entries(struct proc_dir_entry *dir, ide_proc_entry_t *p, void *data)
{
struct proc_dir_entry *ent;
if (!dir || !p)
return;
while (p->name != NULL) {
ent = proc_create_data(p->name, p->mode, dir, p->proc_fops, data);
if (!ent) return;
p++;
}
}
static void ide_remove_proc_entries(struct proc_dir_entry *dir, ide_proc_entry_t *p)
{
if (!dir || !p)
return;
while (p->name != NULL) {
remove_proc_entry(p->name, dir);
p++;
}
}
void ide_proc_register_driver(ide_drive_t *drive, struct ide_driver *driver)
{
mutex_lock(&ide_setting_mtx);
drive->settings = driver->proc_devsets(drive);
mutex_unlock(&ide_setting_mtx);
ide_add_proc_entries(drive->proc, driver->proc_entries(drive), drive);
}
void ide_proc_unregister_driver(ide_drive_t *drive, struct ide_driver *driver)
{
ide_remove_proc_entries(drive->proc, driver->proc_entries(drive));
mutex_lock(&ide_setting_mtx);
drive->settings = NULL;
mutex_unlock(&ide_setting_mtx);
}
void ide_proc_port_register_devices(ide_hwif_t *hwif)
{
struct proc_dir_entry *ent;
struct proc_dir_entry *parent = hwif->proc;
ide_drive_t *drive;
char name[64];
int i;
ide_port_for_each_dev(i, drive, hwif) {
if ((drive->dev_flags & IDE_DFLAG_PRESENT) == 0)
continue;
drive->proc = proc_mkdir(drive->name, parent);
if (drive->proc)
ide_add_proc_entries(drive->proc, generic_drive_entries, drive);
sprintf(name, "ide%d/%s", (drive->name[2]-'a')/2, drive->name);
ent = proc_symlink(drive->name, proc_ide_root, name);
if (!ent) return;
}
}
void ide_proc_unregister_device(ide_drive_t *drive)
{
if (drive->proc) {
ide_remove_proc_entries(drive->proc, generic_drive_entries);
remove_proc_entry(drive->name, proc_ide_root);
remove_proc_entry(drive->name, drive->hwif->proc);
drive->proc = NULL;
}
}
void ide_proc_register_port(ide_hwif_t *hwif)
{
if (!hwif->proc) {
hwif->proc = proc_mkdir(hwif->name, proc_ide_root);
if (!hwif->proc)
return;
ide_add_proc_entries(hwif->proc, hwif_entries, hwif);
}
}
void ide_proc_unregister_port(ide_hwif_t *hwif)
{
if (hwif->proc) {
ide_remove_proc_entries(hwif->proc, hwif_entries);
remove_proc_entry(hwif->name, proc_ide_root);
hwif->proc = NULL;
}
}
static int proc_print_driver(struct device_driver *drv, void *data)
{
struct ide_driver *ide_drv = to_ide_driver(drv);
struct seq_file *s = data;
seq_printf(s, "%s version %s\n", drv->name, ide_drv->version);
return 0;
}
static int ide_drivers_show(struct seq_file *s, void *p)
{
int err;
err = bus_for_each_drv(&ide_bus_type, NULL, s, proc_print_driver);
if (err < 0)
printk(KERN_WARNING "IDE: %s: bus_for_each_drv error: %d\n",
__func__, err);
return 0;
}
static int ide_drivers_open(struct inode *inode, struct file *file)
{
return single_open(file, &ide_drivers_show, NULL);
}
void proc_ide_create(void)
{
proc_ide_root = proc_mkdir("ide", NULL);
if (!proc_ide_root)
return;
proc_create("drivers", 0, proc_ide_root, &ide_drivers_operations);
}
void proc_ide_destroy(void)
{
remove_proc_entry("drivers", proc_ide_root);
remove_proc_entry("ide", NULL);
}
