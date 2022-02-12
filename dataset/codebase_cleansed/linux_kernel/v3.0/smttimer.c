void smt_timer_init(struct s_smc *smc)
{
smc->t.st_queue = NULL;
smc->t.st_fast.tm_active = FALSE ;
smc->t.st_fast.tm_next = NULL;
hwt_init(smc) ;
}
void smt_timer_stop(struct s_smc *smc, struct smt_timer *timer)
{
struct smt_timer **prev ;
struct smt_timer *tm ;
timer->tm_active = FALSE ;
if (smc->t.st_queue == timer && !timer->tm_next) {
hwt_stop(smc) ;
}
for (prev = &smc->t.st_queue ; (tm = *prev) ; prev = &tm->tm_next ) {
if (tm == timer) {
*prev = tm->tm_next ;
if (tm->tm_next) {
tm->tm_next->tm_delta += tm->tm_delta ;
}
return ;
}
}
}
void smt_timer_start(struct s_smc *smc, struct smt_timer *timer, u_long time,
u_long token)
{
struct smt_timer **prev ;
struct smt_timer *tm ;
u_long delta = 0 ;
time /= 16 ;
if (!time)
time = 1 ;
smt_timer_stop(smc,timer) ;
timer->tm_smc = smc ;
timer->tm_token = token ;
timer->tm_active = TRUE ;
if (!smc->t.st_queue) {
smc->t.st_queue = timer ;
timer->tm_next = NULL;
timer->tm_delta = time ;
hwt_start(smc,time) ;
return ;
}
timer_done(smc,0) ;
delta = 0 ;
for (prev = &smc->t.st_queue ; (tm = *prev) ; prev = &tm->tm_next ) {
if (delta + tm->tm_delta > time) {
break ;
}
delta += tm->tm_delta ;
}
*prev = timer ;
timer->tm_next = tm ;
timer->tm_delta = time - delta ;
if (tm)
tm->tm_delta -= timer->tm_delta ;
hwt_start(smc,smc->t.st_queue->tm_delta) ;
}
void smt_force_irq(struct s_smc *smc)
{
smt_timer_start(smc,&smc->t.st_fast,32L, EV_TOKEN(EVENT_SMT,SM_FAST));
}
void smt_timer_done(struct s_smc *smc)
{
timer_done(smc,1) ;
}
static void timer_done(struct s_smc *smc, int restart)
{
u_long delta ;
struct smt_timer *tm ;
struct smt_timer *next ;
struct smt_timer **last ;
int done = 0 ;
delta = hwt_read(smc) ;
last = &smc->t.st_queue ;
tm = smc->t.st_queue ;
while (tm && !done) {
if (delta >= tm->tm_delta) {
tm->tm_active = FALSE ;
delta -= tm->tm_delta ;
last = &tm->tm_next ;
tm = tm->tm_next ;
}
else {
tm->tm_delta -= delta ;
delta = 0 ;
done = 1 ;
}
}
*last = NULL;
next = smc->t.st_queue ;
smc->t.st_queue = tm ;
for ( tm = next ; tm ; tm = next) {
next = tm->tm_next ;
timer_event(smc,tm->tm_token) ;
}
if (restart && smc->t.st_queue)
hwt_start(smc,smc->t.st_queue->tm_delta) ;
}
