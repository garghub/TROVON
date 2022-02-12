static void number_of_connections(struct mei_cl_device *cldev)
{
dev_dbg(&cldev->dev, "running hook %s\n", __func__);
if (cldev->me_cl->props.max_number_of_connections > 1)
cldev->do_match = 0;
}
static void blacklist(struct mei_cl_device *cldev)
{
dev_dbg(&cldev->dev, "running hook %s\n", __func__);
cldev->do_match = 0;
}
static int mei_osver(struct mei_cl_device *cldev)
{
int ret;
const size_t size = sizeof(struct mkhi_msg_hdr) +
sizeof(struct mkhi_fwcaps) +
sizeof(struct mei_os_ver);
size_t length = 8;
char buf[size];
struct mkhi_msg *req;
struct mkhi_fwcaps *fwcaps;
struct mei_os_ver *os_ver;
unsigned int mode = MEI_CL_IO_TX_BLOCKING | MEI_CL_IO_TX_INTERNAL;
memset(buf, 0, size);
req = (struct mkhi_msg *)buf;
req->hdr.group_id = MKHI_FWCAPS_GROUP_ID;
req->hdr.command = MKHI_FWCAPS_SET_OS_VER_APP_RULE_CMD;
fwcaps = (struct mkhi_fwcaps *)req->data;
fwcaps->id.rule_type = 0x0;
fwcaps->id.feature_id = MKHI_FEATURE_PTT;
fwcaps->len = sizeof(*os_ver);
os_ver = (struct mei_os_ver *)fwcaps->data;
os_ver->os_type = OSTYPE_LINUX;
ret = __mei_cl_send(cldev->cl, buf, size, mode);
if (ret < 0)
return ret;
ret = __mei_cl_recv(cldev->cl, buf, length, 0);
if (ret < 0)
return ret;
return 0;
}
static void mei_mkhi_fix(struct mei_cl_device *cldev)
{
int ret;
if (!cldev->bus->hbm_f_os_supported)
return;
ret = mei_cldev_enable(cldev);
if (ret)
return;
ret = mei_osver(cldev);
if (ret)
dev_err(&cldev->dev, "OS version command failed %d\n", ret);
mei_cldev_disable(cldev);
}
static void mei_wd(struct mei_cl_device *cldev)
{
struct pci_dev *pdev = to_pci_dev(cldev->dev.parent);
dev_dbg(&cldev->dev, "running hook %s\n", __func__);
if (pdev->device == MEI_DEV_ID_WPT_LP ||
pdev->device == MEI_DEV_ID_SPT ||
pdev->device == MEI_DEV_ID_SPT_H)
cldev->me_cl->props.protocol_version = 0x2;
cldev->do_match = 1;
}
static inline void mei_wd(struct mei_cl_device *cldev) {}
static int mei_nfc_if_version(struct mei_cl *cl,
struct mei_nfc_if_version *ver)
{
struct mei_device *bus;
struct mei_nfc_cmd cmd = {
.command = MEI_NFC_CMD_MAINTENANCE,
.data_size = 1,
.sub_command = MEI_NFC_SUBCMD_IF_VERSION,
};
struct mei_nfc_reply *reply = NULL;
size_t if_version_length;
int bytes_recv, ret;
bus = cl->dev;
WARN_ON(mutex_is_locked(&bus->device_lock));
ret = __mei_cl_send(cl, (u8 *)&cmd, sizeof(struct mei_nfc_cmd),
MEI_CL_IO_TX_BLOCKING);
if (ret < 0) {
dev_err(bus->dev, "Could not send IF version cmd\n");
return ret;
}
if_version_length = sizeof(struct mei_nfc_reply) +
sizeof(struct mei_nfc_if_version);
reply = kzalloc(if_version_length, GFP_KERNEL);
if (!reply)
return -ENOMEM;
ret = 0;
bytes_recv = __mei_cl_recv(cl, (u8 *)reply, if_version_length, 0);
if (bytes_recv < if_version_length) {
dev_err(bus->dev, "Could not read IF version\n");
ret = -EIO;
goto err;
}
memcpy(ver, reply->data, sizeof(struct mei_nfc_if_version));
dev_info(bus->dev, "NFC MEI VERSION: IVN 0x%x Vendor ID 0x%x Type 0x%x\n",
ver->fw_ivn, ver->vendor_id, ver->radio_type);
err:
kfree(reply);
return ret;
}
static const char *mei_nfc_radio_name(struct mei_nfc_if_version *ver)
{
if (ver->vendor_id == MEI_NFC_VENDOR_INSIDE) {
if (ver->radio_type == MEI_NFC_VENDOR_INSIDE_UREAD)
return "microread";
}
if (ver->vendor_id == MEI_NFC_VENDOR_NXP) {
if (ver->radio_type == MEI_NFC_VENDOR_NXP_PN544)
return "pn544";
}
return NULL;
}
static void mei_nfc(struct mei_cl_device *cldev)
{
struct mei_device *bus;
struct mei_cl *cl;
struct mei_me_client *me_cl = NULL;
struct mei_nfc_if_version ver;
const char *radio_name = NULL;
int ret;
bus = cldev->bus;
dev_dbg(&cldev->dev, "running hook %s\n", __func__);
mutex_lock(&bus->device_lock);
cl = mei_cl_alloc_linked(bus);
if (IS_ERR(cl)) {
ret = PTR_ERR(cl);
cl = NULL;
dev_err(bus->dev, "nfc hook alloc failed %d\n", ret);
goto out;
}
me_cl = mei_me_cl_by_uuid(bus, &mei_nfc_info_guid);
if (!me_cl) {
ret = -ENOTTY;
dev_err(bus->dev, "Cannot find nfc info %d\n", ret);
goto out;
}
ret = mei_cl_connect(cl, me_cl, NULL);
if (ret < 0) {
dev_err(&cldev->dev, "Can't connect to the NFC INFO ME ret = %d\n",
ret);
goto out;
}
mutex_unlock(&bus->device_lock);
ret = mei_nfc_if_version(cl, &ver);
if (ret)
goto disconnect;
radio_name = mei_nfc_radio_name(&ver);
if (!radio_name) {
ret = -ENOENT;
dev_err(&cldev->dev, "Can't get the NFC interface version ret = %d\n",
ret);
goto disconnect;
}
dev_dbg(bus->dev, "nfc radio %s\n", radio_name);
strlcpy(cldev->name, radio_name, sizeof(cldev->name));
disconnect:
mutex_lock(&bus->device_lock);
if (mei_cl_disconnect(cl) < 0)
dev_err(bus->dev, "Can't disconnect the NFC INFO ME\n");
mei_cl_flush_queues(cl, NULL);
out:
mei_cl_unlink(cl);
mutex_unlock(&bus->device_lock);
mei_me_cl_put(me_cl);
kfree(cl);
if (ret)
cldev->do_match = 0;
dev_dbg(bus->dev, "end of fixup match = %d\n", cldev->do_match);
}
void mei_cl_bus_dev_fixup(struct mei_cl_device *cldev)
{
struct mei_fixup *f;
const uuid_le *uuid = mei_me_cl_uuid(cldev->me_cl);
int i;
for (i = 0; i < ARRAY_SIZE(mei_fixups); i++) {
f = &mei_fixups[i];
if (uuid_le_cmp(f->uuid, MEI_UUID_ANY) == 0 ||
uuid_le_cmp(f->uuid, *uuid) == 0)
f->hook(cldev);
}
}
