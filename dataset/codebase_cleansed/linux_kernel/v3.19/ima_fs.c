static ssize_t ima_show_htable_value(char __user *buf, size_t count,
loff_t *ppos, atomic_long_t *val)
{
char tmpbuf[TMPBUFLEN];
ssize_t len;
len = scnprintf(tmpbuf, TMPBUFLEN, "%li\n", atomic_long_read(val));
return simple_read_from_buffer(buf, count, ppos, tmpbuf, len);
}
static ssize_t ima_show_htable_violations(struct file *filp,
char __user *buf,
size_t count, loff_t *ppos)
{
return ima_show_htable_value(buf, count, ppos, &ima_htable.violations);
}
static ssize_t ima_show_measurements_count(struct file *filp,
char __user *buf,
size_t count, loff_t *ppos)
{
return ima_show_htable_value(buf, count, ppos, &ima_htable.len);
}
static void *ima_measurements_start(struct seq_file *m, loff_t *pos)
{
loff_t l = *pos;
struct ima_queue_entry *qe;
rcu_read_lock();
list_for_each_entry_rcu(qe, &ima_measurements, later) {
if (!l--) {
rcu_read_unlock();
return qe;
}
}
rcu_read_unlock();
return NULL;
}
static void *ima_measurements_next(struct seq_file *m, void *v, loff_t *pos)
{
struct ima_queue_entry *qe = v;
rcu_read_lock();
qe = list_entry_rcu(qe->later.next, struct ima_queue_entry, later);
rcu_read_unlock();
(*pos)++;
return (&qe->later == &ima_measurements) ? NULL : qe;
}
static void ima_measurements_stop(struct seq_file *m, void *v)
{
}
void ima_putc(struct seq_file *m, void *data, int datalen)
{
while (datalen--)
seq_putc(m, *(char *)data++);
}
static int ima_measurements_show(struct seq_file *m, void *v)
{
struct ima_queue_entry *qe = v;
struct ima_template_entry *e;
char *template_name;
int namelen;
u32 pcr = CONFIG_IMA_MEASURE_PCR_IDX;
bool is_ima_template = false;
int i;
e = qe->entry;
if (e == NULL)
return -1;
template_name = (e->template_desc->name[0] != '\0') ?
e->template_desc->name : e->template_desc->fmt;
ima_putc(m, &pcr, sizeof(pcr));
ima_putc(m, e->digest, TPM_DIGEST_SIZE);
namelen = strlen(template_name);
ima_putc(m, &namelen, sizeof(namelen));
ima_putc(m, template_name, namelen);
if (strcmp(template_name, IMA_TEMPLATE_IMA_NAME) == 0)
is_ima_template = true;
if (!is_ima_template)
ima_putc(m, &e->template_data_len,
sizeof(e->template_data_len));
for (i = 0; i < e->template_desc->num_fields; i++) {
enum ima_show_type show = IMA_SHOW_BINARY;
struct ima_template_field *field = e->template_desc->fields[i];
if (is_ima_template && strcmp(field->field_id, "d") == 0)
show = IMA_SHOW_BINARY_NO_FIELD_LEN;
if (is_ima_template && strcmp(field->field_id, "n") == 0)
show = IMA_SHOW_BINARY_OLD_STRING_FMT;
field->field_show(m, show, &e->template_data[i]);
}
return 0;
}
static int ima_measurements_open(struct inode *inode, struct file *file)
{
return seq_open(file, &ima_measurments_seqops);
}
void ima_print_digest(struct seq_file *m, u8 *digest, int size)
{
int i;
for (i = 0; i < size; i++)
seq_printf(m, "%02x", *(digest + i));
}
static int ima_ascii_measurements_show(struct seq_file *m, void *v)
{
struct ima_queue_entry *qe = v;
struct ima_template_entry *e;
char *template_name;
int i;
e = qe->entry;
if (e == NULL)
return -1;
template_name = (e->template_desc->name[0] != '\0') ?
e->template_desc->name : e->template_desc->fmt;
seq_printf(m, "%2d ", CONFIG_IMA_MEASURE_PCR_IDX);
ima_print_digest(m, e->digest, TPM_DIGEST_SIZE);
seq_printf(m, " %s", template_name);
for (i = 0; i < e->template_desc->num_fields; i++) {
seq_puts(m, " ");
if (e->template_data[i].len == 0)
continue;
e->template_desc->fields[i]->field_show(m, IMA_SHOW_ASCII,
&e->template_data[i]);
}
seq_puts(m, "\n");
return 0;
}
static int ima_ascii_measurements_open(struct inode *inode, struct file *file)
{
return seq_open(file, &ima_ascii_measurements_seqops);
}
static ssize_t ima_write_policy(struct file *file, const char __user *buf,
size_t datalen, loff_t *ppos)
{
char *data = NULL;
ssize_t result;
if (datalen >= PAGE_SIZE)
datalen = PAGE_SIZE - 1;
result = -EINVAL;
if (*ppos != 0)
goto out;
result = -ENOMEM;
data = kmalloc(datalen + 1, GFP_KERNEL);
if (!data)
goto out;
*(data + datalen) = '\0';
result = -EFAULT;
if (copy_from_user(data, buf, datalen))
goto out;
result = ima_parse_add_rule(data);
out:
if (result < 0)
valid_policy = 0;
kfree(data);
return result;
}
static int ima_open_policy(struct inode *inode, struct file *filp)
{
if (!(filp->f_flags & O_WRONLY))
return -EACCES;
if (test_and_set_bit(IMA_FS_BUSY, &ima_fs_flags))
return -EBUSY;
return 0;
}
static int ima_release_policy(struct inode *inode, struct file *file)
{
const char *cause = valid_policy ? "completed" : "failed";
pr_info("IMA: policy update %s\n", cause);
integrity_audit_msg(AUDIT_INTEGRITY_STATUS, NULL, NULL,
"policy_update", cause, !valid_policy, 0);
if (!valid_policy) {
ima_delete_rules();
valid_policy = 1;
clear_bit(IMA_FS_BUSY, &ima_fs_flags);
return 0;
}
ima_update_policy();
securityfs_remove(ima_policy);
ima_policy = NULL;
return 0;
}
int __init ima_fs_init(void)
{
ima_dir = securityfs_create_dir("ima", NULL);
if (IS_ERR(ima_dir))
return -1;
binary_runtime_measurements =
securityfs_create_file("binary_runtime_measurements",
S_IRUSR | S_IRGRP, ima_dir, NULL,
&ima_measurements_ops);
if (IS_ERR(binary_runtime_measurements))
goto out;
ascii_runtime_measurements =
securityfs_create_file("ascii_runtime_measurements",
S_IRUSR | S_IRGRP, ima_dir, NULL,
&ima_ascii_measurements_ops);
if (IS_ERR(ascii_runtime_measurements))
goto out;
runtime_measurements_count =
securityfs_create_file("runtime_measurements_count",
S_IRUSR | S_IRGRP, ima_dir, NULL,
&ima_measurements_count_ops);
if (IS_ERR(runtime_measurements_count))
goto out;
violations =
securityfs_create_file("violations", S_IRUSR | S_IRGRP,
ima_dir, NULL, &ima_htable_violations_ops);
if (IS_ERR(violations))
goto out;
ima_policy = securityfs_create_file("policy",
S_IWUSR,
ima_dir, NULL,
&ima_measure_policy_ops);
if (IS_ERR(ima_policy))
goto out;
return 0;
out:
securityfs_remove(violations);
securityfs_remove(runtime_measurements_count);
securityfs_remove(ascii_runtime_measurements);
securityfs_remove(binary_runtime_measurements);
securityfs_remove(ima_dir);
securityfs_remove(ima_policy);
return -1;
}
