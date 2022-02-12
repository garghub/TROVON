static inline event_word_t *event_word_from_port(unsigned port)
{
unsigned i = port / EVENT_WORDS_PER_PAGE;
return event_array[i] + port % EVENT_WORDS_PER_PAGE;
}
static unsigned evtchn_fifo_max_channels(void)
{
return EVTCHN_FIFO_NR_CHANNELS;
}
static unsigned evtchn_fifo_nr_channels(void)
{
return event_array_pages * EVENT_WORDS_PER_PAGE;
}
static int init_control_block(int cpu,
struct evtchn_fifo_control_block *control_block)
{
struct evtchn_fifo_queue *q = &per_cpu(cpu_queue, cpu);
struct evtchn_init_control init_control;
unsigned int i;
clear_page(control_block);
for (i = 0; i < EVTCHN_FIFO_MAX_QUEUES; i++)
q->head[i] = 0;
init_control.control_gfn = virt_to_gfn(control_block);
init_control.offset = 0;
init_control.vcpu = xen_vcpu_nr(cpu);
return HYPERVISOR_event_channel_op(EVTCHNOP_init_control, &init_control);
}
static void free_unused_array_pages(void)
{
unsigned i;
for (i = event_array_pages; i < MAX_EVENT_ARRAY_PAGES; i++) {
if (!event_array[i])
break;
free_page((unsigned long)event_array[i]);
event_array[i] = NULL;
}
}
static void init_array_page(event_word_t *array_page)
{
unsigned i;
for (i = 0; i < EVENT_WORDS_PER_PAGE; i++)
array_page[i] = 1 << EVTCHN_FIFO_MASKED;
}
static int evtchn_fifo_setup(struct irq_info *info)
{
unsigned port = info->evtchn;
unsigned new_array_pages;
int ret;
new_array_pages = port / EVENT_WORDS_PER_PAGE + 1;
if (new_array_pages > MAX_EVENT_ARRAY_PAGES)
return -EINVAL;
while (event_array_pages < new_array_pages) {
void *array_page;
struct evtchn_expand_array expand_array;
array_page = event_array[event_array_pages];
if (!array_page) {
array_page = (void *)__get_free_page(GFP_KERNEL);
if (array_page == NULL) {
ret = -ENOMEM;
goto error;
}
event_array[event_array_pages] = array_page;
}
init_array_page(array_page);
expand_array.array_gfn = virt_to_gfn(array_page);
ret = HYPERVISOR_event_channel_op(EVTCHNOP_expand_array, &expand_array);
if (ret < 0)
goto error;
event_array_pages++;
}
return 0;
error:
if (event_array_pages == 0)
panic("xen: unable to expand event array with initial page (%d)\n", ret);
else
pr_err("unable to expand event array (%d)\n", ret);
free_unused_array_pages();
return ret;
}
static void evtchn_fifo_bind_to_cpu(struct irq_info *info, unsigned cpu)
{
}
static void evtchn_fifo_clear_pending(unsigned port)
{
event_word_t *word = event_word_from_port(port);
sync_clear_bit(EVTCHN_FIFO_BIT(PENDING, word), BM(word));
}
static void evtchn_fifo_set_pending(unsigned port)
{
event_word_t *word = event_word_from_port(port);
sync_set_bit(EVTCHN_FIFO_BIT(PENDING, word), BM(word));
}
static bool evtchn_fifo_is_pending(unsigned port)
{
event_word_t *word = event_word_from_port(port);
return sync_test_bit(EVTCHN_FIFO_BIT(PENDING, word), BM(word));
}
static bool evtchn_fifo_test_and_set_mask(unsigned port)
{
event_word_t *word = event_word_from_port(port);
return sync_test_and_set_bit(EVTCHN_FIFO_BIT(MASKED, word), BM(word));
}
static void evtchn_fifo_mask(unsigned port)
{
event_word_t *word = event_word_from_port(port);
sync_set_bit(EVTCHN_FIFO_BIT(MASKED, word), BM(word));
}
static bool evtchn_fifo_is_masked(unsigned port)
{
event_word_t *word = event_word_from_port(port);
return sync_test_bit(EVTCHN_FIFO_BIT(MASKED, word), BM(word));
}
static void clear_masked(volatile event_word_t *word)
{
event_word_t new, old, w;
w = *word;
do {
old = w & ~(1 << EVTCHN_FIFO_BUSY);
new = old & ~(1 << EVTCHN_FIFO_MASKED);
w = sync_cmpxchg(word, old, new);
} while (w != old);
}
static void evtchn_fifo_unmask(unsigned port)
{
event_word_t *word = event_word_from_port(port);
BUG_ON(!irqs_disabled());
clear_masked(word);
if (evtchn_fifo_is_pending(port)) {
struct evtchn_unmask unmask = { .port = port };
(void)HYPERVISOR_event_channel_op(EVTCHNOP_unmask, &unmask);
}
}
static uint32_t clear_linked(volatile event_word_t *word)
{
event_word_t new, old, w;
w = *word;
do {
old = w;
new = (w & ~((1 << EVTCHN_FIFO_LINKED)
| EVTCHN_FIFO_LINK_MASK));
} while ((w = sync_cmpxchg(word, old, new)) != old);
return w & EVTCHN_FIFO_LINK_MASK;
}
static void handle_irq_for_port(unsigned port)
{
int irq;
irq = get_evtchn_to_irq(port);
if (irq != -1)
generic_handle_irq(irq);
}
static void consume_one_event(unsigned cpu,
struct evtchn_fifo_control_block *control_block,
unsigned priority, unsigned long *ready,
bool drop)
{
struct evtchn_fifo_queue *q = &per_cpu(cpu_queue, cpu);
uint32_t head;
unsigned port;
event_word_t *word;
head = q->head[priority];
if (head == 0) {
virt_rmb();
head = control_block->head[priority];
}
port = head;
word = event_word_from_port(port);
head = clear_linked(word);
if (head == 0)
clear_bit(priority, ready);
if (evtchn_fifo_is_pending(port) && !evtchn_fifo_is_masked(port)) {
if (unlikely(drop))
pr_warn("Dropping pending event for port %u\n", port);
else
handle_irq_for_port(port);
}
q->head[priority] = head;
}
static void __evtchn_fifo_handle_events(unsigned cpu, bool drop)
{
struct evtchn_fifo_control_block *control_block;
unsigned long ready;
unsigned q;
control_block = per_cpu(cpu_control_block, cpu);
ready = xchg(&control_block->ready, 0);
while (ready) {
q = find_first_bit(&ready, EVTCHN_FIFO_MAX_QUEUES);
consume_one_event(cpu, control_block, q, &ready, drop);
ready |= xchg(&control_block->ready, 0);
}
}
static void evtchn_fifo_handle_events(unsigned cpu)
{
__evtchn_fifo_handle_events(cpu, false);
}
static void evtchn_fifo_resume(void)
{
unsigned cpu;
for_each_possible_cpu(cpu) {
void *control_block = per_cpu(cpu_control_block, cpu);
int ret;
if (!control_block)
continue;
if (!cpu_online(cpu)) {
free_page((unsigned long)control_block);
per_cpu(cpu_control_block, cpu) = NULL;
continue;
}
ret = init_control_block(cpu, control_block);
if (ret < 0)
BUG();
}
event_array_pages = 0;
}
static int evtchn_fifo_alloc_control_block(unsigned cpu)
{
void *control_block = NULL;
int ret = -ENOMEM;
control_block = (void *)__get_free_page(GFP_KERNEL);
if (control_block == NULL)
goto error;
ret = init_control_block(cpu, control_block);
if (ret < 0)
goto error;
per_cpu(cpu_control_block, cpu) = control_block;
return 0;
error:
free_page((unsigned long)control_block);
return ret;
}
static int xen_evtchn_cpu_prepare(unsigned int cpu)
{
if (!per_cpu(cpu_control_block, cpu))
return evtchn_fifo_alloc_control_block(cpu);
return 0;
}
static int xen_evtchn_cpu_dead(unsigned int cpu)
{
__evtchn_fifo_handle_events(cpu, true);
return 0;
}
int __init xen_evtchn_fifo_init(void)
{
int cpu = get_cpu();
int ret;
ret = evtchn_fifo_alloc_control_block(cpu);
if (ret < 0)
goto out;
pr_info("Using FIFO-based ABI\n");
evtchn_ops = &evtchn_ops_fifo;
cpuhp_setup_state_nocalls(CPUHP_XEN_EVTCHN_PREPARE,
"CPUHP_XEN_EVTCHN_PREPARE",
xen_evtchn_cpu_prepare, xen_evtchn_cpu_dead);
out:
put_cpu();
return ret;
}
