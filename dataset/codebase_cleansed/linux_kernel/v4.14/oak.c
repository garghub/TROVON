static inline int oakscsi_pwrite(struct NCR5380_hostdata *hostdata,
unsigned char *addr, int len)
{
u8 __iomem *base = hostdata->io;
printk("writing %p len %d\n",addr, len);
while(1)
{
int status;
while (((status = readw(base + STAT)) & 0x100)==0);
}
return 0;
}
static inline int oakscsi_pread(struct NCR5380_hostdata *hostdata,
unsigned char *addr, int len)
{
u8 __iomem *base = hostdata->io;
printk("reading %p len %d\n", addr, len);
while(len > 0)
{
unsigned int status, timeout;
unsigned long b;
timeout = 0x01FFFFFF;
while (((status = readw(base + STAT)) & 0x100)==0)
{
timeout--;
if(status & 0x200 || !timeout)
{
printk("status = %08X\n", status);
return -1;
}
}
if(len >= 128)
{
readsw(base + DATA, addr, 128);
addr += 128;
len -= 128;
}
else
{
b = (unsigned long) readw(base + DATA);
*addr ++ = b;
len -= 1;
if(len)
*addr ++ = b>>8;
len -= 1;
}
}
return 0;
}
static int oakscsi_probe(struct expansion_card *ec, const struct ecard_id *id)
{
struct Scsi_Host *host;
int ret = -ENOMEM;
ret = ecard_request_resources(ec);
if (ret)
goto out;
host = scsi_host_alloc(&oakscsi_template, sizeof(struct NCR5380_hostdata));
if (!host) {
ret = -ENOMEM;
goto release;
}
priv(host)->io = ioremap(ecard_resource_start(ec, ECARD_RES_MEMC),
ecard_resource_len(ec, ECARD_RES_MEMC));
if (!priv(host)->io) {
ret = -ENOMEM;
goto unreg;
}
host->irq = NO_IRQ;
ret = NCR5380_init(host, FLAG_DMA_FIXUP | FLAG_LATE_DMA_SETUP);
if (ret)
goto out_unmap;
NCR5380_maybe_reset_bus(host);
ret = scsi_add_host(host, &ec->dev);
if (ret)
goto out_exit;
scsi_scan_host(host);
goto out;
out_exit:
NCR5380_exit(host);
out_unmap:
iounmap(priv(host)->io);
unreg:
scsi_host_put(host);
release:
ecard_release_resources(ec);
out:
return ret;
}
static void oakscsi_remove(struct expansion_card *ec)
{
struct Scsi_Host *host = ecard_get_drvdata(ec);
void __iomem *base = priv(host)->io;
ecard_set_drvdata(ec, NULL);
scsi_remove_host(host);
NCR5380_exit(host);
scsi_host_put(host);
iounmap(base);
ecard_release_resources(ec);
}
static int __init oakscsi_init(void)
{
return ecard_register_driver(&oakscsi_driver);
}
static void __exit oakscsi_exit(void)
{
ecard_remove_driver(&oakscsi_driver);
}
