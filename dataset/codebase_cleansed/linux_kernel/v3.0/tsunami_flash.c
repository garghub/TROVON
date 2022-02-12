static inline map_word tsunami_flash_read8(struct map_info *map, unsigned long offset)
{
map_word val;
val.x[0] = tsunami_tig_readb(offset);
return val;
}
static void tsunami_flash_write8(struct map_info *map, map_word value, unsigned long offset)
{
tsunami_tig_writeb(value.x[0], offset);
}
static void tsunami_flash_copy_from(
struct map_info *map, void *addr, unsigned long offset, ssize_t len)
{
unsigned char *dest;
dest = addr;
while(len && (offset < MAX_TIG_FLASH_SIZE)) {
*dest = tsunami_tig_readb(offset);
offset++;
dest++;
len--;
}
}
static void tsunami_flash_copy_to(
struct map_info *map, unsigned long offset,
const void *addr, ssize_t len)
{
const unsigned char *src;
src = addr;
while(len && (offset < MAX_TIG_FLASH_SIZE)) {
tsunami_tig_writeb(*src, offset);
offset++;
src++;
len--;
}
}
static void __exit cleanup_tsunami_flash(void)
{
struct mtd_info *mtd;
mtd = tsunami_flash_mtd;
if (mtd) {
mtd_device_unregister(mtd);
map_destroy(mtd);
}
tsunami_flash_mtd = 0;
}
static int __init init_tsunami_flash(void)
{
static const char *rom_probe_types[] = { "cfi_probe", "jedec_probe", "map_rom", NULL };
char **type;
tsunami_tig_writeb(FLASH_ENABLE_BYTE, FLASH_ENABLE_PORT);
tsunami_flash_mtd = 0;
type = rom_probe_types;
for(; !tsunami_flash_mtd && *type; type++) {
tsunami_flash_mtd = do_map_probe(*type, &tsunami_flash_map);
}
if (tsunami_flash_mtd) {
tsunami_flash_mtd->owner = THIS_MODULE;
mtd_device_register(tsunami_flash_mtd, NULL, 0);
return 0;
}
return -ENXIO;
}
