static ssize_t bootinfo_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
return simple_read_from_buffer(buf, count, ppos, bootinfo_copy,
bootinfo_size);
}
void __init save_bootinfo(const struct bi_record *bi)
{
const void *start = bi;
size_t size = sizeof(bi->tag);
while (be16_to_cpu(bi->tag) != BI_LAST) {
uint16_t n = be16_to_cpu(bi->size);
size += n;
bi = (struct bi_record *)((unsigned long)bi + n);
}
if (size > sizeof(bootinfo_tmp)) {
pr_err("Cannot save %zu bytes of bootinfo\n", size);
return;
}
pr_info("Saving %zu bytes of bootinfo\n", size);
memcpy(bootinfo_tmp, start, size);
bootinfo_size = size;
}
static int __init init_bootinfo_procfs(void)
{
struct proc_dir_entry *pde;
if (!bootinfo_size)
return -EINVAL;
bootinfo_copy = kmemdup(bootinfo_tmp, bootinfo_size, GFP_KERNEL);
if (!bootinfo_copy)
return -ENOMEM;
pde = proc_create_data("bootinfo", 0400, NULL, &bootinfo_fops, NULL);
if (!pde) {
kfree(bootinfo_copy);
return -ENOMEM;
}
return 0;
}
