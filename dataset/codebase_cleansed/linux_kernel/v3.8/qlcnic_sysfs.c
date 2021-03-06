int qlcnicvf_config_bridged_mode(struct qlcnic_adapter *adapter, u32 enable)
{
return -EOPNOTSUPP;
}
int qlcnicvf_config_led(struct qlcnic_adapter *adapter, u32 state, u32 rate)
{
return -EOPNOTSUPP;
}
static ssize_t qlcnic_store_bridged_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
unsigned long new;
int ret = -EINVAL;
if (!(adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_BDG))
goto err_out;
if (!test_bit(__QLCNIC_DEV_UP, &adapter->state))
goto err_out;
if (strict_strtoul(buf, 2, &new))
goto err_out;
if (!adapter->nic_ops->config_bridged_mode(adapter, !!new))
ret = len;
err_out:
return ret;
}
static ssize_t qlcnic_show_bridged_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
int bridged_mode = 0;
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_BDG)
bridged_mode = !!(adapter->flags & QLCNIC_BRIDGE_ENABLED);
return sprintf(buf, "%d\n", bridged_mode);
}
static ssize_t qlcnic_store_diag_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
unsigned long new;
if (strict_strtoul(buf, 2, &new))
return -EINVAL;
if (!!new != !!(adapter->flags & QLCNIC_DIAG_ENABLED))
adapter->flags ^= QLCNIC_DIAG_ENABLED;
return len;
}
static ssize_t qlcnic_show_diag_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
return sprintf(buf, "%d\n",
!!(adapter->flags & QLCNIC_DIAG_ENABLED));
}
static int qlcnic_validate_beacon(struct qlcnic_adapter *adapter, u16 beacon,
u8 *state, u8 *rate)
{
*rate = LSB(beacon);
*state = MSB(beacon);
QLCDB(adapter, DRV, "rate %x state %x\n", *rate, *state);
if (!*state) {
*rate = __QLCNIC_MAX_LED_RATE;
return 0;
} else if (*state > __QLCNIC_MAX_LED_STATE) {
return -EINVAL;
}
if ((!*rate) || (*rate > __QLCNIC_MAX_LED_RATE))
return -EINVAL;
return 0;
}
static ssize_t qlcnic_store_beacon(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
int max_sds_rings = adapter->max_sds_rings;
u16 beacon;
u8 b_state, b_rate;
int err;
if (adapter->ahw->op_mode == QLCNIC_NON_PRIV_FUNC) {
dev_warn(dev,
"LED test not supported in non privileged mode\n");
return -EOPNOTSUPP;
}
if (len != sizeof(u16))
return QL_STATUS_INVALID_PARAM;
memcpy(&beacon, buf, sizeof(u16));
err = qlcnic_validate_beacon(adapter, beacon, &b_state, &b_rate);
if (err)
return err;
if (adapter->ahw->beacon_state == b_state)
return len;
rtnl_lock();
if (!adapter->ahw->beacon_state)
if (test_and_set_bit(__QLCNIC_LED_ENABLE, &adapter->state)) {
rtnl_unlock();
return -EBUSY;
}
if (test_bit(__QLCNIC_RESETTING, &adapter->state)) {
err = -EIO;
goto out;
}
if (!test_bit(__QLCNIC_DEV_UP, &adapter->state)) {
err = qlcnic_diag_alloc_res(adapter->netdev, QLCNIC_LED_TEST);
if (err)
goto out;
set_bit(__QLCNIC_DIAG_RES_ALLOC, &adapter->state);
}
err = qlcnic_config_led(adapter, b_state, b_rate);
if (!err) {
err = len;
adapter->ahw->beacon_state = b_state;
}
if (test_and_clear_bit(__QLCNIC_DIAG_RES_ALLOC, &adapter->state))
qlcnic_diag_free_res(adapter->netdev, max_sds_rings);
out:
if (!adapter->ahw->beacon_state)
clear_bit(__QLCNIC_LED_ENABLE, &adapter->state);
rtnl_unlock();
return err;
}
static ssize_t qlcnic_show_beacon(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", adapter->ahw->beacon_state);
}
static int qlcnic_sysfs_validate_crb(struct qlcnic_adapter *adapter,
loff_t offset, size_t size)
{
size_t crb_size = 4;
if (!(adapter->flags & QLCNIC_DIAG_ENABLED))
return -EIO;
if (offset < QLCNIC_PCI_CRBSPACE) {
if (ADDR_IN_RANGE(offset, QLCNIC_PCI_CAMQM,
QLCNIC_PCI_CAMQM_END))
crb_size = 8;
else
return -EINVAL;
}
if ((size != crb_size) || (offset & (crb_size-1)))
return -EINVAL;
return 0;
}
static ssize_t qlcnic_sysfs_read_crb(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
u32 data;
u64 qmdata;
int ret;
ret = qlcnic_sysfs_validate_crb(adapter, offset, size);
if (ret != 0)
return ret;
if (ADDR_IN_RANGE(offset, QLCNIC_PCI_CAMQM, QLCNIC_PCI_CAMQM_END)) {
qlcnic_pci_camqm_read_2M(adapter, offset, &qmdata);
memcpy(buf, &qmdata, size);
} else {
data = QLCRD32(adapter, offset);
memcpy(buf, &data, size);
}
return size;
}
static ssize_t qlcnic_sysfs_write_crb(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
u32 data;
u64 qmdata;
int ret;
ret = qlcnic_sysfs_validate_crb(adapter, offset, size);
if (ret != 0)
return ret;
if (ADDR_IN_RANGE(offset, QLCNIC_PCI_CAMQM, QLCNIC_PCI_CAMQM_END)) {
memcpy(&qmdata, buf, size);
qlcnic_pci_camqm_write_2M(adapter, offset, qmdata);
} else {
memcpy(&data, buf, size);
QLCWR32(adapter, offset, data);
}
return size;
}
static int qlcnic_sysfs_validate_mem(struct qlcnic_adapter *adapter,
loff_t offset, size_t size)
{
if (!(adapter->flags & QLCNIC_DIAG_ENABLED))
return -EIO;
if ((size != 8) || (offset & 0x7))
return -EIO;
return 0;
}
static ssize_t qlcnic_sysfs_read_mem(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
u64 data;
int ret;
ret = qlcnic_sysfs_validate_mem(adapter, offset, size);
if (ret != 0)
return ret;
if (qlcnic_pci_mem_read_2M(adapter, offset, &data))
return -EIO;
memcpy(buf, &data, size);
return size;
}
static ssize_t qlcnic_sysfs_write_mem(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t offset, size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
u64 data;
int ret;
ret = qlcnic_sysfs_validate_mem(adapter, offset, size);
if (ret != 0)
return ret;
memcpy(&data, buf, size);
if (qlcnic_pci_mem_write_2M(adapter, offset, data))
return -EIO;
return size;
}
static int validate_pm_config(struct qlcnic_adapter *adapter,
struct qlcnic_pm_func_cfg *pm_cfg, int count)
{
u8 src_pci_func, s_esw_id, d_esw_id, dest_pci_func;
int i;
for (i = 0; i < count; i++) {
src_pci_func = pm_cfg[i].pci_func;
dest_pci_func = pm_cfg[i].dest_npar;
if (src_pci_func >= QLCNIC_MAX_PCI_FUNC ||
dest_pci_func >= QLCNIC_MAX_PCI_FUNC)
return QL_STATUS_INVALID_PARAM;
if (adapter->npars[src_pci_func].type != QLCNIC_TYPE_NIC)
return QL_STATUS_INVALID_PARAM;
if (adapter->npars[dest_pci_func].type != QLCNIC_TYPE_NIC)
return QL_STATUS_INVALID_PARAM;
s_esw_id = adapter->npars[src_pci_func].phy_port;
d_esw_id = adapter->npars[dest_pci_func].phy_port;
if (s_esw_id != d_esw_id)
return QL_STATUS_INVALID_PARAM;
}
return 0;
}
static ssize_t qlcnic_sysfs_write_pm_config(struct file *filp,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_pm_func_cfg *pm_cfg;
u32 id, action, pci_func;
int count, rem, i, ret;
count = size / sizeof(struct qlcnic_pm_func_cfg);
rem = size % sizeof(struct qlcnic_pm_func_cfg);
if (rem)
return QL_STATUS_INVALID_PARAM;
pm_cfg = (struct qlcnic_pm_func_cfg *)buf;
ret = validate_pm_config(adapter, pm_cfg, count);
if (ret)
return ret;
for (i = 0; i < count; i++) {
pci_func = pm_cfg[i].pci_func;
action = !!pm_cfg[i].action;
id = adapter->npars[pci_func].phy_port;
ret = qlcnic_config_port_mirroring(adapter, id, action,
pci_func);
if (ret)
return ret;
}
for (i = 0; i < count; i++) {
pci_func = pm_cfg[i].pci_func;
id = adapter->npars[pci_func].phy_port;
adapter->npars[pci_func].enable_pm = !!pm_cfg[i].action;
adapter->npars[pci_func].dest_npar = id;
}
return size;
}
static ssize_t qlcnic_sysfs_read_pm_config(struct file *filp,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_pm_func_cfg pm_cfg[QLCNIC_MAX_PCI_FUNC];
int i;
if (size != sizeof(pm_cfg))
return QL_STATUS_INVALID_PARAM;
for (i = 0; i < QLCNIC_MAX_PCI_FUNC; i++) {
if (adapter->npars[i].type != QLCNIC_TYPE_NIC)
continue;
pm_cfg[i].action = adapter->npars[i].enable_pm;
pm_cfg[i].dest_npar = 0;
pm_cfg[i].pci_func = i;
}
memcpy(buf, &pm_cfg, size);
return size;
}
static int validate_esw_config(struct qlcnic_adapter *adapter,
struct qlcnic_esw_func_cfg *esw_cfg, int count)
{
u32 op_mode;
u8 pci_func;
int i;
op_mode = readl(adapter->ahw->pci_base0 + QLCNIC_DRV_OP_MODE);
for (i = 0; i < count; i++) {
pci_func = esw_cfg[i].pci_func;
if (pci_func >= QLCNIC_MAX_PCI_FUNC)
return QL_STATUS_INVALID_PARAM;
if (adapter->ahw->op_mode == QLCNIC_MGMT_FUNC) {
if (adapter->npars[pci_func].type != QLCNIC_TYPE_NIC)
return QL_STATUS_INVALID_PARAM;
}
switch (esw_cfg[i].op_mode) {
case QLCNIC_PORT_DEFAULTS:
if (QLC_DEV_GET_DRV(op_mode, pci_func) !=
QLCNIC_NON_PRIV_FUNC) {
if (esw_cfg[i].mac_anti_spoof != 0)
return QL_STATUS_INVALID_PARAM;
if (esw_cfg[i].mac_override != 1)
return QL_STATUS_INVALID_PARAM;
if (esw_cfg[i].promisc_mode != 1)
return QL_STATUS_INVALID_PARAM;
}
break;
case QLCNIC_ADD_VLAN:
if (!IS_VALID_VLAN(esw_cfg[i].vlan_id))
return QL_STATUS_INVALID_PARAM;
if (!esw_cfg[i].op_type)
return QL_STATUS_INVALID_PARAM;
break;
case QLCNIC_DEL_VLAN:
if (!esw_cfg[i].op_type)
return QL_STATUS_INVALID_PARAM;
break;
default:
return QL_STATUS_INVALID_PARAM;
}
}
return 0;
}
static ssize_t qlcnic_sysfs_write_esw_config(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_esw_func_cfg *esw_cfg;
struct qlcnic_npar_info *npar;
int count, rem, i, ret;
u8 pci_func, op_mode = 0;
count = size / sizeof(struct qlcnic_esw_func_cfg);
rem = size % sizeof(struct qlcnic_esw_func_cfg);
if (rem)
return QL_STATUS_INVALID_PARAM;
esw_cfg = (struct qlcnic_esw_func_cfg *)buf;
ret = validate_esw_config(adapter, esw_cfg, count);
if (ret)
return ret;
for (i = 0; i < count; i++) {
if (adapter->ahw->op_mode == QLCNIC_MGMT_FUNC) {
if (qlcnic_config_switch_port(adapter, &esw_cfg[i]))
return QL_STATUS_INVALID_PARAM;
}
if (adapter->ahw->pci_func != esw_cfg[i].pci_func)
continue;
op_mode = esw_cfg[i].op_mode;
qlcnic_get_eswitch_port_config(adapter, &esw_cfg[i]);
esw_cfg[i].op_mode = op_mode;
esw_cfg[i].pci_func = adapter->ahw->pci_func;
switch (esw_cfg[i].op_mode) {
case QLCNIC_PORT_DEFAULTS:
qlcnic_set_eswitch_port_features(adapter, &esw_cfg[i]);
break;
case QLCNIC_ADD_VLAN:
qlcnic_set_vlan_config(adapter, &esw_cfg[i]);
break;
case QLCNIC_DEL_VLAN:
esw_cfg[i].vlan_id = 0;
qlcnic_set_vlan_config(adapter, &esw_cfg[i]);
break;
}
}
if (adapter->ahw->op_mode != QLCNIC_MGMT_FUNC)
goto out;
for (i = 0; i < count; i++) {
pci_func = esw_cfg[i].pci_func;
npar = &adapter->npars[pci_func];
switch (esw_cfg[i].op_mode) {
case QLCNIC_PORT_DEFAULTS:
npar->promisc_mode = esw_cfg[i].promisc_mode;
npar->mac_override = esw_cfg[i].mac_override;
npar->offload_flags = esw_cfg[i].offload_flags;
npar->mac_anti_spoof = esw_cfg[i].mac_anti_spoof;
npar->discard_tagged = esw_cfg[i].discard_tagged;
break;
case QLCNIC_ADD_VLAN:
npar->pvid = esw_cfg[i].vlan_id;
break;
case QLCNIC_DEL_VLAN:
npar->pvid = 0;
break;
}
}
out:
return size;
}
static ssize_t qlcnic_sysfs_read_esw_config(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_esw_func_cfg esw_cfg[QLCNIC_MAX_PCI_FUNC];
u8 i;
if (size != sizeof(esw_cfg))
return QL_STATUS_INVALID_PARAM;
for (i = 0; i < QLCNIC_MAX_PCI_FUNC; i++) {
if (adapter->npars[i].type != QLCNIC_TYPE_NIC)
continue;
esw_cfg[i].pci_func = i;
if (qlcnic_get_eswitch_port_config(adapter, &esw_cfg[i]))
return QL_STATUS_INVALID_PARAM;
}
memcpy(buf, &esw_cfg, size);
return size;
}
static int validate_npar_config(struct qlcnic_adapter *adapter,
struct qlcnic_npar_func_cfg *np_cfg,
int count)
{
u8 pci_func, i;
for (i = 0; i < count; i++) {
pci_func = np_cfg[i].pci_func;
if (pci_func >= QLCNIC_MAX_PCI_FUNC)
return QL_STATUS_INVALID_PARAM;
if (adapter->npars[pci_func].type != QLCNIC_TYPE_NIC)
return QL_STATUS_INVALID_PARAM;
if (!IS_VALID_BW(np_cfg[i].min_bw) ||
!IS_VALID_BW(np_cfg[i].max_bw))
return QL_STATUS_INVALID_PARAM;
}
return 0;
}
static ssize_t qlcnic_sysfs_write_npar_config(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_info nic_info;
struct qlcnic_npar_func_cfg *np_cfg;
int i, count, rem, ret;
u8 pci_func;
count = size / sizeof(struct qlcnic_npar_func_cfg);
rem = size % sizeof(struct qlcnic_npar_func_cfg);
if (rem)
return QL_STATUS_INVALID_PARAM;
np_cfg = (struct qlcnic_npar_func_cfg *)buf;
ret = validate_npar_config(adapter, np_cfg, count);
if (ret)
return ret;
for (i = 0; i < count ; i++) {
pci_func = np_cfg[i].pci_func;
ret = qlcnic_get_nic_info(adapter, &nic_info, pci_func);
if (ret)
return ret;
nic_info.pci_func = pci_func;
nic_info.min_tx_bw = np_cfg[i].min_bw;
nic_info.max_tx_bw = np_cfg[i].max_bw;
ret = qlcnic_set_nic_info(adapter, &nic_info);
if (ret)
return ret;
adapter->npars[i].min_bw = nic_info.min_tx_bw;
adapter->npars[i].max_bw = nic_info.max_tx_bw;
}
return size;
}
static ssize_t qlcnic_sysfs_read_npar_config(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_info nic_info;
struct qlcnic_npar_func_cfg np_cfg[QLCNIC_MAX_PCI_FUNC];
int i, ret;
if (size != sizeof(np_cfg))
return QL_STATUS_INVALID_PARAM;
for (i = 0; i < QLCNIC_MAX_PCI_FUNC; i++) {
if (adapter->npars[i].type != QLCNIC_TYPE_NIC)
continue;
ret = qlcnic_get_nic_info(adapter, &nic_info, i);
if (ret)
return ret;
np_cfg[i].pci_func = i;
np_cfg[i].op_mode = (u8)nic_info.op_mode;
np_cfg[i].port_num = nic_info.phys_port;
np_cfg[i].fw_capab = nic_info.capabilities;
np_cfg[i].min_bw = nic_info.min_tx_bw;
np_cfg[i].max_bw = nic_info.max_tx_bw;
np_cfg[i].max_tx_queues = nic_info.max_tx_ques;
np_cfg[i].max_rx_queues = nic_info.max_rx_ques;
}
memcpy(buf, &np_cfg, size);
return size;
}
static ssize_t qlcnic_sysfs_get_port_stats(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_esw_statistics port_stats;
int ret;
if (size != sizeof(struct qlcnic_esw_statistics))
return QL_STATUS_INVALID_PARAM;
if (offset >= QLCNIC_MAX_PCI_FUNC)
return QL_STATUS_INVALID_PARAM;
memset(&port_stats, 0, size);
ret = qlcnic_get_port_stats(adapter, offset, QLCNIC_QUERY_RX_COUNTER,
&port_stats.rx);
if (ret)
return ret;
ret = qlcnic_get_port_stats(adapter, offset, QLCNIC_QUERY_TX_COUNTER,
&port_stats.tx);
if (ret)
return ret;
memcpy(buf, &port_stats, size);
return size;
}
static ssize_t qlcnic_sysfs_get_esw_stats(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_esw_statistics esw_stats;
int ret;
if (size != sizeof(struct qlcnic_esw_statistics))
return QL_STATUS_INVALID_PARAM;
if (offset >= QLCNIC_NIU_MAX_XG_PORTS)
return QL_STATUS_INVALID_PARAM;
memset(&esw_stats, 0, size);
ret = qlcnic_get_eswitch_stats(adapter, offset, QLCNIC_QUERY_RX_COUNTER,
&esw_stats.rx);
if (ret)
return ret;
ret = qlcnic_get_eswitch_stats(adapter, offset, QLCNIC_QUERY_TX_COUNTER,
&esw_stats.tx);
if (ret)
return ret;
memcpy(buf, &esw_stats, size);
return size;
}
static ssize_t qlcnic_sysfs_clear_esw_stats(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
int ret;
if (offset >= QLCNIC_NIU_MAX_XG_PORTS)
return QL_STATUS_INVALID_PARAM;
ret = qlcnic_clear_esw_stats(adapter, QLCNIC_STATS_ESWITCH, offset,
QLCNIC_QUERY_RX_COUNTER);
if (ret)
return ret;
ret = qlcnic_clear_esw_stats(adapter, QLCNIC_STATS_ESWITCH, offset,
QLCNIC_QUERY_TX_COUNTER);
if (ret)
return ret;
return size;
}
static ssize_t qlcnic_sysfs_clear_port_stats(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
int ret;
if (offset >= QLCNIC_MAX_PCI_FUNC)
return QL_STATUS_INVALID_PARAM;
ret = qlcnic_clear_esw_stats(adapter, QLCNIC_STATS_PORT, offset,
QLCNIC_QUERY_RX_COUNTER);
if (ret)
return ret;
ret = qlcnic_clear_esw_stats(adapter, QLCNIC_STATS_PORT, offset,
QLCNIC_QUERY_TX_COUNTER);
if (ret)
return ret;
return size;
}
static ssize_t qlcnic_sysfs_read_pci_config(struct file *file,
struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t offset,
size_t size)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct qlcnic_adapter *adapter = dev_get_drvdata(dev);
struct qlcnic_pci_func_cfg pci_cfg[QLCNIC_MAX_PCI_FUNC];
struct qlcnic_pci_info *pci_info;
int i, ret;
if (size != sizeof(pci_cfg))
return QL_STATUS_INVALID_PARAM;
pci_info = kcalloc(QLCNIC_MAX_PCI_FUNC, sizeof(*pci_info), GFP_KERNEL);
if (!pci_info)
return -ENOMEM;
ret = qlcnic_get_pci_info(adapter, pci_info);
if (ret) {
kfree(pci_info);
return ret;
}
for (i = 0; i < QLCNIC_MAX_PCI_FUNC ; i++) {
pci_cfg[i].pci_func = pci_info[i].id;
pci_cfg[i].func_type = pci_info[i].type;
pci_cfg[i].port_num = pci_info[i].default_port;
pci_cfg[i].min_bw = pci_info[i].tx_min_bw;
pci_cfg[i].max_bw = pci_info[i].tx_max_bw;
memcpy(&pci_cfg[i].def_mac_addr, &pci_info[i].mac, ETH_ALEN);
}
memcpy(buf, &pci_cfg, size);
kfree(pci_info);
return size;
}
void qlcnic_create_sysfs_entries(struct qlcnic_adapter *adapter)
{
struct device *dev = &adapter->pdev->dev;
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_BDG)
if (device_create_file(dev, &dev_attr_bridged_mode))
dev_warn(dev,
"failed to create bridged_mode sysfs entry\n");
}
void qlcnic_remove_sysfs_entries(struct qlcnic_adapter *adapter)
{
struct device *dev = &adapter->pdev->dev;
if (adapter->ahw->capabilities & QLCNIC_FW_CAPABILITY_BDG)
device_remove_file(dev, &dev_attr_bridged_mode);
}
void qlcnic_create_diag_entries(struct qlcnic_adapter *adapter)
{
struct device *dev = &adapter->pdev->dev;
u32 state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
if (device_create_bin_file(dev, &bin_attr_port_stats))
dev_info(dev, "failed to create port stats sysfs entry");
if (adapter->ahw->op_mode == QLCNIC_NON_PRIV_FUNC)
return;
if (device_create_file(dev, &dev_attr_diag_mode))
dev_info(dev, "failed to create diag_mode sysfs entry\n");
if (device_create_bin_file(dev, &bin_attr_crb))
dev_info(dev, "failed to create crb sysfs entry\n");
if (device_create_bin_file(dev, &bin_attr_mem))
dev_info(dev, "failed to create mem sysfs entry\n");
if (state == QLCNIC_DEV_FAILED || (state == QLCNIC_DEV_BADBAD))
return;
if (device_create_bin_file(dev, &bin_attr_pci_config))
dev_info(dev, "failed to create pci config sysfs entry");
if (device_create_file(dev, &dev_attr_beacon))
dev_info(dev, "failed to create beacon sysfs entry");
if (!(adapter->flags & QLCNIC_ESWITCH_ENABLED))
return;
if (device_create_bin_file(dev, &bin_attr_esw_config))
dev_info(dev, "failed to create esw config sysfs entry");
if (adapter->ahw->op_mode != QLCNIC_MGMT_FUNC)
return;
if (device_create_bin_file(dev, &bin_attr_npar_config))
dev_info(dev, "failed to create npar config sysfs entry");
if (device_create_bin_file(dev, &bin_attr_pm_config))
dev_info(dev, "failed to create pm config sysfs entry");
if (device_create_bin_file(dev, &bin_attr_esw_stats))
dev_info(dev, "failed to create eswitch stats sysfs entry");
}
void qlcnic_remove_diag_entries(struct qlcnic_adapter *adapter)
{
struct device *dev = &adapter->pdev->dev;
u32 state = QLCRD32(adapter, QLCNIC_CRB_DEV_STATE);
device_remove_bin_file(dev, &bin_attr_port_stats);
if (adapter->ahw->op_mode == QLCNIC_NON_PRIV_FUNC)
return;
device_remove_file(dev, &dev_attr_diag_mode);
device_remove_bin_file(dev, &bin_attr_crb);
device_remove_bin_file(dev, &bin_attr_mem);
if (state == QLCNIC_DEV_FAILED || (state == QLCNIC_DEV_BADBAD))
return;
device_remove_bin_file(dev, &bin_attr_pci_config);
device_remove_file(dev, &dev_attr_beacon);
if (!(adapter->flags & QLCNIC_ESWITCH_ENABLED))
return;
device_remove_bin_file(dev, &bin_attr_esw_config);
if (adapter->ahw->op_mode != QLCNIC_MGMT_FUNC)
return;
device_remove_bin_file(dev, &bin_attr_npar_config);
device_remove_bin_file(dev, &bin_attr_pm_config);
device_remove_bin_file(dev, &bin_attr_esw_stats);
}
