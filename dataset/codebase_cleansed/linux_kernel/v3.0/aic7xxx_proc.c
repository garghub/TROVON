static void
proc_debug(const char *fmt, ...)
{
va_list ap;
char buf[256];
va_start(ap, fmt);
vsprintf(buf, fmt, ap);
printk(buf);
va_end(ap);
}
static int
aic7xxx_set_info(char *buffer, int length, struct Scsi_Host *HBAptr)
{
proc_debug("aic7xxx_set_info(): %s\n", buffer);
return (-ENOSYS);
}
int
aic7xxx_proc_info ( struct Scsi_Host *HBAptr, char *buffer, char **start, off_t offset, int length,
int inout)
{
struct aic7xxx_host *p;
struct aic_dev_data *aic_dev;
struct scsi_device *sdptr;
int size = 0;
unsigned char i;
unsigned char tindex;
for(p=first_aic7xxx; p && p->host != HBAptr; p=p->next)
;
if (!p)
{
size += sprintf(buffer, "Can't find adapter for host number %d\n", HBAptr->host_no);
if (size > length)
{
return (size);
}
else
{
return (length);
}
}
if (inout == TRUE)
{
return (aic7xxx_set_info(buffer, length, HBAptr));
}
p = (struct aic7xxx_host *) HBAptr->hostdata;
size = 4096;
list_for_each_entry(aic_dev, &p->aic_devs, list)
size += 512;
if (aic7xxx_buffer_size != size)
{
if (aic7xxx_buffer != NULL)
{
kfree(aic7xxx_buffer);
aic7xxx_buffer_size = 0;
}
aic7xxx_buffer = kmalloc(size, GFP_KERNEL);
}
if (aic7xxx_buffer == NULL)
{
size = sprintf(buffer, "AIC7xxx - kmalloc error at line %d\n",
__LINE__);
return size;
}
aic7xxx_buffer_size = size;
size = 0;
size += sprintf(BLS, "Adaptec AIC7xxx driver version: ");
size += sprintf(BLS, "%s/", AIC7XXX_C_VERSION);
size += sprintf(BLS, "%s", AIC7XXX_H_VERSION);
size += sprintf(BLS, "\n");
size += sprintf(BLS, "Adapter Configuration:\n");
size += sprintf(BLS, " SCSI Adapter: %s\n",
board_names[p->board_name_index]);
if (p->flags & AHC_TWIN)
size += sprintf(BLS, " Twin Channel Controller ");
else
{
char *channel = "";
char *ultra = "";
char *wide = "Narrow ";
if (p->flags & AHC_MULTI_CHANNEL)
{
channel = " Channel A";
if (p->flags & (AHC_CHNLB|AHC_CHNLC))
channel = (p->flags & AHC_CHNLB) ? " Channel B" : " Channel C";
}
if (p->features & AHC_WIDE)
wide = "Wide ";
if (p->features & AHC_ULTRA3)
{
switch(p->chip & AHC_CHIPID_MASK)
{
case AHC_AIC7892:
case AHC_AIC7899:
ultra = "Ultra-160/m LVD/SE ";
break;
default:
ultra = "Ultra-3 LVD/SE ";
break;
}
}
else if (p->features & AHC_ULTRA2)
ultra = "Ultra-2 LVD/SE ";
else if (p->features & AHC_ULTRA)
ultra = "Ultra ";
size += sprintf(BLS, " %s%sController%s ",
ultra, wide, channel);
}
switch(p->chip & ~AHC_CHIPID_MASK)
{
case AHC_VL:
size += sprintf(BLS, "at VLB slot %d\n", p->pci_device_fn);
break;
case AHC_EISA:
size += sprintf(BLS, "at EISA slot %d\n", p->pci_device_fn);
break;
default:
size += sprintf(BLS, "at PCI %d/%d/%d\n", p->pci_bus,
PCI_SLOT(p->pci_device_fn), PCI_FUNC(p->pci_device_fn));
break;
}
if( !(p->maddr) )
{
size += sprintf(BLS, " Programmed I/O Base: %lx\n", p->base);
}
else
{
size += sprintf(BLS, " PCI MMAPed I/O Base: 0x%lx\n", p->mbase);
}
if( (p->chip & (AHC_VL | AHC_EISA)) )
{
size += sprintf(BLS, " BIOS Memory Address: 0x%08x\n", p->bios_address);
}
size += sprintf(BLS, " Adapter SEEPROM Config: %s\n",
(p->flags & AHC_SEEPROM_FOUND) ? "SEEPROM found and used." :
((p->flags & AHC_USEDEFAULTS) ? "SEEPROM not found, using defaults." :
"SEEPROM not found, using leftover BIOS values.") );
size += sprintf(BLS, " Adaptec SCSI BIOS: %s\n",
(p->flags & AHC_BIOS_ENABLED) ? "Enabled" : "Disabled");
size += sprintf(BLS, " IRQ: %d\n", HBAptr->irq);
size += sprintf(BLS, " SCBs: Active %d, Max Active %d,\n",
p->activescbs, p->max_activescbs);
size += sprintf(BLS, " Allocated %d, HW %d, "
"Page %d\n", p->scb_data->numscbs, p->scb_data->maxhscbs,
p->scb_data->maxscbs);
if (p->flags & AHC_EXTERNAL_SRAM)
size += sprintf(BLS, " Using External SCB SRAM\n");
size += sprintf(BLS, " Interrupts: %ld", p->isr_count);
if (p->chip & AHC_EISA)
{
size += sprintf(BLS, " %s\n",
(p->pause & IRQMS) ? "(Level Sensitive)" : "(Edge Triggered)");
}
else
{
size += sprintf(BLS, "\n");
}
size += sprintf(BLS, " BIOS Control Word: 0x%04x\n",
p->bios_control);
size += sprintf(BLS, " Adapter Control Word: 0x%04x\n",
p->adapter_control);
size += sprintf(BLS, " Extended Translation: %sabled\n",
(p->flags & AHC_EXTEND_TRANS_A) ? "En" : "Dis");
size += sprintf(BLS, "Disconnect Enable Flags: 0x%04x\n", p->discenable);
if (p->features & (AHC_ULTRA | AHC_ULTRA2))
{
size += sprintf(BLS, " Ultra Enable Flags: 0x%04x\n", p->ultraenb);
}
size += sprintf(BLS, "Default Tag Queue Depth: %d\n", aic7xxx_default_queue_depth);
size += sprintf(BLS, " Tagged Queue By Device array for aic7xxx host "
"instance %d:\n", p->instance);
size += sprintf(BLS, " {");
for(i=0; i < (MAX_TARGETS - 1); i++)
size += sprintf(BLS, "%d,",aic7xxx_tag_info[p->instance].tag_commands[i]);
size += sprintf(BLS, "%d}\n",aic7xxx_tag_info[p->instance].tag_commands[i]);
size += sprintf(BLS, "\n");
size += sprintf(BLS, "Statistics:\n\n");
list_for_each_entry(aic_dev, &p->aic_devs, list)
{
sdptr = aic_dev->SDptr;
tindex = sdptr->channel << 3 | sdptr->id;
size += sprintf(BLS, "(scsi%d:%d:%d:%d)\n",
p->host_no, sdptr->channel, sdptr->id, sdptr->lun);
size += sprintf(BLS, " Device using %s/%s",
(aic_dev->cur.width == MSG_EXT_WDTR_BUS_16_BIT) ?
"Wide" : "Narrow",
(aic_dev->cur.offset != 0) ?
"Sync transfers at " : "Async transfers.\n" );
if (aic_dev->cur.offset != 0)
{
struct aic7xxx_syncrate *sync_rate;
unsigned char options = aic_dev->cur.options;
int period = aic_dev->cur.period;
int rate = (aic_dev->cur.width ==
MSG_EXT_WDTR_BUS_16_BIT) ? 1 : 0;
sync_rate = aic7xxx_find_syncrate(p, &period, 0, &options);
if (sync_rate != NULL)
{
size += sprintf(BLS, "%s MByte/sec, offset %d\n",
sync_rate->rate[rate],
aic_dev->cur.offset );
}
else
{
size += sprintf(BLS, "3.3 MByte/sec, offset %d\n",
aic_dev->cur.offset );
}
}
size += sprintf(BLS, " Transinfo settings: ");
size += sprintf(BLS, "current(%d/%d/%d/%d), ",
aic_dev->cur.period,
aic_dev->cur.offset,
aic_dev->cur.width,
aic_dev->cur.options);
size += sprintf(BLS, "goal(%d/%d/%d/%d), ",
aic_dev->goal.period,
aic_dev->goal.offset,
aic_dev->goal.width,
aic_dev->goal.options);
size += sprintf(BLS, "user(%d/%d/%d/%d)\n",
p->user[tindex].period,
p->user[tindex].offset,
p->user[tindex].width,
p->user[tindex].options);
if(sdptr->simple_tags)
{
size += sprintf(BLS, " Tagged Command Queueing Enabled, Ordered Tags %s, Depth %d/%d\n", sdptr->ordered_tags ? "Enabled" : "Disabled", sdptr->queue_depth, aic_dev->max_q_depth);
}
if(aic_dev->barrier_total)
size += sprintf(BLS, " Total transfers %ld:\n (%ld/%ld/%ld/%ld reads/writes/REQ_BARRIER/Ordered Tags)\n",
aic_dev->r_total+aic_dev->w_total, aic_dev->r_total, aic_dev->w_total,
aic_dev->barrier_total, aic_dev->ordered_total);
else
size += sprintf(BLS, " Total transfers %ld:\n (%ld/%ld reads/writes)\n",
aic_dev->r_total+aic_dev->w_total, aic_dev->r_total, aic_dev->w_total);
size += sprintf(BLS, "%s\n", HDRB);
size += sprintf(BLS, " Reads:");
for (i = 0; i < ARRAY_SIZE(aic_dev->r_bins); i++)
{
size += sprintf(BLS, " %10ld", aic_dev->r_bins[i]);
}
size += sprintf(BLS, "\n");
size += sprintf(BLS, " Writes:");
for (i = 0; i < ARRAY_SIZE(aic_dev->w_bins); i++)
{
size += sprintf(BLS, " %10ld", aic_dev->w_bins[i]);
}
size += sprintf(BLS, "\n");
size += sprintf(BLS, "\n\n");
}
if (size >= aic7xxx_buffer_size)
{
printk(KERN_WARNING "aic7xxx: Overflow in aic7xxx_proc.c\n");
}
if (offset > size - 1)
{
kfree(aic7xxx_buffer);
aic7xxx_buffer = NULL;
aic7xxx_buffer_size = length = 0;
*start = NULL;
}
else
{
*start = buffer;
length = min_t(int, length, size - offset);
memcpy(buffer, &aic7xxx_buffer[offset], length);
}
return (length);
}
