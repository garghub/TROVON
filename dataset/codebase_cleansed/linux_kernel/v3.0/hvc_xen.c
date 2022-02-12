static inline struct xencons_interface *xencons_interface(void)
{
if (console_pfn == ~0ul)
return mfn_to_virt(xen_start_info->console.domU.mfn);
else
return __va(console_pfn << PAGE_SHIFT);
}
static inline void notify_daemon(void)
{
notify_remote_via_evtchn(xen_start_info->console.domU.evtchn);
}
static int __write_console(const char *data, int len)
{
struct xencons_interface *intf = xencons_interface();
XENCONS_RING_IDX cons, prod;
int sent = 0;
cons = intf->out_cons;
prod = intf->out_prod;
mb();
BUG_ON((prod - cons) > sizeof(intf->out));
while ((sent < len) && ((prod - cons) < sizeof(intf->out)))
intf->out[MASK_XENCONS_IDX(prod++, intf->out)] = data[sent++];
wmb();
intf->out_prod = prod;
if (sent)
notify_daemon();
return sent;
}
static int domU_write_console(uint32_t vtermno, const char *data, int len)
{
int ret = len;
while (len) {
int sent = __write_console(data, len);
data += sent;
len -= sent;
if (unlikely(len))
HYPERVISOR_sched_op(SCHEDOP_yield, NULL);
}
return ret;
}
static int domU_read_console(uint32_t vtermno, char *buf, int len)
{
struct xencons_interface *intf = xencons_interface();
XENCONS_RING_IDX cons, prod;
int recv = 0;
cons = intf->in_cons;
prod = intf->in_prod;
mb();
BUG_ON((prod - cons) > sizeof(intf->in));
while (cons != prod && recv < len)
buf[recv++] = intf->in[MASK_XENCONS_IDX(cons++, intf->in)];
mb();
intf->in_cons = cons;
notify_daemon();
return recv;
}
static int dom0_read_console(uint32_t vtermno, char *buf, int len)
{
return HYPERVISOR_console_io(CONSOLEIO_read, len, buf);
}
static int dom0_write_console(uint32_t vtermno, const char *str, int len)
{
int rc = HYPERVISOR_console_io(CONSOLEIO_write, len, (char *)str);
if (rc < 0)
return 0;
return len;
}
static int __init xen_hvc_init(void)
{
struct hvc_struct *hp;
struct hv_ops *ops;
if (!xen_pv_domain())
return -ENODEV;
if (xen_initial_domain()) {
ops = &dom0_hvc_ops;
xencons_irq = bind_virq_to_irq(VIRQ_CONSOLE, 0);
} else {
if (!xen_start_info->console.domU.evtchn)
return -ENODEV;
ops = &domU_hvc_ops;
xencons_irq = bind_evtchn_to_irq(xen_start_info->console.domU.evtchn);
}
if (xencons_irq < 0)
xencons_irq = 0;
else
irq_set_noprobe(xencons_irq);
hp = hvc_alloc(HVC_COOKIE, xencons_irq, ops, 256);
if (IS_ERR(hp))
return PTR_ERR(hp);
hvc = hp;
console_pfn = mfn_to_pfn(xen_start_info->console.domU.mfn);
return 0;
}
void xen_console_resume(void)
{
if (xencons_irq)
rebind_evtchn_irq(xen_start_info->console.domU.evtchn, xencons_irq);
}
static void __exit xen_hvc_fini(void)
{
if (hvc)
hvc_remove(hvc);
}
static int xen_cons_init(void)
{
struct hv_ops *ops;
if (!xen_pv_domain())
return 0;
if (xen_initial_domain())
ops = &dom0_hvc_ops;
else
ops = &domU_hvc_ops;
hvc_instantiate(HVC_COOKIE, 0, ops);
return 0;
}
static void xenboot_write_console(struct console *console, const char *string,
unsigned len)
{
unsigned int linelen, off = 0;
const char *pos;
dom0_write_console(0, string, len);
if (xen_initial_domain())
return;
domU_write_console(0, "(early) ", 8);
while (off < len && NULL != (pos = strchr(string+off, '\n'))) {
linelen = pos-string+off;
if (off + linelen > len)
break;
domU_write_console(0, string+off, linelen);
domU_write_console(0, "\r\n", 2);
off += linelen + 1;
}
if (off < len)
domU_write_console(0, string+off, len-off);
}
void xen_raw_console_write(const char *str)
{
dom0_write_console(0, str, strlen(str));
}
void xen_raw_printk(const char *fmt, ...)
{
static char buf[512];
va_list ap;
va_start(ap, fmt);
vsnprintf(buf, sizeof(buf), fmt, ap);
va_end(ap);
xen_raw_console_write(buf);
}
