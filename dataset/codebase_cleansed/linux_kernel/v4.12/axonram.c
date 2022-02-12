static ssize_t
axon_ram_sysfs_ecc(struct device *dev, struct device_attribute *attr, char *buf)
{
struct platform_device *device = to_platform_device(dev);
struct axon_ram_bank *bank = device->dev.platform_data;
BUG_ON(!bank);
return sprintf(buf, "%ld\n", bank->ecc_counter);
}
static irqreturn_t
axon_ram_irq_handler(int irq, void *dev)
{
struct platform_device *device = dev;
struct axon_ram_bank *bank = device->dev.platform_data;
BUG_ON(!bank);
dev_err(&device->dev, "Correctable memory error occurred\n");
bank->ecc_counter++;
return IRQ_HANDLED;
}
static blk_qc_t
axon_ram_make_request(struct request_queue *queue, struct bio *bio)
{
struct axon_ram_bank *bank = bio->bi_bdev->bd_disk->private_data;
unsigned long phys_mem, phys_end;
void *user_mem;
struct bio_vec vec;
unsigned int transfered;
struct bvec_iter iter;
phys_mem = bank->io_addr + (bio->bi_iter.bi_sector <<
AXON_RAM_SECTOR_SHIFT);
phys_end = bank->io_addr + bank->size;
transfered = 0;
bio_for_each_segment(vec, bio, iter) {
if (unlikely(phys_mem + vec.bv_len > phys_end)) {
bio_io_error(bio);
return BLK_QC_T_NONE;
}
user_mem = page_address(vec.bv_page) + vec.bv_offset;
if (bio_data_dir(bio) == READ)
memcpy(user_mem, (void *) phys_mem, vec.bv_len);
else
memcpy((void *) phys_mem, user_mem, vec.bv_len);
phys_mem += vec.bv_len;
transfered += vec.bv_len;
}
bio_endio(bio);
return BLK_QC_T_NONE;
}
static long
__axon_ram_direct_access(struct axon_ram_bank *bank, pgoff_t pgoff, long nr_pages,
void **kaddr, pfn_t *pfn)
{
resource_size_t offset = pgoff * PAGE_SIZE;
*kaddr = (void *) bank->io_addr + offset;
*pfn = phys_to_pfn_t(bank->ph_addr + offset, PFN_DEV);
return (bank->size - offset) / PAGE_SIZE;
}
static long
axon_ram_dax_direct_access(struct dax_device *dax_dev, pgoff_t pgoff, long nr_pages,
void **kaddr, pfn_t *pfn)
{
struct axon_ram_bank *bank = dax_get_private(dax_dev);
return __axon_ram_direct_access(bank, pgoff, nr_pages, kaddr, pfn);
}
static int axon_ram_probe(struct platform_device *device)
{
static int axon_ram_bank_id = -1;
struct axon_ram_bank *bank;
struct resource resource;
int rc = 0;
axon_ram_bank_id++;
dev_info(&device->dev, "Found memory controller on %s\n",
device->dev.of_node->full_name);
bank = kzalloc(sizeof(struct axon_ram_bank), GFP_KERNEL);
if (bank == NULL) {
dev_err(&device->dev, "Out of memory\n");
rc = -ENOMEM;
goto failed;
}
device->dev.platform_data = bank;
bank->device = device;
if (of_address_to_resource(device->dev.of_node, 0, &resource) != 0) {
dev_err(&device->dev, "Cannot access device tree\n");
rc = -EFAULT;
goto failed;
}
bank->size = resource_size(&resource);
if (bank->size == 0) {
dev_err(&device->dev, "No DDR2 memory found for %s%d\n",
AXON_RAM_DEVICE_NAME, axon_ram_bank_id);
rc = -ENODEV;
goto failed;
}
dev_info(&device->dev, "Register DDR2 memory device %s%d with %luMB\n",
AXON_RAM_DEVICE_NAME, axon_ram_bank_id, bank->size >> 20);
bank->ph_addr = resource.start;
bank->io_addr = (unsigned long) ioremap_prot(
bank->ph_addr, bank->size, _PAGE_NO_CACHE);
if (bank->io_addr == 0) {
dev_err(&device->dev, "ioremap() failed\n");
rc = -EFAULT;
goto failed;
}
bank->disk = alloc_disk(AXON_RAM_MINORS_PER_DISK);
if (bank->disk == NULL) {
dev_err(&device->dev, "Cannot register disk\n");
rc = -EFAULT;
goto failed;
}
bank->disk->major = azfs_major;
bank->disk->first_minor = azfs_minor;
bank->disk->fops = &axon_ram_devops;
bank->disk->private_data = bank;
sprintf(bank->disk->disk_name, "%s%d",
AXON_RAM_DEVICE_NAME, axon_ram_bank_id);
bank->dax_dev = alloc_dax(bank, bank->disk->disk_name,
&axon_ram_dax_ops);
if (!bank->dax_dev) {
rc = -ENOMEM;
goto failed;
}
bank->disk->queue = blk_alloc_queue(GFP_KERNEL);
if (bank->disk->queue == NULL) {
dev_err(&device->dev, "Cannot register disk queue\n");
rc = -EFAULT;
goto failed;
}
set_capacity(bank->disk, bank->size >> AXON_RAM_SECTOR_SHIFT);
blk_queue_make_request(bank->disk->queue, axon_ram_make_request);
blk_queue_logical_block_size(bank->disk->queue, AXON_RAM_SECTOR_SIZE);
device_add_disk(&device->dev, bank->disk);
bank->irq_id = irq_of_parse_and_map(device->dev.of_node, 0);
if (!bank->irq_id) {
dev_err(&device->dev, "Cannot access ECC interrupt ID\n");
rc = -EFAULT;
goto failed;
}
rc = request_irq(bank->irq_id, axon_ram_irq_handler,
AXON_RAM_IRQ_FLAGS, bank->disk->disk_name, device);
if (rc != 0) {
dev_err(&device->dev, "Cannot register ECC interrupt handler\n");
bank->irq_id = 0;
rc = -EFAULT;
goto failed;
}
rc = device_create_file(&device->dev, &dev_attr_ecc);
if (rc != 0) {
dev_err(&device->dev, "Cannot create sysfs file\n");
rc = -EFAULT;
goto failed;
}
azfs_minor += bank->disk->minors;
return 0;
failed:
if (bank != NULL) {
if (bank->irq_id)
free_irq(bank->irq_id, device);
if (bank->disk != NULL) {
if (bank->disk->major > 0)
unregister_blkdev(bank->disk->major,
bank->disk->disk_name);
if (bank->disk->flags & GENHD_FL_UP)
del_gendisk(bank->disk);
put_disk(bank->disk);
}
kill_dax(bank->dax_dev);
put_dax(bank->dax_dev);
device->dev.platform_data = NULL;
if (bank->io_addr != 0)
iounmap((void __iomem *) bank->io_addr);
kfree(bank);
}
return rc;
}
static int
axon_ram_remove(struct platform_device *device)
{
struct axon_ram_bank *bank = device->dev.platform_data;
BUG_ON(!bank || !bank->disk);
device_remove_file(&device->dev, &dev_attr_ecc);
free_irq(bank->irq_id, device);
kill_dax(bank->dax_dev);
put_dax(bank->dax_dev);
del_gendisk(bank->disk);
put_disk(bank->disk);
iounmap((void __iomem *) bank->io_addr);
kfree(bank);
return 0;
}
static int __init
axon_ram_init(void)
{
azfs_major = register_blkdev(azfs_major, AXON_RAM_DEVICE_NAME);
if (azfs_major < 0) {
printk(KERN_ERR "%s cannot become block device major number\n",
AXON_RAM_MODULE_NAME);
return -EFAULT;
}
azfs_minor = 0;
return platform_driver_register(&axon_ram_driver);
}
static void __exit
axon_ram_exit(void)
{
platform_driver_unregister(&axon_ram_driver);
unregister_blkdev(azfs_major, AXON_RAM_DEVICE_NAME);
}
