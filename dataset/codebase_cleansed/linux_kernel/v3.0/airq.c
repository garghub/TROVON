static int register_airq(struct airq_t *airq, u8 isc)
{
int i;
for (i = 0; i < NR_AIRQS; i++)
if (!cmpxchg(&airqs[isc][i], NULL, airq))
return i;
return -ENOMEM;
}
void *s390_register_adapter_interrupt(adapter_int_handler_t handler,
void *drv_data, u8 isc)
{
struct airq_t *airq;
char dbf_txt[16];
int ret;
if (isc > MAX_ISC)
return ERR_PTR(-EINVAL);
airq = kmalloc(sizeof(struct airq_t), GFP_KERNEL);
if (!airq) {
ret = -ENOMEM;
goto out;
}
airq->handler = handler;
airq->drv_data = drv_data;
ret = register_airq(airq, isc);
out:
snprintf(dbf_txt, sizeof(dbf_txt), "rairq:%d", ret);
CIO_TRACE_EVENT(4, dbf_txt);
if (ret < 0) {
kfree(airq);
return ERR_PTR(ret);
} else
return &indicators[isc].byte[ret];
}
void s390_unregister_adapter_interrupt(void *ind, u8 isc)
{
struct airq_t *airq;
char dbf_txt[16];
int i;
i = (int) ((addr_t) ind) - ((addr_t) &indicators[isc].byte[0]);
snprintf(dbf_txt, sizeof(dbf_txt), "urairq:%d", i);
CIO_TRACE_EVENT(4, dbf_txt);
indicators[isc].byte[i] = 0;
airq = xchg(&airqs[isc][i], NULL);
synchronize_sched();
kfree(airq);
}
void do_adapter_IO(u8 isc)
{
int w;
int i;
unsigned long word;
struct airq_t *airq;
for (w = 0; w < NR_AIRQ_WORDS; w++) {
word = indicators[isc].word[w];
i = w * NR_AIRQS_PER_WORD;
while (word) {
if (word & INDICATOR_MASK) {
airq = airqs[isc][i];
barrier();
if (likely(airq))
airq->handler(&indicators[isc].byte[i],
airq->drv_data);
else
indicators[isc].byte[i] = 0;
}
word <<= 8;
i++;
}
}
}
