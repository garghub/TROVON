static inline uint8_t bbt_get_entry(struct nand_chip *chip, int block)
{
uint8_t entry = chip->bbt[block >> BBT_ENTRY_SHIFT];
entry >>= (block & BBT_ENTRY_MASK) * 2;
return entry & BBT_ENTRY_MASK;
}
static inline void bbt_mark_entry(struct nand_chip *chip, int block,
uint8_t mark)
{
uint8_t msk = (mark & BBT_ENTRY_MASK) << ((block & BBT_ENTRY_MASK) * 2);
chip->bbt[block >> BBT_ENTRY_SHIFT] |= msk;
}
static int check_pattern_no_oob(uint8_t *buf, struct nand_bbt_descr *td)
{
if (memcmp(buf, td->pattern, td->len))
return -1;
return 0;
}
static int check_pattern(uint8_t *buf, int len, int paglen, struct nand_bbt_descr *td)
{
if (td->options & NAND_BBT_NO_OOB)
return check_pattern_no_oob(buf, td);
if (memcmp(buf + paglen + td->offs, td->pattern, td->len))
return -1;
return 0;
}
static int check_short_pattern(uint8_t *buf, struct nand_bbt_descr *td)
{
if (memcmp(buf + td->offs, td->pattern, td->len))
return -1;
return 0;
}
static u32 add_marker_len(struct nand_bbt_descr *td)
{
u32 len;
if (!(td->options & NAND_BBT_NO_OOB))
return 0;
len = td->len;
if (td->options & NAND_BBT_VERSION)
len++;
return len;
}
static int read_bbt(struct mtd_info *mtd, uint8_t *buf, int page, int num,
struct nand_bbt_descr *td, int offs)
{
int res, ret = 0, i, j, act = 0;
struct nand_chip *this = mtd->priv;
size_t retlen, len, totlen;
loff_t from;
int bits = td->options & NAND_BBT_NRBITS_MSK;
uint8_t msk = (uint8_t)((1 << bits) - 1);
u32 marker_len;
int reserved_block_code = td->reserved_block_code;
totlen = (num * bits) >> 3;
marker_len = add_marker_len(td);
from = ((loff_t)page) << this->page_shift;
while (totlen) {
len = min(totlen, (size_t)(1 << this->bbt_erase_shift));
if (marker_len) {
len -= marker_len;
from += marker_len;
marker_len = 0;
}
res = mtd_read(mtd, from, len, &retlen, buf);
if (res < 0) {
if (mtd_is_eccerr(res)) {
pr_info("nand_bbt: ECC error in BBT at "
"0x%012llx\n", from & ~mtd->writesize);
return res;
} else if (mtd_is_bitflip(res)) {
pr_info("nand_bbt: corrected error in BBT at "
"0x%012llx\n", from & ~mtd->writesize);
ret = res;
} else {
pr_info("nand_bbt: error reading BBT\n");
return res;
}
}
for (i = 0; i < len; i++) {
uint8_t dat = buf[i];
for (j = 0; j < 8; j += bits, act++) {
uint8_t tmp = (dat >> j) & msk;
if (tmp == msk)
continue;
if (reserved_block_code && (tmp == reserved_block_code)) {
pr_info("nand_read_bbt: reserved block at 0x%012llx\n",
(loff_t)(offs + act) <<
this->bbt_erase_shift);
bbt_mark_entry(this, offs + act,
BBT_BLOCK_RESERVED);
mtd->ecc_stats.bbtblocks++;
continue;
}
pr_info("nand_read_bbt: bad block at 0x%012llx\n",
(loff_t)(offs + act) <<
this->bbt_erase_shift);
if (tmp == 0)
bbt_mark_entry(this, offs + act,
BBT_BLOCK_FACTORY_BAD);
else
bbt_mark_entry(this, offs + act,
BBT_BLOCK_WORN);
mtd->ecc_stats.badblocks++;
}
}
totlen -= len;
from += len;
}
return ret;
}
static int read_abs_bbt(struct mtd_info *mtd, uint8_t *buf, struct nand_bbt_descr *td, int chip)
{
struct nand_chip *this = mtd->priv;
int res = 0, i;
if (td->options & NAND_BBT_PERCHIP) {
int offs = 0;
for (i = 0; i < this->numchips; i++) {
if (chip == -1 || chip == i)
res = read_bbt(mtd, buf, td->pages[i],
this->chipsize >> this->bbt_erase_shift,
td, offs);
if (res)
return res;
offs += this->chipsize >> this->bbt_erase_shift;
}
} else {
res = read_bbt(mtd, buf, td->pages[0],
mtd->size >> this->bbt_erase_shift, td, 0);
if (res)
return res;
}
return 0;
}
static int scan_read_data(struct mtd_info *mtd, uint8_t *buf, loff_t offs,
struct nand_bbt_descr *td)
{
size_t retlen;
size_t len;
len = td->len;
if (td->options & NAND_BBT_VERSION)
len++;
return mtd_read(mtd, offs, len, &retlen, buf);
}
static int scan_read_oob(struct mtd_info *mtd, uint8_t *buf, loff_t offs,
size_t len)
{
struct mtd_oob_ops ops;
int res, ret = 0;
ops.mode = MTD_OPS_PLACE_OOB;
ops.ooboffs = 0;
ops.ooblen = mtd->oobsize;
while (len > 0) {
ops.datbuf = buf;
ops.len = min(len, (size_t)mtd->writesize);
ops.oobbuf = buf + ops.len;
res = mtd_read_oob(mtd, offs, &ops);
if (res) {
if (!mtd_is_bitflip_or_eccerr(res))
return res;
else if (mtd_is_eccerr(res) || !ret)
ret = res;
}
buf += mtd->oobsize + mtd->writesize;
len -= mtd->writesize;
offs += mtd->writesize;
}
return ret;
}
static int scan_read(struct mtd_info *mtd, uint8_t *buf, loff_t offs,
size_t len, struct nand_bbt_descr *td)
{
if (td->options & NAND_BBT_NO_OOB)
return scan_read_data(mtd, buf, offs, td);
else
return scan_read_oob(mtd, buf, offs, len);
}
static int scan_write_bbt(struct mtd_info *mtd, loff_t offs, size_t len,
uint8_t *buf, uint8_t *oob)
{
struct mtd_oob_ops ops;
ops.mode = MTD_OPS_PLACE_OOB;
ops.ooboffs = 0;
ops.ooblen = mtd->oobsize;
ops.datbuf = buf;
ops.oobbuf = oob;
ops.len = len;
return mtd_write_oob(mtd, offs, &ops);
}
static u32 bbt_get_ver_offs(struct mtd_info *mtd, struct nand_bbt_descr *td)
{
u32 ver_offs = td->veroffs;
if (!(td->options & NAND_BBT_NO_OOB))
ver_offs += mtd->writesize;
return ver_offs;
}
static void read_abs_bbts(struct mtd_info *mtd, uint8_t *buf,
struct nand_bbt_descr *td, struct nand_bbt_descr *md)
{
struct nand_chip *this = mtd->priv;
if (td->options & NAND_BBT_VERSION) {
scan_read(mtd, buf, (loff_t)td->pages[0] << this->page_shift,
mtd->writesize, td);
td->version[0] = buf[bbt_get_ver_offs(mtd, td)];
pr_info("Bad block table at page %d, version 0x%02X\n",
td->pages[0], td->version[0]);
}
if (md && (md->options & NAND_BBT_VERSION)) {
scan_read(mtd, buf, (loff_t)md->pages[0] << this->page_shift,
mtd->writesize, md);
md->version[0] = buf[bbt_get_ver_offs(mtd, md)];
pr_info("Bad block table at page %d, version 0x%02X\n",
md->pages[0], md->version[0]);
}
}
static int scan_block_full(struct mtd_info *mtd, struct nand_bbt_descr *bd,
loff_t offs, uint8_t *buf, size_t readlen,
int scanlen, int numpages)
{
int ret, j;
ret = scan_read_oob(mtd, buf, offs, readlen);
if (ret && !mtd_is_bitflip_or_eccerr(ret))
return ret;
for (j = 0; j < numpages; j++, buf += scanlen) {
if (check_pattern(buf, scanlen, mtd->writesize, bd))
return 1;
}
return 0;
}
static int scan_block_fast(struct mtd_info *mtd, struct nand_bbt_descr *bd,
loff_t offs, uint8_t *buf, int numpages)
{
struct mtd_oob_ops ops;
int j, ret;
ops.ooblen = mtd->oobsize;
ops.oobbuf = buf;
ops.ooboffs = 0;
ops.datbuf = NULL;
ops.mode = MTD_OPS_PLACE_OOB;
for (j = 0; j < numpages; j++) {
ret = mtd_read_oob(mtd, offs, &ops);
if (ret && !mtd_is_bitflip_or_eccerr(ret))
return ret;
if (check_short_pattern(buf, bd))
return 1;
offs += mtd->writesize;
}
return 0;
}
static int create_bbt(struct mtd_info *mtd, uint8_t *buf,
struct nand_bbt_descr *bd, int chip)
{
struct nand_chip *this = mtd->priv;
int i, numblocks, numpages, scanlen;
int startblock;
loff_t from;
size_t readlen;
pr_info("Scanning device for bad blocks\n");
if (bd->options & NAND_BBT_SCANALLPAGES)
numpages = 1 << (this->bbt_erase_shift - this->page_shift);
else if (bd->options & NAND_BBT_SCAN2NDPAGE)
numpages = 2;
else
numpages = 1;
scanlen = 0;
readlen = bd->len;
if (chip == -1) {
numblocks = mtd->size >> this->bbt_erase_shift;
startblock = 0;
from = 0;
} else {
if (chip >= this->numchips) {
pr_warn("create_bbt(): chipnr (%d) > available chips (%d)\n",
chip + 1, this->numchips);
return -EINVAL;
}
numblocks = this->chipsize >> this->bbt_erase_shift;
startblock = chip * numblocks;
numblocks += startblock;
from = (loff_t)startblock << this->bbt_erase_shift;
}
if (this->bbt_options & NAND_BBT_SCANLASTPAGE)
from += mtd->erasesize - (mtd->writesize * numpages);
for (i = startblock; i < numblocks; i++) {
int ret;
BUG_ON(bd->options & NAND_BBT_NO_OOB);
if (bd->options & NAND_BBT_SCANALLPAGES)
ret = scan_block_full(mtd, bd, from, buf, readlen,
scanlen, numpages);
else
ret = scan_block_fast(mtd, bd, from, buf, numpages);
if (ret < 0)
return ret;
if (ret) {
bbt_mark_entry(this, i, BBT_BLOCK_FACTORY_BAD);
pr_warn("Bad eraseblock %d at 0x%012llx\n",
i, (unsigned long long)from);
mtd->ecc_stats.badblocks++;
}
from += (1 << this->bbt_erase_shift);
}
return 0;
}
static int search_bbt(struct mtd_info *mtd, uint8_t *buf, struct nand_bbt_descr *td)
{
struct nand_chip *this = mtd->priv;
int i, chips;
int bits, startblock, block, dir;
int scanlen = mtd->writesize + mtd->oobsize;
int bbtblocks;
int blocktopage = this->bbt_erase_shift - this->page_shift;
if (td->options & NAND_BBT_LASTBLOCK) {
startblock = (mtd->size >> this->bbt_erase_shift) - 1;
dir = -1;
} else {
startblock = 0;
dir = 1;
}
if (td->options & NAND_BBT_PERCHIP) {
chips = this->numchips;
bbtblocks = this->chipsize >> this->bbt_erase_shift;
startblock &= bbtblocks - 1;
} else {
chips = 1;
bbtblocks = mtd->size >> this->bbt_erase_shift;
}
bits = td->options & NAND_BBT_NRBITS_MSK;
for (i = 0; i < chips; i++) {
td->version[i] = 0;
td->pages[i] = -1;
for (block = 0; block < td->maxblocks; block++) {
int actblock = startblock + dir * block;
loff_t offs = (loff_t)actblock << this->bbt_erase_shift;
scan_read(mtd, buf, offs, mtd->writesize, td);
if (!check_pattern(buf, scanlen, mtd->writesize, td)) {
td->pages[i] = actblock << blocktopage;
if (td->options & NAND_BBT_VERSION) {
offs = bbt_get_ver_offs(mtd, td);
td->version[i] = buf[offs];
}
break;
}
}
startblock += this->chipsize >> this->bbt_erase_shift;
}
for (i = 0; i < chips; i++) {
if (td->pages[i] == -1)
pr_warn("Bad block table not found for chip %d\n", i);
else
pr_info("Bad block table found at page %d, version "
"0x%02X\n", td->pages[i], td->version[i]);
}
return 0;
}
static void search_read_bbts(struct mtd_info *mtd, uint8_t *buf,
struct nand_bbt_descr *td,
struct nand_bbt_descr *md)
{
search_bbt(mtd, buf, td);
if (md)
search_bbt(mtd, buf, md);
}
static int write_bbt(struct mtd_info *mtd, uint8_t *buf,
struct nand_bbt_descr *td, struct nand_bbt_descr *md,
int chipsel)
{
struct nand_chip *this = mtd->priv;
struct erase_info einfo;
int i, res, chip = 0;
int bits, startblock, dir, page, offs, numblocks, sft, sftmsk;
int nrchips, pageoffs, ooboffs;
uint8_t msk[4];
uint8_t rcode = td->reserved_block_code;
size_t retlen, len = 0;
loff_t to;
struct mtd_oob_ops ops;
ops.ooblen = mtd->oobsize;
ops.ooboffs = 0;
ops.datbuf = NULL;
ops.mode = MTD_OPS_PLACE_OOB;
if (!rcode)
rcode = 0xff;
if (td->options & NAND_BBT_PERCHIP) {
numblocks = (int)(this->chipsize >> this->bbt_erase_shift);
if (chipsel == -1) {
nrchips = this->numchips;
} else {
nrchips = chipsel + 1;
chip = chipsel;
}
} else {
numblocks = (int)(mtd->size >> this->bbt_erase_shift);
nrchips = 1;
}
for (; chip < nrchips; chip++) {
if (td->pages[chip] != -1) {
page = td->pages[chip];
goto write;
}
if (td->options & NAND_BBT_LASTBLOCK) {
startblock = numblocks * (chip + 1) - 1;
dir = -1;
} else {
startblock = chip * numblocks;
dir = 1;
}
for (i = 0; i < td->maxblocks; i++) {
int block = startblock + dir * i;
switch (bbt_get_entry(this, block)) {
case BBT_BLOCK_WORN:
case BBT_BLOCK_FACTORY_BAD:
continue;
}
page = block <<
(this->bbt_erase_shift - this->page_shift);
if (!md || md->pages[chip] != page)
goto write;
}
pr_err("No space left to write bad block table\n");
return -ENOSPC;
write:
bits = td->options & NAND_BBT_NRBITS_MSK;
msk[2] = ~rcode;
switch (bits) {
case 1: sft = 3; sftmsk = 0x07; msk[0] = 0x00; msk[1] = 0x01;
msk[3] = 0x01;
break;
case 2: sft = 2; sftmsk = 0x06; msk[0] = 0x00; msk[1] = 0x01;
msk[3] = 0x03;
break;
case 4: sft = 1; sftmsk = 0x04; msk[0] = 0x00; msk[1] = 0x0C;
msk[3] = 0x0f;
break;
case 8: sft = 0; sftmsk = 0x00; msk[0] = 0x00; msk[1] = 0x0F;
msk[3] = 0xff;
break;
default: return -EINVAL;
}
to = ((loff_t)page) << this->page_shift;
if (td->options & NAND_BBT_SAVECONTENT) {
to &= ~((loff_t)((1 << this->bbt_erase_shift) - 1));
len = 1 << this->bbt_erase_shift;
res = mtd_read(mtd, to, len, &retlen, buf);
if (res < 0) {
if (retlen != len) {
pr_info("nand_bbt: error reading block "
"for writing the bad block table\n");
return res;
}
pr_warn("nand_bbt: ECC error while reading "
"block for writing bad block table\n");
}
ops.ooblen = (len >> this->page_shift) * mtd->oobsize;
ops.oobbuf = &buf[len];
res = mtd_read_oob(mtd, to + mtd->writesize, &ops);
if (res < 0 || ops.oobretlen != ops.ooblen)
goto outerr;
pageoffs = page - (int)(to >> this->page_shift);
offs = pageoffs << this->page_shift;
memset(&buf[offs], 0xff, (size_t)(numblocks >> sft));
ooboffs = len + (pageoffs * mtd->oobsize);
} else if (td->options & NAND_BBT_NO_OOB) {
ooboffs = 0;
offs = td->len;
if (td->options & NAND_BBT_VERSION)
offs++;
len = (size_t)(numblocks >> sft);
len += offs;
len = ALIGN(len, mtd->writesize);
memset(buf, 0xff, len);
memcpy(buf, td->pattern, td->len);
} else {
len = (size_t)(numblocks >> sft);
len = ALIGN(len, mtd->writesize);
memset(buf, 0xff, len +
(len >> this->page_shift)* mtd->oobsize);
offs = 0;
ooboffs = len;
memcpy(&buf[ooboffs + td->offs], td->pattern, td->len);
}
if (td->options & NAND_BBT_VERSION)
buf[ooboffs + td->veroffs] = td->version[chip];
for (i = 0; i < numblocks; i++) {
uint8_t dat;
int sftcnt = (i << (3 - sft)) & sftmsk;
dat = bbt_get_entry(this, chip * numblocks + i);
buf[offs + (i >> sft)] &= ~(msk[dat] << sftcnt);
}
memset(&einfo, 0, sizeof(einfo));
einfo.mtd = mtd;
einfo.addr = to;
einfo.len = 1 << this->bbt_erase_shift;
res = nand_erase_nand(mtd, &einfo, 1);
if (res < 0)
goto outerr;
res = scan_write_bbt(mtd, to, len, buf,
td->options & NAND_BBT_NO_OOB ? NULL :
&buf[len]);
if (res < 0)
goto outerr;
pr_info("Bad block table written to 0x%012llx, version 0x%02X\n",
(unsigned long long)to, td->version[chip]);
td->pages[chip] = page;
}
return 0;
outerr:
pr_warn("nand_bbt: error while writing bad block table %d\n", res);
return res;
}
static inline int nand_memory_bbt(struct mtd_info *mtd, struct nand_bbt_descr *bd)
{
struct nand_chip *this = mtd->priv;
return create_bbt(mtd, this->buffers->databuf, bd, -1);
}
static int check_create(struct mtd_info *mtd, uint8_t *buf, struct nand_bbt_descr *bd)
{
int i, chips, writeops, create, chipsel, res, res2;
struct nand_chip *this = mtd->priv;
struct nand_bbt_descr *td = this->bbt_td;
struct nand_bbt_descr *md = this->bbt_md;
struct nand_bbt_descr *rd, *rd2;
if (td->options & NAND_BBT_PERCHIP)
chips = this->numchips;
else
chips = 1;
for (i = 0; i < chips; i++) {
writeops = 0;
create = 0;
rd = NULL;
rd2 = NULL;
res = res2 = 0;
chipsel = (td->options & NAND_BBT_PERCHIP) ? i : -1;
if (md) {
if (td->pages[i] == -1 && md->pages[i] == -1) {
create = 1;
writeops = 0x03;
} else if (td->pages[i] == -1) {
rd = md;
writeops = 0x01;
} else if (md->pages[i] == -1) {
rd = td;
writeops = 0x02;
} else if (td->version[i] == md->version[i]) {
rd = td;
if (!(td->options & NAND_BBT_VERSION))
rd2 = md;
} else if (((int8_t)(td->version[i] - md->version[i])) > 0) {
rd = td;
writeops = 0x02;
} else {
rd = md;
writeops = 0x01;
}
} else {
if (td->pages[i] == -1) {
create = 1;
writeops = 0x01;
} else {
rd = td;
}
}
if (create) {
if (!(td->options & NAND_BBT_CREATE))
continue;
if (!(this->bbt_options & NAND_BBT_CREATE_EMPTY))
create_bbt(mtd, buf, bd, chipsel);
td->version[i] = 1;
if (md)
md->version[i] = 1;
}
if (rd) {
res = read_abs_bbt(mtd, buf, rd, chipsel);
if (mtd_is_eccerr(res)) {
rd->pages[i] = -1;
rd->version[i] = 0;
i--;
continue;
}
}
if (rd2) {
res2 = read_abs_bbt(mtd, buf, rd2, chipsel);
if (mtd_is_eccerr(res2)) {
rd2->pages[i] = -1;
rd2->version[i] = 0;
i--;
continue;
}
}
if (mtd_is_bitflip(res) || mtd_is_bitflip(res2))
writeops = 0x03;
if (md) {
td->version[i] = max(td->version[i], md->version[i]);
md->version[i] = td->version[i];
}
if ((writeops & 0x01) && (td->options & NAND_BBT_WRITE)) {
res = write_bbt(mtd, buf, td, md, chipsel);
if (res < 0)
return res;
}
if ((writeops & 0x02) && md && (md->options & NAND_BBT_WRITE)) {
res = write_bbt(mtd, buf, md, td, chipsel);
if (res < 0)
return res;
}
}
return 0;
}
static void mark_bbt_region(struct mtd_info *mtd, struct nand_bbt_descr *td)
{
struct nand_chip *this = mtd->priv;
int i, j, chips, block, nrblocks, update;
uint8_t oldval;
if (td->options & NAND_BBT_PERCHIP) {
chips = this->numchips;
nrblocks = (int)(this->chipsize >> this->bbt_erase_shift);
} else {
chips = 1;
nrblocks = (int)(mtd->size >> this->bbt_erase_shift);
}
for (i = 0; i < chips; i++) {
if ((td->options & NAND_BBT_ABSPAGE) ||
!(td->options & NAND_BBT_WRITE)) {
if (td->pages[i] == -1)
continue;
block = td->pages[i] >> (this->bbt_erase_shift - this->page_shift);
oldval = bbt_get_entry(this, block);
bbt_mark_entry(this, block, BBT_BLOCK_RESERVED);
if ((oldval != BBT_BLOCK_RESERVED) &&
td->reserved_block_code)
nand_update_bbt(mtd, (loff_t)block <<
this->bbt_erase_shift);
continue;
}
update = 0;
if (td->options & NAND_BBT_LASTBLOCK)
block = ((i + 1) * nrblocks) - td->maxblocks;
else
block = i * nrblocks;
for (j = 0; j < td->maxblocks; j++) {
oldval = bbt_get_entry(this, block);
bbt_mark_entry(this, block, BBT_BLOCK_RESERVED);
if (oldval != BBT_BLOCK_RESERVED)
update = 1;
block++;
}
if (update && td->reserved_block_code)
nand_update_bbt(mtd, (loff_t)(block - 1) <<
this->bbt_erase_shift);
}
}
static void verify_bbt_descr(struct mtd_info *mtd, struct nand_bbt_descr *bd)
{
struct nand_chip *this = mtd->priv;
u32 pattern_len;
u32 bits;
u32 table_size;
if (!bd)
return;
pattern_len = bd->len;
bits = bd->options & NAND_BBT_NRBITS_MSK;
BUG_ON((this->bbt_options & NAND_BBT_NO_OOB) &&
!(this->bbt_options & NAND_BBT_USE_FLASH));
BUG_ON(!bits);
if (bd->options & NAND_BBT_VERSION)
pattern_len++;
if (bd->options & NAND_BBT_NO_OOB) {
BUG_ON(!(this->bbt_options & NAND_BBT_USE_FLASH));
BUG_ON(!(this->bbt_options & NAND_BBT_NO_OOB));
BUG_ON(bd->offs);
if (bd->options & NAND_BBT_VERSION)
BUG_ON(bd->veroffs != bd->len);
BUG_ON(bd->options & NAND_BBT_SAVECONTENT);
}
if (bd->options & NAND_BBT_PERCHIP)
table_size = this->chipsize >> this->bbt_erase_shift;
else
table_size = mtd->size >> this->bbt_erase_shift;
table_size >>= 3;
table_size *= bits;
if (bd->options & NAND_BBT_NO_OOB)
table_size += pattern_len;
BUG_ON(table_size > (1 << this->bbt_erase_shift));
}
int nand_scan_bbt(struct mtd_info *mtd, struct nand_bbt_descr *bd)
{
struct nand_chip *this = mtd->priv;
int len, res = 0;
uint8_t *buf;
struct nand_bbt_descr *td = this->bbt_td;
struct nand_bbt_descr *md = this->bbt_md;
len = mtd->size >> (this->bbt_erase_shift + 2);
this->bbt = kzalloc(len, GFP_KERNEL);
if (!this->bbt)
return -ENOMEM;
if (!td) {
if ((res = nand_memory_bbt(mtd, bd))) {
pr_err("nand_bbt: can't scan flash and build the RAM-based BBT\n");
kfree(this->bbt);
this->bbt = NULL;
}
return res;
}
verify_bbt_descr(mtd, td);
verify_bbt_descr(mtd, md);
len = (1 << this->bbt_erase_shift);
len += (len >> this->page_shift) * mtd->oobsize;
buf = vmalloc(len);
if (!buf) {
kfree(this->bbt);
this->bbt = NULL;
return -ENOMEM;
}
if (td->options & NAND_BBT_ABSPAGE) {
read_abs_bbts(mtd, buf, td, md);
} else {
search_read_bbts(mtd, buf, td, md);
}
res = check_create(mtd, buf, bd);
mark_bbt_region(mtd, td);
if (md)
mark_bbt_region(mtd, md);
vfree(buf);
return res;
}
static int nand_update_bbt(struct mtd_info *mtd, loff_t offs)
{
struct nand_chip *this = mtd->priv;
int len, res = 0;
int chip, chipsel;
uint8_t *buf;
struct nand_bbt_descr *td = this->bbt_td;
struct nand_bbt_descr *md = this->bbt_md;
if (!this->bbt || !td)
return -EINVAL;
len = (1 << this->bbt_erase_shift);
len += (len >> this->page_shift) * mtd->oobsize;
buf = kmalloc(len, GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (td->options & NAND_BBT_PERCHIP) {
chip = (int)(offs >> this->chip_shift);
chipsel = chip;
} else {
chip = 0;
chipsel = -1;
}
td->version[chip]++;
if (md)
md->version[chip]++;
if (td->options & NAND_BBT_WRITE) {
res = write_bbt(mtd, buf, td, md, chipsel);
if (res < 0)
goto out;
}
if (md && (md->options & NAND_BBT_WRITE)) {
res = write_bbt(mtd, buf, md, td, chipsel);
}
out:
kfree(buf);
return res;
}
static int nand_create_badblock_pattern(struct nand_chip *this)
{
struct nand_bbt_descr *bd;
if (this->badblock_pattern) {
pr_warn("Bad block pattern already allocated; not replacing\n");
return -EINVAL;
}
bd = kzalloc(sizeof(*bd), GFP_KERNEL);
if (!bd)
return -ENOMEM;
bd->options = this->bbt_options & BADBLOCK_SCAN_MASK;
bd->offs = this->badblockpos;
bd->len = (this->options & NAND_BUSWIDTH_16) ? 2 : 1;
bd->pattern = scan_ff_pattern;
bd->options |= NAND_BBT_DYNAMICSTRUCT;
this->badblock_pattern = bd;
return 0;
}
int nand_default_bbt(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
if (this->bbt_options & NAND_BBT_USE_FLASH) {
if (!this->bbt_td) {
if (this->bbt_options & NAND_BBT_NO_OOB) {
this->bbt_td = &bbt_main_no_oob_descr;
this->bbt_md = &bbt_mirror_no_oob_descr;
} else {
this->bbt_td = &bbt_main_descr;
this->bbt_md = &bbt_mirror_descr;
}
}
} else {
this->bbt_td = NULL;
this->bbt_md = NULL;
}
if (!this->badblock_pattern)
nand_create_badblock_pattern(this);
return nand_scan_bbt(mtd, this->badblock_pattern);
}
int nand_isbad_bbt(struct mtd_info *mtd, loff_t offs, int allowbbt)
{
struct nand_chip *this = mtd->priv;
int block, res;
block = (int)(offs >> this->bbt_erase_shift);
res = bbt_get_entry(this, block);
pr_debug("nand_isbad_bbt(): bbt info for offs 0x%08x: "
"(block %d) 0x%02x\n",
(unsigned int)offs, block, res);
switch (res) {
case BBT_BLOCK_GOOD:
return 0;
case BBT_BLOCK_WORN:
return 1;
case BBT_BLOCK_RESERVED:
return allowbbt ? 0 : 1;
}
return 1;
}
int nand_markbad_bbt(struct mtd_info *mtd, loff_t offs)
{
struct nand_chip *this = mtd->priv;
int block, ret = 0;
block = (int)(offs >> this->bbt_erase_shift);
bbt_mark_entry(this, block, BBT_BLOCK_WORN);
if (this->bbt_options & NAND_BBT_USE_FLASH)
ret = nand_update_bbt(mtd, offs);
return ret;
}
