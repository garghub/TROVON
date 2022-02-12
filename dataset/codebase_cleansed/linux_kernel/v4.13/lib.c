int snd_fw_transaction(struct fw_unit *unit, int tcode,
u64 offset, void *buffer, size_t length,
unsigned int flags)
{
struct fw_device *device = fw_parent_device(unit);
int generation, rcode, tries = 0;
generation = flags & FW_GENERATION_MASK;
for (;;) {
if (!(flags & FW_FIXED_GENERATION)) {
generation = device->generation;
smp_rmb();
}
rcode = fw_run_transaction(device->card, tcode,
device->node_id, generation,
device->max_speed, offset,
buffer, length);
if (rcode == RCODE_COMPLETE)
return 0;
if (rcode == RCODE_GENERATION && (flags & FW_FIXED_GENERATION))
return -EAGAIN;
if (rcode_is_permanent_error(rcode) || ++tries >= 3) {
if (!(flags & FW_QUIET))
dev_err(&unit->device,
"transaction failed: %s\n",
fw_rcode_string(rcode));
return -EIO;
}
msleep(ERROR_RETRY_DELAY_MS);
}
}
void snd_fw_schedule_registration(struct fw_unit *unit,
struct delayed_work *dwork)
{
u64 now, delay;
now = get_jiffies_64();
delay = fw_parent_device(unit)->card->reset_jiffies
+ msecs_to_jiffies(PROBE_DELAY_MS);
if (time_after64(delay, now))
delay -= now;
else
delay = 0;
mod_delayed_work(system_wq, dwork, delay);
}
