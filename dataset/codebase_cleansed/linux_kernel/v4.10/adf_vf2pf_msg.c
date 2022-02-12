int adf_vf2pf_init(struct adf_accel_dev *accel_dev)
{
u32 msg = (ADF_VF2PF_MSGORIGIN_SYSTEM |
(ADF_VF2PF_MSGTYPE_INIT << ADF_VF2PF_MSGTYPE_SHIFT));
if (adf_iov_putmsg(accel_dev, msg, 0)) {
dev_err(&GET_DEV(accel_dev),
"Failed to send Init event to PF\n");
return -EFAULT;
}
set_bit(ADF_STATUS_PF_RUNNING, &accel_dev->status);
return 0;
}
void adf_vf2pf_shutdown(struct adf_accel_dev *accel_dev)
{
u32 msg = (ADF_VF2PF_MSGORIGIN_SYSTEM |
(ADF_VF2PF_MSGTYPE_SHUTDOWN << ADF_VF2PF_MSGTYPE_SHIFT));
if (test_bit(ADF_STATUS_PF_RUNNING, &accel_dev->status))
if (adf_iov_putmsg(accel_dev, msg, 0))
dev_err(&GET_DEV(accel_dev),
"Failed to send Shutdown event to PF\n");
}
