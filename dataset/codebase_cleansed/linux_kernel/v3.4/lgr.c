static inline int stsi_0(void)
{
int rc = stsi(NULL, 0, 0, 0);
return rc == -ENOSYS ? rc : (((unsigned int) rc) >> 28);
}
static void cpascii(char *dst, char *src, int size)
{
memcpy(dst, src, size);
EBCASC(dst, size);
}
static void lgr_stsi_1_1_1(struct lgr_info *lgr_info)
{
struct sysinfo_1_1_1 *si = lgr_page;
if (stsi(si, 1, 1, 1) == -ENOSYS)
return;
cpascii(lgr_info->manufacturer, si->manufacturer,
sizeof(si->manufacturer));
cpascii(lgr_info->type, si->type, sizeof(si->type));
cpascii(lgr_info->model, si->model, sizeof(si->model));
cpascii(lgr_info->sequence, si->sequence, sizeof(si->sequence));
cpascii(lgr_info->plant, si->plant, sizeof(si->plant));
}
static void lgr_stsi_2_2_2(struct lgr_info *lgr_info)
{
struct sysinfo_2_2_2 *si = lgr_page;
if (stsi(si, 2, 2, 2) == -ENOSYS)
return;
cpascii(lgr_info->name, si->name, sizeof(si->name));
memcpy(&lgr_info->lpar_number, &si->lpar_number,
sizeof(lgr_info->lpar_number));
}
static void lgr_stsi_3_2_2(struct lgr_info *lgr_info)
{
struct sysinfo_3_2_2 *si = lgr_page;
int i;
if (stsi(si, 3, 2, 2) == -ENOSYS)
return;
for (i = 0; i < min_t(u8, si->count, VM_LEVEL_MAX); i++) {
cpascii(lgr_info->vm[i].name, si->vm[i].name,
sizeof(si->vm[i].name));
cpascii(lgr_info->vm[i].cpi, si->vm[i].cpi,
sizeof(si->vm[i].cpi));
}
lgr_info->vm_count = si->count;
}
static void lgr_info_get(struct lgr_info *lgr_info)
{
memset(lgr_info, 0, sizeof(*lgr_info));
stfle(lgr_info->stfle_fac_list, ARRAY_SIZE(lgr_info->stfle_fac_list));
lgr_info->level = stsi_0();
if (lgr_info->level == -ENOSYS)
return;
if (lgr_info->level >= 1)
lgr_stsi_1_1_1(lgr_info);
if (lgr_info->level >= 2)
lgr_stsi_2_2_2(lgr_info);
if (lgr_info->level >= 3)
lgr_stsi_3_2_2(lgr_info);
}
void lgr_info_log(void)
{
static DEFINE_SPINLOCK(lgr_info_lock);
unsigned long flags;
if (!spin_trylock_irqsave(&lgr_info_lock, flags))
return;
lgr_info_get(&lgr_info_cur);
if (memcmp(&lgr_info_last, &lgr_info_cur, sizeof(lgr_info_cur)) != 0) {
debug_event(lgr_dbf, 1, &lgr_info_cur, sizeof(lgr_info_cur));
lgr_info_last = lgr_info_cur;
}
spin_unlock_irqrestore(&lgr_info_lock, flags);
}
static void lgr_timer_fn(unsigned long ignored)
{
lgr_info_log();
lgr_timer_set();
}
static void lgr_timer_set(void)
{
mod_timer(&lgr_timer, jiffies + LGR_TIMER_INTERVAL_SECS * HZ);
}
static int __init lgr_init(void)
{
lgr_page = (void *) __get_free_pages(GFP_KERNEL, 0);
if (!lgr_page)
return -ENOMEM;
lgr_dbf = debug_register("lgr", 1, 1, sizeof(struct lgr_info));
if (!lgr_dbf) {
free_page((unsigned long) lgr_page);
return -ENOMEM;
}
debug_register_view(lgr_dbf, &debug_hex_ascii_view);
lgr_info_get(&lgr_info_last);
debug_event(lgr_dbf, 1, &lgr_info_last, sizeof(lgr_info_last));
lgr_timer_set();
return 0;
}
