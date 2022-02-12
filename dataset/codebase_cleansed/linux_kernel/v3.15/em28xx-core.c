int em28xx_read_reg_req_len(struct em28xx *dev, u8 req, u16 reg,
char *buf, int len)
{
int ret;
int pipe = usb_rcvctrlpipe(dev->udev, 0);
if (dev->disconnected)
return -ENODEV;
if (len > URB_MAX_CTRL_SIZE)
return -EINVAL;
if (reg_debug) {
printk(KERN_DEBUG "(pipe 0x%08x): "
"IN: %02x %02x %02x %02x %02x %02x %02x %02x ",
pipe,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
req, 0, 0,
reg & 0xff, reg >> 8,
len & 0xff, len >> 8);
}
mutex_lock(&dev->ctrl_urb_lock);
ret = usb_control_msg(dev->udev, pipe, req,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x0000, reg, dev->urb_buf, len, HZ);
if (ret < 0) {
if (reg_debug)
printk(" failed!\n");
mutex_unlock(&dev->ctrl_urb_lock);
return usb_translate_errors(ret);
}
if (len)
memcpy(buf, dev->urb_buf, len);
mutex_unlock(&dev->ctrl_urb_lock);
if (reg_debug) {
int byte;
printk("<<<");
for (byte = 0; byte < len; byte++)
printk(" %02x", (unsigned char)buf[byte]);
printk("\n");
}
return ret;
}
int em28xx_read_reg_req(struct em28xx *dev, u8 req, u16 reg)
{
int ret;
u8 val;
ret = em28xx_read_reg_req_len(dev, req, reg, &val, 1);
if (ret < 0)
return ret;
return val;
}
int em28xx_read_reg(struct em28xx *dev, u16 reg)
{
return em28xx_read_reg_req(dev, USB_REQ_GET_STATUS, reg);
}
int em28xx_write_regs_req(struct em28xx *dev, u8 req, u16 reg, char *buf,
int len)
{
int ret;
int pipe = usb_sndctrlpipe(dev->udev, 0);
if (dev->disconnected)
return -ENODEV;
if ((len < 1) || (len > URB_MAX_CTRL_SIZE))
return -EINVAL;
if (reg_debug) {
int byte;
printk(KERN_DEBUG "(pipe 0x%08x): "
"OUT: %02x %02x %02x %02x %02x %02x %02x %02x >>>",
pipe,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
req, 0, 0,
reg & 0xff, reg >> 8,
len & 0xff, len >> 8);
for (byte = 0; byte < len; byte++)
printk(" %02x", (unsigned char)buf[byte]);
printk("\n");
}
mutex_lock(&dev->ctrl_urb_lock);
memcpy(dev->urb_buf, buf, len);
ret = usb_control_msg(dev->udev, pipe, req,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x0000, reg, dev->urb_buf, len, HZ);
mutex_unlock(&dev->ctrl_urb_lock);
if (ret < 0)
return usb_translate_errors(ret);
if (dev->wait_after_write)
msleep(dev->wait_after_write);
return ret;
}
int em28xx_write_regs(struct em28xx *dev, u16 reg, char *buf, int len)
{
return em28xx_write_regs_req(dev, USB_REQ_GET_STATUS, reg, buf, len);
}
int em28xx_write_reg(struct em28xx *dev, u16 reg, u8 val)
{
return em28xx_write_regs(dev, reg, &val, 1);
}
int em28xx_write_reg_bits(struct em28xx *dev, u16 reg, u8 val,
u8 bitmask)
{
int oldval;
u8 newval;
oldval = em28xx_read_reg(dev, reg);
if (oldval < 0)
return oldval;
newval = (((u8) oldval) & ~bitmask) | (val & bitmask);
return em28xx_write_regs(dev, reg, &newval, 1);
}
int em28xx_toggle_reg_bits(struct em28xx *dev, u16 reg, u8 bitmask)
{
int oldval;
u8 newval;
oldval = em28xx_read_reg(dev, reg);
if (oldval < 0)
return oldval;
newval = (~oldval & bitmask) | (oldval & ~bitmask);
return em28xx_write_reg(dev, reg, newval);
}
static int em28xx_is_ac97_ready(struct em28xx *dev)
{
unsigned long timeout = jiffies + msecs_to_jiffies(EM28XX_AC97_XFER_TIMEOUT);
int ret;
while (time_is_after_jiffies(timeout)) {
ret = em28xx_read_reg(dev, EM28XX_R43_AC97BUSY);
if (ret < 0)
return ret;
if (!(ret & 0x01))
return 0;
msleep(5);
}
em28xx_warn("AC97 command still being executed: not handled properly!\n");
return -EBUSY;
}
int em28xx_read_ac97(struct em28xx *dev, u8 reg)
{
int ret;
u8 addr = (reg & 0x7f) | 0x80;
u16 val;
ret = em28xx_is_ac97_ready(dev);
if (ret < 0)
return ret;
ret = em28xx_write_regs(dev, EM28XX_R42_AC97ADDR, &addr, 1);
if (ret < 0)
return ret;
ret = dev->em28xx_read_reg_req_len(dev, 0, EM28XX_R40_AC97LSB,
(u8 *)&val, sizeof(val));
if (ret < 0)
return ret;
return le16_to_cpu(val);
}
int em28xx_write_ac97(struct em28xx *dev, u8 reg, u16 val)
{
int ret;
u8 addr = reg & 0x7f;
__le16 value;
value = cpu_to_le16(val);
ret = em28xx_is_ac97_ready(dev);
if (ret < 0)
return ret;
ret = em28xx_write_regs(dev, EM28XX_R40_AC97LSB, (u8 *) &value, 2);
if (ret < 0)
return ret;
ret = em28xx_write_regs(dev, EM28XX_R42_AC97ADDR, &addr, 1);
if (ret < 0)
return ret;
return 0;
}
static int set_ac97_input(struct em28xx *dev)
{
int ret, i;
enum em28xx_amux amux = dev->ctl_ainput;
if (amux == EM28XX_AMUX_VIDEO2)
amux = EM28XX_AMUX_VIDEO;
for (i = 0; i < ARRAY_SIZE(inputs); i++) {
if (amux == inputs[i].mux)
ret = em28xx_write_ac97(dev, inputs[i].reg, 0x0808);
else
ret = em28xx_write_ac97(dev, inputs[i].reg, 0x8000);
if (ret < 0)
em28xx_warn("couldn't setup AC97 register %d\n",
inputs[i].reg);
}
return 0;
}
static int em28xx_set_audio_source(struct em28xx *dev)
{
int ret;
u8 input;
if (dev->board.is_em2800) {
if (dev->ctl_ainput == EM28XX_AMUX_VIDEO)
input = EM2800_AUDIO_SRC_TUNER;
else
input = EM2800_AUDIO_SRC_LINE;
ret = em28xx_write_regs(dev, EM2800_R08_AUDIOSRC, &input, 1);
if (ret < 0)
return ret;
}
if (dev->board.has_msp34xx)
input = EM28XX_AUDIO_SRC_TUNER;
else {
switch (dev->ctl_ainput) {
case EM28XX_AMUX_VIDEO:
input = EM28XX_AUDIO_SRC_TUNER;
break;
default:
input = EM28XX_AUDIO_SRC_LINE;
break;
}
}
if (dev->board.mute_gpio && dev->mute)
em28xx_gpio_set(dev, dev->board.mute_gpio);
else
em28xx_gpio_set(dev, INPUT(dev->ctl_input)->gpio);
ret = em28xx_write_reg_bits(dev, EM28XX_R0E_AUDIOSRC, input, 0xc0);
if (ret < 0)
return ret;
msleep(5);
switch (dev->audio_mode.ac97) {
case EM28XX_NO_AC97:
break;
default:
ret = set_ac97_input(dev);
}
return ret;
}
int em28xx_audio_analog_set(struct em28xx *dev)
{
int ret, i;
u8 xclk;
if (!dev->audio_mode.has_audio)
return 0;
if (dev->audio_mode.ac97 != EM28XX_NO_AC97) {
for (i = 0; i < ARRAY_SIZE(outputs); i++) {
ret = em28xx_write_ac97(dev, outputs[i].reg, 0x8000);
if (ret < 0)
em28xx_warn("couldn't setup AC97 register %d\n",
outputs[i].reg);
}
}
xclk = dev->board.xclk & 0x7f;
if (!dev->mute)
xclk |= EM28XX_XCLK_AUDIO_UNMUTE;
ret = em28xx_write_reg(dev, EM28XX_R0F_XCLK, xclk);
if (ret < 0)
return ret;
msleep(10);
ret = em28xx_set_audio_source(dev);
if (dev->audio_mode.ac97 != EM28XX_NO_AC97) {
int vol;
em28xx_write_ac97(dev, AC97_POWERDOWN, 0x4200);
em28xx_write_ac97(dev, AC97_EXTENDED_STATUS, 0x0031);
em28xx_write_ac97(dev, AC97_PCM_LR_ADC_RATE, 0xbb80);
vol = (0x1f - dev->volume) | ((0x1f - dev->volume) << 8);
if (dev->mute)
vol |= 0x8000;
for (i = 0; i < ARRAY_SIZE(outputs); i++) {
if (dev->ctl_aoutput & outputs[i].mux)
ret = em28xx_write_ac97(dev, outputs[i].reg,
vol);
if (ret < 0)
em28xx_warn("couldn't setup AC97 register %d\n",
outputs[i].reg);
}
if (dev->ctl_aoutput & EM28XX_AOUT_PCM_IN) {
int sel = ac97_return_record_select(dev->ctl_aoutput);
sel |= (sel << 8);
em28xx_write_ac97(dev, AC97_REC_SEL, sel);
}
}
return ret;
}
int em28xx_audio_setup(struct em28xx *dev)
{
int vid1, vid2, feat, cfg;
u32 vid;
if (!dev->audio_mode.has_audio)
return 0;
cfg = em28xx_read_reg(dev, EM28XX_R00_CHIPCFG);
em28xx_info("Config register raw data: 0x%02x\n", cfg);
if (cfg < 0) {
cfg = EM28XX_CHIPCFG_AC97;
} else if ((cfg & EM28XX_CHIPCFG_AUDIOMASK) == 0x00) {
dev->has_alsa_audio = false;
dev->audio_mode.has_audio = false;
return 0;
} else if ((cfg & EM28XX_CHIPCFG_AUDIOMASK) != EM28XX_CHIPCFG_AC97) {
if (dev->chip_id < CHIP_ID_EM2860 &&
(cfg & EM28XX_CHIPCFG_AUDIOMASK) ==
EM2820_CHIPCFG_I2S_1_SAMPRATE)
dev->audio_mode.i2s_samplerates = 1;
else if (dev->chip_id >= CHIP_ID_EM2860 &&
(cfg & EM28XX_CHIPCFG_AUDIOMASK) ==
EM2860_CHIPCFG_I2S_5_SAMPRATES)
dev->audio_mode.i2s_samplerates = 5;
else
dev->audio_mode.i2s_samplerates = 3;
em28xx_info("I2S Audio (%d sample rate(s))\n",
dev->audio_mode.i2s_samplerates);
dev->audio_mode.ac97 = EM28XX_NO_AC97;
goto init_audio;
}
dev->audio_mode.ac97 = EM28XX_AC97_OTHER;
vid1 = em28xx_read_ac97(dev, AC97_VENDOR_ID1);
if (vid1 < 0) {
em28xx_warn("AC97 chip type couldn't be determined\n");
dev->audio_mode.ac97 = EM28XX_NO_AC97;
dev->has_alsa_audio = false;
dev->audio_mode.has_audio = false;
goto init_audio;
}
vid2 = em28xx_read_ac97(dev, AC97_VENDOR_ID2);
if (vid2 < 0)
goto init_audio;
vid = vid1 << 16 | vid2;
dev->audio_mode.ac97_vendor_id = vid;
em28xx_warn("AC97 vendor ID = 0x%08x\n", vid);
feat = em28xx_read_ac97(dev, AC97_RESET);
if (feat < 0)
goto init_audio;
dev->audio_mode.ac97_feat = feat;
em28xx_warn("AC97 features = 0x%04x\n", feat);
if (((vid == 0xffffffff) || (vid == 0x83847650)) && (feat == 0x6a90))
dev->audio_mode.ac97 = EM28XX_AC97_EM202;
else if ((vid >> 8) == 0x838476)
dev->audio_mode.ac97 = EM28XX_AC97_SIGMATEL;
init_audio:
switch (dev->audio_mode.ac97) {
case EM28XX_NO_AC97:
em28xx_info("No AC97 audio processor\n");
break;
case EM28XX_AC97_EM202:
em28xx_info("Empia 202 AC97 audio processor detected\n");
break;
case EM28XX_AC97_SIGMATEL:
em28xx_info("Sigmatel audio processor detected(stac 97%02x)\n",
dev->audio_mode.ac97_vendor_id & 0xff);
break;
case EM28XX_AC97_OTHER:
em28xx_warn("Unknown AC97 audio processor detected!\n");
break;
default:
break;
}
return em28xx_audio_analog_set(dev);
}
const struct em28xx_led *em28xx_find_led(struct em28xx *dev,
enum em28xx_led_role role)
{
if (dev->board.leds) {
u8 k = 0;
while (dev->board.leds[k].role >= 0 &&
dev->board.leds[k].role < EM28XX_NUM_LED_ROLES) {
if (dev->board.leds[k].role == role)
return &dev->board.leds[k];
k++;
}
}
return NULL;
}
int em28xx_capture_start(struct em28xx *dev, int start)
{
int rc;
const struct em28xx_led *led = NULL;
if (dev->chip_id == CHIP_ID_EM2874 ||
dev->chip_id == CHIP_ID_EM2884 ||
dev->chip_id == CHIP_ID_EM28174 ||
dev->chip_id == CHIP_ID_EM28178) {
rc = em28xx_write_reg_bits(dev, EM2874_R5F_TS_ENABLE,
start ?
EM2874_TS1_CAPTURE_ENABLE : 0x00,
EM2874_TS1_CAPTURE_ENABLE);
} else {
rc = em28xx_write_reg_bits(dev, EM28XX_R0C_USBSUSP,
start ? 0x10 : 0x00, 0x10);
if (rc < 0)
return rc;
if (start) {
if (dev->board.is_webcam)
rc = em28xx_write_reg(dev, 0x13, 0x0c);
rc = em28xx_write_reg(dev, 0x48, 0x00);
if (rc < 0)
return rc;
if (dev->mode == EM28XX_ANALOG_MODE)
rc = em28xx_write_reg(dev,
EM28XX_R12_VINENABLE, 0x67);
else
rc = em28xx_write_reg(dev,
EM28XX_R12_VINENABLE, 0x37);
if (rc < 0)
return rc;
msleep(6);
} else {
rc = em28xx_write_reg(dev, EM28XX_R12_VINENABLE, 0x27);
}
}
if (dev->mode == EM28XX_ANALOG_MODE)
led = em28xx_find_led(dev, EM28XX_LED_ANALOG_CAPTURING);
else
led = em28xx_find_led(dev, EM28XX_LED_DIGITAL_CAPTURING);
if (led)
em28xx_write_reg_bits(dev, led->gpio_reg,
(!start ^ led->inverted) ?
~led->gpio_mask : led->gpio_mask,
led->gpio_mask);
return rc;
}
int em28xx_gpio_set(struct em28xx *dev, struct em28xx_reg_seq *gpio)
{
int rc = 0;
if (!gpio)
return rc;
if (dev->mode != EM28XX_SUSPEND) {
em28xx_write_reg(dev, 0x48, 0x00);
if (dev->mode == EM28XX_ANALOG_MODE)
em28xx_write_reg(dev, EM28XX_R12_VINENABLE, 0x67);
else
em28xx_write_reg(dev, EM28XX_R12_VINENABLE, 0x37);
msleep(6);
}
while (gpio->sleep >= 0) {
if (gpio->reg >= 0) {
rc = em28xx_write_reg_bits(dev,
gpio->reg,
gpio->val,
gpio->mask);
if (rc < 0)
return rc;
}
if (gpio->sleep > 0)
msleep(gpio->sleep);
gpio++;
}
return rc;
}
int em28xx_set_mode(struct em28xx *dev, enum em28xx_mode set_mode)
{
if (dev->mode == set_mode)
return 0;
if (set_mode == EM28XX_SUSPEND) {
dev->mode = set_mode;
return em28xx_gpio_set(dev, dev->board.suspend_gpio);
}
dev->mode = set_mode;
if (dev->mode == EM28XX_DIGITAL_MODE)
return em28xx_gpio_set(dev, dev->board.dvb_gpio);
else
return em28xx_gpio_set(dev, INPUT(dev->ctl_input)->gpio);
}
static void em28xx_irq_callback(struct urb *urb)
{
struct em28xx *dev = urb->context;
int i;
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
em28xx_isocdbg("urb completition error %d.\n", urb->status);
break;
}
spin_lock(&dev->slock);
dev->usb_ctl.urb_data_copy(dev, urb);
spin_unlock(&dev->slock);
for (i = 0; i < urb->number_of_packets; i++) {
urb->iso_frame_desc[i].status = 0;
urb->iso_frame_desc[i].actual_length = 0;
}
urb->status = 0;
urb->status = usb_submit_urb(urb, GFP_ATOMIC);
if (urb->status) {
em28xx_isocdbg("urb resubmit failed (error=%i)\n",
urb->status);
}
}
void em28xx_uninit_usb_xfer(struct em28xx *dev, enum em28xx_mode mode)
{
struct urb *urb;
struct em28xx_usb_bufs *usb_bufs;
int i;
em28xx_isocdbg("em28xx: called em28xx_uninit_usb_xfer in mode %d\n",
mode);
if (mode == EM28XX_DIGITAL_MODE)
usb_bufs = &dev->usb_ctl.digital_bufs;
else
usb_bufs = &dev->usb_ctl.analog_bufs;
for (i = 0; i < usb_bufs->num_bufs; i++) {
urb = usb_bufs->urb[i];
if (urb) {
if (!irqs_disabled())
usb_kill_urb(urb);
else
usb_unlink_urb(urb);
if (usb_bufs->transfer_buffer[i]) {
usb_free_coherent(dev->udev,
urb->transfer_buffer_length,
usb_bufs->transfer_buffer[i],
urb->transfer_dma);
}
usb_free_urb(urb);
usb_bufs->urb[i] = NULL;
}
usb_bufs->transfer_buffer[i] = NULL;
}
kfree(usb_bufs->urb);
kfree(usb_bufs->transfer_buffer);
usb_bufs->urb = NULL;
usb_bufs->transfer_buffer = NULL;
usb_bufs->num_bufs = 0;
em28xx_capture_start(dev, 0);
}
void em28xx_stop_urbs(struct em28xx *dev)
{
int i;
struct urb *urb;
struct em28xx_usb_bufs *isoc_bufs = &dev->usb_ctl.digital_bufs;
em28xx_isocdbg("em28xx: called em28xx_stop_urbs\n");
for (i = 0; i < isoc_bufs->num_bufs; i++) {
urb = isoc_bufs->urb[i];
if (urb) {
if (!irqs_disabled())
usb_kill_urb(urb);
else
usb_unlink_urb(urb);
}
}
em28xx_capture_start(dev, 0);
}
int em28xx_alloc_urbs(struct em28xx *dev, enum em28xx_mode mode, int xfer_bulk,
int num_bufs, int max_pkt_size, int packet_multiplier)
{
struct em28xx_usb_bufs *usb_bufs;
int i;
int sb_size, pipe;
struct urb *urb;
int j, k;
em28xx_isocdbg("em28xx: called em28xx_alloc_isoc in mode %d\n", mode);
if (mode == EM28XX_DIGITAL_MODE) {
if ((xfer_bulk && !dev->dvb_ep_bulk) ||
(!xfer_bulk && !dev->dvb_ep_isoc)) {
em28xx_errdev("no endpoint for DVB mode and transfer type %d\n",
xfer_bulk > 0);
return -EINVAL;
}
usb_bufs = &dev->usb_ctl.digital_bufs;
} else if (mode == EM28XX_ANALOG_MODE) {
if ((xfer_bulk && !dev->analog_ep_bulk) ||
(!xfer_bulk && !dev->analog_ep_isoc)) {
em28xx_errdev("no endpoint for analog mode and transfer type %d\n",
xfer_bulk > 0);
return -EINVAL;
}
usb_bufs = &dev->usb_ctl.analog_bufs;
} else {
em28xx_errdev("invalid mode selected\n");
return -EINVAL;
}
em28xx_uninit_usb_xfer(dev, mode);
usb_bufs->num_bufs = num_bufs;
usb_bufs->urb = kzalloc(sizeof(void *)*num_bufs, GFP_KERNEL);
if (!usb_bufs->urb) {
em28xx_errdev("cannot alloc memory for usb buffers\n");
return -ENOMEM;
}
usb_bufs->transfer_buffer = kzalloc(sizeof(void *)*num_bufs,
GFP_KERNEL);
if (!usb_bufs->transfer_buffer) {
em28xx_errdev("cannot allocate memory for usb transfer\n");
kfree(usb_bufs->urb);
return -ENOMEM;
}
usb_bufs->max_pkt_size = max_pkt_size;
if (xfer_bulk)
usb_bufs->num_packets = 0;
else
usb_bufs->num_packets = packet_multiplier;
dev->usb_ctl.vid_buf = NULL;
dev->usb_ctl.vbi_buf = NULL;
sb_size = packet_multiplier * usb_bufs->max_pkt_size;
for (i = 0; i < usb_bufs->num_bufs; i++) {
urb = usb_alloc_urb(usb_bufs->num_packets, GFP_KERNEL);
if (!urb) {
em28xx_err("cannot alloc usb_ctl.urb %i\n", i);
em28xx_uninit_usb_xfer(dev, mode);
return -ENOMEM;
}
usb_bufs->urb[i] = urb;
usb_bufs->transfer_buffer[i] = usb_alloc_coherent(dev->udev,
sb_size, GFP_KERNEL, &urb->transfer_dma);
if (!usb_bufs->transfer_buffer[i]) {
em28xx_err("unable to allocate %i bytes for transfer"
" buffer %i%s\n",
sb_size, i,
in_interrupt() ? " while in int" : "");
em28xx_uninit_usb_xfer(dev, mode);
return -ENOMEM;
}
memset(usb_bufs->transfer_buffer[i], 0, sb_size);
if (xfer_bulk) {
pipe = usb_rcvbulkpipe(dev->udev,
mode == EM28XX_ANALOG_MODE ?
dev->analog_ep_bulk :
dev->dvb_ep_bulk);
usb_fill_bulk_urb(urb, dev->udev, pipe,
usb_bufs->transfer_buffer[i], sb_size,
em28xx_irq_callback, dev);
urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
} else {
pipe = usb_rcvisocpipe(dev->udev,
mode == EM28XX_ANALOG_MODE ?
dev->analog_ep_isoc :
dev->dvb_ep_isoc);
usb_fill_int_urb(urb, dev->udev, pipe,
usb_bufs->transfer_buffer[i], sb_size,
em28xx_irq_callback, dev, 1);
urb->transfer_flags = URB_ISO_ASAP |
URB_NO_TRANSFER_DMA_MAP;
k = 0;
for (j = 0; j < usb_bufs->num_packets; j++) {
urb->iso_frame_desc[j].offset = k;
urb->iso_frame_desc[j].length =
usb_bufs->max_pkt_size;
k += usb_bufs->max_pkt_size;
}
}
urb->number_of_packets = usb_bufs->num_packets;
}
return 0;
}
int em28xx_init_usb_xfer(struct em28xx *dev, enum em28xx_mode mode,
int xfer_bulk, int num_bufs, int max_pkt_size,
int packet_multiplier,
int (*urb_data_copy) (struct em28xx *dev, struct urb *urb))
{
struct em28xx_dmaqueue *dma_q = &dev->vidq;
struct em28xx_dmaqueue *vbi_dma_q = &dev->vbiq;
struct em28xx_usb_bufs *usb_bufs;
int i;
int rc;
int alloc;
em28xx_isocdbg("em28xx: called em28xx_init_usb_xfer in mode %d\n",
mode);
dev->usb_ctl.urb_data_copy = urb_data_copy;
if (mode == EM28XX_DIGITAL_MODE) {
usb_bufs = &dev->usb_ctl.digital_bufs;
alloc = 0;
} else {
usb_bufs = &dev->usb_ctl.analog_bufs;
alloc = 1;
}
if (alloc) {
rc = em28xx_alloc_urbs(dev, mode, xfer_bulk, num_bufs,
max_pkt_size, packet_multiplier);
if (rc)
return rc;
}
if (xfer_bulk) {
rc = usb_clear_halt(dev->udev, usb_bufs->urb[0]->pipe);
if (rc < 0) {
em28xx_err("failed to clear USB bulk endpoint stall/halt condition (error=%i)\n",
rc);
em28xx_uninit_usb_xfer(dev, mode);
return rc;
}
}
init_waitqueue_head(&dma_q->wq);
init_waitqueue_head(&vbi_dma_q->wq);
em28xx_capture_start(dev, 1);
for (i = 0; i < usb_bufs->num_bufs; i++) {
rc = usb_submit_urb(usb_bufs->urb[i], GFP_ATOMIC);
if (rc) {
em28xx_err("submit of urb %i failed (error=%i)\n", i,
rc);
em28xx_uninit_usb_xfer(dev, mode);
return rc;
}
}
return 0;
}
int em28xx_register_extension(struct em28xx_ops *ops)
{
struct em28xx *dev = NULL;
mutex_lock(&em28xx_devlist_mutex);
list_add_tail(&ops->next, &em28xx_extension_devlist);
list_for_each_entry(dev, &em28xx_devlist, devlist) {
ops->init(dev);
}
mutex_unlock(&em28xx_devlist_mutex);
printk(KERN_INFO "em28xx: Registered (%s) extension\n", ops->name);
return 0;
}
void em28xx_unregister_extension(struct em28xx_ops *ops)
{
struct em28xx *dev = NULL;
mutex_lock(&em28xx_devlist_mutex);
list_for_each_entry(dev, &em28xx_devlist, devlist) {
ops->fini(dev);
}
list_del(&ops->next);
mutex_unlock(&em28xx_devlist_mutex);
printk(KERN_INFO "Em28xx: Removed (%s) extension\n", ops->name);
}
void em28xx_init_extension(struct em28xx *dev)
{
const struct em28xx_ops *ops = NULL;
mutex_lock(&em28xx_devlist_mutex);
list_add_tail(&dev->devlist, &em28xx_devlist);
list_for_each_entry(ops, &em28xx_extension_devlist, next) {
if (ops->init)
ops->init(dev);
}
mutex_unlock(&em28xx_devlist_mutex);
}
void em28xx_close_extension(struct em28xx *dev)
{
const struct em28xx_ops *ops = NULL;
mutex_lock(&em28xx_devlist_mutex);
list_for_each_entry(ops, &em28xx_extension_devlist, next) {
if (ops->fini)
ops->fini(dev);
}
list_del(&dev->devlist);
mutex_unlock(&em28xx_devlist_mutex);
}
int em28xx_suspend_extension(struct em28xx *dev)
{
const struct em28xx_ops *ops = NULL;
em28xx_info("Suspending extensions");
mutex_lock(&em28xx_devlist_mutex);
list_for_each_entry(ops, &em28xx_extension_devlist, next) {
if (ops->suspend)
ops->suspend(dev);
}
mutex_unlock(&em28xx_devlist_mutex);
return 0;
}
int em28xx_resume_extension(struct em28xx *dev)
{
const struct em28xx_ops *ops = NULL;
em28xx_info("Resuming extensions");
mutex_lock(&em28xx_devlist_mutex);
list_for_each_entry(ops, &em28xx_extension_devlist, next) {
if (ops->resume)
ops->resume(dev);
}
mutex_unlock(&em28xx_devlist_mutex);
return 0;
}
