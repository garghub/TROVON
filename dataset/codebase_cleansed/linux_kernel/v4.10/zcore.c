int memcpy_hsa_user(void __user *dest, unsigned long src, size_t count)
{
unsigned long offset, bytes;
if (!hsa_available)
return -ENODATA;
while (count) {
if (sclp_sdias_copy(hsa_buf, src / PAGE_SIZE + 2, 1)) {
TRACE("sclp_sdias_copy() failed\n");
return -EIO;
}
offset = src % PAGE_SIZE;
bytes = min(PAGE_SIZE - offset, count);
if (copy_to_user(dest, hsa_buf + offset, bytes))
return -EFAULT;
src += bytes;
dest += bytes;
count -= bytes;
}
return 0;
}
int memcpy_hsa_kernel(void *dest, unsigned long src, size_t count)
{
unsigned long offset, bytes;
if (!hsa_available)
return -ENODATA;
while (count) {
if (sclp_sdias_copy(hsa_buf, src / PAGE_SIZE + 2, 1)) {
TRACE("sclp_sdias_copy() failed\n");
return -EIO;
}
offset = src % PAGE_SIZE;
bytes = min(PAGE_SIZE - offset, count);
memcpy(dest, hsa_buf + offset, bytes);
src += bytes;
dest += bytes;
count -= bytes;
}
return 0;
}
static int __init init_cpu_info(void)
{
struct save_area *sa;
sa = save_area_boot_cpu();
if (!sa)
return -ENOMEM;
if (memcpy_hsa_kernel(hsa_buf, __LC_FPREGS_SAVE_AREA, 512) < 0) {
TRACE("could not copy from HSA\n");
return -EIO;
}
save_area_add_regs(sa, hsa_buf);
return 0;
}
static void release_hsa(void)
{
diag308(DIAG308_REL_HSA, NULL);
hsa_available = 0;
}
static ssize_t zcore_memmap_read(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
return simple_read_from_buffer(buf, count, ppos, filp->private_data,
memblock.memory.cnt * CHUNK_INFO_SIZE);
}
static int zcore_memmap_open(struct inode *inode, struct file *filp)
{
struct memblock_region *reg;
char *buf;
int i = 0;
buf = kzalloc(memblock.memory.cnt * CHUNK_INFO_SIZE, GFP_KERNEL);
if (!buf) {
return -ENOMEM;
}
for_each_memblock(memory, reg) {
sprintf(buf + (i++ * CHUNK_INFO_SIZE), "%016llx %016llx ",
(unsigned long long) reg->base,
(unsigned long long) reg->size);
}
filp->private_data = buf;
return nonseekable_open(inode, filp);
}
static int zcore_memmap_release(struct inode *inode, struct file *filp)
{
kfree(filp->private_data);
return 0;
}
static ssize_t zcore_reipl_write(struct file *filp, const char __user *buf,
size_t count, loff_t *ppos)
{
if (ipl_block) {
diag308(DIAG308_SET, ipl_block);
diag308(DIAG308_LOAD_CLEAR, NULL);
}
return count;
}
static int zcore_reipl_open(struct inode *inode, struct file *filp)
{
return nonseekable_open(inode, filp);
}
static int zcore_reipl_release(struct inode *inode, struct file *filp)
{
return 0;
}
static ssize_t zcore_hsa_read(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
static char str[18];
if (hsa_available)
snprintf(str, sizeof(str), "%lx\n", sclp.hsa_size);
else
snprintf(str, sizeof(str), "0\n");
return simple_read_from_buffer(buf, count, ppos, str, strlen(str));
}
static ssize_t zcore_hsa_write(struct file *filp, const char __user *buf,
size_t count, loff_t *ppos)
{
char value;
if (*ppos != 0)
return -EPIPE;
if (copy_from_user(&value, buf, 1))
return -EFAULT;
if (value != '0')
return -EINVAL;
release_hsa();
return count;
}
static int __init check_sdias(void)
{
if (!sclp.hsa_size) {
TRACE("Could not determine HSA size\n");
return -ENODEV;
}
return 0;
}
static int __init zcore_reipl_init(void)
{
struct ipib_info ipib_info;
int rc;
rc = memcpy_hsa_kernel(&ipib_info, __LC_DUMP_REIPL, sizeof(ipib_info));
if (rc)
return rc;
if (ipib_info.ipib == 0)
return 0;
ipl_block = (void *) __get_free_page(GFP_KERNEL);
if (!ipl_block)
return -ENOMEM;
if (ipib_info.ipib < sclp.hsa_size)
rc = memcpy_hsa_kernel(ipl_block, ipib_info.ipib, PAGE_SIZE);
else
rc = memcpy_real(ipl_block, (void *) ipib_info.ipib, PAGE_SIZE);
if (rc || csum_partial(ipl_block, ipl_block->hdr.len, 0) !=
ipib_info.checksum) {
TRACE("Checksum does not match\n");
free_page((unsigned long) ipl_block);
ipl_block = NULL;
}
return 0;
}
static int __init zcore_init(void)
{
unsigned char arch;
int rc;
if (ipl_info.type != IPL_TYPE_FCP_DUMP)
return -ENODATA;
if (OLDMEM_BASE)
return -ENODATA;
zcore_dbf = debug_register("zcore", 4, 1, 4 * sizeof(long));
debug_register_view(zcore_dbf, &debug_sprintf_view);
debug_set_level(zcore_dbf, 6);
TRACE("devno: %x\n", ipl_info.data.fcp.dev_id.devno);
TRACE("wwpn: %llx\n", (unsigned long long) ipl_info.data.fcp.wwpn);
TRACE("lun: %llx\n", (unsigned long long) ipl_info.data.fcp.lun);
rc = sclp_sdias_init();
if (rc)
goto fail;
rc = check_sdias();
if (rc)
goto fail;
hsa_available = 1;
rc = memcpy_hsa_kernel(&arch, __LC_AR_MODE_ID, 1);
if (rc)
goto fail;
if (arch == ARCH_S390) {
pr_alert("The 64-bit dump tool cannot be used for a "
"32-bit system\n");
rc = -EINVAL;
goto fail;
}
pr_alert("The dump process started for a 64-bit operating system\n");
rc = init_cpu_info();
if (rc)
goto fail;
rc = zcore_reipl_init();
if (rc)
goto fail;
zcore_dir = debugfs_create_dir("zcore" , NULL);
if (!zcore_dir) {
rc = -ENOMEM;
goto fail;
}
zcore_memmap_file = debugfs_create_file("memmap", S_IRUSR, zcore_dir,
NULL, &zcore_memmap_fops);
if (!zcore_memmap_file) {
rc = -ENOMEM;
goto fail_dir;
}
zcore_reipl_file = debugfs_create_file("reipl", S_IRUSR, zcore_dir,
NULL, &zcore_reipl_fops);
if (!zcore_reipl_file) {
rc = -ENOMEM;
goto fail_memmap_file;
}
zcore_hsa_file = debugfs_create_file("hsa", S_IRUSR|S_IWUSR, zcore_dir,
NULL, &zcore_hsa_fops);
if (!zcore_hsa_file) {
rc = -ENOMEM;
goto fail_reipl_file;
}
return 0;
fail_reipl_file:
debugfs_remove(zcore_reipl_file);
fail_memmap_file:
debugfs_remove(zcore_memmap_file);
fail_dir:
debugfs_remove(zcore_dir);
fail:
diag308(DIAG308_REL_HSA, NULL);
return rc;
}
