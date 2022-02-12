struct nfp_app *nfp_app_from_netdev(struct net_device *netdev)
{
if (nfp_netdev_is_nfp_net(netdev)) {
struct nfp_net *nn = netdev_priv(netdev);
return nn->app;
}
if (nfp_netdev_is_nfp_repr(netdev)) {
struct nfp_repr *repr = netdev_priv(netdev);
return repr->app;
}
WARN(1, "Unknown netdev type for nfp_app\n");
return NULL;
}
const char *nfp_app_mip_name(struct nfp_app *app)
{
if (!app || !app->pf->mip)
return "";
return nfp_mip_name(app->pf->mip);
}
struct sk_buff *
nfp_app_ctrl_msg_alloc(struct nfp_app *app, unsigned int size, gfp_t priority)
{
struct sk_buff *skb;
if (nfp_app_ctrl_has_meta(app))
size += 8;
skb = alloc_skb(size, priority);
if (!skb)
return NULL;
if (nfp_app_ctrl_has_meta(app))
skb_reserve(skb, 8);
return skb;
}
struct nfp_reprs *
nfp_app_reprs_set(struct nfp_app *app, enum nfp_repr_type type,
struct nfp_reprs *reprs)
{
struct nfp_reprs *old;
old = rcu_dereference_protected(app->reprs[type],
lockdep_is_held(&app->pf->lock));
if (reprs && old) {
old = ERR_PTR(-EBUSY);
goto exit_unlock;
}
rcu_assign_pointer(app->reprs[type], reprs);
exit_unlock:
return old;
}
struct nfp_app *nfp_app_alloc(struct nfp_pf *pf, enum nfp_app_id id)
{
struct nfp_app *app;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(apps); i++)
if (apps[i]->id == id)
break;
if (i == ARRAY_SIZE(apps)) {
nfp_err(pf->cpp, "failed to find app with ID 0x%02hhx\n", id);
return ERR_PTR(-EINVAL);
}
if (WARN_ON(!apps[i]->name || !apps[i]->vnic_alloc))
return ERR_PTR(-EINVAL);
app = kzalloc(sizeof(*app), GFP_KERNEL);
if (!app)
return ERR_PTR(-ENOMEM);
app->pf = pf;
app->cpp = pf->cpp;
app->pdev = pf->pdev;
app->type = apps[i];
return app;
}
void nfp_app_free(struct nfp_app *app)
{
kfree(app);
}
