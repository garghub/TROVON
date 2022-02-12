static void podhd_destruct(struct usb_interface *interface)
{
struct usb_line6_podhd *podhd = usb_get_intfdata(interface);
if (podhd == NULL)
return;
line6_cleanup_audio(&podhd->line6);
}
static int podhd_try_init(struct usb_interface *interface,
struct usb_line6_podhd *podhd)
{
int err;
struct usb_line6 *line6 = &podhd->line6;
if ((interface == NULL) || (podhd == NULL))
return -ENODEV;
err = line6_init_audio(line6);
if (err < 0)
return err;
err = line6_init_midi(line6);
if (err < 0)
return err;
err = line6_init_pcm(line6, &podhd_pcm_properties);
if (err < 0)
return err;
err = line6_register_audio(line6);
return err;
}
int line6_podhd_init(struct usb_interface *interface,
struct usb_line6_podhd *podhd)
{
int err = podhd_try_init(interface, podhd);
if (err < 0)
podhd_destruct(interface);
return err;
}
void line6_podhd_disconnect(struct usb_interface *interface)
{
struct usb_line6_podhd *podhd;
if (interface == NULL)
return;
podhd = usb_get_intfdata(interface);
if (podhd != NULL) {
struct snd_line6_pcm *line6pcm = podhd->line6.line6pcm;
if (line6pcm != NULL)
line6_pcm_disconnect(line6pcm);
}
podhd_destruct(interface);
}
