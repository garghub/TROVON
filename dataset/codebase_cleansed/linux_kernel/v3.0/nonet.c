static int sock_no_open(struct inode *irrelevant, struct file *dontcare)
{
return -ENXIO;
}
