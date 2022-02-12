int adf_devmgr_add_dev(struct adf_accel_dev *accel_dev)
{
struct list_head *itr;
if (num_devices == ADF_MAX_DEVICES) {
pr_err("QAT: Only support up to %d devices\n", ADF_MAX_DEVICES);
return -EFAULT;
}
mutex_lock(&table_lock);
list_for_each(itr, &accel_table) {
struct adf_accel_dev *ptr =
list_entry(itr, struct adf_accel_dev, list);
if (ptr == accel_dev) {
mutex_unlock(&table_lock);
return -EEXIST;
}
}
atomic_set(&accel_dev->ref_count, 0);
list_add_tail(&accel_dev->list, &accel_table);
accel_dev->accel_id = num_devices++;
mutex_unlock(&table_lock);
return 0;
}
struct list_head *adf_devmgr_get_head(void)
{
return &accel_table;
}
void adf_devmgr_rm_dev(struct adf_accel_dev *accel_dev)
{
mutex_lock(&table_lock);
list_del(&accel_dev->list);
num_devices--;
mutex_unlock(&table_lock);
}
struct adf_accel_dev *adf_devmgr_get_first(void)
{
struct adf_accel_dev *dev = NULL;
if (!list_empty(&accel_table))
dev = list_first_entry(&accel_table, struct adf_accel_dev,
list);
return dev;
}
struct adf_accel_dev *adf_devmgr_pci_to_accel_dev(struct pci_dev *pci_dev)
{
struct list_head *itr;
list_for_each(itr, &accel_table) {
struct adf_accel_dev *ptr =
list_entry(itr, struct adf_accel_dev, list);
if (ptr->accel_pci_dev.pci_dev == pci_dev) {
mutex_unlock(&table_lock);
return ptr;
}
}
return NULL;
}
struct adf_accel_dev *adf_devmgr_get_dev_by_id(uint32_t id)
{
struct list_head *itr;
list_for_each(itr, &accel_table) {
struct adf_accel_dev *ptr =
list_entry(itr, struct adf_accel_dev, list);
if (ptr->accel_id == id) {
mutex_unlock(&table_lock);
return ptr;
}
}
return NULL;
}
int adf_devmgr_verify_id(uint32_t id)
{
if (id == ADF_CFG_ALL_DEVICES)
return 0;
if (adf_devmgr_get_dev_by_id(id))
return 0;
return -ENODEV;
}
void adf_devmgr_get_num_dev(uint32_t *num)
{
struct list_head *itr;
*num = 0;
list_for_each(itr, &accel_table) {
(*num)++;
}
}
int adf_dev_in_use(struct adf_accel_dev *accel_dev)
{
return atomic_read(&accel_dev->ref_count) != 0;
}
int adf_dev_get(struct adf_accel_dev *accel_dev)
{
if (atomic_add_return(1, &accel_dev->ref_count) == 1)
if (!try_module_get(accel_dev->owner))
return -EFAULT;
return 0;
}
void adf_dev_put(struct adf_accel_dev *accel_dev)
{
if (atomic_sub_return(1, &accel_dev->ref_count) == 0)
module_put(accel_dev->owner);
}
int adf_devmgr_in_reset(struct adf_accel_dev *accel_dev)
{
return test_bit(ADF_STATUS_RESTARTING, &accel_dev->status);
}
int adf_dev_started(struct adf_accel_dev *accel_dev)
{
return test_bit(ADF_STATUS_STARTED, &accel_dev->status);
}
