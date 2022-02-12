static void _be_roce_dev_add(struct be_adapter *adapter)
{
struct be_dev_info dev_info;
int i, num_vec;
struct pci_dev *pdev = adapter->pdev;
if (!ocrdma_drv)
return;
if (pdev->device == OC_DEVICE_ID5) {
if (!msix_enabled(adapter))
return;
dev_info.dpp_unmapped_addr = pci_resource_start(pdev, 2);
dev_info.dpp_unmapped_len = pci_resource_len(pdev, 2);
} else {
dev_info.dpp_unmapped_addr = 0;
dev_info.dpp_unmapped_len = 0;
}
dev_info.pdev = adapter->pdev;
dev_info.db = adapter->db;
dev_info.unmapped_db = adapter->roce_db.io_addr;
dev_info.db_page_size = adapter->roce_db.size;
dev_info.db_total_size = adapter->roce_db.total_size;
dev_info.netdev = adapter->netdev;
memcpy(dev_info.mac_addr, adapter->netdev->dev_addr, ETH_ALEN);
dev_info.dev_family = adapter->sli_family;
if (msix_enabled(adapter)) {
num_vec = adapter->num_msix_vec + adapter->num_msix_roce_vec;
dev_info.intr_mode = BE_INTERRUPT_MODE_MSIX;
dev_info.msix.num_vectors = min(num_vec, MAX_ROCE_MSIX_VECTORS);
dev_info.msix.start_vector = adapter->num_evt_qs;
for (i = 0; i < dev_info.msix.num_vectors; i++) {
dev_info.msix.vector_list[i] =
adapter->msix_entries[i].vector;
}
} else {
dev_info.msix.num_vectors = 0;
dev_info.intr_mode = BE_INTERRUPT_MODE_INTX;
}
adapter->ocrdma_dev = ocrdma_drv->add(&dev_info);
}
void be_roce_dev_add(struct be_adapter *adapter)
{
if (be_roce_supported(adapter)) {
INIT_LIST_HEAD(&adapter->entry);
mutex_lock(&be_adapter_list_lock);
list_add_tail(&adapter->entry, &be_adapter_list);
_be_roce_dev_add(adapter);
mutex_unlock(&be_adapter_list_lock);
}
}
void _be_roce_dev_remove(struct be_adapter *adapter)
{
if (ocrdma_drv && ocrdma_drv->remove && adapter->ocrdma_dev)
ocrdma_drv->remove(adapter->ocrdma_dev);
adapter->ocrdma_dev = NULL;
}
void be_roce_dev_remove(struct be_adapter *adapter)
{
if (be_roce_supported(adapter)) {
mutex_lock(&be_adapter_list_lock);
_be_roce_dev_remove(adapter);
list_del(&adapter->entry);
mutex_unlock(&be_adapter_list_lock);
}
}
void _be_roce_dev_open(struct be_adapter *adapter)
{
if (ocrdma_drv && adapter->ocrdma_dev &&
ocrdma_drv->state_change_handler)
ocrdma_drv->state_change_handler(adapter->ocrdma_dev, 0);
}
void be_roce_dev_open(struct be_adapter *adapter)
{
if (be_roce_supported(adapter)) {
mutex_lock(&be_adapter_list_lock);
_be_roce_dev_open(adapter);
mutex_unlock(&be_adapter_list_lock);
}
}
void _be_roce_dev_close(struct be_adapter *adapter)
{
if (ocrdma_drv && adapter->ocrdma_dev &&
ocrdma_drv->state_change_handler)
ocrdma_drv->state_change_handler(adapter->ocrdma_dev, 1);
}
void be_roce_dev_close(struct be_adapter *adapter)
{
if (be_roce_supported(adapter)) {
mutex_lock(&be_adapter_list_lock);
_be_roce_dev_close(adapter);
mutex_unlock(&be_adapter_list_lock);
}
}
int be_roce_register_driver(struct ocrdma_driver *drv)
{
struct be_adapter *dev;
mutex_lock(&be_adapter_list_lock);
if (ocrdma_drv) {
mutex_unlock(&be_adapter_list_lock);
return -EINVAL;
}
ocrdma_drv = drv;
list_for_each_entry(dev, &be_adapter_list, entry) {
struct net_device *netdev;
_be_roce_dev_add(dev);
netdev = dev->netdev;
if (netif_running(netdev) && netif_oper_up(netdev))
_be_roce_dev_open(dev);
}
mutex_unlock(&be_adapter_list_lock);
return 0;
}
void be_roce_unregister_driver(struct ocrdma_driver *drv)
{
struct be_adapter *dev;
mutex_lock(&be_adapter_list_lock);
list_for_each_entry(dev, &be_adapter_list, entry) {
if (dev->ocrdma_dev)
_be_roce_dev_remove(dev);
}
ocrdma_drv = NULL;
mutex_unlock(&be_adapter_list_lock);
}
