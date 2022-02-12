int register_adapter_interrupt(struct airq_struct *airq)
{
char dbf_txt[32];
if (!airq->handler || airq->isc > MAX_ISC)
return -EINVAL;
if (!airq->lsi_ptr) {
airq->lsi_ptr = kzalloc(1, GFP_KERNEL);
if (!airq->lsi_ptr)
return -ENOMEM;
airq->flags |= AIRQ_PTR_ALLOCATED;
}
if (!airq->lsi_mask)
airq->lsi_mask = 0xff;
snprintf(dbf_txt, sizeof(dbf_txt), "rairq:%p", airq);
CIO_TRACE_EVENT(4, dbf_txt);
isc_register(airq->isc);
spin_lock(&airq_lists_lock);
hlist_add_head_rcu(&airq->list, &airq_lists[airq->isc]);
spin_unlock(&airq_lists_lock);
return 0;
}
void unregister_adapter_interrupt(struct airq_struct *airq)
{
char dbf_txt[32];
if (hlist_unhashed(&airq->list))
return;
snprintf(dbf_txt, sizeof(dbf_txt), "urairq:%p", airq);
CIO_TRACE_EVENT(4, dbf_txt);
spin_lock(&airq_lists_lock);
hlist_del_rcu(&airq->list);
spin_unlock(&airq_lists_lock);
synchronize_rcu();
isc_unregister(airq->isc);
if (airq->flags & AIRQ_PTR_ALLOCATED) {
kfree(airq->lsi_ptr);
airq->lsi_ptr = NULL;
airq->flags &= ~AIRQ_PTR_ALLOCATED;
}
}
static irqreturn_t do_airq_interrupt(int irq, void *dummy)
{
struct tpi_info *tpi_info;
struct airq_struct *airq;
struct hlist_head *head;
__this_cpu_write(s390_idle.nohz_delay, 1);
tpi_info = (struct tpi_info *) &get_irq_regs()->int_code;
head = &airq_lists[tpi_info->isc];
rcu_read_lock();
hlist_for_each_entry_rcu(airq, head, list)
if ((*airq->lsi_ptr & airq->lsi_mask) != 0)
airq->handler(airq);
rcu_read_unlock();
return IRQ_HANDLED;
}
void __init init_airq_interrupts(void)
{
irq_set_chip_and_handler(THIN_INTERRUPT,
&dummy_irq_chip, handle_percpu_irq);
setup_irq(THIN_INTERRUPT, &airq_interrupt);
}
struct airq_iv *airq_iv_create(unsigned long bits, unsigned long flags)
{
struct airq_iv *iv;
unsigned long size;
iv = kzalloc(sizeof(*iv), GFP_KERNEL);
if (!iv)
goto out;
iv->bits = bits;
size = BITS_TO_LONGS(bits) * sizeof(unsigned long);
iv->vector = kzalloc(size, GFP_KERNEL);
if (!iv->vector)
goto out_free;
if (flags & AIRQ_IV_ALLOC) {
iv->avail = kmalloc(size, GFP_KERNEL);
if (!iv->avail)
goto out_free;
memset(iv->avail, 0xff, size);
iv->end = 0;
} else
iv->end = bits;
if (flags & AIRQ_IV_BITLOCK) {
iv->bitlock = kzalloc(size, GFP_KERNEL);
if (!iv->bitlock)
goto out_free;
}
if (flags & AIRQ_IV_PTR) {
size = bits * sizeof(unsigned long);
iv->ptr = kzalloc(size, GFP_KERNEL);
if (!iv->ptr)
goto out_free;
}
if (flags & AIRQ_IV_DATA) {
size = bits * sizeof(unsigned int);
iv->data = kzalloc(size, GFP_KERNEL);
if (!iv->data)
goto out_free;
}
spin_lock_init(&iv->lock);
return iv;
out_free:
kfree(iv->ptr);
kfree(iv->bitlock);
kfree(iv->avail);
kfree(iv->vector);
kfree(iv);
out:
return NULL;
}
void airq_iv_release(struct airq_iv *iv)
{
kfree(iv->data);
kfree(iv->ptr);
kfree(iv->bitlock);
kfree(iv->vector);
kfree(iv->avail);
kfree(iv);
}
unsigned long airq_iv_alloc_bit(struct airq_iv *iv)
{
unsigned long bit;
if (!iv->avail)
return -1UL;
spin_lock(&iv->lock);
bit = find_first_bit_inv(iv->avail, iv->bits);
if (bit < iv->bits) {
clear_bit_inv(bit, iv->avail);
if (bit >= iv->end)
iv->end = bit + 1;
} else
bit = -1UL;
spin_unlock(&iv->lock);
return bit;
}
void airq_iv_free_bit(struct airq_iv *iv, unsigned long bit)
{
if (!iv->avail)
return;
spin_lock(&iv->lock);
clear_bit_inv(bit, iv->vector);
set_bit_inv(bit, iv->avail);
if (bit == iv->end - 1) {
while (--iv->end > 0)
if (!test_bit_inv(iv->end - 1, iv->avail))
break;
}
spin_unlock(&iv->lock);
}
unsigned long airq_iv_scan(struct airq_iv *iv, unsigned long start,
unsigned long end)
{
unsigned long bit;
bit = find_next_bit_inv(iv->vector, end, start);
if (bit >= end)
return -1UL;
clear_bit_inv(bit, iv->vector);
return bit;
}
