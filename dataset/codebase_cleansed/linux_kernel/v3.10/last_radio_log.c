static ssize_t last_radio_log_read(struct file *file, char __user *buf,
size_t len, loff_t *offset)
{
return simple_read_from_buffer(buf, len, offset,
radio_log_base, radio_log_size);
}
void msm_init_last_radio_log(struct module *owner)
{
struct proc_dir_entry *entry;
if (last_radio_log_fops.owner) {
pr_err("%s: already claimed\n", __func__);
return;
}
radio_log_base = smem_item(SMEM_CLKREGIM_BSP, &radio_log_size);
if (!radio_log_base) {
pr_err("%s: could not retrieve SMEM_CLKREGIM_BSP\n", __func__);
return;
}
entry = proc_create("last_radio_log", S_IRUGO, NULL,
&last_radio_log_fops);
if (!entry) {
pr_err("%s: could not create proc entry for radio log\n",
__func__);
return;
}
pr_err("%s: last radio log is %d bytes long\n", __func__,
radio_log_size);
last_radio_log_fops.owner = owner;
proc_set_size(entry, radio_log_size);
}
