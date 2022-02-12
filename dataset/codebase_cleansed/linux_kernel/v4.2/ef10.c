static int efx_ef10_get_warm_boot_count(struct efx_nic *efx)
{
efx_dword_t reg;
efx_readd(efx, &reg, ER_DZ_BIU_MC_SFT_STATUS);
return EFX_DWORD_FIELD(reg, EFX_WORD_1) == 0xb007 ?
EFX_DWORD_FIELD(reg, EFX_WORD_0) : -EIO;
}
static unsigned int efx_ef10_mem_map_size(struct efx_nic *efx)
{
int bar;
bar = efx->type->mem_bar;
return resource_size(&efx->pci_dev->resource[bar]);
}
static bool efx_ef10_is_vf(struct efx_nic *efx)
{
return efx->type->is_vf;
}
static int efx_ef10_get_pf_index(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(outbuf, MC_CMD_GET_FUNCTION_INFO_OUT_LEN);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
size_t outlen;
int rc;
rc = efx_mcdi_rpc(efx, MC_CMD_GET_FUNCTION_INFO, NULL, 0, outbuf,
sizeof(outbuf), &outlen);
if (rc)
return rc;
if (outlen < sizeof(outbuf))
return -EIO;
nic_data->pf_index = MCDI_DWORD(outbuf, GET_FUNCTION_INFO_OUT_PF);
return 0;
}
static int efx_ef10_get_vf_index(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(outbuf, MC_CMD_GET_FUNCTION_INFO_OUT_LEN);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
size_t outlen;
int rc;
rc = efx_mcdi_rpc(efx, MC_CMD_GET_FUNCTION_INFO, NULL, 0, outbuf,
sizeof(outbuf), &outlen);
if (rc)
return rc;
if (outlen < sizeof(outbuf))
return -EIO;
nic_data->vf_index = MCDI_DWORD(outbuf, GET_FUNCTION_INFO_OUT_VF);
return 0;
}
static int efx_ef10_init_datapath_caps(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(outbuf, MC_CMD_GET_CAPABILITIES_OUT_LEN);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
size_t outlen;
int rc;
BUILD_BUG_ON(MC_CMD_GET_CAPABILITIES_IN_LEN != 0);
rc = efx_mcdi_rpc(efx, MC_CMD_GET_CAPABILITIES, NULL, 0,
outbuf, sizeof(outbuf), &outlen);
if (rc)
return rc;
if (outlen < sizeof(outbuf)) {
netif_err(efx, drv, efx->net_dev,
"unable to read datapath firmware capabilities\n");
return -EIO;
}
nic_data->datapath_caps =
MCDI_DWORD(outbuf, GET_CAPABILITIES_OUT_FLAGS1);
nic_data->rx_dpcpu_fw_id =
MCDI_WORD(outbuf, GET_CAPABILITIES_OUT_RX_DPCPU_FW_ID);
nic_data->tx_dpcpu_fw_id =
MCDI_WORD(outbuf, GET_CAPABILITIES_OUT_TX_DPCPU_FW_ID);
if (!(nic_data->datapath_caps &
(1 << MC_CMD_GET_CAPABILITIES_OUT_TX_TSO_LBN))) {
netif_err(efx, drv, efx->net_dev,
"current firmware does not support TSO\n");
return -ENODEV;
}
if (!(nic_data->datapath_caps &
(1 << MC_CMD_GET_CAPABILITIES_OUT_RX_PREFIX_LEN_14_LBN))) {
netif_err(efx, probe, efx->net_dev,
"current firmware does not support an RX prefix\n");
return -ENODEV;
}
return 0;
}
static int efx_ef10_get_sysclk_freq(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(outbuf, MC_CMD_GET_CLOCK_OUT_LEN);
int rc;
rc = efx_mcdi_rpc(efx, MC_CMD_GET_CLOCK, NULL, 0,
outbuf, sizeof(outbuf), NULL);
if (rc)
return rc;
rc = MCDI_DWORD(outbuf, GET_CLOCK_OUT_SYS_FREQ);
return rc > 0 ? rc : -ERANGE;
}
static int efx_ef10_get_mac_address_pf(struct efx_nic *efx, u8 *mac_address)
{
MCDI_DECLARE_BUF(outbuf, MC_CMD_GET_MAC_ADDRESSES_OUT_LEN);
size_t outlen;
int rc;
BUILD_BUG_ON(MC_CMD_GET_MAC_ADDRESSES_IN_LEN != 0);
rc = efx_mcdi_rpc(efx, MC_CMD_GET_MAC_ADDRESSES, NULL, 0,
outbuf, sizeof(outbuf), &outlen);
if (rc)
return rc;
if (outlen < MC_CMD_GET_MAC_ADDRESSES_OUT_LEN)
return -EIO;
ether_addr_copy(mac_address,
MCDI_PTR(outbuf, GET_MAC_ADDRESSES_OUT_MAC_ADDR_BASE));
return 0;
}
static int efx_ef10_get_mac_address_vf(struct efx_nic *efx, u8 *mac_address)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_VPORT_GET_MAC_ADDRESSES_IN_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_LENMAX);
size_t outlen;
int num_addrs, rc;
MCDI_SET_DWORD(inbuf, VPORT_GET_MAC_ADDRESSES_IN_VPORT_ID,
EVB_PORT_ID_ASSIGNED);
rc = efx_mcdi_rpc(efx, MC_CMD_VPORT_GET_MAC_ADDRESSES, inbuf,
sizeof(inbuf), outbuf, sizeof(outbuf), &outlen);
if (rc)
return rc;
if (outlen < MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_LENMIN)
return -EIO;
num_addrs = MCDI_DWORD(outbuf,
VPORT_GET_MAC_ADDRESSES_OUT_MACADDR_COUNT);
WARN_ON(num_addrs != 1);
ether_addr_copy(mac_address,
MCDI_PTR(outbuf, VPORT_GET_MAC_ADDRESSES_OUT_MACADDR));
return 0;
}
static ssize_t efx_ef10_show_link_control_flag(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct efx_nic *efx = pci_get_drvdata(to_pci_dev(dev));
return sprintf(buf, "%d\n",
((efx->mcdi->fn_flags) &
(1 << MC_CMD_DRV_ATTACH_EXT_OUT_FLAG_LINKCTRL))
? 1 : 0);
}
static ssize_t efx_ef10_show_primary_flag(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct efx_nic *efx = pci_get_drvdata(to_pci_dev(dev));
return sprintf(buf, "%d\n",
((efx->mcdi->fn_flags) &
(1 << MC_CMD_DRV_ATTACH_EXT_OUT_FLAG_PRIMARY))
? 1 : 0);
}
static int efx_ef10_probe(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data;
struct net_device *net_dev = efx->net_dev;
int i, rc;
efx->max_channels =
min_t(unsigned int,
EFX_MAX_CHANNELS,
efx_ef10_mem_map_size(efx) /
(EFX_VI_PAGE_SIZE * EFX_TXQ_TYPES));
if (WARN_ON(efx->max_channels == 0))
return -EIO;
nic_data = kzalloc(sizeof(*nic_data), GFP_KERNEL);
if (!nic_data)
return -ENOMEM;
efx->nic_data = nic_data;
BUILD_BUG_ON(MCDI_CTL_SDU_LEN_MAX_V2 % 4);
rc = efx_nic_alloc_buffer(efx, &nic_data->mcdi_buf,
8 + MCDI_CTL_SDU_LEN_MAX_V2, GFP_KERNEL);
if (rc)
goto fail1;
i = 0;
for (;;) {
rc = efx_ef10_get_warm_boot_count(efx);
if (rc >= 0)
break;
if (++i == 5)
goto fail2;
ssleep(1);
}
nic_data->warm_boot_count = rc;
nic_data->rx_rss_context = EFX_EF10_RSS_CONTEXT_INVALID;
nic_data->vport_id = EVB_PORT_ID_ASSIGNED;
_efx_writed(efx, cpu_to_le32(1), ER_DZ_MC_DB_HWRD);
rc = efx_mcdi_init(efx);
if (rc)
goto fail2;
rc = efx_mcdi_reset(efx, RESET_TYPE_ALL);
if (rc)
goto fail3;
rc = efx_mcdi_log_ctrl(efx, true, false, 0);
if (rc)
goto fail3;
rc = device_create_file(&efx->pci_dev->dev,
&dev_attr_link_control_flag);
if (rc)
goto fail3;
rc = device_create_file(&efx->pci_dev->dev, &dev_attr_primary_flag);
if (rc)
goto fail4;
rc = efx_ef10_get_pf_index(efx);
if (rc)
goto fail5;
rc = efx_ef10_init_datapath_caps(efx);
if (rc < 0)
goto fail5;
efx->rx_packet_len_offset =
ES_DZ_RX_PREFIX_PKTLEN_OFST - ES_DZ_RX_PREFIX_SIZE;
rc = efx_mcdi_port_get_number(efx);
if (rc < 0)
goto fail5;
efx->port_num = rc;
net_dev->dev_port = rc;
rc = efx->type->get_mac_address(efx, efx->net_dev->perm_addr);
if (rc)
goto fail5;
rc = efx_ef10_get_sysclk_freq(efx);
if (rc < 0)
goto fail5;
efx->timer_quantum_ns = 1536000 / rc;
rc = efx_mcdi_set_workaround(efx, MC_CMD_WORKAROUND_BUG35388, true);
if (rc == 0) {
nic_data->workaround_35388 = true;
} else if (rc == -EPERM) {
unsigned int enabled;
rc = efx_mcdi_get_workarounds(efx, NULL, &enabled);
if (rc)
goto fail3;
nic_data->workaround_35388 = enabled &
MC_CMD_GET_WORKAROUNDS_OUT_BUG35388;
} else if (rc != -ENOSYS && rc != -ENOENT) {
goto fail5;
}
netif_dbg(efx, probe, efx->net_dev,
"workaround for bug 35388 is %sabled\n",
nic_data->workaround_35388 ? "en" : "dis");
rc = efx_mcdi_mon_probe(efx);
if (rc && rc != -EPERM)
goto fail5;
efx_ptp_probe(efx, NULL);
#ifdef CONFIG_SFC_SRIOV
if ((efx->pci_dev->physfn) && (!efx->pci_dev->is_physfn)) {
struct pci_dev *pci_dev_pf = efx->pci_dev->physfn;
struct efx_nic *efx_pf = pci_get_drvdata(pci_dev_pf);
efx_pf->type->get_mac_address(efx_pf, nic_data->port_id);
} else
#endif
ether_addr_copy(nic_data->port_id, efx->net_dev->perm_addr);
return 0;
fail5:
device_remove_file(&efx->pci_dev->dev, &dev_attr_primary_flag);
fail4:
device_remove_file(&efx->pci_dev->dev, &dev_attr_link_control_flag);
fail3:
efx_mcdi_fini(efx);
fail2:
efx_nic_free_buffer(efx, &nic_data->mcdi_buf);
fail1:
kfree(nic_data);
efx->nic_data = NULL;
return rc;
}
static int efx_ef10_free_vis(struct efx_nic *efx)
{
MCDI_DECLARE_BUF_ERR(outbuf);
size_t outlen;
int rc = efx_mcdi_rpc_quiet(efx, MC_CMD_FREE_VIS, NULL, 0,
outbuf, sizeof(outbuf), &outlen);
if (rc == -EALREADY)
rc = 0;
if (rc)
efx_mcdi_display_error(efx, MC_CMD_FREE_VIS, 0, outbuf, outlen,
rc);
return rc;
}
static void efx_ef10_free_piobufs(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
MCDI_DECLARE_BUF(inbuf, MC_CMD_FREE_PIOBUF_IN_LEN);
unsigned int i;
int rc;
BUILD_BUG_ON(MC_CMD_FREE_PIOBUF_OUT_LEN != 0);
for (i = 0; i < nic_data->n_piobufs; i++) {
MCDI_SET_DWORD(inbuf, FREE_PIOBUF_IN_PIOBUF_HANDLE,
nic_data->piobuf_handle[i]);
rc = efx_mcdi_rpc(efx, MC_CMD_FREE_PIOBUF, inbuf, sizeof(inbuf),
NULL, 0, NULL);
WARN_ON(rc);
}
nic_data->n_piobufs = 0;
}
static int efx_ef10_alloc_piobufs(struct efx_nic *efx, unsigned int n)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
MCDI_DECLARE_BUF(outbuf, MC_CMD_ALLOC_PIOBUF_OUT_LEN);
unsigned int i;
size_t outlen;
int rc = 0;
BUILD_BUG_ON(MC_CMD_ALLOC_PIOBUF_IN_LEN != 0);
for (i = 0; i < n; i++) {
rc = efx_mcdi_rpc(efx, MC_CMD_ALLOC_PIOBUF, NULL, 0,
outbuf, sizeof(outbuf), &outlen);
if (rc)
break;
if (outlen < MC_CMD_ALLOC_PIOBUF_OUT_LEN) {
rc = -EIO;
break;
}
nic_data->piobuf_handle[i] =
MCDI_DWORD(outbuf, ALLOC_PIOBUF_OUT_PIOBUF_HANDLE);
netif_dbg(efx, probe, efx->net_dev,
"allocated PIO buffer %u handle %x\n", i,
nic_data->piobuf_handle[i]);
}
nic_data->n_piobufs = i;
if (rc)
efx_ef10_free_piobufs(efx);
return rc;
}
static int efx_ef10_link_piobufs(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
_MCDI_DECLARE_BUF(inbuf,
max(MC_CMD_LINK_PIOBUF_IN_LEN,
MC_CMD_UNLINK_PIOBUF_IN_LEN));
struct efx_channel *channel;
struct efx_tx_queue *tx_queue;
unsigned int offset, index;
int rc;
BUILD_BUG_ON(MC_CMD_LINK_PIOBUF_OUT_LEN != 0);
BUILD_BUG_ON(MC_CMD_UNLINK_PIOBUF_OUT_LEN != 0);
memset(inbuf, 0, sizeof(inbuf));
for (index = 0; index < nic_data->n_piobufs; ++index) {
MCDI_SET_DWORD(inbuf, LINK_PIOBUF_IN_PIOBUF_HANDLE,
nic_data->piobuf_handle[index]);
MCDI_SET_DWORD(inbuf, LINK_PIOBUF_IN_TXQ_INSTANCE,
nic_data->pio_write_vi_base + index);
rc = efx_mcdi_rpc(efx, MC_CMD_LINK_PIOBUF,
inbuf, MC_CMD_LINK_PIOBUF_IN_LEN,
NULL, 0, NULL);
if (rc) {
netif_err(efx, drv, efx->net_dev,
"failed to link VI %u to PIO buffer %u (%d)\n",
nic_data->pio_write_vi_base + index, index,
rc);
goto fail;
}
netif_dbg(efx, probe, efx->net_dev,
"linked VI %u to PIO buffer %u\n",
nic_data->pio_write_vi_base + index, index);
}
efx_for_each_channel(channel, efx) {
efx_for_each_channel_tx_queue(tx_queue, channel) {
offset = ((efx->tx_channel_offset + efx->n_tx_channels -
tx_queue->channel->channel - 1) *
efx_piobuf_size);
index = offset / ER_DZ_TX_PIOBUF_SIZE;
offset = offset % ER_DZ_TX_PIOBUF_SIZE;
if (tx_queue->queue == nic_data->pio_write_vi_base) {
BUG_ON(index != 0);
rc = 0;
} else {
MCDI_SET_DWORD(inbuf,
LINK_PIOBUF_IN_PIOBUF_HANDLE,
nic_data->piobuf_handle[index]);
MCDI_SET_DWORD(inbuf,
LINK_PIOBUF_IN_TXQ_INSTANCE,
tx_queue->queue);
rc = efx_mcdi_rpc(efx, MC_CMD_LINK_PIOBUF,
inbuf, MC_CMD_LINK_PIOBUF_IN_LEN,
NULL, 0, NULL);
}
if (rc) {
netif_err(efx, drv, efx->net_dev,
"failed to link VI %u to PIO buffer %u (%d)\n",
tx_queue->queue, index, rc);
tx_queue->piobuf = NULL;
} else {
tx_queue->piobuf =
nic_data->pio_write_base +
index * EFX_VI_PAGE_SIZE + offset;
tx_queue->piobuf_offset = offset;
netif_dbg(efx, probe, efx->net_dev,
"linked VI %u to PIO buffer %u offset %x addr %p\n",
tx_queue->queue, index,
tx_queue->piobuf_offset,
tx_queue->piobuf);
}
}
}
return 0;
fail:
while (index--) {
MCDI_SET_DWORD(inbuf, UNLINK_PIOBUF_IN_TXQ_INSTANCE,
nic_data->pio_write_vi_base + index);
efx_mcdi_rpc(efx, MC_CMD_UNLINK_PIOBUF,
inbuf, MC_CMD_UNLINK_PIOBUF_IN_LEN,
NULL, 0, NULL);
}
return rc;
}
static int efx_ef10_alloc_piobufs(struct efx_nic *efx, unsigned int n)
{
return n == 0 ? 0 : -ENOBUFS;
}
static int efx_ef10_link_piobufs(struct efx_nic *efx)
{
return 0;
}
static void efx_ef10_free_piobufs(struct efx_nic *efx)
{
}
static void efx_ef10_remove(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
int rc;
#ifdef CONFIG_SFC_SRIOV
struct efx_ef10_nic_data *nic_data_pf;
struct pci_dev *pci_dev_pf;
struct efx_nic *efx_pf;
struct ef10_vf *vf;
if (efx->pci_dev->is_virtfn) {
pci_dev_pf = efx->pci_dev->physfn;
if (pci_dev_pf) {
efx_pf = pci_get_drvdata(pci_dev_pf);
nic_data_pf = efx_pf->nic_data;
vf = nic_data_pf->vf + nic_data->vf_index;
vf->efx = NULL;
} else
netif_info(efx, drv, efx->net_dev,
"Could not get the PF id from VF\n");
}
#endif
efx_ptp_remove(efx);
efx_mcdi_mon_remove(efx);
efx_ef10_rx_free_indir_table(efx);
if (nic_data->wc_membase)
iounmap(nic_data->wc_membase);
rc = efx_ef10_free_vis(efx);
WARN_ON(rc != 0);
if (!nic_data->must_restore_piobufs)
efx_ef10_free_piobufs(efx);
device_remove_file(&efx->pci_dev->dev, &dev_attr_primary_flag);
device_remove_file(&efx->pci_dev->dev, &dev_attr_link_control_flag);
efx_mcdi_fini(efx);
efx_nic_free_buffer(efx, &nic_data->mcdi_buf);
kfree(nic_data);
}
static int efx_ef10_probe_pf(struct efx_nic *efx)
{
return efx_ef10_probe(efx);
}
int efx_ef10_vadaptor_alloc(struct efx_nic *efx, unsigned int port_id)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_VADAPTOR_ALLOC_IN_LEN);
MCDI_SET_DWORD(inbuf, VADAPTOR_ALLOC_IN_UPSTREAM_PORT_ID, port_id);
return efx_mcdi_rpc(efx, MC_CMD_VADAPTOR_ALLOC, inbuf, sizeof(inbuf),
NULL, 0, NULL);
}
int efx_ef10_vadaptor_free(struct efx_nic *efx, unsigned int port_id)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_VADAPTOR_FREE_IN_LEN);
MCDI_SET_DWORD(inbuf, VADAPTOR_FREE_IN_UPSTREAM_PORT_ID, port_id);
return efx_mcdi_rpc(efx, MC_CMD_VADAPTOR_FREE, inbuf, sizeof(inbuf),
NULL, 0, NULL);
}
int efx_ef10_vport_add_mac(struct efx_nic *efx,
unsigned int port_id, u8 *mac)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_VPORT_ADD_MAC_ADDRESS_IN_LEN);
MCDI_SET_DWORD(inbuf, VPORT_ADD_MAC_ADDRESS_IN_VPORT_ID, port_id);
ether_addr_copy(MCDI_PTR(inbuf, VPORT_ADD_MAC_ADDRESS_IN_MACADDR), mac);
return efx_mcdi_rpc(efx, MC_CMD_VPORT_ADD_MAC_ADDRESS, inbuf,
sizeof(inbuf), NULL, 0, NULL);
}
int efx_ef10_vport_del_mac(struct efx_nic *efx,
unsigned int port_id, u8 *mac)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_VPORT_DEL_MAC_ADDRESS_IN_LEN);
MCDI_SET_DWORD(inbuf, VPORT_DEL_MAC_ADDRESS_IN_VPORT_ID, port_id);
ether_addr_copy(MCDI_PTR(inbuf, VPORT_DEL_MAC_ADDRESS_IN_MACADDR), mac);
return efx_mcdi_rpc(efx, MC_CMD_VPORT_DEL_MAC_ADDRESS, inbuf,
sizeof(inbuf), NULL, 0, NULL);
}
static int efx_ef10_probe_vf(struct efx_nic *efx)
{
int rc;
struct pci_dev *pci_dev_pf;
pci_dev_pf = efx->pci_dev->physfn;
if (pci_dev_pf) {
struct efx_nic *efx_pf = pci_get_drvdata(pci_dev_pf);
struct efx_ef10_nic_data *nic_data_pf = efx_pf->nic_data;
if (!nic_data_pf->vf) {
netif_info(efx, drv, efx->net_dev,
"The VF cannot link to its parent PF; "
"please destroy and re-create the VF\n");
return -EBUSY;
}
}
rc = efx_ef10_probe(efx);
if (rc)
return rc;
rc = efx_ef10_get_vf_index(efx);
if (rc)
goto fail;
if (efx->pci_dev->is_virtfn) {
if (efx->pci_dev->physfn) {
struct efx_nic *efx_pf =
pci_get_drvdata(efx->pci_dev->physfn);
struct efx_ef10_nic_data *nic_data_p = efx_pf->nic_data;
struct efx_ef10_nic_data *nic_data = efx->nic_data;
nic_data_p->vf[nic_data->vf_index].efx = efx;
nic_data_p->vf[nic_data->vf_index].pci_dev =
efx->pci_dev;
} else
netif_info(efx, drv, efx->net_dev,
"Could not get the PF id from VF\n");
}
return 0;
fail:
efx_ef10_remove(efx);
return rc;
}
static int efx_ef10_alloc_vis(struct efx_nic *efx,
unsigned int min_vis, unsigned int max_vis)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_ALLOC_VIS_IN_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_ALLOC_VIS_OUT_LEN);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
size_t outlen;
int rc;
MCDI_SET_DWORD(inbuf, ALLOC_VIS_IN_MIN_VI_COUNT, min_vis);
MCDI_SET_DWORD(inbuf, ALLOC_VIS_IN_MAX_VI_COUNT, max_vis);
rc = efx_mcdi_rpc(efx, MC_CMD_ALLOC_VIS, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), &outlen);
if (rc != 0)
return rc;
if (outlen < MC_CMD_ALLOC_VIS_OUT_LEN)
return -EIO;
netif_dbg(efx, drv, efx->net_dev, "base VI is A0x%03x\n",
MCDI_DWORD(outbuf, ALLOC_VIS_OUT_VI_BASE));
nic_data->vi_base = MCDI_DWORD(outbuf, ALLOC_VIS_OUT_VI_BASE);
nic_data->n_allocated_vis = MCDI_DWORD(outbuf, ALLOC_VIS_OUT_VI_COUNT);
return 0;
}
static int efx_ef10_dimension_resources(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
unsigned int uc_mem_map_size, wc_mem_map_size;
unsigned int min_vis, pio_write_vi_base, max_vis;
void __iomem *membase;
int rc;
min_vis = max(efx->n_channels, efx->n_tx_channels * EFX_TXQ_TYPES);
#ifdef EFX_USE_PIO
if (efx_piobuf_size != 0 &&
ER_DZ_TX_PIOBUF_SIZE / efx_piobuf_size * EF10_TX_PIOBUF_COUNT >=
efx->n_tx_channels) {
unsigned int n_piobufs =
DIV_ROUND_UP(efx->n_tx_channels,
ER_DZ_TX_PIOBUF_SIZE / efx_piobuf_size);
rc = efx_ef10_alloc_piobufs(efx, n_piobufs);
if (rc)
netif_err(efx, probe, efx->net_dev,
"failed to allocate PIO buffers (%d)\n", rc);
else
netif_dbg(efx, probe, efx->net_dev,
"allocated %u PIO buffers\n", n_piobufs);
}
#else
nic_data->n_piobufs = 0;
#endif
uc_mem_map_size = PAGE_ALIGN((min_vis - 1) * EFX_VI_PAGE_SIZE +
ER_DZ_TX_PIOBUF);
if (nic_data->n_piobufs) {
pio_write_vi_base = uc_mem_map_size / EFX_VI_PAGE_SIZE;
wc_mem_map_size = (PAGE_ALIGN((pio_write_vi_base +
nic_data->n_piobufs) *
EFX_VI_PAGE_SIZE) -
uc_mem_map_size);
max_vis = pio_write_vi_base + nic_data->n_piobufs;
} else {
pio_write_vi_base = 0;
wc_mem_map_size = 0;
max_vis = min_vis;
}
rc = efx_ef10_free_vis(efx);
if (rc != 0)
return rc;
rc = efx_ef10_alloc_vis(efx, min_vis, max_vis);
if (rc != 0)
return rc;
if (nic_data->n_piobufs &&
nic_data->n_allocated_vis <
pio_write_vi_base + nic_data->n_piobufs) {
netif_dbg(efx, probe, efx->net_dev,
"%u VIs are not sufficient to map %u PIO buffers\n",
nic_data->n_allocated_vis, nic_data->n_piobufs);
efx_ef10_free_piobufs(efx);
}
membase = ioremap_nocache(efx->membase_phys, uc_mem_map_size);
if (!membase) {
netif_err(efx, probe, efx->net_dev,
"could not shrink memory BAR to %x\n",
uc_mem_map_size);
return -ENOMEM;
}
iounmap(efx->membase);
efx->membase = membase;
if (wc_mem_map_size) {
nic_data->wc_membase = ioremap_wc(efx->membase_phys +
uc_mem_map_size,
wc_mem_map_size);
if (!nic_data->wc_membase) {
netif_err(efx, probe, efx->net_dev,
"could not allocate WC mapping of size %x\n",
wc_mem_map_size);
return -ENOMEM;
}
nic_data->pio_write_vi_base = pio_write_vi_base;
nic_data->pio_write_base =
nic_data->wc_membase +
(pio_write_vi_base * EFX_VI_PAGE_SIZE + ER_DZ_TX_PIOBUF -
uc_mem_map_size);
rc = efx_ef10_link_piobufs(efx);
if (rc)
efx_ef10_free_piobufs(efx);
}
netif_dbg(efx, probe, efx->net_dev,
"memory BAR at %pa (virtual %p+%x UC, %p+%x WC)\n",
&efx->membase_phys, efx->membase, uc_mem_map_size,
nic_data->wc_membase, wc_mem_map_size);
return 0;
}
static int efx_ef10_init_nic(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
int rc;
if (nic_data->must_check_datapath_caps) {
rc = efx_ef10_init_datapath_caps(efx);
if (rc)
return rc;
nic_data->must_check_datapath_caps = false;
}
if (nic_data->must_realloc_vis) {
rc = efx_ef10_alloc_vis(efx, nic_data->n_allocated_vis,
nic_data->n_allocated_vis);
if (rc)
return rc;
nic_data->must_realloc_vis = false;
}
if (nic_data->must_restore_piobufs && nic_data->n_piobufs) {
rc = efx_ef10_alloc_piobufs(efx, nic_data->n_piobufs);
if (rc == 0) {
rc = efx_ef10_link_piobufs(efx);
if (rc)
efx_ef10_free_piobufs(efx);
}
if (rc)
netif_err(efx, drv, efx->net_dev,
"failed to restore PIO buffers (%d)\n", rc);
nic_data->must_restore_piobufs = false;
}
efx->type->rx_push_rss_config(efx, false, efx->rx_indir_table);
return 0;
}
static void efx_ef10_reset_mc_allocations(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
nic_data->must_realloc_vis = true;
nic_data->must_restore_filters = true;
nic_data->must_restore_piobufs = true;
nic_data->rx_rss_context = EFX_EF10_RSS_CONTEXT_INVALID;
}
static enum reset_type efx_ef10_map_reset_reason(enum reset_type reason)
{
if (reason == RESET_TYPE_MC_FAILURE)
return RESET_TYPE_DATAPATH;
return efx_mcdi_map_reset_reason(reason);
}
static int efx_ef10_map_reset_flags(u32 *flags)
{
enum {
EF10_RESET_PORT = ((ETH_RESET_MAC | ETH_RESET_PHY) <<
ETH_RESET_SHARED_SHIFT),
EF10_RESET_MC = ((ETH_RESET_DMA | ETH_RESET_FILTER |
ETH_RESET_OFFLOAD | ETH_RESET_MAC |
ETH_RESET_PHY | ETH_RESET_MGMT) <<
ETH_RESET_SHARED_SHIFT)
};
if ((*flags & EF10_RESET_MC) == EF10_RESET_MC) {
*flags &= ~EF10_RESET_MC;
return RESET_TYPE_WORLD;
}
if ((*flags & EF10_RESET_PORT) == EF10_RESET_PORT) {
*flags &= ~EF10_RESET_PORT;
return RESET_TYPE_ALL;
}
return -EINVAL;
}
static int efx_ef10_reset(struct efx_nic *efx, enum reset_type reset_type)
{
int rc = efx_mcdi_reset(efx, reset_type);
if ((reset_type == RESET_TYPE_ALL ||
reset_type == RESET_TYPE_MCDI_TIMEOUT) && !rc)
efx_ef10_reset_mc_allocations(efx);
return rc;
}
static u64 efx_ef10_raw_stat_mask(struct efx_nic *efx)
{
u64 raw_mask = HUNT_COMMON_STAT_MASK;
u32 port_caps = efx_mcdi_phy_get_caps(efx);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
if (!(efx->mcdi->fn_flags &
1 << MC_CMD_DRV_ATTACH_EXT_OUT_FLAG_LINKCTRL))
return 0;
if (port_caps & (1 << MC_CMD_PHY_CAP_40000FDX_LBN))
raw_mask |= HUNT_40G_EXTRA_STAT_MASK;
else
raw_mask |= HUNT_10G_ONLY_STAT_MASK;
if (nic_data->datapath_caps &
(1 << MC_CMD_GET_CAPABILITIES_OUT_PM_AND_RXDP_COUNTERS_LBN))
raw_mask |= HUNT_PM_AND_RXDP_STAT_MASK;
return raw_mask;
}
static void efx_ef10_get_stat_mask(struct efx_nic *efx, unsigned long *mask)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
u64 raw_mask[2];
raw_mask[0] = efx_ef10_raw_stat_mask(efx);
if (nic_data->datapath_caps &
(1 << MC_CMD_GET_CAPABILITIES_OUT_EVB_LBN)) {
raw_mask[0] |= ~((1ULL << EF10_STAT_rx_unicast) - 1);
raw_mask[1] = (1ULL << (EF10_STAT_COUNT - 63)) - 1;
} else {
raw_mask[1] = 0;
}
#if BITS_PER_LONG == 64
mask[0] = raw_mask[0];
mask[1] = raw_mask[1];
#else
mask[0] = raw_mask[0] & 0xffffffff;
mask[1] = raw_mask[0] >> 32;
mask[2] = raw_mask[1] & 0xffffffff;
mask[3] = raw_mask[1] >> 32;
#endif
}
static size_t efx_ef10_describe_stats(struct efx_nic *efx, u8 *names)
{
DECLARE_BITMAP(mask, EF10_STAT_COUNT);
efx_ef10_get_stat_mask(efx, mask);
return efx_nic_describe_stats(efx_ef10_stat_desc, EF10_STAT_COUNT,
mask, names);
}
static size_t efx_ef10_update_stats_common(struct efx_nic *efx, u64 *full_stats,
struct rtnl_link_stats64 *core_stats)
{
DECLARE_BITMAP(mask, EF10_STAT_COUNT);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
u64 *stats = nic_data->stats;
size_t stats_count = 0, index;
efx_ef10_get_stat_mask(efx, mask);
if (full_stats) {
for_each_set_bit(index, mask, EF10_STAT_COUNT) {
if (efx_ef10_stat_desc[index].name) {
*full_stats++ = stats[index];
++stats_count;
}
}
}
if (!core_stats)
return stats_count;
if (nic_data->datapath_caps &
1 << MC_CMD_GET_CAPABILITIES_OUT_EVB_LBN) {
core_stats->rx_packets = stats[EF10_STAT_rx_unicast] +
stats[EF10_STAT_rx_multicast] +
stats[EF10_STAT_rx_broadcast];
core_stats->tx_packets = stats[EF10_STAT_tx_unicast] +
stats[EF10_STAT_tx_multicast] +
stats[EF10_STAT_tx_broadcast];
core_stats->rx_bytes = stats[EF10_STAT_rx_unicast_bytes] +
stats[EF10_STAT_rx_multicast_bytes] +
stats[EF10_STAT_rx_broadcast_bytes];
core_stats->tx_bytes = stats[EF10_STAT_tx_unicast_bytes] +
stats[EF10_STAT_tx_multicast_bytes] +
stats[EF10_STAT_tx_broadcast_bytes];
core_stats->rx_dropped = stats[GENERIC_STAT_rx_nodesc_trunc] +
stats[GENERIC_STAT_rx_noskb_drops];
core_stats->multicast = stats[EF10_STAT_rx_multicast];
core_stats->rx_crc_errors = stats[EF10_STAT_rx_bad];
core_stats->rx_fifo_errors = stats[EF10_STAT_rx_overflow];
core_stats->rx_errors = core_stats->rx_crc_errors;
core_stats->tx_errors = stats[EF10_STAT_tx_bad];
} else {
core_stats->rx_packets = stats[EF10_STAT_port_rx_packets];
core_stats->tx_packets = stats[EF10_STAT_port_tx_packets];
core_stats->rx_bytes = stats[EF10_STAT_port_rx_bytes];
core_stats->tx_bytes = stats[EF10_STAT_port_tx_bytes];
core_stats->rx_dropped = stats[EF10_STAT_port_rx_nodesc_drops] +
stats[GENERIC_STAT_rx_nodesc_trunc] +
stats[GENERIC_STAT_rx_noskb_drops];
core_stats->multicast = stats[EF10_STAT_port_rx_multicast];
core_stats->rx_length_errors =
stats[EF10_STAT_port_rx_gtjumbo] +
stats[EF10_STAT_port_rx_length_error];
core_stats->rx_crc_errors = stats[EF10_STAT_port_rx_bad];
core_stats->rx_frame_errors =
stats[EF10_STAT_port_rx_align_error];
core_stats->rx_fifo_errors = stats[EF10_STAT_port_rx_overflow];
core_stats->rx_errors = (core_stats->rx_length_errors +
core_stats->rx_crc_errors +
core_stats->rx_frame_errors);
}
return stats_count;
}
static int efx_ef10_try_update_nic_stats_pf(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
DECLARE_BITMAP(mask, EF10_STAT_COUNT);
__le64 generation_start, generation_end;
u64 *stats = nic_data->stats;
__le64 *dma_stats;
efx_ef10_get_stat_mask(efx, mask);
dma_stats = efx->stats_buffer.addr;
nic_data = efx->nic_data;
generation_end = dma_stats[MC_CMD_MAC_GENERATION_END];
if (generation_end == EFX_MC_STATS_GENERATION_INVALID)
return 0;
rmb();
efx_nic_update_stats(efx_ef10_stat_desc, EF10_STAT_COUNT, mask,
stats, efx->stats_buffer.addr, false);
rmb();
generation_start = dma_stats[MC_CMD_MAC_GENERATION_START];
if (generation_end != generation_start)
return -EAGAIN;
efx_nic_fix_nodesc_drop_stat(efx,
&stats[EF10_STAT_port_rx_nodesc_drops]);
stats[EF10_STAT_port_rx_good_bytes] =
stats[EF10_STAT_port_rx_bytes] -
stats[EF10_STAT_port_rx_bytes_minus_good_bytes];
efx_update_diff_stat(&stats[EF10_STAT_port_rx_bad_bytes],
stats[EF10_STAT_port_rx_bytes_minus_good_bytes]);
efx_update_sw_stats(efx, stats);
return 0;
}
static size_t efx_ef10_update_stats_pf(struct efx_nic *efx, u64 *full_stats,
struct rtnl_link_stats64 *core_stats)
{
int retry;
for (retry = 0; retry < 100; ++retry) {
if (efx_ef10_try_update_nic_stats_pf(efx) == 0)
break;
udelay(100);
}
return efx_ef10_update_stats_common(efx, full_stats, core_stats);
}
static int efx_ef10_try_update_nic_stats_vf(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_MAC_STATS_IN_LEN);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
DECLARE_BITMAP(mask, EF10_STAT_COUNT);
__le64 generation_start, generation_end;
u64 *stats = nic_data->stats;
u32 dma_len = MC_CMD_MAC_NSTATS * sizeof(u64);
struct efx_buffer stats_buf;
__le64 *dma_stats;
int rc;
spin_unlock_bh(&efx->stats_lock);
if (in_interrupt()) {
spin_lock_bh(&efx->stats_lock);
efx_update_sw_stats(efx, stats);
return 0;
}
efx_ef10_get_stat_mask(efx, mask);
rc = efx_nic_alloc_buffer(efx, &stats_buf, dma_len, GFP_ATOMIC);
if (rc) {
spin_lock_bh(&efx->stats_lock);
return rc;
}
dma_stats = stats_buf.addr;
dma_stats[MC_CMD_MAC_GENERATION_END] = EFX_MC_STATS_GENERATION_INVALID;
MCDI_SET_QWORD(inbuf, MAC_STATS_IN_DMA_ADDR, stats_buf.dma_addr);
MCDI_POPULATE_DWORD_1(inbuf, MAC_STATS_IN_CMD,
MAC_STATS_IN_DMA, 1);
MCDI_SET_DWORD(inbuf, MAC_STATS_IN_DMA_LEN, dma_len);
MCDI_SET_DWORD(inbuf, MAC_STATS_IN_PORT_ID, EVB_PORT_ID_ASSIGNED);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_MAC_STATS, inbuf, sizeof(inbuf),
NULL, 0, NULL);
spin_lock_bh(&efx->stats_lock);
if (rc) {
if (rc != -ENOENT || atomic_read(&efx->active_queues))
efx_mcdi_display_error(efx, MC_CMD_MAC_STATS,
sizeof(inbuf), NULL, 0, rc);
goto out;
}
generation_end = dma_stats[MC_CMD_MAC_GENERATION_END];
if (generation_end == EFX_MC_STATS_GENERATION_INVALID) {
WARN_ON_ONCE(1);
goto out;
}
rmb();
efx_nic_update_stats(efx_ef10_stat_desc, EF10_STAT_COUNT, mask,
stats, stats_buf.addr, false);
rmb();
generation_start = dma_stats[MC_CMD_MAC_GENERATION_START];
if (generation_end != generation_start) {
rc = -EAGAIN;
goto out;
}
efx_update_sw_stats(efx, stats);
out:
efx_nic_free_buffer(efx, &stats_buf);
return rc;
}
static size_t efx_ef10_update_stats_vf(struct efx_nic *efx, u64 *full_stats,
struct rtnl_link_stats64 *core_stats)
{
if (efx_ef10_try_update_nic_stats_vf(efx))
return 0;
return efx_ef10_update_stats_common(efx, full_stats, core_stats);
}
static void efx_ef10_push_irq_moderation(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
unsigned int mode, value;
efx_dword_t timer_cmd;
if (channel->irq_moderation) {
mode = 3;
value = channel->irq_moderation - 1;
} else {
mode = 0;
value = 0;
}
if (EFX_EF10_WORKAROUND_35388(efx)) {
EFX_POPULATE_DWORD_3(timer_cmd, ERF_DD_EVQ_IND_TIMER_FLAGS,
EFE_DD_EVQ_IND_TIMER_FLAGS,
ERF_DD_EVQ_IND_TIMER_MODE, mode,
ERF_DD_EVQ_IND_TIMER_VAL, value);
efx_writed_page(efx, &timer_cmd, ER_DD_EVQ_INDIRECT,
channel->channel);
} else {
EFX_POPULATE_DWORD_2(timer_cmd, ERF_DZ_TC_TIMER_MODE, mode,
ERF_DZ_TC_TIMER_VAL, value);
efx_writed_page(efx, &timer_cmd, ER_DZ_EVQ_TMR,
channel->channel);
}
}
static void efx_ef10_get_wol_vf(struct efx_nic *efx,
struct ethtool_wolinfo *wol) {}
static int efx_ef10_set_wol_vf(struct efx_nic *efx, u32 type)
{
return -EOPNOTSUPP;
}
static void efx_ef10_get_wol(struct efx_nic *efx, struct ethtool_wolinfo *wol)
{
wol->supported = 0;
wol->wolopts = 0;
memset(&wol->sopass, 0, sizeof(wol->sopass));
}
static int efx_ef10_set_wol(struct efx_nic *efx, u32 type)
{
if (type != 0)
return -EINVAL;
return 0;
}
static void efx_ef10_mcdi_request(struct efx_nic *efx,
const efx_dword_t *hdr, size_t hdr_len,
const efx_dword_t *sdu, size_t sdu_len)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
u8 *pdu = nic_data->mcdi_buf.addr;
memcpy(pdu, hdr, hdr_len);
memcpy(pdu + hdr_len, sdu, sdu_len);
wmb();
_efx_writed(efx, cpu_to_le32((u64)nic_data->mcdi_buf.dma_addr >> 32),
ER_DZ_MC_DB_LWRD);
_efx_writed(efx, cpu_to_le32((u32)nic_data->mcdi_buf.dma_addr),
ER_DZ_MC_DB_HWRD);
}
static bool efx_ef10_mcdi_poll_response(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
const efx_dword_t hdr = *(const efx_dword_t *)nic_data->mcdi_buf.addr;
rmb();
return EFX_DWORD_FIELD(hdr, MCDI_HEADER_RESPONSE);
}
static void
efx_ef10_mcdi_read_response(struct efx_nic *efx, efx_dword_t *outbuf,
size_t offset, size_t outlen)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
const u8 *pdu = nic_data->mcdi_buf.addr;
memcpy(outbuf, pdu + offset, outlen);
}
static int efx_ef10_mcdi_poll_reboot(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
int rc;
rc = efx_ef10_get_warm_boot_count(efx);
if (rc < 0) {
return 0;
}
if (rc == nic_data->warm_boot_count)
return 0;
nic_data->warm_boot_count = rc;
efx_ef10_reset_mc_allocations(efx);
nic_data->must_probe_vswitching = true;
nic_data->vport_id = EVB_PORT_ID_ASSIGNED;
nic_data->must_check_datapath_caps = true;
nic_data->stats[EF10_STAT_port_rx_bad_bytes] = 0;
return -EIO;
}
static irqreturn_t efx_ef10_msi_interrupt(int irq, void *dev_id)
{
struct efx_msi_context *context = dev_id;
struct efx_nic *efx = context->efx;
netif_vdbg(efx, intr, efx->net_dev,
"IRQ %d on CPU %d\n", irq, raw_smp_processor_id());
if (likely(ACCESS_ONCE(efx->irq_soft_enabled))) {
if (context->index == efx->irq_level)
efx->last_irq_cpu = raw_smp_processor_id();
efx_schedule_channel_irq(efx->channel[context->index]);
}
return IRQ_HANDLED;
}
static irqreturn_t efx_ef10_legacy_interrupt(int irq, void *dev_id)
{
struct efx_nic *efx = dev_id;
bool soft_enabled = ACCESS_ONCE(efx->irq_soft_enabled);
struct efx_channel *channel;
efx_dword_t reg;
u32 queues;
efx_readd(efx, &reg, ER_DZ_BIU_INT_ISR);
queues = EFX_DWORD_FIELD(reg, ERF_DZ_ISR_REG);
if (queues == 0)
return IRQ_NONE;
if (likely(soft_enabled)) {
if (queues & (1U << efx->irq_level))
efx->last_irq_cpu = raw_smp_processor_id();
efx_for_each_channel(channel, efx) {
if (queues & 1)
efx_schedule_channel_irq(channel);
queues >>= 1;
}
}
netif_vdbg(efx, intr, efx->net_dev,
"IRQ %d on CPU %d status " EFX_DWORD_FMT "\n",
irq, raw_smp_processor_id(), EFX_DWORD_VAL(reg));
return IRQ_HANDLED;
}
static void efx_ef10_irq_test_generate(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_TRIGGER_INTERRUPT_IN_LEN);
BUILD_BUG_ON(MC_CMD_TRIGGER_INTERRUPT_OUT_LEN != 0);
MCDI_SET_DWORD(inbuf, TRIGGER_INTERRUPT_IN_INTR_LEVEL, efx->irq_level);
(void) efx_mcdi_rpc(efx, MC_CMD_TRIGGER_INTERRUPT,
inbuf, sizeof(inbuf), NULL, 0, NULL);
}
static int efx_ef10_tx_probe(struct efx_tx_queue *tx_queue)
{
return efx_nic_alloc_buffer(tx_queue->efx, &tx_queue->txd.buf,
(tx_queue->ptr_mask + 1) *
sizeof(efx_qword_t),
GFP_KERNEL);
}
static inline void efx_ef10_push_tx_desc(struct efx_tx_queue *tx_queue,
const efx_qword_t *txd)
{
unsigned int write_ptr;
efx_oword_t reg;
write_ptr = tx_queue->write_count & tx_queue->ptr_mask;
EFX_POPULATE_OWORD_1(reg, ERF_DZ_TX_DESC_WPTR, write_ptr);
reg.qword[0] = *txd;
efx_writeo_page(tx_queue->efx, &reg,
ER_DZ_TX_DESC_UPD, tx_queue->queue);
}
static void efx_ef10_tx_init(struct efx_tx_queue *tx_queue)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_INIT_TXQ_IN_LEN(EFX_MAX_DMAQ_SIZE * 8 /
EFX_BUF_SIZE));
bool csum_offload = tx_queue->queue & EFX_TXQ_TYPE_OFFLOAD;
size_t entries = tx_queue->txd.buf.len / EFX_BUF_SIZE;
struct efx_channel *channel = tx_queue->channel;
struct efx_nic *efx = tx_queue->efx;
struct efx_ef10_nic_data *nic_data = efx->nic_data;
size_t inlen;
dma_addr_t dma_addr;
efx_qword_t *txd;
int rc;
int i;
BUILD_BUG_ON(MC_CMD_INIT_TXQ_OUT_LEN != 0);
MCDI_SET_DWORD(inbuf, INIT_TXQ_IN_SIZE, tx_queue->ptr_mask + 1);
MCDI_SET_DWORD(inbuf, INIT_TXQ_IN_TARGET_EVQ, channel->channel);
MCDI_SET_DWORD(inbuf, INIT_TXQ_IN_LABEL, tx_queue->queue);
MCDI_SET_DWORD(inbuf, INIT_TXQ_IN_INSTANCE, tx_queue->queue);
MCDI_POPULATE_DWORD_2(inbuf, INIT_TXQ_IN_FLAGS,
INIT_TXQ_IN_FLAG_IP_CSUM_DIS, !csum_offload,
INIT_TXQ_IN_FLAG_TCP_CSUM_DIS, !csum_offload);
MCDI_SET_DWORD(inbuf, INIT_TXQ_IN_OWNER_ID, 0);
MCDI_SET_DWORD(inbuf, INIT_TXQ_IN_PORT_ID, nic_data->vport_id);
dma_addr = tx_queue->txd.buf.dma_addr;
netif_dbg(efx, hw, efx->net_dev, "pushing TXQ %d. %zu entries (%llx)\n",
tx_queue->queue, entries, (u64)dma_addr);
for (i = 0; i < entries; ++i) {
MCDI_SET_ARRAY_QWORD(inbuf, INIT_TXQ_IN_DMA_ADDR, i, dma_addr);
dma_addr += EFX_BUF_SIZE;
}
inlen = MC_CMD_INIT_TXQ_IN_LEN(entries);
rc = efx_mcdi_rpc(efx, MC_CMD_INIT_TXQ, inbuf, inlen,
NULL, 0, NULL);
if (rc)
goto fail;
tx_queue->buffer[0].flags = EFX_TX_BUF_OPTION;
tx_queue->insert_count = 1;
txd = efx_tx_desc(tx_queue, 0);
EFX_POPULATE_QWORD_4(*txd,
ESF_DZ_TX_DESC_IS_OPT, true,
ESF_DZ_TX_OPTION_TYPE,
ESE_DZ_TX_OPTION_DESC_CRC_CSUM,
ESF_DZ_TX_OPTION_UDP_TCP_CSUM, csum_offload,
ESF_DZ_TX_OPTION_IP_CSUM, csum_offload);
tx_queue->write_count = 1;
wmb();
efx_ef10_push_tx_desc(tx_queue, txd);
return;
fail:
netdev_WARN(efx->net_dev, "failed to initialise TXQ %d\n",
tx_queue->queue);
}
static void efx_ef10_tx_fini(struct efx_tx_queue *tx_queue)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_FINI_TXQ_IN_LEN);
MCDI_DECLARE_BUF_ERR(outbuf);
struct efx_nic *efx = tx_queue->efx;
size_t outlen;
int rc;
MCDI_SET_DWORD(inbuf, FINI_TXQ_IN_INSTANCE,
tx_queue->queue);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_FINI_TXQ, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), &outlen);
if (rc && rc != -EALREADY)
goto fail;
return;
fail:
efx_mcdi_display_error(efx, MC_CMD_FINI_TXQ, MC_CMD_FINI_TXQ_IN_LEN,
outbuf, outlen, rc);
}
static void efx_ef10_tx_remove(struct efx_tx_queue *tx_queue)
{
efx_nic_free_buffer(tx_queue->efx, &tx_queue->txd.buf);
}
static inline void efx_ef10_notify_tx_desc(struct efx_tx_queue *tx_queue)
{
unsigned int write_ptr;
efx_dword_t reg;
write_ptr = tx_queue->write_count & tx_queue->ptr_mask;
EFX_POPULATE_DWORD_1(reg, ERF_DZ_TX_DESC_WPTR_DWORD, write_ptr);
efx_writed_page(tx_queue->efx, &reg,
ER_DZ_TX_DESC_UPD_DWORD, tx_queue->queue);
}
static void efx_ef10_tx_write(struct efx_tx_queue *tx_queue)
{
unsigned int old_write_count = tx_queue->write_count;
struct efx_tx_buffer *buffer;
unsigned int write_ptr;
efx_qword_t *txd;
BUG_ON(tx_queue->write_count == tx_queue->insert_count);
do {
write_ptr = tx_queue->write_count & tx_queue->ptr_mask;
buffer = &tx_queue->buffer[write_ptr];
txd = efx_tx_desc(tx_queue, write_ptr);
++tx_queue->write_count;
if (buffer->flags & EFX_TX_BUF_OPTION) {
*txd = buffer->option;
} else {
BUILD_BUG_ON(EFX_TX_BUF_CONT != 1);
EFX_POPULATE_QWORD_3(
*txd,
ESF_DZ_TX_KER_CONT,
buffer->flags & EFX_TX_BUF_CONT,
ESF_DZ_TX_KER_BYTE_CNT, buffer->len,
ESF_DZ_TX_KER_BUF_ADDR, buffer->dma_addr);
}
} while (tx_queue->write_count != tx_queue->insert_count);
wmb();
if (efx_nic_may_push_tx_desc(tx_queue, old_write_count)) {
txd = efx_tx_desc(tx_queue,
old_write_count & tx_queue->ptr_mask);
efx_ef10_push_tx_desc(tx_queue, txd);
++tx_queue->pushes;
} else {
efx_ef10_notify_tx_desc(tx_queue);
}
}
static int efx_ef10_alloc_rss_context(struct efx_nic *efx, u32 *context,
bool exclusive, unsigned *context_size)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_RSS_CONTEXT_ALLOC_IN_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_RSS_CONTEXT_ALLOC_OUT_LEN);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
size_t outlen;
int rc;
u32 alloc_type = exclusive ?
MC_CMD_RSS_CONTEXT_ALLOC_IN_TYPE_EXCLUSIVE :
MC_CMD_RSS_CONTEXT_ALLOC_IN_TYPE_SHARED;
unsigned rss_spread = exclusive ?
efx->rss_spread :
min(rounddown_pow_of_two(efx->rss_spread),
EFX_EF10_MAX_SHARED_RSS_CONTEXT_SIZE);
if (!exclusive && rss_spread == 1) {
*context = EFX_EF10_RSS_CONTEXT_INVALID;
if (context_size)
*context_size = 1;
return 0;
}
MCDI_SET_DWORD(inbuf, RSS_CONTEXT_ALLOC_IN_UPSTREAM_PORT_ID,
nic_data->vport_id);
MCDI_SET_DWORD(inbuf, RSS_CONTEXT_ALLOC_IN_TYPE, alloc_type);
MCDI_SET_DWORD(inbuf, RSS_CONTEXT_ALLOC_IN_NUM_QUEUES, rss_spread);
rc = efx_mcdi_rpc(efx, MC_CMD_RSS_CONTEXT_ALLOC, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), &outlen);
if (rc != 0)
return rc;
if (outlen < MC_CMD_RSS_CONTEXT_ALLOC_OUT_LEN)
return -EIO;
*context = MCDI_DWORD(outbuf, RSS_CONTEXT_ALLOC_OUT_RSS_CONTEXT_ID);
if (context_size)
*context_size = rss_spread;
return 0;
}
static void efx_ef10_free_rss_context(struct efx_nic *efx, u32 context)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_RSS_CONTEXT_FREE_IN_LEN);
int rc;
MCDI_SET_DWORD(inbuf, RSS_CONTEXT_FREE_IN_RSS_CONTEXT_ID,
context);
rc = efx_mcdi_rpc(efx, MC_CMD_RSS_CONTEXT_FREE, inbuf, sizeof(inbuf),
NULL, 0, NULL);
WARN_ON(rc != 0);
}
static int efx_ef10_populate_rss_table(struct efx_nic *efx, u32 context,
const u32 *rx_indir_table)
{
MCDI_DECLARE_BUF(tablebuf, MC_CMD_RSS_CONTEXT_SET_TABLE_IN_LEN);
MCDI_DECLARE_BUF(keybuf, MC_CMD_RSS_CONTEXT_SET_KEY_IN_LEN);
int i, rc;
MCDI_SET_DWORD(tablebuf, RSS_CONTEXT_SET_TABLE_IN_RSS_CONTEXT_ID,
context);
BUILD_BUG_ON(ARRAY_SIZE(efx->rx_indir_table) !=
MC_CMD_RSS_CONTEXT_SET_TABLE_IN_INDIRECTION_TABLE_LEN);
for (i = 0; i < ARRAY_SIZE(efx->rx_indir_table); ++i)
MCDI_PTR(tablebuf,
RSS_CONTEXT_SET_TABLE_IN_INDIRECTION_TABLE)[i] =
(u8) rx_indir_table[i];
rc = efx_mcdi_rpc(efx, MC_CMD_RSS_CONTEXT_SET_TABLE, tablebuf,
sizeof(tablebuf), NULL, 0, NULL);
if (rc != 0)
return rc;
MCDI_SET_DWORD(keybuf, RSS_CONTEXT_SET_KEY_IN_RSS_CONTEXT_ID,
context);
BUILD_BUG_ON(ARRAY_SIZE(efx->rx_hash_key) !=
MC_CMD_RSS_CONTEXT_SET_KEY_IN_TOEPLITZ_KEY_LEN);
for (i = 0; i < ARRAY_SIZE(efx->rx_hash_key); ++i)
MCDI_PTR(keybuf, RSS_CONTEXT_SET_KEY_IN_TOEPLITZ_KEY)[i] =
efx->rx_hash_key[i];
return efx_mcdi_rpc(efx, MC_CMD_RSS_CONTEXT_SET_KEY, keybuf,
sizeof(keybuf), NULL, 0, NULL);
}
static void efx_ef10_rx_free_indir_table(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
if (nic_data->rx_rss_context != EFX_EF10_RSS_CONTEXT_INVALID)
efx_ef10_free_rss_context(efx, nic_data->rx_rss_context);
nic_data->rx_rss_context = EFX_EF10_RSS_CONTEXT_INVALID;
}
static int efx_ef10_rx_push_shared_rss_config(struct efx_nic *efx,
unsigned *context_size)
{
u32 new_rx_rss_context;
struct efx_ef10_nic_data *nic_data = efx->nic_data;
int rc = efx_ef10_alloc_rss_context(efx, &new_rx_rss_context,
false, context_size);
if (rc != 0)
return rc;
nic_data->rx_rss_context = new_rx_rss_context;
nic_data->rx_rss_context_exclusive = false;
efx_set_default_rx_indir_table(efx);
return 0;
}
static int efx_ef10_rx_push_exclusive_rss_config(struct efx_nic *efx,
const u32 *rx_indir_table)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
int rc;
u32 new_rx_rss_context;
if (nic_data->rx_rss_context == EFX_EF10_RSS_CONTEXT_INVALID ||
!nic_data->rx_rss_context_exclusive) {
rc = efx_ef10_alloc_rss_context(efx, &new_rx_rss_context,
true, NULL);
if (rc == -EOPNOTSUPP)
return rc;
else if (rc != 0)
goto fail1;
} else {
new_rx_rss_context = nic_data->rx_rss_context;
}
rc = efx_ef10_populate_rss_table(efx, new_rx_rss_context,
rx_indir_table);
if (rc != 0)
goto fail2;
if (nic_data->rx_rss_context != new_rx_rss_context)
efx_ef10_rx_free_indir_table(efx);
nic_data->rx_rss_context = new_rx_rss_context;
nic_data->rx_rss_context_exclusive = true;
if (rx_indir_table != efx->rx_indir_table)
memcpy(efx->rx_indir_table, rx_indir_table,
sizeof(efx->rx_indir_table));
return 0;
fail2:
if (new_rx_rss_context != nic_data->rx_rss_context)
efx_ef10_free_rss_context(efx, new_rx_rss_context);
fail1:
netif_err(efx, hw, efx->net_dev, "%s: failed rc=%d\n", __func__, rc);
return rc;
}
static int efx_ef10_pf_rx_push_rss_config(struct efx_nic *efx, bool user,
const u32 *rx_indir_table)
{
int rc;
if (efx->rss_spread == 1)
return 0;
rc = efx_ef10_rx_push_exclusive_rss_config(efx, rx_indir_table);
if (rc == -ENOBUFS && !user) {
unsigned context_size;
bool mismatch = false;
size_t i;
for (i = 0; i < ARRAY_SIZE(efx->rx_indir_table) && !mismatch;
i++)
mismatch = rx_indir_table[i] !=
ethtool_rxfh_indir_default(i, efx->rss_spread);
rc = efx_ef10_rx_push_shared_rss_config(efx, &context_size);
if (rc == 0) {
if (context_size != efx->rss_spread)
netif_warn(efx, probe, efx->net_dev,
"Could not allocate an exclusive RSS"
" context; allocated a shared one of"
" different size."
" Wanted %u, got %u.\n",
efx->rss_spread, context_size);
else if (mismatch)
netif_warn(efx, probe, efx->net_dev,
"Could not allocate an exclusive RSS"
" context; allocated a shared one but"
" could not apply custom"
" indirection.\n");
else
netif_info(efx, probe, efx->net_dev,
"Could not allocate an exclusive RSS"
" context; allocated a shared one.\n");
}
}
return rc;
}
static int efx_ef10_rx_probe(struct efx_rx_queue *rx_queue)
{
return efx_nic_alloc_buffer(rx_queue->efx, &rx_queue->rxd.buf,
(rx_queue->ptr_mask + 1) *
sizeof(efx_qword_t),
GFP_KERNEL);
}
static void efx_ef10_rx_init(struct efx_rx_queue *rx_queue)
{
MCDI_DECLARE_BUF(inbuf,
MC_CMD_INIT_RXQ_IN_LEN(EFX_MAX_DMAQ_SIZE * 8 /
EFX_BUF_SIZE));
struct efx_channel *channel = efx_rx_queue_channel(rx_queue);
size_t entries = rx_queue->rxd.buf.len / EFX_BUF_SIZE;
struct efx_nic *efx = rx_queue->efx;
struct efx_ef10_nic_data *nic_data = efx->nic_data;
size_t inlen;
dma_addr_t dma_addr;
int rc;
int i;
BUILD_BUG_ON(MC_CMD_INIT_RXQ_OUT_LEN != 0);
rx_queue->scatter_n = 0;
rx_queue->scatter_len = 0;
MCDI_SET_DWORD(inbuf, INIT_RXQ_IN_SIZE, rx_queue->ptr_mask + 1);
MCDI_SET_DWORD(inbuf, INIT_RXQ_IN_TARGET_EVQ, channel->channel);
MCDI_SET_DWORD(inbuf, INIT_RXQ_IN_LABEL, efx_rx_queue_index(rx_queue));
MCDI_SET_DWORD(inbuf, INIT_RXQ_IN_INSTANCE,
efx_rx_queue_index(rx_queue));
MCDI_POPULATE_DWORD_2(inbuf, INIT_RXQ_IN_FLAGS,
INIT_RXQ_IN_FLAG_PREFIX, 1,
INIT_RXQ_IN_FLAG_TIMESTAMP, 1);
MCDI_SET_DWORD(inbuf, INIT_RXQ_IN_OWNER_ID, 0);
MCDI_SET_DWORD(inbuf, INIT_RXQ_IN_PORT_ID, nic_data->vport_id);
dma_addr = rx_queue->rxd.buf.dma_addr;
netif_dbg(efx, hw, efx->net_dev, "pushing RXQ %d. %zu entries (%llx)\n",
efx_rx_queue_index(rx_queue), entries, (u64)dma_addr);
for (i = 0; i < entries; ++i) {
MCDI_SET_ARRAY_QWORD(inbuf, INIT_RXQ_IN_DMA_ADDR, i, dma_addr);
dma_addr += EFX_BUF_SIZE;
}
inlen = MC_CMD_INIT_RXQ_IN_LEN(entries);
rc = efx_mcdi_rpc(efx, MC_CMD_INIT_RXQ, inbuf, inlen,
NULL, 0, NULL);
if (rc)
netdev_WARN(efx->net_dev, "failed to initialise RXQ %d\n",
efx_rx_queue_index(rx_queue));
}
static void efx_ef10_rx_fini(struct efx_rx_queue *rx_queue)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_FINI_RXQ_IN_LEN);
MCDI_DECLARE_BUF_ERR(outbuf);
struct efx_nic *efx = rx_queue->efx;
size_t outlen;
int rc;
MCDI_SET_DWORD(inbuf, FINI_RXQ_IN_INSTANCE,
efx_rx_queue_index(rx_queue));
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_FINI_RXQ, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), &outlen);
if (rc && rc != -EALREADY)
goto fail;
return;
fail:
efx_mcdi_display_error(efx, MC_CMD_FINI_RXQ, MC_CMD_FINI_RXQ_IN_LEN,
outbuf, outlen, rc);
}
static void efx_ef10_rx_remove(struct efx_rx_queue *rx_queue)
{
efx_nic_free_buffer(rx_queue->efx, &rx_queue->rxd.buf);
}
static inline void
efx_ef10_build_rx_desc(struct efx_rx_queue *rx_queue, unsigned int index)
{
struct efx_rx_buffer *rx_buf;
efx_qword_t *rxd;
rxd = efx_rx_desc(rx_queue, index);
rx_buf = efx_rx_buffer(rx_queue, index);
EFX_POPULATE_QWORD_2(*rxd,
ESF_DZ_RX_KER_BYTE_CNT, rx_buf->len,
ESF_DZ_RX_KER_BUF_ADDR, rx_buf->dma_addr);
}
static void efx_ef10_rx_write(struct efx_rx_queue *rx_queue)
{
struct efx_nic *efx = rx_queue->efx;
unsigned int write_count;
efx_dword_t reg;
write_count = rx_queue->added_count & ~7;
if (rx_queue->notified_count == write_count)
return;
do
efx_ef10_build_rx_desc(
rx_queue,
rx_queue->notified_count & rx_queue->ptr_mask);
while (++rx_queue->notified_count != write_count);
wmb();
EFX_POPULATE_DWORD_1(reg, ERF_DZ_RX_DESC_WPTR,
write_count & rx_queue->ptr_mask);
efx_writed_page(efx, &reg, ER_DZ_RX_DESC_UPD,
efx_rx_queue_index(rx_queue));
}
static void efx_ef10_rx_defer_refill(struct efx_rx_queue *rx_queue)
{
struct efx_channel *channel = efx_rx_queue_channel(rx_queue);
MCDI_DECLARE_BUF(inbuf, MC_CMD_DRIVER_EVENT_IN_LEN);
efx_qword_t event;
EFX_POPULATE_QWORD_2(event,
ESF_DZ_EV_CODE, EFX_EF10_DRVGEN_EV,
ESF_DZ_EV_DATA, EFX_EF10_REFILL);
MCDI_SET_DWORD(inbuf, DRIVER_EVENT_IN_EVQ, channel->channel);
memcpy(MCDI_PTR(inbuf, DRIVER_EVENT_IN_DATA), &event.u64[0],
sizeof(efx_qword_t));
efx_mcdi_rpc_async(channel->efx, MC_CMD_DRIVER_EVENT,
inbuf, sizeof(inbuf), 0,
efx_ef10_rx_defer_refill_complete, 0);
}
static void
efx_ef10_rx_defer_refill_complete(struct efx_nic *efx, unsigned long cookie,
int rc, efx_dword_t *outbuf,
size_t outlen_actual)
{
}
static int efx_ef10_ev_probe(struct efx_channel *channel)
{
return efx_nic_alloc_buffer(channel->efx, &channel->eventq.buf,
(channel->eventq_mask + 1) *
sizeof(efx_qword_t),
GFP_KERNEL);
}
static int efx_ef10_ev_init(struct efx_channel *channel)
{
MCDI_DECLARE_BUF(inbuf,
MC_CMD_INIT_EVQ_IN_LEN(EFX_MAX_EVQ_SIZE * 8 /
EFX_BUF_SIZE));
MCDI_DECLARE_BUF(outbuf, MC_CMD_INIT_EVQ_OUT_LEN);
size_t entries = channel->eventq.buf.len / EFX_BUF_SIZE;
struct efx_nic *efx = channel->efx;
struct efx_ef10_nic_data *nic_data;
bool supports_rx_merge;
size_t inlen, outlen;
dma_addr_t dma_addr;
int rc;
int i;
nic_data = efx->nic_data;
supports_rx_merge =
!!(nic_data->datapath_caps &
1 << MC_CMD_GET_CAPABILITIES_OUT_RX_BATCHING_LBN);
memset(channel->eventq.buf.addr, 0xff, channel->eventq.buf.len);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_SIZE, channel->eventq_mask + 1);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_INSTANCE, channel->channel);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_IRQ_NUM, channel->channel);
MCDI_POPULATE_DWORD_4(inbuf, INIT_EVQ_IN_FLAGS,
INIT_EVQ_IN_FLAG_INTERRUPTING, 1,
INIT_EVQ_IN_FLAG_RX_MERGE, 1,
INIT_EVQ_IN_FLAG_TX_MERGE, 1,
INIT_EVQ_IN_FLAG_CUT_THRU, !supports_rx_merge);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_TMR_MODE,
MC_CMD_INIT_EVQ_IN_TMR_MODE_DIS);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_TMR_LOAD, 0);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_TMR_RELOAD, 0);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_COUNT_MODE,
MC_CMD_INIT_EVQ_IN_COUNT_MODE_DIS);
MCDI_SET_DWORD(inbuf, INIT_EVQ_IN_COUNT_THRSHLD, 0);
dma_addr = channel->eventq.buf.dma_addr;
for (i = 0; i < entries; ++i) {
MCDI_SET_ARRAY_QWORD(inbuf, INIT_EVQ_IN_DMA_ADDR, i, dma_addr);
dma_addr += EFX_BUF_SIZE;
}
inlen = MC_CMD_INIT_EVQ_IN_LEN(entries);
rc = efx_mcdi_rpc(efx, MC_CMD_INIT_EVQ, inbuf, inlen,
outbuf, sizeof(outbuf), &outlen);
return rc;
}
static void efx_ef10_ev_fini(struct efx_channel *channel)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_FINI_EVQ_IN_LEN);
MCDI_DECLARE_BUF_ERR(outbuf);
struct efx_nic *efx = channel->efx;
size_t outlen;
int rc;
MCDI_SET_DWORD(inbuf, FINI_EVQ_IN_INSTANCE, channel->channel);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_FINI_EVQ, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), &outlen);
if (rc && rc != -EALREADY)
goto fail;
return;
fail:
efx_mcdi_display_error(efx, MC_CMD_FINI_EVQ, MC_CMD_FINI_EVQ_IN_LEN,
outbuf, outlen, rc);
}
static void efx_ef10_ev_remove(struct efx_channel *channel)
{
efx_nic_free_buffer(channel->efx, &channel->eventq.buf);
}
static void efx_ef10_handle_rx_wrong_queue(struct efx_rx_queue *rx_queue,
unsigned int rx_queue_label)
{
struct efx_nic *efx = rx_queue->efx;
netif_info(efx, hw, efx->net_dev,
"rx event arrived on queue %d labeled as queue %u\n",
efx_rx_queue_index(rx_queue), rx_queue_label);
efx_schedule_reset(efx, RESET_TYPE_DISABLE);
}
static void
efx_ef10_handle_rx_bad_lbits(struct efx_rx_queue *rx_queue,
unsigned int actual, unsigned int expected)
{
unsigned int dropped = (actual - expected) & rx_queue->ptr_mask;
struct efx_nic *efx = rx_queue->efx;
netif_info(efx, hw, efx->net_dev,
"dropped %d events (index=%d expected=%d)\n",
dropped, actual, expected);
efx_schedule_reset(efx, RESET_TYPE_DISABLE);
}
static void efx_ef10_handle_rx_abort(struct efx_rx_queue *rx_queue)
{
unsigned int rx_desc_ptr;
netif_dbg(rx_queue->efx, hw, rx_queue->efx->net_dev,
"scattered RX aborted (dropping %u buffers)\n",
rx_queue->scatter_n);
rx_desc_ptr = rx_queue->removed_count & rx_queue->ptr_mask;
efx_rx_packet(rx_queue, rx_desc_ptr, rx_queue->scatter_n,
0, EFX_RX_PKT_DISCARD);
rx_queue->removed_count += rx_queue->scatter_n;
rx_queue->scatter_n = 0;
rx_queue->scatter_len = 0;
++efx_rx_queue_channel(rx_queue)->n_rx_nodesc_trunc;
}
static int efx_ef10_handle_rx_event(struct efx_channel *channel,
const efx_qword_t *event)
{
unsigned int rx_bytes, next_ptr_lbits, rx_queue_label, rx_l4_class;
unsigned int n_descs, n_packets, i;
struct efx_nic *efx = channel->efx;
struct efx_rx_queue *rx_queue;
bool rx_cont;
u16 flags = 0;
if (unlikely(ACCESS_ONCE(efx->reset_pending)))
return 0;
rx_bytes = EFX_QWORD_FIELD(*event, ESF_DZ_RX_BYTES);
next_ptr_lbits = EFX_QWORD_FIELD(*event, ESF_DZ_RX_DSC_PTR_LBITS);
rx_queue_label = EFX_QWORD_FIELD(*event, ESF_DZ_RX_QLABEL);
rx_l4_class = EFX_QWORD_FIELD(*event, ESF_DZ_RX_L4_CLASS);
rx_cont = EFX_QWORD_FIELD(*event, ESF_DZ_RX_CONT);
if (EFX_QWORD_FIELD(*event, ESF_DZ_RX_DROP_EVENT))
netdev_WARN(efx->net_dev, "saw RX_DROP_EVENT: event="
EFX_QWORD_FMT "\n",
EFX_QWORD_VAL(*event));
rx_queue = efx_channel_get_rx_queue(channel);
if (unlikely(rx_queue_label != efx_rx_queue_index(rx_queue)))
efx_ef10_handle_rx_wrong_queue(rx_queue, rx_queue_label);
n_descs = ((next_ptr_lbits - rx_queue->removed_count) &
((1 << ESF_DZ_RX_DSC_PTR_LBITS_WIDTH) - 1));
if (n_descs != rx_queue->scatter_n + 1) {
struct efx_ef10_nic_data *nic_data = efx->nic_data;
if (unlikely(n_descs == rx_queue->scatter_n)) {
if (rx_queue->scatter_n == 0 || rx_bytes != 0)
netdev_WARN(efx->net_dev,
"invalid RX abort: scatter_n=%u event="
EFX_QWORD_FMT "\n",
rx_queue->scatter_n,
EFX_QWORD_VAL(*event));
efx_ef10_handle_rx_abort(rx_queue);
return 0;
}
if (!(nic_data->datapath_caps &
(1 << MC_CMD_GET_CAPABILITIES_OUT_RX_BATCHING_LBN)) ||
rx_queue->scatter_n != 0 || rx_cont) {
efx_ef10_handle_rx_bad_lbits(
rx_queue, next_ptr_lbits,
(rx_queue->removed_count +
rx_queue->scatter_n + 1) &
((1 << ESF_DZ_RX_DSC_PTR_LBITS_WIDTH) - 1));
return 0;
}
rx_queue->scatter_n = 1;
rx_queue->scatter_len = 0;
n_packets = n_descs;
++channel->n_rx_merge_events;
channel->n_rx_merge_packets += n_packets;
flags |= EFX_RX_PKT_PREFIX_LEN;
} else {
++rx_queue->scatter_n;
rx_queue->scatter_len += rx_bytes;
if (rx_cont)
return 0;
n_packets = 1;
}
if (unlikely(EFX_QWORD_FIELD(*event, ESF_DZ_RX_ECRC_ERR)))
flags |= EFX_RX_PKT_DISCARD;
if (unlikely(EFX_QWORD_FIELD(*event, ESF_DZ_RX_IPCKSUM_ERR))) {
channel->n_rx_ip_hdr_chksum_err += n_packets;
} else if (unlikely(EFX_QWORD_FIELD(*event,
ESF_DZ_RX_TCPUDP_CKSUM_ERR))) {
channel->n_rx_tcp_udp_chksum_err += n_packets;
} else if (rx_l4_class == ESE_DZ_L4_CLASS_TCP ||
rx_l4_class == ESE_DZ_L4_CLASS_UDP) {
flags |= EFX_RX_PKT_CSUMMED;
}
if (rx_l4_class == ESE_DZ_L4_CLASS_TCP)
flags |= EFX_RX_PKT_TCP;
channel->irq_mod_score += 2 * n_packets;
for (i = 0; i < n_packets; i++) {
efx_rx_packet(rx_queue,
rx_queue->removed_count & rx_queue->ptr_mask,
rx_queue->scatter_n, rx_queue->scatter_len,
flags);
rx_queue->removed_count += rx_queue->scatter_n;
}
rx_queue->scatter_n = 0;
rx_queue->scatter_len = 0;
return n_packets;
}
static int
efx_ef10_handle_tx_event(struct efx_channel *channel, efx_qword_t *event)
{
struct efx_nic *efx = channel->efx;
struct efx_tx_queue *tx_queue;
unsigned int tx_ev_desc_ptr;
unsigned int tx_ev_q_label;
int tx_descs = 0;
if (unlikely(ACCESS_ONCE(efx->reset_pending)))
return 0;
if (unlikely(EFX_QWORD_FIELD(*event, ESF_DZ_TX_DROP_EVENT)))
return 0;
tx_ev_desc_ptr = EFX_QWORD_FIELD(*event, ESF_DZ_TX_DESCR_INDX);
tx_ev_q_label = EFX_QWORD_FIELD(*event, ESF_DZ_TX_QLABEL);
tx_queue = efx_channel_get_tx_queue(channel,
tx_ev_q_label % EFX_TXQ_TYPES);
tx_descs = ((tx_ev_desc_ptr + 1 - tx_queue->read_count) &
tx_queue->ptr_mask);
efx_xmit_done(tx_queue, tx_ev_desc_ptr & tx_queue->ptr_mask);
return tx_descs;
}
static void
efx_ef10_handle_driver_event(struct efx_channel *channel, efx_qword_t *event)
{
struct efx_nic *efx = channel->efx;
int subcode;
subcode = EFX_QWORD_FIELD(*event, ESF_DZ_DRV_SUB_CODE);
switch (subcode) {
case ESE_DZ_DRV_TIMER_EV:
case ESE_DZ_DRV_WAKE_UP_EV:
break;
case ESE_DZ_DRV_START_UP_EV:
break;
default:
netif_err(efx, hw, efx->net_dev,
"channel %d unknown driver event type %d"
" (data " EFX_QWORD_FMT ")\n",
channel->channel, subcode,
EFX_QWORD_VAL(*event));
}
}
static void efx_ef10_handle_driver_generated_event(struct efx_channel *channel,
efx_qword_t *event)
{
struct efx_nic *efx = channel->efx;
u32 subcode;
subcode = EFX_QWORD_FIELD(*event, EFX_DWORD_0);
switch (subcode) {
case EFX_EF10_TEST:
channel->event_test_cpu = raw_smp_processor_id();
break;
case EFX_EF10_REFILL:
efx_fast_push_rx_descriptors(&channel->rx_queue, true);
break;
default:
netif_err(efx, hw, efx->net_dev,
"channel %d unknown driver event type %u"
" (data " EFX_QWORD_FMT ")\n",
channel->channel, (unsigned) subcode,
EFX_QWORD_VAL(*event));
}
}
static int efx_ef10_ev_process(struct efx_channel *channel, int quota)
{
struct efx_nic *efx = channel->efx;
efx_qword_t event, *p_event;
unsigned int read_ptr;
int ev_code;
int tx_descs = 0;
int spent = 0;
if (quota <= 0)
return spent;
read_ptr = channel->eventq_read_ptr;
for (;;) {
p_event = efx_event(channel, read_ptr);
event = *p_event;
if (!efx_event_present(&event))
break;
EFX_SET_QWORD(*p_event);
++read_ptr;
ev_code = EFX_QWORD_FIELD(event, ESF_DZ_EV_CODE);
netif_vdbg(efx, drv, efx->net_dev,
"processing event on %d " EFX_QWORD_FMT "\n",
channel->channel, EFX_QWORD_VAL(event));
switch (ev_code) {
case ESE_DZ_EV_CODE_MCDI_EV:
efx_mcdi_process_event(channel, &event);
break;
case ESE_DZ_EV_CODE_RX_EV:
spent += efx_ef10_handle_rx_event(channel, &event);
if (spent >= quota) {
spent = quota;
goto out;
}
break;
case ESE_DZ_EV_CODE_TX_EV:
tx_descs += efx_ef10_handle_tx_event(channel, &event);
if (tx_descs > efx->txq_entries) {
spent = quota;
goto out;
} else if (++spent == quota) {
goto out;
}
break;
case ESE_DZ_EV_CODE_DRIVER_EV:
efx_ef10_handle_driver_event(channel, &event);
if (++spent == quota)
goto out;
break;
case EFX_EF10_DRVGEN_EV:
efx_ef10_handle_driver_generated_event(channel, &event);
break;
default:
netif_err(efx, hw, efx->net_dev,
"channel %d unknown event type %d"
" (data " EFX_QWORD_FMT ")\n",
channel->channel, ev_code,
EFX_QWORD_VAL(event));
}
}
out:
channel->eventq_read_ptr = read_ptr;
return spent;
}
static void efx_ef10_ev_read_ack(struct efx_channel *channel)
{
struct efx_nic *efx = channel->efx;
efx_dword_t rptr;
if (EFX_EF10_WORKAROUND_35388(efx)) {
BUILD_BUG_ON(EFX_MIN_EVQ_SIZE <
(1 << ERF_DD_EVQ_IND_RPTR_WIDTH));
BUILD_BUG_ON(EFX_MAX_EVQ_SIZE >
(1 << 2 * ERF_DD_EVQ_IND_RPTR_WIDTH));
EFX_POPULATE_DWORD_2(rptr, ERF_DD_EVQ_IND_RPTR_FLAGS,
EFE_DD_EVQ_IND_RPTR_FLAGS_HIGH,
ERF_DD_EVQ_IND_RPTR,
(channel->eventq_read_ptr &
channel->eventq_mask) >>
ERF_DD_EVQ_IND_RPTR_WIDTH);
efx_writed_page(efx, &rptr, ER_DD_EVQ_INDIRECT,
channel->channel);
EFX_POPULATE_DWORD_2(rptr, ERF_DD_EVQ_IND_RPTR_FLAGS,
EFE_DD_EVQ_IND_RPTR_FLAGS_LOW,
ERF_DD_EVQ_IND_RPTR,
channel->eventq_read_ptr &
((1 << ERF_DD_EVQ_IND_RPTR_WIDTH) - 1));
efx_writed_page(efx, &rptr, ER_DD_EVQ_INDIRECT,
channel->channel);
} else {
EFX_POPULATE_DWORD_1(rptr, ERF_DZ_EVQ_RPTR,
channel->eventq_read_ptr &
channel->eventq_mask);
efx_writed_page(efx, &rptr, ER_DZ_EVQ_RPTR, channel->channel);
}
}
static void efx_ef10_ev_test_generate(struct efx_channel *channel)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_DRIVER_EVENT_IN_LEN);
struct efx_nic *efx = channel->efx;
efx_qword_t event;
int rc;
EFX_POPULATE_QWORD_2(event,
ESF_DZ_EV_CODE, EFX_EF10_DRVGEN_EV,
ESF_DZ_EV_DATA, EFX_EF10_TEST);
MCDI_SET_DWORD(inbuf, DRIVER_EVENT_IN_EVQ, channel->channel);
memcpy(MCDI_PTR(inbuf, DRIVER_EVENT_IN_DATA), &event.u64[0],
sizeof(efx_qword_t));
rc = efx_mcdi_rpc(efx, MC_CMD_DRIVER_EVENT, inbuf, sizeof(inbuf),
NULL, 0, NULL);
if (rc != 0)
goto fail;
return;
fail:
WARN_ON(true);
netif_err(efx, hw, efx->net_dev, "%s: failed rc=%d\n", __func__, rc);
}
void efx_ef10_handle_drain_event(struct efx_nic *efx)
{
if (atomic_dec_and_test(&efx->active_queues))
wake_up(&efx->flush_wq);
WARN_ON(atomic_read(&efx->active_queues) < 0);
}
static int efx_ef10_fini_dmaq(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
struct efx_channel *channel;
struct efx_tx_queue *tx_queue;
struct efx_rx_queue *rx_queue;
int pending;
if (nic_data->must_realloc_vis) {
atomic_set(&efx->active_queues, 0);
return 0;
}
if (efx->state != STATE_RECOVERY) {
efx_for_each_channel(channel, efx) {
efx_for_each_channel_rx_queue(rx_queue, channel)
efx_ef10_rx_fini(rx_queue);
efx_for_each_channel_tx_queue(tx_queue, channel)
efx_ef10_tx_fini(tx_queue);
}
wait_event_timeout(efx->flush_wq,
atomic_read(&efx->active_queues) == 0,
msecs_to_jiffies(EFX_MAX_FLUSH_TIME));
pending = atomic_read(&efx->active_queues);
if (pending) {
netif_err(efx, hw, efx->net_dev, "failed to flush %d queues\n",
pending);
return -ETIMEDOUT;
}
}
return 0;
}
static void efx_ef10_prepare_flr(struct efx_nic *efx)
{
atomic_set(&efx->active_queues, 0);
}
static bool efx_ef10_filter_equal(const struct efx_filter_spec *left,
const struct efx_filter_spec *right)
{
if ((left->match_flags ^ right->match_flags) |
((left->flags ^ right->flags) &
(EFX_FILTER_FLAG_RX | EFX_FILTER_FLAG_TX)))
return false;
return memcmp(&left->outer_vid, &right->outer_vid,
sizeof(struct efx_filter_spec) -
offsetof(struct efx_filter_spec, outer_vid)) == 0;
}
static unsigned int efx_ef10_filter_hash(const struct efx_filter_spec *spec)
{
BUILD_BUG_ON(offsetof(struct efx_filter_spec, outer_vid) & 3);
return jhash2((const u32 *)&spec->outer_vid,
(sizeof(struct efx_filter_spec) -
offsetof(struct efx_filter_spec, outer_vid)) / 4,
0);
}
static bool efx_ef10_filter_is_exclusive(const struct efx_filter_spec *spec)
{
if (spec->match_flags & EFX_FILTER_MATCH_LOC_MAC &&
!is_multicast_ether_addr(spec->loc_mac))
return true;
if ((spec->match_flags &
(EFX_FILTER_MATCH_ETHER_TYPE | EFX_FILTER_MATCH_LOC_HOST)) ==
(EFX_FILTER_MATCH_ETHER_TYPE | EFX_FILTER_MATCH_LOC_HOST)) {
if (spec->ether_type == htons(ETH_P_IP) &&
!ipv4_is_multicast(spec->loc_host[0]))
return true;
if (spec->ether_type == htons(ETH_P_IPV6) &&
((const u8 *)spec->loc_host)[0] != 0xff)
return true;
}
return false;
}
static struct efx_filter_spec *
efx_ef10_filter_entry_spec(const struct efx_ef10_filter_table *table,
unsigned int filter_idx)
{
return (struct efx_filter_spec *)(table->entry[filter_idx].spec &
~EFX_EF10_FILTER_FLAGS);
}
static unsigned int
efx_ef10_filter_entry_flags(const struct efx_ef10_filter_table *table,
unsigned int filter_idx)
{
return table->entry[filter_idx].spec & EFX_EF10_FILTER_FLAGS;
}
static void
efx_ef10_filter_set_entry(struct efx_ef10_filter_table *table,
unsigned int filter_idx,
const struct efx_filter_spec *spec,
unsigned int flags)
{
table->entry[filter_idx].spec = (unsigned long)spec | flags;
}
static void efx_ef10_filter_push_prep(struct efx_nic *efx,
const struct efx_filter_spec *spec,
efx_dword_t *inbuf, u64 handle,
bool replacing)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
memset(inbuf, 0, MC_CMD_FILTER_OP_IN_LEN);
if (replacing) {
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_OP,
MC_CMD_FILTER_OP_IN_OP_REPLACE);
MCDI_SET_QWORD(inbuf, FILTER_OP_IN_HANDLE, handle);
} else {
u32 match_fields = 0;
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_OP,
efx_ef10_filter_is_exclusive(spec) ?
MC_CMD_FILTER_OP_IN_OP_INSERT :
MC_CMD_FILTER_OP_IN_OP_SUBSCRIBE);
if (spec->match_flags & EFX_FILTER_MATCH_LOC_MAC_IG)
match_fields |=
is_multicast_ether_addr(spec->loc_mac) ?
1 << MC_CMD_FILTER_OP_IN_MATCH_UNKNOWN_MCAST_DST_LBN :
1 << MC_CMD_FILTER_OP_IN_MATCH_UNKNOWN_UCAST_DST_LBN;
#define COPY_FIELD(gen_flag, gen_field, mcdi_field) \
if (spec->match_flags & EFX_FILTER_MATCH_ ## gen_flag) { \
match_fields |= \
1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN; \
BUILD_BUG_ON( \
MC_CMD_FILTER_OP_IN_ ## mcdi_field ## _LEN < \
sizeof(spec->gen_field)); \
memcpy(MCDI_PTR(inbuf, FILTER_OP_IN_ ## mcdi_field), \
&spec->gen_field, sizeof(spec->gen_field)); \
}
COPY_FIELD(REM_HOST, rem_host, SRC_IP);
COPY_FIELD(LOC_HOST, loc_host, DST_IP);
COPY_FIELD(REM_MAC, rem_mac, SRC_MAC);
COPY_FIELD(REM_PORT, rem_port, SRC_PORT);
COPY_FIELD(LOC_MAC, loc_mac, DST_MAC);
COPY_FIELD(LOC_PORT, loc_port, DST_PORT);
COPY_FIELD(ETHER_TYPE, ether_type, ETHER_TYPE);
COPY_FIELD(INNER_VID, inner_vid, INNER_VLAN);
COPY_FIELD(OUTER_VID, outer_vid, OUTER_VLAN);
COPY_FIELD(IP_PROTO, ip_proto, IP_PROTO);
#undef COPY_FIELD
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_MATCH_FIELDS,
match_fields);
}
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_PORT_ID, nic_data->vport_id);
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_RX_DEST,
spec->dmaq_id == EFX_FILTER_RX_DMAQ_ID_DROP ?
MC_CMD_FILTER_OP_IN_RX_DEST_DROP :
MC_CMD_FILTER_OP_IN_RX_DEST_HOST);
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_TX_DOMAIN, 0);
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_TX_DEST,
MC_CMD_FILTER_OP_IN_TX_DEST_DEFAULT);
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_RX_QUEUE,
spec->dmaq_id == EFX_FILTER_RX_DMAQ_ID_DROP ?
0 : spec->dmaq_id);
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_RX_MODE,
(spec->flags & EFX_FILTER_FLAG_RX_RSS) ?
MC_CMD_FILTER_OP_IN_RX_MODE_RSS :
MC_CMD_FILTER_OP_IN_RX_MODE_SIMPLE);
if (spec->flags & EFX_FILTER_FLAG_RX_RSS)
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_RX_CONTEXT,
spec->rss_context !=
EFX_FILTER_RSS_CONTEXT_DEFAULT ?
spec->rss_context : nic_data->rx_rss_context);
}
static int efx_ef10_filter_push(struct efx_nic *efx,
const struct efx_filter_spec *spec,
u64 *handle, bool replacing)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_FILTER_OP_IN_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_FILTER_OP_OUT_LEN);
int rc;
efx_ef10_filter_push_prep(efx, spec, inbuf, *handle, replacing);
rc = efx_mcdi_rpc(efx, MC_CMD_FILTER_OP, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), NULL);
if (rc == 0)
*handle = MCDI_QWORD(outbuf, FILTER_OP_OUT_HANDLE);
if (rc == -ENOSPC)
rc = -EBUSY;
return rc;
}
static int efx_ef10_filter_rx_match_pri(struct efx_ef10_filter_table *table,
enum efx_filter_match_flags match_flags)
{
unsigned int match_pri;
for (match_pri = 0;
match_pri < table->rx_match_count;
match_pri++)
if (table->rx_match_flags[match_pri] == match_flags)
return match_pri;
return -EPROTONOSUPPORT;
}
static s32 efx_ef10_filter_insert(struct efx_nic *efx,
struct efx_filter_spec *spec,
bool replace_equal)
{
struct efx_ef10_filter_table *table = efx->filter_state;
DECLARE_BITMAP(mc_rem_map, EFX_EF10_FILTER_SEARCH_LIMIT);
struct efx_filter_spec *saved_spec;
unsigned int match_pri, hash;
unsigned int priv_flags;
bool replacing = false;
int ins_index = -1;
DEFINE_WAIT(wait);
bool is_mc_recip;
s32 rc;
if ((spec->flags & (EFX_FILTER_FLAG_RX | EFX_FILTER_FLAG_TX)) !=
EFX_FILTER_FLAG_RX)
return -EINVAL;
rc = efx_ef10_filter_rx_match_pri(table, spec->match_flags);
if (rc < 0)
return rc;
match_pri = rc;
hash = efx_ef10_filter_hash(spec);
is_mc_recip = efx_filter_is_mc_recipient(spec);
if (is_mc_recip)
bitmap_zero(mc_rem_map, EFX_EF10_FILTER_SEARCH_LIMIT);
for (;;) {
unsigned int depth = 1;
unsigned int i;
spin_lock_bh(&efx->filter_lock);
for (;;) {
i = (hash + depth) & (HUNT_FILTER_TBL_ROWS - 1);
saved_spec = efx_ef10_filter_entry_spec(table, i);
if (!saved_spec) {
if (ins_index < 0)
ins_index = i;
} else if (efx_ef10_filter_equal(spec, saved_spec)) {
if (table->entry[i].spec &
EFX_EF10_FILTER_FLAG_BUSY)
break;
if (spec->priority < saved_spec->priority &&
spec->priority != EFX_FILTER_PRI_AUTO) {
rc = -EPERM;
goto out_unlock;
}
if (!is_mc_recip) {
if (spec->priority ==
saved_spec->priority &&
!replace_equal) {
rc = -EEXIST;
goto out_unlock;
}
ins_index = i;
goto found;
} else if (spec->priority >
saved_spec->priority ||
(spec->priority ==
saved_spec->priority &&
replace_equal)) {
if (ins_index < 0)
ins_index = i;
else
__set_bit(depth, mc_rem_map);
}
}
if (depth == EFX_EF10_FILTER_SEARCH_LIMIT) {
if (ins_index < 0) {
rc = -EBUSY;
goto out_unlock;
}
goto found;
}
++depth;
}
prepare_to_wait(&table->waitq, &wait, TASK_UNINTERRUPTIBLE);
spin_unlock_bh(&efx->filter_lock);
schedule();
}
found:
saved_spec = efx_ef10_filter_entry_spec(table, ins_index);
if (saved_spec) {
if (spec->priority == EFX_FILTER_PRI_AUTO &&
saved_spec->priority >= EFX_FILTER_PRI_AUTO) {
if (saved_spec->priority > EFX_FILTER_PRI_AUTO)
saved_spec->flags |= EFX_FILTER_FLAG_RX_OVER_AUTO;
table->entry[ins_index].spec &=
~EFX_EF10_FILTER_FLAG_AUTO_OLD;
rc = ins_index;
goto out_unlock;
}
replacing = true;
priv_flags = efx_ef10_filter_entry_flags(table, ins_index);
} else {
saved_spec = kmalloc(sizeof(*spec), GFP_ATOMIC);
if (!saved_spec) {
rc = -ENOMEM;
goto out_unlock;
}
*saved_spec = *spec;
priv_flags = 0;
}
efx_ef10_filter_set_entry(table, ins_index, saved_spec,
priv_flags | EFX_EF10_FILTER_FLAG_BUSY);
if (is_mc_recip) {
unsigned int depth, i;
for (depth = 0; depth < EFX_EF10_FILTER_SEARCH_LIMIT; depth++) {
i = (hash + depth) & (HUNT_FILTER_TBL_ROWS - 1);
if (test_bit(depth, mc_rem_map))
table->entry[i].spec |=
EFX_EF10_FILTER_FLAG_BUSY;
}
}
spin_unlock_bh(&efx->filter_lock);
rc = efx_ef10_filter_push(efx, spec, &table->entry[ins_index].handle,
replacing);
spin_lock_bh(&efx->filter_lock);
if (rc == 0) {
if (replacing) {
if (saved_spec->priority == EFX_FILTER_PRI_AUTO)
saved_spec->flags |=
EFX_FILTER_FLAG_RX_OVER_AUTO;
saved_spec->priority = spec->priority;
saved_spec->flags &= EFX_FILTER_FLAG_RX_OVER_AUTO;
saved_spec->flags |= spec->flags;
saved_spec->rss_context = spec->rss_context;
saved_spec->dmaq_id = spec->dmaq_id;
}
} else if (!replacing) {
kfree(saved_spec);
saved_spec = NULL;
}
efx_ef10_filter_set_entry(table, ins_index, saved_spec, priv_flags);
if (is_mc_recip) {
MCDI_DECLARE_BUF(inbuf, MC_CMD_FILTER_OP_IN_LEN);
unsigned int depth, i;
memset(inbuf, 0, sizeof(inbuf));
for (depth = 0; depth < EFX_EF10_FILTER_SEARCH_LIMIT; depth++) {
if (!test_bit(depth, mc_rem_map))
continue;
i = (hash + depth) & (HUNT_FILTER_TBL_ROWS - 1);
saved_spec = efx_ef10_filter_entry_spec(table, i);
priv_flags = efx_ef10_filter_entry_flags(table, i);
if (rc == 0) {
spin_unlock_bh(&efx->filter_lock);
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_OP,
MC_CMD_FILTER_OP_IN_OP_UNSUBSCRIBE);
MCDI_SET_QWORD(inbuf, FILTER_OP_IN_HANDLE,
table->entry[i].handle);
rc = efx_mcdi_rpc(efx, MC_CMD_FILTER_OP,
inbuf, sizeof(inbuf),
NULL, 0, NULL);
spin_lock_bh(&efx->filter_lock);
}
if (rc == 0) {
kfree(saved_spec);
saved_spec = NULL;
priv_flags = 0;
} else {
priv_flags &= ~EFX_EF10_FILTER_FLAG_BUSY;
}
efx_ef10_filter_set_entry(table, i, saved_spec,
priv_flags);
}
}
if (rc == 0)
rc = match_pri * HUNT_FILTER_TBL_ROWS + ins_index;
wake_up_all(&table->waitq);
out_unlock:
spin_unlock_bh(&efx->filter_lock);
finish_wait(&table->waitq, &wait);
return rc;
}
static void efx_ef10_filter_update_rx_scatter(struct efx_nic *efx)
{
}
static int efx_ef10_filter_remove_internal(struct efx_nic *efx,
unsigned int priority_mask,
u32 filter_id, bool by_index)
{
unsigned int filter_idx = filter_id % HUNT_FILTER_TBL_ROWS;
struct efx_ef10_filter_table *table = efx->filter_state;
MCDI_DECLARE_BUF(inbuf,
MC_CMD_FILTER_OP_IN_HANDLE_OFST +
MC_CMD_FILTER_OP_IN_HANDLE_LEN);
struct efx_filter_spec *spec;
DEFINE_WAIT(wait);
int rc;
for (;;) {
spin_lock_bh(&efx->filter_lock);
if (!(table->entry[filter_idx].spec &
EFX_EF10_FILTER_FLAG_BUSY))
break;
prepare_to_wait(&table->waitq, &wait, TASK_UNINTERRUPTIBLE);
spin_unlock_bh(&efx->filter_lock);
schedule();
}
spec = efx_ef10_filter_entry_spec(table, filter_idx);
if (!spec ||
(!by_index &&
efx_ef10_filter_rx_match_pri(table, spec->match_flags) !=
filter_id / HUNT_FILTER_TBL_ROWS)) {
rc = -ENOENT;
goto out_unlock;
}
if (spec->flags & EFX_FILTER_FLAG_RX_OVER_AUTO &&
priority_mask == (1U << EFX_FILTER_PRI_AUTO)) {
spec->flags &= ~EFX_FILTER_FLAG_RX_OVER_AUTO;
table->entry[filter_idx].spec &= ~EFX_EF10_FILTER_FLAG_AUTO_OLD;
rc = 0;
goto out_unlock;
}
if (!(priority_mask & (1U << spec->priority))) {
rc = -ENOENT;
goto out_unlock;
}
table->entry[filter_idx].spec |= EFX_EF10_FILTER_FLAG_BUSY;
spin_unlock_bh(&efx->filter_lock);
if (spec->flags & EFX_FILTER_FLAG_RX_OVER_AUTO) {
struct efx_filter_spec new_spec = *spec;
new_spec.priority = EFX_FILTER_PRI_AUTO;
new_spec.flags = (EFX_FILTER_FLAG_RX |
EFX_FILTER_FLAG_RX_RSS);
new_spec.dmaq_id = 0;
new_spec.rss_context = EFX_FILTER_RSS_CONTEXT_DEFAULT;
rc = efx_ef10_filter_push(efx, &new_spec,
&table->entry[filter_idx].handle,
true);
spin_lock_bh(&efx->filter_lock);
if (rc == 0)
*spec = new_spec;
} else {
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_OP,
efx_ef10_filter_is_exclusive(spec) ?
MC_CMD_FILTER_OP_IN_OP_REMOVE :
MC_CMD_FILTER_OP_IN_OP_UNSUBSCRIBE);
MCDI_SET_QWORD(inbuf, FILTER_OP_IN_HANDLE,
table->entry[filter_idx].handle);
rc = efx_mcdi_rpc(efx, MC_CMD_FILTER_OP,
inbuf, sizeof(inbuf), NULL, 0, NULL);
spin_lock_bh(&efx->filter_lock);
if (rc == 0) {
kfree(spec);
efx_ef10_filter_set_entry(table, filter_idx, NULL, 0);
}
}
table->entry[filter_idx].spec &= ~EFX_EF10_FILTER_FLAG_BUSY;
wake_up_all(&table->waitq);
out_unlock:
spin_unlock_bh(&efx->filter_lock);
finish_wait(&table->waitq, &wait);
return rc;
}
static int efx_ef10_filter_remove_safe(struct efx_nic *efx,
enum efx_filter_priority priority,
u32 filter_id)
{
return efx_ef10_filter_remove_internal(efx, 1U << priority,
filter_id, false);
}
static int efx_ef10_filter_get_safe(struct efx_nic *efx,
enum efx_filter_priority priority,
u32 filter_id, struct efx_filter_spec *spec)
{
unsigned int filter_idx = filter_id % HUNT_FILTER_TBL_ROWS;
struct efx_ef10_filter_table *table = efx->filter_state;
const struct efx_filter_spec *saved_spec;
int rc;
spin_lock_bh(&efx->filter_lock);
saved_spec = efx_ef10_filter_entry_spec(table, filter_idx);
if (saved_spec && saved_spec->priority == priority &&
efx_ef10_filter_rx_match_pri(table, saved_spec->match_flags) ==
filter_id / HUNT_FILTER_TBL_ROWS) {
*spec = *saved_spec;
rc = 0;
} else {
rc = -ENOENT;
}
spin_unlock_bh(&efx->filter_lock);
return rc;
}
static int efx_ef10_filter_clear_rx(struct efx_nic *efx,
enum efx_filter_priority priority)
{
unsigned int priority_mask;
unsigned int i;
int rc;
priority_mask = (((1U << (priority + 1)) - 1) &
~(1U << EFX_FILTER_PRI_AUTO));
for (i = 0; i < HUNT_FILTER_TBL_ROWS; i++) {
rc = efx_ef10_filter_remove_internal(efx, priority_mask,
i, true);
if (rc && rc != -ENOENT)
return rc;
}
return 0;
}
static u32 efx_ef10_filter_count_rx_used(struct efx_nic *efx,
enum efx_filter_priority priority)
{
struct efx_ef10_filter_table *table = efx->filter_state;
unsigned int filter_idx;
s32 count = 0;
spin_lock_bh(&efx->filter_lock);
for (filter_idx = 0; filter_idx < HUNT_FILTER_TBL_ROWS; filter_idx++) {
if (table->entry[filter_idx].spec &&
efx_ef10_filter_entry_spec(table, filter_idx)->priority ==
priority)
++count;
}
spin_unlock_bh(&efx->filter_lock);
return count;
}
static u32 efx_ef10_filter_get_rx_id_limit(struct efx_nic *efx)
{
struct efx_ef10_filter_table *table = efx->filter_state;
return table->rx_match_count * HUNT_FILTER_TBL_ROWS;
}
static s32 efx_ef10_filter_get_rx_ids(struct efx_nic *efx,
enum efx_filter_priority priority,
u32 *buf, u32 size)
{
struct efx_ef10_filter_table *table = efx->filter_state;
struct efx_filter_spec *spec;
unsigned int filter_idx;
s32 count = 0;
spin_lock_bh(&efx->filter_lock);
for (filter_idx = 0; filter_idx < HUNT_FILTER_TBL_ROWS; filter_idx++) {
spec = efx_ef10_filter_entry_spec(table, filter_idx);
if (spec && spec->priority == priority) {
if (count == size) {
count = -EMSGSIZE;
break;
}
buf[count++] = (efx_ef10_filter_rx_match_pri(
table, spec->match_flags) *
HUNT_FILTER_TBL_ROWS +
filter_idx);
}
}
spin_unlock_bh(&efx->filter_lock);
return count;
}
static s32 efx_ef10_filter_rfs_insert(struct efx_nic *efx,
struct efx_filter_spec *spec)
{
struct efx_ef10_filter_table *table = efx->filter_state;
MCDI_DECLARE_BUF(inbuf, MC_CMD_FILTER_OP_IN_LEN);
struct efx_filter_spec *saved_spec;
unsigned int hash, i, depth = 1;
bool replacing = false;
int ins_index = -1;
u64 cookie;
s32 rc;
EFX_WARN_ON_PARANOID(spec->flags !=
(EFX_FILTER_FLAG_RX | EFX_FILTER_FLAG_RX_SCATTER));
EFX_WARN_ON_PARANOID(spec->priority != EFX_FILTER_PRI_HINT);
EFX_WARN_ON_PARANOID(efx_filter_is_mc_recipient(spec));
hash = efx_ef10_filter_hash(spec);
spin_lock_bh(&efx->filter_lock);
for (;;) {
i = (hash + depth) & (HUNT_FILTER_TBL_ROWS - 1);
saved_spec = efx_ef10_filter_entry_spec(table, i);
if (!saved_spec) {
if (ins_index < 0)
ins_index = i;
} else if (efx_ef10_filter_equal(spec, saved_spec)) {
if (table->entry[i].spec & EFX_EF10_FILTER_FLAG_BUSY) {
rc = -EBUSY;
goto fail_unlock;
}
if (spec->priority < saved_spec->priority) {
rc = -EPERM;
goto fail_unlock;
}
ins_index = i;
break;
}
if (depth == EFX_EF10_FILTER_SEARCH_LIMIT) {
if (ins_index < 0) {
rc = -EBUSY;
goto fail_unlock;
}
break;
}
++depth;
}
saved_spec = efx_ef10_filter_entry_spec(table, ins_index);
if (saved_spec) {
replacing = true;
} else {
saved_spec = kmalloc(sizeof(*spec), GFP_ATOMIC);
if (!saved_spec) {
rc = -ENOMEM;
goto fail_unlock;
}
*saved_spec = *spec;
}
efx_ef10_filter_set_entry(table, ins_index, saved_spec,
EFX_EF10_FILTER_FLAG_BUSY);
spin_unlock_bh(&efx->filter_lock);
cookie = replacing << 31 | ins_index << 16 | spec->dmaq_id;
efx_ef10_filter_push_prep(efx, spec, inbuf,
table->entry[ins_index].handle, replacing);
efx_mcdi_rpc_async(efx, MC_CMD_FILTER_OP, inbuf, sizeof(inbuf),
MC_CMD_FILTER_OP_OUT_LEN,
efx_ef10_filter_rfs_insert_complete, cookie);
return ins_index;
fail_unlock:
spin_unlock_bh(&efx->filter_lock);
return rc;
}
static void
efx_ef10_filter_rfs_insert_complete(struct efx_nic *efx, unsigned long cookie,
int rc, efx_dword_t *outbuf,
size_t outlen_actual)
{
struct efx_ef10_filter_table *table = efx->filter_state;
unsigned int ins_index, dmaq_id;
struct efx_filter_spec *spec;
bool replacing;
replacing = cookie >> 31;
ins_index = (cookie >> 16) & (HUNT_FILTER_TBL_ROWS - 1);
dmaq_id = cookie & 0xffff;
spin_lock_bh(&efx->filter_lock);
spec = efx_ef10_filter_entry_spec(table, ins_index);
if (rc == 0) {
table->entry[ins_index].handle =
MCDI_QWORD(outbuf, FILTER_OP_OUT_HANDLE);
if (replacing)
spec->dmaq_id = dmaq_id;
} else if (!replacing) {
kfree(spec);
spec = NULL;
}
efx_ef10_filter_set_entry(table, ins_index, spec, 0);
spin_unlock_bh(&efx->filter_lock);
wake_up_all(&table->waitq);
}
static bool efx_ef10_filter_rfs_expire_one(struct efx_nic *efx, u32 flow_id,
unsigned int filter_idx)
{
struct efx_ef10_filter_table *table = efx->filter_state;
struct efx_filter_spec *spec =
efx_ef10_filter_entry_spec(table, filter_idx);
MCDI_DECLARE_BUF(inbuf,
MC_CMD_FILTER_OP_IN_HANDLE_OFST +
MC_CMD_FILTER_OP_IN_HANDLE_LEN);
if (!spec ||
(table->entry[filter_idx].spec & EFX_EF10_FILTER_FLAG_BUSY) ||
spec->priority != EFX_FILTER_PRI_HINT ||
!rps_may_expire_flow(efx->net_dev, spec->dmaq_id,
flow_id, filter_idx))
return false;
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_OP,
MC_CMD_FILTER_OP_IN_OP_REMOVE);
MCDI_SET_QWORD(inbuf, FILTER_OP_IN_HANDLE,
table->entry[filter_idx].handle);
if (efx_mcdi_rpc_async(efx, MC_CMD_FILTER_OP, inbuf, sizeof(inbuf), 0,
efx_ef10_filter_rfs_expire_complete, filter_idx))
return false;
table->entry[filter_idx].spec |= EFX_EF10_FILTER_FLAG_BUSY;
return true;
}
static void
efx_ef10_filter_rfs_expire_complete(struct efx_nic *efx,
unsigned long filter_idx,
int rc, efx_dword_t *outbuf,
size_t outlen_actual)
{
struct efx_ef10_filter_table *table = efx->filter_state;
struct efx_filter_spec *spec =
efx_ef10_filter_entry_spec(table, filter_idx);
spin_lock_bh(&efx->filter_lock);
if (rc == 0) {
kfree(spec);
efx_ef10_filter_set_entry(table, filter_idx, NULL, 0);
}
table->entry[filter_idx].spec &= ~EFX_EF10_FILTER_FLAG_BUSY;
wake_up_all(&table->waitq);
spin_unlock_bh(&efx->filter_lock);
}
static int efx_ef10_filter_match_flags_from_mcdi(u32 mcdi_flags)
{
int match_flags = 0;
#define MAP_FLAG(gen_flag, mcdi_field) { \
u32 old_mcdi_flags = mcdi_flags; \
mcdi_flags &= ~(1 << MC_CMD_FILTER_OP_IN_MATCH_ ## \
mcdi_field ## _LBN); \
if (mcdi_flags != old_mcdi_flags) \
match_flags |= EFX_FILTER_MATCH_ ## gen_flag; \
}
MAP_FLAG(LOC_MAC_IG, UNKNOWN_UCAST_DST);
MAP_FLAG(LOC_MAC_IG, UNKNOWN_MCAST_DST);
MAP_FLAG(REM_HOST, SRC_IP);
MAP_FLAG(LOC_HOST, DST_IP);
MAP_FLAG(REM_MAC, SRC_MAC);
MAP_FLAG(REM_PORT, SRC_PORT);
MAP_FLAG(LOC_MAC, DST_MAC);
MAP_FLAG(LOC_PORT, DST_PORT);
MAP_FLAG(ETHER_TYPE, ETHER_TYPE);
MAP_FLAG(INNER_VID, INNER_VLAN);
MAP_FLAG(OUTER_VID, OUTER_VLAN);
MAP_FLAG(IP_PROTO, IP_PROTO);
#undef MAP_FLAG
if (mcdi_flags)
return -EINVAL;
return match_flags;
}
static int efx_ef10_filter_table_probe(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_GET_PARSER_DISP_INFO_IN_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_GET_PARSER_DISP_INFO_OUT_LENMAX);
unsigned int pd_match_pri, pd_match_count;
struct efx_ef10_filter_table *table;
size_t outlen;
int rc;
table = kzalloc(sizeof(*table), GFP_KERNEL);
if (!table)
return -ENOMEM;
MCDI_SET_DWORD(inbuf, GET_PARSER_DISP_INFO_IN_OP,
MC_CMD_GET_PARSER_DISP_INFO_IN_OP_GET_SUPPORTED_RX_MATCHES);
rc = efx_mcdi_rpc(efx, MC_CMD_GET_PARSER_DISP_INFO,
inbuf, sizeof(inbuf), outbuf, sizeof(outbuf),
&outlen);
if (rc)
goto fail;
pd_match_count = MCDI_VAR_ARRAY_LEN(
outlen, GET_PARSER_DISP_INFO_OUT_SUPPORTED_MATCHES);
table->rx_match_count = 0;
for (pd_match_pri = 0; pd_match_pri < pd_match_count; pd_match_pri++) {
u32 mcdi_flags =
MCDI_ARRAY_DWORD(
outbuf,
GET_PARSER_DISP_INFO_OUT_SUPPORTED_MATCHES,
pd_match_pri);
rc = efx_ef10_filter_match_flags_from_mcdi(mcdi_flags);
if (rc < 0) {
netif_dbg(efx, probe, efx->net_dev,
"%s: fw flags %#x pri %u not supported in driver\n",
__func__, mcdi_flags, pd_match_pri);
} else {
netif_dbg(efx, probe, efx->net_dev,
"%s: fw flags %#x pri %u supported as driver flags %#x pri %u\n",
__func__, mcdi_flags, pd_match_pri,
rc, table->rx_match_count);
table->rx_match_flags[table->rx_match_count++] = rc;
}
}
table->entry = vzalloc(HUNT_FILTER_TBL_ROWS * sizeof(*table->entry));
if (!table->entry) {
rc = -ENOMEM;
goto fail;
}
efx->filter_state = table;
init_waitqueue_head(&table->waitq);
return 0;
fail:
kfree(table);
return rc;
}
static void efx_ef10_filter_table_restore(struct efx_nic *efx)
{
struct efx_ef10_filter_table *table = efx->filter_state;
struct efx_ef10_nic_data *nic_data = efx->nic_data;
struct efx_filter_spec *spec;
unsigned int filter_idx;
bool failed = false;
int rc;
WARN_ON(!rwsem_is_locked(&efx->filter_sem));
if (!nic_data->must_restore_filters)
return;
if (!table)
return;
spin_lock_bh(&efx->filter_lock);
for (filter_idx = 0; filter_idx < HUNT_FILTER_TBL_ROWS; filter_idx++) {
spec = efx_ef10_filter_entry_spec(table, filter_idx);
if (!spec)
continue;
table->entry[filter_idx].spec |= EFX_EF10_FILTER_FLAG_BUSY;
spin_unlock_bh(&efx->filter_lock);
rc = efx_ef10_filter_push(efx, spec,
&table->entry[filter_idx].handle,
false);
if (rc)
failed = true;
spin_lock_bh(&efx->filter_lock);
if (rc) {
kfree(spec);
efx_ef10_filter_set_entry(table, filter_idx, NULL, 0);
} else {
table->entry[filter_idx].spec &=
~EFX_EF10_FILTER_FLAG_BUSY;
}
}
spin_unlock_bh(&efx->filter_lock);
if (failed)
netif_err(efx, hw, efx->net_dev,
"unable to restore all filters\n");
else
nic_data->must_restore_filters = false;
}
static void efx_ef10_filter_table_remove(struct efx_nic *efx)
{
struct efx_ef10_filter_table *table = efx->filter_state;
MCDI_DECLARE_BUF(inbuf, MC_CMD_FILTER_OP_IN_LEN);
struct efx_filter_spec *spec;
unsigned int filter_idx;
int rc;
efx->filter_state = NULL;
if (!table)
return;
for (filter_idx = 0; filter_idx < HUNT_FILTER_TBL_ROWS; filter_idx++) {
spec = efx_ef10_filter_entry_spec(table, filter_idx);
if (!spec)
continue;
MCDI_SET_DWORD(inbuf, FILTER_OP_IN_OP,
efx_ef10_filter_is_exclusive(spec) ?
MC_CMD_FILTER_OP_IN_OP_REMOVE :
MC_CMD_FILTER_OP_IN_OP_UNSUBSCRIBE);
MCDI_SET_QWORD(inbuf, FILTER_OP_IN_HANDLE,
table->entry[filter_idx].handle);
rc = efx_mcdi_rpc(efx, MC_CMD_FILTER_OP, inbuf, sizeof(inbuf),
NULL, 0, NULL);
if (rc)
netdev_WARN(efx->net_dev,
"filter_idx=%#x handle=%#llx\n",
filter_idx,
table->entry[filter_idx].handle);
kfree(spec);
}
vfree(table->entry);
kfree(table);
}
static void efx_ef10_filter_sync_rx_mode(struct efx_nic *efx)
{
struct efx_ef10_filter_table *table = efx->filter_state;
struct net_device *net_dev = efx->net_dev;
struct efx_filter_spec spec;
bool remove_failed = false;
struct netdev_hw_addr *uc;
struct netdev_hw_addr *mc;
unsigned int filter_idx;
int i, n, rc;
if (!efx_dev_registered(efx))
return;
if (!table)
return;
spin_lock_bh(&efx->filter_lock);
n = table->dev_uc_count < 0 ? 1 : table->dev_uc_count;
for (i = 0; i < n; i++) {
filter_idx = table->dev_uc_list[i].id % HUNT_FILTER_TBL_ROWS;
table->entry[filter_idx].spec |= EFX_EF10_FILTER_FLAG_AUTO_OLD;
}
n = table->dev_mc_count < 0 ? 1 : table->dev_mc_count;
for (i = 0; i < n; i++) {
filter_idx = table->dev_mc_list[i].id % HUNT_FILTER_TBL_ROWS;
table->entry[filter_idx].spec |= EFX_EF10_FILTER_FLAG_AUTO_OLD;
}
spin_unlock_bh(&efx->filter_lock);
netif_addr_lock_bh(net_dev);
if (net_dev->flags & IFF_PROMISC ||
netdev_uc_count(net_dev) >= EFX_EF10_FILTER_DEV_UC_MAX) {
table->dev_uc_count = -1;
} else {
table->dev_uc_count = 1 + netdev_uc_count(net_dev);
ether_addr_copy(table->dev_uc_list[0].addr, net_dev->dev_addr);
i = 1;
netdev_for_each_uc_addr(uc, net_dev) {
ether_addr_copy(table->dev_uc_list[i].addr, uc->addr);
i++;
}
}
if (net_dev->flags & (IFF_PROMISC | IFF_ALLMULTI) ||
netdev_mc_count(net_dev) >= EFX_EF10_FILTER_DEV_MC_MAX) {
table->dev_mc_count = -1;
} else {
table->dev_mc_count = 1 + netdev_mc_count(net_dev);
eth_broadcast_addr(table->dev_mc_list[0].addr);
i = 1;
netdev_for_each_mc_addr(mc, net_dev) {
ether_addr_copy(table->dev_mc_list[i].addr, mc->addr);
i++;
}
}
netif_addr_unlock_bh(net_dev);
if (table->dev_uc_count >= 0) {
for (i = 0; i < table->dev_uc_count; i++) {
efx_filter_init_rx(&spec, EFX_FILTER_PRI_AUTO,
EFX_FILTER_FLAG_RX_RSS,
0);
efx_filter_set_eth_local(&spec, EFX_FILTER_VID_UNSPEC,
table->dev_uc_list[i].addr);
rc = efx_ef10_filter_insert(efx, &spec, true);
if (rc < 0) {
while (i--)
efx_ef10_filter_remove_safe(
efx, EFX_FILTER_PRI_AUTO,
table->dev_uc_list[i].id);
table->dev_uc_count = -1;
break;
}
table->dev_uc_list[i].id = rc;
}
}
if (table->dev_uc_count < 0) {
efx_filter_init_rx(&spec, EFX_FILTER_PRI_AUTO,
EFX_FILTER_FLAG_RX_RSS,
0);
efx_filter_set_uc_def(&spec);
rc = efx_ef10_filter_insert(efx, &spec, true);
if (rc < 0) {
WARN_ON(1);
table->dev_uc_count = 0;
} else {
table->dev_uc_list[0].id = rc;
}
}
if (table->dev_mc_count >= 0) {
for (i = 0; i < table->dev_mc_count; i++) {
efx_filter_init_rx(&spec, EFX_FILTER_PRI_AUTO,
EFX_FILTER_FLAG_RX_RSS,
0);
efx_filter_set_eth_local(&spec, EFX_FILTER_VID_UNSPEC,
table->dev_mc_list[i].addr);
rc = efx_ef10_filter_insert(efx, &spec, true);
if (rc < 0) {
while (i--)
efx_ef10_filter_remove_safe(
efx, EFX_FILTER_PRI_AUTO,
table->dev_mc_list[i].id);
table->dev_mc_count = -1;
break;
}
table->dev_mc_list[i].id = rc;
}
}
if (table->dev_mc_count < 0) {
efx_filter_init_rx(&spec, EFX_FILTER_PRI_AUTO,
EFX_FILTER_FLAG_RX_RSS,
0);
efx_filter_set_mc_def(&spec);
rc = efx_ef10_filter_insert(efx, &spec, true);
if (rc < 0) {
WARN_ON(1);
table->dev_mc_count = 0;
} else {
table->dev_mc_list[0].id = rc;
}
}
for (i = 0; i < HUNT_FILTER_TBL_ROWS; i++) {
if (ACCESS_ONCE(table->entry[i].spec) &
EFX_EF10_FILTER_FLAG_AUTO_OLD) {
if (efx_ef10_filter_remove_internal(
efx, 1U << EFX_FILTER_PRI_AUTO,
i, true) < 0)
remove_failed = true;
}
}
WARN_ON(remove_failed);
}
static int efx_ef10_vport_set_mac_address(struct efx_nic *efx)
{
struct efx_ef10_nic_data *nic_data = efx->nic_data;
u8 mac_old[ETH_ALEN];
int rc, rc2;
if (is_zero_ether_addr(nic_data->vport_mac))
return 0;
efx_device_detach_sync(efx);
efx_net_stop(efx->net_dev);
down_write(&efx->filter_sem);
efx_ef10_filter_table_remove(efx);
up_write(&efx->filter_sem);
rc = efx_ef10_vadaptor_free(efx, nic_data->vport_id);
if (rc)
goto restore_filters;
ether_addr_copy(mac_old, nic_data->vport_mac);
rc = efx_ef10_vport_del_mac(efx, nic_data->vport_id,
nic_data->vport_mac);
if (rc)
goto restore_vadaptor;
rc = efx_ef10_vport_add_mac(efx, nic_data->vport_id,
efx->net_dev->dev_addr);
if (!rc) {
ether_addr_copy(nic_data->vport_mac, efx->net_dev->dev_addr);
} else {
rc2 = efx_ef10_vport_add_mac(efx, nic_data->vport_id, mac_old);
if (rc2) {
eth_zero_addr(nic_data->vport_mac);
goto reset_nic;
}
}
restore_vadaptor:
rc2 = efx_ef10_vadaptor_alloc(efx, nic_data->vport_id);
if (rc2)
goto reset_nic;
restore_filters:
down_write(&efx->filter_sem);
rc2 = efx_ef10_filter_table_probe(efx);
up_write(&efx->filter_sem);
if (rc2)
goto reset_nic;
rc2 = efx_net_open(efx->net_dev);
if (rc2)
goto reset_nic;
netif_device_attach(efx->net_dev);
return rc;
reset_nic:
netif_err(efx, drv, efx->net_dev,
"Failed to restore when changing MAC address - scheduling reset\n");
efx_schedule_reset(efx, RESET_TYPE_DATAPATH);
return rc ? rc : rc2;
}
static int efx_ef10_set_mac_address(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_VADAPTOR_SET_MAC_IN_LEN);
struct efx_ef10_nic_data *nic_data = efx->nic_data;
bool was_enabled = efx->port_enabled;
int rc;
efx_device_detach_sync(efx);
efx_net_stop(efx->net_dev);
down_write(&efx->filter_sem);
efx_ef10_filter_table_remove(efx);
ether_addr_copy(MCDI_PTR(inbuf, VADAPTOR_SET_MAC_IN_MACADDR),
efx->net_dev->dev_addr);
MCDI_SET_DWORD(inbuf, VADAPTOR_SET_MAC_IN_UPSTREAM_PORT_ID,
nic_data->vport_id);
rc = efx_mcdi_rpc_quiet(efx, MC_CMD_VADAPTOR_SET_MAC, inbuf,
sizeof(inbuf), NULL, 0, NULL);
efx_ef10_filter_table_probe(efx);
up_write(&efx->filter_sem);
if (was_enabled)
efx_net_open(efx->net_dev);
netif_device_attach(efx->net_dev);
#ifdef CONFIG_SFC_SRIOV
if (efx->pci_dev->is_virtfn && efx->pci_dev->physfn) {
struct pci_dev *pci_dev_pf = efx->pci_dev->physfn;
if (rc == -EPERM) {
struct efx_nic *efx_pf;
efx_pf = pci_get_drvdata(pci_dev_pf);
rc = efx_ef10_sriov_set_vf_mac(efx_pf,
nic_data->vf_index,
efx->net_dev->dev_addr);
} else if (!rc) {
struct efx_nic *efx_pf = pci_get_drvdata(pci_dev_pf);
struct efx_ef10_nic_data *nic_data = efx_pf->nic_data;
unsigned int i;
for (i = 0; i < efx_pf->vf_count; ++i) {
struct ef10_vf *vf = nic_data->vf + i;
if (vf->efx == efx) {
ether_addr_copy(vf->mac,
efx->net_dev->dev_addr);
return 0;
}
}
}
} else
#endif
if (rc == -EPERM) {
netif_err(efx, drv, efx->net_dev,
"Cannot change MAC address; use sfboot to enable"
" mac-spoofing on this interface\n");
} else if (rc == -ENOSYS && !efx_ef10_is_vf(efx)) {
rc = efx_ef10_vport_set_mac_address(efx);
} else {
efx_mcdi_display_error(efx, MC_CMD_VADAPTOR_SET_MAC,
sizeof(inbuf), NULL, 0, rc);
}
return rc;
}
static int efx_ef10_mac_reconfigure(struct efx_nic *efx)
{
efx_ef10_filter_sync_rx_mode(efx);
return efx_mcdi_set_mac(efx);
}
static int efx_ef10_mac_reconfigure_vf(struct efx_nic *efx)
{
efx_ef10_filter_sync_rx_mode(efx);
return 0;
}
static int efx_ef10_start_bist(struct efx_nic *efx, u32 bist_type)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_START_BIST_IN_LEN);
MCDI_SET_DWORD(inbuf, START_BIST_IN_TYPE, bist_type);
return efx_mcdi_rpc(efx, MC_CMD_START_BIST, inbuf, sizeof(inbuf),
NULL, 0, NULL);
}
static int efx_ef10_poll_bist(struct efx_nic *efx)
{
int rc;
MCDI_DECLARE_BUF(outbuf, MC_CMD_POLL_BIST_OUT_LEN);
size_t outlen;
u32 result;
rc = efx_mcdi_rpc(efx, MC_CMD_POLL_BIST, NULL, 0,
outbuf, sizeof(outbuf), &outlen);
if (rc != 0)
return rc;
if (outlen < MC_CMD_POLL_BIST_OUT_LEN)
return -EIO;
result = MCDI_DWORD(outbuf, POLL_BIST_OUT_RESULT);
switch (result) {
case MC_CMD_POLL_BIST_PASSED:
netif_dbg(efx, hw, efx->net_dev, "BIST passed.\n");
return 0;
case MC_CMD_POLL_BIST_TIMEOUT:
netif_err(efx, hw, efx->net_dev, "BIST timed out\n");
return -EIO;
case MC_CMD_POLL_BIST_FAILED:
netif_err(efx, hw, efx->net_dev, "BIST failed.\n");
return -EIO;
default:
netif_err(efx, hw, efx->net_dev,
"BIST returned unknown result %u", result);
return -EIO;
}
}
static int efx_ef10_run_bist(struct efx_nic *efx, u32 bist_type)
{
int rc;
netif_dbg(efx, drv, efx->net_dev, "starting BIST type %u\n", bist_type);
rc = efx_ef10_start_bist(efx, bist_type);
if (rc != 0)
return rc;
return efx_ef10_poll_bist(efx);
}
static int
efx_ef10_test_chip(struct efx_nic *efx, struct efx_self_tests *tests)
{
int rc, rc2;
efx_reset_down(efx, RESET_TYPE_WORLD);
rc = efx_mcdi_rpc(efx, MC_CMD_ENABLE_OFFLINE_BIST,
NULL, 0, NULL, 0, NULL);
if (rc != 0)
goto out;
tests->memory = efx_ef10_run_bist(efx, MC_CMD_MC_MEM_BIST) ? -1 : 1;
tests->registers = efx_ef10_run_bist(efx, MC_CMD_REG_BIST) ? -1 : 1;
rc = efx_mcdi_reset(efx, RESET_TYPE_WORLD);
out:
rc2 = efx_reset_up(efx, RESET_TYPE_WORLD, rc == 0);
return rc ? rc : rc2;
}
static int efx_ef10_mtd_probe_partition(struct efx_nic *efx,
struct efx_mcdi_mtd_partition *part,
unsigned int type)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_NVRAM_METADATA_IN_LEN);
MCDI_DECLARE_BUF(outbuf, MC_CMD_NVRAM_METADATA_OUT_LENMAX);
const struct efx_ef10_nvram_type_info *info;
size_t size, erase_size, outlen;
bool protected;
int rc;
for (info = efx_ef10_nvram_types; ; info++) {
if (info ==
efx_ef10_nvram_types + ARRAY_SIZE(efx_ef10_nvram_types))
return -ENODEV;
if ((type & ~info->type_mask) == info->type)
break;
}
if (info->port != efx_port_num(efx))
return -ENODEV;
rc = efx_mcdi_nvram_info(efx, type, &size, &erase_size, &protected);
if (rc)
return rc;
if (protected)
return -ENODEV;
part->nvram_type = type;
MCDI_SET_DWORD(inbuf, NVRAM_METADATA_IN_TYPE, type);
rc = efx_mcdi_rpc(efx, MC_CMD_NVRAM_METADATA, inbuf, sizeof(inbuf),
outbuf, sizeof(outbuf), &outlen);
if (rc)
return rc;
if (outlen < MC_CMD_NVRAM_METADATA_OUT_LENMIN)
return -EIO;
if (MCDI_DWORD(outbuf, NVRAM_METADATA_OUT_FLAGS) &
(1 << MC_CMD_NVRAM_METADATA_OUT_SUBTYPE_VALID_LBN))
part->fw_subtype = MCDI_DWORD(outbuf,
NVRAM_METADATA_OUT_SUBTYPE);
part->common.dev_type_name = "EF10 NVRAM manager";
part->common.type_name = info->name;
part->common.mtd.type = MTD_NORFLASH;
part->common.mtd.flags = MTD_CAP_NORFLASH;
part->common.mtd.size = size;
part->common.mtd.erasesize = erase_size;
return 0;
}
static int efx_ef10_mtd_probe(struct efx_nic *efx)
{
MCDI_DECLARE_BUF(outbuf, MC_CMD_NVRAM_PARTITIONS_OUT_LENMAX);
struct efx_mcdi_mtd_partition *parts;
size_t outlen, n_parts_total, i, n_parts;
unsigned int type;
int rc;
ASSERT_RTNL();
BUILD_BUG_ON(MC_CMD_NVRAM_PARTITIONS_IN_LEN != 0);
rc = efx_mcdi_rpc(efx, MC_CMD_NVRAM_PARTITIONS, NULL, 0,
outbuf, sizeof(outbuf), &outlen);
if (rc)
return rc;
if (outlen < MC_CMD_NVRAM_PARTITIONS_OUT_LENMIN)
return -EIO;
n_parts_total = MCDI_DWORD(outbuf, NVRAM_PARTITIONS_OUT_NUM_PARTITIONS);
if (n_parts_total >
MCDI_VAR_ARRAY_LEN(outlen, NVRAM_PARTITIONS_OUT_TYPE_ID))
return -EIO;
parts = kcalloc(n_parts_total, sizeof(*parts), GFP_KERNEL);
if (!parts)
return -ENOMEM;
n_parts = 0;
for (i = 0; i < n_parts_total; i++) {
type = MCDI_ARRAY_DWORD(outbuf, NVRAM_PARTITIONS_OUT_TYPE_ID,
i);
rc = efx_ef10_mtd_probe_partition(efx, &parts[n_parts], type);
if (rc == 0)
n_parts++;
else if (rc != -ENODEV)
goto fail;
}
rc = efx_mtd_add(efx, &parts[0].common, n_parts, sizeof(*parts));
fail:
if (rc)
kfree(parts);
return rc;
}
static void efx_ef10_ptp_write_host_time(struct efx_nic *efx, u32 host_time)
{
_efx_writed(efx, cpu_to_le32(host_time), ER_DZ_MC_DB_LWRD);
}
static void efx_ef10_ptp_write_host_time_vf(struct efx_nic *efx,
u32 host_time) {}
static int efx_ef10_rx_enable_timestamping(struct efx_channel *channel,
bool temp)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE_LEN);
int rc;
if (channel->sync_events_state == SYNC_EVENTS_REQUESTED ||
channel->sync_events_state == SYNC_EVENTS_VALID ||
(temp && channel->sync_events_state == SYNC_EVENTS_DISABLED))
return 0;
channel->sync_events_state = SYNC_EVENTS_REQUESTED;
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_TIME_EVENT_SUBSCRIBE);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
MCDI_SET_DWORD(inbuf, PTP_IN_TIME_EVENT_SUBSCRIBE_QUEUE,
channel->channel);
rc = efx_mcdi_rpc(channel->efx, MC_CMD_PTP,
inbuf, sizeof(inbuf), NULL, 0, NULL);
if (rc != 0)
channel->sync_events_state = temp ? SYNC_EVENTS_QUIESCENT :
SYNC_EVENTS_DISABLED;
return rc;
}
static int efx_ef10_rx_disable_timestamping(struct efx_channel *channel,
bool temp)
{
MCDI_DECLARE_BUF(inbuf, MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE_LEN);
int rc;
if (channel->sync_events_state == SYNC_EVENTS_DISABLED ||
(temp && channel->sync_events_state == SYNC_EVENTS_QUIESCENT))
return 0;
if (channel->sync_events_state == SYNC_EVENTS_QUIESCENT) {
channel->sync_events_state = SYNC_EVENTS_DISABLED;
return 0;
}
channel->sync_events_state = temp ? SYNC_EVENTS_QUIESCENT :
SYNC_EVENTS_DISABLED;
MCDI_SET_DWORD(inbuf, PTP_IN_OP, MC_CMD_PTP_OP_TIME_EVENT_UNSUBSCRIBE);
MCDI_SET_DWORD(inbuf, PTP_IN_PERIPH_ID, 0);
MCDI_SET_DWORD(inbuf, PTP_IN_TIME_EVENT_UNSUBSCRIBE_CONTROL,
MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE_SINGLE);
MCDI_SET_DWORD(inbuf, PTP_IN_TIME_EVENT_UNSUBSCRIBE_QUEUE,
channel->channel);
rc = efx_mcdi_rpc(channel->efx, MC_CMD_PTP,
inbuf, sizeof(inbuf), NULL, 0, NULL);
return rc;
}
static int efx_ef10_ptp_set_ts_sync_events(struct efx_nic *efx, bool en,
bool temp)
{
int (*set)(struct efx_channel *channel, bool temp);
struct efx_channel *channel;
set = en ?
efx_ef10_rx_enable_timestamping :
efx_ef10_rx_disable_timestamping;
efx_for_each_channel(channel, efx) {
int rc = set(channel, temp);
if (en && rc != 0) {
efx_ef10_ptp_set_ts_sync_events(efx, false, temp);
return rc;
}
}
return 0;
}
static int efx_ef10_ptp_set_ts_config_vf(struct efx_nic *efx,
struct hwtstamp_config *init)
{
return -EOPNOTSUPP;
}
static int efx_ef10_ptp_set_ts_config(struct efx_nic *efx,
struct hwtstamp_config *init)
{
int rc;
switch (init->rx_filter) {
case HWTSTAMP_FILTER_NONE:
efx_ef10_ptp_set_ts_sync_events(efx, false, false);
return efx_ptp_change_mode(efx,
init->tx_type != HWTSTAMP_TX_OFF, 0);
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
init->rx_filter = HWTSTAMP_FILTER_ALL;
rc = efx_ptp_change_mode(efx, true, 0);
if (!rc)
rc = efx_ef10_ptp_set_ts_sync_events(efx, true, false);
if (rc)
efx_ptp_change_mode(efx, false, 0);
return rc;
default:
return -ERANGE;
}
}
