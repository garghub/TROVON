static void *tpm_bios_measurements_start(struct seq_file *m, loff_t *pos)
{
loff_t i;
struct tpm_chip *chip = m->private;
struct tpm_bios_log *log = &chip->log;
void *addr = log->bios_event_log;
void *limit = log->bios_event_log_end;
struct tcpa_event *event;
u32 converted_event_size;
u32 converted_event_type;
for (i = 0; i < *pos; i++) {
event = addr;
converted_event_size =
do_endian_conversion(event->event_size);
converted_event_type =
do_endian_conversion(event->event_type);
if ((addr + sizeof(struct tcpa_event)) < limit) {
if ((converted_event_type == 0) &&
(converted_event_size == 0))
return NULL;
addr += (sizeof(struct tcpa_event) +
converted_event_size);
}
}
if ((addr + sizeof(struct tcpa_event)) >= limit)
return NULL;
event = addr;
converted_event_size = do_endian_conversion(event->event_size);
converted_event_type = do_endian_conversion(event->event_type);
if (((converted_event_type == 0) && (converted_event_size == 0))
|| ((addr + sizeof(struct tcpa_event) + converted_event_size)
>= limit))
return NULL;
return addr;
}
static void *tpm_bios_measurements_next(struct seq_file *m, void *v,
loff_t *pos)
{
struct tcpa_event *event = v;
struct tpm_chip *chip = m->private;
struct tpm_bios_log *log = &chip->log;
void *limit = log->bios_event_log_end;
u32 converted_event_size;
u32 converted_event_type;
converted_event_size = do_endian_conversion(event->event_size);
v += sizeof(struct tcpa_event) + converted_event_size;
if ((v + sizeof(struct tcpa_event)) >= limit)
return NULL;
event = v;
converted_event_size = do_endian_conversion(event->event_size);
converted_event_type = do_endian_conversion(event->event_type);
if (((converted_event_type == 0) && (converted_event_size == 0)) ||
((v + sizeof(struct tcpa_event) + converted_event_size) >= limit))
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
switch (do_endian_conversion(event->event_type)) {
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
name = tcpa_event_type_strings[do_endian_conversion
(event->event_type)];
n_len = strlen(name);
break;
case SEPARATOR:
case ACTION:
if (MAX_TEXT_EVENT >
do_endian_conversion(event->event_size)) {
name = event_entry;
n_len = do_endian_conversion(event->event_size);
}
break;
case EVENT_TAG:
pc_event = (struct tcpa_pc_event *)event_entry;
switch (do_endian_conversion(pc_event->event_id)) {
case SMBIOS:
case BIS_CERT:
case CMOS:
case NVRAM:
case OPTION_ROM_EXEC:
case OPTION_ROM_CONFIG:
case S_CRTM_VERSION:
name = tcpa_pc_event_id_strings[do_endian_conversion
(pc_event->event_id)];
n_len = strlen(name);
break;
case POST_BIOS_ROM:
case ESCD:
case OPTION_ROM_MICROCODE:
case S_CRTM_CONTENTS:
case POST_CONTENTS:
name = tcpa_pc_event_id_strings[do_endian_conversion
(pc_event->event_id)];
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
struct tcpa_event temp_event;
char *temp_ptr;
int i;
memcpy(&temp_event, event, sizeof(struct tcpa_event));
temp_event.pcr_index = do_endian_conversion(event->pcr_index);
temp_event.event_type = do_endian_conversion(event->event_type);
temp_event.event_size = do_endian_conversion(event->event_size);
temp_ptr = (char *) &temp_event;
for (i = 0; i < (sizeof(struct tcpa_event) - 1) ; i++)
seq_putc(m, temp_ptr[i]);
temp_ptr = (char *) v;
for (i = (sizeof(struct tcpa_event) - 1);
i < (sizeof(struct tcpa_event) + temp_event.event_size); i++)
seq_putc(m, temp_ptr[i]);
return 0;
}
static int tpm_bios_measurements_release(struct inode *inode,
struct file *file)
{
struct seq_file *seq = (struct seq_file *)file->private_data;
struct tpm_chip *chip = (struct tpm_chip *)seq->private;
put_device(&chip->dev);
return seq_release(inode, file);
}
static int tpm_ascii_bios_measurements_show(struct seq_file *m, void *v)
{
int len = 0;
char *eventname;
struct tcpa_event *event = v;
unsigned char *event_entry =
(unsigned char *)(v + sizeof(struct tcpa_event));
eventname = kmalloc(MAX_TEXT_EVENT, GFP_KERNEL);
if (!eventname) {
printk(KERN_ERR "%s: ERROR - No Memory for event name\n ",
__func__);
return -EFAULT;
}
seq_printf(m, "%2d ", do_endian_conversion(event->pcr_index));
seq_printf(m, "%20phN", event->pcr_value);
seq_printf(m, " %02x", do_endian_conversion(event->event_type));
len += get_event_name(eventname, event, event_entry);
seq_printf(m, " %s\n", eventname);
kfree(eventname);
return 0;
}
static int tpm_bios_measurements_open(struct inode *inode,
struct file *file)
{
int err;
struct seq_file *seq;
struct tpm_chip_seqops *chip_seqops;
const struct seq_operations *seqops;
struct tpm_chip *chip;
inode_lock(inode);
if (!inode->i_private) {
inode_unlock(inode);
return -ENODEV;
}
chip_seqops = (struct tpm_chip_seqops *)inode->i_private;
seqops = chip_seqops->seqops;
chip = chip_seqops->chip;
get_device(&chip->dev);
inode_unlock(inode);
err = seq_open(file, seqops);
if (!err) {
seq = file->private_data;
seq->private = chip;
}
return err;
}
static int tpm_read_log(struct tpm_chip *chip)
{
int rc;
if (chip->log.bios_event_log != NULL) {
dev_dbg(&chip->dev,
"%s: ERROR - event log already initialized\n",
__func__);
return -EFAULT;
}
rc = tpm_read_log_acpi(chip);
if (rc != -ENODEV)
return rc;
return tpm_read_log_of(chip);
}
int tpm_bios_log_setup(struct tpm_chip *chip)
{
const char *name = dev_name(&chip->dev);
unsigned int cnt;
int rc = 0;
rc = tpm_read_log(chip);
if (rc)
return rc;
cnt = 0;
chip->bios_dir[cnt] = securityfs_create_dir(name, NULL);
if (IS_ERR(chip->bios_dir[cnt]))
goto err;
cnt++;
chip->bin_log_seqops.chip = chip;
if (chip->flags & TPM_CHIP_FLAG_TPM2)
chip->bin_log_seqops.seqops =
&tpm2_binary_b_measurements_seqops;
else
chip->bin_log_seqops.seqops =
&tpm_binary_b_measurements_seqops;
chip->bios_dir[cnt] =
securityfs_create_file("binary_bios_measurements",
0440, chip->bios_dir[0],
(void *)&chip->bin_log_seqops,
&tpm_bios_measurements_ops);
if (IS_ERR(chip->bios_dir[cnt]))
goto err;
cnt++;
if (!(chip->flags & TPM_CHIP_FLAG_TPM2)) {
chip->ascii_log_seqops.chip = chip;
chip->ascii_log_seqops.seqops =
&tpm_ascii_b_measurements_seqops;
chip->bios_dir[cnt] =
securityfs_create_file("ascii_bios_measurements",
0440, chip->bios_dir[0],
(void *)&chip->ascii_log_seqops,
&tpm_bios_measurements_ops);
if (IS_ERR(chip->bios_dir[cnt]))
goto err;
cnt++;
}
return 0;
err:
rc = PTR_ERR(chip->bios_dir[cnt]);
chip->bios_dir[cnt] = NULL;
tpm_bios_log_teardown(chip);
return rc;
}
void tpm_bios_log_teardown(struct tpm_chip *chip)
{
int i;
struct inode *inode;
for (i = (TPM_NUM_EVENT_LOG_FILES - 1); i >= 0; i--) {
if (chip->bios_dir[i]) {
inode = d_inode(chip->bios_dir[i]);
inode_lock(inode);
inode->i_private = NULL;
inode_unlock(inode);
securityfs_remove(chip->bios_dir[i]);
}
}
}
