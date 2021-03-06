void sq_flush_range(unsigned long start, unsigned int len)
{
unsigned long *sq = (unsigned long *)start;
for (len >>= 5; len--; sq += 8)
prefetchw(sq);
store_queue_barrier();
}
static inline void sq_mapping_list_add(struct sq_mapping *map)
{
struct sq_mapping **p, *tmp;
spin_lock_irq(&sq_mapping_lock);
p = &sq_mapping_list;
while ((tmp = *p) != NULL)
p = &tmp->next;
map->next = tmp;
*p = map;
spin_unlock_irq(&sq_mapping_lock);
}
static inline void sq_mapping_list_del(struct sq_mapping *map)
{
struct sq_mapping **p, *tmp;
spin_lock_irq(&sq_mapping_lock);
for (p = &sq_mapping_list; (tmp = *p); p = &tmp->next)
if (tmp == map) {
*p = tmp->next;
break;
}
spin_unlock_irq(&sq_mapping_lock);
}
static int __sq_remap(struct sq_mapping *map, pgprot_t prot)
{
#if defined(CONFIG_MMU)
struct vm_struct *vma;
vma = __get_vm_area(map->size, VM_ALLOC, map->sq_addr, SQ_ADDRMAX);
if (!vma)
return -ENOMEM;
vma->phys_addr = map->addr;
if (ioremap_page_range((unsigned long)vma->addr,
(unsigned long)vma->addr + map->size,
vma->phys_addr, prot)) {
vunmap(vma->addr);
return -EAGAIN;
}
#else
__raw_writel(((map->addr >> 26) << 2) & 0x1c, SQ_QACR0);
__raw_writel(((map->addr >> 26) << 2) & 0x1c, SQ_QACR1);
#endif
return 0;
}
unsigned long sq_remap(unsigned long phys, unsigned int size,
const char *name, pgprot_t prot)
{
struct sq_mapping *map;
unsigned long end;
unsigned int psz;
int ret, page;
end = phys + size - 1;
if (unlikely(!size || end < phys))
return -EINVAL;
if (unlikely(phys < virt_to_phys(high_memory)))
return -EINVAL;
phys &= PAGE_MASK;
size = PAGE_ALIGN(end + 1) - phys;
map = kmem_cache_alloc(sq_cache, GFP_KERNEL);
if (unlikely(!map))
return -ENOMEM;
map->addr = phys;
map->size = size;
map->name = name;
page = bitmap_find_free_region(sq_bitmap, 0x04000000 >> PAGE_SHIFT,
get_order(map->size));
if (unlikely(page < 0)) {
ret = -ENOSPC;
goto out;
}
map->sq_addr = P4SEG_STORE_QUE + (page << PAGE_SHIFT);
ret = __sq_remap(map, prot);
if (unlikely(ret != 0))
goto out;
psz = (size + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
pr_info("sqremap: %15s [%4d page%s] va 0x%08lx pa 0x%08lx\n",
likely(map->name) ? map->name : "???",
psz, psz == 1 ? " " : "s",
map->sq_addr, map->addr);
sq_mapping_list_add(map);
return map->sq_addr;
out:
kmem_cache_free(sq_cache, map);
return ret;
}
void sq_unmap(unsigned long vaddr)
{
struct sq_mapping **p, *map;
int page;
for (p = &sq_mapping_list; (map = *p); p = &map->next)
if (map->sq_addr == vaddr)
break;
if (unlikely(!map)) {
printk("%s: bad store queue address 0x%08lx\n",
__func__, vaddr);
return;
}
page = (map->sq_addr - P4SEG_STORE_QUE) >> PAGE_SHIFT;
bitmap_release_region(sq_bitmap, page, get_order(map->size));
#ifdef CONFIG_MMU
{
struct vm_struct *vma;
vma = remove_vm_area((void *)(map->sq_addr & PAGE_MASK));
if (!vma) {
printk(KERN_ERR "%s: bad address 0x%08lx\n",
__func__, map->sq_addr);
return;
}
}
#endif
sq_mapping_list_del(map);
kmem_cache_free(sq_cache, map);
}
static ssize_t sq_sysfs_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct sq_sysfs_attr *sattr = to_sq_sysfs_attr(attr);
if (likely(sattr->show))
return sattr->show(buf);
return -EIO;
}
static ssize_t sq_sysfs_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct sq_sysfs_attr *sattr = to_sq_sysfs_attr(attr);
if (likely(sattr->store))
return sattr->store(buf, count);
return -EIO;
}
static ssize_t mapping_show(char *buf)
{
struct sq_mapping **list, *entry;
char *p = buf;
for (list = &sq_mapping_list; (entry = *list); list = &entry->next)
p += sprintf(p, "%08lx-%08lx [%08lx]: %s\n",
entry->sq_addr, entry->sq_addr + entry->size,
entry->addr, entry->name);
return p - buf;
}
static ssize_t mapping_store(const char *buf, size_t count)
{
unsigned long base = 0, len = 0;
sscanf(buf, "%lx %lx", &base, &len);
if (!base)
return -EIO;
if (likely(len)) {
int ret = sq_remap(base, len, "Userspace", PAGE_SHARED);
if (ret < 0)
return ret;
} else
sq_unmap(base);
return count;
}
static int sq_dev_add(struct device *dev, struct subsys_interface *sif)
{
unsigned int cpu = dev->id;
struct kobject *kobj;
int error;
sq_kobject[cpu] = kzalloc(sizeof(struct kobject), GFP_KERNEL);
if (unlikely(!sq_kobject[cpu]))
return -ENOMEM;
kobj = sq_kobject[cpu];
error = kobject_init_and_add(kobj, &ktype_percpu_entry, &dev->kobj,
"%s", "sq");
if (!error)
kobject_uevent(kobj, KOBJ_ADD);
return error;
}
static int sq_dev_remove(struct device *dev, struct subsys_interface *sif)
{
unsigned int cpu = dev->id;
struct kobject *kobj = sq_kobject[cpu];
kobject_put(kobj);
return 0;
}
static int __init sq_api_init(void)
{
unsigned int nr_pages = 0x04000000 >> PAGE_SHIFT;
unsigned int size = (nr_pages + (BITS_PER_LONG - 1)) / BITS_PER_LONG;
int ret = -ENOMEM;
printk(KERN_NOTICE "sq: Registering store queue API.\n");
sq_cache = kmem_cache_create("store_queue_cache",
sizeof(struct sq_mapping), 0, 0, NULL);
if (unlikely(!sq_cache))
return ret;
sq_bitmap = kzalloc(size, GFP_KERNEL);
if (unlikely(!sq_bitmap))
goto out;
ret = subsys_interface_register(&sq_interface);
if (unlikely(ret != 0))
goto out;
return 0;
out:
kfree(sq_bitmap);
kmem_cache_destroy(sq_cache);
return ret;
}
static void __exit sq_api_exit(void)
{
subsys_interface_unregister(&sq_interface);
kfree(sq_bitmap);
kmem_cache_destroy(sq_cache);
}
