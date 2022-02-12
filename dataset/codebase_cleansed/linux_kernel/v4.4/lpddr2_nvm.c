static inline map_word build_map_word(u_long myword)
{
map_word val = { {0} };
val.x[0] = myword;
return val;
}
static inline u_int build_mr_cfgmask(u_int bus_width)
{
u_int val = MR_CFGMASK;
if (bus_width == 0x0004)
val = val << 16;
return val;
}
static inline u_int build_sr_ok_datamask(u_int bus_width)
{
u_int val = SR_OK_DATAMASK;
if (bus_width == 0x0004)
val = (val << 16)+val;
return val;
}
static inline u_long ow_reg_add(struct map_info *map, u_long offset)
{
u_long val = 0;
struct pcm_int_data *pcm_data = map->fldrv_priv;
val = map->pfow_base + offset*pcm_data->bus_width;
return val;
}
static inline void ow_enable(struct map_info *map)
{
struct pcm_int_data *pcm_data = map->fldrv_priv;
writel_relaxed(build_mr_cfgmask(pcm_data->bus_width) | 0x18,
pcm_data->ctl_regs + LPDDR2_MODE_REG_CFG);
writel_relaxed(0x01, pcm_data->ctl_regs + LPDDR2_MODE_REG_DATA);
}
static inline void ow_disable(struct map_info *map)
{
struct pcm_int_data *pcm_data = map->fldrv_priv;
writel_relaxed(build_mr_cfgmask(pcm_data->bus_width) | 0x18,
pcm_data->ctl_regs + LPDDR2_MODE_REG_CFG);
writel_relaxed(0x02, pcm_data->ctl_regs + LPDDR2_MODE_REG_DATA);
}
static int lpddr2_nvm_do_op(struct map_info *map, u_long cmd_code,
u_long cmd_data, u_long cmd_add, u_long cmd_mpr, u_char *buf)
{
map_word add_l = { {0} }, add_h = { {0} }, mpr_l = { {0} },
mpr_h = { {0} }, data_l = { {0} }, cmd = { {0} },
exec_cmd = { {0} }, sr;
map_word data_h = { {0} };
u_long i, status_reg, prg_buff_ofs;
struct pcm_int_data *pcm_data = map->fldrv_priv;
u_int sr_ok_datamask = build_sr_ok_datamask(pcm_data->bus_width);
add_l.x[0] = cmd_add & 0x0000FFFF;
add_h.x[0] = (cmd_add >> 16) & 0x0000FFFF;
mpr_l.x[0] = cmd_mpr & 0x0000FFFF;
mpr_h.x[0] = (cmd_mpr >> 16) & 0x0000FFFF;
cmd.x[0] = cmd_code & 0x0000FFFF;
exec_cmd.x[0] = 0x0001;
data_l.x[0] = cmd_data & 0x0000FFFF;
data_h.x[0] = (cmd_data >> 16) & 0x0000FFFF;
map_write(map, cmd, ow_reg_add(map, CMD_CODE_OFS));
map_write(map, data_l, ow_reg_add(map, CMD_DATA_OFS));
map_write(map, add_l, ow_reg_add(map, CMD_ADD_L_OFS));
map_write(map, add_h, ow_reg_add(map, CMD_ADD_H_OFS));
map_write(map, mpr_l, ow_reg_add(map, MPR_L_OFS));
map_write(map, mpr_h, ow_reg_add(map, MPR_H_OFS));
if (pcm_data->bus_width == 0x0004) {
map_write(map, cmd, ow_reg_add(map, CMD_CODE_OFS) + 2);
map_write(map, data_h, ow_reg_add(map, CMD_DATA_OFS) + 2);
map_write(map, add_l, ow_reg_add(map, CMD_ADD_L_OFS) + 2);
map_write(map, add_h, ow_reg_add(map, CMD_ADD_H_OFS) + 2);
map_write(map, mpr_l, ow_reg_add(map, MPR_L_OFS) + 2);
map_write(map, mpr_h, ow_reg_add(map, MPR_H_OFS) + 2);
}
if ((cmd_code == LPDDR2_NVM_BUF_PROGRAM) ||
(cmd_code == LPDDR2_NVM_BUF_OVERWRITE)) {
prg_buff_ofs = (map_read(map,
ow_reg_add(map, PRG_BUFFER_OFS))).x[0];
for (i = 0; i < cmd_mpr; i++) {
map_write(map, build_map_word(buf[i]), map->pfow_base +
prg_buff_ofs + i);
}
}
map_write(map, exec_cmd, ow_reg_add(map, CMD_EXEC_OFS));
if (pcm_data->bus_width == 0x0004)
map_write(map, exec_cmd, ow_reg_add(map, CMD_EXEC_OFS) + 2);
do {
sr = map_read(map, ow_reg_add(map, STATUS_REG_OFS));
status_reg = sr.x[0];
if (pcm_data->bus_width == 0x0004) {
sr = map_read(map, ow_reg_add(map,
STATUS_REG_OFS) + 2);
status_reg += sr.x[0] << 16;
}
} while ((status_reg & sr_ok_datamask) != sr_ok_datamask);
return (((status_reg & sr_ok_datamask) == sr_ok_datamask) ? 0 : -EIO);
}
static int lpddr2_nvm_do_block_op(struct mtd_info *mtd, loff_t start_add,
uint64_t len, u_char block_op)
{
struct map_info *map = mtd->priv;
u_long add, end_add;
int ret = 0;
mutex_lock(&lpdd2_nvm_mutex);
ow_enable(map);
add = start_add;
end_add = add + len;
do {
ret = lpddr2_nvm_do_op(map, block_op, 0x00, add, add, NULL);
if (ret)
goto out;
add += mtd->erasesize;
} while (add < end_add);
out:
ow_disable(map);
mutex_unlock(&lpdd2_nvm_mutex);
return ret;
}
static int lpddr2_nvm_pfow_present(struct map_info *map)
{
map_word pfow_val[4];
unsigned int found = 1;
mutex_lock(&lpdd2_nvm_mutex);
ow_enable(map);
pfow_val[0] = map_read(map, ow_reg_add(map, PFOW_QUERY_STRING_P));
pfow_val[1] = map_read(map, ow_reg_add(map, PFOW_QUERY_STRING_F));
pfow_val[2] = map_read(map, ow_reg_add(map, PFOW_QUERY_STRING_O));
pfow_val[3] = map_read(map, ow_reg_add(map, PFOW_QUERY_STRING_W));
if (!map_word_equal(map, build_map_word('P'), pfow_val[0]))
found = 0;
if (!map_word_equal(map, build_map_word('F'), pfow_val[1]))
found = 0;
if (!map_word_equal(map, build_map_word('O'), pfow_val[2]))
found = 0;
if (!map_word_equal(map, build_map_word('W'), pfow_val[3]))
found = 0;
ow_disable(map);
mutex_unlock(&lpdd2_nvm_mutex);
return found;
}
static int lpddr2_nvm_read(struct mtd_info *mtd, loff_t start_add,
size_t len, size_t *retlen, u_char *buf)
{
struct map_info *map = mtd->priv;
mutex_lock(&lpdd2_nvm_mutex);
*retlen = len;
map_copy_from(map, buf, start_add, *retlen);
mutex_unlock(&lpdd2_nvm_mutex);
return 0;
}
static int lpddr2_nvm_write(struct mtd_info *mtd, loff_t start_add,
size_t len, size_t *retlen, const u_char *buf)
{
struct map_info *map = mtd->priv;
struct pcm_int_data *pcm_data = map->fldrv_priv;
u_long add, current_len, tot_len, target_len, my_data;
u_char *write_buf = (u_char *)buf;
int ret = 0;
mutex_lock(&lpdd2_nvm_mutex);
ow_enable(map);
add = start_add;
target_len = len;
tot_len = 0;
while (tot_len < target_len) {
if (!(IS_ALIGNED(add, mtd->writesize))) {
my_data = write_buf[tot_len];
my_data += (write_buf[tot_len+1]) << 8;
if (pcm_data->bus_width == 0x0004) {
my_data += (write_buf[tot_len+2]) << 16;
my_data += (write_buf[tot_len+3]) << 24;
}
ret = lpddr2_nvm_do_op(map, LPDDR2_NVM_SW_OVERWRITE,
my_data, add, 0x00, NULL);
if (ret)
goto out;
add += pcm_data->bus_width;
tot_len += pcm_data->bus_width;
} else {
current_len = min(target_len - tot_len,
(u_long) mtd->writesize);
ret = lpddr2_nvm_do_op(map, LPDDR2_NVM_BUF_OVERWRITE,
0x00, add, current_len, write_buf + tot_len);
if (ret)
goto out;
add += current_len;
tot_len += current_len;
}
}
out:
*retlen = tot_len;
ow_disable(map);
mutex_unlock(&lpdd2_nvm_mutex);
return ret;
}
static int lpddr2_nvm_erase(struct mtd_info *mtd, struct erase_info *instr)
{
int ret = lpddr2_nvm_do_block_op(mtd, instr->addr, instr->len,
LPDDR2_NVM_ERASE);
if (!ret) {
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
}
return ret;
}
static int lpddr2_nvm_unlock(struct mtd_info *mtd, loff_t start_add,
uint64_t len)
{
return lpddr2_nvm_do_block_op(mtd, start_add, len, LPDDR2_NVM_UNLOCK);
}
static int lpddr2_nvm_lock(struct mtd_info *mtd, loff_t start_add,
uint64_t len)
{
return lpddr2_nvm_do_block_op(mtd, start_add, len, LPDDR2_NVM_LOCK);
}
static int lpddr2_nvm_probe(struct platform_device *pdev)
{
struct map_info *map;
struct mtd_info *mtd;
struct resource *add_range;
struct resource *control_regs;
struct pcm_int_data *pcm_data;
pcm_data = devm_kzalloc(&pdev->dev, sizeof(*pcm_data), GFP_KERNEL);
if (!pcm_data)
return -ENOMEM;
pcm_data->bus_width = BUS_WIDTH;
map = devm_kzalloc(&pdev->dev, sizeof(*map), GFP_KERNEL);
if (!map)
return -ENOMEM;
mtd = devm_kzalloc(&pdev->dev, sizeof(*mtd), GFP_KERNEL);
if (!mtd)
return -ENOMEM;
add_range = platform_get_resource(pdev, IORESOURCE_MEM, 0);
*map = (struct map_info) {
.virt = devm_ioremap_resource(&pdev->dev, add_range),
.name = pdev->dev.init_name,
.phys = add_range->start,
.size = resource_size(add_range),
.bankwidth = pcm_data->bus_width / 2,
.pfow_base = OW_BASE_ADDRESS,
.fldrv_priv = pcm_data,
};
if (IS_ERR(map->virt))
return PTR_ERR(map->virt);
simple_map_init(map);
control_regs = platform_get_resource(pdev, IORESOURCE_MEM, 1);
pcm_data->ctl_regs = devm_ioremap_resource(&pdev->dev, control_regs);
if (IS_ERR(pcm_data->ctl_regs))
return PTR_ERR(pcm_data->ctl_regs);
*mtd = (struct mtd_info) {
.dev = { .parent = &pdev->dev },
.name = pdev->dev.init_name,
.type = MTD_RAM,
.priv = map,
.size = resource_size(add_range),
.erasesize = ERASE_BLOCKSIZE * pcm_data->bus_width,
.writesize = 1,
.writebufsize = WRITE_BUFFSIZE * pcm_data->bus_width,
.flags = (MTD_CAP_NVRAM | MTD_POWERUP_LOCK),
._read = lpddr2_nvm_read,
._write = lpddr2_nvm_write,
._erase = lpddr2_nvm_erase,
._unlock = lpddr2_nvm_unlock,
._lock = lpddr2_nvm_lock,
};
if (!lpddr2_nvm_pfow_present(map)) {
pr_err("device not recognized\n");
return -EINVAL;
}
return mtd_device_parse_register(mtd, NULL, NULL, NULL, 0);
}
static int lpddr2_nvm_remove(struct platform_device *pdev)
{
return mtd_device_unregister(dev_get_drvdata(&pdev->dev));
}
