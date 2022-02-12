static struct ib_agent_port_private *
__ib_get_agent_port(struct ib_device *device, int port_num)
{
struct ib_agent_port_private *entry;
list_for_each_entry(entry, &ib_agent_port_list, port_list) {
if (entry->agent[1]->device == device &&
entry->agent[1]->port_num == port_num)
return entry;
}
return NULL;
}
static struct ib_agent_port_private *
ib_get_agent_port(struct ib_device *device, int port_num)
{
struct ib_agent_port_private *entry;
unsigned long flags;
spin_lock_irqsave(&ib_agent_port_list_lock, flags);
entry = __ib_get_agent_port(device, port_num);
spin_unlock_irqrestore(&ib_agent_port_list_lock, flags);
return entry;
}
void agent_send_response(struct ib_mad *mad, struct ib_grh *grh,
struct ib_wc *wc, struct ib_device *device,
int port_num, int qpn)
{
struct ib_agent_port_private *port_priv;
struct ib_mad_agent *agent;
struct ib_mad_send_buf *send_buf;
struct ib_ah *ah;
struct ib_mad_send_wr_private *mad_send_wr;
if (device->node_type == RDMA_NODE_IB_SWITCH)
port_priv = ib_get_agent_port(device, 0);
else
port_priv = ib_get_agent_port(device, port_num);
if (!port_priv) {
dev_err(&device->dev, "Unable to find port agent\n");
return;
}
agent = port_priv->agent[qpn];
ah = ib_create_ah_from_wc(agent->qp->pd, wc, grh, port_num);
if (IS_ERR(ah)) {
dev_err(&device->dev, "ib_create_ah_from_wc error %ld\n",
PTR_ERR(ah));
return;
}
send_buf = ib_create_send_mad(agent, wc->src_qp, wc->pkey_index, 0,
IB_MGMT_MAD_HDR, IB_MGMT_MAD_DATA,
GFP_KERNEL);
if (IS_ERR(send_buf)) {
dev_err(&device->dev, "ib_create_send_mad error\n");
goto err1;
}
memcpy(send_buf->mad, mad, sizeof *mad);
send_buf->ah = ah;
if (device->node_type == RDMA_NODE_IB_SWITCH) {
mad_send_wr = container_of(send_buf,
struct ib_mad_send_wr_private,
send_buf);
mad_send_wr->send_wr.wr.ud.port_num = port_num;
}
if (ib_post_send_mad(send_buf, NULL)) {
dev_err(&device->dev, "ib_post_send_mad error\n");
goto err2;
}
return;
err2:
ib_free_send_mad(send_buf);
err1:
ib_destroy_ah(ah);
}
static void agent_send_handler(struct ib_mad_agent *mad_agent,
struct ib_mad_send_wc *mad_send_wc)
{
ib_destroy_ah(mad_send_wc->send_buf->ah);
ib_free_send_mad(mad_send_wc->send_buf);
}
int ib_agent_port_open(struct ib_device *device, int port_num)
{
struct ib_agent_port_private *port_priv;
unsigned long flags;
int ret;
port_priv = kzalloc(sizeof *port_priv, GFP_KERNEL);
if (!port_priv) {
dev_err(&device->dev, "No memory for ib_agent_port_private\n");
ret = -ENOMEM;
goto error1;
}
if (rdma_port_get_link_layer(device, port_num) == IB_LINK_LAYER_INFINIBAND) {
port_priv->agent[0] = ib_register_mad_agent(device, port_num,
IB_QPT_SMI, NULL, 0,
&agent_send_handler,
NULL, NULL, 0);
if (IS_ERR(port_priv->agent[0])) {
ret = PTR_ERR(port_priv->agent[0]);
goto error2;
}
}
port_priv->agent[1] = ib_register_mad_agent(device, port_num,
IB_QPT_GSI, NULL, 0,
&agent_send_handler,
NULL, NULL, 0);
if (IS_ERR(port_priv->agent[1])) {
ret = PTR_ERR(port_priv->agent[1]);
goto error3;
}
spin_lock_irqsave(&ib_agent_port_list_lock, flags);
list_add_tail(&port_priv->port_list, &ib_agent_port_list);
spin_unlock_irqrestore(&ib_agent_port_list_lock, flags);
return 0;
error3:
if (port_priv->agent[0])
ib_unregister_mad_agent(port_priv->agent[0]);
error2:
kfree(port_priv);
error1:
return ret;
}
int ib_agent_port_close(struct ib_device *device, int port_num)
{
struct ib_agent_port_private *port_priv;
unsigned long flags;
spin_lock_irqsave(&ib_agent_port_list_lock, flags);
port_priv = __ib_get_agent_port(device, port_num);
if (port_priv == NULL) {
spin_unlock_irqrestore(&ib_agent_port_list_lock, flags);
dev_err(&device->dev, "Port %d not found\n", port_num);
return -ENODEV;
}
list_del(&port_priv->port_list);
spin_unlock_irqrestore(&ib_agent_port_list_lock, flags);
ib_unregister_mad_agent(port_priv->agent[1]);
if (port_priv->agent[0])
ib_unregister_mad_agent(port_priv->agent[0]);
kfree(port_priv);
return 0;
}
