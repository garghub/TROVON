u32 __hyp_text __init_stage2_translation(void)
{
u64 val = VTCR_EL2_FLAGS;
u64 parange;
u64 tmp;
parange = read_sysreg(id_aa64mmfr0_el1) & 7;
val |= parange << 16;
switch (parange) {
case 0:
parange = 32;
break;
case 1:
parange = 36;
break;
case 2:
parange = 40;
break;
case 3:
parange = 42;
break;
case 4:
parange = 44;
break;
case 5:
default:
parange = 48;
break;
}
val |= 64 - (parange > 40 ? 40 : parange);
tmp = (read_sysreg(id_aa64mmfr1_el1) >> ID_AA64MMFR1_HADBS_SHIFT) & 0xf;
if (tmp)
val |= VTCR_EL2_HA;
tmp = (read_sysreg(id_aa64mmfr1_el1) >> ID_AA64MMFR1_VMIDBITS_SHIFT) & 0xf;
val |= (tmp == ID_AA64MMFR1_VMIDBITS_16) ?
VTCR_EL2_VS_16BIT :
VTCR_EL2_VS_8BIT;
write_sysreg(val, vtcr_el2);
return parange;
}
