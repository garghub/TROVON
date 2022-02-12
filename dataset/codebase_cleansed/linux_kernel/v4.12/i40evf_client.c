void i40evf_notify_client_message(struct i40e_vsi *vsi, u8 *msg, u16 len)
{
struct i40e_client_instance *cinst;
if (!vsi)
return;
cinst = vsi->back->cinst;
if (!cinst || !cinst->client || !cinst->client->ops ||
!cinst->client->ops->virtchnl_receive) {
dev_dbg(&vsi->back->pdev->dev,
"Cannot locate client instance virtchnl_receive function\n");
return;
}
cinst->client->ops->virtchnl_receive(&cinst->lan_info, cinst->client,
msg, len);
}
void i40evf_notify_client_l2_params(struct i40e_vsi *vsi)
{
struct i40e_client_instance *cinst;
struct i40e_params params;
if (!vsi)
return;
cinst = vsi->back->cinst;
memset(&params, 0, sizeof(params));
params.mtu = vsi->netdev->mtu;
params.link_up = vsi->back->link_up;
params.qos.prio_qos[0].qs_handle = vsi->qs_handle;
if (!cinst || !cinst->client || !cinst->client->ops ||
!cinst->client->ops->l2_param_change) {
dev_dbg(&vsi->back->pdev->dev,
"Cannot locate client instance l2_param_change function\n");
return;
}
cinst->client->ops->l2_param_change(&cinst->lan_info, cinst->client,
&params);
}
void i40evf_notify_client_open(struct i40e_vsi *vsi)
{
struct i40evf_adapter *adapter = vsi->back;
struct i40e_client_instance *cinst = adapter->cinst;
int ret;
if (!cinst || !cinst->client || !cinst->client->ops ||
!cinst->client->ops->open) {
dev_dbg(&vsi->back->pdev->dev,
"Cannot locate client instance open function\n");
return;
}
if (!(test_bit(__I40E_CLIENT_INSTANCE_OPENED, &cinst->state))) {
ret = cinst->client->ops->open(&cinst->lan_info, cinst->client);
if (!ret)
set_bit(__I40E_CLIENT_INSTANCE_OPENED, &cinst->state);
}
}
static int i40evf_client_release_qvlist(struct i40e_info *ldev)
{
struct i40evf_adapter *adapter = ldev->vf;
i40e_status err;
if (adapter->aq_required)
return -EAGAIN;
err = i40e_aq_send_msg_to_pf(&adapter->hw,
I40E_VIRTCHNL_OP_RELEASE_IWARP_IRQ_MAP,
I40E_SUCCESS, NULL, 0, NULL);
if (err)
dev_err(&adapter->pdev->dev,
"Unable to send iWarp vector release message to PF, error %d, aq status %d\n",
err, adapter->hw.aq.asq_last_status);
return err;
}
void i40evf_notify_client_close(struct i40e_vsi *vsi, bool reset)
{
struct i40evf_adapter *adapter = vsi->back;
struct i40e_client_instance *cinst = adapter->cinst;
if (!cinst || !cinst->client || !cinst->client->ops ||
!cinst->client->ops->close) {
dev_dbg(&vsi->back->pdev->dev,
"Cannot locate client instance close function\n");
return;
}
cinst->client->ops->close(&cinst->lan_info, cinst->client, reset);
i40evf_client_release_qvlist(&cinst->lan_info);
clear_bit(__I40E_CLIENT_INSTANCE_OPENED, &cinst->state);
}
static struct i40e_client_instance *
i40evf_client_add_instance(struct i40evf_adapter *adapter)
{
struct i40e_client_instance *cinst = NULL;
struct netdev_hw_addr *mac = NULL;
struct i40e_vsi *vsi = &adapter->vsi;
int i;
if (!vf_registered_client)
goto out;
if (adapter->cinst) {
cinst = adapter->cinst;
goto out;
}
cinst = kzalloc(sizeof(*cinst), GFP_KERNEL);
if (!cinst)
goto out;
cinst->lan_info.vf = (void *)adapter;
cinst->lan_info.netdev = vsi->netdev;
cinst->lan_info.pcidev = adapter->pdev;
cinst->lan_info.fid = 0;
cinst->lan_info.ftype = I40E_CLIENT_FTYPE_VF;
cinst->lan_info.hw_addr = adapter->hw.hw_addr;
cinst->lan_info.ops = &i40evf_lan_ops;
cinst->lan_info.version.major = I40EVF_CLIENT_VERSION_MAJOR;
cinst->lan_info.version.minor = I40EVF_CLIENT_VERSION_MINOR;
cinst->lan_info.version.build = I40EVF_CLIENT_VERSION_BUILD;
set_bit(__I40E_CLIENT_INSTANCE_NONE, &cinst->state);
cinst->lan_info.msix_count = adapter->num_iwarp_msix;
cinst->lan_info.msix_entries =
&adapter->msix_entries[adapter->iwarp_base_vector];
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++) {
cinst->lan_info.params.qos.prio_qos[i].tc = 0;
cinst->lan_info.params.qos.prio_qos[i].qs_handle =
vsi->qs_handle;
}
mac = list_first_entry(&cinst->lan_info.netdev->dev_addrs.list,
struct netdev_hw_addr, list);
if (mac)
ether_addr_copy(cinst->lan_info.lanmac, mac->addr);
else
dev_err(&adapter->pdev->dev, "MAC address list is empty!\n");
cinst->client = vf_registered_client;
adapter->cinst = cinst;
out:
return cinst;
}
static
void i40evf_client_del_instance(struct i40evf_adapter *adapter)
{
kfree(adapter->cinst);
adapter->cinst = NULL;
}
void i40evf_client_subtask(struct i40evf_adapter *adapter)
{
struct i40e_client *client = vf_registered_client;
struct i40e_client_instance *cinst;
int ret = 0;
if (adapter->state < __I40EVF_DOWN)
return;
if (!client)
return;
cinst = i40evf_client_add_instance(adapter);
if (!cinst)
return;
dev_info(&adapter->pdev->dev, "Added instance of Client %s\n",
client->name);
if (!test_bit(__I40E_CLIENT_INSTANCE_OPENED, &cinst->state)) {
if (client->ops && client->ops->open)
ret = client->ops->open(&cinst->lan_info, client);
if (!ret)
set_bit(__I40E_CLIENT_INSTANCE_OPENED,
&cinst->state);
else
i40evf_client_del_instance(adapter);
}
}
int i40evf_lan_add_device(struct i40evf_adapter *adapter)
{
struct i40e_device *ldev;
int ret = 0;
mutex_lock(&i40evf_device_mutex);
list_for_each_entry(ldev, &i40evf_devices, list) {
if (ldev->vf == adapter) {
ret = -EEXIST;
goto out;
}
}
ldev = kzalloc(sizeof(*ldev), GFP_KERNEL);
if (!ldev) {
ret = -ENOMEM;
goto out;
}
ldev->vf = adapter;
INIT_LIST_HEAD(&ldev->list);
list_add(&ldev->list, &i40evf_devices);
dev_info(&adapter->pdev->dev, "Added LAN device bus=0x%02x dev=0x%02x func=0x%02x\n",
adapter->hw.bus.bus_id, adapter->hw.bus.device,
adapter->hw.bus.func);
adapter->flags |= I40EVF_FLAG_SERVICE_CLIENT_REQUESTED;
out:
mutex_unlock(&i40evf_device_mutex);
return ret;
}
int i40evf_lan_del_device(struct i40evf_adapter *adapter)
{
struct i40e_device *ldev, *tmp;
int ret = -ENODEV;
mutex_lock(&i40evf_device_mutex);
list_for_each_entry_safe(ldev, tmp, &i40evf_devices, list) {
if (ldev->vf == adapter) {
dev_info(&adapter->pdev->dev,
"Deleted LAN device bus=0x%02x dev=0x%02x func=0x%02x\n",
adapter->hw.bus.bus_id, adapter->hw.bus.device,
adapter->hw.bus.func);
list_del(&ldev->list);
kfree(ldev);
ret = 0;
break;
}
}
mutex_unlock(&i40evf_device_mutex);
return ret;
}
static void i40evf_client_release(struct i40e_client *client)
{
struct i40e_client_instance *cinst;
struct i40e_device *ldev;
struct i40evf_adapter *adapter;
mutex_lock(&i40evf_device_mutex);
list_for_each_entry(ldev, &i40evf_devices, list) {
adapter = ldev->vf;
cinst = adapter->cinst;
if (!cinst)
continue;
if (test_bit(__I40E_CLIENT_INSTANCE_OPENED, &cinst->state)) {
if (client->ops && client->ops->close)
client->ops->close(&cinst->lan_info, client,
false);
i40evf_client_release_qvlist(&cinst->lan_info);
clear_bit(__I40E_CLIENT_INSTANCE_OPENED, &cinst->state);
dev_warn(&adapter->pdev->dev,
"Client %s instance closed\n", client->name);
}
i40evf_client_del_instance(adapter);
dev_info(&adapter->pdev->dev, "Deleted client instance of Client %s\n",
client->name);
}
mutex_unlock(&i40evf_device_mutex);
}
static void i40evf_client_prepare(struct i40e_client *client)
{
struct i40e_device *ldev;
struct i40evf_adapter *adapter;
mutex_lock(&i40evf_device_mutex);
list_for_each_entry(ldev, &i40evf_devices, list) {
adapter = ldev->vf;
adapter->flags |= I40EVF_FLAG_SERVICE_CLIENT_REQUESTED;
}
mutex_unlock(&i40evf_device_mutex);
}
static u32 i40evf_client_virtchnl_send(struct i40e_info *ldev,
struct i40e_client *client,
u8 *msg, u16 len)
{
struct i40evf_adapter *adapter = ldev->vf;
i40e_status err;
if (adapter->aq_required)
return -EAGAIN;
err = i40e_aq_send_msg_to_pf(&adapter->hw, I40E_VIRTCHNL_OP_IWARP,
I40E_SUCCESS, msg, len, NULL);
if (err)
dev_err(&adapter->pdev->dev, "Unable to send iWarp message to PF, error %d, aq status %d\n",
err, adapter->hw.aq.asq_last_status);
return err;
}
static int i40evf_client_setup_qvlist(struct i40e_info *ldev,
struct i40e_client *client,
struct i40e_qvlist_info *qvlist_info)
{
struct i40e_virtchnl_iwarp_qvlist_info *v_qvlist_info;
struct i40evf_adapter *adapter = ldev->vf;
struct i40e_qv_info *qv_info;
i40e_status err;
u32 v_idx, i;
u32 msg_size;
if (adapter->aq_required)
return -EAGAIN;
for (i = 0; i < qvlist_info->num_vectors; i++) {
qv_info = &qvlist_info->qv_info[i];
if (!qv_info)
continue;
v_idx = qv_info->v_idx;
if ((v_idx >=
(adapter->iwarp_base_vector + adapter->num_iwarp_msix)) ||
(v_idx < adapter->iwarp_base_vector))
return -EINVAL;
}
v_qvlist_info = (struct i40e_virtchnl_iwarp_qvlist_info *)qvlist_info;
msg_size = sizeof(struct i40e_virtchnl_iwarp_qvlist_info) +
(sizeof(struct i40e_virtchnl_iwarp_qv_info) *
(v_qvlist_info->num_vectors - 1));
adapter->client_pending |= BIT(I40E_VIRTCHNL_OP_CONFIG_IWARP_IRQ_MAP);
err = i40e_aq_send_msg_to_pf(&adapter->hw,
I40E_VIRTCHNL_OP_CONFIG_IWARP_IRQ_MAP,
I40E_SUCCESS, (u8 *)v_qvlist_info, msg_size, NULL);
if (err) {
dev_err(&adapter->pdev->dev,
"Unable to send iWarp vector config message to PF, error %d, aq status %d\n",
err, adapter->hw.aq.asq_last_status);
goto out;
}
err = -EBUSY;
for (i = 0; i < 5; i++) {
msleep(100);
if (!(adapter->client_pending &
BIT(I40E_VIRTCHNL_OP_CONFIG_IWARP_IRQ_MAP))) {
err = 0;
break;
}
}
out:
return err;
}
int i40evf_register_client(struct i40e_client *client)
{
int ret = 0;
if (!client) {
ret = -EIO;
goto out;
}
if (strlen(client->name) == 0) {
pr_info("i40evf: Failed to register client with no name\n");
ret = -EIO;
goto out;
}
if (vf_registered_client) {
pr_info("i40evf: Client %s has already been registered!\n",
client->name);
ret = -EEXIST;
goto out;
}
if ((client->version.major != I40EVF_CLIENT_VERSION_MAJOR) ||
(client->version.minor != I40EVF_CLIENT_VERSION_MINOR)) {
pr_info("i40evf: Failed to register client %s due to mismatched client interface version\n",
client->name);
pr_info("Client is using version: %02d.%02d.%02d while LAN driver supports %s\n",
client->version.major, client->version.minor,
client->version.build,
i40evf_client_interface_version_str);
ret = -EIO;
goto out;
}
vf_registered_client = client;
i40evf_client_prepare(client);
pr_info("i40evf: Registered client %s with return code %d\n",
client->name, ret);
out:
return ret;
}
int i40evf_unregister_client(struct i40e_client *client)
{
int ret = 0;
i40evf_client_release(client);
if (vf_registered_client != client) {
pr_info("i40evf: Client %s has not been registered\n",
client->name);
ret = -ENODEV;
goto out;
}
vf_registered_client = NULL;
pr_info("i40evf: Unregistered client %s\n", client->name);
out:
return ret;
}
