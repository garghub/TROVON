static int raid_match(struct attribute_container *cont, struct device *dev)
{
struct raid_internal *i = ac_to_raid_internal(cont);
#if defined(CONFIG_SCSI) || defined(CONFIG_SCSI_MODULE)
if (scsi_is_sdev_device(dev)) {
struct scsi_device *sdev = to_scsi_device(dev);
if (i->f->cookie != sdev->host->hostt)
return 0;
return i->f->is_raid(dev);
}
#endif
return 0;
}
static int raid_setup(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct raid_data *rd;
BUG_ON(dev_get_drvdata(cdev));
rd = kzalloc(sizeof(*rd), GFP_KERNEL);
if (!rd)
return -ENOMEM;
INIT_LIST_HEAD(&rd->component_list);
dev_set_drvdata(cdev, rd);
return 0;
}
static int raid_remove(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct raid_data *rd = dev_get_drvdata(cdev);
struct raid_component *rc, *next;
dev_printk(KERN_ERR, dev, "RAID REMOVE\n");
dev_set_drvdata(cdev, NULL);
list_for_each_entry_safe(rc, next, &rd->component_list, node) {
list_del(&rc->node);
dev_printk(KERN_ERR, rc->dev.parent, "RAID COMPONENT REMOVE\n");
device_unregister(&rc->dev);
}
dev_printk(KERN_ERR, dev, "RAID REMOVE DONE\n");
kfree(rd);
return 0;
}
static const char *raid_state_name(enum raid_state state)
{
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(raid_states); i++) {
if (raid_states[i].value == state) {
name = raid_states[i].name;
break;
}
}
return name;
}
static const char *raid_level_name(enum raid_level level)
{
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(raid_levels); i++) {
if (raid_levels[i].value == level) {
name = raid_levels[i].name;
break;
}
}
return name;
}
static void raid_component_release(struct device *dev)
{
struct raid_component *rc =
container_of(dev, struct raid_component, dev);
dev_printk(KERN_ERR, rc->dev.parent, "COMPONENT RELEASE\n");
put_device(rc->dev.parent);
kfree(rc);
}
int raid_component_add(struct raid_template *r,struct device *raid_dev,
struct device *component_dev)
{
struct device *cdev =
attribute_container_find_class_device(&r->raid_attrs.ac,
raid_dev);
struct raid_component *rc;
struct raid_data *rd = dev_get_drvdata(cdev);
int err;
rc = kzalloc(sizeof(*rc), GFP_KERNEL);
if (!rc)
return -ENOMEM;
INIT_LIST_HEAD(&rc->node);
device_initialize(&rc->dev);
rc->dev.release = raid_component_release;
rc->dev.parent = get_device(component_dev);
rc->num = rd->component_count++;
dev_set_name(&rc->dev, "component-%d", rc->num);
list_add_tail(&rc->node, &rd->component_list);
rc->dev.class = &raid_class.class;
err = device_add(&rc->dev);
if (err)
goto err_out;
return 0;
err_out:
list_del(&rc->node);
rd->component_count--;
put_device(component_dev);
kfree(rc);
return err;
}
struct raid_template *
raid_class_attach(struct raid_function_template *ft)
{
struct raid_internal *i = kzalloc(sizeof(struct raid_internal),
GFP_KERNEL);
int count = 0;
if (unlikely(!i))
return NULL;
i->f = ft;
i->r.raid_attrs.ac.class = &raid_class.class;
i->r.raid_attrs.ac.match = raid_match;
i->r.raid_attrs.ac.attrs = &i->attrs[0];
attribute_container_register(&i->r.raid_attrs.ac);
i->attrs[count++] = &dev_attr_level;
i->attrs[count++] = &dev_attr_resync;
i->attrs[count++] = &dev_attr_state;
i->attrs[count] = NULL;
BUG_ON(count > RAID_NUM_ATTRS);
return &i->r;
}
void
raid_class_release(struct raid_template *r)
{
struct raid_internal *i = to_raid_internal(r);
BUG_ON(attribute_container_unregister(&i->r.raid_attrs.ac));
kfree(i);
}
static __init int raid_init(void)
{
return transport_class_register(&raid_class);
}
static __exit void raid_exit(void)
{
transport_class_unregister(&raid_class);
}
