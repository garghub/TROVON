static struct v4l2_clk *v4l2_clk_find(const char *dev_id, const char *id)
{
struct v4l2_clk *clk;
list_for_each_entry(clk, &clk_list, list) {
if (strcmp(dev_id, clk->dev_id))
continue;
if (!id || !clk->id || !strcmp(clk->id, id))
return clk;
}
return ERR_PTR(-ENODEV);
}
struct v4l2_clk *v4l2_clk_get(struct device *dev, const char *id)
{
struct v4l2_clk *clk;
mutex_lock(&clk_lock);
clk = v4l2_clk_find(dev_name(dev), id);
if (!IS_ERR(clk))
atomic_inc(&clk->use_count);
mutex_unlock(&clk_lock);
return clk;
}
void v4l2_clk_put(struct v4l2_clk *clk)
{
struct v4l2_clk *tmp;
if (IS_ERR(clk))
return;
mutex_lock(&clk_lock);
list_for_each_entry(tmp, &clk_list, list)
if (tmp == clk)
atomic_dec(&clk->use_count);
mutex_unlock(&clk_lock);
}
static int v4l2_clk_lock_driver(struct v4l2_clk *clk)
{
struct v4l2_clk *tmp;
int ret = -ENODEV;
mutex_lock(&clk_lock);
list_for_each_entry(tmp, &clk_list, list)
if (tmp == clk) {
ret = !try_module_get(clk->ops->owner);
if (ret)
ret = -EFAULT;
break;
}
mutex_unlock(&clk_lock);
return ret;
}
static void v4l2_clk_unlock_driver(struct v4l2_clk *clk)
{
module_put(clk->ops->owner);
}
int v4l2_clk_enable(struct v4l2_clk *clk)
{
int ret = v4l2_clk_lock_driver(clk);
if (ret < 0)
return ret;
mutex_lock(&clk->lock);
if (++clk->enable == 1 && clk->ops->enable) {
ret = clk->ops->enable(clk);
if (ret < 0)
clk->enable--;
}
mutex_unlock(&clk->lock);
return ret;
}
void v4l2_clk_disable(struct v4l2_clk *clk)
{
int enable;
mutex_lock(&clk->lock);
enable = --clk->enable;
if (WARN(enable < 0, "Unbalanced %s() on %s:%s!\n", __func__,
clk->dev_id, clk->id))
clk->enable++;
else if (!enable && clk->ops->disable)
clk->ops->disable(clk);
mutex_unlock(&clk->lock);
v4l2_clk_unlock_driver(clk);
}
unsigned long v4l2_clk_get_rate(struct v4l2_clk *clk)
{
int ret = v4l2_clk_lock_driver(clk);
if (ret < 0)
return ret;
mutex_lock(&clk->lock);
if (!clk->ops->get_rate)
ret = -ENOSYS;
else
ret = clk->ops->get_rate(clk);
mutex_unlock(&clk->lock);
v4l2_clk_unlock_driver(clk);
return ret;
}
int v4l2_clk_set_rate(struct v4l2_clk *clk, unsigned long rate)
{
int ret = v4l2_clk_lock_driver(clk);
if (ret < 0)
return ret;
mutex_lock(&clk->lock);
if (!clk->ops->set_rate)
ret = -ENOSYS;
else
ret = clk->ops->set_rate(clk, rate);
mutex_unlock(&clk->lock);
v4l2_clk_unlock_driver(clk);
return ret;
}
struct v4l2_clk *v4l2_clk_register(const struct v4l2_clk_ops *ops,
const char *dev_id,
const char *id, void *priv)
{
struct v4l2_clk *clk;
int ret;
if (!ops || !dev_id)
return ERR_PTR(-EINVAL);
clk = kzalloc(sizeof(struct v4l2_clk), GFP_KERNEL);
if (!clk)
return ERR_PTR(-ENOMEM);
clk->id = kstrdup(id, GFP_KERNEL);
clk->dev_id = kstrdup(dev_id, GFP_KERNEL);
if ((id && !clk->id) || !clk->dev_id) {
ret = -ENOMEM;
goto ealloc;
}
clk->ops = ops;
clk->priv = priv;
atomic_set(&clk->use_count, 0);
mutex_init(&clk->lock);
mutex_lock(&clk_lock);
if (!IS_ERR(v4l2_clk_find(dev_id, id))) {
mutex_unlock(&clk_lock);
ret = -EEXIST;
goto eexist;
}
list_add_tail(&clk->list, &clk_list);
mutex_unlock(&clk_lock);
return clk;
eexist:
ealloc:
kfree(clk->id);
kfree(clk->dev_id);
kfree(clk);
return ERR_PTR(ret);
}
void v4l2_clk_unregister(struct v4l2_clk *clk)
{
if (WARN(atomic_read(&clk->use_count),
"%s(): Refusing to unregister ref-counted %s:%s clock!\n",
__func__, clk->dev_id, clk->id))
return;
mutex_lock(&clk_lock);
list_del(&clk->list);
mutex_unlock(&clk_lock);
kfree(clk->id);
kfree(clk->dev_id);
kfree(clk);
}
static unsigned long fixed_get_rate(struct v4l2_clk *clk)
{
struct v4l2_clk_fixed *priv = clk->priv;
return priv->rate;
}
struct v4l2_clk *__v4l2_clk_register_fixed(const char *dev_id,
const char *id, unsigned long rate, struct module *owner)
{
struct v4l2_clk *clk;
struct v4l2_clk_fixed *priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return ERR_PTR(-ENOMEM);
priv->rate = rate;
priv->ops.get_rate = fixed_get_rate;
priv->ops.owner = owner;
clk = v4l2_clk_register(&priv->ops, dev_id, id, priv);
if (IS_ERR(clk))
kfree(priv);
return clk;
}
void v4l2_clk_unregister_fixed(struct v4l2_clk *clk)
{
kfree(clk->priv);
v4l2_clk_unregister(clk);
}
