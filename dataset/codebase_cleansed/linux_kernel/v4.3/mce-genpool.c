void mce_gen_pool_process(void)
{
struct llist_node *head;
struct mce_evt_llist *node;
struct mce *mce;
head = llist_del_all(&mce_event_llist);
if (!head)
return;
head = llist_reverse_order(head);
llist_for_each_entry(node, head, llnode) {
mce = &node->mce;
atomic_notifier_call_chain(&x86_mce_decoder_chain, 0, mce);
gen_pool_free(mce_evt_pool, (unsigned long)node, sizeof(*node));
}
}
bool mce_gen_pool_empty(void)
{
return llist_empty(&mce_event_llist);
}
int mce_gen_pool_add(struct mce *mce)
{
struct mce_evt_llist *node;
if (!mce_evt_pool)
return -EINVAL;
node = (void *)gen_pool_alloc(mce_evt_pool, sizeof(*node));
if (!node) {
pr_warn_ratelimited("MCE records pool full!\n");
return -ENOMEM;
}
memcpy(&node->mce, mce, sizeof(*mce));
llist_add(&node->llnode, &mce_event_llist);
return 0;
}
static int mce_gen_pool_create(void)
{
struct gen_pool *tmpp;
int ret = -ENOMEM;
tmpp = gen_pool_create(ilog2(sizeof(struct mce_evt_llist)), -1);
if (!tmpp)
goto out;
ret = gen_pool_add(tmpp, (unsigned long)gen_pool_buf, MCE_POOLSZ, -1);
if (ret) {
gen_pool_destroy(tmpp);
goto out;
}
mce_evt_pool = tmpp;
out:
return ret;
}
int mce_gen_pool_init(void)
{
if (mce_evt_pool)
return 0;
return mce_gen_pool_create();
}
