static inline u8 bcm47xxnflash_ops_bcm4706_ns_to_cycle(u16 ns, u16 clock)
{
return ((ns * 1000 * clock) / 1000000) + 1;
}
static int bcm47xxnflash_ops_bcm4706_ctl_cmd(struct bcma_drv_cc *cc, u32 code)
{
int i = 0;
bcma_cc_write32(cc, BCMA_CC_NFLASH_CTL, NCTL_START | code);
for (i = 0; i < NFLASH_READY_RETRIES; i++) {
if (!(bcma_cc_read32(cc, BCMA_CC_NFLASH_CTL) & NCTL_START)) {
i = 0;
break;
}
}
if (i) {
pr_err("NFLASH control command not ready!\n");
return -EBUSY;
}
return 0;
}
static int bcm47xxnflash_ops_bcm4706_poll(struct bcma_drv_cc *cc)
{
int i;
for (i = 0; i < NFLASH_READY_RETRIES; i++) {
if (bcma_cc_read32(cc, BCMA_CC_NFLASH_CTL) & NCTL_READY) {
if (bcma_cc_read32(cc, BCMA_CC_NFLASH_CTL) &
BCMA_CC_NFLASH_CTL_ERR) {
pr_err("Error on polling\n");
return -EBUSY;
} else {
return 0;
}
}
}
pr_err("Polling timeout!\n");
return -EBUSY;
}
static void bcm47xxnflash_ops_bcm4706_read(struct mtd_info *mtd, uint8_t *buf,
int len)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
u32 ctlcode;
u32 *dest = (u32 *)buf;
int i;
int toread;
BUG_ON(b47n->curr_page_addr & ~nand_chip->pagemask);
while (len) {
toread = min(len, 0x200);
bcma_cc_write32(b47n->cc, BCMA_CC_NFLASH_COL_ADDR,
b47n->curr_column);
bcma_cc_write32(b47n->cc, BCMA_CC_NFLASH_ROW_ADDR,
b47n->curr_page_addr);
ctlcode = NCTL_CSA | NCTL_CMD1W | NCTL_ROW | NCTL_COL |
NCTL_CMD0;
ctlcode |= NAND_CMD_READSTART << 8;
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(b47n->cc, ctlcode))
return;
if (bcm47xxnflash_ops_bcm4706_poll(b47n->cc))
return;
for (i = 0; i < toread; i += 4, dest++) {
ctlcode = NCTL_CSA | 0x30000000 | NCTL_READ;
if (i == toread - 4)
ctlcode &= ~NCTL_CSA;
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(b47n->cc,
ctlcode))
return;
*dest = bcma_cc_read32(b47n->cc, BCMA_CC_NFLASH_DATA);
}
b47n->curr_column += toread;
len -= toread;
}
}
static void bcm47xxnflash_ops_bcm4706_write(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
struct bcma_drv_cc *cc = b47n->cc;
u32 ctlcode;
const u32 *data = (u32 *)buf;
int i;
BUG_ON(b47n->curr_page_addr & ~nand_chip->pagemask);
for (i = 0; i < len; i += 4, data++) {
bcma_cc_write32(cc, BCMA_CC_NFLASH_DATA, *data);
ctlcode = NCTL_CSA | 0x30000000 | NCTL_WRITE;
if (i == len - 4)
ctlcode &= ~NCTL_CSA;
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(cc, ctlcode)) {
pr_err("%s ctl_cmd didn't work!\n", __func__);
return;
}
}
b47n->curr_column += len;
}
static void bcm47xxnflash_ops_bcm4706_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
u32 code = 0;
if (cmd == NAND_CMD_NONE)
return;
if (cmd & NAND_CTRL_CLE)
code = cmd | NCTL_CMD0;
if (cmd != NAND_CMD_RESET)
code |= NCTL_CSA;
bcm47xxnflash_ops_bcm4706_ctl_cmd(b47n->cc, code);
}
static void bcm47xxnflash_ops_bcm4706_select_chip(struct mtd_info *mtd,
int chip)
{
return;
}
static int bcm47xxnflash_ops_bcm4706_dev_ready(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
return !!(bcma_cc_read32(b47n->cc, BCMA_CC_NFLASH_CTL) & NCTL_READY);
}
static void bcm47xxnflash_ops_bcm4706_cmdfunc(struct mtd_info *mtd,
unsigned command, int column,
int page_addr)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
struct bcma_drv_cc *cc = b47n->cc;
u32 ctlcode;
int i;
if (column != -1)
b47n->curr_column = column;
if (page_addr != -1)
b47n->curr_page_addr = page_addr;
switch (command) {
case NAND_CMD_RESET:
nand_chip->cmd_ctrl(mtd, command, NAND_CTRL_CLE);
ndelay(100);
nand_wait_ready(mtd);
break;
case NAND_CMD_READID:
ctlcode = NCTL_CSA | 0x01000000 | NCTL_CMD1W | NCTL_CMD0;
ctlcode |= NAND_CMD_READID;
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(b47n->cc, ctlcode)) {
pr_err("READID error\n");
break;
}
for (i = 0; i < ARRAY_SIZE(b47n->id_data); i++) {
ctlcode = NCTL_CSA | NCTL_READ;
if (i == ARRAY_SIZE(b47n->id_data) - 1)
ctlcode &= ~NCTL_CSA;
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(b47n->cc,
ctlcode)) {
pr_err("READID error\n");
break;
}
b47n->id_data[i] =
bcma_cc_read32(b47n->cc, BCMA_CC_NFLASH_DATA)
& 0xFF;
}
break;
case NAND_CMD_STATUS:
ctlcode = NCTL_CSA | NCTL_CMD0 | NAND_CMD_STATUS;
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(cc, ctlcode))
pr_err("STATUS command error\n");
break;
case NAND_CMD_READ0:
break;
case NAND_CMD_READOOB:
if (page_addr != -1)
b47n->curr_column += mtd->writesize;
break;
case NAND_CMD_ERASE1:
bcma_cc_write32(cc, BCMA_CC_NFLASH_ROW_ADDR,
b47n->curr_page_addr);
ctlcode = NCTL_ROW | NCTL_CMD1W | NCTL_CMD0 |
NAND_CMD_ERASE1 | (NAND_CMD_ERASE2 << 8);
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(cc, ctlcode))
pr_err("ERASE1 failed\n");
break;
case NAND_CMD_ERASE2:
break;
case NAND_CMD_SEQIN:
bcma_cc_write32(cc, BCMA_CC_NFLASH_COL_ADDR,
b47n->curr_column);
bcma_cc_write32(cc, BCMA_CC_NFLASH_ROW_ADDR,
b47n->curr_page_addr);
ctlcode = 0x40000000 | NCTL_ROW | NCTL_COL | NCTL_CMD0;
ctlcode |= NAND_CMD_SEQIN;
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(cc, ctlcode))
pr_err("SEQIN failed\n");
break;
case NAND_CMD_PAGEPROG:
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(cc, NCTL_CMD0 |
NAND_CMD_PAGEPROG))
pr_err("PAGEPROG failed\n");
if (bcm47xxnflash_ops_bcm4706_poll(cc))
pr_err("PAGEPROG not ready\n");
break;
default:
pr_err("Command 0x%X unsupported\n", command);
break;
}
b47n->curr_command = command;
}
static u8 bcm47xxnflash_ops_bcm4706_read_byte(struct mtd_info *mtd)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
struct bcma_drv_cc *cc = b47n->cc;
u32 tmp = 0;
switch (b47n->curr_command) {
case NAND_CMD_READID:
if (b47n->curr_column >= ARRAY_SIZE(b47n->id_data)) {
pr_err("Requested invalid id_data: %d\n",
b47n->curr_column);
return 0;
}
return b47n->id_data[b47n->curr_column++];
case NAND_CMD_STATUS:
if (bcm47xxnflash_ops_bcm4706_ctl_cmd(cc, NCTL_READ))
return 0;
return bcma_cc_read32(cc, BCMA_CC_NFLASH_DATA) & 0xff;
case NAND_CMD_READOOB:
bcm47xxnflash_ops_bcm4706_read(mtd, (u8 *)&tmp, 4);
return tmp & 0xFF;
}
pr_err("Invalid command for byte read: 0x%X\n", b47n->curr_command);
return 0;
}
static void bcm47xxnflash_ops_bcm4706_read_buf(struct mtd_info *mtd,
uint8_t *buf, int len)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
switch (b47n->curr_command) {
case NAND_CMD_READ0:
case NAND_CMD_READOOB:
bcm47xxnflash_ops_bcm4706_read(mtd, buf, len);
return;
}
pr_err("Invalid command for buf read: 0x%X\n", b47n->curr_command);
}
static void bcm47xxnflash_ops_bcm4706_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
struct nand_chip *nand_chip = (struct nand_chip *)mtd->priv;
struct bcm47xxnflash *b47n = (struct bcm47xxnflash *)nand_chip->priv;
switch (b47n->curr_command) {
case NAND_CMD_SEQIN:
bcm47xxnflash_ops_bcm4706_write(mtd, buf, len);
return;
}
pr_err("Invalid command for buf write: 0x%X\n", b47n->curr_command);
}
int bcm47xxnflash_ops_bcm4706_init(struct bcm47xxnflash *b47n)
{
struct nand_chip *nand_chip = (struct nand_chip *)&b47n->nand_chip;
int err;
u32 freq;
u16 clock;
u8 w0, w1, w2, w3, w4;
unsigned long chipsize;
u8 tbits, col_bits, col_size, row_bits, row_bsize;
u32 val;
b47n->nand_chip.select_chip = bcm47xxnflash_ops_bcm4706_select_chip;
nand_chip->cmd_ctrl = bcm47xxnflash_ops_bcm4706_cmd_ctrl;
nand_chip->dev_ready = bcm47xxnflash_ops_bcm4706_dev_ready;
b47n->nand_chip.cmdfunc = bcm47xxnflash_ops_bcm4706_cmdfunc;
b47n->nand_chip.read_byte = bcm47xxnflash_ops_bcm4706_read_byte;
b47n->nand_chip.read_buf = bcm47xxnflash_ops_bcm4706_read_buf;
b47n->nand_chip.write_buf = bcm47xxnflash_ops_bcm4706_write_buf;
nand_chip->chip_delay = 50;
b47n->nand_chip.bbt_options = NAND_BBT_USE_FLASH;
b47n->nand_chip.ecc.mode = NAND_ECC_NONE;
bcma_cc_set32(b47n->cc, BCMA_CC_4706_FLASHSCFG,
BCMA_CC_4706_FLASHSCFG_NF1);
if (b47n->cc->status & BCMA_CC_CHIPST_4706_PKG_OPTION) {
freq = 400000000 / 4;
} else {
freq = bcma_chipco_pll_read(b47n->cc, 4);
freq = (freq & 0xFFF) >> 3;
freq = (freq * 25000000 / 2) / 4;
}
clock = freq / 1000000;
w0 = bcm47xxnflash_ops_bcm4706_ns_to_cycle(15, clock);
w1 = bcm47xxnflash_ops_bcm4706_ns_to_cycle(20, clock);
w2 = bcm47xxnflash_ops_bcm4706_ns_to_cycle(10, clock);
w3 = bcm47xxnflash_ops_bcm4706_ns_to_cycle(10, clock);
w4 = bcm47xxnflash_ops_bcm4706_ns_to_cycle(100, clock);
bcma_cc_write32(b47n->cc, BCMA_CC_NFLASH_WAITCNT0,
(w4 << 24 | w3 << 18 | w2 << 12 | w1 << 6 | w0));
err = nand_scan(&b47n->mtd, 1);
if (err) {
pr_err("Could not scan NAND flash: %d\n", err);
goto exit;
}
chipsize = b47n->nand_chip.chipsize >> 20;
tbits = ffs(chipsize);
if (!tbits || tbits != fls(chipsize)) {
pr_err("Invalid flash size: 0x%lX\n", chipsize);
err = -ENOTSUPP;
goto exit;
}
tbits += 19;
col_bits = b47n->nand_chip.page_shift + 1;
col_size = (col_bits + 7) / 8;
row_bits = tbits - col_bits + 1;
row_bsize = (row_bits + 7) / 8;
val = ((row_bsize - 1) << 6) | ((col_size - 1) << 4) | 2;
bcma_cc_write32(b47n->cc, BCMA_CC_NFLASH_CONF, val);
exit:
if (err)
bcma_cc_mask32(b47n->cc, BCMA_CC_4706_FLASHSCFG,
~BCMA_CC_4706_FLASHSCFG_NF1);
return err;
}
