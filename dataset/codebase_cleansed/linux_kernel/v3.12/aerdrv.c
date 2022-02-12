void pci_no_aer(void)
{
pcie_aer_disable = 1;
}
bool pci_aer_available(void)
{
return !pcie_aer_disable && pci_msi_enabled();
}
static int set_device_error_reporting(struct pci_dev *dev, void *data)
{
bool enable = *((bool *)data);
int type = pci_pcie_type(dev);
if ((type == PCI_EXP_TYPE_ROOT_PORT) ||
(type == PCI_EXP_TYPE_UPSTREAM) ||
(type == PCI_EXP_TYPE_DOWNSTREAM)) {
if (enable)
pci_enable_pcie_error_reporting(dev);
else
pci_disable_pcie_error_reporting(dev);
}
if (enable)
pcie_set_ecrc_checking(dev);
return 0;
}
static void set_downstream_devices_error_reporting(struct pci_dev *dev,
bool enable)
{
set_device_error_reporting(dev, &enable);
if (!dev->subordinate)
return;
pci_walk_bus(dev->subordinate, set_device_error_reporting, &enable);
}
static void aer_enable_rootport(struct aer_rpc *rpc)
{
struct pci_dev *pdev = rpc->rpd->port;
int aer_pos;
u16 reg16;
u32 reg32;
pcie_capability_read_word(pdev, PCI_EXP_DEVSTA, &reg16);
pcie_capability_write_word(pdev, PCI_EXP_DEVSTA, reg16);
pcie_capability_clear_word(pdev, PCI_EXP_RTCTL,
SYSTEM_ERROR_INTR_ON_MESG_MASK);
aer_pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_ERR);
pci_read_config_dword(pdev, aer_pos + PCI_ERR_ROOT_STATUS, &reg32);
pci_write_config_dword(pdev, aer_pos + PCI_ERR_ROOT_STATUS, reg32);
pci_read_config_dword(pdev, aer_pos + PCI_ERR_COR_STATUS, &reg32);
pci_write_config_dword(pdev, aer_pos + PCI_ERR_COR_STATUS, reg32);
pci_read_config_dword(pdev, aer_pos + PCI_ERR_UNCOR_STATUS, &reg32);
pci_write_config_dword(pdev, aer_pos + PCI_ERR_UNCOR_STATUS, reg32);
set_downstream_devices_error_reporting(pdev, true);
pci_read_config_dword(pdev, aer_pos + PCI_ERR_ROOT_COMMAND, &reg32);
reg32 |= ROOT_PORT_INTR_ON_MESG_MASK;
pci_write_config_dword(pdev, aer_pos + PCI_ERR_ROOT_COMMAND, reg32);
}
static void aer_disable_rootport(struct aer_rpc *rpc)
{
struct pci_dev *pdev = rpc->rpd->port;
u32 reg32;
int pos;
set_downstream_devices_error_reporting(pdev, false);
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_ERR);
pci_read_config_dword(pdev, pos + PCI_ERR_ROOT_COMMAND, &reg32);
reg32 &= ~ROOT_PORT_INTR_ON_MESG_MASK;
pci_write_config_dword(pdev, pos + PCI_ERR_ROOT_COMMAND, reg32);
pci_read_config_dword(pdev, pos + PCI_ERR_ROOT_STATUS, &reg32);
pci_write_config_dword(pdev, pos + PCI_ERR_ROOT_STATUS, reg32);
}
irqreturn_t aer_irq(int irq, void *context)
{
unsigned int status, id;
struct pcie_device *pdev = (struct pcie_device *)context;
struct aer_rpc *rpc = get_service_data(pdev);
int next_prod_idx;
unsigned long flags;
int pos;
pos = pci_find_ext_capability(pdev->port, PCI_EXT_CAP_ID_ERR);
spin_lock_irqsave(&rpc->e_lock, flags);
pci_read_config_dword(pdev->port, pos + PCI_ERR_ROOT_STATUS, &status);
if (!(status & (PCI_ERR_ROOT_UNCOR_RCV|PCI_ERR_ROOT_COR_RCV))) {
spin_unlock_irqrestore(&rpc->e_lock, flags);
return IRQ_NONE;
}
pci_read_config_dword(pdev->port, pos + PCI_ERR_ROOT_ERR_SRC, &id);
pci_write_config_dword(pdev->port, pos + PCI_ERR_ROOT_STATUS, status);
next_prod_idx = rpc->prod_idx + 1;
if (next_prod_idx == AER_ERROR_SOURCES_MAX)
next_prod_idx = 0;
if (next_prod_idx == rpc->cons_idx) {
spin_unlock_irqrestore(&rpc->e_lock, flags);
return IRQ_HANDLED;
}
rpc->e_sources[rpc->prod_idx].status = status;
rpc->e_sources[rpc->prod_idx].id = id;
rpc->prod_idx = next_prod_idx;
spin_unlock_irqrestore(&rpc->e_lock, flags);
schedule_work(&rpc->dpc_handler);
return IRQ_HANDLED;
}
static struct aer_rpc *aer_alloc_rpc(struct pcie_device *dev)
{
struct aer_rpc *rpc;
rpc = kzalloc(sizeof(struct aer_rpc), GFP_KERNEL);
if (!rpc)
return NULL;
spin_lock_init(&rpc->e_lock);
rpc->rpd = dev;
INIT_WORK(&rpc->dpc_handler, aer_isr);
mutex_init(&rpc->rpc_mutex);
init_waitqueue_head(&rpc->wait_release);
set_service_data(dev, rpc);
return rpc;
}
static void aer_remove(struct pcie_device *dev)
{
struct aer_rpc *rpc = get_service_data(dev);
if (rpc) {
if (rpc->isr)
free_irq(dev->irq, dev);
wait_event(rpc->wait_release, rpc->prod_idx == rpc->cons_idx);
aer_disable_rootport(rpc);
kfree(rpc);
set_service_data(dev, NULL);
}
}
static int aer_probe(struct pcie_device *dev)
{
int status;
struct aer_rpc *rpc;
struct device *device = &dev->device;
status = aer_init(dev);
if (status)
return status;
rpc = aer_alloc_rpc(dev);
if (!rpc) {
dev_printk(KERN_DEBUG, device, "alloc rpc failed\n");
aer_remove(dev);
return -ENOMEM;
}
status = request_irq(dev->irq, aer_irq, IRQF_SHARED, "aerdrv", dev);
if (status) {
dev_printk(KERN_DEBUG, device, "request IRQ failed\n");
aer_remove(dev);
return status;
}
rpc->isr = 1;
aer_enable_rootport(rpc);
return status;
}
static pci_ers_result_t aer_root_reset(struct pci_dev *dev)
{
u32 reg32;
int pos;
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
pci_read_config_dword(dev, pos + PCI_ERR_ROOT_COMMAND, &reg32);
reg32 &= ~ROOT_PORT_INTR_ON_MESG_MASK;
pci_write_config_dword(dev, pos + PCI_ERR_ROOT_COMMAND, reg32);
pci_reset_bridge_secondary_bus(dev);
dev_printk(KERN_DEBUG, &dev->dev, "Root Port link has been reset\n");
pci_read_config_dword(dev, pos + PCI_ERR_ROOT_STATUS, &reg32);
pci_write_config_dword(dev, pos + PCI_ERR_ROOT_STATUS, reg32);
pci_read_config_dword(dev, pos + PCI_ERR_ROOT_COMMAND, &reg32);
reg32 |= ROOT_PORT_INTR_ON_MESG_MASK;
pci_write_config_dword(dev, pos + PCI_ERR_ROOT_COMMAND, reg32);
return PCI_ERS_RESULT_RECOVERED;
}
static pci_ers_result_t aer_error_detected(struct pci_dev *dev,
enum pci_channel_state error)
{
return PCI_ERS_RESULT_CAN_RECOVER;
}
static void aer_error_resume(struct pci_dev *dev)
{
int pos;
u32 status, mask;
u16 reg16;
pcie_capability_read_word(dev, PCI_EXP_DEVSTA, &reg16);
pcie_capability_write_word(dev, PCI_EXP_DEVSTA, reg16);
pos = pci_find_ext_capability(dev, PCI_EXT_CAP_ID_ERR);
pci_read_config_dword(dev, pos + PCI_ERR_UNCOR_STATUS, &status);
pci_read_config_dword(dev, pos + PCI_ERR_UNCOR_SEVER, &mask);
if (dev->error_state == pci_channel_io_normal)
status &= ~mask;
else
status &= mask;
pci_write_config_dword(dev, pos + PCI_ERR_UNCOR_STATUS, status);
}
static int __init aer_service_init(void)
{
if (!pci_aer_available() || aer_acpi_firmware_first())
return -ENXIO;
return pcie_port_service_register(&aerdriver);
}
static void __exit aer_service_exit(void)
{
pcie_port_service_unregister(&aerdriver);
}
