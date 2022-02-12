static ssize_t numobd_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
struct lmv_desc *desc;
desc = &dev->u.lmv.desc;
return sprintf(buf, "%u\n", desc->ld_tgt_count);
}
static ssize_t activeobd_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
struct lmv_desc *desc;
desc = &dev->u.lmv.desc;
return sprintf(buf, "%u\n", desc->ld_active_tgt_count);
}
static int lmv_desc_uuid_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lmv_obd *lmv;
LASSERT(dev);
lmv = &dev->u.lmv;
seq_printf(m, "%s\n", lmv->desc.ld_uuid.uuid);
return 0;
}
static void *lmv_tgt_seq_start(struct seq_file *p, loff_t *pos)
{
struct obd_device *dev = p->private;
struct lmv_obd *lmv = &dev->u.lmv;
while (*pos < lmv->tgts_size) {
if (lmv->tgts[*pos])
return lmv->tgts[*pos];
++*pos;
}
return NULL;
}
static void lmv_tgt_seq_stop(struct seq_file *p, void *v)
{
}
static void *lmv_tgt_seq_next(struct seq_file *p, void *v, loff_t *pos)
{
struct obd_device *dev = p->private;
struct lmv_obd *lmv = &dev->u.lmv;
++*pos;
while (*pos < lmv->tgts_size) {
if (lmv->tgts[*pos])
return lmv->tgts[*pos];
++*pos;
}
return NULL;
}
static int lmv_tgt_seq_show(struct seq_file *p, void *v)
{
struct lmv_tgt_desc *tgt = v;
if (!tgt)
return 0;
seq_printf(p, "%u: %s %sACTIVE\n",
tgt->ltd_idx, tgt->ltd_uuid.uuid,
tgt->ltd_active ? "" : "IN");
return 0;
}
static int lmv_target_seq_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int rc;
rc = seq_open(file, &lmv_tgt_sops);
if (rc)
return rc;
seq = file->private_data;
seq->private = inode->i_private;
return 0;
}
void lprocfs_lmv_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->sysfs_vars = &lmv_attr_group;
lvars->obd_vars = lprocfs_lmv_obd_vars;
}
