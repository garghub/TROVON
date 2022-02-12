int edac_mc_get_log_ue(void)
{
return edac_mc_log_ue;
}
int edac_mc_get_log_ce(void)
{
return edac_mc_log_ce;
}
int edac_mc_get_panic_on_ue(void)
{
return edac_mc_panic_on_ue;
}
int edac_mc_get_poll_msec(void)
{
return edac_mc_poll_msec;
}
static int edac_set_poll_msec(const char *val, struct kernel_param *kp)
{
long l;
int ret;
if (!val)
return -EINVAL;
ret = strict_strtol(val, 0, &l);
if (ret == -EINVAL || ((int)l != l))
return -EINVAL;
*((int *)kp->arg) = l;
edac_mc_reset_delay_period(l);
return 0;
}
static ssize_t csrow_ue_count_show(struct csrow_info *csrow, char *data,
int private)
{
return sprintf(data, "%u\n", csrow->ue_count);
}
static ssize_t csrow_ce_count_show(struct csrow_info *csrow, char *data,
int private)
{
return sprintf(data, "%u\n", csrow->ce_count);
}
static ssize_t csrow_size_show(struct csrow_info *csrow, char *data,
int private)
{
return sprintf(data, "%u\n", PAGES_TO_MiB(csrow->nr_pages));
}
static ssize_t csrow_mem_type_show(struct csrow_info *csrow, char *data,
int private)
{
return sprintf(data, "%s\n", mem_types[csrow->mtype]);
}
static ssize_t csrow_dev_type_show(struct csrow_info *csrow, char *data,
int private)
{
return sprintf(data, "%s\n", dev_types[csrow->dtype]);
}
static ssize_t csrow_edac_mode_show(struct csrow_info *csrow, char *data,
int private)
{
return sprintf(data, "%s\n", edac_caps[csrow->edac_mode]);
}
static ssize_t channel_dimm_label_show(struct csrow_info *csrow,
char *data, int channel)
{
if (!csrow->channels[channel].label[0])
return 0;
return snprintf(data, EDAC_MC_LABEL_LEN, "%s\n",
csrow->channels[channel].label);
}
static ssize_t channel_dimm_label_store(struct csrow_info *csrow,
const char *data,
size_t count, int channel)
{
ssize_t max_size = 0;
max_size = min((ssize_t) count, (ssize_t) EDAC_MC_LABEL_LEN - 1);
strncpy(csrow->channels[channel].label, data, max_size);
csrow->channels[channel].label[max_size] = '\0';
return max_size;
}
static ssize_t channel_ce_count_show(struct csrow_info *csrow,
char *data, int channel)
{
return sprintf(data, "%u\n", csrow->channels[channel].ce_count);
}
static ssize_t csrowdev_show(struct kobject *kobj,
struct attribute *attr, char *buffer)
{
struct csrow_info *csrow = to_csrow(kobj);
struct csrowdev_attribute *csrowdev_attr = to_csrowdev_attr(attr);
if (csrowdev_attr->show)
return csrowdev_attr->show(csrow,
buffer, csrowdev_attr->private);
return -EIO;
}
static ssize_t csrowdev_store(struct kobject *kobj, struct attribute *attr,
const char *buffer, size_t count)
{
struct csrow_info *csrow = to_csrow(kobj);
struct csrowdev_attribute *csrowdev_attr = to_csrowdev_attr(attr);
if (csrowdev_attr->store)
return csrowdev_attr->store(csrow,
buffer,
count, csrowdev_attr->private);
return -EIO;
}
static int edac_create_channel_files(struct kobject *kobj, int chan)
{
int err = -ENODEV;
if (chan >= EDAC_NR_CHANNELS)
return err;
err = sysfs_create_file(kobj,
(struct attribute *)
dynamic_csrow_dimm_attr[chan]);
if (!err) {
err = sysfs_create_file(kobj,
(struct attribute *)
dynamic_csrow_ce_count_attr[chan]);
} else {
debugf1("%s() dimm labels and ce_count files created",
__func__);
}
return err;
}
static void edac_csrow_instance_release(struct kobject *kobj)
{
struct mem_ctl_info *mci;
struct csrow_info *cs;
debugf1("%s()\n", __func__);
cs = container_of(kobj, struct csrow_info, kobj);
mci = cs->mci;
kobject_put(&mci->edac_mci_kobj);
}
static int edac_create_csrow_object(struct mem_ctl_info *mci,
struct csrow_info *csrow, int index)
{
struct kobject *kobj_mci = &mci->edac_mci_kobj;
struct kobject *kobj;
int chan;
int err;
memset(&csrow->kobj, 0, sizeof(csrow->kobj));
csrow->mci = mci;
kobj = kobject_get(&mci->edac_mci_kobj);
if (!kobj) {
err = -ENODEV;
goto err_out;
}
err = kobject_init_and_add(&csrow->kobj, &ktype_csrow, kobj_mci,
"csrow%d", index);
if (err)
goto err_release_top_kobj;
for (chan = 0; chan < csrow->nr_channels; chan++) {
err = edac_create_channel_files(&csrow->kobj, chan);
if (err) {
kobject_put(&csrow->kobj);
goto err_out;
}
}
kobject_uevent(&csrow->kobj, KOBJ_ADD);
return 0;
err_release_top_kobj:
kobject_put(&mci->edac_mci_kobj);
err_out:
return err;
}
static ssize_t mci_reset_counters_store(struct mem_ctl_info *mci,
const char *data, size_t count)
{
int row, chan;
mci->ue_noinfo_count = 0;
mci->ce_noinfo_count = 0;
mci->ue_count = 0;
mci->ce_count = 0;
for (row = 0; row < mci->nr_csrows; row++) {
struct csrow_info *ri = &mci->csrows[row];
ri->ue_count = 0;
ri->ce_count = 0;
for (chan = 0; chan < ri->nr_channels; chan++)
ri->channels[chan].ce_count = 0;
}
mci->start_time = jiffies;
return count;
}
static ssize_t mci_sdram_scrub_rate_store(struct mem_ctl_info *mci,
const char *data, size_t count)
{
unsigned long bandwidth = 0;
int new_bw = 0;
if (!mci->set_sdram_scrub_rate)
return -EINVAL;
if (strict_strtoul(data, 10, &bandwidth) < 0)
return -EINVAL;
new_bw = mci->set_sdram_scrub_rate(mci, bandwidth);
if (new_bw < 0) {
edac_printk(KERN_WARNING, EDAC_MC,
"Error setting scrub rate to: %lu\n", bandwidth);
return -EINVAL;
}
return count;
}
static ssize_t mci_sdram_scrub_rate_show(struct mem_ctl_info *mci, char *data)
{
int bandwidth = 0;
if (!mci->get_sdram_scrub_rate)
return -EINVAL;
bandwidth = mci->get_sdram_scrub_rate(mci);
if (bandwidth < 0) {
edac_printk(KERN_DEBUG, EDAC_MC, "Error reading scrub rate\n");
return bandwidth;
}
return sprintf(data, "%d\n", bandwidth);
}
static ssize_t mci_ue_count_show(struct mem_ctl_info *mci, char *data)
{
return sprintf(data, "%d\n", mci->ue_count);
}
static ssize_t mci_ce_count_show(struct mem_ctl_info *mci, char *data)
{
return sprintf(data, "%d\n", mci->ce_count);
}
static ssize_t mci_ce_noinfo_show(struct mem_ctl_info *mci, char *data)
{
return sprintf(data, "%d\n", mci->ce_noinfo_count);
}
static ssize_t mci_ue_noinfo_show(struct mem_ctl_info *mci, char *data)
{
return sprintf(data, "%d\n", mci->ue_noinfo_count);
}
static ssize_t mci_seconds_show(struct mem_ctl_info *mci, char *data)
{
return sprintf(data, "%ld\n", (jiffies - mci->start_time) / HZ);
}
static ssize_t mci_ctl_name_show(struct mem_ctl_info *mci, char *data)
{
return sprintf(data, "%s\n", mci->ctl_name);
}
static ssize_t mci_size_mb_show(struct mem_ctl_info *mci, char *data)
{
int total_pages, csrow_idx;
for (total_pages = csrow_idx = 0; csrow_idx < mci->nr_csrows;
csrow_idx++) {
struct csrow_info *csrow = &mci->csrows[csrow_idx];
if (!csrow->nr_pages)
continue;
total_pages += csrow->nr_pages;
}
return sprintf(data, "%u\n", PAGES_TO_MiB(total_pages));
}
static ssize_t mcidev_show(struct kobject *kobj, struct attribute *attr,
char *buffer)
{
struct mem_ctl_info *mem_ctl_info = to_mci(kobj);
struct mcidev_sysfs_attribute *mcidev_attr = to_mcidev_attr(attr);
debugf1("%s() mem_ctl_info %p\n", __func__, mem_ctl_info);
if (mcidev_attr->show)
return mcidev_attr->show(mem_ctl_info, buffer);
return -EIO;
}
static ssize_t mcidev_store(struct kobject *kobj, struct attribute *attr,
const char *buffer, size_t count)
{
struct mem_ctl_info *mem_ctl_info = to_mci(kobj);
struct mcidev_sysfs_attribute *mcidev_attr = to_mcidev_attr(attr);
debugf1("%s() mem_ctl_info %p\n", __func__, mem_ctl_info);
if (mcidev_attr->store)
return mcidev_attr->store(mem_ctl_info, buffer, count);
return -EIO;
}
static void edac_mci_control_release(struct kobject *kobj)
{
struct mem_ctl_info *mci;
mci = to_mci(kobj);
debugf0("%s() mci instance idx=%d releasing\n", __func__, mci->mc_idx);
module_put(mci->owner);
}
int edac_mc_register_sysfs_main_kobj(struct mem_ctl_info *mci)
{
struct kobject *kobj_mci;
int err;
debugf1("%s()\n", __func__);
kobj_mci = &mci->edac_mci_kobj;
memset(kobj_mci, 0, sizeof(*kobj_mci));
mci->owner = THIS_MODULE;
if (!try_module_get(mci->owner)) {
err = -ENODEV;
goto fail_out;
}
kobj_mci->kset = mc_kset;
err = kobject_init_and_add(kobj_mci, &ktype_mci, NULL,
"mc%d", mci->mc_idx);
if (err) {
debugf1("%s()Failed to register '.../edac/mc%d'\n",
__func__, mci->mc_idx);
goto kobj_reg_fail;
}
kobject_uevent(kobj_mci, KOBJ_ADD);
debugf1("%s() Registered '.../edac/mc%d' kobject\n",
__func__, mci->mc_idx);
return 0;
kobj_reg_fail:
module_put(mci->owner);
fail_out:
return err;
}
void edac_mc_unregister_sysfs_main_kobj(struct mem_ctl_info *mci)
{
debugf1("%s()\n", __func__);
kobject_put(&mci->edac_mci_kobj);
}
static ssize_t inst_grp_show(struct kobject *kobj, struct attribute *attr,
char *buffer)
{
struct mem_ctl_info *mem_ctl_info = grp_to_mci(kobj);
struct mcidev_sysfs_attribute *mcidev_attr = to_mcidev_attr(attr);
debugf1("%s() mem_ctl_info %p\n", __func__, mem_ctl_info);
if (mcidev_attr->show)
return mcidev_attr->show(mem_ctl_info, buffer);
return -EIO;
}
static ssize_t inst_grp_store(struct kobject *kobj, struct attribute *attr,
const char *buffer, size_t count)
{
struct mem_ctl_info *mem_ctl_info = grp_to_mci(kobj);
struct mcidev_sysfs_attribute *mcidev_attr = to_mcidev_attr(attr);
debugf1("%s() mem_ctl_info %p\n", __func__, mem_ctl_info);
if (mcidev_attr->store)
return mcidev_attr->store(mem_ctl_info, buffer, count);
return -EIO;
}
static void edac_inst_grp_release(struct kobject *kobj)
{
struct mcidev_sysfs_group_kobj *grp;
struct mem_ctl_info *mci;
debugf1("%s()\n", __func__);
grp = container_of(kobj, struct mcidev_sysfs_group_kobj, kobj);
mci = grp->mci;
}
static int edac_create_mci_instance_attributes(struct mem_ctl_info *mci,
const struct mcidev_sysfs_attribute *sysfs_attrib,
struct kobject *kobj)
{
int err;
debugf4("%s()\n", __func__);
while (sysfs_attrib) {
debugf4("%s() sysfs_attrib = %p\n",__func__, sysfs_attrib);
if (sysfs_attrib->grp) {
struct mcidev_sysfs_group_kobj *grp_kobj;
grp_kobj = kzalloc(sizeof(*grp_kobj), GFP_KERNEL);
if (!grp_kobj)
return -ENOMEM;
grp_kobj->grp = sysfs_attrib->grp;
grp_kobj->mci = mci;
list_add_tail(&grp_kobj->list, &mci->grp_kobj_list);
debugf0("%s() grp %s, mci %p\n", __func__,
sysfs_attrib->grp->name, mci);
err = kobject_init_and_add(&grp_kobj->kobj,
&ktype_inst_grp,
&mci->edac_mci_kobj,
sysfs_attrib->grp->name);
if (err < 0) {
printk(KERN_ERR "kobject_init_and_add failed: %d\n", err);
return err;
}
err = edac_create_mci_instance_attributes(mci,
grp_kobj->grp->mcidev_attr,
&grp_kobj->kobj);
if (err < 0)
return err;
} else if (sysfs_attrib->attr.name) {
debugf4("%s() file %s\n", __func__,
sysfs_attrib->attr.name);
err = sysfs_create_file(kobj, &sysfs_attrib->attr);
if (err < 0) {
printk(KERN_ERR "sysfs_create_file failed: %d\n", err);
return err;
}
} else
break;
sysfs_attrib++;
}
return 0;
}
static void edac_remove_mci_instance_attributes(struct mem_ctl_info *mci,
const struct mcidev_sysfs_attribute *sysfs_attrib,
struct kobject *kobj, int count)
{
struct mcidev_sysfs_group_kobj *grp_kobj, *tmp;
debugf1("%s()\n", __func__);
while (sysfs_attrib) {
debugf4("%s() sysfs_attrib = %p\n",__func__, sysfs_attrib);
if (sysfs_attrib->grp) {
debugf4("%s() seeking for group %s\n",
__func__, sysfs_attrib->grp->name);
list_for_each_entry(grp_kobj,
&mci->grp_kobj_list, list) {
debugf4("%s() grp_kobj->grp = %p\n",__func__, grp_kobj->grp);
if (grp_kobj->grp == sysfs_attrib->grp) {
edac_remove_mci_instance_attributes(mci,
grp_kobj->grp->mcidev_attr,
&grp_kobj->kobj, count + 1);
debugf4("%s() group %s\n", __func__,
sysfs_attrib->grp->name);
kobject_put(&grp_kobj->kobj);
}
}
debugf4("%s() end of seeking for group %s\n",
__func__, sysfs_attrib->grp->name);
} else if (sysfs_attrib->attr.name) {
debugf4("%s() file %s\n", __func__,
sysfs_attrib->attr.name);
sysfs_remove_file(kobj, &sysfs_attrib->attr);
} else
break;
sysfs_attrib++;
}
if (count)
return;
list_for_each_entry_safe(grp_kobj, tmp,
&mci->grp_kobj_list, list) {
list_del(&grp_kobj->list);
kfree(grp_kobj);
}
}
int edac_create_sysfs_mci_device(struct mem_ctl_info *mci)
{
int i;
int err;
struct csrow_info *csrow;
struct kobject *kobj_mci = &mci->edac_mci_kobj;
debugf0("%s() idx=%d\n", __func__, mci->mc_idx);
INIT_LIST_HEAD(&mci->grp_kobj_list);
err = sysfs_create_link(kobj_mci, &mci->dev->kobj,
EDAC_DEVICE_SYMLINK);
if (err) {
debugf1("%s() failure to create symlink\n", __func__);
goto fail0;
}
if (mci->mc_driver_sysfs_attributes) {
err = edac_create_mci_instance_attributes(mci,
mci->mc_driver_sysfs_attributes,
&mci->edac_mci_kobj);
if (err) {
debugf1("%s() failure to create mci attributes\n",
__func__);
goto fail0;
}
}
for (i = 0; i < mci->nr_csrows; i++) {
csrow = &mci->csrows[i];
if (csrow->nr_pages > 0) {
err = edac_create_csrow_object(mci, csrow, i);
if (err) {
debugf1("%s() failure: create csrow %d obj\n",
__func__, i);
goto fail1;
}
}
}
return 0;
fail1:
for (i--; i >= 0; i--) {
if (csrow->nr_pages > 0) {
kobject_put(&mci->csrows[i].kobj);
}
}
edac_remove_mci_instance_attributes(mci,
mci->mc_driver_sysfs_attributes, &mci->edac_mci_kobj, 0);
sysfs_remove_link(kobj_mci, EDAC_DEVICE_SYMLINK);
fail0:
return err;
}
void edac_remove_sysfs_mci_device(struct mem_ctl_info *mci)
{
int i;
debugf0("%s()\n", __func__);
debugf4("%s() unregister this mci kobj\n", __func__);
for (i = 0; i < mci->nr_csrows; i++) {
if (mci->csrows[i].nr_pages > 0) {
debugf0("%s() unreg csrow-%d\n", __func__, i);
kobject_put(&mci->csrows[i].kobj);
}
}
if (mci->mc_driver_sysfs_attributes) {
debugf4("%s() unregister mci private attributes\n", __func__);
edac_remove_mci_instance_attributes(mci,
mci->mc_driver_sysfs_attributes,
&mci->edac_mci_kobj, 0);
}
debugf4("%s() remove_link\n", __func__);
sysfs_remove_link(&mci->edac_mci_kobj, EDAC_DEVICE_SYMLINK);
debugf4("%s() remove_mci_instance\n", __func__);
kobject_put(&mci->edac_mci_kobj);
}
int edac_sysfs_setup_mc_kset(void)
{
int err = -EINVAL;
struct sysdev_class *edac_class;
debugf1("%s()\n", __func__);
edac_class = edac_get_sysfs_class();
if (edac_class == NULL) {
debugf1("%s() no edac_class error=%d\n", __func__, err);
goto fail_out;
}
mc_kset = kset_create_and_add("mc", NULL, &edac_class->kset.kobj);
if (!mc_kset) {
err = -ENOMEM;
debugf1("%s() Failed to register '.../edac/mc'\n", __func__);
goto fail_kset;
}
debugf1("%s() Registered '.../edac/mc' kobject\n", __func__);
return 0;
fail_kset:
edac_put_sysfs_class();
fail_out:
return err;
}
void edac_sysfs_teardown_mc_kset(void)
{
kset_unregister(mc_kset);
edac_put_sysfs_class();
}
