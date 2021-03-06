void __init_or_module
paravirt_flush_i_cache_range(const void *instr, unsigned long size)
{
extern void paravirt_fc_i(const void *addr);
unsigned long i;
for (i = 0; i < size; i += sizeof(bundle_t))
paravirt_fc_i(instr + i);
}
bundle_t* __init_or_module
paravirt_get_bundle(unsigned long tag)
{
return (bundle_t *)(tag & ~3UL);
}
unsigned long __init_or_module
paravirt_get_slot(unsigned long tag)
{
return tag & 3UL;
}
unsigned long __init_or_module
paravirt_get_num_inst(unsigned long stag, unsigned long etag)
{
bundle_t *sbundle = paravirt_get_bundle(stag);
unsigned long sslot = paravirt_get_slot(stag);
bundle_t *ebundle = paravirt_get_bundle(etag);
unsigned long eslot = paravirt_get_slot(etag);
return (ebundle - sbundle) * 3 + eslot - sslot + 1;
}
unsigned long __init_or_module
paravirt_get_next_tag(unsigned long tag)
{
unsigned long slot = paravirt_get_slot(tag);
switch (slot) {
case 0:
case 1:
return tag + 1;
case 2: {
bundle_t *bundle = paravirt_get_bundle(tag);
return (unsigned long)(bundle + 1);
}
default:
BUG();
}
}
ia64_inst_t __init_or_module
paravirt_read_slot0(const bundle_t *bundle)
{
ia64_inst_t inst;
inst.l = bundle->quad0.slot0;
return inst;
}
ia64_inst_t __init_or_module
paravirt_read_slot1(const bundle_t *bundle)
{
ia64_inst_t inst;
inst.l = bundle->quad0.slot1_p0 |
((unsigned long long)bundle->quad1.slot1_p1 << 18UL);
return inst;
}
ia64_inst_t __init_or_module
paravirt_read_slot2(const bundle_t *bundle)
{
ia64_inst_t inst;
inst.l = bundle->quad1.slot2;
return inst;
}
ia64_inst_t __init_or_module
paravirt_read_inst(unsigned long tag)
{
bundle_t *bundle = paravirt_get_bundle(tag);
unsigned long slot = paravirt_get_slot(tag);
switch (slot) {
case 0:
return paravirt_read_slot0(bundle);
case 1:
return paravirt_read_slot1(bundle);
case 2:
return paravirt_read_slot2(bundle);
default:
BUG();
}
}
void __init_or_module
paravirt_write_slot0(bundle_t *bundle, ia64_inst_t inst)
{
bundle->quad0.slot0 = inst.l;
}
void __init_or_module
paravirt_write_slot1(bundle_t *bundle, ia64_inst_t inst)
{
bundle->quad0.slot1_p0 = inst.l;
bundle->quad1.slot1_p1 = inst.l >> 18UL;
}
void __init_or_module
paravirt_write_slot2(bundle_t *bundle, ia64_inst_t inst)
{
bundle->quad1.slot2 = inst.l;
}
void __init_or_module
paravirt_write_inst(unsigned long tag, ia64_inst_t inst)
{
bundle_t *bundle = paravirt_get_bundle(tag);
unsigned long slot = paravirt_get_slot(tag);
switch (slot) {
case 0:
paravirt_write_slot0(bundle, inst);
break;
case 1:
paravirt_write_slot1(bundle, inst);
break;
case 2:
paravirt_write_slot2(bundle, inst);
break;
default:
BUG();
break;
}
paravirt_flush_i_cache_range(bundle, sizeof(*bundle));
}
void
paravirt_print_bundle(const bundle_t *bundle)
{
const unsigned long *quad = (const unsigned long *)bundle;
ia64_inst_t slot0 = paravirt_read_slot0(bundle);
ia64_inst_t slot1 = paravirt_read_slot1(bundle);
ia64_inst_t slot2 = paravirt_read_slot2(bundle);
printk(KERN_DEBUG
"bundle 0x%p 0x%016lx 0x%016lx\n", bundle, quad[0], quad[1]);
printk(KERN_DEBUG
"bundle template 0x%x\n",
bundle->quad0.template);
printk(KERN_DEBUG
"slot0 0x%lx slot1_p0 0x%lx slot1_p1 0x%lx slot2 0x%lx\n",
(unsigned long)bundle->quad0.slot0,
(unsigned long)bundle->quad0.slot1_p0,
(unsigned long)bundle->quad1.slot1_p1,
(unsigned long)bundle->quad1.slot2);
printk(KERN_DEBUG
"slot0 0x%016llx slot1 0x%016llx slot2 0x%016llx\n",
slot0.l, slot1.l, slot2.l);
}
static int __init setup_noreplace_paravirt(char *str)
{
noreplace_paravirt = 1;
return 1;
}
static void __init_or_module
fill_nop_bundle(void *sbundle, void *ebundle)
{
extern const char paravirt_nop_bundle[];
extern const unsigned long paravirt_nop_bundle_size;
void *bundle = sbundle;
BUG_ON((((unsigned long)sbundle) % sizeof(bundle_t)) != 0);
BUG_ON((((unsigned long)ebundle) % sizeof(bundle_t)) != 0);
while (bundle < ebundle) {
memcpy(bundle, paravirt_nop_bundle, paravirt_nop_bundle_size);
bundle += paravirt_nop_bundle_size;
}
}
unsigned long __init_or_module
__paravirt_patch_apply_bundle(void *sbundle, void *ebundle, unsigned long type,
const struct paravirt_patch_bundle_elem *elems,
unsigned long nelems,
const struct paravirt_patch_bundle_elem **found)
{
unsigned long used = 0;
unsigned long i;
BUG_ON((((unsigned long)sbundle) % sizeof(bundle_t)) != 0);
BUG_ON((((unsigned long)ebundle) % sizeof(bundle_t)) != 0);
found = NULL;
for (i = 0; i < nelems; i++) {
const struct paravirt_patch_bundle_elem *p = &elems[i];
if (p->type == type) {
unsigned long need = p->ebundle - p->sbundle;
unsigned long room = ebundle - sbundle;
if (found != NULL)
*found = p;
if (room < need) {
printk(KERN_DEBUG
"the space is too small to put "
"bundles. type %ld need %ld room %ld\n",
type, need, room);
break;
}
used = need;
memcpy(sbundle, p->sbundle, used);
break;
}
}
return used;
}
void __init_or_module
paravirt_patch_apply_bundle(const struct paravirt_patch_site_bundle *start,
const struct paravirt_patch_site_bundle *end)
{
const struct paravirt_patch_site_bundle *p;
if (noreplace_paravirt)
return;
if (pv_init_ops.patch_bundle == NULL)
return;
for (p = start; p < end; p++) {
unsigned long used;
used = (*pv_init_ops.patch_bundle)(p->sbundle, p->ebundle,
p->type);
if (used == 0)
continue;
fill_nop_bundle(p->sbundle + used, p->ebundle);
paravirt_flush_i_cache_range(p->sbundle,
p->ebundle - p->sbundle);
}
ia64_sync_i();
ia64_srlz_i();
}
static void __init_or_module
fill_nop_inst(unsigned long stag, unsigned long etag)
{
extern const bundle_t paravirt_nop_mfi_inst_bundle[];
unsigned long tag;
const ia64_inst_t nop_inst =
paravirt_read_slot0(paravirt_nop_mfi_inst_bundle);
for (tag = stag; tag < etag; tag = paravirt_get_next_tag(tag))
paravirt_write_inst(tag, nop_inst);
}
void __init_or_module
paravirt_patch_apply_inst(const struct paravirt_patch_site_inst *start,
const struct paravirt_patch_site_inst *end)
{
const struct paravirt_patch_site_inst *p;
if (noreplace_paravirt)
return;
if (pv_init_ops.patch_inst == NULL)
return;
for (p = start; p < end; p++) {
unsigned long tag;
bundle_t *sbundle;
bundle_t *ebundle;
tag = (*pv_init_ops.patch_inst)(p->stag, p->etag, p->type);
if (tag == p->stag)
continue;
fill_nop_inst(tag, p->etag);
sbundle = paravirt_get_bundle(p->stag);
ebundle = paravirt_get_bundle(p->etag) + 1;
paravirt_flush_i_cache_range(sbundle, (ebundle - sbundle) *
sizeof(bundle_t));
}
ia64_sync_i();
ia64_srlz_i();
}
void __init_or_module
paravirt_patch_reloc_brl(unsigned long tag, const void *target)
{
unsigned long tag_op = paravirt_get_next_tag(tag);
unsigned long tag_imm = tag;
bundle_t *bundle = paravirt_get_bundle(tag);
ia64_inst_t inst_op = paravirt_read_inst(tag_op);
ia64_inst_t inst_imm = paravirt_read_inst(tag_imm);
inst_x3_op_t inst_x3_op = { .l = inst_op.l };
inst_x3_imm_t inst_x3_imm = { .l = inst_imm.l };
unsigned long imm60 =
((unsigned long)target - (unsigned long)bundle) >> 4;
BUG_ON(paravirt_get_slot(tag) != 1);
BUG_ON(((unsigned long)target & (sizeof(bundle_t) - 1)) != 0);
inst_x3_op.i = (imm60 >> 59) & 1;
inst_x3_op.imm20b = imm60 & ((1UL << 20) - 1);
inst_x3_imm.imm39 = (imm60 >> 20) & ((1UL << 39) - 1);
inst_op.l = inst_x3_op.l;
inst_imm.l = inst_x3_imm.l;
paravirt_write_inst(tag_op, inst_op);
paravirt_write_inst(tag_imm, inst_imm);
}
void __init
paravirt_patch_reloc_br(unsigned long tag, const void *target)
{
bundle_t *bundle = paravirt_get_bundle(tag);
ia64_inst_t inst = paravirt_read_inst(tag);
unsigned long target25 = (unsigned long)target - (unsigned long)bundle;
inst_b1_t inst_b1;
BUG_ON(((unsigned long)target & (sizeof(bundle_t) - 1)) != 0);
inst_b1.l = inst.l;
if (target25 & (1UL << 63))
inst_b1.s = 1;
else
inst_b1.s = 0;
inst_b1.imm20b = target25 >> 4;
inst.l = inst_b1.l;
paravirt_write_inst(tag, inst);
}
void __init
__paravirt_patch_apply_branch(
unsigned long tag, unsigned long type,
const struct paravirt_patch_branch_target *entries,
unsigned int nr_entries)
{
unsigned int i;
for (i = 0; i < nr_entries; i++) {
if (entries[i].type == type) {
paravirt_patch_reloc_br(tag, entries[i].entry);
break;
}
}
}
static void __init
paravirt_patch_apply_branch(const struct paravirt_patch_site_branch *start,
const struct paravirt_patch_site_branch *end)
{
const struct paravirt_patch_site_branch *p;
if (noreplace_paravirt)
return;
if (pv_init_ops.patch_branch == NULL)
return;
for (p = start; p < end; p++)
(*pv_init_ops.patch_branch)(p->tag, p->type);
ia64_sync_i();
ia64_srlz_i();
}
void __init
paravirt_patch_apply(void)
{
extern const char __start_paravirt_bundles[];
extern const char __stop_paravirt_bundles[];
extern const char __start_paravirt_insts[];
extern const char __stop_paravirt_insts[];
extern const char __start_paravirt_branches[];
extern const char __stop_paravirt_branches[];
paravirt_patch_apply_bundle((const struct paravirt_patch_site_bundle *)
__start_paravirt_bundles,
(const struct paravirt_patch_site_bundle *)
__stop_paravirt_bundles);
paravirt_patch_apply_inst((const struct paravirt_patch_site_inst *)
__start_paravirt_insts,
(const struct paravirt_patch_site_inst *)
__stop_paravirt_insts);
paravirt_patch_apply_branch((const struct paravirt_patch_site_branch *)
__start_paravirt_branches,
(const struct paravirt_patch_site_branch *)
__stop_paravirt_branches);
}
