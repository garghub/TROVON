int ipte_lock_held(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.sie_block->eca & ECA_SII) {
int rc;
read_lock(&vcpu->kvm->arch.sca_lock);
rc = kvm_s390_get_ipte_control(vcpu->kvm)->kh != 0;
read_unlock(&vcpu->kvm->arch.sca_lock);
return rc;
}
return vcpu->kvm->arch.ipte_lock_count != 0;
}
static void ipte_lock_simple(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
mutex_lock(&vcpu->kvm->arch.ipte_mutex);
vcpu->kvm->arch.ipte_lock_count++;
if (vcpu->kvm->arch.ipte_lock_count > 1)
goto out;
retry:
read_lock(&vcpu->kvm->arch.sca_lock);
ic = kvm_s390_get_ipte_control(vcpu->kvm);
do {
old = READ_ONCE(*ic);
if (old.k) {
read_unlock(&vcpu->kvm->arch.sca_lock);
cond_resched();
goto retry;
}
new = old;
new.k = 1;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
read_unlock(&vcpu->kvm->arch.sca_lock);
out:
mutex_unlock(&vcpu->kvm->arch.ipte_mutex);
}
static void ipte_unlock_simple(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
mutex_lock(&vcpu->kvm->arch.ipte_mutex);
vcpu->kvm->arch.ipte_lock_count--;
if (vcpu->kvm->arch.ipte_lock_count)
goto out;
read_lock(&vcpu->kvm->arch.sca_lock);
ic = kvm_s390_get_ipte_control(vcpu->kvm);
do {
old = READ_ONCE(*ic);
new = old;
new.k = 0;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
read_unlock(&vcpu->kvm->arch.sca_lock);
wake_up(&vcpu->kvm->arch.ipte_wq);
out:
mutex_unlock(&vcpu->kvm->arch.ipte_mutex);
}
static void ipte_lock_siif(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
retry:
read_lock(&vcpu->kvm->arch.sca_lock);
ic = kvm_s390_get_ipte_control(vcpu->kvm);
do {
old = READ_ONCE(*ic);
if (old.kg) {
read_unlock(&vcpu->kvm->arch.sca_lock);
cond_resched();
goto retry;
}
new = old;
new.k = 1;
new.kh++;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
read_unlock(&vcpu->kvm->arch.sca_lock);
}
static void ipte_unlock_siif(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
read_lock(&vcpu->kvm->arch.sca_lock);
ic = kvm_s390_get_ipte_control(vcpu->kvm);
do {
old = READ_ONCE(*ic);
new = old;
new.kh--;
if (!new.kh)
new.k = 0;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
read_unlock(&vcpu->kvm->arch.sca_lock);
if (!new.kh)
wake_up(&vcpu->kvm->arch.ipte_wq);
}
void ipte_lock(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.sie_block->eca & ECA_SII)
ipte_lock_siif(vcpu);
else
ipte_lock_simple(vcpu);
}
void ipte_unlock(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.sie_block->eca & ECA_SII)
ipte_unlock_siif(vcpu);
else
ipte_unlock_simple(vcpu);
}
static int ar_translation(struct kvm_vcpu *vcpu, union asce *asce, u8 ar,
enum gacc_mode mode)
{
union alet alet;
struct ale ale;
struct aste aste;
unsigned long ald_addr, authority_table_addr;
union ald ald;
int eax, rc;
u8 authority_table;
if (ar >= NUM_ACRS)
return -EINVAL;
save_access_regs(vcpu->run->s.regs.acrs);
alet.val = vcpu->run->s.regs.acrs[ar];
if (ar == 0 || alet.val == 0) {
asce->val = vcpu->arch.sie_block->gcr[1];
return 0;
} else if (alet.val == 1) {
asce->val = vcpu->arch.sie_block->gcr[7];
return 0;
}
if (alet.reserved)
return PGM_ALET_SPECIFICATION;
if (alet.p)
ald_addr = vcpu->arch.sie_block->gcr[5];
else
ald_addr = vcpu->arch.sie_block->gcr[2];
ald_addr &= 0x7fffffc0;
rc = read_guest_real(vcpu, ald_addr + 16, &ald.val, sizeof(union ald));
if (rc)
return rc;
if (alet.alen / 8 > ald.all)
return PGM_ALEN_TRANSLATION;
if (0x7fffffff - ald.alo * 128 < alet.alen * 16)
return PGM_ADDRESSING;
rc = read_guest_real(vcpu, ald.alo * 128 + alet.alen * 16, &ale,
sizeof(struct ale));
if (rc)
return rc;
if (ale.i == 1)
return PGM_ALEN_TRANSLATION;
if (ale.alesn != alet.alesn)
return PGM_ALE_SEQUENCE;
rc = read_guest_real(vcpu, ale.asteo * 64, &aste, sizeof(struct aste));
if (rc)
return rc;
if (aste.i)
return PGM_ASTE_VALIDITY;
if (aste.astesn != ale.astesn)
return PGM_ASTE_SEQUENCE;
if (ale.p == 1) {
eax = (vcpu->arch.sie_block->gcr[8] >> 16) & 0xffff;
if (ale.aleax != eax) {
if (eax / 16 > aste.atl)
return PGM_EXTENDED_AUTHORITY;
authority_table_addr = aste.ato * 4 + eax / 4;
rc = read_guest_real(vcpu, authority_table_addr,
&authority_table,
sizeof(u8));
if (rc)
return rc;
if ((authority_table & (0x40 >> ((eax & 3) * 2))) == 0)
return PGM_EXTENDED_AUTHORITY;
}
}
if (ale.fo == 1 && mode == GACC_STORE)
return PGM_PROTECTION;
asce->val = aste.asce;
return 0;
}
static int trans_exc(struct kvm_vcpu *vcpu, int code, unsigned long gva,
u8 ar, enum gacc_mode mode, enum prot_type prot)
{
struct kvm_s390_pgm_info *pgm = &vcpu->arch.pgm;
struct trans_exc_code_bits *tec;
memset(pgm, 0, sizeof(*pgm));
pgm->code = code;
tec = (struct trans_exc_code_bits *)&pgm->trans_exc_code;
switch (code) {
case PGM_PROTECTION:
switch (prot) {
case PROT_TYPE_IEP:
tec->b61 = 1;
case PROT_TYPE_LA:
tec->b56 = 1;
break;
case PROT_TYPE_KEYC:
tec->b60 = 1;
break;
case PROT_TYPE_ALC:
tec->b60 = 1;
case PROT_TYPE_DAT:
tec->b61 = 1;
break;
}
case PGM_ASCE_TYPE:
case PGM_PAGE_TRANSLATION:
case PGM_REGION_FIRST_TRANS:
case PGM_REGION_SECOND_TRANS:
case PGM_REGION_THIRD_TRANS:
case PGM_SEGMENT_TRANSLATION:
tec->addr = gva >> PAGE_SHIFT;
tec->fsi = mode == GACC_STORE ? FSI_STORE : FSI_FETCH;
tec->as = psw_bits(vcpu->arch.sie_block->gpsw).as;
case PGM_ALEN_TRANSLATION:
case PGM_ALE_SEQUENCE:
case PGM_ASTE_VALIDITY:
case PGM_ASTE_SEQUENCE:
case PGM_EXTENDED_AUTHORITY:
pgm->exc_access_id = ar;
break;
}
return code;
}
static int get_vcpu_asce(struct kvm_vcpu *vcpu, union asce *asce,
unsigned long ga, u8 ar, enum gacc_mode mode)
{
int rc;
struct psw_bits psw = psw_bits(vcpu->arch.sie_block->gpsw);
if (!psw.dat) {
asce->val = 0;
asce->r = 1;
return 0;
}
if ((mode == GACC_IFETCH) && (psw.as != PSW_BITS_AS_HOME))
psw.as = PSW_BITS_AS_PRIMARY;
switch (psw.as) {
case PSW_BITS_AS_PRIMARY:
asce->val = vcpu->arch.sie_block->gcr[1];
return 0;
case PSW_BITS_AS_SECONDARY:
asce->val = vcpu->arch.sie_block->gcr[7];
return 0;
case PSW_BITS_AS_HOME:
asce->val = vcpu->arch.sie_block->gcr[13];
return 0;
case PSW_BITS_AS_ACCREG:
rc = ar_translation(vcpu, asce, ar, mode);
if (rc > 0)
return trans_exc(vcpu, rc, ga, ar, mode, PROT_TYPE_ALC);
return rc;
}
return 0;
}
static int deref_table(struct kvm *kvm, unsigned long gpa, unsigned long *val)
{
return kvm_read_guest(kvm, gpa, val, sizeof(*val));
}
static unsigned long guest_translate(struct kvm_vcpu *vcpu, unsigned long gva,
unsigned long *gpa, const union asce asce,
enum gacc_mode mode, enum prot_type *prot)
{
union vaddress vaddr = {.addr = gva};
union raddress raddr = {.addr = gva};
union page_table_entry pte;
int dat_protection = 0;
int iep_protection = 0;
union ctlreg0 ctlreg0;
unsigned long ptr;
int edat1, edat2, iep;
ctlreg0.val = vcpu->arch.sie_block->gcr[0];
edat1 = ctlreg0.edat && test_kvm_facility(vcpu->kvm, 8);
edat2 = edat1 && test_kvm_facility(vcpu->kvm, 78);
iep = ctlreg0.iep && test_kvm_facility(vcpu->kvm, 130);
if (asce.r)
goto real_address;
ptr = asce.origin * PAGE_SIZE;
switch (asce.dt) {
case ASCE_TYPE_REGION1:
if (vaddr.rfx01 > asce.tl)
return PGM_REGION_FIRST_TRANS;
ptr += vaddr.rfx * 8;
break;
case ASCE_TYPE_REGION2:
if (vaddr.rfx)
return PGM_ASCE_TYPE;
if (vaddr.rsx01 > asce.tl)
return PGM_REGION_SECOND_TRANS;
ptr += vaddr.rsx * 8;
break;
case ASCE_TYPE_REGION3:
if (vaddr.rfx || vaddr.rsx)
return PGM_ASCE_TYPE;
if (vaddr.rtx01 > asce.tl)
return PGM_REGION_THIRD_TRANS;
ptr += vaddr.rtx * 8;
break;
case ASCE_TYPE_SEGMENT:
if (vaddr.rfx || vaddr.rsx || vaddr.rtx)
return PGM_ASCE_TYPE;
if (vaddr.sx01 > asce.tl)
return PGM_SEGMENT_TRANSLATION;
ptr += vaddr.sx * 8;
break;
}
switch (asce.dt) {
case ASCE_TYPE_REGION1: {
union region1_table_entry rfte;
if (kvm_is_error_gpa(vcpu->kvm, ptr))
return PGM_ADDRESSING;
if (deref_table(vcpu->kvm, ptr, &rfte.val))
return -EFAULT;
if (rfte.i)
return PGM_REGION_FIRST_TRANS;
if (rfte.tt != TABLE_TYPE_REGION1)
return PGM_TRANSLATION_SPEC;
if (vaddr.rsx01 < rfte.tf || vaddr.rsx01 > rfte.tl)
return PGM_REGION_SECOND_TRANS;
if (edat1)
dat_protection |= rfte.p;
ptr = rfte.rto * PAGE_SIZE + vaddr.rsx * 8;
}
case ASCE_TYPE_REGION2: {
union region2_table_entry rste;
if (kvm_is_error_gpa(vcpu->kvm, ptr))
return PGM_ADDRESSING;
if (deref_table(vcpu->kvm, ptr, &rste.val))
return -EFAULT;
if (rste.i)
return PGM_REGION_SECOND_TRANS;
if (rste.tt != TABLE_TYPE_REGION2)
return PGM_TRANSLATION_SPEC;
if (vaddr.rtx01 < rste.tf || vaddr.rtx01 > rste.tl)
return PGM_REGION_THIRD_TRANS;
if (edat1)
dat_protection |= rste.p;
ptr = rste.rto * PAGE_SIZE + vaddr.rtx * 8;
}
case ASCE_TYPE_REGION3: {
union region3_table_entry rtte;
if (kvm_is_error_gpa(vcpu->kvm, ptr))
return PGM_ADDRESSING;
if (deref_table(vcpu->kvm, ptr, &rtte.val))
return -EFAULT;
if (rtte.i)
return PGM_REGION_THIRD_TRANS;
if (rtte.tt != TABLE_TYPE_REGION3)
return PGM_TRANSLATION_SPEC;
if (rtte.cr && asce.p && edat2)
return PGM_TRANSLATION_SPEC;
if (rtte.fc && edat2) {
dat_protection |= rtte.fc1.p;
iep_protection = rtte.fc1.iep;
raddr.rfaa = rtte.fc1.rfaa;
goto absolute_address;
}
if (vaddr.sx01 < rtte.fc0.tf)
return PGM_SEGMENT_TRANSLATION;
if (vaddr.sx01 > rtte.fc0.tl)
return PGM_SEGMENT_TRANSLATION;
if (edat1)
dat_protection |= rtte.fc0.p;
ptr = rtte.fc0.sto * PAGE_SIZE + vaddr.sx * 8;
}
case ASCE_TYPE_SEGMENT: {
union segment_table_entry ste;
if (kvm_is_error_gpa(vcpu->kvm, ptr))
return PGM_ADDRESSING;
if (deref_table(vcpu->kvm, ptr, &ste.val))
return -EFAULT;
if (ste.i)
return PGM_SEGMENT_TRANSLATION;
if (ste.tt != TABLE_TYPE_SEGMENT)
return PGM_TRANSLATION_SPEC;
if (ste.cs && asce.p)
return PGM_TRANSLATION_SPEC;
if (ste.fc && edat1) {
dat_protection |= ste.fc1.p;
iep_protection = ste.fc1.iep;
raddr.sfaa = ste.fc1.sfaa;
goto absolute_address;
}
dat_protection |= ste.fc0.p;
ptr = ste.fc0.pto * (PAGE_SIZE / 2) + vaddr.px * 8;
}
}
if (kvm_is_error_gpa(vcpu->kvm, ptr))
return PGM_ADDRESSING;
if (deref_table(vcpu->kvm, ptr, &pte.val))
return -EFAULT;
if (pte.i)
return PGM_PAGE_TRANSLATION;
if (pte.z)
return PGM_TRANSLATION_SPEC;
dat_protection |= pte.p;
iep_protection = pte.iep;
raddr.pfra = pte.pfra;
real_address:
raddr.addr = kvm_s390_real_to_abs(vcpu, raddr.addr);
absolute_address:
if (mode == GACC_STORE && dat_protection) {
*prot = PROT_TYPE_DAT;
return PGM_PROTECTION;
}
if (mode == GACC_IFETCH && iep_protection && iep) {
*prot = PROT_TYPE_IEP;
return PGM_PROTECTION;
}
if (kvm_is_error_gpa(vcpu->kvm, raddr.addr))
return PGM_ADDRESSING;
*gpa = raddr.addr;
return 0;
}
static inline int is_low_address(unsigned long ga)
{
return (ga & ~0x11fful) == 0;
}
static int low_address_protection_enabled(struct kvm_vcpu *vcpu,
const union asce asce)
{
union ctlreg0 ctlreg0 = {.val = vcpu->arch.sie_block->gcr[0]};
psw_t *psw = &vcpu->arch.sie_block->gpsw;
if (!ctlreg0.lap)
return 0;
if (psw_bits(*psw).dat && asce.p)
return 0;
return 1;
}
static int guest_page_range(struct kvm_vcpu *vcpu, unsigned long ga, u8 ar,
unsigned long *pages, unsigned long nr_pages,
const union asce asce, enum gacc_mode mode)
{
psw_t *psw = &vcpu->arch.sie_block->gpsw;
int lap_enabled, rc = 0;
enum prot_type prot;
lap_enabled = low_address_protection_enabled(vcpu, asce);
while (nr_pages) {
ga = kvm_s390_logical_to_effective(vcpu, ga);
if (mode == GACC_STORE && lap_enabled && is_low_address(ga))
return trans_exc(vcpu, PGM_PROTECTION, ga, ar, mode,
PROT_TYPE_LA);
ga &= PAGE_MASK;
if (psw_bits(*psw).dat) {
rc = guest_translate(vcpu, ga, pages, asce, mode, &prot);
if (rc < 0)
return rc;
} else {
*pages = kvm_s390_real_to_abs(vcpu, ga);
if (kvm_is_error_gpa(vcpu->kvm, *pages))
rc = PGM_ADDRESSING;
}
if (rc)
return trans_exc(vcpu, rc, ga, ar, mode, prot);
ga += PAGE_SIZE;
pages++;
nr_pages--;
}
return 0;
}
int access_guest(struct kvm_vcpu *vcpu, unsigned long ga, u8 ar, void *data,
unsigned long len, enum gacc_mode mode)
{
psw_t *psw = &vcpu->arch.sie_block->gpsw;
unsigned long _len, nr_pages, gpa, idx;
unsigned long pages_array[2];
unsigned long *pages;
int need_ipte_lock;
union asce asce;
int rc;
if (!len)
return 0;
ga = kvm_s390_logical_to_effective(vcpu, ga);
rc = get_vcpu_asce(vcpu, &asce, ga, ar, mode);
if (rc)
return rc;
nr_pages = (((ga & ~PAGE_MASK) + len - 1) >> PAGE_SHIFT) + 1;
pages = pages_array;
if (nr_pages > ARRAY_SIZE(pages_array))
pages = vmalloc(nr_pages * sizeof(unsigned long));
if (!pages)
return -ENOMEM;
need_ipte_lock = psw_bits(*psw).dat && !asce.r;
if (need_ipte_lock)
ipte_lock(vcpu);
rc = guest_page_range(vcpu, ga, ar, pages, nr_pages, asce, mode);
for (idx = 0; idx < nr_pages && !rc; idx++) {
gpa = *(pages + idx) + (ga & ~PAGE_MASK);
_len = min(PAGE_SIZE - (gpa & ~PAGE_MASK), len);
if (mode == GACC_STORE)
rc = kvm_write_guest(vcpu->kvm, gpa, data, _len);
else
rc = kvm_read_guest(vcpu->kvm, gpa, data, _len);
len -= _len;
ga += _len;
data += _len;
}
if (need_ipte_lock)
ipte_unlock(vcpu);
if (nr_pages > ARRAY_SIZE(pages_array))
vfree(pages);
return rc;
}
int access_guest_real(struct kvm_vcpu *vcpu, unsigned long gra,
void *data, unsigned long len, enum gacc_mode mode)
{
unsigned long _len, gpa;
int rc = 0;
while (len && !rc) {
gpa = kvm_s390_real_to_abs(vcpu, gra);
_len = min(PAGE_SIZE - (gpa & ~PAGE_MASK), len);
if (mode)
rc = write_guest_abs(vcpu, gpa, data, _len);
else
rc = read_guest_abs(vcpu, gpa, data, _len);
len -= _len;
gra += _len;
data += _len;
}
return rc;
}
int guest_translate_address(struct kvm_vcpu *vcpu, unsigned long gva, u8 ar,
unsigned long *gpa, enum gacc_mode mode)
{
psw_t *psw = &vcpu->arch.sie_block->gpsw;
enum prot_type prot;
union asce asce;
int rc;
gva = kvm_s390_logical_to_effective(vcpu, gva);
rc = get_vcpu_asce(vcpu, &asce, gva, ar, mode);
if (rc)
return rc;
if (is_low_address(gva) && low_address_protection_enabled(vcpu, asce)) {
if (mode == GACC_STORE)
return trans_exc(vcpu, PGM_PROTECTION, gva, 0,
mode, PROT_TYPE_LA);
}
if (psw_bits(*psw).dat && !asce.r) {
rc = guest_translate(vcpu, gva, gpa, asce, mode, &prot);
if (rc > 0)
return trans_exc(vcpu, rc, gva, 0, mode, prot);
} else {
*gpa = kvm_s390_real_to_abs(vcpu, gva);
if (kvm_is_error_gpa(vcpu->kvm, *gpa))
return trans_exc(vcpu, rc, gva, PGM_ADDRESSING, mode, 0);
}
return rc;
}
int check_gva_range(struct kvm_vcpu *vcpu, unsigned long gva, u8 ar,
unsigned long length, enum gacc_mode mode)
{
unsigned long gpa;
unsigned long currlen;
int rc = 0;
ipte_lock(vcpu);
while (length > 0 && !rc) {
currlen = min(length, PAGE_SIZE - (gva % PAGE_SIZE));
rc = guest_translate_address(vcpu, gva, ar, &gpa, mode);
gva += currlen;
length -= currlen;
}
ipte_unlock(vcpu);
return rc;
}
int kvm_s390_check_low_addr_prot_real(struct kvm_vcpu *vcpu, unsigned long gra)
{
union ctlreg0 ctlreg0 = {.val = vcpu->arch.sie_block->gcr[0]};
if (!ctlreg0.lap || !is_low_address(gra))
return 0;
return trans_exc(vcpu, PGM_PROTECTION, gra, 0, GACC_STORE, PROT_TYPE_LA);
}
static int kvm_s390_shadow_tables(struct gmap *sg, unsigned long saddr,
unsigned long *pgt, int *dat_protection,
int *fake)
{
struct gmap *parent;
union asce asce;
union vaddress vaddr;
unsigned long ptr;
int rc;
*fake = 0;
*dat_protection = 0;
parent = sg->parent;
vaddr.addr = saddr;
asce.val = sg->orig_asce;
ptr = asce.origin * PAGE_SIZE;
if (asce.r) {
*fake = 1;
ptr = 0;
asce.dt = ASCE_TYPE_REGION1;
}
switch (asce.dt) {
case ASCE_TYPE_REGION1:
if (vaddr.rfx01 > asce.tl && !*fake)
return PGM_REGION_FIRST_TRANS;
break;
case ASCE_TYPE_REGION2:
if (vaddr.rfx)
return PGM_ASCE_TYPE;
if (vaddr.rsx01 > asce.tl)
return PGM_REGION_SECOND_TRANS;
break;
case ASCE_TYPE_REGION3:
if (vaddr.rfx || vaddr.rsx)
return PGM_ASCE_TYPE;
if (vaddr.rtx01 > asce.tl)
return PGM_REGION_THIRD_TRANS;
break;
case ASCE_TYPE_SEGMENT:
if (vaddr.rfx || vaddr.rsx || vaddr.rtx)
return PGM_ASCE_TYPE;
if (vaddr.sx01 > asce.tl)
return PGM_SEGMENT_TRANSLATION;
break;
}
switch (asce.dt) {
case ASCE_TYPE_REGION1: {
union region1_table_entry rfte;
if (*fake) {
ptr += vaddr.rfx * _REGION1_SIZE;
rfte.val = ptr;
goto shadow_r2t;
}
rc = gmap_read_table(parent, ptr + vaddr.rfx * 8, &rfte.val);
if (rc)
return rc;
if (rfte.i)
return PGM_REGION_FIRST_TRANS;
if (rfte.tt != TABLE_TYPE_REGION1)
return PGM_TRANSLATION_SPEC;
if (vaddr.rsx01 < rfte.tf || vaddr.rsx01 > rfte.tl)
return PGM_REGION_SECOND_TRANS;
if (sg->edat_level >= 1)
*dat_protection |= rfte.p;
ptr = rfte.rto * PAGE_SIZE;
shadow_r2t:
rc = gmap_shadow_r2t(sg, saddr, rfte.val, *fake);
if (rc)
return rc;
}
case ASCE_TYPE_REGION2: {
union region2_table_entry rste;
if (*fake) {
ptr += vaddr.rsx * _REGION2_SIZE;
rste.val = ptr;
goto shadow_r3t;
}
rc = gmap_read_table(parent, ptr + vaddr.rsx * 8, &rste.val);
if (rc)
return rc;
if (rste.i)
return PGM_REGION_SECOND_TRANS;
if (rste.tt != TABLE_TYPE_REGION2)
return PGM_TRANSLATION_SPEC;
if (vaddr.rtx01 < rste.tf || vaddr.rtx01 > rste.tl)
return PGM_REGION_THIRD_TRANS;
if (sg->edat_level >= 1)
*dat_protection |= rste.p;
ptr = rste.rto * PAGE_SIZE;
shadow_r3t:
rste.p |= *dat_protection;
rc = gmap_shadow_r3t(sg, saddr, rste.val, *fake);
if (rc)
return rc;
}
case ASCE_TYPE_REGION3: {
union region3_table_entry rtte;
if (*fake) {
ptr += vaddr.rtx * _REGION3_SIZE;
rtte.val = ptr;
goto shadow_sgt;
}
rc = gmap_read_table(parent, ptr + vaddr.rtx * 8, &rtte.val);
if (rc)
return rc;
if (rtte.i)
return PGM_REGION_THIRD_TRANS;
if (rtte.tt != TABLE_TYPE_REGION3)
return PGM_TRANSLATION_SPEC;
if (rtte.cr && asce.p && sg->edat_level >= 2)
return PGM_TRANSLATION_SPEC;
if (rtte.fc && sg->edat_level >= 2) {
*dat_protection |= rtte.fc0.p;
*fake = 1;
ptr = rtte.fc1.rfaa * _REGION3_SIZE;
rtte.val = ptr;
goto shadow_sgt;
}
if (vaddr.sx01 < rtte.fc0.tf || vaddr.sx01 > rtte.fc0.tl)
return PGM_SEGMENT_TRANSLATION;
if (sg->edat_level >= 1)
*dat_protection |= rtte.fc0.p;
ptr = rtte.fc0.sto * PAGE_SIZE;
shadow_sgt:
rtte.fc0.p |= *dat_protection;
rc = gmap_shadow_sgt(sg, saddr, rtte.val, *fake);
if (rc)
return rc;
}
case ASCE_TYPE_SEGMENT: {
union segment_table_entry ste;
if (*fake) {
ptr += vaddr.sx * _SEGMENT_SIZE;
ste.val = ptr;
goto shadow_pgt;
}
rc = gmap_read_table(parent, ptr + vaddr.sx * 8, &ste.val);
if (rc)
return rc;
if (ste.i)
return PGM_SEGMENT_TRANSLATION;
if (ste.tt != TABLE_TYPE_SEGMENT)
return PGM_TRANSLATION_SPEC;
if (ste.cs && asce.p)
return PGM_TRANSLATION_SPEC;
*dat_protection |= ste.fc0.p;
if (ste.fc && sg->edat_level >= 1) {
*fake = 1;
ptr = ste.fc1.sfaa * _SEGMENT_SIZE;
ste.val = ptr;
goto shadow_pgt;
}
ptr = ste.fc0.pto * (PAGE_SIZE / 2);
shadow_pgt:
ste.fc0.p |= *dat_protection;
rc = gmap_shadow_pgt(sg, saddr, ste.val, *fake);
if (rc)
return rc;
}
}
*pgt = ptr;
return 0;
}
int kvm_s390_shadow_fault(struct kvm_vcpu *vcpu, struct gmap *sg,
unsigned long saddr)
{
union vaddress vaddr;
union page_table_entry pte;
unsigned long pgt;
int dat_protection, fake;
int rc;
down_read(&sg->mm->mmap_sem);
ipte_lock(vcpu);
rc = gmap_shadow_pgt_lookup(sg, saddr, &pgt, &dat_protection, &fake);
if (rc)
rc = kvm_s390_shadow_tables(sg, saddr, &pgt, &dat_protection,
&fake);
vaddr.addr = saddr;
if (fake) {
pte.val = pgt + vaddr.px * PAGE_SIZE;
goto shadow_page;
}
if (!rc)
rc = gmap_read_table(sg->parent, pgt + vaddr.px * 8, &pte.val);
if (!rc && pte.i)
rc = PGM_PAGE_TRANSLATION;
if (!rc && pte.z)
rc = PGM_TRANSLATION_SPEC;
shadow_page:
pte.p |= dat_protection;
if (!rc)
rc = gmap_shadow_page(sg, saddr, __pte(pte.val));
ipte_unlock(vcpu);
up_read(&sg->mm->mmap_sem);
return rc;
}
