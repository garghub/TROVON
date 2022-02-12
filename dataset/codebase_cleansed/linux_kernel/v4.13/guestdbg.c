static void extend_address_range(u64 *start, u64 *stop, u64 estart, int len)
{
u64 estop;
if (len > 0)
len--;
else
len = 0;
estop = estart + len;
if ((*start == 0) && (*stop == 0)) {
*start = estart;
*stop = estop;
} else if (*start <= *stop) {
if (estart < *start)
*start = estart;
if (estop > *stop)
*stop = estop;
} else {
if (estart <= *stop) {
if (estop > *stop)
*stop = estop;
} else if (estop > *start) {
if (estart < *start)
*start = estart;
}
else if ((estop - *stop) < (*start - estart))
*stop = estop;
else
*start = estart;
}
}
static void enable_all_hw_bp(struct kvm_vcpu *vcpu)
{
unsigned long start, len;
u64 *cr9 = &vcpu->arch.sie_block->gcr[9];
u64 *cr10 = &vcpu->arch.sie_block->gcr[10];
u64 *cr11 = &vcpu->arch.sie_block->gcr[11];
int i;
if (vcpu->arch.guestdbg.nr_hw_bp <= 0 ||
vcpu->arch.guestdbg.hw_bp_info == NULL)
return;
if (!(*cr9 & PER_EVENT_BRANCH))
*cr9 |= PER_CONTROL_BRANCH_ADDRESS;
*cr9 |= PER_EVENT_IFETCH | PER_EVENT_BRANCH;
for (i = 0; i < vcpu->arch.guestdbg.nr_hw_bp; i++) {
start = vcpu->arch.guestdbg.hw_bp_info[i].addr;
len = vcpu->arch.guestdbg.hw_bp_info[i].len;
if (start < MAX_INST_SIZE) {
len += start;
start = 0;
} else {
start -= MAX_INST_SIZE;
len += MAX_INST_SIZE;
}
extend_address_range(cr10, cr11, start, len);
}
}
static void enable_all_hw_wp(struct kvm_vcpu *vcpu)
{
unsigned long start, len;
u64 *cr9 = &vcpu->arch.sie_block->gcr[9];
u64 *cr10 = &vcpu->arch.sie_block->gcr[10];
u64 *cr11 = &vcpu->arch.sie_block->gcr[11];
int i;
if (vcpu->arch.guestdbg.nr_hw_wp <= 0 ||
vcpu->arch.guestdbg.hw_wp_info == NULL)
return;
if (*cr9 & PER_EVENT_STORE && *cr9 & PER_CONTROL_ALTERATION) {
*cr9 &= ~PER_CONTROL_ALTERATION;
*cr10 = 0;
*cr11 = -1UL;
} else {
*cr9 &= ~PER_CONTROL_ALTERATION;
*cr9 |= PER_EVENT_STORE;
for (i = 0; i < vcpu->arch.guestdbg.nr_hw_wp; i++) {
start = vcpu->arch.guestdbg.hw_wp_info[i].addr;
len = vcpu->arch.guestdbg.hw_wp_info[i].len;
extend_address_range(cr10, cr11, start, len);
}
}
}
void kvm_s390_backup_guest_per_regs(struct kvm_vcpu *vcpu)
{
vcpu->arch.guestdbg.cr0 = vcpu->arch.sie_block->gcr[0];
vcpu->arch.guestdbg.cr9 = vcpu->arch.sie_block->gcr[9];
vcpu->arch.guestdbg.cr10 = vcpu->arch.sie_block->gcr[10];
vcpu->arch.guestdbg.cr11 = vcpu->arch.sie_block->gcr[11];
}
void kvm_s390_restore_guest_per_regs(struct kvm_vcpu *vcpu)
{
vcpu->arch.sie_block->gcr[0] = vcpu->arch.guestdbg.cr0;
vcpu->arch.sie_block->gcr[9] = vcpu->arch.guestdbg.cr9;
vcpu->arch.sie_block->gcr[10] = vcpu->arch.guestdbg.cr10;
vcpu->arch.sie_block->gcr[11] = vcpu->arch.guestdbg.cr11;
}
void kvm_s390_patch_guest_per_regs(struct kvm_vcpu *vcpu)
{
if (guestdbg_sstep_enabled(vcpu)) {
vcpu->arch.sie_block->gcr[0] &= ~0x800ul;
vcpu->arch.sie_block->gcr[9] |= PER_EVENT_IFETCH;
vcpu->arch.sie_block->gcr[10] = 0;
vcpu->arch.sie_block->gcr[11] = -1UL;
}
if (guestdbg_hw_bp_enabled(vcpu)) {
enable_all_hw_bp(vcpu);
enable_all_hw_wp(vcpu);
}
if (vcpu->arch.sie_block->gcr[9] & PER_EVENT_NULLIFICATION)
vcpu->arch.sie_block->gcr[9] &= ~PER_EVENT_NULLIFICATION;
}
static int __import_wp_info(struct kvm_vcpu *vcpu,
struct kvm_hw_breakpoint *bp_data,
struct kvm_hw_wp_info_arch *wp_info)
{
int ret = 0;
wp_info->len = bp_data->len;
wp_info->addr = bp_data->addr;
wp_info->phys_addr = bp_data->phys_addr;
wp_info->old_data = NULL;
if (wp_info->len < 0 || wp_info->len > MAX_WP_SIZE)
return -EINVAL;
wp_info->old_data = kmalloc(bp_data->len, GFP_KERNEL);
if (!wp_info->old_data)
return -ENOMEM;
ret = read_guest_abs(vcpu, wp_info->phys_addr, wp_info->old_data,
wp_info->len);
if (ret) {
kfree(wp_info->old_data);
wp_info->old_data = NULL;
}
return ret;
}
int kvm_s390_import_bp_data(struct kvm_vcpu *vcpu,
struct kvm_guest_debug *dbg)
{
int ret = 0, nr_wp = 0, nr_bp = 0, i;
struct kvm_hw_breakpoint *bp_data = NULL;
struct kvm_hw_wp_info_arch *wp_info = NULL;
struct kvm_hw_bp_info_arch *bp_info = NULL;
if (dbg->arch.nr_hw_bp <= 0 || !dbg->arch.hw_bp)
return 0;
else if (dbg->arch.nr_hw_bp > MAX_BP_COUNT)
return -EINVAL;
bp_data = memdup_user(dbg->arch.hw_bp,
sizeof(*bp_data) * dbg->arch.nr_hw_bp);
if (IS_ERR(bp_data))
return PTR_ERR(bp_data);
for (i = 0; i < dbg->arch.nr_hw_bp; i++) {
switch (bp_data[i].type) {
case KVM_HW_WP_WRITE:
nr_wp++;
break;
case KVM_HW_BP:
nr_bp++;
break;
default:
break;
}
}
if (nr_wp > 0) {
wp_info = kmalloc_array(nr_wp,
sizeof(*wp_info),
GFP_KERNEL);
if (!wp_info) {
ret = -ENOMEM;
goto error;
}
}
if (nr_bp > 0) {
bp_info = kmalloc_array(nr_bp,
sizeof(*bp_info),
GFP_KERNEL);
if (!bp_info) {
ret = -ENOMEM;
goto error;
}
}
for (nr_wp = 0, nr_bp = 0, i = 0; i < dbg->arch.nr_hw_bp; i++) {
switch (bp_data[i].type) {
case KVM_HW_WP_WRITE:
ret = __import_wp_info(vcpu, &bp_data[i],
&wp_info[nr_wp]);
if (ret)
goto error;
nr_wp++;
break;
case KVM_HW_BP:
bp_info[nr_bp].len = bp_data[i].len;
bp_info[nr_bp].addr = bp_data[i].addr;
nr_bp++;
break;
}
}
vcpu->arch.guestdbg.nr_hw_bp = nr_bp;
vcpu->arch.guestdbg.hw_bp_info = bp_info;
vcpu->arch.guestdbg.nr_hw_wp = nr_wp;
vcpu->arch.guestdbg.hw_wp_info = wp_info;
return 0;
error:
kfree(bp_data);
kfree(wp_info);
kfree(bp_info);
return ret;
}
void kvm_s390_clear_bp_data(struct kvm_vcpu *vcpu)
{
int i;
struct kvm_hw_wp_info_arch *hw_wp_info = NULL;
for (i = 0; i < vcpu->arch.guestdbg.nr_hw_wp; i++) {
hw_wp_info = &vcpu->arch.guestdbg.hw_wp_info[i];
kfree(hw_wp_info->old_data);
hw_wp_info->old_data = NULL;
}
kfree(vcpu->arch.guestdbg.hw_wp_info);
vcpu->arch.guestdbg.hw_wp_info = NULL;
kfree(vcpu->arch.guestdbg.hw_bp_info);
vcpu->arch.guestdbg.hw_bp_info = NULL;
vcpu->arch.guestdbg.nr_hw_wp = 0;
vcpu->arch.guestdbg.nr_hw_bp = 0;
}
static inline int in_addr_range(u64 addr, u64 a, u64 b)
{
if (a <= b)
return (addr >= a) && (addr <= b);
else
return (addr <= a) && (addr >= b);
}
static struct kvm_hw_bp_info_arch *find_hw_bp(struct kvm_vcpu *vcpu,
unsigned long addr)
{
struct kvm_hw_bp_info_arch *bp_info = vcpu->arch.guestdbg.hw_bp_info;
int i;
if (vcpu->arch.guestdbg.nr_hw_bp == 0)
return NULL;
for (i = 0; i < vcpu->arch.guestdbg.nr_hw_bp; i++) {
if (addr == bp_info->addr)
goto found;
if (bp_info->len > 0 &&
in_addr_range(addr, bp_info->addr, end_of_range(bp_info)))
goto found;
bp_info++;
}
return NULL;
found:
return bp_info;
}
static struct kvm_hw_wp_info_arch *any_wp_changed(struct kvm_vcpu *vcpu)
{
int i;
struct kvm_hw_wp_info_arch *wp_info = NULL;
void *temp = NULL;
if (vcpu->arch.guestdbg.nr_hw_wp == 0)
return NULL;
for (i = 0; i < vcpu->arch.guestdbg.nr_hw_wp; i++) {
wp_info = &vcpu->arch.guestdbg.hw_wp_info[i];
if (!wp_info || !wp_info->old_data || wp_info->len <= 0)
continue;
temp = kmalloc(wp_info->len, GFP_KERNEL);
if (!temp)
continue;
if (!read_guest_abs(vcpu, wp_info->phys_addr, temp,
wp_info->len)) {
if (memcmp(temp, wp_info->old_data, wp_info->len)) {
kfree(temp);
return wp_info;
}
}
kfree(temp);
temp = NULL;
}
return NULL;
}
void kvm_s390_prepare_debug_exit(struct kvm_vcpu *vcpu)
{
vcpu->run->exit_reason = KVM_EXIT_DEBUG;
vcpu->guest_debug &= ~KVM_GUESTDBG_EXIT_PENDING;
}
static int debug_exit_required(struct kvm_vcpu *vcpu, u8 perc,
unsigned long peraddr)
{
struct kvm_debug_exit_arch *debug_exit = &vcpu->run->debug.arch;
struct kvm_hw_wp_info_arch *wp_info = NULL;
struct kvm_hw_bp_info_arch *bp_info = NULL;
unsigned long addr = vcpu->arch.sie_block->gpsw.addr;
if (guestdbg_hw_bp_enabled(vcpu)) {
if (per_write_wp_event(perc) &&
vcpu->arch.guestdbg.nr_hw_wp > 0) {
wp_info = any_wp_changed(vcpu);
if (wp_info) {
debug_exit->addr = wp_info->addr;
debug_exit->type = KVM_HW_WP_WRITE;
goto exit_required;
}
}
if (per_bp_event(perc) &&
vcpu->arch.guestdbg.nr_hw_bp > 0) {
bp_info = find_hw_bp(vcpu, addr);
if (bp_info && (addr != peraddr)) {
debug_exit->addr = addr;
debug_exit->type = KVM_HW_BP;
vcpu->arch.guestdbg.last_bp = addr;
goto exit_required;
}
bp_info = find_hw_bp(vcpu, peraddr);
if (bp_info && vcpu->arch.guestdbg.last_bp != peraddr) {
debug_exit->addr = peraddr;
debug_exit->type = KVM_HW_BP;
goto exit_required;
}
}
}
if (guestdbg_sstep_enabled(vcpu) && per_bp_event(perc)) {
debug_exit->addr = addr;
debug_exit->type = KVM_SINGLESTEP;
goto exit_required;
}
return 0;
exit_required:
return 1;
}
static int per_fetched_addr(struct kvm_vcpu *vcpu, unsigned long *addr)
{
u8 exec_ilen = 0;
u16 opcode[3];
int rc;
if (vcpu->arch.sie_block->icptcode == ICPT_PROGI) {
*addr = vcpu->arch.sie_block->peraddr;
rc = read_guest_instr(vcpu, *addr, &opcode, 2);
if (rc)
return rc;
if (opcode[0] >> 8 == 0x44)
exec_ilen = 4;
if ((opcode[0] & 0xff0f) == 0xc600)
exec_ilen = 6;
} else {
*addr = __rewind_psw(vcpu->arch.sie_block->gpsw,
kvm_s390_get_ilen(vcpu));
if (vcpu->arch.sie_block->icptstatus & 0x01) {
exec_ilen = (vcpu->arch.sie_block->icptstatus & 0x60) >> 4;
if (!exec_ilen)
exec_ilen = 4;
}
}
if (exec_ilen) {
rc = read_guest_instr(vcpu, *addr, &opcode, exec_ilen);
if (rc)
return rc;
if (exec_ilen == 6) {
s32 rl = *((s32 *) (opcode + 1));
*addr += (u64)(s64) rl * 2;
} else {
u32 base = (opcode[1] & 0xf000) >> 12;
u32 disp = opcode[1] & 0x0fff;
u32 index = opcode[0] & 0x000f;
*addr = base ? vcpu->run->s.regs.gprs[base] : 0;
*addr += index ? vcpu->run->s.regs.gprs[index] : 0;
*addr += disp;
}
*addr = kvm_s390_logical_to_effective(vcpu, *addr);
}
return 0;
}
int kvm_s390_handle_per_ifetch_icpt(struct kvm_vcpu *vcpu)
{
const u64 cr10 = vcpu->arch.sie_block->gcr[10];
const u64 cr11 = vcpu->arch.sie_block->gcr[11];
const u8 ilen = kvm_s390_get_ilen(vcpu);
struct kvm_s390_pgm_info pgm_info = {
.code = PGM_PER,
.per_code = PER_CODE_IFETCH,
.per_address = __rewind_psw(vcpu->arch.sie_block->gpsw, ilen),
};
unsigned long fetched_addr;
int rc;
if (!guestdbg_enabled(vcpu))
return kvm_s390_inject_prog_irq(vcpu, &pgm_info);
if (debug_exit_required(vcpu, pgm_info.per_code, pgm_info.per_address))
vcpu->guest_debug |= KVM_GUESTDBG_EXIT_PENDING;
if (!guest_per_enabled(vcpu) ||
!(vcpu->arch.sie_block->gcr[9] & PER_EVENT_IFETCH))
return 0;
rc = per_fetched_addr(vcpu, &fetched_addr);
if (rc < 0)
return rc;
if (rc)
return kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
if (in_addr_range(fetched_addr, cr10, cr11))
return kvm_s390_inject_prog_irq(vcpu, &pgm_info);
return 0;
}
static int filter_guest_per_event(struct kvm_vcpu *vcpu)
{
const u8 perc = vcpu->arch.sie_block->perc;
u64 addr = vcpu->arch.sie_block->gpsw.addr;
u64 cr9 = vcpu->arch.sie_block->gcr[9];
u64 cr10 = vcpu->arch.sie_block->gcr[10];
u64 cr11 = vcpu->arch.sie_block->gcr[11];
u8 guest_perc = perc & (cr9 >> 24) & PER_CODE_MASK;
unsigned long fetched_addr;
int rc;
if (!guest_per_enabled(vcpu))
guest_perc = 0;
if (guest_perc & PER_CODE_BRANCH &&
cr9 & PER_CONTROL_BRANCH_ADDRESS &&
!in_addr_range(addr, cr10, cr11))
guest_perc &= ~PER_CODE_BRANCH;
if (guest_perc & PER_CODE_IFETCH) {
rc = per_fetched_addr(vcpu, &fetched_addr);
if (rc < 0)
return rc;
if (rc || !in_addr_range(fetched_addr, cr10, cr11))
guest_perc &= ~PER_CODE_IFETCH;
}
vcpu->arch.sie_block->perc = guest_perc;
if (!guest_perc)
vcpu->arch.sie_block->iprcc &= ~PGM_PER;
return 0;
}
int kvm_s390_handle_per_event(struct kvm_vcpu *vcpu)
{
int rc, new_as;
if (debug_exit_required(vcpu, vcpu->arch.sie_block->perc,
vcpu->arch.sie_block->peraddr))
vcpu->guest_debug |= KVM_GUESTDBG_EXIT_PENDING;
rc = filter_guest_per_event(vcpu);
if (rc)
return rc;
if (vcpu->arch.sie_block->iprcc == PGM_SPACE_SWITCH) {
vcpu->arch.sie_block->iprcc = 0;
new_as = psw_bits(vcpu->arch.sie_block->gpsw).as;
if (((new_as == PSW_BITS_AS_HOME) ^ old_as_is_home(vcpu)) &&
(pssec(vcpu) || hssec(vcpu)))
vcpu->arch.sie_block->iprcc = PGM_SPACE_SWITCH;
if (new_as == PSW_BITS_AS_PRIMARY && !old_as_is_home(vcpu) &&
(pssec(vcpu) || old_ssec(vcpu)))
vcpu->arch.sie_block->iprcc = PGM_SPACE_SWITCH;
}
return 0;
}
