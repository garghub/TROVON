static void sample_hbp_handler(struct perf_event *bp,
struct perf_sample_data *data,
struct pt_regs *regs)
{
printk(KERN_INFO "%s value is changed\n", ksym_name);
dump_stack();
printk(KERN_INFO "Dump stack from sample_hbp_handler\n");
}
static int __init hw_break_module_init(void)
{
int ret;
struct perf_event_attr attr;
hw_breakpoint_init(&attr);
attr.bp_addr = kallsyms_lookup_name(ksym_name);
attr.bp_len = HW_BREAKPOINT_LEN_4;
attr.bp_type = HW_BREAKPOINT_W | HW_BREAKPOINT_R;
sample_hbp = register_wide_hw_breakpoint(&attr, sample_hbp_handler, NULL);
if (IS_ERR((void __force *)sample_hbp)) {
ret = PTR_ERR((void __force *)sample_hbp);
goto fail;
}
printk(KERN_INFO "HW Breakpoint for %s write installed\n", ksym_name);
return 0;
fail:
printk(KERN_INFO "Breakpoint registration failed\n");
return ret;
}
static void __exit hw_break_module_exit(void)
{
unregister_wide_hw_breakpoint(sample_hbp);
printk(KERN_INFO "HW Breakpoint for %s write uninstalled\n", ksym_name);
}
