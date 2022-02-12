static ssize_t numobd_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
struct lmv_desc *desc;
desc = &dev->u.lmv.desc;
return sprintf(buf, "%u\n", desc->ld_tgt_count);
}
static enum placement_policy placement_name2policy(char *name, int len)
{
int i;
for (i = 0; i < PLACEMENT_MAX_POLICY; i++) {
if (!strncmp(placement_name[i], name, len))
return i;
}
return PLACEMENT_INVAL_POLICY;
}
static const char *placement_policy2name(enum placement_policy placement)
{
LASSERT(placement < PLACEMENT_MAX_POLICY);
return placement_name[placement];
}
static ssize_t placement_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
struct lmv_obd *lmv;
lmv = &dev->u.lmv;
return sprintf(buf, "%s\n", placement_policy2name(lmv->lmv_placement));
}
static ssize_t placement_store(struct kobject *kobj, struct attribute *attr,
const char *buffer,
size_t count)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
char dummy[MAX_POLICY_STRING_SIZE + 1];
enum placement_policy policy;
struct lmv_obd *lmv = &dev->u.lmv;
memcpy(dummy, buffer, MAX_POLICY_STRING_SIZE);
if (count > MAX_POLICY_STRING_SIZE)
count = MAX_POLICY_STRING_SIZE;
if (dummy[count - 1] == '\n')
count--;
dummy[count] = '\0';
policy = placement_name2policy(dummy, count);
if (policy != PLACEMENT_INVAL_POLICY) {
spin_lock(&lmv->lmv_lock);
lmv->lmv_placement = policy;
spin_unlock(&lmv->lmv_lock);
} else {
return -EINVAL;
}
return count;
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
LASSERT(dev != NULL);
lmv = &dev->u.lmv;
seq_printf(m, "%s\n", lmv->desc.ld_uuid.uuid);
return 0;
}
static void *lmv_tgt_seq_start(struct seq_file *p, loff_t *pos)
{
struct obd_device *dev = p->private;
struct lmv_obd *lmv = &dev->u.lmv;
return (*pos >= lmv->desc.ld_tgt_count) ? NULL : lmv->tgts[*pos];
}
static void lmv_tgt_seq_stop(struct seq_file *p, void *v)
{
return;
}
static void *lmv_tgt_seq_next(struct seq_file *p, void *v, loff_t *pos)
{
struct obd_device *dev = p->private;
struct lmv_obd *lmv = &dev->u.lmv;
++*pos;
return (*pos >= lmv->desc.ld_tgt_count) ? NULL : lmv->tgts[*pos];
}
static int lmv_tgt_seq_show(struct seq_file *p, void *v)
{
struct lmv_tgt_desc *tgt = v;
if (tgt == NULL)
return 0;
seq_printf(p, "%d: %s %sACTIVE\n",
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
