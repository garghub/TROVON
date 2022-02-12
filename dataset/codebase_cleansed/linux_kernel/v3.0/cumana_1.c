void cumanascsi_setup(char *str, int *ints)
{
}
const char *cumanascsi_info(struct Scsi_Host *spnt)
{
return "";
}
static inline int
NCR5380_pwrite(struct Scsi_Host *host, unsigned char *addr, int len)
{
unsigned long *laddr;
void __iomem *dma = priv(host)->dma + 0x2000;
if(!len) return 0;
writeb(0x02, priv(host)->base + CTRL);
laddr = (unsigned long *)addr;
while(len >= 32)
{
unsigned int status;
unsigned long v;
status = readb(priv(host)->base + STAT);
if(status & 0x80)
goto end;
if(!(status & 0x40))
continue;
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
v=*laddr++; writew(L(v), dma); writew(H(v), dma);
len -= 32;
if(len == 0)
break;
}
addr = (unsigned char *)laddr;
writeb(0x12, priv(host)->base + CTRL);
while(len > 0)
{
unsigned int status;
status = readb(priv(host)->base + STAT);
if(status & 0x80)
goto end;
if(status & 0x40)
{
writeb(*addr++, dma);
if(--len == 0)
break;
}
status = readb(priv(host)->base + STAT);
if(status & 0x80)
goto end;
if(status & 0x40)
{
writeb(*addr++, dma);
if(--len == 0)
break;
}
}
end:
writeb(priv(host)->ctrl | 0x40, priv(host)->base + CTRL);
return len;
}
static inline int
NCR5380_pread(struct Scsi_Host *host, unsigned char *addr, int len)
{
unsigned long *laddr;
void __iomem *dma = priv(host)->dma + 0x2000;
if(!len) return 0;
writeb(0x00, priv(host)->base + CTRL);
laddr = (unsigned long *)addr;
while(len >= 32)
{
unsigned int status;
status = readb(priv(host)->base + STAT);
if(status & 0x80)
goto end;
if(!(status & 0x40))
continue;
*laddr++ = readw(dma) | (readw(dma) << 16);
*laddr++ = readw(dma) | (readw(dma) << 16);
*laddr++ = readw(dma) | (readw(dma) << 16);
*laddr++ = readw(dma) | (readw(dma) << 16);
*laddr++ = readw(dma) | (readw(dma) << 16);
*laddr++ = readw(dma) | (readw(dma) << 16);
*laddr++ = readw(dma) | (readw(dma) << 16);
*laddr++ = readw(dma) | (readw(dma) << 16);
len -= 32;
if(len == 0)
break;
}
addr = (unsigned char *)laddr;
writeb(0x10, priv(host)->base + CTRL);
while(len > 0)
{
unsigned int status;
status = readb(priv(host)->base + STAT);
if(status & 0x80)
goto end;
if(status & 0x40)
{
*addr++ = readb(dma);
if(--len == 0)
break;
}
status = readb(priv(host)->base + STAT);
if(status & 0x80)
goto end;
if(status & 0x40)
{
*addr++ = readb(dma);
if(--len == 0)
break;
}
}
end:
writeb(priv(host)->ctrl | 0x40, priv(host)->base + CTRL);
return len;
}
static unsigned char cumanascsi_read(struct Scsi_Host *host, unsigned int reg)
{
void __iomem *base = priv(host)->base;
unsigned char val;
writeb(0, base + CTRL);
val = readb(base + 0x2100 + (reg << 2));
priv(host)->ctrl = 0x40;
writeb(0x40, base + CTRL);
return val;
}
static void cumanascsi_write(struct Scsi_Host *host, unsigned int reg, unsigned int value)
{
void __iomem *base = priv(host)->base;
writeb(0, base + CTRL);
writeb(value, base + 0x2100 + (reg << 2));
priv(host)->ctrl = 0x40;
writeb(0x40, base + CTRL);
}
static int __devinit
cumanascsi1_probe(struct expansion_card *ec, const struct ecard_id *id)
{
struct Scsi_Host *host;
int ret;
ret = ecard_request_resources(ec);
if (ret)
goto out;
host = scsi_host_alloc(&cumanascsi_template, sizeof(struct NCR5380_hostdata));
if (!host) {
ret = -ENOMEM;
goto out_release;
}
priv(host)->base = ioremap(ecard_resource_start(ec, ECARD_RES_IOCSLOW),
ecard_resource_len(ec, ECARD_RES_IOCSLOW));
priv(host)->dma = ioremap(ecard_resource_start(ec, ECARD_RES_MEMC),
ecard_resource_len(ec, ECARD_RES_MEMC));
if (!priv(host)->base || !priv(host)->dma) {
ret = -ENOMEM;
goto out_unmap;
}
host->irq = ec->irq;
NCR5380_init(host, 0);
priv(host)->ctrl = 0;
writeb(0, priv(host)->base + CTRL);
host->n_io_port = 255;
if (!(request_region(host->io_port, host->n_io_port, "CumanaSCSI-1"))) {
ret = -EBUSY;
goto out_unmap;
}
ret = request_irq(host->irq, cumanascsi_intr, IRQF_DISABLED,
"CumanaSCSI-1", host);
if (ret) {
printk("scsi%d: IRQ%d not free: %d\n",
host->host_no, host->irq, ret);
goto out_unmap;
}
printk("scsi%d: at port 0x%08lx irq %d",
host->host_no, host->io_port, host->irq);
printk(" options CAN_QUEUE=%d CMD_PER_LUN=%d release=%d",
host->can_queue, host->cmd_per_lun, CUMANASCSI_PUBLIC_RELEASE);
printk("\nscsi%d:", host->host_no);
NCR5380_print_options(host);
printk("\n");
ret = scsi_add_host(host, &ec->dev);
if (ret)
goto out_free_irq;
scsi_scan_host(host);
goto out;
out_free_irq:
free_irq(host->irq, host);
out_unmap:
iounmap(priv(host)->base);
iounmap(priv(host)->dma);
scsi_host_put(host);
out_release:
ecard_release_resources(ec);
out:
return ret;
}
static void __devexit cumanascsi1_remove(struct expansion_card *ec)
{
struct Scsi_Host *host = ecard_get_drvdata(ec);
ecard_set_drvdata(ec, NULL);
scsi_remove_host(host);
free_irq(host->irq, host);
NCR5380_exit(host);
iounmap(priv(host)->base);
iounmap(priv(host)->dma);
scsi_host_put(host);
ecard_release_resources(ec);
}
static int __init cumanascsi_init(void)
{
return ecard_register_driver(&cumanascsi1_driver);
}
static void __exit cumanascsi_exit(void)
{
ecard_remove_driver(&cumanascsi1_driver);
}
