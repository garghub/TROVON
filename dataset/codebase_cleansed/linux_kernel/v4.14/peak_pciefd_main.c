static inline int pciefd_irq_tag(u32 irq_status)
{
return irq_status & 0x0000000f;
}
static inline int pciefd_irq_rx_cnt(u32 irq_status)
{
return (irq_status & 0x000007f0) >> 4;
}
static inline int pciefd_irq_is_lnk(u32 irq_status)
{
return irq_status & 0x00010000;
}
static inline u32 pciefd_sys_readreg(const struct pciefd_board *priv, u16 reg)
{
return readl(priv->reg_base + reg);
}
static inline void pciefd_sys_writereg(const struct pciefd_board *priv,
u32 val, u16 reg)
{
writel(val, priv->reg_base + reg);
}
static inline u32 pciefd_can_readreg(const struct pciefd_can *priv, u16 reg)
{
return readl(priv->reg_base + reg);
}
static inline void pciefd_can_writereg(const struct pciefd_can *priv,
u32 val, u16 reg)
{
writel(val, priv->reg_base + reg);
}
static void pciefd_can_setup_rx_dma(struct pciefd_can *priv)
{
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
const u32 dma_addr_h = (u32)(priv->rx_dma_laddr >> 32);
#else
const u32 dma_addr_h = 0;
#endif
pciefd_can_writereg(priv, CANFD_CTL_RST_BIT, PCIEFD_REG_CAN_RX_CTL_SET);
pciefd_can_writereg(priv, (u32)priv->rx_dma_laddr,
PCIEFD_REG_CAN_RX_DMA_ADDR_L);
pciefd_can_writereg(priv, dma_addr_h, PCIEFD_REG_CAN_RX_DMA_ADDR_H);
pciefd_can_writereg(priv, CANFD_CTL_UNC_BIT, PCIEFD_REG_CAN_RX_CTL_CLR);
}
static void pciefd_can_clear_rx_dma(struct pciefd_can *priv)
{
pciefd_can_writereg(priv, CANFD_CTL_RST_BIT, PCIEFD_REG_CAN_RX_CTL_SET);
pciefd_can_writereg(priv, 0, PCIEFD_REG_CAN_RX_DMA_ADDR_L);
pciefd_can_writereg(priv, 0, PCIEFD_REG_CAN_RX_DMA_ADDR_H);
}
static void pciefd_can_setup_tx_dma(struct pciefd_can *priv)
{
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
const u32 dma_addr_h = (u32)(priv->tx_dma_laddr >> 32);
#else
const u32 dma_addr_h = 0;
#endif
pciefd_can_writereg(priv, CANFD_CTL_RST_BIT, PCIEFD_REG_CAN_TX_CTL_SET);
pciefd_can_writereg(priv, (u32)priv->tx_dma_laddr,
PCIEFD_REG_CAN_TX_DMA_ADDR_L);
pciefd_can_writereg(priv, dma_addr_h, PCIEFD_REG_CAN_TX_DMA_ADDR_H);
pciefd_can_writereg(priv, CANFD_CTL_UNC_BIT, PCIEFD_REG_CAN_TX_CTL_CLR);
}
static void pciefd_can_clear_tx_dma(struct pciefd_can *priv)
{
pciefd_can_writereg(priv, CANFD_CTL_RST_BIT, PCIEFD_REG_CAN_TX_CTL_SET);
pciefd_can_writereg(priv, 0, PCIEFD_REG_CAN_TX_DMA_ADDR_L);
pciefd_can_writereg(priv, 0, PCIEFD_REG_CAN_TX_DMA_ADDR_H);
}
static void pciefd_can_ack_rx_dma(struct pciefd_can *priv)
{
priv->irq_tag = le32_to_cpu(*(__le32 *)priv->rx_dma_vaddr);
priv->irq_tag++;
priv->irq_tag &= 0xf;
pciefd_can_writereg(priv, priv->irq_tag, PCIEFD_REG_CAN_RX_CTL_ACK);
}
static irqreturn_t pciefd_irq_handler(int irq, void *arg)
{
struct pciefd_can *priv = arg;
struct pciefd_rx_dma *rx_dma = priv->rx_dma_vaddr;
if (!pci_dev_msi_enabled(priv->board->pci_dev))
(void)pciefd_sys_readreg(priv->board, PCIEFD_REG_SYS_VER1);
priv->irq_status = le32_to_cpu(rx_dma->irq_status);
if (pciefd_irq_tag(priv->irq_status) != priv->irq_tag)
return IRQ_NONE;
peak_canfd_handle_msgs_list(&priv->ucan,
rx_dma->msg,
pciefd_irq_rx_cnt(priv->irq_status));
if (pciefd_irq_is_lnk(priv->irq_status)) {
unsigned long flags;
spin_lock_irqsave(&priv->tx_lock, flags);
priv->tx_pages_free++;
spin_unlock_irqrestore(&priv->tx_lock, flags);
netif_wake_queue(priv->ucan.ndev);
}
pciefd_can_ack_rx_dma(priv);
return IRQ_HANDLED;
}
static int pciefd_enable_tx_path(struct peak_canfd_priv *ucan)
{
struct pciefd_can *priv = (struct pciefd_can *)ucan;
int i;
priv->tx_pages_free = PCIEFD_TX_PAGE_COUNT - 1;
priv->tx_page_index = 0;
priv->tx_pages[0].vbase = priv->tx_dma_vaddr;
priv->tx_pages[0].lbase = priv->tx_dma_laddr;
for (i = 0; i < PCIEFD_TX_PAGE_COUNT; i++) {
priv->tx_pages[i].offset = 0;
priv->tx_pages[i].size = PCIEFD_TX_PAGE_SIZE -
sizeof(struct pciefd_tx_link);
if (i) {
priv->tx_pages[i].vbase =
priv->tx_pages[i - 1].vbase +
PCIEFD_TX_PAGE_SIZE;
priv->tx_pages[i].lbase =
priv->tx_pages[i - 1].lbase +
PCIEFD_TX_PAGE_SIZE;
}
}
pciefd_can_setup_tx_dma(priv);
pciefd_can_writereg(priv, CANFD_CTL_RST_BIT, PCIEFD_REG_CAN_TX_CTL_CLR);
return 0;
}
static int pciefd_pre_cmd(struct peak_canfd_priv *ucan)
{
struct pciefd_can *priv = (struct pciefd_can *)ucan;
u16 cmd = pucan_cmd_get_opcode(&priv->pucan_cmd);
int err;
switch (cmd) {
case PUCAN_CMD_NORMAL_MODE:
case PUCAN_CMD_LISTEN_ONLY_MODE:
if (ucan->can.state == CAN_STATE_BUS_OFF)
break;
err = request_irq(priv->board->pci_dev->irq,
pciefd_irq_handler,
IRQF_SHARED,
PCIEFD_DRV_NAME,
priv);
if (err)
return err;
pciefd_can_setup_rx_dma(priv);
pciefd_can_writereg(priv, (CANFD_CTL_IRQ_TL_DEF) << 8 |
CANFD_CTL_IRQ_CL_DEF,
PCIEFD_REG_CAN_RX_CTL_WRT);
pciefd_can_writereg(priv, CANFD_CTL_RST_BIT,
PCIEFD_REG_CAN_RX_CTL_CLR);
pciefd_can_writereg(priv, !CANFD_MISC_TS_RST,
PCIEFD_REG_CAN_MISC);
pciefd_can_ack_rx_dma(priv);
pciefd_can_writereg(priv, CANFD_CTL_IEN_BIT,
PCIEFD_REG_CAN_RX_CTL_SET);
break;
default:
break;
}
return 0;
}
static int pciefd_write_cmd(struct peak_canfd_priv *ucan)
{
struct pciefd_can *priv = (struct pciefd_can *)ucan;
unsigned long flags;
spin_lock_irqsave(&priv->board->cmd_lock, flags);
pciefd_can_writereg(priv, *(u32 *)ucan->cmd_buffer,
PCIEFD_REG_CAN_CMD_PORT_L);
pciefd_can_writereg(priv, *(u32 *)(ucan->cmd_buffer + 4),
PCIEFD_REG_CAN_CMD_PORT_H);
spin_unlock_irqrestore(&priv->board->cmd_lock, flags);
return 0;
}
static int pciefd_post_cmd(struct peak_canfd_priv *ucan)
{
struct pciefd_can *priv = (struct pciefd_can *)ucan;
u16 cmd = pucan_cmd_get_opcode(&priv->pucan_cmd);
switch (cmd) {
case PUCAN_CMD_RESET_MODE:
if (ucan->can.state == CAN_STATE_STOPPED)
break;
pciefd_can_clear_tx_dma(priv);
pciefd_can_clear_rx_dma(priv);
pciefd_can_writereg(priv, CANFD_CTL_IEN_BIT,
PCIEFD_REG_CAN_RX_CTL_CLR);
free_irq(priv->board->pci_dev->irq, priv);
ucan->can.state = CAN_STATE_STOPPED;
break;
}
return 0;
}
static void *pciefd_alloc_tx_msg(struct peak_canfd_priv *ucan, u16 msg_size,
int *room_left)
{
struct pciefd_can *priv = (struct pciefd_can *)ucan;
struct pciefd_page *page = priv->tx_pages + priv->tx_page_index;
unsigned long flags;
void *msg;
spin_lock_irqsave(&priv->tx_lock, flags);
if (page->offset + msg_size > page->size) {
struct pciefd_tx_link *lk;
if (!priv->tx_pages_free) {
spin_unlock_irqrestore(&priv->tx_lock, flags);
return NULL;
}
priv->tx_pages_free--;
lk = page->vbase + page->offset;
priv->tx_page_index = (priv->tx_page_index + 1) %
PCIEFD_TX_PAGE_COUNT;
page = priv->tx_pages + priv->tx_page_index;
lk->size = cpu_to_le16(sizeof(*lk));
lk->type = cpu_to_le16(CANFD_MSG_LNK_TX);
lk->laddr_lo = cpu_to_le32(page->lbase);
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
lk->laddr_hi = cpu_to_le32(page->lbase >> 32);
#else
lk->laddr_hi = 0;
#endif
page->offset = 0;
}
*room_left = priv->tx_pages_free * page->size;
spin_unlock_irqrestore(&priv->tx_lock, flags);
msg = page->vbase + page->offset;
*room_left += page->size - (page->offset + msg_size);
return msg;
}
static int pciefd_write_tx_msg(struct peak_canfd_priv *ucan,
struct pucan_tx_msg *msg)
{
struct pciefd_can *priv = (struct pciefd_can *)ucan;
struct pciefd_page *page = priv->tx_pages + priv->tx_page_index;
page->offset += le16_to_cpu(msg->size);
pciefd_can_writereg(priv, 1, PCIEFD_REG_CAN_TX_REQ_ACC);
return 0;
}
static int pciefd_can_probe(struct pciefd_board *pciefd)
{
struct net_device *ndev;
struct pciefd_can *priv;
u32 clk;
int err;
ndev = alloc_peak_canfd_dev(sizeof(*priv), pciefd->can_count,
PCIEFD_ECHO_SKB_MAX);
if (!ndev) {
dev_err(&pciefd->pci_dev->dev,
"failed to alloc candev object\n");
goto failure;
}
priv = netdev_priv(ndev);
priv->ucan.pre_cmd = pciefd_pre_cmd;
priv->ucan.write_cmd = pciefd_write_cmd;
priv->ucan.post_cmd = pciefd_post_cmd;
priv->ucan.enable_tx_path = pciefd_enable_tx_path;
priv->ucan.alloc_tx_msg = pciefd_alloc_tx_msg;
priv->ucan.write_tx_msg = pciefd_write_tx_msg;
priv->ucan.cmd_buffer = &priv->pucan_cmd;
priv->ucan.cmd_maxlen = sizeof(priv->pucan_cmd);
priv->board = pciefd;
priv->reg_base = pciefd->reg_base + PCIEFD_CANX_OFF(priv->ucan.index);
priv->rx_dma_vaddr = dmam_alloc_coherent(&pciefd->pci_dev->dev,
PCIEFD_RX_DMA_SIZE,
&priv->rx_dma_laddr,
GFP_KERNEL);
if (!priv->rx_dma_vaddr) {
dev_err(&pciefd->pci_dev->dev,
"Rx dmam_alloc_coherent(%u) failure\n",
PCIEFD_RX_DMA_SIZE);
goto err_free_candev;
}
priv->tx_dma_vaddr = dmam_alloc_coherent(&pciefd->pci_dev->dev,
PCIEFD_TX_DMA_SIZE,
&priv->tx_dma_laddr,
GFP_KERNEL);
if (!priv->tx_dma_vaddr) {
dev_err(&pciefd->pci_dev->dev,
"Tx dmaim_alloc_coherent(%u) failure\n",
PCIEFD_TX_DMA_SIZE);
goto err_free_candev;
}
pciefd_can_writereg(priv, CANFD_MISC_TS_RST, PCIEFD_REG_CAN_MISC);
clk = pciefd_can_readreg(priv, PCIEFD_REG_CAN_CLK_SEL);
switch (clk) {
case CANFD_CLK_SEL_20MHZ:
priv->ucan.can.clock.freq = 20 * 1000 * 1000;
break;
case CANFD_CLK_SEL_24MHZ:
priv->ucan.can.clock.freq = 24 * 1000 * 1000;
break;
case CANFD_CLK_SEL_30MHZ:
priv->ucan.can.clock.freq = 30 * 1000 * 1000;
break;
case CANFD_CLK_SEL_40MHZ:
priv->ucan.can.clock.freq = 40 * 1000 * 1000;
break;
case CANFD_CLK_SEL_60MHZ:
priv->ucan.can.clock.freq = 60 * 1000 * 1000;
break;
default:
pciefd_can_writereg(priv, CANFD_CLK_SEL_80MHZ,
PCIEFD_REG_CAN_CLK_SEL);
case CANFD_CLK_SEL_80MHZ:
priv->ucan.can.clock.freq = 80 * 1000 * 1000;
break;
}
ndev->irq = pciefd->pci_dev->irq;
SET_NETDEV_DEV(ndev, &pciefd->pci_dev->dev);
err = register_candev(ndev);
if (err) {
dev_err(&pciefd->pci_dev->dev,
"couldn't register CAN device: %d\n", err);
goto err_free_candev;
}
spin_lock_init(&priv->tx_lock);
pciefd->can[pciefd->can_count] = priv;
dev_info(&pciefd->pci_dev->dev, "%s at reg_base=0x%p irq=%d\n",
ndev->name, priv->reg_base, pciefd->pci_dev->irq);
return 0;
err_free_candev:
free_candev(ndev);
failure:
return -ENOMEM;
}
static void pciefd_can_remove(struct pciefd_can *priv)
{
unregister_candev(priv->ucan.ndev);
free_candev(priv->ucan.ndev);
}
static void pciefd_can_remove_all(struct pciefd_board *pciefd)
{
while (pciefd->can_count > 0)
pciefd_can_remove(pciefd->can[--pciefd->can_count]);
}
static int peak_pciefd_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct pciefd_board *pciefd;
int err, can_count;
u16 sub_sys_id;
u8 hw_ver_major;
u8 hw_ver_minor;
u8 hw_ver_sub;
u32 v2;
err = pci_enable_device(pdev);
if (err)
return err;
err = pci_request_regions(pdev, PCIEFD_DRV_NAME);
if (err)
goto err_disable_pci;
err = pci_read_config_word(pdev, PCI_SUBSYSTEM_ID, &sub_sys_id);
if (err)
goto err_release_regions;
dev_dbg(&pdev->dev, "probing device %04x:%04x:%04x\n",
pdev->vendor, pdev->device, sub_sys_id);
if (sub_sys_id >= 0x0012)
can_count = 4;
else if (sub_sys_id >= 0x0010)
can_count = 3;
else if (sub_sys_id >= 0x0004)
can_count = 2;
else
can_count = 1;
pciefd = devm_kzalloc(&pdev->dev, sizeof(*pciefd) +
can_count * sizeof(*pciefd->can),
GFP_KERNEL);
if (!pciefd) {
err = -ENOMEM;
goto err_release_regions;
}
pciefd->pci_dev = pdev;
spin_lock_init(&pciefd->cmd_lock);
pciefd->reg_base = pci_iomap(pdev, 0, PCIEFD_BAR0_SIZE);
if (!pciefd->reg_base) {
dev_err(&pdev->dev, "failed to map PCI resource #0\n");
err = -ENOMEM;
goto err_release_regions;
}
v2 = pciefd_sys_readreg(pciefd, PCIEFD_REG_SYS_VER2);
hw_ver_major = (v2 & 0x0000f000) >> 12;
hw_ver_minor = (v2 & 0x00000f00) >> 8;
hw_ver_sub = (v2 & 0x000000f0) >> 4;
dev_info(&pdev->dev,
"%ux CAN-FD PCAN-PCIe FPGA v%u.%u.%u:\n", can_count,
hw_ver_major, hw_ver_minor, hw_ver_sub);
pciefd_sys_writereg(pciefd, PCIEFD_SYS_CTL_CLK_EN,
PCIEFD_REG_SYS_CTL_CLR);
pci_set_master(pdev);
while (pciefd->can_count < can_count) {
err = pciefd_can_probe(pciefd);
if (err)
goto err_free_canfd;
pciefd->can_count++;
}
pciefd_sys_writereg(pciefd, PCIEFD_SYS_CTL_TS_RST,
PCIEFD_REG_SYS_CTL_SET);
(void)pciefd_sys_readreg(pciefd, PCIEFD_REG_SYS_VER1);
pciefd_sys_writereg(pciefd, PCIEFD_SYS_CTL_TS_RST,
PCIEFD_REG_SYS_CTL_CLR);
pciefd_sys_writereg(pciefd, PCIEFD_SYS_CTL_CLK_EN,
PCIEFD_REG_SYS_CTL_SET);
pci_set_drvdata(pdev, pciefd);
return 0;
err_free_canfd:
pciefd_can_remove_all(pciefd);
pci_iounmap(pdev, pciefd->reg_base);
err_release_regions:
pci_release_regions(pdev);
err_disable_pci:
pci_disable_device(pdev);
return err;
}
static void peak_pciefd_remove(struct pci_dev *pdev)
{
struct pciefd_board *pciefd = pci_get_drvdata(pdev);
pciefd_can_remove_all(pciefd);
pci_iounmap(pdev, pciefd->reg_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
