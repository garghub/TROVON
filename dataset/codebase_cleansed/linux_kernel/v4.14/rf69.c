int rf69_set_mode(struct spi_device *spi, enum mode mode)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: mode");
#endif
switch (mode) {
case transmit: return WRITE_REG(REG_OPMODE, (READ_REG(REG_OPMODE) & ~MASK_OPMODE_MODE) | OPMODE_MODE_TRANSMIT);
case receive: return WRITE_REG(REG_OPMODE, (READ_REG(REG_OPMODE) & ~MASK_OPMODE_MODE) | OPMODE_MODE_RECEIVE);
case synthesizer: return WRITE_REG(REG_OPMODE, (READ_REG(REG_OPMODE) & ~MASK_OPMODE_MODE) | OPMODE_MODE_SYNTHESIZER);
case standby: return WRITE_REG(REG_OPMODE, (READ_REG(REG_OPMODE) & ~MASK_OPMODE_MODE) | OPMODE_MODE_STANDBY);
case mode_sleep: return WRITE_REG(REG_OPMODE, (READ_REG(REG_OPMODE) & ~MASK_OPMODE_MODE) | OPMODE_MODE_SLEEP);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_data_mode(struct spi_device *spi, enum dataMode dataMode)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: data mode");
#endif
switch (dataMode) {
case packet: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODE) | DATAMODUL_MODE_PACKET);
case continuous: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODE) | DATAMODUL_MODE_CONTINUOUS);
case continuousNoSync: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODE) | DATAMODUL_MODE_CONTINUOUS_NOSYNC);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_modulation(struct spi_device *spi, enum modulation modulation)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: modulation");
#endif
switch (modulation) {
case OOK: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_TYPE) | DATAMODUL_MODULATION_TYPE_OOK);
case FSK: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_TYPE) | DATAMODUL_MODULATION_TYPE_FSK);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
enum modulation rf69_get_modulation(struct spi_device *spi)
{
u8 currentValue;
#ifdef DEBUG
dev_dbg(&spi->dev, "get: mode");
#endif
currentValue = READ_REG(REG_DATAMODUL);
switch (currentValue & MASK_DATAMODUL_MODULATION_TYPE >> 3) {
case DATAMODUL_MODULATION_TYPE_OOK: return OOK;
case DATAMODUL_MODULATION_TYPE_FSK: return FSK;
default: return undefined;
}
}
int rf69_set_modulation_shaping(struct spi_device *spi, enum modShaping modShaping)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: mod shaping");
#endif
if (rf69_get_modulation(spi) == FSK) {
switch (modShaping) {
case shapingOff: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_SHAPE) | DATAMODUL_MODULATION_SHAPE_NONE);
case shaping1_0: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_SHAPE) | DATAMODUL_MODULATION_SHAPE_1_0);
case shaping0_5: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_SHAPE) | DATAMODUL_MODULATION_SHAPE_0_3);
case shaping0_3: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_SHAPE) | DATAMODUL_MODULATION_SHAPE_0_5);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
} else {
switch (modShaping) {
case shapingOff: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_SHAPE) | DATAMODUL_MODULATION_SHAPE_NONE);
case shapingBR: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_SHAPE) | DATAMODUL_MODULATION_SHAPE_BR);
case shaping2BR: return WRITE_REG(REG_DATAMODUL, (READ_REG(REG_DATAMODUL) & ~MASK_DATAMODUL_MODULATION_SHAPE) | DATAMODUL_MODULATION_SHAPE_2BR);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
}
int rf69_set_bit_rate(struct spi_device *spi, u16 bitRate)
{
int retval;
u32 bitRate_min;
u32 bitRate_reg;
u8 msb;
u8 lsb;
#ifdef DEBUG
dev_dbg(&spi->dev, "set: bit rate");
#endif
bitRate_min = F_OSC / 8388608;
if (bitRate < bitRate_min) {
dev_dbg(&spi->dev, "setBitRate: illegal input param");
return -EINVAL;
}
bitRate_reg = (F_OSC / bitRate);
msb = (bitRate_reg&0xff00) >> 8;
lsb = (bitRate_reg&0xff);
retval = WRITE_REG(REG_BITRATE_MSB, msb);
if (retval) return retval;
retval = WRITE_REG(REG_BITRATE_LSB, lsb);
if (retval) return retval;
return 0;
}
int rf69_set_deviation(struct spi_device *spi, u32 deviation)
{
int retval;
u64 f_reg;
u64 f_step;
u8 msb;
u8 lsb;
u64 factor = 1000000;
#ifdef DEBUG
dev_dbg(&spi->dev, "set: deviation");
#endif
if (deviation < 600 || deviation > 500000) {
dev_dbg(&spi->dev, "set_deviation: illegal input param");
return -EINVAL;
}
f_step = F_OSC * factor;
do_div(f_step, 524288);
f_reg = deviation * factor;
do_div(f_reg , f_step);
msb = (f_reg&0xff00) >> 8;
lsb = (f_reg&0xff);
if (msb & ~FDEVMASB_MASK) {
dev_dbg(&spi->dev, "set_deviation: err in calc of msb");
return -EINVAL;
}
retval = WRITE_REG(REG_FDEV_MSB, msb);
if (retval) return retval;
retval = WRITE_REG(REG_FDEV_LSB, lsb);
if (retval) return retval;
return 0;
}
int rf69_set_frequency(struct spi_device *spi, u32 frequency)
{
int retval;
u32 f_max;
u64 f_reg;
u64 f_step;
u8 msb;
u8 mid;
u8 lsb;
u64 factor = 1000000;
#ifdef DEBUG
dev_dbg(&spi->dev, "set: frequency");
#endif
f_step = F_OSC * factor;
do_div(f_step, 524288);
f_max = div_u64(f_step * 8388608, factor);
if (frequency > f_max) {
dev_dbg(&spi->dev, "setFrequency: illegal input param");
return -EINVAL;
}
f_reg = frequency * factor;
do_div(f_reg , f_step);
msb = (f_reg&0xff0000) >> 16;
mid = (f_reg&0xff00) >> 8;
lsb = (f_reg&0xff);
retval = WRITE_REG(REG_FRF_MSB, msb);
if (retval) return retval;
retval = WRITE_REG(REG_FRF_MID, mid);
if (retval) return retval;
retval = WRITE_REG(REG_FRF_LSB, lsb);
if (retval) return retval;
return 0;
}
int rf69_set_amplifier_0(struct spi_device *spi, enum optionOnOff optionOnOff)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: amp #0");
#endif
switch(optionOnOff) {
case optionOn: return WRITE_REG(REG_PALEVEL, (READ_REG(REG_PALEVEL) | MASK_PALEVEL_PA0) );
case optionOff: return WRITE_REG(REG_PALEVEL, (READ_REG(REG_PALEVEL) & ~MASK_PALEVEL_PA0) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_amplifier_1(struct spi_device *spi, enum optionOnOff optionOnOff)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: amp #1");
#endif
switch(optionOnOff) {
case optionOn: return WRITE_REG(REG_PALEVEL, (READ_REG(REG_PALEVEL) | MASK_PALEVEL_PA1) );
case optionOff: return WRITE_REG(REG_PALEVEL, (READ_REG(REG_PALEVEL) & ~MASK_PALEVEL_PA1) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_amplifier_2(struct spi_device *spi, enum optionOnOff optionOnOff)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: amp #2");
#endif
switch(optionOnOff) {
case optionOn: return WRITE_REG(REG_PALEVEL, (READ_REG(REG_PALEVEL) | MASK_PALEVEL_PA2) );
case optionOff: return WRITE_REG(REG_PALEVEL, (READ_REG(REG_PALEVEL) & ~MASK_PALEVEL_PA2) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_output_power_level(struct spi_device *spi, u8 powerLevel)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: power level");
#endif
powerLevel +=18;
if (powerLevel > 0x1f) {
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
return WRITE_REG(REG_PALEVEL, (READ_REG(REG_PALEVEL) & ~MASK_PALEVEL_OUTPUT_POWER) | powerLevel);
}
int rf69_set_pa_ramp(struct spi_device *spi, enum paRamp paRamp)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: pa ramp");
#endif
switch(paRamp) {
case ramp3400: return WRITE_REG(REG_PARAMP, PARAMP_3400);
case ramp2000: return WRITE_REG(REG_PARAMP, PARAMP_2000);
case ramp1000: return WRITE_REG(REG_PARAMP, PARAMP_1000);
case ramp500: return WRITE_REG(REG_PARAMP, PARAMP_500);
case ramp250: return WRITE_REG(REG_PARAMP, PARAMP_250);
case ramp125: return WRITE_REG(REG_PARAMP, PARAMP_125);
case ramp100: return WRITE_REG(REG_PARAMP, PARAMP_100);
case ramp62: return WRITE_REG(REG_PARAMP, PARAMP_62);
case ramp50: return WRITE_REG(REG_PARAMP, PARAMP_50);
case ramp40: return WRITE_REG(REG_PARAMP, PARAMP_40);
case ramp31: return WRITE_REG(REG_PARAMP, PARAMP_31);
case ramp25: return WRITE_REG(REG_PARAMP, PARAMP_25);
case ramp20: return WRITE_REG(REG_PARAMP, PARAMP_20);
case ramp15: return WRITE_REG(REG_PARAMP, PARAMP_15);
case ramp12: return WRITE_REG(REG_PARAMP, PARAMP_12);
case ramp10: return WRITE_REG(REG_PARAMP, PARAMP_10);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_antenna_impedance(struct spi_device *spi, enum antennaImpedance antennaImpedance)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: antenna impedance");
#endif
switch(antennaImpedance) {
case fiftyOhm: return WRITE_REG(REG_LNA, (READ_REG(REG_LNA) & ~MASK_LNA_ZIN) );
case twohundretOhm: return WRITE_REG(REG_LNA, (READ_REG(REG_LNA) | MASK_LNA_ZIN) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_lna_gain(struct spi_device *spi, enum lnaGain lnaGain)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: lna gain");
#endif
switch(lnaGain) {
case automatic: return WRITE_REG(REG_LNA, ( (READ_REG(REG_LNA) & ~MASK_LNA_GAIN) & LNA_GAIN_AUTO) );
case max: return WRITE_REG(REG_LNA, ( (READ_REG(REG_LNA) & ~MASK_LNA_GAIN) & LNA_GAIN_MAX) );
case maxMinus6: return WRITE_REG(REG_LNA, ( (READ_REG(REG_LNA) & ~MASK_LNA_GAIN) & LNA_GAIN_MAX_MINUS_6) );
case maxMinus12: return WRITE_REG(REG_LNA, ( (READ_REG(REG_LNA) & ~MASK_LNA_GAIN) & LNA_GAIN_MAX_MINUS_12) );
case maxMinus24: return WRITE_REG(REG_LNA, ( (READ_REG(REG_LNA) & ~MASK_LNA_GAIN) & LNA_GAIN_MAX_MINUS_24) );
case maxMinus36: return WRITE_REG(REG_LNA, ( (READ_REG(REG_LNA) & ~MASK_LNA_GAIN) & LNA_GAIN_MAX_MINUS_36) );
case maxMinus48: return WRITE_REG(REG_LNA, ( (READ_REG(REG_LNA) & ~MASK_LNA_GAIN) & LNA_GAIN_MAX_MINUS_48) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
enum lnaGain rf69_get_lna_gain(struct spi_device *spi)
{
u8 currentValue;
#ifdef DEBUG
dev_dbg(&spi->dev, "get: lna gain");
#endif
currentValue = READ_REG(REG_LNA);
switch (currentValue & MASK_LNA_CURRENT_GAIN >> 3) {
case LNA_GAIN_AUTO: return automatic;
case LNA_GAIN_MAX: return max;
case LNA_GAIN_MAX_MINUS_6: return maxMinus6;
case LNA_GAIN_MAX_MINUS_12: return maxMinus12;
case LNA_GAIN_MAX_MINUS_24: return maxMinus24;
case LNA_GAIN_MAX_MINUS_36: return maxMinus36;
case LNA_GAIN_MAX_MINUS_48: return maxMinus48;
default: return undefined;
}
}
int rf69_set_dc_cut_off_frequency_intern(struct spi_device *spi ,u8 reg, enum dccPercent dccPercent)
{
switch (dccPercent) {
case dcc16Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_16_PERCENT) );
case dcc8Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_8_PERCENT) );
case dcc4Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_4_PERCENT) );
case dcc2Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_2_PERCENT) );
case dcc1Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_1_PERCENT) );
case dcc0_5Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_0_5_PERCENT) );
case dcc0_25Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_0_25_PERCENT) );
case dcc0_125Percent: return WRITE_REG(reg, ( (READ_REG(reg) & ~MASK_BW_DCC_FREQ) | BW_DCC_0_125_PERCENT) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_dc_cut_off_frequency(struct spi_device *spi, enum dccPercent dccPercent)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: cut off freq");
#endif
return rf69_set_dc_cut_off_frequency_intern(spi, REG_RXBW, dccPercent);
}
int rf69_set_dc_cut_off_frequency_during_afc(struct spi_device *spi, enum dccPercent dccPercent)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: cut off freq during afc");
#endif
return rf69_set_dc_cut_off_frequency_intern(spi, REG_AFCBW, dccPercent);
}
static int rf69_set_bandwidth_intern(struct spi_device *spi, u8 reg,
enum mantisse mantisse, u8 exponent)
{
u8 newValue;
if (exponent > 7) {
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
if ((mantisse != mantisse16) &&
(mantisse != mantisse20) &&
(mantisse != mantisse24)) {
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
newValue = READ_REG(reg);
newValue = newValue & MASK_BW_DCC_FREQ;
switch(mantisse) {
case mantisse16: newValue = newValue | BW_MANT_16; break;
case mantisse20: newValue = newValue | BW_MANT_20; break;
case mantisse24: newValue = newValue | BW_MANT_24; break;
}
newValue = newValue | exponent;
return WRITE_REG(reg, newValue);
}
int rf69_set_bandwidth(struct spi_device *spi, enum mantisse mantisse, u8 exponent)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: band width");
#endif
return rf69_set_bandwidth_intern(spi, REG_RXBW, mantisse, exponent);
}
int rf69_set_bandwidth_during_afc(struct spi_device *spi, enum mantisse mantisse, u8 exponent)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: band width during afc");
#endif
return rf69_set_bandwidth_intern(spi, REG_AFCBW, mantisse, exponent);
}
int rf69_set_ook_threshold_type(struct spi_device *spi, enum thresholdType thresholdType)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: threshold type");
#endif
switch (thresholdType) {
case fixed: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESTYPE) | OOKPEAK_THRESHTYPE_FIXED) );
case peak: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESTYPE) | OOKPEAK_THRESHTYPE_PEAK) );
case average: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESTYPE) | OOKPEAK_THRESHTYPE_AVERAGE) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_ook_threshold_step(struct spi_device *spi, enum thresholdStep thresholdStep)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: threshold step");
#endif
switch (thresholdStep) {
case step_0_5db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_0_5_DB) );
case step_1_0db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_1_0_DB) );
case step_1_5db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_1_5_DB) );
case step_2_0db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_2_0_DB) );
case step_3_0db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_3_0_DB) );
case step_4_0db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_4_0_DB) );
case step_5_0db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_5_0_DB) );
case step_6_0db: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESSTEP) | OOKPEAK_THRESHSTEP_6_0_DB) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_ook_threshold_dec(struct spi_device *spi, enum thresholdDecrement thresholdDecrement)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: threshold decrement");
#endif
switch (thresholdDecrement) {
case dec_every8th: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_EVERY_8TH) );
case dec_every4th: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_EVERY_4TH) );
case dec_every2nd: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_EVERY_2ND) );
case dec_once: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_ONCE) );
case dec_twice: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_TWICE) );
case dec_4times: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_4_TIMES) );
case dec_8times: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_8_TIMES) );
case dec_16times: return WRITE_REG(REG_OOKPEAK, ( (READ_REG(REG_OOKPEAK) & ~MASK_OOKPEAK_THRESDEC) | OOKPEAK_THRESHDEC_16_TIMES) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_dio_mapping(struct spi_device *spi, u8 DIONumber, u8 value)
{
u8 mask;
u8 shift;
u8 regaddr;
u8 regValue;
#ifdef DEBUG
dev_dbg(&spi->dev, "set: DIO mapping");
#endif
switch (DIONumber) {
case 0: mask=MASK_DIO0; shift=SHIFT_DIO0; regaddr=REG_DIOMAPPING1; break;
case 1: mask=MASK_DIO1; shift=SHIFT_DIO1; regaddr=REG_DIOMAPPING1; break;
case 2: mask=MASK_DIO2; shift=SHIFT_DIO2; regaddr=REG_DIOMAPPING1; break;
case 3: mask=MASK_DIO3; shift=SHIFT_DIO3; regaddr=REG_DIOMAPPING1; break;
case 4: mask=MASK_DIO4; shift=SHIFT_DIO4; regaddr=REG_DIOMAPPING2; break;
case 5: mask=MASK_DIO5; shift=SHIFT_DIO5; regaddr=REG_DIOMAPPING2; break;
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
regValue=READ_REG(regaddr);
regValue = regValue & ~mask;
regValue = regValue | value << shift;
return WRITE_REG(regaddr,regValue);
}
bool rf69_get_flag(struct spi_device *spi, enum flag flag)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "get: flag");
#endif
switch(flag) {
case modeSwitchCompleted: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_MODE_READY);
case readyToReceive: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_RX_READY);
case readyToSend: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_TX_READY);
case pllLocked: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_PLL_LOCK);
case rssiExceededThreshold: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_RSSI);
case timeout: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_TIMEOUT);
case automode: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_AUTOMODE);
case syncAddressMatch: return (READ_REG(REG_IRQFLAGS1) & MASK_IRQFLAGS1_SYNC_ADDRESS_MATCH);
case fifoFull: return (READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_FIFO_FULL);
case fifoEmpty: return !(READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_FIFO_NOT_EMPTY);
case fifoLevelBelowThreshold: return (READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_FIFO_LEVEL);
case fifoOverrun: return (READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_FIFO_OVERRUN);
case packetSent: return (READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_PACKET_SENT);
case payloadReady: return (READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_PAYLOAD_READY);
case crcOk: return (READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_CRC_OK);
case batteryLow: return (READ_REG(REG_IRQFLAGS2) & MASK_IRQFLAGS2_LOW_BAT);
default: return false;
}
}
int rf69_reset_flag(struct spi_device *spi, enum flag flag)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "reset: flag");
#endif
switch(flag) {
case rssiExceededThreshold: return WRITE_REG(REG_IRQFLAGS1, MASK_IRQFLAGS1_RSSI);
case syncAddressMatch: return WRITE_REG(REG_IRQFLAGS1, MASK_IRQFLAGS1_SYNC_ADDRESS_MATCH);
case fifoOverrun: return WRITE_REG(REG_IRQFLAGS2, MASK_IRQFLAGS2_FIFO_OVERRUN);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_rssi_threshold(struct spi_device *spi, u8 threshold)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: rssi threshold");
#endif
return WRITE_REG(REG_RSSITHRESH, threshold);
}
int rf69_set_rx_start_timeout(struct spi_device *spi, u8 timeout)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: start timeout");
#endif
return WRITE_REG(REG_RXTIMEOUT1, timeout);
}
int rf69_set_rssi_timeout(struct spi_device *spi, u8 timeout)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: rssi timeout");
#endif
return WRITE_REG(REG_RXTIMEOUT2, timeout);
}
int rf69_set_preamble_length(struct spi_device *spi, u16 preambleLength)
{
int retval;
u8 msb, lsb;
#ifdef DEBUG
dev_dbg(&spi->dev, "set: preamble length");
#endif
msb = (preambleLength&0xff00) >> 8;
lsb = (preambleLength&0xff);
retval = WRITE_REG(REG_PREAMBLE_MSB, msb);
if (retval) return retval;
retval = WRITE_REG(REG_PREAMBLE_LSB, lsb);
return retval;
}
int rf69_set_sync_enable(struct spi_device *spi, enum optionOnOff optionOnOff)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: sync enable");
#endif
switch(optionOnOff) {
case optionOn: return WRITE_REG(REG_SYNC_CONFIG, (READ_REG(REG_SYNC_CONFIG) | MASK_SYNC_CONFIG_SYNC_ON) );
case optionOff: return WRITE_REG(REG_SYNC_CONFIG, (READ_REG(REG_SYNC_CONFIG) & ~MASK_SYNC_CONFIG_SYNC_ON) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_fifo_fill_condition(struct spi_device *spi, enum fifoFillCondition fifoFillCondition)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: fifo fill condition");
#endif
switch(fifoFillCondition) {
case always: return WRITE_REG(REG_SYNC_CONFIG, (READ_REG(REG_SYNC_CONFIG) | MASK_SYNC_CONFIG_FIFO_FILL_CONDITION) );
case afterSyncInterrupt: return WRITE_REG(REG_SYNC_CONFIG, (READ_REG(REG_SYNC_CONFIG) & ~MASK_SYNC_CONFIG_FIFO_FILL_CONDITION) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_sync_size(struct spi_device *spi, u8 syncSize)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: sync size");
#endif
if (syncSize > 0x07) {
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
return WRITE_REG(REG_SYNC_CONFIG, (READ_REG(REG_SYNC_CONFIG) & ~MASK_SYNC_CONFIG_SYNC_SIZE) | (syncSize << 3) );
}
int rf69_set_sync_tolerance(struct spi_device *spi, u8 syncTolerance)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: sync tolerance");
#endif
if (syncTolerance > 0x07) {
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
return WRITE_REG(REG_SYNC_CONFIG, (READ_REG(REG_SYNC_CONFIG) & ~MASK_SYNC_CONFIG_SYNC_SIZE) | syncTolerance);
}
int rf69_set_sync_values(struct spi_device *spi, u8 syncValues[8])
{
int retval = 0;
#ifdef DEBUG
dev_dbg(&spi->dev, "set: sync values");
#endif
retval += WRITE_REG(REG_SYNCVALUE1, syncValues[0]);
retval += WRITE_REG(REG_SYNCVALUE2, syncValues[1]);
retval += WRITE_REG(REG_SYNCVALUE3, syncValues[2]);
retval += WRITE_REG(REG_SYNCVALUE4, syncValues[3]);
retval += WRITE_REG(REG_SYNCVALUE5, syncValues[4]);
retval += WRITE_REG(REG_SYNCVALUE6, syncValues[5]);
retval += WRITE_REG(REG_SYNCVALUE7, syncValues[6]);
retval += WRITE_REG(REG_SYNCVALUE8, syncValues[7]);
return retval;
}
int rf69_set_packet_format(struct spi_device *spi, enum packetFormat packetFormat)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: packet format");
#endif
switch(packetFormat) {
case packetLengthVar: return WRITE_REG(REG_PACKETCONFIG1, (READ_REG(REG_PACKETCONFIG1) | MASK_PACKETCONFIG1_PAKET_FORMAT_VARIABLE) );
case packetLengthFix: return WRITE_REG(REG_PACKETCONFIG1, (READ_REG(REG_PACKETCONFIG1) & ~MASK_PACKETCONFIG1_PAKET_FORMAT_VARIABLE) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_crc_enable(struct spi_device *spi, enum optionOnOff optionOnOff)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: crc enable");
#endif
switch(optionOnOff) {
case optionOn: return WRITE_REG(REG_PACKETCONFIG1, (READ_REG(REG_PACKETCONFIG1) | MASK_PACKETCONFIG1_CRC_ON) );
case optionOff: return WRITE_REG(REG_PACKETCONFIG1, (READ_REG(REG_PACKETCONFIG1) & ~MASK_PACKETCONFIG1_CRC_ON) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_adressFiltering(struct spi_device *spi, enum addressFiltering addressFiltering)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: address filtering");
#endif
switch (addressFiltering) {
case filteringOff: return WRITE_REG(REG_PACKETCONFIG1, ( (READ_REG(REG_PACKETCONFIG1) & ~MASK_PACKETCONFIG1_ADDRESSFILTERING) | PACKETCONFIG1_ADDRESSFILTERING_OFF) );
case nodeAddress: return WRITE_REG(REG_PACKETCONFIG1, ( (READ_REG(REG_PACKETCONFIG1) & ~MASK_PACKETCONFIG1_ADDRESSFILTERING) | PACKETCONFIG1_ADDRESSFILTERING_NODE) );
case nodeOrBroadcastAddress: return WRITE_REG(REG_PACKETCONFIG1, ( (READ_REG(REG_PACKETCONFIG1) & ~MASK_PACKETCONFIG1_ADDRESSFILTERING) | PACKETCONFIG1_ADDRESSFILTERING_NODEBROADCAST) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_payload_length(struct spi_device *spi, u8 payloadLength)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: payload length");
#endif
return WRITE_REG(REG_PAYLOAD_LENGTH, payloadLength);
}
u8 rf69_get_payload_length(struct spi_device *spi)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "get: payload length");
#endif
return (u8) READ_REG(REG_PAYLOAD_LENGTH);
}
int rf69_set_node_address(struct spi_device *spi, u8 nodeAddress)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: node address");
#endif
return WRITE_REG(REG_NODEADRS, nodeAddress);
}
int rf69_set_broadcast_address(struct spi_device *spi, u8 broadcastAddress)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: broadcast address");
#endif
return WRITE_REG(REG_BROADCASTADRS, broadcastAddress);
}
int rf69_set_tx_start_condition(struct spi_device *spi, enum txStartCondition txStartCondition)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: start condition");
#endif
switch(txStartCondition) {
case fifoLevel: return WRITE_REG(REG_FIFO_THRESH, (READ_REG(REG_FIFO_THRESH) & ~MASK_FIFO_THRESH_TXSTART) );
case fifoNotEmpty: return WRITE_REG(REG_FIFO_THRESH, (READ_REG(REG_FIFO_THRESH) | MASK_FIFO_THRESH_TXSTART) );
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_set_fifo_threshold(struct spi_device *spi, u8 threshold)
{
int retval;
#ifdef DEBUG
dev_dbg(&spi->dev, "set: fifo threshold");
#endif
if (threshold & 0x80) {
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
retval = WRITE_REG(REG_FIFO_THRESH, (READ_REG(REG_FIFO_THRESH) & ~MASK_FIFO_THRESH_VALUE) | threshold);
if (retval)
return retval;
return rf69_read_fifo (spi, (u8*) &retval, 1);
}
int rf69_set_dagc(struct spi_device *spi, enum dagc dagc)
{
#ifdef DEBUG
dev_dbg(&spi->dev, "set: dagc");
#endif
switch(dagc) {
case normalMode: return WRITE_REG(REG_TESTDAGC, DAGC_NORMAL);
case improve: return WRITE_REG(REG_TESTDAGC, DAGC_IMPROVED_LOWBETA0);
case improve4LowModulationIndex: return WRITE_REG(REG_TESTDAGC, DAGC_IMPROVED_LOWBETA1);
default:
dev_dbg(&spi->dev, "set: illegal input param");
return -EINVAL;
}
}
int rf69_read_fifo (struct spi_device *spi, u8 *buffer, unsigned int size)
{
#ifdef DEBUG_FIFO_ACCESS
int i;
#endif
struct spi_transfer transfer;
u8 local_buffer[FIFO_SIZE + 1];
int retval;
if (size > FIFO_SIZE) {
#ifdef DEBUG
dev_dbg(&spi->dev, "read fifo: passed in buffer bigger then internal buffer \n");
#endif
return -EMSGSIZE;
}
local_buffer[0] = REG_FIFO;
memset(&transfer, 0, sizeof(transfer));
transfer.tx_buf = local_buffer;
transfer.rx_buf = local_buffer;
transfer.len = size+1;
retval = spi_sync_transfer(spi, &transfer, 1);
#ifdef DEBUG_FIFO_ACCESS
for (i=0; i<size; i++)
dev_dbg(&spi->dev, "%d - 0x%x\n", i, local_buffer[i+1]);
#endif
memcpy(buffer, &local_buffer[1], size);
return retval;
}
int rf69_write_fifo(struct spi_device *spi, u8 *buffer, unsigned int size)
{
#ifdef DEBUG_FIFO_ACCESS
int i;
#endif
char spi_address = REG_FIFO | WRITE_BIT;
u8 local_buffer[FIFO_SIZE + 1];
if (size > FIFO_SIZE) {
#ifdef DEBUG
dev_dbg(&spi->dev, "read fifo: passed in buffer bigger then internal buffer \n");
#endif
return -EMSGSIZE;
}
local_buffer[0] = spi_address;
memcpy(&local_buffer[1], buffer, size);
#ifdef DEBUG_FIFO_ACCESS
for (i=0; i<size; i++)
dev_dbg(&spi->dev, "0x%x\n",buffer[i]);
#endif
return spi_write (spi, local_buffer, size + 1);
}
u8 rf69_read_reg(struct spi_device *spi, u8 addr)
{
int retval;
retval = spi_w8r8(spi, addr);
#ifdef DEBUG_VALUES
if (retval < 0)
dev_dbg(&spi->dev, "read 0x%x FAILED\n",
addr);
else
dev_dbg(&spi->dev, "read 0x%x from reg 0x%x\n",
retval,
addr);
#endif
return retval;
}
int rf69_write_reg(struct spi_device *spi, u8 addr, u8 value)
{
int retval;
char buffer[2];
buffer[0] = addr | WRITE_BIT;
buffer[1] = value;
retval = spi_write(spi, &buffer, 2);
#ifdef DEBUG_VALUES
if (retval < 0)
dev_dbg(&spi->dev, "write 0x%x to 0x%x FAILED\n",
value,
addr);
else
dev_dbg(&spi->dev, "wrote 0x%x to reg 0x%x\n",
value,
addr);
#endif
return retval;
}
