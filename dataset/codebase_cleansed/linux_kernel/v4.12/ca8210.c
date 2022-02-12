static int link_to_linux_err(int link_status)
{
if (link_status < 0) {
return link_status;
}
switch (link_status) {
case MAC_SUCCESS:
case MAC_REALIGNMENT:
return 0;
case MAC_IMPROPER_KEY_TYPE:
return -EKEYREJECTED;
case MAC_IMPROPER_SECURITY_LEVEL:
case MAC_UNSUPPORTED_LEGACY:
case MAC_DENIED:
return -EACCES;
case MAC_BEACON_LOST:
case MAC_NO_ACK:
case MAC_NO_BEACON:
return -ENETUNREACH;
case MAC_CHANNEL_ACCESS_FAILURE:
case MAC_TX_ACTIVE:
case MAC_SCAN_IN_PROGRESS:
return -EBUSY;
case MAC_DISABLE_TRX_FAILURE:
case MAC_OUT_OF_CAP:
return -EAGAIN;
case MAC_FRAME_TOO_LONG:
return -EMSGSIZE;
case MAC_INVALID_GTS:
case MAC_PAST_TIME:
return -EBADSLT;
case MAC_INVALID_HANDLE:
return -EBADMSG;
case MAC_INVALID_PARAMETER:
case MAC_UNSUPPORTED_ATTRIBUTE:
case MAC_ON_TIME_TOO_LONG:
case MAC_INVALID_INDEX:
return -EINVAL;
case MAC_NO_DATA:
return -ENODATA;
case MAC_NO_SHORT_ADDRESS:
return -EFAULT;
case MAC_PAN_ID_CONFLICT:
return -EADDRINUSE;
case MAC_TRANSACTION_EXPIRED:
return -ETIME;
case MAC_TRANSACTION_OVERFLOW:
return -ENOBUFS;
case MAC_UNAVAILABLE_KEY:
return -ENOKEY;
case MAC_INVALID_ADDRESS:
return -ENXIO;
case MAC_TRACKING_OFF:
case MAC_SUPERFRAME_OVERLAP:
return -EREMOTEIO;
case MAC_LIMIT_REACHED:
return -EDQUOT;
case MAC_READ_ONLY:
return -EROFS;
default:
return -EPROTO;
}
}
static int ca8210_test_int_driver_write(
const u8 *buf,
size_t len,
void *spi
)
{
struct ca8210_priv *priv = spi_get_drvdata(spi);
struct ca8210_test *test = &priv->test;
char *fifo_buffer;
int i;
dev_dbg(
&priv->spi->dev,
"test_interface: Buffering upstream message:\n"
);
for (i = 0; i < len; i++)
dev_dbg(&priv->spi->dev, "%#03x\n", buf[i]);
fifo_buffer = kmalloc(len, GFP_KERNEL);
if (!fifo_buffer)
return -ENOMEM;
memcpy(fifo_buffer, buf, len);
kfifo_in(&test->up_fifo, &fifo_buffer, 4);
wake_up_interruptible(&priv->test.readq);
return 0;
}
static void ca8210_reset_send(struct spi_device *spi, unsigned int ms)
{
struct ca8210_platform_data *pdata = spi->dev.platform_data;
struct ca8210_priv *priv = spi_get_drvdata(spi);
long status;
gpio_set_value(pdata->gpio_reset, 0);
reinit_completion(&priv->ca8210_is_awake);
msleep(ms);
gpio_set_value(pdata->gpio_reset, 1);
priv->promiscuous = false;
status = wait_for_completion_interruptible_timeout(
&priv->ca8210_is_awake,
msecs_to_jiffies(CA8210_SYNC_TIMEOUT)
);
if (status == 0) {
dev_crit(
&spi->dev,
"Fatal: No wakeup from ca8210 after reset!\n"
);
}
dev_dbg(&spi->dev, "Reset the device\n");
}
static void ca8210_mlme_reset_worker(struct work_struct *work)
{
struct work_priv_container *wpc = container_of(
work,
struct work_priv_container,
work
);
struct ca8210_priv *priv = wpc->priv;
mlme_reset_request_sync(0, priv->spi);
kfree(wpc);
}
static void ca8210_rx_done(struct cas_control *cas_ctl)
{
u8 *buf;
u8 len;
struct work_priv_container *mlme_reset_wpc;
struct ca8210_priv *priv = cas_ctl->priv;
buf = cas_ctl->tx_in_buf;
len = buf[1] + 2;
if (len > CA8210_SPI_BUF_SIZE) {
dev_crit(
&priv->spi->dev,
"Received packet len (%d) erroneously long\n",
len
);
goto finish;
}
if (buf[0] & SPI_SYN) {
if (priv->sync_command_response) {
memcpy(priv->sync_command_response, buf, len);
complete(&priv->sync_exchange_complete);
} else {
if (cascoda_api_upstream)
cascoda_api_upstream(buf, len, priv->spi);
priv->sync_up++;
}
} else {
if (cascoda_api_upstream)
cascoda_api_upstream(buf, len, priv->spi);
}
ca8210_net_rx(priv->hw, buf, len);
if (buf[0] == SPI_MCPS_DATA_CONFIRM) {
if (buf[3] == MAC_TRANSACTION_OVERFLOW) {
dev_info(
&priv->spi->dev,
"Waiting for transaction overflow to stabilise...\n");
msleep(2000);
dev_info(
&priv->spi->dev,
"Resetting MAC...\n");
mlme_reset_wpc = kmalloc(sizeof(*mlme_reset_wpc),
GFP_KERNEL);
if (!mlme_reset_wpc)
goto finish;
INIT_WORK(
&mlme_reset_wpc->work,
ca8210_mlme_reset_worker
);
mlme_reset_wpc->priv = priv;
queue_work(priv->mlme_workqueue, &mlme_reset_wpc->work);
}
} else if (buf[0] == SPI_HWME_WAKEUP_INDICATION) {
dev_notice(
&priv->spi->dev,
"Wakeup indication received, reason:\n"
);
switch (buf[2]) {
case 0:
dev_notice(
&priv->spi->dev,
"Transceiver woken up from Power Up / System Reset\n"
);
break;
case 1:
dev_notice(
&priv->spi->dev,
"Watchdog Timer Time-Out\n"
);
break;
case 2:
dev_notice(
&priv->spi->dev,
"Transceiver woken up from Power-Off by Sleep Timer Time-Out\n");
break;
case 3:
dev_notice(
&priv->spi->dev,
"Transceiver woken up from Power-Off by GPIO Activity\n"
);
break;
case 4:
dev_notice(
&priv->spi->dev,
"Transceiver woken up from Standby by Sleep Timer Time-Out\n"
);
break;
case 5:
dev_notice(
&priv->spi->dev,
"Transceiver woken up from Standby by GPIO Activity\n"
);
break;
case 6:
dev_notice(
&priv->spi->dev,
"Sleep-Timer Time-Out in Active Mode\n"
);
break;
default:
dev_warn(&priv->spi->dev, "Wakeup reason unknown\n");
break;
}
complete(&priv->ca8210_is_awake);
}
finish:;
}
static void ca8210_spi_transfer_complete(void *context)
{
struct cas_control *cas_ctl = context;
struct ca8210_priv *priv = cas_ctl->priv;
bool duplex_rx = false;
int i;
u8 retry_buffer[CA8210_SPI_BUF_SIZE];
if (
cas_ctl->tx_in_buf[0] == SPI_NACK ||
(cas_ctl->tx_in_buf[0] == SPI_IDLE &&
cas_ctl->tx_in_buf[1] == SPI_NACK)
) {
dev_info(&priv->spi->dev, "ca8210 was busy during attempted write\n");
if (cas_ctl->tx_buf[0] == SPI_IDLE) {
dev_warn(
&priv->spi->dev,
"IRQ servicing NACKd, dropping transfer\n"
);
kfree(cas_ctl);
return;
}
if (priv->retries > 3) {
dev_err(&priv->spi->dev, "too many retries!\n");
kfree(cas_ctl);
ca8210_remove(priv->spi);
return;
}
memcpy(retry_buffer, cas_ctl->tx_buf, CA8210_SPI_BUF_SIZE);
kfree(cas_ctl);
ca8210_spi_transfer(
priv->spi,
retry_buffer,
CA8210_SPI_BUF_SIZE
);
priv->retries++;
dev_info(&priv->spi->dev, "retried spi write\n");
return;
} else if (
cas_ctl->tx_in_buf[0] != SPI_IDLE &&
cas_ctl->tx_in_buf[0] != SPI_NACK
) {
duplex_rx = true;
}
if (duplex_rx) {
dev_dbg(&priv->spi->dev, "READ CMD DURING TX\n");
for (i = 0; i < cas_ctl->tx_in_buf[1] + 2; i++)
dev_dbg(
&priv->spi->dev,
"%#03x\n",
cas_ctl->tx_in_buf[i]
);
ca8210_rx_done(cas_ctl);
}
complete(&priv->spi_transfer_complete);
kfree(cas_ctl);
priv->retries = 0;
}
static int ca8210_spi_transfer(
struct spi_device *spi,
const u8 *buf,
size_t len
)
{
int i, status = 0;
struct ca8210_priv *priv = spi_get_drvdata(spi);
struct cas_control *cas_ctl;
if (!spi) {
dev_crit(
&spi->dev,
"NULL spi device passed to ca8210_spi_transfer\n"
);
return -ENODEV;
}
reinit_completion(&priv->spi_transfer_complete);
dev_dbg(&spi->dev, "ca8210_spi_transfer called\n");
cas_ctl = kmalloc(sizeof(*cas_ctl), GFP_ATOMIC);
if (!cas_ctl)
return -ENOMEM;
cas_ctl->priv = priv;
memset(cas_ctl->tx_buf, SPI_IDLE, CA8210_SPI_BUF_SIZE);
memset(cas_ctl->tx_in_buf, SPI_IDLE, CA8210_SPI_BUF_SIZE);
memcpy(cas_ctl->tx_buf, buf, len);
for (i = 0; i < len; i++)
dev_dbg(&spi->dev, "%#03x\n", cas_ctl->tx_buf[i]);
spi_message_init(&cas_ctl->msg);
cas_ctl->transfer.tx_nbits = 1;
cas_ctl->transfer.rx_nbits = 1;
cas_ctl->transfer.speed_hz = 0;
cas_ctl->transfer.bits_per_word = 0;
cas_ctl->transfer.tx_buf = cas_ctl->tx_buf;
cas_ctl->transfer.rx_buf = cas_ctl->tx_in_buf;
cas_ctl->transfer.delay_usecs = 0;
cas_ctl->transfer.cs_change = 0;
cas_ctl->transfer.len = sizeof(struct mac_message);
cas_ctl->msg.complete = ca8210_spi_transfer_complete;
cas_ctl->msg.context = cas_ctl;
spi_message_add_tail(
&cas_ctl->transfer,
&cas_ctl->msg
);
status = spi_async(spi, &cas_ctl->msg);
if (status < 0) {
dev_crit(
&spi->dev,
"status %d from spi_sync in write\n",
status
);
}
return status;
}
static int ca8210_spi_exchange(
const u8 *buf,
size_t len,
u8 *response,
void *device_ref
)
{
int status = 0;
struct spi_device *spi = device_ref;
struct ca8210_priv *priv = spi->dev.driver_data;
long wait_remaining;
if ((buf[0] & SPI_SYN) && response) {
reinit_completion(&priv->sync_exchange_complete);
priv->sync_command_response = response;
}
do {
reinit_completion(&priv->spi_transfer_complete);
status = ca8210_spi_transfer(priv->spi, buf, len);
if (status) {
dev_warn(
&spi->dev,
"spi write failed, returned %d\n",
status
);
if (status == -EBUSY)
continue;
if (((buf[0] & SPI_SYN) && response))
complete(&priv->sync_exchange_complete);
goto cleanup;
}
wait_remaining = wait_for_completion_interruptible_timeout(
&priv->spi_transfer_complete,
msecs_to_jiffies(1000)
);
if (wait_remaining == -ERESTARTSYS) {
status = -ERESTARTSYS;
} else if (wait_remaining == 0) {
dev_err(
&spi->dev,
"SPI downstream transfer timed out!\n"
);
status = -ETIME;
goto cleanup;
}
} while (status < 0);
if (!((buf[0] & SPI_SYN) && response))
goto cleanup;
wait_remaining = wait_for_completion_interruptible_timeout(
&priv->sync_exchange_complete,
msecs_to_jiffies(CA8210_SYNC_TIMEOUT)
);
if (wait_remaining == -ERESTARTSYS) {
status = -ERESTARTSYS;
} else if (wait_remaining == 0) {
dev_err(
&spi->dev,
"Synchronous confirm timeout\n"
);
status = -ETIME;
}
cleanup:
priv->sync_command_response = NULL;
return status;
}
static irqreturn_t ca8210_interrupt_handler(int irq, void *dev_id)
{
struct ca8210_priv *priv = dev_id;
int status;
dev_dbg(&priv->spi->dev, "irq: Interrupt occurred\n");
do {
status = ca8210_spi_transfer(priv->spi, NULL, 0);
if (status && (status != -EBUSY)) {
dev_warn(
&priv->spi->dev,
"spi read failed, returned %d\n",
status
);
}
} while (status == -EBUSY);
return IRQ_HANDLED;
}
static u8 tdme_setsfr_request_sync(
u8 sfr_page,
u8 sfr_address,
u8 sfr_value,
void *device_ref
)
{
int ret;
struct mac_message command, response;
struct spi_device *spi = device_ref;
command.command_id = SPI_TDME_SETSFR_REQUEST;
command.length = 3;
command.pdata.tdme_set_sfr_req.sfr_page = sfr_page;
command.pdata.tdme_set_sfr_req.sfr_address = sfr_address;
command.pdata.tdme_set_sfr_req.sfr_value = sfr_value;
response.command_id = SPI_IDLE;
ret = cascoda_api_downstream(
&command.command_id,
command.length + 2,
&response.command_id,
device_ref
);
if (ret) {
dev_crit(&spi->dev, "cascoda_api_downstream returned %d", ret);
return MAC_SYSTEM_ERROR;
}
if (response.command_id != SPI_TDME_SETSFR_CONFIRM) {
dev_crit(
&spi->dev,
"sync response to SPI_TDME_SETSFR_REQUEST was not SPI_TDME_SETSFR_CONFIRM, it was %d\n",
response.command_id
);
return MAC_SYSTEM_ERROR;
}
return response.pdata.tdme_set_sfr_cnf.status;
}
static u8 tdme_chipinit(void *device_ref)
{
u8 status = MAC_SUCCESS;
u8 sfr_address;
struct spi_device *spi = device_ref;
struct preamble_cfg_sfr pre_cfg_value = {
.timeout_symbols = 3,
.acquisition_symbols = 3,
.search_symbols = 1,
};
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX40),
LNAGX40_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX41),
LNAGX41_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX42),
LNAGX42_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX43),
LNAGX43_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX44),
LNAGX44_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX45),
LNAGX45_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX46),
LNAGX46_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_LNAGX47),
LNAGX47_DEFAULT_GAIN, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_PRECFG),
*((u8 *)&pre_cfg_value), device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
1, (sfr_address = CA8210_SFR_PTHRH),
PTHRH_DEFAULT_THRESHOLD, device_ref);
if (status)
goto finish;
status = tdme_setsfr_request_sync(
0, (sfr_address = CA8210_SFR_PACFGIB),
PACFGIB_DEFAULT_CURRENT, device_ref);
if (status)
goto finish;
finish:
if (status != MAC_SUCCESS) {
dev_err(
&spi->dev,
"failed to set sfr at %#03x, status = %#03x\n",
sfr_address,
status
);
}
return status;
}
static u8 tdme_channelinit(u8 channel, void *device_ref)
{
u8 txcalval;
if (channel >= 25)
txcalval = 0xA7;
else if (channel >= 23)
txcalval = 0xA8;
else if (channel >= 22)
txcalval = 0xA9;
else if (channel >= 20)
txcalval = 0xAA;
else if (channel >= 17)
txcalval = 0xAB;
else if (channel >= 16)
txcalval = 0xAC;
else if (channel >= 14)
txcalval = 0xAD;
else if (channel >= 12)
txcalval = 0xAE;
else
txcalval = 0xAF;
return tdme_setsfr_request_sync(
1,
CA8210_SFR_LOTXCAL,
txcalval,
device_ref
);
}
static u8 tdme_checkpibattribute(
u8 pib_attribute,
u8 pib_attribute_length,
const void *pib_attribute_value
)
{
u8 status = MAC_SUCCESS;
u8 value;
value = *((u8 *)pib_attribute_value);
switch (pib_attribute) {
case PHY_TRANSMIT_POWER:
if (value > 0x3F)
status = MAC_INVALID_PARAMETER;
break;
case PHY_CCA_MODE:
if (value > 0x03)
status = MAC_INVALID_PARAMETER;
break;
case MAC_BATT_LIFE_EXT_PERIODS:
if ((value < 6) || (value > 41))
status = MAC_INVALID_PARAMETER;
break;
case MAC_BEACON_PAYLOAD:
if (pib_attribute_length > MAX_BEACON_PAYLOAD_LENGTH)
status = MAC_INVALID_PARAMETER;
break;
case MAC_BEACON_PAYLOAD_LENGTH:
if (value > MAX_BEACON_PAYLOAD_LENGTH)
status = MAC_INVALID_PARAMETER;
break;
case MAC_BEACON_ORDER:
if (value > 15)
status = MAC_INVALID_PARAMETER;
break;
case MAC_MAX_BE:
if ((value < 3) || (value > 8))
status = MAC_INVALID_PARAMETER;
break;
case MAC_MAX_CSMA_BACKOFFS:
if (value > 5)
status = MAC_INVALID_PARAMETER;
break;
case MAC_MAX_FRAME_RETRIES:
if (value > 7)
status = MAC_INVALID_PARAMETER;
break;
case MAC_MIN_BE:
if (value > 8)
status = MAC_INVALID_PARAMETER;
break;
case MAC_RESPONSE_WAIT_TIME:
if ((value < 2) || (value > 64))
status = MAC_INVALID_PARAMETER;
break;
case MAC_SUPERFRAME_ORDER:
if (value > 15)
status = MAC_INVALID_PARAMETER;
break;
case MAC_ASSOCIATED_PAN_COORD:
case MAC_ASSOCIATION_PERMIT:
case MAC_AUTO_REQUEST:
case MAC_BATT_LIFE_EXT:
case MAC_GTS_PERMIT:
case MAC_PROMISCUOUS_MODE:
case MAC_RX_ON_WHEN_IDLE:
case MAC_SECURITY_ENABLED:
if (value > 1)
status = MAC_INVALID_PARAMETER;
break;
case MAC_AUTO_REQUEST_SECURITY_LEVEL:
if (value > 7)
status = MAC_INVALID_PARAMETER;
break;
case MAC_AUTO_REQUEST_KEY_ID_MODE:
if (value > 3)
status = MAC_INVALID_PARAMETER;
break;
default:
break;
}
return status;
}
static u8 tdme_settxpower(u8 txp, void *device_ref)
{
u8 status;
s8 txp_val;
u8 txp_ext;
union pa_cfg_sfr pa_cfg_val;
txp_ext = 0x3F & txp;
if (txp_ext & 0x20)
txp_ext += 0xC0;
txp_val = (s8)txp_ext;
if (CA8210_MAC_MPW) {
if (txp_val > 0) {
pa_cfg_val.bias_current_trim = 3;
pa_cfg_val.buffer_capacitor_trim = 5;
pa_cfg_val.boost = 1;
} else {
pa_cfg_val.bias_current_trim = 3;
pa_cfg_val.buffer_capacitor_trim = 7;
pa_cfg_val.boost = 0;
}
status = tdme_setsfr_request_sync(
0,
CA8210_SFR_PACFG,
pa_cfg_val.paib,
device_ref
);
} else {
if (txp_val > 8) {
pa_cfg_val.paib = 0x3F;
} else if (txp_val == 8) {
pa_cfg_val.paib = 0x32;
} else if (txp_val == 7) {
pa_cfg_val.paib = 0x22;
} else if (txp_val == 6) {
pa_cfg_val.paib = 0x18;
} else if (txp_val == 5) {
pa_cfg_val.paib = 0x10;
} else if (txp_val == 4) {
pa_cfg_val.paib = 0x0C;
} else if (txp_val == 3) {
pa_cfg_val.paib = 0x08;
} else if (txp_val == 2) {
pa_cfg_val.paib = 0x05;
} else if (txp_val == 1) {
pa_cfg_val.paib = 0x03;
} else if (txp_val == 0) {
pa_cfg_val.paib = 0x01;
} else {
pa_cfg_val.paib = 0x00;
}
status = tdme_setsfr_request_sync(
0,
CA8210_SFR_PACFGIB,
pa_cfg_val.paib,
device_ref
);
}
return status;
}
static u8 mcps_data_request(
u8 src_addr_mode,
u8 dst_address_mode,
u16 dst_pan_id,
union macaddr *dst_addr,
u8 msdu_length,
u8 *msdu,
u8 msdu_handle,
u8 tx_options,
struct secspec *security,
void *device_ref
)
{
struct secspec *psec;
struct mac_message command;
command.command_id = SPI_MCPS_DATA_REQUEST;
command.pdata.data_req.src_addr_mode = src_addr_mode;
command.pdata.data_req.dst.mode = dst_address_mode;
if (dst_address_mode != MAC_MODE_NO_ADDR) {
command.pdata.data_req.dst.pan_id[0] = LS_BYTE(dst_pan_id);
command.pdata.data_req.dst.pan_id[1] = MS_BYTE(dst_pan_id);
if (dst_address_mode == MAC_MODE_SHORT_ADDR) {
command.pdata.data_req.dst.address[0] = LS_BYTE(
dst_addr->short_address
);
command.pdata.data_req.dst.address[1] = MS_BYTE(
dst_addr->short_address
);
} else {
memcpy(
command.pdata.data_req.dst.address,
dst_addr->ieee_address,
8
);
}
}
command.pdata.data_req.msdu_length = msdu_length;
command.pdata.data_req.msdu_handle = msdu_handle;
command.pdata.data_req.tx_options = tx_options;
memcpy(command.pdata.data_req.msdu, msdu, msdu_length);
psec = (struct secspec *)(command.pdata.data_req.msdu + msdu_length);
command.length = sizeof(struct mcps_data_request_pset) -
MAX_DATA_SIZE + msdu_length;
if (!security || (security->security_level == 0)) {
psec->security_level = 0;
command.length += 1;
} else {
*psec = *security;
command.length += sizeof(struct secspec);
}
if (ca8210_spi_transfer(device_ref, &command.command_id,
command.length + 2))
return MAC_SYSTEM_ERROR;
return MAC_SUCCESS;
}
static u8 mlme_reset_request_sync(
u8 set_default_pib,
void *device_ref
)
{
u8 status;
struct mac_message command, response;
struct spi_device *spi = device_ref;
command.command_id = SPI_MLME_RESET_REQUEST;
command.length = 1;
command.pdata.u8param = set_default_pib;
if (cascoda_api_downstream(
&command.command_id,
command.length + 2,
&response.command_id,
device_ref)) {
dev_err(&spi->dev, "cascoda_api_downstream failed\n");
return MAC_SYSTEM_ERROR;
}
if (response.command_id != SPI_MLME_RESET_CONFIRM)
return MAC_SYSTEM_ERROR;
status = response.pdata.status;
if (CA8210_MAC_WORKAROUNDS && set_default_pib && (!status)) {
status = tdme_setsfr_request_sync(
0,
CA8210_SFR_MACCON,
0,
device_ref
);
}
return status;
}
static u8 mlme_set_request_sync(
u8 pib_attribute,
u8 pib_attribute_index,
u8 pib_attribute_length,
const void *pib_attribute_value,
void *device_ref
)
{
u8 status;
struct mac_message command, response;
if (tdme_checkpibattribute(
pib_attribute, pib_attribute_length, pib_attribute_value)) {
return MAC_INVALID_PARAMETER;
}
if (pib_attribute == PHY_CURRENT_CHANNEL) {
status = tdme_channelinit(
*((u8 *)pib_attribute_value),
device_ref
);
if (status)
return status;
}
if (pib_attribute == PHY_TRANSMIT_POWER) {
return tdme_settxpower(
*((u8 *)pib_attribute_value),
device_ref
);
}
command.command_id = SPI_MLME_SET_REQUEST;
command.length = sizeof(struct mlme_set_request_pset) -
MAX_ATTRIBUTE_SIZE + pib_attribute_length;
command.pdata.set_req.pib_attribute = pib_attribute;
command.pdata.set_req.pib_attribute_index = pib_attribute_index;
command.pdata.set_req.pib_attribute_length = pib_attribute_length;
memcpy(
command.pdata.set_req.pib_attribute_value,
pib_attribute_value,
pib_attribute_length
);
if (cascoda_api_downstream(
&command.command_id,
command.length + 2,
&response.command_id,
device_ref)) {
return MAC_SYSTEM_ERROR;
}
if (response.command_id != SPI_MLME_SET_CONFIRM)
return MAC_SYSTEM_ERROR;
return response.pdata.status;
}
static u8 hwme_set_request_sync(
u8 hw_attribute,
u8 hw_attribute_length,
u8 *hw_attribute_value,
void *device_ref
)
{
struct mac_message command, response;
command.command_id = SPI_HWME_SET_REQUEST;
command.length = 2 + hw_attribute_length;
command.pdata.hwme_set_req.hw_attribute = hw_attribute;
command.pdata.hwme_set_req.hw_attribute_length = hw_attribute_length;
memcpy(
command.pdata.hwme_set_req.hw_attribute_value,
hw_attribute_value,
hw_attribute_length
);
if (cascoda_api_downstream(
&command.command_id,
command.length + 2,
&response.command_id,
device_ref)) {
return MAC_SYSTEM_ERROR;
}
if (response.command_id != SPI_HWME_SET_CONFIRM)
return MAC_SYSTEM_ERROR;
return response.pdata.hwme_set_cnf.status;
}
static u8 hwme_get_request_sync(
u8 hw_attribute,
u8 *hw_attribute_length,
u8 *hw_attribute_value,
void *device_ref
)
{
struct mac_message command, response;
command.command_id = SPI_HWME_GET_REQUEST;
command.length = 1;
command.pdata.hwme_get_req.hw_attribute = hw_attribute;
if (cascoda_api_downstream(
&command.command_id,
command.length + 2,
&response.command_id,
device_ref)) {
return MAC_SYSTEM_ERROR;
}
if (response.command_id != SPI_HWME_GET_CONFIRM)
return MAC_SYSTEM_ERROR;
if (response.pdata.hwme_get_cnf.status == MAC_SUCCESS) {
*hw_attribute_length =
response.pdata.hwme_get_cnf.hw_attribute_length;
memcpy(
hw_attribute_value,
response.pdata.hwme_get_cnf.hw_attribute_value,
*hw_attribute_length
);
}
return response.pdata.hwme_get_cnf.status;
}
static int ca8210_async_xmit_complete(
struct ieee802154_hw *hw,
u8 msduhandle,
u8 status)
{
struct ca8210_priv *priv = hw->priv;
if (priv->nextmsduhandle != msduhandle) {
dev_err(
&priv->spi->dev,
"Unexpected msdu_handle on data confirm, Expected %d, got %d\n",
priv->nextmsduhandle,
msduhandle
);
return -EIO;
}
priv->async_tx_pending = false;
priv->nextmsduhandle++;
if (status) {
dev_err(
&priv->spi->dev,
"Link transmission unsuccessful, status = %d\n",
status
);
if (status != MAC_TRANSACTION_OVERFLOW) {
ieee802154_wake_queue(priv->hw);
return 0;
}
}
ieee802154_xmit_complete(priv->hw, priv->tx_skb, true);
return 0;
}
static int ca8210_skb_rx(
struct ieee802154_hw *hw,
size_t len,
u8 *data_ind
)
{
struct ieee802154_hdr hdr;
int msdulen;
int hlen;
u8 mpdulinkquality = data_ind[23];
struct sk_buff *skb;
struct ca8210_priv *priv = hw->priv;
skb = dev_alloc_skb(IEEE802154_MTU + sizeof(hdr));
if (!skb) {
dev_crit(&priv->spi->dev, "dev_alloc_skb failed\n");
return -ENOMEM;
}
skb_reserve(skb, sizeof(hdr));
msdulen = data_ind[22];
if (msdulen > IEEE802154_MTU) {
dev_err(
&priv->spi->dev,
"received erroneously large msdu length!\n"
);
kfree_skb(skb);
return -EMSGSIZE;
}
dev_dbg(&priv->spi->dev, "skb buffer length = %d\n", msdulen);
if (priv->promiscuous)
goto copy_payload;
hdr.sec.level = data_ind[29 + msdulen];
dev_dbg(&priv->spi->dev, "security level: %#03x\n", hdr.sec.level);
if (hdr.sec.level > 0) {
hdr.sec.key_id_mode = data_ind[30 + msdulen];
memcpy(&hdr.sec.extended_src, &data_ind[31 + msdulen], 8);
hdr.sec.key_id = data_ind[39 + msdulen];
}
hdr.source.mode = data_ind[0];
dev_dbg(&priv->spi->dev, "srcAddrMode: %#03x\n", hdr.source.mode);
hdr.source.pan_id = *(u16 *)&data_ind[1];
dev_dbg(&priv->spi->dev, "srcPanId: %#06x\n", hdr.source.pan_id);
memcpy(&hdr.source.extended_addr, &data_ind[3], 8);
hdr.dest.mode = data_ind[11];
dev_dbg(&priv->spi->dev, "dstAddrMode: %#03x\n", hdr.dest.mode);
hdr.dest.pan_id = *(u16 *)&data_ind[12];
dev_dbg(&priv->spi->dev, "dstPanId: %#06x\n", hdr.dest.pan_id);
memcpy(&hdr.dest.extended_addr, &data_ind[14], 8);
hdr.fc.type = 1;
if (hdr.sec.level)
hdr.fc.security_enabled = 1;
else
hdr.fc.security_enabled = 0;
if (data_ind[1] != data_ind[12] || data_ind[2] != data_ind[13])
hdr.fc.intra_pan = 1;
else
hdr.fc.intra_pan = 0;
hdr.fc.dest_addr_mode = hdr.dest.mode;
hdr.fc.source_addr_mode = hdr.source.mode;
hlen = ieee802154_hdr_push(skb, &hdr);
if (hlen < 0) {
dev_crit(&priv->spi->dev, "failed to push mac hdr onto skb!\n");
kfree_skb(skb);
return hlen;
}
skb_reset_mac_header(skb);
skb->mac_len = hlen;
copy_payload:
memcpy(skb_put(skb, msdulen), &data_ind[29], msdulen);
ieee802154_rx_irqsafe(hw, skb, mpdulinkquality);
return 0;
}
static int ca8210_net_rx(struct ieee802154_hw *hw, u8 *command, size_t len)
{
struct ca8210_priv *priv = hw->priv;
unsigned long flags;
u8 status;
dev_dbg(&priv->spi->dev, "ca8210_net_rx(), CmdID = %d\n", command[0]);
if (command[0] == SPI_MCPS_DATA_INDICATION) {
spin_lock_irqsave(&priv->lock, flags);
if (command[26] == priv->last_dsn) {
dev_dbg(
&priv->spi->dev,
"DSN %d resend received, ignoring...\n",
command[26]
);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
priv->last_dsn = command[26];
spin_unlock_irqrestore(&priv->lock, flags);
return ca8210_skb_rx(hw, len - 2, command + 2);
} else if (command[0] == SPI_MCPS_DATA_CONFIRM) {
status = command[3];
if (priv->async_tx_pending) {
return ca8210_async_xmit_complete(
hw,
command[2],
status
);
}
}
return 0;
}
static int ca8210_skb_tx(
struct sk_buff *skb,
u8 msduhandle,
struct ca8210_priv *priv
)
{
int status;
struct ieee802154_hdr header = { 0 };
struct secspec secspec;
unsigned int mac_len;
dev_dbg(&priv->spi->dev, "ca8210_skb_tx() called\n");
mac_len = ieee802154_hdr_peek_addrs(skb, &header);
secspec.security_level = header.sec.level;
secspec.key_id_mode = header.sec.key_id_mode;
if (secspec.key_id_mode == 2)
memcpy(secspec.key_source, &header.sec.short_src, 4);
else if (secspec.key_id_mode == 3)
memcpy(secspec.key_source, &header.sec.extended_src, 8);
secspec.key_index = header.sec.key_id;
status = mcps_data_request(
header.source.mode,
header.dest.mode,
header.dest.pan_id,
(union macaddr *)&header.dest.extended_addr,
skb->len - mac_len,
&skb->data[mac_len],
msduhandle,
header.fc.ack_request,
&secspec,
priv->spi
);
return link_to_linux_err(status);
}
static int ca8210_start(struct ieee802154_hw *hw)
{
int status;
u8 rx_on_when_idle;
u8 lqi_threshold = 0;
struct ca8210_priv *priv = hw->priv;
priv->last_dsn = -1;
rx_on_when_idle = 1;
status = mlme_set_request_sync(
MAC_RX_ON_WHEN_IDLE,
0,
1,
&rx_on_when_idle,
priv->spi
);
if (status) {
dev_crit(
&priv->spi->dev,
"Setting rx_on_when_idle failed, status = %d\n",
status
);
return link_to_linux_err(status);
}
status = hwme_set_request_sync(
HWME_LQILIMIT,
1,
&lqi_threshold,
priv->spi
);
if (status) {
dev_crit(
&priv->spi->dev,
"Setting lqilimit failed, status = %d\n",
status
);
return link_to_linux_err(status);
}
return 0;
}
static void ca8210_stop(struct ieee802154_hw *hw)
{
}
static int ca8210_xmit_async(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct ca8210_priv *priv = hw->priv;
int status;
dev_dbg(&priv->spi->dev, "calling ca8210_xmit_async()\n");
priv->tx_skb = skb;
priv->async_tx_pending = true;
status = ca8210_skb_tx(skb, priv->nextmsduhandle, priv);
return status;
}
static int ca8210_get_ed(struct ieee802154_hw *hw, u8 *level)
{
u8 lenvar;
struct ca8210_priv *priv = hw->priv;
return link_to_linux_err(
hwme_get_request_sync(HWME_EDVALUE, &lenvar, level, priv->spi)
);
}
static int ca8210_set_channel(
struct ieee802154_hw *hw,
u8 page,
u8 channel
)
{
u8 status;
struct ca8210_priv *priv = hw->priv;
status = mlme_set_request_sync(
PHY_CURRENT_CHANNEL,
0,
1,
&channel,
priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting channel, MLME-SET.confirm status = %d\n",
status
);
}
return link_to_linux_err(status);
}
static int ca8210_set_hw_addr_filt(
struct ieee802154_hw *hw,
struct ieee802154_hw_addr_filt *filt,
unsigned long changed
)
{
u8 status = 0;
struct ca8210_priv *priv = hw->priv;
if (changed & IEEE802154_AFILT_PANID_CHANGED) {
status = mlme_set_request_sync(
MAC_PAN_ID,
0,
2,
&filt->pan_id, priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting pan id, MLME-SET.confirm status = %d",
status
);
return link_to_linux_err(status);
}
}
if (changed & IEEE802154_AFILT_SADDR_CHANGED) {
status = mlme_set_request_sync(
MAC_SHORT_ADDRESS,
0,
2,
&filt->short_addr, priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting short address, MLME-SET.confirm status = %d",
status
);
return link_to_linux_err(status);
}
}
if (changed & IEEE802154_AFILT_IEEEADDR_CHANGED) {
status = mlme_set_request_sync(
NS_IEEE_ADDRESS,
0,
8,
&filt->ieee_addr,
priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting ieee address, MLME-SET.confirm status = %d",
status
);
return link_to_linux_err(status);
}
}
return 0;
}
static int ca8210_set_tx_power(struct ieee802154_hw *hw, s32 mbm)
{
struct ca8210_priv *priv = hw->priv;
mbm /= 100;
return link_to_linux_err(
mlme_set_request_sync(PHY_TRANSMIT_POWER, 0, 1, &mbm, priv->spi)
);
}
static int ca8210_set_cca_mode(
struct ieee802154_hw *hw,
const struct wpan_phy_cca *cca
)
{
u8 status;
u8 cca_mode;
struct ca8210_priv *priv = hw->priv;
cca_mode = cca->mode & 3;
if (cca_mode == 3 && cca->opt == NL802154_CCA_OPT_ENERGY_CARRIER_OR) {
cca_mode = 0;
}
status = mlme_set_request_sync(
PHY_CCA_MODE,
0,
1,
&cca_mode,
priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting cca mode, MLME-SET.confirm status = %d",
status
);
}
return link_to_linux_err(status);
}
static int ca8210_set_cca_ed_level(struct ieee802154_hw *hw, s32 level)
{
u8 status;
u8 ed_threshold = (level / 100) * 2 + 256;
struct ca8210_priv *priv = hw->priv;
status = hwme_set_request_sync(
HWME_EDTHRESHOLD,
1,
&ed_threshold,
priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting ed threshold, HWME-SET.confirm status = %d",
status
);
}
return link_to_linux_err(status);
}
static int ca8210_set_csma_params(
struct ieee802154_hw *hw,
u8 min_be,
u8 max_be,
u8 retries
)
{
u8 status;
struct ca8210_priv *priv = hw->priv;
status = mlme_set_request_sync(MAC_MIN_BE, 0, 1, &min_be, priv->spi);
if (status) {
dev_err(
&priv->spi->dev,
"error setting min be, MLME-SET.confirm status = %d",
status
);
return link_to_linux_err(status);
}
status = mlme_set_request_sync(MAC_MAX_BE, 0, 1, &max_be, priv->spi);
if (status) {
dev_err(
&priv->spi->dev,
"error setting max be, MLME-SET.confirm status = %d",
status
);
return link_to_linux_err(status);
}
status = mlme_set_request_sync(
MAC_MAX_CSMA_BACKOFFS,
0,
1,
&retries,
priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting max csma backoffs, MLME-SET.confirm status = %d",
status
);
}
return link_to_linux_err(status);
}
static int ca8210_set_frame_retries(struct ieee802154_hw *hw, s8 retries)
{
u8 status;
struct ca8210_priv *priv = hw->priv;
status = mlme_set_request_sync(
MAC_MAX_FRAME_RETRIES,
0,
1,
&retries,
priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting frame retries, MLME-SET.confirm status = %d",
status
);
}
return link_to_linux_err(status);
}
static int ca8210_set_promiscuous_mode(struct ieee802154_hw *hw, const bool on)
{
u8 status;
struct ca8210_priv *priv = hw->priv;
status = mlme_set_request_sync(
MAC_PROMISCUOUS_MODE,
0,
1,
(const void*)&on,
priv->spi
);
if (status) {
dev_err(
&priv->spi->dev,
"error setting promiscuous mode, MLME-SET.confirm status = %d",
status
);
} else {
priv->promiscuous = on;
}
return link_to_linux_err(status);
}
static int ca8210_test_int_open(struct inode *inodp, struct file *filp)
{
struct ca8210_priv *priv = inodp->i_private;
filp->private_data = priv;
return 0;
}
static int ca8210_test_check_upstream(u8 *buf, void *device_ref)
{
int ret;
u8 response[CA8210_SPI_BUF_SIZE];
if (buf[0] == SPI_MLME_SET_REQUEST) {
ret = tdme_checkpibattribute(buf[2], buf[4], buf + 5);
if (ret) {
response[0] = SPI_MLME_SET_CONFIRM;
response[1] = 3;
response[2] = MAC_INVALID_PARAMETER;
response[3] = buf[2];
response[4] = buf[3];
if (cascoda_api_upstream)
cascoda_api_upstream(response, 5, device_ref);
return ret;
}
}
if (buf[0] == SPI_MLME_ASSOCIATE_REQUEST) {
return tdme_channelinit(buf[2], device_ref);
} else if (buf[0] == SPI_MLME_START_REQUEST) {
return tdme_channelinit(buf[4], device_ref);
} else if (
(buf[0] == SPI_MLME_SET_REQUEST) &&
(buf[2] == PHY_CURRENT_CHANNEL)
) {
return tdme_channelinit(buf[5], device_ref);
} else if (
(buf[0] == SPI_TDME_SET_REQUEST) &&
(buf[2] == TDME_CHANNEL)
) {
return tdme_channelinit(buf[4], device_ref);
} else if (
(CA8210_MAC_WORKAROUNDS) &&
(buf[0] == SPI_MLME_RESET_REQUEST) &&
(buf[2] == 1)
) {
return tdme_setsfr_request_sync(
0,
CA8210_SFR_MACCON,
0,
device_ref
);
}
return 0;
}
static ssize_t ca8210_test_int_user_write(
struct file *filp,
const char __user *in_buf,
size_t len,
loff_t *off
)
{
int ret;
struct ca8210_priv *priv = filp->private_data;
u8 command[CA8210_SPI_BUF_SIZE];
if (len > CA8210_SPI_BUF_SIZE) {
dev_warn(
&priv->spi->dev,
"userspace requested erroneously long write (%zu)\n",
len
);
return -EMSGSIZE;
}
ret = copy_from_user(command, in_buf, len);
if (ret) {
dev_err(
&priv->spi->dev,
"%d bytes could not be copied from userspace\n",
ret
);
return -EIO;
}
ret = ca8210_test_check_upstream(command, priv->spi);
if (ret == 0) {
ret = ca8210_spi_exchange(
command,
command[1] + 2,
NULL,
priv->spi
);
if (ret < 0) {
dev_err(
&priv->spi->dev,
"spi exchange failed\n"
);
return ret;
}
if (command[0] & SPI_SYN)
priv->sync_down++;
}
return len;
}
static ssize_t ca8210_test_int_user_read(
struct file *filp,
char __user *buf,
size_t len,
loff_t *offp
)
{
int i, cmdlen;
struct ca8210_priv *priv = filp->private_data;
unsigned char *fifo_buffer;
unsigned long bytes_not_copied;
if (filp->f_flags & O_NONBLOCK) {
if (kfifo_is_empty(&priv->test.up_fifo))
return 0;
} else {
wait_event_interruptible(
priv->test.readq,
!kfifo_is_empty(&priv->test.up_fifo)
);
}
if (kfifo_out(&priv->test.up_fifo, &fifo_buffer, 4) != 4) {
dev_err(
&priv->spi->dev,
"test_interface: Wrong number of elements popped from upstream fifo\n"
);
return 0;
}
cmdlen = fifo_buffer[1];
bytes_not_copied = cmdlen + 2;
bytes_not_copied = copy_to_user(buf, fifo_buffer, bytes_not_copied);
if (bytes_not_copied > 0) {
dev_err(
&priv->spi->dev,
"%lu bytes could not be copied to user space!\n",
bytes_not_copied
);
}
dev_dbg(&priv->spi->dev, "test_interface: Cmd len = %d\n", cmdlen);
dev_dbg(&priv->spi->dev, "test_interface: Read\n");
for (i = 0; i < cmdlen + 2; i++)
dev_dbg(&priv->spi->dev, "%#03x\n", fifo_buffer[i]);
kfree(fifo_buffer);
return cmdlen + 2;
}
static long ca8210_test_int_ioctl(
struct file *filp,
unsigned int ioctl_num,
unsigned long ioctl_param
)
{
struct ca8210_priv *priv = filp->private_data;
switch (ioctl_num) {
case CA8210_IOCTL_HARD_RESET:
ca8210_reset_send(priv->spi, ioctl_param);
break;
default:
break;
}
return 0;
}
static unsigned int ca8210_test_int_poll(
struct file *filp,
struct poll_table_struct *ptable
)
{
unsigned int return_flags = 0;
struct ca8210_priv *priv = filp->private_data;
poll_wait(filp, &priv->test.readq, ptable);
if (!kfifo_is_empty(&priv->test.up_fifo))
return_flags |= (POLLIN | POLLRDNORM);
if (wait_event_interruptible(
priv->test.readq,
!kfifo_is_empty(&priv->test.up_fifo))) {
return POLLERR;
}
return return_flags;
}
static int ca8210_get_platform_data(
struct spi_device *spi_device,
struct ca8210_platform_data *pdata
)
{
int ret = 0;
if (!spi_device->dev.of_node)
return -EINVAL;
pdata->extclockenable = of_property_read_bool(
spi_device->dev.of_node,
"extclock-enable"
);
if (pdata->extclockenable) {
ret = of_property_read_u32(
spi_device->dev.of_node,
"extclock-freq",
&pdata->extclockfreq
);
if (ret < 0)
return ret;
ret = of_property_read_u32(
spi_device->dev.of_node,
"extclock-gpio",
&pdata->extclockgpio
);
}
return ret;
}
static int ca8210_config_extern_clk(
struct ca8210_platform_data *pdata,
struct spi_device *spi,
bool on
)
{
u8 clkparam[2];
if (on) {
dev_info(&spi->dev, "Switching external clock on\n");
switch (pdata->extclockfreq) {
case SIXTEEN_MHZ:
clkparam[0] = 1;
break;
case EIGHT_MHZ:
clkparam[0] = 2;
break;
case FOUR_MHZ:
clkparam[0] = 3;
break;
case TWO_MHZ:
clkparam[0] = 4;
break;
case ONE_MHZ:
clkparam[0] = 5;
break;
default:
dev_crit(&spi->dev, "Invalid extclock-freq\n");
return -EINVAL;
}
clkparam[1] = pdata->extclockgpio;
} else {
dev_info(&spi->dev, "Switching external clock off\n");
clkparam[0] = 0;
clkparam[1] = 0;
}
return link_to_linux_err(
hwme_set_request_sync(HWME_SYSCLKOUT, 2, clkparam, spi)
);
}
static int ca8210_register_ext_clock(struct spi_device *spi)
{
struct device_node *np = spi->dev.of_node;
struct ca8210_priv *priv = spi_get_drvdata(spi);
struct ca8210_platform_data *pdata = spi->dev.platform_data;
int ret = 0;
if (!np)
return -EFAULT;
priv->clk = clk_register_fixed_rate(
&spi->dev,
np->name,
NULL,
0,
pdata->extclockfreq
);
if (IS_ERR(priv->clk)) {
dev_crit(&spi->dev, "Failed to register external clk\n");
return PTR_ERR(priv->clk);
}
ret = of_clk_add_provider(np, of_clk_src_simple_get, priv->clk);
if (ret) {
clk_unregister(priv->clk);
dev_crit(
&spi->dev,
"Failed to register external clock as clock provider\n"
);
} else {
dev_info(&spi->dev, "External clock set as clock provider\n");
}
return ret;
}
static void ca8210_unregister_ext_clock(struct spi_device *spi)
{
struct ca8210_priv *priv = spi_get_drvdata(spi);
if (!priv->clk)
return
of_clk_del_provider(spi->dev.of_node);
clk_unregister(priv->clk);
dev_info(&spi->dev, "External clock unregistered\n");
}
static int ca8210_reset_init(struct spi_device *spi)
{
int ret;
struct ca8210_platform_data *pdata = spi->dev.platform_data;
pdata->gpio_reset = of_get_named_gpio(
spi->dev.of_node,
"reset-gpio",
0
);
ret = gpio_direction_output(pdata->gpio_reset, 1);
if (ret < 0) {
dev_crit(
&spi->dev,
"Reset GPIO %d did not set to output mode\n",
pdata->gpio_reset
);
}
return ret;
}
static int ca8210_interrupt_init(struct spi_device *spi)
{
int ret;
struct ca8210_platform_data *pdata = spi->dev.platform_data;
pdata->gpio_irq = of_get_named_gpio(
spi->dev.of_node,
"irq-gpio",
0
);
pdata->irq_id = gpio_to_irq(pdata->gpio_irq);
if (pdata->irq_id < 0) {
dev_crit(
&spi->dev,
"Could not get irq for gpio pin %d\n",
pdata->gpio_irq
);
gpio_free(pdata->gpio_irq);
return pdata->irq_id;
}
ret = request_irq(
pdata->irq_id,
ca8210_interrupt_handler,
IRQF_TRIGGER_FALLING,
"ca8210-irq",
spi_get_drvdata(spi)
);
if (ret) {
dev_crit(&spi->dev, "request_irq %d failed\n", pdata->irq_id);
gpio_unexport(pdata->gpio_irq);
gpio_free(pdata->gpio_irq);
}
return ret;
}
static int ca8210_dev_com_init(struct ca8210_priv *priv)
{
priv->mlme_workqueue = alloc_ordered_workqueue(
"MLME work queue",
WQ_UNBOUND
);
if (!priv->mlme_workqueue) {
dev_crit(&priv->spi->dev, "alloc of mlme_workqueue failed!\n");
return -ENOMEM;
}
priv->irq_workqueue = alloc_ordered_workqueue(
"ca8210 irq worker",
WQ_UNBOUND
);
if (!priv->irq_workqueue) {
dev_crit(&priv->spi->dev, "alloc of irq_workqueue failed!\n");
return -ENOMEM;
}
return 0;
}
static void ca8210_dev_com_clear(struct ca8210_priv *priv)
{
flush_workqueue(priv->mlme_workqueue);
destroy_workqueue(priv->mlme_workqueue);
flush_workqueue(priv->irq_workqueue);
destroy_workqueue(priv->irq_workqueue);
}
static void ca8210_hw_setup(struct ieee802154_hw *ca8210_hw)
{
ca8210_hw->phy->supported.channels[0] = CA8210_VALID_CHANNELS;
ca8210_hw->phy->supported.tx_powers_size = CA8210_MAX_TX_POWERS;
ca8210_hw->phy->supported.tx_powers = ca8210_tx_powers;
ca8210_hw->phy->supported.cca_ed_levels_size = CA8210_MAX_ED_LEVELS;
ca8210_hw->phy->supported.cca_ed_levels = ca8210_ed_levels;
ca8210_hw->phy->current_channel = 18;
ca8210_hw->phy->current_page = 0;
ca8210_hw->phy->transmit_power = 800;
ca8210_hw->phy->cca.mode = NL802154_CCA_ENERGY_CARRIER;
ca8210_hw->phy->cca.opt = NL802154_CCA_OPT_ENERGY_CARRIER_AND;
ca8210_hw->phy->cca_ed_level = -9800;
ca8210_hw->phy->symbol_duration = 16;
ca8210_hw->phy->lifs_period = 40;
ca8210_hw->phy->sifs_period = 12;
ca8210_hw->flags =
IEEE802154_HW_AFILT |
IEEE802154_HW_OMIT_CKSUM |
IEEE802154_HW_FRAME_RETRIES |
IEEE802154_HW_PROMISCUOUS |
IEEE802154_HW_CSMA_PARAMS;
ca8210_hw->phy->flags =
WPAN_PHY_FLAG_TXPOWER |
WPAN_PHY_FLAG_CCA_ED_LEVEL |
WPAN_PHY_FLAG_CCA_MODE;
}
static int ca8210_test_interface_init(struct ca8210_priv *priv)
{
struct ca8210_test *test = &priv->test;
char node_name[32];
snprintf(
node_name,
sizeof(node_name),
"ca8210@%d_%d",
priv->spi->master->bus_num,
priv->spi->chip_select
);
test->ca8210_dfs_spi_int = debugfs_create_file(
node_name,
0600,
NULL,
priv,
&test_int_fops
);
if (IS_ERR(test->ca8210_dfs_spi_int)) {
dev_err(
&priv->spi->dev,
"Error %ld when creating debugfs node\n",
PTR_ERR(test->ca8210_dfs_spi_int)
);
return PTR_ERR(test->ca8210_dfs_spi_int);
}
debugfs_create_symlink("ca8210", NULL, node_name);
init_waitqueue_head(&test->readq);
return kfifo_alloc(
&test->up_fifo,
CA8210_TEST_INT_FIFO_SIZE,
GFP_KERNEL
);
}
static void ca8210_test_interface_clear(struct ca8210_priv *priv)
{
struct ca8210_test *test = &priv->test;
if (!IS_ERR(test->ca8210_dfs_spi_int))
debugfs_remove(test->ca8210_dfs_spi_int);
kfifo_free(&test->up_fifo);
dev_info(&priv->spi->dev, "Test interface removed\n");
}
static int ca8210_remove(struct spi_device *spi_device)
{
struct ca8210_priv *priv;
struct ca8210_platform_data *pdata;
dev_info(&spi_device->dev, "Removing ca8210\n");
pdata = spi_device->dev.platform_data;
if (pdata) {
if (pdata->extclockenable) {
ca8210_unregister_ext_clock(spi_device);
ca8210_config_extern_clk(pdata, spi_device, 0);
}
free_irq(pdata->irq_id, spi_device->dev.driver_data);
kfree(pdata);
spi_device->dev.platform_data = NULL;
}
priv = spi_get_drvdata(spi_device);
if (priv) {
dev_info(
&spi_device->dev,
"sync_down = %d, sync_up = %d\n",
priv->sync_down,
priv->sync_up
);
ca8210_dev_com_clear(spi_device->dev.driver_data);
if (priv->hw) {
if (priv->hw_registered)
ieee802154_unregister_hw(priv->hw);
ieee802154_free_hw(priv->hw);
priv->hw = NULL;
dev_info(
&spi_device->dev,
"Unregistered & freed ieee802154_hw.\n"
);
}
if (IS_ENABLED(CONFIG_IEEE802154_CA8210_DEBUGFS))
ca8210_test_interface_clear(priv);
}
return 0;
}
static int ca8210_probe(struct spi_device *spi_device)
{
struct ca8210_priv *priv;
struct ieee802154_hw *hw;
struct ca8210_platform_data *pdata;
int ret;
dev_info(&spi_device->dev, "Inserting ca8210\n");
hw = ieee802154_alloc_hw(sizeof(struct ca8210_priv), &ca8210_phy_ops);
if (!hw) {
dev_crit(&spi_device->dev, "ieee802154_alloc_hw failed\n");
ret = -ENOMEM;
goto error;
}
priv = hw->priv;
priv->hw = hw;
priv->spi = spi_device;
hw->parent = &spi_device->dev;
spin_lock_init(&priv->lock);
priv->async_tx_pending = false;
priv->hw_registered = false;
priv->sync_up = 0;
priv->sync_down = 0;
priv->promiscuous = false;
priv->retries = 0;
init_completion(&priv->ca8210_is_awake);
init_completion(&priv->spi_transfer_complete);
init_completion(&priv->sync_exchange_complete);
spi_set_drvdata(priv->spi, priv);
if (IS_ENABLED(CONFIG_IEEE802154_CA8210_DEBUGFS)) {
cascoda_api_upstream = ca8210_test_int_driver_write;
ca8210_test_interface_init(priv);
} else {
cascoda_api_upstream = NULL;
}
ca8210_hw_setup(hw);
ieee802154_random_extended_addr(&hw->phy->perm_extended_addr);
pdata = kmalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_crit(
&spi_device->dev,
"Could not allocate platform data\n"
);
ret = -ENOMEM;
goto error;
}
ret = ca8210_get_platform_data(priv->spi, pdata);
if (ret) {
dev_crit(&spi_device->dev, "ca8210_get_platform_data failed\n");
goto error;
}
priv->spi->dev.platform_data = pdata;
ret = ca8210_dev_com_init(priv);
if (ret) {
dev_crit(&spi_device->dev, "ca8210_dev_com_init failed\n");
goto error;
}
ret = ca8210_reset_init(priv->spi);
if (ret) {
dev_crit(&spi_device->dev, "ca8210_reset_init failed\n");
goto error;
}
ret = ca8210_interrupt_init(priv->spi);
if (ret) {
dev_crit(&spi_device->dev, "ca8210_interrupt_init failed\n");
goto error;
}
msleep(100);
ca8210_reset_send(priv->spi, 1);
ret = tdme_chipinit(priv->spi);
if (ret) {
dev_crit(&spi_device->dev, "tdme_chipinit failed\n");
goto error;
}
if (pdata->extclockenable) {
ret = ca8210_config_extern_clk(pdata, priv->spi, 1);
if (ret) {
dev_crit(
&spi_device->dev,
"ca8210_config_extern_clk failed\n"
);
goto error;
}
ret = ca8210_register_ext_clock(priv->spi);
if (ret) {
dev_crit(
&spi_device->dev,
"ca8210_register_ext_clock failed\n"
);
goto error;
}
}
ret = ieee802154_register_hw(hw);
if (ret) {
dev_crit(&spi_device->dev, "ieee802154_register_hw failed\n");
goto error;
}
priv->hw_registered = true;
return 0;
error:
msleep(100);
ca8210_remove(spi_device);
return link_to_linux_err(ret);
}
