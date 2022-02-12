static int __init init_ras_IRQ(void)
{
struct device_node *np;
ras_get_sensor_state_token = rtas_token("get-sensor-state");
ras_check_exception_token = rtas_token("check-exception");
np = of_find_node_by_path("/event-sources/internal-errors");
if (np != NULL) {
request_event_sources_irqs(np, ras_error_interrupt,
"RAS_ERROR");
of_node_put(np);
}
np = of_find_node_by_path("/event-sources/epow-events");
if (np != NULL) {
request_event_sources_irqs(np, ras_epow_interrupt, "RAS_EPOW");
of_node_put(np);
}
return 0;
}
static irqreturn_t ras_epow_interrupt(int irq, void *dev_id)
{
int status = 0xdeadbeef;
int state = 0;
int critical;
status = rtas_call(ras_get_sensor_state_token, 2, 2, &state,
EPOW_SENSOR_TOKEN, EPOW_SENSOR_INDEX);
if (state > 3)
critical = 1;
else
critical = 0;
spin_lock(&ras_log_buf_lock);
status = rtas_call(ras_check_exception_token, 6, 1, NULL,
RTAS_VECTOR_EXTERNAL_INTERRUPT,
virq_to_hw(irq),
RTAS_EPOW_WARNING | RTAS_POWERMGM_EVENTS,
critical, __pa(&ras_log_buf),
rtas_get_error_log_max());
udbg_printf("EPOW <0x%lx 0x%x 0x%x>\n",
*((unsigned long *)&ras_log_buf), status, state);
printk(KERN_WARNING "EPOW <0x%lx 0x%x 0x%x>\n",
*((unsigned long *)&ras_log_buf), status, state);
log_error(ras_log_buf, ERR_TYPE_RTAS_LOG, 0);
spin_unlock(&ras_log_buf_lock);
return IRQ_HANDLED;
}
static irqreturn_t ras_error_interrupt(int irq, void *dev_id)
{
struct rtas_error_log *rtas_elog;
int status = 0xdeadbeef;
int fatal;
spin_lock(&ras_log_buf_lock);
status = rtas_call(ras_check_exception_token, 6, 1, NULL,
RTAS_VECTOR_EXTERNAL_INTERRUPT,
virq_to_hw(irq),
RTAS_INTERNAL_ERROR, 1 ,
__pa(&ras_log_buf),
rtas_get_error_log_max());
rtas_elog = (struct rtas_error_log *)ras_log_buf;
if ((status == 0) && (rtas_elog->severity >= RTAS_SEVERITY_ERROR_SYNC))
fatal = 1;
else
fatal = 0;
log_error(ras_log_buf, ERR_TYPE_RTAS_LOG, fatal);
if (fatal) {
udbg_printf("Fatal HW Error <0x%lx 0x%x>\n",
*((unsigned long *)&ras_log_buf), status);
printk(KERN_EMERG "Error: Fatal hardware error <0x%lx 0x%x>\n",
*((unsigned long *)&ras_log_buf), status);
#ifndef DEBUG_RTAS_POWER_OFF
ppc_md.power_off();
#endif
} else {
udbg_printf("Recoverable HW Error <0x%lx 0x%x>\n",
*((unsigned long *)&ras_log_buf), status);
printk(KERN_WARNING
"Warning: Recoverable hardware error <0x%lx 0x%x>\n",
*((unsigned long *)&ras_log_buf), status);
}
spin_unlock(&ras_log_buf_lock);
return IRQ_HANDLED;
}
static struct rtas_error_log *fwnmi_get_errinfo(struct pt_regs *regs)
{
unsigned long *savep;
struct rtas_error_log *h, *errhdr = NULL;
if (!VALID_FWNMI_BUFFER(regs->gpr[3])) {
printk(KERN_ERR "FWNMI: corrupt r3 0x%016lx\n", regs->gpr[3]);
return NULL;
}
savep = __va(regs->gpr[3]);
regs->gpr[3] = savep[0];
h = (struct rtas_error_log *)&savep[1];
if (!h->extended) {
memcpy(&__get_cpu_var(mce_data_buf), h, sizeof(__u64));
errhdr = (struct rtas_error_log *)&__get_cpu_var(mce_data_buf);
} else {
int len;
len = max_t(int, 8+h->extended_log_length, RTAS_ERROR_LOG_MAX);
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
return 0;
}
static int recover_mce(struct pt_regs *regs, struct rtas_error_log *err)
{
int recovered = 0;
if (!(regs->msr & MSR_RI)) {
recovered = 0;
} else if (err->disposition == RTAS_DISP_FULLY_RECOVERED) {
recovered = 1;
} else if (err->disposition == RTAS_DISP_LIMITED_RECOVERY) {
printk(KERN_ERR "MCE: limited recovery, system may "
"be degraded\n");
recovered = 1;
} else if (user_mode(regs) && !is_global_init(current) &&
err->severity == RTAS_SEVERITY_ERROR_SYNC) {
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
