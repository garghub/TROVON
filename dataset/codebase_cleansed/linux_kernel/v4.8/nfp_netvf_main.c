static void nfp_netvf_get_mac_addr(struct nfp_net *nn)
{
u8 mac_addr[ETH_ALEN];
put_unaligned_be32(nn_readl(nn, NFP_NET_CFG_MACADDR + 0), &mac_addr[0]);
put_unaligned_be16(nn_readl(nn, NFP_NET_CFG_MACADDR + 4) >> 16,
&mac_addr[4]);
if (!is_valid_ether_addr(mac_addr)) {
eth_hw_addr_random(nn->netdev);
return;
}
ether_addr_copy(nn->netdev->dev_addr, mac_addr);
ether_addr_copy(nn->netdev->perm_addr, mac_addr);
}
static int nfp_netvf_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *pci_id)
{
struct nfp_net_fw_version fw_ver;
int max_tx_rings, max_rx_rings;
u32 tx_bar_off, rx_bar_off;
u32 tx_bar_sz, rx_bar_sz;
int tx_bar_no, rx_bar_no;
u8 __iomem *ctrl_bar;
struct nfp_net *nn;
int is_nfp3200;
u32 startq;
int stride;
int err;
err = pci_enable_device_mem(pdev);
if (err)
return err;
err = pci_request_regions(pdev, nfp_net_driver_name);
if (err) {
dev_err(&pdev->dev, "Unable to allocate device memory.\n");
goto err_pci_disable;
}
switch (pdev->device) {
case PCI_DEVICE_NFP6000VF:
is_nfp3200 = 0;
break;
default:
err = -ENODEV;
goto err_pci_regions;
}
pci_set_master(pdev);
err = dma_set_mask_and_coherent(&pdev->dev,
DMA_BIT_MASK(NFP_NET_MAX_DMA_BITS));
if (err)
goto err_pci_regions;
ctrl_bar = ioremap_nocache(pci_resource_start(pdev, NFP_NET_CTRL_BAR),
NFP_NET_CFG_BAR_SZ);
if (!ctrl_bar) {
dev_err(&pdev->dev,
"Failed to map resource %d\n", NFP_NET_CTRL_BAR);
err = -EIO;
goto err_pci_regions;
}
nfp_net_get_fw_version(&fw_ver, ctrl_bar);
if (fw_ver.resv || fw_ver.class != NFP_NET_CFG_VERSION_CLASS_GENERIC) {
dev_err(&pdev->dev, "Unknown Firmware ABI %d.%d.%d.%d\n",
fw_ver.resv, fw_ver.class, fw_ver.major, fw_ver.minor);
err = -EINVAL;
goto err_ctrl_unmap;
}
if (nfp_net_fw_ver_eq(&fw_ver, 0, 0, 0, 1)) {
stride = 2;
tx_bar_no = NFP_NET_Q0_BAR;
rx_bar_no = NFP_NET_Q1_BAR;
dev_warn(&pdev->dev, "OBSOLETE Firmware detected - VF isolation not available\n");
} else {
switch (fw_ver.major) {
case 1 ... 3:
if (is_nfp3200) {
stride = 2;
tx_bar_no = NFP_NET_Q0_BAR;
rx_bar_no = NFP_NET_Q1_BAR;
} else {
stride = 4;
tx_bar_no = NFP_NET_Q0_BAR;
rx_bar_no = tx_bar_no;
}
break;
default:
dev_err(&pdev->dev, "Unsupported Firmware ABI %d.%d.%d.%d\n",
fw_ver.resv, fw_ver.class,
fw_ver.major, fw_ver.minor);
err = -EINVAL;
goto err_ctrl_unmap;
}
}
max_tx_rings = readl(ctrl_bar + NFP_NET_CFG_MAX_TXRINGS);
max_rx_rings = readl(ctrl_bar + NFP_NET_CFG_MAX_RXRINGS);
tx_bar_sz = NFP_QCP_QUEUE_ADDR_SZ * max_tx_rings * stride;
rx_bar_sz = NFP_QCP_QUEUE_ADDR_SZ * max_rx_rings * stride;
if (tx_bar_sz > pci_resource_len(pdev, tx_bar_no)) {
dev_err(&pdev->dev,
"TX BAR too small for number of TX rings. Adjusting\n");
tx_bar_sz = pci_resource_len(pdev, tx_bar_no);
max_tx_rings = (tx_bar_sz / NFP_QCP_QUEUE_ADDR_SZ) / 2;
}
if (rx_bar_sz > pci_resource_len(pdev, rx_bar_no)) {
dev_err(&pdev->dev,
"RX BAR too small for number of RX rings. Adjusting\n");
rx_bar_sz = pci_resource_len(pdev, rx_bar_no);
max_rx_rings = (rx_bar_sz / NFP_QCP_QUEUE_ADDR_SZ) / 2;
}
switch (pdev->device) {
case PCI_DEVICE_NFP6000VF:
startq = readl(ctrl_bar + NFP_NET_CFG_START_TXQ);
tx_bar_off = NFP_PCIE_QUEUE(startq);
startq = readl(ctrl_bar + NFP_NET_CFG_START_RXQ);
rx_bar_off = NFP_PCIE_QUEUE(startq);
break;
default:
err = -ENODEV;
goto err_ctrl_unmap;
}
nn = nfp_net_netdev_alloc(pdev, max_tx_rings, max_rx_rings);
if (IS_ERR(nn)) {
err = PTR_ERR(nn);
goto err_ctrl_unmap;
}
nn->fw_ver = fw_ver;
nn->ctrl_bar = ctrl_bar;
nn->is_vf = 1;
nn->is_nfp3200 = is_nfp3200;
nn->stride_tx = stride;
nn->stride_rx = stride;
if (rx_bar_no == tx_bar_no) {
u32 bar_off, bar_sz;
resource_size_t map_addr;
if (tx_bar_off < rx_bar_off)
bar_off = tx_bar_off;
else
bar_off = rx_bar_off;
if ((tx_bar_off + tx_bar_sz) > (rx_bar_off + rx_bar_sz))
bar_sz = (tx_bar_off + tx_bar_sz) - bar_off;
else
bar_sz = (rx_bar_off + rx_bar_sz) - bar_off;
map_addr = pci_resource_start(pdev, tx_bar_no) + bar_off;
nn->q_bar = ioremap_nocache(map_addr, bar_sz);
if (!nn->q_bar) {
nn_err(nn, "Failed to map resource %d\n", tx_bar_no);
err = -EIO;
goto err_netdev_free;
}
nn->tx_bar = nn->q_bar + (tx_bar_off - bar_off);
nn->rx_bar = nn->q_bar + (rx_bar_off - bar_off);
} else {
resource_size_t map_addr;
map_addr = pci_resource_start(pdev, tx_bar_no) + tx_bar_off;
nn->tx_bar = ioremap_nocache(map_addr, tx_bar_sz);
if (!nn->tx_bar) {
nn_err(nn, "Failed to map resource %d\n", tx_bar_no);
err = -EIO;
goto err_netdev_free;
}
map_addr = pci_resource_start(pdev, rx_bar_no) + rx_bar_off;
nn->rx_bar = ioremap_nocache(map_addr, rx_bar_sz);
if (!nn->rx_bar) {
nn_err(nn, "Failed to map resource %d\n", rx_bar_no);
err = -EIO;
goto err_unmap_tx;
}
}
nfp_netvf_get_mac_addr(nn);
err = nfp_net_irqs_alloc(nn);
if (!err) {
nn_warn(nn, "Unable to allocate MSI-X Vectors. Exiting\n");
err = -EIO;
goto err_unmap_rx;
}
nn->me_freq_mhz = 1200;
err = nfp_net_netdev_init(nn->netdev);
if (err)
goto err_irqs_disable;
pci_set_drvdata(pdev, nn);
nfp_net_info(nn);
nfp_net_debugfs_adapter_add(nn);
return 0;
err_irqs_disable:
nfp_net_irqs_disable(nn);
err_unmap_rx:
if (!nn->q_bar)
iounmap(nn->rx_bar);
err_unmap_tx:
if (!nn->q_bar)
iounmap(nn->tx_bar);
else
iounmap(nn->q_bar);
err_netdev_free:
pci_set_drvdata(pdev, NULL);
nfp_net_netdev_free(nn);
err_ctrl_unmap:
iounmap(ctrl_bar);
err_pci_regions:
pci_release_regions(pdev);
err_pci_disable:
pci_disable_device(pdev);
return err;
}
static void nfp_netvf_pci_remove(struct pci_dev *pdev)
{
struct nfp_net *nn = pci_get_drvdata(pdev);
nfp_net_debugfs_adapter_del(nn);
nfp_net_netdev_clean(nn->netdev);
nfp_net_irqs_disable(nn);
if (!nn->q_bar) {
iounmap(nn->rx_bar);
iounmap(nn->tx_bar);
} else {
iounmap(nn->q_bar);
}
iounmap(nn->ctrl_bar);
pci_set_drvdata(pdev, NULL);
nfp_net_netdev_free(nn);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init nfp_netvf_init(void)
{
int err;
pr_info("%s: NFP VF Network driver, Copyright (C) 2014-2015 Netronome Systems\n",
nfp_net_driver_name);
nfp_net_debugfs_create();
err = pci_register_driver(&nfp_netvf_pci_driver);
if (err) {
nfp_net_debugfs_destroy();
return err;
}
return 0;
}
static void __exit nfp_netvf_exit(void)
{
pci_unregister_driver(&nfp_netvf_pci_driver);
nfp_net_debugfs_destroy();
}
