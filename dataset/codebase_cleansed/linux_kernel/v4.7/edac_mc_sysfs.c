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
unsigned long l;
int ret;
if (!val)
return -EINVAL;
ret = kstrtoul(val, 0, &l);
if (ret)
return ret;
if (l < 1000)
return -EINVAL;
*((unsigned long *)kp->arg) = l;
edac_mc_reset_delay_period(l);
return 0;
}
static ssize_t csrow_ue_count_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct csrow_info *csrow = to_csrow(dev);
return sprintf(data, "%u\n", csrow->ue_count);
}
static ssize_t csrow_ce_count_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct csrow_info *csrow = to_csrow(dev);
return sprintf(data, "%u\n", csrow->ce_count);
}
static ssize_t csrow_size_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct csrow_info *csrow = to_csrow(dev);
int i;
u32 nr_pages = 0;
for (i = 0; i < csrow->nr_channels; i++)
nr_pages += csrow->channels[i]->dimm->nr_pages;
return sprintf(data, "%u\n", PAGES_TO_MiB(nr_pages));
}
static ssize_t csrow_mem_type_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct csrow_info *csrow = to_csrow(dev);
return sprintf(data, "%s\n", mem_types[csrow->channels[0]->dimm->mtype]);
}
static ssize_t csrow_dev_type_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct csrow_info *csrow = to_csrow(dev);
return sprintf(data, "%s\n", dev_types[csrow->channels[0]->dimm->dtype]);
}
static ssize_t csrow_edac_mode_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct csrow_info *csrow = to_csrow(dev);
return sprintf(data, "%s\n", edac_caps[csrow->channels[0]->dimm->edac_mode]);
}
static ssize_t channel_dimm_label_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct csrow_info *csrow = to_csrow(dev);
unsigned chan = to_channel(mattr);
struct rank_info *rank = csrow->channels[chan];
if (!rank->dimm->label[0])
return 0;
return snprintf(data, sizeof(rank->dimm->label) + 1, "%s\n",
rank->dimm->label);
}
static ssize_t channel_dimm_label_store(struct device *dev,
struct device_attribute *mattr,
const char *data, size_t count)
{
struct csrow_info *csrow = to_csrow(dev);
unsigned chan = to_channel(mattr);
struct rank_info *rank = csrow->channels[chan];
size_t copy_count = count;
if (count == 0)
return -EINVAL;
if (data[count - 1] == '\0' || data[count - 1] == '\n')
copy_count -= 1;
if (copy_count == 0 || copy_count >= sizeof(rank->dimm->label))
return -EINVAL;
strncpy(rank->dimm->label, data, copy_count);
rank->dimm->label[copy_count] = '\0';
return count;
}
static ssize_t channel_ce_count_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct csrow_info *csrow = to_csrow(dev);
unsigned chan = to_channel(mattr);
struct rank_info *rank = csrow->channels[chan];
return sprintf(data, "%u\n", rank->ce_count);
}
static void csrow_attr_release(struct device *dev)
{
struct csrow_info *csrow = container_of(dev, struct csrow_info, dev);
edac_dbg(1, "Releasing csrow device %s\n", dev_name(dev));
kfree(csrow);
}
static umode_t csrow_dev_is_visible(struct kobject *kobj,
struct attribute *attr, int idx)
{
struct device *dev = kobj_to_dev(kobj);
struct csrow_info *csrow = container_of(dev, struct csrow_info, dev);
if (idx >= csrow->nr_channels)
return 0;
if (!csrow->channels[idx]->dimm->nr_pages)
return 0;
return attr->mode;
}
static inline int nr_pages_per_csrow(struct csrow_info *csrow)
{
int chan, nr_pages = 0;
for (chan = 0; chan < csrow->nr_channels; chan++)
nr_pages += csrow->channels[chan]->dimm->nr_pages;
return nr_pages;
}
static int edac_create_csrow_object(struct mem_ctl_info *mci,
struct csrow_info *csrow, int index)
{
csrow->dev.type = &csrow_attr_type;
csrow->dev.bus = mci->bus;
csrow->dev.groups = csrow_dev_groups;
device_initialize(&csrow->dev);
csrow->dev.parent = &mci->dev;
csrow->mci = mci;
dev_set_name(&csrow->dev, "csrow%d", index);
dev_set_drvdata(&csrow->dev, csrow);
edac_dbg(0, "creating (virtual) csrow node %s\n",
dev_name(&csrow->dev));
return device_add(&csrow->dev);
}
static int edac_create_csrow_objects(struct mem_ctl_info *mci)
{
int err, i;
struct csrow_info *csrow;
for (i = 0; i < mci->nr_csrows; i++) {
csrow = mci->csrows[i];
if (!nr_pages_per_csrow(csrow))
continue;
err = edac_create_csrow_object(mci, mci->csrows[i], i);
if (err < 0) {
edac_dbg(1,
"failure: create csrow objects for csrow %d\n",
i);
goto error;
}
}
return 0;
error:
for (--i; i >= 0; i--) {
csrow = mci->csrows[i];
if (!nr_pages_per_csrow(csrow))
continue;
put_device(&mci->csrows[i]->dev);
}
return err;
}
static void edac_delete_csrow_objects(struct mem_ctl_info *mci)
{
int i;
struct csrow_info *csrow;
for (i = mci->nr_csrows - 1; i >= 0; i--) {
csrow = mci->csrows[i];
if (!nr_pages_per_csrow(csrow))
continue;
device_unregister(&mci->csrows[i]->dev);
}
}
static ssize_t dimmdev_location_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct dimm_info *dimm = to_dimm(dev);
return edac_dimm_info_location(dimm, data, PAGE_SIZE);
}
static ssize_t dimmdev_label_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct dimm_info *dimm = to_dimm(dev);
if (!dimm->label[0])
return 0;
return snprintf(data, sizeof(dimm->label) + 1, "%s\n", dimm->label);
}
static ssize_t dimmdev_label_store(struct device *dev,
struct device_attribute *mattr,
const char *data,
size_t count)
{
struct dimm_info *dimm = to_dimm(dev);
size_t copy_count = count;
if (count == 0)
return -EINVAL;
if (data[count - 1] == '\0' || data[count - 1] == '\n')
copy_count -= 1;
if (copy_count == 0 || copy_count >= sizeof(dimm->label))
return -EINVAL;
strncpy(dimm->label, data, copy_count);
dimm->label[copy_count] = '\0';
return count;
}
static ssize_t dimmdev_size_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct dimm_info *dimm = to_dimm(dev);
return sprintf(data, "%u\n", PAGES_TO_MiB(dimm->nr_pages));
}
static ssize_t dimmdev_mem_type_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct dimm_info *dimm = to_dimm(dev);
return sprintf(data, "%s\n", mem_types[dimm->mtype]);
}
static ssize_t dimmdev_dev_type_show(struct device *dev,
struct device_attribute *mattr, char *data)
{
struct dimm_info *dimm = to_dimm(dev);
return sprintf(data, "%s\n", dev_types[dimm->dtype]);
}
static ssize_t dimmdev_edac_mode_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct dimm_info *dimm = to_dimm(dev);
return sprintf(data, "%s\n", edac_caps[dimm->edac_mode]);
}
static void dimm_attr_release(struct device *dev)
{
struct dimm_info *dimm = container_of(dev, struct dimm_info, dev);
edac_dbg(1, "Releasing dimm device %s\n", dev_name(dev));
kfree(dimm);
}
static int edac_create_dimm_object(struct mem_ctl_info *mci,
struct dimm_info *dimm,
int index)
{
int err;
dimm->mci = mci;
dimm->dev.type = &dimm_attr_type;
dimm->dev.bus = mci->bus;
device_initialize(&dimm->dev);
dimm->dev.parent = &mci->dev;
if (mci->csbased)
dev_set_name(&dimm->dev, "rank%d", index);
else
dev_set_name(&dimm->dev, "dimm%d", index);
dev_set_drvdata(&dimm->dev, dimm);
pm_runtime_forbid(&mci->dev);
err = device_add(&dimm->dev);
edac_dbg(0, "creating rank/dimm device %s\n", dev_name(&dimm->dev));
return err;
}
static ssize_t mci_reset_counters_store(struct device *dev,
struct device_attribute *mattr,
const char *data, size_t count)
{
struct mem_ctl_info *mci = to_mci(dev);
int cnt, row, chan, i;
mci->ue_mc = 0;
mci->ce_mc = 0;
mci->ue_noinfo_count = 0;
mci->ce_noinfo_count = 0;
for (row = 0; row < mci->nr_csrows; row++) {
struct csrow_info *ri = mci->csrows[row];
ri->ue_count = 0;
ri->ce_count = 0;
for (chan = 0; chan < ri->nr_channels; chan++)
ri->channels[chan]->ce_count = 0;
}
cnt = 1;
for (i = 0; i < mci->n_layers; i++) {
cnt *= mci->layers[i].size;
memset(mci->ce_per_layer[i], 0, cnt * sizeof(u32));
memset(mci->ue_per_layer[i], 0, cnt * sizeof(u32));
}
mci->start_time = jiffies;
return count;
}
static ssize_t mci_sdram_scrub_rate_store(struct device *dev,
struct device_attribute *mattr,
const char *data, size_t count)
{
struct mem_ctl_info *mci = to_mci(dev);
unsigned long bandwidth = 0;
int new_bw = 0;
if (kstrtoul(data, 10, &bandwidth) < 0)
return -EINVAL;
new_bw = mci->set_sdram_scrub_rate(mci, bandwidth);
if (new_bw < 0) {
edac_printk(KERN_WARNING, EDAC_MC,
"Error setting scrub rate to: %lu\n", bandwidth);
return -EINVAL;
}
return count;
}
static ssize_t mci_sdram_scrub_rate_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
int bandwidth = 0;
bandwidth = mci->get_sdram_scrub_rate(mci);
if (bandwidth < 0) {
edac_printk(KERN_DEBUG, EDAC_MC, "Error reading scrub rate\n");
return bandwidth;
}
return sprintf(data, "%d\n", bandwidth);
}
static ssize_t mci_ue_count_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
return sprintf(data, "%d\n", mci->ue_mc);
}
static ssize_t mci_ce_count_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
return sprintf(data, "%d\n", mci->ce_mc);
}
static ssize_t mci_ce_noinfo_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
return sprintf(data, "%d\n", mci->ce_noinfo_count);
}
static ssize_t mci_ue_noinfo_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
return sprintf(data, "%d\n", mci->ue_noinfo_count);
}
static ssize_t mci_seconds_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
return sprintf(data, "%ld\n", (jiffies - mci->start_time) / HZ);
}
static ssize_t mci_ctl_name_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
return sprintf(data, "%s\n", mci->ctl_name);
}
static ssize_t mci_size_mb_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
int total_pages = 0, csrow_idx, j;
for (csrow_idx = 0; csrow_idx < mci->nr_csrows; csrow_idx++) {
struct csrow_info *csrow = mci->csrows[csrow_idx];
for (j = 0; j < csrow->nr_channels; j++) {
struct dimm_info *dimm = csrow->channels[j]->dimm;
total_pages += dimm->nr_pages;
}
}
return sprintf(data, "%u\n", PAGES_TO_MiB(total_pages));
}
static ssize_t mci_max_location_show(struct device *dev,
struct device_attribute *mattr,
char *data)
{
struct mem_ctl_info *mci = to_mci(dev);
int i;
char *p = data;
for (i = 0; i < mci->n_layers; i++) {
p += sprintf(p, "%s %d ",
edac_layer_name[mci->layers[i].type],
mci->layers[i].size - 1);
}
return p - data;
}
static umode_t mci_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int idx)
{
struct device *dev = kobj_to_dev(kobj);
struct mem_ctl_info *mci = to_mci(dev);
umode_t mode = 0;
if (attr != &dev_attr_sdram_scrub_rate.attr)
return attr->mode;
if (mci->get_sdram_scrub_rate)
mode |= S_IRUGO;
if (mci->set_sdram_scrub_rate)
mode |= S_IWUSR;
return mode;
}
static void mci_attr_release(struct device *dev)
{
struct mem_ctl_info *mci = container_of(dev, struct mem_ctl_info, dev);
edac_dbg(1, "Releasing csrow device %s\n", dev_name(dev));
kfree(mci);
}
int edac_create_sysfs_mci_device(struct mem_ctl_info *mci,
const struct attribute_group **groups)
{
char *name;
int i, err;
name = kasprintf(GFP_KERNEL, "mc%d", mci->mc_idx);
if (!name)
return -ENOMEM;
mci->bus->name = name;
edac_dbg(0, "creating bus %s\n", mci->bus->name);
err = bus_register(mci->bus);
if (err < 0) {
kfree(name);
return err;
}
mci->dev.type = &mci_attr_type;
device_initialize(&mci->dev);
mci->dev.parent = mci_pdev;
mci->dev.bus = mci->bus;
mci->dev.groups = groups;
dev_set_name(&mci->dev, "mc%d", mci->mc_idx);
dev_set_drvdata(&mci->dev, mci);
pm_runtime_forbid(&mci->dev);
edac_dbg(0, "creating device %s\n", dev_name(&mci->dev));
err = device_add(&mci->dev);
if (err < 0) {
edac_dbg(1, "failure: create device %s\n", dev_name(&mci->dev));
goto fail_unregister_bus;
}
for (i = 0; i < mci->tot_dimms; i++) {
struct dimm_info *dimm = mci->dimms[i];
if (!dimm->nr_pages)
continue;
#ifdef CONFIG_EDAC_DEBUG
edac_dbg(1, "creating dimm%d, located at ", i);
if (edac_debug_level >= 1) {
int lay;
for (lay = 0; lay < mci->n_layers; lay++)
printk(KERN_CONT "%s %d ",
edac_layer_name[mci->layers[lay].type],
dimm->location[lay]);
printk(KERN_CONT "\n");
}
#endif
err = edac_create_dimm_object(mci, dimm, i);
if (err) {
edac_dbg(1, "failure: create dimm %d obj\n", i);
goto fail_unregister_dimm;
}
}
#ifdef CONFIG_EDAC_LEGACY_SYSFS
err = edac_create_csrow_objects(mci);
if (err < 0)
goto fail_unregister_dimm;
#endif
edac_create_debugfs_nodes(mci);
return 0;
fail_unregister_dimm:
for (i--; i >= 0; i--) {
struct dimm_info *dimm = mci->dimms[i];
if (!dimm->nr_pages)
continue;
device_unregister(&dimm->dev);
}
device_unregister(&mci->dev);
fail_unregister_bus:
bus_unregister(mci->bus);
kfree(name);
return err;
}
void edac_remove_sysfs_mci_device(struct mem_ctl_info *mci)
{
int i;
edac_dbg(0, "\n");
#ifdef CONFIG_EDAC_DEBUG
edac_debugfs_remove_recursive(mci->debugfs);
#endif
#ifdef CONFIG_EDAC_LEGACY_SYSFS
edac_delete_csrow_objects(mci);
#endif
for (i = 0; i < mci->tot_dimms; i++) {
struct dimm_info *dimm = mci->dimms[i];
if (dimm->nr_pages == 0)
continue;
edac_dbg(0, "removing device %s\n", dev_name(&dimm->dev));
device_unregister(&dimm->dev);
}
}
void edac_unregister_sysfs(struct mem_ctl_info *mci)
{
struct bus_type *bus = mci->bus;
const char *name = mci->bus->name;
edac_dbg(1, "Unregistering device %s\n", dev_name(&mci->dev));
device_unregister(&mci->dev);
bus_unregister(bus);
kfree(name);
}
static void mc_attr_release(struct device *dev)
{
edac_dbg(1, "Releasing device %s\n", dev_name(dev));
kfree(dev);
}
int __init edac_mc_sysfs_init(void)
{
int err;
mci_pdev = kzalloc(sizeof(*mci_pdev), GFP_KERNEL);
if (!mci_pdev) {
err = -ENOMEM;
goto out;
}
mci_pdev->bus = edac_get_sysfs_subsys();
mci_pdev->type = &mc_attr_type;
device_initialize(mci_pdev);
dev_set_name(mci_pdev, "mc");
err = device_add(mci_pdev);
if (err < 0)
goto out_dev_free;
edac_dbg(0, "device %s created\n", dev_name(mci_pdev));
return 0;
out_dev_free:
kfree(mci_pdev);
out:
return err;
}
void edac_mc_sysfs_exit(void)
{
device_unregister(mci_pdev);
}
