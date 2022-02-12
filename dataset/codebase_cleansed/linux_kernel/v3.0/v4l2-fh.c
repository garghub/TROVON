int v4l2_fh_init(struct v4l2_fh *fh, struct video_device *vdev)
{
fh->vdev = vdev;
INIT_LIST_HEAD(&fh->list);
set_bit(V4L2_FL_USES_V4L2_FH, &fh->vdev->flags);
fh->prio = V4L2_PRIORITY_UNSET;
if (vdev->ioctl_ops && vdev->ioctl_ops->vidioc_subscribe_event)
return v4l2_event_init(fh);
fh->events = NULL;
return 0;
}
void v4l2_fh_add(struct v4l2_fh *fh)
{
unsigned long flags;
if (test_bit(V4L2_FL_USE_FH_PRIO, &fh->vdev->flags))
v4l2_prio_open(fh->vdev->prio, &fh->prio);
spin_lock_irqsave(&fh->vdev->fh_lock, flags);
list_add(&fh->list, &fh->vdev->fh_list);
spin_unlock_irqrestore(&fh->vdev->fh_lock, flags);
}
int v4l2_fh_open(struct file *filp)
{
struct video_device *vdev = video_devdata(filp);
struct v4l2_fh *fh = kzalloc(sizeof(*fh), GFP_KERNEL);
filp->private_data = fh;
if (fh == NULL)
return -ENOMEM;
v4l2_fh_init(fh, vdev);
v4l2_fh_add(fh);
return 0;
}
void v4l2_fh_del(struct v4l2_fh *fh)
{
unsigned long flags;
spin_lock_irqsave(&fh->vdev->fh_lock, flags);
list_del_init(&fh->list);
spin_unlock_irqrestore(&fh->vdev->fh_lock, flags);
if (test_bit(V4L2_FL_USE_FH_PRIO, &fh->vdev->flags))
v4l2_prio_close(fh->vdev->prio, fh->prio);
}
void v4l2_fh_exit(struct v4l2_fh *fh)
{
if (fh->vdev == NULL)
return;
fh->vdev = NULL;
v4l2_event_free(fh);
}
int v4l2_fh_release(struct file *filp)
{
struct v4l2_fh *fh = filp->private_data;
if (fh) {
v4l2_fh_del(fh);
v4l2_fh_exit(fh);
kfree(fh);
}
return 0;
}
int v4l2_fh_is_singular(struct v4l2_fh *fh)
{
unsigned long flags;
int is_singular;
if (fh == NULL || fh->vdev == NULL)
return 0;
spin_lock_irqsave(&fh->vdev->fh_lock, flags);
is_singular = list_is_singular(&fh->list);
spin_unlock_irqrestore(&fh->vdev->fh_lock, flags);
return is_singular;
}
