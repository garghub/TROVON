u32 mega_mod64(u64 dividend, u32 divisor)
{
u64 d;
u32 remainder;
if (!divisor)
printk(KERN_ERR "megasas : DIVISOR is zero, in div fn\n");
d = dividend;
remainder = do_div(d, divisor);
return remainder;
}
u64 mega_div64_32(uint64_t dividend, uint32_t divisor)
{
u32 remainder;
u64 d;
if (!divisor)
printk(KERN_ERR "megasas : DIVISOR is zero in mod fn\n");
d = dividend;
remainder = do_div(d, divisor);
return d;
}
struct MR_LD_RAID *MR_LdRaidGet(u32 ld, struct MR_FW_RAID_MAP_ALL *map)
{
return &map->raidMap.ldSpanMap[ld].ldRaid;
}
static struct MR_SPAN_BLOCK_INFO *MR_LdSpanInfoGet(u32 ld,
struct MR_FW_RAID_MAP_ALL
*map)
{
return &map->raidMap.ldSpanMap[ld].spanBlock[0];
}
static u8 MR_LdDataArmGet(u32 ld, u32 armIdx, struct MR_FW_RAID_MAP_ALL *map)
{
return map->raidMap.ldSpanMap[ld].dataArmMap[armIdx];
}
static u16 MR_ArPdGet(u32 ar, u32 arm, struct MR_FW_RAID_MAP_ALL *map)
{
return map->raidMap.arMapInfo[ar].pd[arm];
}
static u16 MR_LdSpanArrayGet(u32 ld, u32 span, struct MR_FW_RAID_MAP_ALL *map)
{
return map->raidMap.ldSpanMap[ld].spanBlock[span].span.arrayRef;
}
static u16 MR_PdDevHandleGet(u32 pd, struct MR_FW_RAID_MAP_ALL *map)
{
return map->raidMap.devHndlInfo[pd].curDevHdl;
}
u16 MR_GetLDTgtId(u32 ld, struct MR_FW_RAID_MAP_ALL *map)
{
return map->raidMap.ldSpanMap[ld].ldRaid.targetId;
}
u16 MR_TargetIdToLdGet(u32 ldTgtId, struct MR_FW_RAID_MAP_ALL *map)
{
return map->raidMap.ldTgtIdToLd[ldTgtId];
}
static struct MR_LD_SPAN *MR_LdSpanPtrGet(u32 ld, u32 span,
struct MR_FW_RAID_MAP_ALL *map)
{
return &map->raidMap.ldSpanMap[ld].spanBlock[span].span;
}
u8 MR_ValidateMapInfo(struct MR_FW_RAID_MAP_ALL *map,
struct LD_LOAD_BALANCE_INFO *lbInfo)
{
struct MR_FW_RAID_MAP *pFwRaidMap = &map->raidMap;
if (pFwRaidMap->totalSize !=
(sizeof(struct MR_FW_RAID_MAP) -sizeof(struct MR_LD_SPAN_MAP) +
(sizeof(struct MR_LD_SPAN_MAP) *pFwRaidMap->ldCount))) {
printk(KERN_ERR "megasas: map info structure size 0x%x is not matching with ld count\n",
(unsigned int)((sizeof(struct MR_FW_RAID_MAP) -
sizeof(struct MR_LD_SPAN_MAP)) +
(sizeof(struct MR_LD_SPAN_MAP) *
pFwRaidMap->ldCount)));
printk(KERN_ERR "megasas: span map %x, pFwRaidMap->totalSize "
": %x\n", (unsigned int)sizeof(struct MR_LD_SPAN_MAP),
pFwRaidMap->totalSize);
return 0;
}
mr_update_load_balance_params(map, lbInfo);
return 1;
}
u32 MR_GetSpanBlock(u32 ld, u64 row, u64 *span_blk,
struct MR_FW_RAID_MAP_ALL *map, int *div_error)
{
struct MR_SPAN_BLOCK_INFO *pSpanBlock = MR_LdSpanInfoGet(ld, map);
struct MR_QUAD_ELEMENT *quad;
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
u32 span, j;
for (span = 0; span < raid->spanDepth; span++, pSpanBlock++) {
for (j = 0; j < pSpanBlock->block_span_info.noElements; j++) {
quad = &pSpanBlock->block_span_info.quad[j];
if (quad->diff == 0) {
*div_error = 1;
return span;
}
if (quad->logStart <= row && row <= quad->logEnd &&
(mega_mod64(row-quad->logStart, quad->diff)) == 0) {
if (span_blk != NULL) {
u64 blk, debugBlk;
blk =
mega_div64_32(
(row-quad->logStart),
quad->diff);
debugBlk = blk;
blk = (blk + quad->offsetInSpan) <<
raid->stripeShift;
*span_blk = blk;
}
return span;
}
}
}
return span;
}
u8 MR_GetPhyParams(struct megasas_instance *instance, u32 ld, u64 stripRow,
u16 stripRef, u64 *pdBlock, u16 *pDevHandle,
struct RAID_CONTEXT *pRAID_Context,
struct MR_FW_RAID_MAP_ALL *map)
{
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
u32 pd, arRef;
u8 physArm, span;
u64 row;
u8 retval = TRUE;
int error_code = 0;
row = mega_div64_32(stripRow, raid->rowDataSize);
if (raid->level == 6) {
u32 logArm = mega_mod64(stripRow, raid->rowDataSize);
u32 rowMod, armQ, arm;
if (raid->rowSize == 0)
return FALSE;
rowMod = mega_mod64(row, raid->rowSize);
armQ = raid->rowSize-1-rowMod;
arm = armQ+1+logArm;
if (arm >= raid->rowSize)
arm -= raid->rowSize;
physArm = (u8)arm;
} else {
if (raid->modFactor == 0)
return FALSE;
physArm = MR_LdDataArmGet(ld, mega_mod64(stripRow,
raid->modFactor),
map);
}
if (raid->spanDepth == 1) {
span = 0;
*pdBlock = row << raid->stripeShift;
} else {
span = (u8)MR_GetSpanBlock(ld, row, pdBlock, map, &error_code);
if (error_code == 1)
return FALSE;
}
arRef = MR_LdSpanArrayGet(ld, span, map);
pd = MR_ArPdGet(arRef, physArm, map);
if (pd != MR_PD_INVALID)
*pDevHandle = MR_PdDevHandleGet(pd, map);
else {
*pDevHandle = MR_PD_INVALID;
if ((raid->level >= 5) &&
(instance->pdev->device != PCI_DEVICE_ID_LSI_INVADER))
pRAID_Context->regLockFlags = REGION_TYPE_EXCLUSIVE;
else if (raid->level == 1) {
pd = MR_ArPdGet(arRef, physArm + 1, map);
if (pd != MR_PD_INVALID)
*pDevHandle = MR_PdDevHandleGet(pd, map);
}
}
*pdBlock += stripRef + MR_LdSpanPtrGet(ld, span, map)->startBlk;
pRAID_Context->spanArm = (span << RAID_CTX_SPANARM_SPAN_SHIFT) |
physArm;
return retval;
}
u8
MR_BuildRaidContext(struct megasas_instance *instance,
struct IO_REQUEST_INFO *io_info,
struct RAID_CONTEXT *pRAID_Context,
struct MR_FW_RAID_MAP_ALL *map)
{
struct MR_LD_RAID *raid;
u32 ld, stripSize, stripe_mask;
u64 endLba, endStrip, endRow, start_row, start_strip;
u64 regStart;
u32 regSize;
u8 num_strips, numRows;
u16 ref_in_start_stripe, ref_in_end_stripe;
u64 ldStartBlock;
u32 numBlocks, ldTgtId;
u8 isRead;
u8 retval = 0;
ldStartBlock = io_info->ldStartBlock;
numBlocks = io_info->numBlocks;
ldTgtId = io_info->ldTgtId;
isRead = io_info->isRead;
ld = MR_TargetIdToLdGet(ldTgtId, map);
raid = MR_LdRaidGet(ld, map);
stripSize = 1 << raid->stripeShift;
stripe_mask = stripSize-1;
start_strip = ldStartBlock >> raid->stripeShift;
ref_in_start_stripe = (u16)(ldStartBlock & stripe_mask);
endLba = ldStartBlock + numBlocks - 1;
ref_in_end_stripe = (u16)(endLba & stripe_mask);
endStrip = endLba >> raid->stripeShift;
num_strips = (u8)(endStrip - start_strip + 1);
if (raid->rowDataSize == 0)
return FALSE;
start_row = mega_div64_32(start_strip, raid->rowDataSize);
endRow = mega_div64_32(endStrip, raid->rowDataSize);
numRows = (u8)(endRow - start_row + 1);
regStart = start_row << raid->stripeShift;
regSize = stripSize;
if (num_strips > 1 || (!isRead && raid->level != 0) ||
!raid->capability.fpCapable) {
io_info->fpOkForIo = FALSE;
} else {
io_info->fpOkForIo = TRUE;
}
if (numRows == 1) {
if (num_strips == 1) {
regStart += ref_in_start_stripe;
regSize = numBlocks;
}
} else {
if (start_strip == (start_row + 1) * raid->rowDataSize - 1) {
regStart += ref_in_start_stripe;
regSize = stripSize - ref_in_start_stripe;
}
if (numRows > 2)
regSize += (numRows-2) << raid->stripeShift;
if (endStrip == endRow*raid->rowDataSize)
regSize += ref_in_end_stripe+1;
else
regSize += stripSize;
}
pRAID_Context->timeoutValue = map->raidMap.fpPdIoTimeoutSec;
if (instance->pdev->device == PCI_DEVICE_ID_LSI_INVADER)
pRAID_Context->regLockFlags = (isRead) ?
raid->regTypeReqOnRead : raid->regTypeReqOnWrite;
else
pRAID_Context->regLockFlags = (isRead) ?
REGION_TYPE_SHARED_READ : raid->regTypeReqOnWrite;
pRAID_Context->VirtualDiskTgtId = raid->targetId;
pRAID_Context->regLockRowLBA = regStart;
pRAID_Context->regLockLength = regSize;
pRAID_Context->configSeqNum = raid->seqNum;
if (io_info->fpOkForIo) {
retval = MR_GetPhyParams(instance, ld, start_strip,
ref_in_start_stripe,
&io_info->pdBlock,
&io_info->devHandle, pRAID_Context,
map);
if (io_info->devHandle == MR_PD_INVALID)
io_info->fpOkForIo = FALSE;
return retval;
} else if (isRead) {
uint stripIdx;
for (stripIdx = 0; stripIdx < num_strips; stripIdx++) {
if (!MR_GetPhyParams(instance, ld,
start_strip + stripIdx,
ref_in_start_stripe,
&io_info->pdBlock,
&io_info->devHandle,
pRAID_Context, map))
return TRUE;
}
}
return TRUE;
}
void
mr_update_load_balance_params(struct MR_FW_RAID_MAP_ALL *map,
struct LD_LOAD_BALANCE_INFO *lbInfo)
{
int ldCount;
u16 ld;
struct MR_LD_RAID *raid;
for (ldCount = 0; ldCount < MAX_LOGICAL_DRIVES; ldCount++) {
ld = MR_TargetIdToLdGet(ldCount, map);
if (ld >= MAX_LOGICAL_DRIVES) {
lbInfo[ldCount].loadBalanceFlag = 0;
continue;
}
raid = MR_LdRaidGet(ld, map);
if ((raid->level == 1) && (raid->rowSize == 2) &&
(raid->spanDepth == 1) && raid->ldState ==
MR_LD_STATE_OPTIMAL) {
u32 pd, arRef;
lbInfo[ldCount].loadBalanceFlag = 1;
arRef = MR_LdSpanArrayGet(ld, 0, map);
pd = MR_ArPdGet(arRef, 0, map);
lbInfo[ldCount].raid1DevHandle[0] =
MR_PdDevHandleGet(pd, map);
pd = MR_ArPdGet(arRef, 1, map);
lbInfo[ldCount].raid1DevHandle[1] =
MR_PdDevHandleGet(pd, map);
} else
lbInfo[ldCount].loadBalanceFlag = 0;
}
}
u8 megasas_get_best_arm(struct LD_LOAD_BALANCE_INFO *lbInfo, u8 arm, u64 block,
u32 count)
{
u16 pend0, pend1;
u64 diff0, diff1;
u8 bestArm;
pend0 = atomic_read(&lbInfo->scsi_pending_cmds[0]);
pend1 = atomic_read(&lbInfo->scsi_pending_cmds[1]);
diff0 = ABS_DIFF(block, lbInfo->last_accessed_block[0]);
diff1 = ABS_DIFF(block, lbInfo->last_accessed_block[1]);
bestArm = (diff0 <= diff1 ? 0 : 1);
if ((bestArm == arm && pend0 > pend1 + 16) ||
(bestArm != arm && pend1 > pend0 + 16))
bestArm ^= 1;
lbInfo->last_accessed_block[bestArm] = block + count - 1;
return bestArm;
}
u16 get_updated_dev_handle(struct LD_LOAD_BALANCE_INFO *lbInfo,
struct IO_REQUEST_INFO *io_info)
{
u8 arm, old_arm;
u16 devHandle;
old_arm = lbInfo->raid1DevHandle[0] == io_info->devHandle ? 0 : 1;
arm = megasas_get_best_arm(lbInfo, old_arm, io_info->ldStartBlock,
io_info->numBlocks);
devHandle = lbInfo->raid1DevHandle[arm];
atomic_inc(&lbInfo->scsi_pending_cmds[arm]);
return devHandle;
}
