static irqreturn_t soc_irq_thread_fn(int irq, void *dev_data)
{
pr_debug("proc_thermal_interrupt\n");
intel_soc_dts_iosf_interrupt_handler(soc_dts);
return IRQ_HANDLED;
}
static int __init intel_soc_thermal_init(void)
{
int err = 0;
const struct x86_cpu_id *match_cpu;
match_cpu = x86_match_cpu(soc_thermal_ids);
if (!match_cpu)
return -ENODEV;
soc_dts = intel_soc_dts_iosf_init(INTEL_SOC_DTS_INTERRUPT_APIC, 2, 1);
if (IS_ERR(soc_dts)) {
err = PTR_ERR(soc_dts);
return err;
}
soc_dts_thres_irq = (int)match_cpu->driver_data;
if (soc_dts_thres_irq) {
err = request_threaded_irq(soc_dts_thres_irq, NULL,
soc_irq_thread_fn,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"soc_dts", soc_dts);
if (err) {
pr_err("request_threaded_irq ret %d\n", err);
goto error_irq;
}
}
err = intel_soc_dts_iosf_add_read_only_critical_trip(soc_dts,
crit_offset);
if (err)
goto error_trips;
return 0;
error_trips:
if (soc_dts_thres_irq)
free_irq(soc_dts_thres_irq, soc_dts);
error_irq:
intel_soc_dts_iosf_exit(soc_dts);
return err;
}
static void __exit intel_soc_thermal_exit(void)
{
if (soc_dts_thres_irq)
free_irq(soc_dts_thres_irq, soc_dts);
intel_soc_dts_iosf_exit(soc_dts);
}
