static void mei_nfc_free(struct mei_nfc_dev *ndev)
{
if (!ndev)
return;
if (ndev->cl) {
list_del(&ndev->cl->device_link);
mei_cl_unlink(ndev->cl);
kfree(ndev->cl);
}
if (ndev->cl_info) {
list_del(&ndev->cl_info->device_link);
mei_cl_unlink(ndev->cl_info);
kfree(ndev->cl_info);
}
mei_me_cl_put(ndev->me_cl);
kfree(ndev);
}
static int mei_nfc_build_bus_name(struct mei_nfc_dev *ndev)
{
struct mei_device *dev;
if (!ndev->cl)
return -ENODEV;
dev = ndev->cl->dev;
switch (ndev->vendor_id) {
case MEI_NFC_VENDOR_INSIDE:
switch (ndev->radio_type) {
case MEI_NFC_VENDOR_INSIDE_UREAD:
ndev->bus_name = "microread";
return 0;
default:
dev_err(dev->dev, "Unknown radio type 0x%x\n",
ndev->radio_type);
return -EINVAL;
}
case MEI_NFC_VENDOR_NXP:
switch (ndev->radio_type) {
case MEI_NFC_VENDOR_NXP_PN544:
ndev->bus_name = "pn544";
return 0;
default:
dev_err(dev->dev, "Unknown radio type 0x%x\n",
ndev->radio_type);
return -EINVAL;
}
default:
dev_err(dev->dev, "Unknown vendor ID 0x%x\n",
ndev->vendor_id);
return -EINVAL;
}
return 0;
}
static int mei_nfc_if_version(struct mei_nfc_dev *ndev)
{
struct mei_device *dev;
struct mei_cl *cl;
struct mei_nfc_cmd cmd;
struct mei_nfc_reply *reply = NULL;
struct mei_nfc_if_version *version;
size_t if_version_length;
int bytes_recv, ret;
cl = ndev->cl_info;
dev = cl->dev;
memset(&cmd, 0, sizeof(struct mei_nfc_cmd));
cmd.command = MEI_NFC_CMD_MAINTENANCE;
cmd.data_size = 1;
cmd.sub_command = MEI_NFC_SUBCMD_IF_VERSION;
ret = __mei_cl_send(cl, (u8 *)&cmd, sizeof(struct mei_nfc_cmd), 1);
if (ret < 0) {
dev_err(dev->dev, "Could not send IF version cmd\n");
return ret;
}
if_version_length = sizeof(struct mei_nfc_reply) +
sizeof(struct mei_nfc_if_version);
reply = kzalloc(if_version_length, GFP_KERNEL);
if (!reply)
return -ENOMEM;
bytes_recv = __mei_cl_recv(cl, (u8 *)reply, if_version_length);
if (bytes_recv < 0 || bytes_recv < sizeof(struct mei_nfc_reply)) {
dev_err(dev->dev, "Could not read IF version\n");
ret = -EIO;
goto err;
}
version = (struct mei_nfc_if_version *)reply->data;
ndev->fw_ivn = version->fw_ivn;
ndev->vendor_id = version->vendor_id;
ndev->radio_type = version->radio_type;
err:
kfree(reply);
return ret;
}
static void mei_nfc_init(struct work_struct *work)
{
struct mei_device *dev;
struct mei_cl_device *cldev;
struct mei_nfc_dev *ndev;
struct mei_cl *cl_info;
struct mei_me_client *me_cl_info;
ndev = container_of(work, struct mei_nfc_dev, init_work);
cl_info = ndev->cl_info;
dev = cl_info->dev;
mutex_lock(&dev->device_lock);
me_cl_info = mei_me_cl_by_uuid(dev, &mei_nfc_info_guid);
if (!me_cl_info) {
mutex_unlock(&dev->device_lock);
dev_info(dev->dev, "nfc: failed to find the info client\n");
goto err;
}
if (mei_cl_connect(cl_info, me_cl_info, NULL) < 0) {
mei_me_cl_put(me_cl_info);
mutex_unlock(&dev->device_lock);
dev_err(dev->dev, "Could not connect to the NFC INFO ME client");
goto err;
}
mei_me_cl_put(me_cl_info);
mutex_unlock(&dev->device_lock);
if (mei_nfc_if_version(ndev) < 0) {
dev_err(dev->dev, "Could not get the NFC interface version");
goto err;
}
dev_info(dev->dev, "NFC MEI VERSION: IVN 0x%x Vendor ID 0x%x Type 0x%x\n",
ndev->fw_ivn, ndev->vendor_id, ndev->radio_type);
mutex_lock(&dev->device_lock);
if (mei_cl_disconnect(cl_info) < 0) {
mutex_unlock(&dev->device_lock);
dev_err(dev->dev, "Could not disconnect the NFC INFO ME client");
goto err;
}
mutex_unlock(&dev->device_lock);
if (mei_nfc_build_bus_name(ndev) < 0) {
dev_err(dev->dev, "Could not build the bus ID name\n");
return;
}
cldev = mei_cl_add_device(dev, ndev->me_cl, ndev->cl,
ndev->bus_name);
if (!cldev) {
dev_err(dev->dev, "Could not add the NFC device to the MEI bus\n");
goto err;
}
cldev->priv_data = ndev;
return;
err:
mutex_lock(&dev->device_lock);
mei_nfc_free(ndev);
mutex_unlock(&dev->device_lock);
}
int mei_nfc_host_init(struct mei_device *dev, struct mei_me_client *me_cl)
{
struct mei_nfc_dev *ndev;
struct mei_cl *cl_info, *cl;
int ret;
cl = mei_cl_bus_find_cl_by_uuid(dev, mei_nfc_guid);
if (cl)
return 0;
ndev = kzalloc(sizeof(struct mei_nfc_dev), GFP_KERNEL);
if (!ndev) {
ret = -ENOMEM;
goto err;
}
ndev->me_cl = mei_me_cl_get(me_cl);
if (!ndev->me_cl) {
ret = -ENODEV;
goto err;
}
cl_info = mei_cl_alloc_linked(dev, MEI_HOST_CLIENT_ID_ANY);
if (IS_ERR(cl_info)) {
ret = PTR_ERR(cl_info);
goto err;
}
list_add_tail(&cl_info->device_link, &dev->device_list);
ndev->cl_info = cl_info;
cl = mei_cl_alloc_linked(dev, MEI_HOST_CLIENT_ID_ANY);
if (IS_ERR(cl)) {
ret = PTR_ERR(cl);
goto err;
}
list_add_tail(&cl->device_link, &dev->device_list);
ndev->cl = cl;
INIT_WORK(&ndev->init_work, mei_nfc_init);
schedule_work(&ndev->init_work);
return 0;
err:
mei_nfc_free(ndev);
return ret;
}
void mei_nfc_host_exit(struct mei_device *dev)
{
struct mei_nfc_dev *ndev;
struct mei_cl *cl;
struct mei_cl_device *cldev;
cl = mei_cl_bus_find_cl_by_uuid(dev, mei_nfc_guid);
if (!cl)
return;
cldev = cl->device;
if (!cldev)
return;
ndev = (struct mei_nfc_dev *)cldev->priv_data;
if (ndev)
cancel_work_sync(&ndev->init_work);
cldev->priv_data = NULL;
mei_cl_remove_device(cldev);
mutex_lock(&dev->device_lock);
mei_nfc_free(ndev);
mutex_unlock(&dev->device_lock);
}
