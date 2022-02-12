static void set_inverse_transl(struct vc_data *conp, struct uni_pagedir *p, int i)
{
int j, glyph;
unsigned short *t = translations[i];
unsigned char *q;
if (!p) return;
q = p->inverse_translations[i];
if (!q) {
q = p->inverse_translations[i] = kmalloc(MAX_GLYPH, GFP_KERNEL);
if (!q) return;
}
memset(q, 0, MAX_GLYPH);
for (j = 0; j < E_TABSZ; j++) {
glyph = conv_uni_to_pc(conp, t[j]);
if (glyph >= 0 && glyph < MAX_GLYPH && q[glyph] < 32) {
q[glyph] = j;
}
}
}
static void set_inverse_trans_unicode(struct vc_data *conp,
struct uni_pagedir *p)
{
int i, j, k, glyph;
u16 **p1, *p2;
u16 *q;
if (!p) return;
q = p->inverse_trans_unicode;
if (!q) {
q = p->inverse_trans_unicode =
kmalloc(MAX_GLYPH * sizeof(u16), GFP_KERNEL);
if (!q)
return;
}
memset(q, 0, MAX_GLYPH * sizeof(u16));
for (i = 0; i < 32; i++) {
p1 = p->uni_pgdir[i];
if (!p1)
continue;
for (j = 0; j < 32; j++) {
p2 = p1[j];
if (!p2)
continue;
for (k = 0; k < 64; k++) {
glyph = p2[k];
if (glyph >= 0 && glyph < MAX_GLYPH
&& q[glyph] < 32)
q[glyph] = (i << 11) + (j << 6) + k;
}
}
}
}
unsigned short *set_translate(int m, struct vc_data *vc)
{
inv_translate[vc->vc_num] = m;
return translations[m];
}
u16 inverse_translate(struct vc_data *conp, int glyph, int use_unicode)
{
struct uni_pagedir *p;
int m;
if (glyph < 0 || glyph >= MAX_GLYPH)
return 0;
else {
p = *conp->vc_uni_pagedir_loc;
if (!p)
return glyph;
else if (use_unicode) {
if (!p->inverse_trans_unicode)
return glyph;
else
return p->inverse_trans_unicode[glyph];
} else {
m = inv_translate[conp->vc_num];
if (!p->inverse_translations[m])
return glyph;
else
return p->inverse_translations[m][glyph];
}
}
}
static void update_user_maps(void)
{
int i;
struct uni_pagedir *p, *q = NULL;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
if (!vc_cons_allocated(i))
continue;
p = *vc_cons[i].d->vc_uni_pagedir_loc;
if (p && p != q) {
set_inverse_transl(vc_cons[i].d, p, USER_MAP);
set_inverse_trans_unicode(vc_cons[i].d, p);
q = p;
}
}
}
int con_set_trans_old(unsigned char __user * arg)
{
int i;
unsigned short *p = translations[USER_MAP];
if (!access_ok(VERIFY_READ, arg, E_TABSZ))
return -EFAULT;
console_lock();
for (i=0; i<E_TABSZ ; i++) {
unsigned char uc;
__get_user(uc, arg+i);
p[i] = UNI_DIRECT_BASE | uc;
}
update_user_maps();
console_unlock();
return 0;
}
int con_get_trans_old(unsigned char __user * arg)
{
int i, ch;
unsigned short *p = translations[USER_MAP];
if (!access_ok(VERIFY_WRITE, arg, E_TABSZ))
return -EFAULT;
console_lock();
for (i=0; i<E_TABSZ ; i++)
{
ch = conv_uni_to_pc(vc_cons[fg_console].d, p[i]);
__put_user((ch & ~0xff) ? 0 : ch, arg+i);
}
console_unlock();
return 0;
}
int con_set_trans_new(ushort __user * arg)
{
int i;
unsigned short *p = translations[USER_MAP];
if (!access_ok(VERIFY_READ, arg, E_TABSZ*sizeof(unsigned short)))
return -EFAULT;
console_lock();
for (i=0; i<E_TABSZ ; i++) {
unsigned short us;
__get_user(us, arg+i);
p[i] = us;
}
update_user_maps();
console_unlock();
return 0;
}
int con_get_trans_new(ushort __user * arg)
{
int i;
unsigned short *p = translations[USER_MAP];
if (!access_ok(VERIFY_WRITE, arg, E_TABSZ*sizeof(unsigned short)))
return -EFAULT;
console_lock();
for (i=0; i<E_TABSZ ; i++)
__put_user(p[i], arg+i);
console_unlock();
return 0;
}
static void con_release_unimap(struct uni_pagedir *p)
{
u16 **p1;
int i, j;
if (p == dflt) dflt = NULL;
for (i = 0; i < 32; i++) {
p1 = p->uni_pgdir[i];
if (p1 != NULL) {
for (j = 0; j < 32; j++)
kfree(p1[j]);
kfree(p1);
}
p->uni_pgdir[i] = NULL;
}
for (i = 0; i < 4; i++) {
kfree(p->inverse_translations[i]);
p->inverse_translations[i] = NULL;
}
kfree(p->inverse_trans_unicode);
p->inverse_trans_unicode = NULL;
}
void con_free_unimap(struct vc_data *vc)
{
struct uni_pagedir *p;
p = *vc->vc_uni_pagedir_loc;
if (!p)
return;
*vc->vc_uni_pagedir_loc = NULL;
if (--p->refcount)
return;
con_release_unimap(p);
kfree(p);
}
static int con_unify_unimap(struct vc_data *conp, struct uni_pagedir *p)
{
int i, j, k;
struct uni_pagedir *q;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
if (!vc_cons_allocated(i))
continue;
q = *vc_cons[i].d->vc_uni_pagedir_loc;
if (!q || q == p || q->sum != p->sum)
continue;
for (j = 0; j < 32; j++) {
u16 **p1, **q1;
p1 = p->uni_pgdir[j]; q1 = q->uni_pgdir[j];
if (!p1 && !q1)
continue;
if (!p1 || !q1)
break;
for (k = 0; k < 32; k++) {
if (!p1[k] && !q1[k])
continue;
if (!p1[k] || !q1[k])
break;
if (memcmp(p1[k], q1[k], 64*sizeof(u16)))
break;
}
if (k < 32)
break;
}
if (j == 32) {
q->refcount++;
*conp->vc_uni_pagedir_loc = q;
con_release_unimap(p);
kfree(p);
return 1;
}
}
return 0;
}
static int
con_insert_unipair(struct uni_pagedir *p, u_short unicode, u_short fontpos)
{
int i, n;
u16 **p1, *p2;
p1 = p->uni_pgdir[n = unicode >> 11];
if (!p1) {
p1 = p->uni_pgdir[n] = kmalloc(32*sizeof(u16 *), GFP_KERNEL);
if (!p1) return -ENOMEM;
for (i = 0; i < 32; i++)
p1[i] = NULL;
}
p2 = p1[n = (unicode >> 6) & 0x1f];
if (!p2) {
p2 = p1[n] = kmalloc(64*sizeof(u16), GFP_KERNEL);
if (!p2) return -ENOMEM;
memset(p2, 0xff, 64*sizeof(u16));
}
p2[unicode & 0x3f] = fontpos;
p->sum += (fontpos << 20) + unicode;
return 0;
}
static int con_do_clear_unimap(struct vc_data *vc)
{
struct uni_pagedir *p, *q;
p = *vc->vc_uni_pagedir_loc;
if (!p || --p->refcount) {
q = kzalloc(sizeof(*p), GFP_KERNEL);
if (!q) {
if (p)
p->refcount++;
return -ENOMEM;
}
q->refcount=1;
*vc->vc_uni_pagedir_loc = q;
} else {
if (p == dflt) dflt = NULL;
p->refcount++;
p->sum = 0;
con_release_unimap(p);
}
return 0;
}
int con_clear_unimap(struct vc_data *vc)
{
int ret;
console_lock();
ret = con_do_clear_unimap(vc);
console_unlock();
return ret;
}
int con_set_unimap(struct vc_data *vc, ushort ct, struct unipair __user *list)
{
int err = 0, err1, i;
struct uni_pagedir *p, *q;
if (!ct)
return 0;
console_lock();
p = *vc->vc_uni_pagedir_loc;
if (!p) {
err = -EINVAL;
goto out_unlock;
}
if (p->refcount > 1) {
int j, k;
u16 **p1, *p2, l;
err1 = con_do_clear_unimap(vc);
if (err1) {
console_unlock();
return err1;
}
q = *vc->vc_uni_pagedir_loc;
l = 0;
for (i = 0; i < 32; i++) {
p1 = p->uni_pgdir[i];
if (p1)
for (j = 0; j < 32; j++) {
p2 = p1[j];
if (p2) {
for (k = 0; k < 64; k++, l++)
if (p2[k] != 0xffff) {
err1 = con_insert_unipair(q, l, p2[k]);
if (err1) {
p->refcount++;
*vc->vc_uni_pagedir_loc = p;
con_release_unimap(q);
kfree(q);
console_unlock();
return err1;
}
}
} else {
l += 64;
}
}
else
l += 32 * 64;
}
p = q;
} else if (p == dflt) {
dflt = NULL;
}
while (ct--) {
unsigned short unicode, fontpos;
__get_user(unicode, &list->unicode);
__get_user(fontpos, &list->fontpos);
if ((err1 = con_insert_unipair(p, unicode,fontpos)) != 0)
err = err1;
list++;
}
if (con_unify_unimap(vc, p)) {
console_unlock();
return err;
}
for (i = 0; i <= 3; i++)
set_inverse_transl(vc, p, i);
set_inverse_trans_unicode(vc, p);
out_unlock:
console_unlock();
return err;
}
int con_set_default_unimap(struct vc_data *vc)
{
int i, j, err = 0, err1;
u16 *q;
struct uni_pagedir *p;
if (dflt) {
p = *vc->vc_uni_pagedir_loc;
if (p == dflt)
return 0;
dflt->refcount++;
*vc->vc_uni_pagedir_loc = dflt;
if (p && !--p->refcount) {
con_release_unimap(p);
kfree(p);
}
return 0;
}
err = con_do_clear_unimap(vc);
if (err)
return err;
p = *vc->vc_uni_pagedir_loc;
q = dfont_unitable;
for (i = 0; i < 256; i++)
for (j = dfont_unicount[i]; j; j--) {
err1 = con_insert_unipair(p, *(q++), i);
if (err1)
err = err1;
}
if (con_unify_unimap(vc, p)) {
dflt = *vc->vc_uni_pagedir_loc;
return err;
}
for (i = 0; i <= 3; i++)
set_inverse_transl(vc, p, i);
set_inverse_trans_unicode(vc, p);
dflt = p;
return err;
}
int con_copy_unimap(struct vc_data *dst_vc, struct vc_data *src_vc)
{
struct uni_pagedir *q;
if (!*src_vc->vc_uni_pagedir_loc)
return -EINVAL;
if (*dst_vc->vc_uni_pagedir_loc == *src_vc->vc_uni_pagedir_loc)
return 0;
con_free_unimap(dst_vc);
q = *src_vc->vc_uni_pagedir_loc;
q->refcount++;
*dst_vc->vc_uni_pagedir_loc = q;
return 0;
}
int con_get_unimap(struct vc_data *vc, ushort ct, ushort __user *uct, struct unipair __user *list)
{
int i, j, k, ect;
u16 **p1, *p2;
struct uni_pagedir *p;
console_lock();
ect = 0;
if (*vc->vc_uni_pagedir_loc) {
p = *vc->vc_uni_pagedir_loc;
for (i = 0; i < 32; i++) {
p1 = p->uni_pgdir[i];
if (p1)
for (j = 0; j < 32; j++) {
p2 = *(p1++);
if (p2)
for (k = 0; k < 64; k++) {
if (*p2 < MAX_GLYPH && ect++ < ct) {
__put_user((u_short)((i<<11)+(j<<6)+k),
&list->unicode);
__put_user((u_short) *p2,
&list->fontpos);
list++;
}
p2++;
}
}
}
}
__put_user(ect, uct);
console_unlock();
return ((ect <= ct) ? 0 : -ENOMEM);
}
u32 conv_8bit_to_uni(unsigned char c)
{
unsigned short uni = translations[USER_MAP][c];
return uni == (0xf000 | c) ? c : uni;
}
int conv_uni_to_8bit(u32 uni)
{
int c;
for (c = 0; c < 0x100; c++)
if (translations[USER_MAP][c] == uni ||
(translations[USER_MAP][c] == (c | 0xf000) && uni == c))
return c;
return -1;
}
int
conv_uni_to_pc(struct vc_data *conp, long ucs)
{
int h;
u16 **p1, *p2;
struct uni_pagedir *p;
if (ucs > 0xffff)
return -4;
else if (ucs < 0x20)
return -1;
else if (ucs == 0xfeff || (ucs >= 0x200b && ucs <= 0x200f))
return -2;
else if ((ucs & ~UNI_DIRECT_MASK) == UNI_DIRECT_BASE)
return ucs & UNI_DIRECT_MASK;
if (!*conp->vc_uni_pagedir_loc)
return -3;
p = *conp->vc_uni_pagedir_loc;
if ((p1 = p->uni_pgdir[ucs >> 11]) &&
(p2 = p1[(ucs >> 6) & 0x1f]) &&
(h = p2[ucs & 0x3f]) < MAX_GLYPH)
return h;
return -4;
}
void __init
console_map_init(void)
{
int i;
for (i = 0; i < MAX_NR_CONSOLES; i++)
if (vc_cons_allocated(i) && !*vc_cons[i].d->vc_uni_pagedir_loc)
con_set_default_unimap(vc_cons[i].d);
}
