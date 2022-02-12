static int at91_enter_idle(struct cpuidle_device *dev,
struct cpuidle_state *state)
{
struct timeval before, after;
int idle_time;
u32 saved_lpr;
local_irq_disable();
do_gettimeofday(&before);
if (state == &dev->states[0])
cpu_do_idle();
else if (state == &dev->states[1]) {
asm("b 1f; .align 5; 1:");
asm("mcr p15, 0, r0, c7, c10, 4");
saved_lpr = sdram_selfrefresh_enable();
cpu_do_idle();
sdram_selfrefresh_disable(saved_lpr);
}
do_gettimeofday(&after);
local_irq_enable();
idle_time = (after.tv_sec - before.tv_sec) * USEC_PER_SEC +
(after.tv_usec - before.tv_usec);
return idle_time;
}
static int at91_init_cpuidle(void)
{
struct cpuidle_device *device;
cpuidle_register_driver(&at91_idle_driver);
device = &per_cpu(at91_cpuidle_device, smp_processor_id());
device->state_count = AT91_MAX_STATES;
device->states[0].enter = at91_enter_idle;
device->states[0].exit_latency = 1;
device->states[0].target_residency = 10000;
device->states[0].flags = CPUIDLE_FLAG_TIME_VALID;
strcpy(device->states[0].name, "WFI");
strcpy(device->states[0].desc, "Wait for interrupt");
device->states[1].enter = at91_enter_idle;
device->states[1].exit_latency = 10;
device->states[1].target_residency = 10000;
device->states[1].flags = CPUIDLE_FLAG_TIME_VALID;
strcpy(device->states[1].name, "RAM_SR");
strcpy(device->states[1].desc, "WFI and RAM Self Refresh");
if (cpuidle_register_device(device)) {
printk(KERN_ERR "at91_init_cpuidle: Failed registering\n");
return -EIO;
}
return 0;
}
