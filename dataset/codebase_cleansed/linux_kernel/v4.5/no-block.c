static int no_blkdev_open(struct inode * inode, struct file * filp)\r\n{\r\nreturn -ENODEV;\r\n}
