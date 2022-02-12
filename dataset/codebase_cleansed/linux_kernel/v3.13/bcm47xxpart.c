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
uint32_t blocksize = master->erasesize;
struct trx_header *trx;
int trx_part = -1;
int last_trx_part = -1;
int possible_nvram_sizes[] = { 0x8000, 0xF000, 0x10000, };
if (blocksize <= 0x10000)
blocksize = 0x10000;
parts = kzalloc(sizeof(struct mtd_partition) * BCM47XXPART_MAX_PARTS,
GFP_KERNEL);
if (!parts)
return -ENOMEM;
buf = kzalloc(BCM47XXPART_BYTES_TO_READ, GFP_KERNEL);
if (!buf) {
kfree(parts);
return -ENOMEM;
}
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
if (buf[0x100 / 4] == BOARD_DATA_MAGIC) {
bcm47xxpart_add_part(&parts[curr_part++], "board_data",
offset, MTD_WRITEABLE);
continue;
}
if (buf[0x000 / 4] == FACTORY_MAGIC) {
bcm47xxpart_add_part(&parts[curr_part++], "factory",
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
trx_part = curr_part;
bcm47xxpart_add_part(&parts[curr_part++], "firmware",
offset, 0);
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
last_trx_part = curr_part - 1;
offset = rounddown(offset + trx->length, blocksize);
continue;
}
if (buf[0x000 / 4] == SQSH_MAGIC) {
bcm47xxpart_add_part(&parts[curr_part++], "rootfs",
offset, 0);
continue;
}
}
for (i = 0; i < ARRAY_SIZE(possible_nvram_sizes); i++) {
if (curr_part > BCM47XXPART_MAX_PARTS) {
pr_warn("Reached maximum number of partitions, scanning stopped!\n");
break;
}
offset = master->size - possible_nvram_sizes[i];
if (mtd_read(master, offset, 0x4, &bytes_read,
(uint8_t *)buf) < 0) {
pr_err("mtd_read error while reading at offset 0x%X!\n",
offset);
continue;
}
if (buf[0] == NVRAM_HEADER) {
bcm47xxpart_add_part(&parts[curr_part++], "nvram",
master->size - blocksize, 0);
break;
}
}
kfree(buf);
for (i = 0; i < curr_part; i++) {
u64 next_part_offset = (i < curr_part - 1) ?
parts[i + 1].offset : master->size;
parts[i].size = next_part_offset - parts[i].offset;
if (i == last_trx_part && trx_part >= 0)
parts[trx_part].size = next_part_offset -
parts[trx_part].offset;
}
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
