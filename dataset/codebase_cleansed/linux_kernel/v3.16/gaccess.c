int ipte_lock_held(struct kvm_vcpu *vcpu)
{
union ipte_control *ic = &vcpu->kvm->arch.sca->ipte_control;
if (vcpu->arch.sie_block->eca & 1)
return ic->kh != 0;
return ipte_lock_count != 0;
}
static void ipte_lock_simple(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
mutex_lock(&ipte_mutex);
ipte_lock_count++;
if (ipte_lock_count > 1)
goto out;
ic = &vcpu->kvm->arch.sca->ipte_control;
do {
old = ACCESS_ONCE(*ic);
while (old.k) {
cond_resched();
old = ACCESS_ONCE(*ic);
}
new = old;
new.k = 1;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
out:
mutex_unlock(&ipte_mutex);
}
static void ipte_unlock_simple(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
mutex_lock(&ipte_mutex);
ipte_lock_count--;
if (ipte_lock_count)
goto out;
ic = &vcpu->kvm->arch.sca->ipte_control;
do {
new = old = ACCESS_ONCE(*ic);
new.k = 0;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
if (!ipte_lock_count)
wake_up(&vcpu->kvm->arch.ipte_wq);
out:
mutex_unlock(&ipte_mutex);
}
static void ipte_lock_siif(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
ic = &vcpu->kvm->arch.sca->ipte_control;
do {
old = ACCESS_ONCE(*ic);
while (old.kg) {
cond_resched();
old = ACCESS_ONCE(*ic);
}
new = old;
new.k = 1;
new.kh++;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
}
static void ipte_unlock_siif(struct kvm_vcpu *vcpu)
{
union ipte_control old, new, *ic;
ic = &vcpu->kvm->arch.sca->ipte_control;
do {
new = old = ACCESS_ONCE(*ic);
new.kh--;
if (!new.kh)
new.k = 0;
} while (cmpxchg(&ic->val, old.val, new.val) != old.val);
if (!new.kh)
wake_up(&vcpu->kvm->arch.ipte_wq);
}
void ipte_lock(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.sie_block->eca & 1)
ipte_lock_siif(vcpu);
else
ipte_lock_simple(vcpu);
}
void ipte_unlock(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.sie_block->eca & 1)
ipte_unlock_siif(vcpu);
else
ipte_unlock_simple(vcpu);
}
static unsigned long get_vcpu_asce(struct kvm_vcpu *vcpu)
{
switch (psw_bits(vcpu->arch.sie_block->gpsw).as) {
case PSW_AS_PRIMARY:
return vcpu->arch.sie_block->gcr[1];
case PSW_AS_SECONDARY:
return vcpu->arch.sie_block->gcr[7];
case PSW_AS_HOME:
return vcpu->arch.sie_block->gcr[13];
}
return 0;
}
static int deref_table(struct kvm *kvm, unsigned long gpa, unsigned long *val)
{
return kvm_read_guest(kvm, gpa, val, sizeof(*val));
}
static unsigned long guest_translate(struct kvm_vcpu *vcpu, unsigned long gva,
unsigned long *gpa, int write)
{
union vaddress vaddr = {.addr = gva};
union raddress raddr = {.addr = gva};
union page_table_entry pte;
int dat_protection = 0;
union ctlreg0 ctlreg0;
unsigned long ptr;
int edat1, edat2;
union asce asce;
ctlreg0.val = vcpu->arch.sie_block->gcr[0];
edat1 = ctlreg0.edat && test_vfacility(8);
edat2 = edat1 && test_vfacility(78);
asce.val = get_vcpu_asce(vcpu);
if (asce.r)
goto real_address;
ptr = asce.origin * 4096;
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
ptr = rfte.rto * 4096 + vaddr.rsx * 8;
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
ptr = rste.rto * 4096 + vaddr.rtx * 8;
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
raddr.rfaa = rtte.fc1.rfaa;
goto absolute_address;
}
if (vaddr.sx01 < rtte.fc0.tf)
return PGM_SEGMENT_TRANSLATION;
if (vaddr.sx01 > rtte.fc0.tl)
return PGM_SEGMENT_TRANSLATION;
if (edat1)
dat_protection |= rtte.fc0.p;
ptr = rtte.fc0.sto * 4096 + vaddr.sx * 8;
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
raddr.sfaa = ste.fc1.sfaa;
goto absolute_address;
}
dat_protection |= ste.fc0.p;
ptr = ste.fc0.pto * 2048 + vaddr.px * 8;
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
if (pte.co && !edat1)
return PGM_TRANSLATION_SPEC;
dat_protection |= pte.p;
raddr.pfra = pte.pfra;
real_address:
raddr.addr = kvm_s390_real_to_abs(vcpu, raddr.addr);
absolute_address:
if (write && dat_protection)
return PGM_PROTECTION;
if (kvm_is_error_gpa(vcpu->kvm, raddr.addr))
return PGM_ADDRESSING;
*gpa = raddr.addr;
return 0;
}
static inline int is_low_address(unsigned long ga)
{
return (ga & ~0x11fful) == 0;
}
static int low_address_protection_enabled(struct kvm_vcpu *vcpu)
{
union ctlreg0 ctlreg0 = {.val = vcpu->arch.sie_block->gcr[0]};
psw_t *psw = &vcpu->arch.sie_block->gpsw;
union asce asce;
if (!ctlreg0.lap)
return 0;
asce.val = get_vcpu_asce(vcpu);
if (psw_bits(*psw).t && asce.p)
return 0;
return 1;
}
static int guest_page_range(struct kvm_vcpu *vcpu, unsigned long ga,
unsigned long *pages, unsigned long nr_pages,
int write)
{
struct kvm_s390_pgm_info *pgm = &vcpu->arch.pgm;
psw_t *psw = &vcpu->arch.sie_block->gpsw;
struct trans_exc_code_bits *tec_bits;
int lap_enabled, rc;
memset(pgm, 0, sizeof(*pgm));
tec_bits = (struct trans_exc_code_bits *)&pgm->trans_exc_code;
tec_bits->fsi = write ? FSI_STORE : FSI_FETCH;
tec_bits->as = psw_bits(*psw).as;
lap_enabled = low_address_protection_enabled(vcpu);
while (nr_pages) {
ga = kvm_s390_logical_to_effective(vcpu, ga);
tec_bits->addr = ga >> PAGE_SHIFT;
if (write && lap_enabled && is_low_address(ga)) {
pgm->code = PGM_PROTECTION;
return pgm->code;
}
ga &= PAGE_MASK;
if (psw_bits(*psw).t) {
rc = guest_translate(vcpu, ga, pages, write);
if (rc < 0)
return rc;
if (rc == PGM_PROTECTION)
tec_bits->b61 = 1;
if (rc)
pgm->code = rc;
} else {
*pages = kvm_s390_real_to_abs(vcpu, ga);
if (kvm_is_error_gpa(vcpu->kvm, *pages))
pgm->code = PGM_ADDRESSING;
}
if (pgm->code)
return pgm->code;
ga += PAGE_SIZE;
pages++;
nr_pages--;
}
return 0;
}
int access_guest(struct kvm_vcpu *vcpu, unsigned long ga, void *data,
unsigned long len, int write)
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
if (psw_bits(*psw).t && psw_bits(*psw).as == PSW_AS_ACCREG)
return -EOPNOTSUPP;
nr_pages = (((ga & ~PAGE_MASK) + len - 1) >> PAGE_SHIFT) + 1;
pages = pages_array;
if (nr_pages > ARRAY_SIZE(pages_array))
pages = vmalloc(nr_pages * sizeof(unsigned long));
if (!pages)
return -ENOMEM;
asce.val = get_vcpu_asce(vcpu);
need_ipte_lock = psw_bits(*psw).t && !asce.r;
if (need_ipte_lock)
ipte_lock(vcpu);
rc = guest_page_range(vcpu, ga, pages, nr_pages, write);
for (idx = 0; idx < nr_pages && !rc; idx++) {
gpa = *(pages + idx) + (ga & ~PAGE_MASK);
_len = min(PAGE_SIZE - (gpa & ~PAGE_MASK), len);
if (write)
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
void *data, unsigned long len, int write)
{
unsigned long _len, gpa;
int rc = 0;
while (len && !rc) {
gpa = kvm_s390_real_to_abs(vcpu, gra);
_len = min(PAGE_SIZE - (gpa & ~PAGE_MASK), len);
if (write)
rc = write_guest_abs(vcpu, gpa, data, _len);
else
rc = read_guest_abs(vcpu, gpa, data, _len);
len -= _len;
gra += _len;
data += _len;
}
return rc;
}
int guest_translate_address(struct kvm_vcpu *vcpu, unsigned long gva,
unsigned long *gpa, int write)
{
struct kvm_s390_pgm_info *pgm = &vcpu->arch.pgm;
psw_t *psw = &vcpu->arch.sie_block->gpsw;
struct trans_exc_code_bits *tec;
union asce asce;
int rc;
if (psw_bits(*psw).t && psw_bits(*psw).as == PSW_AS_ACCREG)
return -EOPNOTSUPP;
gva = kvm_s390_logical_to_effective(vcpu, gva);
memset(pgm, 0, sizeof(*pgm));
tec = (struct trans_exc_code_bits *)&pgm->trans_exc_code;
tec->as = psw_bits(*psw).as;
tec->fsi = write ? FSI_STORE : FSI_FETCH;
tec->addr = gva >> PAGE_SHIFT;
if (is_low_address(gva) && low_address_protection_enabled(vcpu)) {
if (write) {
rc = pgm->code = PGM_PROTECTION;
return rc;
}
}
asce.val = get_vcpu_asce(vcpu);
if (psw_bits(*psw).t && !asce.r) {
rc = guest_translate(vcpu, gva, gpa, write);
if (rc > 0) {
if (rc == PGM_PROTECTION)
tec->b61 = 1;
pgm->code = rc;
}
} else {
rc = 0;
*gpa = kvm_s390_real_to_abs(vcpu, gva);
if (kvm_is_error_gpa(vcpu->kvm, *gpa))
rc = pgm->code = PGM_ADDRESSING;
}
return rc;
}
int kvm_s390_check_low_addr_protection(struct kvm_vcpu *vcpu, unsigned long ga)
{
struct kvm_s390_pgm_info *pgm = &vcpu->arch.pgm;
psw_t *psw = &vcpu->arch.sie_block->gpsw;
struct trans_exc_code_bits *tec_bits;
if (!is_low_address(ga) || !low_address_protection_enabled(vcpu))
return 0;
memset(pgm, 0, sizeof(*pgm));
tec_bits = (struct trans_exc_code_bits *)&pgm->trans_exc_code;
tec_bits->fsi = FSI_STORE;
tec_bits->as = psw_bits(*psw).as;
tec_bits->addr = ga >> PAGE_SHIFT;
pgm->code = PGM_PROTECTION;
return pgm->code;
}
