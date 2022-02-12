static void *tpm_bios_measurements_start(struct seq_file *m, loff_t *pos)
{
loff_t i;
struct tpm_bios_log *log = m->private;
void *addr = log->bios_event_log;
void *limit = log->bios_event_log_end;
struct tcpa_event *event;
for (i = 0; i < *pos; i++) {
event = addr;
if ((addr + sizeof(struct tcpa_event)) < limit) {
if (event->event_type == 0 && event->event_size == 0)
return NULL;
addr += sizeof(struct tcpa_event) + event->event_size;
}
}
if ((addr + sizeof(struct tcpa_event)) >= limit)
return NULL;
event = addr;
if ((event->event_type == 0 && event->event_size == 0) ||
((addr + sizeof(struct tcpa_event) + event->event_size) >= limit))
return NULL;
return addr;
}
static void *tpm_bios_measurements_next(struct seq_file *m, void *v,
loff_t *pos)
{
struct tcpa_event *event = v;
struct tpm_bios_log *log = m->private;
void *limit = log->bios_event_log_end;
v += sizeof(struct tcpa_event) + event->event_size;
if ((v + sizeof(struct tcpa_event)) >= limit)
return NULL;
event = v;
if (event->event_type == 0 && event->event_size == 0)
return NULL;
if ((event->event_type == 0 && event->event_size == 0) ||
((v + sizeof(struct tcpa_event) + event->event_size) >= limit))
return NULL;
(*pos)++;
return v;
}
static void tpm_bios_measurements_stop(struct seq_file *m, void *v)
{
}
static int get_event_name(char *dest, struct tcpa_event *event,
unsigned char * event_entry)
{
const char *name = "";
char data[41] = "";
int i, n_len = 0, d_len = 0;
struct tcpa_pc_event *pc_event;
switch(event->event_type) {
case PREBOOT:
case POST_CODE:
case UNUSED:
case NO_ACTION:
case SCRTM_CONTENTS:
case SCRTM_VERSION:
case CPU_MICROCODE:
case PLATFORM_CONFIG_FLAGS:
case TABLE_OF_DEVICES:
case COMPACT_HASH:
case IPL:
case IPL_PARTITION_DATA:
case NONHOST_CODE:
case NONHOST_CONFIG:
case NONHOST_INFO:
name = tcpa_event_type_strings[event->event_type];
n_len = strlen(name);
break;
case SEPARATOR:
case ACTION:
if (MAX_TEXT_EVENT > event->event_size) {
name = event_entry;
n_len = event->event_size;
}
break;
case EVENT_TAG:
pc_event = (struct tcpa_pc_event *)event_entry;
switch (pc_event->event_id) {
case SMBIOS:
case BIS_CERT:
case CMOS:
case NVRAM:
case OPTION_ROM_EXEC:
case OPTION_ROM_CONFIG:
case S_CRTM_VERSION:
name = tcpa_pc_event_id_strings[pc_event->event_id];
n_len = strlen(name);
break;
case POST_BIOS_ROM:
case ESCD:
case OPTION_ROM_MICROCODE:
case S_CRTM_CONTENTS:
case POST_CONTENTS:
name = tcpa_pc_event_id_strings[pc_event->event_id];
n_len = strlen(name);
for (i = 0; i < 20; i++)
d_len += sprintf(&data[2*i], "%02x",
pc_event->event_data[i]);
break;
default:
break;
}
default:
break;
}
return snprintf(dest, MAX_TEXT_EVENT, "[%.*s%.*s]",
n_len, name, d_len, data);
}
static int tpm_binary_bios_measurements_show(struct seq_file *m, void *v)
{
struct tcpa_event *event = v;
char *data = v;
int i;
for (i = 0; i < sizeof(struct tcpa_event) + event->event_size; i++)
seq_putc(m, data[i]);
return 0;
}
static int tpm_bios_measurements_release(struct inode *inode,
struct file *file)
{
struct seq_file *seq = file->private_data;
struct tpm_bios_log *log = seq->private;
if (log) {
kfree(log->bios_event_log);
kfree(log);
}
return seq_release(inode, file);
}
static int tpm_ascii_bios_measurements_show(struct seq_file *m, void *v)
{
int len = 0;
int i;
char *eventname;
struct tcpa_event *event = v;
unsigned char *event_entry =
(unsigned char *) (v + sizeof(struct tcpa_event));
eventname = kmalloc(MAX_TEXT_EVENT, GFP_KERNEL);
if (!eventname) {
printk(KERN_ERR "%s: ERROR - No Memory for event name\n ",
__func__);
return -EFAULT;
}
seq_printf(m, "%2d ", event->pcr_index);
for (i = 0; i < 20; i++)
seq_printf(m, "%02x", event->pcr_value[i]);
seq_printf(m, " %02x", event->event_type);
len += get_event_name(eventname, event, event_entry);
seq_printf(m, " %s\n", eventname);
kfree(eventname);
return 0;
}
static int read_log(struct tpm_bios_log *log)
{
struct acpi_tcpa *buff;
acpi_status status;
struct acpi_table_header *virt;
u64 len, start;
if (log->bios_event_log != NULL) {
printk(KERN_ERR
"%s: ERROR - Eventlog already initialized\n",
__func__);
return -EFAULT;
}
status = acpi_get_table(ACPI_SIG_TCPA, 1,
(struct acpi_table_header **)&buff);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR "%s: ERROR - Could not get TCPA table\n",
__func__);
return -EIO;
}
switch(buff->platform_class) {
case BIOS_SERVER:
len = buff->server.log_max_len;
start = buff->server.log_start_addr;
break;
case BIOS_CLIENT:
default:
len = buff->client.log_max_len;
start = buff->client.log_start_addr;
break;
}
if (!len) {
printk(KERN_ERR "%s: ERROR - TCPA log area empty\n", __func__);
return -EIO;
}
log->bios_event_log = kmalloc(len, GFP_KERNEL);
if (!log->bios_event_log) {
printk("%s: ERROR - Not enough Memory for BIOS measurements\n",
__func__);
return -ENOMEM;
}
log->bios_event_log_end = log->bios_event_log + len;
virt = acpi_os_map_memory(start, len);
memcpy(log->bios_event_log, virt, len);
acpi_os_unmap_memory(virt, len);
return 0;
}
static int tpm_ascii_bios_measurements_open(struct inode *inode,
struct file *file)
{
int err;
struct tpm_bios_log *log;
struct seq_file *seq;
log = kzalloc(sizeof(struct tpm_bios_log), GFP_KERNEL);
if (!log)
return -ENOMEM;
if ((err = read_log(log)))
goto out_free;
err = seq_open(file, &tpm_ascii_b_measurments_seqops);
if (!err) {
seq = file->private_data;
seq->private = log;
} else {
goto out_free;
}
out:
return err;
out_free:
kfree(log->bios_event_log);
kfree(log);
goto out;
}
static int tpm_binary_bios_measurements_open(struct inode *inode,
struct file *file)
{
int err;
struct tpm_bios_log *log;
struct seq_file *seq;
log = kzalloc(sizeof(struct tpm_bios_log), GFP_KERNEL);
if (!log)
return -ENOMEM;
if ((err = read_log(log)))
goto out_free;
err = seq_open(file, &tpm_binary_b_measurments_seqops);
if (!err) {
seq = file->private_data;
seq->private = log;
} else {
goto out_free;
}
out:
return err;
out_free:
kfree(log->bios_event_log);
kfree(log);
goto out;
}
static int is_bad(void *p)
{
if (!p)
return 1;
if (IS_ERR(p) && (PTR_ERR(p) != -ENODEV))
return 1;
return 0;
}
struct dentry **tpm_bios_log_setup(char *name)
{
struct dentry **ret = NULL, *tpm_dir, *bin_file, *ascii_file;
tpm_dir = securityfs_create_dir(name, NULL);
if (is_bad(tpm_dir))
goto out;
bin_file =
securityfs_create_file("binary_bios_measurements",
S_IRUSR | S_IRGRP, tpm_dir, NULL,
&tpm_binary_bios_measurements_ops);
if (is_bad(bin_file))
goto out_tpm;
ascii_file =
securityfs_create_file("ascii_bios_measurements",
S_IRUSR | S_IRGRP, tpm_dir, NULL,
&tpm_ascii_bios_measurements_ops);
if (is_bad(ascii_file))
goto out_bin;
ret = kmalloc(3 * sizeof(struct dentry *), GFP_KERNEL);
if (!ret)
goto out_ascii;
ret[0] = ascii_file;
ret[1] = bin_file;
ret[2] = tpm_dir;
return ret;
out_ascii:
securityfs_remove(ascii_file);
out_bin:
securityfs_remove(bin_file);
out_tpm:
securityfs_remove(tpm_dir);
out:
return NULL;
}
void tpm_bios_log_teardown(struct dentry **lst)
{
int i;
for (i = 0; i < 3; i++)
securityfs_remove(lst[i]);
}
