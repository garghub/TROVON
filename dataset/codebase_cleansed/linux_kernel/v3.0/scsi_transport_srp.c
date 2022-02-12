static int srp_host_setup(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct srp_host_attrs *srp_host = to_srp_host_attrs(shost);
atomic_set(&srp_host->next_port_id, 0);
return 0;
}
static ssize_t
show_srp_rport_id(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
return sprintf(buf, SRP_PID_FMT "\n", SRP_PID(rport));
}
static ssize_t
show_srp_rport_roles(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(srp_rport_role_names); i++)
if (srp_rport_role_names[i].value == rport->roles) {
name = srp_rport_role_names[i].name;
break;
}
return sprintf(buf, "%s\n", name ? : "unknown");
}
static void srp_rport_release(struct device *dev)
{
struct srp_rport *rport = dev_to_rport(dev);
put_device(dev->parent);
kfree(rport);
}
static int scsi_is_srp_rport(const struct device *dev)
{
return dev->release == srp_rport_release;
}
static int srp_rport_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct srp_internal *i;
if (!scsi_is_srp_rport(dev))
return 0;
shost = dev_to_shost(dev->parent);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class != &srp_host_class.class)
return 0;
i = to_srp_internal(shost->transportt);
return &i->rport_attr_cont.ac == cont;
}
static int srp_host_match(struct attribute_container *cont, struct device *dev)
{
struct Scsi_Host *shost;
struct srp_internal *i;
if (!scsi_is_host_device(dev))
return 0;
shost = dev_to_shost(dev);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class != &srp_host_class.class)
return 0;
i = to_srp_internal(shost->transportt);
return &i->t.host_attrs.ac == cont;
}
struct srp_rport *srp_rport_add(struct Scsi_Host *shost,
struct srp_rport_identifiers *ids)
{
struct srp_rport *rport;
struct device *parent = &shost->shost_gendev;
int id, ret;
rport = kzalloc(sizeof(*rport), GFP_KERNEL);
if (!rport)
return ERR_PTR(-ENOMEM);
device_initialize(&rport->dev);
rport->dev.parent = get_device(parent);
rport->dev.release = srp_rport_release;
memcpy(rport->port_id, ids->port_id, sizeof(rport->port_id));
rport->roles = ids->roles;
id = atomic_inc_return(&to_srp_host_attrs(shost)->next_port_id);
dev_set_name(&rport->dev, "port-%d:%d", shost->host_no, id);
transport_setup_device(&rport->dev);
ret = device_add(&rport->dev);
if (ret) {
transport_destroy_device(&rport->dev);
put_device(&rport->dev);
return ERR_PTR(ret);
}
if (shost->active_mode & MODE_TARGET &&
ids->roles == SRP_RPORT_ROLE_INITIATOR) {
ret = srp_tgt_it_nexus_create(shost, (unsigned long)rport,
rport->port_id);
if (ret) {
device_del(&rport->dev);
transport_destroy_device(&rport->dev);
put_device(&rport->dev);
return ERR_PTR(ret);
}
}
transport_add_device(&rport->dev);
transport_configure_device(&rport->dev);
return rport;
}
void srp_rport_del(struct srp_rport *rport)
{
struct device *dev = &rport->dev;
struct Scsi_Host *shost = dev_to_shost(dev->parent);
if (shost->active_mode & MODE_TARGET &&
rport->roles == SRP_RPORT_ROLE_INITIATOR)
srp_tgt_it_nexus_destroy(shost, (unsigned long)rport);
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(dev);
}
static int do_srp_rport_del(struct device *dev, void *data)
{
if (scsi_is_srp_rport(dev))
srp_rport_del(dev_to_rport(dev));
return 0;
}
void srp_remove_host(struct Scsi_Host *shost)
{
device_for_each_child(&shost->shost_gendev, NULL, do_srp_rport_del);
}
static int srp_tsk_mgmt_response(struct Scsi_Host *shost, u64 nexus, u64 tm_id,
int result)
{
struct srp_internal *i = to_srp_internal(shost->transportt);
return i->f->tsk_mgmt_response(shost, nexus, tm_id, result);
}
static int srp_it_nexus_response(struct Scsi_Host *shost, u64 nexus, int result)
{
struct srp_internal *i = to_srp_internal(shost->transportt);
return i->f->it_nexus_response(shost, nexus, result);
}
struct scsi_transport_template *
srp_attach_transport(struct srp_function_template *ft)
{
int count;
struct srp_internal *i;
i = kzalloc(sizeof(*i), GFP_KERNEL);
if (!i)
return NULL;
i->t.tsk_mgmt_response = srp_tsk_mgmt_response;
i->t.it_nexus_response = srp_it_nexus_response;
i->t.host_size = sizeof(struct srp_host_attrs);
i->t.host_attrs.ac.attrs = &i->host_attrs[0];
i->t.host_attrs.ac.class = &srp_host_class.class;
i->t.host_attrs.ac.match = srp_host_match;
i->host_attrs[0] = NULL;
transport_container_register(&i->t.host_attrs);
i->rport_attr_cont.ac.attrs = &i->rport_attrs[0];
i->rport_attr_cont.ac.class = &srp_rport_class.class;
i->rport_attr_cont.ac.match = srp_rport_match;
transport_container_register(&i->rport_attr_cont);
count = 0;
SETUP_RPORT_ATTRIBUTE_RD(port_id);
SETUP_RPORT_ATTRIBUTE_RD(roles);
i->rport_attrs[count] = NULL;
i->f = ft;
return &i->t;
}
void srp_release_transport(struct scsi_transport_template *t)
{
struct srp_internal *i = to_srp_internal(t);
transport_container_unregister(&i->t.host_attrs);
transport_container_unregister(&i->rport_attr_cont);
kfree(i);
}
static __init int srp_transport_init(void)
{
int ret;
ret = transport_class_register(&srp_host_class);
if (ret)
return ret;
ret = transport_class_register(&srp_rport_class);
if (ret)
goto unregister_host_class;
return 0;
unregister_host_class:
transport_class_unregister(&srp_host_class);
return ret;
}
static void __exit srp_transport_exit(void)
{
transport_class_unregister(&srp_host_class);
transport_class_unregister(&srp_rport_class);
}
