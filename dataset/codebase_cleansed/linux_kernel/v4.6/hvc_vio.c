static int hvterm_raw_get_chars(uint32_t vtermno, char *buf, int count)
{
struct hvterm_priv *pv = hvterm_privs[vtermno];
unsigned long i;
unsigned long flags;
int got;
if (WARN_ON(!pv))
return 0;
spin_lock_irqsave(&pv->buf_lock, flags);
if (pv->left == 0) {
pv->offset = 0;
pv->left = hvc_get_chars(pv->termno, pv->buf, count);
for (i = 1; i < pv->left; ++i) {
if (pv->buf[i] == 0 && pv->buf[i-1] == '\r') {
--pv->left;
if (i < pv->left) {
memmove(&pv->buf[i], &pv->buf[i+1],
pv->left - i);
}
}
}
}
got = min(count, pv->left);
memcpy(buf, &pv->buf[pv->offset], got);
pv->offset += got;
pv->left -= got;
spin_unlock_irqrestore(&pv->buf_lock, flags);
return got;
}
static int hvterm_raw_put_chars(uint32_t vtermno, const char *buf, int count)
{
struct hvterm_priv *pv = hvterm_privs[vtermno];
if (WARN_ON(!pv))
return 0;
return hvc_put_chars(pv->termno, buf, count);
}
static int hvterm_hvsi_get_chars(uint32_t vtermno, char *buf, int count)
{
struct hvterm_priv *pv = hvterm_privs[vtermno];
if (WARN_ON(!pv))
return 0;
return hvsilib_get_chars(&pv->hvsi, buf, count);
}
static int hvterm_hvsi_put_chars(uint32_t vtermno, const char *buf, int count)
{
struct hvterm_priv *pv = hvterm_privs[vtermno];
if (WARN_ON(!pv))
return 0;
return hvsilib_put_chars(&pv->hvsi, buf, count);
}
static int hvterm_hvsi_open(struct hvc_struct *hp, int data)
{
struct hvterm_priv *pv = hvterm_privs[hp->vtermno];
int rc;
pr_devel("HVSI@%x: open !\n", pv->termno);
rc = notifier_add_irq(hp, data);
if (rc)
return rc;
return hvsilib_open(&pv->hvsi, hp);
}
static void hvterm_hvsi_close(struct hvc_struct *hp, int data)
{
struct hvterm_priv *pv = hvterm_privs[hp->vtermno];
pr_devel("HVSI@%x: do close !\n", pv->termno);
hvsilib_close(&pv->hvsi, hp);
notifier_del_irq(hp, data);
}
void hvterm_hvsi_hangup(struct hvc_struct *hp, int data)
{
struct hvterm_priv *pv = hvterm_privs[hp->vtermno];
pr_devel("HVSI@%x: do hangup !\n", pv->termno);
hvsilib_close(&pv->hvsi, hp);
notifier_hangup_irq(hp, data);
}
static int hvterm_hvsi_tiocmget(struct hvc_struct *hp)
{
struct hvterm_priv *pv = hvterm_privs[hp->vtermno];
if (!pv)
return -EINVAL;
return pv->hvsi.mctrl;
}
static int hvterm_hvsi_tiocmset(struct hvc_struct *hp, unsigned int set,
unsigned int clear)
{
struct hvterm_priv *pv = hvterm_privs[hp->vtermno];
pr_devel("HVSI@%x: Set modem control, set=%x,clr=%x\n",
pv->termno, set, clear);
if (set & TIOCM_DTR)
hvsilib_write_mctrl(&pv->hvsi, 1);
else if (clear & TIOCM_DTR)
hvsilib_write_mctrl(&pv->hvsi, 0);
return 0;
}
static void udbg_hvc_putc(char c)
{
int count = -1;
if (!hvterm_privs[0])
return;
if (c == '\n')
udbg_hvc_putc('\r');
do {
switch(hvterm_privs[0]->proto) {
case HV_PROTOCOL_RAW:
count = hvterm_raw_put_chars(0, &c, 1);
break;
case HV_PROTOCOL_HVSI:
count = hvterm_hvsi_put_chars(0, &c, 1);
break;
}
} while(count == 0);
}
static int udbg_hvc_getc_poll(void)
{
int rc = 0;
char c;
if (!hvterm_privs[0])
return -1;
switch(hvterm_privs[0]->proto) {
case HV_PROTOCOL_RAW:
rc = hvterm_raw_get_chars(0, &c, 1);
break;
case HV_PROTOCOL_HVSI:
rc = hvterm_hvsi_get_chars(0, &c, 1);
break;
}
if (!rc)
return -1;
return c;
}
static int udbg_hvc_getc(void)
{
int ch;
if (!hvterm_privs[0])
return -1;
for (;;) {
ch = udbg_hvc_getc_poll();
if (ch == -1) {
volatile unsigned long delay;
for (delay=0; delay < 2000000; delay++)
;
} else {
return ch;
}
}
}
static int hvc_vio_probe(struct vio_dev *vdev,
const struct vio_device_id *id)
{
const struct hv_ops *ops;
struct hvc_struct *hp;
struct hvterm_priv *pv;
hv_protocol_t proto;
int i, termno = -1;
if (!vdev || !id)
return -EPERM;
if (of_device_is_compatible(vdev->dev.of_node, "hvterm1")) {
proto = HV_PROTOCOL_RAW;
ops = &hvterm_raw_ops;
} else if (of_device_is_compatible(vdev->dev.of_node, "hvterm-protocol")) {
proto = HV_PROTOCOL_HVSI;
ops = &hvterm_hvsi_ops;
} else {
pr_err("hvc_vio: Unknown protocol for %s\n", vdev->dev.of_node->full_name);
return -ENXIO;
}
pr_devel("hvc_vio_probe() device %s, using %s protocol\n",
vdev->dev.of_node->full_name,
proto == HV_PROTOCOL_RAW ? "raw" : "hvsi");
if (hvterm_privs[0] == &hvterm_priv0 &&
vdev->unit_address == hvterm_priv0.termno) {
pv = hvterm_privs[0];
termno = 0;
pr_devel("->boot console, using termno 0\n");
}
else {
for (i = 0; i < MAX_NR_HVC_CONSOLES && termno < 0; i++)
if (!hvterm_privs[i])
termno = i;
pr_devel("->non-boot console, using termno %d\n", termno);
if (termno < 0)
return -ENODEV;
pv = kzalloc(sizeof(struct hvterm_priv), GFP_KERNEL);
if (!pv)
return -ENOMEM;
pv->termno = vdev->unit_address;
pv->proto = proto;
spin_lock_init(&pv->buf_lock);
hvterm_privs[termno] = pv;
hvsilib_init(&pv->hvsi, hvc_get_chars, hvc_put_chars,
pv->termno, 0);
}
hp = hvc_alloc(termno, vdev->irq, ops, MAX_VIO_PUT_CHARS);
if (IS_ERR(hp))
return PTR_ERR(hp);
dev_set_drvdata(&vdev->dev, hp);
if (hp->index == 0 && !udbg_putc) {
udbg_putc = udbg_hvc_putc;
udbg_getc = udbg_hvc_getc;
udbg_getc_poll = udbg_hvc_getc_poll;
}
return 0;
}
static int __init hvc_vio_init(void)
{
int rc;
rc = vio_register_driver(&hvc_vio_driver);
return rc;
}
void __init hvc_vio_init_early(void)
{
const __be32 *termno;
const char *name;
const struct hv_ops *ops;
if (!of_stdout)
return;
name = of_get_property(of_stdout, "name", NULL);
if (!name) {
printk(KERN_WARNING "stdout node missing 'name' property!\n");
return;
}
if (strncmp(name, "vty", 3) != 0)
return;
termno = of_get_property(of_stdout, "reg", NULL);
if (termno == NULL)
return;
hvterm_priv0.termno = of_read_number(termno, 1);
spin_lock_init(&hvterm_priv0.buf_lock);
hvterm_privs[0] = &hvterm_priv0;
if (of_device_is_compatible(of_stdout, "hvterm1")) {
hvterm_priv0.proto = HV_PROTOCOL_RAW;
ops = &hvterm_raw_ops;
}
else if (of_device_is_compatible(of_stdout, "hvterm-protocol")) {
hvterm_priv0.proto = HV_PROTOCOL_HVSI;
ops = &hvterm_hvsi_ops;
hvsilib_init(&hvterm_priv0.hvsi, hvc_get_chars, hvc_put_chars,
hvterm_priv0.termno, 1);
hvsilib_establish(&hvterm_priv0.hvsi);
} else
return;
udbg_putc = udbg_hvc_putc;
udbg_getc = udbg_hvc_getc;
udbg_getc_poll = udbg_hvc_getc_poll;
#ifdef HVC_OLD_HVSI
if (hvterm_priv0.proto == HV_PROTOCOL_HVSI)
return;
#endif
if (!strstr(boot_command_line, "console="))
add_preferred_console("hvc", 0, NULL);
hvc_instantiate(0, 0, ops);
}
void __init udbg_init_debug_lpar(void)
{
hvterm_privs[0] = &hvterm_priv0;
hvterm_priv0.termno = 0;
hvterm_priv0.proto = HV_PROTOCOL_RAW;
spin_lock_init(&hvterm_priv0.buf_lock);
udbg_putc = udbg_hvc_putc;
udbg_getc = udbg_hvc_getc;
udbg_getc_poll = udbg_hvc_getc_poll;
}
void __init udbg_init_debug_lpar_hvsi(void)
{
hvterm_privs[0] = &hvterm_priv0;
hvterm_priv0.termno = CONFIG_PPC_EARLY_DEBUG_HVSI_VTERMNO;
hvterm_priv0.proto = HV_PROTOCOL_HVSI;
spin_lock_init(&hvterm_priv0.buf_lock);
udbg_putc = udbg_hvc_putc;
udbg_getc = udbg_hvc_getc;
udbg_getc_poll = udbg_hvc_getc_poll;
hvsilib_init(&hvterm_priv0.hvsi, hvc_get_chars, hvc_put_chars,
hvterm_priv0.termno, 1);
hvsilib_establish(&hvterm_priv0.hvsi);
}
