static void
salinfo_work_to_do(struct salinfo_data *data)
{
(void)(down_trylock(&data->mutex) ?: 0);
up(&data->mutex);
}
static void
salinfo_platform_oemdata_cpu(void *context)
{
struct salinfo_platform_oemdata_parms *parms = context;
parms->ret = salinfo_platform_oemdata(parms->efi_guid, parms->oemdata, parms->oemdata_size);
}
static void
shift1_data_saved (struct salinfo_data *data, int shift)
{
memcpy(data->data_saved+shift, data->data_saved+shift+1,
(ARRAY_SIZE(data->data_saved) - (shift+1)) * sizeof(data->data_saved[0]));
memset(data->data_saved + ARRAY_SIZE(data->data_saved) - 1, 0,
sizeof(data->data_saved[0]));
}
void
salinfo_log_wakeup(int type, u8 *buffer, u64 size, int irqsafe)
{
struct salinfo_data *data = salinfo_data + type;
struct salinfo_data_saved *data_saved;
unsigned long flags = 0;
int i;
int saved_size = ARRAY_SIZE(data->data_saved);
BUG_ON(type >= ARRAY_SIZE(salinfo_log_name));
if (irqsafe)
spin_lock_irqsave(&data_saved_lock, flags);
if (buffer) {
for (i = 0, data_saved = data->data_saved; i < saved_size; ++i, ++data_saved) {
if (!data_saved->buffer)
break;
}
if (i == saved_size) {
if (!data->saved_num) {
shift1_data_saved(data, 0);
data_saved = data->data_saved + saved_size - 1;
} else
data_saved = NULL;
}
if (data_saved) {
data_saved->cpu = smp_processor_id();
data_saved->id = ((sal_log_record_header_t *)buffer)->id;
data_saved->size = size;
data_saved->buffer = buffer;
}
}
cpu_set(smp_processor_id(), data->cpu_event);
if (irqsafe) {
salinfo_work_to_do(data);
spin_unlock_irqrestore(&data_saved_lock, flags);
}
}
static void
salinfo_timeout_check(struct salinfo_data *data)
{
unsigned long flags;
if (!data->open)
return;
if (!cpus_empty(data->cpu_event)) {
spin_lock_irqsave(&data_saved_lock, flags);
salinfo_work_to_do(data);
spin_unlock_irqrestore(&data_saved_lock, flags);
}
}
static void
salinfo_timeout (unsigned long arg)
{
ia64_mlogbuf_dump();
salinfo_timeout_check(salinfo_data + SAL_INFO_TYPE_MCA);
salinfo_timeout_check(salinfo_data + SAL_INFO_TYPE_INIT);
salinfo_timer.expires = jiffies + SALINFO_TIMER_DELAY;
add_timer(&salinfo_timer);
}
static int
salinfo_event_open(struct inode *inode, struct file *file)
{
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
return 0;
}
static ssize_t
salinfo_event_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
struct salinfo_data *data = PDE_DATA(file_inode(file));
char cmd[32];
size_t size;
int i, n, cpu = -1;
retry:
if (cpus_empty(data->cpu_event) && down_trylock(&data->mutex)) {
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
if (down_interruptible(&data->mutex))
return -EINTR;
}
n = data->cpu_check;
for (i = 0; i < nr_cpu_ids; i++) {
if (cpu_isset(n, data->cpu_event)) {
if (!cpu_online(n)) {
cpu_clear(n, data->cpu_event);
continue;
}
cpu = n;
break;
}
if (++n == nr_cpu_ids)
n = 0;
}
if (cpu == -1)
goto retry;
ia64_mlogbuf_dump();
data->cpu_check = cpu;
if (++data->cpu_check == nr_cpu_ids)
data->cpu_check = 0;
snprintf(cmd, sizeof(cmd), "read %d\n", cpu);
size = strlen(cmd);
if (size > count)
size = count;
if (copy_to_user(buffer, cmd, size))
return -EFAULT;
return size;
}
static int
salinfo_log_open(struct inode *inode, struct file *file)
{
struct salinfo_data *data = PDE_DATA(inode);
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
spin_lock(&data_lock);
if (data->open) {
spin_unlock(&data_lock);
return -EBUSY;
}
data->open = 1;
spin_unlock(&data_lock);
if (data->state == STATE_NO_DATA &&
!(data->log_buffer = vmalloc(ia64_sal_get_state_info_size(data->type)))) {
data->open = 0;
return -ENOMEM;
}
return 0;
}
static int
salinfo_log_release(struct inode *inode, struct file *file)
{
struct salinfo_data *data = PDE_DATA(inode);
if (data->state == STATE_NO_DATA) {
vfree(data->log_buffer);
vfree(data->oemdata);
data->log_buffer = NULL;
data->oemdata = NULL;
}
spin_lock(&data_lock);
data->open = 0;
spin_unlock(&data_lock);
return 0;
}
static void
call_on_cpu(int cpu, void (*fn)(void *), void *arg)
{
cpumask_t save_cpus_allowed = current->cpus_allowed;
set_cpus_allowed_ptr(current, cpumask_of(cpu));
(*fn)(arg);
set_cpus_allowed_ptr(current, &save_cpus_allowed);
}
static void
salinfo_log_read_cpu(void *context)
{
struct salinfo_data *data = context;
sal_log_record_header_t *rh;
data->log_size = ia64_sal_get_state_info(data->type, (u64 *) data->log_buffer);
rh = (sal_log_record_header_t *)(data->log_buffer);
if (rh->severity == sal_log_severity_corrected)
ia64_sal_clear_state_info(data->type);
}
static void
salinfo_log_new_read(int cpu, struct salinfo_data *data)
{
struct salinfo_data_saved *data_saved;
unsigned long flags;
int i;
int saved_size = ARRAY_SIZE(data->data_saved);
data->saved_num = 0;
spin_lock_irqsave(&data_saved_lock, flags);
retry:
for (i = 0, data_saved = data->data_saved; i < saved_size; ++i, ++data_saved) {
if (data_saved->buffer && data_saved->cpu == cpu) {
sal_log_record_header_t *rh = (sal_log_record_header_t *)(data_saved->buffer);
data->log_size = data_saved->size;
memcpy(data->log_buffer, rh, data->log_size);
barrier();
if (rh->id == data_saved->id) {
data->saved_num = i+1;
break;
}
shift1_data_saved(data, i);
goto retry;
}
}
spin_unlock_irqrestore(&data_saved_lock, flags);
if (!data->saved_num)
call_on_cpu(cpu, salinfo_log_read_cpu, data);
if (!data->log_size) {
data->state = STATE_NO_DATA;
cpu_clear(cpu, data->cpu_event);
} else {
data->state = STATE_LOG_RECORD;
}
}
static ssize_t
salinfo_log_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
struct salinfo_data *data = PDE_DATA(file_inode(file));
u8 *buf;
u64 bufsize;
if (data->state == STATE_LOG_RECORD) {
buf = data->log_buffer;
bufsize = data->log_size;
} else if (data->state == STATE_OEMDATA) {
buf = data->oemdata;
bufsize = data->oemdata_size;
} else {
buf = NULL;
bufsize = 0;
}
return simple_read_from_buffer(buffer, count, ppos, buf, bufsize);
}
static void
salinfo_log_clear_cpu(void *context)
{
struct salinfo_data *data = context;
ia64_sal_clear_state_info(data->type);
}
static int
salinfo_log_clear(struct salinfo_data *data, int cpu)
{
sal_log_record_header_t *rh;
unsigned long flags;
spin_lock_irqsave(&data_saved_lock, flags);
data->state = STATE_NO_DATA;
if (!cpu_isset(cpu, data->cpu_event)) {
spin_unlock_irqrestore(&data_saved_lock, flags);
return 0;
}
cpu_clear(cpu, data->cpu_event);
if (data->saved_num) {
shift1_data_saved(data, data->saved_num - 1);
data->saved_num = 0;
}
spin_unlock_irqrestore(&data_saved_lock, flags);
rh = (sal_log_record_header_t *)(data->log_buffer);
if (rh->severity != sal_log_severity_corrected)
call_on_cpu(cpu, salinfo_log_clear_cpu, data);
salinfo_log_new_read(cpu, data);
if (data->state == STATE_LOG_RECORD) {
spin_lock_irqsave(&data_saved_lock, flags);
cpu_set(cpu, data->cpu_event);
salinfo_work_to_do(data);
spin_unlock_irqrestore(&data_saved_lock, flags);
}
return 0;
}
static ssize_t
salinfo_log_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
struct salinfo_data *data = PDE_DATA(file_inode(file));
char cmd[32];
size_t size;
u32 offset;
int cpu;
size = sizeof(cmd);
if (count < size)
size = count;
if (copy_from_user(cmd, buffer, size))
return -EFAULT;
if (sscanf(cmd, "read %d", &cpu) == 1) {
salinfo_log_new_read(cpu, data);
} else if (sscanf(cmd, "clear %d", &cpu) == 1) {
int ret;
if ((ret = salinfo_log_clear(data, cpu)))
count = ret;
} else if (sscanf(cmd, "oemdata %d %d", &cpu, &offset) == 2) {
if (data->state != STATE_LOG_RECORD && data->state != STATE_OEMDATA)
return -EINVAL;
if (offset > data->log_size - sizeof(efi_guid_t))
return -EINVAL;
data->state = STATE_OEMDATA;
if (salinfo_platform_oemdata) {
struct salinfo_platform_oemdata_parms parms = {
.efi_guid = data->log_buffer + offset,
.oemdata = &data->oemdata,
.oemdata_size = &data->oemdata_size
};
call_on_cpu(cpu, salinfo_platform_oemdata_cpu, &parms);
if (parms.ret)
count = parms.ret;
} else
data->oemdata_size = 0;
} else
return -EINVAL;
return count;
}
static int __cpuinit
salinfo_cpu_callback(struct notifier_block *nb, unsigned long action, void *hcpu)
{
unsigned int i, cpu = (unsigned long)hcpu;
unsigned long flags;
struct salinfo_data *data;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
spin_lock_irqsave(&data_saved_lock, flags);
for (i = 0, data = salinfo_data;
i < ARRAY_SIZE(salinfo_data);
++i, ++data) {
cpu_set(cpu, data->cpu_event);
salinfo_work_to_do(data);
}
spin_unlock_irqrestore(&data_saved_lock, flags);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
spin_lock_irqsave(&data_saved_lock, flags);
for (i = 0, data = salinfo_data;
i < ARRAY_SIZE(salinfo_data);
++i, ++data) {
struct salinfo_data_saved *data_saved;
int j;
for (j = ARRAY_SIZE(data->data_saved) - 1, data_saved = data->data_saved + j;
j >= 0;
--j, --data_saved) {
if (data_saved->buffer && data_saved->cpu == cpu) {
shift1_data_saved(data, j);
}
}
cpu_clear(cpu, data->cpu_event);
}
spin_unlock_irqrestore(&data_saved_lock, flags);
break;
}
return NOTIFY_OK;
}
static int __init
salinfo_init(void)
{
struct proc_dir_entry *salinfo_dir;
struct proc_dir_entry **sdir = salinfo_proc_entries;
struct proc_dir_entry *dir, *entry;
struct salinfo_data *data;
int i, j;
salinfo_dir = proc_mkdir("sal", NULL);
if (!salinfo_dir)
return 0;
for (i=0; i < NR_SALINFO_ENTRIES; i++) {
*sdir++ = proc_create_data(salinfo_entries[i].name, 0, salinfo_dir,
&proc_salinfo_fops,
(void *)salinfo_entries[i].feature);
}
for (i = 0; i < ARRAY_SIZE(salinfo_log_name); i++) {
data = salinfo_data + i;
data->type = i;
sema_init(&data->mutex, 1);
dir = proc_mkdir(salinfo_log_name[i], salinfo_dir);
if (!dir)
continue;
entry = proc_create_data("event", S_IRUSR, dir,
&salinfo_event_fops, data);
if (!entry)
continue;
*sdir++ = entry;
entry = proc_create_data("data", S_IRUSR | S_IWUSR, dir,
&salinfo_data_fops, data);
if (!entry)
continue;
*sdir++ = entry;
for_each_online_cpu(j)
cpu_set(j, data->cpu_event);
*sdir++ = dir;
}
*sdir++ = salinfo_dir;
init_timer(&salinfo_timer);
salinfo_timer.expires = jiffies + SALINFO_TIMER_DELAY;
salinfo_timer.function = &salinfo_timeout;
add_timer(&salinfo_timer);
register_hotcpu_notifier(&salinfo_cpu_notifier);
return 0;
}
static int proc_salinfo_show(struct seq_file *m, void *v)
{
unsigned long data = (unsigned long)v;
seq_puts(m, (sal_platform_features & data) ? "1\n" : "0\n");
return 0;
}
static int proc_salinfo_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_salinfo_show, PDE_DATA(inode));
}
