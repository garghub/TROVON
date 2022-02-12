const char *rcode_string(unsigned int rcode)
{
static const char *const names[] = {
[RCODE_COMPLETE] = "complete",
[RCODE_CONFLICT_ERROR] = "conflict error",
[RCODE_DATA_ERROR] = "data error",
[RCODE_TYPE_ERROR] = "type error",
[RCODE_ADDRESS_ERROR] = "address error",
[RCODE_SEND_ERROR] = "send error",
[RCODE_CANCELLED] = "cancelled",
[RCODE_BUSY] = "busy",
[RCODE_GENERATION] = "generation",
[RCODE_NO_ACK] = "no ack",
};
if (rcode < ARRAY_SIZE(names) && names[rcode])
return names[rcode];
else
return "unknown";
}
int snd_fw_transaction(struct fw_unit *unit, int tcode,
u64 offset, void *buffer, size_t length)
{
struct fw_device *device = fw_parent_device(unit);
int generation, rcode, tries = 0;
for (;;) {
generation = device->generation;
smp_rmb();
rcode = fw_run_transaction(device->card, tcode,
device->node_id, generation,
device->max_speed, offset,
buffer, length);
if (rcode == RCODE_COMPLETE)
return 0;
if (rcode_is_permanent_error(rcode) || ++tries >= 3) {
dev_err(&unit->device, "transaction failed: %s\n",
rcode_string(rcode));
return -EIO;
}
msleep(ERROR_RETRY_DELAY_MS);
}
}
