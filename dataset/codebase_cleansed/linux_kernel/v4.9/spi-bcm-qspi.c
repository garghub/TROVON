static inline bool has_bspi(struct bcm_qspi *qspi)
{
return qspi->bspi_mode;
}
static inline u32 bcm_qspi_read(struct bcm_qspi *qspi, enum base_type type,
unsigned int offset)
{
return bcm_qspi_readl(qspi->big_endian, qspi->base[type] + offset);
}
static inline void bcm_qspi_write(struct bcm_qspi *qspi, enum base_type type,
unsigned int offset, unsigned int data)
{
bcm_qspi_writel(qspi->big_endian, data, qspi->base[type] + offset);
}
static int bcm_qspi_bspi_busy_poll(struct bcm_qspi *qspi)
{
int i;
for (i = 0; i < 1000; i++) {
if (!(bcm_qspi_read(qspi, BSPI, BSPI_BUSY_STATUS) & 1))
return 0;
udelay(1);
}
dev_warn(&qspi->pdev->dev, "timeout waiting for !busy_status\n");
return -EIO;
}
static inline bool bcm_qspi_bspi_ver_three(struct bcm_qspi *qspi)
{
if (qspi->bspi_maj_rev < 4)
return true;
return false;
}
static void bcm_qspi_bspi_flush_prefetch_buffers(struct bcm_qspi *qspi)
{
bcm_qspi_bspi_busy_poll(qspi);
bcm_qspi_write(qspi, BSPI, BSPI_B0_CTRL, 1);
bcm_qspi_write(qspi, BSPI, BSPI_B1_CTRL, 1);
bcm_qspi_write(qspi, BSPI, BSPI_B0_CTRL, 0);
bcm_qspi_write(qspi, BSPI, BSPI_B1_CTRL, 0);
}
static int bcm_qspi_bspi_lr_is_fifo_empty(struct bcm_qspi *qspi)
{
return (bcm_qspi_read(qspi, BSPI, BSPI_RAF_STATUS) &
BSPI_RAF_STATUS_FIFO_EMPTY_MASK);
}
static inline u32 bcm_qspi_bspi_lr_read_fifo(struct bcm_qspi *qspi)
{
u32 data = bcm_qspi_read(qspi, BSPI, BSPI_RAF_READ_DATA);
if (bcm_qspi_bspi_ver_three(qspi))
data = le32_to_cpu(data);
return data;
}
static inline void bcm_qspi_bspi_lr_start(struct bcm_qspi *qspi)
{
bcm_qspi_bspi_busy_poll(qspi);
bcm_qspi_write(qspi, BSPI, BSPI_RAF_CTRL,
BSPI_RAF_CTRL_START_MASK);
}
static inline void bcm_qspi_bspi_lr_clear(struct bcm_qspi *qspi)
{
bcm_qspi_write(qspi, BSPI, BSPI_RAF_CTRL,
BSPI_RAF_CTRL_CLEAR_MASK);
bcm_qspi_bspi_flush_prefetch_buffers(qspi);
}
static void bcm_qspi_bspi_lr_data_read(struct bcm_qspi *qspi)
{
u32 *buf = (u32 *)qspi->bspi_rf_msg->buf;
u32 data = 0;
dev_dbg(&qspi->pdev->dev, "xfer %p rx %p rxlen %d\n", qspi->bspi_rf_msg,
qspi->bspi_rf_msg->buf, qspi->bspi_rf_msg_len);
while (!bcm_qspi_bspi_lr_is_fifo_empty(qspi)) {
data = bcm_qspi_bspi_lr_read_fifo(qspi);
if (likely(qspi->bspi_rf_msg_len >= 4) &&
IS_ALIGNED((uintptr_t)buf, 4)) {
buf[qspi->bspi_rf_msg_idx++] = data;
qspi->bspi_rf_msg_len -= 4;
} else {
u8 *cbuf = (u8 *)&buf[qspi->bspi_rf_msg_idx];
data = cpu_to_le32(data);
while (qspi->bspi_rf_msg_len) {
*cbuf++ = (u8)data;
data >>= 8;
qspi->bspi_rf_msg_len--;
}
}
}
}
static void bcm_qspi_bspi_set_xfer_params(struct bcm_qspi *qspi, u8 cmd_byte,
int bpp, int bpc, int flex_mode)
{
bcm_qspi_write(qspi, BSPI, BSPI_FLEX_MODE_ENABLE, 0);
bcm_qspi_write(qspi, BSPI, BSPI_BITS_PER_CYCLE, bpc);
bcm_qspi_write(qspi, BSPI, BSPI_BITS_PER_PHASE, bpp);
bcm_qspi_write(qspi, BSPI, BSPI_CMD_AND_MODE_BYTE, cmd_byte);
bcm_qspi_write(qspi, BSPI, BSPI_FLEX_MODE_ENABLE, flex_mode);
}
static int bcm_qspi_bspi_set_flex_mode(struct bcm_qspi *qspi, int width,
int addrlen, int hp)
{
int bpc = 0, bpp = 0;
u8 command = SPINOR_OP_READ_FAST;
int flex_mode = 1, rv = 0;
bool spans_4byte = false;
dev_dbg(&qspi->pdev->dev, "set flex mode w %x addrlen %x hp %d\n",
width, addrlen, hp);
if (addrlen == BSPI_ADDRLEN_4BYTES) {
bpp = BSPI_BPP_ADDR_SELECT_MASK;
spans_4byte = true;
}
bpp |= 8;
switch (width) {
case SPI_NBITS_SINGLE:
if (addrlen == BSPI_ADDRLEN_3BYTES)
flex_mode = 0;
else
command = SPINOR_OP_READ4_FAST;
break;
case SPI_NBITS_DUAL:
bpc = 0x00000001;
if (hp) {
bpc |= 0x00010100;
bpp = BSPI_BPP_MODE_SELECT_MASK;
command = OPCODE_DIOR;
if (spans_4byte)
command = OPCODE_DIOR_4B;
} else {
command = SPINOR_OP_READ_1_1_2;
if (spans_4byte)
command = SPINOR_OP_READ4_1_1_2;
}
break;
case SPI_NBITS_QUAD:
bpc = 0x00000002;
if (hp) {
bpc |= 0x00020200;
bpp = 4;
bpp |= BSPI_BPP_ADDR_SELECT_MASK;
command = OPCODE_QIOR;
if (spans_4byte)
command = OPCODE_QIOR_4B;
} else {
command = SPINOR_OP_READ_1_1_4;
if (spans_4byte)
command = SPINOR_OP_READ4_1_1_4;
}
break;
default:
rv = -EINVAL;
break;
}
if (rv == 0)
bcm_qspi_bspi_set_xfer_params(qspi, command, bpp, bpc,
flex_mode);
return rv;
}
static int bcm_qspi_bspi_set_override(struct bcm_qspi *qspi, int width,
int addrlen, int hp)
{
u32 data = bcm_qspi_read(qspi, BSPI, BSPI_STRAP_OVERRIDE_CTRL);
dev_dbg(&qspi->pdev->dev, "set override mode w %x addrlen %x hp %d\n",
width, addrlen, hp);
switch (width) {
case SPI_NBITS_SINGLE:
data &= ~(BSPI_STRAP_OVERRIDE_CTRL_DATA_QUAD |
BSPI_STRAP_OVERRIDE_CTRL_DATA_DUAL);
break;
case SPI_NBITS_QUAD:
data &= ~BSPI_STRAP_OVERRIDE_CTRL_DATA_DUAL;
data |= BSPI_STRAP_OVERRIDE_CTRL_DATA_QUAD;
break;
case SPI_NBITS_DUAL:
data &= ~BSPI_STRAP_OVERRIDE_CTRL_DATA_QUAD;
data |= BSPI_STRAP_OVERRIDE_CTRL_DATA_DUAL;
break;
default:
return -EINVAL;
}
if (addrlen == BSPI_ADDRLEN_4BYTES)
data |= BSPI_STRAP_OVERRIDE_CTRL_ADDR_4BYTE;
else
data &= ~BSPI_STRAP_OVERRIDE_CTRL_ADDR_4BYTE;
data |= BSPI_STRAP_OVERRIDE_CTRL_OVERRIDE;
bcm_qspi_write(qspi, BSPI, BSPI_STRAP_OVERRIDE_CTRL, data);
bcm_qspi_bspi_set_xfer_params(qspi, SPINOR_OP_READ_FAST, 0, 0, 0);
return 0;
}
static int bcm_qspi_bspi_set_mode(struct bcm_qspi *qspi,
int width, int addrlen, int hp)
{
int error = 0;
qspi->xfer_mode.flex_mode = true;
if (!bcm_qspi_bspi_ver_three(qspi)) {
u32 val, mask;
val = bcm_qspi_read(qspi, BSPI, BSPI_STRAP_OVERRIDE_CTRL);
mask = BSPI_STRAP_OVERRIDE_CTRL_OVERRIDE;
if (val & mask || qspi->s3_strap_override_ctrl & mask) {
qspi->xfer_mode.flex_mode = false;
bcm_qspi_write(qspi, BSPI, BSPI_FLEX_MODE_ENABLE,
0);
if ((val | qspi->s3_strap_override_ctrl) &
BSPI_STRAP_OVERRIDE_CTRL_DATA_DUAL)
width = SPI_NBITS_DUAL;
else if ((val | qspi->s3_strap_override_ctrl) &
BSPI_STRAP_OVERRIDE_CTRL_DATA_QUAD)
width = SPI_NBITS_QUAD;
error = bcm_qspi_bspi_set_override(qspi, width, addrlen,
hp);
}
}
if (qspi->xfer_mode.flex_mode)
error = bcm_qspi_bspi_set_flex_mode(qspi, width, addrlen, hp);
if (error) {
dev_warn(&qspi->pdev->dev,
"INVALID COMBINATION: width=%d addrlen=%d hp=%d\n",
width, addrlen, hp);
} else if (qspi->xfer_mode.width != width ||
qspi->xfer_mode.addrlen != addrlen ||
qspi->xfer_mode.hp != hp) {
qspi->xfer_mode.width = width;
qspi->xfer_mode.addrlen = addrlen;
qspi->xfer_mode.hp = hp;
dev_dbg(&qspi->pdev->dev,
"cs:%d %d-lane output, %d-byte address%s\n",
qspi->curr_cs,
qspi->xfer_mode.width,
qspi->xfer_mode.addrlen,
qspi->xfer_mode.hp != -1 ? ", hp mode" : "");
}
return error;
}
static void bcm_qspi_enable_bspi(struct bcm_qspi *qspi)
{
if (!has_bspi(qspi) || (qspi->bspi_enabled))
return;
qspi->bspi_enabled = 1;
if ((bcm_qspi_read(qspi, BSPI, BSPI_MAST_N_BOOT_CTRL) & 1) == 0)
return;
bcm_qspi_bspi_flush_prefetch_buffers(qspi);
udelay(1);
bcm_qspi_write(qspi, BSPI, BSPI_MAST_N_BOOT_CTRL, 0);
udelay(1);
}
static void bcm_qspi_disable_bspi(struct bcm_qspi *qspi)
{
if (!has_bspi(qspi) || (!qspi->bspi_enabled))
return;
qspi->bspi_enabled = 0;
if ((bcm_qspi_read(qspi, BSPI, BSPI_MAST_N_BOOT_CTRL) & 1))
return;
bcm_qspi_bspi_busy_poll(qspi);
bcm_qspi_write(qspi, BSPI, BSPI_MAST_N_BOOT_CTRL, 1);
udelay(1);
}
static void bcm_qspi_chip_select(struct bcm_qspi *qspi, int cs)
{
u32 data = 0;
if (qspi->curr_cs == cs)
return;
if (qspi->base[CHIP_SELECT]) {
data = bcm_qspi_read(qspi, CHIP_SELECT, 0);
data = (data & ~0xff) | (1 << cs);
bcm_qspi_write(qspi, CHIP_SELECT, 0, data);
usleep_range(10, 20);
}
qspi->curr_cs = cs;
}
static void bcm_qspi_hw_set_parms(struct bcm_qspi *qspi,
const struct bcm_qspi_parms *xp)
{
u32 spcr, spbr = 0;
if (xp->speed_hz)
spbr = qspi->base_clk / (2 * xp->speed_hz);
spcr = clamp_val(spbr, QSPI_SPBR_MIN, QSPI_SPBR_MAX);
bcm_qspi_write(qspi, MSPI, MSPI_SPCR0_LSB, spcr);
spcr = MSPI_MASTER_BIT;
if (xp->bits_per_word != 16)
spcr |= xp->bits_per_word << 2;
spcr |= xp->mode & 3;
bcm_qspi_write(qspi, MSPI, MSPI_SPCR0_MSB, spcr);
qspi->last_parms = *xp;
}
static void bcm_qspi_update_parms(struct bcm_qspi *qspi,
struct spi_device *spi,
struct spi_transfer *trans)
{
struct bcm_qspi_parms xp;
xp.speed_hz = trans->speed_hz;
xp.bits_per_word = trans->bits_per_word;
xp.mode = spi->mode;
bcm_qspi_hw_set_parms(qspi, &xp);
}
static int bcm_qspi_setup(struct spi_device *spi)
{
struct bcm_qspi_parms *xp;
if (spi->bits_per_word > 16)
return -EINVAL;
xp = spi_get_ctldata(spi);
if (!xp) {
xp = kzalloc(sizeof(*xp), GFP_KERNEL);
if (!xp)
return -ENOMEM;
spi_set_ctldata(spi, xp);
}
xp->speed_hz = spi->max_speed_hz;
xp->mode = spi->mode;
if (spi->bits_per_word)
xp->bits_per_word = spi->bits_per_word;
else
xp->bits_per_word = 8;
return 0;
}
static int update_qspi_trans_byte_count(struct bcm_qspi *qspi,
struct qspi_trans *qt, int flags)
{
int ret = TRANS_STATUS_BREAK_NONE;
if (qt->trans->bits_per_word <= 8)
qt->byte++;
else
qt->byte += 2;
if (qt->byte >= qt->trans->len) {
if (qt->trans->delay_usecs &&
(flags & TRANS_STATUS_BREAK_DELAY))
ret |= TRANS_STATUS_BREAK_DELAY;
if (qt->trans->cs_change &&
(flags & TRANS_STATUS_BREAK_CS_CHANGE))
ret |= TRANS_STATUS_BREAK_CS_CHANGE;
if (ret)
goto done;
dev_dbg(&qspi->pdev->dev, "advance msg exit\n");
if (spi_transfer_is_last(qspi->master, qt->trans))
ret = TRANS_STATUS_BREAK_EOM;
else
ret = TRANS_STATUS_BREAK_NO_BYTES;
qt->trans = NULL;
}
done:
dev_dbg(&qspi->pdev->dev, "trans %p len %d byte %d ret %x\n",
qt->trans, qt->trans ? qt->trans->len : 0, qt->byte, ret);
return ret;
}
static inline u8 read_rxram_slot_u8(struct bcm_qspi *qspi, int slot)
{
u32 slot_offset = MSPI_RXRAM + (slot << 3) + 0x4;
return bcm_qspi_read(qspi, MSPI, slot_offset) & 0xff;
}
static inline u16 read_rxram_slot_u16(struct bcm_qspi *qspi, int slot)
{
u32 reg_offset = MSPI_RXRAM;
u32 lsb_offset = reg_offset + (slot << 3) + 0x4;
u32 msb_offset = reg_offset + (slot << 3);
return (bcm_qspi_read(qspi, MSPI, lsb_offset) & 0xff) |
((bcm_qspi_read(qspi, MSPI, msb_offset) & 0xff) << 8);
}
static void read_from_hw(struct bcm_qspi *qspi, int slots)
{
struct qspi_trans tp;
int slot;
bcm_qspi_disable_bspi(qspi);
if (slots > MSPI_NUM_CDRAM) {
dev_err(&qspi->pdev->dev, "%s: too many slots!\n", __func__);
return;
}
tp = qspi->trans_pos;
for (slot = 0; slot < slots; slot++) {
if (tp.trans->bits_per_word <= 8) {
u8 *buf = tp.trans->rx_buf;
if (buf)
buf[tp.byte] = read_rxram_slot_u8(qspi, slot);
dev_dbg(&qspi->pdev->dev, "RD %02x\n",
buf ? buf[tp.byte] : 0xff);
} else {
u16 *buf = tp.trans->rx_buf;
if (buf)
buf[tp.byte / 2] = read_rxram_slot_u16(qspi,
slot);
dev_dbg(&qspi->pdev->dev, "RD %04x\n",
buf ? buf[tp.byte] : 0xffff);
}
update_qspi_trans_byte_count(qspi, &tp,
TRANS_STATUS_BREAK_NONE);
}
qspi->trans_pos = tp;
}
static inline void write_txram_slot_u8(struct bcm_qspi *qspi, int slot,
u8 val)
{
u32 reg_offset = MSPI_TXRAM + (slot << 3);
bcm_qspi_write(qspi, MSPI, reg_offset, val);
}
static inline void write_txram_slot_u16(struct bcm_qspi *qspi, int slot,
u16 val)
{
u32 reg_offset = MSPI_TXRAM;
u32 msb_offset = reg_offset + (slot << 3);
u32 lsb_offset = reg_offset + (slot << 3) + 0x4;
bcm_qspi_write(qspi, MSPI, msb_offset, (val >> 8));
bcm_qspi_write(qspi, MSPI, lsb_offset, (val & 0xff));
}
static inline u32 read_cdram_slot(struct bcm_qspi *qspi, int slot)
{
return bcm_qspi_read(qspi, MSPI, MSPI_CDRAM + (slot << 2));
}
static inline void write_cdram_slot(struct bcm_qspi *qspi, int slot, u32 val)
{
bcm_qspi_write(qspi, MSPI, (MSPI_CDRAM + (slot << 2)), val);
}
static int write_to_hw(struct bcm_qspi *qspi, struct spi_device *spi)
{
struct qspi_trans tp;
int slot = 0, tstatus = 0;
u32 mspi_cdram = 0;
bcm_qspi_disable_bspi(qspi);
tp = qspi->trans_pos;
bcm_qspi_update_parms(qspi, spi, tp.trans);
while (!tstatus && slot < MSPI_NUM_CDRAM) {
if (tp.trans->bits_per_word <= 8) {
const u8 *buf = tp.trans->tx_buf;
u8 val = buf ? buf[tp.byte] : 0xff;
write_txram_slot_u8(qspi, slot, val);
dev_dbg(&qspi->pdev->dev, "WR %02x\n", val);
} else {
const u16 *buf = tp.trans->tx_buf;
u16 val = buf ? buf[tp.byte / 2] : 0xffff;
write_txram_slot_u16(qspi, slot, val);
dev_dbg(&qspi->pdev->dev, "WR %04x\n", val);
}
mspi_cdram = MSPI_CDRAM_CONT_BIT;
mspi_cdram |= (~(1 << spi->chip_select) &
MSPI_CDRAM_PCS);
mspi_cdram |= ((tp.trans->bits_per_word <= 8) ? 0 :
MSPI_CDRAM_BITSE_BIT);
write_cdram_slot(qspi, slot, mspi_cdram);
tstatus = update_qspi_trans_byte_count(qspi, &tp,
TRANS_STATUS_BREAK_TX);
slot++;
}
if (!slot) {
dev_err(&qspi->pdev->dev, "%s: no data to send?", __func__);
goto done;
}
dev_dbg(&qspi->pdev->dev, "submitting %d slots\n", slot);
bcm_qspi_write(qspi, MSPI, MSPI_NEWQP, 0);
bcm_qspi_write(qspi, MSPI, MSPI_ENDQP, slot - 1);
if (tstatus & TRANS_STATUS_BREAK_DESELECT) {
mspi_cdram = read_cdram_slot(qspi, slot - 1) &
~MSPI_CDRAM_CONT_BIT;
write_cdram_slot(qspi, slot - 1, mspi_cdram);
}
if (has_bspi(qspi))
bcm_qspi_write(qspi, MSPI, MSPI_WRITE_LOCK, 1);
mb();
bcm_qspi_write(qspi, MSPI, MSPI_SPCR2, 0xe0);
done:
return slot;
}
static int bcm_qspi_bspi_flash_read(struct spi_device *spi,
struct spi_flash_read_message *msg)
{
struct bcm_qspi *qspi = spi_master_get_devdata(spi->master);
u32 addr = 0, len, len_words;
int ret = 0;
unsigned long timeo = msecs_to_jiffies(100);
struct bcm_qspi_soc_intc *soc_intc = qspi->soc_intc;
if (bcm_qspi_bspi_ver_three(qspi))
if (msg->addr_width == BSPI_ADDRLEN_4BYTES)
return -EIO;
bcm_qspi_chip_select(qspi, spi->chip_select);
bcm_qspi_write(qspi, MSPI, MSPI_WRITE_LOCK, 0);
if (bcm_qspi_bspi_ver_three(qspi) == false) {
addr = msg->from & 0xff000000;
bcm_qspi_write(qspi, BSPI,
BSPI_BSPI_FLASH_UPPER_ADDR_BYTE, addr);
}
if (!qspi->xfer_mode.flex_mode)
addr = msg->from;
else
addr = msg->from & 0x00ffffff;
len = msg->len;
if (len > BSPI_READ_LENGTH)
len = BSPI_READ_LENGTH;
if (bcm_qspi_bspi_ver_three(qspi) == true)
addr = (addr + 0xc00000) & 0xffffff;
reinit_completion(&qspi->bspi_done);
bcm_qspi_enable_bspi(qspi);
len_words = (len + 3) >> 2;
qspi->bspi_rf_msg = msg;
qspi->bspi_rf_msg_status = 0;
qspi->bspi_rf_msg_idx = 0;
qspi->bspi_rf_msg_len = len;
dev_dbg(&qspi->pdev->dev, "bspi xfr addr 0x%x len 0x%x", addr, len);
bcm_qspi_write(qspi, BSPI, BSPI_RAF_START_ADDR, addr);
bcm_qspi_write(qspi, BSPI, BSPI_RAF_NUM_WORDS, len_words);
bcm_qspi_write(qspi, BSPI, BSPI_RAF_WATERMARK, 0);
if (qspi->soc_intc) {
soc_intc->bcm_qspi_int_ack(soc_intc, MSPI_BSPI_DONE);
soc_intc->bcm_qspi_int_set(soc_intc, BSPI_DONE, true);
}
mb();
bcm_qspi_bspi_lr_start(qspi);
if (!wait_for_completion_timeout(&qspi->bspi_done, timeo)) {
dev_err(&qspi->pdev->dev, "timeout waiting for BSPI\n");
ret = -ETIMEDOUT;
} else {
msg->retlen = len;
}
return ret;
}
static int bcm_qspi_flash_read(struct spi_device *spi,
struct spi_flash_read_message *msg)
{
struct bcm_qspi *qspi = spi_master_get_devdata(spi->master);
int ret = 0;
bool mspi_read = false;
u32 io_width, addrlen, addr, len;
u_char *buf;
buf = msg->buf;
addr = msg->from;
len = msg->len;
if (bcm_qspi_bspi_ver_three(qspi) == true) {
addr = (addr + 0xc00000) & 0xffffff;
if ((~ADDR_4MB_MASK & addr) ^
(~ADDR_4MB_MASK & (addr + len - 1)))
mspi_read = true;
}
if (!IS_ALIGNED((uintptr_t)addr, 4) || !IS_ALIGNED((uintptr_t)buf, 4) ||
len < 4)
mspi_read = true;
if (mspi_read)
return -EAGAIN;
io_width = msg->data_nbits ? msg->data_nbits : SPI_NBITS_SINGLE;
addrlen = msg->addr_width;
ret = bcm_qspi_bspi_set_mode(qspi, io_width, addrlen, -1);
if (!ret)
ret = bcm_qspi_bspi_flash_read(spi, msg);
return ret;
}
static int bcm_qspi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *trans)
{
struct bcm_qspi *qspi = spi_master_get_devdata(master);
int slots;
unsigned long timeo = msecs_to_jiffies(100);
bcm_qspi_chip_select(qspi, spi->chip_select);
qspi->trans_pos.trans = trans;
qspi->trans_pos.byte = 0;
while (qspi->trans_pos.byte < trans->len) {
reinit_completion(&qspi->mspi_done);
slots = write_to_hw(qspi, spi);
if (!wait_for_completion_timeout(&qspi->mspi_done, timeo)) {
dev_err(&qspi->pdev->dev, "timeout waiting for MSPI\n");
return -ETIMEDOUT;
}
read_from_hw(qspi, slots);
}
return 0;
}
static void bcm_qspi_cleanup(struct spi_device *spi)
{
struct bcm_qspi_parms *xp = spi_get_ctldata(spi);
kfree(xp);
}
static irqreturn_t bcm_qspi_mspi_l2_isr(int irq, void *dev_id)
{
struct bcm_qspi_dev_id *qspi_dev_id = dev_id;
struct bcm_qspi *qspi = qspi_dev_id->dev;
u32 status = bcm_qspi_read(qspi, MSPI, MSPI_MSPI_STATUS);
if (status & MSPI_MSPI_STATUS_SPIF) {
struct bcm_qspi_soc_intc *soc_intc = qspi->soc_intc;
status &= ~MSPI_MSPI_STATUS_SPIF;
bcm_qspi_write(qspi, MSPI, MSPI_MSPI_STATUS, status);
if (qspi->soc_intc)
soc_intc->bcm_qspi_int_ack(soc_intc, MSPI_DONE);
complete(&qspi->mspi_done);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static irqreturn_t bcm_qspi_bspi_lr_l2_isr(int irq, void *dev_id)
{
struct bcm_qspi_dev_id *qspi_dev_id = dev_id;
struct bcm_qspi *qspi = qspi_dev_id->dev;
struct bcm_qspi_soc_intc *soc_intc = qspi->soc_intc;
u32 status = qspi_dev_id->irqp->mask;
if (qspi->bspi_enabled && qspi->bspi_rf_msg) {
bcm_qspi_bspi_lr_data_read(qspi);
if (qspi->bspi_rf_msg_len == 0) {
qspi->bspi_rf_msg = NULL;
if (qspi->soc_intc) {
soc_intc->bcm_qspi_int_set(soc_intc, BSPI_DONE,
false);
status = INTR_BSPI_LR_SESSION_DONE_MASK;
}
if (qspi->bspi_rf_msg_status)
bcm_qspi_bspi_lr_clear(qspi);
else
bcm_qspi_bspi_flush_prefetch_buffers(qspi);
}
if (qspi->soc_intc)
soc_intc->bcm_qspi_int_ack(soc_intc, BSPI_DONE);
}
status &= INTR_BSPI_LR_SESSION_DONE_MASK;
if (qspi->bspi_enabled && status && qspi->bspi_rf_msg_len == 0)
complete(&qspi->bspi_done);
return IRQ_HANDLED;
}
static irqreturn_t bcm_qspi_bspi_lr_err_l2_isr(int irq, void *dev_id)
{
struct bcm_qspi_dev_id *qspi_dev_id = dev_id;
struct bcm_qspi *qspi = qspi_dev_id->dev;
struct bcm_qspi_soc_intc *soc_intc = qspi->soc_intc;
dev_err(&qspi->pdev->dev, "BSPI INT error\n");
qspi->bspi_rf_msg_status = -EIO;
if (qspi->soc_intc)
soc_intc->bcm_qspi_int_ack(soc_intc, BSPI_ERR);
complete(&qspi->bspi_done);
return IRQ_HANDLED;
}
static irqreturn_t bcm_qspi_l1_isr(int irq, void *dev_id)
{
struct bcm_qspi_dev_id *qspi_dev_id = dev_id;
struct bcm_qspi *qspi = qspi_dev_id->dev;
struct bcm_qspi_soc_intc *soc_intc = qspi->soc_intc;
irqreturn_t ret = IRQ_NONE;
if (soc_intc) {
u32 status = soc_intc->bcm_qspi_get_int_status(soc_intc);
if (status & MSPI_DONE)
ret = bcm_qspi_mspi_l2_isr(irq, dev_id);
else if (status & BSPI_DONE)
ret = bcm_qspi_bspi_lr_l2_isr(irq, dev_id);
else if (status & BSPI_ERR)
ret = bcm_qspi_bspi_lr_err_l2_isr(irq, dev_id);
}
return ret;
}
static void bcm_qspi_bspi_init(struct bcm_qspi *qspi)
{
u32 val = 0;
val = bcm_qspi_read(qspi, BSPI, BSPI_REVISION_ID);
qspi->bspi_maj_rev = (val >> 8) & 0xff;
qspi->bspi_min_rev = val & 0xff;
if (!(bcm_qspi_bspi_ver_three(qspi))) {
bcm_qspi_write(qspi, BSPI, BSPI_BSPI_XOR_VALUE, 0);
bcm_qspi_write(qspi, BSPI, BSPI_BSPI_XOR_ENABLE, 1);
}
qspi->bspi_enabled = 1;
bcm_qspi_disable_bspi(qspi);
bcm_qspi_write(qspi, BSPI, BSPI_B0_CTRL, 0);
bcm_qspi_write(qspi, BSPI, BSPI_B1_CTRL, 0);
}
static void bcm_qspi_hw_init(struct bcm_qspi *qspi)
{
struct bcm_qspi_parms parms;
bcm_qspi_write(qspi, MSPI, MSPI_SPCR1_LSB, 0);
bcm_qspi_write(qspi, MSPI, MSPI_SPCR1_MSB, 0);
bcm_qspi_write(qspi, MSPI, MSPI_NEWQP, 0);
bcm_qspi_write(qspi, MSPI, MSPI_ENDQP, 0);
bcm_qspi_write(qspi, MSPI, MSPI_SPCR2, 0x20);
parms.mode = SPI_MODE_3;
parms.bits_per_word = 8;
parms.speed_hz = qspi->max_speed_hz;
bcm_qspi_hw_set_parms(qspi, &parms);
if (has_bspi(qspi))
bcm_qspi_bspi_init(qspi);
}
static void bcm_qspi_hw_uninit(struct bcm_qspi *qspi)
{
bcm_qspi_write(qspi, MSPI, MSPI_SPCR2, 0);
if (has_bspi(qspi))
bcm_qspi_write(qspi, MSPI, MSPI_WRITE_LOCK, 0);
}
int bcm_qspi_probe(struct platform_device *pdev,
struct bcm_qspi_soc_intc *soc_intc)
{
struct device *dev = &pdev->dev;
struct bcm_qspi *qspi;
struct spi_master *master;
struct resource *res;
int irq, ret = 0, num_ints = 0;
u32 val;
const char *name = NULL;
int num_irqs = ARRAY_SIZE(qspi_irq_tab);
if (!dev->of_node)
return -ENODEV;
if (!of_match_node(bcm_qspi_of_match, dev->of_node))
return -ENODEV;
master = spi_alloc_master(dev, sizeof(struct bcm_qspi));
if (!master) {
dev_err(dev, "error allocating spi_master\n");
return -ENOMEM;
}
qspi = spi_master_get_devdata(master);
qspi->pdev = pdev;
qspi->trans_pos.trans = NULL;
qspi->trans_pos.byte = 0;
qspi->master = master;
master->bus_num = -1;
master->mode_bits = SPI_CPHA | SPI_CPOL | SPI_RX_DUAL | SPI_RX_QUAD;
master->setup = bcm_qspi_setup;
master->transfer_one = bcm_qspi_transfer_one;
master->spi_flash_read = bcm_qspi_flash_read;
master->cleanup = bcm_qspi_cleanup;
master->dev.of_node = dev->of_node;
master->num_chipselect = NUM_CHIPSELECT;
qspi->big_endian = of_device_is_big_endian(dev->of_node);
if (!of_property_read_u32(dev->of_node, "num-cs", &val))
master->num_chipselect = val;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "hif_mspi");
if (!res)
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"mspi");
if (res) {
qspi->base[MSPI] = devm_ioremap_resource(dev, res);
if (IS_ERR(qspi->base[MSPI])) {
ret = PTR_ERR(qspi->base[MSPI]);
goto qspi_probe_err;
}
} else {
goto qspi_probe_err;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "bspi");
if (res) {
qspi->base[BSPI] = devm_ioremap_resource(dev, res);
if (IS_ERR(qspi->base[BSPI])) {
ret = PTR_ERR(qspi->base[BSPI]);
goto qspi_probe_err;
}
qspi->bspi_mode = true;
} else {
qspi->bspi_mode = false;
}
dev_info(dev, "using %smspi mode\n", qspi->bspi_mode ? "bspi-" : "");
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "cs_reg");
if (res) {
qspi->base[CHIP_SELECT] = devm_ioremap_resource(dev, res);
if (IS_ERR(qspi->base[CHIP_SELECT])) {
ret = PTR_ERR(qspi->base[CHIP_SELECT]);
goto qspi_probe_err;
}
}
qspi->dev_ids = kcalloc(num_irqs, sizeof(struct bcm_qspi_dev_id),
GFP_KERNEL);
if (!qspi->dev_ids) {
ret = -ENOMEM;
goto qspi_probe_err;
}
for (val = 0; val < num_irqs; val++) {
irq = -1;
name = qspi_irq_tab[val].irq_name;
if (qspi_irq_tab[val].irq_source == SINGLE_L2) {
irq = platform_get_irq_byname(pdev, name);
} else if (!num_ints && soc_intc) {
irq = platform_get_irq(pdev, 0);
}
if (irq >= 0) {
ret = devm_request_irq(&pdev->dev, irq,
qspi_irq_tab[val].irq_handler, 0,
name,
&qspi->dev_ids[val]);
if (ret < 0) {
dev_err(&pdev->dev, "IRQ %s not found\n", name);
goto qspi_probe_err;
}
qspi->dev_ids[val].dev = qspi;
qspi->dev_ids[val].irqp = &qspi_irq_tab[val];
num_ints++;
dev_dbg(&pdev->dev, "registered IRQ %s %d\n",
qspi_irq_tab[val].irq_name,
irq);
}
}
if (!num_ints) {
dev_err(&pdev->dev, "no IRQs registered, cannot init driver\n");
ret = -EINVAL;
goto qspi_probe_err;
}
if (soc_intc) {
qspi->soc_intc = soc_intc;
soc_intc->bcm_qspi_int_set(soc_intc, MSPI_DONE, true);
} else {
qspi->soc_intc = NULL;
}
qspi->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(qspi->clk)) {
dev_warn(dev, "unable to get clock\n");
ret = PTR_ERR(qspi->clk);
goto qspi_probe_err;
}
ret = clk_prepare_enable(qspi->clk);
if (ret) {
dev_err(dev, "failed to prepare clock\n");
goto qspi_probe_err;
}
qspi->base_clk = clk_get_rate(qspi->clk);
qspi->max_speed_hz = qspi->base_clk / (QSPI_SPBR_MIN * 2);
bcm_qspi_hw_init(qspi);
init_completion(&qspi->mspi_done);
init_completion(&qspi->bspi_done);
qspi->curr_cs = -1;
platform_set_drvdata(pdev, qspi);
qspi->xfer_mode.width = -1;
qspi->xfer_mode.addrlen = -1;
qspi->xfer_mode.hp = -1;
ret = devm_spi_register_master(&pdev->dev, master);
if (ret < 0) {
dev_err(dev, "can't register master\n");
goto qspi_reg_err;
}
return 0;
qspi_reg_err:
bcm_qspi_hw_uninit(qspi);
clk_disable_unprepare(qspi->clk);
qspi_probe_err:
spi_master_put(master);
kfree(qspi->dev_ids);
return ret;
}
int bcm_qspi_remove(struct platform_device *pdev)
{
struct bcm_qspi *qspi = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
bcm_qspi_hw_uninit(qspi);
clk_disable_unprepare(qspi->clk);
kfree(qspi->dev_ids);
spi_unregister_master(qspi->master);
return 0;
}
static int __maybe_unused bcm_qspi_suspend(struct device *dev)
{
struct bcm_qspi *qspi = dev_get_drvdata(dev);
spi_master_suspend(qspi->master);
clk_disable(qspi->clk);
bcm_qspi_hw_uninit(qspi);
return 0;
}
static int __maybe_unused bcm_qspi_resume(struct device *dev)
{
struct bcm_qspi *qspi = dev_get_drvdata(dev);
int ret = 0;
bcm_qspi_hw_init(qspi);
bcm_qspi_chip_select(qspi, qspi->curr_cs);
if (qspi->soc_intc)
qspi->soc_intc->bcm_qspi_int_set(qspi->soc_intc, MSPI_DONE,
true);
ret = clk_enable(qspi->clk);
if (!ret)
spi_master_resume(qspi->master);
return ret;
}
