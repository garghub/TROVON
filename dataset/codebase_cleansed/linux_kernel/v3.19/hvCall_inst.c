static void *hc_start(struct seq_file *m, loff_t *pos)
{
if ((int)*pos < (HCALL_STAT_ARRAY_SIZE-1))
return (void *)(unsigned long)(*pos + 1);
return NULL;
}
static void *hc_next(struct seq_file *m, void *p, loff_t * pos)
{
++*pos;
return hc_start(m, pos);
}
static void hc_stop(struct seq_file *m, void *p)
{
}
static int hc_show(struct seq_file *m, void *p)
{
unsigned long h_num = (unsigned long)p;
struct hcall_stats *hs = m->private;
if (hs[h_num].num_calls) {
if (cpu_has_feature(CPU_FTR_PURR))
seq_printf(m, "%lu %lu %lu %lu\n", h_num<<2,
hs[h_num].num_calls,
hs[h_num].tb_total,
hs[h_num].purr_total);
else
seq_printf(m, "%lu %lu %lu\n", h_num<<2,
hs[h_num].num_calls,
hs[h_num].tb_total);
}
return 0;
}
static int hcall_inst_seq_open(struct inode *inode, struct file *file)
{
int rc;
struct seq_file *seq;
rc = seq_open(file, &hcall_inst_seq_ops);
seq = file->private_data;
seq->private = file_inode(file)->i_private;
return rc;
}
static void probe_hcall_entry(void *ignored, unsigned long opcode, unsigned long *args)
{
struct hcall_stats *h;
if (opcode > MAX_HCALL_OPCODE)
return;
h = this_cpu_ptr(&hcall_stats[opcode / 4]);
h->tb_start = mftb();
h->purr_start = mfspr(SPRN_PURR);
}
static void probe_hcall_exit(void *ignored, unsigned long opcode, unsigned long retval,
unsigned long *retbuf)
{
struct hcall_stats *h;
if (opcode > MAX_HCALL_OPCODE)
return;
h = this_cpu_ptr(&hcall_stats[opcode / 4]);
h->num_calls++;
h->tb_total += mftb() - h->tb_start;
h->purr_total += mfspr(SPRN_PURR) - h->purr_start;
}
static int __init hcall_inst_init(void)
{
struct dentry *hcall_root;
struct dentry *hcall_file;
char cpu_name_buf[CPU_NAME_BUF_SIZE];
int cpu;
if (!firmware_has_feature(FW_FEATURE_LPAR))
return 0;
if (register_trace_hcall_entry(probe_hcall_entry, NULL))
return -EINVAL;
if (register_trace_hcall_exit(probe_hcall_exit, NULL)) {
unregister_trace_hcall_entry(probe_hcall_entry, NULL);
return -EINVAL;
}
hcall_root = debugfs_create_dir(HCALL_ROOT_DIR, NULL);
if (!hcall_root)
return -ENOMEM;
for_each_possible_cpu(cpu) {
snprintf(cpu_name_buf, CPU_NAME_BUF_SIZE, "cpu%d", cpu);
hcall_file = debugfs_create_file(cpu_name_buf, S_IRUGO,
hcall_root,
per_cpu(hcall_stats, cpu),
&hcall_inst_seq_fops);
if (!hcall_file)
return -ENOMEM;
}
return 0;
}
