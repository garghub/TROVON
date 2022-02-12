void zip_reg_write(u64 val, u64 __iomem *addr)
{
writeq(val, addr);
}
u64 zip_reg_read(u64 __iomem *addr)
{
return readq(addr);
}
static struct zip_device *zip_alloc_device(struct pci_dev *pdev)
{
struct zip_device *zip = NULL;
int idx;
for (idx = 0; idx < MAX_ZIP_DEVICES; idx++) {
if (!zip_dev[idx])
break;
}
if (idx < MAX_ZIP_DEVICES)
zip = devm_kzalloc(&pdev->dev, sizeof(*zip), GFP_KERNEL);
if (!zip)
return NULL;
zip_dev[idx] = zip;
zip->index = idx;
return zip;
}
struct zip_device *zip_get_device(int node)
{
if ((node < MAX_ZIP_DEVICES) && (node >= 0))
return zip_dev[node];
zip_err("ZIP device not found for node id %d\n", node);
return NULL;
}
int zip_get_node_id(void)
{
return cpu_to_node(smp_processor_id());
}
static int zip_init_hw(struct zip_device *zip)
{
union zip_cmd_ctl cmd_ctl;
union zip_constants constants;
union zip_que_ena que_ena;
union zip_quex_map que_map;
union zip_que_pri que_pri;
union zip_quex_sbuf_addr que_sbuf_addr;
union zip_quex_sbuf_ctl que_sbuf_ctl;
int q = 0;
cmd_ctl.u_reg64 = zip_reg_read(zip->reg_base + ZIP_CMD_CTL);
cmd_ctl.s.forceclk = 1;
zip_reg_write(cmd_ctl.u_reg64 & 0xFF, (zip->reg_base + ZIP_CMD_CTL));
zip_msg("ZIP_CMD_CTL : 0x%016llx",
zip_reg_read(zip->reg_base + ZIP_CMD_CTL));
constants.u_reg64 = zip_reg_read(zip->reg_base + ZIP_CONSTANTS);
zip->depth = constants.s.depth;
zip->onfsize = constants.s.onfsize;
zip->ctxsize = constants.s.ctxsize;
zip_msg("depth: 0x%016llx , onfsize : 0x%016llx , ctxsize : 0x%016llx",
zip->depth, zip->onfsize, zip->ctxsize);
for (q = 0; q < ZIP_NUM_QUEUES; q++) {
que_sbuf_ctl.u_reg64 = 0ull;
que_sbuf_ctl.s.size = (ZIP_CMD_QBUF_SIZE / sizeof(u64));
que_sbuf_ctl.s.inst_be = 0;
que_sbuf_ctl.s.stream_id = 0;
zip_reg_write(que_sbuf_ctl.u_reg64,
(zip->reg_base + ZIP_QUEX_SBUF_CTL(q)));
zip_msg("QUEX_SBUF_CTL[%d]: 0x%016llx", q,
zip_reg_read(zip->reg_base + ZIP_QUEX_SBUF_CTL(q)));
}
for (q = 0; q < ZIP_NUM_QUEUES; q++) {
memset(&zip->iq[q], 0x0, sizeof(struct zip_iq));
spin_lock_init(&zip->iq[q].lock);
if (zip_cmd_qbuf_alloc(zip, q)) {
while (q != 0) {
q--;
zip_cmd_qbuf_free(zip, q);
}
return -ENOMEM;
}
zip->iq[q].sw_tail = zip->iq[q].sw_head;
zip->iq[q].hw_tail = zip->iq[q].sw_head;
que_sbuf_addr.u_reg64 = 0ull;
que_sbuf_addr.s.ptr = (__pa(zip->iq[q].sw_head) >>
ZIP_128B_ALIGN);
zip_msg("QUE[%d]_PTR(PHYS): 0x%016llx", q,
(u64)que_sbuf_addr.s.ptr);
zip_reg_write(que_sbuf_addr.u_reg64,
(zip->reg_base + ZIP_QUEX_SBUF_ADDR(q)));
zip_msg("QUEX_SBUF_ADDR[%d]: 0x%016llx", q,
zip_reg_read(zip->reg_base + ZIP_QUEX_SBUF_ADDR(q)));
zip_dbg("sw_head :0x%lx sw_tail :0x%lx hw_tail :0x%lx",
zip->iq[q].sw_head, zip->iq[q].sw_tail,
zip->iq[q].hw_tail);
zip_dbg("sw_head phy addr : 0x%lx", que_sbuf_addr.s.ptr);
}
que_ena.u_reg64 = 0x0ull;
for (q = 0; q < ZIP_NUM_QUEUES; q++)
que_ena.s.ena |= (0x1 << q);
zip_reg_write(que_ena.u_reg64, (zip->reg_base + ZIP_QUE_ENA));
zip_msg("QUE_ENA : 0x%016llx",
zip_reg_read(zip->reg_base + ZIP_QUE_ENA));
for (q = 0; q < ZIP_NUM_QUEUES; q++) {
que_map.u_reg64 = 0ull;
que_map.s.zce = 0x3;
zip_reg_write(que_map.u_reg64,
(zip->reg_base + ZIP_QUEX_MAP(q)));
zip_msg("QUE_MAP(%d) : 0x%016llx", q,
zip_reg_read(zip->reg_base + ZIP_QUEX_MAP(q)));
}
que_pri.u_reg64 = 0ull;
for (q = 0; q < ZIP_NUM_QUEUES; q++)
que_pri.s.pri |= (0x1 << q);
zip_reg_write(que_pri.u_reg64, (zip->reg_base + ZIP_QUE_PRI));
zip_msg("QUE_PRI %016llx", zip_reg_read(zip->reg_base + ZIP_QUE_PRI));
return 0;
}
static int zip_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct device *dev = &pdev->dev;
struct zip_device *zip = NULL;
int err;
zip = zip_alloc_device(pdev);
if (!zip)
return -ENOMEM;
dev_info(dev, "Found ZIP device %d %x:%x on Node %d\n", zip->index,
pdev->vendor, pdev->device, dev_to_node(dev));
pci_set_drvdata(pdev, zip);
zip->pdev = pdev;
err = pci_enable_device(pdev);
if (err) {
dev_err(dev, "Failed to enable PCI device");
goto err_free_device;
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_err(dev, "PCI request regions failed 0x%x", err);
goto err_disable_device;
}
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(48));
if (err) {
dev_err(dev, "Unable to get usable DMA configuration\n");
goto err_release_regions;
}
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(48));
if (err) {
dev_err(dev, "Unable to get 48-bit DMA for allocations\n");
goto err_release_regions;
}
zip->reg_base = pci_ioremap_bar(pdev, PCI_CFG_ZIP_PF_BAR0);
if (!zip->reg_base) {
dev_err(dev, "ZIP: Cannot map BAR0 CSR memory space, aborting");
err = -ENOMEM;
goto err_release_regions;
}
err = zip_init_hw(zip);
if (err)
goto err_release_regions;
return 0;
err_release_regions:
if (zip->reg_base)
iounmap(zip->reg_base);
pci_release_regions(pdev);
err_disable_device:
pci_disable_device(pdev);
err_free_device:
pci_set_drvdata(pdev, NULL);
zip_dev[zip->index] = NULL;
devm_kfree(dev, zip);
return err;
}
static void zip_remove(struct pci_dev *pdev)
{
struct zip_device *zip = pci_get_drvdata(pdev);
union zip_cmd_ctl cmd_ctl;
int q = 0;
if (!zip)
return;
if (zip->reg_base) {
cmd_ctl.u_reg64 = 0x0ull;
cmd_ctl.s.reset = 1;
zip_reg_write(cmd_ctl.u_reg64, (zip->reg_base + ZIP_CMD_CTL));
iounmap(zip->reg_base);
}
pci_release_regions(pdev);
pci_disable_device(pdev);
for (q = 0; q < ZIP_NUM_QUEUES; q++)
zip_cmd_qbuf_free(zip, q);
pci_set_drvdata(pdev, NULL);
zip_dev[zip->index] = NULL;
}
static int zip_register_compression_device(void)
{
int ret;
ret = crypto_register_alg(&zip_comp_deflate);
if (ret < 0) {
zip_err("Deflate algorithm registration failed\n");
return ret;
}
ret = crypto_register_alg(&zip_comp_lzs);
if (ret < 0) {
zip_err("LZS algorithm registration failed\n");
goto err_unregister_alg_deflate;
}
ret = crypto_register_scomp(&zip_scomp_deflate);
if (ret < 0) {
zip_err("Deflate scomp algorithm registration failed\n");
goto err_unregister_alg_lzs;
}
ret = crypto_register_scomp(&zip_scomp_lzs);
if (ret < 0) {
zip_err("LZS scomp algorithm registration failed\n");
goto err_unregister_scomp_deflate;
}
return ret;
err_unregister_scomp_deflate:
crypto_unregister_scomp(&zip_scomp_deflate);
err_unregister_alg_lzs:
crypto_unregister_alg(&zip_comp_lzs);
err_unregister_alg_deflate:
crypto_unregister_alg(&zip_comp_deflate);
return ret;
}
static void zip_unregister_compression_device(void)
{
crypto_unregister_alg(&zip_comp_deflate);
crypto_unregister_alg(&zip_comp_lzs);
crypto_unregister_scomp(&zip_scomp_deflate);
crypto_unregister_scomp(&zip_scomp_lzs);
}
static int zip_show_stats(struct seq_file *s, void *unused)
{
u64 val = 0ull;
u64 avg_chunk = 0ull, avg_cr = 0ull;
u32 q = 0;
int index = 0;
struct zip_device *zip;
struct zip_stats *st;
for (index = 0; index < MAX_ZIP_DEVICES; index++) {
if (zip_dev[index]) {
zip = zip_dev[index];
st = &zip->stats;
for (q = 0; q < ZIP_NUM_QUEUES; q++) {
val = zip_reg_read((zip->reg_base +
ZIP_DBG_COREX_STA(q)));
val = (val >> 32);
val = val & 0xffffff;
atomic64_add(val, &st->pending_req);
}
avg_chunk = (atomic64_read(&st->comp_in_bytes) /
atomic64_read(&st->comp_req_complete));
avg_cr = (atomic64_read(&st->comp_in_bytes) /
atomic64_read(&st->comp_out_bytes));
seq_printf(s, " ZIP Device %d Stats\n"
"-----------------------------------\n"
"Comp Req Submitted : \t%lld\n"
"Comp Req Completed : \t%lld\n"
"Compress In Bytes : \t%lld\n"
"Compressed Out Bytes : \t%lld\n"
"Average Chunk size : \t%llu\n"
"Average Compression ratio : \t%llu\n"
"Decomp Req Submitted : \t%lld\n"
"Decomp Req Completed : \t%lld\n"
"Decompress In Bytes : \t%lld\n"
"Decompressed Out Bytes : \t%lld\n"
"Decompress Bad requests : \t%lld\n"
"Pending Req : \t%lld\n"
"---------------------------------\n",
index,
(u64)atomic64_read(&st->comp_req_submit),
(u64)atomic64_read(&st->comp_req_complete),
(u64)atomic64_read(&st->comp_in_bytes),
(u64)atomic64_read(&st->comp_out_bytes),
avg_chunk,
avg_cr,
(u64)atomic64_read(&st->decomp_req_submit),
(u64)atomic64_read(&st->decomp_req_complete),
(u64)atomic64_read(&st->decomp_in_bytes),
(u64)atomic64_read(&st->decomp_out_bytes),
(u64)atomic64_read(&st->decomp_bad_reqs),
(u64)atomic64_read(&st->pending_req));
atomic64_set(&st->pending_req, 0);
}
}
return 0;
}
static int zip_clear_stats(struct seq_file *s, void *unused)
{
int index = 0;
for (index = 0; index < MAX_ZIP_DEVICES; index++) {
if (zip_dev[index]) {
memset(&zip_dev[index]->stats, 0,
sizeof(struct zip_stats));
seq_printf(s, "Cleared stats for zip %d\n", index);
}
}
return 0;
}
static int zip_print_regs(struct seq_file *s, void *unused)
{
u64 val = 0;
int i = 0, index = 0;
for (index = 0; index < MAX_ZIP_DEVICES; index++) {
if (zip_dev[index]) {
seq_printf(s, "--------------------------------\n"
" ZIP Device %d Registers\n"
"--------------------------------\n",
index);
i = 0;
while (zipregs[i].reg_name) {
val = zip_reg_read((zip_dev[index]->reg_base +
zipregs[i].reg_offset));
seq_printf(s, "%s: 0x%016llx\n",
zipregs[i].reg_name, val);
i++;
}
}
}
return 0;
}
static int zip_stats_open(struct inode *inode, struct file *file)
{
return single_open(file, zip_show_stats, NULL);
}
static int zip_clear_open(struct inode *inode, struct file *file)
{
return single_open(file, zip_clear_stats, NULL);
}
static int zip_regs_open(struct inode *inode, struct file *file)
{
return single_open(file, zip_print_regs, NULL);
}
static int __init zip_debugfs_init(void)
{
struct dentry *zip_stats, *zip_clear, *zip_regs;
if (!debugfs_initialized())
return -ENODEV;
zip_debugfs_root = debugfs_create_dir("thunderx_zip", NULL);
if (!zip_debugfs_root)
return -ENOMEM;
zip_stats = debugfs_create_file("zip_stats", 0444,
zip_debugfs_root,
NULL, &zip_stats_fops);
if (!zip_stats)
goto failed_to_create;
zip_clear = debugfs_create_file("zip_clear", 0444,
zip_debugfs_root,
NULL, &zip_clear_fops);
if (!zip_clear)
goto failed_to_create;
zip_regs = debugfs_create_file("zip_regs", 0444,
zip_debugfs_root,
NULL, &zip_regs_fops);
if (!zip_regs)
goto failed_to_create;
return 0;
failed_to_create:
debugfs_remove_recursive(zip_debugfs_root);
return -ENOENT;
}
static void __exit zip_debugfs_exit(void)
{
debugfs_remove_recursive(zip_debugfs_root);
}
static int __init zip_debugfs_init(void)
{
return 0;
}
static void __exit zip_debugfs_exit(void) { }
static int __init zip_init_module(void)
{
int ret;
zip_msg("%s\n", DRV_NAME);
ret = pci_register_driver(&zip_driver);
if (ret < 0) {
zip_err("ZIP: pci_register_driver() failed\n");
return ret;
}
ret = zip_register_compression_device();
if (ret < 0) {
zip_err("ZIP: Kernel Crypto Registration failed\n");
goto err_pci_unregister;
}
ret = zip_debugfs_init();
if (ret < 0) {
zip_err("ZIP: debugfs initialization failed\n");
goto err_crypto_unregister;
}
return ret;
err_crypto_unregister:
zip_unregister_compression_device();
err_pci_unregister:
pci_unregister_driver(&zip_driver);
return ret;
}
static void __exit zip_cleanup_module(void)
{
zip_debugfs_exit();
zip_unregister_compression_device();
pci_unregister_driver(&zip_driver);
}
