static inline int NCR5380_pwrite(struct Scsi_Host *instance, unsigned char *addr,
int len)
{
void __iomem *base = priv(instance)->base;
printk("writing %p len %d\n",addr, len);
if(!len) return -1;
while(1)
{
int status;
while (((status = readw(base + STAT)) & 0x100)==0);
}
}
static inline int NCR5380_pread(struct Scsi_Host *instance, unsigned char *addr,
int len)
{
void __iomem *base = priv(instance)->base;
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
return 1;
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
priv(host)->base = ioremap(ecard_resource_start(ec, ECARD_RES_MEMC),
ecard_resource_len(ec, ECARD_RES_MEMC));
if (!priv(host)->base) {
ret = -ENOMEM;
goto unreg;
}
host->irq = NO_IRQ;
host->n_io_port = 255;
NCR5380_init(host, 0);
ret = scsi_add_host(host, &ec->dev);
if (ret)
goto out_unmap;
scsi_scan_host(host);
goto out;
out_unmap:
iounmap(priv(host)->base);
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
ecard_set_drvdata(ec, NULL);
scsi_remove_host(host);
NCR5380_exit(host);
iounmap(priv(host)->base);
scsi_host_put(host);
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
