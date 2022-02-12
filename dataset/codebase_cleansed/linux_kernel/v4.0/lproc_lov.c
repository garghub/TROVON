static int lov_stripesize_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lov_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
return seq_printf(m, "%llu\n", desc->ld_default_stripe_size);
}
static ssize_t lov_stripesize_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct obd_device *dev = ((struct seq_file *)file->private_data)->private;
struct lov_desc *desc;
__u64 val;
int rc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
rc = lprocfs_write_u64_helper(buffer, count, &val);
if (rc)
return rc;
lov_fix_desc_stripe_size(&val);
desc->ld_default_stripe_size = val;
return count;
}
static int lov_stripeoffset_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lov_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
return seq_printf(m, "%llu\n", desc->ld_default_stripe_offset);
}
static ssize_t lov_stripeoffset_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct obd_device *dev = ((struct seq_file *)file->private_data)->private;
struct lov_desc *desc;
__u64 val;
int rc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
rc = lprocfs_write_u64_helper(buffer, count, &val);
if (rc)
return rc;
desc->ld_default_stripe_offset = val;
return count;
}
static int lov_stripetype_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lov_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
return seq_printf(m, "%u\n", desc->ld_pattern);
}
static ssize_t lov_stripetype_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct obd_device *dev = ((struct seq_file *)file->private_data)->private;
struct lov_desc *desc;
int val, rc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
lov_fix_desc_pattern(&val);
desc->ld_pattern = val;
return count;
}
static int lov_stripecount_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lov_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
return seq_printf(m, "%d\n",
(__s16)(desc->ld_default_stripe_count + 1) - 1);
}
static ssize_t lov_stripecount_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct obd_device *dev = ((struct seq_file *)file->private_data)->private;
struct lov_desc *desc;
int val, rc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
lov_fix_desc_stripe_count(&val);
desc->ld_default_stripe_count = val;
return count;
}
static int lov_numobd_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lov_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
return seq_printf(m, "%u\n", desc->ld_tgt_count);
}
static int lov_activeobd_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lov_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lov.desc;
return seq_printf(m, "%u\n", desc->ld_active_tgt_count);
}
static int lov_desc_uuid_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lov_obd *lov;
LASSERT(dev != NULL);
lov = &dev->u.lov;
return seq_printf(m, "%s\n", lov->desc.ld_uuid.uuid);
}
static void *lov_tgt_seq_start(struct seq_file *p, loff_t *pos)
{
struct obd_device *dev = p->private;
struct lov_obd *lov = &dev->u.lov;
while (*pos < lov->desc.ld_tgt_count) {
if (lov->lov_tgts[*pos])
return lov->lov_tgts[*pos];
++*pos;
}
return NULL;
}
static void lov_tgt_seq_stop(struct seq_file *p, void *v)
{
}
static void *lov_tgt_seq_next(struct seq_file *p, void *v, loff_t *pos)
{
struct obd_device *dev = p->private;
struct lov_obd *lov = &dev->u.lov;
while (++*pos < lov->desc.ld_tgt_count) {
if (lov->lov_tgts[*pos])
return lov->lov_tgts[*pos];
}
return NULL;
}
static int lov_tgt_seq_show(struct seq_file *p, void *v)
{
struct lov_tgt_desc *tgt = v;
return seq_printf(p, "%d: %s %sACTIVE\n", tgt->ltd_index,
obd_uuid2str(&tgt->ltd_uuid),
tgt->ltd_active ? "" : "IN");
}
static int lov_target_seq_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int rc;
rc = seq_open(file, &lov_tgt_sops);
if (rc)
return rc;
seq = file->private_data;
seq->private = PDE_DATA(inode);
return 0;
}
void lprocfs_lov_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->module_vars = lprocfs_lov_module_vars;
lvars->obd_vars = lprocfs_lov_obd_vars;
}
