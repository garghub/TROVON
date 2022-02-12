static int partition_id_show(struct seq_file *s, void *p)
{
seq_printf(s, "%d\n", sn_partition_id);
return 0;
}
static int partition_id_open(struct inode *inode, struct file *file)
{
return single_open(file, partition_id_show, NULL);
}
static int system_serial_number_show(struct seq_file *s, void *p)
{
seq_printf(s, "%s\n", sn_system_serial_number());
return 0;
}
static int system_serial_number_open(struct inode *inode, struct file *file)
{
return single_open(file, system_serial_number_show, NULL);
}
static int licenseID_show(struct seq_file *s, void *p)
{
seq_printf(s, "0x%llx\n", sn_partition_serial_number_val());
return 0;
}
static int licenseID_open(struct inode *inode, struct file *file)
{
return single_open(file, licenseID_show, NULL);
}
static int coherence_id_show(struct seq_file *s, void *p)
{
seq_printf(s, "%d\n", partition_coherence_id());
return 0;
}
static int coherence_id_open(struct inode *inode, struct file *file)
{
return single_open(file, coherence_id_show, NULL);
}
void register_sn_procfs(void)
{
static struct proc_dir_entry *sgi_proc_dir = NULL;
BUG_ON(sgi_proc_dir != NULL);
if (!(sgi_proc_dir = proc_mkdir("sgi_sn", NULL)))
return;
proc_create("partition_id", 0444, sgi_proc_dir,
&proc_partition_id_fops);
proc_create("system_serial_number", 0444, sgi_proc_dir,
&proc_system_sn_fops);
proc_create("licenseID", 0444, sgi_proc_dir, &proc_license_id_fops);
proc_create("coherence_id", 0444, sgi_proc_dir,
&proc_coherence_id_fops);
proc_create("sn_topology", 0444, sgi_proc_dir, &proc_sn_topo_fops);
}
