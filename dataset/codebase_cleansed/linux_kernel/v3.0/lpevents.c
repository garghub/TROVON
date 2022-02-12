static struct HvLpEvent * get_next_hvlpevent(void)
{
struct HvLpEvent * event;
event = (struct HvLpEvent *)hvlpevent_queue.hq_current_event;
if (hvlpevent_is_valid(event)) {
rmb();
hvlpevent_queue.hq_current_event += ((event->xSizeMinus1 +
IT_LP_EVENT_ALIGN) / IT_LP_EVENT_ALIGN) *
IT_LP_EVENT_ALIGN;
if (hvlpevent_queue.hq_current_event >
hvlpevent_queue.hq_last_event) {
hvlpevent_queue.hq_current_event =
hvlpevent_queue.hq_event_stack;
}
} else {
event = NULL;
}
return event;
}
int hvlpevent_is_pending(void)
{
struct HvLpEvent *next_event;
if (smp_processor_id() >= spread_lpevents)
return 0;
next_event = (struct HvLpEvent *)hvlpevent_queue.hq_current_event;
return hvlpevent_is_valid(next_event) ||
hvlpevent_queue.hq_overflow_pending;
}
static void hvlpevent_clear_valid(struct HvLpEvent * event)
{
struct HvLpEvent *tmp;
unsigned extra = ((event->xSizeMinus1 + IT_LP_EVENT_ALIGN) /
IT_LP_EVENT_ALIGN) - 1;
switch (extra) {
case 3:
tmp = (struct HvLpEvent*)((char*)event + 3 * IT_LP_EVENT_ALIGN);
hvlpevent_invalidate(tmp);
case 2:
tmp = (struct HvLpEvent*)((char*)event + 2 * IT_LP_EVENT_ALIGN);
hvlpevent_invalidate(tmp);
case 1:
tmp = (struct HvLpEvent*)((char*)event + 1 * IT_LP_EVENT_ALIGN);
hvlpevent_invalidate(tmp);
}
mb();
hvlpevent_invalidate(event);
}
void process_hvlpevents(void)
{
struct HvLpEvent * event;
restart:
if (!spin_trylock(&hvlpevent_queue.hq_lock))
return;
for (;;) {
event = get_next_hvlpevent();
if (event) {
if (event->xType < HvLpEvent_Type_NumTypes)
__get_cpu_var(hvlpevent_counts)[event->xType]++;
if (event->xType < HvLpEvent_Type_NumTypes &&
lpEventHandler[event->xType])
lpEventHandler[event->xType](event);
else {
u8 type = event->xType;
hvlpevent_clear_valid(event);
spin_unlock(&hvlpevent_queue.hq_lock);
printk(KERN_INFO
"Unexpected Lp Event type=%d\n", type);
goto restart;
}
hvlpevent_clear_valid(event);
} else if (hvlpevent_queue.hq_overflow_pending)
HvCallEvent_getOverflowLpEvents(hvlpevent_queue.hq_index);
else
break;
}
spin_unlock(&hvlpevent_queue.hq_lock);
}
static int set_spread_lpevents(char *str)
{
unsigned long val = simple_strtoul(str, NULL, 0);
if (( val > 0) && (val <= NR_CPUS)) {
spread_lpevents = val;
printk("lpevent processing spread over %ld processors\n", val);
} else {
printk("invalid spread_lpevents %ld\n", val);
}
return 1;
}
void __init setup_hvlpevent_queue(void)
{
void *eventStack;
spin_lock_init(&hvlpevent_queue.hq_lock);
eventStack = alloc_bootmem_pages(IT_LP_EVENT_STACK_SIZE);
memset(eventStack, 0, IT_LP_EVENT_STACK_SIZE);
HvCallEvent_setLpEventStack(0, eventStack, IT_LP_EVENT_STACK_SIZE);
hvlpevent_queue.hq_event_stack = eventStack;
hvlpevent_queue.hq_current_event = eventStack;
hvlpevent_queue.hq_last_event = (char *)eventStack +
(IT_LP_EVENT_STACK_SIZE - IT_LP_EVENT_MAX_SIZE);
hvlpevent_queue.hq_index = 0;
}
int HvLpEvent_registerHandler(HvLpEvent_Type eventType, LpEventHandler handler)
{
if (eventType < HvLpEvent_Type_NumTypes) {
lpEventHandler[eventType] = handler;
return 0;
}
return 1;
}
int HvLpEvent_unregisterHandler(HvLpEvent_Type eventType)
{
might_sleep();
if (eventType < HvLpEvent_Type_NumTypes) {
if (!lpEventHandlerPaths[eventType]) {
lpEventHandler[eventType] = NULL;
synchronize_sched();
return 0;
}
}
return 1;
}
int HvLpEvent_openPath(HvLpEvent_Type eventType, HvLpIndex lpIndex)
{
if ((eventType < HvLpEvent_Type_NumTypes) &&
lpEventHandler[eventType]) {
if (lpIndex == 0)
lpIndex = itLpNaca.xLpIndex;
HvCallEvent_openLpEventPath(lpIndex, eventType);
++lpEventHandlerPaths[eventType];
return 0;
}
return 1;
}
int HvLpEvent_closePath(HvLpEvent_Type eventType, HvLpIndex lpIndex)
{
if ((eventType < HvLpEvent_Type_NumTypes) &&
lpEventHandler[eventType] &&
lpEventHandlerPaths[eventType]) {
if (lpIndex == 0)
lpIndex = itLpNaca.xLpIndex;
HvCallEvent_closeLpEventPath(lpIndex, eventType);
--lpEventHandlerPaths[eventType];
return 0;
}
return 1;
}
static int proc_lpevents_show(struct seq_file *m, void *v)
{
int cpu, i;
unsigned long sum;
static unsigned long cpu_totals[NR_CPUS];
sum = 0;
for_each_online_cpu(cpu) {
cpu_totals[cpu] = 0;
for (i = 0; i < HvLpEvent_Type_NumTypes; i++) {
cpu_totals[cpu] += per_cpu(hvlpevent_counts, cpu)[i];
}
sum += cpu_totals[cpu];
}
seq_printf(m, "LpEventQueue 0\n");
seq_printf(m, " events processed:\t%lu\n", sum);
for (i = 0; i < HvLpEvent_Type_NumTypes; ++i) {
sum = 0;
for_each_online_cpu(cpu) {
sum += per_cpu(hvlpevent_counts, cpu)[i];
}
seq_printf(m, " %-20s %10lu\n", event_types[i], sum);
}
seq_printf(m, "\n events processed by processor:\n");
for_each_online_cpu(cpu) {
seq_printf(m, " CPU%02d %10lu\n", cpu, cpu_totals[cpu]);
}
return 0;
}
static int proc_lpevents_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_lpevents_show, NULL);
}
static int __init proc_lpevents_init(void)
{
if (!firmware_has_feature(FW_FEATURE_ISERIES))
return 0;
proc_create("iSeries/lpevents", S_IFREG|S_IRUGO, NULL,
&proc_lpevents_operations);
return 0;
}
