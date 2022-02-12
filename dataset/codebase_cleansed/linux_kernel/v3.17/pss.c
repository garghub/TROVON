static void pss_write(struct pss_confdata *devc, int data)
{
unsigned long i, limit;
limit = jiffies + HZ/10;
for (i = 0; i < 5000000 && time_before(jiffies, limit); i++)
{
if (inw(REG(PSS_STATUS)) & PSS_WRITE_EMPTY)
{
outw(data, REG(PSS_DATA));
return;
}
}
printk(KERN_WARNING "PSS: DSP Command (%04x) Timeout.\n", data);
}
static int __init probe_pss(struct address_info *hw_config)
{
unsigned short id;
int irq, dma;
devc->base = hw_config->io_base;
irq = devc->irq = hw_config->irq;
dma = devc->dma = hw_config->dma;
devc->osp = hw_config->osp;
if (devc->base != 0x220 && devc->base != 0x240)
if (devc->base != 0x230 && devc->base != 0x250)
return 0;
if (!request_region(devc->base, 0x10, "PSS mixer, SB emulation")) {
printk(KERN_ERR "PSS: I/O port conflict\n");
return 0;
}
id = inw(REG(PSS_ID));
if ((id >> 8) != 'E') {
printk(KERN_ERR "No PSS signature detected at 0x%x (0x%x)\n", devc->base, id);
release_region(devc->base, 0x10);
return 0;
}
if (!request_region(devc->base + 0x10, 0x9, "PSS config")) {
printk(KERN_ERR "PSS: I/O port conflict\n");
release_region(devc->base, 0x10);
return 0;
}
return 1;
}
static int set_irq(struct pss_confdata *devc, int dev, int irq)
{
static unsigned short irq_bits[16] =
{
0x0000, 0x0000, 0x0000, 0x0008,
0x0000, 0x0010, 0x0000, 0x0018,
0x0000, 0x0020, 0x0028, 0x0030,
0x0038, 0x0000, 0x0000, 0x0000
};
unsigned short tmp, bits;
if (irq < 0 || irq > 15)
return 0;
tmp = inw(REG(dev)) & ~0x38;
if ((bits = irq_bits[irq]) == 0 && irq != 0)
{
printk(KERN_ERR "PSS: Invalid IRQ %d\n", irq);
return 0;
}
outw(tmp | bits, REG(dev));
return 1;
}
static void set_io_base(struct pss_confdata *devc, int dev, int base)
{
unsigned short tmp = inw(REG(dev)) & 0x003f;
unsigned short bits = (base & 0x0ffc) << 4;
outw(bits | tmp, REG(dev));
}
static int set_dma(struct pss_confdata *devc, int dev, int dma)
{
static unsigned short dma_bits[8] =
{
0x0001, 0x0002, 0x0000, 0x0003,
0x0000, 0x0005, 0x0006, 0x0007
};
unsigned short tmp, bits;
if (dma < 0 || dma > 7)
return 0;
tmp = inw(REG(dev)) & ~0x07;
if ((bits = dma_bits[dma]) == 0 && dma != 4)
{
printk(KERN_ERR "PSS: Invalid DMA %d\n", dma);
return 0;
}
outw(tmp | bits, REG(dev));
return 1;
}
static int pss_reset_dsp(struct pss_confdata *devc)
{
unsigned long i, limit = jiffies + HZ/10;
outw(0x2000, REG(PSS_CONTROL));
for (i = 0; i < 32768 && time_after_eq(limit, jiffies); i++)
inw(REG(PSS_CONTROL));
outw(0x0000, REG(PSS_CONTROL));
return 1;
}
static int pss_put_dspword(struct pss_confdata *devc, unsigned short word)
{
int i, val;
for (i = 0; i < 327680; i++)
{
val = inw(REG(PSS_STATUS));
if (val & PSS_WRITE_EMPTY)
{
outw(word, REG(PSS_DATA));
return 1;
}
}
return 0;
}
static int pss_get_dspword(struct pss_confdata *devc, unsigned short *word)
{
int i, val;
for (i = 0; i < 327680; i++)
{
val = inw(REG(PSS_STATUS));
if (val & PSS_READ_FULL)
{
*word = inw(REG(PSS_DATA));
return 1;
}
}
return 0;
}
static int pss_download_boot(struct pss_confdata *devc, unsigned char *block,
int size, int flags)
{
int i, val, count;
unsigned long limit;
if (flags & CPF_FIRST)
{
outw(0x00fe, REG(PSS_DATA));
limit = jiffies + HZ/10;
for (i = 0; i < 32768 && time_before(jiffies, limit); i++)
if (inw(REG(PSS_DATA)) == 0x5500)
break;
outw(*block++, REG(PSS_DATA));
pss_reset_dsp(devc);
}
count = 1;
while ((flags&CPF_LAST) || count<size )
{
int j;
for (j = 0; j < 327670; j++)
{
if (inw(REG(PSS_STATUS)) & PSS_FLAG3)
break;
}
if (j == 327670)
{
if (count >= size && flags & CPF_LAST)
break;
else
{
printk("\n");
printk(KERN_ERR "PSS: Download timeout problems, byte %d=%d\n", count, size);
return 0;
}
}
if (count >= size)
{
outw (0xffff, REG (PSS_DATA));
}
else
{
outw (*block++, REG (PSS_DATA));
}
count++;
}
if (flags & CPF_LAST)
{
outw(0, REG(PSS_DATA));
limit = jiffies + HZ/10;
for (i = 0; i < 32768 && time_after_eq(limit, jiffies); i++)
val = inw(REG(PSS_STATUS));
limit = jiffies + HZ/10;
for (i = 0; i < 32768 && time_after_eq(limit, jiffies); i++)
{
val = inw(REG(PSS_STATUS));
if (val & 0x4000)
break;
}
for (i = 0; i < 32000; i++)
{
val = inw(REG(PSS_STATUS));
if (val & PSS_READ_FULL)
break;
}
if (i == 32000)
return 0;
val = inw(REG(PSS_DATA));
}
return 1;
}
static void set_master_volume(struct pss_confdata *devc, int left, int right)
{
static unsigned char log_scale[101] = {
0xdb, 0xe0, 0xe3, 0xe5, 0xe7, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xed, 0xee,
0xef, 0xef, 0xf0, 0xf0, 0xf1, 0xf1, 0xf2, 0xf2, 0xf2, 0xf3, 0xf3, 0xf3,
0xf4, 0xf4, 0xf4, 0xf5, 0xf5, 0xf5, 0xf5, 0xf6, 0xf6, 0xf6, 0xf6, 0xf7,
0xf7, 0xf7, 0xf7, 0xf7, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf9, 0xf9, 0xf9,
0xf9, 0xf9, 0xf9, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 0xfa, 0xfb, 0xfb,
0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
0xfc, 0xfc, 0xfc, 0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
0xfe, 0xfe, 0xff, 0xff, 0xff
};
pss_write(devc, 0x0010);
pss_write(devc, log_scale[left] | 0x0000);
pss_write(devc, 0x0010);
pss_write(devc, log_scale[right] | 0x0100);
}
static void set_synth_volume(struct pss_confdata *devc, int volume)
{
int vol = ((0x8000*volume)/100L);
pss_write(devc, 0x0080);
pss_write(devc, vol);
pss_write(devc, 0x0081);
pss_write(devc, vol);
}
static void set_bass(struct pss_confdata *devc, int level)
{
int vol = (int)(((0xfd - 0xf0) * level)/100L) + 0xf0;
pss_write(devc, 0x0010);
pss_write(devc, vol | 0x0200);
}
static void set_treble(struct pss_confdata *devc, int level)
{
int vol = (((0xfd - 0xf0) * level)/100L) + 0xf0;
pss_write(devc, 0x0010);
pss_write(devc, vol | 0x0300);
}
static void pss_mixer_reset(struct pss_confdata *devc)
{
set_master_volume(devc, 33, 33);
set_bass(devc, 50);
set_treble(devc, 50);
set_synth_volume(devc, 30);
pss_write (devc, 0x0010);
pss_write (devc, 0x0800 | 0xce);
if(pss_mixer)
{
devc->mixer.volume_l = devc->mixer.volume_r = 33;
devc->mixer.bass = 50;
devc->mixer.treble = 50;
devc->mixer.synth = 30;
}
}
static int set_volume_mono(unsigned __user *p, unsigned int *aleft)
{
unsigned int left, volume;
if (get_user(volume, p))
return -EFAULT;
left = volume & 0xff;
if (left > 100)
left = 100;
*aleft = left;
return 0;
}
static int set_volume_stereo(unsigned __user *p,
unsigned int *aleft,
unsigned int *aright)
{
unsigned int left, right, volume;
if (get_user(volume, p))
return -EFAULT;
left = volume & 0xff;
if (left > 100)
left = 100;
right = (volume >> 8) & 0xff;
if (right > 100)
right = 100;
*aleft = left;
*aright = right;
return 0;
}
static int ret_vol_mono(int left)
{
return ((left << 8) | left);
}
static int ret_vol_stereo(int left, int right)
{
return ((right << 8) | left);
}
static int call_ad_mixer(struct pss_confdata *devc, unsigned int cmd,
void __user *arg)
{
if (devc->ad_mixer_dev != NO_WSS_MIXER)
return mixer_devs[devc->ad_mixer_dev]->ioctl(devc->ad_mixer_dev, cmd, arg);
else
return -EINVAL;
}
static int pss_mixer_ioctl (int dev, unsigned int cmd, void __user *arg)
{
struct pss_confdata *devc = mixer_devs[dev]->devc;
int cmdf = cmd & 0xff;
if ((cmdf != SOUND_MIXER_VOLUME) && (cmdf != SOUND_MIXER_BASS) &&
(cmdf != SOUND_MIXER_TREBLE) && (cmdf != SOUND_MIXER_SYNTH) &&
(cmdf != SOUND_MIXER_DEVMASK) && (cmdf != SOUND_MIXER_STEREODEVS) &&
(cmdf != SOUND_MIXER_RECMASK) && (cmdf != SOUND_MIXER_CAPS) &&
(cmdf != SOUND_MIXER_RECSRC))
{
return call_ad_mixer(devc, cmd, arg);
}
if (((cmd >> 8) & 0xff) != 'M')
return -EINVAL;
if (_SIOC_DIR (cmd) & _SIOC_WRITE)
{
switch (cmdf)
{
case SOUND_MIXER_RECSRC:
if (devc->ad_mixer_dev != NO_WSS_MIXER)
return call_ad_mixer(devc, cmd, arg);
else
{
int v;
if (get_user(v, (int __user *)arg))
return -EFAULT;
if (v != 0)
return -EINVAL;
return 0;
}
case SOUND_MIXER_VOLUME:
if (set_volume_stereo(arg,
&devc->mixer.volume_l,
&devc->mixer.volume_r))
return -EFAULT;
set_master_volume(devc, devc->mixer.volume_l,
devc->mixer.volume_r);
return ret_vol_stereo(devc->mixer.volume_l,
devc->mixer.volume_r);
case SOUND_MIXER_BASS:
if (set_volume_mono(arg, &devc->mixer.bass))
return -EFAULT;
set_bass(devc, devc->mixer.bass);
return ret_vol_mono(devc->mixer.bass);
case SOUND_MIXER_TREBLE:
if (set_volume_mono(arg, &devc->mixer.treble))
return -EFAULT;
set_treble(devc, devc->mixer.treble);
return ret_vol_mono(devc->mixer.treble);
case SOUND_MIXER_SYNTH:
if (set_volume_mono(arg, &devc->mixer.synth))
return -EFAULT;
set_synth_volume(devc, devc->mixer.synth);
return ret_vol_mono(devc->mixer.synth);
default:
return -EINVAL;
}
}
else
{
int val, and_mask = 0, or_mask = 0;
switch (cmdf)
{
case SOUND_MIXER_DEVMASK:
if (call_ad_mixer(devc, cmd, arg) == -EINVAL)
break;
and_mask = ~0;
or_mask = SOUND_MASK_VOLUME | SOUND_MASK_BASS | SOUND_MASK_TREBLE | SOUND_MASK_SYNTH;
break;
case SOUND_MIXER_STEREODEVS:
if (call_ad_mixer(devc, cmd, arg) == -EINVAL)
break;
and_mask = ~0;
or_mask = SOUND_MASK_VOLUME;
break;
case SOUND_MIXER_RECMASK:
if (devc->ad_mixer_dev != NO_WSS_MIXER)
return call_ad_mixer(devc, cmd, arg);
break;
case SOUND_MIXER_CAPS:
if (devc->ad_mixer_dev != NO_WSS_MIXER)
return call_ad_mixer(devc, cmd, arg);
or_mask = SOUND_CAP_EXCL_INPUT;
break;
case SOUND_MIXER_RECSRC:
if (devc->ad_mixer_dev != NO_WSS_MIXER)
return call_ad_mixer(devc, cmd, arg);
break;
case SOUND_MIXER_VOLUME:
or_mask = ret_vol_stereo(devc->mixer.volume_l, devc->mixer.volume_r);
break;
case SOUND_MIXER_BASS:
or_mask = ret_vol_mono(devc->mixer.bass);
break;
case SOUND_MIXER_TREBLE:
or_mask = ret_vol_mono(devc->mixer.treble);
break;
case SOUND_MIXER_SYNTH:
or_mask = ret_vol_mono(devc->mixer.synth);
break;
default:
return -EINVAL;
}
if (get_user(val, (int __user *)arg))
return -EFAULT;
val &= and_mask;
val |= or_mask;
if (put_user(val, (int __user *)arg))
return -EFAULT;
return val;
}
}
static void disable_all_emulations(void)
{
outw(0x0000, REG(CONF_PSS));
outw(0x0000, REG(CONF_WSS));
outw(0x0000, REG(CONF_SB));
outw(0x0000, REG(CONF_MIDI));
outw(0x0000, REG(CONF_CDROM));
}
static void configure_nonsound_components(void)
{
if(pss_enable_joystick)
{
outw(0x0400, REG(CONF_PSS));
printk(KERN_INFO "PSS: joystick enabled.\n");
}
else
{
printk(KERN_INFO "PSS: joystick port not enabled.\n");
}
if (pss_cdrom_port == -1) {
printk(KERN_INFO "PSS: CDROM port not enabled.\n");
} else if (!request_region(pss_cdrom_port, 2, "PSS CDROM")) {
pss_cdrom_port = -1;
printk(KERN_ERR "PSS: CDROM I/O port conflict.\n");
} else {
set_io_base(devc, CONF_CDROM, pss_cdrom_port);
printk(KERN_INFO "PSS: CDROM I/O port set to 0x%x.\n", pss_cdrom_port);
}
}
static int __init attach_pss(struct address_info *hw_config)
{
unsigned short id;
char tmp[100];
devc->base = hw_config->io_base;
devc->irq = hw_config->irq;
devc->dma = hw_config->dma;
devc->osp = hw_config->osp;
devc->ad_mixer_dev = NO_WSS_MIXER;
if (!probe_pss(hw_config))
return 0;
id = inw(REG(PSS_ID)) & 0x00ff;
disable_all_emulations();
#ifdef YOU_REALLY_WANT_TO_ALLOCATE_THESE_RESOURCES
if (sound_alloc_dma(hw_config->dma, "PSS"))
{
printk("pss.c: Can't allocate DMA channel.\n");
release_region(hw_config->io_base, 0x10);
release_region(hw_config->io_base+0x10, 0x9);
return 0;
}
if (!set_irq(devc, CONF_PSS, devc->irq))
{
printk("PSS: IRQ allocation error.\n");
release_region(hw_config->io_base, 0x10);
release_region(hw_config->io_base+0x10, 0x9);
return 0;
}
if (!set_dma(devc, CONF_PSS, devc->dma))
{
printk(KERN_ERR "PSS: DMA allocation error\n");
release_region(hw_config->io_base, 0x10);
release_region(hw_config->io_base+0x10, 0x9);
return 0;
}
#endif
configure_nonsound_components();
pss_initialized = 1;
sprintf(tmp, "ECHO-PSS Rev. %d", id);
conf_printf(tmp, hw_config);
return 1;
}
static int __init probe_pss_mpu(struct address_info *hw_config)
{
struct resource *ports;
int timeout;
if (!pss_initialized)
return 0;
ports = request_region(hw_config->io_base, 2, "mpu401");
if (!ports) {
printk(KERN_ERR "PSS: MPU I/O port conflict\n");
return 0;
}
set_io_base(devc, CONF_MIDI, hw_config->io_base);
if (!set_irq(devc, CONF_MIDI, hw_config->irq)) {
printk(KERN_ERR "PSS: MIDI IRQ allocation error.\n");
goto fail;
}
if (!pss_synthLen) {
printk(KERN_ERR "PSS: Can't enable MPU. MIDI synth microcode not available.\n");
goto fail;
}
if (!pss_download_boot(devc, pss_synth, pss_synthLen, CPF_FIRST | CPF_LAST)) {
printk(KERN_ERR "PSS: Unable to load MIDI synth microcode to DSP.\n");
goto fail;
}
for (timeout = 900000; timeout > 0; timeout--)
{
if ((inb(hw_config->io_base + 1) & 0x80) == 0)
inb(hw_config->io_base);
else
break;
}
if (!probe_mpu401(hw_config, ports))
goto fail;
attach_mpu401(hw_config, THIS_MODULE);
if (hw_config->slots[1] != -1)
midi_devs[hw_config->slots[1]]->coproc = &pss_coproc_operations;
return 1;
fail:
release_region(hw_config->io_base, 2);
return 0;
}
static int pss_coproc_open(void *dev_info, int sub_device)
{
switch (sub_device)
{
case COPR_MIDI:
if (pss_synthLen == 0)
{
printk(KERN_ERR "PSS: MIDI synth microcode not available.\n");
return -EIO;
}
if (nonstandard_microcode)
if (!pss_download_boot(devc, pss_synth, pss_synthLen, CPF_FIRST | CPF_LAST))
{
printk(KERN_ERR "PSS: Unable to load MIDI synth microcode to DSP.\n");
return -EIO;
}
nonstandard_microcode = 0;
break;
default:
break;
}
return 0;
}
static void pss_coproc_close(void *dev_info, int sub_device)
{
return;
}
static void pss_coproc_reset(void *dev_info)
{
if (pss_synthLen)
if (!pss_download_boot(devc, pss_synth, pss_synthLen, CPF_FIRST | CPF_LAST))
{
printk(KERN_ERR "PSS: Unable to load MIDI synth microcode to DSP.\n");
}
nonstandard_microcode = 0;
}
static int download_boot_block(void *dev_info, copr_buffer * buf)
{
if (buf->len <= 0 || buf->len > sizeof(buf->data))
return -EINVAL;
if (!pss_download_boot(devc, buf->data, buf->len, buf->flags))
{
printk(KERN_ERR "PSS: Unable to load microcode block to DSP.\n");
return -EIO;
}
nonstandard_microcode = 1;
return 0;
}
static int pss_coproc_ioctl(void *dev_info, unsigned int cmd, void __user *arg, int local)
{
copr_buffer *buf;
copr_msg *mbuf;
copr_debug_buf dbuf;
unsigned short tmp;
unsigned long flags;
unsigned short *data;
int i, err;
switch (cmd)
{
case SNDCTL_COPR_RESET:
pss_coproc_reset(dev_info);
return 0;
case SNDCTL_COPR_LOAD:
buf = vmalloc(sizeof(copr_buffer));
if (buf == NULL)
return -ENOSPC;
if (copy_from_user(buf, arg, sizeof(copr_buffer))) {
vfree(buf);
return -EFAULT;
}
err = download_boot_block(dev_info, buf);
vfree(buf);
return err;
case SNDCTL_COPR_SENDMSG:
mbuf = vmalloc(sizeof(copr_msg));
if (mbuf == NULL)
return -ENOSPC;
if (copy_from_user(mbuf, arg, sizeof(copr_msg))) {
vfree(mbuf);
return -EFAULT;
}
data = (unsigned short *)(mbuf->data);
spin_lock_irqsave(&lock, flags);
for (i = 0; i < mbuf->len; i++) {
if (!pss_put_dspword(devc, *data++)) {
spin_unlock_irqrestore(&lock,flags);
mbuf->len = i;
err = copy_to_user(arg, mbuf, sizeof(copr_msg));
vfree(mbuf);
return err ? -EFAULT : -EIO;
}
}
spin_unlock_irqrestore(&lock,flags);
vfree(mbuf);
return 0;
case SNDCTL_COPR_RCVMSG:
err = 0;
mbuf = vmalloc(sizeof(copr_msg));
if (mbuf == NULL)
return -ENOSPC;
data = (unsigned short *)mbuf->data;
spin_lock_irqsave(&lock, flags);
for (i = 0; i < sizeof(mbuf->data)/sizeof(unsigned short); i++) {
mbuf->len = i;
if (!pss_get_dspword(devc, data++)) {
if (i == 0)
err = -EIO;
break;
}
}
spin_unlock_irqrestore(&lock,flags);
if (copy_to_user(arg, mbuf, sizeof(copr_msg)))
err = -EFAULT;
vfree(mbuf);
return err;
case SNDCTL_COPR_RDATA:
if (copy_from_user(&dbuf, arg, sizeof(dbuf)))
return -EFAULT;
spin_lock_irqsave(&lock, flags);
if (!pss_put_dspword(devc, 0x00d0)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
if (!pss_put_dspword(devc, (unsigned short)(dbuf.parm1 & 0xffff))) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
if (!pss_get_dspword(devc, &tmp)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
dbuf.parm1 = tmp;
spin_unlock_irqrestore(&lock,flags);
if (copy_to_user(arg, &dbuf, sizeof(dbuf)))
return -EFAULT;
return 0;
case SNDCTL_COPR_WDATA:
if (copy_from_user(&dbuf, arg, sizeof(dbuf)))
return -EFAULT;
spin_lock_irqsave(&lock, flags);
if (!pss_put_dspword(devc, 0x00d1)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
if (!pss_put_dspword(devc, (unsigned short) (dbuf.parm1 & 0xffff))) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
tmp = (unsigned int)dbuf.parm2 & 0xffff;
if (!pss_put_dspword(devc, tmp)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
spin_unlock_irqrestore(&lock,flags);
return 0;
case SNDCTL_COPR_WCODE:
if (copy_from_user(&dbuf, arg, sizeof(dbuf)))
return -EFAULT;
spin_lock_irqsave(&lock, flags);
if (!pss_put_dspword(devc, 0x00d3)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
if (!pss_put_dspword(devc, (unsigned short)(dbuf.parm1 & 0xffff))) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
tmp = (unsigned int)dbuf.parm2 & 0x00ff;
if (!pss_put_dspword(devc, tmp)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
tmp = ((unsigned int)dbuf.parm2 >> 8) & 0xffff;
if (!pss_put_dspword(devc, tmp)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
spin_unlock_irqrestore(&lock,flags);
return 0;
case SNDCTL_COPR_RCODE:
if (copy_from_user(&dbuf, arg, sizeof(dbuf)))
return -EFAULT;
spin_lock_irqsave(&lock, flags);
if (!pss_put_dspword(devc, 0x00d2)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
if (!pss_put_dspword(devc, (unsigned short)(dbuf.parm1 & 0xffff))) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
if (!pss_get_dspword(devc, &tmp)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
dbuf.parm1 = tmp << 8;
if (!pss_get_dspword(devc, &tmp)) {
spin_unlock_irqrestore(&lock,flags);
return -EIO;
}
dbuf.parm1 |= tmp & 0x00ff;
spin_unlock_irqrestore(&lock,flags);
if (copy_to_user(arg, &dbuf, sizeof(dbuf)))
return -EFAULT;
return 0;
default:
return -EINVAL;
}
return -EINVAL;
}
static int __init probe_pss_mss(struct address_info *hw_config)
{
volatile int timeout;
struct resource *ports;
int my_mix = -999;
if (!pss_initialized)
return 0;
if (!request_region(hw_config->io_base, 4, "WSS config")) {
printk(KERN_ERR "PSS: WSS I/O port conflicts.\n");
return 0;
}
ports = request_region(hw_config->io_base + 4, 4, "ad1848");
if (!ports) {
printk(KERN_ERR "PSS: WSS I/O port conflicts.\n");
release_region(hw_config->io_base, 4);
return 0;
}
set_io_base(devc, CONF_WSS, hw_config->io_base);
if (!set_irq(devc, CONF_WSS, hw_config->irq)) {
printk("PSS: WSS IRQ allocation error.\n");
goto fail;
}
if (!set_dma(devc, CONF_WSS, hw_config->dma)) {
printk(KERN_ERR "PSS: WSS DMA allocation error\n");
goto fail;
}
for (timeout = 0; timeout < 100000 && (inb(hw_config->io_base + WSS_INDEX) &
WSS_INITIALIZING); timeout++)
;
outb((0x0b), hw_config->io_base + WSS_INDEX);
for (timeout = 0; (inb(hw_config->io_base + WSS_DATA) & WSS_AUTOCALIBRATION) &&
(timeout < 100000); timeout++)
;
if (!probe_ms_sound(hw_config, ports))
goto fail;
devc->ad_mixer_dev = NO_WSS_MIXER;
if (pss_mixer)
{
if ((my_mix = sound_install_mixer (MIXER_DRIVER_VERSION,
"PSS-SPEAKERS and AD1848 (through MSS audio codec)",
&pss_mixer_operations,
sizeof (struct mixer_operations),
devc)) < 0)
{
printk(KERN_ERR "Could not install PSS mixer\n");
goto fail;
}
}
pss_mixer_reset(devc);
attach_ms_sound(hw_config, ports, THIS_MODULE);
if (hw_config->slots[0] != -1)
{
audio_devs[hw_config->slots[0]]->coproc = &pss_coproc_operations;
if (pss_mixer && (num_mixers == (my_mix + 2)))
{
devc->ad_mixer_dev = audio_devs[hw_config->slots[0]]->mixer_dev;
}
}
return 1;
fail:
release_region(hw_config->io_base + 4, 4);
release_region(hw_config->io_base, 4);
return 0;
}
static inline void __exit unload_pss(struct address_info *hw_config)
{
release_region(hw_config->io_base, 0x10);
release_region(hw_config->io_base+0x10, 0x9);
}
static inline void __exit unload_pss_mpu(struct address_info *hw_config)
{
unload_mpu401(hw_config);
}
static inline void __exit unload_pss_mss(struct address_info *hw_config)
{
unload_ms_sound(hw_config);
}
static int __init init_pss(void)
{
if(pss_no_sound)
{
cfg.io_base = pss_io;
if(!probe_pss(&cfg))
return -ENODEV;
printk(KERN_INFO "ECHO-PSS Rev. %d\n", inw(REG(PSS_ID)) & 0x00ff);
printk(KERN_INFO "PSS: loading in no sound mode.\n");
disable_all_emulations();
configure_nonsound_components();
release_region(pss_io, 0x10);
release_region(pss_io + 0x10, 0x9);
return 0;
}
cfg.io_base = pss_io;
cfg2.io_base = mss_io;
cfg2.irq = mss_irq;
cfg2.dma = mss_dma;
cfg_mpu.io_base = mpu_io;
cfg_mpu.irq = mpu_irq;
if (cfg.io_base == -1 || cfg2.io_base == -1 || cfg2.irq == -1 || cfg.dma == -1) {
printk(KERN_INFO "pss: mss_io, mss_dma, mss_irq and pss_io must be set.\n");
return -EINVAL;
}
if (!pss_synth) {
fw_load = 1;
pss_synthLen = mod_firmware_load(pss_firmware, (void *) &pss_synth);
}
if (!attach_pss(&cfg))
return -ENODEV;
if (probe_pss_mpu(&cfg_mpu))
pssmpu = 1;
if (probe_pss_mss(&cfg2))
pssmss = 1;
return 0;
}
static void __exit cleanup_pss(void)
{
if(!pss_no_sound)
{
if(fw_load && pss_synth)
vfree(pss_synth);
if(pssmss)
unload_pss_mss(&cfg2);
if(pssmpu)
unload_pss_mpu(&cfg_mpu);
unload_pss(&cfg);
} else if (pss_cdrom_port != -1)
release_region(pss_cdrom_port, 2);
if(!pss_keep_settings)
{
disable_all_emulations();
printk(KERN_INFO "Resetting PSS sound card configurations.\n");
}
}
static int __init setup_pss(char *str)
{
int ints[7];
str = get_options(str, ARRAY_SIZE(ints), ints);
pss_io = ints[1];
mss_io = ints[2];
mss_irq = ints[3];
mss_dma = ints[4];
mpu_io = ints[5];
mpu_irq = ints[6];
return 1;
}
