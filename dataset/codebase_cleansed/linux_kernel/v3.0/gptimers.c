void set_gptimer_pwidth(unsigned int timer_id, uint32_t value)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
timer_regs[timer_id]->width = value;
SSYNC();
}
uint32_t get_gptimer_pwidth(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
return timer_regs[timer_id]->width;
}
void set_gptimer_period(unsigned int timer_id, uint32_t period)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
timer_regs[timer_id]->period = period;
SSYNC();
}
uint32_t get_gptimer_period(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
return timer_regs[timer_id]->period;
}
uint32_t get_gptimer_count(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
return timer_regs[timer_id]->counter;
}
uint32_t get_gptimer_status(unsigned int group)
{
tassert(group < BFIN_TIMER_NUM_GROUP);
return group_regs[group]->status;
}
void set_gptimer_status(unsigned int group, uint32_t value)
{
tassert(group < BFIN_TIMER_NUM_GROUP);
group_regs[group]->status = value;
SSYNC();
}
int get_gptimer_intr(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
return !!(group_regs[BFIN_TIMER_OCTET(timer_id)]->status & timil_mask[timer_id]);
}
void clear_gptimer_intr(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
group_regs[BFIN_TIMER_OCTET(timer_id)]->status = timil_mask[timer_id];
}
int get_gptimer_over(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
return !!(group_regs[BFIN_TIMER_OCTET(timer_id)]->status & tovf_mask[timer_id]);
}
void clear_gptimer_over(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
group_regs[BFIN_TIMER_OCTET(timer_id)]->status = tovf_mask[timer_id];
}
int get_gptimer_run(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
return !!(group_regs[BFIN_TIMER_OCTET(timer_id)]->status & trun_mask[timer_id]);
}
void set_gptimer_config(unsigned int timer_id, uint16_t config)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
timer_regs[timer_id]->config = config;
SSYNC();
}
uint16_t get_gptimer_config(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
return timer_regs[timer_id]->config;
}
void enable_gptimers(uint16_t mask)
{
int i;
tassert((mask & ~BLACKFIN_GPTIMER_IDMASK) == 0);
for (i = 0; i < BFIN_TIMER_NUM_GROUP; ++i) {
group_regs[i]->enable = mask & 0xFF;
mask >>= 8;
}
SSYNC();
}
static void _disable_gptimers(uint16_t mask)
{
int i;
uint16_t m = mask;
tassert((mask & ~BLACKFIN_GPTIMER_IDMASK) == 0);
for (i = 0; i < BFIN_TIMER_NUM_GROUP; ++i) {
group_regs[i]->disable = m & 0xFF;
m >>= 8;
}
}
void disable_gptimers(uint16_t mask)
{
int i;
_disable_gptimers(mask);
for (i = 0; i < MAX_BLACKFIN_GPTIMERS; ++i)
if (mask & (1 << i))
group_regs[BFIN_TIMER_OCTET(i)]->status = trun_mask[i];
SSYNC();
}
void disable_gptimers_sync(uint16_t mask)
{
_disable_gptimers(mask);
SSYNC();
}
void set_gptimer_pulse_hi(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
timer_regs[timer_id]->config |= TIMER_PULSE_HI;
SSYNC();
}
void clear_gptimer_pulse_hi(unsigned int timer_id)
{
tassert(timer_id < MAX_BLACKFIN_GPTIMERS);
timer_regs[timer_id]->config &= ~TIMER_PULSE_HI;
SSYNC();
}
uint16_t get_enabled_gptimers(void)
{
int i;
uint16_t result = 0;
for (i = 0; i < BFIN_TIMER_NUM_GROUP; ++i)
result |= (group_regs[i]->enable << (i << 3));
return result;
}
