static void __vmax301_page(struct map_info *map, unsigned long page)
{
writew(page, map->map_priv_2 - WINDOW_LENGTH);
map->map_priv_1 = page;
}
static inline void vmax301_page(struct map_info *map,
unsigned long ofs)
{
unsigned long page = (ofs >> WINDOW_SHIFT);
if (map->map_priv_1 != page)
__vmax301_page(map, page);
}
static map_word vmax301_read8(struct map_info *map, unsigned long ofs)
{
map_word ret;
spin_lock(&vmax301_spin);
vmax301_page(map, ofs);
ret.x[0] = readb(map->map_priv_2 + (ofs & WINDOW_MASK));
spin_unlock(&vmax301_spin);
return ret;
}
static void vmax301_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
while(len) {
unsigned long thislen = len;
if (len > (WINDOW_LENGTH - (from & WINDOW_MASK)))
thislen = WINDOW_LENGTH-(from & WINDOW_MASK);
spin_lock(&vmax301_spin);
vmax301_page(map, from);
memcpy_fromio(to, map->map_priv_2 + from, thislen);
spin_unlock(&vmax301_spin);
to += thislen;
from += thislen;
len -= thislen;
}
}
static void vmax301_write8(struct map_info *map, map_word d, unsigned long adr)
{
spin_lock(&vmax301_spin);
vmax301_page(map, adr);
writeb(d.x[0], map->map_priv_2 + (adr & WINDOW_MASK));
spin_unlock(&vmax301_spin);
}
static void vmax301_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
while(len) {
unsigned long thislen = len;
if (len > (WINDOW_LENGTH - (to & WINDOW_MASK)))
thislen = WINDOW_LENGTH-(to & WINDOW_MASK);
spin_lock(&vmax301_spin);
vmax301_page(map, to);
memcpy_toio(map->map_priv_2 + to, from, thislen);
spin_unlock(&vmax301_spin);
to += thislen;
from += thislen;
len -= thislen;
}
}
static void __exit cleanup_vmax301(void)
{
int i;
for (i=0; i<2; i++) {
if (vmax_mtd[i]) {
mtd_device_unregister(vmax_mtd[i]);
map_destroy(vmax_mtd[i]);
}
}
iounmap((void *)vmax_map[0].map_priv_1 - WINDOW_START);
}
static int __init init_vmax301(void)
{
int i;
unsigned long iomapadr;
printk("Tempustech VMAX 301 MEM:0x%x-0x%x\n",WINDOW_START,
WINDOW_START+4*WINDOW_LENGTH);
iomapadr = (unsigned long)ioremap(WINDOW_START, WINDOW_LENGTH*4);
if (!iomapadr) {
printk("Failed to ioremap memory region\n");
return -EIO;
}
vmax_map[0].map_priv_2 = iomapadr + WINDOW_START;
vmax_map[1].map_priv_2 = iomapadr + (3*WINDOW_START);
for (i=0; i<2; i++) {
vmax_mtd[i] = do_map_probe("cfi_probe", &vmax_map[i]);
if (!vmax_mtd[i])
vmax_mtd[i] = do_map_probe("jedec", &vmax_map[i]);
if (!vmax_mtd[i])
vmax_mtd[i] = do_map_probe("map_ram", &vmax_map[i]);
if (!vmax_mtd[i])
vmax_mtd[i] = do_map_probe("map_rom", &vmax_map[i]);
if (vmax_mtd[i]) {
vmax_mtd[i]->owner = THIS_MODULE;
mtd_device_register(vmax_mtd[i], NULL, 0);
}
}
if (!vmax_mtd[0] && !vmax_mtd[1]) {
iounmap((void *)iomapadr);
return -ENXIO;
}
return 0;
}
