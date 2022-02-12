void et131x_hwaddr_init(struct et131x_adapter *adapter)
{
if (adapter->rom_addr[0] == 0x00 &&
adapter->rom_addr[1] == 0x00 &&
adapter->rom_addr[2] == 0x00 &&
adapter->rom_addr[3] == 0x00 &&
adapter->rom_addr[4] == 0x00 &&
adapter->rom_addr[5] == 0x00) {
get_random_bytes(&adapter->addr[5], 1);
memcpy(adapter->rom_addr,
adapter->addr, ETH_ALEN);
} else {
memcpy(adapter->addr,
adapter->rom_addr, ETH_ALEN);
}
}
static int et131x_pci_init(struct et131x_adapter *adapter,
struct pci_dev *pdev)
{
int i;
u8 max_payload;
u8 read_size_reg;
if (et131x_init_eeprom(adapter) < 0)
return -EIO;
if (pci_read_config_byte(pdev, ET1310_PCI_MAX_PYLD, &max_payload)) {
dev_err(&pdev->dev,
"Could not read PCI config space for Max Payload Size\n");
return -EIO;
}
max_payload &= 0x07;
if (max_payload < 2) {
static const u16 acknak[2] = { 0x76, 0xD0 };
static const u16 replay[2] = { 0x1E0, 0x2ED };
if (pci_write_config_word(pdev, ET1310_PCI_ACK_NACK,
acknak[max_payload])) {
dev_err(&pdev->dev,
"Could not write PCI config space for ACK/NAK\n");
return -EIO;
}
if (pci_write_config_word(pdev, ET1310_PCI_REPLAY,
replay[max_payload])) {
dev_err(&pdev->dev,
"Could not write PCI config space for Replay Timer\n");
return -EIO;
}
}
if (pci_write_config_byte(pdev, ET1310_PCI_L0L1LATENCY, 0x11)) {
dev_err(&pdev->dev,
"Could not write PCI config space for Latency Timers\n");
return -EIO;
}
if (pci_read_config_byte(pdev, 0x51, &read_size_reg)) {
dev_err(&pdev->dev,
"Could not read PCI config space for Max read size\n");
return -EIO;
}
read_size_reg &= 0x8f;
read_size_reg |= 0x40;
if (pci_write_config_byte(pdev, 0x51, read_size_reg)) {
dev_err(&pdev->dev,
"Could not write PCI config space for Max read size\n");
return -EIO;
}
if (!adapter->has_eeprom) {
et131x_hwaddr_init(adapter);
return 0;
}
for (i = 0; i < ETH_ALEN; i++) {
if (pci_read_config_byte(pdev, ET1310_PCI_MAC_ADDRESS + i,
adapter->rom_addr + i)) {
dev_err(&pdev->dev, "Could not read PCI config space for MAC address\n");
return -EIO;
}
}
memcpy(adapter->addr, adapter->rom_addr, ETH_ALEN);
return 0;
}
void et131x_error_timer_handler(unsigned long data)
{
struct et131x_adapter *etdev = (struct et131x_adapter *) data;
u32 pm_csr;
pm_csr = readl(&etdev->regs->global.pm_csr);
if ((pm_csr & ET_PM_PHY_SW_COMA) == 0)
UpdateMacStatHostCounters(etdev);
else
dev_err(&etdev->pdev->dev,
"No interrupts, in PHY coma, pm_csr = 0x%x\n", pm_csr);
if (!etdev->Bmsr.bits.link_status &&
etdev->RegistryPhyComa &&
etdev->boot_coma < 11) {
etdev->boot_coma++;
}
if (etdev->boot_coma == 10) {
if (!etdev->Bmsr.bits.link_status
&& etdev->RegistryPhyComa) {
if ((pm_csr & ET_PM_PHY_SW_COMA) == 0) {
et131x_enable_interrupts(etdev);
EnablePhyComa(etdev);
}
}
}
mod_timer(&etdev->ErrorTimer, jiffies +
TX_ERROR_PERIOD * HZ / 1000);
}
void et131x_link_detection_handler(unsigned long data)
{
struct et131x_adapter *etdev = (struct et131x_adapter *) data;
unsigned long flags;
if (etdev->MediaState == 0) {
spin_lock_irqsave(&etdev->Lock, flags);
etdev->MediaState = NETIF_STATUS_MEDIA_DISCONNECT;
etdev->Flags &= ~fMP_ADAPTER_LINK_DETECTION;
spin_unlock_irqrestore(&etdev->Lock, flags);
netif_carrier_off(etdev->netdev);
}
}
void ConfigGlobalRegs(struct et131x_adapter *etdev)
{
struct global_regs __iomem *regs = &etdev->regs->global;
writel(0, &regs->rxq_start_addr);
writel(INTERNAL_MEM_SIZE - 1, &regs->txq_end_addr);
if (etdev->RegistryJumboPacket < 2048) {
writel(PARM_RX_MEM_END_DEF, &regs->rxq_end_addr);
writel(PARM_RX_MEM_END_DEF + 1, &regs->txq_start_addr);
} else if (etdev->RegistryJumboPacket < 8192) {
writel(INTERNAL_MEM_RX_OFFSET, &regs->rxq_end_addr);
writel(INTERNAL_MEM_RX_OFFSET + 1, &regs->txq_start_addr);
} else {
writel(0x01b3, &regs->rxq_end_addr);
writel(0x01b4, &regs->txq_start_addr);
}
writel(0, &regs->loopback);
writel(0, &regs->msi_config);
writel(0, &regs->watchdog_timer);
}
int et131x_adapter_setup(struct et131x_adapter *etdev)
{
int status = 0;
ConfigGlobalRegs(etdev);
ConfigMACRegs1(etdev);
writel(ET_MMC_ENABLE, &etdev->regs->mmc.mmc_ctrl);
ConfigRxMacRegs(etdev);
ConfigTxMacRegs(etdev);
ConfigRxDmaRegs(etdev);
ConfigTxDmaRegs(etdev);
ConfigMacStatRegs(etdev);
status = et131x_xcvr_find(etdev);
if (status != 0)
dev_warn(&etdev->pdev->dev, "Could not find the xcvr\n");
ET1310_PhyInit(etdev);
ET1310_PhyReset(etdev);
ET1310_PhyPowerDown(etdev, 1);
if (etdev->pdev->device != ET131X_PCI_DEVICE_ID_FAST)
ET1310_PhyAdvertise1000BaseT(etdev, TRUEPHY_ADV_DUPLEX_FULL);
else
ET1310_PhyAdvertise1000BaseT(etdev, TRUEPHY_ADV_DUPLEX_NONE);
ET1310_PhyPowerDown(etdev, 0);
et131x_setphy_normal(etdev);
; return status;
}
void et131x_soft_reset(struct et131x_adapter *adapter)
{
writel(0xc00f0000, &adapter->regs->mac.cfg1);
writel(0x7F, &adapter->regs->global.sw_reset);
writel(0x000f0000, &adapter->regs->mac.cfg1);
writel(0x00000000, &adapter->regs->mac.cfg1);
}
void et131x_align_allocated_memory(struct et131x_adapter *adapter,
uint64_t *phys_addr,
uint64_t *offset, uint64_t mask)
{
uint64_t new_addr;
*offset = 0;
new_addr = *phys_addr & ~mask;
if (new_addr != *phys_addr) {
new_addr += mask + 1;
*offset = new_addr - *phys_addr;
*phys_addr = new_addr;
}
}
int et131x_adapter_memory_alloc(struct et131x_adapter *adapter)
{
int status;
status = et131x_tx_dma_memory_alloc(adapter);
if (status != 0) {
dev_err(&adapter->pdev->dev,
"et131x_tx_dma_memory_alloc FAILED\n");
return status;
}
status = et131x_rx_dma_memory_alloc(adapter);
if (status != 0) {
dev_err(&adapter->pdev->dev,
"et131x_rx_dma_memory_alloc FAILED\n");
et131x_tx_dma_memory_free(adapter);
return status;
}
status = et131x_init_recv(adapter);
if (status != 0) {
dev_err(&adapter->pdev->dev,
"et131x_init_recv FAILED\n");
et131x_tx_dma_memory_free(adapter);
et131x_rx_dma_memory_free(adapter);
}
return status;
}
void et131x_adapter_memory_free(struct et131x_adapter *adapter)
{
et131x_tx_dma_memory_free(adapter);
et131x_rx_dma_memory_free(adapter);
}
static struct et131x_adapter *et131x_adapter_init(struct net_device *netdev,
struct pci_dev *pdev)
{
static const u8 default_mac[] = { 0x00, 0x05, 0x3d, 0x00, 0x02, 0x00 };
static const u8 duplex[] = { 0, 1, 2, 1, 2, 2 };
static const u16 speed[] = { 0, 10, 10, 100, 100, 1000 };
struct et131x_adapter *etdev;
SET_NETDEV_DEV(netdev, &pdev->dev);
etdev = netdev_priv(netdev);
etdev->pdev = pci_dev_get(pdev);
etdev->netdev = netdev;
netdev->irq = pdev->irq;
netdev->base_addr = pci_resource_start(pdev, 0);
spin_lock_init(&etdev->Lock);
spin_lock_init(&etdev->TCBSendQLock);
spin_lock_init(&etdev->TCBReadyQLock);
spin_lock_init(&etdev->send_hw_lock);
spin_lock_init(&etdev->rcv_lock);
spin_lock_init(&etdev->RcvPendLock);
spin_lock_init(&etdev->FbrLock);
spin_lock_init(&etdev->PHYLock);
if (et131x_speed_set)
dev_info(&etdev->pdev->dev,
"Speed set manually to : %d\n", et131x_speed_set);
etdev->SpeedDuplex = et131x_speed_set;
etdev->RegistryJumboPacket = 1514;
memcpy(etdev->addr, default_mac, ETH_ALEN);
if (etdev->pdev->device == ET131X_PCI_DEVICE_ID_FAST &&
etdev->SpeedDuplex == 5)
etdev->SpeedDuplex = 4;
etdev->AiForceSpeed = speed[etdev->SpeedDuplex];
etdev->AiForceDpx = duplex[etdev->SpeedDuplex];
return etdev;
}
static int __devinit et131x_pci_setup(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int result = -EBUSY;
int pm_cap;
bool pci_using_dac;
struct net_device *netdev;
struct et131x_adapter *adapter;
if (pci_enable_device(pdev) != 0) {
dev_err(&pdev->dev,
"pci_enable_device() failed\n");
return -EIO;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
dev_err(&pdev->dev,
"Can't find PCI device's base address\n");
goto err_disable;
}
if (pci_request_regions(pdev, DRIVER_NAME)) {
dev_err(&pdev->dev,
"Can't get PCI resources\n");
goto err_disable;
}
pci_set_master(pdev);
pm_cap = pci_find_capability(pdev, PCI_CAP_ID_PM);
if (pm_cap == 0) {
dev_err(&pdev->dev,
"Cannot find Power Management capabilities\n");
result = -EIO;
goto err_release_res;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
pci_using_dac = true;
result = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (result != 0) {
dev_err(&pdev->dev,
"Unable to obtain 64 bit DMA for consistent allocations\n");
goto err_release_res;
}
} else if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
pci_using_dac = false;
} else {
dev_err(&pdev->dev,
"No usable DMA addressing method\n");
result = -EIO;
goto err_release_res;
}
netdev = et131x_device_alloc();
if (netdev == NULL) {
dev_err(&pdev->dev, "Couldn't alloc netdev struct\n");
result = -ENOMEM;
goto err_release_res;
}
adapter = et131x_adapter_init(netdev, pdev);
et131x_pci_init(adapter, pdev);
adapter->regs = pci_ioremap_bar(pdev, 0);
if (adapter->regs == NULL) {
dev_err(&pdev->dev, "Cannot map device registers\n");
result = -ENOMEM;
goto err_free_dev;
}
writel(ET_PMCSR_INIT, &adapter->regs->global.pm_csr);
et131x_soft_reset(adapter);
et131x_disable_interrupts(adapter);
result = et131x_adapter_memory_alloc(adapter);
if (result != 0) {
dev_err(&pdev->dev, "Could not alloc adapater memory (DMA)\n");
goto err_iounmap;
}
et131x_init_send(adapter);
INIT_WORK(&adapter->task, et131x_isr_handler);
memcpy(netdev->dev_addr, adapter->addr, ETH_ALEN);
et131x_adapter_setup(adapter);
init_timer(&adapter->ErrorTimer);
adapter->ErrorTimer.expires = jiffies + TX_ERROR_PERIOD * HZ / 1000;
adapter->ErrorTimer.function = et131x_error_timer_handler;
adapter->ErrorTimer.data = (unsigned long)adapter;
et131x_link_detection_handler((unsigned long)adapter);
adapter->boot_coma = 0;
result = register_netdev(netdev);
if (result != 0) {
dev_err(&pdev->dev, "register_netdev() failed\n");
goto err_mem_free;
}
pci_set_drvdata(pdev, netdev);
pci_save_state(adapter->pdev);
return result;
err_mem_free:
et131x_adapter_memory_free(adapter);
err_iounmap:
iounmap(adapter->regs);
err_free_dev:
pci_dev_put(pdev);
free_netdev(netdev);
err_release_res:
pci_release_regions(pdev);
err_disable:
pci_disable_device(pdev);
return result;
}
static void __devexit et131x_pci_remove(struct pci_dev *pdev)
{
struct net_device *netdev;
struct et131x_adapter *adapter;
netdev = pci_get_drvdata(pdev);
adapter = netdev_priv(netdev);
unregister_netdev(netdev);
et131x_adapter_memory_free(adapter);
iounmap(adapter->regs);
pci_dev_put(adapter->pdev);
free_netdev(netdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init et131x_init_module(void)
{
if (et131x_speed_set < PARM_SPEED_DUPLEX_MIN ||
et131x_speed_set > PARM_SPEED_DUPLEX_MAX) {
printk(KERN_WARNING "et131x: invalid speed setting ignored.\n");
et131x_speed_set = 0;
}
return pci_register_driver(&et131x_driver);
}
static void __exit et131x_cleanup_module(void)
{
pci_unregister_driver(&et131x_driver);
}
