static void bcm47xxpart_add_part(struct mtd_partition *part, char *name,
u64 offset, uint32_t mask_flags)
{
part->name = name;
part->offset = offset;
part->mask_flags = mask_flags;
}
static int bcm47xxpart_parse(struct mtd_info *master,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct mtd_partition *parts;
uint8_t i, curr_part = 0;
uint32_t *buf;
size_t bytes_read;
uint32_t offset;
uint32_t blocksize = 0x10000;
struct trx_header *trx;
parts = kzalloc(sizeof(struct mtd_partition) * BCM47XXPART_MAX_PARTS,
GFP_KERNEL);
buf = kzalloc(BCM47XXPART_BYTES_TO_READ, GFP_KERNEL);
for (offset = 0; offset <= master->size - blocksize;
offset += blocksize) {
if (offset >= 0x2000000)
break;
if (curr_part > BCM47XXPART_MAX_PARTS) {
pr_warn("Reached maximum number of partitions, scanning stopped!\n");
break;
}
if (mtd_read(master, offset, BCM47XXPART_BYTES_TO_READ,
&bytes_read, (uint8_t *)buf) < 0) {
pr_err("mtd_read error while parsing (offset: 0x%X)!\n",
offset);
continue;
}
if (buf[0x400 / 4] == NVRAM_HEADER) {
bcm47xxpart_add_part(&parts[curr_part++], "boot",
offset, MTD_WRITEABLE);
continue;
}
if (buf[0x000 / 4] == NVRAM_HEADER) {
bcm47xxpart_add_part(&parts[curr_part++], "nvram",
offset, 0);
continue;
}
if (buf[0x100 / 4] == BOARD_DATA_MAGIC) {
bcm47xxpart_add_part(&parts[curr_part++], "board_data",
offset, MTD_WRITEABLE);
continue;
}
if (buf[0x000 / 4] == POT_MAGIC1 &&
(buf[0x004 / 4] & 0xFFFF) == POT_MAGIC2) {
bcm47xxpart_add_part(&parts[curr_part++], "POT", offset,
MTD_WRITEABLE);
continue;
}
if (buf[0x010 / 4] == ML_MAGIC1 &&
buf[0x014 / 4] == ML_MAGIC2) {
bcm47xxpart_add_part(&parts[curr_part++], "ML", offset,
MTD_WRITEABLE);
continue;
}
if (buf[0x000 / 4] == TRX_MAGIC) {
trx = (struct trx_header *)buf;
i = 0;
if (trx->offset[2]) {
bcm47xxpart_add_part(&parts[curr_part++],
"loader",
offset + trx->offset[i],
0);
i++;
}
bcm47xxpart_add_part(&parts[curr_part++], "linux",
offset + trx->offset[i], 0);
i++;
bcm47xxpart_add_part(&parts[curr_part++], "rootfs",
offset + trx->offset[i], 0);
i++;
offset = rounddown(offset + trx->length, blocksize);
continue;
}
}
kfree(buf);
for (i = 0; i < curr_part - 1; i++)
parts[i].size = parts[i + 1].offset - parts[i].offset;
if (curr_part > 0)
parts[curr_part - 1].size =
master->size - parts[curr_part - 1].offset;
*pparts = parts;
return curr_part;
}
static int __init bcm47xxpart_init(void)
{
return register_mtd_parser(&bcm47xxpart_mtd_parser);
}
static void __exit bcm47xxpart_exit(void)
{
deregister_mtd_parser(&bcm47xxpart_mtd_parser);
}
