static inline int not_useful(void *p, int map)
{
unsigned long pv=(unsigned long)p;
pv &= 3;
if(map & (1<<pv))
return 0;
return 1;
}
static unsigned long nubus_get_rom(unsigned char **ptr, int len, int map)
{
unsigned long v = 0;
unsigned char *p = *ptr;
while(len)
{
v <<= 8;
while(not_useful(p,map))
p++;
v |= *p++;
len--;
}
*ptr = p;
return v;
}
static void nubus_rewind(unsigned char **ptr, int len, int map)
{
unsigned char *p=*ptr;
if(len > 65536)
printk(KERN_ERR "rewind of 0x%08x!\n", len);
while(len)
{
do
{
p--;
}
while(not_useful(p, map));
len--;
}
*ptr=p;
}
static void nubus_advance(unsigned char **ptr, int len, int map)
{
unsigned char *p = *ptr;
if(len>65536)
printk(KERN_ERR "advance of 0x%08x!\n", len);
while(len)
{
while(not_useful(p,map))
p++;
p++;
len--;
}
*ptr = p;
}
static void nubus_move(unsigned char **ptr, int len, int map)
{
if(len > 0)
nubus_advance(ptr, len, map);
else if(len < 0)
nubus_rewind(ptr, -len, map);
}
static inline long nubus_expand32(long foo)
{
if(foo & 0x00800000)
foo |= 0xFF000000;
return foo;
}
static inline void *nubus_rom_addr(int slot)
{
return (void *)(0xF1000000+(slot<<24));
}
static unsigned char *nubus_dirptr(const struct nubus_dirent *nd)
{
unsigned char *p = nd->base;
nubus_move(&p, nubus_expand32(nd->data), nd->mask);
return p;
}
void nubus_get_rsrc_mem(void *dest, const struct nubus_dirent* dirent,
int len)
{
unsigned char *t = (unsigned char *)dest;
unsigned char *p = nubus_dirptr(dirent);
while(len)
{
*t++ = nubus_get_rom(&p, 1, dirent->mask);
len--;
}
}
void nubus_get_rsrc_str(void *dest, const struct nubus_dirent* dirent,
int len)
{
unsigned char *t=(unsigned char *)dest;
unsigned char *p = nubus_dirptr(dirent);
while(len)
{
*t = nubus_get_rom(&p, 1, dirent->mask);
if(!*t++)
break;
len--;
}
}
int nubus_get_root_dir(const struct nubus_board* board,
struct nubus_dir* dir)
{
dir->ptr = dir->base = board->directory;
dir->done = 0;
dir->mask = board->lanes;
return 0;
}
int nubus_get_func_dir(const struct nubus_dev* dev,
struct nubus_dir* dir)
{
dir->ptr = dir->base = dev->directory;
dir->done = 0;
dir->mask = dev->board->lanes;
return 0;
}
int nubus_get_board_dir(const struct nubus_board* board,
struct nubus_dir* dir)
{
struct nubus_dirent ent;
dir->ptr = dir->base = board->directory;
dir->done = 0;
dir->mask = board->lanes;
if (nubus_readdir(dir, &ent) == -1)
return -1;
if (nubus_get_subdir(&ent, dir) == -1)
return -1;
return 0;
}
int nubus_get_subdir(const struct nubus_dirent *ent,
struct nubus_dir *dir)
{
dir->ptr = dir->base = nubus_dirptr(ent);
dir->done = 0;
dir->mask = ent->mask;
return 0;
}
int nubus_readdir(struct nubus_dir *nd, struct nubus_dirent *ent)
{
u32 resid;
if (nd->done)
return -1;
ent->base = nd->ptr;
resid = nubus_get_rom(&nd->ptr, 4, nd->mask);
if((resid&0xff000000) == 0xff000000)
{
nd->done = 1;
return -1;
}
ent->type = resid >> 24;
ent->data = resid & 0xffffff;
ent->mask = nd->mask;
return 0;
}
int nubus_rewinddir(struct nubus_dir* dir)
{
dir->ptr = dir->base;
return 0;
}
struct nubus_dev*
nubus_find_device(unsigned short category,
unsigned short type,
unsigned short dr_hw,
unsigned short dr_sw,
const struct nubus_dev* from)
{
struct nubus_dev* itor =
from ? from->next : nubus_devices;
while (itor) {
if (itor->category == category
&& itor->type == type
&& itor->dr_hw == dr_hw
&& itor->dr_sw == dr_sw)
return itor;
itor = itor->next;
}
return NULL;
}
struct nubus_dev*
nubus_find_type(unsigned short category,
unsigned short type,
const struct nubus_dev* from)
{
struct nubus_dev* itor =
from ? from->next : nubus_devices;
while (itor) {
if (itor->category == category
&& itor->type == type)
return itor;
itor = itor->next;
}
return NULL;
}
struct nubus_dev*
nubus_find_slot(unsigned int slot,
const struct nubus_dev* from)
{
struct nubus_dev* itor =
from ? from->next : nubus_devices;
while (itor) {
if (itor->board->slot == slot)
return itor;
itor = itor->next;
}
return NULL;
}
int
nubus_find_rsrc(struct nubus_dir* dir, unsigned char rsrc_type,
struct nubus_dirent* ent)
{
while (nubus_readdir(dir, ent) != -1) {
if (ent->type == rsrc_type)
return 0;
}
return -1;
}
static int __init nubus_show_display_resource(struct nubus_dev* dev,
const struct nubus_dirent* ent)
{
switch (ent->type) {
case NUBUS_RESID_GAMMADIR:
printk(KERN_INFO " gamma directory offset: 0x%06x\n", ent->data);
break;
case 0x0080 ... 0x0085:
printk(KERN_INFO " mode %02X info offset: 0x%06x\n",
ent->type, ent->data);
break;
default:
printk(KERN_INFO " unknown resource %02X, data 0x%06x\n",
ent->type, ent->data);
}
return 0;
}
static int __init nubus_show_network_resource(struct nubus_dev* dev,
const struct nubus_dirent* ent)
{
switch (ent->type) {
case NUBUS_RESID_MAC_ADDRESS:
{
char addr[6];
int i;
nubus_get_rsrc_mem(addr, ent, 6);
printk(KERN_INFO " MAC address: ");
for (i = 0; i < 6; i++)
printk("%02x%s", addr[i] & 0xff,
i == 5 ? "" : ":");
printk("\n");
break;
}
default:
printk(KERN_INFO " unknown resource %02X, data 0x%06x\n",
ent->type, ent->data);
}
return 0;
}
static int __init nubus_show_cpu_resource(struct nubus_dev* dev,
const struct nubus_dirent* ent)
{
switch (ent->type) {
case NUBUS_RESID_MEMINFO:
{
unsigned long meminfo[2];
nubus_get_rsrc_mem(&meminfo, ent, 8);
printk(KERN_INFO " memory: [ 0x%08lx 0x%08lx ]\n",
meminfo[0], meminfo[1]);
break;
}
case NUBUS_RESID_ROMINFO:
{
unsigned long rominfo[2];
nubus_get_rsrc_mem(&rominfo, ent, 8);
printk(KERN_INFO " ROM: [ 0x%08lx 0x%08lx ]\n",
rominfo[0], rominfo[1]);
break;
}
default:
printk(KERN_INFO " unknown resource %02X, data 0x%06x\n",
ent->type, ent->data);
}
return 0;
}
static int __init nubus_show_private_resource(struct nubus_dev* dev,
const struct nubus_dirent* ent)
{
switch (dev->category) {
case NUBUS_CAT_DISPLAY:
nubus_show_display_resource(dev, ent);
break;
case NUBUS_CAT_NETWORK:
nubus_show_network_resource(dev, ent);
break;
case NUBUS_CAT_CPU:
nubus_show_cpu_resource(dev, ent);
break;
default:
printk(KERN_INFO " unknown resource %02X, data 0x%06x\n",
ent->type, ent->data);
}
return 0;
}
static struct nubus_dev* __init
nubus_get_functional_resource(struct nubus_board* board,
int slot,
const struct nubus_dirent* parent)
{
struct nubus_dir dir;
struct nubus_dirent ent;
struct nubus_dev* dev;
printk(KERN_INFO " Function 0x%02x:\n", parent->type);
nubus_get_subdir(parent, &dir);
if (slot == 0 && (unsigned long)dir.base % 2)
dir.base += 1;
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_DEBUG "nubus_get_functional_resource: parent is 0x%p, dir is 0x%p\n",
parent->base, dir.base);
if ((dev = kzalloc(sizeof(*dev), GFP_ATOMIC)) == NULL)
return NULL;
dev->resid = parent->type;
dev->directory = dir.base;
dev->board = board;
while (nubus_readdir(&dir, &ent) != -1)
{
switch(ent.type)
{
case NUBUS_RESID_TYPE:
{
unsigned short nbtdata[4];
nubus_get_rsrc_mem(nbtdata, &ent, 8);
dev->category = nbtdata[0];
dev->type = nbtdata[1];
dev->dr_sw = nbtdata[2];
dev->dr_hw = nbtdata[3];
printk(KERN_INFO " type: [cat 0x%x type 0x%x hw 0x%x sw 0x%x]\n",
nbtdata[0], nbtdata[1], nbtdata[2], nbtdata[3]);
break;
}
case NUBUS_RESID_NAME:
{
nubus_get_rsrc_str(dev->name, &ent, 64);
printk(KERN_INFO " name: %s\n", dev->name);
break;
}
case NUBUS_RESID_DRVRDIR:
{
struct nubus_dir drvr_dir;
struct nubus_dirent drvr_ent;
nubus_get_subdir(&ent, &drvr_dir);
nubus_readdir(&drvr_dir, &drvr_ent);
dev->driver = nubus_dirptr(&drvr_ent);
printk(KERN_INFO " driver at: 0x%p\n",
dev->driver);
break;
}
case NUBUS_RESID_MINOR_BASEOS:
nubus_get_rsrc_mem(&dev->iobase, &ent, 4);
printk(KERN_INFO " memory offset: 0x%08lx\n",
dev->iobase);
break;
case NUBUS_RESID_MINOR_LENGTH:
nubus_get_rsrc_mem(&dev->iosize, &ent, 4);
printk(KERN_INFO " memory length: 0x%08lx\n",
dev->iosize);
break;
case NUBUS_RESID_FLAGS:
dev->flags = ent.data;
printk(KERN_INFO " flags: 0x%06x\n", dev->flags);
break;
case NUBUS_RESID_HWDEVID:
dev->hwdevid = ent.data;
printk(KERN_INFO " hwdevid: 0x%06x\n", dev->hwdevid);
break;
default:
nubus_show_private_resource(dev, &ent);
}
}
return dev;
}
static int __init nubus_get_vidnames(struct nubus_board* board,
const struct nubus_dirent* parent)
{
struct nubus_dir dir;
struct nubus_dirent ent;
struct vidmode {
u32 size;
u16 id;
char name[32];
};
printk(KERN_INFO " video modes supported:\n");
nubus_get_subdir(parent, &dir);
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_DEBUG "nubus_get_vidnames: parent is 0x%p, dir is 0x%p\n",
parent->base, dir.base);
while(nubus_readdir(&dir, &ent) != -1)
{
struct vidmode mode;
u32 size;
nubus_get_rsrc_mem(&size, &ent, 4);
if (size > sizeof(mode) - 1)
size = sizeof(mode) - 1;
memset(&mode, 0, sizeof(mode));
nubus_get_rsrc_mem(&mode, &ent, size);
printk (KERN_INFO " %02X: (%02X) %s\n", ent.type,
mode.id, mode.name);
}
return 0;
}
static int __init nubus_get_icon(struct nubus_board* board,
const struct nubus_dirent* ent)
{
unsigned char icon[128];
int x, y;
nubus_get_rsrc_mem(&icon, ent, 128);
printk(KERN_INFO " icon:\n");
for (y = 0; y < 32; y++) {
printk(KERN_INFO " ");
for (x = 0; x < 32; x++) {
if (icon[y*4 + x/8]
& (0x80 >> (x%8)))
printk("*");
else
printk(" ");
}
printk("\n");
}
return 0;
}
static int __init nubus_get_vendorinfo(struct nubus_board* board,
const struct nubus_dirent* parent)
{
struct nubus_dir dir;
struct nubus_dirent ent;
static char* vendor_fields[6] = {"ID", "serial", "revision",
"part", "date", "unknown field"};
printk(KERN_INFO " vendor info:\n");
nubus_get_subdir(parent, &dir);
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_DEBUG "nubus_get_vendorinfo: parent is 0x%p, dir is 0x%p\n",
parent->base, dir.base);
while(nubus_readdir(&dir, &ent) != -1)
{
char name[64];
nubus_get_rsrc_str(name, &ent, 64);
if (ent.type > 5)
ent.type = 5;
printk(KERN_INFO " %s: %s\n",
vendor_fields[ent.type-1], name);
}
return 0;
}
static int __init nubus_get_board_resource(struct nubus_board* board, int slot,
const struct nubus_dirent* parent)
{
struct nubus_dir dir;
struct nubus_dirent ent;
nubus_get_subdir(parent, &dir);
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_DEBUG "nubus_get_board_resource: parent is 0x%p, dir is 0x%p\n",
parent->base, dir.base);
while(nubus_readdir(&dir, &ent) != -1)
{
switch (ent.type) {
case NUBUS_RESID_TYPE:
{
unsigned short nbtdata[4];
nubus_get_rsrc_mem(nbtdata, &ent, 8);
printk(KERN_INFO " type: [cat 0x%x type 0x%x hw 0x%x sw 0x%x]\n",
nbtdata[0], nbtdata[1], nbtdata[2],
nbtdata[3]);
if (nbtdata[0] != 1 || nbtdata[1] != 0 ||
nbtdata[2] != 0 || nbtdata[3] != 0)
printk(KERN_ERR "this sResource is not a board resource!\n");
break;
}
case NUBUS_RESID_NAME:
nubus_get_rsrc_str(board->name, &ent, 64);
printk(KERN_INFO " name: %s\n", board->name);
break;
case NUBUS_RESID_ICON:
nubus_get_icon(board, &ent);
break;
case NUBUS_RESID_BOARDID:
printk(KERN_INFO " board id: 0x%x\n", ent.data);
break;
case NUBUS_RESID_PRIMARYINIT:
printk(KERN_INFO " primary init offset: 0x%06x\n", ent.data);
break;
case NUBUS_RESID_VENDORINFO:
nubus_get_vendorinfo(board, &ent);
break;
case NUBUS_RESID_FLAGS:
printk(KERN_INFO " flags: 0x%06x\n", ent.data);
break;
case NUBUS_RESID_HWDEVID:
printk(KERN_INFO " hwdevid: 0x%06x\n", ent.data);
break;
case NUBUS_RESID_SECONDINIT:
printk(KERN_INFO " secondary init offset: 0x%06x\n", ent.data);
break;
case NUBUS_RESID_VIDNAMES:
nubus_get_vidnames(board, &ent);
break;
case NUBUS_RESID_VIDMODES:
printk(KERN_INFO " video mode parameter directory offset: 0x%06x\n",
ent.data);
break;
default:
printk(KERN_INFO " unknown resource %02X, data 0x%06x\n",
ent.type, ent.data);
}
}
return 0;
}
static void __init nubus_find_rom_dir(struct nubus_board* board)
{
unsigned char* rp;
unsigned char* romdir;
struct nubus_dir dir;
struct nubus_dirent ent;
rp = board->fblock;
nubus_rewind(&rp, 4, board->lanes);
if (nubus_get_rom(&rp, 4, board->lanes) != NUBUS_TEST_PATTERN) {
board->directory = board->fblock;
nubus_move(&board->directory,
nubus_expand32(board->doffset),
board->lanes);
return;
}
romdir = nubus_rom_addr(board->slot);
nubus_rewind(&romdir, ROM_DIR_OFFSET, board->lanes);
dir.base = dir.ptr = romdir;
dir.done = 0;
dir.mask = board->lanes;
if (nubus_readdir(&dir, &ent) == -1)
goto badrom;
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_INFO "nubus_get_rom_dir: entry %02x %06x\n", ent.type, ent.data);
if (nubus_readdir(&dir, &ent) == -1)
goto badrom;
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_DEBUG "nubus_get_rom_dir: entry %02x %06x\n", ent.type, ent.data);
nubus_get_subdir(&ent, &dir);
if (nubus_readdir(&dir, &ent) == -1)
goto badrom;
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_DEBUG "nubus_get_rom_dir: entry %02x %06x\n", ent.type, ent.data);
if (nubus_readdir(&dir, &ent) == -1)
goto badrom;
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG)
printk(KERN_DEBUG "nubus_get_rom_dir: entry %02x %06x\n", ent.type, ent.data);
nubus_get_subdir(&ent, &dir);
board->directory = dir.base;
return;
badrom:
board->directory = board->fblock;
nubus_move(&board->directory, nubus_expand32(board->doffset), board->lanes);
printk(KERN_ERR "nubus_get_rom_dir: ROM weirdness! Notify the developers...\n");
}
static struct nubus_board* __init nubus_add_board(int slot, int bytelanes)
{
struct nubus_board* board;
struct nubus_board** boardp;
unsigned char *rp;
unsigned long dpat;
struct nubus_dir dir;
struct nubus_dirent ent;
rp = nubus_rom_addr(slot);
nubus_rewind(&rp, FORMAT_BLOCK_SIZE, bytelanes);
if ((board = kzalloc(sizeof(*board), GFP_ATOMIC)) == NULL)
return NULL;
board->fblock = rp;
if (console_loglevel >= CONSOLE_LOGLEVEL_DEBUG) {
int i;
printk(KERN_DEBUG "Slot %X, format block at 0x%p\n",
slot, rp);
printk(KERN_DEBUG "Format block: ");
for (i = 0; i < FORMAT_BLOCK_SIZE; i += 4) {
unsigned short foo, bar;
foo = nubus_get_rom(&rp, 2, bytelanes);
bar = nubus_get_rom(&rp, 2, bytelanes);
printk("%04x %04x ", foo, bar);
}
printk("\n");
rp = board->fblock;
}
board->slot = slot;
board->slot_addr = (unsigned long) nubus_slot_addr(slot);
board->doffset = nubus_get_rom(&rp, 4, bytelanes);
board->rom_length = nubus_get_rom(&rp, 4, bytelanes);
board->crc = nubus_get_rom(&rp, 4, bytelanes);
board->rev = nubus_get_rom(&rp, 1, bytelanes);
board->format = nubus_get_rom(&rp,1, bytelanes);
board->lanes = bytelanes;
if(!(board->doffset & 0x00FF0000))
printk(KERN_WARNING "Dodgy doffset!\n");
dpat = nubus_get_rom(&rp, 4, bytelanes);
if(dpat != NUBUS_TEST_PATTERN)
printk(KERN_WARNING "Wrong test pattern %08lx!\n", dpat);
nubus_find_rom_dir(board);
nubus_get_root_dir(board, &dir);
printk(KERN_INFO "Slot %X:\n", slot);
if (nubus_readdir(&dir, &ent) == -1) {
printk(KERN_ERR "Board resource not found!\n");
return NULL;
} else {
printk(KERN_INFO " Board resource:\n");
nubus_get_board_resource(board, slot, &ent);
}
while (nubus_readdir(&dir, &ent) != -1) {
struct nubus_dev* dev;
struct nubus_dev** devp;
dev = nubus_get_functional_resource(board, slot, &ent);
if (dev == NULL)
continue;
if (board->first_dev == NULL)
board->first_dev = dev;
for (devp=&nubus_devices; *devp!=NULL; devp=&((*devp)->next))
;
*devp = dev;
dev->next = NULL;
}
for (boardp=&nubus_boards; *boardp!=NULL; boardp=&((*boardp)->next))
;
*boardp = board;
board->next = NULL;
return board;
}
void __init nubus_probe_slot(int slot)
{
unsigned char dp;
unsigned char* rp;
int i;
rp = nubus_rom_addr(slot);
for(i = 4; i; i--)
{
unsigned long flags;
int card_present;
rp--;
local_irq_save(flags);
card_present = hwreg_present(rp);
local_irq_restore(flags);
if (!card_present)
continue;
printk(KERN_DEBUG "Now probing slot %X at %p\n", slot, rp);
dp = *rp;
if(dp == 0)
continue;
if ((((dp>>4) ^ dp) & 0x0F) != 0x0F)
continue;
if ((dp & 0x0F) >= (1<<i))
continue;
nubus_add_board(slot, dp);
return;
}
}
void __init nubus_scan_bus(void)
{
int slot;
#ifdef I_WANT_TO_PROBE_SLOT_ZERO
nubus_probe_slot(0);
#endif
for(slot = 9; slot < 15; slot++)
{
nubus_probe_slot(slot);
}
}
static int __init nubus_init(void)
{
if (!MACH_IS_MAC)
return 0;
if (oss_present) {
oss_nubus_init();
} else {
via_nubus_init();
}
#ifdef TRY_TO_DODGE_WSOD
mdelay(1000);
#endif
printk("NuBus: Scanning NuBus slots.\n");
nubus_devices = NULL;
nubus_boards = NULL;
nubus_scan_bus();
nubus_proc_init();
return 0;
}
