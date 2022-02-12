static int __devinit dsp_get_byte(void __iomem *port, u8 *val)
{
int loops = 1000;
while (!(ioread8(port + DSP_PORT_DATA_AVAIL) & 0x80)) {
if (!loops--)
return -EIO;
cpu_relax();
}
*val = ioread8(port + DSP_PORT_READ);
return 0;
}
static int __devinit dsp_reset(void __iomem *port)
{
u8 val;
iowrite8(1, port + DSP_PORT_RESET);
udelay(10);
iowrite8(0, port + DSP_PORT_RESET);
if (dsp_get_byte(port, &val) < 0 || val != DSP_SIGNATURE)
return -ENODEV;
return 0;
}
static int __devinit dsp_command(void __iomem *port, u8 cmd)
{
int loops = 1000;
while (ioread8(port + DSP_PORT_STATUS) & 0x80) {
if (!loops--)
return -EIO;
cpu_relax();
}
iowrite8(cmd, port + DSP_PORT_COMMAND);
return 0;
}
static int __devinit dsp_get_version(void __iomem *port, u8 *major, u8 *minor)
{
int err;
err = dsp_command(port, DSP_COMMAND_GET_VERSION);
if (err < 0)
return err;
err = dsp_get_byte(port, major);
if (err < 0)
return err;
err = dsp_get_byte(port, minor);
if (err < 0)
return err;
return 0;
}
static int __devinit wss_detect(void __iomem *wss_port)
{
if ((ioread8(wss_port + WSS_PORT_SIGNATURE) & 0x3f) != WSS_SIGNATURE)
return -ENODEV;
return 0;
}
static void wss_set_config(void __iomem *wss_port, u8 wss_config)
{
iowrite8(wss_config, wss_port + WSS_PORT_CONFIG);
}
static int __devinit snd_galaxy_match(struct device *dev, unsigned int n)
{
if (!enable[n])
return 0;
switch (port[n]) {
case SNDRV_AUTO_PORT:
dev_err(dev, "please specify port\n");
return 0;
case 0x220:
config[n] |= GALAXY_CONFIG_SBA_220;
break;
case 0x240:
config[n] |= GALAXY_CONFIG_SBA_240;
break;
case 0x260:
config[n] |= GALAXY_CONFIG_SBA_260;
break;
case 0x280:
config[n] |= GALAXY_CONFIG_SBA_280;
break;
default:
dev_err(dev, "invalid port %#lx\n", port[n]);
return 0;
}
switch (wss_port[n]) {
case SNDRV_AUTO_PORT:
dev_err(dev, "please specify wss_port\n");
return 0;
case 0x530:
config[n] |= GALAXY_CONFIG_WSS_ENABLE | GALAXY_CONFIG_WSSA_530;
break;
case 0x604:
config[n] |= GALAXY_CONFIG_WSS_ENABLE | GALAXY_CONFIG_WSSA_604;
break;
case 0xe80:
config[n] |= GALAXY_CONFIG_WSS_ENABLE | GALAXY_CONFIG_WSSA_E80;
break;
case 0xf40:
config[n] |= GALAXY_CONFIG_WSS_ENABLE | GALAXY_CONFIG_WSSA_F40;
break;
default:
dev_err(dev, "invalid WSS port %#lx\n", wss_port[n]);
return 0;
}
switch (irq[n]) {
case SNDRV_AUTO_IRQ:
dev_err(dev, "please specify irq\n");
return 0;
case 7:
wss_config[n] |= WSS_CONFIG_IRQ_7;
break;
case 2:
irq[n] = 9;
case 9:
wss_config[n] |= WSS_CONFIG_IRQ_9;
break;
case 10:
wss_config[n] |= WSS_CONFIG_IRQ_10;
break;
case 11:
wss_config[n] |= WSS_CONFIG_IRQ_11;
break;
default:
dev_err(dev, "invalid IRQ %d\n", irq[n]);
return 0;
}
switch (dma1[n]) {
case SNDRV_AUTO_DMA:
dev_err(dev, "please specify dma1\n");
return 0;
case 0:
wss_config[n] |= WSS_CONFIG_DMA_0;
break;
case 1:
wss_config[n] |= WSS_CONFIG_DMA_1;
break;
case 3:
wss_config[n] |= WSS_CONFIG_DMA_3;
break;
default:
dev_err(dev, "invalid playback DMA %d\n", dma1[n]);
return 0;
}
if (dma2[n] == SNDRV_AUTO_DMA || dma2[n] == dma1[n]) {
dma2[n] = -1;
goto mpu;
}
wss_config[n] |= WSS_CONFIG_DUPLEX;
switch (dma2[n]) {
case 0:
break;
case 1:
if (dma1[n] == 0)
break;
default:
dev_err(dev, "invalid capture DMA %d\n", dma2[n]);
return 0;
}
mpu:
switch (mpu_port[n]) {
case SNDRV_AUTO_PORT:
dev_warn(dev, "mpu_port not specified; not using MPU-401\n");
mpu_port[n] = -1;
goto fm;
case 0x300:
config[n] |= GALAXY_CONFIG_MPU_ENABLE | GALAXY_CONFIG_MPUA_300;
break;
case 0x330:
config[n] |= GALAXY_CONFIG_MPU_ENABLE | GALAXY_CONFIG_MPUA_330;
break;
default:
dev_err(dev, "invalid MPU port %#lx\n", mpu_port[n]);
return 0;
}
switch (mpu_irq[n]) {
case SNDRV_AUTO_IRQ:
dev_warn(dev, "mpu_irq not specified: using polling mode\n");
mpu_irq[n] = -1;
break;
case 2:
mpu_irq[n] = 9;
case 9:
config[n] |= GALAXY_CONFIG_MPUIRQ_2;
break;
#ifdef AZT1605
case 3:
config[n] |= GALAXY_CONFIG_MPUIRQ_3;
break;
#endif
case 5:
config[n] |= GALAXY_CONFIG_MPUIRQ_5;
break;
case 7:
config[n] |= GALAXY_CONFIG_MPUIRQ_7;
break;
#ifdef AZT2316
case 10:
config[n] |= GALAXY_CONFIG_MPUIRQ_10;
break;
#endif
default:
dev_err(dev, "invalid MPU IRQ %d\n", mpu_irq[n]);
return 0;
}
if (mpu_irq[n] == irq[n]) {
dev_err(dev, "cannot share IRQ between WSS and MPU-401\n");
return 0;
}
fm:
switch (fm_port[n]) {
case SNDRV_AUTO_PORT:
dev_warn(dev, "fm_port not specified: not using OPL3\n");
fm_port[n] = -1;
break;
case 0x388:
break;
default:
dev_err(dev, "illegal FM port %#lx\n", fm_port[n]);
return 0;
}
config[n] |= GALAXY_CONFIG_GAME_ENABLE;
return 1;
}
static int __devinit galaxy_init(struct snd_galaxy *galaxy, u8 *type)
{
u8 major;
u8 minor;
int err;
err = dsp_reset(galaxy->port);
if (err < 0)
return err;
err = dsp_get_version(galaxy->port, &major, &minor);
if (err < 0)
return err;
if (major != GALAXY_DSP_MAJOR || minor != GALAXY_DSP_MINOR)
return -ENODEV;
err = dsp_command(galaxy->port, DSP_COMMAND_GALAXY_8);
if (err < 0)
return err;
err = dsp_command(galaxy->port, GALAXY_COMMAND_GET_TYPE);
if (err < 0)
return err;
err = dsp_get_byte(galaxy->port, type);
if (err < 0)
return err;
return 0;
}
static int __devinit galaxy_set_mode(struct snd_galaxy *galaxy, u8 mode)
{
int err;
err = dsp_command(galaxy->port, DSP_COMMAND_GALAXY_9);
if (err < 0)
return err;
err = dsp_command(galaxy->port, mode);
if (err < 0)
return err;
#ifdef AZT1605
err = dsp_reset(galaxy->port);
if (err < 0)
return err;
#endif
return 0;
}
static void galaxy_set_config(struct snd_galaxy *galaxy, u32 config)
{
u8 tmp = ioread8(galaxy->config_port + CONFIG_PORT_SET);
int i;
iowrite8(tmp | 0x80, galaxy->config_port + CONFIG_PORT_SET);
for (i = 0; i < GALAXY_CONFIG_SIZE; i++) {
iowrite8(config, galaxy->config_port + i);
config >>= 8;
}
iowrite8(tmp & 0x7f, galaxy->config_port + CONFIG_PORT_SET);
msleep(10);
}
static void __devinit galaxy_config(struct snd_galaxy *galaxy, u32 config)
{
int i;
for (i = GALAXY_CONFIG_SIZE; i; i--) {
u8 tmp = ioread8(galaxy->config_port + i - 1);
galaxy->config = (galaxy->config << 8) | tmp;
}
config |= galaxy->config & GALAXY_CONFIG_MASK;
galaxy_set_config(galaxy, config);
}
static int __devinit galaxy_wss_config(struct snd_galaxy *galaxy, u8 wss_config)
{
int err;
err = wss_detect(galaxy->wss_port);
if (err < 0)
return err;
wss_set_config(galaxy->wss_port, wss_config);
err = galaxy_set_mode(galaxy, GALAXY_MODE_WSS);
if (err < 0)
return err;
return 0;
}
static void snd_galaxy_free(struct snd_card *card)
{
struct snd_galaxy *galaxy = card->private_data;
if (galaxy->wss_port) {
wss_set_config(galaxy->wss_port, 0);
ioport_unmap(galaxy->wss_port);
release_and_free_resource(galaxy->res_wss_port);
}
if (galaxy->config_port) {
galaxy_set_config(galaxy, galaxy->config);
ioport_unmap(galaxy->config_port);
release_and_free_resource(galaxy->res_config_port);
}
if (galaxy->port) {
ioport_unmap(galaxy->port);
release_and_free_resource(galaxy->res_port);
}
}
static int __devinit snd_galaxy_probe(struct device *dev, unsigned int n)
{
struct snd_galaxy *galaxy;
struct snd_wss *chip;
struct snd_card *card;
u8 type;
int err;
err = snd_card_create(index[n], id[n], THIS_MODULE, sizeof *galaxy,
&card);
if (err < 0)
return err;
snd_card_set_dev(card, dev);
card->private_free = snd_galaxy_free;
galaxy = card->private_data;
galaxy->res_port = request_region(port[n], 16, DRV_NAME);
if (!galaxy->res_port) {
dev_err(dev, "could not grab ports %#lx-%#lx\n", port[n],
port[n] + 15);
err = -EBUSY;
goto error;
}
galaxy->port = ioport_map(port[n], 16);
err = galaxy_init(galaxy, &type);
if (err < 0) {
dev_err(dev, "did not find a Sound Galaxy at %#lx\n", port[n]);
goto error;
}
dev_info(dev, "Sound Galaxy (type %d) found at %#lx\n", type, port[n]);
galaxy->res_config_port = request_region(port[n] + GALAXY_PORT_CONFIG,
16, DRV_NAME);
if (!galaxy->res_config_port) {
dev_err(dev, "could not grab ports %#lx-%#lx\n",
port[n] + GALAXY_PORT_CONFIG,
port[n] + GALAXY_PORT_CONFIG + 15);
err = -EBUSY;
goto error;
}
galaxy->config_port = ioport_map(port[n] + GALAXY_PORT_CONFIG, 16);
galaxy_config(galaxy, config[n]);
galaxy->res_wss_port = request_region(wss_port[n], 4, DRV_NAME);
if (!galaxy->res_wss_port) {
dev_err(dev, "could not grab ports %#lx-%#lx\n", wss_port[n],
wss_port[n] + 3);
err = -EBUSY;
goto error;
}
galaxy->wss_port = ioport_map(wss_port[n], 4);
err = galaxy_wss_config(galaxy, wss_config[n]);
if (err < 0) {
dev_err(dev, "could not configure WSS\n");
goto error;
}
strcpy(card->driver, DRV_NAME);
strcpy(card->shortname, DRV_NAME);
sprintf(card->longname, "%s at %#lx/%#lx, irq %d, dma %d/%d",
card->shortname, port[n], wss_port[n], irq[n], dma1[n],
dma2[n]);
err = snd_wss_create(card, wss_port[n] + 4, -1, irq[n], dma1[n],
dma2[n], WSS_HW_DETECT, 0, &chip);
if (err < 0)
goto error;
err = snd_wss_pcm(chip, 0, NULL);
if (err < 0)
goto error;
err = snd_wss_mixer(chip);
if (err < 0)
goto error;
err = snd_wss_timer(chip, 0, NULL);
if (err < 0)
goto error;
if (mpu_port[n] >= 0) {
err = snd_mpu401_uart_new(card, 0, MPU401_HW_MPU401,
mpu_port[n], 0, mpu_irq[n], NULL);
if (err < 0)
goto error;
}
if (fm_port[n] >= 0) {
struct snd_opl3 *opl3;
err = snd_opl3_create(card, fm_port[n], fm_port[n] + 2,
OPL3_HW_AUTO, 0, &opl3);
if (err < 0) {
dev_err(dev, "no OPL device at %#lx\n", fm_port[n]);
goto error;
}
err = snd_opl3_timer_new(opl3, 1, 2);
if (err < 0)
goto error;
err = snd_opl3_hwdep_new(opl3, 0, 1, NULL);
if (err < 0)
goto error;
}
err = snd_card_register(card);
if (err < 0)
goto error;
dev_set_drvdata(dev, card);
return 0;
error:
snd_card_free(card);
return err;
}
static int __devexit snd_galaxy_remove(struct device *dev, unsigned int n)
{
snd_card_free(dev_get_drvdata(dev));
dev_set_drvdata(dev, NULL);
return 0;
}
static int __init alsa_card_galaxy_init(void)
{
return isa_register_driver(&snd_galaxy_driver, SNDRV_CARDS);
}
static void __exit alsa_card_galaxy_exit(void)
{
isa_unregister_driver(&snd_galaxy_driver);
}
