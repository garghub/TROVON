static int
fld_debugfs_targets_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_fld *fld = (struct lu_client_fld *)m->private;
struct lu_fld_target *target;
LASSERT(fld != NULL);
spin_lock(&fld->lcf_lock);
list_for_each_entry(target,
&fld->lcf_targets, ft_chain)
seq_printf(m, "%s\n", fld_target_name(target));
spin_unlock(&fld->lcf_lock);
return 0;
}
static int
fld_debugfs_hash_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_fld *fld = (struct lu_client_fld *)m->private;
LASSERT(fld != NULL);
spin_lock(&fld->lcf_lock);
seq_printf(m, "%s\n", fld->lcf_hash->fh_name);
spin_unlock(&fld->lcf_lock);
return 0;
}
static ssize_t
fld_debugfs_hash_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct lu_client_fld *fld;
struct lu_fld_hash *hash = NULL;
char fh_name[8];
int i;
if (count > sizeof(fh_name))
return -ENAMETOOLONG;
if (copy_from_user(fh_name, buffer, count) != 0)
return -EFAULT;
fld = ((struct seq_file *)file->private_data)->private;
LASSERT(fld != NULL);
for (i = 0; fld_hash[i].fh_name != NULL; i++) {
if (count != strlen(fld_hash[i].fh_name))
continue;
if (!strncmp(fld_hash[i].fh_name, fh_name, count)) {
hash = &fld_hash[i];
break;
}
}
if (hash != NULL) {
spin_lock(&fld->lcf_lock);
fld->lcf_hash = hash;
spin_unlock(&fld->lcf_lock);
CDEBUG(D_INFO, "%s: Changed hash to \"%s\"\n",
fld->lcf_name, hash->fh_name);
}
return count;
}
static ssize_t
fld_debugfs_cache_flush_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
struct lu_client_fld *fld = file->private_data;
LASSERT(fld != NULL);
fld_cache_flush(fld->lcf_cache);
CDEBUG(D_INFO, "%s: Lookup cache is flushed\n", fld->lcf_name);
return count;
}
static int
fld_debugfs_cache_flush_release(struct inode *inode, struct file *file)
{
file->private_data = NULL;
return 0;
}
