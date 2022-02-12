static int fscache_histogram_show(struct seq_file *m, void *v)
{
unsigned long index;
unsigned n[5], t;
switch ((unsigned long) v) {
case 1:
seq_puts(m, "JIFS SECS OBJ INST OP RUNS OBJ RUNS RETRV DLY RETRIEVLS\n");
return 0;
case 2:
seq_puts(m, "===== ===== ========= ========= ========= ========= =========\n");
return 0;
default:
index = (unsigned long) v - 3;
n[0] = atomic_read(&fscache_obj_instantiate_histogram[index]);
n[1] = atomic_read(&fscache_ops_histogram[index]);
n[2] = atomic_read(&fscache_objs_histogram[index]);
n[3] = atomic_read(&fscache_retrieval_delay_histogram[index]);
n[4] = atomic_read(&fscache_retrieval_histogram[index]);
if (!(n[0] | n[1] | n[2] | n[3] | n[4]))
return 0;
t = (index * 1000) / HZ;
seq_printf(m, "%4lu 0.%03u %9u %9u %9u %9u %9u\n",
index, t, n[0], n[1], n[2], n[3], n[4]);
return 0;
}
}
static void *fscache_histogram_start(struct seq_file *m, loff_t *_pos)
{
if ((unsigned long long)*_pos >= HZ + 2)
return NULL;
if (*_pos == 0)
*_pos = 1;
return (void *)(unsigned long) *_pos;
}
static void *fscache_histogram_next(struct seq_file *m, void *v, loff_t *pos)
{
(*pos)++;
return (unsigned long long)*pos > HZ + 2 ?
NULL : (void *)(unsigned long) *pos;
}
static void fscache_histogram_stop(struct seq_file *m, void *v)
{
}
static int fscache_histogram_open(struct inode *inode, struct file *file)
{
return seq_open(file, &fscache_histogram_ops);
}
