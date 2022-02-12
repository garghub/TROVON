static int speedstep_smi_ownership(void)
{
u32 command, result, magic, dummy;
u32 function = GET_SPEEDSTEP_OWNER;
unsigned char magic_data[] = "Copyright (c) 1999 Intel Corporation";
command = (smi_sig & 0xffffff00) | (smi_cmd & 0xff);
magic = virt_to_phys(magic_data);
pr_debug("trying to obtain ownership with command %x at port %x\n",
command, smi_port);
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp\n"
: "=D" (result),
"=a" (dummy), "=b" (dummy), "=c" (dummy), "=d" (dummy),
"=S" (dummy)
: "a" (command), "b" (function), "c" (0), "d" (smi_port),
"D" (0), "S" (magic)
: "memory"
);
pr_debug("result is %x\n", result);
return result;
}
static int speedstep_smi_get_freqs(unsigned int *low, unsigned int *high)
{
u32 command, result = 0, edi, high_mhz, low_mhz, dummy;
u32 state = 0;
u32 function = GET_SPEEDSTEP_FREQS;
if (!(ist_info.event & 0xFFFF)) {
pr_debug("bug #1422 -- can't read freqs from BIOS\n");
return -ENODEV;
}
command = (smi_sig & 0xffffff00) | (smi_cmd & 0xff);
pr_debug("trying to determine frequencies with command %x at port %x\n",
command, smi_port);
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp"
: "=a" (result),
"=b" (high_mhz),
"=c" (low_mhz),
"=d" (state), "=D" (edi), "=S" (dummy)
: "a" (command),
"b" (function),
"c" (state),
"d" (smi_port), "S" (0), "D" (0)
);
pr_debug("result %x, low_freq %u, high_freq %u\n",
result, low_mhz, high_mhz);
if ((high_mhz + low_mhz) < 600)
return -EINVAL;
*high = high_mhz * 1000;
*low = low_mhz * 1000;
return result;
}
static int speedstep_get_state(void)
{
u32 function = GET_SPEEDSTEP_STATE;
u32 result, state, edi, command, dummy;
command = (smi_sig & 0xffffff00) | (smi_cmd & 0xff);
pr_debug("trying to determine current setting with command %x "
"at port %x\n", command, smi_port);
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp\n"
: "=a" (result),
"=b" (state), "=D" (edi),
"=c" (dummy), "=d" (dummy), "=S" (dummy)
: "a" (command), "b" (function), "c" (0),
"d" (smi_port), "S" (0), "D" (0)
);
pr_debug("state is %x, result is %x\n", state, result);
return state & 1;
}
static void speedstep_set_state(unsigned int state)
{
unsigned int result = 0, command, new_state, dummy;
unsigned long flags;
unsigned int function = SET_SPEEDSTEP_STATE;
unsigned int retry = 0;
if (state > 0x1)
return;
local_irq_save(flags);
command = (smi_sig & 0xffffff00) | (smi_cmd & 0xff);
pr_debug("trying to set frequency to state %u "
"with command %x at port %x\n",
state, command, smi_port);
do {
if (retry) {
pr_debug("retry %u, previous result %u, waiting...\n",
retry, result);
mdelay(retry * 50);
}
retry++;
__asm__ __volatile__(
"push %%ebp\n"
"out %%al, (%%dx)\n"
"pop %%ebp"
: "=b" (new_state), "=D" (result),
"=c" (dummy), "=a" (dummy),
"=d" (dummy), "=S" (dummy)
: "a" (command), "b" (function), "c" (state),
"d" (smi_port), "S" (0), "D" (0)
);
} while ((new_state != state) && (retry <= SMI_TRIES));
local_irq_restore(flags);
if (new_state == state)
pr_debug("change to %u MHz succeeded after %u tries "
"with result %u\n",
(speedstep_freqs[new_state].frequency / 1000),
retry, result);
else
printk(KERN_ERR "cpufreq: change to state %u "
"failed with new_state %u and result %u\n",
state, new_state, result);
return;
}
static int speedstep_target(struct cpufreq_policy *policy, unsigned int index)
{
speedstep_set_state(index);
return 0;
}
static int speedstep_cpu_init(struct cpufreq_policy *policy)
{
int result;
unsigned int *low, *high;
if (policy->cpu != 0)
return -ENODEV;
result = speedstep_smi_ownership();
if (result) {
pr_debug("fails in acquiring ownership of a SMI interface.\n");
return -EINVAL;
}
low = &speedstep_freqs[SPEEDSTEP_LOW].frequency;
high = &speedstep_freqs[SPEEDSTEP_HIGH].frequency;
result = speedstep_smi_get_freqs(low, high);
if (result) {
pr_debug("could not detect low and high frequencies "
"by SMI call.\n");
result = speedstep_get_freqs(speedstep_processor,
low, high,
NULL,
&speedstep_set_state);
if (result) {
pr_debug("could not detect two different speeds"
" -- aborting.\n");
return result;
} else
pr_debug("workaround worked.\n");
}
policy->cpuinfo.transition_latency = CPUFREQ_ETERNAL;
return cpufreq_table_validate_and_show(policy, speedstep_freqs);
}
static unsigned int speedstep_get(unsigned int cpu)
{
if (cpu)
return -ENODEV;
return speedstep_get_frequency(speedstep_processor);
}
static int speedstep_resume(struct cpufreq_policy *policy)
{
int result = speedstep_smi_ownership();
if (result)
pr_debug("fails in re-acquiring ownership of a SMI interface.\n");
return result;
}
static int __init speedstep_init(void)
{
if (!x86_match_cpu(ss_smi_ids))
return -ENODEV;
speedstep_processor = speedstep_detect_processor();
switch (speedstep_processor) {
case SPEEDSTEP_CPU_PIII_T:
case SPEEDSTEP_CPU_PIII_C:
case SPEEDSTEP_CPU_PIII_C_EARLY:
break;
default:
speedstep_processor = 0;
}
if (!speedstep_processor) {
pr_debug("No supported Intel CPU detected.\n");
return -ENODEV;
}
pr_debug("signature:0x%.8ulx, command:0x%.8ulx, "
"event:0x%.8ulx, perf_level:0x%.8ulx.\n",
ist_info.signature, ist_info.command,
ist_info.event, ist_info.perf_level);
if ((ist_info.signature != 0x47534943) && (
(smi_port == 0) || (smi_cmd == 0)))
return -ENODEV;
if (smi_sig == 1)
smi_sig = 0x47534943;
else
smi_sig = ist_info.signature;
if ((smi_port > 0xff) || (smi_port < 0))
return -EINVAL;
else if (smi_port == 0)
smi_port = ist_info.command & 0xff;
if ((smi_cmd > 0xff) || (smi_cmd < 0))
return -EINVAL;
else if (smi_cmd == 0)
smi_cmd = (ist_info.command >> 16) & 0xff;
return cpufreq_register_driver(&speedstep_driver);
}
static void __exit speedstep_exit(void)
{
cpufreq_unregister_driver(&speedstep_driver);
}
