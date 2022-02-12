static int mon_stat_open(struct inode *inode, struct file *file)
{
struct mon_bus *mbus;
struct snap *sp;
sp = kmalloc(sizeof(struct snap), GFP_KERNEL);
if (sp == NULL)
return -ENOMEM;
mbus = inode->i_private;
sp->slen = snprintf(sp->str, STAT_BUF_SIZE,
"nreaders %d events %u text_lost %u\n",
mbus->nreaders, mbus->cnt_events, mbus->cnt_text_lost);
file->private_data = sp;
return 0;
}
static ssize_t mon_stat_read(struct file *file, char __user *buf,
size_t nbytes, loff_t *ppos)
{
struct snap *sp = file->private_data;
return simple_read_from_buffer(buf, nbytes, ppos, sp->str, sp->slen);
}
static int mon_stat_release(struct inode *inode, struct file *file)
{
struct snap *sp = file->private_data;
file->private_data = NULL;
kfree(sp);
return 0;
}
