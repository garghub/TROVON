void __init ltq_soc_detect(struct ltq_soc_info *i)
{
i->partnum = (ltq_r32(LTQ_MPS_CHIPID) & PART_MASK) >> PART_SHIFT;
i->rev = (ltq_r32(LTQ_MPS_CHIPID) & REV_MASK) >> REV_SHIFT;
switch (i->partnum) {
case SOC_ID_AMAZON_SE:
i->name = SOC_AMAZON_SE;
i->type = SOC_TYPE_AMAZON_SE;
break;
default:
unreachable();
break;
}
}
