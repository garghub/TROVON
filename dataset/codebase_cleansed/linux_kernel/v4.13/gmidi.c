static int midi_unbind(struct usb_composite_dev *dev)
{
usb_put_function(f_midi);
usb_put_function_instance(fi_midi);
return 0;
}
static int midi_bind_config(struct usb_configuration *c)
{
int status;
f_midi = usb_get_function(fi_midi);
if (IS_ERR(f_midi))
return PTR_ERR(f_midi);
status = usb_add_function(c, f_midi);
if (status < 0) {
usb_put_function(f_midi);
return status;
}
return 0;
}
static int midi_bind(struct usb_composite_dev *cdev)
{
struct f_midi_opts *midi_opts;
int status;
fi_midi = usb_get_function_instance("midi");
if (IS_ERR(fi_midi))
return PTR_ERR(fi_midi);
midi_opts = container_of(fi_midi, struct f_midi_opts, func_inst);
midi_opts->index = index;
midi_opts->id = id;
midi_opts->in_ports = in_ports;
midi_opts->out_ports = out_ports;
midi_opts->buflen = buflen;
midi_opts->qlen = qlen;
status = usb_string_ids_tab(cdev, strings_dev);
if (status < 0)
goto put;
device_desc.iManufacturer = strings_dev[USB_GADGET_MANUFACTURER_IDX].id;
device_desc.iProduct = strings_dev[USB_GADGET_PRODUCT_IDX].id;
midi_config.iConfiguration = strings_dev[STRING_DESCRIPTION_IDX].id;
status = usb_add_config(cdev, &midi_config, midi_bind_config);
if (status < 0)
goto put;
usb_composite_overwrite_options(cdev, &coverwrite);
pr_info("%s\n", longname);
return 0;
put:
usb_put_function_instance(fi_midi);
return status;
}
