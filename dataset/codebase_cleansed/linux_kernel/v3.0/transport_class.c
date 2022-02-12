int transport_class_register(struct transport_class *tclass)
{
return class_register(&tclass->class);
}
void transport_class_unregister(struct transport_class *tclass)
{
class_unregister(&tclass->class);
}
static int anon_transport_dummy_function(struct transport_container *tc,
struct device *dev,
struct device *cdev)
{
return 0;
}
int anon_transport_class_register(struct anon_transport_class *atc)
{
int error;
atc->container.class = &atc->tclass.class;
attribute_container_set_no_classdevs(&atc->container);
error = attribute_container_register(&atc->container);
if (error)
return error;
atc->tclass.setup = anon_transport_dummy_function;
atc->tclass.remove = anon_transport_dummy_function;
return 0;
}
void anon_transport_class_unregister(struct anon_transport_class *atc)
{
if (unlikely(attribute_container_unregister(&atc->container)))
BUG();
}
static int transport_setup_classdev(struct attribute_container *cont,
struct device *dev,
struct device *classdev)
{
struct transport_class *tclass = class_to_transport_class(cont->class);
struct transport_container *tcont = attribute_container_to_transport_container(cont);
if (tclass->setup)
tclass->setup(tcont, dev, classdev);
return 0;
}
void transport_setup_device(struct device *dev)
{
attribute_container_add_device(dev, transport_setup_classdev);
}
static int transport_add_class_device(struct attribute_container *cont,
struct device *dev,
struct device *classdev)
{
int error = attribute_container_add_class_device(classdev);
struct transport_container *tcont =
attribute_container_to_transport_container(cont);
if (!error && tcont->statistics)
error = sysfs_create_group(&classdev->kobj, tcont->statistics);
return error;
}
void transport_add_device(struct device *dev)
{
attribute_container_device_trigger(dev, transport_add_class_device);
}
static int transport_configure(struct attribute_container *cont,
struct device *dev,
struct device *cdev)
{
struct transport_class *tclass = class_to_transport_class(cont->class);
struct transport_container *tcont = attribute_container_to_transport_container(cont);
if (tclass->configure)
tclass->configure(tcont, dev, cdev);
return 0;
}
void transport_configure_device(struct device *dev)
{
attribute_container_device_trigger(dev, transport_configure);
}
static int transport_remove_classdev(struct attribute_container *cont,
struct device *dev,
struct device *classdev)
{
struct transport_container *tcont =
attribute_container_to_transport_container(cont);
struct transport_class *tclass = class_to_transport_class(cont->class);
if (tclass->remove)
tclass->remove(tcont, dev, classdev);
if (tclass->remove != anon_transport_dummy_function) {
if (tcont->statistics)
sysfs_remove_group(&classdev->kobj, tcont->statistics);
attribute_container_class_device_del(classdev);
}
return 0;
}
void transport_remove_device(struct device *dev)
{
attribute_container_device_trigger(dev, transport_remove_classdev);
}
static void transport_destroy_classdev(struct attribute_container *cont,
struct device *dev,
struct device *classdev)
{
struct transport_class *tclass = class_to_transport_class(cont->class);
if (tclass->remove != anon_transport_dummy_function)
put_device(classdev);
}
void transport_destroy_device(struct device *dev)
{
attribute_container_remove_device(dev, transport_destroy_classdev);
}
