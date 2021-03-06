static unsigned long lock_rtas(void)
{
unsigned long flags;
local_irq_save(flags);
preempt_disable();
arch_spin_lock_flags(&rtas.lock, flags);
return flags;
}
static void unlock_rtas(unsigned long flags)
{
arch_spin_unlock(&rtas.lock);
local_irq_restore(flags);
preempt_enable();
}
static void call_rtas_display_status(char c)
{
struct rtas_args *args = &rtas.args;
unsigned long s;
if (!rtas.base)
return;
s = lock_rtas();
args->token = 10;
args->nargs = 1;
args->nret = 1;
args->rets = (rtas_arg_t *)&(args->args[1]);
args->args[0] = (unsigned char)c;
enter_rtas(__pa(args));
unlock_rtas(s);
}
static void call_rtas_display_status_delay(char c)
{
static int pending_newline = 0;
static int width = 16;
if (c == '\n') {
while (width-- > 0)
call_rtas_display_status(' ');
width = 16;
mdelay(500);
pending_newline = 1;
} else {
if (pending_newline) {
call_rtas_display_status('\r');
call_rtas_display_status('\n');
}
pending_newline = 0;
if (width--) {
call_rtas_display_status(c);
udelay(10000);
}
}
}
void __init udbg_init_rtas_panel(void)
{
udbg_putc = call_rtas_display_status_delay;
}
static void udbg_rtascon_putc(char c)
{
int tries;
if (!rtas.base)
return;
if (c == '\n')
udbg_rtascon_putc('\r');
for (tries = 0; tries < 16; tries++) {
if (rtas_call(rtas_putchar_token, 1, 1, NULL, c) == 0)
break;
udelay(1000);
}
}
static int udbg_rtascon_getc_poll(void)
{
int c;
if (!rtas.base)
return -1;
if (rtas_call(rtas_getchar_token, 0, 2, &c))
return -1;
return c;
}
static int udbg_rtascon_getc(void)
{
int c;
while ((c = udbg_rtascon_getc_poll()) == -1)
;
return c;
}
void __init udbg_init_rtas_console(void)
{
udbg_putc = udbg_rtascon_putc;
udbg_getc = udbg_rtascon_getc;
udbg_getc_poll = udbg_rtascon_getc_poll;
}
void rtas_progress(char *s, unsigned short hex)
{
struct device_node *root;
int width;
const int *p;
char *os;
static int display_character, set_indicator;
static int display_width, display_lines, form_feed;
static const int *row_width;
static DEFINE_SPINLOCK(progress_lock);
static int current_line;
static int pending_newline = 0;
if (!rtas.base)
return;
if (display_width == 0) {
display_width = 0x10;
if ((root = of_find_node_by_path("/rtas"))) {
if ((p = of_get_property(root,
"ibm,display-line-length", NULL)))
display_width = *p;
if ((p = of_get_property(root,
"ibm,form-feed", NULL)))
form_feed = *p;
if ((p = of_get_property(root,
"ibm,display-number-of-lines", NULL)))
display_lines = *p;
row_width = of_get_property(root,
"ibm,display-truncation-length", NULL);
of_node_put(root);
}
display_character = rtas_token("display-character");
set_indicator = rtas_token("set-indicator");
}
if (display_character == RTAS_UNKNOWN_SERVICE) {
if (set_indicator != RTAS_UNKNOWN_SERVICE)
rtas_call(set_indicator, 3, 1, NULL, 6, 0, hex);
return;
}
spin_lock(&progress_lock);
if (pending_newline) {
rtas_call(display_character, 1, 1, NULL, '\r');
rtas_call(display_character, 1, 1, NULL, '\n');
pending_newline = 0;
} else {
current_line = 0;
if (form_feed)
rtas_call(display_character, 1, 1, NULL,
(char)form_feed);
else
rtas_call(display_character, 1, 1, NULL, '\r');
}
if (row_width)
width = row_width[current_line];
else
width = display_width;
os = s;
while (*os) {
if (*os == '\n' || *os == '\r') {
if (*os == '\n' && !os[1]) {
pending_newline = 1;
current_line++;
if (current_line > display_lines-1)
current_line = display_lines-1;
spin_unlock(&progress_lock);
return;
}
if (*os == '\n') {
rtas_call(display_character, 1, 1, NULL, '\r');
rtas_call(display_character, 1, 1, NULL, '\n');
} else {
rtas_call(display_character, 1, 1, NULL, *os);
}
if (row_width)
width = row_width[current_line];
else
width = display_width;
} else {
width--;
rtas_call(display_character, 1, 1, NULL, *os);
}
os++;
if (width <= 0)
while ((*os != 0) && (*os != '\n') && (*os != '\r'))
os++;
}
spin_unlock(&progress_lock);
}
int rtas_token(const char *service)
{
const int *tokp;
if (rtas.dev == NULL)
return RTAS_UNKNOWN_SERVICE;
tokp = of_get_property(rtas.dev, service, NULL);
return tokp ? *tokp : RTAS_UNKNOWN_SERVICE;
}
int rtas_service_present(const char *service)
{
return rtas_token(service) != RTAS_UNKNOWN_SERVICE;
}
int rtas_get_error_log_max(void)
{
static int rtas_error_log_max;
if (rtas_error_log_max)
return rtas_error_log_max;
rtas_error_log_max = rtas_token ("rtas-error-log-max");
if ((rtas_error_log_max == RTAS_UNKNOWN_SERVICE) ||
(rtas_error_log_max > RTAS_ERROR_LOG_MAX)) {
printk (KERN_WARNING "RTAS: bad log buffer size %d\n",
rtas_error_log_max);
rtas_error_log_max = RTAS_ERROR_LOG_MAX;
}
return rtas_error_log_max;
}
static char *__fetch_rtas_last_error(char *altbuf)
{
struct rtas_args err_args, save_args;
u32 bufsz;
char *buf = NULL;
if (rtas_last_error_token == -1)
return NULL;
bufsz = rtas_get_error_log_max();
err_args.token = rtas_last_error_token;
err_args.nargs = 2;
err_args.nret = 1;
err_args.args[0] = (rtas_arg_t)__pa(rtas_err_buf);
err_args.args[1] = bufsz;
err_args.args[2] = 0;
save_args = rtas.args;
rtas.args = err_args;
enter_rtas(__pa(&rtas.args));
err_args = rtas.args;
rtas.args = save_args;
if (unlikely(err_args.args[2] == 0)) {
if (altbuf) {
buf = altbuf;
} else {
buf = rtas_err_buf;
if (mem_init_done)
buf = kmalloc(RTAS_ERROR_LOG_MAX, GFP_ATOMIC);
}
if (buf)
memcpy(buf, rtas_err_buf, RTAS_ERROR_LOG_MAX);
}
return buf;
}
int rtas_call(int token, int nargs, int nret, int *outputs, ...)
{
va_list list;
int i;
unsigned long s;
struct rtas_args *rtas_args;
char *buff_copy = NULL;
int ret;
if (!rtas.entry || token == RTAS_UNKNOWN_SERVICE)
return -1;
s = lock_rtas();
rtas_args = &rtas.args;
rtas_args->token = token;
rtas_args->nargs = nargs;
rtas_args->nret = nret;
rtas_args->rets = (rtas_arg_t *)&(rtas_args->args[nargs]);
va_start(list, outputs);
for (i = 0; i < nargs; ++i)
rtas_args->args[i] = va_arg(list, rtas_arg_t);
va_end(list);
for (i = 0; i < nret; ++i)
rtas_args->rets[i] = 0;
enter_rtas(__pa(rtas_args));
if (rtas_args->rets[0] == -1)
buff_copy = __fetch_rtas_last_error(NULL);
if (nret > 1 && outputs != NULL)
for (i = 0; i < nret-1; ++i)
outputs[i] = rtas_args->rets[i+1];
ret = (nret > 0)? rtas_args->rets[0]: 0;
unlock_rtas(s);
if (buff_copy) {
log_error(buff_copy, ERR_TYPE_RTAS_LOG, 0);
if (mem_init_done)
kfree(buff_copy);
}
return ret;
}
unsigned int rtas_busy_delay_time(int status)
{
int order;
unsigned int ms = 0;
if (status == RTAS_BUSY) {
ms = 1;
} else if (status >= 9900 && status <= 9905) {
order = status - 9900;
for (ms = 1; order > 0; order--)
ms *= 10;
}
return ms;
}
unsigned int rtas_busy_delay(int status)
{
unsigned int ms;
might_sleep();
ms = rtas_busy_delay_time(status);
if (ms && need_resched())
msleep(ms);
return ms;
}
static int rtas_error_rc(int rtas_rc)
{
int rc;
switch (rtas_rc) {
case -1:
rc = -EIO;
break;
case -3:
rc = -EINVAL;
break;
case -9000:
rc = -EFAULT;
break;
case -9001:
rc = -EEXIST;
break;
case -9002:
rc = -ENODEV;
break;
default:
printk(KERN_ERR "%s: unexpected RTAS error %d\n",
__func__, rtas_rc);
rc = -ERANGE;
break;
}
return rc;
}
int rtas_get_power_level(int powerdomain, int *level)
{
int token = rtas_token("get-power-level");
int rc;
if (token == RTAS_UNKNOWN_SERVICE)
return -ENOENT;
while ((rc = rtas_call(token, 1, 2, level, powerdomain)) == RTAS_BUSY)
udelay(1);
if (rc < 0)
return rtas_error_rc(rc);
return rc;
}
int rtas_set_power_level(int powerdomain, int level, int *setlevel)
{
int token = rtas_token("set-power-level");
int rc;
if (token == RTAS_UNKNOWN_SERVICE)
return -ENOENT;
do {
rc = rtas_call(token, 2, 2, setlevel, powerdomain, level);
} while (rtas_busy_delay(rc));
if (rc < 0)
return rtas_error_rc(rc);
return rc;
}
int rtas_get_sensor(int sensor, int index, int *state)
{
int token = rtas_token("get-sensor-state");
int rc;
if (token == RTAS_UNKNOWN_SERVICE)
return -ENOENT;
do {
rc = rtas_call(token, 2, 2, state, sensor, index);
} while (rtas_busy_delay(rc));
if (rc < 0)
return rtas_error_rc(rc);
return rc;
}
bool rtas_indicator_present(int token, int *maxindex)
{
int proplen, count, i;
const struct indicator_elem {
u32 token;
u32 maxindex;
} *indicators;
indicators = of_get_property(rtas.dev, "rtas-indicators", &proplen);
if (!indicators)
return false;
count = proplen / sizeof(struct indicator_elem);
for (i = 0; i < count; i++) {
if (indicators[i].token != token)
continue;
if (maxindex)
*maxindex = indicators[i].maxindex;
return true;
}
return false;
}
int rtas_set_indicator(int indicator, int index, int new_value)
{
int token = rtas_token("set-indicator");
int rc;
if (token == RTAS_UNKNOWN_SERVICE)
return -ENOENT;
do {
rc = rtas_call(token, 3, 1, NULL, indicator, index, new_value);
} while (rtas_busy_delay(rc));
if (rc < 0)
return rtas_error_rc(rc);
return rc;
}
int rtas_set_indicator_fast(int indicator, int index, int new_value)
{
int rc;
int token = rtas_token("set-indicator");
if (token == RTAS_UNKNOWN_SERVICE)
return -ENOENT;
rc = rtas_call(token, 3, 1, NULL, indicator, index, new_value);
WARN_ON(rc == -2 || (rc >= 9900 && rc <= 9905));
if (rc < 0)
return rtas_error_rc(rc);
return rc;
}
void rtas_restart(char *cmd)
{
if (rtas_flash_term_hook)
rtas_flash_term_hook(SYS_RESTART);
printk("RTAS system-reboot returned %d\n",
rtas_call(rtas_token("system-reboot"), 0, 1, NULL));
for (;;);
}
void rtas_power_off(void)
{
if (rtas_flash_term_hook)
rtas_flash_term_hook(SYS_POWER_OFF);
printk("RTAS power-off returned %d\n",
rtas_call(rtas_token("power-off"), 2, 1, NULL, -1, -1));
for (;;);
}
void rtas_halt(void)
{
if (rtas_flash_term_hook)
rtas_flash_term_hook(SYS_HALT);
printk("RTAS power-off returned %d\n",
rtas_call(rtas_token("power-off"), 2, 1, NULL, -1, -1));
for (;;);
}
void rtas_os_term(char *str)
{
int status;
if (RTAS_UNKNOWN_SERVICE == rtas_token("ibm,os-term") ||
RTAS_UNKNOWN_SERVICE == rtas_token("ibm,extended-os-term"))
return;
snprintf(rtas_os_term_buf, 2048, "OS panic: %s", str);
do {
status = rtas_call(rtas_token("ibm,os-term"), 1, 1, NULL,
__pa(rtas_os_term_buf));
} while (rtas_busy_delay(status));
if (status != 0)
printk(KERN_EMERG "ibm,os-term call failed %d\n", status);
}
static int __rtas_suspend_last_cpu(struct rtas_suspend_me_data *data, int wake_when_done)
{
u16 slb_size = mmu_slb_size;
int rc = H_MULTI_THREADS_ACTIVE;
int cpu;
slb_set_size(SLB_MIN_SIZE);
printk(KERN_DEBUG "calling ibm,suspend-me on cpu %i\n", smp_processor_id());
while (rc == H_MULTI_THREADS_ACTIVE && !atomic_read(&data->done) &&
!atomic_read(&data->error))
rc = rtas_call(data->token, 0, 1, NULL);
if (rc || atomic_read(&data->error)) {
printk(KERN_DEBUG "ibm,suspend-me returned %d\n", rc);
slb_set_size(slb_size);
}
if (atomic_read(&data->error))
rc = atomic_read(&data->error);
atomic_set(&data->error, rc);
pSeries_coalesce_init();
if (wake_when_done) {
atomic_set(&data->done, 1);
for_each_online_cpu(cpu)
plpar_hcall_norets(H_PROD, get_hard_smp_processor_id(cpu));
}
if (atomic_dec_return(&data->working) == 0)
complete(data->complete);
return rc;
}
int rtas_suspend_last_cpu(struct rtas_suspend_me_data *data)
{
atomic_inc(&data->working);
return __rtas_suspend_last_cpu(data, 0);
}
static int __rtas_suspend_cpu(struct rtas_suspend_me_data *data, int wake_when_done)
{
long rc = H_SUCCESS;
unsigned long msr_save;
int cpu;
atomic_inc(&data->working);
msr_save = mfmsr();
mtmsr(msr_save & ~(MSR_EE));
while (rc == H_SUCCESS && !atomic_read(&data->done) && !atomic_read(&data->error))
rc = plpar_hcall_norets(H_JOIN);
mtmsr(msr_save);
if (rc == H_SUCCESS) {
goto out;
} else if (rc == H_CONTINUE) {
return __rtas_suspend_last_cpu(data, wake_when_done);
} else {
printk(KERN_ERR "H_JOIN on cpu %i failed with rc = %ld\n",
smp_processor_id(), rc);
atomic_set(&data->error, rc);
}
if (wake_when_done) {
atomic_set(&data->done, 1);
for_each_online_cpu(cpu)
plpar_hcall_norets(H_PROD, get_hard_smp_processor_id(cpu));
}
out:
if (atomic_dec_return(&data->working) == 0)
complete(data->complete);
return rc;
}
int rtas_suspend_cpu(struct rtas_suspend_me_data *data)
{
return __rtas_suspend_cpu(data, 0);
}
static void rtas_percpu_suspend_me(void *info)
{
__rtas_suspend_cpu((struct rtas_suspend_me_data *)info, 1);
}
static int rtas_cpu_state_change_mask(enum rtas_cpu_state state,
cpumask_var_t cpus)
{
if (!cpumask_empty(cpus)) {
cpumask_clear(cpus);
return -EINVAL;
} else
return 0;
}
static int rtas_cpu_state_change_mask(enum rtas_cpu_state state,
cpumask_var_t cpus)
{
int cpu;
int cpuret = 0;
int ret = 0;
if (cpumask_empty(cpus))
return 0;
for_each_cpu(cpu, cpus) {
switch (state) {
case DOWN:
cpuret = cpu_down(cpu);
break;
case UP:
cpuret = cpu_up(cpu);
break;
}
if (cpuret) {
pr_debug("%s: cpu_%s for cpu#%d returned %d.\n",
__func__,
((state == UP) ? "up" : "down"),
cpu, cpuret);
if (!ret)
ret = cpuret;
if (state == UP) {
cpumask_shift_right(cpus, cpus, cpu);
cpumask_shift_left(cpus, cpus, cpu);
break;
} else {
cpumask_clear_cpu(cpu, cpus);
}
}
}
return ret;
}
int rtas_online_cpus_mask(cpumask_var_t cpus)
{
int ret;
ret = rtas_cpu_state_change_mask(UP, cpus);
if (ret) {
cpumask_var_t tmp_mask;
if (!alloc_cpumask_var(&tmp_mask, GFP_TEMPORARY))
return ret;
cpumask_copy(tmp_mask, cpus);
rtas_offline_cpus_mask(tmp_mask);
free_cpumask_var(tmp_mask);
}
return ret;
}
int rtas_offline_cpus_mask(cpumask_var_t cpus)
{
return rtas_cpu_state_change_mask(DOWN, cpus);
}
int rtas_ibm_suspend_me(struct rtas_args *args)
{
long state;
long rc;
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
struct rtas_suspend_me_data data;
DECLARE_COMPLETION_ONSTACK(done);
cpumask_var_t offline_mask;
int cpuret;
if (!rtas_service_present("ibm,suspend-me"))
return -ENOSYS;
rc = plpar_hcall(H_VASI_STATE, retbuf,
((u64)args->args[0] << 32) | args->args[1]);
state = retbuf[0];
if (rc) {
printk(KERN_ERR "rtas_ibm_suspend_me: vasi_state returned %ld\n",rc);
return rc;
} else if (state == H_VASI_ENABLED) {
args->args[args->nargs] = RTAS_NOT_SUSPENDABLE;
return 0;
} else if (state != H_VASI_SUSPENDING) {
printk(KERN_ERR "rtas_ibm_suspend_me: vasi_state returned state %ld\n",
state);
args->args[args->nargs] = -1;
return 0;
}
if (!alloc_cpumask_var(&offline_mask, GFP_TEMPORARY))
return -ENOMEM;
atomic_set(&data.working, 0);
atomic_set(&data.done, 0);
atomic_set(&data.error, 0);
data.token = rtas_token("ibm,suspend-me");
data.complete = &done;
cpumask_andnot(offline_mask, cpu_present_mask, cpu_online_mask);
cpuret = rtas_online_cpus_mask(offline_mask);
if (cpuret) {
pr_err("%s: Could not bring present CPUs online.\n", __func__);
atomic_set(&data.error, cpuret);
goto out;
}
stop_topology_update();
if (on_each_cpu(rtas_percpu_suspend_me, &data, 0))
atomic_set(&data.error, -EINVAL);
wait_for_completion(&done);
if (atomic_read(&data.error) != 0)
printk(KERN_ERR "Error doing global join\n");
start_topology_update();
cpuret = rtas_offline_cpus_mask(offline_mask);
if (cpuret)
pr_warn("%s: Could not restore CPUs to offline state.\n",
__func__);
out:
free_cpumask_var(offline_mask);
return atomic_read(&data.error);
}
int rtas_ibm_suspend_me(struct rtas_args *args)
{
return -ENOSYS;
}
struct pseries_errorlog *get_pseries_errorlog(struct rtas_error_log *log,
uint16_t section_id)
{
struct rtas_ext_event_log_v6 *ext_log =
(struct rtas_ext_event_log_v6 *)log->buffer;
struct pseries_errorlog *sect;
unsigned char *p, *log_end;
if (log->extended_log_length < sizeof(struct rtas_ext_event_log_v6) ||
ext_log->log_format != RTAS_V6EXT_LOG_FORMAT_EVENT_LOG ||
ext_log->company_id != RTAS_V6EXT_COMPANY_ID_IBM)
return NULL;
log_end = log->buffer + log->extended_log_length;
p = ext_log->vendor_log;
while (p < log_end) {
sect = (struct pseries_errorlog *)p;
if (sect->id == section_id)
return sect;
p += sect->length;
}
return NULL;
}
asmlinkage int ppc_rtas(struct rtas_args __user *uargs)
{
struct rtas_args args;
unsigned long flags;
char *buff_copy, *errbuf = NULL;
int nargs;
int rc;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (copy_from_user(&args, uargs, 3 * sizeof(u32)) != 0)
return -EFAULT;
nargs = args.nargs;
if (nargs > ARRAY_SIZE(args.args)
|| args.nret > ARRAY_SIZE(args.args)
|| nargs + args.nret > ARRAY_SIZE(args.args))
return -EINVAL;
if (copy_from_user(args.args, uargs->args,
nargs * sizeof(rtas_arg_t)) != 0)
return -EFAULT;
if (args.token == RTAS_UNKNOWN_SERVICE)
return -EINVAL;
args.rets = &args.args[nargs];
memset(args.rets, 0, args.nret * sizeof(rtas_arg_t));
if (args.token == ibm_suspend_me_token) {
rc = rtas_ibm_suspend_me(&args);
if (rc)
return rc;
goto copy_return;
}
buff_copy = get_errorlog_buffer();
flags = lock_rtas();
rtas.args = args;
enter_rtas(__pa(&rtas.args));
args = rtas.args;
if (args.rets[0] == -1)
errbuf = __fetch_rtas_last_error(buff_copy);
unlock_rtas(flags);
if (buff_copy) {
if (errbuf)
log_error(errbuf, ERR_TYPE_RTAS_LOG, 0);
kfree(buff_copy);
}
copy_return:
if (copy_to_user(uargs->args + nargs,
args.args + nargs,
args.nret * sizeof(rtas_arg_t)) != 0)
return -EFAULT;
return 0;
}
void __init rtas_initialize(void)
{
unsigned long rtas_region = RTAS_INSTANTIATE_MAX;
rtas.dev = of_find_node_by_name(NULL, "rtas");
if (rtas.dev) {
const u32 *basep, *entryp, *sizep;
basep = of_get_property(rtas.dev, "linux,rtas-base", NULL);
sizep = of_get_property(rtas.dev, "rtas-size", NULL);
if (basep != NULL && sizep != NULL) {
rtas.base = *basep;
rtas.size = *sizep;
entryp = of_get_property(rtas.dev,
"linux,rtas-entry", NULL);
if (entryp == NULL)
rtas.entry = rtas.base;
else
rtas.entry = *entryp;
} else
rtas.dev = NULL;
}
if (!rtas.dev)
return;
#ifdef CONFIG_PPC64
if (machine_is(pseries) && firmware_has_feature(FW_FEATURE_LPAR)) {
rtas_region = min(ppc64_rma_size, RTAS_INSTANTIATE_MAX);
ibm_suspend_me_token = rtas_token("ibm,suspend-me");
}
#endif
rtas_rmo_buf = memblock_alloc_base(RTAS_RMOBUF_MAX, PAGE_SIZE, rtas_region);
#ifdef CONFIG_RTAS_ERROR_LOGGING
rtas_last_error_token = rtas_token("rtas-last-error");
#endif
}
int __init early_init_dt_scan_rtas(unsigned long node,
const char *uname, int depth, void *data)
{
u32 *basep, *entryp, *sizep;
if (depth != 1 || strcmp(uname, "rtas") != 0)
return 0;
basep = of_get_flat_dt_prop(node, "linux,rtas-base", NULL);
entryp = of_get_flat_dt_prop(node, "linux,rtas-entry", NULL);
sizep = of_get_flat_dt_prop(node, "rtas-size", NULL);
if (basep && entryp && sizep) {
rtas.base = *basep;
rtas.entry = *entryp;
rtas.size = *sizep;
}
#ifdef CONFIG_UDBG_RTAS_CONSOLE
basep = of_get_flat_dt_prop(node, "put-term-char", NULL);
if (basep)
rtas_putchar_token = *basep;
basep = of_get_flat_dt_prop(node, "get-term-char", NULL);
if (basep)
rtas_getchar_token = *basep;
if (rtas_putchar_token != RTAS_UNKNOWN_SERVICE &&
rtas_getchar_token != RTAS_UNKNOWN_SERVICE)
udbg_init_rtas_console();
#endif
return 1;
}
void rtas_give_timebase(void)
{
unsigned long flags;
local_irq_save(flags);
hard_irq_disable();
arch_spin_lock(&timebase_lock);
rtas_call(rtas_token("freeze-time-base"), 0, 1, NULL);
timebase = get_tb();
arch_spin_unlock(&timebase_lock);
while (timebase)
barrier();
rtas_call(rtas_token("thaw-time-base"), 0, 1, NULL);
local_irq_restore(flags);
}
void rtas_take_timebase(void)
{
while (!timebase)
barrier();
arch_spin_lock(&timebase_lock);
set_tb(timebase >> 32, timebase & 0xffffffff);
timebase = 0;
arch_spin_unlock(&timebase_lock);
}
