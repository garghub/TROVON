int __opal_async_get_token(void)
{
unsigned long flags;
int token;
spin_lock_irqsave(&opal_async_comp_lock, flags);
token = find_first_bit(opal_async_complete_map, opal_max_async_tokens);
if (token >= opal_max_async_tokens) {
token = -EBUSY;
goto out;
}
if (__test_and_set_bit(token, opal_async_token_map)) {
token = -EBUSY;
goto out;
}
__clear_bit(token, opal_async_complete_map);
out:
spin_unlock_irqrestore(&opal_async_comp_lock, flags);
return token;
}
int opal_async_get_token_interruptible(void)
{
int token;
if (down_interruptible(&opal_async_sem))
return -ERESTARTSYS;
token = __opal_async_get_token();
if (token < 0)
up(&opal_async_sem);
return token;
}
int __opal_async_release_token(int token)
{
unsigned long flags;
if (token < 0 || token >= opal_max_async_tokens) {
pr_err("%s: Passed token is out of range, token %d\n",
__func__, token);
return -EINVAL;
}
spin_lock_irqsave(&opal_async_comp_lock, flags);
__set_bit(token, opal_async_complete_map);
__clear_bit(token, opal_async_token_map);
spin_unlock_irqrestore(&opal_async_comp_lock, flags);
return 0;
}
int opal_async_release_token(int token)
{
int ret;
ret = __opal_async_release_token(token);
if (ret)
return ret;
up(&opal_async_sem);
return 0;
}
int opal_async_wait_response(uint64_t token, struct opal_msg *msg)
{
if (token >= opal_max_async_tokens) {
pr_err("%s: Invalid token passed\n", __func__);
return -EINVAL;
}
if (!msg) {
pr_err("%s: Invalid message pointer passed\n", __func__);
return -EINVAL;
}
wait_event(opal_async_wait, test_bit(token, opal_async_complete_map));
memcpy(msg, &opal_async_responses[token], sizeof(*msg));
return 0;
}
static int opal_async_comp_event(struct notifier_block *nb,
unsigned long msg_type, void *msg)
{
struct opal_msg *comp_msg = msg;
unsigned long flags;
uint64_t token;
if (msg_type != OPAL_MSG_ASYNC_COMP)
return 0;
token = be64_to_cpu(comp_msg->params[0]);
memcpy(&opal_async_responses[token], comp_msg, sizeof(*comp_msg));
spin_lock_irqsave(&opal_async_comp_lock, flags);
__set_bit(token, opal_async_complete_map);
spin_unlock_irqrestore(&opal_async_comp_lock, flags);
wake_up(&opal_async_wait);
return 0;
}
static int __init opal_async_comp_init(void)
{
struct device_node *opal_node;
const __be32 *async;
int err;
opal_node = of_find_node_by_path("/ibm,opal");
if (!opal_node) {
pr_err("%s: Opal node not found\n", __func__);
err = -ENOENT;
goto out;
}
async = of_get_property(opal_node, "opal-msg-async-num", NULL);
if (!async) {
pr_err("%s: %s has no opal-msg-async-num\n",
__func__, opal_node->full_name);
err = -ENOENT;
goto out_opal_node;
}
opal_max_async_tokens = be32_to_cpup(async);
if (opal_max_async_tokens > N_ASYNC_COMPLETIONS)
opal_max_async_tokens = N_ASYNC_COMPLETIONS;
err = opal_message_notifier_register(OPAL_MSG_ASYNC_COMP,
&opal_async_comp_nb);
if (err) {
pr_err("%s: Can't register OPAL event notifier (%d)\n",
__func__, err);
goto out_opal_node;
}
opal_async_responses = kzalloc(
sizeof(*opal_async_responses) * opal_max_async_tokens,
GFP_KERNEL);
if (!opal_async_responses) {
pr_err("%s: Out of memory, failed to do asynchronous "
"completion init\n", __func__);
err = -ENOMEM;
goto out_opal_node;
}
sema_init(&opal_async_sem, opal_max_async_tokens - 1);
out_opal_node:
of_node_put(opal_node);
out:
return err;
}
