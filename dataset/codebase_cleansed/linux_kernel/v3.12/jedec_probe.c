static inline u32 jedec_read_mfr(struct map_info *map, uint32_t base,
struct cfi_private *cfi)
{
map_word result;
unsigned long mask;
int bank = 0;
do {
uint32_t ofs = cfi_build_cmd_addr(0 + (bank << 8), map, cfi);
mask = (1 << (cfi->device_type * 8)) - 1;
result = map_read(map, base + ofs);
bank++;
} while ((result.x[0] & mask) == CFI_MFR_CONTINUATION);
return result.x[0] & mask;
}
static inline u32 jedec_read_id(struct map_info *map, uint32_t base,
struct cfi_private *cfi)
{
map_word result;
unsigned long mask;
u32 ofs = cfi_build_cmd_addr(1, map, cfi);
mask = (1 << (cfi->device_type * 8)) -1;
result = map_read(map, base + ofs);
return result.x[0] & mask;
}
static void jedec_reset(u32 base, struct map_info *map, struct cfi_private *cfi)
{
if (cfi->addr_unlock1) {
pr_debug( "reset unlock called %x %x \n",
cfi->addr_unlock1,cfi->addr_unlock2);
cfi_send_gen_cmd(0xaa, cfi->addr_unlock1, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x55, cfi->addr_unlock2, base, map, cfi, cfi->device_type, NULL);
}
cfi_send_gen_cmd(0xF0, cfi->addr_unlock1, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0xFF, 0, base, map, cfi, cfi->device_type, NULL);
}
static int cfi_jedec_setup(struct map_info *map, struct cfi_private *cfi, int index)
{
int i,num_erase_regions;
uint8_t uaddr;
if (!(jedec_table[index].devtypes & cfi->device_type)) {
pr_debug("Rejecting potential %s with incompatible %d-bit device type\n",
jedec_table[index].name, 4 * (1<<cfi->device_type));
return 0;
}
printk(KERN_INFO "Found: %s\n",jedec_table[index].name);
num_erase_regions = jedec_table[index].nr_regions;
cfi->cfiq = kmalloc(sizeof(struct cfi_ident) + num_erase_regions * 4, GFP_KERNEL);
if (!cfi->cfiq) {
return 0;
}
memset(cfi->cfiq, 0, sizeof(struct cfi_ident));
cfi->cfiq->P_ID = jedec_table[index].cmd_set;
cfi->cfiq->NumEraseRegions = jedec_table[index].nr_regions;
cfi->cfiq->DevSize = jedec_table[index].dev_size;
cfi->cfi_mode = CFI_MODE_JEDEC;
cfi->sector_erase_cmd = CMD(0x30);
for (i=0; i<num_erase_regions; i++){
cfi->cfiq->EraseRegionInfo[i] = jedec_table[index].regions[i];
}
cfi->cmdset_priv = NULL;
cfi->mfr = jedec_table[index].mfr_id;
cfi->id = jedec_table[index].dev_id;
uaddr = jedec_table[index].uaddr;
cfi->addr_unlock1 = unlock_addrs[uaddr].addr1 / cfi->device_type;
cfi->addr_unlock2 = unlock_addrs[uaddr].addr2 / cfi->device_type;
return 1;
}
static inline int jedec_match( uint32_t base,
struct map_info *map,
struct cfi_private *cfi,
const struct amd_flash_info *finfo )
{
int rc = 0;
u32 mfr, id;
uint8_t uaddr;
switch (cfi->device_type) {
case CFI_DEVICETYPE_X8:
mfr = (uint8_t)finfo->mfr_id;
id = (uint8_t)finfo->dev_id;
if (finfo->dev_id > 0xff) {
pr_debug("%s(): ID is not 8bit\n",
__func__);
goto match_done;
}
break;
case CFI_DEVICETYPE_X16:
mfr = (uint16_t)finfo->mfr_id;
id = (uint16_t)finfo->dev_id;
break;
case CFI_DEVICETYPE_X32:
mfr = (uint16_t)finfo->mfr_id;
id = (uint32_t)finfo->dev_id;
break;
default:
printk(KERN_WARNING
"MTD %s(): Unsupported device type %d\n",
__func__, cfi->device_type);
goto match_done;
}
if ( cfi->mfr != mfr || cfi->id != id ) {
goto match_done;
}
pr_debug("MTD %s(): Check fit 0x%.8x + 0x%.8x = 0x%.8x\n",
__func__, base, 1 << finfo->dev_size, base + (1 << finfo->dev_size) );
if ( base + cfi_interleave(cfi) * ( 1 << finfo->dev_size ) > map->size ) {
pr_debug("MTD %s(): 0x%.4x 0x%.4x %dKiB doesn't fit\n",
__func__, finfo->mfr_id, finfo->dev_id,
1 << finfo->dev_size );
goto match_done;
}
if (! (finfo->devtypes & cfi->device_type))
goto match_done;
uaddr = finfo->uaddr;
pr_debug("MTD %s(): check unlock addrs 0x%.4x 0x%.4x\n",
__func__, cfi->addr_unlock1, cfi->addr_unlock2 );
if ( MTD_UADDR_UNNECESSARY != uaddr && MTD_UADDR_DONT_CARE != uaddr
&& ( unlock_addrs[uaddr].addr1 / cfi->device_type != cfi->addr_unlock1 ||
unlock_addrs[uaddr].addr2 / cfi->device_type != cfi->addr_unlock2 ) ) {
pr_debug("MTD %s(): 0x%.4x 0x%.4x did not match\n",
__func__,
unlock_addrs[uaddr].addr1,
unlock_addrs[uaddr].addr2);
goto match_done;
}
pr_debug("MTD %s(): check ID's disappear when not in ID mode\n",
__func__ );
jedec_reset( base, map, cfi );
mfr = jedec_read_mfr( map, base, cfi );
id = jedec_read_id( map, base, cfi );
if ( mfr == cfi->mfr && id == cfi->id ) {
pr_debug("MTD %s(): ID 0x%.2x:0x%.2x did not change after reset:\n"
"You might need to manually specify JEDEC parameters.\n",
__func__, cfi->mfr, cfi->id );
goto match_done;
}
rc = 1;
pr_debug("MTD %s(): return to ID mode\n", __func__ );
if (cfi->addr_unlock1) {
cfi_send_gen_cmd(0xaa, cfi->addr_unlock1, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x55, cfi->addr_unlock2, base, map, cfi, cfi->device_type, NULL);
}
cfi_send_gen_cmd(0x90, cfi->addr_unlock1, base, map, cfi, cfi->device_type, NULL);
match_done:
return rc;
}
static int jedec_probe_chip(struct map_info *map, __u32 base,
unsigned long *chip_map, struct cfi_private *cfi)
{
int i;
enum uaddr uaddr_idx = MTD_UADDR_NOT_SUPPORTED;
u32 probe_offset1, probe_offset2;
retry:
if (!cfi->numchips) {
uaddr_idx++;
if (MTD_UADDR_UNNECESSARY == uaddr_idx)
return 0;
cfi->addr_unlock1 = unlock_addrs[uaddr_idx].addr1 / cfi->device_type;
cfi->addr_unlock2 = unlock_addrs[uaddr_idx].addr2 / cfi->device_type;
}
if (base >= map->size) {
printk(KERN_NOTICE
"Probe at base(0x%08x) past the end of the map(0x%08lx)\n",
base, map->size -1);
return 0;
}
probe_offset1 = cfi_build_cmd_addr(cfi->addr_unlock1, map, cfi);
probe_offset2 = cfi_build_cmd_addr(cfi->addr_unlock2, map, cfi);
if ( ((base + probe_offset1 + map_bankwidth(map)) >= map->size) ||
((base + probe_offset2 + map_bankwidth(map)) >= map->size))
goto retry;
jedec_reset(base, map, cfi);
if(cfi->addr_unlock1) {
cfi_send_gen_cmd(0xaa, cfi->addr_unlock1, base, map, cfi, cfi->device_type, NULL);
cfi_send_gen_cmd(0x55, cfi->addr_unlock2, base, map, cfi, cfi->device_type, NULL);
}
cfi_send_gen_cmd(0x90, cfi->addr_unlock1, base, map, cfi, cfi->device_type, NULL);
if (!cfi->numchips) {
cfi->mfr = jedec_read_mfr(map, base, cfi);
cfi->id = jedec_read_id(map, base, cfi);
pr_debug("Search for id:(%02x %02x) interleave(%d) type(%d)\n",
cfi->mfr, cfi->id, cfi_interleave(cfi), cfi->device_type);
for (i = 0; i < ARRAY_SIZE(jedec_table); i++) {
if ( jedec_match( base, map, cfi, &jedec_table[i] ) ) {
pr_debug("MTD %s(): matched device 0x%x,0x%x unlock_addrs: 0x%.4x 0x%.4x\n",
__func__, cfi->mfr, cfi->id,
cfi->addr_unlock1, cfi->addr_unlock2 );
if (!cfi_jedec_setup(map, cfi, i))
return 0;
goto ok_out;
}
}
goto retry;
} else {
uint16_t mfr;
uint16_t id;
mfr = jedec_read_mfr(map, base, cfi);
id = jedec_read_id(map, base, cfi);
if ((mfr != cfi->mfr) || (id != cfi->id)) {
printk(KERN_DEBUG "%s: Found different chip or no chip at all (mfr 0x%x, id 0x%x) at 0x%x\n",
map->name, mfr, id, base);
jedec_reset(base, map, cfi);
return 0;
}
}
for (i=0; i < (base >> cfi->chipshift); i++) {
unsigned long start;
if(!test_bit(i, chip_map)) {
continue;
}
start = i << cfi->chipshift;
if (jedec_read_mfr(map, start, cfi) == cfi->mfr &&
jedec_read_id(map, start, cfi) == cfi->id) {
jedec_reset(start, map, cfi);
if (jedec_read_mfr(map, base, cfi) != cfi->mfr ||
jedec_read_id(map, base, cfi) != cfi->id) {
printk(KERN_DEBUG "%s: Found an alias at 0x%x for the chip at 0x%lx\n",
map->name, base, start);
return 0;
}
jedec_reset(base, map, cfi);
if (jedec_read_mfr(map, base, cfi) == cfi->mfr &&
jedec_read_id(map, base, cfi) == cfi->id) {
printk(KERN_DEBUG "%s: Found an alias at 0x%x for the chip at 0x%lx\n",
map->name, base, start);
return 0;
}
}
}
set_bit((base >> cfi->chipshift), chip_map);
cfi->numchips++;
ok_out:
jedec_reset(base, map, cfi);
printk(KERN_INFO "%s: Found %d x%d devices at 0x%x in %d-bit bank\n",
map->name, cfi_interleave(cfi), cfi->device_type*8, base,
map->bankwidth*8);
return 1;
}
static struct mtd_info *jedec_probe(struct map_info *map)
{
return mtd_do_chip_probe(map, &jedec_chip_probe);
}
static int __init jedec_probe_init(void)
{
register_mtd_chip_driver(&jedec_chipdrv);
return 0;
}
static void __exit jedec_probe_exit(void)
{
unregister_mtd_chip_driver(&jedec_chipdrv);
}
