static int __connect(struct irq_bypass_producer *prod,
struct irq_bypass_consumer *cons)
{
int ret = 0;
if (prod->stop)
prod->stop(prod);
if (cons->stop)
cons->stop(cons);
if (prod->add_consumer)
ret = prod->add_consumer(prod, cons);
if (!ret) {
ret = cons->add_producer(cons, prod);
if (ret && prod->del_consumer)
prod->del_consumer(prod, cons);
}
if (cons->start)
cons->start(cons);
if (prod->start)
prod->start(prod);
return ret;
}
static void __disconnect(struct irq_bypass_producer *prod,
struct irq_bypass_consumer *cons)
{
if (prod->stop)
prod->stop(prod);
if (cons->stop)
cons->stop(cons);
cons->del_producer(cons, prod);
if (prod->del_consumer)
prod->del_consumer(prod, cons);
if (cons->start)
cons->start(cons);
if (prod->start)
prod->start(prod);
}
int irq_bypass_register_producer(struct irq_bypass_producer *producer)
{
struct irq_bypass_producer *tmp;
struct irq_bypass_consumer *consumer;
might_sleep();
if (!try_module_get(THIS_MODULE))
return -ENODEV;
mutex_lock(&lock);
list_for_each_entry(tmp, &producers, node) {
if (tmp->token == producer->token) {
mutex_unlock(&lock);
module_put(THIS_MODULE);
return -EBUSY;
}
}
list_for_each_entry(consumer, &consumers, node) {
if (consumer->token == producer->token) {
int ret = __connect(producer, consumer);
if (ret) {
mutex_unlock(&lock);
module_put(THIS_MODULE);
return ret;
}
break;
}
}
list_add(&producer->node, &producers);
mutex_unlock(&lock);
return 0;
}
void irq_bypass_unregister_producer(struct irq_bypass_producer *producer)
{
struct irq_bypass_producer *tmp;
struct irq_bypass_consumer *consumer;
might_sleep();
if (!try_module_get(THIS_MODULE))
return;
mutex_lock(&lock);
list_for_each_entry(tmp, &producers, node) {
if (tmp->token != producer->token)
continue;
list_for_each_entry(consumer, &consumers, node) {
if (consumer->token == producer->token) {
__disconnect(producer, consumer);
break;
}
}
list_del(&producer->node);
module_put(THIS_MODULE);
break;
}
mutex_unlock(&lock);
module_put(THIS_MODULE);
}
int irq_bypass_register_consumer(struct irq_bypass_consumer *consumer)
{
struct irq_bypass_consumer *tmp;
struct irq_bypass_producer *producer;
if (!consumer->add_producer || !consumer->del_producer)
return -EINVAL;
might_sleep();
if (!try_module_get(THIS_MODULE))
return -ENODEV;
mutex_lock(&lock);
list_for_each_entry(tmp, &consumers, node) {
if (tmp->token == consumer->token) {
mutex_unlock(&lock);
module_put(THIS_MODULE);
return -EBUSY;
}
}
list_for_each_entry(producer, &producers, node) {
if (producer->token == consumer->token) {
int ret = __connect(producer, consumer);
if (ret) {
mutex_unlock(&lock);
module_put(THIS_MODULE);
return ret;
}
break;
}
}
list_add(&consumer->node, &consumers);
mutex_unlock(&lock);
return 0;
}
void irq_bypass_unregister_consumer(struct irq_bypass_consumer *consumer)
{
struct irq_bypass_consumer *tmp;
struct irq_bypass_producer *producer;
might_sleep();
if (!try_module_get(THIS_MODULE))
return;
mutex_lock(&lock);
list_for_each_entry(tmp, &consumers, node) {
if (tmp->token != consumer->token)
continue;
list_for_each_entry(producer, &producers, node) {
if (producer->token == consumer->token) {
__disconnect(producer, consumer);
break;
}
}
list_del(&consumer->node);
module_put(THIS_MODULE);
break;
}
mutex_unlock(&lock);
module_put(THIS_MODULE);
}
