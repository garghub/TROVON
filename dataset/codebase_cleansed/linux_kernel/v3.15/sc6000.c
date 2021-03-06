static unsigned char sc6000_irq_to_softcfg(int irq)
{
unsigned char val = 0;
switch (irq) {
case 5:
val = 0x28;
break;
case 7:
val = 0x8;
break;
case 9:
val = 0x10;
break;
case 10:
val = 0x18;
break;
case 11:
val = 0x20;
break;
default:
break;
}
return val;
}
static unsigned char sc6000_dma_to_softcfg(int dma)
{
unsigned char val = 0;
switch (dma) {
case 0:
val = 1;
break;
case 1:
val = 2;
break;
case 3:
val = 3;
break;
default:
break;
}
return val;
}
static unsigned char sc6000_mpu_irq_to_softcfg(int mpu_irq)
{
unsigned char val = 0;
switch (mpu_irq) {
case 5:
val = 4;
break;
case 7:
val = 0x44;
break;
case 9:
val = 0x84;
break;
case 10:
val = 0xc4;
break;
default:
break;
}
return val;
}
static int sc6000_wait_data(char __iomem *vport)
{
int loop = 1000;
unsigned char val = 0;
do {
val = ioread8(vport + DSP_DATAVAIL);
if (val & 0x80)
return 0;
cpu_relax();
} while (loop--);
return -EAGAIN;
}
static int sc6000_read(char __iomem *vport)
{
if (sc6000_wait_data(vport))
return -EBUSY;
return ioread8(vport + DSP_READ);
}
static int sc6000_write(char __iomem *vport, int cmd)
{
unsigned char val;
int loop = 500000;
do {
val = ioread8(vport + DSP_STATUS);
if (!(val & 0x80)) {
iowrite8(cmd, vport + DSP_COMMAND);
return 0;
}
cpu_relax();
} while (loop--);
snd_printk(KERN_ERR "DSP Command (0x%x) timeout.\n", cmd);
return -EIO;
}
static int sc6000_dsp_get_answer(char __iomem *vport, int command,
char *data, int data_len)
{
int len = 0;
if (sc6000_write(vport, command)) {
snd_printk(KERN_ERR "CMD 0x%x: failed!\n", command);
return -EIO;
}
do {
int val = sc6000_read(vport);
if (val < 0)
break;
data[len++] = val;
} while (len < data_len);
return len ? len : -EIO;
}
static int sc6000_dsp_reset(char __iomem *vport)
{
iowrite8(1, vport + DSP_RESET);
udelay(10);
iowrite8(0, vport + DSP_RESET);
udelay(20);
if (sc6000_read(vport) == 0xaa)
return 0;
return -ENODEV;
}
static int sc6000_hw_cfg_write(char __iomem *vport, const int *cfg)
{
if (sc6000_write(vport, COMMAND_6C) < 0) {
snd_printk(KERN_WARNING "CMD 0x%x: failed!\n", COMMAND_6C);
return -EIO;
}
if (sc6000_write(vport, COMMAND_5C) < 0) {
snd_printk(KERN_ERR "CMD 0x%x: failed!\n", COMMAND_5C);
return -EIO;
}
if (sc6000_write(vport, cfg[0]) < 0) {
snd_printk(KERN_ERR "DATA 0x%x: failed!\n", cfg[0]);
return -EIO;
}
if (sc6000_write(vport, cfg[1]) < 0) {
snd_printk(KERN_ERR "DATA 0x%x: failed!\n", cfg[1]);
return -EIO;
}
if (sc6000_write(vport, COMMAND_C5) < 0) {
snd_printk(KERN_ERR "CMD 0x%x: failed!\n", COMMAND_C5);
return -EIO;
}
return 0;
}
static int sc6000_cfg_write(char __iomem *vport, unsigned char softcfg)
{
if (sc6000_write(vport, WRITE_MDIRQ_CFG)) {
snd_printk(KERN_ERR "CMD 0x%x: failed!\n", WRITE_MDIRQ_CFG);
return -EIO;
}
if (sc6000_write(vport, softcfg)) {
snd_printk(KERN_ERR "sc6000_cfg_write: failed!\n");
return -EIO;
}
return 0;
}
static int sc6000_setup_board(char __iomem *vport, int config)
{
int loop = 10;
do {
if (sc6000_write(vport, COMMAND_88)) {
snd_printk(KERN_ERR "CMD 0x%x: failed!\n",
COMMAND_88);
return -EIO;
}
} while ((sc6000_wait_data(vport) < 0) && loop--);
if (sc6000_read(vport) < 0) {
snd_printk(KERN_ERR "sc6000_read after CMD 0x%x: failed\n",
COMMAND_88);
return -EIO;
}
if (sc6000_cfg_write(vport, config))
return -ENODEV;
return 0;
}
static int sc6000_init_mss(char __iomem *vport, int config,
char __iomem *vmss_port, int mss_config)
{
if (sc6000_write(vport, DSP_INIT_MSS)) {
snd_printk(KERN_ERR "sc6000_init_mss [0x%x]: failed!\n",
DSP_INIT_MSS);
return -EIO;
}
msleep(10);
if (sc6000_cfg_write(vport, config))
return -EIO;
iowrite8(mss_config, vmss_port);
return 0;
}
static void sc6000_hw_cfg_encode(char __iomem *vport, int *cfg,
long xport, long xmpu,
long xmss_port, int joystick)
{
cfg[0] = 0;
cfg[1] = 0;
if (xport == 0x240)
cfg[0] |= 1;
if (xmpu != SNDRV_AUTO_PORT) {
cfg[0] |= (xmpu & 0x30) >> 2;
cfg[1] |= 0x20;
}
if (xmss_port == 0xe80)
cfg[0] |= 0x10;
cfg[0] |= 0x40;
if (!joystick)
cfg[0] |= 0x02;
cfg[1] |= 0x80;
cfg[1] &= ~0x40;
snd_printd("hw cfg %x, %x\n", cfg[0], cfg[1]);
}
static int sc6000_init_board(char __iomem *vport,
char __iomem *vmss_port, int dev)
{
char answer[15];
char version[2];
int mss_config = sc6000_irq_to_softcfg(irq[dev]) |
sc6000_dma_to_softcfg(dma[dev]);
int config = mss_config |
sc6000_mpu_irq_to_softcfg(mpu_irq[dev]);
int err;
int old = 0;
err = sc6000_dsp_reset(vport);
if (err < 0) {
snd_printk(KERN_ERR "sc6000_dsp_reset: failed!\n");
return err;
}
memset(answer, 0, sizeof(answer));
err = sc6000_dsp_get_answer(vport, GET_DSP_COPYRIGHT, answer, 15);
if (err <= 0) {
snd_printk(KERN_ERR "sc6000_dsp_copyright: failed!\n");
return -ENODEV;
}
if (strncmp("SC-6000", answer, 7))
snd_printk(KERN_WARNING "Warning: non SC-6000 audio card!\n");
if (sc6000_dsp_get_answer(vport, GET_DSP_VERSION, version, 2) < 2) {
snd_printk(KERN_ERR "sc6000_dsp_version: failed!\n");
return -ENODEV;
}
printk(KERN_INFO PFX "Detected model: %s, DSP version %d.%d\n",
answer, version[0], version[1]);
sc6000_write(vport, COMMAND_5C);
if (sc6000_read(vport) < 0)
old = 1;
if (!old) {
int cfg[2];
sc6000_hw_cfg_encode(vport, &cfg[0], port[dev], mpu_port[dev],
mss_port[dev], joystick[dev]);
if (sc6000_hw_cfg_write(vport, cfg) < 0) {
snd_printk(KERN_ERR "sc6000_hw_cfg_write: failed!\n");
return -EIO;
}
}
err = sc6000_setup_board(vport, config);
if (err < 0) {
snd_printk(KERN_ERR "sc6000_setup_board: failed!\n");
return -ENODEV;
}
sc6000_dsp_reset(vport);
if (!old) {
sc6000_write(vport, COMMAND_60);
sc6000_write(vport, 0x02);
sc6000_dsp_reset(vport);
}
err = sc6000_setup_board(vport, config);
if (err < 0) {
snd_printk(KERN_ERR "sc6000_setup_board: failed!\n");
return -ENODEV;
}
err = sc6000_init_mss(vport, config, vmss_port, mss_config);
if (err < 0) {
snd_printk(KERN_ERR "Cannot initialize "
"Microsoft Sound System mode.\n");
return -ENODEV;
}
return 0;
}
static int snd_sc6000_mixer(struct snd_wss *chip)
{
struct snd_card *card = chip->card;
struct snd_ctl_elem_id id1, id2;
int err;
memset(&id1, 0, sizeof(id1));
memset(&id2, 0, sizeof(id2));
id1.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
id2.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(id1.name, "Aux Playback Switch");
strcpy(id2.name, "FM Playback Switch");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0)
return err;
strcpy(id1.name, "Aux Playback Volume");
strcpy(id2.name, "FM Playback Volume");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0)
return err;
strcpy(id1.name, "Aux Playback Switch"); id1.index = 1;
strcpy(id2.name, "CD Playback Switch");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0)
return err;
strcpy(id1.name, "Aux Playback Volume");
strcpy(id2.name, "CD Playback Volume");
err = snd_ctl_rename_id(card, &id1, &id2);
if (err < 0)
return err;
return 0;
}
static int snd_sc6000_match(struct device *devptr, unsigned int dev)
{
if (!enable[dev])
return 0;
if (port[dev] == SNDRV_AUTO_PORT) {
printk(KERN_ERR PFX "specify IO port\n");
return 0;
}
if (mss_port[dev] == SNDRV_AUTO_PORT) {
printk(KERN_ERR PFX "specify MSS port\n");
return 0;
}
if (port[dev] != 0x220 && port[dev] != 0x240) {
printk(KERN_ERR PFX "Port must be 0x220 or 0x240\n");
return 0;
}
if (mss_port[dev] != 0x530 && mss_port[dev] != 0xe80) {
printk(KERN_ERR PFX "MSS port must be 0x530 or 0xe80\n");
return 0;
}
if (irq[dev] != SNDRV_AUTO_IRQ && !sc6000_irq_to_softcfg(irq[dev])) {
printk(KERN_ERR PFX "invalid IRQ %d\n", irq[dev]);
return 0;
}
if (dma[dev] != SNDRV_AUTO_DMA && !sc6000_dma_to_softcfg(dma[dev])) {
printk(KERN_ERR PFX "invalid DMA %d\n", dma[dev]);
return 0;
}
if (mpu_port[dev] != SNDRV_AUTO_PORT &&
(mpu_port[dev] & ~0x30L) != 0x300) {
printk(KERN_ERR PFX "invalid MPU-401 port %lx\n",
mpu_port[dev]);
return 0;
}
if (mpu_port[dev] != SNDRV_AUTO_PORT &&
mpu_irq[dev] != SNDRV_AUTO_IRQ && mpu_irq[dev] != 0 &&
!sc6000_mpu_irq_to_softcfg(mpu_irq[dev])) {
printk(KERN_ERR PFX "invalid MPU-401 IRQ %d\n", mpu_irq[dev]);
return 0;
}
return 1;
}
static int snd_sc6000_probe(struct device *devptr, unsigned int dev)
{
static int possible_irqs[] = { 5, 7, 9, 10, 11, -1 };
static int possible_dmas[] = { 1, 3, 0, -1 };
int err;
int xirq = irq[dev];
int xdma = dma[dev];
struct snd_card *card;
struct snd_wss *chip;
struct snd_opl3 *opl3;
char __iomem **vport;
char __iomem *vmss_port;
err = snd_card_new(devptr, index[dev], id[dev], THIS_MODULE,
sizeof(vport), &card);
if (err < 0)
return err;
vport = card->private_data;
if (xirq == SNDRV_AUTO_IRQ) {
xirq = snd_legacy_find_free_irq(possible_irqs);
if (xirq < 0) {
snd_printk(KERN_ERR PFX "unable to find a free IRQ\n");
err = -EBUSY;
goto err_exit;
}
}
if (xdma == SNDRV_AUTO_DMA) {
xdma = snd_legacy_find_free_dma(possible_dmas);
if (xdma < 0) {
snd_printk(KERN_ERR PFX "unable to find a free DMA\n");
err = -EBUSY;
goto err_exit;
}
}
if (!request_region(port[dev], 0x10, DRV_NAME)) {
snd_printk(KERN_ERR PFX
"I/O port region is already in use.\n");
err = -EBUSY;
goto err_exit;
}
*vport = devm_ioport_map(devptr, port[dev], 0x10);
if (*vport == NULL) {
snd_printk(KERN_ERR PFX
"I/O port cannot be iomaped.\n");
err = -EBUSY;
goto err_unmap1;
}
if (!request_region(mss_port[dev], 4, DRV_NAME)) {
snd_printk(KERN_ERR PFX
"SC-6000 port I/O port region is already in use.\n");
err = -EBUSY;
goto err_unmap1;
}
vmss_port = devm_ioport_map(devptr, mss_port[dev], 4);
if (!vmss_port) {
snd_printk(KERN_ERR PFX
"MSS port I/O cannot be iomaped.\n");
err = -EBUSY;
goto err_unmap2;
}
snd_printd("Initializing BASE[0x%lx] IRQ[%d] DMA[%d] MIRQ[%d]\n",
port[dev], xirq, xdma,
mpu_irq[dev] == SNDRV_AUTO_IRQ ? 0 : mpu_irq[dev]);
err = sc6000_init_board(*vport, vmss_port, dev);
if (err < 0)
goto err_unmap2;
err = snd_wss_create(card, mss_port[dev] + 4, -1, xirq, xdma, -1,
WSS_HW_DETECT, 0, &chip);
if (err < 0)
goto err_unmap2;
err = snd_wss_pcm(chip, 0, NULL);
if (err < 0) {
snd_printk(KERN_ERR PFX
"error creating new WSS PCM device\n");
goto err_unmap2;
}
err = snd_wss_mixer(chip);
if (err < 0) {
snd_printk(KERN_ERR PFX "error creating new WSS mixer\n");
goto err_unmap2;
}
err = snd_sc6000_mixer(chip);
if (err < 0) {
snd_printk(KERN_ERR PFX "the mixer rewrite failed\n");
goto err_unmap2;
}
if (snd_opl3_create(card,
0x388, 0x388 + 2,
OPL3_HW_AUTO, 0, &opl3) < 0) {
snd_printk(KERN_ERR PFX "no OPL device at 0x%x-0x%x ?\n",
0x388, 0x388 + 2);
} else {
err = snd_opl3_hwdep_new(opl3, 0, 1, NULL);
if (err < 0)
goto err_unmap2;
}
if (mpu_port[dev] != SNDRV_AUTO_PORT) {
if (mpu_irq[dev] == SNDRV_AUTO_IRQ)
mpu_irq[dev] = -1;
if (snd_mpu401_uart_new(card, 0,
MPU401_HW_MPU401,
mpu_port[dev], 0,
mpu_irq[dev], NULL) < 0)
snd_printk(KERN_ERR "no MPU-401 device at 0x%lx ?\n",
mpu_port[dev]);
}
strcpy(card->driver, DRV_NAME);
strcpy(card->shortname, "SC-6000");
sprintf(card->longname, "Gallant SC-6000 at 0x%lx, irq %d, dma %d",
mss_port[dev], xirq, xdma);
err = snd_card_register(card);
if (err < 0)
goto err_unmap2;
dev_set_drvdata(devptr, card);
return 0;
err_unmap2:
sc6000_setup_board(*vport, 0);
release_region(mss_port[dev], 4);
err_unmap1:
release_region(port[dev], 0x10);
err_exit:
snd_card_free(card);
return err;
}
static int snd_sc6000_remove(struct device *devptr, unsigned int dev)
{
struct snd_card *card = dev_get_drvdata(devptr);
char __iomem **vport = card->private_data;
if (sc6000_setup_board(*vport, 0) < 0)
snd_printk(KERN_WARNING "sc6000_setup_board failed on exit!\n");
release_region(port[dev], 0x10);
release_region(mss_port[dev], 4);
snd_card_free(card);
return 0;
}
static int __init alsa_card_sc6000_init(void)
{
return isa_register_driver(&snd_sc6000_driver, SNDRV_CARDS);
}
static void __exit alsa_card_sc6000_exit(void)
{
isa_unregister_driver(&snd_sc6000_driver);
}
