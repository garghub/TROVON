static __init int
param_setup(char *str)
{
char *pos = str, *next;
int slot = -1;
while(pos != NULL && (next = strchr(pos, ':')) != NULL) {
int val = (int)simple_strtoul(++next, NULL, 0);
if(!strncmp(pos, "slot:", 5))
slot = val;
else if(!strncmp(pos, "id:", 3)) {
if(slot == -1) {
printk(KERN_WARNING "sim710: Must specify slot for id parameter\n");
} else if(slot >= MAX_SLOTS) {
printk(KERN_WARNING "sim710: Illegal slot %d for id %d\n", slot, val);
} else {
id_array[slot] = val;
}
}
if((pos = strchr(pos, ARG_SEP)) != NULL)
pos++;
}
return 1;
}
static __devinit int
sim710_probe_common(struct device *dev, unsigned long base_addr,
int irq, int clock, int differential, int scsi_id)
{
struct Scsi_Host * host = NULL;
struct NCR_700_Host_Parameters *hostdata =
kzalloc(sizeof(struct NCR_700_Host_Parameters), GFP_KERNEL);
printk(KERN_NOTICE "sim710: %s\n", dev_name(dev));
printk(KERN_NOTICE "sim710: irq = %d, clock = %d, base = 0x%lx, scsi_id = %d\n",
irq, clock, base_addr, scsi_id);
if(hostdata == NULL) {
printk(KERN_ERR "sim710: Failed to allocate host data\n");
goto out;
}
if(request_region(base_addr, 64, "sim710") == NULL) {
printk(KERN_ERR "sim710: Failed to reserve IO region 0x%lx\n",
base_addr);
goto out_free;
}
hostdata->base = ioport_map(base_addr, 64);
hostdata->differential = differential;
hostdata->clock = clock;
hostdata->chip710 = 1;
hostdata->burst_length = 8;
if((host = NCR_700_detect(&sim710_driver_template, hostdata, dev))
== NULL) {
printk(KERN_ERR "sim710: No host detected; card configuration problem?\n");
goto out_release;
}
host->this_id = scsi_id;
host->base = base_addr;
host->irq = irq;
if (request_irq(irq, NCR_700_intr, IRQF_SHARED, "sim710", host)) {
printk(KERN_ERR "sim710: request_irq failed\n");
goto out_put_host;
}
dev_set_drvdata(dev, host);
scsi_scan_host(host);
return 0;
out_put_host:
scsi_host_put(host);
out_release:
release_region(base_addr, 64);
out_free:
kfree(hostdata);
out:
return -ENODEV;
}
static __devexit int
sim710_device_remove(struct device *dev)
{
struct Scsi_Host *host = dev_get_drvdata(dev);
struct NCR_700_Host_Parameters *hostdata =
(struct NCR_700_Host_Parameters *)host->hostdata[0];
scsi_remove_host(host);
NCR_700_release(host);
kfree(hostdata);
free_irq(host->irq, host);
release_region(host->base, 64);
return 0;
}
static __init int
sim710_mca_probe(struct device *dev)
{
struct mca_device *mca_dev = to_mca_device(dev);
int slot = mca_dev->slot;
int pos[3];
unsigned int base;
int irq_vector;
short id = sim710_mca_id_table[mca_dev->index];
static int io_004f_by_pos[] = MCA_004F_IO_PORTS;
static int irq_004f_by_pos[] = MCA_004F_IRQS;
static int io_01bb_by_pos[] = MCA_01BB_IO_PORTS;
static int irq_01bb_by_pos[] = MCA_01BB_IRQS;
char *name;
int clock;
pos[0] = mca_device_read_stored_pos(mca_dev, 2);
pos[1] = mca_device_read_stored_pos(mca_dev, 3);
pos[2] = mca_device_read_stored_pos(mca_dev, 4);
if (id == 0x01bb || id == 0x01ba) {
base = io_01bb_by_pos[(pos[2] & 0xFC) >> 2];
irq_vector =
irq_01bb_by_pos[((pos[0] & 0xC0) >> 6)];
clock = 50;
if (id == 0x01bb)
name = "NCR 3360/3430 SCSI SubSystem";
else
name = "NCR Dual SIOP SCSI Host Adapter Board";
} else if ( id == 0x004f ) {
base = io_004f_by_pos[((pos[0] & 0x0E) >> 1)];
irq_vector =
irq_004f_by_pos[((pos[0] & 0x70) >> 4) - 4];
clock = 50;
name = "NCR 53c710 SCSI Host Adapter Board";
} else {
return -ENODEV;
}
mca_device_set_name(mca_dev, name);
mca_device_set_claim(mca_dev, 1);
base = mca_device_transform_ioport(mca_dev, base);
irq_vector = mca_device_transform_irq(mca_dev, irq_vector);
return sim710_probe_common(dev, base, irq_vector, clock,
0, id_array[slot]);
}
static __init int
sim710_eisa_probe(struct device *dev)
{
struct eisa_device *edev = to_eisa_device(dev);
unsigned long io_addr = edev->base_addr;
char eisa_cpq_irqs[] = { 11, 14, 15, 10, 9, 0 };
char eisa_hwp_irqs[] = { 3, 4, 5, 7, 12, 10, 11, 0};
char *eisa_irqs;
unsigned char irq_index;
unsigned char irq, differential = 0, scsi_id = 7;
if(strcmp(edev->id.sig, "HWP0C80") == 0) {
__u8 val;
eisa_irqs = eisa_hwp_irqs;
irq_index = (inb(io_addr + 0xc85) & 0x7) - 1;
val = inb(io_addr + 0x4);
scsi_id = ffs(val) - 1;
if(scsi_id > 7 || (val & ~(1<<scsi_id)) != 0) {
printk(KERN_ERR "sim710.c, EISA card %s has incorrect scsi_id, setting to 7\n", dev_name(dev));
scsi_id = 7;
}
} else {
eisa_irqs = eisa_cpq_irqs;
irq_index = inb(io_addr + 0xc88) & 0x07;
}
if(irq_index >= strlen(eisa_irqs)) {
printk("sim710.c: irq nasty\n");
return -ENODEV;
}
irq = eisa_irqs[irq_index];
return sim710_probe_common(dev, io_addr, irq, 50,
differential, scsi_id);
}
static int __init sim710_init(void)
{
int err = -ENODEV;
#ifdef MODULE
if (sim710)
param_setup(sim710);
#endif
#ifdef CONFIG_MCA
err = mca_register_driver(&sim710_mca_driver);
#endif
#ifdef CONFIG_EISA
err = eisa_driver_register(&sim710_eisa_driver);
#endif
return 0;
}
static void __exit sim710_exit(void)
{
#ifdef CONFIG_MCA
if (MCA_bus)
mca_unregister_driver(&sim710_mca_driver);
#endif
#ifdef CONFIG_EISA
eisa_driver_unregister(&sim710_eisa_driver);
#endif
}
