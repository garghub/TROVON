static int xpram_page_in (unsigned long page_addr, unsigned int xpage_index)
{
int cc = 2;
asm volatile(
" .insn rre,0xb22e0000,%1,%2\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (cc) : "a" (__pa(page_addr)), "d" (xpage_index) : "cc");
if (cc == 3)
return -ENXIO;
if (cc == 2)
return -ENXIO;
if (cc == 1)
return -EIO;
return 0;
}
static long xpram_page_out (unsigned long page_addr, unsigned int xpage_index)
{
int cc = 2;
asm volatile(
" .insn rre,0xb22f0000,%1,%2\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (cc) : "a" (__pa(page_addr)), "d" (xpage_index) : "cc");
if (cc == 3)
return -ENXIO;
if (cc == 2)
return -ENXIO;
if (cc == 1)
return -EIO;
return 0;
}
static int xpram_present(void)
{
unsigned long mem_page;
int rc;
mem_page = (unsigned long) __get_free_page(GFP_KERNEL);
if (!mem_page)
return -ENOMEM;
rc = xpram_page_in(mem_page, 0);
free_page(mem_page);
return rc ? -ENXIO : 0;
}
static unsigned long xpram_highest_page_index(void)
{
unsigned int page_index, add_bit;
unsigned long mem_page;
mem_page = (unsigned long) __get_free_page(GFP_KERNEL);
if (!mem_page)
return 0;
page_index = 0;
add_bit = 1ULL << (sizeof(unsigned int)*8 - 1);
while (add_bit > 0) {
if (xpram_page_in(mem_page, page_index | add_bit) == 0)
page_index |= add_bit;
add_bit >>= 1;
}
free_page (mem_page);
return page_index;
}
static void xpram_make_request(struct request_queue *q, struct bio *bio)
{
xpram_device_t *xdev = bio->bi_bdev->bd_disk->private_data;
struct bio_vec bvec;
struct bvec_iter iter;
unsigned int index;
unsigned long page_addr;
unsigned long bytes;
if ((bio->bi_iter.bi_sector & 7) != 0 ||
(bio->bi_iter.bi_size & 4095) != 0)
goto fail;
if ((bio->bi_iter.bi_size >> 12) > xdev->size)
goto fail;
if ((bio->bi_iter.bi_sector >> 3) > 0xffffffffU - xdev->offset)
goto fail;
index = (bio->bi_iter.bi_sector >> 3) + xdev->offset;
bio_for_each_segment(bvec, bio, iter) {
page_addr = (unsigned long)
kmap(bvec.bv_page) + bvec.bv_offset;
bytes = bvec.bv_len;
if ((page_addr & 4095) != 0 || (bytes & 4095) != 0)
goto fail;
while (bytes > 0) {
if (bio_data_dir(bio) == READ) {
if (xpram_page_in(page_addr, index) != 0)
goto fail;
} else {
if (xpram_page_out(page_addr, index) != 0)
goto fail;
}
page_addr += 4096;
bytes -= 4096;
index++;
}
}
set_bit(BIO_UPTODATE, &bio->bi_flags);
bio_endio(bio, 0);
return;
fail:
bio_io_error(bio);
}
static int xpram_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
unsigned long size;
size = (xpram_pages * 8) & ~0x3f;
geo->cylinders = size >> 6;
geo->heads = 4;
geo->sectors = 16;
geo->start = 4;
return 0;
}
static int __init xpram_setup_sizes(unsigned long pages)
{
unsigned long mem_needed;
unsigned long mem_auto;
unsigned long long size;
char *sizes_end;
int mem_auto_no;
int i;
if (devs <= 0 || devs > XPRAM_MAX_DEVS) {
pr_err("%d is not a valid number of XPRAM devices\n",devs);
return -EINVAL;
}
xpram_devs = devs;
mem_needed = 0;
mem_auto_no = 0;
for (i = 0; i < xpram_devs; i++) {
if (sizes[i]) {
size = simple_strtoull(sizes[i], &sizes_end, 0);
switch (*sizes_end) {
case 'g':
case 'G':
size <<= 20;
break;
case 'm':
case 'M':
size <<= 10;
}
xpram_sizes[i] = (size + 3) & -4UL;
}
if (xpram_sizes[i])
mem_needed += xpram_sizes[i];
else
mem_auto_no++;
}
pr_info(" number of devices (partitions): %d \n", xpram_devs);
for (i = 0; i < xpram_devs; i++) {
if (xpram_sizes[i])
pr_info(" size of partition %d: %u kB\n",
i, xpram_sizes[i]);
else
pr_info(" size of partition %d to be set "
"automatically\n",i);
}
pr_info(" memory needed (for sized partitions): %lu kB\n",
mem_needed);
pr_info(" partitions to be sized automatically: %d\n",
mem_auto_no);
if (mem_needed > pages * 4) {
pr_err("Not enough expanded memory available\n");
return -EINVAL;
}
if (mem_auto_no) {
mem_auto = ((pages - mem_needed / 4) / mem_auto_no) * 4;
pr_info(" automatically determined "
"partition size: %lu kB\n", mem_auto);
for (i = 0; i < xpram_devs; i++)
if (xpram_sizes[i] == 0)
xpram_sizes[i] = mem_auto;
}
return 0;
}
static int __init xpram_setup_blkdev(void)
{
unsigned long offset;
int i, rc = -ENOMEM;
for (i = 0; i < xpram_devs; i++) {
xpram_disks[i] = alloc_disk(1);
if (!xpram_disks[i])
goto out;
xpram_queues[i] = blk_alloc_queue(GFP_KERNEL);
if (!xpram_queues[i]) {
put_disk(xpram_disks[i]);
goto out;
}
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, xpram_queues[i]);
blk_queue_make_request(xpram_queues[i], xpram_make_request);
blk_queue_logical_block_size(xpram_queues[i], 4096);
}
rc = register_blkdev(XPRAM_MAJOR, XPRAM_NAME);
if (rc < 0)
goto out;
offset = 0;
for (i = 0; i < xpram_devs; i++) {
struct gendisk *disk = xpram_disks[i];
xpram_devices[i].size = xpram_sizes[i] / 4;
xpram_devices[i].offset = offset;
offset += xpram_devices[i].size;
disk->major = XPRAM_MAJOR;
disk->first_minor = i;
disk->fops = &xpram_devops;
disk->private_data = &xpram_devices[i];
disk->queue = xpram_queues[i];
sprintf(disk->disk_name, "slram%d", i);
set_capacity(disk, xpram_sizes[i] << 1);
add_disk(disk);
}
return 0;
out:
while (i--) {
blk_cleanup_queue(xpram_queues[i]);
put_disk(xpram_disks[i]);
}
return rc;
}
static void xpram_resume_error(const char *message)
{
pr_err("Resuming the system failed: %s\n", message);
panic("xpram resume error\n");
}
static int xpram_restore(struct device *dev)
{
if (!xpram_pages)
return 0;
if (xpram_present() != 0)
xpram_resume_error("xpram disappeared");
if (xpram_pages != xpram_highest_page_index() + 1)
xpram_resume_error("Size of xpram changed");
return 0;
}
static void __exit xpram_exit(void)
{
int i;
for (i = 0; i < xpram_devs; i++) {
del_gendisk(xpram_disks[i]);
blk_cleanup_queue(xpram_queues[i]);
put_disk(xpram_disks[i]);
}
unregister_blkdev(XPRAM_MAJOR, XPRAM_NAME);
platform_device_unregister(xpram_pdev);
platform_driver_unregister(&xpram_pdrv);
}
static int __init xpram_init(void)
{
int rc;
if (xpram_present() != 0) {
pr_err("No expanded memory available\n");
return -ENODEV;
}
xpram_pages = xpram_highest_page_index() + 1;
pr_info(" %u pages expanded memory found (%lu KB).\n",
xpram_pages, (unsigned long) xpram_pages*4);
rc = xpram_setup_sizes(xpram_pages);
if (rc)
return rc;
rc = platform_driver_register(&xpram_pdrv);
if (rc)
return rc;
xpram_pdev = platform_device_register_simple(XPRAM_NAME, -1, NULL, 0);
if (IS_ERR(xpram_pdev)) {
rc = PTR_ERR(xpram_pdev);
goto fail_platform_driver_unregister;
}
rc = xpram_setup_blkdev();
if (rc)
goto fail_platform_device_unregister;
return 0;
fail_platform_device_unregister:
platform_device_unregister(xpram_pdev);
fail_platform_driver_unregister:
platform_driver_unregister(&xpram_pdrv);
return rc;
}
