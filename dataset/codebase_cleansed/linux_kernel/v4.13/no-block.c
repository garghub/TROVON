static int no_blkdev_open(struct inode * inode, struct file * filp)
{
return -ENODEV;
}
