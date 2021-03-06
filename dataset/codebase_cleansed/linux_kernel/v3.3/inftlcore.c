static void inftl_add_mtd(struct mtd_blktrans_ops *tr, struct mtd_info *mtd)
{
struct INFTLrecord *inftl;
unsigned long temp;
if (mtd->type != MTD_NANDFLASH || mtd->size > UINT_MAX)
return;
if (memcmp(mtd->name, "DiskOnChip", 10))
return;
if (!mtd->block_isbad) {
printk(KERN_ERR
"INFTL no longer supports the old DiskOnChip drivers loaded via docprobe.\n"
"Please use the new diskonchip driver under the NAND subsystem.\n");
return;
}
pr_debug("INFTL: add_mtd for %s\n", mtd->name);
inftl = kzalloc(sizeof(*inftl), GFP_KERNEL);
if (!inftl)
return;
inftl->mbd.mtd = mtd;
inftl->mbd.devnum = -1;
inftl->mbd.tr = tr;
if (INFTL_mount(inftl) < 0) {
printk(KERN_WARNING "INFTL: could not mount device\n");
kfree(inftl);
return;
}
inftl->cylinders = 1024;
inftl->heads = 16;
temp = inftl->cylinders * inftl->heads;
inftl->sectors = inftl->mbd.size / temp;
if (inftl->mbd.size % temp) {
inftl->sectors++;
temp = inftl->cylinders * inftl->sectors;
inftl->heads = inftl->mbd.size / temp;
if (inftl->mbd.size % temp) {
inftl->heads++;
temp = inftl->heads * inftl->sectors;
inftl->cylinders = inftl->mbd.size / temp;
}
}
if (inftl->mbd.size != inftl->heads * inftl->cylinders * inftl->sectors) {
printk(KERN_WARNING "INFTL: cannot calculate a geometry to "
"match size of 0x%lx.\n", inftl->mbd.size);
printk(KERN_WARNING "INFTL: using C:%d H:%d S:%d "
"(== 0x%lx sects)\n",
inftl->cylinders, inftl->heads , inftl->sectors,
(long)inftl->cylinders * (long)inftl->heads *
(long)inftl->sectors );
}
if (add_mtd_blktrans_dev(&inftl->mbd)) {
kfree(inftl->PUtable);
kfree(inftl->VUtable);
kfree(inftl);
return;
}
#ifdef PSYCHO_DEBUG
printk(KERN_INFO "INFTL: Found new inftl%c\n", inftl->mbd.devnum + 'a');
#endif
return;
}
static void inftl_remove_dev(struct mtd_blktrans_dev *dev)
{
struct INFTLrecord *inftl = (void *)dev;
pr_debug("INFTL: remove_dev (i=%d)\n", dev->devnum);
del_mtd_blktrans_dev(dev);
kfree(inftl->PUtable);
kfree(inftl->VUtable);
}
int inftl_read_oob(struct mtd_info *mtd, loff_t offs, size_t len,
size_t *retlen, uint8_t *buf)
{
struct mtd_oob_ops ops;
int res;
ops.mode = MTD_OPS_PLACE_OOB;
ops.ooboffs = offs & (mtd->writesize - 1);
ops.ooblen = len;
ops.oobbuf = buf;
ops.datbuf = NULL;
res = mtd_read_oob(mtd, offs & ~(mtd->writesize - 1), &ops);
*retlen = ops.oobretlen;
return res;
}
int inftl_write_oob(struct mtd_info *mtd, loff_t offs, size_t len,
size_t *retlen, uint8_t *buf)
{
struct mtd_oob_ops ops;
int res;
ops.mode = MTD_OPS_PLACE_OOB;
ops.ooboffs = offs & (mtd->writesize - 1);
ops.ooblen = len;
ops.oobbuf = buf;
ops.datbuf = NULL;
res = mtd_write_oob(mtd, offs & ~(mtd->writesize - 1), &ops);
*retlen = ops.oobretlen;
return res;
}
static int inftl_write(struct mtd_info *mtd, loff_t offs, size_t len,
size_t *retlen, uint8_t *buf, uint8_t *oob)
{
struct mtd_oob_ops ops;
int res;
ops.mode = MTD_OPS_PLACE_OOB;
ops.ooboffs = offs;
ops.ooblen = mtd->oobsize;
ops.oobbuf = oob;
ops.datbuf = buf;
ops.len = len;
res = mtd_write_oob(mtd, offs & ~(mtd->writesize - 1), &ops);
*retlen = ops.retlen;
return res;
}
static u16 INFTL_findfreeblock(struct INFTLrecord *inftl, int desperate)
{
u16 pot = inftl->LastFreeEUN;
int silly = inftl->nb_blocks;
pr_debug("INFTL: INFTL_findfreeblock(inftl=%p,desperate=%d)\n",
inftl, desperate);
if (!desperate && inftl->numfreeEUNs < 2) {
pr_debug("INFTL: there are too few free EUNs (%d)\n",
inftl->numfreeEUNs);
return BLOCK_NIL;
}
do {
if (inftl->PUtable[pot] == BLOCK_FREE) {
inftl->LastFreeEUN = pot;
return pot;
}
if (++pot > inftl->lastEUN)
pot = 0;
if (!silly--) {
printk(KERN_WARNING "INFTL: no free blocks found! "
"EUN range = %d - %d\n", 0, inftl->LastFreeEUN);
return BLOCK_NIL;
}
} while (pot != inftl->LastFreeEUN);
return BLOCK_NIL;
}
static u16 INFTL_foldchain(struct INFTLrecord *inftl, unsigned thisVUC, unsigned pendingblock)
{
u16 BlockMap[MAX_SECTORS_PER_UNIT];
unsigned char BlockDeleted[MAX_SECTORS_PER_UNIT];
unsigned int thisEUN, prevEUN, status;
struct mtd_info *mtd = inftl->mbd.mtd;
int block, silly;
unsigned int targetEUN;
struct inftl_oob oob;
size_t retlen;
pr_debug("INFTL: INFTL_foldchain(inftl=%p,thisVUC=%d,pending=%d)\n",
inftl, thisVUC, pendingblock);
memset(BlockMap, 0xff, sizeof(BlockMap));
memset(BlockDeleted, 0, sizeof(BlockDeleted));
thisEUN = targetEUN = inftl->VUtable[thisVUC];
if (thisEUN == BLOCK_NIL) {
printk(KERN_WARNING "INFTL: trying to fold non-existent "
"Virtual Unit Chain %d!\n", thisVUC);
return BLOCK_NIL;
}
silly = MAX_LOOPS;
while (thisEUN < inftl->nb_blocks) {
for (block = 0; block < inftl->EraseSize/SECTORSIZE; block ++) {
if ((BlockMap[block] != BLOCK_NIL) ||
BlockDeleted[block])
continue;
if (inftl_read_oob(mtd, (thisEUN * inftl->EraseSize)
+ (block * SECTORSIZE), 16, &retlen,
(char *)&oob) < 0)
status = SECTOR_IGNORE;
else
status = oob.b.Status | oob.b.Status1;
switch(status) {
case SECTOR_FREE:
case SECTOR_IGNORE:
break;
case SECTOR_USED:
BlockMap[block] = thisEUN;
continue;
case SECTOR_DELETED:
BlockDeleted[block] = 1;
continue;
default:
printk(KERN_WARNING "INFTL: unknown status "
"for block %d in EUN %d: %x\n",
block, thisEUN, status);
break;
}
}
if (!silly--) {
printk(KERN_WARNING "INFTL: infinite loop in Virtual "
"Unit Chain 0x%x\n", thisVUC);
return BLOCK_NIL;
}
thisEUN = inftl->PUtable[thisEUN];
}
pr_debug("INFTL: folding chain %d into unit %d\n", thisVUC, targetEUN);
for (block = 0; block < inftl->EraseSize/SECTORSIZE ; block++) {
unsigned char movebuf[SECTORSIZE];
int ret;
if (BlockMap[block] == targetEUN || (pendingblock ==
(thisVUC * (inftl->EraseSize / SECTORSIZE) + block))) {
continue;
}
if (BlockMap[block] == BLOCK_NIL)
continue;
ret = mtd_read(mtd,
(inftl->EraseSize * BlockMap[block]) + (block * SECTORSIZE),
SECTORSIZE,
&retlen,
movebuf);
if (ret < 0 && !mtd_is_bitflip(ret)) {
ret = mtd_read(mtd,
(inftl->EraseSize * BlockMap[block]) + (block * SECTORSIZE),
SECTORSIZE,
&retlen,
movebuf);
if (ret != -EIO)
pr_debug("INFTL: error went away on retry?\n");
}
memset(&oob, 0xff, sizeof(struct inftl_oob));
oob.b.Status = oob.b.Status1 = SECTOR_USED;
inftl_write(inftl->mbd.mtd, (inftl->EraseSize * targetEUN) +
(block * SECTORSIZE), SECTORSIZE, &retlen,
movebuf, (char *)&oob);
}
pr_debug("INFTL: want to erase virtual chain %d\n", thisVUC);
for (;;) {
thisEUN = inftl->VUtable[thisVUC];
prevEUN = BLOCK_NIL;
while (inftl->PUtable[thisEUN] != BLOCK_NIL) {
prevEUN = thisEUN;
thisEUN = inftl->PUtable[thisEUN];
}
if (thisEUN == targetEUN)
break;
inftl->PUtable[prevEUN] = BLOCK_NIL;
if (INFTL_formatblock(inftl, thisEUN) < 0) {
inftl->PUtable[thisEUN] = BLOCK_RESERVED;
} else {
inftl->PUtable[thisEUN] = BLOCK_FREE;
inftl->numfreeEUNs++;
}
}
return targetEUN;
}
static u16 INFTL_makefreeblock(struct INFTLrecord *inftl, unsigned pendingblock)
{
u16 LongestChain = 0;
u16 ChainLength = 0, thislen;
u16 chain, EUN;
pr_debug("INFTL: INFTL_makefreeblock(inftl=%p,"
"pending=%d)\n", inftl, pendingblock);
for (chain = 0; chain < inftl->nb_blocks; chain++) {
EUN = inftl->VUtable[chain];
thislen = 0;
while (EUN <= inftl->lastEUN) {
thislen++;
EUN = inftl->PUtable[EUN];
if (thislen > 0xff00) {
printk(KERN_WARNING "INFTL: endless loop in "
"Virtual Chain %d: Unit %x\n",
chain, EUN);
thislen = 0;
break;
}
}
if (thislen > ChainLength) {
ChainLength = thislen;
LongestChain = chain;
}
}
if (ChainLength < 2) {
printk(KERN_WARNING "INFTL: no Virtual Unit Chains available "
"for folding. Failing request\n");
return BLOCK_NIL;
}
return INFTL_foldchain(inftl, LongestChain, pendingblock);
}
static int nrbits(unsigned int val, int bitcount)
{
int i, total = 0;
for (i = 0; (i < bitcount); i++)
total += (((0x1 << i) & val) ? 1 : 0);
return total;
}
static inline u16 INFTL_findwriteunit(struct INFTLrecord *inftl, unsigned block)
{
unsigned int thisVUC = block / (inftl->EraseSize / SECTORSIZE);
unsigned int thisEUN, writeEUN, prev_block, status;
unsigned long blockofs = (block * SECTORSIZE) & (inftl->EraseSize -1);
struct mtd_info *mtd = inftl->mbd.mtd;
struct inftl_oob oob;
struct inftl_bci bci;
unsigned char anac, nacs, parity;
size_t retlen;
int silly, silly2 = 3;
pr_debug("INFTL: INFTL_findwriteunit(inftl=%p,block=%d)\n",
inftl, block);
do {
writeEUN = BLOCK_NIL;
thisEUN = inftl->VUtable[thisVUC];
silly = MAX_LOOPS;
while (thisEUN <= inftl->lastEUN) {
inftl_read_oob(mtd, (thisEUN * inftl->EraseSize) +
blockofs, 8, &retlen, (char *)&bci);
status = bci.Status | bci.Status1;
pr_debug("INFTL: status of block %d in EUN %d is %x\n",
block , writeEUN, status);
switch(status) {
case SECTOR_FREE:
writeEUN = thisEUN;
break;
case SECTOR_DELETED:
case SECTOR_USED:
goto hitused;
case SECTOR_IGNORE:
break;
default:
break;
}
if (!silly--) {
printk(KERN_WARNING "INFTL: infinite loop in "
"Virtual Unit Chain 0x%x\n", thisVUC);
return BLOCK_NIL;
}
thisEUN = inftl->PUtable[thisEUN];
}
hitused:
if (writeEUN != BLOCK_NIL)
return writeEUN;
writeEUN = INFTL_findfreeblock(inftl, 0);
if (writeEUN == BLOCK_NIL) {
thisEUN = INFTL_makefreeblock(inftl, block);
pr_debug("INFTL: using desperate==1 to find free EUN "
"to accommodate write to VUC %d\n",
thisVUC);
writeEUN = INFTL_findfreeblock(inftl, 1);
if (writeEUN == BLOCK_NIL) {
printk(KERN_WARNING "INFTL: cannot make free "
"space.\n");
#ifdef DEBUG
INFTL_dumptables(inftl);
INFTL_dumpVUchains(inftl);
#endif
return BLOCK_NIL;
}
}
anac = 0;
nacs = 0;
thisEUN = inftl->VUtable[thisVUC];
if (thisEUN != BLOCK_NIL) {
inftl_read_oob(mtd, thisEUN * inftl->EraseSize
+ 8, 8, &retlen, (char *)&oob.u);
anac = oob.u.a.ANAC + 1;
nacs = oob.u.a.NACs + 1;
}
prev_block = inftl->VUtable[thisVUC];
if (prev_block < inftl->nb_blocks)
prev_block -= inftl->firstEUN;
parity = (nrbits(thisVUC, 16) & 0x1) ? 0x1 : 0;
parity |= (nrbits(prev_block, 16) & 0x1) ? 0x2 : 0;
parity |= (nrbits(anac, 8) & 0x1) ? 0x4 : 0;
parity |= (nrbits(nacs, 8) & 0x1) ? 0x8 : 0;
oob.u.a.virtualUnitNo = cpu_to_le16(thisVUC);
oob.u.a.prevUnitNo = cpu_to_le16(prev_block);
oob.u.a.ANAC = anac;
oob.u.a.NACs = nacs;
oob.u.a.parityPerField = parity;
oob.u.a.discarded = 0xaa;
inftl_write_oob(mtd, writeEUN * inftl->EraseSize + 8, 8,
&retlen, (char *)&oob.u);
oob.u.b.virtualUnitNo = cpu_to_le16(thisVUC);
oob.u.b.prevUnitNo = cpu_to_le16(prev_block);
oob.u.b.ANAC = anac;
oob.u.b.NACs = nacs;
oob.u.b.parityPerField = parity;
oob.u.b.discarded = 0xaa;
inftl_write_oob(mtd, writeEUN * inftl->EraseSize +
SECTORSIZE * 4 + 8, 8, &retlen, (char *)&oob.u);
inftl->PUtable[writeEUN] = inftl->VUtable[thisVUC];
inftl->VUtable[thisVUC] = writeEUN;
inftl->numfreeEUNs--;
return writeEUN;
} while (silly2--);
printk(KERN_WARNING "INFTL: error folding to make room for Virtual "
"Unit Chain 0x%x\n", thisVUC);
return BLOCK_NIL;
}
static void INFTL_trydeletechain(struct INFTLrecord *inftl, unsigned thisVUC)
{
struct mtd_info *mtd = inftl->mbd.mtd;
unsigned char BlockUsed[MAX_SECTORS_PER_UNIT];
unsigned char BlockDeleted[MAX_SECTORS_PER_UNIT];
unsigned int thisEUN, status;
int block, silly;
struct inftl_bci bci;
size_t retlen;
pr_debug("INFTL: INFTL_trydeletechain(inftl=%p,"
"thisVUC=%d)\n", inftl, thisVUC);
memset(BlockUsed, 0, sizeof(BlockUsed));
memset(BlockDeleted, 0, sizeof(BlockDeleted));
thisEUN = inftl->VUtable[thisVUC];
if (thisEUN == BLOCK_NIL) {
printk(KERN_WARNING "INFTL: trying to delete non-existent "
"Virtual Unit Chain %d!\n", thisVUC);
return;
}
silly = MAX_LOOPS;
while (thisEUN < inftl->nb_blocks) {
for (block = 0; block < inftl->EraseSize/SECTORSIZE; block++) {
if (BlockUsed[block] || BlockDeleted[block])
continue;
if (inftl_read_oob(mtd, (thisEUN * inftl->EraseSize)
+ (block * SECTORSIZE), 8 , &retlen,
(char *)&bci) < 0)
status = SECTOR_IGNORE;
else
status = bci.Status | bci.Status1;
switch(status) {
case SECTOR_FREE:
case SECTOR_IGNORE:
break;
case SECTOR_USED:
BlockUsed[block] = 1;
continue;
case SECTOR_DELETED:
BlockDeleted[block] = 1;
continue;
default:
printk(KERN_WARNING "INFTL: unknown status "
"for block %d in EUN %d: 0x%x\n",
block, thisEUN, status);
}
}
if (!silly--) {
printk(KERN_WARNING "INFTL: infinite loop in Virtual "
"Unit Chain 0x%x\n", thisVUC);
return;
}
thisEUN = inftl->PUtable[thisEUN];
}
for (block = 0; block < inftl->EraseSize/SECTORSIZE; block++)
if (BlockUsed[block])
return;
pr_debug("INFTL: deleting empty VUC %d\n", thisVUC);
for (;;) {
u16 *prevEUN = &inftl->VUtable[thisVUC];
thisEUN = *prevEUN;
if (thisEUN == BLOCK_NIL) {
pr_debug("INFTL: Empty VUC %d for deletion was already absent\n", thisEUN);
return;
}
while (inftl->PUtable[thisEUN] != BLOCK_NIL) {
BUG_ON(thisEUN >= inftl->nb_blocks);
prevEUN = &inftl->PUtable[thisEUN];
thisEUN = *prevEUN;
}
pr_debug("Deleting EUN %d from VUC %d\n",
thisEUN, thisVUC);
if (INFTL_formatblock(inftl, thisEUN) < 0) {
inftl->PUtable[thisEUN] = BLOCK_RESERVED;
} else {
inftl->PUtable[thisEUN] = BLOCK_FREE;
inftl->numfreeEUNs++;
}
*prevEUN = BLOCK_NIL;
cond_resched();
}
inftl->VUtable[thisVUC] = BLOCK_NIL;
}
static int INFTL_deleteblock(struct INFTLrecord *inftl, unsigned block)
{
unsigned int thisEUN = inftl->VUtable[block / (inftl->EraseSize / SECTORSIZE)];
unsigned long blockofs = (block * SECTORSIZE) & (inftl->EraseSize - 1);
struct mtd_info *mtd = inftl->mbd.mtd;
unsigned int status;
int silly = MAX_LOOPS;
size_t retlen;
struct inftl_bci bci;
pr_debug("INFTL: INFTL_deleteblock(inftl=%p,"
"block=%d)\n", inftl, block);
while (thisEUN < inftl->nb_blocks) {
if (inftl_read_oob(mtd, (thisEUN * inftl->EraseSize) +
blockofs, 8, &retlen, (char *)&bci) < 0)
status = SECTOR_IGNORE;
else
status = bci.Status | bci.Status1;
switch (status) {
case SECTOR_FREE:
case SECTOR_IGNORE:
break;
case SECTOR_DELETED:
thisEUN = BLOCK_NIL;
goto foundit;
case SECTOR_USED:
goto foundit;
default:
printk(KERN_WARNING "INFTL: unknown status for "
"block %d in EUN %d: 0x%x\n",
block, thisEUN, status);
break;
}
if (!silly--) {
printk(KERN_WARNING "INFTL: infinite loop in Virtual "
"Unit Chain 0x%x\n",
block / (inftl->EraseSize / SECTORSIZE));
return 1;
}
thisEUN = inftl->PUtable[thisEUN];
}
foundit:
if (thisEUN != BLOCK_NIL) {
loff_t ptr = (thisEUN * inftl->EraseSize) + blockofs;
if (inftl_read_oob(mtd, ptr, 8, &retlen, (char *)&bci) < 0)
return -EIO;
bci.Status = bci.Status1 = SECTOR_DELETED;
if (inftl_write_oob(mtd, ptr, 8, &retlen, (char *)&bci) < 0)
return -EIO;
INFTL_trydeletechain(inftl, block / (inftl->EraseSize / SECTORSIZE));
}
return 0;
}
static int inftl_writeblock(struct mtd_blktrans_dev *mbd, unsigned long block,
char *buffer)
{
struct INFTLrecord *inftl = (void *)mbd;
unsigned int writeEUN;
unsigned long blockofs = (block * SECTORSIZE) & (inftl->EraseSize - 1);
size_t retlen;
struct inftl_oob oob;
char *p, *pend;
pr_debug("INFTL: inftl_writeblock(inftl=%p,block=%ld,"
"buffer=%p)\n", inftl, block, buffer);
pend = buffer + SECTORSIZE;
for (p = buffer; p < pend && !*p; p++)
;
if (p < pend) {
writeEUN = INFTL_findwriteunit(inftl, block);
if (writeEUN == BLOCK_NIL) {
printk(KERN_WARNING "inftl_writeblock(): cannot find "
"block to write to\n");
return 1;
}
memset(&oob, 0xff, sizeof(struct inftl_oob));
oob.b.Status = oob.b.Status1 = SECTOR_USED;
inftl_write(inftl->mbd.mtd, (writeEUN * inftl->EraseSize) +
blockofs, SECTORSIZE, &retlen, (char *)buffer,
(char *)&oob);
} else {
INFTL_deleteblock(inftl, block);
}
return 0;
}
static int inftl_readblock(struct mtd_blktrans_dev *mbd, unsigned long block,
char *buffer)
{
struct INFTLrecord *inftl = (void *)mbd;
unsigned int thisEUN = inftl->VUtable[block / (inftl->EraseSize / SECTORSIZE)];
unsigned long blockofs = (block * SECTORSIZE) & (inftl->EraseSize - 1);
struct mtd_info *mtd = inftl->mbd.mtd;
unsigned int status;
int silly = MAX_LOOPS;
struct inftl_bci bci;
size_t retlen;
pr_debug("INFTL: inftl_readblock(inftl=%p,block=%ld,"
"buffer=%p)\n", inftl, block, buffer);
while (thisEUN < inftl->nb_blocks) {
if (inftl_read_oob(mtd, (thisEUN * inftl->EraseSize) +
blockofs, 8, &retlen, (char *)&bci) < 0)
status = SECTOR_IGNORE;
else
status = bci.Status | bci.Status1;
switch (status) {
case SECTOR_DELETED:
thisEUN = BLOCK_NIL;
goto foundit;
case SECTOR_USED:
goto foundit;
case SECTOR_FREE:
case SECTOR_IGNORE:
break;
default:
printk(KERN_WARNING "INFTL: unknown status for "
"block %ld in EUN %d: 0x%04x\n",
block, thisEUN, status);
break;
}
if (!silly--) {
printk(KERN_WARNING "INFTL: infinite loop in "
"Virtual Unit Chain 0x%lx\n",
block / (inftl->EraseSize / SECTORSIZE));
return 1;
}
thisEUN = inftl->PUtable[thisEUN];
}
foundit:
if (thisEUN == BLOCK_NIL) {
memset(buffer, 0, SECTORSIZE);
} else {
size_t retlen;
loff_t ptr = (thisEUN * inftl->EraseSize) + blockofs;
int ret = mtd_read(mtd, ptr, SECTORSIZE, &retlen, buffer);
if (ret < 0 && !mtd_is_bitflip(ret))
return -EIO;
}
return 0;
}
static int inftl_getgeo(struct mtd_blktrans_dev *dev, struct hd_geometry *geo)
{
struct INFTLrecord *inftl = (void *)dev;
geo->heads = inftl->heads;
geo->sectors = inftl->sectors;
geo->cylinders = inftl->cylinders;
return 0;
}
static int __init init_inftl(void)
{
return register_mtd_blktrans(&inftl_tr);
}
static void __exit cleanup_inftl(void)
{
deregister_mtd_blktrans(&inftl_tr);
}
