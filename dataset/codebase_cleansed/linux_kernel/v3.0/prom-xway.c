void __init ltq_soc_detect(struct ltq_soc_info *i)
{
i->partnum = (ltq_r32(LTQ_MPS_CHIPID) & PART_MASK) >> PART_SHIFT;
i->rev = (ltq_r32(LTQ_MPS_CHIPID) & REV_MASK) >> REV_SHIFT;
switch (i->partnum) {
case SOC_ID_DANUBE1:
case SOC_ID_DANUBE2:
i->name = SOC_DANUBE;
i->type = SOC_TYPE_DANUBE;
break;
case SOC_ID_TWINPASS:
i->name = SOC_TWINPASS;
i->type = SOC_TYPE_DANUBE;
break;
case SOC_ID_ARX188:
case SOC_ID_ARX168:
case SOC_ID_ARX182:
i->name = SOC_AR9;
i->type = SOC_TYPE_AR9;
break;
default:
unreachable();
break;
}
}
