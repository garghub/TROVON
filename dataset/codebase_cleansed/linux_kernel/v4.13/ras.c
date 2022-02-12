static int __init init_ras_IRQ(void)
{
struct device_node *np;
ras_check_exception_token = rtas_token("check-exception");
np = of_find_node_by_path("/event-sources/internal-errors");
if (np != NULL) {
request_event_sources_irqs(np, ras_error_interrupt,
"RAS_ERROR");
of_node_put(np);
}
np = of_find_node_by_path("/event-sources/hot-plug-events");
if (np != NULL) {
request_event_sources_irqs(np, ras_hotplug_interrupt,
"RAS_HOTPLUG");
of_node_put(np);
}
np = of_find_node_by_path("/event-sources/epow-events");
if (np != NULL) {
request_event_sources_irqs(np, ras_epow_interrupt, "RAS_EPOW");
of_node_put(np);
}
return 0;
}
static void handle_system_shutdown(char event_modifier)
{
switch (event_modifier) {
case EPOW_SHUTDOWN_NORMAL:
pr_emerg("Power off requested\n");
orderly_poweroff(true);
break;
case EPOW_SHUTDOWN_ON_UPS:
pr_emerg("Loss of system power detected. System is running on"
" UPS/battery. Check RTAS error log for details\n");
orderly_poweroff(true);
break;
case EPOW_SHUTDOWN_LOSS_OF_CRITICAL_FUNCTIONS:
pr_emerg("Loss of system critical functions detected. Check"
" RTAS error log for details\n");
orderly_poweroff(true);
break;
case EPOW_SHUTDOWN_AMBIENT_TEMPERATURE_TOO_HIGH:
pr_emerg("High ambient temperature detected. Check RTAS"
" error log for details\n");
orderly_poweroff(true);
break;
default:
pr_err("Unknown power/cooling shutdown event (modifier = %d)\n",
event_modifier);
}
}
static void rtas_parse_epow_errlog(struct rtas_error_log *log)
{
struct pseries_errorlog *pseries_log;
struct epow_errorlog *epow_log;
char action_code;
char modifier;
pseries_log = get_pseries_errorlog(log, PSERIES_ELOG_SECT_ID_EPOW);
if (pseries_log == NULL)
return;
epow_log = (struct epow_errorlog *)pseries_log->data;
action_code = epow_log->sensor_value & 0xF;
modifier = epow_log->event_modifier & 0xF;
switch (action_code) {
case EPOW_RESET:
if (num_epow_events) {
pr_info("Non critical power/cooling issue cleared\n");
num_epow_events--;
}
break;
case EPOW_WARN_COOLING:
pr_info("Non-critical cooling issue detected. Check RTAS error"
" log for details\n");
break;
case EPOW_WARN_POWER:
pr_info("Non-critical power issue detected. Check RTAS error"
" log for details\n");
break;
case EPOW_SYSTEM_SHUTDOWN:
handle_system_shutdown(epow_log->event_modifier);
break;
case EPOW_SYSTEM_HALT:
pr_emerg("Critical power/cooling issue detected. Check RTAS"
" error log for details. Powering off.\n");
orderly_poweroff(true);
break;
case EPOW_MAIN_ENCLOSURE:
case EPOW_POWER_OFF:
pr_emerg("System about to lose power. Check RTAS error log "
" for details. Powering off immediately.\n");
emergency_sync();
kernel_power_off();
break;
default:
pr_err("Unknown power/cooling event (action code = %d)\n",
action_code);
}
if (action_code != EPOW_RESET)
num_epow_events++;
}
static irqreturn_t ras_hotplug_interrupt(int irq, void *dev_id)
{
struct pseries_errorlog *pseries_log;
struct pseries_hp_errorlog *hp_elog;
spin_lock(&ras_log_buf_lock);
rtas_call(ras_check_exception_token, 6, 1, NULL,
RTAS_VECTOR_EXTERNAL_INTERRUPT, virq_to_hw(irq),
RTAS_HOTPLUG_EVENTS, 0, __pa(&ras_log_buf),
rtas_get_error_log_max());
pseries_log = get_pseries_errorlog((struct rtas_error_log *)ras_log_buf,
PSERIES_ELOG_SECT_ID_HOTPLUG);
hp_elog = (struct pseries_hp_errorlog *)pseries_log->data;
if (hp_elog->resource == PSERIES_HP_ELOG_RESOURCE_MEM ||
hp_elog->resource == PSERIES_HP_ELOG_RESOURCE_CPU)
queue_hotplug_event(hp_elog, NULL, NULL);
else
log_error(ras_log_buf, ERR_TYPE_RTAS_LOG, 0);
spin_unlock(&ras_log_buf_lock);
return IRQ_HANDLED;
}
static irqreturn_t ras_epow_interrupt(int irq, void *dev_id)
{
int status;
int state;
int critical;
status = rtas_get_sensor_fast(EPOW_SENSOR_TOKEN, EPOW_SENSOR_INDEX,
&state);
if (state > 3)
critical = 1;
else
critical = 0;
spin_lock(&ras_log_buf_lock);
status = rtas_call(ras_check_exception_token, 6, 1, NULL,
RTAS_VECTOR_EXTERNAL_INTERRUPT,
virq_to_hw(irq),
RTAS_EPOW_WARNING,
critical, __pa(&ras_log_buf),
rtas_get_error_log_max());
log_error(ras_log_buf, ERR_TYPE_RTAS_LOG, 0);
rtas_parse_epow_errlog((struct rtas_error_log *)ras_log_buf);
spin_unlock(&ras_log_buf_lock);
return IRQ_HANDLED;
}
static irqreturn_t ras_error_interrupt(int irq, void *dev_id)
{
struct rtas_error_log *rtas_elog;
int status;
int fatal;
spin_lock(&ras_log_buf_lock);
status = rtas_call(ras_check_exception_token, 6, 1, NULL,
RTAS_VECTOR_EXTERNAL_INTERRUPT,
virq_to_hw(irq),
RTAS_INTERNAL_ERROR, 1 ,
__pa(&ras_log_buf),
rtas_get_error_log_max());
rtas_elog = (struct rtas_error_log *)ras_log_buf;
if (status == 0 &&
rtas_error_severity(rtas_elog) >= RTAS_SEVERITY_ERROR_SYNC)
fatal = 1;
else
fatal = 0;
log_error(ras_log_buf, ERR_TYPE_RTAS_LOG, fatal);
if (fatal) {
pr_emerg("Fatal hardware error detected. Check RTAS error"
" log for details. Powering off immediately\n");
emergency_sync();
kernel_power_off();
} else {
pr_err("Recoverable hardware error detected\n");
}
spin_unlock(&ras_log_buf_lock);
return IRQ_HANDLED;
}
static struct rtas_error_log *fwnmi_get_errinfo(struct pt_regs *regs)
{
unsigned long *savep;
struct rtas_error_log *h, *errhdr = NULL;
regs->gpr[3] &= ~(0x3UL << 62);
if (!VALID_FWNMI_BUFFER(regs->gpr[3])) {
printk(KERN_ERR "FWNMI: corrupt r3 0x%016lx\n", regs->gpr[3]);
return NULL;
}
savep = __va(regs->gpr[3]);
regs->gpr[3] = savep[0];
h = (struct rtas_error_log *)&savep[1];
if (!rtas_error_extended(h)) {
memcpy(this_cpu_ptr(&mce_data_buf), h, sizeof(__u64));
errhdr = (struct rtas_error_log *)this_cpu_ptr(&mce_data_buf);
} else {
int len, error_log_length;
error_log_length = 8 + rtas_error_extended_log_length(h);
len = max_t(int, error_log_length, RTAS_ERROR_LOG_MAX);
memset(global_mce_data_buf, 0, RTAS_ERROR_LOG_MAX);
memcpy(global_mce_data_buf, h, len);
errhdr = (struct rtas_error_log *)global_mce_data_buf;
}
return errhdr;
}
static void fwnmi_release_errinfo(void)
{
int ret = rtas_call(rtas_token("ibm,nmi-interlock"), 0, 1, NULL);
if (ret != 0)
printk(KERN_ERR "FWNMI: nmi-interlock failed: %d\n", ret);
}
int pSeries_system_reset_exception(struct pt_regs *regs)
{
if (fwnmi_active) {
struct rtas_error_log *errhdr = fwnmi_get_errinfo(regs);
if (errhdr) {
}
fwnmi_release_errinfo();
}
if (smp_handle_nmi_ipi(regs))
return 1;
return 0;
}
static int recover_mce(struct pt_regs *regs, struct rtas_error_log *err)
{
int recovered = 0;
int disposition = rtas_error_disposition(err);
if (!(regs->msr & MSR_RI)) {
recovered = 0;
} else if (disposition == RTAS_DISP_FULLY_RECOVERED) {
recovered = 1;
} else if (disposition == RTAS_DISP_LIMITED_RECOVERY) {
printk(KERN_ERR "MCE: limited recovery, system may "
"be degraded\n");
recovered = 1;
} else if (user_mode(regs) && !is_global_init(current) &&
rtas_error_severity(err) == RTAS_SEVERITY_ERROR_SYNC) {
printk(KERN_ERR "MCE: uncorrectable error, killing task "
"%s:%d\n", current->comm, current->pid);
_exception(SIGBUS, regs, BUS_MCEERR_AR, regs->nip);
recovered = 1;
}
log_error((char *)err, ERR_TYPE_RTAS_LOG, 0);
return recovered;
}
int pSeries_machine_check_exception(struct pt_regs *regs)
{
struct rtas_error_log *errp;
if (fwnmi_active) {
errp = fwnmi_get_errinfo(regs);
fwnmi_release_errinfo();
if (errp && recover_mce(regs, errp))
return 1;
}
return 0;
}
