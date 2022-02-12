static inline void lru_add(struct ashmem_range *range)
{
list_add_tail(&range->lru, &ashmem_lru_list);
lru_count += range_size(range);
}
static inline void lru_del(struct ashmem_range *range)
{
list_del(&range->lru);
lru_count -= range_size(range);
}
static int range_alloc(struct ashmem_area *asma,
struct ashmem_range *prev_range, unsigned int purged,
size_t start, size_t end)
{
struct ashmem_range *range;
range = kmem_cache_zalloc(ashmem_range_cachep, GFP_KERNEL);
if (unlikely(!range))
return -ENOMEM;
range->asma = asma;
range->pgstart = start;
range->pgend = end;
range->purged = purged;
list_add_tail(&range->unpinned, &prev_range->unpinned);
if (range_on_lru(range))
lru_add(range);
return 0;
}
static void range_del(struct ashmem_range *range)
{
list_del(&range->unpinned);
if (range_on_lru(range))
lru_del(range);
kmem_cache_free(ashmem_range_cachep, range);
}
static inline void range_shrink(struct ashmem_range *range,
size_t start, size_t end)
{
size_t pre = range_size(range);
range->pgstart = start;
range->pgend = end;
if (range_on_lru(range))
lru_count -= pre - range_size(range);
}
static int ashmem_open(struct inode *inode, struct file *file)
{
struct ashmem_area *asma;
int ret;
ret = generic_file_open(inode, file);
if (unlikely(ret))
return ret;
asma = kmem_cache_zalloc(ashmem_area_cachep, GFP_KERNEL);
if (unlikely(!asma))
return -ENOMEM;
INIT_LIST_HEAD(&asma->unpinned_list);
memcpy(asma->name, ASHMEM_NAME_PREFIX, ASHMEM_NAME_PREFIX_LEN);
asma->prot_mask = PROT_MASK;
file->private_data = asma;
return 0;
}
static int ashmem_release(struct inode *ignored, struct file *file)
{
struct ashmem_area *asma = file->private_data;
struct ashmem_range *range, *next;
mutex_lock(&ashmem_mutex);
list_for_each_entry_safe(range, next, &asma->unpinned_list, unpinned)
range_del(range);
mutex_unlock(&ashmem_mutex);
if (asma->file)
fput(asma->file);
kmem_cache_free(ashmem_area_cachep, asma);
return 0;
}
static ssize_t ashmem_read(struct file *file, char __user *buf,
size_t len, loff_t *pos)
{
struct ashmem_area *asma = file->private_data;
int ret = 0;
mutex_lock(&ashmem_mutex);
if (asma->size == 0)
goto out_unlock;
if (!asma->file) {
ret = -EBADF;
goto out_unlock;
}
mutex_unlock(&ashmem_mutex);
ret = __vfs_read(asma->file, buf, len, pos);
if (ret >= 0) {
asma->file->f_pos = *pos;
}
return ret;
out_unlock:
mutex_unlock(&ashmem_mutex);
return ret;
}
static loff_t ashmem_llseek(struct file *file, loff_t offset, int origin)
{
struct ashmem_area *asma = file->private_data;
int ret;
mutex_lock(&ashmem_mutex);
if (asma->size == 0) {
ret = -EINVAL;
goto out;
}
if (!asma->file) {
ret = -EBADF;
goto out;
}
ret = vfs_llseek(asma->file, offset, origin);
if (ret < 0)
goto out;
file->f_pos = asma->file->f_pos;
out:
mutex_unlock(&ashmem_mutex);
return ret;
}
static inline vm_flags_t calc_vm_may_flags(unsigned long prot)
{
return _calc_vm_trans(prot, PROT_READ, VM_MAYREAD) |
_calc_vm_trans(prot, PROT_WRITE, VM_MAYWRITE) |
_calc_vm_trans(prot, PROT_EXEC, VM_MAYEXEC);
}
static int ashmem_mmap(struct file *file, struct vm_area_struct *vma)
{
struct ashmem_area *asma = file->private_data;
int ret = 0;
mutex_lock(&ashmem_mutex);
if (unlikely(!asma->size)) {
ret = -EINVAL;
goto out;
}
if (unlikely((vma->vm_flags & ~calc_vm_prot_bits(asma->prot_mask)) &
calc_vm_prot_bits(PROT_MASK))) {
ret = -EPERM;
goto out;
}
vma->vm_flags &= ~calc_vm_may_flags(~asma->prot_mask);
if (!asma->file) {
char *name = ASHMEM_NAME_DEF;
struct file *vmfile;
if (asma->name[ASHMEM_NAME_PREFIX_LEN] != '\0')
name = asma->name;
vmfile = shmem_file_setup(name, asma->size, vma->vm_flags);
if (IS_ERR(vmfile)) {
ret = PTR_ERR(vmfile);
goto out;
}
asma->file = vmfile;
}
get_file(asma->file);
if (vma->vm_flags & VM_SHARED) {
ret = shmem_zero_setup(vma);
if (ret) {
fput(asma->file);
goto out;
}
}
if (vma->vm_file)
fput(vma->vm_file);
vma->vm_file = asma->file;
out:
mutex_unlock(&ashmem_mutex);
return ret;
}
static unsigned long
ashmem_shrink_scan(struct shrinker *shrink, struct shrink_control *sc)
{
struct ashmem_range *range, *next;
unsigned long freed = 0;
if (!(sc->gfp_mask & __GFP_FS))
return SHRINK_STOP;
mutex_lock(&ashmem_mutex);
list_for_each_entry_safe(range, next, &ashmem_lru_list, lru) {
loff_t start = range->pgstart * PAGE_SIZE;
loff_t end = (range->pgend + 1) * PAGE_SIZE;
vfs_fallocate(range->asma->file,
FALLOC_FL_PUNCH_HOLE | FALLOC_FL_KEEP_SIZE,
start, end - start);
range->purged = ASHMEM_WAS_PURGED;
lru_del(range);
freed += range_size(range);
if (--sc->nr_to_scan <= 0)
break;
}
mutex_unlock(&ashmem_mutex);
return freed;
}
static unsigned long
ashmem_shrink_count(struct shrinker *shrink, struct shrink_control *sc)
{
return lru_count;
}
static int set_prot_mask(struct ashmem_area *asma, unsigned long prot)
{
int ret = 0;
mutex_lock(&ashmem_mutex);
if (unlikely((asma->prot_mask & prot) != prot)) {
ret = -EINVAL;
goto out;
}
if ((prot & PROT_READ) && (current->personality & READ_IMPLIES_EXEC))
prot |= PROT_EXEC;
asma->prot_mask = prot;
out:
mutex_unlock(&ashmem_mutex);
return ret;
}
static int set_name(struct ashmem_area *asma, void __user *name)
{
int len;
int ret = 0;
char local_name[ASHMEM_NAME_LEN];
len = strncpy_from_user(local_name, name, ASHMEM_NAME_LEN);
if (len < 0)
return len;
if (len == ASHMEM_NAME_LEN)
local_name[ASHMEM_NAME_LEN - 1] = '\0';
mutex_lock(&ashmem_mutex);
if (unlikely(asma->file))
ret = -EINVAL;
else
strcpy(asma->name + ASHMEM_NAME_PREFIX_LEN, local_name);
mutex_unlock(&ashmem_mutex);
return ret;
}
static int get_name(struct ashmem_area *asma, void __user *name)
{
int ret = 0;
size_t len;
char local_name[ASHMEM_NAME_LEN];
mutex_lock(&ashmem_mutex);
if (asma->name[ASHMEM_NAME_PREFIX_LEN] != '\0') {
len = strlen(asma->name + ASHMEM_NAME_PREFIX_LEN) + 1;
memcpy(local_name, asma->name + ASHMEM_NAME_PREFIX_LEN, len);
} else {
len = sizeof(ASHMEM_NAME_DEF);
memcpy(local_name, ASHMEM_NAME_DEF, len);
}
mutex_unlock(&ashmem_mutex);
if (unlikely(copy_to_user(name, local_name, len)))
ret = -EFAULT;
return ret;
}
static int ashmem_pin(struct ashmem_area *asma, size_t pgstart, size_t pgend)
{
struct ashmem_range *range, *next;
int ret = ASHMEM_NOT_PURGED;
list_for_each_entry_safe(range, next, &asma->unpinned_list, unpinned) {
if (range_before_page(range, pgstart))
break;
if (page_range_in_range(range, pgstart, pgend)) {
ret |= range->purged;
if (page_range_subsumes_range(range, pgstart, pgend)) {
range_del(range);
continue;
}
if (range->pgstart >= pgstart) {
range_shrink(range, pgend + 1, range->pgend);
continue;
}
if (range->pgend <= pgend) {
range_shrink(range, range->pgstart, pgstart-1);
continue;
}
range_alloc(asma, range, range->purged,
pgend + 1, range->pgend);
range_shrink(range, range->pgstart, pgstart - 1);
break;
}
}
return ret;
}
static int ashmem_unpin(struct ashmem_area *asma, size_t pgstart, size_t pgend)
{
struct ashmem_range *range, *next;
unsigned int purged = ASHMEM_NOT_PURGED;
restart:
list_for_each_entry_safe(range, next, &asma->unpinned_list, unpinned) {
if (range_before_page(range, pgstart))
break;
if (page_range_subsumed_by_range(range, pgstart, pgend))
return 0;
if (page_range_in_range(range, pgstart, pgend)) {
pgstart = min_t(size_t, range->pgstart, pgstart);
pgend = max_t(size_t, range->pgend, pgend);
purged |= range->purged;
range_del(range);
goto restart;
}
}
return range_alloc(asma, range, purged, pgstart, pgend);
}
static int ashmem_get_pin_status(struct ashmem_area *asma, size_t pgstart,
size_t pgend)
{
struct ashmem_range *range;
int ret = ASHMEM_IS_PINNED;
list_for_each_entry(range, &asma->unpinned_list, unpinned) {
if (range_before_page(range, pgstart))
break;
if (page_range_in_range(range, pgstart, pgend)) {
ret = ASHMEM_IS_UNPINNED;
break;
}
}
return ret;
}
static int ashmem_pin_unpin(struct ashmem_area *asma, unsigned long cmd,
void __user *p)
{
struct ashmem_pin pin;
size_t pgstart, pgend;
int ret = -EINVAL;
if (unlikely(!asma->file))
return -EINVAL;
if (unlikely(copy_from_user(&pin, p, sizeof(pin))))
return -EFAULT;
if (!pin.len)
pin.len = PAGE_ALIGN(asma->size) - pin.offset;
if (unlikely((pin.offset | pin.len) & ~PAGE_MASK))
return -EINVAL;
if (unlikely(((__u32) -1) - pin.offset < pin.len))
return -EINVAL;
if (unlikely(PAGE_ALIGN(asma->size) < pin.offset + pin.len))
return -EINVAL;
pgstart = pin.offset / PAGE_SIZE;
pgend = pgstart + (pin.len / PAGE_SIZE) - 1;
mutex_lock(&ashmem_mutex);
switch (cmd) {
case ASHMEM_PIN:
ret = ashmem_pin(asma, pgstart, pgend);
break;
case ASHMEM_UNPIN:
ret = ashmem_unpin(asma, pgstart, pgend);
break;
case ASHMEM_GET_PIN_STATUS:
ret = ashmem_get_pin_status(asma, pgstart, pgend);
break;
}
mutex_unlock(&ashmem_mutex);
return ret;
}
static long ashmem_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct ashmem_area *asma = file->private_data;
long ret = -ENOTTY;
switch (cmd) {
case ASHMEM_SET_NAME:
ret = set_name(asma, (void __user *)arg);
break;
case ASHMEM_GET_NAME:
ret = get_name(asma, (void __user *)arg);
break;
case ASHMEM_SET_SIZE:
ret = -EINVAL;
if (!asma->file) {
ret = 0;
asma->size = (size_t) arg;
}
break;
case ASHMEM_GET_SIZE:
ret = asma->size;
break;
case ASHMEM_SET_PROT_MASK:
ret = set_prot_mask(asma, arg);
break;
case ASHMEM_GET_PROT_MASK:
ret = asma->prot_mask;
break;
case ASHMEM_PIN:
case ASHMEM_UNPIN:
case ASHMEM_GET_PIN_STATUS:
ret = ashmem_pin_unpin(asma, cmd, (void __user *)arg);
break;
case ASHMEM_PURGE_ALL_CACHES:
ret = -EPERM;
if (capable(CAP_SYS_ADMIN)) {
struct shrink_control sc = {
.gfp_mask = GFP_KERNEL,
.nr_to_scan = LONG_MAX,
};
ret = ashmem_shrink_count(&ashmem_shrinker, &sc);
ashmem_shrink_scan(&ashmem_shrinker, &sc);
}
break;
}
return ret;
}
static long compat_ashmem_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
switch (cmd) {
case COMPAT_ASHMEM_SET_SIZE:
cmd = ASHMEM_SET_SIZE;
break;
case COMPAT_ASHMEM_SET_PROT_MASK:
cmd = ASHMEM_SET_PROT_MASK;
break;
}
return ashmem_ioctl(file, cmd, arg);
}
static int __init ashmem_init(void)
{
int ret;
ashmem_area_cachep = kmem_cache_create("ashmem_area_cache",
sizeof(struct ashmem_area),
0, 0, NULL);
if (unlikely(!ashmem_area_cachep)) {
pr_err("failed to create slab cache\n");
return -ENOMEM;
}
ashmem_range_cachep = kmem_cache_create("ashmem_range_cache",
sizeof(struct ashmem_range),
0, 0, NULL);
if (unlikely(!ashmem_range_cachep)) {
pr_err("failed to create slab cache\n");
return -ENOMEM;
}
ret = misc_register(&ashmem_misc);
if (unlikely(ret)) {
pr_err("failed to register misc device!\n");
return ret;
}
register_shrinker(&ashmem_shrinker);
pr_info("initialized\n");
return 0;
}
static void __exit ashmem_exit(void)
{
unregister_shrinker(&ashmem_shrinker);
misc_deregister(&ashmem_misc);
kmem_cache_destroy(ashmem_range_cachep);
kmem_cache_destroy(ashmem_area_cachep);
pr_info("unloaded\n");
}
