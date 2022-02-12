static void *int_seq_start(struct seq_file *f, loff_t *pos)
{
return (*pos <= nr_irqs) ? pos : NULL;
}
static void *int_seq_next(struct seq_file *f, void *v, loff_t *pos)
{
(*pos)++;
if (*pos > nr_irqs)
return NULL;
return pos;
}
static void int_seq_stop(struct seq_file *f, void *v)
{
}
static int interrupts_open(struct inode *inode, struct file *filp)
{
return seq_open(filp, &int_seq_ops);
}
static int __init proc_interrupts_init(void)
{
proc_create("interrupts", 0, NULL, &proc_interrupts_operations);
return 0;
}
