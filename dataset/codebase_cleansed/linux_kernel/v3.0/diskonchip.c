static int doc_ecc_decode(struct rs_control *rs, uint8_t *data, uint8_t *ecc)
{
int i, j, nerr, errpos[8];
uint8_t parity;
uint16_t ds[4], s[5], tmp, errval[8], syn[4];
memset(syn, 0, sizeof(syn));
ds[0] = ((ecc[4] & 0xff) >> 0) | ((ecc[5] & 0x03) << 8);
ds[1] = ((ecc[5] & 0xfc) >> 2) | ((ecc[2] & 0x0f) << 6);
ds[2] = ((ecc[2] & 0xf0) >> 4) | ((ecc[3] & 0x3f) << 4);
ds[3] = ((ecc[3] & 0xc0) >> 6) | ((ecc[0] & 0xff) << 2);
parity = ecc[1];
for (i = 0; i < NROOTS; i++)
s[i] = ds[0];
for (j = 1; j < NROOTS; j++) {
if (ds[j] == 0)
continue;
tmp = rs->index_of[ds[j]];
for (i = 0; i < NROOTS; i++)
s[i] ^= rs->alpha_to[rs_modnn(rs, tmp + (FCR + i) * j)];
}
for (i = 0; i < NROOTS; i++) {
if (s[i])
syn[i] = rs_modnn(rs, rs->index_of[s[i]] + (NN - FCR - i));
}
nerr = decode_rs16(rs, NULL, NULL, 1019, syn, 0, errpos, 0, errval);
if (nerr < 0)
return nerr;
for (i = 0; i < nerr; i++) {
int index, bitpos, pos = 1015 - errpos[i];
uint8_t val;
if (pos >= NB_DATA && pos < 1019)
continue;
if (pos < NB_DATA) {
pos = 10 * (NB_DATA - 1 - pos) - 6;
index = (pos >> 3) ^ 1;
bitpos = pos & 7;
if ((index >= 0 && index < SECTOR_SIZE) || index == (SECTOR_SIZE + 1)) {
val = (uint8_t) (errval[i] >> (2 + bitpos));
parity ^= val;
if (index < SECTOR_SIZE)
data[index] ^= val;
}
index = ((pos >> 3) + 1) ^ 1;
bitpos = (bitpos + 10) & 7;
if (bitpos == 0)
bitpos = 8;
if ((index >= 0 && index < SECTOR_SIZE) || index == (SECTOR_SIZE + 1)) {
val = (uint8_t) (errval[i] << (8 - bitpos));
parity ^= val;
if (index < SECTOR_SIZE)
data[index] ^= val;
}
}
}
return parity ? -EBADMSG : nerr;
}
static void DoC_Delay(struct doc_priv *doc, unsigned short cycles)
{
volatile char dummy;
int i;
for (i = 0; i < cycles; i++) {
if (DoC_is_Millennium(doc))
dummy = ReadDOC(doc->virtadr, NOP);
else if (DoC_is_MillenniumPlus(doc))
dummy = ReadDOC(doc->virtadr, Mplus_NOP);
else
dummy = ReadDOC(doc->virtadr, DOCStatus);
}
}
static int _DoC_WaitReady(struct doc_priv *doc)
{
void __iomem *docptr = doc->virtadr;
unsigned long timeo = jiffies + (HZ * 10);
if (debug)
printk("_DoC_WaitReady...\n");
if (DoC_is_MillenniumPlus(doc)) {
while ((ReadDOC(docptr, Mplus_FlashControl) & CDSN_CTRL_FR_B_MASK) != CDSN_CTRL_FR_B_MASK) {
if (time_after(jiffies, timeo)) {
printk("_DoC_WaitReady timed out.\n");
return -EIO;
}
udelay(1);
cond_resched();
}
} else {
while (!(ReadDOC(docptr, CDSNControl) & CDSN_CTRL_FR_B)) {
if (time_after(jiffies, timeo)) {
printk("_DoC_WaitReady timed out.\n");
return -EIO;
}
udelay(1);
cond_resched();
}
}
return 0;
}
static inline int DoC_WaitReady(struct doc_priv *doc)
{
void __iomem *docptr = doc->virtadr;
int ret = 0;
if (DoC_is_MillenniumPlus(doc)) {
DoC_Delay(doc, 4);
if ((ReadDOC(docptr, Mplus_FlashControl) & CDSN_CTRL_FR_B_MASK) != CDSN_CTRL_FR_B_MASK)
ret = _DoC_WaitReady(doc);
} else {
DoC_Delay(doc, 4);
if (!(ReadDOC(docptr, CDSNControl) & CDSN_CTRL_FR_B))
ret = _DoC_WaitReady(doc);
DoC_Delay(doc, 2);
}
if (debug)
printk("DoC_WaitReady OK\n");
return ret;
}
static void doc2000_write_byte(struct mtd_info *mtd, u_char datum)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
if (debug)
printk("write_byte %02x\n", datum);
WriteDOC(datum, docptr, CDSNSlowIO);
WriteDOC(datum, docptr, 2k_CDSN_IO);
}
static u_char doc2000_read_byte(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
u_char ret;
ReadDOC(docptr, CDSNSlowIO);
DoC_Delay(doc, 2);
ret = ReadDOC(docptr, 2k_CDSN_IO);
if (debug)
printk("read_byte returns %02x\n", ret);
return ret;
}
static void doc2000_writebuf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
if (debug)
printk("writebuf of %d bytes: ", len);
for (i = 0; i < len; i++) {
WriteDOC_(buf[i], docptr, DoC_2k_CDSN_IO + i);
if (debug && i < 16)
printk("%02x ", buf[i]);
}
if (debug)
printk("\n");
}
static void doc2000_readbuf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
if (debug)
printk("readbuf of %d bytes: ", len);
for (i = 0; i < len; i++) {
buf[i] = ReadDOC(docptr, 2k_CDSN_IO + i);
}
}
static void doc2000_readbuf_dword(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
if (debug)
printk("readbuf_dword of %d bytes: ", len);
if (unlikely((((unsigned long)buf) | len) & 3)) {
for (i = 0; i < len; i++) {
*(uint8_t *) (&buf[i]) = ReadDOC(docptr, 2k_CDSN_IO + i);
}
} else {
for (i = 0; i < len; i += 4) {
*(uint32_t *) (&buf[i]) = readl(docptr + DoC_2k_CDSN_IO + i);
}
}
}
static int doc2000_verifybuf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
for (i = 0; i < len; i++)
if (buf[i] != ReadDOC(docptr, 2k_CDSN_IO))
return -EFAULT;
return 0;
}
static uint16_t __init doc200x_ident_chip(struct mtd_info *mtd, int nr)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
uint16_t ret;
doc200x_select_chip(mtd, nr);
doc200x_hwcontrol(mtd, NAND_CMD_READID,
NAND_CTRL_CLE | NAND_CTRL_CHANGE);
doc200x_hwcontrol(mtd, 0, NAND_CTRL_ALE | NAND_CTRL_CHANGE);
doc200x_hwcontrol(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
udelay(50);
ret = this->read_byte(mtd) << 8;
ret |= this->read_byte(mtd);
if (doc->ChipID == DOC_ChipID_Doc2k && try_dword && !nr) {
union {
uint32_t dword;
uint8_t byte[4];
} ident;
void __iomem *docptr = doc->virtadr;
doc200x_hwcontrol(mtd, NAND_CMD_READID,
NAND_CTRL_CLE | NAND_CTRL_CHANGE);
doc200x_hwcontrol(mtd, 0, NAND_CTRL_ALE | NAND_CTRL_CHANGE);
doc200x_hwcontrol(mtd, NAND_CMD_NONE,
NAND_NCE | NAND_CTRL_CHANGE);
udelay(50);
ident.dword = readl(docptr + DoC_2k_CDSN_IO);
if (((ident.byte[0] << 8) | ident.byte[1]) == ret) {
printk(KERN_INFO "DiskOnChip 2000 responds to DWORD access\n");
this->read_buf = &doc2000_readbuf_dword;
}
}
return ret;
}
static void __init doc2000_count_chips(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
uint16_t mfrid;
int i;
doc->chips_per_floor = 4;
mfrid = doc200x_ident_chip(mtd, 0);
for (i = 1; i < 4; i++) {
if (doc200x_ident_chip(mtd, i) != mfrid)
break;
}
doc->chips_per_floor = i;
printk(KERN_DEBUG "Detected %d chips per floor.\n", i);
}
static int doc200x_wait(struct mtd_info *mtd, struct nand_chip *this)
{
struct doc_priv *doc = this->priv;
int status;
DoC_WaitReady(doc);
this->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);
DoC_WaitReady(doc);
status = (int)this->read_byte(mtd);
return status;
}
static void doc2001_write_byte(struct mtd_info *mtd, u_char datum)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
WriteDOC(datum, docptr, CDSNSlowIO);
WriteDOC(datum, docptr, Mil_CDSN_IO);
WriteDOC(datum, docptr, WritePipeTerm);
}
static u_char doc2001_read_byte(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
DoC_Delay(doc, 2);
ReadDOC(docptr, ReadPipeInit);
return ReadDOC(docptr, LastDataRead);
}
static void doc2001_writebuf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
for (i = 0; i < len; i++)
WriteDOC_(buf[i], docptr, DoC_Mil_CDSN_IO + i);
WriteDOC(0x00, docptr, WritePipeTerm);
}
static void doc2001_readbuf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
ReadDOC(docptr, ReadPipeInit);
for (i = 0; i < len - 1; i++)
buf[i] = ReadDOC(docptr, Mil_CDSN_IO + (i & 0xff));
buf[i] = ReadDOC(docptr, LastDataRead);
}
static int doc2001_verifybuf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
ReadDOC(docptr, ReadPipeInit);
for (i = 0; i < len - 1; i++)
if (buf[i] != ReadDOC(docptr, Mil_CDSN_IO)) {
ReadDOC(docptr, LastDataRead);
return i;
}
if (buf[i] != ReadDOC(docptr, LastDataRead))
return i;
return 0;
}
static u_char doc2001plus_read_byte(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
u_char ret;
ReadDOC(docptr, Mplus_ReadPipeInit);
ReadDOC(docptr, Mplus_ReadPipeInit);
ret = ReadDOC(docptr, Mplus_LastDataRead);
if (debug)
printk("read_byte returns %02x\n", ret);
return ret;
}
static void doc2001plus_writebuf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
if (debug)
printk("writebuf of %d bytes: ", len);
for (i = 0; i < len; i++) {
WriteDOC_(buf[i], docptr, DoC_Mil_CDSN_IO + i);
if (debug && i < 16)
printk("%02x ", buf[i]);
}
if (debug)
printk("\n");
}
static void doc2001plus_readbuf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
if (debug)
printk("readbuf of %d bytes: ", len);
ReadDOC(docptr, Mplus_ReadPipeInit);
ReadDOC(docptr, Mplus_ReadPipeInit);
for (i = 0; i < len - 2; i++) {
buf[i] = ReadDOC(docptr, Mil_CDSN_IO);
if (debug && i < 16)
printk("%02x ", buf[i]);
}
buf[len - 2] = ReadDOC(docptr, Mplus_LastDataRead);
if (debug && i < 16)
printk("%02x ", buf[len - 2]);
buf[len - 1] = ReadDOC(docptr, Mplus_LastDataRead);
if (debug && i < 16)
printk("%02x ", buf[len - 1]);
if (debug)
printk("\n");
}
static int doc2001plus_verifybuf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
if (debug)
printk("verifybuf of %d bytes: ", len);
ReadDOC(docptr, Mplus_ReadPipeInit);
ReadDOC(docptr, Mplus_ReadPipeInit);
for (i = 0; i < len - 2; i++)
if (buf[i] != ReadDOC(docptr, Mil_CDSN_IO)) {
ReadDOC(docptr, Mplus_LastDataRead);
ReadDOC(docptr, Mplus_LastDataRead);
return i;
}
if (buf[len - 2] != ReadDOC(docptr, Mplus_LastDataRead))
return len - 2;
if (buf[len - 1] != ReadDOC(docptr, Mplus_LastDataRead))
return len - 1;
return 0;
}
static void doc2001plus_select_chip(struct mtd_info *mtd, int chip)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int floor = 0;
if (debug)
printk("select chip (%d)\n", chip);
if (chip == -1) {
WriteDOC(0, docptr, Mplus_FlashSelect);
return;
}
floor = chip / doc->chips_per_floor;
chip -= (floor * doc->chips_per_floor);
WriteDOC((DOC_FLASH_CE), docptr, Mplus_FlashSelect);
this->cmdfunc(mtd, NAND_CMD_RESET, -1, -1);
doc->curchip = chip;
doc->curfloor = floor;
}
static void doc200x_select_chip(struct mtd_info *mtd, int chip)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int floor = 0;
if (debug)
printk("select chip (%d)\n", chip);
if (chip == -1)
return;
floor = chip / doc->chips_per_floor;
chip -= (floor * doc->chips_per_floor);
doc200x_hwcontrol(mtd, NAND_CMD_NONE, 0 | NAND_CTRL_CHANGE);
WriteDOC(floor, docptr, FloorSelect);
WriteDOC(chip, docptr, CDSNDeviceSelect);
doc200x_hwcontrol(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
doc->curchip = chip;
doc->curfloor = floor;
}
static void doc200x_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
if (ctrl & NAND_CTRL_CHANGE) {
doc->CDSNControl &= ~CDSN_CTRL_MSK;
doc->CDSNControl |= ctrl & CDSN_CTRL_MSK;
if (debug)
printk("hwcontrol(%d): %02x\n", cmd, doc->CDSNControl);
WriteDOC(doc->CDSNControl, docptr, CDSNControl);
DoC_Delay(doc, 4);
}
if (cmd != NAND_CMD_NONE) {
if (DoC_is_2000(doc))
doc2000_write_byte(mtd, cmd);
else
doc2001_write_byte(mtd, cmd);
}
}
static void doc2001plus_command(struct mtd_info *mtd, unsigned command, int column, int page_addr)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
if (command == NAND_CMD_PAGEPROG) {
WriteDOC(0x00, docptr, Mplus_WritePipeTerm);
WriteDOC(0x00, docptr, Mplus_WritePipeTerm);
}
if (command == NAND_CMD_SEQIN) {
int readcmd;
if (column >= mtd->writesize) {
column -= mtd->writesize;
readcmd = NAND_CMD_READOOB;
} else if (column < 256) {
readcmd = NAND_CMD_READ0;
} else {
column -= 256;
readcmd = NAND_CMD_READ1;
}
WriteDOC(readcmd, docptr, Mplus_FlashCmd);
}
WriteDOC(command, docptr, Mplus_FlashCmd);
WriteDOC(0, docptr, Mplus_WritePipeTerm);
WriteDOC(0, docptr, Mplus_WritePipeTerm);
if (column != -1 || page_addr != -1) {
if (column != -1) {
if (this->options & NAND_BUSWIDTH_16)
column >>= 1;
WriteDOC(column, docptr, Mplus_FlashAddress);
}
if (page_addr != -1) {
WriteDOC((unsigned char)(page_addr & 0xff), docptr, Mplus_FlashAddress);
WriteDOC((unsigned char)((page_addr >> 8) & 0xff), docptr, Mplus_FlashAddress);
if (this->chipsize & 0x0c000000) {
WriteDOC((unsigned char)((page_addr >> 16) & 0x0f), docptr, Mplus_FlashAddress);
printk("high density\n");
}
}
WriteDOC(0, docptr, Mplus_WritePipeTerm);
WriteDOC(0, docptr, Mplus_WritePipeTerm);
if (command == NAND_CMD_READ0 || command == NAND_CMD_READ1 ||
command == NAND_CMD_READOOB || command == NAND_CMD_READID)
WriteDOC(0, docptr, Mplus_FlashControl);
}
switch (command) {
case NAND_CMD_PAGEPROG:
case NAND_CMD_ERASE1:
case NAND_CMD_ERASE2:
case NAND_CMD_SEQIN:
case NAND_CMD_STATUS:
return;
case NAND_CMD_RESET:
if (this->dev_ready)
break;
udelay(this->chip_delay);
WriteDOC(NAND_CMD_STATUS, docptr, Mplus_FlashCmd);
WriteDOC(0, docptr, Mplus_WritePipeTerm);
WriteDOC(0, docptr, Mplus_WritePipeTerm);
while (!(this->read_byte(mtd) & 0x40)) ;
return;
default:
if (!this->dev_ready) {
udelay(this->chip_delay);
return;
}
}
ndelay(100);
while (!this->dev_ready(mtd)) ;
}
static int doc200x_dev_ready(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
if (DoC_is_MillenniumPlus(doc)) {
DoC_Delay(doc, 4);
if ((ReadDOC(docptr, Mplus_FlashControl) & CDSN_CTRL_FR_B_MASK) != CDSN_CTRL_FR_B_MASK) {
if (debug)
printk("not ready\n");
return 0;
}
if (debug)
printk("was ready\n");
return 1;
} else {
DoC_Delay(doc, 4);
if (!(ReadDOC(docptr, CDSNControl) & CDSN_CTRL_FR_B)) {
if (debug)
printk("not ready\n");
return 0;
}
DoC_Delay(doc, 2);
if (debug)
printk("was ready\n");
return 1;
}
}
static int doc200x_block_bad(struct mtd_info *mtd, loff_t ofs, int getchip)
{
return 0;
}
static void doc200x_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
switch (mode) {
case NAND_ECC_READ:
WriteDOC(DOC_ECC_RESET, docptr, ECCConf);
WriteDOC(DOC_ECC_EN, docptr, ECCConf);
break;
case NAND_ECC_WRITE:
WriteDOC(DOC_ECC_RESET, docptr, ECCConf);
WriteDOC(DOC_ECC_EN | DOC_ECC_RW, docptr, ECCConf);
break;
}
}
static void doc2001plus_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
switch (mode) {
case NAND_ECC_READ:
WriteDOC(DOC_ECC_RESET, docptr, Mplus_ECCConf);
WriteDOC(DOC_ECC_EN, docptr, Mplus_ECCConf);
break;
case NAND_ECC_WRITE:
WriteDOC(DOC_ECC_RESET, docptr, Mplus_ECCConf);
WriteDOC(DOC_ECC_EN | DOC_ECC_RW, docptr, Mplus_ECCConf);
break;
}
}
static int doc200x_calculate_ecc(struct mtd_info *mtd, const u_char *dat, unsigned char *ecc_code)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
int i;
int emptymatch = 1;
if (DoC_is_2000(doc)) {
WriteDOC(doc->CDSNControl & ~CDSN_CTRL_FLASH_IO, docptr, CDSNControl);
WriteDOC(0, docptr, 2k_CDSN_IO);
WriteDOC(0, docptr, 2k_CDSN_IO);
WriteDOC(0, docptr, 2k_CDSN_IO);
WriteDOC(doc->CDSNControl, docptr, CDSNControl);
} else if (DoC_is_MillenniumPlus(doc)) {
WriteDOC(0, docptr, Mplus_NOP);
WriteDOC(0, docptr, Mplus_NOP);
WriteDOC(0, docptr, Mplus_NOP);
} else {
WriteDOC(0, docptr, NOP);
WriteDOC(0, docptr, NOP);
WriteDOC(0, docptr, NOP);
}
for (i = 0; i < 6; i++) {
if (DoC_is_MillenniumPlus(doc))
ecc_code[i] = ReadDOC_(docptr, DoC_Mplus_ECCSyndrome0 + i);
else
ecc_code[i] = ReadDOC_(docptr, DoC_ECCSyndrome0 + i);
if (ecc_code[i] != empty_write_ecc[i])
emptymatch = 0;
}
if (DoC_is_MillenniumPlus(doc))
WriteDOC(DOC_ECC_DIS, docptr, Mplus_ECCConf);
else
WriteDOC(DOC_ECC_DIS, docptr, ECCConf);
#if 0
if (emptymatch) {
for (i = 0; i < 512; i++) {
if (dat[i] == 0xff)
continue;
emptymatch = 0;
break;
}
}
if (emptymatch)
memset(ecc_code, 0xff, 6);
#endif
return 0;
}
static int doc200x_correct_data(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *isnull)
{
int i, ret = 0;
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
void __iomem *docptr = doc->virtadr;
uint8_t calc_ecc[6];
volatile u_char dummy;
int emptymatch = 1;
if (DoC_is_2000(doc)) {
dummy = ReadDOC(docptr, 2k_ECCStatus);
dummy = ReadDOC(docptr, 2k_ECCStatus);
dummy = ReadDOC(docptr, 2k_ECCStatus);
} else if (DoC_is_MillenniumPlus(doc)) {
dummy = ReadDOC(docptr, Mplus_ECCConf);
dummy = ReadDOC(docptr, Mplus_ECCConf);
dummy = ReadDOC(docptr, Mplus_ECCConf);
} else {
dummy = ReadDOC(docptr, ECCConf);
dummy = ReadDOC(docptr, ECCConf);
dummy = ReadDOC(docptr, ECCConf);
}
if (dummy & 0x80) {
for (i = 0; i < 6; i++) {
if (DoC_is_MillenniumPlus(doc))
calc_ecc[i] = ReadDOC_(docptr, DoC_Mplus_ECCSyndrome0 + i);
else
calc_ecc[i] = ReadDOC_(docptr, DoC_ECCSyndrome0 + i);
if (calc_ecc[i] != empty_read_syndrome[i])
emptymatch = 0;
}
if (emptymatch) {
for (i = 0; i < 6; i++) {
if (read_ecc[i] == 0xff)
continue;
emptymatch = 0;
break;
}
}
if (emptymatch) {
for (i = 0; i < 512; i++) {
if (dat[i] == 0xff)
continue;
emptymatch = 0;
break;
}
}
if (!emptymatch)
ret = doc_ecc_decode(rs_decoder, dat, calc_ecc);
if (ret > 0)
printk(KERN_ERR "doc200x_correct_data corrected %d errors\n", ret);
}
if (DoC_is_MillenniumPlus(doc))
WriteDOC(DOC_ECC_DIS, docptr, Mplus_ECCConf);
else
WriteDOC(DOC_ECC_DIS, docptr, ECCConf);
if (no_ecc_failures && (ret == -EBADMSG)) {
printk(KERN_ERR "suppressing ECC failure\n");
ret = 0;
}
return ret;
}
static int __init find_media_headers(struct mtd_info *mtd, u_char *buf, const char *id, int findmirror)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
unsigned offs;
int ret;
size_t retlen;
for (offs = 0; offs < mtd->size; offs += mtd->erasesize) {
ret = mtd->read(mtd, offs, mtd->writesize, &retlen, buf);
if (retlen != mtd->writesize)
continue;
if (ret) {
printk(KERN_WARNING "ECC error scanning DOC at 0x%x\n", offs);
}
if (memcmp(buf, id, 6))
continue;
printk(KERN_INFO "Found DiskOnChip %s Media Header at 0x%x\n", id, offs);
if (doc->mh0_page == -1) {
doc->mh0_page = offs >> this->page_shift;
if (!findmirror)
return 1;
continue;
}
doc->mh1_page = offs >> this->page_shift;
return 2;
}
if (doc->mh0_page == -1) {
printk(KERN_WARNING "DiskOnChip %s Media Header not found.\n", id);
return 0;
}
offs = doc->mh0_page << this->page_shift;
ret = mtd->read(mtd, offs, mtd->writesize, &retlen, buf);
if (retlen != mtd->writesize) {
printk(KERN_ERR "Read DiskOnChip Media Header once, but can't reread it???\n");
return 0;
}
return 1;
}
static inline int __init nftl_partscan(struct mtd_info *mtd, struct mtd_partition *parts)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
int ret = 0;
u_char *buf;
struct NFTLMediaHeader *mh;
const unsigned psize = 1 << this->page_shift;
int numparts = 0;
unsigned blocks, maxblocks;
int offs, numheaders;
buf = kmalloc(mtd->writesize, GFP_KERNEL);
if (!buf) {
printk(KERN_ERR "DiskOnChip mediaheader kmalloc failed!\n");
return 0;
}
if (!(numheaders = find_media_headers(mtd, buf, "ANAND", 1)))
goto out;
mh = (struct NFTLMediaHeader *)buf;
le16_to_cpus(&mh->NumEraseUnits);
le16_to_cpus(&mh->FirstPhysicalEUN);
le32_to_cpus(&mh->FormattedSize);
printk(KERN_INFO " DataOrgID = %s\n"
" NumEraseUnits = %d\n"
" FirstPhysicalEUN = %d\n"
" FormattedSize = %d\n"
" UnitSizeFactor = %d\n",
mh->DataOrgID, mh->NumEraseUnits,
mh->FirstPhysicalEUN, mh->FormattedSize,
mh->UnitSizeFactor);
blocks = mtd->size >> this->phys_erase_shift;
maxblocks = min(32768U, mtd->erasesize - psize);
if (mh->UnitSizeFactor == 0x00) {
mh->UnitSizeFactor = 0xff;
while (blocks > maxblocks) {
blocks >>= 1;
maxblocks = min(32768U, (maxblocks << 1) + psize);
mh->UnitSizeFactor--;
}
printk(KERN_WARNING "UnitSizeFactor=0x00 detected. Correct value is assumed to be 0x%02x.\n", mh->UnitSizeFactor);
}
if (mh->UnitSizeFactor != 0xff) {
this->bbt_erase_shift += (0xff - mh->UnitSizeFactor);
mtd->erasesize <<= (0xff - mh->UnitSizeFactor);
printk(KERN_INFO "Setting virtual erase size to %d\n", mtd->erasesize);
blocks = mtd->size >> this->bbt_erase_shift;
maxblocks = min(32768U, mtd->erasesize - psize);
}
if (blocks > maxblocks) {
printk(KERN_ERR "UnitSizeFactor of 0x%02x is inconsistent with device size. Aborting.\n", mh->UnitSizeFactor);
goto out;
}
offs = max(doc->mh0_page, doc->mh1_page);
offs <<= this->page_shift;
offs += mtd->erasesize;
if (show_firmware_partition == 1) {
parts[0].name = " DiskOnChip Firmware / Media Header partition";
parts[0].offset = 0;
parts[0].size = offs;
numparts = 1;
}
parts[numparts].name = " DiskOnChip BDTL partition";
parts[numparts].offset = offs;
parts[numparts].size = (mh->NumEraseUnits - numheaders) << this->bbt_erase_shift;
offs += parts[numparts].size;
numparts++;
if (offs < mtd->size) {
parts[numparts].name = " DiskOnChip Remainder partition";
parts[numparts].offset = offs;
parts[numparts].size = mtd->size - offs;
numparts++;
}
ret = numparts;
out:
kfree(buf);
return ret;
}
static inline int __init inftl_partscan(struct mtd_info *mtd, struct mtd_partition *parts)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
int ret = 0;
u_char *buf;
struct INFTLMediaHeader *mh;
struct INFTLPartition *ip;
int numparts = 0;
int blocks;
int vshift, lastvunit = 0;
int i;
int end = mtd->size;
if (inftl_bbt_write)
end -= (INFTL_BBT_RESERVED_BLOCKS << this->phys_erase_shift);
buf = kmalloc(mtd->writesize, GFP_KERNEL);
if (!buf) {
printk(KERN_ERR "DiskOnChip mediaheader kmalloc failed!\n");
return 0;
}
if (!find_media_headers(mtd, buf, "BNAND", 0))
goto out;
doc->mh1_page = doc->mh0_page + (4096 >> this->page_shift);
mh = (struct INFTLMediaHeader *)buf;
le32_to_cpus(&mh->NoOfBootImageBlocks);
le32_to_cpus(&mh->NoOfBinaryPartitions);
le32_to_cpus(&mh->NoOfBDTLPartitions);
le32_to_cpus(&mh->BlockMultiplierBits);
le32_to_cpus(&mh->FormatFlags);
le32_to_cpus(&mh->PercentUsed);
printk(KERN_INFO " bootRecordID = %s\n"
" NoOfBootImageBlocks = %d\n"
" NoOfBinaryPartitions = %d\n"
" NoOfBDTLPartitions = %d\n"
" BlockMultiplerBits = %d\n"
" FormatFlgs = %d\n"
" OsakVersion = %d.%d.%d.%d\n"
" PercentUsed = %d\n",
mh->bootRecordID, mh->NoOfBootImageBlocks,
mh->NoOfBinaryPartitions,
mh->NoOfBDTLPartitions,
mh->BlockMultiplierBits, mh->FormatFlags,
((unsigned char *) &mh->OsakVersion)[0] & 0xf,
((unsigned char *) &mh->OsakVersion)[1] & 0xf,
((unsigned char *) &mh->OsakVersion)[2] & 0xf,
((unsigned char *) &mh->OsakVersion)[3] & 0xf,
mh->PercentUsed);
vshift = this->phys_erase_shift + mh->BlockMultiplierBits;
blocks = mtd->size >> vshift;
if (blocks > 32768) {
printk(KERN_ERR "BlockMultiplierBits=%d is inconsistent with device size. Aborting.\n", mh->BlockMultiplierBits);
goto out;
}
blocks = doc->chips_per_floor << (this->chip_shift - this->phys_erase_shift);
if (inftl_bbt_write && (blocks > mtd->erasesize)) {
printk(KERN_ERR "Writeable BBTs spanning more than one erase block are not yet supported. FIX ME!\n");
goto out;
}
for (i = 0; (i < 4); i++) {
ip = &(mh->Partitions[i]);
le32_to_cpus(&ip->virtualUnits);
le32_to_cpus(&ip->firstUnit);
le32_to_cpus(&ip->lastUnit);
le32_to_cpus(&ip->flags);
le32_to_cpus(&ip->spareUnits);
le32_to_cpus(&ip->Reserved0);
printk(KERN_INFO " PARTITION[%d] ->\n"
" virtualUnits = %d\n"
" firstUnit = %d\n"
" lastUnit = %d\n"
" flags = 0x%x\n"
" spareUnits = %d\n",
i, ip->virtualUnits, ip->firstUnit,
ip->lastUnit, ip->flags,
ip->spareUnits);
if ((show_firmware_partition == 1) &&
(i == 0) && (ip->firstUnit > 0)) {
parts[0].name = " DiskOnChip IPL / Media Header partition";
parts[0].offset = 0;
parts[0].size = mtd->erasesize * ip->firstUnit;
numparts = 1;
}
if (ip->flags & INFTL_BINARY)
parts[numparts].name = " DiskOnChip BDK partition";
else
parts[numparts].name = " DiskOnChip BDTL partition";
parts[numparts].offset = ip->firstUnit << vshift;
parts[numparts].size = (1 + ip->lastUnit - ip->firstUnit) << vshift;
numparts++;
if (ip->lastUnit > lastvunit)
lastvunit = ip->lastUnit;
if (ip->flags & INFTL_LAST)
break;
}
lastvunit++;
if ((lastvunit << vshift) < end) {
parts[numparts].name = " DiskOnChip Remainder partition";
parts[numparts].offset = lastvunit << vshift;
parts[numparts].size = end - parts[numparts].offset;
numparts++;
}
ret = numparts;
out:
kfree(buf);
return ret;
}
static int __init nftl_scan_bbt(struct mtd_info *mtd)
{
int ret, numparts;
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
struct mtd_partition parts[2];
memset((char *)parts, 0, sizeof(parts));
numparts = nftl_partscan(mtd, parts);
if (!numparts)
return -EIO;
this->bbt_td->options = NAND_BBT_ABSPAGE | NAND_BBT_8BIT |
NAND_BBT_SAVECONTENT | NAND_BBT_WRITE |
NAND_BBT_VERSION;
this->bbt_td->veroffs = 7;
this->bbt_td->pages[0] = doc->mh0_page + 1;
if (doc->mh1_page != -1) {
this->bbt_md->options = NAND_BBT_ABSPAGE | NAND_BBT_8BIT |
NAND_BBT_SAVECONTENT | NAND_BBT_WRITE |
NAND_BBT_VERSION;
this->bbt_md->veroffs = 7;
this->bbt_md->pages[0] = doc->mh1_page + 1;
} else {
this->bbt_md = NULL;
}
if ((ret = nand_scan_bbt(mtd, NULL)))
return ret;
mtd_device_register(mtd, NULL, 0);
if (!no_autopart)
mtd_device_register(mtd, parts, numparts);
return 0;
}
static int __init inftl_scan_bbt(struct mtd_info *mtd)
{
int ret, numparts;
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
struct mtd_partition parts[5];
if (this->numchips > doc->chips_per_floor) {
printk(KERN_ERR "Multi-floor INFTL devices not yet supported.\n");
return -EIO;
}
if (DoC_is_MillenniumPlus(doc)) {
this->bbt_td->options = NAND_BBT_2BIT | NAND_BBT_ABSPAGE;
if (inftl_bbt_write)
this->bbt_td->options |= NAND_BBT_WRITE;
this->bbt_td->pages[0] = 2;
this->bbt_md = NULL;
} else {
this->bbt_td->options = NAND_BBT_LASTBLOCK | NAND_BBT_8BIT | NAND_BBT_VERSION;
if (inftl_bbt_write)
this->bbt_td->options |= NAND_BBT_WRITE;
this->bbt_td->offs = 8;
this->bbt_td->len = 8;
this->bbt_td->veroffs = 7;
this->bbt_td->maxblocks = INFTL_BBT_RESERVED_BLOCKS;
this->bbt_td->reserved_block_code = 0x01;
this->bbt_td->pattern = "MSYS_BBT";
this->bbt_md->options = NAND_BBT_LASTBLOCK | NAND_BBT_8BIT | NAND_BBT_VERSION;
if (inftl_bbt_write)
this->bbt_md->options |= NAND_BBT_WRITE;
this->bbt_md->offs = 8;
this->bbt_md->len = 8;
this->bbt_md->veroffs = 7;
this->bbt_md->maxblocks = INFTL_BBT_RESERVED_BLOCKS;
this->bbt_md->reserved_block_code = 0x01;
this->bbt_md->pattern = "TBB_SYSM";
}
if ((ret = nand_scan_bbt(mtd, NULL)))
return ret;
memset((char *)parts, 0, sizeof(parts));
numparts = inftl_partscan(mtd, parts);
if (!numparts)
return -EIO;
mtd_device_register(mtd, NULL, 0);
if (!no_autopart)
mtd_device_register(mtd, parts, numparts);
return 0;
}
static inline int __init doc2000_init(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
this->read_byte = doc2000_read_byte;
this->write_buf = doc2000_writebuf;
this->read_buf = doc2000_readbuf;
this->verify_buf = doc2000_verifybuf;
this->scan_bbt = nftl_scan_bbt;
doc->CDSNControl = CDSN_CTRL_FLASH_IO | CDSN_CTRL_ECC_IO;
doc2000_count_chips(mtd);
mtd->name = "DiskOnChip 2000 (NFTL Model)";
return (4 * doc->chips_per_floor);
}
static inline int __init doc2001_init(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
this->read_byte = doc2001_read_byte;
this->write_buf = doc2001_writebuf;
this->read_buf = doc2001_readbuf;
this->verify_buf = doc2001_verifybuf;
ReadDOC(doc->virtadr, ChipID);
ReadDOC(doc->virtadr, ChipID);
ReadDOC(doc->virtadr, ChipID);
if (ReadDOC(doc->virtadr, ChipID) != DOC_ChipID_DocMil) {
doc2000_count_chips(mtd);
mtd->name = "DiskOnChip 2000 (INFTL Model)";
this->scan_bbt = inftl_scan_bbt;
return (4 * doc->chips_per_floor);
} else {
doc->chips_per_floor = 1;
mtd->name = "DiskOnChip Millennium";
this->scan_bbt = nftl_scan_bbt;
return 1;
}
}
static inline int __init doc2001plus_init(struct mtd_info *mtd)
{
struct nand_chip *this = mtd->priv;
struct doc_priv *doc = this->priv;
this->read_byte = doc2001plus_read_byte;
this->write_buf = doc2001plus_writebuf;
this->read_buf = doc2001plus_readbuf;
this->verify_buf = doc2001plus_verifybuf;
this->scan_bbt = inftl_scan_bbt;
this->cmd_ctrl = NULL;
this->select_chip = doc2001plus_select_chip;
this->cmdfunc = doc2001plus_command;
this->ecc.hwctl = doc2001plus_enable_hwecc;
doc->chips_per_floor = 1;
mtd->name = "DiskOnChip Millennium Plus";
return 1;
}
static int __init doc_probe(unsigned long physadr)
{
unsigned char ChipID;
struct mtd_info *mtd;
struct nand_chip *nand;
struct doc_priv *doc;
void __iomem *virtadr;
unsigned char save_control;
unsigned char tmp, tmpb, tmpc;
int reg, len, numchips;
int ret = 0;
virtadr = ioremap(physadr, DOC_IOREMAP_LEN);
if (!virtadr) {
printk(KERN_ERR "Diskonchip ioremap failed: 0x%x bytes at 0x%lx\n", DOC_IOREMAP_LEN, physadr);
return -EIO;
}
save_control = ReadDOC(virtadr, DOCControl);
WriteDOC(DOC_MODE_CLR_ERR | DOC_MODE_MDWREN | DOC_MODE_RESET, virtadr, DOCControl);
WriteDOC(DOC_MODE_CLR_ERR | DOC_MODE_MDWREN | DOC_MODE_RESET, virtadr, DOCControl);
WriteDOC(DOC_MODE_CLR_ERR | DOC_MODE_MDWREN | DOC_MODE_NORMAL, virtadr, DOCControl);
WriteDOC(DOC_MODE_CLR_ERR | DOC_MODE_MDWREN | DOC_MODE_NORMAL, virtadr, DOCControl);
ChipID = ReadDOC(virtadr, ChipID);
switch (ChipID) {
case DOC_ChipID_Doc2k:
reg = DoC_2k_ECCStatus;
break;
case DOC_ChipID_DocMil:
reg = DoC_ECCConf;
break;
case DOC_ChipID_DocMilPlus16:
case DOC_ChipID_DocMilPlus32:
case 0:
for (tmp = 0; (tmp < 4); tmp++)
ReadDOC(virtadr, Mplus_Power);
tmp = DOC_MODE_RESET | DOC_MODE_MDWREN | DOC_MODE_RST_LAT | DOC_MODE_BDECT;
WriteDOC(tmp, virtadr, Mplus_DOCControl);
WriteDOC(~tmp, virtadr, Mplus_CtrlConfirm);
mdelay(1);
tmp = DOC_MODE_NORMAL | DOC_MODE_MDWREN | DOC_MODE_RST_LAT | DOC_MODE_BDECT;
WriteDOC(tmp, virtadr, Mplus_DOCControl);
WriteDOC(~tmp, virtadr, Mplus_CtrlConfirm);
mdelay(1);
ChipID = ReadDOC(virtadr, ChipID);
switch (ChipID) {
case DOC_ChipID_DocMilPlus16:
reg = DoC_Mplus_Toggle;
break;
case DOC_ChipID_DocMilPlus32:
printk(KERN_ERR "DiskOnChip Millennium Plus 32MB is not supported, ignoring.\n");
default:
ret = -ENODEV;
goto notfound;
}
break;
default:
ret = -ENODEV;
goto notfound;
}
tmp = ReadDOC_(virtadr, reg) & DOC_TOGGLE_BIT;
tmpb = ReadDOC_(virtadr, reg) & DOC_TOGGLE_BIT;
tmpc = ReadDOC_(virtadr, reg) & DOC_TOGGLE_BIT;
if ((tmp == tmpb) || (tmp != tmpc)) {
printk(KERN_WARNING "Possible DiskOnChip at 0x%lx failed TOGGLE test, dropping.\n", physadr);
ret = -ENODEV;
goto notfound;
}
for (mtd = doclist; mtd; mtd = doc->nextdoc) {
unsigned char oldval;
unsigned char newval;
nand = mtd->priv;
doc = nand->priv;
if (ChipID == DOC_ChipID_DocMilPlus16) {
oldval = ReadDOC(doc->virtadr, Mplus_AliasResolution);
newval = ReadDOC(virtadr, Mplus_AliasResolution);
} else {
oldval = ReadDOC(doc->virtadr, AliasResolution);
newval = ReadDOC(virtadr, AliasResolution);
}
if (oldval != newval)
continue;
if (ChipID == DOC_ChipID_DocMilPlus16) {
WriteDOC(~newval, virtadr, Mplus_AliasResolution);
oldval = ReadDOC(doc->virtadr, Mplus_AliasResolution);
WriteDOC(newval, virtadr, Mplus_AliasResolution);
} else {
WriteDOC(~newval, virtadr, AliasResolution);
oldval = ReadDOC(doc->virtadr, AliasResolution);
WriteDOC(newval, virtadr, AliasResolution);
}
newval = ~newval;
if (oldval == newval) {
printk(KERN_DEBUG "Found alias of DOC at 0x%lx to 0x%lx\n", doc->physadr, physadr);
goto notfound;
}
}
printk(KERN_NOTICE "DiskOnChip found at 0x%lx\n", physadr);
len = sizeof(struct mtd_info) +
sizeof(struct nand_chip) + sizeof(struct doc_priv) + (2 * sizeof(struct nand_bbt_descr));
mtd = kzalloc(len, GFP_KERNEL);
if (!mtd) {
printk(KERN_ERR "DiskOnChip kmalloc (%d bytes) failed!\n", len);
ret = -ENOMEM;
goto fail;
}
nand = (struct nand_chip *) (mtd + 1);
doc = (struct doc_priv *) (nand + 1);
nand->bbt_td = (struct nand_bbt_descr *) (doc + 1);
nand->bbt_md = nand->bbt_td + 1;
mtd->priv = nand;
mtd->owner = THIS_MODULE;
nand->priv = doc;
nand->select_chip = doc200x_select_chip;
nand->cmd_ctrl = doc200x_hwcontrol;
nand->dev_ready = doc200x_dev_ready;
nand->waitfunc = doc200x_wait;
nand->block_bad = doc200x_block_bad;
nand->ecc.hwctl = doc200x_enable_hwecc;
nand->ecc.calculate = doc200x_calculate_ecc;
nand->ecc.correct = doc200x_correct_data;
nand->ecc.layout = &doc200x_oobinfo;
nand->ecc.mode = NAND_ECC_HW_SYNDROME;
nand->ecc.size = 512;
nand->ecc.bytes = 6;
nand->options = NAND_USE_FLASH_BBT;
doc->physadr = physadr;
doc->virtadr = virtadr;
doc->ChipID = ChipID;
doc->curfloor = -1;
doc->curchip = -1;
doc->mh0_page = -1;
doc->mh1_page = -1;
doc->nextdoc = doclist;
if (ChipID == DOC_ChipID_Doc2k)
numchips = doc2000_init(mtd);
else if (ChipID == DOC_ChipID_DocMilPlus16)
numchips = doc2001plus_init(mtd);
else
numchips = doc2001_init(mtd);
if ((ret = nand_scan(mtd, numchips))) {
nand_release(mtd);
kfree(mtd);
goto fail;
}
doclist = mtd;
return 0;
notfound:
WriteDOC(save_control, virtadr, DOCControl);
fail:
iounmap(virtadr);
return ret;
}
static void release_nanddoc(void)
{
struct mtd_info *mtd, *nextmtd;
struct nand_chip *nand;
struct doc_priv *doc;
for (mtd = doclist; mtd; mtd = nextmtd) {
nand = mtd->priv;
doc = nand->priv;
nextmtd = doc->nextdoc;
nand_release(mtd);
iounmap(doc->virtadr);
kfree(mtd);
}
}
static int __init init_nanddoc(void)
{
int i, ret = 0;
rs_decoder = init_rs(10, 0x409, FCR, 1, NROOTS);
if (!rs_decoder) {
printk(KERN_ERR "DiskOnChip: Could not create a RS decoder\n");
return -ENOMEM;
}
if (doc_config_location) {
printk(KERN_INFO "Using configured DiskOnChip probe address 0x%lx\n", doc_config_location);
ret = doc_probe(doc_config_location);
if (ret < 0)
goto outerr;
} else {
for (i = 0; (doc_locations[i] != 0xffffffff); i++) {
doc_probe(doc_locations[i]);
}
}
if (!doclist) {
printk(KERN_INFO "No valid DiskOnChip devices found\n");
ret = -ENODEV;
goto outerr;
}
return 0;
outerr:
free_rs(rs_decoder);
return ret;
}
static void __exit cleanup_nanddoc(void)
{
release_nanddoc();
if (rs_decoder) {
free_rs(rs_decoder);
}
}
