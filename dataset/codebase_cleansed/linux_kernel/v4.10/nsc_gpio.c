void nsc_gpio_dump(struct nsc_gpio_ops *amp, unsigned index)
{
u32 config = amp->gpio_config(index, ~0, 0);
dev_info(amp->dev, "io%02u: 0x%04x %s %s %s %s %s %s %s\tio:%d/%d\n",
index, config,
(config & 1) ? "OE" : "TS",
(config & 2) ? "PP" : "OD",
(config & 4) ? "PUE" : "PUD",
(config & 8) ? "LOCKED" : "",
(config & 16) ? "LEVEL" : "EDGE",
(config & 32) ? "HI" : "LO",
(config & 64) ? "DEBOUNCE" : "",
amp->gpio_get(index), amp->gpio_current(index));
}
ssize_t nsc_gpio_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
unsigned m = iminor(file_inode(file));
struct nsc_gpio_ops *amp = file->private_data;
struct device *dev = amp->dev;
size_t i;
int err = 0;
for (i = 0; i < len; ++i) {
char c;
if (get_user(c, data + i))
return -EFAULT;
switch (c) {
case '0':
amp->gpio_set(m, 0);
break;
case '1':
amp->gpio_set(m, 1);
break;
case 'O':
dev_dbg(dev, "GPIO%d output enabled\n", m);
amp->gpio_config(m, ~1, 1);
break;
case 'o':
dev_dbg(dev, "GPIO%d output disabled\n", m);
amp->gpio_config(m, ~1, 0);
break;
case 'T':
dev_dbg(dev, "GPIO%d output is push pull\n", m);
amp->gpio_config(m, ~2, 2);
break;
case 't':
dev_dbg(dev, "GPIO%d output is open drain\n", m);
amp->gpio_config(m, ~2, 0);
break;
case 'P':
dev_dbg(dev, "GPIO%d pull up enabled\n", m);
amp->gpio_config(m, ~4, 4);
break;
case 'p':
dev_dbg(dev, "GPIO%d pull up disabled\n", m);
amp->gpio_config(m, ~4, 0);
break;
case 'v':
amp->gpio_dump(amp, m);
break;
case '\n':
break;
default:
dev_err(dev, "io%2d bad setting: chr<0x%2x>\n",
m, (int)c);
err++;
}
}
if (err)
return -EINVAL;
return len;
}
ssize_t nsc_gpio_read(struct file *file, char __user * buf,
size_t len, loff_t * ppos)
{
unsigned m = iminor(file_inode(file));
int value;
struct nsc_gpio_ops *amp = file->private_data;
value = amp->gpio_get(m);
if (put_user(value ? '1' : '0', buf))
return -EFAULT;
return 1;
}
static int __init nsc_gpio_init(void)
{
printk(KERN_DEBUG NAME " initializing\n");
return 0;
}
static void __exit nsc_gpio_cleanup(void)
{
printk(KERN_DEBUG NAME " cleanup\n");
}
