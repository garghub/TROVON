void exar7300_init(struct channel *sc)
{
exar7300_write(sc, SBE_2T3E3_LIU_REG_REG1, 0);
exar7300_write(sc, SBE_2T3E3_LIU_REG_REG2, 0);
exar7300_write(sc, SBE_2T3E3_LIU_REG_REG3, 0);
exar7300_write(sc, SBE_2T3E3_LIU_REG_REG4,
SBE_2T3E3_LIU_VAL_T3_MODE_SELECT |
SBE_2T3E3_LIU_VAL_LOOPBACK_OFF);
}
void exar7300_set_loopback(struct channel *sc, u32 mode)
{
u32 val;
switch (mode) {
case SBE_2T3E3_LIU_VAL_LOOPBACK_OFF:
case SBE_2T3E3_LIU_VAL_LOOPBACK_REMOTE:
case SBE_2T3E3_LIU_VAL_LOOPBACK_ANALOG:
case SBE_2T3E3_LIU_VAL_LOOPBACK_DIGITAL:
break;
default:
return;
}
val = exar7300_read(sc, SBE_2T3E3_LIU_REG_REG4);
val &= ~(SBE_2T3E3_LIU_VAL_LOCAL_LOOPBACK | SBE_2T3E3_LIU_VAL_REMOTE_LOOPBACK);
val |= mode;
exar7300_write(sc, SBE_2T3E3_LIU_REG_REG4, val);
#if 0
switch (mode) {
case SBE_2T3E3_LIU_VAL_LOOPBACK_OFF:
break;
case SBE_2T3E3_LIU_VAL_LOOPBACK_REMOTE:
exar7300_receive_equalization_onoff(sc, SBE_2T3E3_ON);
break;
case SBE_2T3E3_LIU_VAL_LOOPBACK_ANALOG:
exar7300_receive_equalization_onoff(sc, SBE_2T3E3_OFF);
break;
case SBE_2T3E3_LIU_VAL_LOOPBACK_DIGITAL:
exar7300_receive_equalization_onoff(sc, SBE_2T3E3_ON);
break;
}
#endif
}
void exar7300_set_frame_type(struct channel *sc, u32 type)
{
u32 val;
switch (type) {
case SBE_2T3E3_FRAME_TYPE_T3_CBIT:
case SBE_2T3E3_FRAME_TYPE_T3_M13:
case SBE_2T3E3_FRAME_TYPE_E3_G751:
case SBE_2T3E3_FRAME_TYPE_E3_G832:
break;
default:
return;
}
val = exar7300_read(sc, SBE_2T3E3_LIU_REG_REG4);
val &= ~(SBE_2T3E3_LIU_VAL_T3_MODE_SELECT |
SBE_2T3E3_LIU_VAL_E3_MODE_SELECT);
switch (type) {
case SBE_2T3E3_FRAME_TYPE_T3_CBIT:
case SBE_2T3E3_FRAME_TYPE_T3_M13:
val |= SBE_2T3E3_LIU_VAL_T3_MODE_SELECT;
break;
case SBE_2T3E3_FRAME_TYPE_E3_G751:
case SBE_2T3E3_FRAME_TYPE_E3_G832:
val |= SBE_2T3E3_LIU_VAL_E3_MODE_SELECT;
break;
default:
return;
}
exar7300_write(sc, SBE_2T3E3_LIU_REG_REG4, val);
}
void exar7300_transmit_all_ones_onoff(struct channel *sc, u32 mode)
{
if (sc->p.transmit_all_ones == mode)
return;
switch (mode) {
case SBE_2T3E3_ON:
exar7300_set_bit(sc, SBE_2T3E3_LIU_REG_REG1,
SBE_2T3E3_LIU_VAL_TRANSMIT_ALL_ONES);
break;
case SBE_2T3E3_OFF:
exar7300_clear_bit(sc, SBE_2T3E3_LIU_REG_REG1,
SBE_2T3E3_LIU_VAL_TRANSMIT_ALL_ONES);
break;
default:
return;
}
sc->p.transmit_all_ones = mode;
}
void exar7300_receive_equalization_onoff(struct channel *sc, u32 mode)
{
if (sc->p.receive_equalization == mode)
return;
switch (mode) {
case SBE_2T3E3_OFF:
exar7300_set_bit(sc, SBE_2T3E3_LIU_REG_REG2,
SBE_2T3E3_LIU_VAL_RECEIVE_EQUALIZATION_DISABLE);
break;
case SBE_2T3E3_ON:
exar7300_clear_bit(sc, SBE_2T3E3_LIU_REG_REG2,
SBE_2T3E3_LIU_VAL_RECEIVE_EQUALIZATION_DISABLE);
break;
default:
return;
}
sc->p.receive_equalization = mode;
}
void exar7300_line_build_out_onoff(struct channel *sc, u32 mode)
{
if (sc->p.line_build_out == mode)
return;
switch (mode) {
case SBE_2T3E3_OFF:
exar7300_set_bit(sc, SBE_2T3E3_LIU_REG_REG1,
SBE_2T3E3_LIU_VAL_TRANSMIT_LEVEL_SELECT);
exar7300_receive_equalization_onoff(sc, SBE_2T3E3_OFF);
break;
case SBE_2T3E3_ON:
exar7300_clear_bit(sc, SBE_2T3E3_LIU_REG_REG1,
SBE_2T3E3_LIU_VAL_TRANSMIT_LEVEL_SELECT);
exar7300_receive_equalization_onoff(sc, SBE_2T3E3_ON);
break;
default:
return;
}
sc->p.line_build_out = mode;
}
void exar7300_unipolar_onoff(struct channel *sc, u32 mode)
{
switch (mode) {
case SBE_2T3E3_OFF:
exar7300_clear_bit(sc, SBE_2T3E3_LIU_REG_REG3,
SBE_2T3E3_LIU_VAL_DECODER_DISABLE);
exar7300_clear_bit(sc, SBE_2T3E3_LIU_REG_REG1,
SBE_2T3E3_LIU_VAL_TRANSMIT_BINARY_DATA);
break;
case SBE_2T3E3_ON:
exar7300_set_bit(sc, SBE_2T3E3_LIU_REG_REG3,
SBE_2T3E3_LIU_VAL_DECODER_DISABLE);
exar7300_set_bit(sc, SBE_2T3E3_LIU_REG_REG1,
SBE_2T3E3_LIU_VAL_TRANSMIT_BINARY_DATA);
break;
}
}
