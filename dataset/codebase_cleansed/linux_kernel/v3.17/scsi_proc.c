static ssize_t proc_scsi_host_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct Scsi_Host *shost = PDE_DATA(file_inode(file));
ssize_t ret = -ENOMEM;
char *page;
if (count > PROC_BLOCK_SIZE)
return -EOVERFLOW;
if (!shost->hostt->write_info)
return -EINVAL;
page = (char *)__get_free_page(GFP_KERNEL);
if (page) {
ret = -EFAULT;
if (copy_from_user(page, buf, count))
goto out;
ret = shost->hostt->write_info(shost, page, count);
}
out:
free_page((unsigned long)page);
return ret;
}
static int proc_scsi_show(struct seq_file *m, void *v)
{
struct Scsi_Host *shost = m->private;
return shost->hostt->show_info(m, shost);
}
static int proc_scsi_host_open(struct inode *inode, struct file *file)
{
return single_open_size(file, proc_scsi_show, PDE_DATA(inode),
4 * PAGE_SIZE);
}
void scsi_proc_hostdir_add(struct scsi_host_template *sht)
{
if (!sht->show_info)
return;
mutex_lock(&global_host_template_mutex);
if (!sht->present++) {
sht->proc_dir = proc_mkdir(sht->proc_name, proc_scsi);
if (!sht->proc_dir)
printk(KERN_ERR "%s: proc_mkdir failed for %s\n",
__func__, sht->proc_name);
}
mutex_unlock(&global_host_template_mutex);
}
void scsi_proc_hostdir_rm(struct scsi_host_template *sht)
{
if (!sht->show_info)
return;
mutex_lock(&global_host_template_mutex);
if (!--sht->present && sht->proc_dir) {
remove_proc_entry(sht->proc_name, proc_scsi);
sht->proc_dir = NULL;
}
mutex_unlock(&global_host_template_mutex);
}
void scsi_proc_host_add(struct Scsi_Host *shost)
{
struct scsi_host_template *sht = shost->hostt;
struct proc_dir_entry *p;
char name[10];
if (!sht->proc_dir)
return;
sprintf(name,"%d", shost->host_no);
p = proc_create_data(name, S_IRUGO | S_IWUSR,
sht->proc_dir, &proc_scsi_fops, shost);
if (!p)
printk(KERN_ERR "%s: Failed to register host %d in"
"%s\n", __func__, shost->host_no,
sht->proc_name);
}
void scsi_proc_host_rm(struct Scsi_Host *shost)
{
char name[10];
if (!shost->hostt->proc_dir)
return;
sprintf(name,"%d", shost->host_no);
remove_proc_entry(name, shost->hostt->proc_dir);
}
static int proc_print_scsidevice(struct device *dev, void *data)
{
struct scsi_device *sdev;
struct seq_file *s = data;
int i;
if (!scsi_is_sdev_device(dev))
goto out;
sdev = to_scsi_device(dev);
seq_printf(s,
"Host: scsi%d Channel: %02d Id: %02d Lun: %02llu\n Vendor: ",
sdev->host->host_no, sdev->channel, sdev->id, sdev->lun);
for (i = 0; i < 8; i++) {
if (sdev->vendor[i] >= 0x20)
seq_printf(s, "%c", sdev->vendor[i]);
else
seq_printf(s, " ");
}
seq_printf(s, " Model: ");
for (i = 0; i < 16; i++) {
if (sdev->model[i] >= 0x20)
seq_printf(s, "%c", sdev->model[i]);
else
seq_printf(s, " ");
}
seq_printf(s, " Rev: ");
for (i = 0; i < 4; i++) {
if (sdev->rev[i] >= 0x20)
seq_printf(s, "%c", sdev->rev[i]);
else
seq_printf(s, " ");
}
seq_printf(s, "\n");
seq_printf(s, " Type: %s ", scsi_device_type(sdev->type));
seq_printf(s, " ANSI SCSI revision: %02x",
sdev->scsi_level - (sdev->scsi_level > 1));
if (sdev->scsi_level == 2)
seq_printf(s, " CCS\n");
else
seq_printf(s, "\n");
out:
return 0;
}
static int scsi_add_single_device(uint host, uint channel, uint id, uint lun)
{
struct Scsi_Host *shost;
int error = -ENXIO;
shost = scsi_host_lookup(host);
if (!shost)
return error;
if (shost->transportt->user_scan)
error = shost->transportt->user_scan(shost, channel, id, lun);
else
error = scsi_scan_host_selected(shost, channel, id, lun, 1);
scsi_host_put(shost);
return error;
}
static int scsi_remove_single_device(uint host, uint channel, uint id, uint lun)
{
struct scsi_device *sdev;
struct Scsi_Host *shost;
int error = -ENXIO;
shost = scsi_host_lookup(host);
if (!shost)
return error;
sdev = scsi_device_lookup(shost, channel, id, lun);
if (sdev) {
scsi_remove_device(sdev);
scsi_device_put(sdev);
error = 0;
}
scsi_host_put(shost);
return error;
}
static ssize_t proc_scsi_write(struct file *file, const char __user *buf,
size_t length, loff_t *ppos)
{
int host, channel, id, lun;
char *buffer, *p;
int err;
if (!buf || length > PAGE_SIZE)
return -EINVAL;
buffer = (char *)__get_free_page(GFP_KERNEL);
if (!buffer)
return -ENOMEM;
err = -EFAULT;
if (copy_from_user(buffer, buf, length))
goto out;
err = -EINVAL;
if (length < PAGE_SIZE)
buffer[length] = '\0';
else if (buffer[PAGE_SIZE-1])
goto out;
if (!strncmp("scsi add-single-device", buffer, 22)) {
p = buffer + 23;
host = simple_strtoul(p, &p, 0);
channel = simple_strtoul(p + 1, &p, 0);
id = simple_strtoul(p + 1, &p, 0);
lun = simple_strtoul(p + 1, &p, 0);
err = scsi_add_single_device(host, channel, id, lun);
} else if (!strncmp("scsi remove-single-device", buffer, 25)) {
p = buffer + 26;
host = simple_strtoul(p, &p, 0);
channel = simple_strtoul(p + 1, &p, 0);
id = simple_strtoul(p + 1, &p, 0);
lun = simple_strtoul(p + 1, &p, 0);
err = scsi_remove_single_device(host, channel, id, lun);
}
if (!err)
err = length;
out:
free_page((unsigned long)buffer);
return err;
}
static int always_match(struct device *dev, void *data)
{
return 1;
}
static inline struct device *next_scsi_device(struct device *start)
{
struct device *next = bus_find_device(&scsi_bus_type, start, NULL,
always_match);
put_device(start);
return next;
}
static void *scsi_seq_start(struct seq_file *sfile, loff_t *pos)
{
struct device *dev = NULL;
loff_t n = *pos;
while ((dev = next_scsi_device(dev))) {
if (!n--)
break;
sfile->private++;
}
return dev;
}
static void *scsi_seq_next(struct seq_file *sfile, void *v, loff_t *pos)
{
(*pos)++;
sfile->private++;
return next_scsi_device(v);
}
static void scsi_seq_stop(struct seq_file *sfile, void *v)
{
put_device(v);
}
static int scsi_seq_show(struct seq_file *sfile, void *dev)
{
if (!sfile->private)
seq_puts(sfile, "Attached devices:\n");
return proc_print_scsidevice(dev, sfile);
}
static int proc_scsi_open(struct inode *inode, struct file *file)
{
return seq_open(file, &scsi_seq_ops);
}
int __init scsi_init_procfs(void)
{
struct proc_dir_entry *pde;
proc_scsi = proc_mkdir("scsi", NULL);
if (!proc_scsi)
goto err1;
pde = proc_create("scsi/scsi", 0, NULL, &proc_scsi_operations);
if (!pde)
goto err2;
return 0;
err2:
remove_proc_entry("scsi", NULL);
err1:
return -ENOMEM;
}
void scsi_exit_procfs(void)
{
remove_proc_entry("scsi/scsi", NULL);
remove_proc_entry("scsi", NULL);
}
