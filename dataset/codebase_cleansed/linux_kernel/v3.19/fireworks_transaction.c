int snd_efw_transaction_cmd(struct fw_unit *unit,
const void *cmd, unsigned int size)
{
return snd_fw_transaction(unit, TCODE_WRITE_BLOCK_REQUEST,
MEMORY_SPACE_EFW_COMMAND,
(void *)cmd, size, 0);
}
int snd_efw_transaction_run(struct fw_unit *unit,
const void *cmd, unsigned int cmd_size,
void *resp, unsigned int resp_size)
{
struct transaction_queue t;
unsigned int tries;
int ret;
t.unit = unit;
t.buf = resp;
t.size = resp_size;
t.seqnum = be32_to_cpu(((struct snd_efw_transaction *)cmd)->seqnum) + 1;
t.state = STATE_PENDING;
init_waitqueue_head(&t.wait);
spin_lock_irq(&transaction_queues_lock);
list_add_tail(&t.list, &transaction_queues);
spin_unlock_irq(&transaction_queues_lock);
tries = 0;
do {
ret = snd_efw_transaction_cmd(t.unit, (void *)cmd, cmd_size);
if (ret < 0)
break;
wait_event_timeout(t.wait, t.state != STATE_PENDING,
msecs_to_jiffies(EFC_TIMEOUT_MS));
if (t.state == STATE_COMPLETE) {
ret = t.size;
break;
} else if (t.state == STATE_BUS_RESET) {
msleep(ERROR_DELAY_MS);
} else if (++tries >= ERROR_RETRIES) {
dev_err(&t.unit->device, "EFW transaction timed out\n");
ret = -EIO;
break;
}
} while (1);
spin_lock_irq(&transaction_queues_lock);
list_del(&t.list);
spin_unlock_irq(&transaction_queues_lock);
return ret;
}
static void
copy_resp_to_buf(struct snd_efw *efw, void *data, size_t length, int *rcode)
{
size_t capacity, till_end;
struct snd_efw_transaction *t;
spin_lock_irq(&efw->lock);
t = (struct snd_efw_transaction *)data;
length = min_t(size_t, be32_to_cpu(t->length) * sizeof(u32), length);
if (efw->push_ptr < efw->pull_ptr)
capacity = (unsigned int)(efw->pull_ptr - efw->push_ptr);
else
capacity = snd_efw_resp_buf_size -
(unsigned int)(efw->push_ptr - efw->pull_ptr);
if (capacity < length) {
*rcode = RCODE_CONFLICT_ERROR;
goto end;
}
while (length > 0) {
till_end = snd_efw_resp_buf_size -
(unsigned int)(efw->push_ptr - efw->resp_buf);
till_end = min_t(unsigned int, length, till_end);
memcpy(efw->push_ptr, data, till_end);
efw->push_ptr += till_end;
if (efw->push_ptr >= efw->resp_buf + snd_efw_resp_buf_size)
efw->push_ptr -= snd_efw_resp_buf_size;
length -= till_end;
data += till_end;
}
efw->resp_queues++;
wake_up(&efw->hwdep_wait);
*rcode = RCODE_COMPLETE;
end:
spin_unlock_irq(&efw->lock);
}
static void
handle_resp_for_user(struct fw_card *card, int generation, int source,
void *data, size_t length, int *rcode)
{
struct fw_device *device;
struct snd_efw *efw;
unsigned int i;
spin_lock_irq(&instances_lock);
for (i = 0; i < SNDRV_CARDS; i++) {
efw = instances[i];
if (efw == NULL)
continue;
device = fw_parent_device(efw->unit);
if ((device->card != card) ||
(device->generation != generation))
continue;
smp_rmb();
if (device->node_id != source)
continue;
break;
}
if (i == SNDRV_CARDS)
goto end;
copy_resp_to_buf(efw, data, length, rcode);
end:
spin_unlock_irq(&instances_lock);
}
static void
handle_resp_for_kernel(struct fw_card *card, int generation, int source,
void *data, size_t length, int *rcode, u32 seqnum)
{
struct fw_device *device;
struct transaction_queue *t;
unsigned long flags;
spin_lock_irqsave(&transaction_queues_lock, flags);
list_for_each_entry(t, &transaction_queues, list) {
device = fw_parent_device(t->unit);
if ((device->card != card) ||
(device->generation != generation))
continue;
smp_rmb();
if (device->node_id != source)
continue;
if ((t->state == STATE_PENDING) && (t->seqnum == seqnum)) {
t->state = STATE_COMPLETE;
t->size = min_t(unsigned int, length, t->size);
memcpy(t->buf, data, t->size);
wake_up(&t->wait);
*rcode = RCODE_COMPLETE;
}
}
spin_unlock_irqrestore(&transaction_queues_lock, flags);
}
static void
efw_response(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source,
int generation, unsigned long long offset,
void *data, size_t length, void *callback_data)
{
int rcode, dummy;
u32 seqnum;
rcode = RCODE_TYPE_ERROR;
if (length < sizeof(struct snd_efw_transaction)) {
rcode = RCODE_DATA_ERROR;
goto end;
} else if (offset != MEMORY_SPACE_EFW_RESPONSE) {
rcode = RCODE_ADDRESS_ERROR;
goto end;
}
seqnum = be32_to_cpu(((struct snd_efw_transaction *)data)->seqnum);
if (seqnum > SND_EFW_TRANSACTION_USER_SEQNUM_MAX + 1) {
handle_resp_for_kernel(card, generation, source,
data, length, &rcode, seqnum);
if (snd_efw_resp_buf_debug)
handle_resp_for_user(card, generation, source,
data, length, &dummy);
} else {
handle_resp_for_user(card, generation, source,
data, length, &rcode);
}
end:
fw_send_response(card, request, rcode);
}
void snd_efw_transaction_add_instance(struct snd_efw *efw)
{
unsigned int i;
spin_lock_irq(&instances_lock);
for (i = 0; i < SNDRV_CARDS; i++) {
if (instances[i] != NULL)
continue;
instances[i] = efw;
break;
}
spin_unlock_irq(&instances_lock);
}
void snd_efw_transaction_remove_instance(struct snd_efw *efw)
{
unsigned int i;
spin_lock_irq(&instances_lock);
for (i = 0; i < SNDRV_CARDS; i++) {
if (instances[i] != efw)
continue;
instances[i] = NULL;
}
spin_unlock_irq(&instances_lock);
}
void snd_efw_transaction_bus_reset(struct fw_unit *unit)
{
struct transaction_queue *t;
spin_lock_irq(&transaction_queues_lock);
list_for_each_entry(t, &transaction_queues, list) {
if ((t->unit == unit) &&
(t->state == STATE_PENDING)) {
t->state = STATE_BUS_RESET;
wake_up(&t->wait);
}
}
spin_unlock_irq(&transaction_queues_lock);
}
int snd_efw_transaction_register(void)
{
static const struct fw_address_region resp_register_region = {
.start = MEMORY_SPACE_EFW_RESPONSE,
.end = MEMORY_SPACE_EFW_RESPONSE +
SND_EFW_RESPONSE_MAXIMUM_BYTES
};
return fw_core_add_address_handler(&resp_register_handler,
&resp_register_region);
}
void snd_efw_transaction_unregister(void)
{
WARN_ON(!list_empty(&transaction_queues));
fw_core_remove_address_handler(&resp_register_handler);
}
