static int process_sdio_pending_irqs(struct mmc_host *host)
{
struct mmc_card *card = host->card;
int i, ret, count;
unsigned char pending;
struct sdio_func *func;
func = card->sdio_single_irq;
if (func && host->sdio_irq_pending) {
func->irq_handler(func);
return 1;
}
ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_INTx, 0, &pending);
if (ret) {
pr_debug("%s: error %d reading SDIO_CCCR_INTx\n",
mmc_card_id(card), ret);
return ret;
}
count = 0;
for (i = 1; i <= 7; i++) {
if (pending & (1 << i)) {
func = card->sdio_func[i - 1];
if (!func) {
pr_warning("%s: pending IRQ for "
"non-existent function\n",
mmc_card_id(card));
ret = -EINVAL;
} else if (func->irq_handler) {
func->irq_handler(func);
count++;
} else {
pr_warning("%s: pending IRQ with no handler\n",
sdio_func_id(func));
ret = -EINVAL;
}
}
}
if (count)
return count;
return ret;
}
static int sdio_irq_thread(void *_host)
{
struct mmc_host *host = _host;
struct sched_param param = { .sched_priority = 1 };
unsigned long period, idle_period;
int ret;
sched_setscheduler(current, SCHED_FIFO, &param);
idle_period = msecs_to_jiffies(10);
period = (host->caps & MMC_CAP_SDIO_IRQ) ?
MAX_SCHEDULE_TIMEOUT : idle_period;
pr_debug("%s: IRQ thread started (poll period = %lu jiffies)\n",
mmc_hostname(host), period);
do {
ret = __mmc_claim_host(host, &host->sdio_irq_thread_abort);
if (ret)
break;
ret = process_sdio_pending_irqs(host);
host->sdio_irq_pending = false;
mmc_release_host(host);
if (ret < 0) {
set_current_state(TASK_INTERRUPTIBLE);
if (!kthread_should_stop())
schedule_timeout(HZ);
set_current_state(TASK_RUNNING);
}
if (!(host->caps & MMC_CAP_SDIO_IRQ)) {
if (ret > 0)
period /= 2;
else {
period++;
if (period > idle_period)
period = idle_period;
}
}
set_current_state(TASK_INTERRUPTIBLE);
if (host->caps & MMC_CAP_SDIO_IRQ) {
mmc_host_clk_hold(host);
host->ops->enable_sdio_irq(host, 1);
mmc_host_clk_release(host);
}
if (!kthread_should_stop())
schedule_timeout(period);
set_current_state(TASK_RUNNING);
} while (!kthread_should_stop());
if (host->caps & MMC_CAP_SDIO_IRQ) {
mmc_host_clk_hold(host);
host->ops->enable_sdio_irq(host, 0);
mmc_host_clk_release(host);
}
pr_debug("%s: IRQ thread exiting with code %d\n",
mmc_hostname(host), ret);
return ret;
}
static int sdio_card_irq_get(struct mmc_card *card)
{
struct mmc_host *host = card->host;
WARN_ON(!host->claimed);
if (!host->sdio_irqs++) {
atomic_set(&host->sdio_irq_thread_abort, 0);
host->sdio_irq_thread =
kthread_run(sdio_irq_thread, host, "ksdioirqd/%s",
mmc_hostname(host));
if (IS_ERR(host->sdio_irq_thread)) {
int err = PTR_ERR(host->sdio_irq_thread);
host->sdio_irqs--;
return err;
}
}
return 0;
}
static int sdio_card_irq_put(struct mmc_card *card)
{
struct mmc_host *host = card->host;
WARN_ON(!host->claimed);
BUG_ON(host->sdio_irqs < 1);
if (!--host->sdio_irqs) {
atomic_set(&host->sdio_irq_thread_abort, 1);
kthread_stop(host->sdio_irq_thread);
}
return 0;
}
static void sdio_single_irq_set(struct mmc_card *card)
{
struct sdio_func *func;
int i;
card->sdio_single_irq = NULL;
if ((card->host->caps & MMC_CAP_SDIO_IRQ) &&
card->host->sdio_irqs == 1)
for (i = 0; i < card->sdio_funcs; i++) {
func = card->sdio_func[i];
if (func && func->irq_handler) {
card->sdio_single_irq = func;
break;
}
}
}
int sdio_claim_irq(struct sdio_func *func, sdio_irq_handler_t *handler)
{
int ret;
unsigned char reg;
BUG_ON(!func);
BUG_ON(!func->card);
pr_debug("SDIO: Enabling IRQ for %s...\n", sdio_func_id(func));
if (func->irq_handler) {
pr_debug("SDIO: IRQ for %s already in use.\n", sdio_func_id(func));
return -EBUSY;
}
ret = mmc_io_rw_direct(func->card, 0, 0, SDIO_CCCR_IENx, 0, &reg);
if (ret)
return ret;
reg |= 1 << func->num;
reg |= 1;
ret = mmc_io_rw_direct(func->card, 1, 0, SDIO_CCCR_IENx, reg, NULL);
if (ret)
return ret;
func->irq_handler = handler;
ret = sdio_card_irq_get(func->card);
if (ret)
func->irq_handler = NULL;
sdio_single_irq_set(func->card);
return ret;
}
int sdio_release_irq(struct sdio_func *func)
{
int ret;
unsigned char reg;
BUG_ON(!func);
BUG_ON(!func->card);
pr_debug("SDIO: Disabling IRQ for %s...\n", sdio_func_id(func));
if (func->irq_handler) {
func->irq_handler = NULL;
sdio_card_irq_put(func->card);
sdio_single_irq_set(func->card);
}
ret = mmc_io_rw_direct(func->card, 0, 0, SDIO_CCCR_IENx, 0, &reg);
if (ret)
return ret;
reg &= ~(1 << func->num);
if (!(reg & 0xFE))
reg = 0;
ret = mmc_io_rw_direct(func->card, 1, 0, SDIO_CCCR_IENx, reg, NULL);
if (ret)
return ret;
return 0;
}
