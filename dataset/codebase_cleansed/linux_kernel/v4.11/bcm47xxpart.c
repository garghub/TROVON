static void bcm47xxpart_add_part(struct mtd_partition *part, const char *name,
u64 offset, uint32_t mask_flags)
{
part->name = name;
part->offset = offset;
part->mask_flags = mask_flags;
}
static const char *bcm47xxpart_trx_data_part_name(struct mtd_info *master,
size_t offset)
{
uint32_t buf;
size_t bytes_read;
int err;
err = mtd_read(master, offset, sizeof(buf), &bytes_read,
(uint8_t *)&buf);
if (err && !mtd_is_bitflip(err)) {
pr_err("mtd_read error while parsing (offset: 0x%X): %d\n",
offset, err);
goto out_default;
}
if (buf == UBI_EC_MAGIC)
return "ubi";
out_default:
return "rootfs";
}
static int bcm47xxpart_parse_trx(struct mtd_info *master,
struct mtd_partition *trx,
struct mtd_partition *parts,
size_t parts_len)
{
struct trx_header header;
size_t bytes_read;
int curr_part = 0;
int i, err;
if (parts_len < 3) {
pr_warn("No enough space to add TRX partitions!\n");
return -ENOMEM;
}
err = mtd_read(master, trx->offset, sizeof(header), &bytes_read,
(uint8_t *)&header);
if (err && !mtd_is_bitflip(err)) {
pr_err("mtd_read error while reading TRX header: %d\n", err);
return err;
}
i = 0;
if (header.offset[2]) {
bcm47xxpart_add_part(&parts[curr_part++], "loader",
trx->offset + header.offset[i], 0);
i++;
}
if (header.offset[i]) {
bcm47xxpart_add_part(&parts[curr_part++], "linux",
trx->offset + header.offset[i], 0);
i++;
}
if (header.offset[i]) {
size_t offset = trx->offset + header.offset[i];
const char *name = bcm47xxpart_trx_data_part_name(master,
offset);
bcm47xxpart_add_part(&parts[curr_part++], name, offset, 0);
i++;
}
for (i = 0; i < curr_part; i++) {
u64 next_part_offset = (i < curr_part - 1) ?
parts[i + 1].offset :
trx->offset + trx->size;
parts[i].size = next_part_offset - parts[i].offset;
}
return curr_part;
}
static int bcm47xxpart_bootpartition(void)
{
char buf[4];
int bootpartition;
if (bcm47xx_nvram_getenv("bootpartition", buf, sizeof(buf)) > 0) {
if (!kstrtoint(buf, 0, &bootpartition))
return bootpartition;
}
return 0;
}
static int bcm47xxpart_parse(struct mtd_info *master,
const struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct mtd_partition *parts;
uint8_t i, curr_part = 0;
uint32_t *buf;
size_t bytes_read;
uint32_t offset;
uint32_t blocksize = master->erasesize;
int trx_parts[2];
int trx_num = 0;
int possible_nvram_sizes[] = { 0x8000, 0xF000, 0x10000, };
int err;
if (blocksize < 0x1000)
blocksize = 0x1000;
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
if (IS_ENABLED(CONFIG_BCM47XX) && offset >= 0x2000000)
break;
if (curr_part >= BCM47XXPART_MAX_PARTS) {
pr_warn("Reached maximum number of partitions, scanning stopped!\n");
break;
}
err = mtd_read(master, offset, BCM47XXPART_BYTES_TO_READ,
&bytes_read, (uint8_t *)buf);
if (err && !mtd_is_bitflip(err)) {
pr_err("mtd_read error while parsing (offset: 0x%X): %d\n",
offset, err);
continue;
}
if ((buf[0x4e0 / 4] == CFE_MAGIC && buf[0x4e4 / 4] == CFE_MAGIC) ||
(buf[0x400 / 4] == NVRAM_HEADER)) {
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
struct trx_header *trx;
if (trx_num >= ARRAY_SIZE(trx_parts))
pr_warn("No enough space to store another TRX found at 0x%X\n",
offset);
else
trx_parts[trx_num++] = curr_part;
bcm47xxpart_add_part(&parts[curr_part++], "firmware",
offset, 0);
trx = (struct trx_header *)buf;
offset = roundup(offset + trx->length, blocksize);
offset -= blocksize;
continue;
}
if (le32_to_cpu(buf[0x000 / 4]) == SQUASHFS_MAGIC ||
buf[0x000 / 4] == SHSQ_MAGIC) {
bcm47xxpart_add_part(&parts[curr_part++], "rootfs",
offset, 0);
continue;
}
if (offset != master->size - blocksize &&
buf[0x000 / 4] == NVRAM_HEADER) {
bcm47xxpart_add_part(&parts[curr_part++], "nvram",
offset, 0);
continue;
}
err = mtd_read(master, offset + 0x8000, 0x4, &bytes_read,
(uint8_t *)buf);
if (err && !mtd_is_bitflip(err)) {
pr_err("mtd_read error while parsing (offset: 0x%X): %d\n",
offset, err);
continue;
}
if (buf[0x000 / 4] == BOARD_DATA_MAGIC2) {
bcm47xxpart_add_part(&parts[curr_part++], "board_data",
offset, MTD_WRITEABLE);
continue;
}
}
for (i = 0; i < ARRAY_SIZE(possible_nvram_sizes); i++) {
if (curr_part >= BCM47XXPART_MAX_PARTS) {
pr_warn("Reached maximum number of partitions, scanning stopped!\n");
break;
}
offset = master->size - possible_nvram_sizes[i];
err = mtd_read(master, offset, 0x4, &bytes_read,
(uint8_t *)buf);
if (err && !mtd_is_bitflip(err)) {
pr_err("mtd_read error while reading (offset 0x%X): %d\n",
offset, err);
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
}
for (i = 0; i < trx_num; i++) {
struct mtd_partition *trx = &parts[trx_parts[i]];
if (i == bcm47xxpart_bootpartition()) {
int num_parts;
num_parts = bcm47xxpart_parse_trx(master, trx,
parts + curr_part,
BCM47XXPART_MAX_PARTS - curr_part);
if (num_parts > 0)
curr_part += num_parts;
} else {
trx->name = "failsafe";
}
}
*pparts = parts;
return curr_part;
}
