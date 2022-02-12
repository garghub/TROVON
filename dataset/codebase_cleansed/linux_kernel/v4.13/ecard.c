static inline unsigned short ecard_getu16(unsigned char *v)
{
return v[0] | v[1] << 8;
}
static inline signed long ecard_gets24(unsigned char *v)
{
return v[0] | v[1] << 8 | v[2] << 16 | ((v[2] & 0x80) ? 0xff000000 : 0);
}
static inline ecard_t *slot_to_ecard(unsigned int slot)
{
return slot < MAX_ECARDS ? slot_to_expcard[slot] : NULL;
}
static void ecard_task_reset(struct ecard_request *req)
{
struct expansion_card *ec = req->ec;
struct resource *res;
res = ec->slot_no == 8
? &ec->resource[ECARD_RES_MEMC]
: ec->easi
? &ec->resource[ECARD_RES_EASI]
: &ec->resource[ECARD_RES_IOCSYNC];
ecard_loader_reset(res->start, ec->loader);
}
static void ecard_task_readbytes(struct ecard_request *req)
{
struct expansion_card *ec = req->ec;
unsigned char *buf = req->buffer;
unsigned int len = req->length;
unsigned int off = req->address;
if (ec->slot_no == 8) {
void __iomem *base = (void __iomem *)
ec->resource[ECARD_RES_MEMC].start;
static unsigned int index;
unsigned int page;
page = (off >> 12) * 4;
if (page > 256 * 4)
return;
off &= 4095;
if (off == 0 || index > off) {
writeb(0, base);
index = 0;
}
while (index < off) {
readb(base + page);
index += 1;
}
while (len--) {
*buf++ = readb(base + page);
index += 1;
}
} else {
unsigned long base = (ec->easi
? &ec->resource[ECARD_RES_EASI]
: &ec->resource[ECARD_RES_IOCSYNC])->start;
void __iomem *pbase = (void __iomem *)base;
if (!req->use_loader || !ec->loader) {
off *= 4;
while (len--) {
*buf++ = readb(pbase + off);
off += 4;
}
} else {
while(len--) {
*(unsigned long *)0x108 = 0;
*buf++ = ecard_loader_read(off++, base,
ec->loader);
}
}
}
}
static void ecard_init_pgtables(struct mm_struct *mm)
{
struct vm_area_struct vma;
pgd_t *src_pgd, *dst_pgd;
src_pgd = pgd_offset(mm, (unsigned long)IO_BASE);
dst_pgd = pgd_offset(mm, IO_START);
memcpy(dst_pgd, src_pgd, sizeof(pgd_t) * (IO_SIZE / PGDIR_SIZE));
src_pgd = pgd_offset(mm, (unsigned long)EASI_BASE);
dst_pgd = pgd_offset(mm, EASI_START);
memcpy(dst_pgd, src_pgd, sizeof(pgd_t) * (EASI_SIZE / PGDIR_SIZE));
vma.vm_flags = VM_EXEC;
vma.vm_mm = mm;
flush_tlb_range(&vma, IO_START, IO_START + IO_SIZE);
flush_tlb_range(&vma, EASI_START, EASI_START + EASI_SIZE);
}
static int ecard_init_mm(void)
{
struct mm_struct * mm = mm_alloc();
struct mm_struct *active_mm = current->active_mm;
if (!mm)
return -ENOMEM;
current->mm = mm;
current->active_mm = mm;
activate_mm(active_mm, mm);
mmdrop(active_mm);
ecard_init_pgtables(mm);
return 0;
}
static int
ecard_task(void * unused)
{
if (ecard_init_mm())
panic("kecardd: unable to alloc mm\n");
while (1) {
struct ecard_request *req;
wait_event_interruptible(ecard_wait, ecard_req != NULL);
req = xchg(&ecard_req, NULL);
if (req != NULL) {
req->fn(req);
complete(req->complete);
}
}
}
static void ecard_call(struct ecard_request *req)
{
DECLARE_COMPLETION_ONSTACK(completion);
req->complete = &completion;
mutex_lock(&ecard_mutex);
ecard_req = req;
wake_up(&ecard_wait);
wait_for_completion(&completion);
mutex_unlock(&ecard_mutex);
}
static void
ecard_readbytes(void *addr, ecard_t *ec, int off, int len, int useld)
{
struct ecard_request req;
req.fn = ecard_task_readbytes;
req.ec = ec;
req.address = off;
req.length = len;
req.use_loader = useld;
req.buffer = addr;
ecard_call(&req);
}
int ecard_readchunk(struct in_chunk_dir *cd, ecard_t *ec, int id, int num)
{
struct ex_chunk_dir excd;
int index = 16;
int useld = 0;
if (!ec->cid.cd)
return 0;
while(1) {
ecard_readbytes(&excd, ec, index, 8, useld);
index += 8;
if (c_id(&excd) == 0) {
if (!useld && ec->loader) {
useld = 1;
index = 0;
continue;
}
return 0;
}
if (c_id(&excd) == 0xf0) {
index = c_start(&excd);
continue;
}
if (c_id(&excd) == 0x80) {
if (!ec->loader) {
ec->loader = kmalloc(c_len(&excd),
GFP_KERNEL);
if (ec->loader)
ecard_readbytes(ec->loader, ec,
(int)c_start(&excd),
c_len(&excd), useld);
else
return 0;
}
continue;
}
if (c_id(&excd) == id && num-- == 0)
break;
}
if (c_id(&excd) & 0x80) {
switch (c_id(&excd) & 0x70) {
case 0x70:
ecard_readbytes((unsigned char *)excd.d.string, ec,
(int)c_start(&excd), c_len(&excd),
useld);
break;
case 0x00:
break;
}
}
cd->start_offset = c_start(&excd);
memcpy(cd->d.string, excd.d.string, 256);
return 1;
}
static void ecard_def_irq_enable(ecard_t *ec, int irqnr)
{
}
static void ecard_def_irq_disable(ecard_t *ec, int irqnr)
{
}
static int ecard_def_irq_pending(ecard_t *ec)
{
return !ec->irqmask || readb(ec->irqaddr) & ec->irqmask;
}
static void ecard_def_fiq_enable(ecard_t *ec, int fiqnr)
{
panic("ecard_def_fiq_enable called - impossible");
}
static void ecard_def_fiq_disable(ecard_t *ec, int fiqnr)
{
panic("ecard_def_fiq_disable called - impossible");
}
static int ecard_def_fiq_pending(ecard_t *ec)
{
return !ec->fiqmask || readb(ec->fiqaddr) & ec->fiqmask;
}
static void ecard_irq_unmask(struct irq_data *d)
{
ecard_t *ec = irq_data_get_irq_chip_data(d);
if (ec) {
if (!ec->ops)
ec->ops = &ecard_default_ops;
if (ec->claimed && ec->ops->irqenable)
ec->ops->irqenable(ec, d->irq);
else
printk(KERN_ERR "ecard: rejecting request to "
"enable IRQs for %d\n", d->irq);
}
}
static void ecard_irq_mask(struct irq_data *d)
{
ecard_t *ec = irq_data_get_irq_chip_data(d);
if (ec) {
if (!ec->ops)
ec->ops = &ecard_default_ops;
if (ec->ops && ec->ops->irqdisable)
ec->ops->irqdisable(ec, d->irq);
}
}
void ecard_enablefiq(unsigned int fiqnr)
{
ecard_t *ec = slot_to_ecard(fiqnr);
if (ec) {
if (!ec->ops)
ec->ops = &ecard_default_ops;
if (ec->claimed && ec->ops->fiqenable)
ec->ops->fiqenable(ec, fiqnr);
else
printk(KERN_ERR "ecard: rejecting request to "
"enable FIQs for %d\n", fiqnr);
}
}
void ecard_disablefiq(unsigned int fiqnr)
{
ecard_t *ec = slot_to_ecard(fiqnr);
if (ec) {
if (!ec->ops)
ec->ops = &ecard_default_ops;
if (ec->ops->fiqdisable)
ec->ops->fiqdisable(ec, fiqnr);
}
}
static void ecard_dump_irq_state(void)
{
ecard_t *ec;
printk("Expansion card IRQ state:\n");
for (ec = cards; ec; ec = ec->next) {
if (ec->slot_no == 8)
continue;
printk(" %d: %sclaimed, ",
ec->slot_no, ec->claimed ? "" : "not ");
if (ec->ops && ec->ops->irqpending &&
ec->ops != &ecard_default_ops)
printk("irq %spending\n",
ec->ops->irqpending(ec) ? "" : "not ");
else
printk("irqaddr %p, mask = %02X, status = %02X\n",
ec->irqaddr, ec->irqmask, readb(ec->irqaddr));
}
}
static void ecard_check_lockup(struct irq_desc *desc)
{
static unsigned long last;
static int lockup;
if (last == jiffies) {
lockup += 1;
if (lockup > 1000000) {
printk(KERN_ERR "\nInterrupt lockup detected - "
"disabling all expansion card interrupts\n");
desc->irq_data.chip->irq_mask(&desc->irq_data);
ecard_dump_irq_state();
}
} else
lockup = 0;
if (!last || time_after(jiffies, last + 5*HZ)) {
last = jiffies;
printk(KERN_WARNING "Unrecognised interrupt from backplane\n");
ecard_dump_irq_state();
}
}
static void ecard_irq_handler(struct irq_desc *desc)
{
ecard_t *ec;
int called = 0;
desc->irq_data.chip->irq_mask(&desc->irq_data);
for (ec = cards; ec; ec = ec->next) {
int pending;
if (!ec->claimed || !ec->irq || ec->slot_no == 8)
continue;
if (ec->ops && ec->ops->irqpending)
pending = ec->ops->irqpending(ec);
else
pending = ecard_default_ops.irqpending(ec);
if (pending) {
generic_handle_irq(ec->irq);
called ++;
}
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
if (called == 0)
ecard_check_lockup(desc);
}
static void __iomem *__ecard_address(ecard_t *ec, card_type_t type, card_speed_t speed)
{
void __iomem *address = NULL;
int slot = ec->slot_no;
if (ec->slot_no == 8)
return ECARD_MEMC8_BASE;
ectcr &= ~(1 << slot);
switch (type) {
case ECARD_MEMC:
if (slot < 4)
address = ECARD_MEMC_BASE + (slot << 14);
break;
case ECARD_IOC:
if (slot < 4)
address = ECARD_IOC_BASE + (slot << 14);
else
address = ECARD_IOC4_BASE + ((slot - 4) << 14);
if (address)
address += speed << 19;
break;
case ECARD_EASI:
address = ECARD_EASI_BASE + (slot << 24);
if (speed == ECARD_FAST)
ectcr |= 1 << slot;
break;
default:
break;
}
#ifdef IOMD_ECTCR
iomd_writeb(ectcr, IOMD_ECTCR);
#endif
return address;
}
static int ecard_prints(struct seq_file *m, ecard_t *ec)
{
seq_printf(m, " %d: %s ", ec->slot_no, ec->easi ? "EASI" : " ");
if (ec->cid.id == 0) {
struct in_chunk_dir incd;
seq_printf(m, "[%04X:%04X] ",
ec->cid.manufacturer, ec->cid.product);
if (!ec->card_desc && ec->cid.cd &&
ecard_readchunk(&incd, ec, 0xf5, 0)) {
ec->card_desc = kmalloc(strlen(incd.d.string)+1, GFP_KERNEL);
if (ec->card_desc)
strcpy((char *)ec->card_desc, incd.d.string);
}
seq_printf(m, "%s\n", ec->card_desc ? ec->card_desc : "*unknown*");
} else
seq_printf(m, "Simple card %d\n", ec->cid.id);
return 0;
}
static int ecard_devices_proc_show(struct seq_file *m, void *v)
{
ecard_t *ec = cards;
while (ec) {
ecard_prints(m, ec);
ec = ec->next;
}
return 0;
}
static int ecard_devices_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ecard_devices_proc_show, NULL);
}
static void ecard_proc_init(void)
{
proc_bus_ecard_dir = proc_mkdir("bus/ecard", NULL);
proc_create("devices", 0, proc_bus_ecard_dir, &bus_ecard_proc_fops);
}
static void __init ecard_free_card(struct expansion_card *ec)
{
int i;
for (i = 0; i < ECARD_NUM_RESOURCES; i++)
if (ec->resource[i].flags)
release_resource(&ec->resource[i]);
kfree(ec);
}
static struct expansion_card *__init ecard_alloc_card(int type, int slot)
{
struct expansion_card *ec;
unsigned long base;
int i;
ec = kzalloc(sizeof(ecard_t), GFP_KERNEL);
if (!ec) {
ec = ERR_PTR(-ENOMEM);
goto nomem;
}
ec->slot_no = slot;
ec->easi = type == ECARD_EASI;
ec->irq = 0;
ec->fiq = 0;
ec->dma = NO_DMA;
ec->ops = &ecard_default_ops;
dev_set_name(&ec->dev, "ecard%d", slot);
ec->dev.parent = NULL;
ec->dev.bus = &ecard_bus_type;
ec->dev.dma_mask = &ec->dma_mask;
ec->dma_mask = (u64)0xffffffff;
ec->dev.coherent_dma_mask = ec->dma_mask;
if (slot < 4) {
ec_set_resource(ec, ECARD_RES_MEMC,
PODSLOT_MEMC_BASE + (slot << 14),
PODSLOT_MEMC_SIZE);
base = PODSLOT_IOC0_BASE + (slot << 14);
} else
base = PODSLOT_IOC4_BASE + ((slot - 4) << 14);
#ifdef CONFIG_ARCH_RPC
if (slot < 8) {
ec_set_resource(ec, ECARD_RES_EASI,
PODSLOT_EASI_BASE + (slot << 24),
PODSLOT_EASI_SIZE);
}
if (slot == 8) {
ec_set_resource(ec, ECARD_RES_MEMC, NETSLOT_BASE, NETSLOT_SIZE);
} else
#endif
for (i = 0; i <= ECARD_RES_IOCSYNC - ECARD_RES_IOCSLOW; i++)
ec_set_resource(ec, i + ECARD_RES_IOCSLOW,
base + (i << 19), PODSLOT_IOC_SIZE);
for (i = 0; i < ECARD_NUM_RESOURCES; i++) {
if (ec->resource[i].flags &&
request_resource(&iomem_resource, &ec->resource[i])) {
dev_err(&ec->dev, "resource(s) not available\n");
ec->resource[i].end -= ec->resource[i].start;
ec->resource[i].start = 0;
ec->resource[i].flags = 0;
}
}
nomem:
return ec;
}
static ssize_t irq_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct expansion_card *ec = ECARD_DEV(dev);
return sprintf(buf, "%u\n", ec->irq);
}
static ssize_t dma_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct expansion_card *ec = ECARD_DEV(dev);
return sprintf(buf, "%u\n", ec->dma);
}
static ssize_t resource_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct expansion_card *ec = ECARD_DEV(dev);
char *str = buf;
int i;
for (i = 0; i < ECARD_NUM_RESOURCES; i++)
str += sprintf(str, "%08x %08x %08lx\n",
ec->resource[i].start,
ec->resource[i].end,
ec->resource[i].flags);
return str - buf;
}
static ssize_t vendor_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct expansion_card *ec = ECARD_DEV(dev);
return sprintf(buf, "%u\n", ec->cid.manufacturer);
}
static ssize_t device_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct expansion_card *ec = ECARD_DEV(dev);
return sprintf(buf, "%u\n", ec->cid.product);
}
static ssize_t type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct expansion_card *ec = ECARD_DEV(dev);
return sprintf(buf, "%s\n", ec->easi ? "EASI" : "IOC");
}
int ecard_request_resources(struct expansion_card *ec)
{
int i, err = 0;
for (i = 0; i < ECARD_NUM_RESOURCES; i++) {
if (ecard_resource_end(ec, i) &&
!request_mem_region(ecard_resource_start(ec, i),
ecard_resource_len(ec, i),
ec->dev.driver->name)) {
err = -EBUSY;
break;
}
}
if (err) {
while (i--)
if (ecard_resource_end(ec, i))
release_mem_region(ecard_resource_start(ec, i),
ecard_resource_len(ec, i));
}
return err;
}
void ecard_release_resources(struct expansion_card *ec)
{
int i;
for (i = 0; i < ECARD_NUM_RESOURCES; i++)
if (ecard_resource_end(ec, i))
release_mem_region(ecard_resource_start(ec, i),
ecard_resource_len(ec, i));
}
void ecard_setirq(struct expansion_card *ec, const struct expansion_card_ops *ops, void *irq_data)
{
ec->irq_data = irq_data;
barrier();
ec->ops = ops;
}
void __iomem *ecardm_iomap(struct expansion_card *ec, unsigned int res,
unsigned long offset, unsigned long maxsize)
{
unsigned long start = ecard_resource_start(ec, res);
unsigned long end = ecard_resource_end(ec, res);
if (offset > (end - start))
return NULL;
start += offset;
if (maxsize && end - start > maxsize)
end = start + maxsize;
return devm_ioremap(&ec->dev, start, end - start);
}
static int __init ecard_probe(int slot, unsigned irq, card_type_t type)
{
ecard_t **ecp;
ecard_t *ec;
struct ex_ecid cid;
void __iomem *addr;
int i, rc;
ec = ecard_alloc_card(type, slot);
if (IS_ERR(ec)) {
rc = PTR_ERR(ec);
goto nomem;
}
rc = -ENODEV;
if ((addr = __ecard_address(ec, type, ECARD_SYNC)) == NULL)
goto nodev;
cid.r_zero = 1;
ecard_readbytes(&cid, ec, 0, 16, 0);
if (cid.r_zero)
goto nodev;
ec->cid.id = cid.r_id;
ec->cid.cd = cid.r_cd;
ec->cid.is = cid.r_is;
ec->cid.w = cid.r_w;
ec->cid.manufacturer = ecard_getu16(cid.r_manu);
ec->cid.product = ecard_getu16(cid.r_prod);
ec->cid.country = cid.r_country;
ec->cid.irqmask = cid.r_irqmask;
ec->cid.irqoff = ecard_gets24(cid.r_irqoff);
ec->cid.fiqmask = cid.r_fiqmask;
ec->cid.fiqoff = ecard_gets24(cid.r_fiqoff);
ec->fiqaddr =
ec->irqaddr = addr;
if (ec->cid.is) {
ec->irqmask = ec->cid.irqmask;
ec->irqaddr += ec->cid.irqoff;
ec->fiqmask = ec->cid.fiqmask;
ec->fiqaddr += ec->cid.fiqoff;
} else {
ec->irqmask = 1;
ec->fiqmask = 4;
}
for (i = 0; i < ARRAY_SIZE(blacklist); i++)
if (blacklist[i].manufacturer == ec->cid.manufacturer &&
blacklist[i].product == ec->cid.product) {
ec->card_desc = blacklist[i].type;
break;
}
ec->irq = irq;
if (slot < 8) {
irq_set_chip_and_handler(ec->irq, &ecard_chip,
handle_level_irq);
irq_set_chip_data(ec->irq, ec);
irq_clear_status_flags(ec->irq, IRQ_NOREQUEST);
}
#ifdef CONFIG_ARCH_RPC
if (slot < 2)
ec->dma = 2 + slot;
#endif
for (ecp = &cards; *ecp; ecp = &(*ecp)->next);
*ecp = ec;
slot_to_expcard[slot] = ec;
rc = device_register(&ec->dev);
if (rc)
goto nodev;
return 0;
nodev:
ecard_free_card(ec);
nomem:
return rc;
}
static int __init ecard_init(void)
{
struct task_struct *task;
int slot, irqbase;
irqbase = irq_alloc_descs(-1, 0, 8, -1);
if (irqbase < 0)
return irqbase;
task = kthread_run(ecard_task, NULL, "kecardd");
if (IS_ERR(task)) {
printk(KERN_ERR "Ecard: unable to create kernel thread: %ld\n",
PTR_ERR(task));
irq_free_descs(irqbase, 8);
return PTR_ERR(task);
}
printk("Probing expansion cards\n");
for (slot = 0; slot < 8; slot ++) {
if (ecard_probe(slot, irqbase + slot, ECARD_EASI) == -ENODEV)
ecard_probe(slot, irqbase + slot, ECARD_IOC);
}
ecard_probe(8, 11, ECARD_IOC);
irq_set_chained_handler(IRQ_EXPANSIONCARD, ecard_irq_handler);
ecard_proc_init();
return 0;
}
static const struct ecard_id *
ecard_match_device(const struct ecard_id *ids, struct expansion_card *ec)
{
int i;
for (i = 0; ids[i].manufacturer != 65535; i++)
if (ec->cid.manufacturer == ids[i].manufacturer &&
ec->cid.product == ids[i].product)
return ids + i;
return NULL;
}
static int ecard_drv_probe(struct device *dev)
{
struct expansion_card *ec = ECARD_DEV(dev);
struct ecard_driver *drv = ECARD_DRV(dev->driver);
const struct ecard_id *id;
int ret;
id = ecard_match_device(drv->id_table, ec);
ec->claimed = 1;
ret = drv->probe(ec, id);
if (ret)
ec->claimed = 0;
return ret;
}
static int ecard_drv_remove(struct device *dev)
{
struct expansion_card *ec = ECARD_DEV(dev);
struct ecard_driver *drv = ECARD_DRV(dev->driver);
drv->remove(ec);
ec->claimed = 0;
ec->ops = &ecard_default_ops;
barrier();
ec->irq_data = NULL;
return 0;
}
static void ecard_drv_shutdown(struct device *dev)
{
struct expansion_card *ec = ECARD_DEV(dev);
struct ecard_driver *drv = ECARD_DRV(dev->driver);
struct ecard_request req;
if (dev->driver) {
if (drv->shutdown)
drv->shutdown(ec);
ec->claimed = 0;
}
if (ec->loader) {
req.fn = ecard_task_reset;
req.ec = ec;
ecard_call(&req);
}
}
int ecard_register_driver(struct ecard_driver *drv)
{
drv->drv.bus = &ecard_bus_type;
return driver_register(&drv->drv);
}
void ecard_remove_driver(struct ecard_driver *drv)
{
driver_unregister(&drv->drv);
}
static int ecard_match(struct device *_dev, struct device_driver *_drv)
{
struct expansion_card *ec = ECARD_DEV(_dev);
struct ecard_driver *drv = ECARD_DRV(_drv);
int ret;
if (drv->id_table) {
ret = ecard_match_device(drv->id_table, ec) != NULL;
} else {
ret = ec->cid.id == drv->id;
}
return ret;
}
static int ecard_bus_init(void)
{
return bus_register(&ecard_bus_type);
}
