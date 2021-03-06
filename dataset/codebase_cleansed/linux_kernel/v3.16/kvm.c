static inline void kvm_patch_ins(u32 *inst, u32 new_inst)
{
*inst = new_inst;
flush_icache_range((ulong)inst, (ulong)inst + 4);
}
static void kvm_patch_ins_ll(u32 *inst, long addr, u32 rt)
{
#ifdef CONFIG_64BIT
kvm_patch_ins(inst, KVM_INST_LD | rt | (addr & 0x0000fffc));
#else
kvm_patch_ins(inst, KVM_INST_LWZ | rt | (addr & 0x0000fffc));
#endif
}
static void kvm_patch_ins_ld(u32 *inst, long addr, u32 rt)
{
#ifdef CONFIG_64BIT
kvm_patch_ins(inst, KVM_INST_LD | rt | (addr & 0x0000fffc));
#else
kvm_patch_ins(inst, KVM_INST_LWZ | rt | ((addr + 4) & 0x0000fffc));
#endif
}
static void kvm_patch_ins_lwz(u32 *inst, long addr, u32 rt)
{
kvm_patch_ins(inst, KVM_INST_LWZ | rt | (addr & 0x0000ffff));
}
static void kvm_patch_ins_std(u32 *inst, long addr, u32 rt)
{
#ifdef CONFIG_64BIT
kvm_patch_ins(inst, KVM_INST_STD | rt | (addr & 0x0000fffc));
#else
kvm_patch_ins(inst, KVM_INST_STW | rt | ((addr + 4) & 0x0000fffc));
#endif
}
static void kvm_patch_ins_stw(u32 *inst, long addr, u32 rt)
{
kvm_patch_ins(inst, KVM_INST_STW | rt | (addr & 0x0000fffc));
}
static void kvm_patch_ins_nop(u32 *inst)
{
kvm_patch_ins(inst, KVM_INST_NOP);
}
static void kvm_patch_ins_b(u32 *inst, int addr)
{
#if defined(CONFIG_RELOCATABLE) && defined(CONFIG_PPC_BOOK3S)
if ((ulong)inst < (ulong)&__end_interrupts)
return;
#endif
kvm_patch_ins(inst, KVM_INST_B | (addr & KVM_INST_B_MASK));
}
static u32 *kvm_alloc(int len)
{
u32 *p;
if ((kvm_tmp_index + len) > ARRAY_SIZE(kvm_tmp)) {
printk(KERN_ERR "KVM: No more space (%d + %d)\n",
kvm_tmp_index, len);
kvm_patching_worked = false;
return NULL;
}
p = (void*)&kvm_tmp[kvm_tmp_index];
kvm_tmp_index += len;
return p;
}
static void kvm_patch_ins_mtmsrd(u32 *inst, u32 rt)
{
u32 *p;
int distance_start;
int distance_end;
ulong next_inst;
p = kvm_alloc(kvm_emulate_mtmsrd_len * 4);
if (!p)
return;
distance_start = (ulong)p - (ulong)inst;
next_inst = ((ulong)inst + 4);
distance_end = next_inst - (ulong)&p[kvm_emulate_mtmsrd_branch_offs];
if (distance_start > KVM_INST_B_MAX) {
kvm_patching_worked = false;
return;
}
memcpy(p, kvm_emulate_mtmsrd, kvm_emulate_mtmsrd_len * 4);
p[kvm_emulate_mtmsrd_branch_offs] |= distance_end & KVM_INST_B_MASK;
switch (get_rt(rt)) {
case 30:
kvm_patch_ins_ll(&p[kvm_emulate_mtmsrd_reg_offs],
magic_var(scratch2), KVM_RT_30);
break;
case 31:
kvm_patch_ins_ll(&p[kvm_emulate_mtmsrd_reg_offs],
magic_var(scratch1), KVM_RT_30);
break;
default:
p[kvm_emulate_mtmsrd_reg_offs] |= rt;
break;
}
p[kvm_emulate_mtmsrd_orig_ins_offs] = *inst;
flush_icache_range((ulong)p, (ulong)p + kvm_emulate_mtmsrd_len * 4);
kvm_patch_ins_b(inst, distance_start);
}
static void kvm_patch_ins_mtmsr(u32 *inst, u32 rt)
{
u32 *p;
int distance_start;
int distance_end;
ulong next_inst;
p = kvm_alloc(kvm_emulate_mtmsr_len * 4);
if (!p)
return;
distance_start = (ulong)p - (ulong)inst;
next_inst = ((ulong)inst + 4);
distance_end = next_inst - (ulong)&p[kvm_emulate_mtmsr_branch_offs];
if (distance_start > KVM_INST_B_MAX) {
kvm_patching_worked = false;
return;
}
memcpy(p, kvm_emulate_mtmsr, kvm_emulate_mtmsr_len * 4);
p[kvm_emulate_mtmsr_branch_offs] |= distance_end & KVM_INST_B_MASK;
switch (get_rt(rt)) {
case 30:
kvm_patch_ins_ll(&p[kvm_emulate_mtmsr_reg1_offs],
magic_var(scratch2), KVM_RT_30);
kvm_patch_ins_ll(&p[kvm_emulate_mtmsr_reg2_offs],
magic_var(scratch2), KVM_RT_30);
break;
case 31:
kvm_patch_ins_ll(&p[kvm_emulate_mtmsr_reg1_offs],
magic_var(scratch1), KVM_RT_30);
kvm_patch_ins_ll(&p[kvm_emulate_mtmsr_reg2_offs],
magic_var(scratch1), KVM_RT_30);
break;
default:
p[kvm_emulate_mtmsr_reg1_offs] |= rt;
p[kvm_emulate_mtmsr_reg2_offs] |= rt;
break;
}
p[kvm_emulate_mtmsr_orig_ins_offs] = *inst;
flush_icache_range((ulong)p, (ulong)p + kvm_emulate_mtmsr_len * 4);
kvm_patch_ins_b(inst, distance_start);
}
static void kvm_patch_ins_wrtee(u32 *inst, u32 rt, int imm_one)
{
u32 *p;
int distance_start;
int distance_end;
ulong next_inst;
p = kvm_alloc(kvm_emulate_wrtee_len * 4);
if (!p)
return;
distance_start = (ulong)p - (ulong)inst;
next_inst = ((ulong)inst + 4);
distance_end = next_inst - (ulong)&p[kvm_emulate_wrtee_branch_offs];
if (distance_start > KVM_INST_B_MAX) {
kvm_patching_worked = false;
return;
}
memcpy(p, kvm_emulate_wrtee, kvm_emulate_wrtee_len * 4);
p[kvm_emulate_wrtee_branch_offs] |= distance_end & KVM_INST_B_MASK;
if (imm_one) {
p[kvm_emulate_wrtee_reg_offs] =
KVM_INST_LI | __PPC_RT(R30) | MSR_EE;
} else {
switch (get_rt(rt)) {
case 30:
kvm_patch_ins_ll(&p[kvm_emulate_wrtee_reg_offs],
magic_var(scratch2), KVM_RT_30);
break;
case 31:
kvm_patch_ins_ll(&p[kvm_emulate_wrtee_reg_offs],
magic_var(scratch1), KVM_RT_30);
break;
default:
p[kvm_emulate_wrtee_reg_offs] |= rt;
break;
}
}
p[kvm_emulate_wrtee_orig_ins_offs] = *inst;
flush_icache_range((ulong)p, (ulong)p + kvm_emulate_wrtee_len * 4);
kvm_patch_ins_b(inst, distance_start);
}
static void kvm_patch_ins_wrteei_0(u32 *inst)
{
u32 *p;
int distance_start;
int distance_end;
ulong next_inst;
p = kvm_alloc(kvm_emulate_wrteei_0_len * 4);
if (!p)
return;
distance_start = (ulong)p - (ulong)inst;
next_inst = ((ulong)inst + 4);
distance_end = next_inst - (ulong)&p[kvm_emulate_wrteei_0_branch_offs];
if (distance_start > KVM_INST_B_MAX) {
kvm_patching_worked = false;
return;
}
memcpy(p, kvm_emulate_wrteei_0, kvm_emulate_wrteei_0_len * 4);
p[kvm_emulate_wrteei_0_branch_offs] |= distance_end & KVM_INST_B_MASK;
flush_icache_range((ulong)p, (ulong)p + kvm_emulate_wrteei_0_len * 4);
kvm_patch_ins_b(inst, distance_start);
}
static void kvm_patch_ins_mtsrin(u32 *inst, u32 rt, u32 rb)
{
u32 *p;
int distance_start;
int distance_end;
ulong next_inst;
p = kvm_alloc(kvm_emulate_mtsrin_len * 4);
if (!p)
return;
distance_start = (ulong)p - (ulong)inst;
next_inst = ((ulong)inst + 4);
distance_end = next_inst - (ulong)&p[kvm_emulate_mtsrin_branch_offs];
if (distance_start > KVM_INST_B_MAX) {
kvm_patching_worked = false;
return;
}
memcpy(p, kvm_emulate_mtsrin, kvm_emulate_mtsrin_len * 4);
p[kvm_emulate_mtsrin_branch_offs] |= distance_end & KVM_INST_B_MASK;
p[kvm_emulate_mtsrin_reg1_offs] |= (rb << 10);
p[kvm_emulate_mtsrin_reg2_offs] |= rt;
p[kvm_emulate_mtsrin_orig_ins_offs] = *inst;
flush_icache_range((ulong)p, (ulong)p + kvm_emulate_mtsrin_len * 4);
kvm_patch_ins_b(inst, distance_start);
}
static void kvm_map_magic_page(void *data)
{
u32 *features = data;
ulong in[8] = {0};
ulong out[8];
in[0] = KVM_MAGIC_PAGE;
in[1] = KVM_MAGIC_PAGE | MAGIC_PAGE_FLAG_NOT_MAPPED_NX;
epapr_hypercall(in, out, KVM_HCALL_TOKEN(KVM_HC_PPC_MAP_MAGIC_PAGE));
*features = out[0];
}
static void kvm_check_ins(u32 *inst, u32 features)
{
u32 _inst = *inst;
u32 inst_no_rt = _inst & ~KVM_MASK_RT;
u32 inst_rt = _inst & KVM_MASK_RT;
switch (inst_no_rt) {
case KVM_INST_MFMSR:
kvm_patch_ins_ld(inst, magic_var(msr), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SPRG0):
kvm_patch_ins_ld(inst, magic_var(sprg0), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SPRG1):
kvm_patch_ins_ld(inst, magic_var(sprg1), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SPRG2):
kvm_patch_ins_ld(inst, magic_var(sprg2), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SPRG3):
kvm_patch_ins_ld(inst, magic_var(sprg3), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SRR0):
kvm_patch_ins_ld(inst, magic_var(srr0), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SRR1):
kvm_patch_ins_ld(inst, magic_var(srr1), inst_rt);
break;
#ifdef CONFIG_BOOKE
case KVM_INST_MFSPR(SPRN_DEAR):
#else
case KVM_INST_MFSPR(SPRN_DAR):
#endif
kvm_patch_ins_ld(inst, magic_var(dar), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_DSISR):
kvm_patch_ins_lwz(inst, magic_var(dsisr), inst_rt);
break;
#ifdef CONFIG_PPC_BOOK3E_MMU
case KVM_INST_MFSPR(SPRN_MAS0):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(mas0), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_MAS1):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(mas1), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_MAS2):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_ld(inst, magic_var(mas2), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_MAS3):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(mas7_3) + 4, inst_rt);
break;
case KVM_INST_MFSPR(SPRN_MAS4):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(mas4), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_MAS6):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(mas6), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_MAS7):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(mas7_3), inst_rt);
break;
#endif
case KVM_INST_MFSPR(SPRN_SPRG4):
#ifdef CONFIG_BOOKE
case KVM_INST_MFSPR(SPRN_SPRG4R):
#endif
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_ld(inst, magic_var(sprg4), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SPRG5):
#ifdef CONFIG_BOOKE
case KVM_INST_MFSPR(SPRN_SPRG5R):
#endif
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_ld(inst, magic_var(sprg5), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SPRG6):
#ifdef CONFIG_BOOKE
case KVM_INST_MFSPR(SPRN_SPRG6R):
#endif
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_ld(inst, magic_var(sprg6), inst_rt);
break;
case KVM_INST_MFSPR(SPRN_SPRG7):
#ifdef CONFIG_BOOKE
case KVM_INST_MFSPR(SPRN_SPRG7R):
#endif
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_ld(inst, magic_var(sprg7), inst_rt);
break;
#ifdef CONFIG_BOOKE
case KVM_INST_MFSPR(SPRN_ESR):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(esr), inst_rt);
break;
#endif
case KVM_INST_MFSPR(SPRN_PIR):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_lwz(inst, magic_var(pir), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SPRG0):
kvm_patch_ins_std(inst, magic_var(sprg0), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SPRG1):
kvm_patch_ins_std(inst, magic_var(sprg1), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SPRG2):
kvm_patch_ins_std(inst, magic_var(sprg2), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SPRG3):
kvm_patch_ins_std(inst, magic_var(sprg3), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SRR0):
kvm_patch_ins_std(inst, magic_var(srr0), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SRR1):
kvm_patch_ins_std(inst, magic_var(srr1), inst_rt);
break;
#ifdef CONFIG_BOOKE
case KVM_INST_MTSPR(SPRN_DEAR):
#else
case KVM_INST_MTSPR(SPRN_DAR):
#endif
kvm_patch_ins_std(inst, magic_var(dar), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_DSISR):
kvm_patch_ins_stw(inst, magic_var(dsisr), inst_rt);
break;
#ifdef CONFIG_PPC_BOOK3E_MMU
case KVM_INST_MTSPR(SPRN_MAS0):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_stw(inst, magic_var(mas0), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_MAS1):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_stw(inst, magic_var(mas1), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_MAS2):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_std(inst, magic_var(mas2), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_MAS3):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_stw(inst, magic_var(mas7_3) + 4, inst_rt);
break;
case KVM_INST_MTSPR(SPRN_MAS4):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_stw(inst, magic_var(mas4), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_MAS6):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_stw(inst, magic_var(mas6), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_MAS7):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_stw(inst, magic_var(mas7_3), inst_rt);
break;
#endif
case KVM_INST_MTSPR(SPRN_SPRG4):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_std(inst, magic_var(sprg4), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SPRG5):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_std(inst, magic_var(sprg5), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SPRG6):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_std(inst, magic_var(sprg6), inst_rt);
break;
case KVM_INST_MTSPR(SPRN_SPRG7):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_std(inst, magic_var(sprg7), inst_rt);
break;
#ifdef CONFIG_BOOKE
case KVM_INST_MTSPR(SPRN_ESR):
if (features & KVM_MAGIC_FEAT_MAS0_TO_SPRG7)
kvm_patch_ins_stw(inst, magic_var(esr), inst_rt);
break;
#endif
case KVM_INST_TLBSYNC:
kvm_patch_ins_nop(inst);
break;
case KVM_INST_MTMSRD_L1:
kvm_patch_ins_mtmsrd(inst, inst_rt);
break;
case KVM_INST_MTMSR:
case KVM_INST_MTMSRD_L0:
kvm_patch_ins_mtmsr(inst, inst_rt);
break;
#ifdef CONFIG_BOOKE
case KVM_INST_WRTEE:
kvm_patch_ins_wrtee(inst, inst_rt, 0);
break;
#endif
}
switch (inst_no_rt & ~KVM_MASK_RB) {
#ifdef CONFIG_PPC_BOOK3S_32
case KVM_INST_MTSRIN:
if (features & KVM_MAGIC_FEAT_SR) {
u32 inst_rb = _inst & KVM_MASK_RB;
kvm_patch_ins_mtsrin(inst, inst_rt, inst_rb);
}
break;
break;
#endif
}
switch (_inst) {
#ifdef CONFIG_BOOKE
case KVM_INST_WRTEEI_0:
kvm_patch_ins_wrteei_0(inst);
break;
case KVM_INST_WRTEEI_1:
kvm_patch_ins_wrtee(inst, 0, 1);
break;
#endif
}
}
static void kvm_use_magic_page(void)
{
u32 *p;
u32 *start, *end;
u32 tmp;
u32 features;
on_each_cpu(kvm_map_magic_page, &features, 1);
if (__get_user(tmp, (u32*)KVM_MAGIC_PAGE)) {
kvm_patching_worked = false;
return;
}
start = (void*)_stext;
end = (void*)_etext;
local_irq_disable();
for (p = start; p < end; p++) {
if (p >= kvm_template_start && p < kvm_template_end) {
p = kvm_template_end - 1;
continue;
}
kvm_check_ins(p, features);
}
local_irq_enable();
printk(KERN_INFO "KVM: Live patching for a fast VM %s\n",
kvm_patching_worked ? "worked" : "failed");
}
static __init void kvm_free_tmp(void)
{
free_reserved_area(&kvm_tmp[kvm_tmp_index],
&kvm_tmp[ARRAY_SIZE(kvm_tmp)], -1, NULL);
}
static int __init kvm_guest_init(void)
{
if (!kvm_para_available())
goto free_tmp;
if (!epapr_paravirt_enabled)
goto free_tmp;
if (kvm_para_has_feature(KVM_FEATURE_MAGIC_PAGE))
kvm_use_magic_page();
#ifdef CONFIG_PPC_BOOK3S_64
powersave_nap = 1;
#endif
free_tmp:
kvm_free_tmp();
return 0;
}
