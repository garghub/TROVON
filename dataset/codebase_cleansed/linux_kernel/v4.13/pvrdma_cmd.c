static inline int pvrdma_cmd_recv(struct pvrdma_dev *dev,
union pvrdma_cmd_resp *resp,
unsigned resp_code)
{
int err;
dev_dbg(&dev->pdev->dev, "receive response from device\n");
err = wait_for_completion_interruptible_timeout(&dev->cmd_done,
msecs_to_jiffies(PVRDMA_CMD_TIMEOUT));
if (err == 0 || err == -ERESTARTSYS) {
dev_warn(&dev->pdev->dev,
"completion timeout or interrupted\n");
return -ETIMEDOUT;
}
spin_lock(&dev->cmd_lock);
memcpy(resp, dev->resp_slot, sizeof(*resp));
spin_unlock(&dev->cmd_lock);
if (resp->hdr.ack != resp_code) {
dev_warn(&dev->pdev->dev,
"unknown response %#x expected %#x\n",
resp->hdr.ack, resp_code);
return -EFAULT;
}
return 0;
}
int
pvrdma_cmd_post(struct pvrdma_dev *dev, union pvrdma_cmd_req *req,
union pvrdma_cmd_resp *resp, unsigned resp_code)
{
int err;
dev_dbg(&dev->pdev->dev, "post request to device\n");
down(&dev->cmd_sema);
BUILD_BUG_ON(sizeof(union pvrdma_cmd_req) !=
sizeof(struct pvrdma_cmd_modify_qp));
spin_lock(&dev->cmd_lock);
memcpy(dev->cmd_slot, req, sizeof(*req));
spin_unlock(&dev->cmd_lock);
init_completion(&dev->cmd_done);
pvrdma_write_reg(dev, PVRDMA_REG_REQUEST, 0);
mb();
err = pvrdma_read_reg(dev, PVRDMA_REG_ERR);
if (err == 0) {
if (resp != NULL)
err = pvrdma_cmd_recv(dev, resp, resp_code);
} else {
dev_warn(&dev->pdev->dev,
"failed to write request error reg: %d\n", err);
err = -EFAULT;
}
up(&dev->cmd_sema);
return err;
}
