static int create_composite_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk_comp)
{
int probed_ifnum = get_iface_desc(iface->altsetting)->bInterfaceNumber;
const struct snd_usb_audio_quirk *quirk;
int err;
for (quirk = quirk_comp->data; quirk->ifnum >= 0; ++quirk) {
iface = usb_ifnum_to_if(chip->dev, quirk->ifnum);
if (!iface)
continue;
if (quirk->ifnum != probed_ifnum &&
usb_interface_claimed(iface))
continue;
err = snd_usb_create_quirk(chip, iface, driver, quirk);
if (err < 0)
return err;
}
for (quirk = quirk_comp->data; quirk->ifnum >= 0; ++quirk) {
iface = usb_ifnum_to_if(chip->dev, quirk->ifnum);
if (!iface)
continue;
if (quirk->ifnum != probed_ifnum &&
!usb_interface_claimed(iface))
usb_driver_claim_interface(driver, iface, (void *)-1L);
}
return 0;
}
static int ignore_interface_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
return 0;
}
static int create_align_transfer_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
chip->txfr_quirk = 1;
return 1;
}
static int create_any_midi_quirk(struct snd_usb_audio *chip,
struct usb_interface *intf,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
return snd_usbmidi_create(chip->card, intf, &chip->midi_list, quirk);
}
static int create_standard_audio_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
struct usb_host_interface *alts;
struct usb_interface_descriptor *altsd;
int err;
if (chip->usb_id == USB_ID(0x1686, 0x00dd))
chip->tx_length_quirk = 1;
alts = &iface->altsetting[0];
altsd = get_iface_desc(alts);
err = snd_usb_parse_audio_interface(chip, altsd->bInterfaceNumber);
if (err < 0) {
usb_audio_err(chip, "cannot setup if %d: error %d\n",
altsd->bInterfaceNumber, err);
return err;
}
usb_set_interface(chip->dev, altsd->bInterfaceNumber, 0);
return 0;
}
static int create_fixed_stream_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
struct audioformat *fp;
struct usb_host_interface *alts;
struct usb_interface_descriptor *altsd;
int stream, err;
unsigned *rate_table = NULL;
fp = kmemdup(quirk->data, sizeof(*fp), GFP_KERNEL);
if (!fp) {
usb_audio_err(chip, "cannot memdup\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&fp->list);
if (fp->nr_rates > MAX_NR_RATES) {
kfree(fp);
return -EINVAL;
}
if (fp->nr_rates > 0) {
rate_table = kmemdup(fp->rate_table,
sizeof(int) * fp->nr_rates, GFP_KERNEL);
if (!rate_table) {
kfree(fp);
return -ENOMEM;
}
fp->rate_table = rate_table;
}
stream = (fp->endpoint & USB_DIR_IN)
? SNDRV_PCM_STREAM_CAPTURE : SNDRV_PCM_STREAM_PLAYBACK;
err = snd_usb_add_audio_stream(chip, stream, fp);
if (err < 0)
goto error;
if (fp->iface != get_iface_desc(&iface->altsetting[0])->bInterfaceNumber ||
fp->altset_idx >= iface->num_altsetting) {
err = -EINVAL;
goto error;
}
alts = &iface->altsetting[fp->altset_idx];
altsd = get_iface_desc(alts);
if (altsd->bNumEndpoints < 1) {
err = -EINVAL;
goto error;
}
fp->protocol = altsd->bInterfaceProtocol;
if (fp->datainterval == 0)
fp->datainterval = snd_usb_parse_datainterval(chip, alts);
if (fp->maxpacksize == 0)
fp->maxpacksize = le16_to_cpu(get_endpoint(alts, 0)->wMaxPacketSize);
usb_set_interface(chip->dev, fp->iface, 0);
snd_usb_init_pitch(chip, fp->iface, alts, fp);
snd_usb_init_sample_rate(chip, fp->iface, alts, fp, fp->rate_max);
return 0;
error:
list_del(&fp->list);
kfree(fp);
kfree(rate_table);
return err;
}
static int create_auto_pcm_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver)
{
struct usb_host_interface *alts;
struct usb_interface_descriptor *altsd;
struct usb_endpoint_descriptor *epd;
struct uac1_as_header_descriptor *ashd;
struct uac_format_type_i_discrete_descriptor *fmtd;
if (iface->num_altsetting < 2)
return -ENODEV;
alts = &iface->altsetting[1];
altsd = get_iface_desc(alts);
if (altsd->bNumEndpoints < 1)
return -ENODEV;
epd = get_endpoint(alts, 0);
if (!usb_endpoint_xfer_isoc(epd))
return -ENODEV;
ashd = snd_usb_find_csint_desc(alts->extra, alts->extralen, NULL,
UAC_AS_GENERAL);
fmtd = snd_usb_find_csint_desc(alts->extra, alts->extralen, NULL,
UAC_FORMAT_TYPE);
if (!ashd || ashd->bLength < 7 ||
!fmtd || fmtd->bLength < 8)
return -ENODEV;
return create_standard_audio_quirk(chip, iface, driver, NULL);
}
static int create_yamaha_midi_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
struct usb_host_interface *alts)
{
static const struct snd_usb_audio_quirk yamaha_midi_quirk = {
.type = QUIRK_MIDI_YAMAHA
};
struct usb_midi_in_jack_descriptor *injd;
struct usb_midi_out_jack_descriptor *outjd;
injd = snd_usb_find_csint_desc(alts->extra, alts->extralen,
NULL, USB_MS_MIDI_IN_JACK);
outjd = snd_usb_find_csint_desc(alts->extra, alts->extralen,
NULL, USB_MS_MIDI_OUT_JACK);
if (!injd && !outjd)
return -ENODEV;
if (injd && (injd->bLength < 5 ||
(injd->bJackType != USB_MS_EMBEDDED &&
injd->bJackType != USB_MS_EXTERNAL)))
return -ENODEV;
if (outjd && (outjd->bLength < 6 ||
(outjd->bJackType != USB_MS_EMBEDDED &&
outjd->bJackType != USB_MS_EXTERNAL)))
return -ENODEV;
return create_any_midi_quirk(chip, iface, driver, &yamaha_midi_quirk);
}
static int create_roland_midi_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
struct usb_host_interface *alts)
{
static const struct snd_usb_audio_quirk roland_midi_quirk = {
.type = QUIRK_MIDI_ROLAND
};
u8 *roland_desc = NULL;
for (;;) {
roland_desc = snd_usb_find_csint_desc(alts->extra,
alts->extralen,
roland_desc, 0xf1);
if (!roland_desc)
return -ENODEV;
if (roland_desc[0] < 6 || roland_desc[3] != 2)
continue;
return create_any_midi_quirk(chip, iface, driver,
&roland_midi_quirk);
}
}
static int create_std_midi_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
struct usb_host_interface *alts)
{
struct usb_ms_header_descriptor *mshd;
struct usb_ms_endpoint_descriptor *msepd;
mshd = (struct usb_ms_header_descriptor *)alts->extra;
if (alts->extralen < 7 ||
mshd->bLength < 7 ||
mshd->bDescriptorType != USB_DT_CS_INTERFACE ||
mshd->bDescriptorSubtype != USB_MS_HEADER)
return -ENODEV;
msepd = (struct usb_ms_endpoint_descriptor *)alts->endpoint[0].extra;
if (alts->endpoint[0].extralen < 4 ||
msepd->bLength < 4 ||
msepd->bDescriptorType != USB_DT_CS_ENDPOINT ||
msepd->bDescriptorSubtype != UAC_MS_GENERAL ||
msepd->bNumEmbMIDIJack < 1 ||
msepd->bNumEmbMIDIJack > 16)
return -ENODEV;
return create_any_midi_quirk(chip, iface, driver, NULL);
}
static int create_auto_midi_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver)
{
struct usb_host_interface *alts;
struct usb_interface_descriptor *altsd;
struct usb_endpoint_descriptor *epd;
int err;
alts = &iface->altsetting[0];
altsd = get_iface_desc(alts);
if (altsd->bNumEndpoints < 1)
return -ENODEV;
epd = get_endpoint(alts, 0);
if (!usb_endpoint_xfer_bulk(epd) &&
!usb_endpoint_xfer_int(epd))
return -ENODEV;
switch (USB_ID_VENDOR(chip->usb_id)) {
case 0x0499:
err = create_yamaha_midi_quirk(chip, iface, driver, alts);
if (err != -ENODEV)
return err;
break;
case 0x0582:
err = create_roland_midi_quirk(chip, iface, driver, alts);
if (err != -ENODEV)
return err;
break;
}
return create_std_midi_quirk(chip, iface, driver, alts);
}
static int create_autodetect_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver)
{
int err;
err = create_auto_pcm_quirk(chip, iface, driver);
if (err == -ENODEV)
err = create_auto_midi_quirk(chip, iface, driver);
return err;
}
static int create_autodetect_quirks(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
int probed_ifnum = get_iface_desc(iface->altsetting)->bInterfaceNumber;
int ifcount, ifnum, err;
err = create_autodetect_quirk(chip, iface, driver);
if (err < 0)
return err;
ifcount = chip->dev->actconfig->desc.bNumInterfaces;
for (ifnum = 0; ifnum < ifcount; ifnum++) {
if (ifnum == probed_ifnum || quirk->ifnum >= 0)
continue;
iface = usb_ifnum_to_if(chip->dev, ifnum);
if (!iface ||
usb_interface_claimed(iface) ||
get_iface_desc(iface->altsetting)->bInterfaceClass !=
USB_CLASS_VENDOR_SPEC)
continue;
err = create_autodetect_quirk(chip, iface, driver);
if (err >= 0)
usb_driver_claim_interface(driver, iface, (void *)-1L);
}
return 0;
}
static int create_uaxx_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
static const struct audioformat ua_format = {
.formats = SNDRV_PCM_FMTBIT_S24_3LE,
.channels = 2,
.fmt_type = UAC_FORMAT_TYPE_I,
.altsetting = 1,
.altset_idx = 1,
.rates = SNDRV_PCM_RATE_CONTINUOUS,
};
struct usb_host_interface *alts;
struct usb_interface_descriptor *altsd;
struct audioformat *fp;
int stream, err;
if (iface->num_altsetting < 2)
return -ENXIO;
alts = &iface->altsetting[1];
altsd = get_iface_desc(alts);
if (altsd->bNumEndpoints == 2) {
static const struct snd_usb_midi_endpoint_info ua700_ep = {
.out_cables = 0x0003,
.in_cables = 0x0003
};
static const struct snd_usb_audio_quirk ua700_quirk = {
.type = QUIRK_MIDI_FIXED_ENDPOINT,
.data = &ua700_ep
};
static const struct snd_usb_midi_endpoint_info uaxx_ep = {
.out_cables = 0x0001,
.in_cables = 0x0001
};
static const struct snd_usb_audio_quirk uaxx_quirk = {
.type = QUIRK_MIDI_FIXED_ENDPOINT,
.data = &uaxx_ep
};
const struct snd_usb_audio_quirk *quirk =
chip->usb_id == USB_ID(0x0582, 0x002b)
? &ua700_quirk : &uaxx_quirk;
return __snd_usbmidi_create(chip->card, iface,
&chip->midi_list, quirk,
chip->usb_id);
}
if (altsd->bNumEndpoints != 1)
return -ENXIO;
fp = kmemdup(&ua_format, sizeof(*fp), GFP_KERNEL);
if (!fp)
return -ENOMEM;
fp->iface = altsd->bInterfaceNumber;
fp->endpoint = get_endpoint(alts, 0)->bEndpointAddress;
fp->ep_attr = get_endpoint(alts, 0)->bmAttributes;
fp->datainterval = 0;
fp->maxpacksize = le16_to_cpu(get_endpoint(alts, 0)->wMaxPacketSize);
INIT_LIST_HEAD(&fp->list);
switch (fp->maxpacksize) {
case 0x120:
fp->rate_max = fp->rate_min = 44100;
break;
case 0x138:
case 0x140:
fp->rate_max = fp->rate_min = 48000;
break;
case 0x258:
case 0x260:
fp->rate_max = fp->rate_min = 96000;
break;
default:
usb_audio_err(chip, "unknown sample rate\n");
kfree(fp);
return -ENXIO;
}
stream = (fp->endpoint & USB_DIR_IN)
? SNDRV_PCM_STREAM_CAPTURE : SNDRV_PCM_STREAM_PLAYBACK;
err = snd_usb_add_audio_stream(chip, stream, fp);
if (err < 0) {
list_del(&fp->list);
kfree(fp);
return err;
}
usb_set_interface(chip->dev, fp->iface, 0);
return 0;
}
static int create_standard_mixer_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
if (quirk->ifnum < 0)
return 0;
return snd_usb_create_mixer(chip, quirk->ifnum, 0);
}
int snd_usb_create_quirk(struct snd_usb_audio *chip,
struct usb_interface *iface,
struct usb_driver *driver,
const struct snd_usb_audio_quirk *quirk)
{
typedef int (*quirk_func_t)(struct snd_usb_audio *,
struct usb_interface *,
struct usb_driver *,
const struct snd_usb_audio_quirk *);
static const quirk_func_t quirk_funcs[] = {
[QUIRK_IGNORE_INTERFACE] = ignore_interface_quirk,
[QUIRK_COMPOSITE] = create_composite_quirk,
[QUIRK_AUTODETECT] = create_autodetect_quirks,
[QUIRK_MIDI_STANDARD_INTERFACE] = create_any_midi_quirk,
[QUIRK_MIDI_FIXED_ENDPOINT] = create_any_midi_quirk,
[QUIRK_MIDI_YAMAHA] = create_any_midi_quirk,
[QUIRK_MIDI_ROLAND] = create_any_midi_quirk,
[QUIRK_MIDI_MIDIMAN] = create_any_midi_quirk,
[QUIRK_MIDI_NOVATION] = create_any_midi_quirk,
[QUIRK_MIDI_RAW_BYTES] = create_any_midi_quirk,
[QUIRK_MIDI_EMAGIC] = create_any_midi_quirk,
[QUIRK_MIDI_CME] = create_any_midi_quirk,
[QUIRK_MIDI_AKAI] = create_any_midi_quirk,
[QUIRK_MIDI_FTDI] = create_any_midi_quirk,
[QUIRK_MIDI_CH345] = create_any_midi_quirk,
[QUIRK_AUDIO_STANDARD_INTERFACE] = create_standard_audio_quirk,
[QUIRK_AUDIO_FIXED_ENDPOINT] = create_fixed_stream_quirk,
[QUIRK_AUDIO_EDIROL_UAXX] = create_uaxx_quirk,
[QUIRK_AUDIO_ALIGN_TRANSFER] = create_align_transfer_quirk,
[QUIRK_AUDIO_STANDARD_MIXER] = create_standard_mixer_quirk,
};
if (quirk->type < QUIRK_TYPE_COUNT) {
return quirk_funcs[quirk->type](chip, iface, driver, quirk);
} else {
usb_audio_err(chip, "invalid quirk type %d\n", quirk->type);
return -ENXIO;
}
}
static int snd_usb_extigy_boot_quirk(struct usb_device *dev, struct usb_interface *intf)
{
struct usb_host_config *config = dev->actconfig;
int err;
if (le16_to_cpu(get_cfg_desc(config)->wTotalLength) == EXTIGY_FIRMWARE_SIZE_OLD ||
le16_to_cpu(get_cfg_desc(config)->wTotalLength) == EXTIGY_FIRMWARE_SIZE_NEW) {
dev_dbg(&dev->dev, "sending Extigy boot sequence...\n");
err = snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev,0),
0x10, 0x43, 0x0001, 0x000a, NULL, 0);
if (err < 0)
dev_dbg(&dev->dev, "error sending boot message: %d\n", err);
err = usb_get_descriptor(dev, USB_DT_DEVICE, 0,
&dev->descriptor, sizeof(dev->descriptor));
config = dev->actconfig;
if (err < 0)
dev_dbg(&dev->dev, "error usb_get_descriptor: %d\n", err);
err = usb_reset_configuration(dev);
if (err < 0)
dev_dbg(&dev->dev, "error usb_reset_configuration: %d\n", err);
dev_dbg(&dev->dev, "extigy_boot: new boot length = %d\n",
le16_to_cpu(get_cfg_desc(config)->wTotalLength));
return -ENODEV;
}
return 0;
}
static int snd_usb_audigy2nx_boot_quirk(struct usb_device *dev)
{
u8 buf = 1;
snd_usb_ctl_msg(dev, usb_rcvctrlpipe(dev, 0), 0x2a,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_OTHER,
0, 0, &buf, 1);
if (buf == 0) {
snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0), 0x29,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER,
1, 2000, NULL, 0);
return -ENODEV;
}
return 0;
}
static int snd_usb_fasttrackpro_boot_quirk(struct usb_device *dev)
{
int err;
if (dev->actconfig->desc.bConfigurationValue == 1) {
dev_info(&dev->dev,
"Fast Track Pro switching to config #2\n");
err = usb_driver_set_configuration(dev, 2);
if (err < 0)
dev_dbg(&dev->dev,
"error usb_driver_set_configuration: %d\n",
err);
return -ENODEV;
} else
dev_info(&dev->dev, "Fast Track Pro config OK\n");
return 0;
}
static int snd_usb_cm106_write_int_reg(struct usb_device *dev, int reg, u16 value)
{
u8 buf[4];
buf[0] = 0x20;
buf[1] = value & 0xff;
buf[2] = (value >> 8) & 0xff;
buf[3] = reg;
return snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0), USB_REQ_SET_CONFIGURATION,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_ENDPOINT,
0, 0, &buf, 4);
}
static int snd_usb_cm106_boot_quirk(struct usb_device *dev)
{
return snd_usb_cm106_write_int_reg(dev, 2, 0x8004);
}
static int snd_usb_cm6206_boot_quirk(struct usb_device *dev)
{
int err = 0, reg;
int val[] = {0x2004, 0x3000, 0xf800, 0x143f, 0x0000, 0x3000};
for (reg = 0; reg < ARRAY_SIZE(val); reg++) {
err = snd_usb_cm106_write_int_reg(dev, reg, val[reg]);
if (err < 0)
return err;
}
return err;
}
static int snd_usb_gamecon780_boot_quirk(struct usb_device *dev)
{
u8 buf[2] = { 0x74, 0xe3 };
return snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0), UAC_SET_CUR,
USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT,
UAC_FU_VOLUME << 8, 9 << 8, buf, 2);
}
static int snd_usb_novation_boot_quirk(struct usb_device *dev)
{
usb_set_interface(dev, 0, 1);
return 0;
}
static int snd_usb_accessmusic_boot_quirk(struct usb_device *dev)
{
int err, actual_length;
static const u8 seq[] = { 0x4e, 0x73, 0x52, 0x01 };
void *buf = kmemdup(seq, ARRAY_SIZE(seq), GFP_KERNEL);
if (!buf)
return -ENOMEM;
err = usb_interrupt_msg(dev, usb_sndintpipe(dev, 0x05), buf,
ARRAY_SIZE(seq), &actual_length, 1000);
kfree(buf);
if (err < 0)
return err;
return 0;
}
static int snd_usb_nativeinstruments_boot_quirk(struct usb_device *dev)
{
int ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
0xaf, USB_TYPE_VENDOR | USB_RECIP_DEVICE,
1, 0, NULL, 0, 1000);
if (ret < 0)
return ret;
usb_reset_device(dev);
return -EAGAIN;
}
static void mbox2_setup_48_24_magic(struct usb_device *dev)
{
u8 srate[3];
u8 temp[12];
srate[0] = 0x80;
srate[1] = 0xbb;
srate[2] = 0x00;
snd_usb_ctl_msg(dev, usb_rcvctrlpipe(dev, 0),
0x01, 0x22, 0x0100, 0x0085, &temp, 0x0003);
snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0),
0x81, 0xa2, 0x0100, 0x0085, &srate, 0x0003);
snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0),
0x81, 0xa2, 0x0100, 0x0086, &srate, 0x0003);
snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0),
0x81, 0xa2, 0x0100, 0x0003, &srate, 0x0003);
return;
}
static int snd_usb_mbox2_boot_quirk(struct usb_device *dev)
{
struct usb_host_config *config = dev->actconfig;
int err;
u8 bootresponse[0x12];
int fwsize;
int count;
fwsize = le16_to_cpu(get_cfg_desc(config)->wTotalLength);
if (fwsize != MBOX2_FIRMWARE_SIZE) {
dev_err(&dev->dev, "Invalid firmware size=%d.\n", fwsize);
return -ENODEV;
}
dev_dbg(&dev->dev, "Sending Digidesign Mbox 2 boot sequence...\n");
count = 0;
bootresponse[0] = MBOX2_BOOT_LOADING;
while ((bootresponse[0] == MBOX2_BOOT_LOADING) && (count < 10)) {
msleep(500);
snd_usb_ctl_msg(dev, usb_rcvctrlpipe(dev, 0),
0x85, 0xc0, 0x0001, 0x0000, &bootresponse, 0x0012);
if (bootresponse[0] == MBOX2_BOOT_READY)
break;
dev_dbg(&dev->dev, "device not ready, resending boot sequence...\n");
count++;
}
if (bootresponse[0] != MBOX2_BOOT_READY) {
dev_err(&dev->dev, "Unknown bootresponse=%d, or timed out, ignoring device.\n", bootresponse[0]);
return -ENODEV;
}
dev_dbg(&dev->dev, "device initialised!\n");
err = usb_get_descriptor(dev, USB_DT_DEVICE, 0,
&dev->descriptor, sizeof(dev->descriptor));
config = dev->actconfig;
if (err < 0)
dev_dbg(&dev->dev, "error usb_get_descriptor: %d\n", err);
err = usb_reset_configuration(dev);
if (err < 0)
dev_dbg(&dev->dev, "error usb_reset_configuration: %d\n", err);
dev_dbg(&dev->dev, "mbox2_boot: new boot length = %d\n",
le16_to_cpu(get_cfg_desc(config)->wTotalLength));
mbox2_setup_48_24_magic(dev);
dev_info(&dev->dev, "Digidesign Mbox 2: 24bit 48kHz");
return 0;
}
static int quattro_skip_setting_quirk(struct snd_usb_audio *chip,
int iface, int altno)
{
usb_set_interface(chip->dev, iface, 0);
if (chip->setup & MAUDIO_SET) {
if (chip->setup & MAUDIO_SET_COMPATIBLE) {
if (iface != 1 && iface != 2)
return 1;
} else {
unsigned int mask;
if (iface == 1 || iface == 2)
return 1;
if ((chip->setup & MAUDIO_SET_96K) && altno != 1)
return 1;
mask = chip->setup & MAUDIO_SET_MASK;
if (mask == MAUDIO_SET_24B_48K_DI && altno != 2)
return 1;
if (mask == MAUDIO_SET_24B_48K_NOTDI && altno != 3)
return 1;
if (mask == MAUDIO_SET_16B_48K_NOTDI && altno != 4)
return 1;
}
}
usb_audio_dbg(chip,
"using altsetting %d for interface %d config %d\n",
altno, iface, chip->setup);
return 0;
}
static int audiophile_skip_setting_quirk(struct snd_usb_audio *chip,
int iface,
int altno)
{
usb_set_interface(chip->dev, iface, 0);
if (chip->setup & MAUDIO_SET) {
unsigned int mask;
if ((chip->setup & MAUDIO_SET_DTS) && altno != 6)
return 1;
if ((chip->setup & MAUDIO_SET_96K) && altno != 1)
return 1;
mask = chip->setup & MAUDIO_SET_MASK;
if (mask == MAUDIO_SET_24B_48K_DI && altno != 2)
return 1;
if (mask == MAUDIO_SET_24B_48K_NOTDI && altno != 3)
return 1;
if (mask == MAUDIO_SET_16B_48K_DI && altno != 4)
return 1;
if (mask == MAUDIO_SET_16B_48K_NOTDI && altno != 5)
return 1;
}
return 0;
}
static int fasttrackpro_skip_setting_quirk(struct snd_usb_audio *chip,
int iface, int altno)
{
usb_set_interface(chip->dev, iface, 0);
if (chip->setup & (MAUDIO_SET | MAUDIO_SET_24B)) {
if (chip->setup & MAUDIO_SET_96K) {
if (altno != 3 && altno != 6)
return 1;
} else if (chip->setup & MAUDIO_SET_DI) {
if (iface == 4)
return 1;
if (altno != 2 && altno != 5)
return 1;
} else {
if (iface == 5)
return 1;
if (altno != 2 && altno != 5)
return 1;
}
} else {
if (altno != 1)
return 1;
}
usb_audio_dbg(chip,
"using altsetting %d for interface %d config %d\n",
altno, iface, chip->setup);
return 0;
}
int snd_usb_apply_interface_quirk(struct snd_usb_audio *chip,
int iface,
int altno)
{
if (chip->usb_id == USB_ID(0x0763, 0x2003))
return audiophile_skip_setting_quirk(chip, iface, altno);
if (chip->usb_id == USB_ID(0x0763, 0x2001))
return quattro_skip_setting_quirk(chip, iface, altno);
if (chip->usb_id == USB_ID(0x0763, 0x2012))
return fasttrackpro_skip_setting_quirk(chip, iface, altno);
return 0;
}
int snd_usb_apply_boot_quirk(struct usb_device *dev,
struct usb_interface *intf,
const struct snd_usb_audio_quirk *quirk,
unsigned int id)
{
switch (id) {
case USB_ID(0x041e, 0x3000):
return snd_usb_extigy_boot_quirk(dev, intf);
case USB_ID(0x041e, 0x3020):
return snd_usb_audigy2nx_boot_quirk(dev);
case USB_ID(0x10f5, 0x0200):
return snd_usb_cm106_boot_quirk(dev);
case USB_ID(0x0d8c, 0x0102):
case USB_ID(0x0ccd, 0x00b1):
return snd_usb_cm6206_boot_quirk(dev);
case USB_ID(0x0dba, 0x3000):
return snd_usb_mbox2_boot_quirk(dev);
case USB_ID(0x1235, 0x0010):
case USB_ID(0x1235, 0x0018):
return snd_usb_novation_boot_quirk(dev);
case USB_ID(0x133e, 0x0815):
return snd_usb_accessmusic_boot_quirk(dev);
case USB_ID(0x17cc, 0x1000):
case USB_ID(0x17cc, 0x1010):
case USB_ID(0x17cc, 0x1020):
return snd_usb_nativeinstruments_boot_quirk(dev);
case USB_ID(0x0763, 0x2012):
return snd_usb_fasttrackpro_boot_quirk(dev);
case USB_ID(0x047f, 0xc010):
return snd_usb_gamecon780_boot_quirk(dev);
}
return 0;
}
int snd_usb_is_big_endian_format(struct snd_usb_audio *chip, struct audioformat *fp)
{
switch (chip->usb_id) {
case USB_ID(0x0763, 0x2001):
if (fp->altsetting == 2 || fp->altsetting == 3 ||
fp->altsetting == 5 || fp->altsetting == 6)
return 1;
break;
case USB_ID(0x0763, 0x2003):
if (chip->setup == 0x00 ||
fp->altsetting == 1 || fp->altsetting == 2 ||
fp->altsetting == 3)
return 1;
break;
case USB_ID(0x0763, 0x2012):
if (fp->altsetting == 2 || fp->altsetting == 3 ||
fp->altsetting == 5 || fp->altsetting == 6)
return 1;
break;
}
return 0;
}
static void set_format_emu_quirk(struct snd_usb_substream *subs,
struct audioformat *fmt)
{
unsigned char emu_samplerate_id = 0;
if (subs->direction == SNDRV_PCM_STREAM_PLAYBACK) {
if (subs->stream->substream[SNDRV_PCM_STREAM_CAPTURE].interface != -1)
return;
}
switch (fmt->rate_min) {
case 48000:
emu_samplerate_id = EMU_QUIRK_SR_48000HZ;
break;
case 88200:
emu_samplerate_id = EMU_QUIRK_SR_88200HZ;
break;
case 96000:
emu_samplerate_id = EMU_QUIRK_SR_96000HZ;
break;
case 176400:
emu_samplerate_id = EMU_QUIRK_SR_176400HZ;
break;
case 192000:
emu_samplerate_id = EMU_QUIRK_SR_192000HZ;
break;
default:
emu_samplerate_id = EMU_QUIRK_SR_44100HZ;
break;
}
snd_emuusb_set_samplerate(subs->stream->chip, emu_samplerate_id);
subs->pkt_offset_adj = (emu_samplerate_id >= EMU_QUIRK_SR_176400HZ) ? 4 : 0;
}
void snd_usb_set_format_quirk(struct snd_usb_substream *subs,
struct audioformat *fmt)
{
switch (subs->stream->chip->usb_id) {
case USB_ID(0x041e, 0x3f02):
case USB_ID(0x041e, 0x3f04):
case USB_ID(0x041e, 0x3f0a):
case USB_ID(0x041e, 0x3f19):
set_format_emu_quirk(subs, fmt);
break;
}
}
bool snd_usb_get_sample_rate_quirk(struct snd_usb_audio *chip)
{
switch (chip->usb_id) {
case USB_ID(0x041E, 0x4080):
case USB_ID(0x045E, 0x075D):
case USB_ID(0x045E, 0x076D):
case USB_ID(0x045E, 0x076E):
case USB_ID(0x045E, 0x076F):
case USB_ID(0x045E, 0x0772):
case USB_ID(0x045E, 0x0779):
case USB_ID(0x047F, 0x02F7):
case USB_ID(0x047F, 0x0415):
case USB_ID(0x047F, 0xAA05):
case USB_ID(0x04D8, 0xFEEA):
case USB_ID(0x0556, 0x0014):
case USB_ID(0x05A3, 0x9420):
case USB_ID(0x074D, 0x3553):
case USB_ID(0x1395, 0x740a):
case USB_ID(0x1901, 0x0191):
case USB_ID(0x1de7, 0x0013):
case USB_ID(0x1de7, 0x0014):
case USB_ID(0x1de7, 0x0114):
case USB_ID(0x21B4, 0x0081):
return true;
}
return false;
}
static bool is_marantz_denon_dac(unsigned int id)
{
switch (id) {
case USB_ID(0x154e, 0x1003):
case USB_ID(0x154e, 0x3005):
case USB_ID(0x154e, 0x3006):
return true;
}
return false;
}
static bool is_teac_50X_dac(unsigned int id)
{
switch (id) {
case USB_ID(0x0644, 0x8043):
return true;
}
return false;
}
int snd_usb_select_mode_quirk(struct snd_usb_substream *subs,
struct audioformat *fmt)
{
struct usb_device *dev = subs->dev;
int err;
if (is_marantz_denon_dac(subs->stream->chip->usb_id)) {
err = usb_set_interface(dev, fmt->iface, 0);
if (err < 0)
return err;
mdelay(20);
switch (fmt->altsetting) {
case 2:
case 1:
err = snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0), 0,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
fmt->altsetting - 1, 1, NULL, 0);
if (err < 0)
return err;
break;
}
mdelay(20);
} else if (is_teac_50X_dac(subs->stream->chip->usb_id)) {
switch (fmt->altsetting) {
case 3:
err = snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0), 0,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
1, 1, NULL, 0);
if (err < 0)
return err;
break;
case 2:
case 1:
err = snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0), 0,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
0, 1, NULL, 0);
if (err < 0)
return err;
break;
}
}
return 0;
}
void snd_usb_endpoint_start_quirk(struct snd_usb_endpoint *ep)
{
if (USB_ID_VENDOR(ep->chip->usb_id) == 0x23ba &&
ep->type == SND_USB_ENDPOINT_TYPE_SYNC)
ep->skip_packets = 4;
if ((ep->chip->usb_id == USB_ID(0x0763, 0x2030) ||
ep->chip->usb_id == USB_ID(0x0763, 0x2031)) &&
ep->type == SND_USB_ENDPOINT_TYPE_DATA)
ep->skip_packets = 16;
if ((ep->chip->usb_id == USB_ID(0x0644, 0x8038) ||
ep->chip->usb_id == USB_ID(0x1852, 0x5034)) &&
ep->syncmaxsize == 4)
ep->tenor_fb_quirk = 1;
}
void snd_usb_set_interface_quirk(struct usb_device *dev)
{
struct snd_usb_audio *chip = dev_get_drvdata(&dev->dev);
if (!chip)
return;
switch (USB_ID_VENDOR(chip->usb_id)) {
case 0x23ba:
case 0x0644:
mdelay(50);
break;
}
}
void snd_usb_ctl_msg_quirk(struct usb_device *dev, unsigned int pipe,
__u8 request, __u8 requesttype, __u16 value,
__u16 index, void *data, __u16 size)
{
struct snd_usb_audio *chip = dev_get_drvdata(&dev->dev);
if (!chip)
return;
if (USB_ID_VENDOR(chip->usb_id) == 0x23ba &&
(requesttype & USB_TYPE_MASK) == USB_TYPE_CLASS)
mdelay(20);
if (USB_ID_VENDOR(chip->usb_id) == 0x0644 &&
(requesttype & USB_TYPE_MASK) == USB_TYPE_CLASS)
mdelay(20);
if (is_marantz_denon_dac(chip->usb_id)
&& (requesttype & USB_TYPE_MASK) == USB_TYPE_CLASS)
mdelay(20);
if ((chip->usb_id == USB_ID(0x1686, 0x00dd) ||
chip->usb_id == USB_ID(0x046d, 0x0a46) ||
chip->usb_id == USB_ID(0x0b0e, 0x0349)) &&
(requesttype & USB_TYPE_MASK) == USB_TYPE_CLASS)
mdelay(1);
}
u64 snd_usb_interface_dsd_format_quirks(struct snd_usb_audio *chip,
struct audioformat *fp,
unsigned int sample_bytes)
{
if (USB_ID_VENDOR(chip->usb_id) == 0x23ba) {
switch (fp->altsetting) {
case 1:
fp->dsd_dop = true;
return SNDRV_PCM_FMTBIT_DSD_U16_LE;
case 2:
fp->dsd_bitrev = true;
return SNDRV_PCM_FMTBIT_DSD_U8;
case 3:
fp->dsd_bitrev = true;
return SNDRV_PCM_FMTBIT_DSD_U16_LE;
}
}
switch (chip->usb_id) {
case USB_ID(0x20b1, 0x3008):
case USB_ID(0x20b1, 0x2008):
case USB_ID(0x20b1, 0x300a):
case USB_ID(0x22d9, 0x0416):
if (fp->altsetting == 2)
return SNDRV_PCM_FMTBIT_DSD_U32_BE;
break;
case USB_ID(0x20b1, 0x000a):
case USB_ID(0x20b1, 0x2009):
case USB_ID(0x20b1, 0x2023):
case USB_ID(0x20b1, 0x3023):
case USB_ID(0x2616, 0x0106):
if (fp->altsetting == 3)
return SNDRV_PCM_FMTBIT_DSD_U32_BE;
break;
case USB_ID(0x16d0, 0x071a):
if (fp->altsetting == 2) {
switch (le16_to_cpu(chip->dev->descriptor.bcdDevice)) {
case 0x199:
return SNDRV_PCM_FMTBIT_DSD_U32_LE;
case 0x19b:
return SNDRV_PCM_FMTBIT_DSD_U32_BE;
default:
break;
}
}
break;
case USB_ID(0x16d0, 0x0a23):
if (fp->altsetting == 2)
return SNDRV_PCM_FMTBIT_DSD_U32_BE;
break;
default:
break;
}
if (is_marantz_denon_dac(chip->usb_id)) {
if (fp->altsetting == 2)
return SNDRV_PCM_FMTBIT_DSD_U32_BE;
}
if (is_teac_50X_dac(chip->usb_id)) {
if (fp->altsetting == 3)
return SNDRV_PCM_FMTBIT_DSD_U32_BE;
}
return 0;
}
