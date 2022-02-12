static int qat_send_admin_cmd(struct adf_accel_dev *accel_dev, int cmd)
{
struct adf_hw_device_data *hw_device = accel_dev->hw_device;
struct icp_qat_fw_init_admin_req req;
struct icp_qat_fw_init_admin_resp resp;
int i;
memset(&req, 0, sizeof(struct icp_qat_fw_init_admin_req));
req.init_admin_cmd_id = cmd;
for (i = 0; i < hw_device->get_num_aes(hw_device); i++) {
memset(&resp, 0, sizeof(struct icp_qat_fw_init_admin_resp));
if (adf_put_admin_msg_sync(accel_dev, i, &req, &resp) ||
resp.init_resp_hdr.status)
return -EFAULT;
}
return 0;
}
static int qat_admin_start(struct adf_accel_dev *accel_dev)
{
return qat_send_admin_cmd(accel_dev, ICP_QAT_FW_INIT_ME);
}
static int qat_admin_event_handler(struct adf_accel_dev *accel_dev,
enum adf_event event)
{
int ret;
switch (event) {
case ADF_EVENT_START:
ret = qat_admin_start(accel_dev);
break;
case ADF_EVENT_STOP:
case ADF_EVENT_INIT:
case ADF_EVENT_SHUTDOWN:
default:
ret = 0;
}
return ret;
}
int qat_admin_register(void)
{
memset(&qat_admin, 0, sizeof(struct service_hndl));
qat_admin.event_hld = qat_admin_event_handler;
qat_admin.name = "qat_admin";
qat_admin.admin = 1;
return adf_service_register(&qat_admin);
}
int qat_admin_unregister(void)
{
return adf_service_unregister(&qat_admin);
}
