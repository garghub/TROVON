static char *rtas_event_type(int type)
{
if ((type > 0) && (type < 11))
return rtas_type[type];
switch (type) {
case RTAS_TYPE_EPOW:
return "EPOW";
case RTAS_TYPE_PLATFORM:
return "Platform Error";
case RTAS_TYPE_IO:
return "I/O Event";
case RTAS_TYPE_INFO:
return "Platform Information Event";
case RTAS_TYPE_DEALLOC:
return "Resource Deallocation Event";
case RTAS_TYPE_DUMP:
return "Dump Notification Event";
case RTAS_TYPE_PRRN:
return "Platform Resource Reassignment Event";
}
return rtas_type[0];
}
static void printk_log_rtas(char *buf, int len)
{
int i,j,n = 0;
int perline = 16;
char buffer[64];
char * str = "RTAS event";
if (full_rtas_msgs) {
printk(RTAS_DEBUG "%d -------- %s begin --------\n",
error_log_cnt, str);
for (i = 0; i < len; i++) {
j = i % perline;
if (j == 0) {
memset(buffer, 0, sizeof(buffer));
n = sprintf(buffer, "RTAS %d:", i/perline);
}
if ((i % 4) == 0)
n += sprintf(buffer+n, " ");
n += sprintf(buffer+n, "%02x", (unsigned char)buf[i]);
if (j == (perline-1))
printk(KERN_DEBUG "%s\n", buffer);
}
if ((i % perline) != 0)
printk(KERN_DEBUG "%s\n", buffer);
printk(RTAS_DEBUG "%d -------- %s end ----------\n",
error_log_cnt, str);
} else {
struct rtas_error_log *errlog = (struct rtas_error_log *)buf;
printk(RTAS_DEBUG "event: %d, Type: %s, Severity: %d\n",
error_log_cnt, rtas_event_type(rtas_error_type(errlog)),
rtas_error_severity(errlog));
}
}
static int log_rtas_len(char * buf)
{
int len;
struct rtas_error_log *err;
uint32_t extended_log_length;
len = 8;
err = (struct rtas_error_log *)buf;
extended_log_length = rtas_error_extended_log_length(err);
if (rtas_error_extended(err) && extended_log_length) {
len += extended_log_length;
}
if (rtas_error_log_max == 0)
rtas_error_log_max = rtas_get_error_log_max();
if (len > rtas_error_log_max)
len = rtas_error_log_max;
return len;
}
void pSeries_log_error(char *buf, unsigned int err_type, int fatal)
{
unsigned long offset;
unsigned long s;
int len = 0;
pr_debug("rtasd: logging event\n");
if (buf == NULL)
return;
spin_lock_irqsave(&rtasd_log_lock, s);
switch (err_type & ERR_TYPE_MASK) {
case ERR_TYPE_RTAS_LOG:
len = log_rtas_len(buf);
if (!(err_type & ERR_FLAG_BOOT))
error_log_cnt++;
break;
case ERR_TYPE_KERNEL_PANIC:
default:
WARN_ON_ONCE(!irqs_disabled());
spin_unlock_irqrestore(&rtasd_log_lock, s);
return;
}
#ifdef CONFIG_PPC64
if (logging_enabled && !(err_type & ERR_FLAG_BOOT))
nvram_write_error_log(buf, len, err_type, error_log_cnt);
#endif
if ((err_type & ERR_TYPE_MASK) == ERR_TYPE_RTAS_LOG)
printk_log_rtas(buf, len);
if (fatal || !logging_enabled) {
logging_enabled = 0;
WARN_ON_ONCE(!irqs_disabled());
spin_unlock_irqrestore(&rtasd_log_lock, s);
return;
}
switch (err_type & ERR_TYPE_MASK) {
case ERR_TYPE_RTAS_LOG:
offset = rtas_error_log_buffer_max *
((rtas_log_start+rtas_log_size) & LOG_NUMBER_MASK);
memcpy(&rtas_log_buf[offset], (void *) &error_log_cnt, sizeof(int));
offset += sizeof(int);
memcpy(&rtas_log_buf[offset], buf, len);
if (rtas_log_size < LOG_NUMBER)
rtas_log_size += 1;
else
rtas_log_start += 1;
WARN_ON_ONCE(!irqs_disabled());
spin_unlock_irqrestore(&rtasd_log_lock, s);
wake_up_interruptible(&rtas_log_wait);
break;
case ERR_TYPE_KERNEL_PANIC:
default:
WARN_ON_ONCE(!irqs_disabled());
spin_unlock_irqrestore(&rtasd_log_lock, s);
return;
}
}
static void prrn_work_fn(struct work_struct *work)
{
pseries_devicetree_update(-prrn_update_scope);
}
static void prrn_schedule_update(u32 scope)
{
flush_work(&prrn_work);
prrn_update_scope = scope;
schedule_work(&prrn_work);
}
static void handle_rtas_event(const struct rtas_error_log *log)
{
if (rtas_error_type(log) != RTAS_TYPE_PRRN || !prrn_is_enabled())
return;
prrn_schedule_update(rtas_error_extended_log_length(log));
}
static void handle_rtas_event(const struct rtas_error_log *log)
{
return;
}
static int rtas_log_open(struct inode * inode, struct file * file)
{
return 0;
}
static int rtas_log_release(struct inode * inode, struct file * file)
{
return 0;
}
static ssize_t rtas_log_read(struct file * file, char __user * buf,
size_t count, loff_t *ppos)
{
int error;
char *tmp;
unsigned long s;
unsigned long offset;
if (!buf || count < rtas_error_log_buffer_max)
return -EINVAL;
count = rtas_error_log_buffer_max;
if (!access_ok(VERIFY_WRITE, buf, count))
return -EFAULT;
tmp = kmalloc(count, GFP_KERNEL);
if (!tmp)
return -ENOMEM;
spin_lock_irqsave(&rtasd_log_lock, s);
while (rtas_log_size == 0) {
if (file->f_flags & O_NONBLOCK) {
spin_unlock_irqrestore(&rtasd_log_lock, s);
error = -EAGAIN;
goto out;
}
if (!logging_enabled) {
spin_unlock_irqrestore(&rtasd_log_lock, s);
error = -ENODATA;
goto out;
}
#ifdef CONFIG_PPC64
nvram_clear_error_log();
#endif
spin_unlock_irqrestore(&rtasd_log_lock, s);
error = wait_event_interruptible(rtas_log_wait, rtas_log_size);
if (error)
goto out;
spin_lock_irqsave(&rtasd_log_lock, s);
}
offset = rtas_error_log_buffer_max * (rtas_log_start & LOG_NUMBER_MASK);
memcpy(tmp, &rtas_log_buf[offset], count);
rtas_log_start += 1;
rtas_log_size -= 1;
spin_unlock_irqrestore(&rtasd_log_lock, s);
error = copy_to_user(buf, tmp, count) ? -EFAULT : count;
out:
kfree(tmp);
return error;
}
static unsigned int rtas_log_poll(struct file *file, poll_table * wait)
{
poll_wait(file, &rtas_log_wait, wait);
if (rtas_log_size)
return POLLIN | POLLRDNORM;
return 0;
}
static int enable_surveillance(int timeout)
{
int error;
error = rtas_set_indicator(SURVEILLANCE_TOKEN, 0, timeout);
if (error == 0)
return 0;
if (error == -EINVAL) {
printk(KERN_DEBUG "rtasd: surveillance not supported\n");
return 0;
}
printk(KERN_ERR "rtasd: could not update surveillance\n");
return -1;
}
static void do_event_scan(void)
{
int error;
do {
memset(logdata, 0, rtas_error_log_max);
error = rtas_call(event_scan, 4, 1, NULL,
RTAS_EVENT_SCAN_ALL_EVENTS, 0,
__pa(logdata), rtas_error_log_max);
if (error == -1) {
printk(KERN_ERR "event-scan failed\n");
break;
}
if (error == 0) {
pSeries_log_error(logdata, ERR_TYPE_RTAS_LOG, 0);
handle_rtas_event((struct rtas_error_log *)logdata);
}
} while(error == 0);
}
static void rtas_event_scan(struct work_struct *w)
{
unsigned int cpu;
do_event_scan();
get_online_cpus();
cpu = cpumask_next(raw_smp_processor_id(), cpu_online_mask);
if (cpu >= nr_cpu_ids) {
cpu = cpumask_first(cpu_online_mask);
if (first_pass) {
first_pass = 0;
event_scan_delay = 30*HZ/rtas_event_scan_rate;
if (surveillance_timeout != -1) {
pr_debug("rtasd: enabling surveillance\n");
enable_surveillance(surveillance_timeout);
pr_debug("rtasd: surveillance enabled\n");
}
}
}
schedule_delayed_work_on(cpu, &event_scan_work,
__round_jiffies_relative(event_scan_delay, cpu));
put_online_cpus();
}
static void retreive_nvram_error_log(void)
{
unsigned int err_type ;
int rc ;
memset(logdata, 0, rtas_error_log_max);
rc = nvram_read_error_log(logdata, rtas_error_log_max,
&err_type, &error_log_cnt);
logging_enabled = 1;
if (!rc) {
if (err_type != ERR_FLAG_ALREADY_LOGGED) {
pSeries_log_error(logdata, err_type | ERR_FLAG_BOOT, 0);
}
}
}
static void retreive_nvram_error_log(void)
{
}
static void start_event_scan(void)
{
printk(KERN_DEBUG "RTAS daemon started\n");
pr_debug("rtasd: will sleep for %d milliseconds\n",
(30000 / rtas_event_scan_rate));
retreive_nvram_error_log();
schedule_delayed_work_on(cpumask_first(cpu_online_mask),
&event_scan_work, event_scan_delay);
}
void rtas_cancel_event_scan(void)
{
cancel_delayed_work_sync(&event_scan_work);
}
static int __init rtas_init(void)
{
struct proc_dir_entry *entry;
if (!machine_is(pseries) && !machine_is(chrp))
return 0;
event_scan = rtas_token("event-scan");
if (event_scan == RTAS_UNKNOWN_SERVICE) {
printk(KERN_INFO "rtasd: No event-scan on system\n");
return -ENODEV;
}
rtas_event_scan_rate = rtas_token("rtas-event-scan-rate");
if (rtas_event_scan_rate == RTAS_UNKNOWN_SERVICE) {
printk(KERN_ERR "rtasd: no rtas-event-scan-rate on system\n");
return -ENODEV;
}
if (!rtas_event_scan_rate) {
printk(KERN_DEBUG "rtasd: scan rate is 0, not scanning\n");
return 0;
}
rtas_error_log_max = rtas_get_error_log_max();
rtas_error_log_buffer_max = rtas_error_log_max + sizeof(int);
rtas_log_buf = vmalloc(rtas_error_log_buffer_max*LOG_NUMBER);
if (!rtas_log_buf) {
printk(KERN_ERR "rtasd: no memory\n");
return -ENOMEM;
}
entry = proc_create("powerpc/rtas/error_log", S_IRUSR, NULL,
&proc_rtas_log_operations);
if (!entry)
printk(KERN_ERR "Failed to create error_log proc entry\n");
start_event_scan();
return 0;
}
static int __init surveillance_setup(char *str)
{
int i;
if (!machine_is(pseries))
return 0;
if (get_option(&str,&i)) {
if (i >= 0 && i <= 255)
surveillance_timeout = i;
}
return 1;
}
static int __init rtasmsgs_setup(char *str)
{
return (kstrtobool(str, &full_rtas_msgs) == 0);
}
