static void up_clk(struct _adapter *padapter, u16 *x)
{
*x = *x | _EESK;
r8712_write8(padapter, EE_9346CR, (u8)*x);
udelay(CLOCK_RATE);
}
static void down_clk(struct _adapter *padapter, u16 *x)
{
*x = *x & ~_EESK;
r8712_write8(padapter, EE_9346CR, (u8)*x);
udelay(CLOCK_RATE);
}
static void shift_out_bits(struct _adapter *padapter, u16 data, u16 count)
{
u16 x, mask;
if (padapter->bSurpriseRemoved)
goto out;
mask = 0x01 << (count - 1);
x = r8712_read8(padapter, EE_9346CR);
x &= ~(_EEDO | _EEDI);
do {
x &= ~_EEDI;
if (data & mask)
x |= _EEDI;
if (padapter->bSurpriseRemoved)
goto out;
r8712_write8(padapter, EE_9346CR, (u8)x);
udelay(CLOCK_RATE);
up_clk(padapter, &x);
down_clk(padapter, &x);
mask >>= 1;
} while (mask);
if (padapter->bSurpriseRemoved)
goto out;
x &= ~_EEDI;
r8712_write8(padapter, EE_9346CR, (u8)x);
out:;
}
static u16 shift_in_bits(struct _adapter *padapter)
{
u16 x, d = 0, i;
if (padapter->bSurpriseRemoved)
goto out;
x = r8712_read8(padapter, EE_9346CR);
x &= ~(_EEDO | _EEDI);
d = 0;
for (i = 0; i < 16; i++) {
d <<= 1;
up_clk(padapter, &x);
if (padapter->bSurpriseRemoved)
goto out;
x = r8712_read8(padapter, EE_9346CR);
x &= ~(_EEDI);
if (x & _EEDO)
d |= 1;
down_clk(padapter, &x);
}
out:
return d;
}
static void standby(struct _adapter *padapter)
{
u8 x;
x = r8712_read8(padapter, EE_9346CR);
x &= ~(_EECS | _EESK);
r8712_write8(padapter, EE_9346CR, x);
udelay(CLOCK_RATE);
x |= _EECS;
r8712_write8(padapter, EE_9346CR, x);
udelay(CLOCK_RATE);
}
static u16 wait_eeprom_cmd_done(struct _adapter *padapter)
{
u8 x;
u16 i;
standby(padapter);
for (i = 0; i < 200; i++) {
x = r8712_read8(padapter, EE_9346CR);
if (x & _EEDO)
return true;
udelay(CLOCK_RATE);
}
return false;
}
static void eeprom_clean(struct _adapter *padapter)
{
u16 x;
if (padapter->bSurpriseRemoved)
return;
x = r8712_read8(padapter, EE_9346CR);
if (padapter->bSurpriseRemoved)
return;
x &= ~(_EECS | _EEDI);
r8712_write8(padapter, EE_9346CR, (u8)x);
if (padapter->bSurpriseRemoved)
return;
up_clk(padapter, &x);
if (padapter->bSurpriseRemoved)
return;
down_clk(padapter, &x);
}
void r8712_eeprom_write16(struct _adapter *padapter, u16 reg, u16 data)
{
u8 x;
u8 tmp8_ori, tmp8_new, tmp8_clk_ori, tmp8_clk_new;
tmp8_ori = r8712_read8(padapter, 0x102502f1);
tmp8_new = tmp8_ori & 0xf7;
if (tmp8_ori != tmp8_new)
r8712_write8(padapter, 0x102502f1, tmp8_new);
tmp8_clk_ori = r8712_read8(padapter, 0x10250003);
tmp8_clk_new = tmp8_clk_ori | 0x20;
if (tmp8_clk_new != tmp8_clk_ori)
r8712_write8(padapter, 0x10250003, tmp8_clk_new);
x = r8712_read8(padapter, EE_9346CR);
x &= ~(_EEDI | _EEDO | _EESK | _EEM0);
x |= _EEM1 | _EECS;
r8712_write8(padapter, EE_9346CR, x);
shift_out_bits(padapter, EEPROM_EWEN_OPCODE, 5);
if (padapter->EepromAddressSize == 8)
shift_out_bits(padapter, 0, 6);
else
shift_out_bits(padapter, 0, 4);
standby(padapter);
standby(padapter);
shift_out_bits(padapter, EEPROM_WRITE_OPCODE, 3);
shift_out_bits(padapter, reg, padapter->EepromAddressSize);
shift_out_bits(padapter, data, 16);
if (wait_eeprom_cmd_done(padapter)) {
standby(padapter);
shift_out_bits(padapter, EEPROM_EWDS_OPCODE, 5);
shift_out_bits(padapter, reg, 4);
eeprom_clean(padapter);
}
if (tmp8_clk_new != tmp8_clk_ori)
r8712_write8(padapter, 0x10250003, tmp8_clk_ori);
if (tmp8_new != tmp8_ori)
r8712_write8(padapter, 0x102502f1, tmp8_ori);
}
u16 r8712_eeprom_read16(struct _adapter *padapter, u16 reg)
{
u16 x;
u16 data = 0;
u8 tmp8_ori, tmp8_new, tmp8_clk_ori, tmp8_clk_new;
tmp8_ori = r8712_read8(padapter, 0x102502f1);
tmp8_new = tmp8_ori & 0xf7;
if (tmp8_ori != tmp8_new)
r8712_write8(padapter, 0x102502f1, tmp8_new);
tmp8_clk_ori = r8712_read8(padapter, 0x10250003);
tmp8_clk_new = tmp8_clk_ori | 0x20;
if (tmp8_clk_new != tmp8_clk_ori)
r8712_write8(padapter, 0x10250003, tmp8_clk_new);
if (padapter->bSurpriseRemoved)
goto out;
x = r8712_read8(padapter, EE_9346CR);
if (padapter->bSurpriseRemoved)
goto out;
x &= ~(_EEDI | _EEDO | _EESK | _EEM0);
x |= _EEM1 | _EECS;
r8712_write8(padapter, EE_9346CR, (unsigned char)x);
shift_out_bits(padapter, EEPROM_READ_OPCODE, 3);
shift_out_bits(padapter, reg, padapter->EepromAddressSize);
data = shift_in_bits(padapter);
eeprom_clean(padapter);
out:
if (tmp8_clk_new != tmp8_clk_ori)
r8712_write8(padapter, 0x10250003, tmp8_clk_ori);
if (tmp8_new != tmp8_ori)
r8712_write8(padapter, 0x102502f1, tmp8_ori);
return data;
}
