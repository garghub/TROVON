static void dev_remove(struct net *net, dev_t dev)
{
struct bl_pipe_msg bl_pipe_msg;
struct rpc_pipe_msg *msg = &bl_pipe_msg.msg;
struct bl_dev_msg bl_umount_request;
struct bl_msg_hdr bl_msg = {
.type = BL_DEVICE_UMOUNT,
.totallen = sizeof(bl_umount_request),
};
uint8_t *dataptr;
DECLARE_WAITQUEUE(wq, current);
struct nfs_net *nn = net_generic(net, nfs_net_id);
dprintk("Entering %s\n", __func__);
bl_pipe_msg.bl_wq = &nn->bl_wq;
memset(msg, 0, sizeof(*msg));
msg->len = sizeof(bl_msg) + bl_msg.totallen;
msg->data = kzalloc(msg->len, GFP_NOFS);
if (!msg->data)
goto out;
memset(&bl_umount_request, 0, sizeof(bl_umount_request));
bl_umount_request.major = MAJOR(dev);
bl_umount_request.minor = MINOR(dev);
memcpy(msg->data, &bl_msg, sizeof(bl_msg));
dataptr = (uint8_t *) msg->data;
memcpy(&dataptr[sizeof(bl_msg)], &bl_umount_request, sizeof(bl_umount_request));
add_wait_queue(&nn->bl_wq, &wq);
if (rpc_queue_upcall(nn->bl_device_pipe, msg) < 0) {
remove_wait_queue(&nn->bl_wq, &wq);
goto out;
}
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
__set_current_state(TASK_RUNNING);
remove_wait_queue(&nn->bl_wq, &wq);
out:
kfree(msg->data);
}
static void nfs4_blk_metadev_release(struct pnfs_block_dev *bdev)
{
dprintk("%s Releasing\n", __func__);
nfs4_blkdev_put(bdev->bm_mdev);
dev_remove(bdev->net, bdev->bm_mdev->bd_dev);
}
void bl_free_block_dev(struct pnfs_block_dev *bdev)
{
if (bdev) {
if (bdev->bm_mdev) {
dprintk("%s Removing DM device: %d:%d\n",
__func__,
MAJOR(bdev->bm_mdev->bd_dev),
MINOR(bdev->bm_mdev->bd_dev));
nfs4_blk_metadev_release(bdev);
}
kfree(bdev);
}
}
