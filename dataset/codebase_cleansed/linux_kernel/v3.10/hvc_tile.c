static int hvc_tile_put_chars(uint32_t vt, const char *buf, int count)
{
return hv_console_write((HV_VirtAddr)buf, count);
}
static int hvc_tile_get_chars(uint32_t vt, char *buf, int count)
{
int i, c;
for (i = 0; i < count; ++i) {
c = hv_console_read_if_ready();
if (c < 0)
break;
buf[i] = c;
}
return i;
}
static int __init hvc_tile_console_init(void)
{
extern void disable_early_printk(void);
hvc_instantiate(0, 0, &hvc_tile_get_put_ops);
add_preferred_console("hvc", 0, NULL);
disable_early_printk();
return 0;
}
static int __init hvc_tile_init(void)
{
struct hvc_struct *s;
s = hvc_alloc(0, 0, &hvc_tile_get_put_ops, 128);
return IS_ERR(s) ? PTR_ERR(s) : 0;
}
