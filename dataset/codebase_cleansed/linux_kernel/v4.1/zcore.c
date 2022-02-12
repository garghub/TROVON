int memcpy_hsa(void *dest, unsigned long src, size_t count, int mode)
{
int offs, blk_num;
static char buf[PAGE_SIZE] __attribute__((__aligned__(PAGE_SIZE)));
if (!hsa_available)
return -ENODATA;
if (count == 0)
return 0;
offs = 0;
if ((src % PAGE_SIZE) != 0) {
blk_num = src / PAGE_SIZE + 2;
if (sclp_sdias_copy(buf, blk_num, 1)) {
TRACE("sclp_sdias_copy() failed\n");
return -EIO;
}
offs = min((PAGE_SIZE - (src % PAGE_SIZE)), count);
if (mode == TO_USER) {
if (copy_to_user((__force __user void*) dest,
buf + (src % PAGE_SIZE), offs))
return -EFAULT;
} else
memcpy(dest, buf + (src % PAGE_SIZE), offs);
}
if (offs == count)
goto out;
for (; (offs + PAGE_SIZE) <= count; offs += PAGE_SIZE) {
blk_num = (src + offs) / PAGE_SIZE + 2;
if (sclp_sdias_copy(buf, blk_num, 1)) {
TRACE("sclp_sdias_copy() failed\n");
return -EIO;
}
if (mode == TO_USER) {
if (copy_to_user((__force __user void*) dest + offs,
buf, PAGE_SIZE))
return -EFAULT;
} else
memcpy(dest + offs, buf, PAGE_SIZE);
}
if (offs == count)
goto out;
blk_num = (src + offs) / PAGE_SIZE + 2;
if (sclp_sdias_copy(buf, blk_num, 1)) {
TRACE("sclp_sdias_copy() failed\n");
return -EIO;
}
if (mode == TO_USER) {
if (copy_to_user((__force __user void*) dest + offs, buf,
count - offs))
return -EFAULT;
} else
memcpy(dest + offs, buf, count - offs);
out:
return 0;
}
static int memcpy_hsa_user(void __user *dest, unsigned long src, size_t count)
{
return memcpy_hsa((void __force *) dest, src, count, TO_USER);
}
static int memcpy_hsa_kernel(void *dest, unsigned long src, size_t count)
{
return memcpy_hsa(dest, src, count, TO_KERNEL);
}
static int __init init_cpu_info(enum arch_id arch)
{
struct save_area_ext *sa_ext;
sa_ext = dump_save_area_create(0);
if (!sa_ext)
return -ENOMEM;
if (memcpy_hsa_kernel(&sa_ext->sa, sys_info.sa_base,
sys_info.sa_size) < 0) {
TRACE("could not copy from HSA\n");
kfree(sa_ext);
return -EIO;
}
if (MACHINE_HAS_VX)
save_vx_regs_safe(sa_ext->vx_regs);
return 0;
}
static int copy_lc(void __user *buf, void *sa, int sa_off, int len)
{
int i;
char *lc_mask = (char*)&sys_info.lc_mask;
for (i = 0; i < len; i++) {
if (!lc_mask[i + sa_off])
continue;
if (copy_to_user(buf + i, sa + sa_off + i, 1))
return -EFAULT;
}
return 0;
}
static int zcore_add_lc(char __user *buf, unsigned long start, size_t count)
{
unsigned long end;
int i;
if (count == 0)
return 0;
end = start + count;
for (i = 0; i < dump_save_areas.count; i++) {
unsigned long cp_start, cp_end;
unsigned long sa_start, sa_end;
unsigned long prefix;
unsigned long sa_off, len, buf_off;
struct save_area *save_area = &dump_save_areas.areas[i]->sa;
prefix = save_area->pref_reg;
sa_start = prefix + sys_info.sa_base;
sa_end = prefix + sys_info.sa_base + sys_info.sa_size;
if ((end < sa_start) || (start > sa_end))
continue;
cp_start = max(start, sa_start);
cp_end = min(end, sa_end);
buf_off = cp_start - start;
sa_off = cp_start - sa_start;
len = cp_end - cp_start;
TRACE("copy_lc for: %lx\n", start);
if (copy_lc(buf + buf_off, save_area, sa_off, len))
return -EFAULT;
}
return 0;
}
static void release_hsa(void)
{
diag308(DIAG308_REL_HSA, NULL);
hsa_available = 0;
}
static ssize_t zcore_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
unsigned long mem_start;
size_t mem_offs;
size_t hdr_count;
size_t size;
int rc;
mutex_lock(&zcore_mutex);
if (*ppos > (sys_info.mem_size + HEADER_SIZE)) {
rc = -EINVAL;
goto fail;
}
count = min(count, (size_t) (sys_info.mem_size + HEADER_SIZE - *ppos));
if (*ppos < HEADER_SIZE) {
size = min(count, (size_t) (HEADER_SIZE - *ppos));
if (copy_to_user(buf, &zcore_header + *ppos, size)) {
rc = -EFAULT;
goto fail;
}
hdr_count = size;
mem_start = 0;
} else {
hdr_count = 0;
mem_start = *ppos - HEADER_SIZE;
}
mem_offs = 0;
if (*ppos < sclp_get_hsa_size() + HEADER_SIZE) {
size = min((count - hdr_count),
(size_t) (sclp_get_hsa_size() - mem_start));
rc = memcpy_hsa_user(buf + hdr_count, mem_start, size);
if (rc)
goto fail;
mem_offs += size;
}
size = count - mem_offs - hdr_count;
rc = copy_to_user_real(buf + hdr_count + mem_offs,
(void *) mem_start + mem_offs, size);
if (rc)
goto fail;
if (zcore_add_lc(buf + hdr_count, mem_start, count - hdr_count)) {
rc = -EFAULT;
goto fail;
}
*ppos += count;
fail:
mutex_unlock(&zcore_mutex);
return (rc < 0) ? rc : count;
}
static int zcore_open(struct inode *inode, struct file *filp)
{
if (!hsa_available)
return -ENODATA;
else
return capable(CAP_SYS_RAWIO) ? 0 : -EPERM;
}
static int zcore_release(struct inode *inode, struct file *filep)
{
if (hsa_available)
release_hsa();
return 0;
}
static loff_t zcore_lseek(struct file *file, loff_t offset, int orig)
{
loff_t rc;
mutex_lock(&zcore_mutex);
switch (orig) {
case 0:
file->f_pos = offset;
rc = file->f_pos;
break;
case 1:
file->f_pos += offset;
rc = file->f_pos;
break;
default:
rc = -EINVAL;
}
mutex_unlock(&zcore_mutex);
return rc;
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
diag308(DIAG308_IPL, NULL);
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
snprintf(str, sizeof(str), "%lx\n", sclp_get_hsa_size());
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
static void __init set_lc_mask(struct save_area *map)
{
memset(&map->fp_regs, 0xff, sizeof(map->fp_regs));
memset(&map->gp_regs, 0xff, sizeof(map->gp_regs));
memset(&map->psw, 0xff, sizeof(map->psw));
memset(&map->pref_reg, 0xff, sizeof(map->pref_reg));
memset(&map->fp_ctrl_reg, 0xff, sizeof(map->fp_ctrl_reg));
memset(&map->tod_reg, 0xff, sizeof(map->tod_reg));
memset(&map->timer, 0xff, sizeof(map->timer));
memset(&map->clk_cmp, 0xff, sizeof(map->clk_cmp));
memset(&map->acc_regs, 0xff, sizeof(map->acc_regs));
memset(&map->ctrl_regs, 0xff, sizeof(map->ctrl_regs));
}
static int __init sys_info_init(enum arch_id arch, unsigned long mem_end)
{
int rc;
switch (arch) {
case ARCH_S390X:
pr_alert("DETECTED 'S390X (64 bit) OS'\n");
break;
case ARCH_S390:
pr_alert("DETECTED 'S390 (32 bit) OS'\n");
break;
default:
pr_alert("0x%x is an unknown architecture.\n",arch);
return -EINVAL;
}
sys_info.sa_base = SAVE_AREA_BASE;
sys_info.sa_size = sizeof(struct save_area);
sys_info.arch = arch;
set_lc_mask(&sys_info.lc_mask);
rc = init_cpu_info(arch);
if (rc)
return rc;
sys_info.mem_size = mem_end;
return 0;
}
static int __init check_sdias(void)
{
if (!sclp_get_hsa_size()) {
TRACE("Could not determine HSA size\n");
return -ENODEV;
}
return 0;
}
static int __init get_mem_info(unsigned long *mem, unsigned long *end)
{
struct memblock_region *reg;
for_each_memblock(memory, reg) {
*mem += reg->size;
*end = max_t(unsigned long, *end, reg->base + reg->size);
}
return 0;
}
static void __init zcore_header_init(int arch, struct zcore_header *hdr,
unsigned long mem_size)
{
u32 prefix;
int i;
if (arch == ARCH_S390X)
hdr->arch_id = DUMP_ARCH_S390X;
else
hdr->arch_id = DUMP_ARCH_S390;
hdr->mem_size = mem_size;
hdr->rmem_size = mem_size;
hdr->mem_end = sys_info.mem_size;
hdr->num_pages = mem_size / PAGE_SIZE;
hdr->tod = get_tod_clock();
get_cpu_id(&hdr->cpu_id);
for (i = 0; i < dump_save_areas.count; i++) {
prefix = dump_save_areas.areas[i]->sa.pref_reg;
hdr->real_cpu_cnt++;
if (!prefix)
continue;
hdr->lc_vec[hdr->cpu_cnt] = prefix;
hdr->cpu_cnt++;
}
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
if (ipib_info.ipib < sclp_get_hsa_size())
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
unsigned long mem_size, mem_end;
unsigned char arch;
int rc;
mem_size = mem_end = 0;
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
rc = get_mem_info(&mem_size, &mem_end);
if (rc)
goto fail;
rc = sys_info_init(arch, mem_end);
if (rc)
goto fail;
zcore_header_init(arch, &zcore_header, mem_size);
rc = zcore_reipl_init();
if (rc)
goto fail;
zcore_dir = debugfs_create_dir("zcore" , NULL);
if (!zcore_dir) {
rc = -ENOMEM;
goto fail;
}
zcore_file = debugfs_create_file("mem", S_IRUSR, zcore_dir, NULL,
&zcore_fops);
if (!zcore_file) {
rc = -ENOMEM;
goto fail_dir;
}
zcore_memmap_file = debugfs_create_file("memmap", S_IRUSR, zcore_dir,
NULL, &zcore_memmap_fops);
if (!zcore_memmap_file) {
rc = -ENOMEM;
goto fail_file;
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
fail_file:
debugfs_remove(zcore_file);
fail_dir:
debugfs_remove(zcore_dir);
fail:
diag308(DIAG308_REL_HSA, NULL);
return rc;
}
static void __exit zcore_exit(void)
{
debug_unregister(zcore_dbf);
sclp_sdias_exit();
free_page((unsigned long) ipl_block);
debugfs_remove(zcore_hsa_file);
debugfs_remove(zcore_reipl_file);
debugfs_remove(zcore_memmap_file);
debugfs_remove(zcore_file);
debugfs_remove(zcore_dir);
diag308(DIAG308_REL_HSA, NULL);
}
