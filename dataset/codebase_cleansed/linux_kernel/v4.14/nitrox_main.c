static void write_to_ucd_unit(struct nitrox_device *ndev,
struct ucode *ucode)
{
u32 code_size = be32_to_cpu(ucode->code_size) * 2;
u64 offset, data;
int i = 0;
offset = UCD_UCODE_LOAD_BLOCK_NUM;
nitrox_write_csr(ndev, offset, 0);
code_size = roundup(code_size, 8);
while (code_size) {
data = ucode->code[i];
offset = UCD_UCODE_LOAD_IDX_DATAX(i);
nitrox_write_csr(ndev, offset, data);
code_size -= 8;
i++;
}
offset = POM_GRP_EXECMASKX(SE_GROUP);
nitrox_write_csr(ndev, offset, (~0ULL));
for (i = 0; i < ndev->hw.se_cores; i++) {
offset = UCD_SE_EID_UCODE_BLOCK_NUMX(i);
nitrox_write_csr(ndev, offset, 0x8);
}
usleep_range(300, 400);
}
static int nitrox_load_fw(struct nitrox_device *ndev, const char *fw_name)
{
const struct firmware *fw;
struct ucode *ucode;
int ret;
dev_info(DEV(ndev), "Loading firmware \"%s\"\n", fw_name);
ret = request_firmware(&fw, fw_name, DEV(ndev));
if (ret < 0) {
dev_err(DEV(ndev), "failed to get firmware %s\n", fw_name);
return ret;
}
ucode = (struct ucode *)fw->data;
memcpy(ndev->hw.fw_name, ucode->version, (VERSION_LEN - 2));
ndev->hw.fw_name[VERSION_LEN - 1] = '\0';
write_to_ucd_unit(ndev, ucode);
release_firmware(fw);
set_bit(NITROX_UCODE_LOADED, &ndev->status);
smp_mb__after_atomic();
return 0;
}
static int nitrox_add_to_devlist(struct nitrox_device *ndev)
{
struct nitrox_device *dev;
int ret = 0;
INIT_LIST_HEAD(&ndev->list);
refcount_set(&ndev->refcnt, 1);
mutex_lock(&devlist_lock);
list_for_each_entry(dev, &ndevlist, list) {
if (dev == ndev) {
ret = -EEXIST;
goto unlock;
}
}
ndev->idx = num_devices++;
list_add_tail(&ndev->list, &ndevlist);
unlock:
mutex_unlock(&devlist_lock);
return ret;
}
static void nitrox_remove_from_devlist(struct nitrox_device *ndev)
{
mutex_lock(&devlist_lock);
list_del(&ndev->list);
num_devices--;
mutex_unlock(&devlist_lock);
}
struct nitrox_device *nitrox_get_first_device(void)
{
struct nitrox_device *ndev = NULL;
mutex_lock(&devlist_lock);
list_for_each_entry(ndev, &ndevlist, list) {
if (nitrox_ready(ndev))
break;
}
mutex_unlock(&devlist_lock);
if (!ndev)
return NULL;
refcount_inc(&ndev->refcnt);
smp_mb__after_atomic();
return ndev;
}
void nitrox_put_device(struct nitrox_device *ndev)
{
if (!ndev)
return;
refcount_dec(&ndev->refcnt);
smp_mb__after_atomic();
}
static int nitrox_reset_device(struct pci_dev *pdev)
{
int pos = 0;
pos = pci_save_state(pdev);
if (pos) {
dev_err(&pdev->dev, "Failed to save pci state\n");
return -ENOMEM;
}
pos = pci_pcie_cap(pdev);
if (!pos)
return -ENOTTY;
if (!pci_wait_for_pending_transaction(pdev))
dev_err(&pdev->dev, "waiting for pending transaction\n");
pcie_capability_set_word(pdev, PCI_EXP_DEVCTL, PCI_EXP_DEVCTL_BCR_FLR);
msleep(100);
pci_restore_state(pdev);
return 0;
}
static int nitrox_pf_sw_init(struct nitrox_device *ndev)
{
int err;
err = nitrox_common_sw_init(ndev);
if (err)
return err;
err = nitrox_pf_init_isr(ndev);
if (err)
nitrox_common_sw_cleanup(ndev);
return err;
}
static void nitrox_pf_sw_cleanup(struct nitrox_device *ndev)
{
nitrox_pf_cleanup_isr(ndev);
nitrox_common_sw_cleanup(ndev);
}
static int nitrox_bist_check(struct nitrox_device *ndev)
{
u64 value = 0;
int i;
for (i = 0; i < NR_CLUSTERS; i++) {
value += nitrox_read_csr(ndev, EMU_BIST_STATUSX(i));
value += nitrox_read_csr(ndev, EFL_CORE_BIST_REGX(i));
}
value += nitrox_read_csr(ndev, UCD_BIST_STATUS);
value += nitrox_read_csr(ndev, NPS_CORE_BIST_REG);
value += nitrox_read_csr(ndev, NPS_CORE_NPC_BIST_REG);
value += nitrox_read_csr(ndev, NPS_PKT_SLC_BIST_REG);
value += nitrox_read_csr(ndev, NPS_PKT_IN_BIST_REG);
value += nitrox_read_csr(ndev, POM_BIST_REG);
value += nitrox_read_csr(ndev, BMI_BIST_REG);
value += nitrox_read_csr(ndev, EFL_TOP_BIST_STAT);
value += nitrox_read_csr(ndev, BMO_BIST_REG);
value += nitrox_read_csr(ndev, LBC_BIST_STATUS);
value += nitrox_read_csr(ndev, PEM_BIST_STATUSX(0));
if (value)
return -EIO;
return 0;
}
static void nitrox_get_hwinfo(struct nitrox_device *ndev)
{
union emu_fuse_map emu_fuse;
u64 offset;
int i;
for (i = 0; i < NR_CLUSTERS; i++) {
u8 dead_cores;
offset = EMU_FUSE_MAPX(i);
emu_fuse.value = nitrox_read_csr(ndev, offset);
if (emu_fuse.s.valid) {
dead_cores = hweight32(emu_fuse.s.ae_fuse);
ndev->hw.ae_cores += AE_CORES_PER_CLUSTER - dead_cores;
dead_cores = hweight16(emu_fuse.s.se_fuse);
ndev->hw.se_cores += SE_CORES_PER_CLUSTER - dead_cores;
}
}
}
static int nitrox_pf_hw_init(struct nitrox_device *ndev)
{
int err;
err = nitrox_bist_check(ndev);
if (err) {
dev_err(&ndev->pdev->dev, "BIST check failed\n");
return err;
}
nitrox_get_hwinfo(ndev);
nitrox_config_nps_unit(ndev);
nitrox_config_pom_unit(ndev);
nitrox_config_efl_unit(ndev);
nitrox_config_bmi_unit(ndev);
nitrox_config_bmo_unit(ndev);
nitrox_config_lbc_unit(ndev);
nitrox_config_rand_unit(ndev);
err = nitrox_load_fw(ndev, SE_FW);
if (err)
return err;
nitrox_config_emu_unit(ndev);
return 0;
}
static int registers_show(struct seq_file *s, void *v)
{
struct nitrox_device *ndev = s->private;
u64 offset;
offset = NPS_STATS_PKT_DMA_RD_CNT;
seq_printf(s, "NPS_STATS_PKT_DMA_RD_CNT 0x%016llx\n",
nitrox_read_csr(ndev, offset));
offset = NPS_STATS_PKT_DMA_WR_CNT;
seq_printf(s, "NPS_STATS_PKT_DMA_WR_CNT 0x%016llx\n",
nitrox_read_csr(ndev, offset));
offset = BMI_NPS_PKT_CNT;
seq_printf(s, "BMI_NPS_PKT_CNT 0x%016llx\n",
nitrox_read_csr(ndev, offset));
offset = BMO_NPS_SLC_PKT_CNT;
seq_printf(s, "BMO_NPS_PKT_CNT 0x%016llx\n",
nitrox_read_csr(ndev, offset));
return 0;
}
static int registers_open(struct inode *inode, struct file *file)
{
return single_open(file, registers_show, inode->i_private);
}
static int firmware_show(struct seq_file *s, void *v)
{
struct nitrox_device *ndev = s->private;
seq_printf(s, "Version: %s\n", ndev->hw.fw_name);
return 0;
}
static int firmware_open(struct inode *inode, struct file *file)
{
return single_open(file, firmware_show, inode->i_private);
}
static int nitrox_show(struct seq_file *s, void *v)
{
struct nitrox_device *ndev = s->private;
seq_printf(s, "NITROX-5 [idx: %d]\n", ndev->idx);
seq_printf(s, " Revision ID: 0x%0x\n", ndev->hw.revision_id);
seq_printf(s, " Cores [AE: %u SE: %u]\n",
ndev->hw.ae_cores, ndev->hw.se_cores);
seq_printf(s, " Number of Queues: %u\n", ndev->nr_queues);
seq_printf(s, " Queue length: %u\n", ndev->qlen);
seq_printf(s, " Node: %u\n", ndev->node);
return 0;
}
static int nitrox_open(struct inode *inode, struct file *file)
{
return single_open(file, nitrox_show, inode->i_private);
}
static void nitrox_debugfs_exit(struct nitrox_device *ndev)
{
debugfs_remove_recursive(ndev->debugfs_dir);
ndev->debugfs_dir = NULL;
}
static int nitrox_debugfs_init(struct nitrox_device *ndev)
{
struct dentry *dir, *f;
dir = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (!dir)
return -ENOMEM;
ndev->debugfs_dir = dir;
f = debugfs_create_file("counters", 0400, dir, ndev, &register_fops);
if (!f)
goto err;
f = debugfs_create_file("firmware", 0400, dir, ndev, &firmware_fops);
if (!f)
goto err;
f = debugfs_create_file("nitrox", 0400, dir, ndev, &nitrox_fops);
if (!f)
goto err;
return 0;
err:
nitrox_debugfs_exit(ndev);
return -ENODEV;
}
static int nitrox_debugfs_init(struct nitrox_device *ndev)
{
return 0;
}
static void nitrox_debugfs_exit(struct nitrox_device *ndev)
{
}
static int nitrox_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct nitrox_device *ndev;
int err;
dev_info_once(&pdev->dev, "%s driver version %s\n",
nitrox_driver_name, DRIVER_VERSION);
err = pci_enable_device_mem(pdev);
if (err)
return err;
err = nitrox_reset_device(pdev);
if (err) {
dev_err(&pdev->dev, "FLR failed\n");
pci_disable_device(pdev);
return err;
}
if (!dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64))) {
dev_dbg(&pdev->dev, "DMA to 64-BIT address\n");
} else {
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "DMA configuration failed\n");
pci_disable_device(pdev);
return err;
}
}
err = pci_request_mem_regions(pdev, nitrox_driver_name);
if (err) {
pci_disable_device(pdev);
return err;
}
pci_set_master(pdev);
ndev = kzalloc(sizeof(*ndev), GFP_KERNEL);
if (!ndev) {
err = -ENOMEM;
goto ndev_fail;
}
pci_set_drvdata(pdev, ndev);
ndev->pdev = pdev;
nitrox_add_to_devlist(ndev);
ndev->hw.vendor_id = pdev->vendor;
ndev->hw.device_id = pdev->device;
ndev->hw.revision_id = pdev->revision;
ndev->timeout = msecs_to_jiffies(CMD_TIMEOUT);
ndev->node = dev_to_node(&pdev->dev);
if (ndev->node == NUMA_NO_NODE)
ndev->node = 0;
ndev->bar_addr = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
if (!ndev->bar_addr) {
err = -EIO;
goto ioremap_err;
}
ndev->nr_queues = min_t(u32, MAX_PF_QUEUES, num_online_cpus());
ndev->qlen = qlen;
err = nitrox_pf_sw_init(ndev);
if (err)
goto ioremap_err;
err = nitrox_pf_hw_init(ndev);
if (err)
goto pf_hw_fail;
err = nitrox_debugfs_init(ndev);
if (err)
goto pf_hw_fail;
set_bit(NITROX_READY, &ndev->status);
smp_mb__after_atomic();
err = nitrox_crypto_register();
if (err)
goto crypto_fail;
return 0;
crypto_fail:
nitrox_debugfs_exit(ndev);
clear_bit(NITROX_READY, &ndev->status);
smp_mb__after_atomic();
pf_hw_fail:
nitrox_pf_sw_cleanup(ndev);
ioremap_err:
nitrox_remove_from_devlist(ndev);
kfree(ndev);
pci_set_drvdata(pdev, NULL);
ndev_fail:
pci_release_mem_regions(pdev);
pci_disable_device(pdev);
return err;
}
static void nitrox_remove(struct pci_dev *pdev)
{
struct nitrox_device *ndev = pci_get_drvdata(pdev);
if (!ndev)
return;
if (!refcount_dec_and_test(&ndev->refcnt)) {
dev_err(DEV(ndev), "Device refcnt not zero (%d)\n",
refcount_read(&ndev->refcnt));
return;
}
dev_info(DEV(ndev), "Removing Device %x:%x\n",
ndev->hw.vendor_id, ndev->hw.device_id);
clear_bit(NITROX_READY, &ndev->status);
smp_mb__after_atomic();
nitrox_remove_from_devlist(ndev);
nitrox_crypto_unregister();
nitrox_debugfs_exit(ndev);
nitrox_pf_sw_cleanup(ndev);
iounmap(ndev->bar_addr);
kfree(ndev);
pci_set_drvdata(pdev, NULL);
pci_release_mem_regions(pdev);
pci_disable_device(pdev);
}
static void nitrox_shutdown(struct pci_dev *pdev)
{
pci_set_drvdata(pdev, NULL);
pci_release_mem_regions(pdev);
pci_disable_device(pdev);
}
