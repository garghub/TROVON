static int proc_call_handler(void *data, int write, loff_t *ppos,
void __user *buffer, size_t *lenp,
int (*handler)(void *data, int write,
loff_t pos, void __user *buffer, int len))
{
int rc = handler(data, write, *ppos, buffer, *lenp);
if (rc < 0)
return rc;
if (write) {
*ppos += *lenp;
} else {
*lenp = rc;
*ppos += rc;
}
return 0;
}
static int __proc_dobitmasks(void *data, int write,
loff_t pos, void __user *buffer, int nob)
{
const int tmpstrlen = 512;
char *tmpstr;
int rc;
unsigned int *mask = data;
int is_subsys = (mask == &libcfs_subsystem_debug) ? 1 : 0;
int is_printk = (mask == &libcfs_printk) ? 1 : 0;
rc = cfs_trace_allocate_string_buffer(&tmpstr, tmpstrlen);
if (rc < 0)
return rc;
if (!write) {
libcfs_debug_mask2str(tmpstr, tmpstrlen, *mask, is_subsys);
rc = strlen(tmpstr);
if (pos >= rc) {
rc = 0;
} else {
rc = cfs_trace_copyout_string(buffer, nob,
tmpstr + pos, "\n");
}
} else {
rc = cfs_trace_copyin_string(tmpstr, tmpstrlen, buffer, nob);
if (rc < 0) {
cfs_trace_free_string_buffer(tmpstr, tmpstrlen);
return rc;
}
rc = libcfs_debug_str2mask(mask, tmpstr, is_subsys);
if (is_printk)
*mask |= D_EMERG;
}
cfs_trace_free_string_buffer(tmpstr, tmpstrlen);
return rc;
}
static int proc_dobitmasks(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return proc_call_handler(table->data, write, ppos, buffer, lenp,
__proc_dobitmasks);
}
static int __proc_dump_kernel(void *data, int write,
loff_t pos, void __user *buffer, int nob)
{
if (!write)
return 0;
return cfs_trace_dump_debug_buffer_usrstr(buffer, nob);
}
static int proc_dump_kernel(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return proc_call_handler(table->data, write, ppos, buffer, lenp,
__proc_dump_kernel);
}
static int __proc_daemon_file(void *data, int write,
loff_t pos, void __user *buffer, int nob)
{
if (!write) {
int len = strlen(cfs_tracefile);
if (pos >= len)
return 0;
return cfs_trace_copyout_string(buffer, nob,
cfs_tracefile + pos, "\n");
}
return cfs_trace_daemon_command_usrstr(buffer, nob);
}
static int proc_daemon_file(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return proc_call_handler(table->data, write, ppos, buffer, lenp,
__proc_daemon_file);
}
static int __proc_debug_mb(void *data, int write,
loff_t pos, void __user *buffer, int nob)
{
if (!write) {
char tmpstr[32];
int len = snprintf(tmpstr, sizeof(tmpstr), "%d",
cfs_trace_get_debug_mb());
if (pos >= len)
return 0;
return cfs_trace_copyout_string(buffer, nob, tmpstr + pos,
"\n");
}
return cfs_trace_set_debug_mb_usrstr(buffer, nob);
}
static int proc_debug_mb(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return proc_call_handler(table->data, write, ppos, buffer, lenp,
__proc_debug_mb);
}
int proc_console_max_delay_cs(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int rc, max_delay_cs;
struct ctl_table dummy = *table;
long d;
dummy.data = &max_delay_cs;
dummy.proc_handler = &proc_dointvec;
if (!write) {
max_delay_cs = cfs_duration_sec(libcfs_console_max_delay * 100);
rc = proc_dointvec(&dummy, write, buffer, lenp, ppos);
return rc;
}
max_delay_cs = 0;
rc = proc_dointvec(&dummy, write, buffer, lenp, ppos);
if (rc < 0)
return rc;
if (max_delay_cs <= 0)
return -EINVAL;
d = cfs_time_seconds(max_delay_cs) / 100;
if (d == 0 || d < libcfs_console_min_delay)
return -EINVAL;
libcfs_console_max_delay = d;
return rc;
}
int proc_console_min_delay_cs(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int rc, min_delay_cs;
struct ctl_table dummy = *table;
long d;
dummy.data = &min_delay_cs;
dummy.proc_handler = &proc_dointvec;
if (!write) {
min_delay_cs = cfs_duration_sec(libcfs_console_min_delay * 100);
rc = proc_dointvec(&dummy, write, buffer, lenp, ppos);
return rc;
}
min_delay_cs = 0;
rc = proc_dointvec(&dummy, write, buffer, lenp, ppos);
if (rc < 0)
return rc;
if (min_delay_cs <= 0)
return -EINVAL;
d = cfs_time_seconds(min_delay_cs) / 100;
if (d == 0 || d > libcfs_console_max_delay)
return -EINVAL;
libcfs_console_min_delay = d;
return rc;
}
int proc_console_backoff(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int rc, backoff;
struct ctl_table dummy = *table;
dummy.data = &backoff;
dummy.proc_handler = &proc_dointvec;
if (!write) {
backoff= libcfs_console_backoff;
rc = proc_dointvec(&dummy, write, buffer, lenp, ppos);
return rc;
}
backoff = 0;
rc = proc_dointvec(&dummy, write, buffer, lenp, ppos);
if (rc < 0)
return rc;
if (backoff <= 0)
return -EINVAL;
libcfs_console_backoff = backoff;
return rc;
}
int libcfs_force_lbug(struct ctl_table *table, int write, void __user *buffer,
size_t *lenp, loff_t *ppos)
{
if (write)
LBUG();
return 0;
}
int proc_fail_loc(struct ctl_table *table, int write, void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int rc;
long old_fail_loc = cfs_fail_loc;
rc = proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
if (old_fail_loc != cfs_fail_loc)
wake_up(&cfs_race_waitq);
return rc;
}
static int __proc_cpt_table(void *data, int write,
loff_t pos, void __user *buffer, int nob)
{
char *buf = NULL;
int len = 4096;
int rc = 0;
if (write)
return -EPERM;
LASSERT(cfs_cpt_table != NULL);
while (1) {
LIBCFS_ALLOC(buf, len);
if (buf == NULL)
return -ENOMEM;
rc = cfs_cpt_table_print(cfs_cpt_table, buf, len);
if (rc >= 0)
break;
if (rc == -EFBIG) {
LIBCFS_FREE(buf, len);
len <<= 1;
continue;
}
goto out;
}
if (pos >= rc) {
rc = 0;
goto out;
}
rc = cfs_trace_copyout_string(buffer, nob, buf + pos, NULL);
out:
if (buf != NULL)
LIBCFS_FREE(buf, len);
return rc;
}
static int proc_cpt_table(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
return proc_call_handler(table->data, write, ppos, buffer, lenp,
__proc_cpt_table);
}
int insert_proc(void)
{
if (lnet_table_header == NULL)
lnet_table_header = register_sysctl_table(top_table);
return 0;
}
void remove_proc(void)
{
if (lnet_table_header != NULL)
unregister_sysctl_table(lnet_table_header);
lnet_table_header = NULL;
}
