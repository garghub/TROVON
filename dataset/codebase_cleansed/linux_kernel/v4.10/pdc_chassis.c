static int __init pdc_chassis_setup(char *str)
{
get_option(&str, &pdc_chassis_enabled);
return 1;
}
static int pdc_chassis_panic_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
pdc_chassis_send_status(PDC_CHASSIS_DIRECT_PANIC);
return NOTIFY_DONE;
}
static int pdc_chassis_reboot_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
pdc_chassis_send_status(PDC_CHASSIS_DIRECT_SHUTDOWN);
return NOTIFY_DONE;
}
void __init parisc_pdc_chassis_init(void)
{
#ifdef CONFIG_PDC_CHASSIS
if (likely(pdc_chassis_enabled)) {
DPRINTK(KERN_DEBUG "%s: parisc_pdc_chassis_init()\n", __FILE__);
printk(KERN_INFO "Enabling %s chassis codes support v%s\n",
is_pdc_pat() ? "PDC_PAT" : "regular",
PDC_CHASSIS_VER);
atomic_notifier_chain_register(&panic_notifier_list,
&pdc_chassis_panic_block);
register_reboot_notifier(&pdc_chassis_reboot_block);
}
#endif
}
int pdc_chassis_send_status(int message)
{
int retval = 0;
#ifdef CONFIG_PDC_CHASSIS
if (likely(pdc_chassis_enabled)) {
DPRINTK(KERN_DEBUG "%s: pdc_chassis_send_status(%d)\n", __FILE__, message);
#ifdef CONFIG_64BIT
if (is_pdc_pat()) {
switch(message) {
case PDC_CHASSIS_DIRECT_BSTART:
retval = pdc_pat_chassis_send_log(PDC_CHASSIS_PMSG_BSTART, PDC_CHASSIS_LSTATE_RUN_NORMAL);
break;
case PDC_CHASSIS_DIRECT_BCOMPLETE:
retval = pdc_pat_chassis_send_log(PDC_CHASSIS_PMSG_BCOMPLETE, PDC_CHASSIS_LSTATE_RUN_NORMAL);
break;
case PDC_CHASSIS_DIRECT_SHUTDOWN:
retval = pdc_pat_chassis_send_log(PDC_CHASSIS_PMSG_SHUTDOWN, PDC_CHASSIS_LSTATE_NONOS);
break;
case PDC_CHASSIS_DIRECT_PANIC:
retval = pdc_pat_chassis_send_log(PDC_CHASSIS_PMSG_PANIC, PDC_CHASSIS_LSTATE_RUN_CRASHREC);
break;
case PDC_CHASSIS_DIRECT_LPMC:
retval = pdc_pat_chassis_send_log(PDC_CHASSIS_PMSG_LPMC, PDC_CHASSIS_LSTATE_RUN_SYSINT);
break;
case PDC_CHASSIS_DIRECT_HPMC:
retval = pdc_pat_chassis_send_log(PDC_CHASSIS_PMSG_HPMC, PDC_CHASSIS_LSTATE_RUN_NCRIT);
break;
default:
retval = -1;
}
} else retval = -1;
#else
if (1) {
switch (message) {
case PDC_CHASSIS_DIRECT_BSTART:
retval = pdc_chassis_disp(PDC_CHASSIS_DISP_DATA(OSTAT_INIT));
break;
case PDC_CHASSIS_DIRECT_BCOMPLETE:
retval = pdc_chassis_disp(PDC_CHASSIS_DISP_DATA(OSTAT_RUN));
break;
case PDC_CHASSIS_DIRECT_SHUTDOWN:
retval = pdc_chassis_disp(PDC_CHASSIS_DISP_DATA(OSTAT_SHUT));
break;
case PDC_CHASSIS_DIRECT_HPMC:
case PDC_CHASSIS_DIRECT_PANIC:
retval = pdc_chassis_disp(PDC_CHASSIS_DISP_DATA(OSTAT_FLT));
break;
case PDC_CHASSIS_DIRECT_LPMC:
retval = pdc_chassis_disp(PDC_CHASSIS_DISP_DATA(OSTAT_WARN));
break;
default:
retval = -1;
}
} else retval = -1;
#endif
}
#endif
return retval;
}
static int pdc_chassis_warn_show(struct seq_file *m, void *v)
{
unsigned long warn;
u32 warnreg;
if (pdc_chassis_warn(&warn) != PDC_OK)
return -EIO;
warnreg = (warn & 0xFFFFFFFF);
if ((warnreg >> 24) & 0xFF)
seq_printf(m, "Chassis component failure! (eg fan or PSU): 0x%.2x\n",
(warnreg >> 24) & 0xFF);
seq_printf(m, "Battery: %s\n", (warnreg & 0x04) ? "Low!" : "OK");
seq_printf(m, "Temp low: %s\n", (warnreg & 0x02) ? "Exceeded!" : "OK");
seq_printf(m, "Temp mid: %s\n", (warnreg & 0x01) ? "Exceeded!" : "OK");
return 0;
}
static int pdc_chassis_warn_open(struct inode *inode, struct file *file)
{
return single_open(file, pdc_chassis_warn_show, NULL);
}
static int __init pdc_chassis_create_procfs(void)
{
unsigned long test;
int ret;
ret = pdc_chassis_warn(&test);
if ((ret == PDC_BAD_PROC) || (ret == PDC_BAD_OPTION)) {
printk(KERN_INFO "Chassis warnings not supported.\n");
return 0;
}
printk(KERN_INFO "Enabling PDC chassis warnings support v%s\n",
PDC_CHASSIS_VER);
proc_create("chassis", 0400, NULL, &pdc_chassis_warn_fops);
return 0;
}
