static void ehci_set_command_bit(struct ehci_hcd *ehci, u32 bit)
{
ehci->command |= bit;
ehci_writel(ehci, ehci->command, &ehci->regs->command);
ehci_readl(ehci, &ehci->regs->command);
}
static void ehci_clear_command_bit(struct ehci_hcd *ehci, u32 bit)
{
ehci->command &= ~bit;
ehci_writel(ehci, ehci->command, &ehci->regs->command);
ehci_readl(ehci, &ehci->regs->command);
}
static void ehci_enable_event(struct ehci_hcd *ehci, unsigned event,
bool resched)
{
ktime_t *timeout = &ehci->hr_timeouts[event];
if (resched)
*timeout = ktime_add(ktime_get(),
ktime_set(0, event_delays_ns[event]));
ehci->enabled_hrtimer_events |= (1 << event);
if (event < ehci->next_hrtimer_event) {
ehci->next_hrtimer_event = event;
hrtimer_start_range_ns(&ehci->hrtimer, *timeout,
NSEC_PER_MSEC, HRTIMER_MODE_ABS);
}
}
static void ehci_poll_ASS(struct ehci_hcd *ehci)
{
unsigned actual, want;
if (ehci->rh_state != EHCI_RH_RUNNING)
return;
want = (ehci->command & CMD_ASE) ? STS_ASS : 0;
actual = ehci_readl(ehci, &ehci->regs->status) & STS_ASS;
if (want != actual) {
if (ehci->ASS_poll_count++ < 20) {
ehci_enable_event(ehci, EHCI_HRTIMER_POLL_ASS, true);
return;
}
ehci_warn(ehci, "Waited too long for the async schedule status, giving up\n");
}
ehci->ASS_poll_count = 0;
if (want == 0) {
if (ehci->async_count > 0)
ehci_set_command_bit(ehci, CMD_ASE);
} else {
if (ehci->async_count == 0) {
ehci_enable_event(ehci, EHCI_HRTIMER_DISABLE_ASYNC,
true);
}
}
}
static void ehci_disable_ASE(struct ehci_hcd *ehci)
{
ehci_clear_command_bit(ehci, CMD_ASE);
}
static void ehci_poll_PSS(struct ehci_hcd *ehci)
{
unsigned actual, want;
if (ehci->rh_state != EHCI_RH_RUNNING)
return;
want = (ehci->command & CMD_PSE) ? STS_PSS : 0;
actual = ehci_readl(ehci, &ehci->regs->status) & STS_PSS;
if (want != actual) {
if (ehci->PSS_poll_count++ < 20) {
ehci_enable_event(ehci, EHCI_HRTIMER_POLL_PSS, true);
return;
}
ehci_warn(ehci, "Waited too long for the periodic schedule status, giving up\n");
}
ehci->PSS_poll_count = 0;
if (want == 0) {
if (ehci->periodic_count > 0)
ehci_set_command_bit(ehci, CMD_PSE);
} else {
if (ehci->periodic_count == 0) {
ehci_enable_event(ehci, EHCI_HRTIMER_DISABLE_PERIODIC,
true);
}
}
}
static void ehci_disable_PSE(struct ehci_hcd *ehci)
{
ehci_clear_command_bit(ehci, CMD_PSE);
}
static void ehci_handle_controller_death(struct ehci_hcd *ehci)
{
if (!(ehci_readl(ehci, &ehci->regs->status) & STS_HALT)) {
if (ehci->died_poll_count++ < 5) {
ehci_enable_event(ehci, EHCI_HRTIMER_POLL_DEAD, true);
return;
}
ehci_warn(ehci, "Waited too long for the controller to stop, giving up\n");
}
ehci->rh_state = EHCI_RH_HALTED;
ehci_writel(ehci, 0, &ehci->regs->configured_flag);
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
ehci_work(ehci);
end_unlink_async(ehci);
}
static void ehci_handle_intr_unlinks(struct ehci_hcd *ehci)
{
bool stopped = (ehci->rh_state < EHCI_RH_RUNNING);
ehci->intr_unlinking = true;
while (ehci->intr_unlink) {
struct ehci_qh *qh = ehci->intr_unlink;
if (!stopped && qh->unlink_cycle == ehci->intr_unlink_cycle)
break;
ehci->intr_unlink = qh->unlink_next;
qh->unlink_next = NULL;
end_unlink_intr(ehci, qh);
}
if (ehci->intr_unlink) {
ehci_enable_event(ehci, EHCI_HRTIMER_UNLINK_INTR, true);
++ehci->intr_unlink_cycle;
}
ehci->intr_unlinking = false;
}
static void start_free_itds(struct ehci_hcd *ehci)
{
if (!(ehci->enabled_hrtimer_events & BIT(EHCI_HRTIMER_FREE_ITDS))) {
ehci->last_itd_to_free = list_entry(
ehci->cached_itd_list.prev,
struct ehci_itd, itd_list);
ehci->last_sitd_to_free = list_entry(
ehci->cached_sitd_list.prev,
struct ehci_sitd, sitd_list);
ehci_enable_event(ehci, EHCI_HRTIMER_FREE_ITDS, true);
}
}
static void end_free_itds(struct ehci_hcd *ehci)
{
struct ehci_itd *itd, *n;
struct ehci_sitd *sitd, *sn;
if (ehci->rh_state < EHCI_RH_RUNNING) {
ehci->last_itd_to_free = NULL;
ehci->last_sitd_to_free = NULL;
}
list_for_each_entry_safe(itd, n, &ehci->cached_itd_list, itd_list) {
list_del(&itd->itd_list);
dma_pool_free(ehci->itd_pool, itd, itd->itd_dma);
if (itd == ehci->last_itd_to_free)
break;
}
list_for_each_entry_safe(sitd, sn, &ehci->cached_sitd_list, sitd_list) {
list_del(&sitd->sitd_list);
dma_pool_free(ehci->sitd_pool, sitd, sitd->sitd_dma);
if (sitd == ehci->last_sitd_to_free)
break;
}
if (!list_empty(&ehci->cached_itd_list) ||
!list_empty(&ehci->cached_sitd_list))
start_free_itds(ehci);
}
static void ehci_iaa_watchdog(struct ehci_hcd *ehci)
{
if (ehci->rh_state != EHCI_RH_RUNNING)
return;
if (ehci->async_iaa) {
u32 cmd, status;
cmd = ehci_readl(ehci, &ehci->regs->command);
status = ehci_readl(ehci, &ehci->regs->status);
if ((status & STS_IAA) || !(cmd & CMD_IAAD)) {
COUNT(ehci->stats.lost_iaa);
ehci_writel(ehci, STS_IAA, &ehci->regs->status);
}
ehci_vdbg(ehci, "IAA watchdog: status %x cmd %x\n",
status, cmd);
end_unlink_async(ehci);
}
}
static void turn_on_io_watchdog(struct ehci_hcd *ehci)
{
if (ehci->rh_state != EHCI_RH_RUNNING ||
(ehci->enabled_hrtimer_events &
BIT(EHCI_HRTIMER_IO_WATCHDOG)))
return;
if (ehci->isoc_count > 0 || (ehci->need_io_watchdog &&
ehci->async_count + ehci->intr_count > 0))
ehci_enable_event(ehci, EHCI_HRTIMER_IO_WATCHDOG, true);
}
static enum hrtimer_restart ehci_hrtimer_func(struct hrtimer *t)
{
struct ehci_hcd *ehci = container_of(t, struct ehci_hcd, hrtimer);
ktime_t now;
unsigned long events;
unsigned long flags;
unsigned e;
spin_lock_irqsave(&ehci->lock, flags);
events = ehci->enabled_hrtimer_events;
ehci->enabled_hrtimer_events = 0;
ehci->next_hrtimer_event = EHCI_HRTIMER_NO_EVENT;
now = ktime_get();
for_each_set_bit(e, &events, EHCI_HRTIMER_NUM_EVENTS) {
if (now.tv64 >= ehci->hr_timeouts[e].tv64)
event_handlers[e](ehci);
else
ehci_enable_event(ehci, e, false);
}
spin_unlock_irqrestore(&ehci->lock, flags);
return HRTIMER_NORESTART;
}
