static int hvc_udbg_put(uint32_t vtermno, const char *buf, int count)
{
int i;
for (i = 0; i < count && udbg_putc; i++)
udbg_putc(buf[i]);
return i;
}
static int hvc_udbg_get(uint32_t vtermno, char *buf, int count)
{
int i, c;
if (!udbg_getc_poll)
return 0;
for (i = 0; i < count; i++) {
if ((c = udbg_getc_poll()) == -1)
break;
buf[i] = c;
}
return i;
}
static int __init hvc_udbg_init(void)
{
struct hvc_struct *hp;
if (!udbg_putc)
return -ENODEV;
BUG_ON(hvc_udbg_dev);
hp = hvc_alloc(0, 0, &hvc_udbg_ops, 16);
if (IS_ERR(hp))
return PTR_ERR(hp);
hvc_udbg_dev = hp;
return 0;
}
static int __init hvc_udbg_console_init(void)
{
if (!udbg_putc)
return -ENODEV;
hvc_instantiate(0, 0, &hvc_udbg_ops);
add_preferred_console("hvc", 0, NULL);
return 0;
}
