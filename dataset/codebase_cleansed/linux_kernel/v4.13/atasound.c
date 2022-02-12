void atari_microwire_cmd (int cmd)
{
tt_microwire.mask = 0x7ff;
tt_microwire.data = MW_LM1992_ADDR | cmd;
while( tt_microwire.mask != 0x7ff)
;
}
void atari_mksound (unsigned int hz, unsigned int ticks)
{
unsigned long flags;
unsigned char tmp;
int period;
local_irq_save(flags);
sound_ym.rd_data_reg_sel = 7;
tmp = sound_ym.rd_data_reg_sel;
tmp |= 011;
sound_ym.wd_data = tmp;
if (hz) {
period = PSG_FREQ / hz;
if (period > 0xfff) period = 0xfff;
sound_ym.rd_data_reg_sel = 0;
sound_ym.wd_data = period & 0xff;
sound_ym.rd_data_reg_sel = 1;
sound_ym.wd_data = (period >> 8) & 0xf;
if (ticks) {
int length = (ticks * PSG_ENV_FREQ_10) / HZ / 10;
if (length > 0xffff) length = 0xffff;
sound_ym.rd_data_reg_sel = 11;
sound_ym.wd_data = length & 0xff;
sound_ym.rd_data_reg_sel = 12;
sound_ym.wd_data = length >> 8;
sound_ym.rd_data_reg_sel = 13;
sound_ym.wd_data = 0;
sound_ym.rd_data_reg_sel = 8;
sound_ym.wd_data = 0x10;
} else {
sound_ym.rd_data_reg_sel = 8;
sound_ym.wd_data = 15;
}
sound_ym.rd_data_reg_sel = 7;
tmp &= ~1;
sound_ym.wd_data = tmp;
}
local_irq_restore(flags);
}
