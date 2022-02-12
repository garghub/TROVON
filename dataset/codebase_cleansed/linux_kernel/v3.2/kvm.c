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
static void kvm_patch_ins_wrteei(u32 *inst)
{
u32 *p;
int distance_start;
int distance_end;
ulong next_inst;
p = kvm_alloc(kvm_emulate_wrteei_len * 4);
if (!p)
return;
distance_start = (ulong)p - (ulong)inst;
next_inst = ((ulong)inst + 4);
distance_end = next_inst - (ulong)&p[kvm_emulate_wrteei_branch_offs];
if (distance_start > KVM_INST_B_MAX) {
kvm_patching_worked = false;
return;
}
memcpy(p, kvm_emulate_wrteei, kvm_emulate_wrteei_len * 4);
p[kvm_emulate_wrteei_branch_offs] |= distance_end & KVM_INST_B_MASK;
p[kvm_emulate_wrteei_ee_offs] |= (*inst & MSR_EE);
flush_icache_range((ulong)p, (ulong)p + kvm_emulate_wrteei_len * 4);
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
ulong in[8];
ulong out[8];
in[0] = KVM_MAGIC_PAGE;
in[1] = KVM_MAGIC_PAGE;
kvm_hypercall(in, out, HC_VENDOR_KVM | KVM_HC_PPC_MAP_MAGIC_PAGE);
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
case KVM_INST_MFSPR_SPRG0:
kvm_patch_ins_ld(inst, magic_var(sprg0), inst_rt);
break;
case KVM_INST_MFSPR_SPRG1:
kvm_patch_ins_ld(inst, magic_var(sprg1), inst_rt);
break;
case KVM_INST_MFSPR_SPRG2:
kvm_patch_ins_ld(inst, magic_var(sprg2), inst_rt);
break;
case KVM_INST_MFSPR_SPRG3:
kvm_patch_ins_ld(inst, magic_var(sprg3), inst_rt);
break;
case KVM_INST_MFSPR_SRR0:
kvm_patch_ins_ld(inst, magic_var(srr0), inst_rt);
break;
case KVM_INST_MFSPR_SRR1:
kvm_patch_ins_ld(inst, magic_var(srr1), inst_rt);
break;
case KVM_INST_MFSPR_DAR:
kvm_patch_ins_ld(inst, magic_var(dar), inst_rt);
break;
case KVM_INST_MFSPR_DSISR:
kvm_patch_ins_lwz(inst, magic_var(dsisr), inst_rt);
break;
case KVM_INST_MTSPR_SPRG0:
kvm_patch_ins_std(inst, magic_var(sprg0), inst_rt);
break;
case KVM_INST_MTSPR_SPRG1:
kvm_patch_ins_std(inst, magic_var(sprg1), inst_rt);
break;
case KVM_INST_MTSPR_SPRG2:
kvm_patch_ins_std(inst, magic_var(sprg2), inst_rt);
break;
case KVM_INST_MTSPR_SPRG3:
kvm_patch_ins_std(inst, magic_var(sprg3), inst_rt);
break;
case KVM_INST_MTSPR_SRR0:
kvm_patch_ins_std(inst, magic_var(srr0), inst_rt);
break;
case KVM_INST_MTSPR_SRR1:
kvm_patch_ins_std(inst, magic_var(srr1), inst_rt);
break;
case KVM_INST_MTSPR_DAR:
kvm_patch_ins_std(inst, magic_var(dar), inst_rt);
break;
case KVM_INST_MTSPR_DSISR:
kvm_patch_ins_stw(inst, magic_var(dsisr), inst_rt);
break;
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
case KVM_INST_WRTEEI_1:
kvm_patch_ins_wrteei(inst);
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
for (p = start; p < end; p++)
kvm_check_ins(p, features);
printk(KERN_INFO "KVM: Live patching for a fast VM %s\n",
kvm_patching_worked ? "worked" : "failed");
}
unsigned long kvm_hypercall(unsigned long *in,
unsigned long *out,
unsigned long nr)
{
unsigned long register r0 asm("r0");
unsigned long register r3 asm("r3") = in[0];
unsigned long register r4 asm("r4") = in[1];
unsigned long register r5 asm("r5") = in[2];
unsigned long register r6 asm("r6") = in[3];
unsigned long register r7 asm("r7") = in[4];
unsigned long register r8 asm("r8") = in[5];
unsigned long register r9 asm("r9") = in[6];
unsigned long register r10 asm("r10") = in[7];
unsigned long register r11 asm("r11") = nr;
unsigned long register r12 asm("r12");
asm volatile("bl kvm_hypercall_start"
: "=r"(r0), "=r"(r3), "=r"(r4), "=r"(r5), "=r"(r6),
"=r"(r7), "=r"(r8), "=r"(r9), "=r"(r10), "=r"(r11),
"=r"(r12)
: "r"(r3), "r"(r4), "r"(r5), "r"(r6), "r"(r7), "r"(r8),
"r"(r9), "r"(r10), "r"(r11)
: "memory", "cc", "xer", "ctr", "lr");
out[0] = r4;
out[1] = r5;
out[2] = r6;
out[3] = r7;
out[4] = r8;
out[5] = r9;
out[6] = r10;
out[7] = r11;
return r3;
}
static int kvm_para_setup(void)
{
extern u32 kvm_hypercall_start;
struct device_node *hyper_node;
u32 *insts;
int len, i;
hyper_node = of_find_node_by_path("/hypervisor");
if (!hyper_node)
return -1;
insts = (u32*)of_get_property(hyper_node, "hcall-instructions", &len);
if (len % 4)
return -1;
if (len > (4 * 4))
return -1;
for (i = 0; i < (len / 4); i++)
kvm_patch_ins(&(&kvm_hypercall_start)[i], insts[i]);
return 0;
}
static __init void kvm_free_tmp(void)
{
unsigned long start, end;
start = (ulong)&kvm_tmp[kvm_tmp_index + (PAGE_SIZE - 1)] & PAGE_MASK;
end = (ulong)&kvm_tmp[ARRAY_SIZE(kvm_tmp)] & PAGE_MASK;
for (; start < end; start += PAGE_SIZE) {
ClearPageReserved(virt_to_page(start));
init_page_count(virt_to_page(start));
free_page(start);
totalram_pages++;
}
}
static int __init kvm_guest_init(void)
{
if (!kvm_para_available())
goto free_tmp;
if (kvm_para_setup())
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
