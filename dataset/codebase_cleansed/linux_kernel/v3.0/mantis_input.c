int mantis_input_init(struct mantis_pci *mantis)
{
struct rc_dev *dev;
int err;
err = rc_map_register(&ir_mantis_map);
if (err)
goto out;
dev = rc_allocate_device();
if (!dev) {
dprintk(MANTIS_ERROR, 1, "Remote device allocation failed");
err = -ENOMEM;
goto out_map;
}
sprintf(mantis->input_name, "Mantis %s IR receiver", mantis->hwconfig->model_name);
sprintf(mantis->input_phys, "pci-%s/ir0", pci_name(mantis->pdev));
dev->input_name = mantis->input_name;
dev->input_phys = mantis->input_phys;
dev->input_id.bustype = BUS_PCI;
dev->input_id.vendor = mantis->vendor_id;
dev->input_id.product = mantis->device_id;
dev->input_id.version = 1;
dev->driver_name = MODULE_NAME;
dev->map_name = RC_MAP_MANTIS;
dev->dev.parent = &mantis->pdev->dev;
err = rc_register_device(dev);
if (err) {
dprintk(MANTIS_ERROR, 1, "IR device registration failed, ret = %d", err);
goto out_dev;
}
mantis->rc = dev;
return 0;
out_dev:
rc_free_device(dev);
out_map:
rc_map_unregister(&ir_mantis_map);
out:
return err;
}
int mantis_exit(struct mantis_pci *mantis)
{
rc_unregister_device(mantis->rc);
rc_map_unregister(&ir_mantis_map);
return 0;
}
