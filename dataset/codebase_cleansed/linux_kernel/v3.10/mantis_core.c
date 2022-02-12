static int read_eeprom_byte(struct mantis_pci *mantis, u8 *data, u8 length)
{
int err;
struct i2c_msg msg[] = {
{
.addr = 0x50,
.flags = 0,
.buf = data,
.len = 1
}, {
.addr = 0x50,
.flags = I2C_M_RD,
.buf = data,
.len = length
},
};
err = i2c_transfer(&mantis->adapter, msg, 2);
if (err < 0) {
dprintk(verbose, MANTIS_ERROR, 1,
"ERROR: i2c read: < err=%i d0=0x%02x d1=0x%02x >",
err, data[0], data[1]);
return err;
}
return 0;
}
static int write_eeprom_byte(struct mantis_pci *mantis, u8 *data, u8 length)
{
int err;
struct i2c_msg msg = {
.addr = 0x50,
.flags = 0,
.buf = data,
.len = length
};
err = i2c_transfer(&mantis->adapter, &msg, 1);
if (err < 0) {
dprintk(verbose, MANTIS_ERROR, 1,
"ERROR: i2c write: < err=%i length=0x%02x d0=0x%02x, d1=0x%02x >",
err, length, data[0], data[1]);
return err;
}
return 0;
}
static int get_mac_address(struct mantis_pci *mantis)
{
int err;
mantis->mac_address[0] = 0x08;
err = read_eeprom_byte(mantis, &mantis->mac_address[0], 6);
if (err < 0) {
dprintk(verbose, MANTIS_ERROR, 1, "Mantis EEPROM read error");
return err;
}
dprintk(verbose, MANTIS_ERROR, 0,
" MAC Address=[%pM]\n", mantis->mac_address);
return 0;
}
static void mantis_load_config(struct mantis_pci *mantis)
{
switch (mantis->subsystem_device) {
case MANTIS_VP_1033_DVB_S:
mantis->hwconfig = &vp1033_mantis_config;
break;
case MANTIS_VP_1034_DVB_S:
mantis->hwconfig = &vp1034_mantis_config;
break;
case MANTIS_VP_1041_DVB_S2:
case TECHNISAT_SKYSTAR_HD2:
mantis->hwconfig = &vp1041_mantis_config;
break;
case MANTIS_VP_2033_DVB_C:
mantis->hwconfig = &vp2033_mantis_config;
break;
case MANTIS_VP_2040_DVB_C:
case CINERGY_C:
case TECHNISAT_CABLESTAR_HD2:
mantis->hwconfig = &vp2040_mantis_config;
break;
case MANTIS_VP_3030_DVB_T:
mantis->hwconfig = &vp3030_mantis_config;
break;
default:
mantis->hwconfig = &unknown_device;
break;
}
}
int mantis_core_init(struct mantis_pci *mantis)
{
int err = 0;
mantis_load_config(mantis);
dprintk(verbose, MANTIS_ERROR, 0, "found a %s PCI %s device on (%02x:%02x.%x),\n",
mantis->hwconfig->model_name, mantis->hwconfig->dev_type,
mantis->pdev->bus->number, PCI_SLOT(mantis->pdev->devfn), PCI_FUNC(mantis->pdev->devfn));
dprintk(verbose, MANTIS_ERROR, 0, " Mantis Rev %d [%04x:%04x], ",
mantis->revision,
mantis->subsystem_vendor, mantis->subsystem_device);
dprintk(verbose, MANTIS_ERROR, 0,
"irq: %d, latency: %d\n memory: 0x%lx, mmio: 0x%p\n",
mantis->pdev->irq, mantis->latency,
mantis->mantis_addr, mantis->mantis_mmio);
err = mantis_i2c_init(mantis);
if (err < 0) {
dprintk(verbose, MANTIS_ERROR, 1, "Mantis I2C init failed");
return err;
}
err = get_mac_address(mantis);
if (err < 0) {
dprintk(verbose, MANTIS_ERROR, 1, "get MAC address failed");
return err;
}
err = mantis_dma_init(mantis);
if (err < 0) {
dprintk(verbose, MANTIS_ERROR, 1, "Mantis DMA init failed");
return err;
}
err = mantis_dvb_init(mantis);
if (err < 0) {
dprintk(verbose, MANTIS_DEBUG, 1, "Mantis DVB init failed");
return err;
}
err = mantis_uart_init(mantis);
if (err < 0) {
dprintk(verbose, MANTIS_DEBUG, 1, "Mantis UART init failed");
return err;
}
return 0;
}
int mantis_core_exit(struct mantis_pci *mantis)
{
mantis_dma_stop(mantis);
dprintk(verbose, MANTIS_ERROR, 1, "DMA engine stopping");
mantis_uart_exit(mantis);
dprintk(verbose, MANTIS_ERROR, 1, "UART exit failed");
if (mantis_dma_exit(mantis) < 0)
dprintk(verbose, MANTIS_ERROR, 1, "DMA exit failed");
if (mantis_dvb_exit(mantis) < 0)
dprintk(verbose, MANTIS_ERROR, 1, "DVB exit failed");
if (mantis_i2c_exit(mantis) < 0)
dprintk(verbose, MANTIS_ERROR, 1, "I2C adapter delete.. failed");
return 0;
}
void gpio_set_bits(struct mantis_pci *mantis, u32 bitpos, u8 value)
{
u32 cur;
cur = mmread(MANTIS_GPIF_ADDR);
if (value)
mantis->gpio_status = cur | (1 << bitpos);
else
mantis->gpio_status = cur & (~(1 << bitpos));
mmwrite(mantis->gpio_status, MANTIS_GPIF_ADDR);
mmwrite(0x00, MANTIS_GPIF_DOUT);
udelay(100);
}
void mantis_set_direction(struct mantis_pci *mantis, int direction)
{
u32 reg;
reg = mmread(0x28);
dprintk(verbose, MANTIS_DEBUG, 1, "TS direction setup");
if (direction == 0x01) {
reg |= 0x04;
mmwrite(reg, 0x28);
reg &= 0xff - 0x04;
mmwrite(reg, 0x28);
} else {
reg &= 0xff - 0x04;
mmwrite(reg, 0x28);
reg |= 0x04;
mmwrite(reg, 0x28);
}
}
