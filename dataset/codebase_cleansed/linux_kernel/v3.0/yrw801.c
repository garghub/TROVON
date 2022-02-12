int snd_yrw801_detect(struct snd_opl4 *opl4)
{
char buf[15];
snd_opl4_read_memory(opl4, buf, 0x001200, 15);
if (memcmp(buf, "CopyrightYAMAHA", 15))
return -ENODEV;
snd_opl4_read_memory(opl4, buf, 0x1ffffe, 2);
if (buf[0] != 0x01)
return -ENODEV;
snd_printdd("YRW801 ROM version %02x.%02x\n", buf[0], buf[1]);
return 0;
}
