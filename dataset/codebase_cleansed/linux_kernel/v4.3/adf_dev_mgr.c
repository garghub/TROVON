static int adf_get_vf_id(struct adf_accel_dev *vf)
{
return ((7 * (PCI_SLOT(accel_to_pci_dev(vf)->devfn) - 1)) +
PCI_FUNC(accel_to_pci_dev(vf)->devfn) +
(PCI_SLOT(accel_to_pci_dev(vf)->devfn) - 1));
}
static int adf_get_vf_num(struct adf_accel_dev *vf)
{
return (accel_to_pci_dev(vf)->bus->number << 8) | adf_get_vf_id(vf);
}
static struct vf_id_map *adf_find_vf(u32 bdf)
{
struct list_head *itr;
list_for_each(itr, &vfs_table) {
struct vf_id_map *ptr =
list_entry(itr, struct vf_id_map, list);
if (ptr->bdf == bdf)
return ptr;
}
return NULL;
}
static int adf_get_vf_real_id(u32 fake)
{
struct list_head *itr;
list_for_each(itr, &vfs_table) {
struct vf_id_map *ptr =
list_entry(itr, struct vf_id_map, list);
if (ptr->fake_id == fake)
return ptr->id;
}
return -1;
}
void adf_clean_vf_map(bool vf)
{
struct vf_id_map *map;
struct list_head *ptr, *tmp;
mutex_lock(&table_lock);
list_for_each_safe(ptr, tmp, &vfs_table) {
map = list_entry(ptr, struct vf_id_map, list);
if (map->bdf != -1)
num_devices--;
if (vf && map->bdf == -1)
continue;
list_del(ptr);
kfree(map);
}
mutex_unlock(&table_lock);
}
void adf_devmgr_update_class_index(struct adf_hw_device_data *hw_data)
{
struct adf_hw_device_class *class = hw_data->dev_class;
struct list_head *itr;
int i = 0;
list_for_each(itr, &accel_table) {
struct adf_accel_dev *ptr =
list_entry(itr, struct adf_accel_dev, list);
if (ptr->hw_device->dev_class == class)
ptr->hw_device->instance_id = i++;
if (i == class->instances)
break;
}
}
int adf_devmgr_add_dev(struct adf_accel_dev *accel_dev,
struct adf_accel_dev *pf)
{
struct list_head *itr;
int ret = 0;
if (num_devices == ADF_MAX_DEVICES) {
dev_err(&GET_DEV(accel_dev), "Only support up to %d devices\n",
ADF_MAX_DEVICES);
return -EFAULT;
}
mutex_lock(&table_lock);
atomic_set(&accel_dev->ref_count, 0);
if (!accel_dev->is_vf || (accel_dev->is_vf && !pf)) {
struct vf_id_map *map;
list_for_each(itr, &accel_table) {
struct adf_accel_dev *ptr =
list_entry(itr, struct adf_accel_dev, list);
if (ptr == accel_dev) {
ret = -EEXIST;
goto unlock;
}
}
list_add_tail(&accel_dev->list, &accel_table);
accel_dev->accel_id = num_devices++;
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map) {
ret = -ENOMEM;
goto unlock;
}
map->bdf = ~0;
map->id = accel_dev->accel_id;
map->fake_id = map->id;
map->attached = true;
list_add_tail(&map->list, &vfs_table);
} else if (accel_dev->is_vf && pf) {
struct adf_accel_vf_info *vf_info;
struct vf_id_map *map;
vf_info = pf->pf.vf_info + adf_get_vf_id(accel_dev);
map = adf_find_vf(adf_get_vf_num(accel_dev));
if (map) {
struct vf_id_map *next;
accel_dev->accel_id = map->id;
list_add_tail(&accel_dev->list, &accel_table);
map->fake_id++;
map->attached = true;
next = list_next_entry(map, list);
while (next && &next->list != &vfs_table) {
next->fake_id++;
next = list_next_entry(next, list);
}
ret = 0;
goto unlock;
}
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map) {
ret = -ENOMEM;
goto unlock;
}
accel_dev->accel_id = num_devices++;
list_add_tail(&accel_dev->list, &accel_table);
map->bdf = adf_get_vf_num(accel_dev);
map->id = accel_dev->accel_id;
map->fake_id = map->id;
map->attached = true;
list_add_tail(&map->list, &vfs_table);
}
unlock:
mutex_unlock(&table_lock);
return ret;
}
struct list_head *adf_devmgr_get_head(void)
{
return &accel_table;
}
void adf_devmgr_rm_dev(struct adf_accel_dev *accel_dev,
struct adf_accel_dev *pf)
{
mutex_lock(&table_lock);
if (!accel_dev->is_vf || (accel_dev->is_vf && !pf)) {
num_devices--;
} else if (accel_dev->is_vf && pf) {
struct vf_id_map *map, *next;
map = adf_find_vf(adf_get_vf_num(accel_dev));
if (!map) {
dev_err(&GET_DEV(accel_dev), "Failed to find VF map\n");
goto unlock;
}
map->fake_id--;
map->attached = false;
next = list_next_entry(map, list);
while (next && &next->list != &vfs_table) {
next->fake_id--;
next = list_next_entry(next, list);
}
}
unlock:
list_del(&accel_dev->list);
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
mutex_lock(&table_lock);
list_for_each(itr, &accel_table) {
struct adf_accel_dev *ptr =
list_entry(itr, struct adf_accel_dev, list);
if (ptr->accel_pci_dev.pci_dev == pci_dev) {
mutex_unlock(&table_lock);
return ptr;
}
}
mutex_unlock(&table_lock);
return NULL;
}
struct adf_accel_dev *adf_devmgr_get_dev_by_id(uint32_t id)
{
struct list_head *itr;
int real_id;
mutex_lock(&table_lock);
real_id = adf_get_vf_real_id(id);
if (real_id < 0)
goto unlock;
id = real_id;
list_for_each(itr, &accel_table) {
struct adf_accel_dev *ptr =
list_entry(itr, struct adf_accel_dev, list);
if (ptr->accel_id == id) {
mutex_unlock(&table_lock);
return ptr;
}
}
unlock:
mutex_unlock(&table_lock);
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
static int adf_get_num_dettached_vfs(void)
{
struct list_head *itr;
int vfs = 0;
mutex_lock(&table_lock);
list_for_each(itr, &vfs_table) {
struct vf_id_map *ptr =
list_entry(itr, struct vf_id_map, list);
if (ptr->bdf != ~0 && !ptr->attached)
vfs++;
}
mutex_unlock(&table_lock);
return vfs;
}
void adf_devmgr_get_num_dev(uint32_t *num)
{
*num = num_devices - adf_get_num_dettached_vfs();
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
