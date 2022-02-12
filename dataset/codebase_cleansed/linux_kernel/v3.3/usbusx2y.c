static void i_usX2Y_Out04Int(struct urb *urb)
{
#ifdef CONFIG_SND_DEBUG
if (urb->status) {
int i;
struct usX2Ydev *usX2Y = urb->context;
for (i = 0; i < 10 && usX2Y->AS04.urb[i] != urb; i++);
snd_printdd("i_usX2Y_Out04Int() urb %i status=%i\n", i, urb->status);
}
#endif
}
static void i_usX2Y_In04Int(struct urb *urb)
{
int err = 0;
struct usX2Ydev *usX2Y = urb->context;
struct us428ctls_sharedmem *us428ctls = usX2Y->us428ctls_sharedmem;
usX2Y->In04IntCalls++;
if (urb->status) {
snd_printdd("Interrupt Pipe 4 came back with status=%i\n", urb->status);
return;
}
if (us428ctls) {
int diff = -1;
if (-2 == us428ctls->CtlSnapShotLast) {
diff = 0;
memcpy(usX2Y->In04Last, usX2Y->In04Buf, sizeof(usX2Y->In04Last));
us428ctls->CtlSnapShotLast = -1;
} else {
int i;
for (i = 0; i < 21; i++) {
if (usX2Y->In04Last[i] != ((char*)usX2Y->In04Buf)[i]) {
if (diff < 0)
diff = i;
usX2Y->In04Last[i] = ((char*)usX2Y->In04Buf)[i];
}
}
}
if (0 <= diff) {
int n = us428ctls->CtlSnapShotLast + 1;
if (n >= N_us428_ctl_BUFS || n < 0)
n = 0;
memcpy(us428ctls->CtlSnapShot + n, usX2Y->In04Buf, sizeof(us428ctls->CtlSnapShot[0]));
us428ctls->CtlSnapShotDiffersAt[n] = diff;
us428ctls->CtlSnapShotLast = n;
wake_up(&usX2Y->us428ctls_wait_queue_head);
}
}
if (usX2Y->US04) {
if (0 == usX2Y->US04->submitted)
do {
err = usb_submit_urb(usX2Y->US04->urb[usX2Y->US04->submitted++], GFP_ATOMIC);
} while (!err && usX2Y->US04->submitted < usX2Y->US04->len);
} else
if (us428ctls && us428ctls->p4outLast >= 0 && us428ctls->p4outLast < N_us428_p4out_BUFS) {
if (us428ctls->p4outLast != us428ctls->p4outSent) {
int j, send = us428ctls->p4outSent + 1;
if (send >= N_us428_p4out_BUFS)
send = 0;
for (j = 0; j < URBS_AsyncSeq && !err; ++j)
if (0 == usX2Y->AS04.urb[j]->status) {
struct us428_p4out *p4out = us428ctls->p4out + send;
usb_fill_bulk_urb(usX2Y->AS04.urb[j], usX2Y->dev,
usb_sndbulkpipe(usX2Y->dev, 0x04), &p4out->val.vol,
p4out->type == eLT_Light ? sizeof(struct us428_lights) : 5,
i_usX2Y_Out04Int, usX2Y);
err = usb_submit_urb(usX2Y->AS04.urb[j], GFP_ATOMIC);
us428ctls->p4outSent = send;
break;
}
}
}
if (err)
snd_printk(KERN_ERR "In04Int() usb_submit_urb err=%i\n", err);
urb->dev = usX2Y->dev;
usb_submit_urb(urb, GFP_ATOMIC);
}
int usX2Y_AsyncSeq04_init(struct usX2Ydev *usX2Y)
{
int err = 0,
i;
if (NULL == (usX2Y->AS04.buffer = kmalloc(URB_DataLen_AsyncSeq*URBS_AsyncSeq, GFP_KERNEL))) {
err = -ENOMEM;
} else
for (i = 0; i < URBS_AsyncSeq; ++i) {
if (NULL == (usX2Y->AS04.urb[i] = usb_alloc_urb(0, GFP_KERNEL))) {
err = -ENOMEM;
break;
}
usb_fill_bulk_urb( usX2Y->AS04.urb[i], usX2Y->dev,
usb_sndbulkpipe(usX2Y->dev, 0x04),
usX2Y->AS04.buffer + URB_DataLen_AsyncSeq*i, 0,
i_usX2Y_Out04Int, usX2Y
);
}
return err;
}
int usX2Y_In04_init(struct usX2Ydev *usX2Y)
{
if (! (usX2Y->In04urb = usb_alloc_urb(0, GFP_KERNEL)))
return -ENOMEM;
if (! (usX2Y->In04Buf = kmalloc(21, GFP_KERNEL))) {
usb_free_urb(usX2Y->In04urb);
return -ENOMEM;
}
init_waitqueue_head(&usX2Y->In04WaitQueue);
usb_fill_int_urb(usX2Y->In04urb, usX2Y->dev, usb_rcvintpipe(usX2Y->dev, 0x4),
usX2Y->In04Buf, 21,
i_usX2Y_In04Int, usX2Y,
10);
return usb_submit_urb(usX2Y->In04urb, GFP_KERNEL);
}
static void usX2Y_unlinkSeq(struct snd_usX2Y_AsyncSeq *S)
{
int i;
for (i = 0; i < URBS_AsyncSeq; ++i) {
if (S[i].urb) {
usb_kill_urb(S->urb[i]);
usb_free_urb(S->urb[i]);
S->urb[i] = NULL;
}
}
kfree(S->buffer);
}
static int usX2Y_create_card(struct usb_device *device, struct snd_card **cardp)
{
int dev;
struct snd_card * card;
int err;
for (dev = 0; dev < SNDRV_CARDS; ++dev)
if (enable[dev] && !snd_usX2Y_card_used[dev])
break;
if (dev >= SNDRV_CARDS)
return -ENODEV;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct usX2Ydev), &card);
if (err < 0)
return err;
snd_usX2Y_card_used[usX2Y(card)->card_index = dev] = 1;
card->private_free = snd_usX2Y_card_private_free;
usX2Y(card)->dev = device;
init_waitqueue_head(&usX2Y(card)->prepare_wait_queue);
mutex_init(&usX2Y(card)->prepare_mutex);
INIT_LIST_HEAD(&usX2Y(card)->midi_list);
strcpy(card->driver, "USB "NAME_ALLCAPS"");
sprintf(card->shortname, "TASCAM "NAME_ALLCAPS"");
sprintf(card->longname, "%s (%x:%x if %d at %03d/%03d)",
card->shortname,
le16_to_cpu(device->descriptor.idVendor),
le16_to_cpu(device->descriptor.idProduct),
0,
usX2Y(card)->dev->bus->busnum, usX2Y(card)->dev->devnum
);
*cardp = card;
return 0;
}
static int usX2Y_usb_probe(struct usb_device *device,
struct usb_interface *intf,
const struct usb_device_id *device_id,
struct snd_card **cardp)
{
int err;
struct snd_card * card;
*cardp = NULL;
if (le16_to_cpu(device->descriptor.idVendor) != 0x1604 ||
(le16_to_cpu(device->descriptor.idProduct) != USB_ID_US122 &&
le16_to_cpu(device->descriptor.idProduct) != USB_ID_US224 &&
le16_to_cpu(device->descriptor.idProduct) != USB_ID_US428))
return -EINVAL;
err = usX2Y_create_card(device, &card);
if (err < 0)
return err;
snd_card_set_dev(card, &intf->dev);
if ((err = usX2Y_hwdep_new(card, device)) < 0 ||
(err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
*cardp = card;
return 0;
}
static int snd_usX2Y_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct snd_card *card;
int err;
err = usX2Y_usb_probe(interface_to_usbdev(intf), intf, id, &card);
if (err < 0)
return err;
dev_set_drvdata(&intf->dev, card);
return 0;
}
static void snd_usX2Y_disconnect(struct usb_interface *intf)
{
usX2Y_usb_disconnect(interface_to_usbdev(intf),
usb_get_intfdata(intf));
}
static void snd_usX2Y_card_private_free(struct snd_card *card)
{
kfree(usX2Y(card)->In04Buf);
usb_free_urb(usX2Y(card)->In04urb);
if (usX2Y(card)->us428ctls_sharedmem)
snd_free_pages(usX2Y(card)->us428ctls_sharedmem, sizeof(*usX2Y(card)->us428ctls_sharedmem));
if (usX2Y(card)->card_index >= 0 && usX2Y(card)->card_index < SNDRV_CARDS)
snd_usX2Y_card_used[usX2Y(card)->card_index] = 0;
}
static void usX2Y_usb_disconnect(struct usb_device *device, void* ptr)
{
if (ptr) {
struct snd_card *card = ptr;
struct usX2Ydev *usX2Y = usX2Y(card);
struct list_head *p;
usX2Y->chip_status = USX2Y_STAT_CHIP_HUP;
usX2Y_unlinkSeq(&usX2Y->AS04);
usb_kill_urb(usX2Y->In04urb);
snd_card_disconnect(card);
list_for_each(p, &usX2Y->midi_list) {
snd_usbmidi_disconnect(p);
}
if (usX2Y->us428ctls_sharedmem)
wake_up(&usX2Y->us428ctls_wait_queue_head);
snd_card_free(card);
}
}
