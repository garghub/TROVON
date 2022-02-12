static long cmm_alloc_pages(long nr, long *counter,
struct cmm_page_array **list)
{
struct cmm_page_array *pa, *npa;
unsigned long addr;
while (nr) {
addr = __get_free_page(GFP_NOIO);
if (!addr)
break;
spin_lock(&cmm_lock);
pa = *list;
if (!pa || pa->index >= CMM_NR_PAGES) {
spin_unlock(&cmm_lock);
npa = (struct cmm_page_array *)
__get_free_page(GFP_NOIO);
if (!npa) {
free_page(addr);
break;
}
spin_lock(&cmm_lock);
pa = *list;
if (!pa || pa->index >= CMM_NR_PAGES) {
npa->next = pa;
npa->index = 0;
pa = npa;
*list = pa;
} else
free_page((unsigned long) npa);
}
diag10_range(addr >> PAGE_SHIFT, 1);
pa->pages[pa->index++] = addr;
(*counter)++;
spin_unlock(&cmm_lock);
nr--;
}
return nr;
}
static long cmm_free_pages(long nr, long *counter, struct cmm_page_array **list)
{
struct cmm_page_array *pa;
unsigned long addr;
spin_lock(&cmm_lock);
pa = *list;
while (nr) {
if (!pa || pa->index <= 0)
break;
addr = pa->pages[--pa->index];
if (pa->index == 0) {
pa = pa->next;
free_page((unsigned long) *list);
*list = pa;
}
free_page(addr);
(*counter)--;
nr--;
}
spin_unlock(&cmm_lock);
return nr;
}
static int cmm_oom_notify(struct notifier_block *self,
unsigned long dummy, void *parm)
{
unsigned long *freed = parm;
long nr = 256;
nr = cmm_free_pages(nr, &cmm_timed_pages, &cmm_timed_page_list);
if (nr > 0)
nr = cmm_free_pages(nr, &cmm_pages, &cmm_page_list);
cmm_pages_target = cmm_pages;
cmm_timed_pages_target = cmm_timed_pages;
*freed += 256 - nr;
return NOTIFY_OK;
}
static int cmm_thread(void *dummy)
{
int rc;
while (1) {
rc = wait_event_interruptible(cmm_thread_wait,
(!cmm_suspended && (cmm_pages != cmm_pages_target ||
cmm_timed_pages != cmm_timed_pages_target)) ||
kthread_should_stop());
if (kthread_should_stop() || rc == -ERESTARTSYS) {
cmm_pages_target = cmm_pages;
cmm_timed_pages_target = cmm_timed_pages;
break;
}
if (cmm_pages_target > cmm_pages) {
if (cmm_alloc_pages(1, &cmm_pages, &cmm_page_list))
cmm_pages_target = cmm_pages;
} else if (cmm_pages_target < cmm_pages) {
cmm_free_pages(1, &cmm_pages, &cmm_page_list);
}
if (cmm_timed_pages_target > cmm_timed_pages) {
if (cmm_alloc_pages(1, &cmm_timed_pages,
&cmm_timed_page_list))
cmm_timed_pages_target = cmm_timed_pages;
} else if (cmm_timed_pages_target < cmm_timed_pages) {
cmm_free_pages(1, &cmm_timed_pages,
&cmm_timed_page_list);
}
if (cmm_timed_pages > 0 && !timer_pending(&cmm_timer))
cmm_set_timer();
}
return 0;
}
static void cmm_kick_thread(void)
{
wake_up(&cmm_thread_wait);
}
static void cmm_set_timer(void)
{
if (cmm_timed_pages_target <= 0 || cmm_timeout_seconds <= 0) {
if (timer_pending(&cmm_timer))
del_timer(&cmm_timer);
return;
}
if (timer_pending(&cmm_timer)) {
if (mod_timer(&cmm_timer, jiffies + cmm_timeout_seconds*HZ))
return;
}
cmm_timer.function = cmm_timer_fn;
cmm_timer.data = 0;
cmm_timer.expires = jiffies + cmm_timeout_seconds*HZ;
add_timer(&cmm_timer);
}
static void cmm_timer_fn(unsigned long ignored)
{
long nr;
nr = cmm_timed_pages_target - cmm_timeout_pages;
if (nr < 0)
cmm_timed_pages_target = 0;
else
cmm_timed_pages_target = nr;
cmm_kick_thread();
cmm_set_timer();
}
static void cmm_set_pages(long nr)
{
cmm_pages_target = nr;
cmm_kick_thread();
}
static long cmm_get_pages(void)
{
return cmm_pages;
}
static void cmm_add_timed_pages(long nr)
{
cmm_timed_pages_target += nr;
cmm_kick_thread();
}
static long cmm_get_timed_pages(void)
{
return cmm_timed_pages;
}
static void cmm_set_timeout(long nr, long seconds)
{
cmm_timeout_pages = nr;
cmm_timeout_seconds = seconds;
cmm_set_timer();
}
static int cmm_skip_blanks(char *cp, char **endp)
{
char *str;
for (str = cp; *str == ' ' || *str == '\t'; str++)
;
*endp = str;
return str != cp;
}
static int cmm_pages_handler(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
char buf[16], *p;
unsigned int len;
long nr;
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write) {
len = *lenp;
if (copy_from_user(buf, buffer,
len > sizeof(buf) ? sizeof(buf) : len))
return -EFAULT;
buf[sizeof(buf) - 1] = '\0';
cmm_skip_blanks(buf, &p);
nr = simple_strtoul(p, &p, 0);
if (ctl == &cmm_table[0])
cmm_set_pages(nr);
else
cmm_add_timed_pages(nr);
} else {
if (ctl == &cmm_table[0])
nr = cmm_get_pages();
else
nr = cmm_get_timed_pages();
len = sprintf(buf, "%ld\n", nr);
if (len > *lenp)
len = *lenp;
if (copy_to_user(buffer, buf, len))
return -EFAULT;
}
*lenp = len;
*ppos += len;
return 0;
}
static int cmm_timeout_handler(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
char buf[64], *p;
long nr, seconds;
unsigned int len;
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write) {
len = *lenp;
if (copy_from_user(buf, buffer,
len > sizeof(buf) ? sizeof(buf) : len))
return -EFAULT;
buf[sizeof(buf) - 1] = '\0';
cmm_skip_blanks(buf, &p);
nr = simple_strtoul(p, &p, 0);
cmm_skip_blanks(p, &p);
seconds = simple_strtoul(p, &p, 0);
cmm_set_timeout(nr, seconds);
} else {
len = sprintf(buf, "%ld %ld\n",
cmm_timeout_pages, cmm_timeout_seconds);
if (len > *lenp)
len = *lenp;
if (copy_to_user(buffer, buf, len))
return -EFAULT;
}
*lenp = len;
*ppos += len;
return 0;
}
static void cmm_smsg_target(const char *from, char *msg)
{
long nr, seconds;
if (strlen(sender) > 0 && strcmp(from, sender) != 0)
return;
if (!cmm_skip_blanks(msg + strlen(SMSG_PREFIX), &msg))
return;
if (strncmp(msg, "SHRINK", 6) == 0) {
if (!cmm_skip_blanks(msg + 6, &msg))
return;
nr = simple_strtoul(msg, &msg, 0);
cmm_skip_blanks(msg, &msg);
if (*msg == '\0')
cmm_set_pages(nr);
} else if (strncmp(msg, "RELEASE", 7) == 0) {
if (!cmm_skip_blanks(msg + 7, &msg))
return;
nr = simple_strtoul(msg, &msg, 0);
cmm_skip_blanks(msg, &msg);
if (*msg == '\0')
cmm_add_timed_pages(nr);
} else if (strncmp(msg, "REUSE", 5) == 0) {
if (!cmm_skip_blanks(msg + 5, &msg))
return;
nr = simple_strtoul(msg, &msg, 0);
if (!cmm_skip_blanks(msg, &msg))
return;
seconds = simple_strtoul(msg, &msg, 0);
cmm_skip_blanks(msg, &msg);
if (*msg == '\0')
cmm_set_timeout(nr, seconds);
}
}
static int cmm_suspend(void)
{
cmm_suspended = 1;
cmm_free_pages(cmm_pages, &cmm_pages, &cmm_page_list);
cmm_free_pages(cmm_timed_pages, &cmm_timed_pages, &cmm_timed_page_list);
return 0;
}
static int cmm_resume(void)
{
cmm_suspended = 0;
cmm_kick_thread();
return 0;
}
static int cmm_power_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
switch (event) {
case PM_POST_HIBERNATION:
return cmm_resume();
case PM_HIBERNATION_PREPARE:
return cmm_suspend();
default:
return NOTIFY_DONE;
}
}
static int __init cmm_init(void)
{
int rc = -ENOMEM;
cmm_sysctl_header = register_sysctl_table(cmm_dir_table);
if (!cmm_sysctl_header)
goto out_sysctl;
#ifdef CONFIG_CMM_IUCV
if (sender) {
int len = strlen(sender);
while (len--)
sender[len] = toupper(sender[len]);
} else {
sender = cmm_default_sender;
}
rc = smsg_register_callback(SMSG_PREFIX, cmm_smsg_target);
if (rc < 0)
goto out_smsg;
#endif
rc = register_oom_notifier(&cmm_oom_nb);
if (rc < 0)
goto out_oom_notify;
rc = register_pm_notifier(&cmm_power_notifier);
if (rc)
goto out_pm;
cmm_thread_ptr = kthread_run(cmm_thread, NULL, "cmmthread");
if (!IS_ERR(cmm_thread_ptr))
return 0;
rc = PTR_ERR(cmm_thread_ptr);
unregister_pm_notifier(&cmm_power_notifier);
out_pm:
unregister_oom_notifier(&cmm_oom_nb);
out_oom_notify:
#ifdef CONFIG_CMM_IUCV
smsg_unregister_callback(SMSG_PREFIX, cmm_smsg_target);
out_smsg:
#endif
unregister_sysctl_table(cmm_sysctl_header);
out_sysctl:
del_timer_sync(&cmm_timer);
return rc;
}
static void __exit cmm_exit(void)
{
unregister_sysctl_table(cmm_sysctl_header);
#ifdef CONFIG_CMM_IUCV
smsg_unregister_callback(SMSG_PREFIX, cmm_smsg_target);
#endif
unregister_pm_notifier(&cmm_power_notifier);
unregister_oom_notifier(&cmm_oom_nb);
kthread_stop(cmm_thread_ptr);
del_timer_sync(&cmm_timer);
cmm_free_pages(cmm_pages, &cmm_pages, &cmm_page_list);
cmm_free_pages(cmm_timed_pages, &cmm_timed_pages, &cmm_timed_page_list);
}
