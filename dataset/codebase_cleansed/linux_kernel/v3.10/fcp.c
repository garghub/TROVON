int fcp_avc_transaction(struct fw_unit *unit,
const void *command, unsigned int command_size,
void *response, unsigned int response_size,
unsigned int response_match_bytes)
{
struct fcp_transaction t;
int tcode, ret, tries = 0;
t.unit = unit;
t.response_buffer = response;
t.response_size = response_size;
t.response_match_bytes = response_match_bytes;
t.state = STATE_PENDING;
init_waitqueue_head(&t.wait);
spin_lock_irq(&transactions_lock);
list_add_tail(&t.list, &transactions);
spin_unlock_irq(&transactions_lock);
for (;;) {
tcode = command_size == 4 ? TCODE_WRITE_QUADLET_REQUEST
: TCODE_WRITE_BLOCK_REQUEST;
ret = snd_fw_transaction(t.unit, tcode,
CSR_REGISTER_BASE + CSR_FCP_COMMAND,
(void *)command, command_size);
if (ret < 0)
break;
wait_event_timeout(t.wait, t.state != STATE_PENDING,
msecs_to_jiffies(FCP_TIMEOUT_MS));
if (t.state == STATE_COMPLETE) {
ret = t.response_size;
break;
} else if (t.state == STATE_BUS_RESET) {
msleep(ERROR_DELAY_MS);
} else if (++tries >= ERROR_RETRIES) {
dev_err(&t.unit->device, "FCP command timed out\n");
ret = -EIO;
break;
}
}
spin_lock_irq(&transactions_lock);
list_del(&t.list);
spin_unlock_irq(&transactions_lock);
return ret;
}
void fcp_bus_reset(struct fw_unit *unit)
{
struct fcp_transaction *t;
spin_lock_irq(&transactions_lock);
list_for_each_entry(t, &transactions, list) {
if (t->unit == unit &&
t->state == STATE_PENDING) {
t->state = STATE_BUS_RESET;
wake_up(&t->wait);
}
}
spin_unlock_irq(&transactions_lock);
}
static bool is_matching_response(struct fcp_transaction *transaction,
const void *response, size_t length)
{
const u8 *p1, *p2;
unsigned int mask, i;
p1 = response;
p2 = transaction->response_buffer;
mask = transaction->response_match_bytes;
for (i = 0; ; ++i) {
if ((mask & 1) && p1[i] != p2[i])
return false;
mask >>= 1;
if (!mask)
return true;
if (--length == 0)
return false;
}
}
static void fcp_response(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source,
int generation, unsigned long long offset,
void *data, size_t length, void *callback_data)
{
struct fcp_transaction *t;
unsigned long flags;
if (length < 1 || (*(const u8 *)data & 0xf0) != CTS_AVC)
return;
spin_lock_irqsave(&transactions_lock, flags);
list_for_each_entry(t, &transactions, list) {
struct fw_device *device = fw_parent_device(t->unit);
if (device->card != card ||
device->generation != generation)
continue;
smp_rmb();
if (device->node_id != source)
continue;
if (t->state == STATE_PENDING &&
is_matching_response(t, data, length)) {
t->state = STATE_COMPLETE;
t->response_size = min((unsigned int)length,
t->response_size);
memcpy(t->response_buffer, data, t->response_size);
wake_up(&t->wait);
}
}
spin_unlock_irqrestore(&transactions_lock, flags);
}
static int __init fcp_module_init(void)
{
static const struct fw_address_region response_register_region = {
.start = CSR_REGISTER_BASE + CSR_FCP_RESPONSE,
.end = CSR_REGISTER_BASE + CSR_FCP_END,
};
fw_core_add_address_handler(&response_register_handler,
&response_register_region);
return 0;
}
static void __exit fcp_module_exit(void)
{
WARN_ON(!list_empty(&transactions));
fw_core_remove_address_handler(&response_register_handler);
}
