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
struct MR_LD_RAID *MR_LdRaidGet(u32 ld, struct MR_DRV_RAID_MAP_ALL *map)
{
return &map->raidMap.ldSpanMap[ld].ldRaid;
}
static struct MR_SPAN_BLOCK_INFO *MR_LdSpanInfoGet(u32 ld,
struct MR_DRV_RAID_MAP_ALL
*map)
{
return &map->raidMap.ldSpanMap[ld].spanBlock[0];
}
static u8 MR_LdDataArmGet(u32 ld, u32 armIdx, struct MR_DRV_RAID_MAP_ALL *map)
{
return map->raidMap.ldSpanMap[ld].dataArmMap[armIdx];
}
u16 MR_ArPdGet(u32 ar, u32 arm, struct MR_DRV_RAID_MAP_ALL *map)
{
return le16_to_cpu(map->raidMap.arMapInfo[ar].pd[arm]);
}
u16 MR_LdSpanArrayGet(u32 ld, u32 span, struct MR_DRV_RAID_MAP_ALL *map)
{
return le16_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].span.arrayRef);
}
__le16 MR_PdDevHandleGet(u32 pd, struct MR_DRV_RAID_MAP_ALL *map)
{
return map->raidMap.devHndlInfo[pd].curDevHdl;
}
u16 MR_GetLDTgtId(u32 ld, struct MR_DRV_RAID_MAP_ALL *map)
{
return le16_to_cpu(map->raidMap.ldSpanMap[ld].ldRaid.targetId);
}
u8 MR_TargetIdToLdGet(u32 ldTgtId, struct MR_DRV_RAID_MAP_ALL *map)
{
return map->raidMap.ldTgtIdToLd[ldTgtId];
}
static struct MR_LD_SPAN *MR_LdSpanPtrGet(u32 ld, u32 span,
struct MR_DRV_RAID_MAP_ALL *map)
{
return &map->raidMap.ldSpanMap[ld].spanBlock[span].span;
}
void MR_PopulateDrvRaidMap(struct megasas_instance *instance)
{
struct fusion_context *fusion = instance->ctrl_context;
struct MR_FW_RAID_MAP_ALL *fw_map_old = NULL;
struct MR_FW_RAID_MAP *pFwRaidMap = NULL;
int i;
u16 ld_count;
struct MR_DRV_RAID_MAP_ALL *drv_map =
fusion->ld_drv_map[(instance->map_id & 1)];
struct MR_DRV_RAID_MAP *pDrvRaidMap = &drv_map->raidMap;
if (instance->supportmax256vd) {
memcpy(fusion->ld_drv_map[instance->map_id & 1],
fusion->ld_map[instance->map_id & 1],
fusion->current_map_sz);
pDrvRaidMap->totalSize =
cpu_to_le32(sizeof(struct MR_FW_RAID_MAP_EXT));
} else {
fw_map_old = (struct MR_FW_RAID_MAP_ALL *)
fusion->ld_map[(instance->map_id & 1)];
pFwRaidMap = &fw_map_old->raidMap;
ld_count = (u16)le32_to_cpu(pFwRaidMap->ldCount);
#if VD_EXT_DEBUG
for (i = 0; i < ld_count; i++) {
dev_dbg(&instance->pdev->dev, "(%d) :Index 0x%x "
"Target Id 0x%x Seq Num 0x%x Size 0/%llx\n",
instance->unique_id, i,
fw_map_old->raidMap.ldSpanMap[i].ldRaid.targetId,
fw_map_old->raidMap.ldSpanMap[i].ldRaid.seqNum,
fw_map_old->raidMap.ldSpanMap[i].ldRaid.size);
}
#endif
memset(drv_map, 0, fusion->drv_map_sz);
pDrvRaidMap->totalSize = pFwRaidMap->totalSize;
pDrvRaidMap->ldCount = (__le16)cpu_to_le16(ld_count);
pDrvRaidMap->fpPdIoTimeoutSec = pFwRaidMap->fpPdIoTimeoutSec;
for (i = 0; i < MAX_RAIDMAP_LOGICAL_DRIVES + MAX_RAIDMAP_VIEWS; i++)
pDrvRaidMap->ldTgtIdToLd[i] =
(u8)pFwRaidMap->ldTgtIdToLd[i];
for (i = (MAX_RAIDMAP_LOGICAL_DRIVES + MAX_RAIDMAP_VIEWS);
i < MAX_LOGICAL_DRIVES_EXT; i++)
pDrvRaidMap->ldTgtIdToLd[i] = 0xff;
for (i = 0; i < ld_count; i++) {
pDrvRaidMap->ldSpanMap[i] = pFwRaidMap->ldSpanMap[i];
#if VD_EXT_DEBUG
dev_dbg(&instance->pdev->dev,
"pFwRaidMap->ldSpanMap[%d].ldRaid.targetId 0x%x "
"pFwRaidMap->ldSpanMap[%d].ldRaid.seqNum 0x%x "
"size 0x%x\n", i, i,
pFwRaidMap->ldSpanMap[i].ldRaid.targetId,
pFwRaidMap->ldSpanMap[i].ldRaid.seqNum,
(u32)pFwRaidMap->ldSpanMap[i].ldRaid.rowSize);
dev_dbg(&instance->pdev->dev,
"pDrvRaidMap->ldSpanMap[%d].ldRaid.targetId 0x%x "
"pDrvRaidMap->ldSpanMap[%d].ldRaid.seqNum 0x%x "
"size 0x%x\n", i, i,
pDrvRaidMap->ldSpanMap[i].ldRaid.targetId,
pDrvRaidMap->ldSpanMap[i].ldRaid.seqNum,
(u32)pDrvRaidMap->ldSpanMap[i].ldRaid.rowSize);
dev_dbg(&instance->pdev->dev, "Driver raid map all %p "
"raid map %p LD RAID MAP %p/%p\n", drv_map,
pDrvRaidMap, &pFwRaidMap->ldSpanMap[i].ldRaid,
&pDrvRaidMap->ldSpanMap[i].ldRaid);
#endif
}
memcpy(pDrvRaidMap->arMapInfo, pFwRaidMap->arMapInfo,
sizeof(struct MR_ARRAY_INFO) * MAX_RAIDMAP_ARRAYS);
memcpy(pDrvRaidMap->devHndlInfo, pFwRaidMap->devHndlInfo,
sizeof(struct MR_DEV_HANDLE_INFO) *
MAX_RAIDMAP_PHYSICAL_DEVICES);
}
}
u8 MR_ValidateMapInfo(struct megasas_instance *instance)
{
struct fusion_context *fusion;
struct MR_DRV_RAID_MAP_ALL *drv_map;
struct MR_DRV_RAID_MAP *pDrvRaidMap;
struct LD_LOAD_BALANCE_INFO *lbInfo;
PLD_SPAN_INFO ldSpanInfo;
struct MR_LD_RAID *raid;
u16 ldCount, num_lds;
u16 ld;
u32 expected_size;
MR_PopulateDrvRaidMap(instance);
fusion = instance->ctrl_context;
drv_map = fusion->ld_drv_map[(instance->map_id & 1)];
pDrvRaidMap = &drv_map->raidMap;
lbInfo = fusion->load_balance_info;
ldSpanInfo = fusion->log_to_span;
if (instance->supportmax256vd)
expected_size = sizeof(struct MR_FW_RAID_MAP_EXT);
else
expected_size =
(sizeof(struct MR_FW_RAID_MAP) - sizeof(struct MR_LD_SPAN_MAP) +
(sizeof(struct MR_LD_SPAN_MAP) * le16_to_cpu(pDrvRaidMap->ldCount)));
if (le32_to_cpu(pDrvRaidMap->totalSize) != expected_size) {
dev_err(&instance->pdev->dev, "map info structure size 0x%x is not matching with ld count\n",
(unsigned int) expected_size);
dev_err(&instance->pdev->dev, "megasas: span map %x, pDrvRaidMap->totalSize : %x\n",
(unsigned int)sizeof(struct MR_LD_SPAN_MAP),
le32_to_cpu(pDrvRaidMap->totalSize));
return 0;
}
if (instance->UnevenSpanSupport)
mr_update_span_set(drv_map, ldSpanInfo);
mr_update_load_balance_params(drv_map, lbInfo);
num_lds = le16_to_cpu(drv_map->raidMap.ldCount);
for (ldCount = 0; ldCount < num_lds; ldCount++) {
ld = MR_TargetIdToLdGet(ldCount, drv_map);
raid = MR_LdRaidGet(ld, drv_map);
le32_to_cpus((u32 *)&raid->capability);
}
return 1;
}
u32 MR_GetSpanBlock(u32 ld, u64 row, u64 *span_blk,
struct MR_DRV_RAID_MAP_ALL *map)
{
struct MR_SPAN_BLOCK_INFO *pSpanBlock = MR_LdSpanInfoGet(ld, map);
struct MR_QUAD_ELEMENT *quad;
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
u32 span, j;
for (span = 0; span < raid->spanDepth; span++, pSpanBlock++) {
for (j = 0; j < le32_to_cpu(pSpanBlock->block_span_info.noElements); j++) {
quad = &pSpanBlock->block_span_info.quad[j];
if (le32_to_cpu(quad->diff) == 0)
return SPAN_INVALID;
if (le64_to_cpu(quad->logStart) <= row && row <=
le64_to_cpu(quad->logEnd) && (mega_mod64(row - le64_to_cpu(quad->logStart),
le32_to_cpu(quad->diff))) == 0) {
if (span_blk != NULL) {
u64 blk, debugBlk;
blk = mega_div64_32((row-le64_to_cpu(quad->logStart)), le32_to_cpu(quad->diff));
debugBlk = blk;
blk = (blk + le64_to_cpu(quad->offsetInSpan)) << raid->stripeShift;
*span_blk = blk;
}
return span;
}
}
}
return SPAN_INVALID;
}
static int getSpanInfo(struct MR_DRV_RAID_MAP_ALL *map,
PLD_SPAN_INFO ldSpanInfo)
{
u8 span;
u32 element;
struct MR_LD_RAID *raid;
LD_SPAN_SET *span_set;
struct MR_QUAD_ELEMENT *quad;
int ldCount;
u16 ld;
for (ldCount = 0; ldCount < MAX_LOGICAL_DRIVES_EXT; ldCount++) {
ld = MR_TargetIdToLdGet(ldCount, map);
if (ld >= (MAX_LOGICAL_DRIVES_EXT - 1))
continue;
raid = MR_LdRaidGet(ld, map);
dev_dbg(&instance->pdev->dev, "LD %x: span_depth=%x\n",
ld, raid->spanDepth);
for (span = 0; span < raid->spanDepth; span++)
dev_dbg(&instance->pdev->dev, "Span=%x,"
" number of quads=%x\n", span,
le32_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].
block_span_info.noElements));
for (element = 0; element < MAX_QUAD_DEPTH; element++) {
span_set = &(ldSpanInfo[ld].span_set[element]);
if (span_set->span_row_data_width == 0)
break;
dev_dbg(&instance->pdev->dev, "Span Set %x:"
"width=%x, diff=%x\n", element,
(unsigned int)span_set->span_row_data_width,
(unsigned int)span_set->diff);
dev_dbg(&instance->pdev->dev, "logical LBA"
"start=0x%08lx, end=0x%08lx\n",
(long unsigned int)span_set->log_start_lba,
(long unsigned int)span_set->log_end_lba);
dev_dbg(&instance->pdev->dev, "span row start=0x%08lx,"
" end=0x%08lx\n",
(long unsigned int)span_set->span_row_start,
(long unsigned int)span_set->span_row_end);
dev_dbg(&instance->pdev->dev, "data row start=0x%08lx,"
" end=0x%08lx\n",
(long unsigned int)span_set->data_row_start,
(long unsigned int)span_set->data_row_end);
dev_dbg(&instance->pdev->dev, "data strip start=0x%08lx,"
" end=0x%08lx\n",
(long unsigned int)span_set->data_strip_start,
(long unsigned int)span_set->data_strip_end);
for (span = 0; span < raid->spanDepth; span++) {
if (le32_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].
block_span_info.noElements) >=
element + 1) {
quad = &map->raidMap.ldSpanMap[ld].
spanBlock[span].block_span_info.
quad[element];
dev_dbg(&instance->pdev->dev, "Span=%x,"
"Quad=%x, diff=%x\n", span,
element, le32_to_cpu(quad->diff));
dev_dbg(&instance->pdev->dev,
"offset_in_span=0x%08lx\n",
(long unsigned int)le64_to_cpu(quad->offsetInSpan));
dev_dbg(&instance->pdev->dev,
"logical start=0x%08lx, end=0x%08lx\n",
(long unsigned int)le64_to_cpu(quad->logStart),
(long unsigned int)le64_to_cpu(quad->logEnd));
}
}
}
}
return 0;
}
u32 mr_spanset_get_span_block(struct megasas_instance *instance,
u32 ld, u64 row, u64 *span_blk, struct MR_DRV_RAID_MAP_ALL *map)
{
struct fusion_context *fusion = instance->ctrl_context;
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
LD_SPAN_SET *span_set;
struct MR_QUAD_ELEMENT *quad;
u32 span, info;
PLD_SPAN_INFO ldSpanInfo = fusion->log_to_span;
for (info = 0; info < MAX_QUAD_DEPTH; info++) {
span_set = &(ldSpanInfo[ld].span_set[info]);
if (span_set->span_row_data_width == 0)
break;
if (row > span_set->data_row_end)
continue;
for (span = 0; span < raid->spanDepth; span++)
if (le32_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].
block_span_info.noElements) >= info+1) {
quad = &map->raidMap.ldSpanMap[ld].
spanBlock[span].
block_span_info.quad[info];
if (le32_to_cpu(quad->diff) == 0)
return SPAN_INVALID;
if (le64_to_cpu(quad->logStart) <= row &&
row <= le64_to_cpu(quad->logEnd) &&
(mega_mod64(row - le64_to_cpu(quad->logStart),
le32_to_cpu(quad->diff))) == 0) {
if (span_blk != NULL) {
u64 blk;
blk = mega_div64_32
((row - le64_to_cpu(quad->logStart)),
le32_to_cpu(quad->diff));
blk = (blk + le64_to_cpu(quad->offsetInSpan))
<< raid->stripeShift;
*span_blk = blk;
}
return span;
}
}
}
return SPAN_INVALID;
}
static u64 get_row_from_strip(struct megasas_instance *instance,
u32 ld, u64 strip, struct MR_DRV_RAID_MAP_ALL *map)
{
struct fusion_context *fusion = instance->ctrl_context;
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
LD_SPAN_SET *span_set;
PLD_SPAN_INFO ldSpanInfo = fusion->log_to_span;
u32 info, strip_offset, span, span_offset;
u64 span_set_Strip, span_set_Row, retval;
for (info = 0; info < MAX_QUAD_DEPTH; info++) {
span_set = &(ldSpanInfo[ld].span_set[info]);
if (span_set->span_row_data_width == 0)
break;
if (strip > span_set->data_strip_end)
continue;
span_set_Strip = strip - span_set->data_strip_start;
strip_offset = mega_mod64(span_set_Strip,
span_set->span_row_data_width);
span_set_Row = mega_div64_32(span_set_Strip,
span_set->span_row_data_width) * span_set->diff;
for (span = 0, span_offset = 0; span < raid->spanDepth; span++)
if (le32_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].
block_span_info.noElements) >= info+1) {
if (strip_offset >=
span_set->strip_offset[span])
span_offset++;
else
break;
}
#if SPAN_DEBUG
dev_info(&instance->pdev->dev, "Strip 0x%llx,"
"span_set_Strip 0x%llx, span_set_Row 0x%llx"
"data width 0x%llx span offset 0x%x\n", strip,
(unsigned long long)span_set_Strip,
(unsigned long long)span_set_Row,
(unsigned long long)span_set->span_row_data_width,
span_offset);
dev_info(&instance->pdev->dev, "For strip 0x%llx"
"row is 0x%llx\n", strip,
(unsigned long long) span_set->data_row_start +
(unsigned long long) span_set_Row + (span_offset - 1));
#endif
retval = (span_set->data_row_start + span_set_Row +
(span_offset - 1));
return retval;
}
return -1LLU;
}
static u64 get_strip_from_row(struct megasas_instance *instance,
u32 ld, u64 row, struct MR_DRV_RAID_MAP_ALL *map)
{
struct fusion_context *fusion = instance->ctrl_context;
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
LD_SPAN_SET *span_set;
struct MR_QUAD_ELEMENT *quad;
PLD_SPAN_INFO ldSpanInfo = fusion->log_to_span;
u32 span, info;
u64 strip;
for (info = 0; info < MAX_QUAD_DEPTH; info++) {
span_set = &(ldSpanInfo[ld].span_set[info]);
if (span_set->span_row_data_width == 0)
break;
if (row > span_set->data_row_end)
continue;
for (span = 0; span < raid->spanDepth; span++)
if (le32_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].
block_span_info.noElements) >= info+1) {
quad = &map->raidMap.ldSpanMap[ld].
spanBlock[span].block_span_info.quad[info];
if (le64_to_cpu(quad->logStart) <= row &&
row <= le64_to_cpu(quad->logEnd) &&
mega_mod64((row - le64_to_cpu(quad->logStart)),
le32_to_cpu(quad->diff)) == 0) {
strip = mega_div64_32
(((row - span_set->data_row_start)
- le64_to_cpu(quad->logStart)),
le32_to_cpu(quad->diff));
strip *= span_set->span_row_data_width;
strip += span_set->data_strip_start;
strip += span_set->strip_offset[span];
return strip;
}
}
}
dev_err(&instance->pdev->dev, "get_strip_from_row"
"returns invalid strip for ld=%x, row=%lx\n",
ld, (long unsigned int)row);
return -1;
}
static u32 get_arm_from_strip(struct megasas_instance *instance,
u32 ld, u64 strip, struct MR_DRV_RAID_MAP_ALL *map)
{
struct fusion_context *fusion = instance->ctrl_context;
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
LD_SPAN_SET *span_set;
PLD_SPAN_INFO ldSpanInfo = fusion->log_to_span;
u32 info, strip_offset, span, span_offset, retval;
for (info = 0 ; info < MAX_QUAD_DEPTH; info++) {
span_set = &(ldSpanInfo[ld].span_set[info]);
if (span_set->span_row_data_width == 0)
break;
if (strip > span_set->data_strip_end)
continue;
strip_offset = (uint)mega_mod64
((strip - span_set->data_strip_start),
span_set->span_row_data_width);
for (span = 0, span_offset = 0; span < raid->spanDepth; span++)
if (le32_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].
block_span_info.noElements) >= info+1) {
if (strip_offset >=
span_set->strip_offset[span])
span_offset =
span_set->strip_offset[span];
else
break;
}
#if SPAN_DEBUG
dev_info(&instance->pdev->dev, "get_arm_from_strip:"
"for ld=0x%x strip=0x%lx arm is 0x%x\n", ld,
(long unsigned int)strip, (strip_offset - span_offset));
#endif
retval = (strip_offset - span_offset);
return retval;
}
dev_err(&instance->pdev->dev, "get_arm_from_strip"
"returns invalid arm for ld=%x strip=%lx\n",
ld, (long unsigned int)strip);
return -1;
}
u8 get_arm(struct megasas_instance *instance, u32 ld, u8 span, u64 stripe,
struct MR_DRV_RAID_MAP_ALL *map)
{
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
u32 arm = 0;
switch (raid->level) {
case 0:
case 5:
case 6:
arm = mega_mod64(stripe, SPAN_ROW_SIZE(map, ld, span));
break;
case 1:
arm = get_arm_from_strip(instance, ld, stripe, map);
if (arm != -1U)
arm *= 2;
break;
}
return arm;
}
static u8 mr_spanset_get_phy_params(struct megasas_instance *instance, u32 ld,
u64 stripRow, u16 stripRef, struct IO_REQUEST_INFO *io_info,
struct RAID_CONTEXT *pRAID_Context,
struct MR_DRV_RAID_MAP_ALL *map)
{
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
u32 pd, arRef;
u8 physArm, span;
u64 row;
u8 retval = TRUE;
u64 *pdBlock = &io_info->pdBlock;
__le16 *pDevHandle = &io_info->devHandle;
u32 logArm, rowMod, armQ, arm;
struct fusion_context *fusion;
fusion = instance->ctrl_context;
row = io_info->start_row;
span = io_info->start_span;
if (raid->level == 6) {
logArm = get_arm_from_strip(instance, ld, stripRow, map);
if (logArm == -1U)
return FALSE;
rowMod = mega_mod64(row, SPAN_ROW_SIZE(map, ld, span));
armQ = SPAN_ROW_SIZE(map, ld, span) - 1 - rowMod;
arm = armQ + 1 + logArm;
if (arm >= SPAN_ROW_SIZE(map, ld, span))
arm -= SPAN_ROW_SIZE(map, ld, span);
physArm = (u8)arm;
} else
physArm = get_arm(instance, ld, span, stripRow, map);
if (physArm == 0xFF)
return FALSE;
arRef = MR_LdSpanArrayGet(ld, span, map);
pd = MR_ArPdGet(arRef, physArm, map);
if (pd != MR_PD_INVALID)
*pDevHandle = MR_PdDevHandleGet(pd, map);
else {
*pDevHandle = cpu_to_le16(MR_PD_INVALID);
if ((raid->level >= 5) &&
((fusion->adapter_type == THUNDERBOLT_SERIES) ||
((fusion->adapter_type == INVADER_SERIES) &&
(raid->regTypeReqOnRead != REGION_TYPE_UNUSED))))
pRAID_Context->regLockFlags = REGION_TYPE_EXCLUSIVE;
else if (raid->level == 1) {
pd = MR_ArPdGet(arRef, physArm + 1, map);
if (pd != MR_PD_INVALID)
*pDevHandle = MR_PdDevHandleGet(pd, map);
}
}
*pdBlock += stripRef + le64_to_cpu(MR_LdSpanPtrGet(ld, span, map)->startBlk);
pRAID_Context->spanArm = (span << RAID_CTX_SPANARM_SPAN_SHIFT) |
physArm;
io_info->span_arm = pRAID_Context->spanArm;
return retval;
}
u8 MR_GetPhyParams(struct megasas_instance *instance, u32 ld, u64 stripRow,
u16 stripRef, struct IO_REQUEST_INFO *io_info,
struct RAID_CONTEXT *pRAID_Context,
struct MR_DRV_RAID_MAP_ALL *map)
{
struct MR_LD_RAID *raid = MR_LdRaidGet(ld, map);
u32 pd, arRef;
u8 physArm, span;
u64 row;
u8 retval = TRUE;
u64 *pdBlock = &io_info->pdBlock;
__le16 *pDevHandle = &io_info->devHandle;
struct fusion_context *fusion;
fusion = instance->ctrl_context;
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
span = (u8)MR_GetSpanBlock(ld, row, pdBlock, map);
if (span == SPAN_INVALID)
return FALSE;
}
arRef = MR_LdSpanArrayGet(ld, span, map);
pd = MR_ArPdGet(arRef, physArm, map);
if (pd != MR_PD_INVALID)
*pDevHandle = MR_PdDevHandleGet(pd, map);
else {
*pDevHandle = cpu_to_le16(MR_PD_INVALID);
if ((raid->level >= 5) &&
((fusion->adapter_type == THUNDERBOLT_SERIES) ||
((fusion->adapter_type == INVADER_SERIES) &&
(raid->regTypeReqOnRead != REGION_TYPE_UNUSED))))
pRAID_Context->regLockFlags = REGION_TYPE_EXCLUSIVE;
else if (raid->level == 1) {
pd = MR_ArPdGet(arRef, physArm + 1, map);
if (pd != MR_PD_INVALID)
*pDevHandle = MR_PdDevHandleGet(pd, map);
}
}
*pdBlock += stripRef + le64_to_cpu(MR_LdSpanPtrGet(ld, span, map)->startBlk);
pRAID_Context->spanArm = (span << RAID_CTX_SPANARM_SPAN_SHIFT) |
physArm;
io_info->span_arm = pRAID_Context->spanArm;
return retval;
}
u8
MR_BuildRaidContext(struct megasas_instance *instance,
struct IO_REQUEST_INFO *io_info,
struct RAID_CONTEXT *pRAID_Context,
struct MR_DRV_RAID_MAP_ALL *map, u8 **raidLUN)
{
struct fusion_context *fusion;
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
u8 startlba_span = SPAN_INVALID;
u64 *pdBlock = &io_info->pdBlock;
ldStartBlock = io_info->ldStartBlock;
numBlocks = io_info->numBlocks;
ldTgtId = io_info->ldTgtId;
isRead = io_info->isRead;
io_info->IoforUnevenSpan = 0;
io_info->start_span = SPAN_INVALID;
fusion = instance->ctrl_context;
ld = MR_TargetIdToLdGet(ldTgtId, map);
raid = MR_LdRaidGet(ld, map);
if (raid->rowDataSize == 0) {
if (MR_LdSpanPtrGet(ld, 0, map)->spanRowDataSize == 0)
return FALSE;
else if (instance->UnevenSpanSupport) {
io_info->IoforUnevenSpan = 1;
} else {
dev_info(&instance->pdev->dev,
"raid->rowDataSize is 0, but has SPAN[0]"
"rowDataSize = 0x%0x,"
"but there is _NO_ UnevenSpanSupport\n",
MR_LdSpanPtrGet(ld, 0, map)->spanRowDataSize);
return FALSE;
}
}
stripSize = 1 << raid->stripeShift;
stripe_mask = stripSize-1;
start_strip = ldStartBlock >> raid->stripeShift;
ref_in_start_stripe = (u16)(ldStartBlock & stripe_mask);
endLba = ldStartBlock + numBlocks - 1;
ref_in_end_stripe = (u16)(endLba & stripe_mask);
endStrip = endLba >> raid->stripeShift;
num_strips = (u8)(endStrip - start_strip + 1);
if (io_info->IoforUnevenSpan) {
start_row = get_row_from_strip(instance, ld, start_strip, map);
endRow = get_row_from_strip(instance, ld, endStrip, map);
if (start_row == -1ULL || endRow == -1ULL) {
dev_info(&instance->pdev->dev, "return from %s %d."
"Send IO w/o region lock.\n",
__func__, __LINE__);
return FALSE;
}
if (raid->spanDepth == 1) {
startlba_span = 0;
*pdBlock = start_row << raid->stripeShift;
} else
startlba_span = (u8)mr_spanset_get_span_block(instance,
ld, start_row, pdBlock, map);
if (startlba_span == SPAN_INVALID) {
dev_info(&instance->pdev->dev, "return from %s %d"
"for row 0x%llx,start strip %llx"
"endSrip %llx\n", __func__, __LINE__,
(unsigned long long)start_row,
(unsigned long long)start_strip,
(unsigned long long)endStrip);
return FALSE;
}
io_info->start_span = startlba_span;
io_info->start_row = start_row;
#if SPAN_DEBUG
dev_dbg(&instance->pdev->dev, "Check Span number from %s %d"
"for row 0x%llx, start strip 0x%llx end strip 0x%llx"
" span 0x%x\n", __func__, __LINE__,
(unsigned long long)start_row,
(unsigned long long)start_strip,
(unsigned long long)endStrip, startlba_span);
dev_dbg(&instance->pdev->dev, "start_row 0x%llx endRow 0x%llx"
"Start span 0x%x\n", (unsigned long long)start_row,
(unsigned long long)endRow, startlba_span);
#endif
} else {
start_row = mega_div64_32(start_strip, raid->rowDataSize);
endRow = mega_div64_32(endStrip, raid->rowDataSize);
}
numRows = (u8)(endRow - start_row + 1);
regStart = start_row << raid->stripeShift;
regSize = stripSize;
if (raid->capability.fpCapable) {
if (isRead)
io_info->fpOkForIo = (raid->capability.fpReadCapable &&
((num_strips == 1) ||
raid->capability.
fpReadAcrossStripe));
else
io_info->fpOkForIo = (raid->capability.fpWriteCapable &&
((num_strips == 1) ||
raid->capability.
fpWriteAcrossStripe));
} else
io_info->fpOkForIo = FALSE;
if (numRows == 1) {
if (num_strips == 1) {
regStart += ref_in_start_stripe;
regSize = numBlocks;
}
} else if (io_info->IoforUnevenSpan == 0) {
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
} else {
if (start_strip == (get_strip_from_row(instance, ld, start_row, map) +
SPAN_ROW_DATA_SIZE(map, ld, startlba_span) - 1)) {
regStart += ref_in_start_stripe;
regSize = stripSize - ref_in_start_stripe;
}
if (numRows > 2)
regSize += (numRows-2) << raid->stripeShift;
if (endStrip == get_strip_from_row(instance, ld, endRow, map))
regSize += ref_in_end_stripe + 1;
else
regSize += stripSize;
}
pRAID_Context->timeoutValue =
cpu_to_le16(raid->fpIoTimeoutForLd ?
raid->fpIoTimeoutForLd :
map->raidMap.fpPdIoTimeoutSec);
if (fusion->adapter_type == INVADER_SERIES)
pRAID_Context->regLockFlags = (isRead) ?
raid->regTypeReqOnRead : raid->regTypeReqOnWrite;
else
pRAID_Context->regLockFlags = (isRead) ?
REGION_TYPE_SHARED_READ : raid->regTypeReqOnWrite;
pRAID_Context->VirtualDiskTgtId = raid->targetId;
pRAID_Context->regLockRowLBA = cpu_to_le64(regStart);
pRAID_Context->regLockLength = cpu_to_le32(regSize);
pRAID_Context->configSeqNum = raid->seqNum;
*raidLUN = raid->LUN;
if (io_info->fpOkForIo) {
retval = io_info->IoforUnevenSpan ?
mr_spanset_get_phy_params(instance, ld,
start_strip, ref_in_start_stripe,
io_info, pRAID_Context, map) :
MR_GetPhyParams(instance, ld, start_strip,
ref_in_start_stripe, io_info,
pRAID_Context, map);
if (io_info->devHandle == cpu_to_le16(MR_PD_INVALID))
io_info->fpOkForIo = FALSE;
return retval;
} else if (isRead) {
uint stripIdx;
for (stripIdx = 0; stripIdx < num_strips; stripIdx++) {
retval = io_info->IoforUnevenSpan ?
mr_spanset_get_phy_params(instance, ld,
start_strip + stripIdx,
ref_in_start_stripe, io_info,
pRAID_Context, map) :
MR_GetPhyParams(instance, ld,
start_strip + stripIdx, ref_in_start_stripe,
io_info, pRAID_Context, map);
if (!retval)
return TRUE;
}
}
#if SPAN_DEBUG
if (io_info->IoforUnevenSpan)
get_arm_from_strip(instance, ld, start_strip, map);
#endif
return TRUE;
}
void mr_update_span_set(struct MR_DRV_RAID_MAP_ALL *map,
PLD_SPAN_INFO ldSpanInfo)
{
u8 span, count;
u32 element, span_row_width;
u64 span_row;
struct MR_LD_RAID *raid;
LD_SPAN_SET *span_set, *span_set_prev;
struct MR_QUAD_ELEMENT *quad;
int ldCount;
u16 ld;
for (ldCount = 0; ldCount < MAX_LOGICAL_DRIVES_EXT; ldCount++) {
ld = MR_TargetIdToLdGet(ldCount, map);
if (ld >= (MAX_LOGICAL_DRIVES_EXT - 1))
continue;
raid = MR_LdRaidGet(ld, map);
for (element = 0; element < MAX_QUAD_DEPTH; element++) {
for (span = 0; span < raid->spanDepth; span++) {
if (le32_to_cpu(map->raidMap.ldSpanMap[ld].spanBlock[span].
block_span_info.noElements) <
element + 1)
continue;
span_set = &(ldSpanInfo[ld].span_set[element]);
quad = &map->raidMap.ldSpanMap[ld].
spanBlock[span].block_span_info.
quad[element];
span_set->diff = le32_to_cpu(quad->diff);
for (count = 0, span_row_width = 0;
count < raid->spanDepth; count++) {
if (le32_to_cpu(map->raidMap.ldSpanMap[ld].
spanBlock[count].
block_span_info.
noElements) >= element + 1) {
span_set->strip_offset[count] =
span_row_width;
span_row_width +=
MR_LdSpanPtrGet
(ld, count, map)->spanRowDataSize;
}
}
span_set->span_row_data_width = span_row_width;
span_row = mega_div64_32(((le64_to_cpu(quad->logEnd) -
le64_to_cpu(quad->logStart)) + le32_to_cpu(quad->diff)),
le32_to_cpu(quad->diff));
if (element == 0) {
span_set->log_start_lba = 0;
span_set->log_end_lba =
((span_row << raid->stripeShift)
* span_row_width) - 1;
span_set->span_row_start = 0;
span_set->span_row_end = span_row - 1;
span_set->data_strip_start = 0;
span_set->data_strip_end =
(span_row * span_row_width) - 1;
span_set->data_row_start = 0;
span_set->data_row_end =
(span_row * le32_to_cpu(quad->diff)) - 1;
} else {
span_set_prev = &(ldSpanInfo[ld].
span_set[element - 1]);
span_set->log_start_lba =
span_set_prev->log_end_lba + 1;
span_set->log_end_lba =
span_set->log_start_lba +
((span_row << raid->stripeShift)
* span_row_width) - 1;
span_set->span_row_start =
span_set_prev->span_row_end + 1;
span_set->span_row_end =
span_set->span_row_start + span_row - 1;
span_set->data_strip_start =
span_set_prev->data_strip_end + 1;
span_set->data_strip_end =
span_set->data_strip_start +
(span_row * span_row_width) - 1;
span_set->data_row_start =
span_set_prev->data_row_end + 1;
span_set->data_row_end =
span_set->data_row_start +
(span_row * le32_to_cpu(quad->diff)) - 1;
}
break;
}
if (span == raid->spanDepth)
break;
}
}
#if SPAN_DEBUG
getSpanInfo(map, ldSpanInfo);
#endif
}
void mr_update_load_balance_params(struct MR_DRV_RAID_MAP_ALL *drv_map,
struct LD_LOAD_BALANCE_INFO *lbInfo)
{
int ldCount;
u16 ld;
struct MR_LD_RAID *raid;
if (lb_pending_cmds > 128 || lb_pending_cmds < 1)
lb_pending_cmds = LB_PENDING_CMDS_DEFAULT;
for (ldCount = 0; ldCount < MAX_LOGICAL_DRIVES_EXT; ldCount++) {
ld = MR_TargetIdToLdGet(ldCount, drv_map);
if (ld >= MAX_LOGICAL_DRIVES_EXT) {
lbInfo[ldCount].loadBalanceFlag = 0;
continue;
}
raid = MR_LdRaidGet(ld, drv_map);
if ((raid->level != 1) ||
(raid->ldState != MR_LD_STATE_OPTIMAL)) {
lbInfo[ldCount].loadBalanceFlag = 0;
continue;
}
lbInfo[ldCount].loadBalanceFlag = 1;
}
}
u8 megasas_get_best_arm_pd(struct megasas_instance *instance,
struct LD_LOAD_BALANCE_INFO *lbInfo, struct IO_REQUEST_INFO *io_info)
{
struct fusion_context *fusion;
struct MR_LD_RAID *raid;
struct MR_DRV_RAID_MAP_ALL *drv_map;
u16 pend0, pend1, ld;
u64 diff0, diff1;
u8 bestArm, pd0, pd1, span, arm;
u32 arRef, span_row_size;
u64 block = io_info->ldStartBlock;
u32 count = io_info->numBlocks;
span = ((io_info->span_arm & RAID_CTX_SPANARM_SPAN_MASK)
>> RAID_CTX_SPANARM_SPAN_SHIFT);
arm = (io_info->span_arm & RAID_CTX_SPANARM_ARM_MASK);
fusion = instance->ctrl_context;
drv_map = fusion->ld_drv_map[(instance->map_id & 1)];
ld = MR_TargetIdToLdGet(io_info->ldTgtId, drv_map);
raid = MR_LdRaidGet(ld, drv_map);
span_row_size = instance->UnevenSpanSupport ?
SPAN_ROW_SIZE(drv_map, ld, span) : raid->rowSize;
arRef = MR_LdSpanArrayGet(ld, span, drv_map);
pd0 = MR_ArPdGet(arRef, arm, drv_map);
pd1 = MR_ArPdGet(arRef, (arm + 1) >= span_row_size ?
(arm + 1 - span_row_size) : arm + 1, drv_map);
pend0 = atomic_read(&lbInfo->scsi_pending_cmds[pd0]);
pend1 = atomic_read(&lbInfo->scsi_pending_cmds[pd1]);
diff0 = ABS_DIFF(block, lbInfo->last_accessed_block[pd0]);
diff1 = ABS_DIFF(block, lbInfo->last_accessed_block[pd1]);
bestArm = (diff0 <= diff1 ? arm : arm ^ 1);
if ((bestArm == arm && pend0 > pend1 + lb_pending_cmds) ||
(bestArm != arm && pend1 > pend0 + lb_pending_cmds))
bestArm ^= 1;
io_info->pd_after_lb = (bestArm == arm) ? pd0 : pd1;
lbInfo->last_accessed_block[io_info->pd_after_lb] = block + count - 1;
io_info->span_arm = (span << RAID_CTX_SPANARM_SPAN_SHIFT) | bestArm;
#if SPAN_DEBUG
if (arm != bestArm)
dev_dbg(&instance->pdev->dev, "LSI Debug R1 Load balance "
"occur - span 0x%x arm 0x%x bestArm 0x%x "
"io_info->span_arm 0x%x\n",
span, arm, bestArm, io_info->span_arm);
#endif
return io_info->pd_after_lb;
}
__le16 get_updated_dev_handle(struct megasas_instance *instance,
struct LD_LOAD_BALANCE_INFO *lbInfo, struct IO_REQUEST_INFO *io_info)
{
u8 arm_pd;
__le16 devHandle;
struct fusion_context *fusion;
struct MR_DRV_RAID_MAP_ALL *drv_map;
fusion = instance->ctrl_context;
drv_map = fusion->ld_drv_map[(instance->map_id & 1)];
arm_pd = megasas_get_best_arm_pd(instance, lbInfo, io_info);
devHandle = MR_PdDevHandleGet(arm_pd, drv_map);
atomic_inc(&lbInfo->scsi_pending_cmds[arm_pd]);
return devHandle;
}
