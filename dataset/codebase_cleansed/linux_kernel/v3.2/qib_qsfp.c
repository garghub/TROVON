static int qsfp_read(struct qib_pportdata *ppd, int addr, void *bp, int len)
{
struct qib_devdata *dd = ppd->dd;
u32 out, mask;
int ret, cnt, pass = 0;
int stuck = 0;
u8 *buff = bp;
ret = mutex_lock_interruptible(&dd->eep_lock);
if (ret)
goto no_unlock;
if (dd->twsi_eeprom_dev == QIB_TWSI_NO_DEV) {
ret = -ENXIO;
goto bail;
}
mask = QSFP_GPIO_MOD_SEL_N | QSFP_GPIO_MOD_RST_N | QSFP_GPIO_LP_MODE;
out = QSFP_GPIO_MOD_RST_N | QSFP_GPIO_LP_MODE;
if (ppd->hw_pidx) {
mask <<= QSFP_GPIO_PORT2_SHIFT;
out <<= QSFP_GPIO_PORT2_SHIFT;
}
dd->f_gpio_mod(dd, out, mask, mask);
msleep(2);
ret = qib_twsi_reset(dd);
if (ret) {
qib_dev_porterr(dd, ppd->port,
"QSFP interface Reset for read failed\n");
ret = -EIO;
stuck = 1;
goto deselect;
}
cnt = 0;
while (cnt < len) {
unsigned in_page;
int wlen = len - cnt;
in_page = addr % QSFP_PAGESIZE;
if ((in_page + wlen) > QSFP_PAGESIZE)
wlen = QSFP_PAGESIZE - in_page;
ret = qib_twsi_blk_rd(dd, QSFP_DEV, addr, buff + cnt, wlen);
if (ret && cnt == 0 && ++pass < QSFP_MAX_RETRY)
continue;
if (ret) {
ret = -EIO;
goto deselect;
}
addr += wlen;
cnt += wlen;
}
ret = cnt;
deselect:
udelay(10);
dd->f_gpio_mod(dd, mask, mask, mask);
if (stuck)
qib_dev_err(dd, "QSFP interface bus stuck non-idle\n");
if (pass >= QSFP_MAX_RETRY && ret)
qib_dev_porterr(dd, ppd->port, "QSFP failed even retrying\n");
else if (pass)
qib_dev_porterr(dd, ppd->port, "QSFP retries: %d\n", pass);
msleep(2);
bail:
mutex_unlock(&dd->eep_lock);
no_unlock:
return ret;
}
static int qib_qsfp_write(struct qib_pportdata *ppd, int addr, void *bp,
int len)
{
struct qib_devdata *dd = ppd->dd;
u32 out, mask;
int ret, cnt;
u8 *buff = bp;
ret = mutex_lock_interruptible(&dd->eep_lock);
if (ret)
goto no_unlock;
if (dd->twsi_eeprom_dev == QIB_TWSI_NO_DEV) {
ret = -ENXIO;
goto bail;
}
mask = QSFP_GPIO_MOD_SEL_N | QSFP_GPIO_MOD_RST_N | QSFP_GPIO_LP_MODE;
out = QSFP_GPIO_MOD_RST_N | QSFP_GPIO_LP_MODE;
if (ppd->hw_pidx) {
mask <<= QSFP_GPIO_PORT2_SHIFT;
out <<= QSFP_GPIO_PORT2_SHIFT;
}
dd->f_gpio_mod(dd, out, mask, mask);
msleep(2);
ret = qib_twsi_reset(dd);
if (ret) {
qib_dev_porterr(dd, ppd->port,
"QSFP interface Reset for write failed\n");
ret = -EIO;
goto deselect;
}
cnt = 0;
while (cnt < len) {
unsigned in_page;
int wlen = len - cnt;
in_page = addr % QSFP_PAGESIZE;
if ((in_page + wlen) > QSFP_PAGESIZE)
wlen = QSFP_PAGESIZE - in_page;
ret = qib_twsi_blk_wr(dd, QSFP_DEV, addr, buff + cnt, wlen);
if (ret) {
ret = -EIO;
goto deselect;
}
addr += wlen;
cnt += wlen;
}
ret = cnt;
deselect:
udelay(10);
dd->f_gpio_mod(dd, mask, mask, mask);
msleep(2);
bail:
mutex_unlock(&dd->eep_lock);
no_unlock:
return ret;
}
static int qsfp_cks(struct qib_pportdata *ppd, int first, int next)
{
int ret;
u16 cks;
u8 bval;
cks = 0;
while (first < next) {
ret = qsfp_read(ppd, first, &bval, 1);
if (ret < 0)
goto bail;
cks += bval;
++first;
}
ret = cks & 0xFF;
bail:
return ret;
}
int qib_refresh_qsfp_cache(struct qib_pportdata *ppd, struct qib_qsfp_cache *cp)
{
int ret;
int idx;
u16 cks;
u8 peek[4];
memset(cp, 0, sizeof(*cp));
if (!qib_qsfp_mod_present(ppd)) {
ret = -ENODEV;
goto bail;
}
ret = qsfp_read(ppd, 0, peek, 3);
if (ret < 0)
goto bail;
if ((peek[0] & 0xFE) != 0x0C)
qib_dev_porterr(ppd->dd, ppd->port,
"QSFP byte0 is 0x%02X, S/B 0x0C/D\n", peek[0]);
if ((peek[2] & 2) == 0) {
u8 poke = 0;
ret = qib_qsfp_write(ppd, 127, &poke, 1);
udelay(50);
if (ret != 1) {
qib_dev_porterr(ppd->dd, ppd->port,
"Failed QSFP Page set\n");
goto bail;
}
}
ret = qsfp_read(ppd, QSFP_MOD_ID_OFFS, &cp->id, 1);
if (ret < 0)
goto bail;
if ((cp->id & 0xFE) != 0x0C)
qib_dev_porterr(ppd->dd, ppd->port,
"QSFP ID byte is 0x%02X, S/B 0x0C/D\n", cp->id);
cks = cp->id;
ret = qsfp_read(ppd, QSFP_MOD_PWR_OFFS, &cp->pwr, 1);
if (ret < 0)
goto bail;
cks += cp->pwr;
ret = qsfp_cks(ppd, QSFP_MOD_PWR_OFFS + 1, QSFP_MOD_LEN_OFFS);
if (ret < 0)
goto bail;
cks += ret;
ret = qsfp_read(ppd, QSFP_MOD_LEN_OFFS, &cp->len, 1);
if (ret < 0)
goto bail;
cks += cp->len;
ret = qsfp_read(ppd, QSFP_MOD_TECH_OFFS, &cp->tech, 1);
if (ret < 0)
goto bail;
cks += cp->tech;
ret = qsfp_read(ppd, QSFP_VEND_OFFS, &cp->vendor, QSFP_VEND_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_VEND_LEN; ++idx)
cks += cp->vendor[idx];
ret = qsfp_read(ppd, QSFP_IBXCV_OFFS, &cp->xt_xcv, 1);
if (ret < 0)
goto bail;
cks += cp->xt_xcv;
ret = qsfp_read(ppd, QSFP_VOUI_OFFS, &cp->oui, QSFP_VOUI_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_VOUI_LEN; ++idx)
cks += cp->oui[idx];
ret = qsfp_read(ppd, QSFP_PN_OFFS, &cp->partnum, QSFP_PN_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_PN_LEN; ++idx)
cks += cp->partnum[idx];
ret = qsfp_read(ppd, QSFP_REV_OFFS, &cp->rev, QSFP_REV_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_REV_LEN; ++idx)
cks += cp->rev[idx];
ret = qsfp_read(ppd, QSFP_ATTEN_OFFS, &cp->atten, QSFP_ATTEN_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_ATTEN_LEN; ++idx)
cks += cp->atten[idx];
ret = qsfp_cks(ppd, QSFP_ATTEN_OFFS + QSFP_ATTEN_LEN, QSFP_CC_OFFS);
if (ret < 0)
goto bail;
cks += ret;
cks &= 0xFF;
ret = qsfp_read(ppd, QSFP_CC_OFFS, &cp->cks1, 1);
if (ret < 0)
goto bail;
if (cks != cp->cks1)
qib_dev_porterr(ppd->dd, ppd->port,
"QSFP cks1 is %02X, computed %02X\n", cp->cks1,
cks);
ret = qsfp_cks(ppd, QSFP_CC_OFFS + 1, QSFP_SN_OFFS);
if (ret < 0)
goto bail;
cks = ret;
ret = qsfp_read(ppd, QSFP_SN_OFFS, &cp->serial, QSFP_SN_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_SN_LEN; ++idx)
cks += cp->serial[idx];
ret = qsfp_read(ppd, QSFP_DATE_OFFS, &cp->date, QSFP_DATE_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_DATE_LEN; ++idx)
cks += cp->date[idx];
ret = qsfp_read(ppd, QSFP_LOT_OFFS, &cp->lot, QSFP_LOT_LEN);
if (ret < 0)
goto bail;
for (idx = 0; idx < QSFP_LOT_LEN; ++idx)
cks += cp->lot[idx];
ret = qsfp_cks(ppd, QSFP_LOT_OFFS + QSFP_LOT_LEN, QSFP_CC_EXT_OFFS);
if (ret < 0)
goto bail;
cks += ret;
ret = qsfp_read(ppd, QSFP_CC_EXT_OFFS, &cp->cks2, 1);
if (ret < 0)
goto bail;
cks &= 0xFF;
if (cks != cp->cks2)
qib_dev_porterr(ppd->dd, ppd->port,
"QSFP cks2 is %02X, computed %02X\n", cp->cks2,
cks);
return 0;
bail:
cp->id = 0;
return ret;
}
int qib_qsfp_mod_present(struct qib_pportdata *ppd)
{
u32 mask;
int ret;
mask = QSFP_GPIO_MOD_PRS_N <<
(ppd->hw_pidx * QSFP_GPIO_PORT2_SHIFT);
ret = ppd->dd->f_gpio_mod(ppd->dd, 0, 0, 0);
return !((ret & mask) >>
((ppd->hw_pidx * QSFP_GPIO_PORT2_SHIFT) + 3));
}
void qib_qsfp_init(struct qib_qsfp_data *qd,
void (*fevent)(struct work_struct *))
{
u32 mask, highs;
struct qib_devdata *dd = qd->ppd->dd;
INIT_WORK(&qd->work, fevent);
mask = QSFP_GPIO_MOD_SEL_N | QSFP_GPIO_MOD_RST_N | QSFP_GPIO_LP_MODE;
highs = mask - QSFP_GPIO_MOD_RST_N;
if (qd->ppd->hw_pidx) {
mask <<= QSFP_GPIO_PORT2_SHIFT;
highs <<= QSFP_GPIO_PORT2_SHIFT;
}
dd->f_gpio_mod(dd, highs, mask, mask);
udelay(20);
dd->f_gpio_mod(dd, mask, mask, mask);
return;
}
void qib_qsfp_deinit(struct qib_qsfp_data *qd)
{
}
int qib_qsfp_dump(struct qib_pportdata *ppd, char *buf, int len)
{
struct qib_qsfp_cache cd;
u8 bin_buff[QSFP_DUMP_CHUNK];
char lenstr[6];
int sofar, ret;
int bidx = 0;
sofar = 0;
ret = qib_refresh_qsfp_cache(ppd, &cd);
if (ret < 0)
goto bail;
lenstr[0] = ' ';
lenstr[1] = '\0';
if (QSFP_IS_CU(cd.tech))
sprintf(lenstr, "%dM ", cd.len);
sofar += scnprintf(buf + sofar, len - sofar, "PWR:%.3sW\n", pwr_codes +
(QSFP_PWR(cd.pwr) * 4));
sofar += scnprintf(buf + sofar, len - sofar, "TECH:%s%s\n", lenstr,
qib_qsfp_devtech[cd.tech >> 4]);
sofar += scnprintf(buf + sofar, len - sofar, "Vendor:%.*s\n",
QSFP_VEND_LEN, cd.vendor);
sofar += scnprintf(buf + sofar, len - sofar, "OUI:%06X\n",
QSFP_OUI(cd.oui));
sofar += scnprintf(buf + sofar, len - sofar, "Part#:%.*s\n",
QSFP_PN_LEN, cd.partnum);
sofar += scnprintf(buf + sofar, len - sofar, "Rev:%.*s\n",
QSFP_REV_LEN, cd.rev);
if (QSFP_IS_CU(cd.tech))
sofar += scnprintf(buf + sofar, len - sofar, "Atten:%d, %d\n",
QSFP_ATTEN_SDR(cd.atten),
QSFP_ATTEN_DDR(cd.atten));
sofar += scnprintf(buf + sofar, len - sofar, "Serial:%.*s\n",
QSFP_SN_LEN, cd.serial);
sofar += scnprintf(buf + sofar, len - sofar, "Date:%.*s\n",
QSFP_DATE_LEN, cd.date);
sofar += scnprintf(buf + sofar, len - sofar, "Lot:%.*s\n",
QSFP_LOT_LEN, cd.date);
while (bidx < QSFP_DEFAULT_HDR_CNT) {
int iidx;
ret = qsfp_read(ppd, bidx, bin_buff, QSFP_DUMP_CHUNK);
if (ret < 0)
goto bail;
for (iidx = 0; iidx < ret; ++iidx) {
sofar += scnprintf(buf + sofar, len-sofar, " %02X",
bin_buff[iidx]);
}
sofar += scnprintf(buf + sofar, len - sofar, "\n");
bidx += QSFP_DUMP_CHUNK;
}
ret = sofar;
bail:
return ret;
}
