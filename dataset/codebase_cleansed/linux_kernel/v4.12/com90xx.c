static void __init com90xx_probe(void)
{
int count, status, ioaddr, numprint, airq, openparen = 0;
unsigned long airqmask;
int ports[(0x3f0 - 0x200) / 16 + 1] = { 0 };
unsigned long *shmems;
void __iomem **iomem;
int numports, numshmems, *port;
u_long *p;
int index;
if (!io && !irq && !shmem && !*device && com90xx_skip_probe)
return;
shmems = kzalloc(((0x100000 - 0xa0000) / 0x800) * sizeof(unsigned long),
GFP_KERNEL);
if (!shmems)
return;
iomem = kzalloc(((0x100000 - 0xa0000) / 0x800) * sizeof(void __iomem *),
GFP_KERNEL);
if (!iomem) {
kfree(shmems);
return;
}
if (BUGLVL(D_NORMAL))
pr_info("%s\n", "COM90xx chipset support");
numports = numshmems = 0;
if (io)
ports[numports++] = io;
else
for (count = 0x200; count <= 0x3f0; count += 16)
ports[numports++] = count;
if (shmem)
shmems[numshmems++] = shmem;
else
for (count = 0xA0000; count <= 0xFF800; count += 2048)
shmems[numshmems++] = count;
numprint = -1;
for (port = &ports[0]; port - ports < numports; port++) {
numprint++;
numprint %= 8;
if (!numprint) {
arc_cont(D_INIT, "\n");
arc_cont(D_INIT, "S1: ");
}
arc_cont(D_INIT, "%Xh ", *port);
ioaddr = *port;
if (!request_region(*port, ARCNET_TOTAL_SIZE,
"arcnet (90xx)")) {
arc_cont(D_INIT_REASONS, "(request_region)\n");
arc_cont(D_INIT_REASONS, "S1: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
*port-- = ports[--numports];
continue;
}
if (arcnet_inb(ioaddr, COM9026_REG_R_STATUS) == 0xFF) {
arc_cont(D_INIT_REASONS, "(empty)\n");
arc_cont(D_INIT_REASONS, "S1: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
release_region(*port, ARCNET_TOTAL_SIZE);
*port-- = ports[--numports];
continue;
}
arcnet_inb(ioaddr, COM9026_REG_R_RESET);
arc_cont(D_INIT_REASONS, "\n");
arc_cont(D_INIT_REASONS, "S1: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
}
arc_cont(D_INIT, "\n");
if (!numports) {
arc_cont(D_NORMAL, "S1: No ARCnet cards found.\n");
kfree(shmems);
kfree(iomem);
return;
}
numprint = -1;
for (port = &ports[0]; port < ports + numports; port++) {
numprint++;
numprint %= 8;
if (!numprint) {
arc_cont(D_INIT, "\n");
arc_cont(D_INIT, "S2: ");
}
arc_cont(D_INIT, "%Xh ", *port);
}
arc_cont(D_INIT, "\n");
mdelay(RESETtime);
numprint = -1;
for (index = 0, p = &shmems[0]; index < numshmems; p++, index++) {
void __iomem *base;
numprint++;
numprint %= 8;
if (!numprint) {
arc_cont(D_INIT, "\n");
arc_cont(D_INIT, "S3: ");
}
arc_cont(D_INIT, "%lXh ", *p);
if (!request_mem_region(*p, MIRROR_SIZE, "arcnet (90xx)")) {
arc_cont(D_INIT_REASONS, "(request_mem_region)\n");
arc_cont(D_INIT_REASONS, "Stage 3: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
goto out;
}
base = ioremap(*p, MIRROR_SIZE);
if (!base) {
arc_cont(D_INIT_REASONS, "(ioremap)\n");
arc_cont(D_INIT_REASONS, "Stage 3: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
goto out1;
}
if (arcnet_readb(base, COM9026_REG_R_STATUS) != TESTvalue) {
arc_cont(D_INIT_REASONS, "(%02Xh != %02Xh)\n",
arcnet_readb(base, COM9026_REG_R_STATUS),
TESTvalue);
arc_cont(D_INIT_REASONS, "S3: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
goto out2;
}
arcnet_writeb(0x42, base, COM9026_REG_W_INTMASK);
if (arcnet_readb(base, COM9026_REG_R_STATUS) != 0x42) {
arc_cont(D_INIT_REASONS, "(read only)\n");
arc_cont(D_INIT_REASONS, "S3: ");
goto out2;
}
arc_cont(D_INIT_REASONS, "\n");
arc_cont(D_INIT_REASONS, "S3: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
iomem[index] = base;
continue;
out2:
iounmap(base);
out1:
release_mem_region(*p, MIRROR_SIZE);
out:
*p-- = shmems[--numshmems];
index--;
}
arc_cont(D_INIT, "\n");
if (!numshmems) {
arc_cont(D_NORMAL, "S3: No ARCnet cards found.\n");
for (port = &ports[0]; port < ports + numports; port++)
release_region(*port, ARCNET_TOTAL_SIZE);
kfree(shmems);
kfree(iomem);
return;
}
numprint = -1;
for (p = &shmems[0]; p < shmems + numshmems; p++) {
numprint++;
numprint %= 8;
if (!numprint) {
arc_cont(D_INIT, "\n");
arc_cont(D_INIT, "S4: ");
}
arc_cont(D_INIT, "%lXh ", *p);
}
arc_cont(D_INIT, "\n");
numprint = -1;
for (port = &ports[0]; port < ports + numports; port++) {
int found = 0;
numprint++;
numprint %= 8;
if (!numprint) {
arc_cont(D_INIT, "\n");
arc_cont(D_INIT, "S5: ");
}
arc_cont(D_INIT, "%Xh ", *port);
ioaddr = *port;
status = arcnet_inb(ioaddr, COM9026_REG_R_STATUS);
if ((status & 0x9D)
!= (NORXflag | RECONflag | TXFREEflag | RESETflag)) {
arc_cont(D_INIT_REASONS, "(status=%Xh)\n", status);
arc_cont(D_INIT_REASONS, "S5: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
release_region(*port, ARCNET_TOTAL_SIZE);
*port-- = ports[--numports];
continue;
}
arcnet_outb(CFLAGScmd | RESETclear | CONFIGclear,
ioaddr, COM9026_REG_W_COMMAND);
status = arcnet_inb(ioaddr, COM9026_REG_R_STATUS);
if (status & RESETflag) {
arc_cont(D_INIT_REASONS, " (eternal reset, status=%Xh)\n",
status);
arc_cont(D_INIT_REASONS, "S5: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
release_region(*port, ARCNET_TOTAL_SIZE);
*port-- = ports[--numports];
continue;
}
if (!irq) {
airqmask = probe_irq_on();
arcnet_outb(NORXflag, ioaddr, COM9026_REG_W_INTMASK);
udelay(1);
arcnet_outb(0, ioaddr, COM9026_REG_W_INTMASK);
airq = probe_irq_off(airqmask);
if (airq <= 0) {
arc_cont(D_INIT_REASONS, "(airq=%d)\n", airq);
arc_cont(D_INIT_REASONS, "S5: ");
if (BUGLVL(D_INIT_REASONS))
numprint = 0;
release_region(*port, ARCNET_TOTAL_SIZE);
*port-- = ports[--numports];
continue;
}
} else {
airq = irq;
}
arc_cont(D_INIT, "(%d,", airq);
openparen = 1;
#ifdef FAST_PROBE
if (numports > 1 || numshmems > 1) {
arcnet_inb(ioaddr, COM9026_REG_R_RESET);
mdelay(RESETtime);
} else {
arcnet_writeb(TESTvalue, iomem[0],
COM9026_REG_W_INTMASK);
}
#else
arcnet_inb(ioaddr, COM9026_REG_R_RESET);
mdelay(RESETtime);
#endif
for (index = 0; index < numshmems; index++) {
u_long ptr = shmems[index];
void __iomem *base = iomem[index];
if (arcnet_readb(base, COM9026_REG_R_STATUS) == TESTvalue) {
arc_cont(D_INIT, "%lXh)\n", *p);
openparen = 0;
if (com90xx_found(*port, airq, ptr, base) == 0)
found = 1;
numprint = -1;
shmems[index] = shmems[--numshmems];
iomem[index] = iomem[numshmems];
break;
} else {
arc_cont(D_INIT_REASONS, "%Xh-",
arcnet_readb(base, COM9026_REG_R_STATUS));
}
}
if (openparen) {
if (BUGLVL(D_INIT))
pr_cont("no matching shmem)\n");
if (BUGLVL(D_INIT_REASONS)) {
pr_cont("S5: ");
numprint = 0;
}
}
if (!found)
release_region(*port, ARCNET_TOTAL_SIZE);
*port-- = ports[--numports];
}
if (BUGLVL(D_INIT_REASONS))
pr_cont("\n");
for (index = 0; index < numshmems; index++) {
arcnet_writeb(TESTvalue, iomem[index], COM9026_REG_W_INTMASK);
iounmap(iomem[index]);
release_mem_region(shmems[index], MIRROR_SIZE);
}
kfree(shmems);
kfree(iomem);
}
static int __init check_mirror(unsigned long addr, size_t size)
{
void __iomem *p;
int res = -1;
if (!request_mem_region(addr, size, "arcnet (90xx)"))
return -1;
p = ioremap(addr, size);
if (p) {
if (arcnet_readb(p, COM9026_REG_R_STATUS) == TESTvalue)
res = 1;
else
res = 0;
iounmap(p);
}
release_mem_region(addr, size);
return res;
}
static int __init com90xx_found(int ioaddr, int airq, u_long shmem,
void __iomem *p)
{
struct net_device *dev = NULL;
struct arcnet_local *lp;
u_long first_mirror, last_mirror;
int mirror_size;
dev = alloc_arcdev(device);
if (!dev) {
arc_cont(D_NORMAL, "com90xx: Can't allocate device!\n");
iounmap(p);
release_mem_region(shmem, MIRROR_SIZE);
return -ENOMEM;
}
lp = netdev_priv(dev);
mirror_size = MIRROR_SIZE;
if (arcnet_readb(p, COM9026_REG_R_STATUS) == TESTvalue &&
check_mirror(shmem - MIRROR_SIZE, MIRROR_SIZE) == 0 &&
check_mirror(shmem - 2 * MIRROR_SIZE, MIRROR_SIZE) == 1)
mirror_size = 2 * MIRROR_SIZE;
first_mirror = shmem - mirror_size;
while (check_mirror(first_mirror, mirror_size) == 1)
first_mirror -= mirror_size;
first_mirror += mirror_size;
last_mirror = shmem + mirror_size;
while (check_mirror(last_mirror, mirror_size) == 1)
last_mirror += mirror_size;
last_mirror -= mirror_size;
dev->mem_start = first_mirror;
dev->mem_end = last_mirror + MIRROR_SIZE - 1;
iounmap(p);
release_mem_region(shmem, MIRROR_SIZE);
if (!request_mem_region(dev->mem_start,
dev->mem_end - dev->mem_start + 1,
"arcnet (90xx)"))
goto err_free_dev;
if (request_irq(airq, arcnet_interrupt, 0, "arcnet (90xx)", dev)) {
arc_printk(D_NORMAL, dev, "Can't get IRQ %d!\n", airq);
goto err_release_mem;
}
dev->irq = airq;
lp->card_name = "COM90xx";
lp->hw.command = com90xx_command;
lp->hw.status = com90xx_status;
lp->hw.intmask = com90xx_setmask;
lp->hw.reset = com90xx_reset;
lp->hw.owner = THIS_MODULE;
lp->hw.copy_to_card = com90xx_copy_to_card;
lp->hw.copy_from_card = com90xx_copy_from_card;
lp->mem_start = ioremap(dev->mem_start,
dev->mem_end - dev->mem_start + 1);
if (!lp->mem_start) {
arc_printk(D_NORMAL, dev, "Can't remap device memory!\n");
goto err_free_irq;
}
dev->dev_addr[0] = arcnet_readb(lp->mem_start, COM9026_REG_R_STATION);
dev->base_addr = ioaddr;
arc_printk(D_NORMAL, dev, "COM90xx station %02Xh found at %03lXh, IRQ %d, ShMem %lXh (%ld*%xh).\n",
dev->dev_addr[0],
dev->base_addr, dev->irq, dev->mem_start,
(dev->mem_end - dev->mem_start + 1) / mirror_size,
mirror_size);
if (register_netdev(dev))
goto err_unmap;
cards[numcards++] = dev;
return 0;
err_unmap:
iounmap(lp->mem_start);
err_free_irq:
free_irq(dev->irq, dev);
err_release_mem:
release_mem_region(dev->mem_start, dev->mem_end - dev->mem_start + 1);
err_free_dev:
free_netdev(dev);
return -EIO;
}
static void com90xx_command(struct net_device *dev, int cmd)
{
short ioaddr = dev->base_addr;
arcnet_outb(cmd, ioaddr, COM9026_REG_W_COMMAND);
}
static int com90xx_status(struct net_device *dev)
{
short ioaddr = dev->base_addr;
return arcnet_inb(ioaddr, COM9026_REG_R_STATUS);
}
static void com90xx_setmask(struct net_device *dev, int mask)
{
short ioaddr = dev->base_addr;
arcnet_outb(mask, ioaddr, COM9026_REG_W_INTMASK);
}
static int com90xx_reset(struct net_device *dev, int really_reset)
{
struct arcnet_local *lp = netdev_priv(dev);
short ioaddr = dev->base_addr;
arc_printk(D_INIT, dev, "Resetting (status=%02Xh)\n",
arcnet_inb(ioaddr, COM9026_REG_R_STATUS));
if (really_reset) {
arcnet_inb(ioaddr, COM9026_REG_R_RESET);
mdelay(RESETtime);
}
arcnet_outb(CFLAGScmd | RESETclear, ioaddr, COM9026_REG_W_COMMAND);
arcnet_outb(CFLAGScmd | CONFIGclear, ioaddr, COM9026_REG_W_COMMAND);
#if 0
arcnet_outb(arcnet_inb(ioaddr, COM9026_REG_RW_CONFIG) | ENABLE16flag,
ioaddr, COM9026_REG_RW_CONFIG);
#endif
if (arcnet_readb(lp->mem_start, COM9026_REG_R_STATUS) != TESTvalue) {
if (really_reset)
arc_printk(D_NORMAL, dev, "reset failed: TESTvalue not present.\n");
return 1;
}
arcnet_outb(CONFIGcmd | EXTconf, ioaddr, COM9026_REG_W_COMMAND);
if (BUGLVL(D_DURING))
memset_io(lp->mem_start, 0x42, 2048);
return 0;
}
static void com90xx_copy_to_card(struct net_device *dev, int bufnum,
int offset, void *buf, int count)
{
struct arcnet_local *lp = netdev_priv(dev);
void __iomem *memaddr = lp->mem_start + bufnum * 512 + offset;
TIME(dev, "memcpy_toio", count, memcpy_toio(memaddr, buf, count));
}
static void com90xx_copy_from_card(struct net_device *dev, int bufnum,
int offset, void *buf, int count)
{
struct arcnet_local *lp = netdev_priv(dev);
void __iomem *memaddr = lp->mem_start + bufnum * 512 + offset;
TIME(dev, "memcpy_fromio", count, memcpy_fromio(buf, memaddr, count));
}
static int __init com90xx_init(void)
{
if (irq == 2)
irq = 9;
com90xx_probe();
if (!numcards)
return -EIO;
return 0;
}
static void __exit com90xx_exit(void)
{
struct net_device *dev;
struct arcnet_local *lp;
int count;
for (count = 0; count < numcards; count++) {
dev = cards[count];
lp = netdev_priv(dev);
unregister_netdev(dev);
free_irq(dev->irq, dev);
iounmap(lp->mem_start);
release_region(dev->base_addr, ARCNET_TOTAL_SIZE);
release_mem_region(dev->mem_start,
dev->mem_end - dev->mem_start + 1);
free_netdev(dev);
}
}
static int __init com90xx_setup(char *s)
{
int ints[8];
s = get_options(s, 8, ints);
if (!ints[0] && !*s) {
pr_notice("Disabled\n");
return 1;
}
switch (ints[0]) {
default:
pr_err("Too many arguments\n");
case 3:
shmem = ints[3];
case 2:
irq = ints[2];
case 1:
io = ints[1];
}
if (*s)
snprintf(device, sizeof(device), "%s", s);
return 1;
}
