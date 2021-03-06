static int blacklist_range(range_action action, unsigned int from_ssid,
unsigned int to_ssid, unsigned int from,
unsigned int to, int msgtrigger)
{
if ((from_ssid > to_ssid) || ((from_ssid == to_ssid) && (from > to))) {
if (msgtrigger)
pr_warning("0.%x.%04x to 0.%x.%04x is not a valid "
"range for cio_ignore\n", from_ssid, from,
to_ssid, to);
return 1;
}
while ((from_ssid < to_ssid) || ((from_ssid == to_ssid) &&
(from <= to))) {
if (action == add)
set_bit(from, bl_dev[from_ssid]);
else
clear_bit(from, bl_dev[from_ssid]);
from++;
if (from > __MAX_SUBCHANNEL) {
from_ssid++;
from = 0;
}
}
return 0;
}
static int pure_hex(char **cp, unsigned int *val, int min_digit,
int max_digit, int max_val)
{
int diff;
diff = 0;
*val = 0;
while (diff <= max_digit) {
int value = hex_to_bin(**cp);
if (value < 0)
break;
*val = *val * 16 + value;
(*cp)++;
diff++;
}
if ((diff < min_digit) || (diff > max_digit) || (*val > max_val))
return 1;
return 0;
}
static int parse_busid(char *str, unsigned int *cssid, unsigned int *ssid,
unsigned int *devno, int msgtrigger)
{
char *str_work;
int val, rc, ret;
rc = 1;
if (*str == '\0')
goto out;
str_work = str;
val = simple_strtoul(str, &str_work, 16);
if (*str_work == '\0') {
if (val <= __MAX_SUBCHANNEL) {
*devno = val;
*ssid = 0;
*cssid = 0;
rc = 0;
}
goto out;
}
str_work = str;
ret = pure_hex(&str_work, cssid, 1, 2, __MAX_CSSID);
if (ret || (str_work[0] != '.'))
goto out;
str_work++;
ret = pure_hex(&str_work, ssid, 1, 1, __MAX_SSID);
if (ret || (str_work[0] != '.'))
goto out;
str_work++;
ret = pure_hex(&str_work, devno, 4, 4, __MAX_SUBCHANNEL);
if (ret || (str_work[0] != '\0'))
goto out;
rc = 0;
out:
if (rc && msgtrigger)
pr_warning("%s is not a valid device for the cio_ignore "
"kernel parameter\n", str);
return rc;
}
static int blacklist_parse_parameters(char *str, range_action action,
int msgtrigger)
{
unsigned int from_cssid, to_cssid, from_ssid, to_ssid, from, to;
int rc, totalrc;
char *parm;
range_action ra;
totalrc = 0;
while ((parm = strsep(&str, ","))) {
rc = 0;
ra = action;
if (*parm == '!') {
if (ra == add)
ra = free;
else
ra = add;
parm++;
}
if (strcmp(parm, "all") == 0) {
from_cssid = 0;
from_ssid = 0;
from = 0;
to_cssid = __MAX_CSSID;
to_ssid = __MAX_SSID;
to = __MAX_SUBCHANNEL;
} else {
rc = parse_busid(strsep(&parm, "-"), &from_cssid,
&from_ssid, &from, msgtrigger);
if (!rc) {
if (parm != NULL)
rc = parse_busid(parm, &to_cssid,
&to_ssid, &to,
msgtrigger);
else {
to_cssid = from_cssid;
to_ssid = from_ssid;
to = from;
}
}
}
if (!rc) {
rc = blacklist_range(ra, from_ssid, to_ssid, from, to,
msgtrigger);
if (rc)
totalrc = -EINVAL;
} else
totalrc = -EINVAL;
}
return totalrc;
}
static int __init
blacklist_setup (char *str)
{
CIO_MSG_EVENT(6, "Reading blacklist parameters\n");
if (blacklist_parse_parameters(str, add, 1))
return 0;
return 1;
}
int
is_blacklisted (int ssid, int devno)
{
return test_bit (devno, bl_dev[ssid]);
}
static int blacklist_parse_proc_parameters(char *buf)
{
int rc;
char *parm;
parm = strsep(&buf, " ");
if (strcmp("free", parm) == 0)
rc = blacklist_parse_parameters(buf, free, 0);
else if (strcmp("add", parm) == 0)
rc = blacklist_parse_parameters(buf, add, 0);
else if (strcmp("purge", parm) == 0)
return ccw_purge_blacklisted();
else
return -EINVAL;
css_schedule_reprobe();
return rc;
}
static void *
cio_ignore_proc_seq_start(struct seq_file *s, loff_t *offset)
{
struct ccwdev_iter *iter = s->private;
if (*offset >= (__MAX_SUBCHANNEL + 1) * (__MAX_SSID + 1))
return NULL;
memset(iter, 0, sizeof(*iter));
iter->ssid = *offset / (__MAX_SUBCHANNEL + 1);
iter->devno = *offset % (__MAX_SUBCHANNEL + 1);
return iter;
}
static void
cio_ignore_proc_seq_stop(struct seq_file *s, void *it)
{
}
static void *
cio_ignore_proc_seq_next(struct seq_file *s, void *it, loff_t *offset)
{
struct ccwdev_iter *iter;
if (*offset >= (__MAX_SUBCHANNEL + 1) * (__MAX_SSID + 1))
return NULL;
iter = it;
if (iter->devno == __MAX_SUBCHANNEL) {
iter->devno = 0;
iter->ssid++;
if (iter->ssid > __MAX_SSID)
return NULL;
} else
iter->devno++;
(*offset)++;
return iter;
}
static int
cio_ignore_proc_seq_show(struct seq_file *s, void *it)
{
struct ccwdev_iter *iter;
iter = it;
if (!is_blacklisted(iter->ssid, iter->devno))
return 0;
if (!iter->in_range) {
if ((iter->devno == __MAX_SUBCHANNEL) ||
!is_blacklisted(iter->ssid, iter->devno + 1))
return seq_printf(s, "0.%x.%04x\n",
iter->ssid, iter->devno);
iter->in_range = 1;
return seq_printf(s, "0.%x.%04x-", iter->ssid, iter->devno);
}
if ((iter->devno == __MAX_SUBCHANNEL) ||
!is_blacklisted(iter->ssid, iter->devno + 1)) {
iter->in_range = 0;
return seq_printf(s, "0.%x.%04x\n", iter->ssid, iter->devno);
}
return 0;
}
static ssize_t
cio_ignore_write(struct file *file, const char __user *user_buf,
size_t user_len, loff_t *offset)
{
char *buf;
ssize_t rc, ret, i;
if (*offset)
return -EINVAL;
if (user_len > 65536)
user_len = 65536;
buf = vzalloc(user_len + 1);
if (buf == NULL)
return -ENOMEM;
if (strncpy_from_user (buf, user_buf, user_len) < 0) {
rc = -EFAULT;
goto out_free;
}
i = user_len - 1;
while ((i >= 0) && (isspace(buf[i]) || (buf[i] == 0))) {
buf[i] = '\0';
i--;
}
ret = blacklist_parse_proc_parameters(buf);
if (ret)
rc = ret;
else
rc = user_len;
out_free:
vfree (buf);
return rc;
}
static int
cio_ignore_proc_open(struct inode *inode, struct file *file)
{
return seq_open_private(file, &cio_ignore_proc_seq_ops,
sizeof(struct ccwdev_iter));
}
static int
cio_ignore_proc_init (void)
{
struct proc_dir_entry *entry;
entry = proc_create("cio_ignore", S_IFREG | S_IRUGO | S_IWUSR, NULL,
&cio_ignore_proc_fops);
if (!entry)
return -ENOENT;
return 0;
}
