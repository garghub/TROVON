static int podhd_init(struct usb_line6 *line6,
const struct usb_device_id *id)
{
int err;
err = line6_init_midi(line6);
if (err < 0)
return err;
err = line6_init_pcm(line6, &podhd_pcm_properties);
if (err < 0)
return err;
return snd_card_register(line6->card);
}
static int podhd_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
return line6_probe(interface, id, "Line6-PODHD",
&podhd_properties_table[id->driver_info],
podhd_init, sizeof(struct usb_line6));
}
