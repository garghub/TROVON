static int parman_enlarge(struct parman *parman)
{
unsigned long new_count = parman->limit_count +
parman->ops->resize_step;
int err;
err = parman->ops->resize(parman->priv, new_count);
if (err)
return err;
parman->limit_count = new_count;
return 0;
}
static int parman_shrink(struct parman *parman)
{
unsigned long new_count = parman->limit_count -
parman->ops->resize_step;
int err;
if (new_count < parman->ops->base_count)
return 0;
err = parman->ops->resize(parman->priv, new_count);
if (err)
return err;
parman->limit_count = new_count;
return 0;
}
static bool parman_prio_used(struct parman_prio *prio)
{
return !list_empty(&prio->item_list);
}
static struct parman_item *parman_prio_first_item(struct parman_prio *prio)
{
return list_first_entry(&prio->item_list,
typeof(struct parman_item), list);
}
static unsigned long parman_prio_first_index(struct parman_prio *prio)
{
return parman_prio_first_item(prio)->index;
}
static struct parman_item *parman_prio_last_item(struct parman_prio *prio)
{
return list_last_entry(&prio->item_list,
typeof(struct parman_item), list);
}
static unsigned long parman_prio_last_index(struct parman_prio *prio)
{
return parman_prio_last_item(prio)->index;
}
static unsigned long parman_lsort_new_index_find(struct parman *parman,
struct parman_prio *prio)
{
list_for_each_entry_from_reverse(prio, &parman->prio_list, list) {
if (!parman_prio_used(prio))
continue;
return parman_prio_last_index(prio) + 1;
}
return 0;
}
static void __parman_prio_move(struct parman *parman, struct parman_prio *prio,
struct parman_item *item, unsigned long to_index,
unsigned long count)
{
parman->ops->move(parman->priv, item->index, to_index, count);
}
static void parman_prio_shift_down(struct parman *parman,
struct parman_prio *prio)
{
struct parman_item *item;
unsigned long to_index;
if (!parman_prio_used(prio))
return;
item = parman_prio_first_item(prio);
to_index = parman_prio_last_index(prio) + 1;
__parman_prio_move(parman, prio, item, to_index, 1);
list_move_tail(&item->list, &prio->item_list);
item->index = to_index;
}
static void parman_prio_shift_up(struct parman *parman,
struct parman_prio *prio)
{
struct parman_item *item;
unsigned long to_index;
if (!parman_prio_used(prio))
return;
item = parman_prio_last_item(prio);
to_index = parman_prio_first_index(prio) - 1;
__parman_prio_move(parman, prio, item, to_index, 1);
list_move(&item->list, &prio->item_list);
item->index = to_index;
}
static void parman_prio_item_remove(struct parman *parman,
struct parman_prio *prio,
struct parman_item *item)
{
struct parman_item *last_item;
unsigned long to_index;
last_item = parman_prio_last_item(prio);
if (last_item == item) {
list_del(&item->list);
return;
}
to_index = item->index;
__parman_prio_move(parman, prio, last_item, to_index, 1);
list_del(&last_item->list);
list_replace(&item->list, &last_item->list);
last_item->index = to_index;
}
static int parman_lsort_item_add(struct parman *parman,
struct parman_prio *prio,
struct parman_item *item)
{
struct parman_prio *prio2;
unsigned long new_index;
int err;
if (parman->count + 1 > parman->limit_count) {
err = parman_enlarge(parman);
if (err)
return err;
}
new_index = parman_lsort_new_index_find(parman, prio);
list_for_each_entry_reverse(prio2, &parman->prio_list, list) {
if (prio2 == prio)
break;
parman_prio_shift_down(parman, prio2);
}
item->index = new_index;
list_add_tail(&item->list, &prio->item_list);
parman->count++;
return 0;
}
static void parman_lsort_item_remove(struct parman *parman,
struct parman_prio *prio,
struct parman_item *item)
{
parman_prio_item_remove(parman, prio, item);
list_for_each_entry_continue(prio, &parman->prio_list, list)
parman_prio_shift_up(parman, prio);
parman->count--;
if (parman->limit_count - parman->count >= parman->ops->resize_step)
parman_shrink(parman);
}
struct parman *parman_create(const struct parman_ops *ops, void *priv)
{
struct parman *parman;
parman = kzalloc(sizeof(*parman), GFP_KERNEL);
if (!parman)
return NULL;
INIT_LIST_HEAD(&parman->prio_list);
parman->ops = ops;
parman->priv = priv;
parman->limit_count = ops->base_count;
parman->algo = parman_algos[ops->algo];
return parman;
}
void parman_destroy(struct parman *parman)
{
WARN_ON(!list_empty(&parman->prio_list));
kfree(parman);
}
void parman_prio_init(struct parman *parman, struct parman_prio *prio,
unsigned long priority)
{
struct parman_prio *prio2;
struct list_head *pos;
INIT_LIST_HEAD(&prio->item_list);
prio->priority = priority;
list_for_each(pos, &parman->prio_list) {
prio2 = list_entry(pos, typeof(*prio2), list);
if (prio2->priority > prio->priority)
break;
}
list_add_tail(&prio->list, pos);
}
void parman_prio_fini(struct parman_prio *prio)
{
WARN_ON(parman_prio_used(prio));
list_del(&prio->list);
}
int parman_item_add(struct parman *parman, struct parman_prio *prio,
struct parman_item *item)
{
return parman->algo->item_add(parman, prio, item);
}
void parman_item_remove(struct parman *parman, struct parman_prio *prio,
struct parman_item *item)
{
parman->algo->item_remove(parman, prio, item);
}
