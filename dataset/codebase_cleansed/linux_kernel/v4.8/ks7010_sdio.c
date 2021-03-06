static int ks7010_sdio_read(struct ks_wlan_private *priv, unsigned int address,
unsigned char *buffer, int length)
{
struct ks_sdio_card *card;
int rc;
card = priv->ks_wlan_hw.sdio_card;
if (length == 1)
*buffer = sdio_readb(card->func, address, &rc);
else
rc = sdio_memcpy_fromio(card->func, buffer, address, length);
if (rc != 0)
DPRINTK(1, "sdio error=%d size=%d\n", rc, length);
return rc;
}
static int ks7010_sdio_write(struct ks_wlan_private *priv, unsigned int address,
unsigned char *buffer, int length)
{
struct ks_sdio_card *card;
int rc;
card = priv->ks_wlan_hw.sdio_card;
if (length == 1)
sdio_writeb(card->func, *buffer, (unsigned int)address, &rc);
else
rc = sdio_memcpy_toio(card->func, (unsigned int)address, buffer,
length);
if (rc != 0)
DPRINTK(1, "sdio error=%d size=%d\n", rc, length);
return rc;
}
void ks_wlan_hw_sleep_doze_request(struct ks_wlan_private *priv)
{
unsigned char rw_data;
int retval;
DPRINTK(4, "\n");
atomic_set(&priv->sleepstatus.doze_request, 0);
if (atomic_read(&priv->sleepstatus.status) == 0) {
rw_data = GCR_B_DOZE;
retval =
ks7010_sdio_write(priv, GCR_B, &rw_data, sizeof(rw_data));
if (retval) {
DPRINTK(1, " error : GCR_B=%02X\n", rw_data);
goto out;
}
DPRINTK(4, "PMG SET!! : GCR_B=%02X\n", rw_data);
DPRINTK(3, "sleep_mode=SLP_SLEEP\n");
atomic_set(&priv->sleepstatus.status, 1);
priv->last_doze = jiffies;
} else {
DPRINTK(1, "sleep_mode=%d\n", priv->sleep_mode);
}
out:
priv->sleep_mode = atomic_read(&priv->sleepstatus.status);
return;
}
void ks_wlan_hw_sleep_wakeup_request(struct ks_wlan_private *priv)
{
unsigned char rw_data;
int retval;
DPRINTK(4, "\n");
atomic_set(&priv->sleepstatus.wakeup_request, 0);
if (atomic_read(&priv->sleepstatus.status) == 1) {
rw_data = WAKEUP_REQ;
retval =
ks7010_sdio_write(priv, WAKEUP, &rw_data, sizeof(rw_data));
if (retval) {
DPRINTK(1, " error : WAKEUP=%02X\n", rw_data);
goto out;
}
DPRINTK(4, "wake up : WAKEUP=%02X\n", rw_data);
atomic_set(&priv->sleepstatus.status, 0);
priv->last_wakeup = jiffies;
++priv->wakeup_count;
} else {
DPRINTK(1, "sleep_mode=%d\n", priv->sleep_mode);
}
out:
priv->sleep_mode = atomic_read(&priv->sleepstatus.status);
return;
}
void ks_wlan_hw_wakeup_request(struct ks_wlan_private *priv)
{
unsigned char rw_data;
int retval;
DPRINTK(4, "\n");
if (atomic_read(&priv->psstatus.status) == PS_SNOOZE) {
rw_data = WAKEUP_REQ;
retval =
ks7010_sdio_write(priv, WAKEUP, &rw_data, sizeof(rw_data));
if (retval) {
DPRINTK(1, " error : WAKEUP=%02X\n", rw_data);
}
DPRINTK(4, "wake up : WAKEUP=%02X\n", rw_data);
priv->last_wakeup = jiffies;
++priv->wakeup_count;
} else {
DPRINTK(1, "psstatus=%d\n",
atomic_read(&priv->psstatus.status));
}
}
int _ks_wlan_hw_power_save(struct ks_wlan_private *priv)
{
int rc = 0;
unsigned char rw_data;
int retval;
if (priv->reg.powermgt == POWMGT_ACTIVE_MODE)
return rc;
if (priv->reg.operation_mode == MODE_INFRASTRUCTURE &&
(priv->connect_status & CONNECT_STATUS_MASK) == CONNECT_STATUS) {
if (priv->dev_state == DEVICE_STATE_SLEEP) {
switch (atomic_read(&priv->psstatus.status)) {
case PS_SNOOZE:
break;
default:
DPRINTK(5, "\npsstatus.status=%d\npsstatus.confirm_wait=%d\npsstatus.snooze_guard=%d\ncnt_txqbody=%d\n",
atomic_read(&priv->psstatus.status),
atomic_read(&priv->psstatus.confirm_wait),
atomic_read(&priv->psstatus.snooze_guard),
cnt_txqbody(priv));
if (!atomic_read(&priv->psstatus.confirm_wait)
&& !atomic_read(&priv->psstatus.snooze_guard)
&& !cnt_txqbody(priv)) {
retval =
ks7010_sdio_read(priv, INT_PENDING,
&rw_data,
sizeof(rw_data));
if (retval) {
DPRINTK(1,
" error : INT_PENDING=%02X\n",
rw_data);
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 1);
break;
}
if (!rw_data) {
rw_data = GCR_B_DOZE;
retval =
ks7010_sdio_write(priv,
GCR_B,
&rw_data,
sizeof(rw_data));
if (retval) {
DPRINTK(1,
" error : GCR_B=%02X\n",
rw_data);
queue_delayed_work
(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 1);
break;
}
DPRINTK(4,
"PMG SET!! : GCR_B=%02X\n",
rw_data);
atomic_set(&priv->psstatus.
status, PS_SNOOZE);
DPRINTK(3,
"psstatus.status=PS_SNOOZE\n");
} else {
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 1);
}
} else {
queue_delayed_work(priv->ks_wlan_hw.
ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq,
0);
}
break;
}
}
}
return rc;
}
int ks_wlan_hw_power_save(struct ks_wlan_private *priv)
{
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 1);
return 0;
}
static int enqueue_txdev(struct ks_wlan_private *priv, unsigned char *p,
unsigned long size,
void (*complete_handler) (void *arg1, void *arg2),
void *arg1, void *arg2)
{
struct tx_device_buffer *sp;
if (priv->dev_state < DEVICE_STATE_BOOT) {
kfree(p);
if (complete_handler != NULL)
(*complete_handler) (arg1, arg2);
return 1;
}
if ((TX_DEVICE_BUFF_SIZE - 1) <= cnt_txqbody(priv)) {
DPRINTK(1, "tx buffer overflow\n");
kfree(p);
if (complete_handler != NULL)
(*complete_handler) (arg1, arg2);
return 1;
}
sp = &priv->tx_dev.tx_dev_buff[priv->tx_dev.qtail];
sp->sendp = p;
sp->size = size;
sp->complete_handler = complete_handler;
sp->arg1 = arg1;
sp->arg2 = arg2;
inc_txqtail(priv);
return 0;
}
static int write_to_device(struct ks_wlan_private *priv, unsigned char *buffer,
unsigned long size)
{
int rc, retval;
unsigned char rw_data;
struct hostif_hdr *hdr;
hdr = (struct hostif_hdr *)buffer;
rc = 0;
DPRINTK(4, "size=%d\n", hdr->size);
if (hdr->event < HIF_DATA_REQ || HIF_REQ_MAX < hdr->event) {
DPRINTK(1, "unknown event=%04X\n", hdr->event);
return 0;
}
retval = ks7010_sdio_write(priv, DATA_WINDOW, buffer, size);
if (retval) {
DPRINTK(1, " write error : retval=%d\n", retval);
return -4;
}
rw_data = WRITE_STATUS_BUSY;
retval =
ks7010_sdio_write(priv, WRITE_STATUS, &rw_data, sizeof(rw_data));
if (retval) {
DPRINTK(1, " error : WRITE_STATUS=%02X\n", rw_data);
return -3;
}
return 0;
}
static void tx_device_task(void *dev)
{
struct ks_wlan_private *priv = (struct ks_wlan_private *)dev;
struct tx_device_buffer *sp;
int rc = 0;
DPRINTK(4, "\n");
if (cnt_txqbody(priv) > 0
&& atomic_read(&priv->psstatus.status) != PS_SNOOZE) {
sp = &priv->tx_dev.tx_dev_buff[priv->tx_dev.qhead];
if (priv->dev_state >= DEVICE_STATE_BOOT) {
rc = write_to_device(priv, sp->sendp, sp->size);
if (rc) {
DPRINTK(1, "write_to_device error !!(%d)\n",
rc);
queue_delayed_work(priv->ks_wlan_hw.
ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 1);
return;
}
}
kfree(sp->sendp);
if (sp->complete_handler != NULL)
(*sp->complete_handler) (sp->arg1, sp->arg2);
inc_txqhead(priv);
if (cnt_txqbody(priv) > 0) {
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 0);
}
}
return;
}
int ks_wlan_hw_tx(struct ks_wlan_private *priv, void *p, unsigned long size,
void (*complete_handler) (void *arg1, void *arg2),
void *arg1, void *arg2)
{
int result = 0;
struct hostif_hdr *hdr;
hdr = (struct hostif_hdr *)p;
if (hdr->event < HIF_DATA_REQ || HIF_REQ_MAX < hdr->event) {
DPRINTK(1, "unknown event=%04X\n", hdr->event);
return 0;
}
priv->hostt.buff[priv->hostt.qtail] = hdr->event;
priv->hostt.qtail = (priv->hostt.qtail + 1) % SME_EVENT_BUFF_SIZE;
DPRINTK(4, "event=%04X\n", hdr->event);
spin_lock(&priv->tx_dev.tx_dev_lock);
result = enqueue_txdev(priv, p, size, complete_handler, arg1, arg2);
spin_unlock(&priv->tx_dev.tx_dev_lock);
if (cnt_txqbody(priv) > 0) {
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 0);
}
return result;
}
static void rx_event_task(unsigned long dev)
{
struct ks_wlan_private *priv = (struct ks_wlan_private *)dev;
struct rx_device_buffer *rp;
DPRINTK(4, "\n");
if (cnt_rxqbody(priv) > 0 && priv->dev_state >= DEVICE_STATE_BOOT) {
rp = &priv->rx_dev.rx_dev_buff[priv->rx_dev.qhead];
hostif_receive(priv, rp->data, rp->size);
inc_rxqhead(priv);
if (cnt_rxqbody(priv) > 0) {
tasklet_schedule(&priv->ks_wlan_hw.rx_bh_task);
}
}
return;
}
static void ks_wlan_hw_rx(void *dev, uint16_t size)
{
struct ks_wlan_private *priv = (struct ks_wlan_private *)dev;
int retval;
struct rx_device_buffer *rx_buffer;
struct hostif_hdr *hdr;
unsigned char read_status;
unsigned short event = 0;
DPRINTK(4, "\n");
if (cnt_rxqbody(priv) >= (RX_DEVICE_BUFF_SIZE - 1)) {
DPRINTK(1, "rx buffer overflow \n");
goto error_out;
}
rx_buffer = &priv->rx_dev.rx_dev_buff[priv->rx_dev.qtail];
retval =
ks7010_sdio_read(priv, DATA_WINDOW, &rx_buffer->data[0],
hif_align_size(size));
if (retval) {
goto error_out;
}
if (size > 2046 || size == 0) {
#ifdef KS_WLAN_DEBUG
if (KS_WLAN_DEBUG > 5)
print_hex_dump_bytes("INVALID DATA dump: ",
DUMP_PREFIX_OFFSET,
rx_buffer->data, 32);
#endif
read_status = READ_STATUS_IDLE;
retval =
ks7010_sdio_write(priv, READ_STATUS, &read_status,
sizeof(read_status));
if (retval) {
DPRINTK(1, " error : READ_STATUS=%02X\n", read_status);
}
goto error_out;
}
hdr = (struct hostif_hdr *)&rx_buffer->data[0];
rx_buffer->size = le16_to_cpu(hdr->size) + sizeof(hdr->size);
event = hdr->event;
inc_rxqtail(priv);
read_status = READ_STATUS_IDLE;
retval =
ks7010_sdio_write(priv, READ_STATUS, &read_status,
sizeof(read_status));
if (retval) {
DPRINTK(1, " error : READ_STATUS=%02X\n", read_status);
}
DPRINTK(4, "READ_STATUS=%02X\n", read_status);
if (atomic_read(&priv->psstatus.confirm_wait)) {
if (IS_HIF_CONF(event)) {
DPRINTK(4, "IS_HIF_CONF true !!\n");
atomic_dec(&priv->psstatus.confirm_wait);
}
}
tasklet_schedule(&priv->ks_wlan_hw.rx_bh_task);
error_out:
return;
}
static void ks7010_rw_function(struct work_struct *work)
{
struct hw_info_t *hw;
struct ks_wlan_private *priv;
unsigned char rw_data;
int retval;
hw = container_of(work, struct hw_info_t, rw_wq.work);
priv = container_of(hw, struct ks_wlan_private, ks_wlan_hw);
DPRINTK(4, "\n");
if (time_after(priv->last_doze + ((30 * HZ) / 1000), jiffies)) {
DPRINTK(4, "wait after DOZE \n");
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 1);
return;
}
while (time_after(priv->last_wakeup + ((30 * HZ) / 1000), jiffies)) {
DPRINTK(4, "wait after WAKEUP \n");
printk("wake: %lu %lu\n", priv->last_wakeup + (30 * HZ) / 1000,
jiffies);
msleep(30);
}
sdio_claim_host(priv->ks_wlan_hw.sdio_card->func);
if (atomic_read(&priv->psstatus.status) == PS_SNOOZE) {
if (cnt_txqbody(priv) > 0) {
ks_wlan_hw_wakeup_request(priv);
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 1);
}
goto err_out;
}
if (atomic_read(&priv->sleepstatus.doze_request) == 1) {
ks_wlan_hw_sleep_doze_request(priv);
goto err_out;
}
if (atomic_read(&priv->sleepstatus.wakeup_request) == 1) {
ks_wlan_hw_sleep_wakeup_request(priv);
goto err_out;
}
retval =
ks7010_sdio_read(priv, WSTATUS_RSIZE, &rw_data, sizeof(rw_data));
if (retval) {
DPRINTK(1, " error : WSTATUS_RSIZE=%02X psstatus=%d\n", rw_data,
atomic_read(&priv->psstatus.status));
goto err_out;
}
DPRINTK(4, "WSTATUS_RSIZE=%02X\n", rw_data);
if (rw_data & RSIZE_MASK) {
ks_wlan_hw_rx((void *)priv,
(uint16_t) (((rw_data & RSIZE_MASK) << 4)));
}
if ((rw_data & WSTATUS_MASK)) {
tx_device_task((void *)priv);
}
_ks_wlan_hw_power_save(priv);
err_out:
sdio_release_host(priv->ks_wlan_hw.sdio_card->func);
return;
}
static void ks_sdio_interrupt(struct sdio_func *func)
{
int retval;
struct ks_sdio_card *card;
struct ks_wlan_private *priv;
unsigned char status, rsize, rw_data;
card = sdio_get_drvdata(func);
priv = card->priv;
DPRINTK(4, "\n");
if (priv->dev_state >= DEVICE_STATE_BOOT) {
retval =
ks7010_sdio_read(priv, INT_PENDING, &status,
sizeof(status));
if (retval) {
DPRINTK(1, "read INT_PENDING Failed!!(%d)\n", retval);
goto intr_out;
}
DPRINTK(4, "INT_PENDING=%02X\n", rw_data);
if (status & INT_GCR_B
|| atomic_read(&priv->psstatus.status) == PS_SNOOZE) {
retval =
ks7010_sdio_read(priv, GCR_B, &rw_data,
sizeof(rw_data));
if (retval) {
DPRINTK(1, " error : GCR_B=%02X\n", rw_data);
goto intr_out;
}
if (rw_data == GCR_B_ACTIVE) {
if (atomic_read(&priv->psstatus.status) ==
PS_SNOOZE) {
atomic_set(&priv->psstatus.status,
PS_WAKEUP);
priv->wakeup_count = 0;
}
complete(&priv->psstatus.wakeup_wait);
}
}
do {
retval =
ks7010_sdio_read(priv, WSTATUS_RSIZE, &rw_data,
sizeof(rw_data));
if (retval) {
DPRINTK(1, " error : WSTATUS_RSIZE=%02X\n",
rw_data);
goto intr_out;
}
DPRINTK(4, "WSTATUS_RSIZE=%02X\n", rw_data);
rsize = rw_data & RSIZE_MASK;
if (rsize) {
ks_wlan_hw_rx((void *)priv,
(uint16_t) (((rsize) << 4)));
}
if (rw_data & WSTATUS_MASK) {
#if 0
if (status & INT_WRITE_STATUS
&& !cnt_txqbody(priv)) {
rw_data = 0;
retval =
ks7010_sdio_write(priv, DATA_WINDOW,
&rw_data,
sizeof(rw_data));
if (retval) {
DPRINTK(1,
"write DATA_WINDOW Failed!!(%d)\n",
retval);
}
status &= ~INT_WRITE_STATUS;
} else {
#endif
if (atomic_read(&priv->psstatus.status) == PS_SNOOZE) {
if (cnt_txqbody(priv)) {
ks_wlan_hw_wakeup_request(priv);
queue_delayed_work
(priv->ks_wlan_hw.
ks7010sdio_wq,
&priv->ks_wlan_hw.
rw_wq, 1);
return;
}
} else {
tx_device_task((void *)priv);
}
#if 0
}
#endif
}
} while (rsize);
}
intr_out:
queue_delayed_work(priv->ks_wlan_hw.ks7010sdio_wq,
&priv->ks_wlan_hw.rw_wq, 0);
return;
}
static int trx_device_init(struct ks_wlan_private *priv)
{
priv->tx_dev.qtail = priv->tx_dev.qhead = 0;
priv->rx_dev.qtail = priv->rx_dev.qhead = 0;
spin_lock_init(&priv->tx_dev.tx_dev_lock);
spin_lock_init(&priv->rx_dev.rx_dev_lock);
tasklet_init(&priv->ks_wlan_hw.rx_bh_task, rx_event_task,
(unsigned long)priv);
return 0;
}
static void trx_device_exit(struct ks_wlan_private *priv)
{
struct tx_device_buffer *sp;
while (cnt_txqbody(priv) > 0) {
sp = &priv->tx_dev.tx_dev_buff[priv->tx_dev.qhead];
kfree(sp->sendp);
if (sp->complete_handler != NULL)
(*sp->complete_handler) (sp->arg1, sp->arg2);
inc_txqhead(priv);
}
tasklet_kill(&priv->ks_wlan_hw.rx_bh_task);
return;
}
static int ks7010_sdio_update_index(struct ks_wlan_private *priv, u32 index)
{
int rc = 0;
int retval;
unsigned char *data_buf;
data_buf = NULL;
data_buf = kmalloc(sizeof(u32), GFP_KERNEL);
if (!data_buf) {
rc = 1;
goto error_out;
}
memcpy(data_buf, &index, sizeof(index));
retval = ks7010_sdio_write(priv, WRITE_INDEX, data_buf, sizeof(index));
if (retval) {
rc = 2;
goto error_out;
}
retval = ks7010_sdio_write(priv, READ_INDEX, data_buf, sizeof(index));
if (retval) {
rc = 3;
goto error_out;
}
error_out:
if (data_buf)
kfree(data_buf);
return rc;
}
static int ks7010_sdio_data_compare(struct ks_wlan_private *priv, u32 address,
unsigned char *data, unsigned int size)
{
int rc = 0;
int retval;
unsigned char *read_buf;
read_buf = NULL;
read_buf = kmalloc(ROM_BUFF_SIZE, GFP_KERNEL);
if (!read_buf) {
rc = 1;
goto error_out;
}
retval = ks7010_sdio_read(priv, address, read_buf, size);
if (retval) {
rc = 2;
goto error_out;
}
retval = memcmp(data, read_buf, size);
if (retval) {
DPRINTK(0, "data compare error (%d) \n", retval);
rc = 3;
goto error_out;
}
error_out:
if (read_buf)
kfree(read_buf);
return rc;
}
static int ks7010_upload_firmware(struct ks_wlan_private *priv,
struct ks_sdio_card *card)
{
unsigned int size, offset, n = 0;
unsigned char *rom_buf;
unsigned char rw_data = 0;
int retval, rc = 0;
int length;
const struct firmware *fw_entry = NULL;
rom_buf = NULL;
rom_buf = kmalloc(ROM_BUFF_SIZE, GFP_KERNEL);
if (!rom_buf) {
rc = 3;
goto error_out0;
}
sdio_claim_host(card->func);
retval = ks7010_sdio_read(priv, GCR_A, &rw_data, sizeof(rw_data));
if (rw_data == GCR_A_RUN) {
DPRINTK(0, "MAC firmware running ...\n");
rc = 0;
goto error_out0;
}
retval = request_firmware(&fw_entry, ROM_FILE, &priv->ks_wlan_hw.sdio_card->func->dev);
if (retval)
return retval;
length = fw_entry->size;
n = 0;
do {
if (length >= ROM_BUFF_SIZE) {
size = ROM_BUFF_SIZE;
length = length - ROM_BUFF_SIZE;
} else {
size = length;
length = 0;
}
DPRINTK(4, "size = %d\n", size);
if (size == 0)
break;
memcpy(rom_buf, fw_entry->data + n, size);
offset = n;
retval =
ks7010_sdio_update_index(priv,
KS7010_IRAM_ADDRESS + offset);
if (retval) {
rc = 6;
goto error_out1;
}
retval = ks7010_sdio_write(priv, DATA_WINDOW, rom_buf, size);
if (retval) {
rc = 8;
goto error_out1;
}
retval =
ks7010_sdio_data_compare(priv, DATA_WINDOW, rom_buf, size);
if (retval) {
rc = 9;
goto error_out1;
}
n += size;
} while (size);
rw_data = GCR_A_REMAP;
retval = ks7010_sdio_write(priv, GCR_A, &rw_data, sizeof(rw_data));
if (retval) {
rc = 11;
goto error_out1;
}
DPRINTK(4, " REMAP Request : GCR_A=%02X\n", rw_data);
for (n = 0; n < 50; ++n) {
mdelay(10);
retval =
ks7010_sdio_read(priv, GCR_A, &rw_data, sizeof(rw_data));
if (retval) {
rc = 11;
goto error_out1;
}
if (rw_data == GCR_A_RUN)
break;
}
DPRINTK(4, "firmware wakeup (%d)!!!!\n", n);
if ((50) <= n) {
DPRINTK(1, "firmware can't start\n");
rc = 12;
goto error_out1;
}
rc = 0;
error_out1:
release_firmware(fw_entry);
error_out0:
sdio_release_host(card->func);
if (rom_buf)
kfree(rom_buf);
return rc;
}
static void ks7010_card_init(struct ks_wlan_private *priv)
{
DPRINTK(5, "\ncard_init_task()\n");
init_completion(&priv->confirm_wait);
DPRINTK(5, "init_completion()\n");
hostif_sme_enqueue(priv, SME_START);
DPRINTK(5, "hostif_sme_enqueu()\n");
if (!wait_for_completion_interruptible_timeout
(&priv->confirm_wait, 5 * HZ)) {
DPRINTK(1, "wait time out!! SME_START\n");
}
if (priv->mac_address_valid && priv->version_size) {
priv->dev_state = DEVICE_STATE_PREINIT;
}
hostif_sme_enqueue(priv, SME_GET_EEPROM_CKSUM);
hostif_sme_enqueue(priv, SME_STOP_REQUEST);
hostif_sme_enqueue(priv, SME_RTS_THRESHOLD_REQUEST);
hostif_sme_enqueue(priv, SME_FRAGMENTATION_THRESHOLD_REQUEST);
hostif_sme_enqueue(priv, SME_WEP_INDEX_REQUEST);
hostif_sme_enqueue(priv, SME_WEP_KEY1_REQUEST);
hostif_sme_enqueue(priv, SME_WEP_KEY2_REQUEST);
hostif_sme_enqueue(priv, SME_WEP_KEY3_REQUEST);
hostif_sme_enqueue(priv, SME_WEP_KEY4_REQUEST);
hostif_sme_enqueue(priv, SME_WEP_FLAG_REQUEST);
hostif_sme_enqueue(priv, SME_RSN_ENABLED_REQUEST);
hostif_sme_enqueue(priv, SME_MODE_SET_REQUEST);
hostif_sme_enqueue(priv, SME_START_REQUEST);
if (!wait_for_completion_interruptible_timeout
(&priv->confirm_wait, 5 * HZ)) {
DPRINTK(1, "wait time out!! wireless parameter set\n");
}
if (priv->dev_state >= DEVICE_STATE_PREINIT) {
DPRINTK(1, "DEVICE READY!!\n");
priv->dev_state = DEVICE_STATE_READY;
} else {
DPRINTK(1, "dev_state=%d\n", priv->dev_state);
}
}
static void ks7010_init_defaults(struct ks_wlan_private *priv)
{
priv->reg.tx_rate = TX_RATE_AUTO;
priv->reg.preamble = LONG_PREAMBLE;
priv->reg.powermgt = POWMGT_ACTIVE_MODE;
priv->reg.scan_type = ACTIVE_SCAN;
priv->reg.beacon_lost_count = 20;
priv->reg.rts = 2347UL;
priv->reg.fragment = 2346UL;
priv->reg.phy_type = D_11BG_COMPATIBLE_MODE;
priv->reg.cts_mode = CTS_MODE_FALSE;
priv->reg.rate_set.body[11] = TX_RATE_54M;
priv->reg.rate_set.body[10] = TX_RATE_48M;
priv->reg.rate_set.body[9] = TX_RATE_36M;
priv->reg.rate_set.body[8] = TX_RATE_18M;
priv->reg.rate_set.body[7] = TX_RATE_9M;
priv->reg.rate_set.body[6] = TX_RATE_24M | BASIC_RATE;
priv->reg.rate_set.body[5] = TX_RATE_12M | BASIC_RATE;
priv->reg.rate_set.body[4] = TX_RATE_6M | BASIC_RATE;
priv->reg.rate_set.body[3] = TX_RATE_11M | BASIC_RATE;
priv->reg.rate_set.body[2] = TX_RATE_5M | BASIC_RATE;
priv->reg.rate_set.body[1] = TX_RATE_2M | BASIC_RATE;
priv->reg.rate_set.body[0] = TX_RATE_1M | BASIC_RATE;
priv->reg.tx_rate = TX_RATE_FULL_AUTO;
priv->reg.rate_set.size = 12;
}
static int ks7010_sdio_probe(struct sdio_func *func,
const struct sdio_device_id *device)
{
struct ks_wlan_private *priv;
struct ks_sdio_card *card;
struct net_device *netdev;
unsigned char rw_data;
int ret;
DPRINTK(5, "ks7010_sdio_probe()\n");
priv = NULL;
netdev = NULL;
card = kzalloc(sizeof(struct ks_sdio_card), GFP_KERNEL);
if (!card)
return -ENOMEM;
card->func = func;
spin_lock_init(&card->lock);
sdio_claim_host(func);
ret = sdio_set_block_size(func, KS7010_IO_BLOCK_SIZE);
DPRINTK(5, "multi_block=%d sdio_set_block_size()=%d %d\n",
func->card->cccr.multi_block, func->cur_blksize, ret);
ret = sdio_enable_func(func);
DPRINTK(5, "sdio_enable_func() %d\n", ret);
if (ret)
goto error_free_card;
sdio_writeb(func, 0, INT_ENABLE, &ret);
if (ret)
goto error_free_card;
sdio_writeb(func, 0xff, INT_PENDING, &ret);
if (ret)
goto error_disable_func;
ret = sdio_claim_irq(func, ks_sdio_interrupt);
if (ret)
goto error_disable_func;
sdio_release_host(func);
sdio_set_drvdata(func, card);
DPRINTK(5, "class = 0x%X, vendor = 0x%X, "
"device = 0x%X\n", func->class, func->vendor, func->device);
netdev = alloc_etherdev(sizeof(*priv));
if (netdev == NULL) {
printk(KERN_ERR "ks7010 : Unable to alloc new net device\n");
goto error_release_irq;
}
if (dev_alloc_name(netdev, "wlan%d") < 0) {
printk(KERN_ERR "ks7010 : Couldn't get name!\n");
goto error_free_netdev;
}
priv = netdev_priv(netdev);
card->priv = priv;
SET_NETDEV_DEV(netdev, &card->func->dev);
priv->ks_wlan_hw.sdio_card = card;
init_completion(&priv->ks_wlan_hw.ks7010_sdio_wait);
priv->ks_wlan_hw.read_buf = NULL;
priv->ks_wlan_hw.read_buf = kmalloc(RX_DATA_SIZE, GFP_KERNEL);
if (!priv->ks_wlan_hw.read_buf) {
goto error_free_netdev;
}
priv->dev_state = DEVICE_STATE_PREBOOT;
priv->net_dev = netdev;
priv->firmware_version[0] = '\0';
priv->version_size = 0;
priv->last_doze = jiffies;
priv->last_wakeup = jiffies;
memset(&priv->nstats, 0, sizeof(priv->nstats));
memset(&priv->wstats, 0, sizeof(priv->wstats));
atomic_set(&priv->sleepstatus.doze_request, 0);
atomic_set(&priv->sleepstatus.wakeup_request, 0);
atomic_set(&priv->sleepstatus.wakeup_request, 0);
trx_device_init(priv);
hostif_init(priv);
ks_wlan_net_start(netdev);
ks7010_init_defaults(priv);
ret = ks7010_upload_firmware(priv, card);
if (ret) {
printk(KERN_ERR
"ks7010: firmware load failed !! retern code = %d\n",
ret);
goto error_free_read_buf;
}
rw_data = 0xff;
sdio_claim_host(func);
ret = ks7010_sdio_write(priv, INT_PENDING, &rw_data, sizeof(rw_data));
sdio_release_host(func);
if (ret) {
DPRINTK(1, " error : INT_PENDING=%02X\n", rw_data);
}
DPRINTK(4, " clear Interrupt : INT_PENDING=%02X\n", rw_data);
rw_data = (INT_GCR_B | INT_READ_STATUS | INT_WRITE_STATUS);
sdio_claim_host(func);
ret = ks7010_sdio_write(priv, INT_ENABLE, &rw_data, sizeof(rw_data));
sdio_release_host(func);
if (ret) {
DPRINTK(1, " error : INT_ENABLE=%02X\n", rw_data);
}
DPRINTK(4, " enable Interrupt : INT_ENABLE=%02X\n", rw_data);
priv->dev_state = DEVICE_STATE_BOOT;
priv->ks_wlan_hw.ks7010sdio_wq = create_workqueue("ks7010sdio_wq");
if (!priv->ks_wlan_hw.ks7010sdio_wq) {
DPRINTK(1, "create_workqueue failed !!\n");
goto error_free_read_buf;
}
INIT_DELAYED_WORK(&priv->ks_wlan_hw.rw_wq, ks7010_rw_function);
ks7010_card_init(priv);
ret = register_netdev(priv->net_dev);
if (ret)
goto error_free_read_buf;
return 0;
error_free_read_buf:
kfree(priv->ks_wlan_hw.read_buf);
priv->ks_wlan_hw.read_buf = NULL;
error_free_netdev:
free_netdev(priv->net_dev);
card->priv = NULL;
error_release_irq:
sdio_claim_host(func);
sdio_release_irq(func);
error_disable_func:
sdio_disable_func(func);
error_free_card:
sdio_release_host(func);
sdio_set_drvdata(func, NULL);
kfree(card);
return -ENODEV;
}
static void ks7010_sdio_remove(struct sdio_func *func)
{
int ret;
struct ks_sdio_card *card;
struct ks_wlan_private *priv;
struct net_device *netdev;
DPRINTK(1, "ks7010_sdio_remove()\n");
card = sdio_get_drvdata(func);
if (card == NULL)
return;
DPRINTK(1, "priv = card->priv\n");
priv = card->priv;
netdev = priv->net_dev;
if (priv) {
ks_wlan_net_stop(netdev);
DPRINTK(1, "ks_wlan_net_stop\n");
sdio_claim_host(func);
sdio_writeb(func, 0, INT_ENABLE, &ret);
sdio_writeb(func, 0xff, INT_PENDING, &ret);
sdio_release_host(func);
DPRINTK(1, "interrupt disable\n");
{
struct hostif_stop_request_t *pp;
pp = (struct hostif_stop_request_t *)
kzalloc(hif_align_size(sizeof(*pp)), GFP_KERNEL);
if (pp == NULL) {
DPRINTK(3, "allocate memory failed..\n");
return;
}
pp->header.size =
cpu_to_le16((uint16_t)
(sizeof(*pp) -
sizeof(pp->header.size)));
pp->header.event = cpu_to_le16((uint16_t) HIF_STOP_REQ);
sdio_claim_host(func);
write_to_device(priv, (unsigned char *)pp,
hif_align_size(sizeof(*pp)));
sdio_release_host(func);
kfree(pp);
}
DPRINTK(1, "STOP Req\n");
if (priv->ks_wlan_hw.ks7010sdio_wq) {
flush_workqueue(priv->ks_wlan_hw.ks7010sdio_wq);
destroy_workqueue(priv->ks_wlan_hw.ks7010sdio_wq);
}
DPRINTK(1,
"destroy_workqueue(priv->ks_wlan_hw.ks7010sdio_wq);\n");
hostif_exit(priv);
DPRINTK(1, "hostif_exit\n");
unregister_netdev(netdev);
trx_device_exit(priv);
if (priv->ks_wlan_hw.read_buf) {
kfree(priv->ks_wlan_hw.read_buf);
}
free_netdev(priv->net_dev);
card->priv = NULL;
}
sdio_claim_host(func);
sdio_release_irq(func);
DPRINTK(1, "sdio_release_irq()\n");
sdio_disable_func(func);
DPRINTK(1, "sdio_disable_func()\n");
sdio_release_host(func);
sdio_set_drvdata(func, NULL);
kfree(card);
DPRINTK(1, "kfree()\n");
DPRINTK(5, " Bye !!\n");
return;
}
