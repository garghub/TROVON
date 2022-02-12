static map_word flash_read(struct map_info *map, unsigned long ofs)
{
map_word tmp;
tmp.x[0] = *(flash_data *)(map->map_priv_1 + ofs);
return tmp;
}
static void flash_copy_from(struct map_info *map, void *to,
unsigned long from, ssize_t len)
{
memcpy(to, (void *)(map->map_priv_1 + from), len);
}
static void flash_write(struct map_info *map, map_word d, unsigned long adr)
{
*(flash_data *)(map->map_priv_1 + adr) = (flash_data)d.x[0];
}
static struct mtd_info *probe_cs(struct map_info *map_cs)
{
struct mtd_info *mtd_cs = NULL;
printk(KERN_INFO
"%s: Probing a 0x%08lx bytes large window at 0x%08lx.\n",
map_cs->name, map_cs->size, map_cs->map_priv_1);
#ifdef CONFIG_MTD_CFI
mtd_cs = do_map_probe("cfi_probe", map_cs);
#endif
#ifdef CONFIG_MTD_JEDECPROBE
if (!mtd_cs)
mtd_cs = do_map_probe("jedec_probe", map_cs);
#endif
return mtd_cs;
}
static struct mtd_info *flash_probe(void)
{
struct mtd_info *mtd_cse0;
struct mtd_info *mtd_cse1;
struct mtd_info *mtd_cse;
mtd_cse0 = probe_cs(&map_cse0);
mtd_cse1 = probe_cs(&map_cse1);
if (!mtd_cse0 && !mtd_cse1) {
return NULL;
}
if (mtd_cse0 && mtd_cse1) {
struct mtd_info *mtds[] = { mtd_cse0, mtd_cse1 };
mtd_cse = mtd_concat_create(mtds, ARRAY_SIZE(mtds),
"cse0+cse1");
if (!mtd_cse) {
printk(KERN_ERR "%s and %s: Concatenation failed!\n",
map_cse0.name, map_cse1.name);
mtd_cse = mtd_cse0;
map_destroy(mtd_cse1);
}
} else {
mtd_cse = mtd_cse0? mtd_cse0 : mtd_cse1;
}
return mtd_cse;
}
static int __init init_axis_flash(void)
{
struct mtd_info *mymtd;
int err = 0;
int pidx = 0;
struct partitiontable_head *ptable_head = NULL;
struct partitiontable_entry *ptable;
int use_default_ptable = 1;
const char pmsg[] = " /dev/flash%d at 0x%08x, size 0x%08x\n";
if (!(mymtd = flash_probe())) {
printk(KERN_INFO "axisflashmap: Found no flash chip.\n");
} else {
printk(KERN_INFO "%s: 0x%08x bytes of flash memory.\n",
mymtd->name, mymtd->size);
axisflash_mtd = mymtd;
}
if (mymtd) {
mymtd->owner = THIS_MODULE;
ptable_head = (struct partitiontable_head *)(FLASH_CACHED_ADDR +
CONFIG_ETRAX_PTABLE_SECTOR +
PARTITION_TABLE_OFFSET);
}
pidx++;
if (ptable_head && (ptable_head->magic == PARTITION_TABLE_MAGIC)
&& (ptable_head->size <
(MAX_PARTITIONS * sizeof(struct partitiontable_entry) +
PARTITIONTABLE_END_MARKER_SIZE))
&& (*(unsigned long*)((void*)ptable_head + sizeof(*ptable_head) +
ptable_head->size -
PARTITIONTABLE_END_MARKER_SIZE)
== PARTITIONTABLE_END_MARKER)) {
int ptable_ok = 0;
struct partitiontable_entry *max_addr =
(struct partitiontable_entry *)
((unsigned long)ptable_head + sizeof(*ptable_head) +
ptable_head->size);
unsigned long offset = CONFIG_ETRAX_PTABLE_SECTOR;
unsigned char *p;
unsigned long csum = 0;
ptable = (struct partitiontable_entry *)
((unsigned long)ptable_head + sizeof(*ptable_head));
p = (unsigned char*) ptable;
while (p <= (unsigned char*)max_addr) {
csum += *p++;
csum += *p++;
csum += *p++;
csum += *p++;
}
ptable_ok = (csum == ptable_head->checksum);
printk(KERN_INFO " Found a%s partition table at 0x%p-0x%p.\n",
(ptable_ok ? " valid" : "n invalid"), ptable_head,
max_addr);
while (ptable_ok
&& ptable->offset != 0xffffffff
&& ptable < max_addr
&& pidx < MAX_PARTITIONS) {
axis_partitions[pidx].offset = offset + ptable->offset;
axis_partitions[pidx].size = ptable->size;
printk(pmsg, pidx, axis_partitions[pidx].offset,
axis_partitions[pidx].size);
pidx++;
ptable++;
}
use_default_ptable = !ptable_ok;
}
if (romfs_in_flash) {
axis_partitions[pidx].name = "romfs";
axis_partitions[pidx].size = romfs_length;
axis_partitions[pidx].offset = romfs_start - FLASH_CACHED_ADDR;
axis_partitions[pidx].mask_flags |= MTD_WRITEABLE;
printk(KERN_INFO
" Adding readonly flash partition for romfs image:\n");
printk(pmsg, pidx, axis_partitions[pidx].offset,
axis_partitions[pidx].size);
pidx++;
}
if (mymtd) {
if (use_default_ptable) {
printk(KERN_INFO " Using default partition table.\n");
err = mtd_device_register(mymtd,
axis_default_partitions,
NUM_DEFAULT_PARTITIONS);
} else {
err = mtd_device_register(mymtd, axis_partitions,
pidx);
}
if (err)
panic("axisflashmap could not add MTD partitions!\n");
}
if (!romfs_in_flash) {
#if !defined(CONFIG_MTD_MTDRAM) || (CONFIG_MTDRAM_TOTAL_SIZE != 0)
printk(KERN_EMERG "axisflashmap: Cannot create an MTD RAM "
"device due to kernel (mis)configuration!\n");
panic("This kernel cannot boot from RAM!\n");
#else
struct mtd_info *mtd_ram;
mtd_ram = kmalloc(sizeof(struct mtd_info), GFP_KERNEL);
if (!mtd_ram)
panic("axisflashmap couldn't allocate memory for "
"mtd_info!\n");
printk(KERN_INFO " Adding RAM partition for romfs image:\n");
printk(pmsg, pidx, (unsigned)romfs_start,
(unsigned)romfs_length);
err = mtdram_init_device(mtd_ram,
(void *)romfs_start,
romfs_length,
"romfs");
if (err)
panic("axisflashmap could not initialize MTD RAM "
"device!\n");
#endif
}
return err;
}
