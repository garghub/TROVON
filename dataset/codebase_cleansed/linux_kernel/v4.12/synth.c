void spk_do_catch_up(struct spk_synth *synth)
{
u_char ch;
unsigned long flags;
unsigned long jiff_max;
struct var_t *delay_time;
struct var_t *full_time;
struct var_t *jiffy_delta;
int jiffy_delta_val;
int delay_time_val;
int full_time_val;
jiffy_delta = spk_get_var(JIFFY);
full_time = spk_get_var(FULL);
delay_time = spk_get_var(DELAY);
spin_lock_irqsave(&speakup_info.spinlock, flags);
jiffy_delta_val = jiffy_delta->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
jiff_max = jiffies + jiffy_delta_val;
while (!kthread_should_stop()) {
spin_lock_irqsave(&speakup_info.spinlock, flags);
if (speakup_info.flushing) {
speakup_info.flushing = 0;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
synth->flush(synth);
continue;
}
synth_buffer_skip_nonlatin1();
if (synth_buffer_empty()) {
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
break;
}
ch = synth_buffer_peek();
set_current_state(TASK_INTERRUPTIBLE);
full_time_val = full_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ch == '\n')
ch = synth->procspeech;
if (!synth->io_ops->synth_out(synth, ch)) {
schedule_timeout(msecs_to_jiffies(full_time_val));
continue;
}
if (time_after_eq(jiffies, jiff_max) && (ch == SPACE)) {
spin_lock_irqsave(&speakup_info.spinlock, flags);
jiffy_delta_val = jiffy_delta->u.n.value;
delay_time_val = delay_time->u.n.value;
full_time_val = full_time->u.n.value;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (synth->io_ops->synth_out(synth, synth->procspeech))
schedule_timeout(
msecs_to_jiffies(delay_time_val));
else
schedule_timeout(
msecs_to_jiffies(full_time_val));
jiff_max = jiffies + jiffy_delta_val;
}
set_current_state(TASK_RUNNING);
spin_lock_irqsave(&speakup_info.spinlock, flags);
synth_buffer_getc();
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
}
synth->io_ops->synth_out(synth, synth->procspeech);
}
void spk_synth_flush(struct spk_synth *synth)
{
synth->io_ops->synth_out(synth, synth->clear);
}
int spk_synth_is_alive_nop(struct spk_synth *synth)
{
synth->alive = 1;
return 1;
}
int spk_synth_is_alive_restart(struct spk_synth *synth)
{
if (synth->alive)
return 1;
if (spk_wait_for_xmitr(synth) > 0) {
synth->alive = 1;
synth_printf("%s", synth->init);
return 2;
}
pr_warn("%s: can't restart synth\n", synth->long_name);
return 0;
}
static void thread_wake_up(u_long data)
{
wake_up_interruptible_all(&speakup_event);
}
void synth_start(void)
{
struct var_t *trigger_time;
if (!synth->alive) {
synth_buffer_clear();
return;
}
trigger_time = spk_get_var(TRIGGER);
if (!timer_pending(&thread_timer))
mod_timer(&thread_timer, jiffies +
msecs_to_jiffies(trigger_time->u.n.value));
}
void spk_do_flush(void)
{
if (!synth)
return;
speakup_info.flushing = 1;
synth_buffer_clear();
if (synth->alive) {
if (spk_pitch_shift) {
synth_printf("%s", spk_pitch_buff);
spk_pitch_shift = 0;
}
}
wake_up_interruptible_all(&speakup_event);
wake_up_process(speakup_task);
}
void synth_write(const char *buf, size_t count)
{
while (count--)
synth_buffer_add(*buf++);
synth_start();
}
void synth_printf(const char *fmt, ...)
{
va_list args;
unsigned char buf[160], *p;
int r;
va_start(args, fmt);
r = vsnprintf(buf, sizeof(buf), fmt, args);
va_end(args);
if (r > sizeof(buf) - 1)
r = sizeof(buf) - 1;
p = buf;
while (r--)
synth_buffer_add(*p++);
synth_start();
}
void synth_putwc(u16 wc)
{
synth_buffer_add(wc);
}
void synth_putwc_s(u16 wc)
{
synth_buffer_add(wc);
synth_start();
}
void synth_putws(const u16 *buf)
{
const u16 *p;
for (p = buf; *p; p++)
synth_buffer_add(*p);
}
void synth_putws_s(const u16 *buf)
{
synth_putws(buf);
synth_start();
}
void spk_reset_index_count(int sc)
{
static int first = 1;
if (first)
first = 0;
else
synth->get_index();
index_count = 0;
sentence_count = sc;
}
int synth_supports_indexing(void)
{
if (synth->get_index)
return 1;
return 0;
}
void synth_insert_next_index(int sent_num)
{
int out;
if (synth->alive) {
if (sent_num == 0) {
synth->indexing.currindex++;
index_count++;
if (synth->indexing.currindex >
synth->indexing.highindex)
synth->indexing.currindex =
synth->indexing.lowindex;
}
out = synth->indexing.currindex * 10 + sent_num;
synth_printf(synth->indexing.command, out, out);
}
}
void spk_get_index_count(int *linecount, int *sentcount)
{
int ind = synth->get_index();
if (ind) {
sentence_count = ind % 10;
if ((ind / 10) <= synth->indexing.currindex)
index_count = synth->indexing.currindex - (ind / 10);
else
index_count = synth->indexing.currindex
- synth->indexing.lowindex
+ synth->indexing.highindex - (ind / 10) + 1;
}
*sentcount = sentence_count;
*linecount = index_count;
}
int synth_request_region(unsigned long start, unsigned long n)
{
struct resource *parent = &ioport_resource;
memset(&synth_res, 0, sizeof(synth_res));
synth_res.name = synth->name;
synth_res.start = start;
synth_res.end = start + n - 1;
synth_res.flags = IORESOURCE_BUSY;
return request_resource(parent, &synth_res);
}
int synth_release_region(unsigned long start, unsigned long n)
{
return release_resource(&synth_res);
}
int synth_init(char *synth_name)
{
int i;
int ret = 0;
struct spk_synth *synth = NULL;
if (!synth_name)
return 0;
if (strcmp(synth_name, "none") == 0) {
mutex_lock(&spk_mutex);
synth_release();
mutex_unlock(&spk_mutex);
return 0;
}
mutex_lock(&spk_mutex);
for (i = 0; i < MAXSYNTHS && synths[i]; i++)
if (strcmp(synths[i]->name, synth_name) == 0)
synth = synths[i];
if (synth)
ret = do_synth_init(synth);
else
ret = -ENODEV;
mutex_unlock(&spk_mutex);
return ret;
}
static int do_synth_init(struct spk_synth *in_synth)
{
struct var_t *var;
synth_release();
if (in_synth->checkval != SYNTH_CHECK)
return -EINVAL;
synth = in_synth;
synth->alive = 0;
pr_warn("synth probe\n");
if (synth->probe(synth) < 0) {
pr_warn("%s: device probe failed\n", in_synth->name);
synth = NULL;
return -ENODEV;
}
synth_time_vars[0].u.n.value =
synth_time_vars[0].u.n.default_val = synth->delay;
synth_time_vars[1].u.n.value =
synth_time_vars[1].u.n.default_val = synth->trigger;
synth_time_vars[2].u.n.value =
synth_time_vars[2].u.n.default_val = synth->jiffies;
synth_time_vars[3].u.n.value =
synth_time_vars[3].u.n.default_val = synth->full;
synth_printf("%s", synth->init);
for (var = synth->vars;
(var->var_id >= 0) && (var->var_id < MAXVARS); var++)
speakup_register_var(var);
if (!spk_quiet_boot)
synth_printf("%s found\n", synth->long_name);
if (synth->attributes.name &&
sysfs_create_group(speakup_kobj, &synth->attributes) < 0)
return -ENOMEM;
synth_flags = synth->flags;
wake_up_interruptible_all(&speakup_event);
if (speakup_task)
wake_up_process(speakup_task);
return 0;
}
void synth_release(void)
{
struct var_t *var;
unsigned long flags;
if (!synth)
return;
spin_lock_irqsave(&speakup_info.spinlock, flags);
pr_info("releasing synth %s\n", synth->name);
synth->alive = 0;
del_timer(&thread_timer);
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (synth->attributes.name)
sysfs_remove_group(speakup_kobj, &synth->attributes);
for (var = synth->vars; var->var_id != MAXVARS; var++)
speakup_unregister_var(var->var_id);
synth->release();
synth = NULL;
}
int synth_add(struct spk_synth *in_synth)
{
int i;
int status = 0;
mutex_lock(&spk_mutex);
for (i = 0; i < MAXSYNTHS && synths[i]; i++)
if (in_synth == synths[i]) {
mutex_unlock(&spk_mutex);
return 0;
}
if (i == MAXSYNTHS) {
pr_warn("Error: attempting to add a synth past end of array\n");
mutex_unlock(&spk_mutex);
return -1;
}
synths[i++] = in_synth;
synths[i] = NULL;
if (in_synth->startup)
status = do_synth_init(in_synth);
mutex_unlock(&spk_mutex);
return status;
}
void synth_remove(struct spk_synth *in_synth)
{
int i;
mutex_lock(&spk_mutex);
if (synth == in_synth)
synth_release();
for (i = 0; synths[i]; i++) {
if (in_synth == synths[i])
break;
}
for ( ; synths[i]; i++)
synths[i] = synths[i + 1];
module_status = 0;
mutex_unlock(&spk_mutex);
}
