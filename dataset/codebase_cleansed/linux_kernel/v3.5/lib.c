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
fw_rcode_string(rcode));
return -EIO;
}
msleep(ERROR_RETRY_DELAY_MS);
}
}
