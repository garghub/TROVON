static inline void sbc_gxx_page(struct map_info *map, unsigned long ofs)
{
unsigned long page = ofs >> WINDOW_SHIFT;
if( page!=page_in_window ) {
outw( page | DEVICE_ENABLE, PAGE_IO );
page_in_window = page;
}
}
static map_word sbc_gxx_read8(struct map_info *map, unsigned long ofs)
{
map_word ret;
spin_lock(&sbc_gxx_spin);
sbc_gxx_page(map, ofs);
ret.x[0] = readb(iomapadr + (ofs & WINDOW_MASK));
spin_unlock(&sbc_gxx_spin);
return ret;
}
static void sbc_gxx_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
while(len) {
unsigned long thislen = len;
if (len > (WINDOW_LENGTH - (from & WINDOW_MASK)))
thislen = WINDOW_LENGTH-(from & WINDOW_MASK);
spin_lock(&sbc_gxx_spin);
sbc_gxx_page(map, from);
memcpy_fromio(to, iomapadr + (from & WINDOW_MASK), thislen);
spin_unlock(&sbc_gxx_spin);
to += thislen;
from += thislen;
len -= thislen;
}
}
static void sbc_gxx_write8(struct map_info *map, map_word d, unsigned long adr)
{
spin_lock(&sbc_gxx_spin);
sbc_gxx_page(map, adr);
writeb(d.x[0], iomapadr + (adr & WINDOW_MASK));
spin_unlock(&sbc_gxx_spin);
}
static void sbc_gxx_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
while(len) {
unsigned long thislen = len;
if (len > (WINDOW_LENGTH - (to & WINDOW_MASK)))
thislen = WINDOW_LENGTH-(to & WINDOW_MASK);
spin_lock(&sbc_gxx_spin);
sbc_gxx_page(map, to);
memcpy_toio(iomapadr + (to & WINDOW_MASK), from, thislen);
spin_unlock(&sbc_gxx_spin);
to += thislen;
from += thislen;
len -= thislen;
}
}
static void cleanup_sbc_gxx(void)
{
if( all_mtd ) {
mtd_device_unregister(all_mtd);
map_destroy( all_mtd );
}
iounmap(iomapadr);
release_region(PAGE_IO,PAGE_IO_SIZE);
}
static int __init init_sbc_gxx(void)
{
iomapadr = ioremap(WINDOW_START, WINDOW_LENGTH);
if (!iomapadr) {
printk( KERN_ERR"%s: failed to ioremap memory region\n",
sbc_gxx_map.name );
return -EIO;
}
if (!request_region( PAGE_IO, PAGE_IO_SIZE, "SBC-GXx flash")) {
printk( KERN_ERR"%s: IO ports 0x%x-0x%x in use\n",
sbc_gxx_map.name,
PAGE_IO, PAGE_IO+PAGE_IO_SIZE-1 );
iounmap(iomapadr);
return -EAGAIN;
}
printk( KERN_INFO"%s: IO:0x%x-0x%x MEM:0x%x-0x%x\n",
sbc_gxx_map.name,
PAGE_IO, PAGE_IO+PAGE_IO_SIZE-1,
WINDOW_START, WINDOW_START+WINDOW_LENGTH-1 );
all_mtd = do_map_probe( "cfi_probe", &sbc_gxx_map );
if( !all_mtd ) {
cleanup_sbc_gxx();
return -ENXIO;
}
all_mtd->owner = THIS_MODULE;
mtd_device_register(all_mtd, partition_info, NUM_PARTITIONS);
return 0;
}
