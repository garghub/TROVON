int __init l2cache_init(void)
{
reg_l2cache_rw_ctrl ctrl = {0};
reg_l2cache_rw_cfg cfg = {.en = regk_l2cache_yes};
ctrl.csize = L2CACHE_SIZE;
ctrl.cbase = L2CACHE_SIZE / 4 + (L2CACHE_SIZE % 4 ? 1 : 0);
REG_WR(l2cache, regi_l2cache, rw_ctrl, ctrl);
memset((void *)(MEM_INTMEM_START | MEM_NON_CACHEABLE), 0, 2*1024);
REG_WR(l2cache, regi_l2cache, rw_cfg, cfg);
return 0;
}
