static void ata_tport_release(struct device *dev)
{
put_device(dev->parent);
}
int ata_is_port(const struct device *dev)
{
return dev->release == ata_tport_release;
}
static int ata_tport_match(struct attribute_container *cont,
struct device *dev)
{
if (!ata_is_port(dev))
return 0;
return &ata_scsi_transport_template->host_attrs.ac == cont;
}
void ata_tport_delete(struct ata_port *ap)
{
struct device *dev = &ap->tdev;
ata_tlink_delete(&ap->link);
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(dev);
}
int ata_tport_add(struct device *parent,
struct ata_port *ap)
{
int error;
struct device *dev = &ap->tdev;
device_initialize(dev);
dev->type = &ata_port_type;
dev->parent = get_device(parent);
dev->release = ata_tport_release;
dev_set_name(dev, "ata%d", ap->print_id);
transport_setup_device(dev);
error = device_add(dev);
if (error) {
goto tport_err;
}
device_enable_async_suspend(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
transport_add_device(dev);
transport_configure_device(dev);
error = ata_tlink_add(&ap->link);
if (error) {
goto tport_link_err;
}
return 0;
tport_link_err:
transport_remove_device(dev);
device_del(dev);
tport_err:
transport_destroy_device(dev);
put_device(dev);
return error;
}
static void ata_tlink_release(struct device *dev)
{
put_device(dev->parent);
}
int ata_is_link(const struct device *dev)
{
return dev->release == ata_tlink_release;
}
static int ata_tlink_match(struct attribute_container *cont,
struct device *dev)
{
struct ata_internal* i = to_ata_internal(ata_scsi_transport_template);
if (!ata_is_link(dev))
return 0;
return &i->link_attr_cont.ac == cont;
}
void ata_tlink_delete(struct ata_link *link)
{
struct device *dev = &link->tdev;
struct ata_device *ata_dev;
ata_for_each_dev(ata_dev, link, ALL) {
ata_tdev_delete(ata_dev);
}
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(dev);
}
int ata_tlink_add(struct ata_link *link)
{
struct device *dev = &link->tdev;
struct ata_port *ap = link->ap;
struct ata_device *ata_dev;
int error;
device_initialize(dev);
dev->parent = get_device(&ap->tdev);
dev->release = ata_tlink_release;
if (ata_is_host_link(link))
dev_set_name(dev, "link%d", ap->print_id);
else
dev_set_name(dev, "link%d.%d", ap->print_id, link->pmp);
transport_setup_device(dev);
error = device_add(dev);
if (error) {
goto tlink_err;
}
transport_add_device(dev);
transport_configure_device(dev);
ata_for_each_dev(ata_dev, link, ALL) {
error = ata_tdev_add(ata_dev);
if (error) {
goto tlink_dev_err;
}
}
return 0;
tlink_dev_err:
while (--ata_dev >= link->device) {
ata_tdev_delete(ata_dev);
}
transport_remove_device(dev);
device_del(dev);
tlink_err:
transport_destroy_device(dev);
put_device(dev);
return error;
}
static int ata_show_ering(struct ata_ering_entry *ent, void *void_arg)
{
struct ata_show_ering_arg* arg = void_arg;
struct timespec time;
jiffies_to_timespec(ent->timestamp,&time);
arg->written += sprintf(arg->buf + arg->written,
"[%5lu.%06lu]",
time.tv_sec, time.tv_nsec);
arg->written += get_ata_err_names(ent->err_mask,
arg->buf + arg->written);
return 0;
}
static ssize_t
show_ata_dev_ering(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ata_device *ata_dev = transport_class_to_dev(dev);
struct ata_show_ering_arg arg = { buf, 0 };
ata_ering_map(&ata_dev->ering, ata_show_ering, &arg);
return arg.written;
}
static ssize_t
show_ata_dev_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ata_device *ata_dev = transport_class_to_dev(dev);
int written = 0, i = 0;
if (ata_dev->class == ATA_DEV_PMP)
return 0;
for(i=0;i<ATA_ID_WORDS;i++) {
written += snprintf(buf+written, 20, "%04x%c",
ata_dev->id[i],
((i+1) & 7) ? ' ' : '\n');
}
return written;
}
static ssize_t
show_ata_dev_gscr(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ata_device *ata_dev = transport_class_to_dev(dev);
int written = 0, i = 0;
if (ata_dev->class != ATA_DEV_PMP)
return 0;
for(i=0;i<SATA_PMP_GSCR_DWORDS;i++) {
written += snprintf(buf+written, 20, "%08x%c",
ata_dev->gscr[i],
((i+1) & 3) ? ' ' : '\n');
}
if (SATA_PMP_GSCR_DWORDS & 3)
buf[written-1] = '\n';
return written;
}
static void ata_tdev_release(struct device *dev)
{
put_device(dev->parent);
}
int ata_is_ata_dev(const struct device *dev)
{
return dev->release == ata_tdev_release;
}
static int ata_tdev_match(struct attribute_container *cont,
struct device *dev)
{
struct ata_internal* i = to_ata_internal(ata_scsi_transport_template);
if (!ata_is_ata_dev(dev))
return 0;
return &i->dev_attr_cont.ac == cont;
}
static void ata_tdev_free(struct ata_device *dev)
{
transport_destroy_device(&dev->tdev);
put_device(&dev->tdev);
}
static void ata_tdev_delete(struct ata_device *ata_dev)
{
struct device *dev = &ata_dev->tdev;
transport_remove_device(dev);
device_del(dev);
ata_tdev_free(ata_dev);
}
static int ata_tdev_add(struct ata_device *ata_dev)
{
struct device *dev = &ata_dev->tdev;
struct ata_link *link = ata_dev->link;
struct ata_port *ap = link->ap;
int error;
device_initialize(dev);
dev->parent = get_device(&link->tdev);
dev->release = ata_tdev_release;
if (ata_is_host_link(link))
dev_set_name(dev, "dev%d.%d", ap->print_id,ata_dev->devno);
else
dev_set_name(dev, "dev%d.%d.0", ap->print_id, link->pmp);
transport_setup_device(dev);
error = device_add(dev);
if (error) {
ata_tdev_free(ata_dev);
return error;
}
transport_add_device(dev);
transport_configure_device(dev);
return 0;
}
struct scsi_transport_template *ata_attach_transport(void)
{
struct ata_internal *i;
int count;
i = kzalloc(sizeof(struct ata_internal), GFP_KERNEL);
if (!i)
return NULL;
i->t.eh_strategy_handler = ata_scsi_error;
i->t.eh_timed_out = ata_scsi_timed_out;
i->t.user_scan = ata_scsi_user_scan;
i->t.host_attrs.ac.attrs = &i->port_attrs[0];
i->t.host_attrs.ac.class = &ata_port_class.class;
i->t.host_attrs.ac.match = ata_tport_match;
transport_container_register(&i->t.host_attrs);
i->link_attr_cont.ac.class = &ata_link_class.class;
i->link_attr_cont.ac.attrs = &i->link_attrs[0];
i->link_attr_cont.ac.match = ata_tlink_match;
transport_container_register(&i->link_attr_cont);
i->dev_attr_cont.ac.class = &ata_dev_class.class;
i->dev_attr_cont.ac.attrs = &i->dev_attrs[0];
i->dev_attr_cont.ac.match = ata_tdev_match;
transport_container_register(&i->dev_attr_cont);
count = 0;
SETUP_PORT_ATTRIBUTE(nr_pmp_links);
SETUP_PORT_ATTRIBUTE(idle_irq);
BUG_ON(count > ATA_PORT_ATTRS);
i->port_attrs[count] = NULL;
count = 0;
SETUP_LINK_ATTRIBUTE(hw_sata_spd_limit);
SETUP_LINK_ATTRIBUTE(sata_spd_limit);
SETUP_LINK_ATTRIBUTE(sata_spd);
BUG_ON(count > ATA_LINK_ATTRS);
i->link_attrs[count] = NULL;
count = 0;
SETUP_DEV_ATTRIBUTE(class);
SETUP_DEV_ATTRIBUTE(pio_mode);
SETUP_DEV_ATTRIBUTE(dma_mode);
SETUP_DEV_ATTRIBUTE(xfer_mode);
SETUP_DEV_ATTRIBUTE(spdn_cnt);
SETUP_DEV_ATTRIBUTE(ering);
SETUP_DEV_ATTRIBUTE(id);
SETUP_DEV_ATTRIBUTE(gscr);
BUG_ON(count > ATA_DEV_ATTRS);
i->dev_attrs[count] = NULL;
return &i->t;
}
void ata_release_transport(struct scsi_transport_template *t)
{
struct ata_internal *i = to_ata_internal(t);
transport_container_unregister(&i->t.host_attrs);
transport_container_unregister(&i->link_attr_cont);
transport_container_unregister(&i->dev_attr_cont);
kfree(i);
}
__init int libata_transport_init(void)
{
int error;
error = transport_class_register(&ata_link_class);
if (error)
goto out_unregister_transport;
error = transport_class_register(&ata_port_class);
if (error)
goto out_unregister_link;
error = transport_class_register(&ata_dev_class);
if (error)
goto out_unregister_port;
return 0;
out_unregister_port:
transport_class_unregister(&ata_port_class);
out_unregister_link:
transport_class_unregister(&ata_link_class);
out_unregister_transport:
return error;
}
void __exit libata_transport_exit(void)
{
transport_class_unregister(&ata_link_class);
transport_class_unregister(&ata_port_class);
transport_class_unregister(&ata_dev_class);
}
