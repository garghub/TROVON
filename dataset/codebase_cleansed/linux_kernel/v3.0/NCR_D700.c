static int __init
param_setup(char *string)
{
char *pos = string, *next;
int slot = -1, siop = -1;
while(pos != NULL && (next = strchr(pos, ':')) != NULL) {
int val = (int)simple_strtoul(++next, NULL, 0);
if(!strncmp(pos, "slot:", 5))
slot = val;
else if(!strncmp(pos, "siop:", 5))
siop = val;
else if(!strncmp(pos, "id:", 3)) {
if(slot == -1) {
printk(KERN_WARNING "NCR D700: Must specify slot for id parameter\n");
} else if(slot > MCA_MAX_SLOT_NR) {
printk(KERN_WARNING "NCR D700: Illegal slot %d for id %d\n", slot, val);
} else {
if(siop != 0 && siop != 1) {
id_array[slot*2] = val;
id_array[slot*2 + 1] =val;
} else {
id_array[slot*2 + siop] = val;
}
}
}
if((pos = strchr(pos, ARG_SEP)) != NULL)
pos++;
}
return 1;
}
static int __devinit
NCR_D700_probe_one(struct NCR_D700_private *p, int siop, int irq,
int slot, u32 region, int differential)
{
struct NCR_700_Host_Parameters *hostdata;
struct Scsi_Host *host;
int ret;
hostdata = kzalloc(sizeof(*hostdata), GFP_KERNEL);
if (!hostdata) {
printk(KERN_ERR "NCR D700: SIOP%d: Failed to allocate host"
"data, detatching\n", siop);
return -ENOMEM;
}
if (!request_region(region, 64, "NCR_D700")) {
printk(KERN_ERR "NCR D700: Failed to reserve IO region 0x%x\n",
region);
ret = -ENODEV;
goto region_failed;
}
hostdata->base = ioport_map(region, 64);
hostdata->differential = (((1<<siop) & differential) != 0);
hostdata->clock = NCR_D700_CLOCK_MHZ;
hostdata->burst_length = 8;
host = NCR_700_detect(&NCR_D700_driver_template, hostdata, p->dev);
if (!host) {
ret = -ENOMEM;
goto detect_failed;
}
p->hosts[siop] = host;
host->this_id = id_array[slot * 2 + siop];
host->irq = irq;
host->base = region;
scsi_scan_host(host);
return 0;
detect_failed:
release_region(region, 64);
region_failed:
kfree(hostdata);
return ret;
}
static irqreturn_t
NCR_D700_intr(int irq, void *data)
{
struct NCR_D700_private *p = (struct NCR_D700_private *)data;
int i, found = 0;
for (i = 0; i < 2; i++)
if (p->hosts[i] &&
NCR_700_intr(irq, p->hosts[i]) == IRQ_HANDLED)
found++;
return found ? IRQ_HANDLED : IRQ_NONE;
}
static int __devinit
NCR_D700_probe(struct device *dev)
{
struct NCR_D700_private *p;
int differential;
static int banner = 1;
struct mca_device *mca_dev = to_mca_device(dev);
int slot = mca_dev->slot;
int found = 0;
int irq, i;
int pos3j, pos3k, pos3a, pos3b, pos4;
__u32 base_addr, offset_addr;
pos4 = mca_device_read_pos(mca_dev, 4);
pos4 |= 0x4;
mca_device_write_pos(mca_dev, 4, pos4);
mca_device_write_pos(mca_dev, 6, 9);
pos3j = mca_device_read_pos(mca_dev, 3);
mca_device_write_pos(mca_dev, 6, 10);
pos3k = mca_device_read_pos(mca_dev, 3);
mca_device_write_pos(mca_dev, 6, 0);
pos3a = mca_device_read_pos(mca_dev, 3);
mca_device_write_pos(mca_dev, 6, 1);
pos3b = mca_device_read_pos(mca_dev, 3);
base_addr = ((pos3j << 8) | pos3k) & 0xfffffff0;
offset_addr = ((pos3a << 8) | pos3b) & 0xffffff70;
irq = (pos4 & 0x3) + 11;
if(irq >= 13)
irq++;
if(banner) {
printk(KERN_NOTICE "NCR D700: Driver Version " NCR_D700_VERSION "\n"
"NCR D700: Copyright (c) 2001 by James.Bottomley@HansenPartnership.com\n"
"NCR D700:\n");
banner = 0;
}
irq = mca_device_transform_irq(mca_dev, irq);
base_addr = mca_device_transform_ioport(mca_dev, base_addr);
offset_addr = mca_device_transform_ioport(mca_dev, offset_addr);
printk(KERN_NOTICE "NCR D700: found in slot %d irq = %d I/O base = 0x%x\n", slot, irq, offset_addr);
(void)inb(base_addr + 0x08);
switch(differential = (inb(base_addr + 0x08) >> 6)) {
case 0x00:
differential = 0x02;
break;
case 0x01:
differential = 0x03;
break;
case 0x03:
differential = 0x00;
break;
default:
printk(KERN_ERR "D700: UNEXPECTED DIFFERENTIAL RESULT 0x%02x\n",
differential);
differential = 0x00;
break;
}
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
p->dev = dev;
snprintf(p->name, sizeof(p->name), "D700(%s)", dev_name(dev));
if (request_irq(irq, NCR_D700_intr, IRQF_SHARED, p->name, p)) {
printk(KERN_ERR "D700: request_irq failed\n");
kfree(p);
return -EBUSY;
}
for (i = 0; i < 2; i++) {
int err;
if ((err = NCR_D700_probe_one(p, i, irq, slot,
offset_addr + (0x80 * i),
differential)) != 0)
printk("D700: SIOP%d: probe failed, error = %d\n",
i, err);
else
found++;
}
if (!found) {
kfree(p);
return -ENODEV;
}
mca_device_set_claim(mca_dev, 1);
mca_device_set_name(mca_dev, "NCR_D700");
dev_set_drvdata(dev, p);
return 0;
}
static void __devexit
NCR_D700_remove_one(struct Scsi_Host *host)
{
scsi_remove_host(host);
NCR_700_release(host);
kfree((struct NCR_700_Host_Parameters *)host->hostdata[0]);
free_irq(host->irq, host);
release_region(host->base, 64);
}
static int __devexit
NCR_D700_remove(struct device *dev)
{
struct NCR_D700_private *p = dev_get_drvdata(dev);
int i;
for (i = 0; i < 2; i++)
NCR_D700_remove_one(p->hosts[i]);
kfree(p);
return 0;
}
static int __init NCR_D700_init(void)
{
#ifdef MODULE
if (NCR_D700)
param_setup(NCR_D700);
#endif
return mca_register_driver(&NCR_D700_driver);
}
static void __exit NCR_D700_exit(void)
{
mca_unregister_driver(&NCR_D700_driver);
}
