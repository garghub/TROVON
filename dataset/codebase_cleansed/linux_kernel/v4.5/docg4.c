static inline void write_nop(void __iomem *docptr)
{
writew(0, docptr + DOC_NOP);
}
static void docg4_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
int i;
struct nand_chip *nand = mtd_to_nand(mtd);
uint16_t *p = (uint16_t *) buf;
len >>= 1;
for (i = 0; i < len; i++)
p[i] = readw(nand->IO_ADDR_R);
}
static void docg4_write_buf16(struct mtd_info *mtd, const uint8_t *buf, int len)
{
int i;
struct nand_chip *nand = mtd_to_nand(mtd);
uint16_t *p = (uint16_t *) buf;
len >>= 1;
for (i = 0; i < len; i++)
writew(p[i], nand->IO_ADDR_W);
}
static int poll_status(struct docg4_priv *doc)
{
uint16_t flash_status;
unsigned long timeo;
void __iomem *docptr = doc->virtadr;
dev_dbg(doc->dev, "%s...\n", __func__);
flash_status = readw(docptr + DOC_FLASHCONTROL);
timeo = jiffies + msecs_to_jiffies(200);
do {
cpu_relax();
flash_status = readb(docptr + DOC_FLASHCONTROL);
} while (!(flash_status & DOC_CTRL_FLASHREADY) &&
time_before(jiffies, timeo));
if (unlikely(!(flash_status & DOC_CTRL_FLASHREADY))) {
dev_err(doc->dev, "%s: timed out!\n", __func__);
return NAND_STATUS_FAIL;
}
return 0;
}
static int docg4_wait(struct mtd_info *mtd, struct nand_chip *nand)
{
struct docg4_priv *doc = nand_get_controller_data(nand);
int status = NAND_STATUS_WP;
dev_dbg(doc->dev, "%s...\n", __func__);
if (doc->status) {
status |= doc->status;
doc->status = 0;
return status;
}
status |= poll_status(doc);
return status;
}
static void docg4_select_chip(struct mtd_info *mtd, int chip)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
dev_dbg(doc->dev, "%s: chip %d\n", __func__, chip);
if (chip < 0)
return;
if (chip > 0)
dev_warn(doc->dev, "multiple floors currently unsupported\n");
writew(0, docptr + DOC_DEVICESELECT);
}
static void reset(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
writew(DOC_ASICMODE_RESET | DOC_ASICMODE_MDWREN,
docptr + DOC_ASICMODE);
writew(~(DOC_ASICMODE_RESET | DOC_ASICMODE_MDWREN),
docptr + DOC_ASICMODECONFIRM);
write_nop(docptr);
writew(DOC_ASICMODE_NORMAL | DOC_ASICMODE_MDWREN,
docptr + DOC_ASICMODE);
writew(~(DOC_ASICMODE_NORMAL | DOC_ASICMODE_MDWREN),
docptr + DOC_ASICMODECONFIRM);
writew(DOC_ECCCONF1_ECC_ENABLE, docptr + DOC_ECCCONF1);
poll_status(doc);
}
static void read_hw_ecc(void __iomem *docptr, uint8_t *ecc_buf)
{
int i;
for (i = 0; i < 7; i++) {
ecc_buf[i] = readb(docptr + DOC_BCH_SYNDROM(i));
ecc_buf[i] = readb(docptr + DOC_BCH_SYNDROM(i));
}
}
static int correct_data(struct mtd_info *mtd, uint8_t *buf, int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
int i, numerrs, errpos[4];
const uint8_t blank_read_hwecc[8] = {
0xcf, 0x72, 0xfc, 0x1b, 0xa9, 0xc7, 0xb9, 0 };
read_hw_ecc(docptr, doc->ecc_buf);
if (!memcmp(doc->ecc_buf, blank_read_hwecc, 7))
return 0;
if (ignore_badblocks == false) {
if (nand->oob_poi[15]) {
int bit, numsetbits = 0;
unsigned long written_flag = nand->oob_poi[15];
for_each_set_bit(bit, &written_flag, 8)
numsetbits++;
if (numsetbits > 4) {
dev_warn(doc->dev,
"error(s) in blank page "
"at offset %08x\n",
page * DOCG4_PAGE_SIZE);
return 0;
}
}
}
for (i = 0; i < 7; i++)
doc->ecc_buf[i] = bitrev8(doc->ecc_buf[i]);
numerrs = decode_bch(doc->bch, NULL, DOCG4_USERDATA_LEN, NULL,
doc->ecc_buf, NULL, errpos);
if (numerrs == -EBADMSG) {
dev_warn(doc->dev, "uncorrectable errors at offset %08x\n",
page * DOCG4_PAGE_SIZE);
return -EBADMSG;
}
BUG_ON(numerrs < 0);
for (i = 0; i < numerrs; i++)
errpos[i] = (errpos[i] & ~7)|(7-(errpos[i] & 7));
for (i = 0; i < numerrs; i++) {
if (errpos[i] > DOCG4_USERDATA_LEN * 8)
continue;
if (errpos[i] > DOCG4_PAGE_SIZE * 8)
change_bit(errpos[i] - DOCG4_PAGE_SIZE * 8,
(unsigned long *)nand->oob_poi);
else
change_bit(errpos[i], (unsigned long *)buf);
}
dev_notice(doc->dev, "%d error(s) corrected at offset %08x\n",
numerrs, page * DOCG4_PAGE_SIZE);
return numerrs;
}
static uint8_t docg4_read_byte(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
dev_dbg(doc->dev, "%s\n", __func__);
if (doc->last_command.command == NAND_CMD_STATUS) {
int status;
doc->last_command.command = 0;
if (doc->status) {
status = doc->status;
doc->status = 0;
}
else
status = NAND_STATUS_WP | NAND_STATUS_READY;
return status;
}
dev_warn(doc->dev, "unexpected call to read_byte()\n");
return 0;
}
static void write_addr(struct docg4_priv *doc, uint32_t docg4_addr)
{
void __iomem *docptr = doc->virtadr;
writeb(docg4_addr & 0xff, docptr + DOC_FLASHADDRESS);
docg4_addr >>= 8;
writeb(docg4_addr & 0xff, docptr + DOC_FLASHADDRESS);
docg4_addr >>= 8;
writeb(docg4_addr & 0xff, docptr + DOC_FLASHADDRESS);
docg4_addr >>= 8;
writeb(docg4_addr & 0xff, docptr + DOC_FLASHADDRESS);
}
static int read_progstatus(struct docg4_priv *doc)
{
void __iomem *docptr = doc->virtadr;
uint16_t status1 = readw(docptr + DOC_IOSPACE_DATA);
uint16_t status2 = readw(docptr + DOC_IOSPACE_DATA);
uint16_t status3 = readw(docptr + DOCG4_MYSTERY_REG);
dev_dbg(doc->dev, "docg4: %s: %02x %02x %02x\n",
__func__, status1, status2, status3);
if (status1 != DOCG4_PROGSTATUS_GOOD
|| status2 != DOCG4_PROGSTATUS_GOOD_2
|| status3 != DOCG4_PROGSTATUS_GOOD_2) {
doc->status = NAND_STATUS_FAIL;
dev_warn(doc->dev, "read_progstatus failed: "
"%02x, %02x, %02x\n", status1, status2, status3);
return -EIO;
}
return 0;
}
static int pageprog(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
int retval = 0;
dev_dbg(doc->dev, "docg4: %s\n", __func__);
writew(DOCG4_SEQ_PAGEPROG, docptr + DOC_FLASHSEQUENCE);
writew(DOC_CMD_PROG_CYCLE2, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
write_nop(docptr);
poll_status(doc);
writew(DOCG4_SEQ_FLUSH, docptr + DOC_FLASHSEQUENCE);
writew(DOCG4_CMD_FLUSH, docptr + DOC_FLASHCOMMAND);
writew(DOC_ECCCONF0_READ_MODE | 4, docptr + DOC_ECCCONF0);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
retval = read_progstatus(doc);
writew(0, docptr + DOC_DATAEND);
write_nop(docptr);
poll_status(doc);
write_nop(docptr);
return retval;
}
static void sequence_reset(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
writew(DOC_CTRL_UNKNOWN | DOC_CTRL_CE, docptr + DOC_FLASHCONTROL);
writew(DOC_SEQ_RESET, docptr + DOC_FLASHSEQUENCE);
writew(DOC_CMD_RESET, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
write_nop(docptr);
poll_status(doc);
write_nop(docptr);
}
static void read_page_prologue(struct mtd_info *mtd, uint32_t docg4_addr)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
dev_dbg(doc->dev,
"docg4: %s: g4 page %08x\n", __func__, docg4_addr);
sequence_reset(mtd);
writew(DOCG4_SEQ_PAGE_READ, docptr + DOC_FLASHSEQUENCE);
writew(DOCG4_CMD_PAGE_READ, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
write_addr(doc, docg4_addr);
write_nop(docptr);
writew(DOCG4_CMD_READ2, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
write_nop(docptr);
poll_status(doc);
}
static void write_page_prologue(struct mtd_info *mtd, uint32_t docg4_addr)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
dev_dbg(doc->dev,
"docg4: %s: g4 addr: %x\n", __func__, docg4_addr);
sequence_reset(mtd);
if (unlikely(reliable_mode)) {
writew(DOCG4_SEQ_SETMODE, docptr + DOC_FLASHSEQUENCE);
writew(DOCG4_CMD_FAST_MODE, docptr + DOC_FLASHCOMMAND);
writew(DOC_CMD_RELIABLE_MODE, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
}
writew(DOCG4_SEQ_PAGEWRITE, docptr + DOC_FLASHSEQUENCE);
writew(DOCG4_CMD_PAGEWRITE, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
write_addr(doc, docg4_addr);
write_nop(docptr);
write_nop(docptr);
poll_status(doc);
}
static uint32_t mtd_to_docg4_address(int page, int column)
{
int g4_page = page / 4;
int g4_index = (page % 4) * 0x108 + column/2;
return (g4_page << 16) | g4_index;
}
static void docg4_command(struct mtd_info *mtd, unsigned command, int column,
int page_addr)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
uint32_t g4_addr = mtd_to_docg4_address(page_addr, column);
dev_dbg(doc->dev, "%s %x, page_addr=%x, column=%x\n",
__func__, command, page_addr, column);
doc->last_command.command = command;
doc->last_command.column = column;
doc->last_command.page = page_addr;
switch (command) {
case NAND_CMD_RESET:
reset(mtd);
break;
case NAND_CMD_READ0:
read_page_prologue(mtd, g4_addr);
break;
case NAND_CMD_STATUS:
break;
case NAND_CMD_SEQIN:
if (unlikely(reliable_mode)) {
uint16_t g4_page = g4_addr >> 16;
if (g4_page & 0x01)
dev_warn(doc->dev,
"invalid reliable mode address\n");
}
write_page_prologue(mtd, g4_addr);
if (doc->oob_page == page_addr)
memcpy(nand->oob_poi, doc->oob_buf, 16);
break;
case NAND_CMD_PAGEPROG:
pageprog(mtd);
break;
case NAND_CMD_READOOB:
case NAND_CMD_READID:
case NAND_CMD_ERASE1:
case NAND_CMD_ERASE2:
dev_warn(doc->dev, "docg4_command: "
"unexpected nand command 0x%x\n", command);
break;
}
}
static int read_page(struct mtd_info *mtd, struct nand_chip *nand,
uint8_t *buf, int page, bool use_ecc)
{
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
uint16_t status, edc_err, *buf16;
int bits_corrected = 0;
dev_dbg(doc->dev, "%s: page %08x\n", __func__, page);
writew(DOC_ECCCONF0_READ_MODE |
DOC_ECCCONF0_ECC_ENABLE |
DOC_ECCCONF0_UNKNOWN |
DOCG4_BCH_SIZE,
docptr + DOC_ECCCONF0);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
status = readw(docptr + DOC_IOSPACE_DATA);
if (status & DOCG4_READ_ERROR) {
dev_err(doc->dev,
"docg4_read_page: bad status: 0x%02x\n", status);
writew(0, docptr + DOC_DATAEND);
return -EIO;
}
dev_dbg(doc->dev, "%s: status = 0x%x\n", __func__, status);
docg4_read_buf(mtd, buf, DOCG4_PAGE_SIZE);
docg4_read_buf(mtd, nand->oob_poi, 14);
buf16 = (uint16_t *)(nand->oob_poi + 14);
*buf16 = readw(docptr + DOCG4_MYSTERY_REG);
write_nop(docptr);
if (likely(use_ecc == true)) {
edc_err = readw(docptr + DOC_ECCCONF1);
edc_err = readw(docptr + DOC_ECCCONF1);
dev_dbg(doc->dev, "%s: edc_err = 0x%02x\n", __func__, edc_err);
if (edc_err & DOC_ECCCONF1_BCH_SYNDROM_ERR) {
bits_corrected = correct_data(mtd, buf, page);
if (bits_corrected == -EBADMSG)
mtd->ecc_stats.failed++;
else
mtd->ecc_stats.corrected += bits_corrected;
}
}
writew(0, docptr + DOC_DATAEND);
if (bits_corrected == -EBADMSG)
return 0;
return bits_corrected;
}
static int docg4_read_page_raw(struct mtd_info *mtd, struct nand_chip *nand,
uint8_t *buf, int oob_required, int page)
{
return read_page(mtd, nand, buf, page, false);
}
static int docg4_read_page(struct mtd_info *mtd, struct nand_chip *nand,
uint8_t *buf, int oob_required, int page)
{
return read_page(mtd, nand, buf, page, true);
}
static int docg4_read_oob(struct mtd_info *mtd, struct nand_chip *nand,
int page)
{
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
uint16_t status;
dev_dbg(doc->dev, "%s: page %x\n", __func__, page);
docg4_command(mtd, NAND_CMD_READ0, nand->ecc.size, page);
writew(DOC_ECCCONF0_READ_MODE | DOCG4_OOB_SIZE, docptr + DOC_ECCCONF0);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
status = readw(docptr + DOC_IOSPACE_DATA);
if (status & DOCG4_READ_ERROR) {
dev_warn(doc->dev,
"docg4_read_oob failed: status = 0x%02x\n", status);
return -EIO;
}
dev_dbg(doc->dev, "%s: status = 0x%x\n", __func__, status);
docg4_read_buf(mtd, nand->oob_poi, 16);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
writew(0, docptr + DOC_DATAEND);
write_nop(docptr);
return 0;
}
static int docg4_erase_block(struct mtd_info *mtd, int page)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
uint16_t g4_page;
dev_dbg(doc->dev, "%s: page %04x\n", __func__, page);
sequence_reset(mtd);
writew(DOCG4_SEQ_BLOCKERASE, docptr + DOC_FLASHSEQUENCE);
writew(DOC_CMD_PROG_BLOCK_ADDR, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
g4_page = (uint16_t)(page / 4);
writeb(g4_page & 0xff, docptr + DOC_FLASHADDRESS);
g4_page >>= 8;
writeb(g4_page & 0xff, docptr + DOC_FLASHADDRESS);
write_nop(docptr);
writew(DOC_CMD_ERASECYCLE2, docptr + DOC_FLASHCOMMAND);
write_nop(docptr);
write_nop(docptr);
usleep_range(500, 1000);
poll_status(doc);
writew(DOCG4_SEQ_FLUSH, docptr + DOC_FLASHSEQUENCE);
writew(DOCG4_CMD_FLUSH, docptr + DOC_FLASHCOMMAND);
writew(DOC_ECCCONF0_READ_MODE | 4, docptr + DOC_ECCCONF0);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
write_nop(docptr);
read_progstatus(doc);
writew(0, docptr + DOC_DATAEND);
write_nop(docptr);
poll_status(doc);
write_nop(docptr);
return nand->waitfunc(mtd, nand);
}
static int write_page(struct mtd_info *mtd, struct nand_chip *nand,
const uint8_t *buf, bool use_ecc)
{
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
uint8_t ecc_buf[8];
dev_dbg(doc->dev, "%s...\n", __func__);
writew(DOC_ECCCONF0_ECC_ENABLE |
DOC_ECCCONF0_UNKNOWN |
DOCG4_BCH_SIZE,
docptr + DOC_ECCCONF0);
write_nop(docptr);
docg4_write_buf16(mtd, buf, DOCG4_PAGE_SIZE);
docg4_write_buf16(mtd, nand->oob_poi, 6);
writew(nand->oob_poi[6], docptr + DOCG4_OOB_6_7);
write_nop(docptr);
write_nop(docptr);
if (likely(use_ecc == true)) {
uint8_t hamming = readb(docptr + DOC_HAMMINGPARITY);
hamming = readb(docptr + DOC_HAMMINGPARITY);
writew(hamming, docptr + DOCG4_OOB_6_7);
write_nop(docptr);
read_hw_ecc(docptr, ecc_buf);
ecc_buf[7] = 0;
}
else {
writew(nand->oob_poi[7], docptr + DOCG4_OOB_6_7);
write_nop(docptr);
memcpy(ecc_buf, &nand->oob_poi[8], 8);
}
docg4_write_buf16(mtd, ecc_buf, 8);
write_nop(docptr);
write_nop(docptr);
writew(0, docptr + DOC_DATAEND);
write_nop(docptr);
return 0;
}
static int docg4_write_page_raw(struct mtd_info *mtd, struct nand_chip *nand,
const uint8_t *buf, int oob_required, int page)
{
return write_page(mtd, nand, buf, false);
}
static int docg4_write_page(struct mtd_info *mtd, struct nand_chip *nand,
const uint8_t *buf, int oob_required, int page)
{
return write_page(mtd, nand, buf, true);
}
static int docg4_write_oob(struct mtd_info *mtd, struct nand_chip *nand,
int page)
{
struct docg4_priv *doc = nand_get_controller_data(nand);
doc->oob_page = page;
memcpy(doc->oob_buf, nand->oob_poi, 16);
return 0;
}
static int __init read_factory_bbt(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
uint32_t g4_addr = mtd_to_docg4_address(DOCG4_FACTORY_BBT_PAGE, 0);
uint8_t *buf;
int i, block;
__u32 eccfailed_stats = mtd->ecc_stats.failed;
buf = kzalloc(DOCG4_PAGE_SIZE, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
read_page_prologue(mtd, g4_addr);
docg4_read_page(mtd, nand, buf, 0, DOCG4_FACTORY_BBT_PAGE);
if (nand->bbt == NULL)
goto exit;
if (mtd->ecc_stats.failed > eccfailed_stats) {
eccfailed_stats = mtd->ecc_stats.failed;
docg4_read_page(mtd, nand, buf, 0, DOCG4_REDUNDANT_BBT_PAGE);
if (mtd->ecc_stats.failed > eccfailed_stats) {
dev_warn(doc->dev,
"The factory bbt could not be read!\n");
goto exit;
}
}
for (i = block = 0; block < DOCG4_NUMBLOCKS; block += 8, i++) {
int bitnum;
unsigned long bits = ~buf[i];
for_each_set_bit(bitnum, &bits, 8) {
int badblock = block + 7 - bitnum;
nand->bbt[badblock / 4] |=
0x03 << ((badblock % 4) * 2);
mtd->ecc_stats.badblocks++;
dev_notice(doc->dev, "factory-marked bad block: %d\n",
badblock);
}
}
exit:
kfree(buf);
return 0;
}
static int docg4_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
int ret, i;
uint8_t *buf;
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
struct nand_bbt_descr *bbtd = nand->badblock_pattern;
int page = (int)(ofs >> nand->page_shift);
uint32_t g4_addr = mtd_to_docg4_address(page, 0);
dev_dbg(doc->dev, "%s: %08llx\n", __func__, ofs);
if (unlikely(ofs & (DOCG4_BLOCK_SIZE - 1)))
dev_warn(doc->dev, "%s: ofs %llx not start of block!\n",
__func__, ofs);
buf = kzalloc(DOCG4_PAGE_SIZE, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
memset(nand->oob_poi, 0xff, mtd->oobsize);
for (i = 0; i < bbtd->len; i++)
nand->oob_poi[bbtd->offs + i] = ~bbtd->pattern[i];
write_page_prologue(mtd, g4_addr);
docg4_write_page(mtd, nand, buf, 1, page);
ret = pageprog(mtd);
kfree(buf);
return ret;
}
static int docg4_block_neverbad(struct mtd_info *mtd, loff_t ofs, int getchip)
{
return 0;
}
static int docg4_suspend(struct platform_device *pdev, pm_message_t state)
{
int i;
uint8_t pwr_down;
struct docg4_priv *doc = platform_get_drvdata(pdev);
void __iomem *docptr = doc->virtadr;
dev_dbg(doc->dev, "%s...\n", __func__);
for (i = 0; i < 10; i++) {
pwr_down = readb(docptr + DOC_POWERMODE);
if (pwr_down & DOC_POWERDOWN_READY)
break;
usleep_range(1000, 4000);
}
if (pwr_down & DOC_POWERDOWN_READY) {
dev_err(doc->dev, "suspend failed; "
"timeout polling DOC_POWERDOWN_READY\n");
return -EIO;
}
writew(DOC_ASICMODE_POWERDOWN | DOC_ASICMODE_MDWREN,
docptr + DOC_ASICMODE);
writew(~(DOC_ASICMODE_POWERDOWN | DOC_ASICMODE_MDWREN),
docptr + DOC_ASICMODECONFIRM);
write_nop(docptr);
return 0;
}
static int docg4_resume(struct platform_device *pdev)
{
struct docg4_priv *doc = platform_get_drvdata(pdev);
void __iomem *docptr = doc->virtadr;
int i;
dev_dbg(doc->dev, "%s...\n", __func__);
for (i = 0; i < 12; i++)
readb(docptr + 0x1fff);
return 0;
}
static void __init init_mtd_structs(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
mtd->size = DOCG4_CHIP_SIZE;
mtd->name = "Msys_Diskonchip_G4";
mtd->writesize = DOCG4_PAGE_SIZE;
mtd->erasesize = DOCG4_BLOCK_SIZE;
mtd->oobsize = DOCG4_OOB_SIZE;
nand->chipsize = DOCG4_CHIP_SIZE;
nand->chip_shift = DOCG4_CHIP_SHIFT;
nand->bbt_erase_shift = nand->phys_erase_shift = DOCG4_ERASE_SHIFT;
nand->chip_delay = 20;
nand->page_shift = DOCG4_PAGE_SHIFT;
nand->pagemask = 0x3ffff;
nand->badblockpos = NAND_LARGE_BADBLOCK_POS;
nand->badblockbits = 8;
nand->ecc.layout = &docg4_oobinfo;
nand->ecc.mode = NAND_ECC_HW_SYNDROME;
nand->ecc.size = DOCG4_PAGE_SIZE;
nand->ecc.prepad = 8;
nand->ecc.bytes = 8;
nand->ecc.strength = DOCG4_T;
nand->options = NAND_BUSWIDTH_16 | NAND_NO_SUBPAGE_WRITE;
nand->IO_ADDR_R = nand->IO_ADDR_W = doc->virtadr + DOC_IOSPACE_DATA;
nand->controller = &nand->hwcontrol;
spin_lock_init(&nand->controller->lock);
init_waitqueue_head(&nand->controller->wq);
nand->cmdfunc = docg4_command;
nand->waitfunc = docg4_wait;
nand->select_chip = docg4_select_chip;
nand->read_byte = docg4_read_byte;
nand->block_markbad = docg4_block_markbad;
nand->read_buf = docg4_read_buf;
nand->write_buf = docg4_write_buf16;
nand->erase = docg4_erase_block;
nand->ecc.read_page = docg4_read_page;
nand->ecc.write_page = docg4_write_page;
nand->ecc.read_page_raw = docg4_read_page_raw;
nand->ecc.write_page_raw = docg4_write_page_raw;
nand->ecc.read_oob = docg4_read_oob;
nand->ecc.write_oob = docg4_write_oob;
if (ignore_badblocks) {
nand->options |= NAND_SKIP_BBTSCAN;
nand->block_bad = docg4_block_neverbad;
}
}
static int __init read_id_reg(struct mtd_info *mtd)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct docg4_priv *doc = nand_get_controller_data(nand);
void __iomem *docptr = doc->virtadr;
uint16_t id1, id2;
id1 = readw(docptr + DOC_CHIPID);
id1 = readw(docptr + DOCG4_MYSTERY_REG);
id2 = readw(docptr + DOC_CHIPID_INV);
id2 = readw(docptr + DOCG4_MYSTERY_REG);
if (id1 == DOCG4_IDREG1_VALUE && id2 == DOCG4_IDREG2_VALUE) {
dev_info(doc->dev,
"NAND device: 128MiB Diskonchip G4 detected\n");
return 0;
}
return -ENODEV;
}
static int __init probe_docg4(struct platform_device *pdev)
{
struct mtd_info *mtd;
struct nand_chip *nand;
void __iomem *virtadr;
struct docg4_priv *doc;
int len, retval;
struct resource *r;
struct device *dev = &pdev->dev;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
dev_err(dev, "no io memory resource defined!\n");
return -ENODEV;
}
virtadr = ioremap(r->start, resource_size(r));
if (!virtadr) {
dev_err(dev, "Diskonchip ioremap failed: %pR\n", r);
return -EIO;
}
len = sizeof(struct nand_chip) + sizeof(struct docg4_priv);
nand = kzalloc(len, GFP_KERNEL);
if (nand == NULL) {
retval = -ENOMEM;
goto fail_unmap;
}
mtd = nand_to_mtd(nand);
doc = (struct docg4_priv *) (nand + 1);
nand_set_controller_data(nand, doc);
mtd->dev.parent = &pdev->dev;
doc->virtadr = virtadr;
doc->dev = dev;
init_mtd_structs(mtd);
doc->bch = init_bch(DOCG4_M, DOCG4_T, DOCG4_PRIMITIVE_POLY);
if (doc->bch == NULL) {
retval = -EINVAL;
goto fail;
}
platform_set_drvdata(pdev, doc);
reset(mtd);
retval = read_id_reg(mtd);
if (retval == -ENODEV) {
dev_warn(dev, "No diskonchip G4 device found.\n");
goto fail;
}
retval = nand_scan_tail(mtd);
if (retval)
goto fail;
retval = read_factory_bbt(mtd);
if (retval)
goto fail;
retval = mtd_device_parse_register(mtd, part_probes, NULL, NULL, 0);
if (retval)
goto fail;
doc->mtd = mtd;
return 0;
fail:
nand_release(mtd);
free_bch(doc->bch);
kfree(nand);
fail_unmap:
iounmap(virtadr);
return retval;
}
static int __exit cleanup_docg4(struct platform_device *pdev)
{
struct docg4_priv *doc = platform_get_drvdata(pdev);
nand_release(doc->mtd);
free_bch(doc->bch);
kfree(mtd_to_nand(doc->mtd));
iounmap(doc->virtadr);
return 0;
}
