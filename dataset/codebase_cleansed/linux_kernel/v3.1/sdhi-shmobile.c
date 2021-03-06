static inline u16 sd_ctrl_read16(void __iomem *base, int addr)
{
return __raw_readw(base + addr);
}
static inline u32 sd_ctrl_read32(void __iomem *base, int addr)
{
return __raw_readw(base + addr) |
__raw_readw(base + addr + 2) << 16;
}
static inline void sd_ctrl_write16(void __iomem *base, int addr, u16 val)
{
__raw_writew(val, base + addr);
}
static inline void sd_ctrl_write32(void __iomem *base, int addr, u32 val)
{
__raw_writew(val, base + addr);
__raw_writew(val >> 16, base + addr + 2);
}
static int sdhi_intr(void __iomem *base)
{
unsigned long state = sd_ctrl_read32(base, CTL_STATUS);
if (state & ALL_ERROR) {
sd_ctrl_write32(base, CTL_STATUS, ~ALL_ERROR);
sd_ctrl_write32(base, CTL_IRQ_MASK,
ALL_ERROR |
sd_ctrl_read32(base, CTL_IRQ_MASK));
return -EINVAL;
}
if (state & TMIO_STAT_CMDRESPEND) {
sd_ctrl_write32(base, CTL_STATUS, ~TMIO_STAT_CMDRESPEND);
sd_ctrl_write32(base, CTL_IRQ_MASK,
TMIO_STAT_CMDRESPEND |
sd_ctrl_read32(base, CTL_IRQ_MASK));
return 0;
}
if (state & TMIO_STAT_RXRDY) {
sd_ctrl_write32(base, CTL_STATUS, ~TMIO_STAT_RXRDY);
sd_ctrl_write32(base, CTL_IRQ_MASK,
TMIO_STAT_RXRDY | TMIO_STAT_TXUNDERRUN |
sd_ctrl_read32(base, CTL_IRQ_MASK));
return 0;
}
if (state & TMIO_STAT_DATAEND) {
sd_ctrl_write32(base, CTL_STATUS, ~TMIO_STAT_DATAEND);
sd_ctrl_write32(base, CTL_IRQ_MASK,
TMIO_STAT_DATAEND |
sd_ctrl_read32(base, CTL_IRQ_MASK));
return 0;
}
return -EAGAIN;
}
static int sdhi_boot_wait_resp_end(void __iomem *base)
{
int err = -EAGAIN, timeout = 10000000;
while (timeout--) {
err = sdhi_intr(base);
if (err != -EAGAIN)
break;
udelay(1);
}
return err;
}
static void sdhi_boot_mmc_clk_stop(void __iomem *base)
{
sd_ctrl_write16(base, CTL_CLK_AND_WAIT_CTL, 0x0000);
msleep(10);
sd_ctrl_write16(base, CTL_SD_CARD_CLK_CTL, ~CLK_MMC_ENABLE &
sd_ctrl_read16(base, CTL_SD_CARD_CLK_CTL));
msleep(10);
}
static void sdhi_boot_mmc_clk_start(void __iomem *base)
{
sd_ctrl_write16(base, CTL_SD_CARD_CLK_CTL, CLK_MMC_ENABLE |
sd_ctrl_read16(base, CTL_SD_CARD_CLK_CTL));
msleep(10);
sd_ctrl_write16(base, CTL_CLK_AND_WAIT_CTL, CLK_MMC_ENABLE);
msleep(10);
}
static void sdhi_boot_reset(void __iomem *base)
{
sd_ctrl_write16(base, CTL_RESET_SD, 0x0000);
msleep(10);
sd_ctrl_write16(base, CTL_RESET_SD, 0x0001);
msleep(10);
}
static int sdhi_boot_mmc_set_ios(void __iomem *base, struct mmc_ios *ios)
{
if (sd_ctrl_read32(base, CTL_STATUS) & TMIO_STAT_CMD_BUSY)
return -EBUSY;
if (ios->clock)
sd_ctrl_write16(base, CTL_SD_CARD_CLK_CTL,
ios->clock | CLK_MMC_ENABLE);
switch (ios->power_mode) {
case MMC_POWER_OFF:
sdhi_boot_mmc_clk_stop(base);
break;
case MMC_POWER_ON:
break;
case MMC_POWER_UP:
sdhi_boot_mmc_clk_start(base);
break;
}
switch (ios->bus_width) {
case MMC_BUS_WIDTH_1:
sd_ctrl_write16(base, CTL_SD_MEM_CARD_OPT, 0x80e0);
break;
case MMC_BUS_WIDTH_4:
sd_ctrl_write16(base, CTL_SD_MEM_CARD_OPT, 0x00e0);
break;
}
udelay(140);
return 0;
}
static int sdhi_boot_request(void __iomem *base, struct mmc_command *cmd)
{
int err, c = cmd->opcode;
switch (mmc_resp_type(cmd)) {
case MMC_RSP_NONE: c |= RESP_NONE; break;
case MMC_RSP_R1: c |= RESP_R1; break;
case MMC_RSP_R1B: c |= RESP_R1B; break;
case MMC_RSP_R2: c |= RESP_R2; break;
case MMC_RSP_R3: c |= RESP_R3; break;
default:
return -EINVAL;
}
sd_ctrl_write32(base, CTL_STATUS, ~TMIO_STAT_CMDRESPEND);
sd_ctrl_write32(base, CTL_IRQ_MASK, TMIO_STAT_CMDRESPEND |
sd_ctrl_read32(base, CTL_IRQ_MASK));
sd_ctrl_write32(base, CTL_ARG_REG, cmd->arg);
sd_ctrl_write16(base, CTL_SD_CMD, c);
sd_ctrl_write32(base, CTL_IRQ_MASK,
~(TMIO_STAT_CMDRESPEND | ALL_ERROR) &
sd_ctrl_read32(base, CTL_IRQ_MASK));
err = sdhi_boot_wait_resp_end(base);
if (err)
return err;
cmd->resp[0] = sd_ctrl_read32(base, CTL_RESPONSE);
return 0;
}
static int sdhi_boot_do_read_single(void __iomem *base, int high_capacity,
unsigned long block, unsigned short *buf)
{
int err, i;
{
struct mmc_command cmd;
cmd.opcode = MMC_READ_SINGLE_BLOCK | \
TRANSFER_READ | DATA_PRESENT;
if (high_capacity)
cmd.arg = block;
else
cmd.arg = block * TMIO_BBS;
cmd.flags = MMC_RSP_R1;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
}
sd_ctrl_write32(base, CTL_IRQ_MASK,
~(TMIO_STAT_DATAEND | TMIO_STAT_RXRDY |
TMIO_STAT_TXUNDERRUN) &
sd_ctrl_read32(base, CTL_IRQ_MASK));
err = sdhi_boot_wait_resp_end(base);
if (err)
return err;
sd_ctrl_write16(base, CTL_SD_XFER_LEN, TMIO_BBS);
for (i = 0; i < TMIO_BBS / sizeof(*buf); i++)
*buf++ = sd_ctrl_read16(base, RESP_CMD12);
err = sdhi_boot_wait_resp_end(base);
if (err)
return err;
return 0;
}
int sdhi_boot_do_read(void __iomem *base, int high_capacity,
unsigned long offset, unsigned short count,
unsigned short *buf)
{
unsigned long i;
int err = 0;
for (i = 0; i < count; i++) {
err = sdhi_boot_do_read_single(base, high_capacity, offset + i,
buf + (i * TMIO_BBS /
sizeof(*buf)));
if (err)
return err;
}
return 0;
}
int sdhi_boot_init(void __iomem *base)
{
bool sd_v2 = false, sd_v1_0 = false;
unsigned short cid;
int err, high_capacity = 0;
sdhi_boot_mmc_clk_stop(base);
sdhi_boot_reset(base);
{
struct mmc_ios ios;
ios.power_mode = MMC_POWER_ON;
ios.bus_width = MMC_BUS_WIDTH_1;
ios.clock = CLK_MMC_INIT;
err = sdhi_boot_mmc_set_ios(base, &ios);
if (err)
return err;
}
{
struct mmc_command cmd;
msleep(1);
cmd.opcode = MMC_GO_IDLE_STATE;
cmd.arg = 0;
cmd.flags = MMC_RSP_NONE;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
msleep(2);
}
{
struct mmc_command cmd;
cmd.opcode = SD_SEND_IF_COND;
cmd.arg = (VOLTAGES != 0) << 8 | 0xaa;
cmd.flags = MMC_RSP_R1;
err = sdhi_boot_request(base, &cmd);
if ((cmd.resp[0] & 0xff) == 0xaa)
sd_v2 = true;
}
{
int timeout = 1000;
struct mmc_command cmd;
cmd.arg = 0;
do {
cmd.opcode = MMC_APP_CMD;
cmd.flags = MMC_RSP_R1;
cmd.arg = 0;
err = sdhi_boot_request(base, &cmd);
if (err)
break;
cmd.opcode = SD_APP_OP_COND;
cmd.flags = MMC_RSP_R3;
cmd.arg = (VOLTAGES & 0xff8000);
if (sd_v2)
cmd.arg |= OCR_HCS;
cmd.arg |= OCR_FASTBOOT;
err = sdhi_boot_request(base, &cmd);
if (err)
break;
msleep(1);
} while((!(cmd.resp[0] & OCR_BUSY)) && --timeout);
if (!err && timeout) {
if (!sd_v2)
sd_v1_0 = true;
high_capacity = (cmd.resp[0] & OCR_HCS) == OCR_HCS;
}
}
if (!sd_v2 && !sd_v1_0) {
int timeout = 1000;
struct mmc_command cmd;
do {
cmd.opcode = MMC_SEND_OP_COND;
cmd.arg = VOLTAGES | OCR_HCS;
cmd.flags = MMC_RSP_R3;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
msleep(1);
} while((!(cmd.resp[0] & OCR_BUSY)) && --timeout);
if (!timeout)
return -EAGAIN;
high_capacity = (cmd.resp[0] & OCR_HCS) == OCR_HCS;
}
{
struct mmc_command cmd;
cmd.opcode = MMC_ALL_SEND_CID;
cmd.arg = 0;
cmd.flags = MMC_RSP_R2;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
}
{
struct mmc_command cmd;
cmd.opcode = MMC_SET_RELATIVE_ADDR;
cmd.arg = 0;
cmd.flags = MMC_RSP_R1;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
cid = cmd.resp[0] >> 16;
}
{
struct mmc_command cmd;
cmd.opcode = MMC_SEND_CSD;
cmd.arg = cid << 16;
cmd.flags = MMC_RSP_R2;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
}
{
struct mmc_command cmd;
cmd.opcode = MMC_SELECT_CARD;
cmd.arg = cid << 16;
cmd.flags = MMC_RSP_R1;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
}
{
struct mmc_command cmd;
cmd.opcode = MMC_SET_BLOCKLEN;
cmd.arg = TMIO_BBS;
cmd.flags = MMC_RSP_R1;
err = sdhi_boot_request(base, &cmd);
if (err)
return err;
}
return high_capacity;
}
