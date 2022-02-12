static void
anslcd_write_byte_ctrl ( unsigned char c )
{
#ifdef DEBUG
printk(KERN_DEBUG "LCD: CTRL byte: %02x\n",c);
#endif
out_8(anslcd_ptr + ANSLCD_CTRL_IX, c);
switch(c) {
case 1:
case 2:
case 3:
udelay(anslcd_long_delay); break;
default: udelay(anslcd_short_delay);
}
}
static void
anslcd_write_byte_data ( unsigned char c )
{
out_8(anslcd_ptr + ANSLCD_DATA_IX, c);
udelay(anslcd_short_delay);
}
static ssize_t
anslcd_write( struct file * file, const char __user * buf,
size_t count, loff_t *ppos )
{
const char __user *p = buf;
int i;
#ifdef DEBUG
printk(KERN_DEBUG "LCD: write\n");
#endif
if (!access_ok(VERIFY_READ, buf, count))
return -EFAULT;
mutex_lock(&anslcd_mutex);
for ( i = *ppos; count > 0; ++i, ++p, --count )
{
char c;
__get_user(c, p);
anslcd_write_byte_data( c );
}
mutex_unlock(&anslcd_mutex);
*ppos = i;
return p - buf;
}
static long
anslcd_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
char ch, __user *temp;
long ret = 0;
#ifdef DEBUG
printk(KERN_DEBUG "LCD: ioctl(%d,%d)\n",cmd,arg);
#endif
mutex_lock(&anslcd_mutex);
switch ( cmd )
{
case ANSLCD_CLEAR:
anslcd_write_byte_ctrl ( 0x38 );
anslcd_write_byte_ctrl ( 0x0f );
anslcd_write_byte_ctrl ( 0x06 );
anslcd_write_byte_ctrl ( 0x01 );
anslcd_write_byte_ctrl ( 0x02 );
break;
case ANSLCD_SENDCTRL:
temp = (char __user *) arg;
__get_user(ch, temp);
for (; ch; temp++) {
anslcd_write_byte_ctrl ( ch );
__get_user(ch, temp);
}
break;
case ANSLCD_SETSHORTDELAY:
if (!capable(CAP_SYS_ADMIN))
ret =-EACCES;
else
anslcd_short_delay=arg;
break;
case ANSLCD_SETLONGDELAY:
if (!capable(CAP_SYS_ADMIN))
ret = -EACCES;
else
anslcd_long_delay=arg;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&anslcd_mutex);
return ret;
}
static int
anslcd_open( struct inode * inode, struct file * file )
{
return 0;
}
static int __init
anslcd_init(void)
{
int a;
int retval;
struct device_node* node;
node = of_find_node_by_name(NULL, "lcd");
if (!node || !node->parent || strcmp(node->parent->name, "gc")) {
of_node_put(node);
return -ENODEV;
}
of_node_put(node);
anslcd_ptr = ioremap(ANSLCD_ADDR, 0x20);
retval = misc_register(&anslcd_dev);
if(retval < 0){
printk(KERN_INFO "LCD: misc_register failed\n");
iounmap(anslcd_ptr);
return retval;
}
#ifdef DEBUG
printk(KERN_DEBUG "LCD: init\n");
#endif
mutex_lock(&anslcd_mutex);
anslcd_write_byte_ctrl ( 0x38 );
anslcd_write_byte_ctrl ( 0x0c );
anslcd_write_byte_ctrl ( 0x06 );
anslcd_write_byte_ctrl ( 0x01 );
anslcd_write_byte_ctrl ( 0x02 );
for(a=0;a<80;a++) {
anslcd_write_byte_data(anslcd_logo[a]);
}
mutex_unlock(&anslcd_mutex);
return 0;
}
static void __exit
anslcd_exit(void)
{
misc_deregister(&anslcd_dev);
iounmap(anslcd_ptr);
}
