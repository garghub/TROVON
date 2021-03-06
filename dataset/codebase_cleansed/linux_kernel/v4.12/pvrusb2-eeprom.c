static u8 *pvr2_eeprom_fetch(struct pvr2_hdw *hdw)
{
struct i2c_msg msg[2];
u8 *eeprom;
u8 iadd[2];
u8 addr;
u16 eepromSize;
unsigned int offs;
int ret;
int mode16 = 0;
unsigned pcnt,tcnt;
eeprom = kmalloc(EEPROM_SIZE,GFP_KERNEL);
if (!eeprom) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Failed to allocate memory required to read eeprom");
return NULL;
}
trace_eeprom("Value for eeprom addr from controller was 0x%x",
hdw->eeprom_addr);
addr = hdw->eeprom_addr;
if (addr & 0x80) addr >>= 1;
mode16 = (addr & 1);
eepromSize = (mode16 ? 4096 : 256);
trace_eeprom("Examining %d byte eeprom at location 0x%x using %d bit addressing",
eepromSize, addr,
mode16 ? 16 : 8);
msg[0].addr = addr;
msg[0].flags = 0;
msg[0].len = mode16 ? 2 : 1;
msg[0].buf = iadd;
msg[1].addr = addr;
msg[1].flags = I2C_M_RD;
memset(eeprom,0,EEPROM_SIZE);
for (tcnt = 0; tcnt < EEPROM_SIZE; tcnt += pcnt) {
pcnt = 16;
if (pcnt + tcnt > EEPROM_SIZE) pcnt = EEPROM_SIZE-tcnt;
offs = tcnt + (eepromSize - EEPROM_SIZE);
if (mode16) {
iadd[0] = offs >> 8;
iadd[1] = offs;
} else {
iadd[0] = offs;
}
msg[1].len = pcnt;
msg[1].buf = eeprom+tcnt;
if ((ret = i2c_transfer(&hdw->i2c_adap,
msg,ARRAY_SIZE(msg))) != 2) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"eeprom fetch set offs err=%d",ret);
kfree(eeprom);
return NULL;
}
}
return eeprom;
}
int pvr2_eeprom_analyze(struct pvr2_hdw *hdw)
{
u8 *eeprom;
struct tveeprom tvdata;
memset(&tvdata,0,sizeof(tvdata));
eeprom = pvr2_eeprom_fetch(hdw);
if (!eeprom)
return -EINVAL;
tveeprom_hauppauge_analog(&tvdata, eeprom);
trace_eeprom("eeprom assumed v4l tveeprom module");
trace_eeprom("eeprom direct call results:");
trace_eeprom("has_radio=%d",tvdata.has_radio);
trace_eeprom("tuner_type=%d",tvdata.tuner_type);
trace_eeprom("tuner_formats=0x%x",tvdata.tuner_formats);
trace_eeprom("audio_processor=%d",tvdata.audio_processor);
trace_eeprom("model=%d",tvdata.model);
trace_eeprom("revision=%d",tvdata.revision);
trace_eeprom("serial_number=%d",tvdata.serial_number);
trace_eeprom("rev_str=%s",tvdata.rev_str);
hdw->tuner_type = tvdata.tuner_type;
hdw->tuner_updated = !0;
hdw->serial_number = tvdata.serial_number;
hdw->std_mask_eeprom = tvdata.tuner_formats;
kfree(eeprom);
return 0;
}
