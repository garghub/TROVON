static struct device *sbd_core(void)
{
BUG_ON(!lpm_priv || !lpm_priv->sbd);
return &lpm_priv->sbd->core;
}
void ps3_set_bookmark(u64 bookmark)
{
asm volatile("nop;nop;nop;nop;nop;nop;nop;nop;nop;");
mtspr(SPRN_BKMK, bookmark);
asm volatile("nop;nop;nop;nop;nop;nop;nop;nop;nop;");
}
void ps3_set_pm_bookmark(u64 tag, u64 incident, u64 th_id)
{
u64 bookmark;
bookmark = (get_tb() & 0x00000000FFFFFFFFULL) |
PS3_PM_BOOKMARK_TAG_KERNEL;
bookmark = ((tag << 56) & PS3_PM_BOOKMARK_TAG_MASK_LO) |
(incident << 48) | (th_id << 32) | bookmark;
ps3_set_bookmark(bookmark);
}
u32 ps3_read_phys_ctr(u32 cpu, u32 phys_ctr)
{
int result;
u64 counter0415;
u64 counter2637;
if (phys_ctr >= NR_PHYS_CTRS) {
dev_dbg(sbd_core(), "%s:%u: phys_ctr too big: %u\n", __func__,
__LINE__, phys_ctr);
return 0;
}
result = lv1_set_lpm_counter(lpm_priv->lpm_id, 0, 0, 0, 0, &counter0415,
&counter2637);
if (result) {
dev_err(sbd_core(), "%s:%u: lv1_set_lpm_counter failed: "
"phys_ctr %u, %s\n", __func__, __LINE__, phys_ctr,
ps3_result(result));
return 0;
}
switch (phys_ctr) {
case 0:
return counter0415 >> 32;
case 1:
return counter0415 & PS3_PM_COUNTER_MASK_LO;
case 2:
return counter2637 >> 32;
case 3:
return counter2637 & PS3_PM_COUNTER_MASK_LO;
default:
BUG();
}
return 0;
}
void ps3_write_phys_ctr(u32 cpu, u32 phys_ctr, u32 val)
{
u64 counter0415;
u64 counter0415_mask;
u64 counter2637;
u64 counter2637_mask;
int result;
if (phys_ctr >= NR_PHYS_CTRS) {
dev_dbg(sbd_core(), "%s:%u: phys_ctr too big: %u\n", __func__,
__LINE__, phys_ctr);
return;
}
switch (phys_ctr) {
case 0:
counter0415 = (u64)val << 32;
counter0415_mask = PS3_PM_COUNTER_MASK_HI;
counter2637 = 0x0;
counter2637_mask = 0x0;
break;
case 1:
counter0415 = (u64)val;
counter0415_mask = PS3_PM_COUNTER_MASK_LO;
counter2637 = 0x0;
counter2637_mask = 0x0;
break;
case 2:
counter0415 = 0x0;
counter0415_mask = 0x0;
counter2637 = (u64)val << 32;
counter2637_mask = PS3_PM_COUNTER_MASK_HI;
break;
case 3:
counter0415 = 0x0;
counter0415_mask = 0x0;
counter2637 = (u64)val;
counter2637_mask = PS3_PM_COUNTER_MASK_LO;
break;
default:
BUG();
}
result = lv1_set_lpm_counter(lpm_priv->lpm_id,
counter0415, counter0415_mask,
counter2637, counter2637_mask,
&counter0415, &counter2637);
if (result)
dev_err(sbd_core(), "%s:%u: lv1_set_lpm_counter failed: "
"phys_ctr %u, val %u, %s\n", __func__, __LINE__,
phys_ctr, val, ps3_result(result));
}
u32 ps3_read_ctr(u32 cpu, u32 ctr)
{
u32 val;
u32 phys_ctr = ctr & (NR_PHYS_CTRS - 1);
val = ps3_read_phys_ctr(cpu, phys_ctr);
if (ps3_get_ctr_size(cpu, phys_ctr) == 16)
val = (ctr < NR_PHYS_CTRS) ? (val >> 16) : (val & 0xffff);
return val;
}
void ps3_write_ctr(u32 cpu, u32 ctr, u32 val)
{
u32 phys_ctr;
u32 phys_val;
phys_ctr = ctr & (NR_PHYS_CTRS - 1);
if (ps3_get_ctr_size(cpu, phys_ctr) == 16) {
phys_val = ps3_read_phys_ctr(cpu, phys_ctr);
if (ctr < NR_PHYS_CTRS)
val = (val << 16) | (phys_val & 0xffff);
else
val = (val & 0xffff) | (phys_val & 0xffff0000);
}
ps3_write_phys_ctr(cpu, phys_ctr, val);
}
u32 ps3_read_pm07_control(u32 cpu, u32 ctr)
{
return 0;
}
void ps3_write_pm07_control(u32 cpu, u32 ctr, u32 val)
{
int result;
static const u64 mask = 0xFFFFFFFFFFFFFFFFULL;
u64 old_value;
if (ctr >= NR_CTRS) {
dev_dbg(sbd_core(), "%s:%u: ctr too big: %u\n", __func__,
__LINE__, ctr);
return;
}
result = lv1_set_lpm_counter_control(lpm_priv->lpm_id, ctr, val, mask,
&old_value);
if (result)
dev_err(sbd_core(), "%s:%u: lv1_set_lpm_counter_control "
"failed: ctr %u, %s\n", __func__, __LINE__, ctr,
ps3_result(result));
}
u32 ps3_read_pm(u32 cpu, enum pm_reg_name reg)
{
int result = 0;
u64 val = 0;
switch (reg) {
case pm_control:
return lpm_priv->shadow.pm_control;
case trace_address:
return CBE_PM_TRACE_BUF_EMPTY;
case pm_start_stop:
return lpm_priv->shadow.pm_start_stop;
case pm_interval:
result = lv1_set_lpm_interval(lpm_priv->lpm_id, 0, 0, &val);
if (result) {
val = 0;
dev_dbg(sbd_core(), "%s:%u: lv1 set_interval failed: "
"reg %u, %s\n", __func__, __LINE__, reg,
ps3_result(result));
}
return (u32)val;
case group_control:
return lpm_priv->shadow.group_control;
case debug_bus_control:
return lpm_priv->shadow.debug_bus_control;
case pm_status:
result = lv1_get_lpm_interrupt_status(lpm_priv->lpm_id,
&val);
if (result) {
val = 0;
dev_dbg(sbd_core(), "%s:%u: lv1 get_lpm_status failed: "
"reg %u, %s\n", __func__, __LINE__, reg,
ps3_result(result));
}
return (u32)val;
case ext_tr_timer:
return 0;
default:
dev_dbg(sbd_core(), "%s:%u: unknown reg: %d\n", __func__,
__LINE__, reg);
BUG();
break;
}
return 0;
}
void ps3_write_pm(u32 cpu, enum pm_reg_name reg, u32 val)
{
int result = 0;
u64 dummy;
switch (reg) {
case group_control:
if (val != lpm_priv->shadow.group_control)
result = lv1_set_lpm_group_control(lpm_priv->lpm_id,
val,
PS3_WRITE_PM_MASK,
&dummy);
lpm_priv->shadow.group_control = val;
break;
case debug_bus_control:
if (val != lpm_priv->shadow.debug_bus_control)
result = lv1_set_lpm_debug_bus_control(lpm_priv->lpm_id,
val,
PS3_WRITE_PM_MASK,
&dummy);
lpm_priv->shadow.debug_bus_control = val;
break;
case pm_control:
if (use_start_stop_bookmark)
val |= (PS3_PM_CONTROL_PPU_TH0_BOOKMARK |
PS3_PM_CONTROL_PPU_TH1_BOOKMARK);
if (val != lpm_priv->shadow.pm_control)
result = lv1_set_lpm_general_control(lpm_priv->lpm_id,
val,
PS3_WRITE_PM_MASK,
0, 0, &dummy,
&dummy);
lpm_priv->shadow.pm_control = val;
break;
case pm_interval:
result = lv1_set_lpm_interval(lpm_priv->lpm_id, val,
PS3_WRITE_PM_MASK, &dummy);
break;
case pm_start_stop:
if (val != lpm_priv->shadow.pm_start_stop)
result = lv1_set_lpm_trigger_control(lpm_priv->lpm_id,
val,
PS3_WRITE_PM_MASK,
&dummy);
lpm_priv->shadow.pm_start_stop = val;
break;
case trace_address:
case ext_tr_timer:
case pm_status:
break;
default:
dev_dbg(sbd_core(), "%s:%u: unknown reg: %d\n", __func__,
__LINE__, reg);
BUG();
break;
}
if (result)
dev_err(sbd_core(), "%s:%u: lv1 set_control failed: "
"reg %u, %s\n", __func__, __LINE__, reg,
ps3_result(result));
}
u32 ps3_get_ctr_size(u32 cpu, u32 phys_ctr)
{
u32 pm_ctrl;
if (phys_ctr >= NR_PHYS_CTRS) {
dev_dbg(sbd_core(), "%s:%u: phys_ctr too big: %u\n", __func__,
__LINE__, phys_ctr);
return 0;
}
pm_ctrl = ps3_read_pm(cpu, pm_control);
return (pm_ctrl & CBE_PM_16BIT_CTR(phys_ctr)) ? 16 : 32;
}
void ps3_set_ctr_size(u32 cpu, u32 phys_ctr, u32 ctr_size)
{
u32 pm_ctrl;
if (phys_ctr >= NR_PHYS_CTRS) {
dev_dbg(sbd_core(), "%s:%u: phys_ctr too big: %u\n", __func__,
__LINE__, phys_ctr);
return;
}
pm_ctrl = ps3_read_pm(cpu, pm_control);
switch (ctr_size) {
case 16:
pm_ctrl |= CBE_PM_16BIT_CTR(phys_ctr);
ps3_write_pm(cpu, pm_control, pm_ctrl);
break;
case 32:
pm_ctrl &= ~CBE_PM_16BIT_CTR(phys_ctr);
ps3_write_pm(cpu, pm_control, pm_ctrl);
break;
default:
BUG();
}
}
static u64 pm_translate_signal_group_number_on_island2(u64 subgroup)
{
if (subgroup == 2)
subgroup = 3;
if (subgroup <= 6)
return PM_ISLAND2_BASE_SIGNAL_GROUP_NUMBER + subgroup;
else if (subgroup == 7)
return PM_ISLAND2_SIGNAL_GROUP_NUMBER1;
else
return PM_ISLAND2_SIGNAL_GROUP_NUMBER2;
}
static u64 pm_translate_signal_group_number_on_island3(u64 subgroup)
{
switch (subgroup) {
case 2:
case 3:
case 4:
subgroup += 2;
break;
case 5:
subgroup = 8;
break;
default:
break;
}
return PM_ISLAND3_BASE_SIGNAL_GROUP_NUMBER + subgroup;
}
static u64 pm_translate_signal_group_number_on_island4(u64 subgroup)
{
return PM_ISLAND4_BASE_SIGNAL_GROUP_NUMBER + subgroup;
}
static u64 pm_translate_signal_group_number_on_island5(u64 subgroup)
{
switch (subgroup) {
case 3:
subgroup = 4;
break;
case 4:
subgroup = 6;
break;
default:
break;
}
return PM_ISLAND5_BASE_SIGNAL_GROUP_NUMBER + subgroup;
}
static u64 pm_translate_signal_group_number_on_island6(u64 subgroup,
u64 subsubgroup)
{
switch (subgroup) {
case 3:
case 4:
case 5:
subgroup += 1;
break;
default:
break;
}
switch (subsubgroup) {
case 4:
case 5:
case 6:
subsubgroup += 2;
break;
case 7:
case 8:
case 9:
case 10:
subsubgroup += 4;
break;
case 11:
case 12:
case 13:
subsubgroup += 5;
break;
default:
break;
}
if (subgroup <= 5)
return (PM_ISLAND6_BASE_SIGNAL_GROUP_NUMBER + subgroup);
else
return (PM_ISLAND6_BASE_SIGNAL_GROUP_NUMBER + subgroup
+ subsubgroup - 1);
}
static u64 pm_translate_signal_group_number_on_island7(u64 subgroup)
{
return PM_ISLAND7_BASE_SIGNAL_GROUP_NUMBER + subgroup;
}
static u64 pm_translate_signal_group_number_on_island8(u64 subgroup)
{
return PM_ISLAND8_BASE_SIGNAL_GROUP_NUMBER + subgroup;
}
static u64 pm_signal_group_to_ps3_lv1_signal_group(u64 group)
{
u64 island;
u64 subgroup;
u64 subsubgroup;
subgroup = 0;
subsubgroup = 0;
island = 0;
if (group < 1000) {
if (group < 100) {
if (20 <= group && group < 30) {
island = 2;
subgroup = group - 20;
} else if (30 <= group && group < 40) {
island = 3;
subgroup = group - 30;
} else if (40 <= group && group < 50) {
island = 4;
subgroup = group - 40;
} else if (50 <= group && group < 60) {
island = 5;
subgroup = group - 50;
} else if (60 <= group && group < 70) {
island = 6;
subgroup = group - 60;
} else if (70 <= group && group < 80) {
island = 7;
subgroup = group - 70;
} else if (80 <= group && group < 90) {
island = 8;
subgroup = group - 80;
}
} else if (200 <= group && group < 300) {
island = 2;
subgroup = group - 200;
} else if (600 <= group && group < 700) {
island = 6;
subgroup = 5;
subsubgroup = group - 650;
}
} else if (6000 <= group && group < 7000) {
island = 6;
subgroup = 5;
subsubgroup = group - 6500;
}
switch (island) {
case 2:
return pm_translate_signal_group_number_on_island2(subgroup);
case 3:
return pm_translate_signal_group_number_on_island3(subgroup);
case 4:
return pm_translate_signal_group_number_on_island4(subgroup);
case 5:
return pm_translate_signal_group_number_on_island5(subgroup);
case 6:
return pm_translate_signal_group_number_on_island6(subgroup,
subsubgroup);
case 7:
return pm_translate_signal_group_number_on_island7(subgroup);
case 8:
return pm_translate_signal_group_number_on_island8(subgroup);
default:
dev_dbg(sbd_core(), "%s:%u: island not found: %llu\n", __func__,
__LINE__, group);
BUG();
break;
}
return 0;
}
static u64 pm_bus_word_to_ps3_lv1_bus_word(u8 word)
{
switch (word) {
case 1:
return 0xF000;
case 2:
return 0x0F00;
case 4:
return 0x00F0;
case 8:
default:
return 0x000F;
}
}
static int __ps3_set_signal(u64 lv1_signal_group, u64 bus_select,
u64 signal_select, u64 attr1, u64 attr2, u64 attr3)
{
int ret;
ret = lv1_set_lpm_signal(lpm_priv->lpm_id, lv1_signal_group, bus_select,
signal_select, attr1, attr2, attr3);
if (ret)
dev_err(sbd_core(),
"%s:%u: error:%d 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx 0x%llx\n",
__func__, __LINE__, ret, lv1_signal_group, bus_select,
signal_select, attr1, attr2, attr3);
return ret;
}
int ps3_set_signal(u64 signal_group, u8 signal_bit, u16 sub_unit,
u8 bus_word)
{
int ret;
u64 lv1_signal_group;
u64 bus_select;
u64 signal_select;
u64 attr1, attr2, attr3;
if (signal_group == 0)
return __ps3_set_signal(0, 0, 0, 0, 0, 0);
lv1_signal_group =
pm_signal_group_to_ps3_lv1_signal_group(signal_group);
bus_select = pm_bus_word_to_ps3_lv1_bus_word(bus_word);
switch (signal_group) {
case PM_SIG_GROUP_SPU_TRIGGER:
signal_select = 1;
signal_select = signal_select << (63 - signal_bit);
break;
case PM_SIG_GROUP_SPU_EVENT:
signal_select = 1;
signal_select = (signal_select << (63 - signal_bit)) | 0x3;
break;
default:
signal_select = 0;
break;
}
attr1 = 1;
if (PM_SIG_GROUP_SPU <= signal_group &&
signal_group < PM_SIG_GROUP_MFC_MAX)
attr2 = sub_unit;
else
attr2 = lpm_priv->pu_id;
attr3 = 0;
ret = __ps3_set_signal(lv1_signal_group, bus_select, signal_select,
attr1, attr2, attr3);
if (ret)
dev_err(sbd_core(), "%s:%u: __ps3_set_signal failed: %d\n",
__func__, __LINE__, ret);
return ret;
}
u32 ps3_get_hw_thread_id(int cpu)
{
return get_hard_smp_processor_id(cpu);
}
void ps3_enable_pm(u32 cpu)
{
int result;
u64 tmp;
int insert_bookmark = 0;
lpm_priv->tb_count = 0;
if (use_start_stop_bookmark) {
if (!(lpm_priv->shadow.pm_start_stop &
(PS3_PM_START_STOP_START_MASK
| PS3_PM_START_STOP_STOP_MASK))) {
result = lv1_set_lpm_trigger_control(lpm_priv->lpm_id,
(PS3_PM_START_STOP_PPU_TH0_BOOKMARK_START |
PS3_PM_START_STOP_PPU_TH1_BOOKMARK_START |
PS3_PM_START_STOP_PPU_TH0_BOOKMARK_STOP |
PS3_PM_START_STOP_PPU_TH1_BOOKMARK_STOP),
0xFFFFFFFFFFFFFFFFULL, &tmp);
if (result)
dev_err(sbd_core(), "%s:%u: "
"lv1_set_lpm_trigger_control failed: "
"%s\n", __func__, __LINE__,
ps3_result(result));
insert_bookmark = !result;
}
}
result = lv1_start_lpm(lpm_priv->lpm_id);
if (result)
dev_err(sbd_core(), "%s:%u: lv1_start_lpm failed: %s\n",
__func__, __LINE__, ps3_result(result));
if (use_start_stop_bookmark && !result && insert_bookmark)
ps3_set_bookmark(get_tb() | PS3_PM_BOOKMARK_START);
}
void ps3_disable_pm(u32 cpu)
{
int result;
u64 tmp;
ps3_set_bookmark(get_tb() | PS3_PM_BOOKMARK_STOP);
result = lv1_stop_lpm(lpm_priv->lpm_id, &tmp);
if (result) {
if (result != LV1_WRONG_STATE)
dev_err(sbd_core(), "%s:%u: lv1_stop_lpm failed: %s\n",
__func__, __LINE__, ps3_result(result));
return;
}
lpm_priv->tb_count = tmp;
dev_dbg(sbd_core(), "%s:%u: tb_count %llu (%llxh)\n", __func__, __LINE__,
lpm_priv->tb_count, lpm_priv->tb_count);
}
int ps3_lpm_copy_tb(unsigned long offset, void *buf, unsigned long count,
unsigned long *bytes_copied)
{
int result;
*bytes_copied = 0;
if (!lpm_priv->tb_cache)
return -EPERM;
if (offset >= lpm_priv->tb_count)
return 0;
count = min_t(u64, count, lpm_priv->tb_count - offset);
while (*bytes_copied < count) {
const unsigned long request = count - *bytes_copied;
u64 tmp;
result = lv1_copy_lpm_trace_buffer(lpm_priv->lpm_id, offset,
request, &tmp);
if (result) {
dev_dbg(sbd_core(), "%s:%u: 0x%lx bytes at 0x%lx\n",
__func__, __LINE__, request, offset);
dev_err(sbd_core(), "%s:%u: lv1_copy_lpm_trace_buffer "
"failed: %s\n", __func__, __LINE__,
ps3_result(result));
return result == LV1_WRONG_STATE ? -EBUSY : -EINVAL;
}
memcpy(buf, lpm_priv->tb_cache, tmp);
buf += tmp;
*bytes_copied += tmp;
offset += tmp;
}
dev_dbg(sbd_core(), "%s:%u: copied %lxh bytes\n", __func__, __LINE__,
*bytes_copied);
return 0;
}
int ps3_lpm_copy_tb_to_user(unsigned long offset, void __user *buf,
unsigned long count, unsigned long *bytes_copied)
{
int result;
*bytes_copied = 0;
if (!lpm_priv->tb_cache)
return -EPERM;
if (offset >= lpm_priv->tb_count)
return 0;
count = min_t(u64, count, lpm_priv->tb_count - offset);
while (*bytes_copied < count) {
const unsigned long request = count - *bytes_copied;
u64 tmp;
result = lv1_copy_lpm_trace_buffer(lpm_priv->lpm_id, offset,
request, &tmp);
if (result) {
dev_dbg(sbd_core(), "%s:%u: 0x%lx bytes at 0x%lx\n",
__func__, __LINE__, request, offset);
dev_err(sbd_core(), "%s:%u: lv1_copy_lpm_trace_buffer "
"failed: %s\n", __func__, __LINE__,
ps3_result(result));
return result == LV1_WRONG_STATE ? -EBUSY : -EINVAL;
}
result = copy_to_user(buf, lpm_priv->tb_cache, tmp);
if (result) {
dev_dbg(sbd_core(), "%s:%u: 0x%llx bytes at 0x%p\n",
__func__, __LINE__, tmp, buf);
dev_err(sbd_core(), "%s:%u: copy_to_user failed: %d\n",
__func__, __LINE__, result);
return -EFAULT;
}
buf += tmp;
*bytes_copied += tmp;
offset += tmp;
}
dev_dbg(sbd_core(), "%s:%u: copied %lxh bytes\n", __func__, __LINE__,
*bytes_copied);
return 0;
}
u32 ps3_get_and_clear_pm_interrupts(u32 cpu)
{
return ps3_read_pm(cpu, pm_status);
}
void ps3_enable_pm_interrupts(u32 cpu, u32 thread, u32 mask)
{
if (mask)
ps3_write_pm(cpu, pm_status, mask);
}
void ps3_disable_pm_interrupts(u32 cpu)
{
ps3_get_and_clear_pm_interrupts(cpu);
ps3_write_pm(cpu, pm_status, 0);
}
int ps3_lpm_open(enum ps3_lpm_tb_type tb_type, void *tb_cache,
u64 tb_cache_size)
{
int result;
u64 tb_size;
BUG_ON(!lpm_priv);
BUG_ON(tb_type != PS3_LPM_TB_TYPE_NONE
&& tb_type != PS3_LPM_TB_TYPE_INTERNAL);
if (tb_type == PS3_LPM_TB_TYPE_NONE && tb_cache)
dev_dbg(sbd_core(), "%s:%u: bad in vals\n", __func__, __LINE__);
if (!atomic_add_unless(&lpm_priv->open, 1, 1)) {
dev_dbg(sbd_core(), "%s:%u: busy\n", __func__, __LINE__);
return -EBUSY;
}
if (tb_type == PS3_LPM_TB_TYPE_NONE) {
lpm_priv->tb_cache_size = 0;
lpm_priv->tb_cache_internal = NULL;
lpm_priv->tb_cache = NULL;
} else if (tb_cache) {
if (tb_cache != (void *)_ALIGN_UP((unsigned long)tb_cache, 128)
|| tb_cache_size != _ALIGN_UP(tb_cache_size, 128)) {
dev_err(sbd_core(), "%s:%u: unaligned tb_cache\n",
__func__, __LINE__);
result = -EINVAL;
goto fail_align;
}
lpm_priv->tb_cache_size = tb_cache_size;
lpm_priv->tb_cache_internal = NULL;
lpm_priv->tb_cache = tb_cache;
} else {
lpm_priv->tb_cache_size = PS3_LPM_DEFAULT_TB_CACHE_SIZE;
lpm_priv->tb_cache_internal = kzalloc(
lpm_priv->tb_cache_size + 127, GFP_KERNEL);
if (!lpm_priv->tb_cache_internal) {
dev_err(sbd_core(), "%s:%u: alloc internal tb_cache "
"failed\n", __func__, __LINE__);
result = -ENOMEM;
goto fail_malloc;
}
lpm_priv->tb_cache = (void *)_ALIGN_UP(
(unsigned long)lpm_priv->tb_cache_internal, 128);
}
result = lv1_construct_lpm(lpm_priv->node_id, tb_type, 0, 0,
ps3_mm_phys_to_lpar(__pa(lpm_priv->tb_cache)),
lpm_priv->tb_cache_size, &lpm_priv->lpm_id,
&lpm_priv->outlet_id, &tb_size);
if (result) {
dev_err(sbd_core(), "%s:%u: lv1_construct_lpm failed: %s\n",
__func__, __LINE__, ps3_result(result));
result = -EINVAL;
goto fail_construct;
}
lpm_priv->shadow.pm_control = PS3_LPM_SHADOW_REG_INIT;
lpm_priv->shadow.pm_start_stop = PS3_LPM_SHADOW_REG_INIT;
lpm_priv->shadow.group_control = PS3_LPM_SHADOW_REG_INIT;
lpm_priv->shadow.debug_bus_control = PS3_LPM_SHADOW_REG_INIT;
dev_dbg(sbd_core(), "%s:%u: lpm_id 0x%llx, outlet_id 0x%llx, "
"tb_size 0x%llx\n", __func__, __LINE__, lpm_priv->lpm_id,
lpm_priv->outlet_id, tb_size);
return 0;
fail_construct:
kfree(lpm_priv->tb_cache_internal);
lpm_priv->tb_cache_internal = NULL;
fail_malloc:
fail_align:
atomic_dec(&lpm_priv->open);
return result;
}
int ps3_lpm_close(void)
{
dev_dbg(sbd_core(), "%s:%u\n", __func__, __LINE__);
lv1_destruct_lpm(lpm_priv->lpm_id);
lpm_priv->lpm_id = 0;
kfree(lpm_priv->tb_cache_internal);
lpm_priv->tb_cache_internal = NULL;
atomic_dec(&lpm_priv->open);
return 0;
}
static int ps3_lpm_probe(struct ps3_system_bus_device *dev)
{
dev_dbg(&dev->core, " -> %s:%u\n", __func__, __LINE__);
if (lpm_priv) {
dev_info(&dev->core, "%s:%u: called twice\n",
__func__, __LINE__);
return -EBUSY;
}
lpm_priv = kzalloc(sizeof(*lpm_priv), GFP_KERNEL);
if (!lpm_priv)
return -ENOMEM;
lpm_priv->sbd = dev;
lpm_priv->node_id = dev->lpm.node_id;
lpm_priv->pu_id = dev->lpm.pu_id;
lpm_priv->rights = dev->lpm.rights;
dev_info(&dev->core, " <- %s:%u:\n", __func__, __LINE__);
return 0;
}
static int ps3_lpm_remove(struct ps3_system_bus_device *dev)
{
dev_dbg(&dev->core, " -> %s:%u:\n", __func__, __LINE__);
ps3_lpm_close();
kfree(lpm_priv);
lpm_priv = NULL;
dev_info(&dev->core, " <- %s:%u:\n", __func__, __LINE__);
return 0;
}
static int __init ps3_lpm_init(void)
{
pr_debug("%s:%d:\n", __func__, __LINE__);
return ps3_system_bus_driver_register(&ps3_lpm_driver);
}
static void __exit ps3_lpm_exit(void)
{
pr_debug("%s:%d:\n", __func__, __LINE__);
ps3_system_bus_driver_unregister(&ps3_lpm_driver);
}
