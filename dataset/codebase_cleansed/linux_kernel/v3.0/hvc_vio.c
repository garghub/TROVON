static int filtered_get_chars(uint32_t vtermno, char *buf, int count)
{
unsigned long got;
int i;
if (count < SIZE_VIO_GET_CHARS)
return -EAGAIN;
got = hvc_get_chars(vtermno, buf, count);
for (i = 1; i < got; ++i) {
if (buf[i] == 0 && buf[i-1] == '\r') {
--got;
if (i < got)
memmove(&buf[i], &buf[i+1],
got - i);
}
}
return got;
}
static int __devinit hvc_vio_probe(struct vio_dev *vdev,
const struct vio_device_id *id)
{
struct hvc_struct *hp;
if (!vdev || !id)
return -EPERM;
hp = hvc_alloc(vdev->unit_address, vdev->irq, &hvc_get_put_ops,
MAX_VIO_PUT_CHARS);
if (IS_ERR(hp))
return PTR_ERR(hp);
dev_set_drvdata(&vdev->dev, hp);
return 0;
}
static int __devexit hvc_vio_remove(struct vio_dev *vdev)
{
struct hvc_struct *hp = dev_get_drvdata(&vdev->dev);
return hvc_remove(hp);
}
static int __init hvc_vio_init(void)
{
int rc;
if (firmware_has_feature(FW_FEATURE_ISERIES))
return -EIO;
rc = vio_register_driver(&hvc_vio_driver);
return rc;
}
static void __exit hvc_vio_exit(void)
{
vio_unregister_driver(&hvc_vio_driver);
}
static int hvc_find_vtys(void)
{
struct device_node *vty;
int num_found = 0;
for (vty = of_find_node_by_name(NULL, "vty"); vty != NULL;
vty = of_find_node_by_name(vty, "vty")) {
const uint32_t *vtermno;
if (num_found >= MAX_NR_HVC_CONSOLES) {
of_node_put(vty);
break;
}
vtermno = of_get_property(vty, "reg", NULL);
if (!vtermno)
continue;
if (of_device_is_compatible(vty, "hvterm1")) {
hvc_instantiate(*vtermno, num_found, &hvc_get_put_ops);
++num_found;
}
}
return num_found;
}
