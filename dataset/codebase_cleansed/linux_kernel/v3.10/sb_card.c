static int sb_register_oss(struct sb_card_config *scc, struct sb_module_options *sbmo)
{
if (!request_region(scc->conf.io_base, 16, "soundblaster")) {
printk(KERN_ERR "sb: ports busy.\n");
kfree(scc);
return -EBUSY;
}
if (!sb_dsp_detect(&scc->conf, 0, 0, sbmo)) {
release_region(scc->conf.io_base, 16);
printk(KERN_ERR "sb: Failed DSP Detect.\n");
kfree(scc);
return -ENODEV;
}
if(!sb_dsp_init(&scc->conf, THIS_MODULE)) {
printk(KERN_ERR "sb: Failed DSP init.\n");
kfree(scc);
return -ENODEV;
}
if(scc->mpucnf.io_base > 0) {
scc->mpu = 1;
printk(KERN_INFO "sb: Turning on MPU\n");
if(!probe_sbmpu(&scc->mpucnf, THIS_MODULE))
scc->mpu = 0;
}
return 1;
}
static void sb_unload(struct sb_card_config *scc)
{
sb_dsp_unload(&scc->conf, 0);
if(scc->mpu)
unload_sbmpu(&scc->mpucnf);
kfree(scc);
}
static int __init sb_init_legacy(void)
{
struct sb_module_options sbmo = {0};
if((legacy = kzalloc(sizeof(struct sb_card_config), GFP_KERNEL)) == NULL) {
printk(KERN_ERR "sb: Error: Could not allocate memory\n");
return -ENOMEM;
}
legacy->conf.io_base = io;
legacy->conf.irq = irq;
legacy->conf.dma = dma;
legacy->conf.dma2 = dma16;
legacy->conf.card_subtype = type;
legacy->mpucnf.io_base = mpu_io;
legacy->mpucnf.irq = -1;
legacy->mpucnf.dma = -1;
legacy->mpucnf.dma2 = -1;
sbmo.esstype = esstype;
sbmo.sm_games = sm_games;
sbmo.acer = acer;
return sb_register_oss(legacy, &sbmo);
}
static void sb_dev2cfg(struct pnp_dev *dev, struct sb_card_config *scc)
{
scc->conf.io_base = -1;
scc->conf.irq = -1;
scc->conf.dma = -1;
scc->conf.dma2 = -1;
scc->mpucnf.io_base = -1;
scc->mpucnf.irq = -1;
scc->mpucnf.dma = -1;
scc->mpucnf.dma2 = -1;
if(!strncmp("CTL",scc->card_id,3)) {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,0);
scc->conf.dma2 = pnp_dma(dev,1);
scc->mpucnf.io_base = pnp_port_start(dev,1);
return;
}
if(!strncmp("tBA",scc->card_id,3)) {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,0);
scc->conf.dma2 = pnp_dma(dev,1);
return;
}
if(!strncmp("ESS",scc->card_id,3)) {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,0);
scc->conf.dma2 = pnp_dma(dev,1);
scc->mpucnf.io_base = pnp_port_start(dev,2);
return;
}
if(!strncmp("CMI",scc->card_id,3)) {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,0);
scc->conf.dma2 = pnp_dma(dev,1);
return;
}
if(!strncmp("RWB",scc->card_id,3)) {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,0);
return;
}
if(!strncmp("ALS",scc->card_id,3)) {
if(!strncmp("ALS0007",scc->card_id,7)) {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,0);
} else {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,1);
scc->conf.dma2 = pnp_dma(dev,0);
}
return;
}
if(!strncmp("RTL",scc->card_id,3)) {
scc->conf.io_base = pnp_port_start(dev,0);
scc->conf.irq = pnp_irq(dev,0);
scc->conf.dma = pnp_dma(dev,1);
scc->conf.dma2 = pnp_dma(dev,0);
}
}
static int sb_pnp_probe(struct pnp_card_link *card, const struct pnp_card_device_id *card_id)
{
struct sb_card_config *scc;
struct sb_module_options sbmo = {0};
struct pnp_dev *dev = pnp_request_card_device(card, card_id->devs[0].id, NULL);
if(!dev){
return -EBUSY;
}
if((scc = kzalloc(sizeof(struct sb_card_config), GFP_KERNEL)) == NULL) {
printk(KERN_ERR "sb: Error: Could not allocate memory\n");
return -ENOMEM;
}
printk(KERN_INFO "sb: PnP: Found Card Named = \"%s\", Card PnP id = " \
"%s, Device PnP id = %s\n", card->card->name, card_id->id,
dev->id->id);
scc->card_id = card_id->id;
scc->dev_id = dev->id->id;
sb_dev2cfg(dev, scc);
printk(KERN_INFO "sb: PnP: Detected at: io=0x%x, irq=%d, " \
"dma=%d, dma16=%d\n", scc->conf.io_base, scc->conf.irq,
scc->conf.dma, scc->conf.dma2);
pnp_set_card_drvdata(card, scc);
sb_pnp_devices++;
return sb_register_oss(scc, &sbmo);
}
static void sb_pnp_remove(struct pnp_card_link *card)
{
struct sb_card_config *scc = pnp_get_card_drvdata(card);
if(!scc)
return;
printk(KERN_INFO "sb: PnP: Removing %s\n", scc->card_id);
sb_unload(scc);
}
static void sb_unregister_all(void)
{
#ifdef CONFIG_PNP
if (pnp_registered)
pnp_unregister_card_driver(&sb_pnp_driver);
#endif
}
static int __init sb_init(void)
{
int lres = 0;
int pres = 0;
printk(KERN_INFO "sb: Init: Starting Probe...\n");
if(io != -1 && irq != -1 && dma != -1) {
printk(KERN_INFO "sb: Probing legacy card with io=%x, "\
"irq=%d, dma=%d, dma16=%d\n",io, irq, dma, dma16);
lres = sb_init_legacy();
} else if((io != -1 || irq != -1 || dma != -1) ||
(!pnp && (io == -1 && irq == -1 && dma == -1)))
printk(KERN_ERR "sb: Error: At least io, irq, and dma "\
"must be set for legacy cards.\n");
#ifdef CONFIG_PNP
if(pnp) {
int err = pnp_register_card_driver(&sb_pnp_driver);
if (!err)
pnp_registered = 1;
pres = sb_pnp_devices;
}
#endif
printk(KERN_INFO "sb: Init: Done\n");
if (pres == 0 && lres <= 0) {
sb_unregister_all();
return -ENODEV;
}
return 0;
}
static void __exit sb_exit(void)
{
printk(KERN_INFO "sb: Unloading...\n");
if (legacy) {
printk (KERN_INFO "sb: Unloading legacy card\n");
sb_unload(legacy);
}
sb_unregister_all();
vfree(smw_free);
smw_free = NULL;
}
