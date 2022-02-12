static int
nfp_devlink_fill_eth_port(struct nfp_port *port,
struct nfp_eth_table_port *copy)
{
struct nfp_eth_table_port *eth_port;
eth_port = __nfp_port_get_eth_port(port);
if (!eth_port)
return -EINVAL;
memcpy(copy, eth_port, sizeof(*eth_port));
return 0;
}
static int
nfp_devlink_fill_eth_port_from_id(struct nfp_pf *pf, unsigned int port_index,
struct nfp_eth_table_port *copy)
{
struct nfp_port *port;
port = nfp_port_from_id(pf, NFP_PORT_PHYS_PORT, port_index);
return nfp_devlink_fill_eth_port(port, copy);
}
static int
nfp_devlink_set_lanes(struct nfp_pf *pf, unsigned int idx, unsigned int lanes)
{
struct nfp_nsp *nsp;
int ret;
nsp = nfp_eth_config_start(pf->cpp, idx);
if (IS_ERR(nsp))
return PTR_ERR(nsp);
ret = __nfp_eth_set_split(nsp, lanes);
if (ret) {
nfp_eth_config_cleanup_end(nsp);
return ret;
}
ret = nfp_eth_config_commit_end(nsp);
if (ret < 0)
return ret;
if (ret)
return 0;
return nfp_net_refresh_port_table_sync(pf);
}
static int
nfp_devlink_port_split(struct devlink *devlink, unsigned int port_index,
unsigned int count)
{
struct nfp_pf *pf = devlink_priv(devlink);
struct nfp_eth_table_port eth_port;
int ret;
if (count < 2)
return -EINVAL;
mutex_lock(&pf->lock);
rtnl_lock();
ret = nfp_devlink_fill_eth_port_from_id(pf, port_index, &eth_port);
rtnl_unlock();
if (ret)
goto out;
if (eth_port.is_split || eth_port.port_lanes % count) {
ret = -EINVAL;
goto out;
}
ret = nfp_devlink_set_lanes(pf, eth_port.index,
eth_port.port_lanes / count);
out:
mutex_unlock(&pf->lock);
return ret;
}
static int
nfp_devlink_port_unsplit(struct devlink *devlink, unsigned int port_index)
{
struct nfp_pf *pf = devlink_priv(devlink);
struct nfp_eth_table_port eth_port;
int ret;
mutex_lock(&pf->lock);
rtnl_lock();
ret = nfp_devlink_fill_eth_port_from_id(pf, port_index, &eth_port);
rtnl_unlock();
if (ret)
goto out;
if (!eth_port.is_split) {
ret = -EINVAL;
goto out;
}
ret = nfp_devlink_set_lanes(pf, eth_port.index, eth_port.port_lanes);
out:
mutex_unlock(&pf->lock);
return ret;
}
static int nfp_devlink_eswitch_mode_get(struct devlink *devlink, u16 *mode)
{
struct nfp_pf *pf = devlink_priv(devlink);
int ret;
mutex_lock(&pf->lock);
if (!pf->app) {
ret = -EBUSY;
goto out;
}
ret = nfp_app_eswitch_mode_get(pf->app, mode);
out:
mutex_unlock(&pf->lock);
return ret;
}
int nfp_devlink_port_register(struct nfp_app *app, struct nfp_port *port)
{
struct nfp_eth_table_port eth_port;
struct devlink *devlink;
int ret;
rtnl_lock();
ret = nfp_devlink_fill_eth_port(port, &eth_port);
rtnl_unlock();
if (ret)
return ret;
devlink_port_type_eth_set(&port->dl_port, port->netdev);
if (eth_port.is_split)
devlink_port_split_set(&port->dl_port, eth_port.label_port);
devlink = priv_to_devlink(app->pf);
return devlink_port_register(devlink, &port->dl_port, port->eth_id);
}
void nfp_devlink_port_unregister(struct nfp_port *port)
{
devlink_port_unregister(&port->dl_port);
}
