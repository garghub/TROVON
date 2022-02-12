static inline struct maxiradio *to_maxiradio(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct maxiradio, v4l2_dev);
}
static void maxiradio_tea575x_set_pins(struct snd_tea575x *tea, u8 pins)
{
struct maxiradio *dev = tea->private_data;
u8 bits = 0;
bits |= (pins & TEA575X_DATA) ? data : 0;
bits |= (pins & TEA575X_CLK) ? clk : 0;
bits |= (pins & TEA575X_WREN) ? wren : 0;
bits |= power;
outb(bits, dev->io);
}
static u8 maxiradio_tea575x_get_pins(struct snd_tea575x *tea)
{
struct maxiradio *dev = tea->private_data;
u8 bits = inb(dev->io);
return ((bits & data) ? TEA575X_DATA : 0) |
((bits & mo_st) ? TEA575X_MOST : 0);
}
static void maxiradio_tea575x_set_direction(struct snd_tea575x *tea, bool output)
{
}
static int __devinit maxiradio_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct maxiradio *dev;
struct v4l2_device *v4l2_dev;
int retval = -ENOMEM;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&pdev->dev, "not enough memory\n");
return -ENOMEM;
}
v4l2_dev = &dev->v4l2_dev;
v4l2_device_set_name(v4l2_dev, "maxiradio", &maxiradio_instance);
retval = v4l2_device_register(&pdev->dev, v4l2_dev);
if (retval < 0) {
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
goto errfr;
}
dev->tea.private_data = dev;
dev->tea.ops = &maxiradio_tea_ops;
dev->tea.cannot_read_data = true;
dev->tea.v4l2_dev = v4l2_dev;
dev->tea.radio_nr = radio_nr;
strlcpy(dev->tea.card, "Maxi Radio FM2000", sizeof(dev->tea.card));
snprintf(dev->tea.bus_info, sizeof(dev->tea.bus_info),
"PCI:%s", pci_name(pdev));
retval = -ENODEV;
if (!request_region(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0), v4l2_dev->name)) {
dev_err(&pdev->dev, "can't reserve I/O ports\n");
goto err_hdl;
}
if (pci_enable_device(pdev))
goto err_out_free_region;
dev->io = pci_resource_start(pdev, 0);
if (snd_tea575x_init(&dev->tea)) {
printk(KERN_ERR "radio-maxiradio: Unable to detect TEA575x tuner\n");
goto err_out_free_region;
}
return 0;
err_out_free_region:
release_region(pci_resource_start(pdev, 0), pci_resource_len(pdev, 0));
err_hdl:
v4l2_device_unregister(v4l2_dev);
errfr:
kfree(dev);
return retval;
}
static void __devexit maxiradio_remove(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct maxiradio *dev = to_maxiradio(v4l2_dev);
snd_tea575x_exit(&dev->tea);
outb(0, dev->io);
v4l2_device_unregister(v4l2_dev);
release_region(pci_resource_start(pdev, 0), pci_resource_len(pdev, 0));
}
static int __init maxiradio_init(void)
{
return pci_register_driver(&maxiradio_driver);
}
static void __exit maxiradio_exit(void)
{
pci_unregister_driver(&maxiradio_driver);
}
