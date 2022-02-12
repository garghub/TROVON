void log_buf_kexec_setup(void)
{
VMCOREINFO_SYMBOL(log_buf);
VMCOREINFO_SYMBOL(log_end);
VMCOREINFO_SYMBOL(log_buf_len);
VMCOREINFO_SYMBOL(logged_chars);
}
static int __init log_buf_len_setup(char *str)
{
unsigned size = memparse(str, &str);
if (size)
size = roundup_pow_of_two(size);
if (size > log_buf_len)
new_log_buf_len = size;
return 0;
}
void __init setup_log_buf(int early)
{
unsigned long flags;
unsigned start, dest_idx, offset;
char *new_log_buf;
int free;
if (!new_log_buf_len)
return;
if (early) {
unsigned long mem;
mem = memblock_alloc(new_log_buf_len, PAGE_SIZE);
if (mem == MEMBLOCK_ERROR)
return;
new_log_buf = __va(mem);
} else {
new_log_buf = alloc_bootmem_nopanic(new_log_buf_len);
}
if (unlikely(!new_log_buf)) {
pr_err("log_buf_len: %ld bytes not available\n",
new_log_buf_len);
return;
}
spin_lock_irqsave(&logbuf_lock, flags);
log_buf_len = new_log_buf_len;
log_buf = new_log_buf;
new_log_buf_len = 0;
free = __LOG_BUF_LEN - log_end;
offset = start = min(con_start, log_start);
dest_idx = 0;
while (start != log_end) {
unsigned log_idx_mask = start & (__LOG_BUF_LEN - 1);
log_buf[dest_idx] = __log_buf[log_idx_mask];
start++;
dest_idx++;
}
log_start -= offset;
con_start -= offset;
log_end -= offset;
spin_unlock_irqrestore(&logbuf_lock, flags);
pr_info("log_buf_len: %d\n", log_buf_len);
pr_info("early log buf free: %d(%d%%)\n",
free, (free * 100) / __LOG_BUF_LEN);
}
static int __init boot_delay_setup(char *str)
{
unsigned long lpj;
lpj = preset_lpj ? preset_lpj : 1000000;
loops_per_msec = (unsigned long long)lpj / 1000 * HZ;
get_option(&str, &boot_delay);
if (boot_delay > 10 * 1000)
boot_delay = 0;
pr_debug("boot_delay: %u, preset_lpj: %ld, lpj: %lu, "
"HZ: %d, loops_per_msec: %llu\n",
boot_delay, preset_lpj, lpj, HZ, loops_per_msec);
return 1;
}
static void boot_delay_msec(void)
{
unsigned long long k;
unsigned long timeout;
if (boot_delay == 0 || system_state != SYSTEM_BOOTING)
return;
k = (unsigned long long)loops_per_msec * boot_delay;
timeout = jiffies + msecs_to_jiffies(boot_delay);
while (k) {
k--;
cpu_relax();
if (time_after(jiffies, timeout))
break;
touch_nmi_watchdog();
}
}
static inline void boot_delay_msec(void)
{
}
static int syslog_action_restricted(int type)
{
if (dmesg_restrict)
return 1;
return type != SYSLOG_ACTION_READ_ALL && type != SYSLOG_ACTION_SIZE_BUFFER;
}
static int check_syslog_permissions(int type, bool from_file)
{
if (from_file && type != SYSLOG_ACTION_OPEN)
return 0;
if (syslog_action_restricted(type)) {
if (capable(CAP_SYSLOG))
return 0;
if (capable(CAP_SYS_ADMIN)) {
WARN_ONCE(1, "Attempt to access syslog with CAP_SYS_ADMIN "
"but no CAP_SYSLOG (deprecated).\n");
return 0;
}
return -EPERM;
}
return 0;
}
int do_syslog(int type, char __user *buf, int len, bool from_file)
{
unsigned i, j, limit, count;
int do_clear = 0;
char c;
int error;
error = check_syslog_permissions(type, from_file);
if (error)
goto out;
error = security_syslog(type);
if (error)
return error;
switch (type) {
case SYSLOG_ACTION_CLOSE:
break;
case SYSLOG_ACTION_OPEN:
break;
case SYSLOG_ACTION_READ:
error = -EINVAL;
if (!buf || len < 0)
goto out;
error = 0;
if (!len)
goto out;
if (!access_ok(VERIFY_WRITE, buf, len)) {
error = -EFAULT;
goto out;
}
error = wait_event_interruptible(log_wait,
(log_start - log_end));
if (error)
goto out;
i = 0;
spin_lock_irq(&logbuf_lock);
while (!error && (log_start != log_end) && i < len) {
c = LOG_BUF(log_start);
log_start++;
spin_unlock_irq(&logbuf_lock);
error = __put_user(c,buf);
buf++;
i++;
cond_resched();
spin_lock_irq(&logbuf_lock);
}
spin_unlock_irq(&logbuf_lock);
if (!error)
error = i;
break;
case SYSLOG_ACTION_READ_CLEAR:
do_clear = 1;
case SYSLOG_ACTION_READ_ALL:
error = -EINVAL;
if (!buf || len < 0)
goto out;
error = 0;
if (!len)
goto out;
if (!access_ok(VERIFY_WRITE, buf, len)) {
error = -EFAULT;
goto out;
}
count = len;
if (count > log_buf_len)
count = log_buf_len;
spin_lock_irq(&logbuf_lock);
if (count > logged_chars)
count = logged_chars;
if (do_clear)
logged_chars = 0;
limit = log_end;
for (i = 0; i < count && !error; i++) {
j = limit-1-i;
if (j + log_buf_len < log_end)
break;
c = LOG_BUF(j);
spin_unlock_irq(&logbuf_lock);
error = __put_user(c,&buf[count-1-i]);
cond_resched();
spin_lock_irq(&logbuf_lock);
}
spin_unlock_irq(&logbuf_lock);
if (error)
break;
error = i;
if (i != count) {
int offset = count-error;
for (i = 0; i < error; i++) {
if (__get_user(c,&buf[i+offset]) ||
__put_user(c,&buf[i])) {
error = -EFAULT;
break;
}
cond_resched();
}
}
break;
case SYSLOG_ACTION_CLEAR:
logged_chars = 0;
break;
case SYSLOG_ACTION_CONSOLE_OFF:
if (saved_console_loglevel == -1)
saved_console_loglevel = console_loglevel;
console_loglevel = minimum_console_loglevel;
break;
case SYSLOG_ACTION_CONSOLE_ON:
if (saved_console_loglevel != -1) {
console_loglevel = saved_console_loglevel;
saved_console_loglevel = -1;
}
break;
case SYSLOG_ACTION_CONSOLE_LEVEL:
error = -EINVAL;
if (len < 1 || len > 8)
goto out;
if (len < minimum_console_loglevel)
len = minimum_console_loglevel;
console_loglevel = len;
saved_console_loglevel = -1;
error = 0;
break;
case SYSLOG_ACTION_SIZE_UNREAD:
error = log_end - log_start;
break;
case SYSLOG_ACTION_SIZE_BUFFER:
error = log_buf_len;
break;
default:
error = -EINVAL;
break;
}
out:
return error;
}
void kdb_syslog_data(char *syslog_data[4])
{
syslog_data[0] = log_buf;
syslog_data[1] = log_buf + log_buf_len;
syslog_data[2] = log_buf + log_end -
(logged_chars < log_buf_len ? logged_chars : log_buf_len);
syslog_data[3] = log_buf + log_end;
}
static void __call_console_drivers(unsigned start, unsigned end)
{
struct console *con;
for_each_console(con) {
if (exclusive_console && con != exclusive_console)
continue;
if ((con->flags & CON_ENABLED) && con->write &&
(cpu_online(smp_processor_id()) ||
(con->flags & CON_ANYTIME)))
con->write(con, &LOG_BUF(start), end - start);
}
}
static int __init ignore_loglevel_setup(char *str)
{
ignore_loglevel = 1;
printk(KERN_INFO "debug: ignoring loglevel setting.\n");
return 0;
}
static void _call_console_drivers(unsigned start,
unsigned end, int msg_log_level)
{
if ((msg_log_level < console_loglevel || ignore_loglevel) &&
console_drivers && start != end) {
if ((start & LOG_BUF_MASK) > (end & LOG_BUF_MASK)) {
__call_console_drivers(start & LOG_BUF_MASK,
log_buf_len);
__call_console_drivers(0, end & LOG_BUF_MASK);
} else {
__call_console_drivers(start, end);
}
}
}
static size_t log_prefix(const char *p, unsigned int *level, char *special)
{
unsigned int lev = 0;
char sp = '\0';
size_t len;
if (p[0] != '<' || !p[1])
return 0;
if (p[2] == '>') {
switch (p[1]) {
case '0' ... '7':
lev = p[1] - '0';
break;
case 'c':
case 'd':
sp = p[1];
break;
default:
return 0;
}
len = 3;
} else {
char *endp = NULL;
if (p[1] < '0' && p[1] > '9')
return 0;
lev = (simple_strtoul(&p[1], &endp, 10) & 7);
if (endp == NULL || endp[0] != '>')
return 0;
len = (endp + 1) - p;
}
if (sp && !special)
return 0;
if (special) {
*special = sp;
if (sp)
return len;
}
if (level)
*level = lev;
return len;
}
static void call_console_drivers(unsigned start, unsigned end)
{
unsigned cur_index, start_print;
static int msg_level = -1;
BUG_ON(((int)(start - end)) > 0);
cur_index = start;
start_print = start;
while (cur_index != end) {
if (msg_level < 0 && ((end - cur_index) > 2)) {
cur_index += log_prefix(&LOG_BUF(cur_index), &msg_level, NULL);
start_print = cur_index;
}
while (cur_index != end) {
char c = LOG_BUF(cur_index);
cur_index++;
if (c == '\n') {
if (msg_level < 0) {
msg_level = default_message_loglevel;
}
_call_console_drivers(start_print, cur_index, msg_level);
msg_level = -1;
start_print = cur_index;
break;
}
}
}
_call_console_drivers(start_print, end, msg_level);
}
static void emit_log_char(char c)
{
LOG_BUF(log_end) = c;
log_end++;
if (log_end - log_start > log_buf_len)
log_start = log_end - log_buf_len;
if (log_end - con_start > log_buf_len)
con_start = log_end - log_buf_len;
if (logged_chars < log_buf_len)
logged_chars++;
}
static void zap_locks(void)
{
static unsigned long oops_timestamp;
if (time_after_eq(jiffies, oops_timestamp) &&
!time_after(jiffies, oops_timestamp + 30 * HZ))
return;
oops_timestamp = jiffies;
spin_lock_init(&logbuf_lock);
sema_init(&console_sem, 1);
}
static int have_callable_console(void)
{
struct console *con;
for_each_console(con)
if (con->flags & CON_ANYTIME)
return 1;
return 0;
}
asmlinkage int printk(const char *fmt, ...)
{
va_list args;
int r;
#ifdef CONFIG_KGDB_KDB
if (unlikely(kdb_trap_printk)) {
va_start(args, fmt);
r = vkdb_printf(fmt, args);
va_end(args);
return r;
}
#endif
va_start(args, fmt);
r = vprintk(fmt, args);
va_end(args);
return r;
}
static inline int can_use_console(unsigned int cpu)
{
return cpu_online(cpu) || have_callable_console();
}
static int console_trylock_for_printk(unsigned int cpu)
__releases(&logbuf_lock
static inline void printk_delay(void)
{
if (unlikely(printk_delay_msec)) {
int m = printk_delay_msec;
while (m--) {
mdelay(1);
touch_nmi_watchdog();
}
}
}
asmlinkage int vprintk(const char *fmt, va_list args)
{
int printed_len = 0;
int current_log_level = default_message_loglevel;
unsigned long flags;
int this_cpu;
char *p;
size_t plen;
char special;
boot_delay_msec();
printk_delay();
preempt_disable();
raw_local_irq_save(flags);
this_cpu = smp_processor_id();
if (unlikely(printk_cpu == this_cpu)) {
if (!oops_in_progress) {
recursion_bug = 1;
goto out_restore_irqs;
}
zap_locks();
}
lockdep_off();
spin_lock(&logbuf_lock);
printk_cpu = this_cpu;
if (recursion_bug) {
recursion_bug = 0;
strcpy(printk_buf, recursion_bug_msg);
printed_len = strlen(recursion_bug_msg);
}
printed_len += vscnprintf(printk_buf + printed_len,
sizeof(printk_buf) - printed_len, fmt, args);
p = printk_buf;
plen = log_prefix(p, &current_log_level, &special);
if (plen) {
p += plen;
switch (special) {
case 'c':
plen = 0;
break;
case 'd':
plen = 0;
default:
if (!new_text_line) {
emit_log_char('\n');
new_text_line = 1;
}
}
}
for (; *p; p++) {
if (new_text_line) {
new_text_line = 0;
if (plen) {
int i;
for (i = 0; i < plen; i++)
emit_log_char(printk_buf[i]);
printed_len += plen;
} else {
emit_log_char('<');
emit_log_char(current_log_level + '0');
emit_log_char('>');
printed_len += 3;
}
if (printk_time) {
char tbuf[50], *tp;
unsigned tlen;
unsigned long long t;
unsigned long nanosec_rem;
t = cpu_clock(printk_cpu);
nanosec_rem = do_div(t, 1000000000);
tlen = sprintf(tbuf, "[%5lu.%06lu] ",
(unsigned long) t,
nanosec_rem / 1000);
for (tp = tbuf; tp < tbuf + tlen; tp++)
emit_log_char(*tp);
printed_len += tlen;
}
if (!*p)
break;
}
emit_log_char(*p);
if (*p == '\n')
new_text_line = 1;
}
if (console_trylock_for_printk(this_cpu))
console_unlock();
lockdep_on();
out_restore_irqs:
raw_local_irq_restore(flags);
preempt_enable();
return printed_len;
}
static void call_console_drivers(unsigned start, unsigned end)
{
}
static int __add_preferred_console(char *name, int idx, char *options,
char *brl_options)
{
struct console_cmdline *c;
int i;
for (i = 0; i < MAX_CMDLINECONSOLES && console_cmdline[i].name[0]; i++)
if (strcmp(console_cmdline[i].name, name) == 0 &&
console_cmdline[i].index == idx) {
if (!brl_options)
selected_console = i;
return 0;
}
if (i == MAX_CMDLINECONSOLES)
return -E2BIG;
if (!brl_options)
selected_console = i;
c = &console_cmdline[i];
strlcpy(c->name, name, sizeof(c->name));
c->options = options;
#ifdef CONFIG_A11Y_BRAILLE_CONSOLE
c->brl_options = brl_options;
#endif
c->index = idx;
return 0;
}
static int __init console_setup(char *str)
{
char buf[sizeof(console_cmdline[0].name) + 4];
char *s, *options, *brl_options = NULL;
int idx;
#ifdef CONFIG_A11Y_BRAILLE_CONSOLE
if (!memcmp(str, "brl,", 4)) {
brl_options = "";
str += 4;
} else if (!memcmp(str, "brl=", 4)) {
brl_options = str + 4;
str = strchr(brl_options, ',');
if (!str) {
printk(KERN_ERR "need port name after brl=\n");
return 1;
}
*(str++) = 0;
}
#endif
if (str[0] >= '0' && str[0] <= '9') {
strcpy(buf, "ttyS");
strncpy(buf + 4, str, sizeof(buf) - 5);
} else {
strncpy(buf, str, sizeof(buf) - 1);
}
buf[sizeof(buf) - 1] = 0;
if ((options = strchr(str, ',')) != NULL)
*(options++) = 0;
#ifdef __sparc__
if (!strcmp(str, "ttya"))
strcpy(buf, "ttyS0");
if (!strcmp(str, "ttyb"))
strcpy(buf, "ttyS1");
#endif
for (s = buf; *s; s++)
if ((*s >= '0' && *s <= '9') || *s == ',')
break;
idx = simple_strtoul(s, NULL, 10);
*s = 0;
__add_preferred_console(buf, idx, options, brl_options);
console_set_on_cmdline = 1;
return 1;
}
int add_preferred_console(char *name, int idx, char *options)
{
return __add_preferred_console(name, idx, options, NULL);
}
int update_console_cmdline(char *name, int idx, char *name_new, int idx_new, char *options)
{
struct console_cmdline *c;
int i;
for (i = 0; i < MAX_CMDLINECONSOLES && console_cmdline[i].name[0]; i++)
if (strcmp(console_cmdline[i].name, name) == 0 &&
console_cmdline[i].index == idx) {
c = &console_cmdline[i];
strlcpy(c->name, name_new, sizeof(c->name));
c->name[sizeof(c->name) - 1] = 0;
c->options = options;
c->index = idx_new;
return i;
}
return -1;
}
static int __init console_suspend_disable(char *str)
{
console_suspend_enabled = 0;
return 1;
}
void suspend_console(void)
{
if (!console_suspend_enabled)
return;
printk("Suspending console(s) (use no_console_suspend to debug)\n");
console_lock();
console_suspended = 1;
up(&console_sem);
}
void resume_console(void)
{
if (!console_suspend_enabled)
return;
down(&console_sem);
console_suspended = 0;
console_unlock();
}
static int __cpuinit console_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action) {
case CPU_ONLINE:
case CPU_DEAD:
case CPU_DYING:
case CPU_DOWN_FAILED:
case CPU_UP_CANCELED:
console_lock();
console_unlock();
}
return NOTIFY_OK;
}
void console_lock(void)
{
BUG_ON(in_interrupt());
down(&console_sem);
if (console_suspended)
return;
console_locked = 1;
console_may_schedule = 1;
}
int console_trylock(void)
{
if (down_trylock(&console_sem))
return 0;
if (console_suspended) {
up(&console_sem);
return 0;
}
console_locked = 1;
console_may_schedule = 0;
return 1;
}
int is_console_locked(void)
{
return console_locked;
}
void printk_tick(void)
{
if (__this_cpu_read(printk_pending)) {
__this_cpu_write(printk_pending, 0);
wake_up_interruptible(&log_wait);
}
}
int printk_needs_cpu(int cpu)
{
if (cpu_is_offline(cpu))
printk_tick();
return __this_cpu_read(printk_pending);
}
void wake_up_klogd(void)
{
if (waitqueue_active(&log_wait))
this_cpu_write(printk_pending, 1);
}
void console_unlock(void)
{
unsigned long flags;
unsigned _con_start, _log_end;
unsigned wake_klogd = 0;
if (console_suspended) {
up(&console_sem);
return;
}
console_may_schedule = 0;
for ( ; ; ) {
spin_lock_irqsave(&logbuf_lock, flags);
wake_klogd |= log_start - log_end;
if (con_start == log_end)
break;
_con_start = con_start;
_log_end = log_end;
con_start = log_end;
spin_unlock(&logbuf_lock);
stop_critical_timings();
call_console_drivers(_con_start, _log_end);
start_critical_timings();
local_irq_restore(flags);
}
console_locked = 0;
if (unlikely(exclusive_console))
exclusive_console = NULL;
up(&console_sem);
spin_unlock_irqrestore(&logbuf_lock, flags);
if (wake_klogd)
wake_up_klogd();
}
void __sched console_conditional_schedule(void)
{
if (console_may_schedule)
cond_resched();
}
void console_unblank(void)
{
struct console *c;
if (oops_in_progress) {
if (down_trylock(&console_sem) != 0)
return;
} else
console_lock();
console_locked = 1;
console_may_schedule = 0;
for_each_console(c)
if ((c->flags & CON_ENABLED) && c->unblank)
c->unblank();
console_unlock();
}
struct tty_driver *console_device(int *index)
{
struct console *c;
struct tty_driver *driver = NULL;
console_lock();
for_each_console(c) {
if (!c->device)
continue;
driver = c->device(c, index);
if (driver)
break;
}
console_unlock();
return driver;
}
void console_stop(struct console *console)
{
console_lock();
console->flags &= ~CON_ENABLED;
console_unlock();
}
void console_start(struct console *console)
{
console_lock();
console->flags |= CON_ENABLED;
console_unlock();
}
static int __init keep_bootcon_setup(char *str)
{
keep_bootcon = 1;
printk(KERN_INFO "debug: skip boot console de-registration.\n");
return 0;
}
void register_console(struct console *newcon)
{
int i;
unsigned long flags;
struct console *bcon = NULL;
if (console_drivers && newcon->flags & CON_BOOT) {
for_each_console(bcon) {
if (!(bcon->flags & CON_BOOT)) {
printk(KERN_INFO "Too late to register bootconsole %s%d\n",
newcon->name, newcon->index);
return;
}
}
}
if (console_drivers && console_drivers->flags & CON_BOOT)
bcon = console_drivers;
if (preferred_console < 0 || bcon || !console_drivers)
preferred_console = selected_console;
if (newcon->early_setup)
newcon->early_setup();
if (preferred_console < 0) {
if (newcon->index < 0)
newcon->index = 0;
if (newcon->setup == NULL ||
newcon->setup(newcon, NULL) == 0) {
newcon->flags |= CON_ENABLED;
if (newcon->device) {
newcon->flags |= CON_CONSDEV;
preferred_console = 0;
}
}
}
for (i = 0; i < MAX_CMDLINECONSOLES && console_cmdline[i].name[0];
i++) {
if (strcmp(console_cmdline[i].name, newcon->name) != 0)
continue;
if (newcon->index >= 0 &&
newcon->index != console_cmdline[i].index)
continue;
if (newcon->index < 0)
newcon->index = console_cmdline[i].index;
#ifdef CONFIG_A11Y_BRAILLE_CONSOLE
if (console_cmdline[i].brl_options) {
newcon->flags |= CON_BRL;
braille_register_console(newcon,
console_cmdline[i].index,
console_cmdline[i].options,
console_cmdline[i].brl_options);
return;
}
#endif
if (newcon->setup &&
newcon->setup(newcon, console_cmdline[i].options) != 0)
break;
newcon->flags |= CON_ENABLED;
newcon->index = console_cmdline[i].index;
if (i == selected_console) {
newcon->flags |= CON_CONSDEV;
preferred_console = selected_console;
}
break;
}
if (!(newcon->flags & CON_ENABLED))
return;
if (bcon && ((newcon->flags & (CON_CONSDEV | CON_BOOT)) == CON_CONSDEV))
newcon->flags &= ~CON_PRINTBUFFER;
console_lock();
if ((newcon->flags & CON_CONSDEV) || console_drivers == NULL) {
newcon->next = console_drivers;
console_drivers = newcon;
if (newcon->next)
newcon->next->flags &= ~CON_CONSDEV;
} else {
newcon->next = console_drivers->next;
console_drivers->next = newcon;
}
if (newcon->flags & CON_PRINTBUFFER) {
spin_lock_irqsave(&logbuf_lock, flags);
con_start = log_start;
spin_unlock_irqrestore(&logbuf_lock, flags);
exclusive_console = newcon;
}
console_unlock();
console_sysfs_notify();
if (bcon &&
((newcon->flags & (CON_CONSDEV | CON_BOOT)) == CON_CONSDEV) &&
!keep_bootcon) {
printk(KERN_INFO "console [%s%d] enabled, bootconsole disabled\n",
newcon->name, newcon->index);
for_each_console(bcon)
if (bcon->flags & CON_BOOT)
unregister_console(bcon);
} else {
printk(KERN_INFO "%sconsole [%s%d] enabled\n",
(newcon->flags & CON_BOOT) ? "boot" : "" ,
newcon->name, newcon->index);
}
}
int unregister_console(struct console *console)
{
struct console *a, *b;
int res = 1;
#ifdef CONFIG_A11Y_BRAILLE_CONSOLE
if (console->flags & CON_BRL)
return braille_unregister_console(console);
#endif
console_lock();
if (console_drivers == console) {
console_drivers=console->next;
res = 0;
} else if (console_drivers) {
for (a=console_drivers->next, b=console_drivers ;
a; b=a, a=b->next) {
if (a == console) {
b->next = a->next;
res = 0;
break;
}
}
}
if (console_drivers != NULL && console->flags & CON_CONSDEV)
console_drivers->flags |= CON_CONSDEV;
console_unlock();
console_sysfs_notify();
return res;
}
static int __init printk_late_init(void)
{
struct console *con;
for_each_console(con) {
if (con->flags & CON_BOOT) {
printk(KERN_INFO "turn off boot console %s%d\n",
con->name, con->index);
unregister_console(con);
}
}
hotcpu_notifier(console_cpu_notify, 0);
return 0;
}
int __printk_ratelimit(const char *func)
{
return ___ratelimit(&printk_ratelimit_state, func);
}
bool printk_timed_ratelimit(unsigned long *caller_jiffies,
unsigned int interval_msecs)
{
if (*caller_jiffies == 0
|| !time_in_range(jiffies, *caller_jiffies,
*caller_jiffies
+ msecs_to_jiffies(interval_msecs))) {
*caller_jiffies = jiffies;
return true;
}
return false;
}
int kmsg_dump_register(struct kmsg_dumper *dumper)
{
unsigned long flags;
int err = -EBUSY;
if (!dumper->dump)
return -EINVAL;
spin_lock_irqsave(&dump_list_lock, flags);
if (!dumper->registered) {
dumper->registered = 1;
list_add_tail_rcu(&dumper->list, &dump_list);
err = 0;
}
spin_unlock_irqrestore(&dump_list_lock, flags);
return err;
}
int kmsg_dump_unregister(struct kmsg_dumper *dumper)
{
unsigned long flags;
int err = -EINVAL;
spin_lock_irqsave(&dump_list_lock, flags);
if (dumper->registered) {
dumper->registered = 0;
list_del_rcu(&dumper->list);
err = 0;
}
spin_unlock_irqrestore(&dump_list_lock, flags);
synchronize_rcu();
return err;
}
void kmsg_dump(enum kmsg_dump_reason reason)
{
unsigned long end;
unsigned chars;
struct kmsg_dumper *dumper;
const char *s1, *s2;
unsigned long l1, l2;
unsigned long flags;
spin_lock_irqsave(&logbuf_lock, flags);
end = log_end & LOG_BUF_MASK;
chars = logged_chars;
spin_unlock_irqrestore(&logbuf_lock, flags);
if (chars > end) {
s1 = log_buf + log_buf_len - chars + end;
l1 = chars - end;
s2 = log_buf;
l2 = end;
} else {
s1 = "";
l1 = 0;
s2 = log_buf + end - chars;
l2 = chars;
}
rcu_read_lock();
list_for_each_entry_rcu(dumper, &dump_list, list)
dumper->dump(dumper, reason, s1, l1, s2, l2);
rcu_read_unlock();
}
