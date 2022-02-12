void ODM_InitDebugSetting23a(struct dm_odm_t *pDM_Odm)
{
pDM_Odm->DebugLevel = ODM_DBG_TRACE;
pDM_Odm->DebugComponents = 0;
}
void rt_trace(int comp, int level, const char *fmt, ...)
{
struct va_format vaf;
va_list args;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
pr_info(DRIVER_PREFIX " [0x%08x,%d] %pV", comp, level, &vaf);
va_end(args);
}
