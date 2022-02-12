void __init check_bugs(void)
{
identify_boot_cpu();
#if !defined(CONFIG_SMP)
printk(KERN_INFO "CPU: ");
print_cpu_info(&boot_cpu_data);
#endif
alternative_instructions();
if (!direct_gbpages)
set_memory_4k((unsigned long)__va(0), 1);
}
