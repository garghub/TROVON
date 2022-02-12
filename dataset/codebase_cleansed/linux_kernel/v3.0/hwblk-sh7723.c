int arch_hwblk_sleep_mode(void)
{
if (!sh7723_hwblk_area[CORE_AREA].cnt[HWBLK_CNT_USAGE])
return SUSP_SH_STANDBY | SUSP_SH_SF;
if (!sh7723_hwblk_area[CORE_AREA_BM].cnt[HWBLK_CNT_USAGE])
return SUSP_SH_SLEEP | SUSP_SH_SF;
return SUSP_SH_SLEEP;
}
int __init arch_hwblk_init(void)
{
return hwblk_register(&sh7723_hwblk_info);
}
