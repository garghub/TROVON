const char *smca_get_name(enum smca_bank_types t)
{
if (t >= N_SMCA_BANK_TYPES)
return NULL;
return smca_names[t].name;
}
const char *smca_get_long_name(enum smca_bank_types t)
{
if (t >= N_SMCA_BANK_TYPES)
return NULL;
return smca_names[t].long_name;
}
static void default_deferred_error_interrupt(void)
{
pr_err("Unexpected deferred interrupt at vector %x\n", DEFERRED_ERROR_VECTOR);
}
static void get_smca_bank_info(unsigned int bank)
{
unsigned int i, hwid_mcatype, cpu = smp_processor_id();
struct smca_hwid *s_hwid;
u32 high, instance_id;
if (cpu)
return;
if (rdmsr_safe_on_cpu(cpu, MSR_AMD64_SMCA_MCx_IPID(bank), &instance_id, &high)) {
pr_warn("Failed to read MCA_IPID for bank %d\n", bank);
return;
}
hwid_mcatype = HWID_MCATYPE(high & MCI_IPID_HWID,
(high & MCI_IPID_MCATYPE) >> 16);
for (i = 0; i < ARRAY_SIZE(smca_hwid_mcatypes); i++) {
s_hwid = &smca_hwid_mcatypes[i];
if (hwid_mcatype == s_hwid->hwid_mcatype) {
WARN(smca_banks[bank].hwid,
"Bank %s already initialized!\n",
smca_get_name(s_hwid->bank_type));
smca_banks[bank].hwid = s_hwid;
smca_banks[bank].id = instance_id;
break;
}
}
}
static inline bool is_shared_bank(int bank)
{
if (mce_flags.smca)
return false;
return (bank == 4);
}
static const char *bank4_names(const struct threshold_block *b)
{
switch (b->address) {
case 0x00000413:
return "dram";
case 0xc0000408:
return "ht_links";
case 0xc0000409:
return "l3_cache";
default:
WARN(1, "Funny MSR: 0x%08x\n", b->address);
return "";
}
}
static bool lvt_interrupt_supported(unsigned int bank, u32 msr_high_bits)
{
if (bank == 4)
return true;
return msr_high_bits & BIT(28);
}
static int lvt_off_valid(struct threshold_block *b, int apic, u32 lo, u32 hi)
{
int msr = (hi & MASK_LVTOFF_HI) >> 20;
if (apic < 0) {
pr_err(FW_BUG "cpu %d, failed to setup threshold interrupt "
"for bank %d, block %d (MSR%08X=0x%x%08x)\n", b->cpu,
b->bank, b->block, b->address, hi, lo);
return 0;
}
if (apic != msr) {
if (mce_flags.smca)
return 0;
pr_err(FW_BUG "cpu %d, invalid threshold interrupt offset %d "
"for bank %d, block %d (MSR%08X=0x%x%08x)\n",
b->cpu, apic, b->bank, b->block, b->address, hi, lo);
return 0;
}
return 1;
}
static void threshold_restart_bank(void *_tr)
{
struct thresh_restart *tr = _tr;
u32 hi, lo;
rdmsr(tr->b->address, lo, hi);
if (tr->b->threshold_limit < (hi & THRESHOLD_MAX))
tr->reset = 1;
if (tr->reset) {
hi =
(hi & ~(MASK_ERR_COUNT_HI | MASK_OVERFLOW_HI)) |
(THRESHOLD_MAX - tr->b->threshold_limit);
} else if (tr->old_limit) {
int new_count = (hi & THRESHOLD_MAX) +
(tr->old_limit - tr->b->threshold_limit);
hi = (hi & ~MASK_ERR_COUNT_HI) |
(new_count & THRESHOLD_MAX);
}
hi &= ~MASK_INT_TYPE_HI;
if (!tr->b->interrupt_capable)
goto done;
if (tr->set_lvt_off) {
if (lvt_off_valid(tr->b, tr->lvt_off, lo, hi)) {
hi &= ~MASK_LVTOFF_HI;
hi |= tr->lvt_off << 20;
}
}
if (tr->b->interrupt_enable)
hi |= INT_TYPE_APIC;
done:
hi |= MASK_COUNT_EN_HI;
wrmsr(tr->b->address, lo, hi);
}
static void mce_threshold_block_init(struct threshold_block *b, int offset)
{
struct thresh_restart tr = {
.b = b,
.set_lvt_off = 1,
.lvt_off = offset,
};
b->threshold_limit = THRESHOLD_MAX;
threshold_restart_bank(&tr);
}
static int setup_APIC_mce_threshold(int reserved, int new)
{
if (reserved < 0 && !setup_APIC_eilvt(new, THRESHOLD_APIC_VECTOR,
APIC_EILVT_MSG_FIX, 0))
return new;
return reserved;
}
static int setup_APIC_deferred_error(int reserved, int new)
{
if (reserved < 0 && !setup_APIC_eilvt(new, DEFERRED_ERROR_VECTOR,
APIC_EILVT_MSG_FIX, 0))
return new;
return reserved;
}
static void deferred_error_interrupt_enable(struct cpuinfo_x86 *c)
{
u32 low = 0, high = 0;
int def_offset = -1, def_new;
if (rdmsr_safe(MSR_CU_DEF_ERR, &low, &high))
return;
def_new = (low & MASK_DEF_LVTOFF) >> 4;
if (!(low & MASK_DEF_LVTOFF)) {
pr_err(FW_BUG "Your BIOS is not setting up LVT offset 0x2 for deferred error IRQs correctly.\n");
def_new = DEF_LVT_OFF;
low = (low & ~MASK_DEF_LVTOFF) | (DEF_LVT_OFF << 4);
}
def_offset = setup_APIC_deferred_error(def_offset, def_new);
if ((def_offset == def_new) &&
(deferred_error_int_vector != amd_deferred_error_interrupt))
deferred_error_int_vector = amd_deferred_error_interrupt;
low = (low & ~MASK_DEF_INT_TYPE) | DEF_INT_TYPE_APIC;
wrmsr(MSR_CU_DEF_ERR, low, high);
}
static u32 get_block_address(unsigned int cpu, u32 current_addr, u32 low, u32 high,
unsigned int bank, unsigned int block)
{
u32 addr = 0, offset = 0;
if (mce_flags.smca) {
if (!block) {
addr = MSR_AMD64_SMCA_MCx_MISC(bank);
} else {
u32 low, high;
if (rdmsr_safe_on_cpu(cpu, MSR_AMD64_SMCA_MCx_CONFIG(bank), &low, &high))
return addr;
if (!(low & MCI_CONFIG_MCAX))
return addr;
if (!rdmsr_safe_on_cpu(cpu, MSR_AMD64_SMCA_MCx_MISC(bank), &low, &high) &&
(low & MASK_BLKPTR_LO))
addr = MSR_AMD64_SMCA_MCx_MISCy(bank, block - 1);
}
return addr;
}
switch (block) {
case 0:
addr = msr_ops.misc(bank);
break;
case 1:
offset = ((low & MASK_BLKPTR_LO) >> 21);
if (offset)
addr = MCG_XBLK_ADDR + offset;
break;
default:
addr = ++current_addr;
}
return addr;
}
static int
prepare_threshold_block(unsigned int bank, unsigned int block, u32 addr,
int offset, u32 misc_high)
{
unsigned int cpu = smp_processor_id();
u32 smca_low, smca_high, smca_addr;
struct threshold_block b;
int new;
if (!block)
per_cpu(bank_map, cpu) |= (1 << bank);
memset(&b, 0, sizeof(b));
b.cpu = cpu;
b.bank = bank;
b.block = block;
b.address = addr;
b.interrupt_capable = lvt_interrupt_supported(bank, misc_high);
if (!b.interrupt_capable)
goto done;
b.interrupt_enable = 1;
if (!mce_flags.smca) {
new = (misc_high & MASK_LVTOFF_HI) >> 20;
goto set_offset;
}
smca_addr = MSR_AMD64_SMCA_MCx_CONFIG(bank);
if (!rdmsr_safe(smca_addr, &smca_low, &smca_high)) {
smca_high |= BIT(0);
smca_high &= ~BIT(2);
if ((smca_low & BIT(5)) && !((smca_high >> 5) & 0x3))
smca_high |= BIT(5);
wrmsr(smca_addr, smca_low, smca_high);
}
if (rdmsr_safe(MSR_CU_DEF_ERR, &smca_low, &smca_high))
goto out;
new = (smca_low & SMCA_THR_LVT_OFF) >> 12;
set_offset:
offset = setup_APIC_mce_threshold(offset, new);
if ((offset == new) && (mce_threshold_vector != amd_threshold_interrupt))
mce_threshold_vector = amd_threshold_interrupt;
done:
mce_threshold_block_init(&b, offset);
out:
return offset;
}
void mce_amd_feature_init(struct cpuinfo_x86 *c)
{
u32 low = 0, high = 0, address = 0;
unsigned int bank, block, cpu = smp_processor_id();
int offset = -1;
for (bank = 0; bank < mca_cfg.banks; ++bank) {
if (mce_flags.smca)
get_smca_bank_info(bank);
for (block = 0; block < NR_BLOCKS; ++block) {
address = get_block_address(cpu, address, low, high, bank, block);
if (!address)
break;
if (rdmsr_safe(address, &low, &high))
break;
if (!(high & MASK_VALID_HI))
continue;
if (!(high & MASK_CNTP_HI) ||
(high & MASK_LOCKED_HI))
continue;
offset = prepare_threshold_block(bank, block, address, offset, high);
}
}
if (mce_flags.succor)
deferred_error_interrupt_enable(c);
}
int umc_normaddr_to_sysaddr(u64 norm_addr, u16 nid, u8 umc, u64 *sys_addr)
{
u64 dram_base_addr, dram_limit_addr, dram_hole_base;
u64 ret_addr = norm_addr;
u32 tmp;
u8 die_id_shift, die_id_mask, socket_id_shift, socket_id_mask;
u8 intlv_num_dies, intlv_num_chan, intlv_num_sockets;
u8 intlv_addr_sel, intlv_addr_bit;
u8 num_intlv_bits, hashed_bit;
u8 lgcy_mmio_hole_en, base = 0;
u8 cs_mask, cs_id = 0;
bool hash_enabled = false;
if (amd_df_indirect_read(nid, 0, 0x1B4, umc, &tmp))
goto out_err;
if (tmp & BIT(0)) {
u64 hi_addr_offset = (tmp & GENMASK_ULL(31, 20)) << 8;
if (norm_addr >= hi_addr_offset) {
ret_addr -= hi_addr_offset;
base = 1;
}
}
if (amd_df_indirect_read(nid, 0, 0x110 + (8 * base), umc, &tmp))
goto out_err;
if (!(tmp & BIT(0))) {
pr_err("%s: Invalid DramBaseAddress range: 0x%x.\n",
__func__, tmp);
goto out_err;
}
lgcy_mmio_hole_en = tmp & BIT(1);
intlv_num_chan = (tmp >> 4) & 0xF;
intlv_addr_sel = (tmp >> 8) & 0x7;
dram_base_addr = (tmp & GENMASK_ULL(31, 12)) << 16;
if (intlv_addr_sel > 3) {
pr_err("%s: Invalid interleave address select %d.\n",
__func__, intlv_addr_sel);
goto out_err;
}
if (amd_df_indirect_read(nid, 0, 0x114 + (8 * base), umc, &tmp))
goto out_err;
intlv_num_sockets = (tmp >> 8) & 0x1;
intlv_num_dies = (tmp >> 10) & 0x3;
dram_limit_addr = ((tmp & GENMASK_ULL(31, 12)) << 16) | GENMASK_ULL(27, 0);
intlv_addr_bit = intlv_addr_sel + 8;
switch (intlv_num_chan) {
case 0: intlv_num_chan = 0; break;
case 1: intlv_num_chan = 1; break;
case 3: intlv_num_chan = 2; break;
case 5: intlv_num_chan = 3; break;
case 7: intlv_num_chan = 4; break;
case 8: intlv_num_chan = 1;
hash_enabled = true;
break;
default:
pr_err("%s: Invalid number of interleaved channels %d.\n",
__func__, intlv_num_chan);
goto out_err;
}
num_intlv_bits = intlv_num_chan;
if (intlv_num_dies > 2) {
pr_err("%s: Invalid number of interleaved nodes/dies %d.\n",
__func__, intlv_num_dies);
goto out_err;
}
num_intlv_bits += intlv_num_dies;
num_intlv_bits += intlv_num_sockets;
if (num_intlv_bits > 4) {
pr_err("%s: Invalid interleave bits %d.\n",
__func__, num_intlv_bits);
goto out_err;
}
if (num_intlv_bits > 0) {
u64 temp_addr_x, temp_addr_i, temp_addr_y;
u8 die_id_bit, sock_id_bit, cs_fabric_id;
if (amd_df_indirect_read(nid, 0, 0x50, umc, &tmp))
goto out_err;
cs_fabric_id = (tmp >> 8) & 0xFF;
die_id_bit = 0;
if (intlv_num_chan) {
die_id_bit = intlv_num_chan;
cs_mask = (1 << die_id_bit) - 1;
cs_id = cs_fabric_id & cs_mask;
}
sock_id_bit = die_id_bit;
if (intlv_num_dies || intlv_num_sockets)
if (amd_df_indirect_read(nid, 1, 0x208, umc, &tmp))
goto out_err;
if (intlv_num_dies) {
sock_id_bit = die_id_bit + intlv_num_dies;
die_id_shift = (tmp >> 24) & 0xF;
die_id_mask = (tmp >> 8) & 0xFF;
cs_id |= ((cs_fabric_id & die_id_mask) >> die_id_shift) << die_id_bit;
}
if (intlv_num_sockets) {
socket_id_shift = (tmp >> 28) & 0xF;
socket_id_mask = (tmp >> 16) & 0xFF;
cs_id |= ((cs_fabric_id & socket_id_mask) >> socket_id_shift) << sock_id_bit;
}
temp_addr_y = ret_addr & GENMASK_ULL(intlv_addr_bit-1, 0);
temp_addr_i = (cs_id << intlv_addr_bit);
temp_addr_x = (ret_addr & GENMASK_ULL(63, intlv_addr_bit)) << num_intlv_bits;
ret_addr = temp_addr_x | temp_addr_i | temp_addr_y;
}
ret_addr += dram_base_addr;
if (lgcy_mmio_hole_en) {
if (amd_df_indirect_read(nid, 0, 0x104, umc, &tmp))
goto out_err;
dram_hole_base = tmp & GENMASK(31, 24);
if (ret_addr >= dram_hole_base)
ret_addr += (BIT_ULL(32) - dram_hole_base);
}
if (hash_enabled) {
hashed_bit = (ret_addr >> 12) ^
(ret_addr >> 18) ^
(ret_addr >> 21) ^
(ret_addr >> 30) ^
cs_id;
hashed_bit &= BIT(0);
if (hashed_bit != ((ret_addr >> intlv_addr_bit) & BIT(0)))
ret_addr ^= BIT(intlv_addr_bit);
}
if (ret_addr > dram_limit_addr)
goto out_err;
*sys_addr = ret_addr;
return 0;
out_err:
return -EINVAL;
}
static void
__log_error(unsigned int bank, bool deferred_err, bool threshold_err, u64 misc)
{
u32 msr_status = msr_ops.status(bank);
u32 msr_addr = msr_ops.addr(bank);
struct mce m;
u64 status;
WARN_ON_ONCE(deferred_err && threshold_err);
if (deferred_err && mce_flags.smca) {
msr_status = MSR_AMD64_SMCA_MCx_DESTAT(bank);
msr_addr = MSR_AMD64_SMCA_MCx_DEADDR(bank);
}
rdmsrl(msr_status, status);
if (!(status & MCI_STATUS_VAL))
return;
mce_setup(&m);
m.status = status;
m.bank = bank;
if (threshold_err)
m.misc = misc;
if (m.status & MCI_STATUS_ADDRV) {
rdmsrl(msr_addr, m.addr);
if (mce_flags.smca) {
u8 lsb = (m.addr >> 56) & 0x3f;
m.addr &= GENMASK_ULL(55, lsb);
}
}
if (mce_flags.smca) {
rdmsrl(MSR_AMD64_SMCA_MCx_IPID(bank), m.ipid);
if (m.status & MCI_STATUS_SYNDV)
rdmsrl(MSR_AMD64_SMCA_MCx_SYND(bank), m.synd);
}
mce_log(&m);
wrmsrl(msr_status, 0);
}
static inline void __smp_deferred_error_interrupt(void)
{
inc_irq_stat(irq_deferred_error_count);
deferred_error_int_vector();
}
asmlinkage __visible void smp_deferred_error_interrupt(void)
{
entering_irq();
__smp_deferred_error_interrupt();
exiting_ack_irq();
}
asmlinkage __visible void smp_trace_deferred_error_interrupt(void)
{
entering_irq();
trace_deferred_error_apic_entry(DEFERRED_ERROR_VECTOR);
__smp_deferred_error_interrupt();
trace_deferred_error_apic_exit(DEFERRED_ERROR_VECTOR);
exiting_ack_irq();
}
static void amd_deferred_error_interrupt(void)
{
unsigned int bank;
u32 msr_status;
u64 status;
for (bank = 0; bank < mca_cfg.banks; ++bank) {
msr_status = (mce_flags.smca) ? MSR_AMD64_SMCA_MCx_DESTAT(bank)
: msr_ops.status(bank);
rdmsrl(msr_status, status);
if (!(status & MCI_STATUS_VAL) ||
!(status & MCI_STATUS_DEFERRED))
continue;
__log_error(bank, true, false, 0);
break;
}
}
static void amd_threshold_interrupt(void)
{
u32 low = 0, high = 0, address = 0;
unsigned int bank, block, cpu = smp_processor_id();
struct thresh_restart tr;
for (bank = 0; bank < mca_cfg.banks; ++bank) {
if (!(per_cpu(bank_map, cpu) & (1 << bank)))
continue;
for (block = 0; block < NR_BLOCKS; ++block) {
address = get_block_address(cpu, address, low, high, bank, block);
if (!address)
break;
if (rdmsr_safe(address, &low, &high))
break;
if (!(high & MASK_VALID_HI)) {
if (block)
continue;
else
break;
}
if (!(high & MASK_CNTP_HI) ||
(high & MASK_LOCKED_HI))
continue;
if (high & MASK_OVERFLOW_HI)
goto log;
}
}
return;
log:
__log_error(bank, false, true, ((u64)high << 32) | low);
memset(&tr, 0, sizeof(tr));
tr.b = &per_cpu(threshold_banks, cpu)[bank]->blocks[block];
threshold_restart_bank(&tr);
}
static ssize_t
store_interrupt_enable(struct threshold_block *b, const char *buf, size_t size)
{
struct thresh_restart tr;
unsigned long new;
if (!b->interrupt_capable)
return -EINVAL;
if (kstrtoul(buf, 0, &new) < 0)
return -EINVAL;
b->interrupt_enable = !!new;
memset(&tr, 0, sizeof(tr));
tr.b = b;
smp_call_function_single(b->cpu, threshold_restart_bank, &tr, 1);
return size;
}
static ssize_t
store_threshold_limit(struct threshold_block *b, const char *buf, size_t size)
{
struct thresh_restart tr;
unsigned long new;
if (kstrtoul(buf, 0, &new) < 0)
return -EINVAL;
if (new > THRESHOLD_MAX)
new = THRESHOLD_MAX;
if (new < 1)
new = 1;
memset(&tr, 0, sizeof(tr));
tr.old_limit = b->threshold_limit;
b->threshold_limit = new;
tr.b = b;
smp_call_function_single(b->cpu, threshold_restart_bank, &tr, 1);
return size;
}
static ssize_t show_error_count(struct threshold_block *b, char *buf)
{
u32 lo, hi;
rdmsr_on_cpu(b->cpu, b->address, &lo, &hi);
return sprintf(buf, "%u\n", ((hi & THRESHOLD_MAX) -
(THRESHOLD_MAX - b->threshold_limit)));
}
static ssize_t show(struct kobject *kobj, struct attribute *attr, char *buf)
{
struct threshold_block *b = to_block(kobj);
struct threshold_attr *a = to_attr(attr);
ssize_t ret;
ret = a->show ? a->show(b, buf) : -EIO;
return ret;
}
static ssize_t store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct threshold_block *b = to_block(kobj);
struct threshold_attr *a = to_attr(attr);
ssize_t ret;
ret = a->store ? a->store(b, buf, count) : -EIO;
return ret;
}
static const char *get_name(unsigned int bank, struct threshold_block *b)
{
unsigned int bank_type;
if (!mce_flags.smca) {
if (b && bank == 4)
return bank4_names(b);
return th_names[bank];
}
if (!smca_banks[bank].hwid)
return NULL;
bank_type = smca_banks[bank].hwid->bank_type;
if (b && bank_type == SMCA_UMC) {
if (b->block < ARRAY_SIZE(smca_umc_block_names))
return smca_umc_block_names[b->block];
return NULL;
}
snprintf(buf_mcatype, MAX_MCATYPE_NAME_LEN,
"%s_%x", smca_get_name(bank_type),
smca_banks[bank].id);
return buf_mcatype;
}
static int allocate_threshold_blocks(unsigned int cpu, unsigned int bank,
unsigned int block, u32 address)
{
struct threshold_block *b = NULL;
u32 low, high;
int err;
if ((bank >= mca_cfg.banks) || (block >= NR_BLOCKS))
return 0;
if (rdmsr_safe_on_cpu(cpu, address, &low, &high))
return 0;
if (!(high & MASK_VALID_HI)) {
if (block)
goto recurse;
else
return 0;
}
if (!(high & MASK_CNTP_HI) ||
(high & MASK_LOCKED_HI))
goto recurse;
b = kzalloc(sizeof(struct threshold_block), GFP_KERNEL);
if (!b)
return -ENOMEM;
b->block = block;
b->bank = bank;
b->cpu = cpu;
b->address = address;
b->interrupt_enable = 0;
b->interrupt_capable = lvt_interrupt_supported(bank, high);
b->threshold_limit = THRESHOLD_MAX;
if (b->interrupt_capable) {
threshold_ktype.default_attrs[2] = &interrupt_enable.attr;
b->interrupt_enable = 1;
} else {
threshold_ktype.default_attrs[2] = NULL;
}
INIT_LIST_HEAD(&b->miscj);
if (per_cpu(threshold_banks, cpu)[bank]->blocks) {
list_add(&b->miscj,
&per_cpu(threshold_banks, cpu)[bank]->blocks->miscj);
} else {
per_cpu(threshold_banks, cpu)[bank]->blocks = b;
}
err = kobject_init_and_add(&b->kobj, &threshold_ktype,
per_cpu(threshold_banks, cpu)[bank]->kobj,
get_name(bank, b));
if (err)
goto out_free;
recurse:
address = get_block_address(cpu, address, low, high, bank, ++block);
if (!address)
return 0;
err = allocate_threshold_blocks(cpu, bank, block, address);
if (err)
goto out_free;
if (b)
kobject_uevent(&b->kobj, KOBJ_ADD);
return err;
out_free:
if (b) {
kobject_put(&b->kobj);
list_del(&b->miscj);
kfree(b);
}
return err;
}
static int __threshold_add_blocks(struct threshold_bank *b)
{
struct list_head *head = &b->blocks->miscj;
struct threshold_block *pos = NULL;
struct threshold_block *tmp = NULL;
int err = 0;
err = kobject_add(&b->blocks->kobj, b->kobj, b->blocks->kobj.name);
if (err)
return err;
list_for_each_entry_safe(pos, tmp, head, miscj) {
err = kobject_add(&pos->kobj, b->kobj, pos->kobj.name);
if (err) {
list_for_each_entry_safe_reverse(pos, tmp, head, miscj)
kobject_del(&pos->kobj);
return err;
}
}
return err;
}
static int threshold_create_bank(unsigned int cpu, unsigned int bank)
{
struct device *dev = per_cpu(mce_device, cpu);
struct amd_northbridge *nb = NULL;
struct threshold_bank *b = NULL;
const char *name = get_name(bank, NULL);
int err = 0;
if (!dev)
return -ENODEV;
if (is_shared_bank(bank)) {
nb = node_to_amd_nb(amd_get_nb_id(cpu));
if (nb && nb->bank4) {
b = nb->bank4;
err = kobject_add(b->kobj, &dev->kobj, name);
if (err)
goto out;
per_cpu(threshold_banks, cpu)[bank] = b;
atomic_inc(&b->cpus);
err = __threshold_add_blocks(b);
goto out;
}
}
b = kzalloc(sizeof(struct threshold_bank), GFP_KERNEL);
if (!b) {
err = -ENOMEM;
goto out;
}
b->kobj = kobject_create_and_add(name, &dev->kobj);
if (!b->kobj) {
err = -EINVAL;
goto out_free;
}
per_cpu(threshold_banks, cpu)[bank] = b;
if (is_shared_bank(bank)) {
atomic_set(&b->cpus, 1);
if (nb) {
WARN_ON(nb->bank4);
nb->bank4 = b;
}
}
err = allocate_threshold_blocks(cpu, bank, 0, msr_ops.misc(bank));
if (!err)
goto out;
out_free:
kfree(b);
out:
return err;
}
static void deallocate_threshold_block(unsigned int cpu,
unsigned int bank)
{
struct threshold_block *pos = NULL;
struct threshold_block *tmp = NULL;
struct threshold_bank *head = per_cpu(threshold_banks, cpu)[bank];
if (!head)
return;
list_for_each_entry_safe(pos, tmp, &head->blocks->miscj, miscj) {
kobject_put(&pos->kobj);
list_del(&pos->miscj);
kfree(pos);
}
kfree(per_cpu(threshold_banks, cpu)[bank]->blocks);
per_cpu(threshold_banks, cpu)[bank]->blocks = NULL;
}
static void __threshold_remove_blocks(struct threshold_bank *b)
{
struct threshold_block *pos = NULL;
struct threshold_block *tmp = NULL;
kobject_del(b->kobj);
list_for_each_entry_safe(pos, tmp, &b->blocks->miscj, miscj)
kobject_del(&pos->kobj);
}
static void threshold_remove_bank(unsigned int cpu, int bank)
{
struct amd_northbridge *nb;
struct threshold_bank *b;
b = per_cpu(threshold_banks, cpu)[bank];
if (!b)
return;
if (!b->blocks)
goto free_out;
if (is_shared_bank(bank)) {
if (!atomic_dec_and_test(&b->cpus)) {
__threshold_remove_blocks(b);
per_cpu(threshold_banks, cpu)[bank] = NULL;
return;
} else {
nb = node_to_amd_nb(amd_get_nb_id(cpu));
nb->bank4 = NULL;
}
}
deallocate_threshold_block(cpu, bank);
free_out:
kobject_del(b->kobj);
kobject_put(b->kobj);
kfree(b);
per_cpu(threshold_banks, cpu)[bank] = NULL;
}
int mce_threshold_remove_device(unsigned int cpu)
{
unsigned int bank;
if (!thresholding_en)
return 0;
for (bank = 0; bank < mca_cfg.banks; ++bank) {
if (!(per_cpu(bank_map, cpu) & (1 << bank)))
continue;
threshold_remove_bank(cpu, bank);
}
kfree(per_cpu(threshold_banks, cpu));
per_cpu(threshold_banks, cpu) = NULL;
return 0;
}
int mce_threshold_create_device(unsigned int cpu)
{
unsigned int bank;
struct threshold_bank **bp;
int err = 0;
if (!thresholding_en)
return 0;
bp = per_cpu(threshold_banks, cpu);
if (bp)
return 0;
bp = kzalloc(sizeof(struct threshold_bank *) * mca_cfg.banks,
GFP_KERNEL);
if (!bp)
return -ENOMEM;
per_cpu(threshold_banks, cpu) = bp;
for (bank = 0; bank < mca_cfg.banks; ++bank) {
if (!(per_cpu(bank_map, cpu) & (1 << bank)))
continue;
err = threshold_create_bank(cpu, bank);
if (err)
goto err;
}
return err;
err:
mce_threshold_remove_device(cpu);
return err;
}
static __init int threshold_init_device(void)
{
unsigned lcpu = 0;
if (mce_threshold_vector == amd_threshold_interrupt)
thresholding_en = true;
for_each_online_cpu(lcpu) {
int err = mce_threshold_create_device(lcpu);
if (err)
return err;
}
return 0;
}
