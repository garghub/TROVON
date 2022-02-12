static inline mm_segment_t snd_enter_user(void)
{
mm_segment_t fs = get_fs();
set_fs(get_ds());
return fs;
}
static inline void snd_leave_user(mm_segment_t fs)
{
set_fs(fs);
}
static int snd_emu10k1_gpr_ctl_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct snd_emu10k1_fx8010_ctl *ctl =
(struct snd_emu10k1_fx8010_ctl *) kcontrol->private_value;
if (ctl->min == 0 && ctl->max == 1)
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
else
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = ctl->vcount;
uinfo->value.integer.min = ctl->min;
uinfo->value.integer.max = ctl->max;
return 0;
}
static int snd_emu10k1_gpr_ctl_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_fx8010_ctl *ctl =
(struct snd_emu10k1_fx8010_ctl *) kcontrol->private_value;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&emu->reg_lock, flags);
for (i = 0; i < ctl->vcount; i++)
ucontrol->value.integer.value[i] = ctl->value[i];
spin_unlock_irqrestore(&emu->reg_lock, flags);
return 0;
}
static int snd_emu10k1_gpr_ctl_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_emu10k1 *emu = snd_kcontrol_chip(kcontrol);
struct snd_emu10k1_fx8010_ctl *ctl =
(struct snd_emu10k1_fx8010_ctl *) kcontrol->private_value;
unsigned long flags;
unsigned int nval, val;
unsigned int i, j;
int change = 0;
spin_lock_irqsave(&emu->reg_lock, flags);
for (i = 0; i < ctl->vcount; i++) {
nval = ucontrol->value.integer.value[i];
if (nval < ctl->min)
nval = ctl->min;
if (nval > ctl->max)
nval = ctl->max;
if (nval != ctl->value[i])
change = 1;
val = ctl->value[i] = nval;
switch (ctl->translation) {
case EMU10K1_GPR_TRANSLATION_NONE:
snd_emu10k1_ptr_write(emu, emu->gpr_base + ctl->gpr[i], 0, val);
break;
case EMU10K1_GPR_TRANSLATION_TABLE100:
snd_emu10k1_ptr_write(emu, emu->gpr_base + ctl->gpr[i], 0, db_table[val]);
break;
case EMU10K1_GPR_TRANSLATION_BASS:
if ((ctl->count % 5) != 0 || (ctl->count / 5) != ctl->vcount) {
change = -EIO;
goto __error;
}
for (j = 0; j < 5; j++)
snd_emu10k1_ptr_write(emu, emu->gpr_base + ctl->gpr[j * ctl->vcount + i], 0, bass_table[val][j]);
break;
case EMU10K1_GPR_TRANSLATION_TREBLE:
if ((ctl->count % 5) != 0 || (ctl->count / 5) != ctl->vcount) {
change = -EIO;
goto __error;
}
for (j = 0; j < 5; j++)
snd_emu10k1_ptr_write(emu, emu->gpr_base + ctl->gpr[j * ctl->vcount + i], 0, treble_table[val][j]);
break;
case EMU10K1_GPR_TRANSLATION_ONOFF:
snd_emu10k1_ptr_write(emu, emu->gpr_base + ctl->gpr[i], 0, onoff_table[val]);
break;
}
}
__error:
spin_unlock_irqrestore(&emu->reg_lock, flags);
return change;
}
static void snd_emu10k1_fx8010_interrupt(struct snd_emu10k1 *emu)
{
struct snd_emu10k1_fx8010_irq *irq, *nirq;
irq = emu->fx8010.irq_handlers;
while (irq) {
nirq = irq->next;
if (snd_emu10k1_ptr_read(emu, emu->gpr_base + irq->gpr_running, 0) & 0xffff0000) {
if (irq->handler)
irq->handler(emu, irq->private_data);
snd_emu10k1_ptr_write(emu, emu->gpr_base + irq->gpr_running, 0, 1);
}
irq = nirq;
}
}
int snd_emu10k1_fx8010_register_irq_handler(struct snd_emu10k1 *emu,
snd_fx8010_irq_handler_t *handler,
unsigned char gpr_running,
void *private_data,
struct snd_emu10k1_fx8010_irq **r_irq)
{
struct snd_emu10k1_fx8010_irq *irq;
unsigned long flags;
irq = kmalloc(sizeof(*irq), GFP_ATOMIC);
if (irq == NULL)
return -ENOMEM;
irq->handler = handler;
irq->gpr_running = gpr_running;
irq->private_data = private_data;
irq->next = NULL;
spin_lock_irqsave(&emu->fx8010.irq_lock, flags);
if (emu->fx8010.irq_handlers == NULL) {
emu->fx8010.irq_handlers = irq;
emu->dsp_interrupt = snd_emu10k1_fx8010_interrupt;
snd_emu10k1_intr_enable(emu, INTE_FXDSPENABLE);
} else {
irq->next = emu->fx8010.irq_handlers;
emu->fx8010.irq_handlers = irq;
}
spin_unlock_irqrestore(&emu->fx8010.irq_lock, flags);
if (r_irq)
*r_irq = irq;
return 0;
}
int snd_emu10k1_fx8010_unregister_irq_handler(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_irq *irq)
{
struct snd_emu10k1_fx8010_irq *tmp;
unsigned long flags;
spin_lock_irqsave(&emu->fx8010.irq_lock, flags);
if ((tmp = emu->fx8010.irq_handlers) == irq) {
emu->fx8010.irq_handlers = tmp->next;
if (emu->fx8010.irq_handlers == NULL) {
snd_emu10k1_intr_disable(emu, INTE_FXDSPENABLE);
emu->dsp_interrupt = NULL;
}
} else {
while (tmp && tmp->next != irq)
tmp = tmp->next;
if (tmp)
tmp->next = tmp->next->next;
}
spin_unlock_irqrestore(&emu->fx8010.irq_lock, flags);
kfree(irq);
return 0;
}
static void snd_emu10k1_write_op(struct snd_emu10k1_fx8010_code *icode,
unsigned int *ptr,
u32 op, u32 r, u32 a, u32 x, u32 y)
{
u_int32_t *code;
if (snd_BUG_ON(*ptr >= 512))
return;
code = (u_int32_t __force *)icode->code + (*ptr) * 2;
set_bit(*ptr, icode->code_valid);
code[0] = ((x & 0x3ff) << 10) | (y & 0x3ff);
code[1] = ((op & 0x0f) << 20) | ((r & 0x3ff) << 10) | (a & 0x3ff);
(*ptr)++;
}
static void snd_emu10k1_audigy_write_op(struct snd_emu10k1_fx8010_code *icode,
unsigned int *ptr,
u32 op, u32 r, u32 a, u32 x, u32 y)
{
u_int32_t *code;
if (snd_BUG_ON(*ptr >= 1024))
return;
code = (u_int32_t __force *)icode->code + (*ptr) * 2;
set_bit(*ptr, icode->code_valid);
code[0] = ((x & 0x7ff) << 12) | (y & 0x7ff);
code[1] = ((op & 0x0f) << 24) | ((r & 0x7ff) << 12) | (a & 0x7ff);
(*ptr)++;
}
static void snd_emu10k1_efx_write(struct snd_emu10k1 *emu, unsigned int pc, unsigned int data)
{
pc += emu->audigy ? A_MICROCODEBASE : MICROCODEBASE;
snd_emu10k1_ptr_write(emu, pc, 0, data);
}
unsigned int snd_emu10k1_efx_read(struct snd_emu10k1 *emu, unsigned int pc)
{
pc += emu->audigy ? A_MICROCODEBASE : MICROCODEBASE;
return snd_emu10k1_ptr_read(emu, pc, 0);
}
static int snd_emu10k1_gpr_poke(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
int gpr;
u32 val;
for (gpr = 0; gpr < (emu->audigy ? 0x200 : 0x100); gpr++) {
if (!test_bit(gpr, icode->gpr_valid))
continue;
if (get_user(val, &icode->gpr_map[gpr]))
return -EFAULT;
snd_emu10k1_ptr_write(emu, emu->gpr_base + gpr, 0, val);
}
return 0;
}
static int snd_emu10k1_gpr_peek(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
int gpr;
u32 val;
for (gpr = 0; gpr < (emu->audigy ? 0x200 : 0x100); gpr++) {
set_bit(gpr, icode->gpr_valid);
val = snd_emu10k1_ptr_read(emu, emu->gpr_base + gpr, 0);
if (put_user(val, &icode->gpr_map[gpr]))
return -EFAULT;
}
return 0;
}
static int snd_emu10k1_tram_poke(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
int tram;
u32 addr, val;
for (tram = 0; tram < (emu->audigy ? 0x100 : 0xa0); tram++) {
if (!test_bit(tram, icode->tram_valid))
continue;
if (get_user(val, &icode->tram_data_map[tram]) ||
get_user(addr, &icode->tram_addr_map[tram]))
return -EFAULT;
snd_emu10k1_ptr_write(emu, TANKMEMDATAREGBASE + tram, 0, val);
if (!emu->audigy) {
snd_emu10k1_ptr_write(emu, TANKMEMADDRREGBASE + tram, 0, addr);
} else {
snd_emu10k1_ptr_write(emu, TANKMEMADDRREGBASE + tram, 0, addr << 12);
snd_emu10k1_ptr_write(emu, A_TANKMEMCTLREGBASE + tram, 0, addr >> 20);
}
}
return 0;
}
static int snd_emu10k1_tram_peek(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
int tram;
u32 val, addr;
memset(icode->tram_valid, 0, sizeof(icode->tram_valid));
for (tram = 0; tram < (emu->audigy ? 0x100 : 0xa0); tram++) {
set_bit(tram, icode->tram_valid);
val = snd_emu10k1_ptr_read(emu, TANKMEMDATAREGBASE + tram, 0);
if (!emu->audigy) {
addr = snd_emu10k1_ptr_read(emu, TANKMEMADDRREGBASE + tram, 0);
} else {
addr = snd_emu10k1_ptr_read(emu, TANKMEMADDRREGBASE + tram, 0) >> 12;
addr |= snd_emu10k1_ptr_read(emu, A_TANKMEMCTLREGBASE + tram, 0) << 20;
}
if (put_user(val, &icode->tram_data_map[tram]) ||
put_user(addr, &icode->tram_addr_map[tram]))
return -EFAULT;
}
return 0;
}
static int snd_emu10k1_code_poke(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
u32 pc, lo, hi;
for (pc = 0; pc < (emu->audigy ? 2*1024 : 2*512); pc += 2) {
if (!test_bit(pc / 2, icode->code_valid))
continue;
if (get_user(lo, &icode->code[pc + 0]) ||
get_user(hi, &icode->code[pc + 1]))
return -EFAULT;
snd_emu10k1_efx_write(emu, pc + 0, lo);
snd_emu10k1_efx_write(emu, pc + 1, hi);
}
return 0;
}
static int snd_emu10k1_code_peek(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
u32 pc;
memset(icode->code_valid, 0, sizeof(icode->code_valid));
for (pc = 0; pc < (emu->audigy ? 2*1024 : 2*512); pc += 2) {
set_bit(pc / 2, icode->code_valid);
if (put_user(snd_emu10k1_efx_read(emu, pc + 0), &icode->code[pc + 0]))
return -EFAULT;
if (put_user(snd_emu10k1_efx_read(emu, pc + 1), &icode->code[pc + 1]))
return -EFAULT;
}
return 0;
}
static struct snd_emu10k1_fx8010_ctl *
snd_emu10k1_look_for_ctl(struct snd_emu10k1 *emu, struct snd_ctl_elem_id *id)
{
struct snd_emu10k1_fx8010_ctl *ctl;
struct snd_kcontrol *kcontrol;
list_for_each_entry(ctl, &emu->fx8010.gpr_ctl, list) {
kcontrol = ctl->kcontrol;
if (kcontrol->id.iface == id->iface &&
!strcmp(kcontrol->id.name, id->name) &&
kcontrol->id.index == id->index)
return ctl;
}
return NULL;
}
static unsigned int *copy_tlv(const unsigned int __user *_tlv)
{
unsigned int data[2];
unsigned int *tlv;
if (!_tlv)
return NULL;
if (copy_from_user(data, _tlv, sizeof(data)))
return NULL;
if (data[1] >= MAX_TLV_SIZE)
return NULL;
tlv = kmalloc(data[1] + sizeof(data), GFP_KERNEL);
if (!tlv)
return NULL;
memcpy(tlv, data, sizeof(data));
if (copy_from_user(tlv + 2, _tlv + 2, data[1])) {
kfree(tlv);
return NULL;
}
return tlv;
}
static int copy_gctl(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_control_gpr *gctl,
struct snd_emu10k1_fx8010_control_gpr __user *_gctl,
int idx)
{
struct snd_emu10k1_fx8010_control_old_gpr __user *octl;
if (emu->support_tlv)
return copy_from_user(gctl, &_gctl[idx], sizeof(*gctl));
octl = (struct snd_emu10k1_fx8010_control_old_gpr __user *)_gctl;
if (copy_from_user(gctl, &octl[idx], sizeof(*octl)))
return -EFAULT;
gctl->tlv = NULL;
return 0;
}
static int copy_gctl_to_user(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_control_gpr __user *_gctl,
struct snd_emu10k1_fx8010_control_gpr *gctl,
int idx)
{
struct snd_emu10k1_fx8010_control_old_gpr __user *octl;
if (emu->support_tlv)
return copy_to_user(&_gctl[idx], gctl, sizeof(*gctl));
octl = (struct snd_emu10k1_fx8010_control_old_gpr __user *)_gctl;
return copy_to_user(&octl[idx], gctl, sizeof(*octl));
}
static int snd_emu10k1_verify_controls(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
unsigned int i;
struct snd_ctl_elem_id __user *_id;
struct snd_ctl_elem_id id;
struct snd_emu10k1_fx8010_control_gpr *gctl;
int err;
for (i = 0, _id = icode->gpr_del_controls;
i < icode->gpr_del_control_count; i++, _id++) {
if (copy_from_user(&id, _id, sizeof(id)))
return -EFAULT;
if (snd_emu10k1_look_for_ctl(emu, &id) == NULL)
return -ENOENT;
}
gctl = kmalloc(sizeof(*gctl), GFP_KERNEL);
if (! gctl)
return -ENOMEM;
err = 0;
for (i = 0; i < icode->gpr_add_control_count; i++) {
if (copy_gctl(emu, gctl, icode->gpr_add_controls, i)) {
err = -EFAULT;
goto __error;
}
if (snd_emu10k1_look_for_ctl(emu, &gctl->id))
continue;
down_read(&emu->card->controls_rwsem);
if (snd_ctl_find_id(emu->card, &gctl->id) != NULL) {
up_read(&emu->card->controls_rwsem);
err = -EEXIST;
goto __error;
}
up_read(&emu->card->controls_rwsem);
if (gctl->id.iface != SNDRV_CTL_ELEM_IFACE_MIXER &&
gctl->id.iface != SNDRV_CTL_ELEM_IFACE_PCM) {
err = -EINVAL;
goto __error;
}
}
for (i = 0; i < icode->gpr_list_control_count; i++) {
if (copy_gctl(emu, gctl, icode->gpr_list_controls, i)) {
err = -EFAULT;
goto __error;
}
}
__error:
kfree(gctl);
return err;
}
static void snd_emu10k1_ctl_private_free(struct snd_kcontrol *kctl)
{
struct snd_emu10k1_fx8010_ctl *ctl;
ctl = (struct snd_emu10k1_fx8010_ctl *) kctl->private_value;
kctl->private_value = 0;
list_del(&ctl->list);
kfree(ctl);
if (kctl->tlv.p)
kfree(kctl->tlv.p);
}
static int snd_emu10k1_add_controls(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
unsigned int i, j;
struct snd_emu10k1_fx8010_control_gpr *gctl;
struct snd_emu10k1_fx8010_ctl *ctl, *nctl;
struct snd_kcontrol_new knew;
struct snd_kcontrol *kctl;
struct snd_ctl_elem_value *val;
int err = 0;
val = kmalloc(sizeof(*val), GFP_KERNEL);
gctl = kmalloc(sizeof(*gctl), GFP_KERNEL);
nctl = kmalloc(sizeof(*nctl), GFP_KERNEL);
if (!val || !gctl || !nctl) {
err = -ENOMEM;
goto __error;
}
for (i = 0; i < icode->gpr_add_control_count; i++) {
if (copy_gctl(emu, gctl, icode->gpr_add_controls, i)) {
err = -EFAULT;
goto __error;
}
if (gctl->id.iface != SNDRV_CTL_ELEM_IFACE_MIXER &&
gctl->id.iface != SNDRV_CTL_ELEM_IFACE_PCM) {
err = -EINVAL;
goto __error;
}
if (! gctl->id.name[0]) {
err = -EINVAL;
goto __error;
}
ctl = snd_emu10k1_look_for_ctl(emu, &gctl->id);
memset(&knew, 0, sizeof(knew));
knew.iface = gctl->id.iface;
knew.name = gctl->id.name;
knew.index = gctl->id.index;
knew.device = gctl->id.device;
knew.subdevice = gctl->id.subdevice;
knew.info = snd_emu10k1_gpr_ctl_info;
knew.tlv.p = copy_tlv(gctl->tlv);
if (knew.tlv.p)
knew.access = SNDRV_CTL_ELEM_ACCESS_READWRITE |
SNDRV_CTL_ELEM_ACCESS_TLV_READ;
knew.get = snd_emu10k1_gpr_ctl_get;
knew.put = snd_emu10k1_gpr_ctl_put;
memset(nctl, 0, sizeof(*nctl));
nctl->vcount = gctl->vcount;
nctl->count = gctl->count;
for (j = 0; j < 32; j++) {
nctl->gpr[j] = gctl->gpr[j];
nctl->value[j] = ~gctl->value[j];
val->value.integer.value[j] = gctl->value[j];
}
nctl->min = gctl->min;
nctl->max = gctl->max;
nctl->translation = gctl->translation;
if (ctl == NULL) {
ctl = kmalloc(sizeof(*ctl), GFP_KERNEL);
if (ctl == NULL) {
err = -ENOMEM;
kfree(knew.tlv.p);
goto __error;
}
knew.private_value = (unsigned long)ctl;
*ctl = *nctl;
if ((err = snd_ctl_add(emu->card, kctl = snd_ctl_new1(&knew, emu))) < 0) {
kfree(ctl);
kfree(knew.tlv.p);
goto __error;
}
kctl->private_free = snd_emu10k1_ctl_private_free;
ctl->kcontrol = kctl;
list_add_tail(&ctl->list, &emu->fx8010.gpr_ctl);
} else {
nctl->list = ctl->list;
nctl->kcontrol = ctl->kcontrol;
*ctl = *nctl;
snd_ctl_notify(emu->card, SNDRV_CTL_EVENT_MASK_VALUE |
SNDRV_CTL_EVENT_MASK_INFO, &ctl->kcontrol->id);
}
snd_emu10k1_gpr_ctl_put(ctl->kcontrol, val);
}
__error:
kfree(nctl);
kfree(gctl);
kfree(val);
return err;
}
static int snd_emu10k1_del_controls(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
unsigned int i;
struct snd_ctl_elem_id id;
struct snd_ctl_elem_id __user *_id;
struct snd_emu10k1_fx8010_ctl *ctl;
struct snd_card *card = emu->card;
for (i = 0, _id = icode->gpr_del_controls;
i < icode->gpr_del_control_count; i++, _id++) {
if (copy_from_user(&id, _id, sizeof(id)))
return -EFAULT;
down_write(&card->controls_rwsem);
ctl = snd_emu10k1_look_for_ctl(emu, &id);
if (ctl)
snd_ctl_remove(card, ctl->kcontrol);
up_write(&card->controls_rwsem);
}
return 0;
}
static int snd_emu10k1_list_controls(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
unsigned int i = 0, j;
unsigned int total = 0;
struct snd_emu10k1_fx8010_control_gpr *gctl;
struct snd_emu10k1_fx8010_ctl *ctl;
struct snd_ctl_elem_id *id;
gctl = kmalloc(sizeof(*gctl), GFP_KERNEL);
if (! gctl)
return -ENOMEM;
list_for_each_entry(ctl, &emu->fx8010.gpr_ctl, list) {
total++;
if (icode->gpr_list_controls &&
i < icode->gpr_list_control_count) {
memset(gctl, 0, sizeof(*gctl));
id = &ctl->kcontrol->id;
gctl->id.iface = id->iface;
strlcpy(gctl->id.name, id->name, sizeof(gctl->id.name));
gctl->id.index = id->index;
gctl->id.device = id->device;
gctl->id.subdevice = id->subdevice;
gctl->vcount = ctl->vcount;
gctl->count = ctl->count;
for (j = 0; j < 32; j++) {
gctl->gpr[j] = ctl->gpr[j];
gctl->value[j] = ctl->value[j];
}
gctl->min = ctl->min;
gctl->max = ctl->max;
gctl->translation = ctl->translation;
if (copy_gctl_to_user(emu, icode->gpr_list_controls,
gctl, i)) {
kfree(gctl);
return -EFAULT;
}
i++;
}
}
icode->gpr_list_control_total = total;
kfree(gctl);
return 0;
}
static int snd_emu10k1_icode_poke(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
int err = 0;
mutex_lock(&emu->fx8010.lock);
if ((err = snd_emu10k1_verify_controls(emu, icode)) < 0)
goto __error;
strlcpy(emu->fx8010.name, icode->name, sizeof(emu->fx8010.name));
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg | A_DBG_SINGLE_STEP);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg | EMU10K1_DBG_SINGLE_STEP);
if ((err = snd_emu10k1_del_controls(emu, icode)) < 0 ||
(err = snd_emu10k1_gpr_poke(emu, icode)) < 0 ||
(err = snd_emu10k1_tram_poke(emu, icode)) < 0 ||
(err = snd_emu10k1_code_poke(emu, icode)) < 0 ||
(err = snd_emu10k1_add_controls(emu, icode)) < 0)
goto __error;
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg);
__error:
mutex_unlock(&emu->fx8010.lock);
return err;
}
static int snd_emu10k1_icode_peek(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_code *icode)
{
int err;
mutex_lock(&emu->fx8010.lock);
strlcpy(icode->name, emu->fx8010.name, sizeof(icode->name));
err = snd_emu10k1_gpr_peek(emu, icode);
if (err >= 0)
err = snd_emu10k1_tram_peek(emu, icode);
if (err >= 0)
err = snd_emu10k1_code_peek(emu, icode);
if (err >= 0)
err = snd_emu10k1_list_controls(emu, icode);
mutex_unlock(&emu->fx8010.lock);
return err;
}
static int snd_emu10k1_ipcm_poke(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_pcm_rec *ipcm)
{
unsigned int i;
int err = 0;
struct snd_emu10k1_fx8010_pcm *pcm;
if (ipcm->substream >= EMU10K1_FX8010_PCM_COUNT)
return -EINVAL;
if (ipcm->channels > 32)
return -EINVAL;
pcm = &emu->fx8010.pcm[ipcm->substream];
mutex_lock(&emu->fx8010.lock);
spin_lock_irq(&emu->reg_lock);
if (pcm->opened) {
err = -EBUSY;
goto __error;
}
if (ipcm->channels == 0) {
pcm->valid = 0;
} else {
if (ipcm->channels != 2) {
err = -EINVAL;
goto __error;
}
pcm->valid = 1;
pcm->opened = 0;
pcm->channels = ipcm->channels;
pcm->tram_start = ipcm->tram_start;
pcm->buffer_size = ipcm->buffer_size;
pcm->gpr_size = ipcm->gpr_size;
pcm->gpr_count = ipcm->gpr_count;
pcm->gpr_tmpcount = ipcm->gpr_tmpcount;
pcm->gpr_ptr = ipcm->gpr_ptr;
pcm->gpr_trigger = ipcm->gpr_trigger;
pcm->gpr_running = ipcm->gpr_running;
for (i = 0; i < pcm->channels; i++)
pcm->etram[i] = ipcm->etram[i];
}
__error:
spin_unlock_irq(&emu->reg_lock);
mutex_unlock(&emu->fx8010.lock);
return err;
}
static int snd_emu10k1_ipcm_peek(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_pcm_rec *ipcm)
{
unsigned int i;
int err = 0;
struct snd_emu10k1_fx8010_pcm *pcm;
if (ipcm->substream >= EMU10K1_FX8010_PCM_COUNT)
return -EINVAL;
pcm = &emu->fx8010.pcm[ipcm->substream];
mutex_lock(&emu->fx8010.lock);
spin_lock_irq(&emu->reg_lock);
ipcm->channels = pcm->channels;
ipcm->tram_start = pcm->tram_start;
ipcm->buffer_size = pcm->buffer_size;
ipcm->gpr_size = pcm->gpr_size;
ipcm->gpr_ptr = pcm->gpr_ptr;
ipcm->gpr_count = pcm->gpr_count;
ipcm->gpr_tmpcount = pcm->gpr_tmpcount;
ipcm->gpr_trigger = pcm->gpr_trigger;
ipcm->gpr_running = pcm->gpr_running;
for (i = 0; i < pcm->channels; i++)
ipcm->etram[i] = pcm->etram[i];
ipcm->res1 = ipcm->res2 = 0;
ipcm->pad = 0;
spin_unlock_irq(&emu->reg_lock);
mutex_unlock(&emu->fx8010.lock);
return err;
}
static void
snd_emu10k1_init_mono_control(struct snd_emu10k1_fx8010_control_gpr *ctl,
const char *name, int gpr, int defval)
{
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, name);
ctl->vcount = ctl->count = 1;
ctl->gpr[0] = gpr + 0; ctl->value[0] = defval;
if (high_res_gpr_volume) {
ctl->min = 0;
ctl->max = 0x7fffffff;
ctl->tlv = snd_emu10k1_db_linear;
ctl->translation = EMU10K1_GPR_TRANSLATION_NONE;
} else {
ctl->min = 0;
ctl->max = 100;
ctl->tlv = snd_emu10k1_db_scale1;
ctl->translation = EMU10K1_GPR_TRANSLATION_TABLE100;
}
}
static void
snd_emu10k1_init_stereo_control(struct snd_emu10k1_fx8010_control_gpr *ctl,
const char *name, int gpr, int defval)
{
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, name);
ctl->vcount = ctl->count = 2;
ctl->gpr[0] = gpr + 0; ctl->value[0] = defval;
ctl->gpr[1] = gpr + 1; ctl->value[1] = defval;
if (high_res_gpr_volume) {
ctl->min = 0;
ctl->max = 0x7fffffff;
ctl->tlv = snd_emu10k1_db_linear;
ctl->translation = EMU10K1_GPR_TRANSLATION_NONE;
} else {
ctl->min = 0;
ctl->max = 100;
ctl->tlv = snd_emu10k1_db_scale1;
ctl->translation = EMU10K1_GPR_TRANSLATION_TABLE100;
}
}
static void
snd_emu10k1_init_mono_onoff_control(struct snd_emu10k1_fx8010_control_gpr *ctl,
const char *name, int gpr, int defval)
{
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, name);
ctl->vcount = ctl->count = 1;
ctl->gpr[0] = gpr + 0; ctl->value[0] = defval;
ctl->min = 0;
ctl->max = 1;
ctl->translation = EMU10K1_GPR_TRANSLATION_ONOFF;
}
static void
snd_emu10k1_init_stereo_onoff_control(struct snd_emu10k1_fx8010_control_gpr *ctl,
const char *name, int gpr, int defval)
{
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, name);
ctl->vcount = ctl->count = 2;
ctl->gpr[0] = gpr + 0; ctl->value[0] = defval;
ctl->gpr[1] = gpr + 1; ctl->value[1] = defval;
ctl->min = 0;
ctl->max = 1;
ctl->translation = EMU10K1_GPR_TRANSLATION_ONOFF;
}
static int snd_emu10k1_audigy_dsp_convert_32_to_2x16(
struct snd_emu10k1_fx8010_code *icode,
u32 *ptr, int tmp, int bit_shifter16,
int reg_in, int reg_out)
{
A_OP(icode, ptr, iACC3, A_GPR(tmp + 1), reg_in, A_C_00000000, A_C_00000000);
A_OP(icode, ptr, iANDXOR, A_GPR(tmp), A_GPR(tmp + 1), A_GPR(bit_shifter16 - 1), A_C_00000000);
A_OP(icode, ptr, iTSTNEG, A_GPR(tmp + 2), A_GPR(tmp), A_C_80000000, A_GPR(bit_shifter16 - 2));
A_OP(icode, ptr, iANDXOR, A_GPR(tmp + 2), A_GPR(tmp + 2), A_C_80000000, A_C_00000000);
A_OP(icode, ptr, iANDXOR, A_GPR(tmp), A_GPR(tmp), A_GPR(bit_shifter16 - 3), A_C_00000000);
A_OP(icode, ptr, iMACINT0, A_GPR(tmp), A_C_00000000, A_GPR(tmp), A_C_00010000);
A_OP(icode, ptr, iANDXOR, reg_out, A_GPR(tmp), A_C_ffffffff, A_GPR(tmp + 2));
A_OP(icode, ptr, iACC3, reg_out + 1, A_GPR(tmp + 1), A_C_00000000, A_C_00000000);
return 1;
}
static int _snd_emu10k1_audigy_init_efx(struct snd_emu10k1 *emu)
{
int err, i, z, gpr, nctl;
int bit_shifter16;
const int playback = 10;
const int capture = playback + (SND_EMU10K1_PLAYBACK_CHANNELS * 2);
const int stereo_mix = capture + 2;
const int tmp = 0x88;
u32 ptr;
struct snd_emu10k1_fx8010_code *icode = NULL;
struct snd_emu10k1_fx8010_control_gpr *controls = NULL, *ctl;
u32 *gpr_map;
mm_segment_t seg;
if ((icode = kzalloc(sizeof(*icode), GFP_KERNEL)) == NULL ||
(icode->gpr_map = (u_int32_t __user *)
kcalloc(512 + 256 + 256 + 2 * 1024, sizeof(u_int32_t),
GFP_KERNEL)) == NULL ||
(controls = kcalloc(SND_EMU10K1_GPR_CONTROLS,
sizeof(*controls), GFP_KERNEL)) == NULL) {
err = -ENOMEM;
goto __err;
}
gpr_map = (u32 __force *)icode->gpr_map;
icode->tram_data_map = icode->gpr_map + 512;
icode->tram_addr_map = icode->tram_data_map + 256;
icode->code = icode->tram_addr_map + 256;
for (i = 0; i < 512; i++)
set_bit(i, icode->gpr_valid);
for (i = 0; i < 256; i++)
set_bit(i, icode->tram_valid);
strcpy(icode->name, "Audigy DSP code for ALSA");
ptr = 0;
nctl = 0;
gpr = stereo_mix + 10;
gpr_map[gpr++] = 0x00007fff;
gpr_map[gpr++] = 0x00008000;
gpr_map[gpr++] = 0x0000ffff;
bit_shifter16 = gpr;
snd_emu10k1_ptr_write(emu, A_DBG, 0, (emu->fx8010.dbg = 0) | A_DBG_SINGLE_STEP);
#if 1
A_OP(icode, &ptr, iMAC0, A_GPR(playback), A_C_00000000, A_GPR(gpr), A_FXBUS(FXBUS_PCM_LEFT_FRONT));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+1), A_C_00000000, A_GPR(gpr+1), A_FXBUS(FXBUS_PCM_RIGHT_FRONT));
snd_emu10k1_init_stereo_control(&controls[nctl++], "PCM Front Playback Volume", gpr, 100);
gpr += 2;
A_OP(icode, &ptr, iMAC0, A_GPR(playback+2), A_C_00000000, A_GPR(gpr), A_FXBUS(FXBUS_PCM_LEFT_REAR));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+3), A_C_00000000, A_GPR(gpr+1), A_FXBUS(FXBUS_PCM_RIGHT_REAR));
snd_emu10k1_init_stereo_control(&controls[nctl++], "PCM Surround Playback Volume", gpr, 100);
gpr += 2;
if (emu->card_capabilities->spk71) {
A_OP(icode, &ptr, iMAC0, A_GPR(playback+6), A_C_00000000, A_GPR(gpr), A_FXBUS(FXBUS_PCM_LEFT_SIDE));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+7), A_C_00000000, A_GPR(gpr+1), A_FXBUS(FXBUS_PCM_RIGHT_SIDE));
snd_emu10k1_init_stereo_control(&controls[nctl++], "PCM Side Playback Volume", gpr, 100);
gpr += 2;
}
A_OP(icode, &ptr, iMAC0, A_GPR(playback+4), A_C_00000000, A_GPR(gpr), A_FXBUS(FXBUS_PCM_CENTER));
snd_emu10k1_init_mono_control(&controls[nctl++], "PCM Center Playback Volume", gpr, 100);
gpr++;
A_OP(icode, &ptr, iMAC0, A_GPR(playback+5), A_C_00000000, A_GPR(gpr), A_FXBUS(FXBUS_PCM_LFE));
snd_emu10k1_init_mono_control(&controls[nctl++], "PCM LFE Playback Volume", gpr, 100);
gpr++;
A_OP(icode, &ptr, iMAC0, A_GPR(stereo_mix), A_C_00000000, A_GPR(gpr), A_FXBUS(FXBUS_PCM_LEFT));
A_OP(icode, &ptr, iMAC0, A_GPR(stereo_mix+1), A_C_00000000, A_GPR(gpr+1), A_FXBUS(FXBUS_PCM_RIGHT));
snd_emu10k1_init_stereo_control(&controls[nctl++], "Wave Playback Volume", gpr, 100);
gpr += 2;
A_OP(icode, &ptr, iMAC0, A_GPR(stereo_mix+0), A_GPR(stereo_mix+0), A_GPR(gpr), A_FXBUS(FXBUS_MIDI_LEFT));
A_OP(icode, &ptr, iMAC0, A_GPR(stereo_mix+1), A_GPR(stereo_mix+1), A_GPR(gpr+1), A_FXBUS(FXBUS_MIDI_RIGHT));
snd_emu10k1_init_stereo_control(&controls[nctl++], "Synth Playback Volume", gpr, 100);
gpr += 2;
A_OP(icode, &ptr, iMAC0, A_GPR(capture+0), A_C_00000000, A_GPR(gpr), A_FXBUS(FXBUS_PCM_LEFT));
A_OP(icode, &ptr, iMAC0, A_GPR(capture+1), A_C_00000000, A_GPR(gpr+1), A_FXBUS(FXBUS_PCM_RIGHT));
snd_emu10k1_init_stereo_control(&controls[nctl++], "PCM Capture Volume", gpr, 0);
gpr += 2;
A_OP(icode, &ptr, iMAC0, A_GPR(capture+0), A_GPR(capture+0), A_GPR(gpr), A_FXBUS(FXBUS_MIDI_LEFT));
A_OP(icode, &ptr, iMAC0, A_GPR(capture+1), A_GPR(capture+1), A_GPR(gpr+1), A_FXBUS(FXBUS_MIDI_RIGHT));
snd_emu10k1_init_stereo_control(&controls[nctl++], "Synth Capture Volume", gpr, 0);
gpr += 2;
#define A_ADD_VOLUME_IN(var,vol,input) \
A_OP(icode, &ptr, iMAC0, A_GPR(var), A_GPR(var), A_GPR(vol), A_EXTIN(input))
if (emu->card_capabilities->emu_model) {
if (emu->card_capabilities->ca0108_chip) {
A_OP(icode, &ptr, iMACINT0, A_GPR(tmp), A_C_00000000, A3_EMU32IN(0x0), A_C_00000001);
A_OP(icode, &ptr, iMAC0, A_GPR(capture+0), A_GPR(capture+0), A_GPR(gpr), A_GPR(tmp));
A_OP(icode, &ptr, iMACINT0, A_GPR(tmp), A_C_00000000, A3_EMU32IN(0x1), A_C_00000001);
A_OP(icode, &ptr, iMAC0, A_GPR(capture+1), A_GPR(capture+1), A_GPR(gpr), A_GPR(tmp));
} else {
A_OP(icode, &ptr, iMAC0, A_GPR(capture+0), A_GPR(capture+0), A_GPR(gpr), A_P16VIN(0x0));
A_OP(icode, &ptr, iMAC0, A_GPR(capture+1), A_GPR(capture+1), A_GPR(gpr+1), A_P16VIN(0x1));
}
snd_emu10k1_init_stereo_control(&controls[nctl++], "EMU Capture Volume", gpr, 0);
gpr += 2;
}
A_ADD_VOLUME_IN(stereo_mix, gpr, A_EXTIN_AC97_L);
A_ADD_VOLUME_IN(stereo_mix+1, gpr+1, A_EXTIN_AC97_R);
snd_emu10k1_init_stereo_control(&controls[nctl++], "AMic Playback Volume", gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(capture, gpr, A_EXTIN_AC97_L);
A_ADD_VOLUME_IN(capture+1, gpr+1, A_EXTIN_AC97_R);
snd_emu10k1_init_stereo_control(&controls[nctl++], "Mic Capture Volume", gpr, 0);
gpr += 2;
A_OP(icode, &ptr, iINTERP, A_EXTOUT(A_EXTOUT_MIC_CAP), A_EXTIN(A_EXTIN_AC97_L), 0xcd, A_EXTIN(A_EXTIN_AC97_R));
A_ADD_VOLUME_IN(stereo_mix, gpr, A_EXTIN_SPDIF_CD_L);
A_ADD_VOLUME_IN(stereo_mix+1, gpr+1, A_EXTIN_SPDIF_CD_R);
snd_emu10k1_init_stereo_control(&controls[nctl++],
emu->card_capabilities->ac97_chip ? "Audigy CD Playback Volume" : "CD Playback Volume",
gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(capture, gpr, A_EXTIN_SPDIF_CD_L);
A_ADD_VOLUME_IN(capture+1, gpr+1, A_EXTIN_SPDIF_CD_R);
snd_emu10k1_init_stereo_control(&controls[nctl++],
emu->card_capabilities->ac97_chip ? "Audigy CD Capture Volume" : "CD Capture Volume",
gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(stereo_mix, gpr, A_EXTIN_OPT_SPDIF_L);
A_ADD_VOLUME_IN(stereo_mix+1, gpr+1, A_EXTIN_OPT_SPDIF_R);
snd_emu10k1_init_stereo_control(&controls[nctl++], SNDRV_CTL_NAME_IEC958("Optical ",PLAYBACK,VOLUME), gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(capture, gpr, A_EXTIN_OPT_SPDIF_L);
A_ADD_VOLUME_IN(capture+1, gpr+1, A_EXTIN_OPT_SPDIF_R);
snd_emu10k1_init_stereo_control(&controls[nctl++], SNDRV_CTL_NAME_IEC958("Optical ",CAPTURE,VOLUME), gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(stereo_mix, gpr, A_EXTIN_LINE2_L);
A_ADD_VOLUME_IN(stereo_mix+1, gpr+1, A_EXTIN_LINE2_R);
snd_emu10k1_init_stereo_control(&controls[nctl++],
emu->card_capabilities->ac97_chip ? "Line2 Playback Volume" : "Line Playback Volume",
gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(capture, gpr, A_EXTIN_LINE2_L);
A_ADD_VOLUME_IN(capture+1, gpr+1, A_EXTIN_LINE2_R);
snd_emu10k1_init_stereo_control(&controls[nctl++],
emu->card_capabilities->ac97_chip ? "Line2 Capture Volume" : "Line Capture Volume",
gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(stereo_mix, gpr, A_EXTIN_ADC_L);
A_ADD_VOLUME_IN(stereo_mix+1, gpr+1, A_EXTIN_ADC_R);
snd_emu10k1_init_stereo_control(&controls[nctl++], "Analog Mix Playback Volume", gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(capture, gpr, A_EXTIN_ADC_L);
A_ADD_VOLUME_IN(capture+1, gpr+1, A_EXTIN_ADC_R);
snd_emu10k1_init_stereo_control(&controls[nctl++], "Analog Mix Capture Volume", gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(stereo_mix, gpr, A_EXTIN_AUX2_L);
A_ADD_VOLUME_IN(stereo_mix+1, gpr+1, A_EXTIN_AUX2_R);
snd_emu10k1_init_stereo_control(&controls[nctl++],
emu->card_capabilities->ac97_chip ? "Aux2 Playback Volume" : "Aux Playback Volume",
gpr, 0);
gpr += 2;
A_ADD_VOLUME_IN(capture, gpr, A_EXTIN_AUX2_L);
A_ADD_VOLUME_IN(capture+1, gpr+1, A_EXTIN_AUX2_R);
snd_emu10k1_init_stereo_control(&controls[nctl++],
emu->card_capabilities->ac97_chip ? "Aux2 Capture Volume" : "Aux Capture Volume",
gpr, 0);
gpr += 2;
A_OP(icode, &ptr, iMAC0, A_GPR(playback), A_GPR(playback), A_GPR(gpr), A_GPR(stereo_mix));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+1), A_GPR(playback+1), A_GPR(gpr+1), A_GPR(stereo_mix+1));
snd_emu10k1_init_stereo_control(&controls[nctl++], "Front Playback Volume", gpr, 100);
gpr += 2;
A_OP(icode, &ptr, iMAC0, A_GPR(playback+2), A_GPR(playback+2), A_GPR(gpr), A_GPR(stereo_mix));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+3), A_GPR(playback+3), A_GPR(gpr+1), A_GPR(stereo_mix+1));
snd_emu10k1_init_stereo_control(&controls[nctl++], "Surround Playback Volume", gpr, 0);
gpr += 2;
A_OP(icode, &ptr, iINTERP, A_GPR(tmp), A_GPR(stereo_mix), 0xcd, A_GPR(stereo_mix+1));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+4), A_GPR(playback+4), A_GPR(gpr), A_GPR(tmp));
snd_emu10k1_init_mono_control(&controls[nctl++], "Center Playback Volume", gpr, 0);
gpr++;
A_OP(icode, &ptr, iMAC0, A_GPR(playback+5), A_GPR(playback+5), A_GPR(gpr), A_GPR(tmp));
snd_emu10k1_init_mono_control(&controls[nctl++], "LFE Playback Volume", gpr, 0);
gpr++;
if (emu->card_capabilities->spk71) {
A_OP(icode, &ptr, iMAC0, A_GPR(playback+6), A_GPR(playback+6), A_GPR(gpr), A_GPR(stereo_mix));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+7), A_GPR(playback+7), A_GPR(gpr+1), A_GPR(stereo_mix+1));
snd_emu10k1_init_stereo_control(&controls[nctl++], "Side Playback Volume", gpr, 0);
gpr += 2;
}
#define A_PUT_OUTPUT(out,src) A_OP(icode, &ptr, iACC3, A_EXTOUT(out), A_C_00000000, A_C_00000000, A_GPR(src))
#define A_PUT_STEREO_OUTPUT(out1,out2,src) \
{A_PUT_OUTPUT(out1,src); A_PUT_OUTPUT(out2,src+1);}
#define _A_SWITCH(icode, ptr, dst, src, sw) \
A_OP((icode), ptr, iMACINT0, dst, A_C_00000000, src, sw);
#define A_SWITCH(icode, ptr, dst, src, sw) \
_A_SWITCH(icode, ptr, A_GPR(dst), A_GPR(src), A_GPR(sw))
#define _A_SWITCH_NEG(icode, ptr, dst, src) \
A_OP((icode), ptr, iANDXOR, dst, src, A_C_00000001, A_C_00000001);
#define A_SWITCH_NEG(icode, ptr, dst, src) \
_A_SWITCH_NEG(icode, ptr, A_GPR(dst), A_GPR(src))
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 0), A_GPR(playback + 0), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 1), A_GPR(playback + 1), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 2), A_GPR(playback + 2), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 3), A_GPR(playback + 3), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 4), A_GPR(playback + 4), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 5), A_GPR(playback + 5), A_C_00000000, A_C_00000000);
if (emu->card_capabilities->spk71) {
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 6), A_GPR(playback + 6), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 7), A_GPR(playback + 7), A_C_00000000, A_C_00000000);
}
ctl = &controls[nctl + 0];
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, "Tone Control - Bass");
ctl->vcount = 2;
ctl->count = 10;
ctl->min = 0;
ctl->max = 40;
ctl->value[0] = ctl->value[1] = 20;
ctl->translation = EMU10K1_GPR_TRANSLATION_BASS;
ctl = &controls[nctl + 1];
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, "Tone Control - Treble");
ctl->vcount = 2;
ctl->count = 10;
ctl->min = 0;
ctl->max = 40;
ctl->value[0] = ctl->value[1] = 20;
ctl->translation = EMU10K1_GPR_TRANSLATION_TREBLE;
#define BASS_GPR 0x8c
#define TREBLE_GPR 0x96
for (z = 0; z < 5; z++) {
int j;
for (j = 0; j < 2; j++) {
controls[nctl + 0].gpr[z * 2 + j] = BASS_GPR + z * 2 + j;
controls[nctl + 1].gpr[z * 2 + j] = TREBLE_GPR + z * 2 + j;
}
}
for (z = 0; z < 4; z++) {
int j, k, l, d;
for (j = 0; j < 2; j++) {
k = 0xb0 + (z * 8) + (j * 4);
l = 0xe0 + (z * 8) + (j * 4);
d = playback + SND_EMU10K1_PLAYBACK_CHANNELS + z * 2 + j;
A_OP(icode, &ptr, iMAC0, A_C_00000000, A_C_00000000, A_GPR(d), A_GPR(BASS_GPR + 0 + j));
A_OP(icode, &ptr, iMACMV, A_GPR(k+1), A_GPR(k), A_GPR(k+1), A_GPR(BASS_GPR + 4 + j));
A_OP(icode, &ptr, iMACMV, A_GPR(k), A_GPR(d), A_GPR(k), A_GPR(BASS_GPR + 2 + j));
A_OP(icode, &ptr, iMACMV, A_GPR(k+3), A_GPR(k+2), A_GPR(k+3), A_GPR(BASS_GPR + 8 + j));
A_OP(icode, &ptr, iMAC0, A_GPR(k+2), A_GPR_ACCU, A_GPR(k+2), A_GPR(BASS_GPR + 6 + j));
A_OP(icode, &ptr, iACC3, A_GPR(k+2), A_GPR(k+2), A_GPR(k+2), A_C_00000000);
A_OP(icode, &ptr, iMAC0, A_C_00000000, A_C_00000000, A_GPR(k+2), A_GPR(TREBLE_GPR + 0 + j));
A_OP(icode, &ptr, iMACMV, A_GPR(l+1), A_GPR(l), A_GPR(l+1), A_GPR(TREBLE_GPR + 4 + j));
A_OP(icode, &ptr, iMACMV, A_GPR(l), A_GPR(k+2), A_GPR(l), A_GPR(TREBLE_GPR + 2 + j));
A_OP(icode, &ptr, iMACMV, A_GPR(l+3), A_GPR(l+2), A_GPR(l+3), A_GPR(TREBLE_GPR + 8 + j));
A_OP(icode, &ptr, iMAC0, A_GPR(l+2), A_GPR_ACCU, A_GPR(l+2), A_GPR(TREBLE_GPR + 6 + j));
A_OP(icode, &ptr, iMACINT0, A_GPR(l+2), A_C_00000000, A_GPR(l+2), A_C_00000010);
A_OP(icode, &ptr, iACC3, A_GPR(d), A_GPR(l+2), A_C_00000000, A_C_00000000);
if (z == 2)
break;
}
}
nctl += 2;
#undef BASS_GPR
#undef TREBLE_GPR
for (z = 0; z < 8; z++) {
A_SWITCH(icode, &ptr, tmp + 0, playback + SND_EMU10K1_PLAYBACK_CHANNELS + z, gpr + 0);
A_SWITCH_NEG(icode, &ptr, tmp + 1, gpr + 0);
A_SWITCH(icode, &ptr, tmp + 1, playback + z, tmp + 1);
A_OP(icode, &ptr, iACC3, A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + z), A_GPR(tmp + 0), A_GPR(tmp + 1), A_C_00000000);
}
snd_emu10k1_init_stereo_onoff_control(controls + nctl++, "Tone Control - Switch", gpr, 0);
gpr += 2;
A_OP(icode, &ptr, iMAC0, A_GPR(playback+0+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+0+SND_EMU10K1_PLAYBACK_CHANNELS));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+1+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+1+SND_EMU10K1_PLAYBACK_CHANNELS));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+2+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+2+SND_EMU10K1_PLAYBACK_CHANNELS));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+3+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+3+SND_EMU10K1_PLAYBACK_CHANNELS));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+4+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+4+SND_EMU10K1_PLAYBACK_CHANNELS));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+5+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+5+SND_EMU10K1_PLAYBACK_CHANNELS));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+6+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+6+SND_EMU10K1_PLAYBACK_CHANNELS));
A_OP(icode, &ptr, iMAC0, A_GPR(playback+7+SND_EMU10K1_PLAYBACK_CHANNELS), A_C_00000000, A_GPR(gpr), A_GPR(playback+7+SND_EMU10K1_PLAYBACK_CHANNELS));
snd_emu10k1_init_mono_control(&controls[nctl++], "Wave Master Playback Volume", gpr, 0);
gpr += 2;
A_PUT_STEREO_OUTPUT(A_EXTOUT_AFRONT_L, A_EXTOUT_AFRONT_R, playback + SND_EMU10K1_PLAYBACK_CHANNELS);
A_PUT_STEREO_OUTPUT(A_EXTOUT_AREAR_L, A_EXTOUT_AREAR_R, playback+2 + SND_EMU10K1_PLAYBACK_CHANNELS);
A_PUT_OUTPUT(A_EXTOUT_ACENTER, playback+4 + SND_EMU10K1_PLAYBACK_CHANNELS);
A_PUT_OUTPUT(A_EXTOUT_ALFE, playback+5 + SND_EMU10K1_PLAYBACK_CHANNELS);
if (emu->card_capabilities->spk71)
A_PUT_STEREO_OUTPUT(A_EXTOUT_ASIDE_L, A_EXTOUT_ASIDE_R, playback+6 + SND_EMU10K1_PLAYBACK_CHANNELS);
A_PUT_STEREO_OUTPUT(A_EXTOUT_HEADPHONE_L, A_EXTOUT_HEADPHONE_R, playback + SND_EMU10K1_PLAYBACK_CHANNELS);
if (emu->card_capabilities->emu_model) {
snd_printk(KERN_INFO "EMU outputs on\n");
for (z = 0; z < 8; z++) {
if (emu->card_capabilities->ca0108_chip) {
A_OP(icode, &ptr, iACC3, A3_EMU32OUT(z), A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + z), A_C_00000000, A_C_00000000);
} else {
A_OP(icode, &ptr, iACC3, A_EMU32OUTL(z), A_GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + z), A_C_00000000, A_C_00000000);
}
}
}
gpr_map[gpr++] = 0;
gpr_map[gpr++] = 0x1008;
gpr_map[gpr++] = 0xffff0000;
for (z = 0; z < 2; z++) {
A_OP(icode, &ptr, iMAC0, A_GPR(tmp + 2), A_FXBUS(FXBUS_PT_LEFT + z), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iSKIP, A_GPR_COND, A_GPR_COND, A_GPR(gpr - 2), A_C_00000001);
A_OP(icode, &ptr, iACC3, A_GPR(tmp + 2), A_C_00000000, A_C_00010000, A_GPR(tmp + 2));
A_OP(icode, &ptr, iANDXOR, A_GPR(tmp + 2), A_GPR(tmp + 2), A_GPR(gpr - 1), A_C_00000000);
A_SWITCH(icode, &ptr, tmp + 0, tmp + 2, gpr + z);
A_SWITCH_NEG(icode, &ptr, tmp + 1, gpr + z);
A_SWITCH(icode, &ptr, tmp + 1, playback + SND_EMU10K1_PLAYBACK_CHANNELS + z, tmp + 1);
if ((z==1) && (emu->card_capabilities->spdif_bug)) {
snd_printk(KERN_INFO "Installing spdif_bug patch: %s\n", emu->card_capabilities->name);
A_OP(icode, &ptr, iACC3, A_EXTOUT(A_EXTOUT_FRONT_L + z), A_GPR(gpr - 3), A_C_00000000, A_C_00000000);
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 3), A_GPR(tmp + 0), A_GPR(tmp + 1), A_C_00000000);
} else {
A_OP(icode, &ptr, iACC3, A_EXTOUT(A_EXTOUT_FRONT_L + z), A_GPR(tmp + 0), A_GPR(tmp + 1), A_C_00000000);
}
}
snd_emu10k1_init_stereo_onoff_control(controls + nctl++, SNDRV_CTL_NAME_IEC958("Optical Raw ",PLAYBACK,SWITCH), gpr, 0);
gpr += 2;
A_PUT_STEREO_OUTPUT(A_EXTOUT_REAR_L, A_EXTOUT_REAR_R, playback+2 + SND_EMU10K1_PLAYBACK_CHANNELS);
A_PUT_OUTPUT(A_EXTOUT_CENTER, playback+4 + SND_EMU10K1_PLAYBACK_CHANNELS);
A_PUT_OUTPUT(A_EXTOUT_LFE, playback+5 + SND_EMU10K1_PLAYBACK_CHANNELS);
#ifdef EMU10K1_CAPTURE_DIGITAL_OUT
A_PUT_STEREO_OUTPUT(A_EXTOUT_ADC_CAP_L, A_EXTOUT_ADC_CAP_R, playback + SND_EMU10K1_PLAYBACK_CHANNELS);
#else
A_PUT_OUTPUT(A_EXTOUT_ADC_CAP_L, capture);
A_PUT_OUTPUT(A_EXTOUT_ADC_CAP_R, capture+1);
#endif
if (emu->card_capabilities->emu_model) {
if (emu->card_capabilities->ca0108_chip) {
snd_printk(KERN_INFO "EMU2 inputs on\n");
for (z = 0; z < 0x10; z++) {
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp,
bit_shifter16,
A3_EMU32IN(z),
A_FXBUS2(z*2) );
}
} else {
snd_printk(KERN_INFO "EMU inputs on\n");
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_P16VIN(0x0), A_FXBUS2(0) );
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_GPR(gpr - 1), A_FXBUS2(2) );
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x1), A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_GPR(gpr - 1), A_FXBUS2(4) );
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x2), A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_GPR(gpr - 1), A_FXBUS2(6) );
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x3), A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_GPR(gpr - 1), A_FXBUS2(0x8) );
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x4), A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_GPR(gpr - 1), A_FXBUS2(0xa) );
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x5), A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_GPR(gpr - 1), A_FXBUS2(0xc) );
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x6), A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16( icode, &ptr, tmp, bit_shifter16, A_GPR(gpr - 1), A_FXBUS2(0xe) );
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x7), A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x10));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x8),
A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x12));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0x9),
A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x14));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0xa),
A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x16));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0xb),
A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x18));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0xc),
A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x1a));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0xd),
A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x1c));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0xe),
A_C_00000000, A_C_00000000);
gpr_map[gpr++] = 0x00000000;
snd_emu10k1_audigy_dsp_convert_32_to_2x16(icode, &ptr, tmp,
bit_shifter16,
A_GPR(gpr - 1),
A_FXBUS2(0x1e));
A_OP(icode, &ptr, iACC3, A_GPR(gpr - 1), A_P16VIN(0xf),
A_C_00000000, A_C_00000000);
}
#if 0
for (z = 4; z < 8; z++) {
A_OP(icode, &ptr, iACC3, A_FXBUS2(z), A_C_00000000, A_C_00000000, A_C_00000000);
}
for (z = 0xc; z < 0x10; z++) {
A_OP(icode, &ptr, iACC3, A_FXBUS2(z), A_C_00000000, A_C_00000000, A_C_00000000);
}
#endif
} else {
for (z = 0; z < 16; z++) {
A_OP(icode, &ptr, iACC3, A_FXBUS2(z), A_C_00000000, A_C_00000000, A_EXTIN(z));
}
}
#endif
if (gpr > tmp) {
snd_BUG();
err = -EIO;
goto __err;
}
while (ptr < 0x400)
A_OP(icode, &ptr, 0x0f, 0xc0, 0xc0, 0xcf, 0xc0);
seg = snd_enter_user();
icode->gpr_add_control_count = nctl;
icode->gpr_add_controls = (struct snd_emu10k1_fx8010_control_gpr __user *)controls;
emu->support_tlv = 1;
err = snd_emu10k1_icode_poke(emu, icode);
emu->support_tlv = 0;
snd_leave_user(seg);
__err:
kfree(controls);
if (icode != NULL) {
kfree((void __force *)icode->gpr_map);
kfree(icode);
}
return err;
}
static void _volume(struct snd_emu10k1_fx8010_code *icode, u32 *ptr, u32 dst, u32 src, u32 vol)
{
OP(icode, ptr, iMAC0, dst, C_00000000, src, vol);
OP(icode, ptr, iANDXOR, C_00000000, vol, C_ffffffff, C_7fffffff);
OP(icode, ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_NONZERO, C_00000001);
OP(icode, ptr, iACC3, dst, src, C_00000000, C_00000000);
}
static void _volume_add(struct snd_emu10k1_fx8010_code *icode, u32 *ptr, u32 dst, u32 src, u32 vol)
{
OP(icode, ptr, iANDXOR, C_00000000, vol, C_ffffffff, C_7fffffff);
OP(icode, ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_NONZERO, C_00000002);
OP(icode, ptr, iMACINT0, dst, dst, src, C_00000001);
OP(icode, ptr, iSKIP, C_00000000, C_7fffffff, C_7fffffff, C_00000001);
OP(icode, ptr, iMAC0, dst, dst, src, vol);
}
static void _volume_out(struct snd_emu10k1_fx8010_code *icode, u32 *ptr, u32 dst, u32 src, u32 vol)
{
OP(icode, ptr, iANDXOR, C_00000000, vol, C_ffffffff, C_7fffffff);
OP(icode, ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_NONZERO, C_00000002);
OP(icode, ptr, iACC3, dst, src, C_00000000, C_00000000);
OP(icode, ptr, iSKIP, C_00000000, C_7fffffff, C_7fffffff, C_00000001);
OP(icode, ptr, iMAC0, dst, C_00000000, src, vol);
}
static int _snd_emu10k1_init_efx(struct snd_emu10k1 *emu)
{
int err, i, z, gpr, tmp, playback, capture;
u32 ptr;
struct snd_emu10k1_fx8010_code *icode;
struct snd_emu10k1_fx8010_pcm_rec *ipcm = NULL;
struct snd_emu10k1_fx8010_control_gpr *controls = NULL, *ctl;
u32 *gpr_map;
mm_segment_t seg;
if ((icode = kzalloc(sizeof(*icode), GFP_KERNEL)) == NULL)
return -ENOMEM;
if ((icode->gpr_map = (u_int32_t __user *)
kcalloc(256 + 160 + 160 + 2 * 512, sizeof(u_int32_t),
GFP_KERNEL)) == NULL ||
(controls = kcalloc(SND_EMU10K1_GPR_CONTROLS,
sizeof(struct snd_emu10k1_fx8010_control_gpr),
GFP_KERNEL)) == NULL ||
(ipcm = kzalloc(sizeof(*ipcm), GFP_KERNEL)) == NULL) {
err = -ENOMEM;
goto __err;
}
gpr_map = (u32 __force *)icode->gpr_map;
icode->tram_data_map = icode->gpr_map + 256;
icode->tram_addr_map = icode->tram_data_map + 160;
icode->code = icode->tram_addr_map + 160;
for (i = 0; i < 256; i++)
set_bit(i, icode->gpr_valid);
for (i = 0; i < 160; i++)
set_bit(i, icode->tram_valid);
strcpy(icode->name, "SB Live! FX8010 code for ALSA v1.2 by Jaroslav Kysela");
ptr = 0; i = 0;
playback = SND_EMU10K1_INPUTS;
capture = playback + (SND_EMU10K1_PLAYBACK_CHANNELS * 2);
gpr = capture + SND_EMU10K1_CAPTURE_CHANNELS;
tmp = 0x88;
snd_emu10k1_ptr_write(emu, DBG, 0, (emu->fx8010.dbg = 0) | EMU10K1_DBG_SINGLE_STEP);
OP(icode, &ptr, iMACINT0, GPR(0), C_00000000, FXBUS(FXBUS_PCM_LEFT), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(1), C_00000000, FXBUS(FXBUS_PCM_RIGHT), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(2), C_00000000, FXBUS(FXBUS_MIDI_LEFT), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(3), C_00000000, FXBUS(FXBUS_MIDI_RIGHT), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(4), C_00000000, FXBUS(FXBUS_PCM_LEFT_REAR), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(5), C_00000000, FXBUS(FXBUS_PCM_RIGHT_REAR), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(6), C_00000000, FXBUS(FXBUS_PCM_CENTER), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(7), C_00000000, FXBUS(FXBUS_PCM_LFE), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(8), C_00000000, C_00000000, C_00000000);
OP(icode, &ptr, iMACINT0, GPR(9), C_00000000, C_00000000, C_00000000);
OP(icode, &ptr, iMACINT0, GPR(10), C_00000000, FXBUS(FXBUS_PCM_LEFT_FRONT), C_00000004);
OP(icode, &ptr, iMACINT0, GPR(11), C_00000000, FXBUS(FXBUS_PCM_RIGHT_FRONT), C_00000004);
ipcm->substream = 0;
ipcm->channels = 2;
ipcm->tram_start = 0;
ipcm->buffer_size = (64 * 1024) / 2;
ipcm->gpr_size = gpr++;
ipcm->gpr_ptr = gpr++;
ipcm->gpr_count = gpr++;
ipcm->gpr_tmpcount = gpr++;
ipcm->gpr_trigger = gpr++;
ipcm->gpr_running = gpr++;
ipcm->etram[0] = 0;
ipcm->etram[1] = 1;
gpr_map[gpr + 0] = 0xfffff000;
gpr_map[gpr + 1] = 0xffff0000;
gpr_map[gpr + 2] = 0x70000000;
gpr_map[gpr + 3] = 0x00000007;
gpr_map[gpr + 4] = 0x001f << 11;
gpr_map[gpr + 5] = 0x001c << 11;
gpr_map[gpr + 6] = (0x22 - 0x01) - 1;
gpr_map[gpr + 7] = (0x22 - 0x06) - 1;
gpr_map[gpr + 8] = 0x2000000 + (2<<11);
gpr_map[gpr + 9] = 0x4000000 + (2<<11);
gpr_map[gpr + 10] = 1<<11;
gpr_map[gpr + 11] = (0x24 - 0x0a) - 1;
gpr_map[gpr + 12] = 0;
OP(icode, &ptr, iMAC0, C_00000000, GPR(ipcm->gpr_trigger), C_00000000, C_00000000);
OP(icode, &ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_ZERO, GPR(gpr + 6));
OP(icode, &ptr, iMAC0, C_00000000, GPR(ipcm->gpr_running), C_00000000, C_00000000);
OP(icode, &ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_NONZERO, C_00000004);
OP(icode, &ptr, iANDXOR, GPR(tmp + 0), GPR_DBAC, GPR(gpr + 4), C_00000000);
OP(icode, &ptr, iMACINT0, C_00000000, GPR(tmp + 0), C_ffffffff, GPR(gpr + 5));
OP(icode, &ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_NONZERO, GPR(gpr + 7));
OP(icode, &ptr, iACC3, GPR(gpr + 12), C_00000010, C_00000001, C_00000000);
OP(icode, &ptr, iANDXOR, GPR(ipcm->gpr_running), GPR(ipcm->gpr_running), C_00000000, C_00000001);
OP(icode, &ptr, iACC3, GPR(gpr + 12), GPR(gpr + 12), C_ffffffff, C_00000000);
OP(icode, &ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_NONZERO, GPR(gpr + 11));
OP(icode, &ptr, iACC3, GPR(gpr + 12), C_00000001, C_00000000, C_00000000);
OP(icode, &ptr, iANDXOR, GPR(tmp + 0), ETRAM_DATA(ipcm->etram[0]), GPR(gpr + 0), C_00000000);
OP(icode, &ptr, iLOG, GPR(tmp + 0), GPR(tmp + 0), GPR(gpr + 3), C_00000000);
OP(icode, &ptr, iANDXOR, GPR(8), GPR(tmp + 0), GPR(gpr + 1), GPR(gpr + 2));
OP(icode, &ptr, iSKIP, C_00000000, GPR_COND, CC_REG_MINUS, C_00000001);
OP(icode, &ptr, iANDXOR, GPR(8), GPR(8), GPR(gpr + 1), GPR(gpr + 2));
OP(icode, &ptr, iANDXOR, GPR(tmp + 0), ETRAM_DATA(ipcm->etram[1]), GPR(gpr + 0), C_00000000);
OP(icode, &ptr, iLOG, GPR(tmp + 0), GPR(tmp + 0), GPR(gpr + 3), C_00000000);
OP(icode, &ptr, iANDXOR, GPR(9), GPR(tmp + 0), GPR(gpr + 1), GPR(gpr + 2));
OP(icode, &ptr, iSKIP, C_00000000, GPR_COND, CC_REG_MINUS, C_00000001);
OP(icode, &ptr, iANDXOR, GPR(9), GPR(9), GPR(gpr + 1), GPR(gpr + 2));
OP(icode, &ptr, iACC3, GPR(tmp + 0), GPR(ipcm->gpr_ptr), C_00000001, C_00000000);
OP(icode, &ptr, iMACINT0, C_00000000, GPR(tmp + 0), C_ffffffff, GPR(ipcm->gpr_size));
OP(icode, &ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_MINUS, C_00000001);
OP(icode, &ptr, iACC3, GPR(tmp + 0), C_00000000, C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR(ipcm->gpr_ptr), GPR(tmp + 0), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR(ipcm->gpr_tmpcount), GPR(ipcm->gpr_tmpcount), C_ffffffff, C_00000000);
OP(icode, &ptr, iSKIP, GPR_COND, GPR_COND, CC_REG_NONZERO, C_00000002);
OP(icode, &ptr, iACC3, GPR(ipcm->gpr_tmpcount), GPR(ipcm->gpr_count), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR_IRQ, C_80000000, C_00000000, C_00000000);
OP(icode, &ptr, iANDXOR, GPR(ipcm->gpr_running), GPR(ipcm->gpr_running), C_00000001, C_00010000);
OP(icode, &ptr, iANDXOR, GPR(ipcm->gpr_running), GPR(ipcm->gpr_running), C_00010000, C_00000001);
OP(icode, &ptr, iSKIP, C_00000000, C_7fffffff, C_7fffffff, C_00000002);
OP(icode, &ptr, iMACINT1, ETRAM_ADDR(ipcm->etram[0]), GPR(gpr + 8), GPR_DBAC, C_ffffffff);
OP(icode, &ptr, iMACINT1, ETRAM_ADDR(ipcm->etram[1]), GPR(gpr + 9), GPR_DBAC, C_ffffffff);
gpr += 13;
for (z = 0; z < 2; z++)
VOLUME(icode, &ptr, playback + z, z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Wave Playback Volume", gpr, 100);
gpr += 2;
for (z = 0; z < 2; z++)
VOLUME(icode, &ptr, playback + 2 + z, z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Wave Surround Playback Volume", gpr, 0);
gpr += 2;
OP(icode, &ptr, iACC3, GPR(tmp + 0), FXBUS(FXBUS_PCM_LEFT), FXBUS(FXBUS_PCM_RIGHT), C_00000000);
OP(icode, &ptr, iMACINT0, GPR(tmp + 0), C_00000000, GPR(tmp + 0), C_00000002);
VOLUME(icode, &ptr, playback + 4, tmp + 0, gpr);
snd_emu10k1_init_mono_control(controls + i++, "Wave Center Playback Volume", gpr++, 0);
VOLUME(icode, &ptr, playback + 5, tmp + 0, gpr);
snd_emu10k1_init_mono_control(controls + i++, "Wave LFE Playback Volume", gpr++, 0);
for (z = 0; z < 2; z++) {
SWITCH(icode, &ptr, tmp + 0, z, gpr + 2 + z);
VOLUME(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Wave Capture Volume", gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, "Wave Capture Switch", gpr + 2, 0);
gpr += 4;
for (z = 0; z < 2; z++)
VOLUME_ADD(icode, &ptr, playback + z, 2 + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Synth Playback Volume", gpr, 100);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH(icode, &ptr, tmp + 0, 2 + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Synth Capture Volume", gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, "Synth Capture Switch", gpr + 2, 0);
gpr += 4;
for (z = 0; z < 2; z++)
VOLUME_ADD(icode, &ptr, playback + 2 + z, 4 + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Surround Digital Playback Volume", gpr, 100);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH(icode, &ptr, tmp + 0, 4 + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Surround Capture Volume", gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, "Surround Capture Switch", gpr + 2, 0);
gpr += 4;
VOLUME_ADD(icode, &ptr, playback + 4, 6, gpr);
snd_emu10k1_init_mono_control(controls + i++, "Center Digital Playback Volume", gpr++, 100);
VOLUME_ADD(icode, &ptr, playback + 5, 7, gpr);
snd_emu10k1_init_mono_control(controls + i++, "LFE Digital Playback Volume", gpr++, 100);
for (z = 0; z < 2; z++)
VOLUME_ADD(icode, &ptr, playback + z, 10 + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Front Playback Volume", gpr, 100);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH(icode, &ptr, tmp + 0, 10 + z, gpr + 2);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Front Capture Volume", gpr, 0);
snd_emu10k1_init_mono_onoff_control(controls + i++, "Front Capture Switch", gpr + 2, 0);
gpr += 3;
if (emu->fx8010.extin_mask & ((1<<EXTIN_AC97_L)|(1<<EXTIN_AC97_R))) {
VOLUME_ADDIN(icode, &ptr, playback + 0, EXTIN_AC97_L, gpr); gpr++;
VOLUME_ADDIN(icode, &ptr, playback + 1, EXTIN_AC97_R, gpr); gpr++;
snd_emu10k1_init_stereo_control(controls + i++, "AC97 Playback Volume", gpr-2, 0);
VOLUME_ADDIN(icode, &ptr, capture + 0, EXTIN_AC97_L, gpr); gpr++;
VOLUME_ADDIN(icode, &ptr, capture + 1, EXTIN_AC97_R, gpr); gpr++;
snd_emu10k1_init_stereo_control(controls + i++, "AC97 Capture Volume", gpr-2, 100);
}
if (emu->fx8010.extin_mask & ((1<<EXTIN_SPDIF_CD_L)|(1<<EXTIN_SPDIF_CD_R))) {
for (z = 0; z < 2; z++)
VOLUME_ADDIN(icode, &ptr, playback + z, EXTIN_SPDIF_CD_L + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, SNDRV_CTL_NAME_IEC958("TTL ",PLAYBACK,VOLUME), gpr, 0);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH_IN(icode, &ptr, tmp + 0, EXTIN_SPDIF_CD_L + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, SNDRV_CTL_NAME_IEC958("TTL ",CAPTURE,VOLUME), gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, SNDRV_CTL_NAME_IEC958("TTL ",CAPTURE,SWITCH), gpr + 2, 0);
gpr += 4;
}
if (emu->fx8010.extin_mask & ((1<<EXTIN_ZOOM_L)|(1<<EXTIN_ZOOM_R))) {
for (z = 0; z < 2; z++)
VOLUME_ADDIN(icode, &ptr, playback + z, EXTIN_ZOOM_L + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Zoom Video Playback Volume", gpr, 0);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH_IN(icode, &ptr, tmp + 0, EXTIN_ZOOM_L + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Zoom Video Capture Volume", gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, "Zoom Video Capture Switch", gpr + 2, 0);
gpr += 4;
}
if (emu->fx8010.extin_mask & ((1<<EXTIN_TOSLINK_L)|(1<<EXTIN_TOSLINK_R))) {
for (z = 0; z < 2; z++)
VOLUME_ADDIN(icode, &ptr, playback + z, EXTIN_TOSLINK_L + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, SNDRV_CTL_NAME_IEC958("LiveDrive ",PLAYBACK,VOLUME), gpr, 0);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH_IN(icode, &ptr, tmp + 0, EXTIN_TOSLINK_L + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, SNDRV_CTL_NAME_IEC958("LiveDrive ",CAPTURE,VOLUME), gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, SNDRV_CTL_NAME_IEC958("LiveDrive ",CAPTURE,SWITCH), gpr + 2, 0);
gpr += 4;
}
if (emu->fx8010.extin_mask & ((1<<EXTIN_LINE1_L)|(1<<EXTIN_LINE1_R))) {
for (z = 0; z < 2; z++)
VOLUME_ADDIN(icode, &ptr, playback + z, EXTIN_LINE1_L + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Line LiveDrive Playback Volume", gpr, 0);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH_IN(icode, &ptr, tmp + 0, EXTIN_LINE1_L + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Line LiveDrive Capture Volume", gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, "Line LiveDrive Capture Switch", gpr + 2, 0);
gpr += 4;
}
if (emu->fx8010.extin_mask & ((1<<EXTIN_COAX_SPDIF_L)|(1<<EXTIN_COAX_SPDIF_R))) {
for (z = 0; z < 2; z++)
VOLUME_ADDIN(icode, &ptr, playback + z, EXTIN_COAX_SPDIF_L + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, SNDRV_CTL_NAME_IEC958("Coaxial ",PLAYBACK,VOLUME), gpr, 0);
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH_IN(icode, &ptr, tmp + 0, EXTIN_COAX_SPDIF_L + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, SNDRV_CTL_NAME_IEC958("Coaxial ",CAPTURE,VOLUME), gpr, 0);
snd_emu10k1_init_stereo_onoff_control(controls + i++, SNDRV_CTL_NAME_IEC958("Coaxial ",CAPTURE,SWITCH), gpr + 2, 0);
gpr += 4;
}
if (emu->fx8010.extin_mask & ((1<<EXTIN_LINE2_L)|(1<<EXTIN_LINE2_R))) {
for (z = 0; z < 2; z++)
VOLUME_ADDIN(icode, &ptr, playback + z, EXTIN_LINE2_L + z, gpr + z);
snd_emu10k1_init_stereo_control(controls + i++, "Line2 LiveDrive Playback Volume", gpr, 0);
controls[i-1].id.index = 1;
gpr += 2;
for (z = 0; z < 2; z++) {
SWITCH_IN(icode, &ptr, tmp + 0, EXTIN_LINE2_L + z, gpr + 2 + z);
VOLUME_ADD(icode, &ptr, capture + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Line2 LiveDrive Capture Volume", gpr, 0);
controls[i-1].id.index = 1;
snd_emu10k1_init_stereo_onoff_control(controls + i++, "Line2 LiveDrive Capture Switch", gpr + 2, 0);
controls[i-1].id.index = 1;
gpr += 4;
}
OP(icode, &ptr, iACC3, GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 0), GPR(playback + 0), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 1), GPR(playback + 1), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 2), GPR(playback + 2), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 3), GPR(playback + 3), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 4), GPR(playback + 4), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 5), GPR(playback + 5), C_00000000, C_00000000);
ctl = &controls[i + 0];
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, "Tone Control - Bass");
ctl->vcount = 2;
ctl->count = 10;
ctl->min = 0;
ctl->max = 40;
ctl->value[0] = ctl->value[1] = 20;
ctl->tlv = snd_emu10k1_bass_treble_db_scale;
ctl->translation = EMU10K1_GPR_TRANSLATION_BASS;
ctl = &controls[i + 1];
ctl->id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(ctl->id.name, "Tone Control - Treble");
ctl->vcount = 2;
ctl->count = 10;
ctl->min = 0;
ctl->max = 40;
ctl->value[0] = ctl->value[1] = 20;
ctl->tlv = snd_emu10k1_bass_treble_db_scale;
ctl->translation = EMU10K1_GPR_TRANSLATION_TREBLE;
#define BASS_GPR 0x8c
#define TREBLE_GPR 0x96
for (z = 0; z < 5; z++) {
int j;
for (j = 0; j < 2; j++) {
controls[i + 0].gpr[z * 2 + j] = BASS_GPR + z * 2 + j;
controls[i + 1].gpr[z * 2 + j] = TREBLE_GPR + z * 2 + j;
}
}
for (z = 0; z < 3; z++) {
int j, k, l, d;
for (j = 0; j < 2; j++) {
k = 0xa0 + (z * 8) + (j * 4);
l = 0xd0 + (z * 8) + (j * 4);
d = playback + SND_EMU10K1_PLAYBACK_CHANNELS + z * 2 + j;
OP(icode, &ptr, iMAC0, C_00000000, C_00000000, GPR(d), GPR(BASS_GPR + 0 + j));
OP(icode, &ptr, iMACMV, GPR(k+1), GPR(k), GPR(k+1), GPR(BASS_GPR + 4 + j));
OP(icode, &ptr, iMACMV, GPR(k), GPR(d), GPR(k), GPR(BASS_GPR + 2 + j));
OP(icode, &ptr, iMACMV, GPR(k+3), GPR(k+2), GPR(k+3), GPR(BASS_GPR + 8 + j));
OP(icode, &ptr, iMAC0, GPR(k+2), GPR_ACCU, GPR(k+2), GPR(BASS_GPR + 6 + j));
OP(icode, &ptr, iACC3, GPR(k+2), GPR(k+2), GPR(k+2), C_00000000);
OP(icode, &ptr, iMAC0, C_00000000, C_00000000, GPR(k+2), GPR(TREBLE_GPR + 0 + j));
OP(icode, &ptr, iMACMV, GPR(l+1), GPR(l), GPR(l+1), GPR(TREBLE_GPR + 4 + j));
OP(icode, &ptr, iMACMV, GPR(l), GPR(k+2), GPR(l), GPR(TREBLE_GPR + 2 + j));
OP(icode, &ptr, iMACMV, GPR(l+3), GPR(l+2), GPR(l+3), GPR(TREBLE_GPR + 8 + j));
OP(icode, &ptr, iMAC0, GPR(l+2), GPR_ACCU, GPR(l+2), GPR(TREBLE_GPR + 6 + j));
OP(icode, &ptr, iMACINT0, GPR(l+2), C_00000000, GPR(l+2), C_00000010);
OP(icode, &ptr, iACC3, GPR(d), GPR(l+2), C_00000000, C_00000000);
if (z == 2)
break;
}
}
i += 2;
#undef BASS_GPR
#undef TREBLE_GPR
for (z = 0; z < 6; z++) {
SWITCH(icode, &ptr, tmp + 0, playback + SND_EMU10K1_PLAYBACK_CHANNELS + z, gpr + 0);
SWITCH_NEG(icode, &ptr, tmp + 1, gpr + 0);
SWITCH(icode, &ptr, tmp + 1, playback + z, tmp + 1);
OP(icode, &ptr, iACC3, GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + z), GPR(tmp + 0), GPR(tmp + 1), C_00000000);
}
snd_emu10k1_init_stereo_onoff_control(controls + i++, "Tone Control - Switch", gpr, 0);
gpr += 2;
if (emu->fx8010.extout_mask & ((1<<EXTOUT_AC97_L)|(1<<EXTOUT_AC97_R))) {
for (z = 0; z < 2; z++)
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_AC97_L + z), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + z), C_00000000, C_00000000);
}
if (emu->fx8010.extout_mask & ((1<<EXTOUT_TOSLINK_L)|(1<<EXTOUT_TOSLINK_R))) {
for (z = 0; z < 2; z++) {
SWITCH(icode, &ptr, tmp + 0, 8 + z, gpr + z);
SWITCH_NEG(icode, &ptr, tmp + 1, gpr + z);
SWITCH(icode, &ptr, tmp + 1, playback + SND_EMU10K1_PLAYBACK_CHANNELS + z, tmp + 1);
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_TOSLINK_L + z), GPR(tmp + 0), GPR(tmp + 1), C_00000000);
#ifdef EMU10K1_CAPTURE_DIGITAL_OUT
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_ADC_CAP_L + z), GPR(tmp + 0), GPR(tmp + 1), C_00000000);
#endif
}
snd_emu10k1_init_stereo_onoff_control(controls + i++, SNDRV_CTL_NAME_IEC958("Optical Raw ",PLAYBACK,SWITCH), gpr, 0);
gpr += 2;
}
if (emu->fx8010.extout_mask & ((1<<EXTOUT_HEADPHONE_L)|(1<<EXTOUT_HEADPHONE_R))) {
for (z = 0; z < 2; z++) {
SWITCH(icode, &ptr, tmp + 0, playback + SND_EMU10K1_PLAYBACK_CHANNELS + 4 + z, gpr + 2 + z);
SWITCH_NEG(icode, &ptr, tmp + 1, gpr + 2 + z);
SWITCH(icode, &ptr, tmp + 1, playback + SND_EMU10K1_PLAYBACK_CHANNELS + z, tmp + 1);
OP(icode, &ptr, iACC3, GPR(tmp + 0), GPR(tmp + 0), GPR(tmp + 1), C_00000000);
VOLUME_OUT(icode, &ptr, EXTOUT_HEADPHONE_L + z, tmp + 0, gpr + z);
}
snd_emu10k1_init_stereo_control(controls + i++, "Headphone Playback Volume", gpr + 0, 0);
controls[i-1].id.index = 1;
snd_emu10k1_init_mono_onoff_control(controls + i++, "Headphone Center Playback Switch", gpr + 2, 0);
controls[i-1].id.index = 1;
snd_emu10k1_init_mono_onoff_control(controls + i++, "Headphone LFE Playback Switch", gpr + 3, 0);
controls[i-1].id.index = 1;
gpr += 4;
}
if (emu->fx8010.extout_mask & ((1<<EXTOUT_REAR_L)|(1<<EXTOUT_REAR_R)))
for (z = 0; z < 2; z++)
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_REAR_L + z), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 2 + z), C_00000000, C_00000000);
if (emu->fx8010.extout_mask & ((1<<EXTOUT_AC97_REAR_L)|(1<<EXTOUT_AC97_REAR_R)))
for (z = 0; z < 2; z++)
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_AC97_REAR_L + z), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 2 + z), C_00000000, C_00000000);
if (emu->fx8010.extout_mask & (1<<EXTOUT_AC97_CENTER)) {
#ifndef EMU10K1_CENTER_LFE_FROM_FRONT
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_AC97_CENTER), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 4), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_ACENTER), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 4), C_00000000, C_00000000);
#else
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_AC97_CENTER), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 0), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_ACENTER), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 0), C_00000000, C_00000000);
#endif
}
if (emu->fx8010.extout_mask & (1<<EXTOUT_AC97_LFE)) {
#ifndef EMU10K1_CENTER_LFE_FROM_FRONT
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_AC97_LFE), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 5), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_ALFE), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 5), C_00000000, C_00000000);
#else
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_AC97_LFE), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 1), C_00000000, C_00000000);
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_ALFE), GPR(playback + SND_EMU10K1_PLAYBACK_CHANNELS + 1), C_00000000, C_00000000);
#endif
}
#ifndef EMU10K1_CAPTURE_DIGITAL_OUT
for (z = 0; z < 2; z++)
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_ADC_CAP_L + z), GPR(capture + z), C_00000000, C_00000000);
#endif
if (emu->fx8010.extout_mask & (1<<EXTOUT_MIC_CAP))
OP(icode, &ptr, iACC3, EXTOUT(EXTOUT_MIC_CAP), GPR(capture + 2), C_00000000, C_00000000);
if (emu->card_capabilities->sblive51) {
OP(icode, &ptr, iACC3, FXBUS2(14), C_00000000, C_00000000, EXTIN(0));
OP(icode, &ptr, iACC3, FXBUS2(15), C_00000000, C_00000000, EXTIN(1));
OP(icode, &ptr, iACC3, FXBUS2(0), C_00000000, C_00000000, EXTIN(2));
OP(icode, &ptr, iACC3, FXBUS2(3), C_00000000, C_00000000, EXTIN(3));
for (z = 4; z < 14; z++)
OP(icode, &ptr, iACC3, FXBUS2(z), C_00000000, C_00000000, EXTIN(z));
} else {
for (z = 0; z < 16; z++)
OP(icode, &ptr, iACC3, FXBUS2(z), C_00000000, C_00000000, EXTIN(z));
}
if (gpr > tmp) {
snd_BUG();
err = -EIO;
goto __err;
}
if (i > SND_EMU10K1_GPR_CONTROLS) {
snd_BUG();
err = -EIO;
goto __err;
}
while (ptr < 0x200)
OP(icode, &ptr, iACC3, C_00000000, C_00000000, C_00000000, C_00000000);
if ((err = snd_emu10k1_fx8010_tram_setup(emu, ipcm->buffer_size)) < 0)
goto __err;
seg = snd_enter_user();
icode->gpr_add_control_count = i;
icode->gpr_add_controls = (struct snd_emu10k1_fx8010_control_gpr __user *)controls;
emu->support_tlv = 1;
err = snd_emu10k1_icode_poke(emu, icode);
emu->support_tlv = 0;
snd_leave_user(seg);
if (err >= 0)
err = snd_emu10k1_ipcm_poke(emu, ipcm);
__err:
kfree(ipcm);
kfree(controls);
if (icode != NULL) {
kfree((void __force *)icode->gpr_map);
kfree(icode);
}
return err;
}
int snd_emu10k1_init_efx(struct snd_emu10k1 *emu)
{
spin_lock_init(&emu->fx8010.irq_lock);
INIT_LIST_HEAD(&emu->fx8010.gpr_ctl);
if (emu->audigy)
return _snd_emu10k1_audigy_init_efx(emu);
else
return _snd_emu10k1_init_efx(emu);
}
void snd_emu10k1_free_efx(struct snd_emu10k1 *emu)
{
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg = A_DBG_SINGLE_STEP);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg = EMU10K1_DBG_SINGLE_STEP);
}
int snd_emu10k1_fx8010_tram_setup(struct snd_emu10k1 *emu, u32 size)
{
u8 size_reg = 0;
if (size != 0) {
size = (size - 1) >> 13;
while (size) {
size >>= 1;
size_reg++;
}
size = 0x2000 << size_reg;
}
if ((emu->fx8010.etram_pages.bytes / 2) == size)
return 0;
spin_lock_irq(&emu->emu_lock);
outl(HCFG_LOCKTANKCACHE_MASK | inl(emu->port + HCFG), emu->port + HCFG);
spin_unlock_irq(&emu->emu_lock);
snd_emu10k1_ptr_write(emu, TCB, 0, 0);
snd_emu10k1_ptr_write(emu, TCBS, 0, 0);
if (emu->fx8010.etram_pages.area != NULL) {
snd_dma_free_pages(&emu->fx8010.etram_pages);
emu->fx8010.etram_pages.area = NULL;
emu->fx8010.etram_pages.bytes = 0;
}
if (size > 0) {
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(emu->pci),
size * 2, &emu->fx8010.etram_pages) < 0)
return -ENOMEM;
memset(emu->fx8010.etram_pages.area, 0, size * 2);
snd_emu10k1_ptr_write(emu, TCB, 0, emu->fx8010.etram_pages.addr);
snd_emu10k1_ptr_write(emu, TCBS, 0, size_reg);
spin_lock_irq(&emu->emu_lock);
outl(inl(emu->port + HCFG) & ~HCFG_LOCKTANKCACHE_MASK, emu->port + HCFG);
spin_unlock_irq(&emu->emu_lock);
}
return 0;
}
static int snd_emu10k1_fx8010_open(struct snd_hwdep * hw, struct file *file)
{
return 0;
}
static void copy_string(char *dst, char *src, char *null, int idx)
{
if (src == NULL)
sprintf(dst, "%s %02X", null, idx);
else
strcpy(dst, src);
}
static void snd_emu10k1_fx8010_info(struct snd_emu10k1 *emu,
struct snd_emu10k1_fx8010_info *info)
{
char **fxbus, **extin, **extout;
unsigned short fxbus_mask, extin_mask, extout_mask;
int res;
info->internal_tram_size = emu->fx8010.itram_size;
info->external_tram_size = emu->fx8010.etram_pages.bytes / 2;
fxbus = fxbuses;
extin = emu->audigy ? audigy_ins : creative_ins;
extout = emu->audigy ? audigy_outs : creative_outs;
fxbus_mask = emu->fx8010.fxbus_mask;
extin_mask = emu->fx8010.extin_mask;
extout_mask = emu->fx8010.extout_mask;
for (res = 0; res < 16; res++, fxbus++, extin++, extout++) {
copy_string(info->fxbus_names[res], fxbus_mask & (1 << res) ? *fxbus : NULL, "FXBUS", res);
copy_string(info->extin_names[res], extin_mask & (1 << res) ? *extin : NULL, "Unused", res);
copy_string(info->extout_names[res], extout_mask & (1 << res) ? *extout : NULL, "Unused", res);
}
for (res = 16; res < 32; res++, extout++)
copy_string(info->extout_names[res], extout_mask & (1 << res) ? *extout : NULL, "Unused", res);
info->gpr_controls = emu->fx8010.gpr_count;
}
static int snd_emu10k1_fx8010_ioctl(struct snd_hwdep * hw, struct file *file, unsigned int cmd, unsigned long arg)
{
struct snd_emu10k1 *emu = hw->private_data;
struct snd_emu10k1_fx8010_info *info;
struct snd_emu10k1_fx8010_code *icode;
struct snd_emu10k1_fx8010_pcm_rec *ipcm;
unsigned int addr;
void __user *argp = (void __user *)arg;
int res;
switch (cmd) {
case SNDRV_EMU10K1_IOCTL_PVERSION:
emu->support_tlv = 1;
return put_user(SNDRV_EMU10K1_VERSION, (int __user *)argp);
case SNDRV_EMU10K1_IOCTL_INFO:
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
snd_emu10k1_fx8010_info(emu, info);
if (copy_to_user(argp, info, sizeof(*info))) {
kfree(info);
return -EFAULT;
}
kfree(info);
return 0;
case SNDRV_EMU10K1_IOCTL_CODE_POKE:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
icode = memdup_user(argp, sizeof(*icode));
if (IS_ERR(icode))
return PTR_ERR(icode);
res = snd_emu10k1_icode_poke(emu, icode);
kfree(icode);
return res;
case SNDRV_EMU10K1_IOCTL_CODE_PEEK:
icode = memdup_user(argp, sizeof(*icode));
if (IS_ERR(icode))
return PTR_ERR(icode);
res = snd_emu10k1_icode_peek(emu, icode);
if (res == 0 && copy_to_user(argp, icode, sizeof(*icode))) {
kfree(icode);
return -EFAULT;
}
kfree(icode);
return res;
case SNDRV_EMU10K1_IOCTL_PCM_POKE:
ipcm = memdup_user(argp, sizeof(*ipcm));
if (IS_ERR(ipcm))
return PTR_ERR(ipcm);
res = snd_emu10k1_ipcm_poke(emu, ipcm);
kfree(ipcm);
return res;
case SNDRV_EMU10K1_IOCTL_PCM_PEEK:
ipcm = memdup_user(argp, sizeof(*ipcm));
if (IS_ERR(ipcm))
return PTR_ERR(ipcm);
res = snd_emu10k1_ipcm_peek(emu, ipcm);
if (res == 0 && copy_to_user(argp, ipcm, sizeof(*ipcm))) {
kfree(ipcm);
return -EFAULT;
}
kfree(ipcm);
return res;
case SNDRV_EMU10K1_IOCTL_TRAM_SETUP:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (get_user(addr, (unsigned int __user *)argp))
return -EFAULT;
mutex_lock(&emu->fx8010.lock);
res = snd_emu10k1_fx8010_tram_setup(emu, addr);
mutex_unlock(&emu->fx8010.lock);
return res;
case SNDRV_EMU10K1_IOCTL_STOP:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg |= A_DBG_SINGLE_STEP);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg |= EMU10K1_DBG_SINGLE_STEP);
return 0;
case SNDRV_EMU10K1_IOCTL_CONTINUE:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg = 0);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg = 0);
return 0;
case SNDRV_EMU10K1_IOCTL_ZERO_TRAM_COUNTER:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg | A_DBG_ZC);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg | EMU10K1_DBG_ZC);
udelay(10);
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg);
return 0;
case SNDRV_EMU10K1_IOCTL_SINGLE_STEP:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (get_user(addr, (unsigned int __user *)argp))
return -EFAULT;
if (addr > 0x1ff)
return -EINVAL;
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg |= A_DBG_SINGLE_STEP | addr);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg |= EMU10K1_DBG_SINGLE_STEP | addr);
udelay(10);
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg |= A_DBG_SINGLE_STEP | A_DBG_STEP_ADDR | addr);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg |= EMU10K1_DBG_SINGLE_STEP | EMU10K1_DBG_STEP | addr);
return 0;
case SNDRV_EMU10K1_IOCTL_DBG_READ:
if (emu->audigy)
addr = snd_emu10k1_ptr_read(emu, A_DBG, 0);
else
addr = snd_emu10k1_ptr_read(emu, DBG, 0);
if (put_user(addr, (unsigned int __user *)argp))
return -EFAULT;
return 0;
}
return -ENOTTY;
}
static int snd_emu10k1_fx8010_release(struct snd_hwdep * hw, struct file *file)
{
return 0;
}
int snd_emu10k1_fx8010_new(struct snd_emu10k1 *emu, int device,
struct snd_hwdep **rhwdep)
{
struct snd_hwdep *hw;
int err;
if (rhwdep)
*rhwdep = NULL;
if ((err = snd_hwdep_new(emu->card, "FX8010", device, &hw)) < 0)
return err;
strcpy(hw->name, "EMU10K1 (FX8010)");
hw->iface = SNDRV_HWDEP_IFACE_EMU10K1;
hw->ops.open = snd_emu10k1_fx8010_open;
hw->ops.ioctl = snd_emu10k1_fx8010_ioctl;
hw->ops.release = snd_emu10k1_fx8010_release;
hw->private_data = emu;
if (rhwdep)
*rhwdep = hw;
return 0;
}
int snd_emu10k1_efx_alloc_pm_buffer(struct snd_emu10k1 *emu)
{
int len;
len = emu->audigy ? 0x200 : 0x100;
emu->saved_gpr = kmalloc(len * 4, GFP_KERNEL);
if (! emu->saved_gpr)
return -ENOMEM;
len = emu->audigy ? 0x100 : 0xa0;
emu->tram_val_saved = kmalloc(len * 4, GFP_KERNEL);
emu->tram_addr_saved = kmalloc(len * 4, GFP_KERNEL);
if (! emu->tram_val_saved || ! emu->tram_addr_saved)
return -ENOMEM;
len = emu->audigy ? 2 * 1024 : 2 * 512;
emu->saved_icode = vmalloc(len * 4);
if (! emu->saved_icode)
return -ENOMEM;
return 0;
}
void snd_emu10k1_efx_free_pm_buffer(struct snd_emu10k1 *emu)
{
kfree(emu->saved_gpr);
kfree(emu->tram_val_saved);
kfree(emu->tram_addr_saved);
vfree(emu->saved_icode);
}
void snd_emu10k1_efx_suspend(struct snd_emu10k1 *emu)
{
int i, len;
len = emu->audigy ? 0x200 : 0x100;
for (i = 0; i < len; i++)
emu->saved_gpr[i] = snd_emu10k1_ptr_read(emu, emu->gpr_base + i, 0);
len = emu->audigy ? 0x100 : 0xa0;
for (i = 0; i < len; i++) {
emu->tram_val_saved[i] = snd_emu10k1_ptr_read(emu, TANKMEMDATAREGBASE + i, 0);
emu->tram_addr_saved[i] = snd_emu10k1_ptr_read(emu, TANKMEMADDRREGBASE + i, 0);
if (emu->audigy) {
emu->tram_addr_saved[i] >>= 12;
emu->tram_addr_saved[i] |=
snd_emu10k1_ptr_read(emu, A_TANKMEMCTLREGBASE + i, 0) << 20;
}
}
len = emu->audigy ? 2 * 1024 : 2 * 512;
for (i = 0; i < len; i++)
emu->saved_icode[i] = snd_emu10k1_efx_read(emu, i);
}
void snd_emu10k1_efx_resume(struct snd_emu10k1 *emu)
{
int i, len;
if (emu->fx8010.etram_pages.bytes > 0) {
unsigned size, size_reg = 0;
size = emu->fx8010.etram_pages.bytes / 2;
size = (size - 1) >> 13;
while (size) {
size >>= 1;
size_reg++;
}
outl(HCFG_LOCKTANKCACHE_MASK | inl(emu->port + HCFG), emu->port + HCFG);
snd_emu10k1_ptr_write(emu, TCB, 0, emu->fx8010.etram_pages.addr);
snd_emu10k1_ptr_write(emu, TCBS, 0, size_reg);
outl(inl(emu->port + HCFG) & ~HCFG_LOCKTANKCACHE_MASK, emu->port + HCFG);
}
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg | A_DBG_SINGLE_STEP);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg | EMU10K1_DBG_SINGLE_STEP);
len = emu->audigy ? 0x200 : 0x100;
for (i = 0; i < len; i++)
snd_emu10k1_ptr_write(emu, emu->gpr_base + i, 0, emu->saved_gpr[i]);
len = emu->audigy ? 0x100 : 0xa0;
for (i = 0; i < len; i++) {
snd_emu10k1_ptr_write(emu, TANKMEMDATAREGBASE + i, 0,
emu->tram_val_saved[i]);
if (! emu->audigy)
snd_emu10k1_ptr_write(emu, TANKMEMADDRREGBASE + i, 0,
emu->tram_addr_saved[i]);
else {
snd_emu10k1_ptr_write(emu, TANKMEMADDRREGBASE + i, 0,
emu->tram_addr_saved[i] << 12);
snd_emu10k1_ptr_write(emu, TANKMEMADDRREGBASE + i, 0,
emu->tram_addr_saved[i] >> 20);
}
}
len = emu->audigy ? 2 * 1024 : 2 * 512;
for (i = 0; i < len; i++)
snd_emu10k1_efx_write(emu, i, emu->saved_icode[i]);
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, emu->fx8010.dbg);
else
snd_emu10k1_ptr_write(emu, DBG, 0, emu->fx8010.dbg);
}
