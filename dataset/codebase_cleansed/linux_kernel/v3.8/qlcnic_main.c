inline void qlcnic_update_cmd_producer(struct qlcnic_host_tx_ring *tx_ring)
{
writel(tx_ring->producer, tx_ring->crb_cmd_producer);
}
int qlcnic_alloc_sds_rings(struct qlcnic_recv_context *recv_ctx, int count)
{
int size = sizeof(struct qlcnic_host_sds_ring) * count;
recv_ctx->sds_rings = kzalloc(size, GFP_KERNEL);
return recv_ctx->sds_rings == NULL;
}
void qlcnic_free_sds_rings(struct qlcnic_recv_context *recv_ctx)
{
if (recv_ctx->sds_rings != NULL)
kfree(recv_ctx->sds_rings);
recv_ctx->sds_rings = NULL;
}
static void qlcnic_clear_stats(struct qlcnic_adapter *adapter)
{
memset(&adapter->stats, 0, sizeof(adapter->stats));
}
static void qlcnic_set_msix_bit(struct pci_dev *pdev, int enable)
{
u32 control;
int pos;
pos = pci_find_capability(pdev, PCI_CAP_ID_MSIX);
if (pos) {
pci_read_config_dword(pdev, pos, &control);
if (enable)
control |= PCI_MSIX_FLAGS_ENABLE;
else
control = 0;
pci_write_config_dword(pdev, pos, control);
}
}
static void qlcnic_init_msix_entries(struct qlcnic_adapter *adapter, int count)
{
int i;
for (i = 0; i < count; i++)
adapter->msix_entries[i].entry = i;
}
static int
qlcnic_read_mac_addr(struct qlcnic_adapter *adapter)
{
u8 mac_addr[ETH_ALEN];
struct net_device *netdev = adapter->netdev;
struct pci_dev *pdev = adapter->pdev;
if (qlcnic_get_mac_address(adapter, mac_addr) != 0)
return -EIO;
memcpy(netdev->dev_addr, mac_addr, ETH_ALEN);
memcpy(netdev->perm_addr, netdev->dev_addr, netdev->addr_len);
memcpy(adapter->mac_addr, netdev->dev_addr, netdev->addr_len);
if (!is_valid_ether_addr(netdev->perm_addr))
dev_warn(&pdev->dev, "Bad MAC address %pM.\n",
netdev->dev_addr);
return 0;
}
static int qlcnic_set_mac(struct net_device *netdev, void *p)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct sockaddr *addr = p;
if ((adapter->flags & QLCNIC_MAC_OVERRIDE_DISABLED))
return -EOPNOTSUPP;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (test_bit(__QLCNIC_DEV_UP, &adapter->state)) {
netif_device_detach(netdev);
qlcnic_napi_disable(adapter);
}
memcpy(adapter->mac_addr, addr->sa_data, netdev->addr_len);
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
qlcnic_set_multi(adapter->netdev);
if (test_bit(__QLCNIC_DEV_UP, &adapter->state)) {
netif_device_attach(netdev);
qlcnic_napi_enable(adapter);
}
return 0;
}
static int qlcnic_enable_msix(struct qlcnic_adapter *adapter, u32 num_msix)
{
struct pci_dev *pdev = adapter->pdev;
int err = -1;
adapter->max_sds_rings = 1;
adapter->flags &= ~(QLCNIC_MSI_ENABLED | QLCNIC_MSIX_ENABLED);
qlcnic_set_msix_bit(pdev, 0);
if (adapter->ahw->msix_supported) {
enable_msix:
qlcnic_init_msix_entries(adapter, num_msix);
err = pci_enable_msix(pdev, adapter->msix_entries, num_msix);
if (err == 0) {
adapter->flags |= QLCNIC_MSIX_ENABLED;
qlcnic_set_msix_bit(pdev, 1);
adapter->max_sds_rings = num_msix;
dev_info(&pdev->dev, "using msi-x interrupts\n");
return err;
}
if (err > 0) {
num_msix = rounddown_pow_of_two(err);
if (num_msix)
goto enable_msix;
}
}
return err;
}
static void qlcnic_enable_msi_legacy(struct qlcnic_adapter *adapter)
{
u32 offset, mask_reg;
const struct qlcnic_legacy_intr_set *legacy_intrp;
struct qlcnic_hardware_context *ahw = adapter->ahw;
struct pci_dev *pdev = adapter->pdev;
if (qlcnic_use_msi && !pci_enable_msi(pdev)) {
adapter->flags |= QLCNIC_MSI_ENABLED;
offset = msi_tgt_status[adapter->ahw->pci_func];
adapter->tgt_status_reg = qlcnic_get_ioaddr(adapter->ahw,
offset);
dev_info(&pdev->dev, "using msi interrupts\n");
adapter->msix_entries[0].vector = pdev->irq;
return;
}
legacy_intrp = &legacy_intr[adapter->ahw->pci_func];
adapter->ahw->int_vec_bit = legacy_intrp->int_vec_bit;
offset = legacy_intrp->tgt_status_reg;
adapter->tgt_status_reg = qlcnic_get_ioaddr(ahw, offset);
mask_reg = legacy_intrp->tgt_mask_reg;
adapter->tgt_mask_reg = qlcnic_get_ioaddr(ahw, mask_reg);
adapter->isr_int_vec = qlcnic_get_ioaddr(ahw, ISR_INT_VECTOR);
adapter->crb_int_state_reg = qlcnic_get_ioaddr(ahw, ISR_INT_STATE_REG);
dev_info(&pdev->dev, "using legacy interrupts\n");
adapter->msix_entries[0].vector = pdev->irq;
}
static void
qlcnic_setup_intr(struct qlcnic_adapter *adapter)
{
int num_msix;
if (adapter->ahw->msix_supported) {
num_msix = rounddown_pow_of_two(min_t(int, num_online_cpus(),
QLCNIC_DEF_NUM_STS_DESC_RINGS));
} else
num_msix = 1;
if (!qlcnic_enable_msix(adapter, num_msix))
return;
qlcnic_enable_msi_legacy(adapter);
}
static void
qlcnic_teardown_intr(struct qlcnic_adapter *adapter)
{
if (adapter->flags & QLCNIC_MSIX_ENABLED)
pci_disable_msix(adapter->pdev);
if (adapter->flags & QLCNIC_MSI_ENABLED)
pci_disable_msi(adapter->pdev);
}
static void
qlcnic_cleanup_pci_map(struct qlcnic_adapter *adapter)
{
if (adapter->ahw->pci_base0 != NULL)
iounmap(adapter->ahw->pci_base0);
}
static int qlcnic_init_pci_info(struct qlcnic_adapter *adapter)
{
struct qlcnic_pci_info *pci_info;
int i, ret = 0, j = 0;
u16 act_pci_func;
u8 pfn;
pci_info = kcalloc(QLCNIC_MAX_PCI_FUNC, sizeof(*pci_info), GFP_KERNEL);
if (!pci_info)
return -ENOMEM;
ret = qlcnic_get_pci_info(adapter, pci_info);
if (ret)
goto err_pci_info;
act_pci_func = adapter->ahw->act_pci_func;
adapter->npars = kzalloc(sizeof(struct qlcnic_npar_info) *
act_pci_func, GFP_KERNEL);
if (!adapter->npars) {
ret = -ENOMEM;
goto err_pci_info;
}
adapter->eswitch = kzalloc(sizeof(struct qlcnic_eswitch) *
QLCNIC_NIU_MAX_XG_PORTS, GFP_KERNEL);
if (!adapter->eswitch) {
ret = -ENOMEM;
goto err_npars;
}
for (i = 0; i < QLCNIC_MAX_PCI_FUNC; i++) {
pfn = pci_info[i].id;
if (pfn >= QLCNIC_MAX_PCI_FUNC) {
ret = QL_STATUS_INVALID_PARAM;
goto err_eswitch;
}
if (!pci_info[i].active ||
(pci_info[i].type != QLCNIC_TYPE_NIC))
continue;
adapter->npars[j].pci_func = pfn;
adapter->npars[j].active = (u8)pci_info[i].active;
adapter->npars[j].type = (u8)pci_info[i].type;
adapter->npars[j].phy_port = (u8)pci_info[i].default_port;
adapter->npars[j].min_bw = pci_info[i].tx_min_bw;
adapter->npars[j].max_bw = pci_info[i].tx_max_bw;
j++;
}
for (i = 0; i < QLCNIC_NIU_MAX_XG_PORTS; i++)
adapter->eswitch[i].flags |= QLCNIC_SWITCH_ENABLE;
kfree(pci_info);
return 0;
err_eswitch:
kfree(adapter->eswitch);
adapter->eswitch = NULL;
err_npars:
kfree(adapter->npars);
adapter->npars = NULL;
err_pci_info:
kfree(pci_info);
return ret;
}
static int
qlcnic_set_function_modes(struct qlcnic_adapter *adapter)
{
u8 id;
int i, ret = 1;
u32 data = QLCNIC_MGMT_FUNC;
struct qlcnic_hardware_context *ahw = adapter->ahw;
ret = qlcnic_api_lock(adapter);
if (ret)
goto err_lock;
if (qlcnic_config_npars) {
for (i = 0; i < ahw->act_pci_func; i++) {
id = adapter->npars[i].pci_func;
if (id == ahw->pci_func)
continue;
data |= (qlcnic_config_npars &
QLC_DEV_SET_DRV(0xf, id));
}
} else {
data = QLCRD32(adapter, QLCNIC_DRV_OP_MODE);
data = (data & ~QLC_DEV_SET_DRV(0xf, ahw->pci_func)) |
(QLC_DEV_SET_DRV(QLCNIC_MGMT_FUNC,
ahw->pci_func));
}
QLCWR32(adapter, QLCNIC_DRV_OP_MODE, data);
qlcnic_api_unlock(adapter);
err_lock:
return ret;
}
static void
qlcnic_check_vf(struct qlcnic_adapter *adapter)
{
void __iomem *msix_base_addr;
void __iomem *priv_op;
u32 func;
u32 msix_base;
u32 op_mode, priv_level;
adapter->ahw->fw_hal_version = readl(adapter->ahw->pci_base0 +
QLCNIC_FW_API);
pci_read_config_dword(adapter->pdev, QLCNIC_MSIX_TABLE_OFFSET, &func);
msix_base_addr = adapter->ahw->pci_base0 + QLCNIC_MSIX_BASE;
msix_base = readl(msix_base_addr);
func = (func - msix_base)/QLCNIC_MSIX_TBL_PGSIZE;
adapter->ahw->pci_func = func;
priv_op = adapter->ahw->pci_base0 + QLCNIC_DRV_OP_MODE;
op_mode = readl(priv_op);
if (op_mode == QLC_DEV_DRV_DEFAULT)
priv_level = QLCNIC_MGMT_FUNC;
else
priv_level = QLC_DEV_GET_DRV(op_mode, adapter->ahw->pci_func);
if (priv_level == QLCNIC_NON_PRIV_FUNC) {
adapter->ahw->op_mode = QLCNIC_NON_PRIV_FUNC;
dev_info(&adapter->pdev->dev,
"HAL Version: %d Non Privileged function\n",
adapter->ahw->fw_hal_version);
adapter->nic_ops = &qlcnic_vf_ops;
} else
adapter->nic_ops = &qlcnic_ops;
}
static void qlcnic_get_bar_length(u32 dev_id, ulong *bar)
{
switch (dev_id) {
case PCI_DEVICE_ID_QLOGIC_QLE824X:
*bar = QLCNIC_82XX_BAR0_LENGTH;
break;
default:
*bar = 0;
}
}
static int qlcnic_setup_pci_map(struct pci_dev *pdev,
struct qlcnic_hardware_context *ahw)
{
u32 offset;
void __iomem *mem_ptr0 = NULL;
unsigned long mem_len, pci_len0 = 0, bar0_len;
mem_len = pci_resource_len(pdev, 0);
qlcnic_get_bar_length(pdev->device, &bar0_len);
if (mem_len >= bar0_len) {
mem_ptr0 = pci_ioremap_bar(pdev, 0);
if (mem_ptr0 == NULL) {
dev_err(&pdev->dev, "failed to map PCI bar 0\n");
return -EIO;
}
pci_len0 = mem_len;
} else {
return -EIO;
}
dev_info(&pdev->dev, "%dMB memory map\n", (int)(mem_len>>20));
ahw->pci_base0 = mem_ptr0;
ahw->pci_len0 = pci_len0;
offset = QLCNIC_PCIX_PS_REG(PCIX_OCM_WINDOW_REG(ahw->pci_func));
qlcnic_get_ioaddr(ahw, offset);
return 0;
}
static void qlcnic_get_board_name(struct qlcnic_adapter *adapter, char *name)
{
struct pci_dev *pdev = adapter->pdev;
int i, found = 0;
for (i = 0; i < NUM_SUPPORTED_BOARDS; ++i) {
if (qlcnic_boards[i].vendor == pdev->vendor &&
qlcnic_boards[i].device == pdev->device &&
qlcnic_boards[i].sub_vendor == pdev->subsystem_vendor &&
qlcnic_boards[i].sub_device == pdev->subsystem_device) {
sprintf(name, "%pM: %s" ,
adapter->mac_addr,
qlcnic_boards[i].short_name);
found = 1;
break;
}
}
if (!found)
sprintf(name, "%pM Gigabit Ethernet", adapter->mac_addr);
}
static void
qlcnic_check_options(struct qlcnic_adapter *adapter)
{
u32 fw_major, fw_minor, fw_build, prev_fw_version;
struct pci_dev *pdev = adapter->pdev;
struct qlcnic_fw_dump *fw_dump = &adapter->ahw->fw_dump;
prev_fw_version = adapter->fw_version;
fw_major = QLCRD32(adapter, QLCNIC_FW_VERSION_MAJOR);
fw_minor = QLCRD32(adapter, QLCNIC_FW_VERSION_MINOR);
fw_build = QLCRD32(adapter, QLCNIC_FW_VERSION_SUB);
adapter->fw_version = QLCNIC_VERSION_CODE(fw_major, fw_minor, fw_build);
if (adapter->ahw->op_mode != QLCNIC_NON_PRIV_FUNC) {
if (fw_dump->tmpl_hdr == NULL ||
adapter->fw_version > prev_fw_version) {
if (fw_dump->tmpl_hdr)
vfree(fw_dump->tmpl_hdr);
if (!qlcnic_fw_cmd_get_minidump_temp(adapter))
dev_info(&pdev->dev,
"Supports FW dump capability\n");
}
}
dev_info(&pdev->dev, "firmware v%d.%d.%d\n",
fw_major, fw_minor, fw_build);
if (adapter->ahw->port_type == QLCNIC_XGBE) {
if (adapter->flags & QLCNIC_ESWITCH_ENABLED) {
adapter->num_rxd = DEFAULT_RCV_DESCRIPTORS_VF;
adapter->max_rxd = MAX_RCV_DESCRIPTORS_VF;
} else {
adapter->num_rxd = DEFAULT_RCV_DESCRIPTORS_10G;
adapter->max_rxd = MAX_RCV_DESCRIPTORS_10G;
}
adapter->num_jumbo_rxd = MAX_JUMBO_RCV_DESCRIPTORS_10G;
adapter->max_jumbo_rxd = MAX_JUMBO_RCV_DESCRIPTORS_10G;
} else if (adapter->ahw->port_type == QLCNIC_GBE) {
adapter->num_rxd = DEFAULT_RCV_DESCRIPTORS_1G;
adapter->num_jumbo_rxd = MAX_JUMBO_RCV_DESCRIPTORS_1G;
adapter->max_jumbo_rxd = MAX_JUMBO_RCV_DESCRIPTORS_1G;
adapter->max_rxd = MAX_RCV_DESCRIPTORS_1G;
}
adapter->ahw->msix_supported = !!qlcnic_use_msi_x;
adapter->num_txd = MAX_CMD_DESCRIPTORS;
adapter->max_rds_rings = MAX_RDS_RINGS;
}
static int
qlcnic_initialize_nic(struct qlcnic_adapter *adapter)
{
int err;
struct qlcnic_info nic_info;
memset(&nic_info, 0, sizeof(struct qlcnic_info));
err = qlcnic_get_nic_info(adapter, &nic_info, adapter->ahw->pci_func);
if (err)
return err;
adapter->ahw->physical_port = (u8)nic_info.phys_port;
adapter->ahw->switch_mode = nic_info.switch_mode;
adapter->ahw->max_tx_ques = nic_info.max_tx_ques;
adapter->ahw->max_rx_ques = nic_info.max_rx_ques;
adapter->ahw->capabilities = nic_info.capabilities;
adapter->ahw->max_mac_filters = nic_info.max_mac_filters;
adapter->ahw->max_mtu = nic_info.max_mtu;
if (adapter->ahw->capabilities & BIT_6)
adapter->flags |= QLCNIC_ESWITCH_ENABLED;
else
adapter->flags &= ~QLCNIC_ESWITCH_ENABLED;
return err;
}
void qlcnic_set_vlan_config(struct qlcnic_adapter *adapter,
struct qlcnic_esw_func_cfg *esw_cfg)
{
if (esw_cfg->discard_tagged)
adapter->flags &= ~QLCNIC_TAGGING_ENABLED;
else
adapter->flags |= QLCNIC_TAGGING_ENABLED;
if (esw_cfg->vlan_id)
adapter->pvid = esw_cfg->vlan_id;
else
adapter->pvid = 0;
}
static int
qlcnic_vlan_rx_add(struct net_device *netdev, u16 vid)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
set_bit(vid, adapter->vlans);
return 0;
}
static int
qlcnic_vlan_rx_del(struct net_device *netdev, u16 vid)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
qlcnic_restore_indev_addr(netdev, NETDEV_DOWN);
clear_bit(vid, adapter->vlans);
return 0;
}
void qlcnic_set_eswitch_port_features(struct qlcnic_adapter *adapter,
struct qlcnic_esw_func_cfg *esw_cfg)
{
adapter->flags &= ~(QLCNIC_MACSPOOF | QLCNIC_MAC_OVERRIDE_DISABLED |
QLCNIC_PROMISC_DISABLED);
if (esw_cfg->mac_anti_spoof)
adapter->flags |= QLCNIC_MACSPOOF;
if (!esw_cfg->mac_override)
adapter->flags |= QLCNIC_MAC_OVERRIDE_DISABLED;
if (!esw_cfg->promisc_mode)
adapter->flags |= QLCNIC_PROMISC_DISABLED;
qlcnic_set_netdev_features(adapter, esw_cfg);
}
static int qlcnic_set_eswitch_port_config(struct qlcnic_adapter *adapter)
{
struct qlcnic_esw_func_cfg esw_cfg;
if (!(adapter->flags & QLCNIC_ESWITCH_ENABLED))
return 0;
esw_cfg.pci_func = adapter->ahw->pci_func;
if (qlcnic_get_eswitch_port_config(adapter, &esw_cfg))
return -EIO;
qlcnic_set_vlan_config(adapter, &esw_cfg);
qlcnic_set_eswitch_port_features(adapter, &esw_cfg);
return 0;
}
static void
qlcnic_set_netdev_features(struct qlcnic_adapter *adapter,
struct qlcnic_esw_func_cfg *esw_cfg)
{
struct net_device *netdev = adapter->netdev;
netdev_features_t features, vlan_features;
features = (NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_RXCSUM |
NETIF_F_IPV6_CSUM | NETIF_F_GRO);
vlan_features = (NETIF_F_SG | NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM | NETIF_F_HW_VLAN_FILTER);
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_TSO) {
features |= (NETIF_F_TSO | NETIF_F_TSO6);
vlan_features |= (NETIF_F_TSO | NETIF_F_TSO6);
}
if (netdev->features & NETIF_F_LRO)
features |= NETIF_F_LRO;
if (esw_cfg->offload_flags & BIT_0) {
netdev->features |= features;
if (!(esw_cfg->offload_flags & BIT_1))
netdev->features &= ~NETIF_F_TSO;
if (!(esw_cfg->offload_flags & BIT_2))
netdev->features &= ~NETIF_F_TSO6;
} else {
netdev->features &= ~features;
}
netdev->vlan_features = (features & vlan_features);
}
static int
qlcnic_check_eswitch_mode(struct qlcnic_adapter *adapter)
{
void __iomem *priv_op;
u32 op_mode, priv_level;
int err = 0;
err = qlcnic_initialize_nic(adapter);
if (err)
return err;
if (adapter->flags & QLCNIC_ADAPTER_INITIALIZED)
return 0;
priv_op = adapter->ahw->pci_base0 + QLCNIC_DRV_OP_MODE;
op_mode = readl(priv_op);
priv_level = QLC_DEV_GET_DRV(op_mode, adapter->ahw->pci_func);
if (op_mode == QLC_DEV_DRV_DEFAULT)
priv_level = QLCNIC_MGMT_FUNC;
else
priv_level = QLC_DEV_GET_DRV(op_mode, adapter->ahw->pci_func);
if (adapter->flags & QLCNIC_ESWITCH_ENABLED) {
if (priv_level == QLCNIC_MGMT_FUNC) {
adapter->ahw->op_mode = QLCNIC_MGMT_FUNC;
err = qlcnic_init_pci_info(adapter);
if (err)
return err;
qlcnic_set_function_modes(adapter);
dev_info(&adapter->pdev->dev,
"HAL Version: %d, Management function\n",
adapter->ahw->fw_hal_version);
} else if (priv_level == QLCNIC_PRIV_FUNC) {
adapter->ahw->op_mode = QLCNIC_PRIV_FUNC;
dev_info(&adapter->pdev->dev,
"HAL Version: %d, Privileged function\n",
adapter->ahw->fw_hal_version);
}
}
adapter->flags |= QLCNIC_ADAPTER_INITIALIZED;
return err;
}
static int qlcnic_set_default_offload_settings(struct qlcnic_adapter *adapter)
{
struct qlcnic_esw_func_cfg esw_cfg;
struct qlcnic_npar_info *npar;
u8 i;
if (adapter->need_fw_reset)
return 0;
for (i = 0; i < adapter->ahw->act_pci_func; i++) {
memset(&esw_cfg, 0, sizeof(struct qlcnic_esw_func_cfg));
esw_cfg.pci_func = adapter->npars[i].pci_func;
esw_cfg.mac_override = BIT_0;
esw_cfg.promisc_mode = BIT_0;
if (qlcnic_82xx_check(adapter)) {
esw_cfg.offload_flags = BIT_0;
if (QLCNIC_IS_TSO_CAPABLE(adapter))
esw_cfg.offload_flags |= (BIT_1 | BIT_2);
}
if (qlcnic_config_switch_port(adapter, &esw_cfg))
return -EIO;
npar = &adapter->npars[i];
npar->pvid = esw_cfg.vlan_id;
npar->mac_override = esw_cfg.mac_override;
npar->mac_anti_spoof = esw_cfg.mac_anti_spoof;
npar->discard_tagged = esw_cfg.discard_tagged;
npar->promisc_mode = esw_cfg.promisc_mode;
npar->offload_flags = esw_cfg.offload_flags;
}
return 0;
}
static int
qlcnic_reset_eswitch_config(struct qlcnic_adapter *adapter,
struct qlcnic_npar_info *npar, int pci_func)
{
struct qlcnic_esw_func_cfg esw_cfg;
esw_cfg.op_mode = QLCNIC_PORT_DEFAULTS;
esw_cfg.pci_func = pci_func;
esw_cfg.vlan_id = npar->pvid;
esw_cfg.mac_override = npar->mac_override;
esw_cfg.discard_tagged = npar->discard_tagged;
esw_cfg.mac_anti_spoof = npar->mac_anti_spoof;
esw_cfg.offload_flags = npar->offload_flags;
esw_cfg.promisc_mode = npar->promisc_mode;
if (qlcnic_config_switch_port(adapter, &esw_cfg))
return -EIO;
esw_cfg.op_mode = QLCNIC_ADD_VLAN;
if (qlcnic_config_switch_port(adapter, &esw_cfg))
return -EIO;
return 0;
}
static int qlcnic_reset_npar_config(struct qlcnic_adapter *adapter)
{
int i, err;
struct qlcnic_npar_info *npar;
struct qlcnic_info nic_info;
u8 pci_func;
if (qlcnic_82xx_check(adapter))
if (!adapter->need_fw_reset)
return 0;
for (i = 0; i < adapter->ahw->act_pci_func; i++) {
npar = &adapter->npars[i];
pci_func = npar->pci_func;
memset(&nic_info, 0, sizeof(struct qlcnic_info));
err = qlcnic_get_nic_info(adapter,
&nic_info, pci_func);
if (err)
return err;
nic_info.min_tx_bw = npar->min_bw;
nic_info.max_tx_bw = npar->max_bw;
err = qlcnic_set_nic_info(adapter, &nic_info);
if (err)
return err;
if (npar->enable_pm) {
err = qlcnic_config_port_mirroring(adapter,
npar->dest_npar, 1,
pci_func);
if (err)
return err;
}
err = qlcnic_reset_eswitch_config(adapter, npar, pci_func);
if (err)
return err;
}
return 0;
}
static int qlcnic_check_npar_opertional(struct qlcnic_adapter *adapter)
{
u8 npar_opt_timeo = QLCNIC_DEV_NPAR_OPER_TIMEO;
u32 npar_state;
if (adapter->ahw->op_mode == QLCNIC_MGMT_FUNC)
return 0;
npar_state = QLCRD32(adapter, QLCNIC_CRB_DEV_NPAR_STATE);
while (npar_state != QLCNIC_DEV_NPAR_OPER && --npar_opt_timeo) {
msleep(1000);
npar_state = QLCRD32(adapter, QLCNIC_CRB_DEV_NPAR_STATE);
}
if (!npar_opt_timeo) {
dev_err(&adapter->pdev->dev,
"Waiting for NPAR state to opertional timeout\n");
return -EIO;
}
return 0;
}
static int
qlcnic_set_mgmt_operations(struct qlcnic_adapter *adapter)
{
int err;
if (!(adapter->flags & QLCNIC_ESWITCH_ENABLED) ||
adapter->ahw->op_mode != QLCNIC_MGMT_FUNC)
return 0;
err = qlcnic_set_default_offload_settings(adapter);
if (err)
return err;
err = qlcnic_reset_npar_config(adapter);
if (err)
return err;
qlcnic_dev_set_npar_ready(adapter);
return err;
}
static int
qlcnic_start_firmware(struct qlcnic_adapter *adapter)
{
int err;
err = qlcnic_can_start_firmware(adapter);
if (err < 0)
return err;
else if (!err)
goto check_fw_status;
if (qlcnic_load_fw_file)
qlcnic_request_firmware(adapter);
else {
err = qlcnic_check_flash_fw_ver(adapter);
if (err)
goto err_out;
adapter->ahw->fw_type = QLCNIC_FLASH_ROMIMAGE;
}
err = qlcnic_need_fw_reset(adapter);
if (err == 0)
goto check_fw_status;
err = qlcnic_pinit_from_rom(adapter);
if (err)
goto err_out;
err = qlcnic_load_firmware(adapter);
if (err)
goto err_out;
qlcnic_release_firmware(adapter);
QLCWR32(adapter, CRB_DRIVER_VERSION, QLCNIC_DRIVER_VERSION);
check_fw_status:
err = qlcnic_check_fw_status(adapter);
if (err)
goto err_out;
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE, QLCNIC_DEV_READY);
qlcnic_idc_debug_info(adapter, 1);
err = qlcnic_check_eswitch_mode(adapter);
if (err) {
dev_err(&adapter->pdev->dev,
"Memory allocation failed for eswitch\n");
goto err_out;
}
err = qlcnic_set_mgmt_operations(adapter);
if (err)
goto err_out;
qlcnic_check_options(adapter);
adapter->need_fw_reset = 0;
qlcnic_release_firmware(adapter);
return 0;
err_out:
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE, QLCNIC_DEV_FAILED);
dev_err(&adapter->pdev->dev, "Device state set to failed\n");
qlcnic_release_firmware(adapter);
return err;
}
static int
qlcnic_request_irq(struct qlcnic_adapter *adapter)
{
irq_handler_t handler;
struct qlcnic_host_sds_ring *sds_ring;
int err, ring;
unsigned long flags = 0;
struct net_device *netdev = adapter->netdev;
struct qlcnic_recv_context *recv_ctx = adapter->recv_ctx;
if (adapter->ahw->diag_test == QLCNIC_INTERRUPT_TEST) {
handler = qlcnic_tmp_intr;
if (!QLCNIC_IS_MSI_FAMILY(adapter))
flags |= IRQF_SHARED;
} else {
if (adapter->flags & QLCNIC_MSIX_ENABLED)
handler = qlcnic_msix_intr;
else if (adapter->flags & QLCNIC_MSI_ENABLED)
handler = qlcnic_msi_intr;
else {
flags |= IRQF_SHARED;
handler = qlcnic_intr;
}
}
adapter->irq = netdev->irq;
for (ring = 0; ring < adapter->max_sds_rings; ring++) {
sds_ring = &recv_ctx->sds_rings[ring];
sprintf(sds_ring->name, "%s[%d]", netdev->name, ring);
err = request_irq(sds_ring->irq, handler,
flags, sds_ring->name, sds_ring);
if (err)
return err;
}
return 0;
}
static void
qlcnic_free_irq(struct qlcnic_adapter *adapter)
{
int ring;
struct qlcnic_host_sds_ring *sds_ring;
struct qlcnic_recv_context *recv_ctx = adapter->recv_ctx;
for (ring = 0; ring < adapter->max_sds_rings; ring++) {
sds_ring = &recv_ctx->sds_rings[ring];
free_irq(sds_ring->irq, sds_ring);
}
}
static int
__qlcnic_up(struct qlcnic_adapter *adapter, struct net_device *netdev)
{
int ring;
u32 capab2;
struct qlcnic_host_rds_ring *rds_ring;
if (adapter->is_up != QLCNIC_ADAPTER_UP_MAGIC)
return -EIO;
if (test_bit(__QLCNIC_DEV_UP, &adapter->state))
return 0;
if (qlcnic_set_eswitch_port_config(adapter))
return -EIO;
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_MORE_CAPS) {
capab2 = QLCRD32(adapter, CRB_FW_CAPABILITIES_2);
if (capab2 & QLCNIC_FW_CAPABILITY_2_LRO_MAX_TCP_SEG)
adapter->flags |= QLCNIC_FW_LRO_MSS_CAP;
}
if (qlcnic_fw_create_ctx(adapter))
return -EIO;
for (ring = 0; ring < adapter->max_rds_rings; ring++) {
rds_ring = &adapter->recv_ctx->rds_rings[ring];
qlcnic_post_rx_buffers(adapter, rds_ring);
}
qlcnic_set_multi(netdev);
qlcnic_fw_cmd_set_mtu(adapter, netdev->mtu);
adapter->ahw->linkup = 0;
if (adapter->max_sds_rings > 1)
qlcnic_config_rss(adapter, 1);
qlcnic_config_intr_coalesce(adapter);
if (netdev->features & NETIF_F_LRO)
qlcnic_config_hw_lro(adapter, QLCNIC_LRO_ENABLED);
qlcnic_napi_enable(adapter);
qlcnic_linkevent_request(adapter, 1);
adapter->ahw->reset_context = 0;
set_bit(__QLCNIC_DEV_UP, &adapter->state);
return 0;
}
static int
qlcnic_up(struct qlcnic_adapter *adapter, struct net_device *netdev)
{
int err = 0;
rtnl_lock();
if (netif_running(netdev))
err = __qlcnic_up(adapter, netdev);
rtnl_unlock();
return err;
}
static void
__qlcnic_down(struct qlcnic_adapter *adapter, struct net_device *netdev)
{
if (adapter->is_up != QLCNIC_ADAPTER_UP_MAGIC)
return;
if (!test_and_clear_bit(__QLCNIC_DEV_UP, &adapter->state))
return;
smp_mb();
spin_lock(&adapter->tx_clean_lock);
netif_carrier_off(netdev);
netif_tx_disable(netdev);
qlcnic_free_mac_list(adapter);
if (adapter->fhash.fnum)
qlcnic_delete_lb_filters(adapter);
qlcnic_nic_set_promisc(adapter, QLCNIC_NIU_NON_PROMISC_MODE);
qlcnic_napi_disable(adapter);
qlcnic_fw_destroy_ctx(adapter);
adapter->flags &= ~QLCNIC_FW_LRO_MSS_CAP;
qlcnic_reset_rx_buffers_list(adapter);
qlcnic_release_tx_buffers(adapter);
spin_unlock(&adapter->tx_clean_lock);
}
static void
qlcnic_down(struct qlcnic_adapter *adapter, struct net_device *netdev)
{
rtnl_lock();
if (netif_running(netdev))
__qlcnic_down(adapter, netdev);
rtnl_unlock();
}
static int
qlcnic_attach(struct qlcnic_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct pci_dev *pdev = adapter->pdev;
int err;
if (adapter->is_up == QLCNIC_ADAPTER_UP_MAGIC)
return 0;
err = qlcnic_napi_add(adapter, netdev);
if (err)
return err;
err = qlcnic_alloc_sw_resources(adapter);
if (err) {
dev_err(&pdev->dev, "Error in setting sw resources\n");
goto err_out_napi_del;
}
err = qlcnic_alloc_hw_resources(adapter);
if (err) {
dev_err(&pdev->dev, "Error in setting hw resources\n");
goto err_out_free_sw;
}
err = qlcnic_request_irq(adapter);
if (err) {
dev_err(&pdev->dev, "failed to setup interrupt\n");
goto err_out_free_hw;
}
qlcnic_create_sysfs_entries(adapter);
adapter->is_up = QLCNIC_ADAPTER_UP_MAGIC;
return 0;
err_out_free_hw:
qlcnic_free_hw_resources(adapter);
err_out_free_sw:
qlcnic_free_sw_resources(adapter);
err_out_napi_del:
qlcnic_napi_del(adapter);
return err;
}
static void
qlcnic_detach(struct qlcnic_adapter *adapter)
{
if (adapter->is_up != QLCNIC_ADAPTER_UP_MAGIC)
return;
qlcnic_remove_sysfs_entries(adapter);
qlcnic_free_hw_resources(adapter);
qlcnic_release_rx_buffers(adapter);
qlcnic_free_irq(adapter);
qlcnic_napi_del(adapter);
qlcnic_free_sw_resources(adapter);
adapter->is_up = 0;
}
void qlcnic_diag_free_res(struct net_device *netdev, int max_sds_rings)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct qlcnic_host_sds_ring *sds_ring;
int ring;
clear_bit(__QLCNIC_DEV_UP, &adapter->state);
if (adapter->ahw->diag_test == QLCNIC_INTERRUPT_TEST) {
for (ring = 0; ring < adapter->max_sds_rings; ring++) {
sds_ring = &adapter->recv_ctx->sds_rings[ring];
qlcnic_disable_int(sds_ring);
}
}
qlcnic_fw_destroy_ctx(adapter);
qlcnic_detach(adapter);
adapter->ahw->diag_test = 0;
adapter->max_sds_rings = max_sds_rings;
if (qlcnic_attach(adapter))
goto out;
if (netif_running(netdev))
__qlcnic_up(adapter, netdev);
out:
netif_device_attach(netdev);
}
static int qlcnic_alloc_adapter_resources(struct qlcnic_adapter *adapter)
{
int err = 0;
adapter->ahw = kzalloc(sizeof(struct qlcnic_hardware_context),
GFP_KERNEL);
if (!adapter->ahw) {
dev_err(&adapter->pdev->dev,
"Failed to allocate recv ctx resources for adapter\n");
err = -ENOMEM;
goto err_out;
}
adapter->recv_ctx = kzalloc(sizeof(struct qlcnic_recv_context),
GFP_KERNEL);
if (!adapter->recv_ctx) {
dev_err(&adapter->pdev->dev,
"Failed to allocate recv ctx resources for adapter\n");
kfree(adapter->ahw);
adapter->ahw = NULL;
err = -ENOMEM;
goto err_out;
}
adapter->ahw->coal.flag = QLCNIC_INTR_DEFAULT;
adapter->ahw->coal.rx_time_us = QLCNIC_DEFAULT_INTR_COALESCE_RX_TIME_US;
adapter->ahw->coal.rx_packets = QLCNIC_DEFAULT_INTR_COALESCE_RX_PACKETS;
err_out:
return err;
}
static void qlcnic_free_adapter_resources(struct qlcnic_adapter *adapter)
{
kfree(adapter->recv_ctx);
adapter->recv_ctx = NULL;
if (adapter->ahw->fw_dump.tmpl_hdr) {
vfree(adapter->ahw->fw_dump.tmpl_hdr);
adapter->ahw->fw_dump.tmpl_hdr = NULL;
}
kfree(adapter->ahw);
adapter->ahw = NULL;
}
int qlcnic_diag_alloc_res(struct net_device *netdev, int test)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct qlcnic_host_sds_ring *sds_ring;
struct qlcnic_host_rds_ring *rds_ring;
int ring;
int ret;
netif_device_detach(netdev);
if (netif_running(netdev))
__qlcnic_down(adapter, netdev);
qlcnic_detach(adapter);
adapter->max_sds_rings = 1;
adapter->ahw->diag_test = test;
ret = qlcnic_attach(adapter);
if (ret) {
netif_device_attach(netdev);
return ret;
}
ret = qlcnic_fw_create_ctx(adapter);
if (ret) {
qlcnic_detach(adapter);
netif_device_attach(netdev);
return ret;
}
for (ring = 0; ring < adapter->max_rds_rings; ring++) {
rds_ring = &adapter->recv_ctx->rds_rings[ring];
qlcnic_post_rx_buffers(adapter, rds_ring);
}
if (adapter->ahw->diag_test == QLCNIC_INTERRUPT_TEST) {
for (ring = 0; ring < adapter->max_sds_rings; ring++) {
sds_ring = &adapter->recv_ctx->sds_rings[ring];
qlcnic_enable_int(sds_ring);
}
}
if (adapter->ahw->diag_test == QLCNIC_LOOPBACK_TEST) {
adapter->ahw->loopback_state = 0;
qlcnic_linkevent_request(adapter, 1);
}
set_bit(__QLCNIC_DEV_UP, &adapter->state);
return 0;
}
static int
qlcnic_reset_hw_context(struct qlcnic_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
if (test_and_set_bit(__QLCNIC_RESETTING, &adapter->state))
return -EBUSY;
netif_device_detach(netdev);
qlcnic_down(adapter, netdev);
qlcnic_up(adapter, netdev);
netif_device_attach(netdev);
clear_bit(__QLCNIC_RESETTING, &adapter->state);
return 0;
}
int
qlcnic_reset_context(struct qlcnic_adapter *adapter)
{
int err = 0;
struct net_device *netdev = adapter->netdev;
if (test_and_set_bit(__QLCNIC_RESETTING, &adapter->state))
return -EBUSY;
if (adapter->is_up == QLCNIC_ADAPTER_UP_MAGIC) {
netif_device_detach(netdev);
if (netif_running(netdev))
__qlcnic_down(adapter, netdev);
qlcnic_detach(adapter);
if (netif_running(netdev)) {
err = qlcnic_attach(adapter);
if (!err) {
__qlcnic_up(adapter, netdev);
qlcnic_restore_indev_addr(netdev, NETDEV_UP);
}
}
netif_device_attach(netdev);
}
clear_bit(__QLCNIC_RESETTING, &adapter->state);
return err;
}
static int
qlcnic_setup_netdev(struct qlcnic_adapter *adapter, struct net_device *netdev,
int pci_using_dac)
{
int err;
struct pci_dev *pdev = adapter->pdev;
adapter->ahw->mc_enabled = 0;
adapter->ahw->max_mc_count = 38;
netdev->netdev_ops = &qlcnic_netdev_ops;
netdev->watchdog_timeo = 5*HZ;
qlcnic_change_mtu(netdev, netdev->mtu);
SET_ETHTOOL_OPS(netdev, &qlcnic_ethtool_ops);
netdev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM | NETIF_F_RXCSUM;
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_TSO)
netdev->hw_features |= NETIF_F_TSO | NETIF_F_TSO6;
if (pci_using_dac == 1)
netdev->hw_features |= NETIF_F_HIGHDMA;
netdev->vlan_features = netdev->hw_features;
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_FVLANTX)
netdev->hw_features |= NETIF_F_HW_VLAN_TX;
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_HW_LRO)
netdev->hw_features |= NETIF_F_LRO;
netdev->features |= netdev->hw_features |
NETIF_F_HW_VLAN_RX | NETIF_F_HW_VLAN_FILTER;
netdev->irq = adapter->msix_entries[0].vector;
err = register_netdev(netdev);
if (err) {
dev_err(&pdev->dev, "failed to register net device\n");
return err;
}
return 0;
}
static int qlcnic_set_dma_mask(struct pci_dev *pdev, int *pci_using_dac)
{
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) &&
!pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64)))
*pci_using_dac = 1;
else if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) &&
!pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32)))
*pci_using_dac = 0;
else {
dev_err(&pdev->dev, "Unable to set DMA mask, aborting\n");
return -EIO;
}
return 0;
}
static int
qlcnic_alloc_msix_entries(struct qlcnic_adapter *adapter, u16 count)
{
adapter->msix_entries = kcalloc(count, sizeof(struct msix_entry),
GFP_KERNEL);
if (adapter->msix_entries)
return 0;
dev_err(&adapter->pdev->dev, "failed allocating msix_entries\n");
return -ENOMEM;
}
static int
qlcnic_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev = NULL;
struct qlcnic_adapter *adapter = NULL;
int err, pci_using_dac = -1;
uint8_t revision_id;
char board_name[QLCNIC_MAX_BOARD_NAME_LEN];
err = pci_enable_device(pdev);
if (err)
return err;
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
err = -ENODEV;
goto err_out_disable_pdev;
}
err = qlcnic_set_dma_mask(pdev, &pci_using_dac);
if (err)
goto err_out_disable_pdev;
err = pci_request_regions(pdev, qlcnic_driver_name);
if (err)
goto err_out_disable_pdev;
pci_set_master(pdev);
pci_enable_pcie_error_reporting(pdev);
netdev = alloc_etherdev(sizeof(struct qlcnic_adapter));
if (!netdev) {
err = -ENOMEM;
goto err_out_free_res;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
err = qlcnic_alloc_adapter_resources(adapter);
if (err)
goto err_out_free_netdev;
adapter->dev_rst_time = jiffies;
revision_id = pdev->revision;
adapter->ahw->revision_id = revision_id;
adapter->mac_learn = qlcnic_mac_learn;
rwlock_init(&adapter->ahw->crb_lock);
mutex_init(&adapter->ahw->mem_lock);
spin_lock_init(&adapter->tx_clean_lock);
INIT_LIST_HEAD(&adapter->mac_list);
err = qlcnic_setup_pci_map(pdev, adapter->ahw);
if (err)
goto err_out_free_hw;
qlcnic_check_vf(adapter);
adapter->portnum = adapter->ahw->pci_func;
err = qlcnic_get_board_info(adapter);
if (err) {
dev_err(&pdev->dev, "Error getting board config info.\n");
goto err_out_iounmap;
}
err = qlcnic_setup_idc_param(adapter);
if (err)
goto err_out_iounmap;
adapter->flags |= QLCNIC_NEED_FLR;
err = adapter->nic_ops->start_firmware(adapter);
if (err) {
dev_err(&pdev->dev, "Loading fw failed. Please Reboot\n"
"\t\tIf reboot doesn't help, try flashing the card\n");
goto err_out_maintenance_mode;
}
if (qlcnic_read_mac_addr(adapter))
dev_warn(&pdev->dev, "failed to read mac addr\n");
if (adapter->portnum == 0) {
qlcnic_get_board_name(adapter, board_name);
pr_info("%s: %s Board Chip rev 0x%x\n",
module_name(THIS_MODULE),
board_name, adapter->ahw->revision_id);
}
qlcnic_clear_stats(adapter);
err = qlcnic_alloc_msix_entries(adapter, adapter->ahw->max_rx_ques);
if (err)
goto err_out_decr_ref;
qlcnic_setup_intr(adapter);
err = qlcnic_setup_netdev(adapter, netdev, pci_using_dac);
if (err)
goto err_out_disable_msi;
pci_set_drvdata(pdev, adapter);
if (qlcnic_82xx_check(adapter))
qlcnic_schedule_work(adapter, qlcnic_fw_poll_work,
FW_POLL_DELAY);
switch (adapter->ahw->port_type) {
case QLCNIC_GBE:
dev_info(&adapter->pdev->dev, "%s: GbE port initialized\n",
adapter->netdev->name);
break;
case QLCNIC_XGBE:
dev_info(&adapter->pdev->dev, "%s: XGbE port initialized\n",
adapter->netdev->name);
break;
}
if (adapter->mac_learn)
qlcnic_alloc_lb_filters_mem(adapter);
qlcnic_create_diag_entries(adapter);
return 0;
err_out_disable_msi:
qlcnic_teardown_intr(adapter);
kfree(adapter->msix_entries);
err_out_decr_ref:
qlcnic_clr_all_drv_state(adapter, 0);
err_out_iounmap:
qlcnic_cleanup_pci_map(adapter);
err_out_free_hw:
qlcnic_free_adapter_resources(adapter);
err_out_free_netdev:
free_netdev(netdev);
err_out_free_res:
pci_release_regions(pdev);
err_out_disable_pdev:
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
return err;
err_out_maintenance_mode:
netdev->netdev_ops = &qlcnic_netdev_failed_ops;
SET_ETHTOOL_OPS(netdev, &qlcnic_ethtool_failed_ops);
err = register_netdev(netdev);
if (err) {
dev_err(&pdev->dev, "failed to register net device\n");
goto err_out_decr_ref;
}
pci_set_drvdata(pdev, adapter);
qlcnic_create_diag_entries(adapter);
return 0;
}
static void qlcnic_remove(struct pci_dev *pdev)
{
struct qlcnic_adapter *adapter;
struct net_device *netdev;
adapter = pci_get_drvdata(pdev);
if (adapter == NULL)
return;
netdev = adapter->netdev;
qlcnic_cancel_fw_work(adapter);
unregister_netdev(netdev);
qlcnic_detach(adapter);
if (adapter->npars != NULL)
kfree(adapter->npars);
if (adapter->eswitch != NULL)
kfree(adapter->eswitch);
if (qlcnic_82xx_check(adapter))
qlcnic_clr_all_drv_state(adapter, 0);
clear_bit(__QLCNIC_RESETTING, &adapter->state);
qlcnic_free_lb_filters_mem(adapter);
qlcnic_teardown_intr(adapter);
kfree(adapter->msix_entries);
qlcnic_remove_diag_entries(adapter);
qlcnic_cleanup_pci_map(adapter);
qlcnic_release_firmware(adapter);
pci_disable_pcie_error_reporting(pdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
qlcnic_free_adapter_resources(adapter);
free_netdev(netdev);
}
static int __qlcnic_shutdown(struct pci_dev *pdev)
{
struct qlcnic_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
int retval;
netif_device_detach(netdev);
qlcnic_cancel_fw_work(adapter);
if (netif_running(netdev))
qlcnic_down(adapter, netdev);
if (qlcnic_82xx_check(adapter))
qlcnic_clr_all_drv_state(adapter, 0);
clear_bit(__QLCNIC_RESETTING, &adapter->state);
retval = pci_save_state(pdev);
if (retval)
return retval;
if (qlcnic_82xx_check(adapter)) {
if (qlcnic_wol_supported(adapter)) {
pci_enable_wake(pdev, PCI_D3cold, 1);
pci_enable_wake(pdev, PCI_D3hot, 1);
}
}
return 0;
}
static void qlcnic_shutdown(struct pci_dev *pdev)
{
if (__qlcnic_shutdown(pdev))
return;
pci_disable_device(pdev);
}
static int
qlcnic_suspend(struct pci_dev *pdev, pm_message_t state)
{
int retval;
retval = __qlcnic_shutdown(pdev);
if (retval)
return retval;
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int
qlcnic_resume(struct pci_dev *pdev)
{
struct qlcnic_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
int err;
err = pci_enable_device(pdev);
if (err)
return err;
pci_set_power_state(pdev, PCI_D0);
pci_set_master(pdev);
pci_restore_state(pdev);
err = adapter->nic_ops->start_firmware(adapter);
if (err) {
dev_err(&pdev->dev, "failed to start firmware\n");
return err;
}
if (netif_running(netdev)) {
err = qlcnic_up(adapter, netdev);
if (err)
goto done;
qlcnic_restore_indev_addr(netdev, NETDEV_UP);
}
done:
netif_device_attach(netdev);
qlcnic_schedule_work(adapter, qlcnic_fw_poll_work, FW_POLL_DELAY);
return 0;
}
static int qlcnic_open(struct net_device *netdev)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
u32 state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
int err;
if (state == QLCNIC_DEV_FAILED || (state == QLCNIC_DEV_BADBAD)) {
netdev_err(netdev, "Device in FAILED state\n");
return -EIO;
}
netif_carrier_off(netdev);
err = qlcnic_attach(adapter);
if (err)
return err;
err = __qlcnic_up(adapter, netdev);
if (err)
goto err_out;
netif_start_queue(netdev);
return 0;
err_out:
qlcnic_detach(adapter);
return err;
}
static int qlcnic_close(struct net_device *netdev)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
__qlcnic_down(adapter, netdev);
return 0;
}
void qlcnic_alloc_lb_filters_mem(struct qlcnic_adapter *adapter)
{
void *head;
int i;
if (adapter->fhash.fmax && adapter->fhash.fhead)
return;
spin_lock_init(&adapter->mac_learn_lock);
head = kcalloc(QLCNIC_LB_MAX_FILTERS, sizeof(struct hlist_head),
GFP_KERNEL);
if (!head)
return;
adapter->fhash.fmax = QLCNIC_LB_MAX_FILTERS;
adapter->fhash.fhead = head;
for (i = 0; i < adapter->fhash.fmax; i++)
INIT_HLIST_HEAD(&adapter->fhash.fhead[i]);
}
static void qlcnic_free_lb_filters_mem(struct qlcnic_adapter *adapter)
{
if (adapter->fhash.fmax && adapter->fhash.fhead)
kfree(adapter->fhash.fhead);
adapter->fhash.fhead = NULL;
adapter->fhash.fmax = 0;
}
static int qlcnic_check_temp(struct qlcnic_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
u32 temp_state, temp_val, temp = 0;
int rv = 0;
if (qlcnic_82xx_check(adapter))
temp = QLCRD32(adapter, CRB_TEMP_STATE);
temp_state = qlcnic_get_temp_state(temp);
temp_val = qlcnic_get_temp_val(temp);
if (temp_state == QLCNIC_TEMP_PANIC) {
dev_err(&netdev->dev,
"Device temperature %d degrees C exceeds"
" maximum allowed. Hardware has been shut down.\n",
temp_val);
rv = 1;
} else if (temp_state == QLCNIC_TEMP_WARN) {
if (adapter->ahw->temp == QLCNIC_TEMP_NORMAL) {
dev_err(&netdev->dev,
"Device temperature %d degrees C "
"exceeds operating range."
" Immediate action needed.\n",
temp_val);
}
} else {
if (adapter->ahw->temp == QLCNIC_TEMP_WARN) {
dev_info(&netdev->dev,
"Device temperature is now %d degrees C"
" in normal range.\n", temp_val);
}
}
adapter->ahw->temp = temp_state;
return rv;
}
static void qlcnic_tx_timeout(struct net_device *netdev)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
if (test_bit(__QLCNIC_RESETTING, &adapter->state))
return;
dev_err(&netdev->dev, "transmit timeout, resetting.\n");
if (++adapter->tx_timeo_cnt >= QLCNIC_MAX_TX_TIMEOUTS)
adapter->need_fw_reset = 1;
else
adapter->ahw->reset_context = 1;
}
static struct net_device_stats *qlcnic_get_stats(struct net_device *netdev)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct net_device_stats *stats = &netdev->stats;
stats->rx_packets = adapter->stats.rx_pkts + adapter->stats.lro_pkts;
stats->tx_packets = adapter->stats.xmitfinished;
stats->rx_bytes = adapter->stats.rxbytes + adapter->stats.lrobytes;
stats->tx_bytes = adapter->stats.txbytes;
stats->rx_dropped = adapter->stats.rxdropped;
stats->tx_dropped = adapter->stats.txdropped;
return stats;
}
static irqreturn_t qlcnic_clear_legacy_intr(struct qlcnic_adapter *adapter)
{
u32 status;
status = readl(adapter->isr_int_vec);
if (!(status & adapter->ahw->int_vec_bit))
return IRQ_NONE;
status = readl(adapter->crb_int_state_reg);
if (!ISR_LEGACY_INT_TRIGGERED(status))
return IRQ_NONE;
writel(0xffffffff, adapter->tgt_status_reg);
readl(adapter->isr_int_vec);
readl(adapter->isr_int_vec);
return IRQ_HANDLED;
}
static irqreturn_t qlcnic_tmp_intr(int irq, void *data)
{
struct qlcnic_host_sds_ring *sds_ring = data;
struct qlcnic_adapter *adapter = sds_ring->adapter;
if (adapter->flags & QLCNIC_MSIX_ENABLED)
goto done;
else if (adapter->flags & QLCNIC_MSI_ENABLED) {
writel(0xffffffff, adapter->tgt_status_reg);
goto done;
}
if (qlcnic_clear_legacy_intr(adapter) == IRQ_NONE)
return IRQ_NONE;
done:
adapter->ahw->diag_cnt++;
qlcnic_enable_int(sds_ring);
return IRQ_HANDLED;
}
static irqreturn_t qlcnic_intr(int irq, void *data)
{
struct qlcnic_host_sds_ring *sds_ring = data;
struct qlcnic_adapter *adapter = sds_ring->adapter;
if (qlcnic_clear_legacy_intr(adapter) == IRQ_NONE)
return IRQ_NONE;
napi_schedule(&sds_ring->napi);
return IRQ_HANDLED;
}
static irqreturn_t qlcnic_msi_intr(int irq, void *data)
{
struct qlcnic_host_sds_ring *sds_ring = data;
struct qlcnic_adapter *adapter = sds_ring->adapter;
writel(0xffffffff, adapter->tgt_status_reg);
napi_schedule(&sds_ring->napi);
return IRQ_HANDLED;
}
static irqreturn_t qlcnic_msix_intr(int irq, void *data)
{
struct qlcnic_host_sds_ring *sds_ring = data;
napi_schedule(&sds_ring->napi);
return IRQ_HANDLED;
}
static void qlcnic_poll_controller(struct net_device *netdev)
{
int ring;
struct qlcnic_host_sds_ring *sds_ring;
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct qlcnic_recv_context *recv_ctx = adapter->recv_ctx;
disable_irq(adapter->irq);
for (ring = 0; ring < adapter->max_sds_rings; ring++) {
sds_ring = &recv_ctx->sds_rings[ring];
qlcnic_intr(adapter->irq, sds_ring);
}
enable_irq(adapter->irq);
}
static void
qlcnic_idc_debug_info(struct qlcnic_adapter *adapter, u8 encoding)
{
u32 val;
val = adapter->portnum & 0xf;
val |= encoding << 7;
val |= (jiffies - adapter->dev_rst_time) << 8;
QLCWR32(adapter, QLCNIC_CRB_DRV_SCRATCH, val);
adapter->dev_rst_time = jiffies;
}
static int
qlcnic_set_drv_state(struct qlcnic_adapter *adapter, u8 state)
{
u32 val;
WARN_ON(state != QLCNIC_DEV_NEED_RESET &&
state != QLCNIC_DEV_NEED_QUISCENT);
if (qlcnic_api_lock(adapter))
return -EIO;
val = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
if (state == QLCNIC_DEV_NEED_RESET)
QLC_DEV_SET_RST_RDY(val, adapter->portnum);
else if (state == QLCNIC_DEV_NEED_QUISCENT)
QLC_DEV_SET_QSCNT_RDY(val, adapter->portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_STATE, val);
qlcnic_api_unlock(adapter);
return 0;
}
static int
qlcnic_clr_drv_state(struct qlcnic_adapter *adapter)
{
u32 val;
if (qlcnic_api_lock(adapter))
return -EBUSY;
val = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
QLC_DEV_CLR_RST_QSCNT(val, adapter->portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_STATE, val);
qlcnic_api_unlock(adapter);
return 0;
}
static void
qlcnic_clr_all_drv_state(struct qlcnic_adapter *adapter, u8 failed)
{
u32 val;
if (qlcnic_api_lock(adapter))
goto err;
val = QLCRD32(adapter, QLCNIC_CRB_DRV_ACTIVE);
QLC_DEV_CLR_REF_CNT(val, adapter->portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_ACTIVE, val);
if (failed) {
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE, QLCNIC_DEV_FAILED);
dev_info(&adapter->pdev->dev,
"Device state set to Failed. Please Reboot\n");
} else if (!(val & 0x11111111))
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE, QLCNIC_DEV_COLD);
val = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
QLC_DEV_CLR_RST_QSCNT(val, adapter->portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_STATE, val);
qlcnic_api_unlock(adapter);
err:
adapter->fw_fail_cnt = 0;
adapter->flags &= ~QLCNIC_FW_HANG;
clear_bit(__QLCNIC_START_FW, &adapter->state);
clear_bit(__QLCNIC_RESETTING, &adapter->state);
}
static int
qlcnic_check_drv_state(struct qlcnic_adapter *adapter)
{
int act, state, active_mask;
state = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
act = QLCRD32(adapter, QLCNIC_CRB_DRV_ACTIVE);
if (adapter->flags & QLCNIC_FW_RESET_OWNER) {
active_mask = (~(1 << (adapter->ahw->pci_func * 4)));
act = act & active_mask;
}
if (((state & 0x11111111) == (act & 0x11111111)) ||
((act & 0x11111111) == ((state >> 1) & 0x11111111)))
return 0;
else
return 1;
}
static int qlcnic_check_idc_ver(struct qlcnic_adapter *adapter)
{
u32 val = QLCRD32(adapter, QLCNIC_CRB_DRV_IDC_VER);
if (val != QLCNIC_DRV_IDC_VER) {
dev_warn(&adapter->pdev->dev, "IDC Version mismatch, driver's"
" idc ver = %x; reqd = %x\n", QLCNIC_DRV_IDC_VER, val);
}
return 0;
}
static int
qlcnic_can_start_firmware(struct qlcnic_adapter *adapter)
{
u32 val, prev_state;
u8 dev_init_timeo = adapter->dev_init_timeo;
u8 portnum = adapter->portnum;
u8 ret;
if (test_and_clear_bit(__QLCNIC_START_FW, &adapter->state))
return 1;
if (qlcnic_api_lock(adapter))
return -1;
val = QLCRD32(adapter, QLCNIC_CRB_DRV_ACTIVE);
if (!(val & (1 << (portnum * 4)))) {
QLC_DEV_SET_REF_CNT(val, portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_ACTIVE, val);
}
prev_state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
QLCDB(adapter, HW, "Device state = %u\n", prev_state);
switch (prev_state) {
case QLCNIC_DEV_COLD:
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE, QLCNIC_DEV_INITIALIZING);
QLCWR32(adapter, QLCNIC_CRB_DRV_IDC_VER, QLCNIC_DRV_IDC_VER);
qlcnic_idc_debug_info(adapter, 0);
qlcnic_api_unlock(adapter);
return 1;
case QLCNIC_DEV_READY:
ret = qlcnic_check_idc_ver(adapter);
qlcnic_api_unlock(adapter);
return ret;
case QLCNIC_DEV_NEED_RESET:
val = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
QLC_DEV_SET_RST_RDY(val, portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_STATE, val);
break;
case QLCNIC_DEV_NEED_QUISCENT:
val = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
QLC_DEV_SET_QSCNT_RDY(val, portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_STATE, val);
break;
case QLCNIC_DEV_FAILED:
dev_err(&adapter->pdev->dev, "Device in failed state.\n");
qlcnic_api_unlock(adapter);
return -1;
case QLCNIC_DEV_INITIALIZING:
case QLCNIC_DEV_QUISCENT:
break;
}
qlcnic_api_unlock(adapter);
do {
msleep(1000);
prev_state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
if (prev_state == QLCNIC_DEV_QUISCENT)
continue;
} while ((prev_state != QLCNIC_DEV_READY) && --dev_init_timeo);
if (!dev_init_timeo) {
dev_err(&adapter->pdev->dev,
"Waiting for device to initialize timeout\n");
return -1;
}
if (qlcnic_api_lock(adapter))
return -1;
val = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
QLC_DEV_CLR_RST_QSCNT(val, portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_STATE, val);
ret = qlcnic_check_idc_ver(adapter);
qlcnic_api_unlock(adapter);
return ret;
}
static void
qlcnic_fwinit_work(struct work_struct *work)
{
struct qlcnic_adapter *adapter = container_of(work,
struct qlcnic_adapter, fw_work.work);
u32 dev_state = 0xf;
u32 val;
if (qlcnic_api_lock(adapter))
goto err_ret;
dev_state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
if (dev_state == QLCNIC_DEV_QUISCENT ||
dev_state == QLCNIC_DEV_NEED_QUISCENT) {
qlcnic_api_unlock(adapter);
qlcnic_schedule_work(adapter, qlcnic_fwinit_work,
FW_POLL_DELAY * 2);
return;
}
if (adapter->ahw->op_mode == QLCNIC_NON_PRIV_FUNC) {
qlcnic_api_unlock(adapter);
goto wait_npar;
}
if (dev_state == QLCNIC_DEV_INITIALIZING ||
dev_state == QLCNIC_DEV_READY) {
dev_info(&adapter->pdev->dev, "Detected state change from "
"DEV_NEED_RESET, skipping ack check\n");
goto skip_ack_check;
}
if (adapter->fw_wait_cnt++ > adapter->reset_ack_timeo) {
dev_info(&adapter->pdev->dev, "Reset:Failed to get ack %d sec\n",
adapter->reset_ack_timeo);
goto skip_ack_check;
}
if (!qlcnic_check_drv_state(adapter)) {
skip_ack_check:
dev_state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
if (dev_state == QLCNIC_DEV_NEED_RESET) {
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE,
QLCNIC_DEV_INITIALIZING);
set_bit(__QLCNIC_START_FW, &adapter->state);
QLCDB(adapter, DRV, "Restarting fw\n");
qlcnic_idc_debug_info(adapter, 0);
val = QLCRD32(adapter, QLCNIC_CRB_DRV_STATE);
QLC_DEV_SET_RST_RDY(val, adapter->portnum);
QLCWR32(adapter, QLCNIC_CRB_DRV_STATE, val);
}
qlcnic_api_unlock(adapter);
rtnl_lock();
if (adapter->ahw->fw_dump.enable &&
(adapter->flags & QLCNIC_FW_RESET_OWNER)) {
QLCDB(adapter, DRV, "Take FW dump\n");
qlcnic_dump_fw(adapter);
adapter->flags |= QLCNIC_FW_HANG;
}
rtnl_unlock();
adapter->flags &= ~QLCNIC_FW_RESET_OWNER;
if (!adapter->nic_ops->start_firmware(adapter)) {
qlcnic_schedule_work(adapter, qlcnic_attach_work, 0);
adapter->fw_wait_cnt = 0;
return;
}
goto err_ret;
}
qlcnic_api_unlock(adapter);
wait_npar:
dev_state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
QLCDB(adapter, HW, "Func waiting: Device state=%u\n", dev_state);
switch (dev_state) {
case QLCNIC_DEV_READY:
if (!adapter->nic_ops->start_firmware(adapter)) {
qlcnic_schedule_work(adapter, qlcnic_attach_work, 0);
adapter->fw_wait_cnt = 0;
return;
}
case QLCNIC_DEV_FAILED:
break;
default:
qlcnic_schedule_work(adapter,
qlcnic_fwinit_work, FW_POLL_DELAY);
return;
}
err_ret:
dev_err(&adapter->pdev->dev, "Fwinit work failed state=%u "
"fw_wait_cnt=%u\n", dev_state, adapter->fw_wait_cnt);
netif_device_attach(adapter->netdev);
qlcnic_clr_all_drv_state(adapter, 0);
}
static void
qlcnic_detach_work(struct work_struct *work)
{
struct qlcnic_adapter *adapter = container_of(work,
struct qlcnic_adapter, fw_work.work);
struct net_device *netdev = adapter->netdev;
u32 status;
netif_device_detach(netdev);
if (adapter->dev_state == QLCNIC_DEV_NEED_QUISCENT) {
if (netif_running(netdev))
__qlcnic_down(adapter, netdev);
} else
qlcnic_down(adapter, netdev);
status = QLCRD32(adapter, QLCNIC_PEG_HALT_STATUS1);
if (status & QLCNIC_RCODE_FATAL_ERROR) {
dev_err(&adapter->pdev->dev,
"Detaching the device: peg halt status1=0x%x\n",
status);
if (QLCNIC_FWERROR_CODE(status) == QLCNIC_FWERROR_FAN_FAILURE) {
dev_err(&adapter->pdev->dev,
"On board active cooling fan failed. "
"Device has been halted.\n");
dev_err(&adapter->pdev->dev,
"Replace the adapter.\n");
}
goto err_ret;
}
if (adapter->ahw->temp == QLCNIC_TEMP_PANIC) {
dev_err(&adapter->pdev->dev, "Detaching the device: temp=%d\n",
adapter->ahw->temp);
goto err_ret;
}
if (!(adapter->flags & QLCNIC_FW_RESET_OWNER)) {
if (qlcnic_set_drv_state(adapter, adapter->dev_state)) {
dev_err(&adapter->pdev->dev,
"Failed to set driver state,"
"detaching the device.\n");
goto err_ret;
}
}
adapter->fw_wait_cnt = 0;
qlcnic_schedule_work(adapter, qlcnic_fwinit_work, FW_POLL_DELAY);
return;
err_ret:
netif_device_attach(netdev);
qlcnic_clr_all_drv_state(adapter, 1);
}
static void
qlcnic_set_npar_non_operational(struct qlcnic_adapter *adapter)
{
u32 state;
state = QLCRD32(adapter, QLCNIC_CRB_DEV_NPAR_STATE);
if (state == QLCNIC_DEV_NPAR_NON_OPER)
return;
if (qlcnic_api_lock(adapter))
return;
QLCWR32(adapter, QLCNIC_CRB_DEV_NPAR_STATE, QLCNIC_DEV_NPAR_NON_OPER);
qlcnic_api_unlock(adapter);
}
void
qlcnic_dev_request_reset(struct qlcnic_adapter *adapter)
{
u32 state, xg_val = 0, gb_val = 0;
qlcnic_xg_set_xg0_mask(xg_val);
qlcnic_xg_set_xg1_mask(xg_val);
QLCWR32(adapter, QLCNIC_NIU_XG_PAUSE_CTL, xg_val);
qlcnic_gb_set_gb0_mask(gb_val);
qlcnic_gb_set_gb1_mask(gb_val);
qlcnic_gb_set_gb2_mask(gb_val);
qlcnic_gb_set_gb3_mask(gb_val);
QLCWR32(adapter, QLCNIC_NIU_GB_PAUSE_CTL, gb_val);
dev_info(&adapter->pdev->dev, "Pause control frames disabled"
" on all ports\n");
adapter->need_fw_reset = 1;
if (qlcnic_api_lock(adapter))
return;
state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
if (state == QLCNIC_DEV_FAILED || (state == QLCNIC_DEV_BADBAD)) {
netdev_err(adapter->netdev,
"Device is in FAILED state, Please Reboot\n");
qlcnic_api_unlock(adapter);
return;
}
if (state == QLCNIC_DEV_READY) {
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE, QLCNIC_DEV_NEED_RESET);
adapter->flags |= QLCNIC_FW_RESET_OWNER;
QLCDB(adapter, DRV, "NEED_RESET state set\n");
qlcnic_idc_debug_info(adapter, 0);
}
QLCWR32(adapter, QLCNIC_CRB_DEV_NPAR_STATE, QLCNIC_DEV_NPAR_NON_OPER);
qlcnic_api_unlock(adapter);
}
static void
qlcnic_dev_set_npar_ready(struct qlcnic_adapter *adapter)
{
if (qlcnic_api_lock(adapter))
return;
QLCWR32(adapter, QLCNIC_CRB_DEV_NPAR_STATE, QLCNIC_DEV_NPAR_OPER);
QLCDB(adapter, DRV, "NPAR operational state set\n");
qlcnic_api_unlock(adapter);
}
static void
qlcnic_schedule_work(struct qlcnic_adapter *adapter,
work_func_t func, int delay)
{
if (test_bit(__QLCNIC_AER, &adapter->state))
return;
INIT_DELAYED_WORK(&adapter->fw_work, func);
queue_delayed_work(qlcnic_wq, &adapter->fw_work,
round_jiffies_relative(delay));
}
static void
qlcnic_cancel_fw_work(struct qlcnic_adapter *adapter)
{
while (test_and_set_bit(__QLCNIC_RESETTING, &adapter->state))
msleep(10);
if (!adapter->fw_work.work.func)
return;
cancel_delayed_work_sync(&adapter->fw_work);
}
static void
qlcnic_attach_work(struct work_struct *work)
{
struct qlcnic_adapter *adapter = container_of(work,
struct qlcnic_adapter, fw_work.work);
struct net_device *netdev = adapter->netdev;
u32 npar_state;
if (adapter->ahw->op_mode != QLCNIC_MGMT_FUNC) {
npar_state = QLCRD32(adapter, QLCNIC_CRB_DEV_NPAR_STATE);
if (adapter->fw_wait_cnt++ > QLCNIC_DEV_NPAR_OPER_TIMEO)
qlcnic_clr_all_drv_state(adapter, 0);
else if (npar_state != QLCNIC_DEV_NPAR_OPER)
qlcnic_schedule_work(adapter, qlcnic_attach_work,
FW_POLL_DELAY);
else
goto attach;
QLCDB(adapter, DRV, "Waiting for NPAR state to operational\n");
return;
}
attach:
if (netif_running(netdev)) {
if (qlcnic_up(adapter, netdev))
goto done;
qlcnic_restore_indev_addr(netdev, NETDEV_UP);
}
done:
netif_device_attach(netdev);
adapter->fw_fail_cnt = 0;
adapter->flags &= ~QLCNIC_FW_HANG;
clear_bit(__QLCNIC_RESETTING, &adapter->state);
if (!qlcnic_clr_drv_state(adapter))
qlcnic_schedule_work(adapter, qlcnic_fw_poll_work,
FW_POLL_DELAY);
}
static int
qlcnic_check_health(struct qlcnic_adapter *adapter)
{
u32 state = 0, heartbeat;
u32 peg_status;
if (qlcnic_check_temp(adapter))
goto detach;
if (adapter->need_fw_reset)
qlcnic_dev_request_reset(adapter);
state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
if (state == QLCNIC_DEV_NEED_RESET) {
qlcnic_set_npar_non_operational(adapter);
adapter->need_fw_reset = 1;
} else if (state == QLCNIC_DEV_NEED_QUISCENT)
goto detach;
heartbeat = QLCRD32(adapter, QLCNIC_PEG_ALIVE_COUNTER);
if (heartbeat != adapter->heartbeat) {
adapter->heartbeat = heartbeat;
adapter->fw_fail_cnt = 0;
if (adapter->need_fw_reset)
goto detach;
if (adapter->ahw->reset_context && qlcnic_auto_fw_reset) {
qlcnic_reset_hw_context(adapter);
adapter->netdev->trans_start = jiffies;
}
return 0;
}
if (++adapter->fw_fail_cnt < FW_FAIL_THRESH)
return 0;
adapter->flags |= QLCNIC_FW_HANG;
qlcnic_dev_request_reset(adapter);
if (qlcnic_auto_fw_reset)
clear_bit(__QLCNIC_FW_ATTACHED, &adapter->state);
dev_err(&adapter->pdev->dev, "firmware hang detected\n");
dev_err(&adapter->pdev->dev, "Dumping hw/fw registers\n"
"PEG_HALT_STATUS1: 0x%x, PEG_HALT_STATUS2: 0x%x,\n"
"PEG_NET_0_PC: 0x%x, PEG_NET_1_PC: 0x%x,\n"
"PEG_NET_2_PC: 0x%x, PEG_NET_3_PC: 0x%x,\n"
"PEG_NET_4_PC: 0x%x\n",
QLCRD32(adapter, QLCNIC_PEG_HALT_STATUS1),
QLCRD32(adapter, QLCNIC_PEG_HALT_STATUS2),
QLCRD32(adapter, QLCNIC_CRB_PEG_NET_0 + 0x3c),
QLCRD32(adapter, QLCNIC_CRB_PEG_NET_1 + 0x3c),
QLCRD32(adapter, QLCNIC_CRB_PEG_NET_2 + 0x3c),
QLCRD32(adapter, QLCNIC_CRB_PEG_NET_3 + 0x3c),
QLCRD32(adapter, QLCNIC_CRB_PEG_NET_4 + 0x3c));
peg_status = QLCRD32(adapter, QLCNIC_PEG_HALT_STATUS1);
if (QLCNIC_FWERROR_CODE(peg_status) == 0x67)
dev_err(&adapter->pdev->dev,
"Firmware aborted with error code 0x00006700. "
"Device is being reset.\n");
detach:
adapter->dev_state = (state == QLCNIC_DEV_NEED_QUISCENT) ? state :
QLCNIC_DEV_NEED_RESET;
if (qlcnic_auto_fw_reset && !test_and_set_bit(__QLCNIC_RESETTING,
&adapter->state)) {
qlcnic_schedule_work(adapter, qlcnic_detach_work, 0);
QLCDB(adapter, DRV, "fw recovery scheduled.\n");
}
return 1;
}
static void
qlcnic_fw_poll_work(struct work_struct *work)
{
struct qlcnic_adapter *adapter = container_of(work,
struct qlcnic_adapter, fw_work.work);
if (test_bit(__QLCNIC_RESETTING, &adapter->state))
goto reschedule;
if (qlcnic_check_health(adapter))
return;
if (adapter->fhash.fnum)
qlcnic_prune_lb_filters(adapter);
reschedule:
qlcnic_schedule_work(adapter, qlcnic_fw_poll_work, FW_POLL_DELAY);
}
static int qlcnic_is_first_func(struct pci_dev *pdev)
{
struct pci_dev *oth_pdev;
int val = pdev->devfn;
while (val-- > 0) {
oth_pdev = pci_get_domain_bus_and_slot(pci_domain_nr
(pdev->bus), pdev->bus->number,
PCI_DEVFN(PCI_SLOT(pdev->devfn), val));
if (!oth_pdev)
continue;
if (oth_pdev->current_state != PCI_D3cold) {
pci_dev_put(oth_pdev);
return 0;
}
pci_dev_put(oth_pdev);
}
return 1;
}
static int qlcnic_attach_func(struct pci_dev *pdev)
{
int err, first_func;
struct qlcnic_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
pdev->error_state = pci_channel_io_normal;
err = pci_enable_device(pdev);
if (err)
return err;
pci_set_power_state(pdev, PCI_D0);
pci_set_master(pdev);
pci_restore_state(pdev);
first_func = qlcnic_is_first_func(pdev);
if (qlcnic_api_lock(adapter))
return -EINVAL;
if (adapter->ahw->op_mode != QLCNIC_NON_PRIV_FUNC && first_func) {
adapter->need_fw_reset = 1;
set_bit(__QLCNIC_START_FW, &adapter->state);
QLCWR32(adapter, QLCNIC_CRB_DEV_STATE, QLCNIC_DEV_INITIALIZING);
QLCDB(adapter, DRV, "Restarting fw\n");
}
qlcnic_api_unlock(adapter);
err = adapter->nic_ops->start_firmware(adapter);
if (err)
return err;
qlcnic_clr_drv_state(adapter);
qlcnic_setup_intr(adapter);
if (netif_running(netdev)) {
err = qlcnic_attach(adapter);
if (err) {
qlcnic_clr_all_drv_state(adapter, 1);
clear_bit(__QLCNIC_AER, &adapter->state);
netif_device_attach(netdev);
return err;
}
err = qlcnic_up(adapter, netdev);
if (err)
goto done;
qlcnic_restore_indev_addr(netdev, NETDEV_UP);
}
done:
netif_device_attach(netdev);
return err;
}
static pci_ers_result_t qlcnic_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct qlcnic_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (state == pci_channel_io_normal)
return PCI_ERS_RESULT_RECOVERED;
set_bit(__QLCNIC_AER, &adapter->state);
netif_device_detach(netdev);
cancel_delayed_work_sync(&adapter->fw_work);
if (netif_running(netdev))
qlcnic_down(adapter, netdev);
qlcnic_detach(adapter);
qlcnic_teardown_intr(adapter);
clear_bit(__QLCNIC_RESETTING, &adapter->state);
pci_save_state(pdev);
pci_disable_device(pdev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t qlcnic_io_slot_reset(struct pci_dev *pdev)
{
return qlcnic_attach_func(pdev) ? PCI_ERS_RESULT_DISCONNECT :
PCI_ERS_RESULT_RECOVERED;
}
static void qlcnic_io_resume(struct pci_dev *pdev)
{
struct qlcnic_adapter *adapter = pci_get_drvdata(pdev);
pci_cleanup_aer_uncorrect_error_status(pdev);
if (QLCRD32(adapter, QLCNIC_CRB_DEV_STATE) == QLCNIC_DEV_READY &&
test_and_clear_bit(__QLCNIC_AER, &adapter->state))
qlcnic_schedule_work(adapter, qlcnic_fw_poll_work,
FW_POLL_DELAY);
}
static int
qlcnicvf_start_firmware(struct qlcnic_adapter *adapter)
{
int err;
err = qlcnic_can_start_firmware(adapter);
if (err)
return err;
err = qlcnic_check_npar_opertional(adapter);
if (err)
return err;
err = qlcnic_initialize_nic(adapter);
if (err)
return err;
qlcnic_check_options(adapter);
err = qlcnic_set_eswitch_port_config(adapter);
if (err)
return err;
adapter->need_fw_reset = 0;
return err;
}
int qlcnic_validate_max_rss(struct net_device *netdev, u8 max_hw, u8 val)
{
if (!qlcnic_use_msi_x && !qlcnic_use_msi) {
netdev_info(netdev, "no msix or msi support, hence no rss\n");
return -EINVAL;
}
if ((val > max_hw) || (val < 2) || !is_power_of_2(val)) {
netdev_info(netdev, "rss_ring valid range [2 - %x] in "
" powers of 2\n", max_hw);
return -EINVAL;
}
return 0;
}
int qlcnic_set_max_rss(struct qlcnic_adapter *adapter, u8 data)
{
struct net_device *netdev = adapter->netdev;
int err = 0;
if (test_and_set_bit(__QLCNIC_RESETTING, &adapter->state))
return -EBUSY;
netif_device_detach(netdev);
if (netif_running(netdev))
__qlcnic_down(adapter, netdev);
qlcnic_detach(adapter);
qlcnic_teardown_intr(adapter);
if (qlcnic_enable_msix(adapter, data)) {
netdev_info(netdev, "failed setting max_rss; rss disabled\n");
qlcnic_enable_msi_legacy(adapter);
}
if (netif_running(netdev)) {
err = qlcnic_attach(adapter);
if (err)
goto done;
err = __qlcnic_up(adapter, netdev);
if (err)
goto done;
qlcnic_restore_indev_addr(netdev, NETDEV_UP);
}
done:
netif_device_attach(netdev);
clear_bit(__QLCNIC_RESETTING, &adapter->state);
return err;
}
static void
qlcnic_config_indev_addr(struct qlcnic_adapter *adapter,
struct net_device *dev, unsigned long event)
{
struct in_device *indev;
indev = in_dev_get(dev);
if (!indev)
return;
for_ifa(indev) {
switch (event) {
case NETDEV_UP:
qlcnic_config_ipaddr(adapter,
ifa->ifa_address, QLCNIC_IP_UP);
break;
case NETDEV_DOWN:
qlcnic_config_ipaddr(adapter,
ifa->ifa_address, QLCNIC_IP_DOWN);
break;
default:
break;
}
} endfor_ifa(indev);
in_dev_put(indev);
}
static void
qlcnic_restore_indev_addr(struct net_device *netdev, unsigned long event)
{
struct qlcnic_adapter *adapter = netdev_priv(netdev);
struct net_device *dev;
u16 vid;
qlcnic_config_indev_addr(adapter, netdev, event);
for_each_set_bit(vid, adapter->vlans, VLAN_N_VID) {
dev = __vlan_find_dev_deep(netdev, vid);
if (!dev)
continue;
qlcnic_config_indev_addr(adapter, dev, event);
}
}
static int qlcnic_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct qlcnic_adapter *adapter;
struct net_device *dev = (struct net_device *)ptr;
recheck:
if (dev == NULL)
goto done;
if (dev->priv_flags & IFF_802_1Q_VLAN) {
dev = vlan_dev_real_dev(dev);
goto recheck;
}
if (!is_qlcnic_netdev(dev))
goto done;
adapter = netdev_priv(dev);
if (!adapter)
goto done;
if (!test_bit(__QLCNIC_DEV_UP, &adapter->state))
goto done;
qlcnic_config_indev_addr(adapter, dev, event);
done:
return NOTIFY_DONE;
}
static int
qlcnic_inetaddr_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct qlcnic_adapter *adapter;
struct net_device *dev;
struct in_ifaddr *ifa = (struct in_ifaddr *)ptr;
dev = ifa->ifa_dev ? ifa->ifa_dev->dev : NULL;
recheck:
if (dev == NULL)
goto done;
if (dev->priv_flags & IFF_802_1Q_VLAN) {
dev = vlan_dev_real_dev(dev);
goto recheck;
}
if (!is_qlcnic_netdev(dev))
goto done;
adapter = netdev_priv(dev);
if (!adapter)
goto done;
if (!test_bit(__QLCNIC_DEV_UP, &adapter->state))
goto done;
switch (event) {
case NETDEV_UP:
qlcnic_config_ipaddr(adapter, ifa->ifa_address, QLCNIC_IP_UP);
break;
case NETDEV_DOWN:
qlcnic_config_ipaddr(adapter, ifa->ifa_address, QLCNIC_IP_DOWN);
break;
default:
break;
}
done:
return NOTIFY_DONE;
}
static void
qlcnic_restore_indev_addr(struct net_device *dev, unsigned long event)
{ }
static int __init qlcnic_init_module(void)
{
int ret;
printk(KERN_INFO "%s\n", qlcnic_driver_string);
qlcnic_wq = create_singlethread_workqueue("qlcnic");
if (qlcnic_wq == NULL) {
printk(KERN_ERR "qlcnic: cannot create workqueue\n");
return -ENOMEM;
}
#ifdef CONFIG_INET
register_netdevice_notifier(&qlcnic_netdev_cb);
register_inetaddr_notifier(&qlcnic_inetaddr_cb);
#endif
ret = pci_register_driver(&qlcnic_driver);
if (ret) {
#ifdef CONFIG_INET
unregister_inetaddr_notifier(&qlcnic_inetaddr_cb);
unregister_netdevice_notifier(&qlcnic_netdev_cb);
#endif
destroy_workqueue(qlcnic_wq);
}
return ret;
}
static void __exit qlcnic_exit_module(void)
{
pci_unregister_driver(&qlcnic_driver);
#ifdef CONFIG_INET
unregister_inetaddr_notifier(&qlcnic_inetaddr_cb);
unregister_netdevice_notifier(&qlcnic_netdev_cb);
#endif
destroy_workqueue(qlcnic_wq);
}
