static int sctp_objcnt_seq_show(struct seq_file *seq, void *v)
{
int i, len;
i = (int)*(loff_t *)v;
seq_printf(seq, "%s: %d%n", sctp_dbg_objcnt[i].label,
atomic_read(sctp_dbg_objcnt[i].counter), &len);
seq_printf(seq, "%*s\n", 127 - len, "");
return 0;
}
static void *sctp_objcnt_seq_start(struct seq_file *seq, loff_t *pos)
{
return (*pos >= ARRAY_SIZE(sctp_dbg_objcnt)) ? NULL : (void *)pos;
}
static void sctp_objcnt_seq_stop(struct seq_file *seq, void *v)
{
}
static void * sctp_objcnt_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
++*pos;
return (*pos >= ARRAY_SIZE(sctp_dbg_objcnt)) ? NULL : (void *)pos;
}
static int sctp_objcnt_seq_open(struct inode *inode, struct file *file)
{
return seq_open(file, &sctp_objcnt_seq_ops);
}
void sctp_dbg_objcnt_init(void)
{
struct proc_dir_entry *ent;
ent = proc_create("sctp_dbg_objcnt", 0,
proc_net_sctp, &sctp_objcnt_ops);
if (!ent)
pr_warn("sctp_dbg_objcnt: Unable to create /proc entry.\n");
}
void sctp_dbg_objcnt_exit(void)
{
remove_proc_entry("sctp_dbg_objcnt", proc_net_sctp);
}
