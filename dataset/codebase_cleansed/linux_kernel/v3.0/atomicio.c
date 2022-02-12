static struct acpi_iomap *__acpi_find_iomap(phys_addr_t paddr,
unsigned long size)
{
struct acpi_iomap *map;
list_for_each_entry_rcu(map, &acpi_iomaps, list) {
if (map->paddr + map->size >= paddr + size &&
map->paddr <= paddr)
return map;
}
return NULL;
}
static void __iomem *__acpi_ioremap_fast(phys_addr_t paddr,
unsigned long size)
{
struct acpi_iomap *map;
map = __acpi_find_iomap(paddr, size);
if (map)
return map->vaddr + (paddr - map->paddr);
else
return NULL;
}
static void __iomem *__acpi_try_ioremap(phys_addr_t paddr,
unsigned long size)
{
struct acpi_iomap *map;
map = __acpi_find_iomap(paddr, size);
if (map) {
kref_get(&map->ref);
return map->vaddr + (paddr - map->paddr);
} else
return NULL;
}
static void __iomem *acpi_pre_map(phys_addr_t paddr,
unsigned long size)
{
void __iomem *vaddr;
struct acpi_iomap *map;
unsigned long pg_sz, flags;
phys_addr_t pg_off;
spin_lock_irqsave(&acpi_iomaps_lock, flags);
vaddr = __acpi_try_ioremap(paddr, size);
spin_unlock_irqrestore(&acpi_iomaps_lock, flags);
if (vaddr)
return vaddr;
pg_off = paddr & PAGE_MASK;
pg_sz = ((paddr + size + PAGE_SIZE - 1) & PAGE_MASK) - pg_off;
vaddr = ioremap(pg_off, pg_sz);
if (!vaddr)
return NULL;
map = kmalloc(sizeof(*map), GFP_KERNEL);
if (!map)
goto err_unmap;
INIT_LIST_HEAD(&map->list);
map->paddr = pg_off;
map->size = pg_sz;
map->vaddr = vaddr;
kref_init(&map->ref);
spin_lock_irqsave(&acpi_iomaps_lock, flags);
vaddr = __acpi_try_ioremap(paddr, size);
if (vaddr) {
spin_unlock_irqrestore(&acpi_iomaps_lock, flags);
iounmap(map->vaddr);
kfree(map);
return vaddr;
}
list_add_tail_rcu(&map->list, &acpi_iomaps);
spin_unlock_irqrestore(&acpi_iomaps_lock, flags);
return map->vaddr + (paddr - map->paddr);
err_unmap:
iounmap(vaddr);
return NULL;
}
static void __acpi_kref_del_iomap(struct kref *ref)
{
struct acpi_iomap *map;
map = container_of(ref, struct acpi_iomap, ref);
list_del_rcu(&map->list);
}
static void acpi_post_unmap(phys_addr_t paddr, unsigned long size)
{
struct acpi_iomap *map;
unsigned long flags;
int del;
spin_lock_irqsave(&acpi_iomaps_lock, flags);
map = __acpi_find_iomap(paddr, size);
BUG_ON(!map);
del = kref_put(&map->ref, __acpi_kref_del_iomap);
spin_unlock_irqrestore(&acpi_iomaps_lock, flags);
if (!del)
return;
synchronize_rcu();
iounmap(map->vaddr);
kfree(map);
}
static int acpi_check_gar(struct acpi_generic_address *reg,
u64 *paddr, int silent)
{
u32 width, space_id;
width = reg->bit_width;
space_id = reg->space_id;
memcpy(paddr, &reg->address, sizeof(*paddr));
if (!*paddr) {
if (!silent)
pr_warning(FW_BUG ACPI_PFX
"Invalid physical address in GAR [0x%llx/%u/%u]\n",
*paddr, width, space_id);
return -EINVAL;
}
if ((width != 8) && (width != 16) && (width != 32) && (width != 64)) {
if (!silent)
pr_warning(FW_BUG ACPI_PFX
"Invalid bit width in GAR [0x%llx/%u/%u]\n",
*paddr, width, space_id);
return -EINVAL;
}
if (space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY &&
space_id != ACPI_ADR_SPACE_SYSTEM_IO) {
if (!silent)
pr_warning(FW_BUG ACPI_PFX
"Invalid address space type in GAR [0x%llx/%u/%u]\n",
*paddr, width, space_id);
return -EINVAL;
}
return 0;
}
int acpi_pre_map_gar(struct acpi_generic_address *reg)
{
u64 paddr;
void __iomem *vaddr;
int rc;
if (reg->space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY)
return 0;
rc = acpi_check_gar(reg, &paddr, 0);
if (rc)
return rc;
vaddr = acpi_pre_map(paddr, reg->bit_width / 8);
if (!vaddr)
return -EIO;
return 0;
}
int acpi_post_unmap_gar(struct acpi_generic_address *reg)
{
u64 paddr;
int rc;
if (reg->space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY)
return 0;
rc = acpi_check_gar(reg, &paddr, 0);
if (rc)
return rc;
acpi_post_unmap(paddr, reg->bit_width / 8);
return 0;
}
static int acpi_atomic_read_mem(u64 paddr, u64 *val, u32 width)
{
void __iomem *addr;
rcu_read_lock();
addr = __acpi_ioremap_fast(paddr, width);
switch (width) {
case 8:
*val = readb(addr);
break;
case 16:
*val = readw(addr);
break;
case 32:
*val = readl(addr);
break;
#ifdef readq
case 64:
*val = readq(addr);
break;
#endif
default:
return -EINVAL;
}
rcu_read_unlock();
return 0;
}
static int acpi_atomic_write_mem(u64 paddr, u64 val, u32 width)
{
void __iomem *addr;
rcu_read_lock();
addr = __acpi_ioremap_fast(paddr, width);
switch (width) {
case 8:
writeb(val, addr);
break;
case 16:
writew(val, addr);
break;
case 32:
writel(val, addr);
break;
#ifdef writeq
case 64:
writeq(val, addr);
break;
#endif
default:
return -EINVAL;
}
rcu_read_unlock();
return 0;
}
int acpi_atomic_read(u64 *val, struct acpi_generic_address *reg)
{
u64 paddr;
int rc;
rc = acpi_check_gar(reg, &paddr, 1);
if (rc)
return rc;
*val = 0;
switch (reg->space_id) {
case ACPI_ADR_SPACE_SYSTEM_MEMORY:
return acpi_atomic_read_mem(paddr, val, reg->bit_width);
case ACPI_ADR_SPACE_SYSTEM_IO:
return acpi_os_read_port(paddr, (u32 *)val, reg->bit_width);
default:
return -EINVAL;
}
}
int acpi_atomic_write(u64 val, struct acpi_generic_address *reg)
{
u64 paddr;
int rc;
rc = acpi_check_gar(reg, &paddr, 1);
if (rc)
return rc;
switch (reg->space_id) {
case ACPI_ADR_SPACE_SYSTEM_MEMORY:
return acpi_atomic_write_mem(paddr, val, reg->bit_width);
case ACPI_ADR_SPACE_SYSTEM_IO:
return acpi_os_write_port(paddr, val, reg->bit_width);
default:
return -EINVAL;
}
}
