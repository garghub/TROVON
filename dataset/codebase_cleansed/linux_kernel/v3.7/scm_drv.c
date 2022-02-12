static void notify(struct scm_device *scmdev)
{
pr_info("%lu: The capabilities of the SCM increment changed\n",
(unsigned long) scmdev->address);
SCM_LOG(2, "State changed");
SCM_LOG_STATE(2, scmdev);
}
static int scm_probe(struct scm_device *scmdev)
{
struct scm_blk_dev *bdev;
int ret;
SCM_LOG(2, "probe");
SCM_LOG_STATE(2, scmdev);
if (scmdev->attrs.oper_state != OP_STATE_GOOD)
return -EINVAL;
bdev = kzalloc(sizeof(*bdev), GFP_KERNEL);
if (!bdev)
return -ENOMEM;
dev_set_drvdata(&scmdev->dev, bdev);
ret = scm_blk_dev_setup(bdev, scmdev);
if (ret) {
dev_set_drvdata(&scmdev->dev, NULL);
kfree(bdev);
goto out;
}
out:
return ret;
}
static int scm_remove(struct scm_device *scmdev)
{
struct scm_blk_dev *bdev = dev_get_drvdata(&scmdev->dev);
scm_blk_dev_cleanup(bdev);
dev_set_drvdata(&scmdev->dev, NULL);
kfree(bdev);
return 0;
}
int __init scm_drv_init(void)
{
return scm_driver_register(&scm_drv);
}
void scm_drv_cleanup(void)
{
scm_driver_unregister(&scm_drv);
}
