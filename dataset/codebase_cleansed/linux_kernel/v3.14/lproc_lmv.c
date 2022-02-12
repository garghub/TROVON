static int lmv_numobd_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lmv_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lmv.desc;
return seq_printf(m, "%u\n", desc->ld_tgt_count);
}
static placement_policy_t placement_name2policy(char *name, int len)
{
int i;
for (i = 0; i < PLACEMENT_MAX_POLICY; i++) {
if (!strncmp(placement_name[i], name, len))
return i;
}
return PLACEMENT_INVAL_POLICY;
}
static const char *placement_policy2name(placement_policy_t placement)
{
LASSERT(placement < PLACEMENT_MAX_POLICY);
return placement_name[placement];
}
static int lmv_placement_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lmv_obd *lmv;
LASSERT(dev != NULL);
lmv = &dev->u.lmv;
return seq_printf(m, "%s\n", placement_policy2name(lmv->lmv_placement));
}
static ssize_t lmv_placement_seq_write(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct obd_device *dev = ((struct seq_file *)file->private_data)->private;
char dummy[MAX_POLICY_STRING_SIZE + 1];
int len = count;
placement_policy_t policy;
struct lmv_obd *lmv;
if (copy_from_user(dummy, buffer, MAX_POLICY_STRING_SIZE))
return -EFAULT;
LASSERT(dev != NULL);
lmv = &dev->u.lmv;
if (len > MAX_POLICY_STRING_SIZE)
len = MAX_POLICY_STRING_SIZE;
if (dummy[len - 1] == '\n')
len--;
dummy[len] = '\0';
policy = placement_name2policy(dummy, len);
if (policy != PLACEMENT_INVAL_POLICY) {
spin_lock(&lmv->lmv_lock);
lmv->lmv_placement = policy;
spin_unlock(&lmv->lmv_lock);
} else {
CERROR("Invalid placement policy \"%s\"!\n", dummy);
return -EINVAL;
}
return count;
}
static int lmv_activeobd_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lmv_desc *desc;
LASSERT(dev != NULL);
desc = &dev->u.lmv.desc;
return seq_printf(m, "%u\n", desc->ld_active_tgt_count);
}
static int lmv_desc_uuid_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = (struct obd_device *)m->private;
struct lmv_obd *lmv;
LASSERT(dev != NULL);
lmv = &dev->u.lmv;
return seq_printf(m, "%s\n", lmv->desc.ld_uuid.uuid);
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
return seq_printf(p, "%d: %s %sACTIVE\n", tgt->ltd_idx,
tgt->ltd_uuid.uuid, tgt->ltd_active ? "" : "IN");
}
static int lmv_target_seq_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int rc;
rc = seq_open(file, &lmv_tgt_sops);
if (rc)
return rc;
seq = file->private_data;
seq->private = PDE_DATA(inode);
return 0;
}
void lprocfs_lmv_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->module_vars = lprocfs_lmv_module_vars;
lvars->obd_vars = lprocfs_lmv_obd_vars;
}
