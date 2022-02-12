static int __i2c_write(struct hfi1_pportdata *ppd, u32 target, int i2c_addr,
int offset, void *bp, int len)
{
struct hfi1_devdata *dd = ppd->dd;
int ret, cnt;
u8 *buff = bp;
cnt = 0;
while (cnt < len) {
int wlen = len - cnt;
ret = hfi1_twsi_blk_wr(dd, target, i2c_addr, offset,
buff + cnt, wlen);
if (ret) {
return -EIO;
}
offset += wlen;
cnt += wlen;
}
udelay(20);
return cnt;
}
int i2c_write(struct hfi1_pportdata *ppd, u32 target, int i2c_addr, int offset,
void *bp, int len)
{
int ret;
if (!check_chip_resource(ppd->dd, i2c_target(target), __func__))
return -EACCES;
ret = hfi1_twsi_reset(ppd->dd, target);
if (ret) {
hfi1_dev_porterr(ppd->dd, ppd->port,
"I2C chain %d write interface reset failed\n",
target);
return ret;
}
return __i2c_write(ppd, target, i2c_addr, offset, bp, len);
}
static int __i2c_read(struct hfi1_pportdata *ppd, u32 target, int i2c_addr,
int offset, void *bp, int len)
{
struct hfi1_devdata *dd = ppd->dd;
int ret, cnt, pass = 0;
int orig_offset = offset;
cnt = 0;
while (cnt < len) {
int rlen = len - cnt;
ret = hfi1_twsi_blk_rd(dd, target, i2c_addr, offset,
bp + cnt, rlen);
if (ret && cnt == 0 && ++pass < I2C_MAX_RETRY)
continue;
if (ret) {
ret = -EIO;
goto exit;
}
offset += rlen;
cnt += rlen;
}
ret = cnt;
exit:
if (ret < 0) {
hfi1_dev_porterr(dd, ppd->port,
"I2C chain %d read failed, addr 0x%x, offset 0x%x, len %d\n",
target, i2c_addr, orig_offset, len);
}
udelay(20);
return ret;
}
int i2c_read(struct hfi1_pportdata *ppd, u32 target, int i2c_addr, int offset,
void *bp, int len)
{
int ret;
if (!check_chip_resource(ppd->dd, i2c_target(target), __func__))
return -EACCES;
ret = hfi1_twsi_reset(ppd->dd, target);
if (ret) {
hfi1_dev_porterr(ppd->dd, ppd->port,
"I2C chain %d read interface reset failed\n",
target);
return ret;
}
return __i2c_read(ppd, target, i2c_addr, offset, bp, len);
}
int qsfp_write(struct hfi1_pportdata *ppd, u32 target, int addr, void *bp,
int len)
{
int count = 0;
int offset;
int nwrite;
int ret;
u8 page;
if (!check_chip_resource(ppd->dd, i2c_target(target), __func__))
return -EACCES;
ret = hfi1_twsi_reset(ppd->dd, target);
if (ret) {
hfi1_dev_porterr(ppd->dd, ppd->port,
"QSFP chain %d write interface reset failed\n",
target);
return ret;
}
while (count < len) {
page = (u8)(addr / QSFP_PAGESIZE);
ret = __i2c_write(ppd, target, QSFP_DEV | QSFP_OFFSET_SIZE,
QSFP_PAGE_SELECT_BYTE_OFFS, &page, 1);
if (ret != 1) {
hfi1_dev_porterr(ppd->dd, ppd->port,
"QSFP chain %d can't write QSFP_PAGE_SELECT_BYTE: %d\n",
target, ret);
ret = -EIO;
break;
}
offset = addr % QSFP_PAGESIZE;
nwrite = len - count;
if (((addr % QSFP_RW_BOUNDARY) + nwrite) > QSFP_RW_BOUNDARY)
nwrite = QSFP_RW_BOUNDARY - (addr % QSFP_RW_BOUNDARY);
ret = __i2c_write(ppd, target, QSFP_DEV | QSFP_OFFSET_SIZE,
offset, bp + count, nwrite);
if (ret <= 0)
break;
count += ret;
addr += ret;
}
if (ret < 0)
return ret;
return count;
}
int one_qsfp_write(struct hfi1_pportdata *ppd, u32 target, int addr, void *bp,
int len)
{
struct hfi1_devdata *dd = ppd->dd;
u32 resource = qsfp_resource(dd);
int ret;
ret = acquire_chip_resource(dd, resource, QSFP_WAIT);
if (ret)
return ret;
ret = qsfp_write(ppd, target, addr, bp, len);
release_chip_resource(dd, resource);
return ret;
}
int qsfp_read(struct hfi1_pportdata *ppd, u32 target, int addr, void *bp,
int len)
{
int count = 0;
int offset;
int nread;
int ret;
u8 page;
if (!check_chip_resource(ppd->dd, i2c_target(target), __func__))
return -EACCES;
ret = hfi1_twsi_reset(ppd->dd, target);
if (ret) {
hfi1_dev_porterr(ppd->dd, ppd->port,
"QSFP chain %d read interface reset failed\n",
target);
return ret;
}
while (count < len) {
page = (u8)(addr / QSFP_PAGESIZE);
ret = __i2c_write(ppd, target, QSFP_DEV | QSFP_OFFSET_SIZE,
QSFP_PAGE_SELECT_BYTE_OFFS, &page, 1);
if (ret != 1) {
hfi1_dev_porterr(ppd->dd, ppd->port,
"QSFP chain %d can't write QSFP_PAGE_SELECT_BYTE: %d\n",
target, ret);
ret = -EIO;
break;
}
offset = addr % QSFP_PAGESIZE;
nread = len - count;
if (((addr % QSFP_RW_BOUNDARY) + nread) > QSFP_RW_BOUNDARY)
nread = QSFP_RW_BOUNDARY - (addr % QSFP_RW_BOUNDARY);
mdelay(5);
ret = __i2c_read(ppd, target, QSFP_DEV | QSFP_OFFSET_SIZE,
offset, bp + count, nread);
if (ret <= 0)
break;
count += ret;
addr += ret;
}
if (ret < 0)
return ret;
return count;
}
int one_qsfp_read(struct hfi1_pportdata *ppd, u32 target, int addr, void *bp,
int len)
{
struct hfi1_devdata *dd = ppd->dd;
u32 resource = qsfp_resource(dd);
int ret;
ret = acquire_chip_resource(dd, resource, QSFP_WAIT);
if (ret)
return ret;
ret = qsfp_read(ppd, target, addr, bp, len);
release_chip_resource(dd, resource);
return ret;
}
int refresh_qsfp_cache(struct hfi1_pportdata *ppd, struct qsfp_data *cp)
{
u32 target = ppd->dd->hfi1_id;
int ret;
unsigned long flags;
u8 *cache = &cp->cache[0];
memset(cache, 0, (QSFP_MAX_NUM_PAGES * 128));
spin_lock_irqsave(&ppd->qsfp_info.qsfp_lock, flags);
ppd->qsfp_info.cache_valid = 0;
spin_unlock_irqrestore(&ppd->qsfp_info.qsfp_lock, flags);
if (!qsfp_mod_present(ppd)) {
ret = -ENODEV;
goto bail;
}
ret = qsfp_read(ppd, target, 0, cache, QSFP_PAGESIZE);
if (ret != QSFP_PAGESIZE) {
dd_dev_info(ppd->dd,
"%s: Page 0 read failed, expected %d, got %d\n",
__func__, QSFP_PAGESIZE, ret);
goto bail;
}
if (!(cache[2] & 4)) {
if ((cache[195] & 0xC0) == 0xC0) {
ret = qsfp_read(ppd, target, 384, cache + 256, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
ret = qsfp_read(ppd, target, 640, cache + 384, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
ret = qsfp_read(ppd, target, 896, cache + 512, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
} else if ((cache[195] & 0x80) == 0x80) {
ret = qsfp_read(ppd, target, 640, cache + 384, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
ret = qsfp_read(ppd, target, 896, cache + 512, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
} else if ((cache[195] & 0x40) == 0x40) {
ret = qsfp_read(ppd, target, 384, cache + 256, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
ret = qsfp_read(ppd, target, 896, cache + 512, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
} else {
ret = qsfp_read(ppd, target, 896, cache + 512, 128);
if (ret <= 0 || ret != 128) {
dd_dev_info(ppd->dd, "%s failed\n", __func__);
goto bail;
}
}
}
spin_lock_irqsave(&ppd->qsfp_info.qsfp_lock, flags);
ppd->qsfp_info.cache_valid = 1;
ppd->qsfp_info.cache_refresh_required = 0;
spin_unlock_irqrestore(&ppd->qsfp_info.qsfp_lock, flags);
return 0;
bail:
memset(cache, 0, (QSFP_MAX_NUM_PAGES * 128));
return ret;
}
int get_qsfp_power_class(u8 power_byte)
{
if (QSFP_HIGH_PWR(power_byte) == QSFP_HIGH_PWR_UNUSED)
return (QSFP_PWR(power_byte) + 1);
return (QSFP_HIGH_PWR(power_byte) + 4);
}
int qsfp_mod_present(struct hfi1_pportdata *ppd)
{
struct hfi1_devdata *dd = ppd->dd;
u64 reg;
reg = read_csr(dd, dd->hfi1_id ? ASIC_QSFP2_IN : ASIC_QSFP1_IN);
return !(reg & QSFP_HFI0_MODPRST_N);
}
int get_cable_info(struct hfi1_devdata *dd, u32 port_num, u32 addr, u32 len,
u8 *data)
{
struct hfi1_pportdata *ppd;
u32 excess_len = 0;
int ret = 0;
if (port_num > dd->num_pports || port_num < 1) {
dd_dev_info(dd, "%s: Invalid port number %d\n",
__func__, port_num);
ret = -EINVAL;
goto set_zeroes;
}
ppd = dd->pport + (port_num - 1);
if (!qsfp_mod_present(ppd)) {
ret = -ENODEV;
goto set_zeroes;
}
if (!ppd->qsfp_info.cache_valid) {
ret = -EINVAL;
goto set_zeroes;
}
if (addr >= (QSFP_MAX_NUM_PAGES * 128)) {
ret = -ERANGE;
goto set_zeroes;
}
if ((addr + len) > (QSFP_MAX_NUM_PAGES * 128)) {
excess_len = (addr + len) - (QSFP_MAX_NUM_PAGES * 128);
memcpy(data, &ppd->qsfp_info.cache[addr], (len - excess_len));
data += (len - excess_len);
goto set_zeroes;
}
memcpy(data, &ppd->qsfp_info.cache[addr], len);
return 0;
set_zeroes:
memset(data, 0, excess_len);
return ret;
}
int qsfp_dump(struct hfi1_pportdata *ppd, char *buf, int len)
{
u8 *cache = &ppd->qsfp_info.cache[0];
u8 bin_buff[QSFP_DUMP_CHUNK];
char lenstr[6];
int sofar;
int bidx = 0;
u8 *atten = &cache[QSFP_ATTEN_OFFS];
u8 *vendor_oui = &cache[QSFP_VOUI_OFFS];
u8 power_byte = 0;
sofar = 0;
lenstr[0] = ' ';
lenstr[1] = '\0';
if (ppd->qsfp_info.cache_valid) {
if (QSFP_IS_CU(cache[QSFP_MOD_TECH_OFFS]))
snprintf(lenstr, sizeof(lenstr), "%dM ",
cache[QSFP_MOD_LEN_OFFS]);
power_byte = cache[QSFP_MOD_PWR_OFFS];
sofar += scnprintf(buf + sofar, len - sofar, "PWR:%.3sW\n",
pwr_codes[get_qsfp_power_class(power_byte)]);
sofar += scnprintf(buf + sofar, len - sofar, "TECH:%s%s\n",
lenstr,
hfi1_qsfp_devtech[(cache[QSFP_MOD_TECH_OFFS]) >> 4]);
sofar += scnprintf(buf + sofar, len - sofar, "Vendor:%.*s\n",
QSFP_VEND_LEN, &cache[QSFP_VEND_OFFS]);
sofar += scnprintf(buf + sofar, len - sofar, "OUI:%06X\n",
QSFP_OUI(vendor_oui));
sofar += scnprintf(buf + sofar, len - sofar, "Part#:%.*s\n",
QSFP_PN_LEN, &cache[QSFP_PN_OFFS]);
sofar += scnprintf(buf + sofar, len - sofar, "Rev:%.*s\n",
QSFP_REV_LEN, &cache[QSFP_REV_OFFS]);
if (QSFP_IS_CU(cache[QSFP_MOD_TECH_OFFS]))
sofar += scnprintf(buf + sofar, len - sofar,
"Atten:%d, %d\n",
QSFP_ATTEN_SDR(atten),
QSFP_ATTEN_DDR(atten));
sofar += scnprintf(buf + sofar, len - sofar, "Serial:%.*s\n",
QSFP_SN_LEN, &cache[QSFP_SN_OFFS]);
sofar += scnprintf(buf + sofar, len - sofar, "Date:%.*s\n",
QSFP_DATE_LEN, &cache[QSFP_DATE_OFFS]);
sofar += scnprintf(buf + sofar, len - sofar, "Lot:%.*s\n",
QSFP_LOT_LEN, &cache[QSFP_LOT_OFFS]);
while (bidx < QSFP_DEFAULT_HDR_CNT) {
int iidx;
memcpy(bin_buff, &cache[bidx], QSFP_DUMP_CHUNK);
for (iidx = 0; iidx < QSFP_DUMP_CHUNK; ++iidx) {
sofar += scnprintf(buf + sofar, len - sofar,
" %02X", bin_buff[iidx]);
}
sofar += scnprintf(buf + sofar, len - sofar, "\n");
bidx += QSFP_DUMP_CHUNK;
}
}
return sofar;
}
