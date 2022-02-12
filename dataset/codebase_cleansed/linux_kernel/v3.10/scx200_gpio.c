static int scx200_gpio_open(struct inode *inode, struct file *file)
{
unsigned m = iminor(inode);
file->private_data = &scx200_gpio_ops;
if (m >= MAX_PINS)
return -EINVAL;
return nonseekable_open(inode, file);
}
static int scx200_gpio_release(struct inode *inode, struct file *file)
{
return 0;
}
static int __init scx200_gpio_init(void)
{
int rc;
dev_t devid;
if (!scx200_gpio_present()) {
printk(KERN_ERR DRVNAME ": no SCx200 gpio present\n");
return -ENODEV;
}
pdev = platform_device_alloc(DRVNAME, 0);
if (!pdev)
return -ENOMEM;
rc = platform_device_add(pdev);
if (rc)
goto undo_malloc;
scx200_gpio_ops.dev = &pdev->dev;
if (major) {
devid = MKDEV(major, 0);
rc = register_chrdev_region(devid, MAX_PINS, "scx200_gpio");
} else {
rc = alloc_chrdev_region(&devid, 0, MAX_PINS, "scx200_gpio");
major = MAJOR(devid);
}
if (rc < 0) {
dev_err(&pdev->dev, "SCx200 chrdev_region err: %d\n", rc);
goto undo_platform_device_add;
}
cdev_init(&scx200_gpio_cdev, &scx200_gpio_fileops);
cdev_add(&scx200_gpio_cdev, devid, MAX_PINS);
return 0;
undo_platform_device_add:
platform_device_del(pdev);
undo_malloc:
platform_device_put(pdev);
return rc;
}
static void __exit scx200_gpio_cleanup(void)
{
cdev_del(&scx200_gpio_cdev);
unregister_chrdev_region(MKDEV(major, 0), MAX_PINS);
platform_device_unregister(pdev);
}
