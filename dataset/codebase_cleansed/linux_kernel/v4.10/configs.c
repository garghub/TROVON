static ssize_t
ikconfig_read_current(struct file *file, char __user *buf,
size_t len, loff_t * offset)
{
return simple_read_from_buffer(buf, len, offset,
kernel_config_data + MAGIC_SIZE,
kernel_config_data_size);
}
static int __init ikconfig_init(void)
{
struct proc_dir_entry *entry;
entry = proc_create("config.gz", S_IFREG | S_IRUGO, NULL,
&ikconfig_file_ops);
if (!entry)
return -ENOMEM;
proc_set_size(entry, kernel_config_data_size);
return 0;
}
static void __exit ikconfig_cleanup(void)
{
remove_proc_entry("config.gz", NULL);
}
