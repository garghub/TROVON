static inline int __mmc_send_status(struct mmc_card *card, u32 *status,
bool ignore_crc)
{
int err;
struct mmc_command cmd = {0};
BUG_ON(!card);
BUG_ON(!card->host);
cmd.opcode = MMC_SEND_STATUS;
if (!mmc_host_is_spi(card->host))
cmd.arg = card->rca << 16;
cmd.flags = MMC_RSP_SPI_R2 | MMC_RSP_R1 | MMC_CMD_AC;
if (ignore_crc)
cmd.flags &= ~MMC_RSP_CRC;
err = mmc_wait_for_cmd(card->host, &cmd, MMC_CMD_RETRIES);
if (err)
return err;
if (status)
*status = cmd.resp[0];
return 0;
}
int mmc_send_status(struct mmc_card *card, u32 *status)
{
return __mmc_send_status(card, status, false);
}
static int _mmc_select_card(struct mmc_host *host, struct mmc_card *card)
{
struct mmc_command cmd = {0};
BUG_ON(!host);
cmd.opcode = MMC_SELECT_CARD;
if (card) {
cmd.arg = card->rca << 16;
cmd.flags = MMC_RSP_R1 | MMC_CMD_AC;
} else {
cmd.arg = 0;
cmd.flags = MMC_RSP_NONE | MMC_CMD_AC;
}
return mmc_wait_for_cmd(host, &cmd, MMC_CMD_RETRIES);
}
int mmc_select_card(struct mmc_card *card)
{
BUG_ON(!card);
return _mmc_select_card(card->host, card);
}
int mmc_deselect_cards(struct mmc_host *host)
{
return _mmc_select_card(host, NULL);
}
int mmc_set_dsr(struct mmc_host *host)
{
struct mmc_command cmd = {0};
cmd.opcode = MMC_SET_DSR;
cmd.arg = (host->dsr << 16) | 0xffff;
cmd.flags = MMC_RSP_NONE | MMC_CMD_AC;
return mmc_wait_for_cmd(host, &cmd, MMC_CMD_RETRIES);
}
int mmc_go_idle(struct mmc_host *host)
{
int err;
struct mmc_command cmd = {0};
if (!mmc_host_is_spi(host)) {
mmc_set_chip_select(host, MMC_CS_HIGH);
mmc_delay(1);
}
cmd.opcode = MMC_GO_IDLE_STATE;
cmd.arg = 0;
cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_NONE | MMC_CMD_BC;
err = mmc_wait_for_cmd(host, &cmd, 0);
mmc_delay(1);
if (!mmc_host_is_spi(host)) {
mmc_set_chip_select(host, MMC_CS_DONTCARE);
mmc_delay(1);
}
host->use_spi_crc = 0;
return err;
}
int mmc_send_op_cond(struct mmc_host *host, u32 ocr, u32 *rocr)
{
struct mmc_command cmd = {0};
int i, err = 0;
BUG_ON(!host);
cmd.opcode = MMC_SEND_OP_COND;
cmd.arg = mmc_host_is_spi(host) ? 0 : ocr;
cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R3 | MMC_CMD_BCR;
for (i = 100; i; i--) {
err = mmc_wait_for_cmd(host, &cmd, 0);
if (err)
break;
if (ocr == 0)
break;
if (mmc_host_is_spi(host)) {
if (!(cmd.resp[0] & R1_SPI_IDLE))
break;
} else {
if (cmd.resp[0] & MMC_CARD_BUSY)
break;
}
err = -ETIMEDOUT;
mmc_delay(10);
}
if (rocr && !mmc_host_is_spi(host))
*rocr = cmd.resp[0];
return err;
}
int mmc_all_send_cid(struct mmc_host *host, u32 *cid)
{
int err;
struct mmc_command cmd = {0};
BUG_ON(!host);
BUG_ON(!cid);
cmd.opcode = MMC_ALL_SEND_CID;
cmd.arg = 0;
cmd.flags = MMC_RSP_R2 | MMC_CMD_BCR;
err = mmc_wait_for_cmd(host, &cmd, MMC_CMD_RETRIES);
if (err)
return err;
memcpy(cid, cmd.resp, sizeof(u32) * 4);
return 0;
}
int mmc_set_relative_addr(struct mmc_card *card)
{
struct mmc_command cmd = {0};
BUG_ON(!card);
BUG_ON(!card->host);
cmd.opcode = MMC_SET_RELATIVE_ADDR;
cmd.arg = card->rca << 16;
cmd.flags = MMC_RSP_R1 | MMC_CMD_AC;
return mmc_wait_for_cmd(card->host, &cmd, MMC_CMD_RETRIES);
}
static int
mmc_send_cxd_native(struct mmc_host *host, u32 arg, u32 *cxd, int opcode)
{
int err;
struct mmc_command cmd = {0};
BUG_ON(!host);
BUG_ON(!cxd);
cmd.opcode = opcode;
cmd.arg = arg;
cmd.flags = MMC_RSP_R2 | MMC_CMD_AC;
err = mmc_wait_for_cmd(host, &cmd, MMC_CMD_RETRIES);
if (err)
return err;
memcpy(cxd, cmd.resp, sizeof(u32) * 4);
return 0;
}
static int
mmc_send_cxd_data(struct mmc_card *card, struct mmc_host *host,
u32 opcode, void *buf, unsigned len)
{
struct mmc_request mrq = {NULL};
struct mmc_command cmd = {0};
struct mmc_data data = {0};
struct scatterlist sg;
mrq.cmd = &cmd;
mrq.data = &data;
cmd.opcode = opcode;
cmd.arg = 0;
cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;
data.blksz = len;
data.blocks = 1;
data.flags = MMC_DATA_READ;
data.sg = &sg;
data.sg_len = 1;
sg_init_one(&sg, buf, len);
if (opcode == MMC_SEND_CSD || opcode == MMC_SEND_CID) {
data.timeout_ns = 0;
data.timeout_clks = 64;
} else
mmc_set_data_timeout(&data, card);
mmc_wait_for_req(host, &mrq);
if (cmd.error)
return cmd.error;
if (data.error)
return data.error;
return 0;
}
int mmc_send_csd(struct mmc_card *card, u32 *csd)
{
int ret, i;
u32 *csd_tmp;
if (!mmc_host_is_spi(card->host))
return mmc_send_cxd_native(card->host, card->rca << 16,
csd, MMC_SEND_CSD);
csd_tmp = kzalloc(16, GFP_KERNEL);
if (!csd_tmp)
return -ENOMEM;
ret = mmc_send_cxd_data(card, card->host, MMC_SEND_CSD, csd_tmp, 16);
if (ret)
goto err;
for (i = 0;i < 4;i++)
csd[i] = be32_to_cpu(csd_tmp[i]);
err:
kfree(csd_tmp);
return ret;
}
int mmc_send_cid(struct mmc_host *host, u32 *cid)
{
int ret, i;
u32 *cid_tmp;
if (!mmc_host_is_spi(host)) {
if (!host->card)
return -EINVAL;
return mmc_send_cxd_native(host, host->card->rca << 16,
cid, MMC_SEND_CID);
}
cid_tmp = kzalloc(16, GFP_KERNEL);
if (!cid_tmp)
return -ENOMEM;
ret = mmc_send_cxd_data(NULL, host, MMC_SEND_CID, cid_tmp, 16);
if (ret)
goto err;
for (i = 0;i < 4;i++)
cid[i] = be32_to_cpu(cid_tmp[i]);
err:
kfree(cid_tmp);
return ret;
}
int mmc_get_ext_csd(struct mmc_card *card, u8 **new_ext_csd)
{
int err;
u8 *ext_csd;
if (!card || !new_ext_csd)
return -EINVAL;
if (!mmc_can_ext_csd(card))
return -EOPNOTSUPP;
ext_csd = kzalloc(512, GFP_KERNEL);
if (!ext_csd)
return -ENOMEM;
err = mmc_send_cxd_data(card, card->host, MMC_SEND_EXT_CSD, ext_csd,
512);
if (err)
kfree(ext_csd);
else
*new_ext_csd = ext_csd;
return err;
}
int mmc_spi_read_ocr(struct mmc_host *host, int highcap, u32 *ocrp)
{
struct mmc_command cmd = {0};
int err;
cmd.opcode = MMC_SPI_READ_OCR;
cmd.arg = highcap ? (1 << 30) : 0;
cmd.flags = MMC_RSP_SPI_R3;
err = mmc_wait_for_cmd(host, &cmd, 0);
*ocrp = cmd.resp[1];
return err;
}
int mmc_spi_set_crc(struct mmc_host *host, int use_crc)
{
struct mmc_command cmd = {0};
int err;
cmd.opcode = MMC_SPI_CRC_ON_OFF;
cmd.flags = MMC_RSP_SPI_R1;
cmd.arg = use_crc;
err = mmc_wait_for_cmd(host, &cmd, 0);
if (!err)
host->use_spi_crc = use_crc;
return err;
}
int mmc_switch_status_error(struct mmc_host *host, u32 status)
{
if (mmc_host_is_spi(host)) {
if (status & R1_SPI_ILLEGAL_COMMAND)
return -EBADMSG;
} else {
if (status & 0xFDFFA000)
pr_warn("%s: unexpected status %#x after switch\n",
mmc_hostname(host), status);
if (status & R1_SWITCH_ERROR)
return -EBADMSG;
}
return 0;
}
int __mmc_switch(struct mmc_card *card, u8 set, u8 index, u8 value,
unsigned int timeout_ms, bool use_busy_signal, bool send_status,
bool ignore_crc)
{
struct mmc_host *host = card->host;
int err;
struct mmc_command cmd = {0};
unsigned long timeout;
u32 status = 0;
bool use_r1b_resp = use_busy_signal;
bool expired = false;
mmc_retune_hold(host);
if (timeout_ms && host->max_busy_timeout &&
(timeout_ms > host->max_busy_timeout))
use_r1b_resp = false;
cmd.opcode = MMC_SWITCH;
cmd.arg = (MMC_SWITCH_MODE_WRITE_BYTE << 24) |
(index << 16) |
(value << 8) |
set;
cmd.flags = MMC_CMD_AC;
if (use_r1b_resp) {
cmd.flags |= MMC_RSP_SPI_R1B | MMC_RSP_R1B;
cmd.busy_timeout = timeout_ms;
} else {
cmd.flags |= MMC_RSP_SPI_R1 | MMC_RSP_R1;
}
if (index == EXT_CSD_SANITIZE_START)
cmd.sanitize_busy = true;
err = mmc_wait_for_cmd(host, &cmd, MMC_CMD_RETRIES);
if (err)
goto out;
if (!use_busy_signal)
goto out;
if ((host->caps & MMC_CAP_WAIT_WHILE_BUSY) && use_r1b_resp)
ignore_crc = false;
if (!timeout_ms)
timeout_ms = MMC_OPS_TIMEOUT_MS;
timeout = jiffies + msecs_to_jiffies(timeout_ms);
do {
if (send_status) {
expired = time_after(jiffies, timeout);
err = __mmc_send_status(card, &status, ignore_crc);
if (err)
goto out;
}
if ((host->caps & MMC_CAP_WAIT_WHILE_BUSY) && use_r1b_resp)
break;
if (mmc_host_is_spi(host))
break;
if (!send_status) {
mmc_delay(timeout_ms);
goto out;
}
if (expired && R1_CURRENT_STATE(status) == R1_STATE_PRG) {
pr_err("%s: Card stuck in programming state! %s\n",
mmc_hostname(host), __func__);
err = -ETIMEDOUT;
goto out;
}
} while (R1_CURRENT_STATE(status) == R1_STATE_PRG);
err = mmc_switch_status_error(host, status);
out:
mmc_retune_release(host);
return err;
}
int mmc_switch(struct mmc_card *card, u8 set, u8 index, u8 value,
unsigned int timeout_ms)
{
return __mmc_switch(card, set, index, value, timeout_ms, true, true,
false);
}
int mmc_send_tuning(struct mmc_host *host, u32 opcode, int *cmd_error)
{
struct mmc_request mrq = {NULL};
struct mmc_command cmd = {0};
struct mmc_data data = {0};
struct scatterlist sg;
struct mmc_ios *ios = &host->ios;
const u8 *tuning_block_pattern;
int size, err = 0;
u8 *data_buf;
if (ios->bus_width == MMC_BUS_WIDTH_8) {
tuning_block_pattern = tuning_blk_pattern_8bit;
size = sizeof(tuning_blk_pattern_8bit);
} else if (ios->bus_width == MMC_BUS_WIDTH_4) {
tuning_block_pattern = tuning_blk_pattern_4bit;
size = sizeof(tuning_blk_pattern_4bit);
} else
return -EINVAL;
data_buf = kzalloc(size, GFP_KERNEL);
if (!data_buf)
return -ENOMEM;
mrq.cmd = &cmd;
mrq.data = &data;
cmd.opcode = opcode;
cmd.flags = MMC_RSP_R1 | MMC_CMD_ADTC;
data.blksz = size;
data.blocks = 1;
data.flags = MMC_DATA_READ;
data.timeout_ns = 150 * NSEC_PER_MSEC;
data.sg = &sg;
data.sg_len = 1;
sg_init_one(&sg, data_buf, size);
mmc_wait_for_req(host, &mrq);
if (cmd_error)
*cmd_error = cmd.error;
if (cmd.error) {
err = cmd.error;
goto out;
}
if (data.error) {
err = data.error;
goto out;
}
if (memcmp(data_buf, tuning_block_pattern, size))
err = -EIO;
out:
kfree(data_buf);
return err;
}
static int
mmc_send_bus_test(struct mmc_card *card, struct mmc_host *host, u8 opcode,
u8 len)
{
struct mmc_request mrq = {NULL};
struct mmc_command cmd = {0};
struct mmc_data data = {0};
struct scatterlist sg;
u8 *data_buf;
u8 *test_buf;
int i, err;
static u8 testdata_8bit[8] = { 0x55, 0xaa, 0, 0, 0, 0, 0, 0 };
static u8 testdata_4bit[4] = { 0x5a, 0, 0, 0 };
data_buf = kmalloc(len, GFP_KERNEL);
if (!data_buf)
return -ENOMEM;
if (len == 8)
test_buf = testdata_8bit;
else if (len == 4)
test_buf = testdata_4bit;
else {
pr_err("%s: Invalid bus_width %d\n",
mmc_hostname(host), len);
kfree(data_buf);
return -EINVAL;
}
if (opcode == MMC_BUS_TEST_W)
memcpy(data_buf, test_buf, len);
mrq.cmd = &cmd;
mrq.data = &data;
cmd.opcode = opcode;
cmd.arg = 0;
cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;
data.blksz = len;
data.blocks = 1;
if (opcode == MMC_BUS_TEST_R)
data.flags = MMC_DATA_READ;
else
data.flags = MMC_DATA_WRITE;
data.sg = &sg;
data.sg_len = 1;
mmc_set_data_timeout(&data, card);
sg_init_one(&sg, data_buf, len);
mmc_wait_for_req(host, &mrq);
err = 0;
if (opcode == MMC_BUS_TEST_R) {
for (i = 0; i < len / 4; i++)
if ((test_buf[i] ^ data_buf[i]) != 0xff) {
err = -EIO;
break;
}
}
kfree(data_buf);
if (cmd.error)
return cmd.error;
if (data.error)
return data.error;
return err;
}
int mmc_bus_test(struct mmc_card *card, u8 bus_width)
{
int width;
if (bus_width == MMC_BUS_WIDTH_8)
width = 8;
else if (bus_width == MMC_BUS_WIDTH_4)
width = 4;
else if (bus_width == MMC_BUS_WIDTH_1)
return 0;
else
return -EINVAL;
mmc_send_bus_test(card, card->host, MMC_BUS_TEST_W, width);
return mmc_send_bus_test(card, card->host, MMC_BUS_TEST_R, width);
}
int mmc_send_hpi_cmd(struct mmc_card *card, u32 *status)
{
struct mmc_command cmd = {0};
unsigned int opcode;
int err;
if (!card->ext_csd.hpi) {
pr_warn("%s: Card didn't support HPI command\n",
mmc_hostname(card->host));
return -EINVAL;
}
opcode = card->ext_csd.hpi_cmd;
if (opcode == MMC_STOP_TRANSMISSION)
cmd.flags = MMC_RSP_R1B | MMC_CMD_AC;
else if (opcode == MMC_SEND_STATUS)
cmd.flags = MMC_RSP_R1 | MMC_CMD_AC;
cmd.opcode = opcode;
cmd.arg = card->rca << 16 | 1;
err = mmc_wait_for_cmd(card->host, &cmd, 0);
if (err) {
pr_warn("%s: error %d interrupting operation. "
"HPI command response %#x\n", mmc_hostname(card->host),
err, cmd.resp[0]);
return err;
}
if (status)
*status = cmd.resp[0];
return 0;
}
int mmc_can_ext_csd(struct mmc_card *card)
{
return (card && card->csd.mmca_vsn > CSD_SPEC_VER_3);
}
