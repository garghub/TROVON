static void ser_init()
{
unsigned port=COM_BASE;
outb(0x80,port+3);
outb(0,port+1);
outb(6, port);
outb(3,port+3);
outb(0,port+1);
}
static void ser_puts(char *str)
{
char *ptr;
ser_init();
for (ptr=str;*ptr;++ptr)
ser_putc(*ptr);
}
static void ser_putc(char c)
{
unsigned port=COM_BASE;
while ((inb(port+5) & 0x20)==0);
outb(c,port);
if (c==0x0a)
{
while ((inb(port+5) & 0x20)==0);
outb(0x0d,port);
}
}
static int ser_printk(const char *fmt, ...)
{
va_list args;
int i;
va_start(args,fmt);
i = vsprintf(strbuf,fmt,args);
ser_puts(strbuf);
va_end(args);
return i;
}
static gdth_ha_str *gdth_find_ha(int hanum)
{
gdth_ha_str *ha;
list_for_each_entry(ha, &gdth_instances, list)
if (hanum == ha->hanum)
return ha;
return NULL;
}
static struct gdth_cmndinfo *gdth_get_cmndinfo(gdth_ha_str *ha)
{
struct gdth_cmndinfo *priv = NULL;
unsigned long flags;
int i;
spin_lock_irqsave(&ha->smp_lock, flags);
for (i=0; i<GDTH_MAXCMDS; ++i) {
if (ha->cmndinfo[i].index == 0) {
priv = &ha->cmndinfo[i];
memset(priv, 0, sizeof(*priv));
priv->index = i+1;
break;
}
}
spin_unlock_irqrestore(&ha->smp_lock, flags);
return priv;
}
static void gdth_put_cmndinfo(struct gdth_cmndinfo *priv)
{
BUG_ON(!priv);
priv->index = 0;
}
static void gdth_delay(int milliseconds)
{
if (milliseconds == 0) {
udelay(1);
} else {
mdelay(milliseconds);
}
}
static void gdth_scsi_done(struct scsi_cmnd *scp)
{
struct gdth_cmndinfo *cmndinfo = gdth_cmnd_priv(scp);
int internal_command = cmndinfo->internal_command;
TRACE2(("gdth_scsi_done()\n"));
gdth_put_cmndinfo(cmndinfo);
scp->host_scribble = NULL;
if (internal_command)
complete((struct completion *)scp->request);
else
scp->scsi_done(scp);
}
int __gdth_execute(struct scsi_device *sdev, gdth_cmd_str *gdtcmd, char *cmnd,
int timeout, u32 *info)
{
gdth_ha_str *ha = shost_priv(sdev->host);
Scsi_Cmnd *scp;
struct gdth_cmndinfo cmndinfo;
DECLARE_COMPLETION_ONSTACK(wait);
int rval;
scp = kzalloc(sizeof(*scp), GFP_KERNEL);
if (!scp)
return -ENOMEM;
scp->sense_buffer = kzalloc(SCSI_SENSE_BUFFERSIZE, GFP_KERNEL);
if (!scp->sense_buffer) {
kfree(scp);
return -ENOMEM;
}
scp->device = sdev;
memset(&cmndinfo, 0, sizeof(cmndinfo));
scp->request = (struct request *)&wait;
scp->cmd_len = 12;
scp->cmnd = cmnd;
cmndinfo.priority = IOCTL_PRI;
cmndinfo.internal_cmd_str = gdtcmd;
cmndinfo.internal_command = 1;
TRACE(("__gdth_execute() cmd 0x%x\n", scp->cmnd[0]));
__gdth_queuecommand(ha, scp, &cmndinfo);
wait_for_completion(&wait);
rval = cmndinfo.status;
if (info)
*info = cmndinfo.info;
kfree(scp->sense_buffer);
kfree(scp);
return rval;
}
int gdth_execute(struct Scsi_Host *shost, gdth_cmd_str *gdtcmd, char *cmnd,
int timeout, u32 *info)
{
struct scsi_device *sdev = scsi_get_host_dev(shost);
int rval = __gdth_execute(sdev, gdtcmd, cmnd, timeout, info);
scsi_free_host_dev(sdev);
return rval;
}
static void gdth_eval_mapping(u32 size, u32 *cyls, int *heads, int *secs)
{
*cyls = size /HEADS/SECS;
if (*cyls <= MAXCYLS) {
*heads = HEADS;
*secs = SECS;
} else {
*cyls = size /MEDHEADS/MEDSECS;
if (*cyls <= MAXCYLS) {
*heads = MEDHEADS;
*secs = MEDSECS;
} else {
*cyls = size /BIGHEADS/BIGSECS;
*heads = BIGHEADS;
*secs = BIGSECS;
}
}
}
static int __init gdth_search_eisa(u16 eisa_adr)
{
u32 id;
TRACE(("gdth_search_eisa() adr. %x\n",eisa_adr));
id = inl(eisa_adr+ID0REG);
if (id == GDT3A_ID || id == GDT3B_ID) {
if ((inb(eisa_adr+EISAREG) & 8) == 0)
return 0;
return 1;
}
if (id == GDT3_ID)
return 1;
return 0;
}
static int __init gdth_search_isa(u32 bios_adr)
{
void __iomem *addr;
u32 id;
TRACE(("gdth_search_isa() bios adr. %x\n",bios_adr));
if ((addr = ioremap(bios_adr+BIOS_ID_OFFS, sizeof(u32))) != NULL) {
id = readl(addr);
iounmap(addr);
if (id == GDT2_ID)
return 1;
}
return 0;
}
static bool gdth_search_vortex(u16 device)
{
if (device <= PCI_DEVICE_ID_VORTEX_GDT6555)
return true;
if (device >= PCI_DEVICE_ID_VORTEX_GDT6x17RP &&
device <= PCI_DEVICE_ID_VORTEX_GDTMAXRP)
return true;
if (device == PCI_DEVICE_ID_VORTEX_GDTNEWRX ||
device == PCI_DEVICE_ID_VORTEX_GDTNEWRX2)
return true;
return false;
}
static void __devexit gdth_pci_remove_one(struct pci_dev *pdev)
{
gdth_ha_str *ha = pci_get_drvdata(pdev);
pci_set_drvdata(pdev, NULL);
list_del(&ha->list);
gdth_remove_one(ha);
pci_disable_device(pdev);
}
static int __devinit gdth_pci_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
u16 vendor = pdev->vendor;
u16 device = pdev->device;
unsigned long base0, base1, base2;
int rc;
gdth_pci_str gdth_pcistr;
gdth_ha_str *ha = NULL;
TRACE(("gdth_search_dev() cnt %d vendor %x device %x\n",
gdth_ctr_count, vendor, device));
memset(&gdth_pcistr, 0, sizeof(gdth_pcistr));
if (vendor == PCI_VENDOR_ID_VORTEX && !gdth_search_vortex(device))
return -ENODEV;
rc = pci_enable_device(pdev);
if (rc)
return rc;
if (gdth_ctr_count >= MAXHA)
return -EBUSY;
gdth_pcistr.pdev = pdev;
base0 = pci_resource_flags(pdev, 0);
base1 = pci_resource_flags(pdev, 1);
base2 = pci_resource_flags(pdev, 2);
if (device <= PCI_DEVICE_ID_VORTEX_GDT6000B ||
device >= PCI_DEVICE_ID_VORTEX_GDT6x17RP) {
if (!(base0 & IORESOURCE_MEM))
return -ENODEV;
gdth_pcistr.dpmem = pci_resource_start(pdev, 0);
} else {
if (!(base0 & IORESOURCE_MEM) ||
!(base2 & IORESOURCE_MEM) ||
!(base1 & IORESOURCE_IO))
return -ENODEV;
gdth_pcistr.dpmem = pci_resource_start(pdev, 2);
gdth_pcistr.io = pci_resource_start(pdev, 1);
}
TRACE2(("Controller found at %d/%d, irq %d, dpmem 0x%lx\n",
gdth_pcistr.pdev->bus->number,
PCI_SLOT(gdth_pcistr.pdev->devfn),
gdth_pcistr.irq,
gdth_pcistr.dpmem));
rc = gdth_pci_probe_one(&gdth_pcistr, &ha);
if (rc)
return rc;
return 0;
}
static int __init gdth_init_eisa(u16 eisa_adr,gdth_ha_str *ha)
{
u32 retries,id;
u8 prot_ver,eisacf,i,irq_found;
TRACE(("gdth_init_eisa() adr. %x\n",eisa_adr));
outb(0xff,eisa_adr+EDOORREG);
outb(0x00,eisa_adr+EDENABREG);
outb(0x00,eisa_adr+EINTENABREG);
outb(0xff,eisa_adr+LDOORREG);
retries = INIT_RETRIES;
gdth_delay(20);
while (inb(eisa_adr+EDOORREG) != 0xff) {
if (--retries == 0) {
printk("GDT-EISA: Initialization error (DEINIT failed)\n");
return 0;
}
gdth_delay(1);
TRACE2(("wait for DEINIT: retries=%d\n",retries));
}
prot_ver = inb(eisa_adr+MAILBOXREG);
outb(0xff,eisa_adr+EDOORREG);
if (prot_ver != PROTOCOL_VERSION) {
printk("GDT-EISA: Illegal protocol version\n");
return 0;
}
ha->bmic = eisa_adr;
ha->brd_phys = (u32)eisa_adr >> 12;
outl(0,eisa_adr+MAILBOXREG);
outl(0,eisa_adr+MAILBOXREG+4);
outl(0,eisa_adr+MAILBOXREG+8);
outl(0,eisa_adr+MAILBOXREG+12);
if ((id = inl(eisa_adr+ID0REG)) == GDT3_ID) {
ha->oem_id = OEM_ID_ICP;
ha->type = GDT_EISA;
ha->stype = id;
outl(1,eisa_adr+MAILBOXREG+8);
outb(0xfe,eisa_adr+LDOORREG);
retries = INIT_RETRIES;
gdth_delay(20);
while (inb(eisa_adr+EDOORREG) != 0xfe) {
if (--retries == 0) {
printk("GDT-EISA: Initialization error (get IRQ failed)\n");
return 0;
}
gdth_delay(1);
}
ha->irq = inb(eisa_adr+MAILBOXREG);
outb(0xff,eisa_adr+EDOORREG);
TRACE2(("GDT3000/3020: IRQ=%d\n",ha->irq));
if (ha->irq == 0) {
TRACE2(("Unknown IRQ, use IRQ table from cmd line !\n"));
for (i = 0, irq_found = FALSE;
i < MAXHA && irq[i] != 0xff; ++i) {
if (irq[i]==10 || irq[i]==11 || irq[i]==12 || irq[i]==14) {
irq_found = TRUE;
break;
}
}
if (irq_found) {
ha->irq = irq[i];
irq[i] = 0;
printk("GDT-EISA: Can not detect controller IRQ,\n");
printk("Use IRQ setting from command line (IRQ = %d)\n",
ha->irq);
} else {
printk("GDT-EISA: Initialization error (unknown IRQ), Enable\n");
printk("the controller BIOS or use command line parameters\n");
return 0;
}
}
} else {
eisacf = inb(eisa_adr+EISAREG) & 7;
if (eisacf > 4)
eisacf -= 4;
ha->irq = gdth_irq_tab[eisacf];
ha->oem_id = OEM_ID_ICP;
ha->type = GDT_EISA;
ha->stype = id;
}
ha->dma64_support = 0;
return 1;
}
static int __init gdth_init_isa(u32 bios_adr,gdth_ha_str *ha)
{
register gdt2_dpram_str __iomem *dp2_ptr;
int i;
u8 irq_drq,prot_ver;
u32 retries;
TRACE(("gdth_init_isa() bios adr. %x\n",bios_adr));
ha->brd = ioremap(bios_adr, sizeof(gdt2_dpram_str));
if (ha->brd == NULL) {
printk("GDT-ISA: Initialization error (DPMEM remap error)\n");
return 0;
}
dp2_ptr = ha->brd;
writeb(1, &dp2_ptr->io.memlock);
memset_io(&dp2_ptr->u, 0, sizeof(dp2_ptr->u));
if (readl(&dp2_ptr->u) != 0) {
printk("GDT-ISA: Initialization error (DPMEM write error)\n");
iounmap(ha->brd);
return 0;
}
writeb(0xff, &dp2_ptr->io.irqdel);
writeb(0x00, &dp2_ptr->io.irqen);
writeb(0x00, &dp2_ptr->u.ic.S_Status);
writeb(0x00, &dp2_ptr->u.ic.Cmd_Index);
irq_drq = readb(&dp2_ptr->io.rq);
for (i=0; i<3; ++i) {
if ((irq_drq & 1)==0)
break;
irq_drq >>= 1;
}
ha->drq = gdth_drq_tab[i];
irq_drq = readb(&dp2_ptr->io.rq) >> 3;
for (i=1; i<5; ++i) {
if ((irq_drq & 1)==0)
break;
irq_drq >>= 1;
}
ha->irq = gdth_irq_tab[i];
writel(bios_adr, &dp2_ptr->u.ic.S_Info[0]);
writeb(0xff, &dp2_ptr->u.ic.S_Cmd_Indx);
writeb(0, &dp2_ptr->io.event);
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp2_ptr->u.ic.S_Status) != 0xff) {
if (--retries == 0) {
printk("GDT-ISA: Initialization error (DEINIT failed)\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
prot_ver = (u8)readl(&dp2_ptr->u.ic.S_Info[0]);
writeb(0, &dp2_ptr->u.ic.Status);
writeb(0xff, &dp2_ptr->io.irqdel);
if (prot_ver != PROTOCOL_VERSION) {
printk("GDT-ISA: Illegal protocol version\n");
iounmap(ha->brd);
return 0;
}
ha->oem_id = OEM_ID_ICP;
ha->type = GDT_ISA;
ha->ic_all_size = sizeof(dp2_ptr->u);
ha->stype= GDT2_ID;
ha->brd_phys = bios_adr >> 4;
writel(0x00, &dp2_ptr->u.ic.S_Info[0]);
writel(0x00, &dp2_ptr->u.ic.S_Info[1]);
writel(0x01, &dp2_ptr->u.ic.S_Info[2]);
writel(0x00, &dp2_ptr->u.ic.S_Info[3]);
writeb(0xfe, &dp2_ptr->u.ic.S_Cmd_Indx);
writeb(0, &dp2_ptr->io.event);
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp2_ptr->u.ic.S_Status) != 0xfe) {
if (--retries == 0) {
printk("GDT-ISA: Initialization error\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
writeb(0, &dp2_ptr->u.ic.Status);
writeb(0xff, &dp2_ptr->io.irqdel);
ha->dma64_support = 0;
return 1;
}
static int __devinit gdth_init_pci(struct pci_dev *pdev, gdth_pci_str *pcistr,
gdth_ha_str *ha)
{
register gdt6_dpram_str __iomem *dp6_ptr;
register gdt6c_dpram_str __iomem *dp6c_ptr;
register gdt6m_dpram_str __iomem *dp6m_ptr;
u32 retries;
u8 prot_ver;
u16 command;
int i, found = FALSE;
TRACE(("gdth_init_pci()\n"));
if (pdev->vendor == PCI_VENDOR_ID_INTEL)
ha->oem_id = OEM_ID_INTEL;
else
ha->oem_id = OEM_ID_ICP;
ha->brd_phys = (pdev->bus->number << 8) | (pdev->devfn & 0xf8);
ha->stype = (u32)pdev->device;
ha->irq = pdev->irq;
ha->pdev = pdev;
if (ha->pdev->device <= PCI_DEVICE_ID_VORTEX_GDT6000B) {
TRACE2(("init_pci() dpmem %lx irq %d\n",pcistr->dpmem,ha->irq));
ha->brd = ioremap(pcistr->dpmem, sizeof(gdt6_dpram_str));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
dp6_ptr = ha->brd;
writel(DPMEM_MAGIC, &dp6_ptr->u);
if (readl(&dp6_ptr->u) != DPMEM_MAGIC) {
printk("GDT-PCI: Cannot access DPMEM at 0x%lx (shadowed?)\n",
pcistr->dpmem);
found = FALSE;
for (i = 0xC8000; i < 0xE8000; i += 0x4000) {
iounmap(ha->brd);
ha->brd = ioremap(i, sizeof(u16));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
if (readw(ha->brd) != 0xffff) {
TRACE2(("init_pci_old() address 0x%x busy\n", i));
continue;
}
iounmap(ha->brd);
pci_write_config_dword(pdev, PCI_BASE_ADDRESS_0, i);
ha->brd = ioremap(i, sizeof(gdt6_dpram_str));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
dp6_ptr = ha->brd;
writel(DPMEM_MAGIC, &dp6_ptr->u);
if (readl(&dp6_ptr->u) == DPMEM_MAGIC) {
printk("GDT-PCI: Use free address at 0x%x\n", i);
found = TRUE;
break;
}
}
if (!found) {
printk("GDT-PCI: No free address found!\n");
iounmap(ha->brd);
return 0;
}
}
memset_io(&dp6_ptr->u, 0, sizeof(dp6_ptr->u));
if (readl(&dp6_ptr->u) != 0) {
printk("GDT-PCI: Initialization error (DPMEM write error)\n");
iounmap(ha->brd);
return 0;
}
writeb(0xff, &dp6_ptr->io.irqdel);
writeb(0x00, &dp6_ptr->io.irqen);
writeb(0x00, &dp6_ptr->u.ic.S_Status);
writeb(0x00, &dp6_ptr->u.ic.Cmd_Index);
writel(pcistr->dpmem, &dp6_ptr->u.ic.S_Info[0]);
writeb(0xff, &dp6_ptr->u.ic.S_Cmd_Indx);
writeb(0, &dp6_ptr->io.event);
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp6_ptr->u.ic.S_Status) != 0xff) {
if (--retries == 0) {
printk("GDT-PCI: Initialization error (DEINIT failed)\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
prot_ver = (u8)readl(&dp6_ptr->u.ic.S_Info[0]);
writeb(0, &dp6_ptr->u.ic.S_Status);
writeb(0xff, &dp6_ptr->io.irqdel);
if (prot_ver != PROTOCOL_VERSION) {
printk("GDT-PCI: Illegal protocol version\n");
iounmap(ha->brd);
return 0;
}
ha->type = GDT_PCI;
ha->ic_all_size = sizeof(dp6_ptr->u);
writel(0x00, &dp6_ptr->u.ic.S_Info[0]);
writel(0x00, &dp6_ptr->u.ic.S_Info[1]);
writel(0x00, &dp6_ptr->u.ic.S_Info[2]);
writel(0x00, &dp6_ptr->u.ic.S_Info[3]);
writeb(0xfe, &dp6_ptr->u.ic.S_Cmd_Indx);
writeb(0, &dp6_ptr->io.event);
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp6_ptr->u.ic.S_Status) != 0xfe) {
if (--retries == 0) {
printk("GDT-PCI: Initialization error\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
writeb(0, &dp6_ptr->u.ic.S_Status);
writeb(0xff, &dp6_ptr->io.irqdel);
ha->dma64_support = 0;
} else if (ha->pdev->device <= PCI_DEVICE_ID_VORTEX_GDT6555) {
ha->plx = (gdt6c_plx_regs *)pcistr->io;
TRACE2(("init_pci_new() dpmem %lx irq %d\n",
pcistr->dpmem,ha->irq));
ha->brd = ioremap(pcistr->dpmem, sizeof(gdt6c_dpram_str));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
iounmap(ha->brd);
return 0;
}
dp6c_ptr = ha->brd;
writel(DPMEM_MAGIC, &dp6c_ptr->u);
if (readl(&dp6c_ptr->u) != DPMEM_MAGIC) {
printk("GDT-PCI: Cannot access DPMEM at 0x%lx (shadowed?)\n",
pcistr->dpmem);
found = FALSE;
for (i = 0xC8000; i < 0xE8000; i += 0x4000) {
iounmap(ha->brd);
ha->brd = ioremap(i, sizeof(u16));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
if (readw(ha->brd) != 0xffff) {
TRACE2(("init_pci_plx() address 0x%x busy\n", i));
continue;
}
iounmap(ha->brd);
pci_write_config_dword(pdev, PCI_BASE_ADDRESS_2, i);
ha->brd = ioremap(i, sizeof(gdt6c_dpram_str));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
dp6c_ptr = ha->brd;
writel(DPMEM_MAGIC, &dp6c_ptr->u);
if (readl(&dp6c_ptr->u) == DPMEM_MAGIC) {
printk("GDT-PCI: Use free address at 0x%x\n", i);
found = TRUE;
break;
}
}
if (!found) {
printk("GDT-PCI: No free address found!\n");
iounmap(ha->brd);
return 0;
}
}
memset_io(&dp6c_ptr->u, 0, sizeof(dp6c_ptr->u));
if (readl(&dp6c_ptr->u) != 0) {
printk("GDT-PCI: Initialization error (DPMEM write error)\n");
iounmap(ha->brd);
return 0;
}
outb(0x00,PTR2USHORT(&ha->plx->control1));
outb(0xff,PTR2USHORT(&ha->plx->edoor_reg));
writeb(0x00, &dp6c_ptr->u.ic.S_Status);
writeb(0x00, &dp6c_ptr->u.ic.Cmd_Index);
writel(pcistr->dpmem, &dp6c_ptr->u.ic.S_Info[0]);
writeb(0xff, &dp6c_ptr->u.ic.S_Cmd_Indx);
outb(1,PTR2USHORT(&ha->plx->ldoor_reg));
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp6c_ptr->u.ic.S_Status) != 0xff) {
if (--retries == 0) {
printk("GDT-PCI: Initialization error (DEINIT failed)\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
prot_ver = (u8)readl(&dp6c_ptr->u.ic.S_Info[0]);
writeb(0, &dp6c_ptr->u.ic.Status);
if (prot_ver != PROTOCOL_VERSION) {
printk("GDT-PCI: Illegal protocol version\n");
iounmap(ha->brd);
return 0;
}
ha->type = GDT_PCINEW;
ha->ic_all_size = sizeof(dp6c_ptr->u);
writel(0x00, &dp6c_ptr->u.ic.S_Info[0]);
writel(0x00, &dp6c_ptr->u.ic.S_Info[1]);
writel(0x00, &dp6c_ptr->u.ic.S_Info[2]);
writel(0x00, &dp6c_ptr->u.ic.S_Info[3]);
writeb(0xfe, &dp6c_ptr->u.ic.S_Cmd_Indx);
outb(1,PTR2USHORT(&ha->plx->ldoor_reg));
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp6c_ptr->u.ic.S_Status) != 0xfe) {
if (--retries == 0) {
printk("GDT-PCI: Initialization error\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
writeb(0, &dp6c_ptr->u.ic.S_Status);
ha->dma64_support = 0;
} else {
TRACE2(("init_pci_mpr() dpmem %lx irq %d\n",pcistr->dpmem,ha->irq));
ha->brd = ioremap(pcistr->dpmem, sizeof(gdt6m_dpram_str));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
pci_read_config_word(pdev, PCI_COMMAND, &command);
command |= 6;
pci_write_config_word(pdev, PCI_COMMAND, command);
if (pci_resource_start(pdev, 8) == 1UL)
pci_resource_start(pdev, 8) = 0UL;
i = 0xFEFF0001UL;
pci_write_config_dword(pdev, PCI_ROM_ADDRESS, i);
gdth_delay(1);
pci_write_config_dword(pdev, PCI_ROM_ADDRESS,
pci_resource_start(pdev, 8));
dp6m_ptr = ha->brd;
while( ((int)readb(&dp6m_ptr->i960r.sema0_reg) ) & 3 )
gdth_delay(1);
writel(DPMEM_MAGIC, &dp6m_ptr->u);
if (readl(&dp6m_ptr->u) != DPMEM_MAGIC) {
printk("GDT-PCI: Cannot access DPMEM at 0x%lx (shadowed?)\n",
pcistr->dpmem);
found = FALSE;
for (i = 0xC8000; i < 0xE8000; i += 0x4000) {
iounmap(ha->brd);
ha->brd = ioremap(i, sizeof(u16));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
if (readw(ha->brd) != 0xffff) {
TRACE2(("init_pci_mpr() address 0x%x busy\n", i));
continue;
}
iounmap(ha->brd);
pci_write_config_dword(pdev, PCI_BASE_ADDRESS_0, i);
ha->brd = ioremap(i, sizeof(gdt6m_dpram_str));
if (ha->brd == NULL) {
printk("GDT-PCI: Initialization error (DPMEM remap error)\n");
return 0;
}
dp6m_ptr = ha->brd;
writel(DPMEM_MAGIC, &dp6m_ptr->u);
if (readl(&dp6m_ptr->u) == DPMEM_MAGIC) {
printk("GDT-PCI: Use free address at 0x%x\n", i);
found = TRUE;
break;
}
}
if (!found) {
printk("GDT-PCI: No free address found!\n");
iounmap(ha->brd);
return 0;
}
}
memset_io(&dp6m_ptr->u, 0, sizeof(dp6m_ptr->u));
writeb(readb(&dp6m_ptr->i960r.edoor_en_reg) | 4,
&dp6m_ptr->i960r.edoor_en_reg);
writeb(0xff, &dp6m_ptr->i960r.edoor_reg);
writeb(0x00, &dp6m_ptr->u.ic.S_Status);
writeb(0x00, &dp6m_ptr->u.ic.Cmd_Index);
writel(pcistr->dpmem, &dp6m_ptr->u.ic.S_Info[0]);
writeb(0xff, &dp6m_ptr->u.ic.S_Cmd_Indx);
writeb(1, &dp6m_ptr->i960r.ldoor_reg);
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp6m_ptr->u.ic.S_Status) != 0xff) {
if (--retries == 0) {
printk("GDT-PCI: Initialization error (DEINIT failed)\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
prot_ver = (u8)readl(&dp6m_ptr->u.ic.S_Info[0]);
writeb(0, &dp6m_ptr->u.ic.S_Status);
if (prot_ver != PROTOCOL_VERSION) {
printk("GDT-PCI: Illegal protocol version\n");
iounmap(ha->brd);
return 0;
}
ha->type = GDT_PCIMPR;
ha->ic_all_size = sizeof(dp6m_ptr->u);
writel(0x00, &dp6m_ptr->u.ic.S_Info[0]);
writel(0x00, &dp6m_ptr->u.ic.S_Info[1]);
writel(0x00, &dp6m_ptr->u.ic.S_Info[2]);
writel(0x00, &dp6m_ptr->u.ic.S_Info[3]);
writeb(0xfe, &dp6m_ptr->u.ic.S_Cmd_Indx);
writeb(1, &dp6m_ptr->i960r.ldoor_reg);
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp6m_ptr->u.ic.S_Status) != 0xfe) {
if (--retries == 0) {
printk("GDT-PCI: Initialization error\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
writeb(0, &dp6m_ptr->u.ic.S_Status);
writeb(0xfd, &dp6m_ptr->u.ic.S_Cmd_Indx);
writeb(1, &dp6m_ptr->i960r.ldoor_reg);
retries = INIT_RETRIES;
gdth_delay(20);
while (readb(&dp6m_ptr->u.ic.S_Status) != 0xfd) {
if (--retries == 0) {
printk("GDT-PCI: Initialization error (DEINIT failed)\n");
iounmap(ha->brd);
return 0;
}
gdth_delay(1);
}
prot_ver = (u8)(readl(&dp6m_ptr->u.ic.S_Info[0]) >> 16);
writeb(0, &dp6m_ptr->u.ic.S_Status);
if (prot_ver < 0x2b)
ha->dma64_support = 0;
else
ha->dma64_support = 1;
}
return 1;
}
static void __devinit gdth_enable_int(gdth_ha_str *ha)
{
unsigned long flags;
gdt2_dpram_str __iomem *dp2_ptr;
gdt6_dpram_str __iomem *dp6_ptr;
gdt6m_dpram_str __iomem *dp6m_ptr;
TRACE(("gdth_enable_int() hanum %d\n",ha->hanum));
spin_lock_irqsave(&ha->smp_lock, flags);
if (ha->type == GDT_EISA) {
outb(0xff, ha->bmic + EDOORREG);
outb(0xff, ha->bmic + EDENABREG);
outb(0x01, ha->bmic + EINTENABREG);
} else if (ha->type == GDT_ISA) {
dp2_ptr = ha->brd;
writeb(1, &dp2_ptr->io.irqdel);
writeb(0, &dp2_ptr->u.ic.Cmd_Index);
writeb(1, &dp2_ptr->io.irqen);
} else if (ha->type == GDT_PCI) {
dp6_ptr = ha->brd;
writeb(1, &dp6_ptr->io.irqdel);
writeb(0, &dp6_ptr->u.ic.Cmd_Index);
writeb(1, &dp6_ptr->io.irqen);
} else if (ha->type == GDT_PCINEW) {
outb(0xff, PTR2USHORT(&ha->plx->edoor_reg));
outb(0x03, PTR2USHORT(&ha->plx->control1));
} else if (ha->type == GDT_PCIMPR) {
dp6m_ptr = ha->brd;
writeb(0xff, &dp6m_ptr->i960r.edoor_reg);
writeb(readb(&dp6m_ptr->i960r.edoor_en_reg) & ~4,
&dp6m_ptr->i960r.edoor_en_reg);
}
spin_unlock_irqrestore(&ha->smp_lock, flags);
}
static u8 gdth_get_status(gdth_ha_str *ha)
{
u8 IStatus = 0;
TRACE(("gdth_get_status() irq %d ctr_count %d\n", ha->irq, gdth_ctr_count));
if (ha->type == GDT_EISA)
IStatus = inb((u16)ha->bmic + EDOORREG);
else if (ha->type == GDT_ISA)
IStatus =
readb(&((gdt2_dpram_str __iomem *)ha->brd)->u.ic.Cmd_Index);
else if (ha->type == GDT_PCI)
IStatus =
readb(&((gdt6_dpram_str __iomem *)ha->brd)->u.ic.Cmd_Index);
else if (ha->type == GDT_PCINEW)
IStatus = inb(PTR2USHORT(&ha->plx->edoor_reg));
else if (ha->type == GDT_PCIMPR)
IStatus =
readb(&((gdt6m_dpram_str __iomem *)ha->brd)->i960r.edoor_reg);
return IStatus;
}
static int gdth_test_busy(gdth_ha_str *ha)
{
register int gdtsema0 = 0;
TRACE(("gdth_test_busy() hanum %d\n", ha->hanum));
if (ha->type == GDT_EISA)
gdtsema0 = (int)inb(ha->bmic + SEMA0REG);
else if (ha->type == GDT_ISA)
gdtsema0 = (int)readb(&((gdt2_dpram_str __iomem *)ha->brd)->u.ic.Sema0);
else if (ha->type == GDT_PCI)
gdtsema0 = (int)readb(&((gdt6_dpram_str __iomem *)ha->brd)->u.ic.Sema0);
else if (ha->type == GDT_PCINEW)
gdtsema0 = (int)inb(PTR2USHORT(&ha->plx->sema0_reg));
else if (ha->type == GDT_PCIMPR)
gdtsema0 =
(int)readb(&((gdt6m_dpram_str __iomem *)ha->brd)->i960r.sema0_reg);
return (gdtsema0 & 1);
}
static int gdth_get_cmd_index(gdth_ha_str *ha)
{
int i;
TRACE(("gdth_get_cmd_index() hanum %d\n", ha->hanum));
for (i=0; i<GDTH_MAXCMDS; ++i) {
if (ha->cmd_tab[i].cmnd == UNUSED_CMND) {
ha->cmd_tab[i].cmnd = ha->pccb->RequestBuffer;
ha->cmd_tab[i].service = ha->pccb->Service;
ha->pccb->CommandIndex = (u32)i+2;
return (i+2);
}
}
return 0;
}
static void gdth_set_sema0(gdth_ha_str *ha)
{
TRACE(("gdth_set_sema0() hanum %d\n", ha->hanum));
if (ha->type == GDT_EISA) {
outb(1, ha->bmic + SEMA0REG);
} else if (ha->type == GDT_ISA) {
writeb(1, &((gdt2_dpram_str __iomem *)ha->brd)->u.ic.Sema0);
} else if (ha->type == GDT_PCI) {
writeb(1, &((gdt6_dpram_str __iomem *)ha->brd)->u.ic.Sema0);
} else if (ha->type == GDT_PCINEW) {
outb(1, PTR2USHORT(&ha->plx->sema0_reg));
} else if (ha->type == GDT_PCIMPR) {
writeb(1, &((gdt6m_dpram_str __iomem *)ha->brd)->i960r.sema0_reg);
}
}
static void gdth_copy_command(gdth_ha_str *ha)
{
register gdth_cmd_str *cmd_ptr;
register gdt6m_dpram_str __iomem *dp6m_ptr;
register gdt6c_dpram_str __iomem *dp6c_ptr;
gdt6_dpram_str __iomem *dp6_ptr;
gdt2_dpram_str __iomem *dp2_ptr;
u16 cp_count,dp_offset,cmd_no;
TRACE(("gdth_copy_command() hanum %d\n", ha->hanum));
cp_count = ha->cmd_len;
dp_offset= ha->cmd_offs_dpmem;
cmd_no = ha->cmd_cnt;
cmd_ptr = ha->pccb;
++ha->cmd_cnt;
if (ha->type == GDT_EISA)
return;
if (cp_count & 3)
cp_count += (4 - (cp_count & 3));
ha->cmd_offs_dpmem += cp_count;
if (ha->type == GDT_ISA) {
dp2_ptr = ha->brd;
writew(dp_offset + DPMEM_COMMAND_OFFSET,
&dp2_ptr->u.ic.comm_queue[cmd_no].offset);
writew((u16)cmd_ptr->Service,
&dp2_ptr->u.ic.comm_queue[cmd_no].serv_id);
memcpy_toio(&dp2_ptr->u.ic.gdt_dpr_cmd[dp_offset],cmd_ptr,cp_count);
} else if (ha->type == GDT_PCI) {
dp6_ptr = ha->brd;
writew(dp_offset + DPMEM_COMMAND_OFFSET,
&dp6_ptr->u.ic.comm_queue[cmd_no].offset);
writew((u16)cmd_ptr->Service,
&dp6_ptr->u.ic.comm_queue[cmd_no].serv_id);
memcpy_toio(&dp6_ptr->u.ic.gdt_dpr_cmd[dp_offset],cmd_ptr,cp_count);
} else if (ha->type == GDT_PCINEW) {
dp6c_ptr = ha->brd;
writew(dp_offset + DPMEM_COMMAND_OFFSET,
&dp6c_ptr->u.ic.comm_queue[cmd_no].offset);
writew((u16)cmd_ptr->Service,
&dp6c_ptr->u.ic.comm_queue[cmd_no].serv_id);
memcpy_toio(&dp6c_ptr->u.ic.gdt_dpr_cmd[dp_offset],cmd_ptr,cp_count);
} else if (ha->type == GDT_PCIMPR) {
dp6m_ptr = ha->brd;
writew(dp_offset + DPMEM_COMMAND_OFFSET,
&dp6m_ptr->u.ic.comm_queue[cmd_no].offset);
writew((u16)cmd_ptr->Service,
&dp6m_ptr->u.ic.comm_queue[cmd_no].serv_id);
memcpy_toio(&dp6m_ptr->u.ic.gdt_dpr_cmd[dp_offset],cmd_ptr,cp_count);
}
}
static void gdth_release_event(gdth_ha_str *ha)
{
TRACE(("gdth_release_event() hanum %d\n", ha->hanum));
#ifdef GDTH_STATISTICS
{
u32 i,j;
for (i=0,j=0; j<GDTH_MAXCMDS; ++j) {
if (ha->cmd_tab[j].cmnd != UNUSED_CMND)
++i;
}
if (max_index < i) {
max_index = i;
TRACE3(("GDT: max_index = %d\n",(u16)i));
}
}
#endif
if (ha->pccb->OpCode == GDT_INIT)
ha->pccb->Service |= 0x80;
if (ha->type == GDT_EISA) {
if (ha->pccb->OpCode == GDT_INIT)
outl(ha->ccb_phys, ha->bmic + MAILBOXREG);
outb(ha->pccb->Service, ha->bmic + LDOORREG);
} else if (ha->type == GDT_ISA) {
writeb(0, &((gdt2_dpram_str __iomem *)ha->brd)->io.event);
} else if (ha->type == GDT_PCI) {
writeb(0, &((gdt6_dpram_str __iomem *)ha->brd)->io.event);
} else if (ha->type == GDT_PCINEW) {
outb(1, PTR2USHORT(&ha->plx->ldoor_reg));
} else if (ha->type == GDT_PCIMPR) {
writeb(1, &((gdt6m_dpram_str __iomem *)ha->brd)->i960r.ldoor_reg);
}
}
static int gdth_wait(gdth_ha_str *ha, int index, u32 time)
{
int answer_found = FALSE;
int wait_index = 0;
TRACE(("gdth_wait() hanum %d index %d time %d\n", ha->hanum, index, time));
if (index == 0)
return 1;
do {
__gdth_interrupt(ha, true, &wait_index);
if (wait_index == index) {
answer_found = TRUE;
break;
}
gdth_delay(1);
} while (--time);
while (gdth_test_busy(ha))
gdth_delay(0);
return (answer_found);
}
static int gdth_internal_cmd(gdth_ha_str *ha, u8 service, u16 opcode,
u32 p1, u64 p2, u64 p3)
{
register gdth_cmd_str *cmd_ptr;
int retries,index;
TRACE2(("gdth_internal_cmd() service %d opcode %d\n",service,opcode));
cmd_ptr = ha->pccb;
memset((char*)cmd_ptr,0,sizeof(gdth_cmd_str));
for (retries = INIT_RETRIES;;) {
cmd_ptr->Service = service;
cmd_ptr->RequestBuffer = INTERNAL_CMND;
if (!(index=gdth_get_cmd_index(ha))) {
TRACE(("GDT: No free command index found\n"));
return 0;
}
gdth_set_sema0(ha);
cmd_ptr->OpCode = opcode;
cmd_ptr->BoardNode = LOCALBOARD;
if (service == CACHESERVICE) {
if (opcode == GDT_IOCTL) {
cmd_ptr->u.ioctl.subfunc = p1;
cmd_ptr->u.ioctl.channel = (u32)p2;
cmd_ptr->u.ioctl.param_size = (u16)p3;
cmd_ptr->u.ioctl.p_param = ha->scratch_phys;
} else {
if (ha->cache_feat & GDT_64BIT) {
cmd_ptr->u.cache64.DeviceNo = (u16)p1;
cmd_ptr->u.cache64.BlockNo = p2;
} else {
cmd_ptr->u.cache.DeviceNo = (u16)p1;
cmd_ptr->u.cache.BlockNo = (u32)p2;
}
}
} else if (service == SCSIRAWSERVICE) {
if (ha->raw_feat & GDT_64BIT) {
cmd_ptr->u.raw64.direction = p1;
cmd_ptr->u.raw64.bus = (u8)p2;
cmd_ptr->u.raw64.target = (u8)p3;
cmd_ptr->u.raw64.lun = (u8)(p3 >> 8);
} else {
cmd_ptr->u.raw.direction = p1;
cmd_ptr->u.raw.bus = (u8)p2;
cmd_ptr->u.raw.target = (u8)p3;
cmd_ptr->u.raw.lun = (u8)(p3 >> 8);
}
} else if (service == SCREENSERVICE) {
if (opcode == GDT_REALTIME) {
*(u32 *)&cmd_ptr->u.screen.su.data[0] = p1;
*(u32 *)&cmd_ptr->u.screen.su.data[4] = (u32)p2;
*(u32 *)&cmd_ptr->u.screen.su.data[8] = (u32)p3;
}
}
ha->cmd_len = sizeof(gdth_cmd_str);
ha->cmd_offs_dpmem = 0;
ha->cmd_cnt = 0;
gdth_copy_command(ha);
gdth_release_event(ha);
gdth_delay(20);
if (!gdth_wait(ha, index, INIT_TIMEOUT)) {
printk("GDT: Initialization error (timeout service %d)\n",service);
return 0;
}
if (ha->status != S_BSY || --retries == 0)
break;
gdth_delay(1);
}
return (ha->status != S_OK ? 0:1);
}
static int __devinit gdth_search_drives(gdth_ha_str *ha)
{
u16 cdev_cnt, i;
int ok;
u32 bus_no, drv_cnt, drv_no, j;
gdth_getch_str *chn;
gdth_drlist_str *drl;
gdth_iochan_str *ioc;
gdth_raw_iochan_str *iocr;
gdth_arcdl_str *alst;
gdth_alist_str *alst2;
gdth_oem_str_ioctl *oemstr;
#ifdef INT_COAL
gdth_perf_modes *pmod;
#endif
#ifdef GDTH_RTC
u8 rtc[12];
unsigned long flags;
#endif
TRACE(("gdth_search_drives() hanum %d\n", ha->hanum));
ok = 0;
ha->screen_feat = 0;
if (!force_dma32) {
ok = gdth_internal_cmd(ha, SCREENSERVICE, GDT_X_INIT_SCR, 0, 0, 0);
if (ok)
ha->screen_feat = GDT_64BIT;
}
if (force_dma32 || (!ok && ha->status == (u16)S_NOFUNC))
ok = gdth_internal_cmd(ha, SCREENSERVICE, GDT_INIT, 0, 0, 0);
if (!ok) {
printk("GDT-HA %d: Initialization error screen service (code %d)\n",
ha->hanum, ha->status);
return 0;
}
TRACE2(("gdth_search_drives(): SCREENSERVICE initialized\n"));
#ifdef GDTH_RTC
spin_lock_irqsave(&rtc_lock, flags);
for (j = 0; j < 1000000; ++j)
if (CMOS_READ(RTC_FREQ_SELECT) & RTC_UIP)
break;
for (j = 0; j < 1000000; ++j)
if (!(CMOS_READ(RTC_FREQ_SELECT) & RTC_UIP))
break;
do {
for (j = 0; j < 12; ++j)
rtc[j] = CMOS_READ(j);
} while (rtc[0] != CMOS_READ(0));
spin_unlock_irqrestore(&rtc_lock, flags);
TRACE2(("gdth_search_drives(): RTC: %x/%x/%x\n",*(u32 *)&rtc[0],
*(u32 *)&rtc[4], *(u32 *)&rtc[8]));
gdth_internal_cmd(ha, SCREENSERVICE, GDT_REALTIME, *(u32 *)&rtc[0],
*(u32 *)&rtc[4], *(u32 *)&rtc[8]);
#endif
gdth_internal_cmd(ha, CACHESERVICE, GDT_UNFREEZE_IO, 0, 0, 0);
ha->cache_feat = 0;
if (!force_dma32) {
ok = gdth_internal_cmd(ha, CACHESERVICE, GDT_X_INIT_HOST, LINUX_OS,
0, 0);
if (ok)
ha->cache_feat = GDT_64BIT;
}
if (force_dma32 || (!ok && ha->status == (u16)S_NOFUNC))
ok = gdth_internal_cmd(ha, CACHESERVICE, GDT_INIT, LINUX_OS, 0, 0);
if (!ok) {
printk("GDT-HA %d: Initialization error cache service (code %d)\n",
ha->hanum, ha->status);
return 0;
}
TRACE2(("gdth_search_drives(): CACHESERVICE initialized\n"));
cdev_cnt = (u16)ha->info;
ha->fw_vers = ha->service;
#ifdef INT_COAL
if (ha->type == GDT_PCIMPR) {
pmod = (gdth_perf_modes *)ha->pscratch;
pmod->version = 1;
pmod->st_mode = 1;
*((u64 *)&pmod->st_buff_addr1) = ha->coal_stat_phys;
pmod->st_buff_indx1 = COALINDEX;
pmod->st_buff_addr2 = 0;
pmod->st_buff_u_addr2 = 0;
pmod->st_buff_indx2 = 0;
pmod->st_buff_size = sizeof(gdth_coal_status) * MAXOFFSETS;
pmod->cmd_mode = 0;
pmod->cmd_buff_addr1 = 0;
pmod->cmd_buff_u_addr1 = 0;
pmod->cmd_buff_indx1 = 0;
pmod->cmd_buff_addr2 = 0;
pmod->cmd_buff_u_addr2 = 0;
pmod->cmd_buff_indx2 = 0;
pmod->cmd_buff_size = 0;
pmod->reserved1 = 0;
pmod->reserved2 = 0;
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, SET_PERF_MODES,
INVALID_CHANNEL,sizeof(gdth_perf_modes))) {
printk("GDT-HA %d: Interrupt coalescing activated\n", ha->hanum);
}
}
#endif
iocr = (gdth_raw_iochan_str *)ha->pscratch;
iocr->hdr.version = 0xffffffff;
iocr->hdr.list_entries = MAXBUS;
iocr->hdr.first_chan = 0;
iocr->hdr.last_chan = MAXBUS-1;
iocr->hdr.list_offset = GDTOFFSOF(gdth_raw_iochan_str, list[0]);
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, IOCHAN_RAW_DESC,
INVALID_CHANNEL,sizeof(gdth_raw_iochan_str))) {
TRACE2(("IOCHAN_RAW_DESC supported!\n"));
ha->bus_cnt = iocr->hdr.chan_count;
for (bus_no = 0; bus_no < ha->bus_cnt; ++bus_no) {
if (iocr->list[bus_no].proc_id < MAXID)
ha->bus_id[bus_no] = iocr->list[bus_no].proc_id;
else
ha->bus_id[bus_no] = 0xff;
}
} else {
chn = (gdth_getch_str *)ha->pscratch;
for (bus_no = 0; bus_no < MAXBUS; ++bus_no) {
chn->channel_no = bus_no;
if (!gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL,
SCSI_CHAN_CNT | L_CTRL_PATTERN,
IO_CHANNEL | INVALID_CHANNEL,
sizeof(gdth_getch_str))) {
if (bus_no == 0) {
printk("GDT-HA %d: Error detecting channel count (0x%x)\n",
ha->hanum, ha->status);
return 0;
}
break;
}
if (chn->siop_id < MAXID)
ha->bus_id[bus_no] = chn->siop_id;
else
ha->bus_id[bus_no] = 0xff;
}
ha->bus_cnt = (u8)bus_no;
}
TRACE2(("gdth_search_drives() %d channels\n",ha->bus_cnt));
if (!gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, CACHE_INFO,
INVALID_CHANNEL,sizeof(gdth_cinfo_str))) {
printk("GDT-HA %d: Initialization error cache service (code %d)\n",
ha->hanum, ha->status);
return 0;
}
ha->cpar = ((gdth_cinfo_str *)ha->pscratch)->cpar;
TRACE2(("gdth_search_drives() cinfo: vs %x sta %d str %d dw %d b %d\n",
ha->cpar.version,ha->cpar.state,ha->cpar.strategy,
ha->cpar.write_back,ha->cpar.block_size));
ha->more_proc = FALSE;
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, BOARD_INFO,
INVALID_CHANNEL,sizeof(gdth_binfo_str))) {
memcpy(&ha->binfo, (gdth_binfo_str *)ha->pscratch,
sizeof(gdth_binfo_str));
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, BOARD_FEATURES,
INVALID_CHANNEL,sizeof(gdth_bfeat_str))) {
TRACE2(("BOARD_INFO/BOARD_FEATURES supported\n"));
ha->bfeat = *(gdth_bfeat_str *)ha->pscratch;
ha->more_proc = TRUE;
}
} else {
TRACE2(("BOARD_INFO requires firmware >= 1.10/2.08\n"));
strcpy(ha->binfo.type_string, gdth_ctr_name(ha));
}
TRACE2(("Controller name: %s\n",ha->binfo.type_string));
if (ha->more_proc) {
ioc = (gdth_iochan_str *)ha->pscratch;
ioc->hdr.version = 0xffffffff;
ioc->hdr.list_entries = MAXBUS;
ioc->hdr.first_chan = 0;
ioc->hdr.last_chan = MAXBUS-1;
ioc->hdr.list_offset = GDTOFFSOF(gdth_iochan_str, list[0]);
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, IOCHAN_DESC,
INVALID_CHANNEL,sizeof(gdth_iochan_str))) {
for (bus_no = 0; bus_no < ha->bus_cnt; ++bus_no) {
ha->raw[bus_no].address = ioc->list[bus_no].address;
ha->raw[bus_no].local_no = ioc->list[bus_no].local_no;
}
} else {
for (bus_no = 0; bus_no < ha->bus_cnt; ++bus_no) {
ha->raw[bus_no].address = IO_CHANNEL;
ha->raw[bus_no].local_no = bus_no;
}
}
for (bus_no = 0; bus_no < ha->bus_cnt; ++bus_no) {
chn = (gdth_getch_str *)ha->pscratch;
chn->channel_no = ha->raw[bus_no].local_no;
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL,
SCSI_CHAN_CNT | L_CTRL_PATTERN,
ha->raw[bus_no].address | INVALID_CHANNEL,
sizeof(gdth_getch_str))) {
ha->raw[bus_no].pdev_cnt = chn->drive_cnt;
TRACE2(("Channel %d: %d phys. drives\n",
bus_no,chn->drive_cnt));
}
if (ha->raw[bus_no].pdev_cnt > 0) {
drl = (gdth_drlist_str *)ha->pscratch;
drl->sc_no = ha->raw[bus_no].local_no;
drl->sc_cnt = ha->raw[bus_no].pdev_cnt;
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL,
SCSI_DR_LIST | L_CTRL_PATTERN,
ha->raw[bus_no].address | INVALID_CHANNEL,
sizeof(gdth_drlist_str))) {
for (j = 0; j < ha->raw[bus_no].pdev_cnt; ++j)
ha->raw[bus_no].id_list[j] = drl->sc_list[j];
} else {
ha->raw[bus_no].pdev_cnt = 0;
}
}
}
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, CACHE_DRV_CNT,
INVALID_CHANNEL,sizeof(u32))) {
drv_cnt = *(u32 *)ha->pscratch;
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL, CACHE_DRV_LIST,
INVALID_CHANNEL,drv_cnt * sizeof(u32))) {
for (j = 0; j < drv_cnt; ++j) {
drv_no = ((u32 *)ha->pscratch)[j];
if (drv_no < MAX_LDRIVES) {
ha->hdr[drv_no].is_logdrv = TRUE;
TRACE2(("Drive %d is log. drive\n",drv_no));
}
}
}
alst = (gdth_arcdl_str *)ha->pscratch;
alst->entries_avail = MAX_LDRIVES;
alst->first_entry = 0;
alst->list_offset = GDTOFFSOF(gdth_arcdl_str, list[0]);
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL,
ARRAY_DRV_LIST2 | LA_CTRL_PATTERN,
INVALID_CHANNEL, sizeof(gdth_arcdl_str) +
(alst->entries_avail-1) * sizeof(gdth_alist_str))) {
for (j = 0; j < alst->entries_init; ++j) {
ha->hdr[j].is_arraydrv = alst->list[j].is_arrayd;
ha->hdr[j].is_master = alst->list[j].is_master;
ha->hdr[j].is_parity = alst->list[j].is_parity;
ha->hdr[j].is_hotfix = alst->list[j].is_hotfix;
ha->hdr[j].master_no = alst->list[j].cd_handle;
}
} else if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL,
ARRAY_DRV_LIST | LA_CTRL_PATTERN,
0, 35 * sizeof(gdth_alist_str))) {
for (j = 0; j < 35; ++j) {
alst2 = &((gdth_alist_str *)ha->pscratch)[j];
ha->hdr[j].is_arraydrv = alst2->is_arrayd;
ha->hdr[j].is_master = alst2->is_master;
ha->hdr[j].is_parity = alst2->is_parity;
ha->hdr[j].is_hotfix = alst2->is_hotfix;
ha->hdr[j].master_no = alst2->cd_handle;
}
}
}
}
ha->raw_feat = 0;
if (!force_dma32) {
ok = gdth_internal_cmd(ha, SCSIRAWSERVICE, GDT_X_INIT_RAW, 0, 0, 0);
if (ok)
ha->raw_feat = GDT_64BIT;
}
if (force_dma32 || (!ok && ha->status == (u16)S_NOFUNC))
ok = gdth_internal_cmd(ha, SCSIRAWSERVICE, GDT_INIT, 0, 0, 0);
if (!ok) {
printk("GDT-HA %d: Initialization error raw service (code %d)\n",
ha->hanum, ha->status);
return 0;
}
TRACE2(("gdth_search_drives(): RAWSERVICE initialized\n"));
if (gdth_internal_cmd(ha, SCSIRAWSERVICE, GDT_SET_FEAT, SCATTER_GATHER,
0, 0)) {
TRACE2(("gdth_search_drives(): set features RAWSERVICE OK\n"));
if (gdth_internal_cmd(ha, SCSIRAWSERVICE, GDT_GET_FEAT, 0, 0, 0)) {
TRACE2(("gdth_search_dr(): get feat RAWSERVICE %d\n",
ha->info));
ha->raw_feat |= (u16)ha->info;
}
}
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_SET_FEAT, 0,
SCATTER_GATHER,0)) {
TRACE2(("gdth_search_drives(): set features CACHESERVICE OK\n"));
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_GET_FEAT, 0, 0, 0)) {
TRACE2(("gdth_search_dr(): get feat CACHESERV. %d\n",
ha->info));
ha->cache_feat |= (u16)ha->info;
}
}
if (reserve_mode != 0) {
gdth_internal_cmd(ha, SCSIRAWSERVICE, GDT_RESERVE_ALL,
reserve_mode == 1 ? 1 : 3, 0, 0);
TRACE2(("gdth_search_drives(): RESERVE_ALL code %d\n",
ha->status));
}
for (i = 0; i < MAX_RES_ARGS; i += 4) {
if (reserve_list[i] == ha->hanum && reserve_list[i+1] < ha->bus_cnt &&
reserve_list[i+2] < ha->tid_cnt && reserve_list[i+3] < MAXLUN) {
TRACE2(("gdth_search_drives(): reserve ha %d bus %d id %d lun %d\n",
reserve_list[i], reserve_list[i+1],
reserve_list[i+2], reserve_list[i+3]));
if (!gdth_internal_cmd(ha, SCSIRAWSERVICE, GDT_RESERVE, 0,
reserve_list[i+1], reserve_list[i+2] |
(reserve_list[i+3] << 8))) {
printk("GDT-HA %d: Error raw service (RESERVE, code %d)\n",
ha->hanum, ha->status);
}
}
}
oemstr = (gdth_oem_str_ioctl *)ha->pscratch;
oemstr->params.ctl_version = 0x01;
oemstr->params.buffer_size = sizeof(oemstr->text);
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_IOCTL,
CACHE_READ_OEM_STRING_RECORD,INVALID_CHANNEL,
sizeof(gdth_oem_str_ioctl))) {
TRACE2(("gdth_search_drives(): CACHE_READ_OEM_STRING_RECORD OK\n"));
printk("GDT-HA %d: Vendor: %s Name: %s\n",
ha->hanum, oemstr->text.oem_company_name, ha->binfo.type_string);
strlcpy(ha->oem_name,oemstr->text.scsi_host_drive_inquiry_vendor_id,
sizeof(ha->oem_name));
} else {
TRACE2(("gdth_search_drives(): CACHE_READ_OEM_STRING_RECORD failed\n"));
printk("GDT-HA %d: Name: %s\n",
ha->hanum, ha->binfo.type_string);
if (ha->oem_id == OEM_ID_INTEL)
strlcpy(ha->oem_name,"Intel ", sizeof(ha->oem_name));
else
strlcpy(ha->oem_name,"ICP ", sizeof(ha->oem_name));
}
for (i = 0; i < cdev_cnt; ++i)
gdth_analyse_hdrive(ha, i);
TRACE(("gdth_search_drives() OK\n"));
return 1;
}
static int gdth_analyse_hdrive(gdth_ha_str *ha, u16 hdrive)
{
u32 drv_cyls;
int drv_hds, drv_secs;
TRACE(("gdth_analyse_hdrive() hanum %d drive %d\n", ha->hanum, hdrive));
if (hdrive >= MAX_HDRIVES)
return 0;
if (!gdth_internal_cmd(ha, CACHESERVICE, GDT_INFO, hdrive, 0, 0))
return 0;
ha->hdr[hdrive].present = TRUE;
ha->hdr[hdrive].size = ha->info;
ha->hdr[hdrive].size &= ~SECS32;
if (ha->info2 == 0) {
gdth_eval_mapping(ha->hdr[hdrive].size,&drv_cyls,&drv_hds,&drv_secs);
} else {
drv_hds = ha->info2 & 0xff;
drv_secs = (ha->info2 >> 8) & 0xff;
drv_cyls = (u32)ha->hdr[hdrive].size / drv_hds / drv_secs;
}
ha->hdr[hdrive].heads = (u8)drv_hds;
ha->hdr[hdrive].secs = (u8)drv_secs;
ha->hdr[hdrive].size = drv_cyls * drv_hds * drv_secs;
if (ha->cache_feat & GDT_64BIT) {
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_X_INFO, hdrive, 0, 0)
&& ha->info2 != 0) {
ha->hdr[hdrive].size = ((u64)ha->info2 << 32) | ha->info;
}
}
TRACE2(("gdth_search_dr() cdr. %d size %d hds %d scs %d\n",
hdrive,ha->hdr[hdrive].size,drv_hds,drv_secs));
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_DEVTYPE, hdrive, 0, 0)) {
TRACE2(("gdth_search_dr() cache drive %d devtype %d\n",
hdrive,ha->info));
ha->hdr[hdrive].devtype = (u16)ha->info;
}
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_CLUST_INFO, hdrive, 0, 0)) {
TRACE2(("gdth_search_dr() cache drive %d cluster info %d\n",
hdrive,ha->info));
if (!shared_access)
ha->hdr[hdrive].cluster_type = (u8)ha->info;
}
if (gdth_internal_cmd(ha, CACHESERVICE, GDT_RW_ATTRIBS, hdrive, 0, 0)) {
TRACE2(("gdth_search_dr() cache drive %d r/w attrib. %d\n",
hdrive,ha->info));
ha->hdr[hdrive].rw_attribs = (u8)ha->info;
}
return 1;
}
static void gdth_putq(gdth_ha_str *ha, Scsi_Cmnd *scp, u8 priority)
{
struct gdth_cmndinfo *cmndinfo = gdth_cmnd_priv(scp);
register Scsi_Cmnd *pscp;
register Scsi_Cmnd *nscp;
unsigned long flags;
TRACE(("gdth_putq() priority %d\n",priority));
spin_lock_irqsave(&ha->smp_lock, flags);
if (!cmndinfo->internal_command)
cmndinfo->priority = priority;
if (ha->req_first==NULL) {
ha->req_first = scp;
scp->SCp.ptr = NULL;
} else {
pscp = ha->req_first;
nscp = (Scsi_Cmnd *)pscp->SCp.ptr;
while (nscp && gdth_cmnd_priv(nscp)->priority <= priority) {
pscp = nscp;
nscp = (Scsi_Cmnd *)pscp->SCp.ptr;
}
pscp->SCp.ptr = (char *)scp;
scp->SCp.ptr = (char *)nscp;
}
spin_unlock_irqrestore(&ha->smp_lock, flags);
#ifdef GDTH_STATISTICS
flags = 0;
for (nscp=ha->req_first; nscp; nscp=(Scsi_Cmnd*)nscp->SCp.ptr)
++flags;
if (max_rq < flags) {
max_rq = flags;
TRACE3(("GDT: max_rq = %d\n",(u16)max_rq));
}
#endif
}
static void gdth_next(gdth_ha_str *ha)
{
register Scsi_Cmnd *pscp;
register Scsi_Cmnd *nscp;
u8 b, t, l, firsttime;
u8 this_cmd, next_cmd;
unsigned long flags = 0;
int cmd_index;
TRACE(("gdth_next() hanum %d\n", ha->hanum));
if (!gdth_polling)
spin_lock_irqsave(&ha->smp_lock, flags);
ha->cmd_cnt = ha->cmd_offs_dpmem = 0;
this_cmd = firsttime = TRUE;
next_cmd = gdth_polling ? FALSE:TRUE;
cmd_index = 0;
for (nscp = pscp = ha->req_first; nscp; nscp = (Scsi_Cmnd *)nscp->SCp.ptr) {
struct gdth_cmndinfo *nscp_cmndinfo = gdth_cmnd_priv(nscp);
if (nscp != pscp && nscp != (Scsi_Cmnd *)pscp->SCp.ptr)
pscp = (Scsi_Cmnd *)pscp->SCp.ptr;
if (!nscp_cmndinfo->internal_command) {
b = nscp->device->channel;
t = nscp->device->id;
l = nscp->device->lun;
if (nscp_cmndinfo->priority >= DEFAULT_PRI) {
if ((b != ha->virt_bus && ha->raw[BUS_L2P(ha,b)].lock) ||
(b == ha->virt_bus && t < MAX_HDRIVES && ha->hdr[t].lock))
continue;
}
} else
b = t = l = 0;
if (firsttime) {
if (gdth_test_busy(ha)) {
TRACE(("gdth_next() controller %d busy !\n", ha->hanum));
if (!gdth_polling) {
spin_unlock_irqrestore(&ha->smp_lock, flags);
return;
}
while (gdth_test_busy(ha))
gdth_delay(1);
}
firsttime = FALSE;
}
if (!nscp_cmndinfo->internal_command) {
if (nscp_cmndinfo->phase == -1) {
nscp_cmndinfo->phase = CACHESERVICE;
if (nscp->cmnd[0] == TEST_UNIT_READY) {
TRACE2(("TEST_UNIT_READY Bus %d Id %d LUN %d\n",
b, t, l));
if ((ha->scan_mode & 0x0f) == 0) {
if (b == 0 && t == 0 && l == 0) {
ha->scan_mode |= 1;
TRACE2(("Scan mode: 0x%x\n", ha->scan_mode));
}
} else if ((ha->scan_mode & 0x0f) == 1) {
if (b == 0 && ((t == 0 && l == 1) ||
(t == 1 && l == 0))) {
nscp_cmndinfo->OpCode = GDT_SCAN_START;
nscp_cmndinfo->phase = ((ha->scan_mode & 0x10 ? 1:0) << 8)
| SCSIRAWSERVICE;
ha->scan_mode = 0x12;
TRACE2(("Scan mode: 0x%x (SCAN_START)\n",
ha->scan_mode));
} else {
ha->scan_mode &= 0x10;
TRACE2(("Scan mode: 0x%x\n", ha->scan_mode));
}
} else if (ha->scan_mode == 0x12) {
if (b == ha->bus_cnt && t == ha->tid_cnt-1) {
nscp_cmndinfo->phase = SCSIRAWSERVICE;
nscp_cmndinfo->OpCode = GDT_SCAN_END;
ha->scan_mode &= 0x10;
TRACE2(("Scan mode: 0x%x (SCAN_END)\n",
ha->scan_mode));
}
}
}
if (b == ha->virt_bus && nscp->cmnd[0] != INQUIRY &&
nscp->cmnd[0] != READ_CAPACITY && nscp->cmnd[0] != MODE_SENSE &&
(ha->hdr[t].cluster_type & CLUSTER_DRIVE)) {
nscp_cmndinfo->OpCode = GDT_CLUST_INFO;
}
}
}
if (nscp_cmndinfo->OpCode != -1) {
if ((nscp_cmndinfo->phase & 0xff) == CACHESERVICE) {
if (!(cmd_index=gdth_fill_cache_cmd(ha, nscp, t)))
this_cmd = FALSE;
next_cmd = FALSE;
} else if ((nscp_cmndinfo->phase & 0xff) == SCSIRAWSERVICE) {
if (!(cmd_index=gdth_fill_raw_cmd(ha, nscp, BUS_L2P(ha, b))))
this_cmd = FALSE;
next_cmd = FALSE;
} else {
memset((char*)nscp->sense_buffer,0,16);
nscp->sense_buffer[0] = 0x70;
nscp->sense_buffer[2] = NOT_READY;
nscp->result = (DID_OK << 16) | (CHECK_CONDITION << 1);
if (!nscp_cmndinfo->wait_for_completion)
nscp_cmndinfo->wait_for_completion++;
else
gdth_scsi_done(nscp);
}
} else if (gdth_cmnd_priv(nscp)->internal_command) {
if (!(cmd_index=gdth_special_cmd(ha, nscp)))
this_cmd = FALSE;
next_cmd = FALSE;
} else if (b != ha->virt_bus) {
if (ha->raw[BUS_L2P(ha,b)].io_cnt[t] >= GDTH_MAX_RAW ||
!(cmd_index=gdth_fill_raw_cmd(ha, nscp, BUS_L2P(ha, b))))
this_cmd = FALSE;
else
ha->raw[BUS_L2P(ha,b)].io_cnt[t]++;
} else if (t >= MAX_HDRIVES || !ha->hdr[t].present || l != 0) {
TRACE2(("Command 0x%x to bus %d id %d lun %d -> IGNORE\n",
nscp->cmnd[0], b, t, l));
nscp->result = DID_BAD_TARGET << 16;
if (!nscp_cmndinfo->wait_for_completion)
nscp_cmndinfo->wait_for_completion++;
else
gdth_scsi_done(nscp);
} else {
switch (nscp->cmnd[0]) {
case TEST_UNIT_READY:
case INQUIRY:
case REQUEST_SENSE:
case READ_CAPACITY:
case VERIFY:
case START_STOP:
case MODE_SENSE:
case SERVICE_ACTION_IN:
TRACE(("cache cmd %x/%x/%x/%x/%x/%x\n",nscp->cmnd[0],
nscp->cmnd[1],nscp->cmnd[2],nscp->cmnd[3],
nscp->cmnd[4],nscp->cmnd[5]));
if (ha->hdr[t].media_changed && nscp->cmnd[0] != INQUIRY) {
TRACE2(("cmd 0x%x target %d: UNIT_ATTENTION\n",
nscp->cmnd[0], t));
ha->hdr[t].media_changed = FALSE;
memset((char*)nscp->sense_buffer,0,16);
nscp->sense_buffer[0] = 0x70;
nscp->sense_buffer[2] = UNIT_ATTENTION;
nscp->result = (DID_OK << 16) | (CHECK_CONDITION << 1);
if (!nscp_cmndinfo->wait_for_completion)
nscp_cmndinfo->wait_for_completion++;
else
gdth_scsi_done(nscp);
} else if (gdth_internal_cache_cmd(ha, nscp))
gdth_scsi_done(nscp);
break;
case ALLOW_MEDIUM_REMOVAL:
TRACE(("cache cmd %x/%x/%x/%x/%x/%x\n",nscp->cmnd[0],
nscp->cmnd[1],nscp->cmnd[2],nscp->cmnd[3],
nscp->cmnd[4],nscp->cmnd[5]));
if ( (nscp->cmnd[4]&1) && !(ha->hdr[t].devtype&1) ) {
TRACE(("Prevent r. nonremov. drive->do nothing\n"));
nscp->result = DID_OK << 16;
nscp->sense_buffer[0] = 0;
if (!nscp_cmndinfo->wait_for_completion)
nscp_cmndinfo->wait_for_completion++;
else
gdth_scsi_done(nscp);
} else {
nscp->cmnd[3] = (ha->hdr[t].devtype&1) ? 1:0;
TRACE(("Prevent/allow r. %d rem. drive %d\n",
nscp->cmnd[4],nscp->cmnd[3]));
if (!(cmd_index=gdth_fill_cache_cmd(ha, nscp, t)))
this_cmd = FALSE;
}
break;
case RESERVE:
case RELEASE:
TRACE2(("cache cmd %s\n",nscp->cmnd[0] == RESERVE ?
"RESERVE" : "RELEASE"));
if (!(cmd_index=gdth_fill_cache_cmd(ha, nscp, t)))
this_cmd = FALSE;
break;
case READ_6:
case WRITE_6:
case READ_10:
case WRITE_10:
case READ_16:
case WRITE_16:
if (ha->hdr[t].media_changed) {
TRACE2(("cmd 0x%x target %d: UNIT_ATTENTION\n",
nscp->cmnd[0], t));
ha->hdr[t].media_changed = FALSE;
memset((char*)nscp->sense_buffer,0,16);
nscp->sense_buffer[0] = 0x70;
nscp->sense_buffer[2] = UNIT_ATTENTION;
nscp->result = (DID_OK << 16) | (CHECK_CONDITION << 1);
if (!nscp_cmndinfo->wait_for_completion)
nscp_cmndinfo->wait_for_completion++;
else
gdth_scsi_done(nscp);
} else if (!(cmd_index=gdth_fill_cache_cmd(ha, nscp, t)))
this_cmd = FALSE;
break;
default:
TRACE2(("cache cmd %x/%x/%x/%x/%x/%x unknown\n",nscp->cmnd[0],
nscp->cmnd[1],nscp->cmnd[2],nscp->cmnd[3],
nscp->cmnd[4],nscp->cmnd[5]));
printk("GDT-HA %d: Unknown SCSI command 0x%x to cache service !\n",
ha->hanum, nscp->cmnd[0]);
nscp->result = DID_ABORT << 16;
if (!nscp_cmndinfo->wait_for_completion)
nscp_cmndinfo->wait_for_completion++;
else
gdth_scsi_done(nscp);
break;
}
}
if (!this_cmd)
break;
if (nscp == ha->req_first)
ha->req_first = pscp = (Scsi_Cmnd *)nscp->SCp.ptr;
else
pscp->SCp.ptr = nscp->SCp.ptr;
if (!next_cmd)
break;
}
if (ha->cmd_cnt > 0) {
gdth_release_event(ha);
}
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
if (gdth_polling && ha->cmd_cnt > 0) {
if (!gdth_wait(ha, cmd_index, POLL_TIMEOUT))
printk("GDT-HA %d: Command %d timed out !\n",
ha->hanum, cmd_index);
}
}
static void gdth_copy_internal_data(gdth_ha_str *ha, Scsi_Cmnd *scp,
char *buffer, u16 count)
{
u16 cpcount,i, max_sg = scsi_sg_count(scp);
u16 cpsum,cpnow;
struct scatterlist *sl;
char *address;
cpcount = min_t(u16, count, scsi_bufflen(scp));
if (cpcount) {
cpsum=0;
scsi_for_each_sg(scp, sl, max_sg, i) {
unsigned long flags;
cpnow = (u16)sl->length;
TRACE(("copy_internal() now %d sum %d count %d %d\n",
cpnow, cpsum, cpcount, scsi_bufflen(scp)));
if (cpsum+cpnow > cpcount)
cpnow = cpcount - cpsum;
cpsum += cpnow;
if (!sg_page(sl)) {
printk("GDT-HA %d: invalid sc/gt element in gdth_copy_internal_data()\n",
ha->hanum);
return;
}
local_irq_save(flags);
address = kmap_atomic(sg_page(sl), KM_BIO_SRC_IRQ) + sl->offset;
memcpy(address, buffer, cpnow);
flush_dcache_page(sg_page(sl));
kunmap_atomic(address, KM_BIO_SRC_IRQ);
local_irq_restore(flags);
if (cpsum == cpcount)
break;
buffer += cpnow;
}
} else if (count) {
printk("GDT-HA %d: SCSI command with no buffers but data transfer expected!\n",
ha->hanum);
WARN_ON(1);
}
}
static int gdth_internal_cache_cmd(gdth_ha_str *ha, Scsi_Cmnd *scp)
{
u8 t;
gdth_inq_data inq;
gdth_rdcap_data rdc;
gdth_sense_data sd;
gdth_modep_data mpd;
struct gdth_cmndinfo *cmndinfo = gdth_cmnd_priv(scp);
t = scp->device->id;
TRACE(("gdth_internal_cache_cmd() cmd 0x%x hdrive %d\n",
scp->cmnd[0],t));
scp->result = DID_OK << 16;
scp->sense_buffer[0] = 0;
switch (scp->cmnd[0]) {
case TEST_UNIT_READY:
case VERIFY:
case START_STOP:
TRACE2(("Test/Verify/Start hdrive %d\n",t));
break;
case INQUIRY:
TRACE2(("Inquiry hdrive %d devtype %d\n",
t,ha->hdr[t].devtype));
inq.type_qual = (ha->hdr[t].devtype&4) ? TYPE_ROM:TYPE_DISK;
inq.modif_rmb = 0x00;
if ((ha->hdr[t].devtype & 1) ||
(ha->hdr[t].cluster_type & CLUSTER_DRIVE))
inq.modif_rmb = 0x80;
inq.version = 2;
inq.resp_aenc = 2;
inq.add_length= 32;
strcpy(inq.vendor,ha->oem_name);
sprintf(inq.product,"Host Drive #%02d",t);
strcpy(inq.revision," ");
gdth_copy_internal_data(ha, scp, (char*)&inq, sizeof(gdth_inq_data));
break;
case REQUEST_SENSE:
TRACE2(("Request sense hdrive %d\n",t));
sd.errorcode = 0x70;
sd.segno = 0x00;
sd.key = NO_SENSE;
sd.info = 0;
sd.add_length= 0;
gdth_copy_internal_data(ha, scp, (char*)&sd, sizeof(gdth_sense_data));
break;
case MODE_SENSE:
TRACE2(("Mode sense hdrive %d\n",t));
memset((char*)&mpd,0,sizeof(gdth_modep_data));
mpd.hd.data_length = sizeof(gdth_modep_data);
mpd.hd.dev_par = (ha->hdr[t].devtype&2) ? 0x80:0;
mpd.hd.bd_length = sizeof(mpd.bd);
mpd.bd.block_length[0] = (SECTOR_SIZE & 0x00ff0000) >> 16;
mpd.bd.block_length[1] = (SECTOR_SIZE & 0x0000ff00) >> 8;
mpd.bd.block_length[2] = (SECTOR_SIZE & 0x000000ff);
gdth_copy_internal_data(ha, scp, (char*)&mpd, sizeof(gdth_modep_data));
break;
case READ_CAPACITY:
TRACE2(("Read capacity hdrive %d\n",t));
if (ha->hdr[t].size > (u64)0xffffffff)
rdc.last_block_no = 0xffffffff;
else
rdc.last_block_no = cpu_to_be32(ha->hdr[t].size-1);
rdc.block_length = cpu_to_be32(SECTOR_SIZE);
gdth_copy_internal_data(ha, scp, (char*)&rdc, sizeof(gdth_rdcap_data));
break;
case SERVICE_ACTION_IN:
if ((scp->cmnd[1] & 0x1f) == SAI_READ_CAPACITY_16 &&
(ha->cache_feat & GDT_64BIT)) {
gdth_rdcap16_data rdc16;
TRACE2(("Read capacity (16) hdrive %d\n",t));
rdc16.last_block_no = cpu_to_be64(ha->hdr[t].size-1);
rdc16.block_length = cpu_to_be32(SECTOR_SIZE);
gdth_copy_internal_data(ha, scp, (char*)&rdc16,
sizeof(gdth_rdcap16_data));
} else {
scp->result = DID_ABORT << 16;
}
break;
default:
TRACE2(("Internal cache cmd 0x%x unknown\n",scp->cmnd[0]));
break;
}
if (!cmndinfo->wait_for_completion)
cmndinfo->wait_for_completion++;
else
return 1;
return 0;
}
static int gdth_fill_cache_cmd(gdth_ha_str *ha, Scsi_Cmnd *scp, u16 hdrive)
{
register gdth_cmd_str *cmdp;
struct gdth_cmndinfo *cmndinfo = gdth_cmnd_priv(scp);
u32 cnt, blockcnt;
u64 no, blockno;
int i, cmd_index, read_write, sgcnt, mode64;
cmdp = ha->pccb;
TRACE(("gdth_fill_cache_cmd() cmd 0x%x cmdsize %d hdrive %d\n",
scp->cmnd[0],scp->cmd_len,hdrive));
if (ha->type==GDT_EISA && ha->cmd_cnt>0)
return 0;
mode64 = (ha->cache_feat & GDT_64BIT) ? TRUE : FALSE;
cmdp->Service = CACHESERVICE;
cmdp->RequestBuffer = scp;
if (!(cmd_index=gdth_get_cmd_index(ha))) {
TRACE(("GDT: No free command index found\n"));
return 0;
}
if (ha->cmd_cnt == 0)
gdth_set_sema0(ha);
read_write = 0;
if (cmndinfo->OpCode != -1)
cmdp->OpCode = cmndinfo->OpCode;
else if (scp->cmnd[0] == RESERVE)
cmdp->OpCode = GDT_RESERVE_DRV;
else if (scp->cmnd[0] == RELEASE)
cmdp->OpCode = GDT_RELEASE_DRV;
else if (scp->cmnd[0] == ALLOW_MEDIUM_REMOVAL) {
if (scp->cmnd[4] & 1)
cmdp->OpCode = GDT_MOUNT;
else if (scp->cmnd[3] & 1)
cmdp->OpCode = GDT_UNMOUNT;
else
cmdp->OpCode = GDT_FLUSH;
} else if (scp->cmnd[0] == WRITE_6 || scp->cmnd[0] == WRITE_10 ||
scp->cmnd[0] == WRITE_12 || scp->cmnd[0] == WRITE_16
) {
read_write = 1;
if (gdth_write_through || ((ha->hdr[hdrive].rw_attribs & 1) &&
(ha->cache_feat & GDT_WR_THROUGH)))
cmdp->OpCode = GDT_WRITE_THR;
else
cmdp->OpCode = GDT_WRITE;
} else {
read_write = 2;
cmdp->OpCode = GDT_READ;
}
cmdp->BoardNode = LOCALBOARD;
if (mode64) {
cmdp->u.cache64.DeviceNo = hdrive;
cmdp->u.cache64.BlockNo = 1;
cmdp->u.cache64.sg_canz = 0;
} else {
cmdp->u.cache.DeviceNo = hdrive;
cmdp->u.cache.BlockNo = 1;
cmdp->u.cache.sg_canz = 0;
}
if (read_write) {
if (scp->cmd_len == 16) {
memcpy(&no, &scp->cmnd[2], sizeof(u64));
blockno = be64_to_cpu(no);
memcpy(&cnt, &scp->cmnd[10], sizeof(u32));
blockcnt = be32_to_cpu(cnt);
} else if (scp->cmd_len == 10) {
memcpy(&no, &scp->cmnd[2], sizeof(u32));
blockno = be32_to_cpu(no);
memcpy(&cnt, &scp->cmnd[7], sizeof(u16));
blockcnt = be16_to_cpu(cnt);
} else {
memcpy(&no, &scp->cmnd[0], sizeof(u32));
blockno = be32_to_cpu(no) & 0x001fffffUL;
blockcnt= scp->cmnd[4]==0 ? 0x100 : scp->cmnd[4];
}
if (mode64) {
cmdp->u.cache64.BlockNo = blockno;
cmdp->u.cache64.BlockCnt = blockcnt;
} else {
cmdp->u.cache.BlockNo = (u32)blockno;
cmdp->u.cache.BlockCnt = blockcnt;
}
if (scsi_bufflen(scp)) {
cmndinfo->dma_dir = (read_write == 1 ?
PCI_DMA_TODEVICE : PCI_DMA_FROMDEVICE);
sgcnt = pci_map_sg(ha->pdev, scsi_sglist(scp), scsi_sg_count(scp),
cmndinfo->dma_dir);
if (mode64) {
struct scatterlist *sl;
cmdp->u.cache64.DestAddr= (u64)-1;
cmdp->u.cache64.sg_canz = sgcnt;
scsi_for_each_sg(scp, sl, sgcnt, i) {
cmdp->u.cache64.sg_lst[i].sg_ptr = sg_dma_address(sl);
#ifdef GDTH_DMA_STATISTICS
if (cmdp->u.cache64.sg_lst[i].sg_ptr > (u64)0xffffffff)
ha->dma64_cnt++;
else
ha->dma32_cnt++;
#endif
cmdp->u.cache64.sg_lst[i].sg_len = sg_dma_len(sl);
}
} else {
struct scatterlist *sl;
cmdp->u.cache.DestAddr= 0xffffffff;
cmdp->u.cache.sg_canz = sgcnt;
scsi_for_each_sg(scp, sl, sgcnt, i) {
cmdp->u.cache.sg_lst[i].sg_ptr = sg_dma_address(sl);
#ifdef GDTH_DMA_STATISTICS
ha->dma32_cnt++;
#endif
cmdp->u.cache.sg_lst[i].sg_len = sg_dma_len(sl);
}
}
#ifdef GDTH_STATISTICS
if (max_sg < (u32)sgcnt) {
max_sg = (u32)sgcnt;
TRACE3(("GDT: max_sg = %d\n",max_sg));
}
#endif
}
}
if (mode64) {
TRACE(("cache cmd: addr. %x sganz %x sgptr0 %x sglen0 %x\n",
cmdp->u.cache64.DestAddr,cmdp->u.cache64.sg_canz,
cmdp->u.cache64.sg_lst[0].sg_ptr,
cmdp->u.cache64.sg_lst[0].sg_len));
TRACE(("cache cmd: cmd %d blockno. %d, blockcnt %d\n",
cmdp->OpCode,cmdp->u.cache64.BlockNo,cmdp->u.cache64.BlockCnt));
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.cache64.sg_lst) +
(u16)cmdp->u.cache64.sg_canz * sizeof(gdth_sg64_str);
} else {
TRACE(("cache cmd: addr. %x sganz %x sgptr0 %x sglen0 %x\n",
cmdp->u.cache.DestAddr,cmdp->u.cache.sg_canz,
cmdp->u.cache.sg_lst[0].sg_ptr,
cmdp->u.cache.sg_lst[0].sg_len));
TRACE(("cache cmd: cmd %d blockno. %d, blockcnt %d\n",
cmdp->OpCode,cmdp->u.cache.BlockNo,cmdp->u.cache.BlockCnt));
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.cache.sg_lst) +
(u16)cmdp->u.cache.sg_canz * sizeof(gdth_sg_str);
}
if (ha->cmd_len & 3)
ha->cmd_len += (4 - (ha->cmd_len & 3));
if (ha->cmd_cnt > 0) {
if ((ha->cmd_offs_dpmem + ha->cmd_len + DPMEM_COMMAND_OFFSET) >
ha->ic_all_size) {
TRACE2(("gdth_fill_cache() DPMEM overflow\n"));
ha->cmd_tab[cmd_index-2].cmnd = UNUSED_CMND;
return 0;
}
}
gdth_copy_command(ha);
return cmd_index;
}
static int gdth_fill_raw_cmd(gdth_ha_str *ha, Scsi_Cmnd *scp, u8 b)
{
register gdth_cmd_str *cmdp;
u16 i;
dma_addr_t sense_paddr;
int cmd_index, sgcnt, mode64;
u8 t,l;
struct page *page;
unsigned long offset;
struct gdth_cmndinfo *cmndinfo;
t = scp->device->id;
l = scp->device->lun;
cmdp = ha->pccb;
TRACE(("gdth_fill_raw_cmd() cmd 0x%x bus %d ID %d LUN %d\n",
scp->cmnd[0],b,t,l));
if (ha->type==GDT_EISA && ha->cmd_cnt>0)
return 0;
mode64 = (ha->raw_feat & GDT_64BIT) ? TRUE : FALSE;
cmdp->Service = SCSIRAWSERVICE;
cmdp->RequestBuffer = scp;
if (!(cmd_index=gdth_get_cmd_index(ha))) {
TRACE(("GDT: No free command index found\n"));
return 0;
}
if (ha->cmd_cnt == 0)
gdth_set_sema0(ha);
cmndinfo = gdth_cmnd_priv(scp);
if (cmndinfo->OpCode != -1) {
cmdp->OpCode = cmndinfo->OpCode;
cmdp->BoardNode = LOCALBOARD;
if (mode64) {
cmdp->u.raw64.direction = (cmndinfo->phase >> 8);
TRACE2(("special raw cmd 0x%x param 0x%x\n",
cmdp->OpCode, cmdp->u.raw64.direction));
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.raw64.sg_lst);
} else {
cmdp->u.raw.direction = (cmndinfo->phase >> 8);
TRACE2(("special raw cmd 0x%x param 0x%x\n",
cmdp->OpCode, cmdp->u.raw.direction));
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.raw.sg_lst);
}
} else {
page = virt_to_page(scp->sense_buffer);
offset = (unsigned long)scp->sense_buffer & ~PAGE_MASK;
sense_paddr = pci_map_page(ha->pdev,page,offset,
16,PCI_DMA_FROMDEVICE);
cmndinfo->sense_paddr = sense_paddr;
cmdp->OpCode = GDT_WRITE;
cmdp->BoardNode = LOCALBOARD;
if (mode64) {
cmdp->u.raw64.reserved = 0;
cmdp->u.raw64.mdisc_time = 0;
cmdp->u.raw64.mcon_time = 0;
cmdp->u.raw64.clen = scp->cmd_len;
cmdp->u.raw64.target = t;
cmdp->u.raw64.lun = l;
cmdp->u.raw64.bus = b;
cmdp->u.raw64.priority = 0;
cmdp->u.raw64.sdlen = scsi_bufflen(scp);
cmdp->u.raw64.sense_len = 16;
cmdp->u.raw64.sense_data = sense_paddr;
cmdp->u.raw64.direction =
gdth_direction_tab[scp->cmnd[0]]==DOU ? GDTH_DATA_OUT:GDTH_DATA_IN;
memcpy(cmdp->u.raw64.cmd,scp->cmnd,16);
cmdp->u.raw64.sg_ranz = 0;
} else {
cmdp->u.raw.reserved = 0;
cmdp->u.raw.mdisc_time = 0;
cmdp->u.raw.mcon_time = 0;
cmdp->u.raw.clen = scp->cmd_len;
cmdp->u.raw.target = t;
cmdp->u.raw.lun = l;
cmdp->u.raw.bus = b;
cmdp->u.raw.priority = 0;
cmdp->u.raw.link_p = 0;
cmdp->u.raw.sdlen = scsi_bufflen(scp);
cmdp->u.raw.sense_len = 16;
cmdp->u.raw.sense_data = sense_paddr;
cmdp->u.raw.direction =
gdth_direction_tab[scp->cmnd[0]]==DOU ? GDTH_DATA_OUT:GDTH_DATA_IN;
memcpy(cmdp->u.raw.cmd,scp->cmnd,12);
cmdp->u.raw.sg_ranz = 0;
}
if (scsi_bufflen(scp)) {
cmndinfo->dma_dir = PCI_DMA_BIDIRECTIONAL;
sgcnt = pci_map_sg(ha->pdev, scsi_sglist(scp), scsi_sg_count(scp),
cmndinfo->dma_dir);
if (mode64) {
struct scatterlist *sl;
cmdp->u.raw64.sdata = (u64)-1;
cmdp->u.raw64.sg_ranz = sgcnt;
scsi_for_each_sg(scp, sl, sgcnt, i) {
cmdp->u.raw64.sg_lst[i].sg_ptr = sg_dma_address(sl);
#ifdef GDTH_DMA_STATISTICS
if (cmdp->u.raw64.sg_lst[i].sg_ptr > (u64)0xffffffff)
ha->dma64_cnt++;
else
ha->dma32_cnt++;
#endif
cmdp->u.raw64.sg_lst[i].sg_len = sg_dma_len(sl);
}
} else {
struct scatterlist *sl;
cmdp->u.raw.sdata = 0xffffffff;
cmdp->u.raw.sg_ranz = sgcnt;
scsi_for_each_sg(scp, sl, sgcnt, i) {
cmdp->u.raw.sg_lst[i].sg_ptr = sg_dma_address(sl);
#ifdef GDTH_DMA_STATISTICS
ha->dma32_cnt++;
#endif
cmdp->u.raw.sg_lst[i].sg_len = sg_dma_len(sl);
}
}
#ifdef GDTH_STATISTICS
if (max_sg < sgcnt) {
max_sg = sgcnt;
TRACE3(("GDT: max_sg = %d\n",sgcnt));
}
#endif
}
if (mode64) {
TRACE(("raw cmd: addr. %x sganz %x sgptr0 %x sglen0 %x\n",
cmdp->u.raw64.sdata,cmdp->u.raw64.sg_ranz,
cmdp->u.raw64.sg_lst[0].sg_ptr,
cmdp->u.raw64.sg_lst[0].sg_len));
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.raw64.sg_lst) +
(u16)cmdp->u.raw64.sg_ranz * sizeof(gdth_sg64_str);
} else {
TRACE(("raw cmd: addr. %x sganz %x sgptr0 %x sglen0 %x\n",
cmdp->u.raw.sdata,cmdp->u.raw.sg_ranz,
cmdp->u.raw.sg_lst[0].sg_ptr,
cmdp->u.raw.sg_lst[0].sg_len));
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.raw.sg_lst) +
(u16)cmdp->u.raw.sg_ranz * sizeof(gdth_sg_str);
}
}
if (ha->cmd_len & 3)
ha->cmd_len += (4 - (ha->cmd_len & 3));
if (ha->cmd_cnt > 0) {
if ((ha->cmd_offs_dpmem + ha->cmd_len + DPMEM_COMMAND_OFFSET) >
ha->ic_all_size) {
TRACE2(("gdth_fill_raw() DPMEM overflow\n"));
ha->cmd_tab[cmd_index-2].cmnd = UNUSED_CMND;
return 0;
}
}
gdth_copy_command(ha);
return cmd_index;
}
static int gdth_special_cmd(gdth_ha_str *ha, Scsi_Cmnd *scp)
{
register gdth_cmd_str *cmdp;
struct gdth_cmndinfo *cmndinfo = gdth_cmnd_priv(scp);
int cmd_index;
cmdp= ha->pccb;
TRACE2(("gdth_special_cmd(): "));
if (ha->type==GDT_EISA && ha->cmd_cnt>0)
return 0;
*cmdp = *cmndinfo->internal_cmd_str;
cmdp->RequestBuffer = scp;
if (!(cmd_index=gdth_get_cmd_index(ha))) {
TRACE(("GDT: No free command index found\n"));
return 0;
}
if (ha->cmd_cnt == 0)
gdth_set_sema0(ha);
if (cmdp->OpCode == GDT_IOCTL) {
TRACE2(("IOCTL\n"));
ha->cmd_len =
GDTOFFSOF(gdth_cmd_str,u.ioctl.p_param) + sizeof(u64);
} else if (cmdp->Service == CACHESERVICE) {
TRACE2(("cache command %d\n",cmdp->OpCode));
if (ha->cache_feat & GDT_64BIT)
ha->cmd_len =
GDTOFFSOF(gdth_cmd_str,u.cache64.sg_lst) + sizeof(gdth_sg64_str);
else
ha->cmd_len =
GDTOFFSOF(gdth_cmd_str,u.cache.sg_lst) + sizeof(gdth_sg_str);
} else if (cmdp->Service == SCSIRAWSERVICE) {
TRACE2(("raw command %d\n",cmdp->OpCode));
if (ha->raw_feat & GDT_64BIT)
ha->cmd_len =
GDTOFFSOF(gdth_cmd_str,u.raw64.sg_lst) + sizeof(gdth_sg64_str);
else
ha->cmd_len =
GDTOFFSOF(gdth_cmd_str,u.raw.sg_lst) + sizeof(gdth_sg_str);
}
if (ha->cmd_len & 3)
ha->cmd_len += (4 - (ha->cmd_len & 3));
if (ha->cmd_cnt > 0) {
if ((ha->cmd_offs_dpmem + ha->cmd_len + DPMEM_COMMAND_OFFSET) >
ha->ic_all_size) {
TRACE2(("gdth_special_cmd() DPMEM overflow\n"));
ha->cmd_tab[cmd_index-2].cmnd = UNUSED_CMND;
return 0;
}
}
gdth_copy_command(ha);
return cmd_index;
}
static gdth_evt_str *gdth_store_event(gdth_ha_str *ha, u16 source,
u16 idx, gdth_evt_data *evt)
{
gdth_evt_str *e;
struct timeval tv;
TRACE2(("gdth_store_event() source %d idx %d\n", source, idx));
if (source == 0)
return NULL;
if (ebuffer[elastidx].event_source == source &&
ebuffer[elastidx].event_idx == idx &&
((evt->size != 0 && ebuffer[elastidx].event_data.size != 0 &&
!memcmp((char *)&ebuffer[elastidx].event_data.eu,
(char *)&evt->eu, evt->size)) ||
(evt->size == 0 && ebuffer[elastidx].event_data.size == 0 &&
!strcmp((char *)&ebuffer[elastidx].event_data.event_string,
(char *)&evt->event_string)))) {
e = &ebuffer[elastidx];
do_gettimeofday(&tv);
e->last_stamp = tv.tv_sec;
++e->same_count;
} else {
if (ebuffer[elastidx].event_source != 0) {
++elastidx;
if (elastidx == MAX_EVENTS)
elastidx = 0;
if (elastidx == eoldidx) {
++eoldidx;
if (eoldidx == MAX_EVENTS)
eoldidx = 0;
}
}
e = &ebuffer[elastidx];
e->event_source = source;
e->event_idx = idx;
do_gettimeofday(&tv);
e->first_stamp = e->last_stamp = tv.tv_sec;
e->same_count = 1;
e->event_data = *evt;
e->application = 0;
}
return e;
}
static int gdth_read_event(gdth_ha_str *ha, int handle, gdth_evt_str *estr)
{
gdth_evt_str *e;
int eindex;
unsigned long flags;
TRACE2(("gdth_read_event() handle %d\n", handle));
spin_lock_irqsave(&ha->smp_lock, flags);
if (handle == -1)
eindex = eoldidx;
else
eindex = handle;
estr->event_source = 0;
if (eindex < 0 || eindex >= MAX_EVENTS) {
spin_unlock_irqrestore(&ha->smp_lock, flags);
return eindex;
}
e = &ebuffer[eindex];
if (e->event_source != 0) {
if (eindex != elastidx) {
if (++eindex == MAX_EVENTS)
eindex = 0;
} else {
eindex = -1;
}
memcpy(estr, e, sizeof(gdth_evt_str));
}
spin_unlock_irqrestore(&ha->smp_lock, flags);
return eindex;
}
static void gdth_readapp_event(gdth_ha_str *ha,
u8 application, gdth_evt_str *estr)
{
gdth_evt_str *e;
int eindex;
unsigned long flags;
u8 found = FALSE;
TRACE2(("gdth_readapp_event() app. %d\n", application));
spin_lock_irqsave(&ha->smp_lock, flags);
eindex = eoldidx;
for (;;) {
e = &ebuffer[eindex];
if (e->event_source == 0)
break;
if ((e->application & application) == 0) {
e->application |= application;
found = TRUE;
break;
}
if (eindex == elastidx)
break;
if (++eindex == MAX_EVENTS)
eindex = 0;
}
if (found)
memcpy(estr, e, sizeof(gdth_evt_str));
else
estr->event_source = 0;
spin_unlock_irqrestore(&ha->smp_lock, flags);
}
static void gdth_clear_events(void)
{
TRACE(("gdth_clear_events()"));
eoldidx = elastidx = 0;
ebuffer[0].event_source = 0;
}
static irqreturn_t __gdth_interrupt(gdth_ha_str *ha,
int gdth_from_wait, int* pIndex)
{
gdt6m_dpram_str __iomem *dp6m_ptr = NULL;
gdt6_dpram_str __iomem *dp6_ptr;
gdt2_dpram_str __iomem *dp2_ptr;
Scsi_Cmnd *scp;
int rval, i;
u8 IStatus;
u16 Service;
unsigned long flags = 0;
#ifdef INT_COAL
int coalesced = FALSE;
int next = FALSE;
gdth_coal_status *pcs = NULL;
int act_int_coal = 0;
#endif
TRACE(("gdth_interrupt() IRQ %d\n", ha->irq));
if (gdth_polling) {
if (!gdth_from_wait) {
return IRQ_HANDLED;
}
}
if (!gdth_polling)
spin_lock_irqsave(&ha->smp_lock, flags);
IStatus = gdth_get_status(ha);
if (IStatus == 0) {
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
return IRQ_HANDLED;
}
#ifdef GDTH_STATISTICS
++act_ints;
#endif
#ifdef INT_COAL
if (IStatus == COALINDEX) {
pcs = ha->coal_stat;
coalesced = TRUE;
next = TRUE;
}
do {
if (coalesced) {
IStatus = (u8)(pcs->status & 0xff);
}
#endif
if (ha->type == GDT_EISA) {
if (IStatus & 0x80) {
IStatus &= ~0x80;
ha->status = inw(ha->bmic + MAILBOXREG+8);
TRACE2(("gdth_interrupt() error %d/%d\n",IStatus,ha->status));
} else
ha->status = S_OK;
ha->info = inl(ha->bmic + MAILBOXREG+12);
ha->service = inw(ha->bmic + MAILBOXREG+10);
ha->info2 = inl(ha->bmic + MAILBOXREG+4);
outb(0xff, ha->bmic + EDOORREG);
outb(0x00, ha->bmic + SEMA1REG);
} else if (ha->type == GDT_ISA) {
dp2_ptr = ha->brd;
if (IStatus & 0x80) {
IStatus &= ~0x80;
ha->status = readw(&dp2_ptr->u.ic.Status);
TRACE2(("gdth_interrupt() error %d/%d\n",IStatus,ha->status));
} else
ha->status = S_OK;
ha->info = readl(&dp2_ptr->u.ic.Info[0]);
ha->service = readw(&dp2_ptr->u.ic.Service);
ha->info2 = readl(&dp2_ptr->u.ic.Info[1]);
writeb(0xff, &dp2_ptr->io.irqdel);
writeb(0, &dp2_ptr->u.ic.Cmd_Index);
writeb(0, &dp2_ptr->io.Sema1);
} else if (ha->type == GDT_PCI) {
dp6_ptr = ha->brd;
if (IStatus & 0x80) {
IStatus &= ~0x80;
ha->status = readw(&dp6_ptr->u.ic.Status);
TRACE2(("gdth_interrupt() error %d/%d\n",IStatus,ha->status));
} else
ha->status = S_OK;
ha->info = readl(&dp6_ptr->u.ic.Info[0]);
ha->service = readw(&dp6_ptr->u.ic.Service);
ha->info2 = readl(&dp6_ptr->u.ic.Info[1]);
writeb(0xff, &dp6_ptr->io.irqdel);
writeb(0, &dp6_ptr->u.ic.Cmd_Index);
writeb(0, &dp6_ptr->io.Sema1);
} else if (ha->type == GDT_PCINEW) {
if (IStatus & 0x80) {
IStatus &= ~0x80;
ha->status = inw(PTR2USHORT(&ha->plx->status));
TRACE2(("gdth_interrupt() error %d/%d\n",IStatus,ha->status));
} else
ha->status = S_OK;
ha->info = inl(PTR2USHORT(&ha->plx->info[0]));
ha->service = inw(PTR2USHORT(&ha->plx->service));
ha->info2 = inl(PTR2USHORT(&ha->plx->info[1]));
outb(0xff, PTR2USHORT(&ha->plx->edoor_reg));
outb(0x00, PTR2USHORT(&ha->plx->sema1_reg));
} else if (ha->type == GDT_PCIMPR) {
dp6m_ptr = ha->brd;
if (IStatus & 0x80) {
IStatus &= ~0x80;
#ifdef INT_COAL
if (coalesced)
ha->status = pcs->ext_status & 0xffff;
else
#endif
ha->status = readw(&dp6m_ptr->i960r.status);
TRACE2(("gdth_interrupt() error %d/%d\n",IStatus,ha->status));
} else
ha->status = S_OK;
#ifdef INT_COAL
if (coalesced) {
ha->info = pcs->info0;
ha->info2 = pcs->info1;
ha->service = (pcs->ext_status >> 16) & 0xffff;
} else
#endif
{
ha->info = readl(&dp6m_ptr->i960r.info[0]);
ha->service = readw(&dp6m_ptr->i960r.service);
ha->info2 = readl(&dp6m_ptr->i960r.info[1]);
}
if (IStatus == ASYNCINDEX) {
if (ha->service != SCREENSERVICE &&
(ha->fw_vers & 0xff) >= 0x1a) {
ha->dvr.severity = readb
(&((gdt6m_dpram_str __iomem *)ha->brd)->i960r.severity);
for (i = 0; i < 256; ++i) {
ha->dvr.event_string[i] = readb
(&((gdt6m_dpram_str __iomem *)ha->brd)->i960r.evt_str[i]);
if (ha->dvr.event_string[i] == 0)
break;
}
}
}
#ifdef INT_COAL
if (!coalesced)
#endif
{
writeb(0xff, &dp6m_ptr->i960r.edoor_reg);
writeb(0, &dp6m_ptr->i960r.sema1_reg);
}
} else {
TRACE2(("gdth_interrupt() unknown controller type\n"));
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
return IRQ_HANDLED;
}
TRACE(("gdth_interrupt() index %d stat %d info %d\n",
IStatus,ha->status,ha->info));
if (gdth_from_wait) {
*pIndex = (int)IStatus;
}
if (IStatus == ASYNCINDEX) {
TRACE2(("gdth_interrupt() async. event\n"));
gdth_async_event(ha);
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
gdth_next(ha);
return IRQ_HANDLED;
}
if (IStatus == SPEZINDEX) {
TRACE2(("Service unknown or not initialized !\n"));
ha->dvr.size = sizeof(ha->dvr.eu.driver);
ha->dvr.eu.driver.ionode = ha->hanum;
gdth_store_event(ha, ES_DRIVER, 4, &ha->dvr);
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
return IRQ_HANDLED;
}
scp = ha->cmd_tab[IStatus-2].cmnd;
Service = ha->cmd_tab[IStatus-2].service;
ha->cmd_tab[IStatus-2].cmnd = UNUSED_CMND;
if (scp == UNUSED_CMND) {
TRACE2(("gdth_interrupt() index to unused command (%d)\n",IStatus));
ha->dvr.size = sizeof(ha->dvr.eu.driver);
ha->dvr.eu.driver.ionode = ha->hanum;
ha->dvr.eu.driver.index = IStatus;
gdth_store_event(ha, ES_DRIVER, 1, &ha->dvr);
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
return IRQ_HANDLED;
}
if (scp == INTERNAL_CMND) {
TRACE(("gdth_interrupt() answer to internal command\n"));
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
return IRQ_HANDLED;
}
TRACE(("gdth_interrupt() sync. status\n"));
rval = gdth_sync_event(ha,Service,IStatus,scp);
if (!gdth_polling)
spin_unlock_irqrestore(&ha->smp_lock, flags);
if (rval == 2) {
gdth_putq(ha, scp, gdth_cmnd_priv(scp)->priority);
} else if (rval == 1) {
gdth_scsi_done(scp);
}
#ifdef INT_COAL
if (coalesced) {
++pcs;
#ifdef GDTH_STATISTICS
++act_int_coal;
if (act_int_coal > max_int_coal) {
max_int_coal = act_int_coal;
printk("GDT: max_int_coal = %d\n",(u16)max_int_coal);
}
#endif
if (pcs->status == 0)
next = FALSE;
}
} while (next);
if (ha->type == GDT_PCIMPR && coalesced) {
writeb(0xff, &dp6m_ptr->i960r.edoor_reg);
writeb(0, &dp6m_ptr->i960r.sema1_reg);
}
#endif
gdth_next(ha);
return IRQ_HANDLED;
}
static irqreturn_t gdth_interrupt(int irq, void *dev_id)
{
gdth_ha_str *ha = dev_id;
return __gdth_interrupt(ha, false, NULL);
}
static int gdth_sync_event(gdth_ha_str *ha, int service, u8 index,
Scsi_Cmnd *scp)
{
gdth_msg_str *msg;
gdth_cmd_str *cmdp;
u8 b, t;
struct gdth_cmndinfo *cmndinfo = gdth_cmnd_priv(scp);
cmdp = ha->pccb;
TRACE(("gdth_sync_event() serv %d status %d\n",
service,ha->status));
if (service == SCREENSERVICE) {
msg = ha->pmsg;
TRACE(("len: %d, answer: %d, ext: %d, alen: %d\n",
msg->msg_len,msg->msg_answer,msg->msg_ext,msg->msg_alen));
if (msg->msg_len > MSGLEN+1)
msg->msg_len = MSGLEN+1;
if (msg->msg_len)
if (!(msg->msg_answer && msg->msg_ext)) {
msg->msg_text[msg->msg_len] = '\0';
printk("%s",msg->msg_text);
}
if (msg->msg_ext && !msg->msg_answer) {
while (gdth_test_busy(ha))
gdth_delay(0);
cmdp->Service = SCREENSERVICE;
cmdp->RequestBuffer = SCREEN_CMND;
gdth_get_cmd_index(ha);
gdth_set_sema0(ha);
cmdp->OpCode = GDT_READ;
cmdp->BoardNode = LOCALBOARD;
cmdp->u.screen.reserved = 0;
cmdp->u.screen.su.msg.msg_handle= msg->msg_handle;
cmdp->u.screen.su.msg.msg_addr = ha->msg_phys;
ha->cmd_offs_dpmem = 0;
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.screen.su.msg.msg_addr)
+ sizeof(u64);
ha->cmd_cnt = 0;
gdth_copy_command(ha);
gdth_release_event(ha);
return 0;
}
if (msg->msg_answer && msg->msg_alen) {
if (msg->msg_alen == 1) {
msg->msg_alen = 0;
msg->msg_len = 1;
msg->msg_text[0] = 0;
} else {
msg->msg_alen -= 2;
msg->msg_len = 2;
msg->msg_text[0] = 1;
msg->msg_text[1] = 0;
}
msg->msg_ext = 0;
msg->msg_answer = 0;
while (gdth_test_busy(ha))
gdth_delay(0);
cmdp->Service = SCREENSERVICE;
cmdp->RequestBuffer = SCREEN_CMND;
gdth_get_cmd_index(ha);
gdth_set_sema0(ha);
cmdp->OpCode = GDT_WRITE;
cmdp->BoardNode = LOCALBOARD;
cmdp->u.screen.reserved = 0;
cmdp->u.screen.su.msg.msg_handle= msg->msg_handle;
cmdp->u.screen.su.msg.msg_addr = ha->msg_phys;
ha->cmd_offs_dpmem = 0;
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.screen.su.msg.msg_addr)
+ sizeof(u64);
ha->cmd_cnt = 0;
gdth_copy_command(ha);
gdth_release_event(ha);
return 0;
}
printk("\n");
} else {
b = scp->device->channel;
t = scp->device->id;
if (cmndinfo->OpCode == -1 && b != ha->virt_bus) {
ha->raw[BUS_L2P(ha,b)].io_cnt[t]--;
}
if (ha->status == S_BSY) {
TRACE2(("Controller busy -> retry !\n"));
if (cmndinfo->OpCode == GDT_MOUNT)
cmndinfo->OpCode = GDT_CLUST_INFO;
return 2;
}
if (scsi_bufflen(scp))
pci_unmap_sg(ha->pdev, scsi_sglist(scp), scsi_sg_count(scp),
cmndinfo->dma_dir);
if (cmndinfo->sense_paddr)
pci_unmap_page(ha->pdev, cmndinfo->sense_paddr, 16,
PCI_DMA_FROMDEVICE);
if (ha->status == S_OK) {
cmndinfo->status = S_OK;
cmndinfo->info = ha->info;
if (cmndinfo->OpCode != -1) {
TRACE2(("gdth_sync_event(): special cmd 0x%x OK\n",
cmndinfo->OpCode));
if (cmndinfo->OpCode == GDT_CLUST_INFO) {
ha->hdr[t].cluster_type = (u8)ha->info;
if (!(ha->hdr[t].cluster_type &
CLUSTER_MOUNTED)) {
cmndinfo->OpCode = GDT_MOUNT;
if (ha->hdr[t].cluster_type &
CLUSTER_RESERVED) {
cmndinfo->phase = -2;
}
} else {
cmndinfo->OpCode = -1;
}
} else {
if (cmndinfo->OpCode == GDT_MOUNT) {
ha->hdr[t].cluster_type |= CLUSTER_MOUNTED;
ha->hdr[t].media_changed = TRUE;
} else if (cmndinfo->OpCode == GDT_UNMOUNT) {
ha->hdr[t].cluster_type &= ~CLUSTER_MOUNTED;
ha->hdr[t].media_changed = TRUE;
}
cmndinfo->OpCode = -1;
}
cmndinfo->priority = HIGH_PRI;
return 2;
} else {
if (scp->cmnd[0] == RESERVE) {
ha->hdr[t].cluster_type |= CLUSTER_RESERVED;
} else if (scp->cmnd[0] == RELEASE) {
ha->hdr[t].cluster_type &= ~CLUSTER_RESERVED;
}
scp->result = DID_OK << 16;
scp->sense_buffer[0] = 0;
}
} else {
cmndinfo->status = ha->status;
cmndinfo->info = ha->info;
if (cmndinfo->OpCode != -1) {
TRACE2(("gdth_sync_event(): special cmd 0x%x error 0x%x\n",
cmndinfo->OpCode, ha->status));
if (cmndinfo->OpCode == GDT_SCAN_START ||
cmndinfo->OpCode == GDT_SCAN_END) {
cmndinfo->OpCode = -1;
cmndinfo->priority = HIGH_PRI;
return 2;
}
memset((char*)scp->sense_buffer,0,16);
scp->sense_buffer[0] = 0x70;
scp->sense_buffer[2] = NOT_READY;
scp->result = (DID_OK << 16) | (CHECK_CONDITION << 1);
} else if (service == CACHESERVICE) {
if (ha->status == S_CACHE_UNKNOWN &&
(ha->hdr[t].cluster_type &
CLUSTER_RESERVE_STATE) == CLUSTER_RESERVE_STATE) {
ha->hdr[t].cluster_type &= ~CLUSTER_RESERVED;
}
memset((char*)scp->sense_buffer,0,16);
if (ha->status == (u16)S_CACHE_RESERV) {
scp->result = (DID_OK << 16) | (RESERVATION_CONFLICT << 1);
} else {
scp->sense_buffer[0] = 0x70;
scp->sense_buffer[2] = NOT_READY;
scp->result = (DID_OK << 16) | (CHECK_CONDITION << 1);
}
if (!cmndinfo->internal_command) {
ha->dvr.size = sizeof(ha->dvr.eu.sync);
ha->dvr.eu.sync.ionode = ha->hanum;
ha->dvr.eu.sync.service = service;
ha->dvr.eu.sync.status = ha->status;
ha->dvr.eu.sync.info = ha->info;
ha->dvr.eu.sync.hostdrive = t;
if (ha->status >= 0x8000)
gdth_store_event(ha, ES_SYNC, 0, &ha->dvr);
else
gdth_store_event(ha, ES_SYNC, service, &ha->dvr);
}
} else {
if (ha->status != S_RAW_SCSI || ha->info >= 0x100) {
scp->result = DID_BAD_TARGET << 16;
} else {
scp->result = (DID_OK << 16) | ha->info;
}
}
}
if (!cmndinfo->wait_for_completion)
cmndinfo->wait_for_completion++;
else
return 1;
}
return 0;
}
static int gdth_async_event(gdth_ha_str *ha)
{
gdth_cmd_str *cmdp;
int cmd_index;
cmdp= ha->pccb;
TRACE2(("gdth_async_event() ha %d serv %d\n",
ha->hanum, ha->service));
if (ha->service == SCREENSERVICE) {
if (ha->status == MSG_REQUEST) {
while (gdth_test_busy(ha))
gdth_delay(0);
cmdp->Service = SCREENSERVICE;
cmdp->RequestBuffer = SCREEN_CMND;
cmd_index = gdth_get_cmd_index(ha);
gdth_set_sema0(ha);
cmdp->OpCode = GDT_READ;
cmdp->BoardNode = LOCALBOARD;
cmdp->u.screen.reserved = 0;
cmdp->u.screen.su.msg.msg_handle= MSG_INV_HANDLE;
cmdp->u.screen.su.msg.msg_addr = ha->msg_phys;
ha->cmd_offs_dpmem = 0;
ha->cmd_len = GDTOFFSOF(gdth_cmd_str,u.screen.su.msg.msg_addr)
+ sizeof(u64);
ha->cmd_cnt = 0;
gdth_copy_command(ha);
if (ha->type == GDT_EISA)
printk("[EISA slot %d] ",(u16)ha->brd_phys);
else if (ha->type == GDT_ISA)
printk("[DPMEM 0x%4X] ",(u16)ha->brd_phys);
else
printk("[PCI %d/%d] ",(u16)(ha->brd_phys>>8),
(u16)((ha->brd_phys>>3)&0x1f));
gdth_release_event(ha);
}
} else {
if (ha->type == GDT_PCIMPR &&
(ha->fw_vers & 0xff) >= 0x1a) {
ha->dvr.size = 0;
ha->dvr.eu.async.ionode = ha->hanum;
ha->dvr.eu.async.status = ha->status;
} else {
ha->dvr.size = sizeof(ha->dvr.eu.async);
ha->dvr.eu.async.ionode = ha->hanum;
ha->dvr.eu.async.service = ha->service;
ha->dvr.eu.async.status = ha->status;
ha->dvr.eu.async.info = ha->info;
*(u32 *)ha->dvr.eu.async.scsi_coord = ha->info2;
}
gdth_store_event( ha, ES_ASYNC, ha->service, &ha->dvr );
gdth_log_event( &ha->dvr, NULL );
if (ha->service == CACHESERVICE && ha->status == 56) {
TRACE2(("gdth_async_event(): new host drive %d created\n",
(u16)ha->info));
}
}
return 1;
}
static void gdth_log_event(gdth_evt_data *dvr, char *buffer)
{
gdth_stackframe stack;
char *f = NULL;
int i,j;
TRACE2(("gdth_log_event()\n"));
if (dvr->size == 0) {
if (buffer == NULL) {
printk("Adapter %d: %s\n",dvr->eu.async.ionode,dvr->event_string);
} else {
sprintf(buffer,"Adapter %d: %s\n",
dvr->eu.async.ionode,dvr->event_string);
}
} else if (dvr->eu.async.service == CACHESERVICE &&
INDEX_OK(dvr->eu.async.status, async_cache_tab)) {
TRACE2(("GDT: Async. event cache service, event no.: %d\n",
dvr->eu.async.status));
f = async_cache_tab[dvr->eu.async.status];
for (j=0,i=1; i < f[0]; i+=2) {
switch (f[i+1]) {
case 4:
stack.b[j++] = *(u32*)&dvr->eu.stream[(int)f[i]];
break;
case 2:
stack.b[j++] = *(u16*)&dvr->eu.stream[(int)f[i]];
break;
case 1:
stack.b[j++] = *(u8*)&dvr->eu.stream[(int)f[i]];
break;
default:
break;
}
}
if (buffer == NULL) {
printk(&f[(int)f[0]],stack);
printk("\n");
} else {
sprintf(buffer,&f[(int)f[0]],stack);
}
} else {
if (buffer == NULL) {
printk("GDT HA %u, Unknown async. event service %d event no. %d\n",
dvr->eu.async.ionode,dvr->eu.async.service,dvr->eu.async.status);
} else {
sprintf(buffer,"GDT HA %u, Unknown async. event service %d event no. %d",
dvr->eu.async.ionode,dvr->eu.async.service,dvr->eu.async.status);
}
}
}
static void gdth_timeout(unsigned long data)
{
u32 i;
Scsi_Cmnd *nscp;
gdth_ha_str *ha;
unsigned long flags;
if(unlikely(list_empty(&gdth_instances))) {
gdth_timer_running = 0;
return;
}
ha = list_first_entry(&gdth_instances, gdth_ha_str, list);
spin_lock_irqsave(&ha->smp_lock, flags);
for (act_stats=0,i=0; i<GDTH_MAXCMDS; ++i)
if (ha->cmd_tab[i].cmnd != UNUSED_CMND)
++act_stats;
for (act_rq=0,nscp=ha->req_first; nscp; nscp=(Scsi_Cmnd*)nscp->SCp.ptr)
++act_rq;
TRACE2(("gdth_to(): ints %d, ios %d, act_stats %d, act_rq %d\n",
act_ints, act_ios, act_stats, act_rq));
act_ints = act_ios = 0;
gdth_timer.expires = jiffies + 30 * HZ;
add_timer(&gdth_timer);
spin_unlock_irqrestore(&ha->smp_lock, flags);
}
static void gdth_timer_init(void)
{
if (gdth_timer_running)
return;
gdth_timer_running = 1;
TRACE2(("gdth_detect(): Initializing timer !\n"));
gdth_timer.expires = jiffies + HZ;
gdth_timer.data = 0L;
gdth_timer.function = gdth_timeout;
add_timer(&gdth_timer);
}
static inline void gdth_timer_init(void)
{
}
static void __init internal_setup(char *str,int *ints)
{
int i, argc;
char *cur_str, *argv;
TRACE2(("internal_setup() str %s ints[0] %d\n",
str ? str:"NULL", ints ? ints[0]:0));
if (ints) {
argc = ints[0];
if (argc > 0) {
if (argc > MAXHA)
argc = MAXHA;
for (i = 0; i < argc; ++i)
irq[i] = ints[i+1];
}
}
argv = str;
while (argv && (cur_str = strchr(argv, ':'))) {
int val = 0, c = *++cur_str;
if (c == 'n' || c == 'N')
val = 0;
else if (c == 'y' || c == 'Y')
val = 1;
else
val = (int)simple_strtoul(cur_str, NULL, 0);
if (!strncmp(argv, "disable:", 8))
disable = val;
else if (!strncmp(argv, "reserve_mode:", 13))
reserve_mode = val;
else if (!strncmp(argv, "reverse_scan:", 13))
reverse_scan = val;
else if (!strncmp(argv, "hdr_channel:", 12))
hdr_channel = val;
else if (!strncmp(argv, "max_ids:", 8))
max_ids = val;
else if (!strncmp(argv, "rescan:", 7))
rescan = val;
else if (!strncmp(argv, "shared_access:", 14))
shared_access = val;
else if (!strncmp(argv, "probe_eisa_isa:", 15))
probe_eisa_isa = val;
else if (!strncmp(argv, "reserve_list:", 13)) {
reserve_list[0] = val;
for (i = 1; i < MAX_RES_ARGS; i++) {
cur_str = strchr(cur_str, ',');
if (!cur_str)
break;
if (!isdigit((int)*++cur_str)) {
--cur_str;
break;
}
reserve_list[i] =
(int)simple_strtoul(cur_str, NULL, 0);
}
if (!cur_str)
break;
argv = ++cur_str;
continue;
}
if ((argv = strchr(argv, ',')))
++argv;
}
}
int __init option_setup(char *str)
{
int ints[MAXHA];
char *cur = str;
int i = 1;
TRACE2(("option_setup() str %s\n", str ? str:"NULL"));
while (cur && isdigit(*cur) && i < MAXHA) {
ints[i++] = simple_strtoul(cur, NULL, 0);
if ((cur = strchr(cur, ',')) != NULL) cur++;
}
ints[0] = i - 1;
internal_setup(cur, ints);
return 1;
}
static const char *gdth_ctr_name(gdth_ha_str *ha)
{
TRACE2(("gdth_ctr_name()\n"));
if (ha->type == GDT_EISA) {
switch (ha->stype) {
case GDT3_ID:
return("GDT3000/3020");
case GDT3A_ID:
return("GDT3000A/3020A/3050A");
case GDT3B_ID:
return("GDT3000B/3010A");
}
} else if (ha->type == GDT_ISA) {
return("GDT2000/2020");
} else if (ha->type == GDT_PCI) {
switch (ha->pdev->device) {
case PCI_DEVICE_ID_VORTEX_GDT60x0:
return("GDT6000/6020/6050");
case PCI_DEVICE_ID_VORTEX_GDT6000B:
return("GDT6000B/6010");
}
}
return("");
}
static const char *gdth_info(struct Scsi_Host *shp)
{
gdth_ha_str *ha = shost_priv(shp);
TRACE2(("gdth_info()\n"));
return ((const char *)ha->binfo.type_string);
}
static enum blk_eh_timer_return gdth_timed_out(struct scsi_cmnd *scp)
{
gdth_ha_str *ha = shost_priv(scp->device->host);
struct gdth_cmndinfo *cmndinfo = gdth_cmnd_priv(scp);
u8 b, t;
unsigned long flags;
enum blk_eh_timer_return retval = BLK_EH_NOT_HANDLED;
TRACE(("%s() cmd 0x%x\n", scp->cmnd[0], __func__));
b = scp->device->channel;
t = scp->device->id;
if (++cmndinfo->timeout_count < 6)
retval = BLK_EH_RESET_TIMER;
spin_lock_irqsave(&ha->smp_lock, flags);
if ((b != ha->virt_bus && ha->raw[BUS_L2P(ha, b)].lock) ||
(b == ha->virt_bus && t < MAX_HDRIVES && ha->hdr[t].lock)) {
TRACE2(("%s(): locked IO, reset timeout\n", __func__));
retval = BLK_EH_RESET_TIMER;
}
spin_unlock_irqrestore(&ha->smp_lock, flags);
return retval;
}
static int gdth_eh_bus_reset(Scsi_Cmnd *scp)
{
gdth_ha_str *ha = shost_priv(scp->device->host);
int i;
unsigned long flags;
Scsi_Cmnd *cmnd;
u8 b;
TRACE2(("gdth_eh_bus_reset()\n"));
b = scp->device->channel;
spin_lock_irqsave(&ha->smp_lock, flags);
for (i = 0; i < GDTH_MAXCMDS; ++i) {
cmnd = ha->cmd_tab[i].cmnd;
if (!SPECIAL_SCP(cmnd) && cmnd->device->channel == b)
ha->cmd_tab[i].cmnd = UNUSED_CMND;
}
spin_unlock_irqrestore(&ha->smp_lock, flags);
if (b == ha->virt_bus) {
for (i = 0; i < MAX_HDRIVES; ++i) {
if (ha->hdr[i].present) {
spin_lock_irqsave(&ha->smp_lock, flags);
gdth_polling = TRUE;
while (gdth_test_busy(ha))
gdth_delay(0);
if (gdth_internal_cmd(ha, CACHESERVICE,
GDT_CLUST_RESET, i, 0, 0))
ha->hdr[i].cluster_type &= ~CLUSTER_RESERVED;
gdth_polling = FALSE;
spin_unlock_irqrestore(&ha->smp_lock, flags);
}
}
} else {
spin_lock_irqsave(&ha->smp_lock, flags);
for (i = 0; i < MAXID; ++i)
ha->raw[BUS_L2P(ha,b)].io_cnt[i] = 0;
gdth_polling = TRUE;
while (gdth_test_busy(ha))
gdth_delay(0);
gdth_internal_cmd(ha, SCSIRAWSERVICE, GDT_RESET_BUS,
BUS_L2P(ha,b), 0, 0);
gdth_polling = FALSE;
spin_unlock_irqrestore(&ha->smp_lock, flags);
}
return SUCCESS;
}
static int gdth_bios_param(struct scsi_device *sdev,struct block_device *bdev,sector_t cap,int *ip)
{
u8 b, t;
gdth_ha_str *ha = shost_priv(sdev->host);
struct scsi_device *sd;
unsigned capacity;
sd = sdev;
capacity = cap;
b = sd->channel;
t = sd->id;
TRACE2(("gdth_bios_param() ha %d bus %d target %d\n", ha->hanum, b, t));
if (b != ha->virt_bus || ha->hdr[t].heads == 0) {
TRACE2(("Evaluate mapping\n"));
gdth_eval_mapping(capacity,&ip[2],&ip[0],&ip[1]);
} else {
ip[0] = ha->hdr[t].heads;
ip[1] = ha->hdr[t].secs;
ip[2] = capacity / ip[0] / ip[1];
}
TRACE2(("gdth_bios_param(): %d heads, %d secs, %d cyls\n",
ip[0],ip[1],ip[2]));
return 0;
}
static int gdth_queuecommand_lck(struct scsi_cmnd *scp,
void (*done)(struct scsi_cmnd *))
{
gdth_ha_str *ha = shost_priv(scp->device->host);
struct gdth_cmndinfo *cmndinfo;
TRACE(("gdth_queuecommand() cmd 0x%x\n", scp->cmnd[0]));
cmndinfo = gdth_get_cmndinfo(ha);
BUG_ON(!cmndinfo);
scp->scsi_done = done;
cmndinfo->timeout_count = 0;
cmndinfo->priority = DEFAULT_PRI;
return __gdth_queuecommand(ha, scp, cmndinfo);
}
static int gdth_open(struct inode *inode, struct file *filep)
{
gdth_ha_str *ha;
mutex_lock(&gdth_mutex);
list_for_each_entry(ha, &gdth_instances, list) {
if (!ha->sdev)
ha->sdev = scsi_get_host_dev(ha->shost);
}
mutex_unlock(&gdth_mutex);
TRACE(("gdth_open()\n"));
return 0;
}
static int gdth_close(struct inode *inode, struct file *filep)
{
TRACE(("gdth_close()\n"));
return 0;
}
static int ioc_event(void __user *arg)
{
gdth_ioctl_event evt;
gdth_ha_str *ha;
unsigned long flags;
if (copy_from_user(&evt, arg, sizeof(gdth_ioctl_event)))
return -EFAULT;
ha = gdth_find_ha(evt.ionode);
if (!ha)
return -EFAULT;
if (evt.erase == 0xff) {
if (evt.event.event_source == ES_TEST)
evt.event.event_data.size=sizeof(evt.event.event_data.eu.test);
else if (evt.event.event_source == ES_DRIVER)
evt.event.event_data.size=sizeof(evt.event.event_data.eu.driver);
else if (evt.event.event_source == ES_SYNC)
evt.event.event_data.size=sizeof(evt.event.event_data.eu.sync);
else
evt.event.event_data.size=sizeof(evt.event.event_data.eu.async);
spin_lock_irqsave(&ha->smp_lock, flags);
gdth_store_event(ha, evt.event.event_source, evt.event.event_idx,
&evt.event.event_data);
spin_unlock_irqrestore(&ha->smp_lock, flags);
} else if (evt.erase == 0xfe) {
gdth_clear_events();
} else if (evt.erase == 0) {
evt.handle = gdth_read_event(ha, evt.handle, &evt.event);
} else {
gdth_readapp_event(ha, evt.erase, &evt.event);
}
if (copy_to_user(arg, &evt, sizeof(gdth_ioctl_event)))
return -EFAULT;
return 0;
}
static int ioc_lockdrv(void __user *arg)
{
gdth_ioctl_lockdrv ldrv;
u8 i, j;
unsigned long flags;
gdth_ha_str *ha;
if (copy_from_user(&ldrv, arg, sizeof(gdth_ioctl_lockdrv)))
return -EFAULT;
ha = gdth_find_ha(ldrv.ionode);
if (!ha)
return -EFAULT;
for (i = 0; i < ldrv.drive_cnt && i < MAX_HDRIVES; ++i) {
j = ldrv.drives[i];
if (j >= MAX_HDRIVES || !ha->hdr[j].present)
continue;
if (ldrv.lock) {
spin_lock_irqsave(&ha->smp_lock, flags);
ha->hdr[j].lock = 1;
spin_unlock_irqrestore(&ha->smp_lock, flags);
gdth_wait_completion(ha, ha->bus_cnt, j);
} else {
spin_lock_irqsave(&ha->smp_lock, flags);
ha->hdr[j].lock = 0;
spin_unlock_irqrestore(&ha->smp_lock, flags);
gdth_next(ha);
}
}
return 0;
}
static int ioc_resetdrv(void __user *arg, char *cmnd)
{
gdth_ioctl_reset res;
gdth_cmd_str cmd;
gdth_ha_str *ha;
int rval;
if (copy_from_user(&res, arg, sizeof(gdth_ioctl_reset)) ||
res.number >= MAX_HDRIVES)
return -EFAULT;
ha = gdth_find_ha(res.ionode);
if (!ha)
return -EFAULT;
if (!ha->hdr[res.number].present)
return 0;
memset(&cmd, 0, sizeof(gdth_cmd_str));
cmd.Service = CACHESERVICE;
cmd.OpCode = GDT_CLUST_RESET;
if (ha->cache_feat & GDT_64BIT)
cmd.u.cache64.DeviceNo = res.number;
else
cmd.u.cache.DeviceNo = res.number;
rval = __gdth_execute(ha->sdev, &cmd, cmnd, 30, NULL);
if (rval < 0)
return rval;
res.status = rval;
if (copy_to_user(arg, &res, sizeof(gdth_ioctl_reset)))
return -EFAULT;
return 0;
}
static int ioc_general(void __user *arg, char *cmnd)
{
gdth_ioctl_general gen;
char *buf = NULL;
u64 paddr;
gdth_ha_str *ha;
int rval;
if (copy_from_user(&gen, arg, sizeof(gdth_ioctl_general)))
return -EFAULT;
ha = gdth_find_ha(gen.ionode);
if (!ha)
return -EFAULT;
if (gen.data_len > INT_MAX)
return -EINVAL;
if (gen.sense_len > INT_MAX)
return -EINVAL;
if (gen.data_len + gen.sense_len > INT_MAX)
return -EINVAL;
if (gen.data_len + gen.sense_len != 0) {
if (!(buf = gdth_ioctl_alloc(ha, gen.data_len + gen.sense_len,
FALSE, &paddr)))
return -EFAULT;
if (copy_from_user(buf, arg + sizeof(gdth_ioctl_general),
gen.data_len + gen.sense_len)) {
gdth_ioctl_free(ha, gen.data_len+gen.sense_len, buf, paddr);
return -EFAULT;
}
if (gen.command.OpCode == GDT_IOCTL) {
gen.command.u.ioctl.p_param = paddr;
} else if (gen.command.Service == CACHESERVICE) {
if (ha->cache_feat & GDT_64BIT) {
gen.command.u.cache64.BlockCnt = gen.command.u.cache.BlockCnt;
gen.command.u.cache64.BlockNo = gen.command.u.cache.BlockNo;
gen.command.u.cache64.DeviceNo = gen.command.u.cache.DeviceNo;
if (ha->cache_feat & SCATTER_GATHER) {
gen.command.u.cache64.DestAddr = (u64)-1;
gen.command.u.cache64.sg_canz = 1;
gen.command.u.cache64.sg_lst[0].sg_ptr = paddr;
gen.command.u.cache64.sg_lst[0].sg_len = gen.data_len;
gen.command.u.cache64.sg_lst[1].sg_len = 0;
} else {
gen.command.u.cache64.DestAddr = paddr;
gen.command.u.cache64.sg_canz = 0;
}
} else {
if (ha->cache_feat & SCATTER_GATHER) {
gen.command.u.cache.DestAddr = 0xffffffff;
gen.command.u.cache.sg_canz = 1;
gen.command.u.cache.sg_lst[0].sg_ptr = (u32)paddr;
gen.command.u.cache.sg_lst[0].sg_len = gen.data_len;
gen.command.u.cache.sg_lst[1].sg_len = 0;
} else {
gen.command.u.cache.DestAddr = paddr;
gen.command.u.cache.sg_canz = 0;
}
}
} else if (gen.command.Service == SCSIRAWSERVICE) {
if (ha->raw_feat & GDT_64BIT) {
char cmd[16];
gen.command.u.raw64.sense_len = gen.command.u.raw.sense_len;
gen.command.u.raw64.bus = gen.command.u.raw.bus;
gen.command.u.raw64.lun = gen.command.u.raw.lun;
gen.command.u.raw64.target = gen.command.u.raw.target;
memcpy(cmd, gen.command.u.raw.cmd, 16);
memcpy(gen.command.u.raw64.cmd, cmd, 16);
gen.command.u.raw64.clen = gen.command.u.raw.clen;
gen.command.u.raw64.sdlen = gen.command.u.raw.sdlen;
gen.command.u.raw64.direction = gen.command.u.raw.direction;
if (ha->raw_feat & SCATTER_GATHER) {
gen.command.u.raw64.sdata = (u64)-1;
gen.command.u.raw64.sg_ranz = 1;
gen.command.u.raw64.sg_lst[0].sg_ptr = paddr;
gen.command.u.raw64.sg_lst[0].sg_len = gen.data_len;
gen.command.u.raw64.sg_lst[1].sg_len = 0;
} else {
gen.command.u.raw64.sdata = paddr;
gen.command.u.raw64.sg_ranz = 0;
}
gen.command.u.raw64.sense_data = paddr + gen.data_len;
} else {
if (ha->raw_feat & SCATTER_GATHER) {
gen.command.u.raw.sdata = 0xffffffff;
gen.command.u.raw.sg_ranz = 1;
gen.command.u.raw.sg_lst[0].sg_ptr = (u32)paddr;
gen.command.u.raw.sg_lst[0].sg_len = gen.data_len;
gen.command.u.raw.sg_lst[1].sg_len = 0;
} else {
gen.command.u.raw.sdata = paddr;
gen.command.u.raw.sg_ranz = 0;
}
gen.command.u.raw.sense_data = (u32)paddr + gen.data_len;
}
} else {
gdth_ioctl_free(ha, gen.data_len+gen.sense_len, buf, paddr);
return -EFAULT;
}
}
rval = __gdth_execute(ha->sdev, &gen.command, cmnd, gen.timeout, &gen.info);
if (rval < 0) {
gdth_ioctl_free(ha, gen.data_len+gen.sense_len, buf, paddr);
return rval;
}
gen.status = rval;
if (copy_to_user(arg + sizeof(gdth_ioctl_general), buf,
gen.data_len + gen.sense_len)) {
gdth_ioctl_free(ha, gen.data_len+gen.sense_len, buf, paddr);
return -EFAULT;
}
if (copy_to_user(arg, &gen,
sizeof(gdth_ioctl_general) - sizeof(gdth_cmd_str))) {
gdth_ioctl_free(ha, gen.data_len+gen.sense_len, buf, paddr);
return -EFAULT;
}
gdth_ioctl_free(ha, gen.data_len+gen.sense_len, buf, paddr);
return 0;
}
static int ioc_hdrlist(void __user *arg, char *cmnd)
{
gdth_ioctl_rescan *rsc;
gdth_cmd_str *cmd;
gdth_ha_str *ha;
u8 i;
int rc = -ENOMEM;
u32 cluster_type = 0;
rsc = kmalloc(sizeof(*rsc), GFP_KERNEL);
cmd = kmalloc(sizeof(*cmd), GFP_KERNEL);
if (!rsc || !cmd)
goto free_fail;
if (copy_from_user(rsc, arg, sizeof(gdth_ioctl_rescan)) ||
(NULL == (ha = gdth_find_ha(rsc->ionode)))) {
rc = -EFAULT;
goto free_fail;
}
memset(cmd, 0, sizeof(gdth_cmd_str));
for (i = 0; i < MAX_HDRIVES; ++i) {
if (!ha->hdr[i].present) {
rsc->hdr_list[i].bus = 0xff;
continue;
}
rsc->hdr_list[i].bus = ha->virt_bus;
rsc->hdr_list[i].target = i;
rsc->hdr_list[i].lun = 0;
rsc->hdr_list[i].cluster_type = ha->hdr[i].cluster_type;
if (ha->hdr[i].cluster_type & CLUSTER_DRIVE) {
cmd->Service = CACHESERVICE;
cmd->OpCode = GDT_CLUST_INFO;
if (ha->cache_feat & GDT_64BIT)
cmd->u.cache64.DeviceNo = i;
else
cmd->u.cache.DeviceNo = i;
if (__gdth_execute(ha->sdev, cmd, cmnd, 30, &cluster_type) == S_OK)
rsc->hdr_list[i].cluster_type = cluster_type;
}
}
if (copy_to_user(arg, rsc, sizeof(gdth_ioctl_rescan)))
rc = -EFAULT;
else
rc = 0;
free_fail:
kfree(rsc);
kfree(cmd);
return rc;
}
static int ioc_rescan(void __user *arg, char *cmnd)
{
gdth_ioctl_rescan *rsc;
gdth_cmd_str *cmd;
u16 i, status, hdr_cnt;
u32 info;
int cyls, hds, secs;
int rc = -ENOMEM;
unsigned long flags;
gdth_ha_str *ha;
rsc = kmalloc(sizeof(*rsc), GFP_KERNEL);
cmd = kmalloc(sizeof(*cmd), GFP_KERNEL);
if (!cmd || !rsc)
goto free_fail;
if (copy_from_user(rsc, arg, sizeof(gdth_ioctl_rescan)) ||
(NULL == (ha = gdth_find_ha(rsc->ionode)))) {
rc = -EFAULT;
goto free_fail;
}
memset(cmd, 0, sizeof(gdth_cmd_str));
if (rsc->flag == 0) {
cmd->Service = CACHESERVICE;
if (ha->cache_feat & GDT_64BIT) {
cmd->OpCode = GDT_X_INIT_HOST;
cmd->u.cache64.DeviceNo = LINUX_OS;
} else {
cmd->OpCode = GDT_INIT;
cmd->u.cache.DeviceNo = LINUX_OS;
}
status = __gdth_execute(ha->sdev, cmd, cmnd, 30, &info);
i = 0;
hdr_cnt = (status == S_OK ? (u16)info : 0);
} else {
i = rsc->hdr_no;
hdr_cnt = i + 1;
}
for (; i < hdr_cnt && i < MAX_HDRIVES; ++i) {
cmd->Service = CACHESERVICE;
cmd->OpCode = GDT_INFO;
if (ha->cache_feat & GDT_64BIT)
cmd->u.cache64.DeviceNo = i;
else
cmd->u.cache.DeviceNo = i;
status = __gdth_execute(ha->sdev, cmd, cmnd, 30, &info);
spin_lock_irqsave(&ha->smp_lock, flags);
rsc->hdr_list[i].bus = ha->virt_bus;
rsc->hdr_list[i].target = i;
rsc->hdr_list[i].lun = 0;
if (status != S_OK) {
ha->hdr[i].present = FALSE;
} else {
ha->hdr[i].present = TRUE;
ha->hdr[i].size = info;
ha->hdr[i].size &= ~SECS32;
gdth_eval_mapping(ha->hdr[i].size,&cyls,&hds,&secs);
ha->hdr[i].heads = hds;
ha->hdr[i].secs = secs;
ha->hdr[i].size = cyls * hds * secs;
}
spin_unlock_irqrestore(&ha->smp_lock, flags);
if (status != S_OK)
continue;
cmd->Service = CACHESERVICE;
cmd->OpCode = GDT_DEVTYPE;
if (ha->cache_feat & GDT_64BIT)
cmd->u.cache64.DeviceNo = i;
else
cmd->u.cache.DeviceNo = i;
status = __gdth_execute(ha->sdev, cmd, cmnd, 30, &info);
spin_lock_irqsave(&ha->smp_lock, flags);
ha->hdr[i].devtype = (status == S_OK ? (u16)info : 0);
spin_unlock_irqrestore(&ha->smp_lock, flags);
cmd->Service = CACHESERVICE;
cmd->OpCode = GDT_CLUST_INFO;
if (ha->cache_feat & GDT_64BIT)
cmd->u.cache64.DeviceNo = i;
else
cmd->u.cache.DeviceNo = i;
status = __gdth_execute(ha->sdev, cmd, cmnd, 30, &info);
spin_lock_irqsave(&ha->smp_lock, flags);
ha->hdr[i].cluster_type =
((status == S_OK && !shared_access) ? (u16)info : 0);
spin_unlock_irqrestore(&ha->smp_lock, flags);
rsc->hdr_list[i].cluster_type = ha->hdr[i].cluster_type;
cmd->Service = CACHESERVICE;
cmd->OpCode = GDT_RW_ATTRIBS;
if (ha->cache_feat & GDT_64BIT)
cmd->u.cache64.DeviceNo = i;
else
cmd->u.cache.DeviceNo = i;
status = __gdth_execute(ha->sdev, cmd, cmnd, 30, &info);
spin_lock_irqsave(&ha->smp_lock, flags);
ha->hdr[i].rw_attribs = (status == S_OK ? (u16)info : 0);
spin_unlock_irqrestore(&ha->smp_lock, flags);
}
if (copy_to_user(arg, rsc, sizeof(gdth_ioctl_rescan)))
rc = -EFAULT;
else
rc = 0;
free_fail:
kfree(rsc);
kfree(cmd);
return rc;
}
static int gdth_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
gdth_ha_str *ha;
Scsi_Cmnd *scp;
unsigned long flags;
char cmnd[MAX_COMMAND_SIZE];
void __user *argp = (void __user *)arg;
memset(cmnd, 0xff, 12);
TRACE(("gdth_ioctl() cmd 0x%x\n", cmd));
switch (cmd) {
case GDTIOCTL_CTRCNT:
{
int cnt = gdth_ctr_count;
if (put_user(cnt, (int __user *)argp))
return -EFAULT;
break;
}
case GDTIOCTL_DRVERS:
{
int ver = (GDTH_VERSION<<8) | GDTH_SUBVERSION;
if (put_user(ver, (int __user *)argp))
return -EFAULT;
break;
}
case GDTIOCTL_OSVERS:
{
gdth_ioctl_osvers osv;
osv.version = (u8)(LINUX_VERSION_CODE >> 16);
osv.subversion = (u8)(LINUX_VERSION_CODE >> 8);
osv.revision = (u16)(LINUX_VERSION_CODE & 0xff);
if (copy_to_user(argp, &osv, sizeof(gdth_ioctl_osvers)))
return -EFAULT;
break;
}
case GDTIOCTL_CTRTYPE:
{
gdth_ioctl_ctrtype ctrt;
if (copy_from_user(&ctrt, argp, sizeof(gdth_ioctl_ctrtype)) ||
(NULL == (ha = gdth_find_ha(ctrt.ionode))))
return -EFAULT;
if (ha->type == GDT_ISA || ha->type == GDT_EISA) {
ctrt.type = (u8)((ha->stype>>20) - 0x10);
} else {
if (ha->type != GDT_PCIMPR) {
ctrt.type = (u8)((ha->stype<<4) + 6);
} else {
ctrt.type =
(ha->oem_id == OEM_ID_INTEL ? 0xfd : 0xfe);
if (ha->stype >= 0x300)
ctrt.ext_type = 0x6000 | ha->pdev->subsystem_device;
else
ctrt.ext_type = 0x6000 | ha->stype;
}
ctrt.device_id = ha->pdev->device;
ctrt.sub_device_id = ha->pdev->subsystem_device;
}
ctrt.info = ha->brd_phys;
ctrt.oem_id = ha->oem_id;
if (copy_to_user(argp, &ctrt, sizeof(gdth_ioctl_ctrtype)))
return -EFAULT;
break;
}
case GDTIOCTL_GENERAL:
return ioc_general(argp, cmnd);
case GDTIOCTL_EVENT:
return ioc_event(argp);
case GDTIOCTL_LOCKDRV:
return ioc_lockdrv(argp);
case GDTIOCTL_LOCKCHN:
{
gdth_ioctl_lockchn lchn;
u8 i, j;
if (copy_from_user(&lchn, argp, sizeof(gdth_ioctl_lockchn)) ||
(NULL == (ha = gdth_find_ha(lchn.ionode))))
return -EFAULT;
i = lchn.channel;
if (i < ha->bus_cnt) {
if (lchn.lock) {
spin_lock_irqsave(&ha->smp_lock, flags);
ha->raw[i].lock = 1;
spin_unlock_irqrestore(&ha->smp_lock, flags);
for (j = 0; j < ha->tid_cnt; ++j)
gdth_wait_completion(ha, i, j);
} else {
spin_lock_irqsave(&ha->smp_lock, flags);
ha->raw[i].lock = 0;
spin_unlock_irqrestore(&ha->smp_lock, flags);
for (j = 0; j < ha->tid_cnt; ++j)
gdth_next(ha);
}
}
break;
}
case GDTIOCTL_RESCAN:
return ioc_rescan(argp, cmnd);
case GDTIOCTL_HDRLIST:
return ioc_hdrlist(argp, cmnd);
case GDTIOCTL_RESET_BUS:
{
gdth_ioctl_reset res;
int rval;
if (copy_from_user(&res, argp, sizeof(gdth_ioctl_reset)) ||
(NULL == (ha = gdth_find_ha(res.ionode))))
return -EFAULT;
scp = kzalloc(sizeof(*scp), GFP_KERNEL);
if (!scp)
return -ENOMEM;
scp->device = ha->sdev;
scp->cmd_len = 12;
scp->device->channel = res.number;
rval = gdth_eh_bus_reset(scp);
res.status = (rval == SUCCESS ? S_OK : S_GENERR);
kfree(scp);
if (copy_to_user(argp, &res, sizeof(gdth_ioctl_reset)))
return -EFAULT;
break;
}
case GDTIOCTL_RESET_DRV:
return ioc_resetdrv(argp, cmnd);
default:
break;
}
return 0;
}
static long gdth_unlocked_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret;
mutex_lock(&gdth_mutex);
ret = gdth_ioctl(file, cmd, arg);
mutex_unlock(&gdth_mutex);
return ret;
}
static void gdth_flush(gdth_ha_str *ha)
{
int i;
gdth_cmd_str gdtcmd;
char cmnd[MAX_COMMAND_SIZE];
memset(cmnd, 0xff, MAX_COMMAND_SIZE);
TRACE2(("gdth_flush() hanum %d\n", ha->hanum));
for (i = 0; i < MAX_HDRIVES; ++i) {
if (ha->hdr[i].present) {
gdtcmd.BoardNode = LOCALBOARD;
gdtcmd.Service = CACHESERVICE;
gdtcmd.OpCode = GDT_FLUSH;
if (ha->cache_feat & GDT_64BIT) {
gdtcmd.u.cache64.DeviceNo = i;
gdtcmd.u.cache64.BlockNo = 1;
gdtcmd.u.cache64.sg_canz = 0;
} else {
gdtcmd.u.cache.DeviceNo = i;
gdtcmd.u.cache.BlockNo = 1;
gdtcmd.u.cache.sg_canz = 0;
}
TRACE2(("gdth_flush(): flush ha %d drive %d\n", ha->hanum, i));
gdth_execute(ha->shost, &gdtcmd, cmnd, 30, NULL);
}
}
}
static int gdth_slave_configure(struct scsi_device *sdev)
{
scsi_adjust_queue_depth(sdev, 0, sdev->host->cmd_per_lun);
sdev->skip_ms_page_3f = 1;
sdev->skip_ms_page_8 = 1;
return 0;
}
static int __init gdth_isa_probe_one(u32 isa_bios)
{
struct Scsi_Host *shp;
gdth_ha_str *ha;
dma_addr_t scratch_dma_handle = 0;
int error, i;
if (!gdth_search_isa(isa_bios))
return -ENXIO;
shp = scsi_host_alloc(&gdth_template, sizeof(gdth_ha_str));
if (!shp)
return -ENOMEM;
ha = shost_priv(shp);
error = -ENODEV;
if (!gdth_init_isa(isa_bios,ha))
goto out_host_put;
printk("Configuring GDT-ISA HA at BIOS 0x%05X IRQ %u DRQ %u\n",
isa_bios, ha->irq, ha->drq);
error = request_irq(ha->irq, gdth_interrupt, IRQF_DISABLED, "gdth", ha);
if (error) {
printk("GDT-ISA: Unable to allocate IRQ\n");
goto out_host_put;
}
error = request_dma(ha->drq, "gdth");
if (error) {
printk("GDT-ISA: Unable to allocate DMA channel\n");
goto out_free_irq;
}
set_dma_mode(ha->drq,DMA_MODE_CASCADE);
enable_dma(ha->drq);
shp->unchecked_isa_dma = 1;
shp->irq = ha->irq;
shp->dma_channel = ha->drq;
ha->hanum = gdth_ctr_count++;
ha->shost = shp;
ha->pccb = &ha->cmdext;
ha->ccb_phys = 0L;
ha->pdev = NULL;
error = -ENOMEM;
ha->pscratch = pci_alloc_consistent(ha->pdev, GDTH_SCRATCH,
&scratch_dma_handle);
if (!ha->pscratch)
goto out_dec_counters;
ha->scratch_phys = scratch_dma_handle;
ha->pmsg = pci_alloc_consistent(ha->pdev, sizeof(gdth_msg_str),
&scratch_dma_handle);
if (!ha->pmsg)
goto out_free_pscratch;
ha->msg_phys = scratch_dma_handle;
#ifdef INT_COAL
ha->coal_stat = pci_alloc_consistent(ha->pdev,
sizeof(gdth_coal_status) * MAXOFFSETS,
&scratch_dma_handle);
if (!ha->coal_stat)
goto out_free_pmsg;
ha->coal_stat_phys = scratch_dma_handle;
#endif
ha->scratch_busy = FALSE;
ha->req_first = NULL;
ha->tid_cnt = MAX_HDRIVES;
if (max_ids > 0 && max_ids < ha->tid_cnt)
ha->tid_cnt = max_ids;
for (i = 0; i < GDTH_MAXCMDS; ++i)
ha->cmd_tab[i].cmnd = UNUSED_CMND;
ha->scan_mode = rescan ? 0x10 : 0;
error = -ENODEV;
if (!gdth_search_drives(ha)) {
printk("GDT-ISA: Error during device scan\n");
goto out_free_coal_stat;
}
if (hdr_channel < 0 || hdr_channel > ha->bus_cnt)
hdr_channel = ha->bus_cnt;
ha->virt_bus = hdr_channel;
if (ha->cache_feat & ha->raw_feat & ha->screen_feat & GDT_64BIT)
shp->max_cmd_len = 16;
shp->max_id = ha->tid_cnt;
shp->max_lun = MAXLUN;
shp->max_channel = ha->bus_cnt;
spin_lock_init(&ha->smp_lock);
gdth_enable_int(ha);
error = scsi_add_host(shp, NULL);
if (error)
goto out_free_coal_stat;
list_add_tail(&ha->list, &gdth_instances);
gdth_timer_init();
scsi_scan_host(shp);
return 0;
out_free_coal_stat:
#ifdef INT_COAL
pci_free_consistent(ha->pdev, sizeof(gdth_coal_status) * MAXOFFSETS,
ha->coal_stat, ha->coal_stat_phys);
out_free_pmsg:
#endif
pci_free_consistent(ha->pdev, sizeof(gdth_msg_str),
ha->pmsg, ha->msg_phys);
out_free_pscratch:
pci_free_consistent(ha->pdev, GDTH_SCRATCH,
ha->pscratch, ha->scratch_phys);
out_dec_counters:
gdth_ctr_count--;
out_free_irq:
free_irq(ha->irq, ha);
out_host_put:
scsi_host_put(shp);
return error;
}
static int __init gdth_eisa_probe_one(u16 eisa_slot)
{
struct Scsi_Host *shp;
gdth_ha_str *ha;
dma_addr_t scratch_dma_handle = 0;
int error, i;
if (!gdth_search_eisa(eisa_slot))
return -ENXIO;
shp = scsi_host_alloc(&gdth_template, sizeof(gdth_ha_str));
if (!shp)
return -ENOMEM;
ha = shost_priv(shp);
error = -ENODEV;
if (!gdth_init_eisa(eisa_slot,ha))
goto out_host_put;
printk("Configuring GDT-EISA HA at Slot %d IRQ %u\n",
eisa_slot >> 12, ha->irq);
error = request_irq(ha->irq, gdth_interrupt, IRQF_DISABLED, "gdth", ha);
if (error) {
printk("GDT-EISA: Unable to allocate IRQ\n");
goto out_host_put;
}
shp->unchecked_isa_dma = 0;
shp->irq = ha->irq;
shp->dma_channel = 0xff;
ha->hanum = gdth_ctr_count++;
ha->shost = shp;
TRACE2(("EISA detect Bus 0: hanum %d\n", ha->hanum));
ha->pccb = &ha->cmdext;
ha->ccb_phys = 0L;
error = -ENOMEM;
ha->pdev = NULL;
ha->pscratch = pci_alloc_consistent(ha->pdev, GDTH_SCRATCH,
&scratch_dma_handle);
if (!ha->pscratch)
goto out_free_irq;
ha->scratch_phys = scratch_dma_handle;
ha->pmsg = pci_alloc_consistent(ha->pdev, sizeof(gdth_msg_str),
&scratch_dma_handle);
if (!ha->pmsg)
goto out_free_pscratch;
ha->msg_phys = scratch_dma_handle;
#ifdef INT_COAL
ha->coal_stat = pci_alloc_consistent(ha->pdev,
sizeof(gdth_coal_status) * MAXOFFSETS,
&scratch_dma_handle);
if (!ha->coal_stat)
goto out_free_pmsg;
ha->coal_stat_phys = scratch_dma_handle;
#endif
ha->ccb_phys = pci_map_single(ha->pdev,ha->pccb,
sizeof(gdth_cmd_str), PCI_DMA_BIDIRECTIONAL);
if (!ha->ccb_phys)
goto out_free_coal_stat;
ha->scratch_busy = FALSE;
ha->req_first = NULL;
ha->tid_cnt = MAX_HDRIVES;
if (max_ids > 0 && max_ids < ha->tid_cnt)
ha->tid_cnt = max_ids;
for (i = 0; i < GDTH_MAXCMDS; ++i)
ha->cmd_tab[i].cmnd = UNUSED_CMND;
ha->scan_mode = rescan ? 0x10 : 0;
if (!gdth_search_drives(ha)) {
printk("GDT-EISA: Error during device scan\n");
error = -ENODEV;
goto out_free_ccb_phys;
}
if (hdr_channel < 0 || hdr_channel > ha->bus_cnt)
hdr_channel = ha->bus_cnt;
ha->virt_bus = hdr_channel;
if (ha->cache_feat & ha->raw_feat & ha->screen_feat & GDT_64BIT)
shp->max_cmd_len = 16;
shp->max_id = ha->tid_cnt;
shp->max_lun = MAXLUN;
shp->max_channel = ha->bus_cnt;
spin_lock_init(&ha->smp_lock);
gdth_enable_int(ha);
error = scsi_add_host(shp, NULL);
if (error)
goto out_free_ccb_phys;
list_add_tail(&ha->list, &gdth_instances);
gdth_timer_init();
scsi_scan_host(shp);
return 0;
out_free_ccb_phys:
pci_unmap_single(ha->pdev,ha->ccb_phys, sizeof(gdth_cmd_str),
PCI_DMA_BIDIRECTIONAL);
out_free_coal_stat:
#ifdef INT_COAL
pci_free_consistent(ha->pdev, sizeof(gdth_coal_status) * MAXOFFSETS,
ha->coal_stat, ha->coal_stat_phys);
out_free_pmsg:
#endif
pci_free_consistent(ha->pdev, sizeof(gdth_msg_str),
ha->pmsg, ha->msg_phys);
out_free_pscratch:
pci_free_consistent(ha->pdev, GDTH_SCRATCH,
ha->pscratch, ha->scratch_phys);
out_free_irq:
free_irq(ha->irq, ha);
gdth_ctr_count--;
out_host_put:
scsi_host_put(shp);
return error;
}
static int __devinit gdth_pci_probe_one(gdth_pci_str *pcistr,
gdth_ha_str **ha_out)
{
struct Scsi_Host *shp;
gdth_ha_str *ha;
dma_addr_t scratch_dma_handle = 0;
int error, i;
struct pci_dev *pdev = pcistr->pdev;
*ha_out = NULL;
shp = scsi_host_alloc(&gdth_template, sizeof(gdth_ha_str));
if (!shp)
return -ENOMEM;
ha = shost_priv(shp);
error = -ENODEV;
if (!gdth_init_pci(pdev, pcistr, ha))
goto out_host_put;
printk("Configuring GDT-PCI HA at %d/%d IRQ %u\n",
pdev->bus->number,
PCI_SLOT(pdev->devfn),
ha->irq);
error = request_irq(ha->irq, gdth_interrupt,
IRQF_DISABLED|IRQF_SHARED, "gdth", ha);
if (error) {
printk("GDT-PCI: Unable to allocate IRQ\n");
goto out_host_put;
}
shp->unchecked_isa_dma = 0;
shp->irq = ha->irq;
shp->dma_channel = 0xff;
ha->hanum = gdth_ctr_count++;
ha->shost = shp;
ha->pccb = &ha->cmdext;
ha->ccb_phys = 0L;
error = -ENOMEM;
ha->pscratch = pci_alloc_consistent(ha->pdev, GDTH_SCRATCH,
&scratch_dma_handle);
if (!ha->pscratch)
goto out_free_irq;
ha->scratch_phys = scratch_dma_handle;
ha->pmsg = pci_alloc_consistent(ha->pdev, sizeof(gdth_msg_str),
&scratch_dma_handle);
if (!ha->pmsg)
goto out_free_pscratch;
ha->msg_phys = scratch_dma_handle;
#ifdef INT_COAL
ha->coal_stat = pci_alloc_consistent(ha->pdev,
sizeof(gdth_coal_status) * MAXOFFSETS,
&scratch_dma_handle);
if (!ha->coal_stat)
goto out_free_pmsg;
ha->coal_stat_phys = scratch_dma_handle;
#endif
ha->scratch_busy = FALSE;
ha->req_first = NULL;
ha->tid_cnt = pdev->device >= 0x200 ? MAXID : MAX_HDRIVES;
if (max_ids > 0 && max_ids < ha->tid_cnt)
ha->tid_cnt = max_ids;
for (i = 0; i < GDTH_MAXCMDS; ++i)
ha->cmd_tab[i].cmnd = UNUSED_CMND;
ha->scan_mode = rescan ? 0x10 : 0;
error = -ENODEV;
if (!gdth_search_drives(ha)) {
printk("GDT-PCI %d: Error during device scan\n", ha->hanum);
goto out_free_coal_stat;
}
if (hdr_channel < 0 || hdr_channel > ha->bus_cnt)
hdr_channel = ha->bus_cnt;
ha->virt_bus = hdr_channel;
if (!(ha->cache_feat & ha->raw_feat & ha->screen_feat & GDT_64BIT) ||
!ha->dma64_support) {
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
printk(KERN_WARNING "GDT-PCI %d: "
"Unable to set 32-bit DMA\n", ha->hanum);
goto out_free_coal_stat;
}
} else {
shp->max_cmd_len = 16;
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
printk("GDT-PCI %d: 64-bit DMA enabled\n", ha->hanum);
} else if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
printk(KERN_WARNING "GDT-PCI %d: "
"Unable to set 64/32-bit DMA\n", ha->hanum);
goto out_free_coal_stat;
}
}
shp->max_id = ha->tid_cnt;
shp->max_lun = MAXLUN;
shp->max_channel = ha->bus_cnt;
spin_lock_init(&ha->smp_lock);
gdth_enable_int(ha);
error = scsi_add_host(shp, &pdev->dev);
if (error)
goto out_free_coal_stat;
list_add_tail(&ha->list, &gdth_instances);
pci_set_drvdata(ha->pdev, ha);
gdth_timer_init();
scsi_scan_host(shp);
*ha_out = ha;
return 0;
out_free_coal_stat:
#ifdef INT_COAL
pci_free_consistent(ha->pdev, sizeof(gdth_coal_status) * MAXOFFSETS,
ha->coal_stat, ha->coal_stat_phys);
out_free_pmsg:
#endif
pci_free_consistent(ha->pdev, sizeof(gdth_msg_str),
ha->pmsg, ha->msg_phys);
out_free_pscratch:
pci_free_consistent(ha->pdev, GDTH_SCRATCH,
ha->pscratch, ha->scratch_phys);
out_free_irq:
free_irq(ha->irq, ha);
gdth_ctr_count--;
out_host_put:
scsi_host_put(shp);
return error;
}
static void gdth_remove_one(gdth_ha_str *ha)
{
struct Scsi_Host *shp = ha->shost;
TRACE2(("gdth_remove_one()\n"));
scsi_remove_host(shp);
gdth_flush(ha);
if (ha->sdev) {
scsi_free_host_dev(ha->sdev);
ha->sdev = NULL;
}
if (shp->irq)
free_irq(shp->irq,ha);
#ifdef CONFIG_ISA
if (shp->dma_channel != 0xff)
free_dma(shp->dma_channel);
#endif
#ifdef INT_COAL
if (ha->coal_stat)
pci_free_consistent(ha->pdev, sizeof(gdth_coal_status) *
MAXOFFSETS, ha->coal_stat, ha->coal_stat_phys);
#endif
if (ha->pscratch)
pci_free_consistent(ha->pdev, GDTH_SCRATCH,
ha->pscratch, ha->scratch_phys);
if (ha->pmsg)
pci_free_consistent(ha->pdev, sizeof(gdth_msg_str),
ha->pmsg, ha->msg_phys);
if (ha->ccb_phys)
pci_unmap_single(ha->pdev,ha->ccb_phys,
sizeof(gdth_cmd_str),PCI_DMA_BIDIRECTIONAL);
scsi_host_put(shp);
}
static int gdth_halt(struct notifier_block *nb, unsigned long event, void *buf)
{
gdth_ha_str *ha;
TRACE2(("gdth_halt() event %d\n", (int)event));
if (event != SYS_RESTART && event != SYS_HALT && event != SYS_POWER_OFF)
return NOTIFY_DONE;
list_for_each_entry(ha, &gdth_instances, list)
gdth_flush(ha);
return NOTIFY_OK;
}
static int __init gdth_init(void)
{
if (disable) {
printk("GDT-HA: Controller driver disabled from"
" command line !\n");
return 0;
}
printk("GDT-HA: Storage RAID Controller Driver. Version: %s\n",
GDTH_VERSION_STR);
gdth_polling = TRUE;
gdth_clear_events();
init_timer(&gdth_timer);
if (probe_eisa_isa) {
#ifdef CONFIG_ISA
u32 isa_bios;
for (isa_bios = 0xc8000UL; isa_bios <= 0xd8000UL;
isa_bios += 0x8000UL)
gdth_isa_probe_one(isa_bios);
#endif
#ifdef CONFIG_EISA
{
u16 eisa_slot;
for (eisa_slot = 0x1000; eisa_slot <= 0x8000;
eisa_slot += 0x1000)
gdth_eisa_probe_one(eisa_slot);
}
#endif
}
#ifdef CONFIG_PCI
if (pci_register_driver(&gdth_pci_driver)) {
gdth_ha_str *ha;
list_for_each_entry(ha, &gdth_instances, list)
gdth_remove_one(ha);
return -ENODEV;
}
#endif
TRACE2(("gdth_detect() %d controller detected\n", gdth_ctr_count));
major = register_chrdev(0,"gdth", &gdth_fops);
register_reboot_notifier(&gdth_notifier);
gdth_polling = FALSE;
return 0;
}
static void __exit gdth_exit(void)
{
gdth_ha_str *ha;
unregister_chrdev(major, "gdth");
unregister_reboot_notifier(&gdth_notifier);
#ifdef GDTH_STATISTICS
del_timer_sync(&gdth_timer);
#endif
#ifdef CONFIG_PCI
pci_unregister_driver(&gdth_pci_driver);
#endif
list_for_each_entry(ha, &gdth_instances, list)
gdth_remove_one(ha);
}
