static int
isl_upload_firmware(islpci_private *priv)
{
u32 reg, rc;
void __iomem *device_base = priv->device_base;
reg = readl(device_base + ISL38XX_CTRL_STAT_REG);
reg &= ~ISL38XX_CTRL_STAT_RESET;
reg &= ~ISL38XX_CTRL_STAT_RAMBOOT;
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
udelay(ISL38XX_WRITEIO_DELAY);
reg |= ISL38XX_CTRL_STAT_RESET;
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
udelay(ISL38XX_WRITEIO_DELAY);
reg &= ~ISL38XX_CTRL_STAT_RESET;
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
mdelay(50);
{
const struct firmware *fw_entry = NULL;
long fw_len;
const u32 *fw_ptr;
rc = request_firmware(&fw_entry, priv->firmware, PRISM_FW_PDEV);
if (rc) {
printk(KERN_ERR
"%s: request_firmware() failed for '%s'\n",
"prism54", priv->firmware);
return rc;
}
reg = ISL38XX_DEV_FIRMWARE_ADDRES;
fw_ptr = (u32 *) fw_entry->data;
fw_len = fw_entry->size;
if (fw_len % 4) {
printk(KERN_ERR
"%s: firmware '%s' size is not multiple of 32bit, aborting!\n",
"prism54", priv->firmware);
release_firmware(fw_entry);
return -EILSEQ; ;
}
while (fw_len > 0) {
long _fw_len =
(fw_len >
ISL38XX_MEMORY_WINDOW_SIZE) ?
ISL38XX_MEMORY_WINDOW_SIZE : fw_len;
u32 __iomem *dev_fw_ptr = device_base + ISL38XX_DIRECT_MEM_WIN;
isl38xx_w32_flush(device_base, reg,
ISL38XX_DIR_MEM_BASE_REG);
wmb();
reg += _fw_len;
fw_len -= _fw_len;
while (_fw_len > 0) {
__raw_writel(*fw_ptr, dev_fw_ptr);
fw_ptr++, dev_fw_ptr++;
_fw_len -= 4;
}
(void) readl(device_base + ISL38XX_PCI_POSTING_FLUSH);
wmb();
BUG_ON(_fw_len != 0);
}
BUG_ON(fw_len != 0);
printk(KERN_DEBUG "%s: firmware version: %.8s\n",
priv->ndev->name, fw_entry->data + 40);
release_firmware(fw_entry);
}
reg = readl(device_base + ISL38XX_CTRL_STAT_REG);
reg &= ~ISL38XX_CTRL_STAT_CLKRUN;
reg &= ~ISL38XX_CTRL_STAT_RESET;
reg |= ISL38XX_CTRL_STAT_RAMBOOT;
isl38xx_w32_flush(device_base, reg, ISL38XX_CTRL_STAT_REG);
wmb();
udelay(ISL38XX_WRITEIO_DELAY);
reg |= ISL38XX_CTRL_STAT_RESET;
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
udelay(ISL38XX_WRITEIO_DELAY);
reg &= ~ISL38XX_CTRL_STAT_RESET;
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
udelay(ISL38XX_WRITEIO_DELAY);
return 0;
}
irqreturn_t
islpci_interrupt(int irq, void *config)
{
u32 reg;
islpci_private *priv = config;
struct net_device *ndev = priv->ndev;
void __iomem *device = priv->device_base;
int powerstate = ISL38XX_PSM_POWERSAVE_STATE;
spin_lock(&priv->slock);
reg = readl(device + ISL38XX_CTRL_STAT_REG);
if (reg & ISL38XX_CTRL_STAT_SLEEPMODE)
{
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "Assuming someone else called the IRQ\n");
#endif
spin_unlock(&priv->slock);
return IRQ_NONE;
}
reg = readl(device + ISL38XX_INT_IDENT_REG);
reg &= readl(device + ISL38XX_INT_EN_REG);
reg &= ISL38XX_INT_SOURCES;
if (reg != 0) {
if (islpci_get_state(priv) != PRV_STATE_SLEEP)
powerstate = ISL38XX_PSM_ACTIVE_STATE;
isl38xx_w32_flush(device, reg, ISL38XX_INT_ACK_REG);
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_FUNCTION_CALLS,
"IRQ: Identification register 0x%p 0x%x\n", device, reg);
#endif
if (reg & ISL38XX_INT_IDENT_UPDATE) {
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "IRQ: Update flag\n");
DEBUG(SHOW_QUEUE_INDEXES,
"CB drv Qs: [%i][%i][%i][%i][%i][%i]\n",
le32_to_cpu(priv->control_block->
driver_curr_frag[0]),
le32_to_cpu(priv->control_block->
driver_curr_frag[1]),
le32_to_cpu(priv->control_block->
driver_curr_frag[2]),
le32_to_cpu(priv->control_block->
driver_curr_frag[3]),
le32_to_cpu(priv->control_block->
driver_curr_frag[4]),
le32_to_cpu(priv->control_block->
driver_curr_frag[5])
);
DEBUG(SHOW_QUEUE_INDEXES,
"CB dev Qs: [%i][%i][%i][%i][%i][%i]\n",
le32_to_cpu(priv->control_block->
device_curr_frag[0]),
le32_to_cpu(priv->control_block->
device_curr_frag[1]),
le32_to_cpu(priv->control_block->
device_curr_frag[2]),
le32_to_cpu(priv->control_block->
device_curr_frag[3]),
le32_to_cpu(priv->control_block->
device_curr_frag[4]),
le32_to_cpu(priv->control_block->
device_curr_frag[5])
);
#endif
islpci_eth_cleanup_transmit(priv, priv->control_block);
powerstate = ISL38XX_PSM_ACTIVE_STATE;
if (isl38xx_in_queue(priv->control_block,
ISL38XX_CB_RX_MGMTQ) != 0) {
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING,
"Received frame in Management Queue\n");
#endif
islpci_mgt_receive(ndev);
islpci_mgt_cleanup_transmit(ndev);
islpci_mgmt_rx_fill(ndev);
}
while (isl38xx_in_queue(priv->control_block,
ISL38XX_CB_RX_DATA_LQ) != 0) {
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING,
"Received frame in Data Low Queue\n");
#endif
islpci_eth_receive(priv);
}
if (priv->data_low_tx_full) {
if (ISL38XX_CB_TX_QSIZE -
isl38xx_in_queue(priv->control_block,
ISL38XX_CB_TX_DATA_LQ) >=
ISL38XX_MIN_QTHRESHOLD) {
netif_wake_queue(priv->ndev);
priv->data_low_tx_full = 0;
}
}
}
if (reg & ISL38XX_INT_IDENT_INIT) {
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING,
"IRQ: Init flag, device initialized\n");
#endif
wake_up(&priv->reset_done);
}
if (reg & ISL38XX_INT_IDENT_SLEEP) {
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "IRQ: Sleep flag\n");
#endif
isl38xx_handle_sleep_request(priv->control_block,
&powerstate,
priv->device_base);
}
if (reg & ISL38XX_INT_IDENT_WAKEUP) {
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "IRQ: Wakeup flag\n");
#endif
isl38xx_handle_wakeup(priv->control_block,
&powerstate, priv->device_base);
}
} else {
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "Assuming someone else called the IRQ\n");
#endif
spin_unlock(&priv->slock);
return IRQ_NONE;
}
if (islpci_get_state(priv) == PRV_STATE_SLEEP
&& powerstate == ISL38XX_PSM_ACTIVE_STATE)
islpci_set_state(priv, PRV_STATE_READY);
if (islpci_get_state(priv) != PRV_STATE_SLEEP
&& powerstate == ISL38XX_PSM_POWERSAVE_STATE)
islpci_set_state(priv, PRV_STATE_SLEEP);
spin_unlock(&priv->slock);
return IRQ_HANDLED;
}
static int
islpci_open(struct net_device *ndev)
{
u32 rc;
islpci_private *priv = netdev_priv(ndev);
rc = islpci_reset(priv,1);
if (rc) {
prism54_bring_down(priv);
return rc;
}
netif_start_queue(ndev);
if (priv->iw_mode == IW_MODE_INFRA || priv->iw_mode == IW_MODE_ADHOC)
netif_carrier_off(ndev);
else
netif_carrier_on(ndev);
return 0;
}
static int
islpci_close(struct net_device *ndev)
{
islpci_private *priv = netdev_priv(ndev);
printk(KERN_DEBUG "%s: islpci_close ()\n", ndev->name);
netif_stop_queue(ndev);
return prism54_bring_down(priv);
}
static int
prism54_bring_down(islpci_private *priv)
{
void __iomem *device_base = priv->device_base;
u32 reg;
islpci_set_state(priv, PRV_STATE_PREBOOT);
isl38xx_disable_interrupts(priv->device_base);
synchronize_irq(priv->pdev->irq);
reg = readl(device_base + ISL38XX_CTRL_STAT_REG);
reg &= ~(ISL38XX_CTRL_STAT_RESET | ISL38XX_CTRL_STAT_RAMBOOT);
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
udelay(ISL38XX_WRITEIO_DELAY);
reg |= ISL38XX_CTRL_STAT_RESET;
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
udelay(ISL38XX_WRITEIO_DELAY);
reg &= ~ISL38XX_CTRL_STAT_RESET;
writel(reg, device_base + ISL38XX_CTRL_STAT_REG);
wmb();
schedule_timeout_uninterruptible(msecs_to_jiffies(50));
return 0;
}
static int
islpci_upload_fw(islpci_private *priv)
{
islpci_state_t old_state;
u32 rc;
old_state = islpci_set_state(priv, PRV_STATE_BOOT);
printk(KERN_DEBUG "%s: uploading firmware...\n", priv->ndev->name);
rc = isl_upload_firmware(priv);
if (rc) {
printk(KERN_ERR "%s: could not upload firmware ('%s')\n",
priv->ndev->name, priv->firmware);
islpci_set_state(priv, old_state);
return rc;
}
printk(KERN_DEBUG "%s: firmware upload complete\n",
priv->ndev->name);
islpci_set_state(priv, PRV_STATE_POSTBOOT);
return 0;
}
static int
islpci_reset_if(islpci_private *priv)
{
long remaining;
int result = -ETIME;
int count;
DEFINE_WAIT(wait);
prepare_to_wait(&priv->reset_done, &wait, TASK_UNINTERRUPTIBLE);
isl38xx_interface_reset(priv->device_base, priv->device_host_address);
islpci_set_state(priv, PRV_STATE_PREINIT);
for(count = 0; count < 2 && result; count++) {
remaining = schedule_timeout_uninterruptible(HZ);
if(remaining > 0) {
result = 0;
break;
}
printk(KERN_ERR "%s: no 'reset complete' IRQ seen - retrying\n",
priv->ndev->name);
}
finish_wait(&priv->reset_done, &wait);
if (result) {
printk(KERN_ERR "%s: interface reset failure\n", priv->ndev->name);
return result;
}
islpci_set_state(priv, PRV_STATE_INIT);
isl38xx_enable_common_interrupts(priv->device_base);
down_write(&priv->mib_sem);
result = mgt_commit(priv);
if (result) {
printk(KERN_ERR "%s: interface reset failure\n", priv->ndev->name);
up_write(&priv->mib_sem);
return result;
}
up_write(&priv->mib_sem);
islpci_set_state(priv, PRV_STATE_READY);
printk(KERN_DEBUG "%s: interface reset complete\n", priv->ndev->name);
return 0;
}
int
islpci_reset(islpci_private *priv, int reload_firmware)
{
isl38xx_control_block *cb =
(isl38xx_control_block *) priv->control_block;
unsigned counter;
int rc;
if (reload_firmware)
islpci_set_state(priv, PRV_STATE_PREBOOT);
else
islpci_set_state(priv, PRV_STATE_POSTBOOT);
printk(KERN_DEBUG "%s: resetting device...\n", priv->ndev->name);
isl38xx_disable_interrupts(priv->device_base);
priv->index_mgmt_tx = 0;
priv->index_mgmt_rx = 0;
for (counter = 0; counter < ISL38XX_CB_QCOUNT; counter++) {
cb->driver_curr_frag[counter] = cpu_to_le32(0);
cb->device_curr_frag[counter] = cpu_to_le32(0);
}
for (counter = 0; counter < ISL38XX_CB_MGMT_QSIZE; counter++) {
isl38xx_fragment *frag = &cb->rx_data_mgmt[counter];
frag->size = cpu_to_le16(MGMT_FRAME_SIZE);
frag->flags = 0;
frag->address = cpu_to_le32(priv->mgmt_rx[counter].pci_addr);
}
for (counter = 0; counter < ISL38XX_CB_RX_QSIZE; counter++) {
cb->rx_data_low[counter].address =
cpu_to_le32((u32) priv->pci_map_rx_address[counter]);
}
priv->control_block->driver_curr_frag[ISL38XX_CB_RX_DATA_LQ] =
cpu_to_le32(ISL38XX_CB_RX_QSIZE);
priv->control_block->driver_curr_frag[ISL38XX_CB_RX_MGMTQ] =
cpu_to_le32(ISL38XX_CB_MGMT_QSIZE);
priv->free_data_rx = 0;
priv->free_data_tx = 0;
priv->data_low_tx_full = 0;
if (reload_firmware) {
rc = islpci_upload_fw(priv);
if (rc) {
printk(KERN_ERR "%s: islpci_reset: failure\n",
priv->ndev->name);
return rc;
}
}
rc = islpci_reset_if(priv);
if (rc)
printk(KERN_ERR "prism54: Your card/socket may be faulty, or IRQ line too busy :(\n");
return rc;
}
static int
islpci_alloc_memory(islpci_private *priv)
{
int counter;
#if VERBOSE > SHOW_ERROR_MESSAGES
printk(KERN_DEBUG "islpci_alloc_memory\n");
#endif
if (!(priv->device_base =
ioremap(pci_resource_start(priv->pdev, 0),
ISL38XX_PCI_MEM_SIZE))) {
printk(KERN_ERR "PCI memory remapping failed\n");
return -1;
}
priv->driver_mem_address = pci_alloc_consistent(priv->pdev,
HOST_MEM_BLOCK,
&priv->
device_host_address);
if (!priv->driver_mem_address) {
printk(KERN_ERR "%s: could not allocate DMA memory, aborting!",
"prism54");
return -1;
}
priv->control_block =
(isl38xx_control_block *) priv->driver_mem_address;
priv->device_psm_buffer =
priv->device_host_address + CONTROL_BLOCK_SIZE;
for (counter = 0; counter < ISL38XX_CB_QCOUNT; counter++) {
priv->control_block->driver_curr_frag[counter] = cpu_to_le32(0);
priv->control_block->device_curr_frag[counter] = cpu_to_le32(0);
}
priv->index_mgmt_rx = 0;
memset(priv->mgmt_rx, 0, sizeof(priv->mgmt_rx));
memset(priv->mgmt_tx, 0, sizeof(priv->mgmt_tx));
if (islpci_mgmt_rx_fill(priv->ndev) < 0)
goto out_free;
memset(priv->data_low_rx, 0, sizeof (priv->data_low_rx));
memset(priv->pci_map_rx_address, 0, sizeof (priv->pci_map_rx_address));
for (counter = 0; counter < ISL38XX_CB_RX_QSIZE; counter++) {
struct sk_buff *skb;
if (!(skb = dev_alloc_skb(MAX_FRAGMENT_SIZE_RX + 2))) {
printk(KERN_ERR "Error allocating skb.\n");
skb = NULL;
goto out_free;
}
skb_reserve(skb, (4 - (long) skb->data) & 0x03);
priv->data_low_rx[counter] = skb;
priv->pci_map_rx_address[counter] =
pci_map_single(priv->pdev, (void *) skb->data,
MAX_FRAGMENT_SIZE_RX + 2,
PCI_DMA_FROMDEVICE);
if (!priv->pci_map_rx_address[counter]) {
printk(KERN_ERR "failed to map skb DMA'able\n");
goto out_free;
}
}
prism54_acl_init(&priv->acl);
prism54_wpa_bss_ie_init(priv);
if (mgt_init(priv))
goto out_free;
return 0;
out_free:
islpci_free_memory(priv);
return -1;
}
int
islpci_free_memory(islpci_private *priv)
{
int counter;
if (priv->device_base)
iounmap(priv->device_base);
priv->device_base = NULL;
if (priv->driver_mem_address)
pci_free_consistent(priv->pdev, HOST_MEM_BLOCK,
priv->driver_mem_address,
priv->device_host_address);
priv->driver_mem_address = NULL;
priv->device_host_address = 0;
priv->device_psm_buffer = 0;
priv->control_block = NULL;
for (counter = 0; counter < ISL38XX_CB_MGMT_QSIZE; counter++) {
struct islpci_membuf *buf = &priv->mgmt_rx[counter];
if (buf->pci_addr)
pci_unmap_single(priv->pdev, buf->pci_addr,
buf->size, PCI_DMA_FROMDEVICE);
buf->pci_addr = 0;
kfree(buf->mem);
buf->size = 0;
buf->mem = NULL;
}
for (counter = 0; counter < ISL38XX_CB_RX_QSIZE; counter++) {
if (priv->pci_map_rx_address[counter])
pci_unmap_single(priv->pdev,
priv->pci_map_rx_address[counter],
MAX_FRAGMENT_SIZE_RX + 2,
PCI_DMA_FROMDEVICE);
priv->pci_map_rx_address[counter] = 0;
if (priv->data_low_rx[counter])
dev_kfree_skb(priv->data_low_rx[counter]);
priv->data_low_rx[counter] = NULL;
}
prism54_acl_clean(&priv->acl);
prism54_wpa_bss_ie_clean(priv);
mgt_clean(priv);
return 0;
}
static void islpci_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
}
struct net_device *
islpci_setup(struct pci_dev *pdev)
{
islpci_private *priv;
struct net_device *ndev = alloc_etherdev(sizeof (islpci_private));
if (!ndev)
return ndev;
pci_set_drvdata(pdev, ndev);
SET_NETDEV_DEV(ndev, &pdev->dev);
SET_NETDEV_DEVTYPE(ndev, &wlan_type);
ndev->base_addr = pci_resource_start(pdev, 0);
ndev->irq = pdev->irq;
ndev->netdev_ops = &islpci_netdev_ops;
ndev->wireless_handlers = &prism54_handler_def;
ndev->ethtool_ops = &islpci_ethtool_ops;
ndev->addr_len = ETH_ALEN;
memcpy(ndev->dev_addr, dummy_mac, ETH_ALEN);
ndev->watchdog_timeo = ISLPCI_TX_TIMEOUT;
priv = netdev_priv(ndev);
priv->ndev = ndev;
priv->pdev = pdev;
priv->monitor_type = ARPHRD_IEEE80211;
priv->ndev->type = (priv->iw_mode == IW_MODE_MONITOR) ?
priv->monitor_type : ARPHRD_ETHER;
priv->wireless_data.spy_data = &priv->spy_data;
ndev->wireless_data = &priv->wireless_data;
ndev->mem_start = (unsigned long) priv->device_base;
ndev->mem_end = ndev->mem_start + ISL38XX_PCI_MEM_SIZE;
#if VERBOSE > SHOW_ERROR_MESSAGES
DEBUG(SHOW_TRACING, "PCI Memory remapped to 0x%p\n", priv->device_base);
#endif
init_waitqueue_head(&priv->reset_done);
mutex_init(&priv->mgmt_lock);
priv->mgmt_received = NULL;
init_waitqueue_head(&priv->mgmt_wqueue);
mutex_init(&priv->stats_lock);
spin_lock_init(&priv->slock);
priv->state = PRV_STATE_OFF;
priv->state_off = 1;
INIT_WORK(&priv->stats_work, prism54_update_stats);
priv->stats_timestamp = 0;
INIT_WORK(&priv->reset_task, islpci_do_reset_and_wake);
priv->reset_task_pending = 0;
if (islpci_alloc_memory(priv))
goto do_free_netdev;
switch (pdev->device) {
case 0x3877:
strcpy(priv->firmware, ISL3877_IMAGE_FILE);
break;
case 0x3886:
strcpy(priv->firmware, ISL3886_IMAGE_FILE);
break;
default:
strcpy(priv->firmware, ISL3890_IMAGE_FILE);
break;
}
if (register_netdev(ndev)) {
DEBUG(SHOW_ERROR_MESSAGES,
"ERROR: register_netdev() failed\n");
goto do_islpci_free_memory;
}
return ndev;
do_islpci_free_memory:
islpci_free_memory(priv);
do_free_netdev:
pci_set_drvdata(pdev, NULL);
free_netdev(ndev);
priv = NULL;
return NULL;
}
islpci_state_t
islpci_set_state(islpci_private *priv, islpci_state_t new_state)
{
islpci_state_t old_state;
old_state = priv->state;
switch (new_state) {
case PRV_STATE_OFF:
priv->state_off++;
default:
priv->state = new_state;
break;
case PRV_STATE_PREBOOT:
if (old_state == PRV_STATE_OFF)
priv->state_off--;
if (!priv->state_off)
priv->state = new_state;
break;
}
#if 0
printk(KERN_DEBUG "%s: state transition %d -> %d (off#%d)\n",
priv->ndev->name, old_state, new_state, priv->state_off);
#endif
BUG_ON(priv->state_off < 0);
BUG_ON(priv->state_off && (priv->state != PRV_STATE_OFF));
BUG_ON(!priv->state_off && (priv->state == PRV_STATE_OFF));
return old_state;
}
