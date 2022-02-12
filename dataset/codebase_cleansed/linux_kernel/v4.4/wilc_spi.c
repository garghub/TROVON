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
static int spi_cmd(u8 cmd, u32 adr, u32 data, u32 sz, u8 clockless)
{
u8 bc[9];
int len = 5;
int result = N_OK;
bc[0] = cmd;
switch (cmd) {
case CMD_SINGLE_READ:
bc[1] = (u8)(adr >> 16);
bc[2] = (u8)(adr >> 8);
bc[3] = (u8)adr;
len = 5;
break;
case CMD_INTERNAL_READ:
bc[1] = (u8)(adr >> 8);
if (clockless)
bc[1] |= BIT(7);
bc[2] = (u8)adr;
bc[3] = 0x00;
len = 5;
break;
case CMD_TERMINATE:
bc[1] = 0x00;
bc[2] = 0x00;
bc[3] = 0x00;
len = 5;
break;
case CMD_REPEAT:
bc[1] = 0x00;
bc[2] = 0x00;
bc[3] = 0x00;
len = 5;
break;
case CMD_RESET:
bc[1] = 0xff;
bc[2] = 0xff;
bc[3] = 0xff;
len = 5;
break;
case CMD_DMA_WRITE:
case CMD_DMA_READ:
bc[1] = (u8)(adr >> 16);
bc[2] = (u8)(adr >> 8);
bc[3] = (u8)adr;
bc[4] = (u8)(sz >> 8);
bc[5] = (u8)(sz);
len = 7;
break;
case CMD_DMA_EXT_WRITE:
case CMD_DMA_EXT_READ:
bc[1] = (u8)(adr >> 16);
bc[2] = (u8)(adr >> 8);
bc[3] = (u8)adr;
bc[4] = (u8)(sz >> 16);
bc[5] = (u8)(sz >> 8);
bc[6] = (u8)(sz);
len = 8;
break;
case CMD_INTERNAL_WRITE:
bc[1] = (u8)(adr >> 8);
if (clockless)
bc[1] |= BIT(7);
bc[2] = (u8)(adr);
bc[3] = (u8)(data >> 24);
bc[4] = (u8)(data >> 16);
bc[5] = (u8)(data >> 8);
bc[6] = (u8)(data);
len = 8;
break;
case CMD_SINGLE_WRITE:
bc[1] = (u8)(adr >> 16);
bc[2] = (u8)(adr >> 8);
bc[3] = (u8)(adr);
bc[4] = (u8)(data >> 24);
bc[5] = (u8)(data >> 16);
bc[6] = (u8)(data >> 8);
bc[7] = (u8)(data);
len = 9;
break;
default:
result = N_FAIL;
break;
}
if (result) {
if (!g_spi.crc_off)
bc[len - 1] = (crc7(0x7f, (const u8 *)&bc[0], len - 1)) << 1;
else
len -= 1;
if (!g_spi.spi_tx(bc, len)) {
PRINT_ER("[wilc spi]: Failed cmd write, bus error...\n");
result = N_FAIL;
}
}
return result;
}
static int spi_cmd_rsp(u8 cmd)
{
u8 rsp;
int result = N_OK;
if ((cmd == CMD_RESET) ||
(cmd == CMD_TERMINATE) ||
(cmd == CMD_REPEAT)) {
if (!g_spi.spi_rx(&rsp, 1)) {
result = N_FAIL;
goto _fail_;
}
}
if (!g_spi.spi_rx(&rsp, 1)) {
PRINT_ER("[wilc spi]: Failed cmd response read, bus error...\n");
result = N_FAIL;
goto _fail_;
}
if (rsp != cmd) {
PRINT_ER("[wilc spi]: Failed cmd response, cmd (%02x), resp (%02x)\n", cmd, rsp);
result = N_FAIL;
goto _fail_;
}
if (!g_spi.spi_rx(&rsp, 1)) {
PRINT_ER("[wilc spi]: Failed cmd state read, bus error...\n");
result = N_FAIL;
goto _fail_;
}
if (rsp != 0x00) {
PRINT_ER("[wilc spi]: Failed cmd state response state (%02x)\n", rsp);
result = N_FAIL;
}
_fail_:
return result;
}
static int spi_cmd_complete(u8 cmd, u32 adr, u8 *b, u32 sz, u8 clockless)
{
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
PRINT_ER("[wilc spi]: spi buffer size too small (%d) (%zu)\n",
len2, ARRAY_SIZE(wb));
result = N_FAIL;
return result;
}
for (wix = len; wix < len2; wix++) {
wb[wix] = 0;
}
rix = len;
if (!g_spi.spi_trx(wb, rb, len2)) {
PRINT_ER("[wilc spi]: Failed cmd write, bus error...\n");
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
PRINT_ER("[wilc spi]: Failed cmd response, cmd (%02x)"
", resp (%02x)\n", cmd, rsp);
result = N_FAIL;
return result;
}
rsp = rb[rix++];
if (rsp != 0x00) {
PRINT_ER("[wilc spi]: Failed cmd state response "
"state (%02x)\n", rsp);
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
PRINT_ER("[wilc spi]: Error, data read "
"response (%02x)\n", rsp);
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
PRINT_ER("[wilc spi]: buffer overrun when reading data.\n");
result = N_FAIL;
return result;
}
if (!g_spi.crc_off) {
if ((rix + 1) < len2) {
crc[0] = rb[rix++];
crc[1] = rb[rix++];
} else {
PRINT_ER("[wilc spi]: buffer overrun when reading crc.\n");
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
if (!g_spi.spi_rx(&b[ix], nbytes)) {
PRINT_ER("[wilc spi]: Failed data block read, bus error...\n");
result = N_FAIL;
goto _error_;
}
if (!g_spi.crc_off) {
if (!g_spi.spi_rx(crc, 2)) {
PRINT_ER("[wilc spi]: Failed data block crc read, bus error...\n");
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
if (!g_spi.spi_rx(&rsp, 1)) {
PRINT_ER("[wilc spi]: Failed data response read, bus error...\n");
result = N_FAIL;
break;
}
if (((rsp >> 4) & 0xf) == 0xf)
break;
} while (retry--);
if (result == N_FAIL)
break;
if (!g_spi.spi_rx(&b[ix], nbytes)) {
PRINT_ER("[wilc spi]: Failed data block read, bus error...\n");
result = N_FAIL;
break;
}
if (!g_spi.crc_off) {
if (!g_spi.spi_rx(crc, 2)) {
PRINT_ER("[wilc spi]: Failed data block crc read, bus error...\n");
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
static int spi_data_read(u8 *b, u32 sz)
{
int retry, ix, nbytes;
int result = N_OK;
u8 crc[2];
u8 rsp;
ix = 0;
do {
if (sz <= DATA_PKT_SZ)
nbytes = sz;
else
nbytes = DATA_PKT_SZ;
retry = 10;
do {
if (!g_spi.spi_rx(&rsp, 1)) {
PRINT_ER("[wilc spi]: Failed data response read, bus error...\n");
result = N_FAIL;
break;
}
if (((rsp >> 4) & 0xf) == 0xf)
break;
} while (retry--);
if (result == N_FAIL)
break;
if (retry <= 0) {
PRINT_ER("[wilc spi]: Failed data response read...(%02x)\n", rsp);
result = N_FAIL;
break;
}
if (!g_spi.spi_rx(&b[ix], nbytes)) {
PRINT_ER("[wilc spi]: Failed data block read, bus error...\n");
result = N_FAIL;
break;
}
if (!g_spi.crc_off) {
if (!g_spi.spi_rx(crc, 2)) {
PRINT_ER("[wilc spi]: Failed data block crc read, bus error...\n");
result = N_FAIL;
break;
}
}
ix += nbytes;
sz -= nbytes;
} while (sz);
return result;
}
static int spi_data_write(u8 *b, u32 sz)
{
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
if (!g_spi.spi_tx(&cmd, 1)) {
PRINT_ER("[wilc spi]: Failed data block cmd write, bus error...\n");
result = N_FAIL;
break;
}
if (!g_spi.spi_tx(&b[ix], nbytes)) {
PRINT_ER("[wilc spi]: Failed data block write, bus error...\n");
result = N_FAIL;
break;
}
if (!g_spi.crc_off) {
if (!g_spi.spi_tx(crc, 2)) {
PRINT_ER("[wilc spi]: Failed data block crc write, bus error...\n");
result = N_FAIL;
break;
}
}
ix += nbytes;
sz -= nbytes;
} while (sz);
return result;
}
static int spi_internal_write(u32 adr, u32 dat)
{
int result;
#ifdef BIG_ENDIAN
dat = BYTE_SWAP(dat);
#endif
result = spi_cmd_complete(CMD_INTERNAL_WRITE, adr, (u8 *)&dat, 4, 0);
if (result != N_OK) {
PRINT_ER("[wilc spi]: Failed internal write cmd...\n");
}
return result;
}
static int spi_internal_read(u32 adr, u32 *data)
{
int result;
result = spi_cmd_complete(CMD_INTERNAL_READ, adr, (u8 *)data, 4, 0);
if (result != N_OK) {
PRINT_ER("[wilc spi]: Failed internal read cmd...\n");
return 0;
}
#ifdef BIG_ENDIAN
*data = BYTE_SWAP(*data);
#endif
return 1;
}
static int spi_write_reg(u32 addr, u32 data)
{
int result = N_OK;
u8 cmd = CMD_SINGLE_WRITE;
u8 clockless = 0;
#ifdef BIG_ENDIAN
data = BYTE_SWAP(data);
#endif
if (addr < 0x30) {
cmd = CMD_INTERNAL_WRITE;
clockless = 1;
}
result = spi_cmd_complete(cmd, addr, (u8 *)&data, 4, clockless);
if (result != N_OK) {
PRINT_ER("[wilc spi]: Failed cmd, write reg (%08x)...\n", addr);
}
return result;
}
static int spi_write(u32 addr, u8 *buf, u32 size)
{
int result;
u8 cmd = CMD_DMA_EXT_WRITE;
if (size <= 4)
return 0;
result = spi_cmd_complete(cmd, addr, NULL, size, 0);
if (result != N_OK) {
PRINT_ER("[wilc spi]: Failed cmd, write block (%08x)...\n", addr);
return 0;
}
result = spi_data_write(buf, size);
if (result != N_OK) {
PRINT_ER("[wilc spi]: Failed block data write...\n");
}
return 1;
}
static int spi_read_reg(u32 addr, u32 *data)
{
int result = N_OK;
u8 cmd = CMD_SINGLE_READ;
u8 clockless = 0;
if (addr < 0x30) {
cmd = CMD_INTERNAL_READ;
clockless = 1;
}
result = spi_cmd_complete(cmd, addr, (u8 *)data, 4, clockless);
if (result != N_OK) {
PRINT_ER("[wilc spi]: Failed cmd, read reg (%08x)...\n", addr);
return 0;
}
#ifdef BIG_ENDIAN
*data = BYTE_SWAP(*data);
#endif
return 1;
}
static int spi_read(u32 addr, u8 *buf, u32 size)
{
u8 cmd = CMD_DMA_EXT_READ;
int result;
if (size <= 4)
return 0;
result = spi_cmd_complete(cmd, addr, buf, size, 0);
if (result != N_OK) {
PRINT_ER("[wilc spi]: Failed cmd, read block (%08x)...\n", addr);
return 0;
}
return 1;
}
static int spi_clear_int(void)
{
u32 reg;
if (!spi_read_reg(WILC_HOST_RX_CTRL_0, &reg)) {
PRINT_ER("[wilc spi]: Failed read reg (%08x)...\n", WILC_HOST_RX_CTRL_0);
return 0;
}
reg &= ~0x1;
spi_write_reg(WILC_HOST_RX_CTRL_0, reg);
return 1;
}
static int spi_deinit(void *pv)
{
return 1;
}
static int spi_sync(void)
{
u32 reg;
int ret;
ret = spi_read_reg(WILC_PIN_MUX_0, &reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed read reg (%08x)...\n", WILC_PIN_MUX_0);
return 0;
}
reg |= BIT(8);
ret = spi_write_reg(WILC_PIN_MUX_0, reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed write reg (%08x)...\n", WILC_PIN_MUX_0);
return 0;
}
ret = spi_read_reg(WILC_INTR_ENABLE, &reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed read reg (%08x)...\n", WILC_INTR_ENABLE);
return 0;
}
reg |= BIT(16);
ret = spi_write_reg(WILC_INTR_ENABLE, reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed write reg (%08x)...\n", WILC_INTR_ENABLE);
return 0;
}
return 1;
}
static int spi_init(wilc_wlan_inp_t *inp, wilc_debug_func func)
{
u32 reg;
u32 chipid;
static int isinit;
if (isinit) {
if (!spi_read_reg(0x1000, &chipid)) {
PRINT_ER("[wilc spi]: Fail cmd read chip id...\n");
return 0;
}
return 1;
}
memset(&g_spi, 0, sizeof(wilc_spi_t));
g_spi.dPrint = func;
g_spi.os_context = inp->os_context.os_private;
if (inp->io_func.io_init) {
if (!inp->io_func.io_init(g_spi.os_context)) {
PRINT_ER("[wilc spi]: Failed io init bus...\n");
return 0;
}
} else {
return 0;
}
g_spi.spi_tx = inp->io_func.u.spi.spi_tx;
g_spi.spi_rx = inp->io_func.u.spi.spi_rx;
g_spi.spi_trx = inp->io_func.u.spi.spi_trx;
g_spi.spi_max_speed = inp->io_func.u.spi.spi_max_speed;
g_spi.crc_off = 0;
if (!spi_internal_read(WILC_SPI_PROTOCOL_OFFSET, &reg)) {
g_spi.crc_off = 1;
PRINT_ER("[wilc spi]: Failed internal read protocol with CRC on, retyring with CRC off...\n");
if (!spi_internal_read(WILC_SPI_PROTOCOL_OFFSET, &reg)) {
PRINT_ER("[wilc spi]: Failed internal read protocol...\n");
return 0;
}
}
if (g_spi.crc_off == 0) {
reg &= ~0xc;
reg &= ~0x70;
reg |= (0x5 << 4);
if (!spi_internal_write(WILC_SPI_PROTOCOL_OFFSET, reg)) {
PRINT_ER("[wilc spi %d]: Failed internal write protocol reg...\n", __LINE__);
return 0;
}
g_spi.crc_off = 1;
}
if (!spi_read_reg(0x1000, &chipid)) {
PRINT_ER("[wilc spi]: Fail cmd read chip id...\n");
return 0;
}
g_spi.has_thrpt_enh = 1;
isinit = 1;
return 1;
}
static void spi_max_bus_speed(void)
{
g_spi.spi_max_speed();
}
static void spi_default_bus_speed(void)
{
}
static int spi_read_size(u32 *size)
{
int ret;
if (g_spi.has_thrpt_enh) {
ret = spi_internal_read(0xe840 - WILC_SPI_REG_BASE, size);
*size = *size & IRQ_DMA_WD_CNT_MASK;
} else {
u32 tmp;
u32 byte_cnt;
ret = spi_read_reg(WILC_VMM_TO_HOST_SIZE, &byte_cnt);
if (!ret) {
PRINT_ER("[wilc spi]: Failed read WILC_VMM_TO_HOST_SIZE ...\n");
goto _fail_;
}
tmp = (byte_cnt >> 2) & IRQ_DMA_WD_CNT_MASK;
*size = tmp;
}
_fail_:
return ret;
}
static int spi_read_int(u32 *int_status)
{
int ret;
if (g_spi.has_thrpt_enh) {
ret = spi_internal_read(0xe840 - WILC_SPI_REG_BASE, int_status);
} else {
u32 tmp;
u32 byte_cnt;
ret = spi_read_reg(WILC_VMM_TO_HOST_SIZE, &byte_cnt);
if (!ret) {
PRINT_ER("[wilc spi]: Failed read WILC_VMM_TO_HOST_SIZE ...\n");
goto _fail_;
}
tmp = (byte_cnt >> 2) & IRQ_DMA_WD_CNT_MASK;
{
int happended, j;
j = 0;
do {
u32 irq_flags;
happended = 0;
spi_read_reg(0x1a90, &irq_flags);
tmp |= ((irq_flags >> 27) << IRG_FLAGS_OFFSET);
if (g_spi.nint > 5) {
spi_read_reg(0x1a94, &irq_flags);
tmp |= (((irq_flags >> 0) & 0x7) << (IRG_FLAGS_OFFSET + 5));
}
{
u32 unkmown_mask;
unkmown_mask = ~((1ul << g_spi.nint) - 1);
if ((tmp >> IRG_FLAGS_OFFSET) & unkmown_mask) {
PRINT_ER("[wilc spi]: Unexpected interrupt (2): j=%d, tmp=%x, mask=%x\n", j, tmp, unkmown_mask);
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
static int spi_clear_int_ext(u32 val)
{
int ret;
if (g_spi.has_thrpt_enh) {
ret = spi_internal_write(0xe844 - WILC_SPI_REG_BASE, val);
} else {
u32 flags;
flags = val & (BIT(MAX_NUM_INT) - 1);
if (flags) {
int i;
ret = 1;
for (i = 0; i < g_spi.nint; i++) {
if (flags & 1)
ret = spi_write_reg(0x10c8 + i * 4, 1);
if (!ret)
break;
flags >>= 1;
}
if (!ret) {
PRINT_ER("[wilc spi]: Failed spi_write_reg, set reg %x ...\n", 0x10c8 + i * 4);
goto _fail_;
}
for (i = g_spi.nint; i < MAX_NUM_INT; i++) {
if (flags & 1)
PRINT_ER("[wilc spi]: Unexpected interrupt cleared %d...\n", i);
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
ret = spi_write_reg(WILC_VMM_TBL_CTL, tbl_ctl);
if (!ret) {
PRINT_ER("[wilc spi]: fail write reg vmm_tbl_ctl...\n");
goto _fail_;
}
if ((val & EN_VMM) == EN_VMM) {
ret = spi_write_reg(WILC_VMM_CORE_CTL, 1);
if (!ret) {
PRINT_ER("[wilc spi]: fail write reg vmm_core_ctl...\n");
goto _fail_;
}
}
}
}
_fail_:
return ret;
}
static int spi_sync_ext(int nint )
{
u32 reg;
int ret, i;
if (nint > MAX_NUM_INT) {
PRINT_ER("[wilc spi]: Too many interupts (%d)...\n", nint);
return 0;
}
g_spi.nint = nint;
ret = spi_read_reg(WILC_PIN_MUX_0, &reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed read reg (%08x)...\n", WILC_PIN_MUX_0);
return 0;
}
reg |= BIT(8);
ret = spi_write_reg(WILC_PIN_MUX_0, reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed write reg (%08x)...\n", WILC_PIN_MUX_0);
return 0;
}
ret = spi_read_reg(WILC_INTR_ENABLE, &reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed read reg (%08x)...\n", WILC_INTR_ENABLE);
return 0;
}
for (i = 0; (i < 5) && (nint > 0); i++, nint--) {
reg |= (BIT((27 + i)));
}
ret = spi_write_reg(WILC_INTR_ENABLE, reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed write reg (%08x)...\n", WILC_INTR_ENABLE);
return 0;
}
if (nint) {
ret = spi_read_reg(WILC_INTR2_ENABLE, &reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed read reg (%08x)...\n", WILC_INTR2_ENABLE);
return 0;
}
for (i = 0; (i < 3) && (nint > 0); i++, nint--) {
reg |= BIT(i);
}
ret = spi_read_reg(WILC_INTR2_ENABLE, &reg);
if (!ret) {
PRINT_ER("[wilc spi]: Failed write reg (%08x)...\n", WILC_INTR2_ENABLE);
return 0;
}
}
return 1;
}
