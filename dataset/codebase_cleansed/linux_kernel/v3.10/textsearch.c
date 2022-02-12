static inline struct ts_ops *lookup_ts_algo(const char *name)
{
struct ts_ops *o;
rcu_read_lock();
list_for_each_entry_rcu(o, &ts_ops, list) {
if (!strcmp(name, o->name)) {
if (!try_module_get(o->owner))
o = NULL;
rcu_read_unlock();
return o;
}
}
rcu_read_unlock();
return NULL;
}
int textsearch_register(struct ts_ops *ops)
{
int err = -EEXIST;
struct ts_ops *o;
if (ops->name == NULL || ops->find == NULL || ops->init == NULL ||
ops->get_pattern == NULL || ops->get_pattern_len == NULL)
return -EINVAL;
spin_lock(&ts_mod_lock);
list_for_each_entry(o, &ts_ops, list) {
if (!strcmp(ops->name, o->name))
goto errout;
}
list_add_tail_rcu(&ops->list, &ts_ops);
err = 0;
errout:
spin_unlock(&ts_mod_lock);
return err;
}
int textsearch_unregister(struct ts_ops *ops)
{
int err = 0;
struct ts_ops *o;
spin_lock(&ts_mod_lock);
list_for_each_entry(o, &ts_ops, list) {
if (o == ops) {
list_del_rcu(&o->list);
goto out;
}
}
err = -ENOENT;
out:
spin_unlock(&ts_mod_lock);
return err;
}
static unsigned int get_linear_data(unsigned int consumed, const u8 **dst,
struct ts_config *conf,
struct ts_state *state)
{
struct ts_linear_state *st = (struct ts_linear_state *) state->cb;
if (likely(consumed < st->len)) {
*dst = st->data + consumed;
return st->len - consumed;
}
return 0;
}
unsigned int textsearch_find_continuous(struct ts_config *conf,
struct ts_state *state,
const void *data, unsigned int len)
{
struct ts_linear_state *st = (struct ts_linear_state *) state->cb;
conf->get_next_block = get_linear_data;
st->data = data;
st->len = len;
return textsearch_find(conf, state);
}
struct ts_config *textsearch_prepare(const char *algo, const void *pattern,
unsigned int len, gfp_t gfp_mask, int flags)
{
int err = -ENOENT;
struct ts_config *conf;
struct ts_ops *ops;
if (len == 0)
return ERR_PTR(-EINVAL);
ops = lookup_ts_algo(algo);
#ifdef CONFIG_MODULES
if (ops == NULL && flags & TS_AUTOLOAD) {
request_module("ts_%s", algo);
ops = lookup_ts_algo(algo);
}
#endif
if (ops == NULL)
goto errout;
conf = ops->init(pattern, len, gfp_mask, flags);
if (IS_ERR(conf)) {
err = PTR_ERR(conf);
goto errout;
}
conf->ops = ops;
return conf;
errout:
if (ops)
module_put(ops->owner);
return ERR_PTR(err);
}
void textsearch_destroy(struct ts_config *conf)
{
if (conf->ops) {
if (conf->ops->destroy)
conf->ops->destroy(conf);
module_put(conf->ops->owner);
}
kfree(conf);
}
