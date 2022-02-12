static int entry_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
struct my_data *data;
if (!current->mm)
return 1;
data = (struct my_data *)ri->data;
data->entry_stamp = ktime_get();
return 0;
}
static int ret_handler(struct kretprobe_instance *ri, struct pt_regs *regs)
{
int retval = regs_return_value(regs);
struct my_data *data = (struct my_data *)ri->data;
s64 delta;
ktime_t now;
now = ktime_get();
delta = ktime_to_ns(ktime_sub(now, data->entry_stamp));
printk(KERN_INFO "%s returned %d and took %lld ns to execute\n",
func_name, retval, (long long)delta);
return 0;
}
static int __init kretprobe_init(void)
{
int ret;
my_kretprobe.kp.symbol_name = func_name;
ret = register_kretprobe(&my_kretprobe);
if (ret < 0) {
printk(KERN_INFO "register_kretprobe failed, returned %d\n",
ret);
return -1;
}
printk(KERN_INFO "Planted return probe at %s: %p\n",
my_kretprobe.kp.symbol_name, my_kretprobe.kp.addr);
return 0;
}
static void __exit kretprobe_exit(void)
{
unregister_kretprobe(&my_kretprobe);
printk(KERN_INFO "kretprobe at %p unregistered\n",
my_kretprobe.kp.addr);
printk(KERN_INFO "Missed probing %d instances of %s\n",
my_kretprobe.nmissed, my_kretprobe.kp.symbol_name);
}
