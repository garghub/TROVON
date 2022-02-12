static int __devinit snd_vortex_midi(vortex_t * vortex)
{
struct snd_rawmidi *rmidi;
int temp, mode;
struct snd_mpu401 *mpu;
unsigned long port;
#ifdef VORTEX_MPU401_LEGACY
port = (0x03 << 5);
temp =
(hwread(vortex->mmio, VORTEX_CTRL) & ~CTRL_MIDI_PORT) |
CTRL_MIDI_EN | port;
hwwrite(vortex->mmio, VORTEX_CTRL, temp);
#else
temp =
(hwread(vortex->mmio, VORTEX_CTRL) & ~CTRL_MIDI_PORT) &
~CTRL_MIDI_EN;
hwwrite(vortex->mmio, VORTEX_CTRL, temp);
#endif
mode = 1;
temp = hwread(vortex->mmio, VORTEX_CTRL2) & 0xffff00cf;
temp |= (MIDI_CLOCK_DIV << 8) | ((mode >> 24) & 0xff) << 4;
hwwrite(vortex->mmio, VORTEX_CTRL2, temp);
hwwrite(vortex->mmio, VORTEX_MIDI_CMD, MPU401_RESET);
temp = hwread(vortex->mmio, VORTEX_MIDI_DATA);
if (temp != MPU401_ACK ) {
printk(KERN_ERR "midi port doesn't acknowledge!\n");
return -ENODEV;
}
hwwrite(vortex->mmio, VORTEX_IRQ_CTRL,
hwread(vortex->mmio, VORTEX_IRQ_CTRL) | IRQ_MIDI);
#ifdef VORTEX_MPU401_LEGACY
if ((temp =
snd_mpu401_uart_new(vortex->card, 0, MPU401_HW_MPU401, 0x330,
0, 0, 0, &rmidi)) != 0) {
hwwrite(vortex->mmio, VORTEX_CTRL,
(hwread(vortex->mmio, VORTEX_CTRL) &
~CTRL_MIDI_PORT) & ~CTRL_MIDI_EN);
return temp;
}
#else
port = (unsigned long)(vortex->mmio + VORTEX_MIDI_DATA);
if ((temp =
snd_mpu401_uart_new(vortex->card, 0, MPU401_HW_AUREAL, port,
MPU401_INFO_INTEGRATED | MPU401_INFO_MMIO,
0, 0, &rmidi)) != 0) {
hwwrite(vortex->mmio, VORTEX_CTRL,
(hwread(vortex->mmio, VORTEX_CTRL) &
~CTRL_MIDI_PORT) & ~CTRL_MIDI_EN);
return temp;
}
mpu = rmidi->private_data;
mpu->cport = (unsigned long)(vortex->mmio + VORTEX_MIDI_CMD);
#endif
snprintf(rmidi->name, sizeof(rmidi->name), "%s MIDI %d", CARD_NAME_SHORT , vortex->card->number);
vortex->rmidi = rmidi;
return 0;
}
