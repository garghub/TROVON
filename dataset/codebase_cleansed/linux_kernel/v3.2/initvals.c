static void ath5k_hw_ini_registers(struct ath5k_hw *ah, unsigned int size,
const struct ath5k_ini *ini_regs, bool skip_pcu)
{
unsigned int i;
for (i = 0; i < size; i++) {
if (skip_pcu &&
ini_regs[i].ini_register >= AR5K_PCU_MIN &&
ini_regs[i].ini_register <= AR5K_PCU_MAX)
continue;
switch (ini_regs[i].ini_mode) {
case AR5K_INI_READ:
ath5k_hw_reg_read(ah, ini_regs[i].ini_register);
break;
case AR5K_INI_WRITE:
default:
AR5K_REG_WAIT(i);
ath5k_hw_reg_write(ah, ini_regs[i].ini_value,
ini_regs[i].ini_register);
}
}
}
static void ath5k_hw_ini_mode_registers(struct ath5k_hw *ah,
unsigned int size, const struct ath5k_ini_mode *ini_mode,
u8 mode)
{
unsigned int i;
for (i = 0; i < size; i++) {
AR5K_REG_WAIT(i);
ath5k_hw_reg_write(ah, ini_mode[i].mode_value[mode],
(u32)ini_mode[i].mode_register);
}
}
int ath5k_hw_write_initvals(struct ath5k_hw *ah, u8 mode, bool skip_pcu)
{
if (ah->ah_version == AR5K_AR5212) {
ath5k_hw_ini_mode_registers(ah,
ARRAY_SIZE(ar5212_ini_mode_start),
ar5212_ini_mode_start, mode);
ath5k_hw_ini_registers(ah, ARRAY_SIZE(ar5212_ini_common_start),
ar5212_ini_common_start, skip_pcu);
switch (ah->ah_radio) {
case AR5K_RF5111:
ath5k_hw_ini_mode_registers(ah,
ARRAY_SIZE(rf5111_ini_mode_end),
rf5111_ini_mode_end, mode);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5111_ini_common_end),
rf5111_ini_common_end, skip_pcu);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5111_ini_bbgain),
rf5111_ini_bbgain, skip_pcu);
break;
case AR5K_RF5112:
ath5k_hw_ini_mode_registers(ah,
ARRAY_SIZE(rf5112_ini_mode_end),
rf5112_ini_mode_end, mode);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5112_ini_common_end),
rf5112_ini_common_end, skip_pcu);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5112_ini_bbgain),
rf5112_ini_bbgain, skip_pcu);
break;
case AR5K_RF5413:
ath5k_hw_ini_mode_registers(ah,
ARRAY_SIZE(rf5413_ini_mode_end),
rf5413_ini_mode_end, mode);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5413_ini_common_end),
rf5413_ini_common_end, skip_pcu);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5112_ini_bbgain),
rf5112_ini_bbgain, skip_pcu);
break;
case AR5K_RF2316:
case AR5K_RF2413:
ath5k_hw_ini_mode_registers(ah,
ARRAY_SIZE(rf2413_ini_mode_end),
rf2413_ini_mode_end, mode);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf2413_ini_common_end),
rf2413_ini_common_end, skip_pcu);
if (ah->ah_radio == AR5K_RF2316) {
ath5k_hw_reg_write(ah, 0x00004000,
AR5K_PHY_AGC);
ath5k_hw_reg_write(ah, 0x081b7caa,
0xa274);
}
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5112_ini_bbgain),
rf5112_ini_bbgain, skip_pcu);
break;
case AR5K_RF2317:
ath5k_hw_ini_mode_registers(ah,
ARRAY_SIZE(rf2413_ini_mode_end),
rf2413_ini_mode_end, mode);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf2425_ini_common_end),
rf2425_ini_common_end, skip_pcu);
ath5k_hw_reg_write(ah, 0x00180a65, AR5K_PHY_GAIN);
ath5k_hw_reg_write(ah, 0x00004000, AR5K_PHY_AGC);
AR5K_REG_WRITE_BITS(ah, AR5K_PHY_TPC_RG5,
AR5K_PHY_TPC_RG5_PD_GAIN_OVERLAP, 0xa);
ath5k_hw_reg_write(ah, 0x800000a8, 0x8140);
ath5k_hw_reg_write(ah, 0x000000ff, 0x9958);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5112_ini_bbgain),
rf5112_ini_bbgain, skip_pcu);
break;
case AR5K_RF2425:
ath5k_hw_ini_mode_registers(ah,
ARRAY_SIZE(rf2425_ini_mode_end),
rf2425_ini_mode_end, mode);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf2425_ini_common_end),
rf2425_ini_common_end, skip_pcu);
ath5k_hw_ini_registers(ah,
ARRAY_SIZE(rf5112_ini_bbgain),
rf5112_ini_bbgain, skip_pcu);
break;
default:
return -EINVAL;
}
} else if (ah->ah_version == AR5K_AR5211) {
if (mode > 2) {
ATH5K_ERR(ah,
"unsupported channel mode: %d\n", mode);
return -EINVAL;
}
ath5k_hw_ini_mode_registers(ah, ARRAY_SIZE(ar5211_ini_mode),
ar5211_ini_mode, mode);
ath5k_hw_ini_registers(ah, ARRAY_SIZE(ar5211_ini),
ar5211_ini, skip_pcu);
ath5k_hw_ini_registers(ah, ARRAY_SIZE(rf5111_ini_bbgain),
rf5111_ini_bbgain, skip_pcu);
} else if (ah->ah_version == AR5K_AR5210) {
ath5k_hw_ini_registers(ah, ARRAY_SIZE(ar5210_ini),
ar5210_ini, skip_pcu);
}
return 0;
}
