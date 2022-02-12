static int sp_syscall(int num, int arg0, int arg1, int arg2, int arg3)
{
register long int _num __asm__("$2") = num;
register long int _arg0 __asm__("$4") = arg0;
register long int _arg1 __asm__("$5") = arg1;
register long int _arg2 __asm__("$6") = arg2;
register long int _arg3 __asm__("$7") = arg3;
mm_segment_t old_fs;
old_fs = get_fs();
set_fs(KERNEL_DS);
__asm__ __volatile__ (
" syscall \n"
: "=r" (_num), "=r" (_arg3)
: "r" (_num), "r" (_arg0), "r" (_arg1), "r" (_arg2), "r" (_arg3));
set_fs(old_fs);
if (_arg3)
return -_num;
return _num;
}
static int translate_syscall_command(int cmd)
{
int i;
int ret = -1;
for (i = 0; i < ARRAY_SIZE(syscall_command_table); i++) {
if ((cmd == syscall_command_table[i].sp))
return syscall_command_table[i].ap;
}
return ret;
}
static unsigned int translate_open_flags(int flags)
{
int i;
unsigned int ret = 0;
for (i = 0; i < ARRAY_SIZE(open_flags_table); i++) {
if( (flags & open_flags_table[i].sp) ) {
ret |= open_flags_table[i].ap;
}
}
return ret;
}
static int sp_setfsuidgid(uid_t uid, gid_t gid)
{
struct cred *new;
new = prepare_creds();
if (!new)
return -ENOMEM;
new->fsuid = uid;
new->fsgid = gid;
commit_creds(new);
return 0;
}
void sp_work_handle_request(void)
{
struct mtsp_syscall sc;
struct mtsp_syscall_generic generic;
struct mtsp_syscall_ret ret;
struct kspd_notifications *n;
unsigned long written;
mm_segment_t old_fs;
struct timeval tv;
struct timezone tz;
int err, cmd;
char *vcwd;
int size;
ret.retval = -1;
old_fs = get_fs();
set_fs(KERNEL_DS);
if (!rtlx_read(RTLX_CHANNEL_SYSIO, &sc, sizeof(struct mtsp_syscall))) {
set_fs(old_fs);
printk(KERN_ERR "Expected request but nothing to read\n");
return;
}
size = sc.size;
if (size) {
if (!rtlx_read(RTLX_CHANNEL_SYSIO, &generic, size)) {
set_fs(old_fs);
printk(KERN_ERR "Expected request but nothing to read\n");
return;
}
}
if (vpe_getuid(tclimit)) {
err = sp_setfsuidgid(vpe_getuid(tclimit), vpe_getgid(tclimit));
if (!err)
pr_err("Change of creds failed\n");
}
switch (sc.cmd) {
case MTSP_SYSCALL_PIPEFREQ:
ret.retval = cpu_khz * 1000;
ret.errno = 0;
break;
case MTSP_SYSCALL_GETTOD:
memset(&tz, 0, sizeof(tz));
if ((ret.retval = sp_syscall(__NR_gettimeofday, (int)&tv,
(int)&tz, 0, 0)) == 0)
ret.retval = tv.tv_sec;
break;
case MTSP_SYSCALL_EXIT:
list_for_each_entry(n, &kspd_notifylist, list)
n->kspd_sp_exit(tclimit);
sp_stopping = 1;
printk(KERN_DEBUG "KSPD got exit syscall from SP exitcode %d\n",
generic.arg0);
break;
case MTSP_SYSCALL_OPEN:
generic.arg1 = translate_open_flags(generic.arg1);
vcwd = vpe_getcwd(tclimit);
old_fs = get_fs();
set_fs(KERNEL_DS);
sys_chdir(vcwd);
set_fs(old_fs);
sc.cmd = __NR_open;
default:
if ((sc.cmd >= __NR_Linux) &&
(sc.cmd <= (__NR_Linux + __NR_Linux_syscalls)) )
cmd = sc.cmd;
else
cmd = translate_syscall_command(sc.cmd);
if (cmd >= 0) {
ret.retval = sp_syscall(cmd, generic.arg0, generic.arg1,
generic.arg2, generic.arg3);
} else
printk(KERN_WARNING
"KSPD: Unknown SP syscall number %d\n", sc.cmd);
break;
}
if (vpe_getuid(tclimit)) {
err = sp_setfsuidgid(0, 0);
if (!err)
pr_err("restoring old creds failed\n");
}
old_fs = get_fs();
set_fs(KERNEL_DS);
written = rtlx_write(RTLX_CHANNEL_SYSIO, &ret, sizeof(ret));
set_fs(old_fs);
if (written < sizeof(ret))
printk("KSPD: sp_work_handle_request failed to send to SP\n");
}
static void sp_cleanup(void)
{
struct files_struct *files = current->files;
int i, j;
struct fdtable *fdt;
j = 0;
fdt = files_fdtable(files);
for (;;) {
unsigned long set;
i = j * BITS_PER_LONG;
if (i >= fdt->max_fds)
break;
set = fdt->open_fds[j++];
while (set) {
if (set & 1) {
struct file * file = xchg(&fdt->fd[i], NULL);
if (file)
filp_close(file, files);
}
i++;
set >>= 1;
}
}
sys_chdir("/");
}
static void sp_work(struct work_struct *unused)
{
if (!channel_open) {
if( rtlx_open(RTLX_CHANNEL_SYSIO, 1) != 0) {
printk("KSPD: unable to open sp channel\n");
sp_stopping = 1;
} else {
channel_open++;
printk(KERN_DEBUG "KSPD: SP channel opened\n");
}
} else {
rtlx_read_poll(RTLX_CHANNEL_SYSIO, 1);
if (!sp_stopping)
sp_work_handle_request();
}
if (!sp_stopping)
queue_work(workqueue, &work);
else
sp_cleanup();
}
static void startwork(int vpe)
{
sp_stopping = channel_open = 0;
if (workqueue == NULL) {
if ((workqueue = create_singlethread_workqueue("kspd")) == NULL) {
printk(KERN_ERR "unable to start kspd\n");
return;
}
INIT_WORK(&work, sp_work);
}
queue_work(workqueue, &work);
}
static void stopwork(int vpe)
{
sp_stopping = 1;
printk(KERN_DEBUG "KSPD: SP stopping\n");
}
void kspd_notify(struct kspd_notifications *notify)
{
list_add(&notify->list, &kspd_notifylist);
}
static int kspd_module_init(void)
{
INIT_LIST_HEAD(&kspd_notifylist);
notify.start = startwork;
notify.stop = stopwork;
vpe_notify(tclimit, &notify);
return 0;
}
static void kspd_module_exit(void)
{
}
