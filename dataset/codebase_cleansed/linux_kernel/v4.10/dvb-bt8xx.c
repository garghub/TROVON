static void dvb_bt8xx_task(unsigned long data)
{
struct dvb_bt8xx_card *card = (struct dvb_bt8xx_card *)data;
dprintk("%d\n", card->bt->finished_block);
while (card->bt->last_block != card->bt->finished_block) {
(card->bt->TS_Size ? dvb_dmx_swfilter_204 : dvb_dmx_swfilter)
(&card->demux,
&card->bt->buf_cpu[card->bt->last_block *
card->bt->block_bytes],
card->bt->block_bytes);
card->bt->last_block = (card->bt->last_block + 1) %
card->bt->block_count;
}
}
static int dvb_bt8xx_start_feed(struct dvb_demux_feed *dvbdmxfeed)
{
struct dvb_demux*dvbdmx = dvbdmxfeed->demux;
struct dvb_bt8xx_card *card = dvbdmx->priv;
int rc;
dprintk("dvb_bt8xx: start_feed\n");
if (!dvbdmx->dmx.frontend)
return -EINVAL;
mutex_lock(&card->lock);
card->nfeeds++;
rc = card->nfeeds;
if (card->nfeeds == 1)
bt878_start(card->bt, card->gpio_mode,
card->op_sync_orin, card->irq_err_ignore);
mutex_unlock(&card->lock);
return rc;
}
static int dvb_bt8xx_stop_feed(struct dvb_demux_feed *dvbdmxfeed)
{
struct dvb_demux *dvbdmx = dvbdmxfeed->demux;
struct dvb_bt8xx_card *card = dvbdmx->priv;
dprintk("dvb_bt8xx: stop_feed\n");
if (!dvbdmx->dmx.frontend)
return -EINVAL;
mutex_lock(&card->lock);
card->nfeeds--;
if (card->nfeeds == 0)
bt878_stop(card->bt);
mutex_unlock(&card->lock);
return 0;
}
static int is_pci_slot_eq(struct pci_dev* adev, struct pci_dev* bdev)
{
if ((adev->subsystem_vendor == bdev->subsystem_vendor) &&
(adev->subsystem_device == bdev->subsystem_device) &&
(adev->bus->number == bdev->bus->number) &&
(PCI_SLOT(adev->devfn) == PCI_SLOT(bdev->devfn)))
return 1;
return 0;
}
static struct bt878 *dvb_bt8xx_878_match(unsigned int bttv_nr,
struct pci_dev* bttv_pci_dev)
{
unsigned int card_nr;
for (card_nr = 0; card_nr < bt878_num; card_nr++)
if (is_pci_slot_eq(bt878[card_nr].dev, bttv_pci_dev))
return &bt878[card_nr];
return NULL;
}
static int thomson_dtt7579_demod_init(struct dvb_frontend* fe)
{
static u8 mt352_clock_config [] = { 0x89, 0x38, 0x38 };
static u8 mt352_reset [] = { 0x50, 0x80 };
static u8 mt352_adc_ctl_1_cfg [] = { 0x8E, 0x40 };
static u8 mt352_agc_cfg [] = { 0x67, 0x28, 0x20 };
static u8 mt352_gpp_ctl_cfg [] = { 0x8C, 0x33 };
static u8 mt352_capt_range_cfg[] = { 0x75, 0x32 };
mt352_write(fe, mt352_clock_config, sizeof(mt352_clock_config));
udelay(2000);
mt352_write(fe, mt352_reset, sizeof(mt352_reset));
mt352_write(fe, mt352_adc_ctl_1_cfg, sizeof(mt352_adc_ctl_1_cfg));
mt352_write(fe, mt352_agc_cfg, sizeof(mt352_agc_cfg));
mt352_write(fe, mt352_gpp_ctl_cfg, sizeof(mt352_gpp_ctl_cfg));
mt352_write(fe, mt352_capt_range_cfg, sizeof(mt352_capt_range_cfg));
return 0;
}
static int thomson_dtt7579_tuner_calc_regs(struct dvb_frontend *fe, u8* pllbuf, int buf_len)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 div;
unsigned char bs = 0;
unsigned char cp = 0;
if (buf_len < 5)
return -EINVAL;
div = (((c->frequency + 83333) * 3) / 500000) + IF_FREQUENCYx6;
if (c->frequency < 542000000)
cp = 0xb4;
else if (c->frequency < 771000000)
cp = 0xbc;
else
cp = 0xf4;
if (c->frequency == 0)
bs = 0x03;
else if (c->frequency < 443250000)
bs = 0x02;
else
bs = 0x08;
pllbuf[0] = 0x60;
pllbuf[1] = div >> 8;
pllbuf[2] = div & 0xff;
pllbuf[3] = cp;
pllbuf[4] = bs;
return 5;
}
static int cx24108_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 freq = c->frequency;
int i, a, n, pump;
u32 band, pll;
u32 osci[]={950000,1019000,1075000,1178000,1296000,1432000,
1576000,1718000,1856000,2036000,2150000};
u32 bandsel[]={0,0x00020000,0x00040000,0x00100800,0x00101000,
0x00102000,0x00104000,0x00108000,0x00110000,
0x00120000,0x00140000};
#define XTAL 1011100
dprintk("cx24108 debug: entering SetTunerFreq, freq=%d\n", freq);
if (freq<950000)
freq = 950000;
else if (freq>2150000)
freq = 2150000;
for(i = 1; (i < ARRAY_SIZE(osci) - 1) && (osci[i] < freq); i++);
dprintk("cx24108 debug: select vco #%d (f=%d)\n", i, freq);
band=bandsel[i];
n=((i<=2?2:1)*freq*10L)/(XTAL/100);
a=n%32; n/=32; if(a==0) n--;
pump=(freq<(osci[i-1]+osci[i])/2);
pll=0xf8000000|
((pump?1:2)<<(14+11))|
((n&0x1ff)<<(5+11))|
((a&0x1f)<<11);
dprintk("cx24108 debug: pump=%d, n=%d, a=%d\n", pump, n, a);
cx24110_pll_write(fe,band);
cx24110_pll_write(fe,0x500c0000);
cx24110_pll_write(fe,0x83f1f800);
cx24110_pll_write(fe,pll);
return 0;
}
static int pinnsat_tuner_init(struct dvb_frontend* fe)
{
struct dvb_bt8xx_card *card = fe->dvb->priv;
bttv_gpio_enable(card->bttv_nr, 1, 1);
bttv_write_gpio(card->bttv_nr, 1, 1);
return 0;
}
static int pinnsat_tuner_sleep(struct dvb_frontend* fe)
{
struct dvb_bt8xx_card *card = fe->dvb->priv;
bttv_write_gpio(card->bttv_nr, 1, 0);
return 0;
}
static int microtune_mt7202dtf_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_bt8xx_card *card = (struct dvb_bt8xx_card *) fe->dvb->priv;
u8 cfg, cpump, band_select;
u8 data[4];
u32 div;
struct i2c_msg msg = { .addr = 0x60, .flags = 0, .buf = data, .len = sizeof(data) };
div = (36000000 + c->frequency + 83333) / 166666;
cfg = 0x88;
if (c->frequency < 175000000)
cpump = 2;
else if (c->frequency < 390000000)
cpump = 1;
else if (c->frequency < 470000000)
cpump = 2;
else if (c->frequency < 750000000)
cpump = 2;
else
cpump = 3;
if (c->frequency < 175000000)
band_select = 0x0e;
else if (c->frequency < 470000000)
band_select = 0x05;
else
band_select = 0x03;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = ((div >> 10) & 0x60) | cfg;
data[3] = (cpump << 6) | band_select;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
i2c_transfer(card->i2c_adapter, &msg, 1);
return (div * 166666 - 36000000);
}
static int microtune_mt7202dtf_request_firmware(struct dvb_frontend* fe, const struct firmware **fw, char* name)
{
struct dvb_bt8xx_card* bt = (struct dvb_bt8xx_card*) fe->dvb->priv;
return request_firmware(fw, name, &bt->bt->dev->dev);
}
static int advbt771_samsung_tdtc9251dh0_demod_init(struct dvb_frontend* fe)
{
static u8 mt352_clock_config [] = { 0x89, 0x38, 0x2d };
static u8 mt352_reset [] = { 0x50, 0x80 };
static u8 mt352_adc_ctl_1_cfg [] = { 0x8E, 0x40 };
static u8 mt352_agc_cfg [] = { 0x67, 0x10, 0x23, 0x00, 0xFF, 0xFF,
0x00, 0xFF, 0x00, 0x40, 0x40 };
static u8 mt352_av771_extra[] = { 0xB5, 0x7A };
static u8 mt352_capt_range_cfg[] = { 0x75, 0x32 };
mt352_write(fe, mt352_clock_config, sizeof(mt352_clock_config));
udelay(2000);
mt352_write(fe, mt352_reset, sizeof(mt352_reset));
mt352_write(fe, mt352_adc_ctl_1_cfg, sizeof(mt352_adc_ctl_1_cfg));
mt352_write(fe, mt352_agc_cfg,sizeof(mt352_agc_cfg));
udelay(2000);
mt352_write(fe, mt352_av771_extra,sizeof(mt352_av771_extra));
mt352_write(fe, mt352_capt_range_cfg, sizeof(mt352_capt_range_cfg));
return 0;
}
static int advbt771_samsung_tdtc9251dh0_tuner_calc_regs(struct dvb_frontend *fe, u8 *pllbuf, int buf_len)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 div;
unsigned char bs = 0;
unsigned char cp = 0;
if (buf_len < 5) return -EINVAL;
div = (((c->frequency + 83333) * 3) / 500000) + IF_FREQUENCYx6;
if (c->frequency < 150000000)
cp = 0xB4;
else if (c->frequency < 173000000)
cp = 0xBC;
else if (c->frequency < 250000000)
cp = 0xB4;
else if (c->frequency < 400000000)
cp = 0xBC;
else if (c->frequency < 420000000)
cp = 0xF4;
else if (c->frequency < 470000000)
cp = 0xFC;
else if (c->frequency < 600000000)
cp = 0xBC;
else if (c->frequency < 730000000)
cp = 0xF4;
else
cp = 0xFC;
if (c->frequency < 150000000)
bs = 0x01;
else if (c->frequency < 173000000)
bs = 0x01;
else if (c->frequency < 250000000)
bs = 0x02;
else if (c->frequency < 400000000)
bs = 0x02;
else if (c->frequency < 420000000)
bs = 0x02;
else if (c->frequency < 470000000)
bs = 0x02;
else if (c->frequency < 600000000)
bs = 0x08;
else if (c->frequency < 730000000)
bs = 0x08;
else
bs = 0x08;
pllbuf[0] = 0x61;
pllbuf[1] = div >> 8;
pllbuf[2] = div & 0xff;
pllbuf[3] = cp;
pllbuf[4] = bs;
return 5;
}
static int or51211_request_firmware(struct dvb_frontend* fe, const struct firmware **fw, char* name)
{
struct dvb_bt8xx_card* bt = (struct dvb_bt8xx_card*) fe->dvb->priv;
return request_firmware(fw, name, &bt->bt->dev->dev);
}
static void or51211_setmode(struct dvb_frontend * fe, int mode)
{
struct dvb_bt8xx_card *bt = fe->dvb->priv;
bttv_write_gpio(bt->bttv_nr, 0x0002, mode);
msleep(20);
}
static void or51211_reset(struct dvb_frontend * fe)
{
struct dvb_bt8xx_card *bt = fe->dvb->priv;
int ret = bttv_gpio_enable(bt->bttv_nr, 0x001F, 0x001F);
if (ret != 0)
pr_warn("or51211: Init Error - Can't Reset DVR (%i)\n", ret);
bttv_write_gpio(bt->bttv_nr, 0x001F, 0x0000);
msleep(20);
bttv_write_gpio(bt->bttv_nr, 0x0001F, 0x0001);
msleep(500);
}
static void or51211_sleep(struct dvb_frontend * fe)
{
struct dvb_bt8xx_card *bt = fe->dvb->priv;
bttv_write_gpio(bt->bttv_nr, 0x0001, 0x0000);
}
static int vp3021_alps_tded4_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_bt8xx_card *card = (struct dvb_bt8xx_card *) fe->dvb->priv;
u8 buf[4];
u32 div;
struct i2c_msg msg = { .addr = 0x60, .flags = 0, .buf = buf, .len = sizeof(buf) };
div = (c->frequency + 36166667) / 166667;
buf[0] = (div >> 8) & 0x7F;
buf[1] = div & 0xFF;
buf[2] = 0x85;
if ((c->frequency >= 47000000) && (c->frequency < 153000000))
buf[3] = 0x01;
else if ((c->frequency >= 153000000) && (c->frequency < 430000000))
buf[3] = 0x02;
else if ((c->frequency >= 430000000) && (c->frequency < 824000000))
buf[3] = 0x0C;
else if ((c->frequency >= 824000000) && (c->frequency < 863000000))
buf[3] = 0x8C;
else
return -EINVAL;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
i2c_transfer(card->i2c_adapter, &msg, 1);
return 0;
}
static int digitv_alps_tded4_demod_init(struct dvb_frontend* fe)
{
static u8 mt352_clock_config [] = { 0x89, 0x38, 0x2d };
static u8 mt352_reset [] = { 0x50, 0x80 };
static u8 mt352_adc_ctl_1_cfg [] = { 0x8E, 0x40 };
static u8 mt352_agc_cfg [] = { 0x67, 0x20, 0xa0 };
static u8 mt352_capt_range_cfg[] = { 0x75, 0x32 };
mt352_write(fe, mt352_clock_config, sizeof(mt352_clock_config));
udelay(2000);
mt352_write(fe, mt352_reset, sizeof(mt352_reset));
mt352_write(fe, mt352_adc_ctl_1_cfg, sizeof(mt352_adc_ctl_1_cfg));
mt352_write(fe, mt352_agc_cfg,sizeof(mt352_agc_cfg));
mt352_write(fe, mt352_capt_range_cfg, sizeof(mt352_capt_range_cfg));
return 0;
}
static int digitv_alps_tded4_tuner_calc_regs(struct dvb_frontend *fe, u8 *pllbuf, int buf_len)
{
u32 div;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (buf_len < 5)
return -EINVAL;
div = (((c->frequency + 83333) * 3) / 500000) + IF_FREQUENCYx6;
pllbuf[0] = 0x61;
pllbuf[1] = (div >> 8) & 0x7F;
pllbuf[2] = div & 0xFF;
pllbuf[3] = 0x85;
dprintk("frequency %u, div %u\n", c->frequency, div);
if (c->frequency < 470000000)
pllbuf[4] = 0x02;
else if (c->frequency > 823000000)
pllbuf[4] = 0x88;
else
pllbuf[4] = 0x08;
if (c->bandwidth_hz == 8000000)
pllbuf[4] |= 0x04;
return 5;
}
static void digitv_alps_tded4_reset(struct dvb_bt8xx_card *bt)
{
int ret = bttv_gpio_enable(bt->bttv_nr, 0x08, 0x08);
if (ret != 0)
pr_warn("digitv_alps_tded4: Init Error - Can't Reset DVR (%i)\n",
ret);
bttv_write_gpio(bt->bttv_nr, 0x08, 0x08);
bttv_write_gpio(bt->bttv_nr, 0x08, 0x00);
msleep(100);
bttv_write_gpio(bt->bttv_nr, 0x08, 0x08);
}
static void lgdt330x_reset(struct dvb_bt8xx_card *bt)
{
bttv_write_gpio(bt->bttv_nr, 0x00e00007, 0x00000001);
bttv_write_gpio(bt->bttv_nr, 0x00e00007, 0x00000000);
msleep(100);
bttv_write_gpio(bt->bttv_nr, 0x00e00007, 0x00000001);
msleep(100);
}
static void frontend_init(struct dvb_bt8xx_card *card, u32 type)
{
struct dst_state* state = NULL;
switch(type) {
case BTTV_BOARD_DVICO_DVBT_LITE:
card->fe = dvb_attach(mt352_attach, &thomson_dtt7579_config, card->i2c_adapter);
if (card->fe == NULL)
card->fe = dvb_attach(zl10353_attach, &thomson_dtt7579_zl10353_config,
card->i2c_adapter);
if (card->fe != NULL) {
card->fe->ops.tuner_ops.calc_regs = thomson_dtt7579_tuner_calc_regs;
card->fe->ops.info.frequency_min = 174000000;
card->fe->ops.info.frequency_max = 862000000;
}
break;
case BTTV_BOARD_DVICO_FUSIONHDTV_5_LITE:
lgdt330x_reset(card);
card->fe = dvb_attach(lgdt330x_attach, &tdvs_tua6034_config, card->i2c_adapter);
if (card->fe != NULL) {
dvb_attach(simple_tuner_attach, card->fe,
card->i2c_adapter, 0x61,
TUNER_LG_TDVS_H06XF);
dprintk("dvb_bt8xx: lgdt330x detected\n");
}
break;
case BTTV_BOARD_NEBULA_DIGITV:
digitv_alps_tded4_reset(card);
card->fe = dvb_attach(nxt6000_attach, &vp3021_alps_tded4_config, card->i2c_adapter);
if (card->fe != NULL) {
card->fe->ops.tuner_ops.set_params = vp3021_alps_tded4_tuner_set_params;
dprintk("dvb_bt8xx: an nxt6000 was detected on your digitv card\n");
break;
}
digitv_alps_tded4_reset(card);
card->fe = dvb_attach(mt352_attach, &digitv_alps_tded4_config, card->i2c_adapter);
if (card->fe != NULL) {
card->fe->ops.tuner_ops.calc_regs = digitv_alps_tded4_tuner_calc_regs;
dprintk("dvb_bt8xx: an mt352 was detected on your digitv card\n");
}
break;
case BTTV_BOARD_AVDVBT_761:
card->fe = dvb_attach(sp887x_attach, &microtune_mt7202dtf_config, card->i2c_adapter);
if (card->fe) {
card->fe->ops.tuner_ops.set_params = microtune_mt7202dtf_tuner_set_params;
}
break;
case BTTV_BOARD_AVDVBT_771:
card->fe = dvb_attach(mt352_attach, &advbt771_samsung_tdtc9251dh0_config, card->i2c_adapter);
if (card->fe != NULL) {
card->fe->ops.tuner_ops.calc_regs = advbt771_samsung_tdtc9251dh0_tuner_calc_regs;
card->fe->ops.info.frequency_min = 174000000;
card->fe->ops.info.frequency_max = 862000000;
}
break;
case BTTV_BOARD_TWINHAN_DST:
state = kmalloc(sizeof (struct dst_state), GFP_KERNEL);
if (!state) {
pr_err("No memory\n");
break;
}
state->config = &dst_config;
state->i2c = card->i2c_adapter;
state->bt = card->bt;
state->dst_ca = NULL;
if (dvb_attach(dst_attach, state, &card->dvb_adapter) == NULL) {
pr_err("%s: Could not find a Twinhan DST\n", __func__);
break;
}
card->fe = &state->frontend;
if (state->dst_hw_cap & DST_TYPE_HAS_CA)
dvb_attach(dst_ca_attach, state, &card->dvb_adapter);
break;
case BTTV_BOARD_PINNACLESAT:
card->fe = dvb_attach(cx24110_attach, &pctvsat_config, card->i2c_adapter);
if (card->fe) {
card->fe->ops.tuner_ops.init = pinnsat_tuner_init;
card->fe->ops.tuner_ops.sleep = pinnsat_tuner_sleep;
card->fe->ops.tuner_ops.set_params = cx24108_tuner_set_params;
}
break;
case BTTV_BOARD_PC_HDTV:
card->fe = dvb_attach(or51211_attach, &or51211_config, card->i2c_adapter);
if (card->fe != NULL)
dvb_attach(simple_tuner_attach, card->fe,
card->i2c_adapter, 0x61,
TUNER_PHILIPS_FCV1236D);
break;
}
if (card->fe == NULL)
pr_err("A frontend driver was not found for device [%04x:%04x] subsystem [%04x:%04x]\n",
card->bt->dev->vendor,
card->bt->dev->device,
card->bt->dev->subsystem_vendor,
card->bt->dev->subsystem_device);
else
if (dvb_register_frontend(&card->dvb_adapter, card->fe)) {
pr_err("Frontend registration failed!\n");
dvb_frontend_detach(card->fe);
card->fe = NULL;
}
}
static int dvb_bt8xx_load_card(struct dvb_bt8xx_card *card, u32 type)
{
int result;
result = dvb_register_adapter(&card->dvb_adapter, card->card_name,
THIS_MODULE, &card->bt->dev->dev,
adapter_nr);
if (result < 0) {
pr_err("dvb_register_adapter failed (errno = %d)\n", result);
return result;
}
card->dvb_adapter.priv = card;
card->bt->adapter = card->i2c_adapter;
memset(&card->demux, 0, sizeof(struct dvb_demux));
card->demux.dmx.capabilities = DMX_TS_FILTERING | DMX_SECTION_FILTERING | DMX_MEMORY_BASED_FILTERING;
card->demux.priv = card;
card->demux.filternum = 256;
card->demux.feednum = 256;
card->demux.start_feed = dvb_bt8xx_start_feed;
card->demux.stop_feed = dvb_bt8xx_stop_feed;
card->demux.write_to_decoder = NULL;
result = dvb_dmx_init(&card->demux);
if (result < 0) {
pr_err("dvb_dmx_init failed (errno = %d)\n", result);
goto err_unregister_adaptor;
}
card->dmxdev.filternum = 256;
card->dmxdev.demux = &card->demux.dmx;
card->dmxdev.capabilities = 0;
result = dvb_dmxdev_init(&card->dmxdev, &card->dvb_adapter);
if (result < 0) {
pr_err("dvb_dmxdev_init failed (errno = %d)\n", result);
goto err_dmx_release;
}
card->fe_hw.source = DMX_FRONTEND_0;
result = card->demux.dmx.add_frontend(&card->demux.dmx, &card->fe_hw);
if (result < 0) {
pr_err("dvb_dmx_init failed (errno = %d)\n", result);
goto err_dmxdev_release;
}
card->fe_mem.source = DMX_MEMORY_FE;
result = card->demux.dmx.add_frontend(&card->demux.dmx, &card->fe_mem);
if (result < 0) {
pr_err("dvb_dmx_init failed (errno = %d)\n", result);
goto err_remove_hw_frontend;
}
result = card->demux.dmx.connect_frontend(&card->demux.dmx, &card->fe_hw);
if (result < 0) {
pr_err("dvb_dmx_init failed (errno = %d)\n", result);
goto err_remove_mem_frontend;
}
result = dvb_net_init(&card->dvb_adapter, &card->dvbnet, &card->demux.dmx);
if (result < 0) {
pr_err("dvb_net_init failed (errno = %d)\n", result);
goto err_disconnect_frontend;
}
tasklet_init(&card->bt->tasklet, dvb_bt8xx_task, (unsigned long) card);
frontend_init(card, type);
return 0;
err_disconnect_frontend:
card->demux.dmx.disconnect_frontend(&card->demux.dmx);
err_remove_mem_frontend:
card->demux.dmx.remove_frontend(&card->demux.dmx, &card->fe_mem);
err_remove_hw_frontend:
card->demux.dmx.remove_frontend(&card->demux.dmx, &card->fe_hw);
err_dmxdev_release:
dvb_dmxdev_release(&card->dmxdev);
err_dmx_release:
dvb_dmx_release(&card->demux);
err_unregister_adaptor:
dvb_unregister_adapter(&card->dvb_adapter);
return result;
}
static int dvb_bt8xx_probe(struct bttv_sub_device *sub)
{
struct dvb_bt8xx_card *card;
struct pci_dev* bttv_pci_dev;
int ret;
if (!(card = kzalloc(sizeof(struct dvb_bt8xx_card), GFP_KERNEL)))
return -ENOMEM;
mutex_init(&card->lock);
card->bttv_nr = sub->core->nr;
strlcpy(card->card_name, sub->core->v4l2_dev.name, sizeof(card->card_name));
card->i2c_adapter = &sub->core->i2c_adap;
switch(sub->core->type) {
case BTTV_BOARD_PINNACLESAT:
card->gpio_mode = 0x0400c060;
card->op_sync_orin = BT878_RISC_SYNC_MASK;
card->irq_err_ignore = BT878_AFBUS | BT878_AFDSR;
break;
case BTTV_BOARD_DVICO_DVBT_LITE:
card->gpio_mode = 0x0400C060;
card->op_sync_orin = BT878_RISC_SYNC_MASK;
card->irq_err_ignore = BT878_AFBUS | BT878_AFDSR;
break;
case BTTV_BOARD_DVICO_FUSIONHDTV_5_LITE:
card->gpio_mode = 0x0400c060;
card->op_sync_orin = BT878_RISC_SYNC_MASK;
card->irq_err_ignore = BT878_AFBUS | BT878_AFDSR;
break;
case BTTV_BOARD_NEBULA_DIGITV:
case BTTV_BOARD_AVDVBT_761:
card->gpio_mode = (1 << 26) | (1 << 14) | (1 << 5);
card->op_sync_orin = BT878_RISC_SYNC_MASK;
card->irq_err_ignore = BT878_AFBUS | BT878_AFDSR;
break;
case BTTV_BOARD_AVDVBT_771:
card->gpio_mode = 0x0400402B;
card->op_sync_orin = BT878_RISC_SYNC_MASK;
card->irq_err_ignore = BT878_AFBUS | BT878_AFDSR;
break;
case BTTV_BOARD_TWINHAN_DST:
card->gpio_mode = 0x2204f2c;
card->op_sync_orin = BT878_RISC_SYNC_MASK;
card->irq_err_ignore = BT878_APABORT | BT878_ARIPERR |
BT878_APPERR | BT878_AFBUS;
break;
case BTTV_BOARD_PC_HDTV:
card->gpio_mode = 0x0100EC7B;
card->op_sync_orin = BT878_RISC_SYNC_MASK;
card->irq_err_ignore = BT878_AFBUS | BT878_AFDSR;
break;
default:
pr_err("Unknown bttv card type: %d\n", sub->core->type);
kfree(card);
return -ENODEV;
}
dprintk("dvb_bt8xx: identified card%d as %s\n", card->bttv_nr, card->card_name);
if (!(bttv_pci_dev = bttv_get_pcidev(card->bttv_nr))) {
pr_err("no pci device for card %d\n", card->bttv_nr);
kfree(card);
return -ENODEV;
}
if (!(card->bt = dvb_bt8xx_878_match(card->bttv_nr, bttv_pci_dev))) {
pr_err("unable to determine DMA core of card %d,\n", card->bttv_nr);
pr_err("if you have the ALSA bt87x audio driver installed, try removing it.\n");
kfree(card);
return -ENODEV;
}
mutex_init(&card->bt->gpio_lock);
card->bt->bttv_nr = sub->core->nr;
if ( (ret = dvb_bt8xx_load_card(card, sub->core->type)) ) {
kfree(card);
return ret;
}
dev_set_drvdata(&sub->dev, card);
return 0;
}
static void dvb_bt8xx_remove(struct bttv_sub_device *sub)
{
struct dvb_bt8xx_card *card = dev_get_drvdata(&sub->dev);
dprintk("dvb_bt8xx: unloading card%d\n", card->bttv_nr);
bt878_stop(card->bt);
tasklet_kill(&card->bt->tasklet);
dvb_net_release(&card->dvbnet);
card->demux.dmx.remove_frontend(&card->demux.dmx, &card->fe_mem);
card->demux.dmx.remove_frontend(&card->demux.dmx, &card->fe_hw);
dvb_dmxdev_release(&card->dmxdev);
dvb_dmx_release(&card->demux);
if (card->fe) {
dvb_unregister_frontend(card->fe);
dvb_frontend_detach(card->fe);
}
dvb_unregister_adapter(&card->dvb_adapter);
kfree(card);
}
static int __init dvb_bt8xx_init(void)
{
return bttv_sub_register(&driver, "dvb");
}
static void __exit dvb_bt8xx_exit(void)
{
bttv_sub_unregister(&driver);
}
