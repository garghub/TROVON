static int
wavefront_fx_idle (snd_wavefront_t *dev)
{
int i;
unsigned int x = 0x80;
for (i = 0; i < 1000; i++) {
x = inb (dev->fx_status);
if ((x & 0x80) == 0) {
break;
}
}
if (x & 0x80) {
snd_printk ("FX device never idle.\n");
return 0;
}
return (1);
}
static void
wavefront_fx_mute (snd_wavefront_t *dev, int onoff)
{
if (!wavefront_fx_idle(dev)) {
return;
}
outb (onoff ? 0x02 : 0x00, dev->fx_op);
}
static int
wavefront_fx_memset (snd_wavefront_t *dev,
int page,
int addr,
int cnt,
unsigned short *data)
{
if (page < 0 || page > 7) {
snd_printk ("FX memset: "
"page must be >= 0 and <= 7\n");
return -(EINVAL);
}
if (addr < 0 || addr > 0x7f) {
snd_printk ("FX memset: "
"addr must be >= 0 and <= 7f\n");
return -(EINVAL);
}
if (cnt == 1) {
outb (FX_LSB_TRANSFER, dev->fx_lcr);
outb (page, dev->fx_dsp_page);
outb (addr, dev->fx_dsp_addr);
outb ((data[0] >> 8), dev->fx_dsp_msb);
outb ((data[0] & 0xff), dev->fx_dsp_lsb);
snd_printk ("FX: addr %d:%x set to 0x%x\n",
page, addr, data[0]);
} else {
int i;
outb (FX_AUTO_INCR|FX_LSB_TRANSFER, dev->fx_lcr);
outb (page, dev->fx_dsp_page);
outb (addr, dev->fx_dsp_addr);
for (i = 0; i < cnt; i++) {
outb ((data[i] >> 8), dev->fx_dsp_msb);
outb ((data[i] & 0xff), dev->fx_dsp_lsb);
if (!wavefront_fx_idle (dev)) {
break;
}
}
if (i != cnt) {
snd_printk ("FX memset "
"(0x%x, 0x%x, 0x%lx, %d) incomplete\n",
page, addr, (unsigned long) data, cnt);
return -(EIO);
}
}
return 0;
}
int
snd_wavefront_fx_detect (snd_wavefront_t *dev)
{
if (inb (dev->fx_status) & 0x80) {
snd_printk ("Hmm, probably a Maui or Tropez.\n");
return -1;
}
return 0;
}
int
snd_wavefront_fx_open (struct snd_hwdep *hw, struct file *file)
{
if (!try_module_get(hw->card->module))
return -EFAULT;
file->private_data = hw;
return 0;
}
int
snd_wavefront_fx_release (struct snd_hwdep *hw, struct file *file)
{
module_put(hw->card->module);
return 0;
}
int
snd_wavefront_fx_ioctl (struct snd_hwdep *sdev, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct snd_card *card;
snd_wavefront_card_t *acard;
snd_wavefront_t *dev;
wavefront_fx_info r;
unsigned short *page_data = NULL;
unsigned short *pd;
int err = 0;
card = sdev->card;
if (snd_BUG_ON(!card))
return -ENODEV;
if (snd_BUG_ON(!card->private_data))
return -ENODEV;
acard = card->private_data;
dev = &acard->wavefront;
if (copy_from_user (&r, (void __user *)arg, sizeof (wavefront_fx_info)))
return -EFAULT;
switch (r.request) {
case WFFX_MUTE:
wavefront_fx_mute (dev, r.data[0]);
return -EIO;
case WFFX_MEMSET:
if (r.data[2] <= 0) {
snd_printk ("cannot write "
"<= 0 bytes to FX\n");
return -EIO;
} else if (r.data[2] == 1) {
pd = (unsigned short *) &r.data[3];
} else {
if (r.data[2] > 256) {
snd_printk ("cannot write "
"> 512 bytes to FX\n");
return -EIO;
}
page_data = memdup_user((unsigned char __user *)
r.data[3],
r.data[2] * sizeof(short));
if (IS_ERR(page_data))
return PTR_ERR(page_data);
pd = page_data;
}
err = wavefront_fx_memset (dev,
r.data[0],
r.data[1],
r.data[2],
pd);
kfree(page_data);
break;
default:
snd_printk ("FX: ioctl %d not yet supported\n",
r.request);
return -ENOTTY;
}
return err;
}
int __devinit
snd_wavefront_fx_start (snd_wavefront_t *dev)
{
unsigned int i;
int err;
const struct firmware *firmware = NULL;
if (dev->fx_initialized)
return 0;
err = request_firmware(&firmware, "yamaha/yss225_registers.bin",
dev->card->dev);
if (err < 0) {
err = -1;
goto out;
}
for (i = 0; i + 1 < firmware->size; i += 2) {
if (firmware->data[i] >= 8 && firmware->data[i] < 16) {
outb(firmware->data[i + 1],
dev->base + firmware->data[i]);
} else if (firmware->data[i] == WAIT_IDLE) {
if (!wavefront_fx_idle(dev)) {
err = -1;
goto out;
}
} else {
snd_printk(KERN_ERR "invalid address"
" in register data\n");
err = -1;
goto out;
}
}
dev->fx_initialized = 1;
err = 0;
out:
release_firmware(firmware);
return err;
}
