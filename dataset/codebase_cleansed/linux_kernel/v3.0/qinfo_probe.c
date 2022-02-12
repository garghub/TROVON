static long lpddr_get_qinforec_pos(struct map_info *map, char *id_str)
{
int qinfo_lines = sizeof(qinfo_array)/sizeof(struct qinfo_query_info);
int i;
int bankwidth = map_bankwidth(map) * 8;
int major, minor;
for (i = 0; i < qinfo_lines; i++) {
if (strcmp(id_str, qinfo_array[i].id_str) == 0) {
major = qinfo_array[i].major & ((1 << bankwidth) - 1);
minor = qinfo_array[i].minor & ((1 << bankwidth) - 1);
return minor | (major << bankwidth);
}
}
printk(KERN_ERR"%s qinfo id string is wrong! \n", map->name);
BUG();
return -1;
}
static uint16_t lpddr_info_query(struct map_info *map, char *id_str)
{
unsigned int dsr, val;
int bits_per_chip = map_bankwidth(map) * 8;
unsigned long adr = lpddr_get_qinforec_pos(map, id_str);
int attempts = 20;
map_write(map, CMD(LPDDR_INFO_QUERY),
map->pfow_base + PFOW_COMMAND_CODE);
map_write(map, CMD(adr & ((1 << bits_per_chip) - 1)),
map->pfow_base + PFOW_COMMAND_ADDRESS_L);
map_write(map, CMD(adr >> bits_per_chip),
map->pfow_base + PFOW_COMMAND_ADDRESS_H);
map_write(map, CMD(LPDDR_START_EXECUTION),
map->pfow_base + PFOW_COMMAND_EXECUTE);
while ((attempts--) > 0) {
dsr = CMDVAL(map_read(map, map->pfow_base + PFOW_DSR));
if (dsr & DSR_READY_STATUS)
break;
udelay(10);
}
val = CMDVAL(map_read(map, map->pfow_base + PFOW_COMMAND_DATA));
return val;
}
static int lpddr_pfow_present(struct map_info *map, struct lpddr_private *lpddr)
{
map_word pfow_val[4];
pfow_val[0] = map_read(map, map->pfow_base + PFOW_QUERY_STRING_P);
pfow_val[1] = map_read(map, map->pfow_base + PFOW_QUERY_STRING_F);
pfow_val[2] = map_read(map, map->pfow_base + PFOW_QUERY_STRING_O);
pfow_val[3] = map_read(map, map->pfow_base + PFOW_QUERY_STRING_W);
if (!map_word_equal(map, CMD('P'), pfow_val[0]))
goto out;
if (!map_word_equal(map, CMD('F'), pfow_val[1]))
goto out;
if (!map_word_equal(map, CMD('O'), pfow_val[2]))
goto out;
if (!map_word_equal(map, CMD('W'), pfow_val[3]))
goto out;
return 1;
out:
printk(KERN_WARNING"%s: PFOW string at 0x%lx is not found \n",
map->name, map->pfow_base);
return 0;
}
static int lpddr_chip_setup(struct map_info *map, struct lpddr_private *lpddr)
{
lpddr->qinfo = kzalloc(sizeof(struct qinfo_chip), GFP_KERNEL);
if (!lpddr->qinfo) {
printk(KERN_WARNING "%s: no memory for LPDDR qinfo structure\n",
map->name);
return 0;
}
lpddr->ManufactId = CMDVAL(map_read(map, map->pfow_base + PFOW_MANUFACTURER_ID));
lpddr->DevId = CMDVAL(map_read(map, map->pfow_base + PFOW_DEVICE_ID));
lpddr->qinfo->DevSizeShift = lpddr_info_query(map, "DevSizeShift");
lpddr->qinfo->TotalBlocksNum = lpddr_info_query(map, "TotalBlocksNum");
lpddr->qinfo->BufSizeShift = lpddr_info_query(map, "BufSizeShift");
lpddr->qinfo->HWPartsNum = lpddr_info_query(map, "HWPartsNum");
lpddr->qinfo->UniformBlockSizeShift =
lpddr_info_query(map, "UniformBlockSizeShift");
lpddr->qinfo->SuspEraseSupp = lpddr_info_query(map, "SuspEraseSupp");
lpddr->qinfo->SingleWordProgTime =
lpddr_info_query(map, "SingleWordProgTime");
lpddr->qinfo->ProgBufferTime = lpddr_info_query(map, "ProgBufferTime");
lpddr->qinfo->BlockEraseTime = lpddr_info_query(map, "BlockEraseTime");
return 1;
}
static struct lpddr_private *lpddr_probe_chip(struct map_info *map)
{
struct lpddr_private lpddr;
struct lpddr_private *retlpddr;
int numvirtchips;
if ((map->pfow_base + 0x1000) >= map->size) {
printk(KERN_NOTICE"%s Probe at base (0x%08lx) past the end of"
"the map(0x%08lx)\n", map->name,
(unsigned long)map->pfow_base, map->size - 1);
return NULL;
}
memset(&lpddr, 0, sizeof(struct lpddr_private));
if (!lpddr_pfow_present(map, &lpddr))
return NULL;
if (!lpddr_chip_setup(map, &lpddr))
return NULL;
lpddr.chipshift = lpddr.qinfo->DevSizeShift;
lpddr.numchips = 1;
numvirtchips = lpddr.numchips * lpddr.qinfo->HWPartsNum;
retlpddr = kzalloc(sizeof(struct lpddr_private) +
numvirtchips * sizeof(struct flchip), GFP_KERNEL);
if (!retlpddr)
return NULL;
memcpy(retlpddr, &lpddr, sizeof(struct lpddr_private));
retlpddr->numchips = numvirtchips;
retlpddr->chipshift = retlpddr->qinfo->DevSizeShift -
__ffs(retlpddr->qinfo->HWPartsNum);
return retlpddr;
}
struct mtd_info *lpddr_probe(struct map_info *map)
{
struct mtd_info *mtd = NULL;
struct lpddr_private *lpddr;
lpddr = lpddr_probe_chip(map);
if (!lpddr)
return NULL;
map->fldrv_priv = lpddr;
mtd = lpddr_cmdset(map);
if (mtd) {
if (mtd->size > map->size) {
printk(KERN_WARNING "Reducing visibility of %ldKiB chip"
"to %ldKiB\n", (unsigned long)mtd->size >> 10,
(unsigned long)map->size >> 10);
mtd->size = map->size;
}
return mtd;
}
kfree(lpddr->qinfo);
kfree(lpddr);
map->fldrv_priv = NULL;
return NULL;
}
static int __init lpddr_probe_init(void)
{
register_mtd_chip_driver(&lpddr_chipdrv);
return 0;
}
static void __exit lpddr_probe_exit(void)
{
unregister_mtd_chip_driver(&lpddr_chipdrv);
}
