int __init read_initrd(void)
{
void *area;
long long size;
int err;
if (initrd == NULL)
return 0;
err = os_file_size(initrd, &size);
if (err)
return 0;
if (size == 0) {
printk(KERN_ERR "\"%s\" is a zero-size initrd\n", initrd);
return 0;
}
area = alloc_bootmem(size);
if (load_initrd(initrd, area, size) == -1)
return 0;
initrd_start = (unsigned long) area;
initrd_end = initrd_start + size;
return 0;
}
static int __init uml_initrd_setup(char *line, int *add)
{
initrd = line;
return 0;
}
static int load_initrd(char *filename, void *buf, int size)
{
int fd, n;
fd = os_open_file(filename, of_read(OPENFLAGS()), 0);
if (fd < 0) {
printk(KERN_ERR "Opening '%s' failed - err = %d\n", filename,
-fd);
return -1;
}
n = os_read_file(fd, buf, size);
if (n != size) {
printk(KERN_ERR "Read of %d bytes from '%s' failed, "
"err = %d\n", size,
filename, -n);
return -1;
}
os_close_file(fd);
return 0;
}
