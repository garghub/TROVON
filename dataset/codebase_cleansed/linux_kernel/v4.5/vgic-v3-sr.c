void __hyp_text __vgic_v3_save_state(struct kvm_vcpu *vcpu)
{
struct vgic_v3_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v3;
u64 val;
u32 max_lr_idx, nr_pri_bits;
dsb(st);
cpu_if->vgic_vmcr = read_gicreg(ICH_VMCR_EL2);
cpu_if->vgic_misr = read_gicreg(ICH_MISR_EL2);
cpu_if->vgic_eisr = read_gicreg(ICH_EISR_EL2);
cpu_if->vgic_elrsr = read_gicreg(ICH_ELSR_EL2);
write_gicreg(0, ICH_HCR_EL2);
val = read_gicreg(ICH_VTR_EL2);
max_lr_idx = vtr_to_max_lr_idx(val);
nr_pri_bits = vtr_to_nr_pri_bits(val);
switch (max_lr_idx) {
case 15:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(15)] = read_gicreg(ICH_LR15_EL2);
case 14:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(14)] = read_gicreg(ICH_LR14_EL2);
case 13:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(13)] = read_gicreg(ICH_LR13_EL2);
case 12:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(12)] = read_gicreg(ICH_LR12_EL2);
case 11:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(11)] = read_gicreg(ICH_LR11_EL2);
case 10:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(10)] = read_gicreg(ICH_LR10_EL2);
case 9:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(9)] = read_gicreg(ICH_LR9_EL2);
case 8:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(8)] = read_gicreg(ICH_LR8_EL2);
case 7:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(7)] = read_gicreg(ICH_LR7_EL2);
case 6:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(6)] = read_gicreg(ICH_LR6_EL2);
case 5:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(5)] = read_gicreg(ICH_LR5_EL2);
case 4:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(4)] = read_gicreg(ICH_LR4_EL2);
case 3:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(3)] = read_gicreg(ICH_LR3_EL2);
case 2:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(2)] = read_gicreg(ICH_LR2_EL2);
case 1:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(1)] = read_gicreg(ICH_LR1_EL2);
case 0:
cpu_if->vgic_lr[VGIC_V3_LR_INDEX(0)] = read_gicreg(ICH_LR0_EL2);
}
switch (nr_pri_bits) {
case 7:
cpu_if->vgic_ap0r[3] = read_gicreg(ICH_AP0R3_EL2);
cpu_if->vgic_ap0r[2] = read_gicreg(ICH_AP0R2_EL2);
case 6:
cpu_if->vgic_ap0r[1] = read_gicreg(ICH_AP0R1_EL2);
default:
cpu_if->vgic_ap0r[0] = read_gicreg(ICH_AP0R0_EL2);
}
switch (nr_pri_bits) {
case 7:
cpu_if->vgic_ap1r[3] = read_gicreg(ICH_AP1R3_EL2);
cpu_if->vgic_ap1r[2] = read_gicreg(ICH_AP1R2_EL2);
case 6:
cpu_if->vgic_ap1r[1] = read_gicreg(ICH_AP1R1_EL2);
default:
cpu_if->vgic_ap1r[0] = read_gicreg(ICH_AP1R0_EL2);
}
val = read_gicreg(ICC_SRE_EL2);
write_gicreg(val | ICC_SRE_EL2_ENABLE, ICC_SRE_EL2);
isb();
write_gicreg(1, ICC_SRE_EL1);
}
void __hyp_text __vgic_v3_restore_state(struct kvm_vcpu *vcpu)
{
struct vgic_v3_cpu_if *cpu_if = &vcpu->arch.vgic_cpu.vgic_v3;
u64 val;
u32 max_lr_idx, nr_pri_bits;
write_gicreg(cpu_if->vgic_sre, ICC_SRE_EL1);
isb();
write_gicreg(cpu_if->vgic_hcr, ICH_HCR_EL2);
write_gicreg(cpu_if->vgic_vmcr, ICH_VMCR_EL2);
val = read_gicreg(ICH_VTR_EL2);
max_lr_idx = vtr_to_max_lr_idx(val);
nr_pri_bits = vtr_to_nr_pri_bits(val);
switch (nr_pri_bits) {
case 7:
write_gicreg(cpu_if->vgic_ap0r[3], ICH_AP0R3_EL2);
write_gicreg(cpu_if->vgic_ap0r[2], ICH_AP0R2_EL2);
case 6:
write_gicreg(cpu_if->vgic_ap0r[1], ICH_AP0R1_EL2);
default:
write_gicreg(cpu_if->vgic_ap0r[0], ICH_AP0R0_EL2);
}
switch (nr_pri_bits) {
case 7:
write_gicreg(cpu_if->vgic_ap1r[3], ICH_AP1R3_EL2);
write_gicreg(cpu_if->vgic_ap1r[2], ICH_AP1R2_EL2);
case 6:
write_gicreg(cpu_if->vgic_ap1r[1], ICH_AP1R1_EL2);
default:
write_gicreg(cpu_if->vgic_ap1r[0], ICH_AP1R0_EL2);
}
switch (max_lr_idx) {
case 15:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(15)], ICH_LR15_EL2);
case 14:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(14)], ICH_LR14_EL2);
case 13:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(13)], ICH_LR13_EL2);
case 12:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(12)], ICH_LR12_EL2);
case 11:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(11)], ICH_LR11_EL2);
case 10:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(10)], ICH_LR10_EL2);
case 9:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(9)], ICH_LR9_EL2);
case 8:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(8)], ICH_LR8_EL2);
case 7:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(7)], ICH_LR7_EL2);
case 6:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(6)], ICH_LR6_EL2);
case 5:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(5)], ICH_LR5_EL2);
case 4:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(4)], ICH_LR4_EL2);
case 3:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(3)], ICH_LR3_EL2);
case 2:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(2)], ICH_LR2_EL2);
case 1:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(1)], ICH_LR1_EL2);
case 0:
write_gicreg(cpu_if->vgic_lr[VGIC_V3_LR_INDEX(0)], ICH_LR0_EL2);
}
isb();
dsb(sy);
if (!cpu_if->vgic_sre) {
write_gicreg(read_gicreg(ICC_SRE_EL2) & ~ICC_SRE_EL2_ENABLE,
ICC_SRE_EL2);
}
}
static u64 __hyp_text __vgic_v3_read_ich_vtr_el2(void)
{
return read_gicreg(ICH_VTR_EL2);
}
