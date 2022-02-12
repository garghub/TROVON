static void
lba_dump_res(struct resource *r, int d)
{
int i;
if (NULL == r)
return;
printk(KERN_DEBUG "(%p)", r->parent);
for (i = d; i ; --i) printk(" ");
printk(KERN_DEBUG "%p [%lx,%lx]/%lx\n", r,
(long)r->start, (long)r->end, r->flags);
lba_dump_res(r->child, d+2);
lba_dump_res(r->sibling, d);
}
static int lba_device_present(u8 bus, u8 dfn, struct lba_device *d)
{
u8 first_bus = d->hba.hba_bus->busn_res.start;
u8 last_sub_bus = d->hba.hba_bus->busn_res.end;
if ((bus < first_bus) ||
(bus > last_sub_bus) ||
((bus - first_bus) >= LBA_MAX_NUM_BUSES)) {
return 0;
}
return 1;
}
static unsigned int
lba_rd_cfg(struct lba_device *d, u32 tok, u8 reg, u32 size)
{
u32 data = ~0U;
int error = 0;
u32 arb_mask = 0;
u32 error_config = 0;
u32 status_control = 0;
LBA_CFG_SETUP(d, tok);
LBA_CFG_PROBE(d, tok);
LBA_CFG_MASTER_ABORT_CHECK(d, d->hba.base_addr, tok, error);
if (!error) {
void __iomem *data_reg = d->hba.base_addr + LBA_PCI_CFG_DATA;
LBA_CFG_ADDR_SETUP(d, tok | reg);
switch (size) {
case 1: data = (u32) READ_REG8(data_reg + (reg & 3)); break;
case 2: data = (u32) READ_REG16(data_reg+ (reg & 2)); break;
case 4: data = READ_REG32(data_reg); break;
}
}
LBA_CFG_RESTORE(d, d->hba.base_addr);
return(data);
}
static int elroy_cfg_read(struct pci_bus *bus, unsigned int devfn, int pos, int size, u32 *data)
{
struct lba_device *d = LBA_DEV(parisc_walk_tree(bus->bridge));
u32 local_bus = (bus->parent == NULL) ? 0 : bus->busn_res.start;
u32 tok = LBA_CFG_TOK(local_bus, devfn);
void __iomem *data_reg = d->hba.base_addr + LBA_PCI_CFG_DATA;
if ((pos > 255) || (devfn > 255))
return -EINVAL;
{
*data = lba_rd_cfg(d, tok, pos, size);
DBG_CFG("%s(%x+%2x) -> 0x%x (a)\n", __func__, tok, pos, *data);
return 0;
}
if (LBA_SKIP_PROBE(d) && !lba_device_present(bus->busn_res.start, devfn, d)) {
DBG_CFG("%s(%x+%2x) -> -1 (b)\n", __func__, tok, pos);
*data = ~0U;
return(0);
}
LBA_CFG_ADDR_SETUP(d, tok | pos);
switch(size) {
case 1: *data = READ_REG8 (data_reg + (pos & 3)); break;
case 2: *data = READ_REG16(data_reg + (pos & 2)); break;
case 4: *data = READ_REG32(data_reg); break;
}
DBG_CFG("%s(%x+%2x) -> 0x%x (c)\n", __func__, tok, pos, *data);
return 0;
}
static void
lba_wr_cfg(struct lba_device *d, u32 tok, u8 reg, u32 data, u32 size)
{
int error = 0;
u32 arb_mask = 0;
u32 error_config = 0;
u32 status_control = 0;
void __iomem *data_reg = d->hba.base_addr + LBA_PCI_CFG_DATA;
LBA_CFG_SETUP(d, tok);
LBA_CFG_ADDR_SETUP(d, tok | reg);
switch (size) {
case 1: WRITE_REG8 (data, data_reg + (reg & 3)); break;
case 2: WRITE_REG16(data, data_reg + (reg & 2)); break;
case 4: WRITE_REG32(data, data_reg); break;
}
LBA_CFG_MASTER_ABORT_CHECK(d, d->hba.base_addr, tok, error);
LBA_CFG_RESTORE(d, d->hba.base_addr);
}
static int elroy_cfg_write(struct pci_bus *bus, unsigned int devfn, int pos, int size, u32 data)
{
struct lba_device *d = LBA_DEV(parisc_walk_tree(bus->bridge));
u32 local_bus = (bus->parent == NULL) ? 0 : bus->busn_res.start;
u32 tok = LBA_CFG_TOK(local_bus,devfn);
if ((pos > 255) || (devfn > 255))
return -EINVAL;
if (!LBA_SKIP_PROBE(d)) {
lba_wr_cfg(d, tok, pos, (u32) data, size);
DBG_CFG("%s(%x+%2x) = 0x%x (a)\n", __func__, tok, pos,data);
return 0;
}
if (LBA_SKIP_PROBE(d) && (!lba_device_present(bus->busn_res.start, devfn, d))) {
DBG_CFG("%s(%x+%2x) = 0x%x (b)\n", __func__, tok, pos,data);
return 1;
}
DBG_CFG("%s(%x+%2x) = 0x%x (c)\n", __func__, tok, pos, data);
LBA_CFG_ADDR_SETUP(d, tok | pos);
switch(size) {
case 1: WRITE_REG8 (data, d->hba.base_addr + LBA_PCI_CFG_DATA + (pos & 3));
break;
case 2: WRITE_REG16(data, d->hba.base_addr + LBA_PCI_CFG_DATA + (pos & 2));
break;
case 4: WRITE_REG32(data, d->hba.base_addr + LBA_PCI_CFG_DATA);
break;
}
lba_t32 = READ_REG32(d->hba.base_addr + LBA_PCI_CFG_ADDR);
return 0;
}
static int mercury_cfg_read(struct pci_bus *bus, unsigned int devfn, int pos, int size, u32 *data)
{
struct lba_device *d = LBA_DEV(parisc_walk_tree(bus->bridge));
u32 local_bus = (bus->parent == NULL) ? 0 : bus->busn_res.start;
u32 tok = LBA_CFG_TOK(local_bus, devfn);
void __iomem *data_reg = d->hba.base_addr + LBA_PCI_CFG_DATA;
if ((pos > 255) || (devfn > 255))
return -EINVAL;
LBA_CFG_TR4_ADDR_SETUP(d, tok | pos);
switch(size) {
case 1:
*data = READ_REG8(data_reg + (pos & 3));
break;
case 2:
*data = READ_REG16(data_reg + (pos & 2));
break;
case 4:
*data = READ_REG32(data_reg); break;
break;
}
DBG_CFG("mercury_cfg_read(%x+%2x) -> 0x%x\n", tok, pos, *data);
return 0;
}
static int mercury_cfg_write(struct pci_bus *bus, unsigned int devfn, int pos, int size, u32 data)
{
struct lba_device *d = LBA_DEV(parisc_walk_tree(bus->bridge));
void __iomem *data_reg = d->hba.base_addr + LBA_PCI_CFG_DATA;
u32 local_bus = (bus->parent == NULL) ? 0 : bus->busn_res.start;
u32 tok = LBA_CFG_TOK(local_bus,devfn);
if ((pos > 255) || (devfn > 255))
return -EINVAL;
DBG_CFG("%s(%x+%2x) <- 0x%x (c)\n", __func__, tok, pos, data);
LBA_CFG_TR4_ADDR_SETUP(d, tok | pos);
switch(size) {
case 1:
WRITE_REG8 (data, data_reg + (pos & 3));
break;
case 2:
WRITE_REG16(data, data_reg + (pos & 2));
break;
case 4:
WRITE_REG32(data, data_reg);
break;
}
lba_t32 = READ_U32(d->hba.base_addr + LBA_PCI_CFG_ADDR);
return 0;
}
static void
lba_bios_init(void)
{
DBG(MODULE_NAME ": lba_bios_init\n");
}
static unsigned long
truncate_pat_collision(struct resource *root, struct resource *new)
{
unsigned long start = new->start;
unsigned long end = new->end;
struct resource *tmp = root->child;
if (end <= start || start < root->start || !tmp)
return 0;
while (tmp && tmp->end < start)
tmp = tmp->sibling;
if (!tmp) return 0;
if (tmp->start >= end) return 0;
if (tmp->start <= start) {
new->start = tmp->end + 1;
if (tmp->end >= end) {
return 1;
}
}
if (tmp->end < end ) {
new->end = tmp->start - 1;
}
printk(KERN_WARNING "LBA: Truncating lmmio_space [%lx/%lx] "
"to [%lx,%lx]\n",
start, end,
(long)new->start, (long)new->end );
return 0;
}
static unsigned long
extend_lmmio_len(unsigned long start, unsigned long end, unsigned long lba_len)
{
struct resource *tmp;
if (boot_cpu_data.cpu_type < mako)
return end;
pr_debug("LMMIO mismatch: PAT length = 0x%lx, MASK register = 0x%lx\n",
end - start, lba_len);
lba_len = min(lba_len+1, 256UL*1024*1024);
pr_debug("LBA: lmmio_space [0x%lx-0x%lx] - original\n", start, end);
end += lba_len;
if (end < start)
end = -1ULL;
pr_debug("LBA: lmmio_space [0x%lx-0x%lx] - current\n", start, end);
for (tmp = iomem_resource.child; tmp; tmp = tmp->sibling) {
pr_debug("LBA: testing %pR\n", tmp);
if (tmp->start == start)
continue;
if (tmp->end < start)
continue;
if (tmp->start > end)
continue;
if (end >= tmp->start)
end = tmp->start - 1;
}
pr_info("LBA: lmmio_space [0x%lx-0x%lx] - new\n", start, end);
return end;
}
static void
lba_fixup_bus(struct pci_bus *bus)
{
struct pci_dev *dev;
#ifdef FBB_SUPPORT
u16 status;
#endif
struct lba_device *ldev = LBA_DEV(parisc_walk_tree(bus->bridge));
DBG("lba_fixup_bus(0x%p) bus %d platform_data 0x%p\n",
bus, (int)bus->busn_res.start, bus->bridge->platform_data);
if (bus->parent) {
int i;
pci_read_bridge_bases(bus);
for (i = PCI_BRIDGE_RESOURCES; i < PCI_NUM_RESOURCES; i++)
pci_claim_bridge_resource(bus->self, i);
} else {
int err;
DBG("lba_fixup_bus() %s [%lx/%lx]/%lx\n",
ldev->hba.io_space.name,
ldev->hba.io_space.start, ldev->hba.io_space.end,
ldev->hba.io_space.flags);
DBG("lba_fixup_bus() %s [%lx/%lx]/%lx\n",
ldev->hba.lmmio_space.name,
ldev->hba.lmmio_space.start, ldev->hba.lmmio_space.end,
ldev->hba.lmmio_space.flags);
err = request_resource(&ioport_resource, &(ldev->hba.io_space));
if (err < 0) {
lba_dump_res(&ioport_resource, 2);
BUG();
}
if (ldev->hba.elmmio_space.flags) {
err = request_resource(&iomem_resource,
&(ldev->hba.elmmio_space));
if (err < 0) {
printk("FAILED: lba_fixup_bus() request for "
"elmmio_space [%lx/%lx]\n",
(long)ldev->hba.elmmio_space.start,
(long)ldev->hba.elmmio_space.end);
}
}
if (ldev->hba.lmmio_space.flags) {
err = request_resource(&iomem_resource, &(ldev->hba.lmmio_space));
if (err < 0) {
printk(KERN_ERR "FAILED: lba_fixup_bus() request for "
"lmmio_space [%lx/%lx]\n",
(long)ldev->hba.lmmio_space.start,
(long)ldev->hba.lmmio_space.end);
}
}
#ifdef CONFIG_64BIT
if (ldev->hba.gmmio_space.flags) {
err = request_resource(&iomem_resource, &(ldev->hba.gmmio_space));
if (err < 0) {
printk("FAILED: lba_fixup_bus() request for "
"gmmio_space [%lx/%lx]\n",
(long)ldev->hba.gmmio_space.start,
(long)ldev->hba.gmmio_space.end);
lba_dump_res(&iomem_resource, 2);
BUG();
}
}
#endif
}
list_for_each_entry(dev, &bus->devices, bus_list) {
int i;
DBG("lba_fixup_bus() %s\n", pci_name(dev));
for (i = 0; i < PCI_BRIDGE_RESOURCES; i++) {
struct resource *res = &dev->resource[i];
if (!res->start)
continue;
pci_claim_resource(dev, i);
}
#ifdef FBB_SUPPORT
(void) pci_read_config_word(dev, PCI_STATUS, &status);
bus->bridge_ctl &= ~(status & PCI_STATUS_FAST_BACK);
#endif
if ((dev->class >> 8) == PCI_CLASS_BRIDGE_PCI) {
pcibios_init_bridge(dev);
continue;
}
iosapic_fixup_irq(ldev->iosapic_obj, dev);
}
#ifdef FBB_SUPPORT
if (fbb_enable) {
if (bus->parent) {
u8 control;
(void) pci_read_config_byte(bus->self, PCI_BRIDGE_CONTROL, &control);
(void) pci_write_config_byte(bus->self, PCI_BRIDGE_CONTROL, control | PCI_STATUS_FAST_BACK);
} else {
}
fbb_enable = PCI_COMMAND_FAST_BACK;
}
list_for_each_entry(dev, &bus->devices, bus_list) {
(void) pci_read_config_word(dev, PCI_COMMAND, &status);
status |= PCI_COMMAND_PARITY | PCI_COMMAND_SERR | fbb_enable;
(void) pci_write_config_word(dev, PCI_COMMAND, status);
}
#endif
}
static void
lba_pat_resources(struct parisc_device *pa_dev, struct lba_device *lba_dev)
{
unsigned long bytecnt;
long io_count;
long status;
long pa_count;
pdc_pat_cell_mod_maddr_block_t *pa_pdc_cell;
pdc_pat_cell_mod_maddr_block_t *io_pdc_cell;
int i;
pa_pdc_cell = kzalloc(sizeof(pdc_pat_cell_mod_maddr_block_t), GFP_KERNEL);
if (!pa_pdc_cell)
return;
io_pdc_cell = kzalloc(sizeof(pdc_pat_cell_mod_maddr_block_t), GFP_KERNEL);
if (!io_pdc_cell) {
kfree(pa_pdc_cell);
return;
}
status = pdc_pat_cell_module(&bytecnt, pa_dev->pcell_loc, pa_dev->mod_index,
PA_VIEW, pa_pdc_cell);
pa_count = pa_pdc_cell->mod[1];
status |= pdc_pat_cell_module(&bytecnt, pa_dev->pcell_loc, pa_dev->mod_index,
IO_VIEW, io_pdc_cell);
io_count = io_pdc_cell->mod[1];
if (status != PDC_OK) {
panic("pdc_pat_cell_module() call failed for LBA!\n");
}
if (PAT_GET_ENTITY(pa_pdc_cell->mod_info) != PAT_ENTITY_LBA) {
panic("pdc_pat_cell_module() entity returned != PAT_ENTITY_LBA!\n");
}
for (i = 0; i < pa_count; i++) {
struct {
unsigned long type;
unsigned long start;
unsigned long end;
} *p, *io;
struct resource *r;
p = (void *) &(pa_pdc_cell->mod[2+i*3]);
io = (void *) &(io_pdc_cell->mod[2+i*3]);
switch(p->type & 0xff) {
case PAT_PBNUM:
lba_dev->hba.bus_num.start = p->start;
lba_dev->hba.bus_num.end = p->end;
lba_dev->hba.bus_num.flags = IORESOURCE_BUS;
break;
case PAT_LMMIO:
if (!lba_dev->hba.lmmio_space.flags) {
unsigned long lba_len;
lba_len = ~READ_REG32(lba_dev->hba.base_addr
+ LBA_LMMIO_MASK);
if ((p->end - p->start) != lba_len)
p->end = extend_lmmio_len(p->start,
p->end, lba_len);
sprintf(lba_dev->hba.lmmio_name,
"PCI%02x LMMIO",
(int)lba_dev->hba.bus_num.start);
lba_dev->hba.lmmio_space_offset = p->start -
io->start;
r = &lba_dev->hba.lmmio_space;
r->name = lba_dev->hba.lmmio_name;
} else if (!lba_dev->hba.elmmio_space.flags) {
sprintf(lba_dev->hba.elmmio_name,
"PCI%02x ELMMIO",
(int)lba_dev->hba.bus_num.start);
r = &lba_dev->hba.elmmio_space;
r->name = lba_dev->hba.elmmio_name;
} else {
printk(KERN_WARNING MODULE_NAME
" only supports 2 LMMIO resources!\n");
break;
}
r->start = p->start;
r->end = p->end;
r->flags = IORESOURCE_MEM;
r->parent = r->sibling = r->child = NULL;
break;
case PAT_GMMIO:
sprintf(lba_dev->hba.gmmio_name, "PCI%02x GMMIO",
(int)lba_dev->hba.bus_num.start);
r = &lba_dev->hba.gmmio_space;
r->name = lba_dev->hba.gmmio_name;
r->start = p->start;
r->end = p->end;
r->flags = IORESOURCE_MEM;
r->parent = r->sibling = r->child = NULL;
break;
case PAT_NPIOP:
printk(KERN_WARNING MODULE_NAME
" range[%d] : ignoring NPIOP (0x%lx)\n",
i, p->start);
break;
case PAT_PIOP:
lba_dev->iop_base = ioremap_nocache(p->start, 64 * 1024 * 1024);
sprintf(lba_dev->hba.io_name, "PCI%02x Ports",
(int)lba_dev->hba.bus_num.start);
r = &lba_dev->hba.io_space;
r->name = lba_dev->hba.io_name;
r->start = HBA_PORT_BASE(lba_dev->hba.hba_num);
r->end = r->start + HBA_PORT_SPACE_SIZE - 1;
r->flags = IORESOURCE_IO;
r->parent = r->sibling = r->child = NULL;
break;
default:
printk(KERN_WARNING MODULE_NAME
" range[%d] : unknown pat range type (0x%lx)\n",
i, p->type & 0xff);
break;
}
}
kfree(pa_pdc_cell);
kfree(io_pdc_cell);
}
static void
lba_legacy_resources(struct parisc_device *pa_dev, struct lba_device *lba_dev)
{
struct resource *r;
int lba_num;
lba_dev->hba.lmmio_space_offset = PCI_F_EXTEND;
lba_num = READ_REG32(lba_dev->hba.base_addr + LBA_FW_SCRATCH);
r = &(lba_dev->hba.bus_num);
r->name = "LBA PCI Busses";
r->start = lba_num & 0xff;
r->end = (lba_num>>8) & 0xff;
r->flags = IORESOURCE_BUS;
r = &(lba_dev->hba.lmmio_space);
sprintf(lba_dev->hba.lmmio_name, "PCI%02x LMMIO",
(int)lba_dev->hba.bus_num.start);
r->name = lba_dev->hba.lmmio_name;
#if 1
sba_distributed_lmmio(pa_dev, r);
#else
r->start = READ_REG32(lba_dev->hba.base_addr + LBA_LMMIO_BASE);
if (r->start & 1) {
unsigned long rsize;
r->flags = IORESOURCE_MEM;
r->start &= mmio_mask;
r->start = PCI_HOST_ADDR(HBA_DATA(lba_dev), r->start);
rsize = ~ READ_REG32(lba_dev->hba.base_addr + LBA_LMMIO_MASK);
rsize /= ROPES_PER_IOC;
r->start += (rsize + 1) * LBA_NUM(pa_dev->hpa.start);
r->end = r->start + rsize;
} else {
r->end = r->start = 0;
}
#endif
r = &(lba_dev->hba.elmmio_space);
sprintf(lba_dev->hba.elmmio_name, "PCI%02x ELMMIO",
(int)lba_dev->hba.bus_num.start);
r->name = lba_dev->hba.elmmio_name;
#if 1
sba_directed_lmmio(pa_dev, r);
#else
r->start = READ_REG32(lba_dev->hba.base_addr + LBA_ELMMIO_BASE);
if (r->start & 1) {
unsigned long rsize;
r->flags = IORESOURCE_MEM;
r->start &= mmio_mask;
r->start = PCI_HOST_ADDR(HBA_DATA(lba_dev), r->start);
rsize = READ_REG32(lba_dev->hba.base_addr + LBA_ELMMIO_MASK);
r->end = r->start + ~rsize;
}
#endif
r = &(lba_dev->hba.io_space);
sprintf(lba_dev->hba.io_name, "PCI%02x Ports",
(int)lba_dev->hba.bus_num.start);
r->name = lba_dev->hba.io_name;
r->flags = IORESOURCE_IO;
r->start = READ_REG32(lba_dev->hba.base_addr + LBA_IOS_BASE) & ~1L;
r->end = r->start + (READ_REG32(lba_dev->hba.base_addr + LBA_IOS_MASK) ^ (HBA_PORT_SPACE_SIZE - 1));
lba_num = HBA_PORT_BASE(lba_dev->hba.hba_num);
r->start |= lba_num;
r->end |= lba_num;
}
static int __init
lba_hw_init(struct lba_device *d)
{
u32 stat;
u32 bus_reset;
#if 0
printk(KERN_DEBUG "LBA %lx STAT_CTL %Lx ERROR_CFG %Lx STATUS %Lx DMA_CTL %Lx\n",
d->hba.base_addr,
READ_REG64(d->hba.base_addr + LBA_STAT_CTL),
READ_REG64(d->hba.base_addr + LBA_ERROR_CONFIG),
READ_REG64(d->hba.base_addr + LBA_ERROR_STATUS),
READ_REG64(d->hba.base_addr + LBA_DMA_CTL) );
printk(KERN_DEBUG " ARB mask %Lx pri %Lx mode %Lx mtlt %Lx\n",
READ_REG64(d->hba.base_addr + LBA_ARB_MASK),
READ_REG64(d->hba.base_addr + LBA_ARB_PRI),
READ_REG64(d->hba.base_addr + LBA_ARB_MODE),
READ_REG64(d->hba.base_addr + LBA_ARB_MTLT) );
printk(KERN_DEBUG " HINT cfg 0x%Lx\n",
READ_REG64(d->hba.base_addr + LBA_HINT_CFG));
printk(KERN_DEBUG " HINT reg ");
{ int i;
for (i=LBA_HINT_BASE; i< (14*8 + LBA_HINT_BASE); i+=8)
printk(" %Lx", READ_REG64(d->hba.base_addr + i));
}
printk("\n");
#endif
#ifdef CONFIG_64BIT
#endif
bus_reset = READ_REG32(d->hba.base_addr + LBA_STAT_CTL + 4) & 1;
if (bus_reset) {
printk(KERN_DEBUG "NOTICE: PCI bus reset still asserted! (clearing)\n");
}
stat = READ_REG32(d->hba.base_addr + LBA_ERROR_CONFIG);
if (stat & LBA_SMART_MODE) {
printk(KERN_DEBUG "NOTICE: LBA in SMART mode! (cleared)\n");
stat &= ~LBA_SMART_MODE;
WRITE_REG32(stat, d->hba.base_addr + LBA_ERROR_CONFIG);
}
stat = READ_REG32(d->hba.base_addr + LBA_STAT_CTL);
WRITE_REG32(stat | HF_ENABLE, d->hba.base_addr + LBA_STAT_CTL);
if (bus_reset)
mdelay(pci_post_reset_delay);
if (0 == READ_REG32(d->hba.base_addr + LBA_ARB_MASK)) {
printk(KERN_DEBUG "NOTICE: Enabling PCI Arbitration\n");
WRITE_REG32(0x3, d->hba.base_addr + LBA_ARB_MASK);
}
return 0;
}
static int __init
lba_driver_probe(struct parisc_device *dev)
{
struct lba_device *lba_dev;
LIST_HEAD(resources);
struct pci_bus *lba_bus;
struct pci_ops *cfg_ops;
u32 func_class;
void *tmp_obj;
char *version;
void __iomem *addr = ioremap_nocache(dev->hpa.start, 4096);
int max;
func_class = READ_REG32(addr + LBA_FCLASS);
if (IS_ELROY(dev)) {
func_class &= 0xf;
switch (func_class) {
case 0: version = "TR1.0"; break;
case 1: version = "TR2.0"; break;
case 2: version = "TR2.1"; break;
case 3: version = "TR2.2"; break;
case 4: version = "TR3.0"; break;
case 5: version = "TR4.0"; break;
default: version = "TR4+";
}
printk(KERN_INFO "Elroy version %s (0x%x) found at 0x%lx\n",
version, func_class & 0xf, (long)dev->hpa.start);
if (func_class < 2) {
printk(KERN_WARNING "Can't support LBA older than "
"TR2.1 - continuing under adversity.\n");
}
#if 0
if (func_class > 4) {
cfg_ops = &mercury_cfg_ops;
} else
#endif
{
cfg_ops = &elroy_cfg_ops;
}
} else if (IS_MERCURY(dev) || IS_QUICKSILVER(dev)) {
int major, minor;
func_class &= 0xff;
major = func_class >> 4, minor = func_class & 0xf;
printk(KERN_INFO "%s version TR%d.%d (0x%x) found at 0x%lx\n",
IS_MERCURY(dev) ? "Mercury" : "Quicksilver", major,
minor, func_class, (long)dev->hpa.start);
cfg_ops = &mercury_cfg_ops;
} else {
printk(KERN_ERR "Unknown LBA found at 0x%lx\n",
(long)dev->hpa.start);
return -ENODEV;
}
tmp_obj = iosapic_register(dev->hpa.start + LBA_IOSAPIC_BASE);
lba_dev = kzalloc(sizeof(struct lba_device), GFP_KERNEL);
if (!lba_dev) {
printk(KERN_ERR "lba_init_chip - couldn't alloc lba_device\n");
return(1);
}
lba_dev->hw_rev = func_class;
lba_dev->hba.base_addr = addr;
lba_dev->hba.dev = dev;
lba_dev->iosapic_obj = tmp_obj;
lba_dev->hba.iommu = sba_get_iommu(dev);
parisc_set_drvdata(dev, lba_dev);
pci_bios = &lba_bios_ops;
pcibios_register_hba(HBA_DATA(lba_dev));
spin_lock_init(&lba_dev->lba_lock);
if (lba_hw_init(lba_dev))
return(1);
if (is_pdc_pat()) {
pci_port = &lba_pat_port_ops;
lba_pat_resources(dev, lba_dev);
} else {
if (!astro_iop_base) {
astro_iop_base = ioremap_nocache(LBA_PORT_BASE, 64 * 1024);
pci_port = &lba_astro_port_ops;
}
lba_legacy_resources(dev, lba_dev);
}
if (lba_dev->hba.bus_num.start < lba_next_bus)
lba_dev->hba.bus_num.start = lba_next_bus;
if (truncate_pat_collision(&iomem_resource,
&(lba_dev->hba.lmmio_space))) {
printk(KERN_WARNING "LBA: lmmio_space [%lx/%lx] duplicate!\n",
(long)lba_dev->hba.lmmio_space.start,
(long)lba_dev->hba.lmmio_space.end);
lba_dev->hba.lmmio_space.flags = 0;
}
pci_add_resource_offset(&resources, &lba_dev->hba.io_space,
HBA_PORT_BASE(lba_dev->hba.hba_num));
if (lba_dev->hba.elmmio_space.flags)
pci_add_resource_offset(&resources, &lba_dev->hba.elmmio_space,
lba_dev->hba.lmmio_space_offset);
if (lba_dev->hba.lmmio_space.flags)
pci_add_resource_offset(&resources, &lba_dev->hba.lmmio_space,
lba_dev->hba.lmmio_space_offset);
if (lba_dev->hba.gmmio_space.flags) {
}
pci_add_resource(&resources, &lba_dev->hba.bus_num);
dev->dev.platform_data = lba_dev;
lba_bus = lba_dev->hba.hba_bus =
pci_create_root_bus(&dev->dev, lba_dev->hba.bus_num.start,
cfg_ops, NULL, &resources);
if (!lba_bus) {
pci_free_resource_list(&resources);
return 0;
}
max = pci_scan_child_bus(lba_bus);
if (is_pdc_pat()) {
DBG_PAT("LBA pci_bus_size_bridges()\n");
pci_bus_size_bridges(lba_bus);
DBG_PAT("LBA pci_bus_assign_resources()\n");
pci_bus_assign_resources(lba_bus);
#ifdef DEBUG_LBA_PAT
DBG_PAT("\nLBA PIOP resource tree\n");
lba_dump_res(&lba_dev->hba.io_space, 2);
DBG_PAT("\nLBA LMMIO resource tree\n");
lba_dump_res(&lba_dev->hba.lmmio_space, 2);
#endif
}
if (cfg_ops == &elroy_cfg_ops) {
lba_dev->flags |= LBA_FLAG_SKIP_PROBE;
}
lba_next_bus = max + 1;
pci_bus_add_devices(lba_bus);
return 0;
}
void __init lba_init(void)
{
register_parisc_driver(&lba_driver);
}
void lba_set_iregs(struct parisc_device *lba, u32 ibase, u32 imask)
{
void __iomem * base_addr = ioremap_nocache(lba->hpa.start, 4096);
imask <<= 2;
WARN_ON((ibase & 0x001fffff) != 0);
WARN_ON((imask & 0x001fffff) != 0);
DBG("%s() ibase 0x%x imask 0x%x\n", __func__, ibase, imask);
WRITE_REG32( imask, base_addr + LBA_IMASK);
WRITE_REG32( ibase, base_addr + LBA_IBASE);
iounmap(base_addr);
}
