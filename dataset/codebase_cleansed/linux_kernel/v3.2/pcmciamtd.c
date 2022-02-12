static caddr_t remap_window(struct map_info *map, unsigned long to)
{
struct pcmciamtd_dev *dev = (struct pcmciamtd_dev *)map->map_priv_1;
struct resource *win = (struct resource *) map->map_priv_2;
unsigned int offset;
int ret;
if (!pcmcia_dev_present(dev->p_dev)) {
pr_debug("device removed\n");
return 0;
}
offset = to & ~(dev->win_size-1);
if (offset != dev->offset) {
pr_debug("Remapping window from 0x%8.8x to 0x%8.8x\n",
dev->offset, offset);
ret = pcmcia_map_mem_page(dev->p_dev, win, offset);
if (ret != 0)
return NULL;
dev->offset = offset;
}
return dev->win_base + (to & (dev->win_size-1));
}
static map_word pcmcia_read8_remap(struct map_info *map, unsigned long ofs)
{
caddr_t addr;
map_word d = {{0}};
addr = remap_window(map, ofs);
if(!addr)
return d;
d.x[0] = readb(addr);
pr_debug("ofs = 0x%08lx (%p) data = 0x%02lx\n", ofs, addr, d.x[0]);
return d;
}
static map_word pcmcia_read16_remap(struct map_info *map, unsigned long ofs)
{
caddr_t addr;
map_word d = {{0}};
addr = remap_window(map, ofs);
if(!addr)
return d;
d.x[0] = readw(addr);
pr_debug("ofs = 0x%08lx (%p) data = 0x%04lx\n", ofs, addr, d.x[0]);
return d;
}
static void pcmcia_copy_from_remap(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
struct pcmciamtd_dev *dev = (struct pcmciamtd_dev *)map->map_priv_1;
unsigned long win_size = dev->win_size;
pr_debug("to = %p from = %lu len = %zd\n", to, from, len);
while(len) {
int toread = win_size - (from & (win_size-1));
caddr_t addr;
if(toread > len)
toread = len;
addr = remap_window(map, from);
if(!addr)
return;
pr_debug("memcpy from %p to %p len = %d\n", addr, to, toread);
memcpy_fromio(to, addr, toread);
len -= toread;
to += toread;
from += toread;
}
}
static void pcmcia_write8_remap(struct map_info *map, map_word d, unsigned long adr)
{
caddr_t addr = remap_window(map, adr);
if(!addr)
return;
pr_debug("adr = 0x%08lx (%p) data = 0x%02lx\n", adr, addr, d.x[0]);
writeb(d.x[0], addr);
}
static void pcmcia_write16_remap(struct map_info *map, map_word d, unsigned long adr)
{
caddr_t addr = remap_window(map, adr);
if(!addr)
return;
pr_debug("adr = 0x%08lx (%p) data = 0x%04lx\n", adr, addr, d.x[0]);
writew(d.x[0], addr);
}
static void pcmcia_copy_to_remap(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
struct pcmciamtd_dev *dev = (struct pcmciamtd_dev *)map->map_priv_1;
unsigned long win_size = dev->win_size;
pr_debug("to = %lu from = %p len = %zd\n", to, from, len);
while(len) {
int towrite = win_size - (to & (win_size-1));
caddr_t addr;
if(towrite > len)
towrite = len;
addr = remap_window(map, to);
if(!addr)
return;
pr_debug("memcpy from %p to %p len = %d\n", from, addr, towrite);
memcpy_toio(addr, from, towrite);
len -= towrite;
to += towrite;
from += towrite;
}
}
static map_word pcmcia_read8(struct map_info *map, unsigned long ofs)
{
caddr_t win_base = (caddr_t)map->map_priv_2;
map_word d = {{0}};
if(DEV_REMOVED(map))
return d;
d.x[0] = readb(win_base + ofs);
pr_debug("ofs = 0x%08lx (%p) data = 0x%02lx\n",
ofs, win_base + ofs, d.x[0]);
return d;
}
static map_word pcmcia_read16(struct map_info *map, unsigned long ofs)
{
caddr_t win_base = (caddr_t)map->map_priv_2;
map_word d = {{0}};
if(DEV_REMOVED(map))
return d;
d.x[0] = readw(win_base + ofs);
pr_debug("ofs = 0x%08lx (%p) data = 0x%04lx\n",
ofs, win_base + ofs, d.x[0]);
return d;
}
static void pcmcia_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
caddr_t win_base = (caddr_t)map->map_priv_2;
if(DEV_REMOVED(map))
return;
pr_debug("to = %p from = %lu len = %zd\n", to, from, len);
memcpy_fromio(to, win_base + from, len);
}
static void pcmcia_write8(struct map_info *map, map_word d, unsigned long adr)
{
caddr_t win_base = (caddr_t)map->map_priv_2;
if(DEV_REMOVED(map))
return;
pr_debug("adr = 0x%08lx (%p) data = 0x%02lx\n",
adr, win_base + adr, d.x[0]);
writeb(d.x[0], win_base + adr);
}
static void pcmcia_write16(struct map_info *map, map_word d, unsigned long adr)
{
caddr_t win_base = (caddr_t)map->map_priv_2;
if(DEV_REMOVED(map))
return;
pr_debug("adr = 0x%08lx (%p) data = 0x%04lx\n",
adr, win_base + adr, d.x[0]);
writew(d.x[0], win_base + adr);
}
static void pcmcia_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
caddr_t win_base = (caddr_t)map->map_priv_2;
if(DEV_REMOVED(map))
return;
pr_debug("to = %lu from = %p len = %zd\n", to, from, len);
memcpy_toio(win_base + to, from, len);
}
static void pcmciamtd_set_vpp(struct map_info *map, int on)
{
struct pcmciamtd_dev *dev = (struct pcmciamtd_dev *)map->map_priv_1;
struct pcmcia_device *link = dev->p_dev;
pr_debug("dev = %p on = %d vpp = %d\n\n", dev, on, dev->vpp);
pcmcia_fixup_vpp(link, on ? dev->vpp : 0);
}
static void pcmciamtd_release(struct pcmcia_device *link)
{
struct pcmciamtd_dev *dev = link->priv;
pr_debug("link = 0x%p\n", link);
if (link->resource[2]->end) {
if(dev->win_base) {
iounmap(dev->win_base);
dev->win_base = NULL;
}
}
pcmcia_disable_device(link);
}
static int pcmciamtd_cistpl_format(struct pcmcia_device *p_dev,
tuple_t *tuple,
void *priv_data)
{
cisparse_t parse;
if (!pcmcia_parse_tuple(tuple, &parse)) {
cistpl_format_t *t = &parse.format;
(void)t;
pr_debug("Format type: %u, Error Detection: %u, offset = %u, length =%u\n",
t->type, t->edc, t->offset, t->length);
}
return -ENOSPC;
}
static int pcmciamtd_cistpl_jedec(struct pcmcia_device *p_dev,
tuple_t *tuple,
void *priv_data)
{
cisparse_t parse;
int i;
if (!pcmcia_parse_tuple(tuple, &parse)) {
cistpl_jedec_t *t = &parse.jedec;
for (i = 0; i < t->nid; i++)
pr_debug("JEDEC: 0x%02x 0x%02x\n",
t->id[i].mfr, t->id[i].info);
}
return -ENOSPC;
}
static int pcmciamtd_cistpl_device(struct pcmcia_device *p_dev,
tuple_t *tuple,
void *priv_data)
{
struct pcmciamtd_dev *dev = priv_data;
cisparse_t parse;
cistpl_device_t *t = &parse.device;
int i;
if (pcmcia_parse_tuple(tuple, &parse))
return -EINVAL;
pr_debug("Common memory:\n");
dev->pcmcia_map.size = t->dev[0].size;
for (i = 0; i < t->ndev; i++) {
pr_debug("Region %d, type = %u\n", i, t->dev[i].type);
pr_debug("Region %d, wp = %u\n", i, t->dev[i].wp);
pr_debug("Region %d, speed = %u ns\n", i, t->dev[i].speed);
pr_debug("Region %d, size = %u bytes\n", i, t->dev[i].size);
}
return 0;
}
static int pcmciamtd_cistpl_geo(struct pcmcia_device *p_dev,
tuple_t *tuple,
void *priv_data)
{
struct pcmciamtd_dev *dev = priv_data;
cisparse_t parse;
cistpl_device_geo_t *t = &parse.device_geo;
int i;
if (pcmcia_parse_tuple(tuple, &parse))
return -EINVAL;
dev->pcmcia_map.bankwidth = t->geo[0].buswidth;
for (i = 0; i < t->ngeo; i++) {
pr_debug("region: %d bankwidth = %u\n", i, t->geo[i].buswidth);
pr_debug("region: %d erase_block = %u\n", i, t->geo[i].erase_block);
pr_debug("region: %d read_block = %u\n", i, t->geo[i].read_block);
pr_debug("region: %d write_block = %u\n", i, t->geo[i].write_block);
pr_debug("region: %d partition = %u\n", i, t->geo[i].partition);
pr_debug("region: %d interleave = %u\n", i, t->geo[i].interleave);
}
return 0;
}
static void card_settings(struct pcmciamtd_dev *dev, struct pcmcia_device *p_dev, int *new_name)
{
int i;
if (p_dev->prod_id[0]) {
dev->mtd_name[0] = '\0';
for (i = 0; i < 4; i++) {
if (i)
strcat(dev->mtd_name, " ");
if (p_dev->prod_id[i])
strcat(dev->mtd_name, p_dev->prod_id[i]);
}
pr_debug("Found name: %s\n", dev->mtd_name);
}
pcmcia_loop_tuple(p_dev, CISTPL_FORMAT, pcmciamtd_cistpl_format, NULL);
pcmcia_loop_tuple(p_dev, CISTPL_JEDEC_C, pcmciamtd_cistpl_jedec, NULL);
pcmcia_loop_tuple(p_dev, CISTPL_DEVICE, pcmciamtd_cistpl_device, dev);
pcmcia_loop_tuple(p_dev, CISTPL_DEVICE_GEO, pcmciamtd_cistpl_geo, dev);
if(!dev->pcmcia_map.size)
dev->pcmcia_map.size = MAX_PCMCIA_ADDR;
if(!dev->pcmcia_map.bankwidth)
dev->pcmcia_map.bankwidth = 2;
if(force_size) {
dev->pcmcia_map.size = force_size << 20;
pr_debug("size forced to %dM\n", force_size);
}
if(bankwidth) {
dev->pcmcia_map.bankwidth = bankwidth;
pr_debug("bankwidth forced to %d\n", bankwidth);
}
dev->pcmcia_map.name = dev->mtd_name;
if(!dev->mtd_name[0]) {
strcpy(dev->mtd_name, "PCMCIA Memory card");
*new_name = 1;
}
pr_debug("Device: Size: %lu Width:%d Name: %s\n",
dev->pcmcia_map.size,
dev->pcmcia_map.bankwidth << 3, dev->mtd_name);
}
static int pcmciamtd_config(struct pcmcia_device *link)
{
struct pcmciamtd_dev *dev = link->priv;
struct mtd_info *mtd = NULL;
int ret;
int i, j = 0;
static char *probes[] = { "jedec_probe", "cfi_probe" };
int new_name = 0;
pr_debug("link=0x%p\n", link);
card_settings(dev, link, &new_name);
dev->pcmcia_map.phys = NO_XIP;
dev->pcmcia_map.copy_from = pcmcia_copy_from_remap;
dev->pcmcia_map.copy_to = pcmcia_copy_to_remap;
if (dev->pcmcia_map.bankwidth == 1) {
dev->pcmcia_map.read = pcmcia_read8_remap;
dev->pcmcia_map.write = pcmcia_write8_remap;
} else {
dev->pcmcia_map.read = pcmcia_read16_remap;
dev->pcmcia_map.write = pcmcia_write16_remap;
}
if(setvpp == 1)
dev->pcmcia_map.set_vpp = pcmciamtd_set_vpp;
link->resource[2]->flags |= WIN_MEMORY_TYPE_CM | WIN_ENABLE;
link->resource[2]->flags |= (dev->pcmcia_map.bankwidth == 1) ?
WIN_DATA_WIDTH_8 : WIN_DATA_WIDTH_16;
link->resource[2]->start = 0;
link->resource[2]->end = (force_size) ? force_size << 20 :
MAX_PCMCIA_ADDR;
dev->win_size = 0;
do {
int ret;
pr_debug("requesting window with size = %luKiB memspeed = %d\n",
(unsigned long) resource_size(link->resource[2]) >> 10,
mem_speed);
ret = pcmcia_request_window(link, link->resource[2], mem_speed);
pr_debug("ret = %d dev->win_size = %d\n", ret, dev->win_size);
if(ret) {
j++;
link->resource[2]->start = 0;
link->resource[2]->end = (force_size) ?
force_size << 20 : MAX_PCMCIA_ADDR;
link->resource[2]->end >>= j;
} else {
pr_debug("Got window of size %luKiB\n", (unsigned long)
resource_size(link->resource[2]) >> 10);
dev->win_size = resource_size(link->resource[2]);
break;
}
} while (link->resource[2]->end >= 0x1000);
pr_debug("dev->win_size = %d\n", dev->win_size);
if(!dev->win_size) {
dev_err(&dev->p_dev->dev, "Cannot allocate memory window\n");
pcmciamtd_release(link);
return -ENODEV;
}
pr_debug("Allocated a window of %dKiB\n", dev->win_size >> 10);
dev->win_base = ioremap(link->resource[2]->start,
resource_size(link->resource[2]));
if(!dev->win_base) {
dev_err(&dev->p_dev->dev, "ioremap(%pR) failed\n",
link->resource[2]);
pcmciamtd_release(link);
return -ENODEV;
}
pr_debug("mapped window dev = %p @ %pR, base = %p\n",
dev, link->resource[2], dev->win_base);
dev->offset = 0;
dev->pcmcia_map.map_priv_1 = (unsigned long)dev;
dev->pcmcia_map.map_priv_2 = (unsigned long)link->resource[2];
dev->vpp = (vpp) ? vpp : link->socket->socket.Vpp;
if(setvpp == 2) {
link->vpp = dev->vpp;
} else {
link->vpp = 0;
}
link->config_index = 0;
pr_debug("Setting Configuration\n");
ret = pcmcia_enable_device(link);
if (ret != 0) {
if (dev->win_base) {
iounmap(dev->win_base);
dev->win_base = NULL;
}
return -ENODEV;
}
if(mem_type == 1) {
mtd = do_map_probe("map_ram", &dev->pcmcia_map);
} else if(mem_type == 2) {
mtd = do_map_probe("map_rom", &dev->pcmcia_map);
} else {
for(i = 0; i < ARRAY_SIZE(probes); i++) {
pr_debug("Trying %s\n", probes[i]);
mtd = do_map_probe(probes[i], &dev->pcmcia_map);
if(mtd)
break;
pr_debug("FAILED: %s\n", probes[i]);
}
}
if(!mtd) {
pr_debug("Can not find an MTD\n");
pcmciamtd_release(link);
return -ENODEV;
}
dev->mtd_info = mtd;
mtd->owner = THIS_MODULE;
if(new_name) {
int size = 0;
char unit = ' ';
if(mtd->size < 1048576) {
size = mtd->size >> 10;
unit = 'K';
} else {
size = mtd->size >> 20;
unit = 'M';
}
snprintf(dev->mtd_name, sizeof(dev->mtd_name), "%d%ciB %s", size, unit, "PCMCIA Memory card");
}
if(mtd->size <= dev->win_size) {
pr_debug("Using non remapping memory functions\n");
dev->pcmcia_map.map_priv_2 = (unsigned long)dev->win_base;
if (dev->pcmcia_map.bankwidth == 1) {
dev->pcmcia_map.read = pcmcia_read8;
dev->pcmcia_map.write = pcmcia_write8;
} else {
dev->pcmcia_map.read = pcmcia_read16;
dev->pcmcia_map.write = pcmcia_write16;
}
dev->pcmcia_map.copy_from = pcmcia_copy_from;
dev->pcmcia_map.copy_to = pcmcia_copy_to;
}
if (mtd_device_register(mtd, NULL, 0)) {
map_destroy(mtd);
dev->mtd_info = NULL;
dev_err(&dev->p_dev->dev,
"Could not register the MTD device\n");
pcmciamtd_release(link);
return -ENODEV;
}
dev_info(&dev->p_dev->dev, "mtd%d: %s\n", mtd->index, mtd->name);
return 0;
}
static int pcmciamtd_suspend(struct pcmcia_device *dev)
{
pr_debug("EVENT_PM_RESUME\n");
return 0;
}
static int pcmciamtd_resume(struct pcmcia_device *dev)
{
pr_debug("EVENT_PM_SUSPEND\n");
return 0;
}
static void pcmciamtd_detach(struct pcmcia_device *link)
{
struct pcmciamtd_dev *dev = link->priv;
pr_debug("link=0x%p\n", link);
if(dev->mtd_info) {
mtd_device_unregister(dev->mtd_info);
dev_info(&dev->p_dev->dev, "mtd%d: Removing\n",
dev->mtd_info->index);
map_destroy(dev->mtd_info);
}
pcmciamtd_release(link);
}
static int pcmciamtd_probe(struct pcmcia_device *link)
{
struct pcmciamtd_dev *dev;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) return -ENOMEM;
pr_debug("dev=0x%p\n", dev);
dev->p_dev = link;
link->priv = dev;
return pcmciamtd_config(link);
}
static int __init init_pcmciamtd(void)
{
if(bankwidth && bankwidth != 1 && bankwidth != 2) {
info("bad bankwidth (%d), using default", bankwidth);
bankwidth = 2;
}
if(force_size && (force_size < 1 || force_size > 64)) {
info("bad force_size (%d), using default", force_size);
force_size = 0;
}
if(mem_type && mem_type != 1 && mem_type != 2) {
info("bad mem_type (%d), using default", mem_type);
mem_type = 0;
}
return pcmcia_register_driver(&pcmciamtd_driver);
}
static void __exit exit_pcmciamtd(void)
{
pr_debug(DRIVER_DESC " unloading");
pcmcia_unregister_driver(&pcmciamtd_driver);
}
