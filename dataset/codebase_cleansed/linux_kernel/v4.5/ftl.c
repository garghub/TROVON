static int scan_header(partition_t *part)
{
erase_unit_header_t header;
loff_t offset, max_offset;
size_t ret;
int err;
part->header.FormattedSize = 0;
max_offset = (0x100000<part->mbd.mtd->size)?0x100000:part->mbd.mtd->size;
for (offset = 0;
(offset + sizeof(header)) < max_offset;
offset += part->mbd.mtd->erasesize ? : 0x2000) {
err = mtd_read(part->mbd.mtd, offset, sizeof(header), &ret,
(unsigned char *)&header);
if (err)
return err;
if (strcmp(header.DataOrgTuple+3, "FTL100") == 0) break;
}
if (offset == max_offset) {
printk(KERN_NOTICE "ftl_cs: FTL header not found.\n");
return -ENOENT;
}
if (header.BlockSize != 9 ||
(header.EraseUnitSize < 10) || (header.EraseUnitSize > 31) ||
(header.NumTransferUnits >= le16_to_cpu(header.NumEraseUnits))) {
printk(KERN_NOTICE "ftl_cs: FTL header corrupt!\n");
return -1;
}
if ((1 << header.EraseUnitSize) != part->mbd.mtd->erasesize) {
printk(KERN_NOTICE "ftl: FTL EraseUnitSize %x != MTD erasesize %x\n",
1 << header.EraseUnitSize,part->mbd.mtd->erasesize);
return -1;
}
part->header = header;
return 0;
}
static int build_maps(partition_t *part)
{
erase_unit_header_t header;
uint16_t xvalid, xtrans, i;
unsigned blocks, j;
int hdr_ok, ret = -1;
ssize_t retval;
loff_t offset;
part->DataUnits = le16_to_cpu(part->header.NumEraseUnits) -
part->header.NumTransferUnits;
part->EUNInfo = kmalloc(part->DataUnits * sizeof(struct eun_info_t),
GFP_KERNEL);
if (!part->EUNInfo)
goto out;
for (i = 0; i < part->DataUnits; i++)
part->EUNInfo[i].Offset = 0xffffffff;
part->XferInfo =
kmalloc(part->header.NumTransferUnits * sizeof(struct xfer_info_t),
GFP_KERNEL);
if (!part->XferInfo)
goto out_EUNInfo;
xvalid = xtrans = 0;
for (i = 0; i < le16_to_cpu(part->header.NumEraseUnits); i++) {
offset = ((i + le16_to_cpu(part->header.FirstPhysicalEUN))
<< part->header.EraseUnitSize);
ret = mtd_read(part->mbd.mtd, offset, sizeof(header), &retval,
(unsigned char *)&header);
if (ret)
goto out_XferInfo;
ret = -1;
hdr_ok = (strcmp(header.DataOrgTuple+3, "FTL100") == 0);
if (hdr_ok && (le16_to_cpu(header.LogicalEUN) < part->DataUnits) &&
(part->EUNInfo[le16_to_cpu(header.LogicalEUN)].Offset == 0xffffffff)) {
part->EUNInfo[le16_to_cpu(header.LogicalEUN)].Offset = offset;
part->EUNInfo[le16_to_cpu(header.LogicalEUN)].EraseCount =
le32_to_cpu(header.EraseCount);
xvalid++;
} else {
if (xtrans == part->header.NumTransferUnits) {
printk(KERN_NOTICE "ftl_cs: format error: too many "
"transfer units!\n");
goto out_XferInfo;
}
if (hdr_ok && (le16_to_cpu(header.LogicalEUN) == 0xffff)) {
part->XferInfo[xtrans].state = XFER_PREPARED;
part->XferInfo[xtrans].EraseCount = le32_to_cpu(header.EraseCount);
} else {
part->XferInfo[xtrans].state = XFER_UNKNOWN;
part->XferInfo[xtrans].EraseCount =
le32_to_cpu(part->header.EraseCount);
}
part->XferInfo[xtrans].Offset = offset;
xtrans++;
}
}
header = part->header;
if ((xtrans != header.NumTransferUnits) ||
(xvalid+xtrans != le16_to_cpu(header.NumEraseUnits))) {
printk(KERN_NOTICE "ftl_cs: format error: erase units "
"don't add up!\n");
goto out_XferInfo;
}
blocks = le32_to_cpu(header.FormattedSize) >> header.BlockSize;
part->VirtualBlockMap = vmalloc(blocks * sizeof(uint32_t));
if (!part->VirtualBlockMap)
goto out_XferInfo;
memset(part->VirtualBlockMap, 0xff, blocks * sizeof(uint32_t));
part->BlocksPerUnit = (1 << header.EraseUnitSize) >> header.BlockSize;
part->bam_cache = kmalloc(part->BlocksPerUnit * sizeof(uint32_t),
GFP_KERNEL);
if (!part->bam_cache)
goto out_VirtualBlockMap;
part->bam_index = 0xffff;
part->FreeTotal = 0;
for (i = 0; i < part->DataUnits; i++) {
part->EUNInfo[i].Free = 0;
part->EUNInfo[i].Deleted = 0;
offset = part->EUNInfo[i].Offset + le32_to_cpu(header.BAMOffset);
ret = mtd_read(part->mbd.mtd, offset,
part->BlocksPerUnit * sizeof(uint32_t), &retval,
(unsigned char *)part->bam_cache);
if (ret)
goto out_bam_cache;
for (j = 0; j < part->BlocksPerUnit; j++) {
if (BLOCK_FREE(le32_to_cpu(part->bam_cache[j]))) {
part->EUNInfo[i].Free++;
part->FreeTotal++;
} else if ((BLOCK_TYPE(le32_to_cpu(part->bam_cache[j])) == BLOCK_DATA) &&
(BLOCK_NUMBER(le32_to_cpu(part->bam_cache[j])) < blocks))
part->VirtualBlockMap[BLOCK_NUMBER(le32_to_cpu(part->bam_cache[j]))] =
(i << header.EraseUnitSize) + (j << header.BlockSize);
else if (BLOCK_DELETED(le32_to_cpu(part->bam_cache[j])))
part->EUNInfo[i].Deleted++;
}
}
ret = 0;
goto out;
out_bam_cache:
kfree(part->bam_cache);
out_VirtualBlockMap:
vfree(part->VirtualBlockMap);
out_XferInfo:
kfree(part->XferInfo);
out_EUNInfo:
kfree(part->EUNInfo);
out:
return ret;
}
static int erase_xfer(partition_t *part,
uint16_t xfernum)
{
int ret;
struct xfer_info_t *xfer;
struct erase_info *erase;
xfer = &part->XferInfo[xfernum];
pr_debug("ftl_cs: erasing xfer unit at 0x%x\n", xfer->Offset);
xfer->state = XFER_ERASING;
erase=kmalloc(sizeof(struct erase_info), GFP_KERNEL);
if (!erase)
return -ENOMEM;
erase->mtd = part->mbd.mtd;
erase->callback = ftl_erase_callback;
erase->addr = xfer->Offset;
erase->len = 1 << part->header.EraseUnitSize;
erase->priv = (u_long)part;
ret = mtd_erase(part->mbd.mtd, erase);
if (!ret)
xfer->EraseCount++;
else
kfree(erase);
return ret;
}
static void ftl_erase_callback(struct erase_info *erase)
{
partition_t *part;
struct xfer_info_t *xfer;
int i;
part = (partition_t *)(erase->priv);
for (i = 0; i < part->header.NumTransferUnits; i++)
if (part->XferInfo[i].Offset == erase->addr) break;
if (i == part->header.NumTransferUnits) {
printk(KERN_NOTICE "ftl_cs: internal error: "
"erase lookup failed!\n");
return;
}
xfer = &part->XferInfo[i];
if (erase->state == MTD_ERASE_DONE)
xfer->state = XFER_ERASED;
else {
xfer->state = XFER_FAILED;
printk(KERN_NOTICE "ftl_cs: erase failed: state = %d\n",
erase->state);
}
kfree(erase);
}
static int prepare_xfer(partition_t *part, int i)
{
erase_unit_header_t header;
struct xfer_info_t *xfer;
int nbam, ret;
uint32_t ctl;
ssize_t retlen;
loff_t offset;
xfer = &part->XferInfo[i];
xfer->state = XFER_FAILED;
pr_debug("ftl_cs: preparing xfer unit at 0x%x\n", xfer->Offset);
header = part->header;
header.LogicalEUN = cpu_to_le16(0xffff);
header.EraseCount = cpu_to_le32(xfer->EraseCount);
ret = mtd_write(part->mbd.mtd, xfer->Offset, sizeof(header), &retlen,
(u_char *)&header);
if (ret) {
return ret;
}
nbam = (part->BlocksPerUnit * sizeof(uint32_t) +
le32_to_cpu(part->header.BAMOffset) + SECTOR_SIZE - 1) / SECTOR_SIZE;
offset = xfer->Offset + le32_to_cpu(part->header.BAMOffset);
ctl = cpu_to_le32(BLOCK_CONTROL);
for (i = 0; i < nbam; i++, offset += sizeof(uint32_t)) {
ret = mtd_write(part->mbd.mtd, offset, sizeof(uint32_t), &retlen,
(u_char *)&ctl);
if (ret)
return ret;
}
xfer->state = XFER_PREPARED;
return 0;
}
static int copy_erase_unit(partition_t *part, uint16_t srcunit,
uint16_t xferunit)
{
u_char buf[SECTOR_SIZE];
struct eun_info_t *eun;
struct xfer_info_t *xfer;
uint32_t src, dest, free, i;
uint16_t unit;
int ret;
ssize_t retlen;
loff_t offset;
uint16_t srcunitswap = cpu_to_le16(srcunit);
eun = &part->EUNInfo[srcunit];
xfer = &part->XferInfo[xferunit];
pr_debug("ftl_cs: copying block 0x%x to 0x%x\n",
eun->Offset, xfer->Offset);
if (part->bam_index != srcunit) {
offset = eun->Offset + le32_to_cpu(part->header.BAMOffset);
ret = mtd_read(part->mbd.mtd, offset,
part->BlocksPerUnit * sizeof(uint32_t), &retlen,
(u_char *)(part->bam_cache));
part->bam_index = 0xffff;
if (ret) {
printk( KERN_WARNING "ftl: Failed to read BAM cache in copy_erase_unit()!\n");
return ret;
}
}
xfer->state = XFER_UNKNOWN;
offset = xfer->Offset + 20;
unit = cpu_to_le16(0x7fff);
ret = mtd_write(part->mbd.mtd, offset, sizeof(uint16_t), &retlen,
(u_char *)&unit);
if (ret) {
printk( KERN_WARNING "ftl: Failed to write back to BAM cache in copy_erase_unit()!\n");
return ret;
}
src = eun->Offset; dest = xfer->Offset;
free = 0;
ret = 0;
for (i = 0; i < part->BlocksPerUnit; i++) {
switch (BLOCK_TYPE(le32_to_cpu(part->bam_cache[i]))) {
case BLOCK_CONTROL:
break;
case BLOCK_DATA:
case BLOCK_REPLACEMENT:
ret = mtd_read(part->mbd.mtd, src, SECTOR_SIZE, &retlen,
(u_char *)buf);
if (ret) {
printk(KERN_WARNING "ftl: Error reading old xfer unit in copy_erase_unit\n");
return ret;
}
ret = mtd_write(part->mbd.mtd, dest, SECTOR_SIZE, &retlen,
(u_char *)buf);
if (ret) {
printk(KERN_WARNING "ftl: Error writing new xfer unit in copy_erase_unit\n");
return ret;
}
break;
default:
part->bam_cache[i] = cpu_to_le32(0xffffffff);
free++;
break;
}
src += SECTOR_SIZE;
dest += SECTOR_SIZE;
}
ret = mtd_write(part->mbd.mtd,
xfer->Offset + le32_to_cpu(part->header.BAMOffset),
part->BlocksPerUnit * sizeof(int32_t),
&retlen,
(u_char *)part->bam_cache);
if (ret) {
printk( KERN_WARNING "ftl: Error writing BAM in copy_erase_unit\n");
return ret;
}
ret = mtd_write(part->mbd.mtd, xfer->Offset + 20, sizeof(uint16_t),
&retlen, (u_char *)&srcunitswap);
if (ret) {
printk(KERN_WARNING "ftl: Error writing new LogicalEUN in copy_erase_unit\n");
return ret;
}
swap(xfer->EraseCount, eun->EraseCount);
swap(xfer->Offset, eun->Offset);
part->FreeTotal -= eun->Free;
part->FreeTotal += free;
eun->Free = free;
eun->Deleted = 0;
part->bam_index = srcunit;
return 0;
}
static int reclaim_block(partition_t *part)
{
uint16_t i, eun, xfer;
uint32_t best;
int queued, ret;
pr_debug("ftl_cs: reclaiming space...\n");
pr_debug("NumTransferUnits == %x\n", part->header.NumTransferUnits);
best = 0xffffffff; xfer = 0xffff;
do {
queued = 0;
for (i = 0; i < part->header.NumTransferUnits; i++) {
int n=0;
if (part->XferInfo[i].state == XFER_UNKNOWN) {
pr_debug("XferInfo[%d].state == XFER_UNKNOWN\n",i);
n=1;
erase_xfer(part, i);
}
if (part->XferInfo[i].state == XFER_ERASING) {
pr_debug("XferInfo[%d].state == XFER_ERASING\n",i);
n=1;
queued = 1;
}
else if (part->XferInfo[i].state == XFER_ERASED) {
pr_debug("XferInfo[%d].state == XFER_ERASED\n",i);
n=1;
prepare_xfer(part, i);
}
if (part->XferInfo[i].state == XFER_PREPARED) {
pr_debug("XferInfo[%d].state == XFER_PREPARED\n",i);
n=1;
if (part->XferInfo[i].EraseCount <= best) {
best = part->XferInfo[i].EraseCount;
xfer = i;
}
}
if (!n)
pr_debug("XferInfo[%d].state == %x\n",i, part->XferInfo[i].state);
}
if (xfer == 0xffff) {
if (queued) {
pr_debug("ftl_cs: waiting for transfer "
"unit to be prepared...\n");
mtd_sync(part->mbd.mtd);
} else {
static int ne = 0;
if (++ne < 5)
printk(KERN_NOTICE "ftl_cs: reclaim failed: no "
"suitable transfer units!\n");
else
pr_debug("ftl_cs: reclaim failed: no "
"suitable transfer units!\n");
return -EIO;
}
}
} while (xfer == 0xffff);
eun = 0;
if ((jiffies % shuffle_freq) == 0) {
pr_debug("ftl_cs: recycling freshest block...\n");
best = 0xffffffff;
for (i = 0; i < part->DataUnits; i++)
if (part->EUNInfo[i].EraseCount <= best) {
best = part->EUNInfo[i].EraseCount;
eun = i;
}
} else {
best = 0;
for (i = 0; i < part->DataUnits; i++)
if (part->EUNInfo[i].Deleted >= best) {
best = part->EUNInfo[i].Deleted;
eun = i;
}
if (best == 0) {
static int ne = 0;
if (++ne < 5)
printk(KERN_NOTICE "ftl_cs: reclaim failed: "
"no free blocks!\n");
else
pr_debug("ftl_cs: reclaim failed: "
"no free blocks!\n");
return -EIO;
}
}
ret = copy_erase_unit(part, eun, xfer);
if (!ret)
erase_xfer(part, xfer);
else
printk(KERN_NOTICE "ftl_cs: copy_erase_unit failed!\n");
return ret;
}
static void dump_lists(partition_t *part)
{
int i;
printk(KERN_DEBUG "ftl_cs: Free total = %d\n", part->FreeTotal);
for (i = 0; i < part->DataUnits; i++)
printk(KERN_DEBUG "ftl_cs: unit %d: %d phys, %d free, "
"%d deleted\n", i,
part->EUNInfo[i].Offset >> part->header.EraseUnitSize,
part->EUNInfo[i].Free, part->EUNInfo[i].Deleted);
}
static uint32_t find_free(partition_t *part)
{
uint16_t stop, eun;
uint32_t blk;
size_t retlen;
int ret;
stop = (part->bam_index == 0xffff) ? 0 : part->bam_index;
eun = stop;
do {
if (part->EUNInfo[eun].Free != 0) break;
if (++eun == part->DataUnits) eun = 0;
} while (eun != stop);
if (part->EUNInfo[eun].Free == 0)
return 0;
if (eun != part->bam_index) {
part->bam_index = 0xffff;
ret = mtd_read(part->mbd.mtd,
part->EUNInfo[eun].Offset + le32_to_cpu(part->header.BAMOffset),
part->BlocksPerUnit * sizeof(uint32_t),
&retlen,
(u_char *)(part->bam_cache));
if (ret) {
printk(KERN_WARNING"ftl: Error reading BAM in find_free\n");
return 0;
}
part->bam_index = eun;
}
for (blk = 0; blk < part->BlocksPerUnit; blk++)
if (BLOCK_FREE(le32_to_cpu(part->bam_cache[blk]))) break;
if (blk == part->BlocksPerUnit) {
#ifdef PSYCHO_DEBUG
static int ne = 0;
if (++ne == 1)
dump_lists(part);
#endif
printk(KERN_NOTICE "ftl_cs: bad free list!\n");
return 0;
}
pr_debug("ftl_cs: found free block at %d in %d\n", blk, eun);
return blk;
}
static int ftl_read(partition_t *part, caddr_t buffer,
u_long sector, u_long nblocks)
{
uint32_t log_addr, bsize;
u_long i;
int ret;
size_t offset, retlen;
pr_debug("ftl_cs: ftl_read(0x%p, 0x%lx, %ld)\n",
part, sector, nblocks);
if (!(part->state & FTL_FORMATTED)) {
printk(KERN_NOTICE "ftl_cs: bad partition\n");
return -EIO;
}
bsize = 1 << part->header.EraseUnitSize;
for (i = 0; i < nblocks; i++) {
if (((sector+i) * SECTOR_SIZE) >= le32_to_cpu(part->header.FormattedSize)) {
printk(KERN_NOTICE "ftl_cs: bad read offset\n");
return -EIO;
}
log_addr = part->VirtualBlockMap[sector+i];
if (log_addr == 0xffffffff)
memset(buffer, 0, SECTOR_SIZE);
else {
offset = (part->EUNInfo[log_addr / bsize].Offset
+ (log_addr % bsize));
ret = mtd_read(part->mbd.mtd, offset, SECTOR_SIZE, &retlen,
(u_char *)buffer);
if (ret) {
printk(KERN_WARNING "Error reading MTD device in ftl_read()\n");
return ret;
}
}
buffer += SECTOR_SIZE;
}
return 0;
}
static int set_bam_entry(partition_t *part, uint32_t log_addr,
uint32_t virt_addr)
{
uint32_t bsize, blk, le_virt_addr;
#ifdef PSYCHO_DEBUG
uint32_t old_addr;
#endif
uint16_t eun;
int ret;
size_t retlen, offset;
pr_debug("ftl_cs: set_bam_entry(0x%p, 0x%x, 0x%x)\n",
part, log_addr, virt_addr);
bsize = 1 << part->header.EraseUnitSize;
eun = log_addr / bsize;
blk = (log_addr % bsize) / SECTOR_SIZE;
offset = (part->EUNInfo[eun].Offset + blk * sizeof(uint32_t) +
le32_to_cpu(part->header.BAMOffset));
#ifdef PSYCHO_DEBUG
ret = mtd_read(part->mbd.mtd, offset, sizeof(uint32_t), &retlen,
(u_char *)&old_addr);
if (ret) {
printk(KERN_WARNING"ftl: Error reading old_addr in set_bam_entry: %d\n",ret);
return ret;
}
old_addr = le32_to_cpu(old_addr);
if (((virt_addr == 0xfffffffe) && !BLOCK_FREE(old_addr)) ||
((virt_addr == 0) && (BLOCK_TYPE(old_addr) != BLOCK_DATA)) ||
(!BLOCK_DELETED(virt_addr) && (old_addr != 0xfffffffe))) {
static int ne = 0;
if (++ne < 5) {
printk(KERN_NOTICE "ftl_cs: set_bam_entry() inconsistency!\n");
printk(KERN_NOTICE "ftl_cs: log_addr = 0x%x, old = 0x%x"
", new = 0x%x\n", log_addr, old_addr, virt_addr);
}
return -EIO;
}
#endif
le_virt_addr = cpu_to_le32(virt_addr);
if (part->bam_index == eun) {
#ifdef PSYCHO_DEBUG
if (le32_to_cpu(part->bam_cache[blk]) != old_addr) {
static int ne = 0;
if (++ne < 5) {
printk(KERN_NOTICE "ftl_cs: set_bam_entry() "
"inconsistency!\n");
printk(KERN_NOTICE "ftl_cs: log_addr = 0x%x, cache"
" = 0x%x\n",
le32_to_cpu(part->bam_cache[blk]), old_addr);
}
return -EIO;
}
#endif
part->bam_cache[blk] = le_virt_addr;
}
ret = mtd_write(part->mbd.mtd, offset, sizeof(uint32_t), &retlen,
(u_char *)&le_virt_addr);
if (ret) {
printk(KERN_NOTICE "ftl_cs: set_bam_entry() failed!\n");
printk(KERN_NOTICE "ftl_cs: log_addr = 0x%x, new = 0x%x\n",
log_addr, virt_addr);
}
return ret;
}
static int ftl_write(partition_t *part, caddr_t buffer,
u_long sector, u_long nblocks)
{
uint32_t bsize, log_addr, virt_addr, old_addr, blk;
u_long i;
int ret;
size_t retlen, offset;
pr_debug("ftl_cs: ftl_write(0x%p, %ld, %ld)\n",
part, sector, nblocks);
if (!(part->state & FTL_FORMATTED)) {
printk(KERN_NOTICE "ftl_cs: bad partition\n");
return -EIO;
}
while (part->FreeTotal < nblocks) {
ret = reclaim_block(part);
if (ret)
return ret;
}
bsize = 1 << part->header.EraseUnitSize;
virt_addr = sector * SECTOR_SIZE | BLOCK_DATA;
for (i = 0; i < nblocks; i++) {
if (virt_addr >= le32_to_cpu(part->header.FormattedSize)) {
printk(KERN_NOTICE "ftl_cs: bad write offset\n");
return -EIO;
}
blk = find_free(part);
if (blk == 0) {
static int ne = 0;
if (++ne < 5)
printk(KERN_NOTICE "ftl_cs: internal error: "
"no free blocks!\n");
return -ENOSPC;
}
log_addr = part->bam_index * bsize + blk * SECTOR_SIZE;
part->EUNInfo[part->bam_index].Free--;
part->FreeTotal--;
if (set_bam_entry(part, log_addr, 0xfffffffe))
return -EIO;
part->EUNInfo[part->bam_index].Deleted++;
offset = (part->EUNInfo[part->bam_index].Offset +
blk * SECTOR_SIZE);
ret = mtd_write(part->mbd.mtd, offset, SECTOR_SIZE, &retlen, buffer);
if (ret) {
printk(KERN_NOTICE "ftl_cs: block write failed!\n");
printk(KERN_NOTICE "ftl_cs: log_addr = 0x%x, virt_addr"
" = 0x%x, Offset = 0x%zx\n", log_addr, virt_addr,
offset);
return -EIO;
}
old_addr = part->VirtualBlockMap[sector+i];
if (old_addr != 0xffffffff) {
part->VirtualBlockMap[sector+i] = 0xffffffff;
part->EUNInfo[old_addr/bsize].Deleted++;
if (set_bam_entry(part, old_addr, 0))
return -EIO;
}
if (set_bam_entry(part, log_addr, virt_addr))
return -EIO;
part->VirtualBlockMap[sector+i] = log_addr;
part->EUNInfo[part->bam_index].Deleted--;
buffer += SECTOR_SIZE;
virt_addr += SECTOR_SIZE;
}
return 0;
}
static int ftl_getgeo(struct mtd_blktrans_dev *dev, struct hd_geometry *geo)
{
partition_t *part = (void *)dev;
u_long sect;
sect = le32_to_cpu(part->header.FormattedSize)/SECTOR_SIZE;
geo->heads = 1;
geo->sectors = 8;
geo->cylinders = sect >> 3;
return 0;
}
static int ftl_readsect(struct mtd_blktrans_dev *dev,
unsigned long block, char *buf)
{
return ftl_read((void *)dev, buf, block, 1);
}
static int ftl_writesect(struct mtd_blktrans_dev *dev,
unsigned long block, char *buf)
{
return ftl_write((void *)dev, buf, block, 1);
}
static int ftl_discardsect(struct mtd_blktrans_dev *dev,
unsigned long sector, unsigned nr_sects)
{
partition_t *part = (void *)dev;
uint32_t bsize = 1 << part->header.EraseUnitSize;
pr_debug("FTL erase sector %ld for %d sectors\n",
sector, nr_sects);
while (nr_sects) {
uint32_t old_addr = part->VirtualBlockMap[sector];
if (old_addr != 0xffffffff) {
part->VirtualBlockMap[sector] = 0xffffffff;
part->EUNInfo[old_addr/bsize].Deleted++;
if (set_bam_entry(part, old_addr, 0))
return -EIO;
}
nr_sects--;
sector++;
}
return 0;
}
static void ftl_freepart(partition_t *part)
{
vfree(part->VirtualBlockMap);
part->VirtualBlockMap = NULL;
kfree(part->EUNInfo);
part->EUNInfo = NULL;
kfree(part->XferInfo);
part->XferInfo = NULL;
kfree(part->bam_cache);
part->bam_cache = NULL;
}
static void ftl_add_mtd(struct mtd_blktrans_ops *tr, struct mtd_info *mtd)
{
partition_t *partition;
partition = kzalloc(sizeof(partition_t), GFP_KERNEL);
if (!partition) {
printk(KERN_WARNING "No memory to scan for FTL on %s\n",
mtd->name);
return;
}
partition->mbd.mtd = mtd;
if ((scan_header(partition) == 0) &&
(build_maps(partition) == 0)) {
partition->state = FTL_FORMATTED;
#ifdef PCMCIA_DEBUG
printk(KERN_INFO "ftl_cs: opening %d KiB FTL partition\n",
le32_to_cpu(partition->header.FormattedSize) >> 10);
#endif
partition->mbd.size = le32_to_cpu(partition->header.FormattedSize) >> 9;
partition->mbd.tr = tr;
partition->mbd.devnum = -1;
if (!add_mtd_blktrans_dev((void *)partition))
return;
}
kfree(partition);
}
static void ftl_remove_dev(struct mtd_blktrans_dev *dev)
{
del_mtd_blktrans_dev(dev);
ftl_freepart((partition_t *)dev);
}
static int __init init_ftl(void)
{
return register_mtd_blktrans(&ftl_tr);
}
static void __exit cleanup_ftl(void)
{
deregister_mtd_blktrans(&ftl_tr);
}
