static u8 crc7_byte(u8 crc, u8 data)
{
return crc7_syndrome_table[(crc << 1) ^ data];
}
static u8 crc7(u8 crc, const u8 *buffer, u32 len)
{
while (len--)
crc = crc7_byte(crc, *buffer++);
return crc;
}
static int wilc_bus_probe(struct spi_device *spi)
{
int ret, gpio;
struct wilc *wilc;
gpio = of_get_gpio(spi->dev.of_node, 0);
if (gpio < 0)
gpio = GPIO_NUM;
ret = wilc_netdev_init(&wilc, NULL, HIF_SPI, GPIO_NUM, &wilc_hif_spi);
if (ret)
return ret;
spi_set_drvdata(spi, wilc);
wilc->dev = &spi->dev;
return 0;
}
static int wilc_bus_remove(struct spi_device *spi)
{
wilc_netdev_cleanup(spi_get_drvdata(spi));
return 0;
}
static int wilc_spi_tx(struct wilc *wilc, u8 *b, u32 len)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int ret;
struct spi_message msg;
if (len > 0 && b) {
struct spi_transfer tr = {
.tx_buf = b,
.len = len,
.delay_usecs = 0,
};
char *r_buffer = kzalloc(len, GFP_KERNEL);
if (!r_buffer)
return -ENOMEM;
tr.rx_buf = r_buffer;
dev_dbg(&spi->dev, "Request writing %d bytes\n", len);
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = spi;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(spi, &msg);
if (ret < 0)
dev_err(&spi->dev, "SPI transaction failed\n");
kfree(r_buffer);
} else {
dev_err(&spi->dev,
"can't write data with the following length: %d\n",
len);
dev_err(&spi->dev,
"FAILED due to NULL buffer or ZERO length check the following length: %d\n",
len);
ret = -EINVAL;
}
return ret;
}
static int wilc_spi_rx(struct wilc *wilc, u8 *rb, u32 rlen)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int ret;
if (rlen > 0) {
struct spi_message msg;
struct spi_transfer tr = {
.rx_buf = rb,
.len = rlen,
.delay_usecs = 0,
};
char *t_buffer = kzalloc(rlen, GFP_KERNEL);
if (!t_buffer)
return -ENOMEM;
tr.tx_buf = t_buffer;
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = spi;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(spi, &msg);
if (ret < 0)
dev_err(&spi->dev, "SPI transaction failed\n");
kfree(t_buffer);
} else {
dev_err(&spi->dev,
"can't read data with the following length: %u\n",
rlen);
ret = -EINVAL;
}
return ret;
}
static int wilc_spi_tx_rx(struct wilc *wilc, u8 *wb, u8 *rb, u32 rlen)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int ret;
if (rlen > 0) {
struct spi_message msg;
struct spi_transfer tr = {
.rx_buf = rb,
.tx_buf = wb,
.len = rlen,
.bits_per_word = 8,
.delay_usecs = 0,
};
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = spi;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(spi, &msg);
if (ret < 0)
dev_err(&spi->dev, "SPI transaction failed\n");
} else {
dev_err(&spi->dev,
"can't read data with the following length: %u\n",
rlen);
ret = -EINVAL;
}
return ret;
}
static int spi_cmd_complete(struct wilc *wilc, u8 cmd, u32 adr, u8 *b, u32 sz,
u8 clockless)
{
struct spi_device *spi = to_spi_device(wilc->dev);
u8 wb[32], rb[32];
u8 wix, rix;
u32 len2;
u8 rsp;
int len = 0;
int result = N_OK;
wb[0] = cmd;
switch (cmd) {
case CMD_SINGLE_READ:
wb[1] = (u8)(adr >> 16);
wb[2] = (u8)(adr >> 8);
wb[3] = (u8)adr;
len = 5;
break;
case CMD_INTERNAL_READ:
wb[1] = (u8)(adr >> 8);
if (clockless == 1)
wb[1] |= BIT(7);
wb[2] = (u8)adr;
wb[3] = 0x00;
len = 5;
break;
case CMD_TERMINATE:
wb[1] = 0x00;
wb[2] = 0x00;
wb[3] = 0x00;
len = 5;
break;
case CMD_REPEAT:
wb[1] = 0x00;
wb[2] = 0x00;
wb[3] = 0x00;
len = 5;
break;
case CMD_RESET:
wb[1] = 0xff;
wb[2] = 0xff;
wb[3] = 0xff;
len = 5;
break;
case CMD_DMA_WRITE:
case CMD_DMA_READ:
wb[1] = (u8)(adr >> 16);
wb[2] = (u8)(adr >> 8);
wb[3] = (u8)adr;
wb[4] = (u8)(sz >> 8);
wb[5] = (u8)(sz);
len = 7;
break;
case CMD_DMA_EXT_WRITE:
case CMD_DMA_EXT_READ:
wb[1] = (u8)(adr >> 16);
wb[2] = (u8)(adr >> 8);
wb[3] = (u8)adr;
wb[4] = (u8)(sz >> 16);
wb[5] = (u8)(sz >> 8);
wb[6] = (u8)(sz);
len = 8;
break;
case CMD_INTERNAL_WRITE:
wb[1] = (u8)(adr >> 8);
if (clockless == 1)
wb[1] |= BIT(7);
wb[2] = (u8)(adr);
wb[3] = b[3];
wb[4] = b[2];
wb[5] = b[1];
wb[6] = b[0];
len = 8;
break;
case CMD_SINGLE_WRITE:
wb[1] = (u8)(adr >> 16);
wb[2] = (u8)(adr >> 8);
wb[3] = (u8)(adr);
wb[4] = b[3];
wb[5] = b[2];
wb[6] = b[1];
wb[7] = b[0];
len = 9;
break;
default:
result = N_FAIL;
break;
}
if (result != N_OK) {
return result;
}
if (!g_spi.crc_off)
wb[len - 1] = (crc7(0x7f, (const u8 *)&wb[0], len - 1)) << 1;
else
len -= 1;
#define NUM_SKIP_BYTES (1)
#define NUM_RSP_BYTES (2)
#define NUM_DATA_HDR_BYTES (1)
#define NUM_DATA_BYTES (4)
#define NUM_CRC_BYTES (2)
#define NUM_DUMMY_BYTES (3)
if ((cmd == CMD_RESET) ||
(cmd == CMD_TERMINATE) ||
(cmd == CMD_REPEAT)) {
len2 = len + (NUM_SKIP_BYTES + NUM_RSP_BYTES + NUM_DUMMY_BYTES);
} else if ((cmd == CMD_INTERNAL_READ) || (cmd == CMD_SINGLE_READ)) {
if (!g_spi.crc_off) {
len2 = len + (NUM_RSP_BYTES + NUM_DATA_HDR_BYTES + NUM_DATA_BYTES
+ NUM_CRC_BYTES + NUM_DUMMY_BYTES);
} else {
len2 = len + (NUM_RSP_BYTES + NUM_DATA_HDR_BYTES + NUM_DATA_BYTES
+ NUM_DUMMY_BYTES);
}
} else {
len2 = len + (NUM_RSP_BYTES + NUM_DUMMY_BYTES);
}
#undef NUM_DUMMY_BYTES
if (len2 > ARRAY_SIZE(wb)) {
dev_err(&spi->dev, "spi buffer size too small (%d) (%zu)\n",
len2, ARRAY_SIZE(wb));
result = N_FAIL;
return result;
}
for (wix = len; wix < len2; wix++) {
wb[wix] = 0;
}
rix = len;
if (wilc_spi_tx_rx(wilc, wb, rb, len2)) {
dev_err(&spi->dev, "Failed cmd write, bus error...\n");
result = N_FAIL;
return result;
}
if ((cmd == CMD_RESET) ||
(cmd == CMD_TERMINATE) ||
(cmd == CMD_REPEAT)) {
rix++;
}
rsp = rb[rix++];
if (rsp != cmd) {
dev_err(&spi->dev, "Failed cmd response, cmd (%02x)"
", resp (%02x)\n", cmd, rsp);
result = N_FAIL;
return result;
}
rsp = rb[rix++];
if (rsp != 0x00) {
dev_err(&spi->dev, "Failed cmd state response state (%02x)\n",
rsp);
result = N_FAIL;
return result;
}
if ((cmd == CMD_INTERNAL_READ) || (cmd == CMD_SINGLE_READ)
|| (cmd == CMD_DMA_READ) || (cmd == CMD_DMA_EXT_READ)) {
int retry;
u8 crc[2];
retry = 100;
do {
if (rix < len2) {
rsp = rb[rix++];
} else {
retry = 0;
break;
}
if (((rsp >> 4) & 0xf) == 0xf)
break;
} while (retry--);
if (retry <= 0) {
dev_err(&spi->dev,
"Error, data read response (%02x)\n", rsp);
result = N_RESET;
return result;
}
if ((cmd == CMD_INTERNAL_READ) || (cmd == CMD_SINGLE_READ)) {
if ((rix + 3) < len2) {
b[0] = rb[rix++];
b[1] = rb[rix++];
b[2] = rb[rix++];
b[3] = rb[rix++];
} else {
dev_err(&spi->dev,
"buffer overrun when reading data.\n");
result = N_FAIL;
return result;
}
if (!g_spi.crc_off) {
if ((rix + 1) < len2) {
crc[0] = rb[rix++];
crc[1] = rb[rix++];
} else {
dev_err(&spi->dev,"buffer overrun when reading crc.\n");
result = N_FAIL;
return result;
}
}
} else if ((cmd == CMD_DMA_READ) || (cmd == CMD_DMA_EXT_READ)) {
int ix;
for (ix = 0; (rix < len2) && (ix < sz); ) {
b[ix++] = rb[rix++];
}
sz -= ix;
if (sz > 0) {
int nbytes;
if (sz <= (DATA_PKT_SZ - ix))
nbytes = sz;
else
nbytes = DATA_PKT_SZ - ix;
if (wilc_spi_rx(wilc, &b[ix], nbytes)) {
dev_err(&spi->dev, "Failed data block read, bus error...\n");
result = N_FAIL;
goto _error_;
}
if (!g_spi.crc_off) {
if (wilc_spi_rx(wilc, crc, 2)) {
dev_err(&spi->dev, "Failed data block crc read, bus error...\n");
result = N_FAIL;
goto _error_;
}
}
ix += nbytes;
sz -= nbytes;
}
while (sz > 0) {
int nbytes;
if (sz <= DATA_PKT_SZ)
nbytes = sz;
else
nbytes = DATA_PKT_SZ;
retry = 10;
do {
if (wilc_spi_rx(wilc, &rsp, 1)) {
dev_err(&spi->dev, "Failed data response read, bus error...\n");
result = N_FAIL;
break;
}
if (((rsp >> 4) & 0xf) == 0xf)
break;
} while (retry--);
if (result == N_FAIL)
break;
if (wilc_spi_rx(wilc, &b[ix], nbytes)) {
dev_err(&spi->dev, "Failed data block read, bus error...\n");
result = N_FAIL;
break;
}
if (!g_spi.crc_off) {
if (wilc_spi_rx(wilc, crc, 2)) {
dev_err(&spi->dev, "Failed data block crc read, bus error...\n");
result = N_FAIL;
break;
}
}
ix += nbytes;
sz -= nbytes;
}
}
}
_error_:
return result;
}
static int spi_data_write(struct wilc *wilc, u8 *b, u32 sz)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int ix, nbytes;
int result = 1;
u8 cmd, order, crc[2] = {0};
ix = 0;
do {
if (sz <= DATA_PKT_SZ)
nbytes = sz;
else
nbytes = DATA_PKT_SZ;
cmd = 0xf0;
if (ix == 0) {
if (sz <= DATA_PKT_SZ)
order = 0x3;
else
order = 0x1;
} else {
if (sz <= DATA_PKT_SZ)
order = 0x3;
else
order = 0x2;
}
cmd |= order;
if (wilc_spi_tx(wilc, &cmd, 1)) {
dev_err(&spi->dev,
"Failed data block cmd write, bus error...\n");
result = N_FAIL;
break;
}
if (wilc_spi_tx(wilc, &b[ix], nbytes)) {
dev_err(&spi->dev,
"Failed data block write, bus error...\n");
result = N_FAIL;
break;
}
if (!g_spi.crc_off) {
if (wilc_spi_tx(wilc, crc, 2)) {
dev_err(&spi->dev,"Failed data block crc write, bus error...\n");
result = N_FAIL;
break;
}
}
ix += nbytes;
sz -= nbytes;
} while (sz);
return result;
}
static int spi_internal_write(struct wilc *wilc, u32 adr, u32 dat)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int result;
dat = cpu_to_le32(dat);
result = spi_cmd_complete(wilc, CMD_INTERNAL_WRITE, adr, (u8 *)&dat, 4,
0);
if (result != N_OK) {
dev_err(&spi->dev, "Failed internal write cmd...\n");
}
return result;
}
static int spi_internal_read(struct wilc *wilc, u32 adr, u32 *data)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int result;
result = spi_cmd_complete(wilc, CMD_INTERNAL_READ, adr, (u8 *)data, 4,
0);
if (result != N_OK) {
dev_err(&spi->dev, "Failed internal read cmd...\n");
return 0;
}
*data = cpu_to_le32(*data);
return 1;
}
static int wilc_spi_write_reg(struct wilc *wilc, u32 addr, u32 data)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int result = N_OK;
u8 cmd = CMD_SINGLE_WRITE;
u8 clockless = 0;
data = cpu_to_le32(data);
if (addr < 0x30) {
cmd = CMD_INTERNAL_WRITE;
clockless = 1;
}
result = spi_cmd_complete(wilc, cmd, addr, (u8 *)&data, 4, clockless);
if (result != N_OK) {
dev_err(&spi->dev, "Failed cmd, write reg (%08x)...\n", addr);
}
return result;
}
static int wilc_spi_write(struct wilc *wilc, u32 addr, u8 *buf, u32 size)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int result;
u8 cmd = CMD_DMA_EXT_WRITE;
if (size <= 4)
return 0;
result = spi_cmd_complete(wilc, cmd, addr, NULL, size, 0);
if (result != N_OK) {
dev_err(&spi->dev,
"Failed cmd, write block (%08x)...\n", addr);
return 0;
}
result = spi_data_write(wilc, buf, size);
if (result != N_OK) {
dev_err(&spi->dev, "Failed block data write...\n");
}
return 1;
}
static int wilc_spi_read_reg(struct wilc *wilc, u32 addr, u32 *data)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int result = N_OK;
u8 cmd = CMD_SINGLE_READ;
u8 clockless = 0;
if (addr < 0x30) {
cmd = CMD_INTERNAL_READ;
clockless = 1;
}
result = spi_cmd_complete(wilc, cmd, addr, (u8 *)data, 4, clockless);
if (result != N_OK) {
dev_err(&spi->dev, "Failed cmd, read reg (%08x)...\n", addr);
return 0;
}
*data = cpu_to_le32(*data);
return 1;
}
static int wilc_spi_read(struct wilc *wilc, u32 addr, u8 *buf, u32 size)
{
struct spi_device *spi = to_spi_device(wilc->dev);
u8 cmd = CMD_DMA_EXT_READ;
int result;
if (size <= 4)
return 0;
result = spi_cmd_complete(wilc, cmd, addr, buf, size, 0);
if (result != N_OK) {
dev_err(&spi->dev, "Failed cmd, read block (%08x)...\n", addr);
return 0;
}
return 1;
}
static int _wilc_spi_deinit(struct wilc *wilc)
{
return 1;
}
static int wilc_spi_init(struct wilc *wilc)
{
struct spi_device *spi = to_spi_device(wilc->dev);
u32 reg;
u32 chipid;
static int isinit;
if (isinit) {
if (!wilc_spi_read_reg(wilc, 0x1000, &chipid)) {
dev_err(&spi->dev, "Fail cmd read chip id...\n");
return 0;
}
return 1;
}
memset(&g_spi, 0, sizeof(wilc_spi_t));
g_spi.crc_off = 0;
if (!spi_internal_read(wilc, WILC_SPI_PROTOCOL_OFFSET, &reg)) {
g_spi.crc_off = 1;
dev_err(&spi->dev, "Failed internal read protocol with CRC on, retyring with CRC off...\n");
if (!spi_internal_read(wilc, WILC_SPI_PROTOCOL_OFFSET, &reg)) {
dev_err(&spi->dev,
"Failed internal read protocol...\n");
return 0;
}
}
if (g_spi.crc_off == 0) {
reg &= ~0xc;
reg &= ~0x70;
reg |= (0x5 << 4);
if (!spi_internal_write(wilc, WILC_SPI_PROTOCOL_OFFSET, reg)) {
dev_err(&spi->dev, "[wilc spi %d]: Failed internal write protocol reg...\n", __LINE__);
return 0;
}
g_spi.crc_off = 1;
}
if (!wilc_spi_read_reg(wilc, 0x1000, &chipid)) {
dev_err(&spi->dev, "Fail cmd read chip id...\n");
return 0;
}
g_spi.has_thrpt_enh = 1;
isinit = 1;
return 1;
}
static int wilc_spi_read_size(struct wilc *wilc, u32 *size)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int ret;
if (g_spi.has_thrpt_enh) {
ret = spi_internal_read(wilc, 0xe840 - WILC_SPI_REG_BASE,
size);
*size = *size & IRQ_DMA_WD_CNT_MASK;
} else {
u32 tmp;
u32 byte_cnt;
ret = wilc_spi_read_reg(wilc, WILC_VMM_TO_HOST_SIZE,
&byte_cnt);
if (!ret) {
dev_err(&spi->dev,
"Failed read WILC_VMM_TO_HOST_SIZE ...\n");
goto _fail_;
}
tmp = (byte_cnt >> 2) & IRQ_DMA_WD_CNT_MASK;
*size = tmp;
}
_fail_:
return ret;
}
static int wilc_spi_read_int(struct wilc *wilc, u32 *int_status)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int ret;
if (g_spi.has_thrpt_enh) {
ret = spi_internal_read(wilc, 0xe840 - WILC_SPI_REG_BASE,
int_status);
} else {
u32 tmp;
u32 byte_cnt;
ret = wilc_spi_read_reg(wilc, WILC_VMM_TO_HOST_SIZE,
&byte_cnt);
if (!ret) {
dev_err(&spi->dev,
"Failed read WILC_VMM_TO_HOST_SIZE ...\n");
goto _fail_;
}
tmp = (byte_cnt >> 2) & IRQ_DMA_WD_CNT_MASK;
{
int happended, j;
j = 0;
do {
u32 irq_flags;
happended = 0;
wilc_spi_read_reg(wilc, 0x1a90, &irq_flags);
tmp |= ((irq_flags >> 27) << IRG_FLAGS_OFFSET);
if (g_spi.nint > 5) {
wilc_spi_read_reg(wilc, 0x1a94,
&irq_flags);
tmp |= (((irq_flags >> 0) & 0x7) << (IRG_FLAGS_OFFSET + 5));
}
{
u32 unkmown_mask;
unkmown_mask = ~((1ul << g_spi.nint) - 1);
if ((tmp >> IRG_FLAGS_OFFSET) & unkmown_mask) {
dev_err(&spi->dev, "Unexpected interrupt (2): j=%d, tmp=%x, mask=%x\n", j, tmp, unkmown_mask);
happended = 1;
}
}
j++;
} while (happended);
}
*int_status = tmp;
}
_fail_:
return ret;
}
static int wilc_spi_clear_int_ext(struct wilc *wilc, u32 val)
{
struct spi_device *spi = to_spi_device(wilc->dev);
int ret;
if (g_spi.has_thrpt_enh) {
ret = spi_internal_write(wilc, 0xe844 - WILC_SPI_REG_BASE,
val);
} else {
u32 flags;
flags = val & (BIT(MAX_NUM_INT) - 1);
if (flags) {
int i;
ret = 1;
for (i = 0; i < g_spi.nint; i++) {
if (flags & 1)
ret = wilc_spi_write_reg(wilc, 0x10c8 + i * 4, 1);
if (!ret)
break;
flags >>= 1;
}
if (!ret) {
dev_err(&spi->dev,
"Failed wilc_spi_write_reg, set reg %x ...\n",
0x10c8 + i * 4);
goto _fail_;
}
for (i = g_spi.nint; i < MAX_NUM_INT; i++) {
if (flags & 1)
dev_err(&spi->dev,
"Unexpected interrupt cleared %d...\n",
i);
flags >>= 1;
}
}
{
u32 tbl_ctl;
tbl_ctl = 0;
if ((val & SEL_VMM_TBL0) == SEL_VMM_TBL0)
tbl_ctl |= BIT(0);
if ((val & SEL_VMM_TBL1) == SEL_VMM_TBL1)
tbl_ctl |= BIT(1);
ret = wilc_spi_write_reg(wilc, WILC_VMM_TBL_CTL,
tbl_ctl);
if (!ret) {
dev_err(&spi->dev,
"fail write reg vmm_tbl_ctl...\n");
goto _fail_;
}
if ((val & EN_VMM) == EN_VMM) {
ret = wilc_spi_write_reg(wilc,
WILC_VMM_CORE_CTL, 1);
if (!ret) {
dev_err(&spi->dev,"fail write reg vmm_core_ctl...\n");
goto _fail_;
}
}
}
}
_fail_:
return ret;
}
static int wilc_spi_sync_ext(struct wilc *wilc, int nint)
{
struct spi_device *spi = to_spi_device(wilc->dev);
u32 reg;
int ret, i;
if (nint > MAX_NUM_INT) {
dev_err(&spi->dev, "Too many interupts (%d)...\n", nint);
return 0;
}
g_spi.nint = nint;
ret = wilc_spi_read_reg(wilc, WILC_PIN_MUX_0, &reg);
if (!ret) {
dev_err(&spi->dev, "Failed read reg (%08x)...\n",
WILC_PIN_MUX_0);
return 0;
}
reg |= BIT(8);
ret = wilc_spi_write_reg(wilc, WILC_PIN_MUX_0, reg);
if (!ret) {
dev_err(&spi->dev, "Failed write reg (%08x)...\n",
WILC_PIN_MUX_0);
return 0;
}
ret = wilc_spi_read_reg(wilc, WILC_INTR_ENABLE, &reg);
if (!ret) {
dev_err(&spi->dev, "Failed read reg (%08x)...\n",
WILC_INTR_ENABLE);
return 0;
}
for (i = 0; (i < 5) && (nint > 0); i++, nint--) {
reg |= (BIT((27 + i)));
}
ret = wilc_spi_write_reg(wilc, WILC_INTR_ENABLE, reg);
if (!ret) {
dev_err(&spi->dev, "Failed write reg (%08x)...\n",
WILC_INTR_ENABLE);
return 0;
}
if (nint) {
ret = wilc_spi_read_reg(wilc, WILC_INTR2_ENABLE, &reg);
if (!ret) {
dev_err(&spi->dev, "Failed read reg (%08x)...\n",
WILC_INTR2_ENABLE);
return 0;
}
for (i = 0; (i < 3) && (nint > 0); i++, nint--) {
reg |= BIT(i);
}
ret = wilc_spi_read_reg(wilc, WILC_INTR2_ENABLE, &reg);
if (!ret) {
dev_err(&spi->dev, "Failed write reg (%08x)...\n",
WILC_INTR2_ENABLE);
return 0;
}
}
return 1;
}
