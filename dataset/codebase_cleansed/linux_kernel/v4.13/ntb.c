int __ntb_register_client(struct ntb_client *client, struct module *mod,
const char *mod_name)
{
if (!client)
return -EINVAL;
if (!ntb_client_ops_is_valid(&client->ops))
return -EINVAL;
memset(&client->drv, 0, sizeof(client->drv));
client->drv.bus = &ntb_bus;
client->drv.name = mod_name;
client->drv.owner = mod;
return driver_register(&client->drv);
}
void ntb_unregister_client(struct ntb_client *client)
{
driver_unregister(&client->drv);
}
int ntb_register_device(struct ntb_dev *ntb)
{
if (!ntb)
return -EINVAL;
if (!ntb->pdev)
return -EINVAL;
if (!ntb->ops)
return -EINVAL;
if (!ntb_dev_ops_is_valid(ntb->ops))
return -EINVAL;
init_completion(&ntb->released);
memset(&ntb->dev, 0, sizeof(ntb->dev));
ntb->dev.bus = &ntb_bus;
ntb->dev.parent = &ntb->pdev->dev;
ntb->dev.release = ntb_dev_release;
dev_set_name(&ntb->dev, "%s", pci_name(ntb->pdev));
ntb->ctx = NULL;
ntb->ctx_ops = NULL;
spin_lock_init(&ntb->ctx_lock);
return device_register(&ntb->dev);
}
void ntb_unregister_device(struct ntb_dev *ntb)
{
device_unregister(&ntb->dev);
wait_for_completion(&ntb->released);
}
int ntb_set_ctx(struct ntb_dev *ntb, void *ctx,
const struct ntb_ctx_ops *ctx_ops)
{
unsigned long irqflags;
if (!ntb_ctx_ops_is_valid(ctx_ops))
return -EINVAL;
if (ntb->ctx_ops)
return -EINVAL;
spin_lock_irqsave(&ntb->ctx_lock, irqflags);
{
ntb->ctx = ctx;
ntb->ctx_ops = ctx_ops;
}
spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
return 0;
}
void ntb_clear_ctx(struct ntb_dev *ntb)
{
unsigned long irqflags;
spin_lock_irqsave(&ntb->ctx_lock, irqflags);
{
ntb->ctx_ops = NULL;
ntb->ctx = NULL;
}
spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}
void ntb_link_event(struct ntb_dev *ntb)
{
unsigned long irqflags;
spin_lock_irqsave(&ntb->ctx_lock, irqflags);
{
if (ntb->ctx_ops && ntb->ctx_ops->link_event)
ntb->ctx_ops->link_event(ntb->ctx);
}
spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}
void ntb_db_event(struct ntb_dev *ntb, int vector)
{
unsigned long irqflags;
spin_lock_irqsave(&ntb->ctx_lock, irqflags);
{
if (ntb->ctx_ops && ntb->ctx_ops->db_event)
ntb->ctx_ops->db_event(ntb->ctx, vector);
}
spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}
void ntb_msg_event(struct ntb_dev *ntb)
{
unsigned long irqflags;
spin_lock_irqsave(&ntb->ctx_lock, irqflags);
{
if (ntb->ctx_ops && ntb->ctx_ops->msg_event)
ntb->ctx_ops->msg_event(ntb->ctx);
}
spin_unlock_irqrestore(&ntb->ctx_lock, irqflags);
}
int ntb_default_port_number(struct ntb_dev *ntb)
{
switch (ntb->topo) {
case NTB_TOPO_PRI:
case NTB_TOPO_B2B_USD:
return NTB_PORT_PRI_USD;
case NTB_TOPO_SEC:
case NTB_TOPO_B2B_DSD:
return NTB_PORT_SEC_DSD;
default:
break;
}
return -EINVAL;
}
int ntb_default_peer_port_count(struct ntb_dev *ntb)
{
return NTB_DEF_PEER_CNT;
}
int ntb_default_peer_port_number(struct ntb_dev *ntb, int pidx)
{
if (pidx != NTB_DEF_PEER_IDX)
return -EINVAL;
switch (ntb->topo) {
case NTB_TOPO_PRI:
case NTB_TOPO_B2B_USD:
return NTB_PORT_SEC_DSD;
case NTB_TOPO_SEC:
case NTB_TOPO_B2B_DSD:
return NTB_PORT_PRI_USD;
default:
break;
}
return -EINVAL;
}
int ntb_default_peer_port_idx(struct ntb_dev *ntb, int port)
{
int peer_port = ntb_default_peer_port_number(ntb, NTB_DEF_PEER_IDX);
if (peer_port == -EINVAL || port != peer_port)
return -EINVAL;
return 0;
}
static int ntb_probe(struct device *dev)
{
struct ntb_dev *ntb;
struct ntb_client *client;
int rc;
get_device(dev);
ntb = dev_ntb(dev);
client = drv_ntb_client(dev->driver);
rc = client->ops.probe(client, ntb);
if (rc)
put_device(dev);
return rc;
}
static int ntb_remove(struct device *dev)
{
struct ntb_dev *ntb;
struct ntb_client *client;
if (dev->driver) {
ntb = dev_ntb(dev);
client = drv_ntb_client(dev->driver);
client->ops.remove(client, ntb);
put_device(dev);
}
return 0;
}
static void ntb_dev_release(struct device *dev)
{
struct ntb_dev *ntb = dev_ntb(dev);
complete(&ntb->released);
}
static int __init ntb_driver_init(void)
{
return bus_register(&ntb_bus);
}
static void __exit ntb_driver_exit(void)
{
bus_unregister(&ntb_bus);
}
