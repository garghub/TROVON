static int idefloppy_capacity_proc_show(struct seq_file *m, void *v)
{
ide_drive_t*drive = (ide_drive_t *)m->private;
seq_printf(m, "%llu\n", (long long)ide_gd_capacity(drive));
return 0;
}
static int idefloppy_capacity_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, idefloppy_capacity_proc_show, PDE(inode)->data);
}
