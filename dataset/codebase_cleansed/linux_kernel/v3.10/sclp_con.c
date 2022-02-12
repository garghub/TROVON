static void
sclp_conbuf_callback(struct sclp_buffer *buffer, int rc)
{
unsigned long flags;
void *page;
do {
page = sclp_unmake_buffer(buffer);
spin_lock_irqsave(&sclp_con_lock, flags);
list_del(&buffer->list);
list_add_tail((struct list_head *) page, &sclp_con_pages);
buffer = NULL;
if (!list_empty(&sclp_con_outqueue))
buffer = list_first_entry(&sclp_con_outqueue,
struct sclp_buffer, list);
if (!buffer || sclp_con_suspended) {
sclp_con_queue_running = 0;
spin_unlock_irqrestore(&sclp_con_lock, flags);
break;
}
spin_unlock_irqrestore(&sclp_con_lock, flags);
} while (sclp_emit_buffer(buffer, sclp_conbuf_callback));
}
static void sclp_conbuf_emit(void)
{
struct sclp_buffer* buffer;
unsigned long flags;
int rc;
spin_lock_irqsave(&sclp_con_lock, flags);
if (sclp_conbuf)
list_add_tail(&sclp_conbuf->list, &sclp_con_outqueue);
sclp_conbuf = NULL;
if (sclp_con_queue_running || sclp_con_suspended)
goto out_unlock;
if (list_empty(&sclp_con_outqueue))
goto out_unlock;
buffer = list_first_entry(&sclp_con_outqueue, struct sclp_buffer,
list);
sclp_con_queue_running = 1;
spin_unlock_irqrestore(&sclp_con_lock, flags);
rc = sclp_emit_buffer(buffer, sclp_conbuf_callback);
if (rc)
sclp_conbuf_callback(buffer, rc);
return;
out_unlock:
spin_unlock_irqrestore(&sclp_con_lock, flags);
}
static void sclp_console_sync_queue(void)
{
unsigned long flags;
spin_lock_irqsave(&sclp_con_lock, flags);
if (timer_pending(&sclp_con_timer))
del_timer(&sclp_con_timer);
while (sclp_con_queue_running) {
spin_unlock_irqrestore(&sclp_con_lock, flags);
sclp_sync_wait();
spin_lock_irqsave(&sclp_con_lock, flags);
}
spin_unlock_irqrestore(&sclp_con_lock, flags);
}
static void
sclp_console_timeout(unsigned long data)
{
sclp_conbuf_emit();
}
static void
sclp_console_write(struct console *console, const char *message,
unsigned int count)
{
unsigned long flags;
void *page;
int written;
if (count == 0)
return;
spin_lock_irqsave(&sclp_con_lock, flags);
do {
if (sclp_conbuf == NULL) {
while (list_empty(&sclp_con_pages)) {
if (sclp_con_suspended)
goto out;
spin_unlock_irqrestore(&sclp_con_lock, flags);
sclp_sync_wait();
spin_lock_irqsave(&sclp_con_lock, flags);
}
page = sclp_con_pages.next;
list_del((struct list_head *) page);
sclp_conbuf = sclp_make_buffer(page, sclp_con_columns,
sclp_con_width_htab);
}
written = sclp_write(sclp_conbuf, (const unsigned char *)
message, count);
if (written == count)
break;
spin_unlock_irqrestore(&sclp_con_lock, flags);
sclp_conbuf_emit();
spin_lock_irqsave(&sclp_con_lock, flags);
message += written;
count -= written;
} while (count > 0);
if (sclp_conbuf != NULL && sclp_chars_in_buffer(sclp_conbuf) != 0 &&
!timer_pending(&sclp_con_timer)) {
init_timer(&sclp_con_timer);
sclp_con_timer.function = sclp_console_timeout;
sclp_con_timer.data = 0UL;
sclp_con_timer.expires = jiffies + HZ/10;
add_timer(&sclp_con_timer);
}
out:
spin_unlock_irqrestore(&sclp_con_lock, flags);
}
static struct tty_driver *
sclp_console_device(struct console *c, int *index)
{
*index = c->index;
return sclp_tty_driver;
}
static void
sclp_console_flush(void)
{
sclp_conbuf_emit();
sclp_console_sync_queue();
}
static void sclp_console_resume(void)
{
unsigned long flags;
spin_lock_irqsave(&sclp_con_lock, flags);
sclp_con_suspended = 0;
spin_unlock_irqrestore(&sclp_con_lock, flags);
sclp_conbuf_emit();
}
static void sclp_console_suspend(void)
{
unsigned long flags;
spin_lock_irqsave(&sclp_con_lock, flags);
sclp_con_suspended = 1;
spin_unlock_irqrestore(&sclp_con_lock, flags);
sclp_console_flush();
}
static int sclp_console_notify(struct notifier_block *self,
unsigned long event, void *data)
{
sclp_console_flush();
return NOTIFY_OK;
}
void sclp_console_pm_event(enum sclp_pm_event sclp_pm_event)
{
switch (sclp_pm_event) {
case SCLP_PM_EVENT_FREEZE:
sclp_console_suspend();
break;
case SCLP_PM_EVENT_RESTORE:
case SCLP_PM_EVENT_THAW:
sclp_console_resume();
break;
}
}
static int __init
sclp_console_init(void)
{
void *page;
int i;
int rc;
if (!CONSOLE_IS_SCLP)
return 0;
rc = sclp_rw_init();
if (rc)
return rc;
INIT_LIST_HEAD(&sclp_con_pages);
for (i = 0; i < MAX_CONSOLE_PAGES; i++) {
page = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
list_add_tail(page, &sclp_con_pages);
}
INIT_LIST_HEAD(&sclp_con_outqueue);
spin_lock_init(&sclp_con_lock);
sclp_conbuf = NULL;
init_timer(&sclp_con_timer);
if (MACHINE_IS_VM)
sclp_con_columns = 76;
else
sclp_con_columns = 80;
sclp_con_width_htab = 8;
atomic_notifier_chain_register(&panic_notifier_list, &on_panic_nb);
register_reboot_notifier(&on_reboot_nb);
register_console(&sclp_console);
return 0;
}
