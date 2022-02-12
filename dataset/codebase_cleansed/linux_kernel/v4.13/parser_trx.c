static const char *parser_trx_data_part_name(struct mtd_info *master,
size_t offset)
{
uint32_t buf;
size_t bytes_read;
int err;
err = mtd_read(master, offset, sizeof(buf), &bytes_read,
(uint8_t *)&buf);
if (err && !mtd_is_bitflip(err)) {
pr_err("mtd_read error while parsing (offset: 0x%zX): %d\n",
offset, err);
goto out_default;
}
if (buf == UBI_EC_MAGIC)
return "ubi";
out_default:
return "rootfs";
}
static int parser_trx_parse(struct mtd_info *mtd,
const struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct mtd_partition *parts;
struct mtd_partition *part;
struct trx_header trx;
size_t bytes_read;
uint8_t curr_part = 0, i = 0;
int err;
parts = kzalloc(sizeof(struct mtd_partition) * TRX_PARSER_MAX_PARTS,
GFP_KERNEL);
if (!parts)
return -ENOMEM;
err = mtd_read(mtd, 0, sizeof(trx), &bytes_read, (uint8_t *)&trx);
if (err) {
pr_err("MTD reading error: %d\n", err);
kfree(parts);
return err;
}
if (trx.magic != TRX_MAGIC) {
kfree(parts);
return -ENOENT;
}
if (trx.offset[2]) {
part = &parts[curr_part++];
part->name = "loader";
part->offset = trx.offset[i];
i++;
}
if (trx.offset[i]) {
part = &parts[curr_part++];
part->name = "linux";
part->offset = trx.offset[i];
i++;
}
if (trx.offset[i]) {
part = &parts[curr_part++];
part->name = parser_trx_data_part_name(mtd, trx.offset[i]);
part->offset = trx.offset[i];
i++;
}
for (i = 0; i < curr_part; i++) {
u64 next_part_offset = (i < curr_part - 1) ?
parts[i + 1].offset : mtd->size;
parts[i].size = next_part_offset - parts[i].offset;
}
*pparts = parts;
return i;
}
