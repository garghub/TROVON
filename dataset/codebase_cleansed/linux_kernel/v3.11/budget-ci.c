static void msp430_ir_interrupt(unsigned long data)
{
struct budget_ci *budget_ci = (struct budget_ci *) data;
struct rc_dev *dev = budget_ci->ir.dev;
u32 command = ttpci_budget_debiread(&budget_ci->budget, DEBINOSWAP, DEBIADDR_IR, 2, 1, 0) >> 8;
if (ir_debug)
printk("budget_ci: received byte 0x%02x\n", command);
command = command & 0x7f;
if (command & 0x40) {
budget_ci->ir.have_command = true;
budget_ci->ir.ir_key = command & 0x3f;
return;
}
if (!budget_ci->ir.have_command)
return;
budget_ci->ir.have_command = false;
if (budget_ci->ir.rc5_device != IR_DEVICE_ANY &&
budget_ci->ir.rc5_device != (command & 0x1f))
return;
if (budget_ci->ir.full_rc5) {
rc_keydown(dev,
budget_ci->ir.rc5_device <<8 | budget_ci->ir.ir_key,
(command & 0x20) ? 1 : 0);
return;
}
rc_keydown(dev, budget_ci->ir.ir_key, (command & 0x20) ? 1 : 0);
}
static int msp430_ir_init(struct budget_ci *budget_ci)
{
struct saa7146_dev *saa = budget_ci->budget.dev;
struct rc_dev *dev;
int error;
dev = rc_allocate_device();
if (!dev) {
printk(KERN_ERR "budget_ci: IR interface initialisation failed\n");
return -ENOMEM;
}
snprintf(budget_ci->ir.name, sizeof(budget_ci->ir.name),
"Budget-CI dvb ir receiver %s", saa->name);
snprintf(budget_ci->ir.phys, sizeof(budget_ci->ir.phys),
"pci-%s/ir0", pci_name(saa->pci));
dev->driver_name = MODULE_NAME;
dev->input_name = budget_ci->ir.name;
dev->input_phys = budget_ci->ir.phys;
dev->input_id.bustype = BUS_PCI;
dev->input_id.version = 1;
if (saa->pci->subsystem_vendor) {
dev->input_id.vendor = saa->pci->subsystem_vendor;
dev->input_id.product = saa->pci->subsystem_device;
} else {
dev->input_id.vendor = saa->pci->vendor;
dev->input_id.product = saa->pci->device;
}
dev->dev.parent = &saa->pci->dev;
if (rc5_device < 0)
budget_ci->ir.rc5_device = IR_DEVICE_ANY;
else
budget_ci->ir.rc5_device = rc5_device;
switch (budget_ci->budget.dev->pci->subsystem_device) {
case 0x100c:
case 0x100f:
case 0x1011:
case 0x1012:
dev->map_name = RC_MAP_HAUPPAUGE;
budget_ci->ir.full_rc5 = true;
if (rc5_device < 0)
budget_ci->ir.rc5_device = 0x1f;
break;
case 0x1010:
case 0x1017:
case 0x1019:
case 0x101a:
case 0x101b:
dev->map_name = RC_MAP_TT_1500;
break;
default:
dev->map_name = RC_MAP_BUDGET_CI_OLD;
break;
}
if (!budget_ci->ir.full_rc5)
dev->scanmask = 0xff;
error = rc_register_device(dev);
if (error) {
printk(KERN_ERR "budget_ci: could not init driver for IR device (code %d)\n", error);
rc_free_device(dev);
return error;
}
budget_ci->ir.dev = dev;
tasklet_init(&budget_ci->ir.msp430_irq_tasklet, msp430_ir_interrupt,
(unsigned long) budget_ci);
SAA7146_IER_ENABLE(saa, MASK_06);
saa7146_setgpio(saa, 3, SAA7146_GPIO_IRQHI);
return 0;
}
static void msp430_ir_deinit(struct budget_ci *budget_ci)
{
struct saa7146_dev *saa = budget_ci->budget.dev;
SAA7146_IER_DISABLE(saa, MASK_06);
saa7146_setgpio(saa, 3, SAA7146_GPIO_INPUT);
tasklet_kill(&budget_ci->ir.msp430_irq_tasklet);
rc_unregister_device(budget_ci->ir.dev);
}
static int ciintf_read_attribute_mem(struct dvb_ca_en50221 *ca, int slot, int address)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
if (slot != 0)
return -EINVAL;
return ttpci_budget_debiread(&budget_ci->budget, DEBICICAM,
DEBIADDR_ATTR | (address & 0xfff), 1, 1, 0);
}
static int ciintf_write_attribute_mem(struct dvb_ca_en50221 *ca, int slot, int address, u8 value)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
if (slot != 0)
return -EINVAL;
return ttpci_budget_debiwrite(&budget_ci->budget, DEBICICAM,
DEBIADDR_ATTR | (address & 0xfff), 1, value, 1, 0);
}
static int ciintf_read_cam_control(struct dvb_ca_en50221 *ca, int slot, u8 address)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
if (slot != 0)
return -EINVAL;
return ttpci_budget_debiread(&budget_ci->budget, DEBICICAM,
DEBIADDR_IO | (address & 3), 1, 1, 0);
}
static int ciintf_write_cam_control(struct dvb_ca_en50221 *ca, int slot, u8 address, u8 value)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
if (slot != 0)
return -EINVAL;
return ttpci_budget_debiwrite(&budget_ci->budget, DEBICICAM,
DEBIADDR_IO | (address & 3), 1, value, 1, 0);
}
static int ciintf_slot_reset(struct dvb_ca_en50221 *ca, int slot)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
struct saa7146_dev *saa = budget_ci->budget.dev;
if (slot != 0)
return -EINVAL;
if (budget_ci->ci_irq) {
saa7146_setgpio(saa, 0, SAA7146_GPIO_IRQHI);
}
budget_ci->slot_status = SLOTSTATUS_RESET;
ttpci_budget_debiwrite(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1, 0, 1, 0);
msleep(1);
ttpci_budget_debiwrite(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1,
CICONTROL_RESET, 1, 0);
saa7146_setgpio(saa, 1, SAA7146_GPIO_OUTHI);
ttpci_budget_set_video_port(saa, BUDGET_VIDEO_PORTB);
return 0;
}
static int ciintf_slot_shutdown(struct dvb_ca_en50221 *ca, int slot)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
struct saa7146_dev *saa = budget_ci->budget.dev;
if (slot != 0)
return -EINVAL;
saa7146_setgpio(saa, 1, SAA7146_GPIO_OUTHI);
ttpci_budget_set_video_port(saa, BUDGET_VIDEO_PORTB);
return 0;
}
static int ciintf_slot_ts_enable(struct dvb_ca_en50221 *ca, int slot)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
struct saa7146_dev *saa = budget_ci->budget.dev;
int tmp;
if (slot != 0)
return -EINVAL;
saa7146_setgpio(saa, 1, SAA7146_GPIO_OUTLO);
tmp = ttpci_budget_debiread(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1, 1, 0);
ttpci_budget_debiwrite(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1,
tmp | CICONTROL_ENABLETS, 1, 0);
ttpci_budget_set_video_port(saa, BUDGET_VIDEO_PORTA);
return 0;
}
static void ciintf_interrupt(unsigned long data)
{
struct budget_ci *budget_ci = (struct budget_ci *) data;
struct saa7146_dev *saa = budget_ci->budget.dev;
unsigned int flags;
if (!budget_ci->budget.ci_present)
return;
flags = ttpci_budget_debiread(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1, 1, 0);
if (flags & CICONTROL_CAMDETECT) {
saa7146_setgpio(saa, 0, SAA7146_GPIO_IRQLO);
if (budget_ci->slot_status & SLOTSTATUS_NONE) {
budget_ci->slot_status = SLOTSTATUS_PRESENT;
dvb_ca_en50221_camchange_irq(&budget_ci->ca, 0,
DVB_CA_EN50221_CAMCHANGE_INSERTED);
} else if (budget_ci->slot_status & SLOTSTATUS_RESET) {
budget_ci->slot_status = SLOTSTATUS_READY;
dvb_ca_en50221_camready_irq(&budget_ci->ca, 0);
} else if (budget_ci->slot_status & SLOTSTATUS_READY) {
dvb_ca_en50221_frda_irq(&budget_ci->ca, 0);
}
} else {
saa7146_setgpio(saa, 0, SAA7146_GPIO_IRQHI);
if (budget_ci->slot_status & SLOTSTATUS_OCCUPIED) {
budget_ci->slot_status = SLOTSTATUS_NONE;
dvb_ca_en50221_camchange_irq(&budget_ci->ca, 0,
DVB_CA_EN50221_CAMCHANGE_REMOVED);
}
}
}
static int ciintf_poll_slot_status(struct dvb_ca_en50221 *ca, int slot, int open)
{
struct budget_ci *budget_ci = (struct budget_ci *) ca->data;
unsigned int flags;
if (!budget_ci->budget.ci_present)
return -EINVAL;
flags = ttpci_budget_debiread(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1, 1, 0);
if (flags & CICONTROL_CAMDETECT) {
if (budget_ci->slot_status & SLOTSTATUS_NONE) {
budget_ci->slot_status = SLOTSTATUS_PRESENT;
}
if (budget_ci->slot_status & SLOTSTATUS_RESET) {
if (ciintf_read_attribute_mem(ca, slot, 0) == 0x1d) {
budget_ci->slot_status = SLOTSTATUS_READY;
}
}
} else {
budget_ci->slot_status = SLOTSTATUS_NONE;
}
if (budget_ci->slot_status != SLOTSTATUS_NONE) {
if (budget_ci->slot_status & SLOTSTATUS_READY) {
return DVB_CA_EN50221_POLL_CAM_PRESENT | DVB_CA_EN50221_POLL_CAM_READY;
}
return DVB_CA_EN50221_POLL_CAM_PRESENT;
}
return 0;
}
static int ciintf_init(struct budget_ci *budget_ci)
{
struct saa7146_dev *saa = budget_ci->budget.dev;
int flags;
int result;
int ci_version;
int ca_flags;
memset(&budget_ci->ca, 0, sizeof(struct dvb_ca_en50221));
saa7146_write(saa, MC1, MASK_27 | MASK_11);
ci_version = ttpci_budget_debiread(&budget_ci->budget, DEBICICTL, DEBIADDR_CIVERSION, 1, 1, 0);
if ((ci_version & 0xa0) != 0xa0) {
result = -ENODEV;
goto error;
}
flags = ttpci_budget_debiread(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1, 1, 0);
budget_ci->slot_status = SLOTSTATUS_NONE;
if (flags & CICONTROL_CAMDETECT)
budget_ci->slot_status = SLOTSTATUS_PRESENT;
if (ci_version == 0xa2) {
ca_flags = 0;
budget_ci->ci_irq = 0;
} else {
ca_flags = DVB_CA_EN50221_FLAG_IRQ_CAMCHANGE |
DVB_CA_EN50221_FLAG_IRQ_FR |
DVB_CA_EN50221_FLAG_IRQ_DA;
budget_ci->ci_irq = 1;
}
budget_ci->ca.owner = THIS_MODULE;
budget_ci->ca.read_attribute_mem = ciintf_read_attribute_mem;
budget_ci->ca.write_attribute_mem = ciintf_write_attribute_mem;
budget_ci->ca.read_cam_control = ciintf_read_cam_control;
budget_ci->ca.write_cam_control = ciintf_write_cam_control;
budget_ci->ca.slot_reset = ciintf_slot_reset;
budget_ci->ca.slot_shutdown = ciintf_slot_shutdown;
budget_ci->ca.slot_ts_enable = ciintf_slot_ts_enable;
budget_ci->ca.poll_slot_status = ciintf_poll_slot_status;
budget_ci->ca.data = budget_ci;
if ((result = dvb_ca_en50221_init(&budget_ci->budget.dvb_adapter,
&budget_ci->ca,
ca_flags, 1)) != 0) {
printk("budget_ci: CI interface detected, but initialisation failed.\n");
goto error;
}
if (budget_ci->ci_irq) {
tasklet_init(&budget_ci->ciintf_irq_tasklet, ciintf_interrupt, (unsigned long) budget_ci);
if (budget_ci->slot_status != SLOTSTATUS_NONE) {
saa7146_setgpio(saa, 0, SAA7146_GPIO_IRQLO);
} else {
saa7146_setgpio(saa, 0, SAA7146_GPIO_IRQHI);
}
SAA7146_IER_ENABLE(saa, MASK_03);
}
ttpci_budget_debiwrite(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1,
CICONTROL_RESET, 1, 0);
printk("budget_ci: CI interface initialised\n");
budget_ci->budget.ci_present = 1;
if (budget_ci->ci_irq) {
flags = DVB_CA_EN50221_CAMCHANGE_REMOVED;
if (budget_ci->slot_status != SLOTSTATUS_NONE)
flags = DVB_CA_EN50221_CAMCHANGE_INSERTED;
dvb_ca_en50221_camchange_irq(&budget_ci->ca, 0, flags);
}
return 0;
error:
saa7146_write(saa, MC1, MASK_27);
return result;
}
static void ciintf_deinit(struct budget_ci *budget_ci)
{
struct saa7146_dev *saa = budget_ci->budget.dev;
if (budget_ci->ci_irq) {
SAA7146_IER_DISABLE(saa, MASK_03);
saa7146_setgpio(saa, 0, SAA7146_GPIO_INPUT);
tasklet_kill(&budget_ci->ciintf_irq_tasklet);
}
ttpci_budget_debiwrite(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1, 0, 1, 0);
msleep(1);
ttpci_budget_debiwrite(&budget_ci->budget, DEBICICTL, DEBIADDR_CICONTROL, 1,
CICONTROL_RESET, 1, 0);
saa7146_setgpio(saa, 1, SAA7146_GPIO_INPUT);
dvb_ca_en50221_release(&budget_ci->ca);
saa7146_write(saa, MC1, MASK_27);
}
static void budget_ci_irq(struct saa7146_dev *dev, u32 * isr)
{
struct budget_ci *budget_ci = (struct budget_ci *) dev->ext_priv;
dprintk(8, "dev: %p, budget_ci: %p\n", dev, budget_ci);
if (*isr & MASK_06)
tasklet_schedule(&budget_ci->ir.msp430_irq_tasklet);
if (*isr & MASK_10)
ttpci_budget_irq10_handler(dev, isr);
if ((*isr & MASK_03) && (budget_ci->budget.ci_present) && (budget_ci->ci_irq))
tasklet_schedule(&budget_ci->ciintf_irq_tasklet);
}
static int philips_su1278_tt_set_symbol_rate(struct dvb_frontend *fe, u32 srate, u32 ratio)
{
stv0299_writereg(fe, 0x0e, 0x44);
if (srate >= 10000000) {
stv0299_writereg(fe, 0x13, 0x97);
stv0299_writereg(fe, 0x14, 0x95);
stv0299_writereg(fe, 0x15, 0xc9);
stv0299_writereg(fe, 0x17, 0x8c);
stv0299_writereg(fe, 0x1a, 0xfe);
stv0299_writereg(fe, 0x1c, 0x7f);
stv0299_writereg(fe, 0x2d, 0x09);
} else {
stv0299_writereg(fe, 0x13, 0x99);
stv0299_writereg(fe, 0x14, 0x8d);
stv0299_writereg(fe, 0x15, 0xce);
stv0299_writereg(fe, 0x17, 0x43);
stv0299_writereg(fe, 0x1a, 0x1d);
stv0299_writereg(fe, 0x1c, 0x12);
stv0299_writereg(fe, 0x2d, 0x05);
}
stv0299_writereg(fe, 0x0e, 0x23);
stv0299_writereg(fe, 0x0f, 0x94);
stv0299_writereg(fe, 0x10, 0x39);
stv0299_writereg(fe, 0x15, 0xc9);
stv0299_writereg(fe, 0x1f, (ratio >> 16) & 0xff);
stv0299_writereg(fe, 0x20, (ratio >> 8) & 0xff);
stv0299_writereg(fe, 0x21, (ratio) & 0xf0);
return 0;
}
static int philips_su1278_tt_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct budget_ci *budget_ci = (struct budget_ci *) fe->dvb->priv;
u32 div;
u8 buf[4];
struct i2c_msg msg = {.addr = 0x60,.flags = 0,.buf = buf,.len = sizeof(buf) };
if ((p->frequency < 950000) || (p->frequency > 2150000))
return -EINVAL;
div = (p->frequency + (500 - 1)) / 500;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0x80 | ((div & 0x18000) >> 10) | 2;
buf[3] = 0x20;
if (p->symbol_rate < 4000000)
buf[3] |= 1;
if (p->frequency < 1250000)
buf[3] |= 0;
else if (p->frequency < 1550000)
buf[3] |= 0x40;
else if (p->frequency < 2050000)
buf[3] |= 0x80;
else if (p->frequency < 2150000)
buf[3] |= 0xC0;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget_ci->budget.i2c_adap, &msg, 1) != 1)
return -EIO;
return 0;
}
static int philips_tdm1316l_tuner_init(struct dvb_frontend *fe)
{
struct budget_ci *budget_ci = (struct budget_ci *) fe->dvb->priv;
static u8 td1316_init[] = { 0x0b, 0xf5, 0x85, 0xab };
static u8 disable_mc44BC374c[] = { 0x1d, 0x74, 0xa0, 0x68 };
struct i2c_msg tuner_msg = {.addr = budget_ci->tuner_pll_address,.flags = 0,.buf = td1316_init,.len =
sizeof(td1316_init) };
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget_ci->budget.i2c_adap, &tuner_msg, 1) != 1)
return -EIO;
msleep(1);
tuner_msg.addr = 0x65;
tuner_msg.buf = disable_mc44BC374c;
tuner_msg.len = sizeof(disable_mc44BC374c);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget_ci->budget.i2c_adap, &tuner_msg, 1) != 1) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
i2c_transfer(&budget_ci->budget.i2c_adap, &tuner_msg, 1);
}
return 0;
}
static int philips_tdm1316l_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct budget_ci *budget_ci = (struct budget_ci *) fe->dvb->priv;
u8 tuner_buf[4];
struct i2c_msg tuner_msg = {.addr = budget_ci->tuner_pll_address,.flags = 0,.buf = tuner_buf,.len = sizeof(tuner_buf) };
int tuner_frequency = 0;
u8 band, cp, filter;
tuner_frequency = p->frequency + 36130000;
if (tuner_frequency < 87000000)
return -EINVAL;
else if (tuner_frequency < 130000000)
cp = 3;
else if (tuner_frequency < 160000000)
cp = 5;
else if (tuner_frequency < 200000000)
cp = 6;
else if (tuner_frequency < 290000000)
cp = 3;
else if (tuner_frequency < 420000000)
cp = 5;
else if (tuner_frequency < 480000000)
cp = 6;
else if (tuner_frequency < 620000000)
cp = 3;
else if (tuner_frequency < 830000000)
cp = 5;
else if (tuner_frequency < 895000000)
cp = 7;
else
return -EINVAL;
if (p->frequency < 49000000)
return -EINVAL;
else if (p->frequency < 159000000)
band = 1;
else if (p->frequency < 444000000)
band = 2;
else if (p->frequency < 861000000)
band = 4;
else
return -EINVAL;
switch (p->bandwidth_hz) {
case 6000000:
tda1004x_writereg(fe, 0x0C, 0x14);
filter = 0;
break;
case 7000000:
tda1004x_writereg(fe, 0x0C, 0x80);
filter = 0;
break;
case 8000000:
tda1004x_writereg(fe, 0x0C, 0x14);
filter = 1;
break;
default:
return -EINVAL;
}
tuner_frequency = (((p->frequency / 1000) * 6) + 217280) / 1000;
tuner_buf[0] = tuner_frequency >> 8;
tuner_buf[1] = tuner_frequency & 0xff;
tuner_buf[2] = 0xca;
tuner_buf[3] = (cp << 5) | (filter << 3) | band;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget_ci->budget.i2c_adap, &tuner_msg, 1) != 1)
return -EIO;
msleep(1);
return 0;
}
static int philips_tdm1316l_request_firmware(struct dvb_frontend *fe,
const struct firmware **fw, char *name)
{
struct budget_ci *budget_ci = (struct budget_ci *) fe->dvb->priv;
return request_firmware(fw, name, &budget_ci->budget.dev->pci->dev);
}
static int dvbc_philips_tdm1316l_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct budget_ci *budget_ci = (struct budget_ci *) fe->dvb->priv;
u8 tuner_buf[5];
struct i2c_msg tuner_msg = {.addr = budget_ci->tuner_pll_address,
.flags = 0,
.buf = tuner_buf,
.len = sizeof(tuner_buf) };
int tuner_frequency = 0;
u8 band, cp, filter;
tuner_frequency = p->frequency + 36125000;
if (tuner_frequency < 87000000)
return -EINVAL;
else if (tuner_frequency < 130000000) {
cp = 3;
band = 1;
} else if (tuner_frequency < 160000000) {
cp = 5;
band = 1;
} else if (tuner_frequency < 200000000) {
cp = 6;
band = 1;
} else if (tuner_frequency < 290000000) {
cp = 3;
band = 2;
} else if (tuner_frequency < 420000000) {
cp = 5;
band = 2;
} else if (tuner_frequency < 480000000) {
cp = 6;
band = 2;
} else if (tuner_frequency < 620000000) {
cp = 3;
band = 4;
} else if (tuner_frequency < 830000000) {
cp = 5;
band = 4;
} else if (tuner_frequency < 895000000) {
cp = 7;
band = 4;
} else
return -EINVAL;
filter = 1;
tuner_frequency = (p->frequency + 36125000 + (62500/2)) / 62500;
tuner_buf[0] = tuner_frequency >> 8;
tuner_buf[1] = tuner_frequency & 0xff;
tuner_buf[2] = 0xc8;
tuner_buf[3] = (cp << 5) | (filter << 3) | band;
tuner_buf[4] = 0x80;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget_ci->budget.i2c_adap, &tuner_msg, 1) != 1)
return -EIO;
msleep(50);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&budget_ci->budget.i2c_adap, &tuner_msg, 1) != 1)
return -EIO;
msleep(1);
return 0;
}
static void frontend_init(struct budget_ci *budget_ci)
{
switch (budget_ci->budget.dev->pci->subsystem_device) {
case 0x100c:
budget_ci->budget.dvb_frontend =
dvb_attach(stv0299_attach, &alps_bsru6_config, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
budget_ci->budget.dvb_frontend->ops.tuner_ops.set_params = alps_bsru6_tuner_set_params;
budget_ci->budget.dvb_frontend->tuner_priv = &budget_ci->budget.i2c_adap;
break;
}
break;
case 0x100f:
budget_ci->budget.dvb_frontend =
dvb_attach(stv0299_attach, &philips_su1278_tt_config, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
budget_ci->budget.dvb_frontend->ops.tuner_ops.set_params = philips_su1278_tt_tuner_set_params;
break;
}
break;
case 0x1010:
budget_ci->tuner_pll_address = 0x61;
budget_ci->budget.dvb_frontend =
dvb_attach(stv0297_attach, &dvbc_philips_tdm1316l_config, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
budget_ci->budget.dvb_frontend->ops.tuner_ops.set_params = dvbc_philips_tdm1316l_tuner_set_params;
break;
}
break;
case 0x1011:
budget_ci->tuner_pll_address = 0x63;
budget_ci->budget.dvb_frontend =
dvb_attach(tda10045_attach, &philips_tdm1316l_config, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
budget_ci->budget.dvb_frontend->ops.tuner_ops.init = philips_tdm1316l_tuner_init;
budget_ci->budget.dvb_frontend->ops.tuner_ops.set_params = philips_tdm1316l_tuner_set_params;
break;
}
break;
case 0x1012:
budget_ci->tuner_pll_address = 0x60;
budget_ci->budget.dvb_frontend =
dvb_attach(tda10046_attach, &philips_tdm1316l_config_invert, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
budget_ci->budget.dvb_frontend->ops.tuner_ops.init = philips_tdm1316l_tuner_init;
budget_ci->budget.dvb_frontend->ops.tuner_ops.set_params = philips_tdm1316l_tuner_set_params;
break;
}
break;
case 0x1017:
budget_ci->budget.dvb_frontend = dvb_attach(stv0299_attach, &alps_bsbe1_config, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
budget_ci->budget.dvb_frontend->ops.tuner_ops.set_params = alps_bsbe1_tuner_set_params;
budget_ci->budget.dvb_frontend->tuner_priv = &budget_ci->budget.i2c_adap;
budget_ci->budget.dvb_frontend->ops.dishnetwork_send_legacy_command = NULL;
if (dvb_attach(lnbp21_attach, budget_ci->budget.dvb_frontend, &budget_ci->budget.i2c_adap, LNBP21_LLC, 0) == NULL) {
printk("%s: No LNBP21 found!\n", __func__);
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
budget_ci->budget.dvb_frontend = NULL;
}
}
break;
case 0x101a:
budget_ci->budget.dvb_frontend = dvb_attach(tda10023_attach, &tda10023_config, &budget_ci->budget.i2c_adap, 0x48);
if (budget_ci->budget.dvb_frontend) {
if (dvb_attach(tda827x_attach, budget_ci->budget.dvb_frontend, 0x61, &budget_ci->budget.i2c_adap, &tda827x_config) == NULL) {
printk(KERN_ERR "%s: No tda827x found!\n", __func__);
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
budget_ci->budget.dvb_frontend = NULL;
}
}
break;
case 0x101b:
budget_ci->budget.dvb_frontend = dvb_attach(stv0288_attach, &stv0288_bsbe1_d01a_config, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
if (dvb_attach(stb6000_attach, budget_ci->budget.dvb_frontend, 0x63, &budget_ci->budget.i2c_adap)) {
if (!dvb_attach(lnbp21_attach, budget_ci->budget.dvb_frontend, &budget_ci->budget.i2c_adap, 0, 0)) {
printk(KERN_ERR "%s: No LNBP21 found!\n", __func__);
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
budget_ci->budget.dvb_frontend = NULL;
}
} else {
printk(KERN_ERR "%s: No STB6000 found!\n", __func__);
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
budget_ci->budget.dvb_frontend = NULL;
}
}
break;
case 0x1019:
saa7146_setgpio(budget_ci->budget.dev, 2, SAA7146_GPIO_OUTLO);
msleep(50);
saa7146_setgpio(budget_ci->budget.dev, 2, SAA7146_GPIO_OUTHI);
msleep(250);
budget_ci->budget.dvb_frontend = dvb_attach(stb0899_attach, &tt3200_config, &budget_ci->budget.i2c_adap);
if (budget_ci->budget.dvb_frontend) {
if (dvb_attach(stb6100_attach, budget_ci->budget.dvb_frontend, &tt3200_stb6100_config, &budget_ci->budget.i2c_adap)) {
if (!dvb_attach(lnbp21_attach, budget_ci->budget.dvb_frontend, &budget_ci->budget.i2c_adap, 0, 0)) {
printk("%s: No LNBP21 found!\n", __func__);
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
budget_ci->budget.dvb_frontend = NULL;
}
} else {
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
budget_ci->budget.dvb_frontend = NULL;
}
}
break;
}
if (budget_ci->budget.dvb_frontend == NULL) {
printk("budget-ci: A frontend driver was not found for device [%04x:%04x] subsystem [%04x:%04x]\n",
budget_ci->budget.dev->pci->vendor,
budget_ci->budget.dev->pci->device,
budget_ci->budget.dev->pci->subsystem_vendor,
budget_ci->budget.dev->pci->subsystem_device);
} else {
if (dvb_register_frontend
(&budget_ci->budget.dvb_adapter, budget_ci->budget.dvb_frontend)) {
printk("budget-ci: Frontend registration failed!\n");
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
budget_ci->budget.dvb_frontend = NULL;
}
}
}
static int budget_ci_attach(struct saa7146_dev *dev, struct saa7146_pci_extension_data *info)
{
struct budget_ci *budget_ci;
int err;
budget_ci = kzalloc(sizeof(struct budget_ci), GFP_KERNEL);
if (!budget_ci) {
err = -ENOMEM;
goto out1;
}
dprintk(2, "budget_ci: %p\n", budget_ci);
dev->ext_priv = budget_ci;
err = ttpci_budget_init(&budget_ci->budget, dev, info, THIS_MODULE,
adapter_nr);
if (err)
goto out2;
err = msp430_ir_init(budget_ci);
if (err)
goto out3;
ciintf_init(budget_ci);
budget_ci->budget.dvb_adapter.priv = budget_ci;
frontend_init(budget_ci);
ttpci_budget_init_hooks(&budget_ci->budget);
return 0;
out3:
ttpci_budget_deinit(&budget_ci->budget);
out2:
kfree(budget_ci);
out1:
return err;
}
static int budget_ci_detach(struct saa7146_dev *dev)
{
struct budget_ci *budget_ci = (struct budget_ci *) dev->ext_priv;
struct saa7146_dev *saa = budget_ci->budget.dev;
int err;
if (budget_ci->budget.ci_present)
ciintf_deinit(budget_ci);
msp430_ir_deinit(budget_ci);
if (budget_ci->budget.dvb_frontend) {
dvb_unregister_frontend(budget_ci->budget.dvb_frontend);
dvb_frontend_detach(budget_ci->budget.dvb_frontend);
}
err = ttpci_budget_deinit(&budget_ci->budget);
saa7146_setgpio(saa, 2, SAA7146_GPIO_INPUT);
kfree(budget_ci);
return err;
}
static int __init budget_ci_init(void)
{
return saa7146_register_extension(&budget_extension);
}
static void __exit budget_ci_exit(void)
{
saa7146_unregister_extension(&budget_extension);
}
